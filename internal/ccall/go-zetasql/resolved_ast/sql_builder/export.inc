#ifndef ZETASQL_RESOLVED_AST_SQL_BUILDER_EXPORT_H
#define ZETASQL_RESOLVED_AST_SQL_BUILDER_EXPORT_H

#include "zetasql/resolved_ast/query_expression.h"
#include "zetasql/resolved_ast/sql_builder.h"

#include "zetasql/resolved_ast/query_expression.cc"
#include "zetasql/resolved_ast/sql_builder.cc"

#if 0
namespace zetasql {

  void QueryExpression::ClearAllClauses() {
  }

  std::string QueryExpression::GetSQLQuery() const {
    return "";
  }

  bool QueryExpression::CanFormSQLQuery() const {
    return false;
  }

  void QueryExpression::Wrap(const std::string& alias) {
  }

  bool QueryExpression::TrySetWithClause(const std::vector<std::pair<std::string, std::string>>& with_list,
                                         bool recursive) {
    return false;
  }

  bool QueryExpression::TrySetSelectClause(const std::vector<std::pair<std::string, std::string>>& select_list,
                                           const std::string& select_hints) {
    return false;
  }

  void QueryExpression::ResetSelectClause() {
  }

  bool QueryExpression::TrySetFromClause(const std::string& from) {
    return false;
  }

  bool QueryExpression::TrySetWhereClause(const std::string& where) {
    return false;
  }

  bool QueryExpression::TrySetSetOpScanList(std::vector<std::unique_ptr<QueryExpression>>* set_op_scan_list,
                                            const std::string& set_op_type, const std::string& set_op_modifier,
                                            const std::string& query_hints) {
    return false;
  }

  bool QueryExpression::TrySetGroupByClause(const std::map<int, std::string>& group_by_list,
                                            const std::string& group_by_hints,
                                            const std::vector<int>& rollup_column_id_list) {
    return false;
  }

  bool QueryExpression::TrySetOrderByClause(const std::vector<std::string>& order_by_list,
                                            const std::string& order_by_hints) {
    return false;
  }

  bool QueryExpression::TrySetLimitClause(const std::string& limit) {
    return false;
  }

  bool QueryExpression::TrySetOffsetClause(const std::string& offset) {
    return false;
  }

  bool QueryExpression::TrySetWithAnonymizationClause(const std::string& anonymization_options) {
    return false;
  }

  bool QueryExpression::TrySetPivotClause(const std::string& pivot) {
    return false;
  }

  bool QueryExpression::TrySetUnpivotClause(const std::string& unpivot) {
    return false;
  }

  bool QueryExpression::CanSetWithClause() const {
    return false;
  }

  bool QueryExpression::CanSetSelectClause() const {
    return false;
  }

  bool QueryExpression::CanSetFromClause() const {
    return false;
  }

  bool QueryExpression::CanSetWhereClause() const {
    return false;
  }

  bool QueryExpression::CanSetSetOpScanList() const {
    return false;
  }

  bool QueryExpression::CanSetGroupByClause() const {
    return false;
  }

  bool QueryExpression::CanSetOrderByClause() const {
    return false;
  }

  bool QueryExpression::CanSetLimitClause() const {
    return false;
  }

  bool QueryExpression::CanSetOffsetClause() const {
    return false;
  }

  bool QueryExpression::CanSetPivotClause() const {
    return false;
  }

  bool QueryExpression::CanSetUnpivotClause() const {
    return false;
  }

  const std::vector<std::pair<std::string, std::string>>&
  QueryExpression::SelectList() const {
    const std::vector<std::pair<std::string, std::string>> *v;
    return *v;
  }

  bool QueryExpression::CanSetWithAnonymizationClause() const {
    return false;
  }

  void QueryExpression::SetAliasForSelectColumn(int select_column_pos,
                                                const std::string& alias) {
  }

  void QueryExpression::SetSelectAsModifier(const std::string& modifier) {
  }

}

