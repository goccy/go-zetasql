#ifndef ZETASQL_PUBLIC_FUNCTION_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTION_EXPORT_H

#include "zetasql/public/function.h"
#include "zetasql/public/function_signature.h"
#include "zetasql/public/input_argument_type.h"
#include "zetasql/public/procedure.h"
#include "zetasql/public/table_valued_function.h"

#include "zetasql/public/function.cc"
#include "zetasql/public/function_signature.cc"
#include "zetasql/public/input_argument_type.cc"
#include "zetasql/public/procedure.cc"
#include "zetasql/public/table_valued_function.cc"

#if 0
namespace zetasql {

  const FunctionEnums::WindowOrderSupport FunctionOptions::ORDER_UNSUPPORTED;
  const FunctionEnums::WindowOrderSupport FunctionOptions::ORDER_OPTIONAL;
  const FunctionEnums::WindowOrderSupport FunctionOptions::ORDER_REQUIRED;

  absl::Status FunctionOptions::Deserialize(const FunctionOptionsProto& proto,
                                            std::unique_ptr<FunctionOptions>* result) {
    return absl::OkStatus();
  }

  void FunctionOptions::Serialize(FunctionOptionsProto* proto) const {
  }

  FunctionOptions& FunctionOptions::set_evaluator(const FunctionEvaluator& function_evaluator) {
    return *this;
  }

  bool FunctionOptions::check_all_required_features_are_enabled(const LanguageOptions::LanguageFeatureSet& enabled_features) const {
    return false;
  }

  const char Function::kZetaSQLFunctionGroupName[] = "ZetaSQL";

  const FunctionEnums::Mode Function::SCALAR;
  const FunctionEnums::Mode Function::AGGREGATE;
  const FunctionEnums::Mode Function::ANALYTIC;

  Function::Function(absl::string_view name, absl::string_view group, Mode mode,
                     FunctionOptions function_options)
    : group_(group),
      mode_(mode),
      function_options_(std::move(function_options)) {
  }

  Function::Function(absl::string_view name, absl::string_view group, Mode mode,
                     std::vector<FunctionSignature> function_signatures,
                     FunctionOptions function_options)
    : group_(group),
      mode_(mode),
      function_signatures_(std::move(function_signatures)),
      function_options_(std::move(function_options)) {
  }

  Function::Function(std::vector<std::string> name_path, absl::string_view group,
                     Mode mode,
                     std::vector<FunctionSignature> function_signatures,
                     FunctionOptions function_options)
    : function_name_path_(std::move(name_path)),
      group_(std::move(group)),
      mode_(mode),
      function_signatures_(std::move(function_signatures)),
      function_options_(std::move(function_options)) {
  }

  absl::Status Function::Deserialize(const FunctionProto& proto,
                                     const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                     TypeFactory* factory, std::unique_ptr<Function>* result) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<Function>> Function::Deserialize(const FunctionProto& proto, const TypeDeserializer& type_deserializer) {
  }

  absl::Status Function::Serialize(FileDescriptorSetMap* file_descriptor_set_map,
                                   FunctionProto* proto, bool omit_signatures) const {
    return absl::OkStatus();
  }

  void Function::RegisterDeserializer(const std::string& group_name,
                                      FunctionDeserializer deserializer) {
  }

  const std::string Function::FullName(bool include_group) const {
    return "";
  }

  const std::string Function::SQLName() const {
    return "";
  }

  const std::string Function::QualifiedSQLName(bool capitalize_qualifier) const {
    return "";
  }

  int Function::NumSignatures() const {
    return 0;
  }

  const std::vector<FunctionSignature>& Function::signatures() const {
    std::vector<FunctionSignature> *v;
    return *v;
  }

  void Function::ResetSignatures(const std::vector<FunctionSignature>& signatures) {
  }

  absl::Status Function::CheckMultipleSignatureMatchingSameFunctionCall() const {
    return absl::OkStatus();
  }

  void Function::AddSignature(const FunctionSignature& signature) {
  }

  absl::Status Function::AddSignature(const TypeKind result_kind,
                                      const std::vector<TypeKind>& input_kinds,
                                      void* context,
                                      TypeFactory* factory) {
    return absl::OkStatus();
  }

