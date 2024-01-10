#ifndef STORAGE_ZETASQL_PARSER_PARSE_TREE_VISITOR_H_
#define STORAGE_ZETASQL_PARSER_PARSE_TREE_VISITOR_H_
#include "zetasql/parser/parse_tree.h"
#include "zetasql/parser/visit_result.h"

namespace zetasql {
class ParseTreeVisitor {
 public:
  virtual ~ParseTreeVisitor() {}
  virtual void visit(const ASTNode *node, void* data) = 0;
  virtual void visitASTQueryStatement(const ASTQueryStatement* node, void* data) = 0;

  virtual void visitASTQuery(const ASTQuery* node, void* data) = 0;

  virtual void visitASTSelect(const ASTSelect* node, void* data) = 0;

  virtual void visitASTSelectList(const ASTSelectList* node, void* data) = 0;

  virtual void visitASTSelectColumn(const ASTSelectColumn* node, void* data) = 0;

  virtual void visitASTIntLiteral(const ASTIntLiteral* node, void* data) = 0;

  virtual void visitASTIdentifier(const ASTIdentifier* node, void* data) = 0;

  virtual void visitASTAlias(const ASTAlias* node, void* data) = 0;

  virtual void visitASTPathExpression(const ASTPathExpression* node, void* data) = 0;

  virtual void visitASTTablePathExpression(const ASTTablePathExpression* node, void* data) = 0;

  virtual void visitASTFromClause(const ASTFromClause* node, void* data) = 0;

  virtual void visitASTWhereClause(const ASTWhereClause* node, void* data) = 0;

  virtual void visitASTBooleanLiteral(const ASTBooleanLiteral* node, void* data) = 0;

  virtual void visitASTAndExpr(const ASTAndExpr* node, void* data) = 0;

  virtual void visitASTBinaryExpression(const ASTBinaryExpression* node, void* data) = 0;

  virtual void visitASTStringLiteral(const ASTStringLiteral* node, void* data) = 0;

  virtual void visitASTStar(const ASTStar* node, void* data) = 0;

  virtual void visitASTOrExpr(const ASTOrExpr* node, void* data) = 0;

  virtual void visitASTGroupingItem(const ASTGroupingItem* node, void* data) = 0;

  virtual void visitASTGroupBy(const ASTGroupBy* node, void* data) = 0;

  virtual void visitASTOrderingExpression(const ASTOrderingExpression* node, void* data) = 0;

  virtual void visitASTOrderBy(const ASTOrderBy* node, void* data) = 0;

  virtual void visitASTLimitOffset(const ASTLimitOffset* node, void* data) = 0;

  virtual void visitASTFloatLiteral(const ASTFloatLiteral* node, void* data) = 0;

  virtual void visitASTNullLiteral(const ASTNullLiteral* node, void* data) = 0;

  virtual void visitASTOnClause(const ASTOnClause* node, void* data) = 0;

  virtual void visitASTWithClauseEntry(const ASTWithClauseEntry* node, void* data) = 0;

  virtual void visitASTJoin(const ASTJoin* node, void* data) = 0;

  virtual void visitASTWithClause(const ASTWithClause* node, void* data) = 0;

  virtual void visitASTHaving(const ASTHaving* node, void* data) = 0;

  virtual void visitASTSimpleType(const ASTSimpleType* node, void* data) = 0;

  virtual void visitASTArrayType(const ASTArrayType* node, void* data) = 0;

  virtual void visitASTStructField(const ASTStructField* node, void* data) = 0;

  virtual void visitASTStructType(const ASTStructType* node, void* data) = 0;

  virtual void visitASTCastExpression(const ASTCastExpression* node, void* data) = 0;

  virtual void visitASTSelectAs(const ASTSelectAs* node, void* data) = 0;

  virtual void visitASTRollup(const ASTRollup* node, void* data) = 0;

  virtual void visitASTFunctionCall(const ASTFunctionCall* node, void* data) = 0;

  virtual void visitASTArrayConstructor(const ASTArrayConstructor* node, void* data) = 0;

  virtual void visitASTStructConstructorArg(const ASTStructConstructorArg* node, void* data) = 0;

  virtual void visitASTStructConstructorWithParens(const ASTStructConstructorWithParens* node, void* data) = 0;

  virtual void visitASTStructConstructorWithKeyword(const ASTStructConstructorWithKeyword* node, void* data) = 0;

  virtual void visitASTInExpression(const ASTInExpression* node, void* data) = 0;

  virtual void visitASTInList(const ASTInList* node, void* data) = 0;

  virtual void visitASTBetweenExpression(const ASTBetweenExpression* node, void* data) = 0;

  virtual void visitASTNumericLiteral(const ASTNumericLiteral* node, void* data) = 0;

  virtual void visitASTBigNumericLiteral(const ASTBigNumericLiteral* node, void* data) = 0;

  virtual void visitASTBytesLiteral(const ASTBytesLiteral* node, void* data) = 0;

  virtual void visitASTDateOrTimeLiteral(const ASTDateOrTimeLiteral* node, void* data) = 0;

  virtual void visitASTMaxLiteral(const ASTMaxLiteral* node, void* data) = 0;

  virtual void visitASTJSONLiteral(const ASTJSONLiteral* node, void* data) = 0;

  virtual void visitASTCaseValueExpression(const ASTCaseValueExpression* node, void* data) = 0;

  virtual void visitASTCaseNoValueExpression(const ASTCaseNoValueExpression* node, void* data) = 0;

  virtual void visitASTArrayElement(const ASTArrayElement* node, void* data) = 0;

  virtual void visitASTBitwiseShiftExpression(const ASTBitwiseShiftExpression* node, void* data) = 0;

  virtual void visitASTCollate(const ASTCollate* node, void* data) = 0;

  virtual void visitASTDotGeneralizedField(const ASTDotGeneralizedField* node, void* data) = 0;

  virtual void visitASTDotIdentifier(const ASTDotIdentifier* node, void* data) = 0;

  virtual void visitASTDotStar(const ASTDotStar* node, void* data) = 0;

  virtual void visitASTDotStarWithModifiers(const ASTDotStarWithModifiers* node, void* data) = 0;

  virtual void visitASTExpressionSubquery(const ASTExpressionSubquery* node, void* data) = 0;

  virtual void visitASTExtractExpression(const ASTExtractExpression* node, void* data) = 0;

  virtual void visitASTHavingModifier(const ASTHavingModifier* node, void* data) = 0;

  virtual void visitASTIntervalExpr(const ASTIntervalExpr* node, void* data) = 0;

  virtual void visitASTNamedArgument(const ASTNamedArgument* node, void* data) = 0;

  virtual void visitASTNullOrder(const ASTNullOrder* node, void* data) = 0;

  virtual void visitASTOnOrUsingClauseList(const ASTOnOrUsingClauseList* node, void* data) = 0;

  virtual void visitASTParenthesizedJoin(const ASTParenthesizedJoin* node, void* data) = 0;

  virtual void visitASTPartitionBy(const ASTPartitionBy* node, void* data) = 0;

  virtual void visitASTSetOperation(const ASTSetOperation* node, void* data) = 0;

  virtual void visitASTStarExceptList(const ASTStarExceptList* node, void* data) = 0;

  virtual void visitASTStarModifiers(const ASTStarModifiers* node, void* data) = 0;

  virtual void visitASTStarReplaceItem(const ASTStarReplaceItem* node, void* data) = 0;

  virtual void visitASTStarWithModifiers(const ASTStarWithModifiers* node, void* data) = 0;

  virtual void visitASTTableSubquery(const ASTTableSubquery* node, void* data) = 0;

  virtual void visitASTUnaryExpression(const ASTUnaryExpression* node, void* data) = 0;

  virtual void visitASTUnnestExpression(const ASTUnnestExpression* node, void* data) = 0;

  virtual void visitASTWindowClause(const ASTWindowClause* node, void* data) = 0;

  virtual void visitASTWindowDefinition(const ASTWindowDefinition* node, void* data) = 0;

  virtual void visitASTWindowFrame(const ASTWindowFrame* node, void* data) = 0;

  virtual void visitASTWindowFrameExpr(const ASTWindowFrameExpr* node, void* data) = 0;

