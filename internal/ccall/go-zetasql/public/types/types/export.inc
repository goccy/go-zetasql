#ifndef ZETASQL_PUBLIC_TYPES_TYPES_EXPORT_H
#define ZETASQL_PUBLIC_TYPES_TYPES_EXPORT_H

#include "zetasql/public/types/annotation.h"
#include "zetasql/public/types/array_type.h"
#include "zetasql/public/types/collation.h"
#include "zetasql/public/types/enum_type.h"
#include "zetasql/public/types/extended_type.h"
#include "zetasql/public/types/proto_type.h"
#include "zetasql/public/types/simple_type.h"
#include "zetasql/public/types/simple_value.h"
#include "zetasql/public/types/struct_type.h"
#include "zetasql/public/types/type.h"
#include "zetasql/public/types/type_deserializer.h"
#include "zetasql/public/types/type_factory.h"
#include "zetasql/public/types/type_parameters.h"
#include "zetasql/public/types/value_equality_check_options.h"

#include "zetasql/public/types/annotation.cc"
#include "zetasql/public/types/array_type.cc"
#include "zetasql/public/types/collation.cc"
#include "zetasql/public/types/enum_type.cc"
#include "zetasql/public/types/extended_type.cc"
#include "zetasql/public/types/internal_utils.cc"
#include "zetasql/public/types/internal_utils.h"
#include "zetasql/public/types/proto_type.cc"

#define TypeKindInfo GO_EXPORT(TypeKindInfo)
#include "zetasql/public/types/simple_type.cc"
#undef TypeKindInfo

#include "zetasql/public/types/simple_value.cc"
#include "zetasql/public/types/struct_type.cc"
#include "zetasql/public/types/type.cc"
#include "zetasql/public/types/type_deserializer.cc"
#include "zetasql/public/types/type_factory.cc"
#include "zetasql/public/types/type_parameters.cc"

#if 0

namespace zetasql {

  absl::Status AnnotationMap::Serialize(AnnotationMapProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<AnnotationMap>> AnnotationMap::Deserialize(const AnnotationMapProto& proto) {
    std::unique_ptr<AnnotationMap> v;
    return v;
  }

  bool AnnotationMap::HasCompatibleStructure(const AnnotationMap* lhs,
                                             const AnnotationMap* rhs) {
    return false;
  }

  std::unique_ptr<AnnotationMap> AnnotationMap::Clone() const {
    std::unique_ptr<AnnotationMap> v;
    return v;
  }

  bool AnnotationMap::HasCompatibleStructure(const Type* type) const {
    return false;
  }

  bool AnnotationMap::NormalizeInternal() {
    return false;
  }

  bool AnnotationMap::IsNormalized() const {
    return false;
  }

  bool AnnotationMap::IsNormalizedAndNonEmpty(bool check_non_empty) const {
    return false;
  }

  int64_t AnnotationMap::GetEstimatedOwnedMemoryBytesSize() const {
    return 0;
  }

  bool AnnotationMap::SimpleValueEqualsHelper(const SimpleValue* lhs,
                                              const SimpleValue* rhs) {
    return false;
  }

  bool AnnotationMap::EqualsInternal(const AnnotationMap* lhs,
                                     const AnnotationMap* rhs,
                                     std::optional<int> annotation_spec_id) {
    return false;
  }

  bool AnnotationMap::EmptyInternal(std::optional<int> annotation_spec_id) const {
    return false;
  }

  std::unique_ptr<AnnotationMap> AnnotationMap::Create(const Type* type) {
    std::unique_ptr<AnnotationMap> v;
    return v;
  }

  std::string AnnotationMap::DebugStringInternal(std::optional<int> annotation_spec_id) const {
    return "";
  }

  StructAnnotationMap::StructAnnotationMap(const StructType* struct_type) {
  }

  absl::Status StructAnnotationMap::Serialize(AnnotationMapProto* proto) const {
    return absl::OkStatus();
  }

  std::string StructAnnotationMap::DebugStringInternal(std::optional<int> annotation_spec_id) const {
    return "";
  }

  absl::Status StructAnnotationMap::CloneIntoField(int i, const AnnotationMap* from) {
    return absl::OkStatus();
  }

  absl::Status ArrayAnnotationMap::CloneIntoElement(const AnnotationMap* from) {
    return absl::OkStatus();
  }

  ArrayAnnotationMap::ArrayAnnotationMap(const ArrayType* array_type) {
  }

  std::string ArrayAnnotationMap::DebugStringInternal(std::optional<int> annotation_spec_id) const {
    return "";
  }

  absl::Status ArrayAnnotationMap::Serialize(AnnotationMapProto* proto) const {
    return absl::OkStatus();
  }

}

namespace zetasql {

  ArrayType::ArrayType(const TypeFactory* factory, const Type* element_type)
    : Type(factory, TYPE_ARRAY),
      element_type_(element_type) {
  }

  ArrayType::~ArrayType() {}

  bool ArrayType::IsSupportedType(const LanguageOptions& language_options) const {
    return false;
  }

  bool ArrayType::EqualsForSameKind(const Type* that, bool equivalent) const {
    return false;
  }

  void ArrayType::DebugStringImpl(bool details, TypeOrStringVector* stack,
                                  std::string* debug_string) const {
  }

  bool ArrayType::SupportsOrdering(const LanguageOptions& language_options,
                                   std::string* type_description) const {
    return false;
  }

  bool ArrayType::SupportsEquality() const {
    return false;
  }

  bool ArrayType::SupportsGroupingImpl(const LanguageOptions& language_options,
                                       const Type** no_grouping_type) const {
    return false;
  }

  bool ArrayType::SupportsPartitioningImpl(const LanguageOptions& language_options,
                                           const Type** no_partitioning_type) const {
    return false;
  }

  absl::Status ArrayType::SerializeToProtoAndDistinctFileDescriptorsImpl(const BuildFileDescriptorSetMapOptions& options, TypeProto* type_proto,
                                                                         FileDescriptorSetMap* file_descriptor_set_map) const {
    return absl::OkStatus();
  }

  std::string ArrayType::ShortTypeName(ProductMode mode) const {
    return "";
  }

  std::string ArrayType::TypeName(ProductMode mode) const {
    return "";
  }

  absl::StatusOr<std::string> ArrayType::TypeNameWithParameters(const TypeParameters& type_params, ProductMode mode) const {
    return "";
  }

