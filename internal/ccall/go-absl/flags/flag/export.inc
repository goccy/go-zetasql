#ifndef ABSL_FLAGS_FLAG_EXPORT_H
#define ABSL_FLAGS_FLAG_EXPORT_H

#include "absl/flags/declare.h"
#include "absl/flags/flag.h"

#include "absl/flags/flag.cc"

#if 0
namespace absl {
  namespace flags_internal {
    absl::Mutex *GetGlobalConstructionGuard() { return nullptr; }
  }
}
#endif

#include "go-absl/base/base/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/flags/config/export.inc"
#include "go-absl/flags/flag_internal/export.inc"
#include "go-absl/flags/reflection/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
