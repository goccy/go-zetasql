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

// resolved_ast_deep_copy_visitor.h GENERATED FROM resolved_ast_deep_copy_visitor.h.template

#ifndef ZETASQL_RESOLVED_AST_RESOLVED_AST_DEEP_COPY_VISITOR_H_
#define ZETASQL_RESOLVED_AST_RESOLVED_AST_DEEP_COPY_VISITOR_H_

#include <algorithm>
#include <memory>
#include <stack>
#include <utility>
#include <vector>

#include "zetasql/base/logging.h"
#include "zetasql/resolved_ast/resolved_ast.h"
#include "zetasql/resolved_ast/resolved_ast_visitor.h"
#include "zetasql/resolved_ast/resolved_node.h"
#include "zetasql/base/ret_check.h"
#include "zetasql/base/status.h"
#include "absl/status/statusor.h"

namespace zetasql {

// This is the base class for deep-copy rewriter classes.
//
// It provides the utility functions to handle the data flow and the
// implementations for copying individual node types as well as ResolvedColumn.
// This can be subclassed to create a copy of the AST with modifications.
//
// This class uses a stack which always contains exactly one or zero elements.
// The stack is used as a holding place for a recursive-like bottom up copying
// of the AST.
//
// The stack is used for making the recursive copying work:
// 1. Each call to VisitX pushes its returned node on the stack.
// 2. The caller of VisitX (which called node->Accept()) pops the
//    returned node from the stack.
// 3. The entire copied tree is available using ConsumeRootNode() in the end.
//
// To more concretely show how the stack is used, consider this FunctionCall.
//
// +-FunctionCall(ZetaSQL:$add(INT64, INT64) -> INT64)
//   +-ColumnRef(type=INT64, column=KeyValue.Key#1)
//   +-Literal(type=INT64, value=1)
//
// In order to get a deep copy of the FunctionCall, we must get a deep copy
// of the two child nodes, since they are owned by the parent node.
// To accomplish this, we call Accept on
// each of them, triggering CopyVisitResolvedX. It is guaranteed that
// CopyVisitResolvedX must push exactly one node to the stack, so we can
// consume the deep copied node from the top of the stack. Then, we can create
// our deep copied function call by using the two consumed stack values and
// push it to the stack for it's consumer.
//
// This allows us to perform a bottom-up deep copy.
//
// At the end of each CopyVisitX method, there should be exactly one element
// on the stack -- the copied (or possibly copied/modified) version of X. If
// there was more than one element on the stack, it would imply that a copied
// value was not consumed. If there were zero elements on the stack, a consumer
// would not have any node to consume. Once the final CopyVisitX is called, it
// will remain on the stack to be consumed by ConsumeRootNode, giving a copy of
// the entire AST.
//
// A subclass can modify the copied AST by placing modified copies of nodes
// onto the stack rather than direct copies.
//
// For example, imagine that you wanted to replace the table name of all tables
// in a query from A to B. Part of this can be achieved as follows:
//
//   1. Create a subclass of ResolvedASTDeepCopyVisitor.
//   2. Override
//      absl::Status VisitResolvedTableScan(const ResolvedTableScan *node);
//   3. Instead of the default behavior of pushing a copy of the node onto the
//      stack, push a modified copy, with the desired new table name.
//
// The consumer of the node pushed to the stack will see the modified version of
// the ResolvedTableScan, and will use that in the AST instead.
//
// There are two main ways to implement the Visit methods.
//
// METHOD 1 (preferred): Use the default method to make a copy, and then
//                       mutate it as appropriate.
//
//   This is preferred because it results in simpler code, automatically calls
//   the visitor on all child nodes and stitches them in, and automatically
//   copies all other flags and modifiers to the new node, without having to
//   call the constructor directly.  This method is the most robust against
//   future changes and additions to zetasql resolved node classes.
//
//   The example uses GetUnownedTopOfStack to modify the node in place.
//   The code could also use ConsumeRootNode to pop it from the stack and then
//   use PushNodeToStack to push a replacement.
//
//   Example:
//
//     absl::Status VisitResolvedTableScan(const ResolvedTableScan* node) {
//        const zetasql::Table* replacement_table = nullptr;
//        ZETASQL_RETURN_IF_ERROR(
//          catalog_->FindTable({replacement_table_name_}, &replacement_table));
//
//        // Make a copy using the default copy method.
//        ZETASQL_RETURN_IF_ERROR(CopyVisitResolvedTableScan(node));
//
//        // Mutate it so it points at the new table instead.
//        ResolvedTableScan* scan = GetUnownedTopOfStack<ResolvedTableScan>();
//        scan->set_table(replacement_table);
//
//        return absl::OkStatus();
//      }
//
// METHOD 2: Construct a replacement node directly.
//
//   This allows constructing different node types than the original tree had.
//   Calling node constructors directly means that this code will have to be
//   updated when new fields are added to zetasql nodes.
//
//     absl::Status VisitResolvedTableScan(const ResolvedTableScan* node) {
//        const zetasql::Table* replacement_table = nullptr;
//        ZETASQL_RETURN_IF_ERROR(
//          catalog_->FindTable({replacement_table_name_}, &replacement_table));
//
//        // Push a new unique_ptr of a newly-constructed table scan onto stack.
//        PushNodeToStack(MakeResolvedTableScan(
//            node->column_list(), replacement_table));
//
//        return absl::OkStatus();
//      }
//
//   If the copied node has any child nodes, those child nodes will also
//   need to be copied.  This can be done by invoking ProcessNode on each
//   child node, or by using the default Copy method and then releasing and
//   propagating each field individually, like this:
//
//     absl::Status VisitResolvedFilterScan(const ResolvedFilterScan* node) {
//       ZETASQL_RETURN_IF_ERROR(CopyVisitResolvedFilterScan(node));
//       auto filter_scan = ConsumeTopOfStack<ResolvedFilterScan>();
//
//       // This example just copies the node and its children, without
//       // changing anything.
//       PushNodeToStack(MakeResolvedFilterScan(
//           output_columns, filter_scan->release_input_scan(),
//           filter_scan->release_filter_expr()));
//       return absl::OkStatus();
//     }
//
// In both cases, we must ensure that all fields are deep-copied and that the
// modified node is pushed onto the stack after modification.
//
// Some full examples exist in resolved_ast_deep_copy_visitor_test.cc.
//
// Nodes need not be replaced on the stack with a node of the same kind, but
// the transformation must make sense in the context of the consumer of the
// copied node.
//
// For example, in the example in resolved_ast_deep_copy_visitor_test.cc, a
// ResolvedTableScan is replaced with a ResolvedFilterScan.
//
// Invoking the ResolvedASTDeepCopyVisitor subclass:
//
// The class is used like a regular ResolvedASTVisitor. Create an instance of
// the copier and call node->Accept(&copier). The output can then be consumed
// using copier.ConsumeRootNode().
//
// Example:
//
//   DerivedDeepCopyVisitor copier;
//   analyzer_output->resolved_statement()->Accept(&copier);
//   std::unique_ptr<ResolvedNode> copied_root_node =
//       copier.ConsumeRootNode<zetasql::ResolvedNode>());
//   // Do something with copied_root_node.
//
// Returns an error on unhandled node types. Reusable as long as no errors are
// returned and ConsumeRootNode is called every time.
//
// Not thread-safe.
class ResolvedASTDeepCopyVisitor : public ResolvedASTVisitor {
 public:
  ResolvedASTDeepCopyVisitor() = default;
  ResolvedASTDeepCopyVisitor(const ResolvedASTDeepCopyVisitor&) = delete;
  ResolvedASTDeepCopyVisitor& operator=(const ResolvedASTDeepCopyVisitor&) = delete;