  virtual void visitASTLikeExpression(const ASTLikeExpression* node, void* data) = 0;

  virtual void visitASTWindowSpecification(const ASTWindowSpecification* node, void* data) = 0;

  virtual void visitASTWithOffset(const ASTWithOffset* node, void* data) = 0;

  virtual void visitASTAnySomeAllOp(const ASTAnySomeAllOp* node, void* data) = 0;

  virtual void visitASTStatementList(const ASTStatementList* node, void* data) = 0;

  virtual void visitASTHintedStatement(const ASTHintedStatement* node, void* data) = 0;

  virtual void visitASTExplainStatement(const ASTExplainStatement* node, void* data) = 0;

  virtual void visitASTDescribeStatement(const ASTDescribeStatement* node, void* data) = 0;

  virtual void visitASTShowStatement(const ASTShowStatement* node, void* data) = 0;

  virtual void visitASTTransactionIsolationLevel(const ASTTransactionIsolationLevel* node, void* data) = 0;

  virtual void visitASTTransactionReadWriteMode(const ASTTransactionReadWriteMode* node, void* data) = 0;

  virtual void visitASTTransactionModeList(const ASTTransactionModeList* node, void* data) = 0;

  virtual void visitASTBeginStatement(const ASTBeginStatement* node, void* data) = 0;

  virtual void visitASTSetTransactionStatement(const ASTSetTransactionStatement* node, void* data) = 0;

  virtual void visitASTCommitStatement(const ASTCommitStatement* node, void* data) = 0;

  virtual void visitASTRollbackStatement(const ASTRollbackStatement* node, void* data) = 0;

  virtual void visitASTStartBatchStatement(const ASTStartBatchStatement* node, void* data) = 0;

  virtual void visitASTRunBatchStatement(const ASTRunBatchStatement* node, void* data) = 0;

  virtual void visitASTAbortBatchStatement(const ASTAbortBatchStatement* node, void* data) = 0;

  virtual void visitASTDropEntityStatement(const ASTDropEntityStatement* node, void* data) = 0;

  virtual void visitASTDropFunctionStatement(const ASTDropFunctionStatement* node, void* data) = 0;

  virtual void visitASTDropTableFunctionStatement(const ASTDropTableFunctionStatement* node, void* data) = 0;

  virtual void visitASTDropAllRowAccessPoliciesStatement(const ASTDropAllRowAccessPoliciesStatement* node, void* data) = 0;

  virtual void visitASTDropMaterializedViewStatement(const ASTDropMaterializedViewStatement* node, void* data) = 0;

  virtual void visitASTDropSnapshotTableStatement(const ASTDropSnapshotTableStatement* node, void* data) = 0;

  virtual void visitASTDropSearchIndexStatement(const ASTDropSearchIndexStatement* node, void* data) = 0;

  virtual void visitASTRenameStatement(const ASTRenameStatement* node, void* data) = 0;

  virtual void visitASTImportStatement(const ASTImportStatement* node, void* data) = 0;

  virtual void visitASTModuleStatement(const ASTModuleStatement* node, void* data) = 0;

  virtual void visitASTWithConnectionClause(const ASTWithConnectionClause* node, void* data) = 0;

  virtual void visitASTIntoAlias(const ASTIntoAlias* node, void* data) = 0;

  virtual void visitASTUnnestExpressionWithOptAliasAndOffset(const ASTUnnestExpressionWithOptAliasAndOffset* node, void* data) = 0;

  virtual void visitASTPivotExpression(const ASTPivotExpression* node, void* data) = 0;

  virtual void visitASTPivotValue(const ASTPivotValue* node, void* data) = 0;

  virtual void visitASTPivotExpressionList(const ASTPivotExpressionList* node, void* data) = 0;

  virtual void visitASTPivotValueList(const ASTPivotValueList* node, void* data) = 0;

  virtual void visitASTPivotClause(const ASTPivotClause* node, void* data) = 0;

  virtual void visitASTUnpivotInItem(const ASTUnpivotInItem* node, void* data) = 0;

  virtual void visitASTUnpivotInItemList(const ASTUnpivotInItemList* node, void* data) = 0;

  virtual void visitASTUnpivotClause(const ASTUnpivotClause* node, void* data) = 0;

  virtual void visitASTUsingClause(const ASTUsingClause* node, void* data) = 0;

  virtual void visitASTForSystemTime(const ASTForSystemTime* node, void* data) = 0;

  virtual void visitASTQualify(const ASTQualify* node, void* data) = 0;

  virtual void visitASTClampedBetweenModifier(const ASTClampedBetweenModifier* node, void* data) = 0;

  virtual void visitASTFormatClause(const ASTFormatClause* node, void* data) = 0;

  virtual void visitASTPathExpressionList(const ASTPathExpressionList* node, void* data) = 0;

  virtual void visitASTParameterExpr(const ASTParameterExpr* node, void* data) = 0;

  virtual void visitASTSystemVariableExpr(const ASTSystemVariableExpr* node, void* data) = 0;

  virtual void visitASTWithGroupRows(const ASTWithGroupRows* node, void* data) = 0;

  virtual void visitASTLambda(const ASTLambda* node, void* data) = 0;

  virtual void visitASTAnalyticFunctionCall(const ASTAnalyticFunctionCall* node, void* data) = 0;

  virtual void visitASTFunctionCallWithGroupRows(const ASTFunctionCallWithGroupRows* node, void* data) = 0;

  virtual void visitASTClusterBy(const ASTClusterBy* node, void* data) = 0;

  virtual void visitASTNewConstructorArg(const ASTNewConstructorArg* node, void* data) = 0;

  virtual void visitASTNewConstructor(const ASTNewConstructor* node, void* data) = 0;

  virtual void visitASTOptionsList(const ASTOptionsList* node, void* data) = 0;

  virtual void visitASTOptionsEntry(const ASTOptionsEntry* node, void* data) = 0;

  virtual void visitASTFunctionParameter(const ASTFunctionParameter* node, void* data) = 0;

  virtual void visitASTFunctionParameters(const ASTFunctionParameters* node, void* data) = 0;

  virtual void visitASTFunctionDeclaration(const ASTFunctionDeclaration* node, void* data) = 0;

  virtual void visitASTSqlFunctionBody(const ASTSqlFunctionBody* node, void* data) = 0;

  virtual void visitASTTVFArgument(const ASTTVFArgument* node, void* data) = 0;

  virtual void visitASTTVF(const ASTTVF* node, void* data) = 0;

  virtual void visitASTTableClause(const ASTTableClause* node, void* data) = 0;

  virtual void visitASTModelClause(const ASTModelClause* node, void* data) = 0;

  virtual void visitASTConnectionClause(const ASTConnectionClause* node, void* data) = 0;

  virtual void visitASTCloneDataSource(const ASTCloneDataSource* node, void* data) = 0;

  virtual void visitASTCopyDataSource(const ASTCopyDataSource* node, void* data) = 0;

  virtual void visitASTCloneDataSourceList(const ASTCloneDataSourceList* node, void* data) = 0;

  virtual void visitASTCloneDataStatement(const ASTCloneDataStatement* node, void* data) = 0;

  virtual void visitASTCreateConstantStatement(const ASTCreateConstantStatement* node, void* data) = 0;

  virtual void visitASTCreateDatabaseStatement(const ASTCreateDatabaseStatement* node, void* data) = 0;

  virtual void visitASTCreateProcedureStatement(const ASTCreateProcedureStatement* node, void* data) = 0;

  virtual void visitASTCreateSchemaStatement(const ASTCreateSchemaStatement* node, void* data) = 0;

  virtual void visitASTTransformClause(const ASTTransformClause* node, void* data) = 0;

  virtual void visitASTCreateModelStatement(const ASTCreateModelStatement* node, void* data) = 0;

  virtual void visitASTIndexAllColumns(const ASTIndexAllColumns* node, void* data) = 0;

  virtual void visitASTIndexItemList(const ASTIndexItemList* node, void* data) = 0;

  virtual void visitASTIndexStoringExpressionList(const ASTIndexStoringExpressionList* node, void* data) = 0;

  virtual void visitASTIndexUnnestExpressionList(const ASTIndexUnnestExpressionList* node, void* data) = 0;

