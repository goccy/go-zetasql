#ifndef ZETASQL_SCRIPTING_ERROR_HELPERS_EXPORT_H
#define ZETASQL_SCRIPTING_ERROR_HELPERS_EXPORT_H

#include "zetasql/scripting/error_helpers.h"
#include "zetasql/scripting/error_helpers.cc"

#if 0
namespace zetasql {

  absl::StatusOr<ErrorLocation> ConvertLocalErrorToScriptError(const ScriptSegment& segment, const ErrorLocation& error_location_in) {
    ErrorLocation v;
    return v;
  }

  std::function<zetasql_base::StatusBuilder(zetasql_base::StatusBuilder)>
  ConvertLocalErrorToScriptError(const ScriptSegment& segment) {
    std::function<zetasql_base::StatusBuilder(zetasql_base::StatusBuilder)> v;
    return v;
  }

}
#endif

#include "go-zetasql/scripting/script_exception_cc_proto/export.inc"
#include "go-zetasql/scripting/script_segment/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/status_payload_utils/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/error_location_cc_proto/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
