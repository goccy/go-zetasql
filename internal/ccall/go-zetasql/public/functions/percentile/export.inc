#ifndef ZETASQL_PUBLIC_FUNCTIONS_PERCENTILE_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_PERCENTILE_EXPORT_H

#include "zetasql/public/functions/percentile.h"
#include "zetasql/public/functions/percentile.cc"

#if 0
namespace zetasql {

  size_t PercentileHelper<double>::ComputePercentileIndex(size_t max_index, long double* left_weight, long double* right_weight) const {
    return 0;
  }

  absl::StatusOr<PercentileHelper<double>> PercentileHelper<double>::Create(double percentile) {
    PercentileHelper<double> v;
    return v;
  }

  size_t PercentileHelper<NumericValue>::ComputePercentileIndex(size_t max_index, NumericValue* left_weight, NumericValue* right_weight) const {
    return 0;
  }

  NumericValue PercentileHelper<NumericValue>::ComputeLinearInterpolation(NumericValue left_value, NumericValue left_weight, NumericValue right_value, NumericValue right_weight) {
    NumericValue v;
    return v;
  }

  absl::StatusOr<PercentileHelper<NumericValue>> PercentileHelper<NumericValue>::Create(NumericValue percentile) {
    PercentileHelper<NumericValue> v;
    return v;
  }

  size_t PercentileHelper<BigNumericValue>::ComputePercentileIndex(size_t max_index, BigNumericValue* left_weight, BigNumericValue* right_weight) const {
    return 0;
  }

  BigNumericValue PercentileHelper<BigNumericValue>::ComputeLinearInterpolation(const BigNumericValue& left_value, const BigNumericValue& left_weight, const BigNumericValue& right_value, const BigNumericValue& right_weight) {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<PercentileHelper<BigNumericValue>> PercentileHelper<BigNumericValue>::Create(BigNumericValue percentile) {
    PercentileHelper<BigNumericValue> v;
    return v;
  }

}
#endif

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/mathutil/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/multiprecision_int/export.inc"
#include "go-zetasql/public/numeric_value/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
