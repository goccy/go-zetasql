static zetasql::ResolvedExpr *nodeToExpr(zetasql::ResolvedNode *node)
{
  switch (node->node_kind()) {
  case zetasql::RESOLVED_LITERAL:
  case zetasql::RESOLVED_PARAMETER:
  case zetasql::RESOLVED_EXPRESSION_COLUMN:
  case zetasql::RESOLVED_COLUMN_REF:
  case zetasql::RESOLVED_CONSTANT:
  case zetasql::RESOLVED_SYSTEM_VARIABLE:
  case zetasql::RESOLVED_INLINE_LAMBDA:
  case zetasql::RESOLVED_FILTER_FIELD_ARG:
  case zetasql::RESOLVED_FILTER_FIELD:
  case zetasql::RESOLVED_FUNCTION_CALL:
  case zetasql::RESOLVED_AGGREGATE_FUNCTION_CALL:
  case zetasql::RESOLVED_ANALYTIC_FUNCTION_CALL:
  case zetasql::RESOLVED_EXTENDED_CAST_ELEMENT:
  case zetasql::RESOLVED_EXTENDED_CAST:
  case zetasql::RESOLVED_CAST:
  case zetasql::RESOLVED_MAKE_STRUCT:
  case zetasql::RESOLVED_MAKE_PROTO:
  case zetasql::RESOLVED_MAKE_PROTO_FIELD:
  case zetasql::RESOLVED_GET_STRUCT_FIELD:
  case zetasql::RESOLVED_GET_PROTO_FIELD:
  case zetasql::RESOLVED_GET_JSON_FIELD:
  case zetasql::RESOLVED_FLATTEN:
  case zetasql::RESOLVED_FLATTENED_ARG:
  case zetasql::RESOLVED_REPLACE_FIELD_ITEM:
  case zetasql::RESOLVED_REPLACE_FIELD:
  case zetasql::RESOLVED_SUBQUERY_EXPR:
  case zetasql::RESOLVED_LET_EXPR:
  case zetasql::RESOLVED_MODEL:
  case zetasql::RESOLVED_CONNECTION:
  case zetasql::RESOLVED_DESCRIPTOR:
  case zetasql::RESOLVED_SINGLE_ROW_SCAN:
  case zetasql::RESOLVED_TABLE_SCAN:
  case zetasql::RESOLVED_JOIN_SCAN:
  case zetasql::RESOLVED_ARRAY_SCAN:
  case zetasql::RESOLVED_COLUMN_HOLDER:
  case zetasql::RESOLVED_FILTER_SCAN:
  case zetasql::RESOLVED_GROUPING_SET:
  case zetasql::RESOLVED_AGGREGATE_SCAN:
  case zetasql::RESOLVED_ANONYMIZED_AGGREGATE_SCAN:
  case zetasql::RESOLVED_SET_OPERATION_ITEM:
  case zetasql::RESOLVED_SET_OPERATION_SCAN:
  case zetasql::RESOLVED_ORDER_BY_SCAN:
  case zetasql::RESOLVED_LIMIT_OFFSET_SCAN:
  case zetasql::RESOLVED_WITH_REF_SCAN:
  case zetasql::RESOLVED_ANALYTIC_SCAN:
  case zetasql::RESOLVED_SAMPLE_SCAN:
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
  case zetasql::RESOLVED_PROJECT_SCAN:
  case zetasql::RESOLVED_TVFSCAN:
  case zetasql::RESOLVED_GROUP_ROWS_SCAN:
  case zetasql::RESOLVED_FUNCTION_ARGUMENT:
  case zetasql::RESOLVED_EXPLAIN_STMT:
  case zetasql::RESOLVED_QUERY_STMT:
  case zetasql::RESOLVED_CREATE_DATABASE_STMT:
  case zetasql::RESOLVED_INDEX_ITEM:
  case zetasql::RESOLVED_UNNEST_ITEM:
  case zetasql::RESOLVED_CREATE_INDEX_STMT:
  case zetasql::RESOLVED_CREATE_SCHEMA_STMT:
  case zetasql::RESOLVED_CREATE_TABLE_STMT:
  case zetasql::RESOLVED_CREATE_TABLE_AS_SELECT_STMT:
  case zetasql::RESOLVED_CREATE_MODEL_STMT:
  case zetasql::RESOLVED_CREATE_VIEW_STMT:
  case zetasql::RESOLVED_WITH_PARTITION_COLUMNS:
  case zetasql::RESOLVED_CREATE_SNAPSHOT_TABLE_STMT:
  case zetasql::RESOLVED_CREATE_EXTERNAL_TABLE_STMT:
  case zetasql::RESOLVED_EXPORT_MODEL_STMT:
  case zetasql::RESOLVED_EXPORT_DATA_STMT:
  case zetasql::RESOLVED_DEFINE_TABLE_STMT:
  case zetasql::RESOLVED_DESCRIBE_STMT:
  case zetasql::RESOLVED_SHOW_STMT:
  case zetasql::RESOLVED_BEGIN_STMT:
  case zetasql::RESOLVED_SET_TRANSACTION_STMT:
  case zetasql::RESOLVED_COMMIT_STMT:
  case zetasql::RESOLVED_ROLLBACK_STMT:
  case zetasql::RESOLVED_START_BATCH_STMT:
  case zetasql::RESOLVED_RUN_BATCH_STMT:
  case zetasql::RESOLVED_ABORT_BATCH_STMT:
  case zetasql::RESOLVED_DROP_STMT:
  case zetasql::RESOLVED_DROP_MATERIALIZED_VIEW_STMT:
  case zetasql::RESOLVED_DROP_SNAPSHOT_TABLE_STMT:
  case zetasql::RESOLVED_RECURSIVE_REF_SCAN:
  case zetasql::RESOLVED_RECURSIVE_SCAN:
  case zetasql::RESOLVED_WITH_SCAN:
  case zetasql::RESOLVED_WITH_ENTRY:
  case zetasql::RESOLVED_OPTION:
  case zetasql::RESOLVED_WINDOW_PARTITIONING:
  case zetasql::RESOLVED_WINDOW_ORDERING:
  case zetasql::RESOLVED_WINDOW_FRAME:
  case zetasql::RESOLVED_ANALYTIC_FUNCTION_GROUP:
  case zetasql::RESOLVED_WINDOW_FRAME_EXPR:
  case zetasql::RESOLVED_DMLVALUE:
  case zetasql::RESOLVED_DMLDEFAULT:
  case zetasql::RESOLVED_ASSERT_STMT:
  case zetasql::RESOLVED_ASSERT_ROWS_MODIFIED:
  case zetasql::RESOLVED_INSERT_ROW:
  case zetasql::RESOLVED_INSERT_STMT:
  case zetasql::RESOLVED_DELETE_STMT:
  case zetasql::RESOLVED_UPDATE_ITEM:
  case zetasql::RESOLVED_UPDATE_ARRAY_ITEM:
  case zetasql::RESOLVED_UPDATE_STMT:
  case zetasql::RESOLVED_MERGE_WHEN:
  case zetasql::RESOLVED_MERGE_STMT:
  case zetasql::RESOLVED_TRUNCATE_STMT:
  case zetasql::RESOLVED_OBJECT_UNIT:
  case zetasql::RESOLVED_PRIVILEGE:
  case zetasql::RESOLVED_GRANT_STMT:
  case zetasql::RESOLVED_REVOKE_STMT:
  case zetasql::RESOLVED_ALTER_DATABASE_STMT:
  case zetasql::RESOLVED_ALTER_MATERIALIZED_VIEW_STMT:
  case zetasql::RESOLVED_ALTER_SCHEMA_STMT:
  case zetasql::RESOLVED_ALTER_TABLE_STMT:
  case zetasql::RESOLVED_ALTER_VIEW_STMT:
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
  case zetasql::RESOLVED_SET_COLLATE_CLAUSE:
  case zetasql::RESOLVED_ALTER_TABLE_SET_OPTIONS_STMT:
  case zetasql::RESOLVED_RENAME_STMT:
  case zetasql::RESOLVED_CREATE_PRIVILEGE_RESTRICTION_STMT:
  case zetasql::RESOLVED_CREATE_ROW_ACCESS_POLICY_STMT:
  case zetasql::RESOLVED_DROP_PRIVILEGE_RESTRICTION_STMT:
  case zetasql::RESOLVED_DROP_ROW_ACCESS_POLICY_STMT:
  case zetasql::RESOLVED_DROP_SEARCH_INDEX_STMT:
  case zetasql::RESOLVED_GRANT_TO_ACTION:
  case zetasql::RESOLVED_RESTRICT_TO_ACTION:
  case zetasql::RESOLVED_ADD_TO_RESTRICTEE_LIST_ACTION:
  case zetasql::RESOLVED_REMOVE_FROM_RESTRICTEE_LIST_ACTION:
  case zetasql::RESOLVED_FILTER_USING_ACTION:
  case zetasql::RESOLVED_REVOKE_FROM_ACTION:
  case zetasql::RESOLVED_RENAME_TO_ACTION:
  case zetasql::RESOLVED_ALTER_PRIVILEGE_RESTRICTION_STMT:
  case zetasql::RESOLVED_ALTER_ROW_ACCESS_POLICY_STMT:
  case zetasql::RESOLVED_ALTER_ALL_ROW_ACCESS_POLICIES_STMT:
  case zetasql::RESOLVED_CREATE_CONSTANT_STMT:
  case zetasql::RESOLVED_CREATE_FUNCTION_STMT:
  case zetasql::RESOLVED_ARGUMENT_DEF:
  case zetasql::RESOLVED_ARGUMENT_REF:
  case zetasql::RESOLVED_CREATE_TABLE_FUNCTION_STMT:
  case zetasql::RESOLVED_RELATION_ARGUMENT_SCAN:
  case zetasql::RESOLVED_ARGUMENT_LIST:
  case zetasql::RESOLVED_FUNCTION_SIGNATURE_HOLDER:
  case zetasql::RESOLVED_DROP_FUNCTION_STMT:
  case zetasql::RESOLVED_DROP_TABLE_FUNCTION_STMT:
  case zetasql::RESOLVED_CALL_STMT:
  case zetasql::RESOLVED_IMPORT_STMT:
  case zetasql::RESOLVED_MODULE_STMT:
  case zetasql::RESOLVED_AGGREGATE_HAVING_MODIFIER:
  case zetasql::RESOLVED_CREATE_MATERIALIZED_VIEW_STMT:
  case zetasql::RESOLVED_CREATE_PROCEDURE_STMT:
  case zetasql::RESOLVED_EXECUTE_IMMEDIATE_ARGUMENT:
  case zetasql::RESOLVED_EXECUTE_IMMEDIATE_STMT:
  case zetasql::RESOLVED_ASSIGNMENT_STMT:
  case zetasql::RESOLVED_CREATE_ENTITY_STMT:
  case zetasql::RESOLVED_ALTER_ENTITY_STMT:
  case zetasql::RESOLVED_PIVOT_COLUMN:
  case zetasql::RESOLVED_PIVOT_SCAN:
  case zetasql::RESOLVED_RETURNING_CLAUSE:
  case zetasql::RESOLVED_UNPIVOT_ARG:
  case zetasql::RESOLVED_UNPIVOT_SCAN:
  case zetasql::RESOLVED_CLONE_DATA_STMT:
  case zetasql::RESOLVED_TABLE_AND_COLUMN_INFO:
  case zetasql::RESOLVED_ANALYZE_STMT:
  case zetasql::RESOLVED_AUX_LOAD_DATA_STMT:
  default:
    break;
  }
  return nullptr;
}

