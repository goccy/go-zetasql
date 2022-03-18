#ifndef ZETASQL_REFERENCE_IMPL_ALGEBRIZER_EXPORT_H
#define ZETASQL_REFERENCE_IMPL_ALGEBRIZER_EXPORT_H

#include "zetasql/reference_impl/algebrizer.h"
#include "zetasql/reference_impl/function.h"
#include "zetasql/reference_impl/operator.h"
#include "zetasql/reference_impl/tuple.h"

#include "zetasql/reference_impl/algebrizer.cc"

#if 0
namespace zetasql {

  Algebrizer::Algebrizer(const LanguageOptions& language_options,
                         const AlgebrizerOptions& algebrizer_options,
                         TypeFactory* type_factory, Parameters* parameters,
                         ParameterMap* column_map,
                         SystemVariablesAlgebrizerMap* system_variables_map)
    : language_options_(language_options),
      algebrizer_options_(algebrizer_options),
      column_to_variable_(absl::make_unique<ColumnToVariableMapping>(
                                                                     absl::make_unique<VariableGenerator>())),
      variable_gen_(column_to_variable_->variable_generator()),
      parameters_(parameters),
      column_map_(column_map),
      system_variables_map_(system_variables_map),
      type_factory_(type_factory),
      next_column_(0) {}

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeCast(const ResolvedCast* cast) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<InlineLambdaExpr>> Algebrizer::AlgebrizeLambda(const ResolvedInlineLambda* lambda) {
    std::unique_ptr<InlineLambdaExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeFunctionCallWithLambda(const ResolvedFunctionCall* function_call) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeFunctionCall(const ResolvedFunctionCall* function_call) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeCaseNoValue(const Type* output_type, std::vector<std::unique_ptr<ValueExpr>> args) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeCaseWithValue(const Type* output_type, std::vector<std::unique_ptr<ValueExpr>> args,
                                                                                const std::vector<ResolvedCollation>& collation_list) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeNotEqual(std::vector<std::unique_ptr<ValueExpr>> args) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeIf(const Type* output_type, std::vector<std::unique_ptr<ValueExpr>> args) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeIfNull(const Type* output_type, std::vector<std::unique_ptr<ValueExpr>> args) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeNullIf(const Type* output_type, std::vector<std::unique_ptr<ValueExpr>> args) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeCoalesce(const Type* output_type, std::vector<std::unique_ptr<ValueExpr>> args) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeIn(const Type* output_type, std::vector<std::unique_ptr<ValueExpr>> args) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeBetween(const Type* output_type, std::vector<std::unique_ptr<ValueExpr>> args) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<AggregateArg>> Algebrizer::AlgebrizeAggregateFn(const VariableId& variable,
                                                                                 absl::optional<AnonymizationOptions> anonymization_options,
                                                                                 std::unique_ptr<ValueExpr> filter, const ResolvedExpr* expr) {
    std::unique_ptr<AggregateArg> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<AggregateArg>> Algebrizer::AlgebrizeAggregateFnWithAlgebrizedArguments(const VariableId& variable,
                                                                                                        absl::optional<AnonymizationOptions> anonymization_options,
                                                                                                        std::unique_ptr<ValueExpr> filter, const ResolvedExpr* expr,
                                                                                                        std::vector<std::unique_ptr<ValueExpr>> arguments,
                                                                                                        std::unique_ptr<RelationalOp> group_rows_subquery) {
    std::unique_ptr<AggregateArg> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<NewStructExpr>> Algebrizer::MakeStruct(const ResolvedMakeStruct* make_struct) {
    std::unique_ptr<NewStructExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<FieldValueExpr>> Algebrizer::AlgebrizeGetStructField(const ResolvedGetStructField* get_struct_field) {
    std::unique_ptr<FieldValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ScalarFunctionCallExpr>> Algebrizer::AlgebrizeGetJsonField(const ResolvedGetJsonField* get_json_field) {
    std::unique_ptr<ScalarFunctionCallExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeGetProtoField(const ResolvedGetProtoField* get_proto_field) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeFlatten(const ResolvedFlatten* flatten) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeFlattenedArg(const ResolvedFlattenedArg* flattened_arg) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeGetProtoFieldOfPath(const ResolvedExpr* column_or_param_expr,
                                                                                      const std::vector<absl::variant<const ResolvedGetProtoField*,
                                                                                      const ResolvedGetStructField*>>& path) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeSubqueryExpr(const ResolvedSubqueryExpr* subquery_expr) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeLetExpr(const ResolvedLetExpr* let_expr) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeInArray(std::unique_ptr<ValueExpr> in_value, std::unique_ptr<ValueExpr> array_value,
                                                                          const ResolvedCollation& collation) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeInLikeAnyLikeAllRelation(std::unique_ptr<ValueExpr> lhs,
                                                                                           ResolvedSubqueryExpr::SubqueryType subquery_type,
                                                                                           const VariableId& haystack_var, std::unique_ptr<RelationalOp> haystack_rel,
                                                                                           const ResolvedCollation& collation) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeStandaloneExpression(const ResolvedExpr* expr) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeExpression(const ResolvedExpr* expr) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<Algebrizer::FilterConjunctInfo>> Algebrizer::FilterConjunctInfo::Create(const ResolvedExpr* conjunct) {
    std::unique_ptr<Algebrizer::FilterConjunctInfo> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeSingleRowScan() {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ArrayScanOp>> Algebrizer::CreateScanOfTableAsArray(const ResolvedScan* scan,
                                                                                    bool is_value_table,
                                                                                    std::unique_ptr<ValueExpr> table_expr) {
    std::unique_ptr<ArrayScanOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeTableScan(const ResolvedTableScan* table_scan,
                                                                               std::vector<FilterConjunctInfo*>* active_conjuncts) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::Status Algebrizer::TryAlgebrizeFilterConjunctAsColumnFilterArgs(const TableScanColumnInfoMap& column_info_map,
                                                                        const FilterConjunctInfo& conjunct_info,
                                                                        std::vector<std::unique_ptr<ColumnFilterArg>>* and_filters) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeWithScan(const ResolvedWithScan* scan) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeWithRefScan(const ResolvedWithRefScan* scan) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeArrayScan(const ResolvedArrayScan* array_scan,
                                                                               std::vector<FilterConjunctInfo*>* active_conjuncts) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeArrayScanWithoutJoin(const ResolvedArrayScan* array_scan,
                                                                                          std::vector<FilterConjunctInfo*>* active_conjuncts) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeLimitOffsetScan(const ResolvedLimitOffsetScan* scan) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::Status Algebrizer::AddFilterConjunctsTo(const ResolvedExpr* expr,
                                                std::vector<std::unique_ptr<FilterConjunctInfo>>* conjunct_infos) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeJoinScan(const ResolvedJoinScan* join_scan,
                                                                              std::vector<FilterConjunctInfo*>* active_conjuncts) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeJoinScanInternal(JoinOp::JoinKind join_kind, const ResolvedExpr* join_expr,
                                                                                      const ResolvedScan* left_scan,
                                                                                      const std::vector<ResolvedColumn>& right_output_column_list,
                                                                                      const RightScanAlgebrizerCb& right_scan_algebrizer_cb,
                                                                                      std::vector<FilterConjunctInfo*>* active_conjuncts) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::Status Algebrizer::NarrowJoinKindForFilterConjunct(const FilterConjunctInfo& conjunct_info,
                                                           const absl::flat_hash_set<ResolvedColumn>& left_output_columns,
                                                           const absl::flat_hash_set<ResolvedColumn>& right_output_columns,
                                                           JoinOp::JoinKind* join_kind) {
    return absl::OkStatus();
  }

  absl::Status Algebrizer::CanPushFilterConjunctIntoJoin(const FilterConjunctInfo& conjunct_info, JoinOp::JoinKind join_kind,
                                                         const absl::flat_hash_set<ResolvedColumn>& left_output_columns,
                                                         const absl::flat_hash_set<ResolvedColumn>& right_output_columns,
                                                         bool* push_down_to_join_condition, bool* push_down_to_left_input,
                                                         bool* push_down_to_right_input) {
    return absl::OkStatus();
  }

  absl::Status Algebrizer::CanPushFilterConjunctDownFromInnerJoinCondition(const FilterConjunctInfo& conjunct_info,
                                                                           const absl::flat_hash_set<ResolvedColumn>& left_output_columns,
                                                                           const absl::flat_hash_set<ResolvedColumn>& right_output_columns,
                                                                           bool* push_down_to_left_input, bool* push_down_to_right_input) {
    return absl::OkStatus();
  }

  absl::Status Algebrizer::AlgebrizeJoinConditionForHashJoin(const absl::flat_hash_set<ResolvedColumn>& left_output_columns,
                                                             const absl::flat_hash_set<ResolvedColumn>& right_output_columns,
                                                             std::vector<FilterConjunctInfo*>* conjuncts_with_push_down,
                                                             std::vector<JoinOp::HashJoinEqualityExprs>* hash_join_equality_exprs) {
    return absl::OkStatus();
  }

  absl::StatusOr<bool> Algebrizer::TryAlgebrizeFilterConjunctAsHashJoinEqualityExprs(const FilterConjunctInfo& conjunct_info,
                                                                                     const absl::flat_hash_set<ResolvedColumn>& left_output_columns,
                                                                                     const absl::flat_hash_set<ResolvedColumn>& right_output_columns,
                                                                                     int num_previous_equality_exprs,
                                                                                     JoinOp::HashJoinEqualityExprs* equality_exprs) {
    return false;
  }

  absl::Status Algebrizer::RemapJoinColumns(const ResolvedColumnList& columns,
                                            std::vector<std::unique_ptr<ExprArg>>* output) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeFilterScan(const ResolvedFilterScan* filter_scan,
                                                                                std::vector<FilterConjunctInfo*>* active_conjuncts) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::ApplyAlgebrizedFilterConjuncts(std::unique_ptr<RelationalOp> input,
                                                                                           std::vector<std::unique_ptr<ValueExpr>> algebrized_conjuncts) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeSampleScan(const ResolvedSampleScan* sample_scan,
                                                                                std::vector<FilterConjunctInfo*>* active_conjuncts) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<AggregateOp>> Algebrizer::AlgebrizeAggregateScan(const ResolvedAggregateScan* aggregate_scan) {
    std::unique_ptr<AggregateOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeAnonymizedAggregateScan(const ResolvedAnonymizedAggregateScan* anonymized_aggregate_scan) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeAnalyticScan(const ResolvedAnalyticScan* analytic_scan) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeAnalyticFunctionGroup(const std::set<ResolvedColumn>& input_resolved_columns,
                                                                                           const ResolvedAnalyticFunctionGroup* analytic_group,
                                                                                           std::unique_ptr<RelationalOp> input_relation_op,
                                                                                           bool input_is_from_same_analytic_scan) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::MaybeCreateSortForAnalyticOperator(const std::set<ResolvedColumn>& input_resolved_columns,
                                                                                               const ResolvedAnalyticFunctionGroup* analytic_group,
                                                                                               std::unique_ptr<RelationalOp> input_relation_op, bool require_stable_sort) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::Status Algebrizer::AlgebrizeOrderByItems(bool drop_correlated_columns, bool create_new_ids,
                                                 const std::vector<std::unique_ptr<const ResolvedOrderByItem>>&
                                                 order_by_items,
                                                 absl::flat_hash_map<int, VariableId>* column_to_id_map,
                                                 std::vector<std::unique_ptr<KeyArg>>* order_by_keys) {
    return absl::OkStatus();
  }

  absl::Status Algebrizer::AlgebrizePartitionExpressions(const ResolvedWindowPartitioning* partition_by,
                                                         absl::flat_hash_map<int, VariableId>* column_to_id_map,
                                                         std::vector<std::unique_ptr<KeyArg>>* partition_by_keys) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<AnalyticArg>> Algebrizer::AlgebrizeAnalyticFunctionCall(const VariableId& variable,
                                                                                         const ResolvedAnalyticFunctionCall* analytic_function_call) {
    std::unique_ptr<AnalyticArg> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<WindowFrameArg>> Algebrizer::AlgebrizeWindowFrame(const ResolvedWindowFrame* window_frame) {
    std::unique_ptr<WindowFrameArg> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<WindowFrameBoundaryArg>> Algebrizer::AlgebrizeWindowFrameExpr(const ResolvedWindowFrameExpr* window_frame_expr) {
    std::unique_ptr<WindowFrameBoundaryArg> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeSetOperationScan(const ResolvedSetOperationScan* set_scan) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeUnionScan(const ResolvedSetOperationScan* set_scan) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeExceptIntersectScan(const ResolvedSetOperationScan* set_scan) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeProjectScan(const ResolvedProjectScan* resolved_project,
                                                                                 std::vector<FilterConjunctInfo*>* active_conjuncts) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<SortOp>> Algebrizer::AlgebrizeOrderByScan(const ResolvedOrderByScan* scan, std::unique_ptr<ValueExpr> limit,
                                                                           std::unique_ptr<ValueExpr> offset) {
    std::unique_ptr<SortOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<AggregateOp>> Algebrizer::AlgebrizePivotScan(const ResolvedPivotScan* pivot_scan) {
    std::unique_ptr<AggregateOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeScan(const ResolvedScan* scan,
                                                                          std::vector<FilterConjunctInfo*>* active_conjuncts) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::MaybeApplyFilterConjuncts(std::unique_ptr<RelationalOp> input,
                                                                                      std::vector<FilterConjunctInfo*>* active_conjuncts) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeScan(const ResolvedScan* scan) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  bool Algebrizer::FindColumnDefinition(const std::vector<std::unique_ptr<const ResolvedComputedColumn>>& expr_list,
                                        int column_id, const ResolvedExpr** definition) {
    return false;
  }

  absl::StatusOr<std::unique_ptr<ArrayNestExpr>> Algebrizer::NestRelationInStruct(const ResolvedColumnList& output_columns,
                                                                                  std::unique_ptr<RelationalOp> relation, bool is_with_table) {
    std::unique_ptr<ArrayNestExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ArrayNestExpr>> Algebrizer::NestSingleColumnRelation(const ResolvedColumnList& output_columns,
                                                                                      std::unique_ptr<RelationalOp> relation,
                                                                                      bool is_with_table) {
    std::unique_ptr<ArrayNestExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeRootScanAsValueExpr(const ResolvedColumnList& output_columns, bool is_value_table,
                                                                                      const ResolvedScan* scan) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::WrapWithRootExpr(std::unique_ptr<ValueExpr> value_expr) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  std::unique_ptr<RootData> Algebrizer::GetRootData() {
    std::unique_ptr<RootData> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeQueryStatementAsRelation(const ResolvedQueryStmt* query, ResolvedColumnList* output_column_list,
                                                                                              std::vector<std::string>* output_column_names,
                                                                                              std::vector<VariableId>* output_column_variables) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ValueExpr>> Algebrizer::AlgebrizeDMLStatement(const ResolvedStatement* ast_root) {
    std::unique_ptr<ValueExpr> v;
    return v;
  }

  absl::Status Algebrizer::AlgebrizeDescendantsOfDMLStatement(const ResolvedStatement* ast_root, ResolvedScanMap* resolved_scan_map,
                                                              ResolvedExprMap* resolved_expr_map,
                                                              const ResolvedTableScan** resolved_table_scan) {
    return absl::OkStatus();
  }

  absl::Status Algebrizer::AlgebrizeDMLReturningClause(const ResolvedStatement* ast_root,
                                                       ResolvedColumnList* returning_column_list,
                                                       std::vector<std::unique_ptr<ValueExpr>>* returning_column_values) {
    return absl::OkStatus();
  }

  absl::Status Algebrizer::AlgebrizeDescendantsOfUpdateItem(const ResolvedUpdateItem* update_item, ResolvedScanMap* resolved_scan_map,
                                                            ResolvedExprMap* resolved_expr_map) {
    return absl::OkStatus();
  }

  absl::Status Algebrizer::PopulateResolvedScanMap(const ResolvedScan* resolved_scan, ResolvedScanMap* resolved_scan_map) {
    return absl::OkStatus();
  }

  absl::Status Algebrizer::PopulateResolvedExprMap(const ResolvedExpr* resolved_expr, ResolvedExprMap* resolved_expr_map) {
    return absl::OkStatus();
  }

  absl::StatusOr<ProtoFieldRegistry*> Algebrizer::AddProtoFieldRegistry(const absl::optional<SharedProtoFieldPath>& id) {
    return nullptr;
  }

  absl::StatusOr<ProtoFieldReader*> Algebrizer::AddProtoFieldReader(const absl::optional<SharedProtoFieldPath>& id,
                                                                    const ProtoFieldAccessInfo& access_info, ProtoFieldRegistry* registry) {
    return nullptr;
  }

  std::string Algebrizer::SharedProtoFieldPath::DebugString() const {
    return "";
  }

  absl::Status Algebrizer::AlgebrizeStatement(const LanguageOptions& language_options,
                                              const AlgebrizerOptions& algebrizer_options, TypeFactory* type_factory,
                                              const ResolvedStatement* ast_root, std::unique_ptr<ValueExpr>* output,
                                              Parameters* parameters, ParameterMap* column_map,
                                              SystemVariablesAlgebrizerMap* system_variables_map) {
    return absl::OkStatus();
  }

  absl::Status Algebrizer::AlgebrizeQueryStatementAsRelation(const LanguageOptions& language_options,
                                                             const AlgebrizerOptions& algebrizer_options, TypeFactory* type_factory,
                                                             const ResolvedQueryStmt* ast_root, ResolvedColumnList* output_column_list,
                                                             std::unique_ptr<RelationalOp>* output,
                                                             std::vector<std::string>* output_column_names,
                                                             std::vector<VariableId>* output_column_variables, Parameters* parameters,
                                                             ParameterMap* column_map,
                                                             SystemVariablesAlgebrizerMap* system_variables_map) {
    return absl::OkStatus();
  }

  absl::Status Algebrizer::AlgebrizeExpression(const LanguageOptions& language_options,
                                               const AlgebrizerOptions& algebrizer_options, TypeFactory* type_factory,
                                               const ResolvedExpr* ast_root, std::unique_ptr<ValueExpr>* output,
                                               Parameters* parameters, ParameterMap* column_map,
                                               SystemVariablesAlgebrizerMap* system_variables_map) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::FilterDuplicates(std::unique_ptr<RelationalOp> input, const ResolvedColumnList& column_list,
                                                                             VariableId row_set_id) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeRecursiveScan(const ResolvedRecursiveScan* recursive_scan) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::MapColumns(std::unique_ptr<RelationalOp> input,
                                                                       const ResolvedColumnList& input_columns,
                                                                       const ResolvedColumnList& output_columns) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeRecursiveRefScan(const ResolvedRecursiveRefScan* recursive_ref_scan) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<UnionAllOp::Input> Algebrizer::AlgebrizeUnpivotArg(const ResolvedUnpivotScan* unpivot_scan, const ExprArg& input,
                                                                    int arg_index) {
    UnionAllOp::Input v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<FilterOp>> Algebrizer::AlgebrizeNullFilterForUnpivotScan(const ResolvedUnpivotScan* unpivot_scan,
                                                                                          std::unique_ptr<RelationalOp> input) {
    std::unique_ptr<FilterOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeUnpivotScan(const ResolvedUnpivotScan* unpivot_scan) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<RelationalOp>> Algebrizer::AlgebrizeGroupRowsScan(const ResolvedGroupRowsScan* group_rows_scan) {
    std::unique_ptr<RelationalOp> v;
    return v;
  }

}
#endif

#include "go-zetasql/reference_impl/common/export.inc"
#include "go-zetasql/reference_impl/evaluation/export.inc"
#include "go-zetasql/reference_impl/parameters/export.inc"
#include "go-zetasql/reference_impl/proto_util/export.inc"
#include "go-zetasql/reference_impl/type_helpers/export.inc"
#include "go-zetasql/reference_impl/variable_generator/export.inc"
#include "go-zetasql/analyzer/resolver/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/flat_set/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/stl_util/export.inc"
#include "go-zetasql/common/aggregate_null_handling/export.inc"
#include "go-zetasql/common/internal_value/export.inc"
#include "go-zetasql/public/anonymization_utils/export.inc"
#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/coercer/export.inc"
#include "go-zetasql/public/evaluator_table_iterator/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/simple_catalog/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/public/functions/json/export.inc"
#include "go-zetasql/public/proto/type_annotation_cc_proto/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast_enums_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/serialization_cc_proto/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/cleanup/cleanup/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/container/node_hash_map/export.inc"
#include "go-absl/container/node_hash_set/export.inc"
#include "go-absl/hash/hash/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"
#include "go-absl/types/optional/export.inc"
#include "go-absl/types/span/export.inc"
#include "go-absl/types/variant/export.inc"
#include "go-protobuf/protobuf/export.inc"
#include "go-re2/re2/export.inc"

#endif
