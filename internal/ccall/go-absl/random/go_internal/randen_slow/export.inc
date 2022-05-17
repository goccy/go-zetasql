#ifndef ABSL_RANDOM_INTERNAL_RANDEN_SLOW_EXPORT_H
#define ABSL_RANDOM_INTERNAL_RANDEN_SLOW_EXPORT_H

#include "absl/random/internal/randen_slow.h"
#include "absl/random/internal/randen_slow.cc"

#if 0
namespace absl {
  namespace random_internal {

    const void* RandenSlow::GetKeys() {
      return nullptr;
    }

    void RandenSlow::Absorb(const void* seed_void, void* state_void) {
    }

    void RandenSlow::Generate(const void* keys_void, void* state_void) {
    }

  }
}
#endif

#include "go-absl/random/go_internal/platform/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/endian/export.inc"
#include "go-absl/numeric/int128/export.inc"

#endif
