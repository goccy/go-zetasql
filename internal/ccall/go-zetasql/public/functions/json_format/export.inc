#ifndef ZETASQL_PUBLIC_FUNCTIONS_JSON_FORMAT_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_JSON_FORMAT_EXPORT_H

#include "zetasql/public/functions/json_format.h"
#include "zetasql/public/functions/json_format.cc"

#if 0
namespace zetasql {
  namespace functions {

    void JsonFromNumericOrBool(bool value, std::string* output) {
    }

    void JsonFromNumericOrBool(int32_t value, std::string* output) {
    }

    void JsonFromNumericOrBool(uint32_t value, std::string* output) {
    }

    void JsonFromNumericOrBool(int64_t value, std::string* output) {
    }

    void JsonFromNumericOrBool(uint64_t value, std::string* output) {
    }

    void JsonFromNumericOrBool(float value, std::string* output) {
    }

    void JsonFromNumericOrBool(double value, std::string* output) {
    }

    void JsonFromNumericOrBool(NumericValue value, std::string* output) {
    }

    void JsonFromNumericOrBool(const BigNumericValue& value, std::string* output) {
    }

    void JsonFromString(absl::string_view value, std::string* output) {
    }

    void JsonFromBytes(absl::string_view value, std::string* output, bool quote_output_string) {
    }

    absl::Status JsonFromTimestamp(absl::Time value, std::string* output, bool quote_output_string) {
      return absl::OkStatus();
    }

    absl::Status JsonFromDatetime(const DatetimeValue& value, std::string* output, bool quote_output_string) {
      return absl::OkStatus();
    }

    absl::Status JsonFromDate(int32_t value, std::string* output, bool quote_output_string) {
      return absl::OkStatus();
    }

    absl::Status JsonFromTime(const TimeValue& value, std::string* output, bool quote_output_string) {
      return absl::OkStatus();
    }

    absl::Status JsonFromInterval(const IntervalValue& value, std::string* output) {
      return absl::OkStatus();
    }

    void JsonFromJson(JSONValueConstRef value, JsonPrettyPrinter* pretty_printer, std::string* output) {
    }

    absl::Status JsonFromValue(const Value& value, JsonPrettyPrinter* pretty_printer, std::string* output, const JSONParsingOptions& json_parsing_options) {
      return absl::OkStatus();
    }

  }
}
#endif

#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/json_util/export.inc"
#include "go-zetasql/common/string_util/export.inc"
#include "go-zetasql/public/civil_time/export.inc"
#include "go-zetasql/public/json_value/export.inc"
#include "go-zetasql/public/numeric_value/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
