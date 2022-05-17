#ifndef ABSL_BASE_STRERROR_EXPORT_H
#define ABSL_BASE_STRERROR_EXPORT_H

#include "absl/base/internal/strerror.h"
#include "absl/base/internal/strerror.cc"

#if 0
namespace absl {
  namespace base_internal {
    std::string StrError(int errnum) {
      return "";
    }
  }
}
#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/errno_saver/export.inc"

#endif
