#ifndef ZETASQL_ANALYZER_ANONIMIZATION_REWRITER_EXPORT_H
#define ZETASQL_ANALYZER_ANONIMIZATION_REWRITER_EXPORT_H

#include "zetasql/analyzer/anonymization_rewriter.h"
#include "zetasql/analyzer/anonymization_rewriter.cc"

#if 0
namespace zetasql {

  absl::StatusOr<RewriteForAnonymizationOutput>
  RewriteForAnonymization(const ResolvedNode& query, Catalog* catalog,
                          TypeFactory* type_factory,
                          const AnalyzerOptions& analyzer_options,
                          ColumnFactory& column_factory) {
    RewriteForAnonymizationOutput v;
    return v;
  }

  const Rewriter* GetAnonymizationRewriter() {
    return nullptr;
  }

}
#endif

#include "go-zetasql/analyzer/expr_matching_helpers/export.inc"
#include "go-zetasql/analyzer/name_scope/export.inc"
#include "go-zetasql/analyzer/resolver/export.inc"
#include "go-zetasql/analyzer/rewriters/rewriter_interface/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/status_payload_utils/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/proto/internal_error_location_cc_proto/export.inc"
#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/analyzer_output/export.inc"
#include "go-zetasql/public/analyzer_output_properties/export.inc"
#include "go-zetasql/public/anon_function/export.inc"
#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/make_node_vector/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast_enums_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/rewrite_utils/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/types/span/export.inc"

#endif
