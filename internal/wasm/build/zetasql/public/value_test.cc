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

#include "zetasql/public/value.h"

#include <math.h>
#include <stdlib.h>
#include <time.h>

#include <cstdint>
#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "zetasql/base/logging.h"
#include "google/protobuf/wrappers.pb.h"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/io/zero_copy_stream_impl.h"
#include "google/protobuf/io/zero_copy_stream_impl_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/descriptor_database.h"
#include "google/protobuf/dynamic_message.h"
#include "google/protobuf/text_format.h"
#include "google/protobuf/wire_format_lite.h"
#include "zetasql/common/internal_value.h"
#include "zetasql/common/testing/testing_proto_util.h"
#include "zetasql/public/analyzer.h"
#include "zetasql/public/evaluator.h"
#include "zetasql/public/interval_value.h"
#include "zetasql/public/interval_value_test_util.h"
#include "zetasql/public/json_value.h"
#include "zetasql/public/language_options.h"
#include "zetasql/public/numeric_value.h"
#include "zetasql/public/options.pb.h"
#include "zetasql/public/simple_catalog.h"
#include "zetasql/public/type.h"
#include "zetasql/public/types/type_factory.h"
#include "zetasql/testdata/test_schema.pb.h"
#include "zetasql/testing/test_value.h"
#include "zetasql/testing/using_test_value.cc"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "absl/container/flat_hash_set.h"
#include "absl/hash/hash.h"
#include "absl/hash/hash_testing.h"
#include "absl/status/statusor.h"
#include "absl/strings/numbers.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/string_view.h"
#include "absl/time/time.h"
#include "zetasql/common/testing/proto_matchers.h"
#include "zetasql/base/testing/status_matchers.h"
#include "zetasql/public/types/value_representations.h"

namespace zetasql {

namespace {

using ::google::protobuf::internal::WireFormatLite;
using ::testing::HasSubstr;
using ::testing::IsEmpty;
using ::testing::Not;
using ::zetasql_base::testing::StatusIs;

using interval_testing::Days;
using interval_testing::Micros;
using interval_testing::Months;
using interval_testing::MonthsDaysMicros;
using interval_testing::MonthsDaysNanos;
using interval_testing::Nanos;

void TestHashEqual(const Value& a, const Value& b) {
  EXPECT_EQ(a.HashCode(), b.HashCode()) << "\na: " << a << "\n"
                                        << "b: " << b;
  EXPECT_EQ(absl::Hash<Value>()(a), absl::Hash<Value>()(b))
      << "\na: " << a << "\n"
      << "b: " << b;
}
void TestHashNotEqual(const Value& a, const Value& b) {
  EXPECT_NE(a.HashCode(), b.HashCode()) << "\na: " << a << "\n"
                                        << "b: " << b;
  EXPECT_NE(absl::Hash<Value>()(a), absl::Hash<Value>()(b))
      << "\na: " << a << "\n"
      << "b: " << b;
}

absl::Time ParseTimeWithFormat(absl::string_view format,
                               absl::string_view time_literal) {
  absl::Time time;
  std::string error;
  const bool successful = absl::ParseTime(format, time_literal, &time, &error);
  ZETASQL_CHECK(successful) << error;
  return time;
}

absl::Time ParseTimeHm(absl::string_view str) {
  return ParseTimeWithFormat("%H:%M", str);
}

}  // namespace

// Test that GetSQL returns a string that can be re-parsed as the Value.
// Returns <value> so this can be used as a chained call anywhere we
// construct a Value.
// Also tests that GetSQLLiteral returns a string that can be reparsed as
// a Value (which should be approximately equal to the original) where
// possible.
static Value TestGetSQL(const Value& value) {
  // Make all compiled-in proto type names visible.
  SimpleCatalog catalog("type_catalog");
  catalog.AddZetaSQLFunctions();
  catalog.SetDescriptorPool(
      zetasql_test__::KitchenSinkPB::descriptor()->file()->pool());

  AnalyzerOptions analyzer_options;
  analyzer_options.mutable_language()->EnableLanguageFeature(
      FEATURE_NUMERIC_TYPE);
  analyzer_options.mutable_language()->EnableLanguageFeature(
      FEATURE_BIGNUMERIC_TYPE);
  analyzer_options.mutable_language()->EnableLanguageFeature(FEATURE_JSON_TYPE);
  analyzer_options.mutable_language()->EnableLanguageFeature(
      FEATURE_INTERVAL_TYPE);

  const bool testable_type = !value.type()->IsProto();
  // Test round tripping GetSQL for non-legacy types.
  if (testable_type) {
    const std::string sql = value.GetSQL();
    ZETASQL_VLOG(1) << "sql: " << sql;

    // We have to use the expression evaluator rather than just the analyzer
    // because the returned SQL may be a non-literal.
    PreparedExpression expr(sql);
    const absl::Status prepare_status =
        expr.Prepare(analyzer_options, &catalog);
    ZETASQL_EXPECT_OK(prepare_status)
        << "Value: " << value.DebugString() << "\nSQL: " << sql;

    if (prepare_status.ok()) {
      const absl::StatusOr<Value> result = expr.Execute();
      ZETASQL_EXPECT_OK(result.status()) << value.DebugString();
      if (result.ok()) {
        const Value& new_value = result.value();
        EXPECT_TRUE(value.Equals(new_value))
            << "Value: " << value.FullDebugString() << "\nSQL: " << sql
            << "\nRe-parsed: " << new_value.FullDebugString();
        EXPECT_EQ(value.DebugString(), new_value.DebugString());
      }
    }
  }

  // Test round tripping GetSQLLiteral for non-legacy types.
  if (testable_type) {
    const std::string sql = value.GetSQLLiteral();
    ZETASQL_VLOG(1) << "sql literal: " << sql;

    // For GetSQLLiteral, we re-parse without a catalog because we don't
    // expect any type names to show up.  e.g. For enums, we'll just get
    // a string.
    {
      PreparedExpression expr(sql);
      const absl::Status prepare_status = expr.Prepare(analyzer_options);
      ZETASQL_EXPECT_OK(prepare_status)
          << "Value: " << value.DebugString() << "\nSQL: " << sql;

      if (prepare_status.ok()) {
        const absl::StatusOr<Value> result = expr.Execute();
        ZETASQL_EXPECT_OK(result.status()) << value.DebugString();
        if (result.ok()) {
          const Value& new_value = result.value();
          ZETASQL_VLOG(1) << "New value: " << new_value.DebugString();
          if (value.type()->Equivalent(new_value.type())) {
            EXPECT_TRUE(value.Equals(new_value))
                << "Value: " << value.FullDebugString()
                << "\nSQL literal: " << sql
                << "\nRe-parsed: " << new_value.FullDebugString();
            // Note that for STRUCTs, GetSQLLiteral returns a string that
            // does not contain field name information.  So for STRUCTS,
            // we might get a new_value that has an equivalent type, but
            // not an Equals type.  In that case, the DebugString would not
            // match so we only compare DebugStrings if the Values are equals
            // and Types are Equals.
            if (value.type()->Equals(new_value.type())) {
              EXPECT_EQ(value.DebugString(), new_value.DebugString())
                  << "value: " << value.FullDebugString()
                  << "\nnew_value: " << new_value.FullDebugString();
            }
          }
        }
      }
    }

    bool is_bad_type = false;
    // Exclude incomplete protos, which we won't be able to cast from
    // string back to proto type.
    if (value.type()->IsProto() && !value.is_null()) {
      google::protobuf::DynamicMessageFactory message_factory;
      std::unique_ptr<google::protobuf::Message> m(value.ToMessage(&message_factory));
      if (!m->IsInitialized()) {
        is_bad_type = true;
      }
    }
    // Exclude arrays of non-widest-numeric types because we don't support
    // casts of arrays.
    if (value.type()->IsArray() && !value.is_null()) {
      const Type* element_type = value.type()->AsArray()->element_type();
      if (!(element_type->IsInt64() || element_type->IsString() ||
            element_type->IsBytes() || element_type->IsDouble())) {
        is_bad_type = true;
      }
    }

    // Now try parsing the SQL literal with a CAST to the appropriate type.
    // This should give back the original value.
    // Some types are excluded because the CASTs won't be legal.
    if (!is_bad_type) {
      const std::string cast_expr = absl::StrCat(
          "CAST(", sql, " AS ", value.type()->TypeName(PRODUCT_INTERNAL), ")");
      PreparedExpression expr(cast_expr);
      const absl::Status prepare_status =
          expr.Prepare(analyzer_options, &catalog);
      ZETASQL_EXPECT_OK(prepare_status)
          << "Value: " << value.DebugString() << "\nSQL: " << cast_expr;

      if (prepare_status.ok()) {
        const absl::StatusOr<Value> result = expr.Execute();
        ZETASQL_EXPECT_OK(result.status()) << value.DebugString();
        if (result.ok()) {
          const Value& new_value = result.value();
          EXPECT_TRUE(value.Equals(new_value))
              << "Value: " << value.FullDebugString()
              << "\nSQL literal: " << sql << "\nCAST expr: " << cast_expr
              << "\nRe-parsed: " << new_value.FullDebugString();
          EXPECT_EQ(value.DebugString(), new_value.DebugString());
        }
      }
    }
  }

  return value;
}

class ValueTest : public ::testing::Test {
 public:
  ValueTest() : type_factory_(TypeFactoryOptions().IgnoreValueLifeCycle()) {}
  ValueTest(const ValueTest&) = delete;
  ValueTest& operator=(const ValueTest&) = delete;
  ~ValueTest() override {}

  const EnumType* GetTestEnumType() {
    const EnumType* enum_type;
    const google::protobuf::EnumDescriptor* enum_descriptor =
        zetasql_test__::TestEnum_descriptor();
    ZETASQL_CHECK_OK(type_factory_.MakeEnumType(enum_descriptor, &enum_type));
    return enum_type;
  }

  const EnumType* GetOtherTestEnumType() {
    const EnumType* enum_type;
    const google::protobuf::EnumDescriptor* enum_descriptor =
        zetasql_test__::AnotherTestEnum_descriptor();
    ZETASQL_CHECK_OK(type_factory_.MakeEnumType(enum_descriptor, &enum_type));
    return enum_type;
  }

  const ArrayType* GetTestArrayType(const Type* element_type) {
    const ArrayType* array_type;
    ZETASQL_CHECK_OK(type_factory_.MakeArrayType(element_type, &array_type));
    return array_type;
  }

  // Cannot just use MakeArrayType(GetTestEnumType()), because ArrayType needs
  // to be created by the same TypeFactory as EnumType.
  const ArrayType* GetTestArrayEnumType() {
    return GetTestArrayType(GetTestEnumType());
  }

  const ProtoType* GetTestProtoType() {
    zetasql_test__::KitchenSinkPB kitchen_sink;
    return test_values::MakeProtoType(kitchen_sink.GetDescriptor());
  }

  const ProtoType* GetOtherTestProtoType() {
    zetasql_test__::TestExtraPB test_extra;
    return test_values::MakeProtoType(test_extra.GetDescriptor());
  }

  void TestParameterizedValueAfterReleaseOfTypeFactory(
      bool keep_type_alive_while_referenced_from_value);

