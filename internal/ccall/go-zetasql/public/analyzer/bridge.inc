#if 0
static std::unique_ptr<const zetasql::ResolvedArgument> make_unique_argument(void *arg)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg;
  switch (node->node_kind()) {
  case zetasql::RESOLVED_INLINE_LAMBDA:
  case zetasql::RESOLVED_FILTER_FIELD_ARG:
  case zetasql::RESOLVED_EXTENDED_CAST_ELEMENT:
  case zetasql::RESOLVED_EXTENDED_CAST:
  case zetasql::RESOLVED_MAKE_PROTO_FIELD:
  case zetasql::RESOLVED_REPLACE_FIELD_ITEM:
  case zetasql::RESOLVED_MODEL:
  case zetasql::RESOLVED_CONNECTION:
  case zetasql::RESOLVED_DESCRIPTOR:
  case zetasql::RESOLVED_COLUMN_HOLDER:
  case zetasql::RESOLVED_GROUPING_SET:
  case zetasql::RESOLVED_SET_OPERATION_ITEM:
  case zetasql::RESOLVED_COMPUTED_COLUMN:
  case zetasql::RESOLVED_ORDER_BY_ITEM:
  case zetasql::RESOLVED_COLUMN_ANNOTATIONS:
  case zetasql::RESOLVED_GENERATED_COLUMN_INFO:
  case zetasql::RESOLVED_COLUMN_DEFAULT_VALUE:
  case zetasql::RESOLVED_COLUMN_DEFINITION:
  case zetasql::RESOLVED_PRIMARY_KEY:
  case zetasql::RESOLVED_FOREIGN_KEY:
  case zetasql::RESOLVED_CHECK_CONSTRAINT:
  case zetasql::RESOLVED_OUTPUT_COLUMN:
  case zetasql::RESOLVED_FUNCTION_ARGUMENT:
  case zetasql::RESOLVED_INDEX_ITEM:
  case zetasql::RESOLVED_UNNEST_ITEM:
  case zetasql::RESOLVED_WITH_PARTITION_COLUMNS:
  case zetasql::RESOLVED_WITH_ENTRY:
  case zetasql::RESOLVED_OPTION:
  case zetasql::RESOLVED_WINDOW_PARTITIONING:
  case zetasql::RESOLVED_WINDOW_ORDERING:
  case zetasql::RESOLVED_WINDOW_FRAME:
  case zetasql::RESOLVED_ANALYTIC_FUNCTION_GROUP:
  case zetasql::RESOLVED_WINDOW_FRAME_EXPR:
  case zetasql::RESOLVED_DMLVALUE:
  case zetasql::RESOLVED_ASSERT_ROWS_MODIFIED:
  case zetasql::RESOLVED_INSERT_ROW:
  case zetasql::RESOLVED_UPDATE_ITEM:
  case zetasql::RESOLVED_UPDATE_ARRAY_ITEM:
  case zetasql::RESOLVED_MERGE_WHEN:
  case zetasql::RESOLVED_OBJECT_UNIT:
  case zetasql::RESOLVED_PRIVILEGE:
  case zetasql::RESOLVED_SET_OPTIONS_ACTION:
  case zetasql::RESOLVED_ADD_COLUMN_ACTION:
  case zetasql::RESOLVED_ADD_CONSTRAINT_ACTION:
  case zetasql::RESOLVED_DROP_CONSTRAINT_ACTION:
  case zetasql::RESOLVED_DROP_PRIMARY_KEY_ACTION:
  case zetasql::RESOLVED_ALTER_COLUMN_OPTIONS_ACTION:
  case zetasql::RESOLVED_ALTER_COLUMN_DROP_NOT_NULL_ACTION:
  case zetasql::RESOLVED_ALTER_COLUMN_SET_DATA_TYPE_ACTION:
  case zetasql::RESOLVED_ALTER_COLUMN_SET_DEFAULT_ACTION:
  case zetasql::RESOLVED_ALTER_COLUMN_DROP_DEFAULT_ACTION:
  case zetasql::RESOLVED_DROP_COLUMN_ACTION:
  case zetasql::RESOLVED_RENAME_COLUMN_ACTION:
  case zetasql::RESOLVED_SET_AS_ACTION:
  case zetasql::RESOLVED_GRANT_TO_ACTION:
  case zetasql::RESOLVED_RESTRICT_TO_ACTION:
  case zetasql::RESOLVED_ADD_TO_RESTRICTEE_LIST_ACTION:
  case zetasql::RESOLVED_REMOVE_FROM_RESTRICTEE_LIST_ACTION:
  case zetasql::RESOLVED_FILTER_USING_ACTION:
  case zetasql::RESOLVED_REVOKE_FROM_ACTION:
  case zetasql::RESOLVED_RENAME_TO_ACTION:
  case zetasql::RESOLVED_ARGUMENT_DEF:
  case zetasql::RESOLVED_ARGUMENT_LIST:
  case zetasql::RESOLVED_FUNCTION_SIGNATURE_HOLDER:
  case zetasql::RESOLVED_AGGREGATE_HAVING_MODIFIER:
  case zetasql::RESOLVED_EXECUTE_IMMEDIATE_ARGUMENT:
  case zetasql::RESOLVED_PIVOT_COLUMN:
  case zetasql::RESOLVED_RETURNING_CLAUSE:
  case zetasql::RESOLVED_UNPIVOT_ARG:
  case zetasql::RESOLVED_TABLE_AND_COLUMN_INFO:
  default:
    break;
  }
  return nullptr;
}
#endif

static std::unique_ptr<const zetasql::ResolvedAlterAction> make_unique_action(void *arg)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg;
  switch (node->node_kind()) {
  case zetasql::RESOLVED_SET_OPTIONS_ACTION:{
    auto ret = zetasql::MakeResolvedSetOptionsAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedSetOptionsAction));
    return ret;
  }
  case zetasql::RESOLVED_ADD_COLUMN_ACTION:{
    auto ret = zetasql::MakeResolvedAddColumnAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAddColumnAction));
    return ret;
  }
  case zetasql::RESOLVED_ADD_CONSTRAINT_ACTION:{
    auto ret = zetasql::MakeResolvedAddConstraintAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAddConstraintAction));
    return ret;
  }
  case zetasql::RESOLVED_DROP_CONSTRAINT_ACTION:{
    auto ret = zetasql::MakeResolvedDropConstraintAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedDropConstraintAction));
    return ret;
  }
  case zetasql::RESOLVED_DROP_PRIMARY_KEY_ACTION:{
    auto ret = zetasql::MakeResolvedDropPrimaryKeyAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedDropPrimaryKeyAction));
    return ret;
  }
  case zetasql::RESOLVED_ALTER_COLUMN_OPTIONS_ACTION:{
    auto ret = zetasql::MakeResolvedAlterColumnOptionsAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAlterColumnOptionsAction));
    return ret;
  }
  case zetasql::RESOLVED_ALTER_COLUMN_DROP_NOT_NULL_ACTION:{
    auto ret = zetasql::MakeResolvedAlterColumnDropNotNullAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAlterColumnDropNotNullAction));
    return ret;
  }
  case zetasql::RESOLVED_ALTER_COLUMN_SET_DATA_TYPE_ACTION:{
    auto ret = zetasql::MakeResolvedAlterColumnSetDataTypeAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAlterColumnSetDataTypeAction));
    return ret;
  }
  case zetasql::RESOLVED_ALTER_COLUMN_SET_DEFAULT_ACTION:{
    auto ret = zetasql::MakeResolvedAlterColumnSetDefaultAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAlterColumnSetDefaultAction));
    return ret;
  }
  case zetasql::RESOLVED_ALTER_COLUMN_DROP_DEFAULT_ACTION:{
    auto ret = zetasql::MakeResolvedAlterColumnDropDefaultAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAlterColumnDropDefaultAction));
    return ret;
  }
  case zetasql::RESOLVED_DROP_COLUMN_ACTION:{
    auto ret = zetasql::MakeResolvedDropColumnAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedDropColumnAction));
    return ret;
  }
  case zetasql::RESOLVED_RENAME_COLUMN_ACTION:{
    auto ret = zetasql::MakeResolvedRenameColumnAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedRenameColumnAction));
    return ret;
  }
  case zetasql::RESOLVED_SET_AS_ACTION:{
    auto ret = zetasql::MakeResolvedSetAsAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedSetAsAction));
    return ret;
  }
  case zetasql::RESOLVED_SET_COLLATE_CLAUSE:{
    auto ret = zetasql::MakeResolvedSetCollateClause();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedSetCollateClause));
    return ret;
  }
  case zetasql::RESOLVED_GRANT_TO_ACTION:{
    auto ret = zetasql::MakeResolvedGrantToAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedGrantToAction));
    return ret;
  }
  case zetasql::RESOLVED_RESTRICT_TO_ACTION:{
    auto ret = zetasql::MakeResolvedRestrictToAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedRestrictToAction));
    return ret;
  }
  case zetasql::RESOLVED_ADD_TO_RESTRICTEE_LIST_ACTION:{
    auto ret = zetasql::MakeResolvedAddToRestricteeListAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAddToRestricteeListAction));
    return ret;
  }
  case zetasql::RESOLVED_REMOVE_FROM_RESTRICTEE_LIST_ACTION:{
    auto ret = zetasql::MakeResolvedRemoveFromRestricteeListAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedRemoveFromRestricteeListAction));
    return ret;
  }
  case zetasql::RESOLVED_FILTER_USING_ACTION:{
    auto ret = zetasql::MakeResolvedFilterUsingAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedFilterUsingAction));
    return ret;
  }
  case zetasql::RESOLVED_REVOKE_FROM_ACTION:{
    auto ret = zetasql::MakeResolvedRevokeFromAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedRevokeFromAction));
    return ret;
  }
  case zetasql::RESOLVED_RENAME_TO_ACTION:{
    auto ret = zetasql::MakeResolvedRenameToAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedRenameToAction));
    return ret;
  }
  default:
    break;
  }
  return nullptr;
}

static std::unique_ptr<const zetasql::ResolvedConstraint> make_unique_constraint(void *arg)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg;
  switch (node->node_kind()) {
  case zetasql::RESOLVED_PRIMARY_KEY:{
    auto ret = zetasql::MakeResolvedPrimaryKey();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedPrimaryKey));
    return ret;
  }
  case zetasql::RESOLVED_FOREIGN_KEY:{
    auto ret = zetasql::MakeResolvedForeignKey();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedForeignKey));
    return ret;
  }
  case zetasql::RESOLVED_CHECK_CONSTRAINT:{
    auto ret = zetasql::MakeResolvedCheckConstraint();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCheckConstraint));
    return ret;
  }
  default:
    break;
  }
  return nullptr;
}

static std::unique_ptr<const zetasql::ResolvedExpr> make_unique_expr(void *arg)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg;
  switch (node->node_kind()) {
  case zetasql::RESOLVED_LITERAL: {
    std::unique_ptr<zetasql::ResolvedLiteral> ret = zetasql::MakeResolvedLiteral();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedLiteral));
    return ret;
  }
  case zetasql::RESOLVED_PARAMETER:{
    std::unique_ptr<zetasql::ResolvedParameter> ret = zetasql::MakeResolvedParameter();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedParameter));
    return ret;
  }
  case zetasql::RESOLVED_EXPRESSION_COLUMN:{
    std::unique_ptr<zetasql::ResolvedExpressionColumn> ret = zetasql::MakeResolvedExpressionColumn();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedExpressionColumn));
    return ret;
  }
  case zetasql::RESOLVED_COLUMN_REF:{
    std::unique_ptr<zetasql::ResolvedColumnRef> ret = zetasql::MakeResolvedColumnRef();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedColumnRef));
    return ret;
  }
  case zetasql::RESOLVED_CONSTANT:{
    std::unique_ptr<zetasql::ResolvedConstant> ret = zetasql::MakeResolvedConstant();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedConstant));
    return ret;
  }
  case zetasql::RESOLVED_SYSTEM_VARIABLE:{
    std::unique_ptr<zetasql::ResolvedSystemVariable> ret = zetasql::MakeResolvedSystemVariable();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedSystemVariable));
    return ret;
  }
  case zetasql::RESOLVED_FILTER_FIELD:{
    std::unique_ptr<zetasql::ResolvedFilterField> ret = zetasql::MakeResolvedFilterField();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedFilterField));
    return ret;
  }
  case zetasql::RESOLVED_FUNCTION_CALL:{
#if 0
    auto call = (zetasql::ResolvedFunctionCall *)node;
    return zetasql::MakeResolvedFunctionCall(
        call->type(),
        call->function(),
        call->signature(),
        call->argument_list(),
        call->generic_argument_list(),
        call->error_mode(),
        call->function_call_info()
    );
#endif
    break;
  }
  case zetasql::RESOLVED_AGGREGATE_FUNCTION_CALL:{
#if 0
    auto call = (zetasql::ResolvedAggregateFunctionCall *)node;
    return zetasql::MakeResolvedAggregateFunctionCall(
        call->type(),
        call->function(),
        call->signature(),
        call->argument_list(),
        call->generic_argument_list(),
        call->error_mode(),
        call->distinct(),
        call->null_handling_modifier(),
        call->having_modifier(),
        call->order_by_item_list(),
        call->limit(),
        call->function_call_info()
    );
#endif
    break;
  }
  case zetasql::RESOLVED_ANALYTIC_FUNCTION_CALL:{
#if 0
    auto call = (zetasql::ResolvedAnalyticFunctionCall *)node;
    return zetasql::MakeResolvedAnalyticFunctionCall(
        call->type(),
        call->function(),
        call->signature(),
        call->argument_list(),
        call->generic_argument_list(),
        call->error_mode(),
        call->distinct(),
        call->null_handling_modifier(),
        call->window_frame()
    );
#endif
    break;
  }
  case zetasql::RESOLVED_CAST:{
    std::unique_ptr<zetasql::ResolvedCast> ret = zetasql::MakeResolvedCast();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCast));
    return ret;
  }
  case zetasql::RESOLVED_MAKE_STRUCT:{
    std::unique_ptr<zetasql::ResolvedMakeStruct> ret = zetasql::MakeResolvedMakeStruct();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedMakeStruct));
    return ret;
  }
  case zetasql::RESOLVED_MAKE_PROTO:{
    std::unique_ptr<zetasql::ResolvedMakeProto> ret = zetasql::MakeResolvedMakeProto();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedMakeProto));
    return ret;
  }
  case zetasql::RESOLVED_GET_STRUCT_FIELD:{
    std::unique_ptr<zetasql::ResolvedGetStructField> ret = zetasql::MakeResolvedGetStructField();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedGetStructField));
    return ret;
  }
  case zetasql::RESOLVED_GET_PROTO_FIELD:{
    std::unique_ptr<zetasql::ResolvedGetProtoField> ret = zetasql::MakeResolvedGetProtoField();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedGetProtoField));
    return ret;
  }
  case zetasql::RESOLVED_GET_JSON_FIELD:{
    std::unique_ptr<zetasql::ResolvedGetJsonField> ret = zetasql::MakeResolvedGetJsonField();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedGetJsonField));
    return ret;
  }
  case zetasql::RESOLVED_FLATTEN:{
    std::unique_ptr<zetasql::ResolvedFlatten> ret = zetasql::MakeResolvedFlatten();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedFlatten));
    return ret;
  }
  case zetasql::RESOLVED_FLATTENED_ARG:{
    std::unique_ptr<zetasql::ResolvedFlattenedArg> ret = zetasql::MakeResolvedFlattenedArg();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedFlattenedArg));
    return ret;
  }
  case zetasql::RESOLVED_REPLACE_FIELD:{
    std::unique_ptr<zetasql::ResolvedReplaceField> ret = zetasql::MakeResolvedReplaceField();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedReplaceField));
    return ret;
  }
  case zetasql::RESOLVED_SUBQUERY_EXPR:{
    std::unique_ptr<zetasql::ResolvedSubqueryExpr> ret = zetasql::MakeResolvedSubqueryExpr();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedSubqueryExpr));
    return ret;
  }
  case zetasql::RESOLVED_LET_EXPR:{
#if 0
    auto expr = (zetasql::ResolvedLetExpr *)node;
    return zetasql::MakeResolvedLetExpr(
        expr->type(),
        expr->assignment_list(),
        expr->expr()
    );
#endif
    break;
  }
  case zetasql::RESOLVED_DMLDEFAULT:{
    std::unique_ptr<zetasql::ResolvedDMLDefault> ret = zetasql::MakeResolvedDMLDefault();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedDMLDefault));
    return ret;
  }
  case zetasql::RESOLVED_ARGUMENT_REF:{
    std::unique_ptr<zetasql::ResolvedArgumentRef> ret = zetasql::MakeResolvedArgumentRef();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedArgumentRef));
    return ret;
  }
  default:
    break;
  }
  return nullptr;
}

static std::unique_ptr<const zetasql::ResolvedStatement> make_unique_stmt(void *arg)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg;
  switch (node->node_kind()) {
  case zetasql::RESOLVED_EXPLAIN_STMT:{
    std::unique_ptr<zetasql::ResolvedExplainStmt> ret = zetasql::MakeResolvedExplainStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedExplainStmt));
    return ret;
  }
  case zetasql::RESOLVED_QUERY_STMT:{
    std::unique_ptr<zetasql::ResolvedQueryStmt> ret = zetasql::MakeResolvedQueryStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedQueryStmt));
    return ret;
  }
  case zetasql::RESOLVED_CREATE_DATABASE_STMT:{
    std::unique_ptr<zetasql::ResolvedCreateDatabaseStmt> ret = zetasql::MakeResolvedCreateDatabaseStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreateDatabaseStmt));
    return ret;
  }
  case zetasql::RESOLVED_CREATE_INDEX_STMT:{
    std::unique_ptr<zetasql::ResolvedCreateIndexStmt> ret = zetasql::MakeResolvedCreateIndexStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreateIndexStmt));
    return ret;
  }
  case zetasql::RESOLVED_CREATE_SCHEMA_STMT:{
    std::unique_ptr<zetasql::ResolvedCreateSchemaStmt> ret = zetasql::MakeResolvedCreateSchemaStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreateSchemaStmt));
    return ret;
  }
  case zetasql::RESOLVED_CREATE_TABLE_STMT:{
    std::unique_ptr<zetasql::ResolvedCreateTableStmt> ret = zetasql::MakeResolvedCreateTableStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreateTableStmt));
    return ret;
  }
  case zetasql::RESOLVED_CREATE_TABLE_AS_SELECT_STMT:{
    std::unique_ptr<zetasql::ResolvedCreateTableAsSelectStmt> ret = zetasql::MakeResolvedCreateTableAsSelectStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreateTableAsSelectStmt));
    return ret;
  }
  case zetasql::RESOLVED_CREATE_MODEL_STMT:{
    std::unique_ptr<zetasql::ResolvedCreateModelStmt> ret = zetasql::MakeResolvedCreateModelStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreateModelStmt));
    return ret;
  }
  case zetasql::RESOLVED_CREATE_VIEW_STMT:{
    std::unique_ptr<zetasql::ResolvedCreateViewStmt> ret = zetasql::MakeResolvedCreateViewStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreateViewStmt));
    return ret;
  }
  case zetasql::RESOLVED_CREATE_SNAPSHOT_TABLE_STMT:{
    std::unique_ptr<zetasql::ResolvedCreateSnapshotTableStmt> ret = zetasql::MakeResolvedCreateSnapshotTableStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreateSnapshotTableStmt));
    return ret;
  }
  case zetasql::RESOLVED_CREATE_EXTERNAL_TABLE_STMT:{
    std::unique_ptr<zetasql::ResolvedCreateExternalTableStmt> ret = zetasql::MakeResolvedCreateExternalTableStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreateExternalTableStmt));
    return ret;
  }
  case zetasql::RESOLVED_EXPORT_MODEL_STMT:{
    std::unique_ptr<zetasql::ResolvedExportModelStmt> ret = zetasql::MakeResolvedExportModelStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedExportModelStmt));
    return ret;
  }
  case zetasql::RESOLVED_EXPORT_DATA_STMT:{
    std::unique_ptr<zetasql::ResolvedExportDataStmt> ret = zetasql::MakeResolvedExportDataStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedExportDataStmt));
    return ret;
  }
  case zetasql::RESOLVED_DEFINE_TABLE_STMT:{
    std::unique_ptr<zetasql::ResolvedDefineTableStmt> ret = zetasql::MakeResolvedDefineTableStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedDefineTableStmt));
    return ret;
  }
  case zetasql::RESOLVED_DESCRIBE_STMT:{
    std::unique_ptr<zetasql::ResolvedDescribeStmt> ret = zetasql::MakeResolvedDescribeStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedDescribeStmt));
    return ret;
  }
  case zetasql::RESOLVED_SHOW_STMT:{
    std::unique_ptr<zetasql::ResolvedShowStmt> ret = zetasql::MakeResolvedShowStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedShowStmt));
    return ret;
  }
  case zetasql::RESOLVED_BEGIN_STMT:{
    std::unique_ptr<zetasql::ResolvedBeginStmt> ret = zetasql::MakeResolvedBeginStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedBeginStmt));
    return ret;
  }
  case zetasql::RESOLVED_SET_TRANSACTION_STMT:{
    std::unique_ptr<zetasql::ResolvedSetTransactionStmt> ret = zetasql::MakeResolvedSetTransactionStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedSetTransactionStmt));
    return ret;
  }
  case zetasql::RESOLVED_COMMIT_STMT:{
    std::unique_ptr<zetasql::ResolvedCommitStmt> ret = zetasql::MakeResolvedCommitStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCommitStmt));
    return ret;
  }
  case zetasql::RESOLVED_ROLLBACK_STMT:{
    std::unique_ptr<zetasql::ResolvedRollbackStmt> ret = zetasql::MakeResolvedRollbackStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedRollbackStmt));
    return ret;
  }
  case zetasql::RESOLVED_START_BATCH_STMT:{
    std::unique_ptr<zetasql::ResolvedStartBatchStmt> ret = zetasql::MakeResolvedStartBatchStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedStartBatchStmt));
    return ret;
  }
  case zetasql::RESOLVED_RUN_BATCH_STMT:{
    std::unique_ptr<zetasql::ResolvedRunBatchStmt> ret = zetasql::MakeResolvedRunBatchStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedRunBatchStmt));
    return ret;
  }
  case zetasql::RESOLVED_ABORT_BATCH_STMT:{
    std::unique_ptr<zetasql::ResolvedAbortBatchStmt> ret = zetasql::MakeResolvedAbortBatchStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAbortBatchStmt));
    return ret;
  }
  case zetasql::RESOLVED_DROP_STMT:{
    std::unique_ptr<zetasql::ResolvedDropStmt> ret = zetasql::MakeResolvedDropStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedDropStmt));
    return ret;
  }
  case zetasql::RESOLVED_DROP_MATERIALIZED_VIEW_STMT:{
    std::unique_ptr<zetasql::ResolvedDropMaterializedViewStmt> ret = zetasql::MakeResolvedDropMaterializedViewStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedDropMaterializedViewStmt));
    return ret;
  }
  case zetasql::RESOLVED_DROP_SNAPSHOT_TABLE_STMT:{
    std::unique_ptr<zetasql::ResolvedDropSnapshotTableStmt> ret = zetasql::MakeResolvedDropSnapshotTableStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedDropSnapshotTableStmt));
    return ret;
  }
  case zetasql::RESOLVED_ASSERT_STMT:{
    std::unique_ptr<zetasql::ResolvedAssertStmt> ret = zetasql::MakeResolvedAssertStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAssertStmt));
    return ret;
  }
  case zetasql::RESOLVED_INSERT_STMT:{
    std::unique_ptr<zetasql::ResolvedInsertStmt> ret = zetasql::MakeResolvedInsertStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedInsertStmt));
    return ret;
  }
  case zetasql::RESOLVED_DELETE_STMT:{
    std::unique_ptr<zetasql::ResolvedDeleteStmt> ret = zetasql::MakeResolvedDeleteStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedDeleteStmt));
    return ret;
  }
  case zetasql::RESOLVED_UPDATE_STMT:{
    std::unique_ptr<zetasql::ResolvedUpdateStmt> ret = zetasql::MakeResolvedUpdateStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedUpdateStmt));
    return ret;
  }
  case zetasql::RESOLVED_MERGE_STMT:{
    std::unique_ptr<zetasql::ResolvedMergeStmt> ret = zetasql::MakeResolvedMergeStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedMergeStmt));
    return ret;
  }
  case zetasql::RESOLVED_TRUNCATE_STMT:{
    std::unique_ptr<zetasql::ResolvedTruncateStmt> ret = zetasql::MakeResolvedTruncateStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedTruncateStmt));
    return ret;
  }
  case zetasql::RESOLVED_GRANT_STMT:{
    std::unique_ptr<zetasql::ResolvedGrantStmt> ret = zetasql::MakeResolvedGrantStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedGrantStmt));
    return ret;
  }
  case zetasql::RESOLVED_REVOKE_STMT:{
    std::unique_ptr<zetasql::ResolvedRevokeStmt> ret = zetasql::MakeResolvedRevokeStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedRevokeStmt));
    return ret;
  }
  case zetasql::RESOLVED_ALTER_DATABASE_STMT:{
    std::unique_ptr<zetasql::ResolvedAlterDatabaseStmt> ret = zetasql::MakeResolvedAlterDatabaseStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAlterDatabaseStmt));
    return ret;
  }
  case zetasql::RESOLVED_ALTER_MATERIALIZED_VIEW_STMT:{
    std::unique_ptr<zetasql::ResolvedAlterMaterializedViewStmt> ret = zetasql::MakeResolvedAlterMaterializedViewStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAlterMaterializedViewStmt));
    return ret;
  }
  case zetasql::RESOLVED_ALTER_SCHEMA_STMT:{
    std::unique_ptr<zetasql::ResolvedAlterSchemaStmt> ret = zetasql::MakeResolvedAlterSchemaStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAlterSchemaStmt));
    return ret;
  }
  case zetasql::RESOLVED_ALTER_TABLE_STMT:{
    std::unique_ptr<zetasql::ResolvedAlterTableStmt> ret = zetasql::MakeResolvedAlterTableStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAlterTableStmt));
    return ret;
  }
  case zetasql::RESOLVED_ALTER_VIEW_STMT:{
    std::unique_ptr<zetasql::ResolvedAlterViewStmt> ret = zetasql::MakeResolvedAlterViewStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAlterViewStmt));
    return ret;
  }
  case zetasql::RESOLVED_ALTER_TABLE_SET_OPTIONS_STMT:{
    std::unique_ptr<zetasql::ResolvedAlterTableSetOptionsStmt> ret = zetasql::MakeResolvedAlterTableSetOptionsStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAlterTableSetOptionsStmt));
    return ret;
  }
  case zetasql::RESOLVED_RENAME_STMT:{
    std::unique_ptr<zetasql::ResolvedRenameStmt> ret = zetasql::MakeResolvedRenameStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedRenameStmt));
    return ret;
  }
  case zetasql::RESOLVED_CREATE_PRIVILEGE_RESTRICTION_STMT:{
    std::unique_ptr<zetasql::ResolvedCreatePrivilegeRestrictionStmt> ret = zetasql::MakeResolvedCreatePrivilegeRestrictionStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreatePrivilegeRestrictionStmt));
    return ret;
  }
  case zetasql::RESOLVED_CREATE_ROW_ACCESS_POLICY_STMT:{
    std::unique_ptr<zetasql::ResolvedCreateRowAccessPolicyStmt> ret = zetasql::MakeResolvedCreateRowAccessPolicyStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreateRowAccessPolicyStmt));
    return ret;
  }
  case zetasql::RESOLVED_DROP_PRIVILEGE_RESTRICTION_STMT:{
    std::unique_ptr<zetasql::ResolvedDropPrivilegeRestrictionStmt> ret = zetasql::MakeResolvedDropPrivilegeRestrictionStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedDropPrivilegeRestrictionStmt));
    return ret;
  }
  case zetasql::RESOLVED_DROP_ROW_ACCESS_POLICY_STMT:{
    std::unique_ptr<zetasql::ResolvedDropRowAccessPolicyStmt> ret = zetasql::MakeResolvedDropRowAccessPolicyStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedDropRowAccessPolicyStmt));
    return ret;
  }
  case zetasql::RESOLVED_DROP_SEARCH_INDEX_STMT:{
    std::unique_ptr<zetasql::ResolvedDropSearchIndexStmt> ret = zetasql::MakeResolvedDropSearchIndexStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedDropSearchIndexStmt));
    return ret;
  }
  case zetasql::RESOLVED_ALTER_PRIVILEGE_RESTRICTION_STMT:{
    std::unique_ptr<zetasql::ResolvedAlterPrivilegeRestrictionStmt> ret = zetasql::MakeResolvedAlterPrivilegeRestrictionStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAlterPrivilegeRestrictionStmt));
    return ret;
  }
  case zetasql::RESOLVED_ALTER_ROW_ACCESS_POLICY_STMT:{
    std::unique_ptr<zetasql::ResolvedAlterRowAccessPolicyStmt> ret = zetasql::MakeResolvedAlterRowAccessPolicyStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAlterRowAccessPolicyStmt));
    return ret;
  }
  case zetasql::RESOLVED_ALTER_ALL_ROW_ACCESS_POLICIES_STMT:{
    std::unique_ptr<zetasql::ResolvedAlterAllRowAccessPoliciesStmt> ret = zetasql::MakeResolvedAlterAllRowAccessPoliciesStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAlterAllRowAccessPoliciesStmt));
    return ret;
  }
  case zetasql::RESOLVED_CREATE_CONSTANT_STMT:{
#if 0
    std::unique_ptr<zetasql::ResolvedCreateConstantStmt> ret = zetasql::MakeResolvedCreateConstantStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreateConstantStmt));
    return ret;
#endif
    break;
  }
  case zetasql::RESOLVED_CREATE_FUNCTION_STMT:{
#if 0
    auto stmt = (zetasql::ResolvedCreateFunctionStmt *)node;
    return zetasql::MakeResolvedCreateFunctionStmt(
        stmt->name_path(),
        stmt->create_scope(),
        stmt->has_explicit_return_type(),
        stmt->return_type(),
        stmt->argument_name_list(),
        stmt->signature(),
        stmt->is_aggregate(),
        stmt->language(),
        stmt->code(),
        stmt->aggregate_expression_list(),
        stmt->function_expression(),
        stmt->option_list(),
        stmt->sql_security(),
        stmt->determinism_level(),
        stmt->is_remote(),
        stmt->connection()
    );
#endif
    break;
  }
  case zetasql::RESOLVED_CREATE_TABLE_FUNCTION_STMT:{
#if 0
    std::unique_ptr<zetasql::ResolvedCreateTableFunctionStmt> ret = zetasql::MakeResolvedCreateTableFunctionStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreateTableFunctionStmt));
    return ret;
#endif
    break;
  }
  case zetasql::RESOLVED_DROP_FUNCTION_STMT:{
    std::unique_ptr<zetasql::ResolvedDropFunctionStmt> ret = zetasql::MakeResolvedDropFunctionStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedDropFunctionStmt));
    return ret;
  }
  case zetasql::RESOLVED_DROP_TABLE_FUNCTION_STMT:{
    std::unique_ptr<zetasql::ResolvedDropTableFunctionStmt> ret = zetasql::MakeResolvedDropTableFunctionStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedDropTableFunctionStmt));
    return ret;
  }
  case zetasql::RESOLVED_CALL_STMT:{
#if 0
    std::unique_ptr<zetasql::ResolvedCallStmt> ret = zetasql::MakeResolvedCallStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCallStmt));
    return ret;
#endif
    break;
  }
  case zetasql::RESOLVED_IMPORT_STMT:{
    std::unique_ptr<zetasql::ResolvedImportStmt> ret = zetasql::MakeResolvedImportStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedImportStmt));
    return ret;
  }
  case zetasql::RESOLVED_MODULE_STMT:{
    std::unique_ptr<zetasql::ResolvedModuleStmt> ret = zetasql::MakeResolvedModuleStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedModuleStmt));
    return ret;
  }
  case zetasql::RESOLVED_CREATE_MATERIALIZED_VIEW_STMT:{
    std::unique_ptr<zetasql::ResolvedCreateMaterializedViewStmt> ret = zetasql::MakeResolvedCreateMaterializedViewStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreateMaterializedViewStmt));
    return ret;
  }
  case zetasql::RESOLVED_CREATE_PROCEDURE_STMT:{
#if 0
    std::unique_ptr<zetasql::ResolvedCreateProcedureStmt> ret = zetasql::MakeResolvedCreateProcedureStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreateProcedureStmt));
    return ret;
#endif
    break;
  }
  case zetasql::RESOLVED_EXECUTE_IMMEDIATE_STMT:{
    std::unique_ptr<zetasql::ResolvedExecuteImmediateStmt> ret = zetasql::MakeResolvedExecuteImmediateStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedExecuteImmediateStmt));
    return ret;
  }
  case zetasql::RESOLVED_ASSIGNMENT_STMT:{
    std::unique_ptr<zetasql::ResolvedAssignmentStmt> ret = zetasql::MakeResolvedAssignmentStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAssignmentStmt));
    return ret;
  }
  case zetasql::RESOLVED_CREATE_ENTITY_STMT:{
    std::unique_ptr<zetasql::ResolvedCreateEntityStmt> ret = zetasql::MakeResolvedCreateEntityStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCreateEntityStmt));
    return ret;
  }
  case zetasql::RESOLVED_ALTER_ENTITY_STMT:{
    std::unique_ptr<zetasql::ResolvedAlterEntityStmt> ret = zetasql::MakeResolvedAlterEntityStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAlterEntityStmt));
    return ret;
  }
  case zetasql::RESOLVED_CLONE_DATA_STMT:{
    std::unique_ptr<zetasql::ResolvedCloneDataStmt> ret = zetasql::MakeResolvedCloneDataStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedCloneDataStmt));
    return ret;
  }
  case zetasql::RESOLVED_ANALYZE_STMT:{
    std::unique_ptr<zetasql::ResolvedAnalyzeStmt> ret = zetasql::MakeResolvedAnalyzeStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAnalyzeStmt));
    return ret;
  }
  case zetasql::RESOLVED_AUX_LOAD_DATA_STMT:{
    std::unique_ptr<zetasql::ResolvedAuxLoadDataStmt> ret = zetasql::MakeResolvedAuxLoadDataStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAuxLoadDataStmt));
    return ret;
  }
  default:
    break;
  }
  return nullptr;
}

