void GO_EXPORT(ParseStatement)(void * arg0,void * arg1,void ** arg2,void ** arg3) {
  absl::string_view s = absl::string_view((char *)arg0);
  zetasql::ParserOptions opt;
  if (arg1 != nullptr) {
    opt = *(zetasql::ParserOptions *)arg1;
  }
  std::unique_ptr<zetasql::ParserOutput> out;
  absl::Status ret = zetasql::ParseStatement(s, opt, &out);
  *(std::unique_ptr<zetasql::ParserOutput> *)arg2 = std::move(out);
  *arg3 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(ParseScript)(void * arg0,void * arg1,int arg2,void ** arg3,void ** arg4)
{
  absl::string_view s = absl::string_view((char *)arg0);
  zetasql::ParserOptions opt;
  if (arg1 != nullptr) {
    opt = *(zetasql::ParserOptions *)arg1;
  }
  std::unique_ptr<zetasql::ParserOutput> out;
  absl::Status ret = zetasql::ParseScript(s, opt, (zetasql::ErrorMessageMode)arg2, &out);
  *(std::unique_ptr<zetasql::ParserOutput> *)arg3 = std::move(out);
  *arg4 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(ParseNextStatement)(void * arg0,void * arg1,void ** arg2,char* arg3,void ** arg4)
{
  zetasql::ParseResumeLocation *loc = (zetasql::ParseResumeLocation *)arg0;
  zetasql::ParserOptions opt;
  if (arg1 != nullptr) {
    opt = *(zetasql::ParserOptions *)arg1;
  }
  std::unique_ptr<zetasql::ParserOutput> out;
  bool endOfInput;
  absl::Status ret = zetasql::ParseNextStatement(loc, opt, &out, &endOfInput);
  *(std::unique_ptr<zetasql::ParserOutput> *)arg2 = std::move(out);
  *arg3 = endOfInput;
  *arg4 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(ParseNextScriptStatement)(void * arg0,void * arg1,void ** arg2,char* arg3,void ** arg4)
{
  zetasql::ParseResumeLocation *loc = (zetasql::ParseResumeLocation *)arg0;
  zetasql::ParserOptions opt;
  if (arg1 != nullptr) {
    opt = *(zetasql::ParserOptions *)arg1;
  }
  std::unique_ptr<zetasql::ParserOutput> out;
  bool endOfInput;
  absl::Status ret = zetasql::ParseNextScriptStatement(loc, opt, &out, &endOfInput);
  *(std::unique_ptr<zetasql::ParserOutput> *)arg2 = std::move(out);
  *arg3 = endOfInput;
  *arg4 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(ParseType)(void * arg0,void * arg1,void ** arg2,void ** arg3)
{
  zetasql::ParserOptions opt;
  if (arg1 != nullptr) {
    opt = *(zetasql::ParserOptions *)arg1;
  }
  std::unique_ptr<zetasql::ParserOutput> out;
  absl::Status ret = zetasql::ParseStatement(absl::string_view((char *)arg0), opt, &out);
  *(std::unique_ptr<zetasql::ParserOutput> *)arg2 = std::move(out);
  *arg3 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(ParseExpression)(void * arg0,void * arg1,void ** arg2,void ** arg3)
{
  zetasql::ParserOptions opt;
  if (arg1 != nullptr) {
    opt = *(zetasql::ParserOptions *)arg1;
  }
  std::unique_ptr<zetasql::ParserOutput> out;
  absl::Status ret = zetasql::ParseExpression(absl::string_view((char *)arg0), opt, &out);
  *(std::unique_ptr<zetasql::ParserOutput> *)arg2 = std::move(out);
  *arg3 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(Unparse)(void * arg0,void ** arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = (void *)((new std::string(zetasql::Unparse(node)))->c_str());
}

void GO_EXPORT(ParseResumeLocation_FromStringView)(void * arg0,void ** arg1)
{
  zetasql::ParseResumeLocation ret = zetasql::ParseResumeLocation::FromStringView((char *)arg0);
  *arg1 = new zetasql::ParseResumeLocation(ret);
}

void GO_EXPORT(Status_OK)(void * arg0,char* arg1){
  absl::Status *status = (absl::Status *)arg0;
  *arg1 = status->ok();
}

void GO_EXPORT(Status_String)(void * arg0,void ** arg1){
  absl::Status *status = (absl::Status *)arg0;
  *arg1 = (void *)((new std::string(status->ToString()))->c_str());
}

void GO_EXPORT(ParserOptions_new)(void ** arg0)
{
  *arg0 = (void *)(new zetasql::ParserOptions());
}

void GO_EXPORT(ParserOptions_set_language_options)(void * arg0,void * arg1)
{
  zetasql::ParserOptions *opt = (zetasql::ParserOptions *)arg0;
  opt->set_language_options((const zetasql::LanguageOptions *)arg1);
}

void GO_EXPORT(ParserOptions_language_options)(void * arg0,void ** arg1)
{
  zetasql::ParserOptions *opt = (zetasql::ParserOptions *)arg0;
  *arg1 = (void *)(new zetasql::LanguageOptions(opt->language_options()));
}

void GO_EXPORT(ParserOutput_statement)(void * arg0,void ** arg1) {
  zetasql::ParserOutput *out = (zetasql::ParserOutput *)arg0;
  *arg1 = (void *)out->statement();
}

void GO_EXPORT(ParserOutput_script)(void * arg0,void ** arg1) {
  zetasql::ParserOutput *out = (zetasql::ParserOutput *)arg0;
  *arg1 = (void *)out->script();
}

void GO_EXPORT(ParserOutput_type)(void * arg0,void ** arg1) {
  zetasql::ParserOutput *out = (zetasql::ParserOutput *)arg0;
  *arg1 = (void *)out->type();
}

void GO_EXPORT(ParserOutput_expression)(void * arg0,void ** arg1) {
  zetasql::ParserOutput *out = (zetasql::ParserOutput *)arg0;
  *arg1 = (void *)out->expression();
}

void GO_EXPORT(ASTNode_getId)(void * arg0,int* arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = node->getId();
}

void GO_EXPORT(ASTNode_node_kind)(void * arg0,int* arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = node->node_kind();
}

void GO_EXPORT(ASTNode_SingleNodeDebugString)(void * arg0,void ** arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = (void *)((new std::string(node->SingleNodeDebugString()))->c_str());
}

void GO_EXPORT(ASTNode_set_parent)(void * arg0,void * arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  zetasql::ASTNode *a1 = (zetasql::ASTNode *)arg1;
  node->set_parent(a1);
}

void GO_EXPORT(ASTNode_parent)(void * arg0,void ** arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = (void *)node->parent();
}

void GO_EXPORT(ASTNode_AddChildren)(void * arg0,void * arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  absl::Span<zetasql::ASTNode* const> *a1 = (absl::Span<zetasql::ASTNode* const> *)arg1;
  node->AddChildren(*a1);
}

void GO_EXPORT(ASTNode_AddChild)(void * arg0,void * arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  zetasql::ASTNode *a1 = (zetasql::ASTNode *)arg1;
  node->AddChild(a1);
}

void GO_EXPORT(ASTNode_AddChildFront)(void * arg0,void * arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  zetasql::ASTNode *a1 = (zetasql::ASTNode *)arg1;
  node->AddChildFront(a1);
}

void GO_EXPORT(ASTNode_num_children)(void * arg0,int* arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = node->num_children();
}

void GO_EXPORT(ASTNode_child)(void * arg0,int arg1,void ** arg2)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg2 = (void *)node->child(arg1);
}

void GO_EXPORT(ASTNode_mutable_child)(void * arg0,int arg1,void ** arg2)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg2 = (void *)node->mutable_child(arg1);
}

void GO_EXPORT(ASTNode_find_child_index)(void * arg0,int arg1, int *arg2)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg2 = node->find_child_index(zetasql::ASTNodeKind(arg1));
}

void GO_EXPORT(ASTNode_DebugString)(void * arg0,int arg1,void ** arg2)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg2 = (void *)((new std::string(node->DebugString(arg1)))->c_str());
}

void GO_EXPORT(ASTNode_MoveStartLocation)(void * arg0,int arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  node->MoveStartLocation(arg1);
}

void GO_EXPORT(ASTNode_MoveStartLocationBack)(void * arg0,int arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  node->MoveStartLocationBack(arg1);
}

void GO_EXPORT(ASTNode_SetStartLocationToEndLocation)(void * arg0)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  node->SetStartLocationToEndLocation();
}

void GO_EXPORT(ASTNode_MoveEndLocationBack)(void * arg0,int arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  node->MoveEndLocationBack(arg1);
}

void GO_EXPORT(ASTNode_set_start_location)(void * arg0,void * arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  zetasql::ParseLocationPoint *a1 = (zetasql::ParseLocationPoint *)arg1;
  node->set_start_location(*a1);
}

void GO_EXPORT(ASTNode_set_end_location)(void * arg0,void * arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  zetasql::ParseLocationPoint *a1 = (zetasql::ParseLocationPoint *)arg1;
  node->set_end_location(*a1);
}

void GO_EXPORT(ASTNode_IsTableExpression)(void * arg0,char* arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = node->IsTableExpression();
}

void GO_EXPORT(ASTNode_IsQueryExpression)(void * arg0,char* arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = node->IsQueryExpression();
}

void GO_EXPORT(ASTNode_IsExpression)(void * arg0,char* arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = node->IsExpression();
}

void GO_EXPORT(ASTNode_IsType)(void * arg0,char* arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = node->IsType();
}

void GO_EXPORT(ASTNode_IsLeaf)(void * arg0,char* arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = node->IsLeaf();
}

void GO_EXPORT(ASTNode_IsStatement)(void * arg0,char* arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = node->IsStatement();
}

void GO_EXPORT(ASTNode_IsScriptStatement)(void * arg0,char* arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = node->IsScriptStatement();
}

void GO_EXPORT(ASTNode_IsLoopStatement)(void * arg0,char* arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = node->IsLoopStatement();
}

void GO_EXPORT(ASTNode_IsSqlStatement)(void * arg0,char* arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = node->IsSqlStatement();
}

void GO_EXPORT(ASTNode_IsDdlStatement)(void * arg0,char* arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = node->IsDdlStatement();
}

void GO_EXPORT(ASTNode_IsCreateStatement)(void * arg0,char* arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = node->IsCreateStatement();
}

void GO_EXPORT(ASTNode_IsAlterStatement)(void * arg0,char* arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = node->IsAlterStatement();
}

void GO_EXPORT(ASTNode_GetNodeKindString)(void * arg0,void ** arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = (void *)((new std::string(node->GetNodeKindString()))->c_str());
}

void GO_EXPORT(ASTNode_GetParseLocationRange)(void * arg0,void ** arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  zetasql::ParseLocationRange r1 = node->GetParseLocationRange();
  *arg1 = malloc(sizeof(zetasql::ParseLocationRange));
  memcpy(*arg1, &r1, sizeof(zetasql::ParseLocationRange));
}

void GO_EXPORT(ASTNode_GetLocationString)(void * arg0,void ** arg1)
{
  zetasql::ASTNode *node = (zetasql::ASTNode *)arg0;
  *arg1 = (void *)((new std::string(node->GetLocationString()))->c_str());
}

void GO_EXPORT(ASTNode_NodeKindToString)(int arg0,void ** arg1)
{
  *arg1 = (void *)((new std::string(zetasql::ASTNode::NodeKindToString((zetasql::ASTNodeKind)arg0)))->c_str());
}

void GO_EXPORT(ParseLocationPoint_filename)(void * arg0,void ** arg1)
{
  zetasql::ParseLocationPoint *p = (zetasql::ParseLocationPoint *)arg0;
  *arg1 = (void *)p->filename().data();
}

void GO_EXPORT(ParseLocationPoint_GetByteOffset)(void * arg0,int* arg1)
{
  zetasql::ParseLocationPoint *p = (zetasql::ParseLocationPoint *)arg0;
  *arg1 = p->GetByteOffset();
}

void GO_EXPORT(ParseLocationPoint_GetString)(void * arg0,void ** arg1)
{
  zetasql::ParseLocationPoint *p = (zetasql::ParseLocationPoint *)arg0;
  *arg1 = (void *)((new std::string(p->GetString()))->c_str());
}

void GO_EXPORT(ParseLocationRange_start)(void * arg0,void ** arg1)
{
  zetasql::ParseLocationRange *r = (zetasql::ParseLocationRange *)arg0;
  *arg1 = new zetasql::ParseLocationPoint(r->start());
}

void GO_EXPORT(ParseLocationRange_end)(void * arg0,void ** arg1)
{
  zetasql::ParseLocationRange *r = (zetasql::ParseLocationRange *)arg0;
  *arg1 = new zetasql::ParseLocationPoint(r->end());
}

void GO_EXPORT(ParseLocationRange_GetString)(void * arg0,void ** arg1)
{
  zetasql::ParseLocationRange *r = (zetasql::ParseLocationRange *)arg0;
  *arg1 = (void *)((new std::string(r->GetString()))->c_str());
}

void GO_EXPORT(ASTQueryStatement_query)(void * arg0,void ** arg1)
{
  zetasql::ASTQueryStatement *stmt = (zetasql::ASTQueryStatement *)arg0;
  *arg1 = (void *)stmt->query();
}

void GO_EXPORT(ASTQueryExpression_set_parenthesized)(void * arg0,int arg1)
{
  zetasql::ASTQueryExpression *expr = (zetasql::ASTQueryExpression *)arg0;
  expr->set_parenthesized(arg1);
}

void GO_EXPORT(ASTQueryExpression_parenthesized)(void * arg0,char* arg1)
{
  zetasql::ASTQueryExpression *expr = (zetasql::ASTQueryExpression *)arg0;
  *arg1 = expr->parenthesized();
}

void GO_EXPORT(ASTQuery_set_is_nested)(void * arg0,int arg1)
{
  zetasql::ASTQuery *query = (zetasql::ASTQuery *)arg0;
  query->set_is_nested(arg1);
}

void GO_EXPORT(ASTQuery_is_nested)(void * arg0,char* arg1)
{
  zetasql::ASTQuery *query = (zetasql::ASTQuery *)arg0;
  *arg1 = query->is_nested();
}

void GO_EXPORT(ASTQuery_set_is_pivot_input)(void * arg0,int arg1)
{
  zetasql::ASTQuery *query = (zetasql::ASTQuery *)arg0;
  query->set_is_pivot_input(arg1);
}

void GO_EXPORT(ASTQuery_is_pivot_input)(void * arg0,char* arg1)
{
  zetasql::ASTQuery *query = (zetasql::ASTQuery *)arg0;
  *arg1 = query->is_pivot_input();
}

void GO_EXPORT(ASTQuery_with_clause)(void * arg0,void ** arg1)
{
  zetasql::ASTQuery *query = (zetasql::ASTQuery *)arg0;
  *arg1 = (void *)query->with_clause();
}

void GO_EXPORT(ASTQuery_query_expr)(void * arg0,void ** arg1)
{
  zetasql::ASTQuery *query = (zetasql::ASTQuery *)arg0;
  *arg1 = (void *)query->query_expr();
}

void GO_EXPORT(ASTQuery_order_by)(void * arg0,void ** arg1)
{
  zetasql::ASTQuery *query = (zetasql::ASTQuery *)arg0;
  *arg1 = (void *)query->order_by();
}

void GO_EXPORT(ASTQuery_limit_offset)(void * arg0,void ** arg1)
{
  zetasql::ASTQuery *query = (zetasql::ASTQuery *)arg0;
  *arg1 = (void *)query->limit_offset();
}

void GO_EXPORT(ASTSelect_set_distinct)(void * arg0,int arg1)
{
  zetasql::ASTSelect *select = (zetasql::ASTSelect *)arg0;
  select->set_distinct(arg1);
}

void GO_EXPORT(ASTSelect_distinct)(void * arg0,char* arg1)
{
  zetasql::ASTSelect *select = (zetasql::ASTSelect *)arg0;
  *arg1 = select->distinct();
}

void GO_EXPORT(ASTSelect_hint)(void * arg0,void ** arg1)
{
  zetasql::ASTSelect *select = (zetasql::ASTSelect *)arg0;
  *arg1 = (void *)select->hint();
}

void GO_EXPORT(ASTSelect_anonymization_options)(void * arg0,void ** arg1)
{
  zetasql::ASTSelect *select = (zetasql::ASTSelect *)arg0;
  *arg1 = (void *)select->anonymization_options();
}

void GO_EXPORT(ASTSelect_select_as)(void * arg0,void ** arg1)
{
  zetasql::ASTSelect *select = (zetasql::ASTSelect *)arg0;
  *arg1 = (void *)select->select_as();
}

void GO_EXPORT(ASTSelect_select_list)(void * arg0,void ** arg1)
{
  zetasql::ASTSelect *select = (zetasql::ASTSelect *)arg0;
  *arg1 = (void *)select->select_list();
}

void GO_EXPORT(ASTSelect_from_clause)(void * arg0,void ** arg1)
{
  zetasql::ASTSelect *select = (zetasql::ASTSelect *)arg0;
  *arg1 = (void *)select->from_clause();
}

void GO_EXPORT(ASTSelect_where_clause)(void * arg0,void ** arg1)
{
  zetasql::ASTSelect *select = (zetasql::ASTSelect *)arg0;
  *arg1 = (void *)select->where_clause();
}

void GO_EXPORT(ASTSelect_group_by)(void * arg0,void ** arg1)
{
  zetasql::ASTSelect *select = (zetasql::ASTSelect *)arg0;
  *arg1 = (void *)select->group_by();
}

void GO_EXPORT(ASTSelect_having)(void * arg0,void ** arg1)
{
  zetasql::ASTSelect *select = (zetasql::ASTSelect *)arg0;
  *arg1 = (void *)select->having();
}

void GO_EXPORT(ASTSelect_qualify)(void * arg0,void ** arg1)
{
  zetasql::ASTSelect *select = (zetasql::ASTSelect *)arg0;
  *arg1 = (void *)select->qualify();
}

void GO_EXPORT(ASTSelect_window_clause)(void * arg0,void ** arg1)
{
  zetasql::ASTSelect *select = (zetasql::ASTSelect *)arg0;
  *arg1 = (void *)select->window_clause();
}

void GO_EXPORT(ASTSelectList_column_num)(void * arg0,int * arg1)
{
  zetasql::ASTSelectList *list = (zetasql::ASTSelectList *)arg0;
  *arg1 = list->columns().length();
}

void GO_EXPORT(ASTSelectList_column)(void * arg0,int arg1,void ** arg2)
{
  zetasql::ASTSelectList *list = (zetasql::ASTSelectList *)arg0;
  *arg2 = (void *)list->columns(arg1);
}

void GO_EXPORT(ASTSelectColumn_expression)(void * arg0,void ** arg1)
{
  zetasql::ASTSelectColumn *col = (zetasql::ASTSelectColumn *)arg0;
  *arg1 = (void *)col->expression();
}

void GO_EXPORT(ASTSelectColumn_alias)(void * arg0,void ** arg1)
{
  zetasql::ASTSelectColumn *col = (zetasql::ASTSelectColumn *)arg0;
  *arg1 = (void *)col->alias();
}

void GO_EXPORT(ASTExpression_set_parenthesized)(void * arg0,int arg1)
{
  zetasql::ASTExpression *expr = (zetasql::ASTExpression *)arg0;
  expr->set_parenthesized(arg1);
}

void GO_EXPORT(ASTExpression_parenthesized)(void * arg0,char* arg1)
{
  zetasql::ASTExpression *expr = (zetasql::ASTExpression *)arg0;
  *arg1 = expr->parenthesized();
}

void GO_EXPORT(ASTExpression_IsAllowedInComparison)(void * arg0,char* arg1)
{
  zetasql::ASTExpression *expr = (zetasql::ASTExpression *)arg0;
  *arg1 = expr->IsAllowedInComparison();
}

void GO_EXPORT(ASTLeaf_image)(void * arg0,void ** arg1)
{
  zetasql::ASTLeaf *leaf = (zetasql::ASTLeaf *)arg0;
  *arg1 = (void *)leaf->image().data();
}

void GO_EXPORT(ASTLeaf_set_image)(void * arg0,void * arg1)
{
  zetasql::ASTLeaf *leaf = (zetasql::ASTLeaf *)arg0;
  leaf->set_image((char *)arg1);
}

void GO_EXPORT(ASTIntLiteral_is_hex)(void * arg0,char* arg1)
{
  zetasql::ASTIntLiteral *lit = (zetasql::ASTIntLiteral *)arg0;
  *arg1 = lit->is_hex();
}

void GO_EXPORT(ASTIdentifier_GetAsString)(void * arg0,void ** arg1)
{
  zetasql::ASTIdentifier *node = (zetasql::ASTIdentifier *)arg0;
  *arg1 = (void *)((new std::string(node->GetAsString()))->c_str());
}

void GO_EXPORT(ASTIdentifier_SetIdentifier)(void * arg0,void * arg1)
{
  zetasql::ASTIdentifier *node = (zetasql::ASTIdentifier *)arg0;
  node->SetIdentifier(zetasql::IdString::MakeGlobal((char *)arg1));
}

void GO_EXPORT(ASTAlias_identifier)(void * arg0,void ** arg1)
{
  zetasql::ASTAlias *alias = (zetasql::ASTAlias *)arg0;
  *arg1 = (void *)alias->identifier();
}

void GO_EXPORT(ASTAlias_GetAsString)(void * arg0,void ** arg1)
{
  zetasql::ASTAlias *alias = (zetasql::ASTAlias *)arg0;
  *arg1 = (void *)((new std::string(alias->GetAsString()))->c_str());
}

void GO_EXPORT(ASTPathExpression_num_names)(void * arg0,int* arg1)
{
  zetasql::ASTPathExpression *expr = (zetasql::ASTPathExpression *)arg0;
  *arg1 = expr->num_names();
}

void GO_EXPORT(ASTPathExpression_name)(void * arg0,int arg1,void ** arg2)
{
  zetasql::ASTPathExpression *expr = (zetasql::ASTPathExpression *)arg0;
  *arg2 = (void *)expr->name(arg1);
}

void GO_EXPORT(ASTPathExpression_ToIdentifierPathString)(void * arg0,uint32_t arg1,void ** arg2)
{
  zetasql::ASTPathExpression *expr = (zetasql::ASTPathExpression *)arg0;
  *arg2 = (void *)((new std::string(expr->ToIdentifierPathString(arg1)))->c_str());
}

void GO_EXPORT(ASTTablePathExpression_path_expr)(void * arg0,void ** arg1)
{
  zetasql::ASTTablePathExpression *expr = (zetasql::ASTTablePathExpression *)arg0;
  *arg1 = (void *)expr->path_expr();
}

void GO_EXPORT(ASTTablePathExpression_unnest_expr)(void * arg0,void ** arg1)
{
  zetasql::ASTTablePathExpression *expr = (zetasql::ASTTablePathExpression *)arg0;
  *arg1 = (void *)expr->unnest_expr();
}

void GO_EXPORT(ASTTablePathExpression_hint)(void * arg0,void ** arg1)
{
  zetasql::ASTTablePathExpression *expr = (zetasql::ASTTablePathExpression *)arg0;
  *arg1 = (void *)expr->hint();
}

void GO_EXPORT(ASTTablePathExpression_with_offset)(void * arg0,void ** arg1)
{
  zetasql::ASTTablePathExpression *expr = (zetasql::ASTTablePathExpression *)arg0;
  *arg1 = (void *)expr->with_offset();
}

void GO_EXPORT(ASTTablePathExpression_pivot_clause)(void * arg0,void ** arg1)
{
  zetasql::ASTTablePathExpression *expr = (zetasql::ASTTablePathExpression *)arg0;
  *arg1 = (void *)expr->pivot_clause();
}

void GO_EXPORT(ASTTablePathExpression_unpivot_clause)(void * arg0,void ** arg1)
{
  zetasql::ASTTablePathExpression *expr = (zetasql::ASTTablePathExpression *)arg0;
  *arg1 = (void *)expr->unpivot_clause();
}

void GO_EXPORT(ASTTablePathExpression_for_system_time)(void * arg0,void ** arg1)
{
  zetasql::ASTTablePathExpression *expr = (zetasql::ASTTablePathExpression *)arg0;
  *arg1 = (void *)expr->for_system_time();
}

void GO_EXPORT(ASTTablePathExpression_sample_clause)(void * arg0,void ** arg1)
{
  zetasql::ASTTablePathExpression *expr = (zetasql::ASTTablePathExpression *)arg0;
  *arg1 = (void *)expr->sample_clause();
}

void GO_EXPORT(ASTTablePathExpression_alias)(void * arg0,void ** arg1)
{
  zetasql::ASTTablePathExpression *expr = (zetasql::ASTTablePathExpression *)arg0;
  *arg1 = (void *)expr->alias();
}

void GO_EXPORT(ASTFromClause_table_expression)(void * arg0,void ** arg1)
{
  zetasql::ASTFromClause *clause = (zetasql::ASTFromClause *)arg0;
  *arg1 = (void *)clause->table_expression();
}

void GO_EXPORT(ASTWhereClause_expression)(void * arg0,void ** arg1)
{
  zetasql::ASTWhereClause *clause = (zetasql::ASTWhereClause *)arg0;
  *arg1 = (void *)clause->expression();
}

void GO_EXPORT(ASTBooleanLiteral_set_value)(void * arg0,int arg1)
{
  zetasql::ASTBooleanLiteral *lit = (zetasql::ASTBooleanLiteral *)arg0;
  lit->set_value(arg1);
}

void GO_EXPORT(ASTBooleanLiteral_value)(void * arg0,char* arg1)
{
  zetasql::ASTBooleanLiteral *lit = (zetasql::ASTBooleanLiteral *)arg0;
  *arg1 = lit->value();
}

void GO_EXPORT(ASTAndExpr_conjuncts_num)(void * arg0,int* arg1)
{
  zetasql::ASTAndExpr *expr = (zetasql::ASTAndExpr *)arg0;
  *arg1 = expr->conjuncts().length();
}

void GO_EXPORT(ASTAndExpr_conjunct)(void * arg0, int arg1, void ** arg2)
{
  zetasql::ASTAndExpr *expr = (zetasql::ASTAndExpr *)arg0;
  *arg2 = (void *)expr->conjuncts(arg1);
}

void GO_EXPORT(ASTBinaryExpression_set_op)(void * arg0,int arg1)
{
  zetasql::ASTBinaryExpression *expr = (zetasql::ASTBinaryExpression *)arg0;
  expr->set_op((zetasql::ASTBinaryExpression::Op)arg1);
}

void GO_EXPORT(ASTBinaryExpression_op)(void * arg0,int* arg1)
{
  zetasql::ASTBinaryExpression *expr = (zetasql::ASTBinaryExpression *)arg0;
  *arg1 = expr->op();
}

void GO_EXPORT(ASTBinaryExpression_set_is_not)(void * arg0,int arg1)
{
  zetasql::ASTBinaryExpression *expr = (zetasql::ASTBinaryExpression *)arg0;
  expr->set_is_not(arg1);
}

void GO_EXPORT(ASTBinaryExpression_is_not)(void * arg0,char* arg1)
{
  zetasql::ASTBinaryExpression *expr = (zetasql::ASTBinaryExpression *)arg0;
  *arg1 = expr->is_not();
}

void GO_EXPORT(ASTBinaryExpression_lhs)(void * arg0,void ** arg1)
{
  zetasql::ASTBinaryExpression *expr = (zetasql::ASTBinaryExpression *)arg0;
  *arg1 = (void *)expr->lhs();
}

void GO_EXPORT(ASTBinaryExpression_rhs)(void * arg0,void ** arg1)
{
  zetasql::ASTBinaryExpression *expr = (zetasql::ASTBinaryExpression *)arg0;
  *arg1 = (void *)expr->rhs();
}

void GO_EXPORT(ASTBinaryExpression_GetSQLForOperator)(void * arg0,void ** arg1)
{
  zetasql::ASTBinaryExpression *expr = (zetasql::ASTBinaryExpression *)arg0;
  *arg1 = (void *)((new std::string(expr->GetSQLForOperator()))->c_str());
}

void GO_EXPORT(ASTStringLiteral_string_value)(void * arg0,void ** arg1)
{
  zetasql::ASTStringLiteral *lit = (zetasql::ASTStringLiteral *)arg0;
  *arg1 = (void *)((new std::string(lit->string_value()))->c_str());
}

void GO_EXPORT(ASTStringLiteral_set_string_value)(void * arg0,void * arg1)
{
  zetasql::ASTStringLiteral *lit = (zetasql::ASTStringLiteral *)arg0;
  lit->set_string_value((char *)arg1);
}

void GO_EXPORT(ASTOrExpr_disjuncts_num)(void * arg0,int* arg1){
  zetasql::ASTOrExpr *expr = (zetasql::ASTOrExpr *)arg0;
  *arg1 = expr->disjuncts().length();
}

void GO_EXPORT(ASTOrExpr_disjunct)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTOrExpr *expr = (zetasql::ASTOrExpr *)arg0;
  *arg2 = (void *)expr->disjuncts(arg1);
}

