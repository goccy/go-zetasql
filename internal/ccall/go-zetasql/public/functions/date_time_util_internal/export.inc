#ifndef ZETASQL_PUBLIC_FUNCTIONS_DATE_TIME_UTIL_INTERNAL_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_DATE_TIME_UTIL_INTERNAL_EXPORT_H

#include "zetasql/public/functions/date_time_util_internal.h"
#include "zetasql/public/functions/date_time_util_internal.cc"

#if 0
namespace zetasql {
  namespace functions {
    namespace date_time_util_internal {

      absl::civil_year_t GetIsoYear(absl::CivilDay day) {
        absl::civil_year_t v;
        return v;
      }

      absl::CivilDay GetFirstDayOfIsoYear(absl::CivilDay day) {
        absl::CivilDay v;
        return v;
      }

      absl::CivilDay GetLastDayOfIsoYear(absl::CivilDay day) {
        absl::CivilDay v;
        return v;
      }

      int GetIsoWeek(absl::CivilDay day) {
        return 0;
      }

    }
  }
}
#endif

#include "go-zetasql/base/base/export.inc"
#include "go-absl/time/time/export.inc"

#endif
