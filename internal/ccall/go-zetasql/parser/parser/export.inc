#ifndef ZETASQL_PARSER_PARSER_EXPORT_H
#define ZETASQL_PARSER_PARSER_EXPORT_H

#include "zetasql/parser/ast_node.h"
#include "zetasql/parser/ast_node_kind.h"
#include "zetasql/parser/parse_tree.h"
#include "zetasql/parser/parse_tree_decls.h"
#include "zetasql/parser/parse_tree_errors.h"
#include "zetasql/parser/parse_tree_visitor.h"
#include "zetasql/parser/parser.h"
#include "zetasql/parser/statement_properties.h"
#include "zetasql/parser/unparser.h"
#include "zetasql/parser/visit_result.h"

#include "zetasql/parser/bison_parser.cc"
#include "zetasql/parser/bison_parser.h"
#include "zetasql/parser/bison_parser_mode.h"
#include "zetasql/parser/flex_tokenizer.cc"
#include "zetasql/parser/flex_tokenizer.h"
#include "zetasql/parser/parser.cc"
#include "zetasql/parser/unparser.cc"


#if 0

namespace zetasql {
  namespace parser {

    BisonParser::BisonParser() {}
    BisonParser::~BisonParser() {}

    absl::Status BisonParser::Parse(BisonParserMode mode, absl::string_view filename, absl::string_view input,
                                    int start_byte_offset, IdStringPool* id_string_pool, zetasql_base::UnsafeArena* arena,
                                    const LanguageOptions& language_options, std::unique_ptr<ASTNode>* output,
                                    std::vector<std::unique_ptr<ASTNode>>* other_allocated_ast_nodes,
                                    ASTStatementProperties* ast_statement_properties,
                                    int* statement_end_byte_offset) {
      absl::Status v;
      return v;
    }

    absl::string_view BisonParser::GetFirstTokenOfNode(zetasql_bison_parser::location& bison_location) const {
      absl::string_view v;
      return v;
    }

  }
}

namespace zetasql {
  namespace parser {

    absl::Status ZetaSqlFlexTokenizer::GetNextToken(ParseLocationRange* location, int* token) {
      absl::Status v;
      return v;
    }

    bool ZetaSqlFlexTokenizer::IsDotGeneralizedIdentifierPrefixToken(int bison_token) const {
      return false;
    }

    bool ZetaSqlFlexTokenizer::IsReservedKeyword(absl::string_view text) const {
      return false;
    }

    int ZetaSqlFlexTokenizer::GetIdentifierLength(absl::string_view text) {
      return 0;
    }

  }
}

namespace zetasql {

  using parser::BisonParserMode;
  using parser::BisonParser;

  LanguageOptions LegacyDefaultParserLanguageOptions() {
    LanguageOptions v;
    return v;
  }

  ParserOptions::ParserOptions()
    : ParserOptions(LegacyDefaultParserLanguageOptions()) {}

  ParserOptions::ParserOptions(std::shared_ptr<IdStringPool> id_string_pool,
                               std::shared_ptr<zetasql_base::UnsafeArena> arena,
                               const LanguageOptions* language_options)
    : arena_(std::move(arena)), id_string_pool_(std::move(id_string_pool)) {
  }

  ParserOptions::ParserOptions(LanguageOptions language_options)
    : arena_(std::make_shared<zetasql_base::UnsafeArena>(/*block_size=*/4096)),
      id_string_pool_(std::make_shared<IdStringPool>(arena_)),
      language_options_(std::move(language_options)) {}

  ParserOptions::ParserOptions(std::shared_ptr<IdStringPool> id_string_pool,
                               std::shared_ptr<zetasql_base::UnsafeArena> arena,
                               LanguageOptions language_options)
    : arena_(std::move(arena)),
      id_string_pool_(std::move(id_string_pool)),
      language_options_(std::move(language_options)) {}

  ParserOptions::~ParserOptions() {}

  void ParserOptions::CreateDefaultArenasIfNotSet() {
  }

  ParserOutput::ParserOutput(std::shared_ptr<IdStringPool> id_string_pool,
                             std::shared_ptr<zetasql_base::UnsafeArena> arena,
                             std::vector<std::unique_ptr<ASTNode>> other_allocated_ast_nodes,
                             absl::variant<std::unique_ptr<ASTStatement>, std::unique_ptr<ASTScript>,
                             std::unique_ptr<ASTType>, std::unique_ptr<ASTExpression>>
                             node)
    : id_string_pool_(std::move(id_string_pool)),
      arena_(std::move(arena)),
      other_allocated_ast_nodes_(std::move(other_allocated_ast_nodes)),
      node_(std::move(node)) {}

  ParserOutput::~ParserOutput() {}

  absl::Status ParseStatement(absl::string_view statement_string,
                              const ParserOptions& parser_options_in,
                              std::unique_ptr<ParserOutput>* output) {
    return absl::OkStatus();
  }

  absl::Status ParseScript(absl::string_view script_string,
                           const ParserOptions& parser_options_in,
                           ErrorMessageMode error_message_mode,
                           std::unique_ptr<ParserOutput>* output) {
    return absl::OkStatus();
  }

  absl::Status ParseNextScriptStatement(ParseResumeLocation* resume_location,
                                        const ParserOptions& parser_options_in,
                                        std::unique_ptr<ParserOutput>* output,
                                        bool* at_end_of_input) {
    return absl::OkStatus();
  }