  Function* Function::AddSignatureOrDie(const TypeKind result_kind, const std::vector<TypeKind>& input_kinds,
                                        void* context, TypeFactory* factory) {
    return this;
  }

  const FunctionSignature* Function::GetSignature(int idx) const {
    return nullptr;
  }

  std::string Function::DebugString(bool verbose) const {
    return "";
  }

  std::string Function::GetSQL(std::vector<std::string> inputs,
                               const FunctionSignature* signature) const {
    return "";
  }

  absl::Status Function::CheckPreResolutionArgumentConstraints(const std::vector<InputArgumentType>& arguments,
                                                               const LanguageOptions& language_options) const {
    return absl::OkStatus();
  }

  absl::Status Function::CheckPostResolutionArgumentConstraints(const FunctionSignature& signature,
                                                                const std::vector<InputArgumentType>& arguments,
                                                                const LanguageOptions& language_options) const {
    return absl::OkStatus();
  }

  const std::string Function::GetGenericNoMatchingFunctionSignatureErrorMessage(const std::string& qualified_function_name,
                                                                                const std::vector<InputArgumentType>& arguments, ProductMode product_mode) {
    return "";
  }

  const std::string Function::GetNoMatchingFunctionSignatureErrorMessage(const std::vector<InputArgumentType>& arguments,
                                                                         ProductMode product_mode) const {
    return "";
  }

  const std::string Function::GetSupportedSignaturesUserFacingText(const LanguageOptions& language_options, int* num_signatures) const {
    return "";
  }

  const ArgumentConstraintsCallback& Function::PreResolutionConstraints() const {
    ArgumentConstraintsCallback *v;
    return *v;
  }

  const PostResolutionArgumentConstraintsCallback& Function::PostResolutionConstraints() const {
    PostResolutionArgumentConstraintsCallback *v;
    return *v;
  }

  const ComputeResultTypeCallback& Function::GetComputeResultTypeCallback() const {
    ComputeResultTypeCallback *v;
    return *v;
  }

  const FunctionGetSQLCallback& Function::GetSQLCallback() const {
    FunctionGetSQLCallback *v;
    return *v;
  }

  const NoMatchingSignatureCallback& Function::GetNoMatchingSignatureCallback() const {
    NoMatchingSignatureCallback *v;
    return *v;
  }

  const SupportedSignaturesCallback& Function::GetSupportedSignaturesCallback() const {
    SupportedSignaturesCallback *v;
    return *v;
  }

  const BadArgumentErrorPrefixCallback& Function::GetBadArgumentErrorPrefixCallback() const {
    BadArgumentErrorPrefixCallback *v;
    return *v;
  }

  FunctionEvaluatorFactory Function::GetFunctionEvaluatorFactory() const {
    FunctionEvaluatorFactory v;
    return v;
  }

  absl::Status Function::CheckWindowSupportOptions() const {
    return absl::OkStatus();
  }

  bool Function::SupportsOverClause() const {
    return false;
  }

  bool Function::SupportsWindowOrdering() const {
    return false;
  }

  bool Function::RequiresWindowOrdering() const {
    return false;
  }

  bool Function::SupportsWindowFraming() const {
    return false;
  }

  bool Function::SupportsOrderingArguments() const {
    return false;
  }

  bool Function::SupportsLimitArguments() const {
    return false;
  }

  bool Function::SupportsNullHandlingModifier() const {
    return false;
  }

  bool Function::SupportsSafeErrorMode() const {
    return false;
  }

  bool Function::SupportsHavingModifier() const {
    return false;
  }

  bool Function::SupportsDistinctModifier() const {
    return false;
  }

  bool Function::SupportsClampedBetweenModifier() const {
    return false;
  }

}

namespace zetasql {

  FunctionArgumentTypeOptions::FunctionArgumentTypeOptions(const TVFRelation& relation_input_schema,
                                                           bool extra_relation_input_columns_allowed)
    : relation_input_schema_(new TVFRelation(relation_input_schema)),
      extra_relation_input_columns_allowed_(extra_relation_input_columns_allowed) {}

