#ifndef ABSL_DEBUGGING_LEAK_CHECK_DISABLE_EXPORT_H
#define ABSL_DEBUGGING_LEAK_CHECK_DISABLE_EXPORT_H

#include "absl/debugging/leak_check_disable.cc"

#if 0
extern "C" int __lsan_is_turned_off();
extern "C" int __lsan_is_turned_off() {
  return 1;
}
#endif

#include "go-absl/base/config/export.inc"

#endif
