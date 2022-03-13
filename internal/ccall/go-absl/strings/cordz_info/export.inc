#ifndef ABSL_STRINGS_CORDZ_INFO_EXPORT_H
#define ABSL_STRINGS_CORDZ_INFO_EXPORT_H

#include "absl/strings/internal/cordz_info.h"

#include "absl/strings/internal/cordz_info.cc"

#if 0
namespace absl {
  namespace cord_internal {
    using ::absl::base_internal::SpinLockHolder;
    CordzInfo::List CordzInfo::global_list_{absl::kConstInit};
    
    CordzInfo* CordzInfo::Head(const CordzSnapshot& snapshot) {
      return nullptr;
    }

    CordzInfo* CordzInfo::Next(const CordzSnapshot& snapshot) const {
      return nullptr;
    }

    void CordzInfo::TrackCord(InlineData& cord, MethodIdentifier method) {
    }

    void CordzInfo::TrackCord(InlineData& cord, const InlineData& src,
                              MethodIdentifier method) {
    }

    void CordzInfo::MaybeTrackCordImpl(InlineData& cord, const InlineData& src,
                                       MethodIdentifier method) {
    }

    CordzInfo::MethodIdentifier CordzInfo::GetParentMethod(const CordzInfo* src) {
      CordzInfo::MethodIdentifier v;
      return v;
    }

    int CordzInfo::FillParentStack(const CordzInfo* src, void** stack) {
      return 0;
    }

    CordzInfo::CordzInfo(CordRep* rep, const CordzInfo* src,
                         MethodIdentifier method)
      : rep_(rep),
        stack_depth_(0),
        parent_stack_depth_(FillParentStack(src, parent_stack_)),
        method_(method),
        parent_method_(GetParentMethod(src)),
        create_time_(absl::Now()) {
    }

    CordzInfo::~CordzInfo() {
    }

    void CordzInfo::Track() {
    }

    void CordzInfo::Untrack() {
    }

    void CordzInfo::Lock(MethodIdentifier method) {
    }

    void CordzInfo::Unlock() ABSL_UNLOCK_FUNCTION(mutex_) {
    }

    absl::Span<void* const> CordzInfo::GetStack() const {
      absl::Span<void* const> v;
      return v;
    }

    absl::Span<void* const> CordzInfo::GetParentStack() const {
      absl::Span<void* const> v;
      return v;
    }

    CordzStatistics CordzInfo::GetCordzStatistics() const {
      CordzStatistics v;
      return v;
    }
  }
}

#endif

#include "go-absl/base/base/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/container/inlined_vector/export.inc"
#include "go-absl/debugging/stacktrace/export.inc"
#include "go-absl/strings/cord_internal/export.inc"
#include "go-absl/strings/cordz_functions/export.inc"
#include "go-absl/strings/cordz_handle/export.inc"
#include "go-absl/strings/cordz_statistics/export.inc"
#include "go-absl/strings/cordz_update_tracker/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"
#include "go-absl/types/span/export.inc"

#endif
