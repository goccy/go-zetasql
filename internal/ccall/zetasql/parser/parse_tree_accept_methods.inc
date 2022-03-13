#include "zetasql/parser/parse_tree.h"
namespace zetasql {
void ASTQueryStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTQueryStatement(this, data);
}

void ASTQuery::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTQuery(this, data);
}

void ASTSelect::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSelect(this, data);
}

void ASTSelectList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSelectList(this, data);
}

void ASTSelectColumn::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSelectColumn(this, data);
}

void ASTIntLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIntLiteral(this, data);
}

void ASTIdentifier::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIdentifier(this, data);
}

void ASTAlias::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlias(this, data);
}

void ASTPathExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPathExpression(this, data);
}

void ASTTablePathExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTablePathExpression(this, data);
}

void ASTFromClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFromClause(this, data);
}

void ASTWhereClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWhereClause(this, data);
}

void ASTBooleanLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBooleanLiteral(this, data);
}

void ASTAndExpr::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAndExpr(this, data);
}

void ASTBinaryExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBinaryExpression(this, data);
}

void ASTStringLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStringLiteral(this, data);
}

void ASTStar::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStar(this, data);
}

void ASTOrExpr::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTOrExpr(this, data);
}

void ASTGroupingItem::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGroupingItem(this, data);
}

void ASTGroupBy::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGroupBy(this, data);
}

void ASTOrderingExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTOrderingExpression(this, data);
}

void ASTOrderBy::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTOrderBy(this, data);
}

void ASTLimitOffset::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTLimitOffset(this, data);
}

void ASTFloatLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFloatLiteral(this, data);
}

void ASTNullLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTNullLiteral(this, data);
}

void ASTOnClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTOnClause(this, data);
}

void ASTWithClauseEntry::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithClauseEntry(this, data);
}

void ASTJoin::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTJoin(this, data);
}

void ASTWithClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithClause(this, data);
}

void ASTHaving::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTHaving(this, data);
}

void ASTSimpleType::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSimpleType(this, data);
}

void ASTArrayType::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTArrayType(this, data);
}

void ASTStructField::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStructField(this, data);
}

void ASTStructType::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStructType(this, data);
}

void ASTCastExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCastExpression(this, data);
}

void ASTSelectAs::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSelectAs(this, data);
}

void ASTRollup::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRollup(this, data);
}

void ASTFunctionCall::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFunctionCall(this, data);
}

void ASTArrayConstructor::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTArrayConstructor(this, data);
}

void ASTStructConstructorArg::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStructConstructorArg(this, data);
}

void ASTStructConstructorWithParens::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStructConstructorWithParens(this, data);
}

void ASTStructConstructorWithKeyword::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStructConstructorWithKeyword(this, data);
}

void ASTInExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTInExpression(this, data);
}

void ASTInList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTInList(this, data);
}

void ASTBetweenExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBetweenExpression(this, data);
}

void ASTNumericLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTNumericLiteral(this, data);
}

void ASTBigNumericLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBigNumericLiteral(this, data);
}

void ASTBytesLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBytesLiteral(this, data);
}

void ASTDateOrTimeLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDateOrTimeLiteral(this, data);
}

void ASTMaxLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTMaxLiteral(this, data);
}

void ASTJSONLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTJSONLiteral(this, data);
}

void ASTCaseValueExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCaseValueExpression(this, data);
}

void ASTCaseNoValueExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCaseNoValueExpression(this, data);
}

void ASTArrayElement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTArrayElement(this, data);
}

void ASTBitwiseShiftExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBitwiseShiftExpression(this, data);
}

void ASTCollate::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCollate(this, data);
}

void ASTDotGeneralizedField::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDotGeneralizedField(this, data);
}

void ASTDotIdentifier::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDotIdentifier(this, data);
}

void ASTDotStar::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDotStar(this, data);
}

void ASTDotStarWithModifiers::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDotStarWithModifiers(this, data);
}

void ASTExpressionSubquery::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExpressionSubquery(this, data);
}

void ASTExtractExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExtractExpression(this, data);
}

void ASTHavingModifier::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTHavingModifier(this, data);
}

void ASTIntervalExpr::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIntervalExpr(this, data);
}

void ASTNamedArgument::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTNamedArgument(this, data);
}

void ASTNullOrder::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTNullOrder(this, data);
}

void ASTOnOrUsingClauseList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTOnOrUsingClauseList(this, data);
}

void ASTParenthesizedJoin::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTParenthesizedJoin(this, data);
}

void ASTPartitionBy::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPartitionBy(this, data);
}

void ASTSetOperation::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetOperation(this, data);
}

void ASTStarExceptList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStarExceptList(this, data);
}

void ASTStarModifiers::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStarModifiers(this, data);
}

void ASTStarReplaceItem::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStarReplaceItem(this, data);
}

void ASTStarWithModifiers::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStarWithModifiers(this, data);
}

void ASTTableSubquery::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTableSubquery(this, data);
}

void ASTUnaryExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUnaryExpression(this, data);
}

void ASTUnnestExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUnnestExpression(this, data);
}

void ASTWindowClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWindowClause(this, data);
}

void ASTWindowDefinition::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWindowDefinition(this, data);
}

void ASTWindowFrame::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWindowFrame(this, data);
}

void ASTWindowFrameExpr::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWindowFrameExpr(this, data);
}

void ASTLikeExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTLikeExpression(this, data);
}

void ASTWindowSpecification::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWindowSpecification(this, data);
}

void ASTWithOffset::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithOffset(this, data);
}

void ASTAnySomeAllOp::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAnySomeAllOp(this, data);
}

void ASTStatementList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStatementList(this, data);
}

void ASTHintedStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTHintedStatement(this, data);
}

void ASTExplainStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExplainStatement(this, data);
}

void ASTDescribeStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDescribeStatement(this, data);
}

void ASTShowStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTShowStatement(this, data);
}

void ASTTransactionIsolationLevel::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTransactionIsolationLevel(this, data);
}

void ASTTransactionReadWriteMode::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTransactionReadWriteMode(this, data);
}

void ASTTransactionModeList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTransactionModeList(this, data);
}

void ASTBeginStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBeginStatement(this, data);
}

void ASTSetTransactionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetTransactionStatement(this, data);
}

void ASTCommitStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCommitStatement(this, data);
}

void ASTRollbackStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRollbackStatement(this, data);
}

void ASTStartBatchStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStartBatchStatement(this, data);
}

void ASTRunBatchStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRunBatchStatement(this, data);
}

void ASTAbortBatchStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAbortBatchStatement(this, data);
}

void ASTDropEntityStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropEntityStatement(this, data);
}

void ASTDropFunctionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropFunctionStatement(this, data);
}

void ASTDropTableFunctionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropTableFunctionStatement(this, data);
}

void ASTDropAllRowAccessPoliciesStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropAllRowAccessPoliciesStatement(this, data);
}

void ASTDropMaterializedViewStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropMaterializedViewStatement(this, data);
}

void ASTDropSnapshotTableStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropSnapshotTableStatement(this, data);
}

void ASTDropSearchIndexStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropSearchIndexStatement(this, data);
}

void ASTRenameStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRenameStatement(this, data);
}

void ASTImportStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTImportStatement(this, data);
}

void ASTModuleStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTModuleStatement(this, data);
}

void ASTWithConnectionClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithConnectionClause(this, data);
}

void ASTIntoAlias::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIntoAlias(this, data);
}

void ASTUnnestExpressionWithOptAliasAndOffset::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUnnestExpressionWithOptAliasAndOffset(this, data);
}

void ASTPivotExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPivotExpression(this, data);
}

void ASTPivotValue::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPivotValue(this, data);
}

void ASTPivotExpressionList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPivotExpressionList(this, data);
}

void ASTPivotValueList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPivotValueList(this, data);
}

void ASTPivotClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPivotClause(this, data);
}

void ASTUnpivotInItem::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUnpivotInItem(this, data);
}

void ASTUnpivotInItemList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUnpivotInItemList(this, data);
}

void ASTUnpivotClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUnpivotClause(this, data);
}

void ASTUsingClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUsingClause(this, data);
}

void ASTForSystemTime::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTForSystemTime(this, data);
}

void ASTQualify::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTQualify(this, data);
}

void ASTClampedBetweenModifier::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTClampedBetweenModifier(this, data);
}

void ASTFormatClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFormatClause(this, data);
}

void ASTPathExpressionList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPathExpressionList(this, data);
}

void ASTParameterExpr::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTParameterExpr(this, data);
}

void ASTSystemVariableExpr::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSystemVariableExpr(this, data);
}

void ASTWithGroupRows::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithGroupRows(this, data);
}

void ASTLambda::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTLambda(this, data);
}

void ASTAnalyticFunctionCall::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAnalyticFunctionCall(this, data);
}

void ASTFunctionCallWithGroupRows::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFunctionCallWithGroupRows(this, data);
}

void ASTClusterBy::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTClusterBy(this, data);
}

void ASTNewConstructorArg::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTNewConstructorArg(this, data);
}

void ASTNewConstructor::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTNewConstructor(this, data);
}

void ASTOptionsList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTOptionsList(this, data);
}

void ASTOptionsEntry::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTOptionsEntry(this, data);
}

void ASTFunctionParameter::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFunctionParameter(this, data);
}

void ASTFunctionParameters::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFunctionParameters(this, data);
}

void ASTFunctionDeclaration::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFunctionDeclaration(this, data);
}

void ASTSqlFunctionBody::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSqlFunctionBody(this, data);
}

void ASTTVFArgument::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTVFArgument(this, data);
}

void ASTTVF::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTVF(this, data);
}

void ASTTableClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTableClause(this, data);
}

void ASTModelClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTModelClause(this, data);
}

void ASTConnectionClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTConnectionClause(this, data);
}

void ASTCloneDataSource::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCloneDataSource(this, data);
}

void ASTCopyDataSource::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCopyDataSource(this, data);
}

void ASTCloneDataSourceList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCloneDataSourceList(this, data);
}

void ASTCloneDataStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCloneDataStatement(this, data);
}

void ASTCreateConstantStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateConstantStatement(this, data);
}

void ASTCreateDatabaseStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateDatabaseStatement(this, data);
}

void ASTCreateProcedureStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateProcedureStatement(this, data);
}

void ASTCreateSchemaStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateSchemaStatement(this, data);
}

void ASTTransformClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTransformClause(this, data);
}

void ASTCreateModelStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateModelStatement(this, data);
}

void ASTIndexAllColumns::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIndexAllColumns(this, data);
}

void ASTIndexItemList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIndexItemList(this, data);
}

void ASTIndexStoringExpressionList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIndexStoringExpressionList(this, data);
}

void ASTIndexUnnestExpressionList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIndexUnnestExpressionList(this, data);
}

void ASTCreateIndexStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateIndexStatement(this, data);
}

void ASTExportDataStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExportDataStatement(this, data);
}

void ASTExportModelStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExportModelStatement(this, data);
}

void ASTCallStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCallStatement(this, data);
}

void ASTDefineTableStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDefineTableStatement(this, data);
}

void ASTWithPartitionColumnsClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithPartitionColumnsClause(this, data);
}

void ASTCreateSnapshotTableStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateSnapshotTableStatement(this, data);
}

void ASTTypeParameterList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTypeParameterList(this, data);
}

void ASTTVFSchema::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTVFSchema(this, data);
}

void ASTTVFSchemaColumn::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTVFSchemaColumn(this, data);
}

void ASTTableAndColumnInfo::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTableAndColumnInfo(this, data);
}

void ASTTableAndColumnInfoList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTableAndColumnInfoList(this, data);
}

void ASTTemplatedParameterType::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTemplatedParameterType(this, data);
}

void ASTDefaultLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDefaultLiteral(this, data);
}

void ASTAnalyzeStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAnalyzeStatement(this, data);
}

void ASTAssertStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAssertStatement(this, data);
}

void ASTAssertRowsModified::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAssertRowsModified(this, data);
}

void ASTReturningClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTReturningClause(this, data);
}

void ASTDeleteStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDeleteStatement(this, data);
}

void ASTNotNullColumnAttribute::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTNotNullColumnAttribute(this, data);
}

void ASTHiddenColumnAttribute::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTHiddenColumnAttribute(this, data);
}

void ASTPrimaryKeyColumnAttribute::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPrimaryKeyColumnAttribute(this, data);
}

void ASTForeignKeyColumnAttribute::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTForeignKeyColumnAttribute(this, data);
}

void ASTColumnAttributeList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTColumnAttributeList(this, data);
}