  absl::Status ParseNextStatement(ParseResumeLocation* resume_location,
                                  const ParserOptions& parser_options_in,
                                  std::unique_ptr<ParserOutput>* output,
                                  bool* at_end_of_input) {
    return absl::OkStatus();
  }

  absl::Status ParseType(absl::string_view type_string,
                         const ParserOptions& parser_options_in,
                         std::unique_ptr<ParserOutput>* output) {
    return absl::OkStatus();
  }

  absl::Status ParseExpression(absl::string_view expression_string,
                               const ParserOptions& parser_options_in,
                               std::unique_ptr<ParserOutput>* output) {
    return absl::OkStatus();
  }

  absl::Status ParseExpression(const ParseResumeLocation& resume_location,
                               const ParserOptions& parser_options_in,
                               std::unique_ptr<ParserOutput>* output) {
    return absl::OkStatus();
  }

  ASTNodeKind ParseStatementKind(absl::string_view input,
                                 const LanguageOptions& language_options,
                                 bool* statement_is_ctas) {
    ASTNodeKind v;
    return v;
  }

  ASTNodeKind ParseNextStatementKind(const ParseResumeLocation& resume_location,
                                     const LanguageOptions& language_options,
                                     bool* next_statement_is_ctas) {
    ASTNodeKind v;
    return v;
  }

  absl::Status ParseNextStatementProperties(const ParseResumeLocation& resume_location,
                                            const ParserOptions& parser_options,
                                            std::vector<std::unique_ptr<ASTNode>>* allocated_ast_nodes,
                                            parser::ASTStatementProperties* ast_statement_properties) {
    return absl::OkStatus();
  }

}

namespace zetasql {

  std::string Unparse(const ASTNode* node) {
  }

  namespace parser {

    void Formatter::Indent() {
    }

    void Formatter::Dedent() {
    }

    void Formatter::Format(absl::string_view s) {
    }

    void Formatter::FormatLine(absl::string_view s) {
    }

    void Formatter::AddUnary(absl::string_view s) {
    }

    bool Formatter::LastTokenIsSeparator() {
    }

    void Formatter::FlushLine() {
    }

    void Unparser::PrintOpenParenIfNeeded(const ASTNode* node) {
    }

    void Unparser::PrintCloseParenIfNeeded(const ASTNode* node) {
    }

    void Unparser::UnparseLeafNode(const ASTLeaf* leaf_node) {
    }

    void Unparser::UnparseChildrenWithSeparator(const ASTNode* node, void* data,
                                                const std::string& separator,
                                                bool break_line) {
    }

    void Unparser::UnparseChildrenWithSeparator(const ASTNode* node, void* data,
                                                int begin, int end,
                                                const std::string& separator,
                                                bool break_line) {
    }

    void Unparser::visitASTHintedStatement(const ASTHintedStatement* node,
                                           void* data) {
    }

    void Unparser::visitASTExplainStatement(const ASTExplainStatement* node,
                                            void* data) {
    }

    void Unparser::visitASTQueryStatement(const ASTQueryStatement* node,
                                          void* data) {
    }

    void Unparser::visitASTFunctionParameter(
                                             const ASTFunctionParameter* node, void* data) {
    }

    void Unparser::visitASTTemplatedParameterType(
                                                  const ASTTemplatedParameterType* node, void* data) {
    }

    void Unparser::visitASTFunctionParameters(
                                              const ASTFunctionParameters* node, void* data) {
    }

    void Unparser::visitASTFunctionDeclaration(
                                               const ASTFunctionDeclaration* node, void* data) {
    }

    void Unparser::visitASTSqlFunctionBody(
                                           const ASTSqlFunctionBody* node, void* data) {
    }

    void Unparser::visitASTTableClause(const ASTTableClause* node, void* data) {
    }

    void Unparser::visitASTModelClause(const ASTModelClause* node, void* data) {
    }

    void Unparser::visitASTConnectionClause(const ASTConnectionClause* node,
                                            void* data) {
    }

    void Unparser::visitASTTVF(const ASTTVF* node, void* data) {
    }

    void Unparser::visitASTTVFArgument(const ASTTVFArgument* node, void* data) {
    }

    void Unparser::visitASTTVFSchema(const ASTTVFSchema* node, void* data) {
    }

    void Unparser::visitASTTVFSchemaColumn(const ASTTVFSchemaColumn* node,
                                           void* data) {
    }

    void Unparser::visitASTCreateConstantStatement(const ASTCreateConstantStatement* node, void* data) {
    }

    void Unparser::visitASTCreateDatabaseStatement(const ASTCreateDatabaseStatement* node, void* data) {
    }

    void Unparser::visitASTCreateFunctionStatement(const ASTCreateFunctionStatement* node, void* data) {
    }

    void Unparser::visitASTCreateSchemaStatement(const ASTCreateSchemaStatement* node, void* data) {
    }

    void Unparser::visitASTCreateTableFunctionStatement(const ASTCreateTableFunctionStatement* node, void* data) {
    }

    void Unparser::visitASTAuxLoadDataFromFilesOptionsList(const ASTAuxLoadDataFromFilesOptionsList* node, void* data) {
    }

    void Unparser::visitASTAuxLoadDataStatement(const ASTAuxLoadDataStatement* node, void* data) {
    }

    void Unparser::visitASTCreateTableStatement(const ASTCreateTableStatement* node, void* data) {
    }

    void Unparser::visitASTCreateEntityStatement(const ASTCreateEntityStatement* node, void* data) {
    }

    void Unparser::visitASTAlterEntityStatement(const ASTAlterEntityStatement* node,
                                                void* data) {
    }

