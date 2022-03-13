#ifndef ZETASQL_COMMON_UTF_UTIL_EXPORT_H
#define ZETASQL_COMMON_UTF_UTIL_EXPORT_H

#include "zetasql/common/utf_util.h"
#include "zetasql/common/utf_util.cc"

#if 0
namespace zetasql {

  absl::string_view::size_type SpanWellFormedUTF8(absl::string_view s) {
    absl::string_view::size_type v;
    return v;
  }

  std::string CoerceToWellFormedUTF8(absl::string_view input) {
    return "";
  }

  std::string PrettyTruncateUTF8(absl::string_view input, int max_bytes) {
    return "";
  }

  bool CheckAndCastStrLength(absl::string_view str, int32_t* str_length32) {
    return false;
  }

  absl::optional<int32_t> ForwardN(absl::string_view str, int32_t str_length32,
                                   int64_t num_code_points) {
    absl::optional<int32_t> v;
    return v;
  }

  absl::StatusOr<int32_t> LengthUtf8(absl::string_view str) {
    absl::StatusOr<int32_t> v;
    return v;
  }

  absl::StatusOr<std::string> GetSummaryString(absl::string_view str,
                                               int max_code_points) {
    absl::StatusOr<std::string> v;
    return v;
  }
}
#endif

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/optional/export.inc"
#include "go-icu/icu/export.inc"

#endif
