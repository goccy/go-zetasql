#ifndef ABSL_DEBUGGING_FAILURE_SIGNAL_HANDLER_EXPORT_H
#define ABSL_DEBUGGING_FAILURE_SIGNAL_HANDLER_EXPORT_H

#include "absl/debugging/failure_signal_handler.h"
#include "absl/debugging/failure_signal_handler.cc"

#if 0
namespace absl {
  void RaiseToDefaultHandler(int signo) {
  }
  void RaiseToPreviousHandler(int signo) {
  }

  namespace debugging_internal {

    const char* FailureSignalToString(int signo) {
      return "";
    }
  }

  bool SetupAlternateStackOnce() {
    return false;
  }
  int MaybeSetupAlternateStack() {
    return 0;
  }

  void WriteToStderr(const char* data) {
  }

  void WriteSignalMessage(int signo, int cpu,
                          void (*writerfn)(const char*)) {
  }

  void WriterFnWrapper(const char* data, void* arg) {
  }

  void WriteStackTrace(void* ucontext, bool symbolize_stacktrace,
                       void (*writerfn)(const char*, void*), void* writerfn_arg) {
  }

  void WriteFailureInfo(int signo, void* ucontext, int cpu,
                        void (*writerfn)(const char*)) {
  }

  void PortableSleepForSeconds(int seconds) {
  }

  void ImmediateAbortSignalHandler(int) {
  }

  using GetTidType = decltype(absl::base_internal::GetTID());
#ifndef ABSL_HAVE_SIGACTION
  void AbslFailureSignalHandler(int signo) {}
#else
  void AbslFailureSignalHandler(int signo, siginfo_t*, void* ucontext) {}
#endif
  void InstallFailureSignalHandler(const FailureSignalHandlerOptions& options) {
  }
}
#endif

#include "go-absl/debugging/examine_stack/export.inc"
#include "go-absl/debugging/stacktrace/export.inc"
#include "go-absl/base/base/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/errno_saver/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"

#endif
