#ifndef ABSL_HASH_HASH_EXPORT_H
#define ABSL_HASH_HASH_EXPORT_H

#include "absl/hash/internal/hash.h"

#include "absl/hash/internal/hash.cc"

#if 0
namespace absl {
  namespace hash_internal {

    uint64_t MixingHashState::CombineLargeContiguousImpl32(uint64_t state, const unsigned char* first, size_t len) {
      return 0;
    }

    uint64_t MixingHashState::CombineLargeContiguousImpl64(uint64_t state, const unsigned char* first, size_t len) {
      return 0;
    }

    const void* const MixingHashState::kSeed = nullptr;
    uint64_t MixingHashState::LowLevelHashImpl(const unsigned char* data, size_t len) {
      return 0;
    }
  }
}
#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/endian/export.inc"
#include "go-absl/container/fixed_array/export.inc"
#include "go-absl/functional/function_ref/export.inc"
#include "go-absl/hash/city/export.inc"
#include "go-absl/hash/low_level_hash/export.inc"
#include "go-absl/meta/type_traits/export.inc"
#include "go-absl/numeric/int128/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/optional/export.inc"
#include "go-absl/types/variant/export.inc"
#include "go-absl/utility/utility/export.inc"

#endif
