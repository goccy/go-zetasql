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

#include "zetasql/public/non_sql_function.h"

#include <string>

#include "zetasql/public/error_helpers.h"
#include "zetasql/resolved_ast/resolved_ast.h"
#include "zetasql/base/ret_check.h"

namespace zetasql {

// static
const char NonSqlFunction::kNonSqlFunctionGroup[] = "Non_sql_function";

NonSqlFunction::NonSqlFunction(
    const std::string& name, Mode mode,
    const std::vector<FunctionSignature>& function_signatures,
    const FunctionOptions& function_options,
    const ResolvedCreateFunctionStmt* resolved_create_function_statement,
    const std::vector<std::string>& argument_names,
    absl::optional<ParseResumeLocation> parse_resume_location,
    const std::vector<std::unique_ptr<const ResolvedComputedColumn>>*
        aggregate_expression_list)
    : Function(name, kNonSqlFunctionGroup, mode, function_signatures,
               function_options),
      resolved_create_function_statement_(resolved_create_function_statement),
      argument_names_(argument_names),
      parse_resume_location_(parse_resume_location),
      aggregate_expression_list_(aggregate_expression_list) {}

absl::Status NonSqlFunction::Create(
    const std::string& name, Mode mode,
    const std::vector<FunctionSignature>& function_signatures,
    const FunctionOptions& function_options,
    const ResolvedCreateFunctionStmt* resolved_create_function_statement,
    const std::vector<std::string>& argument_names,
    const std::vector<std::unique_ptr<const ResolvedComputedColumn>>*
        aggregate_expression_list,
    absl::optional<ParseResumeLocation> parse_resume_location,
    std::unique_ptr<NonSqlFunction>* non_sql_function) {
  if (parse_resume_location.has_value()) {
    ZETASQL_RET_CHECK_EQ(function_signatures.size(), 1);
  }
  ZETASQL_RET_CHECK(resolved_create_function_statement != nullptr);
  ZETASQL_RET_CHECK(!resolved_create_function_statement->code().empty() ||
            absl::AsciiStrToUpper(
                resolved_create_function_statement->language()) == "REMOTE");
  ZETASQL_RET_CHECK(!resolved_create_function_statement->language().empty());
  ZETASQL_RET_CHECK_NE(
      absl::AsciiStrToUpper(resolved_create_function_statement->language()),
      "SQL");
  for (const FunctionSignature& function_signature : function_signatures) {
    ZETASQL_RET_CHECK_EQ(argument_names.size(),
                 function_signature.arguments().size())
        << function_signature.DebugString();
  }
  if (mode == FunctionEnums::AGGREGATE) {
    ZETASQL_RET_CHECK(aggregate_expression_list != nullptr);
  }
  non_sql_function->reset(
      new NonSqlFunction(name, mode, function_signatures, function_options,
                         resolved_create_function_statement, argument_names,
                         parse_resume_location, aggregate_expression_list));
  return absl::OkStatus();
}

std::string NonSqlFunction::FullDebugString() const {
  std::string full_debug_string = DebugString(/*verbose=*/true);
  // TODO: The current debug string prints the function signature
  // and argument names separately.  It would be better to embed the argument
  // names in the signature strings.
  if (!argument_names_.empty()) {
    absl::StrAppend(&full_debug_string, "\nargument names (",
                    absl::StrJoin(argument_names_, ", "), ")");
  }
  absl::StrAppend(&full_debug_string, "\nresolved_create_function_statement: ",
                  resolved_create_function_statement_->DebugString());
  return full_debug_string;
}

}  // namespace zetasql