 private:
  TypeFactory type_factory_;
};

TEST_F(ValueTest, Int64Null) {
  Value value = TestGetSQL(Value::NullInt64());
  EXPECT_EQ("INT64", value.type()->DebugString());
  EXPECT_TRUE(value.is_null());
  EXPECT_DEATH(value.int64_value(), "Null value");
  Value value_copy = value;
  EXPECT_EQ("INT64", value_copy.type()->DebugString());
  EXPECT_TRUE(value_copy.is_null());
}

TEST_F(ValueTest, Int64NonNull) {
  Value value = TestGetSQL(Value::Int64(3));
  EXPECT_EQ("INT64", value.type()->DebugString());
  EXPECT_TRUE(!value.is_null());
  EXPECT_EQ(3, value.int64_value());
  Value value_copy = value;
  EXPECT_EQ("INT64", value_copy.type()->DebugString());
  EXPECT_TRUE(!value_copy.is_null());
  EXPECT_EQ(3, value_copy.int64_value());
}

TEST_F(ValueTest, DoubleNull) {
  Value value = TestGetSQL(Value::NullDouble());
  EXPECT_EQ("DOUBLE", value.type()->DebugString());
  EXPECT_TRUE(value.is_null());
  EXPECT_DEATH(value.double_value(), "Null value");
  EXPECT_EQ("NULL", value.DebugString());
  EXPECT_EQ("Double(NULL)", value.FullDebugString());
  EXPECT_EQ("CAST(NULL AS FLOAT64)", value.GetSQL());
  EXPECT_EQ("CAST(NULL AS FLOAT64)", value.GetSQL(PRODUCT_EXTERNAL));
  EXPECT_EQ("CAST(NULL AS DOUBLE)", value.GetSQL(PRODUCT_INTERNAL));
}

TEST_F(ValueTest, DoubleNonNull) {
  TestGetSQL(Value::Double(3));
  TestGetSQL(Value::Double(3.5));
  TestGetSQL(Value::Double(3.000000000004));
  TestGetSQL(Value::Double(.000000000004));
  TestGetSQL(Value::Double(-55500000000));
  TestGetSQL(Value::Double(-0.000034634643));
  TestGetSQL(Value::Double(1.5e50));
  TestGetSQL(Value::Double(-1.5e50));
  TestGetSQL(Value::Double(std::numeric_limits<double>::quiet_NaN()));
  TestGetSQL(Value::Double(std::numeric_limits<double>::infinity()));
  TestGetSQL(Value::Double(-std::numeric_limits<double>::infinity()));
}

TEST_F(ValueTest, DoubleFloatToString) {
  // Test that DebugString and GetSQL for doubles and floats returns values
  // that are clearly floating point, not integers (e.g. they have dots).
  const Value values[] = {
      Value::Double(0.0), Value::Double(1.0),  Value::Double(-1.0),
      Value::Double(1.5), Value::Double(-1.5), Value::Double(.5),
      Value::Double(-.5), Value::Double(1e20), Value::Double(-1e20),
      Value::Float(0.0),  Value::Float(1.0),   Value::Float(-1.0),
      Value::Float(1.5),  Value::Float(-1.5),  Value::Float(.5),
      Value::Float(-.5),  Value::Float(1e20),  Value::Float(-1e20)};
  for (const Value& value : values) {
    TestGetSQL(value);

    double d;
    int64_t i;
    const std::string str = value.GetSQL();
    // strtod will fail for float because GetSQL() will have a CAST.
    EXPECT_EQ(value.type_kind() == TYPE_DOUBLE, absl::SimpleAtod(str, &d))
        << str;
    // Neither float or double GetSQL() should return a valid integer string.
    EXPECT_FALSE(absl::SimpleAtoi(str, &i)) << str;
  }
}

TEST_F(ValueTest, StringNull) {
  Value value = TestGetSQL(Value::NullString());
  EXPECT_EQ("STRING", value.type()->DebugString());
  EXPECT_TRUE(value.is_null());
  EXPECT_DEATH(value.string_value(), "Null value");
  Value value_copy = value;
  EXPECT_EQ("STRING", value_copy.type()->DebugString());
  EXPECT_TRUE(value_copy.is_null());
}

TEST_F(ValueTest, StringNonNull) {
  Value value = TestGetSQL(Value::String("foo"));
  EXPECT_EQ("STRING", value.type()->DebugString());
  EXPECT_TRUE(!value.is_null());
  EXPECT_EQ("foo", value.string_value());
  Value value_copy = value;
  EXPECT_EQ("STRING", value_copy.type()->DebugString());
  EXPECT_TRUE(!value_copy.is_null());
  EXPECT_EQ("foo", value_copy.string_value());
}

void disguised_move(Value& o1, Value& o2) {  // NOLINT
  o1 = std::move(o2);
}

TEST_F(ValueTest, CopyAssignMove) {
  Value expected_value = Value::String("foo");
  Value value = Value::String("foo");
  Value value_copy = value;
  Value another_copy(value_copy);
  Value moved_copy(Value::String("foo"));
  Value assigned_copy = Value::String("foo");
  value_copy = *&value_copy;  // self-copy
  Value moved_value(Value::String("foo"));
  Value moved_assigned_value = Value::String("foo");
  Value to_be_destroyed_value = Value::String("foo");
  Value stolen_value;
  stolen_value = std::move(to_be_destroyed_value);
  EXPECT_EQ(expected_value, value_copy);
  EXPECT_EQ(expected_value, another_copy);
  EXPECT_EQ(expected_value, moved_copy);
  EXPECT_EQ(expected_value, assigned_copy);
  EXPECT_EQ(expected_value, moved_value);
  EXPECT_EQ(expected_value, moved_assigned_value);
  EXPECT_EQ(expected_value, stolen_value);
  EXPECT_DEATH(to_be_destroyed_value.type(), "Uninitialized value");

  // Self-move of an rvalue reference should not crash.
  Value obj = Value::String("foo");
  disguised_move(obj, obj);
  EXPECT_FALSE(obj.is_valid());
}

TEST_F(ValueTest, StringDebugString) {
  // Strings and bytes get escaped as printable zetasql literals.
  EXPECT_EQ("\"abc\"", Value::String("abc").DebugString());
  EXPECT_EQ("'ab\"c'", Value::String("ab\"c").DebugString());
  EXPECT_EQ("\"ab'c\"", Value::String("ab'c").DebugString());
  EXPECT_EQ("\"ab\\x01 c\"",
            TestGetSQL(Value::String("ab\x01 c")).DebugString());
  EXPECT_EQ("\"ab\\x01 c\"",
            TestGetSQL(Value::String(std::string("ab\x01 c")))
                .DebugString());  // NOLINT

  EXPECT_EQ("b\"ab\\x01 c\"",
            TestGetSQL(Value::Bytes("ab\x01 c")).DebugString());
  EXPECT_EQ("b\"ab\\x01 c\"",
            TestGetSQL(Value::Bytes(std::string("ab\x01 c")))
                .DebugString());  // NOLINT
}

TEST_F(ValueTest, SimpleRoundTrip) {
  EXPECT_EQ(-42, Value::Int32(-42).int32_value());
  EXPECT_EQ(-1 * (int64_t{42} << 42),
            Value::Int64(-1 * (int64_t{42} << 42)).int64_value());
  EXPECT_EQ(42u, Value::Uint32(42u).uint32_value());
  EXPECT_EQ(uint64_t{42} << 42,
            Value::Uint64(uint64_t{42} << 42).uint64_value());
  EXPECT_EQ(true, Value::Bool(true).bool_value());
  EXPECT_EQ(false, Value::Bool(false).bool_value());
  EXPECT_EQ(3.1415f, Value::Float(3.1415f).float_value());
  EXPECT_EQ(2.718281828459045, Value::Double(2.718281828459045).double_value());
  EXPECT_EQ("honorificabilitudinitatibus",
            Value::String("honorificabilitudinitatibus").string_value());
  EXPECT_EQ("honorificabilitudinitatibus",
            Value::Bytes("honorificabilitudinitatibus").bytes_value());
  EXPECT_EQ(123, Value::Date(123).date_value());
  int64_t min_micros = zetasql::types::kTimestampMin;
  EXPECT_EQ(min_micros, TimestampFromUnixMicros(min_micros).ToUnixMicros());
}

TEST_F(ValueTest, BaseTime) {
  const absl::TimeZone utc = absl::UTCTimeZone();

  // Minimal and maximal representable timestamp value.
  absl::Time tmin =
      absl::FromCivil(absl::CivilSecond(00001, 01, 01, 00, 00, 00), utc);
  absl::Time tmax =
      absl::FromCivil(absl::CivilSecond(10000, 01, 01, 00, 00, 00), utc) -
      absl::Nanoseconds(1);
  EXPECT_EQ("TIMESTAMP", Value::Timestamp(tmin).type()->DebugString());
  EXPECT_EQ("0001-01-01 00:00:00+00", Value::Timestamp(tmin).DebugString());
  EXPECT_EQ("9999-12-31 23:59:59.999999999+00",
            Value::Timestamp(tmax).DebugString());
  EXPECT_EQ(zetasql::types::kTimestampMin,
            Value::Timestamp(tmin).ToUnixMicros());
  EXPECT_EQ(zetasql::types::kTimestampMax,
            Value::Timestamp(tmax).ToUnixMicros());

  EXPECT_EQ(tmin, Value::Timestamp(tmin).ToTime());
  EXPECT_EQ(tmax, Value::Timestamp(tmax).ToTime());

  // Valid timestamp before Unix epoch with non-empty nanos.
  absl::Time tmin_plus = tmin + absl::Nanoseconds(5);
  EXPECT_EQ(tmin_plus, Value::Timestamp(tmin_plus).ToTime());

  // Out of range values.
  absl::Time tmin_invalid = tmin - absl::Nanoseconds(1);
  absl::Time tmax_invalid = tmax + absl::Nanoseconds(1);
  EXPECT_DEATH(Value::Timestamp(tmin_invalid),
               "Check failed: functions::IsValidTime");
  EXPECT_DEATH(Value::Timestamp(tmax_invalid),
               "Check failed: functions::IsValidTime");

  // Values representable as Unix epoch nanoseconds.
  absl::Time tmin_nanos =
      absl::FromUnixNanos(std::numeric_limits<int64_t>::lowest());
  absl::Time tmax_nanos =
      absl::FromUnixNanos(std::numeric_limits<int64_t>::max());

  EXPECT_EQ("1677-09-21 00:12:43.145224192+00",
            Value::Timestamp(tmin_nanos).DebugString());
  EXPECT_EQ("2262-04-11 23:47:16.854775807+00",
            Value::Timestamp(tmax_nanos).DebugString());

  int64_t unix_nanos = 0;
  ZETASQL_EXPECT_OK(Value::TimestampFromUnixMicros(5).ToUnixNanos(&unix_nanos));
  EXPECT_EQ(5000, unix_nanos);

  // Values not representable as 64-bit Unix epoch nanoseconds.
  Value tmin_nanos_minus = Value::Timestamp(tmin_nanos - absl::Nanoseconds(1));
  Value tmax_nanos_plus = Value::Timestamp(tmax_nanos + absl::Nanoseconds(1));

  EXPECT_THAT(
      tmin_nanos_minus.ToUnixNanos(&unix_nanos),
      StatusIs(
          absl::StatusCode::kOutOfRange,
          HasSubstr("Timestamp value in Unix epoch nanoseconds exceeds 64 bit: "
                    "1677-09-21 00:12:43.145224191+00")));

  EXPECT_THAT(
      tmax_nanos_plus.ToUnixNanos(&unix_nanos),
      StatusIs(
          absl::StatusCode::kOutOfRange,
          HasSubstr("Timestamp value in Unix epoch nanoseconds exceeds 64 bit: "
                    "2262-04-11 23:47:16.854775808+00")));
}

TEST_F(ValueTest, Interval) {
  EXPECT_TRUE(Value::NullInterval().is_null());
  EXPECT_EQ(TYPE_INTERVAL, Value::NullInterval().type_kind());

  IntervalValue interval;
  ZETASQL_ASSERT_OK_AND_ASSIGN(interval, IntervalValue::FromMicros(1));
  // Verify that there are no memory leaks.
  {
    Value v1(Value::Interval(interval));
    EXPECT_EQ(TYPE_INTERVAL, v1.type()->kind());
    EXPECT_FALSE(v1.is_null());
    Value v2(v1);
    EXPECT_EQ(TYPE_INTERVAL, v2.type()->kind());
    EXPECT_FALSE(v2.is_null());
  }

  // Test the assignment operator.
  {
    Value v1 = Value::Interval(interval);
    Value v2 = zetasql::values::Interval(interval);
    Value v3 = Value::NullInterval();
    v3 = v1;
    EXPECT_EQ(TYPE_INTERVAL, v1.type()->kind());
    EXPECT_EQ(TYPE_INTERVAL, v2.type()->kind());
    EXPECT_EQ(TYPE_INTERVAL, v3.type()->kind());
    EXPECT_FALSE(v3.is_null());
    EXPECT_EQ(interval, v1.interval_value());
    EXPECT_EQ(interval, v2.interval_value());
    EXPECT_EQ(interval, v3.interval_value());
  }

  // Equals
  {
    EXPECT_EQ(Value::Interval(Months(0)), Value::Interval(Nanos(0)));
    EXPECT_EQ(Value::Interval(Months(-5)), Value::Interval(Months(-5)));
    EXPECT_EQ(Value::Interval(Months(2)), Value::Interval(Days(60)));
    EXPECT_EQ(Value::Interval(Days(1)),
              Value::Interval(Micros(IntervalValue::kMicrosInDay)));
    EXPECT_EQ(Value::Interval(Months(-1)),
              Value::Interval(Nanos(-IntervalValue::kNanosInMonth)));
    EXPECT_EQ(Value::Interval(Micros(1)), Value::Interval(Nanos(1000)));

    EXPECT_EQ(Value::Interval(Days(45)),
              Value::Interval(MonthsDaysMicros(1, 15, 0)));
    EXPECT_EQ(Value::Interval(Days(45)),
              Value::Interval(MonthsDaysMicros(2, -15, 0)));
    EXPECT_EQ(Value::Interval(MonthsDaysMicros(1, 2, 3)),
              Value::Interval(MonthsDaysNanos(1, 2, 3000)));

    EXPECT_FALSE(Value::Interval(Months(1)) == Value::Interval(Days(31)));
    EXPECT_FALSE(Value::Interval(Months(12)) == Value::Interval(Days(365)));
    EXPECT_FALSE(Value::Interval(Micros(1)) == Value::Interval(Nanos(1)));
    EXPECT_FALSE(Value::Interval(Nanos(-1)) == Value::Interval(Nanos(1)));
  }

  {
    ZETASQL_ASSERT_OK_AND_ASSIGN(
        interval, IntervalValue::FromMonthsDaysMicros(14, 30, 3723456789));
    Value value(Value::Interval(interval));
    EXPECT_EQ("1-2 30 1:2:3.456789", value.DebugString());
    value = TestGetSQL(value);
    EXPECT_EQ("INTERVAL", value.type()->DebugString());
    EXPECT_EQ("1-2 30 1:2:3.456789", value.DebugString());
    EXPECT_FALSE(value.is_null());
    EXPECT_EQ(IntervalValue(interval), value.interval_value());
  }
}

TEST_F(ValueTest, Geography) {
  EXPECT_TRUE(Value::NullGeography().is_null());
  EXPECT_TRUE(Value::NullGeography().type()->IsGeography());
}

TEST_F(ValueTest, Numeric) {
  EXPECT_TRUE(Value::NullNumeric().is_null());
  EXPECT_EQ(TYPE_NUMERIC, Value::NullNumeric().type_kind());

  // Verify that there are no memory leaks.
  {
    Value v1(Value::Numeric(NumericValue(int64_t{1})));
    EXPECT_EQ(TYPE_NUMERIC, v1.type()->kind());
    EXPECT_FALSE(v1.is_null());
    Value v2(v1);
    EXPECT_EQ(TYPE_NUMERIC, v2.type()->kind());
    EXPECT_FALSE(v2.is_null());
    EXPECT_EQ(1.0, v1.ToDouble());
  }

  // Test the assignment operator.
  {
    Value v1 = Value::Numeric(NumericValue(int64_t{100}));
    Value v2 = Value::NullNumeric();
    v2 = v1;
    EXPECT_EQ(TYPE_NUMERIC, v1.type()->kind());
    EXPECT_EQ(TYPE_NUMERIC, v2.type()->kind());
    EXPECT_FALSE(v2.is_null());
    EXPECT_EQ(NumericValue(int64_t{100}), v1.numeric_value());
    EXPECT_EQ(NumericValue(int64_t{100}), v2.numeric_value());
    v1 = Value::Int32(1);
    EXPECT_EQ(TYPE_NUMERIC, v2.type()->kind());
  }

  {
    Value value = TestGetSQL(Value::Numeric(NumericValue(int64_t{123})));
    EXPECT_EQ("NUMERIC", value.type()->DebugString());
    EXPECT_FALSE(value.is_null());
    EXPECT_EQ(NumericValue(int64_t{123}), value.numeric_value());
  }
}

TEST_F(ValueTest, BigNumeric) {
  EXPECT_TRUE(Value::NullBigNumeric().is_null());
  EXPECT_EQ(TYPE_BIGNUMERIC, Value::NullBigNumeric().type_kind());

  // Verify that there are no memory leaks.
  {
    Value v1(Value::BigNumeric(BigNumericValue(int64_t{1})));
    EXPECT_EQ(TYPE_BIGNUMERIC, v1.type()->kind());
    EXPECT_FALSE(v1.is_null());
    Value v2(v1);
    EXPECT_EQ(TYPE_BIGNUMERIC, v2.type()->kind());
    EXPECT_FALSE(v2.is_null());
  }

  // Test the assignment operator.
  {
    Value v1 = Value::BigNumeric(BigNumericValue(int64_t{100}));
    Value v2 = zetasql::values::BigNumeric(int64_t{100});
    Value v3 = Value::NullBigNumeric();
    v3 = v1;
    EXPECT_EQ(TYPE_BIGNUMERIC, v1.type()->kind());
    EXPECT_EQ(TYPE_BIGNUMERIC, v2.type()->kind());
    EXPECT_EQ(TYPE_BIGNUMERIC, v3.type()->kind());
    EXPECT_FALSE(v3.is_null());
    EXPECT_EQ(BigNumericValue(int64_t{100}), v1.bignumeric_value());
    EXPECT_EQ(BigNumericValue(int64_t{100}), v2.bignumeric_value());
    EXPECT_EQ(BigNumericValue(int64_t{100}), v3.bignumeric_value());
    v1 = Value::Int32(1);
    EXPECT_EQ(TYPE_BIGNUMERIC, v3.type()->kind());
  }

  {
    Value value = TestGetSQL(Value::BigNumeric(BigNumericValue(int64_t{123})));
    EXPECT_EQ("BIGNUMERIC", value.type()->DebugString());
    EXPECT_FALSE(value.is_null());
    EXPECT_EQ(BigNumericValue(int64_t{123}), value.bignumeric_value());
  }
}

TEST_F(ValueTest, JSON) {
  constexpr char kStringValue[] = "value";
  constexpr int64_t kIntValue = 1;

  {
    Value null_json = Value::NullJson();
    EXPECT_TRUE(null_json.is_null());
    EXPECT_EQ(null_json.type_kind(), TYPE_JSON);
    EXPECT_FALSE(null_json.is_unparsed_json());
    EXPECT_FALSE(null_json.is_validated_json());
    EXPECT_DEATH(null_json.json_value(), "Null value");
    EXPECT_DEATH(null_json.json_string(), "Null value");
    EXPECT_DEATH(null_json.json_value_unparsed(), "Null value");
  }

  // Verify that there are no memory leaks for validated JSON.
  {
    Value v1(Value::Json(JSONValue(kIntValue)));
    EXPECT_EQ(TYPE_JSON, v1.type()->kind());
    EXPECT_FALSE(v1.is_null());
    EXPECT_TRUE(v1.is_validated_json());

    Value v2(v1);
    EXPECT_EQ(TYPE_JSON, v2.type()->kind());
    EXPECT_FALSE(v2.is_null());
    EXPECT_TRUE(v2.is_validated_json());
    EXPECT_FALSE(v2.is_unparsed_json());
    EXPECT_EQ(v2.json_string(), absl::StrCat(kIntValue));
    EXPECT_DEATH(v2.json_value_unparsed(), "Not an unparsed json value");
  }

  // Verify that there are no memory leaks for unvalidated JSON.
  {
    Value v1(Value::UnvalidatedJsonString(kStringValue));
    EXPECT_EQ(TYPE_JSON, v1.type()->kind());
    EXPECT_FALSE(v1.is_null());
    EXPECT_FALSE(v1.is_validated_json());
    Value v2(v1);
    EXPECT_EQ(TYPE_JSON, v2.type()->kind());
    EXPECT_FALSE(v2.is_null());
    ASSERT_FALSE(v2.is_validated_json());
    ASSERT_TRUE(v2.is_unparsed_json());
    EXPECT_EQ(kStringValue, v2.json_value_unparsed());
    EXPECT_EQ(kStringValue, v2.json_string());
    EXPECT_DEATH(v2.json_value(), "Non a validated json value");
  }

  // Test the assignment operator for validated JSON.
  {
    Value v1 = Value::Json(JSONValue(kIntValue));
    Value v2 = Value::NullJson();
    v2 = v1;
    EXPECT_EQ(TYPE_JSON, v1.type()->kind());
    EXPECT_EQ(TYPE_JSON, v2.type()->kind());
    EXPECT_FALSE(v2.is_null());
    EXPECT_EQ(kIntValue, v1.json_value().GetInt64());
    EXPECT_EQ(kIntValue, v2.json_value().GetInt64());
  }

  // Test the assignment operator for unvalidated JSON.
  {
    Value v1 = Value::UnvalidatedJsonString(kStringValue);
    Value v2 = Value::NullJson();
    v2 = v1;
    EXPECT_EQ(TYPE_JSON, v1.type()->kind());
    EXPECT_EQ(TYPE_JSON, v2.type()->kind());
    EXPECT_FALSE(v2.is_null());
    ASSERT_FALSE(v2.is_validated_json());
    ASSERT_TRUE(v2.is_unparsed_json());
    EXPECT_EQ(kStringValue, v1.json_value_unparsed());
    EXPECT_EQ(kStringValue, v2.json_value_unparsed());
    EXPECT_EQ(kStringValue, v2.json_string());
  }

  {
    Value value = TestGetSQL(Value::Json(JSONValue(kIntValue)));
    EXPECT_EQ("JSON", value.type()->DebugString());
    EXPECT_FALSE(value.is_null());
    ASSERT_TRUE(value.is_validated_json());
    ASSERT_TRUE(value.json_value().IsInt64());
    EXPECT_EQ(kIntValue, value.json_value().GetInt64());
    EXPECT_EQ(absl::StrCat(kIntValue), value.json_string());
  }
}

TEST_F(ValueTest, GenericAccessors) {
  // Return types.
  static Value v;
  static_assert(std::is_same<decltype(v.Get<int32_t>()), int32_t>::value, "");
  static_assert(std::is_same<decltype(v.Get<int64_t>()), int64_t>::value, "");
  static_assert(std::is_same<decltype(v.Get<uint32_t>()), uint32_t>::value, "");
  static_assert(std::is_same<decltype(v.Get<uint64_t>()), uint64_t>::value, "");
  static_assert(std::is_same<decltype(v.Get<bool>()), bool>::value, "");
  static_assert(std::is_same<decltype(v.Get<float>()), float>::value, "");
  static_assert(std::is_same<decltype(v.Get<double>()), double>::value, "");
  // Explicit template instantiations.
  EXPECT_EQ(Value::Int32(1), Value::Make<int32_t>(1));
  EXPECT_EQ(Value::Int64(1), Value::Make<int64_t>(1));
  EXPECT_EQ(Value::Uint32(1), Value::Make<uint32_t>(1));
  EXPECT_EQ(Value::Uint64(1), Value::Make<uint64_t>(1));
  EXPECT_EQ(Value::Bool(true), Value::Make<bool>(true));
  EXPECT_EQ(Value::Float(1.3f), Value::Make<float>(1.3f));
  EXPECT_EQ(Value::Double(1.3), Value::Make<double>(1.3));
  EXPECT_EQ(1, Value::Make<int32_t>(1).Get<int32_t>());
  EXPECT_EQ(1, Value::Make<int64_t>(1).Get<int64_t>());
  EXPECT_EQ(1, Value::Make<uint32_t>(1).Get<uint32_t>());
  EXPECT_EQ(1, Value::Make<uint64_t>(1).Get<uint64_t>());
  EXPECT_EQ(true, Value::Make<bool>(true).Get<bool>());
  EXPECT_EQ(1.3f, Value::Make<float>(1.3f).Get<float>());
  EXPECT_EQ(1.3, Value::Make<double>(1.3).Get<double>());
  // Implicit template instantiations.
  int32_t int32_val = 1;
  int64_t int64_val = 2;
  uint32_t uint32_val = 3;
  uint64_t uint64_val = 4;
  bool bool_val = true;
  float float_val = 1.3f;
  double double_val = 1.5;
  EXPECT_EQ(int32_val, Value::Make(int32_val).Get<int32_t>());
  EXPECT_EQ(int64_val, Value::Make(int64_val).Get<int64_t>());
  EXPECT_EQ(uint32_val, Value::Make(uint32_val).Get<uint32_t>());
  EXPECT_EQ(uint64_val, Value::Make(uint64_val).Get<uint64_t>());
  EXPECT_EQ(bool_val, Value::Make(bool_val).Get<bool>());
  EXPECT_EQ(float_val, Value::Make(float_val).Get<float>());
  EXPECT_EQ(double_val, Value::Make(double_val).Get<double>());
  // MakeNull.
  EXPECT_EQ(Value::NullInt32(), Value::MakeNull<int32_t>());
  EXPECT_EQ(Value::NullInt64(), Value::MakeNull<int64_t>());
  EXPECT_EQ(Value::NullUint32(), Value::MakeNull<uint32_t>());
  EXPECT_EQ(Value::NullUint64(), Value::MakeNull<uint64_t>());
  EXPECT_EQ(Value::NullBool(), Value::MakeNull<bool>());
  EXPECT_EQ(Value::NullFloat(), Value::MakeNull<float>());
  EXPECT_EQ(Value::NullDouble(), Value::MakeNull<double>());
  // Type mismatches.
  EXPECT_DEATH(Value::Make<int32_t>(1).Get<int64_t>(), "Not an int64");
  EXPECT_DEATH(Value::Make<int32_t>(1).Get<bool>(), "Not a bool");
  EXPECT_DEATH(Value::Make<bool>(1).Get<int32_t>(), "Not an int32");
  EXPECT_DEATH(Value::Make<float>(1.3f).Get<double>(), "Not a double");
  EXPECT_DEATH(Value::Make<double>(1.3).Get<float>(), "Not a float");
}

// Verifies that HashCode() is consistent for the same value and not the same
// for all values of the same given type.
TEST_F(ValueTest, HashCode) {
  const absl::TimeZone utc = absl::UTCTimeZone();

  const EnumType* enum_type = GetTestEnumType();
  const EnumType* other_enum_type = GetOtherTestEnumType();

  const ProtoType* proto_type = GetTestProtoType();
  const ProtoType* other_proto_type = GetOtherTestProtoType();

  const ArrayType* array_enum_type = GetTestArrayType(enum_type);
  const ArrayType* array_other_enum_type = GetTestArrayType(other_enum_type);
  const ArrayType* array_proto_type = GetTestArrayType(proto_type);
  const ArrayType* array_other_proto_type = GetTestArrayType(other_proto_type);

  // Include all simple types and some simple examples of complex types. Complex
  // types have additional testing in other tests.
  EXPECT_TRUE(absl::VerifyTypeImplementsAbslHashCorrectly({
      // Invalid value.
      Value(),
      // Typed nulls.
      Value::NullInt32(), Value::NullInt64(), Value::NullUint32(),
      Value::NullUint64(), Value::NullBool(), Value::NullFloat(),
      Value::NullDouble(), Value::NullBytes(), Value::NullString(),
      Value::NullDate(), Value::NullTimestamp(), Value::NullTime(),
      Value::NullDatetime(), Value::NullGeography(), Value::NullNumeric(),
      Value::NullBigNumeric(), Value::NullJson(), Value::Null(enum_type),
      Value::Null(other_enum_type), Value::Null(proto_type),
      Value::Null(other_proto_type), Value::Null(types::Int32ArrayType()),
      Value::Null(types::Int64ArrayType()), Value::Null(array_enum_type),
      Value::Null(array_other_enum_type), Value::Null(array_proto_type),
      Value::Null(array_other_proto_type),
      // Simple scalar types.
      Value::Int32(1001), Value::Int32(1002), Value::Int64(1001),
      Value::Int64(1002), Value::Uint32(1001), Value::Uint32(1002),
      Value::Uint64(1001), Value::Uint64(1002), Value::Bool(false),
      Value::Bool(true), Value::Float(1.3f), Value::Float(1.4f),
      Value::Double(1.3f), Value::Double(1.4f), Value::String("a"),
      Value::String("b"), Value::StringValue(std::string("a")),
      Value::StringValue(std::string("b")), Value::Bytes("a"),
      Value::Bytes("b"), Value::Bytes(std::string("a")),
      Value::Bytes(std::string("b")), Value::Date(1001), Value::Date(1002),
      Value::Timestamp(
          absl::FromCivil(absl::CivilSecond(2018, 2, 14, 16, 36, 11), utc) +
          absl::Nanoseconds(1)),
      Value::Timestamp(
          absl::FromCivil(absl::CivilSecond(2018, 2, 14, 16, 36, 11), utc) +
          absl::Nanoseconds(2)),
      Value::Time(TimeValue::FromHMSAndNanos(16, 36, 11, 1)),
      Value::Time(TimeValue::FromHMSAndNanos(16, 36, 11, 2)),
      Value::Datetime(
          DatetimeValue::FromYMDHMSAndNanos(2018, 2, 14, 16, 36, 11, 1)),
      Value::Datetime(
          DatetimeValue::FromYMDHMSAndNanos(2018, 2, 14, 16, 36, 11, 2)),
      Value::Numeric(NumericValue(int64_t{1001})),
      Value::Numeric(NumericValue(int64_t{1002})),
      Value::BigNumeric(BigNumericValue(int64_t{1001})),
      Value::BigNumeric(BigNumericValue(int64_t{1002})),
      Value::Json(JSONValue(int64_t{1})), Value::UnvalidatedJsonString("value"),
      // Enums of two different types.
      values::Enum(enum_type, 0), values::Enum(enum_type, 1),
      values::Enum(other_enum_type, 0), values::Enum(other_enum_type, 1),
      // Protos of two different types.
      Value::Proto(proto_type, {}), Value::Proto(other_proto_type, {}),
      // Arrays of various types.
      values::Int32Array({}), values::Int32Array({0, 1, 1, 2, 3, 5, 8, 13, 21}),
      values::Int32Array({0, 1, 1, 2, 3, 5, 8, 13, -1}), values::Int64Array({}),
      values::Int64Array({0, 1, 1, 2, 3, 5, 8, 13, 21}),
      values::Int64Array({0, 1, 1, 2, 3, 5, 8, 13, -1}),

      values::JsonArray({}),
      values::JsonArray({JSONValue(int64_t{1}),
                         JSONValue(std::string("\"foo\"")),
                         JSONValue::ParseJSONString("{\"a\": 10}").value()}),
      values::UnvalidatedJsonStringArray({}),
      values::UnvalidatedJsonStringArray({"1", "{\"a:}", "foo"}),

      values::EmptyArray(array_enum_type),
      values::Array(array_enum_type, {values::Enum(enum_type, 0)}),
      values::Array(array_enum_type,
                    {values::Enum(enum_type, 0), values::Enum(enum_type, 1)}),
      values::EmptyArray(array_other_enum_type),
      values::Array(array_other_enum_type, {values::Enum(other_enum_type, 0)}),
      values::Array(array_other_enum_type, {values::Enum(other_enum_type, 0),
                                            values::Enum(other_enum_type, 1)}),

      values::EmptyArray(array_proto_type),
      values::Array(array_proto_type, {Value::Proto(proto_type, {})}),
      values::Array(array_proto_type, {Value::Proto(proto_type, {}),
                                       Value::Proto(proto_type, {})}),
      values::EmptyArray(array_other_proto_type),
      values::Array(array_other_proto_type,
                    {Value::Proto(other_proto_type, {})}),
      values::Array(array_other_proto_type,
                    {Value::Proto(other_proto_type, {}),
                     Value::Proto(other_proto_type, {})}),
  }));
}

TEST_F(ValueTest, InvalidValue) {
  Value invalid;
  EXPECT_EQ("Uninitialized value", invalid.DebugString());
  Value valid = Value::Int32(5);
  EXPECT_EQ("5", valid.DebugString());

  EXPECT_TRUE(invalid.Equals(Value()));
  EXPECT_TRUE(invalid.Equals(invalid));
  EXPECT_FALSE(invalid.Equals(valid));
  EXPECT_FALSE(valid.Equals(invalid));
  EXPECT_TRUE(valid.Equals(valid));

  Value valid_null = Value::NullInt32();
  TestHashEqual(invalid, invalid);
  TestHashNotEqual(invalid, valid);
  TestHashNotEqual(invalid, valid_null);
}

TEST_F(ValueTest, ConstructorTyping) {
  EXPECT_TRUE(Int32Type()->Equals(Value::Int32(-42).type()));
  EXPECT_TRUE(
      Int64Type()->Equals(Value::Int64(-1 * (int64_t{42} << 42)).type()));
  EXPECT_TRUE(Uint32Type()->Equals(Value::Uint32(42u).type()));
  EXPECT_TRUE(Uint64Type()->Equals(Value::Uint64(uint64_t{42} << 42).type()));
  EXPECT_TRUE(BoolType()->Equals(Value::Bool(true).type()));
  EXPECT_TRUE(BoolType()->Equals(Value::Bool(false).type()));
  EXPECT_TRUE(FloatType()->Equals(Value::Float(3.1415f).type()));
  EXPECT_TRUE(DoubleType()->Equals(Value::Double(2.718281828459045).type()));
  EXPECT_TRUE(StringType()->Equals(
      Value::StringValue(std::string("argh")).type()));  // NOLINT
  EXPECT_TRUE(StringType()->Equals(Value::String("argh").type()));
  EXPECT_TRUE(
      BytesType()->Equals(Value::Bytes(std::string("argh")).type()));  // NOLINT
  EXPECT_TRUE(BytesType()->Equals(Value::Bytes("argh").type()));
  EXPECT_TRUE(DateType()->Equals(Value::Date(0).type()));
}

TEST_F(ValueTest, CopyConstructor) {
  Value v0 = TestGetSQL(Value::Int32(-42));
  EXPECT_EQ(-42, v0.int32_value());
  EXPECT_EQ(-42, v0.ToDouble());
  EXPECT_EQ(-42, v0.ToInt64());

  Value v1 = TestGetSQL(Value::Int64(-1 * (int64_t{42} << 42)));
  EXPECT_EQ(-1 * (int64_t{42} << 42), v1.int64_value());
  EXPECT_EQ(-1 * (int64_t{42} << 42), v1.ToDouble());
  EXPECT_EQ(-1 * (int64_t{42} << 42), v1.ToInt64());

  Value v2 = TestGetSQL(Value::Uint32(42u));
  EXPECT_EQ(42u, v2.uint32_value());
  EXPECT_EQ(42, v2.ToDouble());
  EXPECT_EQ(42, v2.ToInt64());
  EXPECT_EQ(42u, v2.ToUint64());

  Value v3 = TestGetSQL(Value::Uint64(uint64_t{42} << 42));
  EXPECT_EQ(uint64_t{42} << 42, v3.uint64_value());
  EXPECT_EQ(uint64_t{42} << 42, v3.ToDouble());
  EXPECT_EQ(uint64_t{42} << 42, v3.ToUint64());

  Value v4 = TestGetSQL(Value::Bool(true));
  EXPECT_EQ(true, v4.bool_value());
  EXPECT_EQ(1, v4.ToDouble());
  EXPECT_EQ(1, v4.ToInt64());
  EXPECT_EQ(1, v4.ToUint64());
  EXPECT_EQ(True(), v4);

  Value v5 = TestGetSQL(Value::Bool(false));
  EXPECT_EQ(false, v5.bool_value());
  EXPECT_EQ(0, v5.ToDouble());
  EXPECT_EQ(0, v5.ToInt64());
  EXPECT_EQ(0, v5.ToUint64());
  EXPECT_EQ(False(), v5);

  Value v6 = TestGetSQL(Value::Float(3.1415f));
  EXPECT_EQ(3.1415f, v6.float_value());
  EXPECT_EQ(3.1415f, v6.ToDouble());
  EXPECT_EQ("3.1415", v6.DebugString());
  EXPECT_EQ("CAST(3.1415 AS FLOAT)", v6.GetSQL());
  EXPECT_EQ("3.1415", v6.GetSQLLiteral());

  Value v6b = TestGetSQL(Value::Float(3.0f));
  EXPECT_EQ(3.0f, v6b.float_value());
  EXPECT_EQ(3.0, v6b.ToDouble());
  EXPECT_EQ("3", v6b.DebugString());
  EXPECT_EQ("CAST(3 AS FLOAT)", v6b.GetSQL());
  EXPECT_EQ("3.0", v6b.GetSQLLiteral());

  Value v7 = TestGetSQL(Value::Double(2.7182818284590451));
  EXPECT_EQ(2.7182818284590451, v7.double_value());
  EXPECT_EQ(2.7182818284590451, v7.ToDouble());
  EXPECT_EQ("2.7182818284590451", v7.GetSQL());

  Value v7b = TestGetSQL(Value::Double(5.0));
  EXPECT_EQ(5.0, v7b.double_value());
  EXPECT_EQ(5.0, v7b.ToDouble());
  EXPECT_EQ("5", v7b.DebugString());
  EXPECT_EQ("5.0", v7b.GetSQL());
  EXPECT_EQ("5.0", v7b.GetSQLLiteral());

  Value v7c = TestGetSQL(Value::Double(-5.0));
  EXPECT_EQ(-5.0, v7c.double_value());
  EXPECT_EQ(-5.0, v7c.ToDouble());
  EXPECT_EQ("-5", v7c.DebugString());
  EXPECT_EQ("-5.0", v7c.GetSQL());
  EXPECT_EQ("-5.0", v7c.GetSQLLiteral());

  Value v7d = TestGetSQL(Value::Double(1e20));
  EXPECT_EQ(1e20, v7d.double_value());
  EXPECT_EQ(1e20, v7d.ToDouble());
  EXPECT_EQ("1e+20", v7d.DebugString());
  EXPECT_EQ("1e+20", v7d.GetSQL());         // No extra ".0" added.
  EXPECT_EQ("1e+20", v7d.GetSQLLiteral());  // No extra ".0" added.

  Value v7e = TestGetSQL(Value::Double(1e-20));
  EXPECT_EQ(1e-20, v7e.double_value());
  EXPECT_EQ(1e-20, v7e.ToDouble());
  double round_trip_double;
  ASSERT_TRUE(absl::SimpleAtod(v7e.DebugString(), &round_trip_double));
  EXPECT_EQ(1e-20, round_trip_double);
  ASSERT_TRUE(absl::SimpleAtod(v7e.GetSQLLiteral(), &round_trip_double));
  EXPECT_EQ(1e-20, round_trip_double);
  EXPECT_EQ("1e-20", v7e.DebugString());
  EXPECT_EQ("1e-20", v7e.GetSQLLiteral());  // No extra ".0" added.

  Value v8 = TestGetSQL(Value::String("honorificabilitudinitatibus"));
  EXPECT_EQ("honorificabilitudinitatibus", v8.string_value());
  EXPECT_EQ("honorificabilitudinitatibus", v8.ToCord());
  Value v9 = TestGetSQL(Value::Bytes("honorificabilitudinitatibus"));
  EXPECT_EQ("honorificabilitudinitatibus", v9.bytes_value());
  EXPECT_EQ("honorificabilitudinitatibus", v9.ToCord());

  Value v10 = TestGetSQL(Value::Date(12345));
  EXPECT_EQ(12345, v10.date_value());
  EXPECT_EQ(12345, v10.ToDouble());
  EXPECT_EQ(12345, v10.ToInt64());
  Value v11 = TestGetSQL(Value::Date(-12345));
  EXPECT_EQ(-12345, v11.date_value());
  EXPECT_EQ(-12345, v11.ToDouble());
  EXPECT_EQ(-12345, v11.ToInt64());
}

TEST_F(ValueTest, DateTests) {
  Value value = TestGetSQL(Value::Date(0));
  EXPECT_EQ("DATE", value.type()->DebugString());
  EXPECT_TRUE(!value.is_null());
  EXPECT_EQ("1970-01-01", value.DebugString());
}

TEST_F(ValueTest, InvalidTimestamps) {
  // Valid values.
  Value::Date(types::kDateMax);
  Value::Date(types::kDateMin);

  // Out of range values.
  EXPECT_DEATH(Value::Date(types::kDateMax + 1),
               "Check failed: value <= types::kDateMax");
  EXPECT_DEATH(Value::Date(types::kDateMin - 1),
               "Check failed: value >= types::kDateMin");
}

TEST_F(ValueTest, NullDeath) {
  EXPECT_DEATH(Value::NullInt32().int32_value(), "Null value");
  EXPECT_DEATH(Value::NullInt64().int64_value(), "Null value");
  EXPECT_DEATH(Value::NullUint32().uint32_value(), "Null value");
  EXPECT_DEATH(Value::NullUint64().uint64_value(), "Null value");
  EXPECT_DEATH(Value::NullBool().bool_value(), "Null value");
  EXPECT_DEATH(Value::NullFloat().float_value(), "Null value");
  EXPECT_DEATH(Value::NullDouble().double_value(), "Null value");
  EXPECT_DEATH(Value::NullString().string_value(), "Null value");
  EXPECT_DEATH(Value::NullBytes().bytes_value(), "Null value");
  EXPECT_DEATH(Value::NullDate().date_value(), "Null value");
}

TEST_F(ValueTest, DistinctValues) {
  std::vector<Value> values = {
      Value::NullInt64(), Value::NullInt32(), Value::NullUint64(),
      Value::NullUint32(), Value::NullBool(), Value::NullFloat(),
      Value::NullDouble(), Value::NullString(), Value::NullBytes(),
      Value::NullDate(),
      Value::Int32(0), Value::Int64(0), Value::Uint32(0), Value::Uint64(0),
      Value::Bool(false), Value::Float(0), Value::Double(0), Value::String(""),
      Value::Bytes(""), Value::Date(0),
  };
  for (int i = 0; i < values.size(); i++) {
    TestGetSQL(values[i]);
    EXPECT_EQ(values[i], values[i]);
    for (int j = 0; j < values.size(); j++) {
      if (i != j) {
        EXPECT_NE(values[i], values[j]);
      }
    }
  }
}

// Returns a number that is larger than 'x' but should compare equal.
template <typename T>
T NextAlmostEqual(T x) {
  return x + 0.5 * 16 * FloatMargin::Ulp(x);
}

// Returns a number that is larger than 'x' and should not compare equal.
template <typename T>
T NextUnequal(T x) {
  return x + 1.5 * 16 * FloatMargin::Ulp(x);
}

TEST_F(ValueTest, AlmostEquals) {
  auto x = Value::Double(3.0);
  auto x_near = Value::Double(NextAlmostEqual(3.0));
  auto x_far = Value::Double(NextUnequal(3.0));
  auto y = Value::Float(7.0);
  auto y_near = Value::Float(NextAlmostEqual(7.0f));
  auto y_far = Value::Float(NextUnequal(7.0f));
  // double
  EXPECT_THAT(x, AlmostEqualsValue(x_near));
  EXPECT_THAT(x, Not(AlmostEqualsValue(x_far)));
  // float
  EXPECT_THAT(y, AlmostEqualsValue(y_near));
  EXPECT_THAT(y, Not(AlmostEqualsValue(y_far)));
  // struct<double>
  EXPECT_THAT(Struct({"v"}, {x}), AlmostEqualsValue(Struct({"v"}, {x_near})));
  EXPECT_THAT(Struct({"v"}, {x}),
              Not(AlmostEqualsValue(Struct({"v"}, {x_far}))));
  // struct<float>
  EXPECT_THAT(Struct({"v"}, {y}), AlmostEqualsValue(Struct({"v"}, {y_near})));
  EXPECT_THAT(Struct({"v"}, {y}),
              Not(AlmostEqualsValue(Struct({"v"}, {y_far}))));
  // array<double>
  EXPECT_THAT(Array({x, x_near}), AlmostEqualsValue(Array({x_near, x})));
  EXPECT_THAT(Array({x, x}), Not(AlmostEqualsValue(Array({x_far, x}))));
  // array<float>
  EXPECT_THAT(Array({y, y_near}), AlmostEqualsValue(Array({y_near, y})));
  EXPECT_THAT(Array({y, y}), Not(AlmostEqualsValue(Array({y_far, y}))));
  // Unordered array<double>
  EXPECT_THAT(
      Array({x, x_near}),
      AlmostEqualsValue(Array({x_near, x}, InternalValue::kIgnoresOrder)));
  // Unordered array<float>
  EXPECT_THAT(
      Array({y, y_near}),
      AlmostEqualsValue(Array({y_near, y}, InternalValue::kIgnoresOrder)));

  // x and x_far differ by 5 ULP bits.
  int bits = 0;
  while (bits < 10 && !FloatMargin::UlpMargin(bits).Equal(
                          x.double_value(), x_far.double_value())) {
    bits++;
  }
  EXPECT_EQ(5, bits);

  // Values that are very close to zero compare as almost equal even though
  // they differ by orders of magnitude.
  double tiny1 = 1e-15;
  double tiny2 = 1e-150;
  EXPECT_THAT(Value::Double(tiny1), AlmostEqualsValue(Value::Double(tiny2)))
      << kDefaultFloatMargin.PrintError(tiny1, tiny2);
}

absl::Cord BuildDoubleValueProto(double value) {
  google::protobuf::DoubleValue m;
  m.set_value(value);
  return SerializeToCord(m);
}

TEST_F(ValueTest, AlmostEqualsMessageWithFloatingPointField) {
  TypeFactory factory;
  const ProtoType* proto_type;
  ZETASQL_ASSERT_OK(factory.MakeProtoType(google::protobuf::DoubleValue::descriptor(),
                                  &proto_type));
  auto x = Value::Proto(proto_type, BuildDoubleValueProto(3.0));
  auto x_near =
      Value::Proto(proto_type, BuildDoubleValueProto(NextAlmostEqual(3.0)));
  auto x_far = Value::Proto(proto_type, BuildDoubleValueProto(7.0));
  // AlmostEquals
  EXPECT_THAT(x, AlmostEqualsValue(x));
  EXPECT_THAT(x, AlmostEqualsValue(x_near));
  EXPECT_THAT(x, Not(AlmostEqualsValue(x_far)));
  // Equals
  EXPECT_THAT(x, EqualsValue(x));
  EXPECT_THAT(x, Not(EqualsValue(x_near)));
  EXPECT_THAT(x, Not(AlmostEqualsValue(x_far)));
}

TEST_F(ValueTest, AlmostEqualsStructArray) {
  auto x = Value::Double(3.0);
  auto x_near = Value::Double(NextAlmostEqual(3.0));
  // TODO: the current algorithm for multiset comparison in value.cc
  // has trouble dealing with non-transitive almost-equal elements. If x_far
  // below is replaced by Value::Double(NextUnequal(3.0)), x_far becomes
  // almost equal to x_near, x_near is almost equal to x, yet x_far is not
  // almost equal to x; and the test fails. Same is potentially true for y_far.
  auto x_far = Value::Double(NextUnequal(NextUnequal(3.0)));
  auto y = Value::Float(7.0);
  auto y_near = Value::Float(NextAlmostEqual(7.0f));
  auto y_far = Value::Float(NextUnequal(NextUnequal(7.0f)));
  // Multiset [(x,      y), (x_near, y_far)] should be equal to
  // multiset [(x_near, y), (x,      y_far)]. If multiset equality were
  // implemented by ordering the elements, this test would fail because it'd
  // wrongly conclude that (x, y) should match (x, y_far).
  auto r1 = Struct({"x", "y"}, {x, y});
  auto r2 = Struct({"x", "y"}, {x_near, y_far});
  auto s1 = Struct({"x", "y"}, {x_near, y});
  auto s2 = Struct({"x", "y"}, {x, y_far});
  EXPECT_THAT(Array({r1, r2}),
              AlmostEqualsValue(Array({s2, s1}, InternalValue::kIgnoresOrder)));

  // Moreover, we can't fix the sort-based algorithm by first comparing
  // y-members then x-members. To prevent that, we add the symmetric structs:
  // [(x,      y), (x_far, y_near)],
  // [(x, y_near), (x_far, y     )].
  auto r3 = Struct({"x", "y"}, {x, y});
  auto r4 = Struct({"x", "y"}, {x_far, y_near});
  auto s3 = Struct({"x", "y"}, {x, y_near});
  auto s4 = Struct({"x", "y"}, {x_far, y});
  EXPECT_THAT(Array({r3, r4}),
              AlmostEqualsValue(Array({s4, s3}, InternalValue::kIgnoresOrder)));

  // And now we combine the multisets with x-distinct and y-distinct structs.
  EXPECT_THAT(
      Array({r1, r2, r3, r4}),
      AlmostEqualsValue(Array({s2, s1, s4, s3}, InternalValue::kIgnoresOrder)));
}

TEST_F(ValueTest, StructNotNull) {
  Value value = Struct({{"a", Value::Int64(1)}, {"b", Value::Int64(2)}});
  TestGetSQL(value);
  EXPECT_FALSE(value.is_null());
  EXPECT_DEATH(value.int64_value(), "Not an int64_t value");
  EXPECT_EQ(2, value.num_fields());
  EXPECT_EQ(1, value.field(0).int64_value());
  EXPECT_EQ(2, value.field(1).int64_value());
  EXPECT_EQ(1, value.FindFieldByName("a").int64_value());
  EXPECT_EQ(2, value.FindFieldByName("b").int64_value());
  EXPECT_FALSE(value.FindFieldByName("junk").is_valid());
  EXPECT_FALSE(value.FindFieldByName("").is_valid());

  EXPECT_EQ("{a:1, b:2}", value.DebugString());

  Value value_copy = value;
  EXPECT_EQ("{a:1, b:2}", value_copy.DebugString());

  Value same_value = Struct({"a", "b"}, {Value::Int64(1), Value::Int64(2)});
  EXPECT_TRUE(value.Equals(same_value));
  EXPECT_EQ(value.DebugString(true), same_value.DebugString(true));
}

TEST_F(ValueTest, StructNull) {
  Value value = TestGetSQL(Value::Null(MakeStructType({{"a", Int64Type()}})));
  EXPECT_TRUE(value.is_null());
  EXPECT_DEATH(value.int64_value(), "Not an int64_t value");
  EXPECT_DEATH(value.num_fields(), "Null value");
  EXPECT_DEATH(value.FindFieldByName("junk"), "Null value");
}

TEST_F(ValueTest, InvalidStructConstruction) {
  const StructType* struct_type = MakeStructType({{"a", Int64Type()}});
  // No values
  std::vector<Value> as_vec;
  absl::Span<const Value> as_span;
  std::array<Value, 0> as_array;
  // Initializer list
  EXPECT_THAT(Value::MakeStruct(struct_type, {}),
              StatusIs(absl::StatusCode::kInternal));
  // Span
  EXPECT_THAT(Value::MakeStruct(struct_type, as_span),
              StatusIs(absl::StatusCode::kInternal));
  EXPECT_THAT(Value::MakeStruct(struct_type, as_vec),
              StatusIs(absl::StatusCode::kInternal));
  // Make sure span coercion works correctly.
  EXPECT_THAT(Value::MakeStruct(struct_type, as_array),
              StatusIs(absl::StatusCode::kInternal));
  const std::vector<Value>& as_vec_c = as_vec;
  EXPECT_THAT(Value::MakeStruct(struct_type, as_vec_c),
              StatusIs(absl::StatusCode::kInternal));

  // Move constructor
  EXPECT_THAT(Value::MakeStruct(struct_type, std::move(as_vec)),
              StatusIs(absl::StatusCode::kInternal));
#ifndef NDEBUG
  // When in debug mode, we check anyway, and expect an error.
  EXPECT_THAT(Value::MakeStructFromValidatedInputs(struct_type, {}),
              StatusIs(absl::StatusCode::kInternal));
#else
  // In production, we don't expect any validation, thus OK.
  ZETASQL_EXPECT_OK(Value::MakeStructFromValidatedInputs(struct_type, {}));
#endif

  // Deprecated API
  EXPECT_DEATH(Value::Struct(struct_type, {}), "(1 vs. 0)");
#ifndef NDEBUG
  EXPECT_DEATH(Value::UnsafeStruct(struct_type, {}), "(1 vs. 0)");
#endif

  // Type mismatch
  EXPECT_THAT(Value::MakeStruct(struct_type, {Value::String("abc")}),
              StatusIs(absl::StatusCode::kInternal));

  // We actually _do_ validate since we are in debug mode
#ifndef NDEBUG
  EXPECT_THAT(
      Value::MakeStructFromValidatedInputs(struct_type, {Value::String("abc")}),
      StatusIs(absl::StatusCode::kInternal));
#else
  ZETASQL_EXPECT_OK(Value::MakeStructFromValidatedInputs(struct_type,
                                                 {Value::String("abc")}));
#endif

  // Deprecated API
  EXPECT_DEATH(Value::Struct(struct_type, {Value::String("abc")}),
               "Field type: INT64");
#ifndef NDEBUG
  EXPECT_DEATH(Value::UnsafeStruct(struct_type, {Value::String("abc")}),
               "Field type: INT64");
#endif
}

TEST_F(ValueTest, StructWithOneAnonymousField) {
  Value value = TestGetSQL(Struct({std::string("")}, {Value::Int64(5)}));
  EXPECT_EQ(1, value.num_fields());
  EXPECT_EQ(5, value.field(0).int64_value());
  EXPECT_FALSE(value.FindFieldByName("").is_valid());
  EXPECT_FALSE(value.FindFieldByName("abc").is_valid());
}

TEST_F(ValueTest, StructWithTwoAnonymousFields) {
  Value value = TestGetSQL(
      Struct({std::string(""), ""}, {Value::Int64(5), Value::String("abc")}));
  EXPECT_EQ(2, value.num_fields());
  EXPECT_EQ(5, value.field(0).int64_value());
  EXPECT_EQ("abc", value.field(1).string_value());
  EXPECT_FALSE(value.FindFieldByName("").is_valid());
}

TEST_F(ValueTest, StructWithNoFields) {
  Value value = TestGetSQL(Struct({}, {}));
  EXPECT_EQ(0, value.num_fields());
  EXPECT_FALSE(value.FindFieldByName("").is_valid());
  EXPECT_FALSE(value.FindFieldByName("abc").is_valid());

  EXPECT_EQ("STRUCT<>()", value.GetSQL());
  EXPECT_EQ("{}", value.DebugString());
  EXPECT_EQ("Struct{}", value.FullDebugString());
}

TEST_F(ValueTest, ArrayNotNull) {
  Value value = TestGetSQL(Int64Array({1, 2}));
  EXPECT_FALSE(value.is_null());
  EXPECT_DEATH(value.int64_value(), "Not an int64_t value");
  EXPECT_EQ(2, value.num_elements());
  EXPECT_EQ(1, value.element(0).int64_value());
  EXPECT_EQ(2, value.element(1).int64_value());
  EXPECT_EQ("[1, 2]", value.DebugString());

  Value value_copy = value;
  EXPECT_EQ("[1, 2]", value_copy.DebugString());
}

TEST_F(ValueTest, ArrayNull) {
  Value value = TestGetSQL(Value::Null(MakeArrayType(Int64Type())));
  EXPECT_TRUE(value.is_null());
  EXPECT_DEATH(value.int64_value(), "Not an int64_t value");
  EXPECT_DEATH(value.empty(), "Null value");
  EXPECT_DEATH(value.num_elements(), "Null value");
  EXPECT_DEATH(value.element(0), "Null value");
  EXPECT_EQ("NULL", value.DebugString());
  EXPECT_EQ("Array<INT64>(NULL)", value.FullDebugString());
  Value value_copy = value;
  EXPECT_TRUE(value_copy.is_null());
  EXPECT_TRUE(value.Equals(value_copy));
  Value value2 = TestGetSQL(Value::Null(MakeArrayType(StringType())));
  EXPECT_TRUE(value2.is_null());
  EXPECT_FALSE(value.Equals(value2));
}

TEST_F(ValueTest, MakeArrayConstruction) {
  const ArrayType* array_type = MakeArrayType(Int64Type());
  // No values
  std::vector<Value> as_vec;
  absl::Span<const Value> as_span;
  std::array<Value, 0> as_array;
  const std::vector<Value>& as_vec_c = as_vec;
  // Initializer list
  ZETASQL_ASSERT_OK_AND_ASSIGN(Value result, Value::MakeArray(array_type, {}));
  EXPECT_THAT(result.elements(), IsEmpty());

  // Span
  ZETASQL_ASSERT_OK_AND_ASSIGN(result, Value::MakeArray(array_type, as_span));
  EXPECT_THAT(result.elements(), IsEmpty());

  ZETASQL_ASSERT_OK_AND_ASSIGN(result, Value::MakeArray(array_type, as_vec));
  EXPECT_THAT(result.elements(), IsEmpty());

  ZETASQL_ASSERT_OK_AND_ASSIGN(result, Value::MakeArray(array_type, as_array));
  EXPECT_THAT(result.elements(), IsEmpty());

  ZETASQL_ASSERT_OK_AND_ASSIGN(result, Value::MakeArray(array_type, as_vec_c));
  EXPECT_THAT(result.elements(), IsEmpty());

  ZETASQL_ASSERT_OK_AND_ASSIGN(result, Value::MakeArray(array_type, std::move(as_vec)));
  EXPECT_THAT(result.elements(), IsEmpty());
}

TEST_F(ValueTest, InvalidArrayConstruction) {
  const ArrayType* array_type = MakeArrayType(Int64Type());

  // Type mismatch
  EXPECT_THAT(Value::MakeArray(array_type, {Value::String("abc")}),
              StatusIs(absl::StatusCode::kInternal));

#ifndef NDEBUG
  // We actually _do_ validate since we are in debug mode
  EXPECT_THAT(
      Value::MakeArrayFromValidatedInputs(array_type, {Value::String("abc")}),
      StatusIs(absl::StatusCode::kInternal));
#else
  ZETASQL_EXPECT_OK(
      Value::MakeArrayFromValidatedInputs(array_type, {Value::String("abc")}));
#endif
  // Deprecated API
  EXPECT_DEATH(Value::Array(array_type, {Value::String("abc")}),
               "must be of type INT64");
  EXPECT_DEATH(Value::ArraySafe(array_type, {Value::String("abc")}),
               "must be of type INT64");
#ifndef NDEBUG
  EXPECT_DEATH(Value::UnsafeArray(array_type, {Value::String("abc")}),
               "must be of type INT64");
#endif
}

TEST_F(ValueTest, NumericArray) {
  Value v = TestGetSQL(values::Int64Array({1, 2}));
  EXPECT_EQ("Array[Int64(1), Int64(2)]", v.FullDebugString());
  EXPECT_EQ("[1, 2]", v.ShortDebugString());
  v = TestGetSQL(values::Int32Array({1, 2}));
  EXPECT_EQ("Array[Int32(1), Int32(2)]", v.FullDebugString());
  EXPECT_EQ("[1, 2]", v.ShortDebugString());
  v = TestGetSQL(values::Uint64Array({1, 2}));
  EXPECT_EQ("Array[Uint64(1), Uint64(2)]", v.FullDebugString());
  EXPECT_EQ("[1, 2]", v.ShortDebugString());
  v = TestGetSQL(values::Uint32Array({1, 2}));
  EXPECT_EQ("Array[Uint32(1), Uint32(2)]", v.FullDebugString());
  EXPECT_EQ("[1, 2]", v.ShortDebugString());
  v = TestGetSQL(values::BoolArray({true, false}));
  EXPECT_EQ("Array[Bool(true), Bool(false)]", v.FullDebugString());
  EXPECT_EQ("[true, false]", v.ShortDebugString());
  v = TestGetSQL(values::FloatArray({1.1, 2.2}));
  EXPECT_EQ("Array[Float(1.1), Float(2.2)]", v.FullDebugString());
  EXPECT_EQ("[1.1, 2.2]", v.ShortDebugString());
  v = TestGetSQL(values::DoubleArray({1.1, 2.2}));
  EXPECT_EQ("Array[Double(1.1), Double(2.2)]", v.FullDebugString());
  EXPECT_EQ("[1.1, 2.2]", v.ShortDebugString());
}

TEST_F(ValueTest, StringArray) {
  Value v1 = TestGetSQL(StringArray({"foo", "bar"}));
  EXPECT_EQ("Array[String(\"foo\"), String(\"bar\")]", v1.FullDebugString());
  EXPECT_EQ("[\"foo\", \"bar\"]", v1.ShortDebugString());
  absl::Cord c1("foo"), c2("bar");
  Value v2 = StringArray({&c1, &c2});
  EXPECT_EQ(v1, v2);
}

TEST_F(ValueTest, BytesArray) {
  Value v1 = TestGetSQL(BytesArray({"foo", "bar"}));
  absl::Cord c1("foo"), c2("bar");
  Value v2 = BytesArray({&c1, &c2});
  EXPECT_EQ("Array[Bytes(b\"foo\"), Bytes(b\"bar\")]", v1.FullDebugString());
  EXPECT_EQ("[b\"foo\", b\"bar\"]", v1.ShortDebugString());
  EXPECT_EQ(v1, v2);
}

TEST_F(ValueTest, FloatArray) {
  Value v1 = TestGetSQL(
      FloatArray({1.5, 2.5, std::numeric_limits<double>::quiet_NaN()}));
  EXPECT_EQ("[1.5, 2.5, nan]", v1.DebugString());
  EXPECT_EQ(
      "ARRAY<FLOAT>[CAST(1.5 AS FLOAT), CAST(2.5 AS FLOAT), "
      "CAST(\"nan\" AS FLOAT)]",
      v1.GetSQL());
  EXPECT_EQ("[1.5, 2.5, CAST(\"nan\" AS FLOAT)]", v1.GetSQLLiteral());
}

TEST_F(ValueTest, DoubleArray) {
  Value v1 = TestGetSQL(DoubleArray({1.5, 2.5}));
  EXPECT_EQ("[1.5, 2.5]", v1.DebugString());
  EXPECT_EQ("ARRAY<FLOAT64>[1.5, 2.5]", v1.GetSQL(PRODUCT_EXTERNAL));
  EXPECT_EQ("ARRAY<DOUBLE>[1.5, 2.5]", v1.GetSQL(PRODUCT_INTERNAL));
  EXPECT_EQ("[1.5, 2.5]", v1.GetSQLLiteral());
  Value v2 = DoubleArray({1.5, std::numeric_limits<double>::infinity()});
  EXPECT_EQ("[1.5, inf]", v2.DebugString());
  EXPECT_EQ("ARRAY<FLOAT64>[1.5, CAST(\"inf\" AS FLOAT64)]",
            v2.GetSQL(PRODUCT_EXTERNAL));
  EXPECT_EQ("ARRAY<DOUBLE>[1.5, CAST(\"inf\" AS DOUBLE)]",
            v2.GetSQL(PRODUCT_INTERNAL));
  EXPECT_EQ("[1.5, CAST(\"inf\" AS FLOAT64)]",
            v2.GetSQLLiteral(PRODUCT_EXTERNAL));
  EXPECT_EQ("[1.5, CAST(\"inf\" AS DOUBLE)]",
            v2.GetSQLLiteral(PRODUCT_INTERNAL));
}

TEST_F(ValueTest, TimestampArray) {
  Value v1 = TestGetSQL(
      values::TimestampArray({ParseTimeHm("12:00"), ParseTimeHm("13:00")}));
  EXPECT_EQ(v1.DebugString(),
            "[1970-01-01 12:00:00+00, 1970-01-01 13:00:00+00]");
  EXPECT_EQ(v1.FullDebugString(),
            "Array[Timestamp(1970-01-01 12:00:00+00), "
            "Timestamp(1970-01-01 13:00:00+00)]");
  absl::Time t1 = ParseTimeHm("12:00"), t2 = ParseTimeHm("13:00");
  Value v2 = values::TimestampArray({t1, t2});
  EXPECT_EQ(v1, v2);
}

TEST_F(ValueTest, JsonArray) {
  Value v1 = TestGetSQL(JsonArray(
      {JSONValue(int64_t{10}), JSONValue(std::string(R"("foo")")),
       JSONValue::ParseJSONString(R"({"a": [1, true, null]})").value()}));
  EXPECT_EQ(R"(Array[Json(10), Json("\"foo\""), Json({"a":[1,true,null]})])",
            v1.FullDebugString());
  EXPECT_EQ(R"([10, "\"foo\"", {"a":[1,true,null]}])", v1.ShortDebugString());
}

