#ifndef ABSL_STRINGS_CORDZ_FUNCTIONS_EXPORT_H
#define ABSL_STRINGS_CORDZ_FUNCTIONS_EXPORT_H

#include "absl/strings/internal/cordz_functions.h"

#include "absl/strings/internal/cordz_functions.cc"

#if 0

namespace absl {
  namespace cord_internal {

#ifdef ABSL_INTERNAL_CORDZ_ENABLED

    thread_local int64_t cordz_next_sample;
    bool cordz_should_profile_slow() {
      return false;
    }

    void cordz_set_next_sample_for_testing(int64_t next_sample) {
    }

#endif  // ABSL_INTERNAL_CORDZ_ENABLED

    int32_t get_cordz_mean_interval() {
      return 0;
    }

    void set_cordz_mean_interval(int32_t mean_interval) {
    }
    
  }
}

#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/profiling/exponential_biased/export.inc"

#endif
