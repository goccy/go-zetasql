#ifndef ZETASQL_PUBLIC_ANON_FUNCTION_EXPORT_H
#define ZETASQL_PUBLIC_ANON_FUNCTION_EXPORT_H

#include "zetasql/public/anon_function.h"

#include "zetasql/public/anon_function.cc"

#if 0
namespace zetasql {

  AnonFunction::AnonFunction(const std::string& name, const std::string& group,
                             const std::vector<FunctionSignature>& function_signatures,
                             const FunctionOptions& function_options,
                             const std::string& partial_aggregate_name)
    : Function(name, group, /*mode=*/Function::AGGREGATE, function_signatures,
               AddDefaultFunctionOptions(name, function_options)),
      partial_aggregate_name_(partial_aggregate_name) {}

  const std::string& AnonFunction::GetPartialAggregateName() const {
    std::string *v;
    return *v;
  }

}
#endif

#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/function_cc_proto/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-absl/functional/bind_front/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
