#ifndef ZETASQL_PUBLIC_EVALUATOR_BASE_EXPORT_H
#define ZETASQL_PUBLIC_EVALUATOR_BASE_EXPORT_H

#include "zetasql/public/evaluator_base.h"
#include "zetasql/public/evaluator_base.cc"

#if 0
namespace zetasql {

  namespace internal {

    EvaluatorOptions EvaluatorOptionsFromTypeFactory(TypeFactory* type_factory) {
      EvaluatorOptions v;
      return v;
    }

  }

  PreparedExpressionBase::PreparedExpressionBase(const std::string& sql,
                                                 TypeFactory* type_factory)
    : PreparedExpressionBase(sql, internal::EvaluatorOptionsFromTypeFactory(type_factory)) {}

  PreparedExpressionBase::PreparedExpressionBase(const std::string& sql,
                                                 const EvaluatorOptions& options)
    : evaluator_(nullptr) {}

  PreparedExpressionBase::PreparedExpressionBase(const ResolvedExpr* expression,
                                                 const EvaluatorOptions& options)
    : evaluator_(nullptr) {}

  PreparedExpressionBase::~PreparedExpressionBase() {}

  absl::Status PreparedExpressionBase::Prepare(const AnalyzerOptions& options,
                                               Catalog* catalog) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::vector<std::string>>
  PreparedExpressionBase::GetReferencedColumns() const {
    absl::StatusOr<std::vector<std::string>> v;
    return v;
  }

  absl::StatusOr<std::vector<std::string>>
  PreparedExpressionBase::GetReferencedParameters() const {
    absl::StatusOr<std::vector<std::string>> v;
    return v;
  }

  absl::StatusOr<int> PreparedExpressionBase::GetPositionalParameterCount() const {
    absl::StatusOr<int> v;
    return v;
  }

  absl::StatusOr<Value> PreparedExpressionBase::Execute(ExpressionOptions options) {
    absl::StatusOr<Value> v;
    return v;
  }

  absl::StatusOr<Value> PreparedExpressionBase::Execute(const ParameterValueMap& columns, const ParameterValueMap& parameters,
                                                        const SystemVariableValuesMap& system_variables) {
    absl::StatusOr<Value> v;
    return v;
  }

  absl::StatusOr<Value> PreparedExpressionBase::ExecuteWithPositionalParams(const ParameterValueMap& columns,
                                                                            const ParameterValueList& positional_parameters,
                                                                            const SystemVariableValuesMap& system_variables) {
    absl::StatusOr<Value> v;
    return v;
  }

  absl::StatusOr<Value> PreparedExpressionBase::ExecuteAfterPrepare(ExpressionOptions options) const {
    absl::StatusOr<Value> v;
    return v;
  }

  absl::StatusOr<Value> PreparedExpressionBase::ExecuteAfterPrepare(const ParameterValueMap& columns, const ParameterValueMap& parameters,
                                                                    const SystemVariableValuesMap& system_variables) const {
    absl::StatusOr<Value> v;
    return v;
  }

  absl::StatusOr<Value> PreparedExpressionBase::ExecuteAfterPrepareWithPositionalParams(const ParameterValueMap& columns,
                                                                                        const ParameterValueList& positional_parameters,
                                                                                        const SystemVariableValuesMap& system_variables) const {
    absl::StatusOr<Value> v;
    return v;
  }

  absl::StatusOr<Value> PreparedExpressionBase::ExecuteAfterPrepareWithOrderedParams(const ParameterValueList& columns, const ParameterValueList& parameters,
                                                                                     const SystemVariableValuesMap& system_variables) const {
    absl::StatusOr<Value> v;
    return v;
  }

  absl::StatusOr<std::string> PreparedExpressionBase::ExplainAfterPrepare() const {
    absl::StatusOr<std::string> v;
    return v;
  }

  const Type* PreparedExpressionBase::output_type() const {
    return nullptr;
  }

  PreparedQueryBase::PreparedQueryBase(const std::string& sql,
                                       const EvaluatorOptions& options)
    : evaluator_(nullptr) {}

  PreparedQueryBase::PreparedQueryBase(const ResolvedQueryStmt* stmt,
                                       const EvaluatorOptions& options)
    : evaluator_(nullptr) {}

  PreparedQueryBase::~PreparedQueryBase() {}

  absl::Status PreparedQueryBase::Prepare(const AnalyzerOptions& options,
                                          Catalog* catalog) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::vector<std::string>>
  PreparedQueryBase::GetReferencedParameters() const {
    absl::StatusOr<std::vector<std::string>> v;
    return v;
  }

