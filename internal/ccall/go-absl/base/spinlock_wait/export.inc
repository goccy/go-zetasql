#ifndef ABSL_BASE_SPINLOCK_WAIT_EXPORT_H
#define ABSL_BASE_SPINLOCK_WAIT_EXPORT_H

#include "absl/base/internal/spinlock_wait.cc"

#if 0

#include "absl/base/internal/spinlock_wait.h"
#if defined(_WIN32)
#include "absl/base/internal/spinlock_win32.inc"
#elif defined(__linux__)
#include "absl/base/internal/spinlock_linux.inc"
#elif defined(__akaros__)
#include "absl/base/internal/spinlock_akaros.inc"
#else
#include "absl/base/internal/spinlock_posix.inc"
#endif

namespace absl {
  namespace base_internal {

    uint32_t SpinLockWait(std::atomic<uint32_t> *w, int n,
                          const SpinLockWaitTransition trans[],
                          base_internal::SchedulingMode scheduling_mode) {
      return 0;
    }

    int SpinLockSuggestedDelayNS(int loop) {
      return 0;
    }
  }
}

#endif

#include "go-absl/base/base_internal/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/errno_saver/export.inc"

#endif
