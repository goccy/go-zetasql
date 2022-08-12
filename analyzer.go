package zetasql

import (
	"fmt"
	"unsafe"

	"github.com/goccy/go-zetasql/ast"
	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
	"github.com/goccy/go-zetasql/resolved_ast"
	"github.com/goccy/go-zetasql/types"
)

import "C"

type AnalyzerOutput struct {
	raw unsafe.Pointer
}

type QueryParametersMap map[string]types.Type

// AnalyzerOptions contains options that affect analyzer behavior.
// The language options that control the language accepted are accessible via the Language() member.
type AnalyzerOptions struct {
	raw unsafe.Pointer
}

func NewAnalyzerOptions() *AnalyzerOptions {
	var v unsafe.Pointer
	internal.AnalyzerOptions_new(&v)
	return &AnalyzerOptions{raw: v}
}

// Language options for the language.
func (o *AnalyzerOptions) Language() *LanguageOptions {
	var v unsafe.Pointer
	internal.AnalyzerOptions_language(o.raw, &v)
	return &LanguageOptions{raw: v}
}

// SetLanguage.
func (o *AnalyzerOptions) SetLanguage(options *LanguageOptions) {
	internal.AnalyzerOptions_set_language(o.raw, options.raw)
}

// AddQueryParameter adds a named query parameter.
// Parameter name lookups are case insensitive.
// Paramater names in the output ParameterNode nodes will always be in lowercase.
//
// ZetaSQL only uses the parameter Type and not the Value. Query analysis is
// not dependent on the value, and query engines may substitute a value after
// analysis.
//
// For example, for the query
//   SELECT * FROM table WHERE CustomerId = @customer_id
// the parameter can be added using
//   analyzerOptions.AddQueryParameter("customer_id", types.Int64Type());
//
// Note that an error will be produced if type is not supported according to
// the current language options.
func (o *AnalyzerOptions) AddQueryParameter(name string, typ types.Type) error {
	var v unsafe.Pointer
	internal.AnalyzerOptions_AddQueryParameter(o.raw, helper.StringToPtr(name), getRawType(typ), &v)
	status := helper.NewStatus(v)
	if !status.OK() {
		return status.Error()
	}
	return nil
}

func (o *AnalyzerOptions) QueryParameters() QueryParametersMap {
	var v unsafe.Pointer
	internal.AnalyzerOptions_query_parameters(o.raw, &v)
	type queryParameter struct {
		name unsafe.Pointer
		typ  unsafe.Pointer
	}
	params := QueryParametersMap{}
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		param := (*queryParameter)(p)
		params[helper.PtrToString(param.name)] = newType(param.typ)
	})
	return params
}

// ClearQueryParameters clears <query_parameters_>.
func (o *AnalyzerOptions) ClearQueryParameters() {
	internal.AnalyzerOptions_clear_query_parameters(o.raw)
}

// AddPositionalQueryParameter adds a positional query parameter.
//
// ZetaSQL only uses the parameter Type and not the Value. Query analysis is
// not dependent on the value, and query engines may substitute a value after
// analysis.
//
// For example, for the query
//   SELECT * FROM table WHERE CustomerId = ?
// the parameter can be added using
//   analyzerOptions.AddPositionalQueryParameter(types.Int64Type());
//
// Note that an error will be produced if type is not supported according to
// the current language options. At least as many positional parameters must
// be provided as there are ? in the query. When allow_undeclared_parameters
// is true, no positional parameters may be provided.
func (o *AnalyzerOptions) AddPositionalQueryParameter(typ types.Type) error {
	var v unsafe.Pointer
	internal.AnalyzerOptions_AddPositionalQueryParameter(o.raw, getRawType(typ), &v)
	status := helper.NewStatus(v)
	if !status.OK() {
		return status.Error()
	}
	return nil
}

// PositionalQueryParameters defined positional parameters. Only used in positional parameter mode.
// Index 0 corresponds with the query parameter at position 1 and so on.
func (o *AnalyzerOptions) PositionalQueryParameters() []types.Type {
	var v unsafe.Pointer
	internal.AnalyzerOptions_positional_query_parameters(o.raw, &v)
	var ret []types.Type
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newType(p))
	})
	return ret
}

// ClearPositionalQueyParameters clears <positional_query_parameters_>.
func (o *AnalyzerOptions) ClearPositionalQueyParameters() {
	internal.AnalyzerOptions_clear_positional_query_parameters(o.raw)
}