    void Unparser::visitASTCreateModelStatement(const ASTCreateModelStatement* node,
                                                void* data) {
    }

    void Unparser::visitASTTableElementList(const ASTTableElementList* node,
                                            void* data) {
    }

    void Unparser::visitASTNotNullColumnAttribute(const ASTNotNullColumnAttribute* node, void* data) {
    }

    void Unparser::visitASTHiddenColumnAttribute(const ASTHiddenColumnAttribute* node, void* data) {
    }

    void Unparser::visitASTPrimaryKeyColumnAttribute(const ASTPrimaryKeyColumnAttribute* node, void* data) {
    }

    void Unparser::visitASTForeignKeyColumnAttribute(const ASTForeignKeyColumnAttribute* node, void* data) {
    }

    void Unparser::visitASTColumnAttributeList(const ASTColumnAttributeList* node, void* data) {
    }

    void Unparser::visitASTColumnDefinition(const ASTColumnDefinition* node,
                                            void* data) {
    }

    void Unparser::visitASTCreateViewStatement(const ASTCreateViewStatement* node, void* data) {
    }

    void Unparser::visitASTCreateMaterializedViewStatement(const ASTCreateMaterializedViewStatement* node, void* data) {
    }

    void Unparser::visitASTWithPartitionColumnsClause(const ASTWithPartitionColumnsClause* node, void* data) {
    }

    void Unparser::visitASTCreateExternalTableStatement(const ASTCreateExternalTableStatement* node, void* data) {
    }

    void Unparser::visitASTCreateSnapshotTableStatement(const ASTCreateSnapshotTableStatement* node, void* data) {
    }

    void Unparser::visitASTGrantToClause(const ASTGrantToClause* node, void* data) {
    }

    void Unparser::visitASTRestrictToClause(const ASTRestrictToClause* node,
                                            void* data) {
    }

    void Unparser::visitASTAddToRestricteeListClause(const ASTAddToRestricteeListClause* node, void* data) {
    }

    void Unparser::visitASTRemoveFromRestricteeListClause(const ASTRemoveFromRestricteeListClause* node, void* data) {
    }

    void Unparser::visitASTFilterUsingClause(const ASTFilterUsingClause* node,
                                             void* data) {
    }

    void Unparser::visitASTCreatePrivilegeRestrictionStatement(const ASTCreatePrivilegeRestrictionStatement* node, void* data) {
    }

    void Unparser::visitASTCreateRowAccessPolicyStatement(const ASTCreateRowAccessPolicyStatement* node, void* data) {
    }

    void Unparser::visitASTExportDataStatement(const ASTExportDataStatement* node, void* data) {
    }

    void Unparser::visitASTExportModelStatement(const ASTExportModelStatement* node,
                                                void* data) {
    }

    void Unparser::visitASTWithConnectionClause(const ASTWithConnectionClause* node,
                                                void* data) {
    }

    void Unparser::visitASTCallStatement(const ASTCallStatement* node, void* data) {
    }

    void Unparser::visitASTDefineTableStatement(const ASTDefineTableStatement* node, void* data) {
    }

    void Unparser::visitASTDescribeStatement(const ASTDescribeStatement* node,
                                             void* data) {
    }

    void Unparser::visitASTDescriptorColumn(const ASTDescriptorColumn* node,
                                            void* data) {
    }

    void Unparser::visitASTDescriptorColumnList(const ASTDescriptorColumnList* node,
                                                void* data) {
    }

    void Unparser::visitASTDescriptor(const ASTDescriptor* node, void* data) {
    }

    void Unparser::visitASTShowStatement(const ASTShowStatement* node, void* data) {
    }

    void Unparser::visitASTBeginStatement(const ASTBeginStatement* node, void* data) {
    }

    void Unparser::visitASTTransactionIsolationLevel(const ASTTransactionIsolationLevel* node, void* data) {
    }

    void Unparser::visitASTTransactionReadWriteMode(const ASTTransactionReadWriteMode* node, void* data) {
    }

    void Unparser::visitASTTransactionModeList(const ASTTransactionModeList* node,
                                               void* data) {
    }

    void Unparser::visitASTSetTransactionStatement(const ASTSetTransactionStatement* node, void* data) {
    }

    void Unparser::visitASTCommitStatement(const ASTCommitStatement* node,
                                           void* data) {
    }

    void Unparser::visitASTRollbackStatement(const ASTRollbackStatement* node,
                                             void* data) {
    }

    void Unparser::visitASTStartBatchStatement(const ASTStartBatchStatement* node,
                                               void* data) {
    }

    void Unparser::visitASTRunBatchStatement(const ASTRunBatchStatement* node,
                                             void* data) {
    }

    void Unparser::visitASTAbortBatchStatement(const ASTAbortBatchStatement* node,
                                               void* data) {
    }

    void Unparser::visitASTDropStatement(const ASTDropStatement* node, void* data) {
    }

    void Unparser::visitASTDropEntityStatement(const ASTDropEntityStatement* node,
                                               void* data) {
    }

    void Unparser::visitASTDropFunctionStatement(const ASTDropFunctionStatement* node, void* data) {
    }

    void Unparser::visitASTDropTableFunctionStatement(const ASTDropTableFunctionStatement* node, void* data) {
    }

    void Unparser::visitASTDropPrivilegeRestrictionStatement(const ASTDropPrivilegeRestrictionStatement* node, void* data) {
    }

    void Unparser::visitASTDropRowAccessPolicyStatement(const ASTDropRowAccessPolicyStatement* node, void* data) {
    }

