#ifndef ZETASQL_RESOLVED_AST_RESOLVED_AST_EXPORT_H
#define ZETASQL_RESOLVED_AST_RESOLVED_AST_EXPORT_H

#include "zetasql/resolved_ast/resolved_ast.h"
#include "zetasql/resolved_ast/resolved_ast_deep_copy_visitor.h"
#include "zetasql/resolved_ast/resolved_ast_helper.h"
#include "zetasql/resolved_ast/resolved_ast_visitor.h"
#include "zetasql/resolved_ast/resolved_collation.h"
#include "zetasql/resolved_ast/resolved_column.h"
#include "zetasql/resolved_ast/resolved_node.h"
#include "zetasql/resolved_ast/resolved_node_kind.h"

#include "zetasql/resolved_ast/resolved_ast.cc"
#include "zetasql/resolved_ast/resolved_ast_deep_copy_visitor.cc"
#include "zetasql/resolved_ast/resolved_ast_helper.cc"
#include "zetasql/resolved_ast/resolved_collation.cc"
#include "zetasql/resolved_ast/resolved_column.cc"
#include "zetasql/resolved_ast/resolved_node.cc"

#if 0
namespace zetasql {

  absl::StatusOr<std::unique_ptr<ResolvedNode>> ResolvedNode::RestoreFrom(const AnyResolvedNodeProto& proto, const RestoreParams& params) {
  }

  std::string ResolvedNodeKindToString(ResolvedNodeKind kind) {
  }

  ResolvedArgument::~ResolvedArgument() {
  }

  absl::Status ResolvedArgument::SaveTo(Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        AnyResolvedNodeProto* proto) const {
  }