  // Transfers the lone-remaining node on the stack to the caller on success.
  // This node must always be the root node, as no other node consumed it.
  // Node->Accept(&copier) must be called for this to be valid. See usage
  // and example comment above.
  template <typename ResolvedNodeType>
  absl::StatusOr<std::unique_ptr<ResolvedNodeType>> ConsumeRootNode() {
    ZETASQL_RET_CHECK_EQ(1, stack_.size());
    return ConsumeTopOfStack<ResolvedNodeType>();
  }

 protected:
  // Pushes a node onto the top of the stack. Used as an easy way to pass the
  // copied or modified node from the producer to the consumer. This should
  // always be called exactly once at or near the end of VisitResolvedX methods.
  void PushNodeToStack(std::unique_ptr<ResolvedNode> node) {
    stack_.push(std::move(node));
  }

  // Returns a pointer to the node at the top of the stack. Does not transfer
  // ownership nor modify the stack.
  // The stack must be non-empty for this to be valid.
  // The top object on the stack must be an instance of 'ResolvedNodeType'
  template <typename ResolvedNodeType>
  ResolvedNodeType* GetUnownedTopOfStack() const {
    ZETASQL_DCHECK(!stack_.empty());
    if (stack_.empty() || stack_.top() == nullptr) {
      return nullptr;
    }
    if (!stack_.top()->Is<ResolvedNodeType>()) {
      // When call requires the wrong type of node, try to fail tests helpfully.
      // In production, return nullptr and hope the caller can do better than
      // crash.
      ZETASQL_LOG(DFATAL) << "Top of stack is not expected type.";
      return nullptr;
    }
    return static_cast<ResolvedNodeType*>(stack_.top().get());
  }

  // Returns a unique pointer to the top of the stack, and removes it from
  // the top of the stack.
  // The top object on the stack must be an instance of 'ResolvedNodeType'
  template <typename ResolvedNodeType>
  std::unique_ptr<ResolvedNodeType> ConsumeTopOfStack() {
    ZETASQL_DCHECK(!stack_.empty());
    if (stack_.empty()) {
      return std::unique_ptr<ResolvedNodeType>();
    }
    if (stack_.top() == nullptr) {
      stack_.pop();
      return std::unique_ptr<ResolvedNodeType>();
    }
    if (!stack_.top()->Is<ResolvedNodeType>()) {
      // When call requires the wrong type of node, try to fail tests helpfully.
      // In production, return nullptr and hope the caller can do better than
      // crash.
      ZETASQL_LOG(DFATAL) << "Top of stack is not expected type.";
      return std::unique_ptr<ResolvedNodeType>();
    }
    std::unique_ptr<ResolvedNodeType> node(
        static_cast<ResolvedNodeType*>(stack_.top().release()));
    stack_.pop();
    return node;
  }

  // Calls Visit on the node, pops the result off of the stack, and returns it.
  template <typename ResolvedNodeType>
  absl::StatusOr<std::unique_ptr<ResolvedNodeType>> ProcessNode(
      const ResolvedNodeType* node) {
    ZETASQL_DCHECK(stack_.empty());
    if (node == nullptr) {
      return std::unique_ptr<ResolvedNodeType>();
    }
    ZETASQL_RETURN_IF_ERROR(node->Accept(this));
    return ConsumeTopOfStack<ResolvedNodeType>();
  }

  // Calls ProcessNode for all nodes of a vector, and returns a new vector of the
  // processed nodes.
  template <typename ResolvedNodeType>
  absl::StatusOr<std::vector<std::unique_ptr<ResolvedNodeType>>>
  ProcessNodeList(
      const std::vector<std::unique_ptr<const ResolvedNodeType>>& node_list) {
    std::vector<std::unique_ptr<ResolvedNodeType>> output_node_list;
    output_node_list.reserve(node_list.size());
    for (const std::unique_ptr<const ResolvedNodeType>& node : node_list) {
      auto processed_node = ProcessNode<ResolvedNodeType>(node.get());
      ZETASQL_RETURN_IF_ERROR(processed_node.status());
      output_node_list.push_back(std::move(*processed_node));
    }
    return output_node_list;
  }

  // Copy a ResolvedColumn. The default behavior makes a trivial copy via the
  // copy constructor. Overrides may be necessary when a visitor needs to
  // remap columns.
  virtual absl::StatusOr<ResolvedColumn> CopyResolvedColumn(
      const ResolvedColumn& column) {
    return column;
  }

  // The following CopyVisitResolvedX functions create a deep copy of node
  // and push it onto the stack to be consumed. Given node must be non-null.
  absl::Status CopyVisitResolvedLiteral(
      const ResolvedLiteral* node);

  absl::Status CopyVisitResolvedParameter(
      const ResolvedParameter* node);

  absl::Status CopyVisitResolvedExpressionColumn(
      const ResolvedExpressionColumn* node);

  absl::Status CopyVisitResolvedColumnRef(
      const ResolvedColumnRef* node);

  absl::Status CopyVisitResolvedConstant(
      const ResolvedConstant* node);

  absl::Status CopyVisitResolvedSystemVariable(
      const ResolvedSystemVariable* node);

  absl::Status CopyVisitResolvedInlineLambda(
      const ResolvedInlineLambda* node);

  absl::Status CopyVisitResolvedFilterFieldArg(
      const ResolvedFilterFieldArg* node);

  absl::Status CopyVisitResolvedFilterField(
      const ResolvedFilterField* node);

  absl::Status CopyVisitResolvedFunctionCall(
      const ResolvedFunctionCall* node);

  absl::Status CopyVisitResolvedAggregateFunctionCall(
      const ResolvedAggregateFunctionCall* node);

  absl::Status CopyVisitResolvedAnalyticFunctionCall(
      const ResolvedAnalyticFunctionCall* node);

  absl::Status CopyVisitResolvedExtendedCastElement(
      const ResolvedExtendedCastElement* node);