  absl::StatusOr<bool> FunctionSignatureOptions::CheckFunctionSignatureConstraints(const FunctionSignature& concrete_signature,
                                                                                   const std::vector<InputArgumentType>& arguments) const {
    absl::StatusOr<bool> v;
    return v;
  }

  absl::Status FunctionSignatureOptions::Deserialize(const FunctionSignatureOptionsProto& proto,
                                                     std::unique_ptr<FunctionSignatureOptions>* result) {
    return absl::OkStatus();
  }

  void FunctionSignatureOptions::Serialize(FunctionSignatureOptionsProto* proto) const {
  }

  const FunctionEnums::ArgumentCardinality FunctionArgumentType::REQUIRED;
  const FunctionEnums::ArgumentCardinality FunctionArgumentType::REPEATED;
  const FunctionEnums::ArgumentCardinality FunctionArgumentType::OPTIONAL;

  absl::Status FunctionArgumentTypeOptions::Deserialize(const FunctionArgumentTypeOptionsProto& options_proto,
                                                        const TypeDeserializer& type_deserializer, SignatureArgumentKind arg_kind,
                                                        const Type* arg_type, FunctionArgumentTypeOptions* options) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<FunctionArgumentType>>
  FunctionArgumentType::Deserialize(const FunctionArgumentTypeProto& proto,
                                    const TypeDeserializer& type_deserializer) {
    absl::StatusOr<std::unique_ptr<FunctionArgumentType>> v;
    return v;
  }

  absl::Status FunctionArgumentTypeOptions::Serialize(const Type* arg_type, FunctionArgumentTypeOptionsProto* options_proto,
                                                      FileDescriptorSetMap* file_descriptor_set_map) const {
    return absl::OkStatus();
  }

  absl::Status FunctionArgumentType::Serialize(FileDescriptorSetMap* file_descriptor_set_map,
                                               FunctionArgumentTypeProto* proto) const {
    return absl::OkStatus();
  }

  FunctionArgumentType FunctionArgumentType::Lambda(std::vector<FunctionArgumentType> lambda_argument_types,
                                                    FunctionArgumentType lambda_body_type) {
    FunctionArgumentType v;
    return v;
  }

  bool Function::is_operator() const {
    return false;
  }

  std::string FunctionArgumentTypeOptions::OptionsDebugString() const {
    return "";
  }

  std::string FunctionArgumentTypeOptions::GetSQLDeclaration(ProductMode product_mode) const {
    return "";
  }

  std::string FunctionArgumentType::SignatureArgumentKindToString(SignatureArgumentKind kind) {
    return "";
  }

  std::shared_ptr<const FunctionArgumentTypeOptions>
  FunctionArgumentType::SimpleOptions(ArgumentCardinality cardinality) {
    std::shared_ptr<const FunctionArgumentTypeOptions> v;
    return v;
  }

  FunctionArgumentType::FunctionArgumentType(SignatureArgumentKind kind, const Type* type,
                                             std::shared_ptr<const FunctionArgumentTypeOptions> options,
                                             int num_occurrences)
    : kind_(kind),
      num_occurrences_(num_occurrences),
      type_(type),
      options_(std::move(options)) {
  }

  FunctionArgumentType::FunctionArgumentType(SignatureArgumentKind kind,
                                             ArgumentCardinality cardinality,
                                             int num_occurrences)
    : FunctionArgumentType(kind, /*type=*/nullptr, SimpleOptions(cardinality),
                           num_occurrences) {}

  FunctionArgumentType::FunctionArgumentType(SignatureArgumentKind kind,
                                             FunctionArgumentTypeOptions options,
                                             int num_occurrences)
    : FunctionArgumentType(
                           kind, /*type=*/nullptr,
                           std::make_shared<FunctionArgumentTypeOptions>(std::move(options)),
                           num_occurrences) {}

  FunctionArgumentType::FunctionArgumentType(SignatureArgumentKind kind,
                                             int num_occurrences)
    : FunctionArgumentType(kind, /*type=*/nullptr, SimpleOptions(),
                           num_occurrences) {}