TEST_F(ValueTest, ArrayBag) {
  std::vector<Value> values = {Int64(1), Int64(2), Int64(1), NullInt64(),
                               NullInt64()};
  Value bag = InternalValue::ArrayChecked(MakeArrayType(Int64Type()),
                                          InternalValue::kIgnoresOrder,
                                          std::move(values));
  values = {Int64(1), NullInt64(), Int64(1), NullInt64(), Int64(2)};
  Value array = Value::Array(MakeArrayType(Int64Type()), values);
  EXPECT_FALSE(bag == array);
  EXPECT_FALSE(array == bag);
  EXPECT_TRUE(InternalValue::Equals(bag, array));
  Value bag_struct = Struct({"foo"}, {bag});
  Value array_struct = Struct({"foo"}, {array});
  EXPECT_FALSE(bag_struct == array_struct);
  EXPECT_TRUE(InternalValue::Equals(bag_struct, array_struct));
  EXPECT_TRUE(InternalValue::Equals(array_struct, bag_struct));
  // Swap bag_struct and array_struct to exercise assignment operator.
  Value tmp;
  tmp = array_struct;
  array_struct = bag_struct;
  bag_struct = tmp;
  EXPECT_FALSE(bag_struct == array_struct);
  EXPECT_TRUE(InternalValue::Equals(bag_struct, array_struct));
  EXPECT_TRUE(InternalValue::Equals(array_struct, bag_struct));
}

