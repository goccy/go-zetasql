#ifndef ZETASQL_REFERENCE_IMPL_VARIABLE_GENERATOR_EXPORT_H
#define ZETASQL_REFERENCE_IMPL_VARIABLE_GENERATOR_EXPORT_H

#include "zetasql/reference_impl/variable_generator.h"

namespace zetasql {

  VariableId VariableGenerator::GetNewVariableName(std::string suggested_name) {
    VariableId v;
    return v;
  }

  VariableId VariableGenerator::GetVariableNameFromSystemVariable(const std::vector<std::string>& name_path,
                                                                  SystemVariablesAlgebrizerMap* system_variables_map) {
    VariableId v;
    return v;
  }

  VariableId VariableGenerator::GetVariableNameFromParameter(const std::string& parameter_name, ParameterMap* map) {
    VariableId v;
    return v;
  }

  VariableId VariableGenerator::GetVariableNameFromParameter(int parameter_position, ParameterList* parameter_list) {
    VariableId v;
    return v;
  }

  VariableId ColumnToVariableMapping::AssignNewVariableToColumn(const ResolvedColumn& column) {
    VariableId v;
    return v;
  }

  VariableId ColumnToVariableMapping::GetVariableNameFromColumn(const ResolvedColumn& column) {
    VariableId v;
    return v;
  }

  absl::StatusOr<VariableId> ColumnToVariableMapping::LookupVariableNameForColumn(const ResolvedColumn& column) const {
    VariableId v;
    return v;
  }

  std::string ColumnToVariableMapping::DebugString() const {
    return "";
  }

}


#include "go-zetasql/reference_impl/common/export.inc"
#include "go-zetasql/reference_impl/parameter/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/analyzer/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/variant/export.inc"

#endif
