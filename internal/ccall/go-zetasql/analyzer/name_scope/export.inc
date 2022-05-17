#ifndef ZETASQL_ANALYZER_NAME_SCOPE_EXPORT_H
#define ZETASQL_ANALYZER_NAME_SCOPE_EXPORT_H

#include "zetasql/analyzer/name_scope.h"
#include "zetasql/analyzer/name_scope.cc"

#if 0
namespace zetasql {

  std::string ValidNamePath::DebugString() const {
    return "";
  }

  std::string ValidFieldInfo::DebugString() const {
    return "";
  }

  ValidFieldInfoMap::~ValidFieldInfoMap() {}

  void ValidFieldInfoMap::InsertNamePath(const ResolvedColumn& column, const ValidNamePath& valid_name_path) {
  }

  bool ValidFieldInfoMap::LookupNamePathList(const ResolvedColumn& column,
                                             const ValidNamePathList** valid_name_path_list) const {
    return false;
  }

  void ValidFieldInfoMap::Clear() {
  }

  std::string ValidFieldInfoMap::DebugString(const std::string& indent) const {
    return "";
  }

  std::string NamedColumn::DebugString(const absl::string_view prefix) const {
    return "";
  }

  NameScope::NameScope(const NameScope* previous_scope,
                       const NameListPtr& name_list,
                       CorrelatedColumnsSet* correlated_columns_set)
    : previous_scope_(previous_scope),
      correlated_columns_set_(correlated_columns_set),
      // Copy state_ from name_list_.
      state_(name_list->name_scope_.state_) {
  }

  NameScope::NameScope(const NameScope* previous_scope,
                       const IdStringHashMapCase<NameTarget>& name_targets,
                       const std::vector<ValueTableColumn>& value_table_columns,
                       CorrelatedColumnsSet* correlated_columns_set)
    : previous_scope_(previous_scope),
      correlated_columns_set_(correlated_columns_set) {
  }

  NameScope::NameScope(const NameList& name_list)
    : state_(name_list.name_scope_.state_) {
  }

  NameScope::~NameScope() {
  }

  bool NameScope::IsEmpty() const {
    return false;
  }

  void NameScope::CopyStateFrom(const NameScope& other) {
  }

  void NameScope::AddNameTarget(IdString name, const NameTarget& target) {
  }

  void NameScope::AddColumn(IdString name, const ResolvedColumn& column,
                            bool is_explicit) {
  }

  void NameScope::AddRangeVariable(IdString name,
                                   const NameListPtr& scan_columns) {
  }

  bool NameScope::LookupName(IdString name, NameTarget* found,
                             CorrelatedColumnsSetList* correlated_columns_sets) const {
    return false;
  }

  absl::Status NameScope::LookupNamePath(const ASTPathExpression* path_expr,
                                         const char* clause_name,
                                         bool is_post_distinct,
                                         bool in_strict_mode,
                                         CorrelatedColumnsSetList* correlated_columns_sets,
                                         int* num_names_consumed,
                                         NameTarget* target_out) const {
    return absl::OkStatus();
  }

  absl::Status NameScope::CreateGetFieldTargetFromInvalidValueTableColumn(const ValueTableColumn& value_table_column, IdString field_name,
                                                                          NameTarget* field_target) {
    return absl::OkStatus();
  }

  Type::HasFieldResult NameScope::LookupFieldTargetLocalOnly(IdString name, NameTarget* field_target) const {
    Type::HasFieldResult v;
    return v;
  }

  bool NameScope::HasName(IdString name) const {
    return false;
  }

  std::string NameScope::SuggestName(IdString mistyped_name) const {
    return "";
  }

  bool NameScope::HasLocalRangeVariables() const {
    return false;
  }

  std::string NameScope::ValueTableColumn::DebugString() const {
    return "";
  }

  std::string NameScope::DebugString(const std::string& indent) const {
    return "";
  }

  void NameScope::InsertNameTargetsIfNotPresent(const IdStringHashMapCase<NameTarget>& names) {
  }

  void NameScope::ExcludeNameFromValueTableIfPresent(IdString name, ValueTableColumn* value_table_column) {
  }

  absl::Status NameScope::CopyNameScopeWithOverridingNames(const std::shared_ptr<NameList>& namelist_with_overriding_names,
                                                           std::unique_ptr<NameScope>* scope_with_new_names) const {
    return absl::OkStatus();
  }

