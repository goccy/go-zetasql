#ifndef ABSL_FLAGS_PROGRAM_NAME_EXPORT_H
#define ABSL_FLAGS_PROGRAM_NAME_EXPORT_H

#include "absl/flags/internal/program_name.h"

#include "absl/flags/internal/program_name.cc"

#if 0
namespace absl {
  namespace flags_internal {

    std::string ProgramInvocationName() {
      return "";
    }

    std::string ShortProgramInvocationName() {
      return "";
    }

    void SetProgramInvocationName(absl::string_view prog_name_str) {
    }
  }
}
#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/flags/path_util/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"

#endif
