package resolved_ast

import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
	"github.com/goccy/go-zetasql/types"
)

type Node interface {
	// Kind return this node's kind ( e.g. TableScan for TableScanNode ).
	Kind() Kind

	// IsScan return true if this node is under this node type.
	IsScan() bool
	IsExpression() bool
	IsStatement() bool

	// DebugString returns a string representation of this tree and all descendants, for
	// testing and debugging purposes. Each entry in <annotations> will cause the
	// subtree <annotation.node> to be annotated with the string
	// <annotation.annotation>. This can be used to explain the context of
	// certain individual nodes in the tree.
	DebugString() string

	// ChildNodes returns in 'child_nodes' all non-NULL Nodes that are children of
	// this node. The order of 'child_nodes' is deterministic, but callers should
	// not depend on how the roles (fields) correspond to locations, especially
	// because NULL children are omitted. For cases where the roles of child nodes
	// matter, use the specific getter functions provided by subnodes.
	ChildNodes() []Node

	// TreeDepth returns the depth of the AST tree rooted at the current node.
	// Considers all descendants of the current node, and returns the maximum
	// depth. Returns 1 if the current node is a leaf.
	TreeDepth() int

	//CheckNoFieldsAccessed() error
	//ClearFieldsAccessed()
	//MarkFieldsAccessed()

	// Returns the previously recorded parsed location range or nil.
	// Parse location ranges are only filled for some nodes (LiteralNodes in particular) and
	// only if AnalyzerOption.SetParseLocationRecordType() is set.
	ParseLocationRange() *types.ParseLocationRange

	getRaw() unsafe.Pointer
}

func getRawNode(n Node) unsafe.Pointer {
	return n.getRaw()
}

// ArgumentNode nodes are not self-contained nodes in the tree.
// They exist only to describe parameters to another node (e.g. columns in an OrderByNode).
// This node is here for organizational purposes only, to cluster these argument nodes.
type ArgumentNode interface {
	Node
}

type ExprNode interface {
	Node
	//AnnotatedType() *types.AnnotatedType
	Type() types.Type
	SetType(types.Type)
	TypeAnnotationMap() types.AnnotationMap
	SetTypeAnnotationMap(types.AnnotationMap)
}

type BaseNode struct {
	raw unsafe.Pointer
}

func (n *BaseNode) Kind() Kind {
	var v int
	internal.ResolvedNode_node_kind(n.raw, &v)
	return Kind(v)
}

func (n *BaseNode) IsScan() bool {
	var v bool
	internal.ResolvedNode_IsScan(n.raw, &v)
	return v
}

func (n *BaseNode) IsExpression() bool {
	var v bool
	internal.ResolvedNode_IsExpression(n.raw, &v)
	return v
}

func (n *BaseNode) IsStatement() bool {
	var v bool
	internal.ResolvedNode_IsStatement(n.raw, &v)
	return v
}

func (n *BaseNode) DebugString() string {
	var v unsafe.Pointer
	internal.ResolvedNode_DebugString(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *BaseNode) ChildNodes() []Node {
	var num int
	internal.ResolvedNode_GetChildNodes_num(n.raw, &num)
	ret := make([]Node, 0, num)
	for i := 0; i < num; i++ {
		var v unsafe.Pointer
		internal.ResolvedNode_GetChildNode(n.raw, i, &v)
		ret = append(ret, newNode(v))
	}
	return ret
}

func (n *BaseNode) ParseLocationRange() *types.ParseLocationRange {
	var v unsafe.Pointer
	internal.ResolvedNode_GetParseLocationRangeOrNULL(n.raw, &v)
	return newParseLocationRange(v)
}

func (n *BaseNode) TreeDepth() int {
	var v int
	internal.ResolvedNode_GetTreeDepth(n.raw, &v)
	return v
}

func (n *BaseNode) getRaw() unsafe.Pointer {
	return n.raw
}

type BaseArgumentNode struct {
	*BaseNode
}

type BaseExprNode struct {
	*BaseNode
}

func (n *BaseExprNode) Type() types.Type {
	var v unsafe.Pointer
	internal.ResolvedExpr_type(n.raw, &v)
	return newType(v)
}

func (n *BaseExprNode) SetType(v types.Type) {
	internal.ResolvedExpr_set_type(n.raw, getRawType(v))
}

func (n *BaseExprNode) TypeAnnotationMap() types.AnnotationMap {
	var v unsafe.Pointer
	internal.ResolvedExpr_type_annotation_map(n.raw, &v)
	return newAnnotationMap(v)
}

func (n *BaseExprNode) SetTypeAnnotationMap(v types.AnnotationMap) {
	internal.ResolvedExpr_set_type_annotation_map(n.raw, getRawAnnotationMap(v))
}

// LiteralNode any literal value, including NULL literals.
type LiteralNode struct {
	*BaseExprNode
}

func (n *LiteralNode) Value() types.Value {
	var v unsafe.Pointer
	internal.ResolvedLiteral_value(n.raw, &v)
	return newValue(v)
}

func (n *LiteralNode) SetValue(v types.Value) {
	internal.ResolvedLiteral_set_value(n.raw, getRawValue(v))
}

// HasExplicitType if true, then the literal is explicitly typed and cannot be used
// for literal coercions.
//
// This exists mainly for resolver bookkeeping and should be ignored by engines.
func (n *LiteralNode) HasExplicitType() bool {
	var v bool
	internal.ResolvedLiteral_has_explicit_type(n.raw, &v)
	return v
}

func (n *LiteralNode) SetHasExplicitType(v bool) {
	internal.ResolvedLiteral_set_has_explicit_type(n.raw, helper.BoolToInt(v))
}

// FloatLiteralID distinct ID of the literal, if it is a floating point value,
// within the resolved AST. When coercing from floating point
// to NUMERIC, the resolver uses the float_literal_id to find the
// original image of the literal to avoid precision loss. An ID of 0
// represents a literal without a cached image.
func (n *LiteralNode) FloatLiteralID() int {
	var v int
	internal.ResolvedLiteral_float_literal_id(n.raw, &v)
	return v
}

func (n *LiteralNode) SetFloatLiteralID(v int) {
	internal.ResolvedLiteral_set_float_literal_id(n.raw, v)
}

// PreserveInLiteralRemover indicates whether ReplaceLiteralsByParameters() should leave
// this literal value in place, rather than replace it with a query
// parameter.
func (n *LiteralNode) PreserveInLiteralRemover() bool {
	var v bool
	internal.ResolvedLiteral_preserve_in_literal_remover(n.raw, &v)
	return v
}

func (n *LiteralNode) SetPreserveInLiteralRemover(v bool) {
	internal.ResolvedLiteral_set_preserve_in_literal_remover(n.raw, helper.BoolToInt(v))
}

// ParameterNode
type ParameterNode struct {
	*BaseExprNode
}

// Name if non-empty, the name of the parameter.
//
// A ParameterNode will have either a name or a position but not both.
func (n *ParameterNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedParameter_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *ParameterNode) SetName(v string) {
	internal.ResolvedParameter_set_name(n.raw, helper.StringToPtr(v))
}

// Position if non-zero, the 1-based position of the positional parameter.
//
// A ParameterNode will have either a name or a position but not both.
func (n *ParameterNode) Position() int {
	var v int
	internal.ResolvedParameter_position(n.raw, &v)
	return v
}

func (n *ParameterNode) SetPosition(v int) {
	internal.ResolvedParameter_set_position(n.raw, v)
}

// IsUntyped if true, then the parameter has no specified type.
//
// This exists mainly for resolver bookkeeping and should be ignored by engines.
func (n *ParameterNode) IsUntyped() bool {
	var v bool
	internal.ResolvedParameter_is_untyped(n.raw, &v)
	return v
}

func (n *ParameterNode) SetIsUntyped(v bool) {
	internal.ResolvedParameter_set_is_untyped(n.raw, helper.BoolToInt(v))
}

// ExpressionColumnNode represents a column when analyzing a standalone expression.
// This is only used when the analyzer was called using AnalyzeExpression.
// Expression column names and types come from
// (*AnalyzerOptions).AddExpressionColumn.
// Name() will always be in lowercase.
type ExpressionColumnNode struct {
	*BaseExprNode
}

func (n *ExpressionColumnNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedExpressionColumn_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *ExpressionColumnNode) SetName(v string) {
	internal.ResolvedExpressionColumn_set_name(n.raw, helper.StringToPtr(v))
}

// ColumnRefNode an expression referencing the value of some column visible in the current Scan node.
//
// If isCorrelated is false, this must be a column visible in the Scan
// containing this expression, either because it was produced inside that
// Scan or it is on the ColumnList of some child of this Scan.
//
// If IsCorrelated is true, this references a column from outside a
// subquery that is visible as a correlated column inside.
// The column referenced here must show up on the parameters list for the subquery.
// See SubqueryExprNode.
type ColumnRefNode struct {
	*BaseExprNode
}

func (n *ColumnRefNode) Column() *Column {
	var v unsafe.Pointer
	internal.ResolvedColumnRef_column(n.raw, &v)
	return newColumn(v)
}

func (n *ColumnRefNode) SetColumn(v *Column) {
	internal.ResolvedColumnRef_set_column(n.raw, v.raw)
}

func (n *ColumnRefNode) IsCorrelated() bool {
	var v bool
	internal.ResolvedColumnRef_is_correlated(n.raw, &v)
	return v
}

func (n *ColumnRefNode) SetIsCorrelated(v bool) {
	internal.ResolvedColumnRef_set_is_correlated(n.raw, helper.BoolToInt(v))
}

// ConstantNode reference to a named constant.
type ConstantNode struct {
	*BaseExprNode
}

// Constant the matching Constant from the Catalog.
func (n *ConstantNode) Constant() types.Constant {
	var v unsafe.Pointer
	internal.ResolvedConstant_constant(n.raw, &v)
	return newConstant(v)
}

func (n *ConstantNode) SetConstant(v types.Constant) {
	internal.ResolvedConstant_set_constant(n.raw, getRawConstant(v))
}

// SystemVariableNode reference to a system variable.
type SystemVariableNode struct {
	*BaseExprNode
}

// NamePath path to system variable.
func (n *SystemVariableNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedSystemVariable_name_path(n.raw, &v)
	return helper.PtrToStrings(v)
}

func (n *SystemVariableNode) SetNamePath(v []string) {
	internal.ResolvedSystemVariable_set_name_path(n.raw, helper.StringsToPtr(v))
}

func (n *SystemVariableNode) AddNamePath(v string) {
	internal.ResolvedSystemVariable_add_name_path(n.raw, helper.StringToPtr(v))
}

// InlineLambdaNode a lambda expression, used inline as a function argument.
// This represents both the definition of the lambda and the resolution of
// its templated signature and body for this function call.
// Currently can only be used as an argument of a function.
//
// ArgumentList defines the argument types and names for the lambda, and
// creates new ColumnsNode which can be used to reference the arguments
// inside Body.
//
// The return type of the lambda function is the type of Body.
//
// In addition to the ArgumentList, the body of a lambda expression can
// reference columns visible to the scope of the function call for which this
// lambda is provided as an argument. Columns in this scope accessed by the
// body are stored in ParameterList.
//
// For example, the following query
//   SELECT ARRAY_FILTER([1,2,3], e -> e = key) FROM KeyValue;
// would have a lambda with ParameterList ['key'] and ArgumentList ['e'].
//
// Body is the body expression of the lambda. The expression can only
// reference columns in ParameterList and ArgumentList.
type InlineLambdaNode struct {
	*BaseArgumentNode
}

func (n *InlineLambdaNode) ArgumentList() []*Column {
	var v unsafe.Pointer
	internal.ResolvedInlineLambda_argument_list(n.raw, &v)
	var ret []*Column
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumn(p))
	})
	return ret
}

func (n *InlineLambdaNode) SetArgumentList(v []*Column) {
	internal.ResolvedInlineLambda_set_argument_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].raw
	}))
}

func (n *InlineLambdaNode) AddArgument(v *Column) {
	internal.ResolvedInlineLambda_add_argument(n.raw, v.raw)
}

func (n *InlineLambdaNode) ParameterList() []*ColumnRefNode {
	var v unsafe.Pointer
	internal.ResolvedInlineLambda_parameter_list(n.raw, &v)
	var ret []*ColumnRefNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumnRefNode(p))
	})
	return ret
}

func (n *InlineLambdaNode) SetParameterList(v []*ColumnRefNode) {
	internal.ResolvedInlineLambda_set_parameter_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *InlineLambdaNode) AddParameter(v *ColumnRefNode) {
	internal.ResolvedInlineLambda_add_parameter(n.raw, v.getRaw())
}

func (n *InlineLambdaNode) Body() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedInlineLambda_body(n.raw, &v)
	return newExprNode(v)
}

func (n *InlineLambdaNode) SetBody(v ExprNode) {
	internal.ResolvedInlineLambda_set_body(n.raw, v.getRaw())
}

// FilterFieldArgNode an argument to the FILTER_FIELDS() function which specifies a sign to show
// inclusion/exclusion status and a field path to include or exclude.
type FilterFieldArgNode struct {
	*BaseArgumentNode
}

// Include true if we want to include this proto path in the resulting proto
// (though we may still remove paths below it).
// If false, we will remove this path (but may still include paths below it).
func (n *FilterFieldArgNode) Include() bool {
	var v bool
	internal.ResolvedFilterFieldArg_include(n.raw, &v)
	return v
}

func (n *FilterFieldArgNode) SetInclude(v bool) {
	internal.ResolvedFilterFieldArg_set_include(n.raw, helper.BoolToInt(v))
}

// FilterFieldNode represents a call to the FILTER_FIELDS() function. This function can be
// used to modify a proto, prune fields and output the resulting proto. The
// SQL syntax for this function is
//   FILTER_FIELDS(<expr>, <filter_field_arg_list>).
//
// <expr> must have proto type. <filter_field_arg> contains a sign ('+' or
// '-') and a field path starting from the proto.
//
// For example:
//   FILTER_FIELDS(proto, +field1, -field1.field2)
// means the resulting proto only contains field1.* except field1.field2.*.
//
// Field paths are evaluated and processed in order,
// ```
//   IF filter_field_arg_list[0].include:
//     CLEAR all fields
//   FOR filter_field_arg IN filter_field_arg_list:
//     IF filter_field_arg.include:
//       UNCLEAR filter_field_arg.field_descriptor_path (and all children)
//     ELSE:
//       CLEAR filter_field_arg.field_descriptor_path (and all children)
// ```
//
// The order of field_field args have following constraints:
// 1. There must be at least one filter_field arg.
// 2. Args for ancestor fields must precede descendants.
// 3. Each arg must have opposite `include` compared to the last preceding
//    ancestor field.
type FilterFieldNode struct {
	*BaseExprNode
}

// Expr the proto to modify.
func (n *FilterFieldNode) Expr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedFilterField_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *FilterFieldNode) SetExpr(v ExprNode) {
	internal.ResolvedFilterField_set_expr(n.raw, v.getRaw())
}

func (n *FilterFieldNode) FilterFieldArgList() []*FilterFieldArgNode {
	var v unsafe.Pointer
	internal.ResolvedFilterField_filter_field_arg_list(n.raw, &v)
	var ret []*FilterFieldArgNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newFilterFieldArgNode(p))
	})
	return ret
}

func (n *FilterFieldNode) SetFilterFieldArgList(v []*FilterFieldArgNode) {
	internal.ResolvedFilterField_set_filter_field_arg_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *FilterFieldNode) AddFilterFieldArg(v *FilterFieldArgNode) {
	internal.ResolvedFilterField_add_filter_field_arg_list(n.raw, v.getRaw())
}

// ResetClearedRequiredFields if true, will reset cleared required fields into a default value.
func (n *FilterFieldNode) ResetClearedRequiredFields() bool {
	var v bool
	internal.ResolvedFilterField_reset_cleared_required_fields(n.raw, &v)
	return v
}

func (n *FilterFieldNode) SetResetClearedRequiredFields(v bool) {
	internal.ResolvedFilterField_set_reset_cleared_required_fields(n.raw, helper.BoolToInt(v))
}

// BaseFunctionCallNode common base node for scalar and aggregate function calls.
//
// <argument_list> contains a list of arguments of type ExprNode.
//
// <generic_argument_list> contains an alternative list of generic arguments.
// This is used for function calls that accept non-expression arguments (i.e.
// arguments that aren't part of the type system, like lambdas).
//
// If all arguments of this function call are ExprNodes, <argument_list>
// is used. If any of the argument is not a ExprNode,
// <generic_argument_list> will be used. Only one of <argument_list> or
// <generic_argument_list> can be non-empty.
//
// <collation_list> (only set when FEATURE_V_1_3_COLLATION_SUPPORT is
// enabled) is the operation collation to use.
// (broken link) lists the functions affected by
// collation, where this can show up.
// <collation_list> is a vector for future extension. For now, functions
// could have at most one element in the <collation_list>.
type BaseFunctionCallNode struct {
	*BaseExprNode
}

// Function the matching Function from the Catalog.
func (n *BaseFunctionCallNode) Function() *types.Function {
	var v unsafe.Pointer
	internal.ResolvedFunctionCallBase_function(n.raw, &v)
	return newFunction(v)
}

func (n *BaseFunctionCallNode) SetFunction(v *types.Function) {
	internal.ResolvedFunctionCallBase_set_function(n.raw, getRawFunction(v))
}

// Signature the concrete FunctionSignature reflecting the matching Function
// signature and the function's resolved input <argument_list>.
// The function has the mode AGGREGATE iff it is an aggregate
// function, in which case this node must be either
// AggregateFunctionCallNode or AnalyticFunctionCallNode.
func (n *BaseFunctionCallNode) Signature() *types.FunctionSignature {
	var v unsafe.Pointer
	internal.ResolvedFunctionCallBase_signature(n.raw, &v)
	return newFunctionSignature(v)
}

func (n *BaseFunctionCallNode) SetSignature(v *types.FunctionSignature) {
	internal.ResolvedFunctionCallBase_set_signature(n.raw, getRawFunctionSignature(v))
}

func (n *BaseFunctionCallNode) ArgumentList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedFunctionCallBase_argument_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *BaseFunctionCallNode) SetArgumentList(v []ExprNode) {
	internal.ResolvedFunctionCallBase_set_argument_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *BaseFunctionCallNode) AddArgument(v ExprNode) {
	internal.ResolvedFunctionCallBase_add_argument_list(n.raw, v.getRaw())
}

func (n *BaseFunctionCallNode) GenericArgumentList() []*FunctionArgumentNode {
	var v unsafe.Pointer
	internal.ResolvedFunctionCallBase_generic_argument_list(n.raw, &v)
	var ret []*FunctionArgumentNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newFunctionArgumentNode(p))
	})
	return ret
}

func (n *BaseFunctionCallNode) SetGenericArgumentList(v []*FunctionArgumentNode) {
	internal.ResolvedFunctionCallBase_set_generic_argument_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *BaseFunctionCallNode) AddGenericArgument(v *FunctionArgumentNode) {
	internal.ResolvedFunctionCallBase_add_generic_argument_list(n.raw, v.getRaw())
}

// ErrorMode if error_mode=SAFE_ERROR_MODE, and if this function call returns a
// semantic error (based on input data, not transient server
// problems), return NULL instead of an error. This is used for
// functions called using SAFE, as in SAFE.FUNCTION(...).
func (n *BaseFunctionCallNode) ErrorMode() ErrorMode {
	var v int
	internal.ResolvedFunctionCallBase_error_mode(n.raw, &v)
	return ErrorMode(v)
}

func (n *BaseFunctionCallNode) SetErrorMode(v ErrorMode) {
	internal.ResolvedFunctionCallBase_set_error_mode(n.raw, int(v))
}

// HintList function call hints.
func (n *BaseFunctionCallNode) HintList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedFunctionCallBase_hint_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *BaseFunctionCallNode) SetHintList(v []*OptionNode) {
	internal.ResolvedFunctionCallBase_set_hint_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *BaseFunctionCallNode) AddHint(v *OptionNode) {
	internal.ResolvedFunctionCallBase_add_hint_list(n.raw, v.getRaw())
}

func (n *BaseFunctionCallNode) CollationList() []*Collation {
	var v unsafe.Pointer
	internal.ResolvedFunctionCallBase_collation_list(n.raw, &v)
	var ret []*Collation
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newCollation(p))
	})
	return ret
}

func (n *BaseFunctionCallNode) SetCollationList(v []*Collation) {
	internal.ResolvedFunctionCallBase_set_collation_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].raw
	}))
}

func (n *BaseFunctionCallNode) AddCollation(v *Collation) {
	internal.ResolvedFunctionCallBase_add_collation_list(n.raw, v.raw)
}

// FunctionCallNode a regular function call.
// The signature will always have mode SCALAR.
// Most scalar expressions show up as FunctionCalls using builtin signatures.
type FunctionCallNode struct {
	*BaseFunctionCallNode
}

// FunctionCallInfo this contains optional custom information about a particular function call.
//
// If some Function subclass requires computing additional
// information at resolving time, that extra information can be
// stored as a subclass of FunctionCallInfoNode here.
// For example, TemplatedSQLFunction stores the resolved template
// body here as a TemplatedSQLFunctionCall.
//
// This field is ignorable because for most types of function calls,
// there is no extra information to consider besides the arguments
// and other fields from BaseFunctionCallNode.
func (n *FunctionCallNode) FunctionCallInfo() *FunctionCallInfo {
	var v unsafe.Pointer
	internal.ResolvedFunctionCall_function_call_info(n.raw, &v)
	return newFunctionCallInfo(v)
}

func (n *FunctionCallNode) SetFunctionCallInfo(v *FunctionCallInfo) {
	internal.ResolvedFunctionCall_set_function_call_info(n.raw, v.raw)
}

// BaseNonScalarFunctionCallNode common base node for scalar and aggregate function calls.
type BaseNonScalarFunctionCallNode struct {
	*BaseFunctionCallNode
}

// Distinct apply DISTINCT to the stream of input values before calling function.
func (n *BaseNonScalarFunctionCallNode) Distinct() bool {
	var v bool
	internal.ResolvedNonScalarFunctionCallBase_distinct(n.raw, &v)
	return v
}

func (n *BaseNonScalarFunctionCallNode) SetDistinct(v bool) {
	internal.ResolvedNonScalarFunctionCallBase_set_distinct(n.raw, helper.BoolToInt(v))
}

// NullHandlingModifier apply IGNORE/RESPECT NULLS filtering to the stream of input values.
func (n *BaseNonScalarFunctionCallNode) NullHandlingModifier() NullHandlingModifier {
	var v int
	internal.ResolvedNonScalarFunctionCallBase_null_handling_modifier(n.raw, &v)
	return NullHandlingModifier(v)
}

func (n *BaseNonScalarFunctionCallNode) SetNullHandlingModifier(v NullHandlingModifier) {
	internal.ResolvedNonScalarFunctionCallBase_set_null_handling_modifier(n.raw, int(v))
}

// WithGroupRowsSubquery holds a table subquery defined in WITH GROUP_ROWS(...) that is
// evaluated over the input rows of a AggregateScanNode
// corresponding to the current group. The function itself is
// evaluated over the rows returned from the subquery.
//
// The subquery should refer to a special TVF GROUP_ROWS(), which
// resolves as GroupRowsScanNode. The subquery will be run for
// each group produced by AggregateScanNode.
//
// GROUP_ROWS() produces a row for each source row in the
// AggregateScanNode's input that matches current group.
//
// The subquery cannot reference any Columns from the outer
// query except what comes in via <with_group_rows_parameter_list>,
// and GROUP_ROWS().
//
// The subquery can return more than one column, and these columns
// can be referenced by the function.
//
// The subquery can be correlated. In this case the
// <with_group_rows_parameter_list> gives the set of Columns
// from outside the subquery that are used inside. The subuery cannot
// refer to correlated columns that are used as aggregation input in
// the immediate outer query. The same rules apply to
// <with_group_rows_parameter_list> as in SubqueryExprNode.
func (n *BaseNonScalarFunctionCallNode) WithGroupRowsSubquery() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedNonScalarFunctionCallBase_with_group_rows_subquery(n.raw, &v)
	return newScanNode(v)
}

func (n *BaseNonScalarFunctionCallNode) SetWithGroupRowsSubquery(v ScanNode) {
	internal.ResolvedNonScalarFunctionCallBase_set_with_group_rows_subquery(n.raw, v.getRaw())
}

// WithGroupRowsParameterList correlated parameters to <with_group_rows_subquery>.
func (n *BaseNonScalarFunctionCallNode) WithGroupRowsParameterList() []*ColumnRefNode {
	var v unsafe.Pointer
	internal.ResolvedNonScalarFunctionCallBase_with_group_rows_parameter_list(n.raw, &v)
	var ret []*ColumnRefNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumnRefNode(p))
	})
	return ret
}

func (n *BaseNonScalarFunctionCallNode) SetWithGroupRowsParameterList(v []*ColumnRefNode) {
	internal.ResolvedNonScalarFunctionCallBase_set_with_group_rows_parameter_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *BaseNonScalarFunctionCallNode) AddWithGroupRowsParameter(v *ColumnRefNode) {
	internal.ResolvedNonScalarFunctionCallBase_add_with_group_rows_parameter_list(n.raw, v.getRaw())
}

// AggregateFunctionCallNode an aggregate function call.
// The signature always has mode AGGREGATE.
// This node only ever shows up as the outer function call in a AggregateScanNode.AggregateList.
type AggregateFunctionCallNode struct {
	*BaseNonScalarFunctionCallNode
}

// HavingModifier apply HAVING MAX/MIN filtering to the stream of input values.
func (n *AggregateFunctionCallNode) HavingModifier() *AggregateHavingModifierNode {
	var v unsafe.Pointer
	internal.ResolvedAggregateFunctionCall_having_modifier(n.raw, &v)
	return newAggregateHavingModifierNode(v)
}

func (n *AggregateFunctionCallNode) SetHavingModifier(v *AggregateHavingModifierNode) {
	internal.ResolvedAggregateFunctionCall_set_having_modifier(n.raw, v.getRaw())
}

// OrderByItemList apply ordering to the stream of input values before calling function.
func (n *AggregateFunctionCallNode) OrderByItemList() []*OrderByItemNode {
	var v unsafe.Pointer
	internal.ResolvedAggregateFunctionCall_order_by_item_list(n.raw, &v)
	var ret []*OrderByItemNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOrderByItemNode(p))
	})
	return ret
}

func (n *AggregateFunctionCallNode) SetOrderByItemList(v []*OrderByItemNode) {
	internal.ResolvedAggregateFunctionCall_set_order_by_item_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AggregateFunctionCallNode) AddOrderByItem(v *OrderByItemNode) {
	internal.ResolvedAggregateFunctionCall_add_order_by_item_list(n.raw, v.getRaw())
}

func (n *AggregateFunctionCallNode) Limit() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedAggregateFunctionCall_limit(n.raw, &v)
	return newExprNode(v)
}

func (n *AggregateFunctionCallNode) SetLimit(v ExprNode) {
	internal.ResolvedAggregateFunctionCall_set_limit(n.raw, v.getRaw())
}

// FunctionCallInfo this contains optional custom information about a particular
// function call. Functions may introduce subclasses of this class to
// add custom information as needed on a per-function basis.
//
// This field is ignorable because for most types of function calls,
// there is no extra information to consider besides the arguments
// and other fields from BaseFunctionCallNode. However, for
// example, the TemplateSQLFunction in
// zetasql/public/templated_sql_function.h defines the
// TemplatedSQLFunctionCall subclass which includes the
// fully-resolved function body in context of the actual concrete
// types of the arguments provided to the function call.
func (n *AggregateFunctionCallNode) FunctionCallInfo() *FunctionCallInfo {
	var v unsafe.Pointer
	internal.ResolvedAggregateFunctionCall_function_call_info(n.raw, &v)
	return newFunctionCallInfo(v)
}

func (n *AggregateFunctionCallNode) SetFunctionCallInfo(v *FunctionCallInfo) {
	internal.ResolvedAggregateFunctionCall_set_function_call_info(n.raw, v.raw)
}

// AnalyticFunctionCallNode an analytic function call.
// The mode of the function is either AGGREGATE or ANALYTIC.
// This node only ever shows up as a function call in a AnalyticFunctionGroupNode.AnalyticFunctionList.
// Its associated window is not under this node but as a sibling of its parent node.
//
// WindowFrame can be nil.
type AnalyticFunctionCallNode struct {
	*BaseNonScalarFunctionCallNode
}

func (n *AnalyticFunctionCallNode) WindowFrame() *WindowFrameNode {
	var v unsafe.Pointer
	internal.ResolvedAnalyticFunctionCall_window_frame(n.raw, &v)
	return newWindowFrameNode(v)
}

func (n *AnalyticFunctionCallNode) SetWindowFrame(v *WindowFrameNode) {
	internal.ResolvedAnalyticFunctionCall_set_window_frame(n.raw, v.getRaw())
}

// ExtendedCastElementNode describes a leaf extended cast of ExtendedCastNode.
// See the comment for ElementList field of ExtendedCastNode for more details.
type ExtendedCastElementNode struct {
	*BaseArgumentNode
}

func (n *ExtendedCastElementNode) FromType() types.Type {
	var v unsafe.Pointer
	internal.ResolvedExtendedCastElement_from_type(n.raw, &v)
	return newType(v)
}

func (n *ExtendedCastElementNode) SetFromType(v types.Type) {
	internal.ResolvedExtendedCastElement_set_from_type(n.raw, getRawType(v))
}

func (n *ExtendedCastElementNode) ToType() types.Type {
	var v unsafe.Pointer
	internal.ResolvedExtendedCastElement_to_type(n.raw, &v)
	return newType(v)
}

func (n *ExtendedCastElementNode) SetToType(v types.Type) {
	internal.ResolvedExtendedCastElement_set_to_type(n.raw, getRawType(v))
}

func (n *ExtendedCastElementNode) Function() *types.Function {
	var v unsafe.Pointer
	internal.ResolvedExtendedCastElement_function(n.raw, &v)
	return newFunction(v)
}

func (n *ExtendedCastElementNode) SetFunction(v *types.Function) {
	internal.ResolvedExtendedCastElement_set_function(n.raw, getRawFunction(v))
}

// ExtendedCastNode describes overall cast operation between two values where at least one
// value's type is or contains an extended type (e.g. on a struct field).
type ExtendedCastNode struct {
	*BaseArgumentNode
}

// ElementList stores the list of leaf extended casts required as elements of this cast.
// Each element is a cast where at least one of the input or output is an extended type.
// For structs or arrays, the elements will be casts for the field or element types.
// For structs, there can be multiple cast elements (one for each distinct pair of field types).
// For non-struct types, there will be just a single element.
func (n *ExtendedCastNode) ElementList() []*ExtendedCastElementNode {
	var v unsafe.Pointer
	internal.ResolvedExtendedCast_element_list(n.raw, &v)
	var ret []*ExtendedCastElementNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExtendedCastElementNode(p))
	})
	return ret
}

func (n *ExtendedCastNode) SetElementList(v []*ExtendedCastElementNode) {
	internal.ResolvedExtendedCast_set_element_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *ExtendedCastNode) AddElement(v *ExtendedCastElementNode) {
	internal.ResolvedExtendedCast_add_element_list(n.raw, v.getRaw())
}

// CastNode a cast expression, casting the result of an input expression to the target Type.
//
// Valid casts are defined in the CastHashMap, which identifies
// valid from-Type, to-Type pairs.
// Consumers can access it through ZetaSQLCasts().
type CastNode struct {
	*BaseExprNode
}

func (n *CastNode) Expr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCast_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *CastNode) SetExpr(v ExprNode) {
	internal.ResolvedCast_set_expr(n.raw, v.getRaw())
}

// ReturnNullOnError whether to return NULL if the cast fails.
// This is set to true for SAFE_CAST.
func (n *CastNode) ReturnNullOnError() bool {
	var v bool
	internal.ResolvedCast_return_null_on_error(n.raw, &v)
	return v
}

func (n *CastNode) SetReturnNullOnError(v bool) {
	internal.ResolvedCast_set_return_null_on_error(n.raw, helper.BoolToInt(v))
}

// ExtendedCast if at least one of types involved in this cast is or contains an
// extended (TYPE_EXTENDED) type, this field contains information
// necessary to execute this cast.
func (n *CastNode) ExtendedCast() *ExtendedCastNode {
	var v unsafe.Pointer
	internal.ResolvedCast_extended_cast(n.raw, &v)
	return newExtendedCastNode(v)
}

func (n *CastNode) SetExtendedCast(v *ExtendedCastNode) {
	internal.ResolvedCast_set_extended_cast(n.raw, v.getRaw())
}

// Format the format string specified by the optional FORMAT clause.
// It is nullptr when the clause does not exist.
func (n *CastNode) Format() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCast_format(n.raw, &v)
	return newExprNode(v)
}

func (n *CastNode) SetFormat(v ExprNode) {
	internal.ResolvedCast_set_format(n.raw, v.getRaw())
}

// TimeZone the time zone expression by the optional AT TIME ZONE clause.
// It is nullptr when the clause does not exist.
func (n *CastNode) TimeZone() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCast_time_zone(n.raw, &v)
	return newExprNode(v)
}

func (n *CastNode) SetTimeZone(v ExprNode) {
	internal.ResolvedCast_set_time_zone(n.raw, v.getRaw())
}

// TypeParameters contains the TypeParametersProto, which stores the type parameters
// if specified in a cast. If there are no type parameters, this
// proto will be empty.
//
// If type parameters are specified, the result of the cast should
// conform to the type parameters. Engines are expected to enforce
// type parameter constraints by erroring out or truncating the cast
// result, depending on the output type.
//
// For example:
//   CAST("ABC" as STRING(2)) should error out
//   CAST(1234 as NUMERIC(2)) should error out
//   CAST(1.234 as NUMERIC(2,1)) should return a NumericValue of 1.2
//
func (n *CastNode) TypeParameters() *types.TypeParameters {
	var v unsafe.Pointer
	internal.ResolvedCast_type_parameters(n.raw, &v)
	return newTypeParameters(v)
}

func (n *CastNode) SetTypeParameters(v *types.TypeParameters) {
	internal.ResolvedCast_set_type_parameters(n.raw, getRawTypeParameters(v))
}

// MakeStructNode construct a struct value.
// Type is always a StructType.
// FieldList matches 1:1 with the fields in Type position-wise.
// Each field's type will match the corresponding field in Type.
type MakeStructNode struct {
	*BaseExprNode
}

func (n *MakeStructNode) FieldList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedMakeStruct_field_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *MakeStructNode) SetFieldList(v []ExprNode) {
	internal.ResolvedMakeStruct_set_field_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *MakeStructNode) AddField(v ExprNode) {
	internal.ResolvedMakeStruct_add_field_list(n.raw, v.getRaw())
}

// MakeProtoNode construct a proto value.
// Type is always a ProtoType.
// FieldList is a vector of (FieldDescriptor, expr) pairs to write.
// FieldList will contain all required fields, and no duplicate fields.
type MakeProtoNode struct {
	*BaseExprNode
}

func (n *MakeProtoNode) FieldList() []*MakeProtoFieldNode {
	var v unsafe.Pointer
	internal.ResolvedMakeProto_field_list(n.raw, &v)
	var ret []*MakeProtoFieldNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newMakeProtoFieldNode(p))
	})
	return ret
}

func (n *MakeProtoNode) SetFieldList(v []*MakeProtoFieldNode) {
	internal.ResolvedMakeProto_set_field_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *MakeProtoNode) AddField(v *MakeProtoFieldNode) {
	internal.ResolvedMakeProto_add_field_list(n.raw, v.getRaw())
}

// MakeProtoFieldNode one field assignment in a MakeProtoNode expression.
// The type of expr will match with the zetasql type of the proto field.
// The type will be an array if the field is repeated.
//
// For NULL values of Expr, the proto field should be cleared.
//
// If any value of Expr cannot be written into the field, this query should fail.
type MakeProtoFieldNode struct {
	*BaseArgumentNode
}

// Format provides the Format annotation that should be used when building this field.
// The annotation specifies both the ZetaSQL type and the encoding format for this field.
func (n *MakeProtoFieldNode) Format() FieldFormat {
	var v int
	internal.ResolvedMakeProtoField_format(n.raw, &v)
	return FieldFormat(v)
}

func (n *MakeProtoFieldNode) SetFormat(v FieldFormat) {
	internal.ResolvedMakeProtoField_set_format(n.raw, int(v))
}

func (n *MakeProtoFieldNode) Expr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedMakeProtoField_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *MakeProtoFieldNode) SetExpr(v ExprNode) {
	internal.ResolvedMakeProtoField_set_expr(n.raw, v.getRaw())
}

// GetStructFieldNode get the field in position FieldIdx (0-based) from Expr, which has a STRUCT type.
type GetStructFieldNode struct {
	*BaseExprNode
}

func (n *GetStructFieldNode) Expr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedGetStructField_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *GetStructFieldNode) SetExpr(v ExprNode) {
	internal.ResolvedGetStructField_set_expr(n.raw, v.getRaw())
}

func (n *GetStructFieldNode) FieldIdx() int {
	var v int
	internal.ResolvedGetStructField_field_idx(n.raw, &v)
	return v
}

func (n *GetStructFieldNode) SetFieldIdx(v int) {
	internal.ResolvedGetStructField_set_field_idx(n.raw, v)
}

// GetProtoFieldNode.
type GetProtoFieldNode struct {
	*BaseExprNode
}

func (n *GetProtoFieldNode) Expr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedGetProtoField_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *GetProtoFieldNode) SetExpr(v ExprNode) {
	internal.ResolvedGetProtoField_set_expr(n.raw, v.getRaw())
}

// DefaultValue to use when the proto field is not set.
// The default may be nil (e.g. for proto2 fields with a use_defaults=false annotation).
//
// This will not be filled in (the Value will be uninitialized) if
// HasBit is true, or the field is required.
//
// If FieldDescriptor().IsRequired() and the field is not present,
// the engine should return an error.
//
// If the Expr itself returns nil, then extracting a field should
// also return nil, unless ReturnDefaultValueWhenUnset is true.
// In that case, the default value is returned.
//
// TODO Make un-ignorable after clients migrate to start using it.
func (n *GetProtoFieldNode) DefaultValue() types.Value {
	var v unsafe.Pointer
	internal.ResolvedGetProtoField_default_value(n.raw, &v)
	return newValue(v)
}

func (n *GetProtoFieldNode) SetDefaultValue(v types.Value) {
	internal.ResolvedGetProtoField_set_default_value(n.raw, getRawValue(v))
}

// HasBit indicates whether to return a bool indicating if a value was
// present, rather than return the value (or nil). Never set for
// repeated fields. This field cannot be set if
// ReturnDefaultValueWhenUnset is true, and vice versa.
// Expression type will be BOOL.
func (n *GetProtoFieldNode) HasBit() bool {
	var v bool
	internal.ResolvedGetProtoField_get_has_bit(n.raw, &v)
	return v
}

func (n *GetProtoFieldNode) SetHasBit(v bool) {
	internal.ResolvedGetProtoField_set_get_has_bit(n.raw, helper.BoolToInt(v))
}

// Format provides the Format annotation that should be used when reading
// this field.  The annotation specifies both the ZetaSQL type and
// the encoding format for this field. This cannot be set when
// HasBit is true.
func (n *GetProtoFieldNode) Format() FieldFormat {
	var v int
	internal.ResolvedGetProtoField_format(n.raw, &v)
	return FieldFormat(v)
}

func (n *GetProtoFieldNode) SetFormat(v FieldFormat) {
	internal.ResolvedGetProtoField_set_format(n.raw, int(v))
}

// ReturnDefaultValueWhenUnset indicates that the default value should be returned if Expr
// (the parent message) is nil. Note that this does *not* affect
// the return value when the extracted field itself is unset, in
// which case the return value depends on the extracted field's
// annotations (e.g., UseFieldDefaults).
//
// This can only be set for non-message fields. If the field is a
// proto2 field, then it must be annotated with
// zetasql.UseDefaults=true. This cannot be set when HasBit is true or the field is required.
func (n *GetProtoFieldNode) ReturnDefaultValueWhenUnset() bool {
	var v bool
	internal.ResolvedGetProtoField_return_default_value_when_unset(n.raw, &v)
	return v
}

func (n *GetProtoFieldNode) SetReturnDefaultValueWhenUnset(v bool) {
	internal.ResolvedGetProtoField_set_return_default_value_when_unset(n.raw, helper.BoolToInt(v))
}

// GetJsonFieldNode get the field FieldName from Expr, which has a JSON type.
type GetJsonFieldNode struct {
	*BaseExprNode
}

func (n *GetJsonFieldNode) Expr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedGetJsonField_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *GetJsonFieldNode) SetExpr(v ExprNode) {
	internal.ResolvedGetJsonField_set_expr(n.raw, v.getRaw())
}

func (n *GetJsonFieldNode) FieldName() string {
	var v unsafe.Pointer
	internal.ResolvedGetJsonField_field_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *GetJsonFieldNode) SetFieldName(v string) {
	internal.ResolvedGetJsonField_set_field_name(n.raw, helper.StringToPtr(v))
}

// FlattenNode constructs an initial input ARRAY<T> from expr.
// For each FieldList expr, we evaluate the expression once with each array input element and
// use the output as a new array of inputs for the next FieldList expr.
// If the result of a single expr is an array, we add each element from that
// array as input to the next step instead of adding the array itself.
//
// The array elements are evaluated and kept in order. For example, if only
// expr is an array, the result will be equivalent to that array having the
// FieldList evaluated on each array element retaining order.
type FlattenNode struct {
	*BaseExprNode
}

func (n *FlattenNode) Expr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedFlatten_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *FlattenNode) SetExpr(v ExprNode) {
	internal.ResolvedFlatten_set_expr(n.raw, v.getRaw())
}

// FieldList list of 'get' fields to evaluate in order (0 or more struct get
// fields followed by 0 or more proto or json get fields) starting
// from expr. Each get is evaluated N times where N is the number of
// array elements from the previous get (or expr for the first expression) generated.
//
// The 'get' fields may either be a Get*Field or an array
// offset function around a Get*Field.
func (n *FlattenNode) GetFieldList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedFlatten_get_field_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *FlattenNode) SetGetFieldList(v []ExprNode) {
	internal.ResolvedFlatten_set_get_field_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))

}

func (n *FlattenNode) AddGetField(v ExprNode) {
	internal.ResolvedFlatten_add_get_field_list(n.raw, v.getRaw())
}

// FlattenArgNode argument for a child of FlattenNode.
// This is a placeholder to indicate that it will be invoked once for each
// array element from FlattenNode's expr or previous GetfieldList entry.
type FlattenedArgNode struct {
	*BaseExprNode
}

// ReplaceFieldItemNode an argument to the REPLACE_FIELDS() function which specifies a field path
// and a value that this field will be set to. The field path to be modified
// can be constructed through the StructIndexPath and ProtoFieldPath fields.
// These vectors correspond to field paths in a STRUCT and PROTO, respectively.
// At least one of these vectors must be non-empty.
//
// If only StructIndexPath is non-empty, then the field path only
// references top-level and nested struct fields.
//
// If only ProtoFieldPath is non-empty, then the field path only
// references top-level and nested message fields.
//
// If both StructIndexPath and ProtoFieldPath are non-empty, then the
// field path should be expanded starting with StructIndexPath.
// The last field in StructIndexPath will be the proto from which the first field
// in ProtoFieldPath is extracted.
//
// Expr and the field to be modified must be the same type.
type ReplaceFieldItemNode struct {
	*BaseArgumentNode
}

// Expr the value that the final field in <proto_field_path> will be set to.
//
// If <expr> is NULL, the field will be unset. If <proto_field_path>
// is a required field, the engine must return an error if it is set to NULL.
func (n *ReplaceFieldItemNode) Expr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedReplaceFieldItem_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *ReplaceFieldItemNode) SetExpr(v ExprNode) {
	internal.ResolvedReplaceFieldItem_set_expr(n.raw, v.getRaw())
}

// StructIndexPath a vector of integers that denotes the path to a struct field that
// will be modified. The integer values in this vector correspond to
// field positions (0-based) in a STRUCT. If <proto_field_path>
// is also non-empty, then the field corresponding to the last index
// in this vector should be of proto type.
func (n *ReplaceFieldItemNode) StructIndexPath() []int {
	var v unsafe.Pointer
	internal.ResolvedReplaceFieldItem_struct_index_path(n.raw, &v)
	var ret []int
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, int(uintptr(p)))
	})
	return ret
}

func (n *ReplaceFieldItemNode) SetStructIndexPath(v []int) {
	internal.ResolvedReplaceFieldItem_set_struct_index_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return unsafe.Pointer(uintptr(v[i]))
	}))
}

func (n *ReplaceFieldItemNode) AddStructIndexPath(v int) {
	internal.ResolvedReplaceFieldItem_add_struct_index_path(n.raw, v)
}

// ReplaceFieldNode represents a call to the REPLACE_FIELDS() function.
// This function can be used to copy a proto or struct, modify a few fields and
// output the resulting proto or struct. The SQL syntax for this
// function is REPLACE_FIELDS(<expr>, <replace_field_item_list>).
type ReplaceFieldNode struct {
	*BaseExprNode
}

// Expr the proto/struct to modify.
func (n *ReplaceFieldNode) Expr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedReplaceField_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *ReplaceFieldNode) SetExpr(v ExprNode) {
	internal.ResolvedReplaceField_set_expr(n.raw, v.getRaw())
}

// ReplaceFieldItemList the list of field paths to be modified along with their new values.
//
// Engines must check at evaluation time that the modifications in
// ReplaceFieldItemList obey the following rules
// regarding updating protos in ZetaSQL:
// - Modifying a subfield of a NULL-valued proto-valued field is an error.
// - Clearing a required field or subfield is an error.
func (n *ReplaceFieldNode) ReplaceFieldItemList() []*ReplaceFieldItemNode {
	var v unsafe.Pointer
	internal.ResolvedReplaceField_replace_field_item_list(n.raw, &v)
	var ret []*ReplaceFieldItemNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newReplaceFieldItemNode(p))
	})
	return ret
}

func (n *ReplaceFieldNode) SetReplaceFieldItemList(v []*ReplaceFieldItemNode) {
	internal.ResolvedReplaceField_set_replace_field_item_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *ReplaceFieldNode) AddReplaceFieldItem(v *ReplaceFieldItemNode) {
	internal.ResolvedReplaceField_add_replace_field_item_list(n.raw, v.getRaw())
}

// SubqueryExprNode a subquery in an expression (not a FROM clause).
// The subquery runs in the context of a single input row and produces a single output value.
//
// Correlated subqueries can be thought of like functions, with a parameter
// list.  The ParameterList gives the set of ColumnsNode from outside the subquery that are used inside.
//
// Inside the subquery, the only allowed references to values outside the
// subquery are to the named ColumnRefs listed in ParameterList.
// Any reference to one of these parameters will be represented as a
// ColumnRefNode with isCorrelated set to true.
//
// These parameters are only visible through one level of expression subquery.
// An expression subquery inside an expression has to list
// parameters again if parameters from the outer query are passed down further.
// (This does not apply for table subqueries inside an expression subquery.
// Table subqueries are never indicated in the resolved AST,
// so Scan nodes inside an expression query may have come from a nested table subquery,
// and they can still reference the expression subquery's parameters.)
//
// An empty ParameterList means that the subquery is uncorrelated.
// It is permissable to run an uncorrelated subquery only once and reuse the result.
// TODO Do we want to specify semantics more firmly here?
//
// The semantics vary based on SubqueryType:
//   SCALAR
//     Usage: ( <subquery> )
//     If the subquery produces zero rows, the output value is NULL.
//     If the subquery produces exactly one row, that row is the output value.
//     If the subquery produces more than one row, raise a runtime error.
//
//   ARRAY
//     Usage: ARRAY( <subquery> )
//     The subquery produces an array value with zero or more rows, with
//     one array element per subquery row produced.
//
//   EXISTS
//     Usage: EXISTS( <subquery> )
//     The output type is always bool.  The result is true if the subquery
//     produces at least one row, and false otherwise.
//
//   IN
//     Usage: <in_expr> [NOT] IN ( <subquery> )
//     The output type is always bool.  The result is true when <in_expr> is
//     equal to at least one row, and false otherwise.  The <subquery> row
//     contains only one column, and the types of <in_expr> and the
//     subquery column must exactly match a built-in signature for the
//     '$equals' comparison function (they must be the same type or one
//     must be INT64 and the other UINT64).  NOT will be expressed as a $not
//     FunctionCall wrapping this SubqueryExpr.
//
//  LIKE
//     Usage: <in_expr> [NOT] LIKE ANY|SOME|ALL ( <subquery> )
//     The output type is always bool. The result is true when <in_expr>
//     matches at least one row for LIKE ANY|SOME or matches all rows for
//     LIKE ALL, and false otherwise.  The <subquery> row contains only one
//     column, and the types of <in_expr> and the subquery column must
//     exactly match a built-in signature for the relevant '$like_any' or
//     '$like_all' comparison function (both must be the same type of either
//     STRING or BYTES).  NOT will be expressed as a $not FunctionCall
//     wrapping this SubqueryExpr.
//
// The subquery for a SCALAR, ARRAY, IN or LIKE subquery must have exactly
// one output column.
// The output type for a SCALAR or ARRAY subquery is that column's type or
// an array of that column's type.  (The subquery scan may include a Project
// with a MakeStruct or MakeProto expression to construct a single value from multiple columns.)
type SubqueryExprNode struct {
	*BaseExprNode
}

func (n *SubqueryExprNode) SubqueryType() SubqueryType {
	var v int
	internal.ResolvedSubqueryExpr_subquery_type(n.raw, &v)
	return SubqueryType(v)
}

func (n *SubqueryExprNode) SetSubqueryType(v SubqueryType) {
	internal.ResolvedSubqueryExpr_set_subquery_type(n.raw, int(v))
}

func (n *SubqueryExprNode) ParameterList() []*ColumnRefNode {
	var v unsafe.Pointer
	internal.ResolvedSubqueryExpr_parameter_list(n.raw, &v)
	var ret []*ColumnRefNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumnRefNode(p))
	})
	return ret
}

func (n *SubqueryExprNode) SetParameterList(v []*ColumnRefNode) {
	internal.ResolvedSubqueryExpr_set_parameter_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *SubqueryExprNode) AddParameter(v *ColumnRefNode) {
	internal.ResolvedSubqueryExpr_add_parameter_list(n.raw, v.getRaw())
}

// InExpr field is only populated for subqueries of type IN or LIKE ANY|SOME|ALL.
func (n *SubqueryExprNode) InExpr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedSubqueryExpr_in_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *SubqueryExprNode) SetInExpr(v ExprNode) {
	internal.ResolvedSubqueryExpr_set_in_expr(n.raw, v.getRaw())
}

// InCollation field is only populated for subqueries of type IN to specify the
// operation collation to use to compare <in_expr> with the rows from <subquery>.
func (n *SubqueryExprNode) InCollation() *Collation {
	var v unsafe.Pointer
	internal.ResolvedSubqueryExpr_in_collation(n.raw, &v)
	return newCollation(v)
}

func (n *SubqueryExprNode) SetInCollation(v *Collation) {
	internal.ResolvedSubqueryExpr_set_in_collation(n.raw, v.raw)
}

func (n *SubqueryExprNode) Subquery() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedSubqueryExpr_subquery(n.raw, &v)
	return newScanNode(v)
}

func (n *SubqueryExprNode) SetSubquery(v ScanNode) {
	internal.ResolvedSubqueryExpr_set_subquery(n.raw, v.getRaw())
}

// HintList
// NOTE: Hints currently happen only for EXISTS, IN, or a LIKE
// expression subquery but not for ARRAY or SCALAR subquery.
func (n *SubqueryExprNode) HintList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedSubqueryExpr_hint_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *SubqueryExprNode) SetHintList(v []*OptionNode) {
	internal.ResolvedSubqueryExpr_set_hint_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *SubqueryExprNode) AddHint(v *OptionNode) {
	internal.ResolvedSubqueryExpr_add_hint_list(n.raw, v.getRaw())
}

// LetExprNode introduces one or more columns in <assignment_list> that
// can then be referenced inside <expr>. Each assigned expression is
// evaluated once, and each reference to that column in <expr> sees the same
// value even if the assigned expression is volatile. Multiple assignment
// expressions are independent and cannot reference other columns in the
// <assignment_list>.
//
// <assignment_list> One or more columns that are computed before evaluating
//                   <expr>, and which may be referenced by <expr>.
// <expr> Computes the result of the LetExprNode. May reference columns
//        from <assignment_list>.
type LetExprNode struct {
	*BaseExprNode
}

func (n *LetExprNode) AssignmentList() []*ComputedColumnNode {
	var v unsafe.Pointer
	internal.ResolvedLetExpr_assignment_list(n.raw, &v)
	var ret []*ComputedColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newComputedColumnNode(p))
	})
	return ret
}

func (n *LetExprNode) SetAssignmentList(v []*ComputedColumnNode) {
	internal.ResolvedLetExpr_set_assignment_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *LetExprNode) AddAssignment(v *ComputedColumnNode) {
	internal.ResolvedLetExpr_add_assignment_list(n.raw, v.getRaw())
}

func (n *LetExprNode) Expr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedLetExpr_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *LetExprNode) SetExpr(v ExprNode) {
	internal.ResolvedLetExpr_set_expr(n.raw, v.getRaw())
}

// ScanNode common interface for all Scans, which are nodes that produce rows
// (e.g. scans, joins, table subqueries).  A query's FROM clause is
// represented as a single Scan that composes all input sources into
// a single row stream.
//
// Each Scan has a <column_list> that says what columns are produced.
// The Scan logically produces a stream of output rows, where each row
// has exactly these columns.
//
// Each Scan may have an attached <hint_list>, storing each hint as
// a OptionNode.
//
// If <is_ordered> is true, this Scan produces an ordered output, either
// by generating order itself (OrderByScan) or by preserving the order
// of its single input scan (LimitOffsetScan, ProjectScan, or WithScan).
type ScanNode interface {
	Node
	ColumnList() []*Column
	SetColumnList([]*Column)
	AddColumn(*Column)
	HintList() []*OptionNode
	SetHintList([]*OptionNode)
	AddHint(*OptionNode)
	IsOrdered() bool
	SetIsOrdered(bool)
}

type BaseScanNode struct {
	*BaseNode
}

func (n *BaseScanNode) ColumnList() []*Column {
	var v unsafe.Pointer
	internal.ResolvedScan_column_list(n.raw, &v)
	var ret []*Column
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumn(p))
	})
	return ret
}

func (n *BaseScanNode) SetColumnList(v []*Column) {
	internal.ResolvedScan_set_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].raw
	}))
}

func (n *BaseScanNode) AddColumn(v *Column) {
	internal.ResolvedScan_add_column_list(n.raw, v.raw)
}

func (n *BaseScanNode) HintList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedScan_hint_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *BaseScanNode) SetHintList(v []*OptionNode) {
	internal.ResolvedScan_set_hint_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *BaseScanNode) AddHint(v *OptionNode) {
	internal.ResolvedScan_add_hint_list(n.raw, v.getRaw())
}

func (n *BaseScanNode) IsOrdered() bool {
	var v bool
	internal.ResolvedScan_is_ordered(n.raw, &v)
	return v
}

func (n *BaseScanNode) SetIsOrdered(v bool) {
	internal.ResolvedScan_set_is_ordered(n.raw, helper.BoolToInt(v))
}

// ModelNode represents a machine learning model as a TVF argument.
// <model> is the machine learning model object known to the resolver
// (usually through the catalog).
type ModelNode struct {
	*BaseArgumentNode
}

func (n *ModelNode) Model() types.Model {
	var v unsafe.Pointer
	internal.ResolvedModel_model(n.raw, &v)
	return newModel(v)
}

func (n *ModelNode) SetModel(v types.Model) {
	internal.ResolvedModel_set_model(n.raw, getRawModel(v))
}

// ConnectionNode represents a connection object as a TVF argument.
// <connection> is the connection object encapsulated metadata to connect to
// an external data source.
type ConnectionNode struct {
	*BaseArgumentNode
}

func (n *ConnectionNode) Connection() types.Connection {
	var v unsafe.Pointer
	internal.ResolvedConnection_connection(n.raw, &v)
	return newConnection(v)
}

func (n *ConnectionNode) SetConnection(v types.Connection) {
	internal.ResolvedConnection_set_connection(n.raw, getRawConnection(v))
}

// DescriptorNode represents a descriptor object as a TVF argument.
// A descriptor is basically a list of unresolved column names, written
//   DESCRIPTOR(column1, column2)
//
// <descriptor_column_name_list> contains the column names.
//
// If FunctionArgumentTypeOptions.ResolveDescriptorNamesTableOffset()
// is true, then <descriptor_column_list> contains resolved columns from
// the sibling FunctionArgumentNode of scan type, and will match
// positionally with <descriptor_column_name_list>.
type DescriptorNode struct {
	*BaseArgumentNode
}

func (n *DescriptorNode) DescriptorColumnList() []*Column {
	var v unsafe.Pointer
	internal.ResolvedDescriptor_descriptor_column_list(n.raw, &v)
	var ret []*Column
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumn(p))
	})
	return ret
}

func (n *DescriptorNode) SetDescriptorColumnList(v []*Column) {
	internal.ResolvedDescriptor_set_descriptor_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].raw
	}))
}

func (n *DescriptorNode) AddDescriptorColumn(v *Column) {
	internal.ResolvedDescriptor_add_descriptor_column_list(n.raw, v.raw)
}

func (n *DescriptorNode) DescriptorColumnNameList() []string {
	var v unsafe.Pointer
	internal.ResolvedDescriptor_descriptor_column_name_list(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *DescriptorNode) SetDescriptorColumnNameList(v []string) {
	internal.ResolvedDescriptor_set_descriptor_column_name_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *DescriptorNode) AddDescriptorColumnName(v string) {
	internal.ResolvedDescriptor_add_descriptor_column_name_list(n.raw, helper.StringToPtr(v))
}

// SingleRowScanNode scan that produces a single row with no columns.
// Used for queries without a FROM clause, where all output comes from the select list.
type SingleRowScanNode struct {
	*BaseScanNode
}

// TableScanNode scan a Table.
// The <column_list>[i] should be matched to a Table column by
// <table>.GetColumn(<column_index_list>[i]).
//
// If AnalyzerOptions.PruneUnusedColumns is true, the <column_list> and
// <column_index_list> will include only columns that were referenced
// in the user query. (SELECT * counts as referencing all columns.)
// This column_list can then be used for column-level ACL checking on tables.
// Pruning has no effect on value tables (the value is never pruned).
//
// for_system_time_expr when non NULL resolves to TIMESTAMP used in
// FOR SYSTEM_TIME AS OF clause. The expression is expected to be constant
// and no columns are visible to it.
//
// <column_index_list> This list matches 1-1 with the <column_list>, and
// identifies the ordinal of the corresponding column in the <table>'s
// column list.
//
// If provided, <alias> refers to an explicit alias which was used to
// reference a Table in the user query. If the Table was given an implicitly
// generated alias, then defaults to "".
//
// TODO: Enforce <column_index_list> in the constructor arg list. For
// historical reasons, some clients match <column_list> to Table columns by
// ResolvedColumn name. This violates the ResolvedColumn contract, which
// explicitly states that the ResolvedColumn name has no semantic meaning.
// All code building a ResolvedTableScan should always
// set_column_index_list() immediately after construction.
type TableScanNode struct {
	*BaseScanNode
}

func (n *TableScanNode) Table() types.Table {
	var v unsafe.Pointer
	internal.ResolvedTableScan_table(n.raw, &v)
	return newTable(v)
}

func (n *TableScanNode) SetTable(v types.Table) {
	internal.ResolvedTableScan_set_table(n.raw, getRawTable(v))
}

func (n *TableScanNode) ForSystemTimeExpr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedTableScan_for_system_time_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *TableScanNode) SetForSystemTimeExpr(v ExprNode) {
	internal.ResolvedTableScan_set_for_system_time_expr(n.raw, v.getRaw())
}

func (n *TableScanNode) ColumnIndexList() []int {
	var v unsafe.Pointer
	internal.ResolvedTableScan_column_index_list(n.raw, &v)
	var ret []int
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, int(uintptr(p)))
	})
	return ret
}

func (n *TableScanNode) SetColumnIndexList(v []int) {
	internal.ResolvedTableScan_set_column_index_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return unsafe.Pointer(uintptr(v[i]))
	}))
}

func (n *TableScanNode) AddColumnIndex(v int) {
	internal.ResolvedTableScan_add_column_index_list(n.raw, v)
}

func (n *TableScanNode) Alias() string {
	var v unsafe.Pointer
	internal.ResolvedTableScan_alias(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *TableScanNode) SetAlias(v string) {
	internal.ResolvedTableScan_set_alias(n.raw, helper.StringToPtr(v))
}

// JoinScanNode scan that joins two input scans.
// The <column_list> will contain columns selected from the union
// of the input scan's <column_lists>.
// When the join is a LEFT/RIGHT/FULL join, ColumnsNode that came from
// the non-joined side get NULL values.
type JoinScanNode struct {
	*BaseScanNode
}

func (n *JoinScanNode) JoinType() JoinType {
	var v int
	internal.ResolvedJoinScan_join_type(n.raw, &v)
	return JoinType(v)
}

func (n *JoinScanNode) SetJoinType(v JoinType) {
	internal.ResolvedJoinScan_set_join_type(n.raw, int(v))
}

func (n *JoinScanNode) LeftScan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedJoinScan_left_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *JoinScanNode) SetLeftScan(v ScanNode) {
	internal.ResolvedJoinScan_set_left_scan(n.raw, v.getRaw())
}

func (n *JoinScanNode) RightScan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedJoinScan_right_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *JoinScanNode) SetRightScan(v ScanNode) {
	internal.ResolvedJoinScan_set_right_scan(n.raw, v.getRaw())
}

func (n *JoinScanNode) JoinExpr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedJoinScan_join_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *JoinScanNode) SetJoinExpr(v ExprNode) {
	internal.ResolvedJoinScan_set_join_expr(n.raw, v.getRaw())
}

// ArrayScanNode scan an array value, produced from some expression.
//
// If input_scan is NULL, this scans the given array value and produces
// one row per array element.  This can occur when using UNNEST(expression).
//
// If <input_scan> is non-NULL, for each row in the stream produced by
// input_scan, this evaluates the expression <array_expr> (which must return
// an array type) and then produces a stream with one row per array element.
//
// If <join_expr> is non-NULL, then this condition is evaluated as an ON
// clause for the array join.  The named column produced in <array_expr>
// may be used inside <join_expr>.
//
// If the array is empty (after evaluating <join_expr>), then
// 1. If <is_outer> is false, the scan produces zero rows.
// 2. If <is_outer> is true, the scan produces one row with a NULL value for
//    the <element_column>.
//
// <element_column> is the new column produced by this scan that stores the
// array element value for each row.
//
// If present, <array_offset_column> defines the column produced by this
// scan that stores the array offset (0-based) for the corresponding
// <element_column>.
//
// This node's column_list can have columns from input_scan, <element_column>
// and <array_offset_column>.
type ArrayScanNode struct {
	*BaseScanNode
}

func (n *ArrayScanNode) InputScan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedArrayScan_input_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *ArrayScanNode) SetInputScan(v ScanNode) {
	internal.ResolvedArrayScan_set_input_scan(n.raw, v.getRaw())
}

func (n *ArrayScanNode) ArrayExpr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedArrayScan_array_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *ArrayScanNode) SetArrayExpr(v ExprNode) {
	internal.ResolvedArrayScan_set_array_expr(n.raw, v.getRaw())
}

func (n *ArrayScanNode) ElementColumn() *Column {
	var v unsafe.Pointer
	internal.ResolvedArrayScan_element_column(n.raw, &v)
	return newColumn(v)
}

func (n *ArrayScanNode) SetElementColumn(v *Column) {
	internal.ResolvedArrayScan_set_element_column(n.raw, v.raw)
}

func (n *ArrayScanNode) ArrayOffsetColumn() *ColumnHolderNode {
	var v unsafe.Pointer
	internal.ResolvedArrayScan_array_offset_column(n.raw, &v)
	return newColumnHolderNode(v)
}

func (n *ArrayScanNode) SetArrayOffsetColumn(v *ColumnHolderNode) {
	internal.ResolvedArrayScan_set_array_offset_column(n.raw, v.getRaw())
}

func (n *ArrayScanNode) JoinExpr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedArrayScan_join_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *ArrayScanNode) SetJoinExpr(v ExprNode) {
	internal.ResolvedArrayScan_set_join_expr(n.raw, v.getRaw())
}

func (n *ArrayScanNode) IsOuter() bool {
	var v bool
	internal.ResolvedArrayScan_is_outer(n.raw, &v)
	return v
}

func (n *ArrayScanNode) SetIsOuter(v bool) {
	internal.ResolvedArrayScan_set_is_outer(n.raw, helper.BoolToInt(v))
}

// ColumnHolderNode this wrapper is used for an optional Column inside another node.
type ColumnHolderNode struct {
	*BaseArgumentNode
}

func (n *ColumnHolderNode) Column() *Column {
	var v unsafe.Pointer
	internal.ResolvedColumnHolder_column(n.raw, &v)
	return newColumn(v)
}

func (n *ColumnHolderNode) SetColumn(v *Column) {
	internal.ResolvedColumnHolder_set_column(n.raw, v.raw)
}

// FilterScanNode scan rows from input_scan, and emit all rows where filter_expr evaluates to true.
// filter_expr is always of type bool.
// This node's column_list will be a subset of input_scan's column_list.
type FilterScanNode struct {
	*BaseScanNode
}

func (n *FilterScanNode) InputScan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedFilterScan_input_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *FilterScanNode) SetInputScan(v ScanNode) {
	internal.ResolvedFilterScan_set_input_scan(n.raw, v.getRaw())
}

func (n *FilterScanNode) FilterExpr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedFilterScan_filter_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *FilterScanNode) SetFilterExpr(v ExprNode) {
	internal.ResolvedFilterScan_set_filter_expr(n.raw, v.getRaw())
}

// GroupingSetNode list of group by columns that form a grouping set.
//
// Columns must come from group_by_list in AggregateScanNode.
// group_by_column_list will not contain any duplicates. There may be more
// than one GroupingSetNode in the AggregateScanNode with the same columns, however.
type GroupingSetNode struct {
	*BaseArgumentNode
}

func (n *GroupingSetNode) GroupByColumnList() []*ColumnRefNode {
	var v unsafe.Pointer
	internal.ResolvedGroupingSet_group_by_column_list(n.raw, &v)
	var ret []*ColumnRefNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumnRefNode(p))
	})
	return ret
}

func (n *GroupingSetNode) SetGroupByColumnList(v []*ColumnRefNode) {
	internal.ResolvedGroupingSet_set_group_by_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *GroupingSetNode) AddGroupByColumn(v *ColumnRefNode) {
	internal.ResolvedGroupingSet_add_group_by_column_list(n.raw, v.getRaw())
}

// BaseAggregateScanNode base node for aggregation scans.
// Apply aggregation to rows produced from input_scan, and output aggregated rows.
//
// Group by keys in <group_by_list>.  If <group_by_list> is empty,
// aggregate all input rows into one output row.
//
// <collation_list> is either empty to indicate that all the elements in
// <group_by_list> have the default collation, or <collation_list> has the
// same number of elements as <group_by_list>.  Each element is the collation
// for the element in <group_by_list> with the same index, or can be empty to
// indicate default collation or when the type is not collatable.
// <collation_list> is only set when FEATURE_V_1_3_COLLATION_SUPPORT is enabled.
//
// Compute all aggregations in <aggregate_list>.  All expressions in
// <aggregate_list> have a AggregateFunctionCallNode with mode
// Function.AGGREGATE as their outermost node.
//
// The output <column_list> contains only columns produced from
// <group_by_list> and <aggregate_list>.  No other columns are visible after aggregation.
type BaseAggregateScanNode struct {
	*BaseScanNode
}

func (n *BaseAggregateScanNode) InputScan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedAggregateScanBase_input_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *BaseAggregateScanNode) SetInputScan(v ScanNode) {
	internal.ResolvedAggregateScanBase_set_input_scan(n.raw, v.getRaw())
}

func (n *BaseAggregateScanNode) GroupByList() []*ComputedColumnNode {
	var v unsafe.Pointer
	internal.ResolvedAggregateScanBase_group_by_list(n.raw, &v)
	var ret []*ComputedColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newComputedColumnNode(p))
	})
	return ret
}

func (n *BaseAggregateScanNode) SetGroupByList(v []*ComputedColumnNode) {
	internal.ResolvedAggregateScanBase_set_group_by_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *BaseAggregateScanNode) AddGroupBy(v *ComputedColumnNode) {
	internal.ResolvedAggregateScanBase_add_group_by_list(n.raw, v.getRaw())
}

func (n *BaseAggregateScanNode) CollationList() []*Collation {
	var v unsafe.Pointer
	internal.ResolvedAggregateScanBase_collation_list(n.raw, &v)
	var ret []*Collation
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newCollation(p))
	})
	return ret
}

func (n *BaseAggregateScanNode) SetCollationList(v []*Collation) {
	internal.ResolvedAggregateScanBase_set_collation_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].raw
	}))
}

func (n *BaseAggregateScanNode) AddCollation(v *Collation) {
	internal.ResolvedAggregateScanBase_add_collation_list(n.raw, v.raw)
}

func (n *BaseAggregateScanNode) AggregateList() []*ComputedColumnNode {
	var v unsafe.Pointer
	internal.ResolvedAggregateScanBase_aggregate_list(n.raw, &v)
	var ret []*ComputedColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newComputedColumnNode(p))
	})
	return ret
}

func (n *BaseAggregateScanNode) SetAggregateList(v []*ComputedColumnNode) {
	internal.ResolvedAggregateScanBase_set_aggregate_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *BaseAggregateScanNode) AddAggregate(v *ComputedColumnNode) {
	internal.ResolvedAggregateScanBase_add_aggregate_list(n.raw, v.getRaw())
}

// AggregateScanNode apply aggregation to rows produced from input_scan,
// and output aggregated rows.
//
// For each item in <grouping_set_list>, output additional rows computing the
// same <aggregate_list> over the input rows using a particular grouping set.
// The aggregation input values, including <input_scan>, computed columns in
// <group_by_list>, and aggregate function arguments in <aggregate_list>,
// should be computed just once and then reused as aggregation input for each
// grouping set. (This ensures that ROLLUP rows have correct totals, even
// with non-stable functions in the input.) For each grouping set, the
// <group_by_list> elements not included in the <group_by_column_list> are
// replaced with NULL.
//
// <rollup_column_list> is the original list of columns from
// GROUP BY ROLLUP(...), if there was a ROLLUP clause, and is used only for
// rebuilding equivalent SQL for the resolved AST. Engines should refer to
// <grouping_set_list> rather than <rollup_column_list>.
type AggregateScanNode struct {
	*BaseAggregateScanNode
}

func (n *AggregateScanNode) GroupingSetList() []*GroupingSetNode {
	var v unsafe.Pointer
	internal.ResolvedAggregateScan_grouping_set_list(n.raw, &v)
	var ret []*GroupingSetNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newGroupingSetNode(p))
	})
	return ret
}

func (n *AggregateScanNode) SetGroupingSetList(v []*GroupingSetNode) {
	internal.ResolvedAggregateScan_set_grouping_set_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AggregateScanNode) AddGroupingSet(v *GroupingSetNode) {
	internal.ResolvedAggregateScan_add_grouping_set_list(n.raw, v.getRaw())
}

func (n *AggregateScanNode) RollupColumnList() []*ColumnRefNode {
	var v unsafe.Pointer
	internal.ResolvedAggregateScan_rollup_column_list(n.raw, &v)
	var ret []*ColumnRefNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumnRefNode(p))
	})
	return ret
}

func (n *AggregateScanNode) SetRollupColumnList(v []*ColumnRefNode) {
	internal.ResolvedAggregateScan_set_rollup_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AggregateScanNode) AddRollupColumn(v *ColumnRefNode) {
	internal.ResolvedAggregateScan_add_rollup_column_list(n.raw, v.getRaw())
}

// AnonymizedAggregateScanNode apply differentially private aggregation (anonymization) to rows produced
// from input_scan, and output anonymized rows.
//
// <k_threshold_expr> when non-null, points to a function call in
// the <aggregate_list> and adds a filter that acts like:
//   HAVING <k_threshold_expr> >= <implementation-defined k-threshold>
// omitting any rows that would not pass this condition.
// TODO: Update this comment after splitting the rewriter out
// into a separate stage.
//
// <anonymization_option_list> provides user-specified options, and
// requires that option names are one of: delta, epsilon, kappa, or
// k_threshold.
type AnonymizedAggregateScanNode struct {
	*BaseAggregateScanNode
}

func (n *AnonymizedAggregateScanNode) KThresholdExpr() *ColumnRefNode {
	var v unsafe.Pointer
	internal.ResolvedAnonymizedAggregateScan_k_threshold_expr(n.raw, &v)
	return newColumnRefNode(v)
}

func (n *AnonymizedAggregateScanNode) SetKThresholdExpr(v *ColumnRefNode) {
	internal.ResolvedAnonymizedAggregateScan_set_k_threshold_expr(n.raw, v.getRaw())
}

func (n *AnonymizedAggregateScanNode) AnonymizationOptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedAnonymizedAggregateScan_anonymization_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *AnonymizedAggregateScanNode) SetAnonymizationOptionList(v []*OptionNode) {
	internal.ResolvedAnonymizedAggregateScan_set_anonymization_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AnonymizedAggregateScanNode) AddAnonymizationOption(v *OptionNode) {
	internal.ResolvedAnonymizedAggregateScan_add_anonymization_option_list(n.raw, v.getRaw())
}

// SetOperationItemNode this is one input item in a SetOperationNode.
// The <output_column_list> matches 1:1 with the SetOperationNode's
// <column_list> and specifies how columns from <scan> map to output columns.
// Each column from <scan> can map to zero or more output columns.
type SetOperationItemNode struct {
	*BaseArgumentNode
}

func (n *SetOperationItemNode) Scan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedSetOperationItem_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *SetOperationItemNode) SetScan(v ScanNode) {
	internal.ResolvedSetOperationItem_set_scan(n.raw, v.getRaw())
}

func (n *SetOperationItemNode) OutputColumnList() []*Column {
	var v unsafe.Pointer
	internal.ResolvedSetOperationItem_output_column_list(n.raw, &v)
	var ret []*Column
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumn(p))
	})
	return ret
}

func (n *SetOperationItemNode) SetOutputColumnList(v []*Column) {
	internal.ResolvedSetOperationItem_set_output_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].raw
	}))
}

func (n *SetOperationItemNode) AddOutputColumn(v *Column) {
	internal.ResolvedSetOperationItem_add_output_column_list(n.raw, v.raw)
}

// SetOperationScanNode apply a set operation (specified by <op_type>) on two or more input scans.
//
// <scan_list> will have at least two elements.
//
// <column_list> is a set of new ColumnsNode created by this scan.
// Each input SetOperationItemNode has an <output_column_list> which
// matches 1:1 with <column_list> and specifies how the input <scan>'s
// columns map into the final <column_list>.
//
// - Results of {UNION, INTERSECT, EXCEPT} ALL can include duplicate rows.
//   More precisely, with two input scans, if a given row R appears exactly
//   m times in first input and n times in second input (m >= 0, n >= 0):
//   For UNION ALL, R will appear exactly m + n times in the result.
//   For INTERSECT ALL, R will appear exactly min(m, n) in the result.
//   For EXCEPT ALL, R will appear exactly max(m - n, 0) in the result.
//
// - Results of {UNION, INTERSECT, EXCEPT} DISTINCT cannot contain any
//   duplicate rows. For UNION and INTERSECT, the DISTINCT is computed
//   after the result above is computed.  For EXCEPT DISTINCT, row R will
//   appear once in the output if m > 0 and n = 0.
//
// - For n (>2) input scans, the above operations generalize so the output is
//   the same as if the inputs were combined incrementally from left to right.
type SetOperationScanNode struct {
	*BaseScanNode
}

func (n *SetOperationScanNode) OpType() SetOperationType {
	var v int
	internal.ResolvedSetOperationScan_op_type(n.raw, &v)
	return SetOperationType(v)
}

func (n *SetOperationScanNode) SetOpType(v SetOperationType) {
	internal.ResolvedSetOperationScan_set_op_type(n.raw, int(v))
}

func (n *SetOperationScanNode) InputItemList() []*SetOperationItemNode {
	var v unsafe.Pointer
	internal.ResolvedSetOperationScan_input_item_list(n.raw, &v)
	var ret []*SetOperationItemNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newSetOperationItemNode(p))
	})
	return ret
}

func (n *SetOperationScanNode) SetInputItemList(v []*SetOperationItemNode) {
	internal.ResolvedSetOperationScan_set_input_item_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *SetOperationScanNode) AddInputItem(v *SetOperationItemNode) {
	internal.ResolvedSetOperationScan_add_input_item_list(n.raw, v.getRaw())
}

// OrderByScanNode apply ordering to rows produced from input_scan, and output ordered
// rows.
//
// The <order_by_item_list> must not be empty.  Each element identifies
// a sort column and indicates direction (ascending or descending).
//
// Order Preservation:
//   A ScanNode produces an ordered output if it has <is_ordered>=true.
//   If <is_ordered>=false, the scan may discard order.  This can happen
//   even for a OrderByScanNode, if it is the top-level scan in a
//   subquery (which discards order).
//
// The following Scan nodes may have <is_ordered>=true, producing or
// propagating an ordering:
//   * OrderByScanNode
//   * LimitOffsetScanNode
//   * ProjectScanNode
//   * WithScanNode
// Other Scan nodes will always discard ordering.
type OrderByScanNode struct {
	*BaseScanNode
}

func (n *OrderByScanNode) InputScan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedOrderByScan_input_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *OrderByScanNode) SetInputScan(v ScanNode) {
	internal.ResolvedOrderByScan_set_input_scan(n.raw, v.getRaw())
}

func (n *OrderByScanNode) OrderByItemList() []*OrderByItemNode {
	var v unsafe.Pointer
	internal.ResolvedOrderByScan_order_by_item_list(n.raw, &v)
	var ret []*OrderByItemNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOrderByItemNode(p))
	})
	return ret
}

func (n *OrderByScanNode) SetOrderByItemList(v []*OrderByItemNode) {
	internal.ResolvedOrderByScan_set_order_by_item_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *OrderByScanNode) AddOrderByItem(v *OrderByItemNode) {
	internal.ResolvedOrderByScan_add_order_by_item_list(n.raw, v.getRaw())
}

// LimitOffsetScanNode apply a LIMIT and optional OFFSET to the rows from input_scan. Emit all
// rows after OFFSET rows have been scanned and up to LIMIT total rows
// emitted. The offset is the number of rows to skip.
// E.g., OFFSET 1 means to skip one row, so the first row emitted will be the
// second ROW, provided the LIMIT is greater than zero.
//
// The arguments to LIMIT <int64> OFFSET <int64> must be non-negative
// integer literals or (possibly casted) query parameters.  Query
// parameter values must be checked at run-time by ZetaSQL compliant
// backend systems.
//
// OFFSET is optional and the absence of OFFSET implies OFFSET 0.
type LimitOffsetScanNode struct {
	*BaseScanNode
}

func (n *LimitOffsetScanNode) InputScan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedLimitOffsetScan_input_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *LimitOffsetScanNode) SetInputScan(v ScanNode) {
	internal.ResolvedLimitOffsetScan_set_input_scan(n.raw, v.getRaw())
}

func (n *LimitOffsetScanNode) Limit() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedLimitOffsetScan_limit(n.raw, &v)
	return newExprNode(v)
}

func (n *LimitOffsetScanNode) SetLimit(v ExprNode) {
	internal.ResolvedLimitOffsetScan_set_limit(n.raw, v.getRaw())
}

func (n *LimitOffsetScanNode) Offset() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedLimitOffsetScan_offset(n.raw, &v)
	return newExprNode(v)
}

func (n *LimitOffsetScanNode) SetOffset(v ExprNode) {
	internal.ResolvedLimitOffsetScan_set_offset(n.raw, v.getRaw())
}

// WithRefScanNode scan the subquery defined in a WITH statement.
// See WithScanNode for more detail.
// The column_list produced here will match 1:1 with the column_list produced
// by the referenced subquery and will given a new unique name to each
// column produced for this scan.
type WithRefScanNode struct {
	*BaseScanNode
}

func (n *WithRefScanNode) WithQueryName() string {
	var v unsafe.Pointer
	internal.ResolvedWithRefScan_with_query_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *WithRefScanNode) SetWithQueryName(v string) {
	internal.ResolvedWithRefScan_set_with_query_name(n.raw, helper.StringToPtr(v))
}

// AnalyticScanNode apply analytic functions to rows produced from input_scan.
//
// The set of analytic functions are partitioned into a list of analytic
// function groups <function_group_list> by the window PARTITION BY and the
// window ORDER BY.
//
// The output <column_list> contains all columns from <input_scan>,
// one column per analytic function. It may also conain partitioning/ordering
// expression columns if they reference to select columns.
type AnalyticScanNode struct {
	*BaseScanNode
}

func (n *AnalyticScanNode) InputScan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedAnalyticScan_input_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *AnalyticScanNode) SetInputScan(v ScanNode) {
	internal.ResolvedAnalyticScan_set_input_scan(n.raw, v.getRaw())
}

func (n *AnalyticScanNode) FunctionGroupList() []*AnalyticFunctionGroupNode {
	var v unsafe.Pointer
	internal.ResolvedAnalyticScan_function_group_list(n.raw, &v)
	var ret []*AnalyticFunctionGroupNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newAnalyticFunctionGroupNode(p))
	})
	return ret
}

func (n *AnalyticScanNode) SetFunctionGroupList(v []*AnalyticFunctionGroupNode) {
	internal.ResolvedAnalyticScan_set_function_group_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AnalyticScanNode) AddFunctionGroup(v *AnalyticFunctionGroupNode) {
	internal.ResolvedAnalyticScan_add_function_group_list(n.raw, v.getRaw())
}

// SampleScanNode samples rows from <input_scan>.
// Specs for WITH WEIGHT and PARTITION BY
//
// <method> is the identifier for the sampling algorithm and will always be
// in lowercase.
// For example BERNOULLI, RESERVOIR, SYSTEM. Engines can also support their
// own implementation-specific set of sampling algorithms.
//
// <size> and <unit> specifies the sample size.
// If <unit> is "ROWS", <size> must be an <int64> and non-negative.
// If <unit> is "PERCENT", <size> must either be a <double> or an <int64> and
// in the range [0, 100].
// <size> can only be a literal value or a (possibly casted) parameter.
//
// <repeatable_argument> is present if we had a REPEATABLE(<argument>) in the
// TABLESAMPLE clause and can only be a literal value or a (possibly
// casted) parameter.
//
// If present, <weight_column> defines the column produced by this scan that
// stores the scaling weight for the corresponding sampled row.
//
// <partition_by_list> can be empty. If <partition_by_list> is not empty,
// <unit> must be ROWS and <method> must be RESERVOIR.
type SampleScanNode struct {
	*BaseScanNode
}

func (n *SampleScanNode) InputScan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedSampleScan_input_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *SampleScanNode) SetInputScan(v ScanNode) {
	internal.ResolvedSampleScan_set_input_scan(n.raw, v.getRaw())
}

func (n *SampleScanNode) Method() string {
	var v unsafe.Pointer
	internal.ResolvedSampleScan_method(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *SampleScanNode) SetMethod(v string) {
	internal.ResolvedSampleScan_set_method(n.raw, helper.StringToPtr(v))
}

func (n *SampleScanNode) Size() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedSampleScan_size(n.raw, &v)
	return newExprNode(v)
}

func (n *SampleScanNode) SetSize(v ExprNode) {
	internal.ResolvedSampleScan_set_size(n.raw, v.getRaw())
}

func (n *SampleScanNode) Unit() SampleUnit {
	var v int
	internal.ResolvedSampleScan_unit(n.raw, &v)
	return SampleUnit(v)
}

func (n *SampleScanNode) SetUnit(v SampleUnit) {
	internal.ResolvedSampleScan_set_unit(n.raw, int(v))
}

func (n *SampleScanNode) RepeatableArgument() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedSampleScan_repeatable_argument(n.raw, &v)
	return newExprNode(v)
}

func (n *SampleScanNode) SetRepeatableArgument(v ExprNode) {
	internal.ResolvedSampleScan_set_repeatable_argument(n.raw, v.getRaw())
}

func (n *SampleScanNode) WeightColumn() *ColumnHolderNode {
	var v unsafe.Pointer
	internal.ResolvedSampleScan_weight_column(n.raw, &v)
	return newColumnHolderNode(v)
}

func (n *SampleScanNode) SetWeightColumn(v *ColumnHolderNode) {
	internal.ResolvedSampleScan_set_weight_column(n.raw, v.getRaw())
}

func (n *SampleScanNode) PartitionByList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedSampleScan_partition_by_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *SampleScanNode) SetPartitionByList(v []ExprNode) {
	internal.ResolvedSampleScan_set_partition_by_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *SampleScanNode) AddPartitionBy(v ExprNode) {
	internal.ResolvedSampleScan_add_partition_by_list(n.raw, v.getRaw())
}

// ComputedColumnNode this is used when an expression is computed and given a name (a new
// Column) that can be referenced elsewhere.  The new Column
// can appear in a column_list or in ColumnRefsNode in other expressions,
// when appropriate.  This node is not an expression itself - it is a
// container that holds an expression.
type ComputedColumnNode struct {
	*BaseArgumentNode
}

func (n *ComputedColumnNode) Column() *Column {
	var v unsafe.Pointer
	internal.ResolvedComputedColumn_column(n.raw, &v)
	return newColumn(v)
}

func (n *ComputedColumnNode) SetColumn(v *Column) {
	internal.ResolvedComputedColumn_set_column(n.raw, v.raw)
}

func (n *ComputedColumnNode) Expr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedComputedColumn_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *ComputedColumnNode) SetExpr(v ExprNode) {
	internal.ResolvedComputedColumn_set_expr(n.raw, v.getRaw())

}

// OrderByItemNode this represents one column of an ORDER BY clause, with the requested
// ordering direction.
//
// <collation_name> is the ORDER BY COLLATE expression, and could be a string
// literal or query parameter.  <collation_name> can only be set when the
// FEATURE_V_1_1_ORDER_BY_COLLATE is enabled.
// <collation> (only set when FEATURE_V_1_3_COLLATION_SUPPORT is enabled) is
// the derived collation to use.  It comes from the <column_ref> and COLLATE
// clause.  It is unset if COLLATE is present and set to a parameter.
// When both features are enabled, if <collation_name> is present and is
// - a parameter, then <collation> is empty
// - a non-parameter, then <collation> is set to the same collation
// An engine which supports both features could read the fields as:
//   If <collation> is set then use it, otherwise use <collation_name>, which
//   must be a query parameter if set.
//
// <null_order> indicates the ordering of NULL values relative to non-NULL
// values. NULLS_FIRST indicates that NULLS sort prior to non-NULL values,
// and NULLS_LAST indicates that NULLS sort after non-NULL values.
type OrderByItemNode struct {
	*BaseArgumentNode
}

func (n *OrderByItemNode) ColumnRef() *ColumnRefNode {
	var v unsafe.Pointer
	internal.ResolvedOrderByItem_column_ref(n.raw, &v)
	return newColumnRefNode(v)
}

func (n *OrderByItemNode) SetColumnRef(v *ColumnRefNode) {
	internal.ResolvedOrderByItem_set_column_ref(n.raw, v.getRaw())
}

func (n *OrderByItemNode) CollationName() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedOrderByItem_collation_name(n.raw, &v)
	return newExprNode(v)
}

func (n *OrderByItemNode) SetCollationName(v ExprNode) {
	internal.ResolvedOrderByItem_set_collation_name(n.raw, v.getRaw())
}

func (n *OrderByItemNode) IsDescending() bool {
	var v bool
	internal.ResolvedOrderByItem_is_descending(n.raw, &v)
	return v
}

func (n *OrderByItemNode) SetIsDescending(v bool) {
	internal.ResolvedOrderByItem_set_is_descending(n.raw, helper.BoolToInt(v))
}

func (n *OrderByItemNode) NullOrder() NullOrderMode {
	var v int
	internal.ResolvedOrderByItem_null_order(n.raw, &v)
	return NullOrderMode(v)
}

func (n *OrderByItemNode) SetNullOrder(v NullOrderMode) {
	internal.ResolvedOrderByItem_set_null_order(n.raw, int(v))
}

func (n *OrderByItemNode) Collation() *Collation {
	var v unsafe.Pointer
	internal.ResolvedOrderByItem_collation(n.raw, &v)
	return newCollation(v)
}

func (n *OrderByItemNode) SetCollation(v *Collation) {
	internal.ResolvedOrderByItem_set_collation(n.raw, v.raw)
}

// ColumnAnnotationsNode this is used in CREATE TABLE statements to provide column annotations
// such as collation, NOT NULL, type parameters, and OPTIONS().
//
// This class is recursive. It mirrors the structure of the column type
// except that child_list might be truncated.
//
// For ARRAY:
//   If the element or its subfield has annotations, then child_list.size()
//   is 1, and child_list(0) stores the element annotations.
//   Otherwise child_list is empty.
// For STRUCT:
//   If the i-th field has annotations then child_list(i) stores the
//   field annotations.
//   Otherwise either child_list.size() <= i or child_list(i) is trivial.
//   If none of the fields and none of their subfields has annotations, then
//   child_list is empty.
// For other types, child_list is empty.
type ColumnAnnotationsNode struct {
	*BaseArgumentNode
}

// CollationName can only be a string literal, and is only set
// when FEATURE_V_1_3_COLLATION_SUPPORT is enabled.
func (n *ColumnAnnotationsNode) CollationName() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedColumnAnnotations_collation_name(n.raw, &v)
	return newExprNode(v)
}

func (n *ColumnAnnotationsNode) SetCollationName(v ExprNode) {
	internal.ResolvedColumnAnnotations_set_collation_name(n.raw, v.getRaw())
}

func (n *ColumnAnnotationsNode) NotNull() bool {
	var v bool
	internal.ResolvedColumnAnnotations_not_null(n.raw, &v)
	return v
}

func (n *ColumnAnnotationsNode) SetNotNull(v bool) {
	internal.ResolvedColumnAnnotations_set_not_null(n.raw, helper.BoolToInt(v))
}

func (n *ColumnAnnotationsNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedColumnAnnotations_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *ColumnAnnotationsNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedColumnAnnotations_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *ColumnAnnotationsNode) AddOption(v *OptionNode) {
	internal.ResolvedColumnAnnotations_add_option_list(n.raw, v.getRaw())
}

func (n *ColumnAnnotationsNode) ChildList() []*ColumnAnnotationsNode {
	var v unsafe.Pointer
	internal.ResolvedColumnAnnotations_child_list(n.raw, &v)
	var ret []*ColumnAnnotationsNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumnAnnotationsNode(p))
	})
	return ret
}

func (n *ColumnAnnotationsNode) SetChildList(v []*ColumnAnnotationsNode) {
	internal.ResolvedColumnAnnotations_set_child_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *ColumnAnnotationsNode) AddChild(v *ColumnAnnotationsNode) {
	internal.ResolvedColumnAnnotations_add_child_list(n.raw, v.getRaw())
}

// TypeParameters child_list in <type_parameters> is not used in here.
// Instead we use child_list of this node (ColumnAnnotationsNode)
// to store type parameters of subfields of STRUCT or ARRAY. Users
// can access the full type parameters with child_list by calling
// ColumnDefinitionNode.FullTypeParameters() function.
func (n *ColumnAnnotationsNode) TypeParameters() *types.TypeParameters {
	var v unsafe.Pointer
	internal.ResolvedColumnAnnotations_type_parameters(n.raw, &v)
	return newTypeParameters(v)
}

func (n *ColumnAnnotationsNode) SetTypeParameters(v *types.TypeParameters) {
	internal.ResolvedColumnAnnotations_set_type_parameters(n.raw, getRawTypeParameters(v))
}

// GeneratedColumnInfoNode <expression> indicates the expression that defines the column.
// The type of the expression will always match the type of the column.
//   - The <expression> can contain ColumnRefsNode corresponding to
//   ColumnDefinitionNode.Column for any of the
//   ColumnDefinitionsNode in the enclosing statement.
//   - The expression can never include a subquery.
//
// <stored_mode> is the mode of a generated column: Values are:
//   - 'NON_STORED': The <expression> must always be evaluated at read time.
//   - 'STORED': The <expression> should be pre-emptively computed at write
//        time (to save work at read time) and must not call any volatle
//        function (e.g. RAND).
//   - 'STORED_VOLATILE': The <expression> must be computed at write time and
//        may call volatile functions (e.g. RAND).
type GeneratedColumnInfoNode struct {
	*BaseArgumentNode
}

func (n *GeneratedColumnInfoNode) Expression() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedGeneratedColumnInfo_expression(n.raw, &v)
	return newExprNode(v)
}

func (n *GeneratedColumnInfoNode) SetExpression(v ExprNode) {
	internal.ResolvedGeneratedColumnInfo_set_expression(n.raw, v.getRaw())
}

func (n *GeneratedColumnInfoNode) StoredMode() StoredMode {
	var v int
	internal.ResolvedGeneratedColumnInfo_stored_mode(n.raw, &v)
	return StoredMode(v)
}

func (n *GeneratedColumnInfoNode) SetStoredMode(v StoredMode) {
	internal.ResolvedGeneratedColumnInfo_set_stored_mode(n.raw, int(v))
}

// ColumnDefaultValueNode <expression> is the default value expression of the column.
// The type of the expression must be coercible to the column type.
//   - <default_value> cannot contain any references to another column.
//   - <default_value> cannot include a subquery, aggregation, or window
//     function.
//
// <sql> is the original SQL string for the default value expression.
//
// Since we can't enforce engines to access at least one of the fields, we
// leave both fields NOT_IGNORABLE to ensure engines access at least one of them.
type ColumnDefaultValueNode struct {
	*BaseArgumentNode
}

func (n *ColumnDefaultValueNode) Expression() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedColumnDefaultValue_expression(n.raw, &v)
	return newExprNode(v)
}

func (n *ColumnDefaultValueNode) SetExpression(v ExprNode) {
	internal.ResolvedColumnDefaultValue_set_expression(n.raw, v.getRaw())
}

func (n *ColumnDefaultValueNode) SQL() string {
	var v unsafe.Pointer
	internal.ResolvedColumnDefaultValue_sql(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *ColumnDefaultValueNode) SetSQL(v string) {
	internal.ResolvedColumnDefaultValue_set_sql(n.raw, helper.StringToPtr(v))
}

// ColumnDefinitionNode this is used in CREATE TABLE statements to provide an explicit column definition.
//
// if <is_hidden> is TRUE, then the column won't show up in SELECT * queries.
//
// if <generated_column_info> is non-NULL, then this column is a generated column.
//
// if <default_value> is non-NULL, then this column has default value.
//
// <generated_column_info> and <default_value> cannot both be set at the same time.
//
// <column> defines an ID for the column, which may appear in expressions in
// the PARTITION BY, CLUSTER BY clause or <generated_column_info> if either is present.
type ColumnDefinitionNode struct {
	*BaseArgumentNode
}

func (n *ColumnDefinitionNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedColumnDefinition_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *ColumnDefinitionNode) SetName(v string) {
	internal.ResolvedColumnDefinition_set_name(n.raw, helper.StringToPtr(v))
}

func (n *ColumnDefinitionNode) Type() types.Type {
	var v unsafe.Pointer
	internal.ResolvedColumnDefinition_type(n.raw, &v)
	return newType(v)
}

func (n *ColumnDefinitionNode) SetType(v types.Type) {
	internal.ResolvedColumnDefinition_set_type(n.raw, getRawType(v))
}

func (n *ColumnDefinitionNode) Annotations() *ColumnAnnotationsNode {
	var v unsafe.Pointer
	internal.ResolvedColumnDefinition_annotations(n.raw, &v)
	return newColumnAnnotationsNode(v)
}

func (n *ColumnDefinitionNode) SetAnnotations(v *ColumnAnnotationsNode) {
	internal.ResolvedColumnDefinition_set_annotations(n.raw, v.getRaw())
}

func (n *ColumnDefinitionNode) IsHidden() bool {
	var v bool
	internal.ResolvedColumnDefinition_is_hidden(n.raw, &v)
	return v
}

func (n *ColumnDefinitionNode) SetIsHidden(v bool) {
	internal.ResolvedColumnDefinition_set_is_hidden(n.raw, helper.BoolToInt(v))
}

func (n *ColumnDefinitionNode) Column() *Column {
	var v unsafe.Pointer
	internal.ResolvedColumnDefinition_column(n.raw, &v)
	return newColumn(v)
}

func (n *ColumnDefinitionNode) SetColumn(v *Column) {
	internal.ResolvedColumnDefinition_set_column(n.raw, v.raw)
}

func (n *ColumnDefinitionNode) GeneratedColumnInfo() *GeneratedColumnInfoNode {
	var v unsafe.Pointer
	internal.ResolvedColumnDefinition_generated_column_info(n.raw, &v)
	return newGeneratedColumnInfoNode(v)
}

func (n *ColumnDefinitionNode) SetGeneratedColumnInfo(v *GeneratedColumnInfoNode) {
	internal.ResolvedColumnDefinition_set_generated_column_info(n.raw, v.getRaw())
}

func (n *ColumnDefinitionNode) DefaultValue() *ColumnDefaultValueNode {
	var v unsafe.Pointer
	internal.ResolvedColumnDefinition_default_value(n.raw, &v)
	return newColumnDefaultValueNode(v)
}

func (n *ColumnDefinitionNode) SetDefaultValue(v *ColumnDefaultValueNode) {
	internal.ResolvedColumnDefinition_set_default_value(n.raw, v.getRaw())
}

// ConstraintNode intermediate node for constraints.
type ConstraintNode interface {
	ArgumentNode
}

type BaseConstraintNode struct {
	*BaseArgumentNode
}

// PrimaryKeyNode this represents the PRIMARY KEY constraint on a table.
// <column_offset_list> provides the offsets of the column definitions that
//                      comprise the primary key. This is empty when a
//                      0-element primary key is defined or when the altered
//                      table does not exist.
// <unenforced> specifies whether the constraint is unenforced.
// <constraint_name> specifies the constraint name, if present
// <column_name_list> provides the column names used in column definitions
//                    that comprise the primary key.
type PrimaryKeyNode struct {
	*BaseConstraintNode
}

func (n *PrimaryKeyNode) ColumnOffsetList() []int {
	var v unsafe.Pointer
	internal.ResolvedPrimaryKey_column_offset_list(n.raw, &v)
	var ret []int
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, int(uintptr(p)))
	})
	return ret
}

func (n *PrimaryKeyNode) SetColumnOffsetList(v []int) {
	internal.ResolvedPrimaryKey_set_column_offset_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return unsafe.Pointer(uintptr(v[i]))
	}))
}

func (n *PrimaryKeyNode) AddColumnOffset(v int) {
	internal.ResolvedPrimaryKey_add_column_offset_list(n.raw, v)
}

func (n *PrimaryKeyNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedPrimaryKey_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *PrimaryKeyNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedPrimaryKey_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *PrimaryKeyNode) AddOption(v *OptionNode) {
	internal.ResolvedPrimaryKey_add_option_list(n.raw, v.getRaw())
}

func (n *PrimaryKeyNode) Unenforced() bool {
	var v bool
	internal.ResolvedPrimaryKey_unenforced(n.raw, &v)
	return v
}

func (n *PrimaryKeyNode) SetUnenforced(v bool) {
	internal.ResolvedPrimaryKey_set_unenforced(n.raw, helper.BoolToInt(v))
}

func (n *PrimaryKeyNode) ConstraintName() string {
	var v unsafe.Pointer
	internal.ResolvedPrimaryKey_constraint_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *PrimaryKeyNode) SetConstraintName(v string) {
	internal.ResolvedPrimaryKey_set_constraint_name(n.raw, helper.StringToPtr(v))
}

func (n *PrimaryKeyNode) ColumnNameList() []string {
	var v unsafe.Pointer
	internal.ResolvedPrimaryKey_column_name_list(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *PrimaryKeyNode) SetColumnNameList(v []string) {
	internal.ResolvedPrimaryKey_set_column_name_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *PrimaryKeyNode) AddColumnName(v string) {
	internal.ResolvedPrimaryKey_add_column_name_list(n.raw, helper.StringToPtr(v))
}

// ForeignKeyNode this represents the FOREIGN KEY constraint on a table. It is of the form:
//
//   CONSTRAINT <constraint_name>
//   FOREIGN KEY <referencing_column_offset_list>
//   REFERENCES <referenced_table> <referenced_column_offset_list>
//   <match_mode>
//   <update_action>
//   <delete_action>
//   <enforced>
//   <option_list>
//
// <constraint_name> uniquely identifies the constraint.
//
// <referencing_column_offset_list> provides the offsets of the column
// definitions for the table defining the foreign key.
//
// <referenced_table> identifies the table this constraint references.
//
// <referenced_column_offset_list> provides the offsets of the column
// definitions for the table referenced by the foreign key.
//
// <match_mode> specifies how referencing keys with null values are handled.
//
// <update_action> specifies what action to take, if any, when a referenced
// value is updated.
//
// <delete_action> specifies what action to take, if any, when a row with a
// referenced values is deleted.
//
// <enforced> specifies whether or not the constraint is enforced.
//
// <option_list> for foreign key table constraints. Empty for foreign key
// column attributes (see instead ColumnAnnotationsNode).
//
// <referencing_column_list> provides the names for the foreign key's
// referencing columns.
type ForeignKeyNode struct {
	*BaseConstraintNode
}

func (n *ForeignKeyNode) ConstraintName() string {
	var v unsafe.Pointer
	internal.ResolvedForeignKey_constraint_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *ForeignKeyNode) SetConstraintName(v string) {
	internal.ResolvedForeignKey_set_constraint_name(n.raw, helper.StringToPtr(v))
}

func (n *ForeignKeyNode) ReferencingColumnOffsetList() []int {
	var v unsafe.Pointer
	internal.ResolvedForeignKey_referencing_column_offset_list(n.raw, &v)
	var ret []int
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, int(uintptr(p)))
	})
	return ret
}

func (n *ForeignKeyNode) SetReferencingColumnOffsetList(v []int) {
	internal.ResolvedForeignKey_set_referencing_column_offset_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return unsafe.Pointer(uintptr(v[i]))
	}))
}

func (n *ForeignKeyNode) AddReferencingColumnOffset(v int) {
	internal.ResolvedForeignKey_add_referencing_column_offset_list(n.raw, v)
}

func (n *ForeignKeyNode) ReferencedTable() types.Table {
	var v unsafe.Pointer
	internal.ResolvedForeignKey_referenced_table(n.raw, &v)
	return newTable(v)
}

func (n *ForeignKeyNode) SetReferencedTable(v types.Table) {
	internal.ResolvedForeignKey_set_referenced_table(n.raw, getRawTable(v))
}

func (n *ForeignKeyNode) ReferencedColumnOffsetList() []int {
	var v unsafe.Pointer
	internal.ResolvedForeignKey_referenced_column_offset_list(n.raw, &v)
	var ret []int
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, int(uintptr(p)))
	})
	return ret
}

func (n *ForeignKeyNode) SetReferencedColumnOffsetList(v []int) {
	internal.ResolvedForeignKey_set_referenced_column_offset_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return unsafe.Pointer(uintptr(v[i]))
	}))
}

func (n *ForeignKeyNode) AddReferencedColumnOffset(v int) {
	internal.ResolvedForeignKey_add_referenced_column_offset_list(n.raw, v)
}

func (n *ForeignKeyNode) MatchMode() MatchMode {
	var v int
	internal.ResolvedForeignKey_match_mode(n.raw, &v)
	return MatchMode(v)
}

func (n *ForeignKeyNode) SetMatchMode(v MatchMode) {
	internal.ResolvedForeignKey_set_match_mode(n.raw, int(v))
}

func (n *ForeignKeyNode) UpdateAction() ActionOperation {
	var v int
	internal.ResolvedForeignKey_update_action(n.raw, &v)
	return ActionOperation(v)
}

func (n *ForeignKeyNode) SetUpdateAction(v ActionOperation) {
	internal.ResolvedForeignKey_set_update_action(n.raw, int(v))
}

func (n *ForeignKeyNode) DeleteAction() ActionOperation {
	var v int
	internal.ResolvedForeignKey_delete_action(n.raw, &v)
	return ActionOperation(v)
}

func (n *ForeignKeyNode) SetDeleteAction(v ActionOperation) {
	internal.ResolvedForeignKey_set_delete_action(n.raw, int(v))
}

func (n *ForeignKeyNode) Enforced() bool {
	var v bool
	internal.ResolvedForeignKey_enforced(n.raw, &v)
	return v
}

func (n *ForeignKeyNode) SetEnforced(v bool) {
	internal.ResolvedForeignKey_set_enforced(n.raw, helper.BoolToInt(v))
}

func (n *ForeignKeyNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedForeignKey_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret

}

func (n *ForeignKeyNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedForeignKey_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *ForeignKeyNode) AddOption(v *OptionNode) {
	internal.ResolvedForeignKey_add_option_list(n.raw, v.getRaw())
}

func (n *ForeignKeyNode) ReferencingColumnList() []string {
	var v unsafe.Pointer
	internal.ResolvedForeignKey_referencing_column_list(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *ForeignKeyNode) SetReferencingColumnList(v []string) {
	internal.ResolvedForeignKey_set_referencing_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *ForeignKeyNode) AddReferencingColumn(v string) {
	internal.ResolvedForeignKey_add_referencing_column_list(n.raw, helper.StringToPtr(v))
}

// CheckConstraintNode this represents the ZETASQL_CHECK constraint on a table. It is of the form:
//
//   CONSTRAINT <constraint_name>
//   ZETASQL_CHECK <expression>
//   <enforced>
//   <option_list>
//
// <constraint_name> uniquely identifies the constraint.
//
// <expression> defines a boolean expression to be evaluated when the row is
// updated. If the result is FALSE, update to the row is not allowed.
//
// <enforced> specifies whether or not the constraint is enforced.
//
// <option_list> list of options for check constraint.
type CheckConstraintNode struct {
	*BaseConstraintNode
}

func (n *CheckConstraintNode) ConstraintName() string {
	var v unsafe.Pointer
	internal.ResolvedCheckConstraint_constraint_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *CheckConstraintNode) SetConstraintName(v string) {
	internal.ResolvedCheckConstraint_set_constraint_name(n.raw, helper.StringToPtr(v))
}

func (n *CheckConstraintNode) Expression() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCheckConstraint_expression(n.raw, &v)
	return newExprNode(v)
}

func (n *CheckConstraintNode) SetExpression(v ExprNode) {
	internal.ResolvedCheckConstraint_set_expression(n.raw, v.getRaw())
}

func (n *CheckConstraintNode) Enforced() bool {
	var v bool
	internal.ResolvedCheckConstraint_enforced(n.raw, &v)
	return v
}

func (n *CheckConstraintNode) SetEnforced(v bool) {
	internal.ResolvedCheckConstraint_set_enforced(n.raw, helper.BoolToInt(v))
}

func (n *CheckConstraintNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedCheckConstraint_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *CheckConstraintNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedCheckConstraint_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CheckConstraintNode) AddOption(v *OptionNode) {
	internal.ResolvedCheckConstraint_add_option_list(n.raw, v.getRaw())
}

// OutputColumnNode this is used in QueryStmtNode to provide a user-visible name
// for each output column.
type OutputColumnNode struct {
	*BaseArgumentNode
}

func (n *OutputColumnNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedOutputColumn_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *OutputColumnNode) SetName(v string) {
	internal.ResolvedOutputColumn_set_name(n.raw, helper.StringToPtr(v))
}

func (n *OutputColumnNode) Column() *Column {
	var v unsafe.Pointer
	internal.ResolvedOutputColumn_column(n.raw, &v)
	return newColumn(v)
}

func (n *OutputColumnNode) SetColumn(v *Column) {
	internal.ResolvedOutputColumn_set_column(n.raw, v.raw)
}

// ProjectScanNode a project node computes new expression values, and possibly drops
// columns from the input Scan's column_list.
//
// Each entry in <expr_list> is a new column computed from an expression.
//
// The column_list can include any columns from input_scan, plus these
// newly computed columns.
//
// NOTE: This scan will propagate the is_ordered property of <input_scan>
// by default.  To make this scan unordered, call set_is_ordered(false).
type ProjectScanNode struct {
	*BaseScanNode
}

func (n *ProjectScanNode) ExprList() []*ComputedColumnNode {
	var v unsafe.Pointer
	internal.ResolvedProjectScan_expr_list(n.raw, &v)
	var ret []*ComputedColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newComputedColumnNode(p))
	})
	return ret
}

func (n *ProjectScanNode) SetExprList(v []*ComputedColumnNode) {
	internal.ResolvedProjectScan_set_expr_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *ProjectScanNode) AddExpr(v *ComputedColumnNode) {
	internal.ResolvedProjectScan_add_expr_list(n.raw, v.getRaw())
}

func (n *ProjectScanNode) InputScan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedProjectScan_input_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *ProjectScanNode) SetInputScan(v ScanNode) {
	internal.ResolvedProjectScan_set_input_scan(n.raw, v.getRaw())
}

// TVFScanNode this scan represents a call to a table-valued function (TVF). Each TVF
// returns an entire output relation instead of a single scalar value. The
// enclosing query may refer to the TVF as if it were a table subquery. The
// TVF may accept scalar arguments and/or other input relations.
//
// Scalar arguments work the same way as arguments for non-table-valued
// functions: in the resolved AST, their types are equal to the required
// argument types specified in the function signature.
//
// The function signature may also include relation arguments, and any such
// relation argument may specify a required schema. If such a required schema
// is present, then in the resolved AST, the ScanNode for each relational
// FunctionArgumentNode is guaranteed to have the same number of columns
// as the required schema, and the provided columns match position-wise with
// the required columns. Each provided column has the same name and type as
// the corresponding required column.
//
// If AnalyzerOptions::prune_unused_columns is true, the <column_list> and
// <column_index_list> will include only columns that were referenced
// in the user query. (SELECT * counts as referencing all columns.)
// Pruning has no effect on value tables (the value is never pruned).
//
// <column_list> is a set of new ColumnsNode created by this scan.
// The <column_list>[i] should be matched to the related TVFScan's output
// relation column by
// <signature>.result_schema().column(<column_index_list>[i]).
//
// <tvf> The TableValuedFunction entry that the catalog returned for this TVF
//       scan. Contains non-concrete function signatures which may include
//       arguments with templated types.
// <signature> The concrete table function signature for this TVF call,
//             including the types of all scalar arguments and the
//             number and types of columns of all table-valued
//             arguments. An engine may also subclass this object to
//             provide extra custom information and return an instance
//             of the subclass from the TableValuedFunction::Resolve
//             method.
// <argument_list> The vector of resolved concrete arguments for this TVF
//                 call, including the default values or NULLs injected for
//                 the omitted arguments (Note the NULL injection is a
//                 temporary solution to handle omitted named arguments. This
//                 is subject to change by upcoming CLs).
//
// <column_index_list> This list matches 1-1 with the <column_list>, and
// identifies the index of the corresponding column in the <signature>'s
// result relation column list.
//
// <alias> The AS alias for the scan, or empty if none.
// <function_call_signature> The FunctionSignature object from the
//                           <tvf->signatures()> list that matched the
//                           current call. The TVFScan's
//                           <FunctionSignature::ConcreteArgument> list
//                           matches 1:1 to <argument_list>, while its
//                           <FunctionSignature::arguments> list still has
//                           the full argument list.
//                           The analyzer only sets this field when
//                           it could be ambiguous for an engine to figure
//                           out the actual arguments provided, e.g., when
//                           there are arguments omitted from the call. When
//                           it is provided, engines may use this object to
//                           check for the argument names and omitted
//                           arguments. SQLBuilder may also need this object
//                           in cases when the named argument notation is
//                           required for this call.
type TVFScanNode struct {
	*BaseScanNode
}

func (n *TVFScanNode) TVF() types.TableValuedFunction {
	var v unsafe.Pointer
	internal.ResolvedTVFScan_tvf(n.raw, &v)
	return newTableValuedFunction(v)
}

func (n *TVFScanNode) SetTVF(v types.TableValuedFunction) {
	internal.ResolvedTVFScan_set_tvf(n.raw, getRawTableValuedFunction(v))
}

func (n *TVFScanNode) Signature() *types.TVFSignature {
	var v unsafe.Pointer
	internal.ResolvedTVFScan_signature(n.raw, &v)
	return newTVFSignature(v)
}

func (n *TVFScanNode) SetSignature(v *types.TVFSignature) {
	internal.ResolvedTVFScan_set_signature(n.raw, getRawTVFSignature(v))
}

func (n *TVFScanNode) ArgumentList() []*FunctionArgumentNode {
	var v unsafe.Pointer
	internal.ResolvedTVFScan_argument_list(n.raw, &v)
	var ret []*FunctionArgumentNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newFunctionArgumentNode(p))
	})
	return ret
}

func (n *TVFScanNode) SetArgumentList(v []*FunctionArgumentNode) {
	internal.ResolvedTVFScan_set_argument_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *TVFScanNode) AddArgument(v *FunctionArgumentNode) {
	internal.ResolvedTVFScan_add_argument_list(n.raw, v.getRaw())
}

func (n *TVFScanNode) ColumnIndexList() []int {
	var v unsafe.Pointer
	internal.ResolvedTVFScan_column_index_list(n.raw, &v)
	var ret []int
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, int(uintptr(p)))
	})
	return ret
}

func (n *TVFScanNode) SetColumnIndexList(v []int) {
	internal.ResolvedTVFScan_set_column_index_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return unsafe.Pointer(uintptr(v[i]))
	}))
}

func (n *TVFScanNode) AddColumnIndex(v int) {
	internal.ResolvedTVFScan_add_column_index_list(n.raw, v)
}

func (n *TVFScanNode) Alias() string {
	var v unsafe.Pointer
	internal.ResolvedTVFScan_alias(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *TVFScanNode) SetAlias(v string) {
	internal.ResolvedTVFScan_set_alias(n.raw, helper.StringToPtr(v))
}

func (n *TVFScanNode) FunctionCallSignature() *types.FunctionSignature {
	var v unsafe.Pointer
	internal.ResolvedTVFScan_function_call_signature(n.raw, &v)
	return newFunctionSignature(v)
}

func (n *TVFScanNode) SetFunctionCallSignature(v *types.FunctionSignature) {
	internal.ResolvedTVFScan_set_function_call_signature(n.raw, getRawFunctionSignature(v))
}

// GroupRowsScanNode represents a call to a special TVF GROUP_ROWS().
// It can only show up inside WITH GROUP_ROWS clause, which is resolved as
// the field with_group_rows_subquery in BaseNonScalarFunctionCallNode GroupRowsScanNode.
// This scan produces rows corresponding to the input
// of AggregateScanNode that belong to the current group.
//
// <input_column_list> is a list of new columns created to store values
// coming from the input of the aggregate scan. ComputedColumnNode can
// only hold ColumnRefNode's and can reference anything from the
// pre-aggregation scan.
//
// <alias> is the alias of the scan or empty if none.
type GroupRowsScanNode struct {
	*BaseScanNode
}

func (n *GroupRowsScanNode) InputColumnList() []*ComputedColumnNode {
	var v unsafe.Pointer
	internal.ResolvedGroupRowsScan_input_column_list(n.raw, &v)
	var ret []*ComputedColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newComputedColumnNode(p))
	})
	return ret
}

func (n *GroupRowsScanNode) SetInputColumnList(v []*ComputedColumnNode) {
	internal.ResolvedGroupRowsScan_set_input_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *GroupRowsScanNode) AddInputColumn(v *ComputedColumnNode) {
	internal.ResolvedGroupRowsScan_add_input_column_list(n.raw, v.getRaw())
}

func (n *GroupRowsScanNode) Alias() string {
	var v unsafe.Pointer
	internal.ResolvedGroupRowsScan_alias(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *GroupRowsScanNode) SetAlias(v string) {
	internal.ResolvedGroupRowsScan_set_alias(n.raw, helper.StringToPtr(v))
}

// FunctionArgumentNode this represents a generic argument to a function.
// The argument can be semantically an expression, relation, model, connection or descriptor.
// Only one of the five fields will be set.
//
// <expr> represents a scalar function argument.
// <scan> represents a table-typed argument.
// <model> represents a ML model function argument.
// <connection> represents a connection object function argument.
// <descriptor_arg> represents a descriptor object function argument.
//
// This node could be used in multiple places:
// * TVFScanNode supports all of these.
// * FunctionCallNode supports only <expr>.
// * CallStmtNode supports only <expr>.
//
// If the argument has type <scan>, <argument_column_list> maps columns from
// <scan> into specific columns of the argument's input schema, matching
// those columns positionally. i.e. <scan>'s column_list may have fewer
// columns or out-of-order columns, and this vector maps those columns into
// specific input columns.
type FunctionArgumentNode struct {
	*BaseArgumentNode
}

func (n *FunctionArgumentNode) Expr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedFunctionArgument_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *FunctionArgumentNode) SetExpr(v ExprNode) {
	internal.ResolvedFunctionArgument_set_expr(n.raw, v.getRaw())
}

func (n *FunctionArgumentNode) Scan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedFunctionArgument_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *FunctionArgumentNode) SetScan(v ScanNode) {
	internal.ResolvedFunctionArgument_set_scan(n.raw, v.getRaw())
}

func (n *FunctionArgumentNode) Model() *ModelNode {
	var v unsafe.Pointer
	internal.ResolvedFunctionArgument_model(n.raw, &v)
	return newModelNode(v)
}

func (n *FunctionArgumentNode) SetModel(v *ModelNode) {
	internal.ResolvedFunctionArgument_set_model(n.raw, v.getRaw())
}

func (n *FunctionArgumentNode) Connection() *ConnectionNode {
	var v unsafe.Pointer
	internal.ResolvedFunctionArgument_connection(n.raw, &v)
	return newConnectionNode(v)
}

func (n *FunctionArgumentNode) SetConnection(v *ConnectionNode) {
	internal.ResolvedFunctionArgument_set_connection(n.raw, v.getRaw())
}

func (n *FunctionArgumentNode) DescriptorArg() *DescriptorNode {
	var v unsafe.Pointer
	internal.ResolvedFunctionArgument_descriptor_arg(n.raw, &v)
	return newDescriptorNode(v)
}

func (n *FunctionArgumentNode) SetDescriptorArg(v *DescriptorNode) {
	internal.ResolvedFunctionArgument_set_descriptor_arg(n.raw, v.getRaw())
}

func (n *FunctionArgumentNode) ArgumentColumnList() []*Column {
	var v unsafe.Pointer
	internal.ResolvedFunctionArgument_argument_column_list(n.raw, &v)
	var ret []*Column
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumn(p))
	})
	return ret
}

func (n *FunctionArgumentNode) SetArgumentColumnList(v []*Column) {
	internal.ResolvedFunctionArgument_set_argument_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].raw
	}))
}

func (n *FunctionArgumentNode) AddArgumentColumn(v *Column) {
	internal.ResolvedFunctionArgument_add_argument_column_list(n.raw, v.raw)
}

func (n *FunctionArgumentNode) InlineLambda() *InlineLambdaNode {
	var v unsafe.Pointer
	internal.ResolvedFunctionArgument_inline_lambda(n.raw, &v)
	return newInlineLambdaNode(v)
}

func (n *FunctionArgumentNode) SetInlineLambda(v *InlineLambdaNode) {
	internal.ResolvedFunctionArgument_set_inline_lambda(n.raw, v.getRaw())
}

// StatementNode the base node of all ZetaSQL statements.
type StatementNode interface {
	Node
	HintList() []*OptionNode
	SetHintList(v []*OptionNode)
	AddHint(v *OptionNode)
}

// BaseStatementNode
type BaseStatementNode struct {
	*BaseNode
}

func (n *BaseStatementNode) HintList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedStatement_hint_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *BaseStatementNode) SetHintList(v []*OptionNode) {
	internal.ResolvedStatement_set_hint_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *BaseStatementNode) AddHint(v *OptionNode) {
	internal.ResolvedStatement_add_hint_list(n.raw, v.getRaw())
}

// ExplainStmtNode an Explain statement. This is always the root of a statement hierarchy.
// Its child may be any statement type except another ExplainStmtNode.
//
// It is implementation dependent what action a back end system takes for an ExplainStatement.
type ExplainStmtNode struct {
	*BaseStatementNode
}

func (n *ExplainStmtNode) Statement() StatementNode {
	var v unsafe.Pointer
	internal.ResolvedExplainStmt_statement(n.raw, &v)
	return newStatementNode(v)
}

func (n *ExplainStmtNode) SetStatement(v StatementNode) {
	internal.ResolvedExplainStmt_set_statement(n.raw, v.getRaw())
}

// QueryStmtNode a SQL query statement.
// This is the outermost query statement that runs
// and produces rows of output, like a SELECT.  (The contained query may be
// a Scan corresponding to a non-Select top-level operation like UNION ALL or WITH.)
//
// <output_column_list> gives the user-visible column names that should be
// returned in the API or query tools.  There may be duplicate names, and
// multiple output columns may reference the same column from <query>.
type QueryStmtNode struct {
	*BaseStatementNode
}

func (n *QueryStmtNode) OutputColumnList() []*OutputColumnNode {
	var v unsafe.Pointer
	internal.ResolvedQueryStmt_output_column_list(n.raw, &v)
	var ret []*OutputColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOutputColumnNode(p))
	})
	return ret
}

func (n *QueryStmtNode) SetOutputColumnList(v []*OutputColumnNode) {
	internal.ResolvedQueryStmt_set_output_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *QueryStmtNode) AddOutputColumn(v *OutputColumnNode) {
	internal.ResolvedQueryStmt_add_output_column_list(n.raw, v.getRaw())
}

// IsValueTable if true, the result of this query is a value table. Rather than
// producing rows with named columns, it produces rows with a single
// unnamed value type.  output_column_list will have exactly one
// column, with an empty name.
func (n *QueryStmtNode) IsValueTable() bool {
	var v bool
	internal.ResolvedQueryStmt_is_value_table(n.raw, &v)
	return v
}

func (n *QueryStmtNode) SetIsValueTable(v bool) {
	internal.ResolvedQueryStmt_set_is_value_table(n.raw, helper.BoolToInt(v))
}

func (n *QueryStmtNode) Query() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedQueryStmt_query(n.raw, &v)
	return newScanNode(v)
}

func (n *QueryStmtNode) SetQuery(v ScanNode) {
	internal.ResolvedQueryStmt_set_query(n.raw, v.getRaw())
}

// CreateDatabaseStmtNode this statement:
//   CREATE DATABASE <name> [OPTIONS (...)]
// <name_path> is a vector giving the identifier path in the database name.
// <option_list> specifies the options of the database.
type CreateDatabaseStmtNode struct {
	*BaseStatementNode
}

func (n *CreateDatabaseStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedCreateDatabaseStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *CreateDatabaseStmtNode) SetNamePath(v []string) {
	internal.ResolvedCreateDatabaseStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *CreateDatabaseStmtNode) AddNamePath(v string) {
	internal.ResolvedCreateDatabaseStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

func (n *CreateDatabaseStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateDatabaseStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *CreateDatabaseStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedCreateDatabaseStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateDatabaseStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedCreateDatabaseStmt_add_option_list(n.raw, v.getRaw())
}

// CreateStatementNode common base node for CREATE statements with standard modifiers like
//         CREATE [OR REPLACE] [TEMP|TEMPORARY|PUBLIC|PRIVATE] <object type>
//         [IF NOT EXISTS] <name> ...
//
// <name_path> is a vector giving the identifier path in the table name.
// <create_scope> is the relevant scope, i.e., DEFAULT, TEMP, PUBLIC,
//                or PRIVATE.  PUBLIC/PRIVATE are only valid in module
//                resolution context.
// <create_mode> indicates if this was CREATE, CREATE OR REPLACE, or
//               CREATE IF NOT EXISTS.
type CreateStatementNode interface {
	StatementNode
	NamePath() []string
	SetNamePath([]string)
	AddNamePath(string)
	CreateScope() CreateScope
	SetCreateScope(CreateScope)
	CreateMode() CreateMode
	SetCreateMode(CreateMode)
}

// BaseCreateStatementNode
type BaseCreateStatementNode struct {
	*BaseStatementNode
}

func (n *BaseCreateStatementNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedCreateStatement_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *BaseCreateStatementNode) SetNamePath(v []string) {
	internal.ResolvedCreateStatement_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *BaseCreateStatementNode) AddNamePath(v string) {
	internal.ResolvedCreateStatement_add_name_path(n.raw, helper.StringToPtr(v))
}

func (n *BaseCreateStatementNode) CreateScope() CreateScope {
	var v int
	internal.ResolvedCreateStatement_create_scope(n.raw, &v)
	return CreateScope(v)
}

func (n *BaseCreateStatementNode) SetCreateScope(v CreateScope) {
	internal.ResolvedCreateStatement_set_create_scope(n.raw, int(v))
}

func (n *BaseCreateStatementNode) CreateMode() CreateMode {
	var v int
	internal.ResolvedCreateStatement_create_mode(n.raw, &v)
	return CreateMode(v)
}

func (n *BaseCreateStatementNode) SetCreateMode(v CreateMode) {
	internal.ResolvedCreateStatement_set_create_mode(n.raw, int(v))
}

// IndexItemNode represents one of indexed items in CREATE INDEX statement, with the
// ordering direction specified.
type IndexItemNode struct {
	*BaseArgumentNode
}

func (n *IndexItemNode) ColumnRef() *ColumnRefNode {
	var v unsafe.Pointer
	internal.ResolvedIndexItem_column_ref(n.raw, &v)
	return newColumnRefNode(v)
}

func (n *IndexItemNode) SetColumnRef(v *ColumnRefNode) {
	internal.ResolvedIndexItem_set_column_ref(n.raw, v.getRaw())
}

func (n *IndexItemNode) Descending() bool {
	var v bool
	internal.ResolvedIndexItem_descending(n.raw, &v)
	return v
}

func (n *IndexItemNode) SetDescending(v bool) {
	internal.ResolvedIndexItem_set_descending(n.raw, helper.BoolToInt(v))
}

// UnnestItemNode this is used in CREATE INDEX STMT to represent the unnest operation
// performed on the base table. The produced element columns or array offset
// columns (optional) can appear in other UnnestItemNode or index keys.
//
// <array_expr> is the expression of the array field, e.g., t.array_field.
// <element_column> is the new column produced by this unnest item that
//                  stores the array element value for each row.
// <array_offset_column> is optional. If present, it defines the column
//                       produced by this unnest item that stores the array
//                       offset (0-based) for the corresponding
//                       <element_column>.
type UnnestItemNode struct {
	*BaseArgumentNode
}

func (n *UnnestItemNode) ArrayExpr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedUnnestItem_array_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *UnnestItemNode) SetArrayExpr(v ExprNode) {
	internal.ResolvedUnnestItem_set_array_expr(n.raw, v.getRaw())
}

func (n *UnnestItemNode) ElementColumn() *Column {
	var v unsafe.Pointer
	internal.ResolvedUnnestItem_element_column(n.raw, &v)
	return newColumn(v)
}

func (n *UnnestItemNode) SetElementColumn(v *Column) {
	internal.ResolvedUnnestItem_set_element_column(n.raw, v.raw)
}

func (n *UnnestItemNode) ArrayOffsetColumn() *ColumnHolderNode {
	var v unsafe.Pointer
	internal.ResolvedUnnestItem_array_offset_column(n.raw, &v)
	return newColumnHolderNode(v)
}

func (n *UnnestItemNode) SetArrayOffsetColumn(v *ColumnHolderNode) {
	internal.ResolvedUnnestItem_set_array_offset_column(n.raw, v.getRaw())
}

// CreateIndexStmtNode this statement:
// CREATE [OR REPLACE] [UNIQUE] [SEARCH] INDEX [IF NOT EXISTS]
//  <index_name_path> ON <table_name_path>
// [STORING (Expression, ...)]
// [UNNEST(path_expression) [[AS] alias] [WITH OFFSET [[AS] alias]], ...]
// (path_expression [ASC|DESC], ...) [OPTIONS (name=value, ...)];
//
// <table_name_path> is the name of table being indexed.
// <table_scan> is a TableScan on the table being indexed.
// <is_unique> specifies if the index has unique entries.
// <is_search> specifies if the index is for search.
// <index_all_columns> specifies if indexing all the columns of the table.
//                     When this field is true, index_item_list must be
//                     empty and is_search must be true.
// <index_item_list> has the columns being indexed, specified as references
//                   to 'computed_columns_list' entries or the columns of
//                   'table_scan'.
// <storing_expression_list> has the expressions in the storing clause.
// <option_list> has engine-specific directives for how and where to
//               materialize this index.
// <computed_columns_list> has computed columns derived from the columns of
//                         'table_scan' or 'unnest_expressions_list'. For
//                         example, the extracted field (e.g., x.y.z).
// <unnest_expressions_list> has unnest expressions derived from
//                           'table_scan' or previous unnest expressions in
//                           the list. So the list order is significant.
type CreateIndexStmtNode struct {
	*BaseCreateStatementNode
}

func (n *CreateIndexStmtNode) TableNamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedCreateIndexStmt_table_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *CreateIndexStmtNode) SetTableNamePath(v []string) {
	internal.ResolvedCreateIndexStmt_set_table_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *CreateIndexStmtNode) AddTableNamePath(v string) {
	internal.ResolvedCreateIndexStmt_add_table_name_path(n.raw, helper.StringToPtr(v))
}

func (n *CreateIndexStmtNode) TableScan() *TableScanNode {
	var v unsafe.Pointer
	internal.ResolvedCreateIndexStmt_table_scan(n.raw, &v)
	return newTableScanNode(v)
}

func (n *CreateIndexStmtNode) SetTableScan(v *TableScanNode) {
	internal.ResolvedCreateIndexStmt_set_table_scan(n.raw, v.getRaw())
}

func (n *CreateIndexStmtNode) IsUnique() bool {
	var v bool
	internal.ResolvedCreateIndexStmt_is_unique(n.raw, &v)
	return v
}

func (n *CreateIndexStmtNode) SetIsUnique(v bool) {
	internal.ResolvedCreateIndexStmt_set_is_unique(n.raw, helper.BoolToInt(v))
}

func (n *CreateIndexStmtNode) IsSearch() bool {
	var v bool
	internal.ResolvedCreateIndexStmt_is_search(n.raw, &v)
	return v
}

func (n *CreateIndexStmtNode) SetIsSearch(v bool) {
	internal.ResolvedCreateIndexStmt_set_is_search(n.raw, helper.BoolToInt(v))
}

func (n *CreateIndexStmtNode) IndexAllColumns() bool {
	var v bool
	internal.ResolvedCreateIndexStmt_index_all_columns(n.raw, &v)
	return v
}

func (n *CreateIndexStmtNode) SetIndexAllColumns(v bool) {
	internal.ResolvedCreateIndexStmt_set_index_all_columns(n.raw, helper.BoolToInt(v))
}

func (n *CreateIndexStmtNode) IndexItemList() []*IndexItemNode {
	var v unsafe.Pointer
	internal.ResolvedCreateIndexStmt_index_item_list(n.raw, &v)
	var ret []*IndexItemNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newIndexItemNode(p))
	})
	return ret
}

func (n *CreateIndexStmtNode) SetIndexItemList(v []*IndexItemNode) {
	internal.ResolvedCreateIndexStmt_set_index_item_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateIndexStmtNode) AddIndexItem(v *IndexItemNode) {
	internal.ResolvedCreateIndexStmt_add_index_item_list(n.raw, v.getRaw())
}

func (n *CreateIndexStmtNode) StoringExpressionList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCreateIndexStmt_storing_expression_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *CreateIndexStmtNode) SetStoringExpressionList(v []ExprNode) {
	internal.ResolvedCreateIndexStmt_set_storing_expression_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateIndexStmtNode) AddStoringExpression(v ExprNode) {
	internal.ResolvedCreateIndexStmt_add_storing_expression_list(n.raw, v.getRaw())
}

func (n *CreateIndexStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateIndexStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *CreateIndexStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedCreateIndexStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateIndexStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedCreateIndexStmt_add_option_list(n.raw, v.getRaw())
}

func (n *CreateIndexStmtNode) ComputedColumnsList() []*ComputedColumnNode {
	var v unsafe.Pointer
	internal.ResolvedCreateIndexStmt_computed_columns_list(n.raw, &v)
	var ret []*ComputedColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newComputedColumnNode(p))
	})
	return ret
}

func (n *CreateIndexStmtNode) SetComputedColumnList(v []*ComputedColumnNode) {
	internal.ResolvedCreateIndexStmt_set_computed_columns_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateIndexStmtNode) AddComputedColumn(v *ComputedColumnNode) {
	internal.ResolvedCreateIndexStmt_add_computed_columns_list(n.raw, v.raw)
}

func (n *CreateIndexStmtNode) UnnestExpressionList() []*UnnestItemNode {
	var v unsafe.Pointer
	internal.ResolvedCreateIndexStmt_unnest_expressions_list(n.raw, &v)
	var ret []*UnnestItemNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newUnnestItemNode(p))
	})
	return ret
}

func (n *CreateIndexStmtNode) SetUnnestExpressionList(v []*UnnestItemNode) {
	internal.ResolvedCreateIndexStmt_set_unnest_expressions_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateIndexStmtNode) AddUnnestExpression(v *UnnestItemNode) {
	internal.ResolvedCreateIndexStmt_add_unnest_expressions_list(n.raw, v.getRaw())
}

// CreateSchemaStmtNode this statement:
//   CREATE [OR REPLACE] SCHEMA [IF NOT EXISTS] <name>
//   [DEFAULT COLLATE <collation>]
//   [OPTIONS (name=value, ...)]
//
// <option_list> engine-specific options.
// <collation_name> specifies the default collation specification for future
//   tables created in the dataset. If a table is created in this dataset
//   without specifying table-level default collation, it inherits the
//   dataset default collation. A change to this field affects only tables
//   created afterwards, not the existing tables. Only string literals
//   are allowed for this field.
//
//   Note: If a table being created in this schema does not specify table
//   default collation, the engine should copy the dataset default collation
//   to the table as the table default collation.
type CreateSchemaStmtNode struct {
	*BaseCreateStatementNode
}

func (n *CreateSchemaStmtNode) CollationName() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCreateSchemaStmt_collation_name(n.raw, &v)
	return newExprNode(v)
}

func (n *CreateSchemaStmtNode) SetCollationName(v ExprNode) {
	internal.ResolvedCreateSchemaStmt_set_collation_name(n.raw, v.getRaw())
}

func (n *CreateSchemaStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateSchemaStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *CreateSchemaStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedCreateSchemaStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateSchemaStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedCreateSchemaStmt_add_option_list(n.raw, v.getRaw())
}

// BaseCreateTableStmtNode this statement:
//   CREATE [TEMP] TABLE <name> [(column type, ...) | LIKE <name_path>]
//   [DEFAULT COLLATE <collation>] [PARTITION BY expr, ...]
//   [CLUSTER BY expr, ...] [OPTIONS (...)]
//
// <option_list> has engine-specific directives for how and where to
//               materialize this table.
// <column_definition_list> has the names and types of the columns in the
//                          created table. If <is_value_table> is true, it
//                          must contain exactly one column, with a generated
//                          name such as "$struct".
// <pseudo_column_list> is a list of some pseudo-columns expected to be
//                      present on the created table (provided by
//                      AnalyzerOptions::SetDdlPseudoColumns*).  These can be
//                      referenced in expressions in <partition_by_list> and
//                      <cluster_by_list>.
// <primary_key> specifies the PRIMARY KEY constraint on the table, it is
//               nullptr when no PRIMARY KEY is specified.
// <foreign_key_list> specifies the FOREIGN KEY constraints on the table.
// <check_constraint_list> specifies the ZETASQL_CHECK constraints on the table.
// <partition_by_list> specifies the partitioning expressions for the table.
// <cluster_by_list> specifies the clustering expressions for the table.
// TODO: Return error when the PARTITION BY / CLUSTER BY
// expression resolves to have collation specified.
// <is_value_table> specifies whether the table is a value table.
// <like_table> identifies the table in the LIKE <name_path>.
//              By default, all fields (column names, types, constraints,
//              keys, clustering etc.) will be inherited from the source
//              table. But if explicitly set, the explicit settings will
//              take precedence.
// <collation_name> specifies the default collation specification to apply to
//   newly added STRING fields in this table. A change of this field affects
//   only the STRING columns and the STRING fields in STRUCTs added
//   afterwards, not existing columns. Only string literals are allowed for
//   this field.
//
//   Note: During table creation or alteration, if a STRING field is added to
//   this table without explicit collation specified, the engine should copy
//   the table default collation to the STRING field.
type BaseCreateTableStmtNode struct {
	*BaseCreateStatementNode
}

func (n *BaseCreateTableStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableStmtBase_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *BaseCreateTableStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedCreateTableStmtBase_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *BaseCreateTableStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedCreateTableStmtBase_add_option_list(n.raw, v.getRaw())
}

func (n *BaseCreateTableStmtNode) ColumnDefinitionList() []*ColumnDefinitionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableStmtBase_column_definition_list(n.raw, &v)
	var ret []*ColumnDefinitionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumnDefinitionNode(p))
	})
	return ret
}

func (n *BaseCreateTableStmtNode) SetColumnDefinitionList(v []*ColumnDefinitionNode) {
	internal.ResolvedCreateTableStmtBase_set_column_definition_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *BaseCreateTableStmtNode) AddColumnDefinition(v *ColumnDefinitionNode) {
	internal.ResolvedCreateTableStmtBase_add_column_definition_list(n.raw, v.getRaw())
}

func (n *BaseCreateTableStmtNode) PseudoColumnList() []*Column {
	var v unsafe.Pointer
	internal.ResolvedCreateTableStmtBase_pseudo_column_list(n.raw, &v)
	var ret []*Column
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumn(p))
	})
	return ret
}

func (n *BaseCreateTableStmtNode) SetPseudoColumnList(v []*Column) {
	internal.ResolvedCreateTableStmtBase_set_pseudo_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].raw
	}))
}

func (n *BaseCreateTableStmtNode) AddPseudoColumn(v *Column) {
	internal.ResolvedCreateTableStmtBase_add_pseudo_column_list(n.raw, v.raw)
}

func (n *BaseCreateTableStmtNode) PrimaryKey() *PrimaryKeyNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableStmtBase_primary_key(n.raw, &v)
	return newPrimaryKeyNode(v)
}

func (n *BaseCreateTableStmtNode) SetPrimaryKey(v *PrimaryKeyNode) {
	internal.ResolvedCreateTableStmtBase_set_primary_key(n.raw, v.getRaw())
}

func (n *BaseCreateTableStmtNode) ForeignKeyList() []*ForeignKeyNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableStmtBase_foreign_key_list(n.raw, &v)
	var ret []*ForeignKeyNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newForeignKeyNode(p))
	})
	return ret
}

func (n *BaseCreateTableStmtNode) SetForeignKeyList(v []*ForeignKeyNode) {
	internal.ResolvedCreateTableStmtBase_set_foreign_key_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *BaseCreateTableStmtNode) AddForeignKey(v *ForeignKeyNode) {
	internal.ResolvedCreateTableStmtBase_add_foreign_key_list(n.raw, v.getRaw())
}

func (n *BaseCreateTableStmtNode) CheckConstraintList() []*CheckConstraintNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableStmtBase_check_constraint_list(n.raw, &v)
	var ret []*CheckConstraintNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newCheckConstraintNode(p))
	})
	return ret
}

func (n *BaseCreateTableStmtNode) SetCheckConstraintList(v []*CheckConstraintNode) {
	internal.ResolvedCreateTableStmtBase_set_check_constraint_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *BaseCreateTableStmtNode) AddCheckConstraint(v *CheckConstraintNode) {
	internal.ResolvedCreateTableStmtBase_add_check_constraint_list(n.raw, v.getRaw())
}

func (n *BaseCreateTableStmtNode) IsValueTable() bool {
	var v bool
	internal.ResolvedCreateTableStmtBase_is_value_table(n.raw, &v)
	return v
}

func (n *BaseCreateTableStmtNode) SetIsValueTable(v bool) {
	internal.ResolvedCreateTableStmtBase_set_is_value_table(n.raw, helper.BoolToInt(v))
}

func (n *BaseCreateTableStmtNode) LikeTable() types.Table {
	var v unsafe.Pointer
	internal.ResolvedCreateTableStmtBase_like_table(n.raw, &v)
	return newTable(v)
}

func (n *BaseCreateTableStmtNode) SetLikeTable(v types.Table) {
	internal.ResolvedCreateTableStmtBase_set_like_table(n.raw, getRawTable(v))
}

func (n *BaseCreateTableStmtNode) CollationName() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableStmtBase_collation_name(n.raw, &v)
	return newExprNode(v)
}

func (n *BaseCreateTableStmtNode) SetCollationName(v ExprNode) {
	internal.ResolvedCreateTableStmtBase_set_collation_name(n.raw, v.getRaw())
}

// CreateTableStmtNode this statement:
//   CREATE [TEMP] TABLE <name>
//   [(column schema, ...) | LIKE <name_path> |
//       {CLONE|COPY} <name_path>
//           [FOR SYSTEM_TIME AS OF <time_expr>]
//           [WHERE <where_clause>]]
//   [DEFAULT COLLATE <collation_name>]
//   [PARTITION BY expr, ...] [CLUSTER BY expr, ...]
//   [OPTIONS (...)]
//
// One of <clone_from> or <copy_from> can be present for CLONE or COPY.
//   <clone_from> specifes the data source to clone from (cheap, typically
//   O(1) operation); while <copy_from> is intended for a full copy.
//
//   TableScanNode will represent the source table, with an optional
//   for_system_time_expr.
//
//   The TableScanNode may be wrapped inside a FilterScanNode if the
//   source table has a where clause. No other Scan types are allowed here.
//
//   If the OPTIONS clause is explicitly specified, the option values are
//   intended to be used for the created or replaced table.
//   If any OPTION is unspecified, the corresponding option from the source
//   table will be used instead.
//
//   The 'clone_from.column_list' field may be set, but should be ignored.
//
//   clone_from and copy_from cannot be value tables.
type CreateTableStmtNode struct {
	*BaseCreateTableStmtNode
}

func (n *CreateTableStmtNode) CloneFrom() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableStmt_clone_from(n.raw, &v)
	return newScanNode(v)
}

func (n *CreateTableStmtNode) SetCloneFrom(v ScanNode) {
	internal.ResolvedCreateTableStmt_set_clone_from(n.raw, v.getRaw())
}

func (n *CreateTableStmtNode) CopyFrom() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableStmt_copy_from(n.raw, &v)
	return newScanNode(v)
}

func (n *CreateTableStmtNode) SetCopyFrom(v ScanNode) {
	internal.ResolvedCreateTableStmt_set_copy_from(n.raw, v.getRaw())
}

func (n *CreateTableStmtNode) PartitionByList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableStmt_partition_by_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *CreateTableStmtNode) SetPartitionByList(v []ExprNode) {
	internal.ResolvedCreateTableStmt_set_partition_by_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateTableStmtNode) AddPartitionBy(v ExprNode) {
	internal.ResolvedCreateTableStmt_add_partition_by_list(n.raw, v.getRaw())
}

func (n *CreateTableStmtNode) ClusterByList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableStmt_cluster_by_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *CreateTableStmtNode) SetClusterByList(v []ExprNode) {
	internal.ResolvedCreateTableStmt_set_cluster_by_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateTableStmtNode) AddClusterBy(v ExprNode) {
	internal.ResolvedCreateTableStmt_add_cluster_by_list(n.raw, v.getRaw())
}

// CreateTableAsSelectStmt this statement:
//   CREATE [TEMP] TABLE <name> [(column schema, ...) | LIKE <name_path>]
//   [DEFAULT COLLATE <collation_name>] [PARTITION BY expr, ...]
//   [CLUSTER BY expr, ...] [OPTIONS (...)]
//   AS SELECT ...
//
// The <output_column_list> matches 1:1 with the <column_definition_list> in
// BaseCreateTableStmtNode, and maps ColumnsNode produced by <query>
// into specific columns of the created table.  The output column names and
// types must match the column definition names and types.  If the table is
// a value table, <output_column_list> must have exactly one column, with a
// generated name such as "$struct".
//
// <output_column_list> does not contain all table schema information that
// <column_definition_list> does. For example, NOT NULL annotations, column
// OPTIONS, and primary keys are only available in <column_definition_list>.
// Consumers are encouraged to read from <column_definition_list> rather
// than than <output_column_list> to determine the table schema, if possible.
//
// <query> is the query to run.
type CreateTableAsSelectStmtNode struct {
	*BaseCreateTableStmtNode
}

func (n *CreateTableAsSelectStmtNode) PartitionByList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableAsSelectStmt_partition_by_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *CreateTableAsSelectStmtNode) SetPartitionByList(v []ExprNode) {
	internal.ResolvedCreateTableAsSelectStmt_set_partition_by_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateTableAsSelectStmtNode) AddPartitionBy(v ExprNode) {
	internal.ResolvedCreateTableAsSelectStmt_add_partition_by_list(n.raw, v.getRaw())
}

func (n *CreateTableAsSelectStmtNode) ClusterByList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableAsSelectStmt_cluster_by_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *CreateTableAsSelectStmtNode) SetClusterByList(v []ExprNode) {
	internal.ResolvedCreateTableAsSelectStmt_set_cluster_by_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateTableAsSelectStmtNode) AddClusterBy(v ExprNode) {
	internal.ResolvedCreateTableAsSelectStmt_add_cluster_by_list(n.raw, v.getRaw())
}

func (n *CreateTableAsSelectStmtNode) OutputColumnList() []*OutputColumnNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableAsSelectStmt_output_column_list(n.raw, &v)
	var ret []*OutputColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOutputColumnNode(p))
	})
	return ret
}

func (n *CreateTableAsSelectStmtNode) SetOutputColumnList(v []*OutputColumnNode) {
	internal.ResolvedCreateTableAsSelectStmt_set_output_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateTableAsSelectStmtNode) AddOutputColumn(v *OutputColumnNode) {
	internal.ResolvedCreateTableAsSelectStmt_add_output_column_list(n.raw, v.getRaw())
}

func (n *CreateTableAsSelectStmtNode) Query() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableAsSelectStmt_query(n.raw, &v)
	return newScanNode(v)
}

func (n *CreateTableAsSelectStmtNode) SetQuery(v ScanNode) {
	internal.ResolvedCreateTableAsSelectStmt_set_query(n.raw, v.getRaw())
}

// CreateModelStmtNode this statement:
//   CREATE [TEMP] MODEL <name> [TRANSFORM(...)] [OPTIONS (...)] AS SELECT ..
//
// <option_list> has engine-specific directives for how to train this model.
// <output_column_list> matches 1:1 with the <query>'s column_list and the
//                      <column_definition_list>, and identifies the names
//                      and types of the columns output from the select
//                      statement.
// <query> is the select statement.
// <transform_input_column_list> introduces new ColumnsNode that have the
//   same names and types of the columns in the <output_column_list>. The
//   transform expressions resolve against these ColumnsNode. It's only
//   set when <transform_list> is non-empty.
// <transform_list> is the list of ComputedColumnNode in TRANSFORM
//   clause.
// <transform_output_column_list> matches 1:1 with <transform_list> output.
//   It records the names of the output columns from TRANSFORM clause.
// <transform_analytic_function_group_list> is the list of
//   AnalyticFunctionGroup for analytic functions inside TRANSFORM clause.
//   It records the input expression of the analytic functions. It can
//   see all the columns from <transform_input_column_list>. The only valid
//   group is for the full, unbounded window generated from empty OVER()
//   clause.
//   For example, CREATE MODEL statement
//   "create model Z
//     transform (max(c) over() as d)
//     options ()
//     as select 1 c, 2 b;"
//   will generate transform_analytic_function_group_list:
//   +-transform_analytic_function_group_list=
//     +-AnalyticFunctionGroup
//       +-analytic_function_list=
//         +-d#5 :=
//           +-AnalyticFunctionCall(ZetaSQL:max(INT64) -> INT64)
//             +-ColumnRef(type=INT64, column=Z.c#3)
//             +-window_frame=
//               +-WindowFrame(frame_unit=ROWS)
//                 +-start_expr=
//                 | +-WindowFrameExpr(boundary_type=UNBOUNDED PRECEDING)
//                 +-end_expr=
//                   +-WindowFrameExpr(boundary_type=UNBOUNDED FOLLOWING)
type CreateModelStmtNode struct {
	*BaseCreateStatementNode
}

func (n *CreateModelStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateModelStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *CreateModelStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedCreateModelStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateModelStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedCreateModelStmt_add_option_list(n.raw, v.getRaw())
}

func (n *CreateModelStmtNode) OutputColumnList() []*OutputColumnNode {
	var v unsafe.Pointer
	internal.ResolvedCreateModelStmt_output_column_list(n.raw, &v)
	var ret []*OutputColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOutputColumnNode(p))
	})
	return ret
}

func (n *CreateModelStmtNode) SetOutputColumnList(v []*OutputColumnNode) {
	internal.ResolvedCreateModelStmt_set_output_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateModelStmtNode) AddOutputColumn(v *OutputColumnNode) {
	internal.ResolvedCreateModelStmt_add_output_column_list(n.raw, v.getRaw())
}

func (n *CreateModelStmtNode) Query() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedCreateModelStmt_query(n.raw, &v)
	return newScanNode(v)
}

func (n *CreateModelStmtNode) SetQuery(v ScanNode) {
	internal.ResolvedCreateModelStmt_set_query(n.raw, v.getRaw())
}

func (n *CreateModelStmtNode) TransformInputColumnList() []*ColumnDefinitionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateModelStmt_transform_input_column_list(n.raw, &v)
	var ret []*ColumnDefinitionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumnDefinitionNode(p))
	})
	return ret
}

func (n *CreateModelStmtNode) SetTransformInputColumnList(v []*ColumnDefinitionNode) {
	internal.ResolvedCreateModelStmt_set_transform_input_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateModelStmtNode) AddTransformInputColumn(v *ColumnDefinitionNode) {
	internal.ResolvedCreateModelStmt_add_transform_input_column_list(n.raw, v.getRaw())
}

func (n *CreateModelStmtNode) TransformList() []*ComputedColumnNode {
	var v unsafe.Pointer
	internal.ResolvedCreateModelStmt_transform_list(n.raw, &v)
	var ret []*ComputedColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newComputedColumnNode(p))
	})
	return ret
}

func (n *CreateModelStmtNode) SetTransformList(v []*ComputedColumnNode) {
	internal.ResolvedCreateModelStmt_set_transform_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateModelStmtNode) AddTransform(v *ComputedColumnNode) {
	internal.ResolvedCreateModelStmt_add_transform_list(n.raw, v.getRaw())
}

func (n *CreateModelStmtNode) TransformOutputColumnList() []*OutputColumnNode {
	var v unsafe.Pointer
	internal.ResolvedCreateModelStmt_transform_output_column_list(n.raw, &v)
	var ret []*OutputColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOutputColumnNode(p))
	})
	return ret
}

func (n *CreateModelStmtNode) SetTransformOutputColumnList(v []*OutputColumnNode) {
	internal.ResolvedCreateModelStmt_set_transform_output_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateModelStmtNode) AddTransformOutputColumn(v *OutputColumnNode) {
	internal.ResolvedCreateModelStmt_add_transform_output_column_list(n.raw, v.getRaw())
}

func (n *CreateModelStmtNode) TransformAnalyticFunctionGroupList() []*AnalyticFunctionGroupNode {
	var v unsafe.Pointer
	internal.ResolvedCreateModelStmt_transform_analytic_function_group_list(n.raw, &v)
	var ret []*AnalyticFunctionGroupNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newAnalyticFunctionGroupNode(p))
	})
	return ret
}

func (n *CreateModelStmtNode) SetTransformAnalyticFunctionGroupList(v []*AnalyticFunctionGroupNode) {
	internal.ResolvedCreateModelStmt_set_transform_analytic_function_group_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateModelStmtNode) AddTransformAnalyticFunctionGroup(v *AnalyticFunctionGroupNode) {
	internal.ResolvedCreateModelStmt_add_transform_analytic_function_group_list(n.raw, v.getRaw())
}

// BaseCreateView common node for CREATE view/materialized view:
//   CREATE [TEMP|MATERIALIZED] [RECURSIVE] VIEW <name> [(...)]
//     [OPTIONS (...)]
//     AS SELECT ...
//
// <option_list> has engine-specific directives for options attached to
//               this view.
// <output_column_list> has the names and types of the columns in the
//                      created view, and maps from <query>'s column_list
//                      to these output columns. If <has_explicit_columns> is
//                      true, names will be explicitly provided.
// <has_explicit_columns> If this is set, the statement includes an explicit
//   column name list. These column names should still be applied even if the
//   query changes or is re-resolved in the future. The view becomes invalid
//   if the query produces a different number of columns.
// <query> is the query to run.
// <sql> is the view query text.
// <sql_security> is the declared security mode for the function. Values
//    include 'INVOKER', 'DEFINER'.
// <recursive> specifies whether or not the view is created with the
//   RECURSIVE keyword.
//
// Note that <query> and <sql> are both marked as IGNORABLE because
// an engine could look at either one (but might not look at both).
// An engine must look at one (and cannot ignore both) to be
// semantically valid, but there is currently no way to enforce that.
//
// The view must produce named columns with unique names.
type BaseCreateViewNode struct {
	*BaseCreateStatementNode
}

func (n *BaseCreateViewNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateViewBase_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *BaseCreateViewNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedCreateViewBase_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *BaseCreateViewNode) AddOption(v *OptionNode) {
	internal.ResolvedCreateViewBase_add_option_list(n.raw, v.getRaw())
}

func (n *BaseCreateViewNode) OutputColumnList() []*OutputColumnNode {
	var v unsafe.Pointer
	internal.ResolvedCreateViewBase_output_column_list(n.raw, &v)
	var ret []*OutputColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOutputColumnNode(p))
	})
	return ret
}

func (n *BaseCreateViewNode) SetOutputColumnList(v []*OutputColumnNode) {
	internal.ResolvedCreateViewBase_set_output_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *BaseCreateViewNode) AddOutputColumn(v *OutputColumnNode) {
	internal.ResolvedCreateViewBase_add_output_column_list(n.raw, v.getRaw())
}

func (n *BaseCreateViewNode) HasExplicitColumns() bool {
	var v bool
	internal.ResolvedCreateViewBase_has_explicit_columns(n.raw, &v)
	return v
}

func (n *BaseCreateViewNode) SetHasExplicitColumns(v bool) {
	internal.ResolvedCreateViewBase_set_has_explicit_columns(n.raw, helper.BoolToInt(v))
}

func (n *BaseCreateViewNode) Query() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedCreateViewBase_query(n.raw, &v)
	return newScanNode(v)
}

func (n *BaseCreateViewNode) SetQuery(v ScanNode) {
	internal.ResolvedCreateViewBase_set_query(n.raw, v.getRaw())
}

func (n *BaseCreateViewNode) SQL() string {
	var v unsafe.Pointer
	internal.ResolvedCreateViewBase_sql(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *BaseCreateViewNode) SetSQL(v string) {
	internal.ResolvedCreateViewBase_set_sql(n.raw, helper.StringToPtr(v))
}

func (n *BaseCreateViewNode) SQLSecurity() SQLSecurity {
	var v int
	internal.ResolvedCreateViewBase_sql_security(n.raw, &v)
	return SQLSecurity(v)
}

func (n *BaseCreateViewNode) SetSQLSecurity(v SQLSecurity) {
	internal.ResolvedCreateViewBase_set_sql_security(n.raw, int(v))
}

// IsValueTable if true, this view produces a value table. Rather than producing
// rows with named columns, it produces rows with a single unnamed
// value type.  output_column_list will have exactly one column, with
// an empty name.
func (n *BaseCreateViewNode) IsValueTable() bool {
	var v bool
	internal.ResolvedCreateViewBase_is_value_table(n.raw, &v)
	return v
}

func (n *BaseCreateViewNode) SetIsValueTable(v bool) {
	internal.ResolvedCreateViewBase_set_is_value_table(n.raw, helper.BoolToInt(v))
}

// Recursive true if the view uses the RECURSIVE keyword. <query>
// can be a RecursiveScanNode only if this is true.
func (n *BaseCreateViewNode) Recursive() bool {
	var v bool
	internal.ResolvedCreateViewBase_recursive(n.raw, &v)
	return v
}

func (n *BaseCreateViewNode) SetRecursive(v bool) {
	internal.ResolvedCreateViewBase_set_recursive(n.raw, helper.BoolToInt(v))
}

// CreateViewStmtNode this statement:
// CREATE [TEMP] VIEW <name> [(...)] [OPTIONS (...)] AS SELECT ...
type CreateViewStmtNode struct {
	*BaseCreateViewNode
}

// WithPartitionColumnsNode this statement:
// WITH PARTITION COLUMNS [(column schema, ...)]
type WithPartitionColumnsNode struct {
	*BaseArgumentNode
}

func (n *WithPartitionColumnsNode) ColumnDefinitionList() []*ColumnDefinitionNode {
	var v unsafe.Pointer
	internal.ResolvedWithPartitionColumns_column_definition_list(n.raw, &v)
	var ret []*ColumnDefinitionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumnDefinitionNode(p))
	})
	return ret
}

func (n *WithPartitionColumnsNode) SetColumnDefinitionList(v []*ColumnDefinitionNode) {
	internal.ResolvedWithPartitionColumns_set_column_definition_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *WithPartitionColumnsNode) AddColumnDefinition(v *ColumnDefinitionNode) {
	internal.ResolvedWithPartitionColumns_add_column_definition_list(n.raw, v.getRaw())
}

// CreateSnapshotTableStmtNode this statement:
//   CREATE SNAPSHOT TABLE [IF NOT EXISTS] <name> [OPTIONS (...)]
//   CLONE <name>
//           [FOR SYSTEM_TIME AS OF <time_expr>]
//
// <clone_from> the source data to clone data from.
//              ResolvedTableScan will represent the source table, with an
//              optional for_system_time_expr.
//              The TableScanNode may be wrapped inside a
//              FilterScanNode if the source table has a where clause.
//              No other Scan types are allowed here.
//              By default, all fields (column names, types, constraints,
//              partition, clustering, options etc.) will be inherited from
//              the source table. If table options are explicitly set, the
//              explicit options will take precedence.
//              The 'clone_from.column_list' field may be set, but should be ignored.
type CreateSnapshotTableStmtNode struct {
	*BaseCreateStatementNode
}

func (n *CreateSnapshotTableStmtNode) CloneFrom() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedCreateSnapshotTableStmt_clone_from(n.raw, &v)
	return newScanNode(v)
}

func (n *CreateSnapshotTableStmtNode) SetCloneFrom(v ScanNode) {
	internal.ResolvedCreateSnapshotTableStmt_set_clone_from(n.raw, v.getRaw())
}

func (n *CreateSnapshotTableStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateSnapshotTableStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *CreateSnapshotTableStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedCreateSnapshotTableStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateSnapshotTableStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedCreateSnapshotTableStmt_add_option_list(n.raw, v.getRaw())
}

// CreateExternalTableStmtNode this statement:
// CREATE [TEMP] EXTERNAL TABLE <name> [(column type, ...)]
// [DEFAULT COLLATE <collation_name>]
// [WITH PARTITION COLUMN [(column type, ...)]]
// [WITH CONNECTION connection_name]
// OPTIONS (...)
type CreateExternalTableStmtNode struct {
	*BaseCreateTableStmtNode
}

func (n *CreateExternalTableStmtNode) WithPartitionColumns() *WithPartitionColumnsNode {
	var v unsafe.Pointer
	internal.ResolvedCreateExternalTableStmt_with_partition_columns(n.raw, &v)
	return newWithPartitionColumnsNode(v)
}

func (n *CreateExternalTableStmtNode) SetWithPartitionColumns(v *WithPartitionColumnsNode) {
	internal.ResolvedCreateExternalTableStmt_set_with_partition_columns(n.raw, v.getRaw())
}

func (n *CreateExternalTableStmtNode) Connection() *ConnectionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateExternalTableStmt_connection(n.raw, &v)
	return newConnectionNode(v)
}

func (n *CreateExternalTableStmtNode) SetConnection(v *ConnectionNode) {
	internal.ResolvedCreateExternalTableStmt_set_connection(n.raw, v.getRaw())
}

// ExportModelStmtNode this statement:
//   EXPORT MODEL <model_name_path> [WITH CONNECTION <connection>]
//   <option_list>
// which is used to export a model to a specific location.
// <connection> is the connection that the model is written to.
// <option_list> identifies user specified options to use when exporting the model.
type ExportModelStmtNode struct {
	*BaseStatementNode
}

func (n *ExportModelStmtNode) ModelNamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedExportModelStmt_model_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *ExportModelStmtNode) SetModelNamePath(v []string) {
	internal.ResolvedExportModelStmt_set_model_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *ExportModelStmtNode) AddModelNamePath(v string) {
	internal.ResolvedExportModelStmt_add_model_name_path(n.raw, helper.StringToPtr(v))
}

func (n *ExportModelStmtNode) Connection() *ConnectionNode {
	var v unsafe.Pointer
	internal.ResolvedExportModelStmt_connection(n.raw, &v)
	return newConnectionNode(v)
}

func (n *ExportModelStmtNode) SetConnection(v *ConnectionNode) {
	internal.ResolvedExportModelStmt_set_connection(n.raw, v.getRaw())
}

func (n *ExportModelStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedExportModelStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *ExportModelStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedExportModelStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *ExportModelStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedExportModelStmt_add_option_list(n.raw, v.getRaw())
}

// ExportDataStmtNode this statement:
//   EXPORT DATA [WITH CONNECTION] <connection> (<option_list>) AS SELECT ...
// which is used to run a query and export its result somewhere
// without giving the result a table name.
// <connection> connection reference for accessing destination source.
// <option_list> has engine-specific directives for how and where to
//               materialize the query result.
// <output_column_list> has the names and types of the columns produced by
//                      the query, and maps from <query>'s column_list
//                      to these output columns.  The engine may ignore
//                      the column names depending on the output format.
// <query> is the query to run.
//
// The query must produce named columns with unique names.
type ExportDataStmtNode struct {
	*BaseStatementNode
}

func (n *ExportDataStmtNode) Connection() *ConnectionNode {
	var v unsafe.Pointer
	internal.ResolvedExportDataStmt_connection(n.raw, &v)
	return newConnectionNode(v)
}

func (n *ExportDataStmtNode) SetConnection(v *ConnectionNode) {
	internal.ResolvedExportDataStmt_set_connection(n.raw, v.getRaw())
}

func (n *ExportDataStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedExportDataStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *ExportDataStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedExportDataStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *ExportDataStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedExportDataStmt_add_option_list(n.raw, v.getRaw())
}

func (n *ExportDataStmtNode) OutputColumnList() []*OutputColumnNode {
	var v unsafe.Pointer
	internal.ResolvedExportDataStmt_output_column_list(n.raw, &v)
	var ret []*OutputColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOutputColumnNode(p))
	})
	return ret
}

func (n *ExportDataStmtNode) SetOutputColumnList(v []*OutputColumnNode) {
	internal.ResolvedExportDataStmt_set_output_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *ExportDataStmtNode) AddOutputColumn(v *OutputColumnNode) {
	internal.ResolvedExportDataStmt_add_output_column_list(n.raw, v.getRaw())
}

// IsValueTable if true, the result of this query is a value table. Rather than
// producing rows with named columns, it produces rows with a single
// unnamed value type.  output_column_list will have exactly one
// column, with an empty name.
func (n *ExportDataStmtNode) IsValueTable() bool {
	var v bool
	internal.ResolvedExportDataStmt_is_value_table(n.raw, &v)
	return v
}

func (n *ExportDataStmtNode) SetIsValueTable(v bool) {
	internal.ResolvedExportDataStmt_set_is_value_table(n.raw, helper.BoolToInt(v))
}

func (n *ExportDataStmtNode) Query() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedExportDataStmt_query(n.raw, &v)
	return newScanNode(v)
}

func (n *ExportDataStmtNode) SetQuery(v ScanNode) {
	internal.ResolvedExportDataStmt_set_query(n.raw, v.getRaw())
}

// DefineTableStmtNode this statement: DEFINE TABLE name (...);
//
// <name_path> is a vector giving the identifier path in the table name.
// <option_list> has engine-specific options of how the table is defined.
//
// DEFINE TABLE normally has the same effect as CREATE TEMP EXTERNAL TABLE.
type DefineTableStmtNode struct {
	*BaseStatementNode
}

func (n *DefineTableStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedDefineTableStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *DefineTableStmtNode) SetNamePath(v []string) {
	internal.ResolvedDefineTableStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *DefineTableStmtNode) AddNamePath(v string) {
	internal.ResolvedDefineTableStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

func (n *DefineTableStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedDefineTableStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *DefineTableStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedDefineTableStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *DefineTableStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedDefineTableStmt_add_option_list(n.raw, v.getRaw())
}

// DescribeStmtNode this statement:
// DESCRIBE [<object_type>] <name> [FROM <from_name_path>];
//
// <object_type> is an optional string identifier,
//               e.g., "INDEX", "FUNCTION", "TYPE", etc.
// <name_path> is a vector giving the identifier path for the object to be described.
// <from_name_path> is an optional vector giving the identifier path of a
//                    containing object, e.g. a table.
type DescribeStmtNode struct {
	*BaseStatementNode
}

func (n *DescribeStmtNode) ObjectType() string {
	var v unsafe.Pointer
	internal.ResolvedDescribeStmt_object_type(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *DescribeStmtNode) SetObjectType(v string) {
	internal.ResolvedDescribeStmt_set_object_type(n.raw, helper.StringToPtr(v))
}

func (n *DescribeStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedDescribeStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *DescribeStmtNode) SetNamePath(v []string) {
	internal.ResolvedDescribeStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *DescribeStmtNode) AddNamePath(v string) {
	internal.ResolvedDescribeStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

func (n *DescribeStmtNode) FromNamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedDescribeStmt_from_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *DescribeStmtNode) SetFromNamePath(v []string) {
	internal.ResolvedDescribeStmt_set_from_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *DescribeStmtNode) AddFromNamePath(v string) {
	internal.ResolvedDescribeStmt_add_from_name_path(n.raw, helper.StringToPtr(v))
}

// ShowStmtNode this statement:
// SHOW <identifier> [FROM <name_path>] [LIKE <like_expr>];
//
// <identifier> is a string that determines the type of objects to be shown,
//              e.g., TABLES, COLUMNS, INDEXES, STATUS,
// <name_path> is an optional path to an object from which <identifier>
//             objects will be shown, e.g., if <identifier> = INDEXES and
//             <name> = table_name, the indexes of "table_name" will be shown.
// <like_expr> is an optional LiteralNode of type string that if present
//             restricts the objects shown to have a name like this string.
type ShowStmtNode struct {
	*BaseStatementNode
}

func (n *ShowStmtNode) Identifier() string {
	var v unsafe.Pointer
	internal.ResolvedShowStmt_identifier(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *ShowStmtNode) SetIdentifier(v string) {
	internal.ResolvedShowStmt_set_identifier(n.raw, helper.StringToPtr(v))
}

func (n *ShowStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedShowStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *ShowStmtNode) SetNamePath(v []string) {
	internal.ResolvedShowStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *ShowStmtNode) AddNamePath(v string) {
	internal.ResolvedShowStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

func (n *ShowStmtNode) LikeExpr() *LiteralNode {
	var v unsafe.Pointer
	internal.ResolvedShowStmt_like_expr(n.raw, &v)
	return newLiteralNode(v)
}

func (n *ShowStmtNode) SetLikeExpr(v *LiteralNode) {
	internal.ResolvedShowStmt_set_like_expr(n.raw, v.getRaw())
}

// BeginStmtNode this statement:
// BEGIN [TRANSACTION] [ <transaction_mode> [, ...] ]
//
// Where transaction_mode is one of:
//      READ ONLY
//      READ WRITE
//      <isolation_level>
//
// <isolation_level> is a string vector storing the identifiers after
//       ISOLATION LEVEL. The strings inside vector could be one of the
//       SQL standard isolation levels:
//
//                   READ UNCOMMITTED
//                   READ COMMITTED
//                   READ REPEATABLE
//                   SERIALIZABLE
//
//       or could be arbitrary strings. ZetaSQL does not validate that
//       the string is valid.
type BeginStmtNode struct {
	*BaseStatementNode
}

func (n *BeginStmtNode) ReadWriteMode() ReadWriteMode {
	var v int
	internal.ResolvedBeginStmt_read_write_mode(n.raw, &v)
	return ReadWriteMode(v)
}

func (n *BeginStmtNode) SetReadWriteMode(v ReadWriteMode) {
	internal.ResolvedBeginStmt_set_read_write_mode(n.raw, int(v))
}

func (n *BeginStmtNode) IsolationLevelList() []string {
	var v unsafe.Pointer
	internal.ResolvedBeginStmt_isolation_level_list(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *BeginStmtNode) SetIsolationLevelList(v []string) {
	internal.ResolvedBeginStmt_set_isolation_level_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *BeginStmtNode) AddIsolationLevel(v string) {
	internal.ResolvedBeginStmt_add_isolation_level_list(n.raw, helper.StringToPtr(v))
}

// SetTransactionStmtNode this statement:
// SET TRANSACTION <transaction_mode> [, ...]
//
// Where transaction_mode is one of:
//      READ ONLY
//      READ WRITE
//      <isolation_level>
//
// <isolation_level> is a string vector storing the identifiers after
//       ISOLATION LEVEL. The strings inside vector could be one of the
//       SQL standard isolation levels:
//
//                   READ UNCOMMITTED
//                   READ COMMITTED
//                   READ REPEATABLE
//                   SERIALIZABLE
//
//       or could be arbitrary strings. ZetaSQL does not validate that
//       the string is valid.
type SetTransactionStmtNode struct {
	*BaseStatementNode
}

func (n *SetTransactionStmtNode) ReadWriteMode() ReadWriteMode {
	var v int
	internal.ResolvedSetTransactionStmt_read_write_mode(n.raw, &v)
	return ReadWriteMode(v)
}

func (n *SetTransactionStmtNode) SetReadWriteMode(v ReadWriteMode) {
	internal.ResolvedSetTransactionStmt_set_read_write_mode(n.raw, int(v))
}

func (n *SetTransactionStmtNode) IsolationLevelList() []string {
	var v unsafe.Pointer
	internal.ResolvedSetTransactionStmt_isolation_level_list(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *SetTransactionStmtNode) SetIsolationLevelList(v []string) {
	internal.ResolvedSetTransactionStmt_set_isolation_level_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *SetTransactionStmtNode) AddIsolationLevel(v string) {
	internal.ResolvedSetTransactionStmt_add_isolation_level_list(n.raw, helper.StringToPtr(v))
}

// CommitStmtNode this statement:
// COMMIT [TRANSACTION];
type CommitStmtNode struct {
	*BaseStatementNode
}

// RollbackStmtNode this statement:
// ROLLBACK [TRANSACTION];
type RollbackStmtNode struct {
	*BaseStatementNode
}

// StartBatchStmtNode this statement:
// START BATCH [<batch_type>];
//
// <batch_type> is an optional string identifier that identifies the type of
//              the batch. (e.g. "DML" or "DDL)
type StartBatchStmtNode struct {
	*BaseStatementNode
}

func (n *StartBatchStmtNode) BatchType() string {
	var v unsafe.Pointer
	internal.ResolvedStartBatchStmt_batch_type(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *StartBatchStmtNode) SetBatchType(v string) {
	internal.ResolvedStartBatchStmt_set_batch_type(n.raw, helper.StringToPtr(v))
}

// RunBatchStmtNode this statement: RUN BATCH;
type RunBatchStmtNode struct {
	*BaseStatementNode
}

// AbortBatchStmtNode this statement: ABORT BATCH;
type AbortBatchStmtNode struct {
	*BaseStatementNode
}

// DropStmtNode this statement:
// DROP <object_type> [IF EXISTS] <name_path> [<drop_mode>];
//
// <object_type> is an string identifier,
//               e.g., "TABLE", "VIEW", "INDEX", "FUNCTION", "TYPE", etc.
// <name_path> is a vector giving the identifier path for the object to be dropped.
// <is_if_exists> silently ignore the "name_path does not exist" error.
// <drop_mode> specifies drop mode RESTRICT/CASCASE, if any.
type DropStmtNode struct {
	*BaseStatementNode
}

func (n *DropStmtNode) ObjectType() string {
	var v unsafe.Pointer
	internal.ResolvedDropStmt_object_type(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *DropStmtNode) SetObjectType(v string) {
	internal.ResolvedDropStmt_set_object_type(n.raw, helper.StringToPtr(v))
}

func (n *DropStmtNode) IsIfExists() bool {
	var v bool
	internal.ResolvedDropStmt_is_if_exists(n.raw, &v)
	return v
}

func (n *DropStmtNode) SetIsIfExists(v bool) {
	internal.ResolvedDropStmt_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

func (n *DropStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedDropStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *DropStmtNode) SetNamePath(v []string) {
	internal.ResolvedDropStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *DropStmtNode) AddNamePath(v string) {
	internal.ResolvedDropStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

func (n *DropStmtNode) DropMode() DropMode {
	var v int
	internal.ResolvedDropStmt_drop_mode(n.raw, &v)
	return DropMode(v)
}

func (n *DropStmtNode) SetDropMode(v DropMode) {
	internal.ResolvedDropStmt_set_drop_mode(n.raw, int(v))
}

// DropMaterializedViewStmtNode this statement:
// DROP MATERIALIZED VIEW [IF EXISTS] <name_path>;
//
// <name_path> is a vector giving the identifier path for the object to be dropped.
// <is_if_exists> silently ignore the "name_path does not exist" error.
type DropMaterializedViewStmtNode struct {
	*BaseStatementNode
}

func (n *DropMaterializedViewStmtNode) IsIfExists() bool {
	var v bool
	internal.ResolvedDropMaterializedViewStmt_is_if_exists(n.raw, &v)
	return v
}

func (n *DropMaterializedViewStmtNode) SetIsIfExists(v bool) {
	internal.ResolvedDropMaterializedViewStmt_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

func (n *DropMaterializedViewStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedDropMaterializedViewStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *DropMaterializedViewStmtNode) SetNamePath(v []string) {
	internal.ResolvedDropMaterializedViewStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *DropMaterializedViewStmtNode) AddNamePath(v string) {
	internal.ResolvedDropMaterializedViewStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

// DropSnapshotTableStmtNode this statement:
// DROP SNAPSHOT TABLE [IF EXISTS] <name_path>;
//
// <name_path> is a vector giving the identifier path for the object to be dropped.
// <is_if_exists> silently ignore the "name_path does not exist" error.
type DropSnapshotTableStmtNode struct {
	*BaseStatementNode
}

func (n *DropSnapshotTableStmtNode) IsIfExists() bool {
	var v bool
	internal.ResolvedDropSnapshotTableStmt_is_if_exists(n.raw, &v)
	return v
}

func (n *DropSnapshotTableStmtNode) SetIsIfExists(v bool) {
	internal.ResolvedDropSnapshotTableStmt_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

func (n *DropSnapshotTableStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedDropSnapshotTableStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *DropSnapshotTableStmtNode) SetNamePath(v []string) {
	internal.ResolvedDropSnapshotTableStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *DropSnapshotTableStmtNode) AddNamePath(v string) {
	internal.ResolvedDropSnapshotTableStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

// RecursiveRefScanNode scan the previous iteration of the recursive alias currently being
// defined, from inside the recursive subquery which defines it. Such nodes
// can exist only in the recursive term of a RecursiveScanNode node.
// The column_list produced here will match 1:1 with the column_list produced
// by the referenced subquery and will be given a new unique name to each
// column produced for this scan.
type RecursiveRefScanNode struct {
	*BaseScanNode
}

// RecursiveScanNode a recursive query inside a WITH RECURSIVE or RECURSIVE VIEW.
// A RecursiveScanNode may appear in a resolved tree only as a top-level
// input scan of a WithEntryNode or BaseCreateViewNode.
//
// Recursive queries must satisfy the form:
//     <non-recursive-query> UNION [ALL|DISTINCT] <recursive-query>
//
// where self-references to table being defined are allowed only in the
// <recursive-query> section.
//
// <column_list> is a set of new ColumnsNode created by this scan.
// Each input SetOperationItemNode has an <output_column_list> which
// matches 1:1 with <column_list> and specifies how the input <scan>'s
// columns map into the final <column_list>.
//
// At runtime, a recursive scan is evaluated using an iterative process:
//
// Step 1: Evaluate the non-recursive term. If UNION DISTINCT
//   is specified, discard duplicates.
//
// Step 2:
//   Repeat until step 2 produces an empty result:
//     Evaluate the recursive term, binding the recursive table to the
//     new rows produced by previous step. If UNION DISTINCT is specified,
//     discard duplicate rows, as well as any rows which match any
//     previously-produced result.
//
// Step 3:
//   The final content of the recursive table is the UNION ALL of all results
//   produced (step 1, plus all iterations of step 2).
//
// RecursiveScanNode only supports a recursive WITH entry which
//   directly references itself; ZetaSQL does not support mutual recursion
//   between multiple with-clause elements.
type RecursiveScanNode struct {
	*BaseScanNode
}

func (n *RecursiveScanNode) OpType() RecursiveSetOperationType {
	var v int
	internal.ResolvedRecursiveScan_op_type(n.raw, &v)
	return RecursiveSetOperationType(v)
}

func (n *RecursiveScanNode) SetOpType(v RecursiveSetOperationType) {
	internal.ResolvedRecursiveScan_set_op_type(n.raw, int(v))
}

func (n *RecursiveScanNode) NonRecursiveTerm() *SetOperationItemNode {
	var v unsafe.Pointer
	internal.ResolvedRecursiveScan_non_recursive_term(n.raw, &v)
	return newSetOperationItemNode(v)
}

func (n *RecursiveScanNode) SetNonRecursiveTerm(v *SetOperationItemNode) {
	internal.ResolvedRecursiveScan_set_non_recursive_term(n.raw, v.getRaw())
}

func (n *RecursiveScanNode) RecursiveTerm() *SetOperationItemNode {
	var v unsafe.Pointer
	internal.ResolvedRecursiveScan_recursive_term(n.raw, &v)
	return newSetOperationItemNode(v)
}

func (n *RecursiveScanNode) SetRecursiveTerm(v *SetOperationItemNode) {
	internal.ResolvedRecursiveScan_set_recursive_term(n.raw, v.getRaw())
}

// WithScanNode this represents a SQL WITH query (or subquery) like
//   WITH [RECURSIVE] <with_query_name1> AS (<with_subquery1>),
//        <with_query_name2> AS (<with_subquery2>)
//   <query>;
//
// WITH entries are sorted in dependency order so that an entry can only
// reference entries earlier in <with_entry_list>, plus itself if the
// RECURSIVE keyword is used. If the RECURSIVE keyword is not used, this will
// be the same order as in the original query, since an entry which
// references itself or any entry later in the list is not allowed.
//
// If a WITH subquery is referenced multiple times, the full query should
// behave as if the subquery runs only once and its result is reused.
//
// There will be one WithEntryNode here for each subquery in the SQL
// WITH statement, in the same order as in the query.
//
// Inside the resolved <query>, or any <with_entry_list> occurring after
// its definition, a <with_query_name> used as a table scan will be
// represented using a WithRefScanNode.
//
// The <with_query_name> aliases are always unique within a query, and should
// be used to connect the WithRefScanNode to the original query
// definition.  The subqueries are not inlined and duplicated into the tree.
//
// In ZetaSQL 1.0, WITH is allowed only on the outermost query and not in
// subqueries, so the WithScanNode node can only occur as the outermost
// scan in a statement (e.g. a QueryStmt or CreateTableAsSelectStmt).
//
// In ZetaSQL 1.1 (language option FEATURE_V_1_1_WITH_ON_SUBQUERY), WITH
// is allowed on subqueries.  Then, WithScanNode can occur anywhere in
// the tree.  The alias introduced by a WithEntryNode is visible only
// in subsequent WithEntryNode queries and in <query>.  The aliases used
// must be globally unique in the resolved AST however, so consumers do not
// need to implement any scoping for these names.  Because the aliases are
// unique, it is legal to collect all WithEntriesNode in the tree and
// treat them as if they were a single WITH clause at the outermost level.
//
// In ZetaSQL 1.3 (language option FEATURE_V_1_3_WITH_RECURSIVE), WITH
// RECURSIVE is supported, which allows any <with_subquery> to reference
// any <with_query_name>, regardless of order, including WITH entries which
// reference themself. Circular dependency chains of WITH entries are allowed
// only for direct self-references, and only when the corresponding
// <with_subquery> takes the form "<non-recursive-term> UNION [ALL|DISTINCT]
// <recursive-term>", with all references to the current <with_query_name>
// confined to the recursive term.
//
// The subqueries inside WithEntriesNode cannot be correlated.
//
// If a WITH subquery is defined but never referenced, it will still be
// resolved and still show up here.  Query engines may choose not to run it.
type WithScanNode struct {
	*BaseScanNode
}

func (n *WithScanNode) WithEntryList() []*WithEntryNode {
	var v unsafe.Pointer
	internal.ResolvedWithScan_with_entry_list(n.raw, &v)
	var ret []*WithEntryNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newWithEntryNode(p))
	})
	return ret
}

func (n *WithScanNode) SetWithEntryList(v []*WithEntryNode) {
	internal.ResolvedWithScan_set_with_entry_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *WithScanNode) AddWithEntry(v *WithEntryNode) {
	internal.ResolvedWithScan_add_with_entry_list(n.raw, v.getRaw())
}

func (n *WithScanNode) Query() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedWithScan_query(n.raw, &v)
	return newScanNode(v)
}

func (n *WithScanNode) SetQuery(v ScanNode) {
	internal.ResolvedWithScan_set_query(n.raw, v.getRaw())
}

// Recursive true if the WITH clause uses the recursive keyword.
func (n *WithScanNode) Recursive() bool {
	var v bool
	internal.ResolvedWithScan_recursive(n.raw, &v)
	return v
}

func (n *WithScanNode) SetRecursive(v bool) {
	internal.ResolvedWithScan_set_recursive(n.raw, helper.BoolToInt(v))
}

// WithEntryNode represents one aliased subquery introduced in a WITH clause.
//
// The <with_query_name>s must be globally unique in the full resolved AST.
// The <with_subquery> cannot be correlated and cannot reference any
// columns from outside.  It may reference other WITH subqueries.
//
// See WithScanNode for full details.
type WithEntryNode struct {
	*BaseArgumentNode
}

func (n *WithEntryNode) WithQueryName() string {
	var v unsafe.Pointer
	internal.ResolvedWithEntry_with_query_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *WithEntryNode) SetWithQueryName(v string) {
	internal.ResolvedWithEntry_set_with_query_name(n.raw, helper.StringToPtr(v))
}

func (n *WithEntryNode) WithSubquery() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedWithEntry_with_subquery(n.raw, &v)
	return newScanNode(v)
}

func (n *WithEntryNode) SetWithSubquery(v ScanNode) {
	internal.ResolvedWithEntry_set_with_subquery(n.raw, v.getRaw())
}

// OptionNode represents one SQL hint key/value pair.
// The SQL syntax @{ key1=value1, key2=value2, some_db.key3=value3 }
// will expand to three OptionsNode.  Keyword hints (e.g. LOOKUP JOIN)
// are interpreted as shorthand, and will be expanded to a OptionNode
// attached to the appropriate node before any explicit long-form hints.
//
// OptionsNode are attached to the ScanNode corresponding to the
// operator that the SQL hint was associated with.
// Hint semantics are implementation defined.
//
// Each hint is resolved as a [<qualifier>.]<name>:=<value> pair.
//   <qualifier> will be empty if no qualifier was present.
//   <name> is always non-empty.
//   <value> can be a LiteralNode or a ParameterNode,
//           a cast of a ParameterNode (for typed hints only),
//           or a general expression (on constant inputs).
//
// If AllowedHintsAndOptions was set in AnalyzerOptions, and this hint or
// option was included there and had an expected type, the type of <value>
// will match that expected type.  Unknown hints (not listed in
// AllowedHintsAndOptions) are not stripped and will still show up here.
//
// If non-empty, <qualifier> should be interpreted as a target system name,
// and a database system should ignore any hints targeted to different
// systems.
//
// The SQL syntax allows using an identifier as a hint value.
// Such values are stored here as LiteralNodes with string type.
type OptionNode struct {
	*BaseArgumentNode
}

func (n *OptionNode) Qualifier() string {
	var v unsafe.Pointer
	internal.ResolvedOption_qualifier(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *OptionNode) SetQualifier(v string) {
	internal.ResolvedOption_set_qualifier(n.raw, helper.StringToPtr(v))
}

func (n *OptionNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedOption_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *OptionNode) SetName(v string) {
	internal.ResolvedOption_set_name(n.raw, helper.StringToPtr(v))
}

func (n *OptionNode) Value() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedOption_value(n.raw, &v)
	return newExprNode(v)
}

func (n *OptionNode) SetValue(v ExprNode) {
	internal.ResolvedOption_set_value(n.raw, v.getRaw())
}

// WindowPartitioningNode window partitioning specification for an analytic function call.
//
// PARTITION BY keys in <partition_by_list>.
type WindowPartitioningNode struct {
	*BaseArgumentNode
}

func (n *WindowPartitioningNode) PartitionByList() []*ColumnRefNode {
	var v unsafe.Pointer
	internal.ResolvedWindowPartitioning_partition_by_list(n.raw, &v)
	var ret []*ColumnRefNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumnRefNode(p))
	})
	return ret
}

func (n *WindowPartitioningNode) SetPartitionByList(v []*ColumnRefNode) {
	internal.ResolvedWindowPartitioning_set_partition_by_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *WindowPartitioningNode) AddPartitionBy(v *ColumnRefNode) {
	internal.ResolvedWindowPartitioning_add_partition_by_list(n.raw, v.getRaw())
}

func (n *WindowPartitioningNode) HintList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedWindowPartitioning_hint_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *WindowPartitioningNode) SetHintList(v []*OptionNode) {
	internal.ResolvedWindowPartitioning_set_hint_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *WindowPartitioningNode) AddHint(v *OptionNode) {
	internal.ResolvedWindowPartitioning_add_hint_list(n.raw, v.getRaw())
}

// WindowOrderingNode window ordering specification for an analytic function call.
//
// ORDER BY items in <order_by_list>. There should be exactly one ORDER
// BY item if this is a window ORDER BY for a RANGE-based window.
type WindowOrderingNode struct {
	*BaseArgumentNode
}

func (n *WindowOrderingNode) OrderByItemList() []*OrderByItemNode {
	var v unsafe.Pointer
	internal.ResolvedWindowOrdering_order_by_item_list(n.raw, &v)
	var ret []*OrderByItemNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOrderByItemNode(p))
	})
	return ret
}

func (n *WindowOrderingNode) SetOrderByItemList(v []*OrderByItemNode) {
	internal.ResolvedWindowOrdering_set_order_by_item_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *WindowOrderingNode) AddOrderByItem(v *OrderByItemNode) {
	internal.ResolvedWindowOrdering_add_order_by_item_list(n.raw, v.getRaw())
}

func (n *WindowOrderingNode) HintList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedWindowOrdering_hint_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *WindowOrderingNode) SetHintList(v []*OptionNode) {
	internal.ResolvedWindowOrdering_set_hint_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *WindowOrderingNode) AddHint(v *OptionNode) {
	internal.ResolvedWindowOrdering_add_hint_list(n.raw, v.getRaw())
}

// WindowFrameNode window framing specification for an analytic function call.
//
// ROW-based window frames compute the frame based on physical offsets
// from the current row.
// RANGE-based window frames compute the frame based on a logical
// range of rows around the current row based on the current row's
// ORDER BY key value.
//
// <start_expr> and <end_expr> cannot be NULL. If the window frame
// is one-sided in the input query, the resolver will generate an
// implicit ending boundary.
type WindowFrameNode struct {
	*BaseArgumentNode
}

func (n *WindowFrameNode) FrameUnit() FrameUnit {
	var v int
	internal.ResolvedWindowFrame_frame_unit(n.raw, &v)
	return FrameUnit(v)
}

func (n *WindowFrameNode) SetFrameUnit(v FrameUnit) {
	internal.ResolvedWindowFrame_set_frame_unit(n.raw, int(v))
}

func (n *WindowFrameNode) StartExpr() *WindowFrameExprNode {
	var v unsafe.Pointer
	internal.ResolvedWindowFrame_start_expr(n.raw, &v)
	return newWindowFrameExprNode(v)
}

func (n *WindowFrameNode) SetStartExpr(v *WindowFrameExprNode) {
	internal.ResolvedWindowFrame_set_start_expr(n.raw, v.getRaw())
}

func (n *WindowFrameNode) EndExpr() *WindowFrameExprNode {
	var v unsafe.Pointer
	internal.ResolvedWindowFrame_end_expr(n.raw, &v)
	return newWindowFrameExprNode(v)
}

func (n *WindowFrameNode) SetEndExpr(v *WindowFrameExprNode) {
	internal.ResolvedWindowFrame_set_end_expr(n.raw, v.getRaw())
}

// AnalyticFunctionGroupNode represents a group of analytic function calls that shares PARTITION
// BY and ORDER BY.
//
// <partition_by> can be NULL. <order_by> may be NULL depending on the
// functions in <analytic_function_list> and the window frame unit. See
// (broken link) for more details.
//
// All expressions in <analytic_function_list> have a
// ResolvedAggregateFunctionCall with a function in mode
// Function::AGGREGATE or Function::ANALYTIC.
type AnalyticFunctionGroupNode struct {
	*BaseArgumentNode
}

func (n *AnalyticFunctionGroupNode) PartitionBy() *WindowPartitioningNode {
	var v unsafe.Pointer
	internal.ResolvedAnalyticFunctionGroup_partition_by(n.raw, &v)
	return newWindowPartitioningNode(v)
}

func (n *AnalyticFunctionGroupNode) SetPartitionBy(v *WindowPartitioningNode) {
	internal.ResolvedAnalyticFunctionGroup_set_partition_by(n.raw, v.getRaw())
}

func (n *AnalyticFunctionGroupNode) OrderBy() *WindowOrderingNode {
	var v unsafe.Pointer
	internal.ResolvedAnalyticFunctionGroup_order_by(n.raw, &v)
	return newWindowOrderingNode(v)
}

func (n *AnalyticFunctionGroupNode) SetOrderBy(v *WindowOrderingNode) {
	internal.ResolvedAnalyticFunctionGroup_set_order_by(n.raw, v.getRaw())
}

func (n *AnalyticFunctionGroupNode) AnalyticFunctionList() []*ComputedColumnNode {
	var v unsafe.Pointer
	internal.ResolvedAnalyticFunctionGroup_analytic_function_list(n.raw, &v)
	var ret []*ComputedColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newComputedColumnNode(p))
	})
	return ret
}

func (n *AnalyticFunctionGroupNode) SetAnalyticFunctionList(v []*ComputedColumnNode) {
	internal.ResolvedAnalyticFunctionGroup_set_analytic_function_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AnalyticFunctionGroupNode) AddAnalyticFunction(v *ComputedColumnNode) {
	internal.ResolvedAnalyticFunctionGroup_add_analytic_function_list(n.raw, v.getRaw())
}

// WindowFrameExprNode window frame boundary expression that determines the first/last row of
// the moving window for each tuple.
//
// <expression> cannot be NULL if the type is OFFSET_PRECEDING
// or OFFSET_FOLLOWING. It must be a constant expression. If this is a
// boundary for a ROW-based window, it must be integer type. Otherwise,
// it must be numeric type and must match exactly the type of the window
// ordering expression.
type WindowFrameExprNode struct {
	*BaseArgumentNode
}

func (n *WindowFrameExprNode) BoundaryType() BoundaryType {
	var v int
	internal.ResolvedWindowFrameExpr_boundary_type(n.raw, &v)
	return BoundaryType(v)
}

func (n *WindowFrameExprNode) SetBoundaryType(v BoundaryType) {
	internal.ResolvedWindowFrameExpr_set_boundary_type(n.raw, int(v))
}

func (n *WindowFrameExprNode) Expression() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedWindowFrameExpr_expression(n.raw, &v)
	return newExprNode(v)
}

func (n *WindowFrameExprNode) SetExpression(v ExprNode) {
	internal.ResolvedWindowFrameExpr_set_expression(n.raw, v.getRaw())
}

// DMLValueNode represents a value inside an INSERT or UPDATE statement.
//
// The <value> is either an expression or a DMLDefault.
//
// For proto fields, NULL values mean the field should be cleared.
type DMLValueNode struct {
	*BaseArgumentNode
}

func (n *DMLValueNode) Value() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedDMLValue_value(n.raw, &v)
	return newExprNode(v)
}

func (n *DMLValueNode) SetValue(v ExprNode) {
	internal.ResolvedDMLValue_set_value(n.raw, v.getRaw())
}

// DMLDefaultNode represents the value DEFAULT that shows up (in place of a
// value expression) in INSERT and UPDATE statements.
// For columns, engines should substitute the engine-defined default value
// for that column, or give an error.
// For proto fields, this always means to clear the field.
// This will never show up inside expressions other than DMLValueNode.
type DMLDefaultNode struct {
	*BaseExprNode
}

// AssertStmtNode represents the ASSERT statement:
//   ASSERT <expression> [AS <description>];
//
// <expression> is any expression that returns a bool.
// <description> is an optional string literal used to give a more
// descriptive error message in case the ASSERT fails.
type AssertStmtNode struct {
	*BaseStatementNode
}

func (n *AssertStmtNode) Expression() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedAssertStmt_expression(n.raw, &v)
	return nil
}

func (n *AssertStmtNode) SetExpression(v ExprNode) {
	internal.ResolvedAssertStmt_set_expression(n.raw, v.getRaw())
}

func (n *AssertStmtNode) Description() string {
	var v unsafe.Pointer
	internal.ResolvedAssertStmt_description(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *AssertStmtNode) SetDescription(v string) {
	internal.ResolvedAssertStmt_set_description(n.raw, helper.StringToPtr(v))
}

// AssertRowsModifiedNode represents the ASSERT ROWS MODIFIED clause on a DML statement.
// The value must be a literal or (possibly casted) parameter int64.
//
// The statement should fail if the number of rows updated does not
// exactly match this number.
type AssertRowsModifiedNode struct {
	*BaseArgumentNode
}

func (n *AssertRowsModifiedNode) Rows() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedAssertRowsModified_rows(n.raw, &v)
	return newExprNode(v)
}

func (n *AssertRowsModifiedNode) SetRows(v ExprNode) {
	internal.ResolvedAssertRowsModified_set_rows(n.raw, v.getRaw())
}

// InsertRowNode represents one row in the VALUES clause of an INSERT.
type InsertRowNode struct {
	*BaseArgumentNode
}

func (n *InsertRowNode) ValueList() []*DMLValueNode {
	var v unsafe.Pointer
	internal.ResolvedInsertRow_value_list(n.raw, &v)
	var ret []*DMLValueNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newDMLValueNode(p))
	})
	return ret
}

func (n *InsertRowNode) SetValueList(v []*DMLValueNode) {
	internal.ResolvedInsertRow_set_value_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *InsertRowNode) AddValue(v *DMLValueNode) {
	internal.ResolvedInsertRow_add_value_list(n.raw, v.getRaw())
}

// InsertStmtNode represents an INSERT statement, or a nested INSERT inside an
// UPDATE statement.
//
// For top-level INSERT statements, <table_scan> gives the table to
// scan and creates ResolvedColumns for its columns.  Those columns can be
// referenced in <insert_column_list>.
//
// For nested INSERTS, there is no <table_scan> or <insert_column_list>.
// There is implicitly a single column to insert, and its type is the
// element type of the array being updated in the UpdateItemNode
// containing this statement.
//
// For nested INSERTs, alternate modes are not supported and <insert_mode>
// will always be set to OR_ERROR.
//
// The rows to insert come from <row_list> or the result of <query>.
// Exactly one of these must be present.
//
// If <row_list> is present, the columns in the row_list match
// positionally with <insert_column_list>.
//
// If <query> is present, <query_output_column_list> must also be present.
// <query_output_column_list> is the list of output columns produced by
// <query> that correspond positionally with the target <insert_column_list>
// on the output table.  For nested INSERTs with no <insert_column_list>,
// <query_output_column_list> must have exactly one column.
//
// <query_parameter_list> is set for nested INSERTs where <query> is set and
// references non-target values (columns or field values) from the table. It
// is only set when FEATURE_V_1_2_CORRELATED_REFS_IN_NESTED_DML is enabled.
//
// If <returning> is present, the INSERT statement will return newly inserted
// rows. <returning> can only occur on top-level statements.
//
// The returning clause has a <output_column_list> to represent the data
// sent back to clients. It can only acccess columns from the <table_scan>.
type InsertStmtNode struct {
	*BaseStatementNode
}

func (n *InsertStmtNode) TableScan() *TableScanNode {
	var v unsafe.Pointer
	internal.ResolvedInsertStmt_table_scan(n.raw, &v)
	return newTableScanNode(v)
}

func (n *InsertStmtNode) SetTableScan(v *TableScanNode) {
	internal.ResolvedInsertStmt_set_table_scan(n.raw, v.getRaw())
}

// InsertMode behavior on duplicate rows (normally defined to mean duplicate primary keys).
func (n *InsertStmtNode) InsertMode() InsertMode {
	var v int
	internal.ResolvedInsertStmt_insert_mode(n.raw, &v)
	return InsertMode(v)
}

func (n *InsertStmtNode) SetInsertMode(v InsertMode) {
	internal.ResolvedInsertStmt_set_insert_mode(n.raw, int(v))
}

func (n *InsertStmtNode) AssertRowsModified() *AssertRowsModifiedNode {
	var v unsafe.Pointer
	internal.ResolvedInsertStmt_assert_rows_modified(n.raw, &v)
	return newAssertRowsModifiedNode(v)
}

func (n *InsertStmtNode) SetAssertRowsModified(v *AssertRowsModifiedNode) {
	internal.ResolvedInsertStmt_set_assert_rows_modified(n.raw, v.getRaw())
}

func (n *InsertStmtNode) Returning() *ReturningClauseNode {
	var v unsafe.Pointer
	internal.ResolvedInsertStmt_returning(n.raw, &v)
	return newReturningClauseNode(v)
}

func (n *InsertStmtNode) SetReturning(v *ReturningClauseNode) {
	internal.ResolvedInsertStmt_set_returning(n.raw, v.getRaw())
}

func (n *InsertStmtNode) InsertColumnList() []*Column {
	var v unsafe.Pointer
	internal.ResolvedInsertStmt_insert_column_list(n.raw, &v)
	var ret []*Column
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumn(p))
	})
	return ret
}

func (n *InsertStmtNode) SetInsertColumnList(v []*Column) {
	internal.ResolvedInsertStmt_set_insert_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].raw
	}))
}

func (n *InsertStmtNode) AddInsertColumn(v *Column) {
	internal.ResolvedInsertStmt_add_insert_column_list(n.raw, v.raw)
}

func (n *InsertStmtNode) QueryParameterList() []*ColumnRefNode {
	var v unsafe.Pointer
	internal.ResolvedInsertStmt_query_parameter_list(n.raw, &v)
	var ret []*ColumnRefNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumnRefNode(p))
	})
	return ret
}

func (n *InsertStmtNode) SetQueryParameterList(v []*ColumnRefNode) {
	internal.ResolvedInsertStmt_set_query_parameter_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *InsertStmtNode) AddQueryParameter(v *ColumnRefNode) {
	internal.ResolvedInsertStmt_add_query_parameter_list(n.raw, v.getRaw())
}

func (n *InsertStmtNode) Query() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedInsertStmt_query(n.raw, &v)
	return newScanNode(v)
}

func (n *InsertStmtNode) SetQuery(v ScanNode) {
	internal.ResolvedInsertStmt_set_query(n.raw, v.getRaw())
}

func (n *InsertStmtNode) QueryOutputColumnList() []*Column {
	var v unsafe.Pointer
	internal.ResolvedInsertStmt_query_output_column_list(n.raw, &v)
	var ret []*Column
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumn(p))
	})
	return ret
}

func (n *InsertStmtNode) SetQueryOutputColumnList(v []*Column) {
	internal.ResolvedInsertStmt_set_query_output_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].raw
	}))
}

func (n *InsertStmtNode) AddQueryOutputColumn(v *Column) {
	internal.ResolvedInsertStmt_add_query_output_column_list(n.raw, v.raw)
}

func (n *InsertStmtNode) RowList() []*InsertRowNode {
	var v unsafe.Pointer
	internal.ResolvedInsertStmt_row_list(n.raw, &v)
	var ret []*InsertRowNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newInsertRowNode(p))
	})
	return ret
}

func (n *InsertStmtNode) SetRowList(v []*InsertRowNode) {
	internal.ResolvedInsertStmt_set_row_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *InsertStmtNode) AddRow(v *InsertRowNode) {
	internal.ResolvedInsertStmt_add_row_list(n.raw, v.getRaw())
}

// DeleteStmtNode represents a DELETE statement or a nested DELETE inside an
// UPDATE statement.
//
// For top-level DELETE statements, <table_scan> gives the table to
// scan and creates Columns for its columns.  Those columns can
// be referenced inside the <where_expr>.
//
// For nested DELETEs, there is no <table_scan>.  The <where_expr> can
// only reference:
//   (1) the element_column from the UpdateItemNode containing this
//       statement,
//   (2) columns from the outer statements, and
//   (3) (optionally) <array_offset_column>, which represents the 0-based
//       offset of the array element being modified.
//
// <where_expr> is required.
//
// If <returning> is present, the DELETE statement will return deleted rows
// back. It can only occur on top-level statements.
//
// This returning clause has a <output_column_list> to represent the data
// sent back to clients. It can only acccess columns from the <table_scan>.
type DeleteStmtNode struct {
	*BaseStatementNode
}

func (n *DeleteStmtNode) TableScan() *TableScanNode {
	var v unsafe.Pointer
	internal.ResolvedDeleteStmt_table_scan(n.raw, &v)
	return newTableScanNode(v)
}

func (n *DeleteStmtNode) SetTableScan(v *TableScanNode) {
	internal.ResolvedDeleteStmt_set_table_scan(n.raw, v.getRaw())
}

func (n *DeleteStmtNode) AssertRowsModified() *AssertRowsModifiedNode {
	var v unsafe.Pointer
	internal.ResolvedDeleteStmt_assert_rows_modified(n.raw, &v)
	return newAssertRowsModifiedNode(v)
}

func (n *DeleteStmtNode) SetAssertRowsModified(v *AssertRowsModifiedNode) {
	internal.ResolvedDeleteStmt_set_assert_rows_modified(n.raw, v.getRaw())
}

func (n *DeleteStmtNode) Returning() *ReturningClauseNode {
	var v unsafe.Pointer
	internal.ResolvedDeleteStmt_returning(n.raw, &v)
	return newReturningClauseNode(v)
}

func (n *DeleteStmtNode) SetReturning(v *ReturningClauseNode) {
	internal.ResolvedDeleteStmt_set_returning(n.raw, v.getRaw())
}

func (n *DeleteStmtNode) ArrayOffsetColumn() *ColumnHolderNode {
	var v unsafe.Pointer
	internal.ResolvedDeleteStmt_array_offset_column(n.raw, &v)
	return newColumnHolderNode(v)
}

func (n *DeleteStmtNode) SetArrayOffsetColumn(v *ColumnHolderNode) {
	internal.ResolvedDeleteStmt_set_array_offset_column(n.raw, v.getRaw())
}

func (n *DeleteStmtNode) WhereExpr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedDeleteStmt_where_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *DeleteStmtNode) SetWhereExpr(v ExprNode) {
	internal.ResolvedDeleteStmt_set_where_expr(n.raw, v.getRaw())
}

// UpdateItemNode represents one item inside the SET clause of an UPDATE.
//
// The entity being updated is specified by <target>.
//
// For a regular
//   SET {target} = {expression} | DEFAULT
// clause (not including an array element update like SET a[OFFSET(0)] = 5),
// <target> and <set_value> will be present, and all other fields will be
// unset.
//
// For an array element update (e.g. SET a.b[<expr>].c = <value>),
//   - <target> is set to the array,
//   - <element_column> is a new Column that can be used inside the
//     update items to refer to the array element.
//   - <array_update_list> will have a node corresponding to the offset into
//     that array and the modification to that array element.
// For example, for SET a.b[<expr>].c = <value>, we have
//    UpdateItemNode
//    +-<target> = a.b
//    +-<element_column> = <x>
//    +-<array_update_list>
//      +-UpdateArrayItemNode
//        +-<offset> = <expr>
//        +-<update_item> = UpdateItemNode
//          +-<target> = <x>.c
//          +-<set_value> = <value>
//
// The engine is required to fail the update if there are two elements of
// <array_update_list> corresponding to offset expressions that evaluate to
// the same value. These are considered to be conflicting updates.
//
// Multiple updates to the same array are always represented as multiple
// elements of <array_update_list> under a single UpdateItemNode
// corresponding to that array. <array_update_list> will only have one
// element for modifications to an array-valued subfield of an array element.
// E.g., for SET a[<expr1>].b[<expr2>] = 5, a[<expr3>].b[<expr4>] = 6, we
// will have:
//     UpdateItemNode
//     +-<target> = a
//     +-<element_column> = x
//     +-<array_update_list>
//       +-UpdateArrayItemNode
//         +-<offset> = <expr1>
//         +-UpdateItemNode for <x>.b[<expr2>] = 5
//       +-UpdateArrayItemNode
//         +-<offset> = <expr3>
//         +-UpdateItemNode for <x>.b[<expr4>] = 6
// The engine must give a runtime error if <expr1> and <expr3> evaluate to
// the same thing. Notably, it does not have to understand that the
// two UpdateItemNodes corresponding to "b" refer to the same array iff
// <expr1> and <expr3> evaluate to the same thing.
//
// TODO: Consider allowing the engine to execute an update like
// SET a[<expr1>].b = 1, a[<expr2>].c = 2 even if <expr1> == <expr2> since
// "b" and "c" do not overlap. Also consider allowing a more complex example
// like SET a[<expr1>].b[<expr2>] = ...,
// a[<expr3>].b[<expr4>].c[<expr5>] = ... even if <expr1> == <expr3>, as long
// as <expr2> != <expr4> in that case.
//
// For nested DML, <target> and <element_column> will both be set, and one or
// more of the nested statement lists will be non-empty. <target> must have
// ARRAY type, and <element_column> introduces a Column representing
// elements of that array. The nested statement lists will always be empty in
// a UpdateItemNode child of a UpdateArrayItemNode.
type UpdateItemNode struct {
	*BaseArgumentNode
}

// Target the target entity to be updated.
//
// This is an expression evaluated using the Columns visible
// inside this statement.  This expression can contain only
// ColumnRefNodes, GetProtoFieldNode and GetStructFieldNodes.
//
// In a top-level UPDATE, the expression always starts with a
// ColumnRefNode referencing a column from the statement's
// TableScan.
//
// In a nested UPDATE, the expression always starts with a
// ColumnRefNode referencing the element_column from the
// UpdateItemNode containing this scan.
//
// This node is also used to represent a modification of a single
// array element (when it occurs as a child of a
// UpdateArrayItemNode).  In that case, the expression
// starts with a ColumnRefNode referencing the <element_column>
// from its grandparent UpdateItemNode. (E.g., for "SET a[<expr>]
// = 5", the grandparent UpdateItemNode has <target> "a", the
// parent UpdateArrayItemNode has offset <expr>, and this node
// has <set_value> 5 and target corresponding to the grandparent's
// <element_column> field.)
//
// For either a nested UPDATE or an array modification, there may be
// a path of field accesses after the initial ColumnRefNode,
// represented by a chain of GetField nodes.
//
// NOTE: We use the same GetField nodes as we do for queries, but
// they are not treated the same.  Here, they express a path inside
// an object that is being mutated, so they have reference semantics.
func (n *UpdateItemNode) Target() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateItem_target(n.raw, &v)
	return newExprNode(v)
}

func (n *UpdateItemNode) SetTarget(v ExprNode) {
	internal.ResolvedUpdateItem_set_target(n.raw, v.getRaw())
}

// SetValue set the target entity to this value.  The types must match.
// This can contain the same columns that can appear in the
// <where_expr> of the enclosing UpdateStmtNode.
//
// This is mutually exclusive with all fields below, which are used
// for nested updates only.
func (n *UpdateItemNode) SetValue() *DMLValueNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateItem_set_value(n.raw, &v)
	return newDMLValueNode(v)
}

func (n *UpdateItemNode) SetSetValue(v *DMLValueNode) {
	internal.ResolvedUpdateItem_set_set_value(n.raw, v.getRaw())
}

// ElementColumn the Column introduced to represent the elements of the
// array being updated.  This works similarly to
// ArrayScan.ElementColumn().
//
// <target> must have array type, and this column has the array's
// element type.
//
// This column can be referenced inside the nested statements below.
func (n *UpdateItemNode) ElementColumn() *ColumnHolderNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateItem_element_column(n.raw, &v)
	return newColumnHolderNode(v)
}

func (n *UpdateItemNode) SetElementColumn(v *ColumnHolderNode) {
	internal.ResolvedUpdateItem_set_element_column(n.raw, v.getRaw())
}

// ArrayUpdateList array element modifications to apply. Each item runs on the value
// of <element_column> specified by UpdateArrayItemNode.offset.
// This field is always empty if the analyzer option
// FEATURE_V_1_2_ARRAY_ELEMENTS_WITH_SET is disabled.
//
// The engine must fail if two elements in this list have offset
// expressions that evaluate to the same value.
// TODO: Consider generalizing this to allow
// SET a[<expr1>].b = ..., a[<expr2>].c = ...
func (n *UpdateItemNode) ArrayUpdateList() []*UpdateArrayItemNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateItem_array_update_list(n.raw, &v)
	var ret []*UpdateArrayItemNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newUpdateArrayItemNode(p))
	})
	return ret
}

func (n *UpdateItemNode) SetArrayUpdateList(v []*UpdateArrayItemNode) {
	internal.ResolvedUpdateItem_set_array_update_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *UpdateItemNode) AddArrayUpdate(v *UpdateArrayItemNode) {
	internal.ResolvedUpdateItem_add_array_update_list(n.raw, v.getRaw())
}

// DeleteList nested DELETE statements to apply.  Each delete runs on one value
// of <element_column> and may choose to delete that array element.
//
// DELETEs are applied before INSERTs or UPDATEs.
//
// It is legal for the same input element to match multiple DELETEs.
func (n *UpdateItemNode) DeleteList() []*DeleteStmtNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateItem_delete_list(n.raw, &v)
	var ret []*DeleteStmtNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newDeleteStmtNode(p))
	})
	return ret
}

func (n *UpdateItemNode) SetDeleteList(v []*DeleteStmtNode) {
	internal.ResolvedUpdateItem_set_delete_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *UpdateItemNode) AddDelete(v *DeleteStmtNode) {
	internal.ResolvedUpdateItem_add_delete_list(n.raw, v.getRaw())
}

// UpdateList nested UPDATE statements to apply.  Each update runs on one value
// of <element_column> and may choose to update that array element.
//
// UPDATEs are applied after DELETEs and before INSERTs.
//
// It is an error if any element is matched by multiple UPDATEs.
func (n *UpdateItemNode) UpdateList() []*UpdateStmtNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateItem_update_list(n.raw, &v)
	var ret []*UpdateStmtNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newUpdateStmtNode(p))
	})
	return ret
}

func (n *UpdateItemNode) SetUpdateList(v []*UpdateStmtNode) {
	internal.ResolvedUpdateItem_set_update_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *UpdateItemNode) AddUpdate(v *UpdateStmtNode) {
	internal.ResolvedUpdateItem_add_update_list(n.raw, v.getRaw())
}

// InsertList nested INSERT statements to apply.  Each insert will produce zero
// or more values for <element_column>.
//
// INSERTs are applied after DELETEs and UPDATEs.
//
// For nested UPDATEs, insert_mode will always be the default, and has no effect.
func (n *UpdateItemNode) InsertList() []*InsertStmtNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateItem_insert_list(n.raw, &v)
	var ret []*InsertStmtNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newInsertStmtNode(p))
	})
	return ret
}

func (n *UpdateItemNode) SetInsertList(v []*InsertStmtNode) {
	internal.ResolvedUpdateItem_set_insert_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *UpdateItemNode) AddInsert(v *InsertStmtNode) {
	internal.ResolvedUpdateItem_add_insert_list(n.raw, v.getRaw())
}

// UpdateArrayItemNode for an array element modification, this node represents the offset
// expression and the modification, but not the array. E.g., for
// SET a[<expr>] = 5, this node represents a modification of "= 5" to offset
// <expr> of the array defined by the parent node.
type UpdateArrayItemNode struct {
	*BaseArgumentNode
}

// Offset the array offset to be modified.
func (n *UpdateArrayItemNode) Offset() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateArrayItem_offset(n.raw, &v)
	return newExprNode(v)
}

func (n *UpdateArrayItemNode) SetOffset(v ExprNode) {
	internal.ResolvedUpdateArrayItem_set_offset(n.raw, v.getRaw())
}

// UpdateItem the modification to perform to the array element.
func (n *UpdateArrayItemNode) UpdateItem() *UpdateItemNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateArrayItem_update_item(n.raw, &v)
	return newUpdateItemNode(v)
}

func (n *UpdateArrayItemNode) SetUpdateItem(v *UpdateItemNode) {
	internal.ResolvedUpdateArrayItem_set_update_item(n.raw, v.getRaw())
}

// UpdateStmtNode represents an UPDATE statement, or a nested UPDATE inside an
// UPDATE statement.
//
// For top-level UPDATE statements, <table_scan> gives the table to
// scan and creates Columns for its columns.  Those columns can be
// referenced in the <update_item_list>. The top-level UPDATE statement may
// also have <from_scan>, the output of which is joined with
// the <table_scan> using expressions in the <where_expr>. The columns
// exposed in the <from_scan> are visible in the right side of the
// expressions in the <update_item_list> and in the <where_expr>.
// <array_offset_column> is never set for top-level UPDATE statements.
//
// Top-level UPDATE statements will also have <column_access_list> populated.
// For each column, this vector indicates if the column was read and/or
// written. The columns in this vector match those of
// <table_scan.column_list>. If a column was not encountered when producing
// the resolved AST, then the value at that index will be Statement::NONE.
//
// For nested UPDATEs, there is no <table_scan>.  The <where_expr> can
// only reference:
//   (1) the element_column from the UpdateItemNode containing this statement,
//   (2) columns from the outer statements, and
//   (3) (optionally) <array_offset_column>, which represents the 0-based
//       offset of the array element being modified.
// The left hand sides of the expressions in <update_item_list> can only
// reference (1). The right hand sides of those expressions can reference
// (1), (2), and (3).
//
// The updates in <update_item_list> will be non-overlapping.
// If there are multiple nested statements updating the same entity,
// they will be combined into one UpdateItemNode.
//
// If <returning> is present, the UPDATE statement will return updated rows.
// <returning> can only occur on top-level statements.
//
// This returning clause has a <output_column_list> to represent the data
// sent back to clients. It can only access columns from the <table_scan>.
// The columns in <from_scan> are not allowed.
// TODO: allow columns in <from_scan> to be referenced.
type UpdateStmtNode struct {
	*BaseStatementNode
}

func (n *UpdateStmtNode) TableScan() *TableScanNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateStmt_table_scan(n.raw, &v)
	return newTableScanNode(v)
}

func (n *UpdateStmtNode) SetTableScan(v *TableScanNode) {
	internal.ResolvedUpdateStmt_set_table_scan(n.raw, v.getRaw())
}

func (n *UpdateStmtNode) ColumnAccessList() []ObjectAccess {
	var v unsafe.Pointer
	internal.ResolvedUpdateStmt_column_access_list(n.raw, &v)
	var ret []ObjectAccess
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, ObjectAccess(uintptr(p)))
	})
	return ret
}

func (n *UpdateStmtNode) SetColumnAccessList(v []ObjectAccess) {
	internal.ResolvedUpdateStmt_set_column_access_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return unsafe.Pointer(uintptr(v[i]))
	}))
}

func (n *UpdateStmtNode) AddColumnAccess(v ObjectAccess) {
	internal.ResolvedUpdateStmt_add_column_access_list(n.raw, int(v))
}

func (n *UpdateStmtNode) AssertRowsModified() *AssertRowsModifiedNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateStmt_assert_rows_modified(n.raw, &v)
	return newAssertRowsModifiedNode(v)
}

func (n *UpdateStmtNode) SetAssertRowsModified(v *AssertRowsModifiedNode) {
	internal.ResolvedUpdateStmt_set_assert_rows_modified(n.raw, v.getRaw())
}

func (n *UpdateStmtNode) Returning() *ReturningClauseNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateStmt_returning(n.raw, &v)
	return newReturningClauseNode(v)
}

func (n *UpdateStmtNode) SetReturning(v *ReturningClauseNode) {
	internal.ResolvedUpdateStmt_set_returning(n.raw, v.getRaw())
}

func (n *UpdateStmtNode) ArrayOffsetColumn() *ColumnHolderNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateStmt_array_offset_column(n.raw, &v)
	return newColumnHolderNode(v)
}

func (n *UpdateStmtNode) SetArrayOffsetColumn(v *ColumnHolderNode) {
	internal.ResolvedUpdateStmt_set_array_offset_column(n.raw, v.getRaw())
}

func (n *UpdateStmtNode) WhereExpr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateStmt_where_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *UpdateStmtNode) SetWhereExpr(v ExprNode) {
	internal.ResolvedUpdateStmt_set_where_expr(n.raw, v.getRaw())
}

func (n *UpdateStmtNode) UpdateItemList() []*UpdateItemNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateStmt_update_item_list(n.raw, &v)
	var ret []*UpdateItemNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newUpdateItemNode(p))
	})
	return ret
}

func (n *UpdateStmtNode) SetUpdateItemList(v []*UpdateItemNode) {
	internal.ResolvedUpdateStmt_set_update_item_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *UpdateStmtNode) AddUpdateItemList(v *UpdateItemNode) {
	internal.ResolvedUpdateStmt_add_update_item_list(n.raw, v.getRaw())
}

func (n *UpdateStmtNode) FromScan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedUpdateStmt_from_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *UpdateStmtNode) SetFromScan(v ScanNode) {
	internal.ResolvedUpdateStmt_set_from_scan(n.raw, v.getRaw())
}

// MergeWhenNode this is used by MergeStmtNode to represent one WHEN ... THEN clause
// within MERGE statement.
//
// There are three types of clauses, which are MATCHED, NOT_MATCHED_BY_SOURCE
// and NOT_MATCHED_BY_TARGET. The <match_type> must have one of these values.
//
// The <match_expr> defines an optional expression to apply to the join
// result of <table_scan> and <from_scan> of the parent MergeStmtNode.
//
// Each MergeWhenNode must define exactly one of three operations,
//   -- INSERT: <action_type> is MergeWhenNode::INSERT.
//              Both <insert_column_list> and <insert_row> are non-empty.
//              The size of <insert_column_list> must be the same with the
//              value_list size of <insert_row>, and, the column data type
//              must match.
//   -- UPDATE: <action_type> is MergeWhenNode::UPDATE.
//              <update_item_list> is non-empty.
//   -- DELETE: <action_type> is MergeWhenNode::DELETE.
// The INSERT, UPDATE and DELETE operations are mutually exclusive.
//
// When <match_type> is MATCHED, <action_type> must be UPDATE or DELETE.
// When <match_type> is NOT_MATCHED_BY_TARGET, <action_type> must be INSERT.
// When <match_type> is NOT_MATCHED_BY_SOURCE, <action_type> must be UPDATE
// or DELETE.
//
// The column visibility within a ResolvedMergeWhen clause is defined as
// following,
//   -- When <match_type> is MATCHED,
//      -- All columns from <table_scan> and <from_scan> are allowed in
//         <match_expr>.
//      -- If <action_type> is UPDATE, only columns from <table_scan> are
//         allowed on left side of expressions in <update_item_list>.
//         All columns from <table_scan> and <from_scan> are allowed on right
//         side of expressions in <update_item_list>.
//   -- When <match_type> is NOT_MATCHED_BY_TARGET,
//      -- Only columns from <from_scan> are allowed in <match_expr>.
//      -- Only columns from <table_scan> are allowed in
//         <insert_column_list>.
//      -- Only columns from <from_scan> are allowed in <insert_row>.
//   -- When <match_type> is NOT_MATCHED_BY_SOURCE,
//      -- Only columns from <table_scan> are allowed in <match_expr>.
//      -- If <action_type> is UPDATE, only columns from <table_scan> are
//         allowed in <update_item_list>.
type MergeWhenNode struct {
	*BaseArgumentNode
}

func (n *MergeWhenNode) MatchType() MatchType {
	var v int
	internal.ResolvedMergeWhen_match_type(n.raw, &v)
	return MatchType(v)
}

func (n *MergeWhenNode) SetMatchType(v MatchType) {
	internal.ResolvedMergeWhen_set_match_type(n.raw, int(v))
}

func (n *MergeWhenNode) MatchExpr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedMergeWhen_match_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *MergeWhenNode) SetMatchExpr(v ExprNode) {
	internal.ResolvedMergeWhen_set_match_expr(n.raw, v.getRaw())
}

func (n *MergeWhenNode) ActionType() ActionType {
	var v int
	internal.ResolvedMergeWhen_action_type(n.raw, &v)
	return ActionType(v)
}

func (n *MergeWhenNode) SetActionType(v ActionType) {
	internal.ResolvedMergeWhen_set_action_type(n.raw, int(v))
}

func (n *MergeWhenNode) InsertColumnList() []*Column {
	var v unsafe.Pointer
	internal.ResolvedMergeWhen_insert_column_list(n.raw, &v)
	var ret []*Column
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumn(p))
	})
	return ret
}

func (n *MergeWhenNode) SetInsertColumnList(v []*Column) {
	internal.ResolvedMergeWhen_set_insert_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].raw
	}))
}

func (n *MergeWhenNode) AddInsertColumn(v *Column) {
	internal.ResolvedMergeWhen_add_insert_column_list(n.raw, v.raw)
}

func (n *MergeWhenNode) InsertRow() *InsertRowNode {
	var v unsafe.Pointer
	internal.ResolvedMergeWhen_insert_row(n.raw, &v)
	return newInsertRowNode(v)
}

func (n *MergeWhenNode) SetInsertRow(v *InsertRowNode) {
	internal.ResolvedMergeWhen_set_insert_row(n.raw, v.getRaw())
}

func (n *MergeWhenNode) UpdateItemList() []*UpdateItemNode {
	var v unsafe.Pointer
	internal.ResolvedMergeWhen_update_item_list(n.raw, &v)
	var ret []*UpdateItemNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newUpdateItemNode(p))
	})
	return ret
}

func (n *MergeWhenNode) SetUpdateItemList(v []*UpdateItemNode) {
	internal.ResolvedMergeWhen_set_update_item_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *MergeWhenNode) AddUpdateItem(v *UpdateItemNode) {
	internal.ResolvedMergeWhen_add_update_item_list(n.raw, v.getRaw())
}

// MergeStmtNode represents a MERGE statement.
//
// <table_scan> gives the target table to scan and creates Columns
// for its columns.
//
// <column_access_list> indicates for each column, whether it was read and/or
// written. The columns in this vector match those of
// <table_scan.column_list>. If a column was not encountered when producing
// the resolved AST, then the value at that index will be
// Statement::NONE(0).
//
// The output of <from_scan> is joined with <table_scan> using the join
// expression <merge_expr>.
//
// The order of elements in <when_clause_list> matters, as they are executed
// sequentially. At most one of the <when_clause_list> clause will be applied
// to each row from <table_scan>.
//
// <table_scan>, <from_scan>, <merge_expr> and <when_clause_list> are
// required. <when_clause_list> must be non-empty.
type MergeStmtNode struct {
	*BaseStatementNode
}

func (n *MergeStmtNode) TableScan() *TableScanNode {
	var v unsafe.Pointer
	internal.ResolvedMergeStmt_table_scan(n.raw, &v)
	return newTableScanNode(v)
}

func (n *MergeStmtNode) SetTableScan(v *TableScanNode) {
	internal.ResolvedMergeStmt_set_table_scan(n.raw, v.getRaw())
}

func (n *MergeStmtNode) ColumnAccessList() []ObjectAccess {
	var v unsafe.Pointer
	internal.ResolvedMergeStmt_column_access_list(n.raw, &v)
	var ret []ObjectAccess
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, ObjectAccess(uintptr(p)))
	})
	return ret
}

func (n *MergeStmtNode) SetColumnAccessList(v []ObjectAccess) {
	internal.ResolvedMergeStmt_set_column_access_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return unsafe.Pointer(uintptr(v[i]))
	}))
}

func (n *MergeStmtNode) AddColumnAccess(v ObjectAccess) {
	internal.ResolvedMergeStmt_add_column_access_list(n.raw, int(v))
}

func (n *MergeStmtNode) FromScan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedMergeStmt_from_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *MergeStmtNode) SetFromScan(v ScanNode) {
	internal.ResolvedMergeStmt_set_from_scan(n.raw, v.getRaw())
}

func (n *MergeStmtNode) MergeExpr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedMergeStmt_merge_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *MergeStmtNode) SetMergeExpr(v ExprNode) {
	internal.ResolvedMergeStmt_set_merge_expr(n.raw, v.getRaw())
}

func (n *MergeStmtNode) WhenClauseList() []*MergeWhenNode {
	var v unsafe.Pointer
	internal.ResolvedMergeStmt_when_clause_list(n.raw, &v)
	var ret []*MergeWhenNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newMergeWhenNode(p))
	})
	return ret
}

func (n *MergeStmtNode) SetWhenClauseList(v []*MergeWhenNode) {
	internal.ResolvedMergeStmt_set_when_clause_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *MergeStmtNode) AddWhenClause(v *MergeWhenNode) {
	internal.ResolvedMergeStmt_add_when_clause_list(n.raw, v.getRaw())
}

// TruncateStmtNode represents a TRUNCATE TABLE statement.
//
// Statement:
//   TRUNCATE TABLE <table_name> [WHERE <boolean_expression>]
//
// <table_scan> is a TableScan for the target table, which is used during
//              resolving and validation. Consumers can use either the table
//              object inside it or name_path to reference the table.
// <where_expr> boolean expression that can reference columns in
//              ResolvedColumns (which the TableScan creates); the
//              <where_expr> should always correspond to entire partitions,
//              and is optional.
type TruncateStmtNode struct {
	*BaseStatementNode
}

func (n *TruncateStmtNode) TableScan() *TableScanNode {
	var v unsafe.Pointer
	internal.ResolvedTruncateStmt_table_scan(n.raw, &v)
	return newTableScanNode(v)
}

func (n *TruncateStmtNode) SetTableScan(v *TableScanNode) {
	internal.ResolvedTruncateStmt_set_table_scan(n.raw, v.getRaw())
}

func (n *TruncateStmtNode) WhereExpr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedTruncateStmt_where_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *TruncateStmtNode) SetWhereExpr(v ExprNode) {
	internal.ResolvedTruncateStmt_set_where_expr(n.raw, v.getRaw())
}

// ObjectUnitNode a reference to a unit of an object (e.g. a column or field of a table).
//
// <name_path> is a vector giving the identifier path of the object unit.
type ObjectUnitNode struct {
	*BaseArgumentNode
}

func (n *ObjectUnitNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedObjectUnit_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *ObjectUnitNode) SetNamePath(v []string) {
	internal.ResolvedObjectUnit_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *ObjectUnitNode) AddNamePath(v string) {
	internal.ResolvedObjectUnit_add_name_path(n.raw, helper.StringToPtr(v))
}

// PrivilegeNode a grantable privilege.
//
// <action_type> is the type of privilege action, e.g. SELECT, INSERT, UPDATE or DELETE.
// <unit_list> is an optional list of units of the object (e.g. columns of a
// table, fields in a value table) that the privilege is scoped to. The
// privilege is on the whole object if the list is empty.
type PrivilegeNode struct {
	*BaseArgumentNode
}

func (n *PrivilegeNode) ActionType() string {
	var v unsafe.Pointer
	internal.ResolvedPrivilege_action_type(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *PrivilegeNode) SetActionType(v string) {
	internal.ResolvedPrivilege_set_action_type(n.raw, helper.StringToPtr(v))
}

func (n *PrivilegeNode) UnitList() []*ObjectUnitNode {
	var v unsafe.Pointer
	internal.ResolvedPrivilege_unit_list(n.raw, &v)
	var ret []*ObjectUnitNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newObjectUnitNode(p))
	})
	return ret
}

func (n *PrivilegeNode) SetUnitList(v []*ObjectUnitNode) {
	internal.ResolvedPrivilege_set_unit_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *PrivilegeNode) AddUnit(v *ObjectUnitNode) {
	internal.ResolvedPrivilege_add_unit_list(n.raw, v.getRaw())
}

// GrantOrRevokeStmtNode common node of GRANT/REVOKE statements.
//
// <privilege_list> is the list of privileges to be granted/revoked. ALL
// PRIVILEGES should be granted/fromed if it is empty.
// <object_type> is an optional string identifier, e.g., TABLE, VIEW.
// <name_path> is a vector of segments of the object identifier's pathname.
// <grantee_list> (DEPRECATED) is the list of grantees (strings).
// <grantee_expr_list> is the list of grantees, and may include parameters.
//
// Only one of <grantee_list> or <grantee_expr_list> will be populated,
// depending on whether or not the FEATURE_PARAMETERS_IN_GRANTEE_LIST
// is enabled.  The <grantee_list> is deprecated, and will be removed
// along with the corresponding FEATURE once all engines have migrated to
// use the <grantee_expr_list>.  Once <grantee_expr_list> is the only
// one, then it should be marked as NOT_IGNORABLE.
type GrantOrRevokeStmtNode struct {
	*BaseStatementNode
}

func (n *GrantOrRevokeStmtNode) PrivilegeList() []*PrivilegeNode {
	var v unsafe.Pointer
	internal.ResolvedGrantOrRevokeStmt_privilege_list(n.raw, &v)
	var ret []*PrivilegeNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newPrivilegeNode(p))
	})
	return ret
}

func (n *GrantOrRevokeStmtNode) SetPrivilegeList(v []*PrivilegeNode) {
	internal.ResolvedGrantOrRevokeStmt_set_privilege_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *GrantOrRevokeStmtNode) AddPrivilege(v *PrivilegeNode) {
	internal.ResolvedGrantOrRevokeStmt_add_privilege_list(n.raw, v.getRaw())
}

func (n *GrantOrRevokeStmtNode) ObjectType() string {
	var v unsafe.Pointer
	internal.ResolvedGrantOrRevokeStmt_object_type(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *GrantOrRevokeStmtNode) SetObjectType(v string) {
	internal.ResolvedGrantOrRevokeStmt_set_object_type(n.raw, helper.StringToPtr(v))
}

func (n *GrantOrRevokeStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedGrantOrRevokeStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *GrantOrRevokeStmtNode) SetNamePath(v []string) {
	internal.ResolvedGrantOrRevokeStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *GrantOrRevokeStmtNode) AddNamePath(v string) {
	internal.ResolvedGrantOrRevokeStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

func (n *GrantOrRevokeStmtNode) GranteeList() []string {
	var v unsafe.Pointer
	internal.ResolvedGrantOrRevokeStmt_grantee_list(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *GrantOrRevokeStmtNode) SetGranteeList(v []string) {
	internal.ResolvedGrantOrRevokeStmt_set_grantee_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *GrantOrRevokeStmtNode) AddGrantee(v string) {
	internal.ResolvedGrantOrRevokeStmt_add_grantee_list(n.raw, helper.StringToPtr(v))
}

func (n *GrantOrRevokeStmtNode) GranteeExprList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedGrantOrRevokeStmt_grantee_expr_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *GrantOrRevokeStmtNode) SetGranteeExprList(v []ExprNode) {
	internal.ResolvedGrantOrRevokeStmt_set_grantee_expr_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *GrantOrRevokeStmtNode) AddGranteeExpr(v ExprNode) {
	internal.ResolvedGrantOrRevokeStmt_add_grantee_expr_list(n.raw, v.getRaw())
}

// GrantStmtNode a GRANT statement.
// It represents the action to grant a list of privileges
// on a specific object to/from list of grantees.
type GrantStmtNode struct {
	*GrantOrRevokeStmtNode
}

// RevokeStmtNode a REVOKE statement.
// It represents the action to revoke a list of
// privileges on a specific object to/from list of grantees.
type RevokeStmtNode struct {
	*GrantOrRevokeStmtNode
}

// AlterObjectStmtNode common node for statements:
//   ALTER <object> [IF EXISTS] <name_path> <alter_action_list>
//
// <name_path> is a vector giving the identifier path in the table <name>. It
//             is optional if
//             FEATURE_ALLOW_MISSING_PATH_EXPRESSION_IN_ALTER_DDL is enabled.
// <alter_action_list> is a vector of actions to be done to the object.
// <is_if_exists> silently ignores the "name_path does not exist" error.
type AlterObjectStmtNode struct {
	*BaseStatementNode
}

func (n *AlterObjectStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedAlterObjectStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *AlterObjectStmtNode) SetNamePath(v []string) {
	internal.ResolvedAlterObjectStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *AlterObjectStmtNode) AddNamePath(v string) {
	internal.ResolvedAlterObjectStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

func (n *AlterObjectStmtNode) AlterActionList() []AlterActionNode {
	var v unsafe.Pointer
	internal.ResolvedAlterObjectStmt_alter_action_list(n.raw, &v)
	var ret []AlterActionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newAlterActionNode(p))
	})
	return ret
}

func (n *AlterObjectStmtNode) SetAlterActionList(v []AlterActionNode) {
	internal.ResolvedAlterObjectStmt_set_alter_action_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AlterObjectStmtNode) AddAlterAction(v AlterActionNode) {
	internal.ResolvedAlterObjectStmt_add_alter_action_list(n.raw, v.getRaw())
}

func (n *AlterObjectStmtNode) IsIfExists() bool {
	var v bool
	internal.ResolvedAlterObjectStmt_is_if_exists(n.raw, &v)
	return v
}

func (n *AlterObjectStmtNode) SetIsIfExists(v bool) {
	internal.ResolvedAlterObjectStmt_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

// AlterDatabaseStmtNode this statement:
//   ALTER DATABASE [IF EXISTS] <name_path> <alter_action_list>
//
// This statement could be used to change the database level options.
type AlterDatabaseStmtNode struct {
	*AlterObjectStmtNode
}

// AlterMaterializedViewStmtNode this statement:
// ALTER MATERIALIZED VIEW [IF EXISTS] <name_path> <alter_action_list>.
type AlterMaterializedViewStmtNode struct {
	*AlterObjectStmtNode
}

// AlterSchemaStmtNode this statement:
// ALTER SCHEMA [IF NOT EXISTS] <name_path> <alter_action_list>.
type AlterSchemaStmtNode struct {
	*AlterObjectStmtNode
}

// AlterTableStmtNode this statement:
// ALTER TABLE [IF EXISTS] <name_path> <alter_action_list>.
type AlterTableStmtNode struct {
	*AlterObjectStmtNode
}

// AlterViewStmtNode this statement:
// ALTER VIEW [IF EXISTS] <name_path> <alter_action_list>.
type AlterViewStmtNode struct {
	*AlterObjectStmtNode
}

// AlterActionNode a common node for all actions in statement ALTER <object>.
type AlterActionNode interface {
	ArgumentNode
}

type BaseAlterActionNode struct {
	*BaseArgumentNode
}

// AlterColumnActionNode a abstract node for all ALTER COLUMN actions in the ALTER TABLE statement:
//   ALTER TABLE <table_name> ALTER COLUMN [IF EXISTS] <column>
//
// <is_if_exists> silently ignores the "column does not exist" error.
// <column> is the name of the column.
type AlterColumnActionNode interface {
	AlterActionNode
	IsIfExists() bool
	SetIsIfExists(bool)
	Column() string
	SetColumn(string)
}

type BaseAlterColumnActionNode struct {
	*BaseAlterActionNode
}

func (n *BaseAlterColumnActionNode) IsIfExists() bool {
	var v bool
	internal.ResolvedAlterColumnAction_is_if_exists(n.raw, &v)
	return v
}

func (n *BaseAlterColumnActionNode) SetIsIfExists(v bool) {
	internal.ResolvedAlterColumnAction_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

func (n *BaseAlterColumnActionNode) Column() string {
	var v unsafe.Pointer
	internal.ResolvedAlterColumnAction_column(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *BaseAlterColumnActionNode) SetColumn(v string) {
	internal.ResolvedAlterColumnAction_set_column(n.raw, helper.StringToPtr(v))
}

// SetOptionsActionNode
// SET OPTIONS action for ALTER <object> statement
//
// <option_list> has engine-specific directives that specify how to
//               alter the metadata for this object.
type SetOptionsActionNode struct {
	*BaseAlterActionNode
}

func (n *SetOptionsActionNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedSetOptionsAction_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *SetOptionsActionNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedSetOptionsAction_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *SetOptionsActionNode) AddOption(v *OptionNode) {
	internal.ResolvedSetOptionsAction_add_option_list(n.raw, v.getRaw())
}

// AddColumnActionNode
// ADD COLUMN action for ALTER TABLE statement.
type AddColumnActionNode struct {
	*BaseAlterActionNode
}

func (n *AddColumnActionNode) IsIfNotExists() bool {
	var v bool
	internal.ResolvedAddColumnAction_is_if_not_exists(n.raw, &v)
	return v
}

func (n *AddColumnActionNode) SetIsIfNotExists(v bool) {
	internal.ResolvedAddColumnAction_set_is_if_not_exists(n.raw, helper.BoolToInt(v))
}

func (n *AddColumnActionNode) ColumnDefinition() *ColumnDefinitionNode {
	var v unsafe.Pointer
	internal.ResolvedAddColumnAction_column_definition(n.raw, &v)
	return newColumnDefinitionNode(v)
}

func (n *AddColumnActionNode) SetColumnDefinition(v *ColumnDefinitionNode) {
	internal.ResolvedAddColumnAction_set_column_definition(n.raw, v.getRaw())
}

// AddConstraintActionNode
// ADD CONSTRAINT for ALTER TABLE statement.
type AddConstraintActionNode struct {
	*BaseAlterActionNode
}

func (n *AddConstraintActionNode) IsIfNotExists() bool {
	var v bool
	internal.ResolvedAddConstraintAction_is_if_not_exists(n.raw, &v)
	return v
}

func (n *AddConstraintActionNode) SetIsIfNotExists(v bool) {
	internal.ResolvedAddConstraintAction_set_is_if_not_exists(n.raw, helper.BoolToInt(v))
}

func (n *AddConstraintActionNode) Constraint() ConstraintNode {
	var v unsafe.Pointer
	internal.ResolvedAddConstraintAction_constraint(n.raw, &v)
	return newConstraintNode(v)
}

func (n *AddConstraintActionNode) SetConstraint(v ConstraintNode) {
	internal.ResolvedAddConstraintAction_set_constraint(n.raw, v.getRaw())
}

func (n *AddConstraintActionNode) Table() types.Table {
	var v unsafe.Pointer
	internal.ResolvedAddConstraintAction_table(n.raw, &v)
	return newTable(v)
}

func (n *AddConstraintActionNode) SetTable(v types.Table) {
	internal.ResolvedAddConstraintAction_set_table(n.raw, getRawTable(v))
}

// DropConstraintActionNode
// DROP CONSTRAINT for ALTER TABLE statement.
type DropConstraintActionNode struct {
	*BaseAlterActionNode
}

func (n *DropConstraintActionNode) IsIfExists() bool {
	var v bool
	internal.ResolvedDropConstraintAction_is_if_exists(n.raw, &v)
	return v
}

func (n *DropConstraintActionNode) SetIsIfExists(v bool) {
	internal.ResolvedDropConstraintAction_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

func (n *DropConstraintActionNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedDropConstraintAction_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *DropConstraintActionNode) SetName(v string) {
	internal.ResolvedDropConstraintAction_set_name(n.raw, helper.StringToPtr(v))
}

// DropPrimaryKeyActionNode
// DROP PRIMARY KEY [IF EXISTS] for ALTER TABLE statement.
type DropPrimaryKeyActionNode struct {
	*BaseAlterActionNode
}

func (n *DropPrimaryKeyActionNode) IsIfExists() bool {
	var v bool
	internal.ResolvedDropPrimaryKeyAction_is_if_exists(n.raw, &v)
	return v
}

func (n *DropPrimaryKeyActionNode) SetIsIfExists(v bool) {
	internal.ResolvedDropPrimaryKeyAction_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

// AlterColumnOptionsActionNode
type AlterColumnOptionsActionNode struct {
	*BaseAlterColumnActionNode
}

func (n *AlterColumnOptionsActionNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedAlterColumnOptionsAction_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *AlterColumnOptionsActionNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedAlterColumnOptionsAction_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AlterColumnOptionsActionNode) AddOption(v *OptionNode) {
	internal.ResolvedAlterColumnOptionsAction_add_option_list(n.raw, v.getRaw())
}

// AlterColumnDropNotNullActionNode
// This ALTER action:
//   ALTER COLUMN [IF EXISTS] <column> DROP NOT NULL
//
// Removes the NOT NULL constraint from the given column.
type AlterColumnDropNotNullActionNode struct {
	*BaseAlterColumnActionNode
}

// AlterColumnSetDataTypeActionNode
// ALTER COLUMN <column> SET DATA TYPE action for ALTER TABLE
// statement. It supports updating the data type of the column as
// well as updating type parameters and collation specifications of
// the column (and on struct fields and array elements).
type AlterColumnSetDataTypeActionNode struct {
	*BaseAlterColumnActionNode
}

// UpdatedType the new type for the column.
func (n *AlterColumnSetDataTypeActionNode) UpdatedType() types.Type {
	var v unsafe.Pointer
	internal.ResolvedAlterColumnSetDataTypeAction_updated_type(n.raw, &v)
	return newType(v)
}

func (n *AlterColumnSetDataTypeActionNode) SetUpdatedType(v types.Type) {
	internal.ResolvedAlterColumnSetDataTypeAction_set_updated_type(n.raw, getRawType(v))
}

// UpdatedTypeParameters the new type parameters for the column, if the new type has
// parameters. Note that unlike with CREATE TABLE, the child_list is
// populated for ARRAY and STRUCT types.
// TODO Use updated_annotations to pass type parameters.
func (n *AlterColumnSetDataTypeActionNode) UpdatedTypeParameters() *types.TypeParameters {
	var v unsafe.Pointer
	internal.ResolvedAlterColumnSetDataTypeAction_updated_type_parameters(n.raw, &v)
	return newTypeParameters(v)
}

func (n *AlterColumnSetDataTypeActionNode) SetUpdatedTypeParameters(v *types.TypeParameters) {
	internal.ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters(n.raw, getRawTypeParameters(v))
}

// UpdatedAnnotations the new annotations for the column including the new collation
// specifications. Changing options using SET DATA TYPE action is not allowed.
func (n *AlterColumnSetDataTypeActionNode) UpdatedAnnotations() *ColumnAnnotationsNode {
	var v unsafe.Pointer
	internal.ResolvedAlterColumnSetDataTypeAction_updated_annotations(n.raw, &v)
	return newColumnAnnotationsNode(v)
}

func (n *AlterColumnSetDataTypeActionNode) SetUpdatedAnnotations(v *ColumnAnnotationsNode) {
	internal.ResolvedAlterColumnSetDataTypeAction_set_updated_annotations(n.raw, v.getRaw())
}

// AlterColumnSetDefaultActionNode alter column set default action:
//   ALTER COLUMN [IF EXISTS] <column> SET DEFAULT <default_value>
//
// <default_value> sets the new default value expression. It only impacts
// future inserted rows, and has no impact on existing rows with the current
// default value. This is a metadata only operation.
//
// Resolver validates that <default_value> expression can be coerced to the
// column type when <column> exists. If <column> is not found and
// <is_if_exists> is true, Resolver skips type match check.
type AlterColumnSetDefaultActionNode struct {
	*BaseAlterColumnActionNode
}

func (n *AlterColumnSetDefaultActionNode) DefaultValue() *ColumnDefaultValueNode {
	var v unsafe.Pointer
	internal.ResolvedAlterColumnSetDefaultAction_default_value(n.raw, &v)
	return newColumnDefaultValueNode(v)
}

func (n *AlterColumnSetDefaultActionNode) SetDefaultValue(v *ColumnDefaultValueNode) {
	internal.ResolvedAlterColumnSetDefaultAction_set_default_value(n.raw, v.getRaw())
}

// AlterColumnDropDefaultAction this ALTER action:
//   ALTER COLUMN [IF EXISTS] <column> DROP DEFAULT
//
// Removes the DEFAULT constraint from the given column.
type AlterColumnDropDefaultActionNode struct {
	*BaseAlterColumnActionNode
}

// DropColumnActionNode
// DROP COLUMN action for ALTER TABLE statement
//
// <name> is the name of the column to drop.
type DropColumnActionNode struct {
	*BaseAlterActionNode
}

func (n *DropColumnActionNode) IsIfExists() bool {
	var v bool
	internal.ResolvedDropColumnAction_is_if_exists(n.raw, &v)
	return v
}

func (n *DropColumnActionNode) SetIsIfExists(v bool) {
	internal.ResolvedDropColumnAction_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

func (n *DropColumnActionNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedDropColumnAction_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *DropColumnActionNode) SetName(v string) {
	internal.ResolvedDropColumnAction_set_name(n.raw, helper.StringToPtr(v))
}

// RenameColumnActionNode
// RENAME COLUMN action for ALTER TABLE statement.
//
// <name> is the name of the column to rename.
// <new_name> is the new name of the column.
//
// RENAME COLUMN actions cannot be part of the same alter_action_list as any
// other type of action.
// Chains of RENAME COLUMN will be interpreted as a sequence of mutations.
// The order of actions matters. Each <name> refers to a column name that
// exists after all preceding renames have been applied.
type RenameColumnActionNode struct {
	*BaseAlterActionNode
}

func (n *RenameColumnActionNode) IsIfExists() bool {
	var v bool
	internal.ResolvedRenameColumnAction_is_if_exists(n.raw, &v)
	return v
}

func (n *RenameColumnActionNode) SetIsIfExists(v bool) {
	internal.ResolvedRenameColumnAction_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

func (n *RenameColumnActionNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedRenameColumnAction_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *RenameColumnActionNode) SetName(v string) {
	internal.ResolvedRenameColumnAction_set_name(n.raw, helper.StringToPtr(v))
}

func (n *RenameColumnActionNode) NewName() string {
	var v unsafe.Pointer
	internal.ResolvedRenameColumnAction_new_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *RenameColumnActionNode) SetNewName(v string) {
	internal.ResolvedRenameColumnAction_set_new_name(n.raw, helper.StringToPtr(v))
}

// SetAsActionNode
// SET AS action for generic ALTER <entity_type> statement.
// Exactly one of <entity_body_json>, <entity_body_text> should be non-empty.
//
// <entity_body_json> is a JSON literal to be interpreted by engine.
// <entity_body_text> is a text literal to be interpreted by engine.
type SetAsActionNode struct {
	*BaseAlterActionNode
}

func (n *SetAsActionNode) EntityBodyJSON() string {
	var v unsafe.Pointer
	internal.ResolvedSetAsAction_entity_body_json(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *SetAsActionNode) SetEntityBodyJSON(v string) {
	internal.ResolvedSetAsAction_set_entity_body_json(n.raw, helper.StringToPtr(v))
}

func (n *SetAsActionNode) EntityBodyText() string {
	var v unsafe.Pointer
	internal.ResolvedSetAsAction_entity_body_text(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *SetAsActionNode) SetEntityBodyText(v string) {
	internal.ResolvedSetAsAction_set_entity_body_text(n.raw, helper.StringToPtr(v))
}

// SetCollateClauseNode
// SET DEFAULT COLLATE clause for generic ALTER <entity_type> statement.
//
// <collation_name> specifies the new default collation specification for a
//   table or schema. Modifying the default collation for a table or schema
//   does not affect any existing columns or tables - the new default
//   collation only affects new tables and/or columns if applicable. Only
//   string literals are allowed for this field.
type SetCollateClauseNode struct {
	*BaseAlterActionNode
}

func (n *SetCollateClauseNode) CollationName() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedSetCollateClause_collation_name(n.raw, &v)
	return newExprNode(v)
}

func (n *SetCollateClauseNode) SetCollationName(v ExprNode) {
	internal.ResolvedSetCollateClause_set_collation_name(n.raw, v.getRaw())
}

// AlterTableSetOptionsStmtNode this statement:
//   ALTER TABLE [IF EXISTS] <name> SET OPTIONS (...)
//
// NOTE: This is deprecated in favor of AlterTableStmtNode.
//
// <name_path> is a vector giving the identifier path in the table <name>.
// <option_list> has engine-specific directives that specify how to
//               alter the metadata for this table.
// <is_if_exists> silently ignore the "name_path does not exist" error.
type AlterTableSetOptionsStmtNode struct {
	*BaseStatementNode
}

func (n *AlterTableSetOptionsStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedAlterTableSetOptionsStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *AlterTableSetOptionsStmtNode) SetNamePath(v []string) {
	internal.ResolvedAlterTableSetOptionsStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *AlterTableSetOptionsStmtNode) AddNamePath(v string) {
	internal.ResolvedAlterTableSetOptionsStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

func (n *AlterTableSetOptionsStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedAlterTableSetOptionsStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *AlterTableSetOptionsStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedAlterTableSetOptionsStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AlterTableSetOptionsStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedAlterTableSetOptionsStmt_add_option_list(n.raw, v.getRaw())
}

func (n *AlterTableSetOptionsStmtNode) IsIfExists() bool {
	var v bool
	internal.ResolvedAlterTableSetOptionsStmt_is_if_exists(n.raw, &v)
	return v
}

func (n *AlterTableSetOptionsStmtNode) SetIsIfExists(v bool) {
	internal.ResolvedAlterTableSetOptionsStmt_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

// RenameStmtNode this statement:
// RENAME <object_type> <old_name_path> TO <new_name_path>;
//
// <object_type> is an string identifier,
//               e.g., "TABLE", "VIEW", "INDEX", "FUNCTION", "TYPE", etc.
// <old_name_path> is a vector giving the identifier path for the object to
//                 be renamed.
// <new_name_path> is a vector giving the identifier path for the object to
//                 be renamed to.
type RenameStmtNode struct {
	*BaseStatementNode
}

func (n *RenameStmtNode) ObjectType() string {
	var v unsafe.Pointer
	internal.ResolvedRenameStmt_object_type(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *RenameStmtNode) SetObjectType(v string) {
	internal.ResolvedRenameStmt_set_object_type(n.raw, helper.StringToPtr(v))
}

func (n *RenameStmtNode) OldNamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedRenameStmt_old_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *RenameStmtNode) SetOldNamePath(v []string) {
	internal.ResolvedRenameStmt_set_old_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *RenameStmtNode) AddOldNamePath(v string) {
	internal.ResolvedRenameStmt_add_old_name_path(n.raw, helper.StringToPtr(v))
}

func (n *RenameStmtNode) NewNamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedRenameStmt_new_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *RenameStmtNode) SetNewNamePath(v []string) {
	internal.ResolvedRenameStmt_set_new_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *RenameStmtNode) AddNewName(v string) {
	internal.ResolvedRenameStmt_add_new_name_path(n.raw, helper.StringToPtr(v))
}

// CreatePrivilegeRestrictionStmtNode this statement:
//     CREATE [OR REPLACE] PRIVILEGE RESTRICTION [IF NOT EXISTS]
//     ON <column_privilege_list> ON <object_type> <name_path>
//     [RESTRICT TO (<restrictee_list>)]
//
// <column_privilege_list> is the name of the column privileges on which
//                         to apply the restrictions.
// <object_type> is a string identifier, which is currently either TABLE or
//               VIEW, which tells the engine how to look up the name.
// <restrictee_list> is a list of users and groups the privilege restrictions
//                   should apply to. Each restrictee is either a string
//                   literal or a parameter.
type CreatePrivilegeRestrictionStmtNode struct {
	*BaseCreateStatementNode
}

func (n *CreatePrivilegeRestrictionStmtNode) ColumnPrivilegeList() []*PrivilegeNode {
	var v unsafe.Pointer
	internal.ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list(n.raw, &v)
	var ret []*PrivilegeNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newPrivilegeNode(p))
	})
	return ret
}

func (n *CreatePrivilegeRestrictionStmtNode) SetColumnPrivilegeList(v []*PrivilegeNode) {
	internal.ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreatePrivilegeRestrictionStmtNode) AddColumnPrivilege(v *PrivilegeNode) {
	internal.ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list(n.raw, v.getRaw())
}

func (n *CreatePrivilegeRestrictionStmtNode) ObjectType() string {
	var v unsafe.Pointer
	internal.ResolvedCreatePrivilegeRestrictionStmt_object_type(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *CreatePrivilegeRestrictionStmtNode) SetObjectType(v string) {
	internal.ResolvedCreatePrivilegeRestrictionStmt_set_object_type(n.raw, helper.StringToPtr(v))
}

func (n *CreatePrivilegeRestrictionStmtNode) RestricteeList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCreatePrivilegeRestrictionStmt_restrictee_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *CreatePrivilegeRestrictionStmtNode) SetRestricteeList(v []ExprNode) {
	internal.ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreatePrivilegeRestrictionStmtNode) AddRestrictee(v ExprNode) {
	internal.ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list(n.raw, v.getRaw())
}

// CreateRowAccessPolicyStmtNode this statement:
// CREATE [OR REPLACE] ROW ACCESS POLICY [IF NOT EXISTS]
//                 [<name>] ON <target_name_path>
//                 [GRANT TO (<grantee_list>)]
//                 FILTER USING (<predicate>);
//
// <create_mode> indicates if this was CREATE, CREATE OR REPLACE, or
//               CREATE IF NOT EXISTS.
// <name> is the name of the row access policy to be created or an empty
//        string.
// <target_name_path> is a vector giving the identifier path of the target
//                    table.
// <table_scan> is a TableScan for the target table, which is used during
//              resolving and validation. Consumers can use either the table
//              object inside it or target_name_path to reference the table.
// <grantee_list> (DEPRECATED) is the list of user principals the policy
//                should apply to.
// <grantee_expr_list> is the list of user principals the policy should
//                     apply to, and may include parameters.
// <predicate> is a boolean expression that selects the rows that are being
//             made visible.
// <predicate_str> is the string form of the predicate.
//
// Only one of <grantee_list> or <grantee_expr_list> will be populated,
// depending on whether or not the FEATURE_PARAMETERS_IN_GRANTEE_LIST
// is enabled.  The <grantee_list> is deprecated, and will be removed
// along with the corresponding FEATURE once all engines have migrated to
// use the <grantee_expr_list>.  Once <grantee_expr_list> is the only
// one, then it should be marked as NOT_IGNORABLE.
type CreateRowAccessPolicyStmtNode struct {
	*BaseStatementNode
}

func (n *CreateRowAccessPolicyStmtNode) CreateMode() CreateMode {
	var v int
	internal.ResolvedCreateRowAccessPolicyStmt_create_mode(n.raw, &v)
	return CreateMode(v)
}

func (n *CreateRowAccessPolicyStmtNode) SetCreateMode(v CreateMode) {
	internal.ResolvedCreateRowAccessPolicyStmt_set_create_mode(n.raw, int(v))
}

func (n *CreateRowAccessPolicyStmtNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedCreateRowAccessPolicyStmt_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *CreateRowAccessPolicyStmtNode) SetName(v string) {
	internal.ResolvedCreateRowAccessPolicyStmt_set_name(n.raw, helper.StringToPtr(v))
}

func (n *CreateRowAccessPolicyStmtNode) TargetNamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedCreateRowAccessPolicyStmt_target_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *CreateRowAccessPolicyStmtNode) SetTargetNamePath(v []string) {
	internal.ResolvedCreateRowAccessPolicyStmt_set_target_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *CreateRowAccessPolicyStmtNode) AddTargetNamePath(v string) {
	internal.ResolvedCreateRowAccessPolicyStmt_add_target_name_path(n.raw, helper.StringToPtr(v))
}

func (n *CreateRowAccessPolicyStmtNode) GranteeList() []string {
	var v unsafe.Pointer
	internal.ResolvedCreateRowAccessPolicyStmt_grantee_list(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *CreateRowAccessPolicyStmtNode) SetGranteeList(v []string) {
	internal.ResolvedCreateRowAccessPolicyStmt_set_grantee_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *CreateRowAccessPolicyStmtNode) AddGrantee(v string) {
	internal.ResolvedCreateRowAccessPolicyStmt_add_grantee_list(n.raw, helper.StringToPtr(v))
}

func (n *CreateRowAccessPolicyStmtNode) GranteeExprList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCreateRowAccessPolicyStmt_grantee_expr_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *CreateRowAccessPolicyStmtNode) SetGranteeExprList(v []ExprNode) {
	internal.ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateRowAccessPolicyStmtNode) AddGranteeExpr(v ExprNode) {
	internal.ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list(n.raw, v.getRaw())
}

func (n *CreateRowAccessPolicyStmtNode) TableScan() *TableScanNode {
	var v unsafe.Pointer
	internal.ResolvedCreateRowAccessPolicyStmt_table_scan(n.raw, &v)
	return newTableScanNode(v)
}

func (n *CreateRowAccessPolicyStmtNode) SetTableScan(v *TableScanNode) {
	internal.ResolvedCreateRowAccessPolicyStmt_set_table_scan(n.raw, v.getRaw())
}

func (n *CreateRowAccessPolicyStmtNode) Predicate() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCreateRowAccessPolicyStmt_predicate(n.raw, &v)
	return newExprNode(v)
}

func (n *CreateRowAccessPolicyStmtNode) SetPredicate(v ExprNode) {
	internal.ResolvedCreateRowAccessPolicyStmt_set_predicate(n.raw, v.getRaw())
}

func (n *CreateRowAccessPolicyStmtNode) PredicateStr() string {
	var v unsafe.Pointer
	internal.ResolvedCreateRowAccessPolicyStmt_predicate_str(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *CreateRowAccessPolicyStmtNode) SetPredicateStr(v string) {
	internal.ResolvedCreateRowAccessPolicyStmt_set_predicate_str(n.raw, helper.StringToPtr(v))
}

// DropPrivilegeRestrictionStmtNode this statement:
//     DROP PRIVILEGE RESTRICTION [IF EXISTS]
//     ON <column_privilege_list> ON <object_type> <name_path>
//
// <column_privilege_list> is the name of the column privileges on which
//                         the restrictions have been applied.
// <object_type> is a string identifier, which is currently either TABLE or
//               VIEW, which tells the engine how to look up the name.
// <name_path> is the name of the table the restrictions are scoped to.
type DropPrivilegeRestrictionStmtNode struct {
	*BaseStatementNode
}

func (n *DropPrivilegeRestrictionStmtNode) ObjectType() string {
	var v unsafe.Pointer
	internal.ResolvedDropPrivilegeRestrictionStmt_object_type(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *DropPrivilegeRestrictionStmtNode) SetObjectType(v string) {
	internal.ResolvedDropPrivilegeRestrictionStmt_set_object_type(n.raw, helper.StringToPtr(v))
}

func (n *DropPrivilegeRestrictionStmtNode) IsIfExists() bool {
	var v bool
	internal.ResolvedDropPrivilegeRestrictionStmt_is_if_exists(n.raw, &v)
	return v
}

func (n *DropPrivilegeRestrictionStmtNode) SetIsIfExists(v bool) {
	internal.ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

func (n *DropPrivilegeRestrictionStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedDropPrivilegeRestrictionStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *DropPrivilegeRestrictionStmtNode) SetNamePath(v []string) {
	internal.ResolvedDropPrivilegeRestrictionStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *DropPrivilegeRestrictionStmtNode) AddNamePath(v string) {
	internal.ResolvedDropPrivilegeRestrictionStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

func (n *DropPrivilegeRestrictionStmtNode) ColumnPrivilegeList() []*PrivilegeNode {
	var v unsafe.Pointer
	internal.ResolvedDropPrivilegeRestrictionStmt_column_privilege_list(n.raw, &v)
	var ret []*PrivilegeNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newPrivilegeNode(p))
	})
	return ret
}

func (n *DropPrivilegeRestrictionStmtNode) SetColumnPrivilegeList(v []*PrivilegeNode) {
	internal.ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *DropPrivilegeRestrictionStmtNode) AddColumnPrivilege(v *PrivilegeNode) {
	internal.ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list(n.raw, v.getRaw())
}

// DropRowAccessPolicyStmtNode this statement:
//     DROP ROW ACCESS POLICY <name> ON <target_name_path>; or
//     DROP ALL ROW [ACCESS] POLICIES ON <target_name_path>;
//
// <is_drop_all> indicates that all policies should be dropped.
// <is_if_exists> silently ignore the "policy <name> does not exist" error.
//                This is not allowed if is_drop_all is true.
// <name> is the name of the row policy to be dropped or an empty string.
// <target_name_path> is a vector giving the identifier path of the target table.
type DropRowAccessPolicyStmtNode struct {
	*BaseStatementNode
}

func (n *DropRowAccessPolicyStmtNode) IsDropAll() bool {
	var v bool
	internal.ResolvedDropRowAccessPolicyStmt_is_drop_all(n.raw, &v)
	return v
}

func (n *DropRowAccessPolicyStmtNode) SetIsDropAll(v bool) {
	internal.ResolvedDropRowAccessPolicyStmt_set_is_drop_all(n.raw, helper.BoolToInt(v))
}

func (n *DropRowAccessPolicyStmtNode) IsIfExists() bool {
	var v bool
	internal.ResolvedDropRowAccessPolicyStmt_is_if_exists(n.raw, &v)
	return v
}

func (n *DropRowAccessPolicyStmtNode) SetIsIfExists(v bool) {
	internal.ResolvedDropRowAccessPolicyStmt_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

func (n *DropRowAccessPolicyStmtNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedDropRowAccessPolicyStmt_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *DropRowAccessPolicyStmtNode) SetName(v string) {
	internal.ResolvedDropRowAccessPolicyStmt_set_name(n.raw, helper.StringToPtr(v))
}

func (n *DropRowAccessPolicyStmtNode) TargetNamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedDropRowAccessPolicyStmt_target_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *DropRowAccessPolicyStmtNode) SetTargetNamePath(v []string) {
	internal.ResolvedDropRowAccessPolicyStmt_set_target_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *DropRowAccessPolicyStmtNode) AddTargetNamePath(v string) {
	internal.ResolvedDropRowAccessPolicyStmt_add_target_name_path(n.raw, helper.StringToPtr(v))
}

// DropSearchIndexStmtNode
// DROP SEARCH INDEX [IF EXISTS] <name> [ON <table_name_path>];
//
// <name> is the name of the search index to be dropped.
// <table_name_path> is a vector giving the identifier path of the target table.
type DropSearchIndexStmtNode struct {
	*BaseStatementNode
}

func (n *DropSearchIndexStmtNode) IsIfExists() bool {
	var v bool
	internal.ResolvedDropSearchIndexStmt_is_if_exists(n.raw, &v)
	return v
}

func (n *DropSearchIndexStmtNode) SetIsIfExists(v bool) {
	internal.ResolvedDropSearchIndexStmt_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

func (n *DropSearchIndexStmtNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedDropSearchIndexStmt_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *DropSearchIndexStmtNode) SetName(v string) {
	internal.ResolvedDropSearchIndexStmt_set_name(n.raw, helper.StringToPtr(v))
}

func (n *DropSearchIndexStmtNode) TableNamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedDropSearchIndexStmt_table_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *DropSearchIndexStmtNode) SetTableNamePath(v []string) {
	internal.ResolvedDropSearchIndexStmt_set_table_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *DropSearchIndexStmtNode) AddTableNamePath(v string) {
	internal.ResolvedDropSearchIndexStmt_add_table_name_path(n.raw, helper.StringToPtr(v))
}

// GrantToActionNode
// GRANT TO action for ALTER ROW ACCESS POLICY statement
//
// <grantee_expr_list> is the list of grantees, and may include parameters.
type GrantToActionNode struct {
	*BaseAlterActionNode
}

func (n *GrantToActionNode) GranteeExprList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedGrantToAction_grantee_expr_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *GrantToActionNode) SetGranteeExprList(v []ExprNode) {
	internal.ResolvedGrantToAction_set_grantee_expr_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *GrantToActionNode) AddGranteeExpr(v ExprNode) {
	internal.ResolvedGrantToAction_add_grantee_expr_list(n.raw, v.getRaw())
}

// RestrictToActionNode this action for ALTER PRIVILEGE RESTRICTION statement:
//     RESTRICT TO <restrictee_list>
//
// <restrictee_list> is a list of users and groups the privilege restrictions
//                   should apply to. Each restrictee is either a string
//                   literal or a parameter.
type RestrictToActionNode struct {
	*BaseAlterActionNode
}

func (n *RestrictToActionNode) RestricteeList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedRestrictToAction_restrictee_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *RestrictToActionNode) SetRestricteeList(v []ExprNode) {
	internal.ResolvedRestrictToAction_set_restrictee_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *RestrictToActionNode) AddRestrictee(v ExprNode) {
	internal.ResolvedRestrictToAction_add_restrictee_list(n.raw, v.getRaw())
}

// AddToRestricteeListActionNode This action for ALTER PRIVILEGE RESTRICTION statement:
//     ADD [IF NOT EXISTS] <restrictee_list>
//
// <restrictee_list> is a list of users and groups the privilege restrictions
//                   should apply to. Each restrictee is either a string
//                   literal or a parameter.
type AddToRestricteeListActionNode struct {
	*BaseAlterActionNode
}

func (n *AddToRestricteeListActionNode) IsIfNotExists() bool {
	var v bool
	internal.ResolvedAddToRestricteeListAction_is_if_not_exists(n.raw, &v)
	return v
}

func (n *AddToRestricteeListActionNode) SetIsIfNotExists(v bool) {
	internal.ResolvedAddToRestricteeListAction_set_is_if_not_exists(n.raw, helper.BoolToInt(v))
}

func (n *AddToRestricteeListActionNode) RestricteeList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedAddToRestricteeListAction_restrictee_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *AddToRestricteeListActionNode) SetRestricteeList(v []ExprNode) {
	internal.ResolvedAddToRestricteeListAction_set_restrictee_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AddToRestricteeListActionNode) AddRestrictee(v ExprNode) {
	internal.ResolvedAddToRestricteeListAction_add_restrictee_list(n.raw, v.getRaw())
}

// RemoveFromRestricteeListActionNode this action for ALTER PRIVILEGE RESTRICTION statement:
//     REMOVE [IF EXISTS] <restrictee_list>
//
// <restrictee_list> is a list of users and groups the privilege restrictions
//                   should apply to. Each restrictee is either a string
//                   literal or a parameter.
type RemoveFromRestricteeListActionNode struct {
	*BaseAlterActionNode
}

func (n *RemoveFromRestricteeListActionNode) IsIfExists() bool {
	var v bool
	internal.ResolvedRemoveFromRestricteeListAction_is_if_exists(n.raw, &v)
	return v
}

func (n *RemoveFromRestricteeListActionNode) SetIsIfExists(v bool) {
	internal.ResolvedRemoveFromRestricteeListAction_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

func (n *RemoveFromRestricteeListActionNode) RestricteeList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedRemoveFromRestricteeListAction_restrictee_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *RemoveFromRestricteeListActionNode) SetRestricteeList(v []ExprNode) {
	internal.ResolvedRemoveFromRestricteeListAction_set_restrictee_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *RemoveFromRestricteeListActionNode) AddRestrictee(v ExprNode) {
	internal.ResolvedRemoveFromRestricteeListAction_add_restrictee_list(n.raw, v.getRaw())
}

// FilterUsingActionNode FILTER USING action for ALTER ROW ACCESS POLICY statement
//
// <predicate> is a boolean expression that selects the rows that are being
//             made visible.
// <predicate_str> is the string form of the predicate.
type FilterUsingActionNode struct {
	*BaseAlterActionNode
}

func (n *FilterUsingActionNode) Predicate() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedFilterUsingAction_predicate(n.raw, &v)
	return newExprNode(v)
}

func (n *FilterUsingActionNode) SetPredicate(v ExprNode) {
	internal.ResolvedFilterUsingAction_set_predicate(n.raw, v.getRaw())
}

func (n *FilterUsingActionNode) PredicateStr() string {
	var v unsafe.Pointer
	internal.ResolvedFilterUsingAction_predicate_str(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *FilterUsingActionNode) SetPredicateStr(v string) {
	internal.ResolvedFilterUsingAction_set_predicate_str(n.raw, helper.StringToPtr(v))
}

// RevokeFromActionNode REVOKE FROM action for ALTER ROW ACCESS POLICY statement
//
// <revokee_expr_list> is the list of revokees, and may include parameters.
// <is_revoke_from_all> is a boolean indicating whether it was a REVOKE FROM
//                      ALL statement.
type RevokeFromActionNode struct {
	*BaseAlterActionNode
}

func (n *RevokeFromActionNode) RevokeeExprList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedRevokeFromAction_revokee_expr_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *RevokeFromActionNode) SetRevokeeExprList(v []ExprNode) {
	internal.ResolvedRevokeFromAction_set_revokee_expr_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *RevokeFromActionNode) AddRevokeeExpr(v ExprNode) {
	internal.ResolvedRevokeFromAction_add_revokee_expr_list(n.raw, v.getRaw())
}

func (n *RevokeFromActionNode) IsRevokeFromAll() bool {
	var v bool
	internal.ResolvedRevokeFromAction_is_revoke_from_all(n.raw, &v)
	return v
}

func (n *RevokeFromActionNode) SetIsRevokeFromAll(v bool) {
	internal.ResolvedRevokeFromAction_set_is_revoke_from_all(n.raw, helper.BoolToInt(v))
}

// RenameToActionNode RENAME TO action for ALTER ROW ACCESS POLICY statement
//         and ALTER TABLE statement
//
// <new_path> is the new name of the row access policy,
//         or the new path of the table.
type RenameToActionNode struct {
	*BaseAlterActionNode
}

func (n *RenameToActionNode) NewPath() []string {
	var v unsafe.Pointer
	internal.ResolvedRenameToAction_new_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(v))
	})
	return ret
}

func (n *RenameToActionNode) SetNewPath(v []string) {
	internal.ResolvedRenameToAction_set_new_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *RenameToActionNode) AddNewPath(v string) {
	internal.ResolvedRenameToAction_add_new_path(n.raw, helper.StringToPtr(v))
}

// AlterPrivilegeRestrictionStmtNode this statement:
//     ALTER PRIVILEGE RESTRICTION [IF EXISTS]
//     ON <column_privilege_list> ON <object_type> <name_path>
//     <alter_action_list>
//
// <column_privilege_list> is the name of the column privileges on which
//                         the restrictions have been applied.
// <object_type> is a string identifier, which is currently either TABLE or
//               VIEW, which tells the engine how to look up the name.
type AlterPrivilegeRestrictionStmtNode struct {
	*AlterObjectStmtNode
}

func (n *AlterPrivilegeRestrictionStmtNode) ColumnPrivilegeList() []*PrivilegeNode {
	var v unsafe.Pointer
	internal.ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list(n.raw, &v)
	var ret []*PrivilegeNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newPrivilegeNode(p))
	})
	return ret
}

func (n *AlterPrivilegeRestrictionStmtNode) SetColumnPrivilegeList(v []*PrivilegeNode) {
	internal.ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AlterPrivilegeRestrictionStmtNode) AddColumnPrivilege(v *PrivilegeNode) {
	internal.ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list(n.raw, v.getRaw())
}

func (n *AlterPrivilegeRestrictionStmtNode) ObjectType() string {
	var v unsafe.Pointer
	internal.ResolvedAlterPrivilegeRestrictionStmt_object_type(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *AlterPrivilegeRestrictionStmtNode) SetObjectType(v string) {
	internal.ResolvedAlterPrivilegeRestrictionStmt_set_object_type(n.raw, helper.StringToPtr(v))
}

// AlterRowAccessPolicyStmtNode this statement:
//     ALTER ROW ACCESS POLICY [IF EXISTS]
//     <name> ON <name_path>
//     <alter_action_list>
//
// <name> is the name of the row access policy to be altered, scoped to the
//        table in the base <name_path>.
// <table_scan> is a TableScan for the target table, which is used during
//              resolving and validation. Consumers can use either the table
//              object inside it or base <name_path> to reference the table.
type AlterRowAccessPolicyStmtNode struct {
	*AlterObjectStmtNode
}

func (n *AlterRowAccessPolicyStmtNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedAlterRowAccessPolicyStmt_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *AlterRowAccessPolicyStmtNode) SetName(v string) {
	internal.ResolvedAlterRowAccessPolicyStmt_set_name(n.raw, helper.StringToPtr(v))
}

func (n *AlterRowAccessPolicyStmtNode) TableScan() *TableScanNode {
	var v unsafe.Pointer
	internal.ResolvedAlterRowAccessPolicyStmt_table_scan(n.raw, &v)
	return newTableScanNode(v)
}

func (n *AlterRowAccessPolicyStmtNode) SetTableScan(v *TableScanNode) {
	internal.ResolvedAlterRowAccessPolicyStmt_set_table_scan(n.raw, v.getRaw())
}

// AlterAllRowAccessPoliciesStmtNode this statement:
//     ALTER ALL ROW ACCESS POLICIES ON <name_path> <alter_action_list>
//
// <name_path> is a vector giving the identifier path in the table name.
// <alter_action_list> is a vector of actions to be done to the object. It
//                     must have exactly one REVOKE FROM action with either
//                     a non-empty grantee list or 'all'.
// <table_scan> is a TableScan for the target table, which is used during
//              resolving and validation. Consumers can use either the table
//              object inside it or base <name_path> to reference the table.
type AlterAllRowAccessPoliciesStmtNode struct {
	*AlterObjectStmtNode
}

func (n *AlterAllRowAccessPoliciesStmtNode) TableScan() *TableScanNode {
	var v unsafe.Pointer
	internal.ResolvedAlterAllRowAccessPoliciesStmt_table_scan(n.raw, &v)
	return newTableScanNode(v)
}

func (n *AlterAllRowAccessPoliciesStmtNode) SetTableScan(v *TableScanNode) {
	internal.ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan(n.raw, v.getRaw())
}

// CreateConstantStmtNode this statement creates a user-defined named constant:
// CREATE [OR REPLACE] [TEMP | TEMPORARY | PUBLIC | PRIVATE] CONSTANT
//   [IF NOT EXISTS] <name_path> = <expression>
//
// <name_path> is the identifier path of the named constants.
// <expr> is the expression that determines the type and the value of the
//        named constant. Note that <expr> need not be constant. Its value
//        is bound to the named constant which is then treated as
//        immutable. <expr> can be evaluated at the time this statement is
//        processed or later (lazy evaluation during query execution).
type CreateConstantStmtNode struct {
	*BaseCreateStatementNode
}

func (n *CreateConstantStmtNode) Expr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCreateConstantStmt_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *CreateConstantStmtNode) SetExpr(v ExprNode) {
	internal.ResolvedCreateConstantStmt_set_expr(n.raw, v.getRaw())
}

// CreateFunctionStmtNode this statement creates a user-defined function:
//   CREATE [TEMP] FUNCTION [IF NOT EXISTS] <name_path> (<arg_list>)
//     [RETURNS <return_type>] [SQL SECURITY <sql_security>]
//     [<determinism_level>]
//     [[LANGUAGE <language>] [AS <code> | AS ( <function_expression> )]
//      | REMOTE [WITH CONNECTION <connection>]]
//     [OPTIONS (<option_list>)]
//
//   <name_path> is the identifier path of the function.
//   <has_explicit_return_type> is true iff RETURNS clause is present.
//   <return_type> is the return type for the function, which can be any
//          valid ZetaSQL type, including ARRAY or STRUCT. It is inferred
//          from <function_expression> if not explicitly set.
//          TODO: Deprecate and remove this. The return type is
//          already specified by the <signature>.
//   <argument_name_list> The names of the function arguments.
//   <signature> is the FunctionSignature of the created function, with all
//          options.  This can be used to create a Function to load into a
//          Catalog for future queries.
//   <is_aggregate> is true if this is an aggregate function.  All arguments
//          are assumed to be aggregate input arguments that may vary for
//          every row.
//   <language> is the programming language used by the function. This field
//          is set to 'SQL' for SQL functions and 'REMOTE' for remote
//          functions and otherwise to the language name specified in the
//          LANGUAGE clause. This field is set to 'REMOTE' iff <is_remote> is
//          set to true.
//   <code> is a string literal that contains the function definition.  Some
//          engines may allow this argument to be omitted for certain types
//          of external functions. This will always be set for SQL functions.
//   <aggregate_expression_list> is a list of SQL aggregate functions to
//          compute prior to computing the final <function_expression>.
//          See below.
//   <function_expression> is the resolved SQL expression invoked for the
//          function. This will be unset for external language functions. For
//          non-template SQL functions, this is a resolved representation of
//          the expression in <code>.
//   <option_list> has engine-specific directives for modifying functions.
//   <sql_security> is the declared security mode for the function. Values
//          include 'INVOKER', 'DEFINER'.
//   <determinism_level> is the declared determinism level of the function.
//          Values are 'DETERMINISTIC', 'NOT DETERMINISTIC', 'IMMUTABLE',
//          'STABLE', 'VOLATILE'.
//   <is_remote> is true if this is an remote function. It is true iff its
//          <language> is set to 'REMOTE'.
//   <connection> is the identifier path of the connection object. It can be
//          only set when <is_remote> is true.
//
// Note that <function_expression> and <code> are both marked as IGNORABLE
// because an engine could look at either one (but might not look at both).
// An engine must look at one (and cannot ignore both, unless the function is
// remote) to be semantically valid, but there is currently no way to enforce
// that.
//
// For aggregate functions, <is_aggregate> will be true.
// Aggregate functions will only occur if LanguageOptions has
// FEATURE_CREATE_AGGREGATE_FUNCTION enabled.
//
// Arguments to aggregate functions must have
// <FunctionSignatureArgumentTypeOptions::is_not_aggregate> true or false.
// Non-aggregate arguments must be passed constant values only.
//
// For SQL aggregate functions, there will be both an
// <aggregate_expression_list>, with aggregate expressions to compute first,
// and then a final <function_expression> to compute on the results
// of the aggregates.  Each aggregate expression is a
// AggregateFunctionCallNode, and may reference any input arguments.
// Each ComputedColumnNode in <aggregate_expression_list> gives the
// aggregate expression a column id.  The final <function_expression> can
// reference these created aggregate columns, and any input arguments
// with <argument_kind>=NOT_AGGREGATE.
//
// For example, with
//   CREATE TEMP FUNCTION my_avg(x) = (SUM(x) / COUNT(x));
// we would have an <aggregate_expression_list> with
//   agg1#1 := SUM(ArgumentRefNode(x))
//   agg2#2 := COUNT(ArgumentRefNode(x))
// and a <function_expression>
//   ColumnRefNode(agg1#1) / ColumnRefNode(agg2#2)
//
// For example, with
//   CREATE FUNCTION scaled_avg(x,y NOT AGGREGATE) = (SUM(x) / COUNT(x) * y);
// we would have an <aggregate_expression_list> with
//   agg1#1 := SUM(ArgumentRefNode(x))
//   agg2#2 := COUNT(ArgumentRefNode(x))
// and a <function_expression>
//   ColumnRefNode(agg1#1) / ColumnRefNode(agg2#2) * ArgumentRefNode(y)
//
// When resolving a query that calls an aggregate UDF, the query will
// have a AggregateScanNode that invokes the UDF function.  The engine
// should remove the UDF aggregate function from the <aggregate_list>, and
// instead compute the additional aggregates from the
// UDF's <aggregate_expression_list>, and then add an additional Project
// to compute the final <function_expression>, which should produce the
// value for the original AggregateScanNode's computed column for the
// UDF.  Some rewrites of the Column references inside the UDF will
// be required.  TODO If using Columns makes this renaming
// too complicated, we could switch to use ArgumentRefNodes, or
// something new.
type CreateFunctionStmtNode struct {
	*BaseCreateStatementNode
}

func (n *CreateFunctionStmtNode) HasExplicitReturnType() bool {
	var v bool
	internal.ResolvedCreateFunctionStmt_has_explicit_return_type(n.raw, &v)
	return v
}

func (n *CreateFunctionStmtNode) SetHasExplicitReturnType(v bool) {
	internal.ResolvedCreateFunctionStmt_set_has_explicit_return_type(n.raw, helper.BoolToInt(v))
}

func (n *CreateFunctionStmtNode) ReturnType() types.Type {
	var v unsafe.Pointer
	internal.ResolvedCreateFunctionStmt_return_type(n.raw, &v)
	return newType(v)
}

func (n *CreateFunctionStmtNode) SetReturnType(v types.Type) {
	internal.ResolvedCreateFunctionStmt_set_return_type(n.raw, getRawType(v))
}

func (n *CreateFunctionStmtNode) ArgumentNameList() []string {
	var v unsafe.Pointer
	internal.ResolvedCreateFunctionStmt_argument_name_list(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *CreateFunctionStmtNode) SetArgumentNameList(v []string) {
	internal.ResolvedCreateFunctionStmt_set_argument_name_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *CreateFunctionStmtNode) AddArgumentName(v string) {
	internal.ResolvedCreateFunctionStmt_add_argument_name_list(n.raw, helper.StringToPtr(v))
}

func (n *CreateFunctionStmtNode) Signature() *types.FunctionSignature {
	var v unsafe.Pointer
	internal.ResolvedCreateFunctionStmt_signature(n.raw, &v)
	return newFunctionSignature(v)
}

func (n *CreateFunctionStmtNode) SetSignature(v *types.FunctionSignature) {
	internal.ResolvedCreateFunctionStmt_set_signature(n.raw, getRawFunctionSignature(v))
}

func (n *CreateFunctionStmtNode) IsAggregate() bool {
	var v bool
	internal.ResolvedCreateFunctionStmt_is_aggregate(n.raw, &v)
	return v
}

func (n *CreateFunctionStmtNode) SetIsAggregate(v bool) {
	internal.ResolvedCreateFunctionStmt_set_is_aggregate(n.raw, helper.BoolToInt(v))
}

func (n *CreateFunctionStmtNode) Language() string {
	var v unsafe.Pointer
	internal.ResolvedCreateFunctionStmt_language(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *CreateFunctionStmtNode) SetLanguage(v string) {
	internal.ResolvedCreateFunctionStmt_set_language(n.raw, helper.StringToPtr(v))
}

func (n *CreateFunctionStmtNode) Code() string {
	var v unsafe.Pointer
	internal.ResolvedCreateFunctionStmt_code(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *CreateFunctionStmtNode) SetCode(v string) {
	internal.ResolvedCreateFunctionStmt_set_code(n.raw, helper.StringToPtr(v))
}

func (n *CreateFunctionStmtNode) AggregateExpressionList() []*ComputedColumnNode {
	var v unsafe.Pointer
	internal.ResolvedCreateFunctionStmt_aggregate_expression_list(n.raw, &v)
	var ret []*ComputedColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newComputedColumnNode(p))
	})
	return ret
}

func (n *CreateFunctionStmtNode) SetAggregateExpressionList(v []*ComputedColumnNode) {
	internal.ResolvedCreateFunctionStmt_set_aggregate_expression_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateFunctionStmtNode) AddAggregateExpression(v *ComputedColumnNode) {
	internal.ResolvedCreateFunctionStmt_add_aggregate_expression_list(n.raw, v.getRaw())
}

func (n *CreateFunctionStmtNode) FunctionExpression() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCreateFunctionStmt_function_expression(n.raw, &v)
	return newExprNode(v)
}

func (n *CreateFunctionStmtNode) SetFunctionExpression(v ExprNode) {
	internal.ResolvedCreateFunctionStmt_set_function_expression(n.raw, v.getRaw())
}

func (n *CreateFunctionStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateFunctionStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *CreateFunctionStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedCreateFunctionStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateFunctionStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedCreateFunctionStmt_add_option_list(n.raw, v.getRaw())
}

func (n *CreateFunctionStmtNode) SQLSecurity() SQLSecurity {
	var v int
	internal.ResolvedCreateFunctionStmt_sql_security(n.raw, &v)
	return SQLSecurity(v)
}

func (n *CreateFunctionStmtNode) SetSQLSecurity(v SQLSecurity) {
	internal.ResolvedCreateFunctionStmt_set_sql_security(n.raw, int(v))
}

func (n *CreateFunctionStmtNode) DeterminismLevel() DeterminismLevel {
	var v int
	internal.ResolvedCreateFunctionStmt_determinism_level(n.raw, &v)
	return DeterminismLevel(v)
}

func (n *CreateFunctionStmtNode) SetDeterminismLevel(v DeterminismLevel) {
	internal.ResolvedCreateFunctionStmt_set_determinism_level(n.raw, int(v))
}

func (n *CreateFunctionStmtNode) IsRemote() bool {
	var v bool
	internal.ResolvedCreateFunctionStmt_is_remote(n.raw, &v)
	return v
}

func (n *CreateFunctionStmtNode) SetIsRemote(v bool) {
	internal.ResolvedCreateFunctionStmt_set_is_remote(n.raw, helper.BoolToInt(v))
}

func (n *CreateFunctionStmtNode) Connection() *ConnectionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateFunctionStmt_connection(n.raw, &v)
	return newConnectionNode(v)
}

func (n *CreateFunctionStmtNode) SetConnection(v *ConnectionNode) {
	internal.ResolvedCreateFunctionStmt_set_connection(n.raw, v.getRaw())
}

// ArgumentDefNode this represents an argument definition, e.g. in a function's argument
// list.
//
// <name> is the name of the argument; optional for DROP FUNCTION statements.
// <type> is the type of the argument.
// <argument_kind> indicates what kind of argument this is, including scalar
//         vs aggregate.  NOT_AGGREGATE means this is a non-aggregate
//         argument in an aggregate function, which can only passed constant
//         values only.
//
// NOTE: Statements that create functions now include a FunctionSignature
// directly, and an argument_name_list if applicable.  These completely
// describe the function signature, so the ArgumentDefNode list can
// be considered unnecessary and deprecated.
// TODO We could remove this node in the future.
type ArgumentDefNode struct {
	*BaseArgumentNode
}

func (n *ArgumentDefNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedArgumentDef_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *ArgumentDefNode) SetName(v string) {
	internal.ResolvedArgumentDef_set_name(n.raw, helper.StringToPtr(v))
}

func (n *ArgumentDefNode) Type() types.Type {
	var v unsafe.Pointer
	internal.ResolvedArgumentDef_type(n.raw, &v)
	return newType(v)
}

func (n *ArgumentDefNode) SetType(v types.Type) {
	internal.ResolvedArgumentDef_set_type(n.raw, getRawType(v))
}

func (n *ArgumentDefNode) ArgumentKind() ArgumentKind {
	var v int
	internal.ResolvedArgumentDef_argument_kind(n.raw, &v)
	return ArgumentKind(v)
}

func (n *ArgumentDefNode) SetArgumentKind(v ArgumentKind) {
	internal.ResolvedArgumentDef_set_argument_kind(n.raw, int(v))
}

// ArgumentRefNode this represents an argument reference, e.g. in a function's body.
// <name> is the name of the argument.
// <argument_kind> is the ArgumentKind from the ArgumentDefNode.
//         For scalar functions, this is always SCALAR.
//         For aggregate functions, it can be AGGREGATE or NOT_AGGREGATE.
//         If NOT_AGGREGATE, then this is a non-aggregate argument
//         to an aggregate function, which has one constant value
//         for the entire function call (over all rows in all groups).
//         (This is copied from the ArgumentDefNode for convenience.)
type ArgumentRefNode struct {
	*BaseExprNode
}

func (n *ArgumentRefNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedArgumentRef_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *ArgumentRefNode) SetName(v string) {
	internal.ResolvedArgumentRef_set_name(n.raw, helper.StringToPtr(v))
}

func (n *ArgumentRefNode) ArgumentKind() ArgumentKind {
	var v int
	internal.ResolvedArgumentRef_argument_kind(n.raw, &v)
	return ArgumentKind(v)
}

func (n *ArgumentRefNode) SetArgumentKind(v ArgumentKind) {
	internal.ResolvedArgumentRef_set_argument_kind(n.raw, int(v))
}

// CreateTableFunctionStmtNode this statement creates a user-defined table-valued function:
//   CREATE [TEMP] TABLE FUNCTION [IF NOT EXISTS]
//     <name_path> (<argument_name_list>)
//     [RETURNS <return_type>]
//     [OPTIONS (<option_list>)]
//     [LANGUAGE <language>]
//     [AS <code> | AS ( <query> )]
//
//   <argument_name_list> contains the names of the function arguments.
//   <signature> is the FunctionSignature of the created function, with all
//          options.  This can be used to create a Function to load into a
//          Catalog for future queries.
//   <option_list> has engine-specific directives for modifying functions.
//   <language> is the programming language used by the function. This field
//          is set to 'SQL' for SQL functions, to the language name specified
//          in the LANGUAGE clause if present, and to 'UNDECLARED' if both
//          the LANGUAGE clause and query are not present.
//   <code> is an optional string literal that contains the function
//          definition.  Some engines may allow this argument to be omitted
//          for certain types of external functions.  This will always be set
//          for SQL functions.
//   <query> is the SQL query invoked for the function.  This will be unset
//          for external language functions. For non-templated SQL functions,
//          this is a resolved representation of the query in <code>.
//   <output_column_list> is the list of resolved output
//          columns returned by the table-valued function.
//   <is_value_table> If true, this function returns a value table.
//          Rather than producing rows with named columns, it produces
//          rows with a single unnamed value type. <output_column_list> will
//          have exactly one anonymous column (with no name).
//          See (broken link).
//   <sql_security> is the declared security mode for the function. Values
//          include 'INVOKER', 'DEFINER'.
//   <has_explicit_return_schema> is true iff RETURNS clause is present.
//
// ----------------------
// Table-Valued Functions
// ----------------------
//
// This is a statement to create a new table-valued function. Each
// table-valued function returns an entire table as output instead of a
// single scalar value. Table-valued functions can only be created if
// LanguageOptions has FEATURE_CREATE_TABLE_FUNCTION enabled.
//
// For SQL table-valued functions that include a defined SQL body, the
// <query> is non-NULL and contains the resolved SQL body.
// In this case, <output_column_list> contains a list of the
// output columns of the SQL body. The <query> uses
// ArgumentRefNodes to refer to scalar arguments and
// RelationArgumentScanNodes to refer to relation arguments.
//
// The table-valued function may include RETURNS TABLE<...> to explicitly
// specify a schema for the output table returned by the function. If the
// function declaration includes a SQL body, then the names and types of the
// output columns of the corresponding <query> will have been
// coerced to exactly match 1:1 with the names and types of the columns
// specified in the RETURNS TABLE<...> section.
//
// When resolving a query that calls a table-valued function, the query will
// have a TVFScanNode that invokes the function.
//
// Value tables: If the function declaration includes a value-table
// parameter, this is written as an argument of type "TABLE" where the table
// contains a single anonymous column with a type but no name. In this case,
// calls to the function may pass a (regular or value) table with a single
// (named or unnamed) column for any of these parameters, and ZetaSQL
// accepts these arguments as long as the column type matches.
//
// Similarly, if the CREATE TABLE FUNCTION statement includes a "RETURNS
// TABLE" section with a single column with no name, then this defines a
// value-table return type. The function then returns a value table as long
// as the SQL body returns a single column whose type matches (independent of
// whether the SQL body result is a value table or not, and whether the
// returned column is named or unnamed).
//
// --------------------------------
// Templated Table-Valued Functions
// --------------------------------
//
// ZetaSQL supports table-valued function declarations with parameters of
// type ANY TABLE. This type indicates that any schema is valid for tables
// passed for this parameter. In this case:
//
// * the IsTemplated() method of the <signature> field returns true,
// * the <output_column_list> field is empty,
// * the <is_value_table> field is set to a default value of false (since
//   ZetaSQL cannot analyze the function body in the presence of templated
//   parameters, it is not possible to detect this property yet),
//
// TODO: Update this description once ZetaSQL supports more types
// of templated function parameters. Currently only ANY TABLE is supported.
type CreateTableFunctionStmtNode struct {
	*BaseCreateStatementNode
}

func NewCreateTableFunctionStmtNode(
	namePath []string,
	scope CreateScope,
	mode CreateMode,
	argumentNameList []string,
	signature *types.FunctionSignature,
	hasExplicitReturnSchema bool,
	optionList []*OptionNode,
	language string,
	code string,
	query ScanNode,
	outputColumnList []*OutputColumnNode,
	isValueTable bool,
	sqlSecurity SQLSecurity) *CreateTableFunctionStmtNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableFunctionStmt_new(
		helper.StringsToPtr(namePath),
		int(scope),
		int(mode),
		helper.StringsToPtr(argumentNameList),
		getRawFunctionSignature(signature),
		helper.BoolToInt(hasExplicitReturnSchema),
		helper.SliceToPtr(optionList, func(idx int) unsafe.Pointer {
			return optionList[idx].getRaw()
		}),
		helper.StringToPtr(language),
		helper.StringToPtr(code),
		query.getRaw(),
		helper.SliceToPtr(outputColumnList, func(idx int) unsafe.Pointer {
			return outputColumnList[idx].getRaw()
		}),
		helper.BoolToInt(isValueTable),
		int(sqlSecurity),
		&v,
	)
	return newCreateTableFunctionStmtNode(v)
}

func (n *CreateTableFunctionStmtNode) ArgumentNameList() []string {
	var v unsafe.Pointer
	internal.ResolvedCreateTableFunctionStmt_argument_name_list(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *CreateTableFunctionStmtNode) SetArgumentNameList(v []string) {
	internal.ResolvedCreateTableFunctionStmt_set_argument_name_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *CreateTableFunctionStmtNode) AddArgumentName(v string) {
	internal.ResolvedCreateTableFunctionStmt_add_argument_name_list(n.raw, helper.StringToPtr(v))
}

func (n *CreateTableFunctionStmtNode) Signature() *types.FunctionSignature {
	var v unsafe.Pointer
	internal.ResolvedCreateTableFunctionStmt_signature(n.raw, &v)
	return newFunctionSignature(v)
}

func (n *CreateTableFunctionStmtNode) SetSignature(v *types.FunctionSignature) {
	internal.ResolvedCreateTableFunctionStmt_set_signature(n.raw, getRawFunctionSignature(v))
}

func (n *CreateTableFunctionStmtNode) HasExplicitReturnSchema() bool {
	var v bool
	internal.ResolvedCreateTableFunctionStmt_has_explicit_return_schema(n.raw, &v)
	return v
}

func (n *CreateTableFunctionStmtNode) SetHasExplicitReturnSchema(v bool) {
	internal.ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema(n.raw, helper.BoolToInt(v))
}

func (n *CreateTableFunctionStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableFunctionStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *CreateTableFunctionStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedCreateTableFunctionStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateTableFunctionStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedCreateTableFunctionStmt_add_option_list(n.raw, v.getRaw())
}

func (n *CreateTableFunctionStmtNode) Language() string {
	var v unsafe.Pointer
	internal.ResolvedCreateTableFunctionStmt_language(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *CreateTableFunctionStmtNode) SetLanguage(v string) {
	internal.ResolvedCreateTableFunctionStmt_set_language(n.raw, helper.StringToPtr(v))
}

func (n *CreateTableFunctionStmtNode) Code() string {
	var v unsafe.Pointer
	internal.ResolvedCreateTableFunctionStmt_code(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *CreateTableFunctionStmtNode) SetCode(v string) {
	internal.ResolvedCreateTableFunctionStmt_set_code(n.raw, helper.StringToPtr(v))
}

func (n *CreateTableFunctionStmtNode) Query() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableFunctionStmt_query(n.raw, &v)
	return newScanNode(v)
}

func (n *CreateTableFunctionStmtNode) SetQuery(v ScanNode) {
	internal.ResolvedCreateTableFunctionStmt_set_query(n.raw, v.getRaw())
}

func (n *CreateTableFunctionStmtNode) OutputColumnList() []*OutputColumnNode {
	var v unsafe.Pointer
	internal.ResolvedCreateTableFunctionStmt_output_column_list(n.raw, &v)
	var ret []*OutputColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOutputColumnNode(p))
	})
	return ret
}

func (n *CreateTableFunctionStmtNode) SetOutputColumnList(v []*OutputColumnNode) {
	internal.ResolvedCreateTableFunctionStmt_set_output_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateTableFunctionStmtNode) AddOutputColumn(v *OutputColumnNode) {
	internal.ResolvedCreateTableFunctionStmt_add_output_column_list(n.raw, v.getRaw())
}

func (n *CreateTableFunctionStmtNode) IsValueTable() bool {
	var v bool
	internal.ResolvedCreateTableFunctionStmt_is_value_table(n.raw, &v)
	return v
}

func (n *CreateTableFunctionStmtNode) SetIsValueTable(v bool) {
	internal.ResolvedCreateTableFunctionStmt_set_is_value_table(n.raw, helper.BoolToInt(v))
}

func (n *CreateTableFunctionStmtNode) SQLSecurity() SQLSecurity {
	var v int
	internal.ResolvedCreateTableFunctionStmt_sql_security(n.raw, &v)
	return SQLSecurity(v)
}

func (n *CreateTableFunctionStmtNode) SetSQLSecurity(v SQLSecurity) {
	internal.ResolvedCreateTableFunctionStmt_set_sql_security(n.raw, int(v))
}

// RelationArgumentScanNode this represents a relation argument reference in a table-valued function's body.
// The 'column_list' of this ScanNode includes column names from
// the relation argument in the table-valued function signature.
type RelationArgumentScanNode struct {
	*BaseScanNode
}

// Name this is the name of the relation argument for the table-valued
// function.  It is used to match this relation argument reference in
// a TVF SQL function body with one of possibly several relation
// arguments in the TVF call.
func (n *RelationArgumentScanNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedRelationArgumentScan_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *RelationArgumentScanNode) SetName(v string) {
	internal.ResolvedRelationArgumentScan_set_name(n.raw, helper.StringToPtr(v))
}

// IsValueTable if true, the result of this query is a value table. Rather than
// producing rows with named columns, it produces rows with a single
// unnamed value type.
func (n *RelationArgumentScanNode) IsValueTable() bool {
	var v bool
	internal.ResolvedRelationArgumentScan_is_value_table(n.raw, &v)
	return v
}

func (n *RelationArgumentScanNode) SetIsValueTable(v bool) {
	internal.ResolvedRelationArgumentScan_set_is_value_table(n.raw, helper.BoolToInt(v))
}

// ArgumentListNode this statement: [ (<arg_list>) ];
//
// <arg_list> is an optional list of parameters.  If given, each parameter
//            may consist of a type, or a name and a type.
//
// NOTE: This can be considered deprecated in favor of the FunctionSignature
//       stored directly in the statement.
//
// NOTE: ArgumentListNode is not related to the ArgumentNode,
//       which just exists to organize node classes.
type ArgumentListNode struct {
	*BaseArgumentNode
}

func (n *ArgumentListNode) ArgList() []*ArgumentDefNode {
	var v unsafe.Pointer
	internal.ResolvedArgumentList_arg_list(n.raw, &v)
	var ret []*ArgumentDefNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newArgumentDefNode(p))
	})
	return ret
}

func (n *ArgumentListNode) SetArgList(v []*ArgumentDefNode) {
	internal.ResolvedArgumentList_set_arg_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *ArgumentListNode) AddArg(v *ArgumentDefNode) {
	internal.ResolvedArgumentList_add_arg_list(n.raw, v.getRaw())
}

// FunctionSignatureHolderNode this wrapper is used for an optional FunctionSignature.
type FunctionSignatureHolderNode struct {
	*BaseArgumentNode
}

func (n *FunctionSignatureHolderNode) Signature() *types.FunctionSignature {
	var v unsafe.Pointer
	internal.ResolvedFunctionSignatureHolder_signature(n.raw, &v)
	return newFunctionSignature(v)
}

func (n *FunctionSignatureHolderNode) SetSignature(v *types.FunctionSignature) {
	internal.ResolvedFunctionSignatureHolder_set_signature(n.raw, getRawFunctionSignature(v))
}

// DropFunctionStmtNode this statement: DROP FUNCTION [IF EXISTS] <name_path>
//   [ (<arguments>) ];
//
// <is_if_exists> silently ignore the "name_path does not exist" error.
// <name_path> is the identifier path of the function to be dropped.
// <arguments> is an optional list of parameters.  If given, each parameter
//            may consist of a type, or a name and a type.  The name is
//            disregarded, and is allowed to permit copy-paste from CREATE
//            FUNCTION statements.
// <signature> is the signature of the dropped function.  Argument names and
//            argument options are ignored because only the types matter
//            for matching signatures in DROP FUNCTION.  The return type
//            in this signature will always be <void>, since return type
//            is ignored when matching signatures for DROP.
//            TODO <arguments> could be deprecated in favor of this.
type DropFunctionStmtNode struct {
	*BaseStatementNode
}

func (n *DropFunctionStmtNode) IsIfExists() bool {
	var v bool
	internal.ResolvedDropFunctionStmt_is_if_exists(n.raw, &v)
	return v
}

func (n *DropFunctionStmtNode) SetIsIfExists(v bool) {
	internal.ResolvedDropFunctionStmt_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

func (n *DropFunctionStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedDropFunctionStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *DropFunctionStmtNode) SetNamePath(v []string) {
	internal.ResolvedDropFunctionStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *DropFunctionStmtNode) AddNamePath(v string) {
	internal.ResolvedDropFunctionStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

// Arguments
// NOTE: arguments for DROP FUNCTION statements are matched only on
// type; names for any arguments in ResolvedArgumentList will be set
// to the empty string irrespective of whether or not argument names
// were given in the DROP FUNCTION statement.
func (n *DropFunctionStmtNode) Arguments() *ArgumentListNode {
	var v unsafe.Pointer
	internal.ResolvedDropFunctionStmt_arguments(n.raw, &v)
	return newArgumentListNode(v)
}

func (n *DropFunctionStmtNode) SetArguments(v *ArgumentListNode) {
	internal.ResolvedDropFunctionStmt_set_arguments(n.raw, v.getRaw())
}

// Signature
// NOTE: arguments for DROP FUNCTION statements are matched only on
// type; names are irrelevant, so no argument names are saved to use
// with this signature.  Additionally, the return type will always be
// <void>, since return types are ignored for DROP FUNCTION.
func (n *DropFunctionStmtNode) Signature() *FunctionSignatureHolderNode {
	var v unsafe.Pointer
	internal.ResolvedDropFunctionStmt_signature(n.raw, &v)
	return newFunctionSignatureHolderNode(v)
}

func (n *DropFunctionStmtNode) SetSignature(v *FunctionSignatureHolderNode) {
	internal.ResolvedDropFunctionStmt_set_signature(n.raw, v.getRaw())
}

// DropTableFunctionStmtNode this statement: DROP TABLE FUNCTION [IF EXISTS] <name_path>;
//
// <is_if_exists> silently ignore the "name_path does not exist" error.
// <name_path> is the identifier path of the function to be dropped.
type DropTableFunctionStmtNode struct {
	*BaseStatementNode
}

func (n *DropTableFunctionStmtNode) IsIfExists() bool {
	var v bool
	internal.ResolvedDropTableFunctionStmt_is_if_exists(n.raw, &v)
	return v
}

func (n *DropTableFunctionStmtNode) SetIsIfExists(v bool) {
	internal.ResolvedDropTableFunctionStmt_set_is_if_exists(n.raw, helper.BoolToInt(v))
}

func (n *DropTableFunctionStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedDropTableFunctionStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *DropTableFunctionStmtNode) SetNamePath(v []string) {
	internal.ResolvedDropTableFunctionStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *DropTableFunctionStmtNode) AddNamePath(v string) {
	internal.ResolvedDropTableFunctionStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

// CallStmtNode this statement: CALL <procedure>;
//
// <procedure> Procedure to call.
// <signature> Resolved FunctionSignature for this procedure.
// <argument_list> Procedure arguments.
type CallStmtNode struct {
	*BaseStatementNode
}

func (n *CallStmtNode) Procedure() types.Procedure {
	var v unsafe.Pointer
	internal.ResolvedCallStmt_procedure(n.raw, &v)
	return newProcedure(v)
}

func (n *CallStmtNode) SetProcedure(v types.Procedure) {
	internal.ResolvedCallStmt_set_procedure(n.raw, getRawProcedure(v))
}

func (n *CallStmtNode) Signature() *types.FunctionSignature {
	var v unsafe.Pointer
	internal.ResolvedCallStmt_signature(n.raw, &v)
	return newFunctionSignature(v)
}

func (n *CallStmtNode) SetSignature(v *types.FunctionSignature) {
	internal.ResolvedCallStmt_set_signature(n.raw, getRawFunctionSignature(v))
}

func (n *CallStmtNode) ArgumentList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCallStmt_argument_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *CallStmtNode) SetArgumentList(v []ExprNode) {
	internal.ResolvedCallStmt_set_argument_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CallStmtNode) AddArgument(v ExprNode) {
	internal.ResolvedCallStmt_add_argument_list(n.raw, v.getRaw())
}

// ImportStmtNode this statement: IMPORT <import_kind>
//                              [<name_path> [AS|INTO <alias_path>]
//                              |<file_path>]
//                        [<option_list>];
//
// <import_kind> The type of the object, currently supports MODULE and PROTO.
// <name_path>   The identifier path of the object to import, e.g., foo.bar,
//               used in IMPORT MODULE statement.
// <file_path>   The file path of the object to import, e.g., "file.proto",
//               used in IMPORT PROTO statement.
// <alias_path>  The AS alias path for the object.
// <into_alias_path>  The INTO alias path for the object.
// <option_list> Engine-specific directives for the import.
//
// Either <name_path> or <file_path> will be populated but not both.
//       <name_path> will be populated for IMPORT MODULE.
//       <file_path> will be populated for IMPORT PROTO.
//
// At most one of <alias_path> or <into_alias_path> will be populated.
//       <alias_path> may be populated for IMPORT MODULE.
//       <into_alias_path> may be populated for IMPORT PROTO.
//
// IMPORT MODULE and IMPORT PROTO both support options.
type ImportStmtNode struct {
	*BaseStatementNode
}

func (n *ImportStmtNode) ImportKind() ImportKind {
	var v int
	internal.ResolvedImportStmt_import_kind(n.raw, &v)
	return ImportKind(v)
}

func (n *ImportStmtNode) SetImportKind(v ImportKind) {
	internal.ResolvedImportStmt_set_import_kind(n.raw, int(v))
}

func (n *ImportStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedImportStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *ImportStmtNode) SetNamePath(v []string) {
	internal.ResolvedImportStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *ImportStmtNode) AddNamePath(v string) {
	internal.ResolvedImportStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

func (n *ImportStmtNode) FilePath() string {
	var v unsafe.Pointer
	internal.ResolvedImportStmt_file_path(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *ImportStmtNode) SetFilePath(v string) {
	internal.ResolvedImportStmt_set_file_path(n.raw, helper.StringToPtr(v))
}

func (n *ImportStmtNode) AliasPath() []string {
	var v unsafe.Pointer
	internal.ResolvedImportStmt_alias_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *ImportStmtNode) SetAliasPath(v []string) {
	internal.ResolvedImportStmt_set_alias_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *ImportStmtNode) AddAliasPath(v string) {
	internal.ResolvedImportStmt_add_alias_path(n.raw, helper.StringToPtr(v))
}

func (n *ImportStmtNode) IntoAliasPath() []string {
	var v unsafe.Pointer
	internal.ResolvedImportStmt_into_alias_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *ImportStmtNode) SetIntoAliasPath(v []string) {
	internal.ResolvedImportStmt_set_into_alias_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *ImportStmtNode) AddIntoAliasPath(v string) {
	internal.ResolvedImportStmt_add_into_alias_path(n.raw, helper.StringToPtr(v))
}

func (n *ImportStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedImportStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *ImportStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedImportStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *ImportStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedImportStmt_add_option_list(n.raw, v.getRaw())
}

// ModuleStmtNode this statement: MODULE <name_path> [<option_list>];
//
// <name_path> is the identifier path of the module.
// <option_list> Engine-specific directives for the module statement.
type ModuleStmtNode struct {
	*BaseStatementNode
}

func (n *ModuleStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedModuleStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *ModuleStmtNode) SetNamePath(v []string) {
	internal.ResolvedModuleStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *ModuleStmtNode) AddNamePath(v string) {
	internal.ResolvedModuleStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

func (n *ModuleStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedModuleStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *ModuleStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedModuleStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *ModuleStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedModuleStmt_add_option_list(n.raw, v.getRaw())
}

// AggregateHavingModifierNode this represents a HAVING MAX or HAVING MIN modifier in an aggregate
// expression. If an aggregate has arguments (x HAVING {MAX/MIN} y),
// the aggregate will be computed over only the x values in the rows with the
// maximal/minimal values of y.
//
// <kind> the MAX/MIN kind of this HAVING
// <having_expr> the HAVING expression (y in the above example)
type AggregateHavingModifierNode struct {
	*BaseArgumentNode
}

func (n *AggregateHavingModifierNode) ModifierKind() HavingModifierKind {
	var v int
	internal.ResolvedAggregateHavingModifier_kind(n.raw, &v)
	return HavingModifierKind(v)
}

func (n *AggregateHavingModifierNode) SetModifierKind(v HavingModifierKind) {
	internal.ResolvedAggregateHavingModifier_set_kind(n.raw, int(v))
}

func (n *AggregateHavingModifierNode) HavingExpr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedAggregateHavingModifier_having_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *AggregateHavingModifierNode) SetHavingExpr(v ExprNode) {
	internal.ResolvedAggregateHavingModifier_set_having_expr(n.raw, v.getRaw())
}

// CreateMaterializedViewStmtNode this statement:
//   CREATE MATERIALIZED VIEW <name> [(...)] [PARTITION BY expr, ...]
//   [CLUSTER BY expr, ...] [OPTIONS (...)] AS SELECT ...
//
// <column_definition_list> matches 1:1 with the <output_column_list> in
// BaseCreateViewNode and provides explicit definition for each
// Column produced by <query>. Output column names and types must
// match column definition names and types. If the table is a value table,
// <column_definition_list> must have exactly one column, with a generated
// name such as "$struct".
//
// Currently <column_definition_list> contains the same schema information
// (column names and types) as <output_definition_list>, but when/if we
// allow specifying column OPTIONS as part of CMV statement, this information
// will be available only in <column_definition_list>. Therefore, consumers
// are encouraged to read from <column_definition_list> rather than from
// <output_column_list> to determine the schema, if possible.
//
// <partition_by_list> specifies the partitioning expressions for the
//                     materialized view.
// <cluster_by_list> specifies the clustering expressions for the
//                   materialized view.
type CreateMaterializedViewStmtNode struct {
	*BaseCreateViewNode
}

func (n *CreateMaterializedViewStmtNode) ColumnDefinitionList() []*ColumnDefinitionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateMaterializedViewStmt_column_definition_list(n.raw, &v)
	var ret []*ColumnDefinitionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumnDefinitionNode(p))
	})
	return ret
}

func (n *CreateMaterializedViewStmtNode) SetColumnDefinitionList(v []*ColumnDefinitionNode) {
	internal.ResolvedCreateMaterializedViewStmt_set_column_definition_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateMaterializedViewStmtNode) AddColumnDefinition(v *ColumnDefinitionNode) {
	internal.ResolvedCreateMaterializedViewStmt_add_column_definition_list(n.raw, v.getRaw())
}

func (n *CreateMaterializedViewStmtNode) PartitionByList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCreateMaterializedViewStmt_partition_by_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *CreateMaterializedViewStmtNode) SetPartitionByList(v []ExprNode) {
	internal.ResolvedCreateMaterializedViewStmt_set_partition_by_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateMaterializedViewStmtNode) AddPartitionBy(v ExprNode) {
	internal.ResolvedCreateMaterializedViewStmt_add_partition_by_list(n.raw, v.getRaw())
}

func (n *CreateMaterializedViewStmtNode) ClusterByList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedCreateMaterializedViewStmt_cluster_by_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *CreateMaterializedViewStmtNode) SetClusterByList(v []ExprNode) {
	internal.ResolvedCreateMaterializedViewStmt_set_cluster_by_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateMaterializedViewStmtNode) AddClusterBy(v ExprNode) {
	internal.ResolvedCreateMaterializedViewStmt_add_cluster_by_list(n.raw, v.getRaw())
}

// CreateProcedureStmtNode this statement creates a user-defined procedure:
// CREATE [OR REPLACE] [TEMP] PROCEDURE [IF NOT EXISTS] <name_path>
// (<arg_list>) [OPTIONS (<option_list>)]
// BEGIN
// <procedure_body>
// END;
//
// <name_path> is the identifier path of the procedure.
// <argument_name_list> The names of the function arguments.
// <signature> is the FunctionSignature of the created procedure, with all
//        options.  This can be used to create a procedure to load into a
//        Catalog for future queries.
// <option_list> has engine-specific directives for modifying procedures.
// <procedure_body> is a string literal that contains the procedure body.
//        It includes everything from the BEGIN keyword to the END keyword,
//        inclusive.
//
//        The resolver will perform some basic validation on the procedure
//        body, for example, verifying that DECLARE statements are in the
//        proper position, and that variables are not declared more than
//        once, but any validation that requires the catalog (including
//        generating resolved tree nodes for individual statements) is
//        deferred until the procedure is actually called.  This deferral
//        makes it possible to define a procedure which references a table
//        or routine that does not yet exist, so long as the entity is
//        created before the procedure is called.
type CreateProcedureStmtNode struct {
	*BaseCreateStatementNode
}

func (n *CreateProcedureStmtNode) ArgumentNameList() []string {
	var v unsafe.Pointer
	internal.ResolvedCreateProcedureStmt_argument_name_list(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *CreateProcedureStmtNode) SetArgumentNameList(v []string) {
	internal.ResolvedCreateProcedureStmt_set_argument_name_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *CreateProcedureStmtNode) AddArgumentName(v string) {
	internal.ResolvedCreateProcedureStmt_add_argument_name_list(n.raw, helper.StringToPtr(v))
}

func (n *CreateProcedureStmtNode) Signature() *types.FunctionSignature {
	var v unsafe.Pointer
	internal.ResolvedCreateProcedureStmt_signature(n.raw, &v)
	return newFunctionSignature(v)
}

func (n *CreateProcedureStmtNode) SetSignature(v *types.FunctionSignature) {
	internal.ResolvedCreateProcedureStmt_set_signature(n.raw, getRawFunctionSignature(v))
}

func (n *CreateProcedureStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateProcedureStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *CreateProcedureStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedCreateProcedureStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateProcedureStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedCreateProcedureStmt_add_option_list(n.raw, v.getRaw())
}

func (n *CreateProcedureStmtNode) ProcedureBody() string {
	var v unsafe.Pointer
	internal.ResolvedCreateProcedureStmt_procedure_body(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *CreateProcedureStmtNode) SetProcedureBody(v string) {
	internal.ResolvedCreateProcedureStmt_set_procedure_body(n.raw, helper.StringToPtr(v))
}

// ExecuteImmediateArgumentNode an argument for an EXECUTE IMMEDIATE's USING clause.
//
// <name> an optional name for this expression
// <expression> the expression's value
type ExecuteImmediateArgumentNode struct {
	*BaseArgumentNode
}

func (n *ExecuteImmediateArgumentNode) Name() string {
	var v unsafe.Pointer
	internal.ResolvedExecuteImmediateArgument_name(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *ExecuteImmediateArgumentNode) SetName(v string) {
	internal.ResolvedExecuteImmediateArgument_set_name(n.raw, helper.StringToPtr(v))
}

func (n *ExecuteImmediateArgumentNode) Expression() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedExecuteImmediateArgument_expression(n.raw, &v)
	return newExprNode(v)
}

func (n *ExecuteImmediateArgumentNode) SetExpression(v ExprNode) {
	internal.ResolvedExecuteImmediateArgument_set_expression(n.raw, v.getRaw())
}

// ExecuteImmediateStmtNode an EXECUTE IMMEDIATE statement
// EXECUTE IMMEDIATE <sql> [<into_clause>] [<using_clause>]
//
// <sql> a string expression indicating a SQL statement to be dynamically
//   executed
// <into_identifier_list> the identifiers whose values should be set.
//   Identifiers should not be repeated in the list.
// <using_argument_list> a list of arguments to supply for dynamic SQL.
//    The arguments should either be all named or all unnamed, and
//    arguments should not be repeated in the list.
type ExecuteImmediateStmtNode struct {
	*BaseStatementNode
}

func (n *ExecuteImmediateStmtNode) SQL() string {
	var v unsafe.Pointer
	internal.ResolvedExecuteImmediateStmt_sql(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *ExecuteImmediateStmtNode) SetSQL(v string) {
	internal.ResolvedExecuteImmediateStmt_set_sql(n.raw, helper.StringToPtr(v))
}

func (n *ExecuteImmediateStmtNode) IntoIdentifierList() []string {
	var v unsafe.Pointer
	internal.ResolvedExecuteImmediateStmt_into_identifier_list(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *ExecuteImmediateStmtNode) SetIntoIdentifierList(v []string) {
	internal.ResolvedExecuteImmediateStmt_set_into_identifier_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *ExecuteImmediateStmtNode) AddIntoIdentifier(v string) {
	internal.ResolvedExecuteImmediateStmt_add_into_identifier_list(n.raw, helper.StringToPtr(v))
}

func (n *ExecuteImmediateStmtNode) UsingArgumentList() []*ExecuteImmediateArgumentNode {
	var v unsafe.Pointer
	internal.ResolvedExecuteImmediateStmt_using_argument_list(n.raw, &v)
	var ret []*ExecuteImmediateArgumentNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExecuteImmediateArgumentNode(p))
	})
	return ret
}

func (n *ExecuteImmediateStmtNode) SetUsingArgumentList(v []*ExecuteImmediateArgumentNode) {
	internal.ResolvedExecuteImmediateStmt_set_using_argument_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *ExecuteImmediateStmtNode) AddUsingArgument(v *ExecuteImmediateArgumentNode) {
	internal.ResolvedExecuteImmediateStmt_add_using_argument_list(n.raw, v.getRaw())
}

// AssignmentStmtNode an assignment of a value to another value.
type AssignmentStmtNode struct {
	*BaseStatementNode
}

// Target target of the assignment.
// currently, this will be either SystemVariableNode, or a chain of GetFieldNode operations around it.
func (n *AssignmentStmtNode) Target() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedAssignmentStmt_target(n.raw, &v)
	return newExprNode(v)
}

func (n *AssignmentStmtNode) SetTarget(v ExprNode) {
	internal.ResolvedAssignmentStmt_set_target(n.raw, v.getRaw())
}

// Expr value to assign into the target.
// This will always be the same type as the target.
func (n *AssignmentStmtNode) Expr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedAssignmentStmt_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *AssignmentStmtNode) SetExpr(v ExprNode) {
	internal.ResolvedAssignmentStmt_set_expr(n.raw, v.getRaw())
}

// CreateEntityStmtNode this statement:
// CREATE [OR REPLACE] <entity_type> [IF NOT EXISTS] <path_expression>
// [OPTIONS <option_list>]
// [AS <entity_body_json>];
//
// At most one of <entity_body_json>, <entity_body_text> can be non-empty.
//
// <entity_type> engine-specific entity type to be created.
// <entity_body_json> is a JSON literal to be interpreted by engine.
// <entity_body_text> is a text literal to be interpreted by engine.
// <option_list> has engine-specific directives for how to
//               create this entity.
type CreateEntityStmtNode struct {
	*BaseCreateStatementNode
}

func (n *CreateEntityStmtNode) EntityType() string {
	var v unsafe.Pointer
	internal.ResolvedCreateEntityStmt_entity_type(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *CreateEntityStmtNode) SetEntityType(v string) {
	internal.ResolvedCreateEntityStmt_set_entity_type(n.raw, helper.StringToPtr(v))
}

func (n *CreateEntityStmtNode) EntityBodyJSON() string {
	var v unsafe.Pointer
	internal.ResolvedCreateEntityStmt_entity_body_json(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *CreateEntityStmtNode) SetEntityBodyJSON(v string) {
	internal.ResolvedCreateEntityStmt_set_entity_body_json(n.raw, helper.StringToPtr(v))
}

func (n *CreateEntityStmtNode) EntityBodyText() string {
	var v unsafe.Pointer
	internal.ResolvedCreateEntityStmt_entity_body_text(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *CreateEntityStmtNode) SetEntityBodyText(v string) {
	internal.ResolvedCreateEntityStmt_set_entity_body_text(n.raw, helper.StringToPtr(v))
}

func (n *CreateEntityStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedCreateEntityStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *CreateEntityStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedCreateEntityStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *CreateEntityStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedCreateEntityStmt_add_option_list(n.raw, v.getRaw())
}

// AlterEntityStmtNode this statement:
// ALTER <entity_type> [IF EXISTS]  <path_expression>
// <generic_alter_action>, ...
//
// <entity_type> engine-specific entity type to be altered.
type AlterEntityStmtNode struct {
	*AlterObjectStmtNode
}

func (n *AlterEntityStmtNode) EntityType() string {
	var v unsafe.Pointer
	internal.ResolvedAlterEntityStmt_entity_type(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *AlterEntityStmtNode) SetEntityType(v string) {
	internal.ResolvedAlterEntityStmt_set_entity_type(n.raw, helper.StringToPtr(v))
}

// PivotColumnNode represents a column produced by aggregating a particular pivot
// expression over a subset of the input for which the FOR expression
// matches a particular pivot value. This aggregation is further
// broken up by the enclosing PivotScanNode's groupby columns,
// with each distinct value of the groupby columns producing a
// separate row in the output.
//
// In any pivot column, 'c',
// 'c' is produced by aggregating pivot expression
//   <pivot_expr_list[c.pivot_expr_index]>
// over input rows such that
//   <for_expr> IS NOT DISTINCT FROM
//   <pivot_value_list[c.pivot_value_index]>
type PivotColumnNode struct {
	*BaseArgumentNode
}

// Column the output column used to represent the result of the pivot.
func (n *PivotColumnNode) Column() *Column {
	var v unsafe.Pointer
	internal.ResolvedPivotColumn_column(n.raw, &v)
	return newColumn(v)
}

func (n *PivotColumnNode) SetColumn(v *Column) {
	internal.ResolvedPivotColumn_set_column(n.raw, v.raw)
}

// PivotExprIndex specifies the index of the pivot expression
// within the enclosing PivotScanNode's <pivot_expr_list> used to
// determine the result of the column.
func (n *PivotColumnNode) PivotExprIndex() int {
	var v int
	internal.ResolvedPivotColumn_pivot_expr_index(n.raw, &v)
	return v
}

func (n *PivotColumnNode) SetPivotExprIndex(v int) {
	internal.ResolvedPivotColumn_set_pivot_expr_index(n.raw, v)
}

// PivotValueIndex specifies the index of the pivot value within
// the enclosing PivotScanNode's <pivot_value_list> used to
// determine the subset of input rows the pivot expression should be
// evaluated over.
func (n *PivotColumnNode) PivotValueIndex() int {
	var v int
	internal.ResolvedPivotColumn_pivot_value_index(n.raw, &v)
	return v
}

func (n *PivotColumnNode) SetPivotValueIndex(v int) {
	internal.ResolvedPivotColumn_set_pivot_value_index(n.raw, v)
}

// PivotScanNode a scan produced by the following SQL fragment:
//   <input_scan> PIVOT(... FOR ... IN (...))
//
// The column list of this scan consists of a subset of columns from
// <group_by_column_list> and <pivot_column_list>.
type PivotScanNode struct {
	*BaseScanNode
}

// InputScan input to the PIVOT clause.
func (n *PivotScanNode) InputScan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedPivotScan_input_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *PivotScanNode) SetInputScan(v ScanNode) {
	internal.ResolvedPivotScan_set_input_scan(n.raw, v.getRaw())
}

// GroupByList the columns from <input_scan> to group by.
// The output will have one row for each distinct combination of
// values for all grouping columns. (There will be one output row if
// this list is empty.)
//
// Each element is a ComputedColumnNode. The expression is always
// a ColumnRefNode that references a column from <input_scan>.
func (n *PivotScanNode) GroupByList() []*ComputedColumnNode {
	var v unsafe.Pointer
	internal.ResolvedPivotScan_group_by_list(n.raw, &v)
	var ret []*ComputedColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newComputedColumnNode(p))
	})
	return ret
}

func (n *PivotScanNode) SetGroupByList(v []*ComputedColumnNode) {
	internal.ResolvedPivotScan_set_group_by_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *PivotScanNode) AddGroupBy(v *ComputedColumnNode) {
	internal.ResolvedPivotScan_add_group_by_list(n.raw, v.getRaw())
}

// PivotExprList pivot expressions which aggregate over the subset of <input_scan>
// where <for_expr> matches each value in <pivot_value_list>, plus
// all columns in <group_by_list>.
func (n *PivotScanNode) PivotExprList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedPivotScan_pivot_expr_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *PivotScanNode) SetPivotExprList(v []ExprNode) {
	internal.ResolvedPivotScan_set_pivot_expr_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *PivotScanNode) AddPivotExpr(v ExprNode) {
	internal.ResolvedPivotScan_add_pivot_expr_list(n.raw, v.getRaw())
}

// ForExpr expression following the FOR keyword, to be evaluated over each row
// in <input_scan>. This value is compared with each value in
// <pivot_value_list> to determine which columns the aggregation
// results of <pivot_expr_list> should go to.
func (n *PivotScanNode) ForExpr() ExprNode {
	var v unsafe.Pointer
	internal.ResolvedPivotScan_for_expr(n.raw, &v)
	return newExprNode(v)
}

func (n *PivotScanNode) SetForExpr(v ExprNode) {
	internal.ResolvedPivotScan_set_for_expr(n.raw, v.getRaw())
}

// PivotValueList a list of pivot values within the IN list, to be compared against
// the result of <for_expr> for each row in the input table. Each
// pivot value generates a distinct column in the output for each
// pivot expression, representing the result of the corresponding
// pivot expression over the subset of input where <for_expr> matches
// this pivot value.
//
// All pivot values in this list must have the same type as
// <for_expr> and must be constant.
func (n *PivotScanNode) PivotValueList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedPivotScan_pivot_value_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *PivotScanNode) SetPivotValueList(v []ExprNode) {
	internal.ResolvedPivotScan_set_pivot_value_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *PivotScanNode) AddPivotValue(v ExprNode) {
	internal.ResolvedPivotScan_add_pivot_value_list(n.raw, v.getRaw())
}

// PivotColumnList list of columns created to store the output pivot columns.
// Each is computed using one of pivot_expr_list and one of
// pivot_value_list.
func (n *PivotScanNode) PivotColumnList() []*PivotColumnNode {
	var v unsafe.Pointer
	internal.ResolvedPivotScan_pivot_column_list(n.raw, &v)
	var ret []*PivotColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newPivotColumnNode(p))
	})
	return ret
}

func (n *PivotScanNode) SetPivotColumnList(v []*PivotColumnNode) {
	internal.ResolvedPivotScan_set_pivot_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *PivotScanNode) AddPivotColumn(v *PivotColumnNode) {
	internal.ResolvedPivotScan_add_pivot_column_list(n.raw, v.getRaw())
}

// ReturningClauseNode represents the returning clause on a DML statement.
type ReturningClauseNode struct {
	*BaseArgumentNode
}

// OutputColumnList specifies the columns in the returned output row with column
// names. It can reference columns from the target table scan
// <table_scan> from INSERT/DELETE/UPDATE statements. Also this list
// can have columns computed in the <expr_list> or an <action_column>
// as the last column.
func (n *ReturningClauseNode) OutputColumnList() []*OutputColumnNode {
	var v unsafe.Pointer
	internal.ResolvedReturningClause_output_column_list(n.raw, &v)
	var ret []*OutputColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOutputColumnNode(p))
	})
	return ret
}

func (n *ReturningClauseNode) SetOutputColumnList(v []*OutputColumnNode) {
	internal.ResolvedReturningClause_set_output_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *ReturningClauseNode) AddOutputColumn(v *OutputColumnNode) {
	internal.ResolvedReturningClause_add_output_column_list(n.raw, v.getRaw())
}

// ActionColumn represents the WITH ACTION column in <output_column_list> as a
// string type column. There are four valid values for this action
// column: "INSERT", "REPLACE", "UPDATE", and "DELETE".
func (n *ReturningClauseNode) ActionColumn() *ColumnHolderNode {
	var v unsafe.Pointer
	internal.ResolvedReturningClause_action_column(n.raw, &v)
	return newColumnHolderNode(v)
}

func (n *ReturningClauseNode) SetActionColumn(v *ColumnHolderNode) {
	internal.ResolvedReturningClause_set_action_column(n.raw, v.getRaw())
}

// ExprList represents the computed expressions so they can be referenced in
// <output_column_list>. Worth noting, it can't see <action_column>
// and can only access columns from the DML statement target table.
func (n *ReturningClauseNode) ExprList() []*ComputedColumnNode {
	var v unsafe.Pointer
	internal.ResolvedReturningClause_expr_list(n.raw, &v)
	var ret []*ComputedColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newComputedColumnNode(p))
	})
	return ret
}

func (n *ReturningClauseNode) SetExprList(v []*ComputedColumnNode) {
	internal.ResolvedReturningClause_set_expr_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *ReturningClauseNode) AddExpr(v *ComputedColumnNode) {
	internal.ResolvedReturningClause_add_expr_list(n.raw, v.getRaw())
}

// UnpivotArgNode a column group in the UNPIVOT IN clause.
//
// Example:
//   'a' in 'UNPIVOT(x FOR z IN (a , b , c))'
//   or '(a , b)' in 'UNPIVOT((x , y) FOR z IN ((a , b), (c , d))'
type UnpivotArgNode struct {
	*BaseArgumentNode
}

// ColumnList a list of columns referencing an output column of the <input_scan>
// of UnpivotScanNode. The size of this vector is
// the same as <value_column_list>.
func (n *UnpivotArgNode) ColumnList() []*ColumnRefNode {
	var v unsafe.Pointer
	internal.ResolvedUnpivotArg_column_list(n.raw, &v)
	var ret []*ColumnRefNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumnRefNode(p))
	})
	return ret
}

func (n *UnpivotArgNode) SetColumnList(v []*ColumnRefNode) {
	internal.ResolvedUnpivotArg_set_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *UnpivotArgNode) AddColumn(v *ColumnRefNode) {
	internal.ResolvedUnpivotArg_add_column_list(n.raw, v.getRaw())
}

// UnpivotScanNode a scan produced by the following SQL fragment:
// <input_scan> UNPIVOT(<value_column_list>
//   FOR <label_column>
//   IN (<unpivot_arg_list>))
//
// size of (<unpivot_arg_list>[i], i.e. column groups inside
// <unpivot_arg_list>)
//   = size of (<value_column_list>)
//   = Let's say num_value_columns
//
// size of (<unpivot_arg_list>)
//   = size of (<label_list>)
//   = Let's say num_args
//
// Here is how output rows are generated --
// for each input row :
//   for arg_index = 0 .. (num_args - 1) :
//     output a row with the original columns from <input_scan>
//
//       plus
//     arg = <unpivot_arg_list>[arg_index]
//     for value_column_index = 0 .. (num_value_columns - 1) :
//       output_value_column = <value_column_list>[value_column_index]
//       input_arg_column = arg [value_column_index]
//       output_value_column = input_arg_column
//
//       plus
//     <label_column> = <label_list>[arg_index]
//
//
// Hence the total number of rows generated in the output =
//   input rows * size of <unpivot_arg_list>
//
// For all column groups inside <unpivot_arg_list>, datatype of
// columns at the same position in the vector must be equivalent, and
// also equivalent to the datatype of the column at the same position in
// <value_column_list>.
// I.e. in the above pseudocode, datatypes must be equivalent for
// output_value_column and input_arg_column.
// Datatype of <label_column> must be the same as datatype of
// <label_list> and can be string or int64.
type UnpivotScanNode struct {
	*BaseScanNode
}

func (n *UnpivotScanNode) InputScan() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedUnpivotScan_input_scan(n.raw, &v)
	return newScanNode(v)
}

func (n *UnpivotScanNode) SetInputScan(v ScanNode) {
	internal.ResolvedUnpivotScan_set_input_scan(n.raw, v.getRaw())
}

// ValueColumnList list of one or more new columns added by UNPIVOT.
// These new column(s) store the value of input columns that are in
// the UNPIVOT IN clause.
func (n *UnpivotScanNode) ValueColumnList() []*Column {
	var v unsafe.Pointer
	internal.ResolvedUnpivotScan_value_column_list(n.raw, &v)
	var ret []*Column
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumn(p))
	})
	return ret
}

func (n *UnpivotScanNode) SetValueColumnList(v []*Column) {
	internal.ResolvedUnpivotScan_set_value_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].raw
	}))
}

func (n *UnpivotScanNode) AddValueColumn(v *Column) {
	internal.ResolvedUnpivotScan_add_value_column_list(n.raw, v.raw)
}

// LabelColumn this is a new column added in the output for storing labels for
// input columns groups that are present in the IN clause. Its
// values are taken from <label_list>.
func (n *UnpivotScanNode) LabelColumn() *Column {
	var v unsafe.Pointer
	internal.ResolvedUnpivotScan_label_column(n.raw, &v)
	return newColumn(v)
}

func (n *UnpivotScanNode) SetLabelColumn(v *Column) {
	internal.ResolvedUnpivotScan_set_label_column(n.raw, v.raw)
}

// LabelList string or integer literal for each column group in
// <unpivot_arg_list>.
func (n *UnpivotScanNode) LabelList() []*LiteralNode {
	var v unsafe.Pointer
	internal.ResolvedUnpivotScan_label_list(n.raw, &v)
	var ret []*LiteralNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newLiteralNode(p))
	})
	return ret
}

func (n *UnpivotScanNode) SetLabelList(v []*LiteralNode) {
	internal.ResolvedUnpivotScan_set_label_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *UnpivotScanNode) AddLabel(v *LiteralNode) {
	internal.ResolvedUnpivotScan_add_label_list(n.raw, v.getRaw())
}

// UnpivotArgList the list of groups of columns in the UNPIVOT IN list. Each group
// contains references to the output columns of <input_scan> of the
// UnpivotScanNode. The values of these columns are stored in the
// new <value_column_list> and the column group labels/names
// in the <label_column>.
func (n *UnpivotScanNode) UnpivotArgList() []*UnpivotArgNode {
	var v unsafe.Pointer
	internal.ResolvedUnpivotScan_unpivot_arg_list(n.raw, &v)
	var ret []*UnpivotArgNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newUnpivotArgNode(p))
	})
	return ret
}

func (n *UnpivotScanNode) SetUnpivotArgList(v []*UnpivotArgNode) {
	internal.ResolvedUnpivotScan_set_unpivot_arg_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *UnpivotScanNode) AddUnpivotArg(v *UnpivotArgNode) {
	internal.ResolvedUnpivotScan_add_unpivot_arg_list(n.raw, v.getRaw())
}

// ProjectedInputColumnList the columns from <input_scan> that are not unpivoted in UNPIVOT
// IN clause. Columns in <projected_input_column_list> and
// <unpivot_arg_list> are mutually exclusive and their union is the
// complete set of columns in the unpivot input-source.
//
// The expression of each ComputedColumnNode is a
// ColumnRefNode that references a column from <input_scan>.
func (n *UnpivotScanNode) ProjectedInputColumnList() []*ComputedColumnNode {
	var v unsafe.Pointer
	internal.ResolvedUnpivotScan_projected_input_column_list(n.raw, &v)
	var ret []*ComputedColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newComputedColumnNode(p))
	})
	return ret
}

func (n *UnpivotScanNode) SetProjectedInputColumnList(v []*ComputedColumnNode) {
	internal.ResolvedUnpivotScan_set_projected_input_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *UnpivotScanNode) AddProjectedInputColumn(v *ComputedColumnNode) {
	internal.ResolvedUnpivotScan_add_projected_input_column_list(n.raw, v.getRaw())
}

// IncludeNulls whether we need to include the rows from output where ALL columns
// from <value_column_list> are null.
func (n *UnpivotScanNode) IncludeNulls() bool {
	var v bool
	internal.ResolvedUnpivotScan_include_nulls(n.raw, &v)
	return v
}

func (n *UnpivotScanNode) SetIncludeNulls(v bool) {
	internal.ResolvedUnpivotScan_set_include_nulls(n.raw, helper.BoolToInt(v))
}

// CloneDataStmtNode
// CLONE DATA INTO <table_name> FROM ...
//
// <target_table> the table to clone data into. Cannot be value table.
// <clone_from> The source table(s) to clone data from.
//              For a single table, the scan is TableScan, with an optional
//                  for_system_time_expr;
//              If WHERE clause is present, the Scan is wrapped inside
//                  FilterScanNode;
//              When multiple sources are present, they are UNION'ed together
//                  in a SetOperationScanNode.
//
//              Constraints:
//                The target_table must not be the same as any source table,
//                and two sources cannot refer to the same table.
//                All source tables and target table must have equal number
//                of columns, with positionally identical column names and
//                types.
//                Cannot be value table.
type CloneDataStmtNode struct {
	*BaseStatementNode
}

func (n *CloneDataStmtNode) TargetTable() *TableScanNode {
	var v unsafe.Pointer
	internal.ResolvedCloneDataStmt_target_table(n.raw, &v)
	return newTableScanNode(v)
}

func (n *CloneDataStmtNode) SetTargetTable(v *TableScanNode) {
	internal.ResolvedCloneDataStmt_set_target_table(n.raw, v.getRaw())
}

func (n *CloneDataStmtNode) CloneFrom() ScanNode {
	var v unsafe.Pointer
	internal.ResolvedCloneDataStmt_clone_from(n.raw, &v)
	return newScanNode(v)
}

func (n *CloneDataStmtNode) SetCloneFrom(v ScanNode) {
	internal.ResolvedCloneDataStmt_set_clone_from(n.raw, v.getRaw())
}

// TableAndColumnInfoNode identifies the <table> and <column_index_list> (which can be empty) that
// are targets of the ANALYZE statement.
//
// <column_index_list> This list identifies the ordinals of columns to be
// analyzed in the <table>'s column list.
type TableAndColumnInfoNode struct {
	*BaseArgumentNode
}

func (n *TableAndColumnInfoNode) Table() types.Table {
	var v unsafe.Pointer
	internal.ResolvedTableAndColumnInfo_table(n.raw, &v)
	return newTable(v)
}

func (n *TableAndColumnInfoNode) SetTable(v types.Table) {
	internal.ResolvedTableAndColumnInfo_set_table(n.raw, getRawTable(v))
}

func (n *TableAndColumnInfoNode) ColumnIndexList() []int {
	var v unsafe.Pointer
	internal.ResolvedTableAndColumnInfo_column_index_list(n.raw, &v)
	var ret []int
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, int(uintptr(p)))
	})
	return ret
}

func (n *TableAndColumnInfoNode) SetColumnIndexList(v []int) {
	internal.ResolvedTableAndColumnInfo_set_column_index_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return unsafe.Pointer(uintptr(v[i]))
	}))
}

func (n *TableAndColumnInfoNode) AddColumnIndex(v int) {
	internal.ResolvedTableAndColumnInfo_add_column_index_list(n.raw, v)
}

// AnalyzeStmtNode represents the ANALYZE statement:
// ANALYZE [OPTIONS (<option_list>)] [<table_and_column_index_list> [, ...]];
//
// <option_list> is a list of options for ANALYZE.
//
// <table_and_column_info_list> identifies a list of tables along with their
// related columns that are the target of ANALYZE.
type AnalyzeStmtNode struct {
	*BaseStatementNode
}

func (n *AnalyzeStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedAnalyzeStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *AnalyzeStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedAnalyzeStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AnalyzeStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedAnalyzeStmt_add_option_list(n.raw, v.getRaw())
}

func (n *AnalyzeStmtNode) TableAndColumnIndexList() []*TableAndColumnInfoNode {
	var v unsafe.Pointer
	internal.ResolvedAnalyzeStmt_table_and_column_index_list(n.raw, &v)
	var ret []*TableAndColumnInfoNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newTableAndColumnInfoNode(p))
	})
	return ret
}

func (n *AnalyzeStmtNode) SetTableAndColumnIndexList(v []*TableAndColumnInfoNode) {
	internal.ResolvedAnalyzeStmt_set_table_and_column_index_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AnalyzeStmtNode) AddTableAndColumnIndex(v *TableAndColumnInfoNode) {
	internal.ResolvedAnalyzeStmt_add_table_and_column_index_list(n.raw, v.getRaw())
}

// AuxLoadDataStmtNode
// LOAD DATA {OVERWRITE|INTO} <table_name> ... FROM FILES ...
//   This statement loads an external file to a new or existing table.
//   See (broken link).
//
// <insertion_mode> either OVERWRITE or APPEND (INTO) the destination table.
// <name_path> the table to load data into.
// <output_column_list> the list of visible columns of the destination table.
//   If <column_definition_list> is explicitly specified:
//     <output_column_list> =
//         <column_definition_list> + <with_partition_columns>
//   Or if the table already exists:
//     <output_column_list> = <name_path>.columns
//   Last, if the table doesn't exist and <column_definition_list> isn't
//   explicitly specified:
//     <output_column_list> = detected-columns + <with_partition_columns>
// <column_definition_list> If not empty, the explicit columns of the
//     destination table. Must be coerciable from the source file's fields.
//
//     When the destination table doesn't already exist, it will be created
//     with these columns (plus the additional columns from WITH PARTITION
//     COLUMNS subclause); otherwise, the destination table's schema must
//     match the explicit columns by both name and type.
// <pseudo_column_list> is a list of pseudo-columns expected to be present on
//     the created table (provided by AnalyzerOptions::SetDdlPseudoColumns*).
//     These can be referenced in expressions in <partition_by_list> and
//     <cluster_by_list>.
// <primary_key> specifies the PRIMARY KEY constraint on the table. It is
//     nullptr when no PRIMARY KEY is specified.
//     If specified, and the table already exists, the primary_key is
//     required to be the same as that of the existing.
// <foreign_key_list> specifies the FOREIGN KEY constraints on the table.
//     If specified, and the table already exists, the foreign keys are
//     required to be the same as that of the existing.
// <check_constraint_list> specifies the ZETASQL_CHECK constraints on the table.
//     If specified, and the table already exists, the constraints are
//     required to be the same as that of the existing.
// <partition_by_list> The list of columns to partition the destination
//     table. Similar to <column_definition_list>, it must match the
//     destination table's partitioning spec if it already exists.
// <cluster_by_list> The list of columns to cluster the destination
//     table. Similar to <column_definition_list>, it must match the
//     destination table's partitioning spec if it already exists.
// <option_list> the options list describing the destination table.
//     If the destination doesn't already exist, it will be created with
//     these options; otherwise it must match the existing destination
//     table's options.
// <with_partition_columns> The columns decoded from partitioned source
//     files. If the destination table doesn't already exist, these columns
//     will be implicitly added to the destination table's schema; otherwise
//     the destination table must already have these columns
//     (matching by both names and types).
//
//     The hive partition columns from the source file do not automatically
//     partition the destination table. To apply the partition, the
//     <partition_by_list> must be specified.
// <connection> optional connection reference for accessing files.
// <from_files_option_list> the options list describing the source file(s).
type AuxLoadDataStmtNode struct {
	*BaseStatementNode
}

func (n *AuxLoadDataStmtNode) InsertionMode() InsertionMode {
	var v int
	internal.ResolvedAuxLoadDataStmt_insertion_mode(n.raw, &v)
	return InsertionMode(v)
}

func (n *AuxLoadDataStmtNode) SetInsertionMode(v InsertionMode) {
	internal.ResolvedAuxLoadDataStmt_set_insertion_mode(n.raw, int(v))
}

func (n *AuxLoadDataStmtNode) NamePath() []string {
	var v unsafe.Pointer
	internal.ResolvedAuxLoadDataStmt_name_path(n.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (n *AuxLoadDataStmtNode) SetNamePath(v []string) {
	internal.ResolvedAuxLoadDataStmt_set_name_path(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return helper.StringToPtr(v[i])
	}))
}

func (n *AuxLoadDataStmtNode) AddNamePath(v string) {
	internal.ResolvedAuxLoadDataStmt_add_name_path(n.raw, helper.StringToPtr(v))
}

func (n *AuxLoadDataStmtNode) OutputColumnList() []*OutputColumnNode {
	var v unsafe.Pointer
	internal.ResolvedAuxLoadDataStmt_output_column_list(n.raw, &v)
	var ret []*OutputColumnNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOutputColumnNode(p))
	})
	return ret
}

func (n *AuxLoadDataStmtNode) SetOutputColumnList(v []*OutputColumnNode) {
	internal.ResolvedAuxLoadDataStmt_set_output_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AuxLoadDataStmtNode) AddOutputColumn(v *OutputColumnNode) {
	internal.ResolvedAuxLoadDataStmt_add_output_column_list(n.raw, v.getRaw())
}

func (n *AuxLoadDataStmtNode) ColumnDefinitionList() []*ColumnDefinitionNode {
	var v unsafe.Pointer
	internal.ResolvedAuxLoadDataStmt_column_definition_list(n.raw, &v)
	var ret []*ColumnDefinitionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumnDefinitionNode(p))
	})
	return ret
}

func (n *AuxLoadDataStmtNode) SetColumnDefinitionList(v []*ColumnDefinitionNode) {
	internal.ResolvedAuxLoadDataStmt_set_column_definition_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AuxLoadDataStmtNode) AddColumnDefinition(v *ColumnDefinitionNode) {
	internal.ResolvedAuxLoadDataStmt_add_column_definition_list(n.raw, v.getRaw())
}

func (n *AuxLoadDataStmtNode) PseudoColumnList() []*Column {
	var v unsafe.Pointer
	internal.ResolvedAuxLoadDataStmt_pseudo_column_list(n.raw, &v)
	var ret []*Column
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newColumn(p))
	})
	return ret
}

func (n *AuxLoadDataStmtNode) SetPseudoColumnList(v []*Column) {
	internal.ResolvedAuxLoadDataStmt_set_pseudo_column_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].raw
	}))
}

func (n *AuxLoadDataStmtNode) AddPseudoColumn(v *Column) {
	internal.ResolvedAuxLoadDataStmt_add_pseudo_column_list(n.raw, v.raw)
}

func (n *AuxLoadDataStmtNode) PrimaryKey() *PrimaryKeyNode {
	var v unsafe.Pointer
	internal.ResolvedAuxLoadDataStmt_primary_key(n.raw, &v)
	return newPrimaryKeyNode(v)
}

func (n *AuxLoadDataStmtNode) SetPrimaryKey(v *PrimaryKeyNode) {
	internal.ResolvedAuxLoadDataStmt_set_primary_key(n.raw, v.getRaw())
}

func (n *AuxLoadDataStmtNode) ForeignKeyList() []*ForeignKeyNode {
	var v unsafe.Pointer
	internal.ResolvedAuxLoadDataStmt_foreign_key_list(n.raw, &v)
	var ret []*ForeignKeyNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newForeignKeyNode(p))
	})
	return ret
}

func (n *AuxLoadDataStmtNode) SetForeignKeyList(v []*ForeignKeyNode) {
	internal.ResolvedAuxLoadDataStmt_set_foreign_key_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AuxLoadDataStmtNode) AddForeignKey(v *ForeignKeyNode) {
	internal.ResolvedAuxLoadDataStmt_add_foreign_key_list(n.raw, v.getRaw())
}

func (n *AuxLoadDataStmtNode) CheckConstraintList() []*CheckConstraintNode {
	var v unsafe.Pointer
	internal.ResolvedAuxLoadDataStmt_check_constraint_list(n.raw, &v)
	var ret []*CheckConstraintNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newCheckConstraintNode(p))
	})
	return ret
}

func (n *AuxLoadDataStmtNode) SetCheckConstraintList(v []*CheckConstraintNode) {
	internal.ResolvedAuxLoadDataStmt_set_check_constraint_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AuxLoadDataStmtNode) AddCheckConstraint(v *CheckConstraintNode) {
	internal.ResolvedAuxLoadDataStmt_add_check_constraint_list(n.raw, v.getRaw())
}

func (n *AuxLoadDataStmtNode) PartitionByList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedAuxLoadDataStmt_partition_by_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *AuxLoadDataStmtNode) SetPartitionByList(v []ExprNode) {
	internal.ResolvedAuxLoadDataStmt_set_partition_by_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AuxLoadDataStmtNode) AddPartitionBy(v ExprNode) {
	internal.ResolvedAuxLoadDataStmt_add_partition_by_list(n.raw, v.getRaw())
}

func (n *AuxLoadDataStmtNode) ClusterByList() []ExprNode {
	var v unsafe.Pointer
	internal.ResolvedAuxLoadDataStmt_cluster_by_list(n.raw, &v)
	var ret []ExprNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newExprNode(p))
	})
	return ret
}

func (n *AuxLoadDataStmtNode) SetClusterByList(v []ExprNode) {
	internal.ResolvedAuxLoadDataStmt_set_cluster_by_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AuxLoadDataStmtNode) AddClusterBy(v ExprNode) {
	internal.ResolvedAuxLoadDataStmt_add_cluster_by_list(n.raw, v.getRaw())
}

func (n *AuxLoadDataStmtNode) OptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedAuxLoadDataStmt_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *AuxLoadDataStmtNode) SetOptionList(v []*OptionNode) {
	internal.ResolvedAuxLoadDataStmt_set_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AuxLoadDataStmtNode) AddOption(v *OptionNode) {
	internal.ResolvedAuxLoadDataStmt_add_option_list(n.raw, v.getRaw())
}

func (n *AuxLoadDataStmtNode) WithPartitionColumns() *WithPartitionColumnsNode {
	var v unsafe.Pointer
	internal.ResolvedAuxLoadDataStmt_with_partition_columns(n.raw, &v)
	return newWithPartitionColumnsNode(v)
}

func (n *AuxLoadDataStmtNode) SetWithPartitionColumns(v *WithPartitionColumnsNode) {
	internal.ResolvedAuxLoadDataStmt_set_with_partition_columns(n.raw, v.getRaw())
}

func (n *AuxLoadDataStmtNode) Connection() *ConnectionNode {
	var v unsafe.Pointer
	internal.ResolvedAuxLoadDataStmt_connection(n.raw, &v)
	return newConnectionNode(v)
}

func (n *AuxLoadDataStmtNode) SetConnection(v *ConnectionNode) {
	internal.ResolvedAuxLoadDataStmt_set_connection(n.raw, v.getRaw())
}

func (n *AuxLoadDataStmtNode) FromFilesOptionList() []*OptionNode {
	var v unsafe.Pointer
	internal.ResolvedAuxLoadDataStmt_from_files_option_list(n.raw, &v)
	var ret []*OptionNode
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newOptionNode(p))
	})
	return ret
}

func (n *AuxLoadDataStmtNode) SetFromFilesOptionList(v []*OptionNode) {
	internal.ResolvedAuxLoadDataStmt_set_from_files_option_list(n.raw, helper.SliceToPtr(v, func(i int) unsafe.Pointer {
		return v[i].getRaw()
	}))
}

func (n *AuxLoadDataStmtNode) AddFromFilesOption(v *OptionNode) {
	internal.ResolvedAuxLoadDataStmt_add_from_files_option_list(n.raw, v.getRaw())
}

type TVFArgumentNode = FunctionArgumentNode

func newNode(v unsafe.Pointer) Node {
	if v == nil {
		return nil
	}
	var kind int
	internal.ResolvedNode_node_kind(v, &kind)
	switch Kind(kind) {
	case Literal:
		return newLiteralNode(v)
	case Parameter:
		return newParameterNode(v)
	case ExpressionColumn:
		return newExpressionColumnNode(v)
	case ColumnRef:
		return newColumnRefNode(v)
	case Constant:
		return newConstantNode(v)
	case SystemVariable:
		return newSystemVariableNode(v)
	case InlineLambda:
		return newInlineLambdaNode(v)
	case FilterFieldArg:
		return newFilterFieldArgNode(v)
	case FilterField:
		return newFilterFieldNode(v)
	case FunctionCall:
		return newFunctionCallNode(v)
	case AggregateFunctionCall:
		return newAggregateFunctionCallNode(v)
	case AnalyticFunctionCall:
		return newAnalyticFunctionCallNode(v)
	case ExtendedCastElement:
		return newExtendedCastElementNode(v)
	case ExtendedCast:
		return newExtendedCastNode(v)
	case Cast:
		return newCastNode(v)
	case MakeStruct:
		return newMakeStructNode(v)
	case MakeProto:
		return newMakeProtoNode(v)
	case MakeProtoField:
		return newMakeProtoFieldNode(v)
	case GetStructField:
		return newGetStructFieldNode(v)
	case GetProtoField:
		return newGetProtoFieldNode(v)
	case GetJsonField:
		return newGetJsonFieldNode(v)
	case Flatten:
		return newFlattenNode(v)
	case FlattenedArg:
		return newFlattenedArgNode(v)
	case ReplaceFieldItem:
		return newReplaceFieldItemNode(v)
	case ReplaceField:
		return newReplaceFieldNode(v)
	case SubqueryExpr:
		return newSubqueryExprNode(v)
	case LetExpr:
		return newLetExprNode(v)
	case Model:
		return newModelNode(v)
	case Connection:
		return newConnectionNode(v)
	case Descriptor:
		return newDescriptorNode(v)
	case SingleRowScan:
		return newSingleRowScanNode(v)
	case TableScan:
		return newTableScanNode(v)
	case JoinScan:
		return newJoinScanNode(v)
	case ArrayScan:
		return newArrayScanNode(v)
	case ColumnHolder:
		return newColumnHolderNode(v)
	case FilterScan:
		return newFilterScanNode(v)
	case GroupingSet:
		return newGroupingSetNode(v)
	case AggregateScan:
		return newAggregateScanNode(v)
	case AnonymizedAggregateScan:
		return newAnonymizedAggregateScanNode(v)
	case SetOperationItem:
		return newSetOperationItemNode(v)
	case SetOperationScan:
		return newSetOperationScanNode(v)
	case OrderByScan:
		return newOrderByScanNode(v)
	case LimitOffsetScan:
		return newLimitOffsetScanNode(v)
	case WithRefScan:
		return newWithRefScanNode(v)
	case AnalyticScan:
		return newAnalyticScanNode(v)
	case SampleScan:
		return newSampleScanNode(v)
	case ComputedColumn:
		return newComputedColumnNode(v)
	case OrderByItem:
		return newOrderByItemNode(v)
	case ColumnAnnotations:
		return newColumnAnnotationsNode(v)
	case GeneratedColumnInfo:
		return newGeneratedColumnInfoNode(v)
	case ColumnDefaultValue:
		return newColumnDefaultValueNode(v)
	case ColumnDefinition:
		return newColumnDefinitionNode(v)
	case PrimaryKey:
		return newPrimaryKeyNode(v)
	case ForeignKey:
		return newForeignKeyNode(v)
	case CheckConstraint:
		return newCheckConstraintNode(v)
	case OutputColumn:
		return newOutputColumnNode(v)
	case ProjectScan:
		return newProjectScanNode(v)
	case TVFScan:
		return newTVFScanNode(v)
	case GroupRowsScan:
		return newGroupRowsScanNode(v)
	case FunctionArgument:
		return newFunctionArgumentNode(v)
	case ExplainStmt:
		return newExplainStmtNode(v)
	case QueryStmt:
		return newQueryStmtNode(v)
	case CreateDatabaseStmt:
		return newCreateDatabaseStmtNode(v)
	case IndexItem:
		return newIndexItemNode(v)
	case UnnestItem:
		return newUnnestItemNode(v)
	case CreateIndexStmt:
		return newCreateIndexStmtNode(v)
	case CreateSchemaStmt:
		return newCreateSchemaStmtNode(v)
	case CreateTableStmt:
		return newCreateTableStmtNode(v)
	case CreateTableAsSelectStmt:
		return newCreateTableAsSelectStmtNode(v)
	case CreateModelStmt:
		return newCreateModelStmtNode(v)
	case CreateViewStmt:
		return newCreateViewStmtNode(v)
	case WithPartitionColumns:
		return newWithPartitionColumnsNode(v)
	case CreateSnapshotTableStmt:
		return newCreateSnapshotTableStmtNode(v)
	case CreateExternalTableStmt:
		return newCreateExternalTableStmtNode(v)
	case ExportModelStmt:
		return newExportModelStmtNode(v)
	case ExportDataStmt:
		return newExportDataStmtNode(v)
	case DefineTableStmt:
		return newDefineTableStmtNode(v)
	case DescribeStmt:
		return newDescribeStmtNode(v)
	case ShowStmt:
		return newShowStmtNode(v)
	case BeginStmt:
		return newBeginStmtNode(v)
	case SetTransactionStmt:
		return newSetTransactionStmtNode(v)
	case CommitStmt:
		return newCommitStmtNode(v)
	case RollbackStmt:
		return newRollbackStmtNode(v)
	case StartBatchStmt:
		return newStartBatchStmtNode(v)
	case RunBatchStmt:
		return newRunBatchStmtNode(v)
	case AbortBatchStmt:
		return newAbortBatchStmtNode(v)
	case DropStmt:
		return newDropStmtNode(v)
	case DropMaterializedViewStmt:
		return newDropMaterializedViewStmtNode(v)
	case DropSnapshotTableStmt:
		return newDropSnapshotTableStmtNode(v)
	case RecursiveRefScan:
		return newRecursiveRefScanNode(v)
	case RecursiveScan:
		return newRecursiveScanNode(v)
	case WithScan:
		return newWithScanNode(v)
	case WithEntry:
		return newWithEntryNode(v)
	case Option:
		return newOptionNode(v)
	case WindowPartitioning:
		return newWindowPartitioningNode(v)
	case WindowOrdering:
		return newWindowOrderingNode(v)
	case WindowFrame:
		return newWindowFrameNode(v)
	case AnalyticFunctionGroup:
		return newAnalyticFunctionGroupNode(v)
	case WindowFrameExpr:
		return newWindowFrameExprNode(v)
	case DMLValue:
		return newDMLValueNode(v)
	case DMLDefault:
		return newDMLDefaultNode(v)
	case AssertStmt:
		return newAssertStmtNode(v)
	case AssertRowsModified:
		return newAssertRowsModifiedNode(v)
	case InsertRow:
		return newInsertRowNode(v)
	case InsertStmt:
		return newInsertStmtNode(v)
	case DeleteStmt:
		return newDeleteStmtNode(v)
	case UpdateItem:
		return newUpdateItemNode(v)
	case UpdateArrayItem:
		return newUpdateArrayItemNode(v)
	case UpdateStmt:
		return newUpdateStmtNode(v)
	case MergeWhen:
		return newMergeWhenNode(v)
	case MergeStmt:
		return newMergeStmtNode(v)
	case TruncateStmt:
		return newTruncateStmtNode(v)
	case ObjectUnit:
		return newObjectUnitNode(v)
	case Privilege:
		return newPrivilegeNode(v)
	case GrantStmt:
		return newGrantStmtNode(v)
	case RevokeStmt:
		return newRevokeStmtNode(v)
	case AlterDatabaseStmt:
		return newAlterDatabaseStmtNode(v)
	case AlterMaterializedViewStmt:
		return newAlterMaterializedViewStmtNode(v)
	case AlterSchemaStmt:
		return newAlterSchemaStmtNode(v)
	case AlterTableStmt:
		return newAlterTableStmtNode(v)
	case AlterViewStmt:
		return newAlterViewStmtNode(v)
	case SetOptionsAction:
		return newSetOptionsActionNode(v)
	case AddColumnAction:
		return newAddColumnActionNode(v)
	case AddConstraintAction:
		return newAddConstraintActionNode(v)
	case DropConstraintAction:
		return newDropConstraintActionNode(v)
	case DropPrimaryKeyAction:
		return newDropPrimaryKeyActionNode(v)
	case AlterColumnOptionsAction:
		return newAlterColumnOptionsActionNode(v)
	case AlterColumnDropNotNullAction:
		return newAlterColumnDropNotNullActionNode(v)
	case AlterColumnSetDataTypeAction:
		return newAlterColumnSetDataTypeActionNode(v)
	case AlterColumnSetDefaultAction:
		return newAlterColumnSetDefaultActionNode(v)
	case AlterColumnDropDefaultAction:
		return newAlterColumnDropDefaultActionNode(v)
	case DropColumnAction:
		return newDropColumnActionNode(v)
	case RenameColumnAction:
		return newRenameColumnActionNode(v)
	case SetAsAction:
		return newSetAsActionNode(v)
	case SetCollateClause:
		return newSetCollateClauseNode(v)
	case AlterTableSetOptionsStmt:
		return newAlterTableSetOptionsStmtNode(v)
	case RenameStmt:
		return newRenameStmtNode(v)
	case CreatePrivilegeRestrictionStmt:
		return newCreatePrivilegeRestrictionStmtNode(v)
	case CreateRowAccessPolicyStmt:
		return newCreateRowAccessPolicyStmtNode(v)
	case DropPrivilegeRestrictionStmt:
		return newDropPrivilegeRestrictionStmtNode(v)
	case DropRowAccessPolicyStmt:
		return newDropRowAccessPolicyStmtNode(v)
	case DropSearchIndexStmt:
		return newDropSearchIndexStmtNode(v)
	case GrantToAction:
		return newGrantToActionNode(v)
	case RestrictToAction:
		return newRestrictToActionNode(v)
	case AddToRestricteeListAction:
		return newAddToRestricteeListActionNode(v)
	case RemoveFromRestricteeListAction:
		return newRemoveFromRestricteeListActionNode(v)
	case FilterUsingAction:
		return newFilterUsingActionNode(v)
	case RevokeFromAction:
		return newRevokeFromActionNode(v)
	case RenameToAction:
		return newRenameToActionNode(v)
	case AlterPrivilegeRestrictionStmt:
		return newAlterPrivilegeRestrictionStmtNode(v)
	case AlterRowAccessPolicyStmt:
		return newAlterRowAccessPolicyStmtNode(v)
	case AlterAllRowAccessPoliciesStmt:
		return newAlterAllRowAccessPoliciesStmtNode(v)
	case CreateConstantStmt:
		return newCreateConstantStmtNode(v)
	case CreateFunctionStmt:
		return newCreateFunctionStmtNode(v)
	case ArgumentDef:
		return newArgumentDefNode(v)
	case ArgumentRef:
		return newArgumentRefNode(v)
	case CreateTableFunctionStmt:
		return newCreateTableFunctionStmtNode(v)
	case RelationArgumentScan:
		return newRelationArgumentScanNode(v)
	case ArgumentList:
		return newArgumentListNode(v)
	case FunctionSignatureHolder:
		return newFunctionSignatureHolderNode(v)
	case DropFunctionStmt:
		return newDropFunctionStmtNode(v)
	case DropTableFunctionStmt:
		return newDropTableFunctionStmtNode(v)
	case CallStmt:
		return newCallStmtNode(v)
	case ImportStmt:
		return newImportStmtNode(v)
	case ModuleStmt:
		return newModuleStmtNode(v)
	case AggregateHavingModifier:
		return newAggregateHavingModifierNode(v)
	case CreateMaterializedViewStmt:
		return newCreateMaterializedViewStmtNode(v)
	case CreateProcedureStmt:
		return newCreateProcedureStmtNode(v)
	case ExecuteImmediateArgument:
		return newExecuteImmediateArgumentNode(v)
	case ExecuteImmediateStmt:
		return newExecuteImmediateStmtNode(v)
	case AssignmentStmt:
		return newAssignmentStmtNode(v)
	case CreateEntityStmt:
		return newCreateEntityStmtNode(v)
	case AlterEntityStmt:
		return newAlterEntityStmtNode(v)
	case PivotColumn:
		return newPivotColumnNode(v)
	case PivotScan:
		return newPivotScanNode(v)
	case ReturningClause:
		return newReturningClauseNode(v)
	case UnpivotArg:
		return newUnpivotArgNode(v)
	case UnpivotScan:
		return newUnpivotScanNode(v)
	case CloneDataStmt:
		return newCloneDataStmtNode(v)
	case TableAndColumnInfo:
		return newTableAndColumnInfoNode(v)
	case AnalyzeStmt:
		return newAnalyzeStmtNode(v)
	case AuxLoadDataStmt:
		return newAuxLoadDataStmtNode(v)
	}
	return nil
}

func newExprNode(v unsafe.Pointer) ExprNode {
	if v == nil {
		return nil
	}
	return newNode(v).(ExprNode)
}

func newScanNode(v unsafe.Pointer) ScanNode {
	if v == nil {
		return nil
	}
	return newNode(v).(ScanNode)
}

func newStatementNode(v unsafe.Pointer) StatementNode {
	if v == nil {
		return nil
	}
	return newNode(v).(StatementNode)
}

func newAlterActionNode(v unsafe.Pointer) AlterActionNode {
	if v == nil {
		return nil
	}
	return newNode(v).(AlterActionNode)
}

func newConstraintNode(v unsafe.Pointer) ConstraintNode {
	if v == nil {
		return nil
	}
	return newNode(v).(ConstraintNode)
}

func newBaseNode(v unsafe.Pointer) *BaseNode {
	if v == nil {
		return nil
	}
	return &BaseNode{raw: v}
}

func newBaseArgumentNode(v unsafe.Pointer) *BaseArgumentNode {
	if v == nil {
		return nil
	}
	return &BaseArgumentNode{BaseNode: newBaseNode(v)}
}

func newBaseExprNode(v unsafe.Pointer) *BaseExprNode {
	if v == nil {
		return nil
	}
	return &BaseExprNode{BaseNode: newBaseNode(v)}
}

func newLiteralNode(v unsafe.Pointer) *LiteralNode {
	if v == nil {
		return nil
	}
	return &LiteralNode{BaseExprNode: newBaseExprNode(v)}
}

func newParameterNode(v unsafe.Pointer) *ParameterNode {
	if v == nil {
		return nil
	}
	return &ParameterNode{BaseExprNode: newBaseExprNode(v)}
}

func newExpressionColumnNode(v unsafe.Pointer) *ExpressionColumnNode {
	if v == nil {
		return nil
	}
	return &ExpressionColumnNode{BaseExprNode: newBaseExprNode(v)}
}

func newColumnRefNode(v unsafe.Pointer) *ColumnRefNode {
	if v == nil {
		return nil
	}
	return &ColumnRefNode{BaseExprNode: newBaseExprNode(v)}
}

func newConstantNode(v unsafe.Pointer) *ConstantNode {
	if v == nil {
		return nil
	}
	return &ConstantNode{BaseExprNode: newBaseExprNode(v)}
}

func newSystemVariableNode(v unsafe.Pointer) *SystemVariableNode {
	if v == nil {
		return nil
	}
	return &SystemVariableNode{BaseExprNode: newBaseExprNode(v)}
}

func newInlineLambdaNode(v unsafe.Pointer) *InlineLambdaNode {
	if v == nil {
		return nil
	}
	return &InlineLambdaNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newFilterFieldArgNode(v unsafe.Pointer) *FilterFieldArgNode {
	if v == nil {
		return nil
	}
	return &FilterFieldArgNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newFilterFieldNode(v unsafe.Pointer) *FilterFieldNode {
	if v == nil {
		return nil
	}
	return &FilterFieldNode{BaseExprNode: newBaseExprNode(v)}
}

func newBaseFunctionCallNode(v unsafe.Pointer) *BaseFunctionCallNode {
	if v == nil {
		return nil
	}
	return &BaseFunctionCallNode{BaseExprNode: newBaseExprNode(v)}
}

func newFunctionCallNode(v unsafe.Pointer) *FunctionCallNode {
	if v == nil {
		return nil
	}
	return &FunctionCallNode{BaseFunctionCallNode: newBaseFunctionCallNode(v)}
}

func newBaseNonScalarFunctionCallNode(v unsafe.Pointer) *BaseNonScalarFunctionCallNode {
	if v == nil {
		return nil
	}
	return &BaseNonScalarFunctionCallNode{BaseFunctionCallNode: newBaseFunctionCallNode(v)}
}

func newAggregateFunctionCallNode(v unsafe.Pointer) *AggregateFunctionCallNode {
	if v == nil {
		return nil
	}
	return &AggregateFunctionCallNode{BaseNonScalarFunctionCallNode: newBaseNonScalarFunctionCallNode(v)}
}

func newAnalyticFunctionCallNode(v unsafe.Pointer) *AnalyticFunctionCallNode {
	if v == nil {
		return nil
	}
	return &AnalyticFunctionCallNode{BaseNonScalarFunctionCallNode: newBaseNonScalarFunctionCallNode(v)}
}

func newExtendedCastElementNode(v unsafe.Pointer) *ExtendedCastElementNode {
	if v == nil {
		return nil
	}
	return &ExtendedCastElementNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newExtendedCastNode(v unsafe.Pointer) *ExtendedCastNode {
	if v == nil {
		return nil
	}
	return &ExtendedCastNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newCastNode(v unsafe.Pointer) *CastNode {
	if v == nil {
		return nil
	}
	return &CastNode{BaseExprNode: newBaseExprNode(v)}
}

func newMakeStructNode(v unsafe.Pointer) *MakeStructNode {
	if v == nil {
		return nil
	}
	return &MakeStructNode{BaseExprNode: newBaseExprNode(v)}
}

func newMakeProtoNode(v unsafe.Pointer) *MakeProtoNode {
	if v == nil {
		return nil
	}
	return &MakeProtoNode{BaseExprNode: newBaseExprNode(v)}
}

func newMakeProtoFieldNode(v unsafe.Pointer) *MakeProtoFieldNode {
	if v == nil {
		return nil
	}
	return &MakeProtoFieldNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newGetStructFieldNode(v unsafe.Pointer) *GetStructFieldNode {
	if v == nil {
		return nil
	}
	return &GetStructFieldNode{BaseExprNode: newBaseExprNode(v)}
}

func newGetProtoFieldNode(v unsafe.Pointer) *GetProtoFieldNode {
	if v == nil {
		return nil
	}
	return &GetProtoFieldNode{BaseExprNode: newBaseExprNode(v)}
}

func newGetJsonFieldNode(v unsafe.Pointer) *GetJsonFieldNode {
	if v == nil {
		return nil
	}
	return &GetJsonFieldNode{BaseExprNode: newBaseExprNode(v)}
}

func newFlattenNode(v unsafe.Pointer) *FlattenNode {
	if v == nil {
		return nil
	}
	return &FlattenNode{BaseExprNode: newBaseExprNode(v)}
}

func newFlattenedArgNode(v unsafe.Pointer) *FlattenedArgNode {
	if v == nil {
		return nil
	}
	return &FlattenedArgNode{BaseExprNode: newBaseExprNode(v)}
}

func newReplaceFieldItemNode(v unsafe.Pointer) *ReplaceFieldItemNode {
	if v == nil {
		return nil
	}
	return &ReplaceFieldItemNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newReplaceFieldNode(v unsafe.Pointer) *ReplaceFieldNode {
	if v == nil {
		return nil
	}
	return &ReplaceFieldNode{BaseExprNode: newBaseExprNode(v)}
}

func newSubqueryExprNode(v unsafe.Pointer) *SubqueryExprNode {
	if v == nil {
		return nil
	}
	return &SubqueryExprNode{BaseExprNode: newBaseExprNode(v)}
}

func newLetExprNode(v unsafe.Pointer) *LetExprNode {
	if v == nil {
		return nil
	}
	return &LetExprNode{BaseExprNode: newBaseExprNode(v)}
}

func newBaseScanNode(v unsafe.Pointer) *BaseScanNode {
	if v == nil {
		return nil
	}
	return &BaseScanNode{BaseNode: newBaseNode(v)}
}

func newModelNode(v unsafe.Pointer) *ModelNode {
	if v == nil {
		return nil
	}
	return &ModelNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newConnectionNode(v unsafe.Pointer) *ConnectionNode {
	if v == nil {
		return nil
	}
	return &ConnectionNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newDescriptorNode(v unsafe.Pointer) *DescriptorNode {
	if v == nil {
		return nil
	}
	return &DescriptorNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newSingleRowScanNode(v unsafe.Pointer) *SingleRowScanNode {
	if v == nil {
		return nil
	}
	return &SingleRowScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newTableScanNode(v unsafe.Pointer) *TableScanNode {
	if v == nil {
		return nil
	}
	return &TableScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newJoinScanNode(v unsafe.Pointer) *JoinScanNode {
	if v == nil {
		return nil
	}
	return &JoinScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newArrayScanNode(v unsafe.Pointer) *ArrayScanNode {
	if v == nil {
		return nil
	}
	return &ArrayScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newColumnHolderNode(v unsafe.Pointer) *ColumnHolderNode {
	if v == nil {
		return nil
	}
	return &ColumnHolderNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newFilterScanNode(v unsafe.Pointer) *FilterScanNode {
	if v == nil {
		return nil
	}
	return &FilterScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newGroupingSetNode(v unsafe.Pointer) *GroupingSetNode {
	if v == nil {
		return nil
	}
	return &GroupingSetNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newBaseAggregateScanNode(v unsafe.Pointer) *BaseAggregateScanNode {
	if v == nil {
		return nil
	}
	return &BaseAggregateScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newAggregateScanNode(v unsafe.Pointer) *AggregateScanNode {
	if v == nil {
		return nil
	}
	return &AggregateScanNode{BaseAggregateScanNode: newBaseAggregateScanNode(v)}
}

func newAnonymizedAggregateScanNode(v unsafe.Pointer) *AnonymizedAggregateScanNode {
	if v == nil {
		return nil
	}
	return &AnonymizedAggregateScanNode{BaseAggregateScanNode: newBaseAggregateScanNode(v)}
}

func newSetOperationItemNode(v unsafe.Pointer) *SetOperationItemNode {
	if v == nil {
		return nil
	}
	return &SetOperationItemNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newSetOperationScanNode(v unsafe.Pointer) *SetOperationScanNode {
	if v == nil {
		return nil
	}
	return &SetOperationScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newOrderByScanNode(v unsafe.Pointer) *OrderByScanNode {
	if v == nil {
		return nil
	}
	return &OrderByScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newLimitOffsetScanNode(v unsafe.Pointer) *LimitOffsetScanNode {
	if v == nil {
		return nil
	}
	return &LimitOffsetScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newWithRefScanNode(v unsafe.Pointer) *WithRefScanNode {
	if v == nil {
		return nil
	}
	return &WithRefScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newAnalyticScanNode(v unsafe.Pointer) *AnalyticScanNode {
	if v == nil {
		return nil
	}
	return &AnalyticScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newSampleScanNode(v unsafe.Pointer) *SampleScanNode {
	if v == nil {
		return nil
	}
	return &SampleScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newComputedColumnNode(v unsafe.Pointer) *ComputedColumnNode {
	if v == nil {
		return nil
	}
	return &ComputedColumnNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newOrderByItemNode(v unsafe.Pointer) *OrderByItemNode {
	if v == nil {
		return nil
	}
	return &OrderByItemNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newColumnAnnotationsNode(v unsafe.Pointer) *ColumnAnnotationsNode {
	if v == nil {
		return nil
	}
	return &ColumnAnnotationsNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newGeneratedColumnInfoNode(v unsafe.Pointer) *GeneratedColumnInfoNode {
	if v == nil {
		return nil
	}
	return &GeneratedColumnInfoNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newColumnDefaultValueNode(v unsafe.Pointer) *ColumnDefaultValueNode {
	if v == nil {
		return nil
	}
	return &ColumnDefaultValueNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newColumnDefinitionNode(v unsafe.Pointer) *ColumnDefinitionNode {
	if v == nil {
		return nil
	}
	return &ColumnDefinitionNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newBaseConstraintNode(v unsafe.Pointer) *BaseConstraintNode {
	if v == nil {
		return nil
	}
	return &BaseConstraintNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newPrimaryKeyNode(v unsafe.Pointer) *PrimaryKeyNode {
	if v == nil {
		return nil
	}
	return &PrimaryKeyNode{BaseConstraintNode: newBaseConstraintNode(v)}
}

func newForeignKeyNode(v unsafe.Pointer) *ForeignKeyNode {
	if v == nil {
		return nil
	}
	return &ForeignKeyNode{BaseConstraintNode: newBaseConstraintNode(v)}
}

func newCheckConstraintNode(v unsafe.Pointer) *CheckConstraintNode {
	if v == nil {
		return nil
	}
	return &CheckConstraintNode{BaseConstraintNode: newBaseConstraintNode(v)}
}

func newOutputColumnNode(v unsafe.Pointer) *OutputColumnNode {
	if v == nil {
		return nil
	}
	return &OutputColumnNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newProjectScanNode(v unsafe.Pointer) *ProjectScanNode {
	if v == nil {
		return nil
	}
	return &ProjectScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newTVFScanNode(v unsafe.Pointer) *TVFScanNode {
	if v == nil {
		return nil
	}
	return &TVFScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newGroupRowsScanNode(v unsafe.Pointer) *GroupRowsScanNode {
	if v == nil {
		return nil
	}
	return &GroupRowsScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newFunctionArgumentNode(v unsafe.Pointer) *FunctionArgumentNode {
	if v == nil {
		return nil
	}
	return &FunctionArgumentNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newBaseStatementNode(v unsafe.Pointer) *BaseStatementNode {
	if v == nil {
		return nil
	}
	return &BaseStatementNode{BaseNode: newBaseNode(v)}
}

func newExplainStmtNode(v unsafe.Pointer) *ExplainStmtNode {
	if v == nil {
		return nil
	}
	return &ExplainStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newQueryStmtNode(v unsafe.Pointer) *QueryStmtNode {
	if v == nil {
		return nil
	}
	return &QueryStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newCreateDatabaseStmtNode(v unsafe.Pointer) *CreateDatabaseStmtNode {
	if v == nil {
		return nil
	}
	return &CreateDatabaseStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newBaseCreateStatementNode(v unsafe.Pointer) *BaseCreateStatementNode {
	if v == nil {
		return nil
	}
	return &BaseCreateStatementNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newIndexItemNode(v unsafe.Pointer) *IndexItemNode {
	if v == nil {
		return nil
	}
	return &IndexItemNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newUnnestItemNode(v unsafe.Pointer) *UnnestItemNode {
	if v == nil {
		return nil
	}
	return &UnnestItemNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newCreateIndexStmtNode(v unsafe.Pointer) *CreateIndexStmtNode {
	if v == nil {
		return nil
	}
	return &CreateIndexStmtNode{BaseCreateStatementNode: newBaseCreateStatementNode(v)}
}

func newCreateSchemaStmtNode(v unsafe.Pointer) *CreateSchemaStmtNode {
	if v == nil {
		return nil
	}
	return &CreateSchemaStmtNode{BaseCreateStatementNode: newBaseCreateStatementNode(v)}
}

func newBaseCreateTableStmtNode(v unsafe.Pointer) *BaseCreateTableStmtNode {
	if v == nil {
		return nil
	}
	return &BaseCreateTableStmtNode{BaseCreateStatementNode: newBaseCreateStatementNode(v)}
}

func newCreateTableStmtNode(v unsafe.Pointer) *CreateTableStmtNode {
	if v == nil {
		return nil
	}
	return &CreateTableStmtNode{BaseCreateTableStmtNode: newBaseCreateTableStmtNode(v)}
}

func newCreateTableAsSelectStmtNode(v unsafe.Pointer) *CreateTableAsSelectStmtNode {
	if v == nil {
		return nil
	}
	return &CreateTableAsSelectStmtNode{BaseCreateTableStmtNode: newBaseCreateTableStmtNode(v)}
}

func newCreateModelStmtNode(v unsafe.Pointer) *CreateModelStmtNode {
	if v == nil {
		return nil
	}
	return &CreateModelStmtNode{BaseCreateStatementNode: newBaseCreateStatementNode(v)}
}

func newBaseCreateViewNode(v unsafe.Pointer) *BaseCreateViewNode {
	if v == nil {
		return nil
	}
	return &BaseCreateViewNode{BaseCreateStatementNode: newBaseCreateStatementNode(v)}
}

func newCreateViewStmtNode(v unsafe.Pointer) *CreateViewStmtNode {
	if v == nil {
		return nil
	}
	return &CreateViewStmtNode{BaseCreateViewNode: newBaseCreateViewNode(v)}
}

func newWithPartitionColumnsNode(v unsafe.Pointer) *WithPartitionColumnsNode {
	if v == nil {
		return nil
	}
	return &WithPartitionColumnsNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newCreateSnapshotTableStmtNode(v unsafe.Pointer) *CreateSnapshotTableStmtNode {
	if v == nil {
		return nil
	}
	return &CreateSnapshotTableStmtNode{BaseCreateStatementNode: newBaseCreateStatementNode(v)}
}

func newCreateExternalTableStmtNode(v unsafe.Pointer) *CreateExternalTableStmtNode {
	if v == nil {
		return nil
	}
	return &CreateExternalTableStmtNode{BaseCreateTableStmtNode: newBaseCreateTableStmtNode(v)}
}

func newExportModelStmtNode(v unsafe.Pointer) *ExportModelStmtNode {
	if v == nil {
		return nil
	}
	return &ExportModelStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newExportDataStmtNode(v unsafe.Pointer) *ExportDataStmtNode {
	if v == nil {
		return nil
	}
	return &ExportDataStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newDefineTableStmtNode(v unsafe.Pointer) *DefineTableStmtNode {
	if v == nil {
		return nil
	}
	return &DefineTableStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newDescribeStmtNode(v unsafe.Pointer) *DescribeStmtNode {
	if v == nil {
		return nil
	}
	return &DescribeStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newShowStmtNode(v unsafe.Pointer) *ShowStmtNode {
	if v == nil {
		return nil
	}
	return &ShowStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newBeginStmtNode(v unsafe.Pointer) *BeginStmtNode {
	if v == nil {
		return nil
	}
	return &BeginStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newSetTransactionStmtNode(v unsafe.Pointer) *SetTransactionStmtNode {
	if v == nil {
		return nil
	}
	return &SetTransactionStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newCommitStmtNode(v unsafe.Pointer) *CommitStmtNode {
	if v == nil {
		return nil
	}
	return &CommitStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newRollbackStmtNode(v unsafe.Pointer) *RollbackStmtNode {
	if v == nil {
		return nil
	}
	return &RollbackStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newStartBatchStmtNode(v unsafe.Pointer) *StartBatchStmtNode {
	if v == nil {
		return nil
	}
	return &StartBatchStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newRunBatchStmtNode(v unsafe.Pointer) *RunBatchStmtNode {
	if v == nil {
		return nil
	}
	return &RunBatchStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newAbortBatchStmtNode(v unsafe.Pointer) *AbortBatchStmtNode {
	if v == nil {
		return nil
	}
	return &AbortBatchStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newDropStmtNode(v unsafe.Pointer) *DropStmtNode {
	if v == nil {
		return nil
	}
	return &DropStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newDropMaterializedViewStmtNode(v unsafe.Pointer) *DropMaterializedViewStmtNode {
	if v == nil {
		return nil
	}
	return &DropMaterializedViewStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newDropSnapshotTableStmtNode(v unsafe.Pointer) *DropSnapshotTableStmtNode {
	if v == nil {
		return nil
	}
	return &DropSnapshotTableStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newRecursiveRefScanNode(v unsafe.Pointer) *RecursiveRefScanNode {
	if v == nil {
		return nil
	}
	return &RecursiveRefScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newRecursiveScanNode(v unsafe.Pointer) *RecursiveScanNode {
	if v == nil {
		return nil
	}
	return &RecursiveScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newWithScanNode(v unsafe.Pointer) *WithScanNode {
	if v == nil {
		return nil
	}
	return &WithScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newWithEntryNode(v unsafe.Pointer) *WithEntryNode {
	if v == nil {
		return nil
	}
	return &WithEntryNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newOptionNode(v unsafe.Pointer) *OptionNode {
	if v == nil {
		return nil
	}
	return &OptionNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newWindowPartitioningNode(v unsafe.Pointer) *WindowPartitioningNode {
	if v == nil {
		return nil
	}
	return &WindowPartitioningNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newWindowOrderingNode(v unsafe.Pointer) *WindowOrderingNode {
	if v == nil {
		return nil
	}
	return &WindowOrderingNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newWindowFrameNode(v unsafe.Pointer) *WindowFrameNode {
	if v == nil {
		return nil
	}
	return &WindowFrameNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newAnalyticFunctionGroupNode(v unsafe.Pointer) *AnalyticFunctionGroupNode {
	if v == nil {
		return nil
	}
	return &AnalyticFunctionGroupNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newWindowFrameExprNode(v unsafe.Pointer) *WindowFrameExprNode {
	if v == nil {
		return nil
	}
	return &WindowFrameExprNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newDMLValueNode(v unsafe.Pointer) *DMLValueNode {
	if v == nil {
		return nil
	}
	return &DMLValueNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newDMLDefaultNode(v unsafe.Pointer) *DMLDefaultNode {
	if v == nil {
		return nil
	}
	return &DMLDefaultNode{BaseExprNode: newBaseExprNode(v)}
}

func newAssertStmtNode(v unsafe.Pointer) *AssertStmtNode {
	if v == nil {
		return nil
	}
	return &AssertStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newAssertRowsModifiedNode(v unsafe.Pointer) *AssertRowsModifiedNode {
	if v == nil {
		return nil
	}
	return &AssertRowsModifiedNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newInsertRowNode(v unsafe.Pointer) *InsertRowNode {
	if v == nil {
		return nil
	}
	return &InsertRowNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newInsertStmtNode(v unsafe.Pointer) *InsertStmtNode {
	if v == nil {
		return nil
	}
	return &InsertStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newDeleteStmtNode(v unsafe.Pointer) *DeleteStmtNode {
	if v == nil {
		return nil
	}
	return &DeleteStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newUpdateItemNode(v unsafe.Pointer) *UpdateItemNode {
	if v == nil {
		return nil
	}
	return &UpdateItemNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newUpdateArrayItemNode(v unsafe.Pointer) *UpdateArrayItemNode {
	if v == nil {
		return nil
	}
	return &UpdateArrayItemNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newUpdateStmtNode(v unsafe.Pointer) *UpdateStmtNode {
	if v == nil {
		return nil
	}
	return &UpdateStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newMergeWhenNode(v unsafe.Pointer) *MergeWhenNode {
	if v == nil {
		return nil
	}
	return &MergeWhenNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newMergeStmtNode(v unsafe.Pointer) *MergeStmtNode {
	if v == nil {
		return nil
	}
	return &MergeStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newTruncateStmtNode(v unsafe.Pointer) *TruncateStmtNode {
	if v == nil {
		return nil
	}
	return &TruncateStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newObjectUnitNode(v unsafe.Pointer) *ObjectUnitNode {
	if v == nil {
		return nil
	}
	return &ObjectUnitNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newPrivilegeNode(v unsafe.Pointer) *PrivilegeNode {
	if v == nil {
		return nil
	}
	return &PrivilegeNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newGrantOrRevokeStmtNode(v unsafe.Pointer) *GrantOrRevokeStmtNode {
	if v == nil {
		return nil
	}
	return &GrantOrRevokeStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newGrantStmtNode(v unsafe.Pointer) *GrantStmtNode {
	if v == nil {
		return nil
	}
	return &GrantStmtNode{GrantOrRevokeStmtNode: newGrantOrRevokeStmtNode(v)}
}

func newRevokeStmtNode(v unsafe.Pointer) *RevokeStmtNode {
	if v == nil {
		return nil
	}
	return &RevokeStmtNode{GrantOrRevokeStmtNode: newGrantOrRevokeStmtNode(v)}
}

func newAlterObjectStmtNode(v unsafe.Pointer) *AlterObjectStmtNode {
	if v == nil {
		return nil
	}
	return &AlterObjectStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newAlterDatabaseStmtNode(v unsafe.Pointer) *AlterDatabaseStmtNode {
	if v == nil {
		return nil
	}
	return &AlterDatabaseStmtNode{AlterObjectStmtNode: newAlterObjectStmtNode(v)}
}

func newAlterMaterializedViewStmtNode(v unsafe.Pointer) *AlterMaterializedViewStmtNode {
	if v == nil {
		return nil
	}
	return &AlterMaterializedViewStmtNode{AlterObjectStmtNode: newAlterObjectStmtNode(v)}
}

func newAlterSchemaStmtNode(v unsafe.Pointer) *AlterSchemaStmtNode {
	if v == nil {
		return nil
	}
	return &AlterSchemaStmtNode{AlterObjectStmtNode: newAlterObjectStmtNode(v)}
}

func newAlterTableStmtNode(v unsafe.Pointer) *AlterTableStmtNode {
	if v == nil {
		return nil
	}
	return &AlterTableStmtNode{AlterObjectStmtNode: newAlterObjectStmtNode(v)}
}

func newAlterViewStmtNode(v unsafe.Pointer) *AlterViewStmtNode {
	if v == nil {
		return nil
	}
	return &AlterViewStmtNode{AlterObjectStmtNode: newAlterObjectStmtNode(v)}
}

func newBaseAlterActionNode(v unsafe.Pointer) *BaseAlterActionNode {
	if v == nil {
		return nil
	}
	return &BaseAlterActionNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newBaseAlterColumnActionNode(v unsafe.Pointer) *BaseAlterColumnActionNode {
	if v == nil {
		return nil
	}
	return &BaseAlterColumnActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newSetOptionsActionNode(v unsafe.Pointer) *SetOptionsActionNode {
	if v == nil {
		return nil
	}
	return &SetOptionsActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newAddColumnActionNode(v unsafe.Pointer) *AddColumnActionNode {
	if v == nil {
		return nil
	}
	return &AddColumnActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newAddConstraintActionNode(v unsafe.Pointer) *AddConstraintActionNode {
	if v == nil {
		return nil
	}
	return &AddConstraintActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newDropConstraintActionNode(v unsafe.Pointer) *DropConstraintActionNode {
	if v == nil {
		return nil
	}
	return &DropConstraintActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newDropPrimaryKeyActionNode(v unsafe.Pointer) *DropPrimaryKeyActionNode {
	if v == nil {
		return nil
	}
	return &DropPrimaryKeyActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newAlterColumnOptionsActionNode(v unsafe.Pointer) *AlterColumnOptionsActionNode {
	if v == nil {
		return nil
	}
	return &AlterColumnOptionsActionNode{BaseAlterColumnActionNode: newBaseAlterColumnActionNode(v)}
}

func newAlterColumnDropNotNullActionNode(v unsafe.Pointer) *AlterColumnDropNotNullActionNode {
	if v == nil {
		return nil
	}
	return &AlterColumnDropNotNullActionNode{BaseAlterColumnActionNode: newBaseAlterColumnActionNode(v)}
}

func newAlterColumnSetDataTypeActionNode(v unsafe.Pointer) *AlterColumnSetDataTypeActionNode {
	if v == nil {
		return nil
	}
	return &AlterColumnSetDataTypeActionNode{BaseAlterColumnActionNode: newBaseAlterColumnActionNode(v)}
}

func newAlterColumnSetDefaultActionNode(v unsafe.Pointer) *AlterColumnSetDefaultActionNode {
	if v == nil {
		return nil
	}
	return &AlterColumnSetDefaultActionNode{BaseAlterColumnActionNode: newBaseAlterColumnActionNode(v)}
}

func newAlterColumnDropDefaultActionNode(v unsafe.Pointer) *AlterColumnDropDefaultActionNode {
	if v == nil {
		return nil
	}
	return &AlterColumnDropDefaultActionNode{BaseAlterColumnActionNode: newBaseAlterColumnActionNode(v)}
}

func newDropColumnActionNode(v unsafe.Pointer) *DropColumnActionNode {
	if v == nil {
		return nil
	}
	return &DropColumnActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newRenameColumnActionNode(v unsafe.Pointer) *RenameColumnActionNode {
	if v == nil {
		return nil
	}
	return &RenameColumnActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newSetAsActionNode(v unsafe.Pointer) *SetAsActionNode {
	if v == nil {
		return nil
	}
	return &SetAsActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newSetCollateClauseNode(v unsafe.Pointer) *SetCollateClauseNode {
	if v == nil {
		return nil
	}
	return &SetCollateClauseNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newAlterTableSetOptionsStmtNode(v unsafe.Pointer) *AlterTableSetOptionsStmtNode {
	if v == nil {
		return nil
	}
	return &AlterTableSetOptionsStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newRenameStmtNode(v unsafe.Pointer) *RenameStmtNode {
	if v == nil {
		return nil
	}
	return &RenameStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newCreatePrivilegeRestrictionStmtNode(v unsafe.Pointer) *CreatePrivilegeRestrictionStmtNode {
	if v == nil {
		return nil
	}
	return &CreatePrivilegeRestrictionStmtNode{BaseCreateStatementNode: newBaseCreateStatementNode(v)}
}

func newCreateRowAccessPolicyStmtNode(v unsafe.Pointer) *CreateRowAccessPolicyStmtNode {
	if v == nil {
		return nil
	}
	return &CreateRowAccessPolicyStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newDropPrivilegeRestrictionStmtNode(v unsafe.Pointer) *DropPrivilegeRestrictionStmtNode {
	if v == nil {
		return nil
	}
	return &DropPrivilegeRestrictionStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newDropRowAccessPolicyStmtNode(v unsafe.Pointer) *DropRowAccessPolicyStmtNode {
	if v == nil {
		return nil
	}
	return &DropRowAccessPolicyStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newDropSearchIndexStmtNode(v unsafe.Pointer) *DropSearchIndexStmtNode {
	if v == nil {
		return nil
	}
	return &DropSearchIndexStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newGrantToActionNode(v unsafe.Pointer) *GrantToActionNode {
	if v == nil {
		return nil
	}
	return &GrantToActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newRestrictToActionNode(v unsafe.Pointer) *RestrictToActionNode {
	if v == nil {
		return nil
	}
	return &RestrictToActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newAddToRestricteeListActionNode(v unsafe.Pointer) *AddToRestricteeListActionNode {
	if v == nil {
		return nil
	}
	return &AddToRestricteeListActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newRemoveFromRestricteeListActionNode(v unsafe.Pointer) *RemoveFromRestricteeListActionNode {
	if v == nil {
		return nil
	}
	return &RemoveFromRestricteeListActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newFilterUsingActionNode(v unsafe.Pointer) *FilterUsingActionNode {
	if v == nil {
		return nil
	}
	return &FilterUsingActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newRevokeFromActionNode(v unsafe.Pointer) *RevokeFromActionNode {
	if v == nil {
		return nil
	}
	return &RevokeFromActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newRenameToActionNode(v unsafe.Pointer) *RenameToActionNode {
	if v == nil {
		return nil
	}
	return &RenameToActionNode{BaseAlterActionNode: newBaseAlterActionNode(v)}
}

func newAlterPrivilegeRestrictionStmtNode(v unsafe.Pointer) *AlterPrivilegeRestrictionStmtNode {
	if v == nil {
		return nil
	}
	return &AlterPrivilegeRestrictionStmtNode{AlterObjectStmtNode: newAlterObjectStmtNode(v)}
}

func newAlterRowAccessPolicyStmtNode(v unsafe.Pointer) *AlterRowAccessPolicyStmtNode {
	if v == nil {
		return nil
	}
	return &AlterRowAccessPolicyStmtNode{AlterObjectStmtNode: newAlterObjectStmtNode(v)}
}

func newAlterAllRowAccessPoliciesStmtNode(v unsafe.Pointer) *AlterAllRowAccessPoliciesStmtNode {
	if v == nil {
		return nil
	}
	return &AlterAllRowAccessPoliciesStmtNode{AlterObjectStmtNode: newAlterObjectStmtNode(v)}
}

func newCreateConstantStmtNode(v unsafe.Pointer) *CreateConstantStmtNode {
	if v == nil {
		return nil
	}
	return &CreateConstantStmtNode{BaseCreateStatementNode: newBaseCreateStatementNode(v)}
}

func newCreateFunctionStmtNode(v unsafe.Pointer) *CreateFunctionStmtNode {
	if v == nil {
		return nil
	}
	return &CreateFunctionStmtNode{BaseCreateStatementNode: newBaseCreateStatementNode(v)}
}

func newArgumentDefNode(v unsafe.Pointer) *ArgumentDefNode {
	if v == nil {
		return nil
	}
	return &ArgumentDefNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newArgumentRefNode(v unsafe.Pointer) *ArgumentRefNode {
	if v == nil {
		return nil
	}
	return &ArgumentRefNode{BaseExprNode: newBaseExprNode(v)}
}

func newCreateTableFunctionStmtNode(v unsafe.Pointer) *CreateTableFunctionStmtNode {
	if v == nil {
		return nil
	}
	return &CreateTableFunctionStmtNode{BaseCreateStatementNode: newBaseCreateStatementNode(v)}
}

func newRelationArgumentScanNode(v unsafe.Pointer) *RelationArgumentScanNode {
	if v == nil {
		return nil
	}
	return &RelationArgumentScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newArgumentListNode(v unsafe.Pointer) *ArgumentListNode {
	if v == nil {
		return nil
	}
	return &ArgumentListNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newFunctionSignatureHolderNode(v unsafe.Pointer) *FunctionSignatureHolderNode {
	if v == nil {
		return nil
	}
	return &FunctionSignatureHolderNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newDropFunctionStmtNode(v unsafe.Pointer) *DropFunctionStmtNode {
	if v == nil {
		return nil
	}
	return &DropFunctionStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newDropTableFunctionStmtNode(v unsafe.Pointer) *DropTableFunctionStmtNode {
	if v == nil {
		return nil
	}
	return &DropTableFunctionStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newCallStmtNode(v unsafe.Pointer) *CallStmtNode {
	if v == nil {
		return nil
	}
	return &CallStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newImportStmtNode(v unsafe.Pointer) *ImportStmtNode {
	if v == nil {
		return nil
	}
	return &ImportStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newModuleStmtNode(v unsafe.Pointer) *ModuleStmtNode {
	if v == nil {
		return nil
	}
	return &ModuleStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newAggregateHavingModifierNode(v unsafe.Pointer) *AggregateHavingModifierNode {
	if v == nil {
		return nil
	}
	return &AggregateHavingModifierNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newCreateMaterializedViewStmtNode(v unsafe.Pointer) *CreateMaterializedViewStmtNode {
	if v == nil {
		return nil
	}
	return &CreateMaterializedViewStmtNode{BaseCreateViewNode: newBaseCreateViewNode(v)}
}

func newCreateProcedureStmtNode(v unsafe.Pointer) *CreateProcedureStmtNode {
	if v == nil {
		return nil
	}
	return &CreateProcedureStmtNode{BaseCreateStatementNode: newBaseCreateStatementNode(v)}
}

func newExecuteImmediateArgumentNode(v unsafe.Pointer) *ExecuteImmediateArgumentNode {
	if v == nil {
		return nil
	}
	return &ExecuteImmediateArgumentNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newExecuteImmediateStmtNode(v unsafe.Pointer) *ExecuteImmediateStmtNode {
	if v == nil {
		return nil
	}
	return &ExecuteImmediateStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newAssignmentStmtNode(v unsafe.Pointer) *AssignmentStmtNode {
	if v == nil {
		return nil
	}
	return &AssignmentStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newCreateEntityStmtNode(v unsafe.Pointer) *CreateEntityStmtNode {
	if v == nil {
		return nil
	}
	return &CreateEntityStmtNode{BaseCreateStatementNode: newBaseCreateStatementNode(v)}
}

func newAlterEntityStmtNode(v unsafe.Pointer) *AlterEntityStmtNode {
	if v == nil {
		return nil
	}
	return &AlterEntityStmtNode{AlterObjectStmtNode: newAlterObjectStmtNode(v)}
}

func newPivotColumnNode(v unsafe.Pointer) *PivotColumnNode {
	if v == nil {
		return nil
	}
	return &PivotColumnNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newPivotScanNode(v unsafe.Pointer) *PivotScanNode {
	if v == nil {
		return nil
	}
	return &PivotScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newReturningClauseNode(v unsafe.Pointer) *ReturningClauseNode {
	if v == nil {
		return nil
	}
	return &ReturningClauseNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newUnpivotArgNode(v unsafe.Pointer) *UnpivotArgNode {
	if v == nil {
		return nil
	}
	return &UnpivotArgNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newUnpivotScanNode(v unsafe.Pointer) *UnpivotScanNode {
	if v == nil {
		return nil
	}
	return &UnpivotScanNode{BaseScanNode: newBaseScanNode(v)}
}

func newCloneDataStmtNode(v unsafe.Pointer) *CloneDataStmtNode {
	if v == nil {
		return nil
	}
	return &CloneDataStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newTableAndColumnInfoNode(v unsafe.Pointer) *TableAndColumnInfoNode {
	if v == nil {
		return nil
	}
	return &TableAndColumnInfoNode{BaseArgumentNode: newBaseArgumentNode(v)}
}

func newAnalyzeStmtNode(v unsafe.Pointer) *AnalyzeStmtNode {
	if v == nil {
		return nil
	}
	return &AnalyzeStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}

func newAuxLoadDataStmtNode(v unsafe.Pointer) *AuxLoadDataStmtNode {
	if v == nil {
		return nil
	}
	return &AuxLoadDataStmtNode{BaseStatementNode: newBaseStatementNode(v)}
}
