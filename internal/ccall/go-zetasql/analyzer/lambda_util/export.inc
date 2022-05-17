#ifndef ZETASQL_ANALYZER_LAMBDA_UTIL_EXPORT_H
#define ZETASQL_ANALYZER_LAMBDA_UTIL_EXPORT_H

#include "zetasql/analyzer/lambda_util.h"
#include "zetasql/analyzer/lambda_util.cc"

#if 0
namespace zetasql {

  absl::StatusOr<std::vector<IdString>> ExtractLambdaArgumentNames(const ASTLambda* ast_lambda) {
    std::vector<IdString> v;
    return v;
  }

  absl::Status ValidateLambdaArgumentListIsIdentifierList(const ASTLambda* ast_lambda) {
    absl::Status v;
    return v;
  }

}
#endif

#include "go-zetasql/base/logging/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"

#endif
