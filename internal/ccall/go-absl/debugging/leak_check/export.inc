#ifndef ABSL_DEBUGGING_LEAK_CHECK_EXPORT_H
#define ABSL_DEBUGGING_LEAK_CHECK_EXPORT_H

#include "absl/debugging/leak_check.h"
#include "absl/debugging/leak_check.cc"

#if 0
namespace absl {
  bool HaveLeakSanitizer() { return false; }
  bool LeakCheckerIsActive() { return false; }
  void DoIgnoreLeak(const void*) { }
  void RegisterLivePointers(const void*, size_t) { }
  void UnRegisterLivePointers(const void*, size_t) { }
  LeakCheckDisabler::LeakCheckDisabler() { }
  LeakCheckDisabler::~LeakCheckDisabler() { }
#ifdef LEAK_SANITIZER
  bool FindAndReportLeaks() { return false; }
#endif
}
#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"

#endif
