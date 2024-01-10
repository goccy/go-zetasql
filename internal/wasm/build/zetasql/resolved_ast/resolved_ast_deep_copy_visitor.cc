//
// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// resolved_ast_deep_copy_visitor.cc GENERATED FROM resolved_ast_deep_copy_visitor.cc.template
#include "zetasql/resolved_ast/resolved_ast_deep_copy_visitor.h"

#include <string>

#include "absl/memory/memory.h"

namespace zetasql {

// Default visit for the AST. This will throw an error, because we want to
// ensure that the entire AST is copied.
absl::Status ResolvedASTDeepCopyVisitor::DefaultVisit(
    const ResolvedNode* node) {
  return ::zetasql_base::InvalidArgumentErrorBuilder(ZETASQL_LOC)
         << "Unhandled node type in deep copy:\n"
         << node->DebugString();
}

// The individual visit methods for each of the node types. We will always
// return CopyVisitX, where X is the node kind. This will deep copy the tree
// recursively.
absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedLiteral(
    const ResolvedLiteral* node) {
  return CopyVisitResolvedLiteral(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedParameter(
    const ResolvedParameter* node) {
  return CopyVisitResolvedParameter(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExpressionColumn(
    const ResolvedExpressionColumn* node) {
  return CopyVisitResolvedExpressionColumn(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedColumnRef(
    const ResolvedColumnRef* node) {
  return CopyVisitResolvedColumnRef(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedConstant(
    const ResolvedConstant* node) {
  return CopyVisitResolvedConstant(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSystemVariable(
    const ResolvedSystemVariable* node) {
  return CopyVisitResolvedSystemVariable(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedInlineLambda(
    const ResolvedInlineLambda* node) {
  return CopyVisitResolvedInlineLambda(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFilterFieldArg(
    const ResolvedFilterFieldArg* node) {
  return CopyVisitResolvedFilterFieldArg(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFilterField(
    const ResolvedFilterField* node) {
  return CopyVisitResolvedFilterField(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFunctionCall(
    const ResolvedFunctionCall* node) {
  return CopyVisitResolvedFunctionCall(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAggregateFunctionCall(
    const ResolvedAggregateFunctionCall* node) {
  return CopyVisitResolvedAggregateFunctionCall(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAnalyticFunctionCall(
    const ResolvedAnalyticFunctionCall* node) {
  return CopyVisitResolvedAnalyticFunctionCall(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExtendedCastElement(
    const ResolvedExtendedCastElement* node) {
  return CopyVisitResolvedExtendedCastElement(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExtendedCast(
    const ResolvedExtendedCast* node) {
  return CopyVisitResolvedExtendedCast(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCast(
    const ResolvedCast* node) {
  return CopyVisitResolvedCast(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedMakeStruct(
    const ResolvedMakeStruct* node) {
  return CopyVisitResolvedMakeStruct(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedMakeProto(
    const ResolvedMakeProto* node) {
  return CopyVisitResolvedMakeProto(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedMakeProtoField(
    const ResolvedMakeProtoField* node) {
  return CopyVisitResolvedMakeProtoField(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGetStructField(
    const ResolvedGetStructField* node) {
  return CopyVisitResolvedGetStructField(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGetProtoField(
    const ResolvedGetProtoField* node) {
  return CopyVisitResolvedGetProtoField(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGetJsonField(
    const ResolvedGetJsonField* node) {
  return CopyVisitResolvedGetJsonField(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFlatten(
    const ResolvedFlatten* node) {
  return CopyVisitResolvedFlatten(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFlattenedArg(
    const ResolvedFlattenedArg* node) {
  return CopyVisitResolvedFlattenedArg(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedReplaceFieldItem(
    const ResolvedReplaceFieldItem* node) {
  return CopyVisitResolvedReplaceFieldItem(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedReplaceField(
    const ResolvedReplaceField* node) {
  return CopyVisitResolvedReplaceField(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSubqueryExpr(
    const ResolvedSubqueryExpr* node) {
  return CopyVisitResolvedSubqueryExpr(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedLetExpr(
    const ResolvedLetExpr* node) {
  return CopyVisitResolvedLetExpr(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedModel(
    const ResolvedModel* node) {
  return CopyVisitResolvedModel(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedConnection(
    const ResolvedConnection* node) {
  return CopyVisitResolvedConnection(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDescriptor(
    const ResolvedDescriptor* node) {
  return CopyVisitResolvedDescriptor(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSingleRowScan(
    const ResolvedSingleRowScan* node) {
  return CopyVisitResolvedSingleRowScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedTableScan(
    const ResolvedTableScan* node) {
  return CopyVisitResolvedTableScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedJoinScan(
    const ResolvedJoinScan* node) {
  return CopyVisitResolvedJoinScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedArrayScan(
    const ResolvedArrayScan* node) {
  return CopyVisitResolvedArrayScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedColumnHolder(
    const ResolvedColumnHolder* node) {
  return CopyVisitResolvedColumnHolder(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFilterScan(
    const ResolvedFilterScan* node) {
  return CopyVisitResolvedFilterScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGroupingSet(
    const ResolvedGroupingSet* node) {
  return CopyVisitResolvedGroupingSet(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAggregateScan(
    const ResolvedAggregateScan* node) {
  return CopyVisitResolvedAggregateScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAnonymizedAggregateScan(
    const ResolvedAnonymizedAggregateScan* node) {
  return CopyVisitResolvedAnonymizedAggregateScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSetOperationItem(
    const ResolvedSetOperationItem* node) {
  return CopyVisitResolvedSetOperationItem(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSetOperationScan(
    const ResolvedSetOperationScan* node) {
  return CopyVisitResolvedSetOperationScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedOrderByScan(
    const ResolvedOrderByScan* node) {
  return CopyVisitResolvedOrderByScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedLimitOffsetScan(
    const ResolvedLimitOffsetScan* node) {
  return CopyVisitResolvedLimitOffsetScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWithRefScan(
    const ResolvedWithRefScan* node) {
  return CopyVisitResolvedWithRefScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAnalyticScan(
    const ResolvedAnalyticScan* node) {
  return CopyVisitResolvedAnalyticScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSampleScan(
    const ResolvedSampleScan* node) {
  return CopyVisitResolvedSampleScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedComputedColumn(
    const ResolvedComputedColumn* node) {
  return CopyVisitResolvedComputedColumn(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedOrderByItem(
    const ResolvedOrderByItem* node) {
  return CopyVisitResolvedOrderByItem(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedColumnAnnotations(
    const ResolvedColumnAnnotations* node) {
  return CopyVisitResolvedColumnAnnotations(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGeneratedColumnInfo(
    const ResolvedGeneratedColumnInfo* node) {
  return CopyVisitResolvedGeneratedColumnInfo(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedColumnDefaultValue(
    const ResolvedColumnDefaultValue* node) {
  return CopyVisitResolvedColumnDefaultValue(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedColumnDefinition(
    const ResolvedColumnDefinition* node) {
  return CopyVisitResolvedColumnDefinition(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedPrimaryKey(
    const ResolvedPrimaryKey* node) {
  return CopyVisitResolvedPrimaryKey(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedForeignKey(
    const ResolvedForeignKey* node) {
  return CopyVisitResolvedForeignKey(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCheckConstraint(
    const ResolvedCheckConstraint* node) {
  return CopyVisitResolvedCheckConstraint(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedOutputColumn(
    const ResolvedOutputColumn* node) {
  return CopyVisitResolvedOutputColumn(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedProjectScan(
    const ResolvedProjectScan* node) {
  return CopyVisitResolvedProjectScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedTVFScan(
    const ResolvedTVFScan* node) {
  return CopyVisitResolvedTVFScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGroupRowsScan(
    const ResolvedGroupRowsScan* node) {
  return CopyVisitResolvedGroupRowsScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFunctionArgument(
    const ResolvedFunctionArgument* node) {
  return CopyVisitResolvedFunctionArgument(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExplainStmt(
    const ResolvedExplainStmt* node) {
  return CopyVisitResolvedExplainStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedQueryStmt(
    const ResolvedQueryStmt* node) {
  return CopyVisitResolvedQueryStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateDatabaseStmt(
    const ResolvedCreateDatabaseStmt* node) {
  return CopyVisitResolvedCreateDatabaseStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedIndexItem(
    const ResolvedIndexItem* node) {
  return CopyVisitResolvedIndexItem(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedUnnestItem(
    const ResolvedUnnestItem* node) {
  return CopyVisitResolvedUnnestItem(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateIndexStmt(
    const ResolvedCreateIndexStmt* node) {
  return CopyVisitResolvedCreateIndexStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateSchemaStmt(
    const ResolvedCreateSchemaStmt* node) {
  return CopyVisitResolvedCreateSchemaStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateTableStmt(
    const ResolvedCreateTableStmt* node) {
  return CopyVisitResolvedCreateTableStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateTableAsSelectStmt(
    const ResolvedCreateTableAsSelectStmt* node) {
  return CopyVisitResolvedCreateTableAsSelectStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateModelStmt(
    const ResolvedCreateModelStmt* node) {
  return CopyVisitResolvedCreateModelStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateViewStmt(
    const ResolvedCreateViewStmt* node) {
  return CopyVisitResolvedCreateViewStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWithPartitionColumns(
    const ResolvedWithPartitionColumns* node) {
  return CopyVisitResolvedWithPartitionColumns(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateSnapshotTableStmt(
    const ResolvedCreateSnapshotTableStmt* node) {
  return CopyVisitResolvedCreateSnapshotTableStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateExternalTableStmt(
    const ResolvedCreateExternalTableStmt* node) {
  return CopyVisitResolvedCreateExternalTableStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExportModelStmt(
    const ResolvedExportModelStmt* node) {
  return CopyVisitResolvedExportModelStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExportDataStmt(
    const ResolvedExportDataStmt* node) {
  return CopyVisitResolvedExportDataStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDefineTableStmt(
    const ResolvedDefineTableStmt* node) {
  return CopyVisitResolvedDefineTableStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDescribeStmt(
    const ResolvedDescribeStmt* node) {
  return CopyVisitResolvedDescribeStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedShowStmt(
    const ResolvedShowStmt* node) {
  return CopyVisitResolvedShowStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedBeginStmt(
    const ResolvedBeginStmt* node) {
  return CopyVisitResolvedBeginStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSetTransactionStmt(
    const ResolvedSetTransactionStmt* node) {
  return CopyVisitResolvedSetTransactionStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCommitStmt(
    const ResolvedCommitStmt* node) {
  return CopyVisitResolvedCommitStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRollbackStmt(
    const ResolvedRollbackStmt* node) {
  return CopyVisitResolvedRollbackStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedStartBatchStmt(
    const ResolvedStartBatchStmt* node) {
  return CopyVisitResolvedStartBatchStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRunBatchStmt(
    const ResolvedRunBatchStmt* node) {
  return CopyVisitResolvedRunBatchStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAbortBatchStmt(
    const ResolvedAbortBatchStmt* node) {
  return CopyVisitResolvedAbortBatchStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropStmt(
    const ResolvedDropStmt* node) {
  return CopyVisitResolvedDropStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropMaterializedViewStmt(
    const ResolvedDropMaterializedViewStmt* node) {
  return CopyVisitResolvedDropMaterializedViewStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropSnapshotTableStmt(
    const ResolvedDropSnapshotTableStmt* node) {
  return CopyVisitResolvedDropSnapshotTableStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRecursiveRefScan(
    const ResolvedRecursiveRefScan* node) {
  return CopyVisitResolvedRecursiveRefScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRecursiveScan(
    const ResolvedRecursiveScan* node) {
  return CopyVisitResolvedRecursiveScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWithScan(
    const ResolvedWithScan* node) {
  return CopyVisitResolvedWithScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWithEntry(
    const ResolvedWithEntry* node) {
  return CopyVisitResolvedWithEntry(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedOption(
    const ResolvedOption* node) {
  return CopyVisitResolvedOption(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWindowPartitioning(
    const ResolvedWindowPartitioning* node) {
  return CopyVisitResolvedWindowPartitioning(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWindowOrdering(
    const ResolvedWindowOrdering* node) {
  return CopyVisitResolvedWindowOrdering(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWindowFrame(
    const ResolvedWindowFrame* node) {
  return CopyVisitResolvedWindowFrame(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAnalyticFunctionGroup(
    const ResolvedAnalyticFunctionGroup* node) {
  return CopyVisitResolvedAnalyticFunctionGroup(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWindowFrameExpr(
    const ResolvedWindowFrameExpr* node) {
  return CopyVisitResolvedWindowFrameExpr(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDMLValue(
    const ResolvedDMLValue* node) {
  return CopyVisitResolvedDMLValue(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDMLDefault(
    const ResolvedDMLDefault* node) {
  return CopyVisitResolvedDMLDefault(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAssertStmt(
    const ResolvedAssertStmt* node) {
  return CopyVisitResolvedAssertStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAssertRowsModified(
    const ResolvedAssertRowsModified* node) {
  return CopyVisitResolvedAssertRowsModified(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedInsertRow(
    const ResolvedInsertRow* node) {
  return CopyVisitResolvedInsertRow(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedInsertStmt(
    const ResolvedInsertStmt* node) {
  return CopyVisitResolvedInsertStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDeleteStmt(
    const ResolvedDeleteStmt* node) {
  return CopyVisitResolvedDeleteStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedUpdateItem(
    const ResolvedUpdateItem* node) {
  return CopyVisitResolvedUpdateItem(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedUpdateArrayItem(
    const ResolvedUpdateArrayItem* node) {
  return CopyVisitResolvedUpdateArrayItem(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedUpdateStmt(
    const ResolvedUpdateStmt* node) {
  return CopyVisitResolvedUpdateStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedMergeWhen(
    const ResolvedMergeWhen* node) {
  return CopyVisitResolvedMergeWhen(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedMergeStmt(
    const ResolvedMergeStmt* node) {
  return CopyVisitResolvedMergeStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedTruncateStmt(
    const ResolvedTruncateStmt* node) {
  return CopyVisitResolvedTruncateStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedObjectUnit(
    const ResolvedObjectUnit* node) {
  return CopyVisitResolvedObjectUnit(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedPrivilege(
    const ResolvedPrivilege* node) {
  return CopyVisitResolvedPrivilege(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGrantStmt(
    const ResolvedGrantStmt* node) {
  return CopyVisitResolvedGrantStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRevokeStmt(
    const ResolvedRevokeStmt* node) {
  return CopyVisitResolvedRevokeStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterDatabaseStmt(
    const ResolvedAlterDatabaseStmt* node) {
  return CopyVisitResolvedAlterDatabaseStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterMaterializedViewStmt(
    const ResolvedAlterMaterializedViewStmt* node) {
  return CopyVisitResolvedAlterMaterializedViewStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterSchemaStmt(
    const ResolvedAlterSchemaStmt* node) {
  return CopyVisitResolvedAlterSchemaStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterTableStmt(
    const ResolvedAlterTableStmt* node) {
  return CopyVisitResolvedAlterTableStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterViewStmt(
    const ResolvedAlterViewStmt* node) {
  return CopyVisitResolvedAlterViewStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSetOptionsAction(
    const ResolvedSetOptionsAction* node) {
  return CopyVisitResolvedSetOptionsAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAddColumnAction(
    const ResolvedAddColumnAction* node) {
  return CopyVisitResolvedAddColumnAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAddConstraintAction(
    const ResolvedAddConstraintAction* node) {
  return CopyVisitResolvedAddConstraintAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropConstraintAction(
    const ResolvedDropConstraintAction* node) {
  return CopyVisitResolvedDropConstraintAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropPrimaryKeyAction(
    const ResolvedDropPrimaryKeyAction* node) {
  return CopyVisitResolvedDropPrimaryKeyAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterColumnOptionsAction(
    const ResolvedAlterColumnOptionsAction* node) {
  return CopyVisitResolvedAlterColumnOptionsAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterColumnDropNotNullAction(
    const ResolvedAlterColumnDropNotNullAction* node) {
  return CopyVisitResolvedAlterColumnDropNotNullAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterColumnSetDataTypeAction(
    const ResolvedAlterColumnSetDataTypeAction* node) {
  return CopyVisitResolvedAlterColumnSetDataTypeAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterColumnSetDefaultAction(
    const ResolvedAlterColumnSetDefaultAction* node) {
  return CopyVisitResolvedAlterColumnSetDefaultAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterColumnDropDefaultAction(
    const ResolvedAlterColumnDropDefaultAction* node) {
  return CopyVisitResolvedAlterColumnDropDefaultAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropColumnAction(
    const ResolvedDropColumnAction* node) {
  return CopyVisitResolvedDropColumnAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRenameColumnAction(
    const ResolvedRenameColumnAction* node) {
  return CopyVisitResolvedRenameColumnAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSetAsAction(
    const ResolvedSetAsAction* node) {
  return CopyVisitResolvedSetAsAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSetCollateClause(
    const ResolvedSetCollateClause* node) {
  return CopyVisitResolvedSetCollateClause(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterTableSetOptionsStmt(
    const ResolvedAlterTableSetOptionsStmt* node) {
  return CopyVisitResolvedAlterTableSetOptionsStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRenameStmt(
    const ResolvedRenameStmt* node) {
  return CopyVisitResolvedRenameStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreatePrivilegeRestrictionStmt(
    const ResolvedCreatePrivilegeRestrictionStmt* node) {
  return CopyVisitResolvedCreatePrivilegeRestrictionStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateRowAccessPolicyStmt(
    const ResolvedCreateRowAccessPolicyStmt* node) {
  return CopyVisitResolvedCreateRowAccessPolicyStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropPrivilegeRestrictionStmt(
    const ResolvedDropPrivilegeRestrictionStmt* node) {
  return CopyVisitResolvedDropPrivilegeRestrictionStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropRowAccessPolicyStmt(
    const ResolvedDropRowAccessPolicyStmt* node) {
  return CopyVisitResolvedDropRowAccessPolicyStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropSearchIndexStmt(
    const ResolvedDropSearchIndexStmt* node) {
  return CopyVisitResolvedDropSearchIndexStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGrantToAction(
    const ResolvedGrantToAction* node) {
  return CopyVisitResolvedGrantToAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRestrictToAction(
    const ResolvedRestrictToAction* node) {
  return CopyVisitResolvedRestrictToAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAddToRestricteeListAction(
    const ResolvedAddToRestricteeListAction* node) {
  return CopyVisitResolvedAddToRestricteeListAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRemoveFromRestricteeListAction(
    const ResolvedRemoveFromRestricteeListAction* node) {
  return CopyVisitResolvedRemoveFromRestricteeListAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFilterUsingAction(
    const ResolvedFilterUsingAction* node) {
  return CopyVisitResolvedFilterUsingAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRevokeFromAction(
    const ResolvedRevokeFromAction* node) {
  return CopyVisitResolvedRevokeFromAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRenameToAction(
    const ResolvedRenameToAction* node) {
  return CopyVisitResolvedRenameToAction(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterPrivilegeRestrictionStmt(
    const ResolvedAlterPrivilegeRestrictionStmt* node) {
  return CopyVisitResolvedAlterPrivilegeRestrictionStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterRowAccessPolicyStmt(
    const ResolvedAlterRowAccessPolicyStmt* node) {
  return CopyVisitResolvedAlterRowAccessPolicyStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterAllRowAccessPoliciesStmt(
    const ResolvedAlterAllRowAccessPoliciesStmt* node) {
  return CopyVisitResolvedAlterAllRowAccessPoliciesStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateConstantStmt(
    const ResolvedCreateConstantStmt* node) {
  return CopyVisitResolvedCreateConstantStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateFunctionStmt(
    const ResolvedCreateFunctionStmt* node) {
  return CopyVisitResolvedCreateFunctionStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedArgumentDef(
    const ResolvedArgumentDef* node) {
  return CopyVisitResolvedArgumentDef(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedArgumentRef(
    const ResolvedArgumentRef* node) {
  return CopyVisitResolvedArgumentRef(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateTableFunctionStmt(
    const ResolvedCreateTableFunctionStmt* node) {
  return CopyVisitResolvedCreateTableFunctionStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRelationArgumentScan(
    const ResolvedRelationArgumentScan* node) {
  return CopyVisitResolvedRelationArgumentScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedArgumentList(
    const ResolvedArgumentList* node) {
  return CopyVisitResolvedArgumentList(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFunctionSignatureHolder(
    const ResolvedFunctionSignatureHolder* node) {
  return CopyVisitResolvedFunctionSignatureHolder(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropFunctionStmt(
    const ResolvedDropFunctionStmt* node) {
  return CopyVisitResolvedDropFunctionStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropTableFunctionStmt(
    const ResolvedDropTableFunctionStmt* node) {
  return CopyVisitResolvedDropTableFunctionStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCallStmt(
    const ResolvedCallStmt* node) {
  return CopyVisitResolvedCallStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedImportStmt(
    const ResolvedImportStmt* node) {
  return CopyVisitResolvedImportStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedModuleStmt(
    const ResolvedModuleStmt* node) {
  return CopyVisitResolvedModuleStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAggregateHavingModifier(
    const ResolvedAggregateHavingModifier* node) {
  return CopyVisitResolvedAggregateHavingModifier(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateMaterializedViewStmt(
    const ResolvedCreateMaterializedViewStmt* node) {
  return CopyVisitResolvedCreateMaterializedViewStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateProcedureStmt(
    const ResolvedCreateProcedureStmt* node) {
  return CopyVisitResolvedCreateProcedureStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExecuteImmediateArgument(
    const ResolvedExecuteImmediateArgument* node) {
  return CopyVisitResolvedExecuteImmediateArgument(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExecuteImmediateStmt(
    const ResolvedExecuteImmediateStmt* node) {
  return CopyVisitResolvedExecuteImmediateStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAssignmentStmt(
    const ResolvedAssignmentStmt* node) {
  return CopyVisitResolvedAssignmentStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateEntityStmt(
    const ResolvedCreateEntityStmt* node) {
  return CopyVisitResolvedCreateEntityStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterEntityStmt(
    const ResolvedAlterEntityStmt* node) {
  return CopyVisitResolvedAlterEntityStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedPivotColumn(
    const ResolvedPivotColumn* node) {
  return CopyVisitResolvedPivotColumn(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedPivotScan(
    const ResolvedPivotScan* node) {
  return CopyVisitResolvedPivotScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedReturningClause(
    const ResolvedReturningClause* node) {
  return CopyVisitResolvedReturningClause(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedUnpivotArg(
    const ResolvedUnpivotArg* node) {
  return CopyVisitResolvedUnpivotArg(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedUnpivotScan(
    const ResolvedUnpivotScan* node) {
  return CopyVisitResolvedUnpivotScan(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCloneDataStmt(
    const ResolvedCloneDataStmt* node) {
  return CopyVisitResolvedCloneDataStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedTableAndColumnInfo(
    const ResolvedTableAndColumnInfo* node) {
  return CopyVisitResolvedTableAndColumnInfo(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAnalyzeStmt(
    const ResolvedAnalyzeStmt* node) {
  return CopyVisitResolvedAnalyzeStmt(node);
}

absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAuxLoadDataStmt(
    const ResolvedAuxLoadDataStmt* node) {
  return CopyVisitResolvedAuxLoadDataStmt(node);
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedLiteral(
    const ResolvedLiteral* node) {
  // Create a mutable instance of ResolvedLiteral.
  auto copy = MakeResolvedLiteral(
    node->type(),
    node->value(),
    node->has_explicit_type(),
    node->float_literal_id()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Copy the preserve_in_literal_remover field explicitly because it is not a
  // constructor arg.
  copy.get()->set_preserve_in_literal_remover(
      node->preserve_in_literal_remover());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedParameter(
    const ResolvedParameter* node) {
  // Create a mutable instance of ResolvedParameter.
  auto copy = MakeResolvedParameter(
    node->type(),
    node->name(),
    node->position(),
    node->is_untyped()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedExpressionColumn(
    const ResolvedExpressionColumn* node) {
  // Create a mutable instance of ResolvedExpressionColumn.
  auto copy = MakeResolvedExpressionColumn(
    node->type(),
    node->name()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedColumnRef(
    const ResolvedColumnRef* node) {
  ZETASQL_ASSIGN_OR_RETURN(
      ResolvedColumn column,
      CopyResolvedColumn(node->column()));

  // Create a mutable instance of ResolvedColumnRef.
  auto copy = MakeResolvedColumnRef(
    node->type(),
    column,
    node->is_correlated()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedConstant(
    const ResolvedConstant* node) {
  // Create a mutable instance of ResolvedConstant.
  auto copy = MakeResolvedConstant(
    node->type(),
    node->constant()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedSystemVariable(
    const ResolvedSystemVariable* node) {
  // Create a mutable instance of ResolvedSystemVariable.
  auto copy = MakeResolvedSystemVariable(
    node->type(),
    node->name_path()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedInlineLambda(
    const ResolvedInlineLambda* node) {
  std::vector<ResolvedColumn> argument_list;
  for (int i = 0; i < node->argument_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->argument_list()[i]));
    argument_list.push_back(elem);
  }

  // Get a deep copy of parameter_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnRef>> parameter_list,
      ProcessNodeList(node->parameter_list()));

  // Get deep copy of body field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> body,
      ProcessNode(node->body()));

  // Create a mutable instance of ResolvedInlineLambda.
  auto copy = MakeResolvedInlineLambda(
    argument_list,
    std::move(parameter_list),
    std::move(body)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedFilterFieldArg(
    const ResolvedFilterFieldArg* node) {
  // Create a mutable instance of ResolvedFilterFieldArg.
  auto copy = MakeResolvedFilterFieldArg(
    node->include(),
    node->field_descriptor_path()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedFilterField(
    const ResolvedFilterField* node) {
  // Get deep copy of expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expr,
      ProcessNode(node->expr()));

  // Get a deep copy of filter_field_arg_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedFilterFieldArg>> filter_field_arg_list,
      ProcessNodeList(node->filter_field_arg_list()));

  // Create a mutable instance of ResolvedFilterField.
  auto copy = MakeResolvedFilterField(
    node->type(),
    std::move(expr),
    std::move(filter_field_arg_list),
    node->reset_cleared_required_fields()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedFunctionCall(
    const ResolvedFunctionCall* node) {
  // Get a deep copy of argument_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> argument_list,
      ProcessNodeList(node->argument_list()));

  // Get a deep copy of generic_argument_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedFunctionArgument>> generic_argument_list,
      ProcessNodeList(node->generic_argument_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedFunctionCall.
  auto copy = MakeResolvedFunctionCall(
    node->type(),
    node->function(),
    node->signature(),
    std::move(argument_list),
    std::move(generic_argument_list),
    node->error_mode(),
    node->function_call_info()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedFunctionCall>(node, copy.get()));

  // Copy the collation field explicitly because it is not a constructor arg.
  copy.get()->set_collation_list(node->collation_list());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAggregateFunctionCall(
    const ResolvedAggregateFunctionCall* node) {
  // Get deep copy of having_modifier field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedAggregateHavingModifier> having_modifier,
      ProcessNode(node->having_modifier()));

  // Get a deep copy of order_by_item_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOrderByItem>> order_by_item_list,
      ProcessNodeList(node->order_by_item_list()));

  // Get deep copy of limit field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> limit,
      ProcessNode(node->limit()));

  // Get a deep copy of argument_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> argument_list,
      ProcessNodeList(node->argument_list()));

  // Get a deep copy of generic_argument_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedFunctionArgument>> generic_argument_list,
      ProcessNodeList(node->generic_argument_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get deep copy of with_group_rows_subquery field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> with_group_rows_subquery,
      ProcessNode(node->with_group_rows_subquery()));

  // Get a deep copy of with_group_rows_parameter_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnRef>> with_group_rows_parameter_list,
      ProcessNodeList(node->with_group_rows_parameter_list()));

  // Create a mutable instance of ResolvedAggregateFunctionCall.
  auto copy = MakeResolvedAggregateFunctionCall(
    node->type(),
    node->function(),
    node->signature(),
    std::move(argument_list),
    std::move(generic_argument_list),
    node->error_mode(),
    node->distinct(),
    node->null_handling_modifier(),
    std::move(having_modifier),
    std::move(order_by_item_list),
    std::move(limit),
    node->function_call_info()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAggregateFunctionCall>(node, copy.get()));

  // Copy the collation field explicitly because it is not a constructor arg.
  copy.get()->set_collation_list(node->collation_list());

  // Copy the with_group_rows_subquery field explicitly because it is not a
  // constructor arg.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> scan,
      ProcessNode(node->with_group_rows_subquery()));
  copy.get()->set_with_group_rows_subquery(std::move(scan));

  // Copy the with_group_rows_parameter_list field explicitly because it is not
  // a constructor arg.
  ZETASQL_RETURN_IF_ERROR(CopyWithGroupRowsParameterList<ResolvedAggregateFunctionCall>(node,
                                                                copy.get()));
  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAnalyticFunctionCall(
    const ResolvedAnalyticFunctionCall* node) {
  // Get deep copy of window_frame field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedWindowFrame> window_frame,
      ProcessNode(node->window_frame()));

  // Get a deep copy of argument_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> argument_list,
      ProcessNodeList(node->argument_list()));

  // Get a deep copy of generic_argument_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedFunctionArgument>> generic_argument_list,
      ProcessNodeList(node->generic_argument_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get deep copy of with_group_rows_subquery field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> with_group_rows_subquery,
      ProcessNode(node->with_group_rows_subquery()));

  // Get a deep copy of with_group_rows_parameter_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnRef>> with_group_rows_parameter_list,
      ProcessNodeList(node->with_group_rows_parameter_list()));

  // Create a mutable instance of ResolvedAnalyticFunctionCall.
  auto copy = MakeResolvedAnalyticFunctionCall(
    node->type(),
    node->function(),
    node->signature(),
    std::move(argument_list),
    std::move(generic_argument_list),
    node->error_mode(),
    node->distinct(),
    node->null_handling_modifier(),
    std::move(window_frame)
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAnalyticFunctionCall>(node, copy.get()));

  // Copy the collation field explicitly because it is not a constructor arg.
  copy.get()->set_collation_list(node->collation_list());

  // Copy the with_group_rows_subquery field explicitly because it is not a
  // constructor arg.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> scan,
      ProcessNode(node->with_group_rows_subquery()));
  copy.get()->set_with_group_rows_subquery(std::move(scan));

  // Copy the with_group_rows_parameter_list field explicitly because it is not
  // a constructor arg.
  ZETASQL_RETURN_IF_ERROR(CopyWithGroupRowsParameterList<ResolvedAnalyticFunctionCall>(node,
                                                                copy.get()));
  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedExtendedCastElement(
    const ResolvedExtendedCastElement* node) {
  // Create a mutable instance of ResolvedExtendedCastElement.
  auto copy = MakeResolvedExtendedCastElement(
    node->from_type(),
    node->to_type(),
    node->function()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedExtendedCast(
    const ResolvedExtendedCast* node) {
  // Get a deep copy of element_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExtendedCastElement>> element_list,
      ProcessNodeList(node->element_list()));

  // Create a mutable instance of ResolvedExtendedCast.
  auto copy = MakeResolvedExtendedCast(
    std::move(element_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCast(
    const ResolvedCast* node) {
  // Get deep copy of expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expr,
      ProcessNode(node->expr()));

  // Get deep copy of extended_cast field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExtendedCast> extended_cast,
      ProcessNode(node->extended_cast()));

  // Get deep copy of format field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> format,
      ProcessNode(node->format()));

  // Get deep copy of time_zone field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> time_zone,
      ProcessNode(node->time_zone()));

  // Create a mutable instance of ResolvedCast.
  auto copy = MakeResolvedCast(
    node->type(),
    std::move(expr),
    node->return_null_on_error(),
    std::move(extended_cast),
    std::move(format),
    std::move(time_zone),
    node->type_parameters()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedMakeStruct(
    const ResolvedMakeStruct* node) {
  // Get a deep copy of field_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> field_list,
      ProcessNodeList(node->field_list()));

  // Create a mutable instance of ResolvedMakeStruct.
  auto copy = MakeResolvedMakeStruct(
    node->type(),
    std::move(field_list)
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedMakeProto(
    const ResolvedMakeProto* node) {
  // Get a deep copy of field_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedMakeProtoField>> field_list,
      ProcessNodeList(node->field_list()));

  // Create a mutable instance of ResolvedMakeProto.
  auto copy = MakeResolvedMakeProto(
    node->type(),
    std::move(field_list)
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedMakeProtoField(
    const ResolvedMakeProtoField* node) {
  // Get deep copy of expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expr,
      ProcessNode(node->expr()));

  // Create a mutable instance of ResolvedMakeProtoField.
  auto copy = MakeResolvedMakeProtoField(
    node->field_descriptor(),
    node->format(),
    std::move(expr)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedGetStructField(
    const ResolvedGetStructField* node) {
  // Get deep copy of expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expr,
      ProcessNode(node->expr()));

  // Create a mutable instance of ResolvedGetStructField.
  auto copy = MakeResolvedGetStructField(
    node->type(),
    std::move(expr),
    node->field_idx()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedGetProtoField(
    const ResolvedGetProtoField* node) {
  // Get deep copy of expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expr,
      ProcessNode(node->expr()));

  // Create a mutable instance of ResolvedGetProtoField.
  auto copy = MakeResolvedGetProtoField(
    node->type(),
    std::move(expr),
    node->field_descriptor(),
    node->default_value(),
    node->get_has_bit(),
    node->format(),
    node->return_default_value_when_unset()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedGetJsonField(
    const ResolvedGetJsonField* node) {
  // Get deep copy of expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expr,
      ProcessNode(node->expr()));

  // Create a mutable instance of ResolvedGetJsonField.
  auto copy = MakeResolvedGetJsonField(
    node->type(),
    std::move(expr),
    node->field_name()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedFlatten(
    const ResolvedFlatten* node) {
  // Get deep copy of expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expr,
      ProcessNode(node->expr()));

  // Get a deep copy of get_field_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> get_field_list,
      ProcessNodeList(node->get_field_list()));

  // Create a mutable instance of ResolvedFlatten.
  auto copy = MakeResolvedFlatten(
    node->type(),
    std::move(expr),
    std::move(get_field_list)
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedFlattenedArg(
    const ResolvedFlattenedArg* node) {
  // Create a mutable instance of ResolvedFlattenedArg.
  auto copy = MakeResolvedFlattenedArg(
    node->type()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedReplaceFieldItem(
    const ResolvedReplaceFieldItem* node) {
  // Get deep copy of expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expr,
      ProcessNode(node->expr()));

  // Create a mutable instance of ResolvedReplaceFieldItem.
  auto copy = MakeResolvedReplaceFieldItem(
    std::move(expr),
    node->struct_index_path(),
    node->proto_field_path()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedReplaceField(
    const ResolvedReplaceField* node) {
  // Get deep copy of expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expr,
      ProcessNode(node->expr()));

  // Get a deep copy of replace_field_item_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedReplaceFieldItem>> replace_field_item_list,
      ProcessNodeList(node->replace_field_item_list()));

  // Create a mutable instance of ResolvedReplaceField.
  auto copy = MakeResolvedReplaceField(
    node->type(),
    std::move(expr),
    std::move(replace_field_item_list)
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedSubqueryExpr(
    const ResolvedSubqueryExpr* node) {
  // Get a deep copy of parameter_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnRef>> parameter_list,
      ProcessNodeList(node->parameter_list()));

  // Get deep copy of in_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> in_expr,
      ProcessNode(node->in_expr()));

  // Get deep copy of subquery field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> subquery,
      ProcessNode(node->subquery()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedSubqueryExpr.
  auto copy = MakeResolvedSubqueryExpr(
    node->type(),
    node->subquery_type(),
    std::move(parameter_list),
    std::move(in_expr),
    std::move(subquery)
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Copy the in_collation field explicitly because it is not a constructor arg.
  copy.get()->set_in_collation(node->in_collation());

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedSubqueryExpr>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedLetExpr(
    const ResolvedLetExpr* node) {
  // Get a deep copy of assignment_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedComputedColumn>> assignment_list,
      ProcessNodeList(node->assignment_list()));

  // Get deep copy of expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expr,
      ProcessNode(node->expr()));

  // Create a mutable instance of ResolvedLetExpr.
  auto copy = MakeResolvedLetExpr(
    node->type(),
    std::move(assignment_list),
    std::move(expr)
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedModel(
    const ResolvedModel* node) {
  // Create a mutable instance of ResolvedModel.
  auto copy = MakeResolvedModel(
    node->model()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedConnection(
    const ResolvedConnection* node) {
  // Create a mutable instance of ResolvedConnection.
  auto copy = MakeResolvedConnection(
    node->connection()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDescriptor(
    const ResolvedDescriptor* node) {
  std::vector<ResolvedColumn> descriptor_column_list;
  for (int i = 0; i < node->descriptor_column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->descriptor_column_list()[i]));
    descriptor_column_list.push_back(elem);
  }

  // Create a mutable instance of ResolvedDescriptor.
  auto copy = MakeResolvedDescriptor(
    descriptor_column_list,
    node->descriptor_column_name_list()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedSingleRowScan(
    const ResolvedSingleRowScan* node) {
  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedSingleRowScan.
  auto copy = MakeResolvedSingleRowScan(
    column_list
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedSingleRowScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedTableScan(
    const ResolvedTableScan* node) {
  // Get deep copy of for_system_time_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> for_system_time_expr,
      ProcessNode(node->for_system_time_expr()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedTableScan.
  auto copy = MakeResolvedTableScan(
    column_list,
    node->table(),
    std::move(for_system_time_expr),
    node->alias()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedTableScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Copy the column_index_list field explicitly because it is not a constructor
  // arg.
  copy.get()->set_column_index_list(node->column_index_list());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedJoinScan(
    const ResolvedJoinScan* node) {
  // Get deep copy of left_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> left_scan,
      ProcessNode(node->left_scan()));

  // Get deep copy of right_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> right_scan,
      ProcessNode(node->right_scan()));

  // Get deep copy of join_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> join_expr,
      ProcessNode(node->join_expr()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedJoinScan.
  auto copy = MakeResolvedJoinScan(
    column_list,
    node->join_type(),
    std::move(left_scan),
    std::move(right_scan),
    std::move(join_expr)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedJoinScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedArrayScan(
    const ResolvedArrayScan* node) {
  // Get deep copy of input_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> input_scan,
      ProcessNode(node->input_scan()));

  // Get deep copy of array_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> array_expr,
      ProcessNode(node->array_expr()));

  ZETASQL_ASSIGN_OR_RETURN(
      ResolvedColumn element_column,
      CopyResolvedColumn(node->element_column()));

  // Get deep copy of array_offset_column field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedColumnHolder> array_offset_column,
      ProcessNode(node->array_offset_column()));

  // Get deep copy of join_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> join_expr,
      ProcessNode(node->join_expr()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedArrayScan.
  auto copy = MakeResolvedArrayScan(
    column_list,
    std::move(input_scan),
    std::move(array_expr),
    element_column,
    std::move(array_offset_column),
    std::move(join_expr),
    node->is_outer()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedArrayScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedColumnHolder(
    const ResolvedColumnHolder* node) {
  ZETASQL_ASSIGN_OR_RETURN(
      ResolvedColumn column,
      CopyResolvedColumn(node->column()));

  // Create a mutable instance of ResolvedColumnHolder.
  auto copy = MakeResolvedColumnHolder(
    column
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedFilterScan(
    const ResolvedFilterScan* node) {
  // Get deep copy of input_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> input_scan,
      ProcessNode(node->input_scan()));

  // Get deep copy of filter_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> filter_expr,
      ProcessNode(node->filter_expr()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedFilterScan.
  auto copy = MakeResolvedFilterScan(
    column_list,
    std::move(input_scan),
    std::move(filter_expr)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedFilterScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedGroupingSet(
    const ResolvedGroupingSet* node) {
  // Get a deep copy of group_by_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnRef>> group_by_column_list,
      ProcessNodeList(node->group_by_column_list()));

  // Create a mutable instance of ResolvedGroupingSet.
  auto copy = MakeResolvedGroupingSet(
    std::move(group_by_column_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAggregateScan(
    const ResolvedAggregateScan* node) {
  // Get a deep copy of grouping_set_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedGroupingSet>> grouping_set_list,
      ProcessNodeList(node->grouping_set_list()));

  // Get a deep copy of rollup_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnRef>> rollup_column_list,
      ProcessNodeList(node->rollup_column_list()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get deep copy of input_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> input_scan,
      ProcessNode(node->input_scan()));

  // Get a deep copy of group_by_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedComputedColumn>> group_by_list,
      ProcessNodeList(node->group_by_list()));

  // Get a deep copy of aggregate_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedComputedColumn>> aggregate_list,
      ProcessNodeList(node->aggregate_list()));

  // Create a mutable instance of ResolvedAggregateScan.
  auto copy = MakeResolvedAggregateScan(
    column_list,
    std::move(input_scan),
    std::move(group_by_list),
    std::move(aggregate_list),
    std::move(grouping_set_list),
    std::move(rollup_column_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAggregateScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Copy the collation field explicitly because it is not a constructor arg.
  copy.get()->set_collation_list(node->collation_list());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAnonymizedAggregateScan(
    const ResolvedAnonymizedAggregateScan* node) {
  // Get deep copy of k_threshold_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedColumnRef> k_threshold_expr,
      ProcessNode(node->k_threshold_expr()));

  // Get a deep copy of anonymization_option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> anonymization_option_list,
      ProcessNodeList(node->anonymization_option_list()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get deep copy of input_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> input_scan,
      ProcessNode(node->input_scan()));

  // Get a deep copy of group_by_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedComputedColumn>> group_by_list,
      ProcessNodeList(node->group_by_list()));

  // Get a deep copy of aggregate_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedComputedColumn>> aggregate_list,
      ProcessNodeList(node->aggregate_list()));

  // Create a mutable instance of ResolvedAnonymizedAggregateScan.
  auto copy = MakeResolvedAnonymizedAggregateScan(
    column_list,
    std::move(input_scan),
    std::move(group_by_list),
    std::move(aggregate_list),
    std::move(k_threshold_expr),
    std::move(anonymization_option_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAnonymizedAggregateScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Copy the collation field explicitly because it is not a constructor arg.
  copy.get()->set_collation_list(node->collation_list());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedSetOperationItem(
    const ResolvedSetOperationItem* node) {
  // Get deep copy of scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> scan,
      ProcessNode(node->scan()));

  std::vector<ResolvedColumn> output_column_list;
  for (int i = 0; i < node->output_column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->output_column_list()[i]));
    output_column_list.push_back(elem);
  }

  // Create a mutable instance of ResolvedSetOperationItem.
  auto copy = MakeResolvedSetOperationItem(
    std::move(scan),
    output_column_list
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedSetOperationScan(
    const ResolvedSetOperationScan* node) {
  // Get a deep copy of input_item_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedSetOperationItem>> input_item_list,
      ProcessNodeList(node->input_item_list()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedSetOperationScan.
  auto copy = MakeResolvedSetOperationScan(
    column_list,
    node->op_type(),
    std::move(input_item_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedSetOperationScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedOrderByScan(
    const ResolvedOrderByScan* node) {
  // Get deep copy of input_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> input_scan,
      ProcessNode(node->input_scan()));

  // Get a deep copy of order_by_item_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOrderByItem>> order_by_item_list,
      ProcessNodeList(node->order_by_item_list()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedOrderByScan.
  auto copy = MakeResolvedOrderByScan(
    column_list,
    std::move(input_scan),
    std::move(order_by_item_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedOrderByScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedLimitOffsetScan(
    const ResolvedLimitOffsetScan* node) {
  // Get deep copy of input_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> input_scan,
      ProcessNode(node->input_scan()));

  // Get deep copy of limit field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> limit,
      ProcessNode(node->limit()));

  // Get deep copy of offset field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> offset,
      ProcessNode(node->offset()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedLimitOffsetScan.
  auto copy = MakeResolvedLimitOffsetScan(
    column_list,
    std::move(input_scan),
    std::move(limit),
    std::move(offset)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedLimitOffsetScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedWithRefScan(
    const ResolvedWithRefScan* node) {
  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedWithRefScan.
  auto copy = MakeResolvedWithRefScan(
    column_list,
    node->with_query_name()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedWithRefScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAnalyticScan(
    const ResolvedAnalyticScan* node) {
  // Get deep copy of input_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> input_scan,
      ProcessNode(node->input_scan()));

  // Get a deep copy of function_group_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedAnalyticFunctionGroup>> function_group_list,
      ProcessNodeList(node->function_group_list()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedAnalyticScan.
  auto copy = MakeResolvedAnalyticScan(
    column_list,
    std::move(input_scan),
    std::move(function_group_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAnalyticScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedSampleScan(
    const ResolvedSampleScan* node) {
  // Get deep copy of input_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> input_scan,
      ProcessNode(node->input_scan()));

  // Get deep copy of size field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> size,
      ProcessNode(node->size()));

  // Get deep copy of repeatable_argument field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> repeatable_argument,
      ProcessNode(node->repeatable_argument()));

  // Get deep copy of weight_column field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedColumnHolder> weight_column,
      ProcessNode(node->weight_column()));

  // Get a deep copy of partition_by_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> partition_by_list,
      ProcessNodeList(node->partition_by_list()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedSampleScan.
  auto copy = MakeResolvedSampleScan(
    column_list,
    std::move(input_scan),
    node->method(),
    std::move(size),
    node->unit(),
    std::move(repeatable_argument),
    std::move(weight_column),
    std::move(partition_by_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedSampleScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedComputedColumn(
    const ResolvedComputedColumn* node) {
  ZETASQL_ASSIGN_OR_RETURN(
      ResolvedColumn column,
      CopyResolvedColumn(node->column()));

  // Get deep copy of expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expr,
      ProcessNode(node->expr()));

  // Create a mutable instance of ResolvedComputedColumn.
  auto copy = MakeResolvedComputedColumn(
    column,
    std::move(expr)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedOrderByItem(
    const ResolvedOrderByItem* node) {
  // Get deep copy of column_ref field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedColumnRef> column_ref,
      ProcessNode(node->column_ref()));

  // Get deep copy of collation_name field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> collation_name,
      ProcessNode(node->collation_name()));

  // Create a mutable instance of ResolvedOrderByItem.
  auto copy = MakeResolvedOrderByItem(
    std::move(column_ref),
    std::move(collation_name),
    node->is_descending(),
    node->null_order()
  );

  // Copy the collation field explicitly because it is not a constructor arg.
  copy.get()->set_collation(node->collation());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedColumnAnnotations(
    const ResolvedColumnAnnotations* node) {
  // Get deep copy of collation_name field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> collation_name,
      ProcessNode(node->collation_name()));

  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of child_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnAnnotations>> child_list,
      ProcessNodeList(node->child_list()));

  // Create a mutable instance of ResolvedColumnAnnotations.
  auto copy = MakeResolvedColumnAnnotations(
    std::move(collation_name),
    node->not_null(),
    std::move(option_list),
    std::move(child_list),
    node->type_parameters()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedGeneratedColumnInfo(
    const ResolvedGeneratedColumnInfo* node) {
  // Get deep copy of expression field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expression,
      ProcessNode(node->expression()));

  // Create a mutable instance of ResolvedGeneratedColumnInfo.
  auto copy = MakeResolvedGeneratedColumnInfo(
    std::move(expression),
    node->stored_mode()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedColumnDefaultValue(
    const ResolvedColumnDefaultValue* node) {
  // Get deep copy of expression field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expression,
      ProcessNode(node->expression()));

  // Create a mutable instance of ResolvedColumnDefaultValue.
  auto copy = MakeResolvedColumnDefaultValue(
    std::move(expression),
    node->sql()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedColumnDefinition(
    const ResolvedColumnDefinition* node) {
  // Get deep copy of annotations field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedColumnAnnotations> annotations,
      ProcessNode(node->annotations()));

  ZETASQL_ASSIGN_OR_RETURN(
      ResolvedColumn column,
      CopyResolvedColumn(node->column()));

  // Get deep copy of generated_column_info field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedGeneratedColumnInfo> generated_column_info,
      ProcessNode(node->generated_column_info()));

  // Get deep copy of default_value field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedColumnDefaultValue> default_value,
      ProcessNode(node->default_value()));

  // Create a mutable instance of ResolvedColumnDefinition.
  auto copy = MakeResolvedColumnDefinition(
    node->name(),
    node->type(),
    std::move(annotations),
    node->is_hidden(),
    column,
    std::move(generated_column_info),
    std::move(default_value)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedPrimaryKey(
    const ResolvedPrimaryKey* node) {
  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Create a mutable instance of ResolvedPrimaryKey.
  auto copy = MakeResolvedPrimaryKey(
    node->column_offset_list(),
    std::move(option_list),
    node->unenforced(),
    node->constraint_name(),
    node->column_name_list()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedForeignKey(
    const ResolvedForeignKey* node) {
  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Create a mutable instance of ResolvedForeignKey.
  auto copy = MakeResolvedForeignKey(
    node->constraint_name(),
    node->referencing_column_offset_list(),
    node->referenced_table(),
    node->referenced_column_offset_list(),
    node->match_mode(),
    node->update_action(),
    node->delete_action(),
    node->enforced(),
    std::move(option_list),
    node->referencing_column_list()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCheckConstraint(
    const ResolvedCheckConstraint* node) {
  // Get deep copy of expression field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expression,
      ProcessNode(node->expression()));

  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Create a mutable instance of ResolvedCheckConstraint.
  auto copy = MakeResolvedCheckConstraint(
    node->constraint_name(),
    std::move(expression),
    node->enforced(),
    std::move(option_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedOutputColumn(
    const ResolvedOutputColumn* node) {
  ZETASQL_ASSIGN_OR_RETURN(
      ResolvedColumn column,
      CopyResolvedColumn(node->column()));

  // Create a mutable instance of ResolvedOutputColumn.
  auto copy = MakeResolvedOutputColumn(
    node->name(),
    column
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedProjectScan(
    const ResolvedProjectScan* node) {
  // Get a deep copy of expr_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedComputedColumn>> expr_list,
      ProcessNodeList(node->expr_list()));

  // Get deep copy of input_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> input_scan,
      ProcessNode(node->input_scan()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedProjectScan.
  auto copy = MakeResolvedProjectScan(
    column_list,
    std::move(expr_list),
    std::move(input_scan)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedProjectScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedTVFScan(
    const ResolvedTVFScan* node) {
  // Get a deep copy of argument_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedFunctionArgument>> argument_list,
      ProcessNodeList(node->argument_list()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedTVFScan.
  auto copy = MakeResolvedTVFScan(
    column_list,
    node->tvf(),
    node->signature(),
    std::move(argument_list),
    node->column_index_list(),
    node->alias(),
    node->function_call_signature()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedTVFScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Copy the column_index_list field explicitly because it is not a constructor
  // arg.
  copy.get()->set_column_index_list(node->column_index_list());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedGroupRowsScan(
    const ResolvedGroupRowsScan* node) {
  // Get a deep copy of input_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedComputedColumn>> input_column_list,
      ProcessNodeList(node->input_column_list()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedGroupRowsScan.
  auto copy = MakeResolvedGroupRowsScan(
    column_list,
    std::move(input_column_list),
    node->alias()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedGroupRowsScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedFunctionArgument(
    const ResolvedFunctionArgument* node) {
  // Get deep copy of expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expr,
      ProcessNode(node->expr()));

  // Get deep copy of scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> scan,
      ProcessNode(node->scan()));

  // Get deep copy of model field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedModel> model,
      ProcessNode(node->model()));

  // Get deep copy of connection field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedConnection> connection,
      ProcessNode(node->connection()));

  // Get deep copy of descriptor_arg field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedDescriptor> descriptor_arg,
      ProcessNode(node->descriptor_arg()));

  std::vector<ResolvedColumn> argument_column_list;
  for (int i = 0; i < node->argument_column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->argument_column_list()[i]));
    argument_column_list.push_back(elem);
  }

  // Get deep copy of inline_lambda field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedInlineLambda> inline_lambda,
      ProcessNode(node->inline_lambda()));

  // Create a mutable instance of ResolvedFunctionArgument.
  auto copy = MakeResolvedFunctionArgument(
    std::move(expr),
    std::move(scan),
    std::move(model),
    std::move(connection),
    std::move(descriptor_arg),
    argument_column_list,
    std::move(inline_lambda)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedExplainStmt(
    const ResolvedExplainStmt* node) {
  // Get deep copy of statement field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedStatement> statement,
      ProcessNode(node->statement()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedExplainStmt.
  auto copy = MakeResolvedExplainStmt(
    std::move(statement)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedExplainStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedQueryStmt(
    const ResolvedQueryStmt* node) {
  // Get a deep copy of output_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOutputColumn>> output_column_list,
      ProcessNodeList(node->output_column_list()));

  // Get deep copy of query field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> query,
      ProcessNode(node->query()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedQueryStmt.
  auto copy = MakeResolvedQueryStmt(
    std::move(output_column_list),
    node->is_value_table(),
    std::move(query)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedQueryStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateDatabaseStmt(
    const ResolvedCreateDatabaseStmt* node) {
  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedCreateDatabaseStmt.
  auto copy = MakeResolvedCreateDatabaseStmt(
    node->name_path(),
    std::move(option_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateDatabaseStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedIndexItem(
    const ResolvedIndexItem* node) {
  // Get deep copy of column_ref field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedColumnRef> column_ref,
      ProcessNode(node->column_ref()));

  // Create a mutable instance of ResolvedIndexItem.
  auto copy = MakeResolvedIndexItem(
    std::move(column_ref),
    node->descending()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedUnnestItem(
    const ResolvedUnnestItem* node) {
  // Get deep copy of array_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> array_expr,
      ProcessNode(node->array_expr()));

  ZETASQL_ASSIGN_OR_RETURN(
      ResolvedColumn element_column,
      CopyResolvedColumn(node->element_column()));

  // Get deep copy of array_offset_column field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedColumnHolder> array_offset_column,
      ProcessNode(node->array_offset_column()));

  // Create a mutable instance of ResolvedUnnestItem.
  auto copy = MakeResolvedUnnestItem(
    std::move(array_expr),
    element_column,
    std::move(array_offset_column)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateIndexStmt(
    const ResolvedCreateIndexStmt* node) {
  // Get deep copy of table_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedTableScan> table_scan,
      ProcessNode(node->table_scan()));

  // Get a deep copy of index_item_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedIndexItem>> index_item_list,
      ProcessNodeList(node->index_item_list()));

  // Get a deep copy of storing_expression_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> storing_expression_list,
      ProcessNodeList(node->storing_expression_list()));

  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of computed_columns_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedComputedColumn>> computed_columns_list,
      ProcessNodeList(node->computed_columns_list()));

  // Get a deep copy of unnest_expressions_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedUnnestItem>> unnest_expressions_list,
      ProcessNodeList(node->unnest_expressions_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedCreateIndexStmt.
  auto copy = MakeResolvedCreateIndexStmt(
    node->name_path(),
    node->create_scope(),
    node->create_mode(),
    node->table_name_path(),
    std::move(table_scan),
    node->is_unique(),
    node->is_search(),
    node->index_all_columns(),
    std::move(index_item_list),
    std::move(storing_expression_list),
    std::move(option_list),
    std::move(computed_columns_list),
    std::move(unnest_expressions_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateIndexStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateSchemaStmt(
    const ResolvedCreateSchemaStmt* node) {
  // Get deep copy of collation_name field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> collation_name,
      ProcessNode(node->collation_name()));

  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedCreateSchemaStmt.
  auto copy = MakeResolvedCreateSchemaStmt(
    node->name_path(),
    node->create_scope(),
    node->create_mode(),
    std::move(collation_name),
    std::move(option_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateSchemaStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateTableStmt(
    const ResolvedCreateTableStmt* node) {
  // Get deep copy of clone_from field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> clone_from,
      ProcessNode(node->clone_from()));

  // Get deep copy of copy_from field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> copy_from,
      ProcessNode(node->copy_from()));

  // Get a deep copy of partition_by_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> partition_by_list,
      ProcessNodeList(node->partition_by_list()));

  // Get a deep copy of cluster_by_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> cluster_by_list,
      ProcessNodeList(node->cluster_by_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of column_definition_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnDefinition>> column_definition_list,
      ProcessNodeList(node->column_definition_list()));

  std::vector<ResolvedColumn> pseudo_column_list;
  for (int i = 0; i < node->pseudo_column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->pseudo_column_list()[i]));
    pseudo_column_list.push_back(elem);
  }

  // Get deep copy of primary_key field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedPrimaryKey> primary_key,
      ProcessNode(node->primary_key()));

  // Get a deep copy of foreign_key_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedForeignKey>> foreign_key_list,
      ProcessNodeList(node->foreign_key_list()));

  // Get a deep copy of check_constraint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedCheckConstraint>> check_constraint_list,
      ProcessNodeList(node->check_constraint_list()));

  // Get deep copy of collation_name field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> collation_name,
      ProcessNode(node->collation_name()));

  // Create a mutable instance of ResolvedCreateTableStmt.
  auto copy = MakeResolvedCreateTableStmt(
    node->name_path(),
    node->create_scope(),
    node->create_mode(),
    std::move(option_list),
    std::move(column_definition_list),
    pseudo_column_list,
    std::move(primary_key),
    std::move(foreign_key_list),
    std::move(check_constraint_list),
    node->is_value_table(),
    node->like_table(),
    std::move(collation_name),
    std::move(clone_from),
    std::move(copy_from),
    std::move(partition_by_list),
    std::move(cluster_by_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateTableStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateTableAsSelectStmt(
    const ResolvedCreateTableAsSelectStmt* node) {
  // Get a deep copy of partition_by_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> partition_by_list,
      ProcessNodeList(node->partition_by_list()));

  // Get a deep copy of cluster_by_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> cluster_by_list,
      ProcessNodeList(node->cluster_by_list()));

  // Get a deep copy of output_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOutputColumn>> output_column_list,
      ProcessNodeList(node->output_column_list()));

  // Get deep copy of query field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> query,
      ProcessNode(node->query()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of column_definition_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnDefinition>> column_definition_list,
      ProcessNodeList(node->column_definition_list()));

  std::vector<ResolvedColumn> pseudo_column_list;
  for (int i = 0; i < node->pseudo_column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->pseudo_column_list()[i]));
    pseudo_column_list.push_back(elem);
  }

  // Get deep copy of primary_key field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedPrimaryKey> primary_key,
      ProcessNode(node->primary_key()));

  // Get a deep copy of foreign_key_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedForeignKey>> foreign_key_list,
      ProcessNodeList(node->foreign_key_list()));

  // Get a deep copy of check_constraint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedCheckConstraint>> check_constraint_list,
      ProcessNodeList(node->check_constraint_list()));

  // Get deep copy of collation_name field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> collation_name,
      ProcessNode(node->collation_name()));

  // Create a mutable instance of ResolvedCreateTableAsSelectStmt.
  auto copy = MakeResolvedCreateTableAsSelectStmt(
    node->name_path(),
    node->create_scope(),
    node->create_mode(),
    std::move(option_list),
    std::move(column_definition_list),
    pseudo_column_list,
    std::move(primary_key),
    std::move(foreign_key_list),
    std::move(check_constraint_list),
    node->is_value_table(),
    node->like_table(),
    std::move(collation_name),
    std::move(partition_by_list),
    std::move(cluster_by_list),
    std::move(output_column_list),
    std::move(query)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateTableAsSelectStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateModelStmt(
    const ResolvedCreateModelStmt* node) {
  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of output_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOutputColumn>> output_column_list,
      ProcessNodeList(node->output_column_list()));

  // Get deep copy of query field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> query,
      ProcessNode(node->query()));

  // Get a deep copy of transform_input_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnDefinition>> transform_input_column_list,
      ProcessNodeList(node->transform_input_column_list()));

  // Get a deep copy of transform_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedComputedColumn>> transform_list,
      ProcessNodeList(node->transform_list()));

  // Get a deep copy of transform_output_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOutputColumn>> transform_output_column_list,
      ProcessNodeList(node->transform_output_column_list()));

  // Get a deep copy of transform_analytic_function_group_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedAnalyticFunctionGroup>> transform_analytic_function_group_list,
      ProcessNodeList(node->transform_analytic_function_group_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedCreateModelStmt.
  auto copy = MakeResolvedCreateModelStmt(
    node->name_path(),
    node->create_scope(),
    node->create_mode(),
    std::move(option_list),
    std::move(output_column_list),
    std::move(query),
    std::move(transform_input_column_list),
    std::move(transform_list),
    std::move(transform_output_column_list),
    std::move(transform_analytic_function_group_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateModelStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateViewStmt(
    const ResolvedCreateViewStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of output_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOutputColumn>> output_column_list,
      ProcessNodeList(node->output_column_list()));

  // Get deep copy of query field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> query,
      ProcessNode(node->query()));

  // Create a mutable instance of ResolvedCreateViewStmt.
  auto copy = MakeResolvedCreateViewStmt(
    node->name_path(),
    node->create_scope(),
    node->create_mode(),
    std::move(option_list),
    std::move(output_column_list),
    node->has_explicit_columns(),
    std::move(query),
    node->sql(),
    node->sql_security(),
    node->is_value_table(),
    node->recursive()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateViewStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedWithPartitionColumns(
    const ResolvedWithPartitionColumns* node) {
  // Get a deep copy of column_definition_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnDefinition>> column_definition_list,
      ProcessNodeList(node->column_definition_list()));

  // Create a mutable instance of ResolvedWithPartitionColumns.
  auto copy = MakeResolvedWithPartitionColumns(
    std::move(column_definition_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateSnapshotTableStmt(
    const ResolvedCreateSnapshotTableStmt* node) {
  // Get deep copy of clone_from field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> clone_from,
      ProcessNode(node->clone_from()));

  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedCreateSnapshotTableStmt.
  auto copy = MakeResolvedCreateSnapshotTableStmt(
    node->name_path(),
    node->create_scope(),
    node->create_mode(),
    std::move(clone_from),
    std::move(option_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateSnapshotTableStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateExternalTableStmt(
    const ResolvedCreateExternalTableStmt* node) {
  // Get deep copy of with_partition_columns field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedWithPartitionColumns> with_partition_columns,
      ProcessNode(node->with_partition_columns()));

  // Get deep copy of connection field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedConnection> connection,
      ProcessNode(node->connection()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of column_definition_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnDefinition>> column_definition_list,
      ProcessNodeList(node->column_definition_list()));

  std::vector<ResolvedColumn> pseudo_column_list;
  for (int i = 0; i < node->pseudo_column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->pseudo_column_list()[i]));
    pseudo_column_list.push_back(elem);
  }

  // Get deep copy of primary_key field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedPrimaryKey> primary_key,
      ProcessNode(node->primary_key()));

  // Get a deep copy of foreign_key_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedForeignKey>> foreign_key_list,
      ProcessNodeList(node->foreign_key_list()));

  // Get a deep copy of check_constraint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedCheckConstraint>> check_constraint_list,
      ProcessNodeList(node->check_constraint_list()));

  // Get deep copy of collation_name field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> collation_name,
      ProcessNode(node->collation_name()));

  // Create a mutable instance of ResolvedCreateExternalTableStmt.
  auto copy = MakeResolvedCreateExternalTableStmt(
    node->name_path(),
    node->create_scope(),
    node->create_mode(),
    std::move(option_list),
    std::move(column_definition_list),
    pseudo_column_list,
    std::move(primary_key),
    std::move(foreign_key_list),
    std::move(check_constraint_list),
    node->is_value_table(),
    node->like_table(),
    std::move(collation_name),
    std::move(with_partition_columns),
    std::move(connection)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateExternalTableStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedExportModelStmt(
    const ResolvedExportModelStmt* node) {
  // Get deep copy of connection field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedConnection> connection,
      ProcessNode(node->connection()));

  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedExportModelStmt.
  auto copy = MakeResolvedExportModelStmt(
    node->model_name_path(),
    std::move(connection),
    std::move(option_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedExportModelStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedExportDataStmt(
    const ResolvedExportDataStmt* node) {
  // Get deep copy of connection field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedConnection> connection,
      ProcessNode(node->connection()));

  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of output_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOutputColumn>> output_column_list,
      ProcessNodeList(node->output_column_list()));

  // Get deep copy of query field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> query,
      ProcessNode(node->query()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedExportDataStmt.
  auto copy = MakeResolvedExportDataStmt(
    std::move(connection),
    std::move(option_list),
    std::move(output_column_list),
    node->is_value_table(),
    std::move(query)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedExportDataStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDefineTableStmt(
    const ResolvedDefineTableStmt* node) {
  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedDefineTableStmt.
  auto copy = MakeResolvedDefineTableStmt(
    node->name_path(),
    std::move(option_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedDefineTableStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDescribeStmt(
    const ResolvedDescribeStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedDescribeStmt.
  auto copy = MakeResolvedDescribeStmt(
    node->object_type(),
    node->name_path(),
    node->from_name_path()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedDescribeStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedShowStmt(
    const ResolvedShowStmt* node) {
  // Get deep copy of like_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedLiteral> like_expr,
      ProcessNode(node->like_expr()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedShowStmt.
  auto copy = MakeResolvedShowStmt(
    node->identifier(),
    node->name_path(),
    std::move(like_expr)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedShowStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedBeginStmt(
    const ResolvedBeginStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedBeginStmt.
  auto copy = MakeResolvedBeginStmt(
    node->read_write_mode(),
    node->isolation_level_list()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedBeginStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedSetTransactionStmt(
    const ResolvedSetTransactionStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedSetTransactionStmt.
  auto copy = MakeResolvedSetTransactionStmt(
    node->read_write_mode(),
    node->isolation_level_list()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedSetTransactionStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCommitStmt(
    const ResolvedCommitStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedCommitStmt.
  auto copy = MakeResolvedCommitStmt(
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCommitStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedRollbackStmt(
    const ResolvedRollbackStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedRollbackStmt.
  auto copy = MakeResolvedRollbackStmt(
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedRollbackStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedStartBatchStmt(
    const ResolvedStartBatchStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedStartBatchStmt.
  auto copy = MakeResolvedStartBatchStmt(
    node->batch_type()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedStartBatchStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedRunBatchStmt(
    const ResolvedRunBatchStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedRunBatchStmt.
  auto copy = MakeResolvedRunBatchStmt(
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedRunBatchStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAbortBatchStmt(
    const ResolvedAbortBatchStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedAbortBatchStmt.
  auto copy = MakeResolvedAbortBatchStmt(
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAbortBatchStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropStmt(
    const ResolvedDropStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedDropStmt.
  auto copy = MakeResolvedDropStmt(
    node->object_type(),
    node->is_if_exists(),
    node->name_path(),
    node->drop_mode()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedDropStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropMaterializedViewStmt(
    const ResolvedDropMaterializedViewStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedDropMaterializedViewStmt.
  auto copy = MakeResolvedDropMaterializedViewStmt(
    node->is_if_exists(),
    node->name_path()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedDropMaterializedViewStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropSnapshotTableStmt(
    const ResolvedDropSnapshotTableStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedDropSnapshotTableStmt.
  auto copy = MakeResolvedDropSnapshotTableStmt(
    node->is_if_exists(),
    node->name_path()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedDropSnapshotTableStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedRecursiveRefScan(
    const ResolvedRecursiveRefScan* node) {
  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedRecursiveRefScan.
  auto copy = MakeResolvedRecursiveRefScan(
    column_list
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedRecursiveRefScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedRecursiveScan(
    const ResolvedRecursiveScan* node) {
  // Get deep copy of non_recursive_term field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedSetOperationItem> non_recursive_term,
      ProcessNode(node->non_recursive_term()));

  // Get deep copy of recursive_term field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedSetOperationItem> recursive_term,
      ProcessNode(node->recursive_term()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedRecursiveScan.
  auto copy = MakeResolvedRecursiveScan(
    column_list,
    node->op_type(),
    std::move(non_recursive_term),
    std::move(recursive_term)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedRecursiveScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedWithScan(
    const ResolvedWithScan* node) {
  // Get a deep copy of with_entry_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedWithEntry>> with_entry_list,
      ProcessNodeList(node->with_entry_list()));

  // Get deep copy of query field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> query,
      ProcessNode(node->query()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedWithScan.
  auto copy = MakeResolvedWithScan(
    column_list,
    std::move(with_entry_list),
    std::move(query),
    node->recursive()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedWithScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedWithEntry(
    const ResolvedWithEntry* node) {
  // Get deep copy of with_subquery field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> with_subquery,
      ProcessNode(node->with_subquery()));

  // Create a mutable instance of ResolvedWithEntry.
  auto copy = MakeResolvedWithEntry(
    node->with_query_name(),
    std::move(with_subquery)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedOption(
    const ResolvedOption* node) {
  // Get deep copy of value field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> value,
      ProcessNode(node->value()));

  // Create a mutable instance of ResolvedOption.
  auto copy = MakeResolvedOption(
    node->qualifier(),
    node->name(),
    std::move(value)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedWindowPartitioning(
    const ResolvedWindowPartitioning* node) {
  // Get a deep copy of partition_by_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnRef>> partition_by_list,
      ProcessNodeList(node->partition_by_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedWindowPartitioning.
  auto copy = MakeResolvedWindowPartitioning(
    std::move(partition_by_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedWindowPartitioning>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedWindowOrdering(
    const ResolvedWindowOrdering* node) {
  // Get a deep copy of order_by_item_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOrderByItem>> order_by_item_list,
      ProcessNodeList(node->order_by_item_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedWindowOrdering.
  auto copy = MakeResolvedWindowOrdering(
    std::move(order_by_item_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedWindowOrdering>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedWindowFrame(
    const ResolvedWindowFrame* node) {
  // Get deep copy of start_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedWindowFrameExpr> start_expr,
      ProcessNode(node->start_expr()));

  // Get deep copy of end_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedWindowFrameExpr> end_expr,
      ProcessNode(node->end_expr()));

  // Create a mutable instance of ResolvedWindowFrame.
  auto copy = MakeResolvedWindowFrame(
    node->frame_unit(),
    std::move(start_expr),
    std::move(end_expr)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAnalyticFunctionGroup(
    const ResolvedAnalyticFunctionGroup* node) {
  // Get deep copy of partition_by field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedWindowPartitioning> partition_by,
      ProcessNode(node->partition_by()));

  // Get deep copy of order_by field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedWindowOrdering> order_by,
      ProcessNode(node->order_by()));

  // Get a deep copy of analytic_function_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedComputedColumn>> analytic_function_list,
      ProcessNodeList(node->analytic_function_list()));

  // Create a mutable instance of ResolvedAnalyticFunctionGroup.
  auto copy = MakeResolvedAnalyticFunctionGroup(
    std::move(partition_by),
    std::move(order_by),
    std::move(analytic_function_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedWindowFrameExpr(
    const ResolvedWindowFrameExpr* node) {
  // Get deep copy of expression field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expression,
      ProcessNode(node->expression()));

  // Create a mutable instance of ResolvedWindowFrameExpr.
  auto copy = MakeResolvedWindowFrameExpr(
    node->boundary_type(),
    std::move(expression)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDMLValue(
    const ResolvedDMLValue* node) {
  // Get deep copy of value field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> value,
      ProcessNode(node->value()));

  // Create a mutable instance of ResolvedDMLValue.
  auto copy = MakeResolvedDMLValue(
    std::move(value)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDMLDefault(
    const ResolvedDMLDefault* node) {
  // Create a mutable instance of ResolvedDMLDefault.
  auto copy = MakeResolvedDMLDefault(
    node->type()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAssertStmt(
    const ResolvedAssertStmt* node) {
  // Get deep copy of expression field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expression,
      ProcessNode(node->expression()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedAssertStmt.
  auto copy = MakeResolvedAssertStmt(
    std::move(expression),
    node->description()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAssertStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAssertRowsModified(
    const ResolvedAssertRowsModified* node) {
  // Get deep copy of rows field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> rows,
      ProcessNode(node->rows()));

  // Create a mutable instance of ResolvedAssertRowsModified.
  auto copy = MakeResolvedAssertRowsModified(
    std::move(rows)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedInsertRow(
    const ResolvedInsertRow* node) {
  // Get a deep copy of value_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedDMLValue>> value_list,
      ProcessNodeList(node->value_list()));

  // Create a mutable instance of ResolvedInsertRow.
  auto copy = MakeResolvedInsertRow(
    std::move(value_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedInsertStmt(
    const ResolvedInsertStmt* node) {
  // Get deep copy of table_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedTableScan> table_scan,
      ProcessNode(node->table_scan()));

  // Get deep copy of assert_rows_modified field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedAssertRowsModified> assert_rows_modified,
      ProcessNode(node->assert_rows_modified()));

  // Get deep copy of returning field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedReturningClause> returning,
      ProcessNode(node->returning()));

  std::vector<ResolvedColumn> insert_column_list;
  for (int i = 0; i < node->insert_column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->insert_column_list()[i]));
    insert_column_list.push_back(elem);
  }

  // Get a deep copy of query_parameter_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnRef>> query_parameter_list,
      ProcessNodeList(node->query_parameter_list()));

  // Get deep copy of query field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> query,
      ProcessNode(node->query()));

  std::vector<ResolvedColumn> query_output_column_list;
  for (int i = 0; i < node->query_output_column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->query_output_column_list()[i]));
    query_output_column_list.push_back(elem);
  }

  // Get a deep copy of row_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedInsertRow>> row_list,
      ProcessNodeList(node->row_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedInsertStmt.
  auto copy = MakeResolvedInsertStmt(
    std::move(table_scan),
    node->insert_mode(),
    std::move(assert_rows_modified),
    std::move(returning),
    insert_column_list,
    std::move(query_parameter_list),
    std::move(query),
    query_output_column_list,
    std::move(row_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedInsertStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDeleteStmt(
    const ResolvedDeleteStmt* node) {
  // Get deep copy of table_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedTableScan> table_scan,
      ProcessNode(node->table_scan()));

  // Get deep copy of assert_rows_modified field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedAssertRowsModified> assert_rows_modified,
      ProcessNode(node->assert_rows_modified()));

  // Get deep copy of returning field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedReturningClause> returning,
      ProcessNode(node->returning()));

  // Get deep copy of array_offset_column field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedColumnHolder> array_offset_column,
      ProcessNode(node->array_offset_column()));

  // Get deep copy of where_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> where_expr,
      ProcessNode(node->where_expr()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedDeleteStmt.
  auto copy = MakeResolvedDeleteStmt(
    std::move(table_scan),
    std::move(assert_rows_modified),
    std::move(returning),
    std::move(array_offset_column),
    std::move(where_expr)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedDeleteStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedUpdateItem(
    const ResolvedUpdateItem* node) {
  // Get deep copy of target field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> target,
      ProcessNode(node->target()));

  // Get deep copy of set_value field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedDMLValue> set_value,
      ProcessNode(node->set_value()));

  // Get deep copy of element_column field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedColumnHolder> element_column,
      ProcessNode(node->element_column()));

  // Get a deep copy of array_update_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedUpdateArrayItem>> array_update_list,
      ProcessNodeList(node->array_update_list()));

  // Get a deep copy of delete_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedDeleteStmt>> delete_list,
      ProcessNodeList(node->delete_list()));

  // Get a deep copy of update_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedUpdateStmt>> update_list,
      ProcessNodeList(node->update_list()));

  // Get a deep copy of insert_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedInsertStmt>> insert_list,
      ProcessNodeList(node->insert_list()));

  // Create a mutable instance of ResolvedUpdateItem.
  auto copy = MakeResolvedUpdateItem(
    std::move(target),
    std::move(set_value),
    std::move(element_column),
    std::move(array_update_list),
    std::move(delete_list),
    std::move(update_list),
    std::move(insert_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedUpdateArrayItem(
    const ResolvedUpdateArrayItem* node) {
  // Get deep copy of offset field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> offset,
      ProcessNode(node->offset()));

  // Get deep copy of update_item field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedUpdateItem> update_item,
      ProcessNode(node->update_item()));

  // Create a mutable instance of ResolvedUpdateArrayItem.
  auto copy = MakeResolvedUpdateArrayItem(
    std::move(offset),
    std::move(update_item)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedUpdateStmt(
    const ResolvedUpdateStmt* node) {
  // Get deep copy of table_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedTableScan> table_scan,
      ProcessNode(node->table_scan()));

  // Get deep copy of assert_rows_modified field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedAssertRowsModified> assert_rows_modified,
      ProcessNode(node->assert_rows_modified()));

  // Get deep copy of returning field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedReturningClause> returning,
      ProcessNode(node->returning()));

  // Get deep copy of array_offset_column field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedColumnHolder> array_offset_column,
      ProcessNode(node->array_offset_column()));

  // Get deep copy of where_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> where_expr,
      ProcessNode(node->where_expr()));

  // Get a deep copy of update_item_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedUpdateItem>> update_item_list,
      ProcessNodeList(node->update_item_list()));

  // Get deep copy of from_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> from_scan,
      ProcessNode(node->from_scan()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedUpdateStmt.
  auto copy = MakeResolvedUpdateStmt(
    std::move(table_scan),
    std::move(assert_rows_modified),
    std::move(returning),
    std::move(array_offset_column),
    std::move(where_expr),
    std::move(update_item_list),
    std::move(from_scan)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedUpdateStmt>(node, copy.get()));

  // Copy the column_access_list field explicitly because it is not a
  // constructor arg.
  copy.get()->set_column_access_list(node->column_access_list());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedMergeWhen(
    const ResolvedMergeWhen* node) {
  // Get deep copy of match_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> match_expr,
      ProcessNode(node->match_expr()));

  std::vector<ResolvedColumn> insert_column_list;
  for (int i = 0; i < node->insert_column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->insert_column_list()[i]));
    insert_column_list.push_back(elem);
  }

  // Get deep copy of insert_row field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedInsertRow> insert_row,
      ProcessNode(node->insert_row()));

  // Get a deep copy of update_item_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedUpdateItem>> update_item_list,
      ProcessNodeList(node->update_item_list()));

  // Create a mutable instance of ResolvedMergeWhen.
  auto copy = MakeResolvedMergeWhen(
    node->match_type(),
    std::move(match_expr),
    node->action_type(),
    insert_column_list,
    std::move(insert_row),
    std::move(update_item_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedMergeStmt(
    const ResolvedMergeStmt* node) {
  // Get deep copy of table_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedTableScan> table_scan,
      ProcessNode(node->table_scan()));

  // Get deep copy of from_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> from_scan,
      ProcessNode(node->from_scan()));

  // Get deep copy of merge_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> merge_expr,
      ProcessNode(node->merge_expr()));

  // Get a deep copy of when_clause_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedMergeWhen>> when_clause_list,
      ProcessNodeList(node->when_clause_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedMergeStmt.
  auto copy = MakeResolvedMergeStmt(
    std::move(table_scan),
    std::move(from_scan),
    std::move(merge_expr),
    std::move(when_clause_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedMergeStmt>(node, copy.get()));

  // Copy the column_access_list field explicitly because it is not a
  // constructor arg.
  copy.get()->set_column_access_list(node->column_access_list());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedTruncateStmt(
    const ResolvedTruncateStmt* node) {
  // Get deep copy of table_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedTableScan> table_scan,
      ProcessNode(node->table_scan()));

  // Get deep copy of where_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> where_expr,
      ProcessNode(node->where_expr()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedTruncateStmt.
  auto copy = MakeResolvedTruncateStmt(
    std::move(table_scan),
    std::move(where_expr)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedTruncateStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedObjectUnit(
    const ResolvedObjectUnit* node) {
  // Create a mutable instance of ResolvedObjectUnit.
  auto copy = MakeResolvedObjectUnit(
    node->name_path()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedPrivilege(
    const ResolvedPrivilege* node) {
  // Get a deep copy of unit_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedObjectUnit>> unit_list,
      ProcessNodeList(node->unit_list()));

  // Create a mutable instance of ResolvedPrivilege.
  auto copy = MakeResolvedPrivilege(
    node->action_type(),
    std::move(unit_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedGrantStmt(
    const ResolvedGrantStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of privilege_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedPrivilege>> privilege_list,
      ProcessNodeList(node->privilege_list()));

  // Get a deep copy of grantee_expr_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> grantee_expr_list,
      ProcessNodeList(node->grantee_expr_list()));

  // Create a mutable instance of ResolvedGrantStmt.
  auto copy = MakeResolvedGrantStmt(
    std::move(privilege_list),
    node->object_type(),
    node->name_path(),
    node->grantee_list(),
    std::move(grantee_expr_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedGrantStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedRevokeStmt(
    const ResolvedRevokeStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of privilege_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedPrivilege>> privilege_list,
      ProcessNodeList(node->privilege_list()));

  // Get a deep copy of grantee_expr_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> grantee_expr_list,
      ProcessNodeList(node->grantee_expr_list()));

  // Create a mutable instance of ResolvedRevokeStmt.
  auto copy = MakeResolvedRevokeStmt(
    std::move(privilege_list),
    node->object_type(),
    node->name_path(),
    node->grantee_list(),
    std::move(grantee_expr_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedRevokeStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterDatabaseStmt(
    const ResolvedAlterDatabaseStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of alter_action_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedAlterAction>> alter_action_list,
      ProcessNodeList(node->alter_action_list()));

  // Create a mutable instance of ResolvedAlterDatabaseStmt.
  auto copy = MakeResolvedAlterDatabaseStmt(
    node->name_path(),
    std::move(alter_action_list),
    node->is_if_exists()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAlterDatabaseStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterMaterializedViewStmt(
    const ResolvedAlterMaterializedViewStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of alter_action_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedAlterAction>> alter_action_list,
      ProcessNodeList(node->alter_action_list()));

  // Create a mutable instance of ResolvedAlterMaterializedViewStmt.
  auto copy = MakeResolvedAlterMaterializedViewStmt(
    node->name_path(),
    std::move(alter_action_list),
    node->is_if_exists()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAlterMaterializedViewStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterSchemaStmt(
    const ResolvedAlterSchemaStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of alter_action_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedAlterAction>> alter_action_list,
      ProcessNodeList(node->alter_action_list()));

  // Create a mutable instance of ResolvedAlterSchemaStmt.
  auto copy = MakeResolvedAlterSchemaStmt(
    node->name_path(),
    std::move(alter_action_list),
    node->is_if_exists()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAlterSchemaStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterTableStmt(
    const ResolvedAlterTableStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of alter_action_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedAlterAction>> alter_action_list,
      ProcessNodeList(node->alter_action_list()));

  // Create a mutable instance of ResolvedAlterTableStmt.
  auto copy = MakeResolvedAlterTableStmt(
    node->name_path(),
    std::move(alter_action_list),
    node->is_if_exists()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAlterTableStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterViewStmt(
    const ResolvedAlterViewStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of alter_action_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedAlterAction>> alter_action_list,
      ProcessNodeList(node->alter_action_list()));

  // Create a mutable instance of ResolvedAlterViewStmt.
  auto copy = MakeResolvedAlterViewStmt(
    node->name_path(),
    std::move(alter_action_list),
    node->is_if_exists()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAlterViewStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedSetOptionsAction(
    const ResolvedSetOptionsAction* node) {
  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Create a mutable instance of ResolvedSetOptionsAction.
  auto copy = MakeResolvedSetOptionsAction(
    std::move(option_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAddColumnAction(
    const ResolvedAddColumnAction* node) {
  // Get deep copy of column_definition field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedColumnDefinition> column_definition,
      ProcessNode(node->column_definition()));

  // Create a mutable instance of ResolvedAddColumnAction.
  auto copy = MakeResolvedAddColumnAction(
    node->is_if_not_exists(),
    std::move(column_definition)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAddConstraintAction(
    const ResolvedAddConstraintAction* node) {
  // Get deep copy of constraint field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedConstraint> constraint,
      ProcessNode(node->constraint()));

  // Create a mutable instance of ResolvedAddConstraintAction.
  auto copy = MakeResolvedAddConstraintAction(
    node->is_if_not_exists(),
    std::move(constraint),
    node->table()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropConstraintAction(
    const ResolvedDropConstraintAction* node) {
  // Create a mutable instance of ResolvedDropConstraintAction.
  auto copy = MakeResolvedDropConstraintAction(
    node->is_if_exists(),
    node->name()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropPrimaryKeyAction(
    const ResolvedDropPrimaryKeyAction* node) {
  // Create a mutable instance of ResolvedDropPrimaryKeyAction.
  auto copy = MakeResolvedDropPrimaryKeyAction(
    node->is_if_exists()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterColumnOptionsAction(
    const ResolvedAlterColumnOptionsAction* node) {
  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Create a mutable instance of ResolvedAlterColumnOptionsAction.
  auto copy = MakeResolvedAlterColumnOptionsAction(
    node->is_if_exists(),
    node->column(),
    std::move(option_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterColumnDropNotNullAction(
    const ResolvedAlterColumnDropNotNullAction* node) {
  // Create a mutable instance of ResolvedAlterColumnDropNotNullAction.
  auto copy = MakeResolvedAlterColumnDropNotNullAction(
    node->is_if_exists(),
    node->column()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterColumnSetDataTypeAction(
    const ResolvedAlterColumnSetDataTypeAction* node) {
  // Get deep copy of updated_annotations field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedColumnAnnotations> updated_annotations,
      ProcessNode(node->updated_annotations()));

  // Create a mutable instance of ResolvedAlterColumnSetDataTypeAction.
  auto copy = MakeResolvedAlterColumnSetDataTypeAction(
    node->is_if_exists(),
    node->column(),
    node->updated_type(),
    node->updated_type_parameters(),
    std::move(updated_annotations)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterColumnSetDefaultAction(
    const ResolvedAlterColumnSetDefaultAction* node) {
  // Get deep copy of default_value field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedColumnDefaultValue> default_value,
      ProcessNode(node->default_value()));

  // Create a mutable instance of ResolvedAlterColumnSetDefaultAction.
  auto copy = MakeResolvedAlterColumnSetDefaultAction(
    node->is_if_exists(),
    node->column(),
    std::move(default_value)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterColumnDropDefaultAction(
    const ResolvedAlterColumnDropDefaultAction* node) {
  // Create a mutable instance of ResolvedAlterColumnDropDefaultAction.
  auto copy = MakeResolvedAlterColumnDropDefaultAction(
    node->is_if_exists(),
    node->column()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropColumnAction(
    const ResolvedDropColumnAction* node) {
  // Create a mutable instance of ResolvedDropColumnAction.
  auto copy = MakeResolvedDropColumnAction(
    node->is_if_exists(),
    node->name()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedRenameColumnAction(
    const ResolvedRenameColumnAction* node) {
  // Create a mutable instance of ResolvedRenameColumnAction.
  auto copy = MakeResolvedRenameColumnAction(
    node->is_if_exists(),
    node->name(),
    node->new_name()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedSetAsAction(
    const ResolvedSetAsAction* node) {
  // Create a mutable instance of ResolvedSetAsAction.
  auto copy = MakeResolvedSetAsAction(
    node->entity_body_json(),
    node->entity_body_text()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedSetCollateClause(
    const ResolvedSetCollateClause* node) {
  // Get deep copy of collation_name field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> collation_name,
      ProcessNode(node->collation_name()));

  // Create a mutable instance of ResolvedSetCollateClause.
  auto copy = MakeResolvedSetCollateClause(
    std::move(collation_name)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterTableSetOptionsStmt(
    const ResolvedAlterTableSetOptionsStmt* node) {
  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedAlterTableSetOptionsStmt.
  auto copy = MakeResolvedAlterTableSetOptionsStmt(
    node->name_path(),
    std::move(option_list),
    node->is_if_exists()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAlterTableSetOptionsStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedRenameStmt(
    const ResolvedRenameStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedRenameStmt.
  auto copy = MakeResolvedRenameStmt(
    node->object_type(),
    node->old_name_path(),
    node->new_name_path()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedRenameStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreatePrivilegeRestrictionStmt(
    const ResolvedCreatePrivilegeRestrictionStmt* node) {
  // Get a deep copy of column_privilege_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedPrivilege>> column_privilege_list,
      ProcessNodeList(node->column_privilege_list()));

  // Get a deep copy of restrictee_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> restrictee_list,
      ProcessNodeList(node->restrictee_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedCreatePrivilegeRestrictionStmt.
  auto copy = MakeResolvedCreatePrivilegeRestrictionStmt(
    node->name_path(),
    node->create_scope(),
    node->create_mode(),
    std::move(column_privilege_list),
    node->object_type(),
    std::move(restrictee_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreatePrivilegeRestrictionStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateRowAccessPolicyStmt(
    const ResolvedCreateRowAccessPolicyStmt* node) {
  // Get a deep copy of grantee_expr_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> grantee_expr_list,
      ProcessNodeList(node->grantee_expr_list()));

  // Get deep copy of table_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedTableScan> table_scan,
      ProcessNode(node->table_scan()));

  // Get deep copy of predicate field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> predicate,
      ProcessNode(node->predicate()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedCreateRowAccessPolicyStmt.
  auto copy = MakeResolvedCreateRowAccessPolicyStmt(
    node->create_mode(),
    node->name(),
    node->target_name_path(),
    node->grantee_list(),
    std::move(grantee_expr_list),
    std::move(table_scan),
    std::move(predicate),
    node->predicate_str()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateRowAccessPolicyStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropPrivilegeRestrictionStmt(
    const ResolvedDropPrivilegeRestrictionStmt* node) {
  // Get a deep copy of column_privilege_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedPrivilege>> column_privilege_list,
      ProcessNodeList(node->column_privilege_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedDropPrivilegeRestrictionStmt.
  auto copy = MakeResolvedDropPrivilegeRestrictionStmt(
    node->object_type(),
    node->is_if_exists(),
    node->name_path(),
    std::move(column_privilege_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedDropPrivilegeRestrictionStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropRowAccessPolicyStmt(
    const ResolvedDropRowAccessPolicyStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedDropRowAccessPolicyStmt.
  auto copy = MakeResolvedDropRowAccessPolicyStmt(
    node->is_drop_all(),
    node->is_if_exists(),
    node->name(),
    node->target_name_path()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedDropRowAccessPolicyStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropSearchIndexStmt(
    const ResolvedDropSearchIndexStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedDropSearchIndexStmt.
  auto copy = MakeResolvedDropSearchIndexStmt(
    node->is_if_exists(),
    node->name(),
    node->table_name_path()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedDropSearchIndexStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedGrantToAction(
    const ResolvedGrantToAction* node) {
  // Get a deep copy of grantee_expr_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> grantee_expr_list,
      ProcessNodeList(node->grantee_expr_list()));

  // Create a mutable instance of ResolvedGrantToAction.
  auto copy = MakeResolvedGrantToAction(
    std::move(grantee_expr_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedRestrictToAction(
    const ResolvedRestrictToAction* node) {
  // Get a deep copy of restrictee_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> restrictee_list,
      ProcessNodeList(node->restrictee_list()));

  // Create a mutable instance of ResolvedRestrictToAction.
  auto copy = MakeResolvedRestrictToAction(
    std::move(restrictee_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAddToRestricteeListAction(
    const ResolvedAddToRestricteeListAction* node) {
  // Get a deep copy of restrictee_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> restrictee_list,
      ProcessNodeList(node->restrictee_list()));

  // Create a mutable instance of ResolvedAddToRestricteeListAction.
  auto copy = MakeResolvedAddToRestricteeListAction(
    node->is_if_not_exists(),
    std::move(restrictee_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedRemoveFromRestricteeListAction(
    const ResolvedRemoveFromRestricteeListAction* node) {
  // Get a deep copy of restrictee_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> restrictee_list,
      ProcessNodeList(node->restrictee_list()));

  // Create a mutable instance of ResolvedRemoveFromRestricteeListAction.
  auto copy = MakeResolvedRemoveFromRestricteeListAction(
    node->is_if_exists(),
    std::move(restrictee_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedFilterUsingAction(
    const ResolvedFilterUsingAction* node) {
  // Get deep copy of predicate field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> predicate,
      ProcessNode(node->predicate()));

  // Create a mutable instance of ResolvedFilterUsingAction.
  auto copy = MakeResolvedFilterUsingAction(
    std::move(predicate),
    node->predicate_str()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedRevokeFromAction(
    const ResolvedRevokeFromAction* node) {
  // Get a deep copy of revokee_expr_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> revokee_expr_list,
      ProcessNodeList(node->revokee_expr_list()));

  // Create a mutable instance of ResolvedRevokeFromAction.
  auto copy = MakeResolvedRevokeFromAction(
    std::move(revokee_expr_list),
    node->is_revoke_from_all()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedRenameToAction(
    const ResolvedRenameToAction* node) {
  // Create a mutable instance of ResolvedRenameToAction.
  auto copy = MakeResolvedRenameToAction(
    node->new_path()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterPrivilegeRestrictionStmt(
    const ResolvedAlterPrivilegeRestrictionStmt* node) {
  // Get a deep copy of column_privilege_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedPrivilege>> column_privilege_list,
      ProcessNodeList(node->column_privilege_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of alter_action_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedAlterAction>> alter_action_list,
      ProcessNodeList(node->alter_action_list()));

  // Create a mutable instance of ResolvedAlterPrivilegeRestrictionStmt.
  auto copy = MakeResolvedAlterPrivilegeRestrictionStmt(
    node->name_path(),
    std::move(alter_action_list),
    node->is_if_exists(),
    std::move(column_privilege_list),
    node->object_type()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAlterPrivilegeRestrictionStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterRowAccessPolicyStmt(
    const ResolvedAlterRowAccessPolicyStmt* node) {
  // Get deep copy of table_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedTableScan> table_scan,
      ProcessNode(node->table_scan()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of alter_action_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedAlterAction>> alter_action_list,
      ProcessNodeList(node->alter_action_list()));

  // Create a mutable instance of ResolvedAlterRowAccessPolicyStmt.
  auto copy = MakeResolvedAlterRowAccessPolicyStmt(
    node->name_path(),
    std::move(alter_action_list),
    node->is_if_exists(),
    node->name(),
    std::move(table_scan)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAlterRowAccessPolicyStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterAllRowAccessPoliciesStmt(
    const ResolvedAlterAllRowAccessPoliciesStmt* node) {
  // Get deep copy of table_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedTableScan> table_scan,
      ProcessNode(node->table_scan()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of alter_action_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedAlterAction>> alter_action_list,
      ProcessNodeList(node->alter_action_list()));

  // Create a mutable instance of ResolvedAlterAllRowAccessPoliciesStmt.
  auto copy = MakeResolvedAlterAllRowAccessPoliciesStmt(
    node->name_path(),
    std::move(alter_action_list),
    node->is_if_exists(),
    std::move(table_scan)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAlterAllRowAccessPoliciesStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateConstantStmt(
    const ResolvedCreateConstantStmt* node) {
  // Get deep copy of expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expr,
      ProcessNode(node->expr()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedCreateConstantStmt.
  auto copy = MakeResolvedCreateConstantStmt(
    node->name_path(),
    node->create_scope(),
    node->create_mode(),
    std::move(expr)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateConstantStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateFunctionStmt(
    const ResolvedCreateFunctionStmt* node) {
  // Get a deep copy of aggregate_expression_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedComputedColumn>> aggregate_expression_list,
      ProcessNodeList(node->aggregate_expression_list()));

  // Get deep copy of function_expression field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> function_expression,
      ProcessNode(node->function_expression()));

  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get deep copy of connection field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedConnection> connection,
      ProcessNode(node->connection()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedCreateFunctionStmt.
  auto copy = MakeResolvedCreateFunctionStmt(
    node->name_path(),
    node->create_scope(),
    node->create_mode(),
    node->has_explicit_return_type(),
    node->return_type(),
    node->argument_name_list(),
    node->signature(),
    node->is_aggregate(),
    node->language(),
    node->code(),
    std::move(aggregate_expression_list),
    std::move(function_expression),
    std::move(option_list),
    node->sql_security(),
    node->determinism_level(),
    node->is_remote(),
    std::move(connection)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateFunctionStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedArgumentDef(
    const ResolvedArgumentDef* node) {
  // Create a mutable instance of ResolvedArgumentDef.
  auto copy = MakeResolvedArgumentDef(
    node->name(),
    node->type(),
    node->argument_kind()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedArgumentRef(
    const ResolvedArgumentRef* node) {
  // Create a mutable instance of ResolvedArgumentRef.
  auto copy = MakeResolvedArgumentRef(
    node->type(),
    node->name(),
    node->argument_kind()
  );

  // Copy the type_annotation_map field explicitly because it is not a
  // constructor arg.
  copy.get()->set_type_annotation_map(node->type_annotation_map());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateTableFunctionStmt(
    const ResolvedCreateTableFunctionStmt* node) {
  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get deep copy of query field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> query,
      ProcessNode(node->query()));

  // Get a deep copy of output_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOutputColumn>> output_column_list,
      ProcessNodeList(node->output_column_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedCreateTableFunctionStmt.
  auto copy = MakeResolvedCreateTableFunctionStmt(
    node->name_path(),
    node->create_scope(),
    node->create_mode(),
    node->argument_name_list(),
    node->signature(),
    node->has_explicit_return_schema(),
    std::move(option_list),
    node->language(),
    node->code(),
    std::move(query),
    std::move(output_column_list),
    node->is_value_table(),
    node->sql_security()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateTableFunctionStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedRelationArgumentScan(
    const ResolvedRelationArgumentScan* node) {
  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedRelationArgumentScan.
  auto copy = MakeResolvedRelationArgumentScan(
    column_list,
    node->name(),
    node->is_value_table()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedRelationArgumentScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedArgumentList(
    const ResolvedArgumentList* node) {
  // Get a deep copy of arg_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedArgumentDef>> arg_list,
      ProcessNodeList(node->arg_list()));

  // Create a mutable instance of ResolvedArgumentList.
  auto copy = MakeResolvedArgumentList(
    std::move(arg_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedFunctionSignatureHolder(
    const ResolvedFunctionSignatureHolder* node) {
  // Create a mutable instance of ResolvedFunctionSignatureHolder.
  auto copy = MakeResolvedFunctionSignatureHolder(
    node->signature()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropFunctionStmt(
    const ResolvedDropFunctionStmt* node) {
  // Get deep copy of arguments field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedArgumentList> arguments,
      ProcessNode(node->arguments()));

  // Get deep copy of signature field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedFunctionSignatureHolder> signature,
      ProcessNode(node->signature()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedDropFunctionStmt.
  auto copy = MakeResolvedDropFunctionStmt(
    node->is_if_exists(),
    node->name_path(),
    std::move(arguments),
    std::move(signature)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedDropFunctionStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropTableFunctionStmt(
    const ResolvedDropTableFunctionStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedDropTableFunctionStmt.
  auto copy = MakeResolvedDropTableFunctionStmt(
    node->is_if_exists(),
    node->name_path()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedDropTableFunctionStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCallStmt(
    const ResolvedCallStmt* node) {
  // Get a deep copy of argument_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> argument_list,
      ProcessNodeList(node->argument_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedCallStmt.
  auto copy = MakeResolvedCallStmt(
    node->procedure(),
    node->signature(),
    std::move(argument_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCallStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedImportStmt(
    const ResolvedImportStmt* node) {
  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedImportStmt.
  auto copy = MakeResolvedImportStmt(
    node->import_kind(),
    node->name_path(),
    node->file_path(),
    node->alias_path(),
    node->into_alias_path(),
    std::move(option_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedImportStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedModuleStmt(
    const ResolvedModuleStmt* node) {
  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedModuleStmt.
  auto copy = MakeResolvedModuleStmt(
    node->name_path(),
    std::move(option_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedModuleStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAggregateHavingModifier(
    const ResolvedAggregateHavingModifier* node) {
  // Get deep copy of having_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> having_expr,
      ProcessNode(node->having_expr()));

  // Create a mutable instance of ResolvedAggregateHavingModifier.
  auto copy = MakeResolvedAggregateHavingModifier(
    node->kind(),
    std::move(having_expr)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateMaterializedViewStmt(
    const ResolvedCreateMaterializedViewStmt* node) {
  // Get a deep copy of column_definition_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnDefinition>> column_definition_list,
      ProcessNodeList(node->column_definition_list()));

  // Get a deep copy of partition_by_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> partition_by_list,
      ProcessNodeList(node->partition_by_list()));

  // Get a deep copy of cluster_by_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> cluster_by_list,
      ProcessNodeList(node->cluster_by_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of output_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOutputColumn>> output_column_list,
      ProcessNodeList(node->output_column_list()));

  // Get deep copy of query field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> query,
      ProcessNode(node->query()));

  // Create a mutable instance of ResolvedCreateMaterializedViewStmt.
  auto copy = MakeResolvedCreateMaterializedViewStmt(
    node->name_path(),
    node->create_scope(),
    node->create_mode(),
    std::move(option_list),
    std::move(output_column_list),
    node->has_explicit_columns(),
    std::move(query),
    node->sql(),
    node->sql_security(),
    node->is_value_table(),
    node->recursive(),
    std::move(column_definition_list),
    std::move(partition_by_list),
    std::move(cluster_by_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateMaterializedViewStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateProcedureStmt(
    const ResolvedCreateProcedureStmt* node) {
  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedCreateProcedureStmt.
  auto copy = MakeResolvedCreateProcedureStmt(
    node->name_path(),
    node->create_scope(),
    node->create_mode(),
    node->argument_name_list(),
    node->signature(),
    std::move(option_list),
    node->procedure_body()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateProcedureStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedExecuteImmediateArgument(
    const ResolvedExecuteImmediateArgument* node) {
  // Get deep copy of expression field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expression,
      ProcessNode(node->expression()));

  // Create a mutable instance of ResolvedExecuteImmediateArgument.
  auto copy = MakeResolvedExecuteImmediateArgument(
    node->name(),
    std::move(expression)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedExecuteImmediateStmt(
    const ResolvedExecuteImmediateStmt* node) {
  // Get deep copy of sql field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> sql,
      ProcessNode(node->sql()));

  // Get a deep copy of using_argument_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExecuteImmediateArgument>> using_argument_list,
      ProcessNodeList(node->using_argument_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedExecuteImmediateStmt.
  auto copy = MakeResolvedExecuteImmediateStmt(
    std::move(sql),
    node->into_identifier_list(),
    std::move(using_argument_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedExecuteImmediateStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAssignmentStmt(
    const ResolvedAssignmentStmt* node) {
  // Get deep copy of target field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> target,
      ProcessNode(node->target()));

  // Get deep copy of expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> expr,
      ProcessNode(node->expr()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedAssignmentStmt.
  auto copy = MakeResolvedAssignmentStmt(
    std::move(target),
    std::move(expr)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAssignmentStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateEntityStmt(
    const ResolvedCreateEntityStmt* node) {
  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedCreateEntityStmt.
  auto copy = MakeResolvedCreateEntityStmt(
    node->name_path(),
    node->create_scope(),
    node->create_mode(),
    node->entity_type(),
    node->entity_body_json(),
    node->entity_body_text(),
    std::move(option_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCreateEntityStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterEntityStmt(
    const ResolvedAlterEntityStmt* node) {
  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Get a deep copy of alter_action_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedAlterAction>> alter_action_list,
      ProcessNodeList(node->alter_action_list()));

  // Create a mutable instance of ResolvedAlterEntityStmt.
  auto copy = MakeResolvedAlterEntityStmt(
    node->name_path(),
    std::move(alter_action_list),
    node->is_if_exists(),
    node->entity_type()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAlterEntityStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedPivotColumn(
    const ResolvedPivotColumn* node) {
  ZETASQL_ASSIGN_OR_RETURN(
      ResolvedColumn column,
      CopyResolvedColumn(node->column()));

  // Create a mutable instance of ResolvedPivotColumn.
  auto copy = MakeResolvedPivotColumn(
    column,
    node->pivot_expr_index(),
    node->pivot_value_index()
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedPivotScan(
    const ResolvedPivotScan* node) {
  // Get deep copy of input_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> input_scan,
      ProcessNode(node->input_scan()));

  // Get a deep copy of group_by_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedComputedColumn>> group_by_list,
      ProcessNodeList(node->group_by_list()));

  // Get a deep copy of pivot_expr_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> pivot_expr_list,
      ProcessNodeList(node->pivot_expr_list()));

  // Get deep copy of for_expr field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedExpr> for_expr,
      ProcessNode(node->for_expr()));

  // Get a deep copy of pivot_value_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> pivot_value_list,
      ProcessNodeList(node->pivot_value_list()));

  // Get a deep copy of pivot_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedPivotColumn>> pivot_column_list,
      ProcessNodeList(node->pivot_column_list()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedPivotScan.
  auto copy = MakeResolvedPivotScan(
    column_list,
    std::move(input_scan),
    std::move(group_by_list),
    std::move(pivot_expr_list),
    std::move(for_expr),
    std::move(pivot_value_list),
    std::move(pivot_column_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedPivotScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedReturningClause(
    const ResolvedReturningClause* node) {
  // Get a deep copy of output_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOutputColumn>> output_column_list,
      ProcessNodeList(node->output_column_list()));

  // Get deep copy of action_column field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedColumnHolder> action_column,
      ProcessNode(node->action_column()));

  // Get a deep copy of expr_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedComputedColumn>> expr_list,
      ProcessNodeList(node->expr_list()));

  // Create a mutable instance of ResolvedReturningClause.
  auto copy = MakeResolvedReturningClause(
    std::move(output_column_list),
    std::move(action_column),
    std::move(expr_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedUnpivotArg(
    const ResolvedUnpivotArg* node) {
  // Get a deep copy of column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnRef>> column_list,
      ProcessNodeList(node->column_list()));

  // Create a mutable instance of ResolvedUnpivotArg.
  auto copy = MakeResolvedUnpivotArg(
    std::move(column_list)
  );

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedUnpivotScan(
    const ResolvedUnpivotScan* node) {
  // Get deep copy of input_scan field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> input_scan,
      ProcessNode(node->input_scan()));

  std::vector<ResolvedColumn> value_column_list;
  for (int i = 0; i < node->value_column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->value_column_list()[i]));
    value_column_list.push_back(elem);
  }

  ZETASQL_ASSIGN_OR_RETURN(
      ResolvedColumn label_column,
      CopyResolvedColumn(node->label_column()));

  // Get a deep copy of label_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedLiteral>> label_list,
      ProcessNodeList(node->label_list()));

  // Get a deep copy of unpivot_arg_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedUnpivotArg>> unpivot_arg_list,
      ProcessNodeList(node->unpivot_arg_list()));

  // Get a deep copy of projected_input_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedComputedColumn>> projected_input_column_list,
      ProcessNodeList(node->projected_input_column_list()));

  std::vector<ResolvedColumn> column_list;
  for (int i = 0; i < node->column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->column_list()[i]));
    column_list.push_back(elem);
  }

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedUnpivotScan.
  auto copy = MakeResolvedUnpivotScan(
    column_list,
    std::move(input_scan),
    value_column_list,
    label_column,
    std::move(label_list),
    std::move(unpivot_arg_list),
    std::move(projected_input_column_list),
    node->include_nulls()
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedUnpivotScan>(node, copy.get()));

  // Copy the is_ordered field explicitly because it is not a constructor arg.
  copy.get()->set_is_ordered(node->is_ordered());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedCloneDataStmt(
    const ResolvedCloneDataStmt* node) {
  // Get deep copy of target_table field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedTableScan> target_table,
      ProcessNode(node->target_table()));

  // Get deep copy of clone_from field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedScan> clone_from,
      ProcessNode(node->clone_from()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedCloneDataStmt.
  auto copy = MakeResolvedCloneDataStmt(
    std::move(target_table),
    std::move(clone_from)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedCloneDataStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedTableAndColumnInfo(
    const ResolvedTableAndColumnInfo* node) {
  // Create a mutable instance of ResolvedTableAndColumnInfo.
  auto copy = MakeResolvedTableAndColumnInfo(
    node->table()
  );

  // Copy the column_index_list field explicitly because it is not a constructor
  // arg.
  copy.get()->set_column_index_list(node->column_index_list());

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAnalyzeStmt(
    const ResolvedAnalyzeStmt* node) {
  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get a deep copy of table_and_column_index_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedTableAndColumnInfo>> table_and_column_index_list,
      ProcessNodeList(node->table_and_column_index_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedAnalyzeStmt.
  auto copy = MakeResolvedAnalyzeStmt(
    std::move(option_list),
    std::move(table_and_column_index_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAnalyzeStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

absl::Status
ResolvedASTDeepCopyVisitor::CopyVisitResolvedAuxLoadDataStmt(
    const ResolvedAuxLoadDataStmt* node) {
  // Get a deep copy of output_column_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOutputColumn>> output_column_list,
      ProcessNodeList(node->output_column_list()));

  // Get a deep copy of column_definition_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedColumnDefinition>> column_definition_list,
      ProcessNodeList(node->column_definition_list()));

  std::vector<ResolvedColumn> pseudo_column_list;
  for (int i = 0; i < node->pseudo_column_list().size(); ++i) {
    ZETASQL_ASSIGN_OR_RETURN(ResolvedColumn elem,
                     CopyResolvedColumn(node->pseudo_column_list()[i]));
    pseudo_column_list.push_back(elem);
  }

  // Get deep copy of primary_key field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedPrimaryKey> primary_key,
      ProcessNode(node->primary_key()));

  // Get a deep copy of foreign_key_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedForeignKey>> foreign_key_list,
      ProcessNodeList(node->foreign_key_list()));

  // Get a deep copy of check_constraint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedCheckConstraint>> check_constraint_list,
      ProcessNodeList(node->check_constraint_list()));

  // Get a deep copy of partition_by_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> partition_by_list,
      ProcessNodeList(node->partition_by_list()));

  // Get a deep copy of cluster_by_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedExpr>> cluster_by_list,
      ProcessNodeList(node->cluster_by_list()));

  // Get a deep copy of option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> option_list,
      ProcessNodeList(node->option_list()));

  // Get deep copy of with_partition_columns field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedWithPartitionColumns> with_partition_columns,
      ProcessNode(node->with_partition_columns()));

  // Get deep copy of connection field.
  ZETASQL_ASSIGN_OR_RETURN(
      std::unique_ptr<ResolvedConnection> connection,
      ProcessNode(node->connection()));

  // Get a deep copy of from_files_option_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> from_files_option_list,
      ProcessNodeList(node->from_files_option_list()));

  // Get a deep copy of hint_list vector.
  ZETASQL_ASSIGN_OR_RETURN(
      std::vector<std::unique_ptr<ResolvedOption>> hint_list,
      ProcessNodeList(node->hint_list()));

  // Create a mutable instance of ResolvedAuxLoadDataStmt.
  auto copy = MakeResolvedAuxLoadDataStmt(
    node->insertion_mode(),
    node->name_path(),
    std::move(output_column_list),
    std::move(column_definition_list),
    pseudo_column_list,
    std::move(primary_key),
    std::move(foreign_key_list),
    std::move(check_constraint_list),
    std::move(partition_by_list),
    std::move(cluster_by_list),
    std::move(option_list),
    std::move(with_partition_columns),
    std::move(connection),
    std::move(from_files_option_list)
  );

  // Copy the hint list explicitly because hint_list is not a constructor arg.
  // Because it is not a constructor arg, the only way to copy the value is to
  // copy it explicitly.
  ZETASQL_RETURN_IF_ERROR(CopyHintList<ResolvedAuxLoadDataStmt>(node, copy.get()));

  // Set parse location range if it was previously set, as this is not a
  // constructor arg.
  const auto parse_location = node->GetParseLocationRangeOrNULL();
  if (parse_location != nullptr) {
    copy.get()->SetParseLocationRange(*parse_location);
  }

  // Add the non-abstract node to the stack.
  PushNodeToStack(std::move(copy));
  return absl::OkStatus();
}

}  // namespace zetasql