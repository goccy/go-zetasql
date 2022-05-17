#ifndef ABSL_RANDOM_INTERNAL_RANDEN_EXPORT_H
#define ABSL_RANDOM_INTERNAL_RANDEN_EXPORT_H

#include "absl/random/internal/randen.h"
#include "absl/random/internal/randen.cc"

#if 0
namespace absl {
  namespace random_internal {

    Randen::Randen() {
    }

  }
}
#endif

#include "go-absl/random/go_internal/platform/export.inc"
#include "go-absl/random/go_internal/randen_hwaes/export.inc"
#include "go-absl/random/go_internal/randen_slow/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"

#endif