// AddExpressionColumn add columns that are visible when resolving standalone expressions.
// These are used only in AnalyzeExpression, and have no effect on other
// analyzer entrypoints.
//
// AddExpressionColumn is used to add one or more columns resolvable by name.
//
// SetInScopeExpressionColumn is used to add at most one expression column
// that can be resolved by name (if <name> is non-empty), and is also
// implicitly in scope so that fields on the value can be used directly,
// without qualifiers.
// Expression column names take precedence over in-scope field names.
//
// SetLookupExpressionColumnCallback is used to add a callback function to
// resolve expression columns. The columns referenced in the expressions but
// not added in the above functions will be resolved using the callback
// function. The column name passed in the callback function is always in the
// lower case.
//
// Column name lookups are case insensitive.  Columns names in the output
// ExpressionColumnNode nodes will always be in lowercase.
//
// For example, to support the expression
//   enabled = true AND cost > 0.0
// those columns can be added using
//   analyzerOptions.AddExpressionColumn("enabled", types.BoolType());
//   analyzerOptions.AddExpressionColumn("cost", types.DoubleType());
//
// To evaluate an expression in the scope of a particular proto, like
//   has_cost AND cost > 0 AND value.cost != 10
//
// Note that an error will be produced if type is not supported according to
// the current language options.
func (o *AnalyzerOptions) AddExpressionColumn(name string, typ types.Type) error {
	var v unsafe.Pointer
	internal.AnalyzerOptions_AddExpressionColumn(o.raw, helper.StringToPtr(name), getRawType(typ), &v)
	status := helper.NewStatus(v)
	if !status.OK() {
		return status.Error()
	}
	return nil
}

func (o *AnalyzerOptions) SetInScopeExpressionColumn(name string, typ types.Type) error {
	var v unsafe.Pointer
	internal.AnalyzerOptions_SetInScopeExpressionColumn(o.raw, helper.StringToPtr(name), getRawType(typ), &v)
	status := helper.NewStatus(v)
	if !status.OK() {
		return status.Error()
	}
	return nil
}

// ExpressionColumns get the named expression columns added.
// This will include the in-scope expression column if one was set.
// This doesn't include the columns resolved using the LookupExpressionColumnCallback function.
func (o *AnalyzerOptions) ExpressionColumns() QueryParametersMap {
	var v unsafe.Pointer
	internal.AnalyzerOptions_expression_columns(o.raw, &v)
	type queryParameter struct {
		name unsafe.Pointer
		typ  unsafe.Pointer
	}
	params := QueryParametersMap{}
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		param := (*queryParameter)(p)
		params[helper.PtrToString(param.name)] = newType(param.typ)
	})
	return params
}

func (o *AnalyzerOptions) HasInScopeExpressionColumn() bool {
	var v bool
	internal.AnalyzerOptions_has_in_scope_expression_column(o.raw, &v)
	return v
}

// InScopeExpressionColumnName get the name and Type of the in-scope expression column.
// These return empty string and nil if there is no in-scope expression column.
func (o *AnalyzerOptions) InScopeExpressionColumnName() string {
	var v unsafe.Pointer
	internal.AnalyzerOptions_in_scope_expression_column_name(o.raw, &v)
	return helper.PtrToString(v)
}

func (o *AnalyzerOptions) InScopeExpressionColumnType() types.Type {
	var v unsafe.Pointer
	internal.AnalyzerOptions_in_scope_expression_column_type(o.raw, &v)
	return newType(v)
}

func (o *AnalyzerOptions) SetErrorMessageMode(mode ErrorMessageMode) {
	internal.AnalyzerOptions_set_error_message_mode(o.raw, int(mode))
}

func (o *AnalyzerOptions) ErrorMessageMode() ErrorMessageMode {
	var v int
	internal.AnalyzerOptions_error_message_mode(o.raw, &v)
	return ErrorMessageMode(v)
}

func (o *AnalyzerOptions) SetStatementContext(ctx StatementContext) {
	internal.AnalyzerOptions_set_statement_context(o.raw, int(ctx))
}

func (o *AnalyzerOptions) StatementContext() StatementContext {
	var v int
	internal.AnalyzerOptions_statement_context(o.raw, &v)
	return StatementContext(v)
}

func (o *AnalyzerOptions) SetParseLocationRecordType(typ ParseLocationRecordType) {
	internal.AnalyzerOptions_set_parse_location_record_type(o.raw, int(typ))
}

func (o *AnalyzerOptions) ParseLocationRecordType() ParseLocationRecordType {
	var v int
	internal.AnalyzerOptions_parse_location_record_type(o.raw, &v)
	return ParseLocationRecordType(v)
}

func (o *AnalyzerOptions) SetCreateNewColumnForEachProjectedOutput(v bool) {
	internal.AnalyzerOptions_set_create_new_column_for_each_projected_output(o.raw, helper.BoolToInt(v))
}

