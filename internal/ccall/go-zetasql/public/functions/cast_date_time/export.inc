#ifndef ZETASQL_PUBLIC_FUNCTIONS_CAST_DATE_TIME_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_CAST_DATE_TIME_EXPORT_H

#include "zetasql/public/functions/cast_date_time.h"

#define kNaiveNumSecondsPerMinute GO_EXPORT(cast_date_time_kNaiveNumSecondsPerMinute)
#define kNaiveNumSecondsPerHour GO_EXPORT(cast_date_time_kNaiveNumSecondsPerHour)
#define kNaiveNumSecondsPerDay GO_EXPORT(cast_date_time_kNaiveNumSecondsPerDay)
#define kNaiveNumMicrosPerDay GO_EXPORT(cast_date_time_kNaiveNumMicrosPerDay)
#define powers_of_ten GO_EXPORT(cast_date_time_powers_of_ten)
#include "zetasql/public/functions/cast_date_time.cc"
#undef kNaiveNumSecondsPerMinute
#undef kNaiveNumSecondsPerHour
#undef kNaiveNumSecondsPerDay
#undef kNaiveNumMicrosPerDay
#undef powers_of_ten

#if 0
namespace zetasql {
  namespace functions {
    namespace cast_date_time_internal {

      std::string DateTimeFormatElement::ToString() const {
        return "";
      }

      using FormatElementTypeTrie =
        zetasql_base::GeneralTrie<FormatElementType, kFormatElementTypeNullValue>;

      const FormatElementTypeTrie* InitializeFormatElementTypeTrie() {
        return nullptr;
      }

      const FormatElementTypeTrie& GetFormatElementTypeTrie() {
        FormatElementTypeTrie* v;
        return *v;
      }

      absl::StatusOr<FormatCasingType> GetFormatCasingTypeOfNonLiteralElements(absl::string_view format_element_str, FormatElementCategory category) {
        FormatCasingType v;
        return v;
      }

      absl::StatusOr<DateTimeFormatElement> GetNextDateTimeFormatElement(absl::string_view format_str, absl::string_view upper_format_str) {
        DateTimeFormatElement v;
        return v;
      }

      absl::StatusOr<std::vector<DateTimeFormatElement>> GetDateTimeFormatElements(absl::string_view format_str) {
        std::vector<DateTimeFormatElement> v;
        return v;
      }

      absl::StatusOr<std::string> FromDateTimeFormatElementToFormatString(const DateTimeFormatElement& format_element, const absl::TimeZone::CivilInfo info) {
        return "";
      }

      absl::StatusOr<std::string> ResolveFormatString(const DateTimeFormatElement& format_element, absl::Time base_time, absl::TimeZone timezone) {
        return "";
      }

      absl::StatusOr<std::string> FromCastFormatTimestampToStringInternal(absl::Span<const DateTimeFormatElement> format_elements,
                                                                          absl::Time base_time, absl::TimeZone timezone) {
        return "";
      }

    }
    absl::Status CastStringToTimestamp(absl::string_view format_string,
                                       absl::string_view timestamp_string,
                                       const absl::TimeZone default_timezone,
                                       const absl::Time current_timestamp,
                                       int64_t* timestamp_micros) {
      return absl::OkStatus();
    }

    absl::Status CastStringToTimestamp(absl::string_view format_string,
                                       absl::string_view timestamp_string,
                                       absl::string_view default_timezone_string,
                                       const absl::Time current_timestamp,
                                       int64_t* timestamp) {
      return absl::OkStatus();
    }

    absl::Status CastStringToTimestamp(absl::string_view format_string,
                                       absl::string_view timestamp_string,
                                       const absl::TimeZone default_timezone,
                                       const absl::Time current_timestamp,
                                       absl::Time* timestamp) {
      return absl::OkStatus();
    }

    absl::Status CastStringToTimestamp(absl::string_view format_string,
                                       absl::string_view timestamp_string,
                                       absl::string_view default_timezone_string,
                                       const absl::Time current_timestamp,
                                       absl::Time* timestamp) {
      return absl::OkStatus();
    }

    absl::Status CastStringToDate(absl::string_view format_string,
                                  absl::string_view date_string,
                                  int32_t current_date, int32_t* date) {
      return absl::OkStatus();
    }

    absl::Status CastStringToTime(absl::string_view format_string,
                                  absl::string_view time_string,
                                  TimestampScale scale, TimeValue* time) {
      return absl::OkStatus();
    }

    absl::Status CastStringToDatetime(absl::string_view format_string,
                                      absl::string_view datetime_string,
                                      TimestampScale scale, int32_t current_date,
                                      DatetimeValue* datetime) {
      return absl::OkStatus();
    }

    absl::Status ValidateFormatStringForParsing(absl::string_view format_string, zetasql::TypeKind out_type) {
      return absl::OkStatus();
    }

    absl::Status ValidateFormatStringForFormatting(absl::string_view format_string, zetasql::TypeKind out_type) {
      return absl::OkStatus();
    }

    absl::Status CastFormatDateToString(absl::string_view format_string, int32_t date, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status CastFormatDatetimeToString(absl::string_view format_string, const DatetimeValue& datetime, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status CastFormatTimeToString(absl::string_view format_string, const TimeValue& time, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status CastFormatTimestampToString(absl::string_view format_string, int64_t timestamp_micros, absl::TimeZone timezone, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status CastFormatTimestampToString(absl::string_view format_string, int64_t timestamp_micros, absl::string_view timezone_string, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status CastFormatTimestampToString(absl::string_view format_string, absl::Time timestamp, absl::string_view timezone_string, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status CastFormatTimestampToString(absl::string_view format_string, absl::Time timestamp, absl::TimeZone timezone, std::string* out) {
      return absl::OkStatus();
    }

  }
}
#endif

#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-zetasql/public/functions/datetime_cc_proto/export.inc"
#include "go-zetasql/public/functions/input_format_string_max_width/export.inc"
#include "go-zetasql/public/functions/parse_date_time_utils/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/general_trie/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/mathutil/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/utf_util/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-icu/icu/export.inc"

#endif
