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

#include "zetasql/reference_impl/algebrizer.h"

#include <cstdint>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "zetasql/base/logging.h"
#include "zetasql/common/evaluator_test_table.h"
#include "zetasql/base/testing/status_matchers.h"
#include "zetasql/public/analyzer.h"
#include "zetasql/public/builtin_function.h"
#include "zetasql/public/builtin_function.pb.h"
#include "zetasql/public/civil_time.h"
#include "zetasql/public/function.h"
#include "zetasql/public/function.pb.h"
#include "zetasql/public/options.pb.h"
#include "zetasql/public/simple_catalog.h"
#include "zetasql/public/type.h"
#include "zetasql/public/value.h"
#include "zetasql/resolved_ast/make_node_vector.h"
#include "zetasql/resolved_ast/resolved_ast.h"
#include "zetasql/resolved_ast/resolved_column.h"
#include "zetasql/resolved_ast/resolved_node_kind.pb.h"
#include "zetasql/testdata/sample_catalog.h"
#include "zetasql/testing/using_test_value.cc"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <cstdint>
#include "absl/memory/memory.h"
#include "absl/status/statusor.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/substitute.h"
#include "zetasql/base/map_util.h"
#include "zetasql/base/status_macros.h"

namespace zetasql {

using testing::HasSubstr;
using testing::MatchesRegex;
using testing::TestWithParam;
using testing::ValuesIn;
using zetasql_base::testing::StatusIs;

static const auto DEFAULT_ERROR_MODE =
    ResolvedFunctionCallBase::DEFAULT_ERROR_MODE;

class AlgebrizerTestBase : public ::testing::Test {
 public:
  // Argument to ResolvedColumnRef constructor to make it non-correlated.
  static constexpr bool kNonCorrelated = false;

  static constexpr int kTotalColumns = 7;
  // Indexes into an array of columns of the table table_all_types.
  static constexpr int kInvalidColIdx = -1;
  static constexpr int kInt32ColIdx = 0;
  static constexpr int kUint32ColIdx = 1;
  static constexpr int kInt64ColIdx = 2;
  static constexpr int kUint64ColIdx = 3;
  static constexpr int kStringColIdx = 4;
  static constexpr int kBoolColIdx = 5;
  static constexpr int kDoubleColIdx = 6;
  // Column ids for table table_all_types.
  static constexpr int kInt32ColId = kInt32ColIdx + 1;
  static constexpr int kUint32ColId = kUint32ColIdx + 1;
  static constexpr int kInt64ColId = kInt64ColIdx + 1;
  static constexpr int kUint64ColId = kUint64ColIdx + 1;
  static constexpr int kStringColId = kStringColIdx + 1;
  static constexpr int kBoolColId = kBoolColIdx + 1;
  static constexpr int kDoubleColId = kDoubleColIdx + 1;
  // Column ids for table table_all_types_2.
  static constexpr int kInt32ColId2 = kInt32ColId + kTotalColumns;
  static constexpr int kUint32ColId2 = kUint32ColId + kTotalColumns;
  static constexpr int kInt64ColId2 = kInt64ColId + kTotalColumns;
  static constexpr int kUint64ColId2 = kUint64ColId + kTotalColumns;
  static constexpr int kStringColId2 = kStringColId + kTotalColumns;
  static constexpr int kBoolColId2 = kBoolColId + kTotalColumns;
  static constexpr int kDoubleColId2 = kDoubleColId + kTotalColumns;

  absl::StatusOr<std::unique_ptr<const ValueExpr>>
  TestAlgebrizeExpressionInternal(
      const ResolvedExpr* resolved_expr,
      const ColumnToVariableMapping::Map* column_to_variable_map = nullptr) {
    absl::optional<ColumnToVariableMapping::Map> original_map;
    if (column_to_variable_map != nullptr) {
      original_map = algebrizer_->column_to_variable_->map();
      algebrizer_->column_to_variable_->set_map(*column_to_variable_map);
    }
    absl::StatusOr<std::unique_ptr<ValueExpr>> result =
        algebrizer_->AlgebrizeExpression(resolved_expr);
    if (original_map.has_value()) {
      algebrizer_->column_to_variable_->set_map(original_map.value());
    }
    return result;
  }

  void TestAlgebrizeExpression(
      const ResolvedExpr* resolved_expr, const std::string& expected,
      const ColumnToVariableMapping::Map* column_to_variable_map = nullptr) {
    absl::StatusOr<std::unique_ptr<const ValueExpr>> expr =
        TestAlgebrizeExpressionInternal(resolved_expr, column_to_variable_map);
    ZETASQL_EXPECT_OK(expr.status());
    if (expr.ok()) {
      EXPECT_EQ(expected, expr.value()->DebugString(true));
    }
  }

  void TestAlgebrizeInt32(int32_t value, std::string expected) {
    std::unique_ptr<const ResolvedExpr> expr(
        MakeResolvedLiteral(Value::Int32(value)));
    TestAlgebrizeExpression(expr.get(), std::move(expected));
  }

  void TestAlgebrizeUint32(int32_t value, std::string expected) {
    std::unique_ptr<const ResolvedExpr> expr(
        MakeResolvedLiteral(Value::Uint32(value)));
    TestAlgebrizeExpression(expr.get(), std::move(expected));
  }

  void TestAlgebrizeInt64(int64_t value, std::string expected) {
    std::unique_ptr<const ResolvedExpr> expr(
        MakeResolvedLiteral(Value::Int64(value)));
    TestAlgebrizeExpression(expr.get(), std::move(expected));
  }

  void TestAlgebrizeUint64(uint64_t value, std::string expected) {
    std::unique_ptr<const ResolvedExpr> expr(
        MakeResolvedLiteral(Value::Uint64(value)));
    TestAlgebrizeExpression(expr.get(), std::move(expected));
  }

  void TestAlgebrizeBool(bool value, std::string expected) {
    std::unique_ptr<const ResolvedExpr> expr(
        MakeResolvedLiteral(Value::Bool(value)));
    TestAlgebrizeExpression(expr.get(), std::move(expected));
  }

  void TestAlgebrizeDouble(double value, std::string expected) {
    std::unique_ptr<const ResolvedExpr> expr(
        MakeResolvedLiteral(Value::Double(value)));
    TestAlgebrizeExpression(expr.get(), std::move(expected));
  }

  void TestAlgebrizeString(const std::string& value, std::string expected) {
    std::unique_ptr<const ResolvedExpr> expr(
        MakeResolvedLiteral(Value::String(value)));
    TestAlgebrizeExpression(expr.get(), std::move(expected));
  }

  void TestAlgebrizeColumnRef(int column_id, const std::string& column_name,
                              const Type* type, const std::string& expected) {
    ResolvedColumn column(column_id,
                          zetasql::IdString::MakeGlobal("table_name_unused"),
                          zetasql::IdString::MakeGlobal(column_name), type);
    std::unique_ptr<const ResolvedExpr> expr(
        MakeResolvedColumnRef(type, column, kNonCorrelated));
    ColumnToVariableMapping::Map map = {{column, VariableId(column_name)}};
    TestAlgebrizeExpression(expr.get(), expected, &map);
  }

  // Build a resolved scan of table_all_types. Column ids start at "*column_id".
  std::unique_ptr<const ResolvedTableScan> ScanTableAllTypesCore(
      int* column_id, const SimpleTable& table,
      const ResolvedColumnList& columns) {
    // Build the resolved columns of the right hand scan and scan itself.
    ResolvedColumnList column_refs;
    for (int i = 0; i < columns.size(); ++i) {
      ResolvedColumn column((*column_id)++,
                            zetasql::IdString::MakeGlobal(table.Name()),
                            zetasql::IdString::MakeGlobal(columns[i].name()),
                            columns[i].type());
      column_refs.push_back(column);
    }
    std::unique_ptr<const ResolvedTableScan> table_scan =
        MakeResolvedTableScan(column_refs, &table, nullptr);
    return table_scan;
  }

  std::unique_ptr<const ResolvedTableScan> ScanTableAllTypes(int* column_id) {
    return ScanTableAllTypesCore(column_id, table_, columns_);
  }

  std::unique_ptr<const ResolvedTableScan> ScanTableAllTypes2(int* column_id) {
    return ScanTableAllTypesCore(column_id, table2_, columns2_);
  }

 protected:
  void SetUp() override {
    algebrizer_ = absl::WrapUnique(
        new Algebrizer(LanguageOptions(), algebrizer_options_, &type_factory_,
                       &parameters_, &column_map_, &system_variables_map_));
  }

  // Table and column names for table table_all_types.
  static const char kAllTypesTable[];
  static const char kAllTypesTableAlias[];
  static const char kInt32Col[];
  static const char kUint32Col[];
  static const char kInt64Col[];
  static const char kUint64Col[];
  static const char kStringCol[];
  static const char kBoolCol[];
  static const char kDoubleCol[];

  // Table and column names for table table_all_types_2.
  static const char kAllTypesTable2[];
  static const char kInt32Col2[];
  static const char kUint32Col2[];
  static const char kInt64Col2[];
  static const char kUint64Col2[];
  static const char kStringCol2[];
  static const char kBoolCol2[];
  static const char kDoubleCol2[];

  // Generates the expected output for a scan operator over table_all_types
  // with a given indent.
  static std::string ScanTableAllTypesAsArrayExprString(int indent) {
    std::string indent_spaces = std::string(indent, ' ');
    std::string scan = absl::Substitute(
        "ArrayScanOp(\n"
        "$0+-$$col_bool := field[5]:col_bool,\n"
        "$0+-$$col_double := field[6]:col_double,\n"
        "$0+-$$col_int32 := field[0]:col_int32,\n"
        "$0+-$$col_int64 := field[2]:col_int64,\n"
        "$0+-$$col_string := field[4]:col_string,\n"
        "$0+-$$col_uint32 := field[1]:col_uint32,\n"
        "$0+-$$col_uint64 := field[3]:col_uint64,\n"
        "$0+-array: TableAsArrayExpr($1))",
        indent_spaces, kAllTypesTable);
    return scan;
  }

  // Construct a new ResolvedProjectScan using the given expressions and
  // input_scan.
  // This builds a column_list and expr_list to match expressions.
  // Takes ownership of pointers in expressions.
  static std::unique_ptr<ResolvedProjectScan> CreateResolvedProjectScan(
      std::vector<std::unique_ptr<const ResolvedComputedColumn>> expressions,
      std::unique_ptr<const ResolvedScan> input_scan) {
    ResolvedColumnList column_list;
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> projected_exprs;
    for (auto& computed_column : expressions) {
      column_list.emplace_back(computed_column->column());
      if (!(computed_column->expr()->node_kind() == RESOLVED_COLUMN_REF)) {
        projected_exprs.emplace_back(std::move(computed_column));
      }
    }
    return MakeResolvedProjectScan(column_list, std::move(projected_exprs),
                                   std::move(input_scan));
  }

  absl::StatusOr<std::unique_ptr<ArrayNestExpr>> AlgebrizeAndNestInStruct(
      const ResolvedScan* resolved_scan) {
    ZETASQL_ASSIGN_OR_RETURN(std::unique_ptr<RelationalOp> relation,
                     algebrizer_->AlgebrizeScan(resolved_scan));
    return algebrizer_->NestRelationInStruct(resolved_scan->column_list(),
                                             std::move(relation),
                                             /*is_with_table=*/false);
  }

