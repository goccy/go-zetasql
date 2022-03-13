#ifndef ZETASQL_COMMON_ERRORS_EXPORT_H
#define ZETASQL_COMMON_ERRORS_EXPORT_H

#include "zetasql/common/errors.h"
#include "zetasql/common/errors.cc"

#if 0

namespace zetasql {

  absl::Status StatusWithInternalErrorLocation(const absl::Status& status, const ParseLocationPoint& error_location) {
    return absl::OkStatus();
  }

  ErrorSource MakeErrorSource(const absl::Status& status, const std::string& text,
                              ErrorMessageMode mode) {
    ErrorSource v;
    return v;
  }

  const absl::optional<::google::protobuf::RepeatedPtrField<ErrorSource>> GetErrorSources(const absl::Status& status) {
    absl::optional<::google::protobuf::RepeatedPtrField<ErrorSource>> v;
    return v;
  }

  std::string DeprecationWarningsToDebugString(const std::vector<FreestandingDeprecationWarning>& warnings) {
    return "";
  }

  absl::StatusOr<FreestandingDeprecationWarning> StatusToDeprecationWarning(const absl::Status& from_status, absl::string_view sql) {
    absl::StatusOr<FreestandingDeprecationWarning> v;
    return v;
  }

  absl::StatusOr<std::vector<FreestandingDeprecationWarning>>
  StatusesToDeprecationWarnings(const std::vector<absl::Status>& from_statuses,
                                absl::string_view sql) {
    absl::StatusOr<std::vector<FreestandingDeprecationWarning>> v;
    return v;
  }

  absl::Status ConvertInternalErrorLocationToExternal(absl::Status status,
                                                      absl::string_view query) {
    return absl::OkStatus();
  }

}

#endif

#include "go-zetasql/common/status_payload_utils/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/proto/internal_error_location_cc_proto/export.inc"
#include "go-zetasql/public/deprecation_warning_cc_proto/export.inc"
#include "go-zetasql/public/error_helpers/export.inc"
#include "go-zetasql/public/error_location_cc_proto/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/optional/export.inc"

#endif
