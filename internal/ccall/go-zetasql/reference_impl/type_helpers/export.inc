#ifndef ZETASQL_REFERENCE_IMPL_TYPE_HELPERS_EXPORT_H
#define ZETASQL_REFERENCE_IMPL_TYPE_HELPERS_EXPORT_H

#include "zetasql/reference_impl/type_helpers.h"

namespace zetasql {

  const char* kDMLOutputNumRowsModifiedColumnName = "num_rows_modified";
  const char* kDMLOutputAllRowsColumnName = "all_rows";
  const char* kDMLOutputReturningColumnName = "returning_rows";

  absl::StatusOr<const ArrayType*> CreateTableArrayType(const ResolvedColumnList& table_columns, bool is_value_table,
                                                        TypeFactory* type_factory) {
    return nullptr;
  }

  absl::StatusOr<const StructType*> CreatePrimaryKeyType(const ResolvedColumnList& table_columns,
                                                         const std::vector<int>& key_column_indexes, TypeFactory* type_factory) {
    return nullptr;
  }

  absl::StatusOr<const StructType*> CreateDMLOutputType(const ArrayType* table_array_type, TypeFactory* type_factory) {
    return nullptr;
  }

  absl::StatusOr<const StructType*> CreateDMLOutputTypeWithReturning(const ArrayType* table_array_type, const ArrayType* returning_array_type,
                                                                     TypeFactory* type_factory) {
    return nullptr;
  }

}

#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