  // Set of resolved columns with one column for every supported type.
  // TODO Add the missing types.
  const ResolvedColumnList columns_ = {
      ResolvedColumn(kInt32ColId,
                     zetasql::IdString::MakeGlobal(kAllTypesTable),
                     zetasql::IdString::MakeGlobal(kInt32Col), Int32Type()),
      ResolvedColumn(kUint32ColId,
                     zetasql::IdString::MakeGlobal(kAllTypesTable),
                     zetasql::IdString::MakeGlobal(kUint32Col), Uint32Type()),
      ResolvedColumn(kInt64ColId,
                     zetasql::IdString::MakeGlobal(kAllTypesTable),
                     zetasql::IdString::MakeGlobal(kInt64Col), Int64Type()),
      ResolvedColumn(kUint64ColId,
                     zetasql::IdString::MakeGlobal(kAllTypesTable),
                     zetasql::IdString::MakeGlobal(kUint64Col), Uint64Type()),
      ResolvedColumn(kStringColId,
                     zetasql::IdString::MakeGlobal(kAllTypesTable),
                     zetasql::IdString::MakeGlobal(kStringCol), StringType()),
      ResolvedColumn(kBoolColId,
                     zetasql::IdString::MakeGlobal(kAllTypesTable),
                     zetasql::IdString::MakeGlobal(kBoolCol), BoolType()),
      ResolvedColumn(
          kDoubleColId, zetasql::IdString::MakeGlobal(kAllTypesTable),
          zetasql::IdString::MakeGlobal(kDoubleCol), DoubleType())};

  // The columns of table_all_types_2.  The columns id's assume that this table
  // is scanned "second" after table_all_types.
  const ResolvedColumnList columns2_ = {
      ResolvedColumn(kInt32ColId2,
                     zetasql::IdString::MakeGlobal(kAllTypesTable2),
                     zetasql::IdString::MakeGlobal(kInt32Col2), Int32Type()),
      ResolvedColumn(
          kUint32ColId2, zetasql::IdString::MakeGlobal(kAllTypesTable2),
          zetasql::IdString::MakeGlobal(kUint32Col2), Uint32Type()),
      ResolvedColumn(kInt64ColId2,
                     zetasql::IdString::MakeGlobal(kAllTypesTable2),
                     zetasql::IdString::MakeGlobal(kInt64Col2), Int64Type()),
      ResolvedColumn(
          kUint64ColId2, zetasql::IdString::MakeGlobal(kAllTypesTable2),
          zetasql::IdString::MakeGlobal(kUint64Col2), Uint64Type()),
      ResolvedColumn(
          kStringColId2, zetasql::IdString::MakeGlobal(kAllTypesTable2),
          zetasql::IdString::MakeGlobal(kStringCol2), StringType()),
      ResolvedColumn(kBoolColId2,
                     zetasql::IdString::MakeGlobal(kAllTypesTable2),
                     zetasql::IdString::MakeGlobal(kBoolCol2), BoolType()),
      ResolvedColumn(
          kDoubleColId2, zetasql::IdString::MakeGlobal(kAllTypesTable2),
          zetasql::IdString::MakeGlobal(kDoubleCol2), DoubleType())};
  // Schema for test tables on the algebra side.
  std::vector<std::pair<std::string, const Type*>> test_table_columns_{
      {kInt32Col, Int32Type()},   {kUint32Col, Uint32Type()},
      {kInt64Col, Int64Type()},   {kUint64Col, Uint64Type()},
      {kStringCol, StringType()}, {kBoolCol, BoolType()},
      {kDoubleCol, DoubleType()},
  };
  std::vector<std::pair<std::string, const Type*>> test_table_columns2_{
      {kInt32Col2, Int32Type()},   {kUint32Col2, Uint32Type()},
      {kInt64Col2, Int64Type()},   {kUint64Col2, Uint64Type()},
      {kStringCol2, StringType()}, {kBoolCol2, BoolType()},
      {kDoubleCol2, DoubleType()},
  };
  // Test tables on the Algebra side.
  SimpleTable table_{kAllTypesTable, test_table_columns_};
  SimpleTable table2_{kAllTypesTable2, test_table_columns2_};
  TypeFactory type_factory_;
  AlgebrizerOptions algebrizer_options_;
  std::unique_ptr<Algebrizer> algebrizer_;
  Parameters parameters_;
  ParameterMap column_map_;
  SystemVariablesAlgebrizerMap system_variables_map_;
  // For tests that require functions.
  std::vector<std::unique_ptr<Function>> functions_;
};

// Table and column names for table table_all_types.
const char AlgebrizerTestBase::kAllTypesTable[] = "table_all_types";
const char AlgebrizerTestBase::kAllTypesTableAlias[] = "table_all_types_alias";
const char AlgebrizerTestBase::kInt32Col[] = "col_int32";
const char AlgebrizerTestBase::kUint32Col[] = "col_uint32";
const char AlgebrizerTestBase::kInt64Col[] = "col_int64";
const char AlgebrizerTestBase::kUint64Col[] = "col_uint64";
const char AlgebrizerTestBase::kStringCol[] = "col_string";
const char AlgebrizerTestBase::kBoolCol[] = "col_bool";
const char AlgebrizerTestBase::kDoubleCol[] = "col_double";

// Table and column names for table table_all_types_2.
const char AlgebrizerTestBase::kAllTypesTable2[] = "table_all_types_2";
const char AlgebrizerTestBase::kInt32Col2[] = "col_int32.2";
const char AlgebrizerTestBase::kUint32Col2[] = "col_uint32.2";
const char AlgebrizerTestBase::kInt64Col2[] = "col_int64.2";
const char AlgebrizerTestBase::kUint64Col2[] = "col_uint64.2";
const char AlgebrizerTestBase::kStringCol2[] = "col_string.2";
const char AlgebrizerTestBase::kBoolCol2[] = "col_bool.2";
const char AlgebrizerTestBase::kDoubleCol2[] = "col_double.2";

class TableAsArrayAlgebrizerTest : public AlgebrizerTestBase {
 protected:
  void SetUp() override {
    algebrizer_options_.use_arrays_for_tables = true;
    AlgebrizerTestBase::SetUp();
  }
};

// For historical reasons, most of the unit tests assume that tables are
// represented by arrays (as in the compliance tests).
using StatementAlgebrizerTest = TableAsArrayAlgebrizerTest;
using ExpressionAlgebrizerTest = AlgebrizerTestBase;

TEST_F(ExpressionAlgebrizerTest, AlgebrizeResolvedExpressions) {
  // Int32boundaries
  TestAlgebrizeInt32(std::numeric_limits<int32_t>::max(),
                     "ConstExpr(Int32(2147483647))");
  TestAlgebrizeInt32(std::numeric_limits<int32_t>::lowest(),
                     "ConstExpr(Int32(-2147483648))");
  // Uint32boundaries
  TestAlgebrizeUint32(std::numeric_limits<uint32_t>::max(),
                      "ConstExpr(Uint32(4294967295))");
  TestAlgebrizeUint32(0, "ConstExpr(Uint32(0))");
  // Int64 boundaries
  TestAlgebrizeInt64(std::numeric_limits<int64_t>::max(),
                     "ConstExpr(Int64(9223372036854775807))");
  TestAlgebrizeInt64(std::numeric_limits<int64_t>::lowest(),
                     "ConstExpr(Int64(-9223372036854775808))");
  // Uint64 boundaries
  TestAlgebrizeUint64(std::numeric_limits<uint64_t>::max(),
                      "ConstExpr(Uint64(18446744073709551615))");
  TestAlgebrizeUint64(0, "ConstExpr(Uint64(0))");
  // Bool boundaries
  TestAlgebrizeBool(true, "ConstExpr(Bool(true))");
  TestAlgebrizeBool(false, "ConstExpr(Bool(false))");
  // Double boundaries
  TestAlgebrizeDouble(std::numeric_limits<double>::max(),
                      "ConstExpr(Double(1.7976931348623157e+308))");
  TestAlgebrizeDouble(std::numeric_limits<double>::min(),
                      "ConstExpr(Double(2.2250738585072014e-308))");
  // String "boundaries"
  TestAlgebrizeString("", "ConstExpr(String(\"\"))");
  TestAlgebrizeString("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
                      "1234567890,./;'[]\\-=`<>?:\"{}|_+~!@#$%^&*()",
                      "ConstExpr(String(\""
                      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
                      "1234567890,./;'[]\\\\-=`<>?:\\\"{}|_+~!@#$%^&*()\"))");
  // Simple column references
  TestAlgebrizeColumnRef(
      kInt64ColId, kInt64Col, Int64Type(), "DerefExpr(col_int64)");
  TestAlgebrizeColumnRef(
      kStringColId, kStringCol, StringType(), "DerefExpr(col_string)");
  TestAlgebrizeColumnRef(
      kBoolColId, kBoolCol, BoolType(), "DerefExpr(col_bool)");
  TestAlgebrizeColumnRef(
      kDoubleColId, kDoubleCol, DoubleType(), "DerefExpr(col_double)");
}

TEST_F(ExpressionAlgebrizerTest, AlgebrizeResolvedCivilTimeExpressions) {
  std::vector<std::pair<std::unique_ptr<const ResolvedExpr>, std::string>>
      test_cases;
  test_cases.emplace_back(MakeResolvedLiteral(Value::Time(
                              TimeValue::FromHMSAndMicros(1, 2, 3, 123456))),
                          "RootExpr(ConstExpr(Time(01:02:03.123456)))");
  test_cases.emplace_back(
      MakeResolvedLiteral(Value::Datetime(
          DatetimeValue::FromYMDHMSAndMicros(2006, 1, 2, 3, 4, 5, 123456))),
      "RootExpr(ConstExpr(Datetime(2006-01-02 03:04:05.123456)))");

  TypeFactory type_factory;

  LanguageOptions language_options;

  // Without the civil time feature option, algebrizing is failing.
  language_options.DisableAllLanguageFeatures();
  for (const auto& each : test_cases) {
    std::unique_ptr<ValueExpr> algebra_output;
    Parameters parameters(ParameterMap{});
    ParameterMap column_map;
    SystemVariablesAlgebrizerMap system_variables_map;
    EXPECT_THAT(Algebrizer::AlgebrizeExpression(
                    language_options, AlgebrizerOptions(), &type_factory,
                    each.first.get(), &algebra_output, &parameters, &column_map,
                    &system_variables_map),
                StatusIs(absl::StatusCode::kInvalidArgument,
                         HasSubstr(absl::StrCat(
                             "Type not found: ",
                             each.first->type()->TypeName(
                                 language_options.product_mode())))));
  }

  // With the civil time feature option, algebrizing is successful.
  language_options.EnableLanguageFeature(FEATURE_V_1_2_CIVIL_TIME);
  for (const auto& each : test_cases) {
    std::unique_ptr<ValueExpr> algebra_output;
    Parameters parameters(ParameterMap{});
    ParameterMap column_map;
    SystemVariablesAlgebrizerMap system_variables_map;
    ZETASQL_ASSERT_OK(Algebrizer::AlgebrizeExpression(
        language_options, AlgebrizerOptions(), &type_factory, each.first.get(),
        &algebra_output, &parameters, &column_map, &system_variables_map));
    EXPECT_EQ(each.second, algebra_output->DebugString(true));
  }
}

TEST_F(ExpressionAlgebrizerTest, AlgebrizeResolvedNullExpressions) {
  std::unique_ptr<const ResolvedExpr> null_int64(
      MakeResolvedLiteral(Value::NullInt64()));
  TestAlgebrizeExpression(null_int64.get(), "ConstExpr(Int64(NULL))");
  std::unique_ptr<const ResolvedExpr> null_bool(
      MakeResolvedLiteral(Value::NullBool()));
  TestAlgebrizeExpression(null_bool.get(), "ConstExpr(Bool(NULL))");
  std::unique_ptr<const ResolvedExpr> null_double(
      MakeResolvedLiteral(Value::NullDouble()));
  TestAlgebrizeExpression(null_double.get(), "ConstExpr(Double(NULL))");
  std::unique_ptr<const ResolvedExpr> null_string(
      MakeResolvedLiteral(Value::NullString()));
  TestAlgebrizeExpression(null_string.get(), "ConstExpr(String(NULL))");
}

TEST_F(StatementAlgebrizerTest, SingleRowScan) {
  // Create a resolved AST for a single row scan with zero columns.
  ResolvedColumnList zero_columns;
  std::unique_ptr<const ResolvedScan> single_row_scan(
      MakeResolvedSingleRowScan(zero_columns));
  // Algebrize the resolved AST and check the result.
  std::unique_ptr<const AlgebraNode> algebrized_scan(
      algebrizer_->AlgebrizeScan(single_row_scan.get()).value());
  EXPECT_EQ("EnumerateOp(ConstExpr(1))", algebrized_scan->DebugString());
}

TEST_F(StatementAlgebrizerTest, TableScanAsArrayType) {
  // Create a resolved AST for a table scan.
  std::unique_ptr<const ResolvedTableScan> table_scan(
      MakeResolvedTableScan(columns_, &table_, nullptr));
  // Algebrize the resolved AST and check the result.
  std::unique_ptr<const AlgebraNode> algebrized_scan(
      algebrizer_->AlgebrizeScan(table_scan.get()).value());
  std::string expected = ScanTableAllTypesAsArrayExprString(0 /* indent */);
  EXPECT_EQ(expected, algebrized_scan->DebugString());
}

TEST_F(AlgebrizerTestBase, TableScanAsIterator) {
  auto table_scan = MakeResolvedTableScan(columns_, &table_,
                                          /*for_system_time_expr=*/nullptr);
  for (int i = 0; i < columns_.size(); ++i) {
    table_scan->add_column_index_list(i);
  }

  // Algebrize the resolved AST and check the result.
  ZETASQL_ASSERT_OK_AND_ASSIGN(std::unique_ptr<const AlgebraNode> algebrized_scan,
                       algebrizer_->AlgebrizeScan(table_scan.get()));
  EXPECT_EQ(algebrized_scan->DebugString(),
            "EvaluatorTableScanOp(\n"
            "+-col_int32#0\n"
            "+-col_uint32#1\n"
            "+-col_int64#2\n"
            "+-col_uint64#3\n"
            "+-col_string#4\n"
            "+-col_bool#5\n"
            "+-col_double#6\n"
            "+-table: table_all_types)");

  // Another test, this time just scanning two columns and providing an alias.
  const ResolvedColumnList two_column_list = {columns_[0], columns_[1]};
  auto two_column_scan = MakeResolvedTableScan(two_column_list, &table_,
                                               /*for_system_time_expr=*/nullptr,
                                               kAllTypesTableAlias);
  for (int i = 0; i < two_column_list.size(); ++i) {
    two_column_scan->add_column_index_list(i);
  }
  ZETASQL_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<const AlgebraNode> algebrized_two_column_scan,
      algebrizer_->AlgebrizeScan(two_column_scan.get()));
  EXPECT_EQ(algebrized_two_column_scan->DebugString(),
            "EvaluatorTableScanOp(\n"
            "+-col_int32#0\n"
            "+-col_uint32#1\n"
            "+-table: table_all_types\n"
            "+-alias: table_all_types_alias)");