  virtual void visitASTCreateIndexStatement(const ASTCreateIndexStatement* node, void* data) = 0;

  virtual void visitASTExportDataStatement(const ASTExportDataStatement* node, void* data) = 0;

  virtual void visitASTExportModelStatement(const ASTExportModelStatement* node, void* data) = 0;

  virtual void visitASTCallStatement(const ASTCallStatement* node, void* data) = 0;

  virtual void visitASTDefineTableStatement(const ASTDefineTableStatement* node, void* data) = 0;

  virtual void visitASTWithPartitionColumnsClause(const ASTWithPartitionColumnsClause* node, void* data) = 0;

  virtual void visitASTCreateSnapshotTableStatement(const ASTCreateSnapshotTableStatement* node, void* data) = 0;

  virtual void visitASTTypeParameterList(const ASTTypeParameterList* node, void* data) = 0;

  virtual void visitASTTVFSchema(const ASTTVFSchema* node, void* data) = 0;

  virtual void visitASTTVFSchemaColumn(const ASTTVFSchemaColumn* node, void* data) = 0;

  virtual void visitASTTableAndColumnInfo(const ASTTableAndColumnInfo* node, void* data) = 0;

  virtual void visitASTTableAndColumnInfoList(const ASTTableAndColumnInfoList* node, void* data) = 0;

  virtual void visitASTTemplatedParameterType(const ASTTemplatedParameterType* node, void* data) = 0;

  virtual void visitASTDefaultLiteral(const ASTDefaultLiteral* node, void* data) = 0;

  virtual void visitASTAnalyzeStatement(const ASTAnalyzeStatement* node, void* data) = 0;

  virtual void visitASTAssertStatement(const ASTAssertStatement* node, void* data) = 0;

  virtual void visitASTAssertRowsModified(const ASTAssertRowsModified* node, void* data) = 0;

  virtual void visitASTReturningClause(const ASTReturningClause* node, void* data) = 0;

  virtual void visitASTDeleteStatement(const ASTDeleteStatement* node, void* data) = 0;

  virtual void visitASTNotNullColumnAttribute(const ASTNotNullColumnAttribute* node, void* data) = 0;

  virtual void visitASTHiddenColumnAttribute(const ASTHiddenColumnAttribute* node, void* data) = 0;

  virtual void visitASTPrimaryKeyColumnAttribute(const ASTPrimaryKeyColumnAttribute* node, void* data) = 0;

  virtual void visitASTForeignKeyColumnAttribute(const ASTForeignKeyColumnAttribute* node, void* data) = 0;

  virtual void visitASTColumnAttributeList(const ASTColumnAttributeList* node, void* data) = 0;

  virtual void visitASTStructColumnField(const ASTStructColumnField* node, void* data) = 0;

  virtual void visitASTGeneratedColumnInfo(const ASTGeneratedColumnInfo* node, void* data) = 0;

  virtual void visitASTColumnDefinition(const ASTColumnDefinition* node, void* data) = 0;

  virtual void visitASTTableElementList(const ASTTableElementList* node, void* data) = 0;

  virtual void visitASTColumnList(const ASTColumnList* node, void* data) = 0;

  virtual void visitASTColumnPosition(const ASTColumnPosition* node, void* data) = 0;

  virtual void visitASTInsertValuesRow(const ASTInsertValuesRow* node, void* data) = 0;

  virtual void visitASTInsertValuesRowList(const ASTInsertValuesRowList* node, void* data) = 0;

  virtual void visitASTInsertStatement(const ASTInsertStatement* node, void* data) = 0;

  virtual void visitASTUpdateSetValue(const ASTUpdateSetValue* node, void* data) = 0;

  virtual void visitASTUpdateItem(const ASTUpdateItem* node, void* data) = 0;

  virtual void visitASTUpdateItemList(const ASTUpdateItemList* node, void* data) = 0;

  virtual void visitASTUpdateStatement(const ASTUpdateStatement* node, void* data) = 0;

  virtual void visitASTTruncateStatement(const ASTTruncateStatement* node, void* data) = 0;

  virtual void visitASTMergeAction(const ASTMergeAction* node, void* data) = 0;

  virtual void visitASTMergeWhenClause(const ASTMergeWhenClause* node, void* data) = 0;

  virtual void visitASTMergeWhenClauseList(const ASTMergeWhenClauseList* node, void* data) = 0;

  virtual void visitASTMergeStatement(const ASTMergeStatement* node, void* data) = 0;

  virtual void visitASTPrivilege(const ASTPrivilege* node, void* data) = 0;

  virtual void visitASTPrivileges(const ASTPrivileges* node, void* data) = 0;

  virtual void visitASTGranteeList(const ASTGranteeList* node, void* data) = 0;

  virtual void visitASTGrantStatement(const ASTGrantStatement* node, void* data) = 0;

  virtual void visitASTRevokeStatement(const ASTRevokeStatement* node, void* data) = 0;

  virtual void visitASTRepeatableClause(const ASTRepeatableClause* node, void* data) = 0;

  virtual void visitASTFilterFieldsArg(const ASTFilterFieldsArg* node, void* data) = 0;

  virtual void visitASTReplaceFieldsArg(const ASTReplaceFieldsArg* node, void* data) = 0;

  virtual void visitASTReplaceFieldsExpression(const ASTReplaceFieldsExpression* node, void* data) = 0;

  virtual void visitASTSampleSize(const ASTSampleSize* node, void* data) = 0;

  virtual void visitASTWithWeight(const ASTWithWeight* node, void* data) = 0;

  virtual void visitASTSampleSuffix(const ASTSampleSuffix* node, void* data) = 0;

  virtual void visitASTSampleClause(const ASTSampleClause* node, void* data) = 0;

  virtual void visitASTSetOptionsAction(const ASTSetOptionsAction* node, void* data) = 0;

  virtual void visitASTSetAsAction(const ASTSetAsAction* node, void* data) = 0;

  virtual void visitASTAddConstraintAction(const ASTAddConstraintAction* node, void* data) = 0;

  virtual void visitASTDropPrimaryKeyAction(const ASTDropPrimaryKeyAction* node, void* data) = 0;

  virtual void visitASTDropConstraintAction(const ASTDropConstraintAction* node, void* data) = 0;

  virtual void visitASTAlterConstraintEnforcementAction(const ASTAlterConstraintEnforcementAction* node, void* data) = 0;

  virtual void visitASTAlterConstraintSetOptionsAction(const ASTAlterConstraintSetOptionsAction* node, void* data) = 0;

  virtual void visitASTAddColumnAction(const ASTAddColumnAction* node, void* data) = 0;

  virtual void visitASTDropColumnAction(const ASTDropColumnAction* node, void* data) = 0;

  virtual void visitASTRenameColumnAction(const ASTRenameColumnAction* node, void* data) = 0;

  virtual void visitASTAlterColumnTypeAction(const ASTAlterColumnTypeAction* node, void* data) = 0;

  virtual void visitASTAlterColumnOptionsAction(const ASTAlterColumnOptionsAction* node, void* data) = 0;

  virtual void visitASTAlterColumnSetDefaultAction(const ASTAlterColumnSetDefaultAction* node, void* data) = 0;

  virtual void visitASTAlterColumnDropDefaultAction(const ASTAlterColumnDropDefaultAction* node, void* data) = 0;

  virtual void visitASTAlterColumnDropNotNullAction(const ASTAlterColumnDropNotNullAction* node, void* data) = 0;

  virtual void visitASTGrantToClause(const ASTGrantToClause* node, void* data) = 0;

  virtual void visitASTRestrictToClause(const ASTRestrictToClause* node, void* data) = 0;

  virtual void visitASTAddToRestricteeListClause(const ASTAddToRestricteeListClause* node, void* data) = 0;

  virtual void visitASTRemoveFromRestricteeListClause(const ASTRemoveFromRestricteeListClause* node, void* data) = 0;

  virtual void visitASTFilterUsingClause(const ASTFilterUsingClause* node, void* data) = 0;

  virtual void visitASTRevokeFromClause(const ASTRevokeFromClause* node, void* data) = 0;