void ASTStructColumnField::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStructColumnField(this, data);
}

void ASTGeneratedColumnInfo::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGeneratedColumnInfo(this, data);
}

void ASTColumnDefinition::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTColumnDefinition(this, data);
}

void ASTTableElementList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTableElementList(this, data);
}

void ASTColumnList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTColumnList(this, data);
}

void ASTColumnPosition::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTColumnPosition(this, data);
}

void ASTInsertValuesRow::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTInsertValuesRow(this, data);
}

void ASTInsertValuesRowList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTInsertValuesRowList(this, data);
}

void ASTInsertStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTInsertStatement(this, data);
}

void ASTUpdateSetValue::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUpdateSetValue(this, data);
}

void ASTUpdateItem::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUpdateItem(this, data);
}

void ASTUpdateItemList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUpdateItemList(this, data);
}

void ASTUpdateStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUpdateStatement(this, data);
}

void ASTTruncateStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTruncateStatement(this, data);
}

void ASTMergeAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTMergeAction(this, data);
}

void ASTMergeWhenClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTMergeWhenClause(this, data);
}

void ASTMergeWhenClauseList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTMergeWhenClauseList(this, data);
}

void ASTMergeStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTMergeStatement(this, data);
}

void ASTPrivilege::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPrivilege(this, data);
}

void ASTPrivileges::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPrivileges(this, data);
}

void ASTGranteeList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGranteeList(this, data);
}

void ASTGrantStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGrantStatement(this, data);
}

void ASTRevokeStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRevokeStatement(this, data);
}

void ASTRepeatableClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRepeatableClause(this, data);
}

void ASTFilterFieldsArg::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFilterFieldsArg(this, data);
}

void ASTReplaceFieldsArg::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTReplaceFieldsArg(this, data);
}

void ASTReplaceFieldsExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTReplaceFieldsExpression(this, data);
}

void ASTSampleSize::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSampleSize(this, data);
}

void ASTWithWeight::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithWeight(this, data);
}

void ASTSampleSuffix::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSampleSuffix(this, data);
}

void ASTSampleClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSampleClause(this, data);
}

void ASTSetOptionsAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetOptionsAction(this, data);
}

void ASTSetAsAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetAsAction(this, data);
}

void ASTAddConstraintAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAddConstraintAction(this, data);
}

void ASTDropPrimaryKeyAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropPrimaryKeyAction(this, data);
}

void ASTDropConstraintAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropConstraintAction(this, data);
}

void ASTAlterConstraintEnforcementAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterConstraintEnforcementAction(this, data);
}

void ASTAlterConstraintSetOptionsAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterConstraintSetOptionsAction(this, data);
}

void ASTAddColumnAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAddColumnAction(this, data);
}

void ASTDropColumnAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropColumnAction(this, data);
}

void ASTRenameColumnAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRenameColumnAction(this, data);
}

void ASTAlterColumnTypeAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterColumnTypeAction(this, data);
}

void ASTAlterColumnOptionsAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterColumnOptionsAction(this, data);
}

void ASTAlterColumnSetDefaultAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterColumnSetDefaultAction(this, data);
}

void ASTAlterColumnDropDefaultAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterColumnDropDefaultAction(this, data);
}

void ASTAlterColumnDropNotNullAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterColumnDropNotNullAction(this, data);
}

void ASTGrantToClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGrantToClause(this, data);
}

void ASTRestrictToClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRestrictToClause(this, data);
}

void ASTAddToRestricteeListClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAddToRestricteeListClause(this, data);
}

void ASTRemoveFromRestricteeListClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRemoveFromRestricteeListClause(this, data);
}

void ASTFilterUsingClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFilterUsingClause(this, data);
}

void ASTRevokeFromClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRevokeFromClause(this, data);
}

void ASTRenameToClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRenameToClause(this, data);
}

void ASTSetCollateClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetCollateClause(this, data);
}

void ASTAlterActionList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterActionList(this, data);
}

void ASTAlterAllRowAccessPoliciesStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterAllRowAccessPoliciesStatement(this, data);
}

void ASTForeignKeyActions::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTForeignKeyActions(this, data);
}

void ASTForeignKeyReference::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTForeignKeyReference(this, data);
}

void ASTScript::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTScript(this, data);
}

void ASTElseifClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTElseifClause(this, data);
}

void ASTElseifClauseList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTElseifClauseList(this, data);
}

void ASTIfStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIfStatement(this, data);
}

void ASTWhenThenClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWhenThenClause(this, data);
}

void ASTWhenThenClauseList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWhenThenClauseList(this, data);
}

void ASTCaseStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCaseStatement(this, data);
}

void ASTHint::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTHint(this, data);
}

void ASTHintEntry::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTHintEntry(this, data);
}

void ASTUnpivotInItemLabel::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUnpivotInItemLabel(this, data);
}

void ASTDescriptor::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDescriptor(this, data);
}

void ASTSimpleColumnSchema::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSimpleColumnSchema(this, data);
}

void ASTArrayColumnSchema::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTArrayColumnSchema(this, data);
}

void ASTPrimaryKey::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPrimaryKey(this, data);
}

void ASTForeignKey::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTForeignKey(this, data);
}

void ASTCheckConstraint::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCheckConstraint(this, data);
}

void ASTDescriptorColumn::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDescriptorColumn(this, data);
}

void ASTDescriptorColumnList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDescriptorColumnList(this, data);
}

void ASTCreateEntityStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateEntityStatement(this, data);
}

void ASTRaiseStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRaiseStatement(this, data);
}

void ASTExceptionHandler::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExceptionHandler(this, data);
}

void ASTExceptionHandlerList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExceptionHandlerList(this, data);
}

void ASTBeginEndBlock::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBeginEndBlock(this, data);
}

void ASTIdentifierList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIdentifierList(this, data);
}

void ASTVariableDeclaration::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTVariableDeclaration(this, data);
}

void ASTUntilClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUntilClause(this, data);
}

void ASTBreakStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBreakStatement(this, data);
}

void ASTContinueStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTContinueStatement(this, data);
}

void ASTDropPrivilegeRestrictionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropPrivilegeRestrictionStatement(this, data);
}

void ASTDropRowAccessPolicyStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropRowAccessPolicyStatement(this, data);
}

void ASTCreatePrivilegeRestrictionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreatePrivilegeRestrictionStatement(this, data);
}

void ASTCreateRowAccessPolicyStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateRowAccessPolicyStatement(this, data);
}

void ASTDropStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropStatement(this, data);
}

void ASTReturnStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTReturnStatement(this, data);
}

void ASTSingleAssignment::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSingleAssignment(this, data);
}

void ASTParameterAssignment::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTParameterAssignment(this, data);
}

void ASTSystemVariableAssignment::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSystemVariableAssignment(this, data);
}

void ASTAssignmentFromStruct::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAssignmentFromStruct(this, data);
}

void ASTCreateTableStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateTableStatement(this, data);
}

void ASTCreateExternalTableStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateExternalTableStatement(this, data);
}

void ASTCreateViewStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateViewStatement(this, data);
}

void ASTCreateMaterializedViewStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateMaterializedViewStatement(this, data);
}

void ASTWhileStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWhileStatement(this, data);
}

void ASTRepeatStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRepeatStatement(this, data);
}

void ASTForInStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTForInStatement(this, data);
}

void ASTAlterDatabaseStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterDatabaseStatement(this, data);
}

void ASTAlterSchemaStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterSchemaStatement(this, data);
}

void ASTAlterTableStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterTableStatement(this, data);
}

void ASTAlterViewStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterViewStatement(this, data);
}

void ASTAlterMaterializedViewStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterMaterializedViewStatement(this, data);
}

void ASTAlterPrivilegeRestrictionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterPrivilegeRestrictionStatement(this, data);
}

void ASTAlterRowAccessPolicyStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterRowAccessPolicyStatement(this, data);
}

void ASTAlterEntityStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterEntityStatement(this, data);
}

void ASTCreateFunctionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateFunctionStatement(this, data);
}

void ASTCreateTableFunctionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateTableFunctionStatement(this, data);
}

void ASTStructColumnSchema::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStructColumnSchema(this, data);
}

void ASTInferredTypeColumnSchema::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTInferredTypeColumnSchema(this, data);
}

void ASTExecuteIntoClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExecuteIntoClause(this, data);
}

void ASTExecuteUsingArgument::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExecuteUsingArgument(this, data);
}

void ASTExecuteUsingClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExecuteUsingClause(this, data);
}

void ASTExecuteImmediateStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExecuteImmediateStatement(this, data);
}

void ASTAuxLoadDataFromFilesOptionsList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAuxLoadDataFromFilesOptionsList(this, data);
}

void ASTAuxLoadDataStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAuxLoadDataStatement(this, data);
}

void ASTLabel::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTLabel(this, data);
}

absl::StatusOr<VisitResult> ASTQueryStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTQueryStatement(this);
}

absl::StatusOr<VisitResult> ASTQuery::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTQuery(this);
}

absl::StatusOr<VisitResult> ASTSelect::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSelect(this);
}

absl::StatusOr<VisitResult> ASTSelectList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSelectList(this);
}

absl::StatusOr<VisitResult> ASTSelectColumn::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSelectColumn(this);
}

absl::StatusOr<VisitResult> ASTIntLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIntLiteral(this);
}

absl::StatusOr<VisitResult> ASTIdentifier::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIdentifier(this);
}

absl::StatusOr<VisitResult> ASTAlias::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlias(this);
}

absl::StatusOr<VisitResult> ASTPathExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPathExpression(this);
}

absl::StatusOr<VisitResult> ASTTablePathExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTablePathExpression(this);
}

absl::StatusOr<VisitResult> ASTFromClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFromClause(this);
}

absl::StatusOr<VisitResult> ASTWhereClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWhereClause(this);
}

absl::StatusOr<VisitResult> ASTBooleanLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBooleanLiteral(this);
}

absl::StatusOr<VisitResult> ASTAndExpr::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAndExpr(this);
}

absl::StatusOr<VisitResult> ASTBinaryExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBinaryExpression(this);
}

absl::StatusOr<VisitResult> ASTStringLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStringLiteral(this);
}

absl::StatusOr<VisitResult> ASTStar::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStar(this);
}

absl::StatusOr<VisitResult> ASTOrExpr::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTOrExpr(this);
}

absl::StatusOr<VisitResult> ASTGroupingItem::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGroupingItem(this);
}

absl::StatusOr<VisitResult> ASTGroupBy::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGroupBy(this);
}

absl::StatusOr<VisitResult> ASTOrderingExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTOrderingExpression(this);
}

absl::StatusOr<VisitResult> ASTOrderBy::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTOrderBy(this);
}

absl::StatusOr<VisitResult> ASTLimitOffset::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTLimitOffset(this);
}

absl::StatusOr<VisitResult> ASTFloatLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFloatLiteral(this);
}

absl::StatusOr<VisitResult> ASTNullLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTNullLiteral(this);
}

absl::StatusOr<VisitResult> ASTOnClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTOnClause(this);
}

absl::StatusOr<VisitResult> ASTWithClauseEntry::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithClauseEntry(this);
}

absl::StatusOr<VisitResult> ASTJoin::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTJoin(this);
}

absl::StatusOr<VisitResult> ASTWithClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithClause(this);
}

absl::StatusOr<VisitResult> ASTHaving::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTHaving(this);
}

absl::StatusOr<VisitResult> ASTSimpleType::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSimpleType(this);
}

absl::StatusOr<VisitResult> ASTArrayType::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTArrayType(this);
}

absl::StatusOr<VisitResult> ASTStructField::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStructField(this);
}

absl::StatusOr<VisitResult> ASTStructType::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStructType(this);
}

absl::StatusOr<VisitResult> ASTCastExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCastExpression(this);
}

absl::StatusOr<VisitResult> ASTSelectAs::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSelectAs(this);
}

absl::StatusOr<VisitResult> ASTRollup::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRollup(this);
}

absl::StatusOr<VisitResult> ASTFunctionCall::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFunctionCall(this);
}

absl::StatusOr<VisitResult> ASTArrayConstructor::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTArrayConstructor(this);
}

absl::StatusOr<VisitResult> ASTStructConstructorArg::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStructConstructorArg(this);
}

absl::StatusOr<VisitResult> ASTStructConstructorWithParens::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStructConstructorWithParens(this);
}

absl::StatusOr<VisitResult> ASTStructConstructorWithKeyword::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStructConstructorWithKeyword(this);
}

absl::StatusOr<VisitResult> ASTInExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTInExpression(this);
}

absl::StatusOr<VisitResult> ASTInList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTInList(this);
}

