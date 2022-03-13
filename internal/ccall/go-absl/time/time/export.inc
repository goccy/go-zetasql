#ifndef ABSL_TIME_TIME_EXPORT_H
#define ABSL_TIME_TIME_EXPORT_H

#include "absl/time/civil_time.h"
#include "absl/time/clock.h"
#include "absl/time/time.h"

#include "absl/time/civil_time.cc"
#include "absl/time/clock.cc"
#include "absl/time/duration.cc"
#include "absl/time/format.cc"

#define unix_epoch GO_EXPORT(unix_epoch)
#include "absl/time/time.cc"
#undef unix_epoch

#if 0

namespace absl {

  std::string FormatCivilTime(CivilSecond c) {
    return "";
  }
  std::string FormatCivilTime(CivilMinute c) {
    return "";
  }
  std::string FormatCivilTime(CivilHour c) {
    return "";
  }
  std::string FormatCivilTime(CivilDay c) {
    return "";
  }
  std::string FormatCivilTime(CivilMonth c) {
    return "";
  }
  std::string FormatCivilTime(CivilYear c) {
    return "";
  }

  bool ParseCivilTime(string_view s, CivilSecond* c) {
    return false;
  }
  bool ParseCivilTime(string_view s, CivilMinute* c) {
    return false;
  }
  bool ParseCivilTime(string_view s, CivilHour* c) {
    return false;
  }
  bool ParseCivilTime(string_view s, CivilDay* c) {
    return false;
  }
  bool ParseCivilTime(string_view s, CivilMonth* c) {
    return false;
  }
  bool ParseCivilTime(string_view s, CivilYear* c) {
    return false;
  }
  bool ParseLenientCivilTime(string_view s, CivilSecond* c) {
    return false;
  }
  bool ParseLenientCivilTime(string_view s, CivilMinute* c) {
    return false;  
  }
  bool ParseLenientCivilTime(string_view s, CivilHour* c) {
    return false;
  }
  bool ParseLenientCivilTime(string_view s, CivilDay* c) {
    return false;
  }
  bool ParseLenientCivilTime(string_view s, CivilMonth* c) {
    return false;
  }
  bool ParseLenientCivilTime(string_view s, CivilYear* c) {
    return false;
  }

  namespace time_internal {

    std::ostream& operator<<(std::ostream& os, CivilYear y) {
      return os;
    }
    std::ostream& operator<<(std::ostream& os, CivilMonth m) {
      return os;
    }
    std::ostream& operator<<(std::ostream& os, CivilDay d) {
      return os;
    }
    std::ostream& operator<<(std::ostream& os, CivilHour h) {
      return os;
    }
    std::ostream& operator<<(std::ostream& os, CivilMinute m) {
      return os;
    }
    std::ostream& operator<<(std::ostream& os, CivilSecond s) {
      return os;
    }

  }
}

namespace absl {

  Time Now() {
    Time v;
    return v;
  }

}

namespace absl {

  int64_t GetCurrentTimeNanosFromKernel(uint64_t last_cycleclock,
                                        uint64_t *cycleclock){
    return 0;
  }

  int64_t GetCurrentTimeNanosSlowPath();

  void ReadTimeSampleAtomic(const struct TimeSampleAtomic *atomic,
                            struct TimeSample *sample) {
  }

  int64_t GetCurrentTimeNanos() {
    return 0;
  }

  uint64_t SafeDivideAndScale(uint64_t a, uint64_t b) {
    return 0;
  }

  uint64_t UpdateLastSample(uint64_t now_cycles, uint64_t now_ns, uint64_t delta_cycles,
                            const struct TimeSample *sample);

  int64_t GetCurrentTimeNanosSlowPath() {
    return 0;
  }

  uint64_t UpdateLastSample(uint64_t now_cycles, uint64_t now_ns,
                            uint64_t delta_cycles,
                            const struct TimeSample *sample) {
    return 0;
  }
}

extern "C" {

  void AbslInternalSleepFor(absl::Duration duration) {
  }

}

namespace absl {

  namespace time_internal {

    int64_t IDivDuration(bool satq, const Duration num, const Duration den,
                         Duration* rem) {
      return 0;
    }

  }

  Duration& Duration::operator+=(Duration rhs) {
    return *this;
  }

  Duration& Duration::operator-=(Duration rhs) {
    return *this;
  }

  Duration& Duration::operator*=(int64_t r) {
    return *this;
  }

  Duration& Duration::operator*=(double r) {
    return *this;
  }

  Duration& Duration::operator/=(int64_t r) {
    return *this;
  }

  Duration& Duration::operator/=(double r) {
    return *this;
  }

  Duration& Duration::operator%=(Duration rhs) {
    return *this;
  }

  double FDivDuration(Duration num, Duration den) {
    return 0;
  }

  Duration Trunc(Duration d, Duration unit) {
    Duration v;
    return v;
  }

  Duration Floor(const Duration d, const Duration unit) {
    Duration v;
    return v;
  }

  Duration Ceil(const Duration d, const Duration unit) {
    Duration v;
    return v;
  }

  Duration DurationFromTimespec(timespec ts) {
    Duration v;
    return v;
  }

  Duration DurationFromTimeval(timeval tv) {
    Duration v;
    return v;
  }

  int64_t ToInt64Nanoseconds(Duration d) {
    return 0;
  }
  int64_t ToInt64Microseconds(Duration d) {
    return 0;
  }
  int64_t ToInt64Milliseconds(Duration d) {
    return 0;
  }
  int64_t ToInt64Seconds(Duration d) {
    return 0;
  }
  int64_t ToInt64Minutes(Duration d) {
    return 0;
  }
  int64_t ToInt64Hours(Duration d) {
    return 0;
  }