  absl::StatusOr<TypeParameters> ArrayType::ValidateAndResolveTypeParameters(const std::vector<TypeParameterValue>& type_parameter_values,
                                                                             ProductMode mode) const {
    TypeParameters v;
    return v;
  }

  absl::Status ArrayType::ValidateResolvedTypeParameters(const TypeParameters& type_parameters, ProductMode mode) const {
    return absl::OkStatus();
  }

  bool ArrayType::EqualsImpl(const ArrayType* const type1,
                             const ArrayType* const type2, bool equivalent) {
    return false;
  }

  void ArrayType::CopyValueContent(const ValueContent& from,
                                   ValueContent* to) const {
  }

  void ArrayType::ClearValueContent(const ValueContent& value) const {
  }

  absl::HashState ArrayType::HashTypeParameter(absl::HashState state) const {
    return state;
  }

  absl::HashState ArrayType::HashValueContent(const ValueContent& value, absl::HashState state) const {
    return state;
  }

  bool ArrayType::ValueContentEquals(const ValueContent& x, const ValueContent& y,
                                     const ValueEqualityCheckOptions& options) const {
    return false;
  }

  bool ArrayType::ValueContentLess(const ValueContent& x, const ValueContent& y,
                                   const Type* other_type) const {
    return false;
  }

  std::string ArrayType::FormatValueContent(const ValueContent& value, const FormatValueContentOptions& options) const {
    return "";
  }

  absl::Status ArrayType::SerializeValueContent(const ValueContent& value,
                                                ValueProto* value_proto) const {
    return absl::OkStatus();
  }

  absl::Status ArrayType::DeserializeValueContent(const ValueProto& value_proto,
                                                  ValueContent* value) const {
    return absl::OkStatus();
  }

}

namespace zetasql {

  Collation Collation::MakeScalar(absl::string_view collation_name) {
    Collation v;
    return v;
  }

  absl::StatusOr<Collation> Collation::MakeCollation(const AnnotationMap& annotation_map) {
    Collation v;
    return v;
  }

  bool Collation::Equals(const Collation& that) const {
    return false;
  }

  absl::Status Collation::Serialize(CollationProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<Collation> Collation::Deserialize(const CollationProto& proto) {
    Collation v;
    return v;
  }

  std::string Collation::DebugString() const {
    return "";
  }

  bool Collation::HasCompatibleStructure(const Type* type) const {
    return false;
  }

  std::string Collation::ToString(const std::vector<Collation>& collation_list) {
    return "";
  }

}

namespace zetasql {

  EnumType::EnumType(const TypeFactory* factory,
                     const google::protobuf::EnumDescriptor* enum_descr,
                     const internal::CatalogName* catalog_name)
    : Type(factory, TYPE_ENUM),
      enum_descriptor_(enum_descr),
      catalog_name_(catalog_name) {
  }

  EnumType::~EnumType() {
  }

  bool EnumType::EqualsForSameKind(const Type* that, bool equivalent) const {
    return false;
  }

  void EnumType::DebugStringImpl(bool details, TypeOrStringVector* stack,
                                 std::string* debug_string) const {
  }

  const google::protobuf::EnumDescriptor* EnumType::enum_descriptor() const {
    return nullptr;
  }

  absl::Status EnumType::SerializeToProtoAndDistinctFileDescriptorsImpl(
                                                                        const BuildFileDescriptorSetMapOptions& options, TypeProto* type_proto,
                                                                        FileDescriptorSetMap* file_descriptor_set_map) const {
    return absl::OkStatus();
  }

  std::string EnumType::TypeName() const {
    return "";
  }

  std::string EnumType::ShortTypeName(ProductMode mode_unused) const {
    return "";
  }

  std::string EnumType::TypeName(ProductMode mode_unused) const {
    return "";
  }

  bool EnumType::FindName(int number, const std::string** name) const {
    return false;
  }

  absl::Span<const std::string> EnumType::CatalogNamePath() const {
    absl::Span<const std::string> v;
    return v;
  }

  bool EnumType::FindNumber(const std::string& name, int* number) const {
    return false;
  }

  bool EnumType::EqualsImpl(const EnumType* const type1,
                            const EnumType* const type2, bool equivalent) {
    return false;
  }

  bool EnumType::IsSupportedType(const LanguageOptions& language_options) const {
    return false;
  }

  absl::HashState EnumType::HashTypeParameter(absl::HashState state) const {
    return state;
  }

  absl::HashState EnumType::HashValueContent(const ValueContent& value,
                                             absl::HashState state) const {
    return state;
  }

  bool EnumType::ValueContentEquals(const ValueContent& x, const ValueContent& y,
                                    const ValueEqualityCheckOptions& options) const {
    return false;
  }

  bool EnumType::ValueContentLess(const ValueContent& x, const ValueContent& y,
                                  const Type* other_type) const {
    return false;
  }

  std::string EnumType::FormatValueContent(const ValueContent& value, const FormatValueContentOptions& options) const {
    return "";
  }

  absl::Status EnumType::SerializeValueContent(const ValueContent& value,
                                               ValueProto* value_proto) const {
    return absl::OkStatus();
  }

  absl::Status EnumType::DeserializeValueContent(const ValueProto& value_proto,
                                                 ValueContent* value) const {
    return absl::OkStatus();
  }

}

namespace zetasql {

  bool ExtendedType::IsSupportedType(const LanguageOptions& language_options) const {
    return false;
  }

  absl::StatusOr<std::string> ExtendedType::TypeNameWithParameters(const TypeParameters& type_params, ProductMode mode) const {
    return "";
  }

}

namespace zetasql {
  namespace internal {

    int64_t FileDescriptorSetMapTotalSize(const FileDescriptorSetMap& file_descriptor_set_map) {
      return 0;
    }

    absl::Status PopulateDistinctFileDescriptorSets(const BuildFileDescriptorMapOptions& options,
                                                    const google::protobuf::FileDescriptor* file_descr,
                                                    FileDescriptorSetMap* file_descriptor_set_map,
                                                    int* file_descriptor_set_index) {
      return absl::OkStatus();
    }

  }
}

namespace zetasql {

  ProtoType::ProtoType(const TypeFactory* factory,
                       const google::protobuf::Descriptor* descriptor,
                       const internal::CatalogName* catalog_name)
    : Type(factory, TYPE_PROTO),
      descriptor_(descriptor),
      catalog_name_(catalog_name) {
  }