void GO_EXPORT(ASTGroupingItem_expression)(void * arg0,void ** arg1){
  zetasql::ASTGroupingItem *item = (zetasql::ASTGroupingItem *)arg0;
  *arg1 = (void *)item->expression();
}

void GO_EXPORT(ASTGroupingItem_rollup)(void * arg0,void ** arg1){
  zetasql::ASTGroupingItem *item = (zetasql::ASTGroupingItem *)arg0;
  *arg1 = (void *)item->rollup();
}

void GO_EXPORT(ASTGroupBy_hint)(void * arg0,void ** arg1){
  zetasql::ASTGroupBy *groupby = (zetasql::ASTGroupBy *)arg0;
  *arg1 = (void *)groupby->hint();
}

void GO_EXPORT(ASTGroupBy_grouping_items_num)(void * arg0,int* arg1){
  zetasql::ASTGroupBy *groupby = (zetasql::ASTGroupBy *)arg0;
  *arg1 = groupby->grouping_items().length();
}

void GO_EXPORT(ASTGroupBy_grouping_item)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTGroupBy *groupby = (zetasql::ASTGroupBy *)arg0;
  *arg2 = (void *)groupby->grouping_items(arg1);
}

void GO_EXPORT(ASTOrderingExpression_set_ordering_spec)(void * arg0,int arg1){
  zetasql::ASTOrderingExpression *node = (zetasql::ASTOrderingExpression *)arg0;
  node->set_ordering_spec((zetasql::ASTOrderingExpression::OrderingSpec)arg1);
}

void GO_EXPORT(ASTOrderingExpression_ordering_spec)(void * arg0,int* arg1){
  zetasql::ASTOrderingExpression *node = (zetasql::ASTOrderingExpression *)arg0;
  *arg1 = node->ordering_spec();
}

void GO_EXPORT(ASTOrderingExpression_expression)(void * arg0,void ** arg1){
  zetasql::ASTOrderingExpression *node = (zetasql::ASTOrderingExpression *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTOrderingExpression_collate)(void * arg0,void ** arg1){
  zetasql::ASTOrderingExpression *node = (zetasql::ASTOrderingExpression *)arg0;
  *arg1 = (void *)node->collate();
}

void GO_EXPORT(ASTOrderingExpression_null_order)(void * arg0,void ** arg1){
  zetasql::ASTOrderingExpression *node = (zetasql::ASTOrderingExpression *)arg0;
  *arg1 = (void *)node->null_order();
}

void GO_EXPORT(ASTOrderBy_hint)(void * arg0,void ** arg1){
  zetasql::ASTOrderBy *node = (zetasql::ASTOrderBy *)arg0;
  *arg1 = (void *)node->hint();
}

void GO_EXPORT(ASTOrderBy_ordering_expressions_num)(void * arg0,int* arg1){
  zetasql::ASTOrderBy *node = (zetasql::ASTOrderBy *)arg0;
  *arg1 = node->ordering_expressions().length();
}

void GO_EXPORT(ASTOrderBy_ordering_expression)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTOrderBy *node = (zetasql::ASTOrderBy *)arg0;
  *arg2 = (void *)node->ordering_expressions(arg1);
}

void GO_EXPORT(ASTLimitOffset_limit)(void * arg0,void ** arg1){
  zetasql::ASTLimitOffset *node = (zetasql::ASTLimitOffset *)arg0;
  *arg1 = (void *)node->limit();
}

void GO_EXPORT(ASTLimitOffset_offset)(void * arg0,void ** arg1){
  zetasql::ASTLimitOffset *node = (zetasql::ASTLimitOffset *)arg0;
  *arg1 = (void *)node->offset();
}

void GO_EXPORT(ASTOnClause_expression)(void * arg0,void ** arg1){
  zetasql::ASTOnClause *node = (zetasql::ASTOnClause *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTWithClauseEntry_alias)(void * arg0,void ** arg1){
  zetasql::ASTWithClauseEntry *node = (zetasql::ASTWithClauseEntry *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTWithClauseEntry_query)(void * arg0,void ** arg1){
  zetasql::ASTWithClauseEntry *node = (zetasql::ASTWithClauseEntry *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ASTJoin_set_join_type)(void * arg0,int arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  node->set_join_type((zetasql::ASTJoin::JoinType)arg1);
}

void GO_EXPORT(ASTJoin_join_type)(void * arg0,int* arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  *arg1 = node->join_type();
}

void GO_EXPORT(ASTJoin_set_join_hint)(void * arg0,int arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  node->set_join_hint((zetasql::ASTJoin::JoinHint)arg1);
}

void GO_EXPORT(ASTJoin_join_hint)(void * arg0,int* arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  *arg1 = node->join_hint();
}

void GO_EXPORT(ASTJoin_set_natural)(void * arg0,int arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  node->set_natural(arg1);
}

void GO_EXPORT(ASTJoin_natural)(void * arg0,char* arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  *arg1 = node->natural();
}

void GO_EXPORT(ASTJoin_set_unmatched_join_count)(void * arg0,int arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  node->set_unmatched_join_count(arg1);
}

void GO_EXPORT(ASTJoin_unmatched_join_count)(void * arg0,int* arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  *arg1 = node->unmatched_join_count();
}

void GO_EXPORT(ASTJoin_set_transformation_needed)(void * arg0,int arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  node->set_transformation_needed(arg1);
}

void GO_EXPORT(ASTJoin_transformation_needed)(void * arg0,char* arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  *arg1 = node->transformation_needed();
}

void GO_EXPORT(ASTJoin_set_contains_comma_join)(void * arg0,int arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  node->set_contains_comma_join(arg1);
}

void GO_EXPORT(ASTJoin_contains_comma_join)(void * arg0,char* arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  *arg1 = node->contains_comma_join();
}

void GO_EXPORT(ASTJoin_lhs)(void * arg0,void ** arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  *arg1 = (void *)node->lhs();
}

void GO_EXPORT(ASTJoin_rhs)(void * arg0,void ** arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  *arg1 = (void *)node->rhs();
}

void GO_EXPORT(ASTJoin_hint)(void * arg0,void ** arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  *arg1 = (void *)node->hint();
}

void GO_EXPORT(ASTJoin_on_clause)(void * arg0,void ** arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  *arg1 = (void *)node->on_clause();
}

void GO_EXPORT(ASTJoin_using_clause)(void * arg0,void ** arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  *arg1 = (void *)node->using_clause();
}

void GO_EXPORT(JoinParseError_error_node)(void * arg0,void ** arg1){
  zetasql::ASTJoin::ParseError *err = (zetasql::ASTJoin::ParseError *)arg0;
  *arg1 = (void *)err->error_node;
}

void GO_EXPORT(JoinParseError_message)(void * arg0,void ** arg1){
  zetasql::ASTJoin::ParseError *err = (zetasql::ASTJoin::ParseError *)arg0;
  *arg1 = (void *)((new std::string(err->message))->c_str());
}

void GO_EXPORT(ASTJoin_parse_error)(void * arg0,void ** arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  *arg1 = (void *)node->parse_error();
}

void GO_EXPORT(ASTJoin_GetSQLForJoinType)(void * arg0,void ** arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  *arg1 = (void *)((new std::string(node->GetSQLForJoinType()))->c_str());
}

void GO_EXPORT(ASTJoin_GetSQLForJoinHint)(void * arg0,void ** arg1){
  zetasql::ASTJoin *node = (zetasql::ASTJoin *)arg0;
  *arg1 = (void *)((new std::string(node->GetSQLForJoinHint()))->c_str());
}

void GO_EXPORT(ASTWithClause_set_recursive)(void * arg0,int arg1){
  zetasql::ASTWithClause *node = (zetasql::ASTWithClause *)arg0;
  node->set_recursive(arg1);
}

void GO_EXPORT(ASTWithClause_recursive)(void * arg0,char* arg1){
  zetasql::ASTWithClause *node = (zetasql::ASTWithClause *)arg0;
  *arg1 = node->recursive();
}

void GO_EXPORT(ASTWithClause_with_num)(void * arg0,int* arg1){
  zetasql::ASTWithClause *node = (zetasql::ASTWithClause *)arg0;
  *arg1 = node->with().length();
}

void GO_EXPORT(ASTWithClause_with)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTWithClause *node = (zetasql::ASTWithClause *)arg0;
  *arg2 = (void *)node->with(arg1);
}

void GO_EXPORT(ASTHaving_expression)(void * arg0,void ** arg1){
  zetasql::ASTHaving *node = (zetasql::ASTHaving *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTType_type_parameters)(void * arg0,void ** arg1){
  zetasql::ASTType *node = (zetasql::ASTType *)arg0;
  *arg1 = (void *)node->type_parameters();
}

void GO_EXPORT(ASTType_collate)(void * arg0,void ** arg1){
  zetasql::ASTType *node = (zetasql::ASTType *)arg0;
  *arg1 = (void *)node->collate();
}

void GO_EXPORT(ASTSimpleType_type_name)(void * arg0,void ** arg1){
  zetasql::ASTSimpleType *node = (zetasql::ASTSimpleType *)arg0;
  *arg1 = (void *)node->type_name();
}

void GO_EXPORT(ASTArrayType_element_type)(void * arg0,void ** arg1){
  zetasql::ASTArrayType *node = (zetasql::ASTArrayType *)arg0;
  *arg1 = (void *)node->element_type();
}

void GO_EXPORT(ASTStructField_name)(void * arg0,void ** arg1){
  zetasql::ASTStructField *node = (zetasql::ASTStructField *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTStructField_type)(void * arg0,void ** arg1){
  zetasql::ASTStructField *node = (zetasql::ASTStructField *)arg0;
  *arg1 = (void *)node->type();
}

void GO_EXPORT(ASTStructType_struct_fields_num)(void * arg0,int* arg1){
  zetasql::ASTStructType *node = (zetasql::ASTStructType *)arg0;
  *arg1 = node->struct_fields().length();
}

void GO_EXPORT(ASTStructType_struct_field)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTStructType *node = (zetasql::ASTStructType *)arg0;
  *arg2 = (void *)node->struct_fields(arg1);
}

void GO_EXPORT(ASTCastExpression_set_is_safe_cast)(void * arg0,int arg1){
  zetasql::ASTCastExpression *node = (zetasql::ASTCastExpression *)arg0;
  node->set_is_safe_cast(arg1);
}

void GO_EXPORT(ASTCastExpression_is_safe_cast)(void * arg0,char* arg1){
  zetasql::ASTCastExpression *node = (zetasql::ASTCastExpression *)arg0;
  *arg1 = node->is_safe_cast();
}

void GO_EXPORT(ASTCastExpression_expr)(void * arg0,void ** arg1){
  zetasql::ASTCastExpression *node = (zetasql::ASTCastExpression *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ASTCastExpression_type)(void * arg0,void ** arg1){
  zetasql::ASTCastExpression *node = (zetasql::ASTCastExpression *)arg0;
  *arg1 = (void *)node->type();
}

void GO_EXPORT(ASTCastExpression_format)(void * arg0,void ** arg1){
  zetasql::ASTCastExpression *node = (zetasql::ASTCastExpression *)arg0;
  *arg1 = (void *)node->format();
}

void GO_EXPORT(ASTSelectAs_set_as_mode)(void * arg0,int arg1){
  zetasql::ASTSelectAs *node = (zetasql::ASTSelectAs *)arg0;
  node->set_as_mode((zetasql::ASTSelectAs::AsMode)arg1);
}

void GO_EXPORT(ASTSelectAs_as_mode)(void * arg0,int* arg1){
  zetasql::ASTSelectAs *node = (zetasql::ASTSelectAs *)arg0;
  *arg1 = node->as_mode();
}

void GO_EXPORT(ASTSelectAs_type_name)(void * arg0,void ** arg1){
  zetasql::ASTSelectAs *node = (zetasql::ASTSelectAs *)arg0;
  *arg1 = (void *)node->type_name();
}

void GO_EXPORT(ASTSelectAs_is_select_as_struct)(void * arg0,char* arg1){
  zetasql::ASTSelectAs *node = (zetasql::ASTSelectAs *)arg0;
  *arg1 = node->is_select_as_struct();
}

void GO_EXPORT(ASTSelectAs_is_select_as_value)(void * arg0,char* arg1){
  zetasql::ASTSelectAs *node = (zetasql::ASTSelectAs *)arg0;
  *arg1 = node->is_select_as_value();
}

void GO_EXPORT(ASTRollup_expressions_num)(void * arg0,int* arg1){
  zetasql::ASTRollup *node = (zetasql::ASTRollup *)arg0;
  *arg1 = node->expressions().length();
}

void GO_EXPORT(ASTRollup_expression)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTRollup *node = (zetasql::ASTRollup *)arg0;
  *arg2 = (void *)node->expressions(arg1);
}

void GO_EXPORT(ASTFunctionCall_set_null_handling_modifier)(void * arg0,int arg1){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  node->set_null_handling_modifier((zetasql::ASTFunctionCall::NullHandlingModifier)arg1);
}

void GO_EXPORT(ASTFunctionCall_null_handling_modifier)(void * arg0,int* arg1){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  *arg1 = node->null_handling_modifier();
}

void GO_EXPORT(ASTFunctionCall_set_distinct)(void * arg0,int arg1){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  node->set_distinct(arg1);
}

void GO_EXPORT(ASTFunctionCall_distinct)(void * arg0,char* arg1){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  *arg1 = node->distinct();
}

void GO_EXPORT(ASTFunctionCall_set_is_current_date_time_without_parentheses)(void * arg0,int arg1){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  node->set_is_current_date_time_without_parentheses(arg1);
}

void GO_EXPORT(ASTFunctionCall_is_current_date_time_without_parentheses)(void * arg0,char* arg1){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  *arg1 = node->is_current_date_time_without_parentheses();
}

void GO_EXPORT(ASTFunctionCall_function)(void * arg0,void ** arg1){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  *arg1 = (void *)node->function();
}

void GO_EXPORT(ASTFunctionCall_having_modifier)(void * arg0,void ** arg1){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  *arg1 = (void *)node->having_modifier();
}

void GO_EXPORT(ASTFunctionCall_clamped_between_modifier)(void * arg0,void ** arg1){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  *arg1 = (void *)node->clamped_between_modifier();
}

void GO_EXPORT(ASTFunctionCall_order_by)(void * arg0,void ** arg1){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  *arg1 = (void *)node->order_by();
}

void GO_EXPORT(ASTFunctionCall_limit_offset)(void * arg0,void ** arg1){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  *arg1 = (void *)node->limit_offset();
}

void GO_EXPORT(ASTFunctionCall_hint)(void * arg0,void ** arg1){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  *arg1 = (void *)node->hint();
}

void GO_EXPORT(ASTFunctionCall_with_group_rows)(void * arg0,void ** arg1){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  *arg1 = (void *)node->with_group_rows();
}

void GO_EXPORT(ASTFunctionCall_arguments_num)(void * arg0,int* arg1){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  *arg1 = node->arguments().length();
}

void GO_EXPORT(ASTFunctionCall_argument)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  *arg2 = (void *)node->arguments(arg1);
}

void GO_EXPORT(ASTFunctionCall_HasModifiers)(void * arg0,char* arg1){
  zetasql::ASTFunctionCall *node = (zetasql::ASTFunctionCall *)arg0;
  *arg1 = node->HasModifiers();
}

void GO_EXPORT(ASTArrayConstructor_type)(void * arg0,void ** arg1){
  zetasql::ASTArrayConstructor *node = (zetasql::ASTArrayConstructor *)arg0;
  *arg1 = (void *)node->type();
}

void GO_EXPORT(ASTArrayConstructor_elements_num)(void * arg0,int* arg1){
  zetasql::ASTArrayConstructor *node = (zetasql::ASTArrayConstructor *)arg0;
  *arg1 = node->elements().length();
}

void GO_EXPORT(ASTArrayConstructor_element)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTArrayConstructor *node = (zetasql::ASTArrayConstructor *)arg0;
  *arg2 = (void *)node->elements(arg1);
}

void GO_EXPORT(ASTStructConstructorArg_expression)(void * arg0,void ** arg1){
  zetasql::ASTStructConstructorArg *node = (zetasql::ASTStructConstructorArg *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTStructConstructorArg_alias)(void * arg0,void ** arg1){
  zetasql::ASTStructConstructorArg *node = (zetasql::ASTStructConstructorArg *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTStructConstructorWithParens_field_expressions_num)(void * arg0,int* arg1){
  zetasql::ASTStructConstructorWithParens *node = (zetasql::ASTStructConstructorWithParens *)arg0;
  *arg1 = node->field_expressions().length();
}

void GO_EXPORT(ASTStructConstructorWithParens_field_expression)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTStructConstructorWithParens *node = (zetasql::ASTStructConstructorWithParens *)arg0;
  *arg2 = (void *)node->field_expressions(arg1);
}

void GO_EXPORT(ASTStructConstructorWithKeyword_struct_type)(void * arg0,void ** arg1){
  zetasql::ASTStructConstructorWithKeyword *node = (zetasql::ASTStructConstructorWithKeyword *)arg0;
  *arg1 = (void *)node->struct_type();
}

void GO_EXPORT(ASTStructConstructorWithKeyword_fields_num)(void * arg0,int* arg1){
  zetasql::ASTStructConstructorWithKeyword *node = (zetasql::ASTStructConstructorWithKeyword *)arg0;
  *arg1 = node->fields().length();
}

void GO_EXPORT(ASTStructConstructorWithKeyword_field)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTStructConstructorWithKeyword *node = (zetasql::ASTStructConstructorWithKeyword *)arg0;
  *arg2 = (void *)node->fields(arg1);
}

void GO_EXPORT(ASTInExpression_set_is_not)(void * arg0,int arg1){
  zetasql::ASTInExpression *node = (zetasql::ASTInExpression *)arg0;
  node->set_is_not(arg1);
}

void GO_EXPORT(ASTInExpression_is_not)(void * arg0,char* arg1){
  zetasql::ASTInExpression *node = (zetasql::ASTInExpression *)arg0;
  *arg1 = node->is_not();
}

void GO_EXPORT(ASTInExpression_lhs)(void * arg0,void ** arg1){
  zetasql::ASTInExpression *node = (zetasql::ASTInExpression *)arg0;
  *arg1 = (void *)node->lhs();
}

void GO_EXPORT(ASTInExpression_hint)(void * arg0,void ** arg1){
  zetasql::ASTInExpression *node = (zetasql::ASTInExpression *)arg0;
  *arg1 = (void *)node->hint();
}

void GO_EXPORT(ASTInExpression_in_list)(void * arg0,void ** arg1){
  zetasql::ASTInExpression *node = (zetasql::ASTInExpression *)arg0;
  *arg1 = (void *)node->in_list();
}

void GO_EXPORT(ASTInExpression_query)(void * arg0,void ** arg1){
  zetasql::ASTInExpression *node = (zetasql::ASTInExpression *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ASTInExpression_unnest_expr)(void * arg0,void ** arg1){
  zetasql::ASTInExpression *node = (zetasql::ASTInExpression *)arg0;
  *arg1 = (void *)node->unnest_expr();
}

void GO_EXPORT(ASTInList_list_num)(void * arg0,int* arg1){
  zetasql::ASTInList *node = (zetasql::ASTInList *)arg0;
  *arg1 = node->list().length();
}

void GO_EXPORT(ASTInList_list)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTInList *node = (zetasql::ASTInList *)arg0;
  *arg2 = (void *)node->list(arg1);
}

void GO_EXPORT(ASTBetweenExpression_set_is_not)(void * arg0,int arg1){
  zetasql::ASTBetweenExpression *node = (zetasql::ASTBetweenExpression *)arg0;
  node->set_is_not(arg1);
}

void GO_EXPORT(ASTBetweenExpression_is_not)(void * arg0,char* arg1){
  zetasql::ASTBetweenExpression *node = (zetasql::ASTBetweenExpression *)arg0;
  *arg1 = node->is_not();
}

void GO_EXPORT(ASTBetweenExpression_lhs)(void * arg0,void ** arg1){
  zetasql::ASTBetweenExpression *node = (zetasql::ASTBetweenExpression *)arg0;
  *arg1 = (void *)node->lhs();
}

void GO_EXPORT(ASTBetweenExpression_low)(void * arg0,void ** arg1){
  zetasql::ASTBetweenExpression *node = (zetasql::ASTBetweenExpression *)arg0;
  *arg1 = (void *)node->low();
}

void GO_EXPORT(ASTBetweenExpression_high)(void * arg0,void ** arg1){
  zetasql::ASTBetweenExpression *node = (zetasql::ASTBetweenExpression *)arg0;
  *arg1 = (void *)node->high();
}

void GO_EXPORT(ASTDateOrTimeLiteral_set_type_kind)(void * arg0,int arg1){
  zetasql::ASTDateOrTimeLiteral *node = (zetasql::ASTDateOrTimeLiteral *)arg0;
  node->set_type_kind((zetasql::TypeKind)arg1);
}

void GO_EXPORT(ASTDateOrTimeLiteral_type_kind)(void * arg0,int* arg1){
  zetasql::ASTDateOrTimeLiteral *node = (zetasql::ASTDateOrTimeLiteral *)arg0;
  *arg1 = node->type_kind();
}

void GO_EXPORT(ASTDateOrTimeLiteral_string_literal)(void * arg0,void ** arg1){
  zetasql::ASTDateOrTimeLiteral *node = (zetasql::ASTDateOrTimeLiteral *)arg0;
  *arg1 = (void *)node->string_literal();
}

void GO_EXPORT(ASTCaseValueExpression_arguments_num)(void * arg0,int* arg1){
  zetasql::ASTCaseValueExpression *node = (zetasql::ASTCaseValueExpression *)arg0;
  *arg1 = node->arguments().length();
}

void GO_EXPORT(ASTCaseValueExpression_argument)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTCaseValueExpression *node = (zetasql::ASTCaseValueExpression *)arg0;
  *arg2 = (void *)node->arguments(arg1);
}

void GO_EXPORT(ASTCaseNoValueExpression_arguments_num)(void * arg0,int* arg1){
  zetasql::ASTCaseNoValueExpression *node = (zetasql::ASTCaseNoValueExpression *)arg0;
  *arg1 = node->arguments().length();
}

void GO_EXPORT(ASTCaseNoValueExpression_argument)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTCaseNoValueExpression *node = (zetasql::ASTCaseNoValueExpression *)arg0;
  *arg2 = (void *)node->arguments(arg1);
}

void GO_EXPORT(ASTArrayElement_array)(void * arg0,void ** arg1){
  zetasql::ASTArrayElement *node = (zetasql::ASTArrayElement *)arg0;
  *arg1 = (void *)node->array();
}

void GO_EXPORT(ASTArrayElement_position)(void * arg0,void ** arg1){
  zetasql::ASTArrayElement *node = (zetasql::ASTArrayElement *)arg0;
  *arg1 = (void *)node->position();
}

void GO_EXPORT(ASTBitwiseShiftExpression_set_is_left_shift)(void * arg0,int arg1){
  zetasql::ASTBitwiseShiftExpression *node = (zetasql::ASTBitwiseShiftExpression *)arg0;
  node->set_is_left_shift(arg1);
}

void GO_EXPORT(ASTBitwiseShiftExpression_is_left_shift)(void * arg0,char* arg1){
  zetasql::ASTBitwiseShiftExpression *node = (zetasql::ASTBitwiseShiftExpression *)arg0;
  *arg1 = node->is_left_shift();
}

void GO_EXPORT(ASTBitwiseShiftExpression_lhs)(void * arg0,void ** arg1){
  zetasql::ASTBitwiseShiftExpression *node = (zetasql::ASTBitwiseShiftExpression *)arg0;
  *arg1 = (void *)node->lhs();
}

void GO_EXPORT(ASTBitwiseShiftExpression_rhs)(void * arg0,void ** arg1){
  zetasql::ASTBitwiseShiftExpression *node = (zetasql::ASTBitwiseShiftExpression *)arg0;
  *arg1 = (void *)node->rhs();
}

void GO_EXPORT(ASTCollate_collation_name)(void * arg0,void ** arg1){
  zetasql::ASTCollate *node = (zetasql::ASTCollate *)arg0;
  *arg1 = (void *)node->collation_name();
}

