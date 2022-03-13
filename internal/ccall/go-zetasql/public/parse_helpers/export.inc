#ifndef ZETASQL_PUBLIC_PARSE_HELPERS_EXPORT_H
#define ZETASQL_PUBLIC_PARSE_HELPERS_EXPORT_H

#include "zetasql/public/parse_helpers.h"
#include "zetasql/public/parse_tokens.h"
#include "zetasql/public/parse_helpers.cc"
#include "zetasql/public/parse_tokens.cc"

#if 0
namespace zetasql {

  absl::Status IsValidStatementSyntax(absl::string_view sql,
                                      ErrorMessageMode error_message_mode) {
    return absl::OkStatus();
  }

  absl::Status IsValidNextStatementSyntax(ParseResumeLocation* resume_location,
                                          ErrorMessageMode error_message_mode,
                                          bool* at_end_of_input) {
    return absl::OkStatus();
  }

  ResolvedNodeKind GetStatementKind(const std::string& input) {
    ResolvedNodeKind v;
    return v;
  }

  ResolvedNodeKind GetStatementKind(ASTNodeKind node_kind) {
    ResolvedNodeKind v;
    return v;
  }

  ResolvedNodeKind GetNextStatementKind(const ParseResumeLocation& resume_location,
                                        const LanguageOptions& language_options) {
    ResolvedNodeKind v;
    return v;
  }

  absl::Status GetStatementProperties(const std::string& input,
                                      const LanguageOptions& language_options,
                                      StatementProperties* statement_properties) {
    return absl::OkStatus();
  }

  absl::Status GetNextStatementProperties(const ParseResumeLocation& resume_location,
                                          const LanguageOptions& language_options,
                                          StatementProperties* statement_properties) {
    return absl::OkStatus();
  }

}

namespace zetasql {

  absl::Status GetParseTokens(const ParseTokenOptions& options,
                              ParseResumeLocation* resume_location,
                              std::vector<ParseToken>* tokens) {
    return absl::OkStatus();
  }

  std::string ParseToken::GetKeyword() const {
    return "";
  }

  std::string ParseToken::GetIdentifier() const {
    return "";
  }

  Value ParseToken::GetValue() const {
    Value v;
    return v;
  }

  std::string ParseToken::GetSQL() const {
    return "";
  }

  absl::string_view ParseToken::GetImage() const {
    absl::string_view v;
    return v;
  }

  std::string ParseToken::DebugString() const {
    return "";
  }

  ParseToken::ParseToken() : kind_(END_OF_INPUT) {}

  ParseToken::ParseToken(ParseLocationRange location_range, std::string image,
                         Kind kind)
    : kind_(kind), image_(std::move(image)), location_range_(location_range) {}

  ParseToken::ParseToken(ParseLocationRange location_range, std::string image,
                         Kind kind, Value value)
    : kind_(kind),
      image_(std::move(image)),
      location_range_(location_range),
      value_(std::move(value)) {
  }

}
#endif

#include "go-zetasql/public/error_helpers/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/parse_resume_location/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/parser/bison_parser_generated_lib/export.inc"
#include "go-zetasql/parser/keywords/export.inc"
#include "go-zetasql/public/functions/convert_string/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
