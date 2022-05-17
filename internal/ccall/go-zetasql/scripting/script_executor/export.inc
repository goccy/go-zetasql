#ifndef ZETASQL_SCRIPTING_SCRIPT_EXECUTOR_EXPORT_H
#define ZETASQL_SCRIPTING_SCRIPT_EXECUTOR_EXPORT_H

#include "zetasql/scripting/script_executor.h"
#include "zetasql/scripting/script_executor_impl.h"
#include "zetasql/scripting/serialization_helpers.h"

#include "zetasql/scripting/script_executor.cc"
#include "zetasql/scripting/script_executor_impl.cc"
#include "zetasql/scripting/serialization_helpers.cc"

#if 0
namespace zetasql {

  void ScriptExecutorOptions::PopulateFromAnalyzerOptions(const AnalyzerOptions& analyzer_options) {
  }

  absl::StatusOr<std::unique_ptr<ScriptExecutor>> ScriptExecutor::Create(absl::string_view script, const ScriptExecutorOptions& options,
                                                                         StatementEvaluator* statement_evaluator) {
    std::unique_ptr<ScriptExecutor> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ScriptExecutor>> ScriptExecutor::CreateFromAST(absl::string_view script, const ASTScript* ast_script,
                                                                                const ScriptExecutorOptions& options,
                                                                                StatementEvaluator* statement_evaluator) {
    std::unique_ptr<ScriptExecutor> v;
    return v;
  }

  absl::Status StatementEvaluator::AssignSystemVariable(ScriptExecutor* executor, const ASTSystemVariableAssignment* ast_assignment,
                                                        const Value& value) {
    absl::Status v;
    return v;
  }

}

namespace zetasql {

  absl::StatusOr<std::unique_ptr<ScriptExecutor>> ScriptExecutorImpl::Create(absl::string_view script, const ASTScript* ast_script,
                                                                             const ScriptExecutorOptions& options, StatementEvaluator* evaluator) {
    std::unique_ptr<ScriptExecutor> v;
    return v;
  }

  ScriptExecutorImpl::ScriptExecutorImpl(const ScriptExecutorOptions& options,
                                         std::unique_ptr<const ParsedScript> parsed_script,
                                         StatementEvaluator* evaluator)
    : options_(options),
      evaluator_(evaluator),
      total_memory_usage_(0),
      type_factory_(options.type_factory()) {
  }

  void ScriptExecutorImpl::SetSystemVariablesForPendingException() {
  }

  Value ScriptExecutorImpl::GetFormattedStackTrace(const ScriptException::Internal& internal_exception) {
  }

  absl::StatusOr<Value> ScriptExecutorImpl::GetStackTraceSystemVariable(const ScriptException::Internal& internal_exception) {
    Value v;
    return v;
  }

  absl::StatusOr<const ArrayType*> ScriptExecutorImpl::GetStackTraceSystemVariableType() {
    return nullptr;
  }

  absl::Status ScriptExecutorImpl::GenerateStackTraceSystemVariable(ScriptException::Internal* proto) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::string> ScriptExecutorImpl::GenerateStatementTextSystemVariable() const {
    return "";
  }

  absl::StatusOr<ScriptException> ScriptExecutorImpl::SetupNewException(const absl::Status& status) {
    ScriptException v;
    return v;
  }

