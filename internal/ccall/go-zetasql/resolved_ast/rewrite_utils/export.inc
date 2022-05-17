#ifndef ZETASQL_RESOLVED_AST_REWRITE_UTILS_EXPORT_H
#define ZETASQL_RESOLVED_AST_REWRITE_UTILS_EXPORT_H

#include "zetasql/resolved_ast/rewrite_utils.h"
#include "zetasql/resolved_ast/rewrite_utils.cc"

#if 0
namespace zetasql {

  ResolvedColumn ColumnFactory::MakeCol(const std::string& table_name,
                                        const std::string& col_name,
                                        const Type* type) {
    ResolvedColumn v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ResolvedExpr>> CorrelateColumnRefsImpl(const ResolvedExpr& expr) {
    std::unique_ptr<ResolvedExpr> v;
    return v;
  }

  absl::Status CollectColumnRefs(const ResolvedNode& node,
                                 std::vector<std::unique_ptr<const ResolvedColumnRef>>* column_refs,
                                 bool correlate) {
    absl::Status v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ResolvedNode>>
  CopyResolvedASTAndRemapColumnsImpl(const ResolvedNode& input_tree,
                                     ColumnFactory& column_factory,
                                     ColumnReplacementMap& column_map) {
    std::unique_ptr<ResolvedNode> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ResolvedFunctionCall>> FunctionCallBuilder::If(std::unique_ptr<const ResolvedExpr> condition,
                                                                                std::unique_ptr<const ResolvedExpr> then_case,
                                                                                std::unique_ptr<const ResolvedExpr> else_case) {
    std::unique_ptr<ResolvedFunctionCall> v;
    return v;
  }

}
#endif

#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/statusor/export.inc"

#endif