  virtual void visitASTRenameToClause(const ASTRenameToClause* node, void* data) = 0;

  virtual void visitASTSetCollateClause(const ASTSetCollateClause* node, void* data) = 0;

  virtual void visitASTAlterActionList(const ASTAlterActionList* node, void* data) = 0;

  virtual void visitASTAlterAllRowAccessPoliciesStatement(const ASTAlterAllRowAccessPoliciesStatement* node, void* data) = 0;

  virtual void visitASTForeignKeyActions(const ASTForeignKeyActions* node, void* data) = 0;

  virtual void visitASTForeignKeyReference(const ASTForeignKeyReference* node, void* data) = 0;

  virtual void visitASTScript(const ASTScript* node, void* data) = 0;

  virtual void visitASTElseifClause(const ASTElseifClause* node, void* data) = 0;

  virtual void visitASTElseifClauseList(const ASTElseifClauseList* node, void* data) = 0;

  virtual void visitASTIfStatement(const ASTIfStatement* node, void* data) = 0;

  virtual void visitASTWhenThenClause(const ASTWhenThenClause* node, void* data) = 0;

  virtual void visitASTWhenThenClauseList(const ASTWhenThenClauseList* node, void* data) = 0;

  virtual void visitASTCaseStatement(const ASTCaseStatement* node, void* data) = 0;

  virtual void visitASTHint(const ASTHint* node, void* data) = 0;

  virtual void visitASTHintEntry(const ASTHintEntry* node, void* data) = 0;

  virtual void visitASTUnpivotInItemLabel(const ASTUnpivotInItemLabel* node, void* data) = 0;

  virtual void visitASTDescriptor(const ASTDescriptor* node, void* data) = 0;

  virtual void visitASTSimpleColumnSchema(const ASTSimpleColumnSchema* node, void* data) = 0;

  virtual void visitASTArrayColumnSchema(const ASTArrayColumnSchema* node, void* data) = 0;

  virtual void visitASTPrimaryKey(const ASTPrimaryKey* node, void* data) = 0;

  virtual void visitASTForeignKey(const ASTForeignKey* node, void* data) = 0;

  virtual void visitASTCheckConstraint(const ASTCheckConstraint* node, void* data) = 0;

  virtual void visitASTDescriptorColumn(const ASTDescriptorColumn* node, void* data) = 0;

  virtual void visitASTDescriptorColumnList(const ASTDescriptorColumnList* node, void* data) = 0;

  virtual void visitASTCreateEntityStatement(const ASTCreateEntityStatement* node, void* data) = 0;

  virtual void visitASTRaiseStatement(const ASTRaiseStatement* node, void* data) = 0;

  virtual void visitASTExceptionHandler(const ASTExceptionHandler* node, void* data) = 0;

  virtual void visitASTExceptionHandlerList(const ASTExceptionHandlerList* node, void* data) = 0;

  virtual void visitASTBeginEndBlock(const ASTBeginEndBlock* node, void* data) = 0;

  virtual void visitASTIdentifierList(const ASTIdentifierList* node, void* data) = 0;

  virtual void visitASTVariableDeclaration(const ASTVariableDeclaration* node, void* data) = 0;

  virtual void visitASTUntilClause(const ASTUntilClause* node, void* data) = 0;

  virtual void visitASTBreakStatement(const ASTBreakStatement* node, void* data) = 0;

  virtual void visitASTContinueStatement(const ASTContinueStatement* node, void* data) = 0;

  virtual void visitASTDropPrivilegeRestrictionStatement(const ASTDropPrivilegeRestrictionStatement* node, void* data) = 0;

  virtual void visitASTDropRowAccessPolicyStatement(const ASTDropRowAccessPolicyStatement* node, void* data) = 0;

  virtual void visitASTCreatePrivilegeRestrictionStatement(const ASTCreatePrivilegeRestrictionStatement* node, void* data) = 0;

  virtual void visitASTCreateRowAccessPolicyStatement(const ASTCreateRowAccessPolicyStatement* node, void* data) = 0;

  virtual void visitASTDropStatement(const ASTDropStatement* node, void* data) = 0;

  virtual void visitASTReturnStatement(const ASTReturnStatement* node, void* data) = 0;

  virtual void visitASTSingleAssignment(const ASTSingleAssignment* node, void* data) = 0;

  virtual void visitASTParameterAssignment(const ASTParameterAssignment* node, void* data) = 0;

  virtual void visitASTSystemVariableAssignment(const ASTSystemVariableAssignment* node, void* data) = 0;

  virtual void visitASTAssignmentFromStruct(const ASTAssignmentFromStruct* node, void* data) = 0;

  virtual void visitASTCreateTableStatement(const ASTCreateTableStatement* node, void* data) = 0;

  virtual void visitASTCreateExternalTableStatement(const ASTCreateExternalTableStatement* node, void* data) = 0;

  virtual void visitASTCreateViewStatement(const ASTCreateViewStatement* node, void* data) = 0;

  virtual void visitASTCreateMaterializedViewStatement(const ASTCreateMaterializedViewStatement* node, void* data) = 0;

  virtual void visitASTWhileStatement(const ASTWhileStatement* node, void* data) = 0;

  virtual void visitASTRepeatStatement(const ASTRepeatStatement* node, void* data) = 0;

  virtual void visitASTForInStatement(const ASTForInStatement* node, void* data) = 0;

  virtual void visitASTAlterDatabaseStatement(const ASTAlterDatabaseStatement* node, void* data) = 0;

  virtual void visitASTAlterSchemaStatement(const ASTAlterSchemaStatement* node, void* data) = 0;

  virtual void visitASTAlterTableStatement(const ASTAlterTableStatement* node, void* data) = 0;

  virtual void visitASTAlterViewStatement(const ASTAlterViewStatement* node, void* data) = 0;

  virtual void visitASTAlterMaterializedViewStatement(const ASTAlterMaterializedViewStatement* node, void* data) = 0;

  virtual void visitASTAlterPrivilegeRestrictionStatement(const ASTAlterPrivilegeRestrictionStatement* node, void* data) = 0;

  virtual void visitASTAlterRowAccessPolicyStatement(const ASTAlterRowAccessPolicyStatement* node, void* data) = 0;

  virtual void visitASTAlterEntityStatement(const ASTAlterEntityStatement* node, void* data) = 0;

  virtual void visitASTCreateFunctionStatement(const ASTCreateFunctionStatement* node, void* data) = 0;

  virtual void visitASTCreateTableFunctionStatement(const ASTCreateTableFunctionStatement* node, void* data) = 0;

  virtual void visitASTStructColumnSchema(const ASTStructColumnSchema* node, void* data) = 0;

  virtual void visitASTInferredTypeColumnSchema(const ASTInferredTypeColumnSchema* node, void* data) = 0;

  virtual void visitASTExecuteIntoClause(const ASTExecuteIntoClause* node, void* data) = 0;

  virtual void visitASTExecuteUsingArgument(const ASTExecuteUsingArgument* node, void* data) = 0;

  virtual void visitASTExecuteUsingClause(const ASTExecuteUsingClause* node, void* data) = 0;

  virtual void visitASTExecuteImmediateStatement(const ASTExecuteImmediateStatement* node, void* data) = 0;

  virtual void visitASTAuxLoadDataFromFilesOptionsList(const ASTAuxLoadDataFromFilesOptionsList* node, void* data) = 0;

  virtual void visitASTAuxLoadDataStatement(const ASTAuxLoadDataStatement* node, void* data) = 0;

