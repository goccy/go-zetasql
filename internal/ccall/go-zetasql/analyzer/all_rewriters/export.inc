#ifndef ZETASQL_ANALYZER_ALL_REWRITERS_EXPORT_H
#define ZETASQL_ANALYZER_ALL_REWRITERS_EXPORT_H

#include "zetasql/analyzer/all_rewriters.h"
#include "zetasql/analyzer/all_rewriters.cc"

#if 0
namespace zetasql {

  void RegisterBuiltinRewriters() {
  }

}
#endif

#include "go-zetasql/analyzer/anonymization_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/array_functions_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/flatten_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/let_expr_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/map_function_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/pivot_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/registration/export.inc"
#include "go-zetasql/analyzer/rewriters/rewriter_interface/export.inc"
#include "go-zetasql/analyzer/rewriters/sql_function_inliner/export.inc"
#include "go-zetasql/analyzer/rewriters/typeof_function_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/unpivot_rewriter/export.inc"
#include "go-absl/base/base/export.inc"

#endif