  // A test with no columns and no table aliases.
  auto zero_column_scan = MakeResolvedTableScan(
      ResolvedColumnList(), &table_, /*for_system_time_expr=*/nullptr);
  ZETASQL_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<const AlgebraNode> algebrized_zero_column_scan,
      algebrizer_->AlgebrizeScan(zero_column_scan.get()));
  EXPECT_EQ(algebrized_zero_column_scan->DebugString(),
            "EvaluatorTableScanOp(\n"
            "+-table: table_all_types)");
}

TEST_F(StatementAlgebrizerTest, SingleRowSelect) {
  // Create a resolved AST for a select:
  // SELECT 101, "Hello world", true, 2.71828, null;
  std::vector<std::pair<const Type*, Value>> rows = {
      {Int64Type(), Value::Int64(101)},
      {StringType(), Value::String("Hello world")},
      {BoolType(), Value::Bool(true)},
      {DoubleType(), Value::Double(2.71828)},
      {Int64Type(), Value::NullInt64()}};
  int column_id = 1;
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> constants;
  for (int i = 0; i < rows.size(); ++i) {
    ResolvedColumn column(
        column_id, zetasql::IdString::MakeGlobal("$query"),
        zetasql::IdString::MakeGlobal(absl::StrCat("$col", column_id)),
        rows[i].first);
    auto literal = MakeResolvedLiteral(rows[i].second);
    constants.push_back(MakeResolvedComputedColumn(column, std::move(literal)));
    column_id++;
  }
  auto scan = MakeResolvedSingleRowScan();
  std::unique_ptr<ResolvedProjectScan> single_row_select =
      CreateResolvedProjectScan(std::move(constants), std::move(scan));
  // Algebrize the resolved AST and check the result.
  ZETASQL_ASSERT_OK_AND_ASSIGN(std::unique_ptr<const AlgebraNode> algebrized_select,
                       AlgebrizeAndNestInStruct(single_row_select.get()));
  EXPECT_EQ(
      "ArrayNestExpr(is_with_table=0\n"
      "+-element: NewStructExpr(\n"
      "| +-type: STRUCT<INT64, STRING, BOOL, DOUBLE, INT64>,\n"
      "| +-0 : $col1,\n"
      "| +-1 : $col2,\n"
      "| +-2 : $col3,\n"
      "| +-3 : $col4,\n"
      "| +-4 : $col5),\n"
      "+-input: ComputeOp(\n"
      "  +-map: {\n"
      "  | +-$col1 := ConstExpr(101),\n"
      "  | +-$col2 := ConstExpr(\"Hello world\"),\n"
      "  | +-$col3 := ConstExpr(true),\n"
      "  | +-$col4 := ConstExpr(2.71828),\n"
      "  | +-$col5 := ConstExpr(NULL)},\n"
      "  +-input: EnumerateOp(ConstExpr(1))))",
      algebrized_select->DebugString());
}

TEST_F(ExpressionAlgebrizerTest, Parameters) {
  // Create snippets of resolved ASTs for two occurrences of parameter "p"
  // and one occurrence of parameter "q".
  auto p1 = MakeResolvedParameter(Int64Type(), "p");
  auto p2 = MakeResolvedParameter(Int64Type(), "p");
  auto q = MakeResolvedParameter(StringType(), "q");
  ZETASQL_ASSERT_OK_AND_ASSIGN(std::unique_ptr<const ValueExpr> result_p1,
                       algebrizer_->AlgebrizeExpression(p1.get()));
  const ParameterMap& parameter_map = parameters_.named_parameters();
  EXPECT_EQ(1, parameter_map.size());
  ZETASQL_ASSERT_OK_AND_ASSIGN(std::unique_ptr<const ValueExpr> result_p2,
                       algebrizer_->AlgebrizeExpression(p2.get()));
  EXPECT_EQ(1, parameter_map.size());  // same param yields same var
  ZETASQL_ASSERT_OK_AND_ASSIGN(std::unique_ptr<const ValueExpr> result_q,
                       algebrizer_->AlgebrizeExpression(q.get()));
  EXPECT_EQ(2, parameter_map.size());
  const VariableId* p_param = zetasql_base::FindOrNull(parameter_map, "p");
  ASSERT_NE(p_param, nullptr);
  const VariableId* q_param = zetasql_base::FindOrNull(parameter_map, "q");
  ASSERT_NE(q_param, nullptr);
  EXPECT_TRUE(p_param->is_valid());
  EXPECT_TRUE(q_param->is_valid());
  EXPECT_NE(*p_param, *q_param);
  EXPECT_TRUE(result_p1->output_type()->IsInt64());
  EXPECT_TRUE(result_p2->output_type()->IsInt64());
  EXPECT_TRUE(result_q->output_type()->IsString());
  EXPECT_EQ("DerefExpr(p)", result_p1->DebugString(true /*verbose*/));
}

TEST_F(ExpressionAlgebrizerTest, PositionalParametersInStatements) {
  // Build a list of ResolvedParameters and corresponding ResolvedColumns.
  // A NULL ResolvedParameter/ResolvedColumn represents a gap.
  std::vector<
      std::tuple<std::unique_ptr<ResolvedParameter>, const ResolvedParameter*,
                 std::unique_ptr<ResolvedColumn>>>
      params_and_columns;
  for (int pos = 1; pos <= 3; ++pos) {
    // Create a gap in 'params_and_columns'.
    if (pos == 2) {
      params_and_columns.emplace_back(nullptr, nullptr, nullptr);
    } else {
      const Type* type = (pos == 1 ? StringType() : Int64Type());

      auto param = MakeResolvedParameter(type, /*name=*/"", pos,
                                         /*is_untyped=*/false);

      const std::string column_name = absl::StrCat("p", param->position());
      auto column = absl::make_unique<ResolvedColumn>(
          pos, IdString::MakeGlobal("TableName"),
          IdString::MakeGlobal(column_name), type);

      const ResolvedParameter* param_ptr = param.get();
      params_and_columns.emplace_back(std::move(param), param_ptr,
                                      std::move(column));
    }
  }

  // Build a single-row query that returns the resolved parameters. After this,
  // 'params_and_columns' no longer owns the ResolvedParameters (so its
  // unique_ptrs are NULL), but the other pointers are still valid.
  auto query = MakeResolvedQueryStmt();
  auto scan = MakeResolvedProjectScan();
  scan->set_input_scan(MakeResolvedSingleRowScan());
  for (auto& param_and_column : params_and_columns) {
    std::unique_ptr<ResolvedParameter>& param = std::get<0>(param_and_column);
    if (param == nullptr) continue;

    const ResolvedColumn& column = *std::get<2>(param_and_column);

    query->add_output_column_list(
        MakeResolvedOutputColumn(column.name(), column));

    scan->add_expr_list(MakeResolvedComputedColumn(column, std::move(param)));
    scan->add_column_list(column);
  }
  query->set_query(std::move(scan));

  parameters_.set_named(false);
  std::unique_ptr<ValueExpr> result;
  ZETASQL_ASSERT_OK(Algebrizer::AlgebrizeStatement(
      LanguageOptions(), AlgebrizerOptions(), &type_factory_, query.get(),
      &result, &parameters_, &column_map_, &system_variables_map_));

  const ParameterList& parameter_list = parameters_.positional_parameters();
  ASSERT_EQ(params_and_columns.size(), parameter_list.size());
  for (int i = 0; i < params_and_columns.size(); ++i) {
    const bool gap = (std::get<2>(params_and_columns[i]) == nullptr);
    const VariableId& variable = parameter_list[i];
    if (gap) {
      EXPECT_FALSE(variable.is_valid());
    } else {
      const ResolvedParameter& param = *std::get<1>(params_and_columns[i]);
      EXPECT_TRUE(variable.is_valid());
      EXPECT_THAT(result->DebugString(/*verbose=*/true),
                  HasSubstr(absl::Substitute("DerefExpr(positional_param_$0)",
                                             param.position())));
    }
  }
}

