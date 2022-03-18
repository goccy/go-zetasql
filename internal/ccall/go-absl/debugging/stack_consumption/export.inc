#ifndef ABSL_DEBUGGING_STACK_CONSUMPTION_EXPORT_H
#define ABSL_DEBUGGING_STACK_CONSUMPTION_EXPORT_H

#include "absl/debugging/internal/stack_consumption.h"
#include "absl/debugging/internal/stack_consumption.cc"

#if 0
namespace absl {
  namespace debugging_internal {
    int GetSignalHandlerStackConsumption(void (*signal_handler)(int)) {
      return 0;
    }
  }
}
#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"

#endif
