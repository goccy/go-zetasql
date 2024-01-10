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

// resolved_ast_visitor.h GENERATED FROM resolved_ast_visitor.h.template
#ifndef ZETASQL_RESOLVED_AST_RESOLVED_AST_VISITOR_H_
#define ZETASQL_RESOLVED_AST_RESOLVED_AST_VISITOR_H_

#include "zetasql/resolved_ast/resolved_ast.h"
#include "zetasql/resolved_ast/resolved_node.h"
#include "zetasql/resolved_ast/resolved_column.h"
#include "zetasql/base/status.h"

namespace zetasql {

class ResolvedASTVisitor {
 public:
  ResolvedASTVisitor() {}
  ResolvedASTVisitor(const ResolvedASTVisitor&) = delete;
  ResolvedASTVisitor& operator=(const ResolvedASTVisitor&) = delete;
  virtual ~ResolvedASTVisitor() {}

  // This is the default visit method called for any node that doesn't have an
  // override for the node specific Visit... method.
  // Users may want to override this to change traversal order, give errors on
  // unhandled nodes or stop traversing after errors.
  //
  // The default implementation just visits the child nodes recursively.
  // Children of a node are visited in an undefined order.
  virtual absl::Status DefaultVisit(const ResolvedNode* node) {
    return node->ChildrenAccept(this);
  }