TEST_F(ExpressionAlgebrizerTest, PositionalParametersInExpressions) {
  // Create snippets of resolved ASTs for occurrences of parameters at different
  // positions.
  auto first_param = MakeResolvedParameter(Int64Type(), "", /*position=*/1,
                                           /*is_untyped=*/false);
  auto second_param = MakeResolvedParameter(Int64Type(), "", /*position=*/2,
                                            /*is_untyped=*/false);
  auto third_param = MakeResolvedParameter(StringType(), "", /*position=*/3,
                                           /*is_untyped=*/false);

  parameters_.set_named(false);
  for (const ResolvedParameter* resolved_parameter :
       {first_param.get(), second_param.get(), third_param.get()}) {
    ZETASQL_ASSERT_OK_AND_ASSIGN(std::unique_ptr<const ValueExpr> result,
                         algebrizer_->AlgebrizeExpression(resolved_parameter));

    const ParameterList& parameter_list = parameters_.positional_parameters();
    ASSERT_EQ(resolved_parameter->position(), parameter_list.size());

    EXPECT_TRUE(parameter_list[resolved_parameter->position() - 1].is_valid());
    EXPECT_EQ(absl::Substitute("DerefExpr(positional_param_$0)",
                               resolved_parameter->position()),
              result->DebugString(/*verbose=*/true));
  }

  // Verifies that Algebrizer::AlgebrizeExpression can handle gaps.
  std::unique_ptr<ValueExpr> output;
  Parameters parameters(ParameterList{});
  ParameterMap column_map;
  SystemVariablesAlgebrizerMap system_variables_map;
  ZETASQL_ASSERT_OK(Algebrizer::AlgebrizeExpression(
      LanguageOptions(), AlgebrizerOptions(), &type_factory_,
      second_param.get(), &output, &parameters, &column_map,
      &system_variables_map));
  ASSERT_EQ(2, parameters.positional_parameters().size());
  EXPECT_FALSE(parameters.positional_parameters()[0].is_valid());
  EXPECT_TRUE(parameters.positional_parameters()[1].is_valid());
  EXPECT_EQ(absl::Substitute("RootExpr(DerefExpr(positional_param_$0))",
                             second_param->position()),
            output->DebugString(/*verbose=*/true));
}

TEST_F(StatementAlgebrizerTest, TableSelectAll) {
  // This test selects every column from a table with one column of every type.
  auto table_scan = MakeResolvedTableScan(columns_, &table_, nullptr);
  // Reference the columns in reverse order that they appear in the table.
  // Use reverse order to test that algebrization doesn't depend on the
  // ordering of the columns.
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> column_refs;
  for (int i = columns_.size() - 1; i >= 0 ; --i) {
    column_refs.push_back(MakeResolvedComputedColumn(
        columns_[i], MakeResolvedColumnRef(columns_[i].type(), columns_[i],
                                           kNonCorrelated)));
  }
  std::unique_ptr<const ResolvedProjectScan> table_select =
      CreateResolvedProjectScan(std::move(column_refs), std::move(table_scan));
  // Algebrize the resolved AST and check the result.
  ZETASQL_ASSERT_OK_AND_ASSIGN(std::unique_ptr<const AlgebraNode> algebrized_select,
                       AlgebrizeAndNestInStruct(table_select.get()));
  std::string expected = absl::Substitute(
      "ArrayNestExpr(is_with_table=0\n"
      "+-element: NewStructExpr(\n"
      "| +-type: STRUCT<col_double DOUBLE, col_bool BOOL, col_string STRING, "
      "col_uint64 UINT64, col_int64 INT64, col_uint32 UINT32, col_int32 INT32>"
      ",\n"
      "| +-0 col_double: $$col_double,\n"
      "| +-1 col_bool: $$col_bool,\n"
      "| +-2 col_string: $$col_string,\n"
      "| +-3 col_uint64: $$col_uint64,\n"
      "| +-4 col_int64: $$col_int64,\n"
      "| +-5 col_uint32: $$col_uint32,\n"
      "| +-6 col_int32: $$col_int32),\n"
      "+-input: $0)",
      ScanTableAllTypesAsArrayExprString(2 /* indent */));
  EXPECT_EQ(expected, algebrized_select->DebugString());
}

// Parameters used for selecting columns.
struct SingleColumnSelect {
  int column_idx;  // Index of the single column to select.
  std::string
      struct_string;  // Debug string for the struct of the selected row.
  std::string column_string;  // Debug string for the column selection itself.
};

class AlgebrizerTestSelectColumn
    : public StatementAlgebrizerTest,
      public ::testing::WithParamInterface<SingleColumnSelect> {
 public:
  static std::vector<SingleColumnSelect> SelectColumnTests() {
    return {
        {kInt64ColIdx, "type: STRUCT<col_int64 INT64>",
         "0 col_int64: $col_int64)"},
        {kStringColIdx, "type: STRUCT<col_string STRING>",
         "0 col_string: $col_string)"},
        {kBoolColIdx, "type: STRUCT<col_bool BOOL>", "0 col_bool: $col_bool)"},
        {kDoubleColIdx, "type: STRUCT<col_double DOUBLE>",
         "0 col_double: $col_double)"}};
  }
};

TEST_P(AlgebrizerTestSelectColumn, SelectColumn) {
  SingleColumnSelect single_column = GetParam();
  int column_idx = single_column.column_idx;
  // Select a single column from a table with one column of every type.
  auto table_scan = MakeResolvedTableScan(columns_, &table_, nullptr);
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> column_refs;
  column_refs.push_back(MakeResolvedComputedColumn(
      columns_[column_idx],
      MakeResolvedColumnRef(columns_[column_idx].type(), columns_[column_idx],
                            kNonCorrelated)));
  std::unique_ptr<const ResolvedProjectScan> table_select =
      CreateResolvedProjectScan(std::move(column_refs), std::move(table_scan));
  // Algebrize the resolved AST and check the result.
  ZETASQL_ASSERT_OK_AND_ASSIGN(std::unique_ptr<const AlgebraNode> algebrized_select,
                       AlgebrizeAndNestInStruct(table_select.get()));
  EXPECT_THAT(algebrized_select->DebugString(),
              HasSubstr(single_column.struct_string));
  EXPECT_THAT(algebrized_select->DebugString(),
              HasSubstr(single_column.column_string));
}

INSTANTIATE_TEST_SUITE_P(
    AlgebrizeTableSelectSingleColumn, AlgebrizerTestSelectColumn,
    ValuesIn(AlgebrizerTestSelectColumn::SelectColumnTests()));

// Algebrizer::Parameters used for testing functions.
struct FunctionTest {
  const ResolvedExpr* function;
  std::string return_type;
  std::string function_call;
};

class AlgebrizerTestFunctions
    : public ExpressionAlgebrizerTest,
      public ::testing::WithParamInterface<FunctionTest> {
 public:
  static const Function* fn_equal;
  static const Function* fn_add;
  static const Function* fn_subtract;
  static const Function* fn_unary_minus;
  static const Function* fn_and;
  static const Function* fn_not;
  static const Function* fn_or;

  static std::vector<std::unique_ptr<const ResolvedExpr>> OneInt64Literal() {
    return MakeNodeVectorP<const ResolvedExpr>(
        MakeResolvedLiteral(Value::Int64(13)));
  }
  static std::vector<std::unique_ptr<const ResolvedExpr>> TwoInt64Literals() {
    return MakeNodeVectorP<const ResolvedExpr>(
        MakeResolvedLiteral(Value::Int64(13)),
        MakeResolvedLiteral(Value::Int64(7)));
  }
  static std::vector<std::unique_ptr<const ResolvedExpr>> TwoStringLiterals() {
    return MakeNodeVectorP<const ResolvedExpr>(
        MakeResolvedLiteral(Value::String("Hello")),
        MakeResolvedLiteral(Value::String("World")));
  }
  static std::vector<std::unique_ptr<const ResolvedExpr>> OneBoolLiteral() {
    return MakeNodeVectorP<const ResolvedExpr>(
        MakeResolvedLiteral(Value::Bool(false)));
  }
  static std::vector<std::unique_ptr<const ResolvedExpr>> TwoBoolLiterals() {
    return MakeNodeVectorP<const ResolvedExpr>(
        MakeResolvedLiteral(Value::Bool(true)),
        MakeResolvedLiteral(Value::Bool(false)));
  }
  static std::vector<std::unique_ptr<const ResolvedExpr>> OneDoubleLiteral() {
    return MakeNodeVectorP<const ResolvedExpr>(
        MakeResolvedLiteral(Value::Double(2.71828)));
  }
  static std::vector<std::unique_ptr<const ResolvedExpr>> TwoDoubleLiterals() {
    return MakeNodeVectorP<const ResolvedExpr>(
        MakeResolvedLiteral(Value::Double(0.01)),
        MakeResolvedLiteral(Value::Double(2.71828)));
  }
  static std::vector<FunctionTest> AllFunctionTests() {
    FunctionSignature bool_int64_int64(BoolType(), {Int64Type(), Int64Type()},
                                       -1 /* context_id */);
    FunctionSignature bool_string_string(BoolType(),
                                         {StringType(), StringType()},
                                         -1 /* context_id */);
    FunctionSignature bool_bool(BoolType(), {BoolType()},
                                -1 /* context_id */);
    FunctionSignature bool_bool_bool(BoolType(), {BoolType(), BoolType()},
                                     -1 /* context_id */);
    FunctionSignature bool_double_double(BoolType(),
                                         {DoubleType(), DoubleType()},
                                         -1 /* context_id */);
    FunctionSignature int64_int64(Int64Type(), {Int64Type()}, -1);
    FunctionSignature int64_int64_int64(Int64Type(), {Int64Type(), Int64Type()},
                                        -1);
    FunctionSignature double_double(DoubleType(), {DoubleType()},
                                    -1 /* context_id */);
    FunctionSignature double_double_double(DoubleType(),
                                           {DoubleType(), DoubleType()},
                                           -1 /* context_id */);

    std::vector<FunctionTest> functions = {
        // "Equal" function.
        {MakeResolvedFunctionCall(BoolType(), fn_equal, bool_int64_int64,
                                  TwoInt64Literals(), DEFAULT_ERROR_MODE)
             .release(),
         "BOOL", "Equal(ConstExpr(13), ConstExpr(7))"},
        {MakeResolvedFunctionCall(BoolType(), fn_equal, bool_string_string,
                                  TwoStringLiterals(), DEFAULT_ERROR_MODE)
             .release(),
         "BOOL", "Equal(ConstExpr(\"Hello\"), ConstExpr(\"World\"))"},
        {MakeResolvedFunctionCall(BoolType(), fn_equal, bool_bool_bool,
                                  TwoBoolLiterals(), DEFAULT_ERROR_MODE)
             .release(),
         "BOOL", "Equal(ConstExpr(true), ConstExpr(false))"},
        {MakeResolvedFunctionCall(BoolType(), fn_equal, bool_double_double,
                                  TwoDoubleLiterals(), DEFAULT_ERROR_MODE)
             .release(),
         "BOOL", "Equal(ConstExpr(0.01), ConstExpr(2.71828))"},
        // "Add" function.
        {MakeResolvedFunctionCall(Int64Type(), fn_add, int64_int64_int64,
                                  TwoInt64Literals(), DEFAULT_ERROR_MODE)
             .release(),
         "INT64", "Add(ConstExpr(13), ConstExpr(7))"},
        {MakeResolvedFunctionCall(DoubleType(), fn_add, double_double_double,
                                  TwoDoubleLiterals(), DEFAULT_ERROR_MODE)
             .release(),
         "DOUBLE", "Add(ConstExpr(0.01), ConstExpr(2.71828))"},
        {MakeResolvedFunctionCall(Int64Type(), fn_subtract, int64_int64_int64,
                                  TwoInt64Literals(), DEFAULT_ERROR_MODE)
             .release(),
         "INT64", "Subtract(ConstExpr(13), ConstExpr(7))"},
        {MakeResolvedFunctionCall(DoubleType(), fn_subtract,
                                  double_double_double, TwoDoubleLiterals(),
                                  DEFAULT_ERROR_MODE)
             .release(),
         "DOUBLE", "Subtract(ConstExpr(0.01), ConstExpr(2.71828))"},
        {MakeResolvedFunctionCall(Int64Type(), fn_unary_minus, int64_int64,
                                  OneInt64Literal(), DEFAULT_ERROR_MODE)
             .release(),
         "INT64", "UnaryMinus(ConstExpr(13))"},
        {MakeResolvedFunctionCall(DoubleType(), fn_unary_minus, double_double,
                                  OneDoubleLiteral(), DEFAULT_ERROR_MODE)
             .release(),
         "DOUBLE", "UnaryMinus(ConstExpr(2.71828))"},
        // "And" function.
        {MakeResolvedFunctionCall(BoolType(), fn_and, bool_bool_bool,
                                  TwoBoolLiterals(), DEFAULT_ERROR_MODE)
             .release(),
         "BOOL", "And(ConstExpr(true), ConstExpr(false))"},
        // "Not" function.
        {MakeResolvedFunctionCall(BoolType(), fn_not, bool_bool,
                                  OneBoolLiteral(), DEFAULT_ERROR_MODE)
             .release(),
         "BOOL", "Not(ConstExpr(false))"},
        // "Or" function.
        {MakeResolvedFunctionCall(BoolType(), fn_or, bool_bool_bool,
                                  TwoBoolLiterals(), DEFAULT_ERROR_MODE)
             .release(),
         "BOOL", "Or(ConstExpr(true), ConstExpr(false))"},
    };
    return functions;
  }
};

