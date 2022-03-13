#ifndef ZETASQL_PUBLIC_STRINGS_EXPORT_H
#define ZETASQL_PUBLIC_STRINGS_EXPORT_H

#include "zetasql/public/strings.h"
#include "zetasql/public/strings.cc"

#if 0

namespace zetasql {

  absl::Status UnescapeString(absl::string_view str, std::string* out,
                              std::string* error_string, int* error_offset) {
    return absl::OkStatus();
  }

  absl::Status UnescapeBytes(absl::string_view str, std::string* out,
                             std::string* error_string, int* error_offset) {
    return absl::OkStatus();
  }

  std::string EscapeString(absl::string_view str) {
    return "";
  }

  std::string EscapeBytes(absl::string_view str, bool escape_all_bytes,
                          char escape_quote_char) {
    return "";
  }

  absl::Status ParseStringLiteral(absl::string_view str, std::string* out,
                                  std::string* error_string, int* error_offset) {
    return absl::OkStatus();
  }

  absl::Status ParseBytesLiteral(absl::string_view str, std::string* out,
                                 std::string* error_string, int* error_offset) {
    return absl::OkStatus();
  }

  std::string ToStringLiteral(absl::string_view str) {
    return "";
  }

  std::string ToSingleQuotedStringLiteral(absl::string_view str) {
    return "";
  }

  std::string ToDoubleQuotedStringLiteral(absl::string_view str) {
    return "";
  }

  std::string ToBytesLiteral(absl::string_view str) {
    return "";
  }

  std::string ToSingleQuotedBytesLiteral(absl::string_view str) {
    return "";
  }

  std::string ToDoubleQuotedBytesLiteral(absl::string_view str) {
    return "";
  }

  absl::Status ParseIdentifier(absl::string_view str,
                               const LanguageOptions& language_options,
                               std::string* out, std::string* error_string,
                               int* error_offset) {
    return absl::OkStatus();
  }

  absl::Status ParseGeneralizedIdentifier(absl::string_view str, std::string* out,
                                          std::string* error_string,
                                          int* error_offset) {
    return absl::OkStatus();
  }

  std::string ToIdentifierLiteral(absl::string_view str,
                                  bool quote_reserved_keywords) {
    return "";
  }

  std::string ToIdentifierLiteral(IdString str, bool quote_reserved_keywords) {
    return "";
  }

  std::string IdentifierPathToString(absl::Span<const std::string> path,
                                     bool quote_reserved_keywords) {
    return "";
  }

  std::string IdentifierPathToString(absl::Span<const IdString> path,
                                     bool quote_reserved_keywords) {
    return "";
  }

  absl::Status ParseIdentifierPath(absl::string_view str,
                                   const LanguageOptions& language_options,
                                   std::vector<std::string>* out) {
    return absl::OkStatus();
  }

  bool IsInternalAlias(const std::string& alias) {
    return false;
  }

  bool IsInternalAlias(IdString alias) {
    return false;
  }

  bool IsKeyword(absl::string_view str) {
    return false;
  }

  bool IsReservedKeyword(absl::string_view str) {
    return false;
  }

  const absl::flat_hash_set<std::string>& GetReservedKeywords() {
    absl::flat_hash_set<std::string> *v;
    return *v;
  }

  const absl::flat_hash_set<std::string>& GetPotentiallyReservedKeywords() {
    absl::flat_hash_set<std::string> *v;
    return *v;
  }

}

#endif

#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/case/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/utf_util/export.inc"
#include "go-zetasql/parser/keywords/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"

#endif
