#ifndef ZETASQL_REFERENCE_IMPL_FUNCTIONS_REGISTER_ALL_EXPORT_H
#define ZETASQL_REFERENCE_IMPL_FUNCTIONS_REGISTER_ALL_EXPORT_H

#include "zetasql/reference_impl/functions/register_all.h"

namespace zetasql {

  void RegisterAllOptionalBuiltinFunctions() {
  }

}

#include "go-zetasql/reference_impl/functions/hash/export.inc"
#include "go-zetasql/reference_impl/functions/json/export.inc"
#include "go-zetasql/reference_impl/functions/string_with_collation/export.inc"
#include "go-zetasql/reference_impl/functions/uuid/export.inc"

#endif
