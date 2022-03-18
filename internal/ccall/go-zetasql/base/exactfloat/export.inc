#ifndef ZETASQL_BASE_EXACTFLOAT_EXPORT_H
#define ZETASQL_BASE_EXACTFLOAT_EXPORT_H

#include "zetasql/base/exactfloat.h"
#include "zetasql/base/exactfloat.cc"

#if 0
namespace zetasql_base {

  const int ExactFloat::kMinExp;
  const int ExactFloat::kMaxExp;
  const int ExactFloat::kMaxPrec;
  const int32_t ExactFloat::kExpNaN;
  const int32_t ExactFloat::kExpInfinity;
  const int32_t ExactFloat::kExpZero;
  const int ExactFloat::kDoubleMantissaBits;

  static int BN_ext_count_low_zero_bits(const BIGNUM* bn) {
    return 0;
  }

  ExactFloat::ExactFloat(double v) {
  }

  ExactFloat::ExactFloat(int v) {
  }

  ExactFloat::ExactFloat(const ExactFloat& b)
    : sign_(b.sign_),
      bn_exp_(b.bn_exp_) {
  }

  ExactFloat ExactFloat::SignedZero(int sign) {
    ExactFloat r;
    return r;
  }

  ExactFloat ExactFloat::Infinity(int sign) {
    ExactFloat r;
    return r;
  }

  ExactFloat ExactFloat::NaN() {
    ExactFloat r;
    return r;
  }

  int ExactFloat::prec() const {
    return 0;
  }

  int ExactFloat::exp() const {
    return 0;
  }

  void ExactFloat::set_zero(int sign) {
  }

  void ExactFloat::set_inf(int sign) {
  }

  void ExactFloat::set_nan() {
  }

  double ExactFloat::ToDouble() const {
    return 0;
  }

  double ExactFloat::ToDoubleHelper() const {
    return 0;
  }

  ExactFloat ExactFloat::RoundToMaxPrec(int max_prec, RoundingMode mode) const {
    ExactFloat r;
    return r;
  }

  ExactFloat ExactFloat::RoundToPowerOf2(int bit_exp, RoundingMode mode) const {
    ExactFloat r;
    return r;
  }

  int ExactFloat::NumSignificantDigitsForPrec(int prec) {
    return 0;
  }

  std::string ExactFloat::ToString() const {
    return "";
  }

  std::string ExactFloat::ToStringWithMaxDigits(int max_digits) const {
    return "";
  }

  static void IncrementDecimalDigits(std::string* digits) {
  }

  int ExactFloat::GetDecimalDigits(int max_digits, std::string* digits) const {
    return 0;
  }

  std::string ExactFloat::ToUniqueString() const {
    return "";
  }

  ExactFloat& ExactFloat::operator=(const ExactFloat& b) {
    return *this;
  }

  ExactFloat ExactFloat::operator-() const {
    ExactFloat r;
    return r;
  }

  ExactFloat operator+(const ExactFloat& a, const ExactFloat& b) {
    ExactFloat r;
    return r;
  }

  ExactFloat operator-(const ExactFloat& a, const ExactFloat& b) {
    ExactFloat r;
    return r;
  }

  ExactFloat ExactFloat::SignedSum(int a_sign, const ExactFloat* a,
                                   int b_sign, const ExactFloat* b) {
    ExactFloat r;
    return r;
  }

  void ExactFloat::Canonicalize() {
  }

  ExactFloat operator*(const ExactFloat& a, const ExactFloat& b) {
    ExactFloat r;
    return r;
  }

  bool operator==(const ExactFloat& a, const ExactFloat& b) {
    return false;
  }

  int ExactFloat::ScaleAndCompare(const ExactFloat& b) const {
    return 0;
  }

  bool ExactFloat::UnsignedLess(const ExactFloat& b) const {
    return false;
  }

  bool operator<(const ExactFloat& a, const ExactFloat& b) {
    return false;
  }

  ExactFloat fabs(const ExactFloat& a) {
    ExactFloat r;
    return r;
  }

  ExactFloat abs(const ExactFloat& a) {
    ExactFloat r;
    return r;
  }

  ExactFloat fmax(const ExactFloat& a, const ExactFloat& b) {
    ExactFloat r;
    return r;
  }

  ExactFloat fmin(const ExactFloat& a, const ExactFloat& b) {
    ExactFloat r;
    return r;
  }

  ExactFloat fdim(const ExactFloat& a, const ExactFloat& b) {
    ExactFloat r;
    return r;
  }

  ExactFloat ceil(const ExactFloat& a) {
    ExactFloat r;
    return r;
  }

  ExactFloat floor(const ExactFloat& a) {
    ExactFloat r;
    return r;
  }

  ExactFloat trunc(const ExactFloat& a) {
    ExactFloat r;
    return r;
  }

  ExactFloat round(const ExactFloat& a) {
    ExactFloat r;
    return r;
  }

  ExactFloat rint(const ExactFloat& a) {
    ExactFloat r;
    return r;
  }

  template <class T>
  T ExactFloat::ToInteger(RoundingMode mode) const {
    T v;
    return v;
  }

  long lrint(const ExactFloat& a) {
    return 0;
  }

  long long llrint(const ExactFloat& a) {
    return 0;
  }

  long lround(const ExactFloat& a) {
    return 0;
  }

  long long llround(const ExactFloat& a) {
    return 0;
  }

  ExactFloat copysign(const ExactFloat& a, const ExactFloat& b) {
    return 0;
  }

  ExactFloat frexp(const ExactFloat& a, int* exp) {
    ExactFloat r;
    return r;
  }

  ExactFloat ldexp(const ExactFloat& a, int exp) {
    ExactFloat r;
    return r;
  }

  ExactFloat scalbln(const ExactFloat& a, long exp) {
    ExactFloat r;
    return r;
  }

  int ilogb(const ExactFloat& a) {
    return 0;
  }

  ExactFloat logb(const ExactFloat& a) {
    ExactFloat r;
    return r;
  }

  ExactFloat ExactFloat::Unimplemented() {
    ExactFloat r;
    return r;
  }

}
#endif

#include "go-zetasql/base/base/export.inc"
#include "go-boringssl/boringssl/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/fixed_array/export.inc"

#endif
