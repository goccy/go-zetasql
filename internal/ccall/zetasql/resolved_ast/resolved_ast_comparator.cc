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

// resolved_ast_comparator.cc GENERATED FROM resolved_ast_comparator.cc.template
#include "zetasql/resolved_ast/resolved_ast_comparator.h"

#include "zetasql/base/logging.h"
#include "google/protobuf/descriptor.h"
#include "zetasql/common/errors.h"
#include "zetasql/public/catalog.h"

namespace zetasql {

namespace {

// Overloads for Equals to compare two node fields of scalar type.
static bool Equals(const std::string& str1, const std::string& str2) {
  return zetasql_base::CaseEqual(str1, str2);
}

static bool Equals(const Type* type1, const Type* type2) {
  return type1->Equals(type2);
}

static bool Equals(const Constant* constant1, const Constant* constant2) {
  // FullName() identifies the full path name of the constant, including its
  // containing catalog names, so two constants in different (sub)catalogs with
  // the same name will have different full names and therefore compare not
  // equal.
  return zetasql_base::CaseEqual(constant1->FullName(), constant2->FullName());
}

static bool Equals(const FunctionSignature& sig1,
                   const FunctionSignature& sig2) {
  return zetasql_base::CaseEqual(sig1.DebugString(), sig2.DebugString());
}

static bool Equals(const std::shared_ptr<ResolvedFunctionCallInfo>& info1,
                   const std::shared_ptr<ResolvedFunctionCallInfo>& info2) {
  if (info1 == nullptr || info2 == nullptr) {
    return (info1 == nullptr) == (info2 == nullptr);
  }
  return zetasql_base::CaseEqual(info1->DebugString(), info2->DebugString());
}

static bool Equals(const Value& val1, const Value& val2) {
  return val1.Equals(val2);
}

static bool Equals(const Function* f1, const Function* f2) {
  // For now, we only compare function names.  If/when we have new use
  // cases, we may want to compare additional things.
  return zetasql_base::CaseEqual(f1->Name(), f2->Name());
}

static bool Equals(const Table* t1, const Table* t2) {
  // For now, we only compare table names.  If/when we have new use
  // cases, we may want to compare additional things.
  return zetasql_base::CaseEqual(t1->Name(), t2->Name());
}

static bool Equals(const google::protobuf::FieldDescriptor* f1,
                   const google::protobuf::FieldDescriptor* f2) {
  return f1->full_name() == f2->full_name() &&
      f1->type_name() == f2->type_name() &&
      f1->number() == f2->number() /* tag number */;
}

static bool Equals(const TypeParameters& tp1, const TypeParameters& tp2) {
  return tp1.Equals(tp2);
}

template <typename T>
static bool Equals(T arg1, T arg2) {
  return arg1 == arg2;
}

}  // namespace

absl::Status* ResolvedASTComparator::stack_overflow_status_ =
    new absl::Status(
        absl::StatusCode::kResourceExhausted,
        "Out of stack space due to deeply nested query expressions when"
        " comparing");

absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAST(
    const ResolvedNode* node1, const ResolvedNode* node2) {
  if (node1 == nullptr && node2 == nullptr) return true;
  if (node1 == nullptr || node2 == nullptr) return false;
  if (node1->node_kind() != node2->node_kind()) return false;

  switch (node1->node_kind()) {
    case RESOLVED_LITERAL:
      return CompareResolvedLiteral(node1->GetAs<ResolvedLiteral>(),
                                   node2->GetAs<ResolvedLiteral>());
    case RESOLVED_PARAMETER:
      return CompareResolvedParameter(node1->GetAs<ResolvedParameter>(),
                                   node2->GetAs<ResolvedParameter>());
    case RESOLVED_EXPRESSION_COLUMN:
      return CompareResolvedExpressionColumn(node1->GetAs<ResolvedExpressionColumn>(),
                                   node2->GetAs<ResolvedExpressionColumn>());
    case RESOLVED_COLUMN_REF:
      return CompareResolvedColumnRef(node1->GetAs<ResolvedColumnRef>(),
                                   node2->GetAs<ResolvedColumnRef>());
    case RESOLVED_CONSTANT:
      return CompareResolvedConstant(node1->GetAs<ResolvedConstant>(),
                                   node2->GetAs<ResolvedConstant>());
    case RESOLVED_SYSTEM_VARIABLE:
      return CompareResolvedSystemVariable(node1->GetAs<ResolvedSystemVariable>(),
                                   node2->GetAs<ResolvedSystemVariable>());
    case RESOLVED_INLINE_LAMBDA:
      return CompareResolvedInlineLambda(node1->GetAs<ResolvedInlineLambda>(),
                                   node2->GetAs<ResolvedInlineLambda>());
    case RESOLVED_FILTER_FIELD_ARG:
      return CompareResolvedFilterFieldArg(node1->GetAs<ResolvedFilterFieldArg>(),
                                   node2->GetAs<ResolvedFilterFieldArg>());
    case RESOLVED_FILTER_FIELD:
      return CompareResolvedFilterField(node1->GetAs<ResolvedFilterField>(),
                                   node2->GetAs<ResolvedFilterField>());
    case RESOLVED_FUNCTION_CALL:
      return CompareResolvedFunctionCall(node1->GetAs<ResolvedFunctionCall>(),
                                   node2->GetAs<ResolvedFunctionCall>());
    case RESOLVED_AGGREGATE_FUNCTION_CALL:
      return CompareResolvedAggregateFunctionCall(node1->GetAs<ResolvedAggregateFunctionCall>(),
                                   node2->GetAs<ResolvedAggregateFunctionCall>());
    case RESOLVED_ANALYTIC_FUNCTION_CALL:
      return CompareResolvedAnalyticFunctionCall(node1->GetAs<ResolvedAnalyticFunctionCall>(),
                                   node2->GetAs<ResolvedAnalyticFunctionCall>());
    case RESOLVED_EXTENDED_CAST_ELEMENT:
      return CompareResolvedExtendedCastElement(node1->GetAs<ResolvedExtendedCastElement>(),
                                   node2->GetAs<ResolvedExtendedCastElement>());
    case RESOLVED_EXTENDED_CAST:
      return CompareResolvedExtendedCast(node1->GetAs<ResolvedExtendedCast>(),
                                   node2->GetAs<ResolvedExtendedCast>());
    case RESOLVED_CAST:
      return CompareResolvedCast(node1->GetAs<ResolvedCast>(),
                                   node2->GetAs<ResolvedCast>());
    case RESOLVED_MAKE_STRUCT:
      return CompareResolvedMakeStruct(node1->GetAs<ResolvedMakeStruct>(),
                                   node2->GetAs<ResolvedMakeStruct>());
    case RESOLVED_MAKE_PROTO:
      return CompareResolvedMakeProto(node1->GetAs<ResolvedMakeProto>(),
                                   node2->GetAs<ResolvedMakeProto>());
    case RESOLVED_MAKE_PROTO_FIELD:
      return CompareResolvedMakeProtoField(node1->GetAs<ResolvedMakeProtoField>(),
                                   node2->GetAs<ResolvedMakeProtoField>());
    case RESOLVED_GET_STRUCT_FIELD:
      return CompareResolvedGetStructField(node1->GetAs<ResolvedGetStructField>(),
                                   node2->GetAs<ResolvedGetStructField>());
    case RESOLVED_GET_PROTO_FIELD:
      return CompareResolvedGetProtoField(node1->GetAs<ResolvedGetProtoField>(),
                                   node2->GetAs<ResolvedGetProtoField>());
    case RESOLVED_GET_JSON_FIELD:
      return CompareResolvedGetJsonField(node1->GetAs<ResolvedGetJsonField>(),
                                   node2->GetAs<ResolvedGetJsonField>());
    case RESOLVED_FLATTEN:
      return CompareResolvedFlatten(node1->GetAs<ResolvedFlatten>(),
                                   node2->GetAs<ResolvedFlatten>());
    case RESOLVED_FLATTENED_ARG:
      return CompareResolvedFlattenedArg(node1->GetAs<ResolvedFlattenedArg>(),
                                   node2->GetAs<ResolvedFlattenedArg>());
    case RESOLVED_REPLACE_FIELD_ITEM:
      return CompareResolvedReplaceFieldItem(node1->GetAs<ResolvedReplaceFieldItem>(),
                                   node2->GetAs<ResolvedReplaceFieldItem>());
    case RESOLVED_REPLACE_FIELD:
      return CompareResolvedReplaceField(node1->GetAs<ResolvedReplaceField>(),
                                   node2->GetAs<ResolvedReplaceField>());
    case RESOLVED_SUBQUERY_EXPR:
      return CompareResolvedSubqueryExpr(node1->GetAs<ResolvedSubqueryExpr>(),
                                   node2->GetAs<ResolvedSubqueryExpr>());
    case RESOLVED_LET_EXPR:
      return CompareResolvedLetExpr(node1->GetAs<ResolvedLetExpr>(),
                                   node2->GetAs<ResolvedLetExpr>());
    case RESOLVED_MODEL:
      return CompareResolvedModel(node1->GetAs<ResolvedModel>(),
                                   node2->GetAs<ResolvedModel>());
    case RESOLVED_CONNECTION:
      return CompareResolvedConnection(node1->GetAs<ResolvedConnection>(),
                                   node2->GetAs<ResolvedConnection>());
    case RESOLVED_DESCRIPTOR:
      return CompareResolvedDescriptor(node1->GetAs<ResolvedDescriptor>(),
                                   node2->GetAs<ResolvedDescriptor>());
    case RESOLVED_SINGLE_ROW_SCAN:
      return CompareResolvedSingleRowScan(node1->GetAs<ResolvedSingleRowScan>(),
                                   node2->GetAs<ResolvedSingleRowScan>());
    case RESOLVED_TABLE_SCAN:
      return CompareResolvedTableScan(node1->GetAs<ResolvedTableScan>(),
                                   node2->GetAs<ResolvedTableScan>());
    case RESOLVED_JOIN_SCAN:
      return CompareResolvedJoinScan(node1->GetAs<ResolvedJoinScan>(),
                                   node2->GetAs<ResolvedJoinScan>());
    case RESOLVED_ARRAY_SCAN:
      return CompareResolvedArrayScan(node1->GetAs<ResolvedArrayScan>(),
                                   node2->GetAs<ResolvedArrayScan>());
    case RESOLVED_COLUMN_HOLDER:
      return CompareResolvedColumnHolder(node1->GetAs<ResolvedColumnHolder>(),
                                   node2->GetAs<ResolvedColumnHolder>());
    case RESOLVED_FILTER_SCAN:
      return CompareResolvedFilterScan(node1->GetAs<ResolvedFilterScan>(),
                                   node2->GetAs<ResolvedFilterScan>());
    case RESOLVED_GROUPING_SET:
      return CompareResolvedGroupingSet(node1->GetAs<ResolvedGroupingSet>(),
                                   node2->GetAs<ResolvedGroupingSet>());
    case RESOLVED_AGGREGATE_SCAN:
      return CompareResolvedAggregateScan(node1->GetAs<ResolvedAggregateScan>(),
                                   node2->GetAs<ResolvedAggregateScan>());
    case RESOLVED_ANONYMIZED_AGGREGATE_SCAN:
      return CompareResolvedAnonymizedAggregateScan(node1->GetAs<ResolvedAnonymizedAggregateScan>(),
                                   node2->GetAs<ResolvedAnonymizedAggregateScan>());
    case RESOLVED_SET_OPERATION_ITEM:
      return CompareResolvedSetOperationItem(node1->GetAs<ResolvedSetOperationItem>(),
                                   node2->GetAs<ResolvedSetOperationItem>());
    case RESOLVED_SET_OPERATION_SCAN:
      return CompareResolvedSetOperationScan(node1->GetAs<ResolvedSetOperationScan>(),
                                   node2->GetAs<ResolvedSetOperationScan>());
    case RESOLVED_ORDER_BY_SCAN:
      return CompareResolvedOrderByScan(node1->GetAs<ResolvedOrderByScan>(),
                                   node2->GetAs<ResolvedOrderByScan>());
    case RESOLVED_LIMIT_OFFSET_SCAN:
      return CompareResolvedLimitOffsetScan(node1->GetAs<ResolvedLimitOffsetScan>(),
                                   node2->GetAs<ResolvedLimitOffsetScan>());
    case RESOLVED_WITH_REF_SCAN:
      return CompareResolvedWithRefScan(node1->GetAs<ResolvedWithRefScan>(),
                                   node2->GetAs<ResolvedWithRefScan>());
    case RESOLVED_ANALYTIC_SCAN:
      return CompareResolvedAnalyticScan(node1->GetAs<ResolvedAnalyticScan>(),
                                   node2->GetAs<ResolvedAnalyticScan>());
    case RESOLVED_SAMPLE_SCAN:
      return CompareResolvedSampleScan(node1->GetAs<ResolvedSampleScan>(),
                                   node2->GetAs<ResolvedSampleScan>());
    case RESOLVED_COMPUTED_COLUMN:
      return CompareResolvedComputedColumn(node1->GetAs<ResolvedComputedColumn>(),
                                   node2->GetAs<ResolvedComputedColumn>());
    case RESOLVED_ORDER_BY_ITEM:
      return CompareResolvedOrderByItem(node1->GetAs<ResolvedOrderByItem>(),
                                   node2->GetAs<ResolvedOrderByItem>());
    case RESOLVED_COLUMN_ANNOTATIONS:
      return CompareResolvedColumnAnnotations(node1->GetAs<ResolvedColumnAnnotations>(),
                                   node2->GetAs<ResolvedColumnAnnotations>());
    case RESOLVED_GENERATED_COLUMN_INFO:
      return CompareResolvedGeneratedColumnInfo(node1->GetAs<ResolvedGeneratedColumnInfo>(),
                                   node2->GetAs<ResolvedGeneratedColumnInfo>());
    case RESOLVED_COLUMN_DEFAULT_VALUE:
      return CompareResolvedColumnDefaultValue(node1->GetAs<ResolvedColumnDefaultValue>(),
                                   node2->GetAs<ResolvedColumnDefaultValue>());
    case RESOLVED_COLUMN_DEFINITION:
      return CompareResolvedColumnDefinition(node1->GetAs<ResolvedColumnDefinition>(),
                                   node2->GetAs<ResolvedColumnDefinition>());
    case RESOLVED_PRIMARY_KEY:
      return CompareResolvedPrimaryKey(node1->GetAs<ResolvedPrimaryKey>(),
                                   node2->GetAs<ResolvedPrimaryKey>());
    case RESOLVED_FOREIGN_KEY:
      return CompareResolvedForeignKey(node1->GetAs<ResolvedForeignKey>(),
                                   node2->GetAs<ResolvedForeignKey>());
    case RESOLVED_CHECK_CONSTRAINT:
      return CompareResolvedCheckConstraint(node1->GetAs<ResolvedCheckConstraint>(),
                                   node2->GetAs<ResolvedCheckConstraint>());
    case RESOLVED_OUTPUT_COLUMN:
      return CompareResolvedOutputColumn(node1->GetAs<ResolvedOutputColumn>(),
                                   node2->GetAs<ResolvedOutputColumn>());
    case RESOLVED_PROJECT_SCAN:
      return CompareResolvedProjectScan(node1->GetAs<ResolvedProjectScan>(),
                                   node2->GetAs<ResolvedProjectScan>());
    case RESOLVED_TVFSCAN:
      return CompareResolvedTVFScan(node1->GetAs<ResolvedTVFScan>(),
                                   node2->GetAs<ResolvedTVFScan>());
    case RESOLVED_GROUP_ROWS_SCAN:
      return CompareResolvedGroupRowsScan(node1->GetAs<ResolvedGroupRowsScan>(),
                                   node2->GetAs<ResolvedGroupRowsScan>());
    case RESOLVED_FUNCTION_ARGUMENT:
      return CompareResolvedFunctionArgument(node1->GetAs<ResolvedFunctionArgument>(),
                                   node2->GetAs<ResolvedFunctionArgument>());
    case RESOLVED_EXPLAIN_STMT:
      return CompareResolvedExplainStmt(node1->GetAs<ResolvedExplainStmt>(),
                                   node2->GetAs<ResolvedExplainStmt>());
    case RESOLVED_QUERY_STMT:
      return CompareResolvedQueryStmt(node1->GetAs<ResolvedQueryStmt>(),
                                   node2->GetAs<ResolvedQueryStmt>());
    case RESOLVED_CREATE_DATABASE_STMT:
      return CompareResolvedCreateDatabaseStmt(node1->GetAs<ResolvedCreateDatabaseStmt>(),
                                   node2->GetAs<ResolvedCreateDatabaseStmt>());
    case RESOLVED_INDEX_ITEM:
      return CompareResolvedIndexItem(node1->GetAs<ResolvedIndexItem>(),
                                   node2->GetAs<ResolvedIndexItem>());
    case RESOLVED_UNNEST_ITEM:
      return CompareResolvedUnnestItem(node1->GetAs<ResolvedUnnestItem>(),
                                   node2->GetAs<ResolvedUnnestItem>());
    case RESOLVED_CREATE_INDEX_STMT:
      return CompareResolvedCreateIndexStmt(node1->GetAs<ResolvedCreateIndexStmt>(),
                                   node2->GetAs<ResolvedCreateIndexStmt>());
    case RESOLVED_CREATE_SCHEMA_STMT:
      return CompareResolvedCreateSchemaStmt(node1->GetAs<ResolvedCreateSchemaStmt>(),
                                   node2->GetAs<ResolvedCreateSchemaStmt>());
    case RESOLVED_CREATE_TABLE_STMT:
      return CompareResolvedCreateTableStmt(node1->GetAs<ResolvedCreateTableStmt>(),
                                   node2->GetAs<ResolvedCreateTableStmt>());
    case RESOLVED_CREATE_TABLE_AS_SELECT_STMT:
      return CompareResolvedCreateTableAsSelectStmt(node1->GetAs<ResolvedCreateTableAsSelectStmt>(),
                                   node2->GetAs<ResolvedCreateTableAsSelectStmt>());
    case RESOLVED_CREATE_MODEL_STMT:
      return CompareResolvedCreateModelStmt(node1->GetAs<ResolvedCreateModelStmt>(),
                                   node2->GetAs<ResolvedCreateModelStmt>());
    case RESOLVED_CREATE_VIEW_STMT:
      return CompareResolvedCreateViewStmt(node1->GetAs<ResolvedCreateViewStmt>(),
                                   node2->GetAs<ResolvedCreateViewStmt>());
    case RESOLVED_WITH_PARTITION_COLUMNS:
      return CompareResolvedWithPartitionColumns(node1->GetAs<ResolvedWithPartitionColumns>(),
                                   node2->GetAs<ResolvedWithPartitionColumns>());
    case RESOLVED_CREATE_SNAPSHOT_TABLE_STMT:
      return CompareResolvedCreateSnapshotTableStmt(node1->GetAs<ResolvedCreateSnapshotTableStmt>(),
                                   node2->GetAs<ResolvedCreateSnapshotTableStmt>());
    case RESOLVED_CREATE_EXTERNAL_TABLE_STMT:
      return CompareResolvedCreateExternalTableStmt(node1->GetAs<ResolvedCreateExternalTableStmt>(),
                                   node2->GetAs<ResolvedCreateExternalTableStmt>());
    case RESOLVED_EXPORT_MODEL_STMT:
      return CompareResolvedExportModelStmt(node1->GetAs<ResolvedExportModelStmt>(),
                                   node2->GetAs<ResolvedExportModelStmt>());
    case RESOLVED_EXPORT_DATA_STMT:
      return CompareResolvedExportDataStmt(node1->GetAs<ResolvedExportDataStmt>(),
                                   node2->GetAs<ResolvedExportDataStmt>());
    case RESOLVED_DEFINE_TABLE_STMT:
      return CompareResolvedDefineTableStmt(node1->GetAs<ResolvedDefineTableStmt>(),
                                   node2->GetAs<ResolvedDefineTableStmt>());
    case RESOLVED_DESCRIBE_STMT:
      return CompareResolvedDescribeStmt(node1->GetAs<ResolvedDescribeStmt>(),
                                   node2->GetAs<ResolvedDescribeStmt>());
    case RESOLVED_SHOW_STMT:
      return CompareResolvedShowStmt(node1->GetAs<ResolvedShowStmt>(),
                                   node2->GetAs<ResolvedShowStmt>());
    case RESOLVED_BEGIN_STMT:
      return CompareResolvedBeginStmt(node1->GetAs<ResolvedBeginStmt>(),
                                   node2->GetAs<ResolvedBeginStmt>());
    case RESOLVED_SET_TRANSACTION_STMT:
      return CompareResolvedSetTransactionStmt(node1->GetAs<ResolvedSetTransactionStmt>(),
                                   node2->GetAs<ResolvedSetTransactionStmt>());
    case RESOLVED_COMMIT_STMT:
      return CompareResolvedCommitStmt(node1->GetAs<ResolvedCommitStmt>(),
                                   node2->GetAs<ResolvedCommitStmt>());
    case RESOLVED_ROLLBACK_STMT:
      return CompareResolvedRollbackStmt(node1->GetAs<ResolvedRollbackStmt>(),
                                   node2->GetAs<ResolvedRollbackStmt>());
    case RESOLVED_START_BATCH_STMT:
      return CompareResolvedStartBatchStmt(node1->GetAs<ResolvedStartBatchStmt>(),
                                   node2->GetAs<ResolvedStartBatchStmt>());
    case RESOLVED_RUN_BATCH_STMT:
      return CompareResolvedRunBatchStmt(node1->GetAs<ResolvedRunBatchStmt>(),
                                   node2->GetAs<ResolvedRunBatchStmt>());
    case RESOLVED_ABORT_BATCH_STMT:
      return CompareResolvedAbortBatchStmt(node1->GetAs<ResolvedAbortBatchStmt>(),
                                   node2->GetAs<ResolvedAbortBatchStmt>());
    case RESOLVED_DROP_STMT:
      return CompareResolvedDropStmt(node1->GetAs<ResolvedDropStmt>(),
                                   node2->GetAs<ResolvedDropStmt>());
    case RESOLVED_DROP_MATERIALIZED_VIEW_STMT:
      return CompareResolvedDropMaterializedViewStmt(node1->GetAs<ResolvedDropMaterializedViewStmt>(),
                                   node2->GetAs<ResolvedDropMaterializedViewStmt>());
    case RESOLVED_DROP_SNAPSHOT_TABLE_STMT:
      return CompareResolvedDropSnapshotTableStmt(node1->GetAs<ResolvedDropSnapshotTableStmt>(),
                                   node2->GetAs<ResolvedDropSnapshotTableStmt>());
    case RESOLVED_RECURSIVE_REF_SCAN:
      return CompareResolvedRecursiveRefScan(node1->GetAs<ResolvedRecursiveRefScan>(),
                                   node2->GetAs<ResolvedRecursiveRefScan>());
    case RESOLVED_RECURSIVE_SCAN:
      return CompareResolvedRecursiveScan(node1->GetAs<ResolvedRecursiveScan>(),
                                   node2->GetAs<ResolvedRecursiveScan>());
    case RESOLVED_WITH_SCAN:
      return CompareResolvedWithScan(node1->GetAs<ResolvedWithScan>(),
                                   node2->GetAs<ResolvedWithScan>());
    case RESOLVED_WITH_ENTRY:
      return CompareResolvedWithEntry(node1->GetAs<ResolvedWithEntry>(),
                                   node2->GetAs<ResolvedWithEntry>());
    case RESOLVED_OPTION:
      return CompareResolvedOption(node1->GetAs<ResolvedOption>(),
                                   node2->GetAs<ResolvedOption>());
    case RESOLVED_WINDOW_PARTITIONING:
      return CompareResolvedWindowPartitioning(node1->GetAs<ResolvedWindowPartitioning>(),
                                   node2->GetAs<ResolvedWindowPartitioning>());
    case RESOLVED_WINDOW_ORDERING:
      return CompareResolvedWindowOrdering(node1->GetAs<ResolvedWindowOrdering>(),
                                   node2->GetAs<ResolvedWindowOrdering>());
    case RESOLVED_WINDOW_FRAME:
      return CompareResolvedWindowFrame(node1->GetAs<ResolvedWindowFrame>(),
                                   node2->GetAs<ResolvedWindowFrame>());
    case RESOLVED_ANALYTIC_FUNCTION_GROUP:
      return CompareResolvedAnalyticFunctionGroup(node1->GetAs<ResolvedAnalyticFunctionGroup>(),
                                   node2->GetAs<ResolvedAnalyticFunctionGroup>());
    case RESOLVED_WINDOW_FRAME_EXPR:
      return CompareResolvedWindowFrameExpr(node1->GetAs<ResolvedWindowFrameExpr>(),
                                   node2->GetAs<ResolvedWindowFrameExpr>());
    case RESOLVED_DMLVALUE:
      return CompareResolvedDMLValue(node1->GetAs<ResolvedDMLValue>(),
                                   node2->GetAs<ResolvedDMLValue>());
    case RESOLVED_DMLDEFAULT:
      return CompareResolvedDMLDefault(node1->GetAs<ResolvedDMLDefault>(),
                                   node2->GetAs<ResolvedDMLDefault>());
    case RESOLVED_ASSERT_STMT:
      return CompareResolvedAssertStmt(node1->GetAs<ResolvedAssertStmt>(),
                                   node2->GetAs<ResolvedAssertStmt>());
    case RESOLVED_ASSERT_ROWS_MODIFIED:
      return CompareResolvedAssertRowsModified(node1->GetAs<ResolvedAssertRowsModified>(),
                                   node2->GetAs<ResolvedAssertRowsModified>());
    case RESOLVED_INSERT_ROW:
      return CompareResolvedInsertRow(node1->GetAs<ResolvedInsertRow>(),
                                   node2->GetAs<ResolvedInsertRow>());
    case RESOLVED_INSERT_STMT:
      return CompareResolvedInsertStmt(node1->GetAs<ResolvedInsertStmt>(),
                                   node2->GetAs<ResolvedInsertStmt>());
    case RESOLVED_DELETE_STMT:
      return CompareResolvedDeleteStmt(node1->GetAs<ResolvedDeleteStmt>(),
                                   node2->GetAs<ResolvedDeleteStmt>());
    case RESOLVED_UPDATE_ITEM:
      return CompareResolvedUpdateItem(node1->GetAs<ResolvedUpdateItem>(),
                                   node2->GetAs<ResolvedUpdateItem>());
    case RESOLVED_UPDATE_ARRAY_ITEM:
      return CompareResolvedUpdateArrayItem(node1->GetAs<ResolvedUpdateArrayItem>(),
                                   node2->GetAs<ResolvedUpdateArrayItem>());
    case RESOLVED_UPDATE_STMT:
      return CompareResolvedUpdateStmt(node1->GetAs<ResolvedUpdateStmt>(),
                                   node2->GetAs<ResolvedUpdateStmt>());
    case RESOLVED_MERGE_WHEN:
      return CompareResolvedMergeWhen(node1->GetAs<ResolvedMergeWhen>(),
                                   node2->GetAs<ResolvedMergeWhen>());
    case RESOLVED_MERGE_STMT:
      return CompareResolvedMergeStmt(node1->GetAs<ResolvedMergeStmt>(),
                                   node2->GetAs<ResolvedMergeStmt>());
    case RESOLVED_TRUNCATE_STMT:
      return CompareResolvedTruncateStmt(node1->GetAs<ResolvedTruncateStmt>(),
                                   node2->GetAs<ResolvedTruncateStmt>());
    case RESOLVED_OBJECT_UNIT:
      return CompareResolvedObjectUnit(node1->GetAs<ResolvedObjectUnit>(),
                                   node2->GetAs<ResolvedObjectUnit>());
    case RESOLVED_PRIVILEGE:
      return CompareResolvedPrivilege(node1->GetAs<ResolvedPrivilege>(),
                                   node2->GetAs<ResolvedPrivilege>());
    case RESOLVED_GRANT_STMT:
      return CompareResolvedGrantStmt(node1->GetAs<ResolvedGrantStmt>(),
                                   node2->GetAs<ResolvedGrantStmt>());
    case RESOLVED_REVOKE_STMT:
      return CompareResolvedRevokeStmt(node1->GetAs<ResolvedRevokeStmt>(),
                                   node2->GetAs<ResolvedRevokeStmt>());
    case RESOLVED_ALTER_DATABASE_STMT:
      return CompareResolvedAlterDatabaseStmt(node1->GetAs<ResolvedAlterDatabaseStmt>(),
                                   node2->GetAs<ResolvedAlterDatabaseStmt>());
    case RESOLVED_ALTER_MATERIALIZED_VIEW_STMT:
      return CompareResolvedAlterMaterializedViewStmt(node1->GetAs<ResolvedAlterMaterializedViewStmt>(),
                                   node2->GetAs<ResolvedAlterMaterializedViewStmt>());
    case RESOLVED_ALTER_SCHEMA_STMT:
      return CompareResolvedAlterSchemaStmt(node1->GetAs<ResolvedAlterSchemaStmt>(),
                                   node2->GetAs<ResolvedAlterSchemaStmt>());
    case RESOLVED_ALTER_TABLE_STMT:
      return CompareResolvedAlterTableStmt(node1->GetAs<ResolvedAlterTableStmt>(),
                                   node2->GetAs<ResolvedAlterTableStmt>());
    case RESOLVED_ALTER_VIEW_STMT:
      return CompareResolvedAlterViewStmt(node1->GetAs<ResolvedAlterViewStmt>(),
                                   node2->GetAs<ResolvedAlterViewStmt>());
    case RESOLVED_SET_OPTIONS_ACTION:
      return CompareResolvedSetOptionsAction(node1->GetAs<ResolvedSetOptionsAction>(),
                                   node2->GetAs<ResolvedSetOptionsAction>());
    case RESOLVED_ADD_COLUMN_ACTION:
      return CompareResolvedAddColumnAction(node1->GetAs<ResolvedAddColumnAction>(),
                                   node2->GetAs<ResolvedAddColumnAction>());
    case RESOLVED_ADD_CONSTRAINT_ACTION:
      return CompareResolvedAddConstraintAction(node1->GetAs<ResolvedAddConstraintAction>(),
                                   node2->GetAs<ResolvedAddConstraintAction>());
    case RESOLVED_DROP_CONSTRAINT_ACTION:
      return CompareResolvedDropConstraintAction(node1->GetAs<ResolvedDropConstraintAction>(),
                                   node2->GetAs<ResolvedDropConstraintAction>());
    case RESOLVED_DROP_PRIMARY_KEY_ACTION:
      return CompareResolvedDropPrimaryKeyAction(node1->GetAs<ResolvedDropPrimaryKeyAction>(),
                                   node2->GetAs<ResolvedDropPrimaryKeyAction>());
    case RESOLVED_ALTER_COLUMN_OPTIONS_ACTION:
      return CompareResolvedAlterColumnOptionsAction(node1->GetAs<ResolvedAlterColumnOptionsAction>(),
                                   node2->GetAs<ResolvedAlterColumnOptionsAction>());
    case RESOLVED_ALTER_COLUMN_DROP_NOT_NULL_ACTION:
      return CompareResolvedAlterColumnDropNotNullAction(node1->GetAs<ResolvedAlterColumnDropNotNullAction>(),
                                   node2->GetAs<ResolvedAlterColumnDropNotNullAction>());
    case RESOLVED_ALTER_COLUMN_SET_DATA_TYPE_ACTION:
      return CompareResolvedAlterColumnSetDataTypeAction(node1->GetAs<ResolvedAlterColumnSetDataTypeAction>(),
                                   node2->GetAs<ResolvedAlterColumnSetDataTypeAction>());
    case RESOLVED_ALTER_COLUMN_SET_DEFAULT_ACTION:
      return CompareResolvedAlterColumnSetDefaultAction(node1->GetAs<ResolvedAlterColumnSetDefaultAction>(),
                                   node2->GetAs<ResolvedAlterColumnSetDefaultAction>());
    case RESOLVED_ALTER_COLUMN_DROP_DEFAULT_ACTION:
      return CompareResolvedAlterColumnDropDefaultAction(node1->GetAs<ResolvedAlterColumnDropDefaultAction>(),
                                   node2->GetAs<ResolvedAlterColumnDropDefaultAction>());
    case RESOLVED_DROP_COLUMN_ACTION:
      return CompareResolvedDropColumnAction(node1->GetAs<ResolvedDropColumnAction>(),
                                   node2->GetAs<ResolvedDropColumnAction>());
    case RESOLVED_RENAME_COLUMN_ACTION:
      return CompareResolvedRenameColumnAction(node1->GetAs<ResolvedRenameColumnAction>(),
                                   node2->GetAs<ResolvedRenameColumnAction>());
    case RESOLVED_SET_AS_ACTION:
      return CompareResolvedSetAsAction(node1->GetAs<ResolvedSetAsAction>(),
                                   node2->GetAs<ResolvedSetAsAction>());
    case RESOLVED_SET_COLLATE_CLAUSE:
      return CompareResolvedSetCollateClause(node1->GetAs<ResolvedSetCollateClause>(),
                                   node2->GetAs<ResolvedSetCollateClause>());
    case RESOLVED_ALTER_TABLE_SET_OPTIONS_STMT:
      return CompareResolvedAlterTableSetOptionsStmt(node1->GetAs<ResolvedAlterTableSetOptionsStmt>(),
                                   node2->GetAs<ResolvedAlterTableSetOptionsStmt>());
    case RESOLVED_RENAME_STMT:
      return CompareResolvedRenameStmt(node1->GetAs<ResolvedRenameStmt>(),
                                   node2->GetAs<ResolvedRenameStmt>());
    case RESOLVED_CREATE_PRIVILEGE_RESTRICTION_STMT:
      return CompareResolvedCreatePrivilegeRestrictionStmt(node1->GetAs<ResolvedCreatePrivilegeRestrictionStmt>(),
                                   node2->GetAs<ResolvedCreatePrivilegeRestrictionStmt>());
    case RESOLVED_CREATE_ROW_ACCESS_POLICY_STMT:
      return CompareResolvedCreateRowAccessPolicyStmt(node1->GetAs<ResolvedCreateRowAccessPolicyStmt>(),
                                   node2->GetAs<ResolvedCreateRowAccessPolicyStmt>());
    case RESOLVED_DROP_PRIVILEGE_RESTRICTION_STMT:
      return CompareResolvedDropPrivilegeRestrictionStmt(node1->GetAs<ResolvedDropPrivilegeRestrictionStmt>(),
                                   node2->GetAs<ResolvedDropPrivilegeRestrictionStmt>());
    case RESOLVED_DROP_ROW_ACCESS_POLICY_STMT:
      return CompareResolvedDropRowAccessPolicyStmt(node1->GetAs<ResolvedDropRowAccessPolicyStmt>(),
                                   node2->GetAs<ResolvedDropRowAccessPolicyStmt>());
    case RESOLVED_DROP_SEARCH_INDEX_STMT:
      return CompareResolvedDropSearchIndexStmt(node1->GetAs<ResolvedDropSearchIndexStmt>(),
                                   node2->GetAs<ResolvedDropSearchIndexStmt>());
    case RESOLVED_GRANT_TO_ACTION:
      return CompareResolvedGrantToAction(node1->GetAs<ResolvedGrantToAction>(),
                                   node2->GetAs<ResolvedGrantToAction>());
    case RESOLVED_RESTRICT_TO_ACTION:
      return CompareResolvedRestrictToAction(node1->GetAs<ResolvedRestrictToAction>(),
                                   node2->GetAs<ResolvedRestrictToAction>());
    case RESOLVED_ADD_TO_RESTRICTEE_LIST_ACTION:
      return CompareResolvedAddToRestricteeListAction(node1->GetAs<ResolvedAddToRestricteeListAction>(),
                                   node2->GetAs<ResolvedAddToRestricteeListAction>());
    case RESOLVED_REMOVE_FROM_RESTRICTEE_LIST_ACTION:
      return CompareResolvedRemoveFromRestricteeListAction(node1->GetAs<ResolvedRemoveFromRestricteeListAction>(),
                                   node2->GetAs<ResolvedRemoveFromRestricteeListAction>());
    case RESOLVED_FILTER_USING_ACTION:
      return CompareResolvedFilterUsingAction(node1->GetAs<ResolvedFilterUsingAction>(),
                                   node2->GetAs<ResolvedFilterUsingAction>());
    case RESOLVED_REVOKE_FROM_ACTION:
      return CompareResolvedRevokeFromAction(node1->GetAs<ResolvedRevokeFromAction>(),
                                   node2->GetAs<ResolvedRevokeFromAction>());
    case RESOLVED_RENAME_TO_ACTION:
      return CompareResolvedRenameToAction(node1->GetAs<ResolvedRenameToAction>(),
                                   node2->GetAs<ResolvedRenameToAction>());
    case RESOLVED_ALTER_PRIVILEGE_RESTRICTION_STMT:
      return CompareResolvedAlterPrivilegeRestrictionStmt(node1->GetAs<ResolvedAlterPrivilegeRestrictionStmt>(),
                                   node2->GetAs<ResolvedAlterPrivilegeRestrictionStmt>());
    case RESOLVED_ALTER_ROW_ACCESS_POLICY_STMT:
      return CompareResolvedAlterRowAccessPolicyStmt(node1->GetAs<ResolvedAlterRowAccessPolicyStmt>(),
                                   node2->GetAs<ResolvedAlterRowAccessPolicyStmt>());
    case RESOLVED_ALTER_ALL_ROW_ACCESS_POLICIES_STMT:
      return CompareResolvedAlterAllRowAccessPoliciesStmt(node1->GetAs<ResolvedAlterAllRowAccessPoliciesStmt>(),
                                   node2->GetAs<ResolvedAlterAllRowAccessPoliciesStmt>());
    case RESOLVED_CREATE_CONSTANT_STMT:
      return CompareResolvedCreateConstantStmt(node1->GetAs<ResolvedCreateConstantStmt>(),
                                   node2->GetAs<ResolvedCreateConstantStmt>());
    case RESOLVED_CREATE_FUNCTION_STMT:
      return CompareResolvedCreateFunctionStmt(node1->GetAs<ResolvedCreateFunctionStmt>(),
                                   node2->GetAs<ResolvedCreateFunctionStmt>());
    case RESOLVED_ARGUMENT_DEF:
      return CompareResolvedArgumentDef(node1->GetAs<ResolvedArgumentDef>(),
                                   node2->GetAs<ResolvedArgumentDef>());
    case RESOLVED_ARGUMENT_REF:
      return CompareResolvedArgumentRef(node1->GetAs<ResolvedArgumentRef>(),
                                   node2->GetAs<ResolvedArgumentRef>());
    case RESOLVED_CREATE_TABLE_FUNCTION_STMT:
      return CompareResolvedCreateTableFunctionStmt(node1->GetAs<ResolvedCreateTableFunctionStmt>(),
                                   node2->GetAs<ResolvedCreateTableFunctionStmt>());
    case RESOLVED_RELATION_ARGUMENT_SCAN:
      return CompareResolvedRelationArgumentScan(node1->GetAs<ResolvedRelationArgumentScan>(),
                                   node2->GetAs<ResolvedRelationArgumentScan>());
    case RESOLVED_ARGUMENT_LIST:
      return CompareResolvedArgumentList(node1->GetAs<ResolvedArgumentList>(),
                                   node2->GetAs<ResolvedArgumentList>());
    case RESOLVED_FUNCTION_SIGNATURE_HOLDER:
      return CompareResolvedFunctionSignatureHolder(node1->GetAs<ResolvedFunctionSignatureHolder>(),
                                   node2->GetAs<ResolvedFunctionSignatureHolder>());
    case RESOLVED_DROP_FUNCTION_STMT:
      return CompareResolvedDropFunctionStmt(node1->GetAs<ResolvedDropFunctionStmt>(),
                                   node2->GetAs<ResolvedDropFunctionStmt>());
    case RESOLVED_DROP_TABLE_FUNCTION_STMT:
      return CompareResolvedDropTableFunctionStmt(node1->GetAs<ResolvedDropTableFunctionStmt>(),
                                   node2->GetAs<ResolvedDropTableFunctionStmt>());
    case RESOLVED_CALL_STMT:
      return CompareResolvedCallStmt(node1->GetAs<ResolvedCallStmt>(),
                                   node2->GetAs<ResolvedCallStmt>());
    case RESOLVED_IMPORT_STMT:
      return CompareResolvedImportStmt(node1->GetAs<ResolvedImportStmt>(),
                                   node2->GetAs<ResolvedImportStmt>());
    case RESOLVED_MODULE_STMT:
      return CompareResolvedModuleStmt(node1->GetAs<ResolvedModuleStmt>(),
                                   node2->GetAs<ResolvedModuleStmt>());
    case RESOLVED_AGGREGATE_HAVING_MODIFIER:
      return CompareResolvedAggregateHavingModifier(node1->GetAs<ResolvedAggregateHavingModifier>(),
                                   node2->GetAs<ResolvedAggregateHavingModifier>());
    case RESOLVED_CREATE_MATERIALIZED_VIEW_STMT:
      return CompareResolvedCreateMaterializedViewStmt(node1->GetAs<ResolvedCreateMaterializedViewStmt>(),
                                   node2->GetAs<ResolvedCreateMaterializedViewStmt>());
    case RESOLVED_CREATE_PROCEDURE_STMT:
      return CompareResolvedCreateProcedureStmt(node1->GetAs<ResolvedCreateProcedureStmt>(),
                                   node2->GetAs<ResolvedCreateProcedureStmt>());
    case RESOLVED_EXECUTE_IMMEDIATE_ARGUMENT:
      return CompareResolvedExecuteImmediateArgument(node1->GetAs<ResolvedExecuteImmediateArgument>(),
                                   node2->GetAs<ResolvedExecuteImmediateArgument>());
    case RESOLVED_EXECUTE_IMMEDIATE_STMT:
      return CompareResolvedExecuteImmediateStmt(node1->GetAs<ResolvedExecuteImmediateStmt>(),
                                   node2->GetAs<ResolvedExecuteImmediateStmt>());
    case RESOLVED_ASSIGNMENT_STMT:
      return CompareResolvedAssignmentStmt(node1->GetAs<ResolvedAssignmentStmt>(),
                                   node2->GetAs<ResolvedAssignmentStmt>());
    case RESOLVED_CREATE_ENTITY_STMT:
      return CompareResolvedCreateEntityStmt(node1->GetAs<ResolvedCreateEntityStmt>(),
                                   node2->GetAs<ResolvedCreateEntityStmt>());
    case RESOLVED_ALTER_ENTITY_STMT:
      return CompareResolvedAlterEntityStmt(node1->GetAs<ResolvedAlterEntityStmt>(),
                                   node2->GetAs<ResolvedAlterEntityStmt>());
    case RESOLVED_PIVOT_COLUMN:
      return CompareResolvedPivotColumn(node1->GetAs<ResolvedPivotColumn>(),
                                   node2->GetAs<ResolvedPivotColumn>());
    case RESOLVED_PIVOT_SCAN:
      return CompareResolvedPivotScan(node1->GetAs<ResolvedPivotScan>(),
                                   node2->GetAs<ResolvedPivotScan>());
    case RESOLVED_RETURNING_CLAUSE:
      return CompareResolvedReturningClause(node1->GetAs<ResolvedReturningClause>(),
                                   node2->GetAs<ResolvedReturningClause>());
    case RESOLVED_UNPIVOT_ARG:
      return CompareResolvedUnpivotArg(node1->GetAs<ResolvedUnpivotArg>(),
                                   node2->GetAs<ResolvedUnpivotArg>());
    case RESOLVED_UNPIVOT_SCAN:
      return CompareResolvedUnpivotScan(node1->GetAs<ResolvedUnpivotScan>(),
                                   node2->GetAs<ResolvedUnpivotScan>());
    case RESOLVED_CLONE_DATA_STMT:
      return CompareResolvedCloneDataStmt(node1->GetAs<ResolvedCloneDataStmt>(),
                                   node2->GetAs<ResolvedCloneDataStmt>());
    case RESOLVED_TABLE_AND_COLUMN_INFO:
      return CompareResolvedTableAndColumnInfo(node1->GetAs<ResolvedTableAndColumnInfo>(),
                                   node2->GetAs<ResolvedTableAndColumnInfo>());
    case RESOLVED_ANALYZE_STMT:
      return CompareResolvedAnalyzeStmt(node1->GetAs<ResolvedAnalyzeStmt>(),
                                   node2->GetAs<ResolvedAnalyzeStmt>());
    case RESOLVED_AUX_LOAD_DATA_STMT:
      return CompareResolvedAuxLoadDataStmt(node1->GetAs<ResolvedAuxLoadDataStmt>(),
                                   node2->GetAs<ResolvedAuxLoadDataStmt>());
    default: return false;
  }
}

absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedLiteral(
    const ResolvedLiteral* node1, const ResolvedLiteral* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  if (!Equals(node1->value(), node2->value())) {
    return false;
  }
  if (!Equals(node1->has_explicit_type(), node2->has_explicit_type())) {
    return false;
  }
  if (!Equals(node1->float_literal_id(), node2->float_literal_id())) {
    return false;
  }
  if (!Equals(node1->preserve_in_literal_remover(), node2->preserve_in_literal_remover())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedParameter(
    const ResolvedParameter* node1, const ResolvedParameter* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  if (!Equals(node1->position(), node2->position())) {
    return false;
  }
  if (!Equals(node1->is_untyped(), node2->is_untyped())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExpressionColumn(
    const ResolvedExpressionColumn* node1, const ResolvedExpressionColumn* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedColumnRef(
    const ResolvedColumnRef* node1, const ResolvedColumnRef* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  if (!Equals(node1->column(), node2->column())) {
    return false;
  }
  if (!Equals(node1->is_correlated(), node2->is_correlated())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedConstant(
    const ResolvedConstant* node1, const ResolvedConstant* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  if (!Equals(node1->constant(), node2->constant())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSystemVariable(
    const ResolvedSystemVariable* node1, const ResolvedSystemVariable* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedInlineLambda(
    const ResolvedInlineLambda* node1, const ResolvedInlineLambda* node2) {

  absl::StatusOr<bool> result;
  if (node1->argument_list().size() != node2->argument_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->argument_list().size(); ++i) {
    if (!Equals(node1->argument_list(i), node2->argument_list(i))) {
      return false;
    }
  }
  if (node1->parameter_list().size() != node2->parameter_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->parameter_list().size(); ++i) {
    result = CompareResolvedAST(node1->parameter_list(i),
                                  node2->parameter_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->body(),
                                node2->body());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFilterFieldArg(
    const ResolvedFilterFieldArg* node1, const ResolvedFilterFieldArg* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->include(), node2->include())) {
    return false;
  }
  if (node1->field_descriptor_path().size() != node2->field_descriptor_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->field_descriptor_path().size(); ++i) {
    if (!Equals(node1->field_descriptor_path(i), node2->field_descriptor_path(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFilterField(
    const ResolvedFilterField* node1, const ResolvedFilterField* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  result = CompareResolvedAST(node1->expr(),
                                node2->expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->filter_field_arg_list().size() != node2->filter_field_arg_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->filter_field_arg_list().size(); ++i) {
    result = CompareResolvedAST(node1->filter_field_arg_list(i),
                                  node2->filter_field_arg_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->reset_cleared_required_fields(), node2->reset_cleared_required_fields())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFunctionCall(
    const ResolvedFunctionCall* node1, const ResolvedFunctionCall* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  if (!Equals(node1->function(), node2->function())) {
    return false;
  }
  if (!Equals(node1->signature(), node2->signature())) {
    return false;
  }
  if (node1->argument_list().size() != node2->argument_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->argument_list().size(); ++i) {
    result = CompareResolvedAST(node1->argument_list(i),
                                  node2->argument_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->generic_argument_list().size() != node2->generic_argument_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->generic_argument_list().size(); ++i) {
    result = CompareResolvedAST(node1->generic_argument_list(i),
                                  node2->generic_argument_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->error_mode(), node2->error_mode())) {
    return false;
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->collation_list().size() != node2->collation_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->collation_list().size(); ++i) {
    if (!Equals(node1->collation_list(i), node2->collation_list(i))) {
      return false;
    }
  }
  if (!Equals(node1->function_call_info(), node2->function_call_info())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAggregateFunctionCall(
    const ResolvedAggregateFunctionCall* node1, const ResolvedAggregateFunctionCall* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  if (!Equals(node1->function(), node2->function())) {
    return false;
  }
  if (!Equals(node1->signature(), node2->signature())) {
    return false;
  }
  if (node1->argument_list().size() != node2->argument_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->argument_list().size(); ++i) {
    result = CompareResolvedAST(node1->argument_list(i),
                                  node2->argument_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->generic_argument_list().size() != node2->generic_argument_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->generic_argument_list().size(); ++i) {
    result = CompareResolvedAST(node1->generic_argument_list(i),
                                  node2->generic_argument_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->error_mode(), node2->error_mode())) {
    return false;
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->collation_list().size() != node2->collation_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->collation_list().size(); ++i) {
    if (!Equals(node1->collation_list(i), node2->collation_list(i))) {
      return false;
    }
  }
  if (!Equals(node1->distinct(), node2->distinct())) {
    return false;
  }
  if (!Equals(node1->null_handling_modifier(), node2->null_handling_modifier())) {
    return false;
  }
  result = CompareResolvedAST(node1->with_group_rows_subquery(),
                                node2->with_group_rows_subquery());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->with_group_rows_parameter_list().size() != node2->with_group_rows_parameter_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->with_group_rows_parameter_list().size(); ++i) {
    result = CompareResolvedAST(node1->with_group_rows_parameter_list(i),
                                  node2->with_group_rows_parameter_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->having_modifier(),
                                node2->having_modifier());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->order_by_item_list().size() != node2->order_by_item_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->order_by_item_list().size(); ++i) {
    result = CompareResolvedAST(node1->order_by_item_list(i),
                                  node2->order_by_item_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->limit(),
                                node2->limit());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->function_call_info(), node2->function_call_info())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAnalyticFunctionCall(
    const ResolvedAnalyticFunctionCall* node1, const ResolvedAnalyticFunctionCall* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  if (!Equals(node1->function(), node2->function())) {
    return false;
  }
  if (!Equals(node1->signature(), node2->signature())) {
    return false;
  }
  if (node1->argument_list().size() != node2->argument_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->argument_list().size(); ++i) {
    result = CompareResolvedAST(node1->argument_list(i),
                                  node2->argument_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->generic_argument_list().size() != node2->generic_argument_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->generic_argument_list().size(); ++i) {
    result = CompareResolvedAST(node1->generic_argument_list(i),
                                  node2->generic_argument_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->error_mode(), node2->error_mode())) {
    return false;
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->collation_list().size() != node2->collation_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->collation_list().size(); ++i) {
    if (!Equals(node1->collation_list(i), node2->collation_list(i))) {
      return false;
    }
  }
  if (!Equals(node1->distinct(), node2->distinct())) {
    return false;
  }
  if (!Equals(node1->null_handling_modifier(), node2->null_handling_modifier())) {
    return false;
  }
  result = CompareResolvedAST(node1->with_group_rows_subquery(),
                                node2->with_group_rows_subquery());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->with_group_rows_parameter_list().size() != node2->with_group_rows_parameter_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->with_group_rows_parameter_list().size(); ++i) {
    result = CompareResolvedAST(node1->with_group_rows_parameter_list(i),
                                  node2->with_group_rows_parameter_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->window_frame(),
                                node2->window_frame());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExtendedCastElement(
    const ResolvedExtendedCastElement* node1, const ResolvedExtendedCastElement* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->from_type(), node2->from_type())) {
    return false;
  }
  if (!Equals(node1->to_type(), node2->to_type())) {
    return false;
  }
  if (!Equals(node1->function(), node2->function())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExtendedCast(
    const ResolvedExtendedCast* node1, const ResolvedExtendedCast* node2) {

  absl::StatusOr<bool> result;
  if (node1->element_list().size() != node2->element_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->element_list().size(); ++i) {
    result = CompareResolvedAST(node1->element_list(i),
                                  node2->element_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCast(
    const ResolvedCast* node1, const ResolvedCast* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  result = CompareResolvedAST(node1->expr(),
                                node2->expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->return_null_on_error(), node2->return_null_on_error())) {
    return false;
  }
  result = CompareResolvedAST(node1->extended_cast(),
                                node2->extended_cast());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->format(),
                                node2->format());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->time_zone(),
                                node2->time_zone());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->type_parameters(), node2->type_parameters())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedMakeStruct(
    const ResolvedMakeStruct* node1, const ResolvedMakeStruct* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  if (node1->field_list().size() != node2->field_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->field_list().size(); ++i) {
    result = CompareResolvedAST(node1->field_list(i),
                                  node2->field_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedMakeProto(
    const ResolvedMakeProto* node1, const ResolvedMakeProto* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  if (node1->field_list().size() != node2->field_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->field_list().size(); ++i) {
    result = CompareResolvedAST(node1->field_list(i),
                                  node2->field_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedMakeProtoField(
    const ResolvedMakeProtoField* node1, const ResolvedMakeProtoField* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->field_descriptor(), node2->field_descriptor())) {
    return false;
  }
  if (!Equals(node1->format(), node2->format())) {
    return false;
  }
  result = CompareResolvedAST(node1->expr(),
                                node2->expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGetStructField(
    const ResolvedGetStructField* node1, const ResolvedGetStructField* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  result = CompareResolvedAST(node1->expr(),
                                node2->expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->field_idx(), node2->field_idx())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGetProtoField(
    const ResolvedGetProtoField* node1, const ResolvedGetProtoField* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  result = CompareResolvedAST(node1->expr(),
                                node2->expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->field_descriptor(), node2->field_descriptor())) {
    return false;
  }
  if (!Equals(node1->default_value(), node2->default_value())) {
    return false;
  }
  if (!Equals(node1->get_has_bit(), node2->get_has_bit())) {
    return false;
  }
  if (!Equals(node1->format(), node2->format())) {
    return false;
  }
  if (!Equals(node1->return_default_value_when_unset(), node2->return_default_value_when_unset())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGetJsonField(
    const ResolvedGetJsonField* node1, const ResolvedGetJsonField* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  result = CompareResolvedAST(node1->expr(),
                                node2->expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->field_name(), node2->field_name())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFlatten(
    const ResolvedFlatten* node1, const ResolvedFlatten* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  result = CompareResolvedAST(node1->expr(),
                                node2->expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->get_field_list().size() != node2->get_field_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->get_field_list().size(); ++i) {
    result = CompareResolvedAST(node1->get_field_list(i),
                                  node2->get_field_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFlattenedArg(
    const ResolvedFlattenedArg* node1, const ResolvedFlattenedArg* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedReplaceFieldItem(
    const ResolvedReplaceFieldItem* node1, const ResolvedReplaceFieldItem* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->expr(),
                                node2->expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->struct_index_path().size() != node2->struct_index_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->struct_index_path().size(); ++i) {
    if (!Equals(node1->struct_index_path(i), node2->struct_index_path(i))) {
      return false;
    }
  }
  if (node1->proto_field_path().size() != node2->proto_field_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->proto_field_path().size(); ++i) {
    if (!Equals(node1->proto_field_path(i), node2->proto_field_path(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedReplaceField(
    const ResolvedReplaceField* node1, const ResolvedReplaceField* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  result = CompareResolvedAST(node1->expr(),
                                node2->expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->replace_field_item_list().size() != node2->replace_field_item_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->replace_field_item_list().size(); ++i) {
    result = CompareResolvedAST(node1->replace_field_item_list(i),
                                  node2->replace_field_item_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSubqueryExpr(
    const ResolvedSubqueryExpr* node1, const ResolvedSubqueryExpr* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  if (!Equals(node1->subquery_type(), node2->subquery_type())) {
    return false;
  }
  if (node1->parameter_list().size() != node2->parameter_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->parameter_list().size(); ++i) {
    result = CompareResolvedAST(node1->parameter_list(i),
                                  node2->parameter_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->in_expr(),
                                node2->in_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->in_collation(), node2->in_collation())) {
    return false;
  }
  result = CompareResolvedAST(node1->subquery(),
                                node2->subquery());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedLetExpr(
    const ResolvedLetExpr* node1, const ResolvedLetExpr* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  if (node1->assignment_list().size() != node2->assignment_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->assignment_list().size(); ++i) {
    result = CompareResolvedAST(node1->assignment_list(i),
                                  node2->assignment_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->expr(),
                                node2->expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedModel(
    const ResolvedModel* node1, const ResolvedModel* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->model(), node2->model())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedConnection(
    const ResolvedConnection* node1, const ResolvedConnection* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->connection(), node2->connection())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDescriptor(
    const ResolvedDescriptor* node1, const ResolvedDescriptor* node2) {

  absl::StatusOr<bool> result;
  if (node1->descriptor_column_list().size() != node2->descriptor_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->descriptor_column_list().size(); ++i) {
    if (!Equals(node1->descriptor_column_list(i), node2->descriptor_column_list(i))) {
      return false;
    }
  }
  if (node1->descriptor_column_name_list().size() != node2->descriptor_column_name_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->descriptor_column_name_list().size(); ++i) {
    if (!Equals(node1->descriptor_column_name_list(i), node2->descriptor_column_name_list(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSingleRowScan(
    const ResolvedSingleRowScan* node1, const ResolvedSingleRowScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedTableScan(
    const ResolvedTableScan* node1, const ResolvedTableScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  if (!Equals(node1->table(), node2->table())) {
    return false;
  }
  result = CompareResolvedAST(node1->for_system_time_expr(),
                                node2->for_system_time_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->column_index_list().size() != node2->column_index_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_index_list().size(); ++i) {
    if (!Equals(node1->column_index_list(i), node2->column_index_list(i))) {
      return false;
    }
  }
  if (!Equals(node1->alias(), node2->alias())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedJoinScan(
    const ResolvedJoinScan* node1, const ResolvedJoinScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  if (!Equals(node1->join_type(), node2->join_type())) {
    return false;
  }
  result = CompareResolvedAST(node1->left_scan(),
                                node2->left_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->right_scan(),
                                node2->right_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->join_expr(),
                                node2->join_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedArrayScan(
    const ResolvedArrayScan* node1, const ResolvedArrayScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  result = CompareResolvedAST(node1->input_scan(),
                                node2->input_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->array_expr(),
                                node2->array_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->element_column(), node2->element_column())) {
    return false;
  }
  result = CompareResolvedAST(node1->array_offset_column(),
                                node2->array_offset_column());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->join_expr(),
                                node2->join_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->is_outer(), node2->is_outer())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedColumnHolder(
    const ResolvedColumnHolder* node1, const ResolvedColumnHolder* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->column(), node2->column())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFilterScan(
    const ResolvedFilterScan* node1, const ResolvedFilterScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  result = CompareResolvedAST(node1->input_scan(),
                                node2->input_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->filter_expr(),
                                node2->filter_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGroupingSet(
    const ResolvedGroupingSet* node1, const ResolvedGroupingSet* node2) {

  absl::StatusOr<bool> result;
  if (node1->group_by_column_list().size() != node2->group_by_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->group_by_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->group_by_column_list(i),
                                  node2->group_by_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAggregateScan(
    const ResolvedAggregateScan* node1, const ResolvedAggregateScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  result = CompareResolvedAST(node1->input_scan(),
                                node2->input_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->group_by_list().size() != node2->group_by_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->group_by_list().size(); ++i) {
    result = CompareResolvedAST(node1->group_by_list(i),
                                  node2->group_by_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->collation_list().size() != node2->collation_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->collation_list().size(); ++i) {
    if (!Equals(node1->collation_list(i), node2->collation_list(i))) {
      return false;
    }
  }
  if (node1->aggregate_list().size() != node2->aggregate_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->aggregate_list().size(); ++i) {
    result = CompareResolvedAST(node1->aggregate_list(i),
                                  node2->aggregate_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->grouping_set_list().size() != node2->grouping_set_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->grouping_set_list().size(); ++i) {
    result = CompareResolvedAST(node1->grouping_set_list(i),
                                  node2->grouping_set_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->rollup_column_list().size() != node2->rollup_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->rollup_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->rollup_column_list(i),
                                  node2->rollup_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAnonymizedAggregateScan(
    const ResolvedAnonymizedAggregateScan* node1, const ResolvedAnonymizedAggregateScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  result = CompareResolvedAST(node1->input_scan(),
                                node2->input_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->group_by_list().size() != node2->group_by_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->group_by_list().size(); ++i) {
    result = CompareResolvedAST(node1->group_by_list(i),
                                  node2->group_by_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->collation_list().size() != node2->collation_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->collation_list().size(); ++i) {
    if (!Equals(node1->collation_list(i), node2->collation_list(i))) {
      return false;
    }
  }
  if (node1->aggregate_list().size() != node2->aggregate_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->aggregate_list().size(); ++i) {
    result = CompareResolvedAST(node1->aggregate_list(i),
                                  node2->aggregate_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->k_threshold_expr(),
                                node2->k_threshold_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->anonymization_option_list().size() != node2->anonymization_option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->anonymization_option_list().size(); ++i) {
    result = CompareResolvedAST(node1->anonymization_option_list(i),
                                  node2->anonymization_option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSetOperationItem(
    const ResolvedSetOperationItem* node1, const ResolvedSetOperationItem* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->scan(),
                                node2->scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->output_column_list().size() != node2->output_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->output_column_list().size(); ++i) {
    if (!Equals(node1->output_column_list(i), node2->output_column_list(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSetOperationScan(
    const ResolvedSetOperationScan* node1, const ResolvedSetOperationScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  if (!Equals(node1->op_type(), node2->op_type())) {
    return false;
  }
  if (node1->input_item_list().size() != node2->input_item_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->input_item_list().size(); ++i) {
    result = CompareResolvedAST(node1->input_item_list(i),
                                  node2->input_item_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedOrderByScan(
    const ResolvedOrderByScan* node1, const ResolvedOrderByScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  result = CompareResolvedAST(node1->input_scan(),
                                node2->input_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->order_by_item_list().size() != node2->order_by_item_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->order_by_item_list().size(); ++i) {
    result = CompareResolvedAST(node1->order_by_item_list(i),
                                  node2->order_by_item_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedLimitOffsetScan(
    const ResolvedLimitOffsetScan* node1, const ResolvedLimitOffsetScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  result = CompareResolvedAST(node1->input_scan(),
                                node2->input_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->limit(),
                                node2->limit());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->offset(),
                                node2->offset());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWithRefScan(
    const ResolvedWithRefScan* node1, const ResolvedWithRefScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  if (!Equals(node1->with_query_name(), node2->with_query_name())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAnalyticScan(
    const ResolvedAnalyticScan* node1, const ResolvedAnalyticScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  result = CompareResolvedAST(node1->input_scan(),
                                node2->input_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->function_group_list().size() != node2->function_group_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->function_group_list().size(); ++i) {
    result = CompareResolvedAST(node1->function_group_list(i),
                                  node2->function_group_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSampleScan(
    const ResolvedSampleScan* node1, const ResolvedSampleScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  result = CompareResolvedAST(node1->input_scan(),
                                node2->input_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->method(), node2->method())) {
    return false;
  }
  result = CompareResolvedAST(node1->size(),
                                node2->size());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->unit(), node2->unit())) {
    return false;
  }
  result = CompareResolvedAST(node1->repeatable_argument(),
                                node2->repeatable_argument());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->weight_column(),
                                node2->weight_column());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->partition_by_list().size() != node2->partition_by_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->partition_by_list().size(); ++i) {
    result = CompareResolvedAST(node1->partition_by_list(i),
                                  node2->partition_by_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedComputedColumn(
    const ResolvedComputedColumn* node1, const ResolvedComputedColumn* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->column(), node2->column())) {
    return false;
  }
  result = CompareResolvedAST(node1->expr(),
                                node2->expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedOrderByItem(
    const ResolvedOrderByItem* node1, const ResolvedOrderByItem* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->column_ref(),
                                node2->column_ref());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->collation_name(),
                                node2->collation_name());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->is_descending(), node2->is_descending())) {
    return false;
  }
  if (!Equals(node1->null_order(), node2->null_order())) {
    return false;
  }
  if (!Equals(node1->collation(), node2->collation())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedColumnAnnotations(
    const ResolvedColumnAnnotations* node1, const ResolvedColumnAnnotations* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->collation_name(),
                                node2->collation_name());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->not_null(), node2->not_null())) {
    return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->child_list().size() != node2->child_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->child_list().size(); ++i) {
    result = CompareResolvedAST(node1->child_list(i),
                                  node2->child_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->type_parameters(), node2->type_parameters())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGeneratedColumnInfo(
    const ResolvedGeneratedColumnInfo* node1, const ResolvedGeneratedColumnInfo* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->expression(),
                                node2->expression());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->stored_mode(), node2->stored_mode())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedColumnDefaultValue(
    const ResolvedColumnDefaultValue* node1, const ResolvedColumnDefaultValue* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->expression(),
                                node2->expression());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->sql(), node2->sql())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedColumnDefinition(
    const ResolvedColumnDefinition* node1, const ResolvedColumnDefinition* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  result = CompareResolvedAST(node1->annotations(),
                                node2->annotations());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->is_hidden(), node2->is_hidden())) {
    return false;
  }
  if (!Equals(node1->column(), node2->column())) {
    return false;
  }
  result = CompareResolvedAST(node1->generated_column_info(),
                                node2->generated_column_info());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->default_value(),
                                node2->default_value());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedPrimaryKey(
    const ResolvedPrimaryKey* node1, const ResolvedPrimaryKey* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_offset_list().size() != node2->column_offset_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_offset_list().size(); ++i) {
    if (!Equals(node1->column_offset_list(i), node2->column_offset_list(i))) {
      return false;
    }
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->unenforced(), node2->unenforced())) {
    return false;
  }
  if (!Equals(node1->constraint_name(), node2->constraint_name())) {
    return false;
  }
  if (node1->column_name_list().size() != node2->column_name_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_name_list().size(); ++i) {
    if (!Equals(node1->column_name_list(i), node2->column_name_list(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedForeignKey(
    const ResolvedForeignKey* node1, const ResolvedForeignKey* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->constraint_name(), node2->constraint_name())) {
    return false;
  }
  if (node1->referencing_column_offset_list().size() != node2->referencing_column_offset_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->referencing_column_offset_list().size(); ++i) {
    if (!Equals(node1->referencing_column_offset_list(i), node2->referencing_column_offset_list(i))) {
      return false;
    }
  }
  if (!Equals(node1->referenced_table(), node2->referenced_table())) {
    return false;
  }
  if (node1->referenced_column_offset_list().size() != node2->referenced_column_offset_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->referenced_column_offset_list().size(); ++i) {
    if (!Equals(node1->referenced_column_offset_list(i), node2->referenced_column_offset_list(i))) {
      return false;
    }
  }
  if (!Equals(node1->match_mode(), node2->match_mode())) {
    return false;
  }
  if (!Equals(node1->update_action(), node2->update_action())) {
    return false;
  }
  if (!Equals(node1->delete_action(), node2->delete_action())) {
    return false;
  }
  if (!Equals(node1->enforced(), node2->enforced())) {
    return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->referencing_column_list().size() != node2->referencing_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->referencing_column_list().size(); ++i) {
    if (!Equals(node1->referencing_column_list(i), node2->referencing_column_list(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCheckConstraint(
    const ResolvedCheckConstraint* node1, const ResolvedCheckConstraint* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->constraint_name(), node2->constraint_name())) {
    return false;
  }
  result = CompareResolvedAST(node1->expression(),
                                node2->expression());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->enforced(), node2->enforced())) {
    return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedOutputColumn(
    const ResolvedOutputColumn* node1, const ResolvedOutputColumn* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  if (!Equals(node1->column(), node2->column())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedProjectScan(
    const ResolvedProjectScan* node1, const ResolvedProjectScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  if (node1->expr_list().size() != node2->expr_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->expr_list().size(); ++i) {
    result = CompareResolvedAST(node1->expr_list(i),
                                  node2->expr_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->input_scan(),
                                node2->input_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedTVFScan(
    const ResolvedTVFScan* node1, const ResolvedTVFScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  if (!Equals(node1->tvf(), node2->tvf())) {
    return false;
  }
  if (!Equals(node1->signature(), node2->signature())) {
    return false;
  }
  if (node1->argument_list().size() != node2->argument_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->argument_list().size(); ++i) {
    result = CompareResolvedAST(node1->argument_list(i),
                                  node2->argument_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->column_index_list().size() != node2->column_index_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_index_list().size(); ++i) {
    if (!Equals(node1->column_index_list(i), node2->column_index_list(i))) {
      return false;
    }
  }
  if (!Equals(node1->alias(), node2->alias())) {
    return false;
  }
  if (!Equals(node1->function_call_signature(), node2->function_call_signature())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGroupRowsScan(
    const ResolvedGroupRowsScan* node1, const ResolvedGroupRowsScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  if (node1->input_column_list().size() != node2->input_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->input_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->input_column_list(i),
                                  node2->input_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->alias(), node2->alias())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFunctionArgument(
    const ResolvedFunctionArgument* node1, const ResolvedFunctionArgument* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->expr(),
                                node2->expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->scan(),
                                node2->scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->model(),
                                node2->model());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->connection(),
                                node2->connection());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->descriptor_arg(),
                                node2->descriptor_arg());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->argument_column_list().size() != node2->argument_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->argument_column_list().size(); ++i) {
    if (!Equals(node1->argument_column_list(i), node2->argument_column_list(i))) {
      return false;
    }
  }
  result = CompareResolvedAST(node1->inline_lambda(),
                                node2->inline_lambda());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExplainStmt(
    const ResolvedExplainStmt* node1, const ResolvedExplainStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->statement(),
                                node2->statement());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedQueryStmt(
    const ResolvedQueryStmt* node1, const ResolvedQueryStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->output_column_list().size() != node2->output_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->output_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->output_column_list(i),
                                  node2->output_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_value_table(), node2->is_value_table())) {
    return false;
  }
  result = CompareResolvedAST(node1->query(),
                                node2->query());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateDatabaseStmt(
    const ResolvedCreateDatabaseStmt* node1, const ResolvedCreateDatabaseStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedIndexItem(
    const ResolvedIndexItem* node1, const ResolvedIndexItem* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->column_ref(),
                                node2->column_ref());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->descending(), node2->descending())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedUnnestItem(
    const ResolvedUnnestItem* node1, const ResolvedUnnestItem* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->array_expr(),
                                node2->array_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->element_column(), node2->element_column())) {
    return false;
  }
  result = CompareResolvedAST(node1->array_offset_column(),
                                node2->array_offset_column());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateIndexStmt(
    const ResolvedCreateIndexStmt* node1, const ResolvedCreateIndexStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->create_scope(), node2->create_scope())) {
    return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  if (node1->table_name_path().size() != node2->table_name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->table_name_path().size(); ++i) {
    if (!Equals(node1->table_name_path(i), node2->table_name_path(i))) {
      return false;
    }
  }
  result = CompareResolvedAST(node1->table_scan(),
                                node2->table_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->is_unique(), node2->is_unique())) {
    return false;
  }
  if (!Equals(node1->is_search(), node2->is_search())) {
    return false;
  }
  if (!Equals(node1->index_all_columns(), node2->index_all_columns())) {
    return false;
  }
  if (node1->index_item_list().size() != node2->index_item_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->index_item_list().size(); ++i) {
    result = CompareResolvedAST(node1->index_item_list(i),
                                  node2->index_item_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->storing_expression_list().size() != node2->storing_expression_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->storing_expression_list().size(); ++i) {
    result = CompareResolvedAST(node1->storing_expression_list(i),
                                  node2->storing_expression_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->computed_columns_list().size() != node2->computed_columns_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->computed_columns_list().size(); ++i) {
    result = CompareResolvedAST(node1->computed_columns_list(i),
                                  node2->computed_columns_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->unnest_expressions_list().size() != node2->unnest_expressions_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->unnest_expressions_list().size(); ++i) {
    result = CompareResolvedAST(node1->unnest_expressions_list(i),
                                  node2->unnest_expressions_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateSchemaStmt(
    const ResolvedCreateSchemaStmt* node1, const ResolvedCreateSchemaStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->create_scope(), node2->create_scope())) {
    return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  result = CompareResolvedAST(node1->collation_name(),
                                node2->collation_name());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateTableStmt(
    const ResolvedCreateTableStmt* node1, const ResolvedCreateTableStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->create_scope(), node2->create_scope())) {
    return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->column_definition_list().size() != node2->column_definition_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_definition_list().size(); ++i) {
    result = CompareResolvedAST(node1->column_definition_list(i),
                                  node2->column_definition_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->pseudo_column_list().size() != node2->pseudo_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->pseudo_column_list().size(); ++i) {
    if (!Equals(node1->pseudo_column_list(i), node2->pseudo_column_list(i))) {
      return false;
    }
  }
  result = CompareResolvedAST(node1->primary_key(),
                                node2->primary_key());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->foreign_key_list().size() != node2->foreign_key_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->foreign_key_list().size(); ++i) {
    result = CompareResolvedAST(node1->foreign_key_list(i),
                                  node2->foreign_key_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->check_constraint_list().size() != node2->check_constraint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->check_constraint_list().size(); ++i) {
    result = CompareResolvedAST(node1->check_constraint_list(i),
                                  node2->check_constraint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_value_table(), node2->is_value_table())) {
    return false;
  }
  if (!Equals(node1->like_table(), node2->like_table())) {
    return false;
  }
  result = CompareResolvedAST(node1->collation_name(),
                                node2->collation_name());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->clone_from(),
                                node2->clone_from());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->copy_from(),
                                node2->copy_from());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->partition_by_list().size() != node2->partition_by_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->partition_by_list().size(); ++i) {
    result = CompareResolvedAST(node1->partition_by_list(i),
                                  node2->partition_by_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->cluster_by_list().size() != node2->cluster_by_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->cluster_by_list().size(); ++i) {
    result = CompareResolvedAST(node1->cluster_by_list(i),
                                  node2->cluster_by_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateTableAsSelectStmt(
    const ResolvedCreateTableAsSelectStmt* node1, const ResolvedCreateTableAsSelectStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->create_scope(), node2->create_scope())) {
    return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->column_definition_list().size() != node2->column_definition_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_definition_list().size(); ++i) {
    result = CompareResolvedAST(node1->column_definition_list(i),
                                  node2->column_definition_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->pseudo_column_list().size() != node2->pseudo_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->pseudo_column_list().size(); ++i) {
    if (!Equals(node1->pseudo_column_list(i), node2->pseudo_column_list(i))) {
      return false;
    }
  }
  result = CompareResolvedAST(node1->primary_key(),
                                node2->primary_key());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->foreign_key_list().size() != node2->foreign_key_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->foreign_key_list().size(); ++i) {
    result = CompareResolvedAST(node1->foreign_key_list(i),
                                  node2->foreign_key_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->check_constraint_list().size() != node2->check_constraint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->check_constraint_list().size(); ++i) {
    result = CompareResolvedAST(node1->check_constraint_list(i),
                                  node2->check_constraint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_value_table(), node2->is_value_table())) {
    return false;
  }
  if (!Equals(node1->like_table(), node2->like_table())) {
    return false;
  }
  result = CompareResolvedAST(node1->collation_name(),
                                node2->collation_name());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->partition_by_list().size() != node2->partition_by_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->partition_by_list().size(); ++i) {
    result = CompareResolvedAST(node1->partition_by_list(i),
                                  node2->partition_by_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->cluster_by_list().size() != node2->cluster_by_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->cluster_by_list().size(); ++i) {
    result = CompareResolvedAST(node1->cluster_by_list(i),
                                  node2->cluster_by_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->output_column_list().size() != node2->output_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->output_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->output_column_list(i),
                                  node2->output_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->query(),
                                node2->query());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateModelStmt(
    const ResolvedCreateModelStmt* node1, const ResolvedCreateModelStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->create_scope(), node2->create_scope())) {
    return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->output_column_list().size() != node2->output_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->output_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->output_column_list(i),
                                  node2->output_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->query(),
                                node2->query());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->transform_input_column_list().size() != node2->transform_input_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->transform_input_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->transform_input_column_list(i),
                                  node2->transform_input_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->transform_list().size() != node2->transform_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->transform_list().size(); ++i) {
    result = CompareResolvedAST(node1->transform_list(i),
                                  node2->transform_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->transform_output_column_list().size() != node2->transform_output_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->transform_output_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->transform_output_column_list(i),
                                  node2->transform_output_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->transform_analytic_function_group_list().size() != node2->transform_analytic_function_group_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->transform_analytic_function_group_list().size(); ++i) {
    result = CompareResolvedAST(node1->transform_analytic_function_group_list(i),
                                  node2->transform_analytic_function_group_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateViewStmt(
    const ResolvedCreateViewStmt* node1, const ResolvedCreateViewStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->create_scope(), node2->create_scope())) {
    return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->output_column_list().size() != node2->output_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->output_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->output_column_list(i),
                                  node2->output_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->has_explicit_columns(), node2->has_explicit_columns())) {
    return false;
  }
  result = CompareResolvedAST(node1->query(),
                                node2->query());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->sql(), node2->sql())) {
    return false;
  }
  if (!Equals(node1->sql_security(), node2->sql_security())) {
    return false;
  }
  if (!Equals(node1->is_value_table(), node2->is_value_table())) {
    return false;
  }
  if (!Equals(node1->recursive(), node2->recursive())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWithPartitionColumns(
    const ResolvedWithPartitionColumns* node1, const ResolvedWithPartitionColumns* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_definition_list().size() != node2->column_definition_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_definition_list().size(); ++i) {
    result = CompareResolvedAST(node1->column_definition_list(i),
                                  node2->column_definition_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateSnapshotTableStmt(
    const ResolvedCreateSnapshotTableStmt* node1, const ResolvedCreateSnapshotTableStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->create_scope(), node2->create_scope())) {
    return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  result = CompareResolvedAST(node1->clone_from(),
                                node2->clone_from());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateExternalTableStmt(
    const ResolvedCreateExternalTableStmt* node1, const ResolvedCreateExternalTableStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->create_scope(), node2->create_scope())) {
    return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->column_definition_list().size() != node2->column_definition_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_definition_list().size(); ++i) {
    result = CompareResolvedAST(node1->column_definition_list(i),
                                  node2->column_definition_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->pseudo_column_list().size() != node2->pseudo_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->pseudo_column_list().size(); ++i) {
    if (!Equals(node1->pseudo_column_list(i), node2->pseudo_column_list(i))) {
      return false;
    }
  }
  result = CompareResolvedAST(node1->primary_key(),
                                node2->primary_key());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->foreign_key_list().size() != node2->foreign_key_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->foreign_key_list().size(); ++i) {
    result = CompareResolvedAST(node1->foreign_key_list(i),
                                  node2->foreign_key_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->check_constraint_list().size() != node2->check_constraint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->check_constraint_list().size(); ++i) {
    result = CompareResolvedAST(node1->check_constraint_list(i),
                                  node2->check_constraint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_value_table(), node2->is_value_table())) {
    return false;
  }
  if (!Equals(node1->like_table(), node2->like_table())) {
    return false;
  }
  result = CompareResolvedAST(node1->collation_name(),
                                node2->collation_name());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->with_partition_columns(),
                                node2->with_partition_columns());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->connection(),
                                node2->connection());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExportModelStmt(
    const ResolvedExportModelStmt* node1, const ResolvedExportModelStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->model_name_path().size() != node2->model_name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->model_name_path().size(); ++i) {
    if (!Equals(node1->model_name_path(i), node2->model_name_path(i))) {
      return false;
    }
  }
  result = CompareResolvedAST(node1->connection(),
                                node2->connection());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExportDataStmt(
    const ResolvedExportDataStmt* node1, const ResolvedExportDataStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->connection(),
                                node2->connection());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->output_column_list().size() != node2->output_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->output_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->output_column_list(i),
                                  node2->output_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_value_table(), node2->is_value_table())) {
    return false;
  }
  result = CompareResolvedAST(node1->query(),
                                node2->query());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDefineTableStmt(
    const ResolvedDefineTableStmt* node1, const ResolvedDefineTableStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDescribeStmt(
    const ResolvedDescribeStmt* node1, const ResolvedDescribeStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->object_type(), node2->object_type())) {
    return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->from_name_path().size() != node2->from_name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->from_name_path().size(); ++i) {
    if (!Equals(node1->from_name_path(i), node2->from_name_path(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedShowStmt(
    const ResolvedShowStmt* node1, const ResolvedShowStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->identifier(), node2->identifier())) {
    return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  result = CompareResolvedAST(node1->like_expr(),
                                node2->like_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedBeginStmt(
    const ResolvedBeginStmt* node1, const ResolvedBeginStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->read_write_mode(), node2->read_write_mode())) {
    return false;
  }
  if (node1->isolation_level_list().size() != node2->isolation_level_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->isolation_level_list().size(); ++i) {
    if (!Equals(node1->isolation_level_list(i), node2->isolation_level_list(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSetTransactionStmt(
    const ResolvedSetTransactionStmt* node1, const ResolvedSetTransactionStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->read_write_mode(), node2->read_write_mode())) {
    return false;
  }
  if (node1->isolation_level_list().size() != node2->isolation_level_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->isolation_level_list().size(); ++i) {
    if (!Equals(node1->isolation_level_list(i), node2->isolation_level_list(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCommitStmt(
    const ResolvedCommitStmt* node1, const ResolvedCommitStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRollbackStmt(
    const ResolvedRollbackStmt* node1, const ResolvedRollbackStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedStartBatchStmt(
    const ResolvedStartBatchStmt* node1, const ResolvedStartBatchStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->batch_type(), node2->batch_type())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRunBatchStmt(
    const ResolvedRunBatchStmt* node1, const ResolvedRunBatchStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAbortBatchStmt(
    const ResolvedAbortBatchStmt* node1, const ResolvedAbortBatchStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropStmt(
    const ResolvedDropStmt* node1, const ResolvedDropStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->object_type(), node2->object_type())) {
    return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->drop_mode(), node2->drop_mode())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropMaterializedViewStmt(
    const ResolvedDropMaterializedViewStmt* node1, const ResolvedDropMaterializedViewStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropSnapshotTableStmt(
    const ResolvedDropSnapshotTableStmt* node1, const ResolvedDropSnapshotTableStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRecursiveRefScan(
    const ResolvedRecursiveRefScan* node1, const ResolvedRecursiveRefScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRecursiveScan(
    const ResolvedRecursiveScan* node1, const ResolvedRecursiveScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  if (!Equals(node1->op_type(), node2->op_type())) {
    return false;
  }
  result = CompareResolvedAST(node1->non_recursive_term(),
                                node2->non_recursive_term());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->recursive_term(),
                                node2->recursive_term());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWithScan(
    const ResolvedWithScan* node1, const ResolvedWithScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  if (node1->with_entry_list().size() != node2->with_entry_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->with_entry_list().size(); ++i) {
    result = CompareResolvedAST(node1->with_entry_list(i),
                                  node2->with_entry_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->query(),
                                node2->query());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->recursive(), node2->recursive())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWithEntry(
    const ResolvedWithEntry* node1, const ResolvedWithEntry* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->with_query_name(), node2->with_query_name())) {
    return false;
  }
  result = CompareResolvedAST(node1->with_subquery(),
                                node2->with_subquery());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedOption(
    const ResolvedOption* node1, const ResolvedOption* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->qualifier(), node2->qualifier())) {
    return false;
  }
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  result = CompareResolvedAST(node1->value(),
                                node2->value());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWindowPartitioning(
    const ResolvedWindowPartitioning* node1, const ResolvedWindowPartitioning* node2) {

  absl::StatusOr<bool> result;
  if (node1->partition_by_list().size() != node2->partition_by_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->partition_by_list().size(); ++i) {
    result = CompareResolvedAST(node1->partition_by_list(i),
                                  node2->partition_by_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWindowOrdering(
    const ResolvedWindowOrdering* node1, const ResolvedWindowOrdering* node2) {

  absl::StatusOr<bool> result;
  if (node1->order_by_item_list().size() != node2->order_by_item_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->order_by_item_list().size(); ++i) {
    result = CompareResolvedAST(node1->order_by_item_list(i),
                                  node2->order_by_item_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWindowFrame(
    const ResolvedWindowFrame* node1, const ResolvedWindowFrame* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->frame_unit(), node2->frame_unit())) {
    return false;
  }
  result = CompareResolvedAST(node1->start_expr(),
                                node2->start_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->end_expr(),
                                node2->end_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAnalyticFunctionGroup(
    const ResolvedAnalyticFunctionGroup* node1, const ResolvedAnalyticFunctionGroup* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->partition_by(),
                                node2->partition_by());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->order_by(),
                                node2->order_by());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->analytic_function_list().size() != node2->analytic_function_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->analytic_function_list().size(); ++i) {
    result = CompareResolvedAST(node1->analytic_function_list(i),
                                  node2->analytic_function_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedWindowFrameExpr(
    const ResolvedWindowFrameExpr* node1, const ResolvedWindowFrameExpr* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->boundary_type(), node2->boundary_type())) {
    return false;
  }
  result = CompareResolvedAST(node1->expression(),
                                node2->expression());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDMLValue(
    const ResolvedDMLValue* node1, const ResolvedDMLValue* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->value(),
                                node2->value());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDMLDefault(
    const ResolvedDMLDefault* node1, const ResolvedDMLDefault* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAssertStmt(
    const ResolvedAssertStmt* node1, const ResolvedAssertStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->expression(),
                                node2->expression());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->description(), node2->description())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAssertRowsModified(
    const ResolvedAssertRowsModified* node1, const ResolvedAssertRowsModified* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->rows(),
                                node2->rows());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedInsertRow(
    const ResolvedInsertRow* node1, const ResolvedInsertRow* node2) {

  absl::StatusOr<bool> result;
  if (node1->value_list().size() != node2->value_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->value_list().size(); ++i) {
    result = CompareResolvedAST(node1->value_list(i),
                                  node2->value_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedInsertStmt(
    const ResolvedInsertStmt* node1, const ResolvedInsertStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->table_scan(),
                                node2->table_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->insert_mode(), node2->insert_mode())) {
    return false;
  }
  result = CompareResolvedAST(node1->assert_rows_modified(),
                                node2->assert_rows_modified());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->returning(),
                                node2->returning());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->insert_column_list().size() != node2->insert_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->insert_column_list().size(); ++i) {
    if (!Equals(node1->insert_column_list(i), node2->insert_column_list(i))) {
      return false;
    }
  }
  if (node1->query_parameter_list().size() != node2->query_parameter_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->query_parameter_list().size(); ++i) {
    result = CompareResolvedAST(node1->query_parameter_list(i),
                                  node2->query_parameter_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->query(),
                                node2->query());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->query_output_column_list().size() != node2->query_output_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->query_output_column_list().size(); ++i) {
    if (!Equals(node1->query_output_column_list(i), node2->query_output_column_list(i))) {
      return false;
    }
  }
  if (node1->row_list().size() != node2->row_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->row_list().size(); ++i) {
    result = CompareResolvedAST(node1->row_list(i),
                                  node2->row_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDeleteStmt(
    const ResolvedDeleteStmt* node1, const ResolvedDeleteStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->table_scan(),
                                node2->table_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->assert_rows_modified(),
                                node2->assert_rows_modified());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->returning(),
                                node2->returning());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->array_offset_column(),
                                node2->array_offset_column());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->where_expr(),
                                node2->where_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedUpdateItem(
    const ResolvedUpdateItem* node1, const ResolvedUpdateItem* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->target(),
                                node2->target());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->set_value(),
                                node2->set_value());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->element_column(),
                                node2->element_column());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->array_update_list().size() != node2->array_update_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->array_update_list().size(); ++i) {
    result = CompareResolvedAST(node1->array_update_list(i),
                                  node2->array_update_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->delete_list().size() != node2->delete_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->delete_list().size(); ++i) {
    result = CompareResolvedAST(node1->delete_list(i),
                                  node2->delete_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->update_list().size() != node2->update_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->update_list().size(); ++i) {
    result = CompareResolvedAST(node1->update_list(i),
                                  node2->update_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->insert_list().size() != node2->insert_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->insert_list().size(); ++i) {
    result = CompareResolvedAST(node1->insert_list(i),
                                  node2->insert_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedUpdateArrayItem(
    const ResolvedUpdateArrayItem* node1, const ResolvedUpdateArrayItem* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->offset(),
                                node2->offset());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->update_item(),
                                node2->update_item());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedUpdateStmt(
    const ResolvedUpdateStmt* node1, const ResolvedUpdateStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->table_scan(),
                                node2->table_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->column_access_list().size() != node2->column_access_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_access_list().size(); ++i) {
    if (!Equals(node1->column_access_list(i), node2->column_access_list(i))) {
      return false;
    }
  }
  result = CompareResolvedAST(node1->assert_rows_modified(),
                                node2->assert_rows_modified());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->returning(),
                                node2->returning());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->array_offset_column(),
                                node2->array_offset_column());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->where_expr(),
                                node2->where_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->update_item_list().size() != node2->update_item_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->update_item_list().size(); ++i) {
    result = CompareResolvedAST(node1->update_item_list(i),
                                  node2->update_item_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->from_scan(),
                                node2->from_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedMergeWhen(
    const ResolvedMergeWhen* node1, const ResolvedMergeWhen* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->match_type(), node2->match_type())) {
    return false;
  }
  result = CompareResolvedAST(node1->match_expr(),
                                node2->match_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->action_type(), node2->action_type())) {
    return false;
  }
  if (node1->insert_column_list().size() != node2->insert_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->insert_column_list().size(); ++i) {
    if (!Equals(node1->insert_column_list(i), node2->insert_column_list(i))) {
      return false;
    }
  }
  result = CompareResolvedAST(node1->insert_row(),
                                node2->insert_row());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->update_item_list().size() != node2->update_item_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->update_item_list().size(); ++i) {
    result = CompareResolvedAST(node1->update_item_list(i),
                                  node2->update_item_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedMergeStmt(
    const ResolvedMergeStmt* node1, const ResolvedMergeStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->table_scan(),
                                node2->table_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->column_access_list().size() != node2->column_access_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_access_list().size(); ++i) {
    if (!Equals(node1->column_access_list(i), node2->column_access_list(i))) {
      return false;
    }
  }
  result = CompareResolvedAST(node1->from_scan(),
                                node2->from_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->merge_expr(),
                                node2->merge_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->when_clause_list().size() != node2->when_clause_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->when_clause_list().size(); ++i) {
    result = CompareResolvedAST(node1->when_clause_list(i),
                                  node2->when_clause_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedTruncateStmt(
    const ResolvedTruncateStmt* node1, const ResolvedTruncateStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->table_scan(),
                                node2->table_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->where_expr(),
                                node2->where_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedObjectUnit(
    const ResolvedObjectUnit* node1, const ResolvedObjectUnit* node2) {

  absl::StatusOr<bool> result;
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedPrivilege(
    const ResolvedPrivilege* node1, const ResolvedPrivilege* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->action_type(), node2->action_type())) {
    return false;
  }
  if (node1->unit_list().size() != node2->unit_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->unit_list().size(); ++i) {
    result = CompareResolvedAST(node1->unit_list(i),
                                  node2->unit_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGrantStmt(
    const ResolvedGrantStmt* node1, const ResolvedGrantStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->privilege_list().size() != node2->privilege_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->privilege_list().size(); ++i) {
    result = CompareResolvedAST(node1->privilege_list(i),
                                  node2->privilege_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->object_type(), node2->object_type())) {
    return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->grantee_list().size() != node2->grantee_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->grantee_list().size(); ++i) {
    if (!Equals(node1->grantee_list(i), node2->grantee_list(i))) {
      return false;
    }
  }
  if (node1->grantee_expr_list().size() != node2->grantee_expr_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->grantee_expr_list().size(); ++i) {
    result = CompareResolvedAST(node1->grantee_expr_list(i),
                                  node2->grantee_expr_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRevokeStmt(
    const ResolvedRevokeStmt* node1, const ResolvedRevokeStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->privilege_list().size() != node2->privilege_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->privilege_list().size(); ++i) {
    result = CompareResolvedAST(node1->privilege_list(i),
                                  node2->privilege_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->object_type(), node2->object_type())) {
    return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->grantee_list().size() != node2->grantee_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->grantee_list().size(); ++i) {
    if (!Equals(node1->grantee_list(i), node2->grantee_list(i))) {
      return false;
    }
  }
  if (node1->grantee_expr_list().size() != node2->grantee_expr_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->grantee_expr_list().size(); ++i) {
    result = CompareResolvedAST(node1->grantee_expr_list(i),
                                  node2->grantee_expr_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterDatabaseStmt(
    const ResolvedAlterDatabaseStmt* node1, const ResolvedAlterDatabaseStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->alter_action_list().size() != node2->alter_action_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->alter_action_list().size(); ++i) {
    result = CompareResolvedAST(node1->alter_action_list(i),
                                  node2->alter_action_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterMaterializedViewStmt(
    const ResolvedAlterMaterializedViewStmt* node1, const ResolvedAlterMaterializedViewStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->alter_action_list().size() != node2->alter_action_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->alter_action_list().size(); ++i) {
    result = CompareResolvedAST(node1->alter_action_list(i),
                                  node2->alter_action_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterSchemaStmt(
    const ResolvedAlterSchemaStmt* node1, const ResolvedAlterSchemaStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->alter_action_list().size() != node2->alter_action_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->alter_action_list().size(); ++i) {
    result = CompareResolvedAST(node1->alter_action_list(i),
                                  node2->alter_action_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterTableStmt(
    const ResolvedAlterTableStmt* node1, const ResolvedAlterTableStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->alter_action_list().size() != node2->alter_action_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->alter_action_list().size(); ++i) {
    result = CompareResolvedAST(node1->alter_action_list(i),
                                  node2->alter_action_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterViewStmt(
    const ResolvedAlterViewStmt* node1, const ResolvedAlterViewStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->alter_action_list().size() != node2->alter_action_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->alter_action_list().size(); ++i) {
    result = CompareResolvedAST(node1->alter_action_list(i),
                                  node2->alter_action_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSetOptionsAction(
    const ResolvedSetOptionsAction* node1, const ResolvedSetOptionsAction* node2) {

  absl::StatusOr<bool> result;
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAddColumnAction(
    const ResolvedAddColumnAction* node1, const ResolvedAddColumnAction* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->is_if_not_exists(), node2->is_if_not_exists())) {
    return false;
  }
  result = CompareResolvedAST(node1->column_definition(),
                                node2->column_definition());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAddConstraintAction(
    const ResolvedAddConstraintAction* node1, const ResolvedAddConstraintAction* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->is_if_not_exists(), node2->is_if_not_exists())) {
    return false;
  }
  result = CompareResolvedAST(node1->constraint(),
                                node2->constraint());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->table(), node2->table())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropConstraintAction(
    const ResolvedDropConstraintAction* node1, const ResolvedDropConstraintAction* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropPrimaryKeyAction(
    const ResolvedDropPrimaryKeyAction* node1, const ResolvedDropPrimaryKeyAction* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterColumnOptionsAction(
    const ResolvedAlterColumnOptionsAction* node1, const ResolvedAlterColumnOptionsAction* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (!Equals(node1->column(), node2->column())) {
    return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterColumnDropNotNullAction(
    const ResolvedAlterColumnDropNotNullAction* node1, const ResolvedAlterColumnDropNotNullAction* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (!Equals(node1->column(), node2->column())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterColumnSetDataTypeAction(
    const ResolvedAlterColumnSetDataTypeAction* node1, const ResolvedAlterColumnSetDataTypeAction* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (!Equals(node1->column(), node2->column())) {
    return false;
  }
  if (!Equals(node1->updated_type(), node2->updated_type())) {
    return false;
  }
  if (!Equals(node1->updated_type_parameters(), node2->updated_type_parameters())) {
    return false;
  }
  result = CompareResolvedAST(node1->updated_annotations(),
                                node2->updated_annotations());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterColumnSetDefaultAction(
    const ResolvedAlterColumnSetDefaultAction* node1, const ResolvedAlterColumnSetDefaultAction* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (!Equals(node1->column(), node2->column())) {
    return false;
  }
  result = CompareResolvedAST(node1->default_value(),
                                node2->default_value());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterColumnDropDefaultAction(
    const ResolvedAlterColumnDropDefaultAction* node1, const ResolvedAlterColumnDropDefaultAction* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (!Equals(node1->column(), node2->column())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropColumnAction(
    const ResolvedDropColumnAction* node1, const ResolvedDropColumnAction* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRenameColumnAction(
    const ResolvedRenameColumnAction* node1, const ResolvedRenameColumnAction* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  if (!Equals(node1->new_name(), node2->new_name())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSetAsAction(
    const ResolvedSetAsAction* node1, const ResolvedSetAsAction* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->entity_body_json(), node2->entity_body_json())) {
    return false;
  }
  if (!Equals(node1->entity_body_text(), node2->entity_body_text())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedSetCollateClause(
    const ResolvedSetCollateClause* node1, const ResolvedSetCollateClause* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->collation_name(),
                                node2->collation_name());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterTableSetOptionsStmt(
    const ResolvedAlterTableSetOptionsStmt* node1, const ResolvedAlterTableSetOptionsStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRenameStmt(
    const ResolvedRenameStmt* node1, const ResolvedRenameStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->object_type(), node2->object_type())) {
    return false;
  }
  if (node1->old_name_path().size() != node2->old_name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->old_name_path().size(); ++i) {
    if (!Equals(node1->old_name_path(i), node2->old_name_path(i))) {
      return false;
    }
  }
  if (node1->new_name_path().size() != node2->new_name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->new_name_path().size(); ++i) {
    if (!Equals(node1->new_name_path(i), node2->new_name_path(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreatePrivilegeRestrictionStmt(
    const ResolvedCreatePrivilegeRestrictionStmt* node1, const ResolvedCreatePrivilegeRestrictionStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->create_scope(), node2->create_scope())) {
    return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  if (node1->column_privilege_list().size() != node2->column_privilege_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_privilege_list().size(); ++i) {
    result = CompareResolvedAST(node1->column_privilege_list(i),
                                  node2->column_privilege_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->object_type(), node2->object_type())) {
    return false;
  }
  if (node1->restrictee_list().size() != node2->restrictee_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->restrictee_list().size(); ++i) {
    result = CompareResolvedAST(node1->restrictee_list(i),
                                  node2->restrictee_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateRowAccessPolicyStmt(
    const ResolvedCreateRowAccessPolicyStmt* node1, const ResolvedCreateRowAccessPolicyStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  if (node1->target_name_path().size() != node2->target_name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->target_name_path().size(); ++i) {
    if (!Equals(node1->target_name_path(i), node2->target_name_path(i))) {
      return false;
    }
  }
  if (node1->grantee_list().size() != node2->grantee_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->grantee_list().size(); ++i) {
    if (!Equals(node1->grantee_list(i), node2->grantee_list(i))) {
      return false;
    }
  }
  if (node1->grantee_expr_list().size() != node2->grantee_expr_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->grantee_expr_list().size(); ++i) {
    result = CompareResolvedAST(node1->grantee_expr_list(i),
                                  node2->grantee_expr_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->table_scan(),
                                node2->table_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->predicate(),
                                node2->predicate());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->predicate_str(), node2->predicate_str())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropPrivilegeRestrictionStmt(
    const ResolvedDropPrivilegeRestrictionStmt* node1, const ResolvedDropPrivilegeRestrictionStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->object_type(), node2->object_type())) {
    return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->column_privilege_list().size() != node2->column_privilege_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_privilege_list().size(); ++i) {
    result = CompareResolvedAST(node1->column_privilege_list(i),
                                  node2->column_privilege_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropRowAccessPolicyStmt(
    const ResolvedDropRowAccessPolicyStmt* node1, const ResolvedDropRowAccessPolicyStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_drop_all(), node2->is_drop_all())) {
    return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  if (node1->target_name_path().size() != node2->target_name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->target_name_path().size(); ++i) {
    if (!Equals(node1->target_name_path(i), node2->target_name_path(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropSearchIndexStmt(
    const ResolvedDropSearchIndexStmt* node1, const ResolvedDropSearchIndexStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  if (node1->table_name_path().size() != node2->table_name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->table_name_path().size(); ++i) {
    if (!Equals(node1->table_name_path(i), node2->table_name_path(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedGrantToAction(
    const ResolvedGrantToAction* node1, const ResolvedGrantToAction* node2) {

  absl::StatusOr<bool> result;
  if (node1->grantee_expr_list().size() != node2->grantee_expr_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->grantee_expr_list().size(); ++i) {
    result = CompareResolvedAST(node1->grantee_expr_list(i),
                                  node2->grantee_expr_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRestrictToAction(
    const ResolvedRestrictToAction* node1, const ResolvedRestrictToAction* node2) {

  absl::StatusOr<bool> result;
  if (node1->restrictee_list().size() != node2->restrictee_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->restrictee_list().size(); ++i) {
    result = CompareResolvedAST(node1->restrictee_list(i),
                                  node2->restrictee_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAddToRestricteeListAction(
    const ResolvedAddToRestricteeListAction* node1, const ResolvedAddToRestricteeListAction* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->is_if_not_exists(), node2->is_if_not_exists())) {
    return false;
  }
  if (node1->restrictee_list().size() != node2->restrictee_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->restrictee_list().size(); ++i) {
    result = CompareResolvedAST(node1->restrictee_list(i),
                                  node2->restrictee_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRemoveFromRestricteeListAction(
    const ResolvedRemoveFromRestricteeListAction* node1, const ResolvedRemoveFromRestricteeListAction* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (node1->restrictee_list().size() != node2->restrictee_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->restrictee_list().size(); ++i) {
    result = CompareResolvedAST(node1->restrictee_list(i),
                                  node2->restrictee_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFilterUsingAction(
    const ResolvedFilterUsingAction* node1, const ResolvedFilterUsingAction* node2) {

  absl::StatusOr<bool> result;
  result = CompareResolvedAST(node1->predicate(),
                                node2->predicate());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->predicate_str(), node2->predicate_str())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRevokeFromAction(
    const ResolvedRevokeFromAction* node1, const ResolvedRevokeFromAction* node2) {

  absl::StatusOr<bool> result;
  if (node1->revokee_expr_list().size() != node2->revokee_expr_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->revokee_expr_list().size(); ++i) {
    result = CompareResolvedAST(node1->revokee_expr_list(i),
                                  node2->revokee_expr_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_revoke_from_all(), node2->is_revoke_from_all())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRenameToAction(
    const ResolvedRenameToAction* node1, const ResolvedRenameToAction* node2) {

  absl::StatusOr<bool> result;
  if (node1->new_path().size() != node2->new_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->new_path().size(); ++i) {
    if (!Equals(node1->new_path(i), node2->new_path(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterPrivilegeRestrictionStmt(
    const ResolvedAlterPrivilegeRestrictionStmt* node1, const ResolvedAlterPrivilegeRestrictionStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->alter_action_list().size() != node2->alter_action_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->alter_action_list().size(); ++i) {
    result = CompareResolvedAST(node1->alter_action_list(i),
                                  node2->alter_action_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (node1->column_privilege_list().size() != node2->column_privilege_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_privilege_list().size(); ++i) {
    result = CompareResolvedAST(node1->column_privilege_list(i),
                                  node2->column_privilege_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->object_type(), node2->object_type())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterRowAccessPolicyStmt(
    const ResolvedAlterRowAccessPolicyStmt* node1, const ResolvedAlterRowAccessPolicyStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->alter_action_list().size() != node2->alter_action_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->alter_action_list().size(); ++i) {
    result = CompareResolvedAST(node1->alter_action_list(i),
                                  node2->alter_action_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  result = CompareResolvedAST(node1->table_scan(),
                                node2->table_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterAllRowAccessPoliciesStmt(
    const ResolvedAlterAllRowAccessPoliciesStmt* node1, const ResolvedAlterAllRowAccessPoliciesStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->alter_action_list().size() != node2->alter_action_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->alter_action_list().size(); ++i) {
    result = CompareResolvedAST(node1->alter_action_list(i),
                                  node2->alter_action_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  result = CompareResolvedAST(node1->table_scan(),
                                node2->table_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateConstantStmt(
    const ResolvedCreateConstantStmt* node1, const ResolvedCreateConstantStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->create_scope(), node2->create_scope())) {
    return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  result = CompareResolvedAST(node1->expr(),
                                node2->expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateFunctionStmt(
    const ResolvedCreateFunctionStmt* node1, const ResolvedCreateFunctionStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->create_scope(), node2->create_scope())) {
    return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  if (!Equals(node1->has_explicit_return_type(), node2->has_explicit_return_type())) {
    return false;
  }
  if (!Equals(node1->return_type(), node2->return_type())) {
    return false;
  }
  if (node1->argument_name_list().size() != node2->argument_name_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->argument_name_list().size(); ++i) {
    if (!Equals(node1->argument_name_list(i), node2->argument_name_list(i))) {
      return false;
    }
  }
  if (!Equals(node1->signature(), node2->signature())) {
    return false;
  }
  if (!Equals(node1->is_aggregate(), node2->is_aggregate())) {
    return false;
  }
  if (!Equals(node1->language(), node2->language())) {
    return false;
  }
  if (!Equals(node1->code(), node2->code())) {
    return false;
  }
  if (node1->aggregate_expression_list().size() != node2->aggregate_expression_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->aggregate_expression_list().size(); ++i) {
    result = CompareResolvedAST(node1->aggregate_expression_list(i),
                                  node2->aggregate_expression_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->function_expression(),
                                node2->function_expression());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->sql_security(), node2->sql_security())) {
    return false;
  }
  if (!Equals(node1->determinism_level(), node2->determinism_level())) {
    return false;
  }
  if (!Equals(node1->is_remote(), node2->is_remote())) {
    return false;
  }
  result = CompareResolvedAST(node1->connection(),
                                node2->connection());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedArgumentDef(
    const ResolvedArgumentDef* node1, const ResolvedArgumentDef* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->argument_kind(), node2->argument_kind())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedArgumentRef(
    const ResolvedArgumentRef* node1, const ResolvedArgumentRef* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->type(), node2->type())) {
    return false;
  }
  if (!Equals(node1->type_annotation_map(), node2->type_annotation_map())) {
    return false;
  }
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  if (!Equals(node1->argument_kind(), node2->argument_kind())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateTableFunctionStmt(
    const ResolvedCreateTableFunctionStmt* node1, const ResolvedCreateTableFunctionStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->create_scope(), node2->create_scope())) {
    return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  if (node1->argument_name_list().size() != node2->argument_name_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->argument_name_list().size(); ++i) {
    if (!Equals(node1->argument_name_list(i), node2->argument_name_list(i))) {
      return false;
    }
  }
  if (!Equals(node1->signature(), node2->signature())) {
    return false;
  }
  if (!Equals(node1->has_explicit_return_schema(), node2->has_explicit_return_schema())) {
    return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->language(), node2->language())) {
    return false;
  }
  if (!Equals(node1->code(), node2->code())) {
    return false;
  }
  result = CompareResolvedAST(node1->query(),
                                node2->query());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->output_column_list().size() != node2->output_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->output_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->output_column_list(i),
                                  node2->output_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_value_table(), node2->is_value_table())) {
    return false;
  }
  if (!Equals(node1->sql_security(), node2->sql_security())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedRelationArgumentScan(
    const ResolvedRelationArgumentScan* node1, const ResolvedRelationArgumentScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  if (!Equals(node1->is_value_table(), node2->is_value_table())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedArgumentList(
    const ResolvedArgumentList* node1, const ResolvedArgumentList* node2) {

  absl::StatusOr<bool> result;
  if (node1->arg_list().size() != node2->arg_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->arg_list().size(); ++i) {
    result = CompareResolvedAST(node1->arg_list(i),
                                  node2->arg_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedFunctionSignatureHolder(
    const ResolvedFunctionSignatureHolder* node1, const ResolvedFunctionSignatureHolder* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->signature(), node2->signature())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropFunctionStmt(
    const ResolvedDropFunctionStmt* node1, const ResolvedDropFunctionStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  result = CompareResolvedAST(node1->arguments(),
                                node2->arguments());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->signature(),
                                node2->signature());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedDropTableFunctionStmt(
    const ResolvedDropTableFunctionStmt* node1, const ResolvedDropTableFunctionStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCallStmt(
    const ResolvedCallStmt* node1, const ResolvedCallStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->procedure(), node2->procedure())) {
    return false;
  }
  if (!Equals(node1->signature(), node2->signature())) {
    return false;
  }
  if (node1->argument_list().size() != node2->argument_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->argument_list().size(); ++i) {
    result = CompareResolvedAST(node1->argument_list(i),
                                  node2->argument_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedImportStmt(
    const ResolvedImportStmt* node1, const ResolvedImportStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->import_kind(), node2->import_kind())) {
    return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->file_path(), node2->file_path())) {
    return false;
  }
  if (node1->alias_path().size() != node2->alias_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->alias_path().size(); ++i) {
    if (!Equals(node1->alias_path(i), node2->alias_path(i))) {
      return false;
    }
  }
  if (node1->into_alias_path().size() != node2->into_alias_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->into_alias_path().size(); ++i) {
    if (!Equals(node1->into_alias_path(i), node2->into_alias_path(i))) {
      return false;
    }
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedModuleStmt(
    const ResolvedModuleStmt* node1, const ResolvedModuleStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAggregateHavingModifier(
    const ResolvedAggregateHavingModifier* node1, const ResolvedAggregateHavingModifier* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->kind(), node2->kind())) {
    return false;
  }
  result = CompareResolvedAST(node1->having_expr(),
                                node2->having_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateMaterializedViewStmt(
    const ResolvedCreateMaterializedViewStmt* node1, const ResolvedCreateMaterializedViewStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->create_scope(), node2->create_scope())) {
    return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->output_column_list().size() != node2->output_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->output_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->output_column_list(i),
                                  node2->output_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->has_explicit_columns(), node2->has_explicit_columns())) {
    return false;
  }
  result = CompareResolvedAST(node1->query(),
                                node2->query());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (!Equals(node1->sql(), node2->sql())) {
    return false;
  }
  if (!Equals(node1->sql_security(), node2->sql_security())) {
    return false;
  }
  if (!Equals(node1->is_value_table(), node2->is_value_table())) {
    return false;
  }
  if (!Equals(node1->recursive(), node2->recursive())) {
    return false;
  }
  if (node1->column_definition_list().size() != node2->column_definition_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_definition_list().size(); ++i) {
    result = CompareResolvedAST(node1->column_definition_list(i),
                                  node2->column_definition_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->partition_by_list().size() != node2->partition_by_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->partition_by_list().size(); ++i) {
    result = CompareResolvedAST(node1->partition_by_list(i),
                                  node2->partition_by_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->cluster_by_list().size() != node2->cluster_by_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->cluster_by_list().size(); ++i) {
    result = CompareResolvedAST(node1->cluster_by_list(i),
                                  node2->cluster_by_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateProcedureStmt(
    const ResolvedCreateProcedureStmt* node1, const ResolvedCreateProcedureStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->create_scope(), node2->create_scope())) {
    return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  if (node1->argument_name_list().size() != node2->argument_name_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->argument_name_list().size(); ++i) {
    if (!Equals(node1->argument_name_list(i), node2->argument_name_list(i))) {
      return false;
    }
  }
  if (!Equals(node1->signature(), node2->signature())) {
    return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->procedure_body(), node2->procedure_body())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExecuteImmediateArgument(
    const ResolvedExecuteImmediateArgument* node1, const ResolvedExecuteImmediateArgument* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->name(), node2->name())) {
    return false;
  }
  result = CompareResolvedAST(node1->expression(),
                                node2->expression());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedExecuteImmediateStmt(
    const ResolvedExecuteImmediateStmt* node1, const ResolvedExecuteImmediateStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->sql(),
                                node2->sql());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->into_identifier_list().size() != node2->into_identifier_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->into_identifier_list().size(); ++i) {
    if (!Equals(node1->into_identifier_list(i), node2->into_identifier_list(i))) {
      return false;
    }
  }
  if (node1->using_argument_list().size() != node2->using_argument_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->using_argument_list().size(); ++i) {
    result = CompareResolvedAST(node1->using_argument_list(i),
                                  node2->using_argument_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAssignmentStmt(
    const ResolvedAssignmentStmt* node1, const ResolvedAssignmentStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->target(),
                                node2->target());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->expr(),
                                node2->expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCreateEntityStmt(
    const ResolvedCreateEntityStmt* node1, const ResolvedCreateEntityStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (!Equals(node1->create_scope(), node2->create_scope())) {
    return false;
  }
  if (!Equals(node1->create_mode(), node2->create_mode())) {
    return false;
  }
  if (!Equals(node1->entity_type(), node2->entity_type())) {
    return false;
  }
  if (!Equals(node1->entity_body_json(), node2->entity_body_json())) {
    return false;
  }
  if (!Equals(node1->entity_body_text(), node2->entity_body_text())) {
    return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAlterEntityStmt(
    const ResolvedAlterEntityStmt* node1, const ResolvedAlterEntityStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->alter_action_list().size() != node2->alter_action_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->alter_action_list().size(); ++i) {
    result = CompareResolvedAST(node1->alter_action_list(i),
                                  node2->alter_action_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_if_exists(), node2->is_if_exists())) {
    return false;
  }
  if (!Equals(node1->entity_type(), node2->entity_type())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedPivotColumn(
    const ResolvedPivotColumn* node1, const ResolvedPivotColumn* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->column(), node2->column())) {
    return false;
  }
  if (!Equals(node1->pivot_expr_index(), node2->pivot_expr_index())) {
    return false;
  }
  if (!Equals(node1->pivot_value_index(), node2->pivot_value_index())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedPivotScan(
    const ResolvedPivotScan* node1, const ResolvedPivotScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  result = CompareResolvedAST(node1->input_scan(),
                                node2->input_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->group_by_list().size() != node2->group_by_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->group_by_list().size(); ++i) {
    result = CompareResolvedAST(node1->group_by_list(i),
                                  node2->group_by_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->pivot_expr_list().size() != node2->pivot_expr_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->pivot_expr_list().size(); ++i) {
    result = CompareResolvedAST(node1->pivot_expr_list(i),
                                  node2->pivot_expr_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->for_expr(),
                                node2->for_expr());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->pivot_value_list().size() != node2->pivot_value_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->pivot_value_list().size(); ++i) {
    result = CompareResolvedAST(node1->pivot_value_list(i),
                                  node2->pivot_value_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->pivot_column_list().size() != node2->pivot_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->pivot_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->pivot_column_list(i),
                                  node2->pivot_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedReturningClause(
    const ResolvedReturningClause* node1, const ResolvedReturningClause* node2) {

  absl::StatusOr<bool> result;
  if (node1->output_column_list().size() != node2->output_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->output_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->output_column_list(i),
                                  node2->output_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->action_column(),
                                node2->action_column());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->expr_list().size() != node2->expr_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->expr_list().size(); ++i) {
    result = CompareResolvedAST(node1->expr_list(i),
                                  node2->expr_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedUnpivotArg(
    const ResolvedUnpivotArg* node1, const ResolvedUnpivotArg* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    result = CompareResolvedAST(node1->column_list(i),
                                  node2->column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedUnpivotScan(
    const ResolvedUnpivotScan* node1, const ResolvedUnpivotScan* node2) {

  absl::StatusOr<bool> result;
  if (node1->column_list().size() != node2->column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_list().size(); ++i) {
    if (!Equals(node1->column_list(i), node2->column_list(i))) {
      return false;
    }
  }
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->is_ordered(), node2->is_ordered())) {
    return false;
  }
  result = CompareResolvedAST(node1->input_scan(),
                                node2->input_scan());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->value_column_list().size() != node2->value_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->value_column_list().size(); ++i) {
    if (!Equals(node1->value_column_list(i), node2->value_column_list(i))) {
      return false;
    }
  }
  if (!Equals(node1->label_column(), node2->label_column())) {
    return false;
  }
  if (node1->label_list().size() != node2->label_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->label_list().size(); ++i) {
    result = CompareResolvedAST(node1->label_list(i),
                                  node2->label_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->unpivot_arg_list().size() != node2->unpivot_arg_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->unpivot_arg_list().size(); ++i) {
    result = CompareResolvedAST(node1->unpivot_arg_list(i),
                                  node2->unpivot_arg_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->projected_input_column_list().size() != node2->projected_input_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->projected_input_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->projected_input_column_list(i),
                                  node2->projected_input_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->include_nulls(), node2->include_nulls())) {
    return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedCloneDataStmt(
    const ResolvedCloneDataStmt* node1, const ResolvedCloneDataStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->target_table(),
                                node2->target_table());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->clone_from(),
                                node2->clone_from());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedTableAndColumnInfo(
    const ResolvedTableAndColumnInfo* node1, const ResolvedTableAndColumnInfo* node2) {

  absl::StatusOr<bool> result;
  if (!Equals(node1->table(), node2->table())) {
    return false;
  }
  if (node1->column_index_list().size() != node2->column_index_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_index_list().size(); ++i) {
    if (!Equals(node1->column_index_list(i), node2->column_index_list(i))) {
      return false;
    }
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAnalyzeStmt(
    const ResolvedAnalyzeStmt* node1, const ResolvedAnalyzeStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->table_and_column_index_list().size() != node2->table_and_column_index_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->table_and_column_index_list().size(); ++i) {
    result = CompareResolvedAST(node1->table_and_column_index_list(i),
                                  node2->table_and_column_index_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
absl::StatusOr<bool> ResolvedASTComparator::CompareResolvedAuxLoadDataStmt(
    const ResolvedAuxLoadDataStmt* node1, const ResolvedAuxLoadDataStmt* node2) {

  absl::StatusOr<bool> result;
  if (node1->hint_list().size() != node2->hint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->hint_list().size(); ++i) {
    result = CompareResolvedAST(node1->hint_list(i),
                                  node2->hint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (!Equals(node1->insertion_mode(), node2->insertion_mode())) {
    return false;
  }
  if (node1->name_path().size() != node2->name_path().size()) {
    return false;
  }
  for (int i = 0; i < node1->name_path().size(); ++i) {
    if (!Equals(node1->name_path(i), node2->name_path(i))) {
      return false;
    }
  }
  if (node1->output_column_list().size() != node2->output_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->output_column_list().size(); ++i) {
    result = CompareResolvedAST(node1->output_column_list(i),
                                  node2->output_column_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->column_definition_list().size() != node2->column_definition_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->column_definition_list().size(); ++i) {
    result = CompareResolvedAST(node1->column_definition_list(i),
                                  node2->column_definition_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->pseudo_column_list().size() != node2->pseudo_column_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->pseudo_column_list().size(); ++i) {
    if (!Equals(node1->pseudo_column_list(i), node2->pseudo_column_list(i))) {
      return false;
    }
  }
  result = CompareResolvedAST(node1->primary_key(),
                                node2->primary_key());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->foreign_key_list().size() != node2->foreign_key_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->foreign_key_list().size(); ++i) {
    result = CompareResolvedAST(node1->foreign_key_list(i),
                                  node2->foreign_key_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->check_constraint_list().size() != node2->check_constraint_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->check_constraint_list().size(); ++i) {
    result = CompareResolvedAST(node1->check_constraint_list(i),
                                  node2->check_constraint_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->partition_by_list().size() != node2->partition_by_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->partition_by_list().size(); ++i) {
    result = CompareResolvedAST(node1->partition_by_list(i),
                                  node2->partition_by_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->cluster_by_list().size() != node2->cluster_by_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->cluster_by_list().size(); ++i) {
    result = CompareResolvedAST(node1->cluster_by_list(i),
                                  node2->cluster_by_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  if (node1->option_list().size() != node2->option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->option_list().size(); ++i) {
    result = CompareResolvedAST(node1->option_list(i),
                                  node2->option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  result = CompareResolvedAST(node1->with_partition_columns(),
                                node2->with_partition_columns());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  result = CompareResolvedAST(node1->connection(),
                                node2->connection());
  ZETASQL_RETURN_IF_ERROR(result.status());
  if (!*result) return false;
  if (node1->from_files_option_list().size() != node2->from_files_option_list().size()) {
    return false;
  }
  for (int i = 0; i < node1->from_files_option_list().size(); ++i) {
    result = CompareResolvedAST(node1->from_files_option_list(i),
                                  node2->from_files_option_list(i));
    ZETASQL_RETURN_IF_ERROR(result.status());
    if (!*result) return false;
  }
  return true;
}
}  // namespace zetasql