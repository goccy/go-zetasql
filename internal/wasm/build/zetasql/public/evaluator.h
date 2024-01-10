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

#ifndef ZETASQL_PUBLIC_EVALUATOR_H_
#define ZETASQL_PUBLIC_EVALUATOR_H_

// ZetaSQL in-memory expression or query evaluation using the reference
// implementation. Please refer to evaluator_base.h for full documentation and
// usage examples.
//
// evaluator_base.h  <- abstract base class and documentation
// evaluator.h       <- entry point for the full evaluator
// evaluator_lite.h  <- entry point for the "lite" evaluator
//
// Unless you have a good reason not to (such as a constraint on executable
// size), you should use the full evaluator in this file. This "full" evaluator
// is the same as the "lite" implementation, but includes all available optional
// builtin functions. Refer to reference_impl/functions/register_all.h for the
// complete list.

#include "zetasql/public/evaluator_base.h"  

namespace zetasql {

// See evaluator_base.h for the full interface and usage instructions.
class PreparedExpression : public PreparedExpressionBase {
 public:
  explicit PreparedExpression(const std::string& sql,
                              TypeFactory* type_factory = nullptr);
  PreparedExpression(const std::string& sql, const EvaluatorOptions& options);
  PreparedExpression(const ResolvedExpr* expression,
                     const EvaluatorOptions& options);
};

// See evaluator_base.h for the full interface and usage instructions.
class PreparedQuery : public PreparedQueryBase {
 public:
  PreparedQuery(const std::string& sql, const EvaluatorOptions& options);
  PreparedQuery(const ResolvedQueryStmt* stmt, const EvaluatorOptions& options);
};

// See evaluator_base.h for the full interface and usage instructions.
class PreparedModify : public PreparedModifyBase {
 public:
  PreparedModify(const std::string& sql, const EvaluatorOptions& options);
  PreparedModify(const ResolvedStatement* stmt,
                 const EvaluatorOptions& options);
};

}  // namespace zetasql

#endif  // ZETASQL_PUBLIC_EVALUATOR_H_
