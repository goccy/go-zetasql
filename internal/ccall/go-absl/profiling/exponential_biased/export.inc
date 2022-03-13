#ifndef ABSL_PROFILING_EXPONENTIAL_BIASED_EXPORT_H
#define ABSL_PROFILING_EXPONENTIAL_BIASED_EXPORT_H

#include "absl/profiling/internal/exponential_biased.h"

#include "absl/profiling/internal/exponential_biased.cc"

#if 0
namespace absl {
  namespace profiling_internal {

    int64_t ExponentialBiased::GetSkipCount(int64_t mean) {
      return 0;
    }

    int64_t ExponentialBiased::GetStride(int64_t mean) {
      return 0;
    }

    void ExponentialBiased::Initialize() {
    }
  }
}
#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"

#endif