TEST_F(ValueTest, NestedArrayBag) {
  std::vector<std::string> table_columns = {"bool_val", "double_val",
                                            "int64_val", "str_val"};
  auto nested_x = StructArray(table_columns,
                              {
                                  {True(), 0.1, int64_t{1}, "1"},
                                  {False(), 0.2, int64_t{2}, "2"},
                              },
                              InternalValue::kIgnoresOrder);
  auto nested_y = StructArray(table_columns,
                              {
                                  {False(), 0.2, int64_t{2}, "2"},
                                  {True(), 0.1, int64_t{1}, "1"},
                              },
                              InternalValue::kIgnoresOrder);
  auto nested_z =
      StructArray(table_columns,
                  {
                      {False(), 0.2, int64_t{2}, "2"},
                      {False(), 0.2, int64_t{2}, "2"},  // duplicate struct
                      {True(), 0.1, int64_t{1}, "1"},
                  },
                  InternalValue::kIgnoresOrder);
  auto array_x =
      StructArray({"col"}, {{nested_x}}, InternalValue::kIgnoresOrder);
  auto array_xx =
      StructArray({"col"}, {{nested_x}}, InternalValue::kIgnoresOrder);
  auto array_y =
      StructArray({"col"}, {{nested_y}}, InternalValue::kIgnoresOrder);
  auto array_z =
      StructArray({"col"}, {{nested_z}}, InternalValue::kIgnoresOrder);
  // Hash code is order-insensitive.
  TestHashEqual(array_x, array_y);
  TestHashEqual(array_x.element(0), array_y.element(0));
  // But operator== is order-sensitive.
  EXPECT_TRUE(array_x == array_xx);
  EXPECT_FALSE(array_x == array_y);
  std::string reason;
  EXPECT_TRUE(InternalValue::Equals(
      array_x, array_y, ValueEqualityCheckOptions{.reason = &reason}))
      << reason;
  EXPECT_TRUE(reason.empty());
  EXPECT_FALSE(InternalValue::Equals(
      array_x, array_z, ValueEqualityCheckOptions{.reason = &reason}));
  EXPECT_FALSE(reason.empty());
  ZETASQL_LOG(INFO) << "Reason: " << reason;
}

// This tests that InternalValue::Equals takes a wholeistic view of
// kIgnoresOrder rather than a purely local view (e.g. b/22417506).
TEST_F(ValueTest, AsymetricNestedArrayBag) {
  auto v1 = Value::Int64(1);
  auto v2 = Value::Int64(2);
  auto vN = Value::MakeNull<int64_t>();
  auto struct_ord1 = Struct({""}, {Array({v1, v2, vN}, kPreservesOrder)});
  auto struct_ord2 = Struct({""}, {Array({v2, vN, v1}, kPreservesOrder)});
  auto struct_unord1 = Struct({""}, {Array({v1, v2, vN}, kIgnoresOrder)});
  auto struct_unord2 = Struct({""}, {Array({vN, v1, v2}, kIgnoresOrder)});

  std::string why = "";

  // Positive tests.
  EXPECT_TRUE(InternalValue::Equals(
      Array({struct_ord1, struct_ord2}), Array({struct_unord1, struct_unord2}),
      ValueEqualityCheckOptions{.float_margin = FloatMargin::UlpMargin(0),
                                .reason = &why}))
      << why;

  EXPECT_TRUE(InternalValue::Equals(
      Array({struct_ord1, struct_ord2}, kPreservesOrder),
      Array({struct_unord1, struct_unord2}, kIgnoresOrder),
      ValueEqualityCheckOptions{.float_margin = FloatMargin::UlpMargin(0),
                                .reason = &why}))
      << why;

  EXPECT_TRUE(InternalValue::Equals(
      Array({struct_unord1, struct_unord2}), Array({struct_ord1, struct_ord2}),
      ValueEqualityCheckOptions{.float_margin = FloatMargin::UlpMargin(0),
                                .reason = &why}))
      << why;

  EXPECT_TRUE(InternalValue::Equals(
      Array({struct_unord1, struct_ord2}), Array({struct_ord1, struct_ord2}),
      ValueEqualityCheckOptions{.float_margin = FloatMargin::UlpMargin(0),
                                .reason = &why}))
      << why;

  EXPECT_TRUE(InternalValue::Equals(
      Array({struct_ord1, struct_ord1}), Array({struct_unord1, struct_unord2}),
      ValueEqualityCheckOptions{.float_margin = FloatMargin::UlpMargin(0),
                                .reason = &why}))
      << why;

  // Negative tests.
  EXPECT_FALSE(InternalValue::Equals(
      Array({struct_ord1, struct_ord1}), Array({struct_ord1, struct_ord2}),
      ValueEqualityCheckOptions{.float_margin = FloatMargin::UlpMargin(0),
                                .reason = &why}))
      << why;
}