  absl::Status ResolvedArgument::SaveTo(Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        ResolvedArgumentProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedArgument>> ResolvedArgument::RestoreFrom(const AnyResolvedArgumentProto& proto,
                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedArgument::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedArgument::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  ResolvedExpr::~ResolvedExpr() {
  }

  absl::Status ResolvedExpr::SaveTo(Type::FileDescriptorSetMap* file_descriptor_set_map,
                                    AnyResolvedNodeProto* proto) const {
  }

  absl::Status ResolvedExpr::SaveTo(Type::FileDescriptorSetMap* file_descriptor_set_map,
                                    ResolvedExprProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedExpr>> ResolvedExpr::RestoreFrom(const AnyResolvedExprProto& proto,
                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedExpr::GetChildNodes(std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedExpr::AddMutableChildNodePointers(std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                 mutable_child_node_ptrs) {
  }

  absl::Status ResolvedExpr::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedExpr::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedExpr::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedExpr::CheckFieldsAccessedImpl(const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedExpr::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedExpr::ClearFieldsAccessed() const {
  }

  void ResolvedExpr::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedLiteral::TYPE;

  ResolvedLiteral::~ResolvedLiteral() {
  }

  absl::Status ResolvedLiteral::SaveTo(Type::FileDescriptorSetMap* file_descriptor_set_map,
                                       AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedLiteral::SaveTo(Type::FileDescriptorSetMap* file_descriptor_set_map,
                                       ResolvedLiteralProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedLiteral>> ResolvedLiteral::RestoreFrom(const ResolvedLiteralProto& proto,
                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedLiteral::GetChildNodes(std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedLiteral::AddMutableChildNodePointers(std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                    mutable_child_node_ptrs) {
  }

  absl::Status ResolvedLiteral::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedLiteral::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedLiteral::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedLiteral::CheckFieldsAccessedImpl(const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedLiteral::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedLiteral::ClearFieldsAccessed() const {
  }

  void ResolvedLiteral::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedParameter::TYPE;

  ResolvedParameter::~ResolvedParameter() {
  }

  absl::Status ResolvedParameter::SaveTo(Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedParameter::SaveTo(Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedParameterProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedParameter>> ResolvedParameter::RestoreFrom(const ResolvedParameterProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedParameter::GetChildNodes(std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedParameter::AddMutableChildNodePointers(std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedParameter::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedParameter::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedParameter::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedParameter::CheckFieldsAccessedImpl(const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedParameter::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedParameter::ClearFieldsAccessed() const {
  }

  void ResolvedParameter::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedExpressionColumn::TYPE;

  ResolvedExpressionColumn::~ResolvedExpressionColumn() {
  }

  absl::Status ResolvedExpressionColumn::SaveTo(Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedExpressionColumn::SaveTo(Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedExpressionColumnProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedExpressionColumn>> ResolvedExpressionColumn::RestoreFrom(const ResolvedExpressionColumnProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedExpressionColumn::GetChildNodes(std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedExpressionColumn::AddMutableChildNodePointers(std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                             mutable_child_node_ptrs) {
  }

  absl::Status ResolvedExpressionColumn::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedExpressionColumn::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedExpressionColumn::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedExpressionColumn::CheckFieldsAccessedImpl(const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedExpressionColumn::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedExpressionColumn::ClearFieldsAccessed() const {
  }

  void ResolvedExpressionColumn::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedColumnRef::TYPE;

  ResolvedColumnRef::~ResolvedColumnRef() {
  }

  absl::Status ResolvedColumnRef::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedColumnRef::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedColumnRefProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedColumnRef>> ResolvedColumnRef::RestoreFrom(
                                                                                    const ResolvedColumnRefProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedColumnRef::GetChildNodes(
                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedColumnRef::AddMutableChildNodePointers(
                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedColumnRef::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedColumnRef::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedColumnRef::CollectDebugStringFields(
                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedColumnRef::CheckFieldsAccessedImpl(
                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedColumnRef::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedColumnRef::ClearFieldsAccessed() const {
  }

  void ResolvedColumnRef::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedConstant::TYPE;

  ResolvedConstant::~ResolvedConstant() {
  }

  absl::Status ResolvedConstant::SaveTo(
                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedConstant::SaveTo(
                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        ResolvedConstantProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedConstant>> ResolvedConstant::RestoreFrom(
                                                                                  const ResolvedConstantProto& proto,
                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedConstant::GetChildNodes(
                                       std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedConstant::AddMutableChildNodePointers(
                                                     std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                     mutable_child_node_ptrs) {
  }

  absl::Status ResolvedConstant::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedConstant::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedConstant::CheckFieldsAccessedImpl(
                                                         const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedConstant::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedConstant::ClearFieldsAccessed() const {
  }

  void ResolvedConstant::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedSystemVariable::TYPE;

  ResolvedSystemVariable::~ResolvedSystemVariable() {
  }

  absl::Status ResolvedSystemVariable::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedSystemVariable::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              ResolvedSystemVariableProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedSystemVariable>> ResolvedSystemVariable::RestoreFrom(
                                                                                              const ResolvedSystemVariableProto& proto,
                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedSystemVariable::GetChildNodes(
                                             std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedSystemVariable::AddMutableChildNodePointers(
                                                           std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                           mutable_child_node_ptrs) {
  }

  absl::Status ResolvedSystemVariable::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedSystemVariable::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedSystemVariable::CheckFieldsAccessedImpl(
                                                               const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedSystemVariable::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedSystemVariable::ClearFieldsAccessed() const {
  }

  void ResolvedSystemVariable::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedInlineLambda::TYPE;

  ResolvedInlineLambda::~ResolvedInlineLambda() {
  }

  absl::Status ResolvedInlineLambda::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedInlineLambda::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            ResolvedInlineLambdaProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedInlineLambda>> ResolvedInlineLambda::RestoreFrom(
                                                                                          const ResolvedInlineLambdaProto& proto,
                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedInlineLambda::GetChildNodes(
                                           std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedInlineLambda::AddMutableChildNodePointers(
                                                         std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                         mutable_child_node_ptrs) {
  }

  absl::Status ResolvedInlineLambda::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedInlineLambda::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedInlineLambda::CollectDebugStringFields(
                                                      std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedInlineLambda::CheckFieldsAccessedImpl(
                                                             const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedInlineLambda::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedInlineLambda::ClearFieldsAccessed() const {
  }

  void ResolvedInlineLambda::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedFilterFieldArg::TYPE;

  ResolvedFilterFieldArg::~ResolvedFilterFieldArg() {
  }

  absl::Status ResolvedFilterFieldArg::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedFilterFieldArg::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              ResolvedFilterFieldArgProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedFilterFieldArg>> ResolvedFilterFieldArg::RestoreFrom(
                                                                                              const ResolvedFilterFieldArgProto& proto,
                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedFilterFieldArg::GetChildNodes(
                                             std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedFilterFieldArg::AddMutableChildNodePointers(
                                                           std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                           mutable_child_node_ptrs) {
  }

  absl::Status ResolvedFilterFieldArg::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedFilterFieldArg::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedFilterFieldArg::CollectDebugStringFields(
                                                        std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedFilterFieldArg::CheckFieldsAccessedImpl(
                                                               const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedFilterFieldArg::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedFilterFieldArg::ClearFieldsAccessed() const {
  }

  void ResolvedFilterFieldArg::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedFilterField::TYPE;

  ResolvedFilterField::~ResolvedFilterField() {
  }

  absl::Status ResolvedFilterField::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedFilterField::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           ResolvedFilterFieldProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedFilterField>> ResolvedFilterField::RestoreFrom(
                                                                                        const ResolvedFilterFieldProto& proto,
                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedFilterField::GetChildNodes(
                                          std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedFilterField::AddMutableChildNodePointers(
                                                        std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                        mutable_child_node_ptrs) {
  }

  absl::Status ResolvedFilterField::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedFilterField::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedFilterField::CollectDebugStringFields(
                                                     std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedFilterField::CheckFieldsAccessedImpl(
                                                            const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedFilterField::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedFilterField::ClearFieldsAccessed() const {
  }

  void ResolvedFilterField::MarkFieldsAccessed() const {
  }

  const ResolvedFunctionCallBase::ErrorMode ResolvedFunctionCallBase::DEFAULT_ERROR_MODE;
  const ResolvedFunctionCallBase::ErrorMode ResolvedFunctionCallBase::SAFE_ERROR_MODE;

  ResolvedFunctionCallBase::~ResolvedFunctionCallBase() {
  }

  absl::Status ResolvedFunctionCallBase::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedFunctionCallBase::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedFunctionCallBaseProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedFunctionCallBase>> ResolvedFunctionCallBase::RestoreFrom(
                                                                                                  const AnyResolvedFunctionCallBaseProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedFunctionCallBase::GetChildNodes(
                                               std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedFunctionCallBase::AddMutableChildNodePointers(
                                                             std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                             mutable_child_node_ptrs) {
  }

  absl::Status ResolvedFunctionCallBase::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedFunctionCallBase::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedFunctionCallBase::CheckFieldsAccessedImpl(
                                                                 const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedFunctionCallBase::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedFunctionCallBase::ClearFieldsAccessed() const {
  }

  void ResolvedFunctionCallBase::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedFunctionCall::TYPE;

  ResolvedFunctionCall::~ResolvedFunctionCall() {
  }

  absl::Status ResolvedFunctionCall::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            AnyResolvedFunctionCallBaseProto* proto) const {
  }

  absl::Status ResolvedFunctionCall::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            ResolvedFunctionCallProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedFunctionCall>> ResolvedFunctionCall::RestoreFrom(
                                                                                          const ResolvedFunctionCallProto& proto,
                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedFunctionCall::GetChildNodes(
                                           std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedFunctionCall::AddMutableChildNodePointers(
                                                         std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                         mutable_child_node_ptrs) {
  }

  absl::Status ResolvedFunctionCall::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedFunctionCall::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedFunctionCall::CollectDebugStringFields(
                                                      std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedFunctionCall::CheckFieldsAccessedImpl(
                                                             const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedFunctionCall::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedFunctionCall::ClearFieldsAccessed() const {
  }

  void ResolvedFunctionCall::MarkFieldsAccessed() const {
  }

  const ResolvedNonScalarFunctionCallBase::NullHandlingModifier ResolvedNonScalarFunctionCallBase::DEFAULT_NULL_HANDLING;
  const ResolvedNonScalarFunctionCallBase::NullHandlingModifier ResolvedNonScalarFunctionCallBase::IGNORE_NULLS;
  const ResolvedNonScalarFunctionCallBase::NullHandlingModifier ResolvedNonScalarFunctionCallBase::RESPECT_NULLS;

  ResolvedNonScalarFunctionCallBase::~ResolvedNonScalarFunctionCallBase() {
  }

  absl::Status ResolvedNonScalarFunctionCallBase::SaveTo(
                                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                         AnyResolvedFunctionCallBaseProto* proto) const {
  }

  absl::Status ResolvedNonScalarFunctionCallBase::SaveTo(
                                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                         ResolvedNonScalarFunctionCallBaseProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedNonScalarFunctionCallBase>> ResolvedNonScalarFunctionCallBase::RestoreFrom(
                                                                                                                    const AnyResolvedNonScalarFunctionCallBaseProto& proto,
                                                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedNonScalarFunctionCallBase::GetChildNodes(
                                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedNonScalarFunctionCallBase::AddMutableChildNodePointers(
                                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedNonScalarFunctionCallBase::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedNonScalarFunctionCallBase::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedNonScalarFunctionCallBase::CollectDebugStringFields(
                                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedNonScalarFunctionCallBase::CheckFieldsAccessedImpl(
                                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedNonScalarFunctionCallBase::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedNonScalarFunctionCallBase::ClearFieldsAccessed() const {
  }

  void ResolvedNonScalarFunctionCallBase::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAggregateFunctionCall::TYPE;

  ResolvedAggregateFunctionCall::~ResolvedAggregateFunctionCall() {
  }

  absl::Status ResolvedAggregateFunctionCall::SaveTo(
                                                     Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                     AnyResolvedNonScalarFunctionCallBaseProto* proto) const {
  }

  absl::Status ResolvedAggregateFunctionCall::SaveTo(
                                                     Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                     ResolvedAggregateFunctionCallProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAggregateFunctionCall>> ResolvedAggregateFunctionCall::RestoreFrom(
                                                                                                            const ResolvedAggregateFunctionCallProto& proto,
                                                                                                            const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAggregateFunctionCall::GetChildNodes(
                                                    std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAggregateFunctionCall::AddMutableChildNodePointers(
                                                                  std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                  mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAggregateFunctionCall::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAggregateFunctionCall::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAggregateFunctionCall::CollectDebugStringFields(
                                                               std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAggregateFunctionCall::CheckFieldsAccessedImpl(
                                                                      const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAggregateFunctionCall::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAggregateFunctionCall::ClearFieldsAccessed() const {
  }

  void ResolvedAggregateFunctionCall::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAnalyticFunctionCall::TYPE;

  ResolvedAnalyticFunctionCall::~ResolvedAnalyticFunctionCall() {
  }

  absl::Status ResolvedAnalyticFunctionCall::SaveTo(
                                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                    AnyResolvedNonScalarFunctionCallBaseProto* proto) const {
  }

  absl::Status ResolvedAnalyticFunctionCall::SaveTo(
                                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                    ResolvedAnalyticFunctionCallProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAnalyticFunctionCall>> ResolvedAnalyticFunctionCall::RestoreFrom(
                                                                                                          const ResolvedAnalyticFunctionCallProto& proto,
                                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAnalyticFunctionCall::GetChildNodes(
                                                   std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAnalyticFunctionCall::AddMutableChildNodePointers(
                                                                 std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                 mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAnalyticFunctionCall::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAnalyticFunctionCall::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAnalyticFunctionCall::CollectDebugStringFields(
                                                              std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAnalyticFunctionCall::CheckFieldsAccessedImpl(
                                                                     const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAnalyticFunctionCall::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAnalyticFunctionCall::ClearFieldsAccessed() const {
  }

  void ResolvedAnalyticFunctionCall::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedExtendedCastElement::TYPE;

  ResolvedExtendedCastElement::~ResolvedExtendedCastElement() {
  }

  absl::Status ResolvedExtendedCastElement::SaveTo(
                                                   Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                   AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedExtendedCastElement::SaveTo(
                                                   Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                   ResolvedExtendedCastElementProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedExtendedCastElement>> ResolvedExtendedCastElement::RestoreFrom(
                                                                                                        const ResolvedExtendedCastElementProto& proto,
                                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedExtendedCastElement::GetChildNodes(
                                                  std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedExtendedCastElement::AddMutableChildNodePointers(
                                                                std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                mutable_child_node_ptrs) {
  }

  absl::Status ResolvedExtendedCastElement::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedExtendedCastElement::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedExtendedCastElement::CheckFieldsAccessedImpl(
                                                                    const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedExtendedCastElement::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedExtendedCastElement::ClearFieldsAccessed() const {
  }

  void ResolvedExtendedCastElement::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedExtendedCast::TYPE;

  ResolvedExtendedCast::~ResolvedExtendedCast() {
  }

  absl::Status ResolvedExtendedCast::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedExtendedCast::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            ResolvedExtendedCastProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedExtendedCast>> ResolvedExtendedCast::RestoreFrom(
                                                                                          const ResolvedExtendedCastProto& proto,
                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedExtendedCast::GetChildNodes(
                                           std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedExtendedCast::AddMutableChildNodePointers(
                                                         std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                         mutable_child_node_ptrs) {
  }

  absl::Status ResolvedExtendedCast::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedExtendedCast::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedExtendedCast::CollectDebugStringFields(
                                                      std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedExtendedCast::CheckFieldsAccessedImpl(
                                                             const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedExtendedCast::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedExtendedCast::ClearFieldsAccessed() const {
  }

  void ResolvedExtendedCast::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCast::TYPE;

  ResolvedCast::~ResolvedCast() {
  }

  absl::Status ResolvedCast::SaveTo(
                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                    AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedCast::SaveTo(
                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                    ResolvedCastProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCast>> ResolvedCast::RestoreFrom(
                                                                          const ResolvedCastProto& proto,
                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCast::GetChildNodes(
                                   std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCast::AddMutableChildNodePointers(
                                                 std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                 mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCast::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCast::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCast::CheckFieldsAccessedImpl(
                                                     const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCast::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCast::ClearFieldsAccessed() const {
  }

  void ResolvedCast::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedMakeStruct::TYPE;

  ResolvedMakeStruct::~ResolvedMakeStruct() {
  }

  absl::Status ResolvedMakeStruct::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedMakeStruct::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedMakeStructProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedMakeStruct>> ResolvedMakeStruct::RestoreFrom(
                                                                                      const ResolvedMakeStructProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedMakeStruct::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedMakeStruct::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedMakeStruct::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedMakeStruct::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedMakeStruct::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedMakeStruct::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedMakeStruct::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedMakeStruct::ClearFieldsAccessed() const {
  }

  void ResolvedMakeStruct::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedMakeProto::TYPE;

  ResolvedMakeProto::~ResolvedMakeProto() {
  }

  absl::Status ResolvedMakeProto::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedMakeProto::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedMakeProtoProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedMakeProto>> ResolvedMakeProto::RestoreFrom(
                                                                                    const ResolvedMakeProtoProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedMakeProto::GetChildNodes(
                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedMakeProto::AddMutableChildNodePointers(
                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedMakeProto::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedMakeProto::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedMakeProto::CollectDebugStringFields(
                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedMakeProto::CheckFieldsAccessedImpl(
                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedMakeProto::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedMakeProto::ClearFieldsAccessed() const {
  }

  void ResolvedMakeProto::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedMakeProtoField::TYPE;

  ResolvedMakeProtoField::~ResolvedMakeProtoField() {
  }

  absl::Status ResolvedMakeProtoField::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedMakeProtoField::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              ResolvedMakeProtoFieldProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedMakeProtoField>> ResolvedMakeProtoField::RestoreFrom(
                                                                                              const ResolvedMakeProtoFieldProto& proto,
                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedMakeProtoField::GetChildNodes(
                                             std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedMakeProtoField::AddMutableChildNodePointers(
                                                           std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                           mutable_child_node_ptrs) {
  }

  absl::Status ResolvedMakeProtoField::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedMakeProtoField::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedMakeProtoField::CheckFieldsAccessedImpl(
                                                               const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedMakeProtoField::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedMakeProtoField::ClearFieldsAccessed() const {
  }

  void ResolvedMakeProtoField::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedGetStructField::TYPE;

  ResolvedGetStructField::~ResolvedGetStructField() {
  }

  absl::Status ResolvedGetStructField::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedGetStructField::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              ResolvedGetStructFieldProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedGetStructField>> ResolvedGetStructField::RestoreFrom(
                                                                                              const ResolvedGetStructFieldProto& proto,
                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedGetStructField::GetChildNodes(
                                             std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedGetStructField::AddMutableChildNodePointers(
                                                           std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                           mutable_child_node_ptrs) {
  }

  absl::Status ResolvedGetStructField::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedGetStructField::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedGetStructField::CollectDebugStringFields(
                                                        std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedGetStructField::CheckFieldsAccessedImpl(
                                                               const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedGetStructField::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedGetStructField::ClearFieldsAccessed() const {
  }

  void ResolvedGetStructField::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedGetProtoField::TYPE;

  ResolvedGetProtoField::~ResolvedGetProtoField() {
  }

  absl::Status ResolvedGetProtoField::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedGetProtoField::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             ResolvedGetProtoFieldProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedGetProtoField>> ResolvedGetProtoField::RestoreFrom(
                                                                                            const ResolvedGetProtoFieldProto& proto,
                                                                                            const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedGetProtoField::GetChildNodes(
                                            std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedGetProtoField::AddMutableChildNodePointers(
                                                          std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                          mutable_child_node_ptrs) {
  }

  absl::Status ResolvedGetProtoField::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedGetProtoField::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedGetProtoField::CollectDebugStringFields(
                                                       std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedGetProtoField::CheckFieldsAccessedImpl(
                                                              const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedGetProtoField::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedGetProtoField::ClearFieldsAccessed() const {
  }

  void ResolvedGetProtoField::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedGetJsonField::TYPE;

  ResolvedGetJsonField::~ResolvedGetJsonField() {
  }

  absl::Status ResolvedGetJsonField::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedGetJsonField::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            ResolvedGetJsonFieldProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedGetJsonField>> ResolvedGetJsonField::RestoreFrom(
                                                                                          const ResolvedGetJsonFieldProto& proto,
                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedGetJsonField::GetChildNodes(
                                           std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedGetJsonField::AddMutableChildNodePointers(
                                                         std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                         mutable_child_node_ptrs) {
  }

  absl::Status ResolvedGetJsonField::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedGetJsonField::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedGetJsonField::CollectDebugStringFields(
                                                      std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedGetJsonField::CheckFieldsAccessedImpl(
                                                             const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedGetJsonField::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedGetJsonField::ClearFieldsAccessed() const {
  }

  void ResolvedGetJsonField::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedFlatten::TYPE;

  ResolvedFlatten::~ResolvedFlatten() {
  }

  absl::Status ResolvedFlatten::SaveTo(
                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                       AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedFlatten::SaveTo(
                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                       ResolvedFlattenProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedFlatten>> ResolvedFlatten::RestoreFrom(
                                                                                const ResolvedFlattenProto& proto,
                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedFlatten::GetChildNodes(
                                      std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedFlatten::AddMutableChildNodePointers(
                                                    std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                    mutable_child_node_ptrs) {
  }

  absl::Status ResolvedFlatten::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedFlatten::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedFlatten::CollectDebugStringFields(
                                                 std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedFlatten::CheckFieldsAccessedImpl(
                                                        const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedFlatten::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedFlatten::ClearFieldsAccessed() const {
  }

  void ResolvedFlatten::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedFlattenedArg::TYPE;

  ResolvedFlattenedArg::~ResolvedFlattenedArg() {
  }

  absl::Status ResolvedFlattenedArg::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedFlattenedArg::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            ResolvedFlattenedArgProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedFlattenedArg>> ResolvedFlattenedArg::RestoreFrom(
                                                                                          const ResolvedFlattenedArgProto& proto,
                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedFlattenedArg::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedFlattenedArg::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedReplaceFieldItem::TYPE;

  ResolvedReplaceFieldItem::~ResolvedReplaceFieldItem() {
  }

  absl::Status ResolvedReplaceFieldItem::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedReplaceFieldItem::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedReplaceFieldItemProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedReplaceFieldItem>> ResolvedReplaceFieldItem::RestoreFrom(
                                                                                                  const ResolvedReplaceFieldItemProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedReplaceFieldItem::GetChildNodes(
                                               std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedReplaceFieldItem::AddMutableChildNodePointers(
                                                             std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                             mutable_child_node_ptrs) {
  }

  absl::Status ResolvedReplaceFieldItem::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedReplaceFieldItem::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedReplaceFieldItem::CollectDebugStringFields(
                                                          std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedReplaceFieldItem::CheckFieldsAccessedImpl(
                                                                 const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedReplaceFieldItem::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedReplaceFieldItem::ClearFieldsAccessed() const {
  }

  void ResolvedReplaceFieldItem::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedReplaceField::TYPE;

  ResolvedReplaceField::~ResolvedReplaceField() {
  }

  absl::Status ResolvedReplaceField::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedReplaceField::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            ResolvedReplaceFieldProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedReplaceField>> ResolvedReplaceField::RestoreFrom(
                                                                                          const ResolvedReplaceFieldProto& proto,
                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedReplaceField::GetChildNodes(
                                           std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedReplaceField::AddMutableChildNodePointers(
                                                         std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                         mutable_child_node_ptrs) {
  }

  absl::Status ResolvedReplaceField::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedReplaceField::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedReplaceField::CollectDebugStringFields(
                                                      std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedReplaceField::CheckFieldsAccessedImpl(
                                                             const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedReplaceField::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedReplaceField::ClearFieldsAccessed() const {
  }

  void ResolvedReplaceField::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedSubqueryExpr::TYPE;

  const ResolvedSubqueryExpr::SubqueryType ResolvedSubqueryExpr::SCALAR;
  const ResolvedSubqueryExpr::SubqueryType ResolvedSubqueryExpr::ARRAY;
  const ResolvedSubqueryExpr::SubqueryType ResolvedSubqueryExpr::EXISTS;
  const ResolvedSubqueryExpr::SubqueryType ResolvedSubqueryExpr::IN;
  const ResolvedSubqueryExpr::SubqueryType ResolvedSubqueryExpr::LIKE_ANY;
  const ResolvedSubqueryExpr::SubqueryType ResolvedSubqueryExpr::LIKE_ALL;

  ResolvedSubqueryExpr::~ResolvedSubqueryExpr() {
  }

  absl::Status ResolvedSubqueryExpr::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedSubqueryExpr::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            ResolvedSubqueryExprProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedSubqueryExpr>> ResolvedSubqueryExpr::RestoreFrom(
                                                                                          const ResolvedSubqueryExprProto& proto,
                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedSubqueryExpr::GetChildNodes(
                                           std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedSubqueryExpr::AddMutableChildNodePointers(
                                                         std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                         mutable_child_node_ptrs) {
  }

  absl::Status ResolvedSubqueryExpr::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedSubqueryExpr::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedSubqueryExpr::CollectDebugStringFields(
                                                      std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedSubqueryExpr::CheckFieldsAccessedImpl(
                                                             const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedSubqueryExpr::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedSubqueryExpr::ClearFieldsAccessed() const {
  }

  void ResolvedSubqueryExpr::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedLetExpr::TYPE;

  ResolvedLetExpr::~ResolvedLetExpr() {
  }

  absl::Status ResolvedLetExpr::SaveTo(
                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                       AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedLetExpr::SaveTo(
                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                       ResolvedLetExprProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedLetExpr>> ResolvedLetExpr::RestoreFrom(
                                                                                const ResolvedLetExprProto& proto,
                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedLetExpr::GetChildNodes(
                                      std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedLetExpr::AddMutableChildNodePointers(
                                                    std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                    mutable_child_node_ptrs) {
  }

  absl::Status ResolvedLetExpr::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedLetExpr::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedLetExpr::CollectDebugStringFields(
                                                 std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedLetExpr::CheckFieldsAccessedImpl(
                                                        const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedLetExpr::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedLetExpr::ClearFieldsAccessed() const {
  }

  void ResolvedLetExpr::MarkFieldsAccessed() const {
  }

  ResolvedScan::~ResolvedScan() {
  }

  absl::Status ResolvedScan::SaveTo(
                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                    AnyResolvedNodeProto* proto) const {
  }

  absl::Status ResolvedScan::SaveTo(
                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                    ResolvedScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedScan>> ResolvedScan::RestoreFrom(
                                                                          const AnyResolvedScanProto& proto,
                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedScan::GetChildNodes(
                                   std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedScan::AddMutableChildNodePointers(
                                                 std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                 mutable_child_node_ptrs) {
  }

  absl::Status ResolvedScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedScan::CollectDebugStringFields(
                                              std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedScan::CheckFieldsAccessedImpl(
                                                     const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedScan::ClearFieldsAccessed() const {
  }

  void ResolvedScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedModel::TYPE;

  ResolvedModel::~ResolvedModel() {
  }

  absl::Status ResolvedModel::SaveTo(
                                     Type::FileDescriptorSetMap* file_descriptor_set_map,
                                     AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedModel::SaveTo(
                                     Type::FileDescriptorSetMap* file_descriptor_set_map,
                                     ResolvedModelProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedModel>> ResolvedModel::RestoreFrom(
                                                                            const ResolvedModelProto& proto,
                                                                            const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedModel::GetChildNodes(
                                    std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedModel::AddMutableChildNodePointers(
                                                  std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                  mutable_child_node_ptrs) {
  }

  absl::Status ResolvedModel::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedModel::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedModel::CollectDebugStringFields(
                                               std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedModel::CheckFieldsAccessedImpl(
                                                      const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedModel::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedModel::ClearFieldsAccessed() const {
  }

  void ResolvedModel::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedConnection::TYPE;

  ResolvedConnection::~ResolvedConnection() {
  }

  absl::Status ResolvedConnection::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedConnection::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedConnectionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedConnection>> ResolvedConnection::RestoreFrom(
                                                                                      const ResolvedConnectionProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedConnection::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedConnection::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedConnection::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedConnection::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedConnection::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedConnection::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedConnection::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedConnection::ClearFieldsAccessed() const {
  }

  void ResolvedConnection::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedDescriptor::TYPE;

  ResolvedDescriptor::~ResolvedDescriptor() {
  }

  absl::Status ResolvedDescriptor::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedDescriptor::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedDescriptorProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDescriptor>> ResolvedDescriptor::RestoreFrom(
                                                                                      const ResolvedDescriptorProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDescriptor::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDescriptor::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDescriptor::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDescriptor::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDescriptor::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDescriptor::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDescriptor::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDescriptor::ClearFieldsAccessed() const {
  }

  void ResolvedDescriptor::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedSingleRowScan::TYPE;

  ResolvedSingleRowScan::~ResolvedSingleRowScan() {
  }

  absl::Status ResolvedSingleRowScan::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedSingleRowScan::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             ResolvedSingleRowScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedSingleRowScan>> ResolvedSingleRowScan::RestoreFrom(
                                                                                            const ResolvedSingleRowScanProto& proto,
                                                                                            const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedSingleRowScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedSingleRowScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedTableScan::TYPE;

  ResolvedTableScan::~ResolvedTableScan() {
  }

  absl::Status ResolvedTableScan::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedTableScan::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedTableScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedTableScan>> ResolvedTableScan::RestoreFrom(
                                                                                    const ResolvedTableScanProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedTableScan::GetChildNodes(
                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedTableScan::AddMutableChildNodePointers(
                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedTableScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedTableScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedTableScan::CollectDebugStringFields(
                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedTableScan::CheckFieldsAccessedImpl(
                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedTableScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedTableScan::ClearFieldsAccessed() const {
  }

  void ResolvedTableScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedJoinScan::TYPE;

  const ResolvedJoinScan::JoinType ResolvedJoinScan::INNER;
  const ResolvedJoinScan::JoinType ResolvedJoinScan::LEFT;
  const ResolvedJoinScan::JoinType ResolvedJoinScan::RIGHT;
  const ResolvedJoinScan::JoinType ResolvedJoinScan::FULL;

  ResolvedJoinScan::~ResolvedJoinScan() {
  }

  absl::Status ResolvedJoinScan::SaveTo(
                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedJoinScan::SaveTo(
                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        ResolvedJoinScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedJoinScan>> ResolvedJoinScan::RestoreFrom(
                                                                                  const ResolvedJoinScanProto& proto,
                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedJoinScan::GetChildNodes(
                                       std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedJoinScan::AddMutableChildNodePointers(
                                                     std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                     mutable_child_node_ptrs) {
  }

  absl::Status ResolvedJoinScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedJoinScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedJoinScan::CollectDebugStringFields(
                                                  std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedJoinScan::CheckFieldsAccessedImpl(
                                                         const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedJoinScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedJoinScan::ClearFieldsAccessed() const {
  }

  void ResolvedJoinScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedArrayScan::TYPE;

  ResolvedArrayScan::~ResolvedArrayScan() {
  }

  absl::Status ResolvedArrayScan::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedArrayScan::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedArrayScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedArrayScan>> ResolvedArrayScan::RestoreFrom(
                                                                                    const ResolvedArrayScanProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedArrayScan::GetChildNodes(
                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedArrayScan::AddMutableChildNodePointers(
                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedArrayScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedArrayScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedArrayScan::CollectDebugStringFields(
                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedArrayScan::CheckFieldsAccessedImpl(
                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedArrayScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedArrayScan::ClearFieldsAccessed() const {
  }

  void ResolvedArrayScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedColumnHolder::TYPE;

  ResolvedColumnHolder::~ResolvedColumnHolder() {
  }

  absl::Status ResolvedColumnHolder::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedColumnHolder::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            ResolvedColumnHolderProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedColumnHolder>> ResolvedColumnHolder::RestoreFrom(
                                                                                          const ResolvedColumnHolderProto& proto,
                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedColumnHolder::GetChildNodes(
                                           std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedColumnHolder::AddMutableChildNodePointers(
                                                         std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                         mutable_child_node_ptrs) {
  }

  absl::Status ResolvedColumnHolder::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedColumnHolder::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedColumnHolder::CollectDebugStringFields(
                                                      std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedColumnHolder::CheckFieldsAccessedImpl(
                                                             const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedColumnHolder::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedColumnHolder::ClearFieldsAccessed() const {
  }

  void ResolvedColumnHolder::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedFilterScan::TYPE;

  ResolvedFilterScan::~ResolvedFilterScan() {
  }

  absl::Status ResolvedFilterScan::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedFilterScan::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedFilterScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedFilterScan>> ResolvedFilterScan::RestoreFrom(
                                                                                      const ResolvedFilterScanProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedFilterScan::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedFilterScan::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedFilterScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedFilterScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedFilterScan::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedFilterScan::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedFilterScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedFilterScan::ClearFieldsAccessed() const {
  }

  void ResolvedFilterScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedGroupingSet::TYPE;

  ResolvedGroupingSet::~ResolvedGroupingSet() {
  }

  absl::Status ResolvedGroupingSet::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedGroupingSet::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           ResolvedGroupingSetProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedGroupingSet>> ResolvedGroupingSet::RestoreFrom(
                                                                                        const ResolvedGroupingSetProto& proto,
                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedGroupingSet::GetChildNodes(
                                          std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedGroupingSet::AddMutableChildNodePointers(
                                                        std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                        mutable_child_node_ptrs) {
  }

  absl::Status ResolvedGroupingSet::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedGroupingSet::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedGroupingSet::CollectDebugStringFields(
                                                     std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedGroupingSet::CheckFieldsAccessedImpl(
                                                            const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedGroupingSet::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedGroupingSet::ClearFieldsAccessed() const {
  }

  void ResolvedGroupingSet::MarkFieldsAccessed() const {
  }

  ResolvedAggregateScanBase::~ResolvedAggregateScanBase() {
  }

  absl::Status ResolvedAggregateScanBase::SaveTo(
                                                 Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                 AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedAggregateScanBase::SaveTo(
                                                 Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                 ResolvedAggregateScanBaseProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAggregateScanBase>> ResolvedAggregateScanBase::RestoreFrom(
                                                                                                    const AnyResolvedAggregateScanBaseProto& proto,
                                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAggregateScanBase::GetChildNodes(
                                                std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAggregateScanBase::AddMutableChildNodePointers(
                                                              std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                              mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAggregateScanBase::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAggregateScanBase::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAggregateScanBase::CollectDebugStringFields(
                                                           std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAggregateScanBase::CheckFieldsAccessedImpl(
                                                                  const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAggregateScanBase::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAggregateScanBase::ClearFieldsAccessed() const {
  }

  void ResolvedAggregateScanBase::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAggregateScan::TYPE;

  ResolvedAggregateScan::~ResolvedAggregateScan() {
  }

  absl::Status ResolvedAggregateScan::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             AnyResolvedAggregateScanBaseProto* proto) const {
  }

  absl::Status ResolvedAggregateScan::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             ResolvedAggregateScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAggregateScan>> ResolvedAggregateScan::RestoreFrom(
                                                                                            const ResolvedAggregateScanProto& proto,
                                                                                            const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAggregateScan::GetChildNodes(
                                            std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAggregateScan::AddMutableChildNodePointers(
                                                          std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                          mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAggregateScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAggregateScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAggregateScan::CollectDebugStringFields(
                                                       std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAggregateScan::CheckFieldsAccessedImpl(
                                                              const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAggregateScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAggregateScan::ClearFieldsAccessed() const {
  }

  void ResolvedAggregateScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAnonymizedAggregateScan::TYPE;

  ResolvedAnonymizedAggregateScan::~ResolvedAnonymizedAggregateScan() {
  }

  absl::Status ResolvedAnonymizedAggregateScan::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       AnyResolvedAggregateScanBaseProto* proto) const {
  }

  absl::Status ResolvedAnonymizedAggregateScan::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       ResolvedAnonymizedAggregateScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAnonymizedAggregateScan>> ResolvedAnonymizedAggregateScan::RestoreFrom(
                                                                                                                const ResolvedAnonymizedAggregateScanProto& proto,
                                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAnonymizedAggregateScan::GetChildNodes(
                                                      std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAnonymizedAggregateScan::AddMutableChildNodePointers(
                                                                    std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                    mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAnonymizedAggregateScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAnonymizedAggregateScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAnonymizedAggregateScan::CollectDebugStringFields(
                                                                 std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAnonymizedAggregateScan::CheckFieldsAccessedImpl(
                                                                        const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAnonymizedAggregateScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAnonymizedAggregateScan::ClearFieldsAccessed() const {
  }

  void ResolvedAnonymizedAggregateScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedSetOperationItem::TYPE;

  ResolvedSetOperationItem::~ResolvedSetOperationItem() {
  }

  absl::Status ResolvedSetOperationItem::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedSetOperationItem::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedSetOperationItemProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedSetOperationItem>> ResolvedSetOperationItem::RestoreFrom(
                                                                                                  const ResolvedSetOperationItemProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedSetOperationItem::GetChildNodes(
                                               std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedSetOperationItem::AddMutableChildNodePointers(
                                                             std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                             mutable_child_node_ptrs) {
  }

  absl::Status ResolvedSetOperationItem::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedSetOperationItem::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedSetOperationItem::CollectDebugStringFields(
                                                          std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedSetOperationItem::CheckFieldsAccessedImpl(
                                                                 const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedSetOperationItem::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedSetOperationItem::ClearFieldsAccessed() const {
  }

  void ResolvedSetOperationItem::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedSetOperationScan::TYPE;

  const ResolvedSetOperationScan::SetOperationType ResolvedSetOperationScan::UNION_ALL;
  const ResolvedSetOperationScan::SetOperationType ResolvedSetOperationScan::UNION_DISTINCT;
  const ResolvedSetOperationScan::SetOperationType ResolvedSetOperationScan::INTERSECT_ALL;
  const ResolvedSetOperationScan::SetOperationType ResolvedSetOperationScan::INTERSECT_DISTINCT;
  const ResolvedSetOperationScan::SetOperationType ResolvedSetOperationScan::EXCEPT_ALL;
  const ResolvedSetOperationScan::SetOperationType ResolvedSetOperationScan::EXCEPT_DISTINCT;

  ResolvedSetOperationScan::~ResolvedSetOperationScan() {
  }

  absl::Status ResolvedSetOperationScan::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedSetOperationScan::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedSetOperationScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedSetOperationScan>> ResolvedSetOperationScan::RestoreFrom(
                                                                                                  const ResolvedSetOperationScanProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedSetOperationScan::GetChildNodes(
                                               std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedSetOperationScan::AddMutableChildNodePointers(
                                                             std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                             mutable_child_node_ptrs) {
  }

  absl::Status ResolvedSetOperationScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedSetOperationScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedSetOperationScan::CollectDebugStringFields(
                                                          std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedSetOperationScan::CheckFieldsAccessedImpl(
                                                                 const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedSetOperationScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedSetOperationScan::ClearFieldsAccessed() const {
  }

  void ResolvedSetOperationScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedOrderByScan::TYPE;

  ResolvedOrderByScan::~ResolvedOrderByScan() {
  }

  absl::Status ResolvedOrderByScan::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedOrderByScan::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           ResolvedOrderByScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedOrderByScan>> ResolvedOrderByScan::RestoreFrom(
                                                                                        const ResolvedOrderByScanProto& proto,
                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedOrderByScan::GetChildNodes(
                                          std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedOrderByScan::AddMutableChildNodePointers(
                                                        std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                        mutable_child_node_ptrs) {
  }

  absl::Status ResolvedOrderByScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedOrderByScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedOrderByScan::CollectDebugStringFields(
                                                     std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedOrderByScan::CheckFieldsAccessedImpl(
                                                            const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedOrderByScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedOrderByScan::ClearFieldsAccessed() const {
  }

  void ResolvedOrderByScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedLimitOffsetScan::TYPE;

  ResolvedLimitOffsetScan::~ResolvedLimitOffsetScan() {
  }

  absl::Status ResolvedLimitOffsetScan::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedLimitOffsetScan::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedLimitOffsetScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedLimitOffsetScan>> ResolvedLimitOffsetScan::RestoreFrom(
                                                                                                const ResolvedLimitOffsetScanProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedLimitOffsetScan::GetChildNodes(
                                              std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedLimitOffsetScan::AddMutableChildNodePointers(
                                                            std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                            mutable_child_node_ptrs) {
  }

  absl::Status ResolvedLimitOffsetScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedLimitOffsetScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedLimitOffsetScan::CollectDebugStringFields(
                                                         std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedLimitOffsetScan::CheckFieldsAccessedImpl(
                                                                const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedLimitOffsetScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedLimitOffsetScan::ClearFieldsAccessed() const {
  }

  void ResolvedLimitOffsetScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedWithRefScan::TYPE;

  ResolvedWithRefScan::~ResolvedWithRefScan() {
  }

  absl::Status ResolvedWithRefScan::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedWithRefScan::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           ResolvedWithRefScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedWithRefScan>> ResolvedWithRefScan::RestoreFrom(
                                                                                        const ResolvedWithRefScanProto& proto,
                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedWithRefScan::GetChildNodes(
                                          std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedWithRefScan::AddMutableChildNodePointers(
                                                        std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                        mutable_child_node_ptrs) {
  }

  absl::Status ResolvedWithRefScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedWithRefScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedWithRefScan::CollectDebugStringFields(
                                                     std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedWithRefScan::CheckFieldsAccessedImpl(
                                                            const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedWithRefScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedWithRefScan::ClearFieldsAccessed() const {
  }

  void ResolvedWithRefScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAnalyticScan::TYPE;

  ResolvedAnalyticScan::~ResolvedAnalyticScan() {
  }

  absl::Status ResolvedAnalyticScan::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedAnalyticScan::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            ResolvedAnalyticScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAnalyticScan>> ResolvedAnalyticScan::RestoreFrom(
                                                                                          const ResolvedAnalyticScanProto& proto,
                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAnalyticScan::GetChildNodes(
                                           std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAnalyticScan::AddMutableChildNodePointers(
                                                         std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                         mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAnalyticScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAnalyticScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAnalyticScan::CollectDebugStringFields(
                                                      std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAnalyticScan::CheckFieldsAccessedImpl(
                                                             const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAnalyticScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAnalyticScan::ClearFieldsAccessed() const {
  }

  void ResolvedAnalyticScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedSampleScan::TYPE;

  const ResolvedSampleScan::SampleUnit ResolvedSampleScan::ROWS;
  const ResolvedSampleScan::SampleUnit ResolvedSampleScan::PERCENT;

  ResolvedSampleScan::~ResolvedSampleScan() {
  }

  absl::Status ResolvedSampleScan::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedSampleScan::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedSampleScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedSampleScan>> ResolvedSampleScan::RestoreFrom(
                                                                                      const ResolvedSampleScanProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedSampleScan::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedSampleScan::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedSampleScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedSampleScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedSampleScan::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedSampleScan::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedSampleScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedSampleScan::ClearFieldsAccessed() const {
  }

  void ResolvedSampleScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedComputedColumn::TYPE;

  ResolvedComputedColumn::~ResolvedComputedColumn() {
  }

  absl::Status ResolvedComputedColumn::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedComputedColumn::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              ResolvedComputedColumnProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedComputedColumn>> ResolvedComputedColumn::RestoreFrom(
                                                                                              const ResolvedComputedColumnProto& proto,
                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedComputedColumn::GetChildNodes(
                                             std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedComputedColumn::AddMutableChildNodePointers(
                                                           std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                           mutable_child_node_ptrs) {
  }

  absl::Status ResolvedComputedColumn::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedComputedColumn::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedComputedColumn::CheckFieldsAccessedImpl(
                                                               const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedComputedColumn::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedComputedColumn::ClearFieldsAccessed() const {
  }

  void ResolvedComputedColumn::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedOrderByItem::TYPE;

  const ResolvedOrderByItem::NullOrderMode ResolvedOrderByItem::ORDER_UNSPECIFIED;
  const ResolvedOrderByItem::NullOrderMode ResolvedOrderByItem::NULLS_FIRST;
  const ResolvedOrderByItem::NullOrderMode ResolvedOrderByItem::NULLS_LAST;

  ResolvedOrderByItem::~ResolvedOrderByItem() {
  }

  absl::Status ResolvedOrderByItem::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedOrderByItem::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           ResolvedOrderByItemProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedOrderByItem>> ResolvedOrderByItem::RestoreFrom(
                                                                                        const ResolvedOrderByItemProto& proto,
                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedOrderByItem::GetChildNodes(
                                          std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedOrderByItem::AddMutableChildNodePointers(
                                                        std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                        mutable_child_node_ptrs) {
  }

  absl::Status ResolvedOrderByItem::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedOrderByItem::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedOrderByItem::CollectDebugStringFields(
                                                     std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedOrderByItem::CheckFieldsAccessedImpl(
                                                            const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedOrderByItem::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedOrderByItem::ClearFieldsAccessed() const {
  }

  void ResolvedOrderByItem::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedColumnAnnotations::TYPE;

  ResolvedColumnAnnotations::~ResolvedColumnAnnotations() {
  }

  absl::Status ResolvedColumnAnnotations::SaveTo(
                                                 Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                 AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedColumnAnnotations::SaveTo(
                                                 Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                 ResolvedColumnAnnotationsProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedColumnAnnotations>> ResolvedColumnAnnotations::RestoreFrom(
                                                                                                    const ResolvedColumnAnnotationsProto& proto,
                                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedColumnAnnotations::GetChildNodes(
                                                std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedColumnAnnotations::AddMutableChildNodePointers(
                                                              std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                              mutable_child_node_ptrs) {
  }

  absl::Status ResolvedColumnAnnotations::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedColumnAnnotations::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedColumnAnnotations::CollectDebugStringFields(
                                                           std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedColumnAnnotations::CheckFieldsAccessedImpl(
                                                                  const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedColumnAnnotations::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedColumnAnnotations::ClearFieldsAccessed() const {
  }

  void ResolvedColumnAnnotations::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedGeneratedColumnInfo::TYPE;

  const ResolvedGeneratedColumnInfo::StoredMode ResolvedGeneratedColumnInfo::NON_STORED;
  const ResolvedGeneratedColumnInfo::StoredMode ResolvedGeneratedColumnInfo::STORED;
  const ResolvedGeneratedColumnInfo::StoredMode ResolvedGeneratedColumnInfo::STORED_VOLATILE;

  ResolvedGeneratedColumnInfo::~ResolvedGeneratedColumnInfo() {
  }

  absl::Status ResolvedGeneratedColumnInfo::SaveTo(
                                                   Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                   AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedGeneratedColumnInfo::SaveTo(
                                                   Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                   ResolvedGeneratedColumnInfoProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedGeneratedColumnInfo>> ResolvedGeneratedColumnInfo::RestoreFrom(
                                                                                                        const ResolvedGeneratedColumnInfoProto& proto,
                                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedGeneratedColumnInfo::GetChildNodes(
                                                  std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedGeneratedColumnInfo::AddMutableChildNodePointers(
                                                                std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                mutable_child_node_ptrs) {
  }

  absl::Status ResolvedGeneratedColumnInfo::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedGeneratedColumnInfo::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedGeneratedColumnInfo::CollectDebugStringFields(
                                                             std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedGeneratedColumnInfo::CheckFieldsAccessedImpl(
                                                                    const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedGeneratedColumnInfo::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedGeneratedColumnInfo::ClearFieldsAccessed() const {
  }

  void ResolvedGeneratedColumnInfo::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedColumnDefaultValue::TYPE;

  ResolvedColumnDefaultValue::~ResolvedColumnDefaultValue() {
  }

  absl::Status ResolvedColumnDefaultValue::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedColumnDefaultValue::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  ResolvedColumnDefaultValueProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedColumnDefaultValue>> ResolvedColumnDefaultValue::RestoreFrom(
                                                                                                      const ResolvedColumnDefaultValueProto& proto,
                                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedColumnDefaultValue::GetChildNodes(
                                                 std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedColumnDefaultValue::AddMutableChildNodePointers(
                                                               std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                               mutable_child_node_ptrs) {
  }

  absl::Status ResolvedColumnDefaultValue::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedColumnDefaultValue::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedColumnDefaultValue::CollectDebugStringFields(
                                                            std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedColumnDefaultValue::CheckFieldsAccessedImpl(
                                                                   const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedColumnDefaultValue::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedColumnDefaultValue::ClearFieldsAccessed() const {
  }

  void ResolvedColumnDefaultValue::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedColumnDefinition::TYPE;

  ResolvedColumnDefinition::~ResolvedColumnDefinition() {
  }

  absl::Status ResolvedColumnDefinition::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedColumnDefinition::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedColumnDefinitionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedColumnDefinition>> ResolvedColumnDefinition::RestoreFrom(
                                                                                                  const ResolvedColumnDefinitionProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedColumnDefinition::GetChildNodes(
                                               std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedColumnDefinition::AddMutableChildNodePointers(
                                                             std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                             mutable_child_node_ptrs) {
  }

  absl::Status ResolvedColumnDefinition::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedColumnDefinition::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedColumnDefinition::CollectDebugStringFields(
                                                          std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedColumnDefinition::CheckFieldsAccessedImpl(
                                                                 const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedColumnDefinition::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedColumnDefinition::ClearFieldsAccessed() const {
  }

  void ResolvedColumnDefinition::MarkFieldsAccessed() const {
  }

  ResolvedConstraint::~ResolvedConstraint() {
  }

  absl::Status ResolvedConstraint::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedConstraint::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedConstraintProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedConstraint>> ResolvedConstraint::RestoreFrom(
                                                                                      const AnyResolvedConstraintProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedConstraint::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedConstraint::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedPrimaryKey::TYPE;

  ResolvedPrimaryKey::~ResolvedPrimaryKey() {
  }

  absl::Status ResolvedPrimaryKey::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedConstraintProto* proto) const {
  }

  absl::Status ResolvedPrimaryKey::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedPrimaryKeyProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedPrimaryKey>> ResolvedPrimaryKey::RestoreFrom(
                                                                                      const ResolvedPrimaryKeyProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedPrimaryKey::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedPrimaryKey::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedPrimaryKey::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedPrimaryKey::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedPrimaryKey::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedPrimaryKey::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedPrimaryKey::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedPrimaryKey::ClearFieldsAccessed() const {
  }

  void ResolvedPrimaryKey::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedForeignKey::TYPE;

  const ResolvedForeignKey::MatchMode ResolvedForeignKey::SIMPLE;
  const ResolvedForeignKey::MatchMode ResolvedForeignKey::FULL;
  const ResolvedForeignKey::MatchMode ResolvedForeignKey::NOT_DISTINCT;
  const ResolvedForeignKey::ActionOperation ResolvedForeignKey::NO_ACTION;
  const ResolvedForeignKey::ActionOperation ResolvedForeignKey::RESTRICT;
  const ResolvedForeignKey::ActionOperation ResolvedForeignKey::CASCADE;
  const ResolvedForeignKey::ActionOperation ResolvedForeignKey::SET_NULL;

  ResolvedForeignKey::~ResolvedForeignKey() {
  }

  absl::Status ResolvedForeignKey::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedConstraintProto* proto) const {
  }

  absl::Status ResolvedForeignKey::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedForeignKeyProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedForeignKey>> ResolvedForeignKey::RestoreFrom(
                                                                                      const ResolvedForeignKeyProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedForeignKey::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedForeignKey::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedForeignKey::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedForeignKey::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedForeignKey::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedForeignKey::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedForeignKey::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedForeignKey::ClearFieldsAccessed() const {
  }

  void ResolvedForeignKey::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCheckConstraint::TYPE;

  ResolvedCheckConstraint::~ResolvedCheckConstraint() {
  }

  absl::Status ResolvedCheckConstraint::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedConstraintProto* proto) const {
  }

  absl::Status ResolvedCheckConstraint::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedCheckConstraintProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCheckConstraint>> ResolvedCheckConstraint::RestoreFrom(
                                                                                                const ResolvedCheckConstraintProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCheckConstraint::GetChildNodes(
                                              std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCheckConstraint::AddMutableChildNodePointers(
                                                            std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                            mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCheckConstraint::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCheckConstraint::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCheckConstraint::CollectDebugStringFields(
                                                         std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCheckConstraint::CheckFieldsAccessedImpl(
                                                                const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCheckConstraint::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCheckConstraint::ClearFieldsAccessed() const {
  }

  void ResolvedCheckConstraint::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedOutputColumn::TYPE;

  ResolvedOutputColumn::~ResolvedOutputColumn() {
  }

  absl::Status ResolvedOutputColumn::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedOutputColumn::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            ResolvedOutputColumnProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedOutputColumn>> ResolvedOutputColumn::RestoreFrom(
                                                                                          const ResolvedOutputColumnProto& proto,
                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedOutputColumn::GetChildNodes(
                                           std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedOutputColumn::AddMutableChildNodePointers(
                                                         std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                         mutable_child_node_ptrs) {
  }

  absl::Status ResolvedOutputColumn::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedOutputColumn::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedOutputColumn::CheckFieldsAccessedImpl(
                                                             const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedOutputColumn::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedOutputColumn::ClearFieldsAccessed() const {
  }

  void ResolvedOutputColumn::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedProjectScan::TYPE;

  ResolvedProjectScan::~ResolvedProjectScan() {
  }

  absl::Status ResolvedProjectScan::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedProjectScan::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           ResolvedProjectScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedProjectScan>> ResolvedProjectScan::RestoreFrom(
                                                                                        const ResolvedProjectScanProto& proto,
                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedProjectScan::GetChildNodes(
                                          std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedProjectScan::AddMutableChildNodePointers(
                                                        std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                        mutable_child_node_ptrs) {
  }

  absl::Status ResolvedProjectScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedProjectScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedProjectScan::CollectDebugStringFields(
                                                     std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedProjectScan::CheckFieldsAccessedImpl(
                                                            const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedProjectScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedProjectScan::ClearFieldsAccessed() const {
  }

  void ResolvedProjectScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedTVFScan::TYPE;

  ResolvedTVFScan::~ResolvedTVFScan() {
  }

  absl::Status ResolvedTVFScan::SaveTo(
                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                       AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedTVFScan::SaveTo(
                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                       ResolvedTVFScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedTVFScan>> ResolvedTVFScan::RestoreFrom(
                                                                                const ResolvedTVFScanProto& proto,
                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedTVFScan::GetChildNodes(
                                      std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedTVFScan::AddMutableChildNodePointers(
                                                    std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                    mutable_child_node_ptrs) {
  }

  absl::Status ResolvedTVFScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedTVFScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedTVFScan::CollectDebugStringFields(
                                                 std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedTVFScan::CheckFieldsAccessedImpl(
                                                        const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedTVFScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedTVFScan::ClearFieldsAccessed() const {
  }

  void ResolvedTVFScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedGroupRowsScan::TYPE;

  ResolvedGroupRowsScan::~ResolvedGroupRowsScan() {
  }

  absl::Status ResolvedGroupRowsScan::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedGroupRowsScan::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             ResolvedGroupRowsScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedGroupRowsScan>> ResolvedGroupRowsScan::RestoreFrom(
                                                                                            const ResolvedGroupRowsScanProto& proto,
                                                                                            const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedGroupRowsScan::GetChildNodes(
                                            std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedGroupRowsScan::AddMutableChildNodePointers(
                                                          std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                          mutable_child_node_ptrs) {
  }

  absl::Status ResolvedGroupRowsScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedGroupRowsScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedGroupRowsScan::CollectDebugStringFields(
                                                       std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedGroupRowsScan::CheckFieldsAccessedImpl(
                                                              const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedGroupRowsScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedGroupRowsScan::ClearFieldsAccessed() const {
  }

  void ResolvedGroupRowsScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedFunctionArgument::TYPE;

  ResolvedFunctionArgument::~ResolvedFunctionArgument() {
  }

  absl::Status ResolvedFunctionArgument::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedFunctionArgument::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedFunctionArgumentProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedFunctionArgument>> ResolvedFunctionArgument::RestoreFrom(
                                                                                                  const ResolvedFunctionArgumentProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedFunctionArgument::GetChildNodes(
                                               std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedFunctionArgument::AddMutableChildNodePointers(
                                                             std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                             mutable_child_node_ptrs) {
  }

  absl::Status ResolvedFunctionArgument::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedFunctionArgument::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedFunctionArgument::CollectDebugStringFields(
                                                          std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedFunctionArgument::CheckFieldsAccessedImpl(
                                                                 const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedFunctionArgument::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedFunctionArgument::ClearFieldsAccessed() const {
  }

  void ResolvedFunctionArgument::MarkFieldsAccessed() const {
  }

  const ResolvedStatement::ObjectAccess ResolvedStatement::NONE;
  const ResolvedStatement::ObjectAccess ResolvedStatement::READ;
  const ResolvedStatement::ObjectAccess ResolvedStatement::WRITE;
  const ResolvedStatement::ObjectAccess ResolvedStatement::READ_WRITE;

  ResolvedStatement::~ResolvedStatement() {
  }

  absl::Status ResolvedStatement::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedNodeProto* proto) const {
  }

  absl::Status ResolvedStatement::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedStatementProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedStatement>> ResolvedStatement::RestoreFrom(
                                                                                    const AnyResolvedStatementProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedStatement::GetChildNodes(
                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedStatement::AddMutableChildNodePointers(
                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedStatement::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedStatement::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedStatement::CollectDebugStringFields(
                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedStatement::CheckFieldsAccessedImpl(
                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedStatement::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedStatement::ClearFieldsAccessed() const {
  }

  void ResolvedStatement::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedExplainStmt::TYPE;

  ResolvedExplainStmt::~ResolvedExplainStmt() {
  }

  absl::Status ResolvedExplainStmt::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedExplainStmt::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           ResolvedExplainStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedExplainStmt>> ResolvedExplainStmt::RestoreFrom(
                                                                                        const ResolvedExplainStmtProto& proto,
                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedExplainStmt::GetChildNodes(
                                          std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedExplainStmt::AddMutableChildNodePointers(
                                                        std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                        mutable_child_node_ptrs) {
  }

  absl::Status ResolvedExplainStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedExplainStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedExplainStmt::CollectDebugStringFields(
                                                     std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedExplainStmt::CheckFieldsAccessedImpl(
                                                            const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedExplainStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedExplainStmt::ClearFieldsAccessed() const {
  }

  void ResolvedExplainStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedQueryStmt::TYPE;

  ResolvedQueryStmt::~ResolvedQueryStmt() {
  }

  absl::Status ResolvedQueryStmt::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedQueryStmt::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedQueryStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedQueryStmt>> ResolvedQueryStmt::RestoreFrom(
                                                                                    const ResolvedQueryStmtProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedQueryStmt::GetChildNodes(
                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedQueryStmt::AddMutableChildNodePointers(
                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedQueryStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedQueryStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedQueryStmt::CollectDebugStringFields(
                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedQueryStmt::CheckFieldsAccessedImpl(
                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedQueryStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedQueryStmt::ClearFieldsAccessed() const {
  }

  void ResolvedQueryStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateDatabaseStmt::TYPE;

  ResolvedCreateDatabaseStmt::~ResolvedCreateDatabaseStmt() {
  }

  absl::Status ResolvedCreateDatabaseStmt::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedCreateDatabaseStmt::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  ResolvedCreateDatabaseStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateDatabaseStmt>> ResolvedCreateDatabaseStmt::RestoreFrom(
                                                                                                      const ResolvedCreateDatabaseStmtProto& proto,
                                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateDatabaseStmt::GetChildNodes(
                                                 std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateDatabaseStmt::AddMutableChildNodePointers(
                                                               std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                               mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateDatabaseStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateDatabaseStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateDatabaseStmt::CollectDebugStringFields(
                                                            std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateDatabaseStmt::CheckFieldsAccessedImpl(
                                                                   const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateDatabaseStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateDatabaseStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreateDatabaseStmt::MarkFieldsAccessed() const {
  }

  const ResolvedCreateStatement::CreateScope ResolvedCreateStatement::CREATE_DEFAULT_SCOPE;
  const ResolvedCreateStatement::CreateScope ResolvedCreateStatement::CREATE_PRIVATE;
  const ResolvedCreateStatement::CreateScope ResolvedCreateStatement::CREATE_PUBLIC;
  const ResolvedCreateStatement::CreateScope ResolvedCreateStatement::CREATE_TEMP;
  const ResolvedCreateStatement::CreateMode ResolvedCreateStatement::CREATE_DEFAULT;
  const ResolvedCreateStatement::CreateMode ResolvedCreateStatement::CREATE_OR_REPLACE;
  const ResolvedCreateStatement::CreateMode ResolvedCreateStatement::CREATE_IF_NOT_EXISTS;
  const ResolvedCreateStatement::SqlSecurity ResolvedCreateStatement::SQL_SECURITY_UNSPECIFIED;
  const ResolvedCreateStatement::SqlSecurity ResolvedCreateStatement::SQL_SECURITY_DEFINER;
  const ResolvedCreateStatement::SqlSecurity ResolvedCreateStatement::SQL_SECURITY_INVOKER;
  const ResolvedCreateStatement::DeterminismLevel ResolvedCreateStatement::DETERMINISM_UNSPECIFIED;
  const ResolvedCreateStatement::DeterminismLevel ResolvedCreateStatement::DETERMINISM_DETERMINISTIC;
  const ResolvedCreateStatement::DeterminismLevel ResolvedCreateStatement::DETERMINISM_NOT_DETERMINISTIC;
  const ResolvedCreateStatement::DeterminismLevel ResolvedCreateStatement::DETERMINISM_IMMUTABLE;
  const ResolvedCreateStatement::DeterminismLevel ResolvedCreateStatement::DETERMINISM_STABLE;
  const ResolvedCreateStatement::DeterminismLevel ResolvedCreateStatement::DETERMINISM_VOLATILE;

  ResolvedCreateStatement::~ResolvedCreateStatement() {
  }

  absl::Status ResolvedCreateStatement::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedCreateStatement::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedCreateStatementProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateStatement>> ResolvedCreateStatement::RestoreFrom(
                                                                                                const AnyResolvedCreateStatementProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateStatement::GetChildNodes(
                                              std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateStatement::AddMutableChildNodePointers(
                                                            std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                            mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateStatement::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateStatement::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateStatement::CollectDebugStringFields(
                                                         std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateStatement::CheckFieldsAccessedImpl(
                                                                const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateStatement::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateStatement::ClearFieldsAccessed() const {
  }

  void ResolvedCreateStatement::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedIndexItem::TYPE;

  ResolvedIndexItem::~ResolvedIndexItem() {
  }

  absl::Status ResolvedIndexItem::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedIndexItem::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedIndexItemProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedIndexItem>> ResolvedIndexItem::RestoreFrom(
                                                                                    const ResolvedIndexItemProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedIndexItem::GetChildNodes(
                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedIndexItem::AddMutableChildNodePointers(
                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedIndexItem::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedIndexItem::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedIndexItem::CollectDebugStringFields(
                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedIndexItem::CheckFieldsAccessedImpl(
                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedIndexItem::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedIndexItem::ClearFieldsAccessed() const {
  }

  void ResolvedIndexItem::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedUnnestItem::TYPE;

  ResolvedUnnestItem::~ResolvedUnnestItem() {
  }

  absl::Status ResolvedUnnestItem::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedUnnestItem::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedUnnestItemProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedUnnestItem>> ResolvedUnnestItem::RestoreFrom(
                                                                                      const ResolvedUnnestItemProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedUnnestItem::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedUnnestItem::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedUnnestItem::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedUnnestItem::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedUnnestItem::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedUnnestItem::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedUnnestItem::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedUnnestItem::ClearFieldsAccessed() const {
  }

  void ResolvedUnnestItem::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateIndexStmt::TYPE;

  ResolvedCreateIndexStmt::~ResolvedCreateIndexStmt() {
  }

  absl::Status ResolvedCreateIndexStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedCreateStatementProto* proto) const {
  }

  absl::Status ResolvedCreateIndexStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedCreateIndexStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateIndexStmt>> ResolvedCreateIndexStmt::RestoreFrom(
                                                                                                const ResolvedCreateIndexStmtProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateIndexStmt::GetChildNodes(
                                              std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateIndexStmt::AddMutableChildNodePointers(
                                                            std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                            mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateIndexStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateIndexStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateIndexStmt::CollectDebugStringFields(
                                                         std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateIndexStmt::CheckFieldsAccessedImpl(
                                                                const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateIndexStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateIndexStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreateIndexStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateSchemaStmt::TYPE;

  ResolvedCreateSchemaStmt::~ResolvedCreateSchemaStmt() {
  }

  absl::Status ResolvedCreateSchemaStmt::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedCreateStatementProto* proto) const {
  }

  absl::Status ResolvedCreateSchemaStmt::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedCreateSchemaStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateSchemaStmt>> ResolvedCreateSchemaStmt::RestoreFrom(
                                                                                                  const ResolvedCreateSchemaStmtProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateSchemaStmt::GetChildNodes(
                                               std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateSchemaStmt::AddMutableChildNodePointers(
                                                             std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                             mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateSchemaStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateSchemaStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateSchemaStmt::CollectDebugStringFields(
                                                          std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateSchemaStmt::CheckFieldsAccessedImpl(
                                                                 const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateSchemaStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateSchemaStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreateSchemaStmt::MarkFieldsAccessed() const {
  }

  ResolvedCreateTableStmtBase::~ResolvedCreateTableStmtBase() {
  }

  absl::Status ResolvedCreateTableStmtBase::SaveTo(
                                                   Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                   AnyResolvedCreateStatementProto* proto) const {
  }

  absl::Status ResolvedCreateTableStmtBase::SaveTo(
                                                   Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                   ResolvedCreateTableStmtBaseProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateTableStmtBase>> ResolvedCreateTableStmtBase::RestoreFrom(
                                                                                                        const AnyResolvedCreateTableStmtBaseProto& proto,
                                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateTableStmtBase::GetChildNodes(
                                                  std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateTableStmtBase::AddMutableChildNodePointers(
                                                                std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateTableStmtBase::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateTableStmtBase::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateTableStmtBase::CollectDebugStringFields(
                                                             std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateTableStmtBase::CheckFieldsAccessedImpl(
                                                                    const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateTableStmtBase::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateTableStmtBase::ClearFieldsAccessed() const {
  }

  void ResolvedCreateTableStmtBase::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateTableStmt::TYPE;

  ResolvedCreateTableStmt::~ResolvedCreateTableStmt() {
  }

  absl::Status ResolvedCreateTableStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedCreateTableStmtBaseProto* proto) const {
  }

  absl::Status ResolvedCreateTableStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedCreateTableStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateTableStmt>> ResolvedCreateTableStmt::RestoreFrom(
                                                                                                const ResolvedCreateTableStmtProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateTableStmt::GetChildNodes(
                                              std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateTableStmt::AddMutableChildNodePointers(
                                                            std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                            mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateTableStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateTableStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateTableStmt::CollectDebugStringFields(
                                                         std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateTableStmt::CheckFieldsAccessedImpl(
                                                                const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateTableStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateTableStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreateTableStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateTableAsSelectStmt::TYPE;

  ResolvedCreateTableAsSelectStmt::~ResolvedCreateTableAsSelectStmt() {
  }

  absl::Status ResolvedCreateTableAsSelectStmt::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       AnyResolvedCreateTableStmtBaseProto* proto) const {
  }

  absl::Status ResolvedCreateTableAsSelectStmt::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       ResolvedCreateTableAsSelectStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateTableAsSelectStmt>> ResolvedCreateTableAsSelectStmt::RestoreFrom(
                                                                                                                const ResolvedCreateTableAsSelectStmtProto& proto,
                                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateTableAsSelectStmt::GetChildNodes(
                                                      std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateTableAsSelectStmt::AddMutableChildNodePointers(
                                                                    std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                    mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateTableAsSelectStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateTableAsSelectStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateTableAsSelectStmt::CollectDebugStringFields(
                                                                 std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateTableAsSelectStmt::CheckFieldsAccessedImpl(
                                                                        const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateTableAsSelectStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateTableAsSelectStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreateTableAsSelectStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateModelStmt::TYPE;

  ResolvedCreateModelStmt::~ResolvedCreateModelStmt() {
  }

  absl::Status ResolvedCreateModelStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedCreateStatementProto* proto) const {
  }

  absl::Status ResolvedCreateModelStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedCreateModelStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateModelStmt>> ResolvedCreateModelStmt::RestoreFrom(
                                                                                                const ResolvedCreateModelStmtProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateModelStmt::GetChildNodes(
                                              std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateModelStmt::AddMutableChildNodePointers(
                                                            std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                            mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateModelStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateModelStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateModelStmt::CollectDebugStringFields(
                                                         std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateModelStmt::CheckFieldsAccessedImpl(
                                                                const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateModelStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateModelStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreateModelStmt::MarkFieldsAccessed() const {
  }

  ResolvedCreateViewBase::~ResolvedCreateViewBase() {
  }

  absl::Status ResolvedCreateViewBase::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              AnyResolvedCreateStatementProto* proto) const {
  }

  absl::Status ResolvedCreateViewBase::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              ResolvedCreateViewBaseProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateViewBase>> ResolvedCreateViewBase::RestoreFrom(
                                                                                              const AnyResolvedCreateViewBaseProto& proto,
                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateViewBase::GetChildNodes(
                                             std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateViewBase::AddMutableChildNodePointers(
                                                           std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                           mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateViewBase::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateViewBase::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateViewBase::CollectDebugStringFields(
                                                        std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateViewBase::CheckFieldsAccessedImpl(
                                                               const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateViewBase::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateViewBase::ClearFieldsAccessed() const {
  }

  void ResolvedCreateViewBase::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateViewStmt::TYPE;

  ResolvedCreateViewStmt::~ResolvedCreateViewStmt() {
  }

  absl::Status ResolvedCreateViewStmt::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              AnyResolvedCreateViewBaseProto* proto) const {
  }

  absl::Status ResolvedCreateViewStmt::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              ResolvedCreateViewStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateViewStmt>> ResolvedCreateViewStmt::RestoreFrom(
                                                                                              const ResolvedCreateViewStmtProto& proto,
                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedCreateViewStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateViewStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedWithPartitionColumns::TYPE;

  ResolvedWithPartitionColumns::~ResolvedWithPartitionColumns() {
  }

  absl::Status ResolvedWithPartitionColumns::SaveTo(
                                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                    AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedWithPartitionColumns::SaveTo(
                                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                    ResolvedWithPartitionColumnsProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedWithPartitionColumns>> ResolvedWithPartitionColumns::RestoreFrom(
                                                                                                          const ResolvedWithPartitionColumnsProto& proto,
                                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedWithPartitionColumns::GetChildNodes(
                                                   std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedWithPartitionColumns::AddMutableChildNodePointers(
                                                                 std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                 mutable_child_node_ptrs) {
  }

  absl::Status ResolvedWithPartitionColumns::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedWithPartitionColumns::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedWithPartitionColumns::CollectDebugStringFields(
                                                              std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedWithPartitionColumns::CheckFieldsAccessedImpl(
                                                                     const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedWithPartitionColumns::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedWithPartitionColumns::ClearFieldsAccessed() const {
  }

  void ResolvedWithPartitionColumns::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateSnapshotTableStmt::TYPE;

  ResolvedCreateSnapshotTableStmt::~ResolvedCreateSnapshotTableStmt() {
  }

  absl::Status ResolvedCreateSnapshotTableStmt::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       AnyResolvedCreateStatementProto* proto) const {
  }

  absl::Status ResolvedCreateSnapshotTableStmt::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       ResolvedCreateSnapshotTableStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateSnapshotTableStmt>> ResolvedCreateSnapshotTableStmt::RestoreFrom(
                                                                                                                const ResolvedCreateSnapshotTableStmtProto& proto,
                                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateSnapshotTableStmt::GetChildNodes(
                                                      std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateSnapshotTableStmt::AddMutableChildNodePointers(
                                                                    std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                    mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateSnapshotTableStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateSnapshotTableStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateSnapshotTableStmt::CollectDebugStringFields(
                                                                 std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateSnapshotTableStmt::CheckFieldsAccessedImpl(
                                                                        const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateSnapshotTableStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateSnapshotTableStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreateSnapshotTableStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateExternalTableStmt::TYPE;

  ResolvedCreateExternalTableStmt::~ResolvedCreateExternalTableStmt() {
  }

  absl::Status ResolvedCreateExternalTableStmt::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       AnyResolvedCreateTableStmtBaseProto* proto) const {
  }

  absl::Status ResolvedCreateExternalTableStmt::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       ResolvedCreateExternalTableStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateExternalTableStmt>> ResolvedCreateExternalTableStmt::RestoreFrom(
                                                                                                                const ResolvedCreateExternalTableStmtProto& proto,
                                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateExternalTableStmt::GetChildNodes(
                                                      std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateExternalTableStmt::AddMutableChildNodePointers(
                                                                    std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                    mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateExternalTableStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateExternalTableStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateExternalTableStmt::CollectDebugStringFields(
                                                                 std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateExternalTableStmt::CheckFieldsAccessedImpl(
                                                                        const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateExternalTableStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateExternalTableStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreateExternalTableStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedExportModelStmt::TYPE;

  ResolvedExportModelStmt::~ResolvedExportModelStmt() {
  }

  absl::Status ResolvedExportModelStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedExportModelStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedExportModelStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedExportModelStmt>> ResolvedExportModelStmt::RestoreFrom(
                                                                                                const ResolvedExportModelStmtProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedExportModelStmt::GetChildNodes(
                                              std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedExportModelStmt::AddMutableChildNodePointers(
                                                            std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                            mutable_child_node_ptrs) {
  }

  absl::Status ResolvedExportModelStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedExportModelStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedExportModelStmt::CollectDebugStringFields(
                                                         std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedExportModelStmt::CheckFieldsAccessedImpl(
                                                                const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedExportModelStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedExportModelStmt::ClearFieldsAccessed() const {
  }

  void ResolvedExportModelStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedExportDataStmt::TYPE;

  ResolvedExportDataStmt::~ResolvedExportDataStmt() {
  }

  absl::Status ResolvedExportDataStmt::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedExportDataStmt::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              ResolvedExportDataStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedExportDataStmt>> ResolvedExportDataStmt::RestoreFrom(
                                                                                              const ResolvedExportDataStmtProto& proto,
                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedExportDataStmt::GetChildNodes(
                                             std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedExportDataStmt::AddMutableChildNodePointers(
                                                           std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                           mutable_child_node_ptrs) {
  }

  absl::Status ResolvedExportDataStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedExportDataStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedExportDataStmt::CollectDebugStringFields(
                                                        std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedExportDataStmt::CheckFieldsAccessedImpl(
                                                               const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedExportDataStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedExportDataStmt::ClearFieldsAccessed() const {
  }

  void ResolvedExportDataStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedDefineTableStmt::TYPE;

  ResolvedDefineTableStmt::~ResolvedDefineTableStmt() {
  }

  absl::Status ResolvedDefineTableStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedDefineTableStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedDefineTableStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDefineTableStmt>> ResolvedDefineTableStmt::RestoreFrom(
                                                                                                const ResolvedDefineTableStmtProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDefineTableStmt::GetChildNodes(
                                              std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDefineTableStmt::AddMutableChildNodePointers(
                                                            std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                            mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDefineTableStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDefineTableStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDefineTableStmt::CollectDebugStringFields(
                                                         std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDefineTableStmt::CheckFieldsAccessedImpl(
                                                                const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDefineTableStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDefineTableStmt::ClearFieldsAccessed() const {
  }

  void ResolvedDefineTableStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedDescribeStmt::TYPE;

  ResolvedDescribeStmt::~ResolvedDescribeStmt() {
  }

  absl::Status ResolvedDescribeStmt::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedDescribeStmt::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            ResolvedDescribeStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDescribeStmt>> ResolvedDescribeStmt::RestoreFrom(
                                                                                          const ResolvedDescribeStmtProto& proto,
                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDescribeStmt::GetChildNodes(
                                           std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDescribeStmt::AddMutableChildNodePointers(
                                                         std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                         mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDescribeStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDescribeStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDescribeStmt::CollectDebugStringFields(
                                                      std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDescribeStmt::CheckFieldsAccessedImpl(
                                                             const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDescribeStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDescribeStmt::ClearFieldsAccessed() const {
  }

  void ResolvedDescribeStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedShowStmt::TYPE;

  ResolvedShowStmt::~ResolvedShowStmt() {
  }

  absl::Status ResolvedShowStmt::SaveTo(
                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedShowStmt::SaveTo(
                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        ResolvedShowStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedShowStmt>> ResolvedShowStmt::RestoreFrom(
                                                                                  const ResolvedShowStmtProto& proto,
                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedShowStmt::GetChildNodes(
                                       std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedShowStmt::AddMutableChildNodePointers(
                                                     std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                     mutable_child_node_ptrs) {
  }

  absl::Status ResolvedShowStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedShowStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedShowStmt::CollectDebugStringFields(
                                                  std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedShowStmt::CheckFieldsAccessedImpl(
                                                         const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedShowStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedShowStmt::ClearFieldsAccessed() const {
  }

  void ResolvedShowStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedBeginStmt::TYPE;

  const ResolvedBeginStmt::ReadWriteMode ResolvedBeginStmt::MODE_UNSPECIFIED;
  const ResolvedBeginStmt::ReadWriteMode ResolvedBeginStmt::MODE_READ_ONLY;
  const ResolvedBeginStmt::ReadWriteMode ResolvedBeginStmt::MODE_READ_WRITE;

  ResolvedBeginStmt::~ResolvedBeginStmt() {
  }

  absl::Status ResolvedBeginStmt::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedBeginStmt::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedBeginStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedBeginStmt>> ResolvedBeginStmt::RestoreFrom(
                                                                                    const ResolvedBeginStmtProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedBeginStmt::GetChildNodes(
                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedBeginStmt::AddMutableChildNodePointers(
                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedBeginStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedBeginStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedBeginStmt::CollectDebugStringFields(
                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedBeginStmt::CheckFieldsAccessedImpl(
                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedBeginStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedBeginStmt::ClearFieldsAccessed() const {
  }

  void ResolvedBeginStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedSetTransactionStmt::TYPE;

  ResolvedSetTransactionStmt::~ResolvedSetTransactionStmt() {
  }

  absl::Status ResolvedSetTransactionStmt::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedSetTransactionStmt::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  ResolvedSetTransactionStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedSetTransactionStmt>> ResolvedSetTransactionStmt::RestoreFrom(
                                                                                                      const ResolvedSetTransactionStmtProto& proto,
                                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedSetTransactionStmt::GetChildNodes(
                                                 std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedSetTransactionStmt::AddMutableChildNodePointers(
                                                               std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                               mutable_child_node_ptrs) {
  }

  absl::Status ResolvedSetTransactionStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedSetTransactionStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedSetTransactionStmt::CollectDebugStringFields(
                                                            std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedSetTransactionStmt::CheckFieldsAccessedImpl(
                                                                   const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedSetTransactionStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedSetTransactionStmt::ClearFieldsAccessed() const {
  }

  void ResolvedSetTransactionStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCommitStmt::TYPE;

  ResolvedCommitStmt::~ResolvedCommitStmt() {
  }

  absl::Status ResolvedCommitStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedCommitStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedCommitStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCommitStmt>> ResolvedCommitStmt::RestoreFrom(
                                                                                      const ResolvedCommitStmtProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedCommitStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCommitStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedRollbackStmt::TYPE;

  ResolvedRollbackStmt::~ResolvedRollbackStmt() {
  }

  absl::Status ResolvedRollbackStmt::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedRollbackStmt::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            ResolvedRollbackStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedRollbackStmt>> ResolvedRollbackStmt::RestoreFrom(
                                                                                          const ResolvedRollbackStmtProto& proto,
                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedRollbackStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedRollbackStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedStartBatchStmt::TYPE;

  ResolvedStartBatchStmt::~ResolvedStartBatchStmt() {
  }

  absl::Status ResolvedStartBatchStmt::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedStartBatchStmt::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              ResolvedStartBatchStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedStartBatchStmt>> ResolvedStartBatchStmt::RestoreFrom(
                                                                                              const ResolvedStartBatchStmtProto& proto,
                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedStartBatchStmt::GetChildNodes(
                                             std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedStartBatchStmt::AddMutableChildNodePointers(
                                                           std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                           mutable_child_node_ptrs) {
  }

  absl::Status ResolvedStartBatchStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedStartBatchStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedStartBatchStmt::CollectDebugStringFields(
                                                        std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedStartBatchStmt::CheckFieldsAccessedImpl(
                                                               const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedStartBatchStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedStartBatchStmt::ClearFieldsAccessed() const {
  }

  void ResolvedStartBatchStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedRunBatchStmt::TYPE;

  ResolvedRunBatchStmt::~ResolvedRunBatchStmt() {
  }

  absl::Status ResolvedRunBatchStmt::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedRunBatchStmt::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            ResolvedRunBatchStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedRunBatchStmt>> ResolvedRunBatchStmt::RestoreFrom(
                                                                                          const ResolvedRunBatchStmtProto& proto,
                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedRunBatchStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedRunBatchStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedAbortBatchStmt::TYPE;

  ResolvedAbortBatchStmt::~ResolvedAbortBatchStmt() {
  }

  absl::Status ResolvedAbortBatchStmt::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedAbortBatchStmt::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              ResolvedAbortBatchStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAbortBatchStmt>> ResolvedAbortBatchStmt::RestoreFrom(
                                                                                              const ResolvedAbortBatchStmtProto& proto,
                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedAbortBatchStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAbortBatchStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedDropStmt::TYPE;

  const ResolvedDropStmt::DropMode ResolvedDropStmt::DROP_MODE_UNSPECIFIED;
  const ResolvedDropStmt::DropMode ResolvedDropStmt::RESTRICT;
  const ResolvedDropStmt::DropMode ResolvedDropStmt::CASCADE;

  ResolvedDropStmt::~ResolvedDropStmt() {
  }

  absl::Status ResolvedDropStmt::SaveTo(
                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedDropStmt::SaveTo(
                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        ResolvedDropStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDropStmt>> ResolvedDropStmt::RestoreFrom(
                                                                                  const ResolvedDropStmtProto& proto,
                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDropStmt::GetChildNodes(
                                       std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDropStmt::AddMutableChildNodePointers(
                                                     std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                     mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDropStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDropStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDropStmt::CollectDebugStringFields(
                                                  std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDropStmt::CheckFieldsAccessedImpl(
                                                         const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDropStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDropStmt::ClearFieldsAccessed() const {
  }

  void ResolvedDropStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedDropMaterializedViewStmt::TYPE;

  ResolvedDropMaterializedViewStmt::~ResolvedDropMaterializedViewStmt() {
  }

  absl::Status ResolvedDropMaterializedViewStmt::SaveTo(
                                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                        AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedDropMaterializedViewStmt::SaveTo(
                                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                        ResolvedDropMaterializedViewStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDropMaterializedViewStmt>> ResolvedDropMaterializedViewStmt::RestoreFrom(
                                                                                                                  const ResolvedDropMaterializedViewStmtProto& proto,
                                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDropMaterializedViewStmt::GetChildNodes(
                                                       std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDropMaterializedViewStmt::AddMutableChildNodePointers(
                                                                     std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                     mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDropMaterializedViewStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDropMaterializedViewStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDropMaterializedViewStmt::CollectDebugStringFields(
                                                                  std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDropMaterializedViewStmt::CheckFieldsAccessedImpl(
                                                                         const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDropMaterializedViewStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDropMaterializedViewStmt::ClearFieldsAccessed() const {
  }

  void ResolvedDropMaterializedViewStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedDropSnapshotTableStmt::TYPE;

  ResolvedDropSnapshotTableStmt::~ResolvedDropSnapshotTableStmt() {
  }

  absl::Status ResolvedDropSnapshotTableStmt::SaveTo(
                                                     Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                     AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedDropSnapshotTableStmt::SaveTo(
                                                     Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                     ResolvedDropSnapshotTableStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDropSnapshotTableStmt>> ResolvedDropSnapshotTableStmt::RestoreFrom(
                                                                                                            const ResolvedDropSnapshotTableStmtProto& proto,
                                                                                                            const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDropSnapshotTableStmt::GetChildNodes(
                                                    std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDropSnapshotTableStmt::AddMutableChildNodePointers(
                                                                  std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                  mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDropSnapshotTableStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDropSnapshotTableStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDropSnapshotTableStmt::CollectDebugStringFields(
                                                               std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDropSnapshotTableStmt::CheckFieldsAccessedImpl(
                                                                      const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDropSnapshotTableStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDropSnapshotTableStmt::ClearFieldsAccessed() const {
  }

  void ResolvedDropSnapshotTableStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedRecursiveRefScan::TYPE;

  ResolvedRecursiveRefScan::~ResolvedRecursiveRefScan() {
  }

  absl::Status ResolvedRecursiveRefScan::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedRecursiveRefScan::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedRecursiveRefScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedRecursiveRefScan>> ResolvedRecursiveRefScan::RestoreFrom(
                                                                                                  const ResolvedRecursiveRefScanProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedRecursiveRefScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedRecursiveRefScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedRecursiveScan::TYPE;

  const ResolvedRecursiveScan::RecursiveSetOperationType ResolvedRecursiveScan::UNION_ALL;
  const ResolvedRecursiveScan::RecursiveSetOperationType ResolvedRecursiveScan::UNION_DISTINCT;

  ResolvedRecursiveScan::~ResolvedRecursiveScan() {
  }

  absl::Status ResolvedRecursiveScan::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedRecursiveScan::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             ResolvedRecursiveScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedRecursiveScan>> ResolvedRecursiveScan::RestoreFrom(
                                                                                            const ResolvedRecursiveScanProto& proto,
                                                                                            const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedRecursiveScan::GetChildNodes(
                                            std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedRecursiveScan::AddMutableChildNodePointers(
                                                          std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                          mutable_child_node_ptrs) {
  }

  absl::Status ResolvedRecursiveScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedRecursiveScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedRecursiveScan::CollectDebugStringFields(
                                                       std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedRecursiveScan::CheckFieldsAccessedImpl(
                                                              const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedRecursiveScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedRecursiveScan::ClearFieldsAccessed() const {
  }

  void ResolvedRecursiveScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedWithScan::TYPE;

  ResolvedWithScan::~ResolvedWithScan() {
  }

  absl::Status ResolvedWithScan::SaveTo(
                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedWithScan::SaveTo(
                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        ResolvedWithScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedWithScan>> ResolvedWithScan::RestoreFrom(
                                                                                  const ResolvedWithScanProto& proto,
                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedWithScan::GetChildNodes(
                                       std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedWithScan::AddMutableChildNodePointers(
                                                     std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                     mutable_child_node_ptrs) {
  }

  absl::Status ResolvedWithScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedWithScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedWithScan::CollectDebugStringFields(
                                                  std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedWithScan::CheckFieldsAccessedImpl(
                                                         const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedWithScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedWithScan::ClearFieldsAccessed() const {
  }

  void ResolvedWithScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedWithEntry::TYPE;

  ResolvedWithEntry::~ResolvedWithEntry() {
  }

  absl::Status ResolvedWithEntry::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedWithEntry::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedWithEntryProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedWithEntry>> ResolvedWithEntry::RestoreFrom(
                                                                                    const ResolvedWithEntryProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedWithEntry::GetChildNodes(
                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedWithEntry::AddMutableChildNodePointers(
                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedWithEntry::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedWithEntry::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedWithEntry::CollectDebugStringFields(
                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedWithEntry::CheckFieldsAccessedImpl(
                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedWithEntry::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedWithEntry::ClearFieldsAccessed() const {
  }

  void ResolvedWithEntry::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedOption::TYPE;

  ResolvedOption::~ResolvedOption() {
  }

  absl::Status ResolvedOption::SaveTo(
                                      Type::FileDescriptorSetMap* file_descriptor_set_map,
                                      AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedOption::SaveTo(
                                      Type::FileDescriptorSetMap* file_descriptor_set_map,
                                      ResolvedOptionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedOption>> ResolvedOption::RestoreFrom(
                                                                              const ResolvedOptionProto& proto,
                                                                              const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedOption::GetChildNodes(
                                     std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedOption::AddMutableChildNodePointers(
                                                   std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                   mutable_child_node_ptrs) {
  }

  absl::Status ResolvedOption::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedOption::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedOption::CheckFieldsAccessedImpl(
                                                       const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedOption::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedOption::ClearFieldsAccessed() const {
  }

  void ResolvedOption::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedWindowPartitioning::TYPE;

  ResolvedWindowPartitioning::~ResolvedWindowPartitioning() {
  }

  absl::Status ResolvedWindowPartitioning::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedWindowPartitioning::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  ResolvedWindowPartitioningProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedWindowPartitioning>> ResolvedWindowPartitioning::RestoreFrom(
                                                                                                      const ResolvedWindowPartitioningProto& proto,
                                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedWindowPartitioning::GetChildNodes(
                                                 std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedWindowPartitioning::AddMutableChildNodePointers(
                                                               std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                               mutable_child_node_ptrs) {
  }

  absl::Status ResolvedWindowPartitioning::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedWindowPartitioning::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedWindowPartitioning::CollectDebugStringFields(
                                                            std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedWindowPartitioning::CheckFieldsAccessedImpl(
                                                                   const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedWindowPartitioning::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedWindowPartitioning::ClearFieldsAccessed() const {
  }

  void ResolvedWindowPartitioning::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedWindowOrdering::TYPE;

  ResolvedWindowOrdering::~ResolvedWindowOrdering() {
  }

  absl::Status ResolvedWindowOrdering::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedWindowOrdering::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              ResolvedWindowOrderingProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedWindowOrdering>> ResolvedWindowOrdering::RestoreFrom(
                                                                                              const ResolvedWindowOrderingProto& proto,
                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedWindowOrdering::GetChildNodes(
                                             std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedWindowOrdering::AddMutableChildNodePointers(
                                                           std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                           mutable_child_node_ptrs) {
  }

  absl::Status ResolvedWindowOrdering::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedWindowOrdering::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedWindowOrdering::CollectDebugStringFields(
                                                        std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedWindowOrdering::CheckFieldsAccessedImpl(
                                                               const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedWindowOrdering::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedWindowOrdering::ClearFieldsAccessed() const {
  }

  void ResolvedWindowOrdering::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedWindowFrame::TYPE;

  const ResolvedWindowFrame::FrameUnit ResolvedWindowFrame::ROWS;
  const ResolvedWindowFrame::FrameUnit ResolvedWindowFrame::RANGE;

  ResolvedWindowFrame::~ResolvedWindowFrame() {
  }

  absl::Status ResolvedWindowFrame::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedWindowFrame::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           ResolvedWindowFrameProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedWindowFrame>> ResolvedWindowFrame::RestoreFrom(
                                                                                        const ResolvedWindowFrameProto& proto,
                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedWindowFrame::GetChildNodes(
                                          std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedWindowFrame::AddMutableChildNodePointers(
                                                        std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                        mutable_child_node_ptrs) {
  }

  absl::Status ResolvedWindowFrame::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedWindowFrame::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedWindowFrame::CheckFieldsAccessedImpl(
                                                            const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedWindowFrame::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedWindowFrame::ClearFieldsAccessed() const {
  }

  void ResolvedWindowFrame::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAnalyticFunctionGroup::TYPE;

  ResolvedAnalyticFunctionGroup::~ResolvedAnalyticFunctionGroup() {
  }

  absl::Status ResolvedAnalyticFunctionGroup::SaveTo(
                                                     Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                     AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedAnalyticFunctionGroup::SaveTo(
                                                     Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                     ResolvedAnalyticFunctionGroupProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAnalyticFunctionGroup>> ResolvedAnalyticFunctionGroup::RestoreFrom(
                                                                                                            const ResolvedAnalyticFunctionGroupProto& proto,
                                                                                                            const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAnalyticFunctionGroup::GetChildNodes(
                                                    std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAnalyticFunctionGroup::AddMutableChildNodePointers(
                                                                  std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                  mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAnalyticFunctionGroup::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAnalyticFunctionGroup::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAnalyticFunctionGroup::CollectDebugStringFields(
                                                               std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAnalyticFunctionGroup::CheckFieldsAccessedImpl(
                                                                      const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAnalyticFunctionGroup::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAnalyticFunctionGroup::ClearFieldsAccessed() const {
  }

  void ResolvedAnalyticFunctionGroup::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedWindowFrameExpr::TYPE;

  const ResolvedWindowFrameExpr::BoundaryType ResolvedWindowFrameExpr::UNBOUNDED_PRECEDING;
  const ResolvedWindowFrameExpr::BoundaryType ResolvedWindowFrameExpr::OFFSET_PRECEDING;
  const ResolvedWindowFrameExpr::BoundaryType ResolvedWindowFrameExpr::CURRENT_ROW;
  const ResolvedWindowFrameExpr::BoundaryType ResolvedWindowFrameExpr::OFFSET_FOLLOWING;
  const ResolvedWindowFrameExpr::BoundaryType ResolvedWindowFrameExpr::UNBOUNDED_FOLLOWING;

  ResolvedWindowFrameExpr::~ResolvedWindowFrameExpr() {
  }

  absl::Status ResolvedWindowFrameExpr::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedWindowFrameExpr::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedWindowFrameExprProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedWindowFrameExpr>> ResolvedWindowFrameExpr::RestoreFrom(
                                                                                                const ResolvedWindowFrameExprProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedWindowFrameExpr::GetChildNodes(
                                              std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedWindowFrameExpr::AddMutableChildNodePointers(
                                                            std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                            mutable_child_node_ptrs) {
  }

  absl::Status ResolvedWindowFrameExpr::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedWindowFrameExpr::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedWindowFrameExpr::CheckFieldsAccessedImpl(
                                                                const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedWindowFrameExpr::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedWindowFrameExpr::ClearFieldsAccessed() const {
  }

  void ResolvedWindowFrameExpr::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedDMLValue::TYPE;

  ResolvedDMLValue::~ResolvedDMLValue() {
  }

  absl::Status ResolvedDMLValue::SaveTo(
                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedDMLValue::SaveTo(
                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        ResolvedDMLValueProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDMLValue>> ResolvedDMLValue::RestoreFrom(
                                                                                  const ResolvedDMLValueProto& proto,
                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDMLValue::GetChildNodes(
                                       std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDMLValue::AddMutableChildNodePointers(
                                                     std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                     mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDMLValue::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDMLValue::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDMLValue::CollectDebugStringFields(
                                                  std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDMLValue::CheckFieldsAccessedImpl(
                                                         const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDMLValue::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDMLValue::ClearFieldsAccessed() const {
  }

  void ResolvedDMLValue::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedDMLDefault::TYPE;

  ResolvedDMLDefault::~ResolvedDMLDefault() {
  }

  absl::Status ResolvedDMLDefault::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedDMLDefault::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedDMLDefaultProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDMLDefault>> ResolvedDMLDefault::RestoreFrom(
                                                                                      const ResolvedDMLDefaultProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedDMLDefault::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDMLDefault::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedAssertStmt::TYPE;

  ResolvedAssertStmt::~ResolvedAssertStmt() {
  }

  absl::Status ResolvedAssertStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedAssertStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedAssertStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAssertStmt>> ResolvedAssertStmt::RestoreFrom(
                                                                                      const ResolvedAssertStmtProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAssertStmt::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAssertStmt::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAssertStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAssertStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAssertStmt::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAssertStmt::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAssertStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAssertStmt::ClearFieldsAccessed() const {
  }

  void ResolvedAssertStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAssertRowsModified::TYPE;

  ResolvedAssertRowsModified::~ResolvedAssertRowsModified() {
  }

  absl::Status ResolvedAssertRowsModified::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedAssertRowsModified::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  ResolvedAssertRowsModifiedProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAssertRowsModified>> ResolvedAssertRowsModified::RestoreFrom(
                                                                                                      const ResolvedAssertRowsModifiedProto& proto,
                                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAssertRowsModified::GetChildNodes(
                                                 std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAssertRowsModified::AddMutableChildNodePointers(
                                                               std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                               mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAssertRowsModified::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAssertRowsModified::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAssertRowsModified::CollectDebugStringFields(
                                                            std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAssertRowsModified::CheckFieldsAccessedImpl(
                                                                   const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAssertRowsModified::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAssertRowsModified::ClearFieldsAccessed() const {
  }

  void ResolvedAssertRowsModified::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedInsertRow::TYPE;

  ResolvedInsertRow::~ResolvedInsertRow() {
  }

  absl::Status ResolvedInsertRow::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedInsertRow::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedInsertRowProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedInsertRow>> ResolvedInsertRow::RestoreFrom(
                                                                                    const ResolvedInsertRowProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedInsertRow::GetChildNodes(
                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedInsertRow::AddMutableChildNodePointers(
                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedInsertRow::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedInsertRow::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedInsertRow::CollectDebugStringFields(
                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedInsertRow::CheckFieldsAccessedImpl(
                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedInsertRow::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedInsertRow::ClearFieldsAccessed() const {
  }

  void ResolvedInsertRow::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedInsertStmt::TYPE;

  const ResolvedInsertStmt::InsertMode ResolvedInsertStmt::OR_ERROR;
  const ResolvedInsertStmt::InsertMode ResolvedInsertStmt::OR_IGNORE;
  const ResolvedInsertStmt::InsertMode ResolvedInsertStmt::OR_REPLACE;
  const ResolvedInsertStmt::InsertMode ResolvedInsertStmt::OR_UPDATE;

  ResolvedInsertStmt::~ResolvedInsertStmt() {
  }

  absl::Status ResolvedInsertStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedInsertStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedInsertStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedInsertStmt>> ResolvedInsertStmt::RestoreFrom(
                                                                                      const ResolvedInsertStmtProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedInsertStmt::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedInsertStmt::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedInsertStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedInsertStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedInsertStmt::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedInsertStmt::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedInsertStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedInsertStmt::ClearFieldsAccessed() const {
  }

  void ResolvedInsertStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedDeleteStmt::TYPE;

  ResolvedDeleteStmt::~ResolvedDeleteStmt() {
  }

  absl::Status ResolvedDeleteStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedDeleteStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedDeleteStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDeleteStmt>> ResolvedDeleteStmt::RestoreFrom(
                                                                                      const ResolvedDeleteStmtProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDeleteStmt::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDeleteStmt::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDeleteStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDeleteStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDeleteStmt::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDeleteStmt::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDeleteStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDeleteStmt::ClearFieldsAccessed() const {
  }

  void ResolvedDeleteStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedUpdateItem::TYPE;

  ResolvedUpdateItem::~ResolvedUpdateItem() {
  }

  absl::Status ResolvedUpdateItem::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedUpdateItem::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedUpdateItemProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedUpdateItem>> ResolvedUpdateItem::RestoreFrom(
                                                                                      const ResolvedUpdateItemProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedUpdateItem::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedUpdateItem::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedUpdateItem::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedUpdateItem::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedUpdateItem::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedUpdateItem::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedUpdateItem::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedUpdateItem::ClearFieldsAccessed() const {
  }

  void ResolvedUpdateItem::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedUpdateArrayItem::TYPE;

  ResolvedUpdateArrayItem::~ResolvedUpdateArrayItem() {
  }

  absl::Status ResolvedUpdateArrayItem::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedUpdateArrayItem::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedUpdateArrayItemProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedUpdateArrayItem>> ResolvedUpdateArrayItem::RestoreFrom(
                                                                                                const ResolvedUpdateArrayItemProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedUpdateArrayItem::GetChildNodes(
                                              std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedUpdateArrayItem::AddMutableChildNodePointers(
                                                            std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                            mutable_child_node_ptrs) {
  }

  absl::Status ResolvedUpdateArrayItem::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedUpdateArrayItem::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedUpdateArrayItem::CollectDebugStringFields(
                                                         std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedUpdateArrayItem::CheckFieldsAccessedImpl(
                                                                const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedUpdateArrayItem::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedUpdateArrayItem::ClearFieldsAccessed() const {
  }

  void ResolvedUpdateArrayItem::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedUpdateStmt::TYPE;

  ResolvedUpdateStmt::~ResolvedUpdateStmt() {
  }

  absl::Status ResolvedUpdateStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedUpdateStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedUpdateStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedUpdateStmt>> ResolvedUpdateStmt::RestoreFrom(
                                                                                      const ResolvedUpdateStmtProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedUpdateStmt::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedUpdateStmt::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedUpdateStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedUpdateStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedUpdateStmt::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedUpdateStmt::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedUpdateStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedUpdateStmt::ClearFieldsAccessed() const {
  }

  void ResolvedUpdateStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedMergeWhen::TYPE;

  const ResolvedMergeWhen::MatchType ResolvedMergeWhen::MATCHED;
  const ResolvedMergeWhen::MatchType ResolvedMergeWhen::NOT_MATCHED_BY_SOURCE;
  const ResolvedMergeWhen::MatchType ResolvedMergeWhen::NOT_MATCHED_BY_TARGET;
  const ResolvedMergeWhen::ActionType ResolvedMergeWhen::INSERT;
  const ResolvedMergeWhen::ActionType ResolvedMergeWhen::UPDATE;
  const ResolvedMergeWhen::ActionType ResolvedMergeWhen::DELETE;

  ResolvedMergeWhen::~ResolvedMergeWhen() {
  }

  absl::Status ResolvedMergeWhen::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedMergeWhen::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedMergeWhenProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedMergeWhen>> ResolvedMergeWhen::RestoreFrom(
                                                                                    const ResolvedMergeWhenProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedMergeWhen::GetChildNodes(
                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedMergeWhen::AddMutableChildNodePointers(
                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedMergeWhen::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedMergeWhen::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedMergeWhen::CollectDebugStringFields(
                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedMergeWhen::CheckFieldsAccessedImpl(
                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedMergeWhen::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedMergeWhen::ClearFieldsAccessed() const {
  }

  void ResolvedMergeWhen::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedMergeStmt::TYPE;

  ResolvedMergeStmt::~ResolvedMergeStmt() {
  }

  absl::Status ResolvedMergeStmt::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedStatementProto* proto) const {
    return SaveTo(
                  file_descriptor_set_map, proto->mutable_resolved_merge_stmt_node());
  }

  absl::Status ResolvedMergeStmt::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedMergeStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedMergeStmt>> ResolvedMergeStmt::RestoreFrom(
                                                                                    const ResolvedMergeStmtProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedMergeStmt::GetChildNodes(
                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedMergeStmt::AddMutableChildNodePointers(
                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedMergeStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedMergeStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedMergeStmt::CollectDebugStringFields(
                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedMergeStmt::CheckFieldsAccessedImpl(
                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedMergeStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedMergeStmt::ClearFieldsAccessed() const {
  }

  void ResolvedMergeStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedTruncateStmt::TYPE;

  ResolvedTruncateStmt::~ResolvedTruncateStmt() {
  }

  absl::Status ResolvedTruncateStmt::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedTruncateStmt::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            ResolvedTruncateStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedTruncateStmt>> ResolvedTruncateStmt::RestoreFrom(
                                                                                          const ResolvedTruncateStmtProto& proto,
                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedTruncateStmt::GetChildNodes(
                                           std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedTruncateStmt::AddMutableChildNodePointers(
                                                         std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                         mutable_child_node_ptrs) {
  }

  absl::Status ResolvedTruncateStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedTruncateStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedTruncateStmt::CollectDebugStringFields(
                                                      std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedTruncateStmt::CheckFieldsAccessedImpl(
                                                             const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedTruncateStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedTruncateStmt::ClearFieldsAccessed() const {
  }

  void ResolvedTruncateStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedObjectUnit::TYPE;

  ResolvedObjectUnit::~ResolvedObjectUnit() {
  }

  absl::Status ResolvedObjectUnit::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedObjectUnit::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedObjectUnitProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedObjectUnit>> ResolvedObjectUnit::RestoreFrom(
                                                                                      const ResolvedObjectUnitProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedObjectUnit::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedObjectUnit::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedObjectUnit::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedObjectUnit::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedObjectUnit::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedObjectUnit::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedObjectUnit::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedObjectUnit::ClearFieldsAccessed() const {
  }

  void ResolvedObjectUnit::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedPrivilege::TYPE;

  ResolvedPrivilege::~ResolvedPrivilege() {
  }

  absl::Status ResolvedPrivilege::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedPrivilege::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedPrivilegeProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedPrivilege>> ResolvedPrivilege::RestoreFrom(
                                                                                    const ResolvedPrivilegeProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedPrivilege::GetChildNodes(
                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedPrivilege::AddMutableChildNodePointers(
                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedPrivilege::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedPrivilege::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedPrivilege::CollectDebugStringFields(
                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedPrivilege::CheckFieldsAccessedImpl(
                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedPrivilege::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedPrivilege::ClearFieldsAccessed() const {
  }

  void ResolvedPrivilege::MarkFieldsAccessed() const {
  }

  ResolvedGrantOrRevokeStmt::~ResolvedGrantOrRevokeStmt() {
  }

  absl::Status ResolvedGrantOrRevokeStmt::SaveTo(
                                                 Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                 AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedGrantOrRevokeStmt::SaveTo(
                                                 Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                 ResolvedGrantOrRevokeStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedGrantOrRevokeStmt>> ResolvedGrantOrRevokeStmt::RestoreFrom(
                                                                                                    const AnyResolvedGrantOrRevokeStmtProto& proto,
                                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedGrantOrRevokeStmt::GetChildNodes(
                                                std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedGrantOrRevokeStmt::AddMutableChildNodePointers(
                                                              std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                              mutable_child_node_ptrs) {
  }

  absl::Status ResolvedGrantOrRevokeStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedGrantOrRevokeStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedGrantOrRevokeStmt::CollectDebugStringFields(
                                                           std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedGrantOrRevokeStmt::CheckFieldsAccessedImpl(
                                                                  const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedGrantOrRevokeStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedGrantOrRevokeStmt::ClearFieldsAccessed() const {
  }

  void ResolvedGrantOrRevokeStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedGrantStmt::TYPE;

  ResolvedGrantStmt::~ResolvedGrantStmt() {
  }

  absl::Status ResolvedGrantStmt::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedGrantOrRevokeStmtProto* proto) const {
  }

  absl::Status ResolvedGrantStmt::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedGrantStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedGrantStmt>> ResolvedGrantStmt::RestoreFrom(
                                                                                    const ResolvedGrantStmtProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedGrantStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedGrantStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedRevokeStmt::TYPE;

  ResolvedRevokeStmt::~ResolvedRevokeStmt() {
  }

  absl::Status ResolvedRevokeStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedGrantOrRevokeStmtProto* proto) const {
  }

  absl::Status ResolvedRevokeStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedRevokeStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedRevokeStmt>> ResolvedRevokeStmt::RestoreFrom(
                                                                                      const ResolvedRevokeStmtProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedRevokeStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedRevokeStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  ResolvedAlterObjectStmt::~ResolvedAlterObjectStmt() {
  }

  absl::Status ResolvedAlterObjectStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedAlterObjectStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedAlterObjectStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterObjectStmt>> ResolvedAlterObjectStmt::RestoreFrom(
                                                                                                const AnyResolvedAlterObjectStmtProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAlterObjectStmt::GetChildNodes(
                                              std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAlterObjectStmt::AddMutableChildNodePointers(
                                                            std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                            mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAlterObjectStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterObjectStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAlterObjectStmt::CollectDebugStringFields(
                                                         std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAlterObjectStmt::CheckFieldsAccessedImpl(
                                                                const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAlterObjectStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAlterObjectStmt::ClearFieldsAccessed() const {
  }

  void ResolvedAlterObjectStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAlterDatabaseStmt::TYPE;

  ResolvedAlterDatabaseStmt::~ResolvedAlterDatabaseStmt() {
  }

  absl::Status ResolvedAlterDatabaseStmt::SaveTo(
                                                 Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                 AnyResolvedAlterObjectStmtProto* proto) const {
  }

  absl::Status ResolvedAlterDatabaseStmt::SaveTo(
                                                 Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                 ResolvedAlterDatabaseStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterDatabaseStmt>> ResolvedAlterDatabaseStmt::RestoreFrom(
                                                                                                    const ResolvedAlterDatabaseStmtProto& proto,
                                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedAlterDatabaseStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterDatabaseStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedAlterMaterializedViewStmt::TYPE;

  ResolvedAlterMaterializedViewStmt::~ResolvedAlterMaterializedViewStmt() {
  }

  absl::Status ResolvedAlterMaterializedViewStmt::SaveTo(
                                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                         AnyResolvedAlterObjectStmtProto* proto) const {
  }

  absl::Status ResolvedAlterMaterializedViewStmt::SaveTo(
                                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                         ResolvedAlterMaterializedViewStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterMaterializedViewStmt>> ResolvedAlterMaterializedViewStmt::RestoreFrom(
                                                                                                                    const ResolvedAlterMaterializedViewStmtProto& proto,
                                                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedAlterMaterializedViewStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterMaterializedViewStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedAlterSchemaStmt::TYPE;

  ResolvedAlterSchemaStmt::~ResolvedAlterSchemaStmt() {
  }

  absl::Status ResolvedAlterSchemaStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedAlterObjectStmtProto* proto) const {
  }

  absl::Status ResolvedAlterSchemaStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedAlterSchemaStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterSchemaStmt>> ResolvedAlterSchemaStmt::RestoreFrom(
                                                                                                const ResolvedAlterSchemaStmtProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedAlterSchemaStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterSchemaStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedAlterTableStmt::TYPE;

  ResolvedAlterTableStmt::~ResolvedAlterTableStmt() {
  }

  absl::Status ResolvedAlterTableStmt::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              AnyResolvedAlterObjectStmtProto* proto) const {
  }

  absl::Status ResolvedAlterTableStmt::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              ResolvedAlterTableStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterTableStmt>> ResolvedAlterTableStmt::RestoreFrom(
                                                                                              const ResolvedAlterTableStmtProto& proto,
                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedAlterTableStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterTableStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedAlterViewStmt::TYPE;

  ResolvedAlterViewStmt::~ResolvedAlterViewStmt() {
  }

  absl::Status ResolvedAlterViewStmt::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             AnyResolvedAlterObjectStmtProto* proto) const {
  }

  absl::Status ResolvedAlterViewStmt::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             ResolvedAlterViewStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterViewStmt>> ResolvedAlterViewStmt::RestoreFrom(
                                                                                            const ResolvedAlterViewStmtProto& proto,
                                                                                            const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedAlterViewStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterViewStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  ResolvedAlterAction::~ResolvedAlterAction() {
  }

  absl::Status ResolvedAlterAction::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedAlterAction::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           ResolvedAlterActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterAction>> ResolvedAlterAction::RestoreFrom(
                                                                                        const AnyResolvedAlterActionProto& proto,
                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedAlterAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  ResolvedAlterColumnAction::~ResolvedAlterColumnAction() {
  }

  absl::Status ResolvedAlterColumnAction::SaveTo(
                                                 Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                 AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedAlterColumnAction::SaveTo(
                                                 Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                 ResolvedAlterColumnActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterColumnAction>> ResolvedAlterColumnAction::RestoreFrom(
                                                                                                    const AnyResolvedAlterColumnActionProto& proto,
                                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAlterColumnAction::GetChildNodes(
                                                std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAlterColumnAction::AddMutableChildNodePointers(
                                                              std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                              mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAlterColumnAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterColumnAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAlterColumnAction::CollectDebugStringFields(
                                                           std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAlterColumnAction::CheckFieldsAccessedImpl(
                                                                  const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAlterColumnAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAlterColumnAction::ClearFieldsAccessed() const {
  }

  void ResolvedAlterColumnAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedSetOptionsAction::TYPE;

  ResolvedSetOptionsAction::~ResolvedSetOptionsAction() {
  }

  absl::Status ResolvedSetOptionsAction::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedSetOptionsAction::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedSetOptionsActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedSetOptionsAction>> ResolvedSetOptionsAction::RestoreFrom(
                                                                                                  const ResolvedSetOptionsActionProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedSetOptionsAction::GetChildNodes(
                                               std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedSetOptionsAction::AddMutableChildNodePointers(
                                                             std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                             mutable_child_node_ptrs) {
  }

  absl::Status ResolvedSetOptionsAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedSetOptionsAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedSetOptionsAction::CollectDebugStringFields(
                                                          std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedSetOptionsAction::CheckFieldsAccessedImpl(
                                                                 const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedSetOptionsAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedSetOptionsAction::ClearFieldsAccessed() const {
  }

  void ResolvedSetOptionsAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAddColumnAction::TYPE;

  ResolvedAddColumnAction::~ResolvedAddColumnAction() {
  }

  absl::Status ResolvedAddColumnAction::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedAddColumnAction::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedAddColumnActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAddColumnAction>> ResolvedAddColumnAction::RestoreFrom(
                                                                                                const ResolvedAddColumnActionProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAddColumnAction::GetChildNodes(
                                              std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAddColumnAction::AddMutableChildNodePointers(
                                                            std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                            mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAddColumnAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAddColumnAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAddColumnAction::CollectDebugStringFields(
                                                         std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAddColumnAction::CheckFieldsAccessedImpl(
                                                                const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAddColumnAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAddColumnAction::ClearFieldsAccessed() const {
  }

  void ResolvedAddColumnAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAddConstraintAction::TYPE;

  ResolvedAddConstraintAction::~ResolvedAddConstraintAction() {
  }

  absl::Status ResolvedAddConstraintAction::SaveTo(
                                                   Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                   AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedAddConstraintAction::SaveTo(
                                                   Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                   ResolvedAddConstraintActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAddConstraintAction>> ResolvedAddConstraintAction::RestoreFrom(
                                                                                                        const ResolvedAddConstraintActionProto& proto,
                                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAddConstraintAction::GetChildNodes(
                                                  std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAddConstraintAction::AddMutableChildNodePointers(
                                                                std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAddConstraintAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAddConstraintAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAddConstraintAction::CollectDebugStringFields(
                                                             std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAddConstraintAction::CheckFieldsAccessedImpl(
                                                                    const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAddConstraintAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAddConstraintAction::ClearFieldsAccessed() const {
  }

  void ResolvedAddConstraintAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedDropConstraintAction::TYPE;

  ResolvedDropConstraintAction::~ResolvedDropConstraintAction() {
  }

  absl::Status ResolvedDropConstraintAction::SaveTo(
                                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                    AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedDropConstraintAction::SaveTo(
                                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                    ResolvedDropConstraintActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDropConstraintAction>> ResolvedDropConstraintAction::RestoreFrom(
                                                                                                          const ResolvedDropConstraintActionProto& proto,
                                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDropConstraintAction::GetChildNodes(
                                                   std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDropConstraintAction::AddMutableChildNodePointers(
                                                                 std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                 mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDropConstraintAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDropConstraintAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDropConstraintAction::CollectDebugStringFields(
                                                              std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDropConstraintAction::CheckFieldsAccessedImpl(
                                                                     const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDropConstraintAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDropConstraintAction::ClearFieldsAccessed() const {
  }

  void ResolvedDropConstraintAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedDropPrimaryKeyAction::TYPE;

  ResolvedDropPrimaryKeyAction::~ResolvedDropPrimaryKeyAction() {
  }

  absl::Status ResolvedDropPrimaryKeyAction::SaveTo(
                                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                    AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedDropPrimaryKeyAction::SaveTo(
                                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                    ResolvedDropPrimaryKeyActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDropPrimaryKeyAction>> ResolvedDropPrimaryKeyAction::RestoreFrom(
                                                                                                          const ResolvedDropPrimaryKeyActionProto& proto,
                                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDropPrimaryKeyAction::GetChildNodes(
                                                   std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDropPrimaryKeyAction::AddMutableChildNodePointers(
                                                                 std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                 mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDropPrimaryKeyAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDropPrimaryKeyAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDropPrimaryKeyAction::CollectDebugStringFields(
                                                              std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDropPrimaryKeyAction::CheckFieldsAccessedImpl(
                                                                     const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDropPrimaryKeyAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDropPrimaryKeyAction::ClearFieldsAccessed() const {
  }

  void ResolvedDropPrimaryKeyAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAlterColumnOptionsAction::TYPE;

  ResolvedAlterColumnOptionsAction::~ResolvedAlterColumnOptionsAction() {
  }

  absl::Status ResolvedAlterColumnOptionsAction::SaveTo(
                                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                        AnyResolvedAlterColumnActionProto* proto) const {
  }

  absl::Status ResolvedAlterColumnOptionsAction::SaveTo(
                                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                        ResolvedAlterColumnOptionsActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterColumnOptionsAction>> ResolvedAlterColumnOptionsAction::RestoreFrom(
                                                                                                                  const ResolvedAlterColumnOptionsActionProto& proto,
                                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAlterColumnOptionsAction::GetChildNodes(
                                                       std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAlterColumnOptionsAction::AddMutableChildNodePointers(
                                                                     std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                     mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAlterColumnOptionsAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterColumnOptionsAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAlterColumnOptionsAction::CollectDebugStringFields(
                                                                  std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAlterColumnOptionsAction::CheckFieldsAccessedImpl(
                                                                         const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAlterColumnOptionsAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAlterColumnOptionsAction::ClearFieldsAccessed() const {
  }

  void ResolvedAlterColumnOptionsAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAlterColumnDropNotNullAction::TYPE;

  ResolvedAlterColumnDropNotNullAction::~ResolvedAlterColumnDropNotNullAction() {
  }

  absl::Status ResolvedAlterColumnDropNotNullAction::SaveTo(
                                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                            AnyResolvedAlterColumnActionProto* proto) const {
  }

  absl::Status ResolvedAlterColumnDropNotNullAction::SaveTo(
                                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                            ResolvedAlterColumnDropNotNullActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterColumnDropNotNullAction>> ResolvedAlterColumnDropNotNullAction::RestoreFrom(
                                                                                                                          const ResolvedAlterColumnDropNotNullActionProto& proto,
                                                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedAlterColumnDropNotNullAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterColumnDropNotNullAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedAlterColumnSetDataTypeAction::TYPE;

  ResolvedAlterColumnSetDataTypeAction::~ResolvedAlterColumnSetDataTypeAction() {
  }

  absl::Status ResolvedAlterColumnSetDataTypeAction::SaveTo(
                                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                            AnyResolvedAlterColumnActionProto* proto) const {
  }

  absl::Status ResolvedAlterColumnSetDataTypeAction::SaveTo(
                                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                            ResolvedAlterColumnSetDataTypeActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterColumnSetDataTypeAction>> ResolvedAlterColumnSetDataTypeAction::RestoreFrom(
                                                                                                                          const ResolvedAlterColumnSetDataTypeActionProto& proto,
                                                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAlterColumnSetDataTypeAction::GetChildNodes(
                                                           std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAlterColumnSetDataTypeAction::AddMutableChildNodePointers(
                                                                         std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                         mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAlterColumnSetDataTypeAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterColumnSetDataTypeAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAlterColumnSetDataTypeAction::CollectDebugStringFields(
                                                                      std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAlterColumnSetDataTypeAction::CheckFieldsAccessedImpl(
                                                                             const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAlterColumnSetDataTypeAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAlterColumnSetDataTypeAction::ClearFieldsAccessed() const {
  }

  void ResolvedAlterColumnSetDataTypeAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAlterColumnSetDefaultAction::TYPE;

  ResolvedAlterColumnSetDefaultAction::~ResolvedAlterColumnSetDefaultAction() {
  }

  absl::Status ResolvedAlterColumnSetDefaultAction::SaveTo(
                                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                           AnyResolvedAlterColumnActionProto* proto) const {
  }

  absl::Status ResolvedAlterColumnSetDefaultAction::SaveTo(
                                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                           ResolvedAlterColumnSetDefaultActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterColumnSetDefaultAction>> ResolvedAlterColumnSetDefaultAction::RestoreFrom(
                                                                                                                        const ResolvedAlterColumnSetDefaultActionProto& proto,
                                                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAlterColumnSetDefaultAction::GetChildNodes(
                                                          std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAlterColumnSetDefaultAction::AddMutableChildNodePointers(
                                                                        std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                        mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAlterColumnSetDefaultAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterColumnSetDefaultAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAlterColumnSetDefaultAction::CollectDebugStringFields(
                                                                     std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAlterColumnSetDefaultAction::CheckFieldsAccessedImpl(
                                                                            const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAlterColumnSetDefaultAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAlterColumnSetDefaultAction::ClearFieldsAccessed() const {
  }

  void ResolvedAlterColumnSetDefaultAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAlterColumnDropDefaultAction::TYPE;

  ResolvedAlterColumnDropDefaultAction::~ResolvedAlterColumnDropDefaultAction() {
  }

  absl::Status ResolvedAlterColumnDropDefaultAction::SaveTo(
                                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                            AnyResolvedAlterColumnActionProto* proto) const {
  }

  absl::Status ResolvedAlterColumnDropDefaultAction::SaveTo(
                                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                            ResolvedAlterColumnDropDefaultActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterColumnDropDefaultAction>> ResolvedAlterColumnDropDefaultAction::RestoreFrom(
                                                                                                                          const ResolvedAlterColumnDropDefaultActionProto& proto,
                                                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  absl::Status ResolvedAlterColumnDropDefaultAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterColumnDropDefaultAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  const ResolvedNodeKind ResolvedDropColumnAction::TYPE;

  ResolvedDropColumnAction::~ResolvedDropColumnAction() {
  }

  absl::Status ResolvedDropColumnAction::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedDropColumnAction::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedDropColumnActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDropColumnAction>> ResolvedDropColumnAction::RestoreFrom(
                                                                                                  const ResolvedDropColumnActionProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDropColumnAction::GetChildNodes(
                                               std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDropColumnAction::AddMutableChildNodePointers(
                                                             std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                             mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDropColumnAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDropColumnAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDropColumnAction::CollectDebugStringFields(
                                                          std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDropColumnAction::CheckFieldsAccessedImpl(
                                                                 const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDropColumnAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDropColumnAction::ClearFieldsAccessed() const {
  }

  void ResolvedDropColumnAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedRenameColumnAction::TYPE;

  ResolvedRenameColumnAction::~ResolvedRenameColumnAction() {
  }

  absl::Status ResolvedRenameColumnAction::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedRenameColumnAction::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  ResolvedRenameColumnActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedRenameColumnAction>> ResolvedRenameColumnAction::RestoreFrom(
                                                                                                      const ResolvedRenameColumnActionProto& proto,
                                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedRenameColumnAction::GetChildNodes(
                                                 std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedRenameColumnAction::AddMutableChildNodePointers(
                                                               std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                               mutable_child_node_ptrs) {
  }

  absl::Status ResolvedRenameColumnAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedRenameColumnAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedRenameColumnAction::CollectDebugStringFields(
                                                            std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedRenameColumnAction::CheckFieldsAccessedImpl(
                                                                   const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedRenameColumnAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedRenameColumnAction::ClearFieldsAccessed() const {
  }

  void ResolvedRenameColumnAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedSetAsAction::TYPE;

  ResolvedSetAsAction::~ResolvedSetAsAction() {
  }

  absl::Status ResolvedSetAsAction::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedSetAsAction::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           ResolvedSetAsActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedSetAsAction>> ResolvedSetAsAction::RestoreFrom(
                                                                                        const ResolvedSetAsActionProto& proto,
                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedSetAsAction::GetChildNodes(
                                          std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedSetAsAction::AddMutableChildNodePointers(
                                                        std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                        mutable_child_node_ptrs) {
  }

  absl::Status ResolvedSetAsAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedSetAsAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedSetAsAction::CollectDebugStringFields(
                                                     std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedSetAsAction::CheckFieldsAccessedImpl(
                                                            const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedSetAsAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedSetAsAction::ClearFieldsAccessed() const {
  }

  void ResolvedSetAsAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedSetCollateClause::TYPE;

  ResolvedSetCollateClause::~ResolvedSetCollateClause() {
  }

  absl::Status ResolvedSetCollateClause::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedSetCollateClause::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedSetCollateClauseProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedSetCollateClause>> ResolvedSetCollateClause::RestoreFrom(
                                                                                                  const ResolvedSetCollateClauseProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedSetCollateClause::GetChildNodes(
                                               std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedSetCollateClause::AddMutableChildNodePointers(
                                                             std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                             mutable_child_node_ptrs) {
  }

  absl::Status ResolvedSetCollateClause::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedSetCollateClause::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedSetCollateClause::CollectDebugStringFields(
                                                          std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedSetCollateClause::CheckFieldsAccessedImpl(
                                                                 const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedSetCollateClause::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedSetCollateClause::ClearFieldsAccessed() const {
  }

  void ResolvedSetCollateClause::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAlterTableSetOptionsStmt::TYPE;

  ResolvedAlterTableSetOptionsStmt::~ResolvedAlterTableSetOptionsStmt() {
  }

  absl::Status ResolvedAlterTableSetOptionsStmt::SaveTo(
                                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                        AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedAlterTableSetOptionsStmt::SaveTo(
                                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                        ResolvedAlterTableSetOptionsStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterTableSetOptionsStmt>> ResolvedAlterTableSetOptionsStmt::RestoreFrom(
                                                                                                                  const ResolvedAlterTableSetOptionsStmtProto& proto,
                                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAlterTableSetOptionsStmt::GetChildNodes(
                                                       std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAlterTableSetOptionsStmt::AddMutableChildNodePointers(
                                                                     std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                     mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAlterTableSetOptionsStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterTableSetOptionsStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAlterTableSetOptionsStmt::CollectDebugStringFields(
                                                                  std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAlterTableSetOptionsStmt::CheckFieldsAccessedImpl(
                                                                         const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAlterTableSetOptionsStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAlterTableSetOptionsStmt::ClearFieldsAccessed() const {
  }

  void ResolvedAlterTableSetOptionsStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedRenameStmt::TYPE;

  ResolvedRenameStmt::~ResolvedRenameStmt() {
  }

  absl::Status ResolvedRenameStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedRenameStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedRenameStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedRenameStmt>> ResolvedRenameStmt::RestoreFrom(
                                                                                      const ResolvedRenameStmtProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedRenameStmt::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedRenameStmt::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedRenameStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedRenameStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedRenameStmt::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedRenameStmt::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedRenameStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedRenameStmt::ClearFieldsAccessed() const {
  }

  void ResolvedRenameStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreatePrivilegeRestrictionStmt::TYPE;

  ResolvedCreatePrivilegeRestrictionStmt::~ResolvedCreatePrivilegeRestrictionStmt() {
  }

  absl::Status ResolvedCreatePrivilegeRestrictionStmt::SaveTo(
                                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                              AnyResolvedCreateStatementProto* proto) const {
  }

  absl::Status ResolvedCreatePrivilegeRestrictionStmt::SaveTo(
                                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                              ResolvedCreatePrivilegeRestrictionStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreatePrivilegeRestrictionStmt>> ResolvedCreatePrivilegeRestrictionStmt::RestoreFrom(
                                                                                                                              const ResolvedCreatePrivilegeRestrictionStmtProto& proto,
                                                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreatePrivilegeRestrictionStmt::GetChildNodes(
                                                             std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreatePrivilegeRestrictionStmt::AddMutableChildNodePointers(
                                                                           std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                           mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreatePrivilegeRestrictionStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreatePrivilegeRestrictionStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreatePrivilegeRestrictionStmt::CollectDebugStringFields(
                                                                        std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreatePrivilegeRestrictionStmt::CheckFieldsAccessedImpl(
                                                                               const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreatePrivilegeRestrictionStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreatePrivilegeRestrictionStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreatePrivilegeRestrictionStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateRowAccessPolicyStmt::TYPE;

  ResolvedCreateRowAccessPolicyStmt::~ResolvedCreateRowAccessPolicyStmt() {
  }

  absl::Status ResolvedCreateRowAccessPolicyStmt::SaveTo(
                                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                         AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedCreateRowAccessPolicyStmt::SaveTo(
                                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                         ResolvedCreateRowAccessPolicyStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateRowAccessPolicyStmt>> ResolvedCreateRowAccessPolicyStmt::RestoreFrom(
                                                                                                                    const ResolvedCreateRowAccessPolicyStmtProto& proto,
                                                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateRowAccessPolicyStmt::GetChildNodes(
                                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateRowAccessPolicyStmt::AddMutableChildNodePointers(
                                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateRowAccessPolicyStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateRowAccessPolicyStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateRowAccessPolicyStmt::CollectDebugStringFields(
                                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateRowAccessPolicyStmt::CheckFieldsAccessedImpl(
                                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateRowAccessPolicyStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateRowAccessPolicyStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreateRowAccessPolicyStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedDropPrivilegeRestrictionStmt::TYPE;

  ResolvedDropPrivilegeRestrictionStmt::~ResolvedDropPrivilegeRestrictionStmt() {
  }

  absl::Status ResolvedDropPrivilegeRestrictionStmt::SaveTo(
                                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                            AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedDropPrivilegeRestrictionStmt::SaveTo(
                                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                            ResolvedDropPrivilegeRestrictionStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDropPrivilegeRestrictionStmt>> ResolvedDropPrivilegeRestrictionStmt::RestoreFrom(
                                                                                                                          const ResolvedDropPrivilegeRestrictionStmtProto& proto,
                                                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDropPrivilegeRestrictionStmt::GetChildNodes(
                                                           std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDropPrivilegeRestrictionStmt::AddMutableChildNodePointers(
                                                                         std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                         mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDropPrivilegeRestrictionStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDropPrivilegeRestrictionStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDropPrivilegeRestrictionStmt::CollectDebugStringFields(
                                                                      std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDropPrivilegeRestrictionStmt::CheckFieldsAccessedImpl(
                                                                             const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDropPrivilegeRestrictionStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDropPrivilegeRestrictionStmt::ClearFieldsAccessed() const {
  }

  void ResolvedDropPrivilegeRestrictionStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedDropRowAccessPolicyStmt::TYPE;

  ResolvedDropRowAccessPolicyStmt::~ResolvedDropRowAccessPolicyStmt() {
  }

  absl::Status ResolvedDropRowAccessPolicyStmt::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedDropRowAccessPolicyStmt::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       ResolvedDropRowAccessPolicyStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDropRowAccessPolicyStmt>> ResolvedDropRowAccessPolicyStmt::RestoreFrom(
                                                                                                                const ResolvedDropRowAccessPolicyStmtProto& proto,
                                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDropRowAccessPolicyStmt::GetChildNodes(
                                                      std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDropRowAccessPolicyStmt::AddMutableChildNodePointers(
                                                                    std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                    mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDropRowAccessPolicyStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDropRowAccessPolicyStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDropRowAccessPolicyStmt::CollectDebugStringFields(
                                                                 std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDropRowAccessPolicyStmt::CheckFieldsAccessedImpl(
                                                                        const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDropRowAccessPolicyStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDropRowAccessPolicyStmt::ClearFieldsAccessed() const {
  }

  void ResolvedDropRowAccessPolicyStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedDropSearchIndexStmt::TYPE;

  ResolvedDropSearchIndexStmt::~ResolvedDropSearchIndexStmt() {
  }

  absl::Status ResolvedDropSearchIndexStmt::SaveTo(
                                                   Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                   AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedDropSearchIndexStmt::SaveTo(
                                                   Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                   ResolvedDropSearchIndexStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDropSearchIndexStmt>> ResolvedDropSearchIndexStmt::RestoreFrom(
                                                                                                        const ResolvedDropSearchIndexStmtProto& proto,
                                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDropSearchIndexStmt::GetChildNodes(
                                                  std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDropSearchIndexStmt::AddMutableChildNodePointers(
                                                                std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDropSearchIndexStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDropSearchIndexStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDropSearchIndexStmt::CollectDebugStringFields(
                                                             std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDropSearchIndexStmt::CheckFieldsAccessedImpl(
                                                                    const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDropSearchIndexStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDropSearchIndexStmt::ClearFieldsAccessed() const {
  }

  void ResolvedDropSearchIndexStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedGrantToAction::TYPE;

  ResolvedGrantToAction::~ResolvedGrantToAction() {
  }

  absl::Status ResolvedGrantToAction::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedGrantToAction::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             ResolvedGrantToActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedGrantToAction>> ResolvedGrantToAction::RestoreFrom(
                                                                                            const ResolvedGrantToActionProto& proto,
                                                                                            const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedGrantToAction::GetChildNodes(
                                            std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedGrantToAction::AddMutableChildNodePointers(
                                                          std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                          mutable_child_node_ptrs) {
  }

  absl::Status ResolvedGrantToAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedGrantToAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedGrantToAction::CollectDebugStringFields(
                                                       std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedGrantToAction::CheckFieldsAccessedImpl(
                                                              const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedGrantToAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedGrantToAction::ClearFieldsAccessed() const {
  }

  void ResolvedGrantToAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedRestrictToAction::TYPE;

  ResolvedRestrictToAction::~ResolvedRestrictToAction() {
  }

  absl::Status ResolvedRestrictToAction::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedRestrictToAction::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedRestrictToActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedRestrictToAction>> ResolvedRestrictToAction::RestoreFrom(
                                                                                                  const ResolvedRestrictToActionProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedRestrictToAction::GetChildNodes(
                                               std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedRestrictToAction::AddMutableChildNodePointers(
                                                             std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                             mutable_child_node_ptrs) {
  }

  absl::Status ResolvedRestrictToAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedRestrictToAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedRestrictToAction::CollectDebugStringFields(
                                                          std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedRestrictToAction::CheckFieldsAccessedImpl(
                                                                 const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedRestrictToAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedRestrictToAction::ClearFieldsAccessed() const {
  }

  void ResolvedRestrictToAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAddToRestricteeListAction::TYPE;

  ResolvedAddToRestricteeListAction::~ResolvedAddToRestricteeListAction() {
  }

  absl::Status ResolvedAddToRestricteeListAction::SaveTo(
                                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                         AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedAddToRestricteeListAction::SaveTo(
                                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                         ResolvedAddToRestricteeListActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAddToRestricteeListAction>> ResolvedAddToRestricteeListAction::RestoreFrom(
                                                                                                                    const ResolvedAddToRestricteeListActionProto& proto,
                                                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAddToRestricteeListAction::GetChildNodes(
                                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAddToRestricteeListAction::AddMutableChildNodePointers(
                                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAddToRestricteeListAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAddToRestricteeListAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAddToRestricteeListAction::CollectDebugStringFields(
                                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAddToRestricteeListAction::CheckFieldsAccessedImpl(
                                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAddToRestricteeListAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAddToRestricteeListAction::ClearFieldsAccessed() const {
  }

  void ResolvedAddToRestricteeListAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedRemoveFromRestricteeListAction::TYPE;

  ResolvedRemoveFromRestricteeListAction::~ResolvedRemoveFromRestricteeListAction() {
  }

  absl::Status ResolvedRemoveFromRestricteeListAction::SaveTo(
                                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                              AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedRemoveFromRestricteeListAction::SaveTo(
                                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                              ResolvedRemoveFromRestricteeListActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedRemoveFromRestricteeListAction>> ResolvedRemoveFromRestricteeListAction::RestoreFrom(
                                                                                                                              const ResolvedRemoveFromRestricteeListActionProto& proto,
                                                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedRemoveFromRestricteeListAction::GetChildNodes(
                                                             std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedRemoveFromRestricteeListAction::AddMutableChildNodePointers(
                                                                           std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                           mutable_child_node_ptrs) {
  }

  absl::Status ResolvedRemoveFromRestricteeListAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedRemoveFromRestricteeListAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedRemoveFromRestricteeListAction::CollectDebugStringFields(
                                                                        std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedRemoveFromRestricteeListAction::CheckFieldsAccessedImpl(
                                                                               const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedRemoveFromRestricteeListAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedRemoveFromRestricteeListAction::ClearFieldsAccessed() const {
  }

  void ResolvedRemoveFromRestricteeListAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedFilterUsingAction::TYPE;

  ResolvedFilterUsingAction::~ResolvedFilterUsingAction() {
  }

  absl::Status ResolvedFilterUsingAction::SaveTo(
                                                 Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                 AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedFilterUsingAction::SaveTo(
                                                 Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                 ResolvedFilterUsingActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedFilterUsingAction>> ResolvedFilterUsingAction::RestoreFrom(
                                                                                                    const ResolvedFilterUsingActionProto& proto,
                                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedFilterUsingAction::GetChildNodes(
                                                std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedFilterUsingAction::AddMutableChildNodePointers(
                                                              std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                              mutable_child_node_ptrs) {
  }

  absl::Status ResolvedFilterUsingAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedFilterUsingAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedFilterUsingAction::CollectDebugStringFields(
                                                           std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedFilterUsingAction::CheckFieldsAccessedImpl(
                                                                  const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedFilterUsingAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedFilterUsingAction::ClearFieldsAccessed() const {
  }

  void ResolvedFilterUsingAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedRevokeFromAction::TYPE;

  ResolvedRevokeFromAction::~ResolvedRevokeFromAction() {
  }

  absl::Status ResolvedRevokeFromAction::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedRevokeFromAction::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedRevokeFromActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedRevokeFromAction>> ResolvedRevokeFromAction::RestoreFrom(
                                                                                                  const ResolvedRevokeFromActionProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedRevokeFromAction::GetChildNodes(
                                               std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedRevokeFromAction::AddMutableChildNodePointers(
                                                             std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                             mutable_child_node_ptrs) {
  }

  absl::Status ResolvedRevokeFromAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedRevokeFromAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedRevokeFromAction::CollectDebugStringFields(
                                                          std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedRevokeFromAction::CheckFieldsAccessedImpl(
                                                                 const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedRevokeFromAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedRevokeFromAction::ClearFieldsAccessed() const {
  }

  void ResolvedRevokeFromAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedRenameToAction::TYPE;

  ResolvedRenameToAction::~ResolvedRenameToAction() {
  }

  absl::Status ResolvedRenameToAction::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              AnyResolvedAlterActionProto* proto) const {
  }

  absl::Status ResolvedRenameToAction::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              ResolvedRenameToActionProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedRenameToAction>> ResolvedRenameToAction::RestoreFrom(
                                                                                              const ResolvedRenameToActionProto& proto,
                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedRenameToAction::GetChildNodes(
                                             std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedRenameToAction::AddMutableChildNodePointers(
                                                           std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                           mutable_child_node_ptrs) {
  }

  absl::Status ResolvedRenameToAction::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedRenameToAction::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedRenameToAction::CollectDebugStringFields(
                                                        std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedRenameToAction::CheckFieldsAccessedImpl(
                                                               const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedRenameToAction::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedRenameToAction::ClearFieldsAccessed() const {
  }

  void ResolvedRenameToAction::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAlterPrivilegeRestrictionStmt::TYPE;

  ResolvedAlterPrivilegeRestrictionStmt::~ResolvedAlterPrivilegeRestrictionStmt() {
  }

  absl::Status ResolvedAlterPrivilegeRestrictionStmt::SaveTo(
                                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                             AnyResolvedAlterObjectStmtProto* proto) const {
  }

  absl::Status ResolvedAlterPrivilegeRestrictionStmt::SaveTo(
                                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                             ResolvedAlterPrivilegeRestrictionStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterPrivilegeRestrictionStmt>> ResolvedAlterPrivilegeRestrictionStmt::RestoreFrom(
                                                                                                                            const ResolvedAlterPrivilegeRestrictionStmtProto& proto,
                                                                                                                            const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAlterPrivilegeRestrictionStmt::GetChildNodes(
                                                            std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAlterPrivilegeRestrictionStmt::AddMutableChildNodePointers(
                                                                          std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                          mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAlterPrivilegeRestrictionStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterPrivilegeRestrictionStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAlterPrivilegeRestrictionStmt::CollectDebugStringFields(
                                                                       std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAlterPrivilegeRestrictionStmt::CheckFieldsAccessedImpl(
                                                                              const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAlterPrivilegeRestrictionStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAlterPrivilegeRestrictionStmt::ClearFieldsAccessed() const {
  }

  void ResolvedAlterPrivilegeRestrictionStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAlterRowAccessPolicyStmt::TYPE;

  ResolvedAlterRowAccessPolicyStmt::~ResolvedAlterRowAccessPolicyStmt() {
  }

  absl::Status ResolvedAlterRowAccessPolicyStmt::SaveTo(
                                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                        AnyResolvedAlterObjectStmtProto* proto) const {
  }

  absl::Status ResolvedAlterRowAccessPolicyStmt::SaveTo(
                                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                        ResolvedAlterRowAccessPolicyStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterRowAccessPolicyStmt>> ResolvedAlterRowAccessPolicyStmt::RestoreFrom(
                                                                                                                  const ResolvedAlterRowAccessPolicyStmtProto& proto,
                                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAlterRowAccessPolicyStmt::GetChildNodes(
                                                       std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAlterRowAccessPolicyStmt::AddMutableChildNodePointers(
                                                                     std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                     mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAlterRowAccessPolicyStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterRowAccessPolicyStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAlterRowAccessPolicyStmt::CollectDebugStringFields(
                                                                  std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAlterRowAccessPolicyStmt::CheckFieldsAccessedImpl(
                                                                         const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAlterRowAccessPolicyStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAlterRowAccessPolicyStmt::ClearFieldsAccessed() const {
  }

  void ResolvedAlterRowAccessPolicyStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAlterAllRowAccessPoliciesStmt::TYPE;

  ResolvedAlterAllRowAccessPoliciesStmt::~ResolvedAlterAllRowAccessPoliciesStmt() {
  }

  absl::Status ResolvedAlterAllRowAccessPoliciesStmt::SaveTo(
                                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                             AnyResolvedAlterObjectStmtProto* proto) const {
  }

  absl::Status ResolvedAlterAllRowAccessPoliciesStmt::SaveTo(
                                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                             ResolvedAlterAllRowAccessPoliciesStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterAllRowAccessPoliciesStmt>> ResolvedAlterAllRowAccessPoliciesStmt::RestoreFrom(
                                                                                                                            const ResolvedAlterAllRowAccessPoliciesStmtProto& proto,
                                                                                                                            const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAlterAllRowAccessPoliciesStmt::GetChildNodes(
                                                            std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAlterAllRowAccessPoliciesStmt::AddMutableChildNodePointers(
                                                                          std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                          mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAlterAllRowAccessPoliciesStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterAllRowAccessPoliciesStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAlterAllRowAccessPoliciesStmt::CollectDebugStringFields(
                                                                       std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAlterAllRowAccessPoliciesStmt::CheckFieldsAccessedImpl(
                                                                              const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAlterAllRowAccessPoliciesStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAlterAllRowAccessPoliciesStmt::ClearFieldsAccessed() const {
  }

  void ResolvedAlterAllRowAccessPoliciesStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateConstantStmt::TYPE;

  ResolvedCreateConstantStmt::~ResolvedCreateConstantStmt() {
  }

  absl::Status ResolvedCreateConstantStmt::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  AnyResolvedCreateStatementProto* proto) const {
  }

  absl::Status ResolvedCreateConstantStmt::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  ResolvedCreateConstantStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateConstantStmt>> ResolvedCreateConstantStmt::RestoreFrom(
                                                                                                      const ResolvedCreateConstantStmtProto& proto,
                                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateConstantStmt::GetChildNodes(
                                                 std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateConstantStmt::AddMutableChildNodePointers(
                                                               std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                               mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateConstantStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateConstantStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateConstantStmt::CollectDebugStringFields(
                                                            std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateConstantStmt::CheckFieldsAccessedImpl(
                                                                   const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateConstantStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateConstantStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreateConstantStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateFunctionStmt::TYPE;

  ResolvedCreateFunctionStmt::~ResolvedCreateFunctionStmt() {
  }

  absl::Status ResolvedCreateFunctionStmt::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  AnyResolvedCreateStatementProto* proto) const {
  }

  absl::Status ResolvedCreateFunctionStmt::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  ResolvedCreateFunctionStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateFunctionStmt>> ResolvedCreateFunctionStmt::RestoreFrom(
                                                                                                      const ResolvedCreateFunctionStmtProto& proto,
                                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateFunctionStmt::GetChildNodes(
                                                 std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateFunctionStmt::AddMutableChildNodePointers(
                                                               std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                               mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateFunctionStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateFunctionStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateFunctionStmt::CollectDebugStringFields(
                                                            std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateFunctionStmt::CheckFieldsAccessedImpl(
                                                                   const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateFunctionStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateFunctionStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreateFunctionStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedArgumentDef::TYPE;

  const ResolvedArgumentDef::ArgumentKind ResolvedArgumentDef::SCALAR;
  const ResolvedArgumentDef::ArgumentKind ResolvedArgumentDef::AGGREGATE;
  const ResolvedArgumentDef::ArgumentKind ResolvedArgumentDef::NOT_AGGREGATE;

  ResolvedArgumentDef::~ResolvedArgumentDef() {
  }

  absl::Status ResolvedArgumentDef::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedArgumentDef::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           ResolvedArgumentDefProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedArgumentDef>> ResolvedArgumentDef::RestoreFrom(
                                                                                        const ResolvedArgumentDefProto& proto,
                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedArgumentDef::GetChildNodes(
                                          std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedArgumentDef::AddMutableChildNodePointers(
                                                        std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                        mutable_child_node_ptrs) {
  }

  absl::Status ResolvedArgumentDef::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedArgumentDef::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedArgumentDef::CollectDebugStringFields(
                                                     std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedArgumentDef::CheckFieldsAccessedImpl(
                                                            const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedArgumentDef::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedArgumentDef::ClearFieldsAccessed() const {
  }

  void ResolvedArgumentDef::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedArgumentRef::TYPE;

  const ResolvedArgumentRef::ArgumentKind ResolvedArgumentRef::SCALAR;
  const ResolvedArgumentRef::ArgumentKind ResolvedArgumentRef::AGGREGATE;
  const ResolvedArgumentRef::ArgumentKind ResolvedArgumentRef::NOT_AGGREGATE;

  ResolvedArgumentRef::~ResolvedArgumentRef() {
  }

  absl::Status ResolvedArgumentRef::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           AnyResolvedExprProto* proto) const {
  }

  absl::Status ResolvedArgumentRef::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           ResolvedArgumentRefProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedArgumentRef>> ResolvedArgumentRef::RestoreFrom(
                                                                                        const ResolvedArgumentRefProto& proto,
                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedArgumentRef::GetChildNodes(
                                          std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedArgumentRef::AddMutableChildNodePointers(
                                                        std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                        mutable_child_node_ptrs) {
  }

  absl::Status ResolvedArgumentRef::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedArgumentRef::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedArgumentRef::CollectDebugStringFields(
                                                     std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedArgumentRef::CheckFieldsAccessedImpl(
                                                            const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedArgumentRef::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedArgumentRef::ClearFieldsAccessed() const {
  }

  void ResolvedArgumentRef::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateTableFunctionStmt::TYPE;

  ResolvedCreateTableFunctionStmt::~ResolvedCreateTableFunctionStmt() {
  }

  absl::Status ResolvedCreateTableFunctionStmt::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       AnyResolvedCreateStatementProto* proto) const {
  }

  absl::Status ResolvedCreateTableFunctionStmt::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       ResolvedCreateTableFunctionStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateTableFunctionStmt>> ResolvedCreateTableFunctionStmt::RestoreFrom(
                                                                                                                const ResolvedCreateTableFunctionStmtProto& proto,
                                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateTableFunctionStmt::GetChildNodes(
                                                      std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateTableFunctionStmt::AddMutableChildNodePointers(
                                                                    std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                    mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateTableFunctionStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateTableFunctionStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateTableFunctionStmt::CollectDebugStringFields(
                                                                 std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateTableFunctionStmt::CheckFieldsAccessedImpl(
                                                                        const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateTableFunctionStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateTableFunctionStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreateTableFunctionStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedRelationArgumentScan::TYPE;

  ResolvedRelationArgumentScan::~ResolvedRelationArgumentScan() {
  }

  absl::Status ResolvedRelationArgumentScan::SaveTo(
                                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                    AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedRelationArgumentScan::SaveTo(
                                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                    ResolvedRelationArgumentScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedRelationArgumentScan>> ResolvedRelationArgumentScan::RestoreFrom(
                                                                                                          const ResolvedRelationArgumentScanProto& proto,
                                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedRelationArgumentScan::GetChildNodes(
                                                   std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedRelationArgumentScan::AddMutableChildNodePointers(
                                                                 std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                 mutable_child_node_ptrs) {
  }

  absl::Status ResolvedRelationArgumentScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedRelationArgumentScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedRelationArgumentScan::CollectDebugStringFields(
                                                              std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedRelationArgumentScan::CheckFieldsAccessedImpl(
                                                                     const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedRelationArgumentScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedRelationArgumentScan::ClearFieldsAccessed() const {
  }

  void ResolvedRelationArgumentScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedArgumentList::TYPE;

  ResolvedArgumentList::~ResolvedArgumentList() {
  }

  absl::Status ResolvedArgumentList::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedArgumentList::SaveTo(
                                            Type::FileDescriptorSetMap* file_descriptor_set_map,
                                            ResolvedArgumentListProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedArgumentList>> ResolvedArgumentList::RestoreFrom(
                                                                                          const ResolvedArgumentListProto& proto,
                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedArgumentList::GetChildNodes(
                                           std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedArgumentList::AddMutableChildNodePointers(
                                                         std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                         mutable_child_node_ptrs) {
  }

  absl::Status ResolvedArgumentList::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedArgumentList::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedArgumentList::CollectDebugStringFields(
                                                      std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedArgumentList::CheckFieldsAccessedImpl(
                                                             const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedArgumentList::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedArgumentList::ClearFieldsAccessed() const {
  }

  void ResolvedArgumentList::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedFunctionSignatureHolder::TYPE;

  ResolvedFunctionSignatureHolder::~ResolvedFunctionSignatureHolder() {
  }

  absl::Status ResolvedFunctionSignatureHolder::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedFunctionSignatureHolder::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       ResolvedFunctionSignatureHolderProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedFunctionSignatureHolder>> ResolvedFunctionSignatureHolder::RestoreFrom(
                                                                                                                const ResolvedFunctionSignatureHolderProto& proto,
                                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedFunctionSignatureHolder::GetChildNodes(
                                                      std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedFunctionSignatureHolder::AddMutableChildNodePointers(
                                                                    std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                    mutable_child_node_ptrs) {
  }

  absl::Status ResolvedFunctionSignatureHolder::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedFunctionSignatureHolder::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedFunctionSignatureHolder::CollectDebugStringFields(
                                                                 std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedFunctionSignatureHolder::CheckFieldsAccessedImpl(
                                                                        const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedFunctionSignatureHolder::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedFunctionSignatureHolder::ClearFieldsAccessed() const {
  }

  void ResolvedFunctionSignatureHolder::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedDropFunctionStmt::TYPE;

  ResolvedDropFunctionStmt::~ResolvedDropFunctionStmt() {
  }

  absl::Status ResolvedDropFunctionStmt::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedDropFunctionStmt::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedDropFunctionStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDropFunctionStmt>> ResolvedDropFunctionStmt::RestoreFrom(
                                                                                                  const ResolvedDropFunctionStmtProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDropFunctionStmt::GetChildNodes(
                                               std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDropFunctionStmt::AddMutableChildNodePointers(
                                                             std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                             mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDropFunctionStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDropFunctionStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDropFunctionStmt::CollectDebugStringFields(
                                                          std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDropFunctionStmt::CheckFieldsAccessedImpl(
                                                                 const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDropFunctionStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDropFunctionStmt::ClearFieldsAccessed() const {
  }

  void ResolvedDropFunctionStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedDropTableFunctionStmt::TYPE;

  ResolvedDropTableFunctionStmt::~ResolvedDropTableFunctionStmt() {
  }

  absl::Status ResolvedDropTableFunctionStmt::SaveTo(
                                                     Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                     AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedDropTableFunctionStmt::SaveTo(
                                                     Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                     ResolvedDropTableFunctionStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedDropTableFunctionStmt>> ResolvedDropTableFunctionStmt::RestoreFrom(
                                                                                                            const ResolvedDropTableFunctionStmtProto& proto,
                                                                                                            const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedDropTableFunctionStmt::GetChildNodes(
                                                    std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedDropTableFunctionStmt::AddMutableChildNodePointers(
                                                                  std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                  mutable_child_node_ptrs) {
  }

  absl::Status ResolvedDropTableFunctionStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedDropTableFunctionStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedDropTableFunctionStmt::CollectDebugStringFields(
                                                               std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedDropTableFunctionStmt::CheckFieldsAccessedImpl(
                                                                      const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedDropTableFunctionStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedDropTableFunctionStmt::ClearFieldsAccessed() const {
  }

  void ResolvedDropTableFunctionStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCallStmt::TYPE;

  ResolvedCallStmt::~ResolvedCallStmt() {
  }

  absl::Status ResolvedCallStmt::SaveTo(
                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedCallStmt::SaveTo(
                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                        ResolvedCallStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCallStmt>> ResolvedCallStmt::RestoreFrom(
                                                                                  const ResolvedCallStmtProto& proto,
                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCallStmt::GetChildNodes(
                                       std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCallStmt::AddMutableChildNodePointers(
                                                     std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                     mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCallStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCallStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCallStmt::CollectDebugStringFields(
                                                  std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCallStmt::CheckFieldsAccessedImpl(
                                                         const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCallStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCallStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCallStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedImportStmt::TYPE;

  const ResolvedImportStmt::ImportKind ResolvedImportStmt::MODULE;
  const ResolvedImportStmt::ImportKind ResolvedImportStmt::PROTO;
  const ResolvedImportStmt::ImportKind ResolvedImportStmt::__ImportKind__switch_must_have_a_default__;

  ResolvedImportStmt::~ResolvedImportStmt() {
  }

  absl::Status ResolvedImportStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedImportStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedImportStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedImportStmt>> ResolvedImportStmt::RestoreFrom(
                                                                                      const ResolvedImportStmtProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedImportStmt::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedImportStmt::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedImportStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedImportStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedImportStmt::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedImportStmt::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedImportStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedImportStmt::ClearFieldsAccessed() const {
  }

  void ResolvedImportStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedModuleStmt::TYPE;

  ResolvedModuleStmt::~ResolvedModuleStmt() {
  }

  absl::Status ResolvedModuleStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedModuleStmt::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedModuleStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedModuleStmt>> ResolvedModuleStmt::RestoreFrom(
                                                                                      const ResolvedModuleStmtProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedModuleStmt::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedModuleStmt::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedModuleStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedModuleStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedModuleStmt::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedModuleStmt::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedModuleStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedModuleStmt::ClearFieldsAccessed() const {
  }

  void ResolvedModuleStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAggregateHavingModifier::TYPE;

  const ResolvedAggregateHavingModifier::HavingModifierKind ResolvedAggregateHavingModifier::INVALID;
  const ResolvedAggregateHavingModifier::HavingModifierKind ResolvedAggregateHavingModifier::MAX;
  const ResolvedAggregateHavingModifier::HavingModifierKind ResolvedAggregateHavingModifier::MIN;

  ResolvedAggregateHavingModifier::~ResolvedAggregateHavingModifier() {
  }

  absl::Status ResolvedAggregateHavingModifier::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedAggregateHavingModifier::SaveTo(
                                                       Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                       ResolvedAggregateHavingModifierProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAggregateHavingModifier>> ResolvedAggregateHavingModifier::RestoreFrom(
                                                                                                                const ResolvedAggregateHavingModifierProto& proto,
                                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAggregateHavingModifier::GetChildNodes(
                                                      std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAggregateHavingModifier::AddMutableChildNodePointers(
                                                                    std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                    mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAggregateHavingModifier::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAggregateHavingModifier::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAggregateHavingModifier::CollectDebugStringFields(
                                                                 std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAggregateHavingModifier::CheckFieldsAccessedImpl(
                                                                        const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAggregateHavingModifier::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAggregateHavingModifier::ClearFieldsAccessed() const {
  }

  void ResolvedAggregateHavingModifier::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateMaterializedViewStmt::TYPE;

  ResolvedCreateMaterializedViewStmt::~ResolvedCreateMaterializedViewStmt() {
  }

  absl::Status ResolvedCreateMaterializedViewStmt::SaveTo(
                                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                          AnyResolvedCreateViewBaseProto* proto) const {
  }

  absl::Status ResolvedCreateMaterializedViewStmt::SaveTo(
                                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                          ResolvedCreateMaterializedViewStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateMaterializedViewStmt>> ResolvedCreateMaterializedViewStmt::RestoreFrom(
                                                                                                                      const ResolvedCreateMaterializedViewStmtProto& proto,
                                                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateMaterializedViewStmt::GetChildNodes(
                                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateMaterializedViewStmt::AddMutableChildNodePointers(
                                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateMaterializedViewStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateMaterializedViewStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateMaterializedViewStmt::CollectDebugStringFields(
                                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateMaterializedViewStmt::CheckFieldsAccessedImpl(
                                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateMaterializedViewStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateMaterializedViewStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreateMaterializedViewStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateProcedureStmt::TYPE;

  ResolvedCreateProcedureStmt::~ResolvedCreateProcedureStmt() {
  }

  absl::Status ResolvedCreateProcedureStmt::SaveTo(
                                                   Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                   AnyResolvedCreateStatementProto* proto) const {
  }

  absl::Status ResolvedCreateProcedureStmt::SaveTo(
                                                   Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                   ResolvedCreateProcedureStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateProcedureStmt>> ResolvedCreateProcedureStmt::RestoreFrom(
                                                                                                        const ResolvedCreateProcedureStmtProto& proto,
                                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateProcedureStmt::GetChildNodes(
                                                  std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateProcedureStmt::AddMutableChildNodePointers(
                                                                std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateProcedureStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateProcedureStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateProcedureStmt::CollectDebugStringFields(
                                                             std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateProcedureStmt::CheckFieldsAccessedImpl(
                                                                    const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateProcedureStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateProcedureStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreateProcedureStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedExecuteImmediateArgument::TYPE;

  ResolvedExecuteImmediateArgument::~ResolvedExecuteImmediateArgument() {
  }

  absl::Status ResolvedExecuteImmediateArgument::SaveTo(
                                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                        AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedExecuteImmediateArgument::SaveTo(
                                                        Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                        ResolvedExecuteImmediateArgumentProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedExecuteImmediateArgument>> ResolvedExecuteImmediateArgument::RestoreFrom(
                                                                                                                  const ResolvedExecuteImmediateArgumentProto& proto,
                                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedExecuteImmediateArgument::GetChildNodes(
                                                       std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedExecuteImmediateArgument::AddMutableChildNodePointers(
                                                                     std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                     mutable_child_node_ptrs) {
  }

  absl::Status ResolvedExecuteImmediateArgument::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedExecuteImmediateArgument::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedExecuteImmediateArgument::CollectDebugStringFields(
                                                                  std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedExecuteImmediateArgument::CheckFieldsAccessedImpl(
                                                                         const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedExecuteImmediateArgument::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedExecuteImmediateArgument::ClearFieldsAccessed() const {
  }

  void ResolvedExecuteImmediateArgument::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedExecuteImmediateStmt::TYPE;

  ResolvedExecuteImmediateStmt::~ResolvedExecuteImmediateStmt() {
  }

  absl::Status ResolvedExecuteImmediateStmt::SaveTo(
                                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                    AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedExecuteImmediateStmt::SaveTo(
                                                    Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                    ResolvedExecuteImmediateStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedExecuteImmediateStmt>> ResolvedExecuteImmediateStmt::RestoreFrom(
                                                                                                          const ResolvedExecuteImmediateStmtProto& proto,
                                                                                                          const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedExecuteImmediateStmt::GetChildNodes(
                                                   std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedExecuteImmediateStmt::AddMutableChildNodePointers(
                                                                 std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                                 mutable_child_node_ptrs) {
  }

  absl::Status ResolvedExecuteImmediateStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedExecuteImmediateStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedExecuteImmediateStmt::CollectDebugStringFields(
                                                              std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedExecuteImmediateStmt::CheckFieldsAccessedImpl(
                                                                     const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedExecuteImmediateStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedExecuteImmediateStmt::ClearFieldsAccessed() const {
  }

  void ResolvedExecuteImmediateStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAssignmentStmt::TYPE;

  ResolvedAssignmentStmt::~ResolvedAssignmentStmt() {
  }

  absl::Status ResolvedAssignmentStmt::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedAssignmentStmt::SaveTo(
                                              Type::FileDescriptorSetMap* file_descriptor_set_map,
                                              ResolvedAssignmentStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAssignmentStmt>> ResolvedAssignmentStmt::RestoreFrom(
                                                                                              const ResolvedAssignmentStmtProto& proto,
                                                                                              const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAssignmentStmt::GetChildNodes(
                                             std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAssignmentStmt::AddMutableChildNodePointers(
                                                           std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                           mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAssignmentStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAssignmentStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAssignmentStmt::CollectDebugStringFields(
                                                        std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAssignmentStmt::CheckFieldsAccessedImpl(
                                                               const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAssignmentStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAssignmentStmt::ClearFieldsAccessed() const {
  }

  void ResolvedAssignmentStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCreateEntityStmt::TYPE;

  ResolvedCreateEntityStmt::~ResolvedCreateEntityStmt() {
  }

  absl::Status ResolvedCreateEntityStmt::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                AnyResolvedCreateStatementProto* proto) const {
  }

  absl::Status ResolvedCreateEntityStmt::SaveTo(
                                                Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                ResolvedCreateEntityStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCreateEntityStmt>> ResolvedCreateEntityStmt::RestoreFrom(
                                                                                                  const ResolvedCreateEntityStmtProto& proto,
                                                                                                  const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCreateEntityStmt::GetChildNodes(
                                               std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCreateEntityStmt::AddMutableChildNodePointers(
                                                             std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                             mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCreateEntityStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCreateEntityStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCreateEntityStmt::CollectDebugStringFields(
                                                          std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCreateEntityStmt::CheckFieldsAccessedImpl(
                                                                 const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCreateEntityStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCreateEntityStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCreateEntityStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAlterEntityStmt::TYPE;

  ResolvedAlterEntityStmt::~ResolvedAlterEntityStmt() {
  }

  absl::Status ResolvedAlterEntityStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedAlterObjectStmtProto* proto) const {
  }

  absl::Status ResolvedAlterEntityStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedAlterEntityStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAlterEntityStmt>> ResolvedAlterEntityStmt::RestoreFrom(
                                                                                                const ResolvedAlterEntityStmtProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAlterEntityStmt::GetChildNodes(
                                              std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAlterEntityStmt::AddMutableChildNodePointers(
                                                            std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                            mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAlterEntityStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAlterEntityStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAlterEntityStmt::CollectDebugStringFields(
                                                         std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAlterEntityStmt::CheckFieldsAccessedImpl(
                                                                const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAlterEntityStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAlterEntityStmt::ClearFieldsAccessed() const {
  }

  void ResolvedAlterEntityStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedPivotColumn::TYPE;

  ResolvedPivotColumn::~ResolvedPivotColumn() {
  }

  absl::Status ResolvedPivotColumn::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedPivotColumn::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           ResolvedPivotColumnProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedPivotColumn>> ResolvedPivotColumn::RestoreFrom(
                                                                                        const ResolvedPivotColumnProto& proto,
                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedPivotColumn::GetChildNodes(
                                          std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedPivotColumn::AddMutableChildNodePointers(
                                                        std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                        mutable_child_node_ptrs) {
  }

  absl::Status ResolvedPivotColumn::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedPivotColumn::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedPivotColumn::CollectDebugStringFields(
                                                     std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedPivotColumn::CheckFieldsAccessedImpl(
                                                            const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedPivotColumn::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedPivotColumn::ClearFieldsAccessed() const {
  }

  void ResolvedPivotColumn::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedPivotScan::TYPE;

  ResolvedPivotScan::~ResolvedPivotScan() {
  }

  absl::Status ResolvedPivotScan::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedPivotScan::SaveTo(
                                         Type::FileDescriptorSetMap* file_descriptor_set_map,
                                         ResolvedPivotScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedPivotScan>> ResolvedPivotScan::RestoreFrom(
                                                                                    const ResolvedPivotScanProto& proto,
                                                                                    const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedPivotScan::GetChildNodes(
                                        std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedPivotScan::AddMutableChildNodePointers(
                                                      std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                      mutable_child_node_ptrs) {
  }

  absl::Status ResolvedPivotScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedPivotScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedPivotScan::CollectDebugStringFields(
                                                   std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedPivotScan::CheckFieldsAccessedImpl(
                                                          const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedPivotScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedPivotScan::ClearFieldsAccessed() const {
  }

  void ResolvedPivotScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedReturningClause::TYPE;

  ResolvedReturningClause::~ResolvedReturningClause() {
  }

  absl::Status ResolvedReturningClause::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedReturningClause::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedReturningClauseProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedReturningClause>> ResolvedReturningClause::RestoreFrom(
                                                                                                const ResolvedReturningClauseProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedReturningClause::GetChildNodes(
                                              std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedReturningClause::AddMutableChildNodePointers(
                                                            std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                            mutable_child_node_ptrs) {
  }

  absl::Status ResolvedReturningClause::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedReturningClause::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedReturningClause::CollectDebugStringFields(
                                                         std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedReturningClause::CheckFieldsAccessedImpl(
                                                                const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedReturningClause::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedReturningClause::ClearFieldsAccessed() const {
  }

  void ResolvedReturningClause::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedUnpivotArg::TYPE;

  ResolvedUnpivotArg::~ResolvedUnpivotArg() {
  }

  absl::Status ResolvedUnpivotArg::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedUnpivotArg::SaveTo(
                                          Type::FileDescriptorSetMap* file_descriptor_set_map,
                                          ResolvedUnpivotArgProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedUnpivotArg>> ResolvedUnpivotArg::RestoreFrom(
                                                                                      const ResolvedUnpivotArgProto& proto,
                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedUnpivotArg::GetChildNodes(
                                         std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedUnpivotArg::AddMutableChildNodePointers(
                                                       std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                       mutable_child_node_ptrs) {
  }

  absl::Status ResolvedUnpivotArg::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedUnpivotArg::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedUnpivotArg::CollectDebugStringFields(
                                                    std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedUnpivotArg::CheckFieldsAccessedImpl(
                                                           const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedUnpivotArg::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedUnpivotArg::ClearFieldsAccessed() const {
  }

  void ResolvedUnpivotArg::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedUnpivotScan::TYPE;

  ResolvedUnpivotScan::~ResolvedUnpivotScan() {
  }

  absl::Status ResolvedUnpivotScan::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           AnyResolvedScanProto* proto) const {
  }

  absl::Status ResolvedUnpivotScan::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           ResolvedUnpivotScanProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedUnpivotScan>> ResolvedUnpivotScan::RestoreFrom(
                                                                                        const ResolvedUnpivotScanProto& proto,
                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedUnpivotScan::GetChildNodes(
                                          std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedUnpivotScan::AddMutableChildNodePointers(
                                                        std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                        mutable_child_node_ptrs) {
  }

  absl::Status ResolvedUnpivotScan::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedUnpivotScan::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedUnpivotScan::CollectDebugStringFields(
                                                     std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedUnpivotScan::CheckFieldsAccessedImpl(
                                                            const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedUnpivotScan::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedUnpivotScan::ClearFieldsAccessed() const {
  }

  void ResolvedUnpivotScan::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedCloneDataStmt::TYPE;

  ResolvedCloneDataStmt::~ResolvedCloneDataStmt() {
  }

  absl::Status ResolvedCloneDataStmt::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedCloneDataStmt::SaveTo(
                                             Type::FileDescriptorSetMap* file_descriptor_set_map,
                                             ResolvedCloneDataStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedCloneDataStmt>> ResolvedCloneDataStmt::RestoreFrom(
                                                                                            const ResolvedCloneDataStmtProto& proto,
                                                                                            const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedCloneDataStmt::GetChildNodes(
                                            std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedCloneDataStmt::AddMutableChildNodePointers(
                                                          std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                          mutable_child_node_ptrs) {
  }

  absl::Status ResolvedCloneDataStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedCloneDataStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedCloneDataStmt::CollectDebugStringFields(
                                                       std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedCloneDataStmt::CheckFieldsAccessedImpl(
                                                              const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedCloneDataStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedCloneDataStmt::ClearFieldsAccessed() const {
  }

  void ResolvedCloneDataStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedTableAndColumnInfo::TYPE;

  ResolvedTableAndColumnInfo::~ResolvedTableAndColumnInfo() {
  }

  absl::Status ResolvedTableAndColumnInfo::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  AnyResolvedArgumentProto* proto) const {
  }

  absl::Status ResolvedTableAndColumnInfo::SaveTo(
                                                  Type::FileDescriptorSetMap* file_descriptor_set_map,
                                                  ResolvedTableAndColumnInfoProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedTableAndColumnInfo>> ResolvedTableAndColumnInfo::RestoreFrom(
                                                                                                      const ResolvedTableAndColumnInfoProto& proto,
                                                                                                      const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedTableAndColumnInfo::GetChildNodes(
                                                 std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedTableAndColumnInfo::AddMutableChildNodePointers(
                                                               std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                               mutable_child_node_ptrs) {
  }

  absl::Status ResolvedTableAndColumnInfo::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedTableAndColumnInfo::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedTableAndColumnInfo::CollectDebugStringFields(
                                                            std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedTableAndColumnInfo::CheckFieldsAccessedImpl(
                                                                   const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedTableAndColumnInfo::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedTableAndColumnInfo::ClearFieldsAccessed() const {
  }

  void ResolvedTableAndColumnInfo::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAnalyzeStmt::TYPE;

  ResolvedAnalyzeStmt::~ResolvedAnalyzeStmt() {
  }

  absl::Status ResolvedAnalyzeStmt::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedAnalyzeStmt::SaveTo(
                                           Type::FileDescriptorSetMap* file_descriptor_set_map,
                                           ResolvedAnalyzeStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAnalyzeStmt>> ResolvedAnalyzeStmt::RestoreFrom(
                                                                                        const ResolvedAnalyzeStmtProto& proto,
                                                                                        const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAnalyzeStmt::GetChildNodes(
                                          std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAnalyzeStmt::AddMutableChildNodePointers(
                                                        std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                        mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAnalyzeStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAnalyzeStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAnalyzeStmt::CollectDebugStringFields(
                                                     std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAnalyzeStmt::CheckFieldsAccessedImpl(
                                                            const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAnalyzeStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAnalyzeStmt::ClearFieldsAccessed() const {
  }

  void ResolvedAnalyzeStmt::MarkFieldsAccessed() const {
  }

  const ResolvedNodeKind ResolvedAuxLoadDataStmt::TYPE;

  const ResolvedAuxLoadDataStmt::InsertionMode ResolvedAuxLoadDataStmt::NONE;
  const ResolvedAuxLoadDataStmt::InsertionMode ResolvedAuxLoadDataStmt::APPEND;
  const ResolvedAuxLoadDataStmt::InsertionMode ResolvedAuxLoadDataStmt::OVERWRITE;

  ResolvedAuxLoadDataStmt::~ResolvedAuxLoadDataStmt() {
  }

  absl::Status ResolvedAuxLoadDataStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               AnyResolvedStatementProto* proto) const {
  }

  absl::Status ResolvedAuxLoadDataStmt::SaveTo(
                                               Type::FileDescriptorSetMap* file_descriptor_set_map,
                                               ResolvedAuxLoadDataStmtProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<ResolvedAuxLoadDataStmt>> ResolvedAuxLoadDataStmt::RestoreFrom(
                                                                                                const ResolvedAuxLoadDataStmtProto& proto,
                                                                                                const ResolvedNode::RestoreParams& params) {
  }

  void ResolvedAuxLoadDataStmt::GetChildNodes(
                                              std::vector<const ResolvedNode*>* child_nodes) const {
  }

  void ResolvedAuxLoadDataStmt::AddMutableChildNodePointers(
                                                            std::vector<std::unique_ptr<const ResolvedNode>*>*
                                                            mutable_child_node_ptrs) {
  }

  absl::Status ResolvedAuxLoadDataStmt::Accept(ResolvedASTVisitor* visitor) const {
  }

  absl::Status ResolvedAuxLoadDataStmt::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedAuxLoadDataStmt::CollectDebugStringFields(
                                                         std::vector<DebugStringField>* fields) const {
  }

  absl::Status ResolvedAuxLoadDataStmt::CheckFieldsAccessedImpl(
                                                                const ResolvedNode* root) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedAuxLoadDataStmt::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedAuxLoadDataStmt::ClearFieldsAccessed() const {
  }

  void ResolvedAuxLoadDataStmt::MarkFieldsAccessed() const {
  }

}


namespace zetasql {

  absl::Status ResolvedASTDeepCopyVisitor::DefaultVisit(const ResolvedNode* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedLiteral(
                                                                const ResolvedLiteral* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedParameter(
                                                                  const ResolvedParameter* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExpressionColumn(
                                                                         const ResolvedExpressionColumn* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedColumnRef(
                                                                  const ResolvedColumnRef* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedConstant(
                                                                 const ResolvedConstant* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSystemVariable(
                                                                       const ResolvedSystemVariable* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedInlineLambda(
                                                                     const ResolvedInlineLambda* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFilterFieldArg(
                                                                       const ResolvedFilterFieldArg* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFilterField(
                                                                    const ResolvedFilterField* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFunctionCall(
                                                                     const ResolvedFunctionCall* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAggregateFunctionCall(
                                                                              const ResolvedAggregateFunctionCall* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAnalyticFunctionCall(
                                                                             const ResolvedAnalyticFunctionCall* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExtendedCastElement(
                                                                            const ResolvedExtendedCastElement* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExtendedCast(
                                                                     const ResolvedExtendedCast* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCast(
                                                             const ResolvedCast* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedMakeStruct(
                                                                   const ResolvedMakeStruct* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedMakeProto(
                                                                  const ResolvedMakeProto* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedMakeProtoField(
                                                                       const ResolvedMakeProtoField* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGetStructField(
                                                                       const ResolvedGetStructField* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGetProtoField(
                                                                      const ResolvedGetProtoField* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGetJsonField(
                                                                     const ResolvedGetJsonField* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFlatten(
                                                                const ResolvedFlatten* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFlattenedArg(
                                                                     const ResolvedFlattenedArg* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedReplaceFieldItem(
                                                                         const ResolvedReplaceFieldItem* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedReplaceField(
                                                                     const ResolvedReplaceField* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSubqueryExpr(
                                                                     const ResolvedSubqueryExpr* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedLetExpr(
                                                                const ResolvedLetExpr* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedModel(
                                                              const ResolvedModel* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedConnection(
                                                                   const ResolvedConnection* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDescriptor(
                                                                   const ResolvedDescriptor* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSingleRowScan(
                                                                      const ResolvedSingleRowScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedTableScan(
                                                                  const ResolvedTableScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedJoinScan(
                                                                 const ResolvedJoinScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedArrayScan(
                                                                  const ResolvedArrayScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedColumnHolder(
                                                                     const ResolvedColumnHolder* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFilterScan(
                                                                   const ResolvedFilterScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGroupingSet(
                                                                    const ResolvedGroupingSet* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAggregateScan(
                                                                      const ResolvedAggregateScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAnonymizedAggregateScan(
                                                                                const ResolvedAnonymizedAggregateScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSetOperationItem(
                                                                         const ResolvedSetOperationItem* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSetOperationScan(
                                                                         const ResolvedSetOperationScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedOrderByScan(
                                                                    const ResolvedOrderByScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedLimitOffsetScan(
                                                                        const ResolvedLimitOffsetScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWithRefScan(
                                                                    const ResolvedWithRefScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAnalyticScan(
                                                                     const ResolvedAnalyticScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSampleScan(
                                                                   const ResolvedSampleScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedComputedColumn(
                                                                       const ResolvedComputedColumn* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedOrderByItem(
                                                                    const ResolvedOrderByItem* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedColumnAnnotations(
                                                                          const ResolvedColumnAnnotations* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGeneratedColumnInfo(
                                                                            const ResolvedGeneratedColumnInfo* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedColumnDefaultValue(
                                                                           const ResolvedColumnDefaultValue* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedColumnDefinition(
                                                                         const ResolvedColumnDefinition* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedPrimaryKey(
                                                                   const ResolvedPrimaryKey* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedForeignKey(
                                                                   const ResolvedForeignKey* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCheckConstraint(
                                                                        const ResolvedCheckConstraint* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedOutputColumn(
                                                                     const ResolvedOutputColumn* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedProjectScan(
                                                                    const ResolvedProjectScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedTVFScan(
                                                                const ResolvedTVFScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGroupRowsScan(
                                                                      const ResolvedGroupRowsScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFunctionArgument(
                                                                         const ResolvedFunctionArgument* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExplainStmt(
                                                                    const ResolvedExplainStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedQueryStmt(
                                                                  const ResolvedQueryStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateDatabaseStmt(
                                                                           const ResolvedCreateDatabaseStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedIndexItem(
                                                                  const ResolvedIndexItem* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedUnnestItem(
                                                                   const ResolvedUnnestItem* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateIndexStmt(
                                                                        const ResolvedCreateIndexStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateSchemaStmt(
                                                                         const ResolvedCreateSchemaStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateTableStmt(
                                                                        const ResolvedCreateTableStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateTableAsSelectStmt(
                                                                                const ResolvedCreateTableAsSelectStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateModelStmt(
                                                                        const ResolvedCreateModelStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateViewStmt(
                                                                       const ResolvedCreateViewStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWithPartitionColumns(
                                                                             const ResolvedWithPartitionColumns* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateSnapshotTableStmt(
                                                                                const ResolvedCreateSnapshotTableStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateExternalTableStmt(
                                                                                const ResolvedCreateExternalTableStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExportModelStmt(
                                                                        const ResolvedExportModelStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExportDataStmt(
                                                                       const ResolvedExportDataStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDefineTableStmt(
                                                                        const ResolvedDefineTableStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDescribeStmt(
                                                                     const ResolvedDescribeStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedShowStmt(
                                                                 const ResolvedShowStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedBeginStmt(
                                                                  const ResolvedBeginStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSetTransactionStmt(
                                                                           const ResolvedSetTransactionStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCommitStmt(
                                                                   const ResolvedCommitStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRollbackStmt(
                                                                     const ResolvedRollbackStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedStartBatchStmt(
                                                                       const ResolvedStartBatchStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRunBatchStmt(
                                                                     const ResolvedRunBatchStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAbortBatchStmt(
                                                                       const ResolvedAbortBatchStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropStmt(
                                                                 const ResolvedDropStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropMaterializedViewStmt(
                                                                                 const ResolvedDropMaterializedViewStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropSnapshotTableStmt(
                                                                              const ResolvedDropSnapshotTableStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRecursiveRefScan(
                                                                         const ResolvedRecursiveRefScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRecursiveScan(
                                                                      const ResolvedRecursiveScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWithScan(
                                                                 const ResolvedWithScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWithEntry(
                                                                  const ResolvedWithEntry* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedOption(
                                                               const ResolvedOption* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWindowPartitioning(
                                                                           const ResolvedWindowPartitioning* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWindowOrdering(
                                                                       const ResolvedWindowOrdering* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWindowFrame(
                                                                    const ResolvedWindowFrame* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAnalyticFunctionGroup(
                                                                              const ResolvedAnalyticFunctionGroup* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedWindowFrameExpr(
                                                                        const ResolvedWindowFrameExpr* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDMLValue(
                                                                 const ResolvedDMLValue* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDMLDefault(
                                                                   const ResolvedDMLDefault* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAssertStmt(
                                                                   const ResolvedAssertStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAssertRowsModified(
                                                                           const ResolvedAssertRowsModified* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedInsertRow(
                                                                  const ResolvedInsertRow* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedInsertStmt(
                                                                   const ResolvedInsertStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDeleteStmt(
                                                                   const ResolvedDeleteStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedUpdateItem(
                                                                   const ResolvedUpdateItem* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedUpdateArrayItem(
                                                                        const ResolvedUpdateArrayItem* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedUpdateStmt(
                                                                   const ResolvedUpdateStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedMergeWhen(
                                                                  const ResolvedMergeWhen* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedMergeStmt(
                                                                  const ResolvedMergeStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedTruncateStmt(
                                                                     const ResolvedTruncateStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedObjectUnit(
                                                                   const ResolvedObjectUnit* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedPrivilege(
                                                                  const ResolvedPrivilege* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGrantStmt(
                                                                  const ResolvedGrantStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRevokeStmt(
                                                                   const ResolvedRevokeStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterDatabaseStmt(
                                                                          const ResolvedAlterDatabaseStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterMaterializedViewStmt(
                                                                                  const ResolvedAlterMaterializedViewStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterSchemaStmt(
                                                                        const ResolvedAlterSchemaStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterTableStmt(
                                                                       const ResolvedAlterTableStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterViewStmt(
                                                                      const ResolvedAlterViewStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSetOptionsAction(
                                                                         const ResolvedSetOptionsAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAddColumnAction(
                                                                        const ResolvedAddColumnAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAddConstraintAction(
                                                                            const ResolvedAddConstraintAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropConstraintAction(
                                                                             const ResolvedDropConstraintAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropPrimaryKeyAction(
                                                                             const ResolvedDropPrimaryKeyAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterColumnOptionsAction(
                                                                                 const ResolvedAlterColumnOptionsAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterColumnDropNotNullAction(
                                                                                     const ResolvedAlterColumnDropNotNullAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterColumnSetDataTypeAction(
                                                                                     const ResolvedAlterColumnSetDataTypeAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterColumnSetDefaultAction(
                                                                                    const ResolvedAlterColumnSetDefaultAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterColumnDropDefaultAction(
                                                                                     const ResolvedAlterColumnDropDefaultAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropColumnAction(
                                                                         const ResolvedDropColumnAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRenameColumnAction(
                                                                           const ResolvedRenameColumnAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSetAsAction(
                                                                    const ResolvedSetAsAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedSetCollateClause(
                                                                         const ResolvedSetCollateClause* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterTableSetOptionsStmt(
                                                                                 const ResolvedAlterTableSetOptionsStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRenameStmt(
                                                                   const ResolvedRenameStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreatePrivilegeRestrictionStmt(
                                                                                       const ResolvedCreatePrivilegeRestrictionStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateRowAccessPolicyStmt(
                                                                                  const ResolvedCreateRowAccessPolicyStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropPrivilegeRestrictionStmt(
                                                                                     const ResolvedDropPrivilegeRestrictionStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropRowAccessPolicyStmt(
                                                                                const ResolvedDropRowAccessPolicyStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropSearchIndexStmt(
                                                                            const ResolvedDropSearchIndexStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedGrantToAction(
                                                                      const ResolvedGrantToAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRestrictToAction(
                                                                         const ResolvedRestrictToAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAddToRestricteeListAction(
                                                                                  const ResolvedAddToRestricteeListAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRemoveFromRestricteeListAction(
                                                                                       const ResolvedRemoveFromRestricteeListAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFilterUsingAction(
                                                                          const ResolvedFilterUsingAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRevokeFromAction(
                                                                         const ResolvedRevokeFromAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRenameToAction(
                                                                       const ResolvedRenameToAction* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterPrivilegeRestrictionStmt(
                                                                                      const ResolvedAlterPrivilegeRestrictionStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterRowAccessPolicyStmt(
                                                                                 const ResolvedAlterRowAccessPolicyStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterAllRowAccessPoliciesStmt(
                                                                                      const ResolvedAlterAllRowAccessPoliciesStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateConstantStmt(
                                                                           const ResolvedCreateConstantStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateFunctionStmt(
                                                                           const ResolvedCreateFunctionStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedArgumentDef(
                                                                    const ResolvedArgumentDef* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedArgumentRef(
                                                                    const ResolvedArgumentRef* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateTableFunctionStmt(
                                                                                const ResolvedCreateTableFunctionStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedRelationArgumentScan(
                                                                             const ResolvedRelationArgumentScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedArgumentList(
                                                                     const ResolvedArgumentList* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedFunctionSignatureHolder(
                                                                                const ResolvedFunctionSignatureHolder* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropFunctionStmt(
                                                                         const ResolvedDropFunctionStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedDropTableFunctionStmt(
                                                                              const ResolvedDropTableFunctionStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCallStmt(
                                                                 const ResolvedCallStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedImportStmt(
                                                                   const ResolvedImportStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedModuleStmt(
                                                                   const ResolvedModuleStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAggregateHavingModifier(
                                                                                const ResolvedAggregateHavingModifier* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateMaterializedViewStmt(
                                                                                   const ResolvedCreateMaterializedViewStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateProcedureStmt(
                                                                            const ResolvedCreateProcedureStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExecuteImmediateArgument(
                                                                                 const ResolvedExecuteImmediateArgument* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedExecuteImmediateStmt(
                                                                             const ResolvedExecuteImmediateStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAssignmentStmt(
                                                                       const ResolvedAssignmentStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCreateEntityStmt(
                                                                         const ResolvedCreateEntityStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAlterEntityStmt(
                                                                        const ResolvedAlterEntityStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedPivotColumn(
                                                                    const ResolvedPivotColumn* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedPivotScan(
                                                                  const ResolvedPivotScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedReturningClause(
                                                                        const ResolvedReturningClause* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedUnpivotArg(
                                                                   const ResolvedUnpivotArg* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedUnpivotScan(
                                                                    const ResolvedUnpivotScan* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedCloneDataStmt(
                                                                      const ResolvedCloneDataStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedTableAndColumnInfo(
                                                                           const ResolvedTableAndColumnInfo* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAnalyzeStmt(
                                                                    const ResolvedAnalyzeStmt* node) {
  }

  absl::Status ResolvedASTDeepCopyVisitor::VisitResolvedAuxLoadDataStmt(
                                                                        const ResolvedAuxLoadDataStmt* node) {
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedLiteral(
                                                       const ResolvedLiteral* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedParameter(
                                                         const ResolvedParameter* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedExpressionColumn(
                                                                const ResolvedExpressionColumn* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedColumnRef(
                                                         const ResolvedColumnRef* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedConstant(
                                                        const ResolvedConstant* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedSystemVariable(
                                                              const ResolvedSystemVariable* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedInlineLambda(
                                                            const ResolvedInlineLambda* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedFilterFieldArg(
                                                              const ResolvedFilterFieldArg* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedFilterField(
                                                           const ResolvedFilterField* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedFunctionCall(
                                                            const ResolvedFunctionCall* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAggregateFunctionCall(
                                                                     const ResolvedAggregateFunctionCall* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAnalyticFunctionCall(
                                                                    const ResolvedAnalyticFunctionCall* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedExtendedCastElement(
                                                                   const ResolvedExtendedCastElement* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedExtendedCast(
                                                            const ResolvedExtendedCast* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCast(
                                                    const ResolvedCast* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedMakeStruct(
                                                          const ResolvedMakeStruct* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedMakeProto(
                                                         const ResolvedMakeProto* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedMakeProtoField(
                                                              const ResolvedMakeProtoField* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedGetStructField(
                                                              const ResolvedGetStructField* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedGetProtoField(
                                                             const ResolvedGetProtoField* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedGetJsonField(
                                                            const ResolvedGetJsonField* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedFlatten(
                                                       const ResolvedFlatten* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedFlattenedArg(
                                                            const ResolvedFlattenedArg* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedReplaceFieldItem(
                                                                const ResolvedReplaceFieldItem* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedReplaceField(
                                                            const ResolvedReplaceField* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedSubqueryExpr(
                                                            const ResolvedSubqueryExpr* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedLetExpr(
                                                       const ResolvedLetExpr* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedModel(
                                                     const ResolvedModel* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedConnection(
                                                          const ResolvedConnection* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDescriptor(
                                                          const ResolvedDescriptor* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedSingleRowScan(
                                                             const ResolvedSingleRowScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedTableScan(
                                                         const ResolvedTableScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedJoinScan(
                                                        const ResolvedJoinScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedArrayScan(
                                                         const ResolvedArrayScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedColumnHolder(
                                                            const ResolvedColumnHolder* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedFilterScan(
                                                          const ResolvedFilterScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedGroupingSet(
                                                           const ResolvedGroupingSet* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAggregateScan(
                                                             const ResolvedAggregateScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAnonymizedAggregateScan(
                                                                       const ResolvedAnonymizedAggregateScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedSetOperationItem(
                                                                const ResolvedSetOperationItem* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedSetOperationScan(
                                                                const ResolvedSetOperationScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedOrderByScan(
                                                           const ResolvedOrderByScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedLimitOffsetScan(
                                                               const ResolvedLimitOffsetScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedWithRefScan(
                                                           const ResolvedWithRefScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAnalyticScan(
                                                            const ResolvedAnalyticScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedSampleScan(
                                                          const ResolvedSampleScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedComputedColumn(
                                                              const ResolvedComputedColumn* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedOrderByItem(
                                                           const ResolvedOrderByItem* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedColumnAnnotations(
                                                                 const ResolvedColumnAnnotations* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedGeneratedColumnInfo(
                                                                   const ResolvedGeneratedColumnInfo* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedColumnDefaultValue(
                                                                  const ResolvedColumnDefaultValue* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedColumnDefinition(
                                                                const ResolvedColumnDefinition* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedPrimaryKey(
                                                          const ResolvedPrimaryKey* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedForeignKey(
                                                          const ResolvedForeignKey* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCheckConstraint(
                                                               const ResolvedCheckConstraint* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedOutputColumn(
                                                            const ResolvedOutputColumn* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedProjectScan(
                                                           const ResolvedProjectScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedTVFScan(
                                                       const ResolvedTVFScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedGroupRowsScan(
                                                             const ResolvedGroupRowsScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedFunctionArgument(
                                                                const ResolvedFunctionArgument* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedExplainStmt(
                                                           const ResolvedExplainStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedQueryStmt(
                                                         const ResolvedQueryStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateDatabaseStmt(
                                                                  const ResolvedCreateDatabaseStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedIndexItem(
                                                         const ResolvedIndexItem* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedUnnestItem(
                                                          const ResolvedUnnestItem* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateIndexStmt(
                                                               const ResolvedCreateIndexStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateSchemaStmt(
                                                                const ResolvedCreateSchemaStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateTableStmt(
                                                               const ResolvedCreateTableStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateTableAsSelectStmt(
                                                                       const ResolvedCreateTableAsSelectStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateModelStmt(
                                                               const ResolvedCreateModelStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateViewStmt(
                                                              const ResolvedCreateViewStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedWithPartitionColumns(
                                                                    const ResolvedWithPartitionColumns* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateSnapshotTableStmt(
                                                                       const ResolvedCreateSnapshotTableStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateExternalTableStmt(
                                                                       const ResolvedCreateExternalTableStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedExportModelStmt(
                                                               const ResolvedExportModelStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedExportDataStmt(
                                                              const ResolvedExportDataStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDefineTableStmt(
                                                               const ResolvedDefineTableStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDescribeStmt(
                                                            const ResolvedDescribeStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedShowStmt(
                                                        const ResolvedShowStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedBeginStmt(
                                                         const ResolvedBeginStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedSetTransactionStmt(
                                                                  const ResolvedSetTransactionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCommitStmt(
                                                          const ResolvedCommitStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedRollbackStmt(
                                                            const ResolvedRollbackStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedStartBatchStmt(
                                                              const ResolvedStartBatchStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedRunBatchStmt(
                                                            const ResolvedRunBatchStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAbortBatchStmt(
                                                              const ResolvedAbortBatchStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropStmt(
                                                        const ResolvedDropStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropMaterializedViewStmt(
                                                                        const ResolvedDropMaterializedViewStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropSnapshotTableStmt(
                                                                     const ResolvedDropSnapshotTableStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedRecursiveRefScan(
                                                                const ResolvedRecursiveRefScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedRecursiveScan(
                                                             const ResolvedRecursiveScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedWithScan(
                                                        const ResolvedWithScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedWithEntry(
                                                         const ResolvedWithEntry* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedOption(
                                                      const ResolvedOption* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedWindowPartitioning(
                                                                  const ResolvedWindowPartitioning* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedWindowOrdering(
                                                              const ResolvedWindowOrdering* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedWindowFrame(
                                                           const ResolvedWindowFrame* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAnalyticFunctionGroup(
                                                                     const ResolvedAnalyticFunctionGroup* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedWindowFrameExpr(
                                                               const ResolvedWindowFrameExpr* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDMLValue(
                                                        const ResolvedDMLValue* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDMLDefault(
                                                          const ResolvedDMLDefault* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAssertStmt(
                                                          const ResolvedAssertStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAssertRowsModified(
                                                                  const ResolvedAssertRowsModified* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedInsertRow(
                                                         const ResolvedInsertRow* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedInsertStmt(
                                                          const ResolvedInsertStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDeleteStmt(
                                                          const ResolvedDeleteStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedUpdateItem(
                                                          const ResolvedUpdateItem* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedUpdateArrayItem(
                                                               const ResolvedUpdateArrayItem* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedUpdateStmt(
                                                          const ResolvedUpdateStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedMergeWhen(
                                                         const ResolvedMergeWhen* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedMergeStmt(
                                                         const ResolvedMergeStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedTruncateStmt(
                                                            const ResolvedTruncateStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedObjectUnit(
                                                          const ResolvedObjectUnit* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedPrivilege(
                                                         const ResolvedPrivilege* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedGrantStmt(
                                                         const ResolvedGrantStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedRevokeStmt(
                                                          const ResolvedRevokeStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterDatabaseStmt(
                                                                 const ResolvedAlterDatabaseStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterMaterializedViewStmt(
                                                                         const ResolvedAlterMaterializedViewStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterSchemaStmt(
                                                               const ResolvedAlterSchemaStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterTableStmt(
                                                              const ResolvedAlterTableStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterViewStmt(
                                                             const ResolvedAlterViewStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedSetOptionsAction(
                                                                const ResolvedSetOptionsAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAddColumnAction(
                                                               const ResolvedAddColumnAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAddConstraintAction(
                                                                   const ResolvedAddConstraintAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropConstraintAction(
                                                                    const ResolvedDropConstraintAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropPrimaryKeyAction(
                                                                    const ResolvedDropPrimaryKeyAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterColumnOptionsAction(
                                                                        const ResolvedAlterColumnOptionsAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterColumnDropNotNullAction(
                                                                            const ResolvedAlterColumnDropNotNullAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterColumnSetDataTypeAction(
                                                                            const ResolvedAlterColumnSetDataTypeAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterColumnSetDefaultAction(
                                                                           const ResolvedAlterColumnSetDefaultAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterColumnDropDefaultAction(
                                                                            const ResolvedAlterColumnDropDefaultAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropColumnAction(
                                                                const ResolvedDropColumnAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedRenameColumnAction(
                                                                  const ResolvedRenameColumnAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedSetAsAction(
                                                           const ResolvedSetAsAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedSetCollateClause(
                                                                const ResolvedSetCollateClause* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterTableSetOptionsStmt(
                                                                        const ResolvedAlterTableSetOptionsStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedRenameStmt(
                                                          const ResolvedRenameStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreatePrivilegeRestrictionStmt(
                                                                              const ResolvedCreatePrivilegeRestrictionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateRowAccessPolicyStmt(
                                                                         const ResolvedCreateRowAccessPolicyStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropPrivilegeRestrictionStmt(
                                                                            const ResolvedDropPrivilegeRestrictionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropRowAccessPolicyStmt(
                                                                       const ResolvedDropRowAccessPolicyStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropSearchIndexStmt(
                                                                   const ResolvedDropSearchIndexStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedGrantToAction(
                                                             const ResolvedGrantToAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedRestrictToAction(
                                                                const ResolvedRestrictToAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAddToRestricteeListAction(
                                                                         const ResolvedAddToRestricteeListAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedRemoveFromRestricteeListAction(
                                                                              const ResolvedRemoveFromRestricteeListAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedFilterUsingAction(
                                                                 const ResolvedFilterUsingAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedRevokeFromAction(
                                                                const ResolvedRevokeFromAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedRenameToAction(
                                                              const ResolvedRenameToAction* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterPrivilegeRestrictionStmt(
                                                                             const ResolvedAlterPrivilegeRestrictionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterRowAccessPolicyStmt(
                                                                        const ResolvedAlterRowAccessPolicyStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterAllRowAccessPoliciesStmt(
                                                                             const ResolvedAlterAllRowAccessPoliciesStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateConstantStmt(
                                                                  const ResolvedCreateConstantStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateFunctionStmt(
                                                                  const ResolvedCreateFunctionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedArgumentDef(
                                                           const ResolvedArgumentDef* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedArgumentRef(
                                                           const ResolvedArgumentRef* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateTableFunctionStmt(
                                                                       const ResolvedCreateTableFunctionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedRelationArgumentScan(
                                                                    const ResolvedRelationArgumentScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedArgumentList(
                                                            const ResolvedArgumentList* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedFunctionSignatureHolder(
                                                                       const ResolvedFunctionSignatureHolder* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropFunctionStmt(
                                                                const ResolvedDropFunctionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedDropTableFunctionStmt(
                                                                     const ResolvedDropTableFunctionStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCallStmt(
                                                        const ResolvedCallStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedImportStmt(
                                                          const ResolvedImportStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedModuleStmt(
                                                          const ResolvedModuleStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAggregateHavingModifier(
                                                                       const ResolvedAggregateHavingModifier* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateMaterializedViewStmt(
                                                                          const ResolvedCreateMaterializedViewStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateProcedureStmt(
                                                                   const ResolvedCreateProcedureStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedExecuteImmediateArgument(
                                                                        const ResolvedExecuteImmediateArgument* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedExecuteImmediateStmt(
                                                                    const ResolvedExecuteImmediateStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAssignmentStmt(
                                                              const ResolvedAssignmentStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCreateEntityStmt(
                                                                const ResolvedCreateEntityStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAlterEntityStmt(
                                                               const ResolvedAlterEntityStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedPivotColumn(
                                                           const ResolvedPivotColumn* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedPivotScan(
                                                         const ResolvedPivotScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedReturningClause(
                                                               const ResolvedReturningClause* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedUnpivotArg(
                                                          const ResolvedUnpivotArg* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedUnpivotScan(
                                                           const ResolvedUnpivotScan* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedCloneDataStmt(
                                                             const ResolvedCloneDataStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedTableAndColumnInfo(
                                                                  const ResolvedTableAndColumnInfo* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAnalyzeStmt(
                                                           const ResolvedAnalyzeStmt* node) {
    return absl::OkStatus();
  }

  absl::Status
  ResolvedASTDeepCopyVisitor::CopyVisitResolvedAuxLoadDataStmt(
                                                               const ResolvedAuxLoadDataStmt* node) {
    return absl::OkStatus();
  }

}

namespace zetasql {

  const ResolvedComputedColumn* FindProjectComputedColumn(const ResolvedProjectScan* project, const ResolvedColumn& column) {
    return nullptr;
  }

  const ResolvedExpr* FindProjectExpr(const ResolvedProjectScan* project, const ResolvedColumn& column) {
    return nullptr;
  }

}

namespace zetasql {

  ResolvedCollation ResolvedCollation::MakeScalar(absl::string_view collation_name) {
    ResolvedCollation v;
    return v;
  }

  absl::StatusOr<ResolvedCollation> ResolvedCollation::MakeResolvedCollation(const AnnotationMap& annotation_map) {
    absl::StatusOr<ResolvedCollation> v;
    return v;
  }

  bool ResolvedCollation::Equals(const ResolvedCollation& that) const {
    return false;
  }

  absl::Status ResolvedCollation::Serialize(ResolvedCollationProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<ResolvedCollation> ResolvedCollation::Deserialize(const ResolvedCollationProto& proto) {
    absl::StatusOr<ResolvedCollation> v;
    return v;
  }

  std::string ResolvedCollation::DebugString() const {
    return "";
  }

  bool ResolvedCollation::HasCompatibleStructure(const Type* type) const {
    return false;
  }

  std::string ResolvedCollation::ToString(const std::vector<ResolvedCollation>& resolved_collation_list) {
    return "";
  }
}

namespace zetasql {

  std::string ResolvedColumn::DebugString() const {
    return "";
  }

  std::string ResolvedColumn::ShortDebugString() const {
    return "";
  }

  absl::Status ResolvedColumn::SaveTo(FileDescriptorSetMap* file_descriptor_set_map,
                                      ResolvedColumnProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<ResolvedColumn> ResolvedColumn::RestoreFrom(const ResolvedColumnProto& proto,
                                                             const ResolvedNode::RestoreParams& params) {
    absl::StatusOr<ResolvedColumn> v;
    return v;
  }

  std::string ResolvedColumnListToString(const ResolvedColumnList& columns) {
    return "";
  }

}

namespace zetasql {

  absl::Status ResolvedNode::Accept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  absl::Status ResolvedNode::ChildrenAccept(ResolvedASTVisitor* visitor) const {
    return absl::OkStatus();
  }

  void ResolvedNode::SetParseLocationRange(const ParseLocationRange& parse_location_range) {
  }

  void ResolvedNode::ClearParseLocationRange() { parse_location_range_.reset(); }

  std::string ResolvedNode::DebugString(absl::Span<const NodeAnnotation> annotations) const {
    return "";
  }

  void ResolvedNode::AppendAnnotations(const ResolvedNode* node, absl::Span<const NodeAnnotation> annotations, std::string* output) {
  }

  void ResolvedNode::DebugStringImpl(const ResolvedNode* node,
                                     absl::Span<const NodeAnnotation> annotations,
                                     const std::string& prefix1,
                                     const std::string& prefix2,
                                     std::string* output) {
  }

  void ResolvedNode::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  bool ResolvedNode::HasDebugStringFieldsWithNodes() const {
    return false;
  }

  std::string ResolvedNode::GetNameForDebugString() const {
    return "";
  }

  absl::Status ResolvedNode::CheckNoFieldsAccessed() const {
    return absl::OkStatus();
  }

  void ResolvedNode::ClearFieldsAccessed() const {}

  void ResolvedNode::MarkFieldsAccessed() const {}

  void ResolvedNode::GetDescendantsWithKinds(const std::set<ResolvedNodeKind>& node_kinds,
                                             std::vector<const ResolvedNode*>* found_nodes) const {
  }

  void ResolvedNode::GetDescendantsSatisfying(bool (ResolvedNode::*filter_method)() const,
                                              std::vector<const ResolvedNode*>* found_nodes) const {
  }

  void ResolvedNode::CollectDebugStringFieldsWithNameFormat(const ResolvedNode* node, std::vector<DebugStringField>* fields) const {
  }

  std::string ResolvedNode::GetNameForDebugStringWithNameFormat(const std::string& name, const ResolvedNode* node) const {
    return "";
  }

  const int ResolvedNode::GetTreeDepth() const {
    return 0;
  }

  absl::Status ResolvedNode::SaveTo(FileDescriptorSetMap* file_descriptor_set_map,
                                    ResolvedNodeProto* proto) const {
    return absl::OkStatus();
  }

  void ResolvedComputedColumn::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  std::string ResolvedComputedColumn::GetNameForDebugString() const {
    return "";
  }

  void ResolvedOutputColumn::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  std::string ResolvedOutputColumn::GetNameForDebugString() const {
    return "";
  }

  void ResolvedConstant::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  std::string ResolvedConstant::GetNameForDebugString() const {
    return "";
  }

  void ResolvedSystemVariable::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  std::string ResolvedSystemVariable::GetNameForDebugString() const {
    return "";
  }

  void ResolvedFunctionCallBase::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  std::string ResolvedFunctionCallBase::GetNameForDebugString() const {
    return "";
  }

  void ResolvedCast::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  std::string ResolvedCast::GetNameForDebugString() const {
    return "";
  }

  void ResolvedExtendedCastElement::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  std::string ResolvedExtendedCastElement::GetNameForDebugString() const {
    return "";
  }

  void ResolvedMakeProtoField::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  std::string ResolvedMakeProtoField::GetNameForDebugString() const {
    return "";
  }

  void ResolvedOption::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  std::string ResolvedOption::GetNameForDebugString() const {
    return "";
  }

  std::string ResolvedWindowFrame::FrameUnitToString(FrameUnit frame_unit) {
    return "";
  }

  std::string ResolvedWindowFrameExpr::BoundaryTypeToString(BoundaryType boundary_type) {
    return "";
  }

  void ResolvedWindowFrame::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  std::string ResolvedWindowFrame::GetFrameUnitString() const {
    return "";
  }

  std::string ResolvedWindowFrame::GetNameForDebugString() const {
    return "";
  }

  void ResolvedWindowFrameExpr::CollectDebugStringFields(std::vector<DebugStringField>* fields) const {
  }

  std::string ResolvedWindowFrameExpr::GetNameForDebugString() const {
    return "";
  }

  std::string ResolvedWindowFrameExpr::GetBoundaryTypeString() const {
    return "";
  }

  std::string ResolvedInsertStmt::InsertModeToString(InsertMode insert_mode) {
    return "";
  }

  std::string ResolvedInsertStmt::GetInsertModeString() const {
    return "";
  }

  std::string ResolvedAggregateHavingModifier::HavingModifierKindToString(HavingModifierKind kind) {
    return "";
  }

  std::string ResolvedAggregateHavingModifier::GetHavingModifierKindString() const {
    return "";
  }

  std::string ResolvedImportStmt::ImportKindToString(ImportKind kind) {
    return "";
  }

  std::string ResolvedImportStmt::GetImportKindString() const {
    return "";
  }

  absl::StatusOr<TypeParameters> ResolvedColumnAnnotations::GetFullTypeParameters(const Type* type) const {
    absl::StatusOr<TypeParameters> v;
    return v;
  }

  absl::StatusOr<TypeParameters> ResolvedColumnDefinition::GetFullTypeParameters() {
    absl::StatusOr<TypeParameters> v;
    return v;
  }

  FunctionEnums::Volatility ResolvedCreateFunctionStmt::volatility() const {
    FunctionEnums::Volatility v;
    return v;
  }

}

#endif

#include "go-zetasql/resolved_ast/resolved_ast_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast_enums_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/serialization_cc_proto/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/public/annotation_cc_proto/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/constant/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/parse_location_range_cc_proto/export.inc"
#include "go-zetasql/public/simple_catalog/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_annotation_cc_proto/export.inc"
#include "go-zetasql/public/type_parameters_cc_proto/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/public/proto/type_annotation_cc_proto/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
