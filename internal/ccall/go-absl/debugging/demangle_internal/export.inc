#ifndef ABSL_DEBUGGING_DEMANGLE_INTERNAL_EXPORT_H
#define ABSL_DEBUGGING_DEMANGLE_INTERNAL_EXPORT_H

#include "absl/debugging/internal/demangle.h"

#include "absl/debugging/internal/demangle.cc"

#if 0

namespace absl {
  namespace debugging_internal {
    size_t StrLen(const char *str) {
      return 0;
    }
    bool AtLeastNumCharsRemaining(const char *str, int n) {
      return false;
    }
    bool StrPrefix(const char *str, const char *prefix) {
      return false;
    }
    bool Optional(bool /*status*/) { return true; }

    bool IsLower(char c) { return false; }

    bool IsAlpha(char c) {
      return false;
    }

    bool IsDigit(char c) { return false; }

    bool IsFunctionCloneSuffix(const char *str) {
      return false;
    }

    bool Demangle(const char *mangled, char *out, int out_size) {
      return false;
    }
  }
}

#endif

#include "go-absl/base/base/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"

#endif