// A sanity test to make sure EqualsInternal does not blow up in the case
// where structs have different numbers of fields.
TEST_F(ValueTest, InternalEqualsOnDifferentSizedStructs) {
  auto struct_1 = Struct({""}, {Value::Int64(1)});
  auto struct_2 = Struct({"", ""}, {Value::Int64(1), Value::Int64(1)});

  std::string why = "";
  EXPECT_FALSE(InternalValue::Equals(
      struct_1, struct_2,
      ValueEqualityCheckOptions{.float_margin = FloatMargin::UlpMargin(0),
                                .reason = &why}));
}

TEST_F(ValueTest, Invalid) {
  EXPECT_EQ(false, Value().is_valid());
  EXPECT_DEATH(Value().is_null(), "");
  EXPECT_DEATH(Value().type(), "");
}

TEST_F(ValueTest, NaN) {
  const Value float_nan =
      TestGetSQL(Value::Float(std::numeric_limits<float>::quiet_NaN()));
  const Value double_nan =
      TestGetSQL(Value::Double(std::numeric_limits<double>::quiet_NaN()));

  EXPECT_TRUE(std::isnan(float_nan.float_value()));
  EXPECT_TRUE(std::isnan(double_nan.double_value()));
  EXPECT_EQ("nan", float_nan.DebugString());
  EXPECT_EQ("nan", double_nan.DebugString());
  EXPECT_EQ("Float(nan)", float_nan.FullDebugString());
  EXPECT_EQ("Double(nan)", double_nan.FullDebugString());
  EXPECT_EQ("CAST(\"nan\" AS FLOAT)", float_nan.GetSQL());
  EXPECT_EQ("CAST(\"nan\" AS FLOAT64)", double_nan.GetSQL(PRODUCT_EXTERNAL));
  EXPECT_EQ("CAST(\"nan\" AS DOUBLE)", double_nan.GetSQL(PRODUCT_INTERNAL));
}

TEST_F(ValueTest, Enum) {
  const EnumType* enum_type = GetTestEnumType();
  EXPECT_TRUE(Value::Enum(enum_type, 0).type()->Equals(enum_type));
  EXPECT_TRUE(TestGetSQL(Value::Null(enum_type))
                  .type()
                  ->Equals(Value::Enum(enum_type, 0).type()));
  EXPECT_EQ(0, TestGetSQL(Value::Enum(enum_type, 0)).enum_value());
  EXPECT_EQ(1, TestGetSQL(Value::Enum(enum_type, 1)).enum_value());
  EXPECT_EQ(2, TestGetSQL(Value::Enum(enum_type, 2)).enum_value());
  EXPECT_EQ("TESTENUM2", Enum(enum_type, 2).enum_name());
  EXPECT_FALSE(Value::Enum(enum_type, 12345).is_valid());
  EXPECT_DEATH(Value::Enum(enum_type, 12345).enum_value(), "Not an enum value");
  EXPECT_EQ(2147483647, Value::Enum(enum_type, 2147483647).enum_value());
  EXPECT_EQ(2147483647, Value::Enum(enum_type, 2147483647).ToInt64());
  EXPECT_EQ(2147483647.0, Value::Enum(enum_type, 2147483647).ToDouble());

  // Verifies that we correctly cast the int64_t to int32_t (when the value is in
  // int32_t range without any truncation) before converting it into an enum
  // value.
  EXPECT_EQ(0x2, Value::Enum(enum_type, 0x000000002).enum_value());
  EXPECT_FALSE(Value::Enum(enum_type, 0x100000002).is_valid());

  EXPECT_TRUE(Value::Null(enum_type).is_null());
  EXPECT_FALSE(Value::Enum(enum_type, 0).is_null());
  EXPECT_EQ(Value::Enum(enum_type, 0), Value::Enum(enum_type, 0));
  EXPECT_TRUE(Value::Enum(enum_type, 0).LessThan(Value::Enum(enum_type, 1)));
  EXPECT_FALSE(Value::Enum(enum_type, 1).LessThan(Value::Enum(enum_type, 0)));
  EXPECT_EQ(Enum(enum_type, 1), Enum(enum_type, "TESTENUM1"));
  // Enum names are case sensitive.
  EXPECT_FALSE(Enum(enum_type, "TeStEnUm1").is_valid());
  Value v(Value::Enum(enum_type, 1));
  EXPECT_EQ(v, Value::Enum(enum_type, 1));
  EXPECT_EQ("TESTENUM1", Value::Enum(enum_type, 1).ShortDebugString());
  EXPECT_EQ("Enum<zetasql_test__.TestEnum>(TESTENUM1:1)",
            Value::Enum(enum_type, 1).FullDebugString());
  EXPECT_EQ("NULL", Value::Null(enum_type).ShortDebugString());
  EXPECT_EQ("Enum<zetasql_test__.TestEnum>(NULL)",
            Value::Null(enum_type).FullDebugString());
  // Null enums.
  const EnumType* other_enum_type = GetOtherTestEnumType();
  Value enum_null_1 = Value::Null(enum_type);
  Value enum_null_2 = Value::Null(other_enum_type);
  EXPECT_TRUE(enum_null_1.is_null());
  EXPECT_TRUE(enum_null_2.is_null());
  EXPECT_TRUE(enum_null_1.Equals(enum_null_1));
  EXPECT_TRUE(enum_null_2.Equals(enum_null_2));
  EXPECT_FALSE(enum_null_1.Equals(enum_null_2));
}

TEST_F(ValueTest, StructWithNanAndInf) {
  // Null < NaN < -Inf < 0 < +Inf
  const Value struct_a_null = Struct({"a"}, {Value::NullFloat()});
  const Value struct_a_nan =
      Struct({"a"}, {std::numeric_limits<float>::quiet_NaN()});
  const Value struct_a_neginf =
      Struct({"a"}, {-std::numeric_limits<float>::infinity()});
  const Value struct_a_zero = Struct({"a"}, {Value::Float(0)});
  const Value struct_a_posinf =
      Struct({"a"}, {std::numeric_limits<float>::infinity()});
  const Value struct_b_zero = Struct({"b"}, {Value::Float(0)});

  EXPECT_TRUE(struct_a_null.LessThan(struct_a_nan));
  EXPECT_TRUE(struct_a_null.LessThan(struct_a_neginf));
  EXPECT_TRUE(struct_a_null.LessThan(struct_a_zero));
  EXPECT_TRUE(struct_a_null.LessThan(struct_a_posinf));
  EXPECT_FALSE(struct_a_nan.LessThan(struct_a_null));
  EXPECT_FALSE(struct_a_neginf.LessThan(struct_a_null));
  EXPECT_FALSE(struct_a_zero.LessThan(struct_a_null));
  EXPECT_FALSE(struct_a_posinf.LessThan(struct_a_null));

  EXPECT_TRUE(struct_a_nan.LessThan(struct_a_neginf));
  EXPECT_TRUE(struct_a_nan.LessThan(struct_a_zero));
  EXPECT_TRUE(struct_a_nan.LessThan(struct_a_posinf));
  EXPECT_FALSE(struct_a_neginf.LessThan(struct_a_nan));
  EXPECT_FALSE(struct_a_zero.LessThan(struct_a_nan));
  EXPECT_FALSE(struct_a_posinf.LessThan(struct_a_nan));

  EXPECT_TRUE(struct_a_neginf.LessThan(struct_a_zero));
  EXPECT_TRUE(struct_a_neginf.LessThan(struct_a_posinf));
  EXPECT_FALSE(struct_a_zero.LessThan(struct_a_neginf));
  EXPECT_FALSE(struct_a_posinf.LessThan(struct_a_neginf));

  EXPECT_TRUE(struct_a_zero.LessThan(struct_a_posinf));
  EXPECT_FALSE(struct_a_posinf.LessThan(struct_a_zero));

  const Value struct_b_posinf =
      Struct({"b"}, {Value::Float(std::numeric_limits<float>::infinity())});

  EXPECT_TRUE(struct_b_zero.LessThan(struct_a_posinf));

  // Nested struct with Nan and Infinity
  const Value struct_anan_bnan = Struct(
      {"a", "b"}, {Value::Float(std::numeric_limits<float>::quiet_NaN()),
                   Value::Float(std::numeric_limits<float>::quiet_NaN())});
  const Value struct_anull_bnan = Struct(
      {"a", "b"}, {Value::NullFloat(),
                   Value::Float(std::numeric_limits<float>::quiet_NaN())});
  const Value struct_anan_bnull =
      Struct({"a", "b"}, {Value::Float(std::numeric_limits<float>::quiet_NaN()),
                          Value::NullFloat()});
  EXPECT_TRUE(struct_anull_bnan.LessThan(struct_anan_bnan));
  EXPECT_TRUE(struct_anull_bnan.LessThan(struct_anan_bnull));
  EXPECT_FALSE(struct_anan_bnan.LessThan(struct_anull_bnan));
  EXPECT_FALSE(struct_anan_bnull.LessThan(struct_anull_bnan));

  EXPECT_TRUE(struct_anan_bnull.LessThan(struct_anan_bnan));
  EXPECT_FALSE(struct_anan_bnan.LessThan(struct_anan_bnull));

  // Compare with self, expecting all false.
  EXPECT_FALSE(struct_a_null.LessThan(struct_a_null));
  EXPECT_FALSE(struct_a_nan.LessThan(struct_a_nan));
  EXPECT_FALSE(struct_a_neginf.LessThan(struct_a_neginf));
  EXPECT_FALSE(struct_a_zero.LessThan(struct_a_zero));
  EXPECT_FALSE(struct_a_posinf.LessThan(struct_a_posinf));
  EXPECT_FALSE(struct_anan_bnan.LessThan(struct_anan_bnan));
  EXPECT_FALSE(struct_anull_bnan.LessThan(struct_anull_bnan));
  EXPECT_FALSE(struct_anan_bnull.LessThan(struct_anan_bnull));
}

TEST_F(ValueTest, StructLessThanSimple) {
  const Value struct_a_1 = Struct({"a"}, {1});
  const Value struct_a_2 = Struct({"a"}, {2});
  const Value struct_b_1 = Struct({"b"}, {1});
  const Value struct_ab_11 = Struct({"a", "b"}, {1, 1});
  const Value struct_ab_12 = Struct({"a", "b"}, {1, 2});
  const Value struct_ab_14 = Struct({"a", "b"}, {1, 4});
  const Value struct_ab_23 = Struct({"a", "b"}, {2, 3});
  const Value struct_ab_34 = Struct({"a", "b"}, {3, 4});
  const Value struct_cd_34 = Struct({"c", "d"}, {3, 4});

  // Compare struct with only one field.
  EXPECT_TRUE(struct_a_1.LessThan(struct_a_2));
  EXPECT_FALSE(struct_a_2.LessThan(struct_a_1));
  EXPECT_TRUE(struct_b_1.LessThan(struct_a_2));
  EXPECT_FALSE(struct_a_2.LessThan(struct_b_1));
  EXPECT_FALSE(struct_a_1.LessThan(struct_b_1));
  EXPECT_FALSE(struct_b_1.LessThan(struct_a_1));

  // Compare struct with two fields
  EXPECT_TRUE(struct_ab_12.LessThan(struct_ab_34));
  EXPECT_FALSE(struct_ab_34.LessThan(struct_ab_12));
  EXPECT_TRUE(struct_ab_12.LessThan(struct_cd_34));
  EXPECT_FALSE(struct_cd_34.LessThan(struct_ab_12));
  EXPECT_FALSE(struct_ab_34.LessThan(struct_cd_34));
  EXPECT_FALSE(struct_cd_34.LessThan(struct_ab_34));
  EXPECT_TRUE(struct_ab_14.LessThan(struct_ab_23));
  EXPECT_FALSE(struct_ab_23.LessThan(struct_ab_14));
  EXPECT_TRUE(struct_ab_11.LessThan(struct_ab_12));
  EXPECT_FALSE(struct_ab_12.LessThan(struct_ab_11));

  // Compare two structs with different number of fields, expect false.
  EXPECT_FALSE(struct_a_1.LessThan(struct_ab_34));
  EXPECT_FALSE(struct_ab_34.LessThan(struct_a_1));
}

TEST_F(ValueTest, StructLessThanNullSimple) {
  const Value struct_a_null = Struct({"a"}, {Value::NullInt32()});
  const Value struct_a_1 = Struct({"a"}, {1});

  const Value struct_ab_1null = Struct({"a", "b"}, {1, Value::NullInt32()});
  const Value struct_ab_12 = Struct({"a", "b"}, {1, 2});
  const Value struct_ab_null1 = Struct({"a", "b"}, {Value::NullInt32(), 1});
  const Value struct_ab_null2 = Struct({"a", "b"}, {Value::NullInt32(), 2});

  const Value null_struct_1 =
      Value::Null(MakeStructType({{"a", Int32Type()}, {"b", Int64Type()}}));
  const Value null_struct_2 =
      Value::Null(MakeStructType({{"c", Int32Type()}, {"d", Int64Type()}}));

  // Compare struct with one field.
  EXPECT_TRUE(struct_a_null.LessThan(struct_a_1));
  EXPECT_FALSE(struct_a_1.LessThan(struct_a_null));
  EXPECT_TRUE(struct_ab_null1.LessThan(struct_ab_null2));
  EXPECT_FALSE(struct_ab_null2.LessThan(struct_ab_null1));

  // Compare two nulls.
  EXPECT_FALSE(null_struct_1.LessThan(null_struct_2));
  EXPECT_FALSE(null_struct_2.LessThan(null_struct_1));

  // Compare structs with two fields.
  EXPECT_TRUE(struct_ab_1null.LessThan(struct_ab_12));
  EXPECT_FALSE(struct_ab_12.LessThan(struct_ab_1null));
  EXPECT_TRUE(struct_ab_null1.LessThan(struct_ab_1null));
  EXPECT_FALSE(struct_ab_1null.LessThan(struct_ab_null1));
  EXPECT_TRUE(struct_ab_null1.LessThan(struct_ab_12));
  EXPECT_FALSE(struct_ab_12.LessThan(struct_ab_null1));

  // Compare two structs with different number of fields. Expect all false.
  EXPECT_FALSE(struct_a_null.LessThan(struct_ab_1null));
  EXPECT_FALSE(struct_ab_1null.LessThan(struct_a_null));
  EXPECT_FALSE(struct_a_null.LessThan(struct_ab_null1));
  EXPECT_FALSE(struct_ab_null1.LessThan(struct_a_null));
}

TEST_F(ValueTest, StructLessThanNested) {
  const Value nested_f4 = Struct(
      {"a", "b"}, {1, Struct({"c", "d"}, {2, Struct({"e", "f"}, {3, 4})})});
  const Value nested_f5 = Struct(
      {"a", "b"}, {1, Struct({"c", "d"}, {2, Struct({"e", "f"}, {3, 5})})});
  EXPECT_TRUE(nested_f4.LessThan(nested_f5));
  EXPECT_FALSE(nested_f5.LessThan(nested_f4));

  // Compare nested struct containing nulls.
  const Value nested_anull =
      Struct({"a", "b"}, {Value::NullInt32(),
                          Struct({"c", "d"}, {2, Struct({"e", "f"}, {3, 5})})});
  const Value nested_bnull = Struct(
      {"a", "b"}, {1, Value::Null(MakeStructType(
                          {{"c", Int32Type()},
                           {"d", MakeStructType({{"e", Int32Type()},
                                                 {"f", Int32Type()}})}}))});
  const Value nested_cnull = Struct(
      {"a", "b"},
      {1, Struct({"c", "d"}, {Value::NullInt32(),
                              Struct({"e", "f"}, {3, Value::NullInt32()})})});
  const Value nested_fnull = Struct(
      {"a", "b"},
      {1,
       Struct({"c", "d"}, {2, Struct({"e", "f"}, {3, Value::NullInt32()})})});

  EXPECT_TRUE(nested_anull.LessThan(nested_bnull));
  EXPECT_TRUE(nested_anull.LessThan(nested_cnull));
  EXPECT_TRUE(nested_anull.LessThan(nested_fnull));
  EXPECT_TRUE(nested_bnull.LessThan(nested_cnull));
  EXPECT_TRUE(nested_bnull.LessThan(nested_fnull));
  EXPECT_TRUE(nested_cnull.LessThan(nested_fnull));

  EXPECT_FALSE(nested_bnull.LessThan(nested_anull));
  EXPECT_FALSE(nested_cnull.LessThan(nested_anull));
  EXPECT_FALSE(nested_fnull.LessThan(nested_anull));
  EXPECT_FALSE(nested_cnull.LessThan(nested_bnull));
  EXPECT_FALSE(nested_fnull.LessThan(nested_bnull));
  EXPECT_FALSE(nested_fnull.LessThan(nested_cnull));
}

TEST_F(ValueTest, ArrayLessThan) {
  const std::vector<Value> values = {Value::Null(types::Int64ArrayType()),
                                     values::Int64Array({}),
                                     Array({Value::NullInt64()}),
                                     Array({Value::NullInt64(), Int64(5)}),
                                     Array({Int64(1)}),
                                     Array({Int64(1), Value::NullInt64()}),
                                     Array({Int64(1), Int64(2)}),
                                     Array({Int64(1), Int64(2),
                                            Value::NullInt64()}),
                                     Array({Int64(1), Int64(2), Int64(3)}),
                                     Array({Int64(1), Int64(3), Int64(2)})},
                           Array({Int64(1), Int64(4)});

  for (int i = 0; i < values.size(); ++i) {
    for (int j = 0; j < values.size(); ++j) {
      EXPECT_EQ(i < j, values[i].LessThan(values[j]))
          << "Value1: " << values[i].DebugString()
          << " Value2: " << values[j].DebugString();
    }
  }
}

