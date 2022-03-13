#ifndef ZETASQL_PUBLIC_ERROR_HELPERS_EXPORT_H
#define ZETASQL_PUBLIC_ERROR_HELPERS_EXPORT_H

#include "zetasql/public/error_helpers.h"
#include "zetasql/public/error_helpers.cc"

#if 0
namespace zetasql {

  std::string FormatErrorLocation(const ErrorLocation& location) {
    return "";
  }

  std::string FormatErrorLocation(const ErrorLocation& location,
                                  absl::string_view input_text,
                                  ErrorMessageMode mode) {
    return "";
  }

  std::string FormatErrorSource(const ErrorSource& error_source,
                                ErrorMessageMode mode) {
    return "";
  }

  std::string FormatError(const absl::Status& status) {
    return "";
  }

  bool HasErrorLocation(const absl::Status& status) {
    return false;
  }

  bool GetErrorLocation(const absl::Status& status, ErrorLocation* location) {
    return false;
  }

  void ClearErrorLocation(absl::Status* status) {
  }

  std::string GetErrorStringWithCaret(absl::string_view input,
                                      const ErrorLocation& location,
                                      int max_width_in) {
    return "";
  }

  absl::Status MaybeUpdateErrorFromPayload(ErrorMessageMode mode,
                                           absl::string_view input_text,
                                           const absl::Status& status) {
    absl::Status v;
    return v;
  }

  absl::Status UpdateErrorLocationPayloadWithFilenameIfNotPresent(const absl::Status& status, const std::string& filename) {
    absl::Status v;
    return v;
  }

}
#endif

#include "go-zetasql/public/error_location_cc_proto/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/status_payload_utils/export.inc"
#include "go-zetasql/common/utf_util/export.inc"
#include "go-zetasql/proto/internal_error_location_cc_proto/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/cord/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
