#ifndef ABSL_STATUS_STATUS_EXPORT_H
#define ABSL_STATUS_STATUS_EXPORT_H

#include "absl/status/status.h"
#include "absl/status/status_payload_printer.h"
#include "absl/status/internal/status_internal.h"

#include "absl/status/status.cc"
#include "absl/status/status_payload_printer.cc"

#if 0
namespace absl {

  std::string StatusCodeToString(StatusCode code) {
    return "";
  }

  std::ostream& operator<<(std::ostream& os, StatusCode code) {
    return os;
  }

  namespace status_internal {

    int FindPayloadIndexByUrl(const Payloads* payloads,
                              absl::string_view type_url) {
      return 0;
    }

    absl::StatusCode MapToLocalCode(int value) {
      absl::StatusCode v;
      return v;
    }
  }

  absl::optional<absl::Cord> Status::GetPayload(absl::string_view type_url) const {
    return absl::nullopt;
  }

  void Status::SetPayload(absl::string_view type_url, absl::Cord payload) {
  }

  bool Status::ErasePayload(absl::string_view type_url) {
    return false;
  }

  void Status::ForEachPayload(absl::FunctionRef<void(absl::string_view, const absl::Cord&)> visitor) const {
  }

  const std::string* Status::EmptyString() {
    return nullptr;
  }

  const std::string* Status::MovedFromString() {
    return nullptr;
  }

  void Status::UnrefNonInlined(uintptr_t rep) {
  }

  Status::Status(absl::StatusCode code, absl::string_view msg){
  }

  int Status::raw_code() const {
    return 0;
  }

  absl::StatusCode Status::code() const {
    absl::StatusCode v;
    return v;
  }

  void Status::PrepareToModify() {
  }

  bool Status::EqualsSlow(const absl::Status& a, const absl::Status& b) {
    return false;
  }

  std::string Status::ToStringSlow(StatusToStringMode mode) const {
    return "";
  }

  std::ostream& operator<<(std::ostream& os, const Status& x) {
    return os;
  }

  Status AbortedError(absl::string_view message) {
    Status v;
    return v;
  }

  Status AlreadyExistsError(absl::string_view message) {
    Status v;
    return v;
  }

  Status CancelledError(absl::string_view message) {
    Status v;
    return v;
  }

  Status DataLossError(absl::string_view message) {
    Status v;
    return v;
  }

  Status DeadlineExceededError(absl::string_view message) {
    Status v;
    return v;
  }

  Status FailedPreconditionError(absl::string_view message) {
    Status v;
    return v;
  }

  Status InternalError(absl::string_view message) {
    Status v;
    return v;
  }

  Status InvalidArgumentError(absl::string_view message) {
    Status v;
    return v;
  }

  Status NotFoundError(absl::string_view message) {
    Status v;
    return v;
  }

  Status OutOfRangeError(absl::string_view message) {
    Status v;
    return v;
  }

  Status PermissionDeniedError(absl::string_view message) {
    Status v;
    return v;
  }

  Status ResourceExhaustedError(absl::string_view message) {
    Status v;
    return v;
  }

  Status UnauthenticatedError(absl::string_view message) {
    Status v;
    return v;
  }

  Status UnavailableError(absl::string_view message) {
    Status v;
    return v;
  }

  Status UnimplementedError(absl::string_view message) {
    Status v;
    return v;
  }

  Status UnknownError(absl::string_view message) {
    Status v;
    return v;
  }

  bool IsAborted(const Status& status) {
    return false;
  }

  bool IsAlreadyExists(const Status& status) {
    return false;
  }

  bool IsCancelled(const Status& status) {
    return false;
  }

  bool IsDataLoss(const Status& status) {
    return false;
  }

  bool IsDeadlineExceeded(const Status& status) {
    return false;
  }

  bool IsFailedPrecondition(const Status& status) {
    return false;
  }

  bool IsInternal(const Status& status) {
    return false;
  }

  bool IsInvalidArgument(const Status& status) {
    return false;
  }

  bool IsNotFound(const Status& status) {
    return false;
  }

  bool IsOutOfRange(const Status& status) {
    return false;
  }

  bool IsPermissionDenied(const Status& status) {
    return false;
  }

  bool IsResourceExhausted(const Status& status) {
    return false;
  }

  bool IsUnauthenticated(const Status& status) {
    return false;
  }

  bool IsUnavailable(const Status& status) {
    return false;
  }

  bool IsUnimplemented(const Status& status) {
    return false;
  }

  bool IsUnknown(const Status& status) {
    return false;
  }
}

namespace absl {

  namespace status_internal {
    void SetStatusPayloadPrinter(StatusPayloadPrinter printer) {
    }

    StatusPayloadPrinter GetStatusPayloadPrinter() {
      StatusPayloadPrinter v;
      return v;
    }

  }
}

#endif

#include "go-absl/base/atomic_hook/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/container/inlined_vector/export.inc"
#include "go-absl/debugging/stacktrace/export.inc"
#include "go-absl/debugging/symbolize/export.inc"
#include "go-absl/functional/function_ref/export.inc"
#include "go-absl/strings/cord/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/optional/export.inc"

#endif
