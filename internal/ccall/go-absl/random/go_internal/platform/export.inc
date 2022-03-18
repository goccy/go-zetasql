#ifndef ABSL_RANDOM_INTERNAL_PLATFORM_EXPORT_H
#define ABSL_RANDOM_INTERNAL_PLATFORM_EXPORT_H

#include "absl/random/internal/randen_traits.h"
#include "absl/random/internal/randen_round_keys.cc"

#if 0
namespace absl {
  namespace random_internal {
    static constexpr size_t kKeyBytes = 2176;
    const unsigned char kRandenRoundKeysBE[kKeyBytes] = {};
    const unsigned char kRandenRoundKeys[kKeyBytes] = {};
  }
}
#endif

#include "go-absl/base/config/export.inc"

#endif
