#ifndef ZETASQL_PUBLIC_PARSE_LOCATION_EXPORT_H
#define ZETASQL_PUBLIC_PARSE_LOCATION_EXPORT_H

#include "zetasql/public/parse_location.h"
#include "zetasql/public/parse_location.cc"

#if 0
namespace zetasql {

  const int kTabWidth = 8;

  InternalErrorLocation ParseLocationPoint::ToInternalErrorLocation() const {
    InternalErrorLocation v;
    return v;
  }

  ParseLocationPoint ParseLocationPoint::FromInternalErrorLocation(const InternalErrorLocation& info) {
    ParseLocationPoint v;
    return v;
  }

  ParseLocationTranslator::ParseLocationTranslator(absl::string_view input)
    : input_(input) {}

  void ParseLocationTranslator::CalculateLineOffsets() const {
  }

  absl::StatusOr<std::pair<int, int>>
  ParseLocationTranslator::GetLineAndColumnFromByteOffset(int byte_offset) const {
    absl::StatusOr<std::pair<int, int>> v;
    return v;
  }

  absl::StatusOr<int> ParseLocationTranslator::GetByteOffsetFromLineAndColumn(int line, int column) const {
    absl::StatusOr<int> v;
    return v;
  }

  absl::StatusOr<std::pair<int, int>>
  ParseLocationTranslator::GetLineAndColumnAfterTabExpansion(ParseLocationPoint point) const {
    absl::StatusOr<std::pair<int, int>> v;
    return v;
  }

  std::string ParseLocationTranslator::ExpandTabs(absl::string_view input) {
    return "";
  }

  absl::StatusOr<absl::string_view> ParseLocationTranslator::GetLineText(int line) const {
    absl::StatusOr<absl::string_view> v;
    return v;
  }

}
#endif

#include "go-zetasql/public/parse_location_range_cc_proto/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/mathutil/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/proto/internal_error_location_cc_proto/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
