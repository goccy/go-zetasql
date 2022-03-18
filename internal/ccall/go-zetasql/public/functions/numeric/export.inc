#ifndef ZETASQL_PUBLIC_FUNCTIONS_NUMERIC_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_NUMERIC_EXPORT_H

#include "zetasql/public/functions/numeric.h"
#include "zetasql/public/functions/numeric.cc"

#if 0
namespace zetasql {
  namespace functions {

    bool ParseNumeric(absl::string_view str, NumericValue* out, absl::Status* error) {
      return false;
    }

    bool ParseBigNumeric(absl::string_view str, BigNumericValue* out, absl::Status* error) {
      return false;
    }

  }
}
#endif

#include "go-zetasql/public/functions/util/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/public/numeric_value/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