const Function* AlgebrizerTestFunctions::fn_equal =
    new Function("$equal", Function::kZetaSQLFunctionGroupName,
                 Function::SCALAR);
const Function* AlgebrizerTestFunctions::fn_add =
    new Function("$add", Function::kZetaSQLFunctionGroupName,
                 Function::SCALAR);
const Function* AlgebrizerTestFunctions::fn_subtract =
    new Function("$subtract", Function::kZetaSQLFunctionGroupName,
                 Function::SCALAR);
const Function* AlgebrizerTestFunctions::fn_unary_minus =
    new Function("$unary_minus", Function::kZetaSQLFunctionGroupName,
                 Function::SCALAR);
const Function* AlgebrizerTestFunctions::fn_and =
    new Function("$and", Function::kZetaSQLFunctionGroupName,
                 Function::SCALAR);
const Function* AlgebrizerTestFunctions::fn_not =
    new Function("$not", Function::kZetaSQLFunctionGroupName,
                 Function::SCALAR);
const Function* AlgebrizerTestFunctions::fn_or =
    new Function("$or", Function::kZetaSQLFunctionGroupName,
                 Function::SCALAR);

// This test algebrizes functions in isolation.
TEST_P(AlgebrizerTestFunctions, Functions) {
  FunctionTest function_test = GetParam();
  absl::StatusOr<std::unique_ptr<ValueExpr>> fct =
      algebrizer_->AlgebrizeExpression(function_test.function);
  EXPECT_EQ(function_test.function_call, fct.value()->DebugString());
}

INSTANTIATE_TEST_SUITE_P(TestFunctions, AlgebrizerTestFunctions,
                         ValuesIn(AlgebrizerTestFunctions::AllFunctionTests()));

// This test algebrizes functions in the context of a select.
TEST_P(AlgebrizerTestFunctions, SelectFunctions) {
  FunctionTest function_test = GetParam();
  auto scan = MakeResolvedSingleRowScan();
  const int kColumnId = 1;
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> select_list;
  select_list.push_back(MakeResolvedComputedColumn(
      ResolvedColumn(kColumnId, zetasql::IdString::MakeGlobal("$query"),
                     zetasql::IdString::MakeGlobal("$col1"),
                     function_test.function->type()),
      absl::WrapUnique(function_test.function)));
  std::unique_ptr<ResolvedProjectScan> single_row_select =
      CreateResolvedProjectScan(std::move(select_list), std::move(scan));
  // Algebrize the resolved AST and check the result.
  ZETASQL_ASSERT_OK_AND_ASSIGN(std::unique_ptr<const AlgebraNode> algebrized_select,
                       AlgebrizeAndNestInStruct(single_row_select.get()));
  // Construct the expected output with a mixture of fixed strings and results
  // from the current algebrization.
  std::string expected = absl::Substitute(
      "ArrayNestExpr(\n"
      "  element: NewStructExpr(\n    type: STRUCT<__col_0 $0>,\n"
      "    0 __col_0: $1),\n"
      "  input: ArrayScanOp(\n"
      "    array: NewArrayExpr(NewStructExpr(\n"
      "        type: STRUCT<>,\n"
      "        ))))",
      function_test.return_type, function_test.function_call);
}

INSTANTIATE_TEST_SUITE_P(AlgebrizerTestSelectFunctionsTest,
                         AlgebrizerTestFunctions,
                         ValuesIn(AlgebrizerTestFunctions::AllFunctionTests()));

// Tests that the algebrizer does not crash on unknown functions.
// TODO: add a test that calls the top-level Algebrize() method
// on a query that uses an unknown function to prevent crashes upon errors.
TEST_F(ExpressionAlgebrizerTest, UnknownFunction) {
  FunctionSignature bool_int64(BoolType(), {Int64Type()}, -1 /* context_id */);
  Function bogus_function("ThisIsNotAValidFunctionName", "function_group",
                          Function::SCALAR);
  auto function_call = MakeResolvedFunctionCall(
      BoolType(), &bogus_function, bool_int64,
      AlgebrizerTestFunctions::OneInt64Literal(), DEFAULT_ERROR_MODE);
  absl::StatusOr<std::unique_ptr<const ValueExpr>> fct =
      TestAlgebrizeExpressionInternal(function_call.get());
  ASSERT_FALSE(fct.ok());
}

// Algebrizer::Parameters used for a single filter test.
struct FilterTest {
  FunctionSignature signature;  // Test input
  std::vector<const ResolvedExpr*> arguments;  // Test input
  std::string filter_condition;                // Test output
};

class AlgebrizerTestFilters : public StatementAlgebrizerTest,
                              public ::testing::WithParamInterface<FilterTest> {
 public:
  static std::vector<FilterTest> AllFilterTests() {
    FunctionSignature bool_int64_int64(BoolType(), {Int64Type(), Int64Type()},
                                       -1 /* context_id */);
    FunctionSignature bool_string_string(BoolType(),
                                         {StringType(), StringType()},
                                         -1 /* context_id */);
    FunctionSignature bool_bool_bool(BoolType(), {BoolType(), BoolType()},
                                     -1 /* context_id */);
    FunctionSignature bool_double_double(BoolType(),
                                         {DoubleType(), DoubleType()},
                                         -1 /* context_id */);
    return {
        // Compare a column to a constant.
        {bool_int64_int64,
         {MakeResolvedColumnRef(
              Int64Type(),
              ResolvedColumn(
                  kInt64ColId, zetasql::IdString::MakeGlobal(kAllTypesTable),
                  zetasql::IdString::MakeGlobal(kInt64Col), Int64Type()),
              kNonCorrelated)
              .release(),
          MakeResolvedLiteral(Value::Int64(101)).release()},
         "Equal($col_int64, ConstExpr(101))"},
        {bool_string_string,
         {MakeResolvedColumnRef(
              StringType(),
              ResolvedColumn(
                  kStringColId, zetasql::IdString::MakeGlobal(kAllTypesTable),
                  zetasql::IdString::MakeGlobal(kStringCol), StringType()),
              kNonCorrelated)
              .release(),
          MakeResolvedLiteral(Value::String("Hello world")).release()},
         "Equal($col_string, ConstExpr(\"Hello world\"))"},
        {bool_bool_bool,
         {MakeResolvedColumnRef(
              BoolType(),
              ResolvedColumn(
                  kBoolColId, zetasql::IdString::MakeGlobal(kAllTypesTable),
                  zetasql::IdString::MakeGlobal(kBoolCol), BoolType()),
              kNonCorrelated)
              .release(),
          MakeResolvedLiteral(Value::Bool(true)).release()},
         "Equal($col_bool, ConstExpr(true))"},
        {bool_double_double,
         {MakeResolvedColumnRef(
              DoubleType(),
              ResolvedColumn(
                  kDoubleColId, zetasql::IdString::MakeGlobal(kAllTypesTable),
                  zetasql::IdString::MakeGlobal(kDoubleCol), DoubleType()),
              kNonCorrelated)
              .release(),
          MakeResolvedLiteral(Value::Double(2.71828)).release()},
         "Equal($col_double, ConstExpr(2.71828))"}};
  }
};

TEST_P(AlgebrizerTestFilters, Filters) {
  FilterTest parameters = GetParam();
  // Create a resolved AST for a table scan.
  auto table_scan = MakeResolvedTableScan(columns_, &table_, nullptr);
  // Create the function and the function signature.
  std::unique_ptr<const Function> equal_function(
      new Function("$equal", Function::kZetaSQLFunctionGroupName,
                   Function::SCALAR));
  FunctionSignature signature(ARG_TYPE_ANY_1,
                              {ARG_TYPE_ANY_1, ARG_TYPE_ANY_1},
                              -1);
  // Create the complete filter expression.
  auto filter_expr =
      MakeResolvedFunctionCall(BoolType(), equal_function.get(), signature,
                               parameters.arguments, DEFAULT_ERROR_MODE);
  // Create the filter scan above the table scan.
  auto filter_scan = MakeResolvedFilterScan(columns_, std::move(table_scan),
                                            std::move(filter_expr));
  // Algebrize the resolved AST and check the result.
  std::unique_ptr<const AlgebraNode> algebrized_filter(
      algebrizer_->AlgebrizeScan(filter_scan.get()).value());
  std::string expected = absl::Substitute(
      "FilterOp(\n"
      "+-condition: $0,\n"
      "+-input:",
      parameters.filter_condition);
  EXPECT_THAT(algebrized_filter->DebugString(), testing::HasSubstr(expected));
}

INSTANTIATE_TEST_SUITE_P(AlgebrizerTestFiltersTest, AlgebrizerTestFilters,
                         ValuesIn(AlgebrizerTestFilters::AllFilterTests()));

TEST_F(StatementAlgebrizerTest, SubqueryInFrom) {
  // Build a resolved AST for a query based on the following template with all
  // column types represented:
  //   SELECT <columns> FROM (SELECT <columns> FROM <kAllTypesTable>);
  // Then algebrize the AST and check the result.
  // Build the base table scan.
  auto table_scan = MakeResolvedTableScan(columns_, &table_, nullptr);
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> column_refs;
  for (int i = 0; i < columns_.size(); ++i) {
    auto column_ref =
        MakeResolvedColumnRef(columns_[i].type(), columns_[i], kNonCorrelated);
    column_refs.push_back(
        MakeResolvedComputedColumn(columns_[i], std::move(column_ref)));
  }
  std::unique_ptr<ResolvedProjectScan> lower_project =
      CreateResolvedProjectScan(std::move(column_refs), std::move(table_scan));
  const ResolvedColumnList& project_columns =
      lower_project->column_list();
  // Put a project over the lower project.
  // Build the column references.
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> upper_column_refs;
  for (int i = 0; i < project_columns.size(); ++i) {
    auto column_ref = MakeResolvedColumnRef(project_columns[i].type(),
                                            project_columns[i], kNonCorrelated);
    upper_column_refs.push_back(MakeResolvedComputedColumn(
        lower_project->column_list()[i], std::move(column_ref)));
  }
  std::unique_ptr<const ResolvedProjectScan> upper_project(
      CreateResolvedProjectScan(std::move(upper_column_refs),
                                std::move(lower_project)));
  ZETASQL_ASSERT_OK_AND_ASSIGN(std::unique_ptr<const AlgebraNode> algebrized_select,
                       AlgebrizeAndNestInStruct(upper_project.get()));
  std::string expected = absl::Substitute(
      "ArrayNestExpr(is_with_table=0\n"
      "+-element: NewStructExpr(\n"
      "| +-type: STRUCT<col_int32 INT32, col_uint32 UINT32, col_int64 INT64, "
      "col_uint64 UINT64, col_string STRING, col_bool BOOL, col_double DOUBLE>,"
      "\n"
      "| +-0 col_int32: $$col_int32,\n"
      "| +-1 col_uint32: $$col_uint32,\n"
      "| +-2 col_int64: $$col_int64,\n"
      "| +-3 col_uint64: $$col_uint64,\n"
      "| +-4 col_string: $$col_string,\n"
      "| +-5 col_bool: $$col_bool,\n"
      "| +-6 col_double: $$col_double),\n"
      "+-input: $0)",
      ScanTableAllTypesAsArrayExprString(2 /* indent */));
  EXPECT_EQ(expected, algebrized_select->DebugString());
}

