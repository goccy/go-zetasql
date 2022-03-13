#ifndef ZETASQL_PARSER_PARSE_TREE_EXPORT_H
#define ZETASQL_PARSER_PARSE_TREE_EXPORT_H

#include "zetasql/parser/ast_node.h"
#include "zetasql/parser/ast_node_kind.h"
#include "zetasql/parser/parse_tree.h"
#include "zetasql/parser/parse_tree_decls.h"
#include "zetasql/parser/parse_tree_errors.h"
#include "zetasql/parser/parse_tree_generated.h"
#include "zetasql/parser/parse_tree_visitor.h"
#include "zetasql/parser/visit_result.h"

#include "zetasql/parser/parse_tree.cc"
#include "zetasql/parser/parse_tree_errors.cc"

#if 0
ABSL_FLAG(bool, output_asc_explicitly, false,
          "If true, outputs the asc explicitly in "
          "ASTOrderingExpression::SingleNodeDebugString and "
          "Unparser::visitASTOrderingExpression.");


namespace zetasql {

  ASTNode::~ASTNode() {}

  void ASTNode::AddChild(ASTNode* child) {
  }

  void ASTNode::AddChildFront(ASTNode* child) {
  }

  void ASTNode::AddChildren(absl::Span<ASTNode* const> children) {
  }

  absl::Status ASTNode::TraverseNonRecursiveHelper(const VisitResult& result, NonRecursiveParseTreeVisitor* visitor,
                                                   std::vector<std::function<absl::Status()>>* stack) {
    return absl::OkStatus();
  }