  virtual absl::Status VisitResolvedArgument(const ResolvedArgument* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedExpr(const ResolvedExpr* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedLiteral(const ResolvedLiteral* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedParameter(const ResolvedParameter* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedExpressionColumn(const ResolvedExpressionColumn* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedColumnRef(const ResolvedColumnRef* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedConstant(const ResolvedConstant* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedSystemVariable(const ResolvedSystemVariable* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedInlineLambda(const ResolvedInlineLambda* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedFilterFieldArg(const ResolvedFilterFieldArg* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedFilterField(const ResolvedFilterField* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedFunctionCallBase(const ResolvedFunctionCallBase* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedFunctionCall(const ResolvedFunctionCall* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedNonScalarFunctionCallBase(const ResolvedNonScalarFunctionCallBase* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAggregateFunctionCall(const ResolvedAggregateFunctionCall* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAnalyticFunctionCall(const ResolvedAnalyticFunctionCall* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedExtendedCastElement(const ResolvedExtendedCastElement* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedExtendedCast(const ResolvedExtendedCast* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCast(const ResolvedCast* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedMakeStruct(const ResolvedMakeStruct* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedMakeProto(const ResolvedMakeProto* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedMakeProtoField(const ResolvedMakeProtoField* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedGetStructField(const ResolvedGetStructField* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedGetProtoField(const ResolvedGetProtoField* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedGetJsonField(const ResolvedGetJsonField* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedFlatten(const ResolvedFlatten* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedFlattenedArg(const ResolvedFlattenedArg* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedReplaceFieldItem(const ResolvedReplaceFieldItem* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedReplaceField(const ResolvedReplaceField* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedSubqueryExpr(const ResolvedSubqueryExpr* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedLetExpr(const ResolvedLetExpr* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedScan(const ResolvedScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedModel(const ResolvedModel* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedConnection(const ResolvedConnection* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDescriptor(const ResolvedDescriptor* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedSingleRowScan(const ResolvedSingleRowScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedTableScan(const ResolvedTableScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedJoinScan(const ResolvedJoinScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedArrayScan(const ResolvedArrayScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedColumnHolder(const ResolvedColumnHolder* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedFilterScan(const ResolvedFilterScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedGroupingSet(const ResolvedGroupingSet* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAggregateScanBase(const ResolvedAggregateScanBase* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAggregateScan(const ResolvedAggregateScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAnonymizedAggregateScan(const ResolvedAnonymizedAggregateScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedSetOperationItem(const ResolvedSetOperationItem* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedSetOperationScan(const ResolvedSetOperationScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedOrderByScan(const ResolvedOrderByScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedLimitOffsetScan(const ResolvedLimitOffsetScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedWithRefScan(const ResolvedWithRefScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAnalyticScan(const ResolvedAnalyticScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedSampleScan(const ResolvedSampleScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedComputedColumn(const ResolvedComputedColumn* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedOrderByItem(const ResolvedOrderByItem* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedColumnAnnotations(const ResolvedColumnAnnotations* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedGeneratedColumnInfo(const ResolvedGeneratedColumnInfo* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedColumnDefaultValue(const ResolvedColumnDefaultValue* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedColumnDefinition(const ResolvedColumnDefinition* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedConstraint(const ResolvedConstraint* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedPrimaryKey(const ResolvedPrimaryKey* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedForeignKey(const ResolvedForeignKey* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCheckConstraint(const ResolvedCheckConstraint* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedOutputColumn(const ResolvedOutputColumn* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedProjectScan(const ResolvedProjectScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedTVFScan(const ResolvedTVFScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedGroupRowsScan(const ResolvedGroupRowsScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedFunctionArgument(const ResolvedFunctionArgument* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedStatement(const ResolvedStatement* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedExplainStmt(const ResolvedExplainStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedQueryStmt(const ResolvedQueryStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateDatabaseStmt(const ResolvedCreateDatabaseStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateStatement(const ResolvedCreateStatement* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedIndexItem(const ResolvedIndexItem* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedUnnestItem(const ResolvedUnnestItem* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateIndexStmt(const ResolvedCreateIndexStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateSchemaStmt(const ResolvedCreateSchemaStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateTableStmtBase(const ResolvedCreateTableStmtBase* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateTableStmt(const ResolvedCreateTableStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateTableAsSelectStmt(const ResolvedCreateTableAsSelectStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateModelStmt(const ResolvedCreateModelStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateViewBase(const ResolvedCreateViewBase* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateViewStmt(const ResolvedCreateViewStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedWithPartitionColumns(const ResolvedWithPartitionColumns* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateSnapshotTableStmt(const ResolvedCreateSnapshotTableStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateExternalTableStmt(const ResolvedCreateExternalTableStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedExportModelStmt(const ResolvedExportModelStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedExportDataStmt(const ResolvedExportDataStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDefineTableStmt(const ResolvedDefineTableStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDescribeStmt(const ResolvedDescribeStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedShowStmt(const ResolvedShowStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedBeginStmt(const ResolvedBeginStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedSetTransactionStmt(const ResolvedSetTransactionStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCommitStmt(const ResolvedCommitStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedRollbackStmt(const ResolvedRollbackStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedStartBatchStmt(const ResolvedStartBatchStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedRunBatchStmt(const ResolvedRunBatchStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAbortBatchStmt(const ResolvedAbortBatchStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDropStmt(const ResolvedDropStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDropMaterializedViewStmt(const ResolvedDropMaterializedViewStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDropSnapshotTableStmt(const ResolvedDropSnapshotTableStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedRecursiveRefScan(const ResolvedRecursiveRefScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedRecursiveScan(const ResolvedRecursiveScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedWithScan(const ResolvedWithScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedWithEntry(const ResolvedWithEntry* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedOption(const ResolvedOption* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedWindowPartitioning(const ResolvedWindowPartitioning* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedWindowOrdering(const ResolvedWindowOrdering* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedWindowFrame(const ResolvedWindowFrame* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAnalyticFunctionGroup(const ResolvedAnalyticFunctionGroup* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedWindowFrameExpr(const ResolvedWindowFrameExpr* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDMLValue(const ResolvedDMLValue* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDMLDefault(const ResolvedDMLDefault* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAssertStmt(const ResolvedAssertStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAssertRowsModified(const ResolvedAssertRowsModified* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedInsertRow(const ResolvedInsertRow* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedInsertStmt(const ResolvedInsertStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDeleteStmt(const ResolvedDeleteStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedUpdateItem(const ResolvedUpdateItem* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedUpdateArrayItem(const ResolvedUpdateArrayItem* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedUpdateStmt(const ResolvedUpdateStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedMergeWhen(const ResolvedMergeWhen* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedMergeStmt(const ResolvedMergeStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedTruncateStmt(const ResolvedTruncateStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedObjectUnit(const ResolvedObjectUnit* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedPrivilege(const ResolvedPrivilege* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedGrantOrRevokeStmt(const ResolvedGrantOrRevokeStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedGrantStmt(const ResolvedGrantStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedRevokeStmt(const ResolvedRevokeStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterObjectStmt(const ResolvedAlterObjectStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterDatabaseStmt(const ResolvedAlterDatabaseStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterMaterializedViewStmt(const ResolvedAlterMaterializedViewStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterSchemaStmt(const ResolvedAlterSchemaStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterTableStmt(const ResolvedAlterTableStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterViewStmt(const ResolvedAlterViewStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterAction(const ResolvedAlterAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterColumnAction(const ResolvedAlterColumnAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedSetOptionsAction(const ResolvedSetOptionsAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAddColumnAction(const ResolvedAddColumnAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAddConstraintAction(const ResolvedAddConstraintAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDropConstraintAction(const ResolvedDropConstraintAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDropPrimaryKeyAction(const ResolvedDropPrimaryKeyAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterColumnOptionsAction(const ResolvedAlterColumnOptionsAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterColumnDropNotNullAction(const ResolvedAlterColumnDropNotNullAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterColumnSetDataTypeAction(const ResolvedAlterColumnSetDataTypeAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterColumnSetDefaultAction(const ResolvedAlterColumnSetDefaultAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterColumnDropDefaultAction(const ResolvedAlterColumnDropDefaultAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDropColumnAction(const ResolvedDropColumnAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedRenameColumnAction(const ResolvedRenameColumnAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedSetAsAction(const ResolvedSetAsAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedSetCollateClause(const ResolvedSetCollateClause* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterTableSetOptionsStmt(const ResolvedAlterTableSetOptionsStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedRenameStmt(const ResolvedRenameStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreatePrivilegeRestrictionStmt(const ResolvedCreatePrivilegeRestrictionStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateRowAccessPolicyStmt(const ResolvedCreateRowAccessPolicyStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDropPrivilegeRestrictionStmt(const ResolvedDropPrivilegeRestrictionStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDropRowAccessPolicyStmt(const ResolvedDropRowAccessPolicyStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDropSearchIndexStmt(const ResolvedDropSearchIndexStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedGrantToAction(const ResolvedGrantToAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedRestrictToAction(const ResolvedRestrictToAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAddToRestricteeListAction(const ResolvedAddToRestricteeListAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedRemoveFromRestricteeListAction(const ResolvedRemoveFromRestricteeListAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedFilterUsingAction(const ResolvedFilterUsingAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedRevokeFromAction(const ResolvedRevokeFromAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedRenameToAction(const ResolvedRenameToAction* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterPrivilegeRestrictionStmt(const ResolvedAlterPrivilegeRestrictionStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterRowAccessPolicyStmt(const ResolvedAlterRowAccessPolicyStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterAllRowAccessPoliciesStmt(const ResolvedAlterAllRowAccessPoliciesStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateConstantStmt(const ResolvedCreateConstantStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateFunctionStmt(const ResolvedCreateFunctionStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedArgumentDef(const ResolvedArgumentDef* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedArgumentRef(const ResolvedArgumentRef* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateTableFunctionStmt(const ResolvedCreateTableFunctionStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedRelationArgumentScan(const ResolvedRelationArgumentScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedArgumentList(const ResolvedArgumentList* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedFunctionSignatureHolder(const ResolvedFunctionSignatureHolder* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDropFunctionStmt(const ResolvedDropFunctionStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedDropTableFunctionStmt(const ResolvedDropTableFunctionStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCallStmt(const ResolvedCallStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedImportStmt(const ResolvedImportStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedModuleStmt(const ResolvedModuleStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAggregateHavingModifier(const ResolvedAggregateHavingModifier* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateMaterializedViewStmt(const ResolvedCreateMaterializedViewStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateProcedureStmt(const ResolvedCreateProcedureStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedExecuteImmediateArgument(const ResolvedExecuteImmediateArgument* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedExecuteImmediateStmt(const ResolvedExecuteImmediateStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAssignmentStmt(const ResolvedAssignmentStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCreateEntityStmt(const ResolvedCreateEntityStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAlterEntityStmt(const ResolvedAlterEntityStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedPivotColumn(const ResolvedPivotColumn* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedPivotScan(const ResolvedPivotScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedReturningClause(const ResolvedReturningClause* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedUnpivotArg(const ResolvedUnpivotArg* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedUnpivotScan(const ResolvedUnpivotScan* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedCloneDataStmt(const ResolvedCloneDataStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedTableAndColumnInfo(const ResolvedTableAndColumnInfo* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAnalyzeStmt(const ResolvedAnalyzeStmt* node) {
    return DefaultVisit(node);
  }
  virtual absl::Status VisitResolvedAuxLoadDataStmt(const ResolvedAuxLoadDataStmt* node) {
    return DefaultVisit(node);
  }
};

}  // namespace zetasql

#endif  // ZETASQL_RESOLVED_AST_RESOLVED_AST_VISITOR_H_