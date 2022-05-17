#ifndef ZETASQL_PUBLIC_SQL_TVF_EXPORT_H
#define ZETASQL_PUBLIC_SQL_TVF_EXPORT_H

#include "zetasql/public/sql_tvf.h"
#include "zetasql/public/sql_tvf.cc"

#if 0
namespace zetasql {

  const char SQLTableValuedFunction::kSQLTableValuedFunctionGroup[] =
    "Lazy_resolution_tvf";

  absl::Status SQLTableValuedFunction::Create(const ::zetasql::ResolvedCreateTableFunctionStmt* create_tvf_statement,
                                              std::unique_ptr<SQLTableValuedFunction>* simple_sql_tvf) {
    return absl::OkStatus();
  }

  absl::Status SQLTableValuedFunction::Create(const ::zetasql::ResolvedCreateTableFunctionStmt* create_tvf_statement,
                                              TableValuedFunctionOptions tvf_options,
                                              std::unique_ptr<SQLTableValuedFunction>* simple_sql_tvf) {
    return absl::OkStatus();
  }

  absl::Status SQLTableValuedFunction::Resolve(const AnalyzerOptions* analyzer_options,
                                               const std::vector<TVFInputArgumentType>& actual_arguments,
                                               const FunctionSignature& concrete_signature, Catalog* catalog,
                                               TypeFactory* type_factory,
                                               std::shared_ptr<TVFSignature>* tvf_signature) const {
    return absl::OkStatus();
  }

  TVFRelation SQLTableValuedFunction::GetQueryOutputSchema(const ResolvedCreateTableFunctionStmt& create_tvf_statement) {
    TVFRelation v;
    return v;
  }

  FunctionSignature SQLTableValuedFunction::GetEmptyFunctionSignature() {
    FunctionSignature v;
    return v;
  }

}
#endif

#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"

#endif
