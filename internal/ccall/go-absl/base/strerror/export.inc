#ifndef ABSL_BASE_STRERROR_EXPORT_H
#define ABSL_BASE_STRERROR_EXPORT_H

#include "absl/base/internal/strerror.h"

namespace absl {
  namespace base_internal {
    std::string StrError(int errnum) {
      return "";
    }
  }
}

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/errno_saver/export.inc"

#endif
