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

void GO_EXPORT(ResolvedFilterFieldArg_include)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedFilterFieldArg_set_include)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedFilterField_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFilterField_set_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFilterField_filter_field_arg_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFilterField_set_filter_field_arg_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFilterField_add_filter_field_arg_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFilterField_reset_cleared_required_fields)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedFilterField_set_reset_cleared_required_fields)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_function)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_set_function)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_signature)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_set_signature)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_argument_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_set_argument_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_add_argument_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_generic_argument_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_set_generic_argument_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_add_generic_argument_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_error_mode)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_set_error_mode)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_hint_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_set_hint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_add_hint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_collation_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_set_collation_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionCallBase_add_collation_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionCall_function_call_info)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFunctionCall_set_function_call_info)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_distinct)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_set_distinct)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_null_handling_modifier)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_set_null_handling_modifier)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_with_group_rows_subquery)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_set_with_group_rows_subquery)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_with_group_rows_parameter_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_set_with_group_rows_parameter_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_add_with_group_rows_parameter_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateFunctionCall_having_modifier)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAggregateFunctionCall_set_having_modifier)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateFunctionCall_order_by_item_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAggregateFunctionCall_set_order_by_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateFunctionCall_add_order_by_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateFunctionCall_limit)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAggregateFunctionCall_set_limit)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateFunctionCall_function_call_info)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAggregateFunctionCall_set_function_call_info)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAnalyticFunctionCall_window_frame)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAnalyticFunctionCall_set_window_frame)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExtendedCastElement_from_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExtendedCastElement_set_from_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExtendedCastElement_to_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExtendedCastElement_set_to_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExtendedCastElement_function)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExtendedCastElement_set_function)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExtendedCast_element_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExtendedCast_set_element_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExtendedCast_add_element_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCast_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCast_set_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCast_return_null_on_error)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCast_set_return_null_on_error)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCast_extended_cast)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCast_set_extended_cast)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCast_format)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCast_set_format)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCast_time_zone)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCast_set_time_zone)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCast_type_parameters)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCast_set_type_parameters)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMakeStruct_field_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedMakeStruct_set_field_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMakeStruct_add_field_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMakeProto_field_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedMakeProto_set_field_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMakeProto_add_field_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMakeProtoField_format)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedMakeProtoField_set_format)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedMakeProtoField_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedMakeProtoField_set_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGetStructField_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedGetStructField_set_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGetStructField_field_idx)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedGetStructField_set_field_idx)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedGetProtoField_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedGetProtoField_set_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGetProtoField_default_value)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedGetProtoField_set_default_value)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGetProtoField_get_has_bit)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedGetProtoField_set_get_has_bit)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedGetProtoField_format)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedGetProtoField_set_format)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedGetProtoField_return_default_value_when_unset)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedGetProtoField_set_return_default_value_when_unset)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedGetJsonField_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedGetJsonField_set_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGetJsonField_field_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedGetJsonField_set_field_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFlatten_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFlatten_set_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFlatten_get_field_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFlatten_set_get_field_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFlatten_add_get_field_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedReplaceFieldItem_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedReplaceFieldItem_set_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedReplaceFieldItem_struct_index_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedReplaceFieldItem_set_struct_index_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedReplaceFieldItem_add_struct_index_path)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedReplaceField_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedReplaceField_set_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedReplaceField_replace_field_item_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedReplaceField_set_replace_field_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedReplaceField_add_replace_field_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSubqueryExpr_subquery_type)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedSubqueryExpr_set_subquery_type)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedSubqueryExpr_parameter_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSubqueryExpr_set_parameter_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSubqueryExpr_add_parameter_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSubqueryExpr_in_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSubqueryExpr_set_in_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSubqueryExpr_in_collation)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSubqueryExpr_set_in_collation)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSubqueryExpr_subquery)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSubqueryExpr_set_subquery)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSubqueryExpr_hint_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSubqueryExpr_set_hint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSubqueryExpr_add_hint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedLetExpr_assignment_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedLetExpr_set_assignment_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedLetExpr_add_assignment_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedLetExpr_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedLetExpr_set_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedScan_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedScan_set_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedScan_add_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedScan_hint_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedScan_set_hint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedScan_add_hint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedScan_is_ordered)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedScan_set_is_ordered)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedModel_model)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedModel_set_model)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedConnection_connection)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedConnection_set_connection)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDescriptor_descriptor_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDescriptor_set_descriptor_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDescriptor_add_descriptor_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDescriptor_descriptor_column_name_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDescriptor_set_descriptor_column_name_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDescriptor_add_descriptor_column_name_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTableScan_table)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedTableScan_set_table)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTableScan_for_system_time_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedTableScan_set_for_system_time_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTableScan_column_index_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedTableScan_set_column_index_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTableScan_add_column_index_list)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedTableScan_alias)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedTableScan_set_alias)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedJoinScan_join_type)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedJoinScan_set_join_type)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedJoinScan_left_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedJoinScan_set_left_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedJoinScan_right_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedJoinScan_set_right_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedJoinScan_join_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedJoinScan_set_join_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedArrayScan_input_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedArrayScan_set_input_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedArrayScan_array_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedArrayScan_set_array_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedArrayScan_element_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedArrayScan_set_element_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedArrayScan_array_offset_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedArrayScan_set_array_offset_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedArrayScan_join_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedArrayScan_set_join_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedArrayScan_is_outer)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedArrayScan_set_is_outer)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedColumnHolder_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedColumnHolder_set_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFilterScan_input_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFilterScan_set_input_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFilterScan_filter_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFilterScan_set_filter_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGroupingSet_group_by_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedGroupingSet_set_group_by_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGroupingSet_add_group_by_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateScanBase_input_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAggregateScanBase_set_input_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateScanBase_group_by_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAggregateScanBase_set_group_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateScanBase_add_group_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateScanBase_collation_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAggregateScanBase_set_collation_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateScanBase_add_collation_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateScanBase_aggregate_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAggregateScanBase_set_aggregate_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateScanBase_add_aggregate_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateScan_grouping_set_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAggregateScan_set_grouping_set_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateScan_add_grouping_set_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateScan_rollup_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAggregateScan_set_rollup_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateScan_add_rollup_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAnonymizedAggregateScan_k_threshold_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAnonymizedAggregateScan_set_k_threshold_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAnonymizedAggregateScan_anonymization_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAnonymizedAggregateScan_set_anonymization_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAnonymizedAggregateScan_add_anonymization_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSetOperationItem_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSetOperationItem_set_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSetOperationItem_output_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSetOperationItem_set_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSetOperationItem_add_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSetOperationScan_op_type)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedSetOperationScan_set_op_type)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedSetOperationScan_input_item_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSetOperationScan_set_input_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSetOperationScan_add_input_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedOrderByScan_input_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedOrderByScan_set_input_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedOrderByScan_order_by_item_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedOrderByScan_set_order_by_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedOrderByScan_add_order_by_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedLimitOffsetScan_input_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedLimitOffsetScan_set_input_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedLimitOffsetScan_limit)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedLimitOffsetScan_set_limit)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedLimitOffsetScan_offset)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedLimitOffsetScan_set_offset)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWithRefScan_with_query_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedWithRefScan_set_with_query_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAnalyticScan_input_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAnalyticScan_set_input_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAnalyticScan_function_group_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAnalyticScan_set_function_group_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAnalyticScan_add_function_group_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSampleScan_input_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSampleScan_set_input_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSampleScan_method)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSampleScan_set_method)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSampleScan_size)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSampleScan_set_size)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSampleScan_unit)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedSampleScan_set_unit)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedSampleScan_repeatable_argument)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSampleScan_set_repeatable_argument)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSampleScan_weight_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSampleScan_set_weight_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSampleScan_partition_by_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSampleScan_set_partition_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSampleScan_add_partition_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedComputedColumn_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedComputedColumn_set_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedComputedColumn_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedComputedColumn_set_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedOrderByItem_column_ref)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedOrderByItem_set_column_ref)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedOrderByItem_collation_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedOrderByItem_set_collation_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedOrderByItem_is_descending)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedOrderByItem_set_is_descending)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedOrderByItem_null_order)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedOrderByItem_set_null_order)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedOrderByItem_collation)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedOrderByItem_set_collation)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedColumnAnnotations_collation_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedColumnAnnotations_set_collation_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedColumnAnnotations_not_null)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedColumnAnnotations_set_not_null)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedColumnAnnotations_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedColumnAnnotations_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedColumnAnnotations_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedColumnAnnotations_child_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedColumnAnnotations_set_child_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedColumnAnnotations_add_child_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedColumnAnnotations_type_parameters)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedColumnAnnotations_set_type_parameters)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGeneratedColumnInfo_expression)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedGeneratedColumnInfo_set_expression)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGeneratedColumnInfo_stored_mode)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedGeneratedColumnInfo_set_stored_mode)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedColumnDefaultValue_expression)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedColumnDefaultValue_set_expression)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedColumnDefaultValue_sql)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedColumnDefaultValue_set_sql)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedColumnDefinition_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedColumnDefinition_set_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedColumnDefinition_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedColumnDefinition_set_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedColumnDefinition_annotations)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedColumnDefinition_set_annotations)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedColumnDefinition_is_hidden)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedColumnDefinition_set_is_hidden)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedColumnDefinition_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedColumnDefinition_set_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedColumnDefinition_generated_column_info)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedColumnDefinition_set_generated_column_info)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedColumnDefinition_default_value)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedColumnDefinition_set_default_value)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPrimaryKey_column_offset_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedPrimaryKey_set_column_offset_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPrimaryKey_add_column_offset_list)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedPrimaryKey_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedPrimaryKey_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPrimaryKey_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPrimaryKey_unenforced)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedPrimaryKey_set_unenforced)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedPrimaryKey_constraint_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedPrimaryKey_set_constraint_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPrimaryKey_column_name_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedPrimaryKey_set_column_name_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPrimaryKey_add_column_name_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedForeignKey_constraint_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedForeignKey_set_constraint_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedForeignKey_referencing_column_offset_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedForeignKey_set_referencing_column_offset_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedForeignKey_add_referencing_column_offset_list)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedForeignKey_referenced_table)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedForeignKey_set_referenced_table)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedForeignKey_referenced_column_offset_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedForeignKey_set_referenced_column_offset_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedForeignKey_add_referenced_column_offset_list)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedForeignKey_match_mode)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedForeignKey_set_match_mode)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedForeignKey_update_action)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedForeignKey_set_update_action)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedForeignKey_delete_action)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedForeignKey_set_delete_action)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedForeignKey_enforced)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedForeignKey_set_enforced)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedForeignKey_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedForeignKey_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedForeignKey_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedForeignKey_referencing_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedForeignKey_set_referencing_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedForeignKey_add_referencing_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCheckConstraint_constraint_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCheckConstraint_set_constraint_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCheckConstraint_expression)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCheckConstraint_set_expression)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCheckConstraint_enforced)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCheckConstraint_set_enforced)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCheckConstraint_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCheckConstraint_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCheckConstraint_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedOutputColumn_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedOutputColumn_set_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedOutputColumn_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedOutputColumn_set_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedProjectScan_expr_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedProjectScan_set_expr_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedProjectScan_add_expr_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedProjectScan_input_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedProjectScan_set_input_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTVFScan_tvf)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedTVFScan_set_tvf)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTVFScan_signature)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedTVFScan_set_signature)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTVFScan_argument_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedTVFScan_set_argument_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTVFScan_add_argument_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTVFScan_column_index_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedTVFScan_set_column_index_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTVFScan_add_column_index_list)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedTVFScan_alias)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedTVFScan_set_alias)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTVFScan_function_call_signature)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedTVFScan_set_function_call_signature)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGroupRowsScan_input_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedGroupRowsScan_set_input_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGroupRowsScan_add_input_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGroupRowsScan_alias)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedGroupRowsScan_set_alias)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionArgument_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFunctionArgument_set_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionArgument_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFunctionArgument_set_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionArgument_model)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFunctionArgument_set_model)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionArgument_connection)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFunctionArgument_set_connection)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionArgument_descriptor_arg)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFunctionArgument_set_descriptor_arg)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionArgument_argument_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFunctionArgument_set_argument_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionArgument_add_argument_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionArgument_inline_lambda)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFunctionArgument_set_inline_lambda)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedStatement_hint_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedStatement_set_hint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedStatement_add_hint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExplainStmt_statement)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExplainStmt_set_statement)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedQueryStmt_output_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedQueryStmt_set_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedQueryStmt_add_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedQueryStmt_is_value_table)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedQueryStmt_set_is_value_table)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedQueryStmt_query)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedQueryStmt_set_query)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateStatement_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateStatement_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateStatement_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateStatement_create_scope)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateStatement_set_create_scope)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateStatement_create_mode)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateStatement_set_create_mode)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedIndexItem_column_ref)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedIndexItem_set_column_ref)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedIndexItem_descending)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedIndexItem_set_descending)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedUnnestItem_array_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUnnestItem_set_array_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUnnestItem_element_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUnnestItem_set_element_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUnnestItem_array_offset_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUnnestItem_set_array_offset_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_table_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_table_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_table_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_table_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_table_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_is_unique)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_is_unique)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_is_search)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_is_search)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_index_all_columns)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_index_all_columns)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_index_item_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_index_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_index_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_storing_expression_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_storing_expression_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_storing_expression_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_computed_columns_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_computed_columns_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_computed_columns_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_unnest_expressions_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_unnest_expressions_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_unnest_expressions_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateSchemaStmt_collation_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateSchemaStmt_set_collation_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateSchemaStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateSchemaStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateSchemaStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_column_definition_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_column_definition_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_add_column_definition_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_pseudo_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_pseudo_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_add_pseudo_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_primary_key)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_primary_key)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_foreign_key_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_foreign_key_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_add_foreign_key_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_check_constraint_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_check_constraint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_add_check_constraint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_is_value_table)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_is_value_table)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_like_table)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_like_table)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_collation_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_collation_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmt_clone_from)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableStmt_set_clone_from)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmt_copy_from)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableStmt_set_copy_from)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmt_partition_by_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableStmt_set_partition_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmt_add_partition_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmt_cluster_by_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableStmt_set_cluster_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableStmt_add_cluster_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_partition_by_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_set_partition_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_add_partition_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_cluster_by_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_set_cluster_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_add_cluster_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_output_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_set_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_add_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_query)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_set_query)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_output_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_set_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_add_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_query)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_set_query)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_transform_input_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_set_transform_input_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_add_transform_input_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_transform_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_set_transform_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_add_transform_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_transform_output_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_set_transform_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_add_transform_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_transform_analytic_function_group_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_set_transform_analytic_function_group_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateModelStmt_add_transform_analytic_function_group_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_output_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_set_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_add_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_has_explicit_columns)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_set_has_explicit_columns)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_query)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_set_query)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_sql)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_set_sql)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_sql_security)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_set_sql_security)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_is_value_table)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_set_is_value_table)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_recursive)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateViewBase_set_recursive)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedWithPartitionColumns_column_definition_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedWithPartitionColumns_set_column_definition_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWithPartitionColumns_add_column_definition_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateSnapshotTableStmt_clone_from)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateSnapshotTableStmt_set_clone_from)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateSnapshotTableStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateSnapshotTableStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateSnapshotTableStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateExternalTableStmt_with_partition_columns)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateExternalTableStmt_set_with_partition_columns)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateExternalTableStmt_connection)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateExternalTableStmt_set_connection)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExportModelStmt_model_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExportModelStmt_set_model_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExportModelStmt_add_model_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExportModelStmt_connection)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExportModelStmt_set_connection)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExportModelStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExportModelStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExportModelStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExportDataStmt_connection)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExportDataStmt_set_connection)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExportDataStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExportDataStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExportDataStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExportDataStmt_output_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExportDataStmt_set_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExportDataStmt_add_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExportDataStmt_is_value_table)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedExportDataStmt_set_is_value_table)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedExportDataStmt_query)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExportDataStmt_set_query)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDefineTableStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDefineTableStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDefineTableStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDefineTableStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDefineTableStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDefineTableStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDescribeStmt_object_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDescribeStmt_set_object_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDescribeStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDescribeStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDescribeStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDescribeStmt_from_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDescribeStmt_set_from_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDescribeStmt_add_from_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedShowStmt_identifier)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedShowStmt_set_identifier)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedShowStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedShowStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedShowStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedShowStmt_like_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedShowStmt_set_like_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedBeginStmt_read_write_mode)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedBeginStmt_set_read_write_mode)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedBeginStmt_isolation_level_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedBeginStmt_set_isolation_level_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedBeginStmt_add_isolation_level_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSetTransactionStmt_read_write_mode)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedSetTransactionStmt_set_read_write_mode)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedSetTransactionStmt_isolation_level_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSetTransactionStmt_set_isolation_level_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSetTransactionStmt_add_isolation_level_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedStartBatchStmt_batch_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedStartBatchStmt_set_batch_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropStmt_object_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropStmt_set_object_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropStmt_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedDropStmt_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedDropStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropStmt_drop_mode)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedDropStmt_set_drop_mode)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedDropMaterializedViewStmt_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedDropMaterializedViewStmt_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedDropMaterializedViewStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropMaterializedViewStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropMaterializedViewStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropSnapshotTableStmt_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedDropSnapshotTableStmt_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedDropSnapshotTableStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropSnapshotTableStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropSnapshotTableStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRecursiveScan_op_type)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedRecursiveScan_set_op_type)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedRecursiveScan_non_recursive_term)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedRecursiveScan_set_non_recursive_term)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRecursiveScan_recursive_term)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedRecursiveScan_set_recursive_term)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWithScan_with_entry_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedWithScan_set_with_entry_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWithScan_add_with_entry_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWithScan_query)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedWithScan_set_query)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWithScan_recursive)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedWithScan_set_recursive)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedWithEntry_with_query_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedWithEntry_set_with_query_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWithEntry_with_subquery)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedWithEntry_set_with_subquery)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedOption_qualifier)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedOption_set_qualifier)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedOption_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedOption_set_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedOption_value)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedOption_set_value)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWindowPartitioning_partition_by_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedWindowPartitioning_set_partition_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWindowPartitioning_add_partition_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWindowPartitioning_hint_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedWindowPartitioning_set_hint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWindowPartitioning_add_hint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWindowOrdering_order_by_item_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedWindowOrdering_set_order_by_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWindowOrdering_add_order_by_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWindowOrdering_hint_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedWindowOrdering_set_hint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWindowOrdering_add_hint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWindowFrame_frame_unit)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedWindowFrame_set_frame_unit)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedWindowFrame_start_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedWindowFrame_set_start_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWindowFrame_end_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedWindowFrame_set_end_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_partition_by)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_set_partition_by)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_order_by)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_set_order_by)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_analytic_function_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_set_analytic_function_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_add_analytic_function_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedWindowFrameExpr_boundary_type)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedWindowFrameExpr_set_boundary_type)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedWindowFrameExpr_expression)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedWindowFrameExpr_set_expression)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDMLValue_value)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDMLValue_set_value)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAssertStmt_expression)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAssertStmt_set_expression)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAssertStmt_description)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAssertStmt_set_description)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAssertRowsModified_rows)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAssertRowsModified_set_rows)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedInsertRow_value_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedInsertRow_set_value_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedInsertRow_add_value_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedInsertStmt_table_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedInsertStmt_set_table_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedInsertStmt_insert_mode)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedInsertStmt_set_insert_mode)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedInsertStmt_assert_rows_modified)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedInsertStmt_set_assert_rows_modified)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedInsertStmt_returning)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedInsertStmt_set_returning)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedInsertStmt_insert_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedInsertStmt_set_insert_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedInsertStmt_add_insert_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedInsertStmt_query_parameter_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedInsertStmt_set_query_parameter_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedInsertStmt_add_query_parameter_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedInsertStmt_query)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedInsertStmt_set_query)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedInsertStmt_query_output_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedInsertStmt_set_query_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedInsertStmt_add_query_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedInsertStmt_row_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedInsertStmt_set_row_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedInsertStmt_add_row_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDeleteStmt_table_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDeleteStmt_set_table_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDeleteStmt_assert_rows_modified)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDeleteStmt_set_assert_rows_modified)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDeleteStmt_returning)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDeleteStmt_set_returning)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDeleteStmt_array_offset_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDeleteStmt_set_array_offset_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDeleteStmt_where_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDeleteStmt_set_where_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateItem_target)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateItem_set_target)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateItem_set_value)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateItem_set_set_value)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateItem_element_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateItem_set_element_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateItem_array_update_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateItem_set_array_update_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateItem_add_array_update_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateItem_delete_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateItem_set_delete_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateItem_add_delete_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateItem_update_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateItem_set_update_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateItem_add_update_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateItem_insert_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateItem_set_insert_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateItem_add_insert_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateArrayItem_offset)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateArrayItem_set_offset)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateArrayItem_update_item)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateArrayItem_set_update_item)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_table_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_set_table_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_column_access_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_set_column_access_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_add_column_access_list)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_assert_rows_modified)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_set_assert_rows_modified)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_returning)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_set_returning)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_array_offset_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_set_array_offset_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_where_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_set_where_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_update_item_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_set_update_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_add_update_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_from_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUpdateStmt_set_from_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMergeWhen_match_type)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedMergeWhen_set_match_type)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedMergeWhen_match_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedMergeWhen_set_match_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMergeWhen_action_type)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedMergeWhen_set_action_type)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedMergeWhen_insert_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedMergeWhen_set_insert_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMergeWhen_add_insert_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMergeWhen_insert_row)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedMergeWhen_set_insert_row)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMergeWhen_update_item_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedMergeWhen_set_update_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMergeWhen_add_update_item_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMergeStmt_table_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedMergeStmt_set_table_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMergeStmt_column_access_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedMergeStmt_set_column_access_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMergeStmt_add_column_access_list)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedMergeStmt_from_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedMergeStmt_set_from_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMergeStmt_merge_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedMergeStmt_set_merge_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMergeStmt_when_clause_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedMergeStmt_set_when_clause_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedMergeStmt_add_when_clause_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTruncateStmt_table_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedTruncateStmt_set_table_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTruncateStmt_where_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedTruncateStmt_set_where_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedObjectUnit_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedObjectUnit_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedObjectUnit_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPrivilege_action_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedPrivilege_set_action_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPrivilege_unit_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedPrivilege_set_unit_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPrivilege_add_unit_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_privilege_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_set_privilege_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_add_privilege_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_object_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_set_object_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_grantee_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_set_grantee_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_add_grantee_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_grantee_expr_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_set_grantee_expr_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_add_grantee_expr_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterObjectStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterObjectStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterObjectStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterObjectStmt_alter_action_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterObjectStmt_set_alter_action_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterObjectStmt_add_alter_action_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterObjectStmt_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedAlterObjectStmt_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedAlterColumnAction_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedAlterColumnAction_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedAlterColumnAction_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterColumnAction_set_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSetOptionsAction_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSetOptionsAction_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSetOptionsAction_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAddColumnAction_is_if_not_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedAddColumnAction_set_is_if_not_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedAddColumnAction_column_definition)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAddColumnAction_set_column_definition)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAddConstraintAction_is_if_not_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedAddConstraintAction_set_is_if_not_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedAddConstraintAction_constraint)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAddConstraintAction_set_constraint)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAddConstraintAction_table)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAddConstraintAction_set_table)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropConstraintAction_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedDropConstraintAction_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedDropConstraintAction_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropConstraintAction_set_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropPrimaryKeyAction_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedDropPrimaryKeyAction_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedAlterColumnOptionsAction_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterColumnOptionsAction_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterColumnOptionsAction_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_updated_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_set_updated_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_updated_type_parameters)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_updated_annotations)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_set_updated_annotations)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterColumnSetDefaultAction_default_value)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterColumnSetDefaultAction_set_default_value)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropColumnAction_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedDropColumnAction_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedDropColumnAction_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropColumnAction_set_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRenameColumnAction_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedRenameColumnAction_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedRenameColumnAction_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedRenameColumnAction_set_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRenameColumnAction_new_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedRenameColumnAction_set_new_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSetAsAction_entity_body_json)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSetAsAction_set_entity_body_json)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSetAsAction_entity_body_text)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSetAsAction_set_entity_body_text)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedSetCollateClause_collation_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedSetCollateClause_set_collation_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedRenameStmt_object_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedRenameStmt_set_object_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRenameStmt_old_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedRenameStmt_set_old_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRenameStmt_add_old_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRenameStmt_new_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedRenameStmt_set_new_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRenameStmt_add_new_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_object_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_set_object_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_restrictee_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_create_mode)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_create_mode)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_target_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_target_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_add_target_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_grantee_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_grantee_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_add_grantee_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_grantee_expr_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_table_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_table_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_predicate)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_predicate)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_predicate_str)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_predicate_str)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_object_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_set_object_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_column_privilege_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_is_drop_all)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_set_is_drop_all)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_set_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_target_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_set_target_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_add_target_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_set_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_table_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_set_table_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_add_table_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGrantToAction_grantee_expr_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedGrantToAction_set_grantee_expr_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedGrantToAction_add_grantee_expr_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRestrictToAction_restrictee_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedRestrictToAction_set_restrictee_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRestrictToAction_add_restrictee_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAddToRestricteeListAction_is_if_not_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedAddToRestricteeListAction_set_is_if_not_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedAddToRestricteeListAction_restrictee_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAddToRestricteeListAction_set_restrictee_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAddToRestricteeListAction_add_restrictee_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRemoveFromRestricteeListAction_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedRemoveFromRestricteeListAction_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedRemoveFromRestricteeListAction_restrictee_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedRemoveFromRestricteeListAction_set_restrictee_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRemoveFromRestricteeListAction_add_restrictee_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFilterUsingAction_predicate)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFilterUsingAction_set_predicate)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFilterUsingAction_predicate_str)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFilterUsingAction_set_predicate_str)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRevokeFromAction_revokee_expr_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedRevokeFromAction_set_revokee_expr_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRevokeFromAction_add_revokee_expr_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRevokeFromAction_is_revoke_from_all)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedRevokeFromAction_set_is_revoke_from_all)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedRenameToAction_new_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedRenameToAction_set_new_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRenameToAction_add_new_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterPrivilegeRestrictionStmt_object_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterPrivilegeRestrictionStmt_set_object_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterRowAccessPolicyStmt_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterRowAccessPolicyStmt_set_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterRowAccessPolicyStmt_table_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterRowAccessPolicyStmt_set_table_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterAllRowAccessPoliciesStmt_table_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateConstantStmt_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateConstantStmt_set_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_has_explicit_return_type)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_has_explicit_return_type)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_return_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_return_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_argument_name_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_argument_name_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_add_argument_name_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_signature)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_signature)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_is_aggregate)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_is_aggregate)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_language)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_language)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_code)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_code)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_aggregate_expression_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_aggregate_expression_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_add_aggregate_expression_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_function_expression)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_function_expression)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_sql_security)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_sql_security)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_determinism_level)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_determinism_level)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_is_remote)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_is_remote)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_connection)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_connection)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedArgumentDef_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedArgumentDef_set_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedArgumentDef_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedArgumentDef_set_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedArgumentDef_argument_kind)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedArgumentDef_set_argument_kind)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedArgumentRef_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedArgumentRef_set_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedArgumentRef_argument_kind)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedArgumentRef_set_argument_kind)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_argument_name_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_argument_name_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_add_argument_name_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_signature)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_signature)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_has_explicit_return_schema)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_language)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_language)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_code)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_code)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_query)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_query)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_output_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_add_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_is_value_table)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_is_value_table)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_sql_security)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_sql_security)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedRelationArgumentScan_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedRelationArgumentScan_set_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedRelationArgumentScan_is_value_table)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedRelationArgumentScan_set_is_value_table)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedArgumentList_arg_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedArgumentList_set_arg_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedArgumentList_add_arg_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedFunctionSignatureHolder_signature)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedFunctionSignatureHolder_set_signature)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropFunctionStmt_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedDropFunctionStmt_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedDropFunctionStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropFunctionStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropFunctionStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropFunctionStmt_arguments)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropFunctionStmt_set_arguments)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropFunctionStmt_signature)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropFunctionStmt_set_signature)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropTableFunctionStmt_is_if_exists)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedDropTableFunctionStmt_set_is_if_exists)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedDropTableFunctionStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedDropTableFunctionStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedDropTableFunctionStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCallStmt_procedure)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCallStmt_set_procedure)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCallStmt_signature)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCallStmt_set_signature)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCallStmt_argument_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCallStmt_set_argument_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCallStmt_add_argument_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedImportStmt_import_kind)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedImportStmt_set_import_kind)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedImportStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedImportStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedImportStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedImportStmt_file_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedImportStmt_set_file_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedImportStmt_alias_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedImportStmt_set_alias_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedImportStmt_add_alias_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedImportStmt_into_alias_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedImportStmt_set_into_alias_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedImportStmt_add_into_alias_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedImportStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedImportStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedImportStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedModuleStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedModuleStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedModuleStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedModuleStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedModuleStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedModuleStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAggregateHavingModifier_kind)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedAggregateHavingModifier_set_kind)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedAggregateHavingModifier_having_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAggregateHavingModifier_set_having_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_column_definition_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_set_column_definition_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_add_column_definition_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_partition_by_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_set_partition_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_add_partition_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_cluster_by_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_set_cluster_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_add_cluster_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateProcedureStmt_argument_name_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateProcedureStmt_set_argument_name_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateProcedureStmt_add_argument_name_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateProcedureStmt_signature)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateProcedureStmt_set_signature)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateProcedureStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateProcedureStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateProcedureStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateProcedureStmt_procedure_body)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateProcedureStmt_set_procedure_body)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExecuteImmediateArgument_name)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExecuteImmediateArgument_set_name)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExecuteImmediateArgument_expression)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExecuteImmediateArgument_set_expression)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_sql)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_set_sql)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_into_identifier_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_set_into_identifier_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_add_into_identifier_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_using_argument_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_set_using_argument_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_add_using_argument_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAssignmentStmt_target)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAssignmentStmt_set_target)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAssignmentStmt_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAssignmentStmt_set_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateEntityStmt_entity_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateEntityStmt_set_entity_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateEntityStmt_entity_body_json)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateEntityStmt_set_entity_body_json)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateEntityStmt_entity_body_text)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateEntityStmt_set_entity_body_text)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateEntityStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCreateEntityStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCreateEntityStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAlterEntityStmt_entity_type)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAlterEntityStmt_set_entity_type)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPivotColumn_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedPivotColumn_set_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPivotColumn_pivot_expr_index)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedPivotColumn_set_pivot_expr_index)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedPivotColumn_pivot_value_index)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedPivotColumn_set_pivot_value_index)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedPivotScan_input_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedPivotScan_set_input_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPivotScan_group_by_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedPivotScan_set_group_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPivotScan_add_group_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPivotScan_pivot_expr_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedPivotScan_set_pivot_expr_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPivotScan_add_pivot_expr_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPivotScan_for_expr)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedPivotScan_set_for_expr)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPivotScan_pivot_value_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedPivotScan_set_pivot_value_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPivotScan_add_pivot_value_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPivotScan_pivot_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedPivotScan_set_pivot_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedPivotScan_add_pivot_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedReturningClause_output_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedReturningClause_set_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedReturningClause_add_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedReturningClause_action_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedReturningClause_set_action_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedReturningClause_expr_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedReturningClause_set_expr_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedReturningClause_add_expr_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUnpivotArg_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUnpivotArg_set_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUnpivotArg_add_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_input_scan)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_set_input_scan)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_value_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_set_value_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_add_value_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_label_column)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_set_label_column)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_label_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_set_label_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_add_label_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_unpivot_arg_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_set_unpivot_arg_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_add_unpivot_arg_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_projected_input_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_set_projected_input_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_add_projected_input_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_include_nulls)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedUnpivotScan_set_include_nulls)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedCloneDataStmt_target_table)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCloneDataStmt_set_target_table)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedCloneDataStmt_clone_from)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedCloneDataStmt_set_clone_from)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTableAndColumnInfo_table)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedTableAndColumnInfo_set_table)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTableAndColumnInfo_column_index_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedTableAndColumnInfo_set_column_index_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedTableAndColumnInfo_add_column_index_list)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedAnalyzeStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAnalyzeStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAnalyzeStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAnalyzeStmt_table_and_column_index_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAnalyzeStmt_set_table_and_column_index_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAnalyzeStmt_add_table_and_column_index_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_insertion_mode)(void * arg0,int* arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_insertion_mode)(void * arg0,int arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_name_path)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_name_path)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_output_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_output_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_column_definition_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_column_definition_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_column_definition_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_pseudo_column_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_pseudo_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_pseudo_column_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_primary_key)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_primary_key)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_foreign_key_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_foreign_key_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_foreign_key_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_check_constraint_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_check_constraint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_check_constraint_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_partition_by_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_partition_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_partition_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_cluster_by_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_cluster_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_cluster_by_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_with_partition_columns)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_with_partition_columns)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_connection)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_connection)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_from_files_option_list)(void * arg0,void ** arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_from_files_option_list)(void * arg0,void * arg1){
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_from_files_option_list)(void * arg0,void * arg1){
}