func (o *AnalyzerOptions) CreateNewColumnForEachProjectedOutput() bool {
	var v bool
	internal.AnalyzerOptions_create_new_column_for_each_projected_output(o.raw, &v)
	return v
}

// SetAllowUndeclaredParameters controls whether undeclared parameters are allowed.
// Undeclared parameters don't appear in QueryParameters().
// Their type will be assigned by the analyzer in the output AST and returned in
// AnalyzerOutput.UndeclaredParameters() or AnalyzerOutput.UndeclaredPositionalParameters() depending on the parameter mode.
// When AllowUndeclaredParameters is true and the parameter mode is positional,
// no positional parameters may be provided in AnalyzerOptions.
func (o *AnalyzerOptions) SetAllowUndeclaredParameters(v bool) {
	internal.AnalyzerOptions_set_allow_undeclared_parameters(o.raw, helper.BoolToInt(v))
}

func (o *AnalyzerOptions) AllowUndeclaredParameters() bool {
	var v bool
	internal.AnalyzerOptions_allow_undeclared_parameters(o.raw, &v)
	return v
}

// SetParameterMode controls whether positional parameters are allowed.
// The analyzer supports either named parameters or positional parameters
// but not both in the same query.
func (o *AnalyzerOptions) SetParameterMode(mode ParameterMode) {
	internal.AnalyzerOptions_set_parameter_mode(o.raw, int(mode))
}

func (o *AnalyzerOptions) ParameterMode() ParameterMode {
	var v int
	internal.AnalyzerOptions_parameter_mode(o.raw, &v)
	return ParameterMode(v)
}

func (o *AnalyzerOptions) SetPruneUnusedColumns(v bool) {
	internal.AnalyzerOptions_set_prune_unused_columns(o.raw, helper.BoolToInt(v))
}

func (o *AnalyzerOptions) PruneUnusedColumns() bool {
	var v bool
	internal.AnalyzerOptions_prune_unused_columns(o.raw, &v)
	return v
}

// SetPreserveColumnAliases controls whether to preserve aliases of aggregate columns and analytic
// function columns. This option has no effect on query semantics and just
// changes what names are used inside Columns.
//
// If true, the analyzer uses column aliases as names of aggregate columns and
// analytic function columns if they exist, and falls back to using internal
// names such as "$agg1" otherwise. If false, the analyzer uses internal names
// unconditionally.
//
// TODO: Make this the default and remove this option.
func (o *AnalyzerOptions) SetPreserveColumnAliases(v bool) {
	internal.AnalyzerOptions_set_preserve_column_aliases(o.raw, helper.BoolToInt(v))
}

func (o *AnalyzerOptions) PreserveColumnAliases() bool {
	var v bool
	internal.AnalyzerOptions_preserve_column_aliases(o.raw, &v)
	return v
}

func (o *AnalyzerOptions) ParserOptions() *ParserOptions {
	var v unsafe.Pointer
	internal.AnalyzerOptions_GetParserOptions(o.raw, &v)
	return newParserOptions(v)
}

// ValidateAnalyzerOptions verifies that the provided AnalyzerOptions have a valid combination of settings.
func ValidateAnalyzerOptions(opt *AnalyzerOptions) error {
	var v unsafe.Pointer
	internal.ValidateAnalyzerOptions(opt.raw, &v)
	status := helper.NewStatus(v)
	if !status.OK() {
		return status.Error()
	}
	return nil
}

func newAnalyzerOutput(raw unsafe.Pointer) *AnalyzerOutput {
	if raw == nil {
		return nil
	}
	return &AnalyzerOutput{raw: raw}
}

func (o *AnalyzerOutput) Statement() resolved_ast.StatementNode {
	var v unsafe.Pointer
	internal.AnalyzerOutput_resolved_statement(o.raw, &v)
	return newResolvedNode(v).(resolved_ast.StatementNode)
}

func (o *AnalyzerOutput) Expr() resolved_ast.ExprNode {
	return nil
}

type DeprecationWarnings struct {
}

func (o *AnalyzerOutput) DeprecationWarnings() *DeprecationWarnings {
	return nil
}

func (o *AnalyzerOutput) UndeclaredParameters() QueryParametersMap {
	return nil
}

func (o *AnalyzerOutput) UndeclaredPositionalParameters() []types.Type {
	return nil
}

func (o *AnalyzerOutput) MaxColumnID() int {
	return 0
}

type AnalyzerOutputProperties struct {
	HasFlatten       bool
	HasAnonymization bool
}

func (o *AnalyzerOutput) AnalyzerOutputProperties() *AnalyzerOutputProperties {
	return nil
}

