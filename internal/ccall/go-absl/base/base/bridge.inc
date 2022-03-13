#if 0
void GO_EXPORT(CycleClock_Now)(int64_t *ret) {
  *ret = absl::base_internal::CycleClock::Now();
}

void GO_EXPORT(CycleClock_Frequency)(double *ret) {
  *ret = absl::base_internal::CycleClock::Frequency();
}

void GO_EXPORT(RegisterSpinLockProfiler)(GO_EXPORT(SpinLockProfiler) profiler) {
  void (*fn)(const void *contendedlock, int64_t wait_cycles) = (void (*)(const void *contendedlock, int64_t wait_cycles))profiler.ptr;
  absl::base_internal::RegisterSpinLockProfiler(fn);
}

void GO_EXPORT(SpinLock_SpinLock)(GO_EXPORT(SchedulingMode) mode, GO_EXPORT(SpinLock) *ret) {
  ret->ptr = (void *)(new absl::base_internal::SpinLock(*(absl::base_internal::SchedulingMode *)(mode.ptr)));
}

void GO_EXPORT(SpinLock_SlowLock)(GO_EXPORT(SpinLock) arg0) {
}

void GO_EXPORT(SpinLock_SlowUnlock)(GO_EXPORT(SpinLock) arg0, uint32_t lock_value) {
}

void GO_EXPORT(NominalCPUFrequency)(double *ret) {
  *ret = absl::base_internal::NominalCPUFrequency();
}

void GO_EXPORT(NumCPUs)(int *ret) {
  *ret = absl::base_internal::NumCPUs();
}

void GO_EXPORT(SetCurrentThreadIdentity)(GO_EXPORT(ThreadIdentity) identity, GO_EXPORT(ThreadIdentityReclaimerFunction) reclaimer) {
  absl::base_internal::SetCurrentThreadIdentity(
     (absl::base_internal::ThreadIdentity *)(identity.ptr),
    *(absl::base_internal::ThreadIdentityReclaimerFunction *)(reclaimer.ptr)
  );
}

void GO_EXPORT(ClearCurrentThreadIdentity)() {
  absl::base_internal::ClearCurrentThreadIdentity();
}

void GO_EXPORT(CurrentThreadIdentityIfPresent)(GO_EXPORT(ThreadIdentity) *ret) {
  ret->ptr = absl::base_internal::CurrentThreadIdentityIfPresent();
}

void GO_EXPORT(UnscaledCycleClock_Now)(int64_t *ret) {
  *ret = absl::base_internal::UnscaledCycleClock::Now();
}

void GO_EXPORT(UnscaledCycleClock_Frequency)(double *ret) {
  *ret = absl::base_internal::UnscaledCycleClock::Frequency();
}
#endif