  FunctionArgumentType::FunctionArgumentType(const Type* type,
                                             ArgumentCardinality cardinality,
                                             int num_occurrences)
    : FunctionArgumentType(ARG_TYPE_FIXED, type, SimpleOptions(cardinality),
                           num_occurrences) {}

  FunctionArgumentType::FunctionArgumentType(const Type* type,
                                             FunctionArgumentTypeOptions options,
                                             int num_occurrences)
    : FunctionArgumentType(
                           ARG_TYPE_FIXED, type,
                           std::make_shared<FunctionArgumentTypeOptions>(std::move(options)),
                           num_occurrences) {}

  FunctionArgumentType::FunctionArgumentType(const Type* type,
                                             int num_occurrences)
    : FunctionArgumentType(ARG_TYPE_FIXED, type, SimpleOptions(),
                           num_occurrences) {}

  bool FunctionArgumentType::IsConcrete() const {
    return false;
  }

  bool FunctionArgumentType::IsTemplated() const {
    return false;
  }

  bool FunctionArgumentType::IsScalar() const {
    return false;
  }

  absl::Status FunctionArgumentType::CheckLambdaArgType(const FunctionArgumentType& arg_type) {
    return absl::OkStatus();
  }

  absl::Status FunctionArgumentType::IsValid(ProductMode product_mode) const {
    return absl::OkStatus();
  }

  std::string FunctionArgumentType::UserFacingName(ProductMode product_mode) const {
    return "";
  }

  std::string FunctionArgumentType::UserFacingNameWithCardinality(ProductMode product_mode) const {
    return "";
  }

  std::string FunctionArgumentType::DebugString(bool verbose) const {
    return "";
  }

  std::string FunctionArgumentType::GetSQLDeclaration(ProductMode product_mode) const {
    return "";
  }

  FunctionSignature::FunctionSignature(FunctionArgumentType result_type,
                                       FunctionArgumentTypeList arguments,
                                       void* context_ptr)
    : arguments_(std::move(arguments)),
      result_type_(std::move(result_type)),
      num_repeated_arguments_(ComputeNumRepeatedArguments()),
      num_optional_arguments_(ComputeNumOptionalArguments()),
      context_ptr_(context_ptr) {
  }

  FunctionSignature::FunctionSignature(FunctionArgumentType result_type,
                                       FunctionArgumentTypeList arguments,
                                       int64_t context_id)
    : FunctionSignature(std::move(result_type), std::move(arguments),
                        context_id, FunctionSignatureOptions()) {}

  FunctionSignature::FunctionSignature(FunctionArgumentType result_type,
                                       FunctionArgumentTypeList arguments,
                                       int64_t context_id,
                                       FunctionSignatureOptions options)
    : arguments_(std::move(arguments)),
      result_type_(std::move(result_type)),
      num_repeated_arguments_(ComputeNumRepeatedArguments()),
      num_optional_arguments_(ComputeNumOptionalArguments()),
      context_id_(context_id),
      options_(std::move(options)) {
  }

  absl::Status FunctionSignature::Deserialize(const FunctionSignatureProto& proto,
                                              const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                              TypeFactory* factory,
                                              std::unique_ptr<FunctionSignature>* result) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<FunctionSignature>>
  FunctionSignature::Deserialize(const FunctionSignatureProto& proto,
                                 const TypeDeserializer& type_deserializer) {
    absl::StatusOr<std::unique_ptr<FunctionSignature>> v;
    return v;
  }

  absl::Status FunctionSignature::Serialize(FileDescriptorSetMap* file_descriptor_set_map,
                                            FunctionSignatureProto* proto) const {
    return absl::OkStatus();
  }

  bool FunctionSignature::HasUnsupportedType(const LanguageOptions& language_options) const {
    return false;
  }

  void FunctionSignature::ComputeConcreteArgumentTypes() {
  }

  bool FunctionSignature::HasConcreteArguments() const {
    return false;
  }

  bool FunctionSignature::ComputeIsConcrete() const {
    return false;
  }

