#ifndef ZETASQL_PUBLIC_FUNCTIONS_CONVERT_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_CONVERT_EXPORT_H

#include "zetasql/public/functions/convert.h"
#include "zetasql/public/functions/convert.cc"

#if 0
namespace zetasql {
  namespace functions {
    namespace internal {

      const char* const kConvertOverflowInt32 = "int32 out of range: ";
      const char* const kConvertOverflowInt64 = "int64 out of range: ";
      const char* const kConvertOverflowUint32 = "uint32 out of range: ";
      const char* const kConvertOverflowUint64 = "uint64 out of range: ";
      const char* const kConvertOverflowFloat = "float out of range: ";
      const char* const kConvertNonFinite = "Illegal conversion of non-finite floating point number to an integer: ";

    }
  }
}
#endif

#include "go-zetasql/public/functions/convert_internal/export.inc"
#include "go-zetasql/public/functions/util/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/numeric_value/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