TEST_F(ValueTest, Proto) {
  TypeFactory type_factory;

  const ProtoType* proto_type = GetTestProtoType();
  zetasql_test__::KitchenSinkPB k;
  absl::Cord bytes = SerializePartialToCord(k);
  // Empty proto.
  EXPECT_EQ(0, bytes.size());
  EXPECT_TRUE(Value::Proto(proto_type, bytes).type()->Equals(proto_type));
  if (ZETASQL_DEBUG_MODE) {
    EXPECT_THROW(Proto(proto_type, k), std::exception);
  }
  zetasql_test__::KitchenSinkPB kvalid;
  kvalid.set_int64_key_1(1);
  kvalid.set_int64_key_2(2);
  EXPECT_EQ("{int64_key_1: 1 int64_key_2: 2}",
            Proto(proto_type, kvalid).ShortDebugString());
  EXPECT_TRUE(Value::Null(proto_type).type()->Equals(proto_type));
  EXPECT_TRUE(Value::Null(proto_type).is_null());
  EXPECT_EQ("Proto<zetasql_test__.KitchenSinkPB>(NULL)",
            Value::Null(proto_type).FullDebugString());
  EXPECT_EQ("NULL", Value::Null(proto_type).ShortDebugString());
  TestGetSQL(Value::Null(proto_type));
  EXPECT_FALSE(Value::Proto(proto_type, bytes).is_null());
  Value proto = TestGetSQL(Proto(proto_type, bytes));
  EXPECT_EQ(bytes, proto.ToCord());
  EXPECT_EQ("Proto<zetasql_test__.KitchenSinkPB>{}", proto.FullDebugString());
  EXPECT_EQ("{}", proto.ShortDebugString());
  // Non-empty proto.
  k.set_int32_val(3);
  bytes = SerializePartialToCord(k);
  EXPECT_EQ(2, bytes.size());
  Value proto1 = TestGetSQL(Proto(proto_type, bytes));
  Value proto2 = proto1;
  TestHashEqual(proto1, proto2);
  EXPECT_EQ(proto1, proto2);
  EXPECT_EQ("Proto<zetasql_test__.KitchenSinkPB>{int32_val: 3\n}",
            proto1.FullDebugString());
  EXPECT_EQ("{int32_val: 3}", proto1.ShortDebugString());
  // Duplicate int32_val tag.
  bytes.Append(bytes);
  Value proto3 = TestGetSQL(Proto(proto_type, bytes));
  // Cord representation is different, but protos compare as equal.
  EXPECT_EQ(2, proto1.ToCord().size());
  EXPECT_EQ(4, proto3.ToCord().size());
  EXPECT_NE(std::string(proto1.ToCord()), std::string(proto3.ToCord()));
  EXPECT_TRUE(proto1.Equals(proto3));
  EXPECT_EQ(proto1, proto3);
  TestHashEqual(proto1, proto3);
  // Null protos.
  const ProtoType* other_proto_type = GetOtherTestProtoType();
  Value proto_null_1 = Value::Null(proto_type);
  Value proto_null_2 = Value::Null(other_proto_type);
  EXPECT_TRUE(proto_null_1.is_null());
  EXPECT_TRUE(proto_null_2.is_null());
  EXPECT_TRUE(proto_null_1.Equals(proto_null_1));
  EXPECT_TRUE(proto_null_2.Equals(proto_null_2));
  EXPECT_FALSE(proto_null_1.Equals(proto_null_2));
  // Same human readable value despite duplicated tag.
  EXPECT_EQ("{int32_val: 3}", proto3.ShortDebugString());
  // Proto with field in NaN value.
  kvalid.set_double_val(std::numeric_limits<double>::quiet_NaN());
  Value proto_with_nan_1 = Proto(proto_type, kvalid);
  kvalid.set_double_val(-std::numeric_limits<double>::quiet_NaN());
  Value proto_with_nan_2 = Proto(proto_type, kvalid);
  EXPECT_NE(std::string(proto_with_nan_1.ToCord()),
            std::string(proto_with_nan_2.ToCord()));
  EXPECT_TRUE(proto_with_nan_1.Equals(proto_with_nan_2));

  // Test with a proto with a duplicate optional field.  The last one takes
  // precedence.
  k.set_int32_val(7);
  absl::Cord bytes4 = SerializePartialToCord(k);
  // Now we have two duplicate 3 values followed by a 7.
  bytes.Append(bytes4);
  Value proto4 = TestGetSQL(Proto(proto_type, bytes));
  EXPECT_EQ(6, proto4.ToCord().size());
  EXPECT_FALSE(proto1.Equals(proto4));
  EXPECT_NE(proto1, proto4);
  EXPECT_EQ("{int32_val: 7}", proto4.ShortDebugString());
  Value proto5 = TestGetSQL(Proto(proto_type, bytes4));
  EXPECT_TRUE(proto4.Equals(proto5));
  EXPECT_EQ(proto4, proto5);
  TestHashEqual(proto4, proto5);
  EXPECT_GT(proto4.ToCord().size(), proto5.ToCord().size());

  // One example where we get a reason out from the proto MessageDifferencer.
  std::string reason;
  EXPECT_FALSE(InternalValue::Equals(
      proto1, proto4, ValueEqualityCheckOptions{.reason = &reason}));
  // We test that get a reason but don't compare the actual reason string.
  EXPECT_FALSE(reason.empty());
  ZETASQL_LOG(INFO) << "Reason: " << reason;

  // Proto with an unknown tag.
  bytes = "";  // clear bytes;
  std::string str_bytes;
  {
    google::protobuf::io::StringOutputStream cord_stream(&str_bytes);
    google::protobuf::io::CodedOutputStream out(&cord_stream);
    out.WriteVarint32(
        WireFormatLite::MakeTag(150775, WireFormatLite::WIRETYPE_VARINT));
    out.WriteVarint32(57);
  }
  bytes = absl::Cord(str_bytes);
  EXPECT_EQ("{150775: 57}",
            TestGetSQL(Proto(proto_type, bytes)).ShortDebugString());

  // Invalid proto contents is accepted without validation, but renders as
  // <unparseable>.
  {
    google::protobuf::io::StringOutputStream cord_stream(&str_bytes);
    google::protobuf::io::CodedOutputStream out(&cord_stream);
    out.WriteVarint32(
        WireFormatLite::MakeTag(150776, WireFormatLite::WIRETYPE_END_GROUP));
  }
  bytes = absl::Cord(str_bytes);
  EXPECT_EQ("Proto<zetasql_test__.KitchenSinkPB>{<unparseable>}",
            Proto(proto_type, bytes).FullDebugString());
  google::protobuf::DynamicMessageFactory message_factory;
  std::unique_ptr<google::protobuf::Message> message(
      Proto(proto_type, bytes).ToMessage(&message_factory));
  std::string text_format;
  google::protobuf::TextFormat::PrintToString(*message, &text_format);
  EXPECT_EQ("150775: 57\n", text_format);

  // Protos with the same tags in different order.
  k.Clear();
  k.set_int32_val(5);
  std::string tag1;
  ASSERT_TRUE(k.SerializePartialToString(&tag1));
  k.Clear();
  k.set_string_val("abc");
  std::string tag2;
  ASSERT_TRUE(k.SerializePartialToString(&tag2));
  absl::Cord tag_1_2_bytes = absl::Cord(absl::StrCat(tag1, tag2));
  absl::Cord tag_2_1_bytes = absl::Cord(absl::StrCat(tag2, tag1));

  Value proto_1_2 = TestGetSQL(Proto(proto_type, tag_1_2_bytes));
  Value proto_2_1 = TestGetSQL(Proto(proto_type, tag_2_1_bytes));
  EXPECT_EQ(proto_1_2, proto_2_1);
  TestHashEqual(proto_1_2, proto_2_1);
  EXPECT_EQ(
      "Proto<zetasql_test__.KitchenSinkPB>{int32_val: 5\n"
      "string_val: \"abc\"\n}",
      proto_2_1.FullDebugString());
  EXPECT_EQ(proto_1_2.FullDebugString(), proto_2_1.FullDebugString());
  EXPECT_NE(proto_1_2.ToCord(), proto_2_1.ToCord());

  // Test equality and hash codes when one message explicitly sets a field to
  // the default value and the other message leaves the field unset.
  k.Clear();
  k.set_int64_key_1(1);
  k.set_int64_key_2(2);
  Value unset_value = Proto(proto_type, k);
  k.set_bool_val(false);
  Value set_value = Proto(proto_type, k);
  EXPECT_NE(set_value, unset_value);
  EXPECT_NE(set_value.FullDebugString(), unset_value.FullDebugString());
  EXPECT_EQ(
      "Proto<zetasql_test__.KitchenSinkPB>{int64_key_1: 1\n"
      "int64_key_2: 2\nbool_val: false\n}",
      set_value.FullDebugString());
  EXPECT_EQ(
      "Proto<zetasql_test__.KitchenSinkPB>{int64_key_1: 1\n"
      "int64_key_2: 2\n}",
      unset_value.FullDebugString());
  EXPECT_FALSE(unset_value.Equals(set_value));
  TestHashEqual(set_value, unset_value);

  const ProtoType* proto3_type;
  ZETASQL_ASSERT_OK(type_factory.MakeProtoType(
      google::protobuf::Int32Value::descriptor(), &proto3_type));

  std::string result;
  {
    ::google::protobuf::io::StringOutputStream string_stream(&result);
    ::google::protobuf::io::CodedOutputStream output_stream(&string_stream);
    WireFormatLite::WriteInt32(/*field_number=*/1, /*value=*/0, &output_stream);
  }
  google::protobuf::Int32Value unset_proto3;
  absl::Cord result_bytes = absl::Cord(result);
  set_value = Value::Proto(proto3_type, result_bytes);
  unset_value = Value::Proto(proto3_type, SerializeToCord(unset_proto3));
  EXPECT_TRUE(set_value.Equals(unset_value));
  TestHashEqual(set_value, unset_value);
}

TEST_F(ValueTest, ClassAndProtoSize) {
  EXPECT_EQ(16, sizeof(Value))
      << "The size of Value class has changed, please also update the proto "
      << "and serialization code if you added/removed fields in it.";
      EXPECT_EQ(23, ValueProto::descriptor()->field_count())
      << "The number of fields in ValueProto has changed, please also update "
      << "the serialization code accordingly.";
  EXPECT_EQ(1, ValueProto::Array::descriptor()->field_count())
      << "The number of fields in ValueProto::Array has changed, please also "
      << "update the serialization code accordingly.";
  EXPECT_EQ(1, ValueProto::Struct::descriptor()->field_count())
      << "The number of fields in ValueProto::Struct has changed, please also "
      << "update the serialization code accordingly.";
}

TEST_F(ValueTest, HashSet) {
  absl::flat_hash_set<Value> s;
  EXPECT_EQ(true, s.insert(Int64(1)).second);
  EXPECT_EQ(false, s.insert(Int64(1)).second);
  EXPECT_EQ(true, s.insert(NullInt64()).second);
  EXPECT_EQ(false, s.insert(NullInt64()).second);

  EXPECT_EQ(true, s.insert(Bool(true)).second);
  EXPECT_EQ(false, s.insert(Bool(true)).second);
  EXPECT_EQ(true, s.insert(NullBool()).second);
  EXPECT_EQ(false, s.insert(NullBool()).second);

  EXPECT_EQ(true, s.insert(Double(1.3)).second);
  EXPECT_EQ(false, s.insert(Double(1.3)).second);
  EXPECT_EQ(true, s.insert(NullDouble()).second);
  EXPECT_EQ(false, s.insert(NullDouble()).second);

  EXPECT_EQ(true, s.insert(String("foo")).second);
  EXPECT_EQ(false, s.insert(String("foo")).second);
  EXPECT_EQ(true, s.insert(NullString()).second);
  EXPECT_EQ(false, s.insert(NullString()).second);

  const EnumType* enum_type = GetTestEnumType();
  EXPECT_EQ(true, s.insert(Enum(enum_type, 1)).second);
  EXPECT_EQ(false, s.insert(Enum(enum_type, 1)).second);
  EXPECT_EQ(true, s.insert(Null(enum_type)).second);
  EXPECT_EQ(false, s.insert(Null(enum_type)).second);

  const ProtoType* proto_type = GetTestProtoType();
  absl::Cord bytes("xyz");
  EXPECT_EQ(true, s.insert(Proto(proto_type, bytes)).second);
  EXPECT_EQ(false, s.insert(Proto(proto_type, bytes)).second);
  EXPECT_EQ(true, s.insert(Null(proto_type)).second);
  EXPECT_EQ(false, s.insert(Null(proto_type)).second);

  std::vector<Value> values = {Int64(1), Int64(2), Int64(1), NullInt64(),
                               NullInt64()};
  Value bag1 = InternalValue::ArrayChecked(MakeArrayType(Int64Type()),
                                           InternalValue::kIgnoresOrder,
                                           std::move(values));

  values = {Int64(1), NullInt64(), Int64(1), NullInt64(), Int64(2)};
  Value bag2 = InternalValue::ArrayChecked(MakeArrayType(Int64Type()),
                                           InternalValue::kIgnoresOrder,
                                           std::move(values));

  values = {Int64(1), NullInt64(), Int64(1), NullInt64(), Int64(2)};
  Value array1 = InternalValue::ArrayChecked(MakeArrayType(Int64Type()),
                                             InternalValue::kPreservesOrder,
                                             std::move(values));

  values = {Int64(1), NullInt64(), Int64(1), NullInt64(), Int64(2)};
  Value array2 = InternalValue::ArrayChecked(MakeArrayType(Int64Type()),
                                             InternalValue::kPreservesOrder,
                                             std::move(values));

  EXPECT_EQ(true, s.insert(bag1).second);
  EXPECT_EQ(false, s.insert(bag1).second);
  EXPECT_EQ(true, s.insert(bag2).second);
  EXPECT_EQ(false, s.insert(bag2).second);

  EXPECT_EQ(false, s.insert(array1).second);
  EXPECT_EQ(false, s.insert(array2).second);
}

TEST_F(ValueTest, TimestampBounds) {
  const time_t lower = static_cast<time_t>(types::kTimestampSecondsMin);
  const time_t upper = static_cast<time_t>(types::kTimestampSecondsMax);
  setenv("TZ", "UTC", 1);
  EXPECT_EQ(std::string("Sat Jan  1 00:00:00 1678\n"), ctime(&lower));
  EXPECT_EQ(std::string("Tue Dec 31 23:59:59 2261\n"), ctime(&upper));
  // TODO Add similar tests that other timestamp bounds and date bounds
  // match these, once we have ToString functions for those types.
}

TEST_F(ValueTest, ValueConstructor) {
  const char chars[] = "a";
  absl::string_view pc(chars);
  ValueConstructor int32_val = {1};
  ValueConstructor uint32_val = {1u};
  ValueConstructor int64_val = {int64_t{1}};
  ValueConstructor uint64_val = {1ull};
  ValueConstructor bool_val = {True()};
  ValueConstructor float_val = {4.0F};
  ValueConstructor double_val = {3.5};
  ValueConstructor string_val = {"a"};
  ValueConstructor string_val2 = {chars};
  ValueConstructor string_val3 = {pc};

  EXPECT_EQ(Int32(1), int32_val.get());
  EXPECT_EQ(Uint32(1), uint32_val.get());
  EXPECT_EQ(Int64(1), int64_val.get());
  EXPECT_EQ(Uint64(1), uint64_val.get());
  EXPECT_EQ(True(), bool_val.get());
  EXPECT_EQ(Float(4), float_val.get());
  EXPECT_EQ(Double(3.5), double_val.get());
  EXPECT_EQ(String("a"), string_val.get());
  EXPECT_EQ(String("a"), string_val2.get());
  EXPECT_EQ(String("a"), string_val3.get());

  std::vector<Value> l = ValueConstructor::ToValues(
      {1, 1u, int64_t{1}, 1ull, True(), 4.0F, 3.5, "a"});
  EXPECT_EQ(Int32(1), l[0]);
  EXPECT_EQ(Uint32(1), l[1]);
  EXPECT_EQ(Int64(1), l[2]);
  EXPECT_EQ(Uint64(1), l[3]);
  EXPECT_EQ(True(), l[4]);
  EXPECT_EQ(Float(4), l[5]);
  EXPECT_EQ(Double(3.5), l[6]);
  EXPECT_EQ(String("a"), l[7]);
}

TEST_F(ValueTest, FormatTestArrayWrapping) {
  // Array that should Format on one line.
  EXPECT_EQ(Array({1, 2, 3, 4}).Format(), "ARRAY<INT32>[1, 2, 3, 4]");
  // Array that triggers wrap due to long element
  EXPECT_EQ(Array({"abcdefghijklmnopqrstuvw", "x", "y", "z"}).Format(),
            R"(ARRAY<STRING>[
  "abcdefghijklmnopqrstuvw",
  "x",
  "y",
  "z"
])");
  // Array that triggers wrap because its long.
  EXPECT_EQ(Array({"h", "i", "j", "k", "l", "m", "n", "p", "p", "q", "r", "s",
                   "t", "u", "v", "w", "x", "y", "z"})
                .Format(),
            R"(ARRAY<STRING>["h",
              "i",
              "j",
              "k",
              "l",
              "m",
              "n",
              "p",
              "p",
              "q",
              "r",
              "s",
              "t",
              "u",
              "v",
              "w",
              "x",
              "y",
              "z"])");
}

TEST_F(ValueTest, FormatTestStructWrapping) {
  // Struct that should Format on one line.
  EXPECT_EQ(Struct({"a", "b"}, {1, 2}).Format(),
            R"(STRUCT<a INT32, b INT32>{1, 2})");
  // Struct that triggers wrap due to many fields
  EXPECT_EQ(
      Struct({"a", "b", "c", "d", "e", "f", "g"}, {1, 2, 3, 4, 5, 6, 7})
          .Format(),
      R"(STRUCT<a INT32, b INT32, c INT32, d INT32, e INT32, f INT32, g INT32>{
  1,
  2,
  3,
  4,
  5,
  6,
  7
})");
}

TEST_F(ValueTest, FormatTestSanitization) {
  // Struct type containing dollar signs
  EXPECT_EQ(Struct({"$col1", "col2$", "$", "$$", "$$$", "$0$1$2", "$$0", "$$$0",
                    "$$$$0"},
                   {"$val1", "val2$", "$", "$$", "$$$", "$0$1$2", "$$0", "$$$0",
                    "$$$$0"})
                .Format(),
            R"(STRUCT<$col1 STRING,
       col2$ STRING,
       $ STRING,
       $$ STRING,
       $$$ STRING,
       $0$1$2 STRING,
       $$0 STRING,
       $$$0 STRING,
       $$$$0 STRING>{
  "$val1",
  "val2$",
  "$",
  "$$",
  "$$$",
  "$0$1$2",
  "$$0",
  "$$$0",
  "$$$$0"
})");
  // Array type containing dollar signs
  EXPECT_EQ(StructArray({"$col1", "col2$", "$", "$$", "$$$", "$0$1$2", "$$0",
                         "$$$0", "$$$$0"},
                        {{"$val1", "val2$", "$", "$$", "$$$", "$0$1$2", "$$0",
                          "$$$0", "$$$$0"}})
                .Format(),
            R"(ARRAY<STRUCT<$col1 STRING,
             col2$ STRING,
             $ STRING,
             $$ STRING,
             $$$ STRING,
             $0$1$2 STRING,
             $$0 STRING,
             $$$0 STRING,
             $$$$0 STRING>>[
  {"$val1", "val2$", "$", "$$", "$$$", "$0$1$2", "$$0", "$$$0", "$$$$0"}
])");
  // Array type containing dollar signs and long enough to trigger wrapping
  // after the multi-line array type.
  EXPECT_EQ(StructArray({"$col1", "col2$", "$", "$$", "$$$", "$0$1$2", "$$0",
                         "$$$0", "$$$$0", "extralong$typename"},
                        {{"$val1", "val2$", "$", "$$", "$$$", "$0$1$2", "$$0",
                          "$$$0", "$$$$0", "extralong$value"}})
                .Format(),
            R"(ARRAY<STRUCT<
        $col1 STRING,
        col2$ STRING,
        $ STRING,
        $$ STRING,
        $$$ STRING,
        $0$1$2 STRING,
        $$0 STRING,
        $$$0 STRING,
        $$$$0 STRING,
        extralong$typename STRING
      >>
[{"$val1",
  "val2$",
  "$",
  "$$",
  "$$$",
  "$0$1$2",
  "$$0",
  "$$$0",
  "$$$$0",
  "extralong$value"}])");
}

TEST_F(ValueTest, FormatTestTypeTruncation) {
  Value v = Array({Struct({"", ""}, {Array({2, 1}), Array({"bar", "foo"})})});
  // The type of an array should be printed down to the next level of arrays.
  EXPECT_EQ(v.Format(), R"(ARRAY<STRUCT<ARRAY<>, ARRAY<>>>[
  {
    ARRAY<INT32>[2, 1],
    ARRAY<STRING>["bar", "foo"]
  }
])");

  // The full type of a empty array should be printed.
  EXPECT_EQ(Value::EmptyArray(v.type()->AsArray()).Format(),
            R"(ARRAY<STRUCT<ARRAY<INT32>, ARRAY<STRING>>>[])");

  // The full type of a null array should be printed.
  EXPECT_EQ(Value::Null(v.type()->AsArray()).Format(),
            R"(ARRAY<STRUCT<ARRAY<INT32>, ARRAY<STRING>>>(NULL))");
}

TEST_F(ValueTest, FormatWrapAfterMultiLineArrayType) {
  // If an array type is broken over several lines, the opening square bracket
  // moves to its own line and the
  Value v = Array({Struct({"struct_field1", "struct_field2", "struct_field3",
                           "struct_field4"},
                          {"11", "12", "13", "14"}),
                   Struct({"struct_field1", "struct_field2", "struct_field3",
                           "struct_field4"},
                          {"21", "22", "23", "24"})});

  // The type of an array should be printed down to the next level of arrays.
  EXPECT_EQ(v.Format(), R"(ARRAY<STRUCT<struct_field1 STRING,
             struct_field2 STRING,
             struct_field3 STRING,
             struct_field4 STRING>>
[
  {"11", "12", "13", "14"},
  {"21", "22", "23", "24"}
])");
}

TEST_F(ValueTest, ProtoFormatTest) {
  zetasql_test__::KitchenSinkPB k;
  k.set_int64_key_1(1);
  k.set_int64_key_2(2);
  k.set_int32_val(3);
  // Empty proto.
  absl::Cord bytes = SerializePartialToCord(k);

  const ProtoType* proto_type = GetTestProtoType();
  EXPECT_EQ(Struct({"p", "i"}, {Proto(proto_type, bytes), 1}).Format(),
            R"(STRUCT<
  p PROTO<zetasql_test__.KitchenSinkPB>,
  i INT32
>{{
    int64_key_1: 1
    int64_key_2: 2
    int32_val: 3
  },
  1})");
}