  absl::Status NameScope::CopyNameScopeWithOverridingNameTargets(const IdStringHashMapCase<NameTarget>& overriding_name_targets,
                                                                 std::unique_ptr<NameScope>* scope_with_new_names) const {
    return absl::OkStatus();
  }

  void NameScope::CreateNewValueTableColumnsGivenValidNamePaths(const ValidFieldInfoMap& valid_field_info_map_in,
                                                                std::vector<ValueTableColumn>* new_value_table_columns) const {
  }

  absl::Status NameScope::CreateNewRangeVariableTargetGivenValidNamePaths(const NameTarget& original_name_target,
                                                                          const ValidFieldInfoMap& valid_field_info_map_in,
                                                                          NameTarget* new_name_target) {
    return absl::OkStatus();
  }

  absl::Status NameScope::CreateNewLocalNameTargetsGivenValidNamePaths(const ValidFieldInfoMap& valid_field_info_map_in,
                                                                       IdStringHashMapCase<NameTarget>* new_name_targets) const {
    return absl::OkStatus();
  }

  absl::Status NameScope::CreateNameScopeGivenValidNamePaths(const ValidFieldInfoMap& valid_field_info_map_in,
                                                             std::unique_ptr<NameScope>* new_name_scope) const {
    return absl::OkStatus();
  }

  void NameTarget::SetAccessError(const Kind original_kind,
                                  const std::string& access_error_message) {
  }

  bool NameTarget::Equals_TESTING(const NameTarget& other) const {
    return false;
  }

  std::string NameTarget::DebugString() const {
    return "";
  }

  NameList::NameList() {
  }

  NameList::~NameList() {
  }

  absl::Status NameList::AddColumn(IdString name, const ResolvedColumn& column, bool is_explicit) {
    return absl::OkStatus();
  }

  absl::Status NameList::AddValueTableColumn(IdString range_variable_name, const ResolvedColumn& column,
                                             const ASTNode* ast_location, const IdStringSetCase& excluded_field_names,
                                             const NameListPtr& pseudo_columns_name_list) {
    return absl::OkStatus();
  }

  absl::Status NameList::AddPseudoColumn(IdString name, const ResolvedColumn& column,
                                         const ASTNode* ast_location) {
    return absl::OkStatus();
  }

  bool NameList::HasRangeVariable(IdString name) const {
    return false;
  }

  absl::Status NameList::AddRangeVariable(IdString name,
                                          const NameListPtr& scan_columns,
                                          const ASTNode* ast_location) {
    return absl::OkStatus();
  }

  absl::Status NameList::AddAmbiguousColumn_Test(IdString name) {
    return absl::OkStatus();
  }

  absl::Status NameList::MergeFrom(const NameList& other,
                                   const ASTNode* ast_location) {
    return absl::OkStatus();
  }

  absl::Status NameList::MergeFromExceptColumns(const NameList& other,
                                                const IdStringSetCase* excluded_field_names,  // May be NULL
                                                const ASTNode* ast_location) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::shared_ptr<NameList>> NameList::AddRangeVariableInWrappingNameList(IdString alias, const ASTNode* ast_location,
                                                                                         std::shared_ptr<const NameList> original_name_list) {
    std::shared_ptr<NameList> v;
    return v;
  }

  absl::StatusOr<std::shared_ptr<NameList>> NameList::CloneWithNewColumns(const ASTNode* ast_location, absl::string_view value_table_error,
                                                                          const ASTAlias* alias,
                                                                          std::function<ResolvedColumn(const ResolvedColumn&)> clone_column,
                                                                          IdStringPool* id_string_pool) const {
    std::shared_ptr<NameList> v;
    return v;
  }

  std::vector<ResolvedColumn> NameList::GetResolvedColumns() const {
    std::vector<ResolvedColumn> v;
    return v;
  }

  std::vector<IdString> NameList::GetColumnNames() const {
    std::vector<IdString> v;
    return v;
  }

  bool NameList::LookupName(IdString name, NameTarget* found) const {
    return false;
  }

  Type::HasFieldResult NameList::SelectStarHasColumn(IdString name) const {
    Type::HasFieldResult v;
    return v;
  }

  std::string NameList::DebugString(absl::string_view indent) const {
    return "";
  }

}
#endif

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
