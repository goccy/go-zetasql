#ifndef ZETASQL_PUBLIC_FUNCTIONS_DATE_TIME_UTIL_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_DATE_TIME_UTIL_EXPORT_H

#include "zetasql/public/functions/date_time_util.h"
#include "zetasql/public/functions/date_time_util.cc"

#if 0
namespace zetasql {
  namespace functions {

    bool IsValidDate(int32_t date) {
      return false;
    }

    bool IsValidDay(absl::civil_year_t year, int month, int day) {
      return false;
    }

    absl::string_view DateTimestampPartToSQL(DateTimestampPart date_part) {
      return "";
    }

    absl::Status LastDayOfDate(int32_t date, DateTimestampPart part,
                               int32_t* output) {
      return absl::OkStatus();
    }

    absl::Status LastDayOfDatetime(const DatetimeValue& datetime,
                                   DateTimestampPart part, int32_t* output) {
      return absl::OkStatus();
    }

    bool IsValidTimestamp(int64_t timestamp, TimestampScale scale) {
      return false;
    }

    bool IsValidTime(absl::Time time) {
      return false;
    }

    bool IsValidTimeZone(int timezone_minutes_offset) {
      return false;
    }

    absl::Time MakeTime(int64_t timestamp, TimestampScale scale) {
      absl::Time v;
      return v;
    }

    bool FromTime(absl::Time base_time, TimestampScale scale, int64_t* output) {
      return false;
    }

    absl::Status ConvertDateToString(int32_t date, std::string* out) {
      return absl::OkStatus();
    }

    absl::StatusOr<absl::CivilDay> ConvertDateToCivilDay(int32_t date) {
      absl::CivilDay v;
      return v;
    }

    absl::Status ConvertTimestampToStringWithoutTruncation(int64_t timestamp,
                                                           TimestampScale scale,
                                                           absl::TimeZone timezone,
                                                           std::string* out) {
      return absl::OkStatus();
    }

