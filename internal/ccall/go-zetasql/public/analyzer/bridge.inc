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

void GO_EXPORT(Node_node_kind)(void * arg0,int* arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  *arg1 = node->node_kind();
}

void GO_EXPORT(Node_IsScan)(void * arg0,int* arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  *arg1 = node->IsScan();
}

void GO_EXPORT(Node_IsExpression)(void * arg0,int* arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  *arg1 = node->IsExpression();
}

void GO_EXPORT(Node_IsStatement)(void * arg0,int* arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  *arg1 = node->IsStatement();
}

void GO_EXPORT(Node_DebugString)(void * arg0,void ** arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  *arg1 = (void *)node->DebugString().c_str();
}

void GO_EXPORT(Node_GetChildNodes_num)(void * arg0,int* arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  std::vector<const zetasql::ResolvedNode *> child_nodes;
  node->GetChildNodes(&child_nodes);
  *arg1 = child_nodes.size();
}

void GO_EXPORT(Node_GetChildNode)(void * arg0,int arg1,void ** arg2)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  std::vector<const zetasql::ResolvedNode *> child_nodes;
  node->GetChildNodes(&child_nodes);
  *arg2 = (void *)child_nodes[arg1];
}

void GO_EXPORT(Node_GetTreeDepth)(void * arg0,int* arg1)
{
  zetasql::ResolvedNode *node = (zetasql::ResolvedNode *)arg0;
  *arg1 = node->GetTreeDepth();
}
