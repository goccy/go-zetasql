#ifndef ABSL_STRINGS_CORDZ_HANDLE_EXPORT_H
#define ABSL_STRINGS_CORDZ_HANDLE_EXPORT_H

#include "absl/strings/internal/cordz_handle.h"

#include "absl/strings/internal/cordz_handle.cc"

#if 0

namespace absl {
  namespace cord_internal {

    using ::absl::base_internal::SpinLockHolder;

    CordzHandle::Queue CordzHandle::global_queue_(absl::kConstInit);

    CordzHandle::CordzHandle(bool is_snapshot) : is_snapshot_(is_snapshot) {
    }

    CordzHandle::~CordzHandle() {
    }

    bool CordzHandle::SafeToDelete() const {
      return false;
    }

    void CordzHandle::Delete(CordzHandle* handle) {
    }

    std::vector<const CordzHandle*> CordzHandle::DiagnosticsGetDeleteQueue() {
      std::vector<const CordzHandle*> v;
      return v;
    }

    bool CordzHandle::DiagnosticsHandleIsSafeToInspect(const CordzHandle* handle) const {
      return false;
    }

    std::vector<const CordzHandle*>
    CordzHandle::DiagnosticsGetSafeToInspectDeletedHandles() {
      std::vector<const CordzHandle*> v;
      return v;
    }

  }
}

#endif

#include "go-absl/base/base/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"

#endif
