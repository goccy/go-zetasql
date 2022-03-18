#ifndef ZETASQL_RESOLVED_AST_VALIDATOR_EXPORT_H
#define ZETASQL_RESOLVED_AST_VALIDATOR_EXPORT_H

#include "zetasql/resolved_ast/validator.h"
#include "zetasql/resolved_ast/validator.cc"

#if 0
namespace zetasql {

  Validator::Validator(const LanguageOptions& language_options,
                       ValidatorOptions validator_options)
    : options_(validator_options), language_options_(language_options) {}

  absl::Status Validator::ValidateResolvedParameter(const ResolvedParameter* resolved_param) {
    return absl::OkStatus();
  }

  absl::Status Validator::CheckColumnIsPresentInColumnSet(const ResolvedColumn& column,
                                                          const std::set<ResolvedColumn>& visible_columns) {
    return absl::OkStatus();
  }

  absl::Status Validator::CheckColumnList(const ResolvedScan* scan, const std::set<ResolvedColumn>& visible_columns) {
    return absl::OkStatus();
  }

  Validator::Validator() {}

  Validator::~Validator() {}

  absl::Status Validator::ValidateResolvedExprList(const std::set<ResolvedColumn>& visible_columns,
                                                   const std::set<ResolvedColumn>& visible_parameters,
                                                   const std::vector<std::unique_ptr<const ResolvedExpr>>& expr_list) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedFunctionArgumentList(const std::set<ResolvedColumn>& visible_columns,
                                                               const std::set<ResolvedColumn>& visible_parameters,
                                                               const std::vector<std::unique_ptr<const ResolvedFunctionArgument>>&
                                                               expr_list) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCast(const std::set<ResolvedColumn>& visible_columns,
                                               const std::set<ResolvedColumn>& visible_parameters,
                                               const ResolvedCast* resolved_cast) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedConstant(const std::set<ResolvedColumn>& visible_columns,
                                                   const std::set<ResolvedColumn>& visible_parameters,
                                                   const ResolvedConstant* resolved_constant) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateGenericArgumentsAgainstConcreteArguments(const ResolvedFunctionCallBase* resolved_function_call,
                                                                           const FunctionSignature& signature) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedFilterField(const std::set<ResolvedColumn>& visible_columns,
                                                      const std::set<ResolvedColumn>& visible_parameters,
                                                      const ResolvedFilterField* filter_field) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedFunctionCallBase(const std::set<ResolvedColumn>& visible_columns,
                                                           const std::set<ResolvedColumn>& visible_parameters,
                                                           const ResolvedFunctionCallBase* resolved_function_call) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateStandaloneResolvedExpr(const ResolvedExpr* expr) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedExpr(const std::set<ResolvedColumn>& visible_columns,
                                               const std::set<ResolvedColumn>& visible_parameters,
                                               const ResolvedExpr* expr) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateOrderByAndLimitClausesOfAggregateFunctionCall(const std::set<ResolvedColumn>& input_scan_visible_columns,
                                                                                const std::set<ResolvedColumn>& visible_parameters,
                                                                                const ResolvedAggregateFunctionCall* aggregate_function_call) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAggregateFunctionCall(const std::set<ResolvedColumn>& visible_columns,
                                                                const std::set<ResolvedColumn>& visible_parameters,
                                                                const ResolvedAggregateFunctionCall* aggregate_function_call) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAnalyticFunctionCall(const std::set<ResolvedColumn>& visible_columns,
                                                               const std::set<ResolvedColumn>& visible_parameters,
                                                               const ResolvedAnalyticFunctionCall* call) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedGetProtoFieldExpr(const std::set<ResolvedColumn>& visible_columns,
                                                            const std::set<ResolvedColumn>& visible_parameters,
                                                            const ResolvedGetProtoField* get_proto_field) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedGetJsonFieldExpr(const std::set<ResolvedColumn>& visible_columns,
                                                           const std::set<ResolvedColumn>& visible_parameters,
                                                           const ResolvedGetJsonField* get_json_field) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedFlatten(const std::set<ResolvedColumn>& visible_columns,
                                                  const std::set<ResolvedColumn>& visible_parameters,
                                                  const ResolvedFlatten* flatten) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedFlattenedArg(const ResolvedFlattenedArg* flattened_arg) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedReplaceField(const std::set<ResolvedColumn>& visible_columns,
                                                       const std::set<ResolvedColumn>& visible_parameters,
                                                       const ResolvedReplaceField* replace_field) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedInlineLambda(const std::set<ResolvedColumn>& visible_columns,
                                                       const std::set<ResolvedColumn>& visible_parameters,
                                                       const ResolvedInlineLambda* resolved_lambda) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedSubqueryExpr(const std::set<ResolvedColumn>& visible_columns,
                                                       const std::set<ResolvedColumn>& visible_parameters,
                                                       const ResolvedSubqueryExpr* resolved_subquery_expr) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedLetExpr(const std::set<ResolvedColumn>& visible_columns,
                                                  const std::set<ResolvedColumn>& visible_parameters,
                                                  const ResolvedLetExpr* resolved_let_expr) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedComputedColumn(const std::set<ResolvedColumn>& visible_columns,
                                                         const std::set<ResolvedColumn>& visible_parameters,
                                                         const ResolvedComputedColumn* computed_column) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedComputedColumnList(const std::set<ResolvedColumn>& visible_columns,
                                                             const std::set<ResolvedColumn>& visible_parameters,
                                                             const std::vector<std::unique_ptr<const ResolvedComputedColumn>>&
                                                             computed_column_list) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedOutputColumn(const std::set<ResolvedColumn>& visible_columns,
                                                       const ResolvedOutputColumn* output_column) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedOutputColumnList(const std::vector<ResolvedColumn>& visible_columns,
                                                           const std::vector<std::unique_ptr<const ResolvedOutputColumn>>&
                                                           output_column_list,
                                                           bool is_value_table) {
    return absl::OkStatus();
  }