  absl::StatusOr<bool> FunctionSignature::CheckArgumentConstraints(const std::vector<InputArgumentType>& arguments) const {
    absl::StatusOr<bool> v;
    return v;
  }

  std::string FunctionSignature::DebugString(const std::string& function_name,
                                             bool verbose) const {
    return "";
  }

  std::string FunctionSignature::SignaturesToString(const std::vector<FunctionSignature>& signatures, bool verbose,
                                                    const std::string& prefix, const std::string& separator) {
    return "";
  }

  std::string FunctionSignature::GetSQLDeclaration(const std::vector<std::string>& argument_names,
                                                   ProductMode product_mode) const {
    return "";
  }

  bool FunctionArgumentType::TemplatedKindIsRelated(SignatureArgumentKind kind) const {
    return false;
  }

  absl::Status FunctionSignature::IsValid(ProductMode product_mode) const {
    return absl::OkStatus();
  }

  absl::Status FunctionSignature::IsValidForFunction() const {
    return absl::OkStatus();
  }

  absl::Status FunctionSignature::IsValidForTableValuedFunction() const {
    return absl::OkStatus();
  }

  absl::Status FunctionSignature::IsValidForProcedure() const {
    return absl::OkStatus();
  }

  int FunctionSignature::FirstRepeatedArgumentIndex() const {
    return 0;
  }

  int FunctionSignature::LastRepeatedArgumentIndex() const {
    return 0;
  }

  int FunctionSignature::NumRequiredArguments() const {
    return 0;
  }

  int FunctionSignature::ComputeNumRepeatedArguments() const {
    return 0;
  }

  int FunctionSignature::ComputeNumOptionalArguments() const {
    return 0;
  }

  void FunctionSignature::SetConcreteResultType(const Type* type) {
  }

}

namespace zetasql {

  bool InputArgumentTypeLess::operator()(const InputArgumentType& type1, const InputArgumentType& type2) const {
    return false;
  }

  bool InputArgumentType::operator==(const InputArgumentType& rhs) const {
    return false;
  }

  bool InputArgumentType::operator!=(const InputArgumentType& type) const {
    return false;
  }

  InputArgumentType::InputArgumentType(const Value& literal_value,
                                       bool is_default_argument_value)
    : category_(kTypedLiteral),
      type_(literal_value.type()),
      literal_value_(literal_value),
      is_default_argument_value_(is_default_argument_value) {
  }

  InputArgumentType::InputArgumentType(const Type* type, bool is_query_parameter)
    : category_(is_query_parameter ? kTypedParameter : kTypedExpression),
      type_(type) {
  }

  std::string InputArgumentType::UserFacingName(ProductMode product_mode) const {
    return "";
  }

  std::string InputArgumentType::DebugString(bool verbose) const {
    return "";
  }

  std::string InputArgumentType::ArgumentsToString(const std::vector<InputArgumentType>& arguments, ProductMode product_mode) {
    return "";
  }

  InputArgumentType InputArgumentType::RelationInputArgumentType(const TVFRelation& relation_input_schema) {
    InputArgumentType v;
    return v;
  }

  InputArgumentType InputArgumentType::ModelInputArgumentType(const TVFModelArgument& model_arg) {
    InputArgumentType v;
    return v;
  }

  InputArgumentType InputArgumentType::ConnectionInputArgumentType(const TVFConnectionArgument& connection_arg) {
    InputArgumentType v;
    return v;
  }

  InputArgumentType InputArgumentType::DescriptorInputArgumentType() {
    InputArgumentType v;
    return v;
  }

  InputArgumentType InputArgumentType::LambdaInputArgumentType() {
    InputArgumentType v;
    return v;
  }

  bool InputArgumentTypeSet::Insert(const InputArgumentType& argument, bool set_dominant) {
    return false;
  }

  void InputArgumentTypeSet::clear() {
  }

  std::string InputArgumentTypeSet::ToString(bool verbose) const {
    return "";
  }

}

namespace zetasql {

  absl::StatusOr<std::unique_ptr<Procedure>> Procedure::Deserialize(const ProcedureProto& proto, const TypeDeserializer& type_deserializer) {
    absl::StatusOr<std::unique_ptr<Procedure>> v;
    return v;
  }

