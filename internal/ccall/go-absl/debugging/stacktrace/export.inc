#ifndef ABSL_DEBUGGING_STACKTRACE_EXPORT_H
#define ABSL_DEBUGGING_STACKTRACE_EXPORT_H

#include "absl/debugging/stacktrace.h"

#include "absl/debugging/internal/stacktrace_config.h"
#include "absl/debugging/stacktrace.cc"

#if 0
namespace absl {
  int GetStackFrames(void** result, int* sizes, int max_depth, int skip_count) {
    return 0;
  }

  int GetStackFramesWithContext(void** result, int* sizes, int max_depth,
                                int skip_count, const void* uc,
                                int* min_dropped_frames) {
    return 0;
  }

  int GetStackTrace(void** result, int max_depth, int skip_count) {
    return 0;
  }

  int GetStackTraceWithContext(void** result, int max_depth, int skip_count,
                               const void* uc, int* min_dropped_frames) {
    return 0;
  }

  int DefaultStackUnwinder(void** pcs, int* sizes, int depth, int skip,
                           const void* uc, int* min_dropped_frames) {
    return 0;
  }
}
#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/debugging/debugging_internal/export.inc"

#endif
