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

#ifndef ZETASQL_PARSER_PARSE_TREE_SERIALIZER_H_
#define ZETASQL_PARSER_PARSE_TREE_SERIALIZER_H_

#include "zetasql/parser/parse_tree.h"
#include "zetasql/parser/parse_tree.pb.h"
#include "zetasql/parser/parser.h"
#include "zetasql/base/status.h"

// NOLINTBEGIN(whitespace/line_length)

namespace zetasql {

class ParseTreeSerializer {
 public:
  // Serialize an ASTStatement to proto.
  static absl::Status Serialize(const ASTStatement* node,
                                AnyASTStatementProto* proto);

  // Serialize an ASTExpression to proto.
  static absl::Status Serialize(const ASTExpression* node,
                                AnyASTExpressionProto* proto);

  // Serialize an ASTType to proto.
  static absl::Status Serialize(const ASTType* node, AnyASTTypeProto* proto);

  // Deserialize a proto back to an ASTStatement, which can be retrieved
  // from output->statement().
  // ParserOptions can be used to set the Arena and IdStringPool to use.
  // LanguageOptions has no effect. The ParserOutput holds the output AST
  // and references to allocated memory pools and should be kept alive as
  // long as the output AST is used.
  static absl::StatusOr<std::unique_ptr<ParserOutput>> Deserialize(
      const AnyASTStatementProto& proto,
      const ParserOptions& parser_options_in);

 private:
  // Every class ASTFoo, whether abstract or final, has a corresponding
  // static method in ParseTreeSerializer class with signature:
  //   Serialize(const ASTFoo*, ASTFooProto* proto).
  //
  // Additionally, for each abstract parent class ASTBar below ASTNode
  // in ASTFoo's ancestry there is a method with signature:
  //   Serialize(const ASTFoo*, AnyASTBarProto* proto).
  //
  // If ASTFoo is abstract, it also has a method with signature:
  //   Serialize(const ASTFoo*, AnyASTFooProto* proto)
  //
  // The public API comprises only the Serialize() and Deserialize() methods
  // for ASTStatement, ASTExpression and ASTTypes.
  //
  // Each class ASTFoo also has a Deserialize() method. If ASTFoo is abstract,
  // the signature takes AnyASTFooProto&, if final it uses ASTFooProto&.
  // Each class also has a DeserializeFields() method, and abstract classes
  // have an additional DeserializeAbstract() method.

