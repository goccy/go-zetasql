#ifndef ZETASQL_PUBLIC_ANALYZER_EXPORT_H
#define ZETASQL_PUBLIC_ANALYZER_EXPORT_H

#include "zetasql/public/analyzer.h"
#include "zetasql/public/table_name_resolver.h"

#include "zetasql/public/analyzer.cc"
#include "zetasql/public/table_name_resolver.cc"

#if 0
namespace zetasql {

  absl::Status AnalyzeStatement(absl::string_view sql,
                                const AnalyzerOptions& options_in,
                                Catalog* catalog, TypeFactory* type_factory,
                                std::unique_ptr<const AnalyzerOutput>* output) {
    return absl::OkStatus();
  }

  absl::Status AnalyzeNextStatement(ParseResumeLocation* resume_location,
                                    const AnalyzerOptions& options_in,
                                    Catalog* catalog,
                                    TypeFactory* type_factory,
                                    std::unique_ptr<const AnalyzerOutput>* output,
                                    bool* at_end_of_input) {
    return absl::OkStatus();
  }

  absl::Status AnalyzeStatementFromParserOutputOwnedOnSuccess(std::unique_ptr<ParserOutput>* statement_parser_output,
                                                              const AnalyzerOptions& options, absl::string_view sql, Catalog* catalog,
                                                              TypeFactory* type_factory, std::unique_ptr<const AnalyzerOutput>* output) {
    return absl::OkStatus();
  }

  absl::Status AnalyzeStatementFromParserOutputUnowned(std::unique_ptr<ParserOutput>* statement_parser_output,
                                                       const AnalyzerOptions& options, absl::string_view sql, Catalog* catalog,
                                                       TypeFactory* type_factory, std::unique_ptr<const AnalyzerOutput>* output) {
    return absl::OkStatus();
  }

  absl::Status AnalyzeStatementFromParserAST(const ASTStatement& statement, const AnalyzerOptions& options,
                                             absl::string_view sql, Catalog* catalog, TypeFactory* type_factory,
                                             std::unique_ptr<const AnalyzerOutput>* output) {
    return absl::OkStatus();
  }

  absl::Status AnalyzeExpression(absl::string_view sql,
                                 const AnalyzerOptions& options, Catalog* catalog,
                                 TypeFactory* type_factory,
                                 std::unique_ptr<const AnalyzerOutput>* output) {
    return absl::OkStatus();
  }

  absl::Status AnalyzeExpressionForAssignmentToType(absl::string_view sql, const AnalyzerOptions& options, Catalog* catalog,
                                                    TypeFactory* type_factory, const Type* target_type,
                                                    std::unique_ptr<const AnalyzerOutput>* output) {
    return absl::OkStatus();
  }

  absl::Status AnalyzeExpressionFromParserAST(const ASTExpression& ast_expression, const AnalyzerOptions& options_in,
                                              absl::string_view sql, TypeFactory* type_factory, Catalog* catalog,
                                              std::unique_ptr<const AnalyzerOutput>* output) {
    return absl::OkStatus();
  }

  absl::Status AnalyzeExpressionFromParserASTForAssignmentToType(const ASTExpression& ast_expression, const AnalyzerOptions& options_in,
                                                                 absl::string_view sql, TypeFactory* type_factory, Catalog* catalog,
                                                                 const Type* target_type, std::unique_ptr<const AnalyzerOutput>* output) {
    return absl::OkStatus();
  }

  absl::Status AnalyzeType(const std::string& type_name,
                           const AnalyzerOptions& options_in, Catalog* catalog,
                           TypeFactory* type_factory, const Type** output_type) {
    return absl::OkStatus();
  }

  absl::Status AnalyzeType(const std::string& type_name,
                           const AnalyzerOptions& options_in, Catalog* catalog,
                           TypeFactory* type_factory, const Type** output_type,
                           TypeParameters* output_type_params) {
    return absl::OkStatus();
  }