  absl::Status CopyVisitResolvedExtendedCast(
      const ResolvedExtendedCast* node);

  absl::Status CopyVisitResolvedCast(
      const ResolvedCast* node);

  absl::Status CopyVisitResolvedMakeStruct(
      const ResolvedMakeStruct* node);

  absl::Status CopyVisitResolvedMakeProto(
      const ResolvedMakeProto* node);

  absl::Status CopyVisitResolvedMakeProtoField(
      const ResolvedMakeProtoField* node);

  absl::Status CopyVisitResolvedGetStructField(
      const ResolvedGetStructField* node);

  absl::Status CopyVisitResolvedGetProtoField(
      const ResolvedGetProtoField* node);

  absl::Status CopyVisitResolvedGetJsonField(
      const ResolvedGetJsonField* node);

  absl::Status CopyVisitResolvedFlatten(
      const ResolvedFlatten* node);

  absl::Status CopyVisitResolvedFlattenedArg(
      const ResolvedFlattenedArg* node);

  absl::Status CopyVisitResolvedReplaceFieldItem(
      const ResolvedReplaceFieldItem* node);

  absl::Status CopyVisitResolvedReplaceField(
      const ResolvedReplaceField* node);

  absl::Status CopyVisitResolvedSubqueryExpr(
      const ResolvedSubqueryExpr* node);

  absl::Status CopyVisitResolvedLetExpr(
      const ResolvedLetExpr* node);

  absl::Status CopyVisitResolvedModel(
      const ResolvedModel* node);

  absl::Status CopyVisitResolvedConnection(
      const ResolvedConnection* node);

  absl::Status CopyVisitResolvedDescriptor(
      const ResolvedDescriptor* node);

  absl::Status CopyVisitResolvedSingleRowScan(
      const ResolvedSingleRowScan* node);

  absl::Status CopyVisitResolvedTableScan(
      const ResolvedTableScan* node);

  absl::Status CopyVisitResolvedJoinScan(
      const ResolvedJoinScan* node);

  absl::Status CopyVisitResolvedArrayScan(
      const ResolvedArrayScan* node);

  absl::Status CopyVisitResolvedColumnHolder(
      const ResolvedColumnHolder* node);

  absl::Status CopyVisitResolvedFilterScan(
      const ResolvedFilterScan* node);

  absl::Status CopyVisitResolvedGroupingSet(
      const ResolvedGroupingSet* node);

  absl::Status CopyVisitResolvedAggregateScan(
      const ResolvedAggregateScan* node);

  absl::Status CopyVisitResolvedAnonymizedAggregateScan(
      const ResolvedAnonymizedAggregateScan* node);

  absl::Status CopyVisitResolvedSetOperationItem(
      const ResolvedSetOperationItem* node);

  absl::Status CopyVisitResolvedSetOperationScan(
      const ResolvedSetOperationScan* node);

  absl::Status CopyVisitResolvedOrderByScan(
      const ResolvedOrderByScan* node);

  absl::Status CopyVisitResolvedLimitOffsetScan(
      const ResolvedLimitOffsetScan* node);

  absl::Status CopyVisitResolvedWithRefScan(
      const ResolvedWithRefScan* node);

  absl::Status CopyVisitResolvedAnalyticScan(
      const ResolvedAnalyticScan* node);

  absl::Status CopyVisitResolvedSampleScan(
      const ResolvedSampleScan* node);

  absl::Status CopyVisitResolvedComputedColumn(
      const ResolvedComputedColumn* node);

  absl::Status CopyVisitResolvedOrderByItem(
      const ResolvedOrderByItem* node);

  absl::Status CopyVisitResolvedColumnAnnotations(
      const ResolvedColumnAnnotations* node);

  absl::Status CopyVisitResolvedGeneratedColumnInfo(
      const ResolvedGeneratedColumnInfo* node);

  absl::Status CopyVisitResolvedColumnDefaultValue(
      const ResolvedColumnDefaultValue* node);

  absl::Status CopyVisitResolvedColumnDefinition(
      const ResolvedColumnDefinition* node);

  absl::Status CopyVisitResolvedPrimaryKey(
      const ResolvedPrimaryKey* node);

  absl::Status CopyVisitResolvedForeignKey(
      const ResolvedForeignKey* node);

  absl::Status CopyVisitResolvedCheckConstraint(
      const ResolvedCheckConstraint* node);

  absl::Status CopyVisitResolvedOutputColumn(
      const ResolvedOutputColumn* node);

  absl::Status CopyVisitResolvedProjectScan(
      const ResolvedProjectScan* node);

  absl::Status CopyVisitResolvedTVFScan(
      const ResolvedTVFScan* node);

  absl::Status CopyVisitResolvedGroupRowsScan(
      const ResolvedGroupRowsScan* node);

  absl::Status CopyVisitResolvedFunctionArgument(
      const ResolvedFunctionArgument* node);

  absl::Status CopyVisitResolvedExplainStmt(
      const ResolvedExplainStmt* node);

  absl::Status CopyVisitResolvedQueryStmt(
      const ResolvedQueryStmt* node);

  absl::Status CopyVisitResolvedCreateDatabaseStmt(
      const ResolvedCreateDatabaseStmt* node);

  absl::Status CopyVisitResolvedIndexItem(
      const ResolvedIndexItem* node);

  absl::Status CopyVisitResolvedUnnestItem(
      const ResolvedUnnestItem* node);

  absl::Status CopyVisitResolvedCreateIndexStmt(
      const ResolvedCreateIndexStmt* node);

  absl::Status CopyVisitResolvedCreateSchemaStmt(
      const ResolvedCreateSchemaStmt* node);

  absl::Status CopyVisitResolvedCreateTableStmt(
      const ResolvedCreateTableStmt* node);

  absl::Status CopyVisitResolvedCreateTableAsSelectStmt(
      const ResolvedCreateTableAsSelectStmt* node);

  absl::Status CopyVisitResolvedCreateModelStmt(
      const ResolvedCreateModelStmt* node);

  absl::Status CopyVisitResolvedCreateViewStmt(
      const ResolvedCreateViewStmt* node);

  absl::Status CopyVisitResolvedWithPartitionColumns(
      const ResolvedWithPartitionColumns* node);

  absl::Status CopyVisitResolvedCreateSnapshotTableStmt(
      const ResolvedCreateSnapshotTableStmt* node);

  absl::Status CopyVisitResolvedCreateExternalTableStmt(
      const ResolvedCreateExternalTableStmt* node);

  absl::Status CopyVisitResolvedExportModelStmt(
      const ResolvedExportModelStmt* node);

  absl::Status CopyVisitResolvedExportDataStmt(
      const ResolvedExportDataStmt* node);

  absl::Status CopyVisitResolvedDefineTableStmt(
      const ResolvedDefineTableStmt* node);

  absl::Status CopyVisitResolvedDescribeStmt(
      const ResolvedDescribeStmt* node);

