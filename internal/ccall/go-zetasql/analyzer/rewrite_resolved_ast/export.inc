#ifndef ZETASQL_ANALYZER_REWRITE_RESOLVED_AST_EXPORT_H
#define ZETASQL_ANALYZER_REWRITE_RESOLVED_AST_EXPORT_H

#include "zetasql/analyzer/rewrite_resolved_ast.h"
#include "zetasql/analyzer/rewrite_resolved_ast.cc"

#if 0
namespace zetasql {

  absl::Status InternalRewriteResolvedAst(const AnalyzerOptions& analyzer_options,
                                          absl::string_view sql, Catalog* catalog,
                                          TypeFactory* type_factory,
                                          AnalyzerOutput& analyzer_output) {
    absl::Status v;
    return v;
  }

}
#endif

#include "go-zetasql/analyzer/rewriters/registration/export.inc"
#include "go-zetasql/analyzer/rewriters/rewriter_interface/export.inc"
#include "go-zetasql/analyzer/rewriters/rewriter_relevance_checker/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/logging/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/analyzer_output/export.inc"
#include "go-zetasql/public/analyzer_output_properties/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/validator/export.inc"
#include "go-absl/algorithm/container/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"

#endif
