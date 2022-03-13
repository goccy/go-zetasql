#ifndef ZETASQL_PUBLIC_VALUE_EXPORT_H
#define ZETASQL_PUBLIC_VALUE_EXPORT_H

#include "zetasql/public/proto_util.h"
#include "zetasql/public/value.h"
#include "zetasql/public/value.cc"
#include "zetasql/public/proto_util.cc"

#if 0
namespace zetasql {

  ProtoFieldDefaultOptions ProtoFieldDefaultOptions::FromFieldAndLanguage(const google::protobuf::FieldDescriptor* field,
                                                                          const LanguageOptions& language_options) {
    ProtoFieldDefaultOptions v;
    return v;
  }

  absl::Status GetProtoFieldDefault(const ProtoFieldDefaultOptions& options,
                                    const google::protobuf::FieldDescriptor* field,
                                    const Type* type, Value* default_value) {
    return absl::OkStatus();
  }

  absl::Status GetProtoFieldTypeAndDefault(const ProtoFieldDefaultOptions& options,
                                           const google::protobuf::FieldDescriptor* field, TypeFactory* type_factory,
                                           const Type** type, Value* default_value) {
    return absl::OkStatus();
  }

  static absl::Status Int64ToAdjustedTimestampInt64(FieldFormat::Format format,
                                                    int64_t s,
                                                    int64_t* adjusted_s) {
    return absl::OkStatus();
  }


  static bool ReadWireValue(google::protobuf::FieldDescriptor::Type field_type,
                            uint32_t tag_and_type, const absl::Cord& bytes,
                            google::protobuf::io::CodedInputStream* in,
                            WireValueType* value) {
    return false;
  }

  static std::string MakeReadValueErrorReason(const google::protobuf::FieldDescriptor* field_descriptor, FieldFormat::Format format,
                                              int64_t v) {
    return "";
  }


  static absl::StatusOr<Value> TranslateWireValue(const WireValueType& wire_value,
                                                  const google::protobuf::FieldDescriptor* field_descriptor, FieldFormat::Format format,
                                                  const Type* type) {
    absl::StatusOr<Value> v;
    return v;
  }

  using PackedValuesVector = absl::InlinedVector<WireValueType, 8>;

  static bool ReadPackedWireValues(int tag_number,
                                   google::protobuf::FieldDescriptor::Type field_type,
                                   google::protobuf::io::CodedInputStream* in,
                                   PackedValuesVector* values) {
    return false;
  }

  static absl::StatusOr<Value> ReadSingularProtoField(const ProtoFieldInfo& field_info, const absl::Cord& bytes) {
    absl::StatusOr<Value> v;
    return v;
  }

  absl::Status ReadProtoFields(absl::Span<const ProtoFieldInfo* const> field_infos,
                               const absl::Cord& bytes, ProtoFieldValueList* field_value_list) {
    return absl::OkStatus();
  }

  absl::Status ReadProtoField(const google::protobuf::FieldDescriptor* field_descr,
                              FieldFormat::Format format, const Type* type,
                              const Value& default_value, bool get_has_bit,
                              const absl::Cord& bytes, Value* output_value) {
    return absl::OkStatus();
  }

  absl::Status ReadProtoField(const google::protobuf::FieldDescriptor* field_descr,
                              FieldFormat::Format format, const Type* type,
                              const Value& default_value, const absl::Cord& bytes,
                              Value* output_value) {
    return absl::OkStatus();
  }

  absl::Status ProtoHasField(int32_t field_tag, const absl::Cord& bytes,
                             bool* has_field) {
    return absl::OkStatus();
  }

  bool IsProtoMap(const Type* type) {
    return false;
  }

  absl::Status ParseProtoMap(const Value& array_of_map_entry,
                             const Type* key_type, const Type* value_type,
                             std::vector<std::pair<Value, Value>>& output) {
    return absl::OkStatus();
  }

}

namespace zetasql {

  std::ostream& operator<<(std::ostream& out, const Value& value) {
    return out;
  }

  void Value::SetMetadataForNonSimpleType(const Type* type, bool is_null,
                                          bool preserves_order) {
  }

  Value::Value(const Type* type, bool is_null, OrderPreservationKind order_kind) {
  }

  void Value::CopyFrom(const Value& that) {
  }

  Value::Value(TypeKind type_kind, int64_t value) : metadata_(type_kind) {
  }

  Value::Value(absl::Time t) {
  }

  Value::Value(TimeValue time)
    : metadata_(TypeKind::TYPE_TIME, time.Nanoseconds()),
      bit_field_32_value_(time.Packed32TimeSeconds()) {
  }