  absl::Status CopyVisitResolvedShowStmt(
      const ResolvedShowStmt* node);

  absl::Status CopyVisitResolvedBeginStmt(
      const ResolvedBeginStmt* node);

  absl::Status CopyVisitResolvedSetTransactionStmt(
      const ResolvedSetTransactionStmt* node);

  absl::Status CopyVisitResolvedCommitStmt(
      const ResolvedCommitStmt* node);

  absl::Status CopyVisitResolvedRollbackStmt(
      const ResolvedRollbackStmt* node);

  absl::Status CopyVisitResolvedStartBatchStmt(
      const ResolvedStartBatchStmt* node);

  absl::Status CopyVisitResolvedRunBatchStmt(
      const ResolvedRunBatchStmt* node);

  absl::Status CopyVisitResolvedAbortBatchStmt(
      const ResolvedAbortBatchStmt* node);

  absl::Status CopyVisitResolvedDropStmt(
      const ResolvedDropStmt* node);

  absl::Status CopyVisitResolvedDropMaterializedViewStmt(
      const ResolvedDropMaterializedViewStmt* node);

  absl::Status CopyVisitResolvedDropSnapshotTableStmt(
      const ResolvedDropSnapshotTableStmt* node);

  absl::Status CopyVisitResolvedRecursiveRefScan(
      const ResolvedRecursiveRefScan* node);

  absl::Status CopyVisitResolvedRecursiveScan(
      const ResolvedRecursiveScan* node);

  absl::Status CopyVisitResolvedWithScan(
      const ResolvedWithScan* node);

  absl::Status CopyVisitResolvedWithEntry(
      const ResolvedWithEntry* node);

  absl::Status CopyVisitResolvedOption(
      const ResolvedOption* node);

  absl::Status CopyVisitResolvedWindowPartitioning(
      const ResolvedWindowPartitioning* node);

  absl::Status CopyVisitResolvedWindowOrdering(
      const ResolvedWindowOrdering* node);

  absl::Status CopyVisitResolvedWindowFrame(
      const ResolvedWindowFrame* node);

  absl::Status CopyVisitResolvedAnalyticFunctionGroup(
      const ResolvedAnalyticFunctionGroup* node);

  absl::Status CopyVisitResolvedWindowFrameExpr(
      const ResolvedWindowFrameExpr* node);

  absl::Status CopyVisitResolvedDMLValue(
      const ResolvedDMLValue* node);

  absl::Status CopyVisitResolvedDMLDefault(
      const ResolvedDMLDefault* node);

  absl::Status CopyVisitResolvedAssertStmt(
      const ResolvedAssertStmt* node);

  absl::Status CopyVisitResolvedAssertRowsModified(
      const ResolvedAssertRowsModified* node);

  absl::Status CopyVisitResolvedInsertRow(
      const ResolvedInsertRow* node);

  absl::Status CopyVisitResolvedInsertStmt(
      const ResolvedInsertStmt* node);

  absl::Status CopyVisitResolvedDeleteStmt(
      const ResolvedDeleteStmt* node);

  absl::Status CopyVisitResolvedUpdateItem(
      const ResolvedUpdateItem* node);

  absl::Status CopyVisitResolvedUpdateArrayItem(
      const ResolvedUpdateArrayItem* node);

  absl::Status CopyVisitResolvedUpdateStmt(
      const ResolvedUpdateStmt* node);

  absl::Status CopyVisitResolvedMergeWhen(
      const ResolvedMergeWhen* node);

  absl::Status CopyVisitResolvedMergeStmt(
      const ResolvedMergeStmt* node);

  absl::Status CopyVisitResolvedTruncateStmt(
      const ResolvedTruncateStmt* node);

  absl::Status CopyVisitResolvedObjectUnit(
      const ResolvedObjectUnit* node);

  absl::Status CopyVisitResolvedPrivilege(
      const ResolvedPrivilege* node);

  absl::Status CopyVisitResolvedGrantStmt(
      const ResolvedGrantStmt* node);

  absl::Status CopyVisitResolvedRevokeStmt(
      const ResolvedRevokeStmt* node);

  absl::Status CopyVisitResolvedAlterDatabaseStmt(
      const ResolvedAlterDatabaseStmt* node);

  absl::Status CopyVisitResolvedAlterMaterializedViewStmt(
      const ResolvedAlterMaterializedViewStmt* node);

  absl::Status CopyVisitResolvedAlterSchemaStmt(
      const ResolvedAlterSchemaStmt* node);

  absl::Status CopyVisitResolvedAlterTableStmt(
      const ResolvedAlterTableStmt* node);

  absl::Status CopyVisitResolvedAlterViewStmt(
      const ResolvedAlterViewStmt* node);

  absl::Status CopyVisitResolvedSetOptionsAction(
      const ResolvedSetOptionsAction* node);

  absl::Status CopyVisitResolvedAddColumnAction(
      const ResolvedAddColumnAction* node);

  absl::Status CopyVisitResolvedAddConstraintAction(
      const ResolvedAddConstraintAction* node);

  absl::Status CopyVisitResolvedDropConstraintAction(
      const ResolvedDropConstraintAction* node);

  absl::Status CopyVisitResolvedDropPrimaryKeyAction(
      const ResolvedDropPrimaryKeyAction* node);

  absl::Status CopyVisitResolvedAlterColumnOptionsAction(
      const ResolvedAlterColumnOptionsAction* node);

  absl::Status CopyVisitResolvedAlterColumnDropNotNullAction(
      const ResolvedAlterColumnDropNotNullAction* node);

  absl::Status CopyVisitResolvedAlterColumnSetDataTypeAction(
      const ResolvedAlterColumnSetDataTypeAction* node);

  absl::Status CopyVisitResolvedAlterColumnSetDefaultAction(
      const ResolvedAlterColumnSetDefaultAction* node);

  absl::Status CopyVisitResolvedAlterColumnDropDefaultAction(
      const ResolvedAlterColumnDropDefaultAction* node);

  absl::Status CopyVisitResolvedDropColumnAction(
      const ResolvedDropColumnAction* node);

  absl::Status CopyVisitResolvedRenameColumnAction(
      const ResolvedRenameColumnAction* node);

  absl::Status CopyVisitResolvedSetAsAction(
      const ResolvedSetAsAction* node);

  absl::Status CopyVisitResolvedSetCollateClause(
      const ResolvedSetCollateClause* node);

  absl::Status CopyVisitResolvedAlterTableSetOptionsStmt(
      const ResolvedAlterTableSetOptionsStmt* node);

  absl::Status CopyVisitResolvedRenameStmt(
      const ResolvedRenameStmt* node);

  absl::Status CopyVisitResolvedCreatePrivilegeRestrictionStmt(
      const ResolvedCreatePrivilegeRestrictionStmt* node);

