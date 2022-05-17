#ifndef ZETASQL_ANALYZER_SUBSTITUTE_EXPORT_H
#define ZETASQL_ANALYZER_SUBSTITUTE_EXPORT_H

#include "zetasql/analyzer/substitute.h"
#include "zetasql/analyzer/substitute.cc"

#if 0
namespace zetasql {

  absl::Status ExpectAnalyzeSubstituteSuccess(zetasql_base::StatusBuilder status_builder) {
    absl::Status v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ResolvedExpr>> AnalyzeSubstitute(AnalyzerOptions options, Catalog& catalog, TypeFactory& type_factory,
                                                                  absl::string_view expression,
                                                                  const absl::flat_hash_map<std::string, const ResolvedExpr*>& variables,
                                                                  const absl::flat_hash_map<std::string, const ResolvedInlineLambda*>&
                                                                  lambdas) {
    std::unique_ptr<ResolvedExpr> v;
    return v;
  }

}
#endif

#include "go-zetasql/analyzer/analyzer_impl/export.inc"
#include "go-zetasql/base/logging/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/analyzer_output/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/function_cc_proto/export.inc"
#include "go-zetasql/public/multi_catalog/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/simple_catalog/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/rewrite_utils/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"

#endif