    void Unparser::visitASTDropAllRowAccessPoliciesStatement(const ASTDropAllRowAccessPoliciesStatement* node, void* data) {
    }

    void Unparser::visitASTDropSearchIndexStatement(const ASTDropSearchIndexStatement* node, void* data) {
    }

    void Unparser::visitASTDropMaterializedViewStatement(const ASTDropMaterializedViewStatement* node, void* data) {
    }

    void Unparser::visitASTDropSnapshotTableStatement(const ASTDropSnapshotTableStatement* node, void* data) {
    }

    void Unparser::visitASTRenameStatement(const ASTRenameStatement* node,
                                           void* data) {
    }

    void Unparser::visitASTImportStatement(const ASTImportStatement* node,
                                           void* data) {
    }

    void Unparser::visitASTModuleStatement(const ASTModuleStatement* node,
                                           void* data) {
    }

    void Unparser::visitASTWithClause(const ASTWithClause* node,
                                      void* data) {
    }

    void Unparser::visitASTWithClauseEntry(const ASTWithClauseEntry* node,
                                           void *data) {
    }

    void Unparser::visitASTQuery(const ASTQuery* node, void* data) {
    }

    void Unparser::visitASTSetOperation(const ASTSetOperation* node, void* data) {
    }

    void Unparser::visitASTSetAsAction(const ASTSetAsAction* node, void* data) {
    }

    void Unparser::visitASTSelect(const ASTSelect* node, void* data) {
    }

    void Unparser::visitASTSelectAs(const ASTSelectAs* node, void* data) {
    }

    void Unparser::visitASTSelectList(const ASTSelectList* node, void* data) {
    }

    void Unparser::visitASTSelectColumn(const ASTSelectColumn* node, void* data) {
    }

    void Unparser::visitASTAlias(const ASTAlias* node, void* data) {
    }

    void Unparser::visitASTIntoAlias(const ASTIntoAlias* node, void* data) {
    }

    void Unparser::visitASTFromClause(const ASTFromClause* node, void* data) {
    }

    void Unparser::visitASTTransformClause(const ASTTransformClause* node,
                                           void* data) {
    }

    void Unparser::visitASTWithOffset(const ASTWithOffset* node, void* data) {
    }

    void Unparser::visitASTUnnestExpression(const ASTUnnestExpression* node,
                                            void* data) {
    }

    void Unparser::visitASTUnnestExpressionWithOptAliasAndOffset(const ASTUnnestExpressionWithOptAliasAndOffset* node, void* data) {
    }

    void Unparser::visitASTTablePathExpression(const ASTTablePathExpression* node, void* data) {
    }

    void Unparser::visitASTPathExpressionList(const ASTPathExpressionList* node,
                                              void* data) {
    }

    void Unparser::visitASTForSystemTime(const ASTForSystemTime* node, void* data) {
    }

    void Unparser::visitASTTableSubquery(const ASTTableSubquery* node, void* data) {
    }

    void Unparser::visitASTJoin(const ASTJoin* node, void* data) {
    }

    void Unparser::visitASTParenthesizedJoin(const ASTParenthesizedJoin* node,
                                             void* data) {
    }

    void Unparser::visitASTOnClause(const ASTOnClause* node, void* data) {
    }

    void Unparser::visitASTOnOrUsingClauseList(const ASTOnOrUsingClauseList* node,
                                               void* data) {
    }

    void Unparser::visitASTUsingClause(const ASTUsingClause* node, void* data) {
    }

    void Unparser::visitASTWhereClause(const ASTWhereClause* node, void* data) {
    }

    void Unparser::visitASTRollup(const ASTRollup* node, void* data) {
    }

    void Unparser::visitASTGroupingItem(const ASTGroupingItem* node, void* data) {
    }

    void Unparser::visitASTGroupBy(const ASTGroupBy* node, void* data) {
    }

    void Unparser::visitASTHaving(const ASTHaving* node, void* data) {
    }

    void Unparser::visitASTQualify(const ASTQualify* node, void* data) {
    }

    void Unparser::visitASTCollate(const ASTCollate* node, void* data) {
    }

    void Unparser::visitASTOrderBy(const ASTOrderBy* node, void* data) {
    }

    void Unparser::visitASTNullOrder(const ASTNullOrder* node, void* data) {
    }

    void Unparser::visitASTOrderingExpression(const ASTOrderingExpression* node,
                                              void* data) {
    }

    void Unparser::visitASTLimitOffset(const ASTLimitOffset* node, void* data) {
    }

    void Unparser::visitASTHavingModifier(const ASTHavingModifier* node,
                                          void* data) {
    }

    void Unparser::visitASTClampedBetweenModifier(const ASTClampedBetweenModifier* node, void* data) {
    }

    void Unparser::UnparseASTTableDataSource(const ASTTableDataSource* node,
                                             void* data) {
    }

    void Unparser::visitASTCloneDataSourceList(const ASTCloneDataSourceList* node,
                                               void* data) {
    }

    void Unparser::visitASTCloneDataStatement(const ASTCloneDataStatement* node,
                                              void* data) {
    }

    void Unparser::visitASTIdentifier(const ASTIdentifier* node, void* data) {
    }

    void Unparser::visitASTNewConstructorArg(const ASTNewConstructorArg* node,
                                             void* data) {
    }

    void Unparser::visitASTNewConstructor(const ASTNewConstructor* node,
                                          void* data) {
    }

    void Unparser::visitASTInferredTypeColumnSchema(const ASTInferredTypeColumnSchema* node, void* data) {
    }

