#ifndef ZETASQL_RESOLVED_AST_COMPARATOR_EXPORT_H
#define ZETASQL_RESOLVED_AST_COMPARATOR_EXPORT_H

#include "zetasql/resolved_ast/resolved_ast_comparator.h"
#include "zetasql/resolved_ast/resolved_ast_comparator.cc"

#if 0
namespace zetasql {

  absl::Status* ResolvedASTComparator::stack_overflow_status_ = nullptr;

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAST(const ResolvedNode* node1, const ResolvedNode* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedLiteral(const ResolvedLiteral* node1, const ResolvedLiteral* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedParameter(const ResolvedParameter* node1, const ResolvedParameter* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExpressionColumn(const ResolvedExpressionColumn* node1, const ResolvedExpressionColumn* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedColumnRef(const ResolvedColumnRef* node1, const ResolvedColumnRef* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedConstant(const ResolvedConstant* node1, const ResolvedConstant* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSystemVariable(const ResolvedSystemVariable* node1, const ResolvedSystemVariable* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedInlineLambda(const ResolvedInlineLambda* node1, const ResolvedInlineLambda* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFilterFieldArg(const ResolvedFilterFieldArg* node1, const ResolvedFilterFieldArg* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFilterField(const ResolvedFilterField* node1, const ResolvedFilterField* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFunctionCall(const ResolvedFunctionCall* node1, const ResolvedFunctionCall* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAggregateFunctionCall(const ResolvedAggregateFunctionCall* node1, const ResolvedAggregateFunctionCall* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAnalyticFunctionCall(const ResolvedAnalyticFunctionCall* node1, const ResolvedAnalyticFunctionCall* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExtendedCastElement(const ResolvedExtendedCastElement* node1, const ResolvedExtendedCastElement* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExtendedCast(const ResolvedExtendedCast* node1, const ResolvedExtendedCast* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCast(const ResolvedCast* node1, const ResolvedCast* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedMakeStruct(const ResolvedMakeStruct* node1, const ResolvedMakeStruct* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedMakeProto(const ResolvedMakeProto* node1, const ResolvedMakeProto* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedMakeProtoField(const ResolvedMakeProtoField* node1, const ResolvedMakeProtoField* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGetStructField(const ResolvedGetStructField* node1, const ResolvedGetStructField* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGetProtoField(const ResolvedGetProtoField* node1, const ResolvedGetProtoField* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGetJsonField(const ResolvedGetJsonField* node1, const ResolvedGetJsonField* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFlatten(const ResolvedFlatten* node1, const ResolvedFlatten* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFlattenedArg(const ResolvedFlattenedArg* node1, const ResolvedFlattenedArg* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedReplaceFieldItem(const ResolvedReplaceFieldItem* node1, const ResolvedReplaceFieldItem* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedReplaceField(const ResolvedReplaceField* node1, const ResolvedReplaceField* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSubqueryExpr(const ResolvedSubqueryExpr* node1, const ResolvedSubqueryExpr* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedLetExpr(const ResolvedLetExpr* node1, const ResolvedLetExpr* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedModel(const ResolvedModel* node1, const ResolvedModel* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedConnection(const ResolvedConnection* node1, const ResolvedConnection* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDescriptor(const ResolvedDescriptor* node1, const ResolvedDescriptor* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSingleRowScan(const ResolvedSingleRowScan* node1, const ResolvedSingleRowScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedTableScan(const ResolvedTableScan* node1, const ResolvedTableScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedJoinScan(const ResolvedJoinScan* node1, const ResolvedJoinScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedArrayScan(const ResolvedArrayScan* node1, const ResolvedArrayScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedColumnHolder(const ResolvedColumnHolder* node1, const ResolvedColumnHolder* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFilterScan(const ResolvedFilterScan* node1, const ResolvedFilterScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGroupingSet(const ResolvedGroupingSet* node1, const ResolvedGroupingSet* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAggregateScan(const ResolvedAggregateScan* node1, const ResolvedAggregateScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAnonymizedAggregateScan(const ResolvedAnonymizedAggregateScan* node1, const ResolvedAnonymizedAggregateScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSetOperationItem(const ResolvedSetOperationItem* node1, const ResolvedSetOperationItem* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSetOperationScan(const ResolvedSetOperationScan* node1, const ResolvedSetOperationScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedOrderByScan(const ResolvedOrderByScan* node1, const ResolvedOrderByScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedLimitOffsetScan(const ResolvedLimitOffsetScan* node1, const ResolvedLimitOffsetScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWithRefScan(const ResolvedWithRefScan* node1, const ResolvedWithRefScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAnalyticScan(const ResolvedAnalyticScan* node1, const ResolvedAnalyticScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSampleScan(const ResolvedSampleScan* node1, const ResolvedSampleScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedComputedColumn(const ResolvedComputedColumn* node1, const ResolvedComputedColumn* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedOrderByItem(const ResolvedOrderByItem* node1, const ResolvedOrderByItem* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedColumnAnnotations(const ResolvedColumnAnnotations* node1, const ResolvedColumnAnnotations* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGeneratedColumnInfo(const ResolvedGeneratedColumnInfo* node1, const ResolvedGeneratedColumnInfo* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedColumnDefaultValue(const ResolvedColumnDefaultValue* node1, const ResolvedColumnDefaultValue* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedColumnDefinition(const ResolvedColumnDefinition* node1, const ResolvedColumnDefinition* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedPrimaryKey(const ResolvedPrimaryKey* node1, const ResolvedPrimaryKey* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedForeignKey(const ResolvedForeignKey* node1, const ResolvedForeignKey* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCheckConstraint(const ResolvedCheckConstraint* node1, const ResolvedCheckConstraint* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedOutputColumn(const ResolvedOutputColumn* node1, const ResolvedOutputColumn* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedProjectScan(const ResolvedProjectScan* node1, const ResolvedProjectScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedTVFScan(const ResolvedTVFScan* node1, const ResolvedTVFScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGroupRowsScan(const ResolvedGroupRowsScan* node1, const ResolvedGroupRowsScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFunctionArgument(const ResolvedFunctionArgument* node1, const ResolvedFunctionArgument* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExplainStmt(const ResolvedExplainStmt* node1, const ResolvedExplainStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedQueryStmt(const ResolvedQueryStmt* node1, const ResolvedQueryStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateDatabaseStmt(const ResolvedCreateDatabaseStmt* node1, const ResolvedCreateDatabaseStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedIndexItem(const ResolvedIndexItem* node1, const ResolvedIndexItem* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedUnnestItem(const ResolvedUnnestItem* node1, const ResolvedUnnestItem* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateIndexStmt(const ResolvedCreateIndexStmt* node1, const ResolvedCreateIndexStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateSchemaStmt(const ResolvedCreateSchemaStmt* node1, const ResolvedCreateSchemaStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateTableStmt(const ResolvedCreateTableStmt* node1, const ResolvedCreateTableStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateTableAsSelectStmt(const ResolvedCreateTableAsSelectStmt* node1, const ResolvedCreateTableAsSelectStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateModelStmt(const ResolvedCreateModelStmt* node1, const ResolvedCreateModelStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateViewStmt(const ResolvedCreateViewStmt* node1, const ResolvedCreateViewStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWithPartitionColumns(const ResolvedWithPartitionColumns* node1, const ResolvedWithPartitionColumns* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateSnapshotTableStmt(const ResolvedCreateSnapshotTableStmt* node1, const ResolvedCreateSnapshotTableStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateExternalTableStmt(const ResolvedCreateExternalTableStmt* node1, const ResolvedCreateExternalTableStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExportModelStmt(const ResolvedExportModelStmt* node1, const ResolvedExportModelStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExportDataStmt(const ResolvedExportDataStmt* node1, const ResolvedExportDataStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDefineTableStmt(const ResolvedDefineTableStmt* node1, const ResolvedDefineTableStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDescribeStmt(const ResolvedDescribeStmt* node1, const ResolvedDescribeStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedShowStmt(const ResolvedShowStmt* node1, const ResolvedShowStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedBeginStmt(const ResolvedBeginStmt* node1, const ResolvedBeginStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSetTransactionStmt(const ResolvedSetTransactionStmt* node1, const ResolvedSetTransactionStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCommitStmt(const ResolvedCommitStmt* node1, const ResolvedCommitStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRollbackStmt(const ResolvedRollbackStmt* node1, const ResolvedRollbackStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedStartBatchStmt(const ResolvedStartBatchStmt* node1, const ResolvedStartBatchStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRunBatchStmt(const ResolvedRunBatchStmt* node1, const ResolvedRunBatchStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAbortBatchStmt(const ResolvedAbortBatchStmt* node1, const ResolvedAbortBatchStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropStmt(const ResolvedDropStmt* node1, const ResolvedDropStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropMaterializedViewStmt(const ResolvedDropMaterializedViewStmt* node1, const ResolvedDropMaterializedViewStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropSnapshotTableStmt(const ResolvedDropSnapshotTableStmt* node1, const ResolvedDropSnapshotTableStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRecursiveRefScan(const ResolvedRecursiveRefScan* node1, const ResolvedRecursiveRefScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRecursiveScan(const ResolvedRecursiveScan* node1, const ResolvedRecursiveScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWithScan(const ResolvedWithScan* node1, const ResolvedWithScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWithEntry(const ResolvedWithEntry* node1, const ResolvedWithEntry* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedOption(const ResolvedOption* node1, const ResolvedOption* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWindowPartitioning(const ResolvedWindowPartitioning* node1, const ResolvedWindowPartitioning* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWindowOrdering(const ResolvedWindowOrdering* node1, const ResolvedWindowOrdering* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWindowFrame(const ResolvedWindowFrame* node1, const ResolvedWindowFrame* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAnalyticFunctionGroup(const ResolvedAnalyticFunctionGroup* node1, const ResolvedAnalyticFunctionGroup* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWindowFrameExpr(const ResolvedWindowFrameExpr* node1, const ResolvedWindowFrameExpr* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDMLValue(const ResolvedDMLValue* node1, const ResolvedDMLValue* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDMLDefault(const ResolvedDMLDefault* node1, const ResolvedDMLDefault* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAssertStmt(const ResolvedAssertStmt* node1, const ResolvedAssertStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAssertRowsModified(const ResolvedAssertRowsModified* node1, const ResolvedAssertRowsModified* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedInsertRow(const ResolvedInsertRow* node1, const ResolvedInsertRow* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedInsertStmt(const ResolvedInsertStmt* node1, const ResolvedInsertStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDeleteStmt(const ResolvedDeleteStmt* node1, const ResolvedDeleteStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedUpdateItem(const ResolvedUpdateItem* node1, const ResolvedUpdateItem* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedUpdateArrayItem(const ResolvedUpdateArrayItem* node1, const ResolvedUpdateArrayItem* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedUpdateStmt(const ResolvedUpdateStmt* node1, const ResolvedUpdateStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedMergeWhen(const ResolvedMergeWhen* node1, const ResolvedMergeWhen* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedMergeStmt(const ResolvedMergeStmt* node1, const ResolvedMergeStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedTruncateStmt(const ResolvedTruncateStmt* node1, const ResolvedTruncateStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedObjectUnit(const ResolvedObjectUnit* node1, const ResolvedObjectUnit* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedPrivilege(const ResolvedPrivilege* node1, const ResolvedPrivilege* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGrantStmt(const ResolvedGrantStmt* node1, const ResolvedGrantStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRevokeStmt(const ResolvedRevokeStmt* node1, const ResolvedRevokeStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterDatabaseStmt(const ResolvedAlterDatabaseStmt* node1, const ResolvedAlterDatabaseStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterMaterializedViewStmt(const ResolvedAlterMaterializedViewStmt* node1, const ResolvedAlterMaterializedViewStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterSchemaStmt(const ResolvedAlterSchemaStmt* node1, const ResolvedAlterSchemaStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterTableStmt(const ResolvedAlterTableStmt* node1, const ResolvedAlterTableStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterViewStmt(const ResolvedAlterViewStmt* node1, const ResolvedAlterViewStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSetOptionsAction(const ResolvedSetOptionsAction* node1, const ResolvedSetOptionsAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAddColumnAction(const ResolvedAddColumnAction* node1, const ResolvedAddColumnAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAddConstraintAction(const ResolvedAddConstraintAction* node1, const ResolvedAddConstraintAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropConstraintAction(const ResolvedDropConstraintAction* node1, const ResolvedDropConstraintAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropPrimaryKeyAction(const ResolvedDropPrimaryKeyAction* node1, const ResolvedDropPrimaryKeyAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterColumnOptionsAction(const ResolvedAlterColumnOptionsAction* node1, const ResolvedAlterColumnOptionsAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterColumnDropNotNullAction(const ResolvedAlterColumnDropNotNullAction* node1, const ResolvedAlterColumnDropNotNullAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterColumnSetDataTypeAction(const ResolvedAlterColumnSetDataTypeAction* node1, const ResolvedAlterColumnSetDataTypeAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterColumnSetDefaultAction(const ResolvedAlterColumnSetDefaultAction* node1, const ResolvedAlterColumnSetDefaultAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterColumnDropDefaultAction(const ResolvedAlterColumnDropDefaultAction* node1, const ResolvedAlterColumnDropDefaultAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropColumnAction(const ResolvedDropColumnAction* node1, const ResolvedDropColumnAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRenameColumnAction(const ResolvedRenameColumnAction* node1, const ResolvedRenameColumnAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSetAsAction(const ResolvedSetAsAction* node1, const ResolvedSetAsAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSetCollateClause(const ResolvedSetCollateClause* node1, const ResolvedSetCollateClause* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterTableSetOptionsStmt(const ResolvedAlterTableSetOptionsStmt* node1, const ResolvedAlterTableSetOptionsStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRenameStmt(const ResolvedRenameStmt* node1, const ResolvedRenameStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreatePrivilegeRestrictionStmt(const ResolvedCreatePrivilegeRestrictionStmt* node1, const ResolvedCreatePrivilegeRestrictionStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateRowAccessPolicyStmt(const ResolvedCreateRowAccessPolicyStmt* node1, const ResolvedCreateRowAccessPolicyStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropPrivilegeRestrictionStmt(const ResolvedDropPrivilegeRestrictionStmt* node1, const ResolvedDropPrivilegeRestrictionStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropRowAccessPolicyStmt(const ResolvedDropRowAccessPolicyStmt* node1, const ResolvedDropRowAccessPolicyStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropSearchIndexStmt(const ResolvedDropSearchIndexStmt* node1, const ResolvedDropSearchIndexStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGrantToAction(const ResolvedGrantToAction* node1, const ResolvedGrantToAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRestrictToAction(const ResolvedRestrictToAction* node1, const ResolvedRestrictToAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAddToRestricteeListAction(const ResolvedAddToRestricteeListAction* node1, const ResolvedAddToRestricteeListAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRemoveFromRestricteeListAction(const ResolvedRemoveFromRestricteeListAction* node1, const ResolvedRemoveFromRestricteeListAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFilterUsingAction(const ResolvedFilterUsingAction* node1, const ResolvedFilterUsingAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRevokeFromAction(const ResolvedRevokeFromAction* node1, const ResolvedRevokeFromAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRenameToAction(const ResolvedRenameToAction* node1, const ResolvedRenameToAction* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterPrivilegeRestrictionStmt(const ResolvedAlterPrivilegeRestrictionStmt* node1, const ResolvedAlterPrivilegeRestrictionStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterRowAccessPolicyStmt(const ResolvedAlterRowAccessPolicyStmt* node1, const ResolvedAlterRowAccessPolicyStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterAllRowAccessPoliciesStmt(const ResolvedAlterAllRowAccessPoliciesStmt* node1, const ResolvedAlterAllRowAccessPoliciesStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateConstantStmt(const ResolvedCreateConstantStmt* node1, const ResolvedCreateConstantStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateFunctionStmt(const ResolvedCreateFunctionStmt* node1, const ResolvedCreateFunctionStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedArgumentDef(const ResolvedArgumentDef* node1, const ResolvedArgumentDef* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedArgumentRef(const ResolvedArgumentRef* node1, const ResolvedArgumentRef* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateTableFunctionStmt(const ResolvedCreateTableFunctionStmt* node1, const ResolvedCreateTableFunctionStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRelationArgumentScan(const ResolvedRelationArgumentScan* node1, const ResolvedRelationArgumentScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedArgumentList(const ResolvedArgumentList* node1, const ResolvedArgumentList* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFunctionSignatureHolder(const ResolvedFunctionSignatureHolder* node1, const ResolvedFunctionSignatureHolder* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropFunctionStmt(const ResolvedDropFunctionStmt* node1, const ResolvedDropFunctionStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropTableFunctionStmt(const ResolvedDropTableFunctionStmt* node1, const ResolvedDropTableFunctionStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCallStmt(const ResolvedCallStmt* node1, const ResolvedCallStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedImportStmt(const ResolvedImportStmt* node1, const ResolvedImportStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedModuleStmt(const ResolvedModuleStmt* node1, const ResolvedModuleStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAggregateHavingModifier(const ResolvedAggregateHavingModifier* node1, const ResolvedAggregateHavingModifier* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateMaterializedViewStmt(const ResolvedCreateMaterializedViewStmt* node1, const ResolvedCreateMaterializedViewStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateProcedureStmt(const ResolvedCreateProcedureStmt* node1, const ResolvedCreateProcedureStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExecuteImmediateArgument(const ResolvedExecuteImmediateArgument* node1, const ResolvedExecuteImmediateArgument* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExecuteImmediateStmt(const ResolvedExecuteImmediateStmt* node1, const ResolvedExecuteImmediateStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAssignmentStmt(const ResolvedAssignmentStmt* node1, const ResolvedAssignmentStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateEntityStmt(const ResolvedCreateEntityStmt* node1, const ResolvedCreateEntityStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterEntityStmt(const ResolvedAlterEntityStmt* node1, const ResolvedAlterEntityStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedPivotColumn(const ResolvedPivotColumn* node1, const ResolvedPivotColumn* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedPivotScan(const ResolvedPivotScan* node1, const ResolvedPivotScan* node2) {return false;
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedReturningClause(const ResolvedReturningClause* node1, const ResolvedReturningClause* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedUnpivotArg(const ResolvedUnpivotArg* node1, const ResolvedUnpivotArg* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedUnpivotScan(const ResolvedUnpivotScan* node1, const ResolvedUnpivotScan* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCloneDataStmt(const ResolvedCloneDataStmt* node1, const ResolvedCloneDataStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedTableAndColumnInfo(const ResolvedTableAndColumnInfo* node1, const ResolvedTableAndColumnInfo* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAnalyzeStmt(const ResolvedAnalyzeStmt* node1, const ResolvedAnalyzeStmt* node2) {
    return false;
  }

  absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAuxLoadDataStmt(const ResolvedAuxLoadDataStmt* node1, const ResolvedAuxLoadDataStmt* node2) {
    return false;
  }

}
#endif

#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/case/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
