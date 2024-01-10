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

#include "zetasql/parser/parse_tree_serializer.h"

// NOLINTBEGIN(whitespace/line_length)

namespace zetasql {

absl::Status ParseTreeSerializer::Serialize(const ASTNode* node,
                                            ASTNodeProto* proto) {
  ZETASQL_ASSIGN_OR_RETURN(*proto->mutable_parse_location_range(),
                   node->GetParseLocationRange().ToProto());
  return absl::OkStatus();
}

absl::StatusOr<std::unique_ptr<ParserOutput>> ParseTreeSerializer::Deserialize(
    const AnyASTStatementProto& proto, const ParserOptions& parser_options_in) {
  ParserOptions parser_options = parser_options_in;
  parser_options.CreateDefaultArenasIfNotSet();
  std::unique_ptr<ASTNode> ast_node;
  std::vector<std::unique_ptr<ASTNode>> allocated_ast_nodes;
  ZETASQL_ASSIGN_OR_RETURN(zetasql::ASTStatement* statement,
                   ParseTreeSerializer::Deserialize(
                       proto, parser_options.id_string_pool().get(),
                       parser_options.arena().get(), &allocated_ast_nodes));

  ZETASQL_RET_CHECK(statement != nullptr);
  for (int i = allocated_ast_nodes.size() - 1; i >= 0; --i) {
    (allocated_ast_nodes)[i]->InitFields();
    // Locate the target statement among the allocated_ast_nodes, move
    // its unique_ptr into *output.
    if ((allocated_ast_nodes)[i].get() == statement) {
      ast_node = std::move((allocated_ast_nodes)[i]);
    }
  }
  std::unique_ptr<ASTStatement> statement_ptr(
      ast_node.release()->GetAsOrDie<ASTStatement>());

  return absl::make_unique<ParserOutput>(
      parser_options.id_string_pool(), parser_options.arena(),
      std::move(allocated_ast_nodes), std::move(statement_ptr));
}

absl::Status ParseTreeSerializer::DeserializeAbstract(
    ASTNode* node, const ASTNodeProto& proto, IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_ASSIGN_OR_RETURN(ParseLocationRange parse_location_range,
                   ParseLocationRange::Create(proto.parse_location_range()));
  node->set_start_location(parse_location_range.start());
  node->set_end_location(parse_location_range.end());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStatement* node,
                                            ASTStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTStatement* node,
                                           AnyASTStatementProto* proto) {
  if (dynamic_cast<const ASTQueryStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTQueryStatement*>(node),
                              proto->mutable_ast_query_statement_node()));
  } else if (dynamic_cast<const ASTScriptStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTScriptStatement*>(node),
                              proto->mutable_ast_script_statement_node()));
  } else if (dynamic_cast<const ASTHintedStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTHintedStatement*>(node),
                              proto->mutable_ast_hinted_statement_node()));
  } else if (dynamic_cast<const ASTExplainStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTExplainStatement*>(node),
                              proto->mutable_ast_explain_statement_node()));
  } else if (dynamic_cast<const ASTDescribeStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDescribeStatement*>(node),
                              proto->mutable_ast_describe_statement_node()));
  } else if (dynamic_cast<const ASTShowStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTShowStatement*>(node),
                              proto->mutable_ast_show_statement_node()));
  } else if (dynamic_cast<const ASTBeginStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTBeginStatement*>(node),
                              proto->mutable_ast_begin_statement_node()));
  } else if (dynamic_cast<const ASTSetTransactionStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTSetTransactionStatement*>(node),
                              proto->mutable_ast_set_transaction_statement_node()));
  } else if (dynamic_cast<const ASTCommitStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCommitStatement*>(node),
                              proto->mutable_ast_commit_statement_node()));
  } else if (dynamic_cast<const ASTRollbackStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTRollbackStatement*>(node),
                              proto->mutable_ast_rollback_statement_node()));
  } else if (dynamic_cast<const ASTStartBatchStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTStartBatchStatement*>(node),
                              proto->mutable_ast_start_batch_statement_node()));
  } else if (dynamic_cast<const ASTRunBatchStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTRunBatchStatement*>(node),
                              proto->mutable_ast_run_batch_statement_node()));
  } else if (dynamic_cast<const ASTAbortBatchStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAbortBatchStatement*>(node),
                              proto->mutable_ast_abort_batch_statement_node()));
  } else if (dynamic_cast<const ASTDdlStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDdlStatement*>(node),
                              proto->mutable_ast_ddl_statement_node()));
  } else if (dynamic_cast<const ASTDropAllRowAccessPoliciesStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDropAllRowAccessPoliciesStatement*>(node),
                              proto->mutable_ast_drop_all_row_access_policies_statement_node()));
  } else if (dynamic_cast<const ASTRenameStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTRenameStatement*>(node),
                              proto->mutable_ast_rename_statement_node()));
  } else if (dynamic_cast<const ASTImportStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTImportStatement*>(node),
                              proto->mutable_ast_import_statement_node()));
  } else if (dynamic_cast<const ASTModuleStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTModuleStatement*>(node),
                              proto->mutable_ast_module_statement_node()));
  } else if (dynamic_cast<const ASTCloneDataStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCloneDataStatement*>(node),
                              proto->mutable_ast_clone_data_statement_node()));
  } else if (dynamic_cast<const ASTCreateDatabaseStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateDatabaseStatement*>(node),
                              proto->mutable_ast_create_database_statement_node()));
  } else if (dynamic_cast<const ASTExportDataStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTExportDataStatement*>(node),
                              proto->mutable_ast_export_data_statement_node()));
  } else if (dynamic_cast<const ASTExportModelStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTExportModelStatement*>(node),
                              proto->mutable_ast_export_model_statement_node()));
  } else if (dynamic_cast<const ASTCallStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCallStatement*>(node),
                              proto->mutable_ast_call_statement_node()));
  } else if (dynamic_cast<const ASTDefineTableStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDefineTableStatement*>(node),
                              proto->mutable_ast_define_table_statement_node()));
  } else if (dynamic_cast<const ASTAnalyzeStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAnalyzeStatement*>(node),
                              proto->mutable_ast_analyze_statement_node()));
  } else if (dynamic_cast<const ASTAssertStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAssertStatement*>(node),
                              proto->mutable_ast_assert_statement_node()));
  } else if (dynamic_cast<const ASTDeleteStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDeleteStatement*>(node),
                              proto->mutable_ast_delete_statement_node()));
  } else if (dynamic_cast<const ASTInsertStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTInsertStatement*>(node),
                              proto->mutable_ast_insert_statement_node()));
  } else if (dynamic_cast<const ASTUpdateStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTUpdateStatement*>(node),
                              proto->mutable_ast_update_statement_node()));
  } else if (dynamic_cast<const ASTTruncateStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTTruncateStatement*>(node),
                              proto->mutable_ast_truncate_statement_node()));
  } else if (dynamic_cast<const ASTMergeStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTMergeStatement*>(node),
                              proto->mutable_ast_merge_statement_node()));
  } else if (dynamic_cast<const ASTGrantStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTGrantStatement*>(node),
                              proto->mutable_ast_grant_statement_node()));
  } else if (dynamic_cast<const ASTRevokeStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTRevokeStatement*>(node),
                              proto->mutable_ast_revoke_statement_node()));
  } else if (dynamic_cast<const ASTAlterAllRowAccessPoliciesStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterAllRowAccessPoliciesStatement*>(node),
                              proto->mutable_ast_alter_all_row_access_policies_statement_node()));
  } else if (dynamic_cast<const ASTParameterAssignment*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTParameterAssignment*>(node),
                              proto->mutable_ast_parameter_assignment_node()));
  } else if (dynamic_cast<const ASTSystemVariableAssignment*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTSystemVariableAssignment*>(node),
                              proto->mutable_ast_system_variable_assignment_node()));
  } else if (dynamic_cast<const ASTExecuteImmediateStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTExecuteImmediateStatement*>(node),
                              proto->mutable_ast_execute_immediate_statement_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTStatement");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTStatement*> ParseTreeSerializer::Deserialize(
    const AnyASTStatementProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTStatementProto::kAstQueryStatementNode: {
      return Deserialize(
          proto.ast_query_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstScriptStatementNode: {
      return Deserialize(
          proto.ast_script_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstHintedStatementNode: {
      return Deserialize(
          proto.ast_hinted_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstExplainStatementNode: {
      return Deserialize(
          proto.ast_explain_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstDescribeStatementNode: {
      return Deserialize(
          proto.ast_describe_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstShowStatementNode: {
      return Deserialize(
          proto.ast_show_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstBeginStatementNode: {
      return Deserialize(
          proto.ast_begin_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstSetTransactionStatementNode: {
      return Deserialize(
          proto.ast_set_transaction_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstCommitStatementNode: {
      return Deserialize(
          proto.ast_commit_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstRollbackStatementNode: {
      return Deserialize(
          proto.ast_rollback_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstStartBatchStatementNode: {
      return Deserialize(
          proto.ast_start_batch_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstRunBatchStatementNode: {
      return Deserialize(
          proto.ast_run_batch_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstAbortBatchStatementNode: {
      return Deserialize(
          proto.ast_abort_batch_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstDdlStatementNode: {
      return Deserialize(
          proto.ast_ddl_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstDropAllRowAccessPoliciesStatementNode: {
      return Deserialize(
          proto.ast_drop_all_row_access_policies_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstRenameStatementNode: {
      return Deserialize(
          proto.ast_rename_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstImportStatementNode: {
      return Deserialize(
          proto.ast_import_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstModuleStatementNode: {
      return Deserialize(
          proto.ast_module_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstCloneDataStatementNode: {
      return Deserialize(
          proto.ast_clone_data_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstCreateDatabaseStatementNode: {
      return Deserialize(
          proto.ast_create_database_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstExportDataStatementNode: {
      return Deserialize(
          proto.ast_export_data_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstExportModelStatementNode: {
      return Deserialize(
          proto.ast_export_model_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstCallStatementNode: {
      return Deserialize(
          proto.ast_call_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstDefineTableStatementNode: {
      return Deserialize(
          proto.ast_define_table_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstAnalyzeStatementNode: {
      return Deserialize(
          proto.ast_analyze_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstAssertStatementNode: {
      return Deserialize(
          proto.ast_assert_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstDeleteStatementNode: {
      return Deserialize(
          proto.ast_delete_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstInsertStatementNode: {
      return Deserialize(
          proto.ast_insert_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstUpdateStatementNode: {
      return Deserialize(
          proto.ast_update_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstTruncateStatementNode: {
      return Deserialize(
          proto.ast_truncate_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstMergeStatementNode: {
      return Deserialize(
          proto.ast_merge_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstGrantStatementNode: {
      return Deserialize(
          proto.ast_grant_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstRevokeStatementNode: {
      return Deserialize(
          proto.ast_revoke_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstAlterAllRowAccessPoliciesStatementNode: {
      return Deserialize(
          proto.ast_alter_all_row_access_policies_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstParameterAssignmentNode: {
      return Deserialize(
          proto.ast_parameter_assignment_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstSystemVariableAssignmentNode: {
      return Deserialize(
          proto.ast_system_variable_assignment_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::kAstExecuteImmediateStatementNode: {
      return Deserialize(
          proto.ast_execute_immediate_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTStatementProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTStatement* node, const ASTStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStatement* node, const ASTStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTQueryStatement* node,
                                            ASTQueryStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->query_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->query_, proto->mutable_query()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTQueryStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTQueryStatementProto* ast_query_statement_proto =
      proto->mutable_ast_query_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_query_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTQueryStatement*> ParseTreeSerializer::Deserialize(
    const ASTQueryStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTQueryStatement* node = zetasql_base::NewInArena<ASTQueryStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTQueryStatement* node, const ASTQueryStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_query()) {
    node->AddChild(Deserialize(proto.query(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTQueryExpression* node,
                                            ASTQueryExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_parenthesized(node->parenthesized_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTQueryExpression* node,
                                           AnyASTQueryExpressionProto* proto) {
  if (dynamic_cast<const ASTQuery*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTQuery*>(node),
                              proto->mutable_ast_query_node()));
  } else if (dynamic_cast<const ASTSelect*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTSelect*>(node),
                              proto->mutable_ast_select_node()));
  } else if (dynamic_cast<const ASTSetOperation*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTSetOperation*>(node),
                              proto->mutable_ast_set_operation_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTQueryExpression");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTQueryExpression*> ParseTreeSerializer::Deserialize(
    const AnyASTQueryExpressionProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTQueryExpressionProto::kAstQueryNode: {
      return Deserialize(
          proto.ast_query_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTQueryExpressionProto::kAstSelectNode: {
      return Deserialize(
          proto.ast_select_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTQueryExpressionProto::kAstSetOperationNode: {
      return Deserialize(
          proto.ast_set_operation_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTQueryExpressionProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTQueryExpression* node, const ASTQueryExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTQueryExpression* node, const ASTQueryExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->parenthesized_ = proto.parenthesized();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTQuery* node,
                                            ASTQueryProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->with_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->with_clause_, proto->mutable_with_clause()));
  }
  if (node->query_expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->query_expr_, proto->mutable_query_expr()));
  }
  if (node->order_by_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->order_by_, proto->mutable_order_by()));
  }
  if (node->limit_offset_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->limit_offset_, proto->mutable_limit_offset()));
  }
  proto->set_is_nested(node->is_nested_);
  proto->set_is_pivot_input(node->is_pivot_input_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTQuery* node,
                                           AnyASTQueryExpressionProto* proto) {
  ASTQueryProto* ast_query_proto =
      proto->mutable_ast_query_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_query_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTQuery*> ParseTreeSerializer::Deserialize(
    const ASTQueryProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTQuery* node = zetasql_base::NewInArena<ASTQuery>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTQuery* node, const ASTQueryProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_with_clause()) {
    node->AddChild(Deserialize(proto.with_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_query_expr()) {
    node->AddChild(Deserialize(proto.query_expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_order_by()) {
    node->AddChild(Deserialize(proto.order_by(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_limit_offset()) {
    node->AddChild(Deserialize(proto.limit_offset(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_nested_ = proto.is_nested();
  node->is_pivot_input_ = proto.is_pivot_input();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSelect* node,
                                            ASTSelectProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->hint_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->hint_, proto->mutable_hint()));
  }
  if (node->anonymization_options_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->anonymization_options_, proto->mutable_anonymization_options()));
  }
  proto->set_distinct(node->distinct_);
  if (node->select_as_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->select_as_, proto->mutable_select_as()));
  }
  if (node->select_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->select_list_, proto->mutable_select_list()));
  }
  if (node->from_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->from_clause_, proto->mutable_from_clause()));
  }
  if (node->where_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->where_clause_, proto->mutable_where_clause()));
  }
  if (node->group_by_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->group_by_, proto->mutable_group_by()));
  }
  if (node->having_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->having_, proto->mutable_having()));
  }
  if (node->qualify_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->qualify_, proto->mutable_qualify()));
  }
  if (node->window_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->window_clause_, proto->mutable_window_clause()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTSelect* node,
                                           AnyASTQueryExpressionProto* proto) {
  ASTSelectProto* ast_select_proto =
      proto->mutable_ast_select_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_select_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTSelect*> ParseTreeSerializer::Deserialize(
    const ASTSelectProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSelect* node = zetasql_base::NewInArena<ASTSelect>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSelect* node, const ASTSelectProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_hint()) {
    node->AddChild(Deserialize(proto.hint(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_anonymization_options()) {
    node->AddChild(Deserialize(proto.anonymization_options(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->distinct_ = proto.distinct();
  if (proto.has_select_as()) {
    node->AddChild(Deserialize(proto.select_as(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_select_list()) {
    node->AddChild(Deserialize(proto.select_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_from_clause()) {
    node->AddChild(Deserialize(proto.from_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_where_clause()) {
    node->AddChild(Deserialize(proto.where_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_group_by()) {
    node->AddChild(Deserialize(proto.group_by(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_having()) {
    node->AddChild(Deserialize(proto.having(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_qualify()) {
    node->AddChild(Deserialize(proto.qualify(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_window_clause()) {
    node->AddChild(Deserialize(proto.window_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSelectList* node,
                                            ASTSelectListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->columns().length(); i++) {
    const ASTSelectColumn* columns_ = node->columns().at(i);
    ASTSelectColumnProto* proto2 = proto->add_columns();
    ZETASQL_RETURN_IF_ERROR(Serialize(columns_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTSelectList*> ParseTreeSerializer::Deserialize(
    const ASTSelectListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSelectList* node = zetasql_base::NewInArena<ASTSelectList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSelectList* node, const ASTSelectListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.columns_size(); i++) {
    node->AddChild(Deserialize(proto.columns(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSelectColumn* node,
                                            ASTSelectColumnProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTSelectColumn*> ParseTreeSerializer::Deserialize(
    const ASTSelectColumnProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSelectColumn* node = zetasql_base::NewInArena<ASTSelectColumn>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSelectColumn* node, const ASTSelectColumnProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTExpression* node,
                                            ASTExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_parenthesized(node->parenthesized_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTExpression* node,
                                           AnyASTExpressionProto* proto) {
  if (dynamic_cast<const ASTLeaf*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTLeaf*>(node),
                              proto->mutable_ast_leaf_node()));
  } else if (dynamic_cast<const ASTIdentifier*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTIdentifier*>(node),
                              proto->mutable_ast_identifier_node()));
  } else if (dynamic_cast<const ASTGeneralizedPathExpression*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTGeneralizedPathExpression*>(node),
                              proto->mutable_ast_generalized_path_expression_node()));
  } else if (dynamic_cast<const ASTAndExpr*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAndExpr*>(node),
                              proto->mutable_ast_and_expr_node()));
  } else if (dynamic_cast<const ASTBinaryExpression*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTBinaryExpression*>(node),
                              proto->mutable_ast_binary_expression_node()));
  } else if (dynamic_cast<const ASTOrExpr*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTOrExpr*>(node),
                              proto->mutable_ast_or_expr_node()));
  } else if (dynamic_cast<const ASTCastExpression*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCastExpression*>(node),
                              proto->mutable_ast_cast_expression_node()));
  } else if (dynamic_cast<const ASTFunctionCall*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTFunctionCall*>(node),
                              proto->mutable_ast_function_call_node()));
  } else if (dynamic_cast<const ASTArrayConstructor*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTArrayConstructor*>(node),
                              proto->mutable_ast_array_constructor_node()));
  } else if (dynamic_cast<const ASTStructConstructorWithParens*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTStructConstructorWithParens*>(node),
                              proto->mutable_ast_struct_constructor_with_parens_node()));
  } else if (dynamic_cast<const ASTStructConstructorWithKeyword*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTStructConstructorWithKeyword*>(node),
                              proto->mutable_ast_struct_constructor_with_keyword_node()));
  } else if (dynamic_cast<const ASTInExpression*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTInExpression*>(node),
                              proto->mutable_ast_in_expression_node()));
  } else if (dynamic_cast<const ASTBetweenExpression*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTBetweenExpression*>(node),
                              proto->mutable_ast_between_expression_node()));
  } else if (dynamic_cast<const ASTDateOrTimeLiteral*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDateOrTimeLiteral*>(node),
                              proto->mutable_ast_date_or_time_literal_node()));
  } else if (dynamic_cast<const ASTCaseValueExpression*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCaseValueExpression*>(node),
                              proto->mutable_ast_case_value_expression_node()));
  } else if (dynamic_cast<const ASTCaseNoValueExpression*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCaseNoValueExpression*>(node),
                              proto->mutable_ast_case_no_value_expression_node()));
  } else if (dynamic_cast<const ASTBitwiseShiftExpression*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTBitwiseShiftExpression*>(node),
                              proto->mutable_ast_bitwise_shift_expression_node()));
  } else if (dynamic_cast<const ASTDotStar*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDotStar*>(node),
                              proto->mutable_ast_dot_star_node()));
  } else if (dynamic_cast<const ASTDotStarWithModifiers*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDotStarWithModifiers*>(node),
                              proto->mutable_ast_dot_star_with_modifiers_node()));
  } else if (dynamic_cast<const ASTExpressionSubquery*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTExpressionSubquery*>(node),
                              proto->mutable_ast_expression_subquery_node()));
  } else if (dynamic_cast<const ASTExtractExpression*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTExtractExpression*>(node),
                              proto->mutable_ast_extract_expression_node()));
  } else if (dynamic_cast<const ASTIntervalExpr*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTIntervalExpr*>(node),
                              proto->mutable_ast_interval_expr_node()));
  } else if (dynamic_cast<const ASTNamedArgument*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTNamedArgument*>(node),
                              proto->mutable_ast_named_argument_node()));
  } else if (dynamic_cast<const ASTStarWithModifiers*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTStarWithModifiers*>(node),
                              proto->mutable_ast_star_with_modifiers_node()));
  } else if (dynamic_cast<const ASTUnaryExpression*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTUnaryExpression*>(node),
                              proto->mutable_ast_unary_expression_node()));
  } else if (dynamic_cast<const ASTLikeExpression*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTLikeExpression*>(node),
                              proto->mutable_ast_like_expression_node()));
  } else if (dynamic_cast<const ASTParameterExprBase*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTParameterExprBase*>(node),
                              proto->mutable_ast_parameter_expr_base_node()));
  } else if (dynamic_cast<const ASTLambda*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTLambda*>(node),
                              proto->mutable_ast_lambda_node()));
  } else if (dynamic_cast<const ASTAnalyticFunctionCall*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAnalyticFunctionCall*>(node),
                              proto->mutable_ast_analytic_function_call_node()));
  } else if (dynamic_cast<const ASTFunctionCallWithGroupRows*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTFunctionCallWithGroupRows*>(node),
                              proto->mutable_ast_function_call_with_group_rows_node()));
  } else if (dynamic_cast<const ASTNewConstructor*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTNewConstructor*>(node),
                              proto->mutable_ast_new_constructor_node()));
  } else if (dynamic_cast<const ASTDefaultLiteral*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDefaultLiteral*>(node),
                              proto->mutable_ast_default_literal_node()));
  } else if (dynamic_cast<const ASTReplaceFieldsExpression*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTReplaceFieldsExpression*>(node),
                              proto->mutable_ast_replace_fields_expression_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTExpression");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTExpression*> ParseTreeSerializer::Deserialize(
    const AnyASTExpressionProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTExpressionProto::kAstLeafNode: {
      return Deserialize(
          proto.ast_leaf_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstIdentifierNode: {
      return Deserialize(
          proto.ast_identifier_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstGeneralizedPathExpressionNode: {
      return Deserialize(
          proto.ast_generalized_path_expression_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstAndExprNode: {
      return Deserialize(
          proto.ast_and_expr_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstBinaryExpressionNode: {
      return Deserialize(
          proto.ast_binary_expression_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstOrExprNode: {
      return Deserialize(
          proto.ast_or_expr_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstCastExpressionNode: {
      return Deserialize(
          proto.ast_cast_expression_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstFunctionCallNode: {
      return Deserialize(
          proto.ast_function_call_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstArrayConstructorNode: {
      return Deserialize(
          proto.ast_array_constructor_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstStructConstructorWithParensNode: {
      return Deserialize(
          proto.ast_struct_constructor_with_parens_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstStructConstructorWithKeywordNode: {
      return Deserialize(
          proto.ast_struct_constructor_with_keyword_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstInExpressionNode: {
      return Deserialize(
          proto.ast_in_expression_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstBetweenExpressionNode: {
      return Deserialize(
          proto.ast_between_expression_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstDateOrTimeLiteralNode: {
      return Deserialize(
          proto.ast_date_or_time_literal_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstCaseValueExpressionNode: {
      return Deserialize(
          proto.ast_case_value_expression_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstCaseNoValueExpressionNode: {
      return Deserialize(
          proto.ast_case_no_value_expression_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstBitwiseShiftExpressionNode: {
      return Deserialize(
          proto.ast_bitwise_shift_expression_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstDotStarNode: {
      return Deserialize(
          proto.ast_dot_star_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstDotStarWithModifiersNode: {
      return Deserialize(
          proto.ast_dot_star_with_modifiers_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstExpressionSubqueryNode: {
      return Deserialize(
          proto.ast_expression_subquery_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstExtractExpressionNode: {
      return Deserialize(
          proto.ast_extract_expression_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstIntervalExprNode: {
      return Deserialize(
          proto.ast_interval_expr_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstNamedArgumentNode: {
      return Deserialize(
          proto.ast_named_argument_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstStarWithModifiersNode: {
      return Deserialize(
          proto.ast_star_with_modifiers_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstUnaryExpressionNode: {
      return Deserialize(
          proto.ast_unary_expression_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstLikeExpressionNode: {
      return Deserialize(
          proto.ast_like_expression_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstParameterExprBaseNode: {
      return Deserialize(
          proto.ast_parameter_expr_base_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstLambdaNode: {
      return Deserialize(
          proto.ast_lambda_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstAnalyticFunctionCallNode: {
      return Deserialize(
          proto.ast_analytic_function_call_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstFunctionCallWithGroupRowsNode: {
      return Deserialize(
          proto.ast_function_call_with_group_rows_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstNewConstructorNode: {
      return Deserialize(
          proto.ast_new_constructor_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstDefaultLiteralNode: {
      return Deserialize(
          proto.ast_default_literal_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::kAstReplaceFieldsExpressionNode: {
      return Deserialize(
          proto.ast_replace_fields_expression_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTExpressionProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTExpression* node, const ASTExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTExpression* node, const ASTExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->parenthesized_ = proto.parenthesized();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTLeaf* node,
                                            ASTLeafProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_image(node->image_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTLeaf* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTLeafProto* ast_leaf_proto =
      proto->mutable_ast_leaf_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_leaf_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTLeaf* node,
                                           AnyASTLeafProto* proto) {
  if (dynamic_cast<const ASTIntLiteral*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTIntLiteral*>(node),
                              proto->mutable_ast_int_literal_node()));
  } else if (dynamic_cast<const ASTBooleanLiteral*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTBooleanLiteral*>(node),
                              proto->mutable_ast_boolean_literal_node()));
  } else if (dynamic_cast<const ASTStringLiteral*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTStringLiteral*>(node),
                              proto->mutable_ast_string_literal_node()));
  } else if (dynamic_cast<const ASTStar*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTStar*>(node),
                              proto->mutable_ast_star_node()));
  } else if (dynamic_cast<const ASTFloatLiteral*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTFloatLiteral*>(node),
                              proto->mutable_ast_float_literal_node()));
  } else if (dynamic_cast<const ASTNullLiteral*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTNullLiteral*>(node),
                              proto->mutable_ast_null_literal_node()));
  } else if (dynamic_cast<const ASTNumericLiteral*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTNumericLiteral*>(node),
                              proto->mutable_ast_numeric_literal_node()));
  } else if (dynamic_cast<const ASTBigNumericLiteral*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTBigNumericLiteral*>(node),
                              proto->mutable_ast_bignumeric_literal_node()));
  } else if (dynamic_cast<const ASTBytesLiteral*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTBytesLiteral*>(node),
                              proto->mutable_ast_bytes_literal_node()));
  } else if (dynamic_cast<const ASTMaxLiteral*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTMaxLiteral*>(node),
                              proto->mutable_ast_max_literal_node()));
  } else if (dynamic_cast<const ASTJSONLiteral*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTJSONLiteral*>(node),
                              proto->mutable_ast_json_literal_node()));
  } else if (dynamic_cast<const ASTIndexAllColumns*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTIndexAllColumns*>(node),
                              proto->mutable_ast_index_all_columns_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTLeaf");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTLeaf*> ParseTreeSerializer::Deserialize(
    const AnyASTLeafProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTLeafProto::kAstIntLiteralNode: {
      return Deserialize(
          proto.ast_int_literal_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTLeafProto::kAstBooleanLiteralNode: {
      return Deserialize(
          proto.ast_boolean_literal_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTLeafProto::kAstStringLiteralNode: {
      return Deserialize(
          proto.ast_string_literal_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTLeafProto::kAstStarNode: {
      return Deserialize(
          proto.ast_star_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTLeafProto::kAstFloatLiteralNode: {
      return Deserialize(
          proto.ast_float_literal_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTLeafProto::kAstNullLiteralNode: {
      return Deserialize(
          proto.ast_null_literal_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTLeafProto::kAstNumericLiteralNode: {
      return Deserialize(
          proto.ast_numeric_literal_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTLeafProto::kAstBignumericLiteralNode: {
      return Deserialize(
          proto.ast_bignumeric_literal_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTLeafProto::kAstBytesLiteralNode: {
      return Deserialize(
          proto.ast_bytes_literal_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTLeafProto::kAstMaxLiteralNode: {
      return Deserialize(
          proto.ast_max_literal_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTLeafProto::kAstJsonLiteralNode: {
      return Deserialize(
          proto.ast_json_literal_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTLeafProto::kAstIndexAllColumnsNode: {
      return Deserialize(
          proto.ast_index_all_columns_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTLeafProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTLeaf* node, const ASTLeafProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTLeaf* node, const ASTLeafProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->image_ = proto.image();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTIntLiteral* node,
                                            ASTIntLiteralProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTIntLiteral* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTLeafProto* ast_leaf_proto =
      proto->mutable_ast_leaf_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_leaf_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTIntLiteral* node,
                                           AnyASTLeafProto* proto) {
  ASTIntLiteralProto* ast_int_literal_proto =
      proto->mutable_ast_int_literal_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_int_literal_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTIntLiteral*> ParseTreeSerializer::Deserialize(
    const ASTIntLiteralProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTIntLiteral* node = zetasql_base::NewInArena<ASTIntLiteral>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTIntLiteral* node, const ASTIntLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTIdentifier* node,
                                            ASTIdentifierProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_id_string(node->id_string_.ToString());
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTIdentifier* node,
                                           AnyASTExpressionProto* proto) {
  ASTIdentifierProto* ast_identifier_proto =
      proto->mutable_ast_identifier_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_identifier_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTIdentifier*> ParseTreeSerializer::Deserialize(
    const ASTIdentifierProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTIdentifier* node = zetasql_base::NewInArena<ASTIdentifier>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTIdentifier* node, const ASTIdentifierProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->id_string_ = id_string_pool->Make(proto.id_string());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlias* node,
                                            ASTAliasProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->identifier_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->identifier_, proto->mutable_identifier()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTAlias*> ParseTreeSerializer::Deserialize(
    const ASTAliasProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlias* node = zetasql_base::NewInArena<ASTAlias>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlias* node, const ASTAliasProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_identifier()) {
    node->AddChild(Deserialize(proto.identifier(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTGeneralizedPathExpression* node,
                                            ASTGeneralizedPathExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTGeneralizedPathExpression* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTGeneralizedPathExpressionProto* ast_generalized_path_expression_proto =
      proto->mutable_ast_generalized_path_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_generalized_path_expression_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTGeneralizedPathExpression* node,
                                           AnyASTGeneralizedPathExpressionProto* proto) {
  if (dynamic_cast<const ASTPathExpression*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTPathExpression*>(node),
                              proto->mutable_ast_path_expression_node()));
  } else if (dynamic_cast<const ASTArrayElement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTArrayElement*>(node),
                              proto->mutable_ast_array_element_node()));
  } else if (dynamic_cast<const ASTDotGeneralizedField*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDotGeneralizedField*>(node),
                              proto->mutable_ast_dot_generalized_field_node()));
  } else if (dynamic_cast<const ASTDotIdentifier*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDotIdentifier*>(node),
                              proto->mutable_ast_dot_identifier_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTGeneralizedPathExpression");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTGeneralizedPathExpression*> ParseTreeSerializer::Deserialize(
    const AnyASTGeneralizedPathExpressionProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTGeneralizedPathExpressionProto::kAstPathExpressionNode: {
      return Deserialize(
          proto.ast_path_expression_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTGeneralizedPathExpressionProto::kAstArrayElementNode: {
      return Deserialize(
          proto.ast_array_element_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTGeneralizedPathExpressionProto::kAstDotGeneralizedFieldNode: {
      return Deserialize(
          proto.ast_dot_generalized_field_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTGeneralizedPathExpressionProto::kAstDotIdentifierNode: {
      return Deserialize(
          proto.ast_dot_identifier_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTGeneralizedPathExpressionProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTGeneralizedPathExpression* node, const ASTGeneralizedPathExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTGeneralizedPathExpression* node, const ASTGeneralizedPathExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTPathExpression* node,
                                            ASTPathExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->names().length(); i++) {
    const ASTIdentifier* names_ = node->names().at(i);
    ASTIdentifierProto* proto2 = proto->add_names();
    ZETASQL_RETURN_IF_ERROR(Serialize(names_, proto2));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTPathExpression* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTGeneralizedPathExpressionProto* ast_generalized_path_expression_proto =
      proto->mutable_ast_generalized_path_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_generalized_path_expression_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTPathExpression* node,
                                           AnyASTGeneralizedPathExpressionProto* proto) {
  ASTPathExpressionProto* ast_path_expression_proto =
      proto->mutable_ast_path_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_path_expression_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTPathExpression*> ParseTreeSerializer::Deserialize(
    const ASTPathExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTPathExpression* node = zetasql_base::NewInArena<ASTPathExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTPathExpression* node, const ASTPathExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.names_size(); i++) {
    node->AddChild(Deserialize(proto.names(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTableExpression* node,
                                            ASTTableExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTTableExpression* node,
                                           AnyASTTableExpressionProto* proto) {
  if (dynamic_cast<const ASTTablePathExpression*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTTablePathExpression*>(node),
                              proto->mutable_ast_table_path_expression_node()));
  } else if (dynamic_cast<const ASTJoin*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTJoin*>(node),
                              proto->mutable_ast_join_node()));
  } else if (dynamic_cast<const ASTParenthesizedJoin*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTParenthesizedJoin*>(node),
                              proto->mutable_ast_parenthesized_join_node()));
  } else if (dynamic_cast<const ASTTableSubquery*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTTableSubquery*>(node),
                              proto->mutable_ast_table_subquery_node()));
  } else if (dynamic_cast<const ASTTVF*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTTVF*>(node),
                              proto->mutable_ast_tvf_node()));
  } else if (dynamic_cast<const ASTTableDataSource*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTTableDataSource*>(node),
                              proto->mutable_ast_table_data_source_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTTableExpression");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTTableExpression*> ParseTreeSerializer::Deserialize(
    const AnyASTTableExpressionProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTTableExpressionProto::kAstTablePathExpressionNode: {
      return Deserialize(
          proto.ast_table_path_expression_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTableExpressionProto::kAstJoinNode: {
      return Deserialize(
          proto.ast_join_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTableExpressionProto::kAstParenthesizedJoinNode: {
      return Deserialize(
          proto.ast_parenthesized_join_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTableExpressionProto::kAstTableSubqueryNode: {
      return Deserialize(
          proto.ast_table_subquery_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTableExpressionProto::kAstTvfNode: {
      return Deserialize(
          proto.ast_tvf_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTableExpressionProto::kAstTableDataSourceNode: {
      return Deserialize(
          proto.ast_table_data_source_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTableExpressionProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTTableExpression* node, const ASTTableExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTableExpression* node, const ASTTableExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTablePathExpression* node,
                                            ASTTablePathExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->path_expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->path_expr_, proto->mutable_path_expr()));
  }
  if (node->unnest_expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->unnest_expr_, proto->mutable_unnest_expr()));
  }
  if (node->hint_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->hint_, proto->mutable_hint()));
  }
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  if (node->with_offset_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->with_offset_, proto->mutable_with_offset()));
  }
  if (node->pivot_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->pivot_clause_, proto->mutable_pivot_clause()));
  }
  if (node->unpivot_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->unpivot_clause_, proto->mutable_unpivot_clause()));
  }
  if (node->for_system_time_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->for_system_time_, proto->mutable_for_system_time()));
  }
  if (node->sample_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->sample_clause_, proto->mutable_sample_clause()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTTablePathExpression* node,
                                           AnyASTTableExpressionProto* proto) {
  ASTTablePathExpressionProto* ast_table_path_expression_proto =
      proto->mutable_ast_table_path_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_table_path_expression_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTTablePathExpression*> ParseTreeSerializer::Deserialize(
    const ASTTablePathExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTablePathExpression* node = zetasql_base::NewInArena<ASTTablePathExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTablePathExpression* node, const ASTTablePathExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_path_expr()) {
    node->AddChild(Deserialize(proto.path_expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_unnest_expr()) {
    node->AddChild(Deserialize(proto.unnest_expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_hint()) {
    node->AddChild(Deserialize(proto.hint(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_with_offset()) {
    node->AddChild(Deserialize(proto.with_offset(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_pivot_clause()) {
    node->AddChild(Deserialize(proto.pivot_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_unpivot_clause()) {
    node->AddChild(Deserialize(proto.unpivot_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_for_system_time()) {
    node->AddChild(Deserialize(proto.for_system_time(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_sample_clause()) {
    node->AddChild(Deserialize(proto.sample_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTFromClause* node,
                                            ASTFromClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->table_expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->table_expression_, proto->mutable_table_expression()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTFromClause*> ParseTreeSerializer::Deserialize(
    const ASTFromClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTFromClause* node = zetasql_base::NewInArena<ASTFromClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTFromClause* node, const ASTFromClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_table_expression()) {
    node->AddChild(Deserialize(proto.table_expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWhereClause* node,
                                            ASTWhereClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTWhereClause*> ParseTreeSerializer::Deserialize(
    const ASTWhereClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWhereClause* node = zetasql_base::NewInArena<ASTWhereClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWhereClause* node, const ASTWhereClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTBooleanLiteral* node,
                                            ASTBooleanLiteralProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_value(node->value_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBooleanLiteral* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTLeafProto* ast_leaf_proto =
      proto->mutable_ast_leaf_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_leaf_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBooleanLiteral* node,
                                           AnyASTLeafProto* proto) {
  ASTBooleanLiteralProto* ast_boolean_literal_proto =
      proto->mutable_ast_boolean_literal_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_boolean_literal_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTBooleanLiteral*> ParseTreeSerializer::Deserialize(
    const ASTBooleanLiteralProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTBooleanLiteral* node = zetasql_base::NewInArena<ASTBooleanLiteral>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTBooleanLiteral* node, const ASTBooleanLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->value_ = proto.value();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAndExpr* node,
                                            ASTAndExprProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->conjuncts().length(); i++) {
    const ASTExpression* conjuncts_ = node->conjuncts().at(i);
    AnyASTExpressionProto* proto2 = proto->add_conjuncts();
    ZETASQL_RETURN_IF_ERROR(Serialize(conjuncts_, proto2));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAndExpr* node,
                                           AnyASTExpressionProto* proto) {
  ASTAndExprProto* ast_and_expr_proto =
      proto->mutable_ast_and_expr_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_and_expr_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAndExpr*> ParseTreeSerializer::Deserialize(
    const ASTAndExprProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAndExpr* node = zetasql_base::NewInArena<ASTAndExpr>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAndExpr* node, const ASTAndExprProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.conjuncts_size(); i++) {
    node->AddChild(Deserialize(proto.conjuncts(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTBinaryExpression* node,
                                            ASTBinaryExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_op(static_cast<ASTBinaryExpressionEnums_Op>(node->op_));
  proto->set_is_not(node->is_not_);
  if (node->lhs_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->lhs_, proto->mutable_lhs()));
  }
  if (node->rhs_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->rhs_, proto->mutable_rhs()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBinaryExpression* node,
                                           AnyASTExpressionProto* proto) {
  ASTBinaryExpressionProto* ast_binary_expression_proto =
      proto->mutable_ast_binary_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_binary_expression_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTBinaryExpression*> ParseTreeSerializer::Deserialize(
    const ASTBinaryExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTBinaryExpression* node = zetasql_base::NewInArena<ASTBinaryExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTBinaryExpression* node, const ASTBinaryExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->op_ = static_cast<ASTBinaryExpression::Op>(proto.op());
  node->is_not_ = proto.is_not();
  if (proto.has_lhs()) {
    node->AddChild(Deserialize(proto.lhs(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_rhs()) {
    node->AddChild(Deserialize(proto.rhs(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStringLiteral* node,
                                            ASTStringLiteralProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_string_value(node->string_value_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTStringLiteral* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTLeafProto* ast_leaf_proto =
      proto->mutable_ast_leaf_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_leaf_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTStringLiteral* node,
                                           AnyASTLeafProto* proto) {
  ASTStringLiteralProto* ast_string_literal_proto =
      proto->mutable_ast_string_literal_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_string_literal_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTStringLiteral*> ParseTreeSerializer::Deserialize(
    const ASTStringLiteralProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTStringLiteral* node = zetasql_base::NewInArena<ASTStringLiteral>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStringLiteral* node, const ASTStringLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->string_value_ = proto.string_value();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStar* node,
                                            ASTStarProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTStar* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTLeafProto* ast_leaf_proto =
      proto->mutable_ast_leaf_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_leaf_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTStar* node,
                                           AnyASTLeafProto* proto) {
  ASTStarProto* ast_star_proto =
      proto->mutable_ast_star_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_star_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTStar*> ParseTreeSerializer::Deserialize(
    const ASTStarProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTStar* node = zetasql_base::NewInArena<ASTStar>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStar* node, const ASTStarProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTOrExpr* node,
                                            ASTOrExprProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->disjuncts().length(); i++) {
    const ASTExpression* disjuncts_ = node->disjuncts().at(i);
    AnyASTExpressionProto* proto2 = proto->add_disjuncts();
    ZETASQL_RETURN_IF_ERROR(Serialize(disjuncts_, proto2));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTOrExpr* node,
                                           AnyASTExpressionProto* proto) {
  ASTOrExprProto* ast_or_expr_proto =
      proto->mutable_ast_or_expr_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_or_expr_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTOrExpr*> ParseTreeSerializer::Deserialize(
    const ASTOrExprProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTOrExpr* node = zetasql_base::NewInArena<ASTOrExpr>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTOrExpr* node, const ASTOrExprProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.disjuncts_size(); i++) {
    node->AddChild(Deserialize(proto.disjuncts(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTGroupingItem* node,
                                            ASTGroupingItemProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  if (node->rollup_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->rollup_, proto->mutable_rollup()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTGroupingItem*> ParseTreeSerializer::Deserialize(
    const ASTGroupingItemProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTGroupingItem* node = zetasql_base::NewInArena<ASTGroupingItem>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTGroupingItem* node, const ASTGroupingItemProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_rollup()) {
    node->AddChild(Deserialize(proto.rollup(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTGroupBy* node,
                                            ASTGroupByProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->hint_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->hint_, proto->mutable_hint()));
  }
  for (int i = 0; i < node->grouping_items().length(); i++) {
    const ASTGroupingItem* grouping_items_ = node->grouping_items().at(i);
    ASTGroupingItemProto* proto2 = proto->add_grouping_items();
    ZETASQL_RETURN_IF_ERROR(Serialize(grouping_items_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTGroupBy*> ParseTreeSerializer::Deserialize(
    const ASTGroupByProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTGroupBy* node = zetasql_base::NewInArena<ASTGroupBy>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTGroupBy* node, const ASTGroupByProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_hint()) {
    node->AddChild(Deserialize(proto.hint(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  for (int i=0; i < proto.grouping_items_size(); i++) {
    node->AddChild(Deserialize(proto.grouping_items(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTOrderingExpression* node,
                                            ASTOrderingExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  if (node->collate_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->collate_, proto->mutable_collate()));
  }
  if (node->null_order_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->null_order_, proto->mutable_null_order()));
  }
  proto->set_ordering_spec(static_cast<ASTOrderingExpressionEnums_OrderingSpec>(node->ordering_spec_));
  return absl::OkStatus();
}
absl::StatusOr<ASTOrderingExpression*> ParseTreeSerializer::Deserialize(
    const ASTOrderingExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTOrderingExpression* node = zetasql_base::NewInArena<ASTOrderingExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTOrderingExpression* node, const ASTOrderingExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_collate()) {
    node->AddChild(Deserialize(proto.collate(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_null_order()) {
    node->AddChild(Deserialize(proto.null_order(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->ordering_spec_ = static_cast<ASTOrderingExpression::OrderingSpec>(proto.ordering_spec());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTOrderBy* node,
                                            ASTOrderByProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->hint_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->hint_, proto->mutable_hint()));
  }
  for (int i = 0; i < node->ordering_expressions().length(); i++) {
    const ASTOrderingExpression* ordering_expressions_ = node->ordering_expressions().at(i);
    ASTOrderingExpressionProto* proto2 = proto->add_ordering_expressions();
    ZETASQL_RETURN_IF_ERROR(Serialize(ordering_expressions_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTOrderBy*> ParseTreeSerializer::Deserialize(
    const ASTOrderByProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTOrderBy* node = zetasql_base::NewInArena<ASTOrderBy>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTOrderBy* node, const ASTOrderByProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_hint()) {
    node->AddChild(Deserialize(proto.hint(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  for (int i=0; i < proto.ordering_expressions_size(); i++) {
    node->AddChild(Deserialize(proto.ordering_expressions(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTLimitOffset* node,
                                            ASTLimitOffsetProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->limit_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->limit_, proto->mutable_limit()));
  }
  if (node->offset_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->offset_, proto->mutable_offset()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTLimitOffset*> ParseTreeSerializer::Deserialize(
    const ASTLimitOffsetProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTLimitOffset* node = zetasql_base::NewInArena<ASTLimitOffset>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTLimitOffset* node, const ASTLimitOffsetProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_limit()) {
    node->AddChild(Deserialize(proto.limit(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_offset()) {
    node->AddChild(Deserialize(proto.offset(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTFloatLiteral* node,
                                            ASTFloatLiteralProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTFloatLiteral* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTLeafProto* ast_leaf_proto =
      proto->mutable_ast_leaf_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_leaf_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTFloatLiteral* node,
                                           AnyASTLeafProto* proto) {
  ASTFloatLiteralProto* ast_float_literal_proto =
      proto->mutable_ast_float_literal_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_float_literal_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTFloatLiteral*> ParseTreeSerializer::Deserialize(
    const ASTFloatLiteralProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTFloatLiteral* node = zetasql_base::NewInArena<ASTFloatLiteral>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTFloatLiteral* node, const ASTFloatLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTNullLiteral* node,
                                            ASTNullLiteralProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTNullLiteral* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTLeafProto* ast_leaf_proto =
      proto->mutable_ast_leaf_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_leaf_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTNullLiteral* node,
                                           AnyASTLeafProto* proto) {
  ASTNullLiteralProto* ast_null_literal_proto =
      proto->mutable_ast_null_literal_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_null_literal_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTNullLiteral*> ParseTreeSerializer::Deserialize(
    const ASTNullLiteralProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTNullLiteral* node = zetasql_base::NewInArena<ASTNullLiteral>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTNullLiteral* node, const ASTNullLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTOnClause* node,
                                            ASTOnClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTOnClause*> ParseTreeSerializer::Deserialize(
    const ASTOnClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTOnClause* node = zetasql_base::NewInArena<ASTOnClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTOnClause* node, const ASTOnClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWithClauseEntry* node,
                                            ASTWithClauseEntryProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  if (node->query_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->query_, proto->mutable_query()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTWithClauseEntry*> ParseTreeSerializer::Deserialize(
    const ASTWithClauseEntryProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWithClauseEntry* node = zetasql_base::NewInArena<ASTWithClauseEntry>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWithClauseEntry* node, const ASTWithClauseEntryProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_query()) {
    node->AddChild(Deserialize(proto.query(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTJoin* node,
                                            ASTJoinProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->lhs_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->lhs_, proto->mutable_lhs()));
  }
  if (node->hint_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->hint_, proto->mutable_hint()));
  }
  if (node->rhs_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->rhs_, proto->mutable_rhs()));
  }
  if (node->on_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->on_clause_, proto->mutable_on_clause()));
  }
  if (node->using_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->using_clause_, proto->mutable_using_clause()));
  }
  if (node->clause_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->clause_list_, proto->mutable_clause_list()));
  }
  proto->set_join_type(static_cast<ASTJoinEnums_JoinType>(node->join_type_));
  proto->set_join_hint(static_cast<ASTJoinEnums_JoinHint>(node->join_hint_));
  proto->set_natural(node->natural_);
  proto->set_unmatched_join_count(node->unmatched_join_count_);
  proto->set_transformation_needed(node->transformation_needed_);
  proto->set_contains_comma_join(node->contains_comma_join_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTJoin* node,
                                           AnyASTTableExpressionProto* proto) {
  ASTJoinProto* ast_join_proto =
      proto->mutable_ast_join_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_join_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTJoin*> ParseTreeSerializer::Deserialize(
    const ASTJoinProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTJoin* node = zetasql_base::NewInArena<ASTJoin>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTJoin* node, const ASTJoinProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_lhs()) {
    node->AddChild(Deserialize(proto.lhs(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_hint()) {
    node->AddChild(Deserialize(proto.hint(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_rhs()) {
    node->AddChild(Deserialize(proto.rhs(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_on_clause()) {
    node->AddChild(Deserialize(proto.on_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_using_clause()) {
    node->AddChild(Deserialize(proto.using_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_clause_list()) {
    node->AddChild(Deserialize(proto.clause_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->join_type_ = static_cast<ASTJoin::JoinType>(proto.join_type());
  node->join_hint_ = static_cast<ASTJoin::JoinHint>(proto.join_hint());
  node->natural_ = proto.natural();
  node->unmatched_join_count_ = proto.unmatched_join_count();
  node->transformation_needed_ = proto.transformation_needed();
  node->contains_comma_join_ = proto.contains_comma_join();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWithClause* node,
                                            ASTWithClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->with().length(); i++) {
    const ASTWithClauseEntry* with_ = node->with().at(i);
    ASTWithClauseEntryProto* proto2 = proto->add_with();
    ZETASQL_RETURN_IF_ERROR(Serialize(with_, proto2));
  }
  proto->set_recursive(node->recursive_);
  return absl::OkStatus();
}
absl::StatusOr<ASTWithClause*> ParseTreeSerializer::Deserialize(
    const ASTWithClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWithClause* node = zetasql_base::NewInArena<ASTWithClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWithClause* node, const ASTWithClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.with_size(); i++) {
    node->AddChild(Deserialize(proto.with(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  node->recursive_ = proto.recursive();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTHaving* node,
                                            ASTHavingProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTHaving*> ParseTreeSerializer::Deserialize(
    const ASTHavingProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTHaving* node = zetasql_base::NewInArena<ASTHaving>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTHaving* node, const ASTHavingProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTType* node,
                                            ASTTypeProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTType* node,
                                           AnyASTTypeProto* proto) {
  if (dynamic_cast<const ASTSimpleType*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTSimpleType*>(node),
                              proto->mutable_ast_simple_type_node()));
  } else if (dynamic_cast<const ASTArrayType*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTArrayType*>(node),
                              proto->mutable_ast_array_type_node()));
  } else if (dynamic_cast<const ASTStructType*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTStructType*>(node),
                              proto->mutable_ast_struct_type_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTType");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTType*> ParseTreeSerializer::Deserialize(
    const AnyASTTypeProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTTypeProto::kAstSimpleTypeNode: {
      return Deserialize(
          proto.ast_simple_type_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTypeProto::kAstArrayTypeNode: {
      return Deserialize(
          proto.ast_array_type_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTypeProto::kAstStructTypeNode: {
      return Deserialize(
          proto.ast_struct_type_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTypeProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTType* node, const ASTTypeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTType* node, const ASTTypeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSimpleType* node,
                                            ASTSimpleTypeProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->type_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_name_, proto->mutable_type_name()));
  }
  if (node->type_parameters_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_parameters_, proto->mutable_type_parameters()));
  }
  if (node->collate_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->collate_, proto->mutable_collate()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTSimpleType* node,
                                           AnyASTTypeProto* proto) {
  ASTSimpleTypeProto* ast_simple_type_proto =
      proto->mutable_ast_simple_type_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_simple_type_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTSimpleType*> ParseTreeSerializer::Deserialize(
    const ASTSimpleTypeProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSimpleType* node = zetasql_base::NewInArena<ASTSimpleType>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSimpleType* node, const ASTSimpleTypeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_type_name()) {
    node->AddChild(Deserialize(proto.type_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_type_parameters()) {
    node->AddChild(Deserialize(proto.type_parameters(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_collate()) {
    node->AddChild(Deserialize(proto.collate(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTArrayType* node,
                                            ASTArrayTypeProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->element_type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->element_type_, proto->mutable_element_type()));
  }
  if (node->type_parameters_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_parameters_, proto->mutable_type_parameters()));
  }
  if (node->collate_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->collate_, proto->mutable_collate()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTArrayType* node,
                                           AnyASTTypeProto* proto) {
  ASTArrayTypeProto* ast_array_type_proto =
      proto->mutable_ast_array_type_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_array_type_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTArrayType*> ParseTreeSerializer::Deserialize(
    const ASTArrayTypeProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTArrayType* node = zetasql_base::NewInArena<ASTArrayType>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTArrayType* node, const ASTArrayTypeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_element_type()) {
    node->AddChild(Deserialize(proto.element_type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_type_parameters()) {
    node->AddChild(Deserialize(proto.type_parameters(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_collate()) {
    node->AddChild(Deserialize(proto.collate(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStructField* node,
                                            ASTStructFieldProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_, proto->mutable_type()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTStructField*> ParseTreeSerializer::Deserialize(
    const ASTStructFieldProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTStructField* node = zetasql_base::NewInArena<ASTStructField>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStructField* node, const ASTStructFieldProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_type()) {
    node->AddChild(Deserialize(proto.type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStructType* node,
                                            ASTStructTypeProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->struct_fields().length(); i++) {
    const ASTStructField* struct_fields_ = node->struct_fields().at(i);
    ASTStructFieldProto* proto2 = proto->add_struct_fields();
    ZETASQL_RETURN_IF_ERROR(Serialize(struct_fields_, proto2));
  }
  if (node->type_parameters_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_parameters_, proto->mutable_type_parameters()));
  }
  if (node->collate_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->collate_, proto->mutable_collate()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTStructType* node,
                                           AnyASTTypeProto* proto) {
  ASTStructTypeProto* ast_struct_type_proto =
      proto->mutable_ast_struct_type_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_struct_type_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTStructType*> ParseTreeSerializer::Deserialize(
    const ASTStructTypeProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTStructType* node = zetasql_base::NewInArena<ASTStructType>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStructType* node, const ASTStructTypeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.struct_fields_size(); i++) {
    node->AddChild(Deserialize(proto.struct_fields(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  if (proto.has_type_parameters()) {
    node->AddChild(Deserialize(proto.type_parameters(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_collate()) {
    node->AddChild(Deserialize(proto.collate(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCastExpression* node,
                                            ASTCastExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expr_, proto->mutable_expr()));
  }
  if (node->type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_, proto->mutable_type()));
  }
  if (node->format_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->format_, proto->mutable_format()));
  }
  proto->set_is_safe_cast(node->is_safe_cast_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCastExpression* node,
                                           AnyASTExpressionProto* proto) {
  ASTCastExpressionProto* ast_cast_expression_proto =
      proto->mutable_ast_cast_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_cast_expression_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCastExpression*> ParseTreeSerializer::Deserialize(
    const ASTCastExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCastExpression* node = zetasql_base::NewInArena<ASTCastExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCastExpression* node, const ASTCastExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expr()) {
    node->AddChild(Deserialize(proto.expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_type()) {
    node->AddChild(Deserialize(proto.type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_format()) {
    node->AddChild(Deserialize(proto.format(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_safe_cast_ = proto.is_safe_cast();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSelectAs* node,
                                            ASTSelectAsProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->type_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_name_, proto->mutable_type_name()));
  }
  proto->set_as_mode(static_cast<ASTSelectAsEnums_AsMode>(node->as_mode_));
  return absl::OkStatus();
}
absl::StatusOr<ASTSelectAs*> ParseTreeSerializer::Deserialize(
    const ASTSelectAsProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSelectAs* node = zetasql_base::NewInArena<ASTSelectAs>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSelectAs* node, const ASTSelectAsProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_type_name()) {
    node->AddChild(Deserialize(proto.type_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->as_mode_ = static_cast<ASTSelectAs::AsMode>(proto.as_mode());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTRollup* node,
                                            ASTRollupProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->expressions().length(); i++) {
    const ASTExpression* expressions_ = node->expressions().at(i);
    AnyASTExpressionProto* proto2 = proto->add_expressions();
    ZETASQL_RETURN_IF_ERROR(Serialize(expressions_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTRollup*> ParseTreeSerializer::Deserialize(
    const ASTRollupProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTRollup* node = zetasql_base::NewInArena<ASTRollup>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTRollup* node, const ASTRollupProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.expressions_size(); i++) {
    node->AddChild(Deserialize(proto.expressions(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTFunctionCall* node,
                                            ASTFunctionCallProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->function_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->function_, proto->mutable_function()));
  }
  for (int i = 0; i < node->arguments().length(); i++) {
    const ASTExpression* arguments_ = node->arguments().at(i);
    AnyASTExpressionProto* proto2 = proto->add_arguments();
    ZETASQL_RETURN_IF_ERROR(Serialize(arguments_, proto2));
  }
  if (node->having_modifier_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->having_modifier_, proto->mutable_having_modifier()));
  }
  if (node->clamped_between_modifier_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->clamped_between_modifier_, proto->mutable_clamped_between_modifier()));
  }
  if (node->order_by_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->order_by_, proto->mutable_order_by()));
  }
  if (node->limit_offset_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->limit_offset_, proto->mutable_limit_offset()));
  }
  if (node->hint_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->hint_, proto->mutable_hint()));
  }
  if (node->with_group_rows_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->with_group_rows_, proto->mutable_with_group_rows()));
  }
  proto->set_null_handling_modifier(static_cast<ASTFunctionCallEnums_NullHandlingModifier>(node->null_handling_modifier_));
  proto->set_distinct(node->distinct_);
  proto->set_is_current_date_time_without_parentheses(node->is_current_date_time_without_parentheses_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTFunctionCall* node,
                                           AnyASTExpressionProto* proto) {
  ASTFunctionCallProto* ast_function_call_proto =
      proto->mutable_ast_function_call_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_function_call_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTFunctionCall*> ParseTreeSerializer::Deserialize(
    const ASTFunctionCallProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTFunctionCall* node = zetasql_base::NewInArena<ASTFunctionCall>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTFunctionCall* node, const ASTFunctionCallProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_function()) {
    node->AddChild(Deserialize(proto.function(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  for (int i=0; i < proto.arguments_size(); i++) {
    node->AddChild(Deserialize(proto.arguments(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  if (proto.has_having_modifier()) {
    node->AddChild(Deserialize(proto.having_modifier(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_clamped_between_modifier()) {
    node->AddChild(Deserialize(proto.clamped_between_modifier(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_order_by()) {
    node->AddChild(Deserialize(proto.order_by(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_limit_offset()) {
    node->AddChild(Deserialize(proto.limit_offset(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_hint()) {
    node->AddChild(Deserialize(proto.hint(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_with_group_rows()) {
    node->AddChild(Deserialize(proto.with_group_rows(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->null_handling_modifier_ = static_cast<ASTFunctionCall::NullHandlingModifier>(proto.null_handling_modifier());
  node->distinct_ = proto.distinct();
  node->is_current_date_time_without_parentheses_ = proto.is_current_date_time_without_parentheses();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTArrayConstructor* node,
                                            ASTArrayConstructorProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_, proto->mutable_type()));
  }
  for (int i = 0; i < node->elements().length(); i++) {
    const ASTExpression* elements_ = node->elements().at(i);
    AnyASTExpressionProto* proto2 = proto->add_elements();
    ZETASQL_RETURN_IF_ERROR(Serialize(elements_, proto2));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTArrayConstructor* node,
                                           AnyASTExpressionProto* proto) {
  ASTArrayConstructorProto* ast_array_constructor_proto =
      proto->mutable_ast_array_constructor_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_array_constructor_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTArrayConstructor*> ParseTreeSerializer::Deserialize(
    const ASTArrayConstructorProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTArrayConstructor* node = zetasql_base::NewInArena<ASTArrayConstructor>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTArrayConstructor* node, const ASTArrayConstructorProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_type()) {
    node->AddChild(Deserialize(proto.type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  for (int i=0; i < proto.elements_size(); i++) {
    node->AddChild(Deserialize(proto.elements(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStructConstructorArg* node,
                                            ASTStructConstructorArgProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTStructConstructorArg*> ParseTreeSerializer::Deserialize(
    const ASTStructConstructorArgProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTStructConstructorArg* node = zetasql_base::NewInArena<ASTStructConstructorArg>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStructConstructorArg* node, const ASTStructConstructorArgProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStructConstructorWithParens* node,
                                            ASTStructConstructorWithParensProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->field_expressions().length(); i++) {
    const ASTExpression* field_expressions_ = node->field_expressions().at(i);
    AnyASTExpressionProto* proto2 = proto->add_field_expressions();
    ZETASQL_RETURN_IF_ERROR(Serialize(field_expressions_, proto2));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTStructConstructorWithParens* node,
                                           AnyASTExpressionProto* proto) {
  ASTStructConstructorWithParensProto* ast_struct_constructor_with_parens_proto =
      proto->mutable_ast_struct_constructor_with_parens_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_struct_constructor_with_parens_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTStructConstructorWithParens*> ParseTreeSerializer::Deserialize(
    const ASTStructConstructorWithParensProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTStructConstructorWithParens* node = zetasql_base::NewInArena<ASTStructConstructorWithParens>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStructConstructorWithParens* node, const ASTStructConstructorWithParensProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.field_expressions_size(); i++) {
    node->AddChild(Deserialize(proto.field_expressions(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStructConstructorWithKeyword* node,
                                            ASTStructConstructorWithKeywordProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->struct_type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->struct_type_, proto->mutable_struct_type()));
  }
  for (int i = 0; i < node->fields().length(); i++) {
    const ASTStructConstructorArg* fields_ = node->fields().at(i);
    ASTStructConstructorArgProto* proto2 = proto->add_fields();
    ZETASQL_RETURN_IF_ERROR(Serialize(fields_, proto2));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTStructConstructorWithKeyword* node,
                                           AnyASTExpressionProto* proto) {
  ASTStructConstructorWithKeywordProto* ast_struct_constructor_with_keyword_proto =
      proto->mutable_ast_struct_constructor_with_keyword_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_struct_constructor_with_keyword_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTStructConstructorWithKeyword*> ParseTreeSerializer::Deserialize(
    const ASTStructConstructorWithKeywordProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTStructConstructorWithKeyword* node = zetasql_base::NewInArena<ASTStructConstructorWithKeyword>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStructConstructorWithKeyword* node, const ASTStructConstructorWithKeywordProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_struct_type()) {
    node->AddChild(Deserialize(proto.struct_type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  for (int i=0; i < proto.fields_size(); i++) {
    node->AddChild(Deserialize(proto.fields(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTInExpression* node,
                                            ASTInExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->lhs_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->lhs_, proto->mutable_lhs()));
  }
  if (node->hint_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->hint_, proto->mutable_hint()));
  }
  if (node->in_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->in_list_, proto->mutable_in_list()));
  }
  if (node->query_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->query_, proto->mutable_query()));
  }
  if (node->unnest_expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->unnest_expr_, proto->mutable_unnest_expr()));
  }
  proto->set_is_not(node->is_not_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTInExpression* node,
                                           AnyASTExpressionProto* proto) {
  ASTInExpressionProto* ast_in_expression_proto =
      proto->mutable_ast_in_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_in_expression_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTInExpression*> ParseTreeSerializer::Deserialize(
    const ASTInExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTInExpression* node = zetasql_base::NewInArena<ASTInExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTInExpression* node, const ASTInExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_lhs()) {
    node->AddChild(Deserialize(proto.lhs(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_hint()) {
    node->AddChild(Deserialize(proto.hint(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_in_list()) {
    node->AddChild(Deserialize(proto.in_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_query()) {
    node->AddChild(Deserialize(proto.query(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_unnest_expr()) {
    node->AddChild(Deserialize(proto.unnest_expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_not_ = proto.is_not();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTInList* node,
                                            ASTInListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->list().length(); i++) {
    const ASTExpression* list_ = node->list().at(i);
    AnyASTExpressionProto* proto2 = proto->add_list();
    ZETASQL_RETURN_IF_ERROR(Serialize(list_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTInList*> ParseTreeSerializer::Deserialize(
    const ASTInListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTInList* node = zetasql_base::NewInArena<ASTInList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTInList* node, const ASTInListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.list_size(); i++) {
    node->AddChild(Deserialize(proto.list(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTBetweenExpression* node,
                                            ASTBetweenExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->lhs_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->lhs_, proto->mutable_lhs()));
  }
  if (node->low_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->low_, proto->mutable_low()));
  }
  if (node->high_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->high_, proto->mutable_high()));
  }
  proto->set_is_not(node->is_not_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBetweenExpression* node,
                                           AnyASTExpressionProto* proto) {
  ASTBetweenExpressionProto* ast_between_expression_proto =
      proto->mutable_ast_between_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_between_expression_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTBetweenExpression*> ParseTreeSerializer::Deserialize(
    const ASTBetweenExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTBetweenExpression* node = zetasql_base::NewInArena<ASTBetweenExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTBetweenExpression* node, const ASTBetweenExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_lhs()) {
    node->AddChild(Deserialize(proto.lhs(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_low()) {
    node->AddChild(Deserialize(proto.low(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_high()) {
    node->AddChild(Deserialize(proto.high(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_not_ = proto.is_not();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTNumericLiteral* node,
                                            ASTNumericLiteralProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTNumericLiteral* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTLeafProto* ast_leaf_proto =
      proto->mutable_ast_leaf_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_leaf_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTNumericLiteral* node,
                                           AnyASTLeafProto* proto) {
  ASTNumericLiteralProto* ast_numeric_literal_proto =
      proto->mutable_ast_numeric_literal_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_numeric_literal_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTNumericLiteral*> ParseTreeSerializer::Deserialize(
    const ASTNumericLiteralProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTNumericLiteral* node = zetasql_base::NewInArena<ASTNumericLiteral>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTNumericLiteral* node, const ASTNumericLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTBigNumericLiteral* node,
                                            ASTBigNumericLiteralProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBigNumericLiteral* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTLeafProto* ast_leaf_proto =
      proto->mutable_ast_leaf_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_leaf_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBigNumericLiteral* node,
                                           AnyASTLeafProto* proto) {
  ASTBigNumericLiteralProto* ast_bignumeric_literal_proto =
      proto->mutable_ast_bignumeric_literal_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_bignumeric_literal_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTBigNumericLiteral*> ParseTreeSerializer::Deserialize(
    const ASTBigNumericLiteralProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTBigNumericLiteral* node = zetasql_base::NewInArena<ASTBigNumericLiteral>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTBigNumericLiteral* node, const ASTBigNumericLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTBytesLiteral* node,
                                            ASTBytesLiteralProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBytesLiteral* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTLeafProto* ast_leaf_proto =
      proto->mutable_ast_leaf_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_leaf_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBytesLiteral* node,
                                           AnyASTLeafProto* proto) {
  ASTBytesLiteralProto* ast_bytes_literal_proto =
      proto->mutable_ast_bytes_literal_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_bytes_literal_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTBytesLiteral*> ParseTreeSerializer::Deserialize(
    const ASTBytesLiteralProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTBytesLiteral* node = zetasql_base::NewInArena<ASTBytesLiteral>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTBytesLiteral* node, const ASTBytesLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDateOrTimeLiteral* node,
                                            ASTDateOrTimeLiteralProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->string_literal_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->string_literal_, proto->mutable_string_literal()));
  }
  proto->set_type_kind(node->type_kind_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDateOrTimeLiteral* node,
                                           AnyASTExpressionProto* proto) {
  ASTDateOrTimeLiteralProto* ast_date_or_time_literal_proto =
      proto->mutable_ast_date_or_time_literal_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_date_or_time_literal_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDateOrTimeLiteral*> ParseTreeSerializer::Deserialize(
    const ASTDateOrTimeLiteralProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDateOrTimeLiteral* node = zetasql_base::NewInArena<ASTDateOrTimeLiteral>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDateOrTimeLiteral* node, const ASTDateOrTimeLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_string_literal()) {
    node->AddChild(Deserialize(proto.string_literal(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->type_kind_ = proto.type_kind();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTMaxLiteral* node,
                                            ASTMaxLiteralProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTMaxLiteral* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTLeafProto* ast_leaf_proto =
      proto->mutable_ast_leaf_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_leaf_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTMaxLiteral* node,
                                           AnyASTLeafProto* proto) {
  ASTMaxLiteralProto* ast_max_literal_proto =
      proto->mutable_ast_max_literal_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_max_literal_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTMaxLiteral*> ParseTreeSerializer::Deserialize(
    const ASTMaxLiteralProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTMaxLiteral* node = zetasql_base::NewInArena<ASTMaxLiteral>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTMaxLiteral* node, const ASTMaxLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTJSONLiteral* node,
                                            ASTJSONLiteralProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTJSONLiteral* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTLeafProto* ast_leaf_proto =
      proto->mutable_ast_leaf_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_leaf_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTJSONLiteral* node,
                                           AnyASTLeafProto* proto) {
  ASTJSONLiteralProto* ast_json_literal_proto =
      proto->mutable_ast_json_literal_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_json_literal_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTJSONLiteral*> ParseTreeSerializer::Deserialize(
    const ASTJSONLiteralProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTJSONLiteral* node = zetasql_base::NewInArena<ASTJSONLiteral>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTJSONLiteral* node, const ASTJSONLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCaseValueExpression* node,
                                            ASTCaseValueExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->arguments().length(); i++) {
    const ASTExpression* arguments_ = node->arguments().at(i);
    AnyASTExpressionProto* proto2 = proto->add_arguments();
    ZETASQL_RETURN_IF_ERROR(Serialize(arguments_, proto2));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCaseValueExpression* node,
                                           AnyASTExpressionProto* proto) {
  ASTCaseValueExpressionProto* ast_case_value_expression_proto =
      proto->mutable_ast_case_value_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_case_value_expression_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCaseValueExpression*> ParseTreeSerializer::Deserialize(
    const ASTCaseValueExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCaseValueExpression* node = zetasql_base::NewInArena<ASTCaseValueExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCaseValueExpression* node, const ASTCaseValueExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.arguments_size(); i++) {
    node->AddChild(Deserialize(proto.arguments(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCaseNoValueExpression* node,
                                            ASTCaseNoValueExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->arguments().length(); i++) {
    const ASTExpression* arguments_ = node->arguments().at(i);
    AnyASTExpressionProto* proto2 = proto->add_arguments();
    ZETASQL_RETURN_IF_ERROR(Serialize(arguments_, proto2));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCaseNoValueExpression* node,
                                           AnyASTExpressionProto* proto) {
  ASTCaseNoValueExpressionProto* ast_case_no_value_expression_proto =
      proto->mutable_ast_case_no_value_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_case_no_value_expression_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCaseNoValueExpression*> ParseTreeSerializer::Deserialize(
    const ASTCaseNoValueExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCaseNoValueExpression* node = zetasql_base::NewInArena<ASTCaseNoValueExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCaseNoValueExpression* node, const ASTCaseNoValueExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.arguments_size(); i++) {
    node->AddChild(Deserialize(proto.arguments(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTArrayElement* node,
                                            ASTArrayElementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->array_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->array_, proto->mutable_array()));
  }
  if (node->position_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->position_, proto->mutable_position()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTArrayElement* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTGeneralizedPathExpressionProto* ast_generalized_path_expression_proto =
      proto->mutable_ast_generalized_path_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_generalized_path_expression_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTArrayElement* node,
                                           AnyASTGeneralizedPathExpressionProto* proto) {
  ASTArrayElementProto* ast_array_element_proto =
      proto->mutable_ast_array_element_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_array_element_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTArrayElement*> ParseTreeSerializer::Deserialize(
    const ASTArrayElementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTArrayElement* node = zetasql_base::NewInArena<ASTArrayElement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTArrayElement* node, const ASTArrayElementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_array()) {
    node->AddChild(Deserialize(proto.array(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_position()) {
    node->AddChild(Deserialize(proto.position(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTBitwiseShiftExpression* node,
                                            ASTBitwiseShiftExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->lhs_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->lhs_, proto->mutable_lhs()));
  }
  if (node->rhs_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->rhs_, proto->mutable_rhs()));
  }
  proto->set_is_left_shift(node->is_left_shift_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBitwiseShiftExpression* node,
                                           AnyASTExpressionProto* proto) {
  ASTBitwiseShiftExpressionProto* ast_bitwise_shift_expression_proto =
      proto->mutable_ast_bitwise_shift_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_bitwise_shift_expression_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTBitwiseShiftExpression*> ParseTreeSerializer::Deserialize(
    const ASTBitwiseShiftExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTBitwiseShiftExpression* node = zetasql_base::NewInArena<ASTBitwiseShiftExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTBitwiseShiftExpression* node, const ASTBitwiseShiftExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_lhs()) {
    node->AddChild(Deserialize(proto.lhs(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_rhs()) {
    node->AddChild(Deserialize(proto.rhs(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_left_shift_ = proto.is_left_shift();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCollate* node,
                                            ASTCollateProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->collation_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->collation_name_, proto->mutable_collation_name()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTCollate*> ParseTreeSerializer::Deserialize(
    const ASTCollateProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCollate* node = zetasql_base::NewInArena<ASTCollate>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCollate* node, const ASTCollateProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_collation_name()) {
    node->AddChild(Deserialize(proto.collation_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDotGeneralizedField* node,
                                            ASTDotGeneralizedFieldProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expr_, proto->mutable_expr()));
  }
  if (node->path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->path_, proto->mutable_path()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDotGeneralizedField* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTGeneralizedPathExpressionProto* ast_generalized_path_expression_proto =
      proto->mutable_ast_generalized_path_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_generalized_path_expression_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDotGeneralizedField* node,
                                           AnyASTGeneralizedPathExpressionProto* proto) {
  ASTDotGeneralizedFieldProto* ast_dot_generalized_field_proto =
      proto->mutable_ast_dot_generalized_field_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_dot_generalized_field_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDotGeneralizedField*> ParseTreeSerializer::Deserialize(
    const ASTDotGeneralizedFieldProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDotGeneralizedField* node = zetasql_base::NewInArena<ASTDotGeneralizedField>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDotGeneralizedField* node, const ASTDotGeneralizedFieldProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expr()) {
    node->AddChild(Deserialize(proto.expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_path()) {
    node->AddChild(Deserialize(proto.path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDotIdentifier* node,
                                            ASTDotIdentifierProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expr_, proto->mutable_expr()));
  }
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDotIdentifier* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTGeneralizedPathExpressionProto* ast_generalized_path_expression_proto =
      proto->mutable_ast_generalized_path_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_generalized_path_expression_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDotIdentifier* node,
                                           AnyASTGeneralizedPathExpressionProto* proto) {
  ASTDotIdentifierProto* ast_dot_identifier_proto =
      proto->mutable_ast_dot_identifier_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_dot_identifier_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDotIdentifier*> ParseTreeSerializer::Deserialize(
    const ASTDotIdentifierProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDotIdentifier* node = zetasql_base::NewInArena<ASTDotIdentifier>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDotIdentifier* node, const ASTDotIdentifierProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expr()) {
    node->AddChild(Deserialize(proto.expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDotStar* node,
                                            ASTDotStarProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expr_, proto->mutable_expr()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDotStar* node,
                                           AnyASTExpressionProto* proto) {
  ASTDotStarProto* ast_dot_star_proto =
      proto->mutable_ast_dot_star_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_dot_star_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDotStar*> ParseTreeSerializer::Deserialize(
    const ASTDotStarProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDotStar* node = zetasql_base::NewInArena<ASTDotStar>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDotStar* node, const ASTDotStarProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expr()) {
    node->AddChild(Deserialize(proto.expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDotStarWithModifiers* node,
                                            ASTDotStarWithModifiersProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expr_, proto->mutable_expr()));
  }
  if (node->modifiers_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->modifiers_, proto->mutable_modifiers()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDotStarWithModifiers* node,
                                           AnyASTExpressionProto* proto) {
  ASTDotStarWithModifiersProto* ast_dot_star_with_modifiers_proto =
      proto->mutable_ast_dot_star_with_modifiers_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_dot_star_with_modifiers_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDotStarWithModifiers*> ParseTreeSerializer::Deserialize(
    const ASTDotStarWithModifiersProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDotStarWithModifiers* node = zetasql_base::NewInArena<ASTDotStarWithModifiers>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDotStarWithModifiers* node, const ASTDotStarWithModifiersProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expr()) {
    node->AddChild(Deserialize(proto.expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_modifiers()) {
    node->AddChild(Deserialize(proto.modifiers(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTExpressionSubquery* node,
                                            ASTExpressionSubqueryProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->hint_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->hint_, proto->mutable_hint()));
  }
  if (node->query_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->query_, proto->mutable_query()));
  }
  proto->set_modifier(static_cast<ASTExpressionSubqueryEnums_Modifier>(node->modifier_));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTExpressionSubquery* node,
                                           AnyASTExpressionProto* proto) {
  ASTExpressionSubqueryProto* ast_expression_subquery_proto =
      proto->mutable_ast_expression_subquery_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_expression_subquery_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTExpressionSubquery*> ParseTreeSerializer::Deserialize(
    const ASTExpressionSubqueryProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTExpressionSubquery* node = zetasql_base::NewInArena<ASTExpressionSubquery>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTExpressionSubquery* node, const ASTExpressionSubqueryProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_hint()) {
    node->AddChild(Deserialize(proto.hint(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_query()) {
    node->AddChild(Deserialize(proto.query(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->modifier_ = static_cast<ASTExpressionSubquery::Modifier>(proto.modifier());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTExtractExpression* node,
                                            ASTExtractExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->lhs_expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->lhs_expr_, proto->mutable_lhs_expr()));
  }
  if (node->rhs_expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->rhs_expr_, proto->mutable_rhs_expr()));
  }
  if (node->time_zone_expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->time_zone_expr_, proto->mutable_time_zone_expr()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTExtractExpression* node,
                                           AnyASTExpressionProto* proto) {
  ASTExtractExpressionProto* ast_extract_expression_proto =
      proto->mutable_ast_extract_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_extract_expression_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTExtractExpression*> ParseTreeSerializer::Deserialize(
    const ASTExtractExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTExtractExpression* node = zetasql_base::NewInArena<ASTExtractExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTExtractExpression* node, const ASTExtractExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_lhs_expr()) {
    node->AddChild(Deserialize(proto.lhs_expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_rhs_expr()) {
    node->AddChild(Deserialize(proto.rhs_expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_time_zone_expr()) {
    node->AddChild(Deserialize(proto.time_zone_expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTHavingModifier* node,
                                            ASTHavingModifierProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expr_, proto->mutable_expr()));
  }
  proto->set_modifier_kind(static_cast<ASTHavingModifierEnums_ModifierKind>(node->modifier_kind_));
  return absl::OkStatus();
}
absl::StatusOr<ASTHavingModifier*> ParseTreeSerializer::Deserialize(
    const ASTHavingModifierProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTHavingModifier* node = zetasql_base::NewInArena<ASTHavingModifier>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTHavingModifier* node, const ASTHavingModifierProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expr()) {
    node->AddChild(Deserialize(proto.expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->modifier_kind_ = static_cast<ASTHavingModifier::ModifierKind>(proto.modifier_kind());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTIntervalExpr* node,
                                            ASTIntervalExprProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->interval_value_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->interval_value_, proto->mutable_interval_value()));
  }
  if (node->date_part_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->date_part_name_, proto->mutable_date_part_name()));
  }
  if (node->date_part_name_to_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->date_part_name_to_, proto->mutable_date_part_name_to()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTIntervalExpr* node,
                                           AnyASTExpressionProto* proto) {
  ASTIntervalExprProto* ast_interval_expr_proto =
      proto->mutable_ast_interval_expr_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_interval_expr_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTIntervalExpr*> ParseTreeSerializer::Deserialize(
    const ASTIntervalExprProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTIntervalExpr* node = zetasql_base::NewInArena<ASTIntervalExpr>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTIntervalExpr* node, const ASTIntervalExprProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_interval_value()) {
    node->AddChild(Deserialize(proto.interval_value(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_date_part_name()) {
    node->AddChild(Deserialize(proto.date_part_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_date_part_name_to()) {
    node->AddChild(Deserialize(proto.date_part_name_to(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTNamedArgument* node,
                                            ASTNamedArgumentProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expr_, proto->mutable_expr()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTNamedArgument* node,
                                           AnyASTExpressionProto* proto) {
  ASTNamedArgumentProto* ast_named_argument_proto =
      proto->mutable_ast_named_argument_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_named_argument_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTNamedArgument*> ParseTreeSerializer::Deserialize(
    const ASTNamedArgumentProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTNamedArgument* node = zetasql_base::NewInArena<ASTNamedArgument>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTNamedArgument* node, const ASTNamedArgumentProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_expr()) {
    node->AddChild(Deserialize(proto.expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTNullOrder* node,
                                            ASTNullOrderProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_nulls_first(node->nulls_first_);
  return absl::OkStatus();
}
absl::StatusOr<ASTNullOrder*> ParseTreeSerializer::Deserialize(
    const ASTNullOrderProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTNullOrder* node = zetasql_base::NewInArena<ASTNullOrder>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTNullOrder* node, const ASTNullOrderProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->nulls_first_ = proto.nulls_first();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTOnOrUsingClauseList* node,
                                            ASTOnOrUsingClauseListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->on_or_using_clause_list().length(); i++) {
    const ASTNode* on_or_using_clause_list_ = node->on_or_using_clause_list().at(i);
    ASTNodeProto* proto2 = proto->add_on_or_using_clause_list();
    ZETASQL_RETURN_IF_ERROR(Serialize(on_or_using_clause_list_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTOnOrUsingClauseList*> ParseTreeSerializer::Deserialize(
    const ASTOnOrUsingClauseListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTOnOrUsingClauseList* node = zetasql_base::NewInArena<ASTOnOrUsingClauseList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTOnOrUsingClauseList* node, const ASTOnOrUsingClauseListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::UnimplementedError("Fields of type ASTNode are not supported");
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTParenthesizedJoin* node,
                                            ASTParenthesizedJoinProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->join_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->join_, proto->mutable_join()));
  }
  if (node->sample_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->sample_clause_, proto->mutable_sample_clause()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTParenthesizedJoin* node,
                                           AnyASTTableExpressionProto* proto) {
  ASTParenthesizedJoinProto* ast_parenthesized_join_proto =
      proto->mutable_ast_parenthesized_join_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_parenthesized_join_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTParenthesizedJoin*> ParseTreeSerializer::Deserialize(
    const ASTParenthesizedJoinProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTParenthesizedJoin* node = zetasql_base::NewInArena<ASTParenthesizedJoin>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTParenthesizedJoin* node, const ASTParenthesizedJoinProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_join()) {
    node->AddChild(Deserialize(proto.join(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_sample_clause()) {
    node->AddChild(Deserialize(proto.sample_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTPartitionBy* node,
                                            ASTPartitionByProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->hint_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->hint_, proto->mutable_hint()));
  }
  for (int i = 0; i < node->partitioning_expressions().length(); i++) {
    const ASTExpression* partitioning_expressions_ = node->partitioning_expressions().at(i);
    AnyASTExpressionProto* proto2 = proto->add_partitioning_expressions();
    ZETASQL_RETURN_IF_ERROR(Serialize(partitioning_expressions_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTPartitionBy*> ParseTreeSerializer::Deserialize(
    const ASTPartitionByProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTPartitionBy* node = zetasql_base::NewInArena<ASTPartitionBy>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTPartitionBy* node, const ASTPartitionByProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_hint()) {
    node->AddChild(Deserialize(proto.hint(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  for (int i=0; i < proto.partitioning_expressions_size(); i++) {
    node->AddChild(Deserialize(proto.partitioning_expressions(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSetOperation* node,
                                            ASTSetOperationProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->hint_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->hint_, proto->mutable_hint()));
  }
  for (int i = 0; i < node->inputs().length(); i++) {
    const ASTQueryExpression* inputs_ = node->inputs().at(i);
    AnyASTQueryExpressionProto* proto2 = proto->add_inputs();
    ZETASQL_RETURN_IF_ERROR(Serialize(inputs_, proto2));
  }
  proto->set_op_type(static_cast<ASTSetOperationEnums_OperationType>(node->op_type_));
  proto->set_distinct(node->distinct_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTSetOperation* node,
                                           AnyASTQueryExpressionProto* proto) {
  ASTSetOperationProto* ast_set_operation_proto =
      proto->mutable_ast_set_operation_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_set_operation_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTSetOperation*> ParseTreeSerializer::Deserialize(
    const ASTSetOperationProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSetOperation* node = zetasql_base::NewInArena<ASTSetOperation>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSetOperation* node, const ASTSetOperationProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_hint()) {
    node->AddChild(Deserialize(proto.hint(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  for (int i=0; i < proto.inputs_size(); i++) {
    node->AddChild(Deserialize(proto.inputs(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  node->op_type_ = static_cast<ASTSetOperation::OperationType>(proto.op_type());
  node->distinct_ = proto.distinct();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStarExceptList* node,
                                            ASTStarExceptListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->identifiers().length(); i++) {
    const ASTIdentifier* identifiers_ = node->identifiers().at(i);
    ASTIdentifierProto* proto2 = proto->add_identifiers();
    ZETASQL_RETURN_IF_ERROR(Serialize(identifiers_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTStarExceptList*> ParseTreeSerializer::Deserialize(
    const ASTStarExceptListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTStarExceptList* node = zetasql_base::NewInArena<ASTStarExceptList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStarExceptList* node, const ASTStarExceptListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.identifiers_size(); i++) {
    node->AddChild(Deserialize(proto.identifiers(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStarModifiers* node,
                                            ASTStarModifiersProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->except_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->except_list_, proto->mutable_except_list()));
  }
  for (int i = 0; i < node->replace_items().length(); i++) {
    const ASTStarReplaceItem* replace_items_ = node->replace_items().at(i);
    ASTStarReplaceItemProto* proto2 = proto->add_replace_items();
    ZETASQL_RETURN_IF_ERROR(Serialize(replace_items_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTStarModifiers*> ParseTreeSerializer::Deserialize(
    const ASTStarModifiersProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTStarModifiers* node = zetasql_base::NewInArena<ASTStarModifiers>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStarModifiers* node, const ASTStarModifiersProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_except_list()) {
    node->AddChild(Deserialize(proto.except_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  for (int i=0; i < proto.replace_items_size(); i++) {
    node->AddChild(Deserialize(proto.replace_items(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStarReplaceItem* node,
                                            ASTStarReplaceItemProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTStarReplaceItem*> ParseTreeSerializer::Deserialize(
    const ASTStarReplaceItemProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTStarReplaceItem* node = zetasql_base::NewInArena<ASTStarReplaceItem>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStarReplaceItem* node, const ASTStarReplaceItemProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStarWithModifiers* node,
                                            ASTStarWithModifiersProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->modifiers_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->modifiers_, proto->mutable_modifiers()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTStarWithModifiers* node,
                                           AnyASTExpressionProto* proto) {
  ASTStarWithModifiersProto* ast_star_with_modifiers_proto =
      proto->mutable_ast_star_with_modifiers_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_star_with_modifiers_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTStarWithModifiers*> ParseTreeSerializer::Deserialize(
    const ASTStarWithModifiersProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTStarWithModifiers* node = zetasql_base::NewInArena<ASTStarWithModifiers>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStarWithModifiers* node, const ASTStarWithModifiersProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_modifiers()) {
    node->AddChild(Deserialize(proto.modifiers(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTableSubquery* node,
                                            ASTTableSubqueryProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->subquery_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->subquery_, proto->mutable_subquery()));
  }
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  if (node->pivot_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->pivot_clause_, proto->mutable_pivot_clause()));
  }
  if (node->unpivot_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->unpivot_clause_, proto->mutable_unpivot_clause()));
  }
  if (node->sample_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->sample_clause_, proto->mutable_sample_clause()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTTableSubquery* node,
                                           AnyASTTableExpressionProto* proto) {
  ASTTableSubqueryProto* ast_table_subquery_proto =
      proto->mutable_ast_table_subquery_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_table_subquery_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTTableSubquery*> ParseTreeSerializer::Deserialize(
    const ASTTableSubqueryProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTableSubquery* node = zetasql_base::NewInArena<ASTTableSubquery>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTableSubquery* node, const ASTTableSubqueryProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_subquery()) {
    node->AddChild(Deserialize(proto.subquery(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_pivot_clause()) {
    node->AddChild(Deserialize(proto.pivot_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_unpivot_clause()) {
    node->AddChild(Deserialize(proto.unpivot_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_sample_clause()) {
    node->AddChild(Deserialize(proto.sample_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTUnaryExpression* node,
                                            ASTUnaryExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->operand_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->operand_, proto->mutable_operand()));
  }
  proto->set_op(static_cast<ASTUnaryExpressionEnums_Op>(node->op_));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTUnaryExpression* node,
                                           AnyASTExpressionProto* proto) {
  ASTUnaryExpressionProto* ast_unary_expression_proto =
      proto->mutable_ast_unary_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_unary_expression_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTUnaryExpression*> ParseTreeSerializer::Deserialize(
    const ASTUnaryExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTUnaryExpression* node = zetasql_base::NewInArena<ASTUnaryExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTUnaryExpression* node, const ASTUnaryExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_operand()) {
    node->AddChild(Deserialize(proto.operand(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->op_ = static_cast<ASTUnaryExpression::Op>(proto.op());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTUnnestExpression* node,
                                            ASTUnnestExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTUnnestExpression*> ParseTreeSerializer::Deserialize(
    const ASTUnnestExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTUnnestExpression* node = zetasql_base::NewInArena<ASTUnnestExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTUnnestExpression* node, const ASTUnnestExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWindowClause* node,
                                            ASTWindowClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->windows().length(); i++) {
    const ASTWindowDefinition* windows_ = node->windows().at(i);
    ASTWindowDefinitionProto* proto2 = proto->add_windows();
    ZETASQL_RETURN_IF_ERROR(Serialize(windows_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTWindowClause*> ParseTreeSerializer::Deserialize(
    const ASTWindowClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWindowClause* node = zetasql_base::NewInArena<ASTWindowClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWindowClause* node, const ASTWindowClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.windows_size(); i++) {
    node->AddChild(Deserialize(proto.windows(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWindowDefinition* node,
                                            ASTWindowDefinitionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->window_spec_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->window_spec_, proto->mutable_window_spec()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTWindowDefinition*> ParseTreeSerializer::Deserialize(
    const ASTWindowDefinitionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWindowDefinition* node = zetasql_base::NewInArena<ASTWindowDefinition>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWindowDefinition* node, const ASTWindowDefinitionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_window_spec()) {
    node->AddChild(Deserialize(proto.window_spec(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWindowFrame* node,
                                            ASTWindowFrameProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->start_expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->start_expr_, proto->mutable_start_expr()));
  }
  if (node->end_expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->end_expr_, proto->mutable_end_expr()));
  }
  proto->set_frame_unit(static_cast<ASTWindowFrameEnums_FrameUnit>(node->frame_unit_));
  return absl::OkStatus();
}
absl::StatusOr<ASTWindowFrame*> ParseTreeSerializer::Deserialize(
    const ASTWindowFrameProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWindowFrame* node = zetasql_base::NewInArena<ASTWindowFrame>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWindowFrame* node, const ASTWindowFrameProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_start_expr()) {
    node->AddChild(Deserialize(proto.start_expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_end_expr()) {
    node->AddChild(Deserialize(proto.end_expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->frame_unit_ = static_cast<ASTWindowFrame::FrameUnit>(proto.frame_unit());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWindowFrameExpr* node,
                                            ASTWindowFrameExprProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  proto->set_boundary_type(static_cast<ASTWindowFrameExprEnums_BoundaryType>(node->boundary_type_));
  return absl::OkStatus();
}
absl::StatusOr<ASTWindowFrameExpr*> ParseTreeSerializer::Deserialize(
    const ASTWindowFrameExprProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWindowFrameExpr* node = zetasql_base::NewInArena<ASTWindowFrameExpr>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWindowFrameExpr* node, const ASTWindowFrameExprProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->boundary_type_ = static_cast<ASTWindowFrameExpr::BoundaryType>(proto.boundary_type());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTLikeExpression* node,
                                            ASTLikeExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->lhs_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->lhs_, proto->mutable_lhs()));
  }
  if (node->op_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->op_, proto->mutable_op()));
  }
  if (node->hint_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->hint_, proto->mutable_hint()));
  }
  if (node->in_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->in_list_, proto->mutable_in_list()));
  }
  if (node->query_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->query_, proto->mutable_query()));
  }
  if (node->unnest_expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->unnest_expr_, proto->mutable_unnest_expr()));
  }
  proto->set_is_not(node->is_not_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTLikeExpression* node,
                                           AnyASTExpressionProto* proto) {
  ASTLikeExpressionProto* ast_like_expression_proto =
      proto->mutable_ast_like_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_like_expression_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTLikeExpression*> ParseTreeSerializer::Deserialize(
    const ASTLikeExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTLikeExpression* node = zetasql_base::NewInArena<ASTLikeExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTLikeExpression* node, const ASTLikeExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_lhs()) {
    node->AddChild(Deserialize(proto.lhs(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_op()) {
    node->AddChild(Deserialize(proto.op(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_hint()) {
    node->AddChild(Deserialize(proto.hint(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_in_list()) {
    node->AddChild(Deserialize(proto.in_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_query()) {
    node->AddChild(Deserialize(proto.query(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_unnest_expr()) {
    node->AddChild(Deserialize(proto.unnest_expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_not_ = proto.is_not();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWindowSpecification* node,
                                            ASTWindowSpecificationProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->base_window_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->base_window_name_, proto->mutable_base_window_name()));
  }
  if (node->partition_by_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->partition_by_, proto->mutable_partition_by()));
  }
  if (node->order_by_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->order_by_, proto->mutable_order_by()));
  }
  if (node->window_frame_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->window_frame_, proto->mutable_window_frame()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTWindowSpecification*> ParseTreeSerializer::Deserialize(
    const ASTWindowSpecificationProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWindowSpecification* node = zetasql_base::NewInArena<ASTWindowSpecification>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWindowSpecification* node, const ASTWindowSpecificationProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_base_window_name()) {
    node->AddChild(Deserialize(proto.base_window_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_partition_by()) {
    node->AddChild(Deserialize(proto.partition_by(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_order_by()) {
    node->AddChild(Deserialize(proto.order_by(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_window_frame()) {
    node->AddChild(Deserialize(proto.window_frame(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWithOffset* node,
                                            ASTWithOffsetProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTWithOffset*> ParseTreeSerializer::Deserialize(
    const ASTWithOffsetProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWithOffset* node = zetasql_base::NewInArena<ASTWithOffset>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWithOffset* node, const ASTWithOffsetProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAnySomeAllOp* node,
                                            ASTAnySomeAllOpProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_op(static_cast<ASTAnySomeAllOpEnums_Op>(node->op_));
  return absl::OkStatus();
}
absl::StatusOr<ASTAnySomeAllOp*> ParseTreeSerializer::Deserialize(
    const ASTAnySomeAllOpProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAnySomeAllOp* node = zetasql_base::NewInArena<ASTAnySomeAllOp>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAnySomeAllOp* node, const ASTAnySomeAllOpProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->op_ = static_cast<ASTAnySomeAllOp::Op>(proto.op());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTParameterExprBase* node,
                                            ASTParameterExprBaseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTParameterExprBase* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTParameterExprBaseProto* ast_parameter_expr_base_proto =
      proto->mutable_ast_parameter_expr_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_parameter_expr_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTParameterExprBase* node,
                                           AnyASTParameterExprBaseProto* proto) {
  if (dynamic_cast<const ASTParameterExpr*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTParameterExpr*>(node),
                              proto->mutable_ast_parameter_expr_node()));
  } else if (dynamic_cast<const ASTSystemVariableExpr*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTSystemVariableExpr*>(node),
                              proto->mutable_ast_system_variable_expr_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTParameterExprBase");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTParameterExprBase*> ParseTreeSerializer::Deserialize(
    const AnyASTParameterExprBaseProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTParameterExprBaseProto::kAstParameterExprNode: {
      return Deserialize(
          proto.ast_parameter_expr_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTParameterExprBaseProto::kAstSystemVariableExprNode: {
      return Deserialize(
          proto.ast_system_variable_expr_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTParameterExprBaseProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTParameterExprBase* node, const ASTParameterExprBaseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTParameterExprBase* node, const ASTParameterExprBaseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStatementList* node,
                                            ASTStatementListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->statement_list().length(); i++) {
    const ASTStatement* statement_list_ = node->statement_list().at(i);
    AnyASTStatementProto* proto2 = proto->add_statement_list();
    ZETASQL_RETURN_IF_ERROR(Serialize(statement_list_, proto2));
  }
  proto->set_variable_declarations_allowed(node->variable_declarations_allowed_);
  return absl::OkStatus();
}
absl::StatusOr<ASTStatementList*> ParseTreeSerializer::Deserialize(
    const ASTStatementListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTStatementList* node = zetasql_base::NewInArena<ASTStatementList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStatementList* node, const ASTStatementListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.statement_list_size(); i++) {
    node->AddChild(Deserialize(proto.statement_list(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  node->variable_declarations_allowed_ = proto.variable_declarations_allowed();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTScriptStatement* node,
                                            ASTScriptStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTScriptStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTScriptStatement* node,
                                           AnyASTScriptStatementProto* proto) {
  if (dynamic_cast<const ASTIfStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTIfStatement*>(node),
                              proto->mutable_ast_if_statement_node()));
  } else if (dynamic_cast<const ASTCaseStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCaseStatement*>(node),
                              proto->mutable_ast_case_statement_node()));
  } else if (dynamic_cast<const ASTRaiseStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTRaiseStatement*>(node),
                              proto->mutable_ast_raise_statement_node()));
  } else if (dynamic_cast<const ASTBeginEndBlock*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTBeginEndBlock*>(node),
                              proto->mutable_ast_begin_end_block_node()));
  } else if (dynamic_cast<const ASTVariableDeclaration*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTVariableDeclaration*>(node),
                              proto->mutable_ast_variable_declaration_node()));
  } else if (dynamic_cast<const ASTBreakContinueStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTBreakContinueStatement*>(node),
                              proto->mutable_ast_break_continue_statement_node()));
  } else if (dynamic_cast<const ASTReturnStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTReturnStatement*>(node),
                              proto->mutable_ast_return_statement_node()));
  } else if (dynamic_cast<const ASTSingleAssignment*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTSingleAssignment*>(node),
                              proto->mutable_ast_single_assignment_node()));
  } else if (dynamic_cast<const ASTAssignmentFromStruct*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAssignmentFromStruct*>(node),
                              proto->mutable_ast_assignment_from_struct_node()));
  } else if (dynamic_cast<const ASTLoopStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTLoopStatement*>(node),
                              proto->mutable_ast_loop_statement_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTScriptStatement");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTScriptStatement*> ParseTreeSerializer::Deserialize(
    const AnyASTScriptStatementProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTScriptStatementProto::kAstIfStatementNode: {
      return Deserialize(
          proto.ast_if_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTScriptStatementProto::kAstCaseStatementNode: {
      return Deserialize(
          proto.ast_case_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTScriptStatementProto::kAstRaiseStatementNode: {
      return Deserialize(
          proto.ast_raise_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTScriptStatementProto::kAstBeginEndBlockNode: {
      return Deserialize(
          proto.ast_begin_end_block_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTScriptStatementProto::kAstVariableDeclarationNode: {
      return Deserialize(
          proto.ast_variable_declaration_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTScriptStatementProto::kAstBreakContinueStatementNode: {
      return Deserialize(
          proto.ast_break_continue_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTScriptStatementProto::kAstReturnStatementNode: {
      return Deserialize(
          proto.ast_return_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTScriptStatementProto::kAstSingleAssignmentNode: {
      return Deserialize(
          proto.ast_single_assignment_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTScriptStatementProto::kAstAssignmentFromStructNode: {
      return Deserialize(
          proto.ast_assignment_from_struct_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTScriptStatementProto::kAstLoopStatementNode: {
      return Deserialize(
          proto.ast_loop_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTScriptStatementProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTScriptStatement* node, const ASTScriptStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTScriptStatement* node, const ASTScriptStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTHintedStatement* node,
                                            ASTHintedStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->hint_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->hint_, proto->mutable_hint()));
  }
  if (node->statement_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->statement_, proto->mutable_statement()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTHintedStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTHintedStatementProto* ast_hinted_statement_proto =
      proto->mutable_ast_hinted_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_hinted_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTHintedStatement*> ParseTreeSerializer::Deserialize(
    const ASTHintedStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTHintedStatement* node = zetasql_base::NewInArena<ASTHintedStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTHintedStatement* node, const ASTHintedStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_hint()) {
    node->AddChild(Deserialize(proto.hint(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_statement()) {
    node->AddChild(Deserialize(proto.statement(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTExplainStatement* node,
                                            ASTExplainStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->statement_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->statement_, proto->mutable_statement()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTExplainStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTExplainStatementProto* ast_explain_statement_proto =
      proto->mutable_ast_explain_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_explain_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTExplainStatement*> ParseTreeSerializer::Deserialize(
    const ASTExplainStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTExplainStatement* node = zetasql_base::NewInArena<ASTExplainStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTExplainStatement* node, const ASTExplainStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_statement()) {
    node->AddChild(Deserialize(proto.statement(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDescribeStatement* node,
                                            ASTDescribeStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->optional_identifier_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->optional_identifier_, proto->mutable_optional_identifier()));
  }
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->optional_from_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->optional_from_name_, proto->mutable_optional_from_name()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDescribeStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTDescribeStatementProto* ast_describe_statement_proto =
      proto->mutable_ast_describe_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_describe_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDescribeStatement*> ParseTreeSerializer::Deserialize(
    const ASTDescribeStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDescribeStatement* node = zetasql_base::NewInArena<ASTDescribeStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDescribeStatement* node, const ASTDescribeStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_optional_identifier()) {
    node->AddChild(Deserialize(proto.optional_identifier(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_optional_from_name()) {
    node->AddChild(Deserialize(proto.optional_from_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTShowStatement* node,
                                            ASTShowStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->identifier_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->identifier_, proto->mutable_identifier()));
  }
  if (node->optional_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->optional_name_, proto->mutable_optional_name()));
  }
  if (node->optional_like_string_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->optional_like_string_, proto->mutable_optional_like_string()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTShowStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTShowStatementProto* ast_show_statement_proto =
      proto->mutable_ast_show_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_show_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTShowStatement*> ParseTreeSerializer::Deserialize(
    const ASTShowStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTShowStatement* node = zetasql_base::NewInArena<ASTShowStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTShowStatement* node, const ASTShowStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_identifier()) {
    node->AddChild(Deserialize(proto.identifier(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_optional_name()) {
    node->AddChild(Deserialize(proto.optional_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_optional_like_string()) {
    node->AddChild(Deserialize(proto.optional_like_string(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTransactionMode* node,
                                            ASTTransactionModeProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTTransactionMode* node,
                                           AnyASTTransactionModeProto* proto) {
  if (dynamic_cast<const ASTTransactionIsolationLevel*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTTransactionIsolationLevel*>(node),
                              proto->mutable_ast_transaction_isolation_level_node()));
  } else if (dynamic_cast<const ASTTransactionReadWriteMode*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTTransactionReadWriteMode*>(node),
                              proto->mutable_ast_transaction_read_write_mode_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTTransactionMode");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTTransactionMode*> ParseTreeSerializer::Deserialize(
    const AnyASTTransactionModeProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTTransactionModeProto::kAstTransactionIsolationLevelNode: {
      return Deserialize(
          proto.ast_transaction_isolation_level_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTransactionModeProto::kAstTransactionReadWriteModeNode: {
      return Deserialize(
          proto.ast_transaction_read_write_mode_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTransactionModeProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTTransactionMode* node, const ASTTransactionModeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTransactionMode* node, const ASTTransactionModeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTransactionIsolationLevel* node,
                                            ASTTransactionIsolationLevelProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->identifier1_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->identifier1_, proto->mutable_identifier1()));
  }
  if (node->identifier2_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->identifier2_, proto->mutable_identifier2()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTTransactionIsolationLevel* node,
                                           AnyASTTransactionModeProto* proto) {
  ASTTransactionIsolationLevelProto* ast_transaction_isolation_level_proto =
      proto->mutable_ast_transaction_isolation_level_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_transaction_isolation_level_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTTransactionIsolationLevel*> ParseTreeSerializer::Deserialize(
    const ASTTransactionIsolationLevelProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTransactionIsolationLevel* node = zetasql_base::NewInArena<ASTTransactionIsolationLevel>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTransactionIsolationLevel* node, const ASTTransactionIsolationLevelProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_identifier1()) {
    node->AddChild(Deserialize(proto.identifier1(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_identifier2()) {
    node->AddChild(Deserialize(proto.identifier2(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTransactionReadWriteMode* node,
                                            ASTTransactionReadWriteModeProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_mode(static_cast<ASTTransactionReadWriteModeEnums_Mode>(node->mode_));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTTransactionReadWriteMode* node,
                                           AnyASTTransactionModeProto* proto) {
  ASTTransactionReadWriteModeProto* ast_transaction_read_write_mode_proto =
      proto->mutable_ast_transaction_read_write_mode_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_transaction_read_write_mode_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTTransactionReadWriteMode*> ParseTreeSerializer::Deserialize(
    const ASTTransactionReadWriteModeProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTransactionReadWriteMode* node = zetasql_base::NewInArena<ASTTransactionReadWriteMode>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTransactionReadWriteMode* node, const ASTTransactionReadWriteModeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->mode_ = static_cast<ASTTransactionReadWriteMode::Mode>(proto.mode());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTransactionModeList* node,
                                            ASTTransactionModeListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->elements().length(); i++) {
    const ASTTransactionMode* elements_ = node->elements().at(i);
    AnyASTTransactionModeProto* proto2 = proto->add_elements();
    ZETASQL_RETURN_IF_ERROR(Serialize(elements_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTTransactionModeList*> ParseTreeSerializer::Deserialize(
    const ASTTransactionModeListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTransactionModeList* node = zetasql_base::NewInArena<ASTTransactionModeList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTransactionModeList* node, const ASTTransactionModeListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.elements_size(); i++) {
    node->AddChild(Deserialize(proto.elements(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTBeginStatement* node,
                                            ASTBeginStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->mode_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->mode_list_, proto->mutable_mode_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBeginStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTBeginStatementProto* ast_begin_statement_proto =
      proto->mutable_ast_begin_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_begin_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTBeginStatement*> ParseTreeSerializer::Deserialize(
    const ASTBeginStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTBeginStatement* node = zetasql_base::NewInArena<ASTBeginStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTBeginStatement* node, const ASTBeginStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_mode_list()) {
    node->AddChild(Deserialize(proto.mode_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSetTransactionStatement* node,
                                            ASTSetTransactionStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->mode_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->mode_list_, proto->mutable_mode_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTSetTransactionStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTSetTransactionStatementProto* ast_set_transaction_statement_proto =
      proto->mutable_ast_set_transaction_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_set_transaction_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTSetTransactionStatement*> ParseTreeSerializer::Deserialize(
    const ASTSetTransactionStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSetTransactionStatement* node = zetasql_base::NewInArena<ASTSetTransactionStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSetTransactionStatement* node, const ASTSetTransactionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_mode_list()) {
    node->AddChild(Deserialize(proto.mode_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCommitStatement* node,
                                            ASTCommitStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCommitStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTCommitStatementProto* ast_commit_statement_proto =
      proto->mutable_ast_commit_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_commit_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCommitStatement*> ParseTreeSerializer::Deserialize(
    const ASTCommitStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCommitStatement* node = zetasql_base::NewInArena<ASTCommitStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCommitStatement* node, const ASTCommitStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTRollbackStatement* node,
                                            ASTRollbackStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTRollbackStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTRollbackStatementProto* ast_rollback_statement_proto =
      proto->mutable_ast_rollback_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_rollback_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTRollbackStatement*> ParseTreeSerializer::Deserialize(
    const ASTRollbackStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTRollbackStatement* node = zetasql_base::NewInArena<ASTRollbackStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTRollbackStatement* node, const ASTRollbackStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStartBatchStatement* node,
                                            ASTStartBatchStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->batch_type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->batch_type_, proto->mutable_batch_type()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTStartBatchStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTStartBatchStatementProto* ast_start_batch_statement_proto =
      proto->mutable_ast_start_batch_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_start_batch_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTStartBatchStatement*> ParseTreeSerializer::Deserialize(
    const ASTStartBatchStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTStartBatchStatement* node = zetasql_base::NewInArena<ASTStartBatchStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStartBatchStatement* node, const ASTStartBatchStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_batch_type()) {
    node->AddChild(Deserialize(proto.batch_type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTRunBatchStatement* node,
                                            ASTRunBatchStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTRunBatchStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTRunBatchStatementProto* ast_run_batch_statement_proto =
      proto->mutable_ast_run_batch_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_run_batch_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTRunBatchStatement*> ParseTreeSerializer::Deserialize(
    const ASTRunBatchStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTRunBatchStatement* node = zetasql_base::NewInArena<ASTRunBatchStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTRunBatchStatement* node, const ASTRunBatchStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAbortBatchStatement* node,
                                            ASTAbortBatchStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAbortBatchStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTAbortBatchStatementProto* ast_abort_batch_statement_proto =
      proto->mutable_ast_abort_batch_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_abort_batch_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAbortBatchStatement*> ParseTreeSerializer::Deserialize(
    const ASTAbortBatchStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAbortBatchStatement* node = zetasql_base::NewInArena<ASTAbortBatchStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAbortBatchStatement* node, const ASTAbortBatchStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDdlStatement* node,
                                            ASTDdlStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDdlStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDdlStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  if (dynamic_cast<const ASTDropEntityStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDropEntityStatement*>(node),
                              proto->mutable_ast_drop_entity_statement_node()));
  } else if (dynamic_cast<const ASTDropFunctionStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDropFunctionStatement*>(node),
                              proto->mutable_ast_drop_function_statement_node()));
  } else if (dynamic_cast<const ASTDropTableFunctionStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDropTableFunctionStatement*>(node),
                              proto->mutable_ast_drop_table_function_statement_node()));
  } else if (dynamic_cast<const ASTDropMaterializedViewStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDropMaterializedViewStatement*>(node),
                              proto->mutable_ast_drop_materialized_view_statement_node()));
  } else if (dynamic_cast<const ASTDropSnapshotTableStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDropSnapshotTableStatement*>(node),
                              proto->mutable_ast_drop_snapshot_table_statement_node()));
  } else if (dynamic_cast<const ASTDropSearchIndexStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDropSearchIndexStatement*>(node),
                              proto->mutable_ast_drop_search_index_statement_node()));
  } else if (dynamic_cast<const ASTCreateStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateStatement*>(node),
                              proto->mutable_ast_create_statement_node()));
  } else if (dynamic_cast<const ASTDropRowAccessPolicyStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDropRowAccessPolicyStatement*>(node),
                              proto->mutable_ast_drop_row_access_policy_statement_node()));
  } else if (dynamic_cast<const ASTDropStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDropStatement*>(node),
                              proto->mutable_ast_drop_statement_node()));
  } else if (dynamic_cast<const ASTAlterStatementBase*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterStatementBase*>(node),
                              proto->mutable_ast_alter_statement_base_node()));
  } else if (dynamic_cast<const ASTDropPrivilegeRestrictionStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDropPrivilegeRestrictionStatement*>(node),
                              proto->mutable_ast_drop_privilege_restriction_statement_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTDdlStatement");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTDdlStatement*> ParseTreeSerializer::Deserialize(
    const AnyASTDdlStatementProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTDdlStatementProto::kAstDropEntityStatementNode: {
      return Deserialize(
          proto.ast_drop_entity_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTDdlStatementProto::kAstDropFunctionStatementNode: {
      return Deserialize(
          proto.ast_drop_function_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTDdlStatementProto::kAstDropTableFunctionStatementNode: {
      return Deserialize(
          proto.ast_drop_table_function_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTDdlStatementProto::kAstDropMaterializedViewStatementNode: {
      return Deserialize(
          proto.ast_drop_materialized_view_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTDdlStatementProto::kAstDropSnapshotTableStatementNode: {
      return Deserialize(
          proto.ast_drop_snapshot_table_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTDdlStatementProto::kAstDropSearchIndexStatementNode: {
      return Deserialize(
          proto.ast_drop_search_index_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTDdlStatementProto::kAstCreateStatementNode: {
      return Deserialize(
          proto.ast_create_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTDdlStatementProto::kAstDropRowAccessPolicyStatementNode: {
      return Deserialize(
          proto.ast_drop_row_access_policy_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTDdlStatementProto::kAstDropStatementNode: {
      return Deserialize(
          proto.ast_drop_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTDdlStatementProto::kAstAlterStatementBaseNode: {
      return Deserialize(
          proto.ast_alter_statement_base_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTDdlStatementProto::kAstDropPrivilegeRestrictionStatementNode: {
      return Deserialize(
          proto.ast_drop_privilege_restriction_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTDdlStatementProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTDdlStatement* node, const ASTDdlStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDdlStatement* node, const ASTDdlStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDropEntityStatement* node,
                                            ASTDropEntityStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->entity_type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->entity_type_, proto->mutable_entity_type()));
  }
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropEntityStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropEntityStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  ASTDropEntityStatementProto* ast_drop_entity_statement_proto =
      proto->mutable_ast_drop_entity_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_drop_entity_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDropEntityStatement*> ParseTreeSerializer::Deserialize(
    const ASTDropEntityStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDropEntityStatement* node = zetasql_base::NewInArena<ASTDropEntityStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDropEntityStatement* node, const ASTDropEntityStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_entity_type()) {
    node->AddChild(Deserialize(proto.entity_type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDropFunctionStatement* node,
                                            ASTDropFunctionStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->parameters_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->parameters_, proto->mutable_parameters()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropFunctionStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropFunctionStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  ASTDropFunctionStatementProto* ast_drop_function_statement_proto =
      proto->mutable_ast_drop_function_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_drop_function_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDropFunctionStatement*> ParseTreeSerializer::Deserialize(
    const ASTDropFunctionStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDropFunctionStatement* node = zetasql_base::NewInArena<ASTDropFunctionStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDropFunctionStatement* node, const ASTDropFunctionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_parameters()) {
    node->AddChild(Deserialize(proto.parameters(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDropTableFunctionStatement* node,
                                            ASTDropTableFunctionStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropTableFunctionStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropTableFunctionStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  ASTDropTableFunctionStatementProto* ast_drop_table_function_statement_proto =
      proto->mutable_ast_drop_table_function_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_drop_table_function_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDropTableFunctionStatement*> ParseTreeSerializer::Deserialize(
    const ASTDropTableFunctionStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDropTableFunctionStatement* node = zetasql_base::NewInArena<ASTDropTableFunctionStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDropTableFunctionStatement* node, const ASTDropTableFunctionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDropAllRowAccessPoliciesStatement* node,
                                            ASTDropAllRowAccessPoliciesStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->table_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->table_name_, proto->mutable_table_name()));
  }
  proto->set_has_access_keyword(node->has_access_keyword_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropAllRowAccessPoliciesStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTDropAllRowAccessPoliciesStatementProto* ast_drop_all_row_access_policies_statement_proto =
      proto->mutable_ast_drop_all_row_access_policies_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_drop_all_row_access_policies_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDropAllRowAccessPoliciesStatement*> ParseTreeSerializer::Deserialize(
    const ASTDropAllRowAccessPoliciesStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDropAllRowAccessPoliciesStatement* node = zetasql_base::NewInArena<ASTDropAllRowAccessPoliciesStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDropAllRowAccessPoliciesStatement* node, const ASTDropAllRowAccessPoliciesStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_table_name()) {
    node->AddChild(Deserialize(proto.table_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->has_access_keyword_ = proto.has_access_keyword();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDropMaterializedViewStatement* node,
                                            ASTDropMaterializedViewStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropMaterializedViewStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropMaterializedViewStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  ASTDropMaterializedViewStatementProto* ast_drop_materialized_view_statement_proto =
      proto->mutable_ast_drop_materialized_view_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_drop_materialized_view_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDropMaterializedViewStatement*> ParseTreeSerializer::Deserialize(
    const ASTDropMaterializedViewStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDropMaterializedViewStatement* node = zetasql_base::NewInArena<ASTDropMaterializedViewStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDropMaterializedViewStatement* node, const ASTDropMaterializedViewStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDropSnapshotTableStatement* node,
                                            ASTDropSnapshotTableStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropSnapshotTableStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropSnapshotTableStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  ASTDropSnapshotTableStatementProto* ast_drop_snapshot_table_statement_proto =
      proto->mutable_ast_drop_snapshot_table_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_drop_snapshot_table_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDropSnapshotTableStatement*> ParseTreeSerializer::Deserialize(
    const ASTDropSnapshotTableStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDropSnapshotTableStatement* node = zetasql_base::NewInArena<ASTDropSnapshotTableStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDropSnapshotTableStatement* node, const ASTDropSnapshotTableStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDropSearchIndexStatement* node,
                                            ASTDropSearchIndexStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->table_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->table_name_, proto->mutable_table_name()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropSearchIndexStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropSearchIndexStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  ASTDropSearchIndexStatementProto* ast_drop_search_index_statement_proto =
      proto->mutable_ast_drop_search_index_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_drop_search_index_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDropSearchIndexStatement*> ParseTreeSerializer::Deserialize(
    const ASTDropSearchIndexStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDropSearchIndexStatement* node = zetasql_base::NewInArena<ASTDropSearchIndexStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDropSearchIndexStatement* node, const ASTDropSearchIndexStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_table_name()) {
    node->AddChild(Deserialize(proto.table_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTRenameStatement* node,
                                            ASTRenameStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->identifier_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->identifier_, proto->mutable_identifier()));
  }
  if (node->old_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->old_name_, proto->mutable_old_name()));
  }
  if (node->new_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->new_name_, proto->mutable_new_name()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTRenameStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTRenameStatementProto* ast_rename_statement_proto =
      proto->mutable_ast_rename_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_rename_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTRenameStatement*> ParseTreeSerializer::Deserialize(
    const ASTRenameStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTRenameStatement* node = zetasql_base::NewInArena<ASTRenameStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTRenameStatement* node, const ASTRenameStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_identifier()) {
    node->AddChild(Deserialize(proto.identifier(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_old_name()) {
    node->AddChild(Deserialize(proto.old_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_new_name()) {
    node->AddChild(Deserialize(proto.new_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTImportStatement* node,
                                            ASTImportStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->string_value_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->string_value_, proto->mutable_string_value()));
  }
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  if (node->into_alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->into_alias_, proto->mutable_into_alias()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  proto->set_import_kind(static_cast<ASTImportStatementEnums_ImportKind>(node->import_kind_));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTImportStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTImportStatementProto* ast_import_statement_proto =
      proto->mutable_ast_import_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_import_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTImportStatement*> ParseTreeSerializer::Deserialize(
    const ASTImportStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTImportStatement* node = zetasql_base::NewInArena<ASTImportStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTImportStatement* node, const ASTImportStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_string_value()) {
    node->AddChild(Deserialize(proto.string_value(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_into_alias()) {
    node->AddChild(Deserialize(proto.into_alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->import_kind_ = static_cast<ASTImportStatement::ImportKind>(proto.import_kind());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTModuleStatement* node,
                                            ASTModuleStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTModuleStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTModuleStatementProto* ast_module_statement_proto =
      proto->mutable_ast_module_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_module_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTModuleStatement*> ParseTreeSerializer::Deserialize(
    const ASTModuleStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTModuleStatement* node = zetasql_base::NewInArena<ASTModuleStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTModuleStatement* node, const ASTModuleStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWithConnectionClause* node,
                                            ASTWithConnectionClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->connection_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->connection_clause_, proto->mutable_connection_clause()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTWithConnectionClause*> ParseTreeSerializer::Deserialize(
    const ASTWithConnectionClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWithConnectionClause* node = zetasql_base::NewInArena<ASTWithConnectionClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWithConnectionClause* node, const ASTWithConnectionClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_connection_clause()) {
    node->AddChild(Deserialize(proto.connection_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTIntoAlias* node,
                                            ASTIntoAliasProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->identifier_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->identifier_, proto->mutable_identifier()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTIntoAlias*> ParseTreeSerializer::Deserialize(
    const ASTIntoAliasProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTIntoAlias* node = zetasql_base::NewInArena<ASTIntoAlias>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTIntoAlias* node, const ASTIntoAliasProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_identifier()) {
    node->AddChild(Deserialize(proto.identifier(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTUnnestExpressionWithOptAliasAndOffset* node,
                                            ASTUnnestExpressionWithOptAliasAndOffsetProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->unnest_expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->unnest_expression_, proto->mutable_unnest_expression()));
  }
  if (node->optional_alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->optional_alias_, proto->mutable_optional_alias()));
  }
  if (node->optional_with_offset_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->optional_with_offset_, proto->mutable_optional_with_offset()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTUnnestExpressionWithOptAliasAndOffset*> ParseTreeSerializer::Deserialize(
    const ASTUnnestExpressionWithOptAliasAndOffsetProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTUnnestExpressionWithOptAliasAndOffset* node = zetasql_base::NewInArena<ASTUnnestExpressionWithOptAliasAndOffset>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTUnnestExpressionWithOptAliasAndOffset* node, const ASTUnnestExpressionWithOptAliasAndOffsetProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_unnest_expression()) {
    node->AddChild(Deserialize(proto.unnest_expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_optional_alias()) {
    node->AddChild(Deserialize(proto.optional_alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_optional_with_offset()) {
    node->AddChild(Deserialize(proto.optional_with_offset(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTPivotExpression* node,
                                            ASTPivotExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTPivotExpression*> ParseTreeSerializer::Deserialize(
    const ASTPivotExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTPivotExpression* node = zetasql_base::NewInArena<ASTPivotExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTPivotExpression* node, const ASTPivotExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTPivotValue* node,
                                            ASTPivotValueProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->value_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->value_, proto->mutable_value()));
  }
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTPivotValue*> ParseTreeSerializer::Deserialize(
    const ASTPivotValueProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTPivotValue* node = zetasql_base::NewInArena<ASTPivotValue>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTPivotValue* node, const ASTPivotValueProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_value()) {
    node->AddChild(Deserialize(proto.value(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTPivotExpressionList* node,
                                            ASTPivotExpressionListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->expressions().length(); i++) {
    const ASTPivotExpression* expressions_ = node->expressions().at(i);
    ASTPivotExpressionProto* proto2 = proto->add_expressions();
    ZETASQL_RETURN_IF_ERROR(Serialize(expressions_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTPivotExpressionList*> ParseTreeSerializer::Deserialize(
    const ASTPivotExpressionListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTPivotExpressionList* node = zetasql_base::NewInArena<ASTPivotExpressionList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTPivotExpressionList* node, const ASTPivotExpressionListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.expressions_size(); i++) {
    node->AddChild(Deserialize(proto.expressions(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTPivotValueList* node,
                                            ASTPivotValueListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->values().length(); i++) {
    const ASTPivotValue* values_ = node->values().at(i);
    ASTPivotValueProto* proto2 = proto->add_values();
    ZETASQL_RETURN_IF_ERROR(Serialize(values_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTPivotValueList*> ParseTreeSerializer::Deserialize(
    const ASTPivotValueListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTPivotValueList* node = zetasql_base::NewInArena<ASTPivotValueList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTPivotValueList* node, const ASTPivotValueListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.values_size(); i++) {
    node->AddChild(Deserialize(proto.values(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTPivotClause* node,
                                            ASTPivotClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->pivot_expressions_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->pivot_expressions_, proto->mutable_pivot_expressions()));
  }
  if (node->for_expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->for_expression_, proto->mutable_for_expression()));
  }
  if (node->pivot_values_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->pivot_values_, proto->mutable_pivot_values()));
  }
  if (node->output_alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->output_alias_, proto->mutable_output_alias()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTPivotClause*> ParseTreeSerializer::Deserialize(
    const ASTPivotClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTPivotClause* node = zetasql_base::NewInArena<ASTPivotClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTPivotClause* node, const ASTPivotClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_pivot_expressions()) {
    node->AddChild(Deserialize(proto.pivot_expressions(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_for_expression()) {
    node->AddChild(Deserialize(proto.for_expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_pivot_values()) {
    node->AddChild(Deserialize(proto.pivot_values(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_output_alias()) {
    node->AddChild(Deserialize(proto.output_alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTUnpivotInItem* node,
                                            ASTUnpivotInItemProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->unpivot_columns_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->unpivot_columns_, proto->mutable_unpivot_columns()));
  }
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTUnpivotInItem*> ParseTreeSerializer::Deserialize(
    const ASTUnpivotInItemProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTUnpivotInItem* node = zetasql_base::NewInArena<ASTUnpivotInItem>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTUnpivotInItem* node, const ASTUnpivotInItemProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_unpivot_columns()) {
    node->AddChild(Deserialize(proto.unpivot_columns(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTUnpivotInItemList* node,
                                            ASTUnpivotInItemListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->in_items().length(); i++) {
    const ASTUnpivotInItem* in_items_ = node->in_items().at(i);
    ASTUnpivotInItemProto* proto2 = proto->add_in_items();
    ZETASQL_RETURN_IF_ERROR(Serialize(in_items_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTUnpivotInItemList*> ParseTreeSerializer::Deserialize(
    const ASTUnpivotInItemListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTUnpivotInItemList* node = zetasql_base::NewInArena<ASTUnpivotInItemList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTUnpivotInItemList* node, const ASTUnpivotInItemListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.in_items_size(); i++) {
    node->AddChild(Deserialize(proto.in_items(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTUnpivotClause* node,
                                            ASTUnpivotClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->unpivot_output_value_columns_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->unpivot_output_value_columns_, proto->mutable_unpivot_output_value_columns()));
  }
  if (node->unpivot_output_name_column_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->unpivot_output_name_column_, proto->mutable_unpivot_output_name_column()));
  }
  if (node->unpivot_in_items_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->unpivot_in_items_, proto->mutable_unpivot_in_items()));
  }
  if (node->output_alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->output_alias_, proto->mutable_output_alias()));
  }
  proto->set_null_filter(static_cast<ASTUnpivotClauseEnums_NullFilter>(node->null_filter_));
  return absl::OkStatus();
}
absl::StatusOr<ASTUnpivotClause*> ParseTreeSerializer::Deserialize(
    const ASTUnpivotClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTUnpivotClause* node = zetasql_base::NewInArena<ASTUnpivotClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTUnpivotClause* node, const ASTUnpivotClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_unpivot_output_value_columns()) {
    node->AddChild(Deserialize(proto.unpivot_output_value_columns(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_unpivot_output_name_column()) {
    node->AddChild(Deserialize(proto.unpivot_output_name_column(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_unpivot_in_items()) {
    node->AddChild(Deserialize(proto.unpivot_in_items(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_output_alias()) {
    node->AddChild(Deserialize(proto.output_alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->null_filter_ = static_cast<ASTUnpivotClause::NullFilter>(proto.null_filter());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTUsingClause* node,
                                            ASTUsingClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->keys().length(); i++) {
    const ASTIdentifier* keys_ = node->keys().at(i);
    ASTIdentifierProto* proto2 = proto->add_keys();
    ZETASQL_RETURN_IF_ERROR(Serialize(keys_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTUsingClause*> ParseTreeSerializer::Deserialize(
    const ASTUsingClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTUsingClause* node = zetasql_base::NewInArena<ASTUsingClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTUsingClause* node, const ASTUsingClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.keys_size(); i++) {
    node->AddChild(Deserialize(proto.keys(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTForSystemTime* node,
                                            ASTForSystemTimeProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTForSystemTime*> ParseTreeSerializer::Deserialize(
    const ASTForSystemTimeProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTForSystemTime* node = zetasql_base::NewInArena<ASTForSystemTime>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTForSystemTime* node, const ASTForSystemTimeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTQualify* node,
                                            ASTQualifyProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTQualify*> ParseTreeSerializer::Deserialize(
    const ASTQualifyProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTQualify* node = zetasql_base::NewInArena<ASTQualify>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTQualify* node, const ASTQualifyProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTClampedBetweenModifier* node,
                                            ASTClampedBetweenModifierProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->low_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->low_, proto->mutable_low()));
  }
  if (node->high_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->high_, proto->mutable_high()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTClampedBetweenModifier*> ParseTreeSerializer::Deserialize(
    const ASTClampedBetweenModifierProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTClampedBetweenModifier* node = zetasql_base::NewInArena<ASTClampedBetweenModifier>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTClampedBetweenModifier* node, const ASTClampedBetweenModifierProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_low()) {
    node->AddChild(Deserialize(proto.low(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_high()) {
    node->AddChild(Deserialize(proto.high(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTFormatClause* node,
                                            ASTFormatClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->format_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->format_, proto->mutable_format()));
  }
  if (node->time_zone_expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->time_zone_expr_, proto->mutable_time_zone_expr()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTFormatClause*> ParseTreeSerializer::Deserialize(
    const ASTFormatClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTFormatClause* node = zetasql_base::NewInArena<ASTFormatClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTFormatClause* node, const ASTFormatClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_format()) {
    node->AddChild(Deserialize(proto.format(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_time_zone_expr()) {
    node->AddChild(Deserialize(proto.time_zone_expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTPathExpressionList* node,
                                            ASTPathExpressionListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->path_expression_list().length(); i++) {
    const ASTPathExpression* path_expression_list_ = node->path_expression_list().at(i);
    ASTPathExpressionProto* proto2 = proto->add_path_expression_list();
    ZETASQL_RETURN_IF_ERROR(Serialize(path_expression_list_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTPathExpressionList*> ParseTreeSerializer::Deserialize(
    const ASTPathExpressionListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTPathExpressionList* node = zetasql_base::NewInArena<ASTPathExpressionList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTPathExpressionList* node, const ASTPathExpressionListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.path_expression_list_size(); i++) {
    node->AddChild(Deserialize(proto.path_expression_list(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTParameterExpr* node,
                                            ASTParameterExprProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  proto->set_position(node->position_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTParameterExpr* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTParameterExprBaseProto* ast_parameter_expr_base_proto =
      proto->mutable_ast_parameter_expr_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_parameter_expr_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTParameterExpr* node,
                                           AnyASTParameterExprBaseProto* proto) {
  ASTParameterExprProto* ast_parameter_expr_proto =
      proto->mutable_ast_parameter_expr_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_parameter_expr_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTParameterExpr*> ParseTreeSerializer::Deserialize(
    const ASTParameterExprProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTParameterExpr* node = zetasql_base::NewInArena<ASTParameterExpr>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTParameterExpr* node, const ASTParameterExprProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->position_ = proto.position();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSystemVariableExpr* node,
                                            ASTSystemVariableExprProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->path_, proto->mutable_path()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTSystemVariableExpr* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTParameterExprBaseProto* ast_parameter_expr_base_proto =
      proto->mutable_ast_parameter_expr_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_parameter_expr_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTSystemVariableExpr* node,
                                           AnyASTParameterExprBaseProto* proto) {
  ASTSystemVariableExprProto* ast_system_variable_expr_proto =
      proto->mutable_ast_system_variable_expr_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_system_variable_expr_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTSystemVariableExpr*> ParseTreeSerializer::Deserialize(
    const ASTSystemVariableExprProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSystemVariableExpr* node = zetasql_base::NewInArena<ASTSystemVariableExpr>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSystemVariableExpr* node, const ASTSystemVariableExprProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_path()) {
    node->AddChild(Deserialize(proto.path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWithGroupRows* node,
                                            ASTWithGroupRowsProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->subquery_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->subquery_, proto->mutable_subquery()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTWithGroupRows*> ParseTreeSerializer::Deserialize(
    const ASTWithGroupRowsProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWithGroupRows* node = zetasql_base::NewInArena<ASTWithGroupRows>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWithGroupRows* node, const ASTWithGroupRowsProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_subquery()) {
    node->AddChild(Deserialize(proto.subquery(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTLambda* node,
                                            ASTLambdaProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->argument_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->argument_list_, proto->mutable_argument_list()));
  }
  if (node->body_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->body_, proto->mutable_body()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTLambda* node,
                                           AnyASTExpressionProto* proto) {
  ASTLambdaProto* ast_lambda_proto =
      proto->mutable_ast_lambda_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_lambda_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTLambda*> ParseTreeSerializer::Deserialize(
    const ASTLambdaProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTLambda* node = zetasql_base::NewInArena<ASTLambda>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTLambda* node, const ASTLambdaProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_argument_list()) {
    node->AddChild(Deserialize(proto.argument_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_body()) {
    node->AddChild(Deserialize(proto.body(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAnalyticFunctionCall* node,
                                            ASTAnalyticFunctionCallProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  if (node->window_spec_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->window_spec_, proto->mutable_window_spec()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAnalyticFunctionCall* node,
                                           AnyASTExpressionProto* proto) {
  ASTAnalyticFunctionCallProto* ast_analytic_function_call_proto =
      proto->mutable_ast_analytic_function_call_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_analytic_function_call_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAnalyticFunctionCall*> ParseTreeSerializer::Deserialize(
    const ASTAnalyticFunctionCallProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAnalyticFunctionCall* node = zetasql_base::NewInArena<ASTAnalyticFunctionCall>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAnalyticFunctionCall* node, const ASTAnalyticFunctionCallProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_window_spec()) {
    node->AddChild(Deserialize(proto.window_spec(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTFunctionCallWithGroupRows* node,
                                            ASTFunctionCallWithGroupRowsProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->function_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->function_, proto->mutable_function()));
  }
  if (node->subquery_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->subquery_, proto->mutable_subquery()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTFunctionCallWithGroupRows* node,
                                           AnyASTExpressionProto* proto) {
  ASTFunctionCallWithGroupRowsProto* ast_function_call_with_group_rows_proto =
      proto->mutable_ast_function_call_with_group_rows_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_function_call_with_group_rows_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTFunctionCallWithGroupRows*> ParseTreeSerializer::Deserialize(
    const ASTFunctionCallWithGroupRowsProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTFunctionCallWithGroupRows* node = zetasql_base::NewInArena<ASTFunctionCallWithGroupRows>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTFunctionCallWithGroupRows* node, const ASTFunctionCallWithGroupRowsProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_function()) {
    node->AddChild(Deserialize(proto.function(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_subquery()) {
    node->AddChild(Deserialize(proto.subquery(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTClusterBy* node,
                                            ASTClusterByProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->clustering_expressions().length(); i++) {
    const ASTExpression* clustering_expressions_ = node->clustering_expressions().at(i);
    AnyASTExpressionProto* proto2 = proto->add_clustering_expressions();
    ZETASQL_RETURN_IF_ERROR(Serialize(clustering_expressions_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTClusterBy*> ParseTreeSerializer::Deserialize(
    const ASTClusterByProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTClusterBy* node = zetasql_base::NewInArena<ASTClusterBy>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTClusterBy* node, const ASTClusterByProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.clustering_expressions_size(); i++) {
    node->AddChild(Deserialize(proto.clustering_expressions(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTNewConstructorArg* node,
                                            ASTNewConstructorArgProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  if (node->optional_identifier_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->optional_identifier_, proto->mutable_optional_identifier()));
  }
  if (node->optional_path_expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->optional_path_expression_, proto->mutable_optional_path_expression()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTNewConstructorArg*> ParseTreeSerializer::Deserialize(
    const ASTNewConstructorArgProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTNewConstructorArg* node = zetasql_base::NewInArena<ASTNewConstructorArg>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTNewConstructorArg* node, const ASTNewConstructorArgProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_optional_identifier()) {
    node->AddChild(Deserialize(proto.optional_identifier(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_optional_path_expression()) {
    node->AddChild(Deserialize(proto.optional_path_expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTNewConstructor* node,
                                            ASTNewConstructorProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->type_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_name_, proto->mutable_type_name()));
  }
  for (int i = 0; i < node->arguments().length(); i++) {
    const ASTNewConstructorArg* arguments_ = node->arguments().at(i);
    ASTNewConstructorArgProto* proto2 = proto->add_arguments();
    ZETASQL_RETURN_IF_ERROR(Serialize(arguments_, proto2));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTNewConstructor* node,
                                           AnyASTExpressionProto* proto) {
  ASTNewConstructorProto* ast_new_constructor_proto =
      proto->mutable_ast_new_constructor_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_new_constructor_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTNewConstructor*> ParseTreeSerializer::Deserialize(
    const ASTNewConstructorProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTNewConstructor* node = zetasql_base::NewInArena<ASTNewConstructor>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTNewConstructor* node, const ASTNewConstructorProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_type_name()) {
    node->AddChild(Deserialize(proto.type_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  for (int i=0; i < proto.arguments_size(); i++) {
    node->AddChild(Deserialize(proto.arguments(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTOptionsList* node,
                                            ASTOptionsListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->options_entries().length(); i++) {
    const ASTOptionsEntry* options_entries_ = node->options_entries().at(i);
    ASTOptionsEntryProto* proto2 = proto->add_options_entries();
    ZETASQL_RETURN_IF_ERROR(Serialize(options_entries_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTOptionsList*> ParseTreeSerializer::Deserialize(
    const ASTOptionsListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTOptionsList* node = zetasql_base::NewInArena<ASTOptionsList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTOptionsList* node, const ASTOptionsListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.options_entries_size(); i++) {
    node->AddChild(Deserialize(proto.options_entries(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTOptionsEntry* node,
                                            ASTOptionsEntryProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->value_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->value_, proto->mutable_value()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTOptionsEntry*> ParseTreeSerializer::Deserialize(
    const ASTOptionsEntryProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTOptionsEntry* node = zetasql_base::NewInArena<ASTOptionsEntry>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTOptionsEntry* node, const ASTOptionsEntryProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_value()) {
    node->AddChild(Deserialize(proto.value(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateStatement* node,
                                            ASTCreateStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_scope(static_cast<ASTCreateStatementEnums_Scope>(node->scope_));
  proto->set_is_or_replace(node->is_or_replace_);
  proto->set_is_if_not_exists(node->is_if_not_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  if (dynamic_cast<const ASTCreateConstantStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateConstantStatement*>(node),
                              proto->mutable_ast_create_constant_statement_node()));
  } else if (dynamic_cast<const ASTCreateProcedureStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateProcedureStatement*>(node),
                              proto->mutable_ast_create_procedure_statement_node()));
  } else if (dynamic_cast<const ASTCreateSchemaStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateSchemaStatement*>(node),
                              proto->mutable_ast_create_schema_statement_node()));
  } else if (dynamic_cast<const ASTCreateModelStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateModelStatement*>(node),
                              proto->mutable_ast_create_model_statement_node()));
  } else if (dynamic_cast<const ASTCreateIndexStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateIndexStatement*>(node),
                              proto->mutable_ast_create_index_statement_node()));
  } else if (dynamic_cast<const ASTCreateSnapshotTableStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateSnapshotTableStatement*>(node),
                              proto->mutable_ast_create_snapshot_table_statement_node()));
  } else if (dynamic_cast<const ASTCreateEntityStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateEntityStatement*>(node),
                              proto->mutable_ast_create_entity_statement_node()));
  } else if (dynamic_cast<const ASTCreateRowAccessPolicyStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateRowAccessPolicyStatement*>(node),
                              proto->mutable_ast_create_row_access_policy_statement_node()));
  } else if (dynamic_cast<const ASTCreateTableStmtBase*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateTableStmtBase*>(node),
                              proto->mutable_ast_create_table_stmt_base_node()));
  } else if (dynamic_cast<const ASTCreateViewStatementBase*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateViewStatementBase*>(node),
                              proto->mutable_ast_create_view_statement_base_node()));
  } else if (dynamic_cast<const ASTCreateFunctionStmtBase*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateFunctionStmtBase*>(node),
                              proto->mutable_ast_create_function_stmt_base_node()));
  } else if (dynamic_cast<const ASTCreatePrivilegeRestrictionStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreatePrivilegeRestrictionStatement*>(node),
                              proto->mutable_ast_create_privilege_restriction_statement_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTCreateStatement");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateStatement*> ParseTreeSerializer::Deserialize(
    const AnyASTCreateStatementProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTCreateStatementProto::kAstCreateConstantStatementNode: {
      return Deserialize(
          proto.ast_create_constant_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateStatementProto::kAstCreateProcedureStatementNode: {
      return Deserialize(
          proto.ast_create_procedure_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateStatementProto::kAstCreateSchemaStatementNode: {
      return Deserialize(
          proto.ast_create_schema_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateStatementProto::kAstCreateModelStatementNode: {
      return Deserialize(
          proto.ast_create_model_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateStatementProto::kAstCreateIndexStatementNode: {
      return Deserialize(
          proto.ast_create_index_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateStatementProto::kAstCreateSnapshotTableStatementNode: {
      return Deserialize(
          proto.ast_create_snapshot_table_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateStatementProto::kAstCreateEntityStatementNode: {
      return Deserialize(
          proto.ast_create_entity_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateStatementProto::kAstCreateRowAccessPolicyStatementNode: {
      return Deserialize(
          proto.ast_create_row_access_policy_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateStatementProto::kAstCreateTableStmtBaseNode: {
      return Deserialize(
          proto.ast_create_table_stmt_base_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateStatementProto::kAstCreateViewStatementBaseNode: {
      return Deserialize(
          proto.ast_create_view_statement_base_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateStatementProto::kAstCreateFunctionStmtBaseNode: {
      return Deserialize(
          proto.ast_create_function_stmt_base_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateStatementProto::kAstCreatePrivilegeRestrictionStatementNode: {
      return Deserialize(
          proto.ast_create_privilege_restriction_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateStatementProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTCreateStatement* node, const ASTCreateStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateStatement* node, const ASTCreateStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->scope_ = static_cast<ASTCreateStatement::Scope>(proto.scope());
  node->is_or_replace_ = proto.is_or_replace();
  node->is_if_not_exists_ = proto.is_if_not_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTFunctionParameter* node,
                                            ASTFunctionParameterProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_, proto->mutable_type()));
  }
  if (node->templated_parameter_type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->templated_parameter_type_, proto->mutable_templated_parameter_type()));
  }
  if (node->tvf_schema_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->tvf_schema_, proto->mutable_tvf_schema()));
  }
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  if (node->default_value_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->default_value_, proto->mutable_default_value()));
  }
  proto->set_procedure_parameter_mode(static_cast<ASTFunctionParameterEnums_ProcedureParameterMode>(node->procedure_parameter_mode_));
  proto->set_is_not_aggregate(node->is_not_aggregate_);
  return absl::OkStatus();
}
absl::StatusOr<ASTFunctionParameter*> ParseTreeSerializer::Deserialize(
    const ASTFunctionParameterProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTFunctionParameter* node = zetasql_base::NewInArena<ASTFunctionParameter>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTFunctionParameter* node, const ASTFunctionParameterProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_type()) {
    node->AddChild(Deserialize(proto.type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_templated_parameter_type()) {
    node->AddChild(Deserialize(proto.templated_parameter_type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_tvf_schema()) {
    node->AddChild(Deserialize(proto.tvf_schema(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_default_value()) {
    node->AddChild(Deserialize(proto.default_value(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->procedure_parameter_mode_ = static_cast<ASTFunctionParameter::ProcedureParameterMode>(proto.procedure_parameter_mode());
  node->is_not_aggregate_ = proto.is_not_aggregate();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTFunctionParameters* node,
                                            ASTFunctionParametersProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->parameter_entries().length(); i++) {
    const ASTFunctionParameter* parameter_entries_ = node->parameter_entries().at(i);
    ASTFunctionParameterProto* proto2 = proto->add_parameter_entries();
    ZETASQL_RETURN_IF_ERROR(Serialize(parameter_entries_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTFunctionParameters*> ParseTreeSerializer::Deserialize(
    const ASTFunctionParametersProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTFunctionParameters* node = zetasql_base::NewInArena<ASTFunctionParameters>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTFunctionParameters* node, const ASTFunctionParametersProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.parameter_entries_size(); i++) {
    node->AddChild(Deserialize(proto.parameter_entries(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTFunctionDeclaration* node,
                                            ASTFunctionDeclarationProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->parameters_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->parameters_, proto->mutable_parameters()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTFunctionDeclaration*> ParseTreeSerializer::Deserialize(
    const ASTFunctionDeclarationProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTFunctionDeclaration* node = zetasql_base::NewInArena<ASTFunctionDeclaration>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTFunctionDeclaration* node, const ASTFunctionDeclarationProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_parameters()) {
    node->AddChild(Deserialize(proto.parameters(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSqlFunctionBody* node,
                                            ASTSqlFunctionBodyProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTSqlFunctionBody*> ParseTreeSerializer::Deserialize(
    const ASTSqlFunctionBodyProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSqlFunctionBody* node = zetasql_base::NewInArena<ASTSqlFunctionBody>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSqlFunctionBody* node, const ASTSqlFunctionBodyProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTVFArgument* node,
                                            ASTTVFArgumentProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expr_, proto->mutable_expr()));
  }
  if (node->table_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->table_clause_, proto->mutable_table_clause()));
  }
  if (node->model_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->model_clause_, proto->mutable_model_clause()));
  }
  if (node->connection_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->connection_clause_, proto->mutable_connection_clause()));
  }
  if (node->desc_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->desc_, proto->mutable_desc()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTTVFArgument*> ParseTreeSerializer::Deserialize(
    const ASTTVFArgumentProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTVFArgument* node = zetasql_base::NewInArena<ASTTVFArgument>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTVFArgument* node, const ASTTVFArgumentProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expr()) {
    node->AddChild(Deserialize(proto.expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_table_clause()) {
    node->AddChild(Deserialize(proto.table_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_model_clause()) {
    node->AddChild(Deserialize(proto.model_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_connection_clause()) {
    node->AddChild(Deserialize(proto.connection_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_desc()) {
    node->AddChild(Deserialize(proto.desc(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTVF* node,
                                            ASTTVFProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  for (int i = 0; i < node->argument_entries().length(); i++) {
    const ASTTVFArgument* argument_entries_ = node->argument_entries().at(i);
    ASTTVFArgumentProto* proto2 = proto->add_argument_entries();
    ZETASQL_RETURN_IF_ERROR(Serialize(argument_entries_, proto2));
  }
  if (node->hint_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->hint_, proto->mutable_hint()));
  }
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  if (node->pivot_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->pivot_clause_, proto->mutable_pivot_clause()));
  }
  if (node->unpivot_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->unpivot_clause_, proto->mutable_unpivot_clause()));
  }
  if (node->sample_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->sample_, proto->mutable_sample()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTTVF* node,
                                           AnyASTTableExpressionProto* proto) {
  ASTTVFProto* ast_tvf_proto =
      proto->mutable_ast_tvf_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_tvf_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTTVF*> ParseTreeSerializer::Deserialize(
    const ASTTVFProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTVF* node = zetasql_base::NewInArena<ASTTVF>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTVF* node, const ASTTVFProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  for (int i=0; i < proto.argument_entries_size(); i++) {
    node->AddChild(Deserialize(proto.argument_entries(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  if (proto.has_hint()) {
    node->AddChild(Deserialize(proto.hint(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_pivot_clause()) {
    node->AddChild(Deserialize(proto.pivot_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_unpivot_clause()) {
    node->AddChild(Deserialize(proto.unpivot_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_sample()) {
    node->AddChild(Deserialize(proto.sample(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTableClause* node,
                                            ASTTableClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->table_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->table_path_, proto->mutable_table_path()));
  }
  if (node->tvf_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->tvf_, proto->mutable_tvf()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTTableClause*> ParseTreeSerializer::Deserialize(
    const ASTTableClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTableClause* node = zetasql_base::NewInArena<ASTTableClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTableClause* node, const ASTTableClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_table_path()) {
    node->AddChild(Deserialize(proto.table_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_tvf()) {
    node->AddChild(Deserialize(proto.tvf(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTModelClause* node,
                                            ASTModelClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->model_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->model_path_, proto->mutable_model_path()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTModelClause*> ParseTreeSerializer::Deserialize(
    const ASTModelClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTModelClause* node = zetasql_base::NewInArena<ASTModelClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTModelClause* node, const ASTModelClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_model_path()) {
    node->AddChild(Deserialize(proto.model_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTConnectionClause* node,
                                            ASTConnectionClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->connection_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->connection_path_, proto->mutable_connection_path()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTConnectionClause*> ParseTreeSerializer::Deserialize(
    const ASTConnectionClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTConnectionClause* node = zetasql_base::NewInArena<ASTConnectionClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTConnectionClause* node, const ASTConnectionClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_connection_path()) {
    node->AddChild(Deserialize(proto.connection_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTableDataSource* node,
                                            ASTTableDataSourceProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->path_expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->path_expr_, proto->mutable_path_expr()));
  }
  if (node->for_system_time_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->for_system_time_, proto->mutable_for_system_time()));
  }
  if (node->where_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->where_clause_, proto->mutable_where_clause()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTTableDataSource* node,
                                           AnyASTTableExpressionProto* proto) {
  AnyASTTableDataSourceProto* ast_table_data_source_proto =
      proto->mutable_ast_table_data_source_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_table_data_source_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTTableDataSource* node,
                                           AnyASTTableDataSourceProto* proto) {
  if (dynamic_cast<const ASTCloneDataSource*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCloneDataSource*>(node),
                              proto->mutable_ast_clone_data_source_node()));
  } else if (dynamic_cast<const ASTCopyDataSource*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCopyDataSource*>(node),
                              proto->mutable_ast_copy_data_source_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTTableDataSource");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTTableDataSource*> ParseTreeSerializer::Deserialize(
    const AnyASTTableDataSourceProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTTableDataSourceProto::kAstCloneDataSourceNode: {
      return Deserialize(
          proto.ast_clone_data_source_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTableDataSourceProto::kAstCopyDataSourceNode: {
      return Deserialize(
          proto.ast_copy_data_source_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTableDataSourceProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTTableDataSource* node, const ASTTableDataSourceProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTableDataSource* node, const ASTTableDataSourceProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_path_expr()) {
    node->AddChild(Deserialize(proto.path_expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_for_system_time()) {
    node->AddChild(Deserialize(proto.for_system_time(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_where_clause()) {
    node->AddChild(Deserialize(proto.where_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCloneDataSource* node,
                                            ASTCloneDataSourceProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCloneDataSource* node,
                                           AnyASTTableExpressionProto* proto) {
  AnyASTTableDataSourceProto* ast_table_data_source_proto =
      proto->mutable_ast_table_data_source_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_table_data_source_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCloneDataSource* node,
                                           AnyASTTableDataSourceProto* proto) {
  ASTCloneDataSourceProto* ast_clone_data_source_proto =
      proto->mutable_ast_clone_data_source_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_clone_data_source_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCloneDataSource*> ParseTreeSerializer::Deserialize(
    const ASTCloneDataSourceProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCloneDataSource* node = zetasql_base::NewInArena<ASTCloneDataSource>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCloneDataSource* node, const ASTCloneDataSourceProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCopyDataSource* node,
                                            ASTCopyDataSourceProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCopyDataSource* node,
                                           AnyASTTableExpressionProto* proto) {
  AnyASTTableDataSourceProto* ast_table_data_source_proto =
      proto->mutable_ast_table_data_source_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_table_data_source_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCopyDataSource* node,
                                           AnyASTTableDataSourceProto* proto) {
  ASTCopyDataSourceProto* ast_copy_data_source_proto =
      proto->mutable_ast_copy_data_source_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_copy_data_source_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCopyDataSource*> ParseTreeSerializer::Deserialize(
    const ASTCopyDataSourceProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCopyDataSource* node = zetasql_base::NewInArena<ASTCopyDataSource>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCopyDataSource* node, const ASTCopyDataSourceProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCloneDataSourceList* node,
                                            ASTCloneDataSourceListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->data_sources().length(); i++) {
    const ASTCloneDataSource* data_sources_ = node->data_sources().at(i);
    ASTCloneDataSourceProto* proto2 = proto->add_data_sources();
    ZETASQL_RETURN_IF_ERROR(Serialize(data_sources_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTCloneDataSourceList*> ParseTreeSerializer::Deserialize(
    const ASTCloneDataSourceListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCloneDataSourceList* node = zetasql_base::NewInArena<ASTCloneDataSourceList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCloneDataSourceList* node, const ASTCloneDataSourceListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.data_sources_size(); i++) {
    node->AddChild(Deserialize(proto.data_sources(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCloneDataStatement* node,
                                            ASTCloneDataStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->target_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->target_path_, proto->mutable_target_path()));
  }
  if (node->data_source_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->data_source_list_, proto->mutable_data_source_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCloneDataStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTCloneDataStatementProto* ast_clone_data_statement_proto =
      proto->mutable_ast_clone_data_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_clone_data_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCloneDataStatement*> ParseTreeSerializer::Deserialize(
    const ASTCloneDataStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCloneDataStatement* node = zetasql_base::NewInArena<ASTCloneDataStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCloneDataStatement* node, const ASTCloneDataStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_target_path()) {
    node->AddChild(Deserialize(proto.target_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_data_source_list()) {
    node->AddChild(Deserialize(proto.data_source_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateConstantStatement* node,
                                            ASTCreateConstantStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expr_, proto->mutable_expr()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateConstantStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateConstantStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateConstantStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  ASTCreateConstantStatementProto* ast_create_constant_statement_proto =
      proto->mutable_ast_create_constant_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_constant_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateConstantStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreateConstantStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreateConstantStatement* node = zetasql_base::NewInArena<ASTCreateConstantStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateConstantStatement* node, const ASTCreateConstantStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_expr()) {
    node->AddChild(Deserialize(proto.expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateDatabaseStatement* node,
                                            ASTCreateDatabaseStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateDatabaseStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTCreateDatabaseStatementProto* ast_create_database_statement_proto =
      proto->mutable_ast_create_database_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_database_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateDatabaseStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreateDatabaseStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreateDatabaseStatement* node = zetasql_base::NewInArena<ASTCreateDatabaseStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateDatabaseStatement* node, const ASTCreateDatabaseStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateProcedureStatement* node,
                                            ASTCreateProcedureStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->parameters_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->parameters_, proto->mutable_parameters()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  if (node->body_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->body_, proto->mutable_body()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateProcedureStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateProcedureStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateProcedureStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  ASTCreateProcedureStatementProto* ast_create_procedure_statement_proto =
      proto->mutable_ast_create_procedure_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_procedure_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateProcedureStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreateProcedureStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreateProcedureStatement* node = zetasql_base::NewInArena<ASTCreateProcedureStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateProcedureStatement* node, const ASTCreateProcedureStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_parameters()) {
    node->AddChild(Deserialize(proto.parameters(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_body()) {
    node->AddChild(Deserialize(proto.body(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateSchemaStatement* node,
                                            ASTCreateSchemaStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->collate_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->collate_, proto->mutable_collate()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateSchemaStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateSchemaStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateSchemaStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  ASTCreateSchemaStatementProto* ast_create_schema_statement_proto =
      proto->mutable_ast_create_schema_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_schema_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateSchemaStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreateSchemaStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreateSchemaStatement* node = zetasql_base::NewInArena<ASTCreateSchemaStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateSchemaStatement* node, const ASTCreateSchemaStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_collate()) {
    node->AddChild(Deserialize(proto.collate(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTransformClause* node,
                                            ASTTransformClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->select_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->select_list_, proto->mutable_select_list()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTTransformClause*> ParseTreeSerializer::Deserialize(
    const ASTTransformClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTransformClause* node = zetasql_base::NewInArena<ASTTransformClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTransformClause* node, const ASTTransformClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_select_list()) {
    node->AddChild(Deserialize(proto.select_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateModelStatement* node,
                                            ASTCreateModelStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->transform_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->transform_clause_, proto->mutable_transform_clause()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  if (node->query_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->query_, proto->mutable_query()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateModelStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateModelStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateModelStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  ASTCreateModelStatementProto* ast_create_model_statement_proto =
      proto->mutable_ast_create_model_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_model_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateModelStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreateModelStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreateModelStatement* node = zetasql_base::NewInArena<ASTCreateModelStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateModelStatement* node, const ASTCreateModelStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_transform_clause()) {
    node->AddChild(Deserialize(proto.transform_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_query()) {
    node->AddChild(Deserialize(proto.query(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTIndexAllColumns* node,
                                            ASTIndexAllColumnsProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTIndexAllColumns* node,
                                           AnyASTExpressionProto* proto) {
  AnyASTLeafProto* ast_leaf_proto =
      proto->mutable_ast_leaf_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_leaf_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTIndexAllColumns* node,
                                           AnyASTLeafProto* proto) {
  ASTIndexAllColumnsProto* ast_index_all_columns_proto =
      proto->mutable_ast_index_all_columns_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_index_all_columns_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTIndexAllColumns*> ParseTreeSerializer::Deserialize(
    const ASTIndexAllColumnsProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTIndexAllColumns* node = zetasql_base::NewInArena<ASTIndexAllColumns>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTIndexAllColumns* node, const ASTIndexAllColumnsProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTIndexItemList* node,
                                            ASTIndexItemListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->ordering_expressions().length(); i++) {
    const ASTOrderingExpression* ordering_expressions_ = node->ordering_expressions().at(i);
    ASTOrderingExpressionProto* proto2 = proto->add_ordering_expressions();
    ZETASQL_RETURN_IF_ERROR(Serialize(ordering_expressions_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTIndexItemList*> ParseTreeSerializer::Deserialize(
    const ASTIndexItemListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTIndexItemList* node = zetasql_base::NewInArena<ASTIndexItemList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTIndexItemList* node, const ASTIndexItemListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.ordering_expressions_size(); i++) {
    node->AddChild(Deserialize(proto.ordering_expressions(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTIndexStoringExpressionList* node,
                                            ASTIndexStoringExpressionListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->expressions().length(); i++) {
    const ASTExpression* expressions_ = node->expressions().at(i);
    AnyASTExpressionProto* proto2 = proto->add_expressions();
    ZETASQL_RETURN_IF_ERROR(Serialize(expressions_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTIndexStoringExpressionList*> ParseTreeSerializer::Deserialize(
    const ASTIndexStoringExpressionListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTIndexStoringExpressionList* node = zetasql_base::NewInArena<ASTIndexStoringExpressionList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTIndexStoringExpressionList* node, const ASTIndexStoringExpressionListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.expressions_size(); i++) {
    node->AddChild(Deserialize(proto.expressions(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTIndexUnnestExpressionList* node,
                                            ASTIndexUnnestExpressionListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->unnest_expressions().length(); i++) {
    const ASTUnnestExpressionWithOptAliasAndOffset* unnest_expressions_ = node->unnest_expressions().at(i);
    ASTUnnestExpressionWithOptAliasAndOffsetProto* proto2 = proto->add_unnest_expressions();
    ZETASQL_RETURN_IF_ERROR(Serialize(unnest_expressions_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTIndexUnnestExpressionList*> ParseTreeSerializer::Deserialize(
    const ASTIndexUnnestExpressionListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTIndexUnnestExpressionList* node = zetasql_base::NewInArena<ASTIndexUnnestExpressionList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTIndexUnnestExpressionList* node, const ASTIndexUnnestExpressionListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.unnest_expressions_size(); i++) {
    node->AddChild(Deserialize(proto.unnest_expressions(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateIndexStatement* node,
                                            ASTCreateIndexStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->table_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->table_name_, proto->mutable_table_name()));
  }
  if (node->optional_table_alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->optional_table_alias_, proto->mutable_optional_table_alias()));
  }
  if (node->optional_index_unnest_expression_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->optional_index_unnest_expression_list_, proto->mutable_optional_index_unnest_expression_list()));
  }
  if (node->index_item_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->index_item_list_, proto->mutable_index_item_list()));
  }
  if (node->optional_index_storing_expressions_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->optional_index_storing_expressions_, proto->mutable_optional_index_storing_expressions()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  proto->set_is_unique(node->is_unique_);
  proto->set_is_search(node->is_search_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateIndexStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateIndexStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateIndexStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  ASTCreateIndexStatementProto* ast_create_index_statement_proto =
      proto->mutable_ast_create_index_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_index_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateIndexStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreateIndexStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreateIndexStatement* node = zetasql_base::NewInArena<ASTCreateIndexStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateIndexStatement* node, const ASTCreateIndexStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_table_name()) {
    node->AddChild(Deserialize(proto.table_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_optional_table_alias()) {
    node->AddChild(Deserialize(proto.optional_table_alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_optional_index_unnest_expression_list()) {
    node->AddChild(Deserialize(proto.optional_index_unnest_expression_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_index_item_list()) {
    node->AddChild(Deserialize(proto.index_item_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_optional_index_storing_expressions()) {
    node->AddChild(Deserialize(proto.optional_index_storing_expressions(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_unique_ = proto.is_unique();
  node->is_search_ = proto.is_search();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTExportDataStatement* node,
                                            ASTExportDataStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->with_connection_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->with_connection_clause_, proto->mutable_with_connection_clause()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  if (node->query_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->query_, proto->mutable_query()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTExportDataStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTExportDataStatementProto* ast_export_data_statement_proto =
      proto->mutable_ast_export_data_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_export_data_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTExportDataStatement*> ParseTreeSerializer::Deserialize(
    const ASTExportDataStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTExportDataStatement* node = zetasql_base::NewInArena<ASTExportDataStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTExportDataStatement* node, const ASTExportDataStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_with_connection_clause()) {
    node->AddChild(Deserialize(proto.with_connection_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_query()) {
    node->AddChild(Deserialize(proto.query(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTExportModelStatement* node,
                                            ASTExportModelStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->model_name_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->model_name_path_, proto->mutable_model_name_path()));
  }
  if (node->with_connection_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->with_connection_clause_, proto->mutable_with_connection_clause()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTExportModelStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTExportModelStatementProto* ast_export_model_statement_proto =
      proto->mutable_ast_export_model_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_export_model_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTExportModelStatement*> ParseTreeSerializer::Deserialize(
    const ASTExportModelStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTExportModelStatement* node = zetasql_base::NewInArena<ASTExportModelStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTExportModelStatement* node, const ASTExportModelStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_model_name_path()) {
    node->AddChild(Deserialize(proto.model_name_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_with_connection_clause()) {
    node->AddChild(Deserialize(proto.with_connection_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCallStatement* node,
                                            ASTCallStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->procedure_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->procedure_name_, proto->mutable_procedure_name()));
  }
  for (int i = 0; i < node->arguments().length(); i++) {
    const ASTTVFArgument* arguments_ = node->arguments().at(i);
    ASTTVFArgumentProto* proto2 = proto->add_arguments();
    ZETASQL_RETURN_IF_ERROR(Serialize(arguments_, proto2));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCallStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTCallStatementProto* ast_call_statement_proto =
      proto->mutable_ast_call_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_call_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCallStatement*> ParseTreeSerializer::Deserialize(
    const ASTCallStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCallStatement* node = zetasql_base::NewInArena<ASTCallStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCallStatement* node, const ASTCallStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_procedure_name()) {
    node->AddChild(Deserialize(proto.procedure_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  for (int i=0; i < proto.arguments_size(); i++) {
    node->AddChild(Deserialize(proto.arguments(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDefineTableStatement* node,
                                            ASTDefineTableStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDefineTableStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTDefineTableStatementProto* ast_define_table_statement_proto =
      proto->mutable_ast_define_table_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_define_table_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDefineTableStatement*> ParseTreeSerializer::Deserialize(
    const ASTDefineTableStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDefineTableStatement* node = zetasql_base::NewInArena<ASTDefineTableStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDefineTableStatement* node, const ASTDefineTableStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWithPartitionColumnsClause* node,
                                            ASTWithPartitionColumnsClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->table_element_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->table_element_list_, proto->mutable_table_element_list()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTWithPartitionColumnsClause*> ParseTreeSerializer::Deserialize(
    const ASTWithPartitionColumnsClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWithPartitionColumnsClause* node = zetasql_base::NewInArena<ASTWithPartitionColumnsClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWithPartitionColumnsClause* node, const ASTWithPartitionColumnsClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_table_element_list()) {
    node->AddChild(Deserialize(proto.table_element_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateSnapshotTableStatement* node,
                                            ASTCreateSnapshotTableStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->clone_data_source_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->clone_data_source_, proto->mutable_clone_data_source()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateSnapshotTableStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateSnapshotTableStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateSnapshotTableStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  ASTCreateSnapshotTableStatementProto* ast_create_snapshot_table_statement_proto =
      proto->mutable_ast_create_snapshot_table_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_snapshot_table_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateSnapshotTableStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreateSnapshotTableStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreateSnapshotTableStatement* node = zetasql_base::NewInArena<ASTCreateSnapshotTableStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateSnapshotTableStatement* node, const ASTCreateSnapshotTableStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_clone_data_source()) {
    node->AddChild(Deserialize(proto.clone_data_source(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTypeParameterList* node,
                                            ASTTypeParameterListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->parameters().length(); i++) {
    const ASTLeaf* parameters_ = node->parameters().at(i);
    AnyASTLeafProto* proto2 = proto->add_parameters();
    ZETASQL_RETURN_IF_ERROR(Serialize(parameters_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTTypeParameterList*> ParseTreeSerializer::Deserialize(
    const ASTTypeParameterListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTypeParameterList* node = zetasql_base::NewInArena<ASTTypeParameterList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTypeParameterList* node, const ASTTypeParameterListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.parameters_size(); i++) {
    node->AddChild(Deserialize(proto.parameters(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTVFSchema* node,
                                            ASTTVFSchemaProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->columns().length(); i++) {
    const ASTTVFSchemaColumn* columns_ = node->columns().at(i);
    ASTTVFSchemaColumnProto* proto2 = proto->add_columns();
    ZETASQL_RETURN_IF_ERROR(Serialize(columns_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTTVFSchema*> ParseTreeSerializer::Deserialize(
    const ASTTVFSchemaProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTVFSchema* node = zetasql_base::NewInArena<ASTTVFSchema>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTVFSchema* node, const ASTTVFSchemaProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.columns_size(); i++) {
    node->AddChild(Deserialize(proto.columns(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTVFSchemaColumn* node,
                                            ASTTVFSchemaColumnProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_, proto->mutable_type()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTTVFSchemaColumn*> ParseTreeSerializer::Deserialize(
    const ASTTVFSchemaColumnProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTVFSchemaColumn* node = zetasql_base::NewInArena<ASTTVFSchemaColumn>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTVFSchemaColumn* node, const ASTTVFSchemaColumnProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_type()) {
    node->AddChild(Deserialize(proto.type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTableAndColumnInfo* node,
                                            ASTTableAndColumnInfoProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->table_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->table_name_, proto->mutable_table_name()));
  }
  if (node->column_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->column_list_, proto->mutable_column_list()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTTableAndColumnInfo*> ParseTreeSerializer::Deserialize(
    const ASTTableAndColumnInfoProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTableAndColumnInfo* node = zetasql_base::NewInArena<ASTTableAndColumnInfo>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTableAndColumnInfo* node, const ASTTableAndColumnInfoProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_table_name()) {
    node->AddChild(Deserialize(proto.table_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_column_list()) {
    node->AddChild(Deserialize(proto.column_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTableAndColumnInfoList* node,
                                            ASTTableAndColumnInfoListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->table_and_column_info_entries().length(); i++) {
    const ASTTableAndColumnInfo* table_and_column_info_entries_ = node->table_and_column_info_entries().at(i);
    ASTTableAndColumnInfoProto* proto2 = proto->add_table_and_column_info_entries();
    ZETASQL_RETURN_IF_ERROR(Serialize(table_and_column_info_entries_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTTableAndColumnInfoList*> ParseTreeSerializer::Deserialize(
    const ASTTableAndColumnInfoListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTableAndColumnInfoList* node = zetasql_base::NewInArena<ASTTableAndColumnInfoList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTableAndColumnInfoList* node, const ASTTableAndColumnInfoListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.table_and_column_info_entries_size(); i++) {
    node->AddChild(Deserialize(proto.table_and_column_info_entries(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTemplatedParameterType* node,
                                            ASTTemplatedParameterTypeProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_kind(static_cast<ASTTemplatedParameterTypeEnums_TemplatedTypeKind>(node->kind_));
  return absl::OkStatus();
}
absl::StatusOr<ASTTemplatedParameterType*> ParseTreeSerializer::Deserialize(
    const ASTTemplatedParameterTypeProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTemplatedParameterType* node = zetasql_base::NewInArena<ASTTemplatedParameterType>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTemplatedParameterType* node, const ASTTemplatedParameterTypeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->kind_ = static_cast<ASTTemplatedParameterType::TemplatedTypeKind>(proto.kind());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDefaultLiteral* node,
                                            ASTDefaultLiteralProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDefaultLiteral* node,
                                           AnyASTExpressionProto* proto) {
  ASTDefaultLiteralProto* ast_default_literal_proto =
      proto->mutable_ast_default_literal_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_default_literal_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDefaultLiteral*> ParseTreeSerializer::Deserialize(
    const ASTDefaultLiteralProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDefaultLiteral* node = zetasql_base::NewInArena<ASTDefaultLiteral>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDefaultLiteral* node, const ASTDefaultLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAnalyzeStatement* node,
                                            ASTAnalyzeStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  if (node->table_and_column_info_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->table_and_column_info_list_, proto->mutable_table_and_column_info_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAnalyzeStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTAnalyzeStatementProto* ast_analyze_statement_proto =
      proto->mutable_ast_analyze_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_analyze_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAnalyzeStatement*> ParseTreeSerializer::Deserialize(
    const ASTAnalyzeStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAnalyzeStatement* node = zetasql_base::NewInArena<ASTAnalyzeStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAnalyzeStatement* node, const ASTAnalyzeStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_table_and_column_info_list()) {
    node->AddChild(Deserialize(proto.table_and_column_info_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAssertStatement* node,
                                            ASTAssertStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expr_, proto->mutable_expr()));
  }
  if (node->description_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->description_, proto->mutable_description()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAssertStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTAssertStatementProto* ast_assert_statement_proto =
      proto->mutable_ast_assert_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_assert_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAssertStatement*> ParseTreeSerializer::Deserialize(
    const ASTAssertStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAssertStatement* node = zetasql_base::NewInArena<ASTAssertStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAssertStatement* node, const ASTAssertStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expr()) {
    node->AddChild(Deserialize(proto.expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_description()) {
    node->AddChild(Deserialize(proto.description(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAssertRowsModified* node,
                                            ASTAssertRowsModifiedProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->num_rows_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->num_rows_, proto->mutable_num_rows()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTAssertRowsModified*> ParseTreeSerializer::Deserialize(
    const ASTAssertRowsModifiedProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAssertRowsModified* node = zetasql_base::NewInArena<ASTAssertRowsModified>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAssertRowsModified* node, const ASTAssertRowsModifiedProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_num_rows()) {
    node->AddChild(Deserialize(proto.num_rows(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTReturningClause* node,
                                            ASTReturningClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->select_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->select_list_, proto->mutable_select_list()));
  }
  if (node->action_alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->action_alias_, proto->mutable_action_alias()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTReturningClause*> ParseTreeSerializer::Deserialize(
    const ASTReturningClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTReturningClause* node = zetasql_base::NewInArena<ASTReturningClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTReturningClause* node, const ASTReturningClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_select_list()) {
    node->AddChild(Deserialize(proto.select_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_action_alias()) {
    node->AddChild(Deserialize(proto.action_alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDeleteStatement* node,
                                            ASTDeleteStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->target_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->target_path_, proto->mutable_target_path()));
  }
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  if (node->offset_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->offset_, proto->mutable_offset()));
  }
  if (node->where_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->where_, proto->mutable_where()));
  }
  if (node->assert_rows_modified_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->assert_rows_modified_, proto->mutable_assert_rows_modified()));
  }
  if (node->returning_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->returning_, proto->mutable_returning()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDeleteStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTDeleteStatementProto* ast_delete_statement_proto =
      proto->mutable_ast_delete_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_delete_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDeleteStatement*> ParseTreeSerializer::Deserialize(
    const ASTDeleteStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDeleteStatement* node = zetasql_base::NewInArena<ASTDeleteStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDeleteStatement* node, const ASTDeleteStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_target_path()) {
    node->AddChild(Deserialize(proto.target_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_offset()) {
    node->AddChild(Deserialize(proto.offset(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_where()) {
    node->AddChild(Deserialize(proto.where(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_assert_rows_modified()) {
    node->AddChild(Deserialize(proto.assert_rows_modified(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_returning()) {
    node->AddChild(Deserialize(proto.returning(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTColumnAttribute* node,
                                            ASTColumnAttributeProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTColumnAttribute* node,
                                           AnyASTColumnAttributeProto* proto) {
  if (dynamic_cast<const ASTNotNullColumnAttribute*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTNotNullColumnAttribute*>(node),
                              proto->mutable_ast_not_null_column_attribute_node()));
  } else if (dynamic_cast<const ASTHiddenColumnAttribute*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTHiddenColumnAttribute*>(node),
                              proto->mutable_ast_hidden_column_attribute_node()));
  } else if (dynamic_cast<const ASTPrimaryKeyColumnAttribute*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTPrimaryKeyColumnAttribute*>(node),
                              proto->mutable_ast_primary_key_column_attribute_node()));
  } else if (dynamic_cast<const ASTForeignKeyColumnAttribute*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTForeignKeyColumnAttribute*>(node),
                              proto->mutable_ast_foreign_key_column_attribute_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTColumnAttribute");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTColumnAttribute*> ParseTreeSerializer::Deserialize(
    const AnyASTColumnAttributeProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTColumnAttributeProto::kAstNotNullColumnAttributeNode: {
      return Deserialize(
          proto.ast_not_null_column_attribute_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTColumnAttributeProto::kAstHiddenColumnAttributeNode: {
      return Deserialize(
          proto.ast_hidden_column_attribute_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTColumnAttributeProto::kAstPrimaryKeyColumnAttributeNode: {
      return Deserialize(
          proto.ast_primary_key_column_attribute_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTColumnAttributeProto::kAstForeignKeyColumnAttributeNode: {
      return Deserialize(
          proto.ast_foreign_key_column_attribute_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTColumnAttributeProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTColumnAttribute* node, const ASTColumnAttributeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTColumnAttribute* node, const ASTColumnAttributeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTNotNullColumnAttribute* node,
                                            ASTNotNullColumnAttributeProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTNotNullColumnAttribute* node,
                                           AnyASTColumnAttributeProto* proto) {
  ASTNotNullColumnAttributeProto* ast_not_null_column_attribute_proto =
      proto->mutable_ast_not_null_column_attribute_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_not_null_column_attribute_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTNotNullColumnAttribute*> ParseTreeSerializer::Deserialize(
    const ASTNotNullColumnAttributeProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTNotNullColumnAttribute* node = zetasql_base::NewInArena<ASTNotNullColumnAttribute>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTNotNullColumnAttribute* node, const ASTNotNullColumnAttributeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTHiddenColumnAttribute* node,
                                            ASTHiddenColumnAttributeProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTHiddenColumnAttribute* node,
                                           AnyASTColumnAttributeProto* proto) {
  ASTHiddenColumnAttributeProto* ast_hidden_column_attribute_proto =
      proto->mutable_ast_hidden_column_attribute_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_hidden_column_attribute_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTHiddenColumnAttribute*> ParseTreeSerializer::Deserialize(
    const ASTHiddenColumnAttributeProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTHiddenColumnAttribute* node = zetasql_base::NewInArena<ASTHiddenColumnAttribute>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTHiddenColumnAttribute* node, const ASTHiddenColumnAttributeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTPrimaryKeyColumnAttribute* node,
                                            ASTPrimaryKeyColumnAttributeProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_enforced(node->enforced_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTPrimaryKeyColumnAttribute* node,
                                           AnyASTColumnAttributeProto* proto) {
  ASTPrimaryKeyColumnAttributeProto* ast_primary_key_column_attribute_proto =
      proto->mutable_ast_primary_key_column_attribute_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_primary_key_column_attribute_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTPrimaryKeyColumnAttribute*> ParseTreeSerializer::Deserialize(
    const ASTPrimaryKeyColumnAttributeProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTPrimaryKeyColumnAttribute* node = zetasql_base::NewInArena<ASTPrimaryKeyColumnAttribute>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTPrimaryKeyColumnAttribute* node, const ASTPrimaryKeyColumnAttributeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->enforced_ = proto.enforced();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTForeignKeyColumnAttribute* node,
                                            ASTForeignKeyColumnAttributeProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->constraint_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->constraint_name_, proto->mutable_constraint_name()));
  }
  if (node->reference_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->reference_, proto->mutable_reference()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTForeignKeyColumnAttribute* node,
                                           AnyASTColumnAttributeProto* proto) {
  ASTForeignKeyColumnAttributeProto* ast_foreign_key_column_attribute_proto =
      proto->mutable_ast_foreign_key_column_attribute_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_foreign_key_column_attribute_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTForeignKeyColumnAttribute*> ParseTreeSerializer::Deserialize(
    const ASTForeignKeyColumnAttributeProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTForeignKeyColumnAttribute* node = zetasql_base::NewInArena<ASTForeignKeyColumnAttribute>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTForeignKeyColumnAttribute* node, const ASTForeignKeyColumnAttributeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_constraint_name()) {
    node->AddChild(Deserialize(proto.constraint_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_reference()) {
    node->AddChild(Deserialize(proto.reference(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTColumnAttributeList* node,
                                            ASTColumnAttributeListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->values().length(); i++) {
    const ASTColumnAttribute* values_ = node->values().at(i);
    AnyASTColumnAttributeProto* proto2 = proto->add_values();
    ZETASQL_RETURN_IF_ERROR(Serialize(values_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTColumnAttributeList*> ParseTreeSerializer::Deserialize(
    const ASTColumnAttributeListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTColumnAttributeList* node = zetasql_base::NewInArena<ASTColumnAttributeList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTColumnAttributeList* node, const ASTColumnAttributeListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.values_size(); i++) {
    node->AddChild(Deserialize(proto.values(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStructColumnField* node,
                                            ASTStructColumnFieldProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->schema_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->schema_, proto->mutable_schema()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTStructColumnField*> ParseTreeSerializer::Deserialize(
    const ASTStructColumnFieldProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTStructColumnField* node = zetasql_base::NewInArena<ASTStructColumnField>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStructColumnField* node, const ASTStructColumnFieldProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_schema()) {
    node->AddChild(Deserialize(proto.schema(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTGeneratedColumnInfo* node,
                                            ASTGeneratedColumnInfoProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  proto->set_stored_mode(static_cast<ASTGeneratedColumnInfoEnums_StoredMode>(node->stored_mode_));
  return absl::OkStatus();
}
absl::StatusOr<ASTGeneratedColumnInfo*> ParseTreeSerializer::Deserialize(
    const ASTGeneratedColumnInfoProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTGeneratedColumnInfo* node = zetasql_base::NewInArena<ASTGeneratedColumnInfo>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTGeneratedColumnInfo* node, const ASTGeneratedColumnInfoProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->stored_mode_ = static_cast<ASTGeneratedColumnInfo::StoredMode>(proto.stored_mode());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTableElement* node,
                                            ASTTableElementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTTableElement* node,
                                           AnyASTTableElementProto* proto) {
  if (dynamic_cast<const ASTColumnDefinition*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTColumnDefinition*>(node),
                              proto->mutable_ast_column_definition_node()));
  } else if (dynamic_cast<const ASTTableConstraint*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTTableConstraint*>(node),
                              proto->mutable_ast_table_constraint_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTTableElement");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTTableElement*> ParseTreeSerializer::Deserialize(
    const AnyASTTableElementProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTTableElementProto::kAstColumnDefinitionNode: {
      return Deserialize(
          proto.ast_column_definition_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTableElementProto::kAstTableConstraintNode: {
      return Deserialize(
          proto.ast_table_constraint_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTableElementProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTTableElement* node, const ASTTableElementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTableElement* node, const ASTTableElementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTColumnDefinition* node,
                                            ASTColumnDefinitionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->schema_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->schema_, proto->mutable_schema()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTColumnDefinition* node,
                                           AnyASTTableElementProto* proto) {
  ASTColumnDefinitionProto* ast_column_definition_proto =
      proto->mutable_ast_column_definition_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_column_definition_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTColumnDefinition*> ParseTreeSerializer::Deserialize(
    const ASTColumnDefinitionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTColumnDefinition* node = zetasql_base::NewInArena<ASTColumnDefinition>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTColumnDefinition* node, const ASTColumnDefinitionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_schema()) {
    node->AddChild(Deserialize(proto.schema(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTableElementList* node,
                                            ASTTableElementListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->elements().length(); i++) {
    const ASTTableElement* elements_ = node->elements().at(i);
    AnyASTTableElementProto* proto2 = proto->add_elements();
    ZETASQL_RETURN_IF_ERROR(Serialize(elements_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTTableElementList*> ParseTreeSerializer::Deserialize(
    const ASTTableElementListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTableElementList* node = zetasql_base::NewInArena<ASTTableElementList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTableElementList* node, const ASTTableElementListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.elements_size(); i++) {
    node->AddChild(Deserialize(proto.elements(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTColumnList* node,
                                            ASTColumnListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->identifiers().length(); i++) {
    const ASTIdentifier* identifiers_ = node->identifiers().at(i);
    ASTIdentifierProto* proto2 = proto->add_identifiers();
    ZETASQL_RETURN_IF_ERROR(Serialize(identifiers_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTColumnList*> ParseTreeSerializer::Deserialize(
    const ASTColumnListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTColumnList* node = zetasql_base::NewInArena<ASTColumnList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTColumnList* node, const ASTColumnListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.identifiers_size(); i++) {
    node->AddChild(Deserialize(proto.identifiers(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTColumnPosition* node,
                                            ASTColumnPositionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->identifier_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->identifier_, proto->mutable_identifier()));
  }
  proto->set_type(static_cast<ASTColumnPositionEnums_RelativePositionType>(node->type_));
  return absl::OkStatus();
}
absl::StatusOr<ASTColumnPosition*> ParseTreeSerializer::Deserialize(
    const ASTColumnPositionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTColumnPosition* node = zetasql_base::NewInArena<ASTColumnPosition>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTColumnPosition* node, const ASTColumnPositionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_identifier()) {
    node->AddChild(Deserialize(proto.identifier(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->type_ = static_cast<ASTColumnPosition::RelativePositionType>(proto.type());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTInsertValuesRow* node,
                                            ASTInsertValuesRowProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->values().length(); i++) {
    const ASTExpression* values_ = node->values().at(i);
    AnyASTExpressionProto* proto2 = proto->add_values();
    ZETASQL_RETURN_IF_ERROR(Serialize(values_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTInsertValuesRow*> ParseTreeSerializer::Deserialize(
    const ASTInsertValuesRowProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTInsertValuesRow* node = zetasql_base::NewInArena<ASTInsertValuesRow>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTInsertValuesRow* node, const ASTInsertValuesRowProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.values_size(); i++) {
    node->AddChild(Deserialize(proto.values(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTInsertValuesRowList* node,
                                            ASTInsertValuesRowListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->rows().length(); i++) {
    const ASTInsertValuesRow* rows_ = node->rows().at(i);
    ASTInsertValuesRowProto* proto2 = proto->add_rows();
    ZETASQL_RETURN_IF_ERROR(Serialize(rows_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTInsertValuesRowList*> ParseTreeSerializer::Deserialize(
    const ASTInsertValuesRowListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTInsertValuesRowList* node = zetasql_base::NewInArena<ASTInsertValuesRowList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTInsertValuesRowList* node, const ASTInsertValuesRowListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.rows_size(); i++) {
    node->AddChild(Deserialize(proto.rows(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTInsertStatement* node,
                                            ASTInsertStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->target_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->target_path_, proto->mutable_target_path()));
  }
  if (node->column_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->column_list_, proto->mutable_column_list()));
  }
  if (node->rows_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->rows_, proto->mutable_rows()));
  }
  if (node->query_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->query_, proto->mutable_query()));
  }
  if (node->assert_rows_modified_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->assert_rows_modified_, proto->mutable_assert_rows_modified()));
  }
  if (node->returning_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->returning_, proto->mutable_returning()));
  }
  proto->set_parse_progress(static_cast<ASTInsertStatementEnums_ParseProgress>(node->parse_progress_));
  proto->set_insert_mode(static_cast<ASTInsertStatementEnums_InsertMode>(node->insert_mode_));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTInsertStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTInsertStatementProto* ast_insert_statement_proto =
      proto->mutable_ast_insert_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_insert_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTInsertStatement*> ParseTreeSerializer::Deserialize(
    const ASTInsertStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTInsertStatement* node = zetasql_base::NewInArena<ASTInsertStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTInsertStatement* node, const ASTInsertStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_target_path()) {
    node->AddChild(Deserialize(proto.target_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_column_list()) {
    node->AddChild(Deserialize(proto.column_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_rows()) {
    node->AddChild(Deserialize(proto.rows(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_query()) {
    node->AddChild(Deserialize(proto.query(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_assert_rows_modified()) {
    node->AddChild(Deserialize(proto.assert_rows_modified(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_returning()) {
    node->AddChild(Deserialize(proto.returning(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->parse_progress_ = static_cast<ASTInsertStatement::ParseProgress>(proto.parse_progress());
  node->insert_mode_ = static_cast<ASTInsertStatement::InsertMode>(proto.insert_mode());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTUpdateSetValue* node,
                                            ASTUpdateSetValueProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->path_, proto->mutable_path()));
  }
  if (node->value_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->value_, proto->mutable_value()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTUpdateSetValue*> ParseTreeSerializer::Deserialize(
    const ASTUpdateSetValueProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTUpdateSetValue* node = zetasql_base::NewInArena<ASTUpdateSetValue>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTUpdateSetValue* node, const ASTUpdateSetValueProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_path()) {
    node->AddChild(Deserialize(proto.path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_value()) {
    node->AddChild(Deserialize(proto.value(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTUpdateItem* node,
                                            ASTUpdateItemProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->set_value_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->set_value_, proto->mutable_set_value()));
  }
  if (node->insert_statement_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->insert_statement_, proto->mutable_insert_statement()));
  }
  if (node->delete_statement_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->delete_statement_, proto->mutable_delete_statement()));
  }
  if (node->update_statement_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->update_statement_, proto->mutable_update_statement()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTUpdateItem*> ParseTreeSerializer::Deserialize(
    const ASTUpdateItemProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTUpdateItem* node = zetasql_base::NewInArena<ASTUpdateItem>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTUpdateItem* node, const ASTUpdateItemProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_set_value()) {
    node->AddChild(Deserialize(proto.set_value(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_insert_statement()) {
    node->AddChild(Deserialize(proto.insert_statement(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_delete_statement()) {
    node->AddChild(Deserialize(proto.delete_statement(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_update_statement()) {
    node->AddChild(Deserialize(proto.update_statement(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTUpdateItemList* node,
                                            ASTUpdateItemListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->update_items().length(); i++) {
    const ASTUpdateItem* update_items_ = node->update_items().at(i);
    ASTUpdateItemProto* proto2 = proto->add_update_items();
    ZETASQL_RETURN_IF_ERROR(Serialize(update_items_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTUpdateItemList*> ParseTreeSerializer::Deserialize(
    const ASTUpdateItemListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTUpdateItemList* node = zetasql_base::NewInArena<ASTUpdateItemList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTUpdateItemList* node, const ASTUpdateItemListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.update_items_size(); i++) {
    node->AddChild(Deserialize(proto.update_items(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTUpdateStatement* node,
                                            ASTUpdateStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->target_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->target_path_, proto->mutable_target_path()));
  }
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  if (node->offset_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->offset_, proto->mutable_offset()));
  }
  if (node->update_item_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->update_item_list_, proto->mutable_update_item_list()));
  }
  if (node->from_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->from_clause_, proto->mutable_from_clause()));
  }
  if (node->where_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->where_, proto->mutable_where()));
  }
  if (node->assert_rows_modified_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->assert_rows_modified_, proto->mutable_assert_rows_modified()));
  }
  if (node->returning_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->returning_, proto->mutable_returning()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTUpdateStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTUpdateStatementProto* ast_update_statement_proto =
      proto->mutable_ast_update_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_update_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTUpdateStatement*> ParseTreeSerializer::Deserialize(
    const ASTUpdateStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTUpdateStatement* node = zetasql_base::NewInArena<ASTUpdateStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTUpdateStatement* node, const ASTUpdateStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_target_path()) {
    node->AddChild(Deserialize(proto.target_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_offset()) {
    node->AddChild(Deserialize(proto.offset(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_update_item_list()) {
    node->AddChild(Deserialize(proto.update_item_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_from_clause()) {
    node->AddChild(Deserialize(proto.from_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_where()) {
    node->AddChild(Deserialize(proto.where(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_assert_rows_modified()) {
    node->AddChild(Deserialize(proto.assert_rows_modified(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_returning()) {
    node->AddChild(Deserialize(proto.returning(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTruncateStatement* node,
                                            ASTTruncateStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->target_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->target_path_, proto->mutable_target_path()));
  }
  if (node->where_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->where_, proto->mutable_where()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTTruncateStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTTruncateStatementProto* ast_truncate_statement_proto =
      proto->mutable_ast_truncate_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_truncate_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTTruncateStatement*> ParseTreeSerializer::Deserialize(
    const ASTTruncateStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTTruncateStatement* node = zetasql_base::NewInArena<ASTTruncateStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTruncateStatement* node, const ASTTruncateStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_target_path()) {
    node->AddChild(Deserialize(proto.target_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_where()) {
    node->AddChild(Deserialize(proto.where(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTMergeAction* node,
                                            ASTMergeActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->insert_column_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->insert_column_list_, proto->mutable_insert_column_list()));
  }
  if (node->insert_row_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->insert_row_, proto->mutable_insert_row()));
  }
  if (node->update_item_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->update_item_list_, proto->mutable_update_item_list()));
  }
  proto->set_action_type(static_cast<ASTMergeActionEnums_ActionType>(node->action_type_));
  return absl::OkStatus();
}
absl::StatusOr<ASTMergeAction*> ParseTreeSerializer::Deserialize(
    const ASTMergeActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTMergeAction* node = zetasql_base::NewInArena<ASTMergeAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTMergeAction* node, const ASTMergeActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_insert_column_list()) {
    node->AddChild(Deserialize(proto.insert_column_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_insert_row()) {
    node->AddChild(Deserialize(proto.insert_row(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_update_item_list()) {
    node->AddChild(Deserialize(proto.update_item_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->action_type_ = static_cast<ASTMergeAction::ActionType>(proto.action_type());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTMergeWhenClause* node,
                                            ASTMergeWhenClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->search_condition_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->search_condition_, proto->mutable_search_condition()));
  }
  if (node->action_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->action_, proto->mutable_action()));
  }
  proto->set_match_type(static_cast<ASTMergeWhenClauseEnums_MatchType>(node->match_type_));
  return absl::OkStatus();
}
absl::StatusOr<ASTMergeWhenClause*> ParseTreeSerializer::Deserialize(
    const ASTMergeWhenClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTMergeWhenClause* node = zetasql_base::NewInArena<ASTMergeWhenClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTMergeWhenClause* node, const ASTMergeWhenClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_search_condition()) {
    node->AddChild(Deserialize(proto.search_condition(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_action()) {
    node->AddChild(Deserialize(proto.action(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->match_type_ = static_cast<ASTMergeWhenClause::MatchType>(proto.match_type());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTMergeWhenClauseList* node,
                                            ASTMergeWhenClauseListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->clause_list().length(); i++) {
    const ASTMergeWhenClause* clause_list_ = node->clause_list().at(i);
    ASTMergeWhenClauseProto* proto2 = proto->add_clause_list();
    ZETASQL_RETURN_IF_ERROR(Serialize(clause_list_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTMergeWhenClauseList*> ParseTreeSerializer::Deserialize(
    const ASTMergeWhenClauseListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTMergeWhenClauseList* node = zetasql_base::NewInArena<ASTMergeWhenClauseList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTMergeWhenClauseList* node, const ASTMergeWhenClauseListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.clause_list_size(); i++) {
    node->AddChild(Deserialize(proto.clause_list(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTMergeStatement* node,
                                            ASTMergeStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->target_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->target_path_, proto->mutable_target_path()));
  }
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  if (node->table_expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->table_expression_, proto->mutable_table_expression()));
  }
  if (node->merge_condition_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->merge_condition_, proto->mutable_merge_condition()));
  }
  if (node->when_clauses_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->when_clauses_, proto->mutable_when_clauses()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTMergeStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTMergeStatementProto* ast_merge_statement_proto =
      proto->mutable_ast_merge_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_merge_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTMergeStatement*> ParseTreeSerializer::Deserialize(
    const ASTMergeStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTMergeStatement* node = zetasql_base::NewInArena<ASTMergeStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTMergeStatement* node, const ASTMergeStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_target_path()) {
    node->AddChild(Deserialize(proto.target_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_table_expression()) {
    node->AddChild(Deserialize(proto.table_expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_merge_condition()) {
    node->AddChild(Deserialize(proto.merge_condition(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_when_clauses()) {
    node->AddChild(Deserialize(proto.when_clauses(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTPrivilege* node,
                                            ASTPrivilegeProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->privilege_action_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->privilege_action_, proto->mutable_privilege_action()));
  }
  if (node->paths_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->paths_, proto->mutable_paths()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTPrivilege*> ParseTreeSerializer::Deserialize(
    const ASTPrivilegeProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTPrivilege* node = zetasql_base::NewInArena<ASTPrivilege>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTPrivilege* node, const ASTPrivilegeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_privilege_action()) {
    node->AddChild(Deserialize(proto.privilege_action(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_paths()) {
    node->AddChild(Deserialize(proto.paths(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTPrivileges* node,
                                            ASTPrivilegesProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->privileges().length(); i++) {
    const ASTPrivilege* privileges_ = node->privileges().at(i);
    ASTPrivilegeProto* proto2 = proto->add_privileges();
    ZETASQL_RETURN_IF_ERROR(Serialize(privileges_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTPrivileges*> ParseTreeSerializer::Deserialize(
    const ASTPrivilegesProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTPrivileges* node = zetasql_base::NewInArena<ASTPrivileges>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTPrivileges* node, const ASTPrivilegesProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.privileges_size(); i++) {
    node->AddChild(Deserialize(proto.privileges(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTGranteeList* node,
                                            ASTGranteeListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->grantee_list().length(); i++) {
    const ASTExpression* grantee_list_ = node->grantee_list().at(i);
    AnyASTExpressionProto* proto2 = proto->add_grantee_list();
    ZETASQL_RETURN_IF_ERROR(Serialize(grantee_list_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTGranteeList*> ParseTreeSerializer::Deserialize(
    const ASTGranteeListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTGranteeList* node = zetasql_base::NewInArena<ASTGranteeList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTGranteeList* node, const ASTGranteeListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.grantee_list_size(); i++) {
    node->AddChild(Deserialize(proto.grantee_list(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTGrantStatement* node,
                                            ASTGrantStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->privileges_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->privileges_, proto->mutable_privileges()));
  }
  if (node->target_type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->target_type_, proto->mutable_target_type()));
  }
  if (node->target_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->target_path_, proto->mutable_target_path()));
  }
  if (node->grantee_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->grantee_list_, proto->mutable_grantee_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTGrantStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTGrantStatementProto* ast_grant_statement_proto =
      proto->mutable_ast_grant_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_grant_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTGrantStatement*> ParseTreeSerializer::Deserialize(
    const ASTGrantStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTGrantStatement* node = zetasql_base::NewInArena<ASTGrantStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTGrantStatement* node, const ASTGrantStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_privileges()) {
    node->AddChild(Deserialize(proto.privileges(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_target_type()) {
    node->AddChild(Deserialize(proto.target_type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_target_path()) {
    node->AddChild(Deserialize(proto.target_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_grantee_list()) {
    node->AddChild(Deserialize(proto.grantee_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTRevokeStatement* node,
                                            ASTRevokeStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->privileges_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->privileges_, proto->mutable_privileges()));
  }
  if (node->target_type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->target_type_, proto->mutable_target_type()));
  }
  if (node->target_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->target_path_, proto->mutable_target_path()));
  }
  if (node->grantee_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->grantee_list_, proto->mutable_grantee_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTRevokeStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTRevokeStatementProto* ast_revoke_statement_proto =
      proto->mutable_ast_revoke_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_revoke_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTRevokeStatement*> ParseTreeSerializer::Deserialize(
    const ASTRevokeStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTRevokeStatement* node = zetasql_base::NewInArena<ASTRevokeStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTRevokeStatement* node, const ASTRevokeStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_privileges()) {
    node->AddChild(Deserialize(proto.privileges(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_target_type()) {
    node->AddChild(Deserialize(proto.target_type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_target_path()) {
    node->AddChild(Deserialize(proto.target_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_grantee_list()) {
    node->AddChild(Deserialize(proto.grantee_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTRepeatableClause* node,
                                            ASTRepeatableClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->argument_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->argument_, proto->mutable_argument()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTRepeatableClause*> ParseTreeSerializer::Deserialize(
    const ASTRepeatableClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTRepeatableClause* node = zetasql_base::NewInArena<ASTRepeatableClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTRepeatableClause* node, const ASTRepeatableClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_argument()) {
    node->AddChild(Deserialize(proto.argument(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTFilterFieldsArg* node,
                                            ASTFilterFieldsArgProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->path_expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->path_expression_, proto->mutable_path_expression()));
  }
  proto->set_filter_type(static_cast<ASTFilterFieldsArgEnums_FilterType>(node->filter_type_));
  return absl::OkStatus();
}
absl::StatusOr<ASTFilterFieldsArg*> ParseTreeSerializer::Deserialize(
    const ASTFilterFieldsArgProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTFilterFieldsArg* node = zetasql_base::NewInArena<ASTFilterFieldsArg>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTFilterFieldsArg* node, const ASTFilterFieldsArgProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_path_expression()) {
    node->AddChild(Deserialize(proto.path_expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->filter_type_ = static_cast<ASTFilterFieldsArg::FilterType>(proto.filter_type());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTReplaceFieldsArg* node,
                                            ASTReplaceFieldsArgProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  if (node->path_expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->path_expression_, proto->mutable_path_expression()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTReplaceFieldsArg*> ParseTreeSerializer::Deserialize(
    const ASTReplaceFieldsArgProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTReplaceFieldsArg* node = zetasql_base::NewInArena<ASTReplaceFieldsArg>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTReplaceFieldsArg* node, const ASTReplaceFieldsArgProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_path_expression()) {
    node->AddChild(Deserialize(proto.path_expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTReplaceFieldsExpression* node,
                                            ASTReplaceFieldsExpressionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expr_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expr_, proto->mutable_expr()));
  }
  for (int i = 0; i < node->arguments().length(); i++) {
    const ASTReplaceFieldsArg* arguments_ = node->arguments().at(i);
    ASTReplaceFieldsArgProto* proto2 = proto->add_arguments();
    ZETASQL_RETURN_IF_ERROR(Serialize(arguments_, proto2));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTReplaceFieldsExpression* node,
                                           AnyASTExpressionProto* proto) {
  ASTReplaceFieldsExpressionProto* ast_replace_fields_expression_proto =
      proto->mutable_ast_replace_fields_expression_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_replace_fields_expression_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTReplaceFieldsExpression*> ParseTreeSerializer::Deserialize(
    const ASTReplaceFieldsExpressionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTReplaceFieldsExpression* node = zetasql_base::NewInArena<ASTReplaceFieldsExpression>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTReplaceFieldsExpression* node, const ASTReplaceFieldsExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expr()) {
    node->AddChild(Deserialize(proto.expr(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  for (int i=0; i < proto.arguments_size(); i++) {
    node->AddChild(Deserialize(proto.arguments(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSampleSize* node,
                                            ASTSampleSizeProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->size_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->size_, proto->mutable_size()));
  }
  if (node->partition_by_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->partition_by_, proto->mutable_partition_by()));
  }
  proto->set_unit(static_cast<ASTSampleSizeEnums_Unit>(node->unit_));
  return absl::OkStatus();
}
absl::StatusOr<ASTSampleSize*> ParseTreeSerializer::Deserialize(
    const ASTSampleSizeProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSampleSize* node = zetasql_base::NewInArena<ASTSampleSize>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSampleSize* node, const ASTSampleSizeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_size()) {
    node->AddChild(Deserialize(proto.size(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_partition_by()) {
    node->AddChild(Deserialize(proto.partition_by(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->unit_ = static_cast<ASTSampleSize::Unit>(proto.unit());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWithWeight* node,
                                            ASTWithWeightProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTWithWeight*> ParseTreeSerializer::Deserialize(
    const ASTWithWeightProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWithWeight* node = zetasql_base::NewInArena<ASTWithWeight>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWithWeight* node, const ASTWithWeightProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSampleSuffix* node,
                                            ASTSampleSuffixProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->weight_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->weight_, proto->mutable_weight()));
  }
  if (node->repeat_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->repeat_, proto->mutable_repeat()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTSampleSuffix*> ParseTreeSerializer::Deserialize(
    const ASTSampleSuffixProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSampleSuffix* node = zetasql_base::NewInArena<ASTSampleSuffix>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSampleSuffix* node, const ASTSampleSuffixProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_weight()) {
    node->AddChild(Deserialize(proto.weight(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_repeat()) {
    node->AddChild(Deserialize(proto.repeat(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSampleClause* node,
                                            ASTSampleClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->sample_method_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->sample_method_, proto->mutable_sample_method()));
  }
  if (node->sample_size_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->sample_size_, proto->mutable_sample_size()));
  }
  if (node->sample_suffix_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->sample_suffix_, proto->mutable_sample_suffix()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTSampleClause*> ParseTreeSerializer::Deserialize(
    const ASTSampleClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSampleClause* node = zetasql_base::NewInArena<ASTSampleClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSampleClause* node, const ASTSampleClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_sample_method()) {
    node->AddChild(Deserialize(proto.sample_method(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_sample_size()) {
    node->AddChild(Deserialize(proto.sample_size(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_sample_suffix()) {
    node->AddChild(Deserialize(proto.sample_suffix(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterAction* node,
                                            ASTAlterActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterAction* node,
                                           AnyASTAlterActionProto* proto) {
  if (dynamic_cast<const ASTSetOptionsAction*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTSetOptionsAction*>(node),
                              proto->mutable_ast_set_options_action_node()));
  } else if (dynamic_cast<const ASTSetAsAction*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTSetAsAction*>(node),
                              proto->mutable_ast_set_as_action_node()));
  } else if (dynamic_cast<const ASTAddConstraintAction*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAddConstraintAction*>(node),
                              proto->mutable_ast_add_constraint_action_node()));
  } else if (dynamic_cast<const ASTDropPrimaryKeyAction*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDropPrimaryKeyAction*>(node),
                              proto->mutable_ast_drop_primary_key_action_node()));
  } else if (dynamic_cast<const ASTDropConstraintAction*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDropConstraintAction*>(node),
                              proto->mutable_ast_drop_constraint_action_node()));
  } else if (dynamic_cast<const ASTAlterConstraintEnforcementAction*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterConstraintEnforcementAction*>(node),
                              proto->mutable_ast_alter_constraint_enforcement_action_node()));
  } else if (dynamic_cast<const ASTAlterConstraintSetOptionsAction*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterConstraintSetOptionsAction*>(node),
                              proto->mutable_ast_alter_constraint_set_options_action_node()));
  } else if (dynamic_cast<const ASTAddColumnAction*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAddColumnAction*>(node),
                              proto->mutable_ast_add_column_action_node()));
  } else if (dynamic_cast<const ASTDropColumnAction*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTDropColumnAction*>(node),
                              proto->mutable_ast_drop_column_action_node()));
  } else if (dynamic_cast<const ASTRenameColumnAction*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTRenameColumnAction*>(node),
                              proto->mutable_ast_rename_column_action_node()));
  } else if (dynamic_cast<const ASTAlterColumnTypeAction*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterColumnTypeAction*>(node),
                              proto->mutable_ast_alter_column_type_action_node()));
  } else if (dynamic_cast<const ASTAlterColumnOptionsAction*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterColumnOptionsAction*>(node),
                              proto->mutable_ast_alter_column_options_action_node()));
  } else if (dynamic_cast<const ASTAlterColumnDropNotNullAction*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterColumnDropNotNullAction*>(node),
                              proto->mutable_ast_alter_column_drop_not_null_action_node()));
  } else if (dynamic_cast<const ASTGrantToClause*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTGrantToClause*>(node),
                              proto->mutable_ast_grant_to_clause_node()));
  } else if (dynamic_cast<const ASTFilterUsingClause*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTFilterUsingClause*>(node),
                              proto->mutable_ast_filter_using_clause_node()));
  } else if (dynamic_cast<const ASTRevokeFromClause*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTRevokeFromClause*>(node),
                              proto->mutable_ast_revoke_from_clause_node()));
  } else if (dynamic_cast<const ASTRenameToClause*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTRenameToClause*>(node),
                              proto->mutable_ast_rename_to_clause_node()));
  } else if (dynamic_cast<const ASTSetCollateClause*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTSetCollateClause*>(node),
                              proto->mutable_ast_set_collate_clause_node()));
  } else if (dynamic_cast<const ASTAlterColumnSetDefaultAction*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterColumnSetDefaultAction*>(node),
                              proto->mutable_ast_alter_column_set_default_action_node()));
  } else if (dynamic_cast<const ASTAlterColumnDropDefaultAction*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterColumnDropDefaultAction*>(node),
                              proto->mutable_ast_alter_column_drop_default_action_node()));
  } else if (dynamic_cast<const ASTRestrictToClause*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTRestrictToClause*>(node),
                              proto->mutable_ast_restrict_to_clause_node()));
  } else if (dynamic_cast<const ASTAddToRestricteeListClause*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAddToRestricteeListClause*>(node),
                              proto->mutable_ast_add_to_restrictee_list_clause_node()));
  } else if (dynamic_cast<const ASTRemoveFromRestricteeListClause*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTRemoveFromRestricteeListClause*>(node),
                              proto->mutable_ast_remove_from_restrictee_list_clause_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTAlterAction");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterAction*> ParseTreeSerializer::Deserialize(
    const AnyASTAlterActionProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTAlterActionProto::kAstSetOptionsActionNode: {
      return Deserialize(
          proto.ast_set_options_action_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstSetAsActionNode: {
      return Deserialize(
          proto.ast_set_as_action_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstAddConstraintActionNode: {
      return Deserialize(
          proto.ast_add_constraint_action_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstDropPrimaryKeyActionNode: {
      return Deserialize(
          proto.ast_drop_primary_key_action_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstDropConstraintActionNode: {
      return Deserialize(
          proto.ast_drop_constraint_action_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstAlterConstraintEnforcementActionNode: {
      return Deserialize(
          proto.ast_alter_constraint_enforcement_action_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstAlterConstraintSetOptionsActionNode: {
      return Deserialize(
          proto.ast_alter_constraint_set_options_action_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstAddColumnActionNode: {
      return Deserialize(
          proto.ast_add_column_action_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstDropColumnActionNode: {
      return Deserialize(
          proto.ast_drop_column_action_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstRenameColumnActionNode: {
      return Deserialize(
          proto.ast_rename_column_action_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstAlterColumnTypeActionNode: {
      return Deserialize(
          proto.ast_alter_column_type_action_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstAlterColumnOptionsActionNode: {
      return Deserialize(
          proto.ast_alter_column_options_action_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstAlterColumnDropNotNullActionNode: {
      return Deserialize(
          proto.ast_alter_column_drop_not_null_action_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstGrantToClauseNode: {
      return Deserialize(
          proto.ast_grant_to_clause_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstFilterUsingClauseNode: {
      return Deserialize(
          proto.ast_filter_using_clause_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstRevokeFromClauseNode: {
      return Deserialize(
          proto.ast_revoke_from_clause_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstRenameToClauseNode: {
      return Deserialize(
          proto.ast_rename_to_clause_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstSetCollateClauseNode: {
      return Deserialize(
          proto.ast_set_collate_clause_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstAlterColumnSetDefaultActionNode: {
      return Deserialize(
          proto.ast_alter_column_set_default_action_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstAlterColumnDropDefaultActionNode: {
      return Deserialize(
          proto.ast_alter_column_drop_default_action_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstRestrictToClauseNode: {
      return Deserialize(
          proto.ast_restrict_to_clause_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstAddToRestricteeListClauseNode: {
      return Deserialize(
          proto.ast_add_to_restrictee_list_clause_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::kAstRemoveFromRestricteeListClauseNode: {
      return Deserialize(
          proto.ast_remove_from_restrictee_list_clause_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterActionProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTAlterAction* node, const ASTAlterActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterAction* node, const ASTAlterActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSetOptionsAction* node,
                                            ASTSetOptionsActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTSetOptionsAction* node,
                                           AnyASTAlterActionProto* proto) {
  ASTSetOptionsActionProto* ast_set_options_action_proto =
      proto->mutable_ast_set_options_action_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_set_options_action_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTSetOptionsAction*> ParseTreeSerializer::Deserialize(
    const ASTSetOptionsActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSetOptionsAction* node = zetasql_base::NewInArena<ASTSetOptionsAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSetOptionsAction* node, const ASTSetOptionsActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSetAsAction* node,
                                            ASTSetAsActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->json_body_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->json_body_, proto->mutable_json_body()));
  }
  if (node->text_body_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->text_body_, proto->mutable_text_body()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTSetAsAction* node,
                                           AnyASTAlterActionProto* proto) {
  ASTSetAsActionProto* ast_set_as_action_proto =
      proto->mutable_ast_set_as_action_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_set_as_action_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTSetAsAction*> ParseTreeSerializer::Deserialize(
    const ASTSetAsActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSetAsAction* node = zetasql_base::NewInArena<ASTSetAsAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSetAsAction* node, const ASTSetAsActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_json_body()) {
    node->AddChild(Deserialize(proto.json_body(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_text_body()) {
    node->AddChild(Deserialize(proto.text_body(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAddConstraintAction* node,
                                            ASTAddConstraintActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->constraint_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->constraint_, proto->mutable_constraint()));
  }
  proto->set_is_if_not_exists(node->is_if_not_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAddConstraintAction* node,
                                           AnyASTAlterActionProto* proto) {
  ASTAddConstraintActionProto* ast_add_constraint_action_proto =
      proto->mutable_ast_add_constraint_action_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_add_constraint_action_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAddConstraintAction*> ParseTreeSerializer::Deserialize(
    const ASTAddConstraintActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAddConstraintAction* node = zetasql_base::NewInArena<ASTAddConstraintAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAddConstraintAction* node, const ASTAddConstraintActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_constraint()) {
    node->AddChild(Deserialize(proto.constraint(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_not_exists_ = proto.is_if_not_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDropPrimaryKeyAction* node,
                                            ASTDropPrimaryKeyActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropPrimaryKeyAction* node,
                                           AnyASTAlterActionProto* proto) {
  ASTDropPrimaryKeyActionProto* ast_drop_primary_key_action_proto =
      proto->mutable_ast_drop_primary_key_action_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_drop_primary_key_action_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDropPrimaryKeyAction*> ParseTreeSerializer::Deserialize(
    const ASTDropPrimaryKeyActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDropPrimaryKeyAction* node = zetasql_base::NewInArena<ASTDropPrimaryKeyAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDropPrimaryKeyAction* node, const ASTDropPrimaryKeyActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDropConstraintAction* node,
                                            ASTDropConstraintActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->constraint_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->constraint_name_, proto->mutable_constraint_name()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropConstraintAction* node,
                                           AnyASTAlterActionProto* proto) {
  ASTDropConstraintActionProto* ast_drop_constraint_action_proto =
      proto->mutable_ast_drop_constraint_action_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_drop_constraint_action_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDropConstraintAction*> ParseTreeSerializer::Deserialize(
    const ASTDropConstraintActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDropConstraintAction* node = zetasql_base::NewInArena<ASTDropConstraintAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDropConstraintAction* node, const ASTDropConstraintActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_constraint_name()) {
    node->AddChild(Deserialize(proto.constraint_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterConstraintEnforcementAction* node,
                                            ASTAlterConstraintEnforcementActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->constraint_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->constraint_name_, proto->mutable_constraint_name()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  proto->set_is_enforced(node->is_enforced_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterConstraintEnforcementAction* node,
                                           AnyASTAlterActionProto* proto) {
  ASTAlterConstraintEnforcementActionProto* ast_alter_constraint_enforcement_action_proto =
      proto->mutable_ast_alter_constraint_enforcement_action_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_constraint_enforcement_action_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterConstraintEnforcementAction*> ParseTreeSerializer::Deserialize(
    const ASTAlterConstraintEnforcementActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterConstraintEnforcementAction* node = zetasql_base::NewInArena<ASTAlterConstraintEnforcementAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterConstraintEnforcementAction* node, const ASTAlterConstraintEnforcementActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_constraint_name()) {
    node->AddChild(Deserialize(proto.constraint_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  node->is_enforced_ = proto.is_enforced();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterConstraintSetOptionsAction* node,
                                            ASTAlterConstraintSetOptionsActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->constraint_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->constraint_name_, proto->mutable_constraint_name()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterConstraintSetOptionsAction* node,
                                           AnyASTAlterActionProto* proto) {
  ASTAlterConstraintSetOptionsActionProto* ast_alter_constraint_set_options_action_proto =
      proto->mutable_ast_alter_constraint_set_options_action_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_constraint_set_options_action_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterConstraintSetOptionsAction*> ParseTreeSerializer::Deserialize(
    const ASTAlterConstraintSetOptionsActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterConstraintSetOptionsAction* node = zetasql_base::NewInArena<ASTAlterConstraintSetOptionsAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterConstraintSetOptionsAction* node, const ASTAlterConstraintSetOptionsActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_constraint_name()) {
    node->AddChild(Deserialize(proto.constraint_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAddColumnAction* node,
                                            ASTAddColumnActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->column_definition_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->column_definition_, proto->mutable_column_definition()));
  }
  if (node->column_position_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->column_position_, proto->mutable_column_position()));
  }
  if (node->fill_expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->fill_expression_, proto->mutable_fill_expression()));
  }
  proto->set_is_if_not_exists(node->is_if_not_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAddColumnAction* node,
                                           AnyASTAlterActionProto* proto) {
  ASTAddColumnActionProto* ast_add_column_action_proto =
      proto->mutable_ast_add_column_action_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_add_column_action_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAddColumnAction*> ParseTreeSerializer::Deserialize(
    const ASTAddColumnActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAddColumnAction* node = zetasql_base::NewInArena<ASTAddColumnAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAddColumnAction* node, const ASTAddColumnActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_column_definition()) {
    node->AddChild(Deserialize(proto.column_definition(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_column_position()) {
    node->AddChild(Deserialize(proto.column_position(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_fill_expression()) {
    node->AddChild(Deserialize(proto.fill_expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_not_exists_ = proto.is_if_not_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDropColumnAction* node,
                                            ASTDropColumnActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->column_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->column_name_, proto->mutable_column_name()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropColumnAction* node,
                                           AnyASTAlterActionProto* proto) {
  ASTDropColumnActionProto* ast_drop_column_action_proto =
      proto->mutable_ast_drop_column_action_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_drop_column_action_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDropColumnAction*> ParseTreeSerializer::Deserialize(
    const ASTDropColumnActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDropColumnAction* node = zetasql_base::NewInArena<ASTDropColumnAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDropColumnAction* node, const ASTDropColumnActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_column_name()) {
    node->AddChild(Deserialize(proto.column_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTRenameColumnAction* node,
                                            ASTRenameColumnActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->column_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->column_name_, proto->mutable_column_name()));
  }
  if (node->new_column_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->new_column_name_, proto->mutable_new_column_name()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTRenameColumnAction* node,
                                           AnyASTAlterActionProto* proto) {
  ASTRenameColumnActionProto* ast_rename_column_action_proto =
      proto->mutable_ast_rename_column_action_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_rename_column_action_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTRenameColumnAction*> ParseTreeSerializer::Deserialize(
    const ASTRenameColumnActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTRenameColumnAction* node = zetasql_base::NewInArena<ASTRenameColumnAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTRenameColumnAction* node, const ASTRenameColumnActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_column_name()) {
    node->AddChild(Deserialize(proto.column_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_new_column_name()) {
    node->AddChild(Deserialize(proto.new_column_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterColumnTypeAction* node,
                                            ASTAlterColumnTypeActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->column_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->column_name_, proto->mutable_column_name()));
  }
  if (node->schema_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->schema_, proto->mutable_schema()));
  }
  if (node->collate_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->collate_, proto->mutable_collate()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterColumnTypeAction* node,
                                           AnyASTAlterActionProto* proto) {
  ASTAlterColumnTypeActionProto* ast_alter_column_type_action_proto =
      proto->mutable_ast_alter_column_type_action_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_column_type_action_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterColumnTypeAction*> ParseTreeSerializer::Deserialize(
    const ASTAlterColumnTypeActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterColumnTypeAction* node = zetasql_base::NewInArena<ASTAlterColumnTypeAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterColumnTypeAction* node, const ASTAlterColumnTypeActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_column_name()) {
    node->AddChild(Deserialize(proto.column_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_schema()) {
    node->AddChild(Deserialize(proto.schema(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_collate()) {
    node->AddChild(Deserialize(proto.collate(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterColumnOptionsAction* node,
                                            ASTAlterColumnOptionsActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->column_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->column_name_, proto->mutable_column_name()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterColumnOptionsAction* node,
                                           AnyASTAlterActionProto* proto) {
  ASTAlterColumnOptionsActionProto* ast_alter_column_options_action_proto =
      proto->mutable_ast_alter_column_options_action_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_column_options_action_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterColumnOptionsAction*> ParseTreeSerializer::Deserialize(
    const ASTAlterColumnOptionsActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterColumnOptionsAction* node = zetasql_base::NewInArena<ASTAlterColumnOptionsAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterColumnOptionsAction* node, const ASTAlterColumnOptionsActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_column_name()) {
    node->AddChild(Deserialize(proto.column_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterColumnSetDefaultAction* node,
                                            ASTAlterColumnSetDefaultActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->column_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->column_name_, proto->mutable_column_name()));
  }
  if (node->default_expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->default_expression_, proto->mutable_default_expression()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterColumnSetDefaultAction* node,
                                           AnyASTAlterActionProto* proto) {
  ASTAlterColumnSetDefaultActionProto* ast_alter_column_set_default_action_proto =
      proto->mutable_ast_alter_column_set_default_action_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_column_set_default_action_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterColumnSetDefaultAction*> ParseTreeSerializer::Deserialize(
    const ASTAlterColumnSetDefaultActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterColumnSetDefaultAction* node = zetasql_base::NewInArena<ASTAlterColumnSetDefaultAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterColumnSetDefaultAction* node, const ASTAlterColumnSetDefaultActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_column_name()) {
    node->AddChild(Deserialize(proto.column_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_default_expression()) {
    node->AddChild(Deserialize(proto.default_expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterColumnDropDefaultAction* node,
                                            ASTAlterColumnDropDefaultActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->column_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->column_name_, proto->mutable_column_name()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterColumnDropDefaultAction* node,
                                           AnyASTAlterActionProto* proto) {
  ASTAlterColumnDropDefaultActionProto* ast_alter_column_drop_default_action_proto =
      proto->mutable_ast_alter_column_drop_default_action_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_column_drop_default_action_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterColumnDropDefaultAction*> ParseTreeSerializer::Deserialize(
    const ASTAlterColumnDropDefaultActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterColumnDropDefaultAction* node = zetasql_base::NewInArena<ASTAlterColumnDropDefaultAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterColumnDropDefaultAction* node, const ASTAlterColumnDropDefaultActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_column_name()) {
    node->AddChild(Deserialize(proto.column_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterColumnDropNotNullAction* node,
                                            ASTAlterColumnDropNotNullActionProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->column_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->column_name_, proto->mutable_column_name()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterColumnDropNotNullAction* node,
                                           AnyASTAlterActionProto* proto) {
  ASTAlterColumnDropNotNullActionProto* ast_alter_column_drop_not_null_action_proto =
      proto->mutable_ast_alter_column_drop_not_null_action_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_column_drop_not_null_action_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterColumnDropNotNullAction*> ParseTreeSerializer::Deserialize(
    const ASTAlterColumnDropNotNullActionProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterColumnDropNotNullAction* node = zetasql_base::NewInArena<ASTAlterColumnDropNotNullAction>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterColumnDropNotNullAction* node, const ASTAlterColumnDropNotNullActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_column_name()) {
    node->AddChild(Deserialize(proto.column_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTGrantToClause* node,
                                            ASTGrantToClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->grantee_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->grantee_list_, proto->mutable_grantee_list()));
  }
  proto->set_has_grant_keyword_and_parens(node->has_grant_keyword_and_parens_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTGrantToClause* node,
                                           AnyASTAlterActionProto* proto) {
  ASTGrantToClauseProto* ast_grant_to_clause_proto =
      proto->mutable_ast_grant_to_clause_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_grant_to_clause_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTGrantToClause*> ParseTreeSerializer::Deserialize(
    const ASTGrantToClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTGrantToClause* node = zetasql_base::NewInArena<ASTGrantToClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTGrantToClause* node, const ASTGrantToClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_grantee_list()) {
    node->AddChild(Deserialize(proto.grantee_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->has_grant_keyword_and_parens_ = proto.has_grant_keyword_and_parens();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTRestrictToClause* node,
                                            ASTRestrictToClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->restrictee_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->restrictee_list_, proto->mutable_restrictee_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTRestrictToClause* node,
                                           AnyASTAlterActionProto* proto) {
  ASTRestrictToClauseProto* ast_restrict_to_clause_proto =
      proto->mutable_ast_restrict_to_clause_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_restrict_to_clause_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTRestrictToClause*> ParseTreeSerializer::Deserialize(
    const ASTRestrictToClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTRestrictToClause* node = zetasql_base::NewInArena<ASTRestrictToClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTRestrictToClause* node, const ASTRestrictToClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_restrictee_list()) {
    node->AddChild(Deserialize(proto.restrictee_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAddToRestricteeListClause* node,
                                            ASTAddToRestricteeListClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_is_if_not_exists(node->is_if_not_exists_);
  if (node->restrictee_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->restrictee_list_, proto->mutable_restrictee_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAddToRestricteeListClause* node,
                                           AnyASTAlterActionProto* proto) {
  ASTAddToRestricteeListClauseProto* ast_add_to_restrictee_list_clause_proto =
      proto->mutable_ast_add_to_restrictee_list_clause_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_add_to_restrictee_list_clause_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAddToRestricteeListClause*> ParseTreeSerializer::Deserialize(
    const ASTAddToRestricteeListClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAddToRestricteeListClause* node = zetasql_base::NewInArena<ASTAddToRestricteeListClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAddToRestricteeListClause* node, const ASTAddToRestricteeListClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->is_if_not_exists_ = proto.is_if_not_exists();
  if (proto.has_restrictee_list()) {
    node->AddChild(Deserialize(proto.restrictee_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTRemoveFromRestricteeListClause* node,
                                            ASTRemoveFromRestricteeListClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_is_if_exists(node->is_if_exists_);
  if (node->restrictee_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->restrictee_list_, proto->mutable_restrictee_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTRemoveFromRestricteeListClause* node,
                                           AnyASTAlterActionProto* proto) {
  ASTRemoveFromRestricteeListClauseProto* ast_remove_from_restrictee_list_clause_proto =
      proto->mutable_ast_remove_from_restrictee_list_clause_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_remove_from_restrictee_list_clause_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTRemoveFromRestricteeListClause*> ParseTreeSerializer::Deserialize(
    const ASTRemoveFromRestricteeListClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTRemoveFromRestricteeListClause* node = zetasql_base::NewInArena<ASTRemoveFromRestricteeListClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTRemoveFromRestricteeListClause* node, const ASTRemoveFromRestricteeListClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->is_if_exists_ = proto.is_if_exists();
  if (proto.has_restrictee_list()) {
    node->AddChild(Deserialize(proto.restrictee_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTFilterUsingClause* node,
                                            ASTFilterUsingClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->predicate_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->predicate_, proto->mutable_predicate()));
  }
  proto->set_has_filter_keyword(node->has_filter_keyword_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTFilterUsingClause* node,
                                           AnyASTAlterActionProto* proto) {
  ASTFilterUsingClauseProto* ast_filter_using_clause_proto =
      proto->mutable_ast_filter_using_clause_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_filter_using_clause_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTFilterUsingClause*> ParseTreeSerializer::Deserialize(
    const ASTFilterUsingClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTFilterUsingClause* node = zetasql_base::NewInArena<ASTFilterUsingClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTFilterUsingClause* node, const ASTFilterUsingClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_predicate()) {
    node->AddChild(Deserialize(proto.predicate(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->has_filter_keyword_ = proto.has_filter_keyword();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTRevokeFromClause* node,
                                            ASTRevokeFromClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->revoke_from_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->revoke_from_list_, proto->mutable_revoke_from_list()));
  }
  proto->set_is_revoke_from_all(node->is_revoke_from_all_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTRevokeFromClause* node,
                                           AnyASTAlterActionProto* proto) {
  ASTRevokeFromClauseProto* ast_revoke_from_clause_proto =
      proto->mutable_ast_revoke_from_clause_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_revoke_from_clause_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTRevokeFromClause*> ParseTreeSerializer::Deserialize(
    const ASTRevokeFromClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTRevokeFromClause* node = zetasql_base::NewInArena<ASTRevokeFromClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTRevokeFromClause* node, const ASTRevokeFromClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_revoke_from_list()) {
    node->AddChild(Deserialize(proto.revoke_from_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_revoke_from_all_ = proto.is_revoke_from_all();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTRenameToClause* node,
                                            ASTRenameToClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->new_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->new_name_, proto->mutable_new_name()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTRenameToClause* node,
                                           AnyASTAlterActionProto* proto) {
  ASTRenameToClauseProto* ast_rename_to_clause_proto =
      proto->mutable_ast_rename_to_clause_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_rename_to_clause_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTRenameToClause*> ParseTreeSerializer::Deserialize(
    const ASTRenameToClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTRenameToClause* node = zetasql_base::NewInArena<ASTRenameToClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTRenameToClause* node, const ASTRenameToClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_new_name()) {
    node->AddChild(Deserialize(proto.new_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSetCollateClause* node,
                                            ASTSetCollateClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->collate_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->collate_, proto->mutable_collate()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTSetCollateClause* node,
                                           AnyASTAlterActionProto* proto) {
  ASTSetCollateClauseProto* ast_set_collate_clause_proto =
      proto->mutable_ast_set_collate_clause_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_set_collate_clause_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTSetCollateClause*> ParseTreeSerializer::Deserialize(
    const ASTSetCollateClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSetCollateClause* node = zetasql_base::NewInArena<ASTSetCollateClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSetCollateClause* node, const ASTSetCollateClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_collate()) {
    node->AddChild(Deserialize(proto.collate(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterActionList* node,
                                            ASTAlterActionListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->actions().length(); i++) {
    const ASTAlterAction* actions_ = node->actions().at(i);
    AnyASTAlterActionProto* proto2 = proto->add_actions();
    ZETASQL_RETURN_IF_ERROR(Serialize(actions_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterActionList*> ParseTreeSerializer::Deserialize(
    const ASTAlterActionListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterActionList* node = zetasql_base::NewInArena<ASTAlterActionList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterActionList* node, const ASTAlterActionListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.actions_size(); i++) {
    node->AddChild(Deserialize(proto.actions(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterAllRowAccessPoliciesStatement* node,
                                            ASTAlterAllRowAccessPoliciesStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->table_name_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->table_name_path_, proto->mutable_table_name_path()));
  }
  if (node->alter_action_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alter_action_, proto->mutable_alter_action()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterAllRowAccessPoliciesStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTAlterAllRowAccessPoliciesStatementProto* ast_alter_all_row_access_policies_statement_proto =
      proto->mutable_ast_alter_all_row_access_policies_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_all_row_access_policies_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterAllRowAccessPoliciesStatement*> ParseTreeSerializer::Deserialize(
    const ASTAlterAllRowAccessPoliciesStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterAllRowAccessPoliciesStatement* node = zetasql_base::NewInArena<ASTAlterAllRowAccessPoliciesStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterAllRowAccessPoliciesStatement* node, const ASTAlterAllRowAccessPoliciesStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_table_name_path()) {
    node->AddChild(Deserialize(proto.table_name_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alter_action()) {
    node->AddChild(Deserialize(proto.alter_action(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTForeignKeyActions* node,
                                            ASTForeignKeyActionsProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_update_action(static_cast<ASTForeignKeyActionsEnums_Action>(node->update_action_));
  proto->set_delete_action(static_cast<ASTForeignKeyActionsEnums_Action>(node->delete_action_));
  return absl::OkStatus();
}
absl::StatusOr<ASTForeignKeyActions*> ParseTreeSerializer::Deserialize(
    const ASTForeignKeyActionsProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTForeignKeyActions* node = zetasql_base::NewInArena<ASTForeignKeyActions>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTForeignKeyActions* node, const ASTForeignKeyActionsProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->update_action_ = static_cast<ASTForeignKeyActions::Action>(proto.update_action());
  node->delete_action_ = static_cast<ASTForeignKeyActions::Action>(proto.delete_action());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTForeignKeyReference* node,
                                            ASTForeignKeyReferenceProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->table_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->table_name_, proto->mutable_table_name()));
  }
  if (node->column_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->column_list_, proto->mutable_column_list()));
  }
  if (node->actions_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->actions_, proto->mutable_actions()));
  }
  proto->set_match(static_cast<ASTForeignKeyReferenceEnums_Match>(node->match_));
  proto->set_enforced(node->enforced_);
  return absl::OkStatus();
}
absl::StatusOr<ASTForeignKeyReference*> ParseTreeSerializer::Deserialize(
    const ASTForeignKeyReferenceProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTForeignKeyReference* node = zetasql_base::NewInArena<ASTForeignKeyReference>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTForeignKeyReference* node, const ASTForeignKeyReferenceProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_table_name()) {
    node->AddChild(Deserialize(proto.table_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_column_list()) {
    node->AddChild(Deserialize(proto.column_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_actions()) {
    node->AddChild(Deserialize(proto.actions(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->match_ = static_cast<ASTForeignKeyReference::Match>(proto.match());
  node->enforced_ = proto.enforced();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTScript* node,
                                            ASTScriptProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->statement_list_node_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->statement_list_node_, proto->mutable_statement_list_node()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTScript*> ParseTreeSerializer::Deserialize(
    const ASTScriptProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTScript* node = zetasql_base::NewInArena<ASTScript>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTScript* node, const ASTScriptProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_statement_list_node()) {
    node->AddChild(Deserialize(proto.statement_list_node(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTElseifClause* node,
                                            ASTElseifClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->condition_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->condition_, proto->mutable_condition()));
  }
  if (node->body_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->body_, proto->mutable_body()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTElseifClause*> ParseTreeSerializer::Deserialize(
    const ASTElseifClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTElseifClause* node = zetasql_base::NewInArena<ASTElseifClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTElseifClause* node, const ASTElseifClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_condition()) {
    node->AddChild(Deserialize(proto.condition(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_body()) {
    node->AddChild(Deserialize(proto.body(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTElseifClauseList* node,
                                            ASTElseifClauseListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->elseif_clauses().length(); i++) {
    const ASTElseifClause* elseif_clauses_ = node->elseif_clauses().at(i);
    ASTElseifClauseProto* proto2 = proto->add_elseif_clauses();
    ZETASQL_RETURN_IF_ERROR(Serialize(elseif_clauses_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTElseifClauseList*> ParseTreeSerializer::Deserialize(
    const ASTElseifClauseListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTElseifClauseList* node = zetasql_base::NewInArena<ASTElseifClauseList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTElseifClauseList* node, const ASTElseifClauseListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.elseif_clauses_size(); i++) {
    node->AddChild(Deserialize(proto.elseif_clauses(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTIfStatement* node,
                                            ASTIfStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->condition_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->condition_, proto->mutable_condition()));
  }
  if (node->then_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->then_list_, proto->mutable_then_list()));
  }
  if (node->elseif_clauses_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->elseif_clauses_, proto->mutable_elseif_clauses()));
  }
  if (node->else_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->else_list_, proto->mutable_else_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTIfStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTIfStatement* node,
                                           AnyASTScriptStatementProto* proto) {
  ASTIfStatementProto* ast_if_statement_proto =
      proto->mutable_ast_if_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_if_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTIfStatement*> ParseTreeSerializer::Deserialize(
    const ASTIfStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTIfStatement* node = zetasql_base::NewInArena<ASTIfStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTIfStatement* node, const ASTIfStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_condition()) {
    node->AddChild(Deserialize(proto.condition(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_then_list()) {
    node->AddChild(Deserialize(proto.then_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_elseif_clauses()) {
    node->AddChild(Deserialize(proto.elseif_clauses(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_else_list()) {
    node->AddChild(Deserialize(proto.else_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWhenThenClause* node,
                                            ASTWhenThenClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->condition_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->condition_, proto->mutable_condition()));
  }
  if (node->body_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->body_, proto->mutable_body()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTWhenThenClause*> ParseTreeSerializer::Deserialize(
    const ASTWhenThenClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWhenThenClause* node = zetasql_base::NewInArena<ASTWhenThenClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWhenThenClause* node, const ASTWhenThenClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_condition()) {
    node->AddChild(Deserialize(proto.condition(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_body()) {
    node->AddChild(Deserialize(proto.body(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWhenThenClauseList* node,
                                            ASTWhenThenClauseListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->when_then_clauses().length(); i++) {
    const ASTWhenThenClause* when_then_clauses_ = node->when_then_clauses().at(i);
    ASTWhenThenClauseProto* proto2 = proto->add_when_then_clauses();
    ZETASQL_RETURN_IF_ERROR(Serialize(when_then_clauses_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTWhenThenClauseList*> ParseTreeSerializer::Deserialize(
    const ASTWhenThenClauseListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWhenThenClauseList* node = zetasql_base::NewInArena<ASTWhenThenClauseList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWhenThenClauseList* node, const ASTWhenThenClauseListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.when_then_clauses_size(); i++) {
    node->AddChild(Deserialize(proto.when_then_clauses(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCaseStatement* node,
                                            ASTCaseStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  if (node->when_then_clauses_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->when_then_clauses_, proto->mutable_when_then_clauses()));
  }
  if (node->else_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->else_list_, proto->mutable_else_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCaseStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCaseStatement* node,
                                           AnyASTScriptStatementProto* proto) {
  ASTCaseStatementProto* ast_case_statement_proto =
      proto->mutable_ast_case_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_case_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCaseStatement*> ParseTreeSerializer::Deserialize(
    const ASTCaseStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCaseStatement* node = zetasql_base::NewInArena<ASTCaseStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCaseStatement* node, const ASTCaseStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_when_then_clauses()) {
    node->AddChild(Deserialize(proto.when_then_clauses(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_else_list()) {
    node->AddChild(Deserialize(proto.else_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTHint* node,
                                            ASTHintProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->num_shards_hint_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->num_shards_hint_, proto->mutable_num_shards_hint()));
  }
  for (int i = 0; i < node->hint_entries().length(); i++) {
    const ASTHintEntry* hint_entries_ = node->hint_entries().at(i);
    ASTHintEntryProto* proto2 = proto->add_hint_entries();
    ZETASQL_RETURN_IF_ERROR(Serialize(hint_entries_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTHint*> ParseTreeSerializer::Deserialize(
    const ASTHintProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTHint* node = zetasql_base::NewInArena<ASTHint>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTHint* node, const ASTHintProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_num_shards_hint()) {
    node->AddChild(Deserialize(proto.num_shards_hint(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  for (int i=0; i < proto.hint_entries_size(); i++) {
    node->AddChild(Deserialize(proto.hint_entries(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTHintEntry* node,
                                            ASTHintEntryProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->qualifier_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->qualifier_, proto->mutable_qualifier()));
  }
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->value_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->value_, proto->mutable_value()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTHintEntry*> ParseTreeSerializer::Deserialize(
    const ASTHintEntryProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTHintEntry* node = zetasql_base::NewInArena<ASTHintEntry>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTHintEntry* node, const ASTHintEntryProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_qualifier()) {
    node->AddChild(Deserialize(proto.qualifier(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_value()) {
    node->AddChild(Deserialize(proto.value(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTUnpivotInItemLabel* node,
                                            ASTUnpivotInItemLabelProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->string_label_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->string_label_, proto->mutable_string_label()));
  }
  if (node->int_label_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->int_label_, proto->mutable_int_label()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTUnpivotInItemLabel*> ParseTreeSerializer::Deserialize(
    const ASTUnpivotInItemLabelProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTUnpivotInItemLabel* node = zetasql_base::NewInArena<ASTUnpivotInItemLabel>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTUnpivotInItemLabel* node, const ASTUnpivotInItemLabelProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_string_label()) {
    node->AddChild(Deserialize(proto.string_label(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_int_label()) {
    node->AddChild(Deserialize(proto.int_label(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDescriptor* node,
                                            ASTDescriptorProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->columns_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->columns_, proto->mutable_columns()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTDescriptor*> ParseTreeSerializer::Deserialize(
    const ASTDescriptorProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDescriptor* node = zetasql_base::NewInArena<ASTDescriptor>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDescriptor* node, const ASTDescriptorProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_columns()) {
    node->AddChild(Deserialize(proto.columns(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTColumnSchema* node,
                                            ASTColumnSchemaProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->type_parameters_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_parameters_, proto->mutable_type_parameters()));
  }
  if (node->generated_column_info_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->generated_column_info_, proto->mutable_generated_column_info()));
  }
  if (node->default_expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->default_expression_, proto->mutable_default_expression()));
  }
  if (node->collate_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->collate_, proto->mutable_collate()));
  }
  if (node->attributes_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->attributes_, proto->mutable_attributes()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTColumnSchema* node,
                                           AnyASTColumnSchemaProto* proto) {
  if (dynamic_cast<const ASTSimpleColumnSchema*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTSimpleColumnSchema*>(node),
                              proto->mutable_ast_simple_column_schema_node()));
  } else if (dynamic_cast<const ASTArrayColumnSchema*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTArrayColumnSchema*>(node),
                              proto->mutable_ast_array_column_schema_node()));
  } else if (dynamic_cast<const ASTStructColumnSchema*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTStructColumnSchema*>(node),
                              proto->mutable_ast_struct_column_schema_node()));
  } else if (dynamic_cast<const ASTInferredTypeColumnSchema*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTInferredTypeColumnSchema*>(node),
                              proto->mutable_ast_inferred_type_column_schema_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTColumnSchema");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTColumnSchema*> ParseTreeSerializer::Deserialize(
    const AnyASTColumnSchemaProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTColumnSchemaProto::kAstSimpleColumnSchemaNode: {
      return Deserialize(
          proto.ast_simple_column_schema_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTColumnSchemaProto::kAstArrayColumnSchemaNode: {
      return Deserialize(
          proto.ast_array_column_schema_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTColumnSchemaProto::kAstStructColumnSchemaNode: {
      return Deserialize(
          proto.ast_struct_column_schema_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTColumnSchemaProto::kAstInferredTypeColumnSchemaNode: {
      return Deserialize(
          proto.ast_inferred_type_column_schema_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTColumnSchemaProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTColumnSchema* node, const ASTColumnSchemaProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTColumnSchema* node, const ASTColumnSchemaProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_type_parameters()) {
    node->AddChild(Deserialize(proto.type_parameters(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_generated_column_info()) {
    node->AddChild(Deserialize(proto.generated_column_info(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_default_expression()) {
    node->AddChild(Deserialize(proto.default_expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_collate()) {
    node->AddChild(Deserialize(proto.collate(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_attributes()) {
    node->AddChild(Deserialize(proto.attributes(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSimpleColumnSchema* node,
                                            ASTSimpleColumnSchemaProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->type_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_name_, proto->mutable_type_name()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTSimpleColumnSchema* node,
                                           AnyASTColumnSchemaProto* proto) {
  ASTSimpleColumnSchemaProto* ast_simple_column_schema_proto =
      proto->mutable_ast_simple_column_schema_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_simple_column_schema_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTSimpleColumnSchema*> ParseTreeSerializer::Deserialize(
    const ASTSimpleColumnSchemaProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSimpleColumnSchema* node = zetasql_base::NewInArena<ASTSimpleColumnSchema>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSimpleColumnSchema* node, const ASTSimpleColumnSchemaProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_type_name()) {
    node->AddChild(Deserialize(proto.type_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTArrayColumnSchema* node,
                                            ASTArrayColumnSchemaProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->element_schema_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->element_schema_, proto->mutable_element_schema()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTArrayColumnSchema* node,
                                           AnyASTColumnSchemaProto* proto) {
  ASTArrayColumnSchemaProto* ast_array_column_schema_proto =
      proto->mutable_ast_array_column_schema_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_array_column_schema_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTArrayColumnSchema*> ParseTreeSerializer::Deserialize(
    const ASTArrayColumnSchemaProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTArrayColumnSchema* node = zetasql_base::NewInArena<ASTArrayColumnSchema>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTArrayColumnSchema* node, const ASTArrayColumnSchemaProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_element_schema()) {
    node->AddChild(Deserialize(proto.element_schema(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTTableConstraint* node,
                                            ASTTableConstraintProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTTableConstraint* node,
                                           AnyASTTableElementProto* proto) {
  AnyASTTableConstraintProto* ast_table_constraint_proto =
      proto->mutable_ast_table_constraint_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_table_constraint_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTTableConstraint* node,
                                           AnyASTTableConstraintProto* proto) {
  if (dynamic_cast<const ASTPrimaryKey*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTPrimaryKey*>(node),
                              proto->mutable_ast_primary_key_node()));
  } else if (dynamic_cast<const ASTForeignKey*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTForeignKey*>(node),
                              proto->mutable_ast_foreign_key_node()));
  } else if (dynamic_cast<const ASTCheckConstraint*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCheckConstraint*>(node),
                              proto->mutable_ast_check_constraint_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTTableConstraint");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTTableConstraint*> ParseTreeSerializer::Deserialize(
    const AnyASTTableConstraintProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTTableConstraintProto::kAstPrimaryKeyNode: {
      return Deserialize(
          proto.ast_primary_key_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTableConstraintProto::kAstForeignKeyNode: {
      return Deserialize(
          proto.ast_foreign_key_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTableConstraintProto::kAstCheckConstraintNode: {
      return Deserialize(
          proto.ast_check_constraint_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTTableConstraintProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTTableConstraint* node, const ASTTableConstraintProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTTableConstraint* node, const ASTTableConstraintProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTPrimaryKey* node,
                                            ASTPrimaryKeyProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->column_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->column_list_, proto->mutable_column_list()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  if (node->constraint_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->constraint_name_, proto->mutable_constraint_name()));
  }
  proto->set_enforced(node->enforced_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTPrimaryKey* node,
                                           AnyASTTableElementProto* proto) {
  AnyASTTableConstraintProto* ast_table_constraint_proto =
      proto->mutable_ast_table_constraint_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_table_constraint_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTPrimaryKey* node,
                                           AnyASTTableConstraintProto* proto) {
  ASTPrimaryKeyProto* ast_primary_key_proto =
      proto->mutable_ast_primary_key_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_primary_key_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTPrimaryKey*> ParseTreeSerializer::Deserialize(
    const ASTPrimaryKeyProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTPrimaryKey* node = zetasql_base::NewInArena<ASTPrimaryKey>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTPrimaryKey* node, const ASTPrimaryKeyProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_column_list()) {
    node->AddChild(Deserialize(proto.column_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_constraint_name()) {
    node->AddChild(Deserialize(proto.constraint_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->enforced_ = proto.enforced();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTForeignKey* node,
                                            ASTForeignKeyProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->column_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->column_list_, proto->mutable_column_list()));
  }
  if (node->reference_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->reference_, proto->mutable_reference()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  if (node->constraint_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->constraint_name_, proto->mutable_constraint_name()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTForeignKey* node,
                                           AnyASTTableElementProto* proto) {
  AnyASTTableConstraintProto* ast_table_constraint_proto =
      proto->mutable_ast_table_constraint_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_table_constraint_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTForeignKey* node,
                                           AnyASTTableConstraintProto* proto) {
  ASTForeignKeyProto* ast_foreign_key_proto =
      proto->mutable_ast_foreign_key_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_foreign_key_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTForeignKey*> ParseTreeSerializer::Deserialize(
    const ASTForeignKeyProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTForeignKey* node = zetasql_base::NewInArena<ASTForeignKey>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTForeignKey* node, const ASTForeignKeyProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_column_list()) {
    node->AddChild(Deserialize(proto.column_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_reference()) {
    node->AddChild(Deserialize(proto.reference(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_constraint_name()) {
    node->AddChild(Deserialize(proto.constraint_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCheckConstraint* node,
                                            ASTCheckConstraintProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  if (node->constraint_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->constraint_name_, proto->mutable_constraint_name()));
  }
  proto->set_is_enforced(node->is_enforced_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCheckConstraint* node,
                                           AnyASTTableElementProto* proto) {
  AnyASTTableConstraintProto* ast_table_constraint_proto =
      proto->mutable_ast_table_constraint_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_table_constraint_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCheckConstraint* node,
                                           AnyASTTableConstraintProto* proto) {
  ASTCheckConstraintProto* ast_check_constraint_proto =
      proto->mutable_ast_check_constraint_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_check_constraint_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCheckConstraint*> ParseTreeSerializer::Deserialize(
    const ASTCheckConstraintProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCheckConstraint* node = zetasql_base::NewInArena<ASTCheckConstraint>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCheckConstraint* node, const ASTCheckConstraintProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_constraint_name()) {
    node->AddChild(Deserialize(proto.constraint_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_enforced_ = proto.is_enforced();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDescriptorColumn* node,
                                            ASTDescriptorColumnProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTDescriptorColumn*> ParseTreeSerializer::Deserialize(
    const ASTDescriptorColumnProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDescriptorColumn* node = zetasql_base::NewInArena<ASTDescriptorColumn>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDescriptorColumn* node, const ASTDescriptorColumnProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDescriptorColumnList* node,
                                            ASTDescriptorColumnListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->descriptor_column_list().length(); i++) {
    const ASTDescriptorColumn* descriptor_column_list_ = node->descriptor_column_list().at(i);
    ASTDescriptorColumnProto* proto2 = proto->add_descriptor_column_list();
    ZETASQL_RETURN_IF_ERROR(Serialize(descriptor_column_list_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTDescriptorColumnList*> ParseTreeSerializer::Deserialize(
    const ASTDescriptorColumnListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDescriptorColumnList* node = zetasql_base::NewInArena<ASTDescriptorColumnList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDescriptorColumnList* node, const ASTDescriptorColumnListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.descriptor_column_list_size(); i++) {
    node->AddChild(Deserialize(proto.descriptor_column_list(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateEntityStatement* node,
                                            ASTCreateEntityStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_, proto->mutable_type()));
  }
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  if (node->json_body_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->json_body_, proto->mutable_json_body()));
  }
  if (node->text_body_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->text_body_, proto->mutable_text_body()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateEntityStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateEntityStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateEntityStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  ASTCreateEntityStatementProto* ast_create_entity_statement_proto =
      proto->mutable_ast_create_entity_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_entity_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateEntityStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreateEntityStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreateEntityStatement* node = zetasql_base::NewInArena<ASTCreateEntityStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateEntityStatement* node, const ASTCreateEntityStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_type()) {
    node->AddChild(Deserialize(proto.type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_json_body()) {
    node->AddChild(Deserialize(proto.json_body(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_text_body()) {
    node->AddChild(Deserialize(proto.text_body(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTRaiseStatement* node,
                                            ASTRaiseStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->message_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->message_, proto->mutable_message()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTRaiseStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTRaiseStatement* node,
                                           AnyASTScriptStatementProto* proto) {
  ASTRaiseStatementProto* ast_raise_statement_proto =
      proto->mutable_ast_raise_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_raise_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTRaiseStatement*> ParseTreeSerializer::Deserialize(
    const ASTRaiseStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTRaiseStatement* node = zetasql_base::NewInArena<ASTRaiseStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTRaiseStatement* node, const ASTRaiseStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_message()) {
    node->AddChild(Deserialize(proto.message(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTExceptionHandler* node,
                                            ASTExceptionHandlerProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->statement_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->statement_list_, proto->mutable_statement_list()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTExceptionHandler*> ParseTreeSerializer::Deserialize(
    const ASTExceptionHandlerProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTExceptionHandler* node = zetasql_base::NewInArena<ASTExceptionHandler>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTExceptionHandler* node, const ASTExceptionHandlerProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_statement_list()) {
    node->AddChild(Deserialize(proto.statement_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTExceptionHandlerList* node,
                                            ASTExceptionHandlerListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->exception_handler_list().length(); i++) {
    const ASTExceptionHandler* exception_handler_list_ = node->exception_handler_list().at(i);
    ASTExceptionHandlerProto* proto2 = proto->add_exception_handler_list();
    ZETASQL_RETURN_IF_ERROR(Serialize(exception_handler_list_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTExceptionHandlerList*> ParseTreeSerializer::Deserialize(
    const ASTExceptionHandlerListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTExceptionHandlerList* node = zetasql_base::NewInArena<ASTExceptionHandlerList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTExceptionHandlerList* node, const ASTExceptionHandlerListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.exception_handler_list_size(); i++) {
    node->AddChild(Deserialize(proto.exception_handler_list(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTBeginEndBlock* node,
                                            ASTBeginEndBlockProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->label_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->label_, proto->mutable_label()));
  }
  if (node->statement_list_node_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->statement_list_node_, proto->mutable_statement_list_node()));
  }
  if (node->handler_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->handler_list_, proto->mutable_handler_list()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBeginEndBlock* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBeginEndBlock* node,
                                           AnyASTScriptStatementProto* proto) {
  ASTBeginEndBlockProto* ast_begin_end_block_proto =
      proto->mutable_ast_begin_end_block_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_begin_end_block_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTBeginEndBlock*> ParseTreeSerializer::Deserialize(
    const ASTBeginEndBlockProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTBeginEndBlock* node = zetasql_base::NewInArena<ASTBeginEndBlock>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTBeginEndBlock* node, const ASTBeginEndBlockProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_label()) {
    node->AddChild(Deserialize(proto.label(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_statement_list_node()) {
    node->AddChild(Deserialize(proto.statement_list_node(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_handler_list()) {
    node->AddChild(Deserialize(proto.handler_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTIdentifierList* node,
                                            ASTIdentifierListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->identifier_list().length(); i++) {
    const ASTIdentifier* identifier_list_ = node->identifier_list().at(i);
    ASTIdentifierProto* proto2 = proto->add_identifier_list();
    ZETASQL_RETURN_IF_ERROR(Serialize(identifier_list_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTIdentifierList*> ParseTreeSerializer::Deserialize(
    const ASTIdentifierListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTIdentifierList* node = zetasql_base::NewInArena<ASTIdentifierList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTIdentifierList* node, const ASTIdentifierListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.identifier_list_size(); i++) {
    node->AddChild(Deserialize(proto.identifier_list(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTVariableDeclaration* node,
                                            ASTVariableDeclarationProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->variable_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->variable_list_, proto->mutable_variable_list()));
  }
  if (node->type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_, proto->mutable_type()));
  }
  if (node->default_value_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->default_value_, proto->mutable_default_value()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTVariableDeclaration* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTVariableDeclaration* node,
                                           AnyASTScriptStatementProto* proto) {
  ASTVariableDeclarationProto* ast_variable_declaration_proto =
      proto->mutable_ast_variable_declaration_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_variable_declaration_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTVariableDeclaration*> ParseTreeSerializer::Deserialize(
    const ASTVariableDeclarationProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTVariableDeclaration* node = zetasql_base::NewInArena<ASTVariableDeclaration>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTVariableDeclaration* node, const ASTVariableDeclarationProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_variable_list()) {
    node->AddChild(Deserialize(proto.variable_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_type()) {
    node->AddChild(Deserialize(proto.type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_default_value()) {
    node->AddChild(Deserialize(proto.default_value(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTUntilClause* node,
                                            ASTUntilClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->condition_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->condition_, proto->mutable_condition()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTUntilClause*> ParseTreeSerializer::Deserialize(
    const ASTUntilClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTUntilClause* node = zetasql_base::NewInArena<ASTUntilClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTUntilClause* node, const ASTUntilClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_condition()) {
    node->AddChild(Deserialize(proto.condition(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTBreakContinueStatement* node,
                                            ASTBreakContinueStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->label_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->label_, proto->mutable_label()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBreakContinueStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBreakContinueStatement* node,
                                           AnyASTScriptStatementProto* proto) {
  AnyASTBreakContinueStatementProto* ast_break_continue_statement_proto =
      proto->mutable_ast_break_continue_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_break_continue_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBreakContinueStatement* node,
                                           AnyASTBreakContinueStatementProto* proto) {
  if (dynamic_cast<const ASTBreakStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTBreakStatement*>(node),
                              proto->mutable_ast_break_statement_node()));
  } else if (dynamic_cast<const ASTContinueStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTContinueStatement*>(node),
                              proto->mutable_ast_continue_statement_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTBreakContinueStatement");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTBreakContinueStatement*> ParseTreeSerializer::Deserialize(
    const AnyASTBreakContinueStatementProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTBreakContinueStatementProto::kAstBreakStatementNode: {
      return Deserialize(
          proto.ast_break_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTBreakContinueStatementProto::kAstContinueStatementNode: {
      return Deserialize(
          proto.ast_continue_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTBreakContinueStatementProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTBreakContinueStatement* node, const ASTBreakContinueStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTBreakContinueStatement* node, const ASTBreakContinueStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_label()) {
    node->AddChild(Deserialize(proto.label(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTBreakStatement* node,
                                            ASTBreakStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_keyword(static_cast<ASTBreakContinueStatementEnums_BreakContinueKeyword>(node->keyword_));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBreakStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBreakStatement* node,
                                           AnyASTScriptStatementProto* proto) {
  AnyASTBreakContinueStatementProto* ast_break_continue_statement_proto =
      proto->mutable_ast_break_continue_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_break_continue_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTBreakStatement* node,
                                           AnyASTBreakContinueStatementProto* proto) {
  ASTBreakStatementProto* ast_break_statement_proto =
      proto->mutable_ast_break_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_break_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTBreakStatement*> ParseTreeSerializer::Deserialize(
    const ASTBreakStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTBreakStatement* node = zetasql_base::NewInArena<ASTBreakStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTBreakStatement* node, const ASTBreakStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->keyword_ = static_cast<ASTBreakStatement::BreakContinueKeyword>(proto.keyword());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTContinueStatement* node,
                                            ASTContinueStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_keyword(static_cast<ASTBreakContinueStatementEnums_BreakContinueKeyword>(node->keyword_));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTContinueStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTContinueStatement* node,
                                           AnyASTScriptStatementProto* proto) {
  AnyASTBreakContinueStatementProto* ast_break_continue_statement_proto =
      proto->mutable_ast_break_continue_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_break_continue_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTContinueStatement* node,
                                           AnyASTBreakContinueStatementProto* proto) {
  ASTContinueStatementProto* ast_continue_statement_proto =
      proto->mutable_ast_continue_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_continue_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTContinueStatement*> ParseTreeSerializer::Deserialize(
    const ASTContinueStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTContinueStatement* node = zetasql_base::NewInArena<ASTContinueStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTContinueStatement* node, const ASTContinueStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->keyword_ = static_cast<ASTContinueStatement::BreakContinueKeyword>(proto.keyword());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDropPrivilegeRestrictionStatement* node,
                                            ASTDropPrivilegeRestrictionStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_is_if_exists(node->is_if_exists_);
  if (node->privileges_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->privileges_, proto->mutable_privileges()));
  }
  if (node->object_type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->object_type_, proto->mutable_object_type()));
  }
  if (node->name_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_path_, proto->mutable_name_path()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropPrivilegeRestrictionStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropPrivilegeRestrictionStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  ASTDropPrivilegeRestrictionStatementProto* ast_drop_privilege_restriction_statement_proto =
      proto->mutable_ast_drop_privilege_restriction_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_drop_privilege_restriction_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDropPrivilegeRestrictionStatement*> ParseTreeSerializer::Deserialize(
    const ASTDropPrivilegeRestrictionStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDropPrivilegeRestrictionStatement* node = zetasql_base::NewInArena<ASTDropPrivilegeRestrictionStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDropPrivilegeRestrictionStatement* node, const ASTDropPrivilegeRestrictionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->is_if_exists_ = proto.is_if_exists();
  if (proto.has_privileges()) {
    node->AddChild(Deserialize(proto.privileges(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_object_type()) {
    node->AddChild(Deserialize(proto.object_type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_name_path()) {
    node->AddChild(Deserialize(proto.name_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDropRowAccessPolicyStatement* node,
                                            ASTDropRowAccessPolicyStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->table_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->table_name_, proto->mutable_table_name()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropRowAccessPolicyStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropRowAccessPolicyStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  ASTDropRowAccessPolicyStatementProto* ast_drop_row_access_policy_statement_proto =
      proto->mutable_ast_drop_row_access_policy_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_drop_row_access_policy_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDropRowAccessPolicyStatement*> ParseTreeSerializer::Deserialize(
    const ASTDropRowAccessPolicyStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDropRowAccessPolicyStatement* node = zetasql_base::NewInArena<ASTDropRowAccessPolicyStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDropRowAccessPolicyStatement* node, const ASTDropRowAccessPolicyStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_table_name()) {
    node->AddChild(Deserialize(proto.table_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreatePrivilegeRestrictionStatement* node,
                                            ASTCreatePrivilegeRestrictionStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->privileges_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->privileges_, proto->mutable_privileges()));
  }
  if (node->object_type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->object_type_, proto->mutable_object_type()));
  }
  if (node->name_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_path_, proto->mutable_name_path()));
  }
  if (node->restrict_to_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->restrict_to_, proto->mutable_restrict_to()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreatePrivilegeRestrictionStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreatePrivilegeRestrictionStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreatePrivilegeRestrictionStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  ASTCreatePrivilegeRestrictionStatementProto* ast_create_privilege_restriction_statement_proto =
      proto->mutable_ast_create_privilege_restriction_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_privilege_restriction_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreatePrivilegeRestrictionStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreatePrivilegeRestrictionStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreatePrivilegeRestrictionStatement* node = zetasql_base::NewInArena<ASTCreatePrivilegeRestrictionStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreatePrivilegeRestrictionStatement* node, const ASTCreatePrivilegeRestrictionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_privileges()) {
    node->AddChild(Deserialize(proto.privileges(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_object_type()) {
    node->AddChild(Deserialize(proto.object_type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_name_path()) {
    node->AddChild(Deserialize(proto.name_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_restrict_to()) {
    node->AddChild(Deserialize(proto.restrict_to(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateRowAccessPolicyStatement* node,
                                            ASTCreateRowAccessPolicyStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->target_path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->target_path_, proto->mutable_target_path()));
  }
  if (node->grant_to_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->grant_to_, proto->mutable_grant_to()));
  }
  if (node->filter_using_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->filter_using_, proto->mutable_filter_using()));
  }
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  proto->set_has_access_keyword(node->has_access_keyword_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateRowAccessPolicyStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateRowAccessPolicyStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateRowAccessPolicyStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  ASTCreateRowAccessPolicyStatementProto* ast_create_row_access_policy_statement_proto =
      proto->mutable_ast_create_row_access_policy_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_row_access_policy_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateRowAccessPolicyStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreateRowAccessPolicyStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreateRowAccessPolicyStatement* node = zetasql_base::NewInArena<ASTCreateRowAccessPolicyStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateRowAccessPolicyStatement* node, const ASTCreateRowAccessPolicyStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_target_path()) {
    node->AddChild(Deserialize(proto.target_path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_grant_to()) {
    node->AddChild(Deserialize(proto.grant_to(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_filter_using()) {
    node->AddChild(Deserialize(proto.filter_using(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->has_access_keyword_ = proto.has_access_keyword();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTDropStatement* node,
                                            ASTDropStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  proto->set_drop_mode(static_cast<ASTDropStatementEnums_DropMode>(node->drop_mode_));
  proto->set_is_if_exists(node->is_if_exists_);
  proto->set_schema_object_kind(static_cast<SchemaObjectKind>(node->schema_object_kind_));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTDropStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  ASTDropStatementProto* ast_drop_statement_proto =
      proto->mutable_ast_drop_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_drop_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTDropStatement*> ParseTreeSerializer::Deserialize(
    const ASTDropStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTDropStatement* node = zetasql_base::NewInArena<ASTDropStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTDropStatement* node, const ASTDropStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->drop_mode_ = static_cast<ASTDropStatement::DropMode>(proto.drop_mode());
  node->is_if_exists_ = proto.is_if_exists();
  node->schema_object_kind_ = static_cast<SchemaObjectKind>(proto.schema_object_kind());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTReturnStatement* node,
                                            ASTReturnStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTReturnStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTReturnStatement* node,
                                           AnyASTScriptStatementProto* proto) {
  ASTReturnStatementProto* ast_return_statement_proto =
      proto->mutable_ast_return_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_return_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTReturnStatement*> ParseTreeSerializer::Deserialize(
    const ASTReturnStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTReturnStatement* node = zetasql_base::NewInArena<ASTReturnStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTReturnStatement* node, const ASTReturnStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSingleAssignment* node,
                                            ASTSingleAssignmentProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->variable_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->variable_, proto->mutable_variable()));
  }
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTSingleAssignment* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTSingleAssignment* node,
                                           AnyASTScriptStatementProto* proto) {
  ASTSingleAssignmentProto* ast_single_assignment_proto =
      proto->mutable_ast_single_assignment_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_single_assignment_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTSingleAssignment*> ParseTreeSerializer::Deserialize(
    const ASTSingleAssignmentProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSingleAssignment* node = zetasql_base::NewInArena<ASTSingleAssignment>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSingleAssignment* node, const ASTSingleAssignmentProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_variable()) {
    node->AddChild(Deserialize(proto.variable(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTParameterAssignment* node,
                                            ASTParameterAssignmentProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->parameter_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->parameter_, proto->mutable_parameter()));
  }
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTParameterAssignment* node,
                                           AnyASTStatementProto* proto) {
  ASTParameterAssignmentProto* ast_parameter_assignment_proto =
      proto->mutable_ast_parameter_assignment_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_parameter_assignment_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTParameterAssignment*> ParseTreeSerializer::Deserialize(
    const ASTParameterAssignmentProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTParameterAssignment* node = zetasql_base::NewInArena<ASTParameterAssignment>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTParameterAssignment* node, const ASTParameterAssignmentProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_parameter()) {
    node->AddChild(Deserialize(proto.parameter(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTSystemVariableAssignment* node,
                                            ASTSystemVariableAssignmentProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->system_variable_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->system_variable_, proto->mutable_system_variable()));
  }
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTSystemVariableAssignment* node,
                                           AnyASTStatementProto* proto) {
  ASTSystemVariableAssignmentProto* ast_system_variable_assignment_proto =
      proto->mutable_ast_system_variable_assignment_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_system_variable_assignment_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTSystemVariableAssignment*> ParseTreeSerializer::Deserialize(
    const ASTSystemVariableAssignmentProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTSystemVariableAssignment* node = zetasql_base::NewInArena<ASTSystemVariableAssignment>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTSystemVariableAssignment* node, const ASTSystemVariableAssignmentProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_system_variable()) {
    node->AddChild(Deserialize(proto.system_variable(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAssignmentFromStruct* node,
                                            ASTAssignmentFromStructProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->variables_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->variables_, proto->mutable_variables()));
  }
  if (node->struct_expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->struct_expression_, proto->mutable_struct_expression()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAssignmentFromStruct* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAssignmentFromStruct* node,
                                           AnyASTScriptStatementProto* proto) {
  ASTAssignmentFromStructProto* ast_assignment_from_struct_proto =
      proto->mutable_ast_assignment_from_struct_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_assignment_from_struct_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAssignmentFromStruct*> ParseTreeSerializer::Deserialize(
    const ASTAssignmentFromStructProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAssignmentFromStruct* node = zetasql_base::NewInArena<ASTAssignmentFromStruct>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAssignmentFromStruct* node, const ASTAssignmentFromStructProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_variables()) {
    node->AddChild(Deserialize(proto.variables(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_struct_expression()) {
    node->AddChild(Deserialize(proto.struct_expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateTableStmtBase* node,
                                            ASTCreateTableStmtBaseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->table_element_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->table_element_list_, proto->mutable_table_element_list()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  if (node->like_table_name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->like_table_name_, proto->mutable_like_table_name()));
  }
  if (node->collate_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->collate_, proto->mutable_collate()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateTableStmtBase* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateTableStmtBase* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateTableStmtBase* node,
                                           AnyASTCreateStatementProto* proto) {
  AnyASTCreateTableStmtBaseProto* ast_create_table_stmt_base_proto =
      proto->mutable_ast_create_table_stmt_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_table_stmt_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateTableStmtBase* node,
                                           AnyASTCreateTableStmtBaseProto* proto) {
  if (dynamic_cast<const ASTCreateTableStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateTableStatement*>(node),
                              proto->mutable_ast_create_table_statement_node()));
  } else if (dynamic_cast<const ASTCreateExternalTableStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateExternalTableStatement*>(node),
                              proto->mutable_ast_create_external_table_statement_node()));
  } else if (dynamic_cast<const ASTAuxLoadDataStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAuxLoadDataStatement*>(node),
                              proto->mutable_ast_aux_load_data_statement_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTCreateTableStmtBase");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateTableStmtBase*> ParseTreeSerializer::Deserialize(
    const AnyASTCreateTableStmtBaseProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTCreateTableStmtBaseProto::kAstCreateTableStatementNode: {
      return Deserialize(
          proto.ast_create_table_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateTableStmtBaseProto::kAstCreateExternalTableStatementNode: {
      return Deserialize(
          proto.ast_create_external_table_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateTableStmtBaseProto::kAstAuxLoadDataStatementNode: {
      return Deserialize(
          proto.ast_aux_load_data_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateTableStmtBaseProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTCreateTableStmtBase* node, const ASTCreateTableStmtBaseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateTableStmtBase* node, const ASTCreateTableStmtBaseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_table_element_list()) {
    node->AddChild(Deserialize(proto.table_element_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_like_table_name()) {
    node->AddChild(Deserialize(proto.like_table_name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_collate()) {
    node->AddChild(Deserialize(proto.collate(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateTableStatement* node,
                                            ASTCreateTableStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->clone_data_source_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->clone_data_source_, proto->mutable_clone_data_source()));
  }
  if (node->copy_data_source_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->copy_data_source_, proto->mutable_copy_data_source()));
  }
  if (node->partition_by_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->partition_by_, proto->mutable_partition_by()));
  }
  if (node->cluster_by_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->cluster_by_, proto->mutable_cluster_by()));
  }
  if (node->query_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->query_, proto->mutable_query()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateTableStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateTableStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateTableStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  AnyASTCreateTableStmtBaseProto* ast_create_table_stmt_base_proto =
      proto->mutable_ast_create_table_stmt_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_table_stmt_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateTableStatement* node,
                                           AnyASTCreateTableStmtBaseProto* proto) {
  ASTCreateTableStatementProto* ast_create_table_statement_proto =
      proto->mutable_ast_create_table_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_table_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateTableStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreateTableStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreateTableStatement* node = zetasql_base::NewInArena<ASTCreateTableStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateTableStatement* node, const ASTCreateTableStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_clone_data_source()) {
    node->AddChild(Deserialize(proto.clone_data_source(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_copy_data_source()) {
    node->AddChild(Deserialize(proto.copy_data_source(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_partition_by()) {
    node->AddChild(Deserialize(proto.partition_by(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_cluster_by()) {
    node->AddChild(Deserialize(proto.cluster_by(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_query()) {
    node->AddChild(Deserialize(proto.query(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateExternalTableStatement* node,
                                            ASTCreateExternalTableStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->with_partition_columns_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->with_partition_columns_clause_, proto->mutable_with_partition_columns_clause()));
  }
  if (node->with_connection_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->with_connection_clause_, proto->mutable_with_connection_clause()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateExternalTableStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateExternalTableStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateExternalTableStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  AnyASTCreateTableStmtBaseProto* ast_create_table_stmt_base_proto =
      proto->mutable_ast_create_table_stmt_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_table_stmt_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateExternalTableStatement* node,
                                           AnyASTCreateTableStmtBaseProto* proto) {
  ASTCreateExternalTableStatementProto* ast_create_external_table_statement_proto =
      proto->mutable_ast_create_external_table_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_external_table_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateExternalTableStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreateExternalTableStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreateExternalTableStatement* node = zetasql_base::NewInArena<ASTCreateExternalTableStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateExternalTableStatement* node, const ASTCreateExternalTableStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_with_partition_columns_clause()) {
    node->AddChild(Deserialize(proto.with_partition_columns_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_with_connection_clause()) {
    node->AddChild(Deserialize(proto.with_connection_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateViewStatementBase* node,
                                            ASTCreateViewStatementBaseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  if (node->column_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->column_list_, proto->mutable_column_list()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  if (node->query_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->query_, proto->mutable_query()));
  }
  proto->set_sql_security(static_cast<ASTCreateStatementEnums_SqlSecurity>(node->sql_security_));
  proto->set_recursive(node->recursive_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateViewStatementBase* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateViewStatementBase* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateViewStatementBase* node,
                                           AnyASTCreateStatementProto* proto) {
  AnyASTCreateViewStatementBaseProto* ast_create_view_statement_base_proto =
      proto->mutable_ast_create_view_statement_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_view_statement_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateViewStatementBase* node,
                                           AnyASTCreateViewStatementBaseProto* proto) {
  if (dynamic_cast<const ASTCreateViewStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateViewStatement*>(node),
                              proto->mutable_ast_create_view_statement_node()));
  } else if (dynamic_cast<const ASTCreateMaterializedViewStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateMaterializedViewStatement*>(node),
                              proto->mutable_ast_create_materialized_view_statement_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTCreateViewStatementBase");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateViewStatementBase*> ParseTreeSerializer::Deserialize(
    const AnyASTCreateViewStatementBaseProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTCreateViewStatementBaseProto::kAstCreateViewStatementNode: {
      return Deserialize(
          proto.ast_create_view_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateViewStatementBaseProto::kAstCreateMaterializedViewStatementNode: {
      return Deserialize(
          proto.ast_create_materialized_view_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateViewStatementBaseProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTCreateViewStatementBase* node, const ASTCreateViewStatementBaseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateViewStatementBase* node, const ASTCreateViewStatementBaseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_column_list()) {
    node->AddChild(Deserialize(proto.column_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_query()) {
    node->AddChild(Deserialize(proto.query(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->sql_security_ = static_cast<ASTCreateViewStatementBase::SqlSecurity>(proto.sql_security());
  node->recursive_ = proto.recursive();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateViewStatement* node,
                                            ASTCreateViewStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateViewStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateViewStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateViewStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  AnyASTCreateViewStatementBaseProto* ast_create_view_statement_base_proto =
      proto->mutable_ast_create_view_statement_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_view_statement_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateViewStatement* node,
                                           AnyASTCreateViewStatementBaseProto* proto) {
  ASTCreateViewStatementProto* ast_create_view_statement_proto =
      proto->mutable_ast_create_view_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_view_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateViewStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreateViewStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreateViewStatement* node = zetasql_base::NewInArena<ASTCreateViewStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateViewStatement* node, const ASTCreateViewStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateMaterializedViewStatement* node,
                                            ASTCreateMaterializedViewStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->partition_by_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->partition_by_, proto->mutable_partition_by()));
  }
  if (node->cluster_by_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->cluster_by_, proto->mutable_cluster_by()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateMaterializedViewStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateMaterializedViewStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateMaterializedViewStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  AnyASTCreateViewStatementBaseProto* ast_create_view_statement_base_proto =
      proto->mutable_ast_create_view_statement_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_view_statement_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateMaterializedViewStatement* node,
                                           AnyASTCreateViewStatementBaseProto* proto) {
  ASTCreateMaterializedViewStatementProto* ast_create_materialized_view_statement_proto =
      proto->mutable_ast_create_materialized_view_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_materialized_view_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateMaterializedViewStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreateMaterializedViewStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreateMaterializedViewStatement* node = zetasql_base::NewInArena<ASTCreateMaterializedViewStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateMaterializedViewStatement* node, const ASTCreateMaterializedViewStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_partition_by()) {
    node->AddChild(Deserialize(proto.partition_by(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_cluster_by()) {
    node->AddChild(Deserialize(proto.cluster_by(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTLoopStatement* node,
                                            ASTLoopStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->label_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->label_, proto->mutable_label()));
  }
  if (node->body_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->body_, proto->mutable_body()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTLoopStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTLoopStatement* node,
                                           AnyASTScriptStatementProto* proto) {
  AnyASTLoopStatementProto* ast_loop_statement_proto =
      proto->mutable_ast_loop_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_loop_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTLoopStatement* node,
                                           AnyASTLoopStatementProto* proto) {
  if (dynamic_cast<const ASTWhileStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTWhileStatement*>(node),
                              proto->mutable_ast_while_statement_node()));
  } else if (dynamic_cast<const ASTRepeatStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTRepeatStatement*>(node),
                              proto->mutable_ast_repeat_statement_node()));
  } else if (dynamic_cast<const ASTForInStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTForInStatement*>(node),
                              proto->mutable_ast_for_in_statement_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTLoopStatement");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTLoopStatement*> ParseTreeSerializer::Deserialize(
    const AnyASTLoopStatementProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTLoopStatementProto::kAstWhileStatementNode: {
      return Deserialize(
          proto.ast_while_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTLoopStatementProto::kAstRepeatStatementNode: {
      return Deserialize(
          proto.ast_repeat_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTLoopStatementProto::kAstForInStatementNode: {
      return Deserialize(
          proto.ast_for_in_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTLoopStatementProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTLoopStatement* node, const ASTLoopStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTLoopStatement* node, const ASTLoopStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_label()) {
    node->AddChild(Deserialize(proto.label(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_body()) {
    node->AddChild(Deserialize(proto.body(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTWhileStatement* node,
                                            ASTWhileStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->condition_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->condition_, proto->mutable_condition()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTWhileStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTWhileStatement* node,
                                           AnyASTScriptStatementProto* proto) {
  AnyASTLoopStatementProto* ast_loop_statement_proto =
      proto->mutable_ast_loop_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_loop_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTWhileStatement* node,
                                           AnyASTLoopStatementProto* proto) {
  ASTWhileStatementProto* ast_while_statement_proto =
      proto->mutable_ast_while_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_while_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTWhileStatement*> ParseTreeSerializer::Deserialize(
    const ASTWhileStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTWhileStatement* node = zetasql_base::NewInArena<ASTWhileStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTWhileStatement* node, const ASTWhileStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_condition()) {
    node->AddChild(Deserialize(proto.condition(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTRepeatStatement* node,
                                            ASTRepeatStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->until_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->until_clause_, proto->mutable_until_clause()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTRepeatStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTRepeatStatement* node,
                                           AnyASTScriptStatementProto* proto) {
  AnyASTLoopStatementProto* ast_loop_statement_proto =
      proto->mutable_ast_loop_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_loop_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTRepeatStatement* node,
                                           AnyASTLoopStatementProto* proto) {
  ASTRepeatStatementProto* ast_repeat_statement_proto =
      proto->mutable_ast_repeat_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_repeat_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTRepeatStatement*> ParseTreeSerializer::Deserialize(
    const ASTRepeatStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTRepeatStatement* node = zetasql_base::NewInArena<ASTRepeatStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTRepeatStatement* node, const ASTRepeatStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_until_clause()) {
    node->AddChild(Deserialize(proto.until_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTForInStatement* node,
                                            ASTForInStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->variable_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->variable_, proto->mutable_variable()));
  }
  if (node->query_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->query_, proto->mutable_query()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTForInStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTScriptStatementProto* ast_script_statement_proto =
      proto->mutable_ast_script_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_script_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTForInStatement* node,
                                           AnyASTScriptStatementProto* proto) {
  AnyASTLoopStatementProto* ast_loop_statement_proto =
      proto->mutable_ast_loop_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_loop_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTForInStatement* node,
                                           AnyASTLoopStatementProto* proto) {
  ASTForInStatementProto* ast_for_in_statement_proto =
      proto->mutable_ast_for_in_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_for_in_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTForInStatement*> ParseTreeSerializer::Deserialize(
    const ASTForInStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTForInStatement* node = zetasql_base::NewInArena<ASTForInStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTForInStatement* node, const ASTForInStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_variable()) {
    node->AddChild(Deserialize(proto.variable(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_query()) {
    node->AddChild(Deserialize(proto.query(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterStatementBase* node,
                                            ASTAlterStatementBaseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->path_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->path_, proto->mutable_path()));
  }
  if (node->action_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->action_list_, proto->mutable_action_list()));
  }
  proto->set_is_if_exists(node->is_if_exists_);
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterStatementBase* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterStatementBase* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTAlterStatementBaseProto* ast_alter_statement_base_proto =
      proto->mutable_ast_alter_statement_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_statement_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterStatementBase* node,
                                           AnyASTAlterStatementBaseProto* proto) {
  if (dynamic_cast<const ASTAlterDatabaseStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterDatabaseStatement*>(node),
                              proto->mutable_ast_alter_database_statement_node()));
  } else if (dynamic_cast<const ASTAlterSchemaStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterSchemaStatement*>(node),
                              proto->mutable_ast_alter_schema_statement_node()));
  } else if (dynamic_cast<const ASTAlterTableStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterTableStatement*>(node),
                              proto->mutable_ast_alter_table_statement_node()));
  } else if (dynamic_cast<const ASTAlterViewStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterViewStatement*>(node),
                              proto->mutable_ast_alter_view_statement_node()));
  } else if (dynamic_cast<const ASTAlterMaterializedViewStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterMaterializedViewStatement*>(node),
                              proto->mutable_ast_alter_materialized_view_statement_node()));
  } else if (dynamic_cast<const ASTAlterRowAccessPolicyStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterRowAccessPolicyStatement*>(node),
                              proto->mutable_ast_alter_row_access_policy_statement_node()));
  } else if (dynamic_cast<const ASTAlterEntityStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterEntityStatement*>(node),
                              proto->mutable_ast_alter_entity_statement_node()));
  } else if (dynamic_cast<const ASTAlterPrivilegeRestrictionStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTAlterPrivilegeRestrictionStatement*>(node),
                              proto->mutable_ast_alter_privilege_restriction_statement_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTAlterStatementBase");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterStatementBase*> ParseTreeSerializer::Deserialize(
    const AnyASTAlterStatementBaseProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTAlterStatementBaseProto::kAstAlterDatabaseStatementNode: {
      return Deserialize(
          proto.ast_alter_database_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterStatementBaseProto::kAstAlterSchemaStatementNode: {
      return Deserialize(
          proto.ast_alter_schema_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterStatementBaseProto::kAstAlterTableStatementNode: {
      return Deserialize(
          proto.ast_alter_table_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterStatementBaseProto::kAstAlterViewStatementNode: {
      return Deserialize(
          proto.ast_alter_view_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterStatementBaseProto::kAstAlterMaterializedViewStatementNode: {
      return Deserialize(
          proto.ast_alter_materialized_view_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterStatementBaseProto::kAstAlterRowAccessPolicyStatementNode: {
      return Deserialize(
          proto.ast_alter_row_access_policy_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterStatementBaseProto::kAstAlterEntityStatementNode: {
      return Deserialize(
          proto.ast_alter_entity_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterStatementBaseProto::kAstAlterPrivilegeRestrictionStatementNode: {
      return Deserialize(
          proto.ast_alter_privilege_restriction_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTAlterStatementBaseProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTAlterStatementBase* node, const ASTAlterStatementBaseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterStatementBase* node, const ASTAlterStatementBaseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_path()) {
    node->AddChild(Deserialize(proto.path(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_action_list()) {
    node->AddChild(Deserialize(proto.action_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_if_exists_ = proto.is_if_exists();
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterDatabaseStatement* node,
                                            ASTAlterDatabaseStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterDatabaseStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterDatabaseStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTAlterStatementBaseProto* ast_alter_statement_base_proto =
      proto->mutable_ast_alter_statement_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_statement_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterDatabaseStatement* node,
                                           AnyASTAlterStatementBaseProto* proto) {
  ASTAlterDatabaseStatementProto* ast_alter_database_statement_proto =
      proto->mutable_ast_alter_database_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_database_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterDatabaseStatement*> ParseTreeSerializer::Deserialize(
    const ASTAlterDatabaseStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterDatabaseStatement* node = zetasql_base::NewInArena<ASTAlterDatabaseStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterDatabaseStatement* node, const ASTAlterDatabaseStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterSchemaStatement* node,
                                            ASTAlterSchemaStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterSchemaStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterSchemaStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTAlterStatementBaseProto* ast_alter_statement_base_proto =
      proto->mutable_ast_alter_statement_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_statement_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterSchemaStatement* node,
                                           AnyASTAlterStatementBaseProto* proto) {
  ASTAlterSchemaStatementProto* ast_alter_schema_statement_proto =
      proto->mutable_ast_alter_schema_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_schema_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterSchemaStatement*> ParseTreeSerializer::Deserialize(
    const ASTAlterSchemaStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterSchemaStatement* node = zetasql_base::NewInArena<ASTAlterSchemaStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterSchemaStatement* node, const ASTAlterSchemaStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterTableStatement* node,
                                            ASTAlterTableStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterTableStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterTableStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTAlterStatementBaseProto* ast_alter_statement_base_proto =
      proto->mutable_ast_alter_statement_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_statement_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterTableStatement* node,
                                           AnyASTAlterStatementBaseProto* proto) {
  ASTAlterTableStatementProto* ast_alter_table_statement_proto =
      proto->mutable_ast_alter_table_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_table_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterTableStatement*> ParseTreeSerializer::Deserialize(
    const ASTAlterTableStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterTableStatement* node = zetasql_base::NewInArena<ASTAlterTableStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterTableStatement* node, const ASTAlterTableStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterViewStatement* node,
                                            ASTAlterViewStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterViewStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterViewStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTAlterStatementBaseProto* ast_alter_statement_base_proto =
      proto->mutable_ast_alter_statement_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_statement_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterViewStatement* node,
                                           AnyASTAlterStatementBaseProto* proto) {
  ASTAlterViewStatementProto* ast_alter_view_statement_proto =
      proto->mutable_ast_alter_view_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_view_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterViewStatement*> ParseTreeSerializer::Deserialize(
    const ASTAlterViewStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterViewStatement* node = zetasql_base::NewInArena<ASTAlterViewStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterViewStatement* node, const ASTAlterViewStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterMaterializedViewStatement* node,
                                            ASTAlterMaterializedViewStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterMaterializedViewStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterMaterializedViewStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTAlterStatementBaseProto* ast_alter_statement_base_proto =
      proto->mutable_ast_alter_statement_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_statement_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterMaterializedViewStatement* node,
                                           AnyASTAlterStatementBaseProto* proto) {
  ASTAlterMaterializedViewStatementProto* ast_alter_materialized_view_statement_proto =
      proto->mutable_ast_alter_materialized_view_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_materialized_view_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterMaterializedViewStatement*> ParseTreeSerializer::Deserialize(
    const ASTAlterMaterializedViewStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterMaterializedViewStatement* node = zetasql_base::NewInArena<ASTAlterMaterializedViewStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterMaterializedViewStatement* node, const ASTAlterMaterializedViewStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterPrivilegeRestrictionStatement* node,
                                            ASTAlterPrivilegeRestrictionStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->privileges_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->privileges_, proto->mutable_privileges()));
  }
  if (node->object_type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->object_type_, proto->mutable_object_type()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterPrivilegeRestrictionStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterPrivilegeRestrictionStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTAlterStatementBaseProto* ast_alter_statement_base_proto =
      proto->mutable_ast_alter_statement_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_statement_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterPrivilegeRestrictionStatement* node,
                                           AnyASTAlterStatementBaseProto* proto) {
  ASTAlterPrivilegeRestrictionStatementProto* ast_alter_privilege_restriction_statement_proto =
      proto->mutable_ast_alter_privilege_restriction_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_privilege_restriction_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterPrivilegeRestrictionStatement*> ParseTreeSerializer::Deserialize(
    const ASTAlterPrivilegeRestrictionStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterPrivilegeRestrictionStatement* node = zetasql_base::NewInArena<ASTAlterPrivilegeRestrictionStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterPrivilegeRestrictionStatement* node, const ASTAlterPrivilegeRestrictionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_privileges()) {
    node->AddChild(Deserialize(proto.privileges(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_object_type()) {
    node->AddChild(Deserialize(proto.object_type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterRowAccessPolicyStatement* node,
                                            ASTAlterRowAccessPolicyStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterRowAccessPolicyStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterRowAccessPolicyStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTAlterStatementBaseProto* ast_alter_statement_base_proto =
      proto->mutable_ast_alter_statement_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_statement_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterRowAccessPolicyStatement* node,
                                           AnyASTAlterStatementBaseProto* proto) {
  ASTAlterRowAccessPolicyStatementProto* ast_alter_row_access_policy_statement_proto =
      proto->mutable_ast_alter_row_access_policy_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_row_access_policy_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterRowAccessPolicyStatement*> ParseTreeSerializer::Deserialize(
    const ASTAlterRowAccessPolicyStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterRowAccessPolicyStatement* node = zetasql_base::NewInArena<ASTAlterRowAccessPolicyStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterRowAccessPolicyStatement* node, const ASTAlterRowAccessPolicyStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAlterEntityStatement* node,
                                            ASTAlterEntityStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->type_, proto->mutable_type()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterEntityStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterEntityStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTAlterStatementBaseProto* ast_alter_statement_base_proto =
      proto->mutable_ast_alter_statement_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_statement_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAlterEntityStatement* node,
                                           AnyASTAlterStatementBaseProto* proto) {
  ASTAlterEntityStatementProto* ast_alter_entity_statement_proto =
      proto->mutable_ast_alter_entity_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_alter_entity_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAlterEntityStatement*> ParseTreeSerializer::Deserialize(
    const ASTAlterEntityStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAlterEntityStatement* node = zetasql_base::NewInArena<ASTAlterEntityStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAlterEntityStatement* node, const ASTAlterEntityStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_type()) {
    node->AddChild(Deserialize(proto.type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateFunctionStmtBase* node,
                                            ASTCreateFunctionStmtBaseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->function_declaration_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->function_declaration_, proto->mutable_function_declaration()));
  }
  if (node->language_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->language_, proto->mutable_language()));
  }
  if (node->code_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->code_, proto->mutable_code()));
  }
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  proto->set_determinism_level(static_cast<ASTCreateFunctionStmtBaseEnums_DeterminismLevel>(node->determinism_level_));
  proto->set_sql_security(static_cast<ASTCreateStatementEnums_SqlSecurity>(node->sql_security_));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateFunctionStmtBase* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateFunctionStmtBase* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateFunctionStmtBase* node,
                                           AnyASTCreateStatementProto* proto) {
  AnyASTCreateFunctionStmtBaseProto* ast_create_function_stmt_base_proto =
      proto->mutable_ast_create_function_stmt_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_function_stmt_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateFunctionStmtBase* node,
                                           AnyASTCreateFunctionStmtBaseProto* proto) {
  if (dynamic_cast<const ASTCreateFunctionStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateFunctionStatement*>(node),
                              proto->mutable_ast_create_function_statement_node()));
  } else if (dynamic_cast<const ASTCreateTableFunctionStatement*>(node)) {
    ZETASQL_RETURN_IF_ERROR(Serialize(static_cast<const ASTCreateTableFunctionStatement*>(node),
                              proto->mutable_ast_create_table_function_statement_node()));
  } else {
    return absl::InvalidArgumentError("Unknown subclass of ASTCreateFunctionStmtBase");
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateFunctionStmtBase*> ParseTreeSerializer::Deserialize(
    const AnyASTCreateFunctionStmtBaseProto& proto,
          IdStringPool* id_string_pool,
          zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {

  switch (proto.node_case()) {
    case AnyASTCreateFunctionStmtBaseProto::kAstCreateFunctionStatementNode: {
      return Deserialize(
          proto.ast_create_function_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateFunctionStmtBaseProto::kAstCreateTableFunctionStatementNode: {
      return Deserialize(
          proto.ast_create_table_function_statement_node(),
          id_string_pool, arena,
          allocated_ast_nodes);
    }
    case AnyASTCreateFunctionStmtBaseProto::NODE_NOT_SET:
      break;
  }
  return absl::InvalidArgumentError("Empty proto!");
}
absl::Status ParseTreeSerializer::DeserializeAbstract(
      ASTCreateFunctionStmtBase* node, const ASTCreateFunctionStmtBaseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  return DeserializeFields(node,
                           proto,
                           id_string_pool,
                           arena,
                           allocated_ast_nodes);
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateFunctionStmtBase* node, const ASTCreateFunctionStmtBaseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_function_declaration()) {
    node->AddChild(Deserialize(proto.function_declaration(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_language()) {
    node->AddChild(Deserialize(proto.language(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_code()) {
    node->AddChild(Deserialize(proto.code(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->determinism_level_ = static_cast<ASTCreateFunctionStmtBase::DeterminismLevel>(proto.determinism_level());
  node->sql_security_ = static_cast<ASTCreateFunctionStmtBase::SqlSecurity>(proto.sql_security());
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateFunctionStatement* node,
                                            ASTCreateFunctionStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->return_type_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->return_type_, proto->mutable_return_type()));
  }
  if (node->sql_function_body_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->sql_function_body_, proto->mutable_sql_function_body()));
  }
  proto->set_is_aggregate(node->is_aggregate_);
  proto->set_is_remote(node->is_remote_);
  if (node->with_connection_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->with_connection_clause_, proto->mutable_with_connection_clause()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateFunctionStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateFunctionStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateFunctionStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  AnyASTCreateFunctionStmtBaseProto* ast_create_function_stmt_base_proto =
      proto->mutable_ast_create_function_stmt_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_function_stmt_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateFunctionStatement* node,
                                           AnyASTCreateFunctionStmtBaseProto* proto) {
  ASTCreateFunctionStatementProto* ast_create_function_statement_proto =
      proto->mutable_ast_create_function_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_function_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateFunctionStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreateFunctionStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreateFunctionStatement* node = zetasql_base::NewInArena<ASTCreateFunctionStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateFunctionStatement* node, const ASTCreateFunctionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_return_type()) {
    node->AddChild(Deserialize(proto.return_type(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_sql_function_body()) {
    node->AddChild(Deserialize(proto.sql_function_body(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  node->is_aggregate_ = proto.is_aggregate();
  node->is_remote_ = proto.is_remote();
  if (proto.has_with_connection_clause()) {
    node->AddChild(Deserialize(proto.with_connection_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTCreateTableFunctionStatement* node,
                                            ASTCreateTableFunctionStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->return_tvf_schema_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->return_tvf_schema_, proto->mutable_return_tvf_schema()));
  }
  if (node->query_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->query_, proto->mutable_query()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateTableFunctionStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateTableFunctionStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateTableFunctionStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  AnyASTCreateFunctionStmtBaseProto* ast_create_function_stmt_base_proto =
      proto->mutable_ast_create_function_stmt_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_function_stmt_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTCreateTableFunctionStatement* node,
                                           AnyASTCreateFunctionStmtBaseProto* proto) {
  ASTCreateTableFunctionStatementProto* ast_create_table_function_statement_proto =
      proto->mutable_ast_create_table_function_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_table_function_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTCreateTableFunctionStatement*> ParseTreeSerializer::Deserialize(
    const ASTCreateTableFunctionStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTCreateTableFunctionStatement* node = zetasql_base::NewInArena<ASTCreateTableFunctionStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTCreateTableFunctionStatement* node, const ASTCreateTableFunctionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_return_tvf_schema()) {
    node->AddChild(Deserialize(proto.return_tvf_schema(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_query()) {
    node->AddChild(Deserialize(proto.query(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTStructColumnSchema* node,
                                            ASTStructColumnSchemaProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->struct_fields().length(); i++) {
    const ASTStructColumnField* struct_fields_ = node->struct_fields().at(i);
    ASTStructColumnFieldProto* proto2 = proto->add_struct_fields();
    ZETASQL_RETURN_IF_ERROR(Serialize(struct_fields_, proto2));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTStructColumnSchema* node,
                                           AnyASTColumnSchemaProto* proto) {
  ASTStructColumnSchemaProto* ast_struct_column_schema_proto =
      proto->mutable_ast_struct_column_schema_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_struct_column_schema_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTStructColumnSchema*> ParseTreeSerializer::Deserialize(
    const ASTStructColumnSchemaProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTStructColumnSchema* node = zetasql_base::NewInArena<ASTStructColumnSchema>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTStructColumnSchema* node, const ASTStructColumnSchemaProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.struct_fields_size(); i++) {
    node->AddChild(Deserialize(proto.struct_fields(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTInferredTypeColumnSchema* node,
                                            ASTInferredTypeColumnSchemaProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTInferredTypeColumnSchema* node,
                                           AnyASTColumnSchemaProto* proto) {
  ASTInferredTypeColumnSchemaProto* ast_inferred_type_column_schema_proto =
      proto->mutable_ast_inferred_type_column_schema_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_inferred_type_column_schema_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTInferredTypeColumnSchema*> ParseTreeSerializer::Deserialize(
    const ASTInferredTypeColumnSchemaProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTInferredTypeColumnSchema* node = zetasql_base::NewInArena<ASTInferredTypeColumnSchema>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTInferredTypeColumnSchema* node, const ASTInferredTypeColumnSchemaProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTExecuteIntoClause* node,
                                            ASTExecuteIntoClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->identifiers_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->identifiers_, proto->mutable_identifiers()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTExecuteIntoClause*> ParseTreeSerializer::Deserialize(
    const ASTExecuteIntoClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTExecuteIntoClause* node = zetasql_base::NewInArena<ASTExecuteIntoClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTExecuteIntoClause* node, const ASTExecuteIntoClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_identifiers()) {
    node->AddChild(Deserialize(proto.identifiers(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTExecuteUsingArgument* node,
                                            ASTExecuteUsingArgumentProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->expression_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->expression_, proto->mutable_expression()));
  }
  if (node->alias_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->alias_, proto->mutable_alias()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTExecuteUsingArgument*> ParseTreeSerializer::Deserialize(
    const ASTExecuteUsingArgumentProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTExecuteUsingArgument* node = zetasql_base::NewInArena<ASTExecuteUsingArgument>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTExecuteUsingArgument* node, const ASTExecuteUsingArgumentProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_expression()) {
    node->AddChild(Deserialize(proto.expression(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_alias()) {
    node->AddChild(Deserialize(proto.alias(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTExecuteUsingClause* node,
                                            ASTExecuteUsingClauseProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  for (int i = 0; i < node->arguments().length(); i++) {
    const ASTExecuteUsingArgument* arguments_ = node->arguments().at(i);
    ASTExecuteUsingArgumentProto* proto2 = proto->add_arguments();
    ZETASQL_RETURN_IF_ERROR(Serialize(arguments_, proto2));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTExecuteUsingClause*> ParseTreeSerializer::Deserialize(
    const ASTExecuteUsingClauseProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTExecuteUsingClause* node = zetasql_base::NewInArena<ASTExecuteUsingClause>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTExecuteUsingClause* node, const ASTExecuteUsingClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  for (int i=0; i < proto.arguments_size(); i++) {
    node->AddChild(Deserialize(proto.arguments(i),
                               id_string_pool,
                               arena,
                               allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTExecuteImmediateStatement* node,
                                            ASTExecuteImmediateStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->sql_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->sql_, proto->mutable_sql()));
  }
  if (node->into_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->into_clause_, proto->mutable_into_clause()));
  }
  if (node->using_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->using_clause_, proto->mutable_using_clause()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTExecuteImmediateStatement* node,
                                           AnyASTStatementProto* proto) {
  ASTExecuteImmediateStatementProto* ast_execute_immediate_statement_proto =
      proto->mutable_ast_execute_immediate_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_execute_immediate_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTExecuteImmediateStatement*> ParseTreeSerializer::Deserialize(
    const ASTExecuteImmediateStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTExecuteImmediateStatement* node = zetasql_base::NewInArena<ASTExecuteImmediateStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTExecuteImmediateStatement* node, const ASTExecuteImmediateStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_sql()) {
    node->AddChild(Deserialize(proto.sql(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_into_clause()) {
    node->AddChild(Deserialize(proto.into_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_using_clause()) {
    node->AddChild(Deserialize(proto.using_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAuxLoadDataFromFilesOptionsList* node,
                                            ASTAuxLoadDataFromFilesOptionsListProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->options_list_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->options_list_, proto->mutable_options_list()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTAuxLoadDataFromFilesOptionsList*> ParseTreeSerializer::Deserialize(
    const ASTAuxLoadDataFromFilesOptionsListProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAuxLoadDataFromFilesOptionsList* node = zetasql_base::NewInArena<ASTAuxLoadDataFromFilesOptionsList>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAuxLoadDataFromFilesOptionsList* node, const ASTAuxLoadDataFromFilesOptionsListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_options_list()) {
    node->AddChild(Deserialize(proto.options_list(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTAuxLoadDataStatement* node,
                                            ASTAuxLoadDataStatementProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  proto->set_insertion_mode(static_cast<ASTAuxLoadDataStatementEnums_InsertionMode>(node->insertion_mode_));
  if (node->partition_by_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->partition_by_, proto->mutable_partition_by()));
  }
  if (node->cluster_by_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->cluster_by_, proto->mutable_cluster_by()));
  }
  if (node->from_files_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->from_files_, proto->mutable_from_files()));
  }
  if (node->with_partition_columns_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->with_partition_columns_clause_, proto->mutable_with_partition_columns_clause()));
  }
  if (node->with_connection_clause_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->with_connection_clause_, proto->mutable_with_connection_clause()));
  }
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAuxLoadDataStatement* node,
                                           AnyASTStatementProto* proto) {
  AnyASTDdlStatementProto* ast_ddl_statement_proto =
      proto->mutable_ast_ddl_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_ddl_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAuxLoadDataStatement* node,
                                           AnyASTDdlStatementProto* proto) {
  AnyASTCreateStatementProto* ast_create_statement_proto =
      proto->mutable_ast_create_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_statement_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAuxLoadDataStatement* node,
                                           AnyASTCreateStatementProto* proto) {
  AnyASTCreateTableStmtBaseProto* ast_create_table_stmt_base_proto =
      proto->mutable_ast_create_table_stmt_base_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_create_table_stmt_base_proto));
  return absl::OkStatus();
}
absl::Status ParseTreeSerializer::Serialize(const ASTAuxLoadDataStatement* node,
                                           AnyASTCreateTableStmtBaseProto* proto) {
  ASTAuxLoadDataStatementProto* ast_aux_load_data_statement_proto =
      proto->mutable_ast_aux_load_data_statement_node();
  ZETASQL_RETURN_IF_ERROR(Serialize(node, ast_aux_load_data_statement_proto));
  return absl::OkStatus();
}
absl::StatusOr<ASTAuxLoadDataStatement*> ParseTreeSerializer::Deserialize(
    const ASTAuxLoadDataStatementProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTAuxLoadDataStatement* node = zetasql_base::NewInArena<ASTAuxLoadDataStatement>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTAuxLoadDataStatement* node, const ASTAuxLoadDataStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  node->insertion_mode_ = static_cast<ASTAuxLoadDataStatement::InsertionMode>(proto.insertion_mode());
  if (proto.has_partition_by()) {
    node->AddChild(Deserialize(proto.partition_by(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_cluster_by()) {
    node->AddChild(Deserialize(proto.cluster_by(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_from_files()) {
    node->AddChild(Deserialize(proto.from_files(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_with_partition_columns_clause()) {
    node->AddChild(Deserialize(proto.with_partition_columns_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  if (proto.has_with_connection_clause()) {
    node->AddChild(Deserialize(proto.with_connection_clause(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}

absl::Status ParseTreeSerializer::Serialize(const ASTLabel* node,
                                            ASTLabelProto* proto) {
  ZETASQL_RETURN_IF_ERROR(Serialize(node, proto->mutable_parent()));
  if (node->name_ != nullptr) {
    ZETASQL_RETURN_IF_ERROR(Serialize(node->name_, proto->mutable_name()));
  }
  return absl::OkStatus();
}
absl::StatusOr<ASTLabel*> ParseTreeSerializer::Deserialize(
    const ASTLabelProto& proto,
    IdStringPool* id_string_pool,
    zetasql_base::UnsafeArena* arena,
    std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  ASTLabel* node = zetasql_base::NewInArena<ASTLabel>(arena);
  allocated_ast_nodes->push_back(std::unique_ptr<ASTNode>(node));
  ZETASQL_RETURN_IF_ERROR(DeserializeAbstract(node,
                                      proto.parent(),
                                      id_string_pool,
                                      arena,
                                      allocated_ast_nodes));
  ZETASQL_RETURN_IF_ERROR(DeserializeFields(node,
                                    proto,
                                    id_string_pool,
                                    arena,
                                    allocated_ast_nodes));
  return node;
}
absl::Status ParseTreeSerializer::DeserializeFields(
      ASTLabel* node, const ASTLabelProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes) {
  if (proto.has_name()) {
    node->AddChild(Deserialize(proto.name(),
                   id_string_pool,
                   arena,
                   allocated_ast_nodes).value());
  }
  return absl::OkStatus();
}
}  // namespace zetasql
// NOLINTEND