    void Unparser::visitASTArrayConstructor(const ASTArrayConstructor* node,
                                            void* data) {
    }

    void Unparser::visitASTStructConstructorArg(const ASTStructConstructorArg* node,
                                                void* data) {
    }

    void Unparser::visitASTStructConstructorWithParens(const ASTStructConstructorWithParens* node, void* data) {
    }

    void Unparser::visitASTStructConstructorWithKeyword(const ASTStructConstructorWithKeyword* node, void* data) {
    }

    void Unparser::visitASTIntLiteral(const ASTIntLiteral* node, void* data) {
    }

    void Unparser::visitASTNumericLiteral(const ASTNumericLiteral* node, void* data) {
    }

    void Unparser::visitASTBigNumericLiteral(const ASTBigNumericLiteral* node,
                                             void* data) {
    }

    void Unparser::visitASTJSONLiteral(const ASTJSONLiteral* node, void* data) {
    }

    void Unparser::visitASTFloatLiteral(const ASTFloatLiteral* node, void* data) {
    }

    void Unparser::visitASTStringLiteral(const ASTStringLiteral* node, void* data) {
    }

    void Unparser::visitASTBytesLiteral(const ASTBytesLiteral* node, void* data) {
    }

    void Unparser::visitASTBooleanLiteral(const ASTBooleanLiteral* node,
                                          void* data) {
    }

    void Unparser::visitASTNullLiteral(const ASTNullLiteral* node, void* data) {
    }

    void Unparser::visitASTDateOrTimeLiteral(const ASTDateOrTimeLiteral* node,
                                             void* data) {
    }

    void Unparser::visitASTStar(const ASTStar* node, void* data) {
    }

    void Unparser::visitASTStarExceptList(const ASTStarExceptList* node,
                                          void* data) {
    }

    void Unparser::visitASTStarReplaceItem(const ASTStarReplaceItem* node,
                                           void* data) {
    }

    void Unparser::visitASTStarModifiers(const ASTStarModifiers* node, void* data) {
    }

    void Unparser::visitASTStarWithModifiers(const ASTStarWithModifiers* node,
                                             void* data) {
    }

    void Unparser::visitASTPathExpression(const ASTPathExpression* node,
                                          void* data) {
    }

    void Unparser::visitASTParameterExpr(const ASTParameterExpr* node, void* data) {
    }

    void Unparser::visitASTSystemVariableExpr(const ASTSystemVariableExpr* node,
                                              void* data) {
    }

    void Unparser::visitASTIntervalExpr(const ASTIntervalExpr* node, void* data) {
    }

    void Unparser::visitASTDotIdentifier(const ASTDotIdentifier* node,
                                         void* data) {
    }

    void Unparser::visitASTDotGeneralizedField(const ASTDotGeneralizedField* node,
                                               void* data) {
    }

    void Unparser::visitASTDotStar(const ASTDotStar* node, void* data) {
    }

    void Unparser::visitASTDotStarWithModifiers(const ASTDotStarWithModifiers* node, void* data) {
    }

    void Unparser::visitASTOrExpr(const ASTOrExpr* node, void* data) {
    }

    void Unparser::visitASTAndExpr(const ASTAndExpr* node, void* data) {
    }

    void Unparser::visitASTUnaryExpression(const ASTUnaryExpression* node,
                                           void* data) {
    }

    void Unparser::visitASTFormatClause(const ASTFormatClause *node, void *data) {
    }

    void Unparser::visitASTCastExpression(const ASTCastExpression* node,
                                          void* data) {
    }

    void Unparser::visitASTExtractExpression(const ASTExtractExpression* node,
                                             void* data) {
    }

    void Unparser::visitASTCaseNoValueExpression(const ASTCaseNoValueExpression* node, void* data) {
    }

    void Unparser::visitASTCaseValueExpression(const ASTCaseValueExpression* node,
                                               void* data) {
    }

    void Unparser::visitASTBinaryExpression(const ASTBinaryExpression* node,
                                            void* data) {
    }

    void Unparser::visitASTBitwiseShiftExpression(const ASTBitwiseShiftExpression* node, void* data) {
    }

    void Unparser::visitASTInExpression(const ASTInExpression* node, void* data) {
    }

    void Unparser::visitASTInList(const ASTInList* node, void* data) {
    }

    void Unparser::visitASTLikeExpression(const ASTLikeExpression* node,
                                          void* data) {
    }

    void Unparser::visitASTAnySomeAllOp(const ASTAnySomeAllOp* node, void* data) {
    }

    void Unparser::visitASTBetweenExpression(const ASTBetweenExpression* node,
                                             void* data) {
    }

    void Unparser::visitASTFunctionCall(const ASTFunctionCall* node, void* data) {
    }

    void Unparser::visitASTWithGroupRows(const ASTWithGroupRows* node, void* data) {
    }

    void Unparser::visitASTArrayElement(const ASTArrayElement* node, void* data) {
    }

    void Unparser::visitASTExpressionSubquery(const ASTExpressionSubquery* node,
                                              void* data) {
    }

    void Unparser::visitASTHint(const ASTHint* node, void* data) {
    }

    void Unparser::visitASTHintEntry(const ASTHintEntry* node, void* data) {
    }

    void Unparser::visitASTOptionsList(const ASTOptionsList* node, void* data) {
    }

    void Unparser::visitASTOptionsEntry(const ASTOptionsEntry* node, void* data) {
    }

