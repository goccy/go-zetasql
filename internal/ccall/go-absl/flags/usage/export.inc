#ifndef ABSL_FLAGS_USAGE_EXPORT_H
#define ABSL_FLAGS_USAGE_EXPORT_H

#include "absl/flags/usage.h"

namespace absl {

  void SetProgramUsageMessage(absl::string_view new_usage_message) {
  }

  absl::string_view ProgramUsageMessage() {
    absl::string_view v;
    return v;
  }
}

#include "go-absl/flags/usage_internal/export.inc"

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"

#endif
