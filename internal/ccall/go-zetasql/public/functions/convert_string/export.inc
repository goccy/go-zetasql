#ifndef ZETASQL_PUBLIC_FUNCTIONS_CONVERT_STRING_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_CONVERT_STRING_EXPORT_H

#include "zetasql/public/functions/convert_string.h"
#include "zetasql/public/functions/convert_string.cc"

#if 0
namespace zetasql {
  namespace functions {

    template <>
    bool NumericToString(bool value, std::string* out, absl::Status* error) {
      return false;
    }

    template <>
    bool NumericToString(int32_t value, std::string* out, absl::Status* error) {
      return false;
    }

    template <>
    bool NumericToString(int64_t value, std::string* out, absl::Status* error) {
      return false;
    }

    template <>
    bool NumericToString(uint32_t value, std::string* out, absl::Status* error) {
      return false;
    }

    template <>
    bool NumericToString(uint64_t value, std::string* out, absl::Status* error) {
      return false;
    }

    template <>
    bool NumericToString(float value, std::string* out, absl::Status* error) {
      return false;
    }

    template <>
    bool NumericToString(double value, std::string* out, absl::Status* error) {
      return false;
    }

    template <>
    bool NumericToString(NumericValue value, std::string* out, absl::Status* error) {
      return false;
    }

    template <>
    bool NumericToString(BigNumericValue value, std::string* out, absl::Status* error) {
      return false;
    }

    template <>
    bool StringToNumeric(absl::string_view value, bool* out, absl::Status* error) {
      return false;
    }

    template <>
    bool StringToNumeric(absl::string_view value, int32_t* out, absl::Status* error) {
      return false;
    }

    template <>
    bool StringToNumeric(absl::string_view value, int64_t* out, absl::Status* error) {
      return false;
    }

    template <>
    bool StringToNumeric(absl::string_view value, uint32_t* out, absl::Status* error) {
      return false;
    }

    template <>
    bool StringToNumeric(absl::string_view value, uint64_t* out, absl::Status* error) {
      return false;
    }

    template <>
    bool StringToNumeric(absl::string_view value, float* out, absl::Status* error) {
      return false;
    }

    template <>
    bool StringToNumeric(absl::string_view value, double* out, absl::Status* error) {
      return false;
    }

    template <>
    bool StringToNumeric(absl::string_view value, NumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool StringToNumeric(absl::string_view value, BigNumericValue* out, absl::Status* error) {
      return false;
    }

  }
}
#endif

#include "go-zetasql/public/functions/util/export.inc"
#include "go-zetasql/base/case/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/common/string_util/export.inc"
#include "go-zetasql/public/numeric_value/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