    void Unparser::visitASTMaxLiteral(const ASTMaxLiteral* node, void* data) {
    }

    void Unparser::visitASTTypeParameterList(const ASTTypeParameterList* node,
                                             void* data) {
    }

    void Unparser::visitASTSimpleType(const ASTSimpleType* node, void* data) {
    }

    void Unparser::visitASTArrayType(const ASTArrayType* node, void* data) {
    }

    void Unparser::visitASTStructType(const ASTStructType* node, void* data) {
    }

    void Unparser::visitASTStructField(const ASTStructField* node, void* data) {
    }

    void Unparser::visitASTSimpleColumnSchema(const ASTSimpleColumnSchema* node,
                                              void* data) {
    }

    void Unparser::visitASTArrayColumnSchema(const ASTArrayColumnSchema* node,
                                             void* data) {
    }

    void Unparser::visitASTStructColumnSchema(const ASTStructColumnSchema* node,
                                              void* data) {
    }

    void Unparser::visitASTGeneratedColumnInfo(const ASTGeneratedColumnInfo* node,
                                               void* data) {
    }

    void Unparser::visitASTStructColumnField(const ASTStructColumnField* node,
                                             void* data) {
    }

    void Unparser::UnparseColumnSchema(const ASTColumnSchema* node, void* data) {
    }

    void Unparser::visitASTAnalyticFunctionCall(const ASTAnalyticFunctionCall* node,
                                                void* data) {
    }

    void Unparser::visitASTFunctionCallWithGroupRows(
                                                     const ASTFunctionCallWithGroupRows* node, void* data) {
    }

    void Unparser::visitASTWindowClause(const ASTWindowClause* node, void* data) {
    }

    void Unparser::visitASTWindowDefinition(const ASTWindowDefinition* node, void* data) {
    }

    void Unparser::visitASTWindowSpecification(const ASTWindowSpecification* node, void* data) {
    }

    void Unparser::visitASTPartitionBy(const ASTPartitionBy* node, void* data) {
    }

    void Unparser::visitASTClusterBy(const ASTClusterBy* node, void* data) {
    }

    void Unparser::visitASTWindowFrame(const ASTWindowFrame* node,
                                       void* data) {
    }

    void Unparser::visitASTWindowFrameExpr(const ASTWindowFrameExpr* node, void* data) {
    }

    void Unparser::visitASTDefaultLiteral(const ASTDefaultLiteral* node,
                                          void* data) {
    }

    void Unparser::visitASTAnalyzeStatement(const ASTAnalyzeStatement* node,
                                            void* data) {
    }

    void Unparser::visitASTTableAndColumnInfo(const ASTTableAndColumnInfo* node,
                                              void* data) {
    }

    void Unparser::visitASTTableAndColumnInfoList(const ASTTableAndColumnInfoList* node, void* data) {
    }

    void Unparser::visitASTAssertStatement(const ASTAssertStatement* node,
                                           void* data) {
    }

    void Unparser::visitASTAssertRowsModified(const ASTAssertRowsModified* node,
                                              void* data) {
    }

    void Unparser::visitASTReturningClause(const ASTReturningClause* node,
                                           void* data) {
    }

    void Unparser::visitASTDeleteStatement(const ASTDeleteStatement* node,
                                           void* data) {
    }

    void Unparser::visitASTColumnList(const ASTColumnList* node, void* data) {
    }

    void Unparser::visitASTInsertValuesRow(const ASTInsertValuesRow* node,
                                           void* data) {
    }

    void Unparser::visitASTInsertValuesRowList(const ASTInsertValuesRowList* node,
                                               void* data) {
    }

    void Unparser::visitASTInsertStatement(const ASTInsertStatement* node,
                                           void* data) {
    }

    void Unparser::visitASTUpdateSetValue(const ASTUpdateSetValue* node,
                                          void* data) {
    }

    void Unparser::visitASTUpdateItem(const ASTUpdateItem* node, void* data) {
    }

    void Unparser::visitASTUpdateItemList(const ASTUpdateItemList* node,
                                          void* data) {
    }

    void Unparser::visitASTUpdateStatement(const ASTUpdateStatement* node,
                                           void* data) {
    }

    void Unparser::visitASTTruncateStatement(const ASTTruncateStatement* node,
                                             void* data) {
    }

    void Unparser::visitASTMergeAction(const ASTMergeAction* node, void* data) {
    }

    void Unparser::visitASTMergeWhenClause(const ASTMergeWhenClause* node,
                                           void* data) {
    }

    void Unparser::visitASTMergeWhenClauseList(const ASTMergeWhenClauseList* node,
                                               void* data) {
    }

    void Unparser::visitASTMergeStatement(const ASTMergeStatement* node,
                                          void* data) {
    }

    void Unparser::visitASTPrimaryKey(const ASTPrimaryKey* node, void* data) {
    }

    void Unparser::visitASTPrivilege(const ASTPrivilege* node, void* data) {
    }

    void Unparser::visitASTPrivileges(const ASTPrivileges* node, void* data) {
    }

    void Unparser::visitASTGranteeList(const ASTGranteeList* node, void* data) {
    }

    void Unparser::visitASTGrantStatement(const ASTGrantStatement* node,
                                          void* data) {
    }

    void Unparser::visitASTRevokeStatement(const ASTRevokeStatement* node,
                                           void* data) {
    }

    void Unparser::visitASTRepeatableClause(const ASTRepeatableClause* node,
                                            void* data) {
    }

    void Unparser::visitASTReplaceFieldsArg(const ASTReplaceFieldsArg* node,
                                            void* data) {
    }

