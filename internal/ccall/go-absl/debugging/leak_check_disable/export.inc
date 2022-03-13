#ifndef ABSL_DEBUGGING_LEAK_CHECK_DISABLE_EXPORT_H
#define ABSL_DEBUGGING_LEAK_CHECK_DISABLE_EXPORT_H

extern "C" int __lsan_is_turned_off();
extern "C" int __lsan_is_turned_off() {
  return 1;
}

#include "go-absl/base/config/export.inc"

#endif
