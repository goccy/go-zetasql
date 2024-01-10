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

#ifndef ZETASQL_PUBLIC_SQL_FUNCTION_H_
#define ZETASQL_PUBLIC_SQL_FUNCTION_H_

#include <memory>
#include <string>
#include <vector>

#include "zetasql/public/function.h"
#include "zetasql/public/parse_resume_location.h"
#include "absl/types/optional.h"
#include "zetasql/base/ret_check.h"
#include "zetasql/base/status.h"

// This file includes interfaces and classes related to NON-templated SQL
// Functions.  It includes a generic interface (SQLFunctionInterface), and a
// concrete implementation of that interface (SQLFunction).
//
// Note: Templated SQL Function objects can be found in
// templated_sql_function.h.
//
// TODO: Consider refactoring the relationship between
// SQLFunction and TemplatedSQLFunction (and between SQLTableValuedFunction
// and TemplatedSQLTVF).  They both support GetArgumentNames(), and they
// both conceptually support getting the resolved function expression and
// aggregate expression list.  SQLFunction supports FunctionExpression() and
// aggregate_expression_list() for fetching the pre-resolved function
// expression info, and SQLTableValuedFunction supports a Resolve() method
// that returns the same information given the actual function call arguments.
// Maybe SQLFunction becomes a subclass of TemplatedSQLFunction where its
// Resolve() method simply returns the pre-resolved expression info (with
// the classes appropriately renamed to reflect the new relationship).

namespace zetasql {

class ResolvedComputedColumn;
class ResolvedExpr;

// The SQLFunctionInterface is a sub-class of Function which represents
// functions whose implementation is defined as a SQL expression.  This
// interface supports both scalar and aggregate functions/expressions.
//
// The current implementation only supports a single function signature,
// or at least requires that all signatures have the same number/names
// of arguments.
//
// TODO: Extend this implementation to support multiple different
// signatures (differing number and/or names of arguments).
class SQLFunctionInterface : public Function {
 public:
  SQLFunctionInterface(
      const std::string& name, const std::string& group, Mode mode,
      const std::vector<FunctionSignature>& function_signatures,
      const FunctionOptions& function_options)
      : Function(name, group, mode, function_signatures, function_options) {}
  SQLFunctionInterface(
      const std::vector<std::string>& name_path, const std::string& group,
      Mode mode, const std::vector<FunctionSignature>& function_signatures,
      const FunctionOptions& function_options)
      : Function(name_path, group, mode, function_signatures,
                 function_options) {}
  SQLFunctionInterface(const SQLFunctionInterface&) = delete;
  SQLFunctionInterface& operator=(const SQLFunctionInterface&) = delete;
  SQLFunctionInterface(SQLFunctionInterface&&) = delete;
  SQLFunctionInterface& operator=(SQLFunctionInterface&&) = delete;

  // Returns the associated function expression.
  virtual const ResolvedExpr* FunctionExpression() const = 0;

  // Returns a list of function argument names.  The function's SQL
  // expression can reference these names, and this list is used to
  // relate expression references to these names back to the function
  // call arguments.
  // TODO: Does it make sense to return argument names and types,
  // rather than just names?  We currently only need names, but logically
  // this seems like it could be a useful part of this interface.
  virtual std::vector<std::string> GetArgumentNames() const = 0;

  // Returns a list of computed aggregate expressions, if relevant.  Only
  // relevant for a SQLFunctionInterface with mode = AGGREGATE.  Returns
  // nullptr for SCALAR functions.
  virtual const std::vector<std::unique_ptr<const ResolvedComputedColumn>>*
      aggregate_expression_list() const = 0;
};

// A simple concrete implementation of SQLFunctionInterface that provides
// implementations of the interface's pure virtual functions by acting as
// a container for the function's resolved function expression (which is
// stored as a field within this class).
class SQLFunction : public SQLFunctionInterface {
 public:
  // The Function group name for SQLFunctions.
  static const char kSQLFunctionGroup[];

  // Creates a SQLFunction from the resolved <function_expression>.
  // Returns an error if the SQLFunction could not be successfully
  // created.
  //
  // Returns an error if:
  //   1) <function_expression> is NULL
  //   2) <mode> is AGGREGATE and <aggregate_expression_list> is NULL
  //   3) the size of <argument_names> does not match the number of arguments
  //      in all of the <function_signatures>
  //
  // Does not take ownership of <function_expression> or
  // <aggregate_expression_list>, which must outlive this class.
  //
  // Optional field <parse_resume_location> identifies the start of the
  // CREATE statement associated with this SQLFunction, if applicable.  Must
  // only be set if there is a single FunctionSignature.
  //
  // TODO: Consider refactoring SQLFunction,
  // SQLTableFunction, and SQLConstantWithValue so that they take ownership
  // of <function_expression> and <aggregate_expression_list>.  This may help
  // avoid potential memory corruption and/or crash bugs.
  static absl::Status Create(
      const std::string& name, Mode mode,
      const std::vector<FunctionSignature>& function_signatures,
      const FunctionOptions& function_options,
      const ResolvedExpr* function_expression,
      const std::vector<std::string>& argument_names,
      const std::vector<std::unique_ptr<const ResolvedComputedColumn>>*
          aggregate_expression_list,
      absl::optional<ParseResumeLocation> parse_resume_location,
      std::unique_ptr<SQLFunction>* sql_function);
  const ResolvedExpr* FunctionExpression() const override {
    return function_expression_;
  }

  std::vector<std::string> GetArgumentNames() const override {
    return argument_names_;
  }

  const std::vector<std::unique_ptr<const ResolvedComputedColumn>>*
      aggregate_expression_list() const override {
    return aggregate_expression_list_;
  }

  absl::optional<ParseResumeLocation> GetParseResumeLocation() const {
    return parse_resume_location_;
  }

  // Returns a debug string that includes the <function_expression_> string,
  // if present.
  std::string FullDebugString() const;

 private:
  // Constructor for valid functions.
  SQLFunction(const std::string& name, Mode mode,
              const std::vector<FunctionSignature>& function_signatures,
              const FunctionOptions& function_options,
              const ResolvedExpr* function_expression,
              const std::vector<std::string>& argument_names,
              absl::optional<ParseResumeLocation> parse_resume_location,
              const std::vector<std::unique_ptr<const ResolvedComputedColumn>>*
                  aggregate_expression_list);

  const ResolvedExpr* function_expression_ = nullptr;  // Not owned.
  const std::vector<std::string> argument_names_;
  absl::optional<ParseResumeLocation> parse_resume_location_;
  const std::vector<std::unique_ptr<const ResolvedComputedColumn>>*
      aggregate_expression_list_ = nullptr;            // Not owned.
};

}  // namespace zetasql

#endif  // ZETASQL_PUBLIC_SQL_FUNCTION_H_