namespace zetasql {

  std::string SQLBuilder::GetColumnPath(const ResolvedColumn& column) {
    return "";
  }

  std::string SQLBuilder::GetColumnAlias(const ResolvedColumn& column) {
    return "";
  }

  std::string SQLBuilder::UpdateColumnAlias(const ResolvedColumn& column) {
    return "";
  }

  SQLBuilder::SQLBuilder(const SQLBuilderOptions& options) : options_(options) {}

  absl::Status SQLBuilder::Process(const ResolvedNode& ast) {
    return absl::OkStatus();
  }

  std::string SQLBuilder::QueryFragment::GetSQL() const {
    return "";
  }

  SQLBuilder::~SQLBuilder() {}

  void SQLBuilder::DumpQueryFragmentStack() {
  }

  void SQLBuilder::PushQueryFragment(std::unique_ptr<QueryFragment> query_fragment) {
  }

  void SQLBuilder::PushQueryFragment(const ResolvedNode* node, const std::string& text) {
  }

  void SQLBuilder::PushQueryFragment(const ResolvedNode* node, QueryExpression* query_expression) {
  }

  std::unique_ptr<SQLBuilder::QueryFragment> SQLBuilder::PopQueryFragment() {
    std::unique_ptr<SQLBuilder::QueryFragment> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<SQLBuilder::QueryFragment>>
  SQLBuilder::ProcessNode(const ResolvedNode* node) {
    std::unique_ptr<SQLBuilder::QueryFragment> v;
    return v;
  }

  absl::StatusOr<std::string> SQLBuilder::GetSQL(const Value& value,
                                                 ProductMode mode,
                                                 bool is_constant_value) {
    return "";
  }

  absl::Status SQLBuilder::VisitResolvedCloneDataStmt(const ResolvedCloneDataStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedExpressionColumn(const ResolvedExpressionColumn* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedLiteral(const ResolvedLiteral* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedConstant(const ResolvedConstant* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedFunctionCall(const ResolvedFunctionCall* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedInlineLambda(const ResolvedInlineLambda* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAggregateFunctionCall(const ResolvedAggregateFunctionCall* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAnalyticFunctionCall(const ResolvedAnalyticFunctionCall* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAnalyticFunctionGroup(const ResolvedAnalyticFunctionGroup* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedWindowPartitioning(const ResolvedWindowPartitioning* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedWindowOrdering(const ResolvedWindowOrdering* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedWindowFrame(const ResolvedWindowFrame* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedWindowFrameExpr(const ResolvedWindowFrameExpr* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedGetProtoField(const ResolvedGetProtoField* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedFlatten(const ResolvedFlatten* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedFlattenedArg(const ResolvedFlattenedArg* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedFilterField(const ResolvedFilterField* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedReplaceField(const ResolvedReplaceField* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedColumnRef(const ResolvedColumnRef* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCast(const ResolvedCast* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedSubqueryExpr(const ResolvedSubqueryExpr* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedLetExpr(const ResolvedLetExpr* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedTableAndColumnInfo(const ResolvedTableAndColumnInfo* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::AppendColumnSchema(const Type* type, bool is_hidden,
                                              const ResolvedColumnAnnotations* annotations,
                                              const ResolvedGeneratedColumnInfo* generated_column_info,
                                              const ResolvedColumnDefaultValue* default_value, std::string* text) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::string> SQLBuilder::GetHintListString(const std::vector<std::unique_ptr<const ResolvedOption>>& hint_list) {
    return "";
  }

  absl::Status SQLBuilder::AppendOptions(const std::vector<std::unique_ptr<const ResolvedOption>>& option_list,
                                         std::string* sql) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::AppendOptionsIfPresent(const std::vector<std::unique_ptr<const ResolvedOption>>& option_list,
                                                  std::string* sql) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::AppendHintsIfPresent(const std::vector<std::unique_ptr<const ResolvedOption>>& hint_list,
                                                std::string* text) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedOption(const ResolvedOption* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedSystemVariable(const ResolvedSystemVariable* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedParameter(const ResolvedParameter* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedMakeProto(const ResolvedMakeProto* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedMakeProtoField(const ResolvedMakeProtoField* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedMakeStruct(const ResolvedMakeStruct* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedGetStructField(const ResolvedGetStructField* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedGetJsonField(const ResolvedGetJsonField* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::WrapQueryExpression(const ResolvedScan* node, QueryExpression* query_expression) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::GetSelectList(const ResolvedColumnList& column_list,
                                         const std::map<int64_t, const ResolvedExpr*>& col_to_expr_map,
                                         const ResolvedScan* parent_scan, QueryExpression* query_expression,
                                         std::vector<std::pair<std::string, std::string>>* select_list) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::GetSelectList(const ResolvedColumnList& column_list, QueryExpression* query_expression,
                                         std::vector<std::pair<std::string, std::string>>* select_list) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::AddSelectListIfNeeded(const ResolvedColumnList& column_list, QueryExpression* query_expression) {
    return absl::OkStatus();
  }

  bool SQLBuilder::CanTableBeUsedWithImplicitAlias(const Table* table) {
    return false;
  }

  absl::Status SQLBuilder::VisitResolvedTableScan(const ResolvedTableScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedSingleRowScan(const ResolvedSingleRowScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedPivotScan(const ResolvedPivotScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedUnpivotScan(const ResolvedUnpivotScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedProjectScan(const ResolvedProjectScan* node) {
    return absl::OkStatus();
  }

  std::string SQLBuilder::ComputedColumnAliasDebugString() const {
    return "";
  }

  absl::Status SQLBuilder::VisitResolvedTVFScan(const ResolvedTVFScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedRelationArgumentScan(const ResolvedRelationArgumentScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedFilterScan(const ResolvedFilterScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAnalyticScan(const ResolvedAnalyticScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedGroupRowsScan(const ResolvedGroupRowsScan* node) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::string> SQLBuilder::GetJoinOperand(const ResolvedScan* scan) {
    return "";
  }

  std::string SQLBuilder::MakeNonconflictingAlias(const std::string& name) {
    return "";
  }

  std::string SQLBuilder::GetTableAlias(const Table* table) {
    return "";
  }

  std::string SQLBuilder::GetScanAlias(const ResolvedScan* scan) {
    return "";
  }

  int64_t SQLBuilder::GetUniqueId() {
    return 0;
  }

  void SQLBuilder::SetPathForColumn(const ResolvedColumn& column,
                                    const std::string& path) {
  }

  void SQLBuilder::SetPathForColumnList(const ResolvedColumnList& column_list,
                                        const std::string& scan_alias) {
  }

  absl::Status SQLBuilder::SetPathForColumnsInScan(const ResolvedScan* scan,
                                                   const std::string& alias) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::SetPathForColumnsInReturningExpr(const ResolvedExpr* expr) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedJoinScan(const ResolvedJoinScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedColumnHolder(const ResolvedColumnHolder* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedArrayScan(const ResolvedArrayScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedLimitOffsetScan(const ResolvedLimitOffsetScan* node) {
    return absl::OkStatus();
  }

  std::pair<std::string, std::string> GetOpTypePair(ResolvedRecursiveScan::RecursiveSetOperationType op_type) {
    std::pair<std::string, std::string> v;
    return v;
  }

  std::pair<std::string, std::string> GetOpTypePair(ResolvedSetOperationScan::SetOperationType op_type) {
    std::pair<std::string, std::string> v;
    return v;
  }

  absl::Status SQLBuilder::VisitResolvedSetOperationScan(const ResolvedSetOperationScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedOrderByItem(const ResolvedOrderByItem* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedComputedColumn(const ResolvedComputedColumn* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedOrderByScan(const ResolvedOrderByScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::ProcessAggregateScanBase(const ResolvedAggregateScanBase* node,
                                                    const std::vector<int>& rollup_column_id_list,
                                                    QueryExpression* query_expression) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAggregateScan(const ResolvedAggregateScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAnonymizedAggregateScan(const ResolvedAnonymizedAggregateScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedWithScan(const ResolvedWithScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedWithRefScan(const ResolvedWithRefScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedSampleScan(const ResolvedSampleScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::MatchOutputColumns(const std::vector<std::unique_ptr<const ResolvedOutputColumn>>&
                                              output_column_list,
                                              const ResolvedScan* query, QueryExpression* query_expression) {
    return absl::OkStatus();
  }

  absl::StatusOr<QueryExpression*> SQLBuilder::ProcessQuery(const ResolvedScan* query,
                                                            const std::vector<std::unique_ptr<const ResolvedOutputColumn>>&
                                                            output_column_list) {
    return nullptr;
  }

  absl::Status SQLBuilder::VisitResolvedQueryStmt(const ResolvedQueryStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedExplainStmt(const ResolvedExplainStmt* node) {
    return absl::OkStatus();
  }

  void SQLBuilder::GetOptionalColumnNameList(const ResolvedCreateViewBase* node,
                                             std::string* sql) {
  }

  absl::Status SQLBuilder::MaybeSetupRecursiveView(const ResolvedCreateViewBase* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::GetCreateViewStatement(const ResolvedCreateViewBase* node, bool is_value_table,
                                                  const std::string& view_type) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::GetCreateStatementPrefix(const ResolvedCreateStatement* node, const std::string& object_type,
                                                    std::string* sql) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::GetPartitionByListString(const std::vector<std::unique_ptr<const ResolvedExpr>>& partition_by_list,
                                                    std::string* sql) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::GetTableAndColumnInfoList(const std::vector<std::unique_ptr<const ResolvedTableAndColumnInfo>>&
                                                     table_and_column_info_list,
                                                     std::string* sql) {
    return absl::OkStatus();
  }

  std::string SQLBuilder::GetOptionalObjectType(const std::string& object_type) {
    return "";
  }

  absl::Status SQLBuilder::GetPrivilegesString(const ResolvedGrantOrRevokeStmt* node, std::string* sql) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCreateDatabaseStmt(const ResolvedCreateDatabaseStmt* node) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::string> SQLBuilder::ProcessForeignKey(const ResolvedForeignKey* foreign_key, bool is_if_not_exists) {
    return "";
  }

  absl::StatusOr<std::string> SQLBuilder::ProcessPrimaryKey(const ResolvedPrimaryKey* resolved_primary_key) {
    return "";
  }

  absl::Status SQLBuilder::ProcessTableElementsBase(std::string* sql,
                                                    const std::vector<std::unique_ptr<const ResolvedColumnDefinition>>&
                                                    column_definition_list,
                                                    const ResolvedPrimaryKey* resolved_primary_key,
                                                    const std::vector<std::unique_ptr<const ResolvedForeignKey>>&
                                                    foreign_key_list,
                                                    const std::vector<std::unique_ptr<const ResolvedCheckConstraint>>&
                                                    check_constraint_list) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::string> SQLBuilder::ProcessCreateTableStmtBase(const ResolvedCreateTableStmtBase* node, bool process_column_definitions,
                                                                     const std::string& table_type) {
    return "";
  }

  absl::Status SQLBuilder::VisitResolvedCreateSchemaStmt(const ResolvedCreateSchemaStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::AppendCloneDataSource(const ResolvedScan* source,
                                                 std::string* sql) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCreateTableStmt(const ResolvedCreateTableStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCreateSnapshotTableStmt(const ResolvedCreateSnapshotTableStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCreateTableAsSelectStmt(const ResolvedCreateTableAsSelectStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCreateModelStmt(const ResolvedCreateModelStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCreateIndexStmt(const ResolvedCreateIndexStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCreateViewStmt(const ResolvedCreateViewStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCreateMaterializedViewStmt(const ResolvedCreateMaterializedViewStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::ProcessWithPartitionColumns(std::string* sql, const ResolvedWithPartitionColumns* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCreateExternalTableStmt(const ResolvedCreateExternalTableStmt* node) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::string> SQLBuilder::GetFunctionArgListString(const std::vector<std::string>& arg_name_list,
                                                                   const FunctionSignature& signature) {
    return "";
  }

  absl::Status SQLBuilder::VisitResolvedCreateConstantStmt(const ResolvedCreateConstantStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCreateFunctionStmt(const ResolvedCreateFunctionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCreateTableFunctionStmt(const ResolvedCreateTableFunctionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCreateProcedureStmt(const ResolvedCreateProcedureStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedArgumentDef(const ResolvedArgumentDef* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedArgumentRef(const ResolvedArgumentRef* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedExportDataStmt(const ResolvedExportDataStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedExportModelStmt(const ResolvedExportModelStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCallStmt(const ResolvedCallStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedDefineTableStmt(const ResolvedDefineTableStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedDescribeStmt(const ResolvedDescribeStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedShowStmt(const ResolvedShowStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedBeginStmt(const ResolvedBeginStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedSetTransactionStmt(const ResolvedSetTransactionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCommitStmt(const ResolvedCommitStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedRollbackStmt(const ResolvedRollbackStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedStartBatchStmt(const ResolvedStartBatchStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedRunBatchStmt(const ResolvedRunBatchStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAbortBatchStmt(const ResolvedAbortBatchStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAssignmentStmt(const ResolvedAssignmentStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAnalyzeStmt(const ResolvedAnalyzeStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAssertStmt(const ResolvedAssertStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAssertRowsModified(const ResolvedAssertRowsModified* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedDeleteStmt(const ResolvedDeleteStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedReturningClause(const ResolvedReturningClause* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedDropStmt(const ResolvedDropStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedDropFunctionStmt(const ResolvedDropFunctionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedDropTableFunctionStmt(const ResolvedDropTableFunctionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedDropMaterializedViewStmt(const ResolvedDropMaterializedViewStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedDropSnapshotTableStmt(const ResolvedDropSnapshotTableStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedDropPrivilegeRestrictionStmt(const ResolvedDropPrivilegeRestrictionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedDropRowAccessPolicyStmt(const ResolvedDropRowAccessPolicyStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedDropSearchIndexStmt(const ResolvedDropSearchIndexStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedTruncateStmt(const ResolvedTruncateStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedDMLDefault(const ResolvedDMLDefault* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedDMLValue(const ResolvedDMLValue* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedUpdateItem(const ResolvedUpdateItem* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedUpdateArrayItem(const ResolvedUpdateArrayItem* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedUpdateStmt(const ResolvedUpdateStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedInsertRow(const ResolvedInsertRow* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedInsertStmt(const ResolvedInsertStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedMergeStmt(const ResolvedMergeStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedMergeWhen(const ResolvedMergeWhen* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAlterDatabaseStmt(const ResolvedAlterDatabaseStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAlterSchemaStmt(const ResolvedAlterSchemaStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAlterTableSetOptionsStmt(const ResolvedAlterTableSetOptionsStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::GetResolvedAlterObjectStmtSQL(const ResolvedAlterObjectStmt* node, absl::string_view object_kind) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAlterTableStmt(const ResolvedAlterTableStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAlterViewStmt(const ResolvedAlterViewStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAlterMaterializedViewStmt(const ResolvedAlterMaterializedViewStmt* node) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::string> SQLBuilder::GetAlterActionSQL(const std::vector<std::unique_ptr<const ResolvedAlterAction>>&
                                                            alter_action_list) {
    return "";
  }

  absl::StatusOr<std::string> SQLBuilder::GetGranteeListSQL(const std::string& prefix, const std::vector<std::string>& grantee_list,
                                                            const std::vector<std::unique_ptr<const ResolvedExpr>>& grantee_expr_list) {
    return "";
  }

  absl::Status SQLBuilder::VisitResolvedAlterPrivilegeRestrictionStmt(const ResolvedAlterPrivilegeRestrictionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAlterRowAccessPolicyStmt(const ResolvedAlterRowAccessPolicyStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAlterAllRowAccessPoliciesStmt(const ResolvedAlterAllRowAccessPoliciesStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedPrivilege(const ResolvedPrivilege* node) {
    return absl::OkStatus();
  }

  absl::StatusOr<absl::string_view> SQLBuilder::GetNullHandlingModifier(ResolvedNonScalarFunctionCallBase::NullHandlingModifier kind) {
    absl::string_view v;
    return v;
  }

  absl::Status SQLBuilder::VisitResolvedAggregateHavingModifier(const ResolvedAggregateHavingModifier* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedGrantStmt(const ResolvedGrantStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedRevokeStmt(const ResolvedRevokeStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedRenameStmt(const ResolvedRenameStmt* node) {
    return absl::OkStatus();
  }

  std::string SQLBuilder::sql() {
    return "";
  }

  absl::Status SQLBuilder::VisitResolvedCreatePrivilegeRestrictionStmt(const ResolvedCreatePrivilegeRestrictionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCreateRowAccessPolicyStmt(const ResolvedCreateRowAccessPolicyStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedImportStmt(const ResolvedImportStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedModuleStmt(const ResolvedModuleStmt* node) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::string> SQLBuilder::ProcessExecuteImmediateArgument(const ResolvedExecuteImmediateArgument* node) {
    return "";
  }

  absl::Status SQLBuilder::VisitResolvedExecuteImmediateStmt(const ResolvedExecuteImmediateStmt* node) {
    return absl::OkStatus();
  }

  void SQLBuilder::PushSQLForQueryExpression(const ResolvedNode* node,
                                             QueryExpression* query_expression) {
  }

  absl::Status SQLBuilder::DefaultVisit(const ResolvedNode* node) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::string> SQLBuilder::GetUpdateItemListSQL(const std::vector<std::unique_ptr<const ResolvedUpdateItem>>&
                                                               update_item_list) {
    return "";
  }

  std::string SQLBuilder::GetInsertColumnListSQL(const std::vector<ResolvedColumn>& insert_column_list) const {
    return "";
  }

  absl::Status SQLBuilder::AddValueTableAliasForVisitResolvedTableScan(absl::string_view table_alias, const ResolvedColumn& column,
                                                                       std::vector<std::pair<std::string, std::string>>* select_list) {
    return absl::OkStatus();
  }

  std::string SQLBuilder::TableToIdentifierLiteral(const Table* table) {
    return "";
  }

  std::string SQLBuilder::TableNameToIdentifierLiteral(absl::string_view table_name) {
    return "";
  }

  std::string SQLBuilder::GetTableAliasForVisitResolvedTableScan(const ResolvedTableScan& node, std::string* from) {
    return "";
  }

  std::string SQLBuilder::GenerateUniqueAliasName() {
    return "";
  }

  absl::Status SQLBuilder::VisitResolvedRecursiveScan(const ResolvedRecursiveScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedRecursiveRefScan(const ResolvedRecursiveRefScan* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedCreateEntityStmt(const ResolvedCreateEntityStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAlterEntityStmt(const ResolvedAlterEntityStmt* node) {
    return absl::OkStatus();
  }

  absl::Status SQLBuilder::VisitResolvedAuxLoadDataStmt(const ResolvedAuxLoadDataStmt* node) {
    return absl::OkStatus();
  }

}
#endif

#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast_enums_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/rewrite_utils/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/public/analyzer/export.inc"
#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/constant/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-zetasql/public/functions/datetime_cc_proto/export.inc"
#include "go-zetasql/public/functions/normalize_mode_cc_proto/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/cleanup/cleanup/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
