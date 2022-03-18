#ifndef ZETASQL_PUBLIC_LITERAL_REMOVER_EXPORT_H
#define ZETASQL_PUBLIC_LITERAL_REMOVER_EXPORT_H

#include "zetasql/public/literal_remover.h"
#include "zetasql/public/literal_remover.cc"

#if 0
namespace zetasql {

  absl::Status ReplaceLiteralsByParameters(const std::string& sql,
                                           const absl::node_hash_set<std::string>& option_names_to_ignore,
                                           const AnalyzerOptions& analyzer_options, const ResolvedStatement* stmt,
                                           LiteralReplacementMap* literal_map,
                                           GeneratedParameterMap* generated_parameters, std::string* result_sql) {
    return absl::OkStatus();
  }

  absl::Status ReplaceLiteralsByParameters(const std::string& sql,
                                           const absl::node_hash_set<std::string>& option_names_to_ignore,
                                           const AnalyzerOptions& analyzer_options,
                                           const AnalyzerOutput* analyzer_output, LiteralReplacementMap* literal_map,
                                           GeneratedParameterMap* generated_parameters, std::string* result_sql) {
    return absl::OkStatus();
  }

  absl::Status ReplaceLiteralsByParameters(const std::string& sql, const AnalyzerOptions& analyzer_options,
                                           const AnalyzerOutput* analyzer_output, LiteralReplacementMap* literal_map,
                                           GeneratedParameterMap* generated_parameters, std::string* result_sql) {
    return absl::OkStatus();
  }

}
#endif

#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/analyzer_output/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-absl/container/node_hash_set/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
