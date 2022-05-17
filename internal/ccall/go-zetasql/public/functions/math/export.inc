#ifndef ZETASQL_PUBLIC_FUNCTIONS_MATH_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_MATH_EXPORT_H

#include "zetasql/public/functions/math.h"
#include "zetasql/public/functions/math.cc"

#if 0
namespace zetasql {
  namespace functions {

    template <>
    bool RoundDecimal(double in, int64_t digits, double* out, absl::Status* error) {
      return false;
    }

    template <>
    bool RoundDecimal(float in, int64_t digits, float* out, absl::Status* error) {
      return false;
    }

    template <>
    bool TruncDecimal(double in, int64_t digits, double* out, absl::Status* error) {
      return false;
    }

    template <>
    bool TruncDecimal(float in, int64_t digits, float* out, absl::Status* error) {
      return false;
    }

    template <>
    bool Round(NumericValue in, NumericValue *out, absl::Status* error) {
      return false;
    }

    template <>
    bool RoundDecimal(NumericValue in, int64_t digits, NumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool Trunc(NumericValue in, NumericValue *out, absl::Status* error) {
      return false;
    }

    template <>
    bool TruncDecimal(NumericValue in, int64_t digits, NumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool Ceil(NumericValue in, NumericValue *out, absl::Status* error) {
      return false;
    }

    template <>
    bool Floor(NumericValue in, NumericValue *out, absl::Status* error) {
      return false;
    }

    template <>
    bool Sqrt(NumericValue in, NumericValue *out, absl::Status* error) {
      return false;
    }

    template <>
    bool Pow(NumericValue in1, NumericValue in2, NumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool Exp(NumericValue in, NumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool NaturalLogarithm(NumericValue in, NumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool DecimalLogarithm(NumericValue in, NumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool Logarithm(NumericValue in1, NumericValue in2, NumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool Ceil(BigNumericValue in, BigNumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool Floor(BigNumericValue in, BigNumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool Round(BigNumericValue in, BigNumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool RoundDecimal(BigNumericValue in, int64_t digits, BigNumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool Trunc(BigNumericValue in, BigNumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool TruncDecimal(BigNumericValue in, int64_t digits, BigNumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool Sqrt(BigNumericValue in, BigNumericValue *out, absl::Status* error) {
      return false;
    }

    template <>
    bool Pow(BigNumericValue in1, BigNumericValue in2, BigNumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool Exp(BigNumericValue in, BigNumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool NaturalLogarithm(BigNumericValue in, BigNumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool DecimalLogarithm(BigNumericValue in, BigNumericValue* out, absl::Status* error) {
      return false;
    }

    template <>
    bool Logarithm(BigNumericValue in1, BigNumericValue in2, BigNumericValue* out, absl::Status* error) {
      return false;
    }

  }
}
#endif

#include "go-zetasql/public/functions/arithmetics/export.inc"
#include "go-zetasql/public/functions/util/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/numeric_value/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
