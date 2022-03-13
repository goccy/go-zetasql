#ifndef ABSL_NUMERIC_INT128_EXPORT_H
#define ABSL_NUMERIC_INT128_EXPORT_H

#include "absl/numeric/int128.h"

#include "absl/numeric/int128.cc"

#if 0

namespace absl {
  const uint128 kuint128max(0);

  uint128::uint128(float v) : uint128(0) {}
  uint128::uint128(double v) : uint128(0) {}
  uint128::uint128(long double v) : uint128(0) {}

#if !defined(ABSL_HAVE_INTRINSIC_INT128)
  uint128 operator/(uint128 lhs, uint128 rhs) {
    uint128 v;
    return v;
  }

  uint128 operator%(uint128 lhs, uint128 rhs) {
    uint128 v;
    return v;
  }
#endif

  std::ostream& operator<<(std::ostream& os, uint128 v) {
    return os;
  }

#if !defined(ABSL_HAVE_INTRINSIC_INT128)

  int128::int128(float v) : int128(0) {}
  int128::int128(double v) : int128(0) {}
  int128::int128(long double v) : int128(0) {}

  int128 operator/(int128 lhs, int128 rhs) {
    int128 v;
    return v;
  }

  int128 operator%(int128 lhs, int128 rhs) {
    int128 v;
    return v;
  }
#endif

  std::ostream& operator<<(std::ostream& os, int128 v) {
    return os;
  }
}

#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/numeric/bits/export.inc"

#endif
