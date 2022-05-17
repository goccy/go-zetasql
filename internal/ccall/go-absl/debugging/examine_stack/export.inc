#ifndef ABSL_DEBUGGING_EXAMINE_STACK_EXPORT_H
#define ABSL_DEBUGGING_EXAMINE_STACK_EXPORT_H

#include "absl/debugging/internal/examine_stack.h"
#include "absl/debugging/internal/examine_stack.cc"

#if 0
namespace absl {
  namespace debugging_internal {
    void* GetProgramCounter(void* vuc) {
      return nullptr;
    }

    void DumpPCAndFrameSizeAndSymbol(void (*writerfn)(const char*, void*),
                                     void* writerfn_arg, void* pc,
                                     void* symbolize_pc, int framesize,
                                     const char* const prefix) {
    }

    void DumpPCAndFrameSize(void (*writerfn)(const char*, void*),
                            void* writerfn_arg, void* pc, int framesize,
                            const char* const prefix) {
    }

    void DumpPCAndFrameSizesAndStackTrace(
                                          void* pc, void* const stack[], int frame_sizes[], int depth,
                                          int min_dropped_frames, bool symbolize_stacktrace,
                                          void (*writerfn)(const char*, void*), void* writerfn_arg) {
    }
  }
}
#endif

#include "go-absl/debugging/stacktrace/export.inc"
#include "go-absl/debugging/symbolize/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"

#endif