  absl::Status CopyVisitResolvedCreateRowAccessPolicyStmt(
      const ResolvedCreateRowAccessPolicyStmt* node);

  absl::Status CopyVisitResolvedDropPrivilegeRestrictionStmt(
      const ResolvedDropPrivilegeRestrictionStmt* node);

  absl::Status CopyVisitResolvedDropRowAccessPolicyStmt(
      const ResolvedDropRowAccessPolicyStmt* node);

  absl::Status CopyVisitResolvedDropSearchIndexStmt(
      const ResolvedDropSearchIndexStmt* node);

  absl::Status CopyVisitResolvedGrantToAction(
      const ResolvedGrantToAction* node);

  absl::Status CopyVisitResolvedRestrictToAction(
      const ResolvedRestrictToAction* node);

  absl::Status CopyVisitResolvedAddToRestricteeListAction(
      const ResolvedAddToRestricteeListAction* node);

  absl::Status CopyVisitResolvedRemoveFromRestricteeListAction(
      const ResolvedRemoveFromRestricteeListAction* node);

  absl::Status CopyVisitResolvedFilterUsingAction(
      const ResolvedFilterUsingAction* node);

  absl::Status CopyVisitResolvedRevokeFromAction(
      const ResolvedRevokeFromAction* node);

  absl::Status CopyVisitResolvedRenameToAction(
      const ResolvedRenameToAction* node);

  absl::Status CopyVisitResolvedAlterPrivilegeRestrictionStmt(
      const ResolvedAlterPrivilegeRestrictionStmt* node);

  absl::Status CopyVisitResolvedAlterRowAccessPolicyStmt(
      const ResolvedAlterRowAccessPolicyStmt* node);

  absl::Status CopyVisitResolvedAlterAllRowAccessPoliciesStmt(
      const ResolvedAlterAllRowAccessPoliciesStmt* node);

  absl::Status CopyVisitResolvedCreateConstantStmt(
      const ResolvedCreateConstantStmt* node);

  absl::Status CopyVisitResolvedCreateFunctionStmt(
      const ResolvedCreateFunctionStmt* node);

  absl::Status CopyVisitResolvedArgumentDef(
      const ResolvedArgumentDef* node);

  absl::Status CopyVisitResolvedArgumentRef(
      const ResolvedArgumentRef* node);

  absl::Status CopyVisitResolvedCreateTableFunctionStmt(
      const ResolvedCreateTableFunctionStmt* node);

  absl::Status CopyVisitResolvedRelationArgumentScan(
      const ResolvedRelationArgumentScan* node);

  absl::Status CopyVisitResolvedArgumentList(
      const ResolvedArgumentList* node);

  absl::Status CopyVisitResolvedFunctionSignatureHolder(
      const ResolvedFunctionSignatureHolder* node);

  absl::Status CopyVisitResolvedDropFunctionStmt(
      const ResolvedDropFunctionStmt* node);

  absl::Status CopyVisitResolvedDropTableFunctionStmt(
      const ResolvedDropTableFunctionStmt* node);

  absl::Status CopyVisitResolvedCallStmt(
      const ResolvedCallStmt* node);

  absl::Status CopyVisitResolvedImportStmt(
      const ResolvedImportStmt* node);

  absl::Status CopyVisitResolvedModuleStmt(
      const ResolvedModuleStmt* node);

  absl::Status CopyVisitResolvedAggregateHavingModifier(
      const ResolvedAggregateHavingModifier* node);

  absl::Status CopyVisitResolvedCreateMaterializedViewStmt(
      const ResolvedCreateMaterializedViewStmt* node);

  absl::Status CopyVisitResolvedCreateProcedureStmt(
      const ResolvedCreateProcedureStmt* node);

  absl::Status CopyVisitResolvedExecuteImmediateArgument(
      const ResolvedExecuteImmediateArgument* node);

  absl::Status CopyVisitResolvedExecuteImmediateStmt(
      const ResolvedExecuteImmediateStmt* node);

  absl::Status CopyVisitResolvedAssignmentStmt(
      const ResolvedAssignmentStmt* node);

  absl::Status CopyVisitResolvedCreateEntityStmt(
      const ResolvedCreateEntityStmt* node);

  absl::Status CopyVisitResolvedAlterEntityStmt(
      const ResolvedAlterEntityStmt* node);

  absl::Status CopyVisitResolvedPivotColumn(
      const ResolvedPivotColumn* node);

  absl::Status CopyVisitResolvedPivotScan(
      const ResolvedPivotScan* node);

  absl::Status CopyVisitResolvedReturningClause(
      const ResolvedReturningClause* node);

  absl::Status CopyVisitResolvedUnpivotArg(
      const ResolvedUnpivotArg* node);

  absl::Status CopyVisitResolvedUnpivotScan(
      const ResolvedUnpivotScan* node);

  absl::Status CopyVisitResolvedCloneDataStmt(
      const ResolvedCloneDataStmt* node);

  absl::Status CopyVisitResolvedTableAndColumnInfo(
      const ResolvedTableAndColumnInfo* node);

  absl::Status CopyVisitResolvedAnalyzeStmt(
      const ResolvedAnalyzeStmt* node);

  absl::Status CopyVisitResolvedAuxLoadDataStmt(
      const ResolvedAuxLoadDataStmt* node);

  absl::Status DefaultVisit(const ResolvedNode* node) override;

  // The individual visit methods for each of the node types. We will copy
  // and visit each of the nodes.
  absl::Status VisitResolvedLiteral(
      const ResolvedLiteral* node) override;

  absl::Status VisitResolvedParameter(
      const ResolvedParameter* node) override;

  absl::Status VisitResolvedExpressionColumn(
      const ResolvedExpressionColumn* node) override;

  absl::Status VisitResolvedColumnRef(
      const ResolvedColumnRef* node) override;

  absl::Status VisitResolvedConstant(
      const ResolvedConstant* node) override;

  absl::Status VisitResolvedSystemVariable(
      const ResolvedSystemVariable* node) override;

  absl::Status VisitResolvedInlineLambda(
      const ResolvedInlineLambda* node) override;

  absl::Status VisitResolvedFilterFieldArg(
      const ResolvedFilterFieldArg* node) override;

  absl::Status VisitResolvedFilterField(
      const ResolvedFilterField* node) override;

  absl::Status VisitResolvedFunctionCall(
      const ResolvedFunctionCall* node) override;

  absl::Status VisitResolvedAggregateFunctionCall(
      const ResolvedAggregateFunctionCall* node) override;

  absl::Status VisitResolvedAnalyticFunctionCall(
      const ResolvedAnalyticFunctionCall* node) override;

  absl::Status VisitResolvedExtendedCastElement(
      const ResolvedExtendedCastElement* node) override;

  absl::Status VisitResolvedExtendedCast(
      const ResolvedExtendedCast* node) override;

