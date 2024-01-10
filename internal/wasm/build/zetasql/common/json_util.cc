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

#include "zetasql/common/json_util.h"

#include <string>

#include "absl/strings/str_format.h"
#include "absl/strings/string_view.h"

namespace zetasql {

void JsonEscapeString(absl::string_view raw, std::string* value_string) {
  value_string->clear();
  value_string->reserve(raw.size() + 2);

  value_string->push_back('"');
  const size_t length = raw.length();
  for (size_t i = 0; i < length; ++i) {
    const unsigned char c = raw[i];
    if (c < 0x20) {
      // Not printable.
      value_string->push_back('\\');
      switch (c) {
        case '\b':
          value_string->push_back('b');
          break;
        case '\f':
          value_string->push_back('f');
          break;
        case '\n':
          value_string->push_back('n');
          break;
        case '\r':
          value_string->push_back('r');
          break;
        case '\t':
          value_string->push_back('t');
          break;
        default:
          absl::StrAppendFormat(value_string, "u%04x", c);
      }
      continue;
    }

    switch (c) {
      case '\"':
        value_string->append("\\\"");
        continue;
      case '\\':
        value_string->append("\\\\");
        continue;

      // Escape U+2028 (LINE SEPARATOR) and U+2029 (PARAGRAPH SEPARATOR).
      // Those characters are valid characters in a JSON string, but to put
      // the characters in a JSON string we need escaping. Otherwise the JSON
      // string will be something like:
      //   var json = "foo[U+2028]
      //   bar";
      // It should be:
      //   var json = "foo\u2028bar";
      case 0xe2: {
        if ((i + 2 < length) && (raw[i + 1] == '\x80')) {
          if (raw[i + 2] == '\xa8') {
            value_string->append("\\u2028");
            i += 2;
            continue;
          } else if (raw[i + 2] == '\xa9') {
            value_string->append("\\u2029");
            i += 2;
            continue;
          }
        }
        value_string->push_back(c);
        continue;
      }
    }

    // Character should not be escaped.
    value_string->push_back(c);
  }
  value_string->push_back('"');
}

bool JsonStringNeedsEscaping(absl::string_view raw) {
  const size_t length = raw.length();
  for (size_t i = 0; i < length; ++i) {
    const unsigned char c = raw[i];

    if (c < 0x20) {
      // Not printable
      return true;
    }

    switch (c) {
      case '\"':
        return true;

      case '\\':
        return true;

      // Escape U+2028 (LINE SEPARATOR) and U+2029 (PARAGRAPH SEPARATOR).
      // Those characters are valid characters in a JSON string, but to put
      // the characters in a JSON string we need escaping. Otherwise the JSON
      // string will be something like:
      //   var json = "foo[U+2028]
      //   bar";
      // It should be:
      //   var json = "foo\u2028bar";
      case 0xe2:
        if ((i + 2 < length) && (raw[i + 1] == '\x80') &&
            (raw[i + 2] == '\xa8' || raw[i + 2] == '\xa9')) {
          return true;
        }
        break;

      default:
        break;
    }
  }

  return false;
}

}  // namespace zetasql
