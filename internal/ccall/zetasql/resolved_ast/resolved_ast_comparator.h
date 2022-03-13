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

// resolved_ast_comparator.h GENERATED FROM resolved_ast_comparator.h.template
#ifndef ZETASQL_RESOLVED_AST_RESOLVED_AST_COMPARATOR_H_
#define ZETASQL_RESOLVED_AST_RESOLVED_AST_COMPARATOR_H_

#include "zetasql/resolved_ast/resolved_ast.h"
#include "zetasql/resolved_ast/resolved_node.h"
#include "zetasql/resolved_ast/resolved_column.h"
#include "absl/status/statusor.h"

namespace zetasql {

class ResolvedASTComparator {
 public:
  ResolvedASTComparator(const ResolvedASTComparator&) = delete;
  ResolvedASTComparator& operator=(const ResolvedASTComparator&) = delete;

  // Compares any two given nodes for equality. While comparing :
  // * We check the two nodes are of the same node_kind.
  // * We check the two nodes have the same structure of the tree (recursively
  //   matching the node kinds).
  // * We check for each node in the tree that all field values are equal.
  static absl::StatusOr<bool> CompareResolvedAST(const ResolvedNode* node1,
                                                 const ResolvedNode* node2);
 private:
  // Status object returned when the stack overflows.
  static absl::Status* stack_overflow_status_;

  static void InitStackOverflowStatus();