  ProtoType::~ProtoType() {
  }

  bool ProtoType::IsSupportedType(const LanguageOptions& language_options) const {
    return false;
  }

  bool ProtoType::EqualsForSameKind(const Type* that, bool equivalent) const {
    return false;
  }

  void ProtoType::DebugStringImpl(bool details, TypeOrStringVector* stack,
                                  std::string* debug_string) const {
  }

  bool ProtoType::SupportsOrdering(const LanguageOptions& language_options,
                                   std::string* type_description) const {
    return false;
  }

  const google::protobuf::Descriptor* ProtoType::descriptor() const {
    return nullptr;
  }

  const google::protobuf::FieldDescriptor* ProtoType::map_key() const {
    return nullptr;
  }

  const google::protobuf::FieldDescriptor* ProtoType::map_value() const {
    return nullptr;
  }

  absl::Status ProtoType::SerializeToProtoAndDistinctFileDescriptorsImpl(
                                                                         const BuildFileDescriptorMapOptions& options, TypeProto* type_proto,
                                                                         FileDescriptorSetMap* file_descriptor_set_map) const {
    return absl::OkStatus();
  }

  absl::Status ProtoType::GetFieldTypeByTagNumber(int number,
                                                  TypeFactory* factory,
                                                  bool use_obsolete_timestamp,
                                                  const Type** type,
                                                  std::string* name) const {
    return absl::OkStatus();
  }

  absl::Status ProtoType::GetFieldTypeByName(const std::string& name,
                                             TypeFactory* factory,
                                             bool use_obsolete_timestamp,
                                             const Type** type,
                                             int* number) const {
    return absl::OkStatus();
  }

  std::string ProtoType::TypeName() const {
    return "";
  }

  std::string ProtoType::ShortTypeName(ProductMode mode_unused) const {
    return "";
  }

  std::string ProtoType::TypeName(ProductMode mode_unused) const {
    return "";
  }

  absl::Span<const std::string> ProtoType::CatalogNamePath() const {
    absl::Span<const std::string> v;
    return v;
  }

  absl::Status ProtoType::GetTypeKindFromFieldDescriptor(const google::protobuf::FieldDescriptor* field, bool ignore_format_annotations,
                                                         bool use_obsolete_timestamp, TypeKind* kind) {
    return absl::OkStatus();
  }

  absl::Status ProtoType::FieldDescriptorToTypeKind(bool ignore_annotations, const google::protobuf::FieldDescriptor* field,
                                                    TypeKind* kind) {
    return absl::OkStatus();
  }

  absl::Status ProtoType::FieldDescriptorToTypeKind(const google::protobuf::FieldDescriptor* field, bool use_obsolete_timestamp,
                                                    TypeKind* kind) {
    return absl::OkStatus();
  }

  const google::protobuf::FieldDescriptor* ProtoType::FindFieldByNameIgnoreCase(
                                                                                const google::protobuf::Descriptor* descriptor, const std::string& name) {
    return nullptr;
  }

  bool ProtoType::HasFormatAnnotation(const google::protobuf::FieldDescriptor* field) {
    return false;
  }

  FieldFormat::Format ProtoType::GetFormatAnnotationImpl(const google::protobuf::FieldDescriptor* field) {
    FieldFormat::Format v;
    return v;
  }

  bool ProtoType::HasSubfieldWithFormat(const google::protobuf::Descriptor* descriptor,
                                        FieldFormat::Format format) {
    return false;
  }

  bool ProtoType::HasSubfieldWithFormat(const google::protobuf::FieldDescriptor* field,
                                        FieldFormat::Format format) {
    return false;
  }

  FieldFormat::Format ProtoType::GetFormatAnnotation(const google::protobuf::FieldDescriptor* field) {
    FieldFormat::Format v;
    return v;
  }

  bool ProtoType::GetUseDefaultsExtension(const google::protobuf::FieldDescriptor* field) {
    return false;
  }

  bool ProtoType::GetIsWrapperAnnotation(const google::protobuf::Descriptor* message) {
    return false;
  }

  bool ProtoType::GetIsStructAnnotation(const google::protobuf::Descriptor* message) {
    return false;
  }

  bool ProtoType::HasStructFieldName(const google::protobuf::FieldDescriptor* field) {
    return false;
  }

  const std::string& ProtoType::GetStructFieldName(const google::protobuf::FieldDescriptor* field) {
    std::string *v;
    return *v;
  }

  Type::HasFieldResult ProtoType::HasFieldImpl(const std::string& name,
                                               int* field_id,
                                               bool include_pseudo_fields) const {
    Type::HasFieldResult v;
    return v;
  }

  bool ProtoType::HasAnyFields() const {
    return false;
  }

  bool ProtoType::EqualsImpl(const ProtoType* const type1,
                             const ProtoType* const type2, bool equivalent) {
    return false;
  }

  void ProtoType::CopyValueContent(const ValueContent& from,
                                   ValueContent* to) const {
  }

  void ProtoType::ClearValueContent(const ValueContent& value) const {
  }

  uint64_t ProtoType::GetValueContentExternallyAllocatedByteSize(const ValueContent& value) const {
    return 0;
  }

  absl::HashState ProtoType::HashTypeParameter(absl::HashState state) const {
    return state;
  }

  absl::HashState ProtoType::HashValueContent(const ValueContent& value, absl::HashState state) const {
    return state;
  }

  bool ProtoType::ValueContentEquals(const ValueContent& x, const ValueContent& y,
                                     const ValueEqualityCheckOptions& options) const {
    return false;
  }

  bool ProtoType::ValueContentLess(const ValueContent& x, const ValueContent& y,
                                   const Type* other_type) const {
    return false;
  }

  std::string ProtoType::FormatValueContent(const ValueContent& value, const FormatValueContentOptions& options) const {
    return "";
  }

  absl::Status ProtoType::SerializeValueContent(const ValueContent& value,
                                                ValueProto* value_proto) const {
    return absl::OkStatus();
  }

  absl::Status ProtoType::DeserializeValueContent(const ValueProto& value_proto,
                                                  ValueContent* value) const {
    return absl::OkStatus();
  }

}

namespace zetasql {

