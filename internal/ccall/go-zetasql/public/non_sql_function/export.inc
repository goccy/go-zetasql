#ifndef ZETASQL_PUBLIC_NON_SQL_FUNCTION_EXPORT_H
#define ZETASQL_PUBLIC_NON_SQL_FUNCTION_EXPORT_H

#include "zetasql/public/non_sql_function.h"
#include "zetasql/public/non_sql_function.cc"

#if 0
namespace zetasql {

  const char NonSqlFunction::kNonSqlFunctionGroup[] = "Non_sql_function";

  NonSqlFunction::NonSqlFunction(const std::string& name, Mode mode,
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

  absl::Status NonSqlFunction::Create(const std::string& name, Mode mode,
                                      const std::vector<FunctionSignature>& function_signatures,
                                      const FunctionOptions& function_options,
                                      const ResolvedCreateFunctionStmt* resolved_create_function_statement,
                                      const std::vector<std::string>& argument_names,
                                      const std::vector<std::unique_ptr<const ResolvedComputedColumn>>*
                                      aggregate_expression_list,
                                      absl::optional<ParseResumeLocation> parse_resume_location,
                                      std::unique_ptr<NonSqlFunction>* non_sql_function) {
    return absl::OkStatus();
  }

  std::string NonSqlFunction::FullDebugString() const {
    return "";
  }

}
#endif

#include "go-zetasql/public/error_helpers/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/parse_resume_location/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-absl/types/optional/export.inc"

#endif
