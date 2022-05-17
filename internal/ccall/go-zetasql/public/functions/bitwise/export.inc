#ifndef ZETASQL_PUBLIC_FUNCTIONS_BITWISE_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_BITWISE_EXPORT_H

#include "zetasql/public/functions/bitwise.h"
#include "zetasql/public/functions/bitwise.cc"

#if 0
namespace zetasql {
  namespace functions {

    bool BitwiseNotBytes(absl::string_view in, std::string* out,
                         absl::Status* error) {
      return false;
    }

    bool BitwiseLeftShiftBytes(absl::string_view in1, int64_t in2, std::string* out,
                               absl::Status* error) {
      return false;
    }

    bool BitwiseRightShiftBytes(absl::string_view in1, int64_t in2,
                                std::string* out, absl::Status* error) {
      return false;
    }

    int64_t BitCount(absl::string_view in) {
      return 0;
    }
  }
}
#endif

#include "go-zetasql/public/functions/util/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/bits/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-absl/base/base/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
