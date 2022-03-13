#ifndef ABSL_BASE_BASE_EXPORT_H
#define ABSL_BASE_BASE_EXPORT_H

#include "absl/base/call_once.h"
#include "absl/base/casts.h"
#include "absl/base/internal/cycleclock.h"
#include "absl/base/internal/low_level_scheduling.h"
#include "absl/base/internal/per_thread_tls.h"
#include "absl/base/internal/spinlock.h"
#include "absl/base/internal/sysinfo.h"
#include "absl/base/internal/thread_identity.h"
#include "absl/base/internal/tsan_mutex_interface.h"
#include "absl/base/internal/unscaledcycleclock.h"

#include "absl/base/internal/cycleclock.cc"
#include "absl/base/internal/spinlock.cc"
#include "absl/base/internal/sysinfo.cc"
#include "absl/base/internal/thread_identity.cc"
#include "absl/base/internal/unscaledcycleclock.cc"

#if 0
#include "_cgo_export.h"

namespace absl {
  namespace base_internal {

    int64_t CycleClock::Now() {
      int64_t ret;
      GO_EXPORT(CycleClock_Now)(&ret);
      return ret;
    }

    double CycleClock::Frequency() {
      double ret;
      GO_EXPORT(CycleClock_Frequency)(&ret);
      return ret;
    }

    void RegisterSpinLockProfiler(void (*fn)(const void *contendedlock, int64_t wait_cycles)) {
      GO_EXPORT(SpinLockProfiler) ret;
      ret.ptr = (void *)fn;
      GO_EXPORT(RegisterSpinLockProfiler)(ret);
    }

    SpinLock::SpinLock(base_internal::SchedulingMode mode) : lockword_(0) {
      GO_EXPORT(SchedulingMode) arg0;
      arg0.ptr = &mode;
      GO_EXPORT(SpinLock) ret;
      GO_EXPORT(SpinLock_SpinLock)(arg0, &ret);
      memcpy(this, ret.ptr, sizeof(SpinLock));
      free(ret.ptr);
    }

    void SpinLock::SlowLock() {
      GO_EXPORT(SpinLock) arg0;
      arg0.ptr = this;
      GO_EXPORT(SpinLock_SlowLock)(arg0);
    }

    void SpinLock::SlowUnlock(uint32_t lock_value) {
      GO_EXPORT(SpinLock) arg0;
      arg0.ptr = this;
      GO_EXPORT(SpinLock_SlowUnlock)(arg0, lock_value);
    }


    double NominalCPUFrequency() {
      double ret;
      GO_EXPORT(NominalCPUFrequency)(&ret);
      return ret;
    }

    int NumCPUs() {
      int ret;
      GO_EXPORT(NumCPUs)(&ret);
      return ret;
    }

    void SetCurrentThreadIdentity(ThreadIdentity* identity, ThreadIdentityReclaimerFunction reclaimer) {
      GO_EXPORT(ThreadIdentity) arg0;
      arg0.ptr = identity;
      GO_EXPORT(ThreadIdentityReclaimerFunction) arg1;
      arg1.ptr = &reclaimer;
      GO_EXPORT(SetCurrentThreadIdentity)(arg0, arg1);
    }

    void ClearCurrentThreadIdentity() {
      GO_EXPORT(ClearCurrentThreadIdentity)();
    }

    ThreadIdentity* CurrentThreadIdentityIfPresent() {
      GO_EXPORT(ThreadIdentity) ret;
      GO_EXPORT(CurrentThreadIdentityIfPresent)(&ret);
      return (ThreadIdentity *)ret.ptr;
    }

    int64_t UnscaledCycleClock::Now() {
      int64_t ret;
      GO_EXPORT(UnscaledCycleClock_Now)(&ret);
      return ret;
    }

    double UnscaledCycleClock::Frequency() {
      double ret;
      GO_EXPORT(UnscaledCycleClock_Frequency)(&ret);
      return ret;
    }
  }
}
#endif

#include "go-absl/base/atomic_hook/export.inc"
#include "go-absl/base/base_internal/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/dynamic_annotations/export.inc"
#include "go-absl/base/log_severity/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/base/spinlock_wait/export.inc"
#include "go-absl/meta/type_traits/export.inc"

#endif
