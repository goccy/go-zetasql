#ifndef ZETASQL_COMMON_AGGREGATE_NULL_HANDLING_EXPORT_H
#define ZETASQL_COMMON_AGGREGATE_NULL_HANDLING_EXPORT_H

#include "zetasql/common/aggregate_null_handling.h"
#include "zetasql/common/aggregate_null_handling.cc"

#if 0
namespace zetasql {

  bool IgnoresNullArguments(const ResolvedNonScalarFunctionCallBase* aggregate_function) {
    return false;
  }

}
#endif

#include "go-zetasql/base/case/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"

#endif