  using DateValueContentType = int32_t;       // Used with TYPE_DATE.
  using TimestampValueContentType = int64_t;  // Used with TYPE_TIMESTAMP.
  using TimeValueContentType = int32_t;       // Used with TYPE_TIME.
  using DateTimeValueContentType = int64_t;   // Used with TYPE_DATETIME.

  SimpleType::SimpleType(const TypeFactory* factory, TypeKind kind)
    : Type(factory, kind) {
  }

  SimpleType::~SimpleType() {
  }

  bool SimpleType::IsSupportedType(const LanguageOptions& language_options) const {
    return false;
  }

  void SimpleType::DebugStringImpl(bool details, TypeOrStringVector* stack,
                                   std::string* debug_string) const {
  }

  absl::Status SimpleType::SerializeToProtoAndDistinctFileDescriptorsImpl(const BuildFileDescriptorSetMapOptions& options, TypeProto* type_proto,
                                                                          FileDescriptorSetMap* file_descriptor_set_map) const {
    return absl::OkStatus();
  }

  std::string SimpleType::TypeName(ProductMode mode) const {
    return "";
  }

  absl::StatusOr<std::string> SimpleType::TypeNameWithParameters(const TypeParameters& type_params, ProductMode mode) const {
    return "";
  }

  TypeKind SimpleType::GetTypeKindIfSimple(absl::string_view type_name, ProductMode mode,
                                           const LanguageOptions::LanguageFeatureSet* language_features) {
    TypeKind v;
    return v;
  }

  bool SimpleType::SupportsGroupingImpl(const LanguageOptions& language_options,
                                        const Type** no_grouping_type) const {
    return false;
  }

  void SimpleType::CopyValueContent(TypeKind kind, const ValueContent& from,
                                    ValueContent* to) {
  }

  void SimpleType::CopyValueContent(const ValueContent& from,
                                    ValueContent* to) const {
  }

  void SimpleType::ClearValueContent(TypeKind kind, const ValueContent& value) {
  }

  void SimpleType::ClearValueContent(const ValueContent& value) const {
  }

  uint64_t SimpleType::GetValueContentExternallyAllocatedByteSize(const ValueContent& value) const {
    return 0;
  }

  absl::HashState SimpleType::HashTypeParameter(absl::HashState state) const {
    return state;
  }

  absl::HashState SimpleType::HashValueContent(const ValueContent& value, absl::HashState state) const {
    return state;
  }

  bool AllPartsIntervalMatch(const IntervalValue& x, const IntervalValue& y) {
    return false;
  }

  bool SimpleType::ValueContentEquals(const ValueContent& x, const ValueContent& y,
                                      const ValueEqualityCheckOptions& options) const {
    return false;
  }

  bool SimpleType::ValueContentLess(const ValueContent& x, const ValueContent& y,
                                    const Type* other_type) const {
    return false;
  }

  std::string SimpleType::FormatValueContent(const ValueContent& value, const FormatValueContentOptions& options) const {
    return "";
  }

  absl::Status SimpleType::SerializeValueContent(const ValueContent& value,
                                                 ValueProto* value_proto) const {
    return absl::OkStatus();
  }

  absl::Status SimpleType::DeserializeValueContent(const ValueProto& value_proto,
                                                   ValueContent* value) const {
    return absl::OkStatus();
  }

  absl::Time SimpleType::GetTimestampValue(const ValueContent& value) {
    absl::Time v;
    return v;
  }

  absl::Status SimpleType::SetTimestampValue(absl::Time time,
                                             ValueContent* value) {
    return absl::OkStatus();
  }

  TimeValue SimpleType::GetTimeValue(const ValueContent& value) {
    TimeValue v;
    return v;
  }

  absl::Status SimpleType::SetTimeValue(TimeValue time, ValueContent* value) {
    return absl::OkStatus();
  }

  DatetimeValue SimpleType::GetDateTimeValue(const ValueContent& value) {
    DatetimeValue v;
    return v;
  }

  absl::Status SimpleType::SetDateTimeValue(DatetimeValue datetime,
                                            ValueContent* value) {
    return absl::OkStatus();
  }

  absl::StatusOr<TypeParameters> SimpleType::ValidateAndResolveTypeParameters(const std::vector<TypeParameterValue>& type_parameter_values,
                                                                              ProductMode mode) const {
    TypeParameters v;
    return v;
  }

  absl::StatusOr<TypeParameters> SimpleType::ResolveStringBytesTypeParameters(const std::vector<TypeParameterValue>& type_parameter_values,
                                                                              ProductMode mode) const {
    TypeParameters v;
    return v;
  }

  absl::StatusOr<TypeParameters> SimpleType::ResolveNumericBignumericTypeParameters(const std::vector<TypeParameterValue>& type_parameter_values,
                                                                                    ProductMode mode) const {
    TypeParameters v;
    return v;
  }

  absl::Status SimpleType::ValidateResolvedTypeParameters(const TypeParameters& type_parameters, ProductMode mode) const {
    return absl::OkStatus();
  }

  absl::Status SimpleType::ValidateNumericTypeParameters(const NumericTypeParametersProto& numeric_param, ProductMode mode) const {
    return absl::OkStatus();
  }

}

namespace zetasql {

  SimpleValue SimpleValue::String(std::string v) {
    SimpleValue value;
    return value;
  }

  SimpleValue SimpleValue::Int64(int64_t v) {
    SimpleValue value;
    return value;
  }

  SimpleValue SimpleValue::Bool(bool v) {
    SimpleValue value;
    return value;
  }

  SimpleValue SimpleValue::Double(double v) {
    SimpleValue value;
    return value;
  }

  SimpleValue SimpleValue::Bytes(std::string v) {
    SimpleValue value;
    return value;
  }

  SimpleValue::SimpleValue(SimpleValue&& that) {
  }

  SimpleValue& SimpleValue::operator=(const SimpleValue& that) {
    return *this;
  }

  SimpleValue& SimpleValue::operator=(SimpleValue&& that) {
    return *this;
  }

  void SimpleValue::Clear() {
  }

  int64_t SimpleValue::GetEstimatedOwnedMemoryBytesSize() const {
    return 0;
  }

  void SimpleValue::CopyFrom(const SimpleValue& that) {
  }

  int64_t SimpleValue::int64_value() const {
    return 0;
  }

  const std::string& SimpleValue::string_value() const {
    std::string *v;
    return *v;
  }

