#ifndef ABSL_FLAGS_USAGE_INTERNAL_EXPORT_H
#define ABSL_FLAGS_USAGE_INTERNAL_EXPORT_H

#include "absl/flags/internal/usage.h"
#include "absl/flags/internal/usage.cc"

#if 0
namespace absl {
  namespace flags_internal {

    void FlagHelp(std::ostream& out, const CommandLineFlag& flag,
                  HelpFormat format) {
    }

    void FlagsHelp(std::ostream& out, absl::string_view filter, HelpFormat format,
                   absl::string_view program_usage_message) {
    }

    int HandleUsageFlags(std::ostream& out,
                         absl::string_view program_usage_message) {
      return 0;
    }

    std::string GetFlagsHelpMatchSubstr() {
      return "";
    }

    void SetFlagsHelpMatchSubstr(absl::string_view substr) {
    }

    HelpMode GetFlagsHelpMode() {
      HelpMode v;
      return v;
    }

    void SetFlagsHelpMode(HelpMode mode) {
    }

    HelpFormat GetFlagsHelpFormat() {
      HelpFormat v;
      return v;
    }

    void SetFlagsHelpFormat(HelpFormat format) {
    }

    bool DeduceUsageFlags(absl::string_view name, absl::string_view value) {
      return false;
    }
  }
}
#endif

#include "go-absl/flags/commandlineflag/export.inc"
#include "go-absl/flags/config/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/flags/flag_internal/export.inc"
#include "go-absl/flags/path_util/export.inc"
#include "go-absl/flags/private_handle_accessor/export.inc"
#include "go-absl/flags/program_name/export.inc"
#include "go-absl/flags/reflection/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