  Value::Value(DatetimeValue datetime)
    : metadata_(TypeKind::TYPE_DATETIME, datetime.Nanoseconds()),
      bit_field_64_value_(datetime.Packed64DatetimeSeconds()) {
  }

  Value::Value(const EnumType* enum_type, int64_t value) {
  }

  Value::Value(const EnumType* enum_type, absl::string_view name) {
  }

  Value::Value(const ProtoType* proto_type, absl::Cord value)
    : proto_ptr_(new internal::ProtoRep(proto_type, std::move(value))) {
  }

  Value::Value(const ExtendedType* extended_type, const ValueContent& value) {
  }

  absl::StatusOr<Value> Value::MakeArrayInternal(bool already_validated,
                                                 const ArrayType* array_type,
                                                 OrderPreservationKind order_kind,
                                                 std::vector<Value> values) {
    absl::StatusOr<Value> v;
    return v;
  }

  absl::StatusOr<Value> Value::MakeStructInternal(bool already_validated,
                                                  const StructType* struct_type,
                                                  std::vector<Value> values) {
    absl::StatusOr<Value> v;
    return v;
  }

  const Type* Value::type() const {
    return nullptr;
  }

  const std::vector<Value>& Value::fields() const {
    std::vector<Value> *v;
    return *v;
  }

  const std::vector<Value>& Value::elements() const {
    std::vector<Value> *v;
    return *v;
  }

  Value Value::TimestampFromUnixMicros(int64_t v) {
    Value v;
    return v;
  }

  Value Value::TimeFromPacked64Micros(int64_t v) {
    Value v;
    return v;
  }

  Value Value::DatetimeFromPacked64Micros(int64_t v) {
    Value v;
    return v;
  }

  const std::string& Value::enum_name() const {
    std::string *v;
    return *v;
  }

  int64_t Value::ToInt64() const {
    return 0;
  }

  uint64_t Value::ToUint64() const {
    return 0;
  }

  double Value::ToDouble() const {
    return 0;
  }

  uint64_t Value::physical_byte_size() const {
    return 0;
  }

  absl::Cord Value::ToCord() const {
    absl::Cord v;
    return v;
  }

  absl::Time Value::ToTime() const {
    absl::Time v;
    return v;
  }

  int64_t Value::ToUnixMicros() const {
    return 0;
  }

  int64_t Value::ToPacked64TimeMicros() const {
    return 0;
  }

  int64_t Value::ToPacked64DatetimeMicros() const {
    return 0;
  }

  absl::Status Value::ToUnixNanos(int64_t* nanos) const {
    return absl::OkStatus();
  }

  ValueContent Value::extended_value() const {
    ValueContent v;
    return v;
  }

  google::protobuf::Message* Value::ToMessage(google::protobuf::DynamicMessageFactory* message_factory,
                                              bool return_null_on_error) const {
    return nullptr;
  }

  const Value& Value::FindFieldByName(absl::string_view name) const {
    Value *v;
    return *v;
  }

  void Value::DeepOrderKindSpec::FillSpec(const Value& v) {
  }

  bool Value::EqualsInternal(const Value& x, const Value& y, bool allow_bags,
                             DeepOrderKindSpec* deep_order_spec,
                             const ValueEqualityCheckOptions& options) {
    return false;
  }

  bool Value::EqualElementMultiSet(const Value& x, const Value& y,
                                   DeepOrderKindSpec* deep_order_spec,
                                   const ValueEqualityCheckOptions& options) {
    return false;
  }

  Value Value::SqlEquals(const Value& that) const {
    Value v;
    return v;
  }

  size_t Value::HashCode() const {
    return 0;
  }

  size_t Value::HashCodeInternal(FloatMargin float_margin) const {
    return 0;
  }

  bool Value::LessThan(const Value& that) const {
    return false;
  }

  Value Value::SqlLessThan(const Value& that) const {
    Value v;
    return v;
  }

  std::string Value::ComplexValueToDebugString(const Value* root, bool verbose) {
    return ""
  }

  std::string Value::DebugString(bool verbose) const {
    return ""
  }

  std::string Value::Format() const {
    return ""
  }

  std::string Value::GetSQL(ProductMode mode) const {
    return ""
  }

  std::string Value::GetSQLLiteral(ProductMode mode) const {
    return ""
  }

  template <bool as_literal, bool maybe_add_simple_type_prefix>
  std::string Value::GetSQLInternal(ProductMode mode) const {
    return ""
  }

  std::string RepeatString(const std::string& text, int times) {
    return ""
  }

  const int kIndentStep = 2;
  const char* kIndentChar = " ";
  const int kWrapCols = 78;
  const int kMaxSingleLineElement = 20;
  const int kMaxColumnIndent = 15;

