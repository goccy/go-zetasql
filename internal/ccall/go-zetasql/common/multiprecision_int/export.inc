#ifndef ZETASQL_COMMON_MULTIPRECISION_INT_EXPORT_H
#define ZETASQL_COMMON_MULTIPRECISION_INT_EXPORT_H

#include "zetasql/common/multiprecision_int.h"
#include "zetasql/common/multiprecision_int_impl.h"

#include "zetasql/common/multiprecision_int_impl.cc"

#if 0
namespace zetasql {
  namespace multiprecision_int_impl {

    void AppendSegmentsToString(const uint32_t segments[], size_t num_segments,
                                std::string* result) {
    }

  }
}
#endif

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/bits/export.inc"
#include "go-zetasql/base/endian/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"

#endif
