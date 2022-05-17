#ifndef ZETASQL_PUBLIC_FUNCTIONS_CONVERT_STRING_WITH_FORMAT_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_CONVERT_STRING_WITH_FORMAT_EXPORT_H

#include "zetasql/public/functions/convert_string_with_format.h"
#include "zetasql/public/functions/convert_string_with_format.cc"

#if 0
namespace zetasql {
  namespace functions {
    namespace internal {

      std::string FormatElementToString(FormatElement element) {
        return "";
      }

      absl::optional<FormatElement> GetFormatElement(absl::string_view str, int& length) {
        return absl::nullopt;
      }

      absl::StatusOr<ParsedFormatElementInfo> FormatParser::Parse(absl::string_view format) {
        ParsedFormatElementInfo v;
        return v;
      }

      absl::StatusOr<std::string> GenerateFractionalPart(const ParsedFormatElementInfo& parsed_info, const ParsedNumberString& n) {
        return "";
      }

      absl::StatusOr<std::string> GenerateCurrencyOutput(bool is_b_effective, const ParsedFormatElementInfo& parsed_info) {
        return "";
      }

      bool OverflowForInfinityOrNaN(const ParsedFormatElementInfo& parsed_info) {
        return false;
      }

      absl::StatusOr<std::string> GenerateFractionalPartForInfinityOrNaN(const ParsedFormatElementInfo& parsed_info) {
        return "";
      }

      absl::StatusOr<std::string> FormatInfinityOrNaN(const ParsedFormatElementInfo& parsed_info, const ParsedNumberString& n) {
        return "";
      }

      absl::StatusOr<std::string> FormatAsDecimalInternal(const ParsedFormatElementInfo& parsed_info, const ParsedNumberString& n) {
        return "";
      }

      absl::StatusOr<std::string> FormatAsDecimal(const ParsedFormatElementInfo& parsed_info, const Value& v, ProductMode product_mode) {
        return "";
      }

      absl::StatusOr<std::string> FormatAsHexadecimal(const ParsedFormatElementInfo& parsed_info, const Value& v) {
        return "";
      }

      absl::StatusOr<ParsedNumberString> ParseFormattedRealNumber(absl::string_view number_string) {
        ParsedNumberString v;
        return v;
      }

      absl::StatusOr<ParsedFormatElementInfo> ParseForTest(absl::string_view format) {
        ParsedFormatElementInfo v;
        return v;
      }

    }

    absl::StatusOr<std::string> NumericalToStringFormatter::Format(const Value& v) {
      return "";
    }

    absl::Status NumericalToStringFormatter::SetFormatString(absl::string_view format) {
      return absl::OkStatus();
    }

    absl::Status ValidateNumericalToStringFormat(absl::string_view format) {
      return absl::OkStatus();
    }

    absl::StatusOr<std::string> NumericalToStringWithFormat(const Value& v, absl::string_view format, ProductMode product_mode) {
      return "";
    }

  }
}
#endif

#include "go-zetasql/public/functions/convert/export.inc"
#include "go-zetasql/public/functions/format_max_output_width/export.inc"
#include "go-zetasql/public/functions/string_format/export.inc"
#include "go-zetasql/public/functions/util/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-re2/re2/export.inc"

#endif