TEST_F(StatementAlgebrizerTest, CrossApply) {
  // Build a resolved AST for a self cross join of table_all_types.
  int column_id = 1;
  std::unique_ptr<const ResolvedTableScan> left_table_scan =
      ScanTableAllTypes(&column_id);
  std::unique_ptr<const ResolvedTableScan> right_table_scan =
      ScanTableAllTypes2(&column_id);
  // Build the output columns of the cross join (all columns from each child).
  ResolvedColumnList join_output_columns;
  ResolvedColumnList left_columns = left_table_scan->column_list();
  for (int i = 0; i < left_columns.size(); ++i) {
    join_output_columns.push_back(left_columns[i]);
  }
  ResolvedColumnList right_columns = right_table_scan->column_list();
  for (int i = 0; i < right_columns.size(); ++i) {
    join_output_columns.push_back(right_columns[i]);
  }
  // Build the join scan.
  auto join_scan = MakeResolvedJoinScan(
      join_output_columns, ResolvedJoinScan::INNER, std::move(left_table_scan),
      std::move(right_table_scan), nullptr /* condition */);
  // Algebrize the resolved AST and check the result.
  std::unique_ptr<const AlgebraNode> algebrized_cross_apply(
      algebrizer_->AlgebrizeScan(join_scan.get()).value());
  std::string expected =
      "JoinOp\\(INNER\n"
      "..hash_join_equality_left_exprs: \\{\\},\n"
      "..hash_join_equality_right_exprs: \\{\\},\n"
      "..remaining_condition: ConstExpr\\(true\\),\n"
      "..left_input: ArrayScanOp\\(\n(.*\n)*.*\\),\n"
      "..right_input: ArrayScanOp\\(\n(.*\n)*.*\\)\\)";
  EXPECT_THAT(algebrized_cross_apply->DebugString(),
              testing::MatchesRegex(expected))
      << algebrized_cross_apply->DebugString();
}

class AlgebrizerTestJoins : public StatementAlgebrizerTest,
                            public ::testing::WithParamInterface<FilterTest> {
 public:
  static std::vector<FilterTest> AllJoinTests() {
    FunctionSignature bool_int64_int64(BoolType(), {Int64Type(), Int64Type()},
                                       -1 /* context_id */);
    FunctionSignature bool_string_string(BoolType(),
                                         {StringType(), StringType()},
                                         -1 /* context_id */);
    FunctionSignature bool_bool_bool(BoolType(), {BoolType(), BoolType()},
                                     -1 /* context_id */);
    FunctionSignature bool_double_double(BoolType(),
                                         {DoubleType(), DoubleType()},
                                         -1 /* context_id */);
    return {
        {bool_bool_bool,
         {MakeResolvedColumnRef(
              BoolType(),
              ResolvedColumn(
                  kBoolColId, zetasql::IdString::MakeGlobal(kAllTypesTable),
                  zetasql::IdString::MakeGlobal(kBoolCol), BoolType()),
              kNonCorrelated)
              .release(),
          MakeResolvedColumnRef(
              BoolType(),
              ResolvedColumn(
                  kBoolColId2, zetasql::IdString::MakeGlobal(kAllTypesTable2),
                  zetasql::IdString::MakeGlobal(kBoolCol2), BoolType()),
              kNonCorrelated)
              .release()},
         "Equal\\(\\$col_bool, \\$col_bool.2\\)"},
        {bool_double_double,
         {MakeResolvedColumnRef(
              DoubleType(),
              ResolvedColumn(
                  kDoubleColId, zetasql::IdString::MakeGlobal(kAllTypesTable),
                  zetasql::IdString::MakeGlobal(kDoubleCol), DoubleType()),
              kNonCorrelated)
              .release(),
          MakeResolvedColumnRef(
              DoubleType(),
              ResolvedColumn(kDoubleColId2,
                             zetasql::IdString::MakeGlobal(kAllTypesTable2),
                             zetasql::IdString::MakeGlobal(kDoubleCol2),
                             DoubleType()),
              kNonCorrelated)
              .release()},
         "Equal\\(\\$col_double, \\$col_double.2\\)"},
        {bool_int64_int64,
         {MakeResolvedColumnRef(
              Int64Type(),
              ResolvedColumn(
                  kInt64ColId, zetasql::IdString::MakeGlobal(kAllTypesTable),
                  zetasql::IdString::MakeGlobal(kInt64Col), Int64Type()),
              kNonCorrelated)
              .release(),
          MakeResolvedColumnRef(
              Int64Type(),
              ResolvedColumn(kInt64ColId2,
                             zetasql::IdString::MakeGlobal(kAllTypesTable2),
                             zetasql::IdString::MakeGlobal(kInt64Col2),
                             Int64Type()),
              kNonCorrelated)
              .release()},
         "Equal\\(\\$col_int64, \\$col_int64.2\\)"},
        {bool_string_string,
         {MakeResolvedColumnRef(
              StringType(),
              ResolvedColumn(
                  kStringColId, zetasql::IdString::MakeGlobal(kAllTypesTable),
                  zetasql::IdString::MakeGlobal(kStringCol), StringType()),
              kNonCorrelated)
              .release(),
          MakeResolvedColumnRef(
              StringType(),
              ResolvedColumn(kStringColId2,
                             zetasql::IdString::MakeGlobal(kAllTypesTable2),
                             zetasql::IdString::MakeGlobal(kStringCol2),
                             StringType()),
              kNonCorrelated)
              .release()},
         "Equal\\(\\$col_string, \\$col_string.2\\)"}};
  }
};

TEST_P(AlgebrizerTestJoins, InnerJoin) {
  FilterTest parameters = GetParam();
  // Build a resolved AST for a join of table_all_types with itself.
  // The resolved AST looks more or less like the following (column id's will
  // vary as types are added).
  // JoinScan
  // +-column_list=[table_all_types.col_int64#1, ...,
  //                    table_all_types_2.col_int64.2#5, ...]
  // +-left=
  // | +-TableScan(column_list=table_all_types.[col_int64#1, ...],
  //                   table=table_all_types)
  // +-right=
  // | +-TableScan(column_list=table_all_types_2.[col_int64.2#5, ...],
  //                   table=table_all_types_2)
  // +-condition=
  //   +-FunctionCall(function_group:$equal(<T1>, <T1>) -> <T1>)
  //     +-ColumnRef(type=BOOL, column=table_all_types.col_bool#3)
  //     +-ColumnRef(type=BOOL, column=table_all_types_2.col_bool.2#7)
  int column_id = 1;
  std::unique_ptr<const ResolvedTableScan> left_table_scan =
      ScanTableAllTypes(&column_id);
  std::unique_ptr<const ResolvedTableScan> right_table_scan =
      ScanTableAllTypes2(&column_id);
  // Build the output columns of the cross join (all columns from each child).
  ResolvedColumnList join_output_columns;
  ResolvedColumnList left_columns = left_table_scan->column_list();
  for (int i = 0; i < left_columns.size(); ++i) {
    join_output_columns.push_back(left_columns[i]);
  }
  ResolvedColumnList right_columns = right_table_scan->column_list();
  for (int i = 0; i < right_columns.size(); ++i) {
    join_output_columns.push_back(right_columns[i]);
  }
  // Create the join condition.
  std::unique_ptr<const Function> equal_function(
      new Function("$equal", Function::kZetaSQLFunctionGroupName,
                   Function::SCALAR));
  FunctionSignature signature(ARG_TYPE_ANY_1,
                              {ARG_TYPE_ANY_1, ARG_TYPE_ANY_1},
                              -1);
  auto join_expr =
      MakeResolvedFunctionCall(BoolType(), equal_function.get(), signature,
                               parameters.arguments, DEFAULT_ERROR_MODE);
  // Build the join scan.
  auto join_scan = MakeResolvedJoinScan(
      join_output_columns, ResolvedJoinScan::INNER, std::move(left_table_scan),
      std::move(right_table_scan), std::move(join_expr));
  // Algebrize the resolved AST and check the result.
  std::unique_ptr<const AlgebraNode> algebrized_join(
      algebrizer_->AlgebrizeScan(join_scan.get()).value());
  std::string expected = absl::Substitute(
      "JoinOp\\(INNER\n"
      "..hash_join_equality_left_exprs: \\{\\},\n"
      "..hash_join_equality_right_exprs: \\{\\},\n"
      "..remaining_condition: $0,\n"
      "..left_input: ArrayScanOp\\(\n(.*\n)*.*\\),\n"
      "..right_input: ArrayScanOp\\(\n(.*\n)*.*\\)\\)",
      parameters.filter_condition);
  EXPECT_THAT(algebrized_join->DebugString(),
              testing::MatchesRegex(expected))
      << algebrized_join->DebugString()
      << "\nFilter: " << parameters.filter_condition;
}

INSTANTIATE_TEST_SUITE_P(InnerJoin, AlgebrizerTestJoins,
                         ValuesIn(AlgebrizerTestJoins::AllJoinTests()));

TEST_P(AlgebrizerTestJoins, CorrelatedInnerJoin) {
  FilterTest parameters = GetParam();
  // Build a resolved AST for a join of table_all_types with table_all_types_2
  // with a correlated filter inside the map (aka inner or right) side.
  // The correlated filter is always on the integer column, the join column
  // varies over all possible types.
  // The resolved AST looks more or less like the following (column id's will
  // vary as types are added).
  // JoinScan
  // +-column_list=[table_all_types.col_int64#1, ...,
  //                    table_all_types_2.col_int64.2#5, ...]
  // +-left=
  // | +-TableScan(column_list=table_all_types.[col_int64#1, ...],
  //                   table=table_all_types)
  // +-right=
  // | +-FilterScan
  // |   +-column_list=table_all_types_2.[col_int64.2#5, ...]
  // |   +-input_scan=
  // |   | +-TableScan(column_list=table_all_types_2.[col_int64.2#5, ...],
  //                       table=table_all_types_2)
  // |   +-filter_expr=
  // |     +-FunctionCall(function_group:$equal(<T1>, <T1>) -> <T1>)
  // |       +-ColumnRef(type=INT64, column=table_all_types.col_int64#1)
  // |       +-ColumnRef(type=INT64, column=table_all_types_2.col_int64.2#5)
  // +-condition=
  //   +-FunctionCall(function_group:$equal(<T1>, <T1>) -> <T1>)
  //     +-ColumnRef(type=BOOL, column=table_all_types.col_bool#3)
  //     +-ColumnRef(type=BOOL, column=table_all_types_2.col_bool.2#7)
  int column_id = 1;
  std::unique_ptr<const ResolvedTableScan> left_table_scan =
      ScanTableAllTypes(&column_id);
  std::unique_ptr<const ResolvedTableScan> right_table_scan =
      ScanTableAllTypes2(&column_id);
  // Create the function and the function signature.
  std::unique_ptr<const Function> equal_filter_function(
      new Function("$equal", Function::kZetaSQLFunctionGroupName,
                   Function::SCALAR));
  FunctionSignature signature(ARG_TYPE_ANY_1,
                              {ARG_TYPE_ANY_1, ARG_TYPE_ANY_1},
                              -1);
  // Create a filter expression.
  auto filter_arguments = MakeNodeVector(
      MakeResolvedColumnRef(
          Int64Type(),
          ResolvedColumn(
              kInt64ColId, zetasql::IdString::MakeGlobal(kAllTypesTable),
              zetasql::IdString::MakeGlobal(kInt64Col), Int64Type()),
          kNonCorrelated),
      MakeResolvedColumnRef(
          Int64Type(),
          ResolvedColumn(
              kInt64ColId2, zetasql::IdString::MakeGlobal(kAllTypesTable2),
              zetasql::IdString::MakeGlobal(kInt64Col2), Int64Type()),
          kNonCorrelated));
  auto filter_expr = MakeResolvedFunctionCall(
      BoolType(), equal_filter_function.get(), signature,
      std::move(filter_arguments), DEFAULT_ERROR_MODE);
  // Create a filter scan above the table scan.
  auto filter_scan = MakeResolvedFilterScan(
      columns2_, std::move(right_table_scan), std::move(filter_expr));
  // Build the output columns of the cross join (all columns from each child).
  ResolvedColumnList join_output_columns;
  ResolvedColumnList left_columns = left_table_scan->column_list();
  for (int i = 0; i < left_columns.size(); ++i) {
    join_output_columns.push_back(left_columns[i]);
  }
  ResolvedColumnList right_columns = filter_scan->column_list();
  for (int i = 0; i < right_columns.size(); ++i) {
    join_output_columns.push_back(right_columns[i]);
  }
  // Create the join condition.
  std::unique_ptr<const Function> equal_join_function(
      new Function("$equal", Function::kZetaSQLFunctionGroupName,
                   Function::SCALAR));
  auto join_expr =
      MakeResolvedFunctionCall(BoolType(), equal_join_function.get(), signature,
                               parameters.arguments, DEFAULT_ERROR_MODE);
  // Build the join scan.
  auto join_scan = MakeResolvedJoinScan(
      join_output_columns, ResolvedJoinScan::INNER, std::move(left_table_scan),
      std::move(filter_scan), std::move(join_expr));
  // Algebrize the resolved AST and check the result.
  std::unique_ptr<const AlgebraNode> algebrized_join(
      algebrizer_->AlgebrizeScan(join_scan.get()).value());
  std::string expected = absl::Substitute(
      "JoinOp\\(INNER\n"
      "..hash_join_equality_left_exprs: \\{\\},\n"
      "..hash_join_equality_right_exprs: \\{\\},\n"
      "..remaining_condition: $0,\n"
      "..left_input: ArrayScanOp\\(\n(.*\n)*.*\\),\n"
      "..right_input: FilterOp\\(\n"
      ". ..condition: Equal\\(\\$$col_int64, \\$$col_int64.2\\),\n"
      ". ..input: ArrayScanOp\\(\n(.*\n)*.*\\)\\)\\)",
      parameters.filter_condition);
  EXPECT_THAT(algebrized_join->DebugString(),
              testing::MatchesRegex(expected))
      << algebrized_join->DebugString();
}

