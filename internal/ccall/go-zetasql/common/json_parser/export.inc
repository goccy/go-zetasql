#ifndef ZETASQL_COMMON_JSON_PARSER_EXPORT_H
#define ZETASQL_COMMON_JSON_PARSER_EXPORT_H

#include "zetasql/common/json_parser.h"

#define kReplacementCharacter GO_EXPORT(kReplacementCharacter)
#include "zetasql/common/json_parser.cc"
#undef kReplacementCharacter

#if 0
namespace zetasql {

  JSONParser::JSONParser(absl::string_view json) : json_(json) {}

  JSONParser::~JSONParser() {}

  bool JSONParser::Parse() {
    return false;
  }

  bool JSONParser::ParseValue() {
    return false;
  }

  bool JSONParser::ParseString() {
    return false;
  }

  bool JSONParser::ParseHexDigits(const int size, std::string* str) {
    return false;
  }

  bool JSONParser::IsOctalDigit(char c) {
    return false;
  }

  void JSONParser::ParseOctalDigits(const int max_size, std::string* str) {
  }

  bool JSONParser::ParseStringHelper(std::string* str) {
    return false;
  }

  bool JSONParser::ParseNumber() {
    return false;
  }

  bool JSONParser::ParseNumberTextHelper(absl::string_view* str) {
    return false;
  }

  bool JSONParser::ParseNumberHelper(double* d) {
    return false;
  }

  bool JSONParser::ParseObject() {
    return false;
  }

  bool JSONParser::ParseArray() {
    return false;
  }

  bool JSONParser::ParseTrue() {
    return false;
  }

  bool JSONParser::ParseFalse() {
    return false;
  }

  bool JSONParser::ParseNull() {
    return false;
  }

  bool JSONParser::ParseKey(absl::string_view* key) {
    return false;
  }

  void JSONParser::SkipWhitespace() {
  }

  void JSONParser::AdvanceOneByte() {
  }

  void JSONParser::AdvanceOneCodepoint() {
  }

  JSONParser::TokenType JSONParser::GetNextTokenType() {
    JSONParser::TokenType v;
    return v;
  }

  std::string JSONParser::ContextAtCurrentPosition(int context_length) const {
    return "";
  }

  bool JSONParser::ReportFailure(const std::string& error_message) {
    return false;
  }

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

}

#endif

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-re2/re2/export.inc"
#include "go-icu/icu/export.inc"

#endif