  static absl::Status Serialize(const ASTNode* node,
                                ASTNodeProto* proto);
  static absl::Status DeserializeAbstract(
      ASTNode* node, const ASTNodeProto& proto, IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStatement* node,
                                ASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTStatement* node, const ASTStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStatement*> Deserialize(
      const AnyASTStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTStatement* node, const ASTStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTQueryStatement* node,
                                ASTQueryStatementProto* proto);
  static absl::Status Serialize(const ASTQueryStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTQueryStatement* node, const ASTQueryStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTQueryStatement*> Deserialize(
      const ASTQueryStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTQueryExpression* node,
                                ASTQueryExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTQueryExpression* node, const ASTQueryExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTQueryExpression* node,
                                AnyASTQueryExpressionProto* proto);
  static absl::StatusOr<ASTQueryExpression*> Deserialize(
      const AnyASTQueryExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTQueryExpression* node, const ASTQueryExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTQuery* node,
                                ASTQueryProto* proto);
  static absl::Status Serialize(const ASTQuery* node,
                                AnyASTQueryExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTQuery* node, const ASTQueryProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTQuery*> Deserialize(
      const ASTQueryProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSelect* node,
                                ASTSelectProto* proto);
  static absl::Status Serialize(const ASTSelect* node,
                                AnyASTQueryExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTSelect* node, const ASTSelectProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSelect*> Deserialize(
      const ASTSelectProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSelectList* node,
                                ASTSelectListProto* proto);
  static absl::Status DeserializeFields(
      ASTSelectList* node, const ASTSelectListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSelectList*> Deserialize(
      const ASTSelectListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSelectColumn* node,
                                ASTSelectColumnProto* proto);
  static absl::Status DeserializeFields(
      ASTSelectColumn* node, const ASTSelectColumnProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSelectColumn*> Deserialize(
      const ASTSelectColumnProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTExpression* node,
                                ASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTExpression* node, const ASTExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTExpression*> Deserialize(
      const AnyASTExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTExpression* node, const ASTExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTLeaf* node,
                                ASTLeafProto* proto);
  static absl::Status Serialize(const ASTLeaf* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTLeaf* node, const ASTLeafProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTLeaf* node,
                                AnyASTLeafProto* proto);
  static absl::StatusOr<ASTLeaf*> Deserialize(
      const AnyASTLeafProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTLeaf* node, const ASTLeafProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTIntLiteral* node,
                                ASTIntLiteralProto* proto);
  static absl::Status Serialize(const ASTIntLiteral* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTIntLiteral* node,
                                AnyASTLeafProto* proto);
  static absl::Status DeserializeFields(
      ASTIntLiteral* node, const ASTIntLiteralProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTIntLiteral*> Deserialize(
      const ASTIntLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTIdentifier* node,
                                ASTIdentifierProto* proto);
  static absl::Status Serialize(const ASTIdentifier* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTIdentifier* node, const ASTIdentifierProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTIdentifier*> Deserialize(
      const ASTIdentifierProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlias* node,
                                ASTAliasProto* proto);
  static absl::Status DeserializeFields(
      ASTAlias* node, const ASTAliasProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlias*> Deserialize(
      const ASTAliasProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTGeneralizedPathExpression* node,
                                ASTGeneralizedPathExpressionProto* proto);
  static absl::Status Serialize(const ASTGeneralizedPathExpression* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTGeneralizedPathExpression* node, const ASTGeneralizedPathExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTGeneralizedPathExpression* node,
                                AnyASTGeneralizedPathExpressionProto* proto);
  static absl::StatusOr<ASTGeneralizedPathExpression*> Deserialize(
      const AnyASTGeneralizedPathExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTGeneralizedPathExpression* node, const ASTGeneralizedPathExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTPathExpression* node,
                                ASTPathExpressionProto* proto);
  static absl::Status Serialize(const ASTPathExpression* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTPathExpression* node,
                                AnyASTGeneralizedPathExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTPathExpression* node, const ASTPathExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTPathExpression*> Deserialize(
      const ASTPathExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTableExpression* node,
                                ASTTableExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTTableExpression* node, const ASTTableExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTTableExpression* node,
                                AnyASTTableExpressionProto* proto);
  static absl::StatusOr<ASTTableExpression*> Deserialize(
      const AnyASTTableExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTTableExpression* node, const ASTTableExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTablePathExpression* node,
                                ASTTablePathExpressionProto* proto);
  static absl::Status Serialize(const ASTTablePathExpression* node,
                                AnyASTTableExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTTablePathExpression* node, const ASTTablePathExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTablePathExpression*> Deserialize(
      const ASTTablePathExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTFromClause* node,
                                ASTFromClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTFromClause* node, const ASTFromClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTFromClause*> Deserialize(
      const ASTFromClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWhereClause* node,
                                ASTWhereClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTWhereClause* node, const ASTWhereClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWhereClause*> Deserialize(
      const ASTWhereClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTBooleanLiteral* node,
                                ASTBooleanLiteralProto* proto);
  static absl::Status Serialize(const ASTBooleanLiteral* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTBooleanLiteral* node,
                                AnyASTLeafProto* proto);
  static absl::Status DeserializeFields(
      ASTBooleanLiteral* node, const ASTBooleanLiteralProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTBooleanLiteral*> Deserialize(
      const ASTBooleanLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAndExpr* node,
                                ASTAndExprProto* proto);
  static absl::Status Serialize(const ASTAndExpr* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTAndExpr* node, const ASTAndExprProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAndExpr*> Deserialize(
      const ASTAndExprProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTBinaryExpression* node,
                                ASTBinaryExpressionProto* proto);
  static absl::Status Serialize(const ASTBinaryExpression* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTBinaryExpression* node, const ASTBinaryExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTBinaryExpression*> Deserialize(
      const ASTBinaryExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStringLiteral* node,
                                ASTStringLiteralProto* proto);
  static absl::Status Serialize(const ASTStringLiteral* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTStringLiteral* node,
                                AnyASTLeafProto* proto);
  static absl::Status DeserializeFields(
      ASTStringLiteral* node, const ASTStringLiteralProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStringLiteral*> Deserialize(
      const ASTStringLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStar* node,
                                ASTStarProto* proto);
  static absl::Status Serialize(const ASTStar* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTStar* node,
                                AnyASTLeafProto* proto);
  static absl::Status DeserializeFields(
      ASTStar* node, const ASTStarProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStar*> Deserialize(
      const ASTStarProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTOrExpr* node,
                                ASTOrExprProto* proto);
  static absl::Status Serialize(const ASTOrExpr* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTOrExpr* node, const ASTOrExprProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTOrExpr*> Deserialize(
      const ASTOrExprProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTGroupingItem* node,
                                ASTGroupingItemProto* proto);
  static absl::Status DeserializeFields(
      ASTGroupingItem* node, const ASTGroupingItemProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTGroupingItem*> Deserialize(
      const ASTGroupingItemProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTGroupBy* node,
                                ASTGroupByProto* proto);
  static absl::Status DeserializeFields(
      ASTGroupBy* node, const ASTGroupByProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTGroupBy*> Deserialize(
      const ASTGroupByProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTOrderingExpression* node,
                                ASTOrderingExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTOrderingExpression* node, const ASTOrderingExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTOrderingExpression*> Deserialize(
      const ASTOrderingExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTOrderBy* node,
                                ASTOrderByProto* proto);
  static absl::Status DeserializeFields(
      ASTOrderBy* node, const ASTOrderByProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTOrderBy*> Deserialize(
      const ASTOrderByProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTLimitOffset* node,
                                ASTLimitOffsetProto* proto);
  static absl::Status DeserializeFields(
      ASTLimitOffset* node, const ASTLimitOffsetProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTLimitOffset*> Deserialize(
      const ASTLimitOffsetProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTFloatLiteral* node,
                                ASTFloatLiteralProto* proto);
  static absl::Status Serialize(const ASTFloatLiteral* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTFloatLiteral* node,
                                AnyASTLeafProto* proto);
  static absl::Status DeserializeFields(
      ASTFloatLiteral* node, const ASTFloatLiteralProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTFloatLiteral*> Deserialize(
      const ASTFloatLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTNullLiteral* node,
                                ASTNullLiteralProto* proto);
  static absl::Status Serialize(const ASTNullLiteral* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTNullLiteral* node,
                                AnyASTLeafProto* proto);
  static absl::Status DeserializeFields(
      ASTNullLiteral* node, const ASTNullLiteralProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTNullLiteral*> Deserialize(
      const ASTNullLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTOnClause* node,
                                ASTOnClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTOnClause* node, const ASTOnClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTOnClause*> Deserialize(
      const ASTOnClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWithClauseEntry* node,
                                ASTWithClauseEntryProto* proto);
  static absl::Status DeserializeFields(
      ASTWithClauseEntry* node, const ASTWithClauseEntryProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWithClauseEntry*> Deserialize(
      const ASTWithClauseEntryProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTJoin* node,
                                ASTJoinProto* proto);
  static absl::Status Serialize(const ASTJoin* node,
                                AnyASTTableExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTJoin* node, const ASTJoinProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTJoin*> Deserialize(
      const ASTJoinProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWithClause* node,
                                ASTWithClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTWithClause* node, const ASTWithClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWithClause*> Deserialize(
      const ASTWithClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTHaving* node,
                                ASTHavingProto* proto);
  static absl::Status DeserializeFields(
      ASTHaving* node, const ASTHavingProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTHaving*> Deserialize(
      const ASTHavingProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTType* node,
                                ASTTypeProto* proto);
  static absl::Status DeserializeFields(
      ASTType* node, const ASTTypeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTType*> Deserialize(
      const AnyASTTypeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTType* node, const ASTTypeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSimpleType* node,
                                ASTSimpleTypeProto* proto);
  static absl::Status Serialize(const ASTSimpleType* node,
                                AnyASTTypeProto* proto);
  static absl::Status DeserializeFields(
      ASTSimpleType* node, const ASTSimpleTypeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSimpleType*> Deserialize(
      const ASTSimpleTypeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTArrayType* node,
                                ASTArrayTypeProto* proto);
  static absl::Status Serialize(const ASTArrayType* node,
                                AnyASTTypeProto* proto);
  static absl::Status DeserializeFields(
      ASTArrayType* node, const ASTArrayTypeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTArrayType*> Deserialize(
      const ASTArrayTypeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStructField* node,
                                ASTStructFieldProto* proto);
  static absl::Status DeserializeFields(
      ASTStructField* node, const ASTStructFieldProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStructField*> Deserialize(
      const ASTStructFieldProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStructType* node,
                                ASTStructTypeProto* proto);
  static absl::Status Serialize(const ASTStructType* node,
                                AnyASTTypeProto* proto);
  static absl::Status DeserializeFields(
      ASTStructType* node, const ASTStructTypeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStructType*> Deserialize(
      const ASTStructTypeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCastExpression* node,
                                ASTCastExpressionProto* proto);
  static absl::Status Serialize(const ASTCastExpression* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTCastExpression* node, const ASTCastExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCastExpression*> Deserialize(
      const ASTCastExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSelectAs* node,
                                ASTSelectAsProto* proto);
  static absl::Status DeserializeFields(
      ASTSelectAs* node, const ASTSelectAsProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSelectAs*> Deserialize(
      const ASTSelectAsProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTRollup* node,
                                ASTRollupProto* proto);
  static absl::Status DeserializeFields(
      ASTRollup* node, const ASTRollupProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTRollup*> Deserialize(
      const ASTRollupProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTFunctionCall* node,
                                ASTFunctionCallProto* proto);
  static absl::Status Serialize(const ASTFunctionCall* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTFunctionCall* node, const ASTFunctionCallProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTFunctionCall*> Deserialize(
      const ASTFunctionCallProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTArrayConstructor* node,
                                ASTArrayConstructorProto* proto);
  static absl::Status Serialize(const ASTArrayConstructor* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTArrayConstructor* node, const ASTArrayConstructorProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTArrayConstructor*> Deserialize(
      const ASTArrayConstructorProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStructConstructorArg* node,
                                ASTStructConstructorArgProto* proto);
  static absl::Status DeserializeFields(
      ASTStructConstructorArg* node, const ASTStructConstructorArgProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStructConstructorArg*> Deserialize(
      const ASTStructConstructorArgProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStructConstructorWithParens* node,
                                ASTStructConstructorWithParensProto* proto);
  static absl::Status Serialize(const ASTStructConstructorWithParens* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTStructConstructorWithParens* node, const ASTStructConstructorWithParensProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStructConstructorWithParens*> Deserialize(
      const ASTStructConstructorWithParensProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStructConstructorWithKeyword* node,
                                ASTStructConstructorWithKeywordProto* proto);
  static absl::Status Serialize(const ASTStructConstructorWithKeyword* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTStructConstructorWithKeyword* node, const ASTStructConstructorWithKeywordProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStructConstructorWithKeyword*> Deserialize(
      const ASTStructConstructorWithKeywordProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTInExpression* node,
                                ASTInExpressionProto* proto);
  static absl::Status Serialize(const ASTInExpression* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTInExpression* node, const ASTInExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTInExpression*> Deserialize(
      const ASTInExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTInList* node,
                                ASTInListProto* proto);
  static absl::Status DeserializeFields(
      ASTInList* node, const ASTInListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTInList*> Deserialize(
      const ASTInListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTBetweenExpression* node,
                                ASTBetweenExpressionProto* proto);
  static absl::Status Serialize(const ASTBetweenExpression* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTBetweenExpression* node, const ASTBetweenExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTBetweenExpression*> Deserialize(
      const ASTBetweenExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTNumericLiteral* node,
                                ASTNumericLiteralProto* proto);
  static absl::Status Serialize(const ASTNumericLiteral* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTNumericLiteral* node,
                                AnyASTLeafProto* proto);
  static absl::Status DeserializeFields(
      ASTNumericLiteral* node, const ASTNumericLiteralProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTNumericLiteral*> Deserialize(
      const ASTNumericLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTBigNumericLiteral* node,
                                ASTBigNumericLiteralProto* proto);
  static absl::Status Serialize(const ASTBigNumericLiteral* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTBigNumericLiteral* node,
                                AnyASTLeafProto* proto);
  static absl::Status DeserializeFields(
      ASTBigNumericLiteral* node, const ASTBigNumericLiteralProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTBigNumericLiteral*> Deserialize(
      const ASTBigNumericLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTBytesLiteral* node,
                                ASTBytesLiteralProto* proto);
  static absl::Status Serialize(const ASTBytesLiteral* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTBytesLiteral* node,
                                AnyASTLeafProto* proto);
  static absl::Status DeserializeFields(
      ASTBytesLiteral* node, const ASTBytesLiteralProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTBytesLiteral*> Deserialize(
      const ASTBytesLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDateOrTimeLiteral* node,
                                ASTDateOrTimeLiteralProto* proto);
  static absl::Status Serialize(const ASTDateOrTimeLiteral* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTDateOrTimeLiteral* node, const ASTDateOrTimeLiteralProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDateOrTimeLiteral*> Deserialize(
      const ASTDateOrTimeLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTMaxLiteral* node,
                                ASTMaxLiteralProto* proto);
  static absl::Status Serialize(const ASTMaxLiteral* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTMaxLiteral* node,
                                AnyASTLeafProto* proto);
  static absl::Status DeserializeFields(
      ASTMaxLiteral* node, const ASTMaxLiteralProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTMaxLiteral*> Deserialize(
      const ASTMaxLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTJSONLiteral* node,
                                ASTJSONLiteralProto* proto);
  static absl::Status Serialize(const ASTJSONLiteral* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTJSONLiteral* node,
                                AnyASTLeafProto* proto);
  static absl::Status DeserializeFields(
      ASTJSONLiteral* node, const ASTJSONLiteralProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTJSONLiteral*> Deserialize(
      const ASTJSONLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCaseValueExpression* node,
                                ASTCaseValueExpressionProto* proto);
  static absl::Status Serialize(const ASTCaseValueExpression* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTCaseValueExpression* node, const ASTCaseValueExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCaseValueExpression*> Deserialize(
      const ASTCaseValueExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCaseNoValueExpression* node,
                                ASTCaseNoValueExpressionProto* proto);
  static absl::Status Serialize(const ASTCaseNoValueExpression* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTCaseNoValueExpression* node, const ASTCaseNoValueExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCaseNoValueExpression*> Deserialize(
      const ASTCaseNoValueExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTArrayElement* node,
                                ASTArrayElementProto* proto);
  static absl::Status Serialize(const ASTArrayElement* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTArrayElement* node,
                                AnyASTGeneralizedPathExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTArrayElement* node, const ASTArrayElementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTArrayElement*> Deserialize(
      const ASTArrayElementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTBitwiseShiftExpression* node,
                                ASTBitwiseShiftExpressionProto* proto);
  static absl::Status Serialize(const ASTBitwiseShiftExpression* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTBitwiseShiftExpression* node, const ASTBitwiseShiftExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTBitwiseShiftExpression*> Deserialize(
      const ASTBitwiseShiftExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCollate* node,
                                ASTCollateProto* proto);
  static absl::Status DeserializeFields(
      ASTCollate* node, const ASTCollateProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCollate*> Deserialize(
      const ASTCollateProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDotGeneralizedField* node,
                                ASTDotGeneralizedFieldProto* proto);
  static absl::Status Serialize(const ASTDotGeneralizedField* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTDotGeneralizedField* node,
                                AnyASTGeneralizedPathExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTDotGeneralizedField* node, const ASTDotGeneralizedFieldProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDotGeneralizedField*> Deserialize(
      const ASTDotGeneralizedFieldProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDotIdentifier* node,
                                ASTDotIdentifierProto* proto);
  static absl::Status Serialize(const ASTDotIdentifier* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTDotIdentifier* node,
                                AnyASTGeneralizedPathExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTDotIdentifier* node, const ASTDotIdentifierProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDotIdentifier*> Deserialize(
      const ASTDotIdentifierProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDotStar* node,
                                ASTDotStarProto* proto);
  static absl::Status Serialize(const ASTDotStar* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTDotStar* node, const ASTDotStarProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDotStar*> Deserialize(
      const ASTDotStarProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDotStarWithModifiers* node,
                                ASTDotStarWithModifiersProto* proto);
  static absl::Status Serialize(const ASTDotStarWithModifiers* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTDotStarWithModifiers* node, const ASTDotStarWithModifiersProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDotStarWithModifiers*> Deserialize(
      const ASTDotStarWithModifiersProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTExpressionSubquery* node,
                                ASTExpressionSubqueryProto* proto);
  static absl::Status Serialize(const ASTExpressionSubquery* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTExpressionSubquery* node, const ASTExpressionSubqueryProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTExpressionSubquery*> Deserialize(
      const ASTExpressionSubqueryProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTExtractExpression* node,
                                ASTExtractExpressionProto* proto);
  static absl::Status Serialize(const ASTExtractExpression* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTExtractExpression* node, const ASTExtractExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTExtractExpression*> Deserialize(
      const ASTExtractExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTHavingModifier* node,
                                ASTHavingModifierProto* proto);
  static absl::Status DeserializeFields(
      ASTHavingModifier* node, const ASTHavingModifierProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTHavingModifier*> Deserialize(
      const ASTHavingModifierProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTIntervalExpr* node,
                                ASTIntervalExprProto* proto);
  static absl::Status Serialize(const ASTIntervalExpr* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTIntervalExpr* node, const ASTIntervalExprProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTIntervalExpr*> Deserialize(
      const ASTIntervalExprProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTNamedArgument* node,
                                ASTNamedArgumentProto* proto);
  static absl::Status Serialize(const ASTNamedArgument* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTNamedArgument* node, const ASTNamedArgumentProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTNamedArgument*> Deserialize(
      const ASTNamedArgumentProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTNullOrder* node,
                                ASTNullOrderProto* proto);
  static absl::Status DeserializeFields(
      ASTNullOrder* node, const ASTNullOrderProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTNullOrder*> Deserialize(
      const ASTNullOrderProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTOnOrUsingClauseList* node,
                                ASTOnOrUsingClauseListProto* proto);
  static absl::Status DeserializeFields(
      ASTOnOrUsingClauseList* node, const ASTOnOrUsingClauseListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTOnOrUsingClauseList*> Deserialize(
      const ASTOnOrUsingClauseListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTParenthesizedJoin* node,
                                ASTParenthesizedJoinProto* proto);
  static absl::Status Serialize(const ASTParenthesizedJoin* node,
                                AnyASTTableExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTParenthesizedJoin* node, const ASTParenthesizedJoinProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTParenthesizedJoin*> Deserialize(
      const ASTParenthesizedJoinProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTPartitionBy* node,
                                ASTPartitionByProto* proto);
  static absl::Status DeserializeFields(
      ASTPartitionBy* node, const ASTPartitionByProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTPartitionBy*> Deserialize(
      const ASTPartitionByProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSetOperation* node,
                                ASTSetOperationProto* proto);
  static absl::Status Serialize(const ASTSetOperation* node,
                                AnyASTQueryExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTSetOperation* node, const ASTSetOperationProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSetOperation*> Deserialize(
      const ASTSetOperationProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStarExceptList* node,
                                ASTStarExceptListProto* proto);
  static absl::Status DeserializeFields(
      ASTStarExceptList* node, const ASTStarExceptListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStarExceptList*> Deserialize(
      const ASTStarExceptListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStarModifiers* node,
                                ASTStarModifiersProto* proto);
  static absl::Status DeserializeFields(
      ASTStarModifiers* node, const ASTStarModifiersProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStarModifiers*> Deserialize(
      const ASTStarModifiersProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStarReplaceItem* node,
                                ASTStarReplaceItemProto* proto);
  static absl::Status DeserializeFields(
      ASTStarReplaceItem* node, const ASTStarReplaceItemProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStarReplaceItem*> Deserialize(
      const ASTStarReplaceItemProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStarWithModifiers* node,
                                ASTStarWithModifiersProto* proto);
  static absl::Status Serialize(const ASTStarWithModifiers* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTStarWithModifiers* node, const ASTStarWithModifiersProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStarWithModifiers*> Deserialize(
      const ASTStarWithModifiersProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTableSubquery* node,
                                ASTTableSubqueryProto* proto);
  static absl::Status Serialize(const ASTTableSubquery* node,
                                AnyASTTableExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTTableSubquery* node, const ASTTableSubqueryProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTableSubquery*> Deserialize(
      const ASTTableSubqueryProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTUnaryExpression* node,
                                ASTUnaryExpressionProto* proto);
  static absl::Status Serialize(const ASTUnaryExpression* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTUnaryExpression* node, const ASTUnaryExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTUnaryExpression*> Deserialize(
      const ASTUnaryExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTUnnestExpression* node,
                                ASTUnnestExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTUnnestExpression* node, const ASTUnnestExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTUnnestExpression*> Deserialize(
      const ASTUnnestExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWindowClause* node,
                                ASTWindowClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTWindowClause* node, const ASTWindowClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWindowClause*> Deserialize(
      const ASTWindowClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWindowDefinition* node,
                                ASTWindowDefinitionProto* proto);
  static absl::Status DeserializeFields(
      ASTWindowDefinition* node, const ASTWindowDefinitionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWindowDefinition*> Deserialize(
      const ASTWindowDefinitionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWindowFrame* node,
                                ASTWindowFrameProto* proto);
  static absl::Status DeserializeFields(
      ASTWindowFrame* node, const ASTWindowFrameProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWindowFrame*> Deserialize(
      const ASTWindowFrameProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWindowFrameExpr* node,
                                ASTWindowFrameExprProto* proto);
  static absl::Status DeserializeFields(
      ASTWindowFrameExpr* node, const ASTWindowFrameExprProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWindowFrameExpr*> Deserialize(
      const ASTWindowFrameExprProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTLikeExpression* node,
                                ASTLikeExpressionProto* proto);
  static absl::Status Serialize(const ASTLikeExpression* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTLikeExpression* node, const ASTLikeExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTLikeExpression*> Deserialize(
      const ASTLikeExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWindowSpecification* node,
                                ASTWindowSpecificationProto* proto);
  static absl::Status DeserializeFields(
      ASTWindowSpecification* node, const ASTWindowSpecificationProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWindowSpecification*> Deserialize(
      const ASTWindowSpecificationProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWithOffset* node,
                                ASTWithOffsetProto* proto);
  static absl::Status DeserializeFields(
      ASTWithOffset* node, const ASTWithOffsetProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWithOffset*> Deserialize(
      const ASTWithOffsetProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAnySomeAllOp* node,
                                ASTAnySomeAllOpProto* proto);
  static absl::Status DeserializeFields(
      ASTAnySomeAllOp* node, const ASTAnySomeAllOpProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAnySomeAllOp*> Deserialize(
      const ASTAnySomeAllOpProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTParameterExprBase* node,
                                ASTParameterExprBaseProto* proto);
  static absl::Status Serialize(const ASTParameterExprBase* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTParameterExprBase* node, const ASTParameterExprBaseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTParameterExprBase* node,
                                AnyASTParameterExprBaseProto* proto);
  static absl::StatusOr<ASTParameterExprBase*> Deserialize(
      const AnyASTParameterExprBaseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTParameterExprBase* node, const ASTParameterExprBaseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStatementList* node,
                                ASTStatementListProto* proto);
  static absl::Status DeserializeFields(
      ASTStatementList* node, const ASTStatementListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStatementList*> Deserialize(
      const ASTStatementListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTScriptStatement* node,
                                ASTScriptStatementProto* proto);
  static absl::Status Serialize(const ASTScriptStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTScriptStatement* node, const ASTScriptStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTScriptStatement* node,
                                AnyASTScriptStatementProto* proto);
  static absl::StatusOr<ASTScriptStatement*> Deserialize(
      const AnyASTScriptStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTScriptStatement* node, const ASTScriptStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTHintedStatement* node,
                                ASTHintedStatementProto* proto);
  static absl::Status Serialize(const ASTHintedStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTHintedStatement* node, const ASTHintedStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTHintedStatement*> Deserialize(
      const ASTHintedStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTExplainStatement* node,
                                ASTExplainStatementProto* proto);
  static absl::Status Serialize(const ASTExplainStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTExplainStatement* node, const ASTExplainStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTExplainStatement*> Deserialize(
      const ASTExplainStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDescribeStatement* node,
                                ASTDescribeStatementProto* proto);
  static absl::Status Serialize(const ASTDescribeStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTDescribeStatement* node, const ASTDescribeStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDescribeStatement*> Deserialize(
      const ASTDescribeStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTShowStatement* node,
                                ASTShowStatementProto* proto);
  static absl::Status Serialize(const ASTShowStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTShowStatement* node, const ASTShowStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTShowStatement*> Deserialize(
      const ASTShowStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTransactionMode* node,
                                ASTTransactionModeProto* proto);
  static absl::Status DeserializeFields(
      ASTTransactionMode* node, const ASTTransactionModeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTTransactionMode* node,
                                AnyASTTransactionModeProto* proto);
  static absl::StatusOr<ASTTransactionMode*> Deserialize(
      const AnyASTTransactionModeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTTransactionMode* node, const ASTTransactionModeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTransactionIsolationLevel* node,
                                ASTTransactionIsolationLevelProto* proto);
  static absl::Status Serialize(const ASTTransactionIsolationLevel* node,
                                AnyASTTransactionModeProto* proto);
  static absl::Status DeserializeFields(
      ASTTransactionIsolationLevel* node, const ASTTransactionIsolationLevelProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTransactionIsolationLevel*> Deserialize(
      const ASTTransactionIsolationLevelProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTransactionReadWriteMode* node,
                                ASTTransactionReadWriteModeProto* proto);
  static absl::Status Serialize(const ASTTransactionReadWriteMode* node,
                                AnyASTTransactionModeProto* proto);
  static absl::Status DeserializeFields(
      ASTTransactionReadWriteMode* node, const ASTTransactionReadWriteModeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTransactionReadWriteMode*> Deserialize(
      const ASTTransactionReadWriteModeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTransactionModeList* node,
                                ASTTransactionModeListProto* proto);
  static absl::Status DeserializeFields(
      ASTTransactionModeList* node, const ASTTransactionModeListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTransactionModeList*> Deserialize(
      const ASTTransactionModeListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTBeginStatement* node,
                                ASTBeginStatementProto* proto);
  static absl::Status Serialize(const ASTBeginStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTBeginStatement* node, const ASTBeginStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTBeginStatement*> Deserialize(
      const ASTBeginStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSetTransactionStatement* node,
                                ASTSetTransactionStatementProto* proto);
  static absl::Status Serialize(const ASTSetTransactionStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTSetTransactionStatement* node, const ASTSetTransactionStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSetTransactionStatement*> Deserialize(
      const ASTSetTransactionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCommitStatement* node,
                                ASTCommitStatementProto* proto);
  static absl::Status Serialize(const ASTCommitStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCommitStatement* node, const ASTCommitStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCommitStatement*> Deserialize(
      const ASTCommitStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTRollbackStatement* node,
                                ASTRollbackStatementProto* proto);
  static absl::Status Serialize(const ASTRollbackStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTRollbackStatement* node, const ASTRollbackStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTRollbackStatement*> Deserialize(
      const ASTRollbackStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStartBatchStatement* node,
                                ASTStartBatchStatementProto* proto);
  static absl::Status Serialize(const ASTStartBatchStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTStartBatchStatement* node, const ASTStartBatchStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStartBatchStatement*> Deserialize(
      const ASTStartBatchStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTRunBatchStatement* node,
                                ASTRunBatchStatementProto* proto);
  static absl::Status Serialize(const ASTRunBatchStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTRunBatchStatement* node, const ASTRunBatchStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTRunBatchStatement*> Deserialize(
      const ASTRunBatchStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAbortBatchStatement* node,
                                ASTAbortBatchStatementProto* proto);
  static absl::Status Serialize(const ASTAbortBatchStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTAbortBatchStatement* node, const ASTAbortBatchStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAbortBatchStatement*> Deserialize(
      const ASTAbortBatchStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDdlStatement* node,
                                ASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTDdlStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTDdlStatement* node, const ASTDdlStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTDdlStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::StatusOr<ASTDdlStatement*> Deserialize(
      const AnyASTDdlStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTDdlStatement* node, const ASTDdlStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDropEntityStatement* node,
                                ASTDropEntityStatementProto* proto);
  static absl::Status Serialize(const ASTDropEntityStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTDropEntityStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTDropEntityStatement* node, const ASTDropEntityStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDropEntityStatement*> Deserialize(
      const ASTDropEntityStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDropFunctionStatement* node,
                                ASTDropFunctionStatementProto* proto);
  static absl::Status Serialize(const ASTDropFunctionStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTDropFunctionStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTDropFunctionStatement* node, const ASTDropFunctionStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDropFunctionStatement*> Deserialize(
      const ASTDropFunctionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDropTableFunctionStatement* node,
                                ASTDropTableFunctionStatementProto* proto);
  static absl::Status Serialize(const ASTDropTableFunctionStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTDropTableFunctionStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTDropTableFunctionStatement* node, const ASTDropTableFunctionStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDropTableFunctionStatement*> Deserialize(
      const ASTDropTableFunctionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDropAllRowAccessPoliciesStatement* node,
                                ASTDropAllRowAccessPoliciesStatementProto* proto);
  static absl::Status Serialize(const ASTDropAllRowAccessPoliciesStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTDropAllRowAccessPoliciesStatement* node, const ASTDropAllRowAccessPoliciesStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDropAllRowAccessPoliciesStatement*> Deserialize(
      const ASTDropAllRowAccessPoliciesStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDropMaterializedViewStatement* node,
                                ASTDropMaterializedViewStatementProto* proto);
  static absl::Status Serialize(const ASTDropMaterializedViewStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTDropMaterializedViewStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTDropMaterializedViewStatement* node, const ASTDropMaterializedViewStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDropMaterializedViewStatement*> Deserialize(
      const ASTDropMaterializedViewStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDropSnapshotTableStatement* node,
                                ASTDropSnapshotTableStatementProto* proto);
  static absl::Status Serialize(const ASTDropSnapshotTableStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTDropSnapshotTableStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTDropSnapshotTableStatement* node, const ASTDropSnapshotTableStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDropSnapshotTableStatement*> Deserialize(
      const ASTDropSnapshotTableStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDropSearchIndexStatement* node,
                                ASTDropSearchIndexStatementProto* proto);
  static absl::Status Serialize(const ASTDropSearchIndexStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTDropSearchIndexStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTDropSearchIndexStatement* node, const ASTDropSearchIndexStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDropSearchIndexStatement*> Deserialize(
      const ASTDropSearchIndexStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTRenameStatement* node,
                                ASTRenameStatementProto* proto);
  static absl::Status Serialize(const ASTRenameStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTRenameStatement* node, const ASTRenameStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTRenameStatement*> Deserialize(
      const ASTRenameStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTImportStatement* node,
                                ASTImportStatementProto* proto);
  static absl::Status Serialize(const ASTImportStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTImportStatement* node, const ASTImportStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTImportStatement*> Deserialize(
      const ASTImportStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTModuleStatement* node,
                                ASTModuleStatementProto* proto);
  static absl::Status Serialize(const ASTModuleStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTModuleStatement* node, const ASTModuleStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTModuleStatement*> Deserialize(
      const ASTModuleStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWithConnectionClause* node,
                                ASTWithConnectionClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTWithConnectionClause* node, const ASTWithConnectionClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWithConnectionClause*> Deserialize(
      const ASTWithConnectionClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTIntoAlias* node,
                                ASTIntoAliasProto* proto);
  static absl::Status DeserializeFields(
      ASTIntoAlias* node, const ASTIntoAliasProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTIntoAlias*> Deserialize(
      const ASTIntoAliasProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTUnnestExpressionWithOptAliasAndOffset* node,
                                ASTUnnestExpressionWithOptAliasAndOffsetProto* proto);
  static absl::Status DeserializeFields(
      ASTUnnestExpressionWithOptAliasAndOffset* node, const ASTUnnestExpressionWithOptAliasAndOffsetProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTUnnestExpressionWithOptAliasAndOffset*> Deserialize(
      const ASTUnnestExpressionWithOptAliasAndOffsetProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTPivotExpression* node,
                                ASTPivotExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTPivotExpression* node, const ASTPivotExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTPivotExpression*> Deserialize(
      const ASTPivotExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTPivotValue* node,
                                ASTPivotValueProto* proto);
  static absl::Status DeserializeFields(
      ASTPivotValue* node, const ASTPivotValueProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTPivotValue*> Deserialize(
      const ASTPivotValueProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTPivotExpressionList* node,
                                ASTPivotExpressionListProto* proto);
  static absl::Status DeserializeFields(
      ASTPivotExpressionList* node, const ASTPivotExpressionListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTPivotExpressionList*> Deserialize(
      const ASTPivotExpressionListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTPivotValueList* node,
                                ASTPivotValueListProto* proto);
  static absl::Status DeserializeFields(
      ASTPivotValueList* node, const ASTPivotValueListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTPivotValueList*> Deserialize(
      const ASTPivotValueListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTPivotClause* node,
                                ASTPivotClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTPivotClause* node, const ASTPivotClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTPivotClause*> Deserialize(
      const ASTPivotClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTUnpivotInItem* node,
                                ASTUnpivotInItemProto* proto);
  static absl::Status DeserializeFields(
      ASTUnpivotInItem* node, const ASTUnpivotInItemProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTUnpivotInItem*> Deserialize(
      const ASTUnpivotInItemProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTUnpivotInItemList* node,
                                ASTUnpivotInItemListProto* proto);
  static absl::Status DeserializeFields(
      ASTUnpivotInItemList* node, const ASTUnpivotInItemListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTUnpivotInItemList*> Deserialize(
      const ASTUnpivotInItemListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTUnpivotClause* node,
                                ASTUnpivotClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTUnpivotClause* node, const ASTUnpivotClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTUnpivotClause*> Deserialize(
      const ASTUnpivotClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTUsingClause* node,
                                ASTUsingClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTUsingClause* node, const ASTUsingClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTUsingClause*> Deserialize(
      const ASTUsingClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTForSystemTime* node,
                                ASTForSystemTimeProto* proto);
  static absl::Status DeserializeFields(
      ASTForSystemTime* node, const ASTForSystemTimeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTForSystemTime*> Deserialize(
      const ASTForSystemTimeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTQualify* node,
                                ASTQualifyProto* proto);
  static absl::Status DeserializeFields(
      ASTQualify* node, const ASTQualifyProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTQualify*> Deserialize(
      const ASTQualifyProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTClampedBetweenModifier* node,
                                ASTClampedBetweenModifierProto* proto);
  static absl::Status DeserializeFields(
      ASTClampedBetweenModifier* node, const ASTClampedBetweenModifierProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTClampedBetweenModifier*> Deserialize(
      const ASTClampedBetweenModifierProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTFormatClause* node,
                                ASTFormatClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTFormatClause* node, const ASTFormatClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTFormatClause*> Deserialize(
      const ASTFormatClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTPathExpressionList* node,
                                ASTPathExpressionListProto* proto);
  static absl::Status DeserializeFields(
      ASTPathExpressionList* node, const ASTPathExpressionListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTPathExpressionList*> Deserialize(
      const ASTPathExpressionListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTParameterExpr* node,
                                ASTParameterExprProto* proto);
  static absl::Status Serialize(const ASTParameterExpr* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTParameterExpr* node,
                                AnyASTParameterExprBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTParameterExpr* node, const ASTParameterExprProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTParameterExpr*> Deserialize(
      const ASTParameterExprProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSystemVariableExpr* node,
                                ASTSystemVariableExprProto* proto);
  static absl::Status Serialize(const ASTSystemVariableExpr* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTSystemVariableExpr* node,
                                AnyASTParameterExprBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTSystemVariableExpr* node, const ASTSystemVariableExprProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSystemVariableExpr*> Deserialize(
      const ASTSystemVariableExprProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWithGroupRows* node,
                                ASTWithGroupRowsProto* proto);
  static absl::Status DeserializeFields(
      ASTWithGroupRows* node, const ASTWithGroupRowsProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWithGroupRows*> Deserialize(
      const ASTWithGroupRowsProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTLambda* node,
                                ASTLambdaProto* proto);
  static absl::Status Serialize(const ASTLambda* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTLambda* node, const ASTLambdaProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTLambda*> Deserialize(
      const ASTLambdaProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAnalyticFunctionCall* node,
                                ASTAnalyticFunctionCallProto* proto);
  static absl::Status Serialize(const ASTAnalyticFunctionCall* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTAnalyticFunctionCall* node, const ASTAnalyticFunctionCallProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAnalyticFunctionCall*> Deserialize(
      const ASTAnalyticFunctionCallProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTFunctionCallWithGroupRows* node,
                                ASTFunctionCallWithGroupRowsProto* proto);
  static absl::Status Serialize(const ASTFunctionCallWithGroupRows* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTFunctionCallWithGroupRows* node, const ASTFunctionCallWithGroupRowsProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTFunctionCallWithGroupRows*> Deserialize(
      const ASTFunctionCallWithGroupRowsProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTClusterBy* node,
                                ASTClusterByProto* proto);
  static absl::Status DeserializeFields(
      ASTClusterBy* node, const ASTClusterByProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTClusterBy*> Deserialize(
      const ASTClusterByProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTNewConstructorArg* node,
                                ASTNewConstructorArgProto* proto);
  static absl::Status DeserializeFields(
      ASTNewConstructorArg* node, const ASTNewConstructorArgProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTNewConstructorArg*> Deserialize(
      const ASTNewConstructorArgProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTNewConstructor* node,
                                ASTNewConstructorProto* proto);
  static absl::Status Serialize(const ASTNewConstructor* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTNewConstructor* node, const ASTNewConstructorProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTNewConstructor*> Deserialize(
      const ASTNewConstructorProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTOptionsList* node,
                                ASTOptionsListProto* proto);
  static absl::Status DeserializeFields(
      ASTOptionsList* node, const ASTOptionsListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTOptionsList*> Deserialize(
      const ASTOptionsListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTOptionsEntry* node,
                                ASTOptionsEntryProto* proto);
  static absl::Status DeserializeFields(
      ASTOptionsEntry* node, const ASTOptionsEntryProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTOptionsEntry*> Deserialize(
      const ASTOptionsEntryProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateStatement* node,
                                ASTCreateStatementProto* proto);
  static absl::Status Serialize(const ASTCreateStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateStatement* node, const ASTCreateStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTCreateStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::StatusOr<ASTCreateStatement*> Deserialize(
      const AnyASTCreateStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTCreateStatement* node, const ASTCreateStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTFunctionParameter* node,
                                ASTFunctionParameterProto* proto);
  static absl::Status DeserializeFields(
      ASTFunctionParameter* node, const ASTFunctionParameterProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTFunctionParameter*> Deserialize(
      const ASTFunctionParameterProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTFunctionParameters* node,
                                ASTFunctionParametersProto* proto);
  static absl::Status DeserializeFields(
      ASTFunctionParameters* node, const ASTFunctionParametersProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTFunctionParameters*> Deserialize(
      const ASTFunctionParametersProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTFunctionDeclaration* node,
                                ASTFunctionDeclarationProto* proto);
  static absl::Status DeserializeFields(
      ASTFunctionDeclaration* node, const ASTFunctionDeclarationProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTFunctionDeclaration*> Deserialize(
      const ASTFunctionDeclarationProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSqlFunctionBody* node,
                                ASTSqlFunctionBodyProto* proto);
  static absl::Status DeserializeFields(
      ASTSqlFunctionBody* node, const ASTSqlFunctionBodyProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSqlFunctionBody*> Deserialize(
      const ASTSqlFunctionBodyProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTVFArgument* node,
                                ASTTVFArgumentProto* proto);
  static absl::Status DeserializeFields(
      ASTTVFArgument* node, const ASTTVFArgumentProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTVFArgument*> Deserialize(
      const ASTTVFArgumentProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTVF* node,
                                ASTTVFProto* proto);
  static absl::Status Serialize(const ASTTVF* node,
                                AnyASTTableExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTTVF* node, const ASTTVFProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTVF*> Deserialize(
      const ASTTVFProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTableClause* node,
                                ASTTableClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTTableClause* node, const ASTTableClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTableClause*> Deserialize(
      const ASTTableClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTModelClause* node,
                                ASTModelClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTModelClause* node, const ASTModelClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTModelClause*> Deserialize(
      const ASTModelClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTConnectionClause* node,
                                ASTConnectionClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTConnectionClause* node, const ASTConnectionClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTConnectionClause*> Deserialize(
      const ASTConnectionClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTableDataSource* node,
                                ASTTableDataSourceProto* proto);
  static absl::Status Serialize(const ASTTableDataSource* node,
                                AnyASTTableExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTTableDataSource* node, const ASTTableDataSourceProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTTableDataSource* node,
                                AnyASTTableDataSourceProto* proto);
  static absl::StatusOr<ASTTableDataSource*> Deserialize(
      const AnyASTTableDataSourceProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTTableDataSource* node, const ASTTableDataSourceProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCloneDataSource* node,
                                ASTCloneDataSourceProto* proto);
  static absl::Status Serialize(const ASTCloneDataSource* node,
                                AnyASTTableExpressionProto* proto);
  static absl::Status Serialize(const ASTCloneDataSource* node,
                                AnyASTTableDataSourceProto* proto);
  static absl::Status DeserializeFields(
      ASTCloneDataSource* node, const ASTCloneDataSourceProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCloneDataSource*> Deserialize(
      const ASTCloneDataSourceProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCopyDataSource* node,
                                ASTCopyDataSourceProto* proto);
  static absl::Status Serialize(const ASTCopyDataSource* node,
                                AnyASTTableExpressionProto* proto);
  static absl::Status Serialize(const ASTCopyDataSource* node,
                                AnyASTTableDataSourceProto* proto);
  static absl::Status DeserializeFields(
      ASTCopyDataSource* node, const ASTCopyDataSourceProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCopyDataSource*> Deserialize(
      const ASTCopyDataSourceProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCloneDataSourceList* node,
                                ASTCloneDataSourceListProto* proto);
  static absl::Status DeserializeFields(
      ASTCloneDataSourceList* node, const ASTCloneDataSourceListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCloneDataSourceList*> Deserialize(
      const ASTCloneDataSourceListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCloneDataStatement* node,
                                ASTCloneDataStatementProto* proto);
  static absl::Status Serialize(const ASTCloneDataStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCloneDataStatement* node, const ASTCloneDataStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCloneDataStatement*> Deserialize(
      const ASTCloneDataStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateConstantStatement* node,
                                ASTCreateConstantStatementProto* proto);
  static absl::Status Serialize(const ASTCreateConstantStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateConstantStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateConstantStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateConstantStatement* node, const ASTCreateConstantStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreateConstantStatement*> Deserialize(
      const ASTCreateConstantStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateDatabaseStatement* node,
                                ASTCreateDatabaseStatementProto* proto);
  static absl::Status Serialize(const ASTCreateDatabaseStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateDatabaseStatement* node, const ASTCreateDatabaseStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreateDatabaseStatement*> Deserialize(
      const ASTCreateDatabaseStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateProcedureStatement* node,
                                ASTCreateProcedureStatementProto* proto);
  static absl::Status Serialize(const ASTCreateProcedureStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateProcedureStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateProcedureStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateProcedureStatement* node, const ASTCreateProcedureStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreateProcedureStatement*> Deserialize(
      const ASTCreateProcedureStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateSchemaStatement* node,
                                ASTCreateSchemaStatementProto* proto);
  static absl::Status Serialize(const ASTCreateSchemaStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateSchemaStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateSchemaStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateSchemaStatement* node, const ASTCreateSchemaStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreateSchemaStatement*> Deserialize(
      const ASTCreateSchemaStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTransformClause* node,
                                ASTTransformClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTTransformClause* node, const ASTTransformClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTransformClause*> Deserialize(
      const ASTTransformClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateModelStatement* node,
                                ASTCreateModelStatementProto* proto);
  static absl::Status Serialize(const ASTCreateModelStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateModelStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateModelStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateModelStatement* node, const ASTCreateModelStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreateModelStatement*> Deserialize(
      const ASTCreateModelStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTIndexAllColumns* node,
                                ASTIndexAllColumnsProto* proto);
  static absl::Status Serialize(const ASTIndexAllColumns* node,
                                AnyASTExpressionProto* proto);
  static absl::Status Serialize(const ASTIndexAllColumns* node,
                                AnyASTLeafProto* proto);
  static absl::Status DeserializeFields(
      ASTIndexAllColumns* node, const ASTIndexAllColumnsProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTIndexAllColumns*> Deserialize(
      const ASTIndexAllColumnsProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTIndexItemList* node,
                                ASTIndexItemListProto* proto);
  static absl::Status DeserializeFields(
      ASTIndexItemList* node, const ASTIndexItemListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTIndexItemList*> Deserialize(
      const ASTIndexItemListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTIndexStoringExpressionList* node,
                                ASTIndexStoringExpressionListProto* proto);
  static absl::Status DeserializeFields(
      ASTIndexStoringExpressionList* node, const ASTIndexStoringExpressionListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTIndexStoringExpressionList*> Deserialize(
      const ASTIndexStoringExpressionListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTIndexUnnestExpressionList* node,
                                ASTIndexUnnestExpressionListProto* proto);
  static absl::Status DeserializeFields(
      ASTIndexUnnestExpressionList* node, const ASTIndexUnnestExpressionListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTIndexUnnestExpressionList*> Deserialize(
      const ASTIndexUnnestExpressionListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateIndexStatement* node,
                                ASTCreateIndexStatementProto* proto);
  static absl::Status Serialize(const ASTCreateIndexStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateIndexStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateIndexStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateIndexStatement* node, const ASTCreateIndexStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreateIndexStatement*> Deserialize(
      const ASTCreateIndexStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTExportDataStatement* node,
                                ASTExportDataStatementProto* proto);
  static absl::Status Serialize(const ASTExportDataStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTExportDataStatement* node, const ASTExportDataStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTExportDataStatement*> Deserialize(
      const ASTExportDataStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTExportModelStatement* node,
                                ASTExportModelStatementProto* proto);
  static absl::Status Serialize(const ASTExportModelStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTExportModelStatement* node, const ASTExportModelStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTExportModelStatement*> Deserialize(
      const ASTExportModelStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCallStatement* node,
                                ASTCallStatementProto* proto);
  static absl::Status Serialize(const ASTCallStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCallStatement* node, const ASTCallStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCallStatement*> Deserialize(
      const ASTCallStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDefineTableStatement* node,
                                ASTDefineTableStatementProto* proto);
  static absl::Status Serialize(const ASTDefineTableStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTDefineTableStatement* node, const ASTDefineTableStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDefineTableStatement*> Deserialize(
      const ASTDefineTableStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWithPartitionColumnsClause* node,
                                ASTWithPartitionColumnsClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTWithPartitionColumnsClause* node, const ASTWithPartitionColumnsClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWithPartitionColumnsClause*> Deserialize(
      const ASTWithPartitionColumnsClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateSnapshotTableStatement* node,
                                ASTCreateSnapshotTableStatementProto* proto);
  static absl::Status Serialize(const ASTCreateSnapshotTableStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateSnapshotTableStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateSnapshotTableStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateSnapshotTableStatement* node, const ASTCreateSnapshotTableStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreateSnapshotTableStatement*> Deserialize(
      const ASTCreateSnapshotTableStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTypeParameterList* node,
                                ASTTypeParameterListProto* proto);
  static absl::Status DeserializeFields(
      ASTTypeParameterList* node, const ASTTypeParameterListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTypeParameterList*> Deserialize(
      const ASTTypeParameterListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTVFSchema* node,
                                ASTTVFSchemaProto* proto);
  static absl::Status DeserializeFields(
      ASTTVFSchema* node, const ASTTVFSchemaProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTVFSchema*> Deserialize(
      const ASTTVFSchemaProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTVFSchemaColumn* node,
                                ASTTVFSchemaColumnProto* proto);
  static absl::Status DeserializeFields(
      ASTTVFSchemaColumn* node, const ASTTVFSchemaColumnProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTVFSchemaColumn*> Deserialize(
      const ASTTVFSchemaColumnProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTableAndColumnInfo* node,
                                ASTTableAndColumnInfoProto* proto);
  static absl::Status DeserializeFields(
      ASTTableAndColumnInfo* node, const ASTTableAndColumnInfoProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTableAndColumnInfo*> Deserialize(
      const ASTTableAndColumnInfoProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTableAndColumnInfoList* node,
                                ASTTableAndColumnInfoListProto* proto);
  static absl::Status DeserializeFields(
      ASTTableAndColumnInfoList* node, const ASTTableAndColumnInfoListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTableAndColumnInfoList*> Deserialize(
      const ASTTableAndColumnInfoListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTemplatedParameterType* node,
                                ASTTemplatedParameterTypeProto* proto);
  static absl::Status DeserializeFields(
      ASTTemplatedParameterType* node, const ASTTemplatedParameterTypeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTemplatedParameterType*> Deserialize(
      const ASTTemplatedParameterTypeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDefaultLiteral* node,
                                ASTDefaultLiteralProto* proto);
  static absl::Status Serialize(const ASTDefaultLiteral* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTDefaultLiteral* node, const ASTDefaultLiteralProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDefaultLiteral*> Deserialize(
      const ASTDefaultLiteralProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAnalyzeStatement* node,
                                ASTAnalyzeStatementProto* proto);
  static absl::Status Serialize(const ASTAnalyzeStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTAnalyzeStatement* node, const ASTAnalyzeStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAnalyzeStatement*> Deserialize(
      const ASTAnalyzeStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAssertStatement* node,
                                ASTAssertStatementProto* proto);
  static absl::Status Serialize(const ASTAssertStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTAssertStatement* node, const ASTAssertStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAssertStatement*> Deserialize(
      const ASTAssertStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAssertRowsModified* node,
                                ASTAssertRowsModifiedProto* proto);
  static absl::Status DeserializeFields(
      ASTAssertRowsModified* node, const ASTAssertRowsModifiedProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAssertRowsModified*> Deserialize(
      const ASTAssertRowsModifiedProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTReturningClause* node,
                                ASTReturningClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTReturningClause* node, const ASTReturningClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTReturningClause*> Deserialize(
      const ASTReturningClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDeleteStatement* node,
                                ASTDeleteStatementProto* proto);
  static absl::Status Serialize(const ASTDeleteStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTDeleteStatement* node, const ASTDeleteStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDeleteStatement*> Deserialize(
      const ASTDeleteStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTColumnAttribute* node,
                                ASTColumnAttributeProto* proto);
  static absl::Status DeserializeFields(
      ASTColumnAttribute* node, const ASTColumnAttributeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTColumnAttribute* node,
                                AnyASTColumnAttributeProto* proto);
  static absl::StatusOr<ASTColumnAttribute*> Deserialize(
      const AnyASTColumnAttributeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTColumnAttribute* node, const ASTColumnAttributeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTNotNullColumnAttribute* node,
                                ASTNotNullColumnAttributeProto* proto);
  static absl::Status Serialize(const ASTNotNullColumnAttribute* node,
                                AnyASTColumnAttributeProto* proto);
  static absl::Status DeserializeFields(
      ASTNotNullColumnAttribute* node, const ASTNotNullColumnAttributeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTNotNullColumnAttribute*> Deserialize(
      const ASTNotNullColumnAttributeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTHiddenColumnAttribute* node,
                                ASTHiddenColumnAttributeProto* proto);
  static absl::Status Serialize(const ASTHiddenColumnAttribute* node,
                                AnyASTColumnAttributeProto* proto);
  static absl::Status DeserializeFields(
      ASTHiddenColumnAttribute* node, const ASTHiddenColumnAttributeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTHiddenColumnAttribute*> Deserialize(
      const ASTHiddenColumnAttributeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTPrimaryKeyColumnAttribute* node,
                                ASTPrimaryKeyColumnAttributeProto* proto);
  static absl::Status Serialize(const ASTPrimaryKeyColumnAttribute* node,
                                AnyASTColumnAttributeProto* proto);
  static absl::Status DeserializeFields(
      ASTPrimaryKeyColumnAttribute* node, const ASTPrimaryKeyColumnAttributeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTPrimaryKeyColumnAttribute*> Deserialize(
      const ASTPrimaryKeyColumnAttributeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTForeignKeyColumnAttribute* node,
                                ASTForeignKeyColumnAttributeProto* proto);
  static absl::Status Serialize(const ASTForeignKeyColumnAttribute* node,
                                AnyASTColumnAttributeProto* proto);
  static absl::Status DeserializeFields(
      ASTForeignKeyColumnAttribute* node, const ASTForeignKeyColumnAttributeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTForeignKeyColumnAttribute*> Deserialize(
      const ASTForeignKeyColumnAttributeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTColumnAttributeList* node,
                                ASTColumnAttributeListProto* proto);
  static absl::Status DeserializeFields(
      ASTColumnAttributeList* node, const ASTColumnAttributeListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTColumnAttributeList*> Deserialize(
      const ASTColumnAttributeListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStructColumnField* node,
                                ASTStructColumnFieldProto* proto);
  static absl::Status DeserializeFields(
      ASTStructColumnField* node, const ASTStructColumnFieldProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStructColumnField*> Deserialize(
      const ASTStructColumnFieldProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTGeneratedColumnInfo* node,
                                ASTGeneratedColumnInfoProto* proto);
  static absl::Status DeserializeFields(
      ASTGeneratedColumnInfo* node, const ASTGeneratedColumnInfoProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTGeneratedColumnInfo*> Deserialize(
      const ASTGeneratedColumnInfoProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTableElement* node,
                                ASTTableElementProto* proto);
  static absl::Status DeserializeFields(
      ASTTableElement* node, const ASTTableElementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTTableElement* node,
                                AnyASTTableElementProto* proto);
  static absl::StatusOr<ASTTableElement*> Deserialize(
      const AnyASTTableElementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTTableElement* node, const ASTTableElementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTColumnDefinition* node,
                                ASTColumnDefinitionProto* proto);
  static absl::Status Serialize(const ASTColumnDefinition* node,
                                AnyASTTableElementProto* proto);
  static absl::Status DeserializeFields(
      ASTColumnDefinition* node, const ASTColumnDefinitionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTColumnDefinition*> Deserialize(
      const ASTColumnDefinitionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTableElementList* node,
                                ASTTableElementListProto* proto);
  static absl::Status DeserializeFields(
      ASTTableElementList* node, const ASTTableElementListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTableElementList*> Deserialize(
      const ASTTableElementListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTColumnList* node,
                                ASTColumnListProto* proto);
  static absl::Status DeserializeFields(
      ASTColumnList* node, const ASTColumnListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTColumnList*> Deserialize(
      const ASTColumnListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTColumnPosition* node,
                                ASTColumnPositionProto* proto);
  static absl::Status DeserializeFields(
      ASTColumnPosition* node, const ASTColumnPositionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTColumnPosition*> Deserialize(
      const ASTColumnPositionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTInsertValuesRow* node,
                                ASTInsertValuesRowProto* proto);
  static absl::Status DeserializeFields(
      ASTInsertValuesRow* node, const ASTInsertValuesRowProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTInsertValuesRow*> Deserialize(
      const ASTInsertValuesRowProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTInsertValuesRowList* node,
                                ASTInsertValuesRowListProto* proto);
  static absl::Status DeserializeFields(
      ASTInsertValuesRowList* node, const ASTInsertValuesRowListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTInsertValuesRowList*> Deserialize(
      const ASTInsertValuesRowListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTInsertStatement* node,
                                ASTInsertStatementProto* proto);
  static absl::Status Serialize(const ASTInsertStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTInsertStatement* node, const ASTInsertStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTInsertStatement*> Deserialize(
      const ASTInsertStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTUpdateSetValue* node,
                                ASTUpdateSetValueProto* proto);
  static absl::Status DeserializeFields(
      ASTUpdateSetValue* node, const ASTUpdateSetValueProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTUpdateSetValue*> Deserialize(
      const ASTUpdateSetValueProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTUpdateItem* node,
                                ASTUpdateItemProto* proto);
  static absl::Status DeserializeFields(
      ASTUpdateItem* node, const ASTUpdateItemProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTUpdateItem*> Deserialize(
      const ASTUpdateItemProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTUpdateItemList* node,
                                ASTUpdateItemListProto* proto);
  static absl::Status DeserializeFields(
      ASTUpdateItemList* node, const ASTUpdateItemListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTUpdateItemList*> Deserialize(
      const ASTUpdateItemListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTUpdateStatement* node,
                                ASTUpdateStatementProto* proto);
  static absl::Status Serialize(const ASTUpdateStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTUpdateStatement* node, const ASTUpdateStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTUpdateStatement*> Deserialize(
      const ASTUpdateStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTruncateStatement* node,
                                ASTTruncateStatementProto* proto);
  static absl::Status Serialize(const ASTTruncateStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTTruncateStatement* node, const ASTTruncateStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTTruncateStatement*> Deserialize(
      const ASTTruncateStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTMergeAction* node,
                                ASTMergeActionProto* proto);
  static absl::Status DeserializeFields(
      ASTMergeAction* node, const ASTMergeActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTMergeAction*> Deserialize(
      const ASTMergeActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTMergeWhenClause* node,
                                ASTMergeWhenClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTMergeWhenClause* node, const ASTMergeWhenClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTMergeWhenClause*> Deserialize(
      const ASTMergeWhenClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTMergeWhenClauseList* node,
                                ASTMergeWhenClauseListProto* proto);
  static absl::Status DeserializeFields(
      ASTMergeWhenClauseList* node, const ASTMergeWhenClauseListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTMergeWhenClauseList*> Deserialize(
      const ASTMergeWhenClauseListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTMergeStatement* node,
                                ASTMergeStatementProto* proto);
  static absl::Status Serialize(const ASTMergeStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTMergeStatement* node, const ASTMergeStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTMergeStatement*> Deserialize(
      const ASTMergeStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTPrivilege* node,
                                ASTPrivilegeProto* proto);
  static absl::Status DeserializeFields(
      ASTPrivilege* node, const ASTPrivilegeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTPrivilege*> Deserialize(
      const ASTPrivilegeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTPrivileges* node,
                                ASTPrivilegesProto* proto);
  static absl::Status DeserializeFields(
      ASTPrivileges* node, const ASTPrivilegesProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTPrivileges*> Deserialize(
      const ASTPrivilegesProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTGranteeList* node,
                                ASTGranteeListProto* proto);
  static absl::Status DeserializeFields(
      ASTGranteeList* node, const ASTGranteeListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTGranteeList*> Deserialize(
      const ASTGranteeListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTGrantStatement* node,
                                ASTGrantStatementProto* proto);
  static absl::Status Serialize(const ASTGrantStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTGrantStatement* node, const ASTGrantStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTGrantStatement*> Deserialize(
      const ASTGrantStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTRevokeStatement* node,
                                ASTRevokeStatementProto* proto);
  static absl::Status Serialize(const ASTRevokeStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTRevokeStatement* node, const ASTRevokeStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTRevokeStatement*> Deserialize(
      const ASTRevokeStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTRepeatableClause* node,
                                ASTRepeatableClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTRepeatableClause* node, const ASTRepeatableClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTRepeatableClause*> Deserialize(
      const ASTRepeatableClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTFilterFieldsArg* node,
                                ASTFilterFieldsArgProto* proto);
  static absl::Status DeserializeFields(
      ASTFilterFieldsArg* node, const ASTFilterFieldsArgProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTFilterFieldsArg*> Deserialize(
      const ASTFilterFieldsArgProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTReplaceFieldsArg* node,
                                ASTReplaceFieldsArgProto* proto);
  static absl::Status DeserializeFields(
      ASTReplaceFieldsArg* node, const ASTReplaceFieldsArgProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTReplaceFieldsArg*> Deserialize(
      const ASTReplaceFieldsArgProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTReplaceFieldsExpression* node,
                                ASTReplaceFieldsExpressionProto* proto);
  static absl::Status Serialize(const ASTReplaceFieldsExpression* node,
                                AnyASTExpressionProto* proto);
  static absl::Status DeserializeFields(
      ASTReplaceFieldsExpression* node, const ASTReplaceFieldsExpressionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTReplaceFieldsExpression*> Deserialize(
      const ASTReplaceFieldsExpressionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSampleSize* node,
                                ASTSampleSizeProto* proto);
  static absl::Status DeserializeFields(
      ASTSampleSize* node, const ASTSampleSizeProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSampleSize*> Deserialize(
      const ASTSampleSizeProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWithWeight* node,
                                ASTWithWeightProto* proto);
  static absl::Status DeserializeFields(
      ASTWithWeight* node, const ASTWithWeightProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWithWeight*> Deserialize(
      const ASTWithWeightProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSampleSuffix* node,
                                ASTSampleSuffixProto* proto);
  static absl::Status DeserializeFields(
      ASTSampleSuffix* node, const ASTSampleSuffixProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSampleSuffix*> Deserialize(
      const ASTSampleSuffixProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSampleClause* node,
                                ASTSampleClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTSampleClause* node, const ASTSampleClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSampleClause*> Deserialize(
      const ASTSampleClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterAction* node,
                                ASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterAction* node, const ASTAlterActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTAlterAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::StatusOr<ASTAlterAction*> Deserialize(
      const AnyASTAlterActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTAlterAction* node, const ASTAlterActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSetOptionsAction* node,
                                ASTSetOptionsActionProto* proto);
  static absl::Status Serialize(const ASTSetOptionsAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTSetOptionsAction* node, const ASTSetOptionsActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSetOptionsAction*> Deserialize(
      const ASTSetOptionsActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSetAsAction* node,
                                ASTSetAsActionProto* proto);
  static absl::Status Serialize(const ASTSetAsAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTSetAsAction* node, const ASTSetAsActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSetAsAction*> Deserialize(
      const ASTSetAsActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAddConstraintAction* node,
                                ASTAddConstraintActionProto* proto);
  static absl::Status Serialize(const ASTAddConstraintAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTAddConstraintAction* node, const ASTAddConstraintActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAddConstraintAction*> Deserialize(
      const ASTAddConstraintActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDropPrimaryKeyAction* node,
                                ASTDropPrimaryKeyActionProto* proto);
  static absl::Status Serialize(const ASTDropPrimaryKeyAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTDropPrimaryKeyAction* node, const ASTDropPrimaryKeyActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDropPrimaryKeyAction*> Deserialize(
      const ASTDropPrimaryKeyActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDropConstraintAction* node,
                                ASTDropConstraintActionProto* proto);
  static absl::Status Serialize(const ASTDropConstraintAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTDropConstraintAction* node, const ASTDropConstraintActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDropConstraintAction*> Deserialize(
      const ASTDropConstraintActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterConstraintEnforcementAction* node,
                                ASTAlterConstraintEnforcementActionProto* proto);
  static absl::Status Serialize(const ASTAlterConstraintEnforcementAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterConstraintEnforcementAction* node, const ASTAlterConstraintEnforcementActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterConstraintEnforcementAction*> Deserialize(
      const ASTAlterConstraintEnforcementActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterConstraintSetOptionsAction* node,
                                ASTAlterConstraintSetOptionsActionProto* proto);
  static absl::Status Serialize(const ASTAlterConstraintSetOptionsAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterConstraintSetOptionsAction* node, const ASTAlterConstraintSetOptionsActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterConstraintSetOptionsAction*> Deserialize(
      const ASTAlterConstraintSetOptionsActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAddColumnAction* node,
                                ASTAddColumnActionProto* proto);
  static absl::Status Serialize(const ASTAddColumnAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTAddColumnAction* node, const ASTAddColumnActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAddColumnAction*> Deserialize(
      const ASTAddColumnActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDropColumnAction* node,
                                ASTDropColumnActionProto* proto);
  static absl::Status Serialize(const ASTDropColumnAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTDropColumnAction* node, const ASTDropColumnActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDropColumnAction*> Deserialize(
      const ASTDropColumnActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTRenameColumnAction* node,
                                ASTRenameColumnActionProto* proto);
  static absl::Status Serialize(const ASTRenameColumnAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTRenameColumnAction* node, const ASTRenameColumnActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTRenameColumnAction*> Deserialize(
      const ASTRenameColumnActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterColumnTypeAction* node,
                                ASTAlterColumnTypeActionProto* proto);
  static absl::Status Serialize(const ASTAlterColumnTypeAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterColumnTypeAction* node, const ASTAlterColumnTypeActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterColumnTypeAction*> Deserialize(
      const ASTAlterColumnTypeActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterColumnOptionsAction* node,
                                ASTAlterColumnOptionsActionProto* proto);
  static absl::Status Serialize(const ASTAlterColumnOptionsAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterColumnOptionsAction* node, const ASTAlterColumnOptionsActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterColumnOptionsAction*> Deserialize(
      const ASTAlterColumnOptionsActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterColumnSetDefaultAction* node,
                                ASTAlterColumnSetDefaultActionProto* proto);
  static absl::Status Serialize(const ASTAlterColumnSetDefaultAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterColumnSetDefaultAction* node, const ASTAlterColumnSetDefaultActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterColumnSetDefaultAction*> Deserialize(
      const ASTAlterColumnSetDefaultActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterColumnDropDefaultAction* node,
                                ASTAlterColumnDropDefaultActionProto* proto);
  static absl::Status Serialize(const ASTAlterColumnDropDefaultAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterColumnDropDefaultAction* node, const ASTAlterColumnDropDefaultActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterColumnDropDefaultAction*> Deserialize(
      const ASTAlterColumnDropDefaultActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterColumnDropNotNullAction* node,
                                ASTAlterColumnDropNotNullActionProto* proto);
  static absl::Status Serialize(const ASTAlterColumnDropNotNullAction* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterColumnDropNotNullAction* node, const ASTAlterColumnDropNotNullActionProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterColumnDropNotNullAction*> Deserialize(
      const ASTAlterColumnDropNotNullActionProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTGrantToClause* node,
                                ASTGrantToClauseProto* proto);
  static absl::Status Serialize(const ASTGrantToClause* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTGrantToClause* node, const ASTGrantToClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTGrantToClause*> Deserialize(
      const ASTGrantToClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTRestrictToClause* node,
                                ASTRestrictToClauseProto* proto);
  static absl::Status Serialize(const ASTRestrictToClause* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTRestrictToClause* node, const ASTRestrictToClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTRestrictToClause*> Deserialize(
      const ASTRestrictToClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAddToRestricteeListClause* node,
                                ASTAddToRestricteeListClauseProto* proto);
  static absl::Status Serialize(const ASTAddToRestricteeListClause* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTAddToRestricteeListClause* node, const ASTAddToRestricteeListClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAddToRestricteeListClause*> Deserialize(
      const ASTAddToRestricteeListClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTRemoveFromRestricteeListClause* node,
                                ASTRemoveFromRestricteeListClauseProto* proto);
  static absl::Status Serialize(const ASTRemoveFromRestricteeListClause* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTRemoveFromRestricteeListClause* node, const ASTRemoveFromRestricteeListClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTRemoveFromRestricteeListClause*> Deserialize(
      const ASTRemoveFromRestricteeListClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTFilterUsingClause* node,
                                ASTFilterUsingClauseProto* proto);
  static absl::Status Serialize(const ASTFilterUsingClause* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTFilterUsingClause* node, const ASTFilterUsingClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTFilterUsingClause*> Deserialize(
      const ASTFilterUsingClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTRevokeFromClause* node,
                                ASTRevokeFromClauseProto* proto);
  static absl::Status Serialize(const ASTRevokeFromClause* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTRevokeFromClause* node, const ASTRevokeFromClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTRevokeFromClause*> Deserialize(
      const ASTRevokeFromClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTRenameToClause* node,
                                ASTRenameToClauseProto* proto);
  static absl::Status Serialize(const ASTRenameToClause* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTRenameToClause* node, const ASTRenameToClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTRenameToClause*> Deserialize(
      const ASTRenameToClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSetCollateClause* node,
                                ASTSetCollateClauseProto* proto);
  static absl::Status Serialize(const ASTSetCollateClause* node,
                                AnyASTAlterActionProto* proto);
  static absl::Status DeserializeFields(
      ASTSetCollateClause* node, const ASTSetCollateClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSetCollateClause*> Deserialize(
      const ASTSetCollateClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterActionList* node,
                                ASTAlterActionListProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterActionList* node, const ASTAlterActionListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterActionList*> Deserialize(
      const ASTAlterActionListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterAllRowAccessPoliciesStatement* node,
                                ASTAlterAllRowAccessPoliciesStatementProto* proto);
  static absl::Status Serialize(const ASTAlterAllRowAccessPoliciesStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterAllRowAccessPoliciesStatement* node, const ASTAlterAllRowAccessPoliciesStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterAllRowAccessPoliciesStatement*> Deserialize(
      const ASTAlterAllRowAccessPoliciesStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTForeignKeyActions* node,
                                ASTForeignKeyActionsProto* proto);
  static absl::Status DeserializeFields(
      ASTForeignKeyActions* node, const ASTForeignKeyActionsProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTForeignKeyActions*> Deserialize(
      const ASTForeignKeyActionsProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTForeignKeyReference* node,
                                ASTForeignKeyReferenceProto* proto);
  static absl::Status DeserializeFields(
      ASTForeignKeyReference* node, const ASTForeignKeyReferenceProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTForeignKeyReference*> Deserialize(
      const ASTForeignKeyReferenceProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTScript* node,
                                ASTScriptProto* proto);
  static absl::Status DeserializeFields(
      ASTScript* node, const ASTScriptProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTScript*> Deserialize(
      const ASTScriptProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTElseifClause* node,
                                ASTElseifClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTElseifClause* node, const ASTElseifClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTElseifClause*> Deserialize(
      const ASTElseifClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTElseifClauseList* node,
                                ASTElseifClauseListProto* proto);
  static absl::Status DeserializeFields(
      ASTElseifClauseList* node, const ASTElseifClauseListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTElseifClauseList*> Deserialize(
      const ASTElseifClauseListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTIfStatement* node,
                                ASTIfStatementProto* proto);
  static absl::Status Serialize(const ASTIfStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTIfStatement* node,
                                AnyASTScriptStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTIfStatement* node, const ASTIfStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTIfStatement*> Deserialize(
      const ASTIfStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWhenThenClause* node,
                                ASTWhenThenClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTWhenThenClause* node, const ASTWhenThenClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWhenThenClause*> Deserialize(
      const ASTWhenThenClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWhenThenClauseList* node,
                                ASTWhenThenClauseListProto* proto);
  static absl::Status DeserializeFields(
      ASTWhenThenClauseList* node, const ASTWhenThenClauseListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWhenThenClauseList*> Deserialize(
      const ASTWhenThenClauseListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCaseStatement* node,
                                ASTCaseStatementProto* proto);
  static absl::Status Serialize(const ASTCaseStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCaseStatement* node,
                                AnyASTScriptStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCaseStatement* node, const ASTCaseStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCaseStatement*> Deserialize(
      const ASTCaseStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTHint* node,
                                ASTHintProto* proto);
  static absl::Status DeserializeFields(
      ASTHint* node, const ASTHintProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTHint*> Deserialize(
      const ASTHintProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTHintEntry* node,
                                ASTHintEntryProto* proto);
  static absl::Status DeserializeFields(
      ASTHintEntry* node, const ASTHintEntryProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTHintEntry*> Deserialize(
      const ASTHintEntryProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTUnpivotInItemLabel* node,
                                ASTUnpivotInItemLabelProto* proto);
  static absl::Status DeserializeFields(
      ASTUnpivotInItemLabel* node, const ASTUnpivotInItemLabelProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTUnpivotInItemLabel*> Deserialize(
      const ASTUnpivotInItemLabelProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDescriptor* node,
                                ASTDescriptorProto* proto);
  static absl::Status DeserializeFields(
      ASTDescriptor* node, const ASTDescriptorProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDescriptor*> Deserialize(
      const ASTDescriptorProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTColumnSchema* node,
                                ASTColumnSchemaProto* proto);
  static absl::Status DeserializeFields(
      ASTColumnSchema* node, const ASTColumnSchemaProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTColumnSchema* node,
                                AnyASTColumnSchemaProto* proto);
  static absl::StatusOr<ASTColumnSchema*> Deserialize(
      const AnyASTColumnSchemaProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTColumnSchema* node, const ASTColumnSchemaProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSimpleColumnSchema* node,
                                ASTSimpleColumnSchemaProto* proto);
  static absl::Status Serialize(const ASTSimpleColumnSchema* node,
                                AnyASTColumnSchemaProto* proto);
  static absl::Status DeserializeFields(
      ASTSimpleColumnSchema* node, const ASTSimpleColumnSchemaProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSimpleColumnSchema*> Deserialize(
      const ASTSimpleColumnSchemaProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTArrayColumnSchema* node,
                                ASTArrayColumnSchemaProto* proto);
  static absl::Status Serialize(const ASTArrayColumnSchema* node,
                                AnyASTColumnSchemaProto* proto);
  static absl::Status DeserializeFields(
      ASTArrayColumnSchema* node, const ASTArrayColumnSchemaProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTArrayColumnSchema*> Deserialize(
      const ASTArrayColumnSchemaProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTTableConstraint* node,
                                ASTTableConstraintProto* proto);
  static absl::Status Serialize(const ASTTableConstraint* node,
                                AnyASTTableElementProto* proto);
  static absl::Status DeserializeFields(
      ASTTableConstraint* node, const ASTTableConstraintProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTTableConstraint* node,
                                AnyASTTableConstraintProto* proto);
  static absl::StatusOr<ASTTableConstraint*> Deserialize(
      const AnyASTTableConstraintProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTTableConstraint* node, const ASTTableConstraintProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTPrimaryKey* node,
                                ASTPrimaryKeyProto* proto);
  static absl::Status Serialize(const ASTPrimaryKey* node,
                                AnyASTTableElementProto* proto);
  static absl::Status Serialize(const ASTPrimaryKey* node,
                                AnyASTTableConstraintProto* proto);
  static absl::Status DeserializeFields(
      ASTPrimaryKey* node, const ASTPrimaryKeyProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTPrimaryKey*> Deserialize(
      const ASTPrimaryKeyProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTForeignKey* node,
                                ASTForeignKeyProto* proto);
  static absl::Status Serialize(const ASTForeignKey* node,
                                AnyASTTableElementProto* proto);
  static absl::Status Serialize(const ASTForeignKey* node,
                                AnyASTTableConstraintProto* proto);
  static absl::Status DeserializeFields(
      ASTForeignKey* node, const ASTForeignKeyProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTForeignKey*> Deserialize(
      const ASTForeignKeyProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCheckConstraint* node,
                                ASTCheckConstraintProto* proto);
  static absl::Status Serialize(const ASTCheckConstraint* node,
                                AnyASTTableElementProto* proto);
  static absl::Status Serialize(const ASTCheckConstraint* node,
                                AnyASTTableConstraintProto* proto);
  static absl::Status DeserializeFields(
      ASTCheckConstraint* node, const ASTCheckConstraintProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCheckConstraint*> Deserialize(
      const ASTCheckConstraintProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDescriptorColumn* node,
                                ASTDescriptorColumnProto* proto);
  static absl::Status DeserializeFields(
      ASTDescriptorColumn* node, const ASTDescriptorColumnProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDescriptorColumn*> Deserialize(
      const ASTDescriptorColumnProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDescriptorColumnList* node,
                                ASTDescriptorColumnListProto* proto);
  static absl::Status DeserializeFields(
      ASTDescriptorColumnList* node, const ASTDescriptorColumnListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDescriptorColumnList*> Deserialize(
      const ASTDescriptorColumnListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateEntityStatement* node,
                                ASTCreateEntityStatementProto* proto);
  static absl::Status Serialize(const ASTCreateEntityStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateEntityStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateEntityStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateEntityStatement* node, const ASTCreateEntityStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreateEntityStatement*> Deserialize(
      const ASTCreateEntityStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTRaiseStatement* node,
                                ASTRaiseStatementProto* proto);
  static absl::Status Serialize(const ASTRaiseStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTRaiseStatement* node,
                                AnyASTScriptStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTRaiseStatement* node, const ASTRaiseStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTRaiseStatement*> Deserialize(
      const ASTRaiseStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTExceptionHandler* node,
                                ASTExceptionHandlerProto* proto);
  static absl::Status DeserializeFields(
      ASTExceptionHandler* node, const ASTExceptionHandlerProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTExceptionHandler*> Deserialize(
      const ASTExceptionHandlerProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTExceptionHandlerList* node,
                                ASTExceptionHandlerListProto* proto);
  static absl::Status DeserializeFields(
      ASTExceptionHandlerList* node, const ASTExceptionHandlerListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTExceptionHandlerList*> Deserialize(
      const ASTExceptionHandlerListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTBeginEndBlock* node,
                                ASTBeginEndBlockProto* proto);
  static absl::Status Serialize(const ASTBeginEndBlock* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTBeginEndBlock* node,
                                AnyASTScriptStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTBeginEndBlock* node, const ASTBeginEndBlockProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTBeginEndBlock*> Deserialize(
      const ASTBeginEndBlockProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTIdentifierList* node,
                                ASTIdentifierListProto* proto);
  static absl::Status DeserializeFields(
      ASTIdentifierList* node, const ASTIdentifierListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTIdentifierList*> Deserialize(
      const ASTIdentifierListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTVariableDeclaration* node,
                                ASTVariableDeclarationProto* proto);
  static absl::Status Serialize(const ASTVariableDeclaration* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTVariableDeclaration* node,
                                AnyASTScriptStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTVariableDeclaration* node, const ASTVariableDeclarationProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTVariableDeclaration*> Deserialize(
      const ASTVariableDeclarationProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTUntilClause* node,
                                ASTUntilClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTUntilClause* node, const ASTUntilClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTUntilClause*> Deserialize(
      const ASTUntilClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTBreakContinueStatement* node,
                                ASTBreakContinueStatementProto* proto);
  static absl::Status Serialize(const ASTBreakContinueStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTBreakContinueStatement* node,
                                AnyASTScriptStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTBreakContinueStatement* node, const ASTBreakContinueStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTBreakContinueStatement* node,
                                AnyASTBreakContinueStatementProto* proto);
  static absl::StatusOr<ASTBreakContinueStatement*> Deserialize(
      const AnyASTBreakContinueStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTBreakContinueStatement* node, const ASTBreakContinueStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTBreakStatement* node,
                                ASTBreakStatementProto* proto);
  static absl::Status Serialize(const ASTBreakStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTBreakStatement* node,
                                AnyASTScriptStatementProto* proto);
  static absl::Status Serialize(const ASTBreakStatement* node,
                                AnyASTBreakContinueStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTBreakStatement* node, const ASTBreakStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTBreakStatement*> Deserialize(
      const ASTBreakStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTContinueStatement* node,
                                ASTContinueStatementProto* proto);
  static absl::Status Serialize(const ASTContinueStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTContinueStatement* node,
                                AnyASTScriptStatementProto* proto);
  static absl::Status Serialize(const ASTContinueStatement* node,
                                AnyASTBreakContinueStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTContinueStatement* node, const ASTContinueStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTContinueStatement*> Deserialize(
      const ASTContinueStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDropPrivilegeRestrictionStatement* node,
                                ASTDropPrivilegeRestrictionStatementProto* proto);
  static absl::Status Serialize(const ASTDropPrivilegeRestrictionStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTDropPrivilegeRestrictionStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTDropPrivilegeRestrictionStatement* node, const ASTDropPrivilegeRestrictionStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDropPrivilegeRestrictionStatement*> Deserialize(
      const ASTDropPrivilegeRestrictionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDropRowAccessPolicyStatement* node,
                                ASTDropRowAccessPolicyStatementProto* proto);
  static absl::Status Serialize(const ASTDropRowAccessPolicyStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTDropRowAccessPolicyStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTDropRowAccessPolicyStatement* node, const ASTDropRowAccessPolicyStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDropRowAccessPolicyStatement*> Deserialize(
      const ASTDropRowAccessPolicyStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreatePrivilegeRestrictionStatement* node,
                                ASTCreatePrivilegeRestrictionStatementProto* proto);
  static absl::Status Serialize(const ASTCreatePrivilegeRestrictionStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreatePrivilegeRestrictionStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreatePrivilegeRestrictionStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCreatePrivilegeRestrictionStatement* node, const ASTCreatePrivilegeRestrictionStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreatePrivilegeRestrictionStatement*> Deserialize(
      const ASTCreatePrivilegeRestrictionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateRowAccessPolicyStatement* node,
                                ASTCreateRowAccessPolicyStatementProto* proto);
  static absl::Status Serialize(const ASTCreateRowAccessPolicyStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateRowAccessPolicyStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateRowAccessPolicyStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateRowAccessPolicyStatement* node, const ASTCreateRowAccessPolicyStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreateRowAccessPolicyStatement*> Deserialize(
      const ASTCreateRowAccessPolicyStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTDropStatement* node,
                                ASTDropStatementProto* proto);
  static absl::Status Serialize(const ASTDropStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTDropStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTDropStatement* node, const ASTDropStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTDropStatement*> Deserialize(
      const ASTDropStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTReturnStatement* node,
                                ASTReturnStatementProto* proto);
  static absl::Status Serialize(const ASTReturnStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTReturnStatement* node,
                                AnyASTScriptStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTReturnStatement* node, const ASTReturnStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTReturnStatement*> Deserialize(
      const ASTReturnStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSingleAssignment* node,
                                ASTSingleAssignmentProto* proto);
  static absl::Status Serialize(const ASTSingleAssignment* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTSingleAssignment* node,
                                AnyASTScriptStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTSingleAssignment* node, const ASTSingleAssignmentProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSingleAssignment*> Deserialize(
      const ASTSingleAssignmentProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTParameterAssignment* node,
                                ASTParameterAssignmentProto* proto);
  static absl::Status Serialize(const ASTParameterAssignment* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTParameterAssignment* node, const ASTParameterAssignmentProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTParameterAssignment*> Deserialize(
      const ASTParameterAssignmentProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTSystemVariableAssignment* node,
                                ASTSystemVariableAssignmentProto* proto);
  static absl::Status Serialize(const ASTSystemVariableAssignment* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTSystemVariableAssignment* node, const ASTSystemVariableAssignmentProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTSystemVariableAssignment*> Deserialize(
      const ASTSystemVariableAssignmentProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAssignmentFromStruct* node,
                                ASTAssignmentFromStructProto* proto);
  static absl::Status Serialize(const ASTAssignmentFromStruct* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTAssignmentFromStruct* node,
                                AnyASTScriptStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTAssignmentFromStruct* node, const ASTAssignmentFromStructProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAssignmentFromStruct*> Deserialize(
      const ASTAssignmentFromStructProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateTableStmtBase* node,
                                ASTCreateTableStmtBaseProto* proto);
  static absl::Status Serialize(const ASTCreateTableStmtBase* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateTableStmtBase* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateTableStmtBase* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateTableStmtBase* node, const ASTCreateTableStmtBaseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTCreateTableStmtBase* node,
                                AnyASTCreateTableStmtBaseProto* proto);
  static absl::StatusOr<ASTCreateTableStmtBase*> Deserialize(
      const AnyASTCreateTableStmtBaseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTCreateTableStmtBase* node, const ASTCreateTableStmtBaseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateTableStatement* node,
                                ASTCreateTableStatementProto* proto);
  static absl::Status Serialize(const ASTCreateTableStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateTableStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateTableStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status Serialize(const ASTCreateTableStatement* node,
                                AnyASTCreateTableStmtBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateTableStatement* node, const ASTCreateTableStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreateTableStatement*> Deserialize(
      const ASTCreateTableStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateExternalTableStatement* node,
                                ASTCreateExternalTableStatementProto* proto);
  static absl::Status Serialize(const ASTCreateExternalTableStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateExternalTableStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateExternalTableStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status Serialize(const ASTCreateExternalTableStatement* node,
                                AnyASTCreateTableStmtBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateExternalTableStatement* node, const ASTCreateExternalTableStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreateExternalTableStatement*> Deserialize(
      const ASTCreateExternalTableStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateViewStatementBase* node,
                                ASTCreateViewStatementBaseProto* proto);
  static absl::Status Serialize(const ASTCreateViewStatementBase* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateViewStatementBase* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateViewStatementBase* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateViewStatementBase* node, const ASTCreateViewStatementBaseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTCreateViewStatementBase* node,
                                AnyASTCreateViewStatementBaseProto* proto);
  static absl::StatusOr<ASTCreateViewStatementBase*> Deserialize(
      const AnyASTCreateViewStatementBaseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTCreateViewStatementBase* node, const ASTCreateViewStatementBaseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateViewStatement* node,
                                ASTCreateViewStatementProto* proto);
  static absl::Status Serialize(const ASTCreateViewStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateViewStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateViewStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status Serialize(const ASTCreateViewStatement* node,
                                AnyASTCreateViewStatementBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateViewStatement* node, const ASTCreateViewStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreateViewStatement*> Deserialize(
      const ASTCreateViewStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateMaterializedViewStatement* node,
                                ASTCreateMaterializedViewStatementProto* proto);
  static absl::Status Serialize(const ASTCreateMaterializedViewStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateMaterializedViewStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateMaterializedViewStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status Serialize(const ASTCreateMaterializedViewStatement* node,
                                AnyASTCreateViewStatementBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateMaterializedViewStatement* node, const ASTCreateMaterializedViewStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreateMaterializedViewStatement*> Deserialize(
      const ASTCreateMaterializedViewStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTLoopStatement* node,
                                ASTLoopStatementProto* proto);
  static absl::Status Serialize(const ASTLoopStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTLoopStatement* node,
                                AnyASTScriptStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTLoopStatement* node, const ASTLoopStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTLoopStatement* node,
                                AnyASTLoopStatementProto* proto);
  static absl::StatusOr<ASTLoopStatement*> Deserialize(
      const AnyASTLoopStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTLoopStatement* node, const ASTLoopStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTWhileStatement* node,
                                ASTWhileStatementProto* proto);
  static absl::Status Serialize(const ASTWhileStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTWhileStatement* node,
                                AnyASTScriptStatementProto* proto);
  static absl::Status Serialize(const ASTWhileStatement* node,
                                AnyASTLoopStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTWhileStatement* node, const ASTWhileStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTWhileStatement*> Deserialize(
      const ASTWhileStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTRepeatStatement* node,
                                ASTRepeatStatementProto* proto);
  static absl::Status Serialize(const ASTRepeatStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTRepeatStatement* node,
                                AnyASTScriptStatementProto* proto);
  static absl::Status Serialize(const ASTRepeatStatement* node,
                                AnyASTLoopStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTRepeatStatement* node, const ASTRepeatStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTRepeatStatement*> Deserialize(
      const ASTRepeatStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTForInStatement* node,
                                ASTForInStatementProto* proto);
  static absl::Status Serialize(const ASTForInStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTForInStatement* node,
                                AnyASTScriptStatementProto* proto);
  static absl::Status Serialize(const ASTForInStatement* node,
                                AnyASTLoopStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTForInStatement* node, const ASTForInStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTForInStatement*> Deserialize(
      const ASTForInStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterStatementBase* node,
                                ASTAlterStatementBaseProto* proto);
  static absl::Status Serialize(const ASTAlterStatementBase* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTAlterStatementBase* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterStatementBase* node, const ASTAlterStatementBaseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTAlterStatementBase* node,
                                AnyASTAlterStatementBaseProto* proto);
  static absl::StatusOr<ASTAlterStatementBase*> Deserialize(
      const AnyASTAlterStatementBaseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTAlterStatementBase* node, const ASTAlterStatementBaseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterDatabaseStatement* node,
                                ASTAlterDatabaseStatementProto* proto);
  static absl::Status Serialize(const ASTAlterDatabaseStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTAlterDatabaseStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTAlterDatabaseStatement* node,
                                AnyASTAlterStatementBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterDatabaseStatement* node, const ASTAlterDatabaseStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterDatabaseStatement*> Deserialize(
      const ASTAlterDatabaseStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterSchemaStatement* node,
                                ASTAlterSchemaStatementProto* proto);
  static absl::Status Serialize(const ASTAlterSchemaStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTAlterSchemaStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTAlterSchemaStatement* node,
                                AnyASTAlterStatementBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterSchemaStatement* node, const ASTAlterSchemaStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterSchemaStatement*> Deserialize(
      const ASTAlterSchemaStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterTableStatement* node,
                                ASTAlterTableStatementProto* proto);
  static absl::Status Serialize(const ASTAlterTableStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTAlterTableStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTAlterTableStatement* node,
                                AnyASTAlterStatementBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterTableStatement* node, const ASTAlterTableStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterTableStatement*> Deserialize(
      const ASTAlterTableStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterViewStatement* node,
                                ASTAlterViewStatementProto* proto);
  static absl::Status Serialize(const ASTAlterViewStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTAlterViewStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTAlterViewStatement* node,
                                AnyASTAlterStatementBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterViewStatement* node, const ASTAlterViewStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterViewStatement*> Deserialize(
      const ASTAlterViewStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterMaterializedViewStatement* node,
                                ASTAlterMaterializedViewStatementProto* proto);
  static absl::Status Serialize(const ASTAlterMaterializedViewStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTAlterMaterializedViewStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTAlterMaterializedViewStatement* node,
                                AnyASTAlterStatementBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterMaterializedViewStatement* node, const ASTAlterMaterializedViewStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterMaterializedViewStatement*> Deserialize(
      const ASTAlterMaterializedViewStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterPrivilegeRestrictionStatement* node,
                                ASTAlterPrivilegeRestrictionStatementProto* proto);
  static absl::Status Serialize(const ASTAlterPrivilegeRestrictionStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTAlterPrivilegeRestrictionStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTAlterPrivilegeRestrictionStatement* node,
                                AnyASTAlterStatementBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterPrivilegeRestrictionStatement* node, const ASTAlterPrivilegeRestrictionStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterPrivilegeRestrictionStatement*> Deserialize(
      const ASTAlterPrivilegeRestrictionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterRowAccessPolicyStatement* node,
                                ASTAlterRowAccessPolicyStatementProto* proto);
  static absl::Status Serialize(const ASTAlterRowAccessPolicyStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTAlterRowAccessPolicyStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTAlterRowAccessPolicyStatement* node,
                                AnyASTAlterStatementBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterRowAccessPolicyStatement* node, const ASTAlterRowAccessPolicyStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterRowAccessPolicyStatement*> Deserialize(
      const ASTAlterRowAccessPolicyStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAlterEntityStatement* node,
                                ASTAlterEntityStatementProto* proto);
  static absl::Status Serialize(const ASTAlterEntityStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTAlterEntityStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTAlterEntityStatement* node,
                                AnyASTAlterStatementBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTAlterEntityStatement* node, const ASTAlterEntityStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAlterEntityStatement*> Deserialize(
      const ASTAlterEntityStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateFunctionStmtBase* node,
                                ASTCreateFunctionStmtBaseProto* proto);
  static absl::Status Serialize(const ASTCreateFunctionStmtBase* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateFunctionStmtBase* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateFunctionStmtBase* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateFunctionStmtBase* node, const ASTCreateFunctionStmtBaseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status Serialize(const ASTCreateFunctionStmtBase* node,
                                AnyASTCreateFunctionStmtBaseProto* proto);
  static absl::StatusOr<ASTCreateFunctionStmtBase*> Deserialize(
      const AnyASTCreateFunctionStmtBaseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::Status DeserializeAbstract(
      ASTCreateFunctionStmtBase* node, const ASTCreateFunctionStmtBaseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateFunctionStatement* node,
                                ASTCreateFunctionStatementProto* proto);
  static absl::Status Serialize(const ASTCreateFunctionStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateFunctionStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateFunctionStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status Serialize(const ASTCreateFunctionStatement* node,
                                AnyASTCreateFunctionStmtBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateFunctionStatement* node, const ASTCreateFunctionStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreateFunctionStatement*> Deserialize(
      const ASTCreateFunctionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTCreateTableFunctionStatement* node,
                                ASTCreateTableFunctionStatementProto* proto);
  static absl::Status Serialize(const ASTCreateTableFunctionStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTCreateTableFunctionStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTCreateTableFunctionStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status Serialize(const ASTCreateTableFunctionStatement* node,
                                AnyASTCreateFunctionStmtBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTCreateTableFunctionStatement* node, const ASTCreateTableFunctionStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTCreateTableFunctionStatement*> Deserialize(
      const ASTCreateTableFunctionStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTStructColumnSchema* node,
                                ASTStructColumnSchemaProto* proto);
  static absl::Status Serialize(const ASTStructColumnSchema* node,
                                AnyASTColumnSchemaProto* proto);
  static absl::Status DeserializeFields(
      ASTStructColumnSchema* node, const ASTStructColumnSchemaProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTStructColumnSchema*> Deserialize(
      const ASTStructColumnSchemaProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTInferredTypeColumnSchema* node,
                                ASTInferredTypeColumnSchemaProto* proto);
  static absl::Status Serialize(const ASTInferredTypeColumnSchema* node,
                                AnyASTColumnSchemaProto* proto);
  static absl::Status DeserializeFields(
      ASTInferredTypeColumnSchema* node, const ASTInferredTypeColumnSchemaProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTInferredTypeColumnSchema*> Deserialize(
      const ASTInferredTypeColumnSchemaProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTExecuteIntoClause* node,
                                ASTExecuteIntoClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTExecuteIntoClause* node, const ASTExecuteIntoClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTExecuteIntoClause*> Deserialize(
      const ASTExecuteIntoClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTExecuteUsingArgument* node,
                                ASTExecuteUsingArgumentProto* proto);
  static absl::Status DeserializeFields(
      ASTExecuteUsingArgument* node, const ASTExecuteUsingArgumentProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTExecuteUsingArgument*> Deserialize(
      const ASTExecuteUsingArgumentProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTExecuteUsingClause* node,
                                ASTExecuteUsingClauseProto* proto);
  static absl::Status DeserializeFields(
      ASTExecuteUsingClause* node, const ASTExecuteUsingClauseProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTExecuteUsingClause*> Deserialize(
      const ASTExecuteUsingClauseProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTExecuteImmediateStatement* node,
                                ASTExecuteImmediateStatementProto* proto);
  static absl::Status Serialize(const ASTExecuteImmediateStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status DeserializeFields(
      ASTExecuteImmediateStatement* node, const ASTExecuteImmediateStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTExecuteImmediateStatement*> Deserialize(
      const ASTExecuteImmediateStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAuxLoadDataFromFilesOptionsList* node,
                                ASTAuxLoadDataFromFilesOptionsListProto* proto);
  static absl::Status DeserializeFields(
      ASTAuxLoadDataFromFilesOptionsList* node, const ASTAuxLoadDataFromFilesOptionsListProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAuxLoadDataFromFilesOptionsList*> Deserialize(
      const ASTAuxLoadDataFromFilesOptionsListProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTAuxLoadDataStatement* node,
                                ASTAuxLoadDataStatementProto* proto);
  static absl::Status Serialize(const ASTAuxLoadDataStatement* node,
                                AnyASTStatementProto* proto);
  static absl::Status Serialize(const ASTAuxLoadDataStatement* node,
                                AnyASTDdlStatementProto* proto);
  static absl::Status Serialize(const ASTAuxLoadDataStatement* node,
                                AnyASTCreateStatementProto* proto);
  static absl::Status Serialize(const ASTAuxLoadDataStatement* node,
                                AnyASTCreateTableStmtBaseProto* proto);
  static absl::Status DeserializeFields(
      ASTAuxLoadDataStatement* node, const ASTAuxLoadDataStatementProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTAuxLoadDataStatement*> Deserialize(
      const ASTAuxLoadDataStatementProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);

  static absl::Status Serialize(const ASTLabel* node,
                                ASTLabelProto* proto);
  static absl::Status DeserializeFields(
      ASTLabel* node, const ASTLabelProto& proto,
      IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
  static absl::StatusOr<ASTLabel*> Deserialize(
      const ASTLabelProto& proto,
      IdStringPool* id_string_pool,
      zetasql_base::UnsafeArena* arena,
      std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes);
};
}  // namespace zetasql
// NOLINTEND
#endif  // ZETASQL_PARSER_PARSE_TREE_SERIALIZER_H_