  virtual void visitASTLabel(const ASTLabel* node, void* data) = 0;

};

class DefaultParseTreeVisitor : public ParseTreeVisitor {
 public:
  virtual void defaultVisit(const ASTNode* node, void* data) = 0;
  void visit(const ASTNode* node, void* data) override {
    defaultVisit(node, data);
  }
  void visitASTQueryStatement(const ASTQueryStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTQuery(const ASTQuery* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSelect(const ASTSelect* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSelectList(const ASTSelectList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSelectColumn(const ASTSelectColumn* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIntLiteral(const ASTIntLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIdentifier(const ASTIdentifier* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlias(const ASTAlias* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPathExpression(const ASTPathExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTablePathExpression(const ASTTablePathExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFromClause(const ASTFromClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWhereClause(const ASTWhereClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBooleanLiteral(const ASTBooleanLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAndExpr(const ASTAndExpr* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBinaryExpression(const ASTBinaryExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStringLiteral(const ASTStringLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStar(const ASTStar* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTOrExpr(const ASTOrExpr* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGroupingItem(const ASTGroupingItem* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGroupBy(const ASTGroupBy* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTOrderingExpression(const ASTOrderingExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTOrderBy(const ASTOrderBy* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTLimitOffset(const ASTLimitOffset* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFloatLiteral(const ASTFloatLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTNullLiteral(const ASTNullLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTOnClause(const ASTOnClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithClauseEntry(const ASTWithClauseEntry* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTJoin(const ASTJoin* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithClause(const ASTWithClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTHaving(const ASTHaving* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSimpleType(const ASTSimpleType* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTArrayType(const ASTArrayType* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStructField(const ASTStructField* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStructType(const ASTStructType* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCastExpression(const ASTCastExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSelectAs(const ASTSelectAs* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRollup(const ASTRollup* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFunctionCall(const ASTFunctionCall* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTArrayConstructor(const ASTArrayConstructor* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStructConstructorArg(const ASTStructConstructorArg* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStructConstructorWithParens(const ASTStructConstructorWithParens* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStructConstructorWithKeyword(const ASTStructConstructorWithKeyword* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTInExpression(const ASTInExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTInList(const ASTInList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBetweenExpression(const ASTBetweenExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTNumericLiteral(const ASTNumericLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBigNumericLiteral(const ASTBigNumericLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBytesLiteral(const ASTBytesLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDateOrTimeLiteral(const ASTDateOrTimeLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTMaxLiteral(const ASTMaxLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTJSONLiteral(const ASTJSONLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCaseValueExpression(const ASTCaseValueExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCaseNoValueExpression(const ASTCaseNoValueExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTArrayElement(const ASTArrayElement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBitwiseShiftExpression(const ASTBitwiseShiftExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCollate(const ASTCollate* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDotGeneralizedField(const ASTDotGeneralizedField* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDotIdentifier(const ASTDotIdentifier* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDotStar(const ASTDotStar* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDotStarWithModifiers(const ASTDotStarWithModifiers* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExpressionSubquery(const ASTExpressionSubquery* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExtractExpression(const ASTExtractExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTHavingModifier(const ASTHavingModifier* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIntervalExpr(const ASTIntervalExpr* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTNamedArgument(const ASTNamedArgument* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTNullOrder(const ASTNullOrder* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTOnOrUsingClauseList(const ASTOnOrUsingClauseList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTParenthesizedJoin(const ASTParenthesizedJoin* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPartitionBy(const ASTPartitionBy* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetOperation(const ASTSetOperation* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStarExceptList(const ASTStarExceptList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStarModifiers(const ASTStarModifiers* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStarReplaceItem(const ASTStarReplaceItem* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStarWithModifiers(const ASTStarWithModifiers* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTableSubquery(const ASTTableSubquery* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUnaryExpression(const ASTUnaryExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUnnestExpression(const ASTUnnestExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWindowClause(const ASTWindowClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWindowDefinition(const ASTWindowDefinition* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWindowFrame(const ASTWindowFrame* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWindowFrameExpr(const ASTWindowFrameExpr* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTLikeExpression(const ASTLikeExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWindowSpecification(const ASTWindowSpecification* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithOffset(const ASTWithOffset* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAnySomeAllOp(const ASTAnySomeAllOp* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStatementList(const ASTStatementList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTHintedStatement(const ASTHintedStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExplainStatement(const ASTExplainStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDescribeStatement(const ASTDescribeStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTShowStatement(const ASTShowStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTransactionIsolationLevel(const ASTTransactionIsolationLevel* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTransactionReadWriteMode(const ASTTransactionReadWriteMode* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTransactionModeList(const ASTTransactionModeList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBeginStatement(const ASTBeginStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetTransactionStatement(const ASTSetTransactionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCommitStatement(const ASTCommitStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRollbackStatement(const ASTRollbackStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStartBatchStatement(const ASTStartBatchStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRunBatchStatement(const ASTRunBatchStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAbortBatchStatement(const ASTAbortBatchStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropEntityStatement(const ASTDropEntityStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropFunctionStatement(const ASTDropFunctionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropTableFunctionStatement(const ASTDropTableFunctionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropAllRowAccessPoliciesStatement(const ASTDropAllRowAccessPoliciesStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropMaterializedViewStatement(const ASTDropMaterializedViewStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropSnapshotTableStatement(const ASTDropSnapshotTableStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropSearchIndexStatement(const ASTDropSearchIndexStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRenameStatement(const ASTRenameStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTImportStatement(const ASTImportStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTModuleStatement(const ASTModuleStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithConnectionClause(const ASTWithConnectionClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIntoAlias(const ASTIntoAlias* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUnnestExpressionWithOptAliasAndOffset(const ASTUnnestExpressionWithOptAliasAndOffset* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPivotExpression(const ASTPivotExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPivotValue(const ASTPivotValue* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPivotExpressionList(const ASTPivotExpressionList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPivotValueList(const ASTPivotValueList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPivotClause(const ASTPivotClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUnpivotInItem(const ASTUnpivotInItem* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUnpivotInItemList(const ASTUnpivotInItemList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUnpivotClause(const ASTUnpivotClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUsingClause(const ASTUsingClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTForSystemTime(const ASTForSystemTime* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTQualify(const ASTQualify* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTClampedBetweenModifier(const ASTClampedBetweenModifier* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFormatClause(const ASTFormatClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPathExpressionList(const ASTPathExpressionList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTParameterExpr(const ASTParameterExpr* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSystemVariableExpr(const ASTSystemVariableExpr* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithGroupRows(const ASTWithGroupRows* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTLambda(const ASTLambda* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAnalyticFunctionCall(const ASTAnalyticFunctionCall* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFunctionCallWithGroupRows(const ASTFunctionCallWithGroupRows* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTClusterBy(const ASTClusterBy* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTNewConstructorArg(const ASTNewConstructorArg* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTNewConstructor(const ASTNewConstructor* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTOptionsList(const ASTOptionsList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTOptionsEntry(const ASTOptionsEntry* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFunctionParameter(const ASTFunctionParameter* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFunctionParameters(const ASTFunctionParameters* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFunctionDeclaration(const ASTFunctionDeclaration* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSqlFunctionBody(const ASTSqlFunctionBody* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTVFArgument(const ASTTVFArgument* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTVF(const ASTTVF* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTableClause(const ASTTableClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTModelClause(const ASTModelClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTConnectionClause(const ASTConnectionClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCloneDataSource(const ASTCloneDataSource* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCopyDataSource(const ASTCopyDataSource* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCloneDataSourceList(const ASTCloneDataSourceList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCloneDataStatement(const ASTCloneDataStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateConstantStatement(const ASTCreateConstantStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateDatabaseStatement(const ASTCreateDatabaseStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateProcedureStatement(const ASTCreateProcedureStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateSchemaStatement(const ASTCreateSchemaStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTransformClause(const ASTTransformClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateModelStatement(const ASTCreateModelStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIndexAllColumns(const ASTIndexAllColumns* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIndexItemList(const ASTIndexItemList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIndexStoringExpressionList(const ASTIndexStoringExpressionList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIndexUnnestExpressionList(const ASTIndexUnnestExpressionList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateIndexStatement(const ASTCreateIndexStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExportDataStatement(const ASTExportDataStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExportModelStatement(const ASTExportModelStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCallStatement(const ASTCallStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDefineTableStatement(const ASTDefineTableStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithPartitionColumnsClause(const ASTWithPartitionColumnsClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateSnapshotTableStatement(const ASTCreateSnapshotTableStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTypeParameterList(const ASTTypeParameterList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTVFSchema(const ASTTVFSchema* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTVFSchemaColumn(const ASTTVFSchemaColumn* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTableAndColumnInfo(const ASTTableAndColumnInfo* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTableAndColumnInfoList(const ASTTableAndColumnInfoList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTemplatedParameterType(const ASTTemplatedParameterType* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDefaultLiteral(const ASTDefaultLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAnalyzeStatement(const ASTAnalyzeStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAssertStatement(const ASTAssertStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAssertRowsModified(const ASTAssertRowsModified* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTReturningClause(const ASTReturningClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDeleteStatement(const ASTDeleteStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTNotNullColumnAttribute(const ASTNotNullColumnAttribute* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTHiddenColumnAttribute(const ASTHiddenColumnAttribute* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPrimaryKeyColumnAttribute(const ASTPrimaryKeyColumnAttribute* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTForeignKeyColumnAttribute(const ASTForeignKeyColumnAttribute* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTColumnAttributeList(const ASTColumnAttributeList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStructColumnField(const ASTStructColumnField* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGeneratedColumnInfo(const ASTGeneratedColumnInfo* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTColumnDefinition(const ASTColumnDefinition* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTableElementList(const ASTTableElementList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTColumnList(const ASTColumnList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTColumnPosition(const ASTColumnPosition* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTInsertValuesRow(const ASTInsertValuesRow* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTInsertValuesRowList(const ASTInsertValuesRowList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTInsertStatement(const ASTInsertStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUpdateSetValue(const ASTUpdateSetValue* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUpdateItem(const ASTUpdateItem* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUpdateItemList(const ASTUpdateItemList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUpdateStatement(const ASTUpdateStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTruncateStatement(const ASTTruncateStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTMergeAction(const ASTMergeAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTMergeWhenClause(const ASTMergeWhenClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTMergeWhenClauseList(const ASTMergeWhenClauseList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTMergeStatement(const ASTMergeStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPrivilege(const ASTPrivilege* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPrivileges(const ASTPrivileges* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGranteeList(const ASTGranteeList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGrantStatement(const ASTGrantStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRevokeStatement(const ASTRevokeStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRepeatableClause(const ASTRepeatableClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFilterFieldsArg(const ASTFilterFieldsArg* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTReplaceFieldsArg(const ASTReplaceFieldsArg* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTReplaceFieldsExpression(const ASTReplaceFieldsExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSampleSize(const ASTSampleSize* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithWeight(const ASTWithWeight* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSampleSuffix(const ASTSampleSuffix* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSampleClause(const ASTSampleClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetOptionsAction(const ASTSetOptionsAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetAsAction(const ASTSetAsAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAddConstraintAction(const ASTAddConstraintAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropPrimaryKeyAction(const ASTDropPrimaryKeyAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropConstraintAction(const ASTDropConstraintAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterConstraintEnforcementAction(const ASTAlterConstraintEnforcementAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterConstraintSetOptionsAction(const ASTAlterConstraintSetOptionsAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAddColumnAction(const ASTAddColumnAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropColumnAction(const ASTDropColumnAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRenameColumnAction(const ASTRenameColumnAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterColumnTypeAction(const ASTAlterColumnTypeAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterColumnOptionsAction(const ASTAlterColumnOptionsAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterColumnSetDefaultAction(const ASTAlterColumnSetDefaultAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterColumnDropDefaultAction(const ASTAlterColumnDropDefaultAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterColumnDropNotNullAction(const ASTAlterColumnDropNotNullAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGrantToClause(const ASTGrantToClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRestrictToClause(const ASTRestrictToClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAddToRestricteeListClause(const ASTAddToRestricteeListClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRemoveFromRestricteeListClause(const ASTRemoveFromRestricteeListClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFilterUsingClause(const ASTFilterUsingClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRevokeFromClause(const ASTRevokeFromClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRenameToClause(const ASTRenameToClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetCollateClause(const ASTSetCollateClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterActionList(const ASTAlterActionList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterAllRowAccessPoliciesStatement(const ASTAlterAllRowAccessPoliciesStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTForeignKeyActions(const ASTForeignKeyActions* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTForeignKeyReference(const ASTForeignKeyReference* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTScript(const ASTScript* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTElseifClause(const ASTElseifClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTElseifClauseList(const ASTElseifClauseList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIfStatement(const ASTIfStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWhenThenClause(const ASTWhenThenClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWhenThenClauseList(const ASTWhenThenClauseList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCaseStatement(const ASTCaseStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTHint(const ASTHint* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTHintEntry(const ASTHintEntry* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUnpivotInItemLabel(const ASTUnpivotInItemLabel* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDescriptor(const ASTDescriptor* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSimpleColumnSchema(const ASTSimpleColumnSchema* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTArrayColumnSchema(const ASTArrayColumnSchema* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPrimaryKey(const ASTPrimaryKey* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTForeignKey(const ASTForeignKey* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCheckConstraint(const ASTCheckConstraint* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDescriptorColumn(const ASTDescriptorColumn* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDescriptorColumnList(const ASTDescriptorColumnList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateEntityStatement(const ASTCreateEntityStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRaiseStatement(const ASTRaiseStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExceptionHandler(const ASTExceptionHandler* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExceptionHandlerList(const ASTExceptionHandlerList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBeginEndBlock(const ASTBeginEndBlock* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIdentifierList(const ASTIdentifierList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTVariableDeclaration(const ASTVariableDeclaration* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUntilClause(const ASTUntilClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBreakStatement(const ASTBreakStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTContinueStatement(const ASTContinueStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropPrivilegeRestrictionStatement(const ASTDropPrivilegeRestrictionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropRowAccessPolicyStatement(const ASTDropRowAccessPolicyStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreatePrivilegeRestrictionStatement(const ASTCreatePrivilegeRestrictionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateRowAccessPolicyStatement(const ASTCreateRowAccessPolicyStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropStatement(const ASTDropStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTReturnStatement(const ASTReturnStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSingleAssignment(const ASTSingleAssignment* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTParameterAssignment(const ASTParameterAssignment* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSystemVariableAssignment(const ASTSystemVariableAssignment* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAssignmentFromStruct(const ASTAssignmentFromStruct* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateTableStatement(const ASTCreateTableStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateExternalTableStatement(const ASTCreateExternalTableStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateViewStatement(const ASTCreateViewStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateMaterializedViewStatement(const ASTCreateMaterializedViewStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWhileStatement(const ASTWhileStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRepeatStatement(const ASTRepeatStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTForInStatement(const ASTForInStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterDatabaseStatement(const ASTAlterDatabaseStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterSchemaStatement(const ASTAlterSchemaStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterTableStatement(const ASTAlterTableStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterViewStatement(const ASTAlterViewStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterMaterializedViewStatement(const ASTAlterMaterializedViewStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterPrivilegeRestrictionStatement(const ASTAlterPrivilegeRestrictionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterRowAccessPolicyStatement(const ASTAlterRowAccessPolicyStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterEntityStatement(const ASTAlterEntityStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateFunctionStatement(const ASTCreateFunctionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateTableFunctionStatement(const ASTCreateTableFunctionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStructColumnSchema(const ASTStructColumnSchema* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTInferredTypeColumnSchema(const ASTInferredTypeColumnSchema* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExecuteIntoClause(const ASTExecuteIntoClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExecuteUsingArgument(const ASTExecuteUsingArgument* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExecuteUsingClause(const ASTExecuteUsingClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExecuteImmediateStatement(const ASTExecuteImmediateStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAuxLoadDataFromFilesOptionsList(const ASTAuxLoadDataFromFilesOptionsList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAuxLoadDataStatement(const ASTAuxLoadDataStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTLabel(const ASTLabel* node, void* data) override {
    defaultVisit(node, data);
  }

};

class NonRecursiveParseTreeVisitor {
 public:
  virtual ~NonRecursiveParseTreeVisitor() {}
  virtual absl::StatusOr<VisitResult> defaultVisit(const ASTNode* node) = 0;
  absl::StatusOr<VisitResult> visit(const ASTNode* node) {
    return defaultVisit(node);
  }
  virtual absl::StatusOr<VisitResult> visitASTQueryStatement(const ASTQueryStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTQuery(const ASTQuery* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSelect(const ASTSelect* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSelectList(const ASTSelectList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSelectColumn(const ASTSelectColumn* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIntLiteral(const ASTIntLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIdentifier(const ASTIdentifier* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlias(const ASTAlias* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPathExpression(const ASTPathExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTablePathExpression(const ASTTablePathExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFromClause(const ASTFromClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWhereClause(const ASTWhereClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBooleanLiteral(const ASTBooleanLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAndExpr(const ASTAndExpr* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBinaryExpression(const ASTBinaryExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStringLiteral(const ASTStringLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStar(const ASTStar* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTOrExpr(const ASTOrExpr* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGroupingItem(const ASTGroupingItem* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGroupBy(const ASTGroupBy* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTOrderingExpression(const ASTOrderingExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTOrderBy(const ASTOrderBy* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTLimitOffset(const ASTLimitOffset* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFloatLiteral(const ASTFloatLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTNullLiteral(const ASTNullLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTOnClause(const ASTOnClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithClauseEntry(const ASTWithClauseEntry* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTJoin(const ASTJoin* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithClause(const ASTWithClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTHaving(const ASTHaving* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSimpleType(const ASTSimpleType* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTArrayType(const ASTArrayType* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStructField(const ASTStructField* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStructType(const ASTStructType* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCastExpression(const ASTCastExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSelectAs(const ASTSelectAs* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRollup(const ASTRollup* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFunctionCall(const ASTFunctionCall* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTArrayConstructor(const ASTArrayConstructor* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStructConstructorArg(const ASTStructConstructorArg* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStructConstructorWithParens(const ASTStructConstructorWithParens* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStructConstructorWithKeyword(const ASTStructConstructorWithKeyword* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTInExpression(const ASTInExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTInList(const ASTInList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBetweenExpression(const ASTBetweenExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTNumericLiteral(const ASTNumericLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBigNumericLiteral(const ASTBigNumericLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBytesLiteral(const ASTBytesLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDateOrTimeLiteral(const ASTDateOrTimeLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTMaxLiteral(const ASTMaxLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTJSONLiteral(const ASTJSONLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCaseValueExpression(const ASTCaseValueExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCaseNoValueExpression(const ASTCaseNoValueExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTArrayElement(const ASTArrayElement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBitwiseShiftExpression(const ASTBitwiseShiftExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCollate(const ASTCollate* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDotGeneralizedField(const ASTDotGeneralizedField* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDotIdentifier(const ASTDotIdentifier* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDotStar(const ASTDotStar* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDotStarWithModifiers(const ASTDotStarWithModifiers* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExpressionSubquery(const ASTExpressionSubquery* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExtractExpression(const ASTExtractExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTHavingModifier(const ASTHavingModifier* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIntervalExpr(const ASTIntervalExpr* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTNamedArgument(const ASTNamedArgument* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTNullOrder(const ASTNullOrder* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTOnOrUsingClauseList(const ASTOnOrUsingClauseList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTParenthesizedJoin(const ASTParenthesizedJoin* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPartitionBy(const ASTPartitionBy* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetOperation(const ASTSetOperation* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStarExceptList(const ASTStarExceptList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStarModifiers(const ASTStarModifiers* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStarReplaceItem(const ASTStarReplaceItem* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStarWithModifiers(const ASTStarWithModifiers* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTableSubquery(const ASTTableSubquery* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUnaryExpression(const ASTUnaryExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUnnestExpression(const ASTUnnestExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWindowClause(const ASTWindowClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWindowDefinition(const ASTWindowDefinition* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWindowFrame(const ASTWindowFrame* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWindowFrameExpr(const ASTWindowFrameExpr* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTLikeExpression(const ASTLikeExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWindowSpecification(const ASTWindowSpecification* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithOffset(const ASTWithOffset* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAnySomeAllOp(const ASTAnySomeAllOp* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStatementList(const ASTStatementList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTHintedStatement(const ASTHintedStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExplainStatement(const ASTExplainStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDescribeStatement(const ASTDescribeStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTShowStatement(const ASTShowStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTransactionIsolationLevel(const ASTTransactionIsolationLevel* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTransactionReadWriteMode(const ASTTransactionReadWriteMode* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTransactionModeList(const ASTTransactionModeList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBeginStatement(const ASTBeginStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetTransactionStatement(const ASTSetTransactionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCommitStatement(const ASTCommitStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRollbackStatement(const ASTRollbackStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStartBatchStatement(const ASTStartBatchStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRunBatchStatement(const ASTRunBatchStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAbortBatchStatement(const ASTAbortBatchStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropEntityStatement(const ASTDropEntityStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropFunctionStatement(const ASTDropFunctionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropTableFunctionStatement(const ASTDropTableFunctionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropAllRowAccessPoliciesStatement(const ASTDropAllRowAccessPoliciesStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropMaterializedViewStatement(const ASTDropMaterializedViewStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropSnapshotTableStatement(const ASTDropSnapshotTableStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropSearchIndexStatement(const ASTDropSearchIndexStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRenameStatement(const ASTRenameStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTImportStatement(const ASTImportStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTModuleStatement(const ASTModuleStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithConnectionClause(const ASTWithConnectionClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIntoAlias(const ASTIntoAlias* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUnnestExpressionWithOptAliasAndOffset(const ASTUnnestExpressionWithOptAliasAndOffset* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPivotExpression(const ASTPivotExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPivotValue(const ASTPivotValue* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPivotExpressionList(const ASTPivotExpressionList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPivotValueList(const ASTPivotValueList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPivotClause(const ASTPivotClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUnpivotInItem(const ASTUnpivotInItem* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUnpivotInItemList(const ASTUnpivotInItemList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUnpivotClause(const ASTUnpivotClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUsingClause(const ASTUsingClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTForSystemTime(const ASTForSystemTime* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTQualify(const ASTQualify* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTClampedBetweenModifier(const ASTClampedBetweenModifier* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFormatClause(const ASTFormatClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPathExpressionList(const ASTPathExpressionList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTParameterExpr(const ASTParameterExpr* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSystemVariableExpr(const ASTSystemVariableExpr* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithGroupRows(const ASTWithGroupRows* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTLambda(const ASTLambda* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAnalyticFunctionCall(const ASTAnalyticFunctionCall* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFunctionCallWithGroupRows(const ASTFunctionCallWithGroupRows* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTClusterBy(const ASTClusterBy* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTNewConstructorArg(const ASTNewConstructorArg* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTNewConstructor(const ASTNewConstructor* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTOptionsList(const ASTOptionsList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTOptionsEntry(const ASTOptionsEntry* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFunctionParameter(const ASTFunctionParameter* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFunctionParameters(const ASTFunctionParameters* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFunctionDeclaration(const ASTFunctionDeclaration* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSqlFunctionBody(const ASTSqlFunctionBody* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTVFArgument(const ASTTVFArgument* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTVF(const ASTTVF* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTableClause(const ASTTableClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTModelClause(const ASTModelClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTConnectionClause(const ASTConnectionClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCloneDataSource(const ASTCloneDataSource* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCopyDataSource(const ASTCopyDataSource* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCloneDataSourceList(const ASTCloneDataSourceList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCloneDataStatement(const ASTCloneDataStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateConstantStatement(const ASTCreateConstantStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateDatabaseStatement(const ASTCreateDatabaseStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateProcedureStatement(const ASTCreateProcedureStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateSchemaStatement(const ASTCreateSchemaStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTransformClause(const ASTTransformClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateModelStatement(const ASTCreateModelStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIndexAllColumns(const ASTIndexAllColumns* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIndexItemList(const ASTIndexItemList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIndexStoringExpressionList(const ASTIndexStoringExpressionList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIndexUnnestExpressionList(const ASTIndexUnnestExpressionList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateIndexStatement(const ASTCreateIndexStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExportDataStatement(const ASTExportDataStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExportModelStatement(const ASTExportModelStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCallStatement(const ASTCallStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDefineTableStatement(const ASTDefineTableStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithPartitionColumnsClause(const ASTWithPartitionColumnsClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateSnapshotTableStatement(const ASTCreateSnapshotTableStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTypeParameterList(const ASTTypeParameterList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTVFSchema(const ASTTVFSchema* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTVFSchemaColumn(const ASTTVFSchemaColumn* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTableAndColumnInfo(const ASTTableAndColumnInfo* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTableAndColumnInfoList(const ASTTableAndColumnInfoList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTemplatedParameterType(const ASTTemplatedParameterType* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDefaultLiteral(const ASTDefaultLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAnalyzeStatement(const ASTAnalyzeStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAssertStatement(const ASTAssertStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAssertRowsModified(const ASTAssertRowsModified* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTReturningClause(const ASTReturningClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDeleteStatement(const ASTDeleteStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTNotNullColumnAttribute(const ASTNotNullColumnAttribute* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTHiddenColumnAttribute(const ASTHiddenColumnAttribute* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPrimaryKeyColumnAttribute(const ASTPrimaryKeyColumnAttribute* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTForeignKeyColumnAttribute(const ASTForeignKeyColumnAttribute* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTColumnAttributeList(const ASTColumnAttributeList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStructColumnField(const ASTStructColumnField* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGeneratedColumnInfo(const ASTGeneratedColumnInfo* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTColumnDefinition(const ASTColumnDefinition* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTableElementList(const ASTTableElementList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTColumnList(const ASTColumnList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTColumnPosition(const ASTColumnPosition* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTInsertValuesRow(const ASTInsertValuesRow* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTInsertValuesRowList(const ASTInsertValuesRowList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTInsertStatement(const ASTInsertStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUpdateSetValue(const ASTUpdateSetValue* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUpdateItem(const ASTUpdateItem* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUpdateItemList(const ASTUpdateItemList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUpdateStatement(const ASTUpdateStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTruncateStatement(const ASTTruncateStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTMergeAction(const ASTMergeAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTMergeWhenClause(const ASTMergeWhenClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTMergeWhenClauseList(const ASTMergeWhenClauseList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTMergeStatement(const ASTMergeStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPrivilege(const ASTPrivilege* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPrivileges(const ASTPrivileges* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGranteeList(const ASTGranteeList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGrantStatement(const ASTGrantStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRevokeStatement(const ASTRevokeStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRepeatableClause(const ASTRepeatableClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFilterFieldsArg(const ASTFilterFieldsArg* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTReplaceFieldsArg(const ASTReplaceFieldsArg* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTReplaceFieldsExpression(const ASTReplaceFieldsExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSampleSize(const ASTSampleSize* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithWeight(const ASTWithWeight* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSampleSuffix(const ASTSampleSuffix* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSampleClause(const ASTSampleClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetOptionsAction(const ASTSetOptionsAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetAsAction(const ASTSetAsAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAddConstraintAction(const ASTAddConstraintAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropPrimaryKeyAction(const ASTDropPrimaryKeyAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropConstraintAction(const ASTDropConstraintAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterConstraintEnforcementAction(const ASTAlterConstraintEnforcementAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterConstraintSetOptionsAction(const ASTAlterConstraintSetOptionsAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAddColumnAction(const ASTAddColumnAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropColumnAction(const ASTDropColumnAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRenameColumnAction(const ASTRenameColumnAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterColumnTypeAction(const ASTAlterColumnTypeAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterColumnOptionsAction(const ASTAlterColumnOptionsAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterColumnSetDefaultAction(const ASTAlterColumnSetDefaultAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterColumnDropDefaultAction(const ASTAlterColumnDropDefaultAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterColumnDropNotNullAction(const ASTAlterColumnDropNotNullAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGrantToClause(const ASTGrantToClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRestrictToClause(const ASTRestrictToClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAddToRestricteeListClause(const ASTAddToRestricteeListClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRemoveFromRestricteeListClause(const ASTRemoveFromRestricteeListClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFilterUsingClause(const ASTFilterUsingClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRevokeFromClause(const ASTRevokeFromClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRenameToClause(const ASTRenameToClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetCollateClause(const ASTSetCollateClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterActionList(const ASTAlterActionList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterAllRowAccessPoliciesStatement(const ASTAlterAllRowAccessPoliciesStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTForeignKeyActions(const ASTForeignKeyActions* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTForeignKeyReference(const ASTForeignKeyReference* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTScript(const ASTScript* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTElseifClause(const ASTElseifClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTElseifClauseList(const ASTElseifClauseList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIfStatement(const ASTIfStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWhenThenClause(const ASTWhenThenClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWhenThenClauseList(const ASTWhenThenClauseList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCaseStatement(const ASTCaseStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTHint(const ASTHint* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTHintEntry(const ASTHintEntry* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUnpivotInItemLabel(const ASTUnpivotInItemLabel* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDescriptor(const ASTDescriptor* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSimpleColumnSchema(const ASTSimpleColumnSchema* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTArrayColumnSchema(const ASTArrayColumnSchema* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPrimaryKey(const ASTPrimaryKey* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTForeignKey(const ASTForeignKey* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCheckConstraint(const ASTCheckConstraint* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDescriptorColumn(const ASTDescriptorColumn* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDescriptorColumnList(const ASTDescriptorColumnList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateEntityStatement(const ASTCreateEntityStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRaiseStatement(const ASTRaiseStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExceptionHandler(const ASTExceptionHandler* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExceptionHandlerList(const ASTExceptionHandlerList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBeginEndBlock(const ASTBeginEndBlock* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIdentifierList(const ASTIdentifierList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTVariableDeclaration(const ASTVariableDeclaration* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUntilClause(const ASTUntilClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBreakStatement(const ASTBreakStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTContinueStatement(const ASTContinueStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropPrivilegeRestrictionStatement(const ASTDropPrivilegeRestrictionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropRowAccessPolicyStatement(const ASTDropRowAccessPolicyStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreatePrivilegeRestrictionStatement(const ASTCreatePrivilegeRestrictionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateRowAccessPolicyStatement(const ASTCreateRowAccessPolicyStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropStatement(const ASTDropStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTReturnStatement(const ASTReturnStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSingleAssignment(const ASTSingleAssignment* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTParameterAssignment(const ASTParameterAssignment* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSystemVariableAssignment(const ASTSystemVariableAssignment* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAssignmentFromStruct(const ASTAssignmentFromStruct* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateTableStatement(const ASTCreateTableStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateExternalTableStatement(const ASTCreateExternalTableStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateViewStatement(const ASTCreateViewStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateMaterializedViewStatement(const ASTCreateMaterializedViewStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWhileStatement(const ASTWhileStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRepeatStatement(const ASTRepeatStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTForInStatement(const ASTForInStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterDatabaseStatement(const ASTAlterDatabaseStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterSchemaStatement(const ASTAlterSchemaStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterTableStatement(const ASTAlterTableStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterViewStatement(const ASTAlterViewStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterMaterializedViewStatement(const ASTAlterMaterializedViewStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterPrivilegeRestrictionStatement(const ASTAlterPrivilegeRestrictionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterRowAccessPolicyStatement(const ASTAlterRowAccessPolicyStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterEntityStatement(const ASTAlterEntityStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateFunctionStatement(const ASTCreateFunctionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateTableFunctionStatement(const ASTCreateTableFunctionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStructColumnSchema(const ASTStructColumnSchema* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTInferredTypeColumnSchema(const ASTInferredTypeColumnSchema* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExecuteIntoClause(const ASTExecuteIntoClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExecuteUsingArgument(const ASTExecuteUsingArgument* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExecuteUsingClause(const ASTExecuteUsingClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExecuteImmediateStatement(const ASTExecuteImmediateStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAuxLoadDataFromFilesOptionsList(const ASTAuxLoadDataFromFilesOptionsList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAuxLoadDataStatement(const ASTAuxLoadDataStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTLabel(const ASTLabel* node) {return defaultVisit(node);};

};
}  // namespace zetasql
#endif  // STORAGE_ZETASQL_PARSER_PARSE_TREE_VISITOR_H_
