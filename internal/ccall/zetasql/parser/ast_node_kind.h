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

#ifndef ZETASQL_PARSER_AST_NODE_KIND_H_
#define ZETASQL_PARSER_AST_NODE_KIND_H_

namespace zetasql {

// Constants for parse tree node types.
enum ASTNodeKind {
  // Returned by ParseNextStatementKind for unknown types.
  kUnknownASTNodeKind = -1,

  kFirstASTNodeKind = 0,
  AST_FAKE = kFirstASTNodeKind,  // AST_FAKE is for testing purposes only.
  AST_ABORT_BATCH_STATEMENT,
  AST_ADD_COLUMN_ACTION,
  AST_ADD_CONSTRAINT_ACTION,
  AST_ADD_TO_RESTRICTEE_LIST_CLAUSE,
  AST_FUNCTION_CALL_WITH_GROUP_ROWS,
  AST_ALIAS,
  AST_ALTER_ACTION_LIST,
  AST_ALTER_ALL_ROW_ACCESS_POLICIES_STATEMENT,
  AST_ALTER_COLUMN_OPTIONS_ACTION,
  AST_ALTER_COLUMN_DROP_NOT_NULL_ACTION,
  AST_ALTER_COLUMN_TYPE_ACTION,
  AST_ALTER_COLUMN_SET_DEFAULT_ACTION,
  AST_ALTER_COLUMN_DROP_DEFAULT_ACTION,
  AST_ALTER_CONSTRAINT_ENFORCEMENT_ACTION,
  AST_ALTER_CONSTRAINT_SET_OPTIONS_ACTION,
  AST_ALTER_DATABASE_STATEMENT,
  AST_ALTER_ENTITY_STATEMENT,
  AST_ALTER_MATERIALIZED_VIEW_STATEMENT,
  AST_ALTER_PRIVILEGE_RESTRICTION_STATEMENT,
  AST_ALTER_ROW_ACCESS_POLICY_STATEMENT,
  AST_ALTER_SCHEMA_STATEMENT,
  AST_ALTER_TABLE_STATEMENT,
  AST_ALTER_VIEW_STATEMENT,
  AST_ANALYTIC_FUNCTION_CALL,
  AST_ANALYZE_STATEMENT,
  AST_AND_EXPR,
  AST_ANY_SOME_ALL_OP,
  AST_ARRAY_COLUMN_SCHEMA,
  AST_ARRAY_CONSTRUCTOR,
  AST_ARRAY_ELEMENT,
  AST_ARRAY_TYPE,
  AST_ASSERT_ROWS_MODIFIED,
  AST_ASSERT_STATEMENT,
  AST_ASSIGNMENT_FROM_STRUCT,
  AST_BEGIN_STATEMENT,
  AST_BETWEEN_EXPRESSION,
  AST_AUX_LOAD_DATA_FROM_FILES_OPTIONS_LIST,
  AST_AUX_LOAD_DATA_STATEMENT,
  AST_BIGNUMERIC_LITERAL,
  AST_BINARY_EXPRESSION,
  AST_BITWISE_SHIFT_EXPRESSION,
  AST_BEGIN_END_BLOCK,
  AST_BOOLEAN_LITERAL,
  AST_BREAK_STATEMENT,
  AST_BYTES_LITERAL,
  AST_CALL_STATEMENT,
  AST_CASE_STATEMENT,
  AST_CASE_NO_VALUE_EXPRESSION,
  AST_CASE_VALUE_EXPRESSION,
  AST_CAST_EXPRESSION,
  AST_CHECK_CONSTRAINT,
  AST_CLAMPED_BETWEEN_MODIFIER,
  AST_CLONE_DATA_SOURCE,
  AST_CLONE_DATA_SOURCE_LIST,
  AST_CLONE_DATA_STATEMENT,
  AST_CLUSTER_BY,
  AST_COLLATE,
  AST_COLUMN_ATTRIBUTE_LIST,
  AST_COLUMN_DEFINITION,
  AST_COLUMN_LIST,
  AST_COLUMN_POSITION,
  AST_COMMIT_STATEMENT,
  AST_CONNECTION_CLAUSE,
  AST_CONTINUE_STATEMENT,
  AST_COPY_DATA_SOURCE,
  AST_CREATE_CONSTANT_STATEMENT,
  AST_CREATE_DATABASE_STATEMENT,
  AST_CREATE_EXTERNAL_TABLE_STATEMENT,
  AST_CREATE_FUNCTION_STATEMENT,
  AST_CREATE_INDEX_STATEMENT,
  AST_CREATE_MODEL_STATEMENT,
  AST_CREATE_PROCEDURE_STATEMENT,
  AST_CREATE_PRIVILEGE_RESTRICTION_STATEMENT,
  AST_CREATE_ROW_ACCESS_POLICY_STATEMENT,
  AST_CREATE_SCHEMA_STATEMENT,
  AST_CREATE_SNAPSHOT_TABLE_STATEMENT,
  AST_CREATE_TABLE_FUNCTION_STATEMENT,
  AST_CREATE_TABLE_STATEMENT,
  AST_CREATE_ENTITY_STATEMENT,
  AST_CREATE_VIEW_STATEMENT,
  AST_CREATE_MATERIALIZED_VIEW_STATEMENT,
  AST_DATE_OR_TIME_LITERAL,
  AST_DEFAULT_LITERAL,
  AST_DEFINE_TABLE_STATEMENT,
  AST_DELETE_STATEMENT,
  AST_DESCRIBE_STATEMENT,
  AST_DESCRIPTOR_COLUMN,
  AST_DESCRIPTOR_COLUMN_LIST,
  AST_DESCRIPTOR,
  AST_DOT_GENERALIZED_FIELD,
  AST_DOT_IDENTIFIER,
  AST_DOT_STAR,
  AST_DOT_STAR_WITH_MODIFIERS,
  AST_DROP_ALL_ROW_ACCESS_POLICIES_STATEMENT,
  AST_DROP_COLUMN_ACTION,
  AST_DROP_CONSTRAINT_ACTION,
  AST_DROP_ENTITY_STATEMENT,
  AST_DROP_FUNCTION_STATEMENT,
  AST_DROP_PRIMARY_KEY_ACTION,
  AST_DROP_PRIVILEGE_RESTRICTION_STATEMENT,
  AST_DROP_ROW_ACCESS_POLICY_STATEMENT,
  AST_DROP_SEARCH_INDEX_STATEMENT,
  AST_DROP_STATEMENT,
  AST_DROP_TABLE_FUNCTION_STATEMENT,
  AST_DROP_MATERIALIZED_VIEW_STATEMENT,
  AST_DROP_SNAPSHOT_TABLE_STATEMENT,
  AST_ELSEIF_CLAUSE,
  AST_ELSEIF_CLAUSE_LIST,
  AST_EXCEPTION_HANDLER,
  AST_EXCEPTION_HANDLER_LIST,
  AST_EXECUTE_IMMEDIATE_STATEMENT,
  AST_EXECUTE_INTO_CLAUSE,
  AST_EXECUTE_USING_ARGUMENT,
  AST_EXECUTE_USING_CLAUSE,
  AST_EXPLAIN_STATEMENT,
  AST_EXPORT_DATA_STATEMENT,
  AST_EXPORT_MODEL_STATEMENT,
  AST_EXPRESSION_SUBQUERY,
  AST_EXTRACT_EXPRESSION,
  AST_FILTER_FIELDS_ARG,
  AST_FILTER_FIELDS_EXPRESSION,
  AST_FILTER_USING_CLAUSE,
  AST_FLOAT_LITERAL,
  AST_FOR_IN_STATEMENT,
  AST_FOREIGN_KEY,
  AST_FOREIGN_KEY_ACTIONS,
  AST_FOREIGN_KEY_COLUMN_ATTRIBUTE,
  AST_FOREIGN_KEY_REFERENCE,
  AST_FORMAT_CLAUSE,
  AST_FOR_SYSTEM_TIME,
  AST_FROM_CLAUSE,
  AST_FUNCTION_CALL,
  AST_FUNCTION_DECLARATION,
  AST_FUNCTION_PARAMETER,
  AST_FUNCTION_PARAMETERS,
  AST_GENERATED_COLUMN_INFO,
  AST_GRANTEE_LIST,
  AST_GRANT_STATEMENT,
  AST_GRANT_TO_CLAUSE,
  AST_RESTRICT_TO_CLAUSE,
  AST_GROUP_BY,
  AST_GROUPING_ITEM,
  AST_HAVING,
  AST_HAVING_MODIFIER,
  AST_HIDDEN_COLUMN_ATTRIBUTE,
  AST_HINT,
  AST_HINTED_STATEMENT,
  AST_HINT_ENTRY,
  AST_IDENTIFIER,
  AST_IDENTIFIER_LIST,
  AST_IF_STATEMENT,
  AST_IMPORT_STATEMENT,
  AST_IN_EXPRESSION,
  AST_IN_LIST,
  AST_INDEX_ALL_COLUMNS,
  AST_INDEX_ITEM_LIST,
  AST_INDEX_STORING_EXPRESSION_LIST,
  AST_INDEX_UNNEST_EXPRESSION_LIST,
  AST_INFERRED_TYPE_COLUMN_SCHEMA,
  AST_INSERT_STATEMENT,
  AST_INSERT_VALUES_ROW,
  AST_INSERT_VALUES_ROW_LIST,
  AST_INTERVAL_EXPR,
  AST_INTO_ALIAS,
  AST_INT_LITERAL,
  AST_JOIN,
  AST_JSON_LITERAL,
  AST_LABEL,
  AST_LAMBDA,
  AST_LIKE_EXPRESSION,
  AST_LIMIT_OFFSET,
  AST_MAX_LITERAL,
  AST_MERGE_ACTION,
  AST_MERGE_STATEMENT,
  AST_MERGE_WHEN_CLAUSE,
  AST_MERGE_WHEN_CLAUSE_LIST,
  AST_MODEL_CLAUSE,
  AST_MODULE_STATEMENT,
  AST_NAMED_ARGUMENT,
  AST_NEW_CONSTRUCTOR,
  AST_NEW_CONSTRUCTOR_ARG,
  AST_NOT_NULL_COLUMN_ATTRIBUTE,
  AST_NULL_LITERAL,
  AST_NULL_ORDER,
  AST_NUMERIC_LITERAL,
  AST_ON_CLAUSE,
  AST_ON_OR_USING_CLAUSE_LIST,
  AST_OPTIONS_ENTRY,
  AST_OPTIONS_LIST,
  AST_ORDER_BY,
  AST_ORDERING_EXPRESSION,
  AST_OR_EXPR,
  AST_PARAMETER_ASSIGNMENT,
  AST_PARAMETER_EXPR,
  AST_PARENTHESIZED_JOIN,
  AST_PARTITION_BY,
  AST_PATH_EXPRESSION,
  AST_PATH_EXPRESSION_LIST,
  AST_PIVOT_CLAUSE,
  AST_UNPIVOT_CLAUSE,
  AST_UNPIVOT_IN_ITEM_LABEL,
  AST_UNPIVOT_IN_ITEM,
  AST_UNPIVOT_IN_ITEM_LIST,
  AST_PIVOT_EXPRESSION,
  AST_PIVOT_EXPRESSION_LIST,
  AST_PIVOT_VALUE,
  AST_PIVOT_VALUE_LIST,
  AST_PRIMARY_KEY,
  AST_PRIMARY_KEY_COLUMN_ATTRIBUTE,
  AST_PRIVILEGE,
  AST_PRIVILEGES,
  AST_QUALIFY,
  AST_QUERY,
  AST_QUERY_STATEMENT,
  AST_RAISE_STATEMENT,
  AST_REMOVE_FROM_RESTRICTEE_LIST_CLAUSE,
  AST_RENAME_COLUMN_ACTION,
  AST_RENAME_TO_CLAUSE,
  AST_RENAME_STATEMENT,
  AST_REPEAT_STATEMENT,
  AST_REPEATABLE_CLAUSE,
  AST_REPLACE_FIELDS_ARG,
  AST_REPLACE_FIELDS_EXPRESSION,
  AST_RETURN_STATEMENT,
  AST_RETURNING_CLAUSE,
  AST_REVOKE_FROM_CLAUSE,
  AST_REVOKE_STATEMENT,
  AST_ROLLBACK_STATEMENT,
  AST_ROLLUP,
  AST_RUN_BATCH_STATEMENT,
  AST_SAMPLE_CLAUSE,
  AST_SAMPLE_SIZE,
  AST_SAMPLE_SUFFIX,
  AST_SCRIPT,
  AST_SELECT,
  AST_SELECT_AS,
  AST_SELECT_COLUMN,
  AST_SELECT_LIST,
  AST_SET_OPERATION,
  AST_SET_OPTIONS_ACTION,
  AST_SET_AS_ACTION,
  AST_SET_COLLATE_CLAUSE,
  AST_SET_TRANSACTION_STATEMENT,
  AST_SINGLE_ASSIGNMENT,
  AST_SHOW_STATEMENT,
  AST_SIMPLE_COLUMN_SCHEMA,
  AST_SIMPLE_TYPE,
  AST_SQL_FUNCTION_BODY,
  AST_STAR,
  AST_STAR_EXCEPT_LIST,
  AST_STAR_MODIFIERS,
  AST_STAR_REPLACE_ITEM,
  AST_STAR_WITH_MODIFIERS,
  AST_START_BATCH_STATEMENT,
  AST_STATEMENT_LIST,
  AST_STRING_LITERAL,
  AST_STRUCT_COLUMN_FIELD,
  AST_STRUCT_COLUMN_SCHEMA,
  AST_STRUCT_CONSTRUCTOR_ARG,
  AST_STRUCT_CONSTRUCTOR_WITH_KEYWORD,
  AST_STRUCT_CONSTRUCTOR_WITH_PARENS,
  AST_STRUCT_FIELD,
  AST_STRUCT_TYPE,
  AST_SYSTEM_VARIABLE_ASSIGNMENT,
  AST_SYSTEM_VARIABLE_EXPR,
  AST_TABLE_AND_COLUMN_INFO,
  AST_TABLE_AND_COLUMN_INFO_LIST,
  AST_TABLE_CLAUSE,
  AST_TABLE_ELEMENT_LIST,
  AST_TABLE_PATH_EXPRESSION,
  AST_TABLE_SUBQUERY,
  AST_TEMPLATED_PARAMETER_TYPE,
  AST_TRANSACTION_ISOLATION_LEVEL,
  AST_TRANSACTION_MODE_LIST,
  AST_TRANSACTION_READ_WRITE_MODE,
  AST_TRANSFORM_CLAUSE,
  AST_TRUNCATE_STATEMENT,
  AST_TVF,
  AST_TVF_ARGUMENT,
  AST_TVF_SCHEMA,
  AST_TVF_SCHEMA_COLUMN,
  AST_TYPE_PARAMETER_LIST,
  AST_UNARY_EXPRESSION,
  AST_UNNEST_EXPRESSION,
  AST_UNNEST_EXPRESSION_WITH_OPT_ALIAS_AND_OFFSET,
  AST_UNTIL_CLAUSE,
  AST_UPDATE_ITEM,
  AST_UPDATE_ITEM_LIST,
  AST_UPDATE_SET_VALUE,
  AST_UPDATE_STATEMENT,
  AST_USING_CLAUSE,
  AST_VARIABLE_DECLARATION,
  AST_WHEN_THEN_CLAUSE,
  AST_WHEN_THEN_CLAUSE_LIST,
  AST_WHERE_CLAUSE,
  AST_WHILE_STATEMENT,
  AST_WINDOW_CLAUSE,
  AST_WINDOW_DEFINITION,
  AST_WINDOW_FRAME,
  AST_WINDOW_FRAME_EXPR,
  AST_WINDOW_SPECIFICATION,
  AST_WITH_CLAUSE,
  AST_WITH_CLAUSE_ENTRY,
  AST_WITH_CONNECTION_CLAUSE,
  AST_WITH_GROUP_ROWS,
  AST_WITH_OFFSET,
  AST_WITH_PARTITION_COLUMNS_CLAUSE,
  AST_WITH_WEIGHT,
  kLastASTNodeKind = AST_WITH_WEIGHT
};

}  // namespace zetasql

#endif  // ZETASQL_PARSER_AST_NODE_KIND_H_
