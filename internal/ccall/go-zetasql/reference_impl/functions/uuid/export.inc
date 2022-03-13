#ifndef ZETASQL_REFERENCE_IMPL_FUNCTIONS_UUID_EXPORT_H
#define ZETASQL_REFERENCE_IMPL_FUNCTIONS_UUID_EXPORT_H

#include "zetasql/reference_impl/functions/uuid.h"

namespace zetasql {

  void RegisterBuiltinUuidFunctions() {
  }

}

#include "go-zetasql/public/functions/uuid/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/reference_impl/evaluation/export.inc"
#include "go-absl/status/statusor/export.inc"

#endif