  absl::Status ExtractTableNamesFromStatement(absl::string_view sql,
                                              const AnalyzerOptions& options_in,
                                              TableNamesSet* table_names) {
    return absl::OkStatus();
  }

  absl::Status ExtractTableResolutionTimeFromStatement(absl::string_view sql, const AnalyzerOptions& options_in,
                                                       TypeFactory* type_factory, Catalog* catalog,
                                                       TableResolutionTimeInfoMap* table_resolution_time_info_map,
                                                       std::unique_ptr<ParserOutput>* parser_output) {
    return absl::OkStatus();
  }

  absl::Status ExtractTableNamesFromNextStatement(ParseResumeLocation* resume_location, const AnalyzerOptions& options_in,
                                                  TableNamesSet* table_names, bool* at_end_of_input) {
    return absl::OkStatus();
  }

  absl::Status ExtractTableNamesFromASTStatement(const ASTStatement& ast_statement, const AnalyzerOptions& options_in,
                                                 absl::string_view sql, TableNamesSet* table_names) {
    return absl::OkStatus();
  }

  absl::Status ExtractTableResolutionTimeFromASTStatement(const ASTStatement& ast_statement, const AnalyzerOptions& options_in,
                                                          absl::string_view sql, TypeFactory* type_factory, Catalog* catalog,
                                                          TableResolutionTimeInfoMap* table_resolution_time_info_map) {
    return absl::OkStatus();
  }

  absl::Status ExtractTableNamesFromScript(absl::string_view sql,
                                           const AnalyzerOptions& options_in,
                                           TableNamesSet* table_names) {
  }

  absl::Status ExtractTableNamesFromASTScript(const ASTScript& ast_script,
                                              const AnalyzerOptions& options_in,
                                              absl::string_view sql,
                                              TableNamesSet* table_names) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<const AnalyzerOutput>> RewriteForAnonymization(const std::unique_ptr<const AnalyzerOutput>& analyzer_output,
                                                                                const AnalyzerOptions& analyzer_options, Catalog* catalog,
                                                                                TypeFactory* type_factory) {
    absl::StatusOr<std::unique_ptr<const AnalyzerOutput>> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<const AnalyzerOutput>> RewriteForAnonymization(const AnalyzerOutput& analyzer_output,
                                                                                const AnalyzerOptions& analyzer_options, Catalog* catalog,
                                                                                TypeFactory* type_factory) {
    absl::StatusOr<std::unique_ptr<const AnalyzerOutput>> v;
    return v;
  }

  absl::Status RewriteResolvedAst(const AnalyzerOptions& analyzer_options,
                                  absl::string_view sql, Catalog* catalog,
                                  TypeFactory* type_factory,
                                  AnalyzerOutput& analyzer_output) {
    return absl::OkStatus();
  }

}

namespace zetasql {
  namespace table_name_resolver {

    absl::Status FindTableNamesAndResolutionTime(absl::string_view sql, const ASTStatement& statement,
                                                 const AnalyzerOptions& analyzer_options, TypeFactory* type_factory,
                                                 Catalog* catalog, TableNamesSet* table_names,
                                                 TableResolutionTimeInfoMap* table_resolution_time_info_map) {
      return absl::OkStatus();
    }

    absl::Status FindTableNamesInScript(absl::string_view sql,
                                        const ASTScript& script,
                                        const AnalyzerOptions& analyzer_options,
                                        TableNamesSet* table_names) {
      return absl::OkStatus();
    }

  }
}
#endif

#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/analyzer_output/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_helpers/export.inc"
#include "go-zetasql/public/parse_resume_location/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/analyzer/all_rewriters/export.inc"
#include "go-zetasql/analyzer/analyzer_impl/export.inc"
#include "go-zetasql/analyzer/resolver/export.inc"
#include "go-zetasql/analyzer/rewrite_resolved_ast/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/arena/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/validator/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
