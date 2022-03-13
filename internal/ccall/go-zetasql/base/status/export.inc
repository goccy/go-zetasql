#ifndef ZETASQL_BASE_STATUS_EXPORT_H
#define ZETASQL_BASE_STATUS_EXPORT_H

#include "zetasql/base/canonical_errors.h"
#include "zetasql/base/status.h"
#include "zetasql/base/status_builder.h"
#include "zetasql/base/status_macros.h"
#include "zetasql/base/status_payload.h"

#include "zetasql/base/status_builder.cc"
#include "zetasql/base/status_payload.cc"

#if 0
namespace zetasql_base {

  static void CopyStatusPayloads(const absl::Status& from, absl::Status* to) {
  }

  StatusBuilder& StatusBuilder::SetErrorCode(absl::StatusCode code) {
    return *this;
  }

  StatusBuilder::Rep::Rep(const Rep& r)
    : logging_mode(r.logging_mode),
      log_severity(r.log_severity),
      verbose_level(r.verbose_level),
      stream(),
      should_log_stack_trace(r.should_log_stack_trace),
      message_join_style(r.message_join_style) {
  }

  absl::Status StatusBuilder::JoinMessageToStatus(absl::Status s,
                                                  absl::string_view msg,
                                                  MessageJoinStyle style) {
    absl::Status v;
    return v;
  }

  void StatusBuilder::ConditionallyLog(const absl::Status& result) const {
  }

  absl::Status StatusBuilder::CreateStatusAndConditionallyLog() && {
    absl::Status v;
    return v;
  }

  StatusBuilder AbortedErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

  StatusBuilder AlreadyExistsErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

  StatusBuilder CancelledErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

  StatusBuilder DataLossErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

  StatusBuilder DeadlineExceededErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

  StatusBuilder FailedPreconditionErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

  StatusBuilder InternalErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

  StatusBuilder InvalidArgumentErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

  StatusBuilder NotFoundErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

  StatusBuilder OutOfRangeErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

  StatusBuilder PermissionDeniedErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

  StatusBuilder UnauthenticatedErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

  StatusBuilder ResourceExhaustedErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

  StatusBuilder UnavailableErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

  StatusBuilder UnimplementedErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

  StatusBuilder UnknownErrorBuilder(zetasql_base::SourceLocation location) {
    return StatusBuilder(absl::StatusCode::kAborted);
  }

}

namespace zetasql_base {

  const absl::string_view kZetaSqlTypeUrlPrefix =
    "type.googleapis.com/";

}

#endif


#include "go-zetasql/base/logging/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/log_severity/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/cord/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