  absl::Status VisitResolvedCast(
      const ResolvedCast* node) override;

  absl::Status VisitResolvedMakeStruct(
      const ResolvedMakeStruct* node) override;

  absl::Status VisitResolvedMakeProto(
      const ResolvedMakeProto* node) override;

  absl::Status VisitResolvedMakeProtoField(
      const ResolvedMakeProtoField* node) override;

  absl::Status VisitResolvedGetStructField(
      const ResolvedGetStructField* node) override;

  absl::Status VisitResolvedGetProtoField(
      const ResolvedGetProtoField* node) override;

  absl::Status VisitResolvedGetJsonField(
      const ResolvedGetJsonField* node) override;

  absl::Status VisitResolvedFlatten(
      const ResolvedFlatten* node) override;

  absl::Status VisitResolvedFlattenedArg(
      const ResolvedFlattenedArg* node) override;

  absl::Status VisitResolvedReplaceFieldItem(
      const ResolvedReplaceFieldItem* node) override;

  absl::Status VisitResolvedReplaceField(
      const ResolvedReplaceField* node) override;

  absl::Status VisitResolvedSubqueryExpr(
      const ResolvedSubqueryExpr* node) override;

  absl::Status VisitResolvedLetExpr(
      const ResolvedLetExpr* node) override;

  absl::Status VisitResolvedModel(
      const ResolvedModel* node) override;

  absl::Status VisitResolvedConnection(
      const ResolvedConnection* node) override;

  absl::Status VisitResolvedDescriptor(
      const ResolvedDescriptor* node) override;

  absl::Status VisitResolvedSingleRowScan(
      const ResolvedSingleRowScan* node) override;

  absl::Status VisitResolvedTableScan(
      const ResolvedTableScan* node) override;

  absl::Status VisitResolvedJoinScan(
      const ResolvedJoinScan* node) override;

  absl::Status VisitResolvedArrayScan(
      const ResolvedArrayScan* node) override;

  absl::Status VisitResolvedColumnHolder(
      const ResolvedColumnHolder* node) override;

  absl::Status VisitResolvedFilterScan(
      const ResolvedFilterScan* node) override;

  absl::Status VisitResolvedGroupingSet(
      const ResolvedGroupingSet* node) override;

  absl::Status VisitResolvedAggregateScan(
      const ResolvedAggregateScan* node) override;

  absl::Status VisitResolvedAnonymizedAggregateScan(
      const ResolvedAnonymizedAggregateScan* node) override;

  absl::Status VisitResolvedSetOperationItem(
      const ResolvedSetOperationItem* node) override;

  absl::Status VisitResolvedSetOperationScan(
      const ResolvedSetOperationScan* node) override;

  absl::Status VisitResolvedOrderByScan(
      const ResolvedOrderByScan* node) override;

  absl::Status VisitResolvedLimitOffsetScan(
      const ResolvedLimitOffsetScan* node) override;

  absl::Status VisitResolvedWithRefScan(
      const ResolvedWithRefScan* node) override;

  absl::Status VisitResolvedAnalyticScan(
      const ResolvedAnalyticScan* node) override;

  absl::Status VisitResolvedSampleScan(
      const ResolvedSampleScan* node) override;

  absl::Status VisitResolvedComputedColumn(
      const ResolvedComputedColumn* node) override;

  absl::Status VisitResolvedOrderByItem(
      const ResolvedOrderByItem* node) override;

  absl::Status VisitResolvedColumnAnnotations(
      const ResolvedColumnAnnotations* node) override;

  absl::Status VisitResolvedGeneratedColumnInfo(
      const ResolvedGeneratedColumnInfo* node) override;

  absl::Status VisitResolvedColumnDefaultValue(
      const ResolvedColumnDefaultValue* node) override;

  absl::Status VisitResolvedColumnDefinition(
      const ResolvedColumnDefinition* node) override;

  absl::Status VisitResolvedPrimaryKey(
      const ResolvedPrimaryKey* node) override;

  absl::Status VisitResolvedForeignKey(
      const ResolvedForeignKey* node) override;

  absl::Status VisitResolvedCheckConstraint(
      const ResolvedCheckConstraint* node) override;

  absl::Status VisitResolvedOutputColumn(
      const ResolvedOutputColumn* node) override;

  absl::Status VisitResolvedProjectScan(
      const ResolvedProjectScan* node) override;

  absl::Status VisitResolvedTVFScan(
      const ResolvedTVFScan* node) override;

  absl::Status VisitResolvedGroupRowsScan(
      const ResolvedGroupRowsScan* node) override;

  absl::Status VisitResolvedFunctionArgument(
      const ResolvedFunctionArgument* node) override;

  absl::Status VisitResolvedExplainStmt(
      const ResolvedExplainStmt* node) override;

  absl::Status VisitResolvedQueryStmt(
      const ResolvedQueryStmt* node) override;

  absl::Status VisitResolvedCreateDatabaseStmt(
      const ResolvedCreateDatabaseStmt* node) override;

  absl::Status VisitResolvedIndexItem(
      const ResolvedIndexItem* node) override;

  absl::Status VisitResolvedUnnestItem(
      const ResolvedUnnestItem* node) override;

  absl::Status VisitResolvedCreateIndexStmt(
      const ResolvedCreateIndexStmt* node) override;

  absl::Status VisitResolvedCreateSchemaStmt(
      const ResolvedCreateSchemaStmt* node) override;

  absl::Status VisitResolvedCreateTableStmt(
      const ResolvedCreateTableStmt* node) override;

  absl::Status VisitResolvedCreateTableAsSelectStmt(
      const ResolvedCreateTableAsSelectStmt* node) override;

  absl::Status VisitResolvedCreateModelStmt(
      const ResolvedCreateModelStmt* node) override;

  absl::Status VisitResolvedCreateViewStmt(
      const ResolvedCreateViewStmt* node) override;

  absl::Status VisitResolvedWithPartitionColumns(
      const ResolvedWithPartitionColumns* node) override;

  absl::Status VisitResolvedCreateSnapshotTableStmt(
      const ResolvedCreateSnapshotTableStmt* node) override;

  absl::Status VisitResolvedCreateExternalTableStmt(
      const ResolvedCreateExternalTableStmt* node) override;

  absl::Status VisitResolvedExportModelStmt(
      const ResolvedExportModelStmt* node) override;

  absl::Status VisitResolvedExportDataStmt(
      const ResolvedExportDataStmt* node) override;

  absl::Status VisitResolvedDefineTableStmt(
      const ResolvedDefineTableStmt* node) override;

  absl::Status VisitResolvedDescribeStmt(
      const ResolvedDescribeStmt* node) override;

  absl::Status VisitResolvedShowStmt(
      const ResolvedShowStmt* node) override;

  absl::Status VisitResolvedBeginStmt(
      const ResolvedBeginStmt* node) override;

