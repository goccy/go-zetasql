#ifndef ABSL_STATUS_STATUSOR_EXPORT_H
#define ABSL_STATUS_STATUSOR_EXPORT_H

#include "absl/status/statusor.h"
#include "absl/status/internal/statusor_internal.h"

#include "absl/status/statusor.cc"

#if 0
namespace absl {

  BadStatusOrAccess::BadStatusOrAccess(absl::Status status)
    : status_(std::move(status)) {}

  BadStatusOrAccess::BadStatusOrAccess(const BadStatusOrAccess& other)
    : status_(other.status_) {}

  BadStatusOrAccess& BadStatusOrAccess::operator=(
                                                  const BadStatusOrAccess& other) {
    return *this;
  }

  BadStatusOrAccess& BadStatusOrAccess::operator=(BadStatusOrAccess&& other) {
    return *this;
  }

  BadStatusOrAccess::BadStatusOrAccess(BadStatusOrAccess&& other)
    : status_(std::move(other.status_)) {}

  const char* BadStatusOrAccess::what() const noexcept {
    return nullptr;
  }

  const absl::Status& BadStatusOrAccess::status() const { return status_; }

  void BadStatusOrAccess::InitWhat() const {
  }

  namespace internal_statusor {

    void Helper::HandleInvalidStatusCtorArg(absl::Status* status) {
    }

    void Helper::Crash(const absl::Status& status) {
      throw std::runtime_error("error");
    }

    void ThrowBadStatusOrAccess(absl::Status status) {
      throw std::runtime_error("error");
    }

  }
}
#endif

#include "go-absl/base/base/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/meta/type_traits/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/variant/export.inc"
#include "go-absl/utility/utility/export.inc"

#endif
