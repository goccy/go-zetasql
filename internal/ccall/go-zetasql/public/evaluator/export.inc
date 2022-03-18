#ifndef ZETASQL_PUBLIC_EVALUATOR_EXPORT_H
#define ZETASQL_PUBLIC_EVALUATOR_EXPORT_H

#include "zetasql/public/evaluator.h"
#include "zetasql/public/evaluator.cc"

#if 0
namespace zetasql {

  PreparedExpression::PreparedExpression(const std::string& sql,
                                         TypeFactory* type_factory)
    : PreparedExpressionBase(sql, type_factory) {
  }

  PreparedExpression::PreparedExpression(const std::string& sql,
                                         const EvaluatorOptions& options)
    : PreparedExpressionBase(sql, options) {
  }

  PreparedExpression::PreparedExpression(const ResolvedExpr* expression,
                                         const EvaluatorOptions& options)
    : PreparedExpressionBase(expression, options) {
  }

  PreparedQuery::PreparedQuery(const std::string& sql,
                               const EvaluatorOptions& options)
    : PreparedQueryBase(sql, options) {
  }

  PreparedQuery::PreparedQuery(const ResolvedQueryStmt* stmt,
                               const EvaluatorOptions& options)
    : PreparedQueryBase(stmt, options) {
  }

  PreparedModify::PreparedModify(const std::string& sql,
                                 const EvaluatorOptions& options)
    : PreparedModifyBase(sql, options) {
  }

  PreparedModify::PreparedModify(const ResolvedStatement* stmt,
                                 const EvaluatorOptions& options)
    : PreparedModifyBase(stmt, options) {
  }

}
#endif

#include "go-zetasql/public/evaluator_base/export.inc"
#include "go-zetasql/common/evaluator_registration_utils/export.inc"

#endif