absl::StatusOr<VisitResult> ASTBetweenExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBetweenExpression(this);
}

absl::StatusOr<VisitResult> ASTNumericLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTNumericLiteral(this);
}

absl::StatusOr<VisitResult> ASTBigNumericLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBigNumericLiteral(this);
}

absl::StatusOr<VisitResult> ASTBytesLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBytesLiteral(this);
}

absl::StatusOr<VisitResult> ASTDateOrTimeLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDateOrTimeLiteral(this);
}

absl::StatusOr<VisitResult> ASTMaxLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTMaxLiteral(this);
}

absl::StatusOr<VisitResult> ASTJSONLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTJSONLiteral(this);
}

absl::StatusOr<VisitResult> ASTCaseValueExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCaseValueExpression(this);
}

absl::StatusOr<VisitResult> ASTCaseNoValueExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCaseNoValueExpression(this);
}

absl::StatusOr<VisitResult> ASTArrayElement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTArrayElement(this);
}

absl::StatusOr<VisitResult> ASTBitwiseShiftExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBitwiseShiftExpression(this);
}

absl::StatusOr<VisitResult> ASTCollate::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCollate(this);
}

absl::StatusOr<VisitResult> ASTDotGeneralizedField::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDotGeneralizedField(this);
}

absl::StatusOr<VisitResult> ASTDotIdentifier::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDotIdentifier(this);
}

absl::StatusOr<VisitResult> ASTDotStar::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDotStar(this);
}

absl::StatusOr<VisitResult> ASTDotStarWithModifiers::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDotStarWithModifiers(this);
}

absl::StatusOr<VisitResult> ASTExpressionSubquery::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExpressionSubquery(this);
}

absl::StatusOr<VisitResult> ASTExtractExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExtractExpression(this);
}

absl::StatusOr<VisitResult> ASTHavingModifier::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTHavingModifier(this);
}

absl::StatusOr<VisitResult> ASTIntervalExpr::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIntervalExpr(this);
}

absl::StatusOr<VisitResult> ASTNamedArgument::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTNamedArgument(this);
}

absl::StatusOr<VisitResult> ASTNullOrder::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTNullOrder(this);
}

absl::StatusOr<VisitResult> ASTOnOrUsingClauseList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTOnOrUsingClauseList(this);
}

absl::StatusOr<VisitResult> ASTParenthesizedJoin::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTParenthesizedJoin(this);
}

absl::StatusOr<VisitResult> ASTPartitionBy::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPartitionBy(this);
}

absl::StatusOr<VisitResult> ASTSetOperation::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetOperation(this);
}

absl::StatusOr<VisitResult> ASTStarExceptList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStarExceptList(this);
}

absl::StatusOr<VisitResult> ASTStarModifiers::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStarModifiers(this);
}

absl::StatusOr<VisitResult> ASTStarReplaceItem::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStarReplaceItem(this);
}

absl::StatusOr<VisitResult> ASTStarWithModifiers::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStarWithModifiers(this);
}

absl::StatusOr<VisitResult> ASTTableSubquery::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTableSubquery(this);
}

absl::StatusOr<VisitResult> ASTUnaryExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUnaryExpression(this);
}

absl::StatusOr<VisitResult> ASTUnnestExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUnnestExpression(this);
}

absl::StatusOr<VisitResult> ASTWindowClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWindowClause(this);
}

absl::StatusOr<VisitResult> ASTWindowDefinition::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWindowDefinition(this);
}

absl::StatusOr<VisitResult> ASTWindowFrame::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWindowFrame(this);
}

absl::StatusOr<VisitResult> ASTWindowFrameExpr::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWindowFrameExpr(this);
}

absl::StatusOr<VisitResult> ASTLikeExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTLikeExpression(this);
}

absl::StatusOr<VisitResult> ASTWindowSpecification::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWindowSpecification(this);
}

absl::StatusOr<VisitResult> ASTWithOffset::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithOffset(this);
}

absl::StatusOr<VisitResult> ASTAnySomeAllOp::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAnySomeAllOp(this);
}

absl::StatusOr<VisitResult> ASTStatementList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStatementList(this);
}

absl::StatusOr<VisitResult> ASTHintedStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTHintedStatement(this);
}

absl::StatusOr<VisitResult> ASTExplainStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExplainStatement(this);
}

absl::StatusOr<VisitResult> ASTDescribeStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDescribeStatement(this);
}

absl::StatusOr<VisitResult> ASTShowStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTShowStatement(this);
}

absl::StatusOr<VisitResult> ASTTransactionIsolationLevel::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTransactionIsolationLevel(this);
}

absl::StatusOr<VisitResult> ASTTransactionReadWriteMode::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTransactionReadWriteMode(this);
}

absl::StatusOr<VisitResult> ASTTransactionModeList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTransactionModeList(this);
}

absl::StatusOr<VisitResult> ASTBeginStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBeginStatement(this);
}

absl::StatusOr<VisitResult> ASTSetTransactionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetTransactionStatement(this);
}

absl::StatusOr<VisitResult> ASTCommitStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCommitStatement(this);
}

absl::StatusOr<VisitResult> ASTRollbackStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRollbackStatement(this);
}

absl::StatusOr<VisitResult> ASTStartBatchStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStartBatchStatement(this);
}

absl::StatusOr<VisitResult> ASTRunBatchStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRunBatchStatement(this);
}

absl::StatusOr<VisitResult> ASTAbortBatchStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAbortBatchStatement(this);
}

absl::StatusOr<VisitResult> ASTDropEntityStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropEntityStatement(this);
}

absl::StatusOr<VisitResult> ASTDropFunctionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropFunctionStatement(this);
}

absl::StatusOr<VisitResult> ASTDropTableFunctionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropTableFunctionStatement(this);
}

absl::StatusOr<VisitResult> ASTDropAllRowAccessPoliciesStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropAllRowAccessPoliciesStatement(this);
}

absl::StatusOr<VisitResult> ASTDropMaterializedViewStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropMaterializedViewStatement(this);
}

absl::StatusOr<VisitResult> ASTDropSnapshotTableStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropSnapshotTableStatement(this);
}

absl::StatusOr<VisitResult> ASTDropSearchIndexStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropSearchIndexStatement(this);
}

absl::StatusOr<VisitResult> ASTRenameStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRenameStatement(this);
}

absl::StatusOr<VisitResult> ASTImportStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTImportStatement(this);
}

