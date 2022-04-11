
extern void GO_EXPORT(AnalyzeStatement)(void * arg0,void * arg1,void ** arg2,void ** arg3);
extern void GO_EXPORT(AnalyzerOutput_resolved_statement)(void * arg0,void ** arg1);
extern void GO_EXPORT(Node_node_kind)(void * arg0,int* arg1);
extern void GO_EXPORT(Node_IsScan)(void * arg0,int* arg1);
extern void GO_EXPORT(Node_IsExpression)(void * arg0,int* arg1);
extern void GO_EXPORT(Node_IsStatement)(void * arg0,int* arg1);
extern void GO_EXPORT(Node_DebugString)(void * arg0,void ** arg1);
extern void GO_EXPORT(Node_GetChildNodes_num)(void * arg0,int* arg1);
extern void GO_EXPORT(Node_GetChildNode)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(Node_GetTreeDepth)(void * arg0,int* arg1);
extern void GO_EXPORT(Literal_value)(void * arg0,void ** arg1);
extern void GO_EXPORT(Literal_set_value)(void * arg0,void * arg1);
extern void GO_EXPORT(Literal_has_explicit_type)(void * arg0,int* arg1);
extern void GO_EXPORT(Literal_set_has_explicit_type)(void * arg0,int arg1);
extern void GO_EXPORT(Literal_float_literal_id)(void * arg0,int* arg1);
extern void GO_EXPORT(Literal_set_float_literal_id)(void * arg0,int arg1);
extern void GO_EXPORT(Literal_preserve_in_literal_remover)(void * arg0,int* arg1);
extern void GO_EXPORT(Literal_set_preserve_in_literal_remover)(void * arg0,int arg1);
