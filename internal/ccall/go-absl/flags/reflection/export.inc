#ifndef ABSL_FLAGS_REFLECTION_EXPORT_H
#define ABSL_FLAGS_REFLECTION_EXPORT_H

#include "absl/flags/internal/registry.h"
#include "absl/flags/reflection.h"

#include "absl/flags/reflection.cc"

#if 0
namespace absl {
  namespace flags_internal {
    void ForEachFlag(std::function<void(CommandLineFlag&)> visitor) {
    }
    bool RegisterCommandLineFlag(CommandLineFlag& flag, const char* filename) {
      return false;
    }
    void FinalizeRegistry() {
    }

    void Retire(const char* name, FlagFastTypeId type_id, char* buf) {
    }
  }

  FlagSaver::~FlagSaver() {
  }

  CommandLineFlag* FindCommandLineFlag(absl::string_view name) {
    return nullptr;
  }

  absl::flat_hash_map<absl::string_view, absl::CommandLineFlag*> GetAllFlags() {
    absl::flat_hash_map<absl::string_view, absl::CommandLineFlag*> res;
    return res;
  }
}
#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/flags/commandlineflag/export.inc"
#include "go-absl/flags/commandlineflag_internal/export.inc"
#include "go-absl/flags/config/export.inc"
#include "go-absl/flags/private_handle_accessor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"

#endif
