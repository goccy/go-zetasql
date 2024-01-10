//
// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// Helper methods for producing the types required by TestDriver
// implementations.
#include <vector>

#include "zetasql/public/type.h"
#include "zetasql/resolved_ast/resolved_column.h"
#include "absl/status/statusor.h"

#ifndef ZETASQL_REFERENCE_IMPL_TYPE_HELPERS_H_
#define ZETASQL_REFERENCE_IMPL_TYPE_HELPERS_H_

namespace zetasql {

// Creates the Relational Algebra representation of a relation from the
// resolved AST, which is modeled as an array in the compliance tests.
absl::StatusOr<const ArrayType*> CreateTableArrayType(
    const ResolvedColumnList& table_columns, bool is_value_table,
    TypeFactory* type_factory);

// Names of DML output columns used by CreateDMLOutputType().
extern const char* kDMLOutputNumRowsModifiedColumnName;
extern const char* kDMLOutputAllRowsColumnName;
extern const char* kDMLOutputReturningColumnName;

// Creates a Struct type representing the primary key of a table.
//
// Each key column is represented by a field named StrCat("$pk#", column_name).
//
// key_column_indexes are positional indexes of primary key columns in
// table_columns.
absl::StatusOr<const StructType*> CreatePrimaryKeyType(
    const ResolvedColumnList& table_columns,
    const std::vector<int>& key_column_indexes, TypeFactory* type_factory);

// Creates the DML output struct type corresponding to a DML statement on a
// table whose corresponding array type is 'table_array_type'.
//
// The returned type is a struct with two fields: an int64_t representing the
// number of rows modified by the statement, and an array of structs, where each
// element of the array represents a row of the modified table.
absl::StatusOr<const StructType*> CreateDMLOutputType(
    const ArrayType* table_array_type, TypeFactory* type_factory);

// Creates the DML output struct type corresponding to a DML statement on a
// table whose corresponding array type is 'table_array_type' and a returning
// result table whose corresponding array type is 'returning_array_type'.
// If "returning_array_type" is nullptr, this table as a return type of
// returning clause is ignored from the DML output struct type.
// and
//
// The returned type is a struct with three fields: an int64_t representing the
// number of rows modified by the statement, and an array of structs, where each
// element of the array represents a row of the modified table.
absl::StatusOr<const StructType*> CreateDMLOutputTypeWithReturning(
    const ArrayType* table_array_type, const ArrayType* returning_array_type,
    TypeFactory* type_factory);

}  // namespace zetasql

#endif  // ZETASQL_REFERENCE_IMPL_TYPE_HELPERS_H_
