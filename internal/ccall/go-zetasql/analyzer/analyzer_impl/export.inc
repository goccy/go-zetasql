#ifndef ZETASQL_ANALYZER_ANALYZER_IMPL_EXPORT_H
#define ZETASQL_ANALYZER_ANALYZER_IMPL_EXPORT_H

#include "zetasql/analyzer/analyzer_impl.h"
#include "zetasql/analyzer/analyzer_impl.cc"

#if 0
namespace zetasql {

  absl::Status InternalAnalyzeExpression(absl::string_view sql, const AnalyzerOptions& options, Catalog* catalog,
                                         TypeFactory* type_factory, const Type* target_type,
                                         std::unique_ptr<const AnalyzerOutput>* output) {
    return absl::OkStatus();
  }

  absl::Status ConvertExprToTargetType(const ASTExpression& ast_expression, absl::string_view sql,
                                       const AnalyzerOptions& analyzer_options, Catalog* catalog,
                                       TypeFactory* type_factory, const Type* target_type,
                                       std::unique_ptr<const ResolvedExpr>* resolved_expr) {
    return absl::OkStatus();
  }

  absl::Status InternalAnalyzeExpressionFromParserAST(const ASTExpression& ast_expression,
                                                      std::unique_ptr<ParserOutput> parser_output, absl::string_view sql,
                                                      const AnalyzerOptions& options, Catalog* catalog, TypeFactory* type_factory,
                                                      const Type* target_type, std::unique_ptr<const AnalyzerOutput>* output) {
    return absl::OkStatus();
  }
}
#endif

#include "go-zetasql/analyzer/resolver/export.inc"
#include "go-zetasql/analyzer/rewrite_resolved_ast/export.inc"
#include "go-zetasql/analyzer/rewriters/rewriter_interface/export.inc"
#include "go-zetasql/base/logging/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/analyzer_output/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/validator/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"

#endif
