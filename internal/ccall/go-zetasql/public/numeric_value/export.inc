#ifndef ZETASQL_PUBLIC_NUMERIC_VALUE_EXPORT_H
#define ZETASQL_PUBLIC_NUMERIC_VALUE_EXPORT_H

#include "zetasql/public/numeric_value.h"

#define PowersAsc GO_EXPORT(PowersAscValue)
#include "zetasql/public/numeric_value.cc"
#undef PowersAsc

#if 0
namespace zetasql {

  absl::StatusOr<NumericValue> NumericValue::FromStringStrict(absl::string_view str) {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::FromString(absl::string_view str) {
    NumericValue v;
    return v;
  }

  size_t NumericValue::HashCode() const {
    return 0;
  }

  void NumericValue::AppendToString(std::string* output) const {
  }

  template <bool is_strict>
  absl::StatusOr<NumericValue> NumericValue::FromStringInternal(absl::string_view str) {
    NumericValue v;
    return v;
  }

  double NumericValue::ToDouble() const {
    return 0;
  }

  template <typename S, typename T>
  bool ScaleAndRoundAwayFromZero(S scale, double value, T* result) {
    return false;
  }

  absl::StatusOr<NumericValue> NumericValue::FromDouble(double value) {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::Multiply(NumericValue rh) const {
    NumericValue v;
    return v;
  }

  NumericValue NumericValue::Abs() const {
    NumericValue v;
    return v;
  }

  int NumericValue::Sign() const {
    return 0;
  }

  absl::StatusOr<NumericValue> NumericValue::Power(NumericValue exp) const {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::Exp() const {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::Ln() const {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::Log10() const {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::Log(NumericValue base) const {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::Sqrt() const {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::Round(int64_t digits) const {
    NumericValue v;
    return v;
  }

  NumericValue NumericValue::Trunc(int64_t digits) const {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::Ceiling() const {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::Floor() const {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::Divide(NumericValue rh) const {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::DivideToIntegralValue(NumericValue rh) const {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::Mod(NumericValue rh) const {
    NumericValue v;
    return v;
  }

  void NumericValue::SerializeAndAppendToProtoBytes(std::string* bytes) const {
  }

  absl::StatusOr<NumericValue> NumericValue::DeserializeFromProtoBytes(absl::string_view bytes) {
    NumericValue v;
    return v;
  }

  void NumericValue::FormatAndAppend(FormatSpec spec, std::string* output) const {
  }

  std::ostream& operator<<(std::ostream& out, NumericValue value) {
    return out;
  }

  absl::StatusOr<NumericValue> NumericValue::Rescale(int scale, bool allow_rounding) const {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::FromScaledLittleEndianValue(absl::string_view little_endian_value, int scale, bool allow_rounding) {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::SumAggregator::GetSum() const {
    NumericValue v;
    return v;
  }

  absl::StatusOr<NumericValue> NumericValue::SumAggregator::GetAverage(uint64_t count) const {
    NumericValue v;
    return v;
  }

  void NumericValue::SumAggregator::SerializeAndAppendToProtoBytes(std::string* bytes) const {
  }

  absl::StatusOr<NumericValue::SumAggregator> NumericValue::SumAggregator::DeserializeFromProtoBytes(absl::string_view bytes) {
    NumericValue::SumAggregator v;
    return v;
  }

  void NumericValue::VarianceAggregator::Subtract(NumericValue value) {
  }

  absl::optional<double> NumericValue::VarianceAggregator::GetVariance(uint64_t count, bool is_sampling) const {
    return absl::nullopt;
  }

  absl::optional<double> NumericValue::VarianceAggregator::GetStdDev(uint64_t count, bool is_sampling) const {
    return absl::nullopt;
  }

  void NumericValue::VarianceAggregator::MergeWith(const VarianceAggregator& other) {
  }

  void NumericValue::VarianceAggregator::SerializeAndAppendToProtoBytes(std::string* bytes) const {
  }

  absl::StatusOr<NumericValue::VarianceAggregator> NumericValue::VarianceAggregator::DeserializeFromProtoBytes(absl::string_view bytes) {
    absl::StatusOr<NumericValue::VarianceAggregator> v;
    return v;
  }

  void NumericValue::CovarianceAggregator::Add(NumericValue x, NumericValue y) {
  }

  void NumericValue::CovarianceAggregator::Subtract(NumericValue x, NumericValue y) {
  }

  absl::optional<double> NumericValue::CovarianceAggregator::GetCovariance(uint64_t count, bool is_sampling) const {
    return absl::nullopt;
  }

  void NumericValue::CovarianceAggregator::MergeWith(const CovarianceAggregator& other) {
  }

  void NumericValue::CovarianceAggregator::SerializeAndAppendToProtoBytes(std::string* bytes) const {
  }

  absl::StatusOr<NumericValue::CovarianceAggregator> NumericValue::CovarianceAggregator::DeserializeFromProtoBytes(absl::string_view bytes) {
    NumericValue::CovarianceAggregator v;
    return v;
  }

  void NumericValue::CorrelationAggregator::Add(NumericValue x, NumericValue y) {
  }

  void NumericValue::CorrelationAggregator::Subtract(NumericValue x, NumericValue y) {
  }

  absl::optional<double> NumericValue::CorrelationAggregator::GetCorrelation(uint64_t count) const {
    return absl::nullopt;
  }

  void NumericValue::CorrelationAggregator::MergeWith(const CorrelationAggregator& other) {
  }

  void NumericValue::CorrelationAggregator::SerializeAndAppendToProtoBytes(std::string* bytes) const {
  }

  absl::StatusOr<NumericValue::CorrelationAggregator> NumericValue::CorrelationAggregator::DeserializeFromProtoBytes(absl::string_view bytes) {
    NumericValue::CorrelationAggregator v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::Multiply(const BigNumericValue& rh) const {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::Divide(const BigNumericValue& rh) const {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::DivideToIntegralValue(const BigNumericValue& rh) const {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::Mod(const BigNumericValue& rh) const {
    BigNumericValue v;
    return v;
  }

  bool BigNumericValue::HasFractionalPart() const {
    return false;
  }

  double BigNumericValue::RemoveScaleAndConvertToDouble(const FixedInt<64, 4>& value) {
    return 0;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::Round(int64_t digits) const {
    BigNumericValue v;
    return v;
  }

  BigNumericValue BigNumericValue::Trunc(int64_t digits) const {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::Floor() const {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::Ceiling() const {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::Power(const BigNumericValue& exp) const {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::Exp() const {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::Ln() const {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::Log10() const {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::Log(const BigNumericValue& base) const {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::Sqrt() const {
    BigNumericValue v;
    return v;
  }

  template <bool is_strict>
  absl::StatusOr<BigNumericValue> BigNumericValue::FromStringInternal(absl::string_view str) {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::FromStringStrict(absl::string_view str) {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::FromString(absl::string_view str) {
    BigNumericValue v;
    return v;
  }

  size_t BigNumericValue::HashCode() const {
    return 0;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::FromDouble(double value) {
    BigNumericValue v;
    return v;
  }

  void BigNumericValue::AppendToString(std::string* output) const {
  }

  void BigNumericValue::SerializeAndAppendToProtoBytes(std::string* bytes) const {
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::DeserializeFromProtoBytes(absl::string_view bytes) {
    BigNumericValue v;
    return v;
  }

  void BigNumericValue::FormatAndAppend(FormatSpec spec, std::string* output) const {
  }

  std::ostream& operator<<(std::ostream& out, const BigNumericValue& value) {
    return out;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::FromScaledLittleEndianValue(absl::string_view little_endian_value, int scale, bool allow_rounding) {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::Rescale(int scale, bool allow_rounding) const {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::SumAggregator::GetSum() const {
    BigNumericValue v;
    return v;
  }

  absl::StatusOr<BigNumericValue> BigNumericValue::SumAggregator::GetAverage(uint64_t count) const {
    BigNumericValue v;
    return v;
  }

  void BigNumericValue::SumAggregator::SerializeAndAppendToProtoBytes(std::string* bytes) const {
  }

  absl::StatusOr<BigNumericValue::SumAggregator> BigNumericValue::SumAggregator::DeserializeFromProtoBytes(absl::string_view bytes) {
    BigNumericValue::SumAggregator v;
    return v;
  }

  void BigNumericValue::VarianceAggregator::Add(BigNumericValue value) {
  }

  void BigNumericValue::VarianceAggregator::Subtract(BigNumericValue value) {
  }

  absl::optional<double> BigNumericValue::VarianceAggregator::GetVariance(uint64_t count, bool is_sampling) const {
    return absl::nullopt;
  }

  absl::optional<double> BigNumericValue::VarianceAggregator::GetStdDev(uint64_t count, bool is_sampling) const {
    return absl::nullopt;
  }

  void BigNumericValue::VarianceAggregator::MergeWith(const VarianceAggregator& other) {
  }

  void BigNumericValue::VarianceAggregator::SerializeAndAppendToProtoBytes(std::string* bytes) const {
  }

  absl::StatusOr<BigNumericValue::VarianceAggregator> BigNumericValue::VarianceAggregator::DeserializeFromProtoBytes(absl::string_view bytes) {
    BigNumericValue::VarianceAggregator v;
    return v;
  }

  void BigNumericValue::CovarianceAggregator::Add(BigNumericValue x, BigNumericValue y) {
  }

  void BigNumericValue::CovarianceAggregator::Subtract(BigNumericValue x, BigNumericValue y) {
  }

  absl::optional<double> BigNumericValue::CovarianceAggregator::GetCovariance(uint64_t count, bool is_sampling) const {
    return absl::nullopt;
  }

  void BigNumericValue::CovarianceAggregator::MergeWith(const CovarianceAggregator& other) {
  }

  void BigNumericValue::CovarianceAggregator::SerializeAndAppendToProtoBytes(std::string* bytes) const {
  }

  absl::StatusOr<BigNumericValue::CovarianceAggregator> BigNumericValue::CovarianceAggregator::DeserializeFromProtoBytes(absl::string_view bytes) {
    BigNumericValue::CovarianceAggregator v;
    return v;
  }

  void BigNumericValue::CorrelationAggregator::Add(BigNumericValue x, BigNumericValue y) {
  }

  void BigNumericValue::CorrelationAggregator::Subtract(BigNumericValue x, BigNumericValue y) {
  }

  absl::optional<double> BigNumericValue::CorrelationAggregator::GetCorrelation(uint64_t count) const {
    return absl::nullopt;
  }

  void BigNumericValue::CorrelationAggregator::MergeWith(const CorrelationAggregator& other) {
  }

  void BigNumericValue::CorrelationAggregator::SerializeAndAppendToProtoBytes(std::string* bytes) const {
  }

  absl::StatusOr<BigNumericValue::CorrelationAggregator> BigNumericValue::CorrelationAggregator::DeserializeFromProtoBytes(absl::string_view bytes) {
    BigNumericValue::CorrelationAggregator v;
    return v;
  }

  std::ostream& operator<<(std::ostream& out, const VarNumericValue& value) {
    return out;
  }

  VarNumericValue VarNumericValue::FromScaledLittleEndianValue(absl::string_view little_endian_value, uint scale) {
    VarNumericValue v;
    return v;
  }

  void VarNumericValue::AppendToString(std::string* output) const {
  }

}
#endif

#include "go-zetasql/public/numeric_constants/export.inc"
#include "go-zetasql/public/numeric_parser/export.inc"

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/endian/export.inc"
#include "go-zetasql/base/mathutil/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/stl_util/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/multiprecision_int/export.inc"

#include "go-absl/base/core_headers/export.inc"
#include "go-absl/hash/hash/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/optional/export.inc"

#endif
