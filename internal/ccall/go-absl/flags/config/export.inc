#ifndef ABSL_FLAGS_CONFIG_EXPORT_H
#define ABSL_FLAGS_CONFIG_EXPORT_H

#include "absl/flags/config.h"
#include "absl/flags/usage_config.h"

#include "absl/flags/usage_config.cc"

#if 0

namespace absl {
  namespace flags_internal {
    FlagsUsageConfig GetUsageConfig() {
      FlagsUsageConfig default_config;
      return default_config;
    }

    void ReportUsageError(absl::string_view msg, bool is_fatal) {
    }
  }

  void SetFlagsUsageConfig(FlagsUsageConfig usage_config) {
  }
}

#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/flags/path_util/export.inc"
#include "go-absl/flags/program_name/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"

#endif