  std::string Indent(int columns) {
    return ""
  }

  size_t LongestLine(const std::string& formatted) {
    return 0;
  }

  std::string ReIndentTail(const std::string& formatted, int added_depth) {
    return ""
  }

  std::string FormatBlock(absl::string_view block_template,
                          const std::vector<std::string>& elements,
                          const std::string& separator, int block_indent_cols,
                          WrapStyle wrap_style) {
    return ""
  }

  const int kArrayIndent = 6;
  const int kStructIndent = 7;

  std::string FormatType(const Type* type, ArrayElemFormat elem_format,
                         int indent_cols) {
    return ""
  }

  std::string Value::FormatInternal(int indent, bool force_type) const {
    return ""
  }

  bool Value::ParseInteger(absl::string_view input, Value* value) {
    return false;
  }

  namespace values {

    Value Int32Array(absl::Span<const int32_t> values) {
      Value v;
      return v;
    }

    Value Int64Array(absl::Span<const int64_t> values) {
      Value v;
      return v;
    }

    Value Uint32Array(absl::Span<const uint32_t> values) {
      Value v;
      return v;
    }

    Value Uint64Array(absl::Span<const uint64_t> values) {
      Value v;
      return v;
    }

    Value BoolArray(const std::vector<bool>& values) {
      Value v;
      return v;
    }

    Value FloatArray(absl::Span<const float> values) {
      Value v;
      return v;
    }

    Value DoubleArray(absl::Span<const double> values) {
      Value v;
      return v;
    }

    Value StringArray(absl::Span<const std::string> values) {
      Value v;
      return v;
    }

    Value StringArray(absl::Span<const absl::Cord* const> values) {
      Value v;
      return v;
    }

    Value BytesArray(absl::Span<const std::string> values) {
      Value v;
      return v;
    }

    Value BytesArray(absl::Span<const absl::Cord* const> values) {
      Value v;
      return v;
    }

    Value NumericArray(absl::Span<const NumericValue> values) {
      Value v;
      return v;
    }

    Value BigNumericArray(absl::Span<const BigNumericValue> values) {
      Value v;
      return v;
    }

    Value JsonArray(absl::Span<const JSONValue> values) {
      Value v;
      return v;
    }

    Value UnvalidatedJsonStringArray(absl::Span<const std::string> values) {
      Value v;
      return v;
    }

    Value TimestampArray(absl::Span<const absl::Time> values) {
      Value v;
      return v;
    }

  }

  absl::Status Value::Serialize(ValueProto* value_proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<Value> Value::Deserialize(const ValueProto& value_proto,
                                           const Type* type) {
    absl::StatusOr<Value> v;
    return v;
  }

  ValueContent Value::GetContent() const {
    ValueContent v;
    return v;
  }

  void Value::SetContent(const ValueContent& content) {
  }

  Value::Metadata::Content* Value::Metadata::content() {
    return nullptr;
  }

  const Value::Metadata::Content* Value::Metadata::content() const {
    return nullptr;
  }

  const Type* Value::Metadata::type() const {
    return nullptr;
  }

  TypeKind Value::Metadata::type_kind() const {
    TypeKind v;
    return v;
  }

  bool Value::Metadata::is_null() const {
    return false;
  }

  bool Value::Metadata::preserves_order() const {
    return false;
  }

  bool Value::Metadata::has_type_pointer() const {
    return false;
  }

  bool Value::Metadata::can_store_value_extended_content() const {
    return false;
  }

  int32_t Value::Metadata::value_extended_content() const {
    return 0;
  }

  bool Value::Metadata::is_valid() const {
    return false;
  }

  Value::Metadata::Metadata(const Type* type, bool is_null,
                            bool preserves_order) {
  }

}
#endif

#include "go-zetasql/public/civil_time/export.inc"
#include "go-zetasql/public/interval_value/export.inc"
#include "go-zetasql/public/json_value/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/numeric_value/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value_cc_proto/export.inc"
#include "go-zetasql/public/value_content/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/refcount/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/float_margin/export.inc"
#include "go-zetasql/common/string_util/export.inc"
#include "go-zetasql/public/proto/type_annotation_cc_proto/export.inc"
#include "go-zetasql/public/functions/arithmetics/export.inc"
#include "go-zetasql/public/functions/comparison/export.inc"
#include "go-zetasql/public/functions/convert_proto/export.inc"
#include "go-zetasql/public/functions/convert_string/export.inc"
#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/public/types/value_representations/export.inc"
#include "go-absl/base/base/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/inlined_vector/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/hash/hash/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/cord/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-absl/types/span/export.inc"
#include "go-absl/types/variant/export.inc"

#endif
