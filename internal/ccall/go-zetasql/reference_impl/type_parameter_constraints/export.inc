#ifndef ZETASQL_REFERENCE_IMPL_TYPE_PARAMETER_CONSTRAINTS_EXPORT_H
#define ZETASQL_REFERENCE_IMPL_TYPE_PARAMETER_CONSTRAINTS_EXPORT_H

#include "zetasql/reference_impl/type_parameter_constraints.h"

namespace zetasql {

  absl::Status ApplyConstraints(const TypeParameters& type_params,
                                ProductMode mode, Value& value) {
    return absl::OkStatus();
  }

}

#include "go-zetasql/public/functions/string/export.inc"
#include "go-zetasql/public/types/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
