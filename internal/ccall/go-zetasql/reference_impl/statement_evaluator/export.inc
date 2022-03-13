#ifndef ZETASQL_REFERENCE_IMPL_STATEMENT_EVALUATOR_EXPORT_H
#define ZETASQL_REFERENCE_IMPL_STATEMENT_EVALUATOR_EXPORT_H

#include "zetasql/reference_impl/statement_evaluator.h"

namespace zetasql {

  const ResolvedStatement* StatementEvaluatorImpl::StatementEvaluation::resolved_statement() const {
    return nullptr;
  }

  const ResolvedExpr* StatementEvaluatorImpl::ExpressionEvaluation::resolved_expr() const {
    return nullptr;
  }

  absl::Status StatementEvaluatorImpl::Evaluation::Evaluate(const ScriptExecutor& script_executor, StatementEvaluatorImpl* evaluator,
                                                            const ScriptSegment& segment) {
    return absl::OkStatus();
  }

  absl::Status StatementEvaluatorImpl::Evaluation::EvaluateInternal(const ScriptExecutor& script_executor, StatementEvaluatorImpl* evaluator,
                                                                    const ScriptSegment& segment) {
    return absl::OkStatus();
  }

  absl::Status StatementEvaluatorImpl::StatementEvaluation::Analyze(absl::string_view sql, const AnalyzerOptions& analyzer_options,
                                                                    Catalog* catalog) {
    return absl::OkStatus();
  }

  absl::StatusOr<int>
  StatementEvaluatorImpl::StatementEvaluation::DoDmlSideEffects(EvaluatorTableModifyIterator* iterator) {
    return 0;
  }

  absl::Status StatementEvaluatorImpl::ExpressionEvaluation::EvaluateImpl(absl::string_view sql, const AnalyzerOptions& analyzer_options,
                                                                          Catalog* catalog, const EvaluatorOptions& evaluator_options,
                                                                          const SystemVariableValuesMap& system_variables,
                                                                          absl::variant<ParameterValueList, ParameterValueMap> parameters) {
    return absl::OkStatus();
  }

  absl::Status StatementEvaluatorImpl::StatementEvaluation::EvaluateImpl(absl::string_view sql, const AnalyzerOptions& analyzer_options,
                                                                         Catalog* catalog, const EvaluatorOptions& evaluator_options,
                                                                         const SystemVariableValuesMap& system_variables,
                                                                         absl::variant<ParameterValueList, ParameterValueMap> parameters) {
    return absl::OkStatus();
  }

  absl::Status StatementEvaluatorImpl::ExecuteStatement(const ScriptExecutor& executor, const ScriptSegment& segment) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<EvaluatorTableIterator>>
  StatementEvaluatorImpl::ExecuteQueryWithResult(const ScriptExecutor& executor, const ScriptSegment& segment) {
    std::unique_ptr<EvaluatorTableIterator> v;
    return v;
  }

  absl::Status StatementEvaluatorImpl::SerializeIterator(const EvaluatorTableIterator& iterator,
                                                         google::protobuf::Any& out) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<EvaluatorTableIterator>>
  StatementEvaluatorImpl::DeserializeToIterator(const google::protobuf::Any& msg,
                                                const ScriptExecutor& executor,
                                                const ParsedScript& parsed_script) {
    std::unique_ptr<EvaluatorTableIterator> v;
    return v;
  }

  absl::StatusOr<int64_t> StatementEvaluatorImpl::GetIteratorMemoryUsage(const EvaluatorTableIterator& iterator) {
    return 0;
  }

  absl::StatusOr<int>
  StatementEvaluatorImpl::EvaluateCaseExpression(const ScriptSegment& case_value,
                                                 const std::vector<ScriptSegment>& when_values,
                                                 const ScriptExecutor& executor) {
    return 0;
  }

  absl::StatusOr<Value> StatementEvaluatorImpl::EvaluateScalarExpression(const ScriptExecutor& executor, const ScriptSegment& segment,
                                                                         const Type* target_type) {
    Value v;
    return v;
  }

  bool StatementEvaluatorImpl::IsSupportedVariableType(const TypeWithParameters& type_with_params) {
    return false;
  }

  absl::Status StatementEvaluatorImpl::ApplyTypeParameterConstraints(const TypeParameters& type_params, Value* value) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ProcedureDefinition>>
  StatementEvaluatorImpl::LoadProcedure(const ScriptExecutor& executor,
                                        const absl::Span<const std::string>& path,
                                        const int64_t num_arguments) {
    return absl::NotFoundError("");
  }

  absl::StatusOr<TypeWithParameters> StatementEvaluatorImpl::ResolveTypeName(const ScriptExecutor& executor, const ScriptSegment& segment) {
    TypeWithParameters v;
    return v;
  }

}

#include "go-zetasql/reference_impl/evaluator_table_iterator_cc_proto/export.inc"
#include "go-zetasql/reference_impl/type_helpers/export.inc"
#include "go-zetasql/reference_impl/type_parameter_constraints/export.inc"
#include "go-zetasql/analyzer/resolver/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/status_payload_utils/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/analyzer/export.inc"
#include "go-zetasql/public/coercer/export.inc"
#include "go-zetasql/public/error_helpers/export.inc"
#include "go-zetasql/public/evaluator/export.inc"
#include "go-zetasql/public/evaluator_table_iterator/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/multi_catalog/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/parse_resume_location/export.inc"
#include "go-zetasql/public/simple_catalog/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-zetasql/scripting/script_exception_cc_proto/export.inc"
#include "go-zetasql/scripting/script_executor/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/types/optional/export.inc"

#endif