  double ToDoubleNanoseconds(Duration d) {
    return 0;
  }
  double ToDoubleMicroseconds(Duration d) {
    return 0;
  }
  double ToDoubleMilliseconds(Duration d) {
    return 0;
  }
  double ToDoubleSeconds(Duration d) {
    return 0;
  }
  double ToDoubleMinutes(Duration d) {
    return 0;
  }
  double ToDoubleHours(Duration d) {
    return 0;
  }

  timespec ToTimespec(Duration d) {
    timespec v;
    return v;
  }

  timeval ToTimeval(Duration d) {
    timeval v;
    return v;
  }

  std::chrono::nanoseconds ToChronoNanoseconds(Duration d) {
    std::chrono::nanoseconds v;
    return v;
  }
  std::chrono::microseconds ToChronoMicroseconds(Duration d) {
    std::chrono::microseconds v;
    return v;
  }
  std::chrono::milliseconds ToChronoMilliseconds(Duration d) {
    std::chrono::milliseconds v;
    return v;
  }
  std::chrono::seconds ToChronoSeconds(Duration d) {
    std::chrono::seconds v;
    return v;
  }
  std::chrono::minutes ToChronoMinutes(Duration d) {
    std::chrono::minutes v;
    return v;
  }
  std::chrono::hours ToChronoHours(Duration d) {
    std::chrono::hours v;
    return v;
  }

  std::string FormatDuration(Duration d) {
    return "";
  }

  bool ParseDuration(absl::string_view dur_sv, Duration* d) {
    return false;
  }

  bool AbslParseFlag(absl::string_view text, Duration* dst, std::string*) {
    return false;
  }

  std::string AbslUnparseFlag(Duration d) {
    return "";
  }

  bool ParseFlag(const std::string& text, Duration* dst, std::string* ) {
    return false;
  }

  std::string UnparseFlag(Duration d) {
    return "";
  }

}

namespace cctz = absl::time_internal::cctz;

namespace absl {

  extern const char RFC3339_full[] = {};
  extern const char RFC3339_sec[] = {};
  extern const char RFC1123_full[] = {};
  extern const char RFC1123_no_wday[] = {};

  std::string FormatTime(absl::string_view format, absl::Time t,
                         absl::TimeZone tz) {
    return "";
  }

  std::string FormatTime(absl::Time t, absl::TimeZone tz) {
    return "";
  }

  std::string FormatTime(absl::Time t) {
    return "";
  }

  bool ParseTime(absl::string_view format, absl::string_view input,
                 absl::Time* time, std::string* err) {
    return false;
  }

  bool ParseTime(absl::string_view format, absl::string_view input,
                 absl::TimeZone tz, absl::Time* time, std::string* err) {
    return false;
  }

  bool AbslParseFlag(absl::string_view text, absl::Time* t, std::string* error) {
    return false;
  }

  std::string AbslUnparseFlag(absl::Time t) {
    return "";
  }
  bool ParseFlag(const std::string& text, absl::Time* t, std::string* error) {
    return false;
  }

  std::string UnparseFlag(absl::Time t) {
    return "";
  }

}

namespace cctz = absl::time_internal::cctz;

namespace absl {

  absl::Time::Breakdown Time::In(absl::TimeZone tz) const {
    absl::Time::Breakdown v;
    return v;
  }

  absl::Time FromUDate(double udate) {
    absl::Time v;
    return v;
  }

  absl::Time FromUniversal(int64_t universal) {
    absl::Time v;
    return v;
  }

  int64_t ToUnixNanos(Time t) {
    return 0;
  }

  int64_t ToUnixMicros(Time t) {
    return 0;
  }

  int64_t ToUnixMillis(Time t) {
    return 0;
  }

  int64_t ToUnixSeconds(Time t) {
    return 0;
  }

  time_t ToTimeT(Time t) {
    time_t v;
    return v;
  }

  double ToUDate(Time t) {
    return 0;
  }

  int64_t ToUniversal(absl::Time t) {
    return 0;
  }

  absl::Time TimeFromTimespec(timespec ts) {
    absl::Time v;
    return v;
  }

  absl::Time TimeFromTimeval(timeval tv) {
    absl::Time v;
    return v;
  }

  timespec ToTimespec(Time t) {
    timespec v;
    return v;
  }

  timeval ToTimeval(Time t) {
    timeval v;
    return v;
  }

  Time FromChrono(const std::chrono::system_clock::time_point& tp) {
    Time v;
    return v;
  }

  std::chrono::system_clock::time_point ToChronoTime(absl::Time t) {
    std::chrono::system_clock::time_point v;
    return v;
  }

  absl::TimeZone::CivilInfo TimeZone::At(Time t) const {
    absl::TimeZone::CivilInfo v;
    return v;
  }

  absl::TimeZone::TimeInfo TimeZone::At(CivilSecond ct) const {
    absl::TimeZone::TimeInfo v;
    return v;
  }

  bool TimeZone::NextTransition(Time t, CivilTransition* trans) const {
    return false;
  }

  bool TimeZone::PrevTransition(Time t, CivilTransition* trans) const {
    return false;
  }

  absl::TimeConversion ConvertDateTime(int64_t year, int mon, int day, int hour,
                                       int min, int sec, TimeZone tz) {
    absl::TimeConversion v;
    return v;
  }

  absl::Time FromTM(const struct tm& tm, absl::TimeZone tz) {
    absl::Time v;
    return v;
  }

  struct tm ToTM(absl::Time t, absl::TimeZone tz) {
    struct tm v;
    return v;
  }

}
#endif

#include "go-absl/base/base/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/numeric/int128/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/time/go_internal/cctz/civil_time/export.inc"
#include "go-absl/time/go_internal/cctz/time_zone/export.inc"

#endif
