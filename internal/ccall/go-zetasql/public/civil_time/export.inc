#ifndef ZETASQL_PUBLIC_CIVIL_TIME_EXPORT_H
#define ZETASQL_PUBLIC_CIVIL_TIME_EXPORT_H

#include "zetasql/public/civil_time.h"
#include "zetasql/public/civil_time.cc"

#if 0
namespace zetasql {

  TimeValue::TimeValue()
    : valid_(true), hour_(0), minute_(0), second_(0), nanosecond_(0) {}

  TimeValue TimeValue::FromHMSAndNanos(int32_t hour, int32_t minute,
                                       int32_t second, int32_t nanosecond) {
    TimeValue v;
    return v;
  }

  TimeValue TimeValue::FromHMSAndNanosNormalized(int32_t hour, int32_t minute,
                                                 int32_t second,
                                                 int32_t nanosecond) {
    TimeValue v;
    return v;
  }

  TimeValue TimeValue::FromHMSAndMicros(int32_t hour, int32_t minute,
                                        int32_t second, int32_t microsecond) {
    TimeValue v;
    return v;
  }

  TimeValue TimeValue::FromHMSAndMicrosNormalized(int32_t hour, int32_t minute,
                                                  int32_t second,
                                                  int32_t microsecond) {
    TimeValue v;
    return v;
  }

  TimeValue TimeValue::FromHMSAndNanosInternal(int64_t hour, int64_t minute,
                                               int64_t second,
                                               int64_t nanosecond) {
    TimeValue v;
    return v;
  }

  TimeValue TimeValue::InternalFromPacked64SecondsAndNanos(uint64_t bit_field_time_seconds, int64_t nanosecond) {
    TimeValue v;
    return v;
  }

  TimeValue TimeValue::FromPacked64Micros(int64_t bit_field_time_micros) {
    TimeValue v;
    return v;
  }

  TimeValue TimeValue::FromPacked64Nanos(int64_t bit_field_time_nanos) {
    TimeValue v;
    return v;
  }

  TimeValue TimeValue::FromPacked32SecondsAndNanos(int32_t bit_field_time_seconds,
                                                   int32_t nanosecond) {
    TimeValue v;
    return v;
  }

  TimeValue TimeValue::FromPacked32SecondsAndMicros(int32_t bit_field_time_seconds, int32_t microsecond) {
    TimeValue v;
    return v;
  }

  int32_t TimeValue::Packed32TimeSeconds() const {
    return 0;
  }

  int64_t TimeValue::Packed64TimeMicros() const {
    return 0;
  }

  int64_t TimeValue::Packed64TimeNanos() const {
    return 0;
  }

  std::string TimeValue::DebugString() const {
    return "";
  }

  DatetimeValue::DatetimeValue()
    : year_(1970),
      month_(1),
      day_(1),
      hour_(0),
      minute_(0),
      second_(0),
      valid_(true),
      nanosecond_(0) {}

  DatetimeValue DatetimeValue::FromYMDHMSAndNanosInternal(int64_t year, int64_t month, int64_t day, int64_t hour, int64_t minute,
                                                          int64_t second, int64_t nanosecond) {
    DatetimeValue v;
    return v;
  }

  DatetimeValue DatetimeValue::FromYMDHMSAndMicros(int32_t year, int32_t month,
                                                   int32_t day, int32_t hour,
                                                   int32_t minute, int32_t second,
                                                   int32_t microsecond) {
    DatetimeValue v;
    return v;
  }

  DatetimeValue DatetimeValue::FromYMDHMSAndMicrosNormalized(
                                                             int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute,
                                                             int32_t second, int32_t microsecond) {
    DatetimeValue v;
    return v;
  }

  DatetimeValue DatetimeValue::FromYMDHMSAndNanos(int32_t year, int32_t month,
                                                  int32_t day, int32_t hour,
                                                  int32_t minute, int32_t second,
                                                  int32_t nanosecond) {
    DatetimeValue v;
    return v;
  }

  DatetimeValue DatetimeValue::FromYMDHMSAndNanosNormalized(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute,
                                                            int32_t second, int32_t nanosecond) {
    DatetimeValue v;
    return v;
  }

  DatetimeValue DatetimeValue::FromCivilSecondAndMicros(absl::CivilSecond civil_second, int32_t microsecond) {
    DatetimeValue v;
    return v;
  }

  DatetimeValue DatetimeValue::FromCivilSecondAndNanos(absl::CivilSecond civil_second, int32_t nanosecond) {
    DatetimeValue v;
    return v;
  }

  DatetimeValue DatetimeValue::FromCivilSecondAndNanosInternal(absl::CivilSecond civil_second, int64_t nanosecond) {
    DatetimeValue v;
    return v;
  }

  DatetimeValue DatetimeValue::FromPacked64SecondsAndMicros(int64_t bit_field_datetime_seconds, int32_t microsecond) {
    DatetimeValue v;
    return v;
  }

  DatetimeValue DatetimeValue::FromPacked64SecondsAndNanos(int64_t bit_field_datetime_seconds, int32_t nanosecond) {
    DatetimeValue v;
    return v;
  }

  DatetimeValue DatetimeValue::FromPacked64Micros(int64_t bit_field_datetime_micros) {
    DatetimeValue v;
    return v;
  }

  DatetimeValue DatetimeValue::FromPacked64SecondsAndNanosInternal(uint64_t bit_field, int64_t nanosecond) {
    DatetimeValue v;
    return v;
  }

  int64_t DatetimeValue::Packed64DatetimeSeconds() const {
    return 0;
  }

  int64_t DatetimeValue::Packed64DatetimeMicros() const {
    return 0;
  }

  std::string DatetimeValue::DebugString() const {
    return "";
  }

}
#endif

#include "go-zetasql/base/mathutil/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/time/time/export.inc"

#endif
