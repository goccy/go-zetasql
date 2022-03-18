#ifndef ZETASQL_ANALYZER_FUNCTION_SIGNATURE_MATCHER_EXPORT_H
#define ZETASQL_ANALYZER_FUNCTION_SIGNATURE_MATCHER_EXPORT_H

#include "zetasql/analyzer/function_signature_matcher.h"
#include "zetasql/analyzer/function_signature_matcher.cc"

#if 0
namespace zetasql {

  bool SignatureArgumentCountMatches(const FunctionSignature& signature,
                                     int input_arguments_size,
                                     int* repetitions, int* optionals) {
    return false;
  }

  bool FunctionSignatureMatches(const LanguageOptions& language_options, const Coercer& coercer,
                                const std::vector<const ASTNode*>& arg_ast_nodes,
                                const std::vector<InputArgumentType>& input_arguments,
                                const FunctionSignature& signature, bool allow_argument_coercion,
                                TypeFactory* type_factory,
                                const ResolveLambdaCallback* resolve_lambda_callback,
                                std::unique_ptr<FunctionSignature>* result_signature,
                                SignatureMatchResult* signature_match_result,
                                std::vector<FunctionArgumentOverride>* arg_overrides) {
    return false;
  }

  absl::StatusOr<bool> FunctionSignatureMatchesWithStatus(const LanguageOptions& language_options, const Coercer& coercer,
                                                          const std::vector<const ASTNode*>& arg_ast_nodes,
                                                          const std::vector<InputArgumentType>& input_arguments,
                                                          const FunctionSignature& signature, bool allow_argument_coercion,
                                                          TypeFactory* type_factory,
                                                          const ResolveLambdaCallback* resolve_lambda_callback,
                                                          std::unique_ptr<FunctionSignature>* result_signature,
                                                          SignatureMatchResult* signature_match_result,
                                                          std::vector<FunctionArgumentOverride>* arg_overrides) {
    return false;
  }

}
#endif

#include "go-zetasql/analyzer/lambda_util/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/coercer/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/function_cc_proto/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/signature_match_result/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"

#endif
