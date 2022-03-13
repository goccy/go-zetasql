#ifndef ABSL_BASE_RAW_LOGGING_INTERNAL_EXPORT_H
#define ABSL_BASE_RAW_LOGGING_INTERNAL_EXPORT_H

#include "absl/base/internal/raw_logging.h"

#include "absl/base/internal/raw_logging.cc"

#if 0

#include "_cgo_export.h"

namespace absl {
  namespace raw_logging_internal {

    void SafeWriteToStderr(const char *s, size_t len) {
      GO_EXPORT(SafeWriteToStderr)((char *)s, len);
    }

    void RawLog(absl::LogSeverity severity, const char* file, int line, const char* format, ...) {
    }

    bool RawLoggingFullySupported() {
      int ret;
      GO_EXPORT(RawLoggingFullySupported)(&ret);
      if (ret) {
        return true;
      }
      return false;
    }

    void defaultInternalLog(absl::LogSeverity severity, const char* file, int line, const std::string& message) {
    }

    absl::base_internal::AtomicHook<InternalLogFunction> internal_log_function(defaultInternalLog);

    void RegisterLogPrefixHook(LogPrefixHook func) {
      GO_EXPORT(LogPrefixHook) arg0;
      arg0.ptr = &func;
      GO_EXPORT(RegisterLogPrefixHook)(arg0);
    }

    void RegisterAbortHook(AbortHook func) {
      GO_EXPORT(AbortHook) arg0;
      arg0.ptr = &func;
      GO_EXPORT(RegisterAbortHook)(arg0);
    }

    void RegisterInternalLogFunction(InternalLogFunction func) {
      internal_log_function.Store(func);
    }
  }
}
#endif

#include "go-absl/base/atomic_hook/export.inc"
#include "go-absl/base/log_severity/export.inc"

#endif