  absl::Status ASTNode::TraverseNonRecursive(NonRecursiveParseTreeVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ASTNode::Accept(ParseTreeVisitor* visitor, void* data) const {
  }

  void ASTNode::ChildrenAccept(ParseTreeVisitor* visitor, void* data) const {
  }

  std::string ASTNode::NodeKindToString(ASTNodeKind node_kind) {
    return "";
  }

  std::string ASTNode::GetNodeKindString() const {
    return "";
  }

  std::string ASTNode::SingleNodeDebugString() const {
    return "";
  }

  bool ASTNode::Dumper::DumpNode() {
    return false;
  }

  void ASTNode::Dumper::Dump() {
  }

  std::string ASTNode::DebugString(int max_depth) const {
    return "";
  }

  std::string ASTNode::DebugString(absl::string_view sql, int max_depth) const {
    return "";
  }

  std::string ASTNode::GetLocationString() const {
    return "";
  }

  void ASTNode::GetDescendantsWithKindsImpl(const std::set<int>& node_kinds,
                                            std::vector<const ASTNode*>* found_nodes,
                                            bool continue_traversal) const {
  }

  std::pair<std::string, std::string> ASTSetOperation::GetSQLForOperationPair() const {
    std::pair<std::string, std::string> v;
    return v;
  }

  std::string ASTSetOperation::GetSQLForOperation() const {
    return "";
  }

  std::string ASTSetOperation::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTQuery::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTSelect::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTSelectAs::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTAlias::GetAsString() const {
    return "";
  }

  absl::string_view ASTAlias::GetAsStringView() const {
    absl::string_view v;
    return v;
  }

  std::string ASTIntoAlias::GetAsString() const {
    return "";
  }

  absl::string_view ASTIntoAlias::GetAsStringView() const {
    absl::string_view v;
    return v;
  }

  const ASTNode* ASTTableExpression::alias_location() const {
    return nullptr;
  }

  std::string ASTUnpivotClause::GetSQLForNullFilter() const {
    return "";
  }

  std::string ASTUnpivotClause::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTJoin::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTJoin::GetSQLForJoinType() const {
    return "";
  }

  std::string ASTJoin::GetSQLForJoinHint() const {
    return "";
  }

  std::string ASTNullOrder::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTOrderingExpression::SingleNodeDebugString() const {
    return "";
  }

  absl::Status ASTGeneralizedPathExpression::VerifyIsPureGeneralizedPathExpression(const ASTExpression* path) {
    return absl::OkStatus();
  }

  std::string ASTBinaryExpression::GetSQLForOperator() const {
    return "";
  }

  bool ASTBinaryExpression::IsAllowedInComparison() const {
    return false;
  }

  std::string ASTBinaryExpression::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTBitwiseShiftExpression::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTInExpression::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTLikeExpression::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTAnySomeAllOp::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTAnySomeAllOp::GetSQLForOperator() const {
    return "";
  }

  std::string ASTBetweenExpression::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTUnaryExpression::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTUnaryExpression::GetSQLForOperator() const {
    return "";
  }

  std::string ASTCastExpression::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTDropStatement::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTDropStatement::GetSQLForDropMode(DropMode drop_mode) {
    return "";
  }

  std::string ASTDropEntityStatement::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTDropFunctionStatement::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTDropTableFunctionStatement::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTDropRowAccessPolicyStatement::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTDropSearchIndexStatement::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTDropMaterializedViewStatement::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTDropSnapshotTableStatement::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTPathExpression::ToIdentifierPathString(size_t max_prefix_size) const {
    return "";
  }

  std::vector<std::string> ASTPathExpression::ToIdentifierVector() const {
    std::vector<std::string> v;
    return v;
  }

  std::vector<IdString> ASTPathExpression::ToIdStringVector() const {
    std::vector<IdString> v;
    return v;
  }

  std::string ASTParameterExpr::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTFunctionCall::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTWindowFrame::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTWindowFrame::FrameUnitToString(FrameUnit unit) {
    return "";
  }

  std::string ASTWindowFrame::GetFrameUnitString() const {
    return "";
  }

  std::string ASTWindowFrameExpr::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTWindowFrameExpr::BoundaryTypeToString(BoundaryType type) {
    return "";
  }

  std::string ASTWindowFrameExpr::GetBoundaryTypeString() const {
    return "";
  }

  const ASTFunctionCall* ASTAnalyticFunctionCall::function() const {
    return nullptr;
  }

  const ASTFunctionCallWithGroupRows* ASTAnalyticFunctionCall::function_with_group_rows() const {
    return nullptr;
  }

  std::string ASTExpressionSubquery::ModifierToString(Modifier modifier) {
    return "";
  }

  std::string ASTExpressionSubquery::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTIdentifier::SingleNodeDebugString() const {
    return "";
  }

  bool ASTIntLiteral::is_hex() const {
    return false;
  }

  std::string ASTDateOrTimeLiteral::SingleNodeDebugString() const {
    return "";
  }

  void ASTCreateStatement::CollectModifiers(std::vector<std::string>* modifiers) const {
  }

  std::string ASTCreateStatement::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTFunctionParameter::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTFunctionParameter::ProcedureParameterModeToString(ProcedureParameterMode mode) {
    return "";
  }

  bool ASTFunctionParameter::IsTableParameter() const {
    return false;
  }

  bool ASTFunctionDeclaration::IsTemplated() const {
    return false;
  }

  std::string ASTCreateFunctionStmtBase::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTCreateFunctionStatement::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTCreateFunctionStmtBase::GetSqlForSqlSecurity() const {
    return "";
  }

  std::string ASTCreateFunctionStmtBase::GetSqlForDeterminismLevel() const {
    return "";
  }

  void ASTCreateViewStatementBase::CollectModifiers(std::vector<std::string>* modifiers) const {
  }

  std::string ASTCreateViewStatementBase::GetSqlForSqlSecurity() const {
    return "";
  }

  std::string ASTCreateTableFunctionStatement::SingleNodeDebugString() const {
    return "";
  }

  absl::StatusOr<const ASTPathExpression*>
  ASTDeleteStatement::GetTargetPathForNonNested() const {
    return nullptr;
  }

  absl::StatusOr<const ASTPathExpression*>
  ASTTruncateStatement::GetTargetPathForNonNested() const {
    return nullptr;
  }

  std::string ASTInsertStatement::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTInsertStatement::GetSQLForInsertMode() const {
    return "";
  }

  absl::StatusOr<const ASTPathExpression*>
  ASTInsertStatement::GetTargetPathForNonNested() const {
    return nullptr;
  }

  absl::StatusOr<const ASTPathExpression*>
  ASTUpdateStatement::GetTargetPathForNonNested() const {
    return nullptr;
  }

  std::string ASTMergeAction::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTMergeWhenClause::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTMergeWhenClause::GetSQLForMatchType() const {
    return "";
  }

  std::string ASTSampleSize::GetSQLForUnit() const {
    return "";
  }

  std::string ASTGeneratedColumnInfo::GetSqlForStoredMode() const {
    return "";
  }

  std::string ASTGeneratedColumnInfo::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTNotNullColumnAttribute::SingleNodeSqlString() const {
    return "";
  }

  std::string ASTHiddenColumnAttribute::SingleNodeSqlString() const {
    return "";
  }

  std::string ASTPrimaryKeyColumnAttribute::SingleNodeSqlString() const {
    return "";
  }

  std::string ASTPrimaryKeyColumnAttribute::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTPrimaryKey::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTForeignKeyColumnAttribute::SingleNodeSqlString() const {
    return "";
  }

  bool ASTColumnSchema::ContainsAttribute(ASTNodeKind node_kind) const {
    return false;
  }

  std::string ASTCreateIndexStatement::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTForeignKeyReference::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTForeignKeyReference::GetSQLForMatch() const {
    return "";
  }

  std::string ASTForeignKeyActions::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTForeignKeyActions::GetSQLForAction(Action action) {
    return "";
  }

  std::string ASTCheckConstraint::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTSetCollateClause::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTSetOptionsAction::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTSetAsAction::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTAddConstraintAction::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTAddConstraintAction::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTDropConstraintAction::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTDropConstraintAction::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTDropPrimaryKeyAction::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTDropPrimaryKeyAction::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTAlterConstraintSetOptionsAction::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTAlterConstraintSetOptionsAction::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTAlterConstraintEnforcementAction::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTAlterConstraintEnforcementAction::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTAddColumnAction::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTAddColumnAction::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTColumnPosition::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTAlterColumnOptionsAction::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTAlterColumnOptionsAction::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTAlterColumnTypeAction::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTAlterColumnTypeAction::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTAlterColumnSetDefaultAction::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTAlterColumnSetDefaultAction::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTAlterColumnDropDefaultAction::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTAlterColumnDropDefaultAction::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTAlterColumnDropNotNullAction::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTAlterColumnDropNotNullAction::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTDropColumnAction::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTDropColumnAction::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTRenameColumnAction::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTRenameColumnAction::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTGrantToClause::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTRestrictToClause::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTAddToRestricteeListClause::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTRemoveFromRestricteeListClause::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTFilterFieldsArg::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTLeaf::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTWithClause::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTFilterFieldsArg::GetSQLForOperator() const {
    return "";
  }

  std::string ASTFilterUsingClause::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTRevokeFromClause::SingleNodeDebugString() const {
    return "";
  }

  std::string ASTRevokeFromClause::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTRenameToClause::GetSQLForAlterAction() const {
    return "";
  }

  std::string ASTAlterStatementBase::SingleNodeDebugString() const {
    return "";
  }

  std::ostream& operator<<(std::ostream& out, SchemaObjectKind kind) {
    return out;
  }

  absl::string_view SchemaObjectKindToName(SchemaObjectKind schema_object_kind) {
    absl::string_view v;
    return v;
  }

}

namespace zetasql {

