//
// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "zetasql/common/json_parser.h"

#include <cstdint>

#include "zetasql/base/logging.h"
#include "absl/strings/ascii.h"
#include "absl/strings/escaping.h"
#include "absl/strings/match.h"
#include "absl/strings/str_format.h"
#include "absl/strings/string_view.h"
#include "zetasql/base/string_numbers.h"  // iwyu: keep
#include "unicode/utf8.h"
#include "re2/re2.h"

namespace zetasql {

static const int kUnicodeEscapedLength = 6;
static const int kLatin1HexEscapedLength = 4;
static const int kLatin1OctEscapedLength = 4;

static constexpr absl::string_view kTrue = "true";
static constexpr absl::string_view kFalse = "false";
static constexpr absl::string_view kNull = "null";

// Regexp for validating and extracting a key or variable name.
static LazyRE2 key_re = {"([\\w_$][\\d\\w_$]*)"};

JSONParser::JSONParser(absl::string_view json) : json_(json) {}

JSONParser::~JSONParser() {}

bool JSONParser::Parse() {
  p_ = json_;

  bool ret = ParseValue();
  // Test that the entire string was consumed
  SkipWhitespace();
  if (!p_.empty())
    return ReportFailure("Parser terminated before end of string");
  return ret;
}


bool JSONParser::ParseValue() {
  switch (GetNextTokenType()) {
    case BEGIN_STRING:
      return ParseString();
    case BEGIN_NUMBER:
      return ParseNumber();
    case BEGIN_OBJECT:
      return ParseObject();
    case BEGIN_ARRAY:
      return ParseArray();
    case BEGIN_TRUE:
      return ParseTrue();
    case BEGIN_FALSE:
      return ParseFalse();
    case BEGIN_NULL:
      return ParseNull();
    case END_ARRAY:
    case VALUE_SEPARATOR:
      return ParsedNull();
    default:
      return ReportFailure("Unexpected token");
  }
}

bool JSONParser::ParseString() {
  std::string str;
  if (!ParseStringHelper(&str)) return false;
  if (!ParsedString(str)) return ReportFailure("ParsedString returned false");
  return true;
}

constexpr absl::string_view kReplacementCharacter = "\uFFFD";

// Converts a unicode escaped or Latin-1 escaped character to a decimal value
// stored in a char32_t for use in UTF8 encoding utility.  We assume that str
// begins with \uhhhh or \xhh and converts that from the hex number to a decimal
// value.
//
//
// Background reading:
//   - http://www.unicode.org/reports/tr36/#UTF-8_Exploit
bool JSONParser::ParseHexDigits(const int size, std::string* str) {
  if (p_.length() < size) {
    return false;
  }
  ZETASQL_CHECK_GT(size, 2);
  ZETASQL_CHECK_EQ(p_.data()[0], '\\');
  ZETASQL_CHECK(p_.data()[1] == 'u' || p_.data()[1] == 'x');
  char32_t code = 0;
  for (int i = 2; i < size; ++i) {
    if (!absl::ascii_isxdigit(p_.data()[i])) {
      return ReportFailure("Invalid escape sequence.");
    }
    code = (code << 4) + zetasql_base::hex_digit_to_int(p_.data()[i]);
  }
  char buf[U8_MAX_LENGTH];
  UBool is_error = false;
  int32_t len = 0;
  U8_APPEND(buf, len, U8_MAX_LENGTH, code, is_error);
  if (is_error) {
    // If the codepoint is bogus, just replace with replacement character.
    str->append(kReplacementCharacter.data(), kReplacementCharacter.size());
  } else {
    str->append(buf, len);
  }
  // We cheat and advance size - 1 chars and unescape because Advance() in
  // ParseStringHelper loop that calls this function advances one
  // character.
  p_.remove_prefix(size - 1);
  return true;
}

// static
bool JSONParser::IsOctalDigit(char c) { return (c >= '0' && c <= '7'); }

void JSONParser::ParseOctalDigits(const int max_size, std::string* str) {
  // Length >= 2 because it must have a \ and at least one octal digit.
  ZETASQL_DCHECK_GE(p_.length(), 2);
  ZETASQL_CHECK_EQ(p_.data()[0], '\\');
  char32_t sum = 0;
  // Start at one because we skip the \.
  int num_octal_digits = 1;
  for (; num_octal_digits < std::min<int>(p_.length(), max_size);
       ++num_octal_digits) {
    if (!IsOctalDigit(p_.data()[num_octal_digits])) {
      break;
    }
    sum = (sum << 3) + p_.data()[num_octal_digits] - '0';
  }
  char buf[U8_MAX_LENGTH];
  UBool is_error = false;
  int32_t len = 0;
  U8_APPEND(buf, len, sizeof(buf), sum, is_error);
  if (is_error) {
    // If the codepoint is bogus, just replace with replacement character.
    str->append(kReplacementCharacter.data(), kReplacementCharacter.size());
  } else {
    str->append(buf, len);
  }

  p_.remove_prefix(num_octal_digits - 1);
}

bool JSONParser::ParseStringHelper(std::string* str) {
  str->clear();
  // The character used to open the string (' or ") must also close the string.
  const char* open = p_.data();
  ZETASQL_CHECK(*open == '\"' || *open == '\'');
  // We may hit the end of the string before finding the closing quote.
  bool found_close_quote = false;
  AdvanceOneByte();

  // This code block builds up `str` to contain the, possibly escaped,
  // string literal from the json input. Often, this is going to be a simple
  // copy of the inputs. however in the case of escaped characters such as
  // the two-byte sequence '\','b' we replace them with the one byte sequence
  // '\b'. This also handles unicode and octal escaping.
  //
  // We reduce calls to str->append() by buffering up chunks of contiguous
  // sequences of characters. We flush whenever we encounter an escape sequence,
  // and at the end of loop.

  // Denotes the start of the "buffer" as a pointer into `json_`, nullptr
  // indicates the "buffer" is empty.
  const char* flush_start = nullptr;

  // Append the sequence from flush_start to flush_end to `str`. if
  // `flush_start` is nullptr, do nothing.
  auto flush = [](const char* flush_start, const char* flush_end,
                  std::string* str) {
    if (flush_start == nullptr) {
      return;
    }
    ZETASQL_DCHECK_GE(flush_end, flush_start);
    str->append(flush_start, flush_end - flush_start);
  };

  for (; !p_.empty(); AdvanceOneCodepoint()) {
    if (*p_.data() == '\\') {
      flush(flush_start, p_.data(), str);
      flush_start = nullptr;
      // we know p->length() > 0
      if (p_.length() == 1) return false;
      if (p_.data()[1] == 'u') {
        if (!ParseHexDigits(kUnicodeEscapedLength, str)) return false;
      } else if (p_.data()[1] == 'x') {
        if (!ParseHexDigits(kLatin1HexEscapedLength, str)) return false;
      } else if (IsOctalDigit(p_.data()[1])) {
        ParseOctalDigits(kLatin1OctEscapedLength, str);
      } else {
        // This code parses escaped whitespace.
        switch (p_.data()[1]) {
          case 'b':
            str->push_back('\b');
            break;
          case 'f':
            str->push_back('\f');
            break;
          case 'n':
            str->push_back('\n');
            break;
          case 'r':
            str->push_back('\r');
            break;
          case 't':
            str->push_back('\t');
            break;
          case 'v':
            str->push_back('\v');
            break;
          default:
            str->push_back(p_.data()[1]);
        }
        p_.remove_prefix(1);
      }
    } else if (*p_.data() == *open) {
      found_close_quote = true;
      break;
    } else {
      if (flush_start == nullptr) {
        flush_start = p_.data();
      }
    }
  }
  flush(flush_start, p_.data(), str);
  if (!found_close_quote)
    return ReportFailure("Closing quote expected in string");
  AdvanceOneCodepoint();
  return true;
}

bool JSONParser::ParseNumber() {
  absl::string_view str;
  if (!ParseNumberTextHelper(&str)) return false;
  if (!ParsedNumber(str)) return ReportFailure("ParsedNumber returned false");
  return true;
}

bool JSONParser::ParseNumberTextHelper(absl::string_view* str) {
  ZETASQL_CHECK(str);
  const char* p = p_.data();
  const char* end = p + p_.size();

  // Optional leading minus.
  if (*p == '-') p++;

  // A single zero, or a series of digits.
  if (p < end && *p == '0') {
    p++;
  } else if (p < end && *p >= '1' && *p <= '9') {
    do {
      p++;
    } while (p < end && *p >= '0' && *p <= '9');
  } else {
    return ReportFailure(
        "Could not parse number: number must begin with optional '-'"
        " and then digits.");
  }

  // Optional fraction.
  if (p < end && *p == '.') {
    p++;
    // One or more digits.
    if (p < end && *p >= '0' && *p <= '9') {
      do {
        p++;
      } while (p < end && *p >= '0' && *p <= '9');
    } else {
      return ReportFailure(
          "Could not parse number: '.' must be followed by digits.");
    }
  }

  // Optional exponent.
  if (p < end && (*p == 'e' || *p == 'E')) {
    p++;

    // Optional leading plus or minus.
    if (p < end && (*p == '+' || *p == '-')) p++;

    if (p < end && *p >= '0' && *p <= '9') {
      // One or more digits.
      do {
        p++;
      } while (p < end && *p >= '0' && *p <= '9');
    } else {
      return ReportFailure(
          "Could not parse number: 'e' or 'E' must be followed by optional"
          " '+' or '-' and then digits.");
    }
  }

  *str = p_.substr(0, p - p_.data());
  p_.remove_prefix(p - p_.data());
  return true;
}

bool JSONParser::ParseNumberHelper(double* d) {
  ZETASQL_CHECK(d);
  char* end;
  errno = 0;
  // Number formats of strtod and JSON are actually different,
  // Some users might depend on the current behavior though.
  *d = strtod(p_.data(), &end);
  if (errno != 0 || end == p_.data())
    return ReportFailure("Could not parse number");
  p_.remove_prefix(end - p_.data());
  return true;
}

bool JSONParser::ParseObject() {
  ZETASQL_CHECK_EQ('{', *p_.data());
  AdvanceOneByte();

  if (!BeginObject()) return ReportFailure("BeginObject returned false");

  // Handle the {} case.
  TokenType t = GetNextTokenType();
  if (t == END_OBJECT) {
    if (!EndObject()) return ReportFailure("EndObject returned false");
    AdvanceOneByte();
    return true;
  }

  // An object is a comma-separated list of key/string : value.
  // This loop consumes one key:value pair per iteration.
  while (true) {
    t = GetNextTokenType();
    if (t == BEGIN_STRING) {
      std::string str;
      if (!ParseStringHelper(&str)) return false;
      if (!BeginMember(str)) return ReportFailure("BeginMember returned false");
    } else if (t == BEGIN_KEY || t == BEGIN_NUMBER) {
      return ReportFailure("Non-string key encountered while parsing object");
    } else {
      return ReportFailure("Expected key");
    }

    // Consume the colon
    SkipWhitespace();
    if (p_.empty() || *p_.data() != ':')
      return ReportFailure("Expected : between key:value pair");
    AdvanceOneByte();

    // Parse the value for this member
    if (!ParseValue()) return ReportFailure("Could not parse value");

    // ',' '}' or possibly ',}' must appear next.
    t = GetNextTokenType();
    AdvanceOneByte();
    if (t == END_OBJECT) {
      if (!EndMember(true)) return ReportFailure("EndMember returned false");
      break;
    }
    if (t == VALUE_SEPARATOR) {
      // Look ahead for '}'
      t = GetNextTokenType();
      if (t == END_OBJECT) {
        if (!EndMember(true)) return ReportFailure("EndMember returned false");
        AdvanceOneByte();
        break;
      }
      if (!EndMember(false)) return ReportFailure("EndMember returned false");
      continue;
    }
    // Fall through case.
    return ReportFailure("Expected , or } after key:value pair");
  }
  if (!EndObject()) return ReportFailure("EndObject returned false");
  return true;
}

bool JSONParser::ParseArray() {
  ZETASQL_CHECK_EQ('[', *p_.data());
  AdvanceOneByte();
  if (!BeginArray()) return ReportFailure("BeginArray returned false");
  // Deal with [] case
  TokenType t = GetNextTokenType();
  if (t == END_ARRAY) {
    AdvanceOneByte();
    if (!EndArray()) return ReportFailure("EndArray returned false");
    return true;
  }

  // An array is a comma-separated list of values.
  while (true) {
    if (!BeginArrayEntry())
      return ReportFailure("BeginArrayEntry returned false");
    if (!ParseValue()) return ReportFailure("Could not parse value");

    // ',' ']' or possibly ',]' must appear next.
    t = GetNextTokenType();
    AdvanceOneByte();
    if (t == END_ARRAY) {
      if (!EndArrayEntry(true))
        return ReportFailure("EndArrayEntry returned false");
      break;
    }
    if (t == VALUE_SEPARATOR) {
      t = GetNextTokenType();
      if (t == END_ARRAY) {
        if (!EndArrayEntry(true))
          return ReportFailure("EndArrayEntry returned false");
        AdvanceOneByte();
        break;
      }
      if (!EndArrayEntry(false))
        return ReportFailure("EndArrayEntry returned false");
      continue;
    }
    // Fall through case.
    return ReportFailure("Expected , or ] after array value");
  }
  if (!EndArray()) return ReportFailure("EndArray returned false");
  return true;
}

bool JSONParser::ParseTrue() {
  if (!ParsedBool(true)) return ReportFailure("ParsedBool returned false");
  ZETASQL_DCHECK_GE(p_.length(), kTrue.length());
  p_.remove_prefix(kTrue.length());
  return true;
}

bool JSONParser::ParseFalse() {
  if (!ParsedBool(false)) return ReportFailure("ParsedBool returned false");
  ZETASQL_DCHECK_GE(p_.length(), kFalse.length());
  p_.remove_prefix(kFalse.length());
  return true;
}

bool JSONParser::ParseNull() {
  if (!ParsedNull()) return ReportFailure("ParsedNull returned false");
  ZETASQL_DCHECK_GE(p_.length(), kNull.length());
  p_.remove_prefix(kNull.length());
  return true;
}

bool JSONParser::ParseKey(absl::string_view* key) {
  // TODO: Optimize later if necessary.
  if (!RE2::Consume(&p_, *key_re, key))
    return ReportFailure("Invalid key or variable name");
  return true;
}

void JSONParser::SkipWhitespace() {
  int i = 0;
  for (; i < p_.length() && absl::ascii_isspace(p_[i]); ++i) {
  }
  p_.remove_prefix(i);
}

void JSONParser::AdvanceOneByte() {
  if (!p_.empty()) {
    p_.remove_prefix(1);
  }
}

void JSONParser::AdvanceOneCodepoint() {
  // Cannot advance an empty string.
  if (p_.empty()) {
    return;
  }
  size_t len = 0;
  // Note, This examines only the first byte of p_, deriving its length from
  // that.  If the UTF-8 is invalid, and the length encoded in the first byte
  // is misleading, we may skip sections of the string, resulting in undefined
  // behavior.
  U8_FWD_1_UNSAFE(p_.data(), len);
  p_.remove_prefix(std::min(p_.length(), len));
}

JSONParser::TokenType JSONParser::GetNextTokenType() {
  SkipWhitespace();

  // TODO: Optimize later if necessary.
  if (p_.empty()) {
    ReportFailure("Unexpected end of string");
    return UNKNOWN;  // Unexpected end of string.
  }

  switch (*p_.data()) {
    case '\"':
    case '\'':
      return BEGIN_STRING;
    case '-':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      return BEGIN_NUMBER;
    case '{':
      return BEGIN_OBJECT;
    case '}':
      return END_OBJECT;
    case '[':
      return BEGIN_ARRAY;
    case ']':
      return END_ARRAY;
    case ',':
      return VALUE_SEPARATOR;
    case 't':
      if (absl::StartsWith(p_, kTrue)) return BEGIN_TRUE;
      break;
    case 'f':
      if (absl::StartsWith(p_, kFalse)) return BEGIN_FALSE;
      break;
    case 'n':
      if (absl::StartsWith(p_, kNull)) return BEGIN_NULL;
      break;
  }

  absl::string_view temp = p_;  // Consume modifies pointer.
  if (RE2::Consume(&temp, *key_re)) return BEGIN_KEY;

  ReportFailure("Unknown token type");
  return UNKNOWN;
}

std::string JSONParser::ContextAtCurrentPosition(int context_length) const {
  const char* begin =
      std::max<const char*>(p_.data() - context_length, json_.data());
  const char* end = std::min<const char*>(p_.data() + context_length,
                                          json_.data() + json_.size());
  return std::string(begin, end - begin);
}

// virtual
bool JSONParser::ReportFailure(const std::string& error_message) {
  static const int kContextLength = 10;
  ZETASQL_VLOG(1) << error_message;
  ZETASQL_VLOG(2) << "Character " << p_.data() - json_.data() << ":" << std::endl
          << ContextAtCurrentPosition(kContextLength);
  return false;  // Convenient return value for forwarding.
}

// Implement default event handlers.
// This allows base classes to listen to only a subset of events,
// and by ignoring all events one obtains a JSON syntax checker.
bool JSONParser::BeginObject() { return true; }
bool JSONParser::EndObject() { return true; }
bool JSONParser::BeginMember(const std::string& key) { return true; }
bool JSONParser::EndMember(bool last) { return true; }
bool JSONParser::BeginArray() { return true; }
bool JSONParser::EndArray() { return true; }
bool JSONParser::BeginArrayEntry() { return true; }
bool JSONParser::EndArrayEntry(bool last) { return true; }
bool JSONParser::ParsedString(const std::string& str) { return true; }
bool JSONParser::ParsedNumber(absl::string_view str) { return true; }
bool JSONParser::ParsedBool(bool val) { return true; }
bool JSONParser::ParsedNull() { return true; }

}  // namespace zetasql
