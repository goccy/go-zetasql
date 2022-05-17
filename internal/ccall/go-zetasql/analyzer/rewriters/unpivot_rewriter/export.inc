#ifndef ZETASQL_ANALYZER_REWRITERS_UNPIVOT_REWRITER_EXPORT_H
#define ZETASQL_ANALYZER_REWRITERS_UNPIVOT_REWRITER_EXPORT_H

#include "zetasql/analyzer/rewriters/unpivot_rewriter.h"
#include "zetasql/analyzer/rewriters/unpivot_rewriter.cc"

#if 0
namespace zetasql {

  const Rewriter* GetUnpivotRewriter() {
    return nullptr;
  }

}
#endif

#include "go-zetasql/analyzer/rewriters/rewriter_interface/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/analyzer_output/export.inc"
#include "go-zetasql/public/analyzer_output_properties/export.inc"
#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/rewrite_utils/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"

#endif