INSTANTIATE_TEST_SUITE_P(CorrelatedInnerJoin, AlgebrizerTestJoins,
                         ValuesIn(AlgebrizerTestJoins::AllJoinTests()));

// Parameters used for grouping and aggregation.
struct GroupByTest {
  // Input to the test.
  std::vector<int> key_col_idxs;  // The index(es) of the column(s) to group on.
  // Output from the test.
  std::string column_assignments;
};

class AlgebrizerTestGroupingAggregation
    : public StatementAlgebrizerTest,
      public ::testing::WithParamInterface<GroupByTest> {
 public:
  static std::vector<GroupByTest> AllGroupByTests() {
    return {// Zero grouping columns.
            {{}, ""},
            // One grouping column.
            {{kInt64ColIdx}, "\n| +-$col_int64.2 := $col_int64"},
            {{kStringColIdx}, "\n| +-$col_string.2 := $col_string"},
            {{kBoolColIdx}, "\n| +-$col_bool.2 := $col_bool"},
            {{kDoubleColIdx}, "\n| +-$col_double.2 := $col_double"},
            // Four grouping columns.
            {{kInt64ColIdx, kStringColIdx, kBoolColIdx, kDoubleColIdx},
             "\n| +-$col_int64.2 := $col_int64,"
             "\n| +-$col_string.2 := $col_string,"
             "\n| +-$col_bool.2 := $col_bool,"
             "\n| +-$col_double.2 := $col_double"}};
  }

  void AddAggregateColumn(
      FunctionSignatureId fn_id, const Type* result_type,
      int argument_column_id, int* output_column_id, int first_agg_id,
      std::vector<std::unique_ptr<const ResolvedComputedColumn>>*
          aggregate_exprs,
      ResolvedColumnList* output_columns) {
    // Follows the naming scheme used by the resolver assuming the aggregate
    // columns are added to the output after the grouping columns.
    std::string output_column_name =
        kAggNamePrefix + std::to_string(*output_column_id - first_agg_id + 1);
    ResolvedColumn output_column(
        (*output_column_id)++, zetasql::IdString::MakeGlobal(kTableName),
        zetasql::IdString::MakeGlobal(output_column_name), result_type);
    output_columns->push_back(output_column);
    // Build the aggregate function
    functions_.emplace_back(new Function(
        FunctionSignatureIdToName(fn_id),
        Function::kZetaSQLFunctionGroupName, Function::AGGREGATE));
    std::vector<std::unique_ptr<const ResolvedExpr>> arguments;
    FunctionArgumentTypeList argument_type_list;
    bool has_argument = (argument_column_id != kInvalidColIdx);
    if (has_argument) {
      const Type* argument_type = columns_[argument_column_id].type();
      argument_type_list.push_back(argument_type);
      arguments.push_back(MakeResolvedColumnRef(
          argument_type, columns_[argument_column_id], kNonCorrelated));
    }
    const FunctionArgumentType fn_result_type(result_type);
    FunctionSignature signature(fn_result_type, argument_type_list, nullptr);
    auto agg_fn = MakeResolvedAggregateFunctionCall(
        result_type, functions_.back().get(), signature, std::move(arguments),
        DEFAULT_ERROR_MODE, false /* distinct */,
        ResolvedNonScalarFunctionCallBase::DEFAULT_NULL_HANDLING,
        nullptr /* having_modifier */, {} /* order_by_item_list */,
        nullptr /* limit */);
    // The named expression links the output column to the aggregate function.
    aggregate_exprs->push_back(
        MakeResolvedComputedColumn(output_column, std::move(agg_fn)));
  }

  void BuildGroupingExpressions(
      GroupByTest parameters, const ResolvedColumnList& table_columns,
      int* column_id, ResolvedColumnList* output_columns,
      std::vector<std::unique_ptr<const ResolvedComputedColumn>>* groupby_exprs)
      const {
    // Build the grouping expressions.
    for (int i = 0; i < parameters.key_col_idxs.size(); ++i) {
      ResolvedColumn groupby_column = table_columns[parameters.key_col_idxs[i]];
      ResolvedColumn output_column(
          (*column_id)++,
          zetasql::IdString::MakeGlobal(groupby_column.table_name()),
          zetasql::IdString::MakeGlobal(groupby_column.name()),
          groupby_column.type());
      output_columns->push_back(output_column);
      auto key_grouping = MakeResolvedColumnRef(output_column.type(),
                                                groupby_column, kNonCorrelated);
      // The named expression links the output column to the grouping column.
      groupby_exprs->push_back(
          MakeResolvedComputedColumn(output_column, std::move(key_grouping)));
    }
  }

 protected:
  // This is the "table name" generated by the resolver for an aggregate scan.
  // It has no semantic impact.
  const std::string kTableName = "$groupby";
  // This is the aggregate name generated by the resolver for an aggregate
  // function. It has no semantic impact.
  const std::string kAggNamePrefix = "$agg";
};

