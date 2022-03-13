#ifndef ZETASQL_BASE_STRING_NUMBERS_EXPORT_H
#define ZETASQL_BASE_STRING_NUMBERS_EXPORT_H

#include "zetasql/base/string_numbers.h"

#include "zetasql/base/string_numbers.cc"

#if 0
namespace zetasql_base {

  std::string RoundTripDoubleToString(double d) {
    return "";
  }

  std::string RoundTripFloatToString(float value) {
    return "";
  }

  bool safe_strto32_base(absl::string_view text, int32_t* value, int base) {
    return false;
  }

  bool safe_strto64_base(absl::string_view text, int64_t* value, int base) {
    return false;
  }

  bool safe_strtou32_base(absl::string_view text, uint32_t* value, int base) {
    return false;
  }

  bool safe_strtou64_base(absl::string_view text, uint64_t* value, int base) {
    return false;
  }

}
#endif

#include "go-zetasql/base/logging/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
