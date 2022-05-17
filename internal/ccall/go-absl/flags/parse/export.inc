#ifndef ABSL_FLAGS_PARSE_EXPORT_H
#define ABSL_FLAGS_PARSE_EXPORT_H

#include "absl/flags/internal/parse.h"
#include "absl/flags/parse.h"

#include "absl/flags/parse.cc"

#if 0
namespace absl {
  namespace flags_internal {

    bool WasPresentOnCommandLine(absl::string_view flag_name) {
      return false;
    }
    std::vector<char*> ParseCommandLineImpl(int argc, char* argv[],
                                            ArgvListAction arg_list_act,
                                            UsageFlagsAction usage_flag_act,
                                            OnUndefinedFlag on_undef_flag) {
      std::vector<char*> v;
      return v;
    }
  }

  std::vector<char*> ParseCommandLine(int argc, char* argv[]) {
    std::vector<char*> v;
    return v;
  }
}
#endif

#include "go-absl/flags/commandlineflag/export.inc"
#include "go-absl/flags/commandlineflag_internal/export.inc"
#include "go-absl/flags/config/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/flags/flag_internal/export.inc"
#include "go-absl/flags/private_handle_accessor/export.inc"
#include "go-absl/flags/program_name/export.inc"
#include "go-absl/flags/reflection/export.inc"
#include "go-absl/flags/usage/export.inc"
#include "go-absl/flags/usage_internal/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"

#endif
