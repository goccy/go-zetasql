//
// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <math.h>

#include <limits>
#include <vector>

#include "zetasql/base/logging.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "absl/base/casts.h"
#include <cstdint>
#include "zetasql/base/exactfloat.h"

namespace zetasql_base {
namespace {

TEST(ExactFloatTest, Overflow) {
  // Construct an ExactFloat whose exponent is kMaxExp.
  const int kMaxExp = ExactFloat::kMaxExp;

  ExactFloat v = ldexp(ExactFloat(0.5), kMaxExp);
  EXPECT_FALSE(v.is_inf());
  EXPECT_EQ(kMaxExp, v.exp());

  // Now check that if the exponent is made larger, it overflows.
  EXPECT_TRUE((2 * v).is_inf());
  EXPECT_GT(2 * v, 0);
  EXPECT_TRUE((-2 * v).is_inf());
  EXPECT_LT(-2 * v, 0);

  // Check that overflowing the exponent a lot does not cause problems.
  EXPECT_TRUE((v * v).is_inf());
}

TEST(ExactFloatTest, OverflowMaxExpAndPrecision) {
  const int kMaxExp = ExactFloat::kMaxExp;
  const int kMaxPrec = ExactFloat::kMaxPrec;
  const int kMinExp = ExactFloat::kMinExp;

  // Now build an ExactFloat whose exponent and precision are both maximal (!)
  const ExactFloat v = ldexp(1.0 - ldexp(ExactFloat(1.0), -kMaxPrec), kMaxExp);
  EXPECT_FALSE(v.is_inf());
  EXPECT_EQ(ExactFloat::kMaxExp, v.exp());
  EXPECT_EQ(ExactFloat::kMaxPrec, v.prec());

  // Try overflowing it in various ways.
  EXPECT_TRUE((v + ldexp(ExactFloat(1.0), kMaxExp - kMaxPrec)).is_inf());
  EXPECT_TRUE((2 * v).is_inf());

  // Check that if kMaxPrec is exceeded, the result is NaN.  The first line
  // attempts to add one more bit to the mantissa, while the second line
  // attempts to add as many bits as possible (by adding together the largest
  // and smallest possible maximum-precision numbers).
  EXPECT_TRUE((v + ldexp(ExactFloat(1.0), kMaxExp - kMaxPrec - 1)).is_nan());
  EXPECT_TRUE(
      (v + ldexp(1.0 - ldexp(ExactFloat(1.0), -kMaxPrec), kMinExp)).is_nan());

  // Check that if kMaxExp and kMaxPrec are exceeded simultaneously, the
  // result is infinity rather than NaN.
  EXPECT_TRUE((v * v).is_inf());
}

TEST(ExactFloatTest, Underflow) {
  // Construct an ExactFloat whose exponent is kMinExp.
  const int kMinExp = ExactFloat::kMinExp;
  const ExactFloat v = ldexp(ExactFloat(0.5), kMinExp);
  EXPECT_FALSE(v.is_zero());
  EXPECT_EQ(kMinExp, v.exp());

  // Now check that if the exponent is made smaller, it underflows.
  EXPECT_TRUE((0.5 * v).is_zero());
  EXPECT_FALSE((0.5 * v).sign_bit());
  EXPECT_TRUE((-0.5 * v).is_zero());
  EXPECT_TRUE((-0.5 * v).sign_bit());

  // Check that underflowing the exponent a lot does not cause problems.
  EXPECT_TRUE((v * v).is_zero());
}

// Skip this test for iOS* because it times out constantly.
#ifndef __APPLE__
TEST(ExactFloatTest, UnderflowMaxExpAndMinPrecision) {
  const int kMinExp = ExactFloat::kMinExp;
  const int kMaxPrec = ExactFloat::kMaxPrec;

  // Now build an ExactFloat whose exponent is minimal and whose precision is
  // maximal.
  const ExactFloat v = ldexp(1.0 - ldexp(ExactFloat(1.0), -kMaxPrec), kMinExp);
  EXPECT_FALSE(v.is_zero());
  EXPECT_EQ(ExactFloat::kMinExp, v.exp());
  EXPECT_EQ(ExactFloat::kMaxPrec, v.prec());

  // Try underflowing it in various ways.
  ExactFloat underflow = 0.5 * v;
  EXPECT_TRUE(underflow.is_zero() && !underflow.sign_bit());
  underflow = -0.5 * v;
  EXPECT_TRUE(underflow.is_zero() && underflow.sign_bit());

  // Check that if kMaxPrec is exceeded, the result is NaN.
  EXPECT_TRUE((v + ldexp(ExactFloat(1.0), kMinExp + 1)).is_nan());

  // Check that if kMinExp and kMaxPrec are exceeded simultaneously, the
  // result is infinity rather than NaN.
  underflow = v * v;
  EXPECT_TRUE(underflow.is_zero() && !underflow.sign_bit());
  underflow = v * (-v);
  EXPECT_TRUE(underflow.is_zero() && underflow.sign_bit());
}
#endif

}  // namespace
}  // namespace zetasql_base
