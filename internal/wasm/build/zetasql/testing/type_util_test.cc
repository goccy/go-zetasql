//
// Copyright 2019 Google LLC
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

#include "zetasql/testing/type_util.h"

#include "zetasql/base/testing/status_matchers.h"
#include "zetasql/public/type.h"
#include "zetasql/testing/sql_types_test.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using zetasql::ZetaSQLTypesTest;
using zetasql::testing::HasFloatingPointNumber;
using zetasql::TypeFactory;
using zetasql::Type;

namespace {

TEST(HasFloatingPointNumber, NotFloatReturnsFalse) {
  EXPECT_FALSE(HasFloatingPointNumber(zetasql::types::BoolType()));
}

TEST(HasFloatingPointNumber, FloatTypeReturnsTrue) {
  EXPECT_TRUE(HasFloatingPointNumber(zetasql::types::FloatType()));
  EXPECT_TRUE(HasFloatingPointNumber(zetasql::types::DoubleType()));
}

TEST(HasFloatingPointNumber, StructWithFloatReturnsTrue) {
  TypeFactory type_factory;
  const Type* struct_type_with_float;
  ZETASQL_ASSERT_OK(type_factory.MakeStructType(
      {{"string_type", zetasql::types::StringType()},
       {"float_type", zetasql::types::FloatType()}},
      &struct_type_with_float));
  EXPECT_TRUE(HasFloatingPointNumber(struct_type_with_float));
}

TEST(HasFloatingPointNumber, NestedStructWithDoubleReturnsTrue) {
  TypeFactory type_factory;
  const Type* struct_type_with_double;
  const Type* nested_struct_type_with_double;
  ZETASQL_ASSERT_OK(type_factory.MakeStructType(
      {{"string_type", zetasql::types::StringType()},
       {"double_type", zetasql::types::DoubleType()}},
      &struct_type_with_double));
  ZETASQL_ASSERT_OK(type_factory.MakeStructType(
      {{"struct_with_double", struct_type_with_double},
       {"string_type", zetasql::types::StringType()}},
      &nested_struct_type_with_double));
  EXPECT_TRUE(HasFloatingPointNumber(nested_struct_type_with_double));
}

// This test shows that this function does not properly support proto type
// input. Currently this returns false even though the kitchen sink proto type
// has floats.
TEST_F(ZetaSQLTypesTest,
       DISABLED_HasFloatingPointNumber_ProtoWithFloatReturnsTrue) {
  EXPECT_TRUE(
      HasFloatingPointNumber(GetKitchenSinkNestedProtoType()));  // fails
}

TEST(HasFloatingPointNumber, ArrayWithFloatsReturnsTrue) {
  TypeFactory type_factory;
  const Type* array_type;
  ZETASQL_ASSERT_OK(
      type_factory.MakeArrayType(zetasql::types::FloatType(), &array_type));
  EXPECT_TRUE(HasFloatingPointNumber(array_type));
}

}  // namespace
