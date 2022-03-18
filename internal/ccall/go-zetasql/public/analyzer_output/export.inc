#ifndef ZETASQL_PUBLIC_ANALYZER_OUTPUT_EXPORT_H
#define ZETASQL_PUBLIC_ANALYZER_OUTPUT_EXPORT_H

#include "zetasql/public/analyzer_output.h"
#include "zetasql/public/analyzer_output.cc"

#if 0

namespace zetasql {

  AnalyzerOutput::AnalyzerOutput(std::shared_ptr<IdStringPool> id_string_pool,
                                 std::shared_ptr<zetasql_base::UnsafeArena> arena,
                                 std::unique_ptr<const ResolvedStatement> statement,
                                 const AnalyzerOutputProperties& analyzer_output_properties,
                                 std::unique_ptr<ParserOutput> parser_output,
                                 const std::vector<absl::Status>& deprecation_warnings,
                                 const QueryParametersMap& undeclared_parameters,
                                 const std::vector<const Type*>& undeclared_positional_parameters,
                                 int max_column_id)
  : id_string_pool_(std::move(id_string_pool)),
    arena_(std::move(arena)),
    statement_(std::move(statement)),
    analyzer_output_properties_(analyzer_output_properties),
    parser_output_(std::move(parser_output)),
    deprecation_warnings_(deprecation_warnings),
    undeclared_parameters_(undeclared_parameters),
    undeclared_positional_parameters_(undeclared_positional_parameters),
    max_column_id_(max_column_id) {}

  AnalyzerOutput::AnalyzerOutput(std::shared_ptr<IdStringPool> id_string_pool,
                                 std::shared_ptr<zetasql_base::UnsafeArena> arena,
                                 std::unique_ptr<const ResolvedExpr> expr,
                                 const AnalyzerOutputProperties& analyzer_output_properties,
                                 std::unique_ptr<ParserOutput> parser_output,
                                 const std::vector<absl::Status>& deprecation_warnings,
                                 const QueryParametersMap& undeclared_parameters,
                                 const std::vector<const Type*>& undeclared_positional_parameters,
                                 int max_column_id)
  : id_string_pool_(std::move(id_string_pool)),
    arena_(std::move(arena)),
    expr_(std::move(expr)),
    analyzer_output_properties_(analyzer_output_properties),
    parser_output_(std::move(parser_output)),
    deprecation_warnings_(deprecation_warnings),
    undeclared_parameters_(undeclared_parameters),
    undeclared_positional_parameters_(undeclared_positional_parameters),
    max_column_id_(max_column_id) {}

  AnalyzerOutput::~AnalyzerOutput() {}

}
#endif

#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/analyzer_output_properties/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/base/arena/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-absl/status/status/export.inc"

#endif