    void Unparser::visitASTReplaceFieldsExpression(const ASTReplaceFieldsExpression* node, void* data) {
    }

    void Unparser::visitASTFilterFieldsArg(const ASTFilterFieldsArg* node,
                                           void* data) {
    }

    void Unparser::visitASTPivotExpression(const ASTPivotExpression* node,
                                           void* data) {
    }

    void Unparser::visitASTPivotExpressionList(const ASTPivotExpressionList* node,
                                               void* data) {
    }

    void Unparser::visitASTPivotValue(const ASTPivotValue* node, void* data) {
    }

    void Unparser::visitASTPivotValueList(const ASTPivotValueList* node,
                                          void* data) {
    }

    void Unparser::visitASTPivotClause(const ASTPivotClause* node, void* data) {
    }

    void Unparser::visitASTUnpivotInItem(const ASTUnpivotInItem* node, void* data) {
    }

    void Unparser::visitASTUnpivotInItemList(const ASTUnpivotInItemList* node,
                                             void* data) {
    }

    void Unparser::visitASTUnpivotInItemLabel(const ASTUnpivotInItemLabel* node,
                                              void* data) {
    }

    void Unparser::visitASTUnpivotClause(const ASTUnpivotClause* node, void* data) {
    }

    void Unparser::visitASTSampleSize(const ASTSampleSize* node, void* data) {
    }

    void Unparser::visitASTSampleSuffix(const ASTSampleSuffix* node, void* data) {
    }

    void Unparser::visitASTWithWeight(const ASTWithWeight* node, void *data) {
    }

    void Unparser::visitASTSampleClause(const ASTSampleClause* node, void* data) {
    }

    void Unparser::VisitAlterStatementBase(const ASTAlterStatementBase* node,
                                           void* data) {
    }

    void Unparser::visitASTAlterMaterializedViewStatement(const ASTAlterMaterializedViewStatement* node, void* data) {
    }

    void Unparser::visitASTAlterDatabaseStatement(const ASTAlterDatabaseStatement* node, void* data) {
    }

    void Unparser::visitASTAlterSchemaStatement(const ASTAlterSchemaStatement* node, void* data) {
    }

    void Unparser::visitASTAlterTableStatement(const ASTAlterTableStatement* node,
                                               void* data) {
    }

    void Unparser::visitASTAlterViewStatement(const ASTAlterViewStatement* node,
                                              void* data) {
    }

    void Unparser::visitASTSetOptionsAction(const ASTSetOptionsAction* node,
                                            void* data) {
    }

    void Unparser::VisitCheckConstraintSpec(const ASTCheckConstraint* node,
                                            void* data) {
    }

    void Unparser::visitASTAddConstraintAction(const ASTAddConstraintAction* node,
                                               void* data) {
    }

    void Unparser::visitASTDropConstraintAction(const ASTDropConstraintAction* node,
                                                void* data) {
    }

    void Unparser::visitASTDropPrimaryKeyAction(const ASTDropPrimaryKeyAction* node,
                                                void* data) {
    }

    void Unparser::visitASTAlterConstraintEnforcementAction(
                                                            const ASTAlterConstraintEnforcementAction* node, void* data) {
    }

    void Unparser::visitASTAlterConstraintSetOptionsAction(
                                                           const ASTAlterConstraintSetOptionsAction* node, void* data) {
    }

    void Unparser::visitASTAddColumnAction(const ASTAddColumnAction* node,
                                           void* data) {
    }

    void Unparser::visitASTColumnPosition(const ASTColumnPosition* node,
                                          void* data) {
    }

    void Unparser::visitASTDropColumnAction(const ASTDropColumnAction* node,
                                            void* data) {
    }

    void Unparser::visitASTRenameColumnAction(const ASTRenameColumnAction* node,
                                              void* data) {
    }

    void Unparser::visitASTAlterColumnOptionsAction(const ASTAlterColumnOptionsAction* node, void* data) {
    }

    void Unparser::visitASTAlterColumnDropNotNullAction(const ASTAlterColumnDropNotNullAction* node, void* data) {
    }

    void Unparser::visitASTAlterColumnTypeAction(const ASTAlterColumnTypeAction* node, void* data) {
    }

    void Unparser::visitASTAlterColumnSetDefaultAction(const ASTAlterColumnSetDefaultAction* node, void* data) {
    }

    void Unparser::visitASTAlterColumnDropDefaultAction(const ASTAlterColumnDropDefaultAction* node, void* data) {
    }

    void Unparser::visitASTRevokeFromClause(const ASTRevokeFromClause* node,
                                            void* data) {
    }

    void Unparser::visitASTRenameToClause(const ASTRenameToClause* node,
                                          void* data) {
    }

    void Unparser::visitASTSetCollateClause(const ASTSetCollateClause* node,
                                            void* data) {
    }

    void Unparser::visitASTAlterActionList(const ASTAlterActionList* node,
                                           void* data) {
    }

    void Unparser::visitASTAlterPrivilegeRestrictionStatement(const ASTAlterPrivilegeRestrictionStatement* node, void* data) {
    }

    void Unparser::visitASTAlterRowAccessPolicyStatement(const ASTAlterRowAccessPolicyStatement* node, void* data) {
    }

    void Unparser::visitASTAlterAllRowAccessPoliciesStatement(const ASTAlterAllRowAccessPoliciesStatement* node, void* data) {
    }

    void Unparser::visitASTCreateIndexStatement(const ASTCreateIndexStatement* node,
                                                void* data) {
    }

