#ifndef ZETASQL_ANALYZER_EXPR_MATCHING_HELPERS_EXPORT_H
#define ZETASQL_ANALYZER_EXPR_MATCHING_HELPERS_EXPORT_H

#include "zetasql/analyzer/expr_matching_helpers.h"
#include "zetasql/analyzer/expr_matching_helpers.cc"

#if 0
namespace zetasql {

  absl::StatusOr<bool> IsSameExpressionForGroupBy(const ResolvedExpr* expr1,
                                                  const ResolvedExpr* expr2) {
    return false;
  }

  size_t FieldPathHash(const ResolvedExpr* expr) {
    return 0;
  }

  bool IsSameFieldPath(const ResolvedExpr* field_path1,
                       const ResolvedExpr* field_path2,
                       FieldPathMatchingOption match_option) {
    return false;
  }

}
#endif

#include "go-zetasql/base/logging/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/function_cc_proto/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-absl/hash/hash/export.inc"
#include "go-absl/status/statusor/export.inc"

#endif
