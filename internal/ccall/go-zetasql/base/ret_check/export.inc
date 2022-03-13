#ifndef ZETASQL_BASE_RET_CHECK_EXPORT_H
#define ZETASQL_BASE_RET_CHECK_EXPORT_H

#include "zetasql/base/ret_check.h"

#include "zetasql/base/ret_check.cc"

#if 0
namespace zetasql_base {
  namespace internal_ret_check {

    StatusBuilder RetCheckFailSlowPath(SourceLocation location) {
      return StatusBuilder(absl::StatusCode::kAborted);
    }

    StatusBuilder RetCheckFailSlowPath(SourceLocation location,
                                       std::string* condition) {
      return StatusBuilder(absl::StatusCode::kAborted);
    }

    StatusBuilder RetCheckFailSlowPath(SourceLocation location,
                                       const char* condition) {
      return StatusBuilder(absl::StatusCode::kAborted);
    }

    StatusBuilder RetCheckFailSlowPath(SourceLocation location,
                                       const char* condition,
                                       const absl::Status& status) {
      return StatusBuilder(absl::StatusCode::kAborted);
    }

  }
}
#endif

#include "go-zetasql/base/logging/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-absl/status/status/export.inc"

#endif
