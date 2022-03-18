#ifndef ZETASQL_ANALYZER_INPUT_ARGUMENT_TYPE_RESOLVER_HELPER_EXPORT_H
#define ZETASQL_ANALYZER_INPUT_ARGUMENT_TYPE_RESOLVER_HELPER_EXPORT_H

#include "zetasql/analyzer/input_argument_type_resolver_helper.h"
#include "zetasql/analyzer/input_argument_type_resolver_helper.cc"

#if 0
namespace zetasql {

  InputArgumentType GetInputArgumentTypeForExpr(const ResolvedExpr* expr) {
    InputArgumentType v;
    return v;
  }

  void GetInputArgumentTypesForGenericArgumentList(const std::vector<const ASTNode*>& argument_ast_nodes,
                                                   const std::vector<std::unique_ptr<const ResolvedExpr>>& arguments,
                                                   std::vector<InputArgumentType>* input_arguments) {
  }

}
#endif

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-absl/types/optional/export.inc"

#endif