static std::unique_ptr<const zetasql::ResolvedScan> make_unique_scan(void *arg)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg;
  switch (node->node_kind()) {
  case zetasql::RESOLVED_SINGLE_ROW_SCAN:{
    std::unique_ptr<zetasql::ResolvedSingleRowScan> ret = zetasql::MakeResolvedSingleRowScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedSingleRowScan));
    return ret;
  }
  case zetasql::RESOLVED_TABLE_SCAN:{
    std::unique_ptr<zetasql::ResolvedTableScan> ret = zetasql::MakeResolvedTableScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedTableScan));
    return ret;
  }
  case zetasql::RESOLVED_JOIN_SCAN:{
    std::unique_ptr<zetasql::ResolvedJoinScan> ret = zetasql::MakeResolvedJoinScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedJoinScan));
    return ret;
  }
  case zetasql::RESOLVED_ARRAY_SCAN:{
    std::unique_ptr<zetasql::ResolvedArrayScan> ret = zetasql::MakeResolvedArrayScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedArrayScan));
    return ret;
  }
  case zetasql::RESOLVED_FILTER_SCAN:{
    std::unique_ptr<zetasql::ResolvedFilterScan> ret = zetasql::MakeResolvedFilterScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedFilterScan));
    return ret;
  }
  case zetasql::RESOLVED_AGGREGATE_SCAN:{
    std::unique_ptr<zetasql::ResolvedAggregateScan> ret = zetasql::MakeResolvedAggregateScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAggregateScan));
    return ret;
  }
  case zetasql::RESOLVED_ANONYMIZED_AGGREGATE_SCAN:{
    std::unique_ptr<zetasql::ResolvedAnonymizedAggregateScan> ret = zetasql::MakeResolvedAnonymizedAggregateScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAnonymizedAggregateScan));
    return ret;
  }
  case zetasql::RESOLVED_SET_OPERATION_SCAN:{
    std::unique_ptr<zetasql::ResolvedSetOperationScan> ret = zetasql::MakeResolvedSetOperationScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedSetOperationScan));
    return ret;
  }
  case zetasql::RESOLVED_ORDER_BY_SCAN:{
    std::unique_ptr<zetasql::ResolvedOrderByScan> ret = zetasql::MakeResolvedOrderByScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedOrderByScan));
    return ret;
  }
  case zetasql::RESOLVED_LIMIT_OFFSET_SCAN:{
    std::unique_ptr<zetasql::ResolvedLimitOffsetScan> ret = zetasql::MakeResolvedLimitOffsetScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedLimitOffsetScan));
    return ret;
  }
  case zetasql::RESOLVED_WITH_REF_SCAN:{
    std::unique_ptr<zetasql::ResolvedWithRefScan> ret = zetasql::MakeResolvedWithRefScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedWithRefScan));
    return ret;
  }
  case zetasql::RESOLVED_ANALYTIC_SCAN:{
    std::unique_ptr<zetasql::ResolvedAnalyticScan> ret = zetasql::MakeResolvedAnalyticScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedAnalyticScan));
    return ret;
  }
  case zetasql::RESOLVED_SAMPLE_SCAN:{
    std::unique_ptr<zetasql::ResolvedSampleScan> ret = zetasql::MakeResolvedSampleScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedSampleScan));
    return ret;
  }
  case zetasql::RESOLVED_PROJECT_SCAN:{
    std::unique_ptr<zetasql::ResolvedProjectScan> ret = zetasql::MakeResolvedProjectScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedProjectScan));
    return ret;
  }
  case zetasql::RESOLVED_TVFSCAN:{
    auto scan = (zetasql::ResolvedTVFScan *)arg;
    std::vector<std::unique_ptr<const zetasql::ResolvedFunctionArgument>> argument_list;
    for (int i = 0; i < scan->argument_list_size(); i++) {
      auto a = zetasql::MakeResolvedFunctionArgument();
      memcpy((void *)a.get(), (void *)scan->argument_list(i), sizeof(zetasql::ResolvedFunctionArgument));
      argument_list.push_back(std::move(a));
    }
    return zetasql::MakeResolvedTVFScan(
      scan->column_list(),
      scan->tvf(),
      scan->signature(),
      std::move(argument_list),
      scan->column_index_list(),
      scan->alias(),
      scan->function_call_signature()
    );
  }
  case zetasql::RESOLVED_GROUP_ROWS_SCAN:{
    auto scan = (zetasql::ResolvedGroupRowsScan *)arg;
    std::vector<std::unique_ptr<const zetasql::ResolvedComputedColumn>> input_column_list;
    for (int i = 0; i < scan->input_column_list_size(); i++) {
      auto col = zetasql::MakeResolvedComputedColumn();
      memcpy((void *)col.get(), (void *)scan->input_column_list(i), sizeof(zetasql::ResolvedComputedColumn));
      input_column_list.push_back(std::move(col));
    }
    return zetasql::MakeResolvedGroupRowsScan(
      scan->column_list(),
      std::move(input_column_list),
      scan->alias()
    );
  }
  case zetasql::RESOLVED_RECURSIVE_REF_SCAN:{
    std::unique_ptr<zetasql::ResolvedRecursiveRefScan> ret = zetasql::MakeResolvedRecursiveRefScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedRecursiveRefScan));
    return ret;
  }
  case zetasql::RESOLVED_RECURSIVE_SCAN:{
    std::unique_ptr<zetasql::ResolvedRecursiveScan> ret = zetasql::MakeResolvedRecursiveScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedRecursiveScan));
    return ret;
  }
  case zetasql::RESOLVED_WITH_SCAN:{
    std::unique_ptr<zetasql::ResolvedWithScan> ret = zetasql::MakeResolvedWithScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedWithScan));
    return ret;
  }
  case zetasql::RESOLVED_RELATION_ARGUMENT_SCAN:{
    std::unique_ptr<zetasql::ResolvedRelationArgumentScan> ret = zetasql::MakeResolvedRelationArgumentScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedRelationArgumentScan));
    return ret;
  }
  case zetasql::RESOLVED_PIVOT_SCAN:{
    std::unique_ptr<zetasql::ResolvedPivotScan> ret = zetasql::MakeResolvedPivotScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedPivotScan));
    return ret;
  }
  case zetasql::RESOLVED_UNPIVOT_SCAN:{
    std::unique_ptr<zetasql::ResolvedUnpivotScan> ret = zetasql::MakeResolvedUnpivotScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(zetasql::ResolvedUnpivotScan));
    return ret;
  }
  default:
    break;
  }
  return nullptr;
}

void GO_EXPORT(LanguageOptions_new)(void ** arg0){
  *arg0 = (void *)(new zetasql::LanguageOptions());
}

void GO_EXPORT(LanguageOptions_SupportsStatementKind)(void * arg0,int arg1,char* arg2){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  *arg2 = opt->SupportsStatementKind((zetasql::ResolvedNodeKind)arg1);
}

void GO_EXPORT(LanguageOptions_SetSupportedStatementKinds)(void * arg0,void * arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  std::set<zetasql::ResolvedNodeKind> kinds;
  GoSlice *goslice = (GoSlice *)arg1;
  void **data = (void **)goslice->data;
  for (int i = 0; i < goslice->len; i++) {
    kinds.insert((zetasql::ResolvedNodeKind)(uintptr_t)data[i]);
  }
  opt->SetSupportedStatementKinds(kinds);
}

void GO_EXPORT(LanguageOptions_SetSupportsAllStatementKinds)(void * arg0){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  opt->SetSupportsAllStatementKinds();
}

void GO_EXPORT(LanguageOptions_AddSupportedStatementKind)(void * arg0,int arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  opt->AddSupportedStatementKind((zetasql::ResolvedNodeKind)arg1);
}

void GO_EXPORT(LanguageOptions_LanguageFeatureEnabled)(void * arg0,int arg1,char* arg2){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  *arg2 = opt->LanguageFeatureEnabled((zetasql::LanguageFeature)arg1);
}

void GO_EXPORT(LanguageOptions_SetLanguageVersion)(void * arg0,int arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  opt->SetLanguageVersion((zetasql::LanguageVersion)arg1);
}

void GO_EXPORT(LanguageOptions_EnableLanguageFeature)(void * arg0,int arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  opt->EnableLanguageFeature((zetasql::LanguageFeature)arg1);
}

void GO_EXPORT(LanguageOptions_SetEnabledLanguageFeatures)(void * arg0,void * arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  zetasql::LanguageOptions::LanguageFeatureSet features;
  GoSlice *goslice = (GoSlice *)arg1;
  void **data = (void **)goslice->data;
  for (int i = 0; i < goslice->len; i++) {
    features.insert((zetasql::LanguageFeature)(uintptr_t)data[i]);
  }
  opt->SetEnabledLanguageFeatures(features);
}

void GO_EXPORT(LanguageOptions_EnabledLanguageFeatures)(void * arg0,void ** arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  auto features = opt->GetEnabledLanguageFeatures();
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  int *data = (int *)malloc(sizeof(int) * features.size());
  int i = 0;
  for (auto it = features.begin(); it != features.end(); it++, i++) {
    data[i] = *it;
  }
  slice->data = (void *)data;
  slice->len = features.size();
  slice->cap = features.size();
  *arg1 = (void *)slice;
}

void GO_EXPORT(LanguageOptions_EnabledLanguageFeaturesAsString)(void * arg0,void ** arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  *arg1 = (void *)((new std::string(opt->GetEnabledLanguageFeaturesAsString()))->c_str());
}

void GO_EXPORT(LanguageOptions_DisableAllLanguageFeatures)(void * arg0){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  opt->DisableAllLanguageFeatures();
}

void GO_EXPORT(LanguageOptions_EnableMaximumLanguageFeatures)(void * arg0){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  opt->EnableMaximumLanguageFeatures();
}

void GO_EXPORT(LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment)(void * arg0){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  opt->EnableMaximumLanguageFeaturesForDevelopment();
}

void GO_EXPORT(LanguageOptions_set_name_resolution_mode)(void * arg0,int arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  opt->set_name_resolution_mode((zetasql::NameResolutionMode)arg1);
}

void GO_EXPORT(LanguageOptions_name_resolution_mode)(void * arg0,int* arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  *arg1 = opt->name_resolution_mode();
}

void GO_EXPORT(LanguageOptions_set_product_mode)(void * arg0,int arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  opt->set_product_mode((zetasql::ProductMode)arg1);
}

void GO_EXPORT(LanguageOptions_product_mode)(void * arg0,int* arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  *arg1 = opt->product_mode();
}

void GO_EXPORT(LanguageOptions_SupportsProtoTypes)(void * arg0,char* arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  *arg1 = opt->SupportsProtoTypes();
}

void GO_EXPORT(LanguageOptions_set_error_on_deprecated_syntax)(void * arg0,int arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  opt->set_error_on_deprecated_syntax(arg1);
}

void GO_EXPORT(LanguageOptions_error_on_deprecated_syntax)(void * arg0,char* arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  *arg1 = opt->error_on_deprecated_syntax();
}

void GO_EXPORT(LanguageOptions_SetSupportedGenericEntityTypes)(void * arg0,void * arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  SET_LIST(opt->SetSupportedGenericEntityTypes, std::string, arg1);
}

void GO_EXPORT(LanguageOptions_GenericEntityTypeSupported)(void * arg0,void * arg1,char* arg2){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  *arg2 = opt->GenericEntityTypeSupported((char *)arg1);
}

void GO_EXPORT(LanguageOptions_IsReservedKeyword)(void * arg0,void * arg1,char* arg2){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  *arg2 = opt->IsReservedKeyword((char *)arg1);
}

void GO_EXPORT(LanguageOptions_EnableReservableKeyword)(void * arg0,void * arg1,int arg2,void ** arg3){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  *arg3 = (void *)(new absl::Status(opt->EnableReservableKeyword((char *)arg1, arg2)));
}

void GO_EXPORT(LanguageOptions_EnableAllReservableKeywords)(void * arg0,int arg1){
  zetasql::LanguageOptions *opt = (zetasql::LanguageOptions *)arg0;
  opt->EnableAllReservableKeywords(arg1);
}

void GO_EXPORT(AnalyzerOptions_new)(void ** arg0){
  *arg0 = (void *)(new zetasql::AnalyzerOptions());
}

void GO_EXPORT(AnalyzerOptions_language)(void * arg0,void ** arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg1 = (void *)(new zetasql::LanguageOptions(opt->language()));
}

void GO_EXPORT(AnalyzerOptions_set_language)(void * arg0,void * arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  opt->set_language(*(zetasql::LanguageOptions *)arg1);
}

void GO_EXPORT(AnalyzerOptions_AddQueryParameter)(void * arg0,void * arg1,void * arg2,void ** arg3){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg3 = (void *)(new absl::Status(opt->AddQueryParameter((char *)arg1, (const zetasql::Type *)arg2)));
}

typedef struct {
  void *name;
  void *type;
} query_param_t;

void GO_EXPORT(AnalyzerOptions_query_parameters)(void * arg0,void ** arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  auto params = opt->query_parameters();
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  void **data = (void **)malloc(sizeof(void *) * params.size());
  int idx = 0;
  for (auto it = params.begin(); it != params.end(); it++) {
    query_param_t *param = (query_param_t *)malloc(sizeof(query_param_t));
    param->name = (void *)((new std::string(it->first))->c_str());
    param->type = (void *)it->second;
    data[idx] = (void *)param;
  }
  slice->data = data;
  slice->cap = params.size();
  slice->len = params.size();
  *arg1 = (void *)slice;
}

void GO_EXPORT(AnalyzerOptions_clear_query_parameters)(void * arg0){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  opt->clear_query_parameters();
}

void GO_EXPORT(AnalyzerOptions_AddPositionalQueryParameter)(void * arg0,void * arg1,void ** arg2){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg2 = (void *)(new absl::Status(opt->AddPositionalQueryParameter((const zetasql::Type *)arg1)));
}

void GO_EXPORT(AnalyzerOptions_positional_query_parameters)(void * arg0,void ** arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  auto params = opt->positional_query_parameters();
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  void **data = (void **)malloc(sizeof(void *) * params.size());
  for (int i = 0; i < params.size(); i++) {
    data[i] = (void *)params[i];
  }
  slice->data = data;
  slice->cap = params.size();
  slice->len = params.size();
  *arg1 = (void *)slice;
}

void GO_EXPORT(AnalyzerOptions_clear_positional_query_parameters)(void * arg0){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  opt->clear_positional_query_parameters();
}

void GO_EXPORT(AnalyzerOptions_AddExpressionColumn)(void * arg0,void * arg1,void * arg2,void ** arg3){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg3 = (void *)(new absl::Status(opt->AddExpressionColumn((char *)arg1, (const zetasql::Type *)arg2)));
}

void GO_EXPORT(AnalyzerOptions_SetInScopeExpressionColumn)(void * arg0,void * arg1,void * arg2,void ** arg3){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg3 = (void *)(new absl::Status(opt->SetInScopeExpressionColumn((char *)arg1, (const zetasql::Type *)arg2)));
}

void GO_EXPORT(AnalyzerOptions_expression_columns)(void * arg0,void ** arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  auto columns = opt->expression_columns();
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  void **data = (void **)malloc(sizeof(void *) * columns.size());
  int idx = 0;
  for (auto it = columns.begin(); it != columns.end(); it++) {
    query_param_t *param = (query_param_t *)malloc(sizeof(query_param_t));
    param->name = (void *)((new std::string(it->first))->c_str());
    param->type = (void *)it->second;
    data[idx] = (void *)param;
  }
  slice->data = data;
  slice->cap = columns.size();
  slice->len = columns.size();
  *arg1 = (void *)slice;
}

void GO_EXPORT(AnalyzerOptions_has_in_scope_expression_column)(void * arg0,char* arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg1 = opt->has_in_scope_expression_column();
}

void GO_EXPORT(AnalyzerOptions_in_scope_expression_column_name)(void * arg0,void ** arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg1 = (void *)((new std::string(opt->in_scope_expression_column_name()))->c_str());
}

void GO_EXPORT(AnalyzerOptions_in_scope_expression_column_type)(void * arg0,void ** arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg1 = (void *)opt->in_scope_expression_column_type();
}

void GO_EXPORT(AnalyzerOptions_set_error_message_mode)(void * arg0,int arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  opt->set_error_message_mode((zetasql::ErrorMessageMode)arg1);
}

void GO_EXPORT(AnalyzerOptions_error_message_mode)(void * arg0,int* arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg1 = opt->error_message_mode();
}

void GO_EXPORT(AnalyzerOptions_set_statement_context)(void * arg0,int arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  opt->set_statement_context((zetasql::StatementContext)arg1);
}

void GO_EXPORT(AnalyzerOptions_statement_context)(void * arg0,int* arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg1 = opt->statement_context();
}

void GO_EXPORT(AnalyzerOptions_set_parse_location_record_type)(void * arg0,int arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  opt->set_parse_location_record_type((zetasql::ParseLocationRecordType)arg1);
}

void GO_EXPORT(AnalyzerOptions_parse_location_record_type)(void * arg0,int* arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg1 = opt->parse_location_record_type();
}

void GO_EXPORT(AnalyzerOptions_set_create_new_column_for_each_projected_output)(void * arg0,int arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  opt->set_create_new_column_for_each_projected_output(arg1);
}

void GO_EXPORT(AnalyzerOptions_create_new_column_for_each_projected_output)(void * arg0,char* arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg1 = opt->create_new_column_for_each_projected_output();
}

void GO_EXPORT(AnalyzerOptions_set_allow_undeclared_parameters)(void * arg0,int arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  opt->set_allow_undeclared_parameters(arg1);
}

void GO_EXPORT(AnalyzerOptions_allow_undeclared_parameters)(void * arg0,char* arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg1 = opt->allow_undeclared_parameters();
}

void GO_EXPORT(AnalyzerOptions_set_parameter_mode)(void * arg0,int arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  opt->set_parameter_mode((zetasql::ParameterMode)arg1);
}

void GO_EXPORT(AnalyzerOptions_parameter_mode)(void * arg0,int* arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg1 = opt->parameter_mode();
}

void GO_EXPORT(AnalyzerOptions_set_prune_unused_columns)(void * arg0,int arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  opt->set_prune_unused_columns(arg1);
}

void GO_EXPORT(AnalyzerOptions_prune_unused_columns)(void * arg0,char* arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg1 = opt->prune_unused_columns();
}

void GO_EXPORT(AnalyzerOptions_set_preserve_column_aliases)(void * arg0,int arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  opt->set_preserve_column_aliases(arg1);
}

void GO_EXPORT(AnalyzerOptions_preserve_column_aliases)(void * arg0,char* arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg1 = opt->preserve_column_aliases();
}

void GO_EXPORT(AnalyzerOptions_GetParserOptions)(void * arg0,void ** arg1)
{
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg1 = (void *)(new zetasql::ParserOptions(opt->GetParserOptions()));
}

void GO_EXPORT(ValidateAnalyzerOptions)(void * arg0,void ** arg1){
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg0;
  *arg1 = (void *)(new absl::Status(zetasql::ValidateAnalyzerOptions(*opt)));
}