absl::StatusOr<VisitResult> ASTModuleStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTModuleStatement(this);
}

absl::StatusOr<VisitResult> ASTWithConnectionClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithConnectionClause(this);
}

absl::StatusOr<VisitResult> ASTIntoAlias::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIntoAlias(this);
}

absl::StatusOr<VisitResult> ASTUnnestExpressionWithOptAliasAndOffset::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUnnestExpressionWithOptAliasAndOffset(this);
}

absl::StatusOr<VisitResult> ASTPivotExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPivotExpression(this);
}

absl::StatusOr<VisitResult> ASTPivotValue::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPivotValue(this);
}

absl::StatusOr<VisitResult> ASTPivotExpressionList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPivotExpressionList(this);
}

absl::StatusOr<VisitResult> ASTPivotValueList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPivotValueList(this);
}

absl::StatusOr<VisitResult> ASTPivotClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPivotClause(this);
}

absl::StatusOr<VisitResult> ASTUnpivotInItem::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUnpivotInItem(this);
}

absl::StatusOr<VisitResult> ASTUnpivotInItemList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUnpivotInItemList(this);
}

absl::StatusOr<VisitResult> ASTUnpivotClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUnpivotClause(this);
}

absl::StatusOr<VisitResult> ASTUsingClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUsingClause(this);
}

absl::StatusOr<VisitResult> ASTForSystemTime::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTForSystemTime(this);
}

absl::StatusOr<VisitResult> ASTQualify::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTQualify(this);
}

absl::StatusOr<VisitResult> ASTClampedBetweenModifier::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTClampedBetweenModifier(this);
}

absl::StatusOr<VisitResult> ASTFormatClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFormatClause(this);
}

absl::StatusOr<VisitResult> ASTPathExpressionList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPathExpressionList(this);
}

absl::StatusOr<VisitResult> ASTParameterExpr::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTParameterExpr(this);
}

absl::StatusOr<VisitResult> ASTSystemVariableExpr::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSystemVariableExpr(this);
}

absl::StatusOr<VisitResult> ASTWithGroupRows::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithGroupRows(this);
}

absl::StatusOr<VisitResult> ASTLambda::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTLambda(this);
}

absl::StatusOr<VisitResult> ASTAnalyticFunctionCall::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAnalyticFunctionCall(this);
}

absl::StatusOr<VisitResult> ASTFunctionCallWithGroupRows::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFunctionCallWithGroupRows(this);
}

absl::StatusOr<VisitResult> ASTClusterBy::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTClusterBy(this);
}

absl::StatusOr<VisitResult> ASTNewConstructorArg::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTNewConstructorArg(this);
}

absl::StatusOr<VisitResult> ASTNewConstructor::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTNewConstructor(this);
}

absl::StatusOr<VisitResult> ASTOptionsList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTOptionsList(this);
}

absl::StatusOr<VisitResult> ASTOptionsEntry::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTOptionsEntry(this);
}

absl::StatusOr<VisitResult> ASTFunctionParameter::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFunctionParameter(this);
}

absl::StatusOr<VisitResult> ASTFunctionParameters::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFunctionParameters(this);
}

absl::StatusOr<VisitResult> ASTFunctionDeclaration::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFunctionDeclaration(this);
}

absl::StatusOr<VisitResult> ASTSqlFunctionBody::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSqlFunctionBody(this);
}

absl::StatusOr<VisitResult> ASTTVFArgument::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTVFArgument(this);
}

absl::StatusOr<VisitResult> ASTTVF::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTVF(this);
}

absl::StatusOr<VisitResult> ASTTableClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTableClause(this);
}

absl::StatusOr<VisitResult> ASTModelClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTModelClause(this);
}

absl::StatusOr<VisitResult> ASTConnectionClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTConnectionClause(this);
}

absl::StatusOr<VisitResult> ASTCloneDataSource::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCloneDataSource(this);
}

absl::StatusOr<VisitResult> ASTCopyDataSource::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCopyDataSource(this);
}

absl::StatusOr<VisitResult> ASTCloneDataSourceList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCloneDataSourceList(this);
}

absl::StatusOr<VisitResult> ASTCloneDataStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCloneDataStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateConstantStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateConstantStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateDatabaseStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateDatabaseStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateProcedureStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateProcedureStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateSchemaStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateSchemaStatement(this);
}

absl::StatusOr<VisitResult> ASTTransformClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTransformClause(this);
}

absl::StatusOr<VisitResult> ASTCreateModelStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateModelStatement(this);
}

absl::StatusOr<VisitResult> ASTIndexAllColumns::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIndexAllColumns(this);
}

absl::StatusOr<VisitResult> ASTIndexItemList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIndexItemList(this);
}

absl::StatusOr<VisitResult> ASTIndexStoringExpressionList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIndexStoringExpressionList(this);
}

absl::StatusOr<VisitResult> ASTIndexUnnestExpressionList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIndexUnnestExpressionList(this);
}

absl::StatusOr<VisitResult> ASTCreateIndexStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateIndexStatement(this);
}

absl::StatusOr<VisitResult> ASTExportDataStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExportDataStatement(this);
}

absl::StatusOr<VisitResult> ASTExportModelStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExportModelStatement(this);
}

absl::StatusOr<VisitResult> ASTCallStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCallStatement(this);
}

absl::StatusOr<VisitResult> ASTDefineTableStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDefineTableStatement(this);
}

absl::StatusOr<VisitResult> ASTWithPartitionColumnsClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithPartitionColumnsClause(this);
}

absl::StatusOr<VisitResult> ASTCreateSnapshotTableStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateSnapshotTableStatement(this);
}

absl::StatusOr<VisitResult> ASTTypeParameterList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTypeParameterList(this);
}

absl::StatusOr<VisitResult> ASTTVFSchema::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTVFSchema(this);
}

absl::StatusOr<VisitResult> ASTTVFSchemaColumn::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTVFSchemaColumn(this);
}

absl::StatusOr<VisitResult> ASTTableAndColumnInfo::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTableAndColumnInfo(this);
}

absl::StatusOr<VisitResult> ASTTableAndColumnInfoList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTableAndColumnInfoList(this);
}

absl::StatusOr<VisitResult> ASTTemplatedParameterType::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTemplatedParameterType(this);
}

absl::StatusOr<VisitResult> ASTDefaultLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDefaultLiteral(this);
}