// Test that proto value equality still works as expected when the proto
// descriptors come from different pools.
TEST_F(ValueTest, EquivalentProtos) {
  // Build a second DescriptorPool with copies of all types in the default pool.
  google::protobuf::DescriptorPoolDatabase database(
      *google::protobuf::DescriptorPool::generated_pool());
  google::protobuf::DescriptorPool alt_pool(&database);

  TypeFactory type_factory;

  const ProtoType* proto_type;
  const ProtoType* alt_proto_type;
  ZETASQL_ASSERT_OK(type_factory.MakeProtoType(
      zetasql_test__::TestExtraPB::descriptor(), &proto_type));
  ZETASQL_ASSERT_OK(type_factory.MakeProtoType(
      alt_pool.FindMessageTypeByName("zetasql_test__.TestExtraPB"),
      &alt_proto_type));

  EXPECT_FALSE(proto_type->Equals(alt_proto_type));
  EXPECT_TRUE(proto_type->Equivalent(alt_proto_type));

  zetasql_test__::TestExtraPB proto_value;
  proto_value.set_int32_val1(5);
  absl::Cord bytes = absl::Cord(proto_value.SerializeAsString());
  Value value1 = Value::Proto(proto_type, bytes);
  Value value2 = Value::Proto(alt_proto_type, bytes);
  EXPECT_TRUE(value1.Equals(value2));

  proto_value.set_int32_val2(6);
  bytes = proto_value.SerializeAsString();
  value2 = Value::Proto(alt_proto_type, bytes);

  EXPECT_FALSE(value1.Equals(value2));

  // Do the same test with a proto enum type.
  const EnumType* enum_type;
  const EnumType* alt_enum_type;
  ZETASQL_ASSERT_OK(type_factory.MakeEnumType(zetasql_test__::TestEnum_descriptor(),
                                      &enum_type));
  ZETASQL_ASSERT_OK(type_factory.MakeEnumType(
      alt_pool.FindEnumTypeByName("zetasql_test__.TestEnum"), &alt_enum_type));

  EXPECT_FALSE(enum_type->Equals(alt_enum_type));
  EXPECT_TRUE(enum_type->Equivalent(alt_enum_type));

  EXPECT_TRUE(Value::Enum(enum_type, 1).Equals(Value::Enum(alt_enum_type, 1)));
  EXPECT_FALSE(Value::Enum(enum_type, 1).Equals(Value::Enum(alt_enum_type, 2)));

  // Enums also support LessThan, which should also work with types from
  // different pools.
  EXPECT_FALSE(
      Value::Enum(enum_type, 1).LessThan(Value::Enum(alt_enum_type, 1)));
  EXPECT_TRUE(
      Value::Enum(enum_type, 1).LessThan(Value::Enum(alt_enum_type, 2)));
}

static std::string TestParseInteger(const std::string& input) {
  Value value;
  if (!Value::ParseInteger(input, &value)) {
    return "ERROR";
  } else {
    return value.FullDebugString();
  }
}

TEST_F(ValueTest, ParseInteger) {
  EXPECT_EQ("ERROR", TestParseInteger(""));
  EXPECT_EQ("ERROR", TestParseInteger(" "));
  EXPECT_EQ("ERROR", TestParseInteger("    "));
  EXPECT_EQ("ERROR", TestParseInteger("abc"));
  EXPECT_EQ("ERROR", TestParseInteger("0x"));
  EXPECT_EQ("ERROR", TestParseInteger("0xaz"));
  EXPECT_EQ("ERROR", TestParseInteger("1."));
  EXPECT_EQ("ERROR", TestParseInteger("1.5"));
  EXPECT_EQ("ERROR", TestParseInteger("123x"));
  EXPECT_EQ("Int64(0)", TestParseInteger("0"));
  EXPECT_EQ("Int64(123)", TestParseInteger("123"));
  EXPECT_EQ("Int64(-123)", TestParseInteger("-123"));

  EXPECT_EQ("Int64(291)", TestParseInteger("0x123"));
  EXPECT_EQ("Int64(-291)", TestParseInteger("-0x123"));
  EXPECT_EQ("Int64(109506)", TestParseInteger("0x1aBc2"));
  EXPECT_EQ("Int64(-109506)", TestParseInteger("-0X1aBc2"));
  EXPECT_EQ("Int64(109506)", TestParseInteger("+0X1aBc2"));
  EXPECT_EQ("ERROR", TestParseInteger("- 0X1aBc2"));
  EXPECT_EQ("ERROR", TestParseInteger("-+0X1aBc2"));

  EXPECT_EQ("Int64(11)", TestParseInteger("011"));
  EXPECT_EQ("Int64(-11)", TestParseInteger("-011"));
  EXPECT_EQ("Int64(11)", TestParseInteger("+011"));
  EXPECT_EQ("ERROR", TestParseInteger("- 011"));

  EXPECT_EQ("Int64(10)", TestParseInteger(" 10"));
  EXPECT_EQ("Int64(10)", TestParseInteger("10 "));
  EXPECT_EQ("Int64(10)", TestParseInteger("    10   "));
  EXPECT_EQ("Int64(-10)", TestParseInteger("   -10   "));
  EXPECT_EQ("ERROR", TestParseInteger("   - 10   "));

  EXPECT_EQ("Int64(10)", TestParseInteger("0XA"));
  EXPECT_EQ("Int64(10)", TestParseInteger("0XA   "));
  EXPECT_EQ("Int64(10)", TestParseInteger(" 0XA"));
  EXPECT_EQ("Int64(-10)", TestParseInteger("-0XA"));
  EXPECT_EQ("Int64(-10)", TestParseInteger("   -0XA   "));
  EXPECT_EQ("ERROR", TestParseInteger("   - 0XA   "));

  EXPECT_EQ("Int64(4294967295)", TestParseInteger("4294967295"));
  EXPECT_EQ("Int64(4294967296)", TestParseInteger("4294967296"));
  EXPECT_EQ("Int64(-4294967296)", TestParseInteger("-4294967296"));

  // Near std::numeric_limits<int64_t>::max().
  EXPECT_EQ("Int64(9223372036854775807)",
            TestParseInteger("9223372036854775807"));
  EXPECT_EQ("Uint64(9223372036854775808)",
            TestParseInteger("9223372036854775808"));
  EXPECT_EQ("Int64(9223372036854775807)",
            TestParseInteger("0x7FFFFFFFFFFFFFFF"));
  EXPECT_EQ("Uint64(9223372036854775808)",
            TestParseInteger("0x8000000000000000"));
  EXPECT_EQ("Uint64(18446744073709551615)",
            TestParseInteger("0xFFFFFFFFFFFFFFFF"));

  // Near std::numeric_limits<int64_t>::lowest().
  EXPECT_EQ("Int64(-9223372036854775807)",
            TestParseInteger("-9223372036854775807"));
  EXPECT_EQ("Int64(-9223372036854775808)",
            TestParseInteger("-9223372036854775808"));
  EXPECT_EQ("Int64(-9223372036854775807)",
            TestParseInteger("-0x7FFFFFFFFFFFFFFF"));
  EXPECT_EQ("ERROR", TestParseInteger("-9223372036854775809"));
  // Too many hex digits.
  EXPECT_EQ("ERROR", TestParseInteger("0xFFFFFFFFFFFFFFFABCD"));

  // Near std::numeric_limits<uint64_t>::max().
  EXPECT_EQ("Uint64(18446744073709551615)",
            TestParseInteger("18446744073709551615"));
  EXPECT_EQ("ERROR", TestParseInteger("18446744073709551616"));
  EXPECT_EQ("Uint64(18446744073709551615)",
            TestParseInteger("0xFFFFFFFFFFFFFFFF"));
  EXPECT_EQ("ERROR", TestParseInteger("0x10000000000000000"));
}

void ValueTest::TestParameterizedValueAfterReleaseOfTypeFactory(
    bool keep_type_alive_while_referenced_from_value) {
  SCOPED_TRACE(absl::StrCat("keep_type_alive_while_referenced_from_value=",
                            keep_type_alive_while_referenced_from_value));

  const internal::TypeStore* store = nullptr;
  Value proto_value;
  {
    Value enum_value, struct_value, array_value;
    {
      TypeFactoryOptions options;
      options.keep_alive_while_referenced_from_value =
          keep_type_alive_while_referenced_from_value;
      TypeFactory type_factory(options);
      store = internal::TypeStoreHelper::GetTypeStore(&type_factory);

      // Proto value
      const ProtoType* proto_type;
      ZETASQL_ASSERT_OK(type_factory.MakeProtoType(
          zetasql_test__::TestExtraPB::descriptor(), &proto_type));

      zetasql_test__::TestExtraPB proto_msg;
      proto_msg.set_int32_val1(5);
      absl::Cord bytes = absl::Cord(proto_msg.SerializeAsString());
      proto_value = Value::Proto(proto_type, bytes);

      // Enum value
      const EnumType* enum_type;
      const google::protobuf::EnumDescriptor* enum_descriptor =
          zetasql_test__::TestEnum_descriptor();
      ZETASQL_ASSERT_OK(type_factory.MakeEnumType(enum_descriptor, &enum_type));
      enum_value = values::Enum(enum_type, 1);

      // Struct value
      const StructType* struct_type;
      ZETASQL_ASSERT_OK(type_factory.MakeStructType(
          {{"f1", proto_type}, {"f2", enum_type}}, &struct_type));
      struct_value = values::Struct(struct_type, {proto_value, enum_value});

      // Array value
      const ArrayType* array_type;
      ZETASQL_ASSERT_OK(type_factory.MakeArrayType(struct_type, &array_type));
      array_value = values::Array(array_type, {struct_value});
#ifdef NDEBUG
      if (!keep_type_alive_while_referenced_from_value) {
        ASSERT_EQ(internal::TypeStoreHelper::Test_GetRefCount(store), 1);

        // We don't keep track of references under release mode (NDEBUG) when
        // keep_alive_while_referenced_from_value is disabled. Thus, just
        // emulate an error message.
        ZETASQL_LOG(FATAL) << "Type factory is released while there are still some "
                      "objects that reference it";
      }
#endif
      // TypeFactory has been destroyed at this point.
    }

    // We expect 7 values currently exists: proto_value, enum_value,
    // struct_value, array_value, 2 field values in struct_value and 1 element
    // in array_value. Since TypeFactory is gone, we should have 7 references.
    EXPECT_EQ(internal::TypeStoreHelper::Test_GetRefCount(store), 7);

    EXPECT_EQ(proto_value.DebugString(), "{int32_val1: 5}");
    EXPECT_EQ(enum_value.DebugString(), "TESTENUM1");
    EXPECT_EQ(struct_value.DebugString(), "{f1:{int32_val1: 5}, f2:TESTENUM1}");
    EXPECT_EQ(array_value.DebugString(),
              "[{f1:{int32_val1: 5}, f2:TESTENUM1}]");
  }

  // Values enum_value, struct_value, array_value have been gone at this point
  // and only proto_value still alive - thus we should have a single reference.
  EXPECT_EQ(internal::TypeStoreHelper::Test_GetRefCount(store), 1);
}

TEST_F(ValueTest, ValueIsLifeAfterTypeFactoryRelease) {
  EXPECT_DEATH(TestParameterizedValueAfterReleaseOfTypeFactory(
                   /*keep_type_alive_while_referenced_from_value=*/false),
               "Type factory is released while there are still some objects "
               "that reference it");

  TestParameterizedValueAfterReleaseOfTypeFactory(
      /*keep_type_alive_while_referenced_from_value=*/true);
}

TEST_F(ValueTest, PhysicalByteSize) {
  // Coverage messes with the object sizes, so skip it.
  if (std::getenv("BAZEL_CC_COVERAGE_TOOL") != nullptr) return;

  // Null values.
  EXPECT_EQ(sizeof(Value), Value::NullBool().physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::NullBytes().physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::NullDate().physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::NullDatetime().physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::NullDouble().physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::NullFloat().physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::NullInt32().physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::NullInt64().physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::NullNumeric().physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::NullString().physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::NullTime().physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::NullTimestamp().physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::NullUint32().physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::NullUint64().physical_byte_size());

  // Constant sized types.
  auto bool_value = Value::Bool(true);
  auto date_value = Value::Date(1);
  auto int_value = Value::Int32(1);
  EXPECT_EQ(sizeof(Value), bool_value.physical_byte_size());
  EXPECT_EQ(sizeof(Value), date_value.physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::DatetimeFromPacked64Micros(0X1F7EA704E5181CD)
                               .physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::Double(1.0).physical_byte_size());
  EXPECT_EQ(sizeof(Value),
            Value::Enum(GetTestEnumType(), 0).physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::Float(1.0).physical_byte_size());
  EXPECT_EQ(sizeof(Value), int_value.physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::Int64(1).physical_byte_size());
  EXPECT_EQ(48, Value::Numeric(NumericValue::FromDouble(1.0).value())
                    .physical_byte_size());
  EXPECT_EQ(sizeof(Value),
            Value::Time(TimeValue::FromPacked64Micros(int64_t{0xD38F1E240}))
                .physical_byte_size());
  EXPECT_EQ(sizeof(Value),
            Value::TimestampFromUnixMicros(1).physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::Uint32(1).physical_byte_size());
  EXPECT_EQ(sizeof(Value), Value::Uint64(1).physical_byte_size());

  // Variable sized types.
  uint64_t empty_array_size = values::Int64Array({}).physical_byte_size();
  EXPECT_EQ(sizeof(Value) + sizeof(Value::TypedList), empty_array_size);
  EXPECT_EQ(empty_array_size + Value::Int64(1).physical_byte_size(),
            values::Int64Array({1}).physical_byte_size());
  EXPECT_EQ(empty_array_size + 3 * Value::Int64(1).physical_byte_size(),
            values::Int64Array({1, 2, 3}).physical_byte_size());

  EXPECT_EQ(sizeof(Value) + sizeof(internal::StringRef),
            Value::Bytes("").physical_byte_size());
  EXPECT_EQ(sizeof(Value) + sizeof(internal::StringRef) + 3 * sizeof(char),
            Value::Bytes("abc").physical_byte_size());
  // Strings should be consistent with bytes.
  EXPECT_EQ(Value::Bytes("").physical_byte_size(),
            Value::String("").physical_byte_size());
  EXPECT_EQ(Value::Bytes("abc").physical_byte_size(),
            Value::String("abc").physical_byte_size());

  // Structs should be consistent with their contents.
  EXPECT_EQ(sizeof(Value) + sizeof(Value::TypedList),
            Struct({}, {}).physical_byte_size());
  EXPECT_EQ(sizeof(Value) + sizeof(Value::TypedList) +
                bool_value.physical_byte_size() +
                date_value.physical_byte_size(),
            Struct({"b", "d"}, {bool_value, date_value}).physical_byte_size());
}

// Roundtrips Value through ValueProto and back.
static void SerializeDeserialize(const Value& value) {
  ValueProto value_proto;
  ZETASQL_ASSERT_OK(value.Serialize(&value_proto)) << value.DebugString();
  auto status_or_value = Value::Deserialize(value_proto, value.type());
  ZETASQL_ASSERT_OK(status_or_value.status());
  EXPECT_EQ(value, status_or_value.value()) << "\nSerialized value:\n"
                                            << value_proto.DebugString();
}

// Roundtrips ValueProto through Value and back.
static void DeserializeSerialize(const std::string& value_proto_str,
                                 const Type* type) {
  ValueProto value_proto;
  ZETASQL_CHECK(google::protobuf::TextFormat::ParseFromString(value_proto_str, &value_proto))
      << value_proto_str;
  auto status_or_value = Value::Deserialize(value_proto, type);
  ZETASQL_ASSERT_OK(status_or_value.status()) << value_proto.DebugString();
  ValueProto roundtrip_value_proto;
  ZETASQL_ASSERT_OK(status_or_value.value().Serialize(&roundtrip_value_proto))
      << value_proto.DebugString();
  EXPECT_THAT(value_proto, testing::EqualsProto(roundtrip_value_proto));
}

