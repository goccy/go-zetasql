#ifndef ABSL_RANDOM_INTERNAL_RANDEN_HWAES_IMPL_EXPORT_H
#define ABSL_RANDOM_INTERNAL_RANDEN_HWAES_IMPL_EXPORT_H

#include "absl/random/internal/randen_hwaes.h"

namespace absl {
  namespace random_internal {

    bool HasRandenHwAesImplementation() { return false; }
    const void* RandenHwAes::GetKeys() {
      return nullptr;
    }

    void RandenHwAes::Absorb(const void*, void*) {
    }

    void RandenHwAes::Generate(const void*, void*) {
    }

  }
}

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/numeric/int128/export.inc"
#include "go-absl/random/internal/platform/export.inc"

#endif
