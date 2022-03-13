#ifndef ZETASQL_BASE_MATHUTIL_EXPORT_H
#define ZETASQL_BASE_MATHUTIL_EXPORT_H

#include "zetasql/base/mathutil.h"
#include "zetasql/base/mathutil.cc"

#if 0

namespace zetasql_base {

  MathUtil::FloatParts MathUtil::Decompose(float value) {
    MathUtil::FloatParts v;
    return v;
  }

  MathUtil::DoubleParts MathUtil::Decompose(double value) {
    MathUtil::DoubleParts v;
    return v;
  }

}

#endif

#include "go-zetasql/base/bits/export.inc"
#include "go-zetasql/base/logging/export.inc"
#include "go-zetasql/base/mathlimits/export.inc"
#include "go-absl/base/base/export.inc"
#include "go-absl/base/core_headers/export.inc"

#endif
