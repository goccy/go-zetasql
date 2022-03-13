#ifndef ABSL_TIME_INTERNAL_CCTZ_CIVIL_TIME_EXPORT_H
#define ABSL_TIME_INTERNAL_CCTZ_CIVIL_TIME_EXPORT_H

#include "absl/time/internal/cctz/include/cctz/civil_time.h"

#include "absl/time/internal/cctz/src/civil_time_detail.cc"

#if 0
namespace absl {
  namespace time_internal {
    namespace cctz {
      namespace detail {

        std::ostream& operator<<(std::ostream& os, const civil_year& y) {
          return os;
        }
        std::ostream& operator<<(std::ostream& os, const civil_month& m) {
          return os;
        }
        std::ostream& operator<<(std::ostream& os, const civil_day& d) {
          return os;
        }
        std::ostream& operator<<(std::ostream& os, const civil_hour& h) {
          return os;
        }
        std::ostream& operator<<(std::ostream& os, const civil_minute& m) {
          return os;
        }
        std::ostream& operator<<(std::ostream& os, const civil_second& s) {
          return os;
        }
        std::ostream& operator<<(std::ostream& os, weekday wd) {
          return os;
        }
      }
    }
  }
}
#endif

#include "go-absl/base/config/export.inc"

#endif