  bool SimpleValue::bool_value() const {
    return false;
  }

  double SimpleValue::double_value() const {
    return 0;
  }

  const std::string& SimpleValue::bytes_value() const {
    std::string *v;
    return *v;
  }

  absl::Status SimpleValue::Serialize(SimpleValueProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<SimpleValue> SimpleValue::Deserialize(const SimpleValueProto& proto) {
    SimpleValue v;
    return v;
  }

  bool SimpleValue::Equals(const SimpleValue& that) const {
    return false;
  }

  std::string SimpleValue::DebugString() const {
    return "";
  }

}

namespace zetasql {

  StructType::StructType(const TypeFactory* factory,
                         std::vector<StructField> fields, int nesting_depth)
    : Type(factory, TYPE_STRUCT),
      fields_(std::move(fields)),
      nesting_depth_(nesting_depth) {}

  bool StructType::IsSupportedType(const LanguageOptions& language_options) const {
    return false;
  }

  bool StructType::EqualsForSameKind(const Type* that, bool equivalent) const {
    return false;
  }

  void StructType::DebugStringImpl(bool details, TypeOrStringVector* stack,
                                   std::string* debug_string) const {
  }

  bool StructType::SupportsGroupingImpl(const LanguageOptions& language_options,
                                        const Type** no_grouping_type) const {
    return false;
  }

  bool StructType::SupportsPartitioningImpl(const LanguageOptions& language_options,
                                            const Type** no_partitioning_type) const {
    return false;
  }

  StructType::~StructType() {}

  bool StructType::SupportsOrdering(const LanguageOptions& language_options,
                                    std::string* type_description) const {
    return false;
  }

  bool StructType::SupportsEquality() const {
    return false;
  }

  bool StructType::UsingFeatureV12CivilTimeType() const {
    return false;
  }

  absl::Status StructType::SerializeToProtoAndDistinctFileDescriptorsImpl(const BuildFileDescriptorMapOptions& options, TypeProto* type_proto,
                                                                          FileDescriptorSetMap* file_descriptor_set_map) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::string> StructType::TypeNameImpl(int field_limit,
                                                       const std::function<absl::StatusOr<std::string>(const zetasql::Type*, int field_index)>& field_debug_fn) const {
    return "";
  }

  std::string StructType::ShortTypeName(ProductMode mode) const {
    return "";
  }

  std::string StructType::TypeName(ProductMode mode) const {
    return "";
  }

  absl::StatusOr<std::string> StructType::TypeNameWithParameters(const TypeParameters& type_params, ProductMode mode) const {
    return "";
  }

  absl::StatusOr<TypeParameters> StructType::ValidateAndResolveTypeParameters(const std::vector<TypeParameterValue>& type_parameter_values,
                                                                              ProductMode mode) const {
    TypeParameters v;
    return v;
  }

  absl::Status StructType::ValidateResolvedTypeParameters(const TypeParameters& type_parameters, ProductMode mode) const {
    return absl::OkStatus();
  }

  const StructType::StructField* StructType::FindField(absl::string_view name,
                                                       bool* is_ambiguous,
                                                       int* found_idx) const {
    return nullptr;
  }

  Type::HasFieldResult StructType::HasFieldImpl(const std::string& name, int* field_id, bool include_pseudo_fields) const {
    Type::HasFieldResult v;
    return v;
  }

  bool StructType::HasAnyFields() const {
    return false;
  }

  int64_t GetEstimatedStructFieldOwnedMemoryBytesSize(const StructField& field) {
    return 0;
  }

  int64_t StructType::GetEstimatedOwnedMemoryBytesSize() const {
    return 0;
  }

  bool StructType::FieldEqualsImpl(const StructType::StructField& field1,
                                   const StructType::StructField& field2,
                                   bool equivalent) {
    return false;
  }

  bool StructType::EqualsImpl(const StructType* const type1,
                              const StructType* const type2, bool equivalent) {
    return false;
  }

  void StructType::CopyValueContent(const ValueContent& from,
                                    ValueContent* to) const {
  }

  void StructType::ClearValueContent(const ValueContent& value) const {
  }

  absl::HashState StructType::HashTypeParameter(absl::HashState state) const {
    return state;
  }

  absl::HashState StructType::HashValueContent(const ValueContent& value, absl::HashState state) const {
    return state;
  }

  bool StructType::ValueContentEquals(const ValueContent& x, const ValueContent& y,
                                      const ValueEqualityCheckOptions& options) const {
    return false;
  }

  bool StructType::ValueContentLess(const ValueContent& x, const ValueContent& y,
                                    const Type* other_type) const {
    return false;
  }

  std::string StructType::FormatValueContent(const ValueContent& value, const FormatValueContentOptions& options) const {
    return "";
  }

  absl::Status StructType::SerializeValueContent(const ValueContent& value,
                                                 ValueProto* value_proto) const {
    return absl::OkStatus();
  }

  absl::Status StructType::DeserializeValueContent(const ValueProto& value_proto,
                                                   ValueContent* value) const {
    return absl::OkStatus();
  }

}

namespace zetasql {

  Type::Type(const TypeFactory* factory, TypeKind kind)
    : type_store_(internal::TypeStoreHelper::GetTypeStore(factory)),
      kind_(kind) {}

  Type::~Type() {
  }

  bool Type::IsSimpleType(TypeKind kind) {
    return false;
  }

  bool Type::IsSupportedSimpleTypeKind(TypeKind kind,
                                       const LanguageOptions& language_options) {
    return false;
  }

  TypeKind Type::ResolveBuiltinTypeNameToKindIfSimple(absl::string_view type_name,
                                                      ProductMode mode) {
    TypeKind v;
    return v;
  }

  TypeKind Type::ResolveBuiltinTypeNameToKindIfSimple(absl::string_view type_name, const LanguageOptions& language_options) {
    TypeKind v;
    return v;
  }

  std::string Type::TypeKindToString(TypeKind kind, ProductMode mode) {
    return "";
  }

  std::string Type::TypeKindListToString(const std::vector<TypeKind>& kinds,
                                         ProductMode mode) {
    return "";
  }

  std::string Type::TypeListToString(TypeListView types, ProductMode mode) {
    return "";
  }

  int Type::KindSpecificity(TypeKind kind) {
    return 0;
  }

  int Type::GetTypeCoercionCost(TypeKind kind1, TypeKind kind2) {
    return 0;
  }