TEST_F(ValueTest, Serialize) {
  // Scalar types.
  SerializeDeserialize(NullInt32());
  SerializeDeserialize(Int32(-100));

  SerializeDeserialize(Null(Int32ArrayType()));
  SerializeDeserialize(EmptyArray(Int32ArrayType()));
  SerializeDeserialize(
      Array({NullInt32(), Int32(std::numeric_limits<int32_t>::lowest()),
             Int32(std::numeric_limits<int32_t>::max()), Int32(0)}));

  SerializeDeserialize(NullInt64());
  SerializeDeserialize(Int64(-9876543210));

  SerializeDeserialize(Null(Int64ArrayType()));
  SerializeDeserialize(EmptyArray(Int64ArrayType()));
  SerializeDeserialize(
      Array({NullInt64(), Int64(std::numeric_limits<int64_t>::lowest()),
             Int64(std::numeric_limits<int64_t>::max()), Int64(0)}));

  SerializeDeserialize(NullUint32());
  SerializeDeserialize(Uint32(42));

  SerializeDeserialize(Null(Uint32ArrayType()));
  SerializeDeserialize(EmptyArray(Uint32ArrayType()));
  SerializeDeserialize(
      Array({NullUint32(), Uint32(std::numeric_limits<int32_t>::max()),
             Uint32(std::numeric_limits<uint32_t>::max()), Uint32(0)}));

  SerializeDeserialize(NullUint64());
  SerializeDeserialize(Uint64(9876543210));

  SerializeDeserialize(Null(Uint64ArrayType()));
  SerializeDeserialize(EmptyArray(Uint64ArrayType()));
  SerializeDeserialize(
      Array({NullUint64(), Uint64(std::numeric_limits<int64_t>::max()),
             Uint64(std::numeric_limits<uint64_t>::max()), Uint64(0)}));

  SerializeDeserialize(NullBool());
  SerializeDeserialize(Bool(true));
  SerializeDeserialize(Bool(false));

  SerializeDeserialize(Null(BoolArrayType()));
  SerializeDeserialize(EmptyArray(BoolArrayType()));
  SerializeDeserialize(Array({Bool(false), Bool(true), NullBool()}));

  SerializeDeserialize(NullFloat());
  SerializeDeserialize(Float(3.1415));

  SerializeDeserialize(Null(FloatArrayType()));
  SerializeDeserialize(EmptyArray(FloatArrayType()));
  SerializeDeserialize(
      Array({Float(std::numeric_limits<float>::min()),
             Float(std::numeric_limits<float>::max()),
             Float(std::numeric_limits<float>::lowest()),
             Float(std::numeric_limits<float>::round_error()),
             Float(std::numeric_limits<float>::epsilon()),
             Float(std::numeric_limits<float>::infinity()),
             Float(-std::numeric_limits<float>::infinity()),
             Float(std::numeric_limits<float>::denorm_min()), NullFloat()}));

  SerializeDeserialize(NullDouble());
  SerializeDeserialize(Double(2.71));

  SerializeDeserialize(Null(DoubleArrayType()));
  SerializeDeserialize(EmptyArray(DoubleArrayType()));
  SerializeDeserialize(
      Array({Double(std::numeric_limits<double>::min()),
             Double(std::numeric_limits<double>::max()),
             Double(std::numeric_limits<double>::lowest()),
             Double(std::numeric_limits<double>::round_error()),
             Double(std::numeric_limits<double>::epsilon()),
             Double(std::numeric_limits<double>::infinity()),
             Double(-std::numeric_limits<double>::infinity()),
             Double(std::numeric_limits<double>::denorm_min()), NullDouble()}));

  SerializeDeserialize(Value::NullNumeric());
  SerializeDeserialize(Value::Numeric(NumericValue(int64_t{1})));

  SerializeDeserialize(EmptyArray(types::NumericArrayType()));
  SerializeDeserialize(
      Array({Value::Numeric(NumericValue()),
             Value::Numeric(NumericValue(int64_t{-1})),
             Value::Numeric(NumericValue(int64_t{1})),
             Value::Numeric(NumericValue::MinValue()),
             Value::Numeric(NumericValue::MaxValue()), Value::NullNumeric()}));

  SerializeDeserialize(Value::NullBigNumeric());
  SerializeDeserialize(Value::BigNumeric(BigNumericValue()));
  SerializeDeserialize(Value::BigNumeric(BigNumericValue(int64_t{1})));
  SerializeDeserialize(Value::BigNumeric(BigNumericValue(int64_t{-1})));
  SerializeDeserialize(Value::BigNumeric(BigNumericValue::MinValue()));
  SerializeDeserialize(Value::BigNumeric(BigNumericValue::MaxValue()));

  SerializeDeserialize(EmptyArray(types::BigNumericArrayType()));
  SerializeDeserialize(Array({Value::BigNumeric(BigNumericValue()),
                              Value::BigNumeric(BigNumericValue(int64_t{-1})),
                              Value::BigNumeric(BigNumericValue(int64_t{1})),
                              Value::BigNumeric(BigNumericValue::MinValue()),
                              Value::BigNumeric(BigNumericValue::MaxValue()),
                              Value::NullBigNumeric()}));

  SerializeDeserialize(Value::NullJson());
  SerializeDeserialize(Value::Json(JSONValue()));
  SerializeDeserialize(Value::Json(JSONValue(int64_t{1})));
  SerializeDeserialize(Value::Json(JSONValue(int64_t{-1})));
  SerializeDeserialize(Value::UnvalidatedJsonString("value"));

  SerializeDeserialize(EmptyArray(types::JsonArrayType()));
  SerializeDeserialize(
      Array({Value::NullJson(), Value::Json(JSONValue(int64_t{-1})),
             Value::Json(JSONValue(int64_t{1})),
             Value::UnvalidatedJsonString("value")}));

  SerializeDeserialize(NullString());
  SerializeDeserialize(String("Hello, world!"));

  SerializeDeserialize(Null(StringArrayType()));
  SerializeDeserialize(EmptyArray(StringArrayType()));
  SerializeDeserialize(Array({String("привет!"), String("!שָׁלוֹם")}));

  SerializeDeserialize(NullBytes());
  SerializeDeserialize(Bytes("\000\001\002"));

  SerializeDeserialize(Null(BytesArrayType()));
  SerializeDeserialize(EmptyArray(BytesArrayType()));
  SerializeDeserialize(Array({NullBytes(), Bytes("!@#$%\n")}));

  SerializeDeserialize(NullDate());
  SerializeDeserialize(Date(10000));

  SerializeDeserialize(Null(types::DateArrayType()));
  SerializeDeserialize(EmptyArray(types::DateArrayType()));
  SerializeDeserialize(Array({NullDate(), Date(zetasql::types::kDateMax),
                              Date(zetasql::types::kDateMin)}));

  SerializeDeserialize(NullTimestamp());
  SerializeDeserialize(TimestampFromUnixMicros(-5364662400000000));

  SerializeDeserialize(Null(types::TimestampArrayType()));
  SerializeDeserialize(EmptyArray(types::TimestampArrayType()));
  SerializeDeserialize(
      Array({NullTimestamp(),
             TimestampFromUnixMicros(zetasql::types::kTimestampMin),
             TimestampFromUnixMicros(zetasql::types::kTimestampMax)}));

  SerializeDeserialize(NullDatetime());
  SerializeDeserialize(Datetime(
      DatetimeValue::FromYMDHMSAndMicros(2010, 8, 7, 15, 26, 31, 712)));
  SerializeDeserialize(Datetime(
      DatetimeValue::FromYMDHMSAndNanos(1871, 11, 21, 9, 5, 4, 192837)));

  SerializeDeserialize(Null(types::DatetimeArrayType()));
  SerializeDeserialize(EmptyArray(types::DatetimeArrayType()));
  SerializeDeserialize(
      Array({NullDatetime(), Value::Datetime(DatetimeValue::FromYMDHMSAndNanos(
                                 1, 2, 3, 4, 5, 6, 7))}));

  SerializeDeserialize(NullTime());
  SerializeDeserialize(Time(TimeValue::FromHMSAndMicros(9, 18, 23, 501)));
  SerializeDeserialize(Time(TimeValue::FromHMSAndNanos(10, 1, 59, 372810)));

  SerializeDeserialize(Null(types::DatetimeArrayType()));
  SerializeDeserialize(EmptyArray(types::DatetimeArrayType()));
  SerializeDeserialize(
      Array({NullDatetime(), Value::Datetime(DatetimeValue::FromYMDHMSAndNanos(
                                 1, 2, 3, 4, 5, 6, 7))}));

  // Interval
  ZETASQL_ASSERT_OK_AND_ASSIGN(IntervalValue interval_min,
                       IntervalValue::FromMonthsDaysNanos(
                           IntervalValue::kMinMonths, IntervalValue::kMinDays,
                           IntervalValue::kMinNanos));
  ZETASQL_ASSERT_OK_AND_ASSIGN(IntervalValue interval_max,
                       IntervalValue::FromMonthsDaysNanos(
                           IntervalValue::kMaxMonths, IntervalValue::kMaxDays,
                           IntervalValue::kMaxNanos));

  SerializeDeserialize(Value::NullInterval());
  SerializeDeserialize(Value::Interval(Nanos(0)));
  SerializeDeserialize(Value::Interval(Nanos(1001)));
  SerializeDeserialize(Value::Interval(Micros(-12)));
  SerializeDeserialize(Value::Interval(Days(370)));
  SerializeDeserialize(Value::Interval(Months(-121)));
  SerializeDeserialize(Value::Interval(interval_min));
  SerializeDeserialize(Value::Interval(interval_max));

  SerializeDeserialize(EmptyArray(types::IntervalArrayType()));
  SerializeDeserialize(
      Array({Value::NullInterval(), Value::Interval(Months(0)),
             Value::Interval(Days(-5)), Value::Interval(Micros(123456789)),
             Value::Interval(interval_min), Value::Interval(interval_max)}));

  // Enum.
  const EnumType* enum_type = GetTestEnumType();
  SerializeDeserialize(Null(enum_type));
  SerializeDeserialize(Enum(enum_type, 1));

  const ArrayType* array_enum_type = GetTestArrayEnumType();
  SerializeDeserialize(Null(array_enum_type));
  SerializeDeserialize(EmptyArray(array_enum_type));
  SerializeDeserialize(
      Value::Array(array_enum_type,
                   {Null(enum_type), Enum(enum_type, 0), Enum(enum_type, 1)}));

  // Proto
  const ProtoType* proto_type = GetTestProtoType();

  zetasql_test__::KitchenSinkPB ks;
  ZETASQL_CHECK(google::protobuf::TextFormat::ParseFromString(R"(
      int64_key_1: 1
      int64_key_2: 2
      )",
                                             &ks));

  absl::Cord ks_serialized = SerializePartialToCord(ks);

  SerializeDeserialize(Null(proto_type));
  SerializeDeserialize(Proto(proto_type, ks_serialized));
  SerializeDeserialize(Array({Proto(proto_type, ks_serialized)}));

  // Empty structs
  SerializeDeserialize(Null(EmptyStructType()));
  SerializeDeserialize(Struct({}));

  // Array of empty structs.
  SerializeDeserialize(Array({Null(EmptyStructType()), Struct({})}));

  // Structs
  const StructType* simple_struct_type =
      MakeStructType({{"a", Int64ArrayType()}, {"t", TimestampType()}});

  const StructType* struct_type = MakeStructType({{"a", Int32ArrayType()},
                                                  {"b", BytesType()},
                                                  {"d", DateType()},
                                                  {"e", EmptyStructType()},
                                                  {"p", GetTestProtoType()},
                                                  {"s", simple_struct_type}});

  SerializeDeserialize(Null(struct_type));
  SerializeDeserialize(Struct({{"a", Null(Int32ArrayType())},
                               {"b", NullBytes()},
                               {"d", NullDate()},
                               {"e", Null(EmptyStructType())},
                               {"p", Null(GetTestProtoType())},
                               {"s", Null(simple_struct_type)}}));
  SerializeDeserialize(Struct(
      {{"a", Int32Array({0, 1, 2, 3, 4, 5})},
       {"b", Bytes("\001\000\002\005")},
       {"d", Date(365)},
       {"e", Struct({})},
       {"p", Null(GetTestProtoType())},
       {"s", Struct({{"a", Array({NullInt64(), Int64(999)})},
                     {"t", TimestampFromUnixMicros(1430855635016138)}})}}));
}

TEST_F(ValueTest, Deserialize) {
  // Scalars.
  DeserializeSerialize("", Int32Type());
  DeserializeSerialize("int32_value: 0", Int32Type());

  DeserializeSerialize("", Int32ArrayType());
  DeserializeSerialize("array_value: <>", Int32ArrayType());
  DeserializeSerialize("array_value: <element: <>>", Int32ArrayType());
  DeserializeSerialize(R"(
    array_value: <
      element: <int32_value: -1>
      element: <>
      element: <int32_value: 1>>
    )",
                       Int32ArrayType());

  // Empty struct.
  DeserializeSerialize("", EmptyStructType());
  DeserializeSerialize("struct_value: <>", EmptyStructType());

  // Array of empty structs.
  const Type* array_empty_struct_type = MakeArrayType(EmptyStructType());
  DeserializeSerialize("", array_empty_struct_type);
  DeserializeSerialize("array_value: <>", array_empty_struct_type);
  DeserializeSerialize("array_value: <element: <>>", array_empty_struct_type);
  DeserializeSerialize("array_value: <element: <struct_value: <>>>",
                       array_empty_struct_type);
  DeserializeSerialize(R"(
    array_value: <
      element: <struct_value: <>>
      element: <struct_value: <>>>
    )",
                       array_empty_struct_type);

  // Structs.
  const StructType* simple_struct_type =
      MakeStructType({{"a", Int64ArrayType()}, {"t", TimestampType()}});

  const StructType* struct_type = MakeStructType({{"a", Int32ArrayType()},
                                                  {"b", BytesType()},
                                                  {"d", DateType()},
                                                  {"e", EmptyStructType()},
                                                  {"p", GetTestProtoType()},
                                                  {"s", simple_struct_type}});

  DeserializeSerialize("", struct_type);
  DeserializeSerialize(R"(
    struct_value: <
      field: <>  # a
      field: <>  # b
      field: <>  # d
      field: <>  # e
      field: <>  # p
      field: <>  # s
    >
    )",
                       struct_type);

  DeserializeSerialize(R"(
    struct_value: <
      field: <array_value: <>>      # a
      field: <bytes_value: 'xxx'>   # b
      field: <date_value: 1000>     # d
      field: <struct_value: <>>     # e
      field: <>                     # p
      field:                        # s
        <struct_value <
          field: <                  # s.a
            array_value: <
              element: <int64_value: 1>
              element: <>
              element: <int64_value: 2>
            >
          >
          field:                    # s.t
            <timestamp_value: <seconds: 946684800>>
        >
      >
    >
    )",
                       struct_type);

  ValueProto value_proto;
  absl::StatusOr<Value> status_or_value;

  // Timestamp value.
  ZETASQL_CHECK(google::protobuf::TextFormat::ParseFromString("timestamp_value: <seconds: 5>",
                                             &value_proto));
  status_or_value = Value::Deserialize(value_proto, TimestampType());
  ZETASQL_EXPECT_OK(status_or_value.status());
  EXPECT_EQ(5000000, status_or_value.value().ToUnixMicros());

  // Invalid values for DATE/TIMESTAMP
  ZETASQL_CHECK(google::protobuf::TextFormat::ParseFromString(
      absl::StrCat("date_value: ", zetasql::types::kDateMin - 1),
      &value_proto));
  status_or_value = Value::Deserialize(value_proto, DateType());
  EXPECT_THAT(status_or_value, StatusIs(absl::StatusCode::kOutOfRange));

  ZETASQL_CHECK(google::protobuf::TextFormat::ParseFromString(
      absl::StrCat("date_value: ", zetasql::types::kDateMax + 1),
      &value_proto));
  status_or_value = Value::Deserialize(value_proto, DateType());
  EXPECT_THAT(status_or_value, StatusIs(absl::StatusCode::kOutOfRange));

  const int64_t kTimestampSecondsMin =
      zetasql::types::kTimestampMin / 1000000;
  const int64_t kTimestampSecondsMax =
      zetasql::types::kTimestampMax / 1000000;
  ZETASQL_CHECK(google::protobuf::TextFormat::ParseFromString(
      absl::StrCat("timestamp_value: <seconds: ", kTimestampSecondsMin - 1,
                   " nanos: 999999999>"),
      &value_proto));
  status_or_value = Value::Deserialize(value_proto, TimestampType());
  EXPECT_THAT(status_or_value, StatusIs(absl::StatusCode::kOutOfRange));

  ZETASQL_CHECK(google::protobuf::TextFormat::ParseFromString(
      absl::StrCat("timestamp_value: <seconds: ", kTimestampSecondsMax + 1,
                   ">"),
      &value_proto));
  status_or_value = Value::Deserialize(value_proto, TimestampType());
  EXPECT_THAT(status_or_value, StatusIs(absl::StatusCode::kOutOfRange));

  // Invalid ENUM value.
  ZETASQL_CHECK(google::protobuf::TextFormat::ParseFromString("enum_value: -10", &value_proto));
  status_or_value = Value::Deserialize(value_proto, GetTestEnumType());
  EXPECT_THAT(status_or_value, StatusIs(absl::StatusCode::kOutOfRange));

  ZETASQL_CHECK(google::protobuf::TextFormat::ParseFromString("enum_value: 100", &value_proto));
  status_or_value = Value::Deserialize(value_proto, GetTestEnumType());
  EXPECT_THAT(status_or_value, StatusIs(absl::StatusCode::kOutOfRange));

  // Type mismatch errors.
  ZETASQL_CHECK(google::protobuf::TextFormat::ParseFromString("int32_value: 1", &value_proto));
  status_or_value = Value::Deserialize(value_proto, Int64Type());
  EXPECT_THAT(status_or_value, StatusIs(absl::StatusCode::kInternal));
  status_or_value = Value::Deserialize(value_proto, DateType());
  EXPECT_THAT(status_or_value, StatusIs(absl::StatusCode::kInternal));
  status_or_value = Value::Deserialize(value_proto, GetTestEnumType());
  EXPECT_THAT(status_or_value, StatusIs(absl::StatusCode::kInternal));

  ZETASQL_CHECK(google::protobuf::TextFormat::ParseFromString(R"(
    array_value: <
      element: <uint32_value: 1>
      element: <int32_value: 1>>  # wrong type!
    )",
                                             &value_proto));
  status_or_value = Value::Deserialize(value_proto, Uint64ArrayType());
  EXPECT_THAT(status_or_value, StatusIs(absl::StatusCode::kInternal));

  // simple_struct_type: STRUCT<ARRAY<INT64>> a, TIMESTAMP t>
  ZETASQL_CHECK(google::protobuf::TextFormat::ParseFromString(R"(
    struct_value: <
      field: <array_value: <element: <int32_value: 1>>>  # wrong type!
      field: <timestamp_value: <seconds: 935573798>>
    >
    )",
                                             &value_proto));
  status_or_value = Value::Deserialize(value_proto, simple_struct_type);
  EXPECT_THAT(status_or_value, StatusIs(absl::StatusCode::kInternal));

  ZETASQL_CHECK(google::protobuf::TextFormat::ParseFromString(R"(
    struct_value: <
      field: <array_value: <element: <int64_value: 1>>>
      field: <int64_value: 935573798000000>  # wrong type!
    >
    )",
                                             &value_proto));
  status_or_value = Value::Deserialize(value_proto, simple_struct_type);
  EXPECT_THAT(status_or_value, StatusIs(absl::StatusCode::kInternal));

  // Mismatch in number of fields in struct.
  ZETASQL_CHECK(google::protobuf::TextFormat::ParseFromString(R"(
    struct_value: <
      field: <timestamp_value: <seconds: 935573798>>
    >
    )",
                                             &value_proto));
  status_or_value = Value::Deserialize(value_proto, simple_struct_type);
  EXPECT_THAT(status_or_value, StatusIs(absl::StatusCode::kInternal));
}

namespace {

template <typename T>
bool IsNaN(const Value& value) {
  return value.type()->IsFloatingPoint() && !value.is_null() &&
         std::isnan(value.Get<T>());
}

template <>
bool IsNaN<NumericValue>(const Value& value) {
  return false;
}

template <>
bool IsNaN<BigNumericValue>(const Value& value) {
  return false;
}

template <typename T>
void MakeSortedVector(std::vector<zetasql::Value>* values) {
  // In ZetaSQL the ordering of values is ((broken link)):
  // NULL, NaN(s), negative infinity, finite negative numbers, zero,
  // finite positive numbers, positive infinity.

  // NULL
  values->push_back(zetasql::Value::MakeNull<T>());

  // NaN(s) - quiet and signaling, negative and positive
  if (std::numeric_limits<T>::has_quiet_NaN) {
    values->push_back(
        zetasql::Value::Make(std::numeric_limits<T>::quiet_NaN()));
    values->push_back(
        zetasql::Value::Make(-std::numeric_limits<T>::quiet_NaN()));
  }
  if (std::numeric_limits<T>::has_signaling_NaN) {
    values->push_back(
        zetasql::Value::Make(std::numeric_limits<T>::signaling_NaN()));
    values->push_back(
        zetasql::Value::Make(-std::numeric_limits<T>::signaling_NaN()));
  }

  // For signed numbers
  if (std::numeric_limits<T>::is_signed) {
    // Negative infinity
    if (std::numeric_limits<T>::has_infinity) {
      values->push_back(
          zetasql::Value::Make(-std::numeric_limits<T>::infinity()));
    }
    // Lowest finite number (will be negative)
    values->push_back(zetasql::Value::Make(std::numeric_limits<T>::lowest()));

    // Some finite negative number
    values->push_back(zetasql::Value::Make(static_cast<T>(-5)));
  }
  // Zero
  values->push_back(zetasql::Value::Make(static_cast<T>(0)));
  // Some finite positive number
  values->push_back(zetasql::Value::Make(static_cast<T>(239)));
  // Highest finite positive number
  values->push_back(zetasql::Value::Make(std::numeric_limits<T>::max()));
  // Positive infinity
  if (std::numeric_limits<T>::has_infinity) {
    values->push_back(
        zetasql::Value::Make(std::numeric_limits<T>::infinity()));
  }
}

template <>
void MakeSortedVector<NumericValue>(std::vector<zetasql::Value>* values) {
  // NULL
  values->push_back(NullNumeric());
  // Lowest finite number (will be negative)
  values->push_back(Value::Numeric(NumericValue::MinValue()));

  // Some finite negative number
  values->push_back(Value::Numeric(NumericValue(-5)));
  // Zero
  values->push_back(Value::Numeric(NumericValue(0)));
  // Some finite positive number
  values->push_back(
      Value::Numeric(NumericValue::FromStringStrict("123.4").value()));
  // Highest finite positive number
  values->push_back(Value::Numeric(NumericValue::MaxValue()));
}

template <>
void MakeSortedVector<BigNumericValue>(std::vector<zetasql::Value>* values) {
  // NULL
  values->push_back(NullBigNumeric());
  // Lowest finite number (will be negative)
  values->push_back(Value::BigNumeric(BigNumericValue::MinValue()));

  // Some finite negative number
  values->push_back(Value::BigNumeric(BigNumericValue(-5)));
  // Zero
  values->push_back(Value::BigNumeric(BigNumericValue(0)));
  // Some finite positive number
  values->push_back(
      Value::BigNumeric(BigNumericValue::FromStringStrict("123.4").value()));
  // Highest finite positive number
  values->push_back(Value::BigNumeric(BigNumericValue::MaxValue()));
}
}  // namespace

class ValueCompareTest : public ::testing::Test {
 public:
  ValueCompareTest() {}
  ValueCompareTest(const ValueCompareTest&) = delete;
  ValueCompareTest& operator=(const ValueCompareTest&) = delete;
  ~ValueCompareTest() override {}

  template <typename T>
  void TestSortOrder() {
    // In ZetaSQL the ordering of values is ((broken link)):
    // NULL, NaN(s), negative infinity, finite negative numbers, zero,
    // finite positive numbers, positive infinity.
    std::vector<zetasql::Value> values;

    MakeSortedVector<T>(&values);

    size_t num_values = values.size();
    for (int i = 0; i < num_values; i++) {
      // values[i] = values[i] for any i
      EXPECT_EQ(values[i], values[i]);
      EXPECT_TRUE(values[i].Equals(values[i]));
      EXPECT_FALSE(values[i].LessThan(values[i]));
      for (int j = i + 1; j < num_values; j++) {
        if (IsNaN<T>(values[i]) && IsNaN<T>(values[j])) {
          // values[i] == values[j] when both are NaNs
          EXPECT_EQ(values[i], values[j]);
          EXPECT_TRUE(values[i].Equals(values[j]));
          EXPECT_FALSE(values[i].LessThan(values[j]));
          EXPECT_FALSE(values[j].LessThan(values[i]));
        } else {
          // values[i] < values[j]
          EXPECT_NE(values[i], values[j]);
          EXPECT_FALSE(values[i].Equals(values[j]));
          EXPECT_TRUE(values[i].LessThan(values[j]));
          EXPECT_FALSE(values[j].LessThan(values[i]));
        }
      }
    }
  }
};

TEST_F(ValueCompareTest, SortOrder) {
  TestSortOrder<int32_t>();
  TestSortOrder<uint32_t>();
  TestSortOrder<int64_t>();
  TestSortOrder<uint64_t>();
  TestSortOrder<float>();
  TestSortOrder<double>();
  TestSortOrder<NumericValue>();
  TestSortOrder<BigNumericValue>();
}

}  // namespace zetasql
