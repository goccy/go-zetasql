#ifndef ZETASQL_PUBLIC_BUILTIN_FUNCTION_EXPORT_H
#define ZETASQL_PUBLIC_BUILTIN_FUNCTION_EXPORT_H

#include "zetasql/public/builtin_function.h"
#include "zetasql/public/builtin_function.cc"

#if 0
namespace zetasql {

  const std::string FunctionSignatureIdToName(FunctionSignatureId id) {
    return "";
  }

  using NameToFunctionMap = std::map<std::string, std::unique_ptr<Function>>;

  void GetZetaSQLFunctions(TypeFactory* type_factory,
                           const ZetaSQLBuiltinFunctionOptions& options,
                           NameToFunctionMap* functions) {
  }

  bool FunctionMayHaveUnintendedArgumentCoercion(const Function* function) {
    return false;
  }

}
#endif

#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-zetasql/public/builtin_function_options/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/cycle_detector/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/common/builtin_function_internal/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/proto/options_cc_proto/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