void GO_EXPORT(AnalyzeStatement)(void * arg0,void * arg1,void ** arg2,void ** arg3)
{
  zetasql::AnalyzerOptions opt;
  std::unique_ptr<const zetasql::AnalyzerOutput> out;
  absl::Status ret = zetasql::AnalyzeStatement((char *)arg0, opt, (zetasql::Catalog *)arg1, nullptr, &out);
  *(std::unique_ptr<const zetasql::AnalyzerOutput> *)arg2 = std::move(out);
  *arg3 = (void *)(new absl::Status(ret));
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

void GO_EXPORT(ResolvedNode_IsScan)(void * arg0,int* arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  *arg1 = node->IsScan();
}

void GO_EXPORT(ResolvedNode_IsExpression)(void * arg0,int* arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  *arg1 = node->IsExpression();
}

void GO_EXPORT(ResolvedNode_IsStatement)(void * arg0,int* arg1)
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

void GO_EXPORT(ResolvedLiteral_has_explicit_type)(void * arg0,int* arg1)
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

void GO_EXPORT(ResolvedLiteral_preserve_in_literal_remover)(void * arg0,int* arg1)
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

void GO_EXPORT(ResolvedParameter_is_untyped)(void * arg0,int* arg1)
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

void GO_EXPORT(ResolvedColumnRef_is_correlated)(void * arg0,int* arg1)
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
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  const std::vector<std::string> &path = node->name_path();
  const char **data = (const char **)malloc(sizeof(void *) * path.size());
  for (size_t i = 0; i < path.size(); i++) {
    data[i] = (new std::string(path[i]))->c_str();
  }
  slice->data = (void *)data;
  slice->len = path.size();
  slice->cap = path.size();
  *arg1 = (void *)slice;
}