  absl::Status ScriptExecutorImpl::EnterExceptionHandler(const ScriptException& exception) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::ExitExceptionHandler() {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::ExitForLoop() {
    return absl::OkStatus();
  }

  absl::StatusOr<const ASTStatement*> ScriptExecutorImpl::ExitProcedure(bool normal_return) {
      return nullptr;
  }

  bool ScriptExecutorImpl::IsComplete() const {
    return false;
  }

  absl::Status ScriptExecutorImpl::ExecuteNext() {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::ExecuteNextImpl() {
    return absl::OkStatus();
  }

  absl::StatusOr<bool> ScriptExecutorImpl::DefaultAssignSystemVariable(const ASTSystemVariableAssignment* ast_assignment, const Value& value) {
    return false;
  }

  absl::Status ScriptExecutorImpl::SetTimezone(const Value& timezone_value,
                                               const ASTNode* location) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::ExecuteSystemVariableAssignment(const ASTSystemVariableAssignment* stmt) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::ExecuteRaiseStatement(const ASTRaiseStatement* stmt) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::RaiseNewException(const ASTRaiseStatement* stmt) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::ReraiseCaughtException(const ASTRaiseStatement* stmt) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::UpdateAndCheckMemorySize(const ASTNode* node, int64_t current_memory_size,
                                                            int64_t previous_memory_size) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::UpdateAndCheckVariableSize(const ASTNode* node, const IdString& var_name, int64_t variable_size,
                                                              VariableSizesMap* variable_sizes_map) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::OnVariablesValueChangedWithoutSizeCheck(bool notify_evaluator, const StackFrame& var_declaration_stack_frame,
                                                                           const ASTNode* current_node,
                                                                           const std::vector<VariableChange>& variable_changes) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::OnVariablesValueChangedWithSizeCheck(bool notify_evaluator, const StackFrame& var_declaration_stack_frame,
                                                                        const ASTNode* current_node,
                                                                        const std::vector<VariableChange>& variable_changes,
                                                                        VariableSizesMap* variable_sizes_map) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::MakeVariableIsTooLargeError(const ASTNode* node, const IdString& var_name,
                                                               int64_t per_variable_size_limit) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::MakeNoSizeRemainingError(const ASTNode* node, int64_t total_size_limit,
                                                            const std::vector<StackFrameImpl>& callstack) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::ExecuteSingleAssignment() {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::ExecuteAssignmentFromStruct() {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::ExecuteVariableDeclaration() {
    return absl::OkStatus();
  }

  absl::StatusOr<Value> ScriptExecutorImpl::EvaluateExpression(const ASTExpression* expr, const Type* target_type) const {
    Value v;
    return v;
  }

  absl::StatusOr<bool> ScriptExecutorImpl::EvaluateCondition(const ASTExpression* condition) const {
    return false;
  }

  absl::Status ScriptExecutorImpl::ExecuteWhileCondition() {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::ExecuteCaseStatement() {
    return absl::OkStatus();
  }

  absl::StatusOr<bool> ScriptExecutorImpl::EvaluateWhenThenClause() {
    return false;
  }

  absl::StatusOr<Value> ScriptExecutorImpl::GenerateStructValueFromRow(TypeFactory* type_factory,
                                                                       const EvaluatorTableIterator& iterator,
                                                                       const StructType* struct_type) const {
    Value v;
    return v;
  }

  absl::Status ScriptExecutorImpl::ExecuteForInStatement() {
    return absl::OkStatus();
  }

  absl::StatusOr<OutputArgumentMap> VerifyOutputArgumentsAndBuildMap(const ProcedureDefinition& procedure_definition,
                                                                     const ASTCallStatement* call_statement, IdStringPool* id_string_pool) {
    OutputArgumentMap v;
    return v;
  }

  absl::StatusOr<Value> ScriptExecutorImpl::EvaluateProcedureArgument(absl::string_view argument_name,
                                                                      const FunctionArgumentType& function_argument_type,
                                                                      const ASTExpression* argument_expr) {
    Value v;
    return v;
  }

  absl::Status ScriptExecutorImpl::CheckAndEvaluateProcedureArguments(const ASTCallStatement* call_statement,
                                                                      const ProcedureDefinition& procedure_definition,
                                                                      IdStringPool* id_string_pool, VariableMap* variables,
                                                                      VariableSizesMap* variable_sizes) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::ExecuteCallStatement() {
    return absl::OkStatus();
  }

  absl::TimeZone ScriptExecutorImpl::time_zone() const {
    return time_zone_;
  }

  absl::Status ScriptExecutorImpl::UpdateAnalyzerOptions(AnalyzerOptions& analyzer_options) const {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::UpdateAnalyzerOptionParameters(AnalyzerOptions* options) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::optional<absl::variant<ParameterValueList, ParameterValueMap>>>
  ScriptExecutorImpl::EvaluateDynamicParams(const ASTExecuteUsingClause* using_clause,
                                            VariableSizesMap* variable_sizes_map) {
    std::optional<absl::variant<ParameterValueList, ParameterValueMap>> v;
    return v;
  }

  absl::Status ScriptExecutorImpl::ExecuteDynamicIntoStatement(const ASTExecuteIntoClause* into_clause) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::ExecuteDynamicStatement() {
    return absl::OkStatus();
  }

  absl::string_view ScriptExecutorImpl::GetScriptText() const {
    absl::string_view v;
    return v;
  }

  const ControlFlowNode* ScriptExecutorImpl::GetCurrentNode() const {
    return nullptr;
  }

  absl::Status ScriptExecutorImpl::ValidateVariablesOnSetState(const ControlFlowNode * next_cfg_node,
                                                               const VariableMap& new_variables,
                                                               const ParsedScript& parsed_script) const {
    return absl::OkStatus();
  }

  ParserOptions ScriptExecutorImpl::GetParserOptions() const {
    ParserOptions v;
    return v;
  }

  absl::Status ScriptExecutorImpl::SetState(const ScriptExecutorStateProto& state) {
    return absl::OkStatus();
  }

  absl::StatusOr<ScriptExecutorStateProto> ScriptExecutorImpl::GetState() const {
    ScriptExecutorStateProto v;
    return v;
  }

  absl::Status ScriptExecutorImpl::ResetVariableSizes(const ASTNode* node, const VariableMap& new_variables,
                                                      VariableSizesMap* variable_sizes) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::ResetIteratorSizes(const ASTNode* node,
                                                      const std::vector<std::unique_ptr<EvaluatorTableIterator>>& iterator_vec) {
    return absl::OkStatus();
  }

  std::string ScriptExecutorImpl::CallStackDebugString(bool verbose) const {
    return "";
  }

  std::string ScriptExecutorImpl::StackTraceString(absl::Span<StackFrameTrace> stack_frame_traces, bool verbose) const {
    return "";
  }

  std::string ScriptExecutorImpl::VariablesDebugString() const {
    return "";
  }

  std::string ScriptExecutorImpl::ParameterDebugString() const {
    return "";
  }

  std::string ScriptExecutorImpl::DebugString(bool verbose) const {
    return "";
  }

  absl::string_view ScriptExecutorImpl::GetCurrentProcedureName() const {
    return "";
  }

  absl::string_view ScriptExecutorImpl::GetCurrentStackFrameName() const {
    return "";
  }

  absl::StatusOr<std::vector<StackFrameTrace>> ScriptExecutorImpl::StackTrace() const {
    std::vector<StackFrameTrace> v;
    return v;
  }

  absl::Status ScriptExecutorImpl::Reset() {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::DestroyVariables(const std::set<std::string>& variables) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::AssignOutArguments(const ProcedureDefinition& procedure_definition,
                                                      const VariableMap& argument_map, StackFrameImpl* frame_return_to) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::ExitFromProcedure(const ProcedureDefinition& procedure_exit_from,
                                                     StackFrameImpl* frame_exit_from, StackFrameImpl* frame_return_to,
                                                     bool normal_return) {
    return absl::OkStatus();
  }

  bool ScriptExecutorImpl::CoercesTo(const Type* from_type,
                                     const Type* to_type) const {
    return false;
  }

  absl::StatusOr<Value> ScriptExecutorImpl::CastValueToType(const Value& from_value, const Type* to_type) const {
    Value v;
    return v;
  }

  ScriptSegment ScriptExecutorImpl::SegmentForScalarExpression(const ASTExpression* expr) const {
    ScriptSegment v;
    return v;
  }

  absl::StatusOr<bool> ScriptExecutorImpl::CheckIfExceptionHandled() const {
    return false;
  }

  absl::Status ScriptExecutorImpl::DispatchException(const ScriptException& exception) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::ExecuteSideEffects(const ControlFlowEdge& edge,
                                                      const absl::optional<ScriptException>& exception) {
    return absl::OkStatus();
  }

  absl::StatusOr<bool> ScriptExecutorImpl::UpdateCurrentLocation(const ControlFlowEdge& edge) {
    return false;
  }

  absl::Status ScriptExecutorImpl::AdvanceInternal(ControlFlowEdge::Kind edge_kind) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::AdvancePastCurrentStatement(const absl::Status& status) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::AdvancePastCurrentCondition(const absl::StatusOr<bool>& condition_value) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::MaybeDispatchException(const absl::Status& status) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::RethrowException(const ScriptException& exception) {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::EnterBlock() {
    return absl::OkStatus();
  }

  absl::Status ScriptExecutorImpl::SetPredefinedVariables(const VariableWithTypeParameterMap& variables) {
    return absl::OkStatus();
  }
}

namespace zetasql {

  absl::Status SerializeVariableProto(const VariableMap& variables, const VariableTypeParametersMap& type_params,
                                      google::protobuf::RepeatedPtrField<VariableProto>* variables_proto) {
    return absl::OkStatus();
  }

  absl::Status DeserializeVariableProto(const google::protobuf::RepeatedPtrField<VariableProto>& variables_proto,
                                        VariableMap* variables, VariableTypeParametersMap* variable_type_params,
                                        google::protobuf::DescriptorPool* descriptor_pool, IdStringPool* id_string_pool,
                                        TypeFactory* type_factory) {
    return absl::OkStatus();
  }

  // static
  absl::StatusOr<std::unique_ptr<ProcedureDefinition>>
  DeserializeProcedureDefinitionProto(const ScriptExecutorStateProto::ProcedureDefinition& proto,
                                      const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                      TypeFactory* factory) {
    std::unique_ptr<ProcedureDefinition> v;
    return v;
  }

  absl::Status SerializeProcedureDefinitionProto(const ProcedureDefinition& procedure_definition,
                                                 ScriptExecutorStateProto::ProcedureDefinition* proto,
                                                 FileDescriptorSetMap* file_descriptor_set_map) {

    return absl::OkStatus();
  }

  absl::Status SerializeParametersProto(const absl::optional<absl::variant<ParameterValueList, ParameterValueMap>>&
                                        parameters,
                                        ParametersProto* parameters_proto) {
    return absl::OkStatus();
  }

  absl::Status DeserializeParametersProto(const ParametersProto& parameters_proto,
                                          absl::optional<absl::variant<ParameterValueList, ParameterValueMap>>*
                                          parameters,
                                          google::protobuf::DescriptorPool* descriptor_pool, IdStringPool* id_string_pool,
                                          TypeFactory* type_factory) {
    return absl::OkStatus();
  }

}
#endif

#include "go-zetasql/scripting/control_flow_graph/export.inc"
#include "go-zetasql/scripting/error_helpers/export.inc"
#include "go-zetasql/scripting/parsed_script/export.inc"
#include "go-zetasql/scripting/script_exception_cc_proto/export.inc"
#include "go-zetasql/scripting/script_executor_state_cc_proto/export.inc"
#include "go-zetasql/scripting/script_segment/export.inc"
#include "go-zetasql/scripting/stack_frame/export.inc"
#include "go-zetasql/scripting/type_aliases/export.inc"
#include "go-zetasql/scripting/variable_cc_proto/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/flat_set/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/status_payload_utils/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/analyzer/export.inc"
#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/coercer/export.inc"
#include "go-zetasql/public/evaluator/export.inc"
#include "go-zetasql/public/evaluator_table_iterator/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-re2/re2/export.inc"

#endif