  absl::Status VisitResolvedSetTransactionStmt(
      const ResolvedSetTransactionStmt* node) override;

  absl::Status VisitResolvedCommitStmt(
      const ResolvedCommitStmt* node) override;

  absl::Status VisitResolvedRollbackStmt(
      const ResolvedRollbackStmt* node) override;

  absl::Status VisitResolvedStartBatchStmt(
      const ResolvedStartBatchStmt* node) override;

  absl::Status VisitResolvedRunBatchStmt(
      const ResolvedRunBatchStmt* node) override;

  absl::Status VisitResolvedAbortBatchStmt(
      const ResolvedAbortBatchStmt* node) override;

  absl::Status VisitResolvedDropStmt(
      const ResolvedDropStmt* node) override;

  absl::Status VisitResolvedDropMaterializedViewStmt(
      const ResolvedDropMaterializedViewStmt* node) override;

  absl::Status VisitResolvedDropSnapshotTableStmt(
      const ResolvedDropSnapshotTableStmt* node) override;

  absl::Status VisitResolvedRecursiveRefScan(
      const ResolvedRecursiveRefScan* node) override;

  absl::Status VisitResolvedRecursiveScan(
      const ResolvedRecursiveScan* node) override;

  absl::Status VisitResolvedWithScan(
      const ResolvedWithScan* node) override;

  absl::Status VisitResolvedWithEntry(
      const ResolvedWithEntry* node) override;

  absl::Status VisitResolvedOption(
      const ResolvedOption* node) override;

  absl::Status VisitResolvedWindowPartitioning(
      const ResolvedWindowPartitioning* node) override;

  absl::Status VisitResolvedWindowOrdering(
      const ResolvedWindowOrdering* node) override;

  absl::Status VisitResolvedWindowFrame(
      const ResolvedWindowFrame* node) override;

  absl::Status VisitResolvedAnalyticFunctionGroup(
      const ResolvedAnalyticFunctionGroup* node) override;

  absl::Status VisitResolvedWindowFrameExpr(
      const ResolvedWindowFrameExpr* node) override;

  absl::Status VisitResolvedDMLValue(
      const ResolvedDMLValue* node) override;

  absl::Status VisitResolvedDMLDefault(
      const ResolvedDMLDefault* node) override;

  absl::Status VisitResolvedAssertStmt(
      const ResolvedAssertStmt* node) override;

  absl::Status VisitResolvedAssertRowsModified(
      const ResolvedAssertRowsModified* node) override;

  absl::Status VisitResolvedInsertRow(
      const ResolvedInsertRow* node) override;

  absl::Status VisitResolvedInsertStmt(
      const ResolvedInsertStmt* node) override;

  absl::Status VisitResolvedDeleteStmt(
      const ResolvedDeleteStmt* node) override;

  absl::Status VisitResolvedUpdateItem(
      const ResolvedUpdateItem* node) override;

  absl::Status VisitResolvedUpdateArrayItem(
      const ResolvedUpdateArrayItem* node) override;

  absl::Status VisitResolvedUpdateStmt(
      const ResolvedUpdateStmt* node) override;

  absl::Status VisitResolvedMergeWhen(
      const ResolvedMergeWhen* node) override;

  absl::Status VisitResolvedMergeStmt(
      const ResolvedMergeStmt* node) override;

  absl::Status VisitResolvedTruncateStmt(
      const ResolvedTruncateStmt* node) override;

  absl::Status VisitResolvedObjectUnit(
      const ResolvedObjectUnit* node) override;

  absl::Status VisitResolvedPrivilege(
      const ResolvedPrivilege* node) override;

  absl::Status VisitResolvedGrantStmt(
      const ResolvedGrantStmt* node) override;

  absl::Status VisitResolvedRevokeStmt(
      const ResolvedRevokeStmt* node) override;

  absl::Status VisitResolvedAlterDatabaseStmt(
      const ResolvedAlterDatabaseStmt* node) override;

  absl::Status VisitResolvedAlterMaterializedViewStmt(
      const ResolvedAlterMaterializedViewStmt* node) override;

  absl::Status VisitResolvedAlterSchemaStmt(
      const ResolvedAlterSchemaStmt* node) override;

  absl::Status VisitResolvedAlterTableStmt(
      const ResolvedAlterTableStmt* node) override;

  absl::Status VisitResolvedAlterViewStmt(
      const ResolvedAlterViewStmt* node) override;

  absl::Status VisitResolvedSetOptionsAction(
      const ResolvedSetOptionsAction* node) override;

  absl::Status VisitResolvedAddColumnAction(
      const ResolvedAddColumnAction* node) override;

  absl::Status VisitResolvedAddConstraintAction(
      const ResolvedAddConstraintAction* node) override;

  absl::Status VisitResolvedDropConstraintAction(
      const ResolvedDropConstraintAction* node) override;

  absl::Status VisitResolvedDropPrimaryKeyAction(
      const ResolvedDropPrimaryKeyAction* node) override;

  absl::Status VisitResolvedAlterColumnOptionsAction(
      const ResolvedAlterColumnOptionsAction* node) override;

  absl::Status VisitResolvedAlterColumnDropNotNullAction(
      const ResolvedAlterColumnDropNotNullAction* node) override;

  absl::Status VisitResolvedAlterColumnSetDataTypeAction(
      const ResolvedAlterColumnSetDataTypeAction* node) override;

  absl::Status VisitResolvedAlterColumnSetDefaultAction(
      const ResolvedAlterColumnSetDefaultAction* node) override;

  absl::Status VisitResolvedAlterColumnDropDefaultAction(
      const ResolvedAlterColumnDropDefaultAction* node) override;

  absl::Status VisitResolvedDropColumnAction(
      const ResolvedDropColumnAction* node) override;

  absl::Status VisitResolvedRenameColumnAction(
      const ResolvedRenameColumnAction* node) override;

  absl::Status VisitResolvedSetAsAction(
      const ResolvedSetAsAction* node) override;

  absl::Status VisitResolvedSetCollateClause(
      const ResolvedSetCollateClause* node) override;

  absl::Status VisitResolvedAlterTableSetOptionsStmt(
      const ResolvedAlterTableSetOptionsStmt* node) override;

  absl::Status VisitResolvedRenameStmt(
      const ResolvedRenameStmt* node) override;

  absl::Status VisitResolvedCreatePrivilegeRestrictionStmt(
      const ResolvedCreatePrivilegeRestrictionStmt* node) override;

  absl::Status VisitResolvedCreateRowAccessPolicyStmt(
      const ResolvedCreateRowAccessPolicyStmt* node) override;

  absl::Status VisitResolvedDropPrivilegeRestrictionStmt(
      const ResolvedDropPrivilegeRestrictionStmt* node) override;

