#ifndef ZETASQL_PUBLIC_TEMPLATED_SQL_FUNCTION_EXPORT_H
#define ZETASQL_PUBLIC_TEMPLATED_SQL_FUNCTION_EXPORT_H

#include "zetasql/public/templated_sql_function.h"

#define module_initialization_complete GO_EXPORT(templated_sql_function_module_initialization_complete)
#include "zetasql/public/templated_sql_function.cc"
#undef module_initialization_complete

#if 0
namespace zetasql {

  const char TemplatedSQLFunction::kTemplatedSQLFunctionGroup[] =
    "Templated_SQL_Function";

  TemplatedSQLFunction::TemplatedSQLFunction(const std::vector<std::string>& function_name_path,
                                             const FunctionSignature& signature,
                                             const std::vector<std::string>& argument_names,
                                             const ParseResumeLocation& parse_resume_location, Mode mode,
                                             const FunctionOptions& options)
    : Function(function_name_path, kTemplatedSQLFunctionGroup, mode,
    {signature}, options),
      argument_names_(argument_names),
      parse_resume_location_(parse_resume_location) {
  }

  absl::Status TemplatedSQLFunction::Deserialize(const FunctionProto& proto,
                                                 const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                                 TypeFactory* factory, std::unique_ptr<Function>* result) {
    return absl::OkStatus();
  }

  absl::Status TemplatedSQLFunction::Serialize(FileDescriptorSetMap* file_descriptor_set_map, FunctionProto* proto,
                                               bool omit_signatures) const {
    return absl::OkStatus();
  }

  TemplatedSQLFunctionCall::TemplatedSQLFunctionCall(std::unique_ptr<const ResolvedExpr> expr,
                                                     std::vector<std::unique_ptr<const ResolvedComputedColumn>>
                                                     aggregate_expr_list)
    : expr_(expr.release()),
      aggregate_expression_list_(std::move(aggregate_expr_list)) {}

  const std::vector<std::unique_ptr<const ResolvedComputedColumn>>&
  TemplatedSQLFunctionCall::aggregate_expression_list() const {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> *v;
    return *v;
  }

  std::string TemplatedSQLFunctionCall::DebugString() const {
    return "";
  }

}
#endif

#include "go-zetasql/public/error_location_cc_proto/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/parse_resume_location/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/proto/function_cc_proto/export.inc"
#include "go-zetasql/proto/internal_error_location_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