  ParseLocationPoint GetErrorLocationPoint(const ASTNode* ast_node,
                                           bool include_leftmost_child) {
    return {};
  }

  absl::Status StatusWithInternalErrorLocation(const absl::Status& status,
                                               const ASTNode* ast_node,
                                               bool include_leftmost_child) {
    absl::Status v;
    return v;
  }

  absl::Status MakeStatusWithErrorLocation(absl::StatusCode code,
                                           absl::string_view message,
                                           const std::string& filename,
                                           const std::string& query,
                                           const ASTNode* ast_node,
                                           bool include_leftmost_child) {
    absl::Status v;
    return v;
  }

  InternalErrorLocation MakeInternalErrorLocation(const ASTNode* ast_node, absl::string_view filename,
                                                  bool include_leftmost_child) {
    InternalErrorLocation v;
    return v;
  }

  absl::Status WrapNestedErrorStatus(const ASTNode* ast_location,
                                     const std::string& error_message,
                                     const absl::Status& input_status,
                                     ErrorMessageMode error_source_mode) {
    absl::Status v;
    return v;
  }

}

#include "zetasql/parser/parse_tree_accept_methods.inc"
#endif

#include "go-zetasql/parser/ast_enums_cc_proto/export.inc"
#include "go-zetasql/base/arena_allocator/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/utf_util/export.inc"
#include "go-zetasql/proto/internal_error_location_cc_proto/export.inc"
#include "go-zetasql/public/deprecation_warning_cc_proto/export.inc"
#include "go-zetasql/public/error_helpers/export.inc"
#include "go-zetasql/public/error_location_cc_proto/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/parse_resume_location/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/inlined_vector/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"
#include "go-re2/re2/export.inc"
#include "go-icu/icu/export.inc"

#endif
