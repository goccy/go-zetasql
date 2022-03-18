#ifndef ZETASQL_PUBLIC_FUNCTIONS_REGEXP_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_REGEXP_EXPORT_H

#include "zetasql/public/functions/regexp.h"
#include "zetasql/public/functions/regexp.cc"

#if 0
namespace zetasql {
  namespace functions {

    bool RegExp::InitializePatternUtf8(absl::string_view pattern, absl::Status* error) {
      return false;
    }

    bool RegExp::InitializePatternBytes(absl::string_view pattern, absl::Status* error) {
      return false;
    }

    bool RegExp::InitializeWithOptions(absl::string_view pattern, const RE2::Options& options, absl::Status* error) {
      return false;
    }

    bool RegExp::Contains(absl::string_view str, bool* out, absl::Status* error) const {
      return false;
    }

    bool RegExp::Match(absl::string_view str, bool* out, absl::Status* error) const {
      return false;
    }

    bool RegExp::Extract(absl::string_view str, PositionUnit position_unit,
                         int64_t position, int64_t occurrence_index,
                         absl::string_view* out, bool* is_null,
                         absl::Status* error) const {
      return false;
    }

    RegExp::ExtractAllIterator::ExtractAllIterator(const RE2* re, absl::string_view str)
      : re_(re), extract_all_input_(str) {}

    bool RegExp::ExtractAllIterator::Next(absl::string_view* out, absl::Status* error) {
      return false;
    }

    RegExp::ExtractAllIterator RegExp::CreateExtractAllIterator(absl::string_view str) const {
      RegExp::ExtractAllIterator v;
      return v;
    }

    bool RegExp::Instr(const InstrParams& options, absl::Status* error) const {
      return false;
    }

    bool RegExp::Replace(absl::string_view str, absl::string_view newsub, std::string* out, absl::Status* error) const {
      return false;
    }

    bool RegExp::Replace(absl::string_view str, absl::string_view newsub, int32_t max_out_size, std::string* out, absl::Status* error) const {
      return false;
    }

    bool RegExp::Rewrite(absl::string_view rewrite, const std::vector<absl::string_view>& groups, int32_t max_out_size, std::string* out, absl::Status* error) const {
      return false;
    }

    absl::StatusOr<std::unique_ptr<const RegExp>> MakeRegExpUtf8(absl::string_view pattern) {
      std::unique_ptr<const RegExp> v;
      return v;
    }

    absl::StatusOr<std::unique_ptr<const RegExp>> MakeRegExpBytes(absl::string_view pattern) {
      std::unique_ptr<const RegExp> v;
      return v;
    }

    absl::StatusOr<std::unique_ptr<const RegExp>> MakeRegExpWithOptions(absl::string_view pattern, const RE2::Options& options) {
      std::unique_ptr<const RegExp> v;
      return v;
    }

  }
}
#endif

#include "go-zetasql/public/functions/string/export.inc"
#include "go-zetasql/public/functions/util/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/utf_util/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/optional/export.inc"
#include "go-re2/re2/export.inc"
#include "go-icu/icu/export.inc"

#endif