void GO_EXPORT(ASTDotGeneralizedField_expr)(void * arg0,void ** arg1){
  zetasql::ASTDotGeneralizedField *node = (zetasql::ASTDotGeneralizedField *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ASTDotGeneralizedField_path)(void * arg0,void ** arg1){
  zetasql::ASTDotGeneralizedField *node = (zetasql::ASTDotGeneralizedField *)arg0;
  *arg1 = (void *)node->path();
}

void GO_EXPORT(ASTDotIdentifier_expr)(void * arg0,void ** arg1){
  zetasql::ASTDotIdentifier *node = (zetasql::ASTDotIdentifier *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ASTDotIdentifier_name)(void * arg0,void ** arg1){
  zetasql::ASTDotIdentifier *node = (zetasql::ASTDotIdentifier *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTDotStar_expr)(void * arg0,void ** arg1){
  zetasql::ASTDotStar *node = (zetasql::ASTDotStar *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ASTDotStarWithModifiers_expr)(void * arg0,void ** arg1){
  zetasql::ASTDotStarWithModifiers *node = (zetasql::ASTDotStarWithModifiers *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ASTDotStarWithModifiers_modifiers)(void * arg0,void ** arg1){
  zetasql::ASTDotStarWithModifiers *node = (zetasql::ASTDotStarWithModifiers *)arg0;
  *arg1 = (void *)node->modifiers();
}

void GO_EXPORT(ASTExpressionSubquery_set_modifier)(void * arg0,int arg1){
  zetasql::ASTExpressionSubquery *node = (zetasql::ASTExpressionSubquery *)arg0;
  node->set_modifier((zetasql::ASTExpressionSubquery::Modifier)arg1);
}

void GO_EXPORT(ASTExpressionSubquery_modifier)(void * arg0,int* arg1){
  zetasql::ASTExpressionSubquery *node = (zetasql::ASTExpressionSubquery *)arg0;
  *arg1 = node->modifier();
}

void GO_EXPORT(ASTExpressionSubquery_hint)(void * arg0,void ** arg1){
  zetasql::ASTExpressionSubquery *node = (zetasql::ASTExpressionSubquery *)arg0;
  *arg1 = (void *)node->hint();
}

void GO_EXPORT(ASTExpressionSubquery_query)(void * arg0,void ** arg1){
  zetasql::ASTExpressionSubquery *node = (zetasql::ASTExpressionSubquery *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ASTExtractExpression_lhs_expr)(void * arg0,void ** arg1){
  zetasql::ASTExtractExpression *node = (zetasql::ASTExtractExpression *)arg0;
  *arg1 = (void *)node->lhs_expr();
}

void GO_EXPORT(ASTExtractExpression_rhs_expr)(void * arg0,void ** arg1){
  zetasql::ASTExtractExpression *node = (zetasql::ASTExtractExpression *)arg0;
  *arg1 = (void *)node->rhs_expr();
}

void GO_EXPORT(ASTExtractExpression_time_zone_expr)(void * arg0,void ** arg1){
  zetasql::ASTExtractExpression *node = (zetasql::ASTExtractExpression *)arg0;
  *arg1 = (void *)node->time_zone_expr();
}

void GO_EXPORT(ASTHavingModifier_set_modifier_kind)(void * arg0,int arg1){
  zetasql::ASTHavingModifier *node = (zetasql::ASTHavingModifier *)arg0;
  node->set_modifier_kind((zetasql::ASTHavingModifier::ModifierKind)arg1);
}

void GO_EXPORT(ASTHavingModifier_modifier_kind)(void * arg0,int* arg1){
  zetasql::ASTHavingModifier *node = (zetasql::ASTHavingModifier *)arg0;
  *arg1 = node->modifier_kind();
}

void GO_EXPORT(ASTHavingModifier_expr)(void * arg0,void ** arg1){
  zetasql::ASTHavingModifier *node = (zetasql::ASTHavingModifier *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ASTIntervalExpr_interval_value)(void * arg0,void ** arg1){
  zetasql::ASTIntervalExpr *node = (zetasql::ASTIntervalExpr *)arg0;
  *arg1 = (void *)node->interval_value();
}

void GO_EXPORT(ASTIntervalExpr_date_part_name)(void * arg0,void ** arg1){
  zetasql::ASTIntervalExpr *node = (zetasql::ASTIntervalExpr *)arg0;
  *arg1 = (void *)node->date_part_name();
}

void GO_EXPORT(ASTIntervalExpr_date_part_name_to)(void * arg0,void ** arg1){
  zetasql::ASTIntervalExpr *node = (zetasql::ASTIntervalExpr *)arg0;
  *arg1 = (void *)node->date_part_name_to();
}

void GO_EXPORT(ASTNamedArgument_name)(void * arg0,void ** arg1){
  zetasql::ASTNamedArgument *node = (zetasql::ASTNamedArgument *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTNamedArgument_expr)(void * arg0,void ** arg1){
  zetasql::ASTNamedArgument *node = (zetasql::ASTNamedArgument *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ASTNullOrder_set_nulls_first)(void * arg0,int arg1){
  zetasql::ASTNullOrder *node = (zetasql::ASTNullOrder *)arg0;
  node->set_nulls_first(arg1);
}

void GO_EXPORT(ASTNullOrder_nulls_first)(void * arg0,char* arg1){
  zetasql::ASTNullOrder *node = (zetasql::ASTNullOrder *)arg0;
  *arg1 = node->nulls_first();
}

void GO_EXPORT(ASTOnOrUsingClauseList_on_or_using_clause_list_num)(void * arg0,int* arg1){
  zetasql::ASTOnOrUsingClauseList *node = (zetasql::ASTOnOrUsingClauseList *)arg0;
  *arg1 = node->on_or_using_clause_list().length();
}

void GO_EXPORT(ASTOnUsingClauseList_on_or_using_clause_list)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTOnOrUsingClauseList *node = (zetasql::ASTOnOrUsingClauseList *)arg0;
  *arg2 = (void *)node->on_or_using_clause_list(arg1);
}

void GO_EXPORT(ASTParenthesizedJoin_join)(void * arg0,void ** arg1){
  zetasql::ASTParenthesizedJoin *node = (zetasql::ASTParenthesizedJoin *)arg0;
  *arg1 = (void *)node->join();
}

void GO_EXPORT(ASTParenthesizedJoin_sample_clause)(void * arg0,void ** arg1){
  zetasql::ASTParenthesizedJoin *node = (zetasql::ASTParenthesizedJoin *)arg0;
  *arg1 = (void *)node->sample_clause();
}

void GO_EXPORT(ASTPartitionBy_hint)(void * arg0,void ** arg1){
  zetasql::ASTPartitionBy *node = (zetasql::ASTPartitionBy *)arg0;
  *arg1 = (void *)node->hint();
}

void GO_EXPORT(ASTPartitionBy_partitioning_expressions_num)(void * arg0,int* arg1){
  zetasql::ASTPartitionBy *node = (zetasql::ASTPartitionBy *)arg0;
  *arg1 = node->partitioning_expressions().length();
}

void GO_EXPORT(ASTPartitionBy_partitioning_expression)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTPartitionBy *node = (zetasql::ASTPartitionBy *)arg0;
  *arg2 = (void *)node->partitioning_expressions(arg1);
}

void GO_EXPORT(ASTSetOperation_set_op_type)(void * arg0,int arg1){
  zetasql::ASTSetOperation *node = (zetasql::ASTSetOperation *)arg0;
  node->set_op_type((zetasql::ASTSetOperation::OperationType)arg1);
}

void GO_EXPORT(ASTSetOperation_op_type)(void * arg0,int* arg1){
  zetasql::ASTSetOperation *node = (zetasql::ASTSetOperation *)arg0;
  *arg1 = node->op_type();
}

void GO_EXPORT(ASTSetOperation_set_distinct)(void * arg0,int arg1){
  zetasql::ASTSetOperation *node = (zetasql::ASTSetOperation *)arg0;
  node->set_distinct(arg1);
}

void GO_EXPORT(ASTSetOperation_distinct)(void * arg0,char* arg1){
  zetasql::ASTSetOperation *node = (zetasql::ASTSetOperation *)arg0;
  *arg1 = node->distinct();
}

void GO_EXPORT(ASTSetOperation_hint)(void * arg0,void ** arg1){
  zetasql::ASTSetOperation *node = (zetasql::ASTSetOperation *)arg0;
  *arg1 = (void *)node->hint();
}

void GO_EXPORT(ASTSetOperation_inputs_num)(void * arg0,int* arg1){
  zetasql::ASTSetOperation *node = (zetasql::ASTSetOperation *)arg0;
  *arg1 = node->inputs().length();
}

void GO_EXPORT(ASTSetOperation_input)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTSetOperation *node = (zetasql::ASTSetOperation *)arg0;
  *arg2 = (void *)node->inputs(arg1);
}

void GO_EXPORT(ASTSetOperation_GetSQLForOperation)(void * arg0,void ** arg1){
  zetasql::ASTSetOperation *node = (zetasql::ASTSetOperation *)arg0;
  *arg1 = (void *)((new std::string(node->GetSQLForOperation()))->c_str());
}

void GO_EXPORT(ASTStarExceptList_identifiers_num)(void * arg0,int* arg1){
  zetasql::ASTStarExceptList *node = (zetasql::ASTStarExceptList *)arg0;
  *arg1 = node->identifiers().length();
}

void GO_EXPORT(ASTStarExpcetList_identifier)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTStarExceptList *node = (zetasql::ASTStarExceptList *)arg0;
  *arg2 = (void *)node->identifiers(arg1);
}

void GO_EXPORT(ASTStarModifiers_except_list)(void * arg0,void ** arg1){
  zetasql::ASTStarModifiers *node = (zetasql::ASTStarModifiers *)arg0;
  *arg1 = (void *)node->except_list();
}

void GO_EXPORT(ASTStarModifiers_replace_items_num)(void * arg0,int* arg1){
  zetasql::ASTStarModifiers *node = (zetasql::ASTStarModifiers *)arg0;
  *arg1 = node->replace_items().length();
}

void GO_EXPORT(ASTStarModifiers_replace_item)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTStarModifiers *node = (zetasql::ASTStarModifiers *)arg0;
  *arg2 = (void *)node->replace_items(arg1);
}

void GO_EXPORT(ASTStarReplaceItem_expression)(void * arg0,void ** arg1){
  zetasql::ASTStarReplaceItem *node = (zetasql::ASTStarReplaceItem *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTStarReplaceItem_alias)(void * arg0,void ** arg1){
  zetasql::ASTStarReplaceItem *node = (zetasql::ASTStarReplaceItem *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTStarWithModifiers_modifiers)(void * arg0,void ** arg1){
  zetasql::ASTStarWithModifiers *node = (zetasql::ASTStarWithModifiers *)arg0;
  *arg1 = (void *)node->modifiers();
}

void GO_EXPORT(ASTTableSubquery_subquery)(void * arg0,void ** arg1){
  zetasql::ASTTableSubquery *node = (zetasql::ASTTableSubquery *)arg0;
  *arg1 = (void *)node->subquery();
}

void GO_EXPORT(ASTTableSubquery_pivot_clause)(void * arg0,void ** arg1){
  zetasql::ASTTableSubquery *node = (zetasql::ASTTableSubquery *)arg0;
  *arg1 = (void *)node->pivot_clause();
}

void GO_EXPORT(ASTTableSubquery_unpivot_clause)(void * arg0,void ** arg1){
  zetasql::ASTTableSubquery *node = (zetasql::ASTTableSubquery *)arg0;
  *arg1 = (void *)node->unpivot_clause();
}

void GO_EXPORT(ASTTableSubquery_sample_clause)(void * arg0,void ** arg1){
  zetasql::ASTTableSubquery *node = (zetasql::ASTTableSubquery *)arg0;
  *arg1 = (void *)node->sample_clause();
}

void GO_EXPORT(ASTTableSubquery_alias)(void * arg0,void ** arg1){
  zetasql::ASTTableSubquery *node = (zetasql::ASTTableSubquery *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTUnaryExpression_set_op)(void * arg0,int arg1){
  zetasql::ASTUnaryExpression *node = (zetasql::ASTUnaryExpression *)arg0;
  node->set_op((zetasql::ASTUnaryExpression::Op)arg1);
}

void GO_EXPORT(ASTUnaryExpression_op)(void * arg0,int* arg1){
  zetasql::ASTUnaryExpression *node = (zetasql::ASTUnaryExpression *)arg0;
  *arg1 = node->op();
}

void GO_EXPORT(ASTUnaryExpression_operand)(void * arg0,void ** arg1){
  zetasql::ASTUnaryExpression *node = (zetasql::ASTUnaryExpression *)arg0;
  *arg1 = (void *)node->operand();
}

void GO_EXPORT(ASTUnaryExpression_GetSQLForOperator)(void * arg0,void ** arg1){
  zetasql::ASTUnaryExpression *node = (zetasql::ASTUnaryExpression *)arg0;
  *arg1 = (void *)((new std::string(node->GetSQLForOperator()))->c_str());
}

void GO_EXPORT(ASTUnnestExpression_expression)(void * arg0,void ** arg1){
  zetasql::ASTUnnestExpression *node = (zetasql::ASTUnnestExpression *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTWindowClause_windows_num)(void * arg0,int* arg1){
  zetasql::ASTWindowClause *node = (zetasql::ASTWindowClause *)arg0;
  *arg1 = node->windows().length();
}

void GO_EXPORT(ASTWindowClause_window)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTWindowClause *node = (zetasql::ASTWindowClause *)arg0;
  *arg2 = (void *)node->windows(arg1);
}

void GO_EXPORT(ASTWindowDefinition_name)(void * arg0,void ** arg1){
  zetasql::ASTWindowDefinition *node = (zetasql::ASTWindowDefinition *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTWindowDefinition_window_spec)(void * arg0,void ** arg1){
  zetasql::ASTWindowDefinition *node = (zetasql::ASTWindowDefinition *)arg0;
  *arg1 = (void *)node->window_spec();
}

void GO_EXPORT(ASTWindowFrame_start_expr)(void * arg0,void ** arg1){
  zetasql::ASTWindowFrame *node = (zetasql::ASTWindowFrame *)arg0;
  *arg1 = (void *)node->start_expr();
}

void GO_EXPORT(ASTWindowFrame_end_expr)(void * arg0,void ** arg1){
  zetasql::ASTWindowFrame *node = (zetasql::ASTWindowFrame *)arg0;
  *arg1 = (void *)node->end_expr();
}

void GO_EXPORT(ASTWindowFrame_set_unit)(void * arg0,int arg1){
  zetasql::ASTWindowFrame *node = (zetasql::ASTWindowFrame *)arg0;
  node->set_unit((zetasql::ASTWindowFrame::FrameUnit)arg1);
}

void GO_EXPORT(ASTWindowFrame_frame_unit)(void * arg0,int* arg1){
  zetasql::ASTWindowFrame *node = (zetasql::ASTWindowFrame *)arg0;
  *arg1 = node->frame_unit();
}

void GO_EXPORT(ASTWindowFrame_GetFrameUnitString)(void * arg0,void ** arg1){
  zetasql::ASTWindowFrame *node = (zetasql::ASTWindowFrame *)arg0;
  *arg1 = (void *)((new std::string(node->GetFrameUnitString()))->c_str());
}

void GO_EXPORT(ASTWindowFrameExpr_set_boundary_type)(void * arg0,int arg1){
  zetasql::ASTWindowFrameExpr *node = (zetasql::ASTWindowFrameExpr *)arg0;
  node->set_boundary_type((zetasql::ASTWindowFrameExpr::BoundaryType)arg1);
}

void GO_EXPORT(ASTWindowFrameExpr_boundary_type)(void * arg0,int* arg1){
  zetasql::ASTWindowFrameExpr *node = (zetasql::ASTWindowFrameExpr *)arg0;
  *arg1 = node->boundary_type();
}

void GO_EXPORT(ASTWindowFrameExpr_expression)(void * arg0,void ** arg1){
  zetasql::ASTWindowFrameExpr *node = (zetasql::ASTWindowFrameExpr *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTLikeExpression_set_is_not)(void * arg0,int arg1){
  zetasql::ASTLikeExpression *node = (zetasql::ASTLikeExpression *)arg0;
  node->set_is_not(arg1);
}

void GO_EXPORT(ASTLikeExpression_is_not)(void * arg0,char *arg1){
  zetasql::ASTLikeExpression *node = (zetasql::ASTLikeExpression *)arg0;
  *arg1 = node->is_not();
}

void GO_EXPORT(ASTLikeExpression_lhs)(void * arg0,void ** arg1){
  zetasql::ASTLikeExpression *node = (zetasql::ASTLikeExpression *)arg0;
  *arg1 = (void *)node->lhs();
}

void GO_EXPORT(ASTLikeExpression_op)(void * arg0,void ** arg1){
  zetasql::ASTLikeExpression *node = (zetasql::ASTLikeExpression *)arg0;
  *arg1 = (void *)node->op();
}

void GO_EXPORT(ASTLikeExpression_hint)(void * arg0,void ** arg1){
  zetasql::ASTLikeExpression *node = (zetasql::ASTLikeExpression *)arg0;
  *arg1 = (void *)node->hint();
}

void GO_EXPORT(ASTLikeExpression_in_list)(void * arg0,void ** arg1){
  zetasql::ASTLikeExpression *node = (zetasql::ASTLikeExpression *)arg0;
  *arg1 = (void *)node->in_list();
}

void GO_EXPORT(ASTLikeExpression_query)(void * arg0,void ** arg1){
  zetasql::ASTLikeExpression *node = (zetasql::ASTLikeExpression *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ASTLikeExpression_unnest_expr)(void * arg0,void ** arg1){
  zetasql::ASTLikeExpression *node = (zetasql::ASTLikeExpression *)arg0;
  *arg1 = (void *)node->unnest_expr();
}

void GO_EXPORT(ASTWindowSpecification_base_window_name)(void * arg0,void ** arg1){
  zetasql::ASTWindowSpecification *node = (zetasql::ASTWindowSpecification *)arg0;
  *arg1 = (void *)node->base_window_name();
}

void GO_EXPORT(ASTWindowSpecification_partition_by)(void * arg0,void ** arg1){
  zetasql::ASTWindowSpecification *node = (zetasql::ASTWindowSpecification *)arg0;
  *arg1 = (void *)node->partition_by();
}

void GO_EXPORT(ASTWindowSpecification_order_by)(void * arg0,void ** arg1){
  zetasql::ASTWindowSpecification *node = (zetasql::ASTWindowSpecification *)arg0;
  *arg1 = (void *)node->order_by();
}

void GO_EXPORT(ASTWindowSpecification_window_frame)(void * arg0,void ** arg1){
  zetasql::ASTWindowSpecification *node = (zetasql::ASTWindowSpecification *)arg0;
  *arg1 = (void *)node->window_frame();
}

void GO_EXPORT(ASTWithOffset_alias)(void * arg0,void ** arg1){
  zetasql::ASTWithOffset *node = (zetasql::ASTWithOffset *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTAnySomeAllOp_set_op)(void * arg0,int arg1){
  zetasql::ASTAnySomeAllOp *node = (zetasql::ASTAnySomeAllOp *)arg0;
  node->set_op((zetasql::ASTAnySomeAllOp::Op)arg1);
}

void GO_EXPORT(ASTAnySomeAllOp_op)(void * arg0,int* arg1){
  zetasql::ASTAnySomeAllOp *node = (zetasql::ASTAnySomeAllOp *)arg0;
  *arg1 = node->op();
}

void GO_EXPORT(ASTAnySomeAllOp_GetSQLForOperator)(void * arg0,void ** arg1){
  zetasql::ASTAnySomeAllOp *node = (zetasql::ASTAnySomeAllOp *)arg0;
  *arg1 = (void *)((new std::string(node->GetSQLForOperator()))->c_str());
}

void GO_EXPORT(ASTStatementList_set_variable_declarations_allowed)(void * arg0,int arg1){
  zetasql::ASTStatementList *node = (zetasql::ASTStatementList *)arg0;
  node->set_variable_declarations_allowed(arg1);
}

void GO_EXPORT(ASTStatementList_variable_declarations_allowed)(void * arg0,char* arg1){
  zetasql::ASTStatementList *node = (zetasql::ASTStatementList *)arg0;
  *arg1 = node->variable_declarations_allowed();
}

void GO_EXPORT(ASTStatementList_statement_list_num)(void * arg0,int* arg1){
  zetasql::ASTStatementList *node = (zetasql::ASTStatementList *)arg0;
  *arg1 = node->statement_list().length();
}

void GO_EXPORT(ASTStatementList_statement_list)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTStatementList *node = (zetasql::ASTStatementList *)arg0;
  *arg2 = (void *)node->statement_list(arg1);
}

void GO_EXPORT(ASTHintedStatement_hint)(void * arg0,void ** arg1){
  zetasql::ASTHintedStatement *node = (zetasql::ASTHintedStatement *)arg0;
  *arg1 = (void *)node->hint();
}

void GO_EXPORT(ASTHintedStatement_statement)(void * arg0,void ** arg1){
  zetasql::ASTHintedStatement *node = (zetasql::ASTHintedStatement *)arg0;
  *arg1 = (void *)node->statement();
}

void GO_EXPORT(ASTExplainStatement_statement)(void * arg0,void ** arg1){
  zetasql::ASTExplainStatement *node = (zetasql::ASTExplainStatement *)arg0;
  *arg1 = (void *)node->statement();
}

void GO_EXPORT(ASTDescribeStatement_optional_identifier)(void * arg0,void ** arg1){
  zetasql::ASTDescribeStatement *node = (zetasql::ASTDescribeStatement *)arg0;
  *arg1 = (void *)node->optional_identifier();
}

void GO_EXPORT(ASTDescribeStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTDescribeStatement *node = (zetasql::ASTDescribeStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTDescribeStatement_optional_from_name)(void * arg0,void ** arg1){
  zetasql::ASTDescribeStatement *node = (zetasql::ASTDescribeStatement *)arg0;
  *arg1 = (void *)node->optional_from_name();
}

void GO_EXPORT(ASTShowStatement_identifier)(void * arg0,void ** arg1){
  zetasql::ASTShowStatement *node = (zetasql::ASTShowStatement *)arg0;
  *arg1 = (void *)node->identifier();
}

void GO_EXPORT(ASTShowStatement_optional_name)(void * arg0,void ** arg1){
  zetasql::ASTShowStatement *node = (zetasql::ASTShowStatement *)arg0;
  *arg1 = (void *)node->optional_name();
}

void GO_EXPORT(ASTShowStatement_optional_like_string)(void * arg0,void ** arg1){
  zetasql::ASTShowStatement *node = (zetasql::ASTShowStatement *)arg0;
  *arg1 = (void *)node->optional_like_string();
}

void GO_EXPORT(ASTTransactionIsolationLevel_identifier1)(void * arg0,void ** arg1){
  zetasql::ASTTransactionIsolationLevel *node = (zetasql::ASTTransactionIsolationLevel *)arg0;
  *arg1 = (void *)node->identifier1();
}

void GO_EXPORT(ASTTransactionIsolationLevel_identifier2)(void * arg0,void ** arg1){
  zetasql::ASTTransactionIsolationLevel *node = (zetasql::ASTTransactionIsolationLevel *)arg0;
  *arg1 = (void *)node->identifier2();
}

void GO_EXPORT(ASTTransactionReadWriteMode_set_mode)(void * arg0,int arg1){
  zetasql::ASTTransactionReadWriteMode *node = (zetasql::ASTTransactionReadWriteMode *)arg0;
  node->set_mode((zetasql::ASTTransactionReadWriteMode::Mode)arg1);
}

void GO_EXPORT(ASTTransactionReadWriteMode_mode)(void * arg0,int* arg1){
  zetasql::ASTTransactionReadWriteMode *node = (zetasql::ASTTransactionReadWriteMode *)arg0;
  *arg1 = node->mode();
}

void GO_EXPORT(ASTTransactionModeList_elements_num)(void * arg0,int* arg1){
  zetasql::ASTTransactionModeList *node = (zetasql::ASTTransactionModeList *)arg0;
  *arg1 = node->elements().length();
}

void GO_EXPORT(ASTTransactionModeList_element)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTTransactionModeList *node = (zetasql::ASTTransactionModeList *)arg0;
  *arg2 = (void *)node->elements(arg1);
}

void GO_EXPORT(ASTBeginStatement_mode_list)(void * arg0,void ** arg1){
  zetasql::ASTBeginStatement *node = (zetasql::ASTBeginStatement *)arg0;
  *arg1 = (void *)node->mode_list();
}

void GO_EXPORT(ASTSetTransactionStatement_mode_list)(void * arg0,void ** arg1){
  zetasql::ASTSetTransactionStatement *node = (zetasql::ASTSetTransactionStatement *)arg0;
  *arg1 = (void *)node->mode_list();
}

void GO_EXPORT(ASTStartBatchStatement_batch_type)(void * arg0,void ** arg1){
  zetasql::ASTStartBatchStatement *node = (zetasql::ASTStartBatchStatement *)arg0;
  *arg1 = (void *)node->batch_type();
}

void GO_EXPORT(ASTDdlStatement_GetDdlTarget)(void * arg0,void ** arg1){
  zetasql::ASTDdlStatement *node = (zetasql::ASTDdlStatement *)arg0;
  *arg1 = (void *)node->GetDdlTarget();
}

void GO_EXPORT(ASTDropEntityStatement_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTDropEntityStatement *node = (zetasql::ASTDropEntityStatement *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTDropEntityStatement_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTDropEntityStatement *node = (zetasql::ASTDropEntityStatement *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTDropEntityStatement_entity_type)(void * arg0,void ** arg1){
  zetasql::ASTDropEntityStatement *node = (zetasql::ASTDropEntityStatement *)arg0;
  *arg1 = (void *)node->entity_type();
}

void GO_EXPORT(ASTDropEntityStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTDropEntityStatement *node = (zetasql::ASTDropEntityStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTDropFunctionStatement_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTDropFunctionStatement *node = (zetasql::ASTDropFunctionStatement *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTDropFunctionStatement_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTDropFunctionStatement *node = (zetasql::ASTDropFunctionStatement *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTDropFunctionStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTDropFunctionStatement *node = (zetasql::ASTDropFunctionStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTDropFunctionStatement_parameters)(void * arg0,void ** arg1){
  zetasql::ASTDropFunctionStatement *node = (zetasql::ASTDropFunctionStatement *)arg0;
  *arg1 = (void *)node->parameters();
}

void GO_EXPORT(ASTDropTableFunctionStatement_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTDropTableFunctionStatement *node = (zetasql::ASTDropTableFunctionStatement *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTDropTableFunctionStatement_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTDropTableFunctionStatement *node = (zetasql::ASTDropTableFunctionStatement *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTDropTableFunctionStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTDropTableFunctionStatement *node = (zetasql::ASTDropTableFunctionStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTDropAllRowAccessPoliciesStatement_set_has_access_keyword)(void * arg0,int arg1){
  zetasql::ASTDropAllRowAccessPoliciesStatement *node = (zetasql::ASTDropAllRowAccessPoliciesStatement *)arg0;
  node->set_has_access_keyword(arg1);
}

void GO_EXPORT(ASTDropAllRowAccessPoliciesStatement_has_access_keyword)(void * arg0,char* arg1){
  zetasql::ASTDropAllRowAccessPoliciesStatement *node = (zetasql::ASTDropAllRowAccessPoliciesStatement *)arg0;
  *arg1 = node->has_access_keyword();
}

void GO_EXPORT(ASTDropAllRowAccessPoliciesStatement_table_name)(void * arg0,void ** arg1){
  zetasql::ASTDropAllRowAccessPoliciesStatement *node = (zetasql::ASTDropAllRowAccessPoliciesStatement *)arg0;
  *arg1 = (void *)node->table_name();
}

void GO_EXPORT(ASTDropMaterializedViewStatement_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTDropMaterializedViewStatement *node = (zetasql::ASTDropMaterializedViewStatement *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTDropMaterializedViewStatement_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTDropMaterializedViewStatement *node = (zetasql::ASTDropMaterializedViewStatement *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTDropMaterializedViewStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTDropMaterializedViewStatement *node = (zetasql::ASTDropMaterializedViewStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTDropSnapshotTableStatement_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTDropSnapshotTableStatement *node = (zetasql::ASTDropSnapshotTableStatement *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTDropSnapshotTableStatement_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTDropSnapshotTableStatement *node = (zetasql::ASTDropSnapshotTableStatement *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTDropSnapshotTableStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTDropSnapshotTableStatement *node = (zetasql::ASTDropSnapshotTableStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTDropSearchIndexStatement_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTDropSearchIndexStatement *node = (zetasql::ASTDropSearchIndexStatement *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTDropSearchIndexStatement_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTDropSearchIndexStatement *node = (zetasql::ASTDropSearchIndexStatement *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTDropSearchIndexStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTDropSearchIndexStatement *node = (zetasql::ASTDropSearchIndexStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTDropSearchIndexStatement_table_name)(void * arg0,void ** arg1){
  zetasql::ASTDropSearchIndexStatement *node = (zetasql::ASTDropSearchIndexStatement *)arg0;
  *arg1 = (void *)node->table_name();
}

void GO_EXPORT(ASTRenameStatement_identifier)(void * arg0,void ** arg1){
  zetasql::ASTRenameStatement *node = (zetasql::ASTRenameStatement *)arg0;
  *arg1 = (void *)node->identifier();
}

void GO_EXPORT(ASTRenameStatement_old_name)(void * arg0,void ** arg1){
  zetasql::ASTRenameStatement *node = (zetasql::ASTRenameStatement *)arg0;
  *arg1 = (void *)node->old_name();
}

void GO_EXPORT(ASTRenameStatement_new_name)(void * arg0,void ** arg1){
  zetasql::ASTRenameStatement *node = (zetasql::ASTRenameStatement *)arg0;
  *arg1 = (void *)node->new_name();
}

void GO_EXPORT(ASTImportStatement_set_import_kind)(void * arg0,int arg1){
  zetasql::ASTImportStatement *node = (zetasql::ASTImportStatement *)arg0;
  node->set_import_kind((zetasql::ASTImportStatement::ImportKind)arg1);
}

void GO_EXPORT(ASTImportStatement_import_kind)(void * arg0,int* arg1){
  zetasql::ASTImportStatement *node = (zetasql::ASTImportStatement *)arg0;
  *arg1 = node->import_kind();
}

void GO_EXPORT(ASTImportStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTImportStatement *node = (zetasql::ASTImportStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTImportStatement_string_value)(void * arg0,void ** arg1){
  zetasql::ASTImportStatement *node = (zetasql::ASTImportStatement *)arg0;
  *arg1 = (void *)node->string_value();
}

void GO_EXPORT(ASTImportStatement_alias)(void * arg0,void ** arg1){
  zetasql::ASTImportStatement *node = (zetasql::ASTImportStatement *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTImportStatement_into_alias)(void * arg0,void ** arg1){
  zetasql::ASTImportStatement *node = (zetasql::ASTImportStatement *)arg0;
  *arg1 = (void *)node->into_alias();
}

void GO_EXPORT(ASTImportStatement_options_list)(void * arg0,void ** arg1){
  zetasql::ASTImportStatement *node = (zetasql::ASTImportStatement *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTModuleStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTModuleStatement *node = (zetasql::ASTModuleStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTModuleStatement_options_list)(void * arg0,void ** arg1){
  zetasql::ASTModuleStatement *node = (zetasql::ASTModuleStatement *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTWithConnectionClause_connection_clause)(void * arg0,void ** arg1){
  zetasql::ASTWithConnectionClause *node = (zetasql::ASTWithConnectionClause *)arg0;
  *arg1 = (void *)node->connection_clause();
}

void GO_EXPORT(ASTIntoAlias_identifier)(void * arg0,void ** arg1){
  zetasql::ASTIntoAlias *node = (zetasql::ASTIntoAlias *)arg0;
  *arg1 = (void *)node->identifier();
}

void GO_EXPORT(ASTIntoAlias_GetAsString)(void * arg0,void ** arg1){
  zetasql::ASTIntoAlias *node = (zetasql::ASTIntoAlias *)arg0;
  *arg1 = (void *)((new std::string(node->GetAsString()))->c_str());
}

void GO_EXPORT(ASTUnnestExpressionWithOptAliasAndOffset_unnest_expression)(void * arg0,void ** arg1){
  zetasql::ASTUnnestExpressionWithOptAliasAndOffset *node = (zetasql::ASTUnnestExpressionWithOptAliasAndOffset *)arg0;
  *arg1 = (void *)node->unnest_expression();
}

void GO_EXPORT(ASTUnnestExpressionWithOptAliasAndOffset_optional_alias)(void * arg0,void ** arg1){
  zetasql::ASTUnnestExpressionWithOptAliasAndOffset *node = (zetasql::ASTUnnestExpressionWithOptAliasAndOffset *)arg0;
  *arg1 = (void *)node->optional_alias();
}

void GO_EXPORT(ASTUnnestExpressionWithOptAliasAndOffset_optional_with_offset)(void * arg0,void ** arg1){
  zetasql::ASTUnnestExpressionWithOptAliasAndOffset *node = (zetasql::ASTUnnestExpressionWithOptAliasAndOffset *)arg0;
  *arg1 = (void *)node->optional_with_offset();
}

void GO_EXPORT(ASTPivotExpression_expression)(void * arg0,void ** arg1){
  zetasql::ASTPivotExpression *node = (zetasql::ASTPivotExpression *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTPivotExpression_alias)(void * arg0,void ** arg1){
  zetasql::ASTPivotExpression *node = (zetasql::ASTPivotExpression *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTPivotValue_value)(void * arg0,void ** arg1){
  zetasql::ASTPivotValue *node = (zetasql::ASTPivotValue *)arg0;
  *arg1 = (void *)node->value();
}

void GO_EXPORT(ASTPivotValue_alias)(void * arg0,void ** arg1){
  zetasql::ASTPivotValue *node = (zetasql::ASTPivotValue *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTPivotExpressionList_expressions_num)(void * arg0,int* arg1){
  zetasql::ASTPivotExpressionList *node = (zetasql::ASTPivotExpressionList *)arg0;
  *arg1 = node->expressions().length();
}

void GO_EXPORT(ASTPivotExpressionList_expression)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTPivotExpressionList *node = (zetasql::ASTPivotExpressionList *)arg0;
  *arg2 = (void *)node->expressions(arg1);
}

void GO_EXPORT(ASTPivotValueList_values_num)(void * arg0,int* arg1){
  zetasql::ASTPivotValueList *node = (zetasql::ASTPivotValueList *)arg0;
  *arg1 = node->values().length();
}

void GO_EXPORT(ASTPivotValueList_value)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTPivotValueList *node = (zetasql::ASTPivotValueList *)arg0;
  *arg2 = (void *)node->values(arg1);
}

void GO_EXPORT(ASTPivotClause_pivot_expressions)(void * arg0,void ** arg1){
  zetasql::ASTPivotClause *node = (zetasql::ASTPivotClause *)arg0;
  *arg1 = (void *)node->pivot_expressions();
}

void GO_EXPORT(ASTPivotClause_for_expression)(void * arg0,void ** arg1){
  zetasql::ASTPivotClause *node = (zetasql::ASTPivotClause *)arg0;
  *arg1 = (void *)node->for_expression();
}

void GO_EXPORT(ASTPivotClause_pivot_values)(void * arg0,void ** arg1){
  zetasql::ASTPivotClause *node = (zetasql::ASTPivotClause *)arg0;
  *arg1 = (void *)node->pivot_values();
}

void GO_EXPORT(ASTPivotClause_output_alias)(void * arg0,void ** arg1){
  zetasql::ASTPivotClause *node = (zetasql::ASTPivotClause *)arg0;
  *arg1 = (void *)node->output_alias();
}

void GO_EXPORT(ASTUnpivotInItem_unpivot_columns)(void * arg0,void ** arg1){
  zetasql::ASTUnpivotInItem *node = (zetasql::ASTUnpivotInItem *)arg0;
  *arg1 = (void *)node->unpivot_columns();
}

void GO_EXPORT(ASTUnpivotInItem_alias)(void * arg0,void ** arg1){
  zetasql::ASTUnpivotInItem *node = (zetasql::ASTUnpivotInItem *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTUnpivotInItemList_in_items_num)(void * arg0,int* arg1){
  zetasql::ASTUnpivotInItemList *node = (zetasql::ASTUnpivotInItemList *)arg0;
  *arg1 = node->in_items().length();
}

void GO_EXPORT(ASTUnpivotInItemList_in_item)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTUnpivotInItemList *node = (zetasql::ASTUnpivotInItemList *)arg0;
  *arg2 = (void *)node->in_items(arg1);
}

void GO_EXPORT(ASTUnpivotClause_set_null_filter)(void * arg0,int arg1){
  zetasql::ASTUnpivotClause *node = (zetasql::ASTUnpivotClause *)arg0;
  node->set_null_filter((zetasql::ASTUnpivotClause::NullFilter)arg1);
}

void GO_EXPORT(ASTUnpivotClause_null_filter)(void * arg0,int* arg1){
  zetasql::ASTUnpivotClause *node = (zetasql::ASTUnpivotClause *)arg0;
  *arg1 = node->null_filter();
}

void GO_EXPORT(ASTUnpivotClause_unpivot_output_value_columns)(void * arg0,void ** arg1){
  zetasql::ASTUnpivotClause *node = (zetasql::ASTUnpivotClause *)arg0;
  *arg1 = (void *)node->unpivot_output_value_columns();
}

void GO_EXPORT(ASTUnpivotClause_unpivot_output_name_column)(void * arg0,void ** arg1){
  zetasql::ASTUnpivotClause *node = (zetasql::ASTUnpivotClause *)arg0;
  *arg1 = (void *)node->unpivot_output_name_column();
}

void GO_EXPORT(ASTUnpivotClause_unpivot_in_items)(void * arg0,void ** arg1){
  zetasql::ASTUnpivotClause *node = (zetasql::ASTUnpivotClause *)arg0;
  *arg1 = (void *)node->unpivot_in_items();
}

void GO_EXPORT(ASTUnpivotClause_output_alias)(void * arg0,void ** arg1){
  zetasql::ASTUnpivotClause *node = (zetasql::ASTUnpivotClause *)arg0;
  *arg1 = (void *)node->output_alias();
}

void GO_EXPORT(ASTUsingClause_keys_num)(void * arg0,int* arg1){
  zetasql::ASTUsingClause *node = (zetasql::ASTUsingClause *)arg0;
  *arg1 = node->keys().length();
}

void GO_EXPORT(ASTUsingClause_key)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTUsingClause *node = (zetasql::ASTUsingClause *)arg0;
  *arg2 = (void *)node->keys(arg1);
}

void GO_EXPORT(ASTForSystemTime_expression)(void * arg0,void ** arg1){
  zetasql::ASTForSystemTime *node = (zetasql::ASTForSystemTime *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTQualify_expression)(void * arg0,void ** arg1){
  zetasql::ASTQualify *node = (zetasql::ASTQualify *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTClampedBetweenModifier_low)(void * arg0,void ** arg1){
  zetasql::ASTClampedBetweenModifier *node = (zetasql::ASTClampedBetweenModifier *)arg0;
  *arg1 = (void *)node->low();
}

void GO_EXPORT(ASTClampedBetweenModifier_high)(void * arg0,void ** arg1){
  zetasql::ASTClampedBetweenModifier *node = (zetasql::ASTClampedBetweenModifier *)arg0;
  *arg1 = (void *)node->high();
}

void GO_EXPORT(ASTFormatClause_format)(void * arg0,void ** arg1){
  zetasql::ASTFormatClause *node = (zetasql::ASTFormatClause *)arg0;
  *arg1 = (void *)node->format();
}

void GO_EXPORT(ASTFormatClause_time_zone_expr)(void * arg0,void ** arg1){
  zetasql::ASTFormatClause *node = (zetasql::ASTFormatClause *)arg0;
  *arg1 = (void *)node->time_zone_expr();
}

void GO_EXPORT(ASTPathExpressionList_path_expression_list_num)(void * arg0,int* arg1){
  zetasql::ASTPathExpressionList *node = (zetasql::ASTPathExpressionList *)arg0;
  *arg1 = node->path_expression_list().length();
}

void GO_EXPORT(ASTPathExpressionList_path_expression_list)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTPathExpressionList *node = (zetasql::ASTPathExpressionList *)arg0;
  *arg2 = (void *)node->path_expression_list(arg1);
}

void GO_EXPORT(ASTParameterExpr_set_position)(void * arg0,int arg1){
  zetasql::ASTParameterExpr *node = (zetasql::ASTParameterExpr *)arg0;
  node->set_position(arg1);
}

void GO_EXPORT(ASTParameterExpr_position)(void * arg0,int* arg1){
  zetasql::ASTParameterExpr *node = (zetasql::ASTParameterExpr *)arg0;
  *arg1 = node->position();
}

void GO_EXPORT(ASTParameterExpr_name)(void * arg0,void ** arg1){
  zetasql::ASTParameterExpr *node = (zetasql::ASTParameterExpr *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTSystemVariableExpr_path)(void * arg0,void ** arg1){
  zetasql::ASTSystemVariableExpr *node = (zetasql::ASTSystemVariableExpr *)arg0;
  *arg1 = (void *)node->path();
}

void GO_EXPORT(ASTWithGroupRows_subquery)(void * arg0,void ** arg1){
  zetasql::ASTWithGroupRows *node = (zetasql::ASTWithGroupRows *)arg0;
  *arg1 = (void *)node->subquery();
}

void GO_EXPORT(ASTLambda_argument_list)(void * arg0,void ** arg1){
  zetasql::ASTLambda *node = (zetasql::ASTLambda *)arg0;
  *arg1 = (void *)node->argument_list();
}

void GO_EXPORT(ASTLambda_body)(void * arg0,void ** arg1){
  zetasql::ASTLambda *node = (zetasql::ASTLambda *)arg0;
  *arg1 = (void *)node->body();
}

void GO_EXPORT(ASTAnalyticFunctionCall_window_spec)(void * arg0,void ** arg1){
  zetasql::ASTAnalyticFunctionCall *node = (zetasql::ASTAnalyticFunctionCall *)arg0;
  *arg1 = (void *)node->window_spec();
}

void GO_EXPORT(ASTAnalyticFunctionCall_function)(void * arg0,void ** arg1){
  zetasql::ASTAnalyticFunctionCall *node = (zetasql::ASTAnalyticFunctionCall *)arg0;
  *arg1 = (void *)node->function();
}

void GO_EXPORT(ASTAnalyticFunctionCall_function_with_group_rows)(void * arg0,void ** arg1){
  zetasql::ASTAnalyticFunctionCall *node = (zetasql::ASTAnalyticFunctionCall *)arg0;
  *arg1 = (void *)node->function_with_group_rows();
}

void GO_EXPORT(ASTFunctionCallWithGroupRows_function)(void * arg0,void ** arg1){
  zetasql::ASTFunctionCallWithGroupRows *node = (zetasql::ASTFunctionCallWithGroupRows *)arg0;
  *arg1 = (void *)node->function();
}

void GO_EXPORT(ASTFunctionCallWithGroupRows_subquery)(void * arg0,void ** arg1){
  zetasql::ASTFunctionCallWithGroupRows *node = (zetasql::ASTFunctionCallWithGroupRows *)arg0;
  *arg1 = (void *)node->subquery();
}

void GO_EXPORT(ASTClusterBy_clustering_expressions_num)(void * arg0,int* arg1){
  zetasql::ASTClusterBy *node = (zetasql::ASTClusterBy *)arg0;
  *arg1 = node->clustering_expressions().length();
}

void GO_EXPORT(ASTClusterBy_clustering_expression)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTClusterBy *node = (zetasql::ASTClusterBy *)arg0;
  *arg2 = (void *)node->clustering_expressions(arg1);
}

void GO_EXPORT(ASTNewConstructorArg_expression)(void * arg0,void ** arg1){
  zetasql::ASTNewConstructorArg *node = (zetasql::ASTNewConstructorArg *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTNewConstructorArg_optional_identifier)(void * arg0,void ** arg1){
  zetasql::ASTNewConstructorArg *node = (zetasql::ASTNewConstructorArg *)arg0;
  *arg1 = (void *)node->optional_identifier();
}

void GO_EXPORT(ASTNewConstructorArg_optional_path_expression)(void * arg0,void ** arg1){
  zetasql::ASTNewConstructorArg *node = (zetasql::ASTNewConstructorArg *)arg0;
  *arg1 = (void *)node->optional_path_expression();
}

void GO_EXPORT(ASTNewConstructor_type_name)(void * arg0,void ** arg1){
  zetasql::ASTNewConstructor *node = (zetasql::ASTNewConstructor *)arg0;
  *arg1 = (void *)node->type_name();
}

void GO_EXPORT(ASTNewConstructor_arguments_num)(void * arg0,int* arg1){
  zetasql::ASTNewConstructor *node = (zetasql::ASTNewConstructor *)arg0;
  *arg1 = node->arguments().length();
}

void GO_EXPORT(ASTNewConstructor_argument)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTNewConstructor *node = (zetasql::ASTNewConstructor *)arg0;
  *arg2 = (void *)node->arguments(arg1);
}

void GO_EXPORT(ASTOptionsList_options_entries_num)(void * arg0,int* arg1){
  zetasql::ASTOptionsList *node = (zetasql::ASTOptionsList *)arg0;
  *arg1 = node->options_entries().length();
}

void GO_EXPORT(ASTOptionsList_options_entry)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTOptionsList *node = (zetasql::ASTOptionsList *)arg0;
  *arg2 = (void *)node->options_entries(arg1);
}

void GO_EXPORT(ASTOptionsEntry_name)(void * arg0,void ** arg1){
  zetasql::ASTOptionsEntry *node = (zetasql::ASTOptionsEntry *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTOptionsEntry_value)(void * arg0,void ** arg1){
  zetasql::ASTOptionsEntry *node = (zetasql::ASTOptionsEntry *)arg0;
  *arg1 = (void *)node->value();
}

void GO_EXPORT(ASTCreateStatement_set_scope)(void * arg0,int arg1){
  zetasql::ASTCreateStatement *node = (zetasql::ASTCreateStatement *)arg0;
  node->set_scope((zetasql::ASTCreateStatement::Scope)arg1);
}

void GO_EXPORT(ASTCreateStatement_scope)(void * arg0,int* arg1){
  zetasql::ASTCreateStatement *node = (zetasql::ASTCreateStatement *)arg0;
  *arg1 = node->scope();
}

void GO_EXPORT(ASTCreateStatement_set_is_or_replace)(void * arg0,int arg1){
  zetasql::ASTCreateStatement *node = (zetasql::ASTCreateStatement *)arg0;
  node->set_is_or_replace(arg1);
}

void GO_EXPORT(ASTCreateStatement_is_or_replace)(void * arg0,char* arg1){
  zetasql::ASTCreateStatement *node = (zetasql::ASTCreateStatement *)arg0;
  *arg1 = node->is_or_replace();
}

void GO_EXPORT(ASTCreateStatement_set_is_if_not_exists)(void * arg0,int arg1){
  zetasql::ASTCreateStatement *node = (zetasql::ASTCreateStatement *)arg0;
}

void GO_EXPORT(ASTCreateStatement_is_if_not_exists)(void * arg0,char* arg1){
  zetasql::ASTCreateStatement *node = (zetasql::ASTCreateStatement *)arg0;
  *arg1 = node->is_if_not_exists();
}

void GO_EXPORT(ASTCreateStatement_is_default_scope)(void * arg0,char* arg1){
  zetasql::ASTCreateStatement *node = (zetasql::ASTCreateStatement *)arg0;
  *arg1 = node->is_default_scope();
}

void GO_EXPORT(ASTCreateStatement_is_private)(void * arg0,char* arg1){
  zetasql::ASTCreateStatement *node = (zetasql::ASTCreateStatement *)arg0;
  *arg1 = node->is_private();
}

void GO_EXPORT(ASTCreateStatement_is_public)(void * arg0,char* arg1){
  zetasql::ASTCreateStatement *node = (zetasql::ASTCreateStatement *)arg0;
  *arg1 = node->is_public();
}

void GO_EXPORT(ASTCreateStatement_is_temp)(void * arg0,char* arg1){
  zetasql::ASTCreateStatement *node = (zetasql::ASTCreateStatement *)arg0;
  *arg1 = node->is_temp();
}

void GO_EXPORT(ASTFunctionParameter_set_procedure_parameter_mode)(void * arg0,int arg1){
  zetasql::ASTFunctionParameter *node = (zetasql::ASTFunctionParameter *)arg0;
  node->set_procedure_parameter_mode((zetasql::ASTFunctionParameter::ProcedureParameterMode)arg1);
}

void GO_EXPORT(ASTFunctionParameter_procedure_parameter_mode)(void * arg0,int* arg1){
  zetasql::ASTFunctionParameter *node = (zetasql::ASTFunctionParameter *)arg0;
  *arg1 = node->procedure_parameter_mode();
}

void GO_EXPORT(ASTFunctionParameter_set_is_not_aggregate)(void * arg0,int arg1){
  zetasql::ASTFunctionParameter *node = (zetasql::ASTFunctionParameter *)arg0;
  node->set_is_not_aggregate(arg1);
}

void GO_EXPORT(ASTFunctionParameter_is_not_aggregate)(void * arg0,char* arg1){
  zetasql::ASTFunctionParameter *node = (zetasql::ASTFunctionParameter *)arg0;
  *arg1 = node->is_not_aggregate();
}

void GO_EXPORT(ASTFunctionParameter_name)(void * arg0,void ** arg1){
  zetasql::ASTFunctionParameter *node = (zetasql::ASTFunctionParameter *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTFunctionParameter_type)(void * arg0,void ** arg1){
  zetasql::ASTFunctionParameter *node = (zetasql::ASTFunctionParameter *)arg0;
  *arg1 = (void *)node->type();
}

void GO_EXPORT(ASTFunctionParameter_templated_parameter_type)(void * arg0,void ** arg1){
  zetasql::ASTFunctionParameter *node = (zetasql::ASTFunctionParameter *)arg0;
  *arg1 = (void *)node->templated_parameter_type();
}

void GO_EXPORT(ASTFunctionParameter_tvf_schema)(void * arg0,void ** arg1){
  zetasql::ASTFunctionParameter *node = (zetasql::ASTFunctionParameter *)arg0;
  *arg1 = (void *)node->tvf_schema();
}

void GO_EXPORT(ASTFunctionParameter_alias)(void * arg0,void ** arg1){
  zetasql::ASTFunctionParameter *node = (zetasql::ASTFunctionParameter *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTFunctionParameter_default_value)(void * arg0,void ** arg1){
  zetasql::ASTFunctionParameter *node = (zetasql::ASTFunctionParameter *)arg0;
  *arg1 = (void *)node->default_value();
}

void GO_EXPORT(ASTFunctionParameter_IsTableParameter)(void * arg0,char* arg1){
  zetasql::ASTFunctionParameter *node = (zetasql::ASTFunctionParameter *)arg0;
  *arg1 = node->IsTableParameter();
}

void GO_EXPORT(ASTFunctionParameter_IsTemplated)(void * arg0,char* arg1){
  zetasql::ASTFunctionParameter *node = (zetasql::ASTFunctionParameter *)arg0;
  *arg1 = node->IsTemplated();
}

void GO_EXPORT(ASTFunctionParameters_parameter_entries_num)(void * arg0,int* arg1){
  zetasql::ASTFunctionParameters *node = (zetasql::ASTFunctionParameters *)arg0;
  *arg1 = node->parameter_entries().length();
}

void GO_EXPORT(ASTFunctionParameters_parameter_entry)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTFunctionParameters *node = (zetasql::ASTFunctionParameters *)arg0;
  *arg2 = (void *)node->parameter_entries(arg1);
}

void GO_EXPORT(ASTFunctionDeclaration_name)(void * arg0,void ** arg1){
  zetasql::ASTFunctionDeclaration *node = (zetasql::ASTFunctionDeclaration *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTFunctionDeclaration_parameters)(void * arg0,void ** arg1){
  zetasql::ASTFunctionDeclaration *node = (zetasql::ASTFunctionDeclaration *)arg0;
  *arg1 = (void *)node->parameters();
}

void GO_EXPORT(ASTFunctionDeclaration_IsTemplated)(void * arg0,char* arg1){
  zetasql::ASTFunctionDeclaration *node = (zetasql::ASTFunctionDeclaration *)arg0;
  *arg1 = node->IsTemplated();
}

void GO_EXPORT(ASTSqlFunctionBody_expression)(void * arg0,void ** arg1){
  zetasql::ASTSqlFunctionBody *node = (zetasql::ASTSqlFunctionBody *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTTVFArgument_expr)(void * arg0,void ** arg1){
  zetasql::ASTTVFArgument *node = (zetasql::ASTTVFArgument *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ASTTVFArgument_table_clause)(void * arg0,void ** arg1){
  zetasql::ASTTVFArgument *node = (zetasql::ASTTVFArgument *)arg0;
  *arg1 = (void *)node->table_clause();
}

void GO_EXPORT(ASTTVFArgument_model_clause)(void * arg0,void ** arg1){
  zetasql::ASTTVFArgument *node = (zetasql::ASTTVFArgument *)arg0;
  *arg1 = (void *)node->model_clause();
}

void GO_EXPORT(ASTTVFArgument_connection_clause)(void * arg0,void ** arg1){
  zetasql::ASTTVFArgument *node = (zetasql::ASTTVFArgument *)arg0;
  *arg1 = (void *)node->connection_clause();
}

void GO_EXPORT(ASTTVFArgument_descriptor)(void * arg0,void ** arg1){
  zetasql::ASTTVFArgument *node = (zetasql::ASTTVFArgument *)arg0;
  *arg1 = (void *)node->descriptor();
}

void GO_EXPORT(ASTTVF_name)(void * arg0,void ** arg1){
  zetasql::ASTTVF *node = (zetasql::ASTTVF *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTTVF_hint)(void * arg0,void ** arg1){
  zetasql::ASTTVF *node = (zetasql::ASTTVF *)arg0;
  *arg1 = (void *)node->hint();
}

void GO_EXPORT(ASTTVF_alias)(void * arg0,void ** arg1){
  zetasql::ASTTVF *node = (zetasql::ASTTVF *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTTVF_pivot_clause)(void * arg0,void ** arg1){
  zetasql::ASTTVF *node = (zetasql::ASTTVF *)arg0;
  *arg1 = (void *)node->pivot_clause();
}

void GO_EXPORT(ASTTVF_unpivot_clause)(void * arg0,void ** arg1){
  zetasql::ASTTVF *node = (zetasql::ASTTVF *)arg0;
  *arg1 = (void *)node->unpivot_clause();
}

void GO_EXPORT(ASTTVF_sample)(void * arg0,void ** arg1){
  zetasql::ASTTVF *node = (zetasql::ASTTVF *)arg0;
  *arg1 = (void *)node->sample();
}

void GO_EXPORT(ASTTVF_argument_entries_num)(void * arg0,int* arg1){
  zetasql::ASTTVF *node = (zetasql::ASTTVF *)arg0;
  *arg1 = node->argument_entries().length();
}

void GO_EXPORT(ASTTVF_argument_entry)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTTVF *node = (zetasql::ASTTVF *)arg0;
  *arg2 = (void *)node->argument_entries(arg1);
}

void GO_EXPORT(ASTTableClause_table_path)(void * arg0,void ** arg1){
  zetasql::ASTTableClause *node = (zetasql::ASTTableClause *)arg0;
  *arg1 = (void *)node->table_path();
}

void GO_EXPORT(ASTTableClause_tvf)(void * arg0,void ** arg1){
  zetasql::ASTTableClause *node = (zetasql::ASTTableClause *)arg0;
  *arg1 = (void *)node->tvf();
}

void GO_EXPORT(ASTModelClause_model_path)(void * arg0,void ** arg1){
  zetasql::ASTModelClause *node = (zetasql::ASTModelClause *)arg0;
  *arg1 = (void *)node->model_path();
}

void GO_EXPORT(ASTConnectionClause_connection_path)(void * arg0,void ** arg1){
  zetasql::ASTConnectionClause *node = (zetasql::ASTConnectionClause *)arg0;
  *arg1 = (void *)node->connection_path();
}

void GO_EXPORT(ASTTableDataSource_path_expr)(void * arg0,void ** arg1){
  zetasql::ASTTableDataSource *node = (zetasql::ASTTableDataSource *)arg0;
  *arg1 = (void *)node->path_expr();
}

void GO_EXPORT(ASTTableDataSource_for_system_time)(void * arg0,void ** arg1){
  zetasql::ASTTableDataSource *node = (zetasql::ASTTableDataSource *)arg0;
  *arg1 = (void *)node->for_system_time();
}

void GO_EXPORT(ASTTableDataSource_where_clause)(void * arg0,void ** arg1){
  zetasql::ASTTableDataSource *node = (zetasql::ASTTableDataSource *)arg0;
  *arg1 = (void *)node->where_clause();
}

void GO_EXPORT(ASTCloneDataSourceList_data_sources_num)(void * arg0,int* arg1){
  zetasql::ASTCloneDataSourceList *node = (zetasql::ASTCloneDataSourceList *)arg0;
  *arg1 = node->data_sources().length();
}

void GO_EXPORT(ASTCloneDataSourceList_data_source)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTCloneDataSourceList *node = (zetasql::ASTCloneDataSourceList *)arg0;
  *arg2 = (void *)node->data_sources(arg1);
}

void GO_EXPORT(ASTCloneDataStatement_target_path)(void * arg0,void ** arg1){
  zetasql::ASTCloneDataStatement *node = (zetasql::ASTCloneDataStatement *)arg0;
  *arg1 = (void *)node->target_path();
}

void GO_EXPORT(ASTCloneDataStatement_data_source_list)(void * arg0,void ** arg1){
  zetasql::ASTCloneDataStatement *node = (zetasql::ASTCloneDataStatement *)arg0;
  *arg1 = (void *)node->data_source_list();
}

void GO_EXPORT(ASTCreateConstantStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTCreateConstantStatement *node = (zetasql::ASTCreateConstantStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTCreateConstantStatement_expr)(void * arg0,void ** arg1){
  zetasql::ASTCreateConstantStatement *node = (zetasql::ASTCreateConstantStatement *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ASTCreateDatabaseStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTCreateDatabaseStatement *node = (zetasql::ASTCreateDatabaseStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTCreateDatabaseStatement_options_list)(void * arg0,void ** arg1){
  zetasql::ASTCreateDatabaseStatement *node = (zetasql::ASTCreateDatabaseStatement *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTCreateProcedureStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTCreateProcedureStatement *node = (zetasql::ASTCreateProcedureStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTCreateProcedureStatement_parameters)(void * arg0,void ** arg1){
  zetasql::ASTCreateProcedureStatement *node = (zetasql::ASTCreateProcedureStatement *)arg0;
  *arg1 = (void *)node->parameters();
}

void GO_EXPORT(ASTCreateProcedureStatement_options_list)(void * arg0,void ** arg1){
  zetasql::ASTCreateProcedureStatement *node = (zetasql::ASTCreateProcedureStatement *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTCreateProcedureStatement_body)(void * arg0,void ** arg1){
  zetasql::ASTCreateProcedureStatement *node = (zetasql::ASTCreateProcedureStatement *)arg0;
  *arg1 = (void *)node->body();
}

void GO_EXPORT(ASTCreateSchemaStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTCreateSchemaStatement *node = (zetasql::ASTCreateSchemaStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTCreateSchemaStatement_collate)(void * arg0,void ** arg1){
  zetasql::ASTCreateSchemaStatement *node = (zetasql::ASTCreateSchemaStatement *)arg0;
  *arg1 = (void *)node->collate();
}

void GO_EXPORT(ASTCreateSchemaStatement_options_list)(void * arg0,void ** arg1){
  zetasql::ASTCreateSchemaStatement *node = (zetasql::ASTCreateSchemaStatement *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTTransformClause_select_list)(void * arg0,void ** arg1){
  zetasql::ASTTransformClause *node = (zetasql::ASTTransformClause *)arg0;
  *arg1 = (void *)node->select_list();
}

void GO_EXPORT(ASTCreateModelStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTCreateModelStatement *node = (zetasql::ASTCreateModelStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTCreateModelStatement_transform_clause)(void * arg0,void ** arg1){
  zetasql::ASTCreateModelStatement *node = (zetasql::ASTCreateModelStatement *)arg0;
  *arg1 = (void *)node->transform_clause();
}

void GO_EXPORT(ASTCreateModelStatement_options_list)(void * arg0,void ** arg1){
  zetasql::ASTCreateModelStatement *node = (zetasql::ASTCreateModelStatement *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTCreateModelStatement_query)(void * arg0,void ** arg1){
  zetasql::ASTCreateModelStatement *node = (zetasql::ASTCreateModelStatement *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ASTIndexItemList_ordering_expressions_num)(void * arg0,int* arg1){
  zetasql::ASTIndexItemList *node = (zetasql::ASTIndexItemList *)arg0;
  *arg1 = node->ordering_expressions().length();
}

void GO_EXPORT(ASTIndexItemList_ordering_expression)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTIndexItemList *node = (zetasql::ASTIndexItemList *)arg0;
  *arg2 = (void *)node->ordering_expressions(arg1);
}

void GO_EXPORT(ASTIndexStoringExpressionList_expressions_num)(void * arg0,int* arg1){
  zetasql::ASTIndexStoringExpressionList *node = (zetasql::ASTIndexStoringExpressionList *)arg0;
  *arg1 = node->expressions().length();
}

void GO_EXPORT(ASTIndexStoringExpressionList_expression)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTIndexStoringExpressionList *node = (zetasql::ASTIndexStoringExpressionList *)arg0;
  *arg2 = (void *)node->expressions(arg1);
}

void GO_EXPORT(ASTIndexUnnestExpressionList_unnest_expressions_num)(void * arg0,int* arg1){
  zetasql::ASTIndexUnnestExpressionList *node = (zetasql::ASTIndexUnnestExpressionList *)arg0;
  *arg1 = node->unnest_expressions().length();
}

void GO_EXPORT(ASTIndexUnnestExpressionList_unnest_expression)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTIndexUnnestExpressionList *node = (zetasql::ASTIndexUnnestExpressionList *)arg0;
  *arg2 = (void *)node->unnest_expressions(arg1);
}

void GO_EXPORT(ASTCreateIndexStatement_set_is_unique)(void * arg0,int arg1){
  zetasql::ASTCreateIndexStatement *node = (zetasql::ASTCreateIndexStatement *)arg0;
  node->set_is_unique(arg1);
}

void GO_EXPORT(ASTCreateIndexStatement_is_unique)(void * arg0,char* arg1){
  zetasql::ASTCreateIndexStatement *node = (zetasql::ASTCreateIndexStatement *)arg0;
  *arg1 = node->is_unique();
}

void GO_EXPORT(ASTCreateIndexStatement_set_is_search)(void * arg0,int arg1){
  zetasql::ASTCreateIndexStatement *node = (zetasql::ASTCreateIndexStatement *)arg0;
  node->set_is_search(arg1);
}

void GO_EXPORT(ASTCreateIndexStatement_is_search)(void * arg0,char* arg1){
  zetasql::ASTCreateIndexStatement *node = (zetasql::ASTCreateIndexStatement *)arg0;
  *arg1 = node->is_search();
}

void GO_EXPORT(ASTCreateIndexStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTCreateIndexStatement *node = (zetasql::ASTCreateIndexStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTCreateIndexStatement_table_name)(void * arg0,void ** arg1){
  zetasql::ASTCreateIndexStatement *node = (zetasql::ASTCreateIndexStatement *)arg0;
  *arg1 = (void *)node->table_name();
}

void GO_EXPORT(ASTCreateIndexStatement_optional_table_alias)(void * arg0,void ** arg1){
  zetasql::ASTCreateIndexStatement *node = (zetasql::ASTCreateIndexStatement *)arg0;
  *arg1 = (void *)node->optional_table_alias();
}

void GO_EXPORT(ASTCreateIndexStatement_optional_index_unnest_expression_list)(void * arg0,void ** arg1){
  zetasql::ASTCreateIndexStatement *node = (zetasql::ASTCreateIndexStatement *)arg0;
  *arg1 = (void *)node->optional_index_unnest_expression_list();
}

void GO_EXPORT(ASTCreateIndexStatement_index_item_list)(void * arg0,void ** arg1){
  zetasql::ASTCreateIndexStatement *node = (zetasql::ASTCreateIndexStatement *)arg0;
  *arg1 = (void *)node->index_item_list();
}

void GO_EXPORT(ASTCreateIndexStatement_optional_index_storing_expressions)(void * arg0,void ** arg1){
  zetasql::ASTCreateIndexStatement *node = (zetasql::ASTCreateIndexStatement *)arg0;
  *arg1 = (void *)node->optional_index_storing_expressions();
}

void GO_EXPORT(ASTCreateIndexStatement_options_list)(void * arg0,void ** arg1){
  zetasql::ASTCreateIndexStatement *node = (zetasql::ASTCreateIndexStatement *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTExportDataStatement_with_connection_clause)(void * arg0,void ** arg1){
  zetasql::ASTExportDataStatement *node = (zetasql::ASTExportDataStatement *)arg0;
  *arg1 = (void *)node->with_connection_clause();
}

void GO_EXPORT(ASTExportDataStatement_options_list)(void * arg0,void ** arg1){
  zetasql::ASTExportDataStatement *node = (zetasql::ASTExportDataStatement *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTExportDataStatement_query)(void * arg0,void ** arg1){
  zetasql::ASTExportDataStatement *node = (zetasql::ASTExportDataStatement *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ASTExportModelStatement_model_name_path)(void * arg0,void ** arg1){
  zetasql::ASTExportModelStatement *node = (zetasql::ASTExportModelStatement *)arg0;
  *arg1 = (void *)node->model_name_path();
}

void GO_EXPORT(ASTExportModelStatement_with_connection_clause)(void * arg0,void ** arg1){
  zetasql::ASTExportModelStatement *node = (zetasql::ASTExportModelStatement *)arg0;
  *arg1 = (void *)node->with_connection_clause();
}

void GO_EXPORT(ASTExportModelStatement_options_list)(void * arg0,void ** arg1){
  zetasql::ASTExportModelStatement *node = (zetasql::ASTExportModelStatement *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTCallStatement_procedure_name)(void * arg0,void ** arg1){
  zetasql::ASTCallStatement *node = (zetasql::ASTCallStatement *)arg0;
  *arg1 = (void *)node->procedure_name();
}

void GO_EXPORT(ASTCallStatement_arguments_num)(void * arg0,int* arg1){
  zetasql::ASTCallStatement *node = (zetasql::ASTCallStatement *)arg0;
  *arg1 = node->arguments().length();
}

void GO_EXPORT(ASTCallStatement_argument)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTCallStatement *node = (zetasql::ASTCallStatement *)arg0;
  *arg2 = (void *)node->arguments(arg1);
}

void GO_EXPORT(ASTDefineTableStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTDefineTableStatement *node = (zetasql::ASTDefineTableStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTDefineTableStatement_options_list)(void * arg0,void ** arg1){
  zetasql::ASTDefineTableStatement *node = (zetasql::ASTDefineTableStatement *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTWithPartitionColumnsClause_table_element_list)(void * arg0,void ** arg1){
  zetasql::ASTWithPartitionColumnsClause *node = (zetasql::ASTWithPartitionColumnsClause *)arg0;
  *arg1 = (void *)node->table_element_list();
}

void GO_EXPORT(ASTCreateSnapshotTableStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTCreateSnapshotTableStatement *node = (zetasql::ASTCreateSnapshotTableStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTCreateSnapshotTableStatement_clone_data_source)(void * arg0,void ** arg1){
  zetasql::ASTCreateSnapshotTableStatement *node = (zetasql::ASTCreateSnapshotTableStatement *)arg0;
  *arg1 = (void *)node->clone_data_source();
}

void GO_EXPORT(ASTCreateSnapshotTableStatement_options_list)(void * arg0,void ** arg1){
  zetasql::ASTCreateSnapshotTableStatement *node = (zetasql::ASTCreateSnapshotTableStatement *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTTypeParameterList_parameters_num)(void * arg0,int* arg1){
  zetasql::ASTTypeParameterList *node = (zetasql::ASTTypeParameterList *)arg0;
  *arg1 = node->parameters().length();
}

void GO_EXPORT(ASTTypeParameterList_parameter)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTTypeParameterList *node = (zetasql::ASTTypeParameterList *)arg0;
  *arg2 = (void *)node->parameters(arg1);
}

void GO_EXPORT(ASTTVFSchema_columns_num)(void * arg0,int* arg1){
  zetasql::ASTTVFSchema *node = (zetasql::ASTTVFSchema *)arg0;
  *arg1 = node->columns().length();
}

void GO_EXPORT(ASTTVFSchema_column)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTTVFSchema *node = (zetasql::ASTTVFSchema *)arg0;
  *arg2 = (void *)node->columns(arg1);
}

void GO_EXPORT(ASTTVFSchemaColumn_name)(void * arg0,void ** arg1){
  zetasql::ASTTVFSchemaColumn *node = (zetasql::ASTTVFSchemaColumn *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTTVFSchemaColumn_type)(void * arg0,void ** arg1){
  zetasql::ASTTVFSchemaColumn *node = (zetasql::ASTTVFSchemaColumn *)arg0;
  *arg1 = (void *)node->type();
}

void GO_EXPORT(ASTTableAndColumnInfo_table_name)(void * arg0,void ** arg1){
  zetasql::ASTTableAndColumnInfo *node = (zetasql::ASTTableAndColumnInfo *)arg0;
  *arg1 = (void *)node->table_name();
}

void GO_EXPORT(ASTTableAndColumnInfo_column_list)(void * arg0,void ** arg1){
  zetasql::ASTTableAndColumnInfo *node = (zetasql::ASTTableAndColumnInfo *)arg0;
  *arg1 = (void *)node->column_list();
}

void GO_EXPORT(ASTTableAndColumnInfoList_table_and_column_info_entries_num)(void * arg0,int* arg1){
  zetasql::ASTTableAndColumnInfoList *node = (zetasql::ASTTableAndColumnInfoList *)arg0;
  *arg1 = node->table_and_column_info_entries().length();
}

void GO_EXPORT(ASTTableAndColumnInfoList_table_and_column_info_entry)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTTableAndColumnInfoList *node = (zetasql::ASTTableAndColumnInfoList *)arg0;
  *arg2 = (void *)node->table_and_column_info_entries(arg1);
}

void GO_EXPORT(ASTTemplatedParameterType_set_kind)(void * arg0,int arg1){
  zetasql::ASTTemplatedParameterType *node = (zetasql::ASTTemplatedParameterType *)arg0;
  node->set_kind((zetasql::ASTTemplatedParameterType::TemplatedTypeKind)arg1);
}

void GO_EXPORT(ASTTemplatedParameterType_kind)(void * arg0,int* arg1){
  zetasql::ASTTemplatedParameterType *node = (zetasql::ASTTemplatedParameterType *)arg0;
  *arg1 = node->kind();
}

void GO_EXPORT(ASTAnalyzeStatement_options_list)(void * arg0,void ** arg1){
  zetasql::ASTAnalyzeStatement *node = (zetasql::ASTAnalyzeStatement *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTAnalyzeStatement_table_and_column_info_list)(void * arg0,void ** arg1){
  zetasql::ASTAnalyzeStatement *node = (zetasql::ASTAnalyzeStatement *)arg0;
  *arg1 = (void *)node->table_and_column_info_list();
}

void GO_EXPORT(ASTAssertStatement_expr)(void * arg0,void ** arg1){
  zetasql::ASTAssertStatement *node = (zetasql::ASTAssertStatement *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ASTAssertStatement_description)(void * arg0,void ** arg1){
  zetasql::ASTAssertStatement *node = (zetasql::ASTAssertStatement *)arg0;
  *arg1 = (void *)node->description();
}

void GO_EXPORT(ASTAssertRowsModified_num_rows)(void * arg0,void ** arg1){
  zetasql::ASTAssertRowsModified *node = (zetasql::ASTAssertRowsModified *)arg0;
  *arg1 = (void *)node->num_rows();
}

void GO_EXPORT(ASTReturningClause_select_list)(void * arg0,void ** arg1){
  zetasql::ASTReturningClause *node = (zetasql::ASTReturningClause *)arg0;
  *arg1 = (void *)node->select_list();
}

void GO_EXPORT(ASTReturningClause_action_alias)(void * arg0,void ** arg1){
  zetasql::ASTReturningClause *node = (zetasql::ASTReturningClause *)arg0;
  *arg1 = (void *)node->action_alias();
}

void GO_EXPORT(ASTDeleteStatement_target_path)(void * arg0,void ** arg1){
  zetasql::ASTDeleteStatement *node = (zetasql::ASTDeleteStatement *)arg0;
  *arg1 = (void *)node->target_path();
}

void GO_EXPORT(ASTDeleteStatement_alias)(void * arg0,void ** arg1){
  zetasql::ASTDeleteStatement *node = (zetasql::ASTDeleteStatement *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTDeleteStatement_offset)(void * arg0,void ** arg1){
  zetasql::ASTDeleteStatement *node = (zetasql::ASTDeleteStatement *)arg0;
  *arg1 = (void *)node->offset();
}

void GO_EXPORT(ASTDeleteStatement_where)(void * arg0,void ** arg1){
  zetasql::ASTDeleteStatement *node = (zetasql::ASTDeleteStatement *)arg0;
  *arg1 = (void *)node->where();
}

void GO_EXPORT(ASTDeleteStatement_assert_rows_modified)(void * arg0,void ** arg1){
  zetasql::ASTDeleteStatement *node = (zetasql::ASTDeleteStatement *)arg0;
  *arg1 = (void *)node->assert_rows_modified();
}

void GO_EXPORT(ASTDeleteStatement_returning)(void * arg0,void ** arg1){
  zetasql::ASTDeleteStatement *node = (zetasql::ASTDeleteStatement *)arg0;
  *arg1 = (void *)node->returning();
}

void GO_EXPORT(ASTPrimaryKeyColumnAttribute_set_enforced)(void * arg0,int arg1){
  zetasql::ASTPrimaryKeyColumnAttribute *node = (zetasql::ASTPrimaryKeyColumnAttribute *)arg0;
  node->set_enforced(arg1);
}

void GO_EXPORT(ASTPrimaryKeyColumnAttribute_enforced)(void * arg0,char* arg1){
  zetasql::ASTPrimaryKeyColumnAttribute *node = (zetasql::ASTPrimaryKeyColumnAttribute *)arg0;
  *arg1 = node->enforced();
}

void GO_EXPORT(ASTForeignKeyColumnAttribute_constraint_name)(void * arg0,void ** arg1){
  zetasql::ASTForeignKeyColumnAttribute *node = (zetasql::ASTForeignKeyColumnAttribute *)arg0;
  *arg1 = (void *)node->constraint_name();
}

void GO_EXPORT(ASTForeignKeyColumnAttribute_reference)(void * arg0,void ** arg1){
  zetasql::ASTForeignKeyColumnAttribute *node = (zetasql::ASTForeignKeyColumnAttribute *)arg0;
  *arg1 = (void *)node->reference();
}

void GO_EXPORT(ASTColumnAttributeList_values_num)(void * arg0,int* arg1){
  zetasql::ASTColumnAttributeList *node = (zetasql::ASTColumnAttributeList *)arg0;
  *arg1 = node->values().length();
}

void GO_EXPORT(ASTColumnAttributeList_value)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTColumnAttributeList *node = (zetasql::ASTColumnAttributeList *)arg0;
  *arg2 = (void *)node->values(arg1);
}

void GO_EXPORT(ASTStructColumnField_name)(void * arg0,void ** arg1){
  zetasql::ASTStructColumnField *node = (zetasql::ASTStructColumnField *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTStructColumnField_schema)(void * arg0,void ** arg1){
  zetasql::ASTStructColumnField *node = (zetasql::ASTStructColumnField *)arg0;
  *arg1 = (void *)node->schema();
}

void GO_EXPORT(ASTGeneratedColumnInfo_set_stored_mode)(void * arg0,int arg1){
  zetasql::ASTGeneratedColumnInfo *node = (zetasql::ASTGeneratedColumnInfo *)arg0;
  node->set_stored_mode((zetasql::ASTGeneratedColumnInfo::StoredMode)arg1);
}

void GO_EXPORT(ASTGeneratedColumnInfo_stored_mode)(void * arg0,int* arg1){
  zetasql::ASTGeneratedColumnInfo *node = (zetasql::ASTGeneratedColumnInfo *)arg0;
  *arg1 = node->stored_mode();
}

void GO_EXPORT(ASTGeneratedColumnInfo_expression)(void * arg0,void ** arg1){
  zetasql::ASTGeneratedColumnInfo *node = (zetasql::ASTGeneratedColumnInfo *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTGeneratedColumnInfo_GetSqlForStoredMode)(void * arg0,void ** arg1){
  zetasql::ASTGeneratedColumnInfo *node = (zetasql::ASTGeneratedColumnInfo *)arg0;
  *arg1 = (void *)((new std::string(node->GetSqlForStoredMode()))->c_str());
}

void GO_EXPORT(ASTColumnDefinition_name)(void * arg0,void ** arg1){
  zetasql::ASTColumnDefinition *node = (zetasql::ASTColumnDefinition *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTColumnDefinition_schema)(void * arg0,void ** arg1){
  zetasql::ASTColumnDefinition *node = (zetasql::ASTColumnDefinition *)arg0;
  *arg1 = (void *)node->schema();
}

void GO_EXPORT(ASTTableElementList_elements_num)(void * arg0,int* arg1){
  zetasql::ASTTableElementList *node = (zetasql::ASTTableElementList *)arg0;
  *arg1 = node->elements().length();
}

void GO_EXPORT(ASTTableElementList_element)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTTableElementList *node = (zetasql::ASTTableElementList *)arg0;
  *arg2 = (void *)node->elements(arg1);
}

void GO_EXPORT(ASTColumnList_identifiers_num)(void * arg0,int* arg1){
  zetasql::ASTColumnList *node = (zetasql::ASTColumnList *)arg0;
  *arg1 = node->identifiers().length();
}

void GO_EXPORT(ASTColumnList_identifier)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTColumnList *node = (zetasql::ASTColumnList *)arg0;
  *arg2 = (void *)node->identifiers(arg1);
}

void GO_EXPORT(ASTColumnPosition_set_type)(void * arg0,int arg1){
  zetasql::ASTColumnPosition *node = (zetasql::ASTColumnPosition *)arg0;
  node->set_type((zetasql::ASTColumnPosition::RelativePositionType)arg1);
}

void GO_EXPORT(ASTColumnPosition_type)(void * arg0,int * arg1){
  zetasql::ASTColumnPosition *node = (zetasql::ASTColumnPosition *)arg0;
  *arg1 = node->type();
}

void GO_EXPORT(ASTColumnPosition_identifier)(void * arg0,void ** arg1){
  zetasql::ASTColumnPosition *node = (zetasql::ASTColumnPosition *)arg0;
  *arg1 = (void *)node->identifier();
}

void GO_EXPORT(ASTInsertValuesRow_values_num)(void * arg0,int* arg1){
  zetasql::ASTInsertValuesRow *node = (zetasql::ASTInsertValuesRow *)arg0;
  *arg1 = node->values().length();
}

void GO_EXPORT(ASTInsertValuesRow_value)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTInsertValuesRow *node = (zetasql::ASTInsertValuesRow *)arg0;
  *arg2 = (void *)node->values(arg1);
}

void GO_EXPORT(ASTInsertValuesRowList_rows_num)(void * arg0,int* arg1){
  zetasql::ASTInsertValuesRowList *node = (zetasql::ASTInsertValuesRowList *)arg0;
  *arg1 = node->rows().length();
}

void GO_EXPORT(ASTInsertValuesRowList_row)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTInsertValuesRowList *node = (zetasql::ASTInsertValuesRowList *)arg0;
  *arg2 = (void *)node->rows(arg1);
}

void GO_EXPORT(ASTInsertStatement_set_parse_progress)(void * arg0,int arg1){
  zetasql::ASTInsertStatement *node = (zetasql::ASTInsertStatement *)arg0;
  node->set_parse_progress((zetasql::ASTInsertStatement::ParseProgress)arg1);
}

void GO_EXPORT(ASTInsertStatement_parse_progress)(void * arg0,int* arg1){
  zetasql::ASTInsertStatement *node = (zetasql::ASTInsertStatement *)arg0;
  *arg1 = node->parse_progress();
}

void GO_EXPORT(ASTInsertStatement_set_insert_mode)(void * arg0,int arg1){
  zetasql::ASTInsertStatement *node = (zetasql::ASTInsertStatement *)arg0;
  node->set_insert_mode((zetasql::ASTInsertStatement::InsertMode)arg1);
}

void GO_EXPORT(ASTInsertStatement_insert_mode)(void * arg0,int* arg1){
  zetasql::ASTInsertStatement *node = (zetasql::ASTInsertStatement *)arg0;
  *arg1 = node->insert_mode();
}

void GO_EXPORT(ASTInsertStatement_target_path)(void * arg0,void ** arg1){
  zetasql::ASTInsertStatement *node = (zetasql::ASTInsertStatement *)arg0;
  *arg1 = (void *)node->target_path();
}

void GO_EXPORT(ASTInsertStatement_column_list)(void * arg0,void ** arg1){
  zetasql::ASTInsertStatement *node = (zetasql::ASTInsertStatement *)arg0;
  *arg1 = (void *)node->column_list();
}

void GO_EXPORT(ASTInsertStatement_rows)(void * arg0,void ** arg1){
  zetasql::ASTInsertStatement *node = (zetasql::ASTInsertStatement *)arg0;
  *arg1 = (void *)node->rows();
}

void GO_EXPORT(ASTInsertStatement_query)(void * arg0,void ** arg1){
  zetasql::ASTInsertStatement *node = (zetasql::ASTInsertStatement *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ASTInsertStatement_assert_rows_modified)(void * arg0,void ** arg1){
  zetasql::ASTInsertStatement *node = (zetasql::ASTInsertStatement *)arg0;
  *arg1 = (void *)node->assert_rows_modified();
}

void GO_EXPORT(ASTInsertStatement_returning)(void * arg0,void ** arg1){
  zetasql::ASTInsertStatement *node = (zetasql::ASTInsertStatement *)arg0;
  *arg1 = (void *)node->returning();
}

void GO_EXPORT(ASTInsertStatement_GetSQLForInsertMode)(void * arg0,void ** arg1){
  zetasql::ASTInsertStatement *node = (zetasql::ASTInsertStatement *)arg0;
  *arg1 = (void *)((new std::string(node->GetSQLForInsertMode()))->c_str());
}

void GO_EXPORT(ASTUpdateSetValue_path)(void * arg0,void ** arg1){
  zetasql::ASTUpdateSetValue *node = (zetasql::ASTUpdateSetValue *)arg0;
  *arg1 = (void *)node->path();
}

void GO_EXPORT(ASTUpdateSetValue_value)(void * arg0,void ** arg1){
  zetasql::ASTUpdateSetValue *node = (zetasql::ASTUpdateSetValue *)arg0;
  *arg1 = (void *)node->value();
}

void GO_EXPORT(ASTUpdateItem_set_value)(void * arg0,void ** arg1){
  zetasql::ASTUpdateItem *node = (zetasql::ASTUpdateItem *)arg0;
  *arg1 = (void *)node->set_value();
}

void GO_EXPORT(ASTUpdateItem_insert_statement)(void * arg0,void ** arg1){
  zetasql::ASTUpdateItem *node = (zetasql::ASTUpdateItem *)arg0;
  *arg1 = (void *)node->insert_statement();
}

void GO_EXPORT(ASTUpdateItem_delete_statement)(void * arg0,void ** arg1){
  zetasql::ASTUpdateItem *node = (zetasql::ASTUpdateItem *)arg0;
  *arg1 = (void *)node->delete_statement();
}

void GO_EXPORT(ASTUpdateItem_update_statement)(void * arg0,void ** arg1){
  zetasql::ASTUpdateItem *node = (zetasql::ASTUpdateItem *)arg0;
  *arg1 = (void *)node->update_statement();
}

void GO_EXPORT(ASTUpdateItemList_update_items_num)(void * arg0,int* arg1){
  zetasql::ASTUpdateItemList *node = (zetasql::ASTUpdateItemList *)arg0;
  *arg1 = node->update_items().length();
}

void GO_EXPORT(ASTUpdateItemList_update_item)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTUpdateItemList *node = (zetasql::ASTUpdateItemList *)arg0;
  *arg2 = (void *)node->update_items(arg1);
}

void GO_EXPORT(ASTUpdateStatement_target_path)(void * arg0,void ** arg1){
  zetasql::ASTUpdateStatement *node = (zetasql::ASTUpdateStatement *)arg0;
  *arg1 = (void *)node->target_path();
}

void GO_EXPORT(ASTUpdateStatement_alias)(void * arg0,void ** arg1){
  zetasql::ASTUpdateStatement *node = (zetasql::ASTUpdateStatement *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTUpdateStatement_offset)(void * arg0,void ** arg1){
  zetasql::ASTUpdateStatement *node = (zetasql::ASTUpdateStatement *)arg0;
  *arg1 = (void *)node->offset();
}

void GO_EXPORT(ASTUpdateStatement_update_item_list)(void * arg0,void ** arg1){
  zetasql::ASTUpdateStatement *node = (zetasql::ASTUpdateStatement *)arg0;
  *arg1 = (void *)node->update_item_list();
}

void GO_EXPORT(ASTUpdateStatement_from_clause)(void * arg0,void ** arg1){
  zetasql::ASTUpdateStatement *node = (zetasql::ASTUpdateStatement *)arg0;
  *arg1 = (void *)node->from_clause();
}

void GO_EXPORT(ASTUpdateStatement_where)(void * arg0,void ** arg1){
  zetasql::ASTUpdateStatement *node = (zetasql::ASTUpdateStatement *)arg0;
  *arg1 = (void *)node->where();
}

void GO_EXPORT(ASTUpdateStatement_assert_rows_modified)(void * arg0,void ** arg1){
  zetasql::ASTUpdateStatement *node = (zetasql::ASTUpdateStatement *)arg0;
  *arg1 = (void *)node->assert_rows_modified();
}

void GO_EXPORT(ASTUpdateStatement_returning)(void * arg0,void ** arg1){
  zetasql::ASTUpdateStatement *node = (zetasql::ASTUpdateStatement *)arg0;
  *arg1 = (void *)node->returning();
}

void GO_EXPORT(ASTTruncateStatement_target_path)(void * arg0,void ** arg1){
  zetasql::ASTTruncateStatement *node = (zetasql::ASTTruncateStatement *)arg0;
  *arg1 = (void *)node->target_path();
}

void GO_EXPORT(ASTTruncateStatement_where)(void * arg0,void ** arg1){
  zetasql::ASTTruncateStatement *node = (zetasql::ASTTruncateStatement *)arg0;
  *arg1 = (void *)node->where();
}

void GO_EXPORT(ASTMergeAction_set_action_type)(void * arg0,int arg1){
  zetasql::ASTMergeAction *node = (zetasql::ASTMergeAction *)arg0;
  node->set_action_type((zetasql::ASTMergeAction::ActionType)arg1);
}

void GO_EXPORT(ASTMergeAction_action_type)(void * arg0,int* arg1){
  zetasql::ASTMergeAction *node = (zetasql::ASTMergeAction *)arg0;
  *arg1 = node->action_type();
}

void GO_EXPORT(ASTMergeAction_insert_column_list)(void * arg0,void ** arg1){
  zetasql::ASTMergeAction *node = (zetasql::ASTMergeAction *)arg0;
  *arg1 = (void *)node->insert_column_list();
}

void GO_EXPORT(ASTMergeAction_insert_row)(void * arg0,void ** arg1){
  zetasql::ASTMergeAction *node = (zetasql::ASTMergeAction *)arg0;
  *arg1 = (void *)node->insert_row();
}

void GO_EXPORT(ASTMergeAction_update_item_list)(void * arg0,void ** arg1){
  zetasql::ASTMergeAction *node = (zetasql::ASTMergeAction *)arg0;
  *arg1 = (void *)node->update_item_list();
}

void GO_EXPORT(ASTMergeWhenClause_set_match_type)(void * arg0,int arg1){
  zetasql::ASTMergeWhenClause *node = (zetasql::ASTMergeWhenClause *)arg0;
  node->set_match_type((zetasql::ASTMergeWhenClause::MatchType)arg1);
}

void GO_EXPORT(ASTMergeWhenClause_match_type)(void * arg0,int* arg1){
  zetasql::ASTMergeWhenClause *node = (zetasql::ASTMergeWhenClause *)arg0;
  *arg1 = node->match_type();
}

void GO_EXPORT(ASTMergeWhenClause_search_condition)(void * arg0,void ** arg1){
  zetasql::ASTMergeWhenClause *node = (zetasql::ASTMergeWhenClause *)arg0;
  *arg1 = (void *)node->search_condition();
}

void GO_EXPORT(ASTMergeWhenClause_action)(void * arg0,void ** arg1){
  zetasql::ASTMergeWhenClause *node = (zetasql::ASTMergeWhenClause *)arg0;
  *arg1 = (void *)node->action();
}

void GO_EXPORT(ASTMergeWhenClause_GetSQLForMatchType)(void * arg0,void ** arg1){
  zetasql::ASTMergeWhenClause *node = (zetasql::ASTMergeWhenClause *)arg0;
  *arg1 = (void *)((new std::string(node->GetSQLForMatchType()))->c_str());
}

void GO_EXPORT(ASTMergeWhenClauseList_clause_list_num)(void * arg0,int* arg1){
  zetasql::ASTMergeWhenClauseList *node = (zetasql::ASTMergeWhenClauseList *)arg0;
  *arg1 = node->clause_list().length();
}

void GO_EXPORT(ASTMergeWhenClauseList_clause_list)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTMergeWhenClauseList *node = (zetasql::ASTMergeWhenClauseList *)arg0;
  *arg2 = (void *)node->clause_list(arg1);
}

void GO_EXPORT(ASTMergeStatement_target_path)(void * arg0,void ** arg1){
  zetasql::ASTMergeStatement *node = (zetasql::ASTMergeStatement *)arg0;
  *arg1 = (void *)node->target_path();
}

void GO_EXPORT(ASTMergeStatement_alias)(void * arg0,void ** arg1){
  zetasql::ASTMergeStatement *node = (zetasql::ASTMergeStatement *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTMergeStatement_table_expression)(void * arg0,void ** arg1){
  zetasql::ASTMergeStatement *node = (zetasql::ASTMergeStatement *)arg0;
  *arg1 = (void *)node->table_expression();
}

void GO_EXPORT(ASTMergeStatement_merge_condition)(void * arg0,void ** arg1){
  zetasql::ASTMergeStatement *node = (zetasql::ASTMergeStatement *)arg0;
  *arg1 = (void *)node->merge_condition();
}

void GO_EXPORT(ASTMergeStatement_when_clauses)(void * arg0,void ** arg1){
  zetasql::ASTMergeStatement *node = (zetasql::ASTMergeStatement *)arg0;
  *arg1 = (void *)node->when_clauses();
}

void GO_EXPORT(ASTPrivilege_privilege_action)(void * arg0,void ** arg1){
  zetasql::ASTPrivilege *node = (zetasql::ASTPrivilege *)arg0;
  *arg1 = (void *)node->privilege_action();
}

void GO_EXPORT(ASTPrivilege_paths)(void * arg0,void ** arg1){
  zetasql::ASTPrivilege *node = (zetasql::ASTPrivilege *)arg0;
  *arg1 = (void *)node->paths();
}

void GO_EXPORT(ASTPrivileges_privileges_num)(void * arg0,int* arg1){
  zetasql::ASTPrivileges *node = (zetasql::ASTPrivileges *)arg0;
  *arg1 = node->privileges().length();
}

void GO_EXPORT(ASTPrivileges_privilege)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTPrivileges *node = (zetasql::ASTPrivileges *)arg0;
  *arg2 = (void *)node->privileges(arg1);
}

void GO_EXPORT(ASTPrivileges_is_all_privileges)(void * arg0,char* arg1){
  zetasql::ASTPrivileges *node = (zetasql::ASTPrivileges *)arg0;
  *arg1 = node->is_all_privileges();
}

void GO_EXPORT(ASTGranteeList_grantee_list_num)(void * arg0,int* arg1){
  zetasql::ASTGranteeList *node = (zetasql::ASTGranteeList *)arg0;
  *arg1 = node->grantee_list().length();
}

void GO_EXPORT(ASTGranteeList_grantee_list)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTGranteeList *node = (zetasql::ASTGranteeList *)arg0;
  *arg2 = (void *)node->grantee_list(arg1);
}

void GO_EXPORT(ASTGrantStatement_privileges)(void * arg0,void ** arg1){
  zetasql::ASTGrantStatement *node = (zetasql::ASTGrantStatement *)arg0;
  *arg1 = (void *)node->privileges();
}

void GO_EXPORT(ASTGrantStatement_target_type)(void * arg0,void ** arg1){
  zetasql::ASTGrantStatement *node = (zetasql::ASTGrantStatement *)arg0;
  *arg1 = (void *)node->target_type();
}

void GO_EXPORT(ASTGrantStatement_target_path)(void * arg0,void ** arg1){
  zetasql::ASTGrantStatement *node = (zetasql::ASTGrantStatement *)arg0;
  *arg1 = (void *)node->target_path();
}

void GO_EXPORT(ASTGrantStatement_grantee_list)(void * arg0,void ** arg1){
  zetasql::ASTGrantStatement *node = (zetasql::ASTGrantStatement *)arg0;
  *arg1 = (void *)node->grantee_list();
}

void GO_EXPORT(ASTRevokeStatement_privileges)(void * arg0,void ** arg1){
  zetasql::ASTRevokeStatement *node = (zetasql::ASTRevokeStatement *)arg0;
  *arg1 = (void *)node->privileges();
}

void GO_EXPORT(ASTRevokeStatement_target_type)(void * arg0,void ** arg1){
  zetasql::ASTRevokeStatement *node = (zetasql::ASTRevokeStatement *)arg0;
  *arg1 = (void *)node->target_type();
}

void GO_EXPORT(ASTRevokeStatement_target_path)(void * arg0,void ** arg1){
  zetasql::ASTRevokeStatement *node = (zetasql::ASTRevokeStatement *)arg0;
  *arg1 = (void *)node->target_path();
}

void GO_EXPORT(ASTRevokeStatement_grantee_list)(void * arg0,void ** arg1){
  zetasql::ASTRevokeStatement *node = (zetasql::ASTRevokeStatement *)arg0;
  *arg1 = (void *)node->grantee_list();
}

void GO_EXPORT(ASTRepeatableClause_argument)(void * arg0,void ** arg1){
  zetasql::ASTRepeatableClause *node = (zetasql::ASTRepeatableClause *)arg0;
  *arg1 = (void *)node->argument();
}

void GO_EXPORT(ASTFilterFieldsArg_set_filter_type)(void * arg0,int arg1){
  zetasql::ASTFilterFieldsArg *node = (zetasql::ASTFilterFieldsArg *)arg0;
  node->set_filter_type((zetasql::ASTFilterFieldsArg::FilterType)arg1);
}

void GO_EXPORT(ASTFilterFieldsArg_filter_type)(void * arg0,int* arg1){
  zetasql::ASTFilterFieldsArg *node = (zetasql::ASTFilterFieldsArg *)arg0;
  *arg1 = node->filter_type();
}

void GO_EXPORT(ASTFilterFieldsArg_path_expression)(void * arg0,void ** arg1){
  zetasql::ASTFilterFieldsArg *node = (zetasql::ASTFilterFieldsArg *)arg0;
  *arg1 = (void *)node->path_expression();
}

void GO_EXPORT(ASTFilterFieldsArg_GetSQLForOperator)(void * arg0,void ** arg1){
  zetasql::ASTFilterFieldsArg *node = (zetasql::ASTFilterFieldsArg *)arg0;
  *arg1 = (void *)((new std::string(node->GetSQLForOperator()))->c_str());
}

void GO_EXPORT(ASTReplaceFieldsArg_expression)(void * arg0,void ** arg1){
  zetasql::ASTReplaceFieldsArg *node = (zetasql::ASTReplaceFieldsArg *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTReplaceFieldsArg_path_expression)(void * arg0,void ** arg1){
  zetasql::ASTReplaceFieldsArg *node = (zetasql::ASTReplaceFieldsArg *)arg0;
  *arg1 = (void *)node->path_expression();
}

void GO_EXPORT(ASTReplaceFieldsExpression_expr)(void * arg0,void ** arg1){
  zetasql::ASTReplaceFieldsExpression *node = (zetasql::ASTReplaceFieldsExpression *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ASTReplaceFieldsExpression_arguments_num)(void * arg0,int* arg1){
  zetasql::ASTReplaceFieldsExpression *node = (zetasql::ASTReplaceFieldsExpression *)arg0;
  *arg1 = node->arguments().length();
}

void GO_EXPORT(ASTReplaceFieldsExpression_argument)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTReplaceFieldsExpression *node = (zetasql::ASTReplaceFieldsExpression *)arg0;
  *arg2 = (void *)node->arguments(arg1);
}

void GO_EXPORT(ASTSampleSize_set_unit)(void * arg0,int arg1){
  zetasql::ASTSampleSize *node = (zetasql::ASTSampleSize *)arg0;
  node->set_unit((zetasql::ASTSampleSize::Unit)arg1);
}

void GO_EXPORT(ASTSampleSize_unit)(void * arg0,int* arg1){
  zetasql::ASTSampleSize *node = (zetasql::ASTSampleSize *)arg0;
  *arg1 = node->unit();
}

void GO_EXPORT(ASTSampleSize_size)(void * arg0,void ** arg1){
  zetasql::ASTSampleSize *node = (zetasql::ASTSampleSize *)arg0;
  *arg1 = (void *)node->size();
}

void GO_EXPORT(ASTSampleSize_partition_by)(void * arg0,void ** arg1){
  zetasql::ASTSampleSize *node = (zetasql::ASTSampleSize *)arg0;
  *arg1 = (void *)node->partition_by();
}

void GO_EXPORT(ASTSampleSize_GetSQLForUnit)(void * arg0,void ** arg1){
  zetasql::ASTSampleSize *node = (zetasql::ASTSampleSize *)arg0;
  *arg1 = (void *)((new std::string(node->GetSQLForUnit()))->c_str());
}

void GO_EXPORT(ASTWithWeight_alias)(void * arg0,void ** arg1){
  zetasql::ASTWithWeight *node = (zetasql::ASTWithWeight *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTSampleSuffix_weight)(void * arg0,void ** arg1){
  zetasql::ASTSampleSuffix *node = (zetasql::ASTSampleSuffix *)arg0;
  *arg1 = (void *)node->weight();
}

void GO_EXPORT(ASTSampleSuffix_repeat)(void * arg0,void ** arg1){
  zetasql::ASTSampleSuffix *node = (zetasql::ASTSampleSuffix *)arg0;
  *arg1 = (void *)node->repeat();
}

void GO_EXPORT(ASTSampleClause_sample_method)(void * arg0,void ** arg1){
  zetasql::ASTSampleClause *node = (zetasql::ASTSampleClause *)arg0;
  *arg1 = (void *)node->sample_method();
}

void GO_EXPORT(ASTSampleClause_sample_size)(void * arg0,void ** arg1){
  zetasql::ASTSampleClause *node = (zetasql::ASTSampleClause *)arg0;
  *arg1 = (void *)node->sample_size();
}

void GO_EXPORT(ASTSampleClause_sample_suffix)(void * arg0,void ** arg1){
  zetasql::ASTSampleClause *node = (zetasql::ASTSampleClause *)arg0;
  *arg1 = (void *)node->sample_suffix();
}

void GO_EXPORT(ASTAlterAction_GetSQLForAlterAction)(void * arg0,void ** arg1){
  zetasql::ASTAlterAction *node = (zetasql::ASTAlterAction *)arg0;
  *arg1 = (void *)((new std::string(node->GetSQLForAlterAction()))->c_str());
}

void GO_EXPORT(ASTSetOptionsAction_options_list)(void * arg0,void ** arg1){
  zetasql::ASTSetOptionsAction *node = (zetasql::ASTSetOptionsAction *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTSetAsAction_json_body)(void * arg0,void ** arg1){
  zetasql::ASTSetAsAction *node = (zetasql::ASTSetAsAction *)arg0;
  *arg1 = (void *)node->json_body();
}

void GO_EXPORT(ASTSetAsAction_text_body)(void * arg0,void ** arg1){
  zetasql::ASTSetAsAction *node = (zetasql::ASTSetAsAction *)arg0;
  *arg1 = (void *)node->text_body();
}

void GO_EXPORT(ASTAddConstraintAction_set_is_if_not_exists)(void * arg0,int arg1){
  zetasql::ASTAddConstraintAction *node = (zetasql::ASTAddConstraintAction *)arg0;
  node->set_is_if_not_exists(arg1);
}

void GO_EXPORT(ASTAddConstraintAction_is_if_not_exists)(void * arg0,char* arg1){
  zetasql::ASTAddConstraintAction *node = (zetasql::ASTAddConstraintAction *)arg0;
  *arg1 = node->is_if_not_exists();
}

void GO_EXPORT(ASTAddConstraintAction_constraint)(void * arg0,void ** arg1){
  zetasql::ASTAddConstraintAction *node = (zetasql::ASTAddConstraintAction *)arg0;
  *arg1 = (void *)node->constraint();
}

void GO_EXPORT(ASTDropPrimaryKeyAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTDropPrimaryKeyAction *node = (zetasql::ASTDropPrimaryKeyAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTDropPrimaryKeyAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTDropPrimaryKeyAction *node = (zetasql::ASTDropPrimaryKeyAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTDropConstraintAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTDropConstraintAction *node = (zetasql::ASTDropConstraintAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTDropConstraintAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTDropConstraintAction *node = (zetasql::ASTDropConstraintAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTDropConstraintAction_constraint_name)(void * arg0,void ** arg1){
  zetasql::ASTDropConstraintAction *node = (zetasql::ASTDropConstraintAction *)arg0;
  *arg1 = (void *)node->constraint_name();
}

void GO_EXPORT(ASTAlterConstraintEnforcementAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTAlterConstraintEnforcementAction *node = (zetasql::ASTAlterConstraintEnforcementAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTAlterConstraintEnforcementAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTAlterConstraintEnforcementAction *node = (zetasql::ASTAlterConstraintEnforcementAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTAlterConstraintEnforcementAction_set_is_enforced)(void * arg0,int arg1){
  zetasql::ASTAlterConstraintEnforcementAction *node = (zetasql::ASTAlterConstraintEnforcementAction *)arg0;
  node->set_is_enforced(arg1);
}

void GO_EXPORT(ASTAlterConstraintEnforcementAction_is_enforced)(void * arg0,char* arg1){
  zetasql::ASTAlterConstraintEnforcementAction *node = (zetasql::ASTAlterConstraintEnforcementAction *)arg0;
  *arg1 = node->is_enforced();
}

void GO_EXPORT(ASTAlterConstraintEnforcementAction_constraint_name)(void * arg0,void ** arg1){
  zetasql::ASTAlterConstraintEnforcementAction *node = (zetasql::ASTAlterConstraintEnforcementAction *)arg0;
  *arg1 = (void *)node->constraint_name();
}

void GO_EXPORT(ASTAlterConstraintSetOptionsAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTAlterConstraintSetOptionsAction *node = (zetasql::ASTAlterConstraintSetOptionsAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTAlterConstraintSetOptionsAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTAlterConstraintSetOptionsAction *node = (zetasql::ASTAlterConstraintSetOptionsAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTAlterConstraintSetOptionsAction_constraint_name)(void * arg0,void ** arg1){
  zetasql::ASTAlterConstraintSetOptionsAction *node = (zetasql::ASTAlterConstraintSetOptionsAction *)arg0;
  *arg1 = (void *)node->constraint_name();
}

void GO_EXPORT(ASTAlterConstraintSetOptionsAction_options_list)(void * arg0,void ** arg1){
  zetasql::ASTAlterConstraintSetOptionsAction *node = (zetasql::ASTAlterConstraintSetOptionsAction *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTAddColumnAction_set_is_if_not_exists)(void * arg0,int arg1){
  zetasql::ASTAddColumnAction *node = (zetasql::ASTAddColumnAction *)arg0;
  node->set_is_if_not_exists(arg1);
}

void GO_EXPORT(ASTAddColumnAction_is_if_not_exists)(void * arg0,char* arg1){
  zetasql::ASTAddColumnAction *node = (zetasql::ASTAddColumnAction *)arg0;
  *arg1 = node->is_if_not_exists();
}

void GO_EXPORT(ASTAddColumnAction_column_definition)(void * arg0,void ** arg1){
  zetasql::ASTAddColumnAction *node = (zetasql::ASTAddColumnAction *)arg0;
  *arg1 = (void *)node->column_definition();
}

void GO_EXPORT(ASTAddColumnAction_column_position)(void * arg0,void ** arg1){
  zetasql::ASTAddColumnAction *node = (zetasql::ASTAddColumnAction *)arg0;
  *arg1 = (void *)node->column_position();
}

void GO_EXPORT(ASTAddColumnAction_fill_expression)(void * arg0,void ** arg1){
  zetasql::ASTAddColumnAction *node = (zetasql::ASTAddColumnAction *)arg0;
  *arg1 = (void *)node->fill_expression();
}

void GO_EXPORT(ASTDropColumnAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTDropColumnAction *node = (zetasql::ASTDropColumnAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTDropColumnAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTDropColumnAction *node = (zetasql::ASTDropColumnAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTDropColumnAction_column_name)(void * arg0,void ** arg1){
  zetasql::ASTDropColumnAction *node = (zetasql::ASTDropColumnAction *)arg0;
  *arg1 = (void *)node->column_name();
}

void GO_EXPORT(ASTRenameColumnAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTRenameColumnAction *node = (zetasql::ASTRenameColumnAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTRenameColumnAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTRenameColumnAction *node = (zetasql::ASTRenameColumnAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTRenameColumnAction_column_name)(void * arg0,void ** arg1){
  zetasql::ASTRenameColumnAction *node = (zetasql::ASTRenameColumnAction *)arg0;
  *arg1 = (void *)node->column_name();
}

void GO_EXPORT(ASTRenameColumnAction_new_column_name)(void * arg0,void ** arg1){
  zetasql::ASTRenameColumnAction *node = (zetasql::ASTRenameColumnAction *)arg0;
  *arg1 = (void *)node->new_column_name();
}

void GO_EXPORT(ASTAlterColumnTypeAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTAlterColumnTypeAction *node = (zetasql::ASTAlterColumnTypeAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTAlterColumnTypeAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTAlterColumnTypeAction *node = (zetasql::ASTAlterColumnTypeAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTAlterColumnTypeAction_column_name)(void * arg0,void ** arg1){
  zetasql::ASTAlterColumnTypeAction *node = (zetasql::ASTAlterColumnTypeAction *)arg0;
  *arg1 = (void *)node->column_name();
}

void GO_EXPORT(ASTAlterColumnTypeAction_schema)(void * arg0,void ** arg1){
  zetasql::ASTAlterColumnTypeAction *node = (zetasql::ASTAlterColumnTypeAction *)arg0;
  *arg1 = (void *)node->schema();
}

void GO_EXPORT(ASTAlterColumnTypeAction_collate)(void * arg0,void ** arg1){
  zetasql::ASTAlterColumnTypeAction *node = (zetasql::ASTAlterColumnTypeAction *)arg0;
  *arg1 = (void *)node->collate();
}

void GO_EXPORT(ASTAlterColumnOptionsAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTAlterColumnOptionsAction *node = (zetasql::ASTAlterColumnOptionsAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTAlterColumnOptionsAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTAlterColumnOptionsAction *node = (zetasql::ASTAlterColumnOptionsAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTAlterColumnOptionsAction_column_name)(void * arg0,void ** arg1){
  zetasql::ASTAlterColumnOptionsAction *node = (zetasql::ASTAlterColumnOptionsAction *)arg0;
  *arg1 = (void *)node->column_name();
}

void GO_EXPORT(ASTAlterColumnOptionsAction_options_list)(void * arg0,void ** arg1){
  zetasql::ASTAlterColumnOptionsAction *node = (zetasql::ASTAlterColumnOptionsAction *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTAlterColumnSetDefaultAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTAlterColumnSetDefaultAction *node = (zetasql::ASTAlterColumnSetDefaultAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTAlterColumnSetDefaultAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTAlterColumnSetDefaultAction *node = (zetasql::ASTAlterColumnSetDefaultAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTAlterColumnSetDefaultAction_column_name)(void * arg0,void ** arg1){
  zetasql::ASTAlterColumnSetDefaultAction *node = (zetasql::ASTAlterColumnSetDefaultAction *)arg0;
  *arg1 = (void *)node->column_name();
}

void GO_EXPORT(ASTAlterColumnSetDefaultAction_default_expression)(void * arg0,void ** arg1){
  zetasql::ASTAlterColumnSetDefaultAction *node = (zetasql::ASTAlterColumnSetDefaultAction *)arg0;
  *arg1 = (void *)node->default_expression();
}

void GO_EXPORT(ASTAlterColumnDropDefaultAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTAlterColumnDropDefaultAction *node = (zetasql::ASTAlterColumnDropDefaultAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTAlterColumnDropDefaultAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTAlterColumnDropDefaultAction *node = (zetasql::ASTAlterColumnDropDefaultAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTAlterColumnDropDefaultAction_column_name)(void * arg0,void ** arg1){
  zetasql::ASTAlterColumnDropDefaultAction *node = (zetasql::ASTAlterColumnDropDefaultAction *)arg0;
  *arg1 = (void *)node->column_name();
}

void GO_EXPORT(ASTAlterColumnDropNotNullAction_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTAlterColumnDropNotNullAction *node = (zetasql::ASTAlterColumnDropNotNullAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTAlterColumnDropNotNullAction_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTAlterColumnDropNotNullAction *node = (zetasql::ASTAlterColumnDropNotNullAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTAlterColumnDropNotNullAction_column_name)(void * arg0,void ** arg1){
  zetasql::ASTAlterColumnDropNotNullAction *node = (zetasql::ASTAlterColumnDropNotNullAction *)arg0;
  *arg1 = (void *)node->column_name();
}

void GO_EXPORT(ASTGrantToClause_set_has_grant_keyword_and_parens)(void * arg0,int arg1){
  zetasql::ASTGrantToClause *node = (zetasql::ASTGrantToClause *)arg0;
  node->set_has_grant_keyword_and_parens(arg1);
}

void GO_EXPORT(ASTGrantToClause_has_grant_keyword_and_parens)(void * arg0,char* arg1){
  zetasql::ASTGrantToClause *node = (zetasql::ASTGrantToClause *)arg0;
  *arg1 = node->has_grant_keyword_and_parens();
}

void GO_EXPORT(ASTGrantToClause_grantee_list)(void * arg0,void ** arg1){
  zetasql::ASTGrantToClause *node = (zetasql::ASTGrantToClause *)arg0;
  *arg1 = (void *)node->grantee_list();
}

void GO_EXPORT(ASTRestrictToClause_restrictee_list)(void * arg0,void ** arg1){
  zetasql::ASTRestrictToClause *node = (zetasql::ASTRestrictToClause *)arg0;
  *arg1 = (void *)node->restrictee_list();
}

void GO_EXPORT(ASTAddToRestricteeListClause_set_is_if_not_exists)(void * arg0,int arg1){
  zetasql::ASTAddToRestricteeListClause *node = (zetasql::ASTAddToRestricteeListClause *)arg0;
  node->set_is_if_not_exists(arg1);
}

void GO_EXPORT(ASTAddToRestricteeListClause_is_if_not_exists)(void * arg0,char* arg1){
  zetasql::ASTAddToRestricteeListClause *node = (zetasql::ASTAddToRestricteeListClause *)arg0;
  *arg1 = node->is_if_not_exists();
}

void GO_EXPORT(ASTAddToRestricteeListClause_restrictee_list)(void * arg0,void ** arg1){
  zetasql::ASTAddToRestricteeListClause *node = (zetasql::ASTAddToRestricteeListClause *)arg0;
  *arg1 = (void *)node->restrictee_list();
}

void GO_EXPORT(ASTRemoveFromRestricteeListClause_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTRemoveFromRestricteeListClause *node = (zetasql::ASTRemoveFromRestricteeListClause *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTRemoveFromRestricteeListClause_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTRemoveFromRestricteeListClause *node = (zetasql::ASTRemoveFromRestricteeListClause *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTRemoveFromRestricteeListClause_restrictee_list)(void * arg0,void ** arg1){
  zetasql::ASTRemoveFromRestricteeListClause *node = (zetasql::ASTRemoveFromRestricteeListClause *)arg0;
  *arg1 = (void *)node->restrictee_list();
}

void GO_EXPORT(ASTFilterUsingClause_set_has_filter_keyword)(void * arg0,int arg1){
  zetasql::ASTFilterUsingClause *node = (zetasql::ASTFilterUsingClause *)arg0;
  node->set_has_filter_keyword(arg1);
}

void GO_EXPORT(ASTFilterUsingClause_has_filter_keyword)(void * arg0,char* arg1){
  zetasql::ASTFilterUsingClause *node = (zetasql::ASTFilterUsingClause *)arg0;
  *arg1 = node->has_filter_keyword();
}

void GO_EXPORT(ASTFilterUsingClause_predicate)(void * arg0,void ** arg1){
  zetasql::ASTFilterUsingClause *node = (zetasql::ASTFilterUsingClause *)arg0;
  *arg1 = (void *)node->predicate();
}

void GO_EXPORT(ASTRevokeFromClause_set_is_revoke_from_all)(void * arg0,int arg1){
  zetasql::ASTRevokeFromClause *node = (zetasql::ASTRevokeFromClause *)arg0;
  node->set_is_revoke_from_all(arg1);
}

void GO_EXPORT(ASTRevokeFromClause_is_revoke_from_all)(void * arg0,char* arg1){
  zetasql::ASTRevokeFromClause *node = (zetasql::ASTRevokeFromClause *)arg0;
  *arg1 = node->is_revoke_from_all();
}

void GO_EXPORT(ASTRevokeFromClause_revoke_from_list)(void * arg0,void ** arg1){
  zetasql::ASTRevokeFromClause *node = (zetasql::ASTRevokeFromClause *)arg0;
  *arg1 = (void *)node->revoke_from_list();
}

void GO_EXPORT(ASTRenameToClause_new_name)(void * arg0,void ** arg1){
  zetasql::ASTRenameToClause *node = (zetasql::ASTRenameToClause *)arg0;
  *arg1 = (void *)node->new_name();
}

void GO_EXPORT(ASTSetCollateClause_collate)(void * arg0,void ** arg1){
  zetasql::ASTSetCollateClause *node = (zetasql::ASTSetCollateClause *)arg0;
  *arg1 = (void *)node->collate();
}

void GO_EXPORT(ASTAlterActionList_actions_num)(void * arg0,int* arg1){
  zetasql::ASTAlterActionList *node = (zetasql::ASTAlterActionList *)arg0;
  *arg1 = node->actions().length();
}

void GO_EXPORT(ASTAlterActionList_action)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTAlterActionList *node = (zetasql::ASTAlterActionList *)arg0;
  *arg2 = (void *)node->actions(arg1);
}

void GO_EXPORT(ASTAlterAllRowAccessPoliciesStatement_table_name_path)(void * arg0,void ** arg1){
  zetasql::ASTAlterAllRowAccessPoliciesStatement *node = (zetasql::ASTAlterAllRowAccessPoliciesStatement *)arg0;
  *arg1 = (void *)node->table_name_path();
}

void GO_EXPORT(ASTAlterAllRowAccessPoliciesStatement_alter_action)(void * arg0,void ** arg1){
  zetasql::ASTAlterAllRowAccessPoliciesStatement *node = (zetasql::ASTAlterAllRowAccessPoliciesStatement *)arg0;
  *arg1 = (void *)node->alter_action();
}

void GO_EXPORT(ASTForeignKeyActions_set_udpate_action)(void * arg0,int arg1){
  zetasql::ASTForeignKeyActions *node = (zetasql::ASTForeignKeyActions *)arg0;
  node->set_update_action((zetasql::ASTForeignKeyActions::Action)arg1);
}

void GO_EXPORT(ASTForeignKeyActions_udpate_action)(void * arg0,int* arg1){
  zetasql::ASTForeignKeyActions *node = (zetasql::ASTForeignKeyActions *)arg0;
  *arg1 = node->update_action();
}

void GO_EXPORT(ASTForeignKeyActions_set_delete_action)(void * arg0,int arg1){
  zetasql::ASTForeignKeyActions *node = (zetasql::ASTForeignKeyActions *)arg0;
  node->set_delete_action((zetasql::ASTForeignKeyActions::Action)arg1);
}

void GO_EXPORT(ASTForeignKeyActions_delete_action)(void * arg0,int* arg1){
  zetasql::ASTForeignKeyActions *node = (zetasql::ASTForeignKeyActions *)arg0;
  *arg1 = node->delete_action();
}

void GO_EXPORT(ASTForeignKeyReference_set_match)(void * arg0,int arg1){
  zetasql::ASTForeignKeyReference *node = (zetasql::ASTForeignKeyReference *)arg0;
  node->set_match((zetasql::ASTForeignKeyReference::Match)arg1);
}

void GO_EXPORT(ASTForeignKeyReference_match)(void * arg0,int* arg1){
  zetasql::ASTForeignKeyReference *node = (zetasql::ASTForeignKeyReference *)arg0;
  *arg1 = node->match();
}

void GO_EXPORT(ASTForeignKeyReference_set_enforced)(void * arg0,int arg1){
  zetasql::ASTForeignKeyReference *node = (zetasql::ASTForeignKeyReference *)arg0;
  node->set_enforced(arg1);
}

void GO_EXPORT(ASTForeignKeyReference_enforced)(void * arg0,char* arg1){
  zetasql::ASTForeignKeyReference *node = (zetasql::ASTForeignKeyReference *)arg0;
  *arg1 = node->enforced();
}

void GO_EXPORT(ASTForeignKeyReference_table_name)(void * arg0,void ** arg1){
  zetasql::ASTForeignKeyReference *node = (zetasql::ASTForeignKeyReference *)arg0;
  *arg1 = (void *)node->table_name();
}

void GO_EXPORT(ASTForeignKeyReference_column_list)(void * arg0,void ** arg1){
  zetasql::ASTForeignKeyReference *node = (zetasql::ASTForeignKeyReference *)arg0;
  *arg1 = (void *)node->column_list();
}

void GO_EXPORT(ASTForeignKeyReference_actions)(void * arg0,void ** arg1){
  zetasql::ASTForeignKeyReference *node = (zetasql::ASTForeignKeyReference *)arg0;
  *arg1 = (void *)node->actions();
}

void GO_EXPORT(ASTScript_statement_list_node)(void * arg0,void ** arg1){
  zetasql::ASTScript *node = (zetasql::ASTScript *)arg0;
  *arg1 = (void *)node->statement_list_node();
}

void GO_EXPORT(ASTScript_statement_list_num)(void * arg0,int* arg1){
  zetasql::ASTScript *node = (zetasql::ASTScript *)arg0;
  *arg1 = node->statement_list().length();
}

void GO_EXPORT(ASTScript_statement_list)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTScript *node = (zetasql::ASTScript *)arg0;
  *arg2 = (void *)node->statement_list()[arg1];
}

void GO_EXPORT(ASTElseifClause_condition)(void * arg0,void ** arg1){
  zetasql::ASTElseifClause *node = (zetasql::ASTElseifClause *)arg0;
  *arg1 = (void *)node->condition();
}

void GO_EXPORT(ASTElseifClause_body)(void * arg0,void ** arg1){
  zetasql::ASTElseifClause *node = (zetasql::ASTElseifClause *)arg0;
  *arg1 = (void *)node->body();
}

void GO_EXPORT(ASTElseifClause_if_stmt)(void * arg0,void ** arg1){
  zetasql::ASTElseifClause *node = (zetasql::ASTElseifClause *)arg0;
  *arg1 = (void *)node->if_stmt();
}

void GO_EXPORT(ASTElseifClauseList_elseif_clauses_num)(void * arg0,int* arg1){
  zetasql::ASTElseifClauseList *node = (zetasql::ASTElseifClauseList *)arg0;
  *arg1 = node->elseif_clauses().length();
}

void GO_EXPORT(ASTElseifClauseList_elseif_clause)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTElseifClauseList *node = (zetasql::ASTElseifClauseList *)arg0;
  *arg2 = (void *)node->elseif_clauses(arg1);
}

void GO_EXPORT(ASTIfStatement_condition)(void * arg0,void ** arg1){
  zetasql::ASTIfStatement *node = (zetasql::ASTIfStatement *)arg0;
  *arg1 = (void *)node->condition();
}

void GO_EXPORT(ASTIfStatement_then_list)(void * arg0,void ** arg1){
  zetasql::ASTIfStatement *node = (zetasql::ASTIfStatement *)arg0;
  *arg1 = (void *)node->then_list();
}

void GO_EXPORT(ASTIfStatement_elseif_clauses)(void * arg0,void ** arg1){
  zetasql::ASTIfStatement *node = (zetasql::ASTIfStatement *)arg0;
  *arg1 = (void *)node->elseif_clauses();
}

void GO_EXPORT(ASTIfStatement_else_list)(void * arg0,void ** arg1){
  zetasql::ASTIfStatement *node = (zetasql::ASTIfStatement *)arg0;
  *arg1 = (void *)node->else_list();
}

void GO_EXPORT(ASTWhenThenClause_condition)(void * arg0,void ** arg1){
  zetasql::ASTWhenThenClause *node = (zetasql::ASTWhenThenClause *)arg0;
  *arg1 = (void *)node->condition();
}

void GO_EXPORT(ASTWhenThenClause_body)(void * arg0,void ** arg1){
  zetasql::ASTWhenThenClause *node = (zetasql::ASTWhenThenClause *)arg0;
  *arg1 = (void *)node->body();
}

void GO_EXPORT(ASTWhenThenClause_case_stmt)(void * arg0,void ** arg1){
  zetasql::ASTWhenThenClause *node = (zetasql::ASTWhenThenClause *)arg0;
  *arg1 = (void *)node->case_stmt();
}

void GO_EXPORT(ASTWhenThenClauseList_when_then_clauses_num)(void * arg0,int* arg1){
  zetasql::ASTWhenThenClauseList *node = (zetasql::ASTWhenThenClauseList *)arg0;
  *arg1 = node->when_then_clauses().length();
}

void GO_EXPORT(ASTWhenThenClauseList_when_then_clause)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTWhenThenClauseList *node = (zetasql::ASTWhenThenClauseList *)arg0;
  *arg2 = (void *)node->when_then_clauses(arg1);
}

void GO_EXPORT(ASTCaseStatement_expression)(void * arg0,void ** arg1){
  zetasql::ASTCaseStatement *node = (zetasql::ASTCaseStatement *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTCaseStatement_when_then_clauses)(void * arg0,void ** arg1){
  zetasql::ASTCaseStatement *node = (zetasql::ASTCaseStatement *)arg0;
  *arg1 = (void *)node->when_then_clauses();
}

void GO_EXPORT(ASTCaseStatement_else_list)(void * arg0,void ** arg1){
  zetasql::ASTCaseStatement *node = (zetasql::ASTCaseStatement *)arg0;
  *arg1 = (void *)node->else_list();
}

void GO_EXPORT(ASTHint_num_shards_hint)(void * arg0,void ** arg1){
  zetasql::ASTHint *node = (zetasql::ASTHint *)arg0;
  *arg1 = (void *)node->num_shards_hint();
}

void GO_EXPORT(ASTHint_hint_entries_num)(void * arg0,int* arg1){
  zetasql::ASTHint *node = (zetasql::ASTHint *)arg0;
  *arg1 = node->hint_entries().length();
}

void GO_EXPORT(ASTHint_hint_entry)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTHint *node = (zetasql::ASTHint *)arg0;
  *arg2 = (void *)node->hint_entries(arg1);
}

void GO_EXPORT(ASTHintEntry_qualifier)(void * arg0,void ** arg1){
  zetasql::ASTHintEntry *node = (zetasql::ASTHintEntry *)arg0;
  *arg1 = (void *)node->qualifier();
}

void GO_EXPORT(ASTHintEntry_name)(void * arg0,void ** arg1){
  zetasql::ASTHintEntry *node = (zetasql::ASTHintEntry *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTHintEntry_value)(void * arg0,void ** arg1){
  zetasql::ASTHintEntry *node = (zetasql::ASTHintEntry *)arg0;
  *arg1 = (void *)node->value();
}

void GO_EXPORT(ASTUnpivotInItemLabel_label)(void * arg0,void ** arg1){
  zetasql::ASTUnpivotInItemLabel *node = (zetasql::ASTUnpivotInItemLabel *)arg0;
  *arg1 = (void *)node->label();
}

void GO_EXPORT(ASTDescriptor_columns)(void * arg0,void ** arg1){
  zetasql::ASTDescriptor *node = (zetasql::ASTDescriptor *)arg0;
  *arg1 = (void *)node->columns();
}

void GO_EXPORT(ASTColumnSchema_type_parameters)(void * arg0,void ** arg1){
  zetasql::ASTColumnSchema *node = (zetasql::ASTColumnSchema *)arg0;
  *arg1 = (void *)node->type_parameters();
}

void GO_EXPORT(ASTColumnSchema_generated_column_info)(void * arg0,void ** arg1){
  zetasql::ASTColumnSchema *node = (zetasql::ASTColumnSchema *)arg0;
  *arg1 = (void *)node->generated_column_info();
}

void GO_EXPORT(ASTColumnSchema_default_expression)(void * arg0,void ** arg1){
  zetasql::ASTColumnSchema *node = (zetasql::ASTColumnSchema *)arg0;
  *arg1 = (void *)node->default_expression();
}

void GO_EXPORT(ASTColumnSchema_collate)(void * arg0,void ** arg1){
  zetasql::ASTColumnSchema *node = (zetasql::ASTColumnSchema *)arg0;
  *arg1 = (void *)node->collate();
}

void GO_EXPORT(ASTColumnSchema_attributes)(void * arg0,void ** arg1){
  zetasql::ASTColumnSchema *node = (zetasql::ASTColumnSchema *)arg0;
  *arg1 = (void *)node->attributes();
}

void GO_EXPORT(ASTColumnSchema_options_list)(void * arg0,void ** arg1){
  zetasql::ASTColumnSchema *node = (zetasql::ASTColumnSchema *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTColumnSchema_ContainsAttribute)(void * arg0,int arg1,char* arg2){
  zetasql::ASTColumnSchema *node = (zetasql::ASTColumnSchema *)arg0;
  *arg2 = node->ContainsAttribute((zetasql::ASTNodeKind)arg1);
}

void GO_EXPORT(ASTSimpleColumnSchema_type_name)(void * arg0,void ** arg1){
  zetasql::ASTSimpleColumnSchema *node = (zetasql::ASTSimpleColumnSchema *)arg0;
  *arg1 = (void *)node->type_name();
}

void GO_EXPORT(ASTArrayColumnSchema_element_schema)(void * arg0,void ** arg1){
  zetasql::ASTArrayColumnSchema *node = (zetasql::ASTArrayColumnSchema *)arg0;
  *arg1 = (void *)node->element_schema();
}

void GO_EXPORT(ASTTableConstraint_constraint_name)(void * arg0,void ** arg1){
  zetasql::ASTTableConstraint *node = (zetasql::ASTTableConstraint *)arg0;
  *arg1 = (void *)node->constraint_name();
}

void GO_EXPORT(ASTPrimaryKey_set_enforced)(void * arg0,int arg1){
  zetasql::ASTPrimaryKey *node = (zetasql::ASTPrimaryKey *)arg0;
  node->set_enforced(arg1);
}

void GO_EXPORT(ASTPrimaryKey_enforced)(void * arg0,char* arg1){
  zetasql::ASTPrimaryKey *node = (zetasql::ASTPrimaryKey *)arg0;
  *arg1 = node->enforced();
}

void GO_EXPORT(ASTPrimaryKey_column_list)(void * arg0,void ** arg1){
  zetasql::ASTPrimaryKey *node = (zetasql::ASTPrimaryKey *)arg0;
  *arg1 = (void *)node->column_list();
}

void GO_EXPORT(ASTPrimaryKey_options_list)(void * arg0,void ** arg1){
  zetasql::ASTPrimaryKey *node = (zetasql::ASTPrimaryKey *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTForeignKey_column_list)(void * arg0,void ** arg1){
  zetasql::ASTForeignKey *node = (zetasql::ASTForeignKey *)arg0;
  *arg1 = (void *)node->column_list();
}

void GO_EXPORT(ASTForeignKey_reference)(void * arg0,void ** arg1){
  zetasql::ASTForeignKey *node = (zetasql::ASTForeignKey *)arg0;
  *arg1 = (void *)node->reference();
}

void GO_EXPORT(ASTForeignKey_options_list)(void * arg0,void ** arg1){
  zetasql::ASTForeignKey *node = (zetasql::ASTForeignKey *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTCheckConstraint_set_is_enforced)(void * arg0,int arg1){
  zetasql::ASTCheckConstraint *node = (zetasql::ASTCheckConstraint *)arg0;
  node->set_is_enforced(arg1);
}

void GO_EXPORT(ASTCheckConstraint_is_enforced)(void * arg0,char* arg1){
  zetasql::ASTCheckConstraint *node = (zetasql::ASTCheckConstraint *)arg0;
  *arg1 = node->is_enforced();
}

void GO_EXPORT(ASTCheckConstraint_expression)(void * arg0,void ** arg1){
  zetasql::ASTCheckConstraint *node = (zetasql::ASTCheckConstraint *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTCheckConstraint_options_list)(void * arg0,void ** arg1){
  zetasql::ASTCheckConstraint *node = (zetasql::ASTCheckConstraint *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTDescriptorColumn_name)(void * arg0,void ** arg1){
  zetasql::ASTDescriptorColumn *node = (zetasql::ASTDescriptorColumn *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTDescriptorColumnList_descriptor_column_list_num)(void * arg0,int* arg1){
  zetasql::ASTDescriptorColumnList *node = (zetasql::ASTDescriptorColumnList *)arg0;
  *arg1 = node->descriptor_column_list().length();
}

void GO_EXPORT(ASTDescriptorColumnList_descriptor_column_list)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTDescriptorColumnList *node = (zetasql::ASTDescriptorColumnList *)arg0;
  *arg2 = (void *)node->descriptor_column_list(arg1);
}

void GO_EXPORT(ASTCreateEntityStatement_type)(void * arg0,void ** arg1){
  zetasql::ASTCreateEntityStatement *node = (zetasql::ASTCreateEntityStatement *)arg0;
  *arg1 = (void *)node->type();
}

void GO_EXPORT(ASTCreateEntityStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTCreateEntityStatement *node = (zetasql::ASTCreateEntityStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTCreateEntityStatement_options_list)(void * arg0,void ** arg1){
  zetasql::ASTCreateEntityStatement *node = (zetasql::ASTCreateEntityStatement *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTCreateEntityStatement_json_body)(void * arg0,void ** arg1){
  zetasql::ASTCreateEntityStatement *node = (zetasql::ASTCreateEntityStatement *)arg0;
  *arg1 = (void *)node->json_body();
}

void GO_EXPORT(ASTCreateEntityStatement_text_body)(void * arg0,void ** arg1){
  zetasql::ASTCreateEntityStatement *node = (zetasql::ASTCreateEntityStatement *)arg0;
  *arg1 = (void *)node->text_body();
}

void GO_EXPORT(ASTRaiseStatement_message)(void * arg0,void ** arg1){
  zetasql::ASTRaiseStatement *node = (zetasql::ASTRaiseStatement *)arg0;
  *arg1 = (void *)node->message();
}

void GO_EXPORT(ASTRaiseStatement_is_rethrow)(void * arg0,char* arg1){
  zetasql::ASTRaiseStatement *node = (zetasql::ASTRaiseStatement *)arg0;
  *arg1 = node->is_rethrow();
}

void GO_EXPORT(ASTExceptionHandler_statement_list)(void * arg0,void ** arg1){
  zetasql::ASTExceptionHandler *node = (zetasql::ASTExceptionHandler *)arg0;
  *arg1 = (void *)node->statement_list();
}

void GO_EXPORT(ASTExceptionHandlerList_exception_handler_list_num)(void * arg0,int* arg1){
  zetasql::ASTExceptionHandlerList *node = (zetasql::ASTExceptionHandlerList *)arg0;
  *arg1 = node->exception_handler_list().length();
}

void GO_EXPORT(ASTExceptionHandlerList_exception_handler_list)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTExceptionHandlerList *node = (zetasql::ASTExceptionHandlerList *)arg0;
  *arg2 = (void *)node->exception_handler_list(arg1);
}

void GO_EXPORT(ASTBeginEndBlock_label)(void * arg0,void ** arg1){
  zetasql::ASTBeginEndBlock *node = (zetasql::ASTBeginEndBlock *)arg0;
  *arg1 = (void *)node->label();
}

void GO_EXPORT(ASTBeginEndBlock_statement_list_node)(void * arg0,void ** arg1){
  zetasql::ASTBeginEndBlock *node = (zetasql::ASTBeginEndBlock *)arg0;
  *arg1 = (void *)node->statement_list_node();
}

void GO_EXPORT(ASTBeginEndBlock_handler_list)(void * arg0,void ** arg1){
  zetasql::ASTBeginEndBlock *node = (zetasql::ASTBeginEndBlock *)arg0;
  *arg1 = (void *)node->handler_list();
}

void GO_EXPORT(ASTBeginEndBlock_statement_list_num)(void * arg0,int* arg1){
  zetasql::ASTBeginEndBlock *node = (zetasql::ASTBeginEndBlock *)arg0;
  *arg1 = node->statement_list().length();
}

void GO_EXPORT(ASTBeginEndBlock_statement_list)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTBeginEndBlock *node = (zetasql::ASTBeginEndBlock *)arg0;
  *arg2 = (void *)node->statement_list()[arg1];
}

void GO_EXPORT(ASTBeginEndBlock_has_exception_handler)(void * arg0,char* arg1){
  zetasql::ASTBeginEndBlock *node = (zetasql::ASTBeginEndBlock *)arg0;
  *arg1 = node->has_exception_handler();
}

void GO_EXPORT(ASTIdentifierList_identifier_list_num)(void * arg0,int* arg1){
  zetasql::ASTIdentifierList *node = (zetasql::ASTIdentifierList *)arg0;
  *arg1 = node->identifier_list().length();
}

void GO_EXPORT(ASTIdentifierList_identifier_list)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTIdentifierList *node = (zetasql::ASTIdentifierList *)arg0;
  *arg2 = (void *)node->identifier_list(arg1);
}

void GO_EXPORT(ASTVariableDeclaration_variable_list)(void * arg0,void ** arg1){
  zetasql::ASTVariableDeclaration *node = (zetasql::ASTVariableDeclaration *)arg0;
  *arg1 = (void *)node->variable_list();
}

void GO_EXPORT(ASTVariableDeclaration_type)(void * arg0,void ** arg1){
  zetasql::ASTVariableDeclaration *node = (zetasql::ASTVariableDeclaration *)arg0;
  *arg1 = (void *)node->type();
}

void GO_EXPORT(ASTVariableDeclaration_default_value)(void * arg0,void ** arg1){
  zetasql::ASTVariableDeclaration *node = (zetasql::ASTVariableDeclaration *)arg0;
  *arg1 = (void *)node->default_value();
}

void GO_EXPORT(ASTUntilClause_condition)(void * arg0,void ** arg1){
  zetasql::ASTUntilClause *node = (zetasql::ASTUntilClause *)arg0;
  *arg1 = (void *)node->condition();
}

void GO_EXPORT(ASTUntilClause_repeat_stmt)(void * arg0,void ** arg1){
  zetasql::ASTUntilClause *node = (zetasql::ASTUntilClause *)arg0;
  *arg1 = (void *)node->repeat_stmt();
}

void GO_EXPORT(ASTBreakContinueStatement_label)(void * arg0,void ** arg1){
  zetasql::ASTBreakContinueStatement *node = (zetasql::ASTBreakContinueStatement *)arg0;
  *arg1 = (void *)node->label();
}

void GO_EXPORT(ASTBreakContinueStatement_set_keyword)(void * arg0,int arg1){
  zetasql::ASTBreakContinueStatement *node = (zetasql::ASTBreakContinueStatement *)arg0;
  node->set_keyword((zetasql::ASTBreakContinueStatement::BreakContinueKeyword)arg1);
}

void GO_EXPORT(ASTBreakContinueStatement_keyword)(void * arg0,int* arg1){
  zetasql::ASTBreakContinueStatement *node = (zetasql::ASTBreakContinueStatement *)arg0;
  *arg1 = node->keyword();
}

void GO_EXPORT(ASTBreakStatement_set_keyword)(void * arg0,int arg1){
  zetasql::ASTBreakStatement *node = (zetasql::ASTBreakStatement *)arg0;
  node->set_keyword((zetasql::ASTBreakContinueStatement::BreakContinueKeyword)arg1);
}

void GO_EXPORT(ASTBreakStatement_keyword)(void * arg0,int* arg1){
  zetasql::ASTBreakStatement *node = (zetasql::ASTBreakStatement *)arg0;
  *arg1 = node->keyword();
}

void GO_EXPORT(ASTContinueStatement_set_keyword)(void * arg0,int arg1){
  zetasql::ASTContinueStatement *node = (zetasql::ASTContinueStatement *)arg0;
  node->set_keyword((zetasql::ASTBreakContinueStatement::BreakContinueKeyword)arg1);
}

void GO_EXPORT(ASTContinueStatement_keyword)(void * arg0,int* arg1){
  zetasql::ASTContinueStatement *node = (zetasql::ASTContinueStatement *)arg0;
  *arg1 = node->keyword();
}

void GO_EXPORT(ASTDropPrivilegeRestrictionStatement_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTDropPrivilegeRestrictionStatement *node = (zetasql::ASTDropPrivilegeRestrictionStatement *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTDropPrivilegeRestrictionStatement_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTDropPrivilegeRestrictionStatement *node = (zetasql::ASTDropPrivilegeRestrictionStatement *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTDropPrivilegeRestrictionStatement_privileges)(void * arg0,void ** arg1){
  zetasql::ASTDropPrivilegeRestrictionStatement *node = (zetasql::ASTDropPrivilegeRestrictionStatement *)arg0;
  *arg1 = (void *)node->privileges();
}

void GO_EXPORT(ASTDropPrivilegeRestrictionStatement_object_type)(void * arg0,void ** arg1){
  zetasql::ASTDropPrivilegeRestrictionStatement *node = (zetasql::ASTDropPrivilegeRestrictionStatement *)arg0;
  *arg1 = (void *)node->object_type();
}

void GO_EXPORT(ASTDropPrivilegeRestrictionStatement_name_path)(void * arg0,void ** arg1){
  zetasql::ASTDropPrivilegeRestrictionStatement *node = (zetasql::ASTDropPrivilegeRestrictionStatement *)arg0;
  *arg1 = (void *)node->name_path();
}

void GO_EXPORT(ASTDropRowAccessPolicyStatement_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTDropRowAccessPolicyStatement *node = (zetasql::ASTDropRowAccessPolicyStatement *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTDropRowAccessPolicyStatement_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTDropRowAccessPolicyStatement *node = (zetasql::ASTDropRowAccessPolicyStatement *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTDropRowAccessPolicyStatement_table_name)(void * arg0,void ** arg1){
  zetasql::ASTDropRowAccessPolicyStatement *node = (zetasql::ASTDropRowAccessPolicyStatement *)arg0;
  *arg1 = (void *)node->table_name();
}

void GO_EXPORT(ASTDropRowAccessPolicyStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTDropRowAccessPolicyStatement *node = (zetasql::ASTDropRowAccessPolicyStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTCreatePrivilegeRestrictionStatement_privileges)(void * arg0,void ** arg1){
  zetasql::ASTCreatePrivilegeRestrictionStatement *node = (zetasql::ASTCreatePrivilegeRestrictionStatement *)arg0;
  *arg1 = (void *)node->privileges();
}

void GO_EXPORT(ASTCreatePrivilegeRestrictionStatement_object_type)(void * arg0,void ** arg1){
  zetasql::ASTCreatePrivilegeRestrictionStatement *node = (zetasql::ASTCreatePrivilegeRestrictionStatement *)arg0;
  *arg1 = (void *)node->object_type();
}

void GO_EXPORT(ASTCreatePrivilegeRestrictionStatement_name_path)(void * arg0,void ** arg1){
  zetasql::ASTCreatePrivilegeRestrictionStatement *node = (zetasql::ASTCreatePrivilegeRestrictionStatement *)arg0;
  *arg1 = (void *)node->name_path();
}

void GO_EXPORT(ASTCreatePrivilegeRestrictionStatement_restrict_to)(void * arg0,void ** arg1){
  zetasql::ASTCreatePrivilegeRestrictionStatement *node = (zetasql::ASTCreatePrivilegeRestrictionStatement *)arg0;
  *arg1 = (void *)node->restrict_to();
}

void GO_EXPORT(ASTCreateRowAccessPolicyStatement_set_has_access_keyword)(void * arg0,int arg1){
  zetasql::ASTCreateRowAccessPolicyStatement *node = (zetasql::ASTCreateRowAccessPolicyStatement *)arg0;
  node->set_has_access_keyword(arg1);
}

void GO_EXPORT(ASTCreateRowAccessPolicyStatement_has_access_keyword)(void * arg0,char* arg1){
  zetasql::ASTCreateRowAccessPolicyStatement *node = (zetasql::ASTCreateRowAccessPolicyStatement *)arg0;
  *arg1 = node->has_access_keyword();
}

void GO_EXPORT(ASTCreateRowAccessPolicyStatement_target_path)(void * arg0,void ** arg1){
  zetasql::ASTCreateRowAccessPolicyStatement *node = (zetasql::ASTCreateRowAccessPolicyStatement *)arg0;
  *arg1 = (void *)node->target_path();
}

void GO_EXPORT(ASTCreateRowAccessPolicyStatement_grant_to)(void * arg0,void ** arg1){
  zetasql::ASTCreateRowAccessPolicyStatement *node = (zetasql::ASTCreateRowAccessPolicyStatement *)arg0;
  *arg1 = (void *)node->grant_to();
}

void GO_EXPORT(ASTCreateRowAccessPolicyStatement_filter_using)(void * arg0,void ** arg1){
  zetasql::ASTCreateRowAccessPolicyStatement *node = (zetasql::ASTCreateRowAccessPolicyStatement *)arg0;
  *arg1 = (void *)node->filter_using();
}

void GO_EXPORT(ASTCreateRowAccessPolicyStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTCreateRowAccessPolicyStatement *node = (zetasql::ASTCreateRowAccessPolicyStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTDropStatement_set_drop_mode)(void * arg0,int arg1){
  zetasql::ASTDropStatement *node = (zetasql::ASTDropStatement *)arg0;
  node->set_drop_mode((zetasql::ASTDropStatement::DropMode)arg1);
}

void GO_EXPORT(ASTDropStatement_drop_mode)(void * arg0,int* arg1){
  zetasql::ASTDropStatement *node = (zetasql::ASTDropStatement *)arg0;
  *arg1 = node->drop_mode();
}

void GO_EXPORT(ASTDropStatement_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTDropStatement *node = (zetasql::ASTDropStatement *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTDropStatement_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTDropStatement *node = (zetasql::ASTDropStatement *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTDropStatement_set_schema_object_kind)(void * arg0,int arg1){
  zetasql::ASTDropStatement *node = (zetasql::ASTDropStatement *)arg0;
  node->set_schema_object_kind((zetasql::SchemaObjectKind)arg1);
}

void GO_EXPORT(ASTDropStatement_schema_object_kind)(void * arg0,int* arg1){
  zetasql::ASTDropStatement *node = (zetasql::ASTDropStatement *)arg0;
  *arg1 = node->schema_object_kind();
}

void GO_EXPORT(ASTDropStatemnt_name)(void * arg0,void ** arg1){
  zetasql::ASTDropStatement *node = (zetasql::ASTDropStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTSingleAssignment_variable)(void * arg0,void ** arg1){
  zetasql::ASTSingleAssignment *node = (zetasql::ASTSingleAssignment *)arg0;
  *arg1 = (void *)node->variable();
}

void GO_EXPORT(ASTSingleAssignment_expression)(void * arg0,void ** arg1){
  zetasql::ASTSingleAssignment *node = (zetasql::ASTSingleAssignment *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTParameterAssignment_parameter)(void * arg0,void ** arg1){
  zetasql::ASTParameterAssignment *node = (zetasql::ASTParameterAssignment *)arg0;
  *arg1 = (void *)node->parameter();
}

void GO_EXPORT(ASTParameterAssignment_expression)(void * arg0,void ** arg1){
  zetasql::ASTParameterAssignment *node = (zetasql::ASTParameterAssignment *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTSystemVariableAssignment_system_variable)(void * arg0,void ** arg1){
  zetasql::ASTSystemVariableAssignment *node = (zetasql::ASTSystemVariableAssignment *)arg0;
  *arg1 = (void *)node->system_variable();
}

void GO_EXPORT(ASTSystemVariableAssignment_expression)(void * arg0,void ** arg1){
  zetasql::ASTSystemVariableAssignment *node = (zetasql::ASTSystemVariableAssignment *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTAssignmentFromStruct_variables)(void * arg0,void ** arg1){
  zetasql::ASTAssignmentFromStruct *node = (zetasql::ASTAssignmentFromStruct *)arg0;
  *arg1 = (void *)node->variables();
}

void GO_EXPORT(ASTAssignmentFromStruct_struct_expression)(void * arg0,void ** arg1){
  zetasql::ASTAssignmentFromStruct *node = (zetasql::ASTAssignmentFromStruct *)arg0;
  *arg1 = (void *)node->struct_expression();
}

void GO_EXPORT(ASTCreateTableStmtBase_name)(void * arg0,void ** arg1){
  zetasql::ASTCreateTableStmtBase *node = (zetasql::ASTCreateTableStmtBase *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTCreateTableStmtBase_table_element_list)(void * arg0,void ** arg1){
  zetasql::ASTCreateTableStmtBase *node = (zetasql::ASTCreateTableStmtBase *)arg0;
  *arg1 = (void *)node->table_element_list();
}

void GO_EXPORT(ASTCreateTableStmtBase_options_list)(void * arg0,void ** arg1){
  zetasql::ASTCreateTableStmtBase *node = (zetasql::ASTCreateTableStmtBase *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTCreateTableStmtBase_like_table_name)(void * arg0,void ** arg1){
  zetasql::ASTCreateTableStmtBase *node = (zetasql::ASTCreateTableStmtBase *)arg0;
  *arg1 = (void *)node->like_table_name();
}

void GO_EXPORT(ASTCreateTableStmtBase_collate)(void * arg0,void ** arg1){
  zetasql::ASTCreateTableStmtBase *node = (zetasql::ASTCreateTableStmtBase *)arg0;
  *arg1 = (void *)node->collate();
}

void GO_EXPORT(ASTCreateTableStatement_clone_data_source)(void * arg0,void ** arg1){
  zetasql::ASTCreateTableStatement *node = (zetasql::ASTCreateTableStatement *)arg0;
  *arg1 = (void *)node->clone_data_source();
}

void GO_EXPORT(ASTCreateTableStatement_copy_data_source)(void * arg0,void ** arg1){
  zetasql::ASTCreateTableStatement *node = (zetasql::ASTCreateTableStatement *)arg0;
  *arg1 = (void *)node->copy_data_source();
}

void GO_EXPORT(ASTCreateTableStatement_partition_by)(void * arg0,void ** arg1){
  zetasql::ASTCreateTableStatement *node = (zetasql::ASTCreateTableStatement *)arg0;
  *arg1 = (void *)node->partition_by();
}

void GO_EXPORT(ASTCreateTableStatement_cluster_by)(void * arg0,void ** arg1){
  zetasql::ASTCreateTableStatement *node = (zetasql::ASTCreateTableStatement *)arg0;
  *arg1 = (void *)node->cluster_by();
}

void GO_EXPORT(ASTCreateTableStatement_query)(void * arg0,void ** arg1){
  zetasql::ASTCreateTableStatement *node = (zetasql::ASTCreateTableStatement *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ASTCreateExternalTableStatement_with_partition_columns_clause)(void * arg0,void ** arg1){
  zetasql::ASTCreateExternalTableStatement *node = (zetasql::ASTCreateExternalTableStatement *)arg0;
  *arg1 = (void *)node->with_partition_columns_clause();
}

void GO_EXPORT(ASTCreateExternalTableStatement_with_connection_clause)(void * arg0,void ** arg1){
  zetasql::ASTCreateExternalTableStatement *node = (zetasql::ASTCreateExternalTableStatement *)arg0;
  *arg1 = (void *)node->with_connection_clause();
}

void GO_EXPORT(ASTCreateViewStatementBase_name)(void * arg0,void ** arg1){
  zetasql::ASTCreateViewStatementBase *node = (zetasql::ASTCreateViewStatementBase *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTCreateViewStatementBase_column_list)(void * arg0,void ** arg1){
  zetasql::ASTCreateViewStatementBase *node = (zetasql::ASTCreateViewStatementBase *)arg0;
  *arg1 = (void *)node->column_list();
}

void GO_EXPORT(ASTCreateViewStatementBase_options_list)(void * arg0,void ** arg1){
  zetasql::ASTCreateViewStatementBase *node = (zetasql::ASTCreateViewStatementBase *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTCreateViewStatementBase_query)(void * arg0,void ** arg1){
  zetasql::ASTCreateViewStatementBase *node = (zetasql::ASTCreateViewStatementBase *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ASTCreateMaterializedViewStatement_partition_by)(void * arg0,void ** arg1){
  zetasql::ASTCreateMaterializedViewStatement *node = (zetasql::ASTCreateMaterializedViewStatement *)arg0;
  *arg1 = (void *)node->partition_by();
}

void GO_EXPORT(ASTCreateMaterializedViewStatement_cluster_by)(void * arg0,void ** arg1){
  zetasql::ASTCreateMaterializedViewStatement *node = (zetasql::ASTCreateMaterializedViewStatement *)arg0;
  *arg1 = (void *)node->cluster_by();
}

void GO_EXPORT(ASTLoopStatement_label)(void * arg0,void ** arg1){
  zetasql::ASTLoopStatement *node = (zetasql::ASTLoopStatement *)arg0;
  *arg1 = (void *)node->label();
}

void GO_EXPORT(ASTLoopStatement_body)(void * arg0,void ** arg1){
  zetasql::ASTLoopStatement *node = (zetasql::ASTLoopStatement *)arg0;
  *arg1 = (void *)node->body();
}

void GO_EXPORT(ASTLoopStatement_IsLoopStatement)(void * arg0,char* arg1){
  zetasql::ASTLoopStatement *node = (zetasql::ASTLoopStatement *)arg0;
  *arg1 = node->IsLoopStatement();
}

void GO_EXPORT(ASTWhileStatement_condition)(void * arg0,void ** arg1){
  zetasql::ASTWhileStatement *node = (zetasql::ASTWhileStatement *)arg0;
  *arg1 = (void *)node->condition();
}

void GO_EXPORT(ASTRepeatStatement_until_clause)(void * arg0,void ** arg1){
  zetasql::ASTRepeatStatement *node = (zetasql::ASTRepeatStatement *)arg0;
  *arg1 = (void *)node->until_clause();
}

void GO_EXPORT(ASTForInStatement_variable)(void * arg0,void ** arg1){
  zetasql::ASTForInStatement *node = (zetasql::ASTForInStatement *)arg0;
  *arg1 = (void *)node->variable();
}

void GO_EXPORT(ASTForInStatement_query)(void * arg0,void ** arg1){
  zetasql::ASTForInStatement *node = (zetasql::ASTForInStatement *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ASTAlterStatementBase_set_is_if_exists)(void * arg0,int arg1){
  zetasql::ASTAlterStatementBase *node = (zetasql::ASTAlterStatementBase *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ASTAlterStatementBase_is_if_exists)(void * arg0,char* arg1){
  zetasql::ASTAlterStatementBase *node = (zetasql::ASTAlterStatementBase *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ASTAlterStatementBase_path)(void * arg0,void ** arg1){
  zetasql::ASTAlterStatementBase *node = (zetasql::ASTAlterStatementBase *)arg0;
  *arg1 = (void *)node->path();
}

void GO_EXPORT(ASTAlterStatementBase_action_list)(void * arg0,void ** arg1){
  zetasql::ASTAlterStatementBase *node = (zetasql::ASTAlterStatementBase *)arg0;
  *arg1 = (void *)node->action_list();
}

void GO_EXPORT(ASTAlterPrivilegeRestrictionStatement_privileges)(void * arg0,void ** arg1){
  zetasql::ASTAlterPrivilegeRestrictionStatement *node = (zetasql::ASTAlterPrivilegeRestrictionStatement *)arg0;
  *arg1 = (void *)node->privileges();
}

void GO_EXPORT(ASTAlterPrivilegeRestrictionStatement_object_type)(void * arg0,void ** arg1){
  zetasql::ASTAlterPrivilegeRestrictionStatement *node = (zetasql::ASTAlterPrivilegeRestrictionStatement *)arg0;
  *arg1 = (void *)node->object_type();
}

void GO_EXPORT(ASTAlterRowAccessPolicyStatement_name)(void * arg0,void ** arg1){
  zetasql::ASTAlterRowAccessPolicyStatement *node = (zetasql::ASTAlterRowAccessPolicyStatement *)arg0;
  *arg1 = (void *)node->name();
}

void GO_EXPORT(ASTAlterEntityStatement_type)(void * arg0,void ** arg1){
  zetasql::ASTAlterEntityStatement *node = (zetasql::ASTAlterEntityStatement *)arg0;
  *arg1 = (void *)node->type();
}

void GO_EXPORT(ASTCreateFunctionStmtBase_set_determinism_level)(void * arg0,int arg1){
  zetasql::ASTCreateFunctionStmtBase *node = (zetasql::ASTCreateFunctionStmtBase *)arg0;
  node->set_determinism_level((zetasql::ASTCreateFunctionStmtBase::DeterminismLevel)arg1);
}

void GO_EXPORT(ASTCreateFunctionStmtBase_determinism_level)(void * arg0,int* arg1){
  zetasql::ASTCreateFunctionStmtBase *node = (zetasql::ASTCreateFunctionStmtBase *)arg0;
  *arg1 = node->determinism_level();
}

void GO_EXPORT(ASTCreateFunctionStmtBase_set_sql_security)(void * arg0,int arg1){
  zetasql::ASTCreateFunctionStmtBase *node = (zetasql::ASTCreateFunctionStmtBase *)arg0;
  node->set_sql_security((zetasql::ASTCreateStatement::SqlSecurity)arg1);
}

void GO_EXPORT(ASTCreateFunctionStmtBase_sql_security)(void * arg0,int* arg1){
  zetasql::ASTCreateFunctionStmtBase *node = (zetasql::ASTCreateFunctionStmtBase *)arg0;
  *arg1 = node->sql_security();
}

void GO_EXPORT(ASTCreateFunctionStmtBase_function_declaration)(void * arg0,void ** arg1){
  zetasql::ASTCreateFunctionStmtBase *node = (zetasql::ASTCreateFunctionStmtBase *)arg0;
  *arg1 = (void *)node->function_declaration();
}

void GO_EXPORT(ASTCreateFunctionStmtBase_language)(void * arg0,void ** arg1){
  zetasql::ASTCreateFunctionStmtBase *node = (zetasql::ASTCreateFunctionStmtBase *)arg0;
  *arg1 = (void *)node->language();
}

void GO_EXPORT(ASTCreateFunctionStmtBase_code)(void * arg0,void ** arg1){
  zetasql::ASTCreateFunctionStmtBase *node = (zetasql::ASTCreateFunctionStmtBase *)arg0;
  *arg1 = (void *)node->code();
}

void GO_EXPORT(ASTCreateFunctionStmtBase_options_list)(void * arg0,void ** arg1){
  zetasql::ASTCreateFunctionStmtBase *node = (zetasql::ASTCreateFunctionStmtBase *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTCreateFunctionStatement_set_is_aggregate)(void * arg0,int arg1){
  zetasql::ASTCreateFunctionStatement *node =(zetasql::ASTCreateFunctionStatement *)arg0;
  node->set_is_aggregate(arg1);
}

void GO_EXPORT(ASTCreateFunctionStatement_is_aggregate)(void * arg0,char* arg1){
  zetasql::ASTCreateFunctionStatement *node =(zetasql::ASTCreateFunctionStatement *)arg0;
  *arg1 = node->is_aggregate();
}

void GO_EXPORT(ASTCreateFunctionStatement_set_is_remote)(void * arg0,int arg1){
  zetasql::ASTCreateFunctionStatement *node =(zetasql::ASTCreateFunctionStatement *)arg0;
  node->set_is_remote(arg1);
}

void GO_EXPORT(ASTCreateFunctionStatement_is_remote)(void * arg0,char* arg1){
  zetasql::ASTCreateFunctionStatement *node =(zetasql::ASTCreateFunctionStatement *)arg0;
  *arg1 = node->is_remote();
}

void GO_EXPORT(ASTCreateFunctionStatement_return_type)(void * arg0,void ** arg1){
  zetasql::ASTCreateFunctionStatement *node =(zetasql::ASTCreateFunctionStatement *)arg0;
  *arg1 = (void *)node->return_type();
}

void GO_EXPORT(ASTCreateFunctionStatement_sql_function_body)(void * arg0,void ** arg1){
  zetasql::ASTCreateFunctionStatement *node =(zetasql::ASTCreateFunctionStatement *)arg0;
  *arg1 = (void *)node->sql_function_body();
}

void GO_EXPORT(ASTCreateFunctionStatement_with_connection_clause)(void * arg0,void ** arg1){
  zetasql::ASTCreateFunctionStatement *node =(zetasql::ASTCreateFunctionStatement *)arg0;
  *arg1 = (void *)node->with_connection_clause();
}

void GO_EXPORT(ASTCreateTableFunctionStatement_return_tvf_schema)(void * arg0,void ** arg1){
  zetasql::ASTCreateTableFunctionStatement *node = (zetasql::ASTCreateTableFunctionStatement *)arg0;
  *arg1 = (void *)node->return_tvf_schema();
}

void GO_EXPORT(ASTCreateTableFunctionStatement_query)(void * arg0,void ** arg1){
  zetasql::ASTCreateTableFunctionStatement *node = (zetasql::ASTCreateTableFunctionStatement *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ASTStructColumnSchema_struct_fields_num)(void * arg0,int* arg1){
  zetasql::ASTStructColumnSchema *node = (zetasql::ASTStructColumnSchema *)arg0;
  *arg1 = node->struct_fields().length();
}

void GO_EXPORT(ASTStructColumnSchema_struct_field)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTStructColumnSchema *node = (zetasql::ASTStructColumnSchema *)arg0;
  *arg2 = (void *)node->struct_fields(arg1);
}

void GO_EXPORT(ASTExecuteIntoClause_identifiers)(void * arg0,void ** arg1){
  zetasql::ASTExecuteIntoClause *node = (zetasql::ASTExecuteIntoClause *)arg0;
  *arg1 = (void *)node->identifiers();
}

void GO_EXPORT(ASTExecuteUsingArgument_expression)(void * arg0,void ** arg1){
  zetasql::ASTExecuteUsingArgument *node = (zetasql::ASTExecuteUsingArgument *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ASTExecuteUsingArgument_alias)(void * arg0,void ** arg1){
  zetasql::ASTExecuteUsingArgument *node = (zetasql::ASTExecuteUsingArgument *)arg0;
  *arg1 = (void *)node->alias();
}

void GO_EXPORT(ASTExecuteUsingClause_arguments_num)(void * arg0,int* arg1){
  zetasql::ASTExecuteUsingClause *node = (zetasql::ASTExecuteUsingClause *)arg0;
  *arg1 = node->arguments().length();
}

void GO_EXPORT(ASTExecuteUsingClause_argument)(void * arg0,int arg1,void ** arg2){
  zetasql::ASTExecuteUsingClause *node = (zetasql::ASTExecuteUsingClause *)arg0;
  *arg2 = (void *)node->arguments(arg1);
}

void GO_EXPORT(ASTExecuteImmediateStatement_sql)(void * arg0,void ** arg1){
  zetasql::ASTExecuteImmediateStatement *node = (zetasql::ASTExecuteImmediateStatement *)arg0;
  *arg1 = (void *)node->sql();
}

void GO_EXPORT(ASTExecuteImmediateStatement_into_clause)(void * arg0,void ** arg1){
  zetasql::ASTExecuteImmediateStatement *node = (zetasql::ASTExecuteImmediateStatement *)arg0;
  *arg1 = (void *)node->into_clause();
}

void GO_EXPORT(ASTExecuteImmediateStatement_using_clause)(void * arg0,void ** arg1){
  zetasql::ASTExecuteImmediateStatement *node = (zetasql::ASTExecuteImmediateStatement *)arg0;
  *arg1 = (void *)node->using_clause();
}

void GO_EXPORT(ASTAuxLoadDataFromFilesOptionsList_options_list)(void * arg0,void ** arg1){
  zetasql::ASTAuxLoadDataFromFilesOptionsList *node = (zetasql::ASTAuxLoadDataFromFilesOptionsList *)arg0;
  *arg1 = (void *)node->options_list();
}

void GO_EXPORT(ASTAuxLoadDataStatement_set_insertion_mode)(void * arg0,int arg1){
  zetasql::ASTAuxLoadDataStatement *node = (zetasql::ASTAuxLoadDataStatement *)arg0;
  node->set_insertion_mode((zetasql::ASTAuxLoadDataStatement::InsertionMode)arg1);
}

void GO_EXPORT(ASTAuxLoadDataStatement_insertion_mode)(void * arg0,int* arg1){
  zetasql::ASTAuxLoadDataStatement *node = (zetasql::ASTAuxLoadDataStatement *)arg0;
  *arg1 = node->insertion_mode();
}

void GO_EXPORT(ASTAuxLoadDataStatement_partition_by)(void * arg0,void ** arg1){
  zetasql::ASTAuxLoadDataStatement *node = (zetasql::ASTAuxLoadDataStatement *)arg0;
  *arg1 = (void *)node->partition_by();
}

void GO_EXPORT(ASTAuxLoadDataStatement_cluster_by)(void * arg0,void ** arg1){
  zetasql::ASTAuxLoadDataStatement *node = (zetasql::ASTAuxLoadDataStatement *)arg0;
  *arg1 = (void *)node->cluster_by();
}

void GO_EXPORT(ASTAuxLoadDataStatement_from_files)(void * arg0,void ** arg1){
  zetasql::ASTAuxLoadDataStatement *node = (zetasql::ASTAuxLoadDataStatement *)arg0;
  *arg1 = (void *)node->from_files();
}

void GO_EXPORT(ASTAuxLoadDataStatement_with_partition_columns_clause)(void * arg0,void ** arg1){
  zetasql::ASTAuxLoadDataStatement *node = (zetasql::ASTAuxLoadDataStatement *)arg0;
  *arg1 = (void *)node->with_partition_columns_clause();
}

void GO_EXPORT(ASTAuxLoadDataStatement_with_connection_clause)(void * arg0,void ** arg1){
  zetasql::ASTAuxLoadDataStatement *node = (zetasql::ASTAuxLoadDataStatement *)arg0;
  *arg1 = (void *)node->with_connection_clause();
}

void GO_EXPORT(ASTLabel_name)(void * arg0,void ** arg1){
  zetasql::ASTLabel *node = (zetasql::ASTLabel *)arg0;
  *arg1 = (void *)node->name();
}

