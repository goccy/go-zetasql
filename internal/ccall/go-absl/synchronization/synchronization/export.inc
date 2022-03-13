#ifndef ABSL_SYNCHRONIZATION_SYNCHRONIZATION_EXPORT_H
#define ABSL_SYNCHRONIZATION_SYNCHRONIZATION_EXPORT_H

#include "absl/synchronization/barrier.h"
#include "absl/synchronization/blocking_counter.h"
#include "absl/synchronization/internal/create_thread_identity.h"
#include "absl/synchronization/internal/futex.h"
#include "absl/synchronization/internal/per_thread_sem.h"
#include "absl/synchronization/internal/waiter.h"
#include "absl/synchronization/mutex.h"
#include "absl/synchronization/notification.h"

#include "absl/synchronization/barrier.cc"
#include "absl/synchronization/blocking_counter.cc"
#include "absl/synchronization/internal/create_thread_identity.cc"
#include "absl/synchronization/internal/per_thread_sem.cc"
#include "absl/synchronization/internal/waiter.cc"
#include "absl/synchronization/mutex.cc"
#include "absl/synchronization/notification.cc"

#if 0

namespace absl {

  static bool IsZero(void *arg) {
    return false;
  }

  bool Barrier::Block() {
    return false;
  }

}

namespace absl {

  BlockingCounter::BlockingCounter(int initial_count)
    : count_(initial_count),
      num_waiting_(0),
      done_{initial_count == 0 ? true : false} {
  }

  bool BlockingCounter::DecrementCount() {
    return false;
  }

  void BlockingCounter::Wait() {
  }

}

namespace absl {

  namespace synchronization_internal {

    void ReclaimThreadIdentity(void* v) {
    }

    intptr_t RoundUp(intptr_t addr, intptr_t align) {
      return addr;
    }

    void ResetThreadIdentity(base_internal::ThreadIdentity* identity) {
    }

    base_internal::ThreadIdentity* NewThreadIdentity() {
      return nullptr;
    }

    base_internal::ThreadIdentity* CreateThreadIdentity() {
      return nullptr;
    }

  }
}

namespace absl {
  namespace synchronization_internal {

    void PerThreadSem::SetThreadBlockedCounter(std::atomic<int> *counter) {
    }

    std::atomic<int> *PerThreadSem::GetThreadBlockedCounter() {
      return 0;
    }

    void PerThreadSem::Init(base_internal::ThreadIdentity *identity) {
    }

    void PerThreadSem::Destroy(base_internal::ThreadIdentity *identity) {
    }

    void PerThreadSem::Tick(base_internal::ThreadIdentity *identity) {
    }

  }
}

extern "C" {

  void AbslInternalPerThreadSemPost(absl::base_internal::ThreadIdentity *identity) {
  }

}

namespace absl {

  namespace synchronization_internal {

    static void MaybeBecomeIdle() {
    }

#if ABSL_WAITER_MODE == ABSL_WAITER_MODE_FUTEX

    Waiter::Waiter() {
    }

    Waiter::~Waiter() = default;

    void Waiter::Post() {
    }

    void Waiter::Poke() {
    }

#elif ABSL_WAITER_MODE == ABSL_WAITER_MODE_CONDVAR

    Waiter::Waiter() {
    }

    Waiter::~Waiter() {
    }

    void Waiter::Post() {
    }

    void Waiter::Poke() {
    }

    void Waiter::InternalCondVarPoke() {
    }

#elif ABSL_WAITER_MODE == ABSL_WAITER_MODE_SEM

    Waiter::Waiter() {
    }

    Waiter::~Waiter() {
    }

    void Waiter::Post() {
    }

    void Waiter::Poke() {
    }

#elif ABSL_WAITER_MODE == ABSL_WAITER_MODE_WIN32

    Waiter::Waiter() {
    }

    Waiter::~Waiter() = default;

    void Waiter::Post() {

    }

    void Waiter::Poke() {
    }

    void Waiter::InternalCondVarPoke() {
    }

#else
#error Unknown ABSL_WAITER_MODE
#endif

  }
}


extern "C" {
  void AbslInternalMutexYield() {
  }
}

namespace absl {

  void RegisterMutexProfiler(void (*fn)(int64_t wait_cycles)) {
  }

  void RegisterMutexTracer(void (*fn)(const char *msg, const void *obj,
                                      int64_t wait_cycles)) {
  }

  void RegisterCondVarTracer(void (*fn)(const char *msg, const void *cv)) {
  }

  void RegisterSymbolizer(bool (*fn)(const void *pc, char *out, int out_size)) {
  }

  namespace synchronization_internal {

    int MutexDelay(int32_t c, int mode) {
      return 0;
    }
  }

  void AtomicSetBits(std::atomic<intptr_t>* pv, intptr_t bits,
                     intptr_t wait_until_clear) {
  }

  void AtomicClearBits(std::atomic<intptr_t>* pv, intptr_t bits,
                              intptr_t wait_until_clear) {
  }

  void ForgetSynchEvent(std::atomic<intptr_t> *addr, intptr_t bits,
                               intptr_t lockbit) {
  }

  void PostSynchEvent(void *obj, int ev) {
  }

  SynchLocksHeld *LocksHeldAlloc() {
    return nullptr;
  }

  SynchLocksHeld *Synch_GetAllLocks() {
    return nullptr;
  }

