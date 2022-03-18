#ifndef ZETASQL_ANALYZER_REWRITERS_REWRITER_RELEVANCE_CHECKER_EXPORT_H
#define ZETASQL_ANALYZER_REWRITERS_REWRITER_RELEVANCE_CHECKER_EXPORT_H

#include "zetasql/analyzer/rewriters/rewriter_relevance_checker.h"
#include "zetasql/analyzer/rewriters/rewriter_relevance_checker.cc"

#if 0
namespace zetasql {

  absl::StatusOr<absl::btree_set<ResolvedASTRewrite>> FindRelevantRewriters(const ResolvedNode* node) {
    absl::btree_set<ResolvedASTRewrite> v;
    return v;
  }

}
#endif

#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/sql_function/export.inc"
#include "go-zetasql/public/templated_sql_function/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-absl/container/btree/export.inc"
#include "go-absl/status/statusor/export.inc"

#endif