  bool Type::KindSpecificityLess(TypeKind kind1, TypeKind kind2) {
    return false;
  }

  bool Type::TypeSpecificityLess(const Type* t1, const Type* t2) {
    return false;
  }

  absl::Status Type::SerializeToProtoAndFileDescriptors(TypeProto* type_proto,
                                                        google::protobuf::FileDescriptorSet* file_descriptor_set,
                                                        std::set<const google::protobuf::FileDescriptor*>* file_descriptors) const {
    return absl::OkStatus();
  }

  absl::Status Type::SerializeToProtoAndDistinctFileDescriptors(TypeProto* type_proto,
                                                                FileDescriptorSetMap* file_descriptor_set_map) const {
    return absl::OkStatus();
  }

  absl::Status Type::SerializeToProtoAndDistinctFileDescriptors(TypeProto* type_proto,
                                                                absl::optional<int64_t> file_descriptor_sets_max_size_bytes,
                                                                FileDescriptorSetMap* file_descriptor_set_map) const {
    return absl::OkStatus();
  }

  absl::Status Type::SerializeToSelfContainedProto(TypeProto* type_proto) const {
    return absl::OkStatus();
  }

  std::string Type::ShortTypeName(ProductMode mode) const {
    return "";
  }

  std::string Type::DebugString(bool details) const {
    return "";
  }

  bool Type::SupportsGrouping(const LanguageOptions& language_options,
                              std::string* type_description) const {
    return false;
  }

  bool Type::SupportsGroupingImpl(const LanguageOptions& language_options,
                                  const Type** no_grouping_type) const {
    return false;
  }

  bool Type::SupportsPartitioning(const LanguageOptions& language_options,
                                  std::string* type_description) const {
    return false;
  }

  bool Type::SupportsPartitioningImpl(const LanguageOptions& language_options,
                                      const Type** no_partitioning_type) const {
    return false;
  }

  bool Type::SupportsOrdering(const LanguageOptions& language_options,
                              std::string* type_description) const {
    return false;
  }

  bool Type::SupportsOrdering() const {
    return false;
  }

  bool Type::SupportsEquality(const LanguageOptions& language_options) const {
    return false;
  }

  void Type::CopyValueContent(const ValueContent& from, ValueContent* to) const {
  }

  absl::HashState Type::Hash(absl::HashState state) const {
    return state;
  }

  absl::Status Type::TypeMismatchError(const ValueProto& value_proto) const {
    return absl::OkStatus();
  }

  bool TypeEquals::operator()(const Type* const type1,
                              const Type* const type2) const {
    return false;
  }

  bool TypeEquivalent::operator()(const Type* const type1,
                                  const Type* const type2) const {
    return false;
  }

  size_t TypeHash::operator()(const Type* const type) const {
    return 0;
  }

  absl::StatusOr<TypeParameters> Type::ValidateAndResolveTypeParameters(const std::vector<TypeParameterValue>& type_parameter_values,
                                                                        ProductMode mode) const {
    TypeParameters v;
    return v;
  }

  absl::Status Type::ValidateResolvedTypeParameters(const TypeParameters& type_parameters, ProductMode mode) const {
    return absl::OkStatus();
  }

}

namespace zetasql {

  absl::StatusOr<const Type*> TypeDeserializer::Deserialize(const TypeProto& type_proto) const {
    return nullptr;
  }

  absl::Status TypeDeserializer::DeserializeDescriptorPoolsFromSelfContainedProto(const TypeProto& type_proto,
                                                                                  absl::Span<google::protobuf::DescriptorPool* const> pools) {
    return absl::OkStatus();
  }

}

namespace zetasql {

  namespace internal {

    TypeStore::TypeStore(bool keep_alive_while_referenced_from_value)
      : keep_alive_while_referenced_from_value_(keep_alive_while_referenced_from_value) {}

    TypeStore::~TypeStore() {
    }

    void TypeStore::Ref() const {
    }

    void TypeStore::Unref() const {
    }

    void TypeStoreHelper::RefFromValue(const TypeStore* store) {
    }

    void TypeStoreHelper::UnrefFromValue(const TypeStore* store) {
    }

    const TypeStore* TypeStoreHelper::GetTypeStore(const TypeFactory* factory) {
      return nullptr;
    }

    int64_t TypeStoreHelper::Test_GetRefCount(const TypeStore* store) {
      return 0;
    }

  }

  TypeFactory::TypeFactory(const TypeFactoryOptions& options)
    : store_(new internal::TypeStore(options.keep_alive_while_referenced_from_value)),
      nesting_depth_limit_(0),
      estimated_memory_used_by_types_(0) {
  }

  TypeFactory::~TypeFactory() {
  }

  int TypeFactory::nesting_depth_limit() const {
    return 0;
  }

  void TypeFactory::set_nesting_depth_limit(int value) {
  }

  int64_t TypeFactory::GetEstimatedOwnedMemoryBytesSize() const {
    return 0;
  }

  template <class TYPE>
  const TYPE* TypeFactory::TakeOwnership(const TYPE* type) {
    return nullptr;
  }

  template <class TYPE>
  const TYPE* TypeFactory::TakeOwnershipLocked(const TYPE* type) {
    return nullptr;
  }

  template <class TYPE>
  const TYPE* TypeFactory::TakeOwnershipLocked(const TYPE* type,
                                               int64_t type_owned_bytes_size) {
    return nullptr;
  }

  const Type* TypeFactory::get_int32() {
    return nullptr;
  }

  const Type* TypeFactory::get_int64() {
    return nullptr;
  }

  const Type* TypeFactory::get_uint32() {
    return nullptr;
  }

  const Type* TypeFactory::get_uint64() {
    return nullptr;
  }

  const Type* TypeFactory::get_string() {
    return nullptr;
  }

  const Type* TypeFactory::get_bytes() {
    return nullptr;
  }

  const Type* TypeFactory::get_bool() {
    return nullptr;
  }

  const Type* TypeFactory::get_float() {
    return nullptr;
  }

  const Type* TypeFactory::get_double() {
    return nullptr;
  }

  const Type* TypeFactory::get_date() {
    return nullptr;
  }

  const Type* TypeFactory::get_timestamp() {
    return nullptr;
  }

  const Type* TypeFactory::get_time() {
    return nullptr;
  }

  const Type* TypeFactory::get_datetime() {
    return nullptr;
  }

