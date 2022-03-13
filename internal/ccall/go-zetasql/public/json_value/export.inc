#ifndef ZETASQL_PUBLIC_JSON_VALUE_EXPORT_H
#define ZETASQL_PUBLIC_JSON_VALUE_EXPORT_H

#include "zetasql/public/json_value.h"
#include "zetasql/public/json_value.cc"

#if 0

#include "single_include/nlohmann/json.hpp"

#ifdef ToString
#undef ToString
#endif

namespace zetasql {

  using JSON = ::nlohmann::json;
  using ::absl::StatusOr;

  struct JSONValue::Impl {
    JSON value;
  };

  StatusOr<JSONValue> JSONValue::ParseJSONString(absl::string_view str, JSONParsingOptions parsing_options) {
    StatusOr<JSONValue> v;
    return v;
  }

  StatusOr<JSONValue> JSONValue::DeserializeFromProtoBytes(absl::string_view str, absl::optional<int> max_nesting_level) {
    StatusOr<JSONValue> v;
    return v;
  }

  JSONValue JSONValue::CopyFrom(JSONValueConstRef value) {
    JSONValue v;
    return v;
  }

  JSONValue::JSONValue() : impl_(nullptr) {}

  JSONValue::JSONValue(int64_t value) : impl_(nullptr) {}
  JSONValue::JSONValue(uint64_t value) : impl_(nullptr) {}
  JSONValue::JSONValue(double value) : impl_(nullptr) {}
  JSONValue::JSONValue(bool value) : impl_(nullptr) {}
  JSONValue::JSONValue(std::string value) : impl_(nullptr) {}

  JSONValue::JSONValue(JSONValue&& value) : impl_(nullptr) {}

  JSONValue::~JSONValue() {}

  JSONValue& JSONValue::operator=(JSONValue&& value) {
    return *this;
  }

  JSONValueRef JSONValue::GetRef() {
    JSONValueRef v(nullptr);
    return v;
  }

  JSONValueConstRef JSONValue::GetConstRef() const {
    JSONValueConstRef v(nullptr);
    return v;
  }

  JSONValueConstRef::JSONValueConstRef(const JSONValue::Impl* value_pointer)
    : impl_(value_pointer) {}

  bool JSONValueConstRef::IsBoolean() const {
    return false;
  }

  bool JSONValueConstRef::IsNumber() const {
    return false;
  }

  bool JSONValueConstRef::IsNull() const {
    return false;
  }

  bool JSONValueConstRef::IsString() const {
    return false;
  }

  bool JSONValueConstRef::IsObject() const {
    return false;
  }

  bool JSONValueConstRef::IsArray() const {
    return false;
  }

  bool JSONValueConstRef::IsInt64() const {
    return false;
  }

  bool JSONValueConstRef::IsUInt64() const {
    return false;
  }

  bool JSONValueConstRef::IsDouble() const {
    return false;
  }

  int64_t JSONValueConstRef::GetInt64() const {
    return 0;
  }

  uint64_t JSONValueConstRef::GetUInt64() const {
    return 0;
  }

  double JSONValueConstRef::GetDouble() const {
    return 0;
  }

  std::string JSONValueConstRef::GetString() const {
    return "";
  }

  bool JSONValueConstRef::GetBoolean() const {
    return false;
  }

  size_t JSONValueConstRef::GetObjectSize() const {
    return 0;
  }

  bool JSONValueConstRef::HasMember(absl::string_view key) const {
    return false;
  }

  JSONValueConstRef JSONValueConstRef::GetMember(absl::string_view key) const {
    JSONValueConstRef v(nullptr);
    return v;
  }

  absl::optional<JSONValueConstRef> JSONValueConstRef::GetMemberIfExists(absl::string_view key) const {
    absl::optional<JSONValueConstRef> v;
    return v;
  }

  std::vector<std::pair<absl::string_view, JSONValueConstRef>> JSONValueConstRef::GetMembers() const {
    std::vector<std::pair<absl::string_view, JSONValueConstRef>> v;
    return v;
  }

  size_t JSONValueConstRef::GetArraySize() const {
    return 0;
  }

  JSONValueConstRef JSONValueConstRef::GetArrayElement(size_t index) const {
    JSONValueConstRef v(nullptr);
    return v;
  }

  std::vector<JSONValueConstRef> JSONValueConstRef::GetArrayElements() const {
    std::vector<JSONValueConstRef> v;
    return v;
  }

  std::string JSONValueConstRef::ToString() const {
    return "";
  }

  std::string JSONValueConstRef::Format() const {
    return "";
  }

  void JSONValueConstRef::SerializeAndAppendToProtoBytes(std::string* output) const {
  }

  uint64_t JSONValueConstRef::SpaceUsed() const {
    return 0;
  }

  bool JSONValueConstRef::NestingLevelExceedsMax(int64_t max_nesting) const {
    return false;
  }

  bool JSONValueConstRef::NormalizedEquals(JSONValueConstRef that) const {
    return false;
  }

  JSONValueRef::JSONValueRef(JSONValue::Impl* impl)
    : JSONValueConstRef(impl), impl_(impl) {}

  JSONValueRef JSONValueRef::GetMember(absl::string_view key) {
    JSONValueRef v(nullptr);
    return v;
  }

  std::vector<std::pair<absl::string_view, JSONValueRef>> JSONValueRef::GetMembers() {
    std::vector<std::pair<absl::string_view, JSONValueRef>> v;
    return v;
  }

  JSONValueRef JSONValueRef::GetArrayElement(size_t index) {
    JSONValueRef v(nullptr);
    return v;
  }

  std::vector<JSONValueRef> JSONValueRef::GetArrayElements() {
    std::vector<JSONValueRef> v;
    return v;
  }

  void JSONValueRef::SetNull() {
  }

  void JSONValueRef::SetInt64(int64_t value) {
  }

  void JSONValueRef::SetUInt64(uint64_t value) {
  }

  void JSONValueRef::SetDouble(double value) {
  }

  void JSONValueRef::SetString(absl::string_view value) {
  }

  void JSONValueRef::SetBoolean(bool value) {
  }

  void JSONValueRef::Set(JSONValue json_value) {
  }

  void JSONValueRef::SetToEmptyObject() {
  }

  void JSONValueRef::SetToEmptyArray() {
  }

  absl::Status internal::CheckNumberRoundtrip(absl::string_view lhs, double val) {
    absl::Status v;
    return v;
  }

}

#endif

#include "go-zetasql/public/numeric_parser/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/json_parser/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/optional/export.inc"

#endif
