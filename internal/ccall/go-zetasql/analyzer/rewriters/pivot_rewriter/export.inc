#ifndef ZETASQL_ANALYZER_REWRITERS_PIVOT_REWRITER_EXPORT_H
#define ZETASQL_ANALYZER_REWRITERS_PIVOT_REWRITER_EXPORT_H

#include "zetasql/analyzer/rewriters/pivot_rewriter.h"
#include "zetasql/analyzer/rewriters/pivot_rewriter.cc"

#if 0
namespace zetasql {

  const Rewriter* GetPivotRewriter() {
    return nullptr;
  }

}
#endif

#include "go-zetasql/analyzer/rewriters/rewriter_interface/export.inc"
#include "go-zetasql/analyzer/resolver/export.inc"
#include "go-zetasql/analyzer/substitute/export.inc"
#include "go-zetasql/base/logging/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/aggregate_null_handling/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/analyzer_output/export.inc"
#include "go-zetasql/public/analyzer_output_properties/export.inc"
#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/public/annotation/collation/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast_enums_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/rewrite_utils/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/types/span/export.inc"

#endif