  const Type* TypeFactory::get_interval() {
    return nullptr;
  }

  const Type* TypeFactory::get_geography() {
    return nullptr;
  }

  const Type* TypeFactory::get_numeric() {
    return nullptr;
  }

  const Type* TypeFactory::get_bignumeric() {
    return nullptr;
  }

  const Type* TypeFactory::get_json() {
    return nullptr;
  }

  const Type* TypeFactory::MakeSimpleType(TypeKind kind) {
    return nullptr;
  }

  absl::Status TypeFactory::MakeArrayType(const Type* element_type,
                                          const ArrayType** result) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::MakeArrayType(const Type* element_type,
                                          const Type** result) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::MakeStructType(absl::Span<const StructType::StructField> fields,
                                           const StructType** result) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::MakeStructType(absl::Span<const StructType::StructField> fields, const Type** result) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::MakeStructTypeFromVector(std::vector<StructType::StructField> fields, const StructType** result) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::MakeStructTypeFromVector(std::vector<StructType::StructField> fields, const Type** result) {
    return absl::OkStatus();
  }

  template <typename Descriptor>
  const auto* TypeFactory::MakeDescribedType(const Descriptor* descriptor,
                                             absl::Span<const std::string> catalog_name_path) {
    return nullptr;
  }

  template <>
  const auto*& TypeFactory::FindOrCreateCachedType<google::protobuf::Descriptor>(const google::protobuf::Descriptor* descriptor,
                                                                                 const internal::CatalogName* catalog) {
    return catalog;
  }

  template <>
  const auto*& TypeFactory::FindOrCreateCachedType<google::protobuf::EnumDescriptor>(const google::protobuf::EnumDescriptor* descriptor,
                                                                                     const internal::CatalogName* catalog) {
    return catalog;
  }

  const internal::CatalogName* TypeFactory::FindOrCreateCatalogName(absl::Span<const std::string> catalog_name_path) {
    return nullptr;
  }

  absl::Status TypeFactory::MakeProtoType(const google::protobuf::Descriptor* descriptor, const ProtoType** result,
                                          absl::Span<const std::string> catalog_name_path) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::MakeProtoType(const google::protobuf::Descriptor* descriptor, const Type** result,
                                          absl::Span<const std::string> catalog_name_path) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::MakeEnumType(const google::protobuf::EnumDescriptor* enum_descriptor, const EnumType** result,
                                         absl::Span<const std::string> catalog_name_path) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::MakeEnumType(const google::protobuf::EnumDescriptor* enum_descriptor, const Type** result,
                                         absl::Span<const std::string> catalog_name_path) {
    return absl::OkStatus();
  }

  absl::StatusOr<const ExtendedType*> TypeFactory::InternalizeExtendedType(std::unique_ptr<const ExtendedType> extended_type) {
    return nullptr;
  }

  absl::Status TypeFactory::MakeUnwrappedTypeFromProto(const google::protobuf::Descriptor* message, bool use_obsolete_timestamp,
                                                       const Type** result_type) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::UnwrapTypeIfAnnotatedProto(const Type* input_type, bool use_obsolete_timestamp,
                                                       const Type** result_type) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::UnwrapTypeIfAnnotatedProtoImpl(const Type* input_type, bool use_obsolete_timestamp,
                                                           const Type** result_type,
                                                           std::set<const google::protobuf::Descriptor*>* ancestor_messages) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::MakeUnwrappedTypeFromProtoImpl(const google::protobuf::Descriptor* message, const Type* existing_message_type,
                                                           bool use_obsolete_timestamp, const Type** result_type,
                                                           std::set<const google::protobuf::Descriptor*>* ancestor_messages) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::GetProtoFieldTypeWithKind(const google::protobuf::FieldDescriptor* field_descr, TypeKind kind,
                                                      const Type** type) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::GetProtoFieldType(bool ignore_annotations, const google::protobuf::FieldDescriptor* field_descr,
                                              const Type** type) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::GetProtoFieldType(const google::protobuf::FieldDescriptor* field_descr, bool use_obsolete_timestamp,
                                              const Type** type) {
    return absl::OkStatus();
  }

  absl::StatusOr<const AnnotationMap*> TypeFactory::TakeOwnership(std::unique_ptr<AnnotationMap> annotation_map) {
    return nullptr;
  }

  absl::Status TypeFactory::DeserializeAnnotationMap(const AnnotationMapProto& proto, const AnnotationMap** annotation_map) {
    return absl::OkStatus();
  }

  const AnnotationMap* TypeFactory::TakeOwnershipInternal(const AnnotationMap* annotation_map) {
    return nullptr;
  }

  absl::Status TypeFactory::DeserializeFromProtoUsingExistingPool(const TypeProto& type_proto, const google::protobuf::DescriptorPool* pool,
                                                                  const Type** type) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::DeserializeFromProtoUsingExistingPools(const TypeProto& type_proto,
                                                                   const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                                                   const Type** type) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::DeserializeFromSelfContainedProto(const TypeProto& type_proto, google::protobuf::DescriptorPool* pool,
                                                              const Type** type) {
    return absl::OkStatus();
  }

  absl::Status TypeFactory::DeserializeFromSelfContainedProtoWithDistinctFiles(const TypeProto& type_proto,
                                                                               const std::vector<google::protobuf::DescriptorPool*>& pools, const Type** type) {
    return absl::OkStatus();
  }

  bool IsValidTypeKind(int kind) {
    return false;
  }

  namespace types {

    const Type* Int32Type() {
      return nullptr;
    }
    
    const Type* Int64Type() {
      return nullptr;
    }

    const Type* Uint32Type() {
      return nullptr;
    }

    const Type* Uint64Type() {
      return nullptr;
    }
    
    const Type* BoolType() {
      return nullptr;
    }

    const Type* FloatType() {
      return nullptr;
    }

    const Type* DoubleType() {
      return nullptr;
    }

    const Type* StringType() {
      return nullptr;
    }

    const Type* BytesType() {
      return nullptr;
    }

    const Type* DateType() {
      return nullptr;
    }

    const Type* TimestampType() {
      return nullptr;
    }

    const Type* TimeType() {
      return nullptr;
    }

    const Type* DatetimeType() {
      return nullptr;
    }

    const Type* IntervalType() {
      return nullptr;
    }

    const Type* GeographyType() {
      return nullptr;
    }