  absl::Status Validator::AddColumnList(const ResolvedColumnList& column_list,
                                        std::set<ResolvedColumn>* visible_columns) {
    return absl::OkStatus();
  }

  absl::Status Validator::AddColumnList(const ResolvedColumnList& column_list,
                                        absl::flat_hash_set<ResolvedColumn>* visible_columns) {
    return absl::OkStatus();
  }

  absl::Status Validator::AddColumn(const ResolvedColumn& column,
                                    absl::flat_hash_set<ResolvedColumn>* visible_columns) {
    return absl::OkStatus();
  }

  absl::Status Validator::AddColumnFromComputedColumn(const ResolvedComputedColumn* computed_column,
                                                      std::set<ResolvedColumn>* visible_columns) {
    return absl::OkStatus();
  }

  absl::Status Validator::AddColumnsFromComputedColumnList(const std::vector<std::unique_ptr<const ResolvedComputedColumn>>&
                                                           computed_column_list,
                                                           std::set<ResolvedColumn>* visible_columns) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedTableScan(const ResolvedTableScan* scan,
                                                    const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedJoinScan(const ResolvedJoinScan* scan,
                                                   const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedArrayScan(const ResolvedArrayScan* scan,
                                                    const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedFilterScan(const ResolvedFilterScan* scan,
                                                     const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAggregateComputedColumn(const ResolvedComputedColumn* computed_column,
                                                                  const std::set<ResolvedColumn>& input_scan_visible_columns,
                                                                  const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAggregateScanBase(const ResolvedAggregateScanBase* scan,
                                                            const std::set<ResolvedColumn>& visible_parameters,
                                                            std::set<ResolvedColumn>* input_scan_visible_columns) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAggregateScan(const ResolvedAggregateScan* scan,
                                                        const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAnonymizedAggregateScan(const ResolvedAnonymizedAggregateScan* scan,
                                                                  const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidatePercentArgument(const ResolvedExpr* expr) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedSampleScan(const ResolvedSampleScan* scan,
                                                     const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::CheckUniqueColumnId(const ResolvedColumn& column) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAnalyticScan(const ResolvedAnalyticScan* scan,
                                                       const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAnalyticFunctionGroup(const ResolvedAnalyticFunctionGroup* group,
                                                                const std::set<ResolvedColumn>& input_visible_columns,
                                                                const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedWindowFrame(const std::set<ResolvedColumn>& visible_columns,
                                                      const std::set<ResolvedColumn>& visible_parameters,
                                                      const ResolvedWindowOrdering* window_ordering,
                                                      const ResolvedWindowFrame* window_frame) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedWindowFrameExpr(const std::set<ResolvedColumn>& visible_columns,
                                                          const std::set<ResolvedColumn>& visible_parameters,
                                                          const ResolvedWindowOrdering* window_ordering,
                                                          const ResolvedWindowFrame::FrameUnit& frame_unit,
                                                          const ResolvedWindowFrameExpr* window_frame_expr) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedWindowFrameExprType(const ResolvedWindowFrame::FrameUnit& frame_unit,
                                                              const ResolvedExpr* window_ordering_expr,
                                                              const ResolvedExpr& window_frame_expr) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedSetOperationItem(const ResolvedSetOperationItem* input_item,
                                                           const ResolvedColumnList& output_column_list,
                                                           const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedSetOperationScan(const ResolvedSetOperationScan* set_op_scan,
                                                           const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateArgumentIsInt64Constant(const ResolvedExpr* expr) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedLimitOffsetScan(const ResolvedLimitOffsetScan* scan,
                                                          const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedProjectScan(const ResolvedProjectScan* scan,
                                                      const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedTVFScan(const ResolvedTVFScan* resolved_tvf_scan,
                                                  const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedRelationArgumentScan(const ResolvedRelationArgumentScan* arg_ref,
                                                               const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedWithScan(const ResolvedWithScan* scan,
                                                   const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedReturningClause(const ResolvedReturningClause* returning,
                                                          std::set<ResolvedColumn>& visible_columns) {
    return absl::OkStatus();
  }

  void Validator::Reset() {
  }

  absl::Status Validator::ValidateResolvedStatement(const ResolvedStatement* statement) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedStatementInternal(const ResolvedStatement* statement) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateDatabaseStmt(const ResolvedCreateDatabaseStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedIndexStmt(const ResolvedCreateIndexStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateSchemaStmt(const ResolvedCreateSchemaStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedForeignKey(const ResolvedForeignKey* foreign_key,
                                                     const std::vector<const Type*> column_types,
                                                     absl::flat_hash_set<std::string>* constraint_names) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedPrimaryKey(const std::vector<const Type*>& resolved_column_types,
                                                     const ResolvedPrimaryKey* primary_key,
                                                     absl::flat_hash_set<std::string>* seen_constraint_names) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateColumnDefinitions(const std::vector<std::unique_ptr<const ResolvedColumnDefinition>>&
                                                    column_definitions,
                                                    std::set<ResolvedColumn>* visible_columns) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateTableStmtBase(const ResolvedCreateTableStmtBase* stmt,
                                                              std::set<ResolvedColumn>* visible_columns) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateTableStmt(const ResolvedCreateTableStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateSnapshotTableStmt(const ResolvedCreateSnapshotTableStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedGeneratedColumnInfo(const ResolvedColumnDefinition* column_definition,
                                                              const std::set<ResolvedColumn>& visible_columns) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateTableAsSelectStmt(const ResolvedCreateTableAsSelectStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateModelStmt(const ResolvedCreateModelStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateViewStmt(const ResolvedCreateViewStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateMaterializedViewStmt(const ResolvedCreateMaterializedViewStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedWithPartitionColumns(const ResolvedWithPartitionColumns* with_partition_columns,
                                                               std::set<ResolvedColumn>* visible_columns) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateExternalTableStmt(const ResolvedCreateExternalTableStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreatePrivilegeRestrictionStmt(const ResolvedCreatePrivilegeRestrictionStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateRowAccessPolicyStmt(const ResolvedCreateRowAccessPolicyStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateConstantStmt(const ResolvedCreateConstantStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateFunctionStmt(const ResolvedCreateFunctionStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::CheckFunctionArgumentType(const FunctionArgumentTypeList& argument_type_list,
                                                    absl::string_view statement_type) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateTableFunctionStmt(const ResolvedCreateTableFunctionStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateProcedureStmt(const ResolvedCreateProcedureStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCreateEntityStmt(const ResolvedCreateEntityStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAlterEntityStmt(const ResolvedAlterEntityStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateCompatibleSchemaForClone(const Table* source,
                                                           const Table* target) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateSingleCloneDataSource(const ResolvedScan* source, const Table* target) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCloneDataSource(const ResolvedScan* source, const Table* target) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCloneDataStmt(const ResolvedCloneDataStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedExportDataStmt(const ResolvedExportDataStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedExportModelStmt(const ResolvedExportModelStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCallStmt(const ResolvedCallStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedDefineTableStmt(const ResolvedDefineTableStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedDescribeStmt(const ResolvedDescribeStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedShowStmt(const ResolvedShowStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedBeginStmt(const ResolvedBeginStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedSetTransactionStmt(const ResolvedSetTransactionStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedCommitStmt(const ResolvedCommitStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedRollbackStmt(const ResolvedRollbackStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedStartBatchStmt(const ResolvedStartBatchStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedRunBatchStmt(const ResolvedRunBatchStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAbortBatchStmt(const ResolvedAbortBatchStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedDropStmt(const ResolvedDropStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedDropFunctionStmt(const ResolvedDropFunctionStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedDropTableFunctionStmt(const ResolvedDropTableFunctionStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedDropSnapshotTableStmt(const ResolvedDropSnapshotTableStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedDropMaterializedViewStmt(const ResolvedDropMaterializedViewStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedDropPrivilegeRestrictionStmt(const ResolvedDropPrivilegeRestrictionStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedDropRowAccessPolicyStmt(const ResolvedDropRowAccessPolicyStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedDropSearchIndexStmt(const ResolvedDropSearchIndexStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedGrantStmt(const ResolvedGrantStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedRevokeStmt(const ResolvedRevokeStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedOrderByScan(const ResolvedOrderByScan* scan,
                                                      const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedOrderByItem(const std::set<ResolvedColumn>& visible_columns,
                                                      const std::set<ResolvedColumn>& visible_parameters,
                                                      const ResolvedOrderByItem* item) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedQueryStmt(const ResolvedQueryStmt* query) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedScan(const ResolvedScan* scan,
                                               const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedRecursiveScan(const ResolvedRecursiveScan* scan,
                                                        const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedRecursiveRefScan(const ResolvedRecursiveRefScan* scan) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedScanOrdering(const ResolvedScan* scan) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateGroupRowsScan(const ResolvedGroupRowsScan* scan) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateHintList(const std::vector<std::unique_ptr<const ResolvedOption>>& hint_list) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedTableAndColumnInfo(const ResolvedTableAndColumnInfo* table_and_column_info) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedTableAndColumnInfoList(const std::vector<std::unique_ptr<const ResolvedTableAndColumnInfo>>&
                                                                 table_and_column_info_list) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateCollateExpr(const ResolvedExpr* resolved_collate) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateColumnAnnotations(const ResolvedColumnAnnotations* annotations) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateUpdatedAnnotations(const ResolvedColumnAnnotations* annotations) {
    return absl::OkStatus();
  }

  template <class STMT>
  absl::Status Validator::ValidateResolvedDMLStmt(const STMT* stmt, const ResolvedColumn* array_element_column,
                                                  std::set<ResolvedColumn>* visible_columns) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedInsertStmt(const ResolvedInsertStmt* stmt,
                                                     const std::set<ResolvedColumn>* outer_visible_columns,
                                                     const ResolvedColumn* array_element_column) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedDeleteStmt(const ResolvedDeleteStmt* stmt,
                                                     const std::set<ResolvedColumn>* outer_visible_columns,
                                                     const ResolvedColumn* array_element_column) {
    return absl::OkStatus();
  }

  absl::Status Validator::CheckExprIsPath(const ResolvedExpr* expr,
                                          const ResolvedColumnRef** ref) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedUpdateStmt(const ResolvedUpdateStmt* stmt,
                                                     const std::set<ResolvedColumn>* outer_visible_columns,
                                                     const ResolvedColumn* array_element_column) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedUpdateItem(const ResolvedUpdateItem* item, bool allow_nested_statements,
                                                     const ResolvedColumn* array_element_column,
                                                     const std::set<ResolvedColumn>& target_visible_columns,
                                                     const std::set<ResolvedColumn>& offset_and_where_visible_columns) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedUpdateArrayItem(const ResolvedUpdateArrayItem* item, const ResolvedColumn& element_column,
                                                          const std::set<ResolvedColumn>& target_visible_columns,
                                                          const std::set<ResolvedColumn>& offset_and_where_visible_columns) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedMergeWhen(const ResolvedMergeWhen* merge_when,
                                                    const std::set<ResolvedColumn>& all_visible_columns,
                                                    const std::set<ResolvedColumn>& source_visible_columns,
                                                    const std::set<ResolvedColumn>& target_visible_columns) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedMergeStmt(const ResolvedMergeStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedTruncateStmt(const ResolvedTruncateStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAlterTableSetOptionsStmt(const ResolvedAlterTableSetOptionsStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAlterPrivilegeRestrictionStmt(const ResolvedAlterPrivilegeRestrictionStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAlterRowAccessPolicyStmt(const ResolvedAlterRowAccessPolicyStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAlterAllRowAccessPoliciesStmt(const ResolvedAlterAllRowAccessPoliciesStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedRenameStmt(const ResolvedRenameStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedImportStmt(const ResolvedImportStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedModuleStmt(const ResolvedModuleStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAssignmentStmt(const ResolvedAssignmentStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAnalyzeStmt(const ResolvedAnalyzeStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAssertStmt(const ResolvedAssertStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedFunctionArgument(const std::set<ResolvedColumn>& visible_columns,
                                                           const std::set<ResolvedColumn>& visible_parameters,
                                                           const ResolvedFunctionArgument* resolved_arg) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateRelationSchemaInResolvedFunctionArgument(const TVFRelation& required_input_schema, const TVFRelation& input_relation,
                                                                           const ResolvedFunctionArgument* resolved_arg) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAlterObjectStmt(const ResolvedAlterObjectStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateAddForeignKeyAction(const ResolvedAddConstraintAction* action,
                                                      absl::flat_hash_set<std::string>* constraint_names) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAlterAction(const ResolvedAlterAction* action) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedColumnDefaultValue(const ResolvedColumnDefaultValue* default_value,
                                                             const zetasql::Type* column_type, bool skip_check_type_match) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedExecuteImmediateStmt(const ResolvedExecuteImmediateStmt* stmt) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedPivotScan(const ResolvedPivotScan* scan,
                                                    const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedUnpivotScan(const ResolvedUnpivotScan* scan,
                                                      const std::set<ResolvedColumn>& visible_parameters) {
    return absl::OkStatus();
  }

  absl::Status Validator::ValidateResolvedAuxLoadDataStmt(const ResolvedAuxLoadDataStmt* stmt) {
    return absl::OkStatus();
  }

  std::string Validator::RecordContext() {
    return "";
  }

}
#endif

#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast_enums_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/rewrite_utils/export.inc"
#include "go-zetasql/analyzer/filter_fields_path_validator/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/stl_util/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/base/varsetter/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/constant/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/function_cc_proto/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/templated_sql_function/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-absl/cleanup/cleanup/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