  static absl::StatusOr<bool> CompareResolvedLiteral(const ResolvedLiteral* node1,
                                                   const ResolvedLiteral* node2);
  static absl::StatusOr<bool> CompareResolvedParameter(const ResolvedParameter* node1,
                                                   const ResolvedParameter* node2);
  static absl::StatusOr<bool> CompareResolvedExpressionColumn(const ResolvedExpressionColumn* node1,
                                                   const ResolvedExpressionColumn* node2);
  static absl::StatusOr<bool> CompareResolvedColumnRef(const ResolvedColumnRef* node1,
                                                   const ResolvedColumnRef* node2);
  static absl::StatusOr<bool> CompareResolvedConstant(const ResolvedConstant* node1,
                                                   const ResolvedConstant* node2);
  static absl::StatusOr<bool> CompareResolvedSystemVariable(const ResolvedSystemVariable* node1,
                                                   const ResolvedSystemVariable* node2);
  static absl::StatusOr<bool> CompareResolvedInlineLambda(const ResolvedInlineLambda* node1,
                                                   const ResolvedInlineLambda* node2);
  static absl::StatusOr<bool> CompareResolvedFilterFieldArg(const ResolvedFilterFieldArg* node1,
                                                   const ResolvedFilterFieldArg* node2);
  static absl::StatusOr<bool> CompareResolvedFilterField(const ResolvedFilterField* node1,
                                                   const ResolvedFilterField* node2);
  static absl::StatusOr<bool> CompareResolvedFunctionCall(const ResolvedFunctionCall* node1,
                                                   const ResolvedFunctionCall* node2);
  static absl::StatusOr<bool> CompareResolvedAggregateFunctionCall(const ResolvedAggregateFunctionCall* node1,
                                                   const ResolvedAggregateFunctionCall* node2);
  static absl::StatusOr<bool> CompareResolvedAnalyticFunctionCall(const ResolvedAnalyticFunctionCall* node1,
                                                   const ResolvedAnalyticFunctionCall* node2);
  static absl::StatusOr<bool> CompareResolvedExtendedCastElement(const ResolvedExtendedCastElement* node1,
                                                   const ResolvedExtendedCastElement* node2);
  static absl::StatusOr<bool> CompareResolvedExtendedCast(const ResolvedExtendedCast* node1,
                                                   const ResolvedExtendedCast* node2);
  static absl::StatusOr<bool> CompareResolvedCast(const ResolvedCast* node1,
                                                   const ResolvedCast* node2);
  static absl::StatusOr<bool> CompareResolvedMakeStruct(const ResolvedMakeStruct* node1,
                                                   const ResolvedMakeStruct* node2);
  static absl::StatusOr<bool> CompareResolvedMakeProto(const ResolvedMakeProto* node1,
                                                   const ResolvedMakeProto* node2);
  static absl::StatusOr<bool> CompareResolvedMakeProtoField(const ResolvedMakeProtoField* node1,
                                                   const ResolvedMakeProtoField* node2);
  static absl::StatusOr<bool> CompareResolvedGetStructField(const ResolvedGetStructField* node1,
                                                   const ResolvedGetStructField* node2);
  static absl::StatusOr<bool> CompareResolvedGetProtoField(const ResolvedGetProtoField* node1,
                                                   const ResolvedGetProtoField* node2);
  static absl::StatusOr<bool> CompareResolvedGetJsonField(const ResolvedGetJsonField* node1,
                                                   const ResolvedGetJsonField* node2);
  static absl::StatusOr<bool> CompareResolvedFlatten(const ResolvedFlatten* node1,
                                                   const ResolvedFlatten* node2);
  static absl::StatusOr<bool> CompareResolvedFlattenedArg(const ResolvedFlattenedArg* node1,
                                                   const ResolvedFlattenedArg* node2);
  static absl::StatusOr<bool> CompareResolvedReplaceFieldItem(const ResolvedReplaceFieldItem* node1,
                                                   const ResolvedReplaceFieldItem* node2);
  static absl::StatusOr<bool> CompareResolvedReplaceField(const ResolvedReplaceField* node1,
                                                   const ResolvedReplaceField* node2);
  static absl::StatusOr<bool> CompareResolvedSubqueryExpr(const ResolvedSubqueryExpr* node1,
                                                   const ResolvedSubqueryExpr* node2);
  static absl::StatusOr<bool> CompareResolvedLetExpr(const ResolvedLetExpr* node1,
                                                   const ResolvedLetExpr* node2);
  static absl::StatusOr<bool> CompareResolvedModel(const ResolvedModel* node1,
                                                   const ResolvedModel* node2);
  static absl::StatusOr<bool> CompareResolvedConnection(const ResolvedConnection* node1,
                                                   const ResolvedConnection* node2);
  static absl::StatusOr<bool> CompareResolvedDescriptor(const ResolvedDescriptor* node1,
                                                   const ResolvedDescriptor* node2);
  static absl::StatusOr<bool> CompareResolvedSingleRowScan(const ResolvedSingleRowScan* node1,
                                                   const ResolvedSingleRowScan* node2);
  static absl::StatusOr<bool> CompareResolvedTableScan(const ResolvedTableScan* node1,
                                                   const ResolvedTableScan* node2);
  static absl::StatusOr<bool> CompareResolvedJoinScan(const ResolvedJoinScan* node1,
                                                   const ResolvedJoinScan* node2);
  static absl::StatusOr<bool> CompareResolvedArrayScan(const ResolvedArrayScan* node1,
                                                   const ResolvedArrayScan* node2);
  static absl::StatusOr<bool> CompareResolvedColumnHolder(const ResolvedColumnHolder* node1,
                                                   const ResolvedColumnHolder* node2);
  static absl::StatusOr<bool> CompareResolvedFilterScan(const ResolvedFilterScan* node1,
                                                   const ResolvedFilterScan* node2);
  static absl::StatusOr<bool> CompareResolvedGroupingSet(const ResolvedGroupingSet* node1,
                                                   const ResolvedGroupingSet* node2);
  static absl::StatusOr<bool> CompareResolvedAggregateScan(const ResolvedAggregateScan* node1,
                                                   const ResolvedAggregateScan* node2);
  static absl::StatusOr<bool> CompareResolvedAnonymizedAggregateScan(const ResolvedAnonymizedAggregateScan* node1,
                                                   const ResolvedAnonymizedAggregateScan* node2);
  static absl::StatusOr<bool> CompareResolvedSetOperationItem(const ResolvedSetOperationItem* node1,
                                                   const ResolvedSetOperationItem* node2);
  static absl::StatusOr<bool> CompareResolvedSetOperationScan(const ResolvedSetOperationScan* node1,
                                                   const ResolvedSetOperationScan* node2);
  static absl::StatusOr<bool> CompareResolvedOrderByScan(const ResolvedOrderByScan* node1,
                                                   const ResolvedOrderByScan* node2);
  static absl::StatusOr<bool> CompareResolvedLimitOffsetScan(const ResolvedLimitOffsetScan* node1,
                                                   const ResolvedLimitOffsetScan* node2);
  static absl::StatusOr<bool> CompareResolvedWithRefScan(const ResolvedWithRefScan* node1,
                                                   const ResolvedWithRefScan* node2);
  static absl::StatusOr<bool> CompareResolvedAnalyticScan(const ResolvedAnalyticScan* node1,
                                                   const ResolvedAnalyticScan* node2);
  static absl::StatusOr<bool> CompareResolvedSampleScan(const ResolvedSampleScan* node1,
                                                   const ResolvedSampleScan* node2);
  static absl::StatusOr<bool> CompareResolvedComputedColumn(const ResolvedComputedColumn* node1,
                                                   const ResolvedComputedColumn* node2);
  static absl::StatusOr<bool> CompareResolvedOrderByItem(const ResolvedOrderByItem* node1,
                                                   const ResolvedOrderByItem* node2);
  static absl::StatusOr<bool> CompareResolvedColumnAnnotations(const ResolvedColumnAnnotations* node1,
                                                   const ResolvedColumnAnnotations* node2);
  static absl::StatusOr<bool> CompareResolvedGeneratedColumnInfo(const ResolvedGeneratedColumnInfo* node1,
                                                   const ResolvedGeneratedColumnInfo* node2);
  static absl::StatusOr<bool> CompareResolvedColumnDefaultValue(const ResolvedColumnDefaultValue* node1,
                                                   const ResolvedColumnDefaultValue* node2);
  static absl::StatusOr<bool> CompareResolvedColumnDefinition(const ResolvedColumnDefinition* node1,
                                                   const ResolvedColumnDefinition* node2);
  static absl::StatusOr<bool> CompareResolvedPrimaryKey(const ResolvedPrimaryKey* node1,
                                                   const ResolvedPrimaryKey* node2);
  static absl::StatusOr<bool> CompareResolvedForeignKey(const ResolvedForeignKey* node1,
                                                   const ResolvedForeignKey* node2);
  static absl::StatusOr<bool> CompareResolvedCheckConstraint(const ResolvedCheckConstraint* node1,
                                                   const ResolvedCheckConstraint* node2);
  static absl::StatusOr<bool> CompareResolvedOutputColumn(const ResolvedOutputColumn* node1,
                                                   const ResolvedOutputColumn* node2);
  static absl::StatusOr<bool> CompareResolvedProjectScan(const ResolvedProjectScan* node1,
                                                   const ResolvedProjectScan* node2);
  static absl::StatusOr<bool> CompareResolvedTVFScan(const ResolvedTVFScan* node1,
                                                   const ResolvedTVFScan* node2);
  static absl::StatusOr<bool> CompareResolvedGroupRowsScan(const ResolvedGroupRowsScan* node1,
                                                   const ResolvedGroupRowsScan* node2);
  static absl::StatusOr<bool> CompareResolvedFunctionArgument(const ResolvedFunctionArgument* node1,
                                                   const ResolvedFunctionArgument* node2);
  static absl::StatusOr<bool> CompareResolvedExplainStmt(const ResolvedExplainStmt* node1,
                                                   const ResolvedExplainStmt* node2);
  static absl::StatusOr<bool> CompareResolvedQueryStmt(const ResolvedQueryStmt* node1,
                                                   const ResolvedQueryStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateDatabaseStmt(const ResolvedCreateDatabaseStmt* node1,
                                                   const ResolvedCreateDatabaseStmt* node2);
  static absl::StatusOr<bool> CompareResolvedIndexItem(const ResolvedIndexItem* node1,
                                                   const ResolvedIndexItem* node2);
  static absl::StatusOr<bool> CompareResolvedUnnestItem(const ResolvedUnnestItem* node1,
                                                   const ResolvedUnnestItem* node2);
  static absl::StatusOr<bool> CompareResolvedCreateIndexStmt(const ResolvedCreateIndexStmt* node1,
                                                   const ResolvedCreateIndexStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateSchemaStmt(const ResolvedCreateSchemaStmt* node1,
                                                   const ResolvedCreateSchemaStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateTableStmt(const ResolvedCreateTableStmt* node1,
                                                   const ResolvedCreateTableStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateTableAsSelectStmt(const ResolvedCreateTableAsSelectStmt* node1,
                                                   const ResolvedCreateTableAsSelectStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateModelStmt(const ResolvedCreateModelStmt* node1,
                                                   const ResolvedCreateModelStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateViewStmt(const ResolvedCreateViewStmt* node1,
                                                   const ResolvedCreateViewStmt* node2);
  static absl::StatusOr<bool> CompareResolvedWithPartitionColumns(const ResolvedWithPartitionColumns* node1,
                                                   const ResolvedWithPartitionColumns* node2);
  static absl::StatusOr<bool> CompareResolvedCreateSnapshotTableStmt(const ResolvedCreateSnapshotTableStmt* node1,
                                                   const ResolvedCreateSnapshotTableStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateExternalTableStmt(const ResolvedCreateExternalTableStmt* node1,
                                                   const ResolvedCreateExternalTableStmt* node2);
  static absl::StatusOr<bool> CompareResolvedExportModelStmt(const ResolvedExportModelStmt* node1,
                                                   const ResolvedExportModelStmt* node2);
  static absl::StatusOr<bool> CompareResolvedExportDataStmt(const ResolvedExportDataStmt* node1,
                                                   const ResolvedExportDataStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDefineTableStmt(const ResolvedDefineTableStmt* node1,
                                                   const ResolvedDefineTableStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDescribeStmt(const ResolvedDescribeStmt* node1,
                                                   const ResolvedDescribeStmt* node2);
  static absl::StatusOr<bool> CompareResolvedShowStmt(const ResolvedShowStmt* node1,
                                                   const ResolvedShowStmt* node2);
  static absl::StatusOr<bool> CompareResolvedBeginStmt(const ResolvedBeginStmt* node1,
                                                   const ResolvedBeginStmt* node2);
  static absl::StatusOr<bool> CompareResolvedSetTransactionStmt(const ResolvedSetTransactionStmt* node1,
                                                   const ResolvedSetTransactionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCommitStmt(const ResolvedCommitStmt* node1,
                                                   const ResolvedCommitStmt* node2);
  static absl::StatusOr<bool> CompareResolvedRollbackStmt(const ResolvedRollbackStmt* node1,
                                                   const ResolvedRollbackStmt* node2);
  static absl::StatusOr<bool> CompareResolvedStartBatchStmt(const ResolvedStartBatchStmt* node1,
                                                   const ResolvedStartBatchStmt* node2);
  static absl::StatusOr<bool> CompareResolvedRunBatchStmt(const ResolvedRunBatchStmt* node1,
                                                   const ResolvedRunBatchStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAbortBatchStmt(const ResolvedAbortBatchStmt* node1,
                                                   const ResolvedAbortBatchStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDropStmt(const ResolvedDropStmt* node1,
                                                   const ResolvedDropStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDropMaterializedViewStmt(const ResolvedDropMaterializedViewStmt* node1,
                                                   const ResolvedDropMaterializedViewStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDropSnapshotTableStmt(const ResolvedDropSnapshotTableStmt* node1,
                                                   const ResolvedDropSnapshotTableStmt* node2);
  static absl::StatusOr<bool> CompareResolvedRecursiveRefScan(const ResolvedRecursiveRefScan* node1,
                                                   const ResolvedRecursiveRefScan* node2);
  static absl::StatusOr<bool> CompareResolvedRecursiveScan(const ResolvedRecursiveScan* node1,
                                                   const ResolvedRecursiveScan* node2);
  static absl::StatusOr<bool> CompareResolvedWithScan(const ResolvedWithScan* node1,
                                                   const ResolvedWithScan* node2);
  static absl::StatusOr<bool> CompareResolvedWithEntry(const ResolvedWithEntry* node1,
                                                   const ResolvedWithEntry* node2);
  static absl::StatusOr<bool> CompareResolvedOption(const ResolvedOption* node1,
                                                   const ResolvedOption* node2);
  static absl::StatusOr<bool> CompareResolvedWindowPartitioning(const ResolvedWindowPartitioning* node1,
                                                   const ResolvedWindowPartitioning* node2);
  static absl::StatusOr<bool> CompareResolvedWindowOrdering(const ResolvedWindowOrdering* node1,
                                                   const ResolvedWindowOrdering* node2);
  static absl::StatusOr<bool> CompareResolvedWindowFrame(const ResolvedWindowFrame* node1,
                                                   const ResolvedWindowFrame* node2);
  static absl::StatusOr<bool> CompareResolvedAnalyticFunctionGroup(const ResolvedAnalyticFunctionGroup* node1,
                                                   const ResolvedAnalyticFunctionGroup* node2);
  static absl::StatusOr<bool> CompareResolvedWindowFrameExpr(const ResolvedWindowFrameExpr* node1,
                                                   const ResolvedWindowFrameExpr* node2);
  static absl::StatusOr<bool> CompareResolvedDMLValue(const ResolvedDMLValue* node1,
                                                   const ResolvedDMLValue* node2);
  static absl::StatusOr<bool> CompareResolvedDMLDefault(const ResolvedDMLDefault* node1,
                                                   const ResolvedDMLDefault* node2);
  static absl::StatusOr<bool> CompareResolvedAssertStmt(const ResolvedAssertStmt* node1,
                                                   const ResolvedAssertStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAssertRowsModified(const ResolvedAssertRowsModified* node1,
                                                   const ResolvedAssertRowsModified* node2);
  static absl::StatusOr<bool> CompareResolvedInsertRow(const ResolvedInsertRow* node1,
                                                   const ResolvedInsertRow* node2);
  static absl::StatusOr<bool> CompareResolvedInsertStmt(const ResolvedInsertStmt* node1,
                                                   const ResolvedInsertStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDeleteStmt(const ResolvedDeleteStmt* node1,
                                                   const ResolvedDeleteStmt* node2);
  static absl::StatusOr<bool> CompareResolvedUpdateItem(const ResolvedUpdateItem* node1,
                                                   const ResolvedUpdateItem* node2);
  static absl::StatusOr<bool> CompareResolvedUpdateArrayItem(const ResolvedUpdateArrayItem* node1,
                                                   const ResolvedUpdateArrayItem* node2);
  static absl::StatusOr<bool> CompareResolvedUpdateStmt(const ResolvedUpdateStmt* node1,
                                                   const ResolvedUpdateStmt* node2);
  static absl::StatusOr<bool> CompareResolvedMergeWhen(const ResolvedMergeWhen* node1,
                                                   const ResolvedMergeWhen* node2);
  static absl::StatusOr<bool> CompareResolvedMergeStmt(const ResolvedMergeStmt* node1,
                                                   const ResolvedMergeStmt* node2);
  static absl::StatusOr<bool> CompareResolvedTruncateStmt(const ResolvedTruncateStmt* node1,
                                                   const ResolvedTruncateStmt* node2);
  static absl::StatusOr<bool> CompareResolvedObjectUnit(const ResolvedObjectUnit* node1,
                                                   const ResolvedObjectUnit* node2);
  static absl::StatusOr<bool> CompareResolvedPrivilege(const ResolvedPrivilege* node1,
                                                   const ResolvedPrivilege* node2);
  static absl::StatusOr<bool> CompareResolvedGrantStmt(const ResolvedGrantStmt* node1,
                                                   const ResolvedGrantStmt* node2);
  static absl::StatusOr<bool> CompareResolvedRevokeStmt(const ResolvedRevokeStmt* node1,
                                                   const ResolvedRevokeStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterDatabaseStmt(const ResolvedAlterDatabaseStmt* node1,
                                                   const ResolvedAlterDatabaseStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterMaterializedViewStmt(const ResolvedAlterMaterializedViewStmt* node1,
                                                   const ResolvedAlterMaterializedViewStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterSchemaStmt(const ResolvedAlterSchemaStmt* node1,
                                                   const ResolvedAlterSchemaStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterTableStmt(const ResolvedAlterTableStmt* node1,
                                                   const ResolvedAlterTableStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterViewStmt(const ResolvedAlterViewStmt* node1,
                                                   const ResolvedAlterViewStmt* node2);
  static absl::StatusOr<bool> CompareResolvedSetOptionsAction(const ResolvedSetOptionsAction* node1,
                                                   const ResolvedSetOptionsAction* node2);
  static absl::StatusOr<bool> CompareResolvedAddColumnAction(const ResolvedAddColumnAction* node1,
                                                   const ResolvedAddColumnAction* node2);
  static absl::StatusOr<bool> CompareResolvedAddConstraintAction(const ResolvedAddConstraintAction* node1,
                                                   const ResolvedAddConstraintAction* node2);
  static absl::StatusOr<bool> CompareResolvedDropConstraintAction(const ResolvedDropConstraintAction* node1,
                                                   const ResolvedDropConstraintAction* node2);
  static absl::StatusOr<bool> CompareResolvedDropPrimaryKeyAction(const ResolvedDropPrimaryKeyAction* node1,
                                                   const ResolvedDropPrimaryKeyAction* node2);
  static absl::StatusOr<bool> CompareResolvedAlterColumnOptionsAction(const ResolvedAlterColumnOptionsAction* node1,
                                                   const ResolvedAlterColumnOptionsAction* node2);
  static absl::StatusOr<bool> CompareResolvedAlterColumnDropNotNullAction(const ResolvedAlterColumnDropNotNullAction* node1,
                                                   const ResolvedAlterColumnDropNotNullAction* node2);
  static absl::StatusOr<bool> CompareResolvedAlterColumnSetDataTypeAction(const ResolvedAlterColumnSetDataTypeAction* node1,
                                                   const ResolvedAlterColumnSetDataTypeAction* node2);
  static absl::StatusOr<bool> CompareResolvedAlterColumnSetDefaultAction(const ResolvedAlterColumnSetDefaultAction* node1,
                                                   const ResolvedAlterColumnSetDefaultAction* node2);
  static absl::StatusOr<bool> CompareResolvedAlterColumnDropDefaultAction(const ResolvedAlterColumnDropDefaultAction* node1,
                                                   const ResolvedAlterColumnDropDefaultAction* node2);
  static absl::StatusOr<bool> CompareResolvedDropColumnAction(const ResolvedDropColumnAction* node1,
                                                   const ResolvedDropColumnAction* node2);
  static absl::StatusOr<bool> CompareResolvedRenameColumnAction(const ResolvedRenameColumnAction* node1,
                                                   const ResolvedRenameColumnAction* node2);
  static absl::StatusOr<bool> CompareResolvedSetAsAction(const ResolvedSetAsAction* node1,
                                                   const ResolvedSetAsAction* node2);
  static absl::StatusOr<bool> CompareResolvedSetCollateClause(const ResolvedSetCollateClause* node1,
                                                   const ResolvedSetCollateClause* node2);
  static absl::StatusOr<bool> CompareResolvedAlterTableSetOptionsStmt(const ResolvedAlterTableSetOptionsStmt* node1,
                                                   const ResolvedAlterTableSetOptionsStmt* node2);
  static absl::StatusOr<bool> CompareResolvedRenameStmt(const ResolvedRenameStmt* node1,
                                                   const ResolvedRenameStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreatePrivilegeRestrictionStmt(const ResolvedCreatePrivilegeRestrictionStmt* node1,
                                                   const ResolvedCreatePrivilegeRestrictionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateRowAccessPolicyStmt(const ResolvedCreateRowAccessPolicyStmt* node1,
                                                   const ResolvedCreateRowAccessPolicyStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDropPrivilegeRestrictionStmt(const ResolvedDropPrivilegeRestrictionStmt* node1,
                                                   const ResolvedDropPrivilegeRestrictionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDropRowAccessPolicyStmt(const ResolvedDropRowAccessPolicyStmt* node1,
                                                   const ResolvedDropRowAccessPolicyStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDropSearchIndexStmt(const ResolvedDropSearchIndexStmt* node1,
                                                   const ResolvedDropSearchIndexStmt* node2);
  static absl::StatusOr<bool> CompareResolvedGrantToAction(const ResolvedGrantToAction* node1,
                                                   const ResolvedGrantToAction* node2);
  static absl::StatusOr<bool> CompareResolvedRestrictToAction(const ResolvedRestrictToAction* node1,
                                                   const ResolvedRestrictToAction* node2);
  static absl::StatusOr<bool> CompareResolvedAddToRestricteeListAction(const ResolvedAddToRestricteeListAction* node1,
                                                   const ResolvedAddToRestricteeListAction* node2);
  static absl::StatusOr<bool> CompareResolvedRemoveFromRestricteeListAction(const ResolvedRemoveFromRestricteeListAction* node1,
                                                   const ResolvedRemoveFromRestricteeListAction* node2);
  static absl::StatusOr<bool> CompareResolvedFilterUsingAction(const ResolvedFilterUsingAction* node1,
                                                   const ResolvedFilterUsingAction* node2);
  static absl::StatusOr<bool> CompareResolvedRevokeFromAction(const ResolvedRevokeFromAction* node1,
                                                   const ResolvedRevokeFromAction* node2);
  static absl::StatusOr<bool> CompareResolvedRenameToAction(const ResolvedRenameToAction* node1,
                                                   const ResolvedRenameToAction* node2);
  static absl::StatusOr<bool> CompareResolvedAlterPrivilegeRestrictionStmt(const ResolvedAlterPrivilegeRestrictionStmt* node1,
                                                   const ResolvedAlterPrivilegeRestrictionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterRowAccessPolicyStmt(const ResolvedAlterRowAccessPolicyStmt* node1,
                                                   const ResolvedAlterRowAccessPolicyStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterAllRowAccessPoliciesStmt(const ResolvedAlterAllRowAccessPoliciesStmt* node1,
                                                   const ResolvedAlterAllRowAccessPoliciesStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateConstantStmt(const ResolvedCreateConstantStmt* node1,
                                                   const ResolvedCreateConstantStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateFunctionStmt(const ResolvedCreateFunctionStmt* node1,
                                                   const ResolvedCreateFunctionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedArgumentDef(const ResolvedArgumentDef* node1,
                                                   const ResolvedArgumentDef* node2);
  static absl::StatusOr<bool> CompareResolvedArgumentRef(const ResolvedArgumentRef* node1,
                                                   const ResolvedArgumentRef* node2);
  static absl::StatusOr<bool> CompareResolvedCreateTableFunctionStmt(const ResolvedCreateTableFunctionStmt* node1,
                                                   const ResolvedCreateTableFunctionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedRelationArgumentScan(const ResolvedRelationArgumentScan* node1,
                                                   const ResolvedRelationArgumentScan* node2);
  static absl::StatusOr<bool> CompareResolvedArgumentList(const ResolvedArgumentList* node1,
                                                   const ResolvedArgumentList* node2);
  static absl::StatusOr<bool> CompareResolvedFunctionSignatureHolder(const ResolvedFunctionSignatureHolder* node1,
                                                   const ResolvedFunctionSignatureHolder* node2);
  static absl::StatusOr<bool> CompareResolvedDropFunctionStmt(const ResolvedDropFunctionStmt* node1,
                                                   const ResolvedDropFunctionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDropTableFunctionStmt(const ResolvedDropTableFunctionStmt* node1,
                                                   const ResolvedDropTableFunctionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCallStmt(const ResolvedCallStmt* node1,
                                                   const ResolvedCallStmt* node2);
  static absl::StatusOr<bool> CompareResolvedImportStmt(const ResolvedImportStmt* node1,
                                                   const ResolvedImportStmt* node2);
  static absl::StatusOr<bool> CompareResolvedModuleStmt(const ResolvedModuleStmt* node1,
                                                   const ResolvedModuleStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAggregateHavingModifier(const ResolvedAggregateHavingModifier* node1,
                                                   const ResolvedAggregateHavingModifier* node2);
  static absl::StatusOr<bool> CompareResolvedCreateMaterializedViewStmt(const ResolvedCreateMaterializedViewStmt* node1,
                                                   const ResolvedCreateMaterializedViewStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateProcedureStmt(const ResolvedCreateProcedureStmt* node1,
                                                   const ResolvedCreateProcedureStmt* node2);
  static absl::StatusOr<bool> CompareResolvedExecuteImmediateArgument(const ResolvedExecuteImmediateArgument* node1,
                                                   const ResolvedExecuteImmediateArgument* node2);
  static absl::StatusOr<bool> CompareResolvedExecuteImmediateStmt(const ResolvedExecuteImmediateStmt* node1,
                                                   const ResolvedExecuteImmediateStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAssignmentStmt(const ResolvedAssignmentStmt* node1,
                                                   const ResolvedAssignmentStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateEntityStmt(const ResolvedCreateEntityStmt* node1,
                                                   const ResolvedCreateEntityStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterEntityStmt(const ResolvedAlterEntityStmt* node1,
                                                   const ResolvedAlterEntityStmt* node2);
  static absl::StatusOr<bool> CompareResolvedPivotColumn(const ResolvedPivotColumn* node1,
                                                   const ResolvedPivotColumn* node2);
  static absl::StatusOr<bool> CompareResolvedPivotScan(const ResolvedPivotScan* node1,
                                                   const ResolvedPivotScan* node2);
  static absl::StatusOr<bool> CompareResolvedReturningClause(const ResolvedReturningClause* node1,
                                                   const ResolvedReturningClause* node2);
  static absl::StatusOr<bool> CompareResolvedUnpivotArg(const ResolvedUnpivotArg* node1,
                                                   const ResolvedUnpivotArg* node2);
  static absl::StatusOr<bool> CompareResolvedUnpivotScan(const ResolvedUnpivotScan* node1,
                                                   const ResolvedUnpivotScan* node2);
  static absl::StatusOr<bool> CompareResolvedCloneDataStmt(const ResolvedCloneDataStmt* node1,
                                                   const ResolvedCloneDataStmt* node2);
  static absl::StatusOr<bool> CompareResolvedTableAndColumnInfo(const ResolvedTableAndColumnInfo* node1,
                                                   const ResolvedTableAndColumnInfo* node2);
  static absl::StatusOr<bool> CompareResolvedAnalyzeStmt(const ResolvedAnalyzeStmt* node1,
                                                   const ResolvedAnalyzeStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAuxLoadDataStmt(const ResolvedAuxLoadDataStmt* node1,
                                                   const ResolvedAuxLoadDataStmt* node2);
};

}  // namespace zetasql

#endif  // ZETASQL_RESOLVED_AST_RESOLVED_AST_COMPARATOR_H_