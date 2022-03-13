#ifndef ABSL_HASH_LOW_LEVEL_HASH_EXPORT_H
#define ABSL_HASH_LOW_LEVEL_HASH_EXPORT_H

#include "absl/hash/internal/low_level_hash.h"

#include "absl/hash/internal/low_level_hash.cc"

#if 0
namespace absl {
  namespace hash_internal {

    uint64_t Mix(uint64_t v0, uint64_t v1) {
      return 0;
    }

    uint64_t LowLevelHash(const void* data, size_t len, uint64_t seed,
                          const uint64_t salt[]) {
      return 0;
    }
  }
}
#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/endian/export.inc"
#include "go-absl/numeric/bits/export.inc"
#include "go-absl/numeric/int128/export.inc"

#endif
