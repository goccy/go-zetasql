#ifndef ABSL_FLAGS_PRIVATE_HANDLE_ACCESSOR_EXPORT_H
#define ABSL_FLAGS_PRIVATE_HANDLE_ACCESSOR_EXPORT_H

#include "absl/flags/internal/private_handle_accessor.h"
#include "absl/flags/internal/private_handle_accessor.cc"

#if 0

namespace absl {
  namespace flags_internal {

    FlagFastTypeId PrivateHandleAccessor::TypeId(const CommandLineFlag& flag) {
      FlagFastTypeId v;
      return v;
    }

    std::unique_ptr<FlagStateInterface> PrivateHandleAccessor::SaveState(CommandLineFlag& flag) {
      std::unique_ptr<FlagStateInterface> v;
      return v;
    }

    bool PrivateHandleAccessor::IsSpecifiedOnCommandLine(const CommandLineFlag& flag) {
      return false;
    }

    bool PrivateHandleAccessor::ValidateInputValue(const CommandLineFlag& flag,
                                                   absl::string_view value) {
      return false;
    }

    void PrivateHandleAccessor::CheckDefaultValueParsingRoundtrip(const CommandLineFlag& flag) {
    }

    bool PrivateHandleAccessor::ParseFrom(CommandLineFlag& flag,
                                          absl::string_view value,
                                          flags_internal::FlagSettingMode set_mode,
                                          flags_internal::ValueSource source,
                                          std::string& error) {
      return false;
    }
  }
}

#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/flags/commandlineflag/export.inc"
#include "go-absl/flags/commandlineflag_internal/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
