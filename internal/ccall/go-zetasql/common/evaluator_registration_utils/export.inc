#ifndef ZETASQL_COMMON_EVALUATOR_REGISTRATION_UTILS_EXPORT_H
#define ZETASQL_COMMON_EVALUATOR_REGISTRATION_UTILS_EXPORT_H

#include "zetasql/common/evaluator_registration_utils.h"

namespace zetasql::internal {

  void EnableFullEvaluatorFeatures() {
  }

}

#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/collator/export.inc"
#include "go-zetasql/reference_impl/functions/register_all/export.inc"
#include "go-absl/base/base/export.inc"

#endif
