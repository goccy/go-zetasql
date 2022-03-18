#ifndef ZETASQL_SCRIPTING_PARSED_SCRIPT_EXPORT_H
#define ZETASQL_SCRIPTING_PARSED_SCRIPT_EXPORT_H

#include "zetasql/scripting/break_continue_context.h"
#include "zetasql/scripting/parsed_script.h"

#include "zetasql/scripting/parsed_script.cc"

#if 0
namespace zetasql {

  absl::StatusOr<const ASTNode*> ParsedScript::FindScriptNodeFromPosition(const ParseLocationPoint& start_pos) const {
    return nullptr;
  }

  absl::StatusOr<ParsedScript::VariableCreationMap>
  ParsedScript::GetVariablesInScopeAtNode(const ControlFlowNode * node) const {
    ParsedScript::VariableCreationMap v;
    return v;
  }

  absl::Status ParsedScript::GatherInformationAndRunChecksInternal() {
    return absl::OkStatus();
  }

  absl::Status ParsedScript::GatherInformationAndRunChecks() {
    return absl::OkStatus();
  }

  ParsedScript::ParsedScript(absl::string_view script_string, const ASTScript* ast_script,
                             std::unique_ptr<ParserOutput> parser_output,
                             ErrorMessageMode error_message_mode, ArgumentTypeMap routine_arguments,
                             bool is_procedure,
                             const VariableWithTypeParameterMap& predefined_variable_names)
    : parser_output_(std::move(parser_output)),
      ast_script_(ast_script),
      script_string_(script_string),
      error_message_mode_(error_message_mode),
      routine_arguments_(std::move(routine_arguments)),
      is_procedure_(is_procedure),
      predefined_variable_names_(predefined_variable_names) {}

  absl::StatusOr<std::unique_ptr<ParsedScript>> ParsedScript::CreateInternal(absl::string_view script_string, const ParserOptions& parser_options,
                                                                             ErrorMessageMode error_message_mode, ArgumentTypeMap routine_arguments,
                                                                             bool is_procedure,
                                                                             const VariableWithTypeParameterMap& predefined_variable_names) {
    std::unique_ptr<ParsedScript> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ParsedScript>> ParsedScript::Create(absl::string_view script_string, const ParserOptions& parser_options,
                                                                     ErrorMessageMode error_message_mode,
                                                                     const VariableWithTypeParameterMap& predefined_variable_names) {
    std::unique_ptr<ParsedScript> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ParsedScript>> ParsedScript::CreateForRoutine(absl::string_view script_string, const ParserOptions& parser_options,
                                                                               ErrorMessageMode error_message_mode, ArgumentTypeMap routine_arguments,
                                                                               const VariableWithTypeParameterMap& predefined_variable_names) {
    std::unique_ptr<ParsedScript> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ParsedScript>> ParsedScript::CreateForRoutine(absl::string_view script_string, const ASTScript* ast_script,
                                                                               ErrorMessageMode error_message_mode, ArgumentTypeMap routine_arguments,
                                                                               const VariableWithTypeParameterMap& predefined_variable_names) {
    std::unique_ptr<ParsedScript> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ParsedScript>> ParsedScript::Create(absl::string_view script_string, const ASTScript* ast_script,
                                                                     ErrorMessageMode error_message_mode,
                                                                     const VariableWithTypeParameterMap& predefined_variable_names) {
    std::unique_ptr<ParsedScript> v;
    return v;
  }

  absl::Status ParsedScript::PopulateQueryParameters() {
    return absl::OkStatus();
  }

  std::pair<int64_t, int64_t> ParsedScript::GetPositionalParameters(const ParseLocationRange& range) const {
    std::pair<int64_t, int64_t> v;
    return v;
  }

  ParsedScript::StringSet ParsedScript::GetNamedParameters(const ParseLocationRange& range) const {
    ParsedScript::StringSet v;
    return v;
  }

  ParsedScript::StringSet ParsedScript::GetAllNamedParameters() const {
    ParsedScript::StringSet v;
    return v;
  }

  absl::Status ParsedScript::CheckQueryParameters(const ParsedScript::QueryParameters& parameters) const {
    return absl::OkStatus();
  }

  absl::Status ParsedScript::CheckQueryParametersInternal(const ParsedScript::QueryParameters& parameters) const {
    return absl::OkStatus();
  }

}
#endif

#include "go-zetasql/scripting/control_flow_graph/export.inc"
#include "go-zetasql/scripting/error_helpers/export.inc"
#include "go-zetasql/scripting/type_aliases/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/variant/export.inc"

#endif