void GO_EXPORT(AnalyzeStatement)(void * arg0,void * arg1,void * arg2,void ** arg3,void ** arg4){
  std::unique_ptr<const zetasql::AnalyzerOutput> out;
  auto typeFactory = new zetasql::TypeFactory(); // FIXME: typeFactory will be leaked.
  absl::Status ret = zetasql::AnalyzeStatement(
    (char *)arg0,
    *(zetasql::AnalyzerOptions *)arg1,
    (zetasql::Catalog *)arg2,
    typeFactory,
    &out
  );
  *(std::unique_ptr<const zetasql::AnalyzerOutput> *)arg3 = std::move(out);
  *arg4 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(AnalyzeNextStatement)(void * arg0,void * arg1,void * arg2,void ** arg3,char* arg4,void ** arg5)
{
  auto typeFactory = new zetasql::TypeFactory(); // FIXME: typeFactory will be leaked.
  zetasql::ParseResumeLocation *loc = (zetasql::ParseResumeLocation *)arg0;
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg1;
  zetasql::Catalog *cat = (zetasql::Catalog *)arg2;
  std::unique_ptr<const zetasql::AnalyzerOutput> out;
  bool endOfInput;
  absl::Status ret = zetasql::AnalyzeNextStatement(loc, *opt, cat, typeFactory, &out, &endOfInput);
  *(std::unique_ptr<const zetasql::AnalyzerOutput> *)arg3 = std::move(out);
  *arg4 = endOfInput;
  *arg5 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(AnalyzeExpression)(void * arg0,void * arg1,void * arg2,void ** arg3,void ** arg4)
{
  auto typeFactory = new zetasql::TypeFactory(); // FIXME: typeFactory will be leaked.
  zetasql::AnalyzerOptions *opt = (zetasql::AnalyzerOptions *)arg1;
  zetasql::Catalog *cat = (zetasql::Catalog *)arg2;
  std::unique_ptr<const zetasql::AnalyzerOutput> out;
  absl::Status ret = zetasql::AnalyzeExpression((char *)arg0, *opt, cat, typeFactory, &out);
  *(std::unique_ptr<const zetasql::AnalyzerOutput> *)arg3 = std::move(out);
  *arg4 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(AnalyzeStatementFromParserAST)(void * arg0,void * arg1,void * arg2,void * arg3,void ** arg4,void ** arg5)
{
  std::unique_ptr<const zetasql::AnalyzerOutput> out;
  auto typeFactory = new zetasql::TypeFactory(); // FIXME: typeFactory will be leaked.
  absl::Status ret = zetasql::AnalyzeStatementFromParserAST(
    *(zetasql::ASTStatement *)arg0,
    *(zetasql::AnalyzerOptions *)arg1,
    (char *)arg2,
    (zetasql::Catalog *)arg3,
    typeFactory,
    &out
  );
  *(std::unique_ptr<const zetasql::AnalyzerOutput> *)arg4 = std::move(out);
  *arg5 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(AnalyzerOutput_resolved_statement)(void * arg0,void ** arg1)
{
  zetasql::AnalyzerOutput *out = (zetasql::AnalyzerOutput *)arg0;
  *arg1 = (void *)out->resolved_statement();
}

void GO_EXPORT(ResolvedNode_node_kind)(void * arg0,int* arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  *arg1 = node->node_kind();
}

void GO_EXPORT(ResolvedNode_IsScan)(void * arg0,char* arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  *arg1 = node->IsScan();
}

void GO_EXPORT(ResolvedNode_IsExpression)(void * arg0,char* arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  *arg1 = node->IsExpression();
}

void GO_EXPORT(ResolvedNode_IsStatement)(void * arg0,char* arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  *arg1 = node->IsStatement();
}

void GO_EXPORT(ResolvedNode_DebugString)(void * arg0,void ** arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  *arg1 = (void *)((new std::string(node->DebugString()))->c_str());
}

void GO_EXPORT(ResolvedNode_GetChildNodes_num)(void * arg0,int* arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  std::vector<const zetasql::ResolvedNode *> child_nodes;
  node->GetChildNodes(&child_nodes);
  *arg1 = child_nodes.size();
}

void GO_EXPORT(ResolvedNode_GetChildNode)(void * arg0,int arg1,void ** arg2)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  std::vector<const zetasql::ResolvedNode *> child_nodes;
  node->GetChildNodes(&child_nodes);
  *arg2 = (void *)child_nodes[arg1];
}

void GO_EXPORT(ResolvedNode_GetParseLocationRangeOrNULL)(void * arg0,void ** arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  *arg1 = (void *)node->GetParseLocationRangeOrNULL();
}

void GO_EXPORT(ResolvedNode_GetTreeDepth)(void * arg0,int* arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  *arg1 = node->GetTreeDepth();
}

void GO_EXPORT(ResolvedExpr_type)(void * arg0,void ** arg1)
{
  zetasql::ResolvedExpr *expr = (zetasql::ResolvedExpr *)arg0;
  *arg1 = (void *)expr->type();
}

void GO_EXPORT(ResolvedExpr_set_type)(void * arg0,void * arg1)
{
  zetasql::ResolvedExpr *expr = (zetasql::ResolvedExpr *)arg0;
  expr->set_type((zetasql::Type *)arg1);
}

void GO_EXPORT(ResolvedExpr_type_annotation_map)(void * arg0,void ** arg1)
{
  zetasql::ResolvedExpr *expr = (zetasql::ResolvedExpr *)arg0;
  *arg1 = (void *)expr->type_annotation_map();
}

void GO_EXPORT(ResolvedExpr_set_type_annotation_map)(void * arg0,void * arg1)
{
  zetasql::ResolvedExpr *expr = (zetasql::ResolvedExpr *)arg0;
  expr->set_type_annotation_map((zetasql::AnnotationMap *)arg1);
}

void GO_EXPORT(ResolvedLiteral_value)(void * arg0,void ** arg1)
{
  zetasql::ResolvedLiteral *node = (zetasql::ResolvedLiteral *)arg0;
  *arg1 = (void *)(new zetasql::Value(node->value()));
}

void GO_EXPORT(ResolvedLiteral_set_value)(void * arg0,void * arg1)
{
  zetasql::ResolvedLiteral *node = (zetasql::ResolvedLiteral *)arg0;
  node->set_value(*(zetasql::Value *)arg1);
}

void GO_EXPORT(ResolvedLiteral_has_explicit_type)(void * arg0,char* arg1)
{
  zetasql::ResolvedLiteral *node = (zetasql::ResolvedLiteral *)arg0;
  *arg1 = node->has_explicit_type();
}

void GO_EXPORT(ResolvedLiteral_set_has_explicit_type)(void * arg0,int arg1)
{
  zetasql::ResolvedLiteral *node = (zetasql::ResolvedLiteral *)arg0;
  node->set_has_explicit_type(arg1);
}

void GO_EXPORT(ResolvedLiteral_float_literal_id)(void * arg0,int* arg1)
{
  zetasql::ResolvedLiteral *node = (zetasql::ResolvedLiteral *)arg0;
  *arg1 = node->float_literal_id();
}

void GO_EXPORT(ResolvedLiteral_set_float_literal_id)(void * arg0,int arg1)
{
  zetasql::ResolvedLiteral *node = (zetasql::ResolvedLiteral *)arg0;
  node->set_float_literal_id(arg1);
}

void GO_EXPORT(ResolvedLiteral_preserve_in_literal_remover)(void * arg0,char* arg1)
{
  zetasql::ResolvedLiteral *node = (zetasql::ResolvedLiteral *)arg0;
  *arg1 = node->preserve_in_literal_remover();
}

void GO_EXPORT(ResolvedLiteral_set_preserve_in_literal_remover)(void * arg0,int arg1)
{
  zetasql::ResolvedLiteral *node = (zetasql::ResolvedLiteral *)arg0;
  node->set_preserve_in_literal_remover(arg1);
}

void GO_EXPORT(ResolvedParameter_name)(void * arg0,void ** arg1)
{
  zetasql::ResolvedParameter *node = (zetasql::ResolvedParameter *)arg0;
  *arg1 = (void *)node->name().c_str();
}

void GO_EXPORT(ResolvedParameter_set_name)(void * arg0,void * arg1)
{
  zetasql::ResolvedParameter *node = (zetasql::ResolvedParameter *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedParameter_position)(void * arg0,int* arg1)
{
  zetasql::ResolvedParameter *node = (zetasql::ResolvedParameter *)arg0;
  *arg1 = node->position();
}

void GO_EXPORT(ResolvedParameter_set_position)(void * arg0,int arg1)
{
  zetasql::ResolvedParameter *node = (zetasql::ResolvedParameter *)arg0;
  node->set_position(arg1);
}

void GO_EXPORT(ResolvedParameter_is_untyped)(void * arg0,char* arg1)
{
  zetasql::ResolvedParameter *node = (zetasql::ResolvedParameter *)arg0;
  *arg1 = node->is_untyped();
}

void GO_EXPORT(ResolvedParameter_set_is_untyped)(void * arg0,int arg1)
{
  zetasql::ResolvedParameter *node = (zetasql::ResolvedParameter *)arg0;
  node->set_is_untyped(arg1);
}

void GO_EXPORT(ResolvedExpressionColumn_name)(void * arg0,void ** arg1)
{
  zetasql::ResolvedExpressionColumn *node = (zetasql::ResolvedExpressionColumn *)arg0;
  *arg1 = (void *)node->name().c_str();
}

void GO_EXPORT(ResolvedExpressionColumn_set_name)(void * arg0,void * arg1)
{
  zetasql::ResolvedExpressionColumn *node = (zetasql::ResolvedExpressionColumn *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedColumnRef_column)(void * arg0,void ** arg1)
{
  zetasql::ResolvedColumnRef *node = (zetasql::ResolvedColumnRef *)arg0;
  *arg1 = (void *)(new zetasql::ResolvedColumn(node->column()));
}

void GO_EXPORT(ResolvedColumnRef_set_column)(void * arg0,void * arg1)
{
  zetasql::ResolvedColumnRef *node = (zetasql::ResolvedColumnRef *)arg0;
  node->set_column(*(zetasql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedColumnRef_is_correlated)(void * arg0,char* arg1)
{
  zetasql::ResolvedColumnRef *node = (zetasql::ResolvedColumnRef *)arg0;
  *arg1 = node->is_correlated();
}

void GO_EXPORT(ResolvedColumnRef_set_is_correlated)(void * arg0,int arg1)
{
  zetasql::ResolvedColumnRef *node = (zetasql::ResolvedColumnRef *)arg0;
  node->set_is_correlated(arg1);
}

void GO_EXPORT(ResolvedConstant_constant)(void * arg0,void ** arg1)
{
  zetasql::ResolvedConstant *node = (zetasql::ResolvedConstant *)arg0;
  *arg1 = (void *)node->constant();
}

void GO_EXPORT(ResolvedConstant_set_constant)(void * arg0,void * arg1)
{
  zetasql::ResolvedConstant *node = (zetasql::ResolvedConstant *)arg0;
  node->set_constant((zetasql::Constant *)arg1);
}

void GO_EXPORT(ResolvedSystemVariable_name_path)(void * arg0,void ** arg1)
{
  zetasql::ResolvedSystemVariable *node = (zetasql::ResolvedSystemVariable *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedSystemVariable_set_name_path)(void * arg0,void * arg1)
{
  zetasql::ResolvedSystemVariable *node = (zetasql::ResolvedSystemVariable *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedSystemVariable_add_name_path)(void * arg0,void * arg1)
{
  zetasql::ResolvedSystemVariable *node = (zetasql::ResolvedSystemVariable *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedInlineLambda_argument_list)(void * arg0,void ** arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  GET_LIST(node->argument_list, arg1);
}

void GO_EXPORT(ResolvedInlineLambda_set_argument_list)(void * arg0,void * arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  SET_LIST(node->set_argument_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedInlineLambda_add_argument)(void * arg0,void * arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  node->add_argument_list(*(zetasql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedInlineLambda_parameter_list)(void * arg0,void ** arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  GET_UNIQUE_PTR_LIST(node->parameter_list, arg1);
}

void GO_EXPORT(ResolvedInlineLambda_set_parameter_list)(void * arg0,void * arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_parameter_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedInlineLambda_add_parameter)(void * arg0,void * arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_parameter_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedInlineLambda_body)(void * arg0,void ** arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  *arg1 = (void *)node->body();
}

void GO_EXPORT(ResolvedInlineLambda_set_body)(void * arg0,void * arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  node->set_body(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedFilterFieldArg_include)(void * arg0,char* arg1){
  zetasql::ResolvedFilterFieldArg *node = (zetasql::ResolvedFilterFieldArg *)arg0;
  *arg1 = node->include();
}

void GO_EXPORT(ResolvedFilterFieldArg_set_include)(void * arg0,int arg1){
  zetasql::ResolvedFilterFieldArg *node = (zetasql::ResolvedFilterFieldArg *)arg0;
  node->set_include(arg1);
}

void GO_EXPORT(ResolvedFilterField_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedFilterField *node = (zetasql::ResolvedFilterField *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedFilterField_set_expr)(void * arg0,void * arg1){
  zetasql::ResolvedFilterField *node = (zetasql::ResolvedFilterField *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedFilterField_filter_field_arg_list)(void * arg0,void ** arg1){
  zetasql::ResolvedFilterField *node = (zetasql::ResolvedFilterField *)arg0;
  GET_UNIQUE_PTR_LIST(node->filter_field_arg_list, arg1);
}

void GO_EXPORT(ResolvedFilterField_set_filter_field_arg_list)(void * arg0,void * arg1){
  zetasql::ResolvedFilterField *node = (zetasql::ResolvedFilterField *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_filter_field_arg_list, ResolvedFilterFieldArg, arg1);
}

void GO_EXPORT(ResolvedFilterField_add_filter_field_arg_list)(void * arg0,void * arg1){
  zetasql::ResolvedFilterField *node = (zetasql::ResolvedFilterField *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_filter_field_arg_list, ResolvedFilterFieldArg, arg1);
}

void GO_EXPORT(ResolvedFilterField_reset_cleared_required_fields)(void * arg0,char* arg1){
  zetasql::ResolvedFilterField *node = (zetasql::ResolvedFilterField *)arg0;
  *arg1 = node->reset_cleared_required_fields();
}

void GO_EXPORT(ResolvedFilterField_set_reset_cleared_required_fields)(void * arg0,int arg1){
  zetasql::ResolvedFilterField *node = (zetasql::ResolvedFilterField *)arg0;
  node->set_reset_cleared_required_fields(arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_function)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  *arg1 = (void *)node->function();
}

void GO_EXPORT(ResolvedFunctionCallBase_set_function)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  node->set_function((const zetasql::Function *)arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_signature)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  *arg1 = (void *)(new zetasql::FunctionSignature(node->signature()));
}

void GO_EXPORT(ResolvedFunctionCallBase_set_signature)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  node->set_signature(*(zetasql::FunctionSignature *)arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_argument_list)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->argument_list, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_set_argument_list)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_argument_list, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_add_argument_list)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_argument_list, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_generic_argument_list)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->generic_argument_list, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_set_generic_argument_list)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_generic_argument_list, ResolvedFunctionArgument, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_add_generic_argument_list)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_generic_argument_list, ResolvedFunctionArgument, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_error_mode)(void * arg0,int* arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  *arg1 = node->error_mode();
}

void GO_EXPORT(ResolvedFunctionCallBase_set_error_mode)(void * arg0,int arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  node->set_error_mode((zetasql::ResolvedFunctionCallBase::ErrorMode)arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_hint_list)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->hint_list, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_set_hint_list)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_add_hint_list)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_collation_list)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  GET_LIST(node->collation_list, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_set_collation_list)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  SET_LIST(node->set_collation_list, zetasql::ResolvedCollation, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_add_collation_list)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionCallBase *node = (zetasql::ResolvedFunctionCallBase *)arg0;
  ADD_LIST(node->add_collation_list, zetasql::ResolvedCollation, arg1);
}

void GO_EXPORT(ResolvedFunctionCall_function_call_info)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionCall *node = (zetasql::ResolvedFunctionCall *)arg0;
  *arg1 = (void *)node->function_call_info().get();
}

void GO_EXPORT(ResolvedFunctionCall_set_function_call_info)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionCall *node = (zetasql::ResolvedFunctionCall *)arg0;
  auto p = std::make_shared<zetasql::ResolvedFunctionCallInfo>();
  memcpy((void *)p.get(), arg1, sizeof(zetasql::ResolvedFunctionCallInfo));
  node->set_function_call_info(p);
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_distinct)(void * arg0,char* arg1){
  zetasql::ResolvedNonScalarFunctionCallBase *node = (zetasql::ResolvedNonScalarFunctionCallBase *)arg0;
  *arg1 = node->distinct();
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_set_distinct)(void * arg0,int arg1){
  zetasql::ResolvedNonScalarFunctionCallBase *node = (zetasql::ResolvedNonScalarFunctionCallBase *)arg0;
  node->set_distinct(arg1);
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_null_handling_modifier)(void * arg0,int* arg1){
  zetasql::ResolvedNonScalarFunctionCallBase *node = (zetasql::ResolvedNonScalarFunctionCallBase *)arg0;
  *arg1 = node->null_handling_modifier();
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_set_null_handling_modifier)(void * arg0,int arg1){
  zetasql::ResolvedNonScalarFunctionCallBase *node = (zetasql::ResolvedNonScalarFunctionCallBase *)arg0;
  node->set_null_handling_modifier((zetasql::ResolvedNonScalarFunctionCallBase::NullHandlingModifier)arg1);
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_with_group_rows_subquery)(void * arg0,void ** arg1){
  zetasql::ResolvedNonScalarFunctionCallBase *node = (zetasql::ResolvedNonScalarFunctionCallBase *)arg0;
  *arg1 = (void *)node->with_group_rows_subquery();
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_set_with_group_rows_subquery)(void * arg0,void * arg1){
  zetasql::ResolvedNonScalarFunctionCallBase *node = (zetasql::ResolvedNonScalarFunctionCallBase *)arg0;
  node->set_with_group_rows_subquery(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_with_group_rows_parameter_list)(void * arg0,void ** arg1){
  zetasql::ResolvedNonScalarFunctionCallBase *node = (zetasql::ResolvedNonScalarFunctionCallBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->with_group_rows_parameter_list, arg1);
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_set_with_group_rows_parameter_list)(void * arg0,void * arg1){
  zetasql::ResolvedNonScalarFunctionCallBase *node = (zetasql::ResolvedNonScalarFunctionCallBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_with_group_rows_parameter_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_add_with_group_rows_parameter_list)(void * arg0,void * arg1){
  zetasql::ResolvedNonScalarFunctionCallBase *node = (zetasql::ResolvedNonScalarFunctionCallBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_with_group_rows_parameter_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedAggregateFunctionCall_having_modifier)(void * arg0,void ** arg1){
  zetasql::ResolvedAggregateFunctionCall *node = (zetasql::ResolvedAggregateFunctionCall *)arg0;
  *arg1 = (void *)node->having_modifier();
}

void GO_EXPORT(ResolvedAggregateFunctionCall_set_having_modifier)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateFunctionCall *node = (zetasql::ResolvedAggregateFunctionCall *)arg0;
  SET_UNIQUE_PTR(node->set_having_modifier, ResolvedAggregateHavingModifier, arg1);
}

void GO_EXPORT(ResolvedAggregateFunctionCall_order_by_item_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAggregateFunctionCall *node = (zetasql::ResolvedAggregateFunctionCall *)arg0;
  GET_UNIQUE_PTR_LIST(node->order_by_item_list, arg1);
}

void GO_EXPORT(ResolvedAggregateFunctionCall_set_order_by_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateFunctionCall *node = (zetasql::ResolvedAggregateFunctionCall *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_order_by_item_list, ResolvedOrderByItem, arg1);
}

void GO_EXPORT(ResolvedAggregateFunctionCall_add_order_by_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateFunctionCall *node = (zetasql::ResolvedAggregateFunctionCall *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_order_by_item_list, ResolvedOrderByItem, arg1);
}

void GO_EXPORT(ResolvedAggregateFunctionCall_limit)(void * arg0,void ** arg1){
  zetasql::ResolvedAggregateFunctionCall *node = (zetasql::ResolvedAggregateFunctionCall *)arg0;
  *arg1 = (void *)node->limit();
}

void GO_EXPORT(ResolvedAggregateFunctionCall_set_limit)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateFunctionCall *node = (zetasql::ResolvedAggregateFunctionCall *)arg0;
  node->set_limit(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedAggregateFunctionCall_function_call_info)(void * arg0,void ** arg1){
  zetasql::ResolvedAggregateFunctionCall *node = (zetasql::ResolvedAggregateFunctionCall *)arg0;
  *arg1 = (void *)node->function_call_info().get();
}

void GO_EXPORT(ResolvedAggregateFunctionCall_set_function_call_info)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateFunctionCall *node = (zetasql::ResolvedAggregateFunctionCall *)arg0;
  auto p = std::make_shared<zetasql::ResolvedFunctionCallInfo>();
  memcpy((void *)p.get(), arg1, sizeof(zetasql::ResolvedFunctionCallInfo));
  node->set_function_call_info(p);
}

void GO_EXPORT(ResolvedAnalyticFunctionCall_window_frame)(void * arg0,void ** arg1){
  zetasql::ResolvedAnalyticFunctionCall *node = (zetasql::ResolvedAnalyticFunctionCall *)arg0;
  *arg1 = (void *)node->window_frame();
}

void GO_EXPORT(ResolvedAnalyticFunctionCall_set_window_frame)(void * arg0,void * arg1){
  zetasql::ResolvedAnalyticFunctionCall *node = (zetasql::ResolvedAnalyticFunctionCall *)arg0;
  SET_UNIQUE_PTR(node->set_window_frame, ResolvedWindowFrame, arg1);
}

void GO_EXPORT(ResolvedExtendedCastElement_from_type)(void * arg0,void ** arg1){
  zetasql::ResolvedExtendedCastElement *node = (zetasql::ResolvedExtendedCastElement *)arg0;
  *arg1 = (void *)node->from_type();
}

void GO_EXPORT(ResolvedExtendedCastElement_set_from_type)(void * arg0,void * arg1){
  zetasql::ResolvedExtendedCastElement *node = (zetasql::ResolvedExtendedCastElement *)arg0;
  node->set_from_type((const zetasql::Type *)arg1);
}

void GO_EXPORT(ResolvedExtendedCastElement_to_type)(void * arg0,void ** arg1){
  zetasql::ResolvedExtendedCastElement *node = (zetasql::ResolvedExtendedCastElement *)arg0;
  *arg1 = (void *)node->to_type();
}

void GO_EXPORT(ResolvedExtendedCastElement_set_to_type)(void * arg0,void * arg1){
  zetasql::ResolvedExtendedCastElement *node = (zetasql::ResolvedExtendedCastElement *)arg0;
  node->set_to_type((const zetasql::Type *)arg1);
}

void GO_EXPORT(ResolvedExtendedCastElement_function)(void * arg0,void ** arg1){
  zetasql::ResolvedExtendedCastElement *node = (zetasql::ResolvedExtendedCastElement *)arg0;
  *arg1 = (void *)node->function();
}

void GO_EXPORT(ResolvedExtendedCastElement_set_function)(void * arg0,void * arg1){
  zetasql::ResolvedExtendedCastElement *node = (zetasql::ResolvedExtendedCastElement *)arg0;
  node->set_function((const zetasql::Function *)arg1);
}

void GO_EXPORT(ResolvedExtendedCast_element_list)(void * arg0,void ** arg1){
  zetasql::ResolvedExtendedCast *node = (zetasql::ResolvedExtendedCast *)arg0;
  GET_UNIQUE_PTR_LIST(node->element_list, arg1);
}

void GO_EXPORT(ResolvedExtendedCast_set_element_list)(void * arg0,void * arg1){
  zetasql::ResolvedExtendedCast *node = (zetasql::ResolvedExtendedCast *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_element_list, ResolvedExtendedCastElement, arg1);
}

void GO_EXPORT(ResolvedExtendedCast_add_element_list)(void * arg0,void * arg1){
  zetasql::ResolvedExtendedCast *node = (zetasql::ResolvedExtendedCast *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_element_list, ResolvedExtendedCastElement, arg1);
}

void GO_EXPORT(ResolvedCast_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedCast *node = (zetasql::ResolvedCast *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedCast_set_expr)(void * arg0,void * arg1){
  zetasql::ResolvedCast *node = (zetasql::ResolvedCast *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCast_return_null_on_error)(void * arg0,char* arg1){
  zetasql::ResolvedCast *node = (zetasql::ResolvedCast *)arg0;
  *arg1 = node->return_null_on_error();
}

void GO_EXPORT(ResolvedCast_set_return_null_on_error)(void * arg0,int arg1){
  zetasql::ResolvedCast *node = (zetasql::ResolvedCast *)arg0;
  node->set_return_null_on_error(arg1);
}

void GO_EXPORT(ResolvedCast_extended_cast)(void * arg0,void ** arg1){
  zetasql::ResolvedCast *node = (zetasql::ResolvedCast *)arg0;
  *arg1 = (void *)node->extended_cast();
}

void GO_EXPORT(ResolvedCast_set_extended_cast)(void * arg0,void * arg1){
  zetasql::ResolvedCast *node = (zetasql::ResolvedCast *)arg0;
  SET_UNIQUE_PTR(node->set_extended_cast, ResolvedExtendedCast, arg1);
}

void GO_EXPORT(ResolvedCast_format)(void * arg0,void ** arg1){
  zetasql::ResolvedCast *node = (zetasql::ResolvedCast *)arg0;
  *arg1 = (void *)node->format();
}

void GO_EXPORT(ResolvedCast_set_format)(void * arg0,void * arg1){
  zetasql::ResolvedCast *node = (zetasql::ResolvedCast *)arg0;
  node->set_format(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCast_time_zone)(void * arg0,void ** arg1){
  zetasql::ResolvedCast *node = (zetasql::ResolvedCast *)arg0;
  *arg1 = (void *)node->time_zone();
}

void GO_EXPORT(ResolvedCast_set_time_zone)(void * arg0,void * arg1){
  zetasql::ResolvedCast *node = (zetasql::ResolvedCast *)arg0;
  node->set_time_zone(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCast_type_parameters)(void * arg0,void ** arg1){
  zetasql::ResolvedCast *node = (zetasql::ResolvedCast *)arg0;
  *arg1 = (void *)(new zetasql::TypeParameters(node->type_parameters()));
}

void GO_EXPORT(ResolvedCast_set_type_parameters)(void * arg0,void * arg1){
  zetasql::ResolvedCast *node = (zetasql::ResolvedCast *)arg0;
  node->set_type_parameters(*(zetasql::TypeParameters *)arg1);
}

void GO_EXPORT(ResolvedMakeStruct_field_list)(void * arg0,void ** arg1){
  zetasql::ResolvedMakeStruct *node = (zetasql::ResolvedMakeStruct *)arg0;
  GET_UNIQUE_PTR_LIST(node->field_list, arg1);
}

void GO_EXPORT(ResolvedMakeStruct_set_field_list)(void * arg0,void * arg1){
  zetasql::ResolvedMakeStruct *node = (zetasql::ResolvedMakeStruct *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_field_list, arg1);
}

void GO_EXPORT(ResolvedMakeStruct_add_field_list)(void * arg0,void * arg1){
  zetasql::ResolvedMakeStruct *node = (zetasql::ResolvedMakeStruct *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_field_list, arg1);
}

void GO_EXPORT(ResolvedMakeProto_field_list)(void * arg0,void ** arg1){
  zetasql::ResolvedMakeProto *node = (zetasql::ResolvedMakeProto *)arg0;
  GET_UNIQUE_PTR_LIST(node->field_list, arg1);
}

void GO_EXPORT(ResolvedMakeProto_set_field_list)(void * arg0,void * arg1){
  zetasql::ResolvedMakeProto *node = (zetasql::ResolvedMakeProto *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_field_list, ResolvedMakeProtoField, arg1);
}

void GO_EXPORT(ResolvedMakeProto_add_field_list)(void * arg0,void * arg1){
  zetasql::ResolvedMakeProto *node = (zetasql::ResolvedMakeProto *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_field_list, ResolvedMakeProtoField, arg1);
}

void GO_EXPORT(ResolvedMakeProtoField_format)(void * arg0,int* arg1){
  zetasql::ResolvedMakeProtoField *node = (zetasql::ResolvedMakeProtoField *)arg0;
  *arg1 = node->format();
}

void GO_EXPORT(ResolvedMakeProtoField_set_format)(void * arg0,int arg1){
  zetasql::ResolvedMakeProtoField *node = (zetasql::ResolvedMakeProtoField *)arg0;
  node->set_format((zetasql::FieldFormat::Format)arg1);
}

void GO_EXPORT(ResolvedMakeProtoField_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedMakeProtoField *node = (zetasql::ResolvedMakeProtoField *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedMakeProtoField_set_expr)(void * arg0,void * arg1){
  zetasql::ResolvedMakeProtoField *node = (zetasql::ResolvedMakeProtoField *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedGetStructField_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedGetStructField *node = (zetasql::ResolvedGetStructField *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedGetStructField_set_expr)(void * arg0,void * arg1){
  zetasql::ResolvedGetStructField *node = (zetasql::ResolvedGetStructField *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedGetStructField_field_idx)(void * arg0,int* arg1){
  zetasql::ResolvedGetStructField *node = (zetasql::ResolvedGetStructField *)arg0;
  *arg1 = node->field_idx();
}

void GO_EXPORT(ResolvedGetStructField_set_field_idx)(void * arg0,int arg1){
  zetasql::ResolvedGetStructField *node = (zetasql::ResolvedGetStructField *)arg0;
  node->set_field_idx(arg1);
}

void GO_EXPORT(ResolvedGetProtoField_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedGetProtoField *node = (zetasql::ResolvedGetProtoField *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedGetProtoField_set_expr)(void * arg0,void * arg1){
  zetasql::ResolvedGetProtoField *node = (zetasql::ResolvedGetProtoField *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedGetProtoField_default_value)(void * arg0,void ** arg1){
  zetasql::ResolvedGetProtoField *node = (zetasql::ResolvedGetProtoField *)arg0;
  *arg1 = (void *)(new zetasql::Value(node->default_value()));
}

void GO_EXPORT(ResolvedGetProtoField_set_default_value)(void * arg0,void * arg1){
  zetasql::ResolvedGetProtoField *node = (zetasql::ResolvedGetProtoField *)arg0;
  node->set_default_value(*(zetasql::Value *)arg1);
}

void GO_EXPORT(ResolvedGetProtoField_get_has_bit)(void * arg0,char* arg1){
  zetasql::ResolvedGetProtoField *node = (zetasql::ResolvedGetProtoField *)arg0;
  *arg1 = node->get_has_bit();
}

void GO_EXPORT(ResolvedGetProtoField_set_get_has_bit)(void * arg0,int arg1){
  zetasql::ResolvedGetProtoField *node = (zetasql::ResolvedGetProtoField *)arg0;
  node->set_get_has_bit(arg1);
}

void GO_EXPORT(ResolvedGetProtoField_format)(void * arg0,int* arg1){
  zetasql::ResolvedGetProtoField *node = (zetasql::ResolvedGetProtoField *)arg0;
  *arg1 = node->format();
}

void GO_EXPORT(ResolvedGetProtoField_set_format)(void * arg0,int arg1){
  zetasql::ResolvedGetProtoField *node = (zetasql::ResolvedGetProtoField *)arg0;
  node->set_format((zetasql::FieldFormat::Format)arg1);
}

void GO_EXPORT(ResolvedGetProtoField_return_default_value_when_unset)(void * arg0,char* arg1){
  zetasql::ResolvedGetProtoField *node = (zetasql::ResolvedGetProtoField *)arg0;
  *arg1 = node->return_default_value_when_unset();
}

void GO_EXPORT(ResolvedGetProtoField_set_return_default_value_when_unset)(void * arg0,int arg1){
  zetasql::ResolvedGetProtoField *node = (zetasql::ResolvedGetProtoField *)arg0;
  node->set_return_default_value_when_unset(arg1);
}

void GO_EXPORT(ResolvedGetJsonField_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedGetJsonField *node = (zetasql::ResolvedGetJsonField *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedGetJsonField_set_expr)(void * arg0,void * arg1){
  zetasql::ResolvedGetJsonField *node = (zetasql::ResolvedGetJsonField *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedGetJsonField_field_name)(void * arg0,void ** arg1){
  zetasql::ResolvedGetJsonField *node = (zetasql::ResolvedGetJsonField *)arg0;
  *arg1 = (void *)((new std::string(node->field_name()))->c_str());
}

void GO_EXPORT(ResolvedGetJsonField_set_field_name)(void * arg0,void * arg1){
  zetasql::ResolvedGetJsonField *node = (zetasql::ResolvedGetJsonField *)arg0;
  node->set_field_name((char *)arg1);
}

void GO_EXPORT(ResolvedFlatten_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedFlatten *node = (zetasql::ResolvedFlatten *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedFlatten_set_expr)(void * arg0,void * arg1){
  zetasql::ResolvedFlatten *node = (zetasql::ResolvedFlatten *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedFlatten_get_field_list)(void * arg0,void ** arg1){
  zetasql::ResolvedFlatten *node = (zetasql::ResolvedFlatten *)arg0;
  GET_UNIQUE_PTR_LIST(node->get_field_list, arg1);
}

void GO_EXPORT(ResolvedFlatten_set_get_field_list)(void * arg0,void * arg1){
  zetasql::ResolvedFlatten *node = (zetasql::ResolvedFlatten *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_get_field_list, arg1);
}

void GO_EXPORT(ResolvedFlatten_add_get_field_list)(void * arg0,void * arg1){
  zetasql::ResolvedFlatten *node = (zetasql::ResolvedFlatten *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_get_field_list, arg1);
}

void GO_EXPORT(ResolvedReplaceFieldItem_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedReplaceFieldItem *node = (zetasql::ResolvedReplaceFieldItem *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedReplaceFieldItem_set_expr)(void * arg0,void * arg1){
  zetasql::ResolvedReplaceFieldItem *node = (zetasql::ResolvedReplaceFieldItem *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedReplaceFieldItem_struct_index_path)(void * arg0,void ** arg1){
  zetasql::ResolvedReplaceFieldItem *node = (zetasql::ResolvedReplaceFieldItem *)arg0;
  GET_INTS(node->struct_index_path, arg1);
}

void GO_EXPORT(ResolvedReplaceFieldItem_set_struct_index_path)(void * arg0,void * arg1){
  zetasql::ResolvedReplaceFieldItem *node = (zetasql::ResolvedReplaceFieldItem *)arg0;
  SET_INTS(node->set_struct_index_path, arg1);
}

void GO_EXPORT(ResolvedReplaceFieldItem_add_struct_index_path)(void * arg0,int arg1){
  zetasql::ResolvedReplaceFieldItem *node = (zetasql::ResolvedReplaceFieldItem *)arg0;
  node->add_struct_index_path(arg1);
}

void GO_EXPORT(ResolvedReplaceField_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedReplaceField *node = (zetasql::ResolvedReplaceField *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedReplaceField_set_expr)(void * arg0,void * arg1){
  zetasql::ResolvedReplaceField *node = (zetasql::ResolvedReplaceField *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedReplaceField_replace_field_item_list)(void * arg0,void ** arg1){
  zetasql::ResolvedReplaceField *node = (zetasql::ResolvedReplaceField *)arg0;
  GET_UNIQUE_PTR_LIST(node->replace_field_item_list, arg1);
}

void GO_EXPORT(ResolvedReplaceField_set_replace_field_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedReplaceField *node = (zetasql::ResolvedReplaceField *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_replace_field_item_list, ResolvedReplaceFieldItem, arg1);
}

void GO_EXPORT(ResolvedReplaceField_add_replace_field_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedReplaceField *node = (zetasql::ResolvedReplaceField *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_replace_field_item_list, ResolvedReplaceFieldItem, arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_subquery_type)(void * arg0,int* arg1){
  zetasql::ResolvedSubqueryExpr *node = (zetasql::ResolvedSubqueryExpr *)arg0;
  *arg1 = node->subquery_type();
}

void GO_EXPORT(ResolvedSubqueryExpr_set_subquery_type)(void * arg0,int arg1){
  zetasql::ResolvedSubqueryExpr *node = (zetasql::ResolvedSubqueryExpr *)arg0;
  node->set_subquery_type((zetasql::ResolvedSubqueryExpr::SubqueryType)arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_parameter_list)(void * arg0,void ** arg1){
  zetasql::ResolvedSubqueryExpr *node = (zetasql::ResolvedSubqueryExpr *)arg0;
  GET_UNIQUE_PTR_LIST(node->parameter_list, arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_set_parameter_list)(void * arg0,void * arg1){
  zetasql::ResolvedSubqueryExpr *node = (zetasql::ResolvedSubqueryExpr *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_parameter_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_add_parameter_list)(void * arg0,void * arg1){
  zetasql::ResolvedSubqueryExpr *node = (zetasql::ResolvedSubqueryExpr *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_parameter_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_in_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedSubqueryExpr *node = (zetasql::ResolvedSubqueryExpr *)arg0;
  *arg1 = (void *)node->in_expr();
}

void GO_EXPORT(ResolvedSubqueryExpr_set_in_expr)(void * arg0,void * arg1){
  zetasql::ResolvedSubqueryExpr *node = (zetasql::ResolvedSubqueryExpr *)arg0;
  node->set_in_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedSubqueryExpr_in_collation)(void * arg0,void ** arg1){
  zetasql::ResolvedSubqueryExpr *node = (zetasql::ResolvedSubqueryExpr *)arg0;
  *arg1 = (void *)(new zetasql::ResolvedCollation(node->in_collation()));
}

void GO_EXPORT(ResolvedSubqueryExpr_set_in_collation)(void * arg0,void * arg1){
  zetasql::ResolvedSubqueryExpr *node = (zetasql::ResolvedSubqueryExpr *)arg0;
  node->set_in_collation(*(zetasql::ResolvedCollation *)arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_subquery)(void * arg0,void ** arg1){
  zetasql::ResolvedSubqueryExpr *node = (zetasql::ResolvedSubqueryExpr *)arg0;
  *arg1 = (void *)node->subquery();
}

void GO_EXPORT(ResolvedSubqueryExpr_set_subquery)(void * arg0,void * arg1){
  zetasql::ResolvedSubqueryExpr *node = (zetasql::ResolvedSubqueryExpr *)arg0;
  node->set_subquery(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedSubqueryExpr_hint_list)(void * arg0,void ** arg1){
  zetasql::ResolvedSubqueryExpr *node = (zetasql::ResolvedSubqueryExpr *)arg0;
  GET_UNIQUE_PTR_LIST(node->hint_list, arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_set_hint_list)(void * arg0,void * arg1){
  zetasql::ResolvedSubqueryExpr *node = (zetasql::ResolvedSubqueryExpr *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_add_hint_list)(void * arg0,void * arg1){
  zetasql::ResolvedSubqueryExpr *node = (zetasql::ResolvedSubqueryExpr *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedLetExpr_assignment_list)(void * arg0,void ** arg1){
  zetasql::ResolvedLetExpr *node = (zetasql::ResolvedLetExpr *)arg0;
  GET_UNIQUE_PTR_LIST(node->assignment_list, arg1);
}

void GO_EXPORT(ResolvedLetExpr_set_assignment_list)(void * arg0,void * arg1){
  zetasql::ResolvedLetExpr *node = (zetasql::ResolvedLetExpr *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_assignment_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedLetExpr_add_assignment_list)(void * arg0,void * arg1){
  zetasql::ResolvedLetExpr *node = (zetasql::ResolvedLetExpr *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_assignment_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedLetExpr_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedLetExpr *node = (zetasql::ResolvedLetExpr *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedLetExpr_set_expr)(void * arg0,void * arg1){
  zetasql::ResolvedLetExpr *node = (zetasql::ResolvedLetExpr *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedScan_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedScan *node = (zetasql::ResolvedScan *)arg0;
  GET_LIST(node->column_list, arg1);
}

void GO_EXPORT(ResolvedScan_set_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedScan *node = (zetasql::ResolvedScan *)arg0;
  SET_LIST(node->set_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedScan_add_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedScan *node = (zetasql::ResolvedScan *)arg0;
  ADD_LIST(node->add_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedScan_hint_list)(void * arg0,void ** arg1){
  zetasql::ResolvedScan *node = (zetasql::ResolvedScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->hint_list, arg1);
}

void GO_EXPORT(ResolvedScan_set_hint_list)(void * arg0,void * arg1){
  zetasql::ResolvedScan *node = (zetasql::ResolvedScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedScan_add_hint_list)(void * arg0,void * arg1){
  zetasql::ResolvedScan *node = (zetasql::ResolvedScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedScan_is_ordered)(void * arg0,char* arg1){
  zetasql::ResolvedScan *node = (zetasql::ResolvedScan *)arg0;
  *arg1 = node->is_ordered();
}

void GO_EXPORT(ResolvedScan_set_is_ordered)(void * arg0,int arg1){
  zetasql::ResolvedScan *node = (zetasql::ResolvedScan *)arg0;
  node->set_is_ordered(arg1);
}

void GO_EXPORT(ResolvedModel_model)(void * arg0,void ** arg1){
  zetasql::ResolvedModel *node = (zetasql::ResolvedModel *)arg0;
  *arg1 = (void *)node->model();
}

void GO_EXPORT(ResolvedModel_set_model)(void * arg0,void * arg1){
  zetasql::ResolvedModel *node = (zetasql::ResolvedModel *)arg0;
  node->set_model((const zetasql::Model *)arg1);
}

void GO_EXPORT(ResolvedConnection_connection)(void * arg0,void ** arg1){
  zetasql::ResolvedConnection *node = (zetasql::ResolvedConnection *)arg0;
  *arg1 = (void *)node->connection();
}

void GO_EXPORT(ResolvedConnection_set_connection)(void * arg0,void * arg1){
  zetasql::ResolvedConnection *node = (zetasql::ResolvedConnection *)arg0;
  node->set_connection((const zetasql::Connection *)arg1);
}

void GO_EXPORT(ResolvedDescriptor_descriptor_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedDescriptor *node = (zetasql::ResolvedDescriptor *)arg0;
  GET_LIST(node->descriptor_column_list, arg1);
}

void GO_EXPORT(ResolvedDescriptor_set_descriptor_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedDescriptor *node = (zetasql::ResolvedDescriptor *)arg0;
  SET_LIST(node->set_descriptor_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedDescriptor_add_descriptor_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedDescriptor *node = (zetasql::ResolvedDescriptor *)arg0;
  ADD_LIST(node->add_descriptor_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedDescriptor_descriptor_column_name_list)(void * arg0,void ** arg1){
  zetasql::ResolvedDescriptor *node = (zetasql::ResolvedDescriptor *)arg0;
  GET_STRS(node->descriptor_column_name_list, arg1);
}

void GO_EXPORT(ResolvedDescriptor_set_descriptor_column_name_list)(void * arg0,void * arg1){
  zetasql::ResolvedDescriptor *node = (zetasql::ResolvedDescriptor *)arg0;
  SET_LIST(node->set_descriptor_column_name_list, std::string, arg1);
}

void GO_EXPORT(ResolvedDescriptor_add_descriptor_column_name_list)(void * arg0,void * arg1){
  zetasql::ResolvedDescriptor *node = (zetasql::ResolvedDescriptor *)arg0;
  node->add_descriptor_column_name_list((char *)arg1);
}

void GO_EXPORT(ResolvedTableScan_table)(void * arg0,void ** arg1){
  zetasql::ResolvedTableScan *node = (zetasql::ResolvedTableScan *)arg0;
  *arg1 = (void *)node->table();
}

void GO_EXPORT(ResolvedTableScan_set_table)(void * arg0,void * arg1){
  zetasql::ResolvedTableScan *node = (zetasql::ResolvedTableScan *)arg0;
  node->set_table((const zetasql::Table *)arg1);
}

void GO_EXPORT(ResolvedTableScan_for_system_time_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedTableScan *node = (zetasql::ResolvedTableScan *)arg0;
  *arg1 = (void *)node->for_system_time_expr();
}

void GO_EXPORT(ResolvedTableScan_set_for_system_time_expr)(void * arg0,void * arg1){
  zetasql::ResolvedTableScan *node = (zetasql::ResolvedTableScan *)arg0;
  node->set_for_system_time_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedTableScan_column_index_list)(void * arg0,void ** arg1){
  zetasql::ResolvedTableScan *node = (zetasql::ResolvedTableScan *)arg0;
  GET_INTS(node->column_index_list, arg1);
}

void GO_EXPORT(ResolvedTableScan_set_column_index_list)(void * arg0,void * arg1){
  zetasql::ResolvedTableScan *node = (zetasql::ResolvedTableScan *)arg0;
  SET_INTS(node->set_column_index_list, arg1);
}

void GO_EXPORT(ResolvedTableScan_add_column_index_list)(void * arg0,int arg1){
  zetasql::ResolvedTableScan *node = (zetasql::ResolvedTableScan *)arg0;
  node->add_column_index_list(arg1);
}

void GO_EXPORT(ResolvedTableScan_alias)(void * arg0,void ** arg1){
  zetasql::ResolvedTableScan *node = (zetasql::ResolvedTableScan *)arg0;
  *arg1 = (void *)((new std::string(node->alias()))->c_str());
}

void GO_EXPORT(ResolvedTableScan_set_alias)(void * arg0,void * arg1){
  zetasql::ResolvedTableScan *node = (zetasql::ResolvedTableScan *)arg0;
  node->set_alias((char *)arg1);
}

void GO_EXPORT(ResolvedJoinScan_join_type)(void * arg0,int* arg1){
  zetasql::ResolvedJoinScan *node = (zetasql::ResolvedJoinScan *)arg0;
  *arg1 = node->join_type();
}

void GO_EXPORT(ResolvedJoinScan_set_join_type)(void * arg0,int arg1){
  zetasql::ResolvedJoinScan *node = (zetasql::ResolvedJoinScan *)arg0;
  node->set_join_type((zetasql::ResolvedJoinScan::JoinType)arg1);
}

void GO_EXPORT(ResolvedJoinScan_left_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedJoinScan *node = (zetasql::ResolvedJoinScan *)arg0;
  *arg1 = (void *)node->left_scan();
}

void GO_EXPORT(ResolvedJoinScan_set_left_scan)(void * arg0,void * arg1){
  zetasql::ResolvedJoinScan *node = (zetasql::ResolvedJoinScan *)arg0;
  node->set_left_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedJoinScan_right_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedJoinScan *node = (zetasql::ResolvedJoinScan *)arg0;
  *arg1 = (void *)node->right_scan();
}

void GO_EXPORT(ResolvedJoinScan_set_right_scan)(void * arg0,void * arg1){
  zetasql::ResolvedJoinScan *node = (zetasql::ResolvedJoinScan *)arg0;
  node->set_right_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedJoinScan_join_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedJoinScan *node = (zetasql::ResolvedJoinScan *)arg0;
  *arg1 = (void *)node->join_expr();
}

void GO_EXPORT(ResolvedJoinScan_set_join_expr)(void * arg0,void * arg1){
  zetasql::ResolvedJoinScan *node = (zetasql::ResolvedJoinScan *)arg0;
  node->set_join_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedArrayScan_input_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedArrayScan *node = (zetasql::ResolvedArrayScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedArrayScan_set_input_scan)(void * arg0,void * arg1){
  zetasql::ResolvedArrayScan *node = (zetasql::ResolvedArrayScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedArrayScan_array_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedArrayScan *node = (zetasql::ResolvedArrayScan *)arg0;
  *arg1 = (void *)node->array_expr();
}

void GO_EXPORT(ResolvedArrayScan_set_array_expr)(void * arg0,void * arg1){
  zetasql::ResolvedArrayScan *node = (zetasql::ResolvedArrayScan *)arg0;
  node->set_array_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedArrayScan_element_column)(void * arg0,void ** arg1){
  zetasql::ResolvedArrayScan *node = (zetasql::ResolvedArrayScan *)arg0;
  *arg1 = (void *)(new zetasql::ResolvedColumn(node->element_column()));
}

void GO_EXPORT(ResolvedArrayScan_set_element_column)(void * arg0,void * arg1){
  zetasql::ResolvedArrayScan *node = (zetasql::ResolvedArrayScan *)arg0;
  node->set_element_column(*(zetasql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedArrayScan_array_offset_column)(void * arg0,void ** arg1){
  zetasql::ResolvedArrayScan *node = (zetasql::ResolvedArrayScan *)arg0;
  *arg1 = (void *)node->array_offset_column();
}

void GO_EXPORT(ResolvedArrayScan_set_array_offset_column)(void * arg0,void * arg1){
  zetasql::ResolvedArrayScan *node = (zetasql::ResolvedArrayScan *)arg0;
  SET_UNIQUE_PTR(node->set_array_offset_column, ResolvedColumnHolder, arg1);
}

void GO_EXPORT(ResolvedArrayScan_join_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedArrayScan *node = (zetasql::ResolvedArrayScan *)arg0;
  *arg1 = (void *)node->join_expr();
}

void GO_EXPORT(ResolvedArrayScan_set_join_expr)(void * arg0,void * arg1){
  zetasql::ResolvedArrayScan *node = (zetasql::ResolvedArrayScan *)arg0;
  node->set_join_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedArrayScan_is_outer)(void * arg0,char* arg1){
  zetasql::ResolvedArrayScan *node = (zetasql::ResolvedArrayScan *)arg0;
  *arg1 = node->is_outer();
}

void GO_EXPORT(ResolvedArrayScan_set_is_outer)(void * arg0,int arg1){
  zetasql::ResolvedArrayScan *node = (zetasql::ResolvedArrayScan *)arg0;
  node->set_is_outer(arg1);
}

void GO_EXPORT(ResolvedColumnHolder_column)(void * arg0,void ** arg1){
  zetasql::ResolvedColumnHolder *node = (zetasql::ResolvedColumnHolder *)arg0;
  *arg1 = (void *)(new zetasql::ResolvedColumn(node->column()));
}

void GO_EXPORT(ResolvedColumnHolder_set_column)(void * arg0,void * arg1){
  zetasql::ResolvedColumnHolder *node = (zetasql::ResolvedColumnHolder *)arg0;
  node->set_column(*(zetasql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedFilterScan_input_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedFilterScan *node = (zetasql::ResolvedFilterScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedFilterScan_set_input_scan)(void * arg0,void * arg1){
  zetasql::ResolvedFilterScan *node = (zetasql::ResolvedFilterScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedFilterScan_filter_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedFilterScan *node = (zetasql::ResolvedFilterScan *)arg0;
  *arg1 = (void *)node->filter_expr();
}

void GO_EXPORT(ResolvedFilterScan_set_filter_expr)(void * arg0,void * arg1){
  zetasql::ResolvedFilterScan *node = (zetasql::ResolvedFilterScan *)arg0;
  node->set_filter_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedGroupingSet_group_by_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedGroupingSet *node = (zetasql::ResolvedGroupingSet *)arg0;
  GET_UNIQUE_PTR_LIST(node->group_by_column_list, arg1);
}

void GO_EXPORT(ResolvedGroupingSet_set_group_by_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedGroupingSet *node = (zetasql::ResolvedGroupingSet *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_group_by_column_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedGroupingSet_add_group_by_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedGroupingSet *node = (zetasql::ResolvedGroupingSet *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_group_by_column_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_input_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedAggregateScanBase *node = (zetasql::ResolvedAggregateScanBase *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedAggregateScanBase_set_input_scan)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateScanBase *node = (zetasql::ResolvedAggregateScanBase *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedAggregateScanBase_group_by_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAggregateScanBase *node = (zetasql::ResolvedAggregateScanBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->group_by_list, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_set_group_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateScanBase *node = (zetasql::ResolvedAggregateScanBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_group_by_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_add_group_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateScanBase *node = (zetasql::ResolvedAggregateScanBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_group_by_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_collation_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAggregateScanBase *node = (zetasql::ResolvedAggregateScanBase *)arg0;
  GET_LIST(node->collation_list, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_set_collation_list)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateScanBase *node = (zetasql::ResolvedAggregateScanBase *)arg0;
  SET_LIST(node->set_collation_list, zetasql::ResolvedCollation, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_add_collation_list)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateScanBase *node = (zetasql::ResolvedAggregateScanBase *)arg0;
  ADD_LIST(node->add_collation_list, zetasql::ResolvedCollation, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_aggregate_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAggregateScanBase *node = (zetasql::ResolvedAggregateScanBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->aggregate_list, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_set_aggregate_list)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateScanBase *node = (zetasql::ResolvedAggregateScanBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_aggregate_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_add_aggregate_list)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateScanBase *node = (zetasql::ResolvedAggregateScanBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_aggregate_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedAggregateScan_grouping_set_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAggregateScan *node = (zetasql::ResolvedAggregateScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->grouping_set_list, arg1);
}

void GO_EXPORT(ResolvedAggregateScan_set_grouping_set_list)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateScan *node = (zetasql::ResolvedAggregateScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_grouping_set_list, ResolvedGroupingSet, arg1);
}

void GO_EXPORT(ResolvedAggregateScan_add_grouping_set_list)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateScan *node = (zetasql::ResolvedAggregateScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_grouping_set_list, ResolvedGroupingSet, arg1);
}

void GO_EXPORT(ResolvedAggregateScan_rollup_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAggregateScan *node = (zetasql::ResolvedAggregateScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->rollup_column_list, arg1);
}

void GO_EXPORT(ResolvedAggregateScan_set_rollup_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateScan *node = (zetasql::ResolvedAggregateScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_rollup_column_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedAggregateScan_add_rollup_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateScan *node = (zetasql::ResolvedAggregateScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_rollup_column_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedAnonymizedAggregateScan_k_threshold_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedAnonymizedAggregateScan *node = (zetasql::ResolvedAnonymizedAggregateScan *)arg0;
  *arg1 = (void *)node->k_threshold_expr();
}

void GO_EXPORT(ResolvedAnonymizedAggregateScan_set_k_threshold_expr)(void * arg0,void * arg1){
  zetasql::ResolvedAnonymizedAggregateScan *node = (zetasql::ResolvedAnonymizedAggregateScan *)arg0;
  SET_UNIQUE_PTR(node->set_k_threshold_expr, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedAnonymizedAggregateScan_anonymization_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAnonymizedAggregateScan *node = (zetasql::ResolvedAnonymizedAggregateScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->anonymization_option_list, arg1);
}

void GO_EXPORT(ResolvedAnonymizedAggregateScan_set_anonymization_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedAnonymizedAggregateScan *node = (zetasql::ResolvedAnonymizedAggregateScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_anonymization_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAnonymizedAggregateScan_add_anonymization_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedAnonymizedAggregateScan *node = (zetasql::ResolvedAnonymizedAggregateScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_anonymization_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedSetOperationItem_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedSetOperationItem *node = (zetasql::ResolvedSetOperationItem *)arg0;
  *arg1 = (void *)node->scan();
}

void GO_EXPORT(ResolvedSetOperationItem_set_scan)(void * arg0,void * arg1){
  zetasql::ResolvedSetOperationItem *node = (zetasql::ResolvedSetOperationItem *)arg0;
  node->set_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedSetOperationItem_output_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedSetOperationItem *node = (zetasql::ResolvedSetOperationItem *)arg0;
  GET_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedSetOperationItem_set_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedSetOperationItem *node = (zetasql::ResolvedSetOperationItem *)arg0;
  SET_LIST(node->set_output_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedSetOperationItem_add_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedSetOperationItem *node = (zetasql::ResolvedSetOperationItem *)arg0;
  ADD_LIST(node->add_output_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedSetOperationScan_op_type)(void * arg0,int* arg1){
  zetasql::ResolvedSetOperationScan *node = (zetasql::ResolvedSetOperationScan *)arg0;
  *arg1 = node->op_type();
}

void GO_EXPORT(ResolvedSetOperationScan_set_op_type)(void * arg0,int arg1){
  zetasql::ResolvedSetOperationScan *node = (zetasql::ResolvedSetOperationScan *)arg0;
  node->set_op_type((zetasql::ResolvedSetOperationScan::SetOperationType)arg1);
}

void GO_EXPORT(ResolvedSetOperationScan_input_item_list)(void * arg0,void ** arg1){
  zetasql::ResolvedSetOperationScan *node = (zetasql::ResolvedSetOperationScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->input_item_list, arg1);
}

void GO_EXPORT(ResolvedSetOperationScan_set_input_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedSetOperationScan *node = (zetasql::ResolvedSetOperationScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_input_item_list, ResolvedSetOperationItem, arg1);
}

void GO_EXPORT(ResolvedSetOperationScan_add_input_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedSetOperationScan *node = (zetasql::ResolvedSetOperationScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_input_item_list, ResolvedSetOperationItem, arg1);
}

void GO_EXPORT(ResolvedOrderByScan_input_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedOrderByScan *node = (zetasql::ResolvedOrderByScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedOrderByScan_set_input_scan)(void * arg0,void * arg1){
  zetasql::ResolvedOrderByScan *node = (zetasql::ResolvedOrderByScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedOrderByScan_order_by_item_list)(void * arg0,void ** arg1){
  zetasql::ResolvedOrderByScan *node = (zetasql::ResolvedOrderByScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->order_by_item_list, arg1);
}

void GO_EXPORT(ResolvedOrderByScan_set_order_by_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedOrderByScan *node = (zetasql::ResolvedOrderByScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_order_by_item_list, ResolvedOrderByItem, arg1);
}

void GO_EXPORT(ResolvedOrderByScan_add_order_by_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedOrderByScan *node = (zetasql::ResolvedOrderByScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_order_by_item_list, ResolvedOrderByItem, arg1);
}

void GO_EXPORT(ResolvedLimitOffsetScan_input_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedLimitOffsetScan *node = (zetasql::ResolvedLimitOffsetScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedLimitOffsetScan_set_input_scan)(void * arg0,void * arg1){
  zetasql::ResolvedLimitOffsetScan *node = (zetasql::ResolvedLimitOffsetScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedLimitOffsetScan_limit)(void * arg0,void ** arg1){
  zetasql::ResolvedLimitOffsetScan *node = (zetasql::ResolvedLimitOffsetScan *)arg0;
  *arg1 = (void *)node->limit();
}

void GO_EXPORT(ResolvedLimitOffsetScan_set_limit)(void * arg0,void * arg1){
  zetasql::ResolvedLimitOffsetScan *node = (zetasql::ResolvedLimitOffsetScan *)arg0;
  node->set_limit(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedLimitOffsetScan_offset)(void * arg0,void ** arg1){
  zetasql::ResolvedLimitOffsetScan *node = (zetasql::ResolvedLimitOffsetScan *)arg0;
  *arg1 = (void *)node->offset();
}

void GO_EXPORT(ResolvedLimitOffsetScan_set_offset)(void * arg0,void * arg1){
  zetasql::ResolvedLimitOffsetScan *node = (zetasql::ResolvedLimitOffsetScan *)arg0;
  node->set_offset(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedWithRefScan_with_query_name)(void * arg0,void ** arg1){
  zetasql::ResolvedWithRefScan *node = (zetasql::ResolvedWithRefScan *)arg0;
  *arg1 = (void *)((new std::string(node->with_query_name()))->c_str());
}

void GO_EXPORT(ResolvedWithRefScan_set_with_query_name)(void * arg0,void * arg1){
  zetasql::ResolvedWithRefScan *node = (zetasql::ResolvedWithRefScan *)arg0;
  node->set_with_query_name((char *)arg1);
}

void GO_EXPORT(ResolvedAnalyticScan_input_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedAnalyticScan *node = (zetasql::ResolvedAnalyticScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedAnalyticScan_set_input_scan)(void * arg0,void * arg1){
  zetasql::ResolvedAnalyticScan *node = (zetasql::ResolvedAnalyticScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedAnalyticScan_function_group_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAnalyticScan *node = (zetasql::ResolvedAnalyticScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->function_group_list, arg1);
}

void GO_EXPORT(ResolvedAnalyticScan_set_function_group_list)(void * arg0,void * arg1){
  zetasql::ResolvedAnalyticScan *node = (zetasql::ResolvedAnalyticScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_function_group_list, ResolvedAnalyticFunctionGroup, arg1);
}

void GO_EXPORT(ResolvedAnalyticScan_add_function_group_list)(void * arg0,void * arg1){
  zetasql::ResolvedAnalyticScan *node = (zetasql::ResolvedAnalyticScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_function_group_list, ResolvedAnalyticFunctionGroup, arg1);
}

void GO_EXPORT(ResolvedSampleScan_input_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedSampleScan *node = (zetasql::ResolvedSampleScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedSampleScan_set_input_scan)(void * arg0,void * arg1){
  zetasql::ResolvedSampleScan *node = (zetasql::ResolvedSampleScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedSampleScan_method)(void * arg0,void ** arg1){
  zetasql::ResolvedSampleScan *node = (zetasql::ResolvedSampleScan *)arg0;
  *arg1 = (void *)((new std::string(node->method()))->c_str());
}

void GO_EXPORT(ResolvedSampleScan_set_method)(void * arg0,void * arg1){
  zetasql::ResolvedSampleScan *node = (zetasql::ResolvedSampleScan *)arg0;
  node->set_method((char *)arg1);
}

void GO_EXPORT(ResolvedSampleScan_size)(void * arg0,void ** arg1){
  zetasql::ResolvedSampleScan *node = (zetasql::ResolvedSampleScan *)arg0;
  *arg1 = (void *)node->size();
}

void GO_EXPORT(ResolvedSampleScan_set_size)(void * arg0,void * arg1){
  zetasql::ResolvedSampleScan *node = (zetasql::ResolvedSampleScan *)arg0;
  node->set_size(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedSampleScan_unit)(void * arg0,int* arg1){
  zetasql::ResolvedSampleScan *node = (zetasql::ResolvedSampleScan *)arg0;
  *arg1 = node->unit();
}

void GO_EXPORT(ResolvedSampleScan_set_unit)(void * arg0,int arg1){
  zetasql::ResolvedSampleScan *node = (zetasql::ResolvedSampleScan *)arg0;
  node->set_unit((zetasql::ResolvedSampleScan::SampleUnit)arg1);
}

void GO_EXPORT(ResolvedSampleScan_repeatable_argument)(void * arg0,void ** arg1){
  zetasql::ResolvedSampleScan *node = (zetasql::ResolvedSampleScan *)arg0;
  *arg1 = (void *)node->repeatable_argument();
}

void GO_EXPORT(ResolvedSampleScan_set_repeatable_argument)(void * arg0,void * arg1){
  zetasql::ResolvedSampleScan *node = (zetasql::ResolvedSampleScan *)arg0;
  node->set_repeatable_argument(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedSampleScan_weight_column)(void * arg0,void ** arg1){
  zetasql::ResolvedSampleScan *node = (zetasql::ResolvedSampleScan *)arg0;
  *arg1 = (void *)node->weight_column();
}

void GO_EXPORT(ResolvedSampleScan_set_weight_column)(void * arg0,void * arg1){
  zetasql::ResolvedSampleScan *node = (zetasql::ResolvedSampleScan *)arg0;
  SET_UNIQUE_PTR(node->set_weight_column, ResolvedColumnHolder, arg1);
}

void GO_EXPORT(ResolvedSampleScan_partition_by_list)(void * arg0,void ** arg1){
  zetasql::ResolvedSampleScan *node = (zetasql::ResolvedSampleScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->partition_by_list, arg1);
}

void GO_EXPORT(ResolvedSampleScan_set_partition_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedSampleScan *node = (zetasql::ResolvedSampleScan *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedSampleScan_add_partition_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedSampleScan *node = (zetasql::ResolvedSampleScan *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedComputedColumn_column)(void * arg0,void ** arg1){
  zetasql::ResolvedComputedColumn *node = (zetasql::ResolvedComputedColumn *)arg0;
  *arg1 = (void *)(new zetasql::ResolvedColumn(node->column()));
}

void GO_EXPORT(ResolvedComputedColumn_set_column)(void * arg0,void * arg1){
  zetasql::ResolvedComputedColumn *node = (zetasql::ResolvedComputedColumn *)arg0;
  node->set_column(*(zetasql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedComputedColumn_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedComputedColumn *node = (zetasql::ResolvedComputedColumn *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedComputedColumn_set_expr)(void * arg0,void * arg1){
  zetasql::ResolvedComputedColumn *node = (zetasql::ResolvedComputedColumn *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedOrderByItem_column_ref)(void * arg0,void ** arg1){
  zetasql::ResolvedOrderByItem *node = (zetasql::ResolvedOrderByItem *)arg0;
  *arg1 = (void *)node->column_ref();
}

void GO_EXPORT(ResolvedOrderByItem_set_column_ref)(void * arg0,void * arg1){
  zetasql::ResolvedOrderByItem *node = (zetasql::ResolvedOrderByItem *)arg0;
  SET_UNIQUE_PTR(node->set_column_ref, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedOrderByItem_collation_name)(void * arg0,void ** arg1){
  zetasql::ResolvedOrderByItem *node = (zetasql::ResolvedOrderByItem *)arg0;
  *arg1 = (void *)node->collation_name();
}

void GO_EXPORT(ResolvedOrderByItem_set_collation_name)(void * arg0,void * arg1){
  zetasql::ResolvedOrderByItem *node = (zetasql::ResolvedOrderByItem *)arg0;
  node->set_collation_name(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedOrderByItem_is_descending)(void * arg0,char* arg1){
  zetasql::ResolvedOrderByItem *node = (zetasql::ResolvedOrderByItem *)arg0;
  *arg1 = node->is_descending();
}

void GO_EXPORT(ResolvedOrderByItem_set_is_descending)(void * arg0,int arg1){
  zetasql::ResolvedOrderByItem *node = (zetasql::ResolvedOrderByItem *)arg0;
  node->set_is_descending(arg1);
}

void GO_EXPORT(ResolvedOrderByItem_null_order)(void * arg0,int* arg1){
  zetasql::ResolvedOrderByItem *node = (zetasql::ResolvedOrderByItem *)arg0;
  *arg1 = node->null_order();
}

void GO_EXPORT(ResolvedOrderByItem_set_null_order)(void * arg0,int arg1){
  zetasql::ResolvedOrderByItem *node = (zetasql::ResolvedOrderByItem *)arg0;
  node->set_null_order((zetasql::ResolvedOrderByItem::NullOrderMode)arg1);
}

void GO_EXPORT(ResolvedOrderByItem_collation)(void * arg0,void ** arg1){
  zetasql::ResolvedOrderByItem *node = (zetasql::ResolvedOrderByItem *)arg0;
  *arg1 = (void *)(new zetasql::ResolvedCollation(node->collation()));
}

void GO_EXPORT(ResolvedOrderByItem_set_collation)(void * arg0,void * arg1){
  zetasql::ResolvedOrderByItem *node = (zetasql::ResolvedOrderByItem *)arg0;
  node->set_collation(*(zetasql::ResolvedCollation *)arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_collation_name)(void * arg0,void ** arg1){
  zetasql::ResolvedColumnAnnotations *node = (zetasql::ResolvedColumnAnnotations *)arg0;
  *arg1 = (void *)node->collation_name();
}

void GO_EXPORT(ResolvedColumnAnnotations_set_collation_name)(void * arg0,void * arg1){
  zetasql::ResolvedColumnAnnotations *node = (zetasql::ResolvedColumnAnnotations *)arg0;
  node->set_collation_name(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedColumnAnnotations_not_null)(void * arg0,char* arg1){
  zetasql::ResolvedColumnAnnotations *node = (zetasql::ResolvedColumnAnnotations *)arg0;
  *arg1 = node->not_null();
}

void GO_EXPORT(ResolvedColumnAnnotations_set_not_null)(void * arg0,int arg1){
  zetasql::ResolvedColumnAnnotations *node = (zetasql::ResolvedColumnAnnotations *)arg0;
  node->set_not_null(arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedColumnAnnotations *node = (zetasql::ResolvedColumnAnnotations *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedColumnAnnotations *node = (zetasql::ResolvedColumnAnnotations *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedColumnAnnotations *node = (zetasql::ResolvedColumnAnnotations *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_child_list)(void * arg0,void ** arg1){
  zetasql::ResolvedColumnAnnotations *node = (zetasql::ResolvedColumnAnnotations *)arg0;
  GET_UNIQUE_PTR_LIST(node->child_list, arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_set_child_list)(void * arg0,void * arg1){
  zetasql::ResolvedColumnAnnotations *node = (zetasql::ResolvedColumnAnnotations *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_child_list, ResolvedColumnAnnotations, arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_add_child_list)(void * arg0,void * arg1){
  zetasql::ResolvedColumnAnnotations *node = (zetasql::ResolvedColumnAnnotations *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_child_list, ResolvedColumnAnnotations, arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_type_parameters)(void * arg0,void ** arg1){
  zetasql::ResolvedColumnAnnotations *node = (zetasql::ResolvedColumnAnnotations *)arg0;
  *arg1 = (void *)(new zetasql::TypeParameters(node->type_parameters()));
}

void GO_EXPORT(ResolvedColumnAnnotations_set_type_parameters)(void * arg0,void * arg1){
  zetasql::ResolvedColumnAnnotations *node = (zetasql::ResolvedColumnAnnotations *)arg0;
  node->set_type_parameters(*(zetasql::TypeParameters *)arg1);
}

void GO_EXPORT(ResolvedGeneratedColumnInfo_expression)(void * arg0,void ** arg1){
  zetasql::ResolvedGeneratedColumnInfo *node = (zetasql::ResolvedGeneratedColumnInfo *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ResolvedGeneratedColumnInfo_set_expression)(void * arg0,void * arg1){
  zetasql::ResolvedGeneratedColumnInfo *node = (zetasql::ResolvedGeneratedColumnInfo *)arg0;
  node->set_expression(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedGeneratedColumnInfo_stored_mode)(void * arg0,int* arg1){
  zetasql::ResolvedGeneratedColumnInfo *node = (zetasql::ResolvedGeneratedColumnInfo *)arg0;
  *arg1 = node->stored_mode();
}

void GO_EXPORT(ResolvedGeneratedColumnInfo_set_stored_mode)(void * arg0,int arg1){
  zetasql::ResolvedGeneratedColumnInfo *node = (zetasql::ResolvedGeneratedColumnInfo *)arg0;
  node->set_stored_mode((zetasql::ResolvedGeneratedColumnInfo::StoredMode)arg1);
}

void GO_EXPORT(ResolvedColumnDefaultValue_expression)(void * arg0,void ** arg1){
  zetasql::ResolvedColumnDefaultValue *node = (zetasql::ResolvedColumnDefaultValue *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ResolvedColumnDefaultValue_set_expression)(void * arg0,void * arg1){
  zetasql::ResolvedColumnDefaultValue *node = (zetasql::ResolvedColumnDefaultValue *)arg0;
  node->set_expression(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedColumnDefaultValue_sql)(void * arg0,void ** arg1){
  zetasql::ResolvedColumnDefaultValue *node = (zetasql::ResolvedColumnDefaultValue *)arg0;
  *arg1 = (void *)((new std::string(node->sql()))->c_str());
}

void GO_EXPORT(ResolvedColumnDefaultValue_set_sql)(void * arg0,void * arg1){
  zetasql::ResolvedColumnDefaultValue *node = (zetasql::ResolvedColumnDefaultValue *)arg0;
  node->set_sql((char *)arg1);
}

void GO_EXPORT(ResolvedColumnDefinition_name)(void * arg0,void ** arg1){
  zetasql::ResolvedColumnDefinition *node = (zetasql::ResolvedColumnDefinition *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedColumnDefinition_set_name)(void * arg0,void * arg1){
  zetasql::ResolvedColumnDefinition *node = (zetasql::ResolvedColumnDefinition *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedColumnDefinition_type)(void * arg0,void ** arg1){
  zetasql::ResolvedColumnDefinition *node = (zetasql::ResolvedColumnDefinition *)arg0;
  *arg1 = (void *)node->type();
}

void GO_EXPORT(ResolvedColumnDefinition_set_type)(void * arg0,void * arg1){
  zetasql::ResolvedColumnDefinition *node = (zetasql::ResolvedColumnDefinition *)arg0;
  node->set_type((const zetasql::Type *)arg1);
}

void GO_EXPORT(ResolvedColumnDefinition_annotations)(void * arg0,void ** arg1){
  zetasql::ResolvedColumnDefinition *node = (zetasql::ResolvedColumnDefinition *)arg0;
  *arg1 = (void *)node->annotations();
}

void GO_EXPORT(ResolvedColumnDefinition_set_annotations)(void * arg0,void * arg1){
  zetasql::ResolvedColumnDefinition *node = (zetasql::ResolvedColumnDefinition *)arg0;
  SET_UNIQUE_PTR(node->set_annotations, ResolvedColumnAnnotations, arg1);
}

void GO_EXPORT(ResolvedColumnDefinition_is_hidden)(void * arg0,char* arg1){
  zetasql::ResolvedColumnDefinition *node = (zetasql::ResolvedColumnDefinition *)arg0;
  *arg1 = node->is_hidden();
}

void GO_EXPORT(ResolvedColumnDefinition_set_is_hidden)(void * arg0,int arg1){
  zetasql::ResolvedColumnDefinition *node = (zetasql::ResolvedColumnDefinition *)arg0;
  node->set_is_hidden(arg1);
}

void GO_EXPORT(ResolvedColumnDefinition_column)(void * arg0,void ** arg1){
  zetasql::ResolvedColumnDefinition *node = (zetasql::ResolvedColumnDefinition *)arg0;
  *arg1 = (void *)(new zetasql::ResolvedColumn(node->column()));
}

void GO_EXPORT(ResolvedColumnDefinition_set_column)(void * arg0,void * arg1){
  zetasql::ResolvedColumnDefinition *node = (zetasql::ResolvedColumnDefinition *)arg0;
  node->set_column(*(zetasql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedColumnDefinition_generated_column_info)(void * arg0,void ** arg1){
  zetasql::ResolvedColumnDefinition *node = (zetasql::ResolvedColumnDefinition *)arg0;
  *arg1 = (void *)node->generated_column_info();
}

void GO_EXPORT(ResolvedColumnDefinition_set_generated_column_info)(void * arg0,void * arg1){
  zetasql::ResolvedColumnDefinition *node = (zetasql::ResolvedColumnDefinition *)arg0;
  SET_UNIQUE_PTR(node->set_generated_column_info, ResolvedGeneratedColumnInfo, arg1);
}

void GO_EXPORT(ResolvedColumnDefinition_default_value)(void * arg0,void ** arg1){
  zetasql::ResolvedColumnDefinition *node = (zetasql::ResolvedColumnDefinition *)arg0;
  *arg1 = (void *)node->default_value();
}

void GO_EXPORT(ResolvedColumnDefinition_set_default_value)(void * arg0,void * arg1){
  zetasql::ResolvedColumnDefinition *node = (zetasql::ResolvedColumnDefinition *)arg0;
  SET_UNIQUE_PTR(node->set_default_value, ResolvedColumnDefaultValue, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_column_offset_list)(void * arg0,void ** arg1){
  zetasql::ResolvedPrimaryKey *node = (zetasql::ResolvedPrimaryKey *)arg0;
  GET_INTS(node->column_offset_list, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_set_column_offset_list)(void * arg0,void * arg1){
  zetasql::ResolvedPrimaryKey *node = (zetasql::ResolvedPrimaryKey *)arg0;
  SET_INTS(node->set_column_offset_list, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_add_column_offset_list)(void * arg0,int arg1){
  zetasql::ResolvedPrimaryKey *node = (zetasql::ResolvedPrimaryKey *)arg0;
  node->add_column_offset_list(arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedPrimaryKey *node = (zetasql::ResolvedPrimaryKey *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedPrimaryKey *node = (zetasql::ResolvedPrimaryKey *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedPrimaryKey *node = (zetasql::ResolvedPrimaryKey *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_unenforced)(void * arg0,char* arg1){
  zetasql::ResolvedPrimaryKey *node = (zetasql::ResolvedPrimaryKey *)arg0;
  *arg1 = node->unenforced();
}

void GO_EXPORT(ResolvedPrimaryKey_set_unenforced)(void * arg0,int arg1){
  zetasql::ResolvedPrimaryKey *node = (zetasql::ResolvedPrimaryKey *)arg0;
  node->set_unenforced(arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_constraint_name)(void * arg0,void ** arg1){
  zetasql::ResolvedPrimaryKey *node = (zetasql::ResolvedPrimaryKey *)arg0;
  *arg1 = (void *)((new std::string(node->constraint_name()))->c_str());
}

void GO_EXPORT(ResolvedPrimaryKey_set_constraint_name)(void * arg0,void * arg1){
  zetasql::ResolvedPrimaryKey *node = (zetasql::ResolvedPrimaryKey *)arg0;
  node->set_constraint_name((char *)arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_column_name_list)(void * arg0,void ** arg1){
  zetasql::ResolvedPrimaryKey *node = (zetasql::ResolvedPrimaryKey *)arg0;
  GET_STRS(node->column_name_list, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_set_column_name_list)(void * arg0,void * arg1){
  zetasql::ResolvedPrimaryKey *node = (zetasql::ResolvedPrimaryKey *)arg0;
  SET_LIST(node->set_column_name_list, std::string, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_add_column_name_list)(void * arg0,void * arg1){
  zetasql::ResolvedPrimaryKey *node = (zetasql::ResolvedPrimaryKey *)arg0;
  node->add_column_name_list((char *)arg1);
}

void GO_EXPORT(ResolvedForeignKey_constraint_name)(void * arg0,void ** arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  *arg1 = (void *)((new std::string(node->constraint_name()))->c_str());
}

void GO_EXPORT(ResolvedForeignKey_set_constraint_name)(void * arg0,void * arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  node->set_constraint_name((char *)arg1);
}

void GO_EXPORT(ResolvedForeignKey_referencing_column_offset_list)(void * arg0,void ** arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  GET_INTS(node->referencing_column_offset_list, arg1);
}

void GO_EXPORT(ResolvedForeignKey_set_referencing_column_offset_list)(void * arg0,void * arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  SET_INTS(node->set_referencing_column_offset_list, arg1);
}

void GO_EXPORT(ResolvedForeignKey_add_referencing_column_offset_list)(void * arg0,int arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  node->add_referencing_column_offset_list(arg1);
}

void GO_EXPORT(ResolvedForeignKey_referenced_table)(void * arg0,void ** arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  *arg1 = (void *)node->referenced_table();
}

void GO_EXPORT(ResolvedForeignKey_set_referenced_table)(void * arg0,void * arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  node->set_referenced_table((const zetasql::Table *)arg1);
}

void GO_EXPORT(ResolvedForeignKey_referenced_column_offset_list)(void * arg0,void ** arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  GET_INTS(node->referenced_column_offset_list, arg1);
}

void GO_EXPORT(ResolvedForeignKey_set_referenced_column_offset_list)(void * arg0,void * arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  SET_INTS(node->set_referenced_column_offset_list, arg1);
}

void GO_EXPORT(ResolvedForeignKey_add_referenced_column_offset_list)(void * arg0,int arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  node->add_referenced_column_offset_list(arg1);
}

void GO_EXPORT(ResolvedForeignKey_match_mode)(void * arg0,int* arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  *arg1 = node->match_mode();
}

void GO_EXPORT(ResolvedForeignKey_set_match_mode)(void * arg0,int arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  node->set_match_mode((zetasql::ResolvedForeignKey::MatchMode)arg1);
}

void GO_EXPORT(ResolvedForeignKey_update_action)(void * arg0,int* arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  *arg1 = node->update_action();
}

void GO_EXPORT(ResolvedForeignKey_set_update_action)(void * arg0,int arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  node->set_update_action((zetasql::ResolvedForeignKey::ActionOperation)arg1);
}

void GO_EXPORT(ResolvedForeignKey_delete_action)(void * arg0,int* arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  *arg1 = node->delete_action();
}

void GO_EXPORT(ResolvedForeignKey_set_delete_action)(void * arg0,int arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  node->set_delete_action((zetasql::ResolvedForeignKey::ActionOperation)arg1);
}

void GO_EXPORT(ResolvedForeignKey_enforced)(void * arg0,char* arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  *arg1 = node->enforced();
}

void GO_EXPORT(ResolvedForeignKey_set_enforced)(void * arg0,int arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  node->set_enforced(arg1);
}

void GO_EXPORT(ResolvedForeignKey_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedForeignKey_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedForeignKey_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedForeignKey_referencing_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  GET_STRS(node->referencing_column_list, arg1);
}

void GO_EXPORT(ResolvedForeignKey_set_referencing_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  SET_LIST(node->set_referencing_column_list, std::string, arg1);
}

void GO_EXPORT(ResolvedForeignKey_add_referencing_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedForeignKey *node = (zetasql::ResolvedForeignKey *)arg0;
  node->add_referencing_column_list((char *)arg1);
}

void GO_EXPORT(ResolvedCheckConstraint_constraint_name)(void * arg0,void ** arg1){
  zetasql::ResolvedCheckConstraint *node = (zetasql::ResolvedCheckConstraint *)arg0;
  *arg1 = (void *)((new std::string(node->constraint_name()))->c_str());
}

void GO_EXPORT(ResolvedCheckConstraint_set_constraint_name)(void * arg0,void * arg1){
  zetasql::ResolvedCheckConstraint *node = (zetasql::ResolvedCheckConstraint *)arg0;
  node->set_constraint_name((char *)arg1);
}

void GO_EXPORT(ResolvedCheckConstraint_expression)(void * arg0,void ** arg1){
  zetasql::ResolvedCheckConstraint *node = (zetasql::ResolvedCheckConstraint *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ResolvedCheckConstraint_set_expression)(void * arg0,void * arg1){
  zetasql::ResolvedCheckConstraint *node = (zetasql::ResolvedCheckConstraint *)arg0;
  node->set_expression(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCheckConstraint_enforced)(void * arg0,char* arg1){
  zetasql::ResolvedCheckConstraint *node = (zetasql::ResolvedCheckConstraint *)arg0;
  *arg1 = node->enforced();
}

void GO_EXPORT(ResolvedCheckConstraint_set_enforced)(void * arg0,int arg1){
  zetasql::ResolvedCheckConstraint *node = (zetasql::ResolvedCheckConstraint *)arg0;
  node->set_enforced(arg1);
}

void GO_EXPORT(ResolvedCheckConstraint_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCheckConstraint *node = (zetasql::ResolvedCheckConstraint *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCheckConstraint_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCheckConstraint *node = (zetasql::ResolvedCheckConstraint *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCheckConstraint_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCheckConstraint *node = (zetasql::ResolvedCheckConstraint *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedOutputColumn_name)(void * arg0,void ** arg1){
  zetasql::ResolvedOutputColumn *node = (zetasql::ResolvedOutputColumn *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedOutputColumn_set_name)(void * arg0,void * arg1){
  zetasql::ResolvedOutputColumn *node = (zetasql::ResolvedOutputColumn *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedOutputColumn_column)(void * arg0,void ** arg1){
  zetasql::ResolvedOutputColumn *node = (zetasql::ResolvedOutputColumn *)arg0;
  *arg1 = (void *)(new zetasql::ResolvedColumn(node->column()));
}

void GO_EXPORT(ResolvedOutputColumn_set_column)(void * arg0,void * arg1){
  zetasql::ResolvedOutputColumn *node = (zetasql::ResolvedOutputColumn *)arg0;
  node->set_column(*(zetasql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedProjectScan_expr_list)(void * arg0,void ** arg1){
  zetasql::ResolvedProjectScan *node = (zetasql::ResolvedProjectScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->expr_list, arg1);
}

void GO_EXPORT(ResolvedProjectScan_set_expr_list)(void * arg0,void * arg1){
  zetasql::ResolvedProjectScan *node = (zetasql::ResolvedProjectScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_expr_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedProjectScan_add_expr_list)(void * arg0,void * arg1){
  zetasql::ResolvedProjectScan *node = (zetasql::ResolvedProjectScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_expr_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedProjectScan_input_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedProjectScan *node = (zetasql::ResolvedProjectScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedProjectScan_set_input_scan)(void * arg0,void * arg1){
  zetasql::ResolvedProjectScan *node = (zetasql::ResolvedProjectScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedTVFScan_tvf)(void * arg0,void ** arg1){
  zetasql::ResolvedTVFScan *node = (zetasql::ResolvedTVFScan *)arg0;
  *arg1 = (void *)node->tvf();
}

void GO_EXPORT(ResolvedTVFScan_set_tvf)(void * arg0,void * arg1){
  zetasql::ResolvedTVFScan *node = (zetasql::ResolvedTVFScan *)arg0;
  node->set_tvf((const zetasql::TableValuedFunction *)arg1);
}

void GO_EXPORT(ResolvedTVFScan_signature)(void * arg0,void ** arg1){
  zetasql::ResolvedTVFScan *node = (zetasql::ResolvedTVFScan *)arg0;
  *arg1 = (void *)node->signature().get();
}

void GO_EXPORT(ResolvedTVFScan_set_signature)(void * arg0,void * arg1){
  zetasql::ResolvedTVFScan *node = (zetasql::ResolvedTVFScan *)arg0;
  zetasql::TVFSignature *sig = (zetasql::TVFSignature *)arg1;
  std::shared_ptr<zetasql::TVFSignature> p = std::make_shared<zetasql::TVFSignature>(
    sig->input_arguments(),
    sig->result_schema(),
    sig->options()
  );
  node->set_signature(p);
}

void GO_EXPORT(ResolvedTVFScan_argument_list)(void * arg0,void ** arg1){
  zetasql::ResolvedTVFScan *node = (zetasql::ResolvedTVFScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->argument_list, arg1);
}

void GO_EXPORT(ResolvedTVFScan_set_argument_list)(void * arg0,void * arg1){
  zetasql::ResolvedTVFScan *node = (zetasql::ResolvedTVFScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_argument_list, ResolvedFunctionArgument, arg1);
}

void GO_EXPORT(ResolvedTVFScan_add_argument_list)(void * arg0,void * arg1){
  zetasql::ResolvedTVFScan *node = (zetasql::ResolvedTVFScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_argument_list, ResolvedFunctionArgument, arg1);
}

void GO_EXPORT(ResolvedTVFScan_column_index_list)(void * arg0,void ** arg1){
  zetasql::ResolvedTVFScan *node = (zetasql::ResolvedTVFScan *)arg0;
  GET_INTS(node->column_index_list, arg1);
}

void GO_EXPORT(ResolvedTVFScan_set_column_index_list)(void * arg0,void * arg1){
  zetasql::ResolvedTVFScan *node = (zetasql::ResolvedTVFScan *)arg0;
  SET_INTS(node->set_column_index_list, arg1);
}

void GO_EXPORT(ResolvedTVFScan_add_column_index_list)(void * arg0,int arg1){
  zetasql::ResolvedTVFScan *node = (zetasql::ResolvedTVFScan *)arg0;
  node->add_column_index_list(arg1);
}

void GO_EXPORT(ResolvedTVFScan_alias)(void * arg0,void ** arg1){
  zetasql::ResolvedTVFScan *node = (zetasql::ResolvedTVFScan *)arg0;
  *arg1 = (void *)((new std::string(node->alias()))->c_str());
}

void GO_EXPORT(ResolvedTVFScan_set_alias)(void * arg0,void * arg1){
  zetasql::ResolvedTVFScan *node = (zetasql::ResolvedTVFScan *)arg0;
  node->set_alias((char *)arg1);
}

void GO_EXPORT(ResolvedTVFScan_function_call_signature)(void * arg0,void ** arg1){
  zetasql::ResolvedTVFScan *node = (zetasql::ResolvedTVFScan *)arg0;
  *arg1 = (void *)node->function_call_signature().get();
}

void GO_EXPORT(ResolvedTVFScan_set_function_call_signature)(void * arg0,void * arg1){
  zetasql::ResolvedTVFScan *node = (zetasql::ResolvedTVFScan *)arg0;
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg1;
  auto p = std::make_shared<zetasql::FunctionSignature>(*sig, (void *)sig->context_ptr());
  node->set_function_call_signature(p);
}

void GO_EXPORT(ResolvedGroupRowsScan_input_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedGroupRowsScan *node = (zetasql::ResolvedGroupRowsScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->input_column_list, arg1);
}

void GO_EXPORT(ResolvedGroupRowsScan_set_input_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedGroupRowsScan *node = (zetasql::ResolvedGroupRowsScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_input_column_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedGroupRowsScan_add_input_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedGroupRowsScan *node = (zetasql::ResolvedGroupRowsScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_input_column_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedGroupRowsScan_alias)(void * arg0,void ** arg1){
  zetasql::ResolvedGroupRowsScan *node = (zetasql::ResolvedGroupRowsScan *)arg0;
  *arg1 = (void *)((new std::string(node->alias()))->c_str());
}

void GO_EXPORT(ResolvedGroupRowsScan_set_alias)(void * arg0,void * arg1){
  zetasql::ResolvedGroupRowsScan *node = (zetasql::ResolvedGroupRowsScan *)arg0;
  node->set_alias((char *)arg1);
}

void GO_EXPORT(ResolvedFunctionArgument_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionArgument *node = (zetasql::ResolvedFunctionArgument *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedFunctionArgument_set_expr)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionArgument *node = (zetasql::ResolvedFunctionArgument *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedFunctionArgument_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionArgument *node = (zetasql::ResolvedFunctionArgument *)arg0;
  *arg1 = (void *)node->scan();
}

void GO_EXPORT(ResolvedFunctionArgument_set_scan)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionArgument *node = (zetasql::ResolvedFunctionArgument *)arg0;
  node->set_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedFunctionArgument_model)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionArgument *node = (zetasql::ResolvedFunctionArgument *)arg0;
  *arg1 = (void *)node->model();
}

void GO_EXPORT(ResolvedFunctionArgument_set_model)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionArgument *node = (zetasql::ResolvedFunctionArgument *)arg0;
  SET_UNIQUE_PTR(node->set_model, ResolvedModel, arg1);
}

void GO_EXPORT(ResolvedFunctionArgument_connection)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionArgument *node = (zetasql::ResolvedFunctionArgument *)arg0;
  *arg1 = (void *)node->connection();
}

void GO_EXPORT(ResolvedFunctionArgument_set_connection)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionArgument *node = (zetasql::ResolvedFunctionArgument *)arg0;
  SET_UNIQUE_PTR(node->set_connection, ResolvedConnection, arg1);
}

void GO_EXPORT(ResolvedFunctionArgument_descriptor_arg)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionArgument *node = (zetasql::ResolvedFunctionArgument *)arg0;
  *arg1 = (void *)node->descriptor_arg();
}

void GO_EXPORT(ResolvedFunctionArgument_set_descriptor_arg)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionArgument *node = (zetasql::ResolvedFunctionArgument *)arg0;
  SET_UNIQUE_PTR(node->set_descriptor_arg, ResolvedDescriptor, arg1);
}

void GO_EXPORT(ResolvedFunctionArgument_argument_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionArgument *node = (zetasql::ResolvedFunctionArgument *)arg0;
  GET_LIST(node->argument_column_list, arg1);
}

void GO_EXPORT(ResolvedFunctionArgument_set_argument_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionArgument *node = (zetasql::ResolvedFunctionArgument *)arg0;
  SET_LIST(node->set_argument_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedFunctionArgument_add_argument_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionArgument *node = (zetasql::ResolvedFunctionArgument *)arg0;
  ADD_LIST(node->add_argument_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedFunctionArgument_inline_lambda)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionArgument *node = (zetasql::ResolvedFunctionArgument *)arg0;
  *arg1 = (void *)node->inline_lambda();
}

void GO_EXPORT(ResolvedFunctionArgument_set_inline_lambda)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionArgument *node = (zetasql::ResolvedFunctionArgument *)arg0;
  SET_UNIQUE_PTR(node->set_inline_lambda, ResolvedInlineLambda, arg1);
}

void GO_EXPORT(ResolvedStatement_hint_list)(void * arg0,void ** arg1){
  zetasql::ResolvedStatement *node = (zetasql::ResolvedStatement *)arg0;
  GET_UNIQUE_PTR_LIST(node->hint_list, arg1);
}

void GO_EXPORT(ResolvedStatement_set_hint_list)(void * arg0,void * arg1){
  zetasql::ResolvedStatement *node = (zetasql::ResolvedStatement *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedStatement_add_hint_list)(void * arg0,void * arg1){
  zetasql::ResolvedStatement *node = (zetasql::ResolvedStatement *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedExplainStmt_statement)(void * arg0,void ** arg1){
  zetasql::ResolvedExplainStmt *node = (zetasql::ResolvedExplainStmt *)arg0;
  *arg1 = (void *)node->statement();
}

void GO_EXPORT(ResolvedExplainStmt_set_statement)(void * arg0,void * arg1){
  zetasql::ResolvedExplainStmt *node = (zetasql::ResolvedExplainStmt *)arg0;
  node->set_statement(make_unique_stmt(arg1));
}

void GO_EXPORT(ResolvedQueryStmt_output_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedQueryStmt *node = (zetasql::ResolvedQueryStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedQueryStmt_set_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedQueryStmt *node = (zetasql::ResolvedQueryStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedQueryStmt_add_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedQueryStmt *node = (zetasql::ResolvedQueryStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedQueryStmt_is_value_table)(void * arg0,char* arg1){
  zetasql::ResolvedQueryStmt *node = (zetasql::ResolvedQueryStmt *)arg0;
  *arg1 = node->is_value_table();
}

void GO_EXPORT(ResolvedQueryStmt_set_is_value_table)(void * arg0,int arg1){
  zetasql::ResolvedQueryStmt *node = (zetasql::ResolvedQueryStmt *)arg0;
  node->set_is_value_table(arg1);
}

void GO_EXPORT(ResolvedQueryStmt_query)(void * arg0,void ** arg1){
  zetasql::ResolvedQueryStmt *node = (zetasql::ResolvedQueryStmt *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedQueryStmt_set_query)(void * arg0,void * arg1){
  zetasql::ResolvedQueryStmt *node = (zetasql::ResolvedQueryStmt *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateDatabaseStmt *node = (zetasql::ResolvedCreateDatabaseStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedCreateDatabaseStmt *node = (zetasql::ResolvedCreateDatabaseStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedCreateDatabaseStmt *node = (zetasql::ResolvedCreateDatabaseStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateDatabaseStmt *node = (zetasql::ResolvedCreateDatabaseStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateDatabaseStmt *node = (zetasql::ResolvedCreateDatabaseStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateDatabaseStmt *node = (zetasql::ResolvedCreateDatabaseStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateStatement_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateStatement *node = (zetasql::ResolvedCreateStatement *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedCreateStatement_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedCreateStatement *node = (zetasql::ResolvedCreateStatement *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateStatement_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedCreateStatement *node = (zetasql::ResolvedCreateStatement *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedCreateStatement_create_scope)(void * arg0,int* arg1){
  zetasql::ResolvedCreateStatement *node = (zetasql::ResolvedCreateStatement *)arg0;
  *arg1 = node->create_scope();
}

void GO_EXPORT(ResolvedCreateStatement_set_create_scope)(void * arg0,int arg1){
  zetasql::ResolvedCreateStatement *node = (zetasql::ResolvedCreateStatement *)arg0;
  node->set_create_scope((zetasql::ResolvedCreateStatement::CreateScope)arg1);
}

void GO_EXPORT(ResolvedCreateStatement_create_mode)(void * arg0,int* arg1){
  zetasql::ResolvedCreateStatement *node = (zetasql::ResolvedCreateStatement *)arg0;
  *arg1 = node->create_mode();
}

void GO_EXPORT(ResolvedCreateStatement_set_create_mode)(void * arg0,int arg1){
  zetasql::ResolvedCreateStatement *node = (zetasql::ResolvedCreateStatement *)arg0;
  node->set_create_mode((zetasql::ResolvedCreateStatement::CreateMode)arg1);
}

void GO_EXPORT(ResolvedIndexItem_column_ref)(void * arg0,void ** arg1){
  zetasql::ResolvedIndexItem *node = (zetasql::ResolvedIndexItem *)arg0;
  *arg1 = (void *)node->column_ref();
}

void GO_EXPORT(ResolvedIndexItem_set_column_ref)(void * arg0,void * arg1){
  zetasql::ResolvedIndexItem *node = (zetasql::ResolvedIndexItem *)arg0;
  SET_UNIQUE_PTR(node->set_column_ref, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedIndexItem_descending)(void * arg0,char* arg1){
  zetasql::ResolvedIndexItem *node = (zetasql::ResolvedIndexItem *)arg0;
  *arg1 = node->descending();
}

void GO_EXPORT(ResolvedIndexItem_set_descending)(void * arg0,int arg1){
  zetasql::ResolvedIndexItem *node = (zetasql::ResolvedIndexItem *)arg0;
  node->set_descending(arg1);
}

void GO_EXPORT(ResolvedUnnestItem_array_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedUnnestItem *node = (zetasql::ResolvedUnnestItem *)arg0;
  *arg1 = (void *)node->array_expr();
}

void GO_EXPORT(ResolvedUnnestItem_set_array_expr)(void * arg0,void * arg1){
  zetasql::ResolvedUnnestItem *node = (zetasql::ResolvedUnnestItem *)arg0;
  node->set_array_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedUnnestItem_element_column)(void * arg0,void ** arg1){
  zetasql::ResolvedUnnestItem *node = (zetasql::ResolvedUnnestItem *)arg0;
  *arg1 = (void *)(new zetasql::ResolvedColumn(node->element_column()));
}

void GO_EXPORT(ResolvedUnnestItem_set_element_column)(void * arg0,void * arg1){
  zetasql::ResolvedUnnestItem *node = (zetasql::ResolvedUnnestItem *)arg0;
  node->set_element_column(*(zetasql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedUnnestItem_array_offset_column)(void * arg0,void ** arg1){
  zetasql::ResolvedUnnestItem *node = (zetasql::ResolvedUnnestItem *)arg0;
  *arg1 = (void *)node->array_offset_column();
}

void GO_EXPORT(ResolvedUnnestItem_set_array_offset_column)(void * arg0,void * arg1){
  zetasql::ResolvedUnnestItem *node = (zetasql::ResolvedUnnestItem *)arg0;
  SET_UNIQUE_PTR(node->set_array_offset_column, ResolvedColumnHolder, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_table_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  GET_STRS(node->table_name_path, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_table_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  SET_LIST(node->set_table_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_table_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  node->add_table_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_table_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_table_scan)(void * arg0,void * arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_is_unique)(void * arg0,char* arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  *arg1 = node->is_unique();
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_is_unique)(void * arg0,int arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  node->set_is_unique(arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_is_search)(void * arg0,char* arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  *arg1 = node->is_search();
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_is_search)(void * arg0,int arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  node->set_is_search(arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_index_all_columns)(void * arg0,char* arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  *arg1 = node->index_all_columns();
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_index_all_columns)(void * arg0,int arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  node->set_index_all_columns(arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_index_item_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->index_item_list, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_index_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_index_item_list, ResolvedIndexItem, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_index_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_index_item_list, ResolvedIndexItem, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_storing_expression_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->storing_expression_list, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_storing_expression_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_storing_expression_list, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_storing_expression_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_storing_expression_list, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_computed_columns_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->computed_columns_list, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_computed_columns_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_computed_columns_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_computed_columns_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_computed_columns_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_unnest_expressions_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->unnest_expressions_list, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_unnest_expressions_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_unnest_expressions_list, ResolvedUnnestItem, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_unnest_expressions_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateIndexStmt *node = (zetasql::ResolvedCreateIndexStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_unnest_expressions_list, ResolvedUnnestItem, arg1);
}

void GO_EXPORT(ResolvedCreateSchemaStmt_collation_name)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateSchemaStmt *node = (zetasql::ResolvedCreateSchemaStmt *)arg0;
  *arg1 = (void *)node->collation_name();
}

void GO_EXPORT(ResolvedCreateSchemaStmt_set_collation_name)(void * arg0,void * arg1){
  zetasql::ResolvedCreateSchemaStmt *node = (zetasql::ResolvedCreateSchemaStmt *)arg0;
  node->set_collation_name(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCreateSchemaStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateSchemaStmt *node = (zetasql::ResolvedCreateSchemaStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateSchemaStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateSchemaStmt *node = (zetasql::ResolvedCreateSchemaStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateSchemaStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateSchemaStmt *node = (zetasql::ResolvedCreateSchemaStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_column_definition_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_definition_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_column_definition_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_add_column_definition_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_pseudo_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  GET_LIST(node->pseudo_column_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_pseudo_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  SET_LIST(node->set_pseudo_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_add_pseudo_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  ADD_LIST(node->add_pseudo_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_primary_key)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  *arg1 = (void *)node->primary_key();
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_primary_key)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  SET_UNIQUE_PTR(node->set_primary_key, ResolvedPrimaryKey, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_foreign_key_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->foreign_key_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_foreign_key_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_foreign_key_list, ResolvedForeignKey, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_add_foreign_key_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_foreign_key_list, ResolvedForeignKey, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_check_constraint_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->check_constraint_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_check_constraint_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_check_constraint_list, ResolvedCheckConstraint, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_add_check_constraint_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_check_constraint_list, ResolvedCheckConstraint, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_is_value_table)(void * arg0,char* arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  *arg1 = node->is_value_table();
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_is_value_table)(void * arg0,int arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  node->set_is_value_table(arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_like_table)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  *arg1 = (void *)node->like_table();
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_like_table)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  node->set_like_table((const zetasql::Table *)arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_collation_name)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  *arg1 = (void *)node->collation_name();
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_collation_name)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmtBase *node = (zetasql::ResolvedCreateTableStmtBase *)arg0;
  node->set_collation_name(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCreateTableStmt_clone_from)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableStmt *node = (zetasql::ResolvedCreateTableStmt *)arg0;
  *arg1 = (void *)node->clone_from();
}

void GO_EXPORT(ResolvedCreateTableStmt_set_clone_from)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmt *node = (zetasql::ResolvedCreateTableStmt *)arg0;
  node->set_clone_from(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateTableStmt_copy_from)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableStmt *node = (zetasql::ResolvedCreateTableStmt *)arg0;
  *arg1 = (void *)node->copy_from();
}

void GO_EXPORT(ResolvedCreateTableStmt_set_copy_from)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmt *node = (zetasql::ResolvedCreateTableStmt *)arg0;
  node->set_copy_from(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateTableStmt_partition_by_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableStmt *node = (zetasql::ResolvedCreateTableStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmt_set_partition_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmt *node = (zetasql::ResolvedCreateTableStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmt_add_partition_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmt *node = (zetasql::ResolvedCreateTableStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmt_cluster_by_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableStmt *node = (zetasql::ResolvedCreateTableStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmt_set_cluster_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmt *node = (zetasql::ResolvedCreateTableStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmt_add_cluster_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableStmt *node = (zetasql::ResolvedCreateTableStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_partition_by_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableAsSelectStmt *node = (zetasql::ResolvedCreateTableAsSelectStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_set_partition_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableAsSelectStmt *node = (zetasql::ResolvedCreateTableAsSelectStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_add_partition_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableAsSelectStmt *node = (zetasql::ResolvedCreateTableAsSelectStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_cluster_by_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableAsSelectStmt *node = (zetasql::ResolvedCreateTableAsSelectStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_set_cluster_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableAsSelectStmt *node = (zetasql::ResolvedCreateTableAsSelectStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_add_cluster_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableAsSelectStmt *node = (zetasql::ResolvedCreateTableAsSelectStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_output_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableAsSelectStmt *node = (zetasql::ResolvedCreateTableAsSelectStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_set_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableAsSelectStmt *node = (zetasql::ResolvedCreateTableAsSelectStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_add_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableAsSelectStmt *node = (zetasql::ResolvedCreateTableAsSelectStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_query)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableAsSelectStmt *node = (zetasql::ResolvedCreateTableAsSelectStmt *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_set_query)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableAsSelectStmt *node = (zetasql::ResolvedCreateTableAsSelectStmt *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateModelStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_output_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_set_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_add_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_query)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedCreateModelStmt_set_query)(void * arg0,void * arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateModelStmt_transform_input_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->transform_input_column_list, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_set_transform_input_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_transform_input_column_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_add_transform_input_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_transform_input_column_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_transform_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->transform_list, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_set_transform_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_transform_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_add_transform_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_transform_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_transform_output_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->transform_output_column_list, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_set_transform_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_transform_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_add_transform_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_transform_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_transform_analytic_function_group_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->transform_analytic_function_group_list, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_set_transform_analytic_function_group_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_transform_analytic_function_group_list, ResolvedAnalyticFunctionGroup, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_add_transform_analytic_function_group_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateModelStmt *node = (zetasql::ResolvedCreateModelStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_transform_analytic_function_group_list, ResolvedAnalyticFunctionGroup, arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_output_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_set_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_add_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_has_explicit_columns)(void * arg0,char* arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  *arg1 = node->has_explicit_columns();
}

void GO_EXPORT(ResolvedCreateViewBase_set_has_explicit_columns)(void * arg0,int arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  node->set_has_explicit_columns(arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_query)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedCreateViewBase_set_query)(void * arg0,void * arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateViewBase_sql)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  *arg1 = (void *)((new std::string(node->sql()))->c_str());
}

void GO_EXPORT(ResolvedCreateViewBase_set_sql)(void * arg0,void * arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  node->set_sql((char *)arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_sql_security)(void * arg0,int* arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  *arg1 = node->sql_security();
}

void GO_EXPORT(ResolvedCreateViewBase_set_sql_security)(void * arg0,int arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  node->set_sql_security((zetasql::ResolvedCreateViewBase::SqlSecurity)arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_is_value_table)(void * arg0,char* arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  *arg1 = node->is_value_table();
}

void GO_EXPORT(ResolvedCreateViewBase_set_is_value_table)(void * arg0,int arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  node->set_is_value_table(arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_recursive)(void * arg0,char* arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  *arg1 = node->recursive();
}

void GO_EXPORT(ResolvedCreateViewBase_set_recursive)(void * arg0,int arg1){
  zetasql::ResolvedCreateViewBase *node = (zetasql::ResolvedCreateViewBase *)arg0;
  node->set_recursive(arg1);
}

void GO_EXPORT(ResolvedWithPartitionColumns_column_definition_list)(void * arg0,void ** arg1){
  zetasql::ResolvedWithPartitionColumns *node = (zetasql::ResolvedWithPartitionColumns *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_definition_list, arg1);
}

void GO_EXPORT(ResolvedWithPartitionColumns_set_column_definition_list)(void * arg0,void * arg1){
  zetasql::ResolvedWithPartitionColumns *node = (zetasql::ResolvedWithPartitionColumns *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedWithPartitionColumns_add_column_definition_list)(void * arg0,void * arg1){
  zetasql::ResolvedWithPartitionColumns *node = (zetasql::ResolvedWithPartitionColumns *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedCreateSnapshotTableStmt_clone_from)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateSnapshotTableStmt *node = (zetasql::ResolvedCreateSnapshotTableStmt *)arg0;
  *arg1 = (void *)node->clone_from();
}

void GO_EXPORT(ResolvedCreateSnapshotTableStmt_set_clone_from)(void * arg0,void * arg1){
  zetasql::ResolvedCreateSnapshotTableStmt *node = (zetasql::ResolvedCreateSnapshotTableStmt *)arg0;
  node->set_clone_from(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateSnapshotTableStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateSnapshotTableStmt *node = (zetasql::ResolvedCreateSnapshotTableStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateSnapshotTableStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateSnapshotTableStmt *node = (zetasql::ResolvedCreateSnapshotTableStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateSnapshotTableStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateSnapshotTableStmt *node = (zetasql::ResolvedCreateSnapshotTableStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateExternalTableStmt_with_partition_columns)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateExternalTableStmt *node = (zetasql::ResolvedCreateExternalTableStmt *)arg0;
  *arg1 = (void *)node->with_partition_columns();
}

void GO_EXPORT(ResolvedCreateExternalTableStmt_set_with_partition_columns)(void * arg0,void * arg1){
  zetasql::ResolvedCreateExternalTableStmt *node = (zetasql::ResolvedCreateExternalTableStmt *)arg0;
  SET_UNIQUE_PTR(node->set_with_partition_columns, ResolvedWithPartitionColumns, arg1);
}

void GO_EXPORT(ResolvedCreateExternalTableStmt_connection)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateExternalTableStmt *node = (zetasql::ResolvedCreateExternalTableStmt *)arg0;
  *arg1 = (void *)node->connection();
}

void GO_EXPORT(ResolvedCreateExternalTableStmt_set_connection)(void * arg0,void * arg1){
  zetasql::ResolvedCreateExternalTableStmt *node = (zetasql::ResolvedCreateExternalTableStmt *)arg0;
  SET_UNIQUE_PTR(node->set_connection, ResolvedConnection, arg1);
}

void GO_EXPORT(ResolvedExportModelStmt_model_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedExportModelStmt *node = (zetasql::ResolvedExportModelStmt *)arg0;
  GET_STRS(node->model_name_path, arg1);
}

void GO_EXPORT(ResolvedExportModelStmt_set_model_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedExportModelStmt *node = (zetasql::ResolvedExportModelStmt *)arg0;
  SET_LIST(node->set_model_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedExportModelStmt_add_model_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedExportModelStmt *node = (zetasql::ResolvedExportModelStmt *)arg0;
  node->add_model_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedExportModelStmt_connection)(void * arg0,void ** arg1){
  zetasql::ResolvedExportModelStmt *node = (zetasql::ResolvedExportModelStmt *)arg0;
  *arg1 = (void *)node->connection();
}

void GO_EXPORT(ResolvedExportModelStmt_set_connection)(void * arg0,void * arg1){
  zetasql::ResolvedExportModelStmt *node = (zetasql::ResolvedExportModelStmt *)arg0;
  SET_UNIQUE_PTR(node->set_connection, ResolvedConnection, arg1);
}

void GO_EXPORT(ResolvedExportModelStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedExportModelStmt *node = (zetasql::ResolvedExportModelStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedExportModelStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedExportModelStmt *node = (zetasql::ResolvedExportModelStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedExportModelStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedExportModelStmt *node = (zetasql::ResolvedExportModelStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_connection)(void * arg0,void ** arg1){
  zetasql::ResolvedExportDataStmt *node = (zetasql::ResolvedExportDataStmt *)arg0;
  *arg1 = (void *)node->connection();
}

void GO_EXPORT(ResolvedExportDataStmt_set_connection)(void * arg0,void * arg1){
  zetasql::ResolvedExportDataStmt *node = (zetasql::ResolvedExportDataStmt *)arg0;
  SET_UNIQUE_PTR(node->set_connection, ResolvedConnection, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedExportDataStmt *node = (zetasql::ResolvedExportDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedExportDataStmt *node = (zetasql::ResolvedExportDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedExportDataStmt *node = (zetasql::ResolvedExportDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_output_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedExportDataStmt *node = (zetasql::ResolvedExportDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_set_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedExportDataStmt *node = (zetasql::ResolvedExportDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_add_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedExportDataStmt *node = (zetasql::ResolvedExportDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_is_value_table)(void * arg0,char* arg1){
  zetasql::ResolvedExportDataStmt *node = (zetasql::ResolvedExportDataStmt *)arg0;
  *arg1 = node->is_value_table();
}

void GO_EXPORT(ResolvedExportDataStmt_set_is_value_table)(void * arg0,int arg1){
  zetasql::ResolvedExportDataStmt *node = (zetasql::ResolvedExportDataStmt *)arg0;
  node->set_is_value_table(arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_query)(void * arg0,void ** arg1){
  zetasql::ResolvedExportDataStmt *node = (zetasql::ResolvedExportDataStmt *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedExportDataStmt_set_query)(void * arg0,void * arg1){
  zetasql::ResolvedExportDataStmt *node = (zetasql::ResolvedExportDataStmt *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedDefineTableStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedDefineTableStmt *node = (zetasql::ResolvedDefineTableStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDefineTableStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDefineTableStmt *node = (zetasql::ResolvedDefineTableStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDefineTableStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDefineTableStmt *node = (zetasql::ResolvedDefineTableStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedDefineTableStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedDefineTableStmt *node = (zetasql::ResolvedDefineTableStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedDefineTableStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedDefineTableStmt *node = (zetasql::ResolvedDefineTableStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedDefineTableStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedDefineTableStmt *node = (zetasql::ResolvedDefineTableStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedDescribeStmt_object_type)(void * arg0,void ** arg1){
  zetasql::ResolvedDescribeStmt *node = (zetasql::ResolvedDescribeStmt *)arg0;
  *arg1 = (void *)((new std::string(node->object_type()))->c_str());
}

void GO_EXPORT(ResolvedDescribeStmt_set_object_type)(void * arg0,void * arg1){
  zetasql::ResolvedDescribeStmt *node = (zetasql::ResolvedDescribeStmt *)arg0;
  node->set_object_type((char *)arg1);
}

void GO_EXPORT(ResolvedDescribeStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedDescribeStmt *node = (zetasql::ResolvedDescribeStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDescribeStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDescribeStmt *node = (zetasql::ResolvedDescribeStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDescribeStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDescribeStmt *node = (zetasql::ResolvedDescribeStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedDescribeStmt_from_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedDescribeStmt *node = (zetasql::ResolvedDescribeStmt *)arg0;
  GET_STRS(node->from_name_path, arg1);
}

void GO_EXPORT(ResolvedDescribeStmt_set_from_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDescribeStmt *node = (zetasql::ResolvedDescribeStmt *)arg0;
  SET_LIST(node->set_from_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDescribeStmt_add_from_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDescribeStmt *node = (zetasql::ResolvedDescribeStmt *)arg0;
  node->add_from_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedShowStmt_identifier)(void * arg0,void ** arg1){
  zetasql::ResolvedShowStmt *node = (zetasql::ResolvedShowStmt *)arg0;
  *arg1 = (void *)((new std::string(node->identifier()))->c_str());
}

void GO_EXPORT(ResolvedShowStmt_set_identifier)(void * arg0,void * arg1){
  zetasql::ResolvedShowStmt *node = (zetasql::ResolvedShowStmt *)arg0;
  node->set_identifier((char *)arg1);
}

void GO_EXPORT(ResolvedShowStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedShowStmt *node = (zetasql::ResolvedShowStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedShowStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedShowStmt *node = (zetasql::ResolvedShowStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedShowStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedShowStmt *node = (zetasql::ResolvedShowStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedShowStmt_like_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedShowStmt *node = (zetasql::ResolvedShowStmt *)arg0;
  *arg1 = (void *)node->like_expr();
}

void GO_EXPORT(ResolvedShowStmt_set_like_expr)(void * arg0,void * arg1){
  zetasql::ResolvedShowStmt *node = (zetasql::ResolvedShowStmt *)arg0;
  SET_UNIQUE_PTR(node->set_like_expr, ResolvedLiteral, arg1);
}

void GO_EXPORT(ResolvedBeginStmt_read_write_mode)(void * arg0,int* arg1){
  zetasql::ResolvedBeginStmt *node = (zetasql::ResolvedBeginStmt *)arg0;
  *arg1 = node->read_write_mode();
}

void GO_EXPORT(ResolvedBeginStmt_set_read_write_mode)(void * arg0,int arg1){
  zetasql::ResolvedBeginStmt *node = (zetasql::ResolvedBeginStmt *)arg0;
  node->set_read_write_mode((zetasql::ResolvedBeginStmt::ReadWriteMode)arg1);
}

void GO_EXPORT(ResolvedBeginStmt_isolation_level_list)(void * arg0,void ** arg1){
  zetasql::ResolvedBeginStmt *node = (zetasql::ResolvedBeginStmt *)arg0;
  GET_STRS(node->isolation_level_list, arg1);
}

void GO_EXPORT(ResolvedBeginStmt_set_isolation_level_list)(void * arg0,void * arg1){
  zetasql::ResolvedBeginStmt *node = (zetasql::ResolvedBeginStmt *)arg0;
  SET_LIST(node->set_isolation_level_list, std::string, arg1);
}

void GO_EXPORT(ResolvedBeginStmt_add_isolation_level_list)(void * arg0,void * arg1){
  zetasql::ResolvedBeginStmt *node = (zetasql::ResolvedBeginStmt *)arg0;
  node->add_isolation_level_list((char *)arg1);
}

void GO_EXPORT(ResolvedSetTransactionStmt_read_write_mode)(void * arg0,int* arg1){
  zetasql::ResolvedSetTransactionStmt *node = (zetasql::ResolvedSetTransactionStmt *)arg0;
  *arg1 = node->read_write_mode();
}

void GO_EXPORT(ResolvedSetTransactionStmt_set_read_write_mode)(void * arg0,int arg1){
  zetasql::ResolvedSetTransactionStmt *node = (zetasql::ResolvedSetTransactionStmt *)arg0;
  node->set_read_write_mode((zetasql::ResolvedSetTransactionStmt::ReadWriteMode)arg1);
}

void GO_EXPORT(ResolvedSetTransactionStmt_isolation_level_list)(void * arg0,void ** arg1){
  zetasql::ResolvedSetTransactionStmt *node = (zetasql::ResolvedSetTransactionStmt *)arg0;
  GET_STRS(node->isolation_level_list, arg1);
}

void GO_EXPORT(ResolvedSetTransactionStmt_set_isolation_level_list)(void * arg0,void * arg1){
  zetasql::ResolvedSetTransactionStmt *node = (zetasql::ResolvedSetTransactionStmt *)arg0;
  SET_LIST(node->set_isolation_level_list, std::string, arg1);
}

void GO_EXPORT(ResolvedSetTransactionStmt_add_isolation_level_list)(void * arg0,void * arg1){
  zetasql::ResolvedSetTransactionStmt *node = (zetasql::ResolvedSetTransactionStmt *)arg0;
  node->add_isolation_level_list((char *)arg1);
}

void GO_EXPORT(ResolvedStartBatchStmt_batch_type)(void * arg0,void ** arg1){
  zetasql::ResolvedStartBatchStmt *node = (zetasql::ResolvedStartBatchStmt *)arg0;
  *arg1 = (void *)((new std::string(node->batch_type()))->c_str());
}

void GO_EXPORT(ResolvedStartBatchStmt_set_batch_type)(void * arg0,void * arg1){
  zetasql::ResolvedStartBatchStmt *node = (zetasql::ResolvedStartBatchStmt *)arg0;
  node->set_batch_type((char *)arg1);
}

void GO_EXPORT(ResolvedDropStmt_object_type)(void * arg0,void ** arg1){
  zetasql::ResolvedDropStmt *node = (zetasql::ResolvedDropStmt *)arg0;
  *arg1 = (void *)((new std::string(node->object_type()))->c_str());
}

void GO_EXPORT(ResolvedDropStmt_set_object_type)(void * arg0,void * arg1){
  zetasql::ResolvedDropStmt *node = (zetasql::ResolvedDropStmt *)arg0;
  node->set_object_type((char *)arg1);
}

void GO_EXPORT(ResolvedDropStmt_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedDropStmt *node = (zetasql::ResolvedDropStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropStmt_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedDropStmt *node = (zetasql::ResolvedDropStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedDropStmt *node = (zetasql::ResolvedDropStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDropStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropStmt *node = (zetasql::ResolvedDropStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDropStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropStmt *node = (zetasql::ResolvedDropStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedDropStmt_drop_mode)(void * arg0,int* arg1){
  zetasql::ResolvedDropStmt *node = (zetasql::ResolvedDropStmt *)arg0;
  *arg1 = node->drop_mode();
}

void GO_EXPORT(ResolvedDropStmt_set_drop_mode)(void * arg0,int arg1){
  zetasql::ResolvedDropStmt *node = (zetasql::ResolvedDropStmt *)arg0;
  node->set_drop_mode((zetasql::ResolvedDropStmt::DropMode)arg1);
}

void GO_EXPORT(ResolvedDropMaterializedViewStmt_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedDropMaterializedViewStmt *node = (zetasql::ResolvedDropMaterializedViewStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropMaterializedViewStmt_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedDropMaterializedViewStmt *node = (zetasql::ResolvedDropMaterializedViewStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropMaterializedViewStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedDropMaterializedViewStmt *node = (zetasql::ResolvedDropMaterializedViewStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDropMaterializedViewStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropMaterializedViewStmt *node = (zetasql::ResolvedDropMaterializedViewStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDropMaterializedViewStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropMaterializedViewStmt *node = (zetasql::ResolvedDropMaterializedViewStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedDropSnapshotTableStmt_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedDropSnapshotTableStmt *node = (zetasql::ResolvedDropSnapshotTableStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropSnapshotTableStmt_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedDropSnapshotTableStmt *node = (zetasql::ResolvedDropSnapshotTableStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropSnapshotTableStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedDropSnapshotTableStmt *node = (zetasql::ResolvedDropSnapshotTableStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDropSnapshotTableStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropSnapshotTableStmt *node = (zetasql::ResolvedDropSnapshotTableStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDropSnapshotTableStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropSnapshotTableStmt *node = (zetasql::ResolvedDropSnapshotTableStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedRecursiveScan_op_type)(void * arg0,int* arg1){
  zetasql::ResolvedRecursiveScan *node = (zetasql::ResolvedRecursiveScan *)arg0;
  *arg1 = node->op_type();
}

void GO_EXPORT(ResolvedRecursiveScan_set_op_type)(void * arg0,int arg1){
  zetasql::ResolvedRecursiveScan *node = (zetasql::ResolvedRecursiveScan *)arg0;
  node->set_op_type((zetasql::ResolvedRecursiveScan::RecursiveSetOperationType)arg1);
}

void GO_EXPORT(ResolvedRecursiveScan_non_recursive_term)(void * arg0,void ** arg1){
  zetasql::ResolvedRecursiveScan *node = (zetasql::ResolvedRecursiveScan *)arg0;
  *arg1 = (void *)node->non_recursive_term();
}

void GO_EXPORT(ResolvedRecursiveScan_set_non_recursive_term)(void * arg0,void * arg1){
  zetasql::ResolvedRecursiveScan *node = (zetasql::ResolvedRecursiveScan *)arg0;
  SET_UNIQUE_PTR(node->set_non_recursive_term, ResolvedSetOperationItem, arg1);
}

void GO_EXPORT(ResolvedRecursiveScan_recursive_term)(void * arg0,void ** arg1){
  zetasql::ResolvedRecursiveScan *node = (zetasql::ResolvedRecursiveScan *)arg0;
  *arg1 = (void *)node->recursive_term();
}

void GO_EXPORT(ResolvedRecursiveScan_set_recursive_term)(void * arg0,void * arg1){
  zetasql::ResolvedRecursiveScan *node = (zetasql::ResolvedRecursiveScan *)arg0;
  SET_UNIQUE_PTR(node->set_recursive_term, ResolvedSetOperationItem, arg1);
}

void GO_EXPORT(ResolvedWithScan_with_entry_list)(void * arg0,void ** arg1){
  zetasql::ResolvedWithScan *node = (zetasql::ResolvedWithScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->with_entry_list, arg1);
}

void GO_EXPORT(ResolvedWithScan_set_with_entry_list)(void * arg0,void * arg1){
  zetasql::ResolvedWithScan *node = (zetasql::ResolvedWithScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_with_entry_list, ResolvedWithEntry, arg1);
}

void GO_EXPORT(ResolvedWithScan_add_with_entry_list)(void * arg0,void * arg1){
  zetasql::ResolvedWithScan *node = (zetasql::ResolvedWithScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_with_entry_list, ResolvedWithEntry, arg1);
}

void GO_EXPORT(ResolvedWithScan_query)(void * arg0,void ** arg1){
  zetasql::ResolvedWithScan *node = (zetasql::ResolvedWithScan *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedWithScan_set_query)(void * arg0,void * arg1){
  zetasql::ResolvedWithScan *node = (zetasql::ResolvedWithScan *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedWithScan_recursive)(void * arg0,char* arg1){
  zetasql::ResolvedWithScan *node = (zetasql::ResolvedWithScan *)arg0;
  *arg1 = node->recursive();
}

void GO_EXPORT(ResolvedWithScan_set_recursive)(void * arg0,int arg1){
  zetasql::ResolvedWithScan *node = (zetasql::ResolvedWithScan *)arg0;
  node->set_recursive(arg1);
}

void GO_EXPORT(ResolvedWithEntry_with_query_name)(void * arg0,void ** arg1){
  zetasql::ResolvedWithEntry *node = (zetasql::ResolvedWithEntry *)arg0;
  *arg1 = (void *)((new std::string(node->with_query_name()))->c_str());
}

void GO_EXPORT(ResolvedWithEntry_set_with_query_name)(void * arg0,void * arg1){
  zetasql::ResolvedWithEntry *node = (zetasql::ResolvedWithEntry *)arg0;
  node->set_with_query_name((char *)arg1);
}

void GO_EXPORT(ResolvedWithEntry_with_subquery)(void * arg0,void ** arg1){
  zetasql::ResolvedWithEntry *node = (zetasql::ResolvedWithEntry *)arg0;
  *arg1 = (void *)node->with_subquery();
}

void GO_EXPORT(ResolvedWithEntry_set_with_subquery)(void * arg0,void * arg1){
  zetasql::ResolvedWithEntry *node = (zetasql::ResolvedWithEntry *)arg0;
  node->set_with_subquery(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedOption_qualifier)(void * arg0,void ** arg1){
  zetasql::ResolvedOption *node = (zetasql::ResolvedOption *)arg0;
  *arg1 = (void *)((new std::string(node->qualifier()))->c_str());
}

void GO_EXPORT(ResolvedOption_set_qualifier)(void * arg0,void * arg1){
  zetasql::ResolvedOption *node = (zetasql::ResolvedOption *)arg0;
  node->set_qualifier((char *)arg1);
}

void GO_EXPORT(ResolvedOption_name)(void * arg0,void ** arg1){
  zetasql::ResolvedOption *node = (zetasql::ResolvedOption *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedOption_set_name)(void * arg0,void * arg1){
  zetasql::ResolvedOption *node = (zetasql::ResolvedOption *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedOption_value)(void * arg0,void ** arg1){
  zetasql::ResolvedOption *node = (zetasql::ResolvedOption *)arg0;
  *arg1 = (void *)node->value();
}

void GO_EXPORT(ResolvedOption_set_value)(void * arg0,void * arg1){
  zetasql::ResolvedOption *node = (zetasql::ResolvedOption *)arg0;
  node->set_value(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedWindowPartitioning_partition_by_list)(void * arg0,void ** arg1){
  zetasql::ResolvedWindowPartitioning *node = (zetasql::ResolvedWindowPartitioning *)arg0;
  GET_UNIQUE_PTR_LIST(node->partition_by_list, arg1);
}

void GO_EXPORT(ResolvedWindowPartitioning_set_partition_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedWindowPartitioning *node = (zetasql::ResolvedWindowPartitioning *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_partition_by_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedWindowPartitioning_add_partition_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedWindowPartitioning *node = (zetasql::ResolvedWindowPartitioning *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_partition_by_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedWindowPartitioning_hint_list)(void * arg0,void ** arg1){
  zetasql::ResolvedWindowPartitioning *node = (zetasql::ResolvedWindowPartitioning *)arg0;
  GET_UNIQUE_PTR_LIST(node->hint_list, arg1);
}

void GO_EXPORT(ResolvedWindowPartitioning_set_hint_list)(void * arg0,void * arg1){
  zetasql::ResolvedWindowPartitioning *node = (zetasql::ResolvedWindowPartitioning *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedWindowPartitioning_add_hint_list)(void * arg0,void * arg1){
  zetasql::ResolvedWindowPartitioning *node = (zetasql::ResolvedWindowPartitioning *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedWindowOrdering_order_by_item_list)(void * arg0,void ** arg1){
  zetasql::ResolvedWindowOrdering *node = (zetasql::ResolvedWindowOrdering *)arg0;
  GET_UNIQUE_PTR_LIST(node->order_by_item_list, arg1);
}

void GO_EXPORT(ResolvedWindowOrdering_set_order_by_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedWindowOrdering *node = (zetasql::ResolvedWindowOrdering *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_order_by_item_list, ResolvedOrderByItem, arg1);
}

void GO_EXPORT(ResolvedWindowOrdering_add_order_by_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedWindowOrdering *node = (zetasql::ResolvedWindowOrdering *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_order_by_item_list, ResolvedOrderByItem, arg1);
}

void GO_EXPORT(ResolvedWindowOrdering_hint_list)(void * arg0,void ** arg1){
  zetasql::ResolvedWindowOrdering *node = (zetasql::ResolvedWindowOrdering *)arg0;
  GET_UNIQUE_PTR_LIST(node->hint_list, arg1);
}

void GO_EXPORT(ResolvedWindowOrdering_set_hint_list)(void * arg0,void * arg1){
  zetasql::ResolvedWindowOrdering *node = (zetasql::ResolvedWindowOrdering *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedWindowOrdering_add_hint_list)(void * arg0,void * arg1){
  zetasql::ResolvedWindowOrdering *node = (zetasql::ResolvedWindowOrdering *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedWindowFrame_frame_unit)(void * arg0,int* arg1){
  zetasql::ResolvedWindowFrame *node = (zetasql::ResolvedWindowFrame *)arg0;
  *arg1 = node->frame_unit();
}

void GO_EXPORT(ResolvedWindowFrame_set_frame_unit)(void * arg0,int arg1){
  zetasql::ResolvedWindowFrame *node = (zetasql::ResolvedWindowFrame *)arg0;
  node->set_frame_unit((zetasql::ResolvedWindowFrame::FrameUnit)arg1);
}

void GO_EXPORT(ResolvedWindowFrame_start_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedWindowFrame *node = (zetasql::ResolvedWindowFrame *)arg0;
  *arg1 = (void *)node->start_expr();
}

void GO_EXPORT(ResolvedWindowFrame_set_start_expr)(void * arg0,void * arg1){
  zetasql::ResolvedWindowFrame *node = (zetasql::ResolvedWindowFrame *)arg0;
  SET_UNIQUE_PTR(node->set_start_expr, ResolvedWindowFrameExpr, arg1);
}

void GO_EXPORT(ResolvedWindowFrame_end_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedWindowFrame *node = (zetasql::ResolvedWindowFrame *)arg0;
  *arg1 = (void *)node->end_expr();
}

void GO_EXPORT(ResolvedWindowFrame_set_end_expr)(void * arg0,void * arg1){
  zetasql::ResolvedWindowFrame *node = (zetasql::ResolvedWindowFrame *)arg0;
  SET_UNIQUE_PTR(node->set_end_expr, ResolvedWindowFrameExpr, arg1);
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_partition_by)(void * arg0,void ** arg1){
  zetasql::ResolvedAnalyticFunctionGroup *node = (zetasql::ResolvedAnalyticFunctionGroup *)arg0;
  *arg1 = (void *)node->partition_by();
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_set_partition_by)(void * arg0,void * arg1){
  zetasql::ResolvedAnalyticFunctionGroup *node = (zetasql::ResolvedAnalyticFunctionGroup *)arg0;
  SET_UNIQUE_PTR(node->set_partition_by, ResolvedWindowPartitioning, arg1);
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_order_by)(void * arg0,void ** arg1){
  zetasql::ResolvedAnalyticFunctionGroup *node = (zetasql::ResolvedAnalyticFunctionGroup *)arg0;
  *arg1 = (void *)node->order_by();
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_set_order_by)(void * arg0,void * arg1){
  zetasql::ResolvedAnalyticFunctionGroup *node = (zetasql::ResolvedAnalyticFunctionGroup *)arg0;
  SET_UNIQUE_PTR(node->set_order_by, ResolvedWindowOrdering, arg1);
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_analytic_function_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAnalyticFunctionGroup *node = (zetasql::ResolvedAnalyticFunctionGroup *)arg0;
  GET_UNIQUE_PTR_LIST(node->analytic_function_list, arg1);
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_set_analytic_function_list)(void * arg0,void * arg1){
  zetasql::ResolvedAnalyticFunctionGroup *node = (zetasql::ResolvedAnalyticFunctionGroup *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_analytic_function_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_add_analytic_function_list)(void * arg0,void * arg1){
  zetasql::ResolvedAnalyticFunctionGroup *node = (zetasql::ResolvedAnalyticFunctionGroup *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_analytic_function_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedWindowFrameExpr_boundary_type)(void * arg0,int* arg1){
  zetasql::ResolvedWindowFrameExpr *node = (zetasql::ResolvedWindowFrameExpr *)arg0;
  *arg1 = node->boundary_type();
}

void GO_EXPORT(ResolvedWindowFrameExpr_set_boundary_type)(void * arg0,int arg1){
  zetasql::ResolvedWindowFrameExpr *node = (zetasql::ResolvedWindowFrameExpr *)arg0;
  node->set_boundary_type((zetasql::ResolvedWindowFrameExpr::BoundaryType)arg1);
}

void GO_EXPORT(ResolvedWindowFrameExpr_expression)(void * arg0,void ** arg1){
  zetasql::ResolvedWindowFrameExpr *node = (zetasql::ResolvedWindowFrameExpr *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ResolvedWindowFrameExpr_set_expression)(void * arg0,void * arg1){
  zetasql::ResolvedWindowFrameExpr *node = (zetasql::ResolvedWindowFrameExpr *)arg0;
  node->set_expression(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedDMLValue_value)(void * arg0,void ** arg1){
  zetasql::ResolvedDMLValue *node = (zetasql::ResolvedDMLValue *)arg0;
  *arg1 = (void *)node->value();
}

void GO_EXPORT(ResolvedDMLValue_set_value)(void * arg0,void * arg1){
  zetasql::ResolvedDMLValue *node = (zetasql::ResolvedDMLValue *)arg0;
  node->set_value(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedAssertStmt_expression)(void * arg0,void ** arg1){
  zetasql::ResolvedAssertStmt *node = (zetasql::ResolvedAssertStmt *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ResolvedAssertStmt_set_expression)(void * arg0,void * arg1){
  zetasql::ResolvedAssertStmt *node = (zetasql::ResolvedAssertStmt *)arg0;
  node->set_expression(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedAssertStmt_description)(void * arg0,void ** arg1){
  zetasql::ResolvedAssertStmt *node = (zetasql::ResolvedAssertStmt *)arg0;
  *arg1 = (void *)((new std::string(node->description()))->c_str());
}

void GO_EXPORT(ResolvedAssertStmt_set_description)(void * arg0,void * arg1){
  zetasql::ResolvedAssertStmt *node = (zetasql::ResolvedAssertStmt *)arg0;
  node->set_description((char *)arg1);
}

void GO_EXPORT(ResolvedAssertRowsModified_rows)(void * arg0,void ** arg1){
  zetasql::ResolvedAssertRowsModified *node = (zetasql::ResolvedAssertRowsModified *)arg0;
  *arg1 = (void *)node->rows();
}

void GO_EXPORT(ResolvedAssertRowsModified_set_rows)(void * arg0,void * arg1){
  zetasql::ResolvedAssertRowsModified *node = (zetasql::ResolvedAssertRowsModified *)arg0;
  node->set_rows(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedInsertRow_value_list)(void * arg0,void ** arg1){
  zetasql::ResolvedInsertRow *node = (zetasql::ResolvedInsertRow *)arg0;
  GET_UNIQUE_PTR_LIST(node->value_list, arg1);
}

void GO_EXPORT(ResolvedInsertRow_set_value_list)(void * arg0,void * arg1){
  zetasql::ResolvedInsertRow *node = (zetasql::ResolvedInsertRow *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_value_list, ResolvedDMLValue, arg1);
}

void GO_EXPORT(ResolvedInsertRow_add_value_list)(void * arg0,void * arg1){
  zetasql::ResolvedInsertRow *node = (zetasql::ResolvedInsertRow *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_value_list, ResolvedDMLValue, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_table_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedInsertStmt_set_table_scan)(void * arg0,void * arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_insert_mode)(void * arg0,int* arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  *arg1 = node->insert_mode();
}

void GO_EXPORT(ResolvedInsertStmt_set_insert_mode)(void * arg0,int arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  node->set_insert_mode((zetasql::ResolvedInsertStmt::InsertMode)arg1);
}

void GO_EXPORT(ResolvedInsertStmt_assert_rows_modified)(void * arg0,void ** arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  *arg1 = (void *)node->assert_rows_modified();
}

void GO_EXPORT(ResolvedInsertStmt_set_assert_rows_modified)(void * arg0,void * arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  SET_UNIQUE_PTR(node->set_assert_rows_modified, ResolvedAssertRowsModified, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_returning)(void * arg0,void ** arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  *arg1 = (void *)node->returning();
}

void GO_EXPORT(ResolvedInsertStmt_set_returning)(void * arg0,void * arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  SET_UNIQUE_PTR(node->set_returning, ResolvedReturningClause, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_insert_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  GET_LIST(node->insert_column_list, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_set_insert_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  SET_LIST(node->set_insert_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_add_insert_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  ADD_LIST(node->add_insert_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_query_parameter_list)(void * arg0,void ** arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->query_parameter_list, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_set_query_parameter_list)(void * arg0,void * arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_query_parameter_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_add_query_parameter_list)(void * arg0,void * arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_query_parameter_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_query)(void * arg0,void ** arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedInsertStmt_set_query)(void * arg0,void * arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedInsertStmt_query_output_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  GET_LIST(node->query_output_column_list, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_set_query_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  SET_LIST(node->set_query_output_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_add_query_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  ADD_LIST(node->add_query_output_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_row_list)(void * arg0,void ** arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->row_list, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_set_row_list)(void * arg0,void * arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_row_list, ResolvedInsertRow, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_add_row_list)(void * arg0,void * arg1){
  zetasql::ResolvedInsertStmt *node = (zetasql::ResolvedInsertStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_row_list, ResolvedInsertRow, arg1);
}

void GO_EXPORT(ResolvedDeleteStmt_table_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedDeleteStmt *node = (zetasql::ResolvedDeleteStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedDeleteStmt_set_table_scan)(void * arg0,void * arg1){
  zetasql::ResolvedDeleteStmt *node = (zetasql::ResolvedDeleteStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedDeleteStmt_assert_rows_modified)(void * arg0,void ** arg1){
  zetasql::ResolvedDeleteStmt *node = (zetasql::ResolvedDeleteStmt *)arg0;
  *arg1 = (void *)node->assert_rows_modified();
}

void GO_EXPORT(ResolvedDeleteStmt_set_assert_rows_modified)(void * arg0,void * arg1){
  zetasql::ResolvedDeleteStmt *node = (zetasql::ResolvedDeleteStmt *)arg0;
  SET_UNIQUE_PTR(node->set_assert_rows_modified, ResolvedAssertRowsModified, arg1);
}

void GO_EXPORT(ResolvedDeleteStmt_returning)(void * arg0,void ** arg1){
  zetasql::ResolvedDeleteStmt *node = (zetasql::ResolvedDeleteStmt *)arg0;
  *arg1 = (void *)node->returning();
}

void GO_EXPORT(ResolvedDeleteStmt_set_returning)(void * arg0,void * arg1){
  zetasql::ResolvedDeleteStmt *node = (zetasql::ResolvedDeleteStmt *)arg0;
  SET_UNIQUE_PTR(node->set_returning, ResolvedReturningClause, arg1);
}

void GO_EXPORT(ResolvedDeleteStmt_array_offset_column)(void * arg0,void ** arg1){
  zetasql::ResolvedDeleteStmt *node = (zetasql::ResolvedDeleteStmt *)arg0;
  *arg1 = (void *)node->array_offset_column();
}

void GO_EXPORT(ResolvedDeleteStmt_set_array_offset_column)(void * arg0,void * arg1){
  zetasql::ResolvedDeleteStmt *node = (zetasql::ResolvedDeleteStmt *)arg0;
  SET_UNIQUE_PTR(node->set_array_offset_column, ResolvedColumnHolder, arg1);
}

void GO_EXPORT(ResolvedDeleteStmt_where_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedDeleteStmt *node = (zetasql::ResolvedDeleteStmt *)arg0;
  *arg1 = (void *)node->where_expr();
}

void GO_EXPORT(ResolvedDeleteStmt_set_where_expr)(void * arg0,void * arg1){
  zetasql::ResolvedDeleteStmt *node = (zetasql::ResolvedDeleteStmt *)arg0;
  node->set_where_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedUpdateItem_target)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  *arg1 = (void *)node->target();
}

void GO_EXPORT(ResolvedUpdateItem_set_target)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  node->set_target(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedUpdateItem_set_value)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  *arg1 = (void *)node->set_value();
}

void GO_EXPORT(ResolvedUpdateItem_set_set_value)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  SET_UNIQUE_PTR(node->set_set_value, ResolvedDMLValue, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_element_column)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  *arg1 = (void *)node->element_column();
}

void GO_EXPORT(ResolvedUpdateItem_set_element_column)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  SET_UNIQUE_PTR(node->set_element_column, ResolvedColumnHolder, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_array_update_list)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  GET_UNIQUE_PTR_LIST(node->array_update_list, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_set_array_update_list)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_array_update_list, ResolvedUpdateArrayItem, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_add_array_update_list)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_array_update_list, ResolvedUpdateArrayItem, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_delete_list)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  GET_UNIQUE_PTR_LIST(node->delete_list, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_set_delete_list)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_delete_list, ResolvedDeleteStmt, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_add_delete_list)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_delete_list, ResolvedDeleteStmt, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_update_list)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  GET_UNIQUE_PTR_LIST(node->update_list, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_set_update_list)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_update_list, ResolvedUpdateStmt, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_add_update_list)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_update_list, ResolvedUpdateStmt, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_insert_list)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  GET_UNIQUE_PTR_LIST(node->insert_list, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_set_insert_list)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_insert_list, ResolvedInsertStmt, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_add_insert_list)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateItem *node = (zetasql::ResolvedUpdateItem *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_insert_list, ResolvedInsertStmt, arg1);
}

void GO_EXPORT(ResolvedUpdateArrayItem_offset)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateArrayItem *node = (zetasql::ResolvedUpdateArrayItem *)arg0;
  *arg1 = (void *)node->offset();
}

void GO_EXPORT(ResolvedUpdateArrayItem_set_offset)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateArrayItem *node = (zetasql::ResolvedUpdateArrayItem *)arg0;
  node->set_offset(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedUpdateArrayItem_update_item)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateArrayItem *node = (zetasql::ResolvedUpdateArrayItem *)arg0;
  *arg1 = (void *)node->update_item();
}

void GO_EXPORT(ResolvedUpdateArrayItem_set_update_item)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateArrayItem *node = (zetasql::ResolvedUpdateArrayItem *)arg0;
  SET_UNIQUE_PTR(node->set_update_item, ResolvedUpdateItem, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_table_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedUpdateStmt_set_table_scan)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_column_access_list)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  GET_ENUMS(node->column_access_list, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_set_column_access_list)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  SET_ENUMS(node->set_column_access_list, zetasql::ResolvedUpdateStmt::ObjectAccess, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_add_column_access_list)(void * arg0,int arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  node->add_column_access_list((zetasql::ResolvedUpdateStmt::ObjectAccess)arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_assert_rows_modified)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  *arg1 = (void *)node->assert_rows_modified();
}

void GO_EXPORT(ResolvedUpdateStmt_set_assert_rows_modified)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  SET_UNIQUE_PTR(node->set_assert_rows_modified, ResolvedAssertRowsModified, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_returning)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  *arg1 = (void *)node->returning();
}

void GO_EXPORT(ResolvedUpdateStmt_set_returning)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  SET_UNIQUE_PTR(node->set_returning, ResolvedReturningClause, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_array_offset_column)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  *arg1 = (void *)node->array_offset_column();
}

void GO_EXPORT(ResolvedUpdateStmt_set_array_offset_column)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  SET_UNIQUE_PTR(node->set_array_offset_column, ResolvedColumnHolder, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_where_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  *arg1 = (void *)node->where_expr();
}

void GO_EXPORT(ResolvedUpdateStmt_set_where_expr)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  node->set_where_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedUpdateStmt_update_item_list)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->update_item_list, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_set_update_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_update_item_list, ResolvedUpdateItem, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_add_update_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_update_item_list, ResolvedUpdateItem, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_from_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  *arg1 = (void *)node->from_scan();
}

void GO_EXPORT(ResolvedUpdateStmt_set_from_scan)(void * arg0,void * arg1){
  zetasql::ResolvedUpdateStmt *node = (zetasql::ResolvedUpdateStmt *)arg0;
  node->set_from_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedMergeWhen_match_type)(void * arg0,int* arg1){
  zetasql::ResolvedMergeWhen *node = (zetasql::ResolvedMergeWhen *)arg0;
  *arg1 = node->match_type();
}

void GO_EXPORT(ResolvedMergeWhen_set_match_type)(void * arg0,int arg1){
  zetasql::ResolvedMergeWhen *node = (zetasql::ResolvedMergeWhen *)arg0;
  node->set_match_type((zetasql::ResolvedMergeWhen::MatchType)arg1);
}

void GO_EXPORT(ResolvedMergeWhen_match_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedMergeWhen *node = (zetasql::ResolvedMergeWhen *)arg0;
  *arg1 = (void *)node->match_expr();
}

void GO_EXPORT(ResolvedMergeWhen_set_match_expr)(void * arg0,void * arg1){
  zetasql::ResolvedMergeWhen *node = (zetasql::ResolvedMergeWhen *)arg0;
  node->set_match_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedMergeWhen_action_type)(void * arg0,int* arg1){
  zetasql::ResolvedMergeWhen *node = (zetasql::ResolvedMergeWhen *)arg0;
  *arg1 = node->action_type();
}

void GO_EXPORT(ResolvedMergeWhen_set_action_type)(void * arg0,int arg1){
  zetasql::ResolvedMergeWhen *node = (zetasql::ResolvedMergeWhen *)arg0;
  node->set_action_type((zetasql::ResolvedMergeWhen::ActionType)arg1);
}

void GO_EXPORT(ResolvedMergeWhen_insert_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedMergeWhen *node = (zetasql::ResolvedMergeWhen *)arg0;
  GET_LIST(node->insert_column_list, arg1);
}

void GO_EXPORT(ResolvedMergeWhen_set_insert_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedMergeWhen *node = (zetasql::ResolvedMergeWhen *)arg0;
  SET_LIST(node->set_insert_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedMergeWhen_add_insert_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedMergeWhen *node = (zetasql::ResolvedMergeWhen *)arg0;
  ADD_LIST(node->add_insert_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedMergeWhen_insert_row)(void * arg0,void ** arg1){
  zetasql::ResolvedMergeWhen *node = (zetasql::ResolvedMergeWhen *)arg0;
  *arg1 = (void *)node->insert_row();
}

void GO_EXPORT(ResolvedMergeWhen_set_insert_row)(void * arg0,void * arg1){
  zetasql::ResolvedMergeWhen *node = (zetasql::ResolvedMergeWhen *)arg0;
  SET_UNIQUE_PTR(node->set_insert_row, ResolvedInsertRow, arg1);
}

void GO_EXPORT(ResolvedMergeWhen_update_item_list)(void * arg0,void ** arg1){
  zetasql::ResolvedMergeWhen *node = (zetasql::ResolvedMergeWhen *)arg0;
  GET_UNIQUE_PTR_LIST(node->update_item_list, arg1);
}

void GO_EXPORT(ResolvedMergeWhen_set_update_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedMergeWhen *node = (zetasql::ResolvedMergeWhen *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_update_item_list, ResolvedUpdateItem, arg1);
}

void GO_EXPORT(ResolvedMergeWhen_add_update_item_list)(void * arg0,void * arg1){
  zetasql::ResolvedMergeWhen *node = (zetasql::ResolvedMergeWhen *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_update_item_list, ResolvedUpdateItem, arg1);
}

void GO_EXPORT(ResolvedMergeStmt_table_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedMergeStmt *node = (zetasql::ResolvedMergeStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedMergeStmt_set_table_scan)(void * arg0,void * arg1){
  zetasql::ResolvedMergeStmt *node = (zetasql::ResolvedMergeStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedMergeStmt_column_access_list)(void * arg0,void ** arg1){
  zetasql::ResolvedMergeStmt *node = (zetasql::ResolvedMergeStmt *)arg0;
  GET_ENUMS(node->column_access_list, arg1);
}

void GO_EXPORT(ResolvedMergeStmt_set_column_access_list)(void * arg0,void * arg1){
  zetasql::ResolvedMergeStmt *node = (zetasql::ResolvedMergeStmt *)arg0;
  SET_ENUMS(node->set_column_access_list, zetasql::ResolvedMergeStmt::ObjectAccess, arg1);
}

void GO_EXPORT(ResolvedMergeStmt_add_column_access_list)(void * arg0,int arg1){
  zetasql::ResolvedMergeStmt *node = (zetasql::ResolvedMergeStmt *)arg0;
  node->add_column_access_list((zetasql::ResolvedMergeStmt::ObjectAccess)arg1);
}

void GO_EXPORT(ResolvedMergeStmt_from_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedMergeStmt *node = (zetasql::ResolvedMergeStmt *)arg0;
  *arg1 = (void *)node->from_scan();
}

void GO_EXPORT(ResolvedMergeStmt_set_from_scan)(void * arg0,void * arg1){
  zetasql::ResolvedMergeStmt *node = (zetasql::ResolvedMergeStmt *)arg0;
  node->set_from_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedMergeStmt_merge_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedMergeStmt *node = (zetasql::ResolvedMergeStmt *)arg0;
  *arg1 = (void *)node->merge_expr();
}

void GO_EXPORT(ResolvedMergeStmt_set_merge_expr)(void * arg0,void * arg1){
  zetasql::ResolvedMergeStmt *node = (zetasql::ResolvedMergeStmt *)arg0;
  node->set_merge_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedMergeStmt_when_clause_list)(void * arg0,void ** arg1){
  zetasql::ResolvedMergeStmt *node = (zetasql::ResolvedMergeStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->when_clause_list, arg1);
}

void GO_EXPORT(ResolvedMergeStmt_set_when_clause_list)(void * arg0,void * arg1){
  zetasql::ResolvedMergeStmt *node = (zetasql::ResolvedMergeStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_when_clause_list, ResolvedMergeWhen, arg1);
}

void GO_EXPORT(ResolvedMergeStmt_add_when_clause_list)(void * arg0,void * arg1){
  zetasql::ResolvedMergeStmt *node = (zetasql::ResolvedMergeStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_when_clause_list, ResolvedMergeWhen, arg1);
}

void GO_EXPORT(ResolvedTruncateStmt_table_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedTruncateStmt *node = (zetasql::ResolvedTruncateStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedTruncateStmt_set_table_scan)(void * arg0,void * arg1){
  zetasql::ResolvedTruncateStmt *node = (zetasql::ResolvedTruncateStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedTruncateStmt_where_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedTruncateStmt *node = (zetasql::ResolvedTruncateStmt *)arg0;
  *arg1 = (void *)node->where_expr();
}

void GO_EXPORT(ResolvedTruncateStmt_set_where_expr)(void * arg0,void * arg1){
  zetasql::ResolvedTruncateStmt *node = (zetasql::ResolvedTruncateStmt *)arg0;
  node->set_where_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedObjectUnit_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedObjectUnit *node = (zetasql::ResolvedObjectUnit *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedObjectUnit_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedObjectUnit *node = (zetasql::ResolvedObjectUnit *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedObjectUnit_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedObjectUnit *node = (zetasql::ResolvedObjectUnit *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedPrivilege_action_type)(void * arg0,void ** arg1){
  zetasql::ResolvedPrivilege *node = (zetasql::ResolvedPrivilege *)arg0;
  *arg1 = (void *)((new std::string(node->action_type()))->c_str());
}

void GO_EXPORT(ResolvedPrivilege_set_action_type)(void * arg0,void * arg1){
  zetasql::ResolvedPrivilege *node = (zetasql::ResolvedPrivilege *)arg0;
  node->set_action_type((char *)arg1);
}

void GO_EXPORT(ResolvedPrivilege_unit_list)(void * arg0,void ** arg1){
  zetasql::ResolvedPrivilege *node = (zetasql::ResolvedPrivilege *)arg0;
  GET_UNIQUE_PTR_LIST(node->unit_list, arg1);
}

void GO_EXPORT(ResolvedPrivilege_set_unit_list)(void * arg0,void * arg1){
  zetasql::ResolvedPrivilege *node = (zetasql::ResolvedPrivilege *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_unit_list, ResolvedObjectUnit, arg1);
}

void GO_EXPORT(ResolvedPrivilege_add_unit_list)(void * arg0,void * arg1){
  zetasql::ResolvedPrivilege *node = (zetasql::ResolvedPrivilege *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_unit_list, ResolvedObjectUnit, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_privilege_list)(void * arg0,void ** arg1){
  zetasql::ResolvedGrantOrRevokeStmt *node = (zetasql::ResolvedGrantOrRevokeStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->privilege_list, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_set_privilege_list)(void * arg0,void * arg1){
  zetasql::ResolvedGrantOrRevokeStmt *node = (zetasql::ResolvedGrantOrRevokeStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_add_privilege_list)(void * arg0,void * arg1){
  zetasql::ResolvedGrantOrRevokeStmt *node = (zetasql::ResolvedGrantOrRevokeStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_object_type)(void * arg0,void ** arg1){
  zetasql::ResolvedGrantOrRevokeStmt *node = (zetasql::ResolvedGrantOrRevokeStmt *)arg0;
  *arg1 = (void *)((new std::string(node->object_type()))->c_str());
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_set_object_type)(void * arg0,void * arg1){
  zetasql::ResolvedGrantOrRevokeStmt *node = (zetasql::ResolvedGrantOrRevokeStmt *)arg0;
  node->set_object_type((char *)arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedGrantOrRevokeStmt *node = (zetasql::ResolvedGrantOrRevokeStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedGrantOrRevokeStmt *node = (zetasql::ResolvedGrantOrRevokeStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedGrantOrRevokeStmt *node = (zetasql::ResolvedGrantOrRevokeStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_grantee_list)(void * arg0,void ** arg1){
  zetasql::ResolvedGrantOrRevokeStmt *node = (zetasql::ResolvedGrantOrRevokeStmt *)arg0;
  GET_STRS(node->grantee_list, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_set_grantee_list)(void * arg0,void * arg1){
  zetasql::ResolvedGrantOrRevokeStmt *node = (zetasql::ResolvedGrantOrRevokeStmt *)arg0;
  SET_LIST(node->set_grantee_list, std::string, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_add_grantee_list)(void * arg0,void * arg1){
  zetasql::ResolvedGrantOrRevokeStmt *node = (zetasql::ResolvedGrantOrRevokeStmt *)arg0;
  node->add_grantee_list((char *)arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_grantee_expr_list)(void * arg0,void ** arg1){
  zetasql::ResolvedGrantOrRevokeStmt *node = (zetasql::ResolvedGrantOrRevokeStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_set_grantee_expr_list)(void * arg0,void * arg1){
  zetasql::ResolvedGrantOrRevokeStmt *node = (zetasql::ResolvedGrantOrRevokeStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_add_grantee_expr_list)(void * arg0,void * arg1){
  zetasql::ResolvedGrantOrRevokeStmt *node = (zetasql::ResolvedGrantOrRevokeStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedAlterObjectStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterObjectStmt *node = (zetasql::ResolvedAlterObjectStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedAlterObjectStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedAlterObjectStmt *node = (zetasql::ResolvedAlterObjectStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedAlterObjectStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedAlterObjectStmt *node = (zetasql::ResolvedAlterObjectStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedAlterObjectStmt_alter_action_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterObjectStmt *node = (zetasql::ResolvedAlterObjectStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->alter_action_list, arg1);
}

void GO_EXPORT(ResolvedAlterObjectStmt_set_alter_action_list)(void * arg0,void * arg1){
  zetasql::ResolvedAlterObjectStmt *node = (zetasql::ResolvedAlterObjectStmt *)arg0;
  SET_UNIQUE_PTR_ACTION_LIST(node->set_alter_action_list, arg1);
}

void GO_EXPORT(ResolvedAlterObjectStmt_add_alter_action_list)(void * arg0,void * arg1){
  zetasql::ResolvedAlterObjectStmt *node = (zetasql::ResolvedAlterObjectStmt *)arg0;
  ADD_UNIQUE_PTR_ACTION_LIST(node->add_alter_action_list, arg1);
}

void GO_EXPORT(ResolvedAlterObjectStmt_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedAlterObjectStmt *node = (zetasql::ResolvedAlterObjectStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedAlterObjectStmt_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedAlterObjectStmt *node = (zetasql::ResolvedAlterObjectStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedAlterColumnAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedAlterColumnAction *node = (zetasql::ResolvedAlterColumnAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedAlterColumnAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedAlterColumnAction *node = (zetasql::ResolvedAlterColumnAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedAlterColumnAction_column)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterColumnAction *node = (zetasql::ResolvedAlterColumnAction *)arg0;
  *arg1 = (void *)((new std::string(node->column()))->c_str());
}

void GO_EXPORT(ResolvedAlterColumnAction_set_column)(void * arg0,void * arg1){
  zetasql::ResolvedAlterColumnAction *node = (zetasql::ResolvedAlterColumnAction *)arg0;
  node->set_column((char *)arg1);
}

void GO_EXPORT(ResolvedSetOptionsAction_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedSetOptionsAction *node = (zetasql::ResolvedSetOptionsAction *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedSetOptionsAction_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedSetOptionsAction *node = (zetasql::ResolvedSetOptionsAction *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedSetOptionsAction_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedSetOptionsAction *node = (zetasql::ResolvedSetOptionsAction *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAddColumnAction_is_if_not_exists)(void * arg0,char* arg1){
  zetasql::ResolvedAddColumnAction *node = (zetasql::ResolvedAddColumnAction *)arg0;
  *arg1 = node->is_if_not_exists();
}

void GO_EXPORT(ResolvedAddColumnAction_set_is_if_not_exists)(void * arg0,int arg1){
  zetasql::ResolvedAddColumnAction *node = (zetasql::ResolvedAddColumnAction *)arg0;
  node->set_is_if_not_exists(arg1);
}

void GO_EXPORT(ResolvedAddColumnAction_column_definition)(void * arg0,void ** arg1){
  zetasql::ResolvedAddColumnAction *node = (zetasql::ResolvedAddColumnAction *)arg0;
  *arg1 = (void *)node->column_definition();
}

void GO_EXPORT(ResolvedAddColumnAction_set_column_definition)(void * arg0,void * arg1){
  zetasql::ResolvedAddColumnAction *node = (zetasql::ResolvedAddColumnAction *)arg0;
  SET_UNIQUE_PTR(node->set_column_definition, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedAddConstraintAction_is_if_not_exists)(void * arg0,char* arg1){
  zetasql::ResolvedAddConstraintAction *node = (zetasql::ResolvedAddConstraintAction *)arg0;
  *arg1 = node->is_if_not_exists();
}

void GO_EXPORT(ResolvedAddConstraintAction_set_is_if_not_exists)(void * arg0,int arg1){
  zetasql::ResolvedAddConstraintAction *node = (zetasql::ResolvedAddConstraintAction *)arg0;
  node->set_is_if_not_exists(arg1);
}

void GO_EXPORT(ResolvedAddConstraintAction_constraint)(void * arg0,void ** arg1){
  zetasql::ResolvedAddConstraintAction *node = (zetasql::ResolvedAddConstraintAction *)arg0;
  *arg1 = (void *)node->constraint();
}

void GO_EXPORT(ResolvedAddConstraintAction_set_constraint)(void * arg0,void * arg1){
  zetasql::ResolvedAddConstraintAction *node = (zetasql::ResolvedAddConstraintAction *)arg0;
  node->set_constraint(make_unique_constraint(arg1));
}

void GO_EXPORT(ResolvedAddConstraintAction_table)(void * arg0,void ** arg1){
  zetasql::ResolvedAddConstraintAction *node = (zetasql::ResolvedAddConstraintAction *)arg0;
  *arg1 = (void *)node->table();
}

void GO_EXPORT(ResolvedAddConstraintAction_set_table)(void * arg0,void * arg1){
  zetasql::ResolvedAddConstraintAction *node = (zetasql::ResolvedAddConstraintAction *)arg0;
  node->set_table((const zetasql::Table *)arg1);
}

void GO_EXPORT(ResolvedDropConstraintAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedDropConstraintAction *node = (zetasql::ResolvedDropConstraintAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropConstraintAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedDropConstraintAction *node = (zetasql::ResolvedDropConstraintAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropConstraintAction_name)(void * arg0,void ** arg1){
  zetasql::ResolvedDropConstraintAction *node = (zetasql::ResolvedDropConstraintAction *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedDropConstraintAction_set_name)(void * arg0,void * arg1){
  zetasql::ResolvedDropConstraintAction *node = (zetasql::ResolvedDropConstraintAction *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedDropPrimaryKeyAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedDropPrimaryKeyAction *node = (zetasql::ResolvedDropPrimaryKeyAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropPrimaryKeyAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedDropPrimaryKeyAction *node = (zetasql::ResolvedDropPrimaryKeyAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedAlterColumnOptionsAction_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterColumnOptionsAction *node = (zetasql::ResolvedAlterColumnOptionsAction *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedAlterColumnOptionsAction_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedAlterColumnOptionsAction *node = (zetasql::ResolvedAlterColumnOptionsAction *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAlterColumnOptionsAction_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedAlterColumnOptionsAction *node = (zetasql::ResolvedAlterColumnOptionsAction *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_updated_type)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterColumnSetDataTypeAction *node = (zetasql::ResolvedAlterColumnSetDataTypeAction *)arg0;
  *arg1 = (void *)node->updated_type();
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_set_updated_type)(void * arg0,void * arg1){
  zetasql::ResolvedAlterColumnSetDataTypeAction *node = (zetasql::ResolvedAlterColumnSetDataTypeAction *)arg0;
  node->set_updated_type((const zetasql::Type *)arg1);
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_updated_type_parameters)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterColumnSetDataTypeAction *node = (zetasql::ResolvedAlterColumnSetDataTypeAction *)arg0;
  *arg1 = (void *)(new zetasql::TypeParameters(node->updated_type_parameters()));
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters)(void * arg0,void * arg1){
  zetasql::ResolvedAlterColumnSetDataTypeAction *node = (zetasql::ResolvedAlterColumnSetDataTypeAction *)arg0;
  node->set_updated_type_parameters(*(zetasql::TypeParameters *)arg1);
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_updated_annotations)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterColumnSetDataTypeAction *node = (zetasql::ResolvedAlterColumnSetDataTypeAction *)arg0;
  *arg1 = (void *)node->updated_annotations();
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_set_updated_annotations)(void * arg0,void * arg1){
  zetasql::ResolvedAlterColumnSetDataTypeAction *node = (zetasql::ResolvedAlterColumnSetDataTypeAction *)arg0;
  SET_UNIQUE_PTR(node->set_updated_annotations, ResolvedColumnAnnotations, arg1);
}

void GO_EXPORT(ResolvedAlterColumnSetDefaultAction_default_value)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterColumnSetDefaultAction *node = (zetasql::ResolvedAlterColumnSetDefaultAction *)arg0;
  *arg1 = (void *)node->default_value();
}

void GO_EXPORT(ResolvedAlterColumnSetDefaultAction_set_default_value)(void * arg0,void * arg1){
  zetasql::ResolvedAlterColumnSetDefaultAction *node = (zetasql::ResolvedAlterColumnSetDefaultAction *)arg0;
  SET_UNIQUE_PTR(node->set_default_value, ResolvedColumnDefaultValue, arg1);
}

void GO_EXPORT(ResolvedDropColumnAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedDropColumnAction *node = (zetasql::ResolvedDropColumnAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropColumnAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedDropColumnAction *node = (zetasql::ResolvedDropColumnAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropColumnAction_name)(void * arg0,void ** arg1){
  zetasql::ResolvedDropColumnAction *node = (zetasql::ResolvedDropColumnAction *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedDropColumnAction_set_name)(void * arg0,void * arg1){
  zetasql::ResolvedDropColumnAction *node = (zetasql::ResolvedDropColumnAction *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedRenameColumnAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedRenameColumnAction *node = (zetasql::ResolvedRenameColumnAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedRenameColumnAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedRenameColumnAction *node = (zetasql::ResolvedRenameColumnAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedRenameColumnAction_name)(void * arg0,void ** arg1){
  zetasql::ResolvedRenameColumnAction *node = (zetasql::ResolvedRenameColumnAction *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedRenameColumnAction_set_name)(void * arg0,void * arg1){
  zetasql::ResolvedRenameColumnAction *node = (zetasql::ResolvedRenameColumnAction *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedRenameColumnAction_new_name)(void * arg0,void ** arg1){
  zetasql::ResolvedRenameColumnAction *node = (zetasql::ResolvedRenameColumnAction *)arg0;
  *arg1 = (void *)((new std::string(node->new_name()))->c_str());
}

void GO_EXPORT(ResolvedRenameColumnAction_set_new_name)(void * arg0,void * arg1){
  zetasql::ResolvedRenameColumnAction *node = (zetasql::ResolvedRenameColumnAction *)arg0;
  node->set_new_name((char *)arg1);
}

void GO_EXPORT(ResolvedSetAsAction_entity_body_json)(void * arg0,void ** arg1){
  zetasql::ResolvedSetAsAction *node = (zetasql::ResolvedSetAsAction *)arg0;
  *arg1 = (void *)((new std::string(node->entity_body_json()))->c_str());
}

void GO_EXPORT(ResolvedSetAsAction_set_entity_body_json)(void * arg0,void * arg1){
  zetasql::ResolvedSetAsAction *node = (zetasql::ResolvedSetAsAction *)arg0;
  node->set_entity_body_json((char *)arg1);
}

void GO_EXPORT(ResolvedSetAsAction_entity_body_text)(void * arg0,void ** arg1){
  zetasql::ResolvedSetAsAction *node = (zetasql::ResolvedSetAsAction *)arg0;
  *arg1 = (void *)((new std::string(node->entity_body_text()))->c_str());
}

void GO_EXPORT(ResolvedSetAsAction_set_entity_body_text)(void * arg0,void * arg1){
  zetasql::ResolvedSetAsAction *node = (zetasql::ResolvedSetAsAction *)arg0;
  node->set_entity_body_text((char *)arg1);
}

void GO_EXPORT(ResolvedSetCollateClause_collation_name)(void * arg0,void ** arg1){
  zetasql::ResolvedSetCollateClause *node = (zetasql::ResolvedSetCollateClause *)arg0;
  *arg1 = (void *)node->collation_name();
}

void GO_EXPORT(ResolvedSetCollateClause_set_collation_name)(void * arg0,void * arg1){
  zetasql::ResolvedSetCollateClause *node = (zetasql::ResolvedSetCollateClause *)arg0;
  node->set_collation_name(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterTableSetOptionsStmt *node = (zetasql::ResolvedAlterTableSetOptionsStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedAlterTableSetOptionsStmt *node = (zetasql::ResolvedAlterTableSetOptionsStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedAlterTableSetOptionsStmt *node = (zetasql::ResolvedAlterTableSetOptionsStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterTableSetOptionsStmt *node = (zetasql::ResolvedAlterTableSetOptionsStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedAlterTableSetOptionsStmt *node = (zetasql::ResolvedAlterTableSetOptionsStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedAlterTableSetOptionsStmt *node = (zetasql::ResolvedAlterTableSetOptionsStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedAlterTableSetOptionsStmt *node = (zetasql::ResolvedAlterTableSetOptionsStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedAlterTableSetOptionsStmt *node = (zetasql::ResolvedAlterTableSetOptionsStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedRenameStmt_object_type)(void * arg0,void ** arg1){
  zetasql::ResolvedRenameStmt *node = (zetasql::ResolvedRenameStmt *)arg0;
  *arg1 = (void *)((new std::string(node->object_type()))->c_str());
}

void GO_EXPORT(ResolvedRenameStmt_set_object_type)(void * arg0,void * arg1){
  zetasql::ResolvedRenameStmt *node = (zetasql::ResolvedRenameStmt *)arg0;
  node->set_object_type((char *)arg1);
}

void GO_EXPORT(ResolvedRenameStmt_old_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedRenameStmt *node = (zetasql::ResolvedRenameStmt *)arg0;
  GET_STRS(node->old_name_path, arg1);
}

void GO_EXPORT(ResolvedRenameStmt_set_old_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedRenameStmt *node = (zetasql::ResolvedRenameStmt *)arg0;
  SET_LIST(node->set_old_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedRenameStmt_add_old_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedRenameStmt *node = (zetasql::ResolvedRenameStmt *)arg0;
  node->add_old_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedRenameStmt_new_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedRenameStmt *node = (zetasql::ResolvedRenameStmt *)arg0;
  GET_STRS(node->new_name_path, arg1);
}

void GO_EXPORT(ResolvedRenameStmt_set_new_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedRenameStmt *node = (zetasql::ResolvedRenameStmt *)arg0;
  SET_LIST(node->set_new_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedRenameStmt_add_new_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedRenameStmt *node = (zetasql::ResolvedRenameStmt *)arg0;
  node->add_new_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreatePrivilegeRestrictionStmt *node = (zetasql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_privilege_list, arg1);
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreatePrivilegeRestrictionStmt *node = (zetasql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreatePrivilegeRestrictionStmt *node = (zetasql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_object_type)(void * arg0,void ** arg1){
  zetasql::ResolvedCreatePrivilegeRestrictionStmt *node = (zetasql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  *arg1 = (void *)((new std::string(node->object_type()))->c_str());
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_set_object_type)(void * arg0,void * arg1){
  zetasql::ResolvedCreatePrivilegeRestrictionStmt *node = (zetasql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  node->set_object_type((char *)arg1);
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_restrictee_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreatePrivilegeRestrictionStmt *node = (zetasql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->restrictee_list, arg1);
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreatePrivilegeRestrictionStmt *node = (zetasql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreatePrivilegeRestrictionStmt *node = (zetasql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_create_mode)(void * arg0,int* arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  *arg1 = node->create_mode();
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_create_mode)(void * arg0,int arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  node->set_create_mode((zetasql::ResolvedCreateRowAccessPolicyStmt::CreateMode)arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_name)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_name)(void * arg0,void * arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_target_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  GET_STRS(node->target_name_path, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_target_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  SET_LIST(node->set_target_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_add_target_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  node->add_target_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_grantee_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  GET_STRS(node->grantee_list, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_grantee_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  SET_LIST(node->set_grantee_list, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_add_grantee_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  node->add_grantee_list((char *)arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_grantee_expr_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_table_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_table_scan)(void * arg0,void * arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_predicate)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  *arg1 = (void *)node->predicate();
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_predicate)(void * arg0,void * arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  node->set_predicate(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_predicate_str)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  *arg1 = (void *)((new std::string(node->predicate_str()))->c_str());
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_predicate_str)(void * arg0,void * arg1){
  zetasql::ResolvedCreateRowAccessPolicyStmt *node = (zetasql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  node->set_predicate_str((char *)arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_object_type)(void * arg0,void ** arg1){
  zetasql::ResolvedDropPrivilegeRestrictionStmt *node = (zetasql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  *arg1 = (void *)((new std::string(node->object_type()))->c_str());
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_set_object_type)(void * arg0,void * arg1){
  zetasql::ResolvedDropPrivilegeRestrictionStmt *node = (zetasql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  node->set_object_type((char *)arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedDropPrivilegeRestrictionStmt *node = (zetasql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedDropPrivilegeRestrictionStmt *node = (zetasql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedDropPrivilegeRestrictionStmt *node = (zetasql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropPrivilegeRestrictionStmt *node = (zetasql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropPrivilegeRestrictionStmt *node = (zetasql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_column_privilege_list)(void * arg0,void ** arg1){
  zetasql::ResolvedDropPrivilegeRestrictionStmt *node = (zetasql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_privilege_list, arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list)(void * arg0,void * arg1){
  zetasql::ResolvedDropPrivilegeRestrictionStmt *node = (zetasql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list)(void * arg0,void * arg1){
  zetasql::ResolvedDropPrivilegeRestrictionStmt *node = (zetasql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_is_drop_all)(void * arg0,char* arg1){
  zetasql::ResolvedDropRowAccessPolicyStmt *node = (zetasql::ResolvedDropRowAccessPolicyStmt *)arg0;
  *arg1 = node->is_drop_all();
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_set_is_drop_all)(void * arg0,int arg1){
  zetasql::ResolvedDropRowAccessPolicyStmt *node = (zetasql::ResolvedDropRowAccessPolicyStmt *)arg0;
  node->set_is_drop_all(arg1);
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedDropRowAccessPolicyStmt *node = (zetasql::ResolvedDropRowAccessPolicyStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedDropRowAccessPolicyStmt *node = (zetasql::ResolvedDropRowAccessPolicyStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_name)(void * arg0,void ** arg1){
  zetasql::ResolvedDropRowAccessPolicyStmt *node = (zetasql::ResolvedDropRowAccessPolicyStmt *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_set_name)(void * arg0,void * arg1){
  zetasql::ResolvedDropRowAccessPolicyStmt *node = (zetasql::ResolvedDropRowAccessPolicyStmt *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_target_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedDropRowAccessPolicyStmt *node = (zetasql::ResolvedDropRowAccessPolicyStmt *)arg0;
  GET_STRS(node->target_name_path, arg1);
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_set_target_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropRowAccessPolicyStmt *node = (zetasql::ResolvedDropRowAccessPolicyStmt *)arg0;
  SET_LIST(node->set_target_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_add_target_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropRowAccessPolicyStmt *node = (zetasql::ResolvedDropRowAccessPolicyStmt *)arg0;
  node->add_target_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedDropSearchIndexStmt *node = (zetasql::ResolvedDropSearchIndexStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedDropSearchIndexStmt *node = (zetasql::ResolvedDropSearchIndexStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_name)(void * arg0,void ** arg1){
  zetasql::ResolvedDropSearchIndexStmt *node = (zetasql::ResolvedDropSearchIndexStmt *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_set_name)(void * arg0,void * arg1){
  zetasql::ResolvedDropSearchIndexStmt *node = (zetasql::ResolvedDropSearchIndexStmt *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_table_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedDropSearchIndexStmt *node = (zetasql::ResolvedDropSearchIndexStmt *)arg0;
  GET_STRS(node->table_name_path, arg1);
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_set_table_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropSearchIndexStmt *node = (zetasql::ResolvedDropSearchIndexStmt *)arg0;
  SET_LIST(node->set_table_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_add_table_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropSearchIndexStmt *node = (zetasql::ResolvedDropSearchIndexStmt *)arg0;
  node->add_table_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedGrantToAction_grantee_expr_list)(void * arg0,void ** arg1){
  zetasql::ResolvedGrantToAction *node = (zetasql::ResolvedGrantToAction *)arg0;
  GET_UNIQUE_PTR_LIST(node->grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedGrantToAction_set_grantee_expr_list)(void * arg0,void * arg1){
  zetasql::ResolvedGrantToAction *node = (zetasql::ResolvedGrantToAction *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedGrantToAction_add_grantee_expr_list)(void * arg0,void * arg1){
  zetasql::ResolvedGrantToAction *node = (zetasql::ResolvedGrantToAction *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedRestrictToAction_restrictee_list)(void * arg0,void ** arg1){
  zetasql::ResolvedRestrictToAction *node = (zetasql::ResolvedRestrictToAction *)arg0;
  GET_UNIQUE_PTR_LIST(node->restrictee_list, arg1);
}

void GO_EXPORT(ResolvedRestrictToAction_set_restrictee_list)(void * arg0,void * arg1){
  zetasql::ResolvedRestrictToAction *node = (zetasql::ResolvedRestrictToAction *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedRestrictToAction_add_restrictee_list)(void * arg0,void * arg1){
  zetasql::ResolvedRestrictToAction *node = (zetasql::ResolvedRestrictToAction *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedAddToRestricteeListAction_is_if_not_exists)(void * arg0,char* arg1){
  zetasql::ResolvedAddToRestricteeListAction *node = (zetasql::ResolvedAddToRestricteeListAction *)arg0;
  *arg1 = node->is_if_not_exists();
}

void GO_EXPORT(ResolvedAddToRestricteeListAction_set_is_if_not_exists)(void * arg0,int arg1){
  zetasql::ResolvedAddToRestricteeListAction *node = (zetasql::ResolvedAddToRestricteeListAction *)arg0;
  node->set_is_if_not_exists(arg1);
}

void GO_EXPORT(ResolvedAddToRestricteeListAction_restrictee_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAddToRestricteeListAction *node = (zetasql::ResolvedAddToRestricteeListAction *)arg0;
  GET_UNIQUE_PTR_LIST(node->restrictee_list, arg1);
}

void GO_EXPORT(ResolvedAddToRestricteeListAction_set_restrictee_list)(void * arg0,void * arg1){
  zetasql::ResolvedAddToRestricteeListAction *node = (zetasql::ResolvedAddToRestricteeListAction *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedAddToRestricteeListAction_add_restrictee_list)(void * arg0,void * arg1){
  zetasql::ResolvedAddToRestricteeListAction *node = (zetasql::ResolvedAddToRestricteeListAction *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedRemoveFromRestricteeListAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedRemoveFromRestricteeListAction *node = (zetasql::ResolvedRemoveFromRestricteeListAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedRemoveFromRestricteeListAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedRemoveFromRestricteeListAction *node = (zetasql::ResolvedRemoveFromRestricteeListAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedRemoveFromRestricteeListAction_restrictee_list)(void * arg0,void ** arg1){
  zetasql::ResolvedRemoveFromRestricteeListAction *node = (zetasql::ResolvedRemoveFromRestricteeListAction *)arg0;
  GET_UNIQUE_PTR_LIST(node->restrictee_list, arg1);
}

void GO_EXPORT(ResolvedRemoveFromRestricteeListAction_set_restrictee_list)(void * arg0,void * arg1){
  zetasql::ResolvedRemoveFromRestricteeListAction *node = (zetasql::ResolvedRemoveFromRestricteeListAction *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedRemoveFromRestricteeListAction_add_restrictee_list)(void * arg0,void * arg1){
  zetasql::ResolvedRemoveFromRestricteeListAction *node = (zetasql::ResolvedRemoveFromRestricteeListAction *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedFilterUsingAction_predicate)(void * arg0,void ** arg1){
  zetasql::ResolvedFilterUsingAction *node = (zetasql::ResolvedFilterUsingAction *)arg0;
  *arg1 = (void *)node->predicate();
}

void GO_EXPORT(ResolvedFilterUsingAction_set_predicate)(void * arg0,void * arg1){
  zetasql::ResolvedFilterUsingAction *node = (zetasql::ResolvedFilterUsingAction *)arg0;
  node->set_predicate(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedFilterUsingAction_predicate_str)(void * arg0,void ** arg1){
  zetasql::ResolvedFilterUsingAction *node = (zetasql::ResolvedFilterUsingAction *)arg0;
  *arg1 = (void *)((new std::string(node->predicate_str()))->c_str());
}

void GO_EXPORT(ResolvedFilterUsingAction_set_predicate_str)(void * arg0,void * arg1){
  zetasql::ResolvedFilterUsingAction *node = (zetasql::ResolvedFilterUsingAction *)arg0;
  node->set_predicate_str((char *)arg1);
}

void GO_EXPORT(ResolvedRevokeFromAction_revokee_expr_list)(void * arg0,void ** arg1){
  zetasql::ResolvedRevokeFromAction *node = (zetasql::ResolvedRevokeFromAction *)arg0;
  GET_UNIQUE_PTR_LIST(node->revokee_expr_list, arg1);
}

void GO_EXPORT(ResolvedRevokeFromAction_set_revokee_expr_list)(void * arg0,void * arg1){
  zetasql::ResolvedRevokeFromAction *node = (zetasql::ResolvedRevokeFromAction *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_revokee_expr_list, arg1);
}

void GO_EXPORT(ResolvedRevokeFromAction_add_revokee_expr_list)(void * arg0,void * arg1){
  zetasql::ResolvedRevokeFromAction *node = (zetasql::ResolvedRevokeFromAction *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_revokee_expr_list, arg1);
}

void GO_EXPORT(ResolvedRevokeFromAction_is_revoke_from_all)(void * arg0,char* arg1){
  zetasql::ResolvedRevokeFromAction *node = (zetasql::ResolvedRevokeFromAction *)arg0;
  *arg1 = node->is_revoke_from_all();
}

void GO_EXPORT(ResolvedRevokeFromAction_set_is_revoke_from_all)(void * arg0,int arg1){
  zetasql::ResolvedRevokeFromAction *node = (zetasql::ResolvedRevokeFromAction *)arg0;
  node->set_is_revoke_from_all(arg1);
}

void GO_EXPORT(ResolvedRenameToAction_new_path)(void * arg0,void ** arg1){
  zetasql::ResolvedRenameToAction *node = (zetasql::ResolvedRenameToAction *)arg0;
  GET_STRS(node->new_path, arg1);
}

void GO_EXPORT(ResolvedRenameToAction_set_new_path)(void * arg0,void * arg1){
  zetasql::ResolvedRenameToAction *node = (zetasql::ResolvedRenameToAction *)arg0;
  SET_LIST(node->set_new_path, std::string, arg1);
}

void GO_EXPORT(ResolvedRenameToAction_add_new_path)(void * arg0,void * arg1){
  zetasql::ResolvedRenameToAction *node = (zetasql::ResolvedRenameToAction *)arg0;
  node->add_new_path((char *)arg1);
}

void GO_EXPORT(ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterPrivilegeRestrictionStmt *node = (zetasql::ResolvedAlterPrivilegeRestrictionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_privilege_list, arg1);
}

void GO_EXPORT(ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list)(void * arg0,void * arg1){
  zetasql::ResolvedAlterPrivilegeRestrictionStmt *node = (zetasql::ResolvedAlterPrivilegeRestrictionStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list)(void * arg0,void * arg1){
  zetasql::ResolvedAlterPrivilegeRestrictionStmt *node = (zetasql::ResolvedAlterPrivilegeRestrictionStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedAlterPrivilegeRestrictionStmt_object_type)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterPrivilegeRestrictionStmt *node = (zetasql::ResolvedAlterPrivilegeRestrictionStmt *)arg0;
  *arg1 = (void *)((new std::string(node->object_type()))->c_str());
}

void GO_EXPORT(ResolvedAlterPrivilegeRestrictionStmt_set_object_type)(void * arg0,void * arg1){
  zetasql::ResolvedAlterPrivilegeRestrictionStmt *node = (zetasql::ResolvedAlterPrivilegeRestrictionStmt *)arg0;
  node->set_object_type((char *)arg1);
}

void GO_EXPORT(ResolvedAlterRowAccessPolicyStmt_name)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterRowAccessPolicyStmt *node = (zetasql::ResolvedAlterRowAccessPolicyStmt *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedAlterRowAccessPolicyStmt_set_name)(void * arg0,void * arg1){
  zetasql::ResolvedAlterRowAccessPolicyStmt *node = (zetasql::ResolvedAlterRowAccessPolicyStmt *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedAlterRowAccessPolicyStmt_table_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterRowAccessPolicyStmt *node = (zetasql::ResolvedAlterRowAccessPolicyStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedAlterRowAccessPolicyStmt_set_table_scan)(void * arg0,void * arg1){
  zetasql::ResolvedAlterRowAccessPolicyStmt *node = (zetasql::ResolvedAlterRowAccessPolicyStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedAlterAllRowAccessPoliciesStmt_table_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterAllRowAccessPoliciesStmt *node = (zetasql::ResolvedAlterAllRowAccessPoliciesStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan)(void * arg0,void * arg1){
  zetasql::ResolvedAlterAllRowAccessPoliciesStmt *node = (zetasql::ResolvedAlterAllRowAccessPoliciesStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedCreateConstantStmt_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateConstantStmt *node = (zetasql::ResolvedCreateConstantStmt *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedCreateConstantStmt_set_expr)(void * arg0,void * arg1){
  zetasql::ResolvedCreateConstantStmt *node = (zetasql::ResolvedCreateConstantStmt *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCreateFunctionStmt_has_explicit_return_type)(void * arg0,char* arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = node->has_explicit_return_type();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_has_explicit_return_type)(void * arg0,int arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  node->set_has_explicit_return_type(arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_return_type)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = (void *)node->return_type();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_return_type)(void * arg0,void * arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  node->set_return_type((const zetasql::Type *)arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_argument_name_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  GET_STRS(node->argument_name_list, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_argument_name_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  SET_LIST(node->set_argument_name_list, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_add_argument_name_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  node->add_argument_name_list((char *)arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_signature)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = (void *)(new zetasql::FunctionSignature(node->signature()));
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_signature)(void * arg0,void * arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  node->set_signature(*(zetasql::FunctionSignature *)arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_is_aggregate)(void * arg0,char* arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = node->is_aggregate();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_is_aggregate)(void * arg0,int arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  node->set_is_aggregate(arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_language)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = (void *)((new std::string(node->language()))->c_str());
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_language)(void * arg0,void * arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  node->set_language((char *)arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_code)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = (void *)((new std::string(node->code()))->c_str());
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_code)(void * arg0,void * arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  node->set_code((char *)arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_aggregate_expression_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->aggregate_expression_list, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_aggregate_expression_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_aggregate_expression_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_add_aggregate_expression_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_aggregate_expression_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_function_expression)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = (void *)node->function_expression();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_function_expression)(void * arg0,void * arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  node->set_function_expression(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCreateFunctionStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_sql_security)(void * arg0,int* arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = node->sql_security();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_sql_security)(void * arg0,int arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  node->set_sql_security((zetasql::ResolvedCreateFunctionStmt::SqlSecurity)arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_determinism_level)(void * arg0,int* arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = node->determinism_level();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_determinism_level)(void * arg0,int arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  node->set_determinism_level((zetasql::ResolvedCreateFunctionStmt::DeterminismLevel)arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_is_remote)(void * arg0,char* arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = node->is_remote();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_is_remote)(void * arg0,int arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  node->set_is_remote(arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_connection)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = (void *)node->connection();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_connection)(void * arg0,void * arg1){
  zetasql::ResolvedCreateFunctionStmt *node = (zetasql::ResolvedCreateFunctionStmt *)arg0;
  SET_UNIQUE_PTR(node->set_connection, ResolvedConnection, arg1);
}

void GO_EXPORT(ResolvedArgumentDef_name)(void * arg0,void ** arg1){
  zetasql::ResolvedArgumentDef *node = (zetasql::ResolvedArgumentDef *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedArgumentDef_set_name)(void * arg0,void * arg1){
  zetasql::ResolvedArgumentDef *node = (zetasql::ResolvedArgumentDef *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedArgumentDef_type)(void * arg0,void ** arg1){
  zetasql::ResolvedArgumentDef *node = (zetasql::ResolvedArgumentDef *)arg0;
  *arg1 = (void *)node->type();
}

void GO_EXPORT(ResolvedArgumentDef_set_type)(void * arg0,void * arg1){
  zetasql::ResolvedArgumentDef *node = (zetasql::ResolvedArgumentDef *)arg0;
  node->set_type((const zetasql::Type *)arg1);
}

void GO_EXPORT(ResolvedArgumentDef_argument_kind)(void * arg0,int* arg1){
  zetasql::ResolvedArgumentDef *node = (zetasql::ResolvedArgumentDef *)arg0;
  *arg1 = node->argument_kind();
}

void GO_EXPORT(ResolvedArgumentDef_set_argument_kind)(void * arg0,int arg1){
  zetasql::ResolvedArgumentDef *node = (zetasql::ResolvedArgumentDef *)arg0;
  node->set_argument_kind((zetasql::ResolvedArgumentDef::ArgumentKind)arg1);
}

void GO_EXPORT(ResolvedArgumentRef_name)(void * arg0,void ** arg1){
  zetasql::ResolvedArgumentRef *node = (zetasql::ResolvedArgumentRef *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedArgumentRef_set_name)(void * arg0,void * arg1){
  zetasql::ResolvedArgumentRef *node = (zetasql::ResolvedArgumentRef *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedArgumentRef_argument_kind)(void * arg0,int* arg1){
  zetasql::ResolvedArgumentRef *node = (zetasql::ResolvedArgumentRef *)arg0;
  *arg1 = node->argument_kind();
}

void GO_EXPORT(ResolvedArgumentRef_set_argument_kind)(void * arg0,int arg1){
  zetasql::ResolvedArgumentRef *node = (zetasql::ResolvedArgumentRef *)arg0;
  node->set_argument_kind((zetasql::ResolvedArgumentDef::ArgumentKind)arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_new)(void * arg0,int arg1,int arg2,void * arg3,void * arg4,int arg5,void * arg6,void * arg7,void * arg8,void *arg9,void * arg10,int arg11,int arg12,void ** arg13)
{
  std::vector<std::unique_ptr<const zetasql::ResolvedOption>> option_list;
  std::vector<std::unique_ptr<const zetasql::ResolvedOption>> *option_list_ref = &option_list;
  UNIQUE_PTR_LIST_TO_VEC(option_list_ref, ResolvedOption, arg6);

  std::vector<std::unique_ptr<const zetasql::ResolvedOutputColumn>> output_column_list;
  std::vector<std::unique_ptr<const zetasql::ResolvedOutputColumn>> *output_column_list_ref = &output_column_list;
  UNIQUE_PTR_LIST_TO_VEC(output_column_list_ref, ResolvedOutputColumn, arg10);

  *(std::unique_ptr<zetasql::ResolvedCreateTableFunctionStmt> *)arg13 = zetasql::MakeResolvedCreateTableFunctionStmt(
    slice_to_strs(arg0),
    (zetasql::ResolvedCreateStatementEnums::CreateScope)arg1,
    (zetasql::ResolvedCreateStatementEnums::CreateMode)arg2,
    slice_to_strs(arg3),
    *(zetasql::FunctionSignature *)arg4,
    arg5,
    std::move(option_list),
    (char *)arg7,
    (char *)arg8,
    make_unique_scan(arg9),
    std::move(output_column_list),
    arg11,
    (zetasql::ResolvedCreateStatementEnums::SqlSecurity)arg12
  );
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_argument_name_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  GET_STRS(node->argument_name_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_argument_name_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  SET_LIST(node->set_argument_name_list, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_add_argument_name_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  node->add_argument_name_list((char *)arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_signature)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  *arg1 = (void *)(new zetasql::FunctionSignature(node->signature()));
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_signature)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  node->set_signature(*(zetasql::FunctionSignature *)arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_has_explicit_return_schema)(void * arg0,char* arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  *arg1 = node->has_explicit_return_schema();
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema)(void * arg0,int arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  node->set_has_explicit_return_schema(arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_language)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  *arg1 = (void *)((new std::string(node->language()))->c_str());
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_language)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  node->set_language((char *)arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_code)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  *arg1 = (void *)((new std::string(node->code()))->c_str());
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_code)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  node->set_code((char *)arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_query)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_query)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_output_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_add_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_is_value_table)(void * arg0,char* arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  *arg1 = node->is_value_table();
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_is_value_table)(void * arg0,int arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  node->set_is_value_table(arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_sql_security)(void * arg0,int* arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  *arg1 = node->sql_security();
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_sql_security)(void * arg0,int arg1){
  zetasql::ResolvedCreateTableFunctionStmt *node = (zetasql::ResolvedCreateTableFunctionStmt *)arg0;
  node->set_sql_security((zetasql::ResolvedCreateTableFunctionStmt::SqlSecurity)arg1);
}

void GO_EXPORT(ResolvedRelationArgumentScan_name)(void * arg0,void ** arg1){
  zetasql::ResolvedRelationArgumentScan *node = (zetasql::ResolvedRelationArgumentScan *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedRelationArgumentScan_set_name)(void * arg0,void * arg1){
  zetasql::ResolvedRelationArgumentScan *node = (zetasql::ResolvedRelationArgumentScan *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedRelationArgumentScan_is_value_table)(void * arg0,char* arg1){
  zetasql::ResolvedRelationArgumentScan *node = (zetasql::ResolvedRelationArgumentScan *)arg0;
  *arg1 = node->is_value_table();
}

void GO_EXPORT(ResolvedRelationArgumentScan_set_is_value_table)(void * arg0,int arg1){
  zetasql::ResolvedRelationArgumentScan *node = (zetasql::ResolvedRelationArgumentScan *)arg0;
  node->set_is_value_table(arg1);
}

void GO_EXPORT(ResolvedArgumentList_arg_list)(void * arg0,void ** arg1){
  zetasql::ResolvedArgumentList *node = (zetasql::ResolvedArgumentList *)arg0;
  GET_UNIQUE_PTR_LIST(node->arg_list, arg1);
}

void GO_EXPORT(ResolvedArgumentList_set_arg_list)(void * arg0,void * arg1){
  zetasql::ResolvedArgumentList *node = (zetasql::ResolvedArgumentList *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_arg_list, ResolvedArgumentDef, arg1);
}

void GO_EXPORT(ResolvedArgumentList_add_arg_list)(void * arg0,void * arg1){
  zetasql::ResolvedArgumentList *node = (zetasql::ResolvedArgumentList *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_arg_list, ResolvedArgumentDef, arg1);
}

void GO_EXPORT(ResolvedFunctionSignatureHolder_signature)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionSignatureHolder *node = (zetasql::ResolvedFunctionSignatureHolder *)arg0;
  *arg1 = (void *)(new zetasql::FunctionSignature(node->signature()));
}

void GO_EXPORT(ResolvedFunctionSignatureHolder_set_signature)(void * arg0,void * arg1){
  zetasql::ResolvedFunctionSignatureHolder *node = (zetasql::ResolvedFunctionSignatureHolder *)arg0;
  node->set_signature(*(zetasql::FunctionSignature *)arg1);
}

void GO_EXPORT(ResolvedDropFunctionStmt_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedDropFunctionStmt *node = (zetasql::ResolvedDropFunctionStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropFunctionStmt_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedDropFunctionStmt *node = (zetasql::ResolvedDropFunctionStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropFunctionStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedDropFunctionStmt *node = (zetasql::ResolvedDropFunctionStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDropFunctionStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropFunctionStmt *node = (zetasql::ResolvedDropFunctionStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDropFunctionStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropFunctionStmt *node = (zetasql::ResolvedDropFunctionStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedDropFunctionStmt_arguments)(void * arg0,void ** arg1){
  zetasql::ResolvedDropFunctionStmt *node = (zetasql::ResolvedDropFunctionStmt *)arg0;
  *arg1 = (void *)node->arguments();
}

void GO_EXPORT(ResolvedDropFunctionStmt_set_arguments)(void * arg0,void * arg1){
  zetasql::ResolvedDropFunctionStmt *node = (zetasql::ResolvedDropFunctionStmt *)arg0;
  SET_UNIQUE_PTR(node->set_arguments, ResolvedArgumentList, arg1);
}

void GO_EXPORT(ResolvedDropFunctionStmt_signature)(void * arg0,void ** arg1){
  zetasql::ResolvedDropFunctionStmt *node = (zetasql::ResolvedDropFunctionStmt *)arg0;
  *arg1 = (void *)node->signature();
}

void GO_EXPORT(ResolvedDropFunctionStmt_set_signature)(void * arg0,void * arg1){
  zetasql::ResolvedDropFunctionStmt *node = (zetasql::ResolvedDropFunctionStmt *)arg0;
  node->set_signature(zetasql::MakeResolvedFunctionSignatureHolder(*(zetasql::FunctionSignature *)arg1));
}

void GO_EXPORT(ResolvedDropTableFunctionStmt_is_if_exists)(void * arg0,char* arg1){
  zetasql::ResolvedDropTableFunctionStmt *node = (zetasql::ResolvedDropTableFunctionStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropTableFunctionStmt_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ResolvedDropTableFunctionStmt *node = (zetasql::ResolvedDropTableFunctionStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropTableFunctionStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedDropTableFunctionStmt *node = (zetasql::ResolvedDropTableFunctionStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDropTableFunctionStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropTableFunctionStmt *node = (zetasql::ResolvedDropTableFunctionStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDropTableFunctionStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedDropTableFunctionStmt *node = (zetasql::ResolvedDropTableFunctionStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedCallStmt_procedure)(void * arg0,void ** arg1){
  zetasql::ResolvedCallStmt *node = (zetasql::ResolvedCallStmt *)arg0;
  *arg1 = (void *)node->procedure();
}

void GO_EXPORT(ResolvedCallStmt_set_procedure)(void * arg0,void * arg1){
  zetasql::ResolvedCallStmt *node = (zetasql::ResolvedCallStmt *)arg0;
  node->set_procedure((const zetasql::Procedure *)arg1);
}

void GO_EXPORT(ResolvedCallStmt_signature)(void * arg0,void ** arg1){
  zetasql::ResolvedCallStmt *node = (zetasql::ResolvedCallStmt *)arg0;
  *arg1 = (void *)(new zetasql::FunctionSignature(node->signature()));
}

void GO_EXPORT(ResolvedCallStmt_set_signature)(void * arg0,void * arg1){
  zetasql::ResolvedCallStmt *node = (zetasql::ResolvedCallStmt *)arg0;
  node->set_signature(*(zetasql::FunctionSignature *)arg1);
}

void GO_EXPORT(ResolvedCallStmt_argument_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCallStmt *node = (zetasql::ResolvedCallStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->argument_list, arg1);
}

void GO_EXPORT(ResolvedCallStmt_set_argument_list)(void * arg0,void * arg1){
  zetasql::ResolvedCallStmt *node = (zetasql::ResolvedCallStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_argument_list, arg1);
}

void GO_EXPORT(ResolvedCallStmt_add_argument_list)(void * arg0,void * arg1){
  zetasql::ResolvedCallStmt *node = (zetasql::ResolvedCallStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_argument_list, arg1);
}

void GO_EXPORT(ResolvedImportStmt_import_kind)(void * arg0,int* arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  *arg1 = node->import_kind();
}

void GO_EXPORT(ResolvedImportStmt_set_import_kind)(void * arg0,int arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  node->set_import_kind((zetasql::ResolvedImportStmt::ImportKind)arg1);
}

void GO_EXPORT(ResolvedImportStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedImportStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedImportStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedImportStmt_file_path)(void * arg0,void ** arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  *arg1 = (void *)((new std::string(node->file_path()))->c_str());
}

void GO_EXPORT(ResolvedImportStmt_set_file_path)(void * arg0,void * arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  node->set_file_path((char *)arg1);
}

void GO_EXPORT(ResolvedImportStmt_alias_path)(void * arg0,void ** arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  GET_STRS(node->alias_path, arg1);
}

void GO_EXPORT(ResolvedImportStmt_set_alias_path)(void * arg0,void * arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  SET_LIST(node->set_alias_path, std::string, arg1);
}

void GO_EXPORT(ResolvedImportStmt_add_alias_path)(void * arg0,void * arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  node->add_alias_path((char *)arg1);
}

void GO_EXPORT(ResolvedImportStmt_into_alias_path)(void * arg0,void ** arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  GET_STRS(node->into_alias_path, arg1);
}

void GO_EXPORT(ResolvedImportStmt_set_into_alias_path)(void * arg0,void * arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  SET_LIST(node->set_into_alias_path, std::string, arg1);
}

void GO_EXPORT(ResolvedImportStmt_add_into_alias_path)(void * arg0,void * arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  node->add_into_alias_path((char *)arg1);
}

void GO_EXPORT(ResolvedImportStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedImportStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedImportStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedImportStmt *node = (zetasql::ResolvedImportStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedModuleStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedModuleStmt *node = (zetasql::ResolvedModuleStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedModuleStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedModuleStmt *node = (zetasql::ResolvedModuleStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedModuleStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedModuleStmt *node = (zetasql::ResolvedModuleStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedModuleStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedModuleStmt *node = (zetasql::ResolvedModuleStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedModuleStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedModuleStmt *node = (zetasql::ResolvedModuleStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedModuleStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedModuleStmt *node = (zetasql::ResolvedModuleStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAggregateHavingModifier_kind)(void * arg0,int* arg1){
  zetasql::ResolvedAggregateHavingModifier *node = (zetasql::ResolvedAggregateHavingModifier *)arg0;
  *arg1 = node->kind();
}

void GO_EXPORT(ResolvedAggregateHavingModifier_set_kind)(void * arg0,int arg1){
  zetasql::ResolvedAggregateHavingModifier *node = (zetasql::ResolvedAggregateHavingModifier *)arg0;
  node->set_kind((zetasql::ResolvedAggregateHavingModifier::HavingModifierKind)arg1);
}

void GO_EXPORT(ResolvedAggregateHavingModifier_having_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedAggregateHavingModifier *node = (zetasql::ResolvedAggregateHavingModifier *)arg0;
  *arg1 = (void *)node->having_expr();
}

void GO_EXPORT(ResolvedAggregateHavingModifier_set_having_expr)(void * arg0,void * arg1){
  zetasql::ResolvedAggregateHavingModifier *node = (zetasql::ResolvedAggregateHavingModifier *)arg0;
  node->set_having_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_column_definition_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateMaterializedViewStmt *node = (zetasql::ResolvedCreateMaterializedViewStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_definition_list, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_set_column_definition_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateMaterializedViewStmt *node = (zetasql::ResolvedCreateMaterializedViewStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_add_column_definition_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateMaterializedViewStmt *node = (zetasql::ResolvedCreateMaterializedViewStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_partition_by_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateMaterializedViewStmt *node = (zetasql::ResolvedCreateMaterializedViewStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_set_partition_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateMaterializedViewStmt *node = (zetasql::ResolvedCreateMaterializedViewStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_add_partition_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateMaterializedViewStmt *node = (zetasql::ResolvedCreateMaterializedViewStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_cluster_by_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateMaterializedViewStmt *node = (zetasql::ResolvedCreateMaterializedViewStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_set_cluster_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateMaterializedViewStmt *node = (zetasql::ResolvedCreateMaterializedViewStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_add_cluster_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateMaterializedViewStmt *node = (zetasql::ResolvedCreateMaterializedViewStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_argument_name_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateProcedureStmt *node = (zetasql::ResolvedCreateProcedureStmt *)arg0;
  GET_STRS(node->argument_name_list, arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_set_argument_name_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateProcedureStmt *node = (zetasql::ResolvedCreateProcedureStmt *)arg0;
  SET_LIST(node->set_argument_name_list, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_add_argument_name_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateProcedureStmt *node = (zetasql::ResolvedCreateProcedureStmt *)arg0;
  node->add_argument_name_list((char *)arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_signature)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateProcedureStmt *node = (zetasql::ResolvedCreateProcedureStmt *)arg0;
  *arg1 = (void *)(new zetasql::FunctionSignature(node->signature()));
}

void GO_EXPORT(ResolvedCreateProcedureStmt_set_signature)(void * arg0,void * arg1){
  zetasql::ResolvedCreateProcedureStmt *node = (zetasql::ResolvedCreateProcedureStmt *)arg0;
  node->set_signature(*(zetasql::FunctionSignature *)arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateProcedureStmt *node = (zetasql::ResolvedCreateProcedureStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateProcedureStmt *node = (zetasql::ResolvedCreateProcedureStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateProcedureStmt *node = (zetasql::ResolvedCreateProcedureStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_procedure_body)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateProcedureStmt *node = (zetasql::ResolvedCreateProcedureStmt *)arg0;
  *arg1 = (void *)((new std::string(node->procedure_body()))->c_str());
}

void GO_EXPORT(ResolvedCreateProcedureStmt_set_procedure_body)(void * arg0,void * arg1){
  zetasql::ResolvedCreateProcedureStmt *node = (zetasql::ResolvedCreateProcedureStmt *)arg0;
  node->set_procedure_body((char *)arg1);
}

void GO_EXPORT(ResolvedExecuteImmediateArgument_name)(void * arg0,void ** arg1){
  zetasql::ResolvedExecuteImmediateArgument *node = (zetasql::ResolvedExecuteImmediateArgument *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedExecuteImmediateArgument_set_name)(void * arg0,void * arg1){
  zetasql::ResolvedExecuteImmediateArgument *node = (zetasql::ResolvedExecuteImmediateArgument *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedExecuteImmediateArgument_expression)(void * arg0,void ** arg1){
  zetasql::ResolvedExecuteImmediateArgument *node = (zetasql::ResolvedExecuteImmediateArgument *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ResolvedExecuteImmediateArgument_set_expression)(void * arg0,void * arg1){
  zetasql::ResolvedExecuteImmediateArgument *node = (zetasql::ResolvedExecuteImmediateArgument *)arg0;
  node->set_expression(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_sql)(void * arg0,void ** arg1){
  zetasql::ResolvedExecuteImmediateStmt *node = (zetasql::ResolvedExecuteImmediateStmt *)arg0;
  *arg1 = (void *)node->sql();
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_set_sql)(void * arg0,void * arg1){
  zetasql::ResolvedExecuteImmediateStmt *node = (zetasql::ResolvedExecuteImmediateStmt *)arg0;
  node->set_sql(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_into_identifier_list)(void * arg0,void ** arg1){
  zetasql::ResolvedExecuteImmediateStmt *node = (zetasql::ResolvedExecuteImmediateStmt *)arg0;
  GET_STRS(node->into_identifier_list, arg1);
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_set_into_identifier_list)(void * arg0,void * arg1){
  zetasql::ResolvedExecuteImmediateStmt *node = (zetasql::ResolvedExecuteImmediateStmt *)arg0;
  SET_LIST(node->set_into_identifier_list, std::string, arg1);
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_add_into_identifier_list)(void * arg0,void * arg1){
  zetasql::ResolvedExecuteImmediateStmt *node = (zetasql::ResolvedExecuteImmediateStmt *)arg0;
  node->add_into_identifier_list((char *)arg1);
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_using_argument_list)(void * arg0,void ** arg1){
  zetasql::ResolvedExecuteImmediateStmt *node = (zetasql::ResolvedExecuteImmediateStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->using_argument_list, arg1);
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_set_using_argument_list)(void * arg0,void * arg1){
  zetasql::ResolvedExecuteImmediateStmt *node = (zetasql::ResolvedExecuteImmediateStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_using_argument_list, ResolvedExecuteImmediateArgument, arg1);
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_add_using_argument_list)(void * arg0,void * arg1){
  zetasql::ResolvedExecuteImmediateStmt *node = (zetasql::ResolvedExecuteImmediateStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_using_argument_list, ResolvedExecuteImmediateArgument, arg1);
}

void GO_EXPORT(ResolvedAssignmentStmt_target)(void * arg0,void ** arg1){
  zetasql::ResolvedAssignmentStmt *node = (zetasql::ResolvedAssignmentStmt *)arg0;
  *arg1 = (void *)node->target();
}

void GO_EXPORT(ResolvedAssignmentStmt_set_target)(void * arg0,void * arg1){
  zetasql::ResolvedAssignmentStmt *node = (zetasql::ResolvedAssignmentStmt *)arg0;
  node->set_target(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedAssignmentStmt_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedAssignmentStmt *node = (zetasql::ResolvedAssignmentStmt *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedAssignmentStmt_set_expr)(void * arg0,void * arg1){
  zetasql::ResolvedAssignmentStmt *node = (zetasql::ResolvedAssignmentStmt *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCreateEntityStmt_entity_type)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateEntityStmt *node = (zetasql::ResolvedCreateEntityStmt *)arg0;
  *arg1 = (void *)((new std::string(node->entity_type()))->c_str());
}

void GO_EXPORT(ResolvedCreateEntityStmt_set_entity_type)(void * arg0,void * arg1){
  zetasql::ResolvedCreateEntityStmt *node = (zetasql::ResolvedCreateEntityStmt *)arg0;
  node->set_entity_type((char *)arg1);
}

void GO_EXPORT(ResolvedCreateEntityStmt_entity_body_json)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateEntityStmt *node = (zetasql::ResolvedCreateEntityStmt *)arg0;
  *arg1 = (void *)((new std::string(node->entity_body_json()))->c_str());
}

void GO_EXPORT(ResolvedCreateEntityStmt_set_entity_body_json)(void * arg0,void * arg1){
  zetasql::ResolvedCreateEntityStmt *node = (zetasql::ResolvedCreateEntityStmt *)arg0;
  node->set_entity_body_json((char *)arg1);
}

void GO_EXPORT(ResolvedCreateEntityStmt_entity_body_text)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateEntityStmt *node = (zetasql::ResolvedCreateEntityStmt *)arg0;
  *arg1 = (void *)((new std::string(node->entity_body_text()))->c_str());
}

void GO_EXPORT(ResolvedCreateEntityStmt_set_entity_body_text)(void * arg0,void * arg1){
  zetasql::ResolvedCreateEntityStmt *node = (zetasql::ResolvedCreateEntityStmt *)arg0;
  node->set_entity_body_text((char *)arg1);
}

void GO_EXPORT(ResolvedCreateEntityStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCreateEntityStmt *node = (zetasql::ResolvedCreateEntityStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateEntityStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateEntityStmt *node = (zetasql::ResolvedCreateEntityStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateEntityStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedCreateEntityStmt *node = (zetasql::ResolvedCreateEntityStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAlterEntityStmt_entity_type)(void * arg0,void ** arg1){
  zetasql::ResolvedAlterEntityStmt *node = (zetasql::ResolvedAlterEntityStmt *)arg0;
  *arg1 = (void *)((new std::string(node->entity_type()))->c_str());  
}

void GO_EXPORT(ResolvedAlterEntityStmt_set_entity_type)(void * arg0,void * arg1){
  zetasql::ResolvedAlterEntityStmt *node = (zetasql::ResolvedAlterEntityStmt *)arg0;
  node->set_entity_type((char *)arg1);
}

void GO_EXPORT(ResolvedPivotColumn_column)(void * arg0,void ** arg1){
  zetasql::ResolvedPivotColumn *node = (zetasql::ResolvedPivotColumn *)arg0;
  *arg1 = (void *)(new zetasql::ResolvedColumn(node->column()));
}

void GO_EXPORT(ResolvedPivotColumn_set_column)(void * arg0,void * arg1){
  zetasql::ResolvedPivotColumn *node = (zetasql::ResolvedPivotColumn *)arg0;
  node->set_column(*(zetasql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedPivotColumn_pivot_expr_index)(void * arg0,int* arg1){
  zetasql::ResolvedPivotColumn *node = (zetasql::ResolvedPivotColumn *)arg0;
  *arg1 = node->pivot_expr_index();
}

void GO_EXPORT(ResolvedPivotColumn_set_pivot_expr_index)(void * arg0,int arg1){
  zetasql::ResolvedPivotColumn *node = (zetasql::ResolvedPivotColumn *)arg0;
  node->set_pivot_expr_index(arg1);
}

void GO_EXPORT(ResolvedPivotColumn_pivot_value_index)(void * arg0,int* arg1){
  zetasql::ResolvedPivotColumn *node = (zetasql::ResolvedPivotColumn *)arg0;
  *arg1 = node->pivot_value_index();
}

void GO_EXPORT(ResolvedPivotColumn_set_pivot_value_index)(void * arg0,int arg1){
  zetasql::ResolvedPivotColumn *node = (zetasql::ResolvedPivotColumn *)arg0;
  node->set_pivot_value_index(arg1);
}

void GO_EXPORT(ResolvedPivotScan_input_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedPivotScan_set_input_scan)(void * arg0,void * arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedPivotScan_group_by_list)(void * arg0,void ** arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->group_by_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_set_group_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_group_by_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedPivotScan_add_group_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_group_by_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedPivotScan_pivot_expr_list)(void * arg0,void ** arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->pivot_expr_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_set_pivot_expr_list)(void * arg0,void * arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_pivot_expr_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_add_pivot_expr_list)(void * arg0,void * arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_pivot_expr_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_for_expr)(void * arg0,void ** arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  *arg1 = (void *)node->for_expr();
}

void GO_EXPORT(ResolvedPivotScan_set_for_expr)(void * arg0,void * arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  node->set_for_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedPivotScan_pivot_value_list)(void * arg0,void ** arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->pivot_value_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_set_pivot_value_list)(void * arg0,void * arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_pivot_value_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_add_pivot_value_list)(void * arg0,void * arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_pivot_value_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_pivot_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->pivot_column_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_set_pivot_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_pivot_column_list, ResolvedPivotColumn, arg1);
}

void GO_EXPORT(ResolvedPivotScan_add_pivot_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedPivotScan *node = (zetasql::ResolvedPivotScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_pivot_column_list, ResolvedPivotColumn, arg1);
}

void GO_EXPORT(ResolvedReturningClause_output_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedReturningClause *node = (zetasql::ResolvedReturningClause *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedReturningClause_set_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedReturningClause *node = (zetasql::ResolvedReturningClause *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedReturningClause_add_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedReturningClause *node = (zetasql::ResolvedReturningClause *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedReturningClause_action_column)(void * arg0,void ** arg1){
  zetasql::ResolvedReturningClause *node = (zetasql::ResolvedReturningClause *)arg0;
  *arg1 = (void *)node->action_column();
}

void GO_EXPORT(ResolvedReturningClause_set_action_column)(void * arg0,void * arg1){
  zetasql::ResolvedReturningClause *node = (zetasql::ResolvedReturningClause *)arg0;
  SET_UNIQUE_PTR(node->set_action_column, ResolvedColumnHolder, arg1);
}

void GO_EXPORT(ResolvedReturningClause_expr_list)(void * arg0,void ** arg1){
  zetasql::ResolvedReturningClause *node = (zetasql::ResolvedReturningClause *)arg0;
  GET_UNIQUE_PTR_LIST(node->expr_list, arg1);
}

void GO_EXPORT(ResolvedReturningClause_set_expr_list)(void * arg0,void * arg1){
  zetasql::ResolvedReturningClause *node = (zetasql::ResolvedReturningClause *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_expr_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedReturningClause_add_expr_list)(void * arg0,void * arg1){
  zetasql::ResolvedReturningClause *node = (zetasql::ResolvedReturningClause *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_expr_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedUnpivotArg_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedUnpivotArg *node = (zetasql::ResolvedUnpivotArg *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_list, arg1);
}

void GO_EXPORT(ResolvedUnpivotArg_set_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedUnpivotArg *node = (zetasql::ResolvedUnpivotArg *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedUnpivotArg_add_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedUnpivotArg *node = (zetasql::ResolvedUnpivotArg *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_input_scan)(void * arg0,void ** arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedUnpivotScan_set_input_scan)(void * arg0,void * arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedUnpivotScan_value_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  GET_LIST(node->value_column_list, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_set_value_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  SET_LIST(node->set_value_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_add_value_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  ADD_LIST(node->add_value_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_label_column)(void * arg0,void ** arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  *arg1 = (void *)(new zetasql::ResolvedColumn(node->label_column()));
}

void GO_EXPORT(ResolvedUnpivotScan_set_label_column)(void * arg0,void * arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  node->set_label_column(*(zetasql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_label_list)(void * arg0,void ** arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->label_list, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_set_label_list)(void * arg0,void * arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_label_list, ResolvedLiteral, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_add_label_list)(void * arg0,void * arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_label_list, ResolvedLiteral, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_unpivot_arg_list)(void * arg0,void ** arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->unpivot_arg_list, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_set_unpivot_arg_list)(void * arg0,void * arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_unpivot_arg_list, ResolvedUnpivotArg, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_add_unpivot_arg_list)(void * arg0,void * arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_unpivot_arg_list, ResolvedUnpivotArg, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_projected_input_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->projected_input_column_list, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_set_projected_input_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_projected_input_column_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_add_projected_input_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_projected_input_column_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_include_nulls)(void * arg0,char* arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  *arg1 = node->include_nulls();
}

void GO_EXPORT(ResolvedUnpivotScan_set_include_nulls)(void * arg0,int arg1){
  zetasql::ResolvedUnpivotScan *node = (zetasql::ResolvedUnpivotScan *)arg0;
  node->set_include_nulls(arg1);
}

void GO_EXPORT(ResolvedCloneDataStmt_target_table)(void * arg0,void ** arg1){
  zetasql::ResolvedCloneDataStmt *node = (zetasql::ResolvedCloneDataStmt *)arg0;
  *arg1 = (void *)node->target_table();
}

void GO_EXPORT(ResolvedCloneDataStmt_set_target_table)(void * arg0,void * arg1){
  zetasql::ResolvedCloneDataStmt *node = (zetasql::ResolvedCloneDataStmt *)arg0;
  SET_UNIQUE_PTR(node->set_target_table, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedCloneDataStmt_clone_from)(void * arg0,void ** arg1){
  zetasql::ResolvedCloneDataStmt *node = (zetasql::ResolvedCloneDataStmt *)arg0;
  *arg1 = (void *)node->clone_from();
}

void GO_EXPORT(ResolvedCloneDataStmt_set_clone_from)(void * arg0,void * arg1){
  zetasql::ResolvedCloneDataStmt *node = (zetasql::ResolvedCloneDataStmt *)arg0;
  node->set_clone_from(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedTableAndColumnInfo_table)(void * arg0,void ** arg1){
  zetasql::ResolvedTableAndColumnInfo *node = (zetasql::ResolvedTableAndColumnInfo *)arg0;
  *arg1 = (void *)node->table();
}

void GO_EXPORT(ResolvedTableAndColumnInfo_set_table)(void * arg0,void * arg1){
  zetasql::ResolvedTableAndColumnInfo *node = (zetasql::ResolvedTableAndColumnInfo *)arg0;
  node->set_table((const zetasql::Table *)arg1);
}

void GO_EXPORT(ResolvedTableAndColumnInfo_column_index_list)(void * arg0,void ** arg1){
  zetasql::ResolvedTableAndColumnInfo *node = (zetasql::ResolvedTableAndColumnInfo *)arg0;
  GET_INTS(node->column_index_list, arg1);
}

void GO_EXPORT(ResolvedTableAndColumnInfo_set_column_index_list)(void * arg0,void * arg1){
  zetasql::ResolvedTableAndColumnInfo *node = (zetasql::ResolvedTableAndColumnInfo *)arg0;
  SET_INTS(node->set_column_index_list, arg1);
}

void GO_EXPORT(ResolvedTableAndColumnInfo_add_column_index_list)(void * arg0,int arg1){
  zetasql::ResolvedTableAndColumnInfo *node = (zetasql::ResolvedTableAndColumnInfo *)arg0;
  node->add_column_index_list(arg1);
}

void GO_EXPORT(ResolvedAnalyzeStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAnalyzeStmt *node = (zetasql::ResolvedAnalyzeStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedAnalyzeStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedAnalyzeStmt *node = (zetasql::ResolvedAnalyzeStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAnalyzeStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedAnalyzeStmt *node = (zetasql::ResolvedAnalyzeStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAnalyzeStmt_table_and_column_index_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAnalyzeStmt *node = (zetasql::ResolvedAnalyzeStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->table_and_column_index_list, arg1);
}

void GO_EXPORT(ResolvedAnalyzeStmt_set_table_and_column_index_list)(void * arg0,void * arg1){
  zetasql::ResolvedAnalyzeStmt *node = (zetasql::ResolvedAnalyzeStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_table_and_column_index_list, ResolvedTableAndColumnInfo, arg1);
}

void GO_EXPORT(ResolvedAnalyzeStmt_add_table_and_column_index_list)(void * arg0,void * arg1){
  zetasql::ResolvedAnalyzeStmt *node = (zetasql::ResolvedAnalyzeStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_table_and_column_index_list, ResolvedTableAndColumnInfo, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_insertion_mode)(void * arg0,int* arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  *arg1 = node->insertion_mode();
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_insertion_mode)(void * arg0,int arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  node->set_insertion_mode((zetasql::ResolvedAuxLoadDataStmt::InsertionMode)arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_name_path)(void * arg0,void ** arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_name_path)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_output_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_output_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_column_definition_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_definition_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_column_definition_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_column_definition_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_pseudo_column_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  GET_LIST(node->pseudo_column_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_pseudo_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  SET_LIST(node->set_pseudo_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_pseudo_column_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_LIST(node->add_pseudo_column_list, zetasql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_primary_key)(void * arg0,void ** arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  *arg1 = (void *)node->primary_key();
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_primary_key)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR(node->set_primary_key, ResolvedPrimaryKey, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_foreign_key_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->foreign_key_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_foreign_key_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_foreign_key_list, ResolvedForeignKey, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_foreign_key_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_foreign_key_list, ResolvedForeignKey, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_check_constraint_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->check_constraint_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_check_constraint_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_check_constraint_list, ResolvedCheckConstraint, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_check_constraint_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_check_constraint_list, ResolvedCheckConstraint, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_partition_by_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->partition_by_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_partition_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_partition_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_cluster_by_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_cluster_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_cluster_by_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_with_partition_columns)(void * arg0,void ** arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  *arg1 = (void *)node->with_partition_columns();
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_with_partition_columns)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR(node->set_with_partition_columns, ResolvedWithPartitionColumns, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_connection)(void * arg0,void ** arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  *arg1 = (void *)node->connection();
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_connection)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR(node->set_connection, ResolvedConnection, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_from_files_option_list)(void * arg0,void ** arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->from_files_option_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_from_files_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_from_files_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_from_files_option_list)(void * arg0,void * arg1){
  zetasql::ResolvedAuxLoadDataStmt *node = (zetasql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_from_files_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedColumn_IsInitialized)(void * arg0,char* arg1){
  zetasql::ResolvedColumn *col = (zetasql::ResolvedColumn *)arg0;
  *arg1 = col->IsInitialized();
}

void GO_EXPORT(ResolvedColumn_Clear)(void * arg0){
  zetasql::ResolvedColumn *col = (zetasql::ResolvedColumn *)arg0;
  col->Clear();
}

void GO_EXPORT(ResolvedColumn_DebugString)(void * arg0,void ** arg1){
  zetasql::ResolvedColumn *col = (zetasql::ResolvedColumn *)arg0;
  *arg1 = (void *)((new std::string(col->DebugString()))->c_str());
}
  
void GO_EXPORT(ResolvedColumn_ShortDebugString)(void * arg0,void ** arg1){
  zetasql::ResolvedColumn *col = (zetasql::ResolvedColumn *)arg0;
  *arg1 = (void *)((new std::string(col->ShortDebugString()))->c_str());
}

void GO_EXPORT(ResolvedColumn_column_id)(void * arg0,int* arg1){
  zetasql::ResolvedColumn *col = (zetasql::ResolvedColumn *)arg0;
  *arg1 = col->column_id();
}

void GO_EXPORT(ResolvedColumn_table_name)(void * arg0,void ** arg1){
  zetasql::ResolvedColumn *col = (zetasql::ResolvedColumn *)arg0;
  *arg1 = (void *)((new std::string(col->table_name()))->c_str());
}

void GO_EXPORT(ResolvedColumn_name)(void * arg0,void ** arg1){
  zetasql::ResolvedColumn *col = (zetasql::ResolvedColumn *)arg0;
  *arg1 = (void *)((new std::string(col->name()))->c_str());
}

void GO_EXPORT(ResolvedColumn_table_name_id)(void * arg0,void ** arg1){
  zetasql::ResolvedColumn *col = (zetasql::ResolvedColumn *)arg0;
  *arg1 = (void *)((new std::string(col->table_name_id().data()))->c_str());
}

void GO_EXPORT(ResolvedColumn_name_id)(void * arg0,void ** arg1){
  zetasql::ResolvedColumn *col = (zetasql::ResolvedColumn *)arg0;
  *arg1 = (void *)((new std::string(col->name_id().data()))->c_str());
}

void GO_EXPORT(ResolvedColumn_type)(void * arg0,void ** arg1){
  zetasql::ResolvedColumn *col = (zetasql::ResolvedColumn *)arg0;
  *arg1 = (void *)col->type();
}

void GO_EXPORT(ResolvedColumn_type_annotation_map)(void * arg0,void ** arg1){
  zetasql::ResolvedColumn *col = (zetasql::ResolvedColumn *)arg0;
  *arg1 = (void *)col->type_annotation_map();
}

void GO_EXPORT(ResolvedColumn_annotated_type)(void * arg0,void ** arg1){
  zetasql::ResolvedColumn *col = (zetasql::ResolvedColumn *)arg0;
  *arg1 = (void *)(new zetasql::AnnotatedType(col->annotated_type()));
}

void GO_EXPORT(ResolvedCollation_Empty)(void * arg0,char* arg1){
  zetasql::ResolvedCollation *col = (zetasql::ResolvedCollation *)arg0;
  *arg1 = col->Empty();
}

void GO_EXPORT(ResolvedCollation_Equals)(void * arg0,void * arg1,char* arg2){
  zetasql::ResolvedCollation *col = (zetasql::ResolvedCollation *)arg0;
  *arg2 = col->Equals(*(zetasql::ResolvedCollation *)arg1);
}

void GO_EXPORT(ResolvedCollation_HasCompatibleStructure)(void * arg0,void * arg1,char* arg2){
  zetasql::ResolvedCollation *col = (zetasql::ResolvedCollation *)arg0;
  *arg2 = col->HasCompatibleStructure((const zetasql::Type *)arg1);
}

void GO_EXPORT(ResolvedCollation_HasCollation)(void * arg0,char* arg1){
  zetasql::ResolvedCollation *col = (zetasql::ResolvedCollation *)arg0;
  *arg1 = col->HasCollation();
}

void GO_EXPORT(ResolvedCollation_CollationName)(void * arg0,void ** arg1){
  zetasql::ResolvedCollation *col = (zetasql::ResolvedCollation *)arg0;
  *arg1 = (void *)((new std::string(col->CollationName()))->c_str());
}

void GO_EXPORT(ResolvedCollation_child_list)(void * arg0,void ** arg1){
  zetasql::ResolvedCollation *col = (zetasql::ResolvedCollation *)arg0;
  GET_LIST(col->child_list, arg1);
}

void GO_EXPORT(ResolvedCollation_DebugString)(void * arg0,void ** arg1){
  zetasql::ResolvedCollation *col = (zetasql::ResolvedCollation *)arg0;
  *arg1 = (void *)((new std::string(col->DebugString()))->c_str());
}

void GO_EXPORT(ResolvedFunctionCallInfo_DebugString)(void * arg0,void ** arg1){
  zetasql::ResolvedFunctionCallInfo *info = (zetasql::ResolvedFunctionCallInfo *)arg0;
  *arg1 = (void *)((new std::string(info->DebugString()))->c_str());
}
