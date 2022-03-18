#ifndef ZETASQL_SCRIPTING_PARSE_HELPERS_EXPORT_H
#define ZETASQL_SCRIPTING_PARSE_HELPERS_EXPORT_H

#include "zetasql/scripting/parse_helpers.h"
#include "zetasql/scripting/parse_helpers.cc"

#if 0
namespace zetasql {
  absl::StatusOr<std::unique_ptr<ParserOutput>> ParseAndValidateScript(absl::string_view script_string, const ParserOptions& parser_options,
                                                                       ErrorMessageMode error_message_mode) {
    std::unique_ptr<ParserOutput> v;
    return v;
  }
}
#endif

#include "go-zetasql/scripting/parsed_script/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