void GO_EXPORT(ResolvedSystemVariable_set_name_path)(void * arg0,void * arg1)
{
  zetasql::ResolvedSystemVariable *node = (zetasql::ResolvedSystemVariable *)arg0;
  GoSlice *slice = (GoSlice *)arg1;
  char **data = (char **)slice->data;
  std::vector<std::string> name_path;
  for (int i = 0; i < slice->len; i++) {
    name_path.push_back(data[i]);
  }
  node->set_name_path(name_path);
}

void GO_EXPORT(ResolvedSystemVariable_add_name_path)(void * arg0,void * arg1)
{
  zetasql::ResolvedSystemVariable *node = (zetasql::ResolvedSystemVariable *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedInlineLambda_argument_list)(void * arg0,void ** arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  const std::vector<zetasql::ResolvedColumn> &cols = node->argument_list();
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  zetasql::ResolvedColumn **data = (zetasql::ResolvedColumn **)malloc(sizeof(void *) * cols.size());
  for (size_t i = 0; i < cols.size(); i++) {
    data[i] = new zetasql::ResolvedColumn(cols[i]);
  }
  slice->data = (void *)data;
  slice->len = cols.size();
  slice->cap = cols.size();
  *arg1 = (void *)slice;
}

void GO_EXPORT(ResolvedInlineLambda_set_argument_list)(void * arg0,void * arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  GoSlice *slice = (GoSlice *)arg1;
  zetasql::ResolvedColumn **data = (zetasql::ResolvedColumn **)slice->data;
  std::vector<zetasql::ResolvedColumn> cols;
  for (int i = 0; i < slice->len; i++) {
    cols.push_back(*data[i]);
  }
  node->set_argument_list(cols);
}

void GO_EXPORT(ResolvedInlineLambda_add_argument)(void * arg0,void * arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  node->add_argument_list(*(zetasql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedInlineLambda_parameter_list)(void * arg0,void ** arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  const std::vector<std::unique_ptr<const zetasql::ResolvedColumnRef>> &params = node->parameter_list();
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  const zetasql::ResolvedColumnRef **data = (const zetasql::ResolvedColumnRef **)malloc(sizeof(void *) * params.size());
  for (size_t i = 0; i < params.size(); i++) {
    data[i] = params[i].get();
  }
  slice->data = (void *)data;
  slice->len = params.size();
  slice->cap = params.size();
  *arg1 = (void *)slice;
}

void GO_EXPORT(ResolvedInlineLambda_set_parameter_list)(void * arg0,void * arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  GoSlice *slice = (GoSlice *)arg1;
  zetasql::ResolvedColumnRef **data = (zetasql::ResolvedColumnRef **)slice->data;
  std::vector<std::unique_ptr<const zetasql::ResolvedColumnRef>> params;
  for (int i = 0; i < slice->len; i++) {
    auto p = zetasql::MakeResolvedColumnRef(data[i]->type(), data[i]->column(), data[i]->is_correlated());
    params.push_back(std::move(p));
  }
  node->set_parameter_list(std::move(params));
}

void GO_EXPORT(ResolvedInlineLambda_add_parameter)(void * arg0,void * arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  zetasql::ResolvedColumnRef *col = (zetasql::ResolvedColumnRef *)arg1;
  std::unique_ptr<const zetasql::ResolvedColumnRef> p = zetasql::MakeResolvedColumnRef(col->type(), col->column(), col->is_correlated());
  node->add_parameter_list(std::move(p));
}

void GO_EXPORT(ResolvedInlineLambda_body)(void * arg0,void ** arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  *arg1 = (void *)node->body();
}

void GO_EXPORT(ResolvedInlineLambda_set_body)(void * arg0,void * arg1)
{
  zetasql::ResolvedInlineLambda *node = (zetasql::ResolvedInlineLambda *)arg0;
  //node->set_body(std::make_unique<const zetasql::ResolvedLiteral>(*(const zetasql::ResolvedLiteral *)arg1));
}
