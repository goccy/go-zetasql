#ifndef ABSL_FLAGS_COMMANDLINEFLAG_EXPORT_H
#define ABSL_FLAGS_COMMANDLINEFLAG_EXPORT_H

#include "absl/flags/commandlineflag.h"

#include "absl/flags/commandlineflag.cc"

#if 0

namespace absl {
  bool CommandLineFlag::IsRetired() const { return false; }
  bool CommandLineFlag::ParseFrom(absl::string_view value, std::string* error) {
    return false;
  }
}

#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/fast_type_id/export.inc"
#include "go-absl/flags/commandlineflag_internal/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/optional/export.inc"

#endif