  absl::Status VisitResolvedDropRowAccessPolicyStmt(
      const ResolvedDropRowAccessPolicyStmt* node) override;

  absl::Status VisitResolvedDropSearchIndexStmt(
      const ResolvedDropSearchIndexStmt* node) override;

  absl::Status VisitResolvedGrantToAction(
      const ResolvedGrantToAction* node) override;

  absl::Status VisitResolvedRestrictToAction(
      const ResolvedRestrictToAction* node) override;

  absl::Status VisitResolvedAddToRestricteeListAction(
      const ResolvedAddToRestricteeListAction* node) override;

  absl::Status VisitResolvedRemoveFromRestricteeListAction(
      const ResolvedRemoveFromRestricteeListAction* node) override;

  absl::Status VisitResolvedFilterUsingAction(
      const ResolvedFilterUsingAction* node) override;

  absl::Status VisitResolvedRevokeFromAction(
      const ResolvedRevokeFromAction* node) override;

  absl::Status VisitResolvedRenameToAction(
      const ResolvedRenameToAction* node) override;

  absl::Status VisitResolvedAlterPrivilegeRestrictionStmt(
      const ResolvedAlterPrivilegeRestrictionStmt* node) override;

  absl::Status VisitResolvedAlterRowAccessPolicyStmt(
      const ResolvedAlterRowAccessPolicyStmt* node) override;

  absl::Status VisitResolvedAlterAllRowAccessPoliciesStmt(
      const ResolvedAlterAllRowAccessPoliciesStmt* node) override;

  absl::Status VisitResolvedCreateConstantStmt(
      const ResolvedCreateConstantStmt* node) override;

  absl::Status VisitResolvedCreateFunctionStmt(
      const ResolvedCreateFunctionStmt* node) override;

  absl::Status VisitResolvedArgumentDef(
      const ResolvedArgumentDef* node) override;

  absl::Status VisitResolvedArgumentRef(
      const ResolvedArgumentRef* node) override;

  absl::Status VisitResolvedCreateTableFunctionStmt(
      const ResolvedCreateTableFunctionStmt* node) override;

  absl::Status VisitResolvedRelationArgumentScan(
      const ResolvedRelationArgumentScan* node) override;

  absl::Status VisitResolvedArgumentList(
      const ResolvedArgumentList* node) override;

  absl::Status VisitResolvedFunctionSignatureHolder(
      const ResolvedFunctionSignatureHolder* node) override;

  absl::Status VisitResolvedDropFunctionStmt(
      const ResolvedDropFunctionStmt* node) override;

  absl::Status VisitResolvedDropTableFunctionStmt(
      const ResolvedDropTableFunctionStmt* node) override;

  absl::Status VisitResolvedCallStmt(
      const ResolvedCallStmt* node) override;

  absl::Status VisitResolvedImportStmt(
      const ResolvedImportStmt* node) override;

  absl::Status VisitResolvedModuleStmt(
      const ResolvedModuleStmt* node) override;

  absl::Status VisitResolvedAggregateHavingModifier(
      const ResolvedAggregateHavingModifier* node) override;

  absl::Status VisitResolvedCreateMaterializedViewStmt(
      const ResolvedCreateMaterializedViewStmt* node) override;

  absl::Status VisitResolvedCreateProcedureStmt(
      const ResolvedCreateProcedureStmt* node) override;

  absl::Status VisitResolvedExecuteImmediateArgument(
      const ResolvedExecuteImmediateArgument* node) override;

  absl::Status VisitResolvedExecuteImmediateStmt(
      const ResolvedExecuteImmediateStmt* node) override;

  absl::Status VisitResolvedAssignmentStmt(
      const ResolvedAssignmentStmt* node) override;

  absl::Status VisitResolvedCreateEntityStmt(
      const ResolvedCreateEntityStmt* node) override;

  absl::Status VisitResolvedAlterEntityStmt(
      const ResolvedAlterEntityStmt* node) override;

  absl::Status VisitResolvedPivotColumn(
      const ResolvedPivotColumn* node) override;

  absl::Status VisitResolvedPivotScan(
      const ResolvedPivotScan* node) override;

  absl::Status VisitResolvedReturningClause(
      const ResolvedReturningClause* node) override;

  absl::Status VisitResolvedUnpivotArg(
      const ResolvedUnpivotArg* node) override;

  absl::Status VisitResolvedUnpivotScan(
      const ResolvedUnpivotScan* node) override;

  absl::Status VisitResolvedCloneDataStmt(
      const ResolvedCloneDataStmt* node) override;

  absl::Status VisitResolvedTableAndColumnInfo(
      const ResolvedTableAndColumnInfo* node) override;

  absl::Status VisitResolvedAnalyzeStmt(
      const ResolvedAnalyzeStmt* node) override;

  absl::Status VisitResolvedAuxLoadDataStmt(
      const ResolvedAuxLoadDataStmt* node) override;

 private:
  // Copies the hint list from the original node to the copied node. This is
  // required, as hint_list is not a constructor arg, and the only way to
  // transfer ownership is to explicitly set it after constructing the copy.
  template <typename ResolvedNodeType> absl::Status CopyHintList(
      const ResolvedNodeType *from, ResolvedNodeType *to) {
    for (const std::unique_ptr<const zetasql::ResolvedOption>& hint :
        from->hint_list()) {
      ZETASQL_ASSIGN_OR_RETURN(std::unique_ptr<zetasql::ResolvedOption> copied_hint,
                       ProcessNode(hint.get()));
      to->add_hint_list(std::move(copied_hint));
    }
    return absl::OkStatus();
  }

  // Copies the WITH GROUP_ROWS parameter list from the original node to the
  // copied node. This is required, as with_group_rows_parameter_list is not a
  // constructor arg, and the only way to transfer ownership is to explicitly
  // set it after constructing the copy.
  template <typename ResolvedNodeType>
  absl::Status CopyWithGroupRowsParameterList(const ResolvedNodeType* from,
                                              ResolvedNodeType* to) {
    for (const std::unique_ptr<const ResolvedColumnRef>& param :
         from->with_group_rows_parameter_list()) {
      ZETASQL_ASSIGN_OR_RETURN(std::unique_ptr<ResolvedColumnRef> copied_ref,
                       ProcessNode(param.get()));
      to->add_with_group_rows_parameter_list(std::move(copied_ref));
    }
    return absl::OkStatus();
  }

  // The stack is used for making the recursive copying work:
  // 1. A copied node is pushed to the stack before the VisitX function returns.
  // 2. The consuming VisitX functions (the one calling node_x->Accept())
  //    takes it from the stack.
  // 3. The entire copied tree is available using ConsumeRootNode() in the end.
  std::stack<std::unique_ptr<ResolvedNode>> stack_;
};

}  // namespace zetasql

#endif  // ZETASQL_RESOLVED_AST_RESOLVED_AST_DEEP_COPY_VISITOR_H_