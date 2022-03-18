#ifndef ABSL_RANDOM_INTERNAL_POOL_URBG_EXPORT_H
#define ABSL_RANDOM_INTERNAL_POOL_URBG_EXPORT_H

#include "absl/random/internal/pool_urbg.h"
#include "absl/random/internal/pool_urbg.cc"

#if 0
namespace absl {
  namespace random_internal {

    template <typename T>
    typename RandenPool<T>::result_type RandenPool<T>::Generate() {
      RandenPool<T>::result_type v;
      return v;
    }

    template <typename T>
    void RandenPool<T>::Fill(absl::Span<result_type> data) {
    }

    template class RandenPool<uint8_t>;
    template class RandenPool<uint16_t>;
    template class RandenPool<uint32_t>;
    template class RandenPool<uint64_t>;

  }
}
#endif

#include "go-absl/random/go_internal/randen/export.inc"
#include "go-absl/random/go_internal/seed_material/export.inc"
#include "go-absl/random/go_internal/traits/export.inc"
#include "go-absl/base/base/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/endian/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/random/seed_gen_exception/export.inc"
#include "go-absl/types/span/export.inc"

#endif