    const Type* NumericType() {
      return nullptr;
    }

    const Type* BigNumericType() {
      return nullptr;
    }

    const Type* JsonType() {
      return nullptr;
    }

    const StructType* EmptyStructType() {
      return nullptr;
    }

    const EnumType* DatePartEnumType() {
      return nullptr;
    }

    const EnumType* NormalizeModeEnumType() {
      return nullptr;
    }

    const ArrayType* Int32ArrayType() {
      return nullptr;
    }

    const ArrayType* Int64ArrayType() {
      return nullptr;
    }

    const ArrayType* Uint32ArrayType() {
      return nullptr;
    }

    const ArrayType* Uint64ArrayType() {
      return nullptr;
    }

    const ArrayType* BoolArrayType() {
      return nullptr;
    }

    const ArrayType* FloatArrayType() {
      return nullptr;
    }

    const ArrayType* DoubleArrayType() {
      return nullptr;
    }
    
    const ArrayType* StringArrayType() {
      return nullptr;
    }

    const ArrayType* BytesArrayType() {
      return nullptr;
    }

    const ArrayType* TimestampArrayType() {
      return nullptr;
    }

    const ArrayType* DateArrayType() {
      return nullptr;
    }

    const ArrayType* DatetimeArrayType() {
      return nullptr;
    }

    const ArrayType* TimeArrayType() {
      return nullptr;
    }

    const ArrayType* IntervalArrayType() {
      return nullptr;
    }

    const ArrayType* GeographyArrayType() {
      return nullptr;
    }

    const ArrayType* NumericArrayType() {
      return nullptr;
    }

    const ArrayType* BigNumericArrayType() {
      return nullptr;
    }

    const ArrayType* JsonArrayType() {
      return nullptr;
    }

    const Type* TypeFromSimpleTypeKind(TypeKind type_kind) {
        return nullptr;
    }

    const ArrayType* ArrayTypeFromSimpleTypeKind(TypeKind type_kind) {
      return nullptr;
    }

  }

  void TypeFactory::AddDependency(const Type* other_type) {
  }

}

namespace zetasql {

  std::string TypeParameters::DebugString() const {
    return "";
  }

  TypeParameters::TypeParameters(const StringTypeParametersProto& string_parameters)
    : type_parameters_holder_(string_parameters) {}

  TypeParameters::TypeParameters(const NumericTypeParametersProto& numeric_parameters)
    : type_parameters_holder_(numeric_parameters) {}

  TypeParameters::TypeParameters(const ExtendedTypeParameters& extended_parameters,
                                 std::vector<TypeParameters> child_list)
    : type_parameters_holder_(extended_parameters),
      child_list_(std::move(child_list)) {}

  TypeParameters::TypeParameters(std::vector<TypeParameters> child_list)
    : child_list_(std::move(child_list)) {}

  TypeParameters::TypeParameters() {}

  absl::StatusOr<TypeParameters> TypeParameters::MakeStringTypeParameters(const StringTypeParametersProto& string_type_parameters) {
    TypeParameters v;
    return v;
  }

  absl::StatusOr<TypeParameters> TypeParameters::MakeNumericTypeParameters(const NumericTypeParametersProto& numeric_type_parameters) {
    TypeParameters v;
    return v;
  }

  TypeParameters TypeParameters::MakeExtendedTypeParameters(const ExtendedTypeParameters& extended_type_parameters,
                                                            std::vector<TypeParameters> child_list) {
    TypeParameters v;
    return v;
  }

  TypeParameters TypeParameters::MakeTypeParametersWithChildList(std::vector<TypeParameters> child_list) {
    TypeParameters v;
    return v;
  }

  absl::Status TypeParameters::ValidateStringTypeParameters(const StringTypeParametersProto& string_type_parameters) {
    return absl::OkStatus();
  }

  absl::Status TypeParameters::ValidateNumericTypeParameters(const NumericTypeParametersProto& numeric_type_parameters) {
    return absl::OkStatus();
  }

  void TypeParameters::set_child_list(std::vector<TypeParameters> child_list) {
  }

  absl::Status TypeParameters::Serialize(TypeParametersProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::string> TypeParameters::SerializeAsString() const {
    return "";
  }

  absl::StatusOr<TypeParameters> TypeParameters::Deserialize(const TypeParametersProto& proto) {
    TypeParameters v;
    return v;
  }

  bool TypeParameters::Equals(const TypeParameters& that) const {
    return false;
  }

  bool TypeParameters::MatchType(const Type* type) const {
    return false;
  }

  std::string ExtendedTypeParameters::DebugString() const {
    return "";
  }

  absl::Status ExtendedTypeParameters::Serialize(ExtendedTypeParametersProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<ExtendedTypeParameters> ExtendedTypeParameters::Deserialize(const ExtendedTypeParametersProto& proto) {
    std::vector<SimpleValue> v;
    return ExtendedTypeParameters(v);
  }

}

#endif

#include "go-zetasql/public/types/timestamp_util/export.inc"
#include "go-zetasql/public/types/value_representations/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/case/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/refcount/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/time_proto_util/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/float_margin/export.inc"
#include "go-zetasql/common/proto_helper/export.inc"
#include "go-zetasql/common/string_util/export.inc"
#include "go-zetasql/public/annotation_cc_proto/export.inc"
#include "go-zetasql/public/functions/convert_proto/export.inc"
#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-zetasql/public/functions/datetime_cc_proto/export.inc"
#include "go-zetasql/public/functions/normalize_mode_cc_proto/export.inc"
#include "go-zetasql/public/interval_value/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/numeric_value/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/proto/type_annotation_cc_proto/export.inc"
#include "go-zetasql/public/simple_value_cc_proto/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type_annotation_cc_proto/export.inc"
#include "go-zetasql/public/value_cc_proto/export.inc"
#include "go-zetasql/public/value_content/export.inc"
#include "go-zetasql/public/type_parameters_cc_proto/export.inc"
#include "go-zetasql/public/collation_cc_proto/export.inc"
#include "go-absl/algorithm/container/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/cleanup/cleanup/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/container/inlined_vector/export.inc"
#include "go-absl/container/node_hash_map/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/hash/hash/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/meta/type_traits/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/cord/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-absl/types/optional/export.inc"
#include "go-absl/types/span/export.inc"
#include "go-absl/types/variant/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
