#ifndef ABSL_DEBUGGING_SYMBOLIZE_EXPORT_H
#define ABSL_DEBUGGING_SYMBOLIZE_EXPORT_H

#include "absl/debugging/internal/symbolize.h"
#include "absl/debugging/symbolize.h"

#include "absl/debugging/symbolize.cc"

#if 0
namespace absl {
  namespace debugging_internal {
    int InstallSymbolDecorator(SymbolDecorator, void*) { return -1; }
    bool RemoveSymbolDecorator(int) { return false; }
    bool RemoveAllSymbolDecorators(void) { return false; }
    bool RegisterFileMappingHint(const void *, const void *, uint64_t, const char *) {
      return false;
    }
    bool GetFileMappingHint(const void **, const void **, uint64_t *, const char **) {
      return false;
    }
  }
  void InitializeSymbolizer(const char*) {}
  bool Symbolize(const void *, char *, int) { return false; }
}
#endif

#include "go-absl/base/base/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/dynamic_annotations/export.inc"
#include "go-absl/base/malloc_internal/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/debugging/debugging_internal/export.inc"
#include "go-absl/debugging/demangle_internal/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