absl::StatusOr<VisitResult> ASTAnalyzeStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAnalyzeStatement(this);
}

absl::StatusOr<VisitResult> ASTAssertStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAssertStatement(this);
}

absl::StatusOr<VisitResult> ASTAssertRowsModified::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAssertRowsModified(this);
}

absl::StatusOr<VisitResult> ASTReturningClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTReturningClause(this);
}

absl::StatusOr<VisitResult> ASTDeleteStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDeleteStatement(this);
}

absl::StatusOr<VisitResult> ASTNotNullColumnAttribute::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTNotNullColumnAttribute(this);
}

absl::StatusOr<VisitResult> ASTHiddenColumnAttribute::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTHiddenColumnAttribute(this);
}

absl::StatusOr<VisitResult> ASTPrimaryKeyColumnAttribute::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPrimaryKeyColumnAttribute(this);
}

absl::StatusOr<VisitResult> ASTForeignKeyColumnAttribute::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTForeignKeyColumnAttribute(this);
}

absl::StatusOr<VisitResult> ASTColumnAttributeList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTColumnAttributeList(this);
}

absl::StatusOr<VisitResult> ASTStructColumnField::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStructColumnField(this);
}

absl::StatusOr<VisitResult> ASTGeneratedColumnInfo::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGeneratedColumnInfo(this);
}

absl::StatusOr<VisitResult> ASTColumnDefinition::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTColumnDefinition(this);
}

absl::StatusOr<VisitResult> ASTTableElementList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTableElementList(this);
}

absl::StatusOr<VisitResult> ASTColumnList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTColumnList(this);
}

absl::StatusOr<VisitResult> ASTColumnPosition::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTColumnPosition(this);
}

absl::StatusOr<VisitResult> ASTInsertValuesRow::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTInsertValuesRow(this);
}

absl::StatusOr<VisitResult> ASTInsertValuesRowList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTInsertValuesRowList(this);
}

absl::StatusOr<VisitResult> ASTInsertStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTInsertStatement(this);
}

absl::StatusOr<VisitResult> ASTUpdateSetValue::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUpdateSetValue(this);
}

absl::StatusOr<VisitResult> ASTUpdateItem::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUpdateItem(this);
}

absl::StatusOr<VisitResult> ASTUpdateItemList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUpdateItemList(this);
}

absl::StatusOr<VisitResult> ASTUpdateStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUpdateStatement(this);
}

absl::StatusOr<VisitResult> ASTTruncateStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTruncateStatement(this);
}

absl::StatusOr<VisitResult> ASTMergeAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTMergeAction(this);
}

absl::StatusOr<VisitResult> ASTMergeWhenClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTMergeWhenClause(this);
}

absl::StatusOr<VisitResult> ASTMergeWhenClauseList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTMergeWhenClauseList(this);
}

absl::StatusOr<VisitResult> ASTMergeStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTMergeStatement(this);
}

absl::StatusOr<VisitResult> ASTPrivilege::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPrivilege(this);
}

absl::StatusOr<VisitResult> ASTPrivileges::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPrivileges(this);
}

absl::StatusOr<VisitResult> ASTGranteeList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGranteeList(this);
}

absl::StatusOr<VisitResult> ASTGrantStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGrantStatement(this);
}

absl::StatusOr<VisitResult> ASTRevokeStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRevokeStatement(this);
}

absl::StatusOr<VisitResult> ASTRepeatableClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRepeatableClause(this);
}

absl::StatusOr<VisitResult> ASTFilterFieldsArg::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFilterFieldsArg(this);
}

absl::StatusOr<VisitResult> ASTReplaceFieldsArg::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTReplaceFieldsArg(this);
}

absl::StatusOr<VisitResult> ASTReplaceFieldsExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTReplaceFieldsExpression(this);
}

absl::StatusOr<VisitResult> ASTSampleSize::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSampleSize(this);
}

absl::StatusOr<VisitResult> ASTWithWeight::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithWeight(this);
}

absl::StatusOr<VisitResult> ASTSampleSuffix::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSampleSuffix(this);
}

absl::StatusOr<VisitResult> ASTSampleClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSampleClause(this);
}

absl::StatusOr<VisitResult> ASTSetOptionsAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetOptionsAction(this);
}

absl::StatusOr<VisitResult> ASTSetAsAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetAsAction(this);
}

absl::StatusOr<VisitResult> ASTAddConstraintAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAddConstraintAction(this);
}

absl::StatusOr<VisitResult> ASTDropPrimaryKeyAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropPrimaryKeyAction(this);
}

absl::StatusOr<VisitResult> ASTDropConstraintAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropConstraintAction(this);
}

absl::StatusOr<VisitResult> ASTAlterConstraintEnforcementAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterConstraintEnforcementAction(this);
}

absl::StatusOr<VisitResult> ASTAlterConstraintSetOptionsAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterConstraintSetOptionsAction(this);
}

absl::StatusOr<VisitResult> ASTAddColumnAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAddColumnAction(this);
}

absl::StatusOr<VisitResult> ASTDropColumnAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropColumnAction(this);
}

absl::StatusOr<VisitResult> ASTRenameColumnAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRenameColumnAction(this);
}

absl::StatusOr<VisitResult> ASTAlterColumnTypeAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterColumnTypeAction(this);
}

absl::StatusOr<VisitResult> ASTAlterColumnOptionsAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterColumnOptionsAction(this);
}

absl::StatusOr<VisitResult> ASTAlterColumnSetDefaultAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterColumnSetDefaultAction(this);
}

absl::StatusOr<VisitResult> ASTAlterColumnDropDefaultAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterColumnDropDefaultAction(this);
}

absl::StatusOr<VisitResult> ASTAlterColumnDropNotNullAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterColumnDropNotNullAction(this);
}

absl::StatusOr<VisitResult> ASTGrantToClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGrantToClause(this);
}

absl::StatusOr<VisitResult> ASTRestrictToClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRestrictToClause(this);
}

absl::StatusOr<VisitResult> ASTAddToRestricteeListClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAddToRestricteeListClause(this);
}

absl::StatusOr<VisitResult> ASTRemoveFromRestricteeListClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRemoveFromRestricteeListClause(this);
}

absl::StatusOr<VisitResult> ASTFilterUsingClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFilterUsingClause(this);
}

absl::StatusOr<VisitResult> ASTRevokeFromClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRevokeFromClause(this);
}