// AnalyzeStatement analyze a ZetaSQL statement.
//
// This can return errors that point at a location in the input.
// How this location is reported is given by <opt.ErrorMessageMode()>.
func AnalyzeStatement(sql string, catalog types.Catalog, opt *AnalyzerOptions) (*AnalyzerOutput, error) {
	var (
		out    unsafe.Pointer
		status unsafe.Pointer
	)
	if catalog == nil {
		return nil, ErrRequiredCatalog
	}
	if opt == nil || opt.raw == nil {
		opt = NewAnalyzerOptions()
	}
	internal.AnalyzeStatement(
		helper.StringToPtr(sql),
		opt.raw,
		getRawCatalog(catalog),
		&out,
		&status,
	)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newAnalyzerOutput(out), nil
}

// AnalyzeNextStatement analyze one statement from a string that may contain multiple statements.
// This can be called in a loop with the same <resume_location> to parse all statements from a string.
//
// On successful return,
// <*at_end_of_input> is true if parsing reached the end of the string.
// <*output> contains the next statement found.
//
// Statements are separated by semicolons.  A final semicolon is not required
// on the last statement.  If only whitespace and comments follow the
// semicolon, isEnd will be set.
//
// This can return errors that point at a location in the input. How this
// location is reported is given by <opt.ErrorMessageMode()>.
//
// After an error, <resume_location> may not be updated and analyzing further
// statements is not supported.
func AnalyzeNextStatement(loc *ParseResumeLocation, catalog types.Catalog, opt *AnalyzerOptions) (*AnalyzerOutput, bool, error) {
	var (
		out    unsafe.Pointer
		isEnd  bool
		status unsafe.Pointer
	)
	if catalog == nil {
		return nil, false, ErrRequiredCatalog
	}
	if opt == nil || opt.raw == nil {
		opt = NewAnalyzerOptions()
	}
	internal.AnalyzeNextStatement(
		loc.raw,
		opt.raw,
		getRawCatalog(catalog),
		&out,
		&isEnd,
		&status,
	)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, false, st.Error()
	}
	return newAnalyzerOutput(out), isEnd, nil
}

// AnalyzeExpression analyze a ZetaSQL expression.
// The expression may include query parameters, subqueries, and any other valid expression syntax.
//
// The Catalog provides functions and named data types as usual.  If it
// includes Tables, those tables will be queryable in subqueries inside the
// expression.
//
// Column names added to <options> with AddExpressionColumn will be usable
// in the expression, and will show up as ExpressionColumn nodes in
// the output.
//
// Can return errors that point at a location in the input. This location can be
// reported in multiple ways depending on <options.error_message_mode()>.
func AnalyzeExpression(sql string, catalog types.Catalog, opt *AnalyzerOptions) (*AnalyzerOutput, error) {
	var (
		out    unsafe.Pointer
		status unsafe.Pointer
	)
	if catalog == nil {
		return nil, ErrRequiredCatalog
	}
	if opt == nil || opt.raw == nil {
		opt = NewAnalyzerOptions()
	}
	internal.AnalyzeExpression(
		helper.StringToPtr(sql),
		opt.raw,
		getRawCatalog(catalog),
		&out,
		&status,
	)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newAnalyzerOutput(out), nil
}

func AnalyzeType(typeName string, catalog types.Catalog, opt *AnalyzerOptions) ([]types.Type, error) {
	return nil, fmt.Errorf("go-zetasql: unimplemented")
}

func AnalyzeStatementFromParserAST(sql string, stmt ast.StatementNode, catalog types.Catalog, opt *AnalyzerOptions) (*AnalyzerOutput, error) {
	var (
		out    unsafe.Pointer
		status unsafe.Pointer
	)
	if catalog == nil {
		return nil, ErrRequiredCatalog
	}
	if opt == nil || opt.raw == nil {
		opt = NewAnalyzerOptions()
	}
	internal.AnalyzeStatementFromParserAST(
		getNodeRaw(stmt),
		opt.raw,
		helper.StringToPtr(sql),
		getRawCatalog(catalog),
		&out,
		&status,
	)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newAnalyzerOutput(out), nil
}

type TableNameSet struct{}

func ExtractTableNamesFromStatement(sql string) (*TableNameSet, error) {
	return nil, fmt.Errorf("go-zetasql: unimplemented")
}

func ExtractTableNamesFromNextStatement(loc *ParseResumeLocation) (*TableNameSet, bool, error) {
	return nil, false, fmt.Errorf("go-zetasql: unimplemented")
}

func ExtractTableNamesFromScript(sql string) (*TableNameSet, error) {
	return nil, fmt.Errorf("go-zetasql: unimplemented")
}