  absl::Status Procedure::Serialize(FileDescriptorSetMap* file_descriptor_set_map,
                                    ProcedureProto* proto) const {
    return absl::OkStatus();
  }

  std::string Procedure::GetSupportedSignatureUserFacingText(ProductMode product_mode) const {
    return "";
  }

}

namespace zetasql {

  absl::Status TableValuedFunctionOptions::Deserialize(const TableValuedFunctionOptionsProto& proto,
                                                       std::unique_ptr<TableValuedFunctionOptions>* result) {
    return absl::OkStatus();
  }

  void TableValuedFunctionOptions::Serialize(TableValuedFunctionOptionsProto* proto) const {
  }

  int64_t TableValuedFunction::NumSignatures() const {
    return 0;
  }

  const std::vector<FunctionSignature>& TableValuedFunction::signatures() const {
    std::vector<FunctionSignature> *v;
    return *v;
  }

  absl::Status TableValuedFunction::AddSignature(const FunctionSignature& function_signature) {
    return absl::OkStatus();
  }

  const FunctionSignature* TableValuedFunction::GetSignature(int64_t idx) const {
    return nullptr;
  }

  std::string TableValuedFunction::GetSupportedSignaturesUserFacingText(const LanguageOptions& language_options) const {
    return "";
  }

  std::string TableValuedFunction::GetSignatureUserFacingText(const FunctionSignature& signature,
                                                              const LanguageOptions& language_options) const {
    return "";
  }

  std::string TableValuedFunction::DebugString() const {
    return "";
  }

  std::string TableValuedFunction::GetTVFSignatureErrorMessage(const std::string& tvf_name_string,
                                                               const std::vector<InputArgumentType>& input_arg_types, int signature_idx,
                                                               const SignatureMatchResult& signature_match_result,
                                                               const LanguageOptions& language_options) const {
    return "";
  }

  absl::Status TableValuedFunction::Serialize(FileDescriptorSetMap* file_descriptor_set_map,
                                              TableValuedFunctionProto* proto) const {
    return absl::OkStatus();
  }

  absl::Status TableValuedFunction::Deserialize(const TableValuedFunctionProto& proto,
                                                const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                                TypeFactory* factory, std::unique_ptr<TableValuedFunction>* result) {
    return absl::OkStatus();
  }

  void TableValuedFunction::RegisterDeserializer(FunctionEnums::TableValuedFunctionType type, TVFDeserializer deserializer) {
  }

  absl::Status TableValuedFunction::SetUserIdColumnNamePath(absl::Span<const std::string> userid_column_name_path) {
    return absl::OkStatus();
  }

  absl::StatusOr<TVFRelationColumnProto> TVFSchemaColumn::ToProto(FileDescriptorSetMap* file_descriptor_set_map) const {
    absl::StatusOr<TVFRelationColumnProto> v;
    return v;
  }

  absl::StatusOr<TVFSchemaColumn> TVFSchemaColumn::FromProto(const TVFRelationColumnProto& proto,
                                                             const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                                             TypeFactory* factory) {
    absl::StatusOr<TVFSchemaColumn> v;
    return v;
  }

  std::string TVFRelation::GetSQLDeclaration(ProductMode product_mode) const {
    return "";
  }

  std::string TVFRelation::DebugString() const {
    return "";
  }