    void Unparser::visitASTStatementList(const ASTStatementList* node, void* data) {
    }

    void Unparser::visitASTElseifClause(const ASTElseifClause* node, void* data) {
    }

    void Unparser::visitASTElseifClauseList(const ASTElseifClauseList* node,
                                            void* data) {
    }

    void Unparser::visitASTIfStatement(const ASTIfStatement* node, void* data) {
    }

    void Unparser::visitASTWhenThenClause(const ASTWhenThenClause* node,
                                          void* data) {
    }

    void Unparser::visitASTWhenThenClauseList(const ASTWhenThenClauseList* node,
                                              void* data) {
    }

    void Unparser::visitASTCaseStatement(const ASTCaseStatement* node, void* data) {
    }

    void Unparser::visitASTBeginEndBlock(const ASTBeginEndBlock* node, void* data) {
    }

    void Unparser::visitASTIndexAllColumns(const ASTIndexAllColumns* node,
                                           void* data) {
    }

    void Unparser::visitASTIndexItemList(const ASTIndexItemList* node, void* data) {
    }

    void Unparser::visitASTIndexStoringExpressionList(const ASTIndexStoringExpressionList* node, void* data) {
    }

    void Unparser::visitASTIndexUnnestExpressionList(const ASTIndexUnnestExpressionList* node, void* data) {
    }

    void Unparser::VisitForeignKeySpec(const ASTForeignKey* node, void* data) {
    }

    void Unparser::visitASTForeignKey(const ASTForeignKey* node, void* data) {
    }

    void Unparser::visitASTForeignKeyReference(const ASTForeignKeyReference* node, void* data) {
    }

    void Unparser::visitASTForeignKeyActions(const ASTForeignKeyActions* node, void* data) {
    }

    void Unparser::visitASTCheckConstraint(const ASTCheckConstraint* node,
                                           void* data) {
    }

    void Unparser::visitASTIdentifierList(const ASTIdentifierList* node,
                                          void* data) {
    }

    void Unparser::visitASTVariableDeclaration(const ASTVariableDeclaration* node,
                                               void* data) {
    }

    void Unparser::visitASTSingleAssignment(const ASTSingleAssignment* node,
                                            void* data) {
    }

    void Unparser::visitASTParameterAssignment(const ASTParameterAssignment* node,
                                               void* data) {
    }

    void Unparser::visitASTSystemVariableAssignment(const ASTSystemVariableAssignment* node, void* data) {
    }

    void Unparser::visitASTAssignmentFromStruct(const ASTAssignmentFromStruct* node,
                                                void* data) {
    }

    void Unparser::visitASTWhileStatement(const ASTWhileStatement* node,
                                          void* data) {
    }

    void Unparser::visitASTUntilClause(const ASTUntilClause* node,
                                       void* data) {
    }

    void Unparser::visitASTRepeatStatement(const ASTRepeatStatement* node,
                                           void* data) {
    }

    void Unparser::visitASTForInStatement(const ASTForInStatement* node,
                                          void* data) {
    }

    void Unparser::visitASTLabel(const ASTLabel* node, void* data) {
    }

    void Unparser::visitASTScript(const ASTScript* node, void* data) {
    }

    void Unparser::visitASTBreakStatement(const ASTBreakStatement* node,
                                          void* data) {
    }

    void Unparser::visitASTContinueStatement(const ASTContinueStatement* node,
                                             void* data) {
    }

    void Unparser::visitASTReturnStatement(const ASTReturnStatement* node,
                                           void* data) {
    }

    void Unparser::visitASTCreateProcedureStatement(const ASTCreateProcedureStatement* node, void* data) {
    }

    void Unparser::visitASTNamedArgument(const ASTNamedArgument* node, void* data) {
    }

    void Unparser::visitASTLambda(const ASTLambda* node, void* data) {
    }

    void Unparser::visitASTExceptionHandler(const ASTExceptionHandler* node,
                                            void* data) {
    }

    void Unparser::visitASTExceptionHandlerList(const ASTExceptionHandlerList* node,
                                                void* data) {
    }

    void Unparser::visitASTExecuteIntoClause(const ASTExecuteIntoClause* node,
                                             void* data) {
    }

    void Unparser::visitASTExecuteUsingArgument(const ASTExecuteUsingArgument* node,
                                                void* data) {
    }

    void Unparser::visitASTExecuteUsingClause(const ASTExecuteUsingClause* node,
                                              void* data) {
    }

    void Unparser::visitASTExecuteImmediateStatement(const ASTExecuteImmediateStatement* node, void* data) {
    }

    void Unparser::visitASTRaiseStatement(const ASTRaiseStatement* node,
                                          void* data) {
    }

  }
}

#endif

#include "go-zetasql/parser/ast_enums_cc_proto/export.inc"
#include "go-zetasql/parser/bison_parser_generated_lib/export.inc"
#include "go-zetasql/parser/flex_istream/export.inc"
#include "go-zetasql/parser/keywords/export.inc"
#include "go-zetasql/parser/parse_tree/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/arena/export.inc"
#include "go-zetasql/base/arena_allocator/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/utf_util/export.inc"
#include "go-zetasql/proto/internal_error_location_cc_proto/export.inc"
#include "go-zetasql/public/error_helpers/export.inc"
#include "go-zetasql/public/error_location_cc_proto/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/parse_resume_location/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/cleanup/cleanup/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/inlined_vector/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"
#include "go-absl/types/variant/export.inc"
#include "go-re2/re2/export.inc"

#endif
