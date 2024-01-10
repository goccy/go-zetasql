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

// This library defines an internal portion of the analyzer API that is used
// inside AST rewriters, and thus needs to be separate from public/analyzer.h
// to avoid a circular dependency.

#ifndef ZETASQL_ANALYZER_ANALYZER_IMPL_H_
#define ZETASQL_ANALYZER_ANALYZER_IMPL_H_

#include <memory>

#include "zetasql/analyzer/rewriters/rewriter_interface.h"
#include "zetasql/parser/parse_tree.h"
#include "zetasql/parser/parser.h"
#include "zetasql/public/analyzer_options.h"
#include "zetasql/public/analyzer_output.h"
#include "zetasql/public/catalog.h"
#include "zetasql/public/types/type.h"
#include "zetasql/public/types/type_factory.h"
#include "zetasql/resolved_ast/resolved_ast.h"
#include "absl/status/status.h"
#include "absl/strings/string_view.h"
#include "absl/types/span.h"

namespace zetasql {

// Analyzes the expression and places the results in output. This is the
// internal version of the API, for use in AST rewriters without causing a
// circular dependency.
//
// If 'target_type' is non-null, coerces the expression to be of type
// 'target_type'.
absl::Status InternalAnalyzeExpression(
    absl::string_view sql, const AnalyzerOptions& options, Catalog* catalog,
    TypeFactory* type_factory, const Type* target_type,
    std::unique_ptr<const AnalyzerOutput>* output);

// Coerces <resolved_expr> to <target_type>, using assignment semantics
// For details, see Coercer::AssignableTo() in
// .../public/coercer.h
//
// Upon success, a resolved tree that implements the conversion is stored in
// <resolved_expr>, replacing the tree that was previously there.
absl::Status ConvertExprToTargetType(
    const ASTExpression& ast_expression, absl::string_view sql,
    const AnalyzerOptions& analyzer_options, Catalog* catalog,
    TypeFactory* type_factory, const Type* target_type,
    std::unique_ptr<const ResolvedExpr>* resolved_expr);

absl::Status InternalAnalyzeExpressionFromParserAST(
    const ASTExpression& ast_expression,
    std::unique_ptr<ParserOutput> parser_output, absl::string_view sql,
    const AnalyzerOptions& options, Catalog* catalog, TypeFactory* type_factory,
    const Type* target_type, std::unique_ptr<const AnalyzerOutput>* output);
}  // namespace zetasql

#endif  // ZETASQL_ANALYZER_ANALYZER_IMPL_H_