  void Mutex::InternalAttemptToUseMutexInFatalSignalHandler() {
  }

  absl::Time DeadlineFromTimeout(absl::Duration timeout) {
    absl::Time v;
    return v;
  }

  bool DebugOnlyIsExiting() {
    return false;
  }

  Mutex::~Mutex() {
  }

  void Mutex::EnableDebugLog(const char *name) {
  }

  void EnableMutexInvariantDebugging(bool enabled) {
  }

  void Mutex::EnableInvariantDebugging(void (*invariant)(void *),
                                       void *arg) {
  }

  void SetMutexDeadlockDetectionMode(OnDeadlockCycle mode) {
  }

  char *StackString(void **pcs, int n, char *buf, int maxlen,
                    bool symbolize) {
    return nullptr;
  }

  char *CurrentStackString(char *buf, int maxlen, bool symbolize) {
    return nullptr;
  }

  void Mutex::ForgetDeadlockInfo() {
  }

  void Mutex::AssertNotHeld() const {
  }

  bool TryAcquireWithSpinning(std::atomic<intptr_t>* mu) {
    return false;
  }

  void Mutex::Lock() {
  }

  void Mutex::ReaderLock() {
  }

  void Mutex::LockWhen(const Condition &cond) {
  }

  bool Mutex::LockWhenWithTimeout(const Condition &cond, absl::Duration timeout) {
    return false;
  }

  bool Mutex::LockWhenWithDeadline(const Condition &cond, absl::Time deadline) {
    return false;
  }

  void Mutex::ReaderLockWhen(const Condition &cond) {
  }

  bool Mutex::ReaderLockWhenWithTimeout(const Condition &cond,
                                        absl::Duration timeout) {
    return false;
  }

  bool Mutex::ReaderLockWhenWithDeadline(const Condition &cond,
                                         absl::Time deadline) {
    return false;
  }

  void Mutex::Await(const Condition &cond) {
  }

  bool Mutex::AwaitWithTimeout(const Condition &cond, absl::Duration timeout) {
    return false;
  }

  bool Mutex::AwaitWithDeadline(const Condition &cond, absl::Time deadline) {
    return false;
  }

  bool Mutex::TryLock() {
    return false;
  }

  bool Mutex::ReaderTryLock() {
    return false;
  }

  void Mutex::Unlock() {
  }

  bool ExactlyOneReader(intptr_t v) {
    return false;
  }

  void Mutex::ReaderUnlock() {
  }

  intptr_t ClearDesignatedWakerMask(int flag) {
    return 0;
  }

  intptr_t IgnoreWaitingWritersMask(int flag) {
    return 0;
  }

  void Mutex::LockSlow(MuHow how, const Condition *cond,
                       int flags) {
  }

  void CheckForMutexCorruption(intptr_t v, const char* label) {
  }

  void Mutex::Trans(MuHow how) {
  }

  void Mutex::AssertHeld() const {
  }

  void Mutex::AssertReaderHeld() const {
  }

  void CondVar::EnableDebugLog(const char *name) {
  }

  CondVar::~CondVar() {
  }


  bool CondVar::WaitWithTimeout(Mutex *mu, absl::Duration timeout) {
    return false;
  }

  bool CondVar::WaitWithDeadline(Mutex *mu, absl::Time deadline) {
    return false;
  }

  void CondVar::Wait(Mutex *mu) {
  }

  void CondVar::Signal() {
  }

  void CondVar::SignalAll () {
  }

  void ReleasableMutexLock::Release() {
  }

#ifdef ABSL_HAVE_THREAD_SANITIZER
  extern "C" void __tsan_read1(void *addr);
#else
#define __tsan_read1(addr)  // do nothing if TSan not enabled
#endif

  bool Dereference(void *arg) {
    return false;
  }

  Condition::Condition() {}
  const Condition Condition::kTrue;

  Condition::Condition(bool (*func)(void *), void *arg)
    : eval_(&CallVoidPtrFunction),
      function_(func),
      method_(nullptr),
      arg_(arg) {}

  bool Condition::CallVoidPtrFunction(const Condition *c) {
    return false;
  }

  Condition::Condition(const bool *cond)
    : eval_(CallVoidPtrFunction),
      function_(Dereference),
      method_(nullptr),
      // const_cast is safe since Dereference does not modify arg
      arg_(const_cast<bool *>(cond)) {}

  bool Condition::Eval() const {
    return false;
  }

  bool Condition::GuaranteedEqual(const Condition *a, const Condition *b) {
    return false;
  }

}

namespace absl {

  void Notification::Notify() {
  }

  Notification::~Notification() {
  }

  void Notification::WaitForNotification() const {
  }

  bool Notification::WaitForNotificationWithTimeout(absl::Duration timeout) const {
    return false;
  }

  bool Notification::WaitForNotificationWithDeadline(absl::Time deadline) const {
    return false;
  }

}

#endif

#include "go-absl/base/atomic_hook/export.inc"
#include "go-absl/base/base/export.inc"
#include "go-absl/base/base_internal/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/dynamic_annotations/export.inc"
#include "go-absl/base/malloc_internal/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/debugging/stacktrace/export.inc"
#include "go-absl/debugging/symbolize/export.inc"
#include "go-absl/synchronization/graphcycles_internal/export.inc"
#include "go-absl/synchronization/kernel_timeout_internal/export.inc"
#include "go-absl/time/time/export.inc"

#endif