    absl::Status ConvertTimestampToStringWithoutTruncation(int64_t timestamp, TimestampScale scale, absl::string_view timezone_string, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status ConvertTimestampMicrosToStringWithTruncation(int64_t timestamp, absl::TimeZone timezone, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status ConvertTimestampToStringWithTruncation(int64_t timestamp,
                                                        TimestampScale scale,
                                                        absl::TimeZone timezone,
                                                        std::string* out) {
      return absl::OkStatus();
    }

    absl::Status ConvertTimestampToStringWithTruncation(int64_t timestamp, TimestampScale scale, absl::string_view timezone_string, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status ConvertTimeToString(TimeValue time, TimestampScale scale, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status ConvertDatetimeToString(DatetimeValue datetime, TimestampScale scale, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status FormatDateToString(absl::string_view format_string, int64_t date, const FormatDateTimestampOptions& format_options, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status FormatDateToString(absl::string_view format_string, int32_t date, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status FormatDatetimeToStringWithOptions(absl::string_view format_string, const DatetimeValue& datetime, const FormatDateTimestampOptions& format_options, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status FormatDatetimeToString(absl::string_view format_string,
                                        const DatetimeValue& datetime,
                                        std::string* out) {
      return absl::OkStatus();
    }

    absl::Status FormatTimeToString(absl::string_view format_string,
                                    const TimeValue& time, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status FormatTimestampToString(absl::string_view format_str, absl::Time timestamp, absl::TimeZone timezone,
                                         const FormatDateTimestampOptions& format_options, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status FormatTimestampToString(absl::string_view format_str, absl::Time timestamp,
                                         absl::string_view timezone_string,
                                         const FormatDateTimestampOptions& format_options, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status FormatTimestampToString(absl::string_view format_str, int64_t timestamp,
                                         absl::string_view timezone_string,
                                         const FormatDateTimestampOptions& format_options, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status FormatTimestampToString(absl::string_view format_str, int64_t timestamp, absl::TimeZone timezone,
                                         const FormatDateTimestampOptions& format_options, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status FormatTimestampToString(absl::string_view format_str,
                                         int64_t timestamp, absl::TimeZone timezone,
                                         std::string* out) {
      return absl::OkStatus();
    }

    absl::Status FormatTimestampToString(absl::string_view format_str,
                                         int64_t timestamp,
                                         absl::string_view timezone_string,
                                         std::string* out) {
      return absl::OkStatus();
    }

    absl::Status FormatTimestampToString(absl::string_view format_str,
                                         absl::Time timestamp,
                                         absl::TimeZone timezone,
                                         std::string* out) {
      return absl::OkStatus();
    }

    absl::Status FormatTimestampToString(absl::string_view format_string,
                                         absl::Time timestamp,
                                         absl::string_view timezone_string,
                                         std::string* out) {
      return absl::OkStatus();
    }

    absl::Status ConvertTimestampToString(absl::Time input, TimestampScale scale,
                                          absl::TimeZone timezone,
                                          std::string* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertTimestampToString(absl::Time input, TimestampScale scale,
                                          absl::string_view timezone_string,
                                          std::string* output) {
      return absl::OkStatus();
    }

    absl::Status MakeTimeZone(absl::string_view timezone_string,
                              absl::TimeZone* timezone) {
      return absl::OkStatus();
    }

    absl::Status ConvertStringToDate(absl::string_view str, int32_t* date) {
      return absl::OkStatus();
    }

    absl::StatusOr<int32_t> ConvertCivilDayToDate(absl::CivilDay civil_day) {
      return 0;
    }

    absl::Status ConvertStringToTimestamp(absl::string_view str,
                                          absl::TimeZone default_timezone,
                                          TimestampScale scale,
                                          int64_t* timestamp) {
      return absl::OkStatus();
    }

    absl::Status ConvertStringToTimestamp(absl::string_view str,
                                          absl::TimeZone default_timezone,
                                          TimestampScale scale,
                                          bool allow_tz_in_str,
                                          int64_t* timestamp) {
      return absl::OkStatus();
    }

    absl::Status ConvertStringToTimestamp(absl::string_view str,
                                          absl::string_view default_timezone_string,
                                          TimestampScale scale,
                                          bool allow_tz_in_str,
                                          int64_t* timestamp) {
      return absl::OkStatus();
    }

    absl::Status ConvertStringToTimestamp(absl::string_view str,
                                          absl::string_view default_timezone_string,
                                          TimestampScale scale,
                                          int64_t* timestamp) {
      return absl::OkStatus();
    }

    absl::Status ConvertStringToTimestamp(absl::string_view str,
                                          absl::TimeZone default_timezone,
                                          TimestampScale scale,
                                          bool allow_tz_in_str,
                                          absl::Time* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertStringToTime(absl::string_view str, TimestampScale scale,
                                     TimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertStringToDatetime(absl::string_view str,
                                         TimestampScale scale,
                                         DatetimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status ConstructDate(int year, int month, int day, int32_t* output) {
      return absl::OkStatus();
    }

    absl::Status ConstructTime(int hour, int minute, int second, TimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status ConstructDatetime(int year, int month, int day, int hour,
                                   int minute, int second, DatetimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status ConstructDatetime(int32_t date, const TimeValue& time, DatetimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status ExtractFromTimestamp(DateTimestampPart part, int64_t timestamp,
                                      TimestampScale scale, absl::TimeZone timezone,
                                      int32_t* output) {
      return absl::OkStatus();
    }

    absl::Status ExtractFromTimestamp(DateTimestampPart part, int64_t timestamp,
                                      TimestampScale scale,
                                      absl::string_view timezone_string,
                                      int32_t* output) {
      return absl::OkStatus();
    }

    absl::Status ExtractFromTimestamp(DateTimestampPart part, absl::Time base_time,
                                      absl::TimeZone timezone, int32_t* output) {
      return absl::OkStatus();
    }

    absl::Status ExtractFromTimestamp(DateTimestampPart part, absl::Time base_time,
                                      absl::string_view timezone_string,
                                      int32_t* output) {
      return absl::OkStatus();
    }

    absl::Status ExtractFromDate(DateTimestampPart part, int32_t date,
                                 int32_t* output) {
      return absl::OkStatus();
    }

    absl::Status ExtractFromTime(DateTimestampPart part, const TimeValue& time,
                                 int32_t* output) {
      return absl::OkStatus();
    }

    absl::Status ExtractFromDatetime(DateTimestampPart part,
                                     const DatetimeValue& datetime,
                                     int32_t* output) {
      return absl::OkStatus();
    }

    absl::Status ExtractTimeFromDatetime(const DatetimeValue& datetime, TimeValue* time) {
      return absl::OkStatus();
    }

    absl::Status ConvertDatetimeToTimestamp(const DatetimeValue& datetime,
                                            absl::TimeZone timezone,
                                            absl::Time* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertDatetimeToTimestamp(const DatetimeValue& datetime,
                                            absl::string_view timezone_string,
                                            absl::Time* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertTimestampToDatetime(absl::Time base_time,
                                            absl::TimeZone timezone,
                                            DatetimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertTimestampToDatetime(absl::Time base_time,
                                            absl::string_view timezone_string,
                                            DatetimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertTimestampToTime(absl::Time base_time,
                                        absl::TimeZone timezone,
                                        TimestampScale scale, TimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertTimestampToTime(absl::Time base_time,
                                        absl::string_view timezone_string,
                                        TimestampScale scale, TimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertTimestampToTime(absl::Time base_time,
                                        absl::TimeZone timezone,
                                        TimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertTimestampToTime(absl::Time base_time,
                                        absl::string_view timezone_string,
                                        TimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertDateToTimestamp(int32_t date, absl::TimeZone timezone,
                                        absl::Time* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertDateToTimestamp(int32_t date,
                                        absl::string_view timezone_string,
                                        absl::Time* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertDateToTimestamp(int32_t date, TimestampScale scale,
                                        absl::TimeZone timezone, int64_t* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertDateToTimestamp(int32_t date, TimestampScale scale,
                                        absl::string_view timezone_string,
                                        int64_t* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertProto3TimestampToTimestamp(const google::protobuf::Timestamp& input_timestamp,
                                                   TimestampScale output_scale, int64_t* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertProto3TimestampToTimestamp(const google::protobuf::Timestamp& input_timestamp, absl::Time* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertTimestampToProto3Timestamp(int64_t input_timestamp, TimestampScale scale,
                                                   google::protobuf::Timestamp* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertTimestampToProto3Timestamp(absl::Time input_timestamp, google::protobuf::Timestamp* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertProto3DateToDate(const google::type::Date& input, int32_t* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertDateToProto3Date(int32_t input,
                                         google::type::Date* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertBetweenTimestamps(int64_t input_timestamp,
                                          TimestampScale input_scale,
                                          TimestampScale output_scale,
                                          int64_t* output) {
      return absl::OkStatus();
    }

    absl::Status AddDateOverflow(int32_t date, DateTimestampPart part,
                                 int32_t interval, int32_t* output,
                                 bool* had_overflow) {
      return absl::OkStatus();
    }

    absl::Status AddDate(int32_t date, DateTimestampPart part, int64_t interval, int32_t* output) {
      return absl::OkStatus();
    }

    absl::Status AddDate(int32_t date, zetasql::IntervalValue interval, DatetimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status SubDate(int32_t date, DateTimestampPart part, int64_t interval, int32_t* output) {
      return absl::OkStatus();
    }

    absl::Status DiffDates(int32_t date1, int32_t date2, DateTimestampPart part, int32_t* output) {
      return absl::OkStatus();
    }

    absl::StatusOr<IntervalValue> IntervalDiffDates(int32_t date1, int32_t date2) {
      IntervalValue v;
      return v;
    }

    absl::Status DiffDatetimes(const DatetimeValue& datetime1,
                               const DatetimeValue& datetime2,
                               DateTimestampPart part, int64_t* output) {
      return absl::OkStatus();
    }

    absl::StatusOr<IntervalValue> IntervalDiffDatetimes(const DatetimeValue& datetime1, const DatetimeValue& datetime2) {
      IntervalValue v;
      return v;
    }

    absl::Status AddDatetime(const DatetimeValue& datetime, DateTimestampPart part,
                             int64_t interval, DatetimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status SubDatetime(const DatetimeValue& datetime, DateTimestampPart part,
                             int64_t interval, DatetimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status AddDatetime(DatetimeValue datetime,
                             zetasql::IntervalValue interval,
                             DatetimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status AddTimestamp(int64_t timestamp, TimestampScale scale,
                              absl::TimeZone timezone, DateTimestampPart part,
                              int64_t interval, int64_t* output) {
      return absl::OkStatus();
    }

    absl::Status AddTimestamp(int64_t timestamp, TimestampScale scale,
                              absl::string_view timezone_string,
                              DateTimestampPart part, int64_t interval,
                              int64_t* output) {
      return absl::OkStatus();
    }

    absl::Status AddTimestamp(absl::Time timestamp, absl::TimeZone timezone,
                              DateTimestampPart part, int64_t interval,
                              absl::Time* output) {
      return absl::OkStatus();
    }

    absl::Status AddTimestamp(absl::Time timestamp,
                              absl::string_view timezone_string,
                              DateTimestampPart part, int64_t interval,
                              absl::Time* output) {
      return absl::OkStatus();
    }

    absl::Status AddTimestamp(absl::Time timestamp, absl::TimeZone timezone,
                              zetasql::IntervalValue interval,
                              absl::Time* output) {
      return absl::OkStatus();
    }

    absl::Status AddTimestampOverflow(absl::Time timestamp, absl::TimeZone timezone,
                                      DateTimestampPart part, int64_t interval,
                                      absl::Time* output, bool* had_overflow) {
      return absl::OkStatus();
    }

    absl::Status SubTimestamp(int64_t timestamp, TimestampScale scale,
                              absl::TimeZone timezone, DateTimestampPart part,
                              int64_t interval, int64_t* output) {
      return absl::OkStatus();
    }

    absl::Status SubTimestamp(int64_t timestamp, TimestampScale scale,
                              absl::string_view timezone_string,
                              DateTimestampPart part, int64_t interval,
                              int64_t* output) {
      return absl::OkStatus();
    }

    absl::Status SubTimestamp(absl::Time timestamp, absl::TimeZone timezone,
                              DateTimestampPart part, int64_t interval,
                              absl::Time* output) {
      return absl::OkStatus();
    }

    absl::Status SubTimestamp(absl::Time timestamp,
                              absl::string_view timezone_string,
                              DateTimestampPart part, int64_t interval,
                              absl::Time* output) {
      return absl::OkStatus();
    }

    absl::Status AddTime(const TimeValue& time, DateTimestampPart part,
                         int64_t interval, TimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status SubTime(const TimeValue& time, DateTimestampPart part,
                         int64_t interval, TimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status DiffTimes(const TimeValue& time1, const TimeValue& time2,
                           DateTimestampPart part, int64_t* output) {
      return absl::OkStatus();
    }

    absl::StatusOr<IntervalValue> IntervalDiffTimes(const TimeValue& time1,
                                                    const TimeValue& time2) {
      IntervalValue v;
      return v;
    }

    absl::Status TruncateTime(const TimeValue& time, DateTimestampPart part,
                              TimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status TruncateDate(int32_t date, DateTimestampPart part, int32_t* output) {
      return absl::OkStatus();
    }

    absl::Status TimestampTrunc(int64_t timestamp, absl::TimeZone timezone,
                                DateTimestampPart part, int64_t* output) {
      return absl::OkStatus();
    }

    absl::Status TimestampTrunc(int64_t timestamp,
                                absl::string_view timezone_string,
                                DateTimestampPart part, int64_t* output) {
      return absl::OkStatus();
    }

    absl::Status TimestampTrunc(absl::Time timestamp, absl::TimeZone timezone,
                                DateTimestampPart part, absl::Time* output) {
      return absl::OkStatus();
    }

    absl::Status TimestampTrunc(absl::Time timestamp,
                                absl::string_view timezone_string,
                                DateTimestampPart part, absl::Time* output) {
      return absl::OkStatus();
    }

    absl::Status TruncateTimestamp(int64_t timestamp, TimestampScale scale,
                                   absl::TimeZone timezone, DateTimestampPart part,
                                   int64_t* output) {
      return absl::OkStatus();
    }

    absl::Status TruncateTimestamp(int64_t timestamp, TimestampScale scale,
                                   absl::string_view timezone_string,
                                   DateTimestampPart part, int64_t* output) {
      return absl::OkStatus();
    }

    absl::Status TruncateDatetime(const DatetimeValue& datetime,
                                  DateTimestampPart part, DatetimeValue* output) {
      return absl::OkStatus();
    }

    absl::Status TimestampDiff(int64_t timestamp1, int64_t timestamp2,
                               TimestampScale scale, DateTimestampPart part,
                               int64_t* output) {
      return absl::OkStatus();
    }

    absl::Status TimestampDiff(absl::Time timestamp1, absl::Time timestamp2,
                               DateTimestampPart part, int64_t* output) {
      return absl::OkStatus();
    }

    absl::StatusOr<IntervalValue> IntervalDiffTimestamps(absl::Time timestamp1,
                                                         absl::Time timestamp2) {
      IntervalValue v;
      return v;
    }

    std::string TimestampScale_Name(TimestampScale scale) {
      return "";
    }

    int DateTimestampPart_FromName(absl::string_view name) {
      return 0;
    }

    absl::Status DecodeFormattedDate(int64_t input_formatted_date,
                                     FieldFormat::Format format,
                                     int32_t* output_date, bool* output_is_null) {
      return absl::OkStatus();
    }

    absl::Status EncodeFormattedDate(int32_t input_date, FieldFormat::Format format,
                                     int32_t* output_formatted_date) {
      return absl::OkStatus();
    }

    int32_t CurrentDate(absl::TimeZone timezone) {
      return 0;
    }

    absl::Status CurrentDate(absl::string_view timezone_string, int32_t* date) {
      return absl::OkStatus();
    }

    int64_t CurrentTimestamp() {
      return 0;
    }

    void NarrowTimestampScaleIfPossible(absl::Time time, TimestampScale* scale) {
    }

    namespace internal_functions {

      absl::Status ExpandPercentZQJ(absl::string_view format_string,
                                    absl::Time base_time, absl::TimeZone timezone,
                                    const ExpansionOptions& expansion_options,
                                    std::string* expanded_format_string) {
        return absl::OkStatus();
      }

      int DayOfWeekIntegerSunToSat1To7(absl::Weekday weekday) {
        return 0;
      }

      void GetSignHourAndMinuteTimeZoneOffset(const absl::TimeZone::CivilInfo& info,
                                              bool* positive_offset,
                                              int32_t* hour_offset,
                                              int32_t* minute_offset) {
      }

      absl::TimeZone GetNormalizedTimeZone(absl::Time base_time, absl::TimeZone timezone) {
        absl::TimeZone v;
        return v;
      }
    }
  }
}

#endif

#include "go-zetasql/public/functions/arithmetics/export.inc"
#include "go-zetasql/public/functions/date_time_util_internal/export.inc"
#include "go-zetasql/public/functions/datetime_cc_proto/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/mathutil/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/base/time_proto_util/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/utf_util/export.inc"
#include "go-zetasql/public/civil_time/export.inc"
#include "go-zetasql/public/interval_value/export.inc"
#include "go-zetasql/public/proto/type_annotation_cc_proto/export.inc"
#include "go-zetasql/public/types/timestamp_util/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