  absl::Status TVFRelation::Serialize(FileDescriptorSetMap* file_descriptor_set_map,
                                      TVFRelationProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<TVFRelation> TVFRelation::Deserialize(const TVFRelationProto& proto,
                                                       const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                                       TypeFactory* factory) {
    absl::StatusOr<TVFRelation> v;
    return v;
  }

  bool operator==(const TVFSchemaColumn& a, const TVFSchemaColumn& b) {
    return false;
  }

  std::ostream& operator<<(std::ostream& out,
                           const TVFSchemaColumn& column) {
    return out;
  }

  bool operator == (const TVFRelation& a, const TVFRelation& b) {
    return false;
  }

  std::string TVFModelArgument::GetSQLDeclaration(ProductMode product_mode) const {
    return "";
  }

  std::string TVFModelArgument::DebugString() const {
    return "";
  }

  std::string TVFConnectionArgument::GetSQLDeclaration(ProductMode product_mode) const {
    return "";
  }

  std::string TVFConnectionArgument::DebugString() const {
    return "";
  }

  std::string TVFDescriptorArgument::DebugString() const {
    return "";
  }

  absl::Status FixedOutputSchemaTVF::Serialize(FileDescriptorSetMap* file_descriptor_set_map,
                                               TableValuedFunctionProto* proto) const {
     return absl::OkStatus();
  }

  absl::Status FixedOutputSchemaTVF::Deserialize(const TableValuedFunctionProto& proto,
                                                 const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                                 TypeFactory* factory, std::unique_ptr<TableValuedFunction>* result) {
    return absl::OkStatus();
  }

  absl::Status FixedOutputSchemaTVF::Resolve(const AnalyzerOptions* analyzer_options,
                                             const std::vector<TVFInputArgumentType>& actual_arguments,
                                             const FunctionSignature& concrete_signature, Catalog* catalog,
                                             TypeFactory* type_factory,
                                             std::shared_ptr<TVFSignature>* tvf_signature) const {
    return absl::OkStatus();
  }

  absl::Status ForwardInputSchemaToOutputSchemaTVF::Serialize(FileDescriptorSetMap* file_descriptor_set_map,
                                                              TableValuedFunctionProto* proto) const {
    return absl::OkStatus();
  }

  absl::Status ForwardInputSchemaToOutputSchemaTVF::Deserialize(const TableValuedFunctionProto& proto,
                                                                const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                                                TypeFactory* factory, std::unique_ptr<TableValuedFunction>* result) {
    return absl::OkStatus();
  }

  absl::Status ForwardInputSchemaToOutputSchemaTVF::Resolve(const AnalyzerOptions* analyzer_options,
                                                            const std::vector<TVFInputArgumentType>& actual_arguments,
                                                            const FunctionSignature& concrete_signature, Catalog* catalog,
                                                            TypeFactory* type_factory,
                                                            std::shared_ptr<TVFSignature>* output_tvf_signature) const {
    return absl::OkStatus();
  }

  absl::Status ForwardInputSchemaToOutputSchemaTVF::CheckIsValid() const {
    return absl::OkStatus();
  }

  absl::Status ForwardInputSchemaToOutputSchemaWithAppendedColumnTVF::Serialize(FileDescriptorSetMap* file_descriptor_set_map,
                                                                                TableValuedFunctionProto* proto) const {
    return absl::OkStatus();
  }

  absl::Status ForwardInputSchemaToOutputSchemaWithAppendedColumnTVF::Resolve(const AnalyzerOptions* analyzer_options,
                                                                              const std::vector<TVFInputArgumentType>& actual_arguments,
                                                                              const FunctionSignature& concrete_signature, Catalog* catalog,
                                                                              TypeFactory* type_factory,
                                                                              std::shared_ptr<TVFSignature>* output_tvf_signature) const {
    return absl::OkStatus();
  }

  absl::Status ForwardInputSchemaToOutputSchemaWithAppendedColumnTVF::Deserialize(const TableValuedFunctionProto& proto,
                                                                                  const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                                                                  TypeFactory* factory, std::unique_ptr<TableValuedFunction>* result) {
    return absl::OkStatus();
  }

  absl::Status ForwardInputSchemaToOutputSchemaWithAppendedColumnTVF::
  IsValidForwardInputSchemaToOutputSchemaWithAppendedColumnTVF(bool isTemplated,
                                                               const std::vector<TVFSchemaColumn>& extra_columns) const {
    return absl::OkStatus();
  }
}
#endif

#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/deprecation_warning_cc_proto/export.inc"
#include "go-zetasql/public/function_cc_proto/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/signature_match_result/export.inc"
#include "go-zetasql/public/simple_table_cc_proto/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/proto/function_cc_proto/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/serialization_cc_proto/export.inc"
#include "go-absl/algorithm/container/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/optional/export.inc"
#include "go-absl/types/span/export.inc"

#endif
