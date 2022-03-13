#ifndef ABSL_FLAGS_COMMANDLINEFLAG_INTERNAL_EXPORT_H
#define ABSL_FLAGS_COMMANDLINEFLAG_INTERNAL_EXPORT_H

#include "absl/flags/internal/commandlineflag.h"
#include "absl/flags/internal/commandlineflag.cc"

#if 0
namespace absl {
  namespace flags_internal {
    FlagStateInterface::~FlagStateInterface() {}
  }
}
#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/fast_type_id/export.inc"

#endif
