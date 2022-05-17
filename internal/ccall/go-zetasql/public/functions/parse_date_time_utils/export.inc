#ifndef ZETASQL_PUBLIC_FUNCTIONS_PARSE_DATE_TIME_UTILS_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_PARSE_DATE_TIME_UTILS_EXPORT_H

#include "zetasql/public/functions/parse_date_time_utils.h"
#include "zetasql/public/functions/parse_date_time_utils.cc"

#if 0
namespace zetasql {
  namespace functions {
    namespace parse_date_time_utils {

      bool ConvertTimeToTimestamp(absl::Time time, int64_t* timestamp) {
        return false;
      }

      const char* ParseInt(const char* dp, const char* end_of_data, int max_width, int64_t min, int64_t max, int64_t* vp) {
        return nullptr;
      }

      const char* ParseInt(const char* dp, const char* end_of_data, int max_width, int64_t min, int64_t max, int* vp) {
        return nullptr;
      }

      const char* ParseSubSeconds(const char* dp, const char* end_of_data, int max_digits, TimestampScale scale, absl::Duration* subseconds) {
        return nullptr;
      }

    }
  }
}
#endif

#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-absl/time/time/export.inc"

#endif