TEST_P(AlgebrizerTestGroupingAggregation, GroupByCountStar) {
  // Build a resolved AST for an aggregate scan with a variable number of
  // grouping columns and the single aggregate function "COUNT(*)".
  GroupByTest parameters = GetParam();
  int column_id = 1;
  std::unique_ptr<const ResolvedTableScan> table_scan =
      ScanTableAllTypes(&column_id);
  ResolvedColumnList table_columns = table_scan->column_list();
  ResolvedColumnList output_columns;
  // Build the grouping expressions.
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> groupby_exprs;
  BuildGroupingExpressions(parameters, table_columns, &column_id,
                           &output_columns, &groupby_exprs);
  // Build the aggregate column for COUNT(*).
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> aggregate_exprs;
  int first_agg_id = column_id;  // Used solely for generating aggregate names.
  AddAggregateColumn(FN_COUNT_STAR, Int64Type(), kInvalidColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  // Build the aggregate scan.
  auto aggregate_scan = MakeResolvedAggregateScan(
      output_columns, std::move(table_scan), std::move(groupby_exprs),
      std::move(aggregate_exprs), {} /* grouping_set_list */,
      {} /* rollup_column_list */);
  // Algebrize the resolved AST and check the result.
  std::unique_ptr<const AlgebraNode> algebrized_groupby_aggregation(
      algebrizer_->AlgebrizeScan(aggregate_scan.get()).value());
  std::string expected = absl::Substitute(
      "AggregateOp(\n"
      "+-keys: {$0},\n"
      "+-aggregators: {\n"
      "| +-$$agg1 := Count()},\n"
      "+-input: $1)",
      parameters.column_assignments,
      ScanTableAllTypesAsArrayExprString(2 /* indent */));
  EXPECT_EQ(expected, algebrized_groupby_aggregation->DebugString());
}

INSTANTIATE_TEST_SUITE_P(
    GroupByCountStar, AlgebrizerTestGroupingAggregation,
    ValuesIn(AlgebrizerTestGroupingAggregation::AllGroupByTests()));

TEST_P(AlgebrizerTestGroupingAggregation, GroupByCountColumn) {
  // Build a resolved AST for an aggregate scan with a variable number of
  // grouping columns and the aggregate functions:
  //   COUNT(col_bool), COUNT(col_double), COUNT(col_int64), COUNT(col_string);
  GroupByTest parameters = GetParam();
  int column_id = 1;
  std::unique_ptr<const ResolvedTableScan> table_scan =
      ScanTableAllTypes(&column_id);
  ResolvedColumnList table_columns = table_scan->column_list();
  ResolvedColumnList output_columns;
  // Build the grouping expressions.
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> groupby_exprs;
  BuildGroupingExpressions(parameters, table_columns, &column_id,
                           &output_columns, &groupby_exprs);
  // Create the aggregate expressions.
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> aggregate_exprs;
  int first_agg_id = column_id;  // Used solely for generating aggregate names.
  AddAggregateColumn(FN_COUNT, Int64Type(), kBoolColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  AddAggregateColumn(FN_COUNT, Int64Type(), kDoubleColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  AddAggregateColumn(FN_COUNT, Int64Type(), kInt64ColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  AddAggregateColumn(FN_COUNT, Int64Type(), kStringColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  // Build the aggregate scan.
  auto aggregate_scan = MakeResolvedAggregateScan(
      output_columns, std::move(table_scan), std::move(groupby_exprs),
      std::move(aggregate_exprs), {} /* grouping_set_list */,
      {} /* rollup_column_list */);
  // Algebrize the resolved AST and check the result.
  std::unique_ptr<const AlgebraNode> algebrized_groupby_aggregation(
      algebrizer_->AlgebrizeScan(aggregate_scan.get()).value());
  std::string expected = absl::Substitute(
      "AggregateOp(\n"
      "+-keys: {$0},\n"
      "+-aggregators: {\n"
      "| +-$$agg1 := Count($$col_bool),\n"
      "| +-$$agg2 := Count($$col_double),\n"
      "| +-$$agg3 := Count($$col_int64),\n"
      "| +-$$agg4 := Count($$col_string)},\n"
      "+-input: $1)",
      parameters.column_assignments,
      ScanTableAllTypesAsArrayExprString(2 /* indent */));
  EXPECT_EQ(expected, algebrized_groupby_aggregation->DebugString());
}

INSTANTIATE_TEST_SUITE_P(
    GroupByCountColumn, AlgebrizerTestGroupingAggregation,
    ValuesIn(AlgebrizerTestGroupingAggregation::AllGroupByTests()));

TEST_P(AlgebrizerTestGroupingAggregation, GroupByMax) {
  // Build a resolved AST for an aggregate scan with a variable number of
  // grouping columns and the aggregate functions:
  //   MAX(col_bool), MAX(col_double), MAX(col_int64), MAX(col_string);
  GroupByTest parameters = GetParam();
  int column_id = 1;
  std::unique_ptr<const ResolvedTableScan> table_scan =
      ScanTableAllTypes(&column_id);
  ResolvedColumnList table_columns = table_scan->column_list();
  ResolvedColumnList output_columns;
  // Build the grouping expressions.
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> groupby_exprs;
  BuildGroupingExpressions(parameters, table_columns, &column_id,
                           &output_columns, &groupby_exprs);
  // Create the aggregate expressions.
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> aggregate_exprs;
  int first_agg_id = column_id;  // Used soley for generating aggregate names.
  AddAggregateColumn(FN_MAX, BoolType(), kBoolColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  AddAggregateColumn(FN_MAX, DoubleType(), kDoubleColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  AddAggregateColumn(FN_MAX, Int64Type(), kInt64ColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  AddAggregateColumn(FN_MAX, StringType(), kStringColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  // Build the aggregate scan.
  auto aggregate_scan = MakeResolvedAggregateScan(
      output_columns, std::move(table_scan), std::move(groupby_exprs),
      std::move(aggregate_exprs), {} /* grouping_set_list */,
      {} /* rollup_column_list */);
  // Algebrize the resolved AST and check the result.
  std::unique_ptr<const AlgebraNode> algebrized_groupby_aggregation(
      algebrizer_->AlgebrizeScan(aggregate_scan.get()).value());
  std::string expected = absl::Substitute(
      "AggregateOp(\n"
      "+-keys: {$0},\n"
      "+-aggregators: {\n"
      "| +-$$agg1 := Max($$col_bool),\n"
      "| +-$$agg2 := Max($$col_double),\n"
      "| +-$$agg3 := Max($$col_int64),\n"
      "| +-$$agg4 := Max($$col_string)},\n"
      "+-input: $1)",
      parameters.column_assignments,
      ScanTableAllTypesAsArrayExprString(2 /* indent */));
  EXPECT_EQ(expected, algebrized_groupby_aggregation->DebugString());
}

INSTANTIATE_TEST_SUITE_P(
    GroupByMax, AlgebrizerTestGroupingAggregation,
    ValuesIn(AlgebrizerTestGroupingAggregation::AllGroupByTests()));

TEST_P(AlgebrizerTestGroupingAggregation, GroupByMin) {
  // Build a resolved AST for an aggregate scan with a variable number of
  // grouping columns and the aggregate functions:
  //   MIN(col_bool), MIN(col_double), MIN(col_int64), MIN(col_string);
  GroupByTest parameters = GetParam();
  int column_id = 1;
  std::unique_ptr<const ResolvedTableScan> table_scan =
      ScanTableAllTypes(&column_id);
  ResolvedColumnList table_columns = table_scan->column_list();
  ResolvedColumnList output_columns;
  // Build the grouping expressions.
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> groupby_exprs;
  BuildGroupingExpressions(parameters, table_columns, &column_id,
                           &output_columns, &groupby_exprs);
  // Create the aggregate expressions.
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> aggregate_exprs;
  int first_agg_id = column_id;  // Used soley for generating aggregate names.
  AddAggregateColumn(FN_MIN, BoolType(), kBoolColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  AddAggregateColumn(FN_MIN, DoubleType(), kDoubleColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  AddAggregateColumn(FN_MIN, Int64Type(), kInt64ColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  AddAggregateColumn(FN_MIN, StringType(), kStringColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  // Build the aggregate scan.
  std::unique_ptr<const ResolvedAggregateScan> aggregate_scan =
      MakeResolvedAggregateScan(
          output_columns, std::move(table_scan), std::move(groupby_exprs),
          std::move(aggregate_exprs), {} /* grouping_set_list */,
          {} /* rollup_column_list */);
  // Algebrize the resolved AST and check the result.
  std::unique_ptr<const AlgebraNode> algebrized_groupby_aggregation(
      algebrizer_->AlgebrizeScan(aggregate_scan.get()).value());
  std::string expected = absl::Substitute(
      "AggregateOp(\n"
      "+-keys: {$0},\n"
      "+-aggregators: {\n"
      "| +-$$agg1 := Min($$col_bool),\n"
      "| +-$$agg2 := Min($$col_double),\n"
      "| +-$$agg3 := Min($$col_int64),\n"
      "| +-$$agg4 := Min($$col_string)},\n"
      "+-input: $1)",
      parameters.column_assignments,
      ScanTableAllTypesAsArrayExprString(2 /* indent */));
  EXPECT_EQ(expected, algebrized_groupby_aggregation->DebugString());
}

INSTANTIATE_TEST_SUITE_P(
    GroupByMin, AlgebrizerTestGroupingAggregation,
    ValuesIn(AlgebrizerTestGroupingAggregation::AllGroupByTests()));

TEST_P(AlgebrizerTestGroupingAggregation, GroupBySum) {
  // Build a resolved AST for an aggregate scan with a variable number of
  // grouping columns and two aggregate functions:
  //   SUM(col_int64), SUM(col_double)
  GroupByTest parameters = GetParam();
  int column_id = 1;
  std::unique_ptr<const ResolvedTableScan> table_scan =
      ScanTableAllTypes(&column_id);
  ResolvedColumnList table_columns = table_scan->column_list();
  ResolvedColumnList output_columns;
  // Build the grouping expressions.
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> groupby_exprs;
  BuildGroupingExpressions(parameters, table_columns, &column_id,
                           &output_columns, &groupby_exprs);
  // Create the aggregate expressions.
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> aggregate_exprs;
  int first_agg_id = column_id;  // Used soley for generating aggregate names.
  AddAggregateColumn(FN_SUM_INT64, Int64Type(), kInt64ColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  AddAggregateColumn(FN_SUM_DOUBLE, DoubleType(), kDoubleColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  // Build the aggregate scan.
  std::unique_ptr<const ResolvedAggregateScan> aggregate_scan(
      MakeResolvedAggregateScan(
          output_columns, std::move(table_scan), std::move(groupby_exprs),
          std::move(aggregate_exprs), {} /* grouping_set_list */,
          {} /* rollup_column_list */));
  // Algebrize the resolved AST and check the result.
  std::unique_ptr<const AlgebraNode> algebrized_groupby_aggregation(
      algebrizer_->AlgebrizeScan(aggregate_scan.get()).value());
  std::string expected = absl::Substitute(
      "AggregateOp(\n"
      "+-keys: {$0},\n"
      "+-aggregators: {\n"
      "| +-$$agg1 := Sum($$col_int64),\n"
      "| +-$$agg2 := Sum($$col_double)},\n"
      "+-input: $1)",
      parameters.column_assignments,
      ScanTableAllTypesAsArrayExprString(2 /* indent */));
  EXPECT_EQ(expected, algebrized_groupby_aggregation->DebugString());
}

TEST_P(AlgebrizerTestGroupingAggregation, GroupByAvg) {
  // Build a resolved AST for an aggregate scan with a variable number of
  // grouping columns and two aggregate functions:
  //   AVG(col_int64), AVG(col_double)
  GroupByTest parameters = GetParam();
  int column_id = 1;
  std::unique_ptr<const ResolvedTableScan> table_scan =
      ScanTableAllTypes(&column_id);
  ResolvedColumnList table_columns = table_scan->column_list();
  ResolvedColumnList output_columns;
  // Build the grouping expressions.
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> groupby_exprs;
  BuildGroupingExpressions(parameters, table_columns, &column_id,
                           &output_columns, &groupby_exprs);
  // Create the aggregate expressions.
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> aggregate_exprs;
  int first_agg_id = column_id;  // Used soley for generating aggregate names.
  AddAggregateColumn(FN_AVG_INT64, DoubleType(), kInt64ColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  AddAggregateColumn(FN_AVG_DOUBLE, DoubleType(), kDoubleColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  // Build the aggregate scan.
  std::unique_ptr<const ResolvedAggregateScan> aggregate_scan(
      MakeResolvedAggregateScan(
          output_columns, std::move(table_scan), std::move(groupby_exprs),
          std::move(aggregate_exprs), {} /* grouping_set_list */,
          {} /* rollup_column_list */));
  // Algebrize the resolved AST and check the result.
  std::unique_ptr<const AlgebraNode> algebrized_groupby_aggregation(
      algebrizer_->AlgebrizeScan(aggregate_scan.get()).value());
  std::string expected = absl::Substitute(
      "AggregateOp(\n"
      "+-keys: {$0},\n"
      "+-aggregators: {\n"
      "| +-$$agg1 := Avg($$col_int64),\n"
      "| +-$$agg2 := Avg($$col_double)},\n"
      "+-input: $1)",
      parameters.column_assignments,
      ScanTableAllTypesAsArrayExprString(2 /* indent */));
  EXPECT_EQ(expected, algebrized_groupby_aggregation->DebugString());
}

TEST_P(AlgebrizerTestGroupingAggregation, GroupByAny) {
  // Build a resolved AST for an aggregate scan with a variable number of
  // grouping columns and aggregate functions:
  //   ANY_VALUE(col_bool), ANY_VALUE(col_double), ANY_VALUE(col_int64),
  //   ANY_VALUE(col_str)
  GroupByTest parameters = GetParam();
  int column_id = 1;
  std::unique_ptr<const ResolvedTableScan> table_scan =
      ScanTableAllTypes(&column_id);
  ResolvedColumnList table_columns = table_scan->column_list();
  ResolvedColumnList output_columns;
  // Build the grouping expressions.
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> groupby_exprs;
  BuildGroupingExpressions(parameters, table_columns, &column_id,
                           &output_columns, &groupby_exprs);
  // Create the aggregate expressions.
  std::vector<std::unique_ptr<const ResolvedComputedColumn>> aggregate_exprs;
  int first_agg_id = column_id;  // Used soley for generating aggregate names.
  AddAggregateColumn(FN_ANY_VALUE, BoolType(), kBoolColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  AddAggregateColumn(FN_ANY_VALUE, DoubleType(), kDoubleColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  AddAggregateColumn(FN_ANY_VALUE, Int64Type(), kInt64ColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  AddAggregateColumn(FN_ANY_VALUE, StringType(), kStringColIdx, &column_id,
                     first_agg_id, &aggregate_exprs, &output_columns);
  // Build the aggregate scan.
  std::unique_ptr<const ResolvedAggregateScan> aggregate_scan(
      MakeResolvedAggregateScan(
          output_columns, std::move(table_scan), std::move(groupby_exprs),
          std::move(aggregate_exprs), {} /* grouping_set_list */,
          {} /* rollup_column_list */));
  // Algebrize the resolved AST and check the result.
  std::unique_ptr<const AlgebraNode> algebrized_groupby_aggregation(
      algebrizer_->AlgebrizeScan(aggregate_scan.get()).value());
  std::string expected = absl::Substitute(
      "AggregateOp(\n"
      "+-keys: {$0},\n"
      "+-aggregators: {\n"
      "| +-$$agg1 := AnyValue($$col_bool) [ignores_null = false],\n"
      "| +-$$agg2 := AnyValue($$col_double) [ignores_null = false],\n"
      "| +-$$agg3 := AnyValue($$col_int64) [ignores_null = false],\n"
      "| +-$$agg4 := AnyValue($$col_string) [ignores_null = false]},\n"
      "+-input: $1)",
      parameters.column_assignments,
      ScanTableAllTypesAsArrayExprString(2 /* indent */));
  EXPECT_EQ(expected, algebrized_groupby_aggregation->DebugString());
}

INSTANTIATE_TEST_SUITE_P(
    GroupBySum, AlgebrizerTestGroupingAggregation,
    ValuesIn(AlgebrizerTestGroupingAggregation::AllGroupByTests()));

}  // namespace zetasql
