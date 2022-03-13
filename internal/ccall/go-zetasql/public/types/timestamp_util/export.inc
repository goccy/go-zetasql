#ifndef ZETASQL_PUBLIC_TYPES_TIMESTAMP_UTIL_EXPORT_H
#define ZETASQL_PUBLIC_TYPES_TIMESTAMP_UTIL_EXPORT_H

#include "zetasql/public/types/timestamp_util.h"
#include "zetasql/public/types/timestamp_util.cc"

#if 0
namespace zetasql::types {

  absl::Time TimestampMaxBaseTime() {
    absl::Time v;
    return v;
  }

}
#endif

#include "go-absl/time/time/export.inc"

#endif