absl::StatusOr<VisitResult> ASTRenameToClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRenameToClause(this);
}

absl::StatusOr<VisitResult> ASTSetCollateClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetCollateClause(this);
}

absl::StatusOr<VisitResult> ASTAlterActionList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterActionList(this);
}

absl::StatusOr<VisitResult> ASTAlterAllRowAccessPoliciesStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterAllRowAccessPoliciesStatement(this);
}

absl::StatusOr<VisitResult> ASTForeignKeyActions::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTForeignKeyActions(this);
}

absl::StatusOr<VisitResult> ASTForeignKeyReference::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTForeignKeyReference(this);
}

absl::StatusOr<VisitResult> ASTScript::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTScript(this);
}

absl::StatusOr<VisitResult> ASTElseifClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTElseifClause(this);
}

absl::StatusOr<VisitResult> ASTElseifClauseList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTElseifClauseList(this);
}

absl::StatusOr<VisitResult> ASTIfStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIfStatement(this);
}

absl::StatusOr<VisitResult> ASTWhenThenClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWhenThenClause(this);
}

absl::StatusOr<VisitResult> ASTWhenThenClauseList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWhenThenClauseList(this);
}

absl::StatusOr<VisitResult> ASTCaseStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCaseStatement(this);
}

absl::StatusOr<VisitResult> ASTHint::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTHint(this);
}

absl::StatusOr<VisitResult> ASTHintEntry::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTHintEntry(this);
}

absl::StatusOr<VisitResult> ASTUnpivotInItemLabel::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUnpivotInItemLabel(this);
}

absl::StatusOr<VisitResult> ASTDescriptor::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDescriptor(this);
}

absl::StatusOr<VisitResult> ASTSimpleColumnSchema::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSimpleColumnSchema(this);
}

absl::StatusOr<VisitResult> ASTArrayColumnSchema::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTArrayColumnSchema(this);
}

absl::StatusOr<VisitResult> ASTPrimaryKey::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPrimaryKey(this);
}

absl::StatusOr<VisitResult> ASTForeignKey::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTForeignKey(this);
}

absl::StatusOr<VisitResult> ASTCheckConstraint::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCheckConstraint(this);
}

absl::StatusOr<VisitResult> ASTDescriptorColumn::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDescriptorColumn(this);
}

absl::StatusOr<VisitResult> ASTDescriptorColumnList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDescriptorColumnList(this);
}

absl::StatusOr<VisitResult> ASTCreateEntityStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateEntityStatement(this);
}

absl::StatusOr<VisitResult> ASTRaiseStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRaiseStatement(this);
}

absl::StatusOr<VisitResult> ASTExceptionHandler::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExceptionHandler(this);
}

absl::StatusOr<VisitResult> ASTExceptionHandlerList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExceptionHandlerList(this);
}

absl::StatusOr<VisitResult> ASTBeginEndBlock::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBeginEndBlock(this);
}

absl::StatusOr<VisitResult> ASTIdentifierList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIdentifierList(this);
}

absl::StatusOr<VisitResult> ASTVariableDeclaration::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTVariableDeclaration(this);
}

absl::StatusOr<VisitResult> ASTUntilClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUntilClause(this);
}

absl::StatusOr<VisitResult> ASTBreakStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBreakStatement(this);
}

absl::StatusOr<VisitResult> ASTContinueStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTContinueStatement(this);
}

absl::StatusOr<VisitResult> ASTDropPrivilegeRestrictionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropPrivilegeRestrictionStatement(this);
}

absl::StatusOr<VisitResult> ASTDropRowAccessPolicyStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropRowAccessPolicyStatement(this);
}

absl::StatusOr<VisitResult> ASTCreatePrivilegeRestrictionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreatePrivilegeRestrictionStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateRowAccessPolicyStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateRowAccessPolicyStatement(this);
}

absl::StatusOr<VisitResult> ASTDropStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropStatement(this);
}

absl::StatusOr<VisitResult> ASTReturnStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTReturnStatement(this);
}

absl::StatusOr<VisitResult> ASTSingleAssignment::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSingleAssignment(this);
}

absl::StatusOr<VisitResult> ASTParameterAssignment::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTParameterAssignment(this);
}

absl::StatusOr<VisitResult> ASTSystemVariableAssignment::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSystemVariableAssignment(this);
}

absl::StatusOr<VisitResult> ASTAssignmentFromStruct::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAssignmentFromStruct(this);
}

absl::StatusOr<VisitResult> ASTCreateTableStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateTableStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateExternalTableStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateExternalTableStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateViewStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateViewStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateMaterializedViewStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateMaterializedViewStatement(this);
}

absl::StatusOr<VisitResult> ASTWhileStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWhileStatement(this);
}

absl::StatusOr<VisitResult> ASTRepeatStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRepeatStatement(this);
}

absl::StatusOr<VisitResult> ASTForInStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTForInStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterDatabaseStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterDatabaseStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterSchemaStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterSchemaStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterTableStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterTableStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterViewStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterViewStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterMaterializedViewStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterMaterializedViewStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterPrivilegeRestrictionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterPrivilegeRestrictionStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterRowAccessPolicyStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterRowAccessPolicyStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterEntityStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterEntityStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateFunctionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateFunctionStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateTableFunctionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateTableFunctionStatement(this);
}

absl::StatusOr<VisitResult> ASTStructColumnSchema::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStructColumnSchema(this);
}

absl::StatusOr<VisitResult> ASTInferredTypeColumnSchema::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTInferredTypeColumnSchema(this);
}

absl::StatusOr<VisitResult> ASTExecuteIntoClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExecuteIntoClause(this);
}

absl::StatusOr<VisitResult> ASTExecuteUsingArgument::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExecuteUsingArgument(this);
}

absl::StatusOr<VisitResult> ASTExecuteUsingClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExecuteUsingClause(this);
}

absl::StatusOr<VisitResult> ASTExecuteImmediateStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExecuteImmediateStatement(this);
}

absl::StatusOr<VisitResult> ASTAuxLoadDataFromFilesOptionsList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAuxLoadDataFromFilesOptionsList(this);
}

absl::StatusOr<VisitResult> ASTAuxLoadDataStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAuxLoadDataStatement(this);
}

absl::StatusOr<VisitResult> ASTLabel::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTLabel(this);
}

}  // namespace zetasql
