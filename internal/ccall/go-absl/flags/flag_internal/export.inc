#ifndef ABSL_FLAGS_FLAG_INTERNAL_EXPORT_H
#define ABSL_FLAGS_FLAG_INTERNAL_EXPORT_H

#include "absl/flags/internal/flag.h"
#include "absl/flags/internal/sequence_lock.h"
#include "absl/flags/internal/flag.cc"

#if 0
namespace absl {
  namespace flags_internal {

    const char kStrippedFlagHelp[] = {};

    bool ShouldValidateFlagValue(FlagFastTypeId flag_type_id) {
      return false;
    }

    class FlagImpl;

    DynValueDeleter::DynValueDeleter(FlagOpFn op_arg) : op(op_arg) {}
    void DynValueDeleter::operator()(void* ptr) const {
    }

    void FlagImpl::Init() {
    }

    absl::Mutex* FlagImpl::DataGuard() const {
      return nullptr;
    }

    void FlagImpl::AssertValidType(FlagFastTypeId rhs_type_id,
                                   const std::type_info* (*gen_rtti)()) const {
    }

    std::unique_ptr<void, DynValueDeleter> FlagImpl::MakeInitValue() const {
      std::unique_ptr<void, DynValueDeleter> v;
      return v;
    }

    void FlagImpl::StoreValue(const void* src) {
    }

    absl::string_view FlagImpl::Name() const {
      absl::string_view v;
      return v;
    }

    std::string FlagImpl::Filename() const {
      return "";
    }

    std::string FlagImpl::Help() const {
      return "";
    }

    FlagFastTypeId FlagImpl::TypeId() const {
      FlagFastTypeId v;
      return v;
    }

    int64_t FlagImpl::ModificationCount() const {
      return 0;
    }

    bool FlagImpl::IsSpecifiedOnCommandLine() const {
      return false;
    }

    std::string FlagImpl::DefaultValue() const {
      return "";
    }

    std::string FlagImpl::CurrentValue() const {
      return "";
    }

    void FlagImpl::SetCallback(const FlagCallbackFunc mutation_callback) {
    }

    void FlagImpl::InvokeCallback() const {
    }

    std::unique_ptr<FlagStateInterface> FlagImpl::SaveState() {
      return nullptr;
    }

    bool FlagImpl::RestoreState(const FlagState& flag_state) {
      return false;
    }

    template <typename StorageT>
    StorageT* FlagImpl::OffsetValue() const {
      return nullptr;
    }

    void* FlagImpl::AlignedBufferValue() const {
      return nullptr;
    }

    std::atomic<uint64_t>* FlagImpl::AtomicBufferValue() const {
      return nullptr;
    }

    std::atomic<int64_t>& FlagImpl::OneWordValue() const {
      std::atomic<int64_t> *v;
      return *v;
    }

    std::unique_ptr<void, DynValueDeleter> FlagImpl::TryParse(
                                                              absl::string_view value, std::string& err) const {
      return nullptr;
    }

    void FlagImpl::Read(void* dst) const {
    }

    int64_t FlagImpl::ReadOneWord() const {
      return 0;
    }

    bool FlagImpl::ReadOneBool() const {
      return false;
    }

    void FlagImpl::ReadSequenceLockedData(void* dst) const {
    }

    void FlagImpl::Write(const void* src) {
    }

    bool FlagImpl::ParseFrom(absl::string_view value, FlagSettingMode set_mode,
                             ValueSource source, std::string& err) {
      return false;
    }

    void FlagImpl::CheckDefaultValueParsingRoundtrip() const {
    }

    bool FlagImpl::ValidateInputValue(absl::string_view value) const {
      return false;
    }
  }
}
#endif

#include "go-absl/base/base/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/dynamic_annotations/export.inc"
#include "go-absl/flags/commandlineflag/export.inc"
#include "go-absl/flags/commandlineflag_internal/export.inc"
#include "go-absl/flags/config/export.inc"
#include "go-absl/flags/marshalling/export.inc"
#include "go-absl/flags/reflection/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/meta/type_traits/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"
#include "go-absl/utility/utility/export.inc"

#endif