  absl::StatusOr<int> PreparedQueryBase::GetPositionalParameterCount() const {
    absl::StatusOr<int> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<EvaluatorTableIterator>>
  PreparedQueryBase::Execute(const QueryOptions& options) {
    absl::StatusOr<std::unique_ptr<EvaluatorTableIterator>> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<EvaluatorTableIterator>>
  PreparedQueryBase::Execute(const ParameterValueMap& parameters,
                             const SystemVariableValuesMap& system_variables) {
    absl::StatusOr<std::unique_ptr<EvaluatorTableIterator>> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<EvaluatorTableIterator>>
  PreparedQueryBase::ExecuteWithPositionalParams(const ParameterValueList& positional_parameters,
                                                 const SystemVariableValuesMap& system_variables) {
    absl::StatusOr<std::unique_ptr<EvaluatorTableIterator>> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<EvaluatorTableIterator>>
  PreparedQueryBase::ExecuteAfterPrepare(const QueryOptions& options) const {
    absl::StatusOr<std::unique_ptr<EvaluatorTableIterator>> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<EvaluatorTableIterator>>
  PreparedQueryBase::ExecuteAfterPrepare(const ParameterValueList& parameters,
                                         const SystemVariableValuesMap& system_variables) const {
    absl::StatusOr<std::unique_ptr<EvaluatorTableIterator>> v;
    return v;
  }

  absl::StatusOr<std::string> PreparedQueryBase::ExplainAfterPrepare() const {
    absl::StatusOr<std::string> v;
    return v;
  }

  int PreparedQueryBase::num_columns() const {
    return 0;
  }

  std::string PreparedQueryBase::column_name(int i) const {
    return "";
  }

  const Type* PreparedQueryBase::column_type(int i) const {
    return nullptr;
  }

  std::vector<PreparedQueryBase::NameAndType> PreparedQueryBase::GetColumns() const {
    std::vector<PreparedQueryBase::NameAndType> v;
    return v;
  }

  const ResolvedQueryStmt* PreparedQueryBase::resolved_query_stmt() const {
    return nullptr;
  }

  void PreparedQueryBase::SetCreateEvaluationCallbackTestOnly(std::function<void(EvaluationContext*)> cb) {
  }

  PreparedModifyBase::PreparedModifyBase(const std::string& sql,
                                         const EvaluatorOptions& options)
    : evaluator_(nullptr) {}

  PreparedModifyBase::PreparedModifyBase(const ResolvedStatement* stmt,
                                         const EvaluatorOptions& options)
    : evaluator_(nullptr) {}

  PreparedModifyBase::~PreparedModifyBase() {}

  absl::Status PreparedModifyBase::Prepare(const AnalyzerOptions& options,
                                           Catalog* catalog) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<EvaluatorTableModifyIterator>>
  PreparedModifyBase::Execute(const ParameterValueMap& parameters,
                              const SystemVariableValuesMap& system_variables) {
    absl::StatusOr<std::unique_ptr<EvaluatorTableModifyIterator>> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<EvaluatorTableModifyIterator>>
  PreparedModifyBase::ExecuteWithPositionalParams(const ParameterValueList& positional_parameters,
                                                  const SystemVariableValuesMap& system_variables) {
    absl::StatusOr<std::unique_ptr<EvaluatorTableModifyIterator>> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<EvaluatorTableModifyIterator>>
  PreparedModifyBase::ExecuteAfterPrepare(const ParameterValueMap& parameters,
                                          const SystemVariableValuesMap& system_variables) const {
    absl::StatusOr<std::unique_ptr<EvaluatorTableModifyIterator>> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<EvaluatorTableModifyIterator>>
  PreparedModifyBase::ExecuteAfterPrepareWithOrderedParams(const ParameterValueList& parameters,
                                                           const SystemVariableValuesMap& system_variables) const {
    absl::StatusOr<std::unique_ptr<EvaluatorTableModifyIterator>> v;
    return v;
  }

  absl::StatusOr<std::string> PreparedModifyBase::ExplainAfterPrepare() const {
    absl::StatusOr<std::string> v;
    return v;
  }

  const ResolvedStatement* PreparedModifyBase::resolved_statement() const {
    return nullptr;
  }

  absl::StatusOr<std::vector<std::string>>
  PreparedModifyBase::GetReferencedParameters() const {
    absl::StatusOr<std::vector<std::string>> v;
    return v;
  }

  absl::StatusOr<int> PreparedModifyBase::GetPositionalParameterCount() const {
    absl::StatusOr<int> v;
    return v;
  }

}
#endif

#include "go-zetasql/public/analyzer/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/evaluator_table_iterator/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/simple_catalog/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/clock/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/reference_impl/algebrizer/export.inc"
#include "go-zetasql/reference_impl/common/export.inc"
#include "go-zetasql/reference_impl/evaluation/export.inc"
#include "go-zetasql/reference_impl/parameters/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/validator/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/node_hash_map/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-absl/types/span/export.inc"
#include "go-absl/types/variant/export.inc"

#endif
