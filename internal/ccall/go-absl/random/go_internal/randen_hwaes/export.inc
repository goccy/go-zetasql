#ifndef ABSL_RANDOM_INTERNAL_RANDEN_HWAES_EXPORT_H
#define ABSL_RANDOM_INTERNAL_RANDEN_HWAES_EXPORT_H

#include "absl/random/internal/randen_detect.h"
#include "absl/random/internal/randen_hwaes.h"
#include "absl/random/internal/randen_detect.cc"

#if 0
namespace absl {
  namespace random_internal {

    bool CPUSupportsRandenHwAes() {
      return false;
    }
  }
}
#endif

#include "go-absl/random/go_internal/platform/export.inc"
#include "go-absl/random/go_internal/randen_hwaes_impl/export.inc"
#include "go-absl/base/config/export.inc"

#endif
