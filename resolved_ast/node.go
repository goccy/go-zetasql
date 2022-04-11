package resolved_ast

import (
	"unsafe"

	"github.com/goccy/go-zetasql/constant"
	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/public/analyzer"
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

	getRaw() unsafe.Pointer
}

// ArgumentNode nodes are not self-contained nodes in the tree.
// They exist only to describe parameters to another node (e.g. columns in an OrderByNode).
// This node is here for organizational purposes only, to cluster these argument nodes.
type ArgumentNode interface {
	Node
}

type ExprNode interface {
	AnnotatedType() *types.AnnotatedType
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
	internal.Node_node_kind(n.raw, &v)
	return Kind(v)
}

func (n *BaseNode) IsScan() bool {
	var v bool
	internal.Node_IsScan(n.raw, &v)
	return v
}

func (n *BaseNode) IsExpression() bool {
	var v bool
	internal.Node_IsExpression(n.raw, &v)
	return v
}

func (n *BaseNode) IsStatement() bool {
	var v bool
	internal.Node_IsStatement(n.raw, &v)
	return v
}

func (n *BaseNode) DebugString() string {
	var v unsafe.Pointer
	internal.Node_DebugString(n.raw, &v)
	return helper.PtrToString(v)
}

func (n *BaseNode) ChildNodes() []Node {
	var num int
	internal.Node_GetChildNodes_num(n.raw, &num)
	ret := make([]Node, 0, num)
	for i := 0; i < num; i++ {
		var v unsafe.Pointer
		internal.Node_GetChildNode(n.raw, i, &v)
		ret = append(ret, newNode(v))
	}
	return ret
}

func (n *BaseNode) TreeDepth() int {
	var v int
	internal.Node_GetTreeDepth(n.raw, &v)
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

func (n *BaseExprNode) AnnotatedType() *types.AnnotatedType {
	return nil
}

func (n *BaseExprNode) Type() types.Type {
	return nil
}

func (n *BaseExprNode) SetType(v types.Type) {
}

func (n *BaseExprNode) TypeAnnotationMap() types.AnnotationMap {
	return nil
}

func (n *BaseExprNode) SetTypeAnnotationMap(v types.AnnotationMap) {
}

// LiteralNode any literal value, including NULL literals.
type LiteralNode struct {
	*BaseExprNode
}

func (n *LiteralNode) Value() constant.Value {
	return nil
}

func (n *LiteralNode) SetValue(v constant.Value) {

}

func (n *LiteralNode) HasExplicitType() bool {
	return false
}

func (n *LiteralNode) SetHasExplicitType(v bool) {
}

func (n *LiteralNode) FloatLiteralID() int {
	return 0
}

func (n *LiteralNode) SetFloatLiteralID(v int) {
}

func (n *LiteralNode) PreserveInLiteralRemover() bool {
	return false
}

func (n *LiteralNode) SetPreserveInLiteralRemover(v bool) {
}

type ParameterNode struct {
	*BaseExprNode
}

func (n *ParameterNode) Name() string {
	return ""
}

func (n *ParameterNode) SetName(s string) {
}

func (n *ParameterNode) Position() int {
	return 0
}

func (n *ParameterNode) SetPosition(v int) {

}

func (n *ParameterNode) IsUntyped() bool {
	return false
}

func (n *ParameterNode) SetIsUntyped(v bool) {
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
	return ""
}

func (n *ExpressionColumnNode) SetName(v string) {

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
	return nil
}

func (n *ColumnRefNode) SetColumn(v *Column) {

}

func (n *ColumnRefNode) IsCorrelated() bool {
	return false
}

func (n *ColumnRefNode) SetIsCorrelated(v bool) {

}

// ConstantNode reference to a named constant.
type ConstantNode struct {
	*BaseExprNode
}

func (n *ConstantNode) Constant() constant.Constant {
	return nil
}

func (n *ConstantNode) SetConstant(v constant.Constant) {
}

// SystemVariableNode reference to a system variable.
type SystemVariableNode struct {
	*BaseExprNode
}

func (n *SystemVariableNode) NamePaths() []string {
	return nil
}

func (n *SystemVariableNode) SetNamePath(v []string) {
}

func (n *SystemVariableNode) AddNamePath(v string) {
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
	return nil
}

func (n *InlineLambdaNode) SetArgumentList(v []*Column) {
}

func (n *InlineLambdaNode) AddArgument(v *Column) {
}

func (n *InlineLambdaNode) ParameterList() []*ColumnRefNode {
	return nil
}

func (n *InlineLambdaNode) SetParameterList(v []*ColumnRefNode) {
}

func (n *InlineLambdaNode) AddParameter(v *ColumnRefNode) {
}

func (n *InlineLambdaNode) Body() ExprNode {
	return nil
}

func (n *InlineLambdaNode) SetBody(v ExprNode) {
}

// FilterFieldArgNode an argument to the FILTER_FIELDS() function which specifies a sign to show
// inclusion/exclusion status and a field path to include or exclude.
type FilterFieldArgNode struct {
	*BaseArgumentNode
}

func (n *FilterFieldArgNode) Include() bool {
	return false
}

func (n *FilterFieldArgNode) SetInclude(v bool) {
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
	return nil
}

func (n *FilterFieldNode) SetExpr(v ExprNode) {

}

func (n *FilterFieldNode) FilterFieldArgList() []*FilterFieldArgNode {
	return nil
}

func (n *FilterFieldNode) SetFilterFieldArgList(v []*FilterFieldArgNode) {
}

func (n *FilterFieldNode) AddFilterFieldArg(v *FilterFieldArgNode) {
}

func (n *FilterFieldNode) ResetClearedRequiredFields() bool {
	return false
}

func (n *FilterFieldNode) SetResetClearedRequiredFields(v bool) {
}

type BaseFunctionCallNode struct {
	*BaseExprNode
}

func (n *BaseFunctionCallNode) Function() *types.Function {
	return nil
}

func (n *BaseFunctionCallNode) SetFunction(v *types.Function) {
}

func (n *BaseFunctionCallNode) Signature() *types.FunctionSignature {
	return nil
}

func (n *BaseFunctionCallNode) SetSignature(v *types.FunctionSignature) {
}

func (n *BaseFunctionCallNode) ArgumentList() []ExprNode {
	return nil
}

func (n *BaseFunctionCallNode) SetArgumentList(v []ExprNode) {
}

func (n *BaseFunctionCallNode) AddArgument(v ExprNode) {
}

func (n *BaseFunctionCallNode) GenericArgumentList() []*FunctionArgumentNode {
	return nil
}

func (n *BaseFunctionCallNode) SetGenericArgumentList(v []*FunctionArgumentNode) {
}

func (n *BaseFunctionCallNode) AddGenericArgument(v *FunctionArgumentNode) {
}

func (n *BaseFunctionCallNode) ErrorMode() ErrorMode {
	return ErrorMode(0)
}

func (n *BaseFunctionCallNode) SetErrorMode(v ErrorMode) {
}

func (n *BaseFunctionCallNode) HintList() []*OptionNode {
	return nil
}

func (n *BaseFunctionCallNode) SetHintList(v []*OptionNode) {
}

func (n *BaseFunctionCallNode) AddHint(v *OptionNode) {
}

func (n *BaseFunctionCallNode) CollationList() []*Collation {
	return nil
}

func (n *BaseFunctionCallNode) SetCollationList(v []*Collation) {
}

func (n *BaseFunctionCallNode) AddCollation(v *Collation) {
}

// FunctionCallNode a regular function call.
// The signature will always have mode SCALAR.
// Most scalar expressions show up as FunctionCalls using builtin signatures.
type FunctionCallNode struct {
	*BaseFunctionCallNode
}

func (n *FunctionCallNode) FunctionCallInfo() *FunctionCallInfo {
	return nil
}

func (n *FunctionCallNode) SetFunctionCallInfo(v *FunctionCallInfo) {
}

type BaseNonScalarFunctionCallNode struct {
	*BaseFunctionCallNode
}

func (n *BaseNonScalarFunctionCallNode) Distinct() bool {
	return false
}

func (n *BaseNonScalarFunctionCallNode) SetDistinct(v bool) {
}

func (n *BaseNonScalarFunctionCallNode) NullHandlingModifier() NullHandlingModifier {
	return NullHandlingModifier(0)
}

func (n *BaseNonScalarFunctionCallNode) SetNullHandlingModifier(v NullHandlingModifier) {

}

func (n *BaseNonScalarFunctionCallNode) WithGroupRowsSubquery() *ScanNode {
	return nil
}

func (n *BaseNonScalarFunctionCallNode) SetWithGroupRowsSubquery(v *ScanNode) {
}

func (n *BaseNonScalarFunctionCallNode) WithGroupRowsParameterList() []*ColumnRefNode {
	return nil
}

func (n *BaseNonScalarFunctionCallNode) SetWithGroupRowsParameterList(v []*ColumnRefNode) {
}

func (n *BaseNonScalarFunctionCallNode) AddWithGroupRowsParameter(v *ColumnRefNode) {
}

// AggregateFunctionCallNode an aggregate function call.
// The signature always has mode AGGREGATE.
// This node only ever shows up as the outer function call in a AggregateScanNode.AggregateList.
type AggregateFunctionCallNode struct {
	*BaseNonScalarFunctionCallNode
}

// HavingModifier apply HAVING MAX/MIN filtering to the stream of input values.
func (n *AggregateFunctionCallNode) HavingModifier() *AggregateHavingModifierNode {
	return nil
}

func (n *AggregateFunctionCallNode) SetHavingModifier(v *AggregateHavingModifierNode) {

}

func (n *AggregateFunctionCallNode) OrderByItemList() []*OrderByItemNode {
	return nil
}

func (n *AggregateFunctionCallNode) SetOrderByItemList(v []*OrderByItemNode) {
}

func (n *AggregateFunctionCallNode) AddOrderByItem(v *OrderByItemNode) {
}

func (n *AggregateFunctionCallNode) Limit() ExprNode {
	return nil
}

func (n *AggregateFunctionCallNode) SetLimit(v ExprNode) {
}

func (n *AggregateFunctionCallNode) FunctionCallInfo() *FunctionCallInfo {
	return nil
}

func (n *AggregateFunctionCallNode) SetFunctionCallInfo(v *FunctionCallInfo) {
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
	return nil
}

func (n *AnalyticFunctionCallNode) SetWindowFrame(v *WindowFrameNode) {

}

// ExtendedCastElementNode describes a leaf extended cast of ExtendedCastNode.
// See the comment for ElementList field of ExtendedCastNode for more details.
type ExtendedCastElementNode struct {
	*BaseArgumentNode
}

func (n *ExtendedCastElementNode) FromType() types.Type {
	return nil
}

func (n *ExtendedCastElementNode) SetFromType(v types.Type) {
}

func (n *ExtendedCastElementNode) ToType() types.Type {
	return nil
}

func (n *ExtendedCastElementNode) SetToType(v types.Type) {
}

func (n *ExtendedCastElementNode) Function() *types.Function {
	return nil
}

func (n *ExtendedCastElementNode) SetFunction(v *types.Function) {
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
	return nil
}

func (n *ExtendedCastNode) SetElementList(v []*ExtendedCastElementNode) {
}

func (n *ExtendedCastNode) AddElement(v *ExtendedCastElementNode) {
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
	return nil
}

func (n *CastNode) SetExpr(v ExprNode) {
}

func (n *CastNode) ReturnNullOnError() bool {
	return false
}

func (n *CastNode) SetReturnNullOnError(v bool) {
}

// ExtendedCast if at least one of types involved in this cast is or contains an
// extended (TYPE_EXTENDED) type, this field contains information
// necessary to execute this cast.
func (n *CastNode) ExtendedCast() *ExtendedCastNode {
	return nil
}

func (n *CastNode) SetExtendedCast(v *ExtendedCastNode) {
}

// Format the format string specified by the optional FORMAT clause.
// It is nullptr when the clause does not exist.
func (n *CastNode) Format() ExprNode {
	return nil
}

func (n *CastNode) SetFormat(v ExprNode) {
}

// TimeZone the time zone expression by the optional AT TIME ZONE clause.
// It is nullptr when the clause does not exist.
func (n *CastNode) TimeZone() ExprNode {
	return nil
}

func (n *CastNode) SetTimeZone(v ExprNode) {
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
	return nil
}

func (n *CastNode) SetTypeParameters(v *types.TypeParameters) {
}

// MakeStructNode construct a struct value.
// Type is always a StructType.
// FieldList matches 1:1 with the fields in Type position-wise.
// Each field's type will match the corresponding field in Type.
type MakeStructNode struct {
	*BaseExprNode
}

func (n *MakeStructNode) FieldList() []ExprNode {
	return nil
}

func (n *MakeStructNode) SetFieldList(v []ExprNode) {
}

func (n *MakeStructNode) AddField(v ExprNode) {
}

// MakeProtoNode construct a proto value.
// Type is always a ProtoType.
// FieldList is a vector of (FieldDescriptor, expr) pairs to write.
// FieldList will contain all required fields, and no duplicate fields.
type MakeProtoNode struct {
	*BaseExprNode
}

func (n *MakeProtoNode) FieldList() []*MakeProtoFieldNode {
	return nil
}

func (n *MakeProtoNode) SetFieldList(v []*MakeProtoFieldNode) {
}

func (n *MakeProtoNode) AddField(v *MakeProtoFieldNode) {
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

func (n *MakeProtoFieldNode) Format() Format {
	return Format(0)
}

func (n *MakeProtoFieldNode) SetFormat(v Format) {
}

func (n *MakeProtoFieldNode) Expr() ExprNode {
	return nil
}

func (n *MakeProtoFieldNode) SetExpr(v ExprNode) {
}

// GetStructFieldNode get the field in position FieldIdx (0-based) from Expr, which has a STRUCT type.
type GetStructFieldNode struct {
	*BaseExprNode
}

func (n *GetStructFieldNode) Expr() ExprNode {
	return nil
}

func (n *GetStructFieldNode) SetExpr(v ExprNode) {
}

func (n *GetStructFieldNode) FieldIdx() int {
	return 0
}

func (n *GetStructFieldNode) SetFieldIdx(v int) {
}

// GetProtoFieldNode
type GetProtoFieldNode struct {
	*BaseExprNode
}

func (n *GetProtoFieldNode) Expr() ExprNode {
	return nil
}

func (n *GetProtoFieldNode) SetExpr(v ExprNode) {
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
func (n *GetProtoFieldNode) DefaultValue() constant.Value {
	return nil
}

func (n *GetProtoFieldNode) SetDefaultValue(v constant.Value) {
}

// HasBit indicates whether to return a bool indicating if a value was
// present, rather than return the value (or nil). Never set for
// repeated fields. This field cannot be set if
// ReturnDefaultValueWhenUnset is true, and vice versa.
// Expression type will be BOOL.
func (n *GetProtoFieldNode) HasBit() bool {
	return false
}

func (n *GetProtoFieldNode) SetHasBit(v bool) {
}

// Format provides the Format annotation that should be used when reading
// this field.  The annotation specifies both the ZetaSQL type and
// the encoding format for this field. This cannot be set when
// HasBit is true.
func (n *GetProtoFieldNode) Format() Format {
	return Format(0)
}

func (n *GetProtoFieldNode) SetFormat(v Format) {
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
	return false
}

func (n *GetProtoFieldNode) SetReturnDefaultValueWhenUnset(v bool) {
}

// GetJsonFieldNode get the field FieldName from Expr, which has a JSON type.
type GetJsonFieldNode struct {
	*BaseExprNode
}

func (n *GetJsonFieldNode) Expr() ExprNode {
	return nil
}

func (n *GetJsonFieldNode) SetExpr(v ExprNode) {
}

func (n *GetJsonFieldNode) FieldName() string {
	return ""
}

func (n *GetJsonFieldNode) SetFieldName(v string) {
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
	return nil
}

func (n *FlattenNode) SetExpr(v ExprNode) {
}

// FieldList list of 'get' fields to evaluate in order (0 or more struct get
// fields followed by 0 or more proto or json get fields) starting
// from expr. Each get is evaluated N times where N is the number of
// array elements from the previous get (or expr for the first expression) generated.
//
// The 'get' fields may either be a Get*Field or an array
// offset function around a Get*Field.
func (n *FlattenNode) GetFieldList() []ExprNode {
	return nil
}

func (n *FlattenNode) SetGetFieldList(v []ExprNode) {
}

func (n *FlattenNode) AddGetField(v ExprNode) {
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

func (n *ReplaceFieldItemNode) Expr() ExprNode {
	return nil
}

func (n *ReplaceFieldItemNode) SetExpr(v ExprNode) {
}

func (n *ReplaceFieldItemNode) StructIndexPath() []int {
	return nil
}

func (n *ReplaceFieldItemNode) SetStructIndexPath(v []int) {
}

func (n *ReplaceFieldItemNode) AddStructIndexPath(v int) {
}

// ReplaceFieldNode represents a call to the REPLACE_FIELDS() function.
// This function can be used to copy a proto or struct, modify a few fields and
// output the resulting proto or struct. The SQL syntax for this
// function is REPLACE_FIELDS(<expr>, <replace_field_item_list>).
type ReplaceFieldNode struct {
	*BaseExprNode
}

func (n *ReplaceFieldNode) Expr() ExprNode {
	return nil
}

func (n *ReplaceFieldNode) SetExpr(v ExprNode) {
}

// ReplaceFieldItemList the list of field paths to be modified along with their new values.
//
// Engines must check at evaluation time that the modifications in
// ReplaceFieldItemList obey the following rules
// regarding updating protos in ZetaSQL:
// - Modifying a subfield of a NULL-valued proto-valued field is an error.
// - Clearing a required field or subfield is an error.
func (n *ReplaceFieldNode) ReplaceFieldItemList() []*ReplaceFieldItemNode {
	return nil
}

func (n *ReplaceFieldNode) SetReplaceFieldItemList(v []*ReplaceFieldItemNode) {
}

func (n *ReplaceFieldNode) AddReplaceFieldItem(v *ReplaceFieldItemNode) {
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
	return SubqueryType(0)
}

func (n *SubqueryExprNode) SetSubqueryType(v SubqueryType) {
}

func (n *SubqueryExprNode) ParameterList() []*ColumnRefNode {
	return nil
}

func (n *SubqueryExprNode) SetParameterList(v []*ColumnRefNode) {
}

func (n *SubqueryExprNode) AddParameter(v *ColumnRefNode) {
}

func (n *SubqueryExprNode) InExpr() ExprNode {
	return nil
}

func (n *SubqueryExprNode) SetInExpr(v ExprNode) {
}

// InCollation field is only populated for subqueries of type IN to specify the
// operation collation to use to compare <in_expr> with the rows from <subquery>.
func (n *SubqueryExprNode) InCollation() *Collation {
	return nil
}

func (n *SubqueryExprNode) SetInCollation(v *Collation) {
}

func (n *SubqueryExprNode) Subquery() *ScanNode {
	return nil
}

func (n *SubqueryExprNode) SetSubquery(v *ScanNode) {
}

// HintList
// NOTE: Hints currently happen only for EXISTS, IN, or a LIKE
// expression subquery but not for ARRAY or SCALAR subquery.
func (n *SubqueryExprNode) HintList() []*OptionNode {
	return nil
}

func (n *SubqueryExprNode) SetHintList(v []*OptionNode) {
}

func (n *SubqueryExprNode) AddHint(v *OptionNode) {
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
	return nil
}

func (n *LetExprNode) SetAssignmentList(v []*ComputedColumnNode) {
}

func (n *LetExprNode) AddAssignment(v *ComputedColumnNode) {
}

func (n *LetExprNode) Expr() ExprNode {
	return nil
}

func (n *LetExprNode) SetExpr(v ExprNode) {
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
	return nil
}

func (n *BaseScanNode) SetColumnList(v []*Column) {

}

func (n *BaseScanNode) AddColumn(v *Column) {

}

func (n *BaseScanNode) HintList() []*OptionNode {
	return nil
}

func (n *BaseScanNode) SetHintList(v []*OptionNode) {

}

func (n *BaseScanNode) AddHint(v *OptionNode) {

}

func (n *BaseScanNode) IsOrdered() bool {
	return false
}

func (n *BaseScanNode) SetIsOrdered(v bool) {

}

// ModelNode represents a machine learning model as a TVF argument.
// <model> is the machine learning model object known to the resolver
// (usually through the catalog).
type ModelNode struct {
	*BaseArgumentNode
}

func (n *ModelNode) Model() types.Model {
	return nil
}

func (n *ModelNode) SetModel(v types.Model) {

}

// ConnectionNode represents a connection object as a TVF argument.
// <connection> is the connection object encapsulated metadata to connect to
// an external data source.
type ConnectionNode struct {
	*BaseArgumentNode
}

func (n *ConnectionNode) Connection() types.Connection {
	return nil
}

func (n *ConnectionNode) SetConnection(v types.Connection) {
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
	return nil
}

func (n *DescriptorNode) SetDescriptorColumnList(v []*Column) {
}

func (n *DescriptorNode) AddDescriptorColumn(v *Column) {
}

func (n *DescriptorNode) DescriptorColumnNameList() []string {
	return nil
}

func (n *DescriptorNode) SetDescriptorColumnNameList(v []string) {

}

func (n *DescriptorNode) AddDescriptorColumnName(v string) {

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
	return nil
}

func (n *TableScanNode) SetTable(v types.Table) {
}

func (n *TableScanNode) ForSystemTimeExpr() ExprNode {
	return nil
}

func (n *TableScanNode) SetForSystemTimeExpr(v ExprNode) {
}

func (n *TableScanNode) ColumnIndexList() []int {
	return nil
}

func (n *TableScanNode) SetColumnIndexList(v []int) {
}

func (n *TableScanNode) AddColumnIndex(v int) {
}

func (n *TableScanNode) Alias() string {
	return ""
}

func (n *TableScanNode) SetAlias(v string) {
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
	return JoinType(0)
}

func (n *JoinScanNode) SetJoinType(v JoinType) {
}

func (n *JoinScanNode) LeftScan() ScanNode {
	return nil
}

func (n *JoinScanNode) SetLeftScan(v ScanNode) {
}

func (n *JoinScanNode) RightScan() ScanNode {
	return nil
}

func (n *JoinScanNode) SetRightScan(v ScanNode) {
}

func (n *JoinScanNode) JoinExpr() ExprNode {
	return nil
}

func (n *JoinScanNode) SetJoinExpr(v ExprNode) {
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
	return nil
}

func (n *ArrayScanNode) SetInputScan(v ScanNode) {
}

func (n *ArrayScanNode) ArrayExpr() ExprNode {
	return nil
}

func (n *ArrayScanNode) SetArrayExpr(v ExprNode) {
}

func (n *ArrayScanNode) ElementColumn() *Column {
	return nil
}

func (n *ArrayScanNode) SetElementColumn(v *Column) {
}

func (n *ArrayScanNode) ArrayOffsetColumn() *ColumnHolderNode {
	return nil
}

func (n *ArrayScanNode) SetArrayOffsetColumn(v *ColumnHolderNode) {
}

func (n *ArrayScanNode) JoinExpr() ExprNode {
	return nil
}

func (n *ArrayScanNode) SetJoinExpr(v ExprNode) {
}

func (n *ArrayScanNode) IsOuter() bool {
	return false
}

func (n *ArrayScanNode) SetIsOuter(v bool) {
}

// ColumnHolderNode this wrapper is used for an optional Column inside another node.
type ColumnHolderNode struct {
	*BaseArgumentNode
}

func (n *ColumnHolderNode) Column() *Column {
	return nil
}

func (n *ColumnHolderNode) SetColumn(v *Column) {
}

// FilterScanNode scan rows from input_scan, and emit all rows where filter_expr evaluates to true.
// filter_expr is always of type bool.
// This node's column_list will be a subset of input_scan's column_list.
type FilterScanNode struct {
	*BaseScanNode
}

func (n *FilterScanNode) InputScan() ScanNode {
	return nil
}

func (n *FilterScanNode) SetInputScan(v ScanNode) {
}

func (n *FilterScanNode) FilterExpr() ExprNode {
	return nil
}

func (n *FilterScanNode) SetFilterExpr(v ExprNode) {
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
	return nil
}

func (n *GroupingSetNode) SetGroupByColumnList(v []*ColumnRefNode) {
}

func (n *GroupingSetNode) AddGroupByColumn(v *ColumnRefNode) {
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
	return nil
}

func (n *BaseAggregateScanNode) SetInputScan(v ScanNode) {
}

func (n *BaseAggregateScanNode) GroupByList() []*ComputedColumnNode {
	return nil
}

func (n *BaseAggregateScanNode) SetGroupByList(v []*ComputedColumnNode) {
}

func (n *BaseAggregateScanNode) AddGroupBy(v *ComputedColumnNode) {
}

func (n *BaseAggregateScanNode) CollationList() []*Collation {
	return nil
}

func (n *BaseAggregateScanNode) SetCollationList(v []*Collation) {
}

func (n *BaseAggregateScanNode) AddCollation(v *Collation) {
}

func (n *BaseAggregateScanNode) AggregateList() []*ComputedColumnNode {
	return nil
}

func (n *BaseAggregateScanNode) SetAggregateList(v []*ComputedColumnNode) {
}

func (n *BaseAggregateScanNode) AddAggregate(v *ComputedColumnNode) {
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
	return nil
}

func (n *AggregateScanNode) SetGroupingSetList(v []*GroupingSetNode) {
}

func (n *AggregateScanNode) AddGroupingSet(v *GroupingSetNode) {
}

func (n *AggregateScanNode) RollupColumnList() []*ColumnRefNode {
	return nil
}

func (n *AggregateScanNode) SetRollupColumnList(v []*ColumnRefNode) {
}

func (n *AggregateScanNode) AddRollupColumn(v *ColumnRefNode) {
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
	return nil
}

func (n *AnonymizedAggregateScanNode) SetKThresholdExpr(v *ColumnRefNode) {
}

func (n *AnonymizedAggregateScanNode) AnonymizationOptionList() []*OptionNode {
	return nil
}

func (n *AnonymizedAggregateScanNode) SetAnonymizationOptionList(v []*OptionNode) {
}

func (n *AnonymizedAggregateScanNode) AddAnonymizationOption(v *OptionNode) {
}

// SetOperationItemNode this is one input item in a SetOperationNode.
// The <output_column_list> matches 1:1 with the SetOperationNode's
// <column_list> and specifies how columns from <scan> map to output columns.
// Each column from <scan> can map to zero or more output columns.
type SetOperationItemNode struct {
	*BaseArgumentNode
}

func (n *SetOperationItemNode) Scan() ScanNode {
	return nil
}

func (n *SetOperationItemNode) SetScan(v ScanNode) {
}

func (n *SetOperationItemNode) OutputColumnList() []*Column {
	return nil
}

func (n *SetOperationItemNode) SetOutputColumnList(v []*Column) {
}

func (n *SetOperationItemNode) AddOutputColumn(v *Column) {
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
	return SetOperationType(0)
}

func (n *SetOperationScanNode) SetOpType(v SetOperationType) {
}

func (n *SetOperationScanNode) InputItemList() []*SetOperationItemNode {
	return nil
}

func (n *SetOperationScanNode) SetInputItemList(v []*SetOperationItemNode) {
}

func (n *SetOperationScanNode) AddInputItem(v *SetOperationItemNode) {
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
	return nil
}

func (n *OrderByScanNode) SetInputScan(v ScanNode) {
}

func (n *OrderByScanNode) OrderByItemList() []*OrderByItemNode {
	return nil
}

func (n *OrderByScanNode) SetOrderByItemList(v []*OrderByItemNode) {
}

func (n *OrderByScanNode) AddOrderByItem(v *OrderByItemNode) {
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
	return nil
}

func (n *LimitOffsetScanNode) SetInputScan(v ScanNode) {
}

func (n *LimitOffsetScanNode) Limit() ExprNode {
	return nil
}

func (n *LimitOffsetScanNode) SetLimit(v ExprNode) {
}

func (n *LimitOffsetScanNode) Offset() ExprNode {
	return nil
}

func (n *LimitOffsetScanNode) SetOffset(v ExprNode) {
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
	return ""
}

func (n *WithRefScanNode) SetWithQueryName(v string) {
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
	return nil
}

func (n *AnalyticScanNode) SetInputScan(v ScanNode) {
}

func (n *AnalyticScanNode) FunctionGroupList() []*AnalyticFunctionGroupNode {
	return nil
}

func (n *AnalyticScanNode) SetFunctionGroupList(v []*AnalyticFunctionGroupNode) {
}

func (n *AnalyticScanNode) AddFunctionGroup(v *AnalyticFunctionGroupNode) {
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
	return nil
}

func (n *SampleScanNode) SetInputScan(v ScanNode) {
}

func (n *SampleScanNode) Method() string {
	return ""
}

func (n *SampleScanNode) SetMethod(v string) {
}

func (n *SampleScanNode) Size() ExprNode {
	return nil
}

func (n *SampleScanNode) SetSize(v ExprNode) {
}

func (n *SampleScanNode) Unit() SampleUnit {
	return SampleUnit(0)
}

func (n *SampleScanNode) SetUnit(v SampleUnit) {
}

func (n *SampleScanNode) RepeatableArgument() ExprNode {
	return nil
}

func (n *SampleScanNode) SetRepeatableArgument(v ExprNode) {
}

func (n *SampleScanNode) WeightColumn() *ColumnHolderNode {
	return nil
}

func (n *SampleScanNode) SetWeightColumn(v *ColumnHolderNode) {
}

func (n *SampleScanNode) PartitionByList() []ExprNode {
	return nil
}

func (n *SampleScanNode) SetPartitionByList(v []ExprNode) {
}

func (n *SampleScanNode) AddPartitionBy(v ExprNode) {
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
	return nil
}

func (n *ComputedColumnNode) SetColumn(v *Column) {
}

func (n *ComputedColumnNode) Expr() ExprNode {
	return nil
}

func (n *ComputedColumnNode) SetExpr(v ExprNode) {

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
	return nil
}

func (n *OrderByItemNode) SetColumnRef(v *ColumnRefNode) {
}

func (n *OrderByItemNode) CollationName() ExprNode {
	return nil
}

func (n *OrderByItemNode) SetCollationName(v ExprNode) {
}

func (n *OrderByItemNode) IsDescending() bool {
	return false
}

func (n *OrderByItemNode) SetIsDescending(v bool) {
}

func (n *OrderByItemNode) NullOrder() NullOrderMode {
	return NullOrderMode(0)
}

func (n *OrderByItemNode) SetNullOrder(v NullOrderMode) {
}

func (n *OrderByItemNode) Collation() *Collation {
	return nil
}

func (n *OrderByItemNode) SetCollation(v *Collation) {
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
	return nil
}

func (n *ColumnAnnotationsNode) SetCollationName(v ExprNode) {
}

func (n *ColumnAnnotationsNode) NotNull() bool {
	return false
}

func (n *ColumnAnnotationsNode) SetNotNull(v bool) {
}

func (n *ColumnAnnotationsNode) OptionList() []*OptionNode {
	return nil
}

func (n *ColumnAnnotationsNode) SetOptionList(v []*OptionNode) {
}

func (n *ColumnAnnotationsNode) AddOption(v *OptionNode) {
}

func (n *ColumnAnnotationsNode) ChildList() []*ColumnAnnotationsNode {
	return nil
}

func (n *ColumnAnnotationsNode) SetChildList(v []*ColumnAnnotationsNode) {
}

func (n *ColumnAnnotationsNode) AddChild(v *ColumnAnnotationsNode) {
}

func (n *ColumnAnnotationsNode) TypeParameters() *types.TypeParameters {
	return nil
}

func (n *ColumnAnnotationsNode) SetTypeParameters(v *types.TypeParameters) {
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
	return nil
}

func (n *GeneratedColumnInfoNode) SetExpression(v ExprNode) {
}

func (n *GeneratedColumnInfoNode) StoredMode() StoredMode {
	return StoredMode(0)
}

func (n *GeneratedColumnInfoNode) SetStoredMode(v StoredMode) {
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
	return nil
}

func (n *ColumnDefaultValueNode) SetExpression(v ExprNode) {
}

func (n *ColumnDefaultValueNode) SQL() string {
	return ""
}

func (n *ColumnDefaultValueNode) SetSQL(v string) {
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
	return ""
}

func (n *ColumnDefinitionNode) SetName(v string) {
}

func (n *ColumnDefinitionNode) Type() types.Type {
	return nil
}

func (n *ColumnDefinitionNode) SetType(v types.Type) {
}

func (n *ColumnDefinitionNode) Annotations() *ColumnAnnotationsNode {
	return nil
}

func (n *ColumnDefinitionNode) SetAnnotations(v *ColumnAnnotationsNode) {
}

func (n *ColumnDefinitionNode) IsHidden() bool {
	return false
}

func (n *ColumnDefinitionNode) SetIsHidden(v bool) {
}

func (n *ColumnDefinitionNode) Column() *Column {
	return nil
}

func (n *ColumnDefinitionNode) SetColumn(v *Column) {
}

func (n *ColumnDefinitionNode) GeneratedColumnInfo() *GeneratedColumnInfoNode {
	return nil
}

func (n *ColumnDefinitionNode) SetGeneratedColumnInfo(v *GeneratedColumnInfoNode) {
}

func (n *ColumnDefinitionNode) DefaultValue() *ColumnDefaultValueNode {
	return nil
}

func (n *ColumnDefinitionNode) SetDefaultValue(v *ColumnDefaultValueNode) {
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
	return nil
}

func (n *PrimaryKeyNode) SetColumnOffsetList(v []int) {
}

func (n *PrimaryKeyNode) AddColumnOffset(v int) {
}

func (n *PrimaryKeyNode) OptionList() []*OptionNode {
	return nil
}

func (n *PrimaryKeyNode) SetOptionList(v []*OptionNode) {
}

func (n *PrimaryKeyNode) AddOption(v *OptionNode) {
}

func (n *PrimaryKeyNode) Unenforced() bool {
	return false
}

func (n *PrimaryKeyNode) SetUnenforced(v bool) {
}

func (n *PrimaryKeyNode) ConstraintName() string {
	return ""
}

func (n *PrimaryKeyNode) SetConstraintName(v string) {
}

func (n *PrimaryKeyNode) ColumnNameList() []string {
	return nil
}

func (n *PrimaryKeyNode) SetColumnNameList(v []string) {
}

func (n *PrimaryKeyNode) AddColumnName(v string) {
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
	return ""
}

func (n *ForeignKeyNode) SetConstraintName(v string) {
}

func (n *ForeignKeyNode) ReferencingColumnOffsetList() []int {
	return nil
}

func (n *ForeignKeyNode) SetReferencingColumnOffsetList(v []int) {
}

func (n *ForeignKeyNode) AddReferencingColumnOffset(v int) {
}

func (n *ForeignKeyNode) ReferencedTable() types.Table {
	return nil
}

func (n *ForeignKeyNode) SetReferencedTable(v types.Table) {
}

func (n *ForeignKeyNode) ReferencedColumnOffsetList() []int {
	return nil
}

func (n *ForeignKeyNode) SetReferencedColumnOffsetList(v []int) {
}

func (n *ForeignKeyNode) AddReferencedColumnOffset(v int) {
}

func (n *ForeignKeyNode) MatchMode() MatchMode {
	return MatchMode(0)
}

func (n *ForeignKeyNode) SetMatchMode(v MatchMode) {
}

func (n *ForeignKeyNode) UpdateAction() ActionOperation {
	return ActionOperation(0)
}

func (n *ForeignKeyNode) SetUpdateAction(v ActionOperation) {
}

func (n *ForeignKeyNode) DeleteAction() ActionOperation {
	return ActionOperation(0)
}

func (n *ForeignKeyNode) SetDeleteAction(v ActionOperation) {
}

func (n *ForeignKeyNode) Enforced() bool {
	return false
}

func (n *ForeignKeyNode) SetEnforced(v bool) {
}

func (n *ForeignKeyNode) OptionList() []*OptionNode {
	return nil
}

func (n *ForeignKeyNode) SetOptionList(v []*OptionNode) {
}

func (n *ForeignKeyNode) AddOption(v *OptionNode) {
}

func (n *ForeignKeyNode) ReferencingColumnList() []string {
	return nil
}

func (n *ForeignKeyNode) SetReferencingColumnList(v []string) {
}

func (n *ForeignKeyNode) AddReferencingColumn(v string) {
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
	return ""
}

func (n *CheckConstraintNode) SetConstraintName(v string) {
}

func (n *CheckConstraintNode) Expression() ExprNode {
	return nil
}

func (n *CheckConstraintNode) SetExpression(v ExprNode) {
}

func (n *CheckConstraintNode) Enforced() bool {
	return false
}

func (n *CheckConstraintNode) SetEnforced(v bool) {
}

func (n *CheckConstraintNode) OptionList() []*OptionNode {
	return nil
}

func (n *CheckConstraintNode) SetOptionList(v []*OptionNode) {
}

func (n *CheckConstraintNode) AddOption(v *OptionNode) {
}

// OutputColumnNode this is used in QueryStmtNode to provide a user-visible name
// for each output column.
type OutputColumnNode struct {
	*BaseArgumentNode
}

func (n *OutputColumnNode) Name() string {
	return ""
}

func (n *OutputColumnNode) SetName(v string) {
}

func (n *OutputColumnNode) Column() *Column {
	return nil
}

func (n *OutputColumnNode) SetColumn(v *Column) {
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
	return nil
}

func (n *ProjectScanNode) SetExprList(v []*ComputedColumnNode) {
}

func (n *ProjectScanNode) AddExpr(v *ComputedColumnNode) {
}

func (n *ProjectScanNode) InputScan() ScanNode {
	return nil
}

func (n *ProjectScanNode) SetInputScan(v ScanNode) {
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

func (n *TVFScanNode) TVF() *types.TableValuedFunction {
	return nil
}

func (n *TVFScanNode) SetTVF(v *types.TableValuedFunction) {
}

func (n *TVFScanNode) Signature() *types.TVFSignature {
	return nil
}

func (n *TVFScanNode) SetSignature(v *types.TVFSignature) {
}

func (n *TVFScanNode) ArgumentList() []*FunctionArgumentNode {
	return nil
}

func (n *TVFScanNode) SetArgumentList(v []*FunctionArgumentNode) {
}

func (n *TVFScanNode) AddArgument(v *FunctionArgumentNode) {
}

func (n *TVFScanNode) ColumnIndexList() []int {
	return nil
}

func (n *TVFScanNode) SetColumnIndexList(v []int) {
}

func (n *TVFScanNode) AddColumnIndex(v int) {
}

func (n *TVFScanNode) Alias() string {
	return ""
}

func (n *TVFScanNode) SetAlias(v string) {
}

func (n *TVFScanNode) FunctionCallSignature() *types.FunctionSignature {
	return nil
}

func (n *TVFScanNode) SetFunctionCallSignature(v *types.FunctionSignature) {
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
	return nil
}

func (n *GroupRowsScanNode) SetInputColumnList(v []*ComputedColumnNode) {
}

func (n *GroupRowsScanNode) AddInputColumn(v *ComputedColumnNode) {
}

func (n *GroupRowsScanNode) Alias() string {
	return ""
}

func (n *GroupRowsScanNode) SetAlias(v string) {
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
	return nil
}

func (n *FunctionArgumentNode) SetExpr(v ExprNode) {
}

func (n *FunctionArgumentNode) Scan() ScanNode {
	return nil
}

func (n *FunctionArgumentNode) SetScan(v ScanNode) {
}

func (n *FunctionArgumentNode) Model() *ModelNode {
	return nil
}

func (n *FunctionArgumentNode) SetModel(v *ModelNode) {
}

func (n *FunctionArgumentNode) Connection() *ConnectionNode {
	return nil
}

func (n *FunctionArgumentNode) SetConnection(v *ConnectionNode) {
}

func (n *FunctionArgumentNode) DescriptorArg() *DescriptorNode {
	return nil
}

func (n *FunctionArgumentNode) SetDescriptorArg(v *DescriptorNode) {
}

func (n *FunctionArgumentNode) ArgumentColumnList() []*Column {
	return nil
}

func (n *FunctionArgumentNode) SetArgumentColumnList(v []*Column) {
}

func (n *FunctionArgumentNode) AddArgumentColumn(v *Column) {
}

func (n *FunctionArgumentNode) InlineLambda() *InlineLambdaNode {
	return nil
}

func (n *FunctionArgumentNode) SetInlineLambda(v *InlineLambdaNode) {
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
	return nil
}

func (n *BaseStatementNode) SetHintList(v []*OptionNode) {
}

func (n *BaseStatementNode) AddHint(v *OptionNode) {
}

// ExplainStmtNode an Explain statement. This is always the root of a statement hierarchy.
// Its child may be any statement type except another ExplainStmtNode.
//
// It is implementation dependent what action a back end system takes for an ExplainStatement.
type ExplainStmtNode struct {
	*BaseStatementNode
}

func (n *ExplainStmtNode) Statement() StatementNode {
	return nil
}

func (n *ExplainStmtNode) SetStatement(v StatementNode) {
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
	return nil
}

func (n *QueryStmtNode) SetOutputColumnList(v []*OutputColumnNode) {
}

func (n *QueryStmtNode) AddOutputColumn(v *OutputColumnNode) {
}

func (n *QueryStmtNode) IsValueTable() bool {
	return false
}

func (n *QueryStmtNode) SetIsValueTable(v bool) {
}

func (n *QueryStmtNode) Query() ScanNode {
	return nil
}

func (n *QueryStmtNode) SetQuery(v ScanNode) {
}

// CreateDatabaseStmtNode this statement:
//   CREATE DATABASE <name> [OPTIONS (...)]
// <name_path> is a vector giving the identifier path in the database name.
// <option_list> specifies the options of the database.
type CreateDatabaseStmtNode struct {
	*BaseStatementNode
}

func (n *CreateDatabaseStmtNode) NamePath() []string {
	return nil
}

func (n *CreateDatabaseStmtNode) SetNamePath(v []string) {
}

func (n *CreateDatabaseStmtNode) AddName(v string) {
}

func (n *CreateDatabaseStmtNode) OptionList() []*OptionNode {
	return nil
}

func (n *CreateDatabaseStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *CreateDatabaseStmtNode) AddOption(v *OptionNode) {
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
	AddName(string)
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
	return nil
}

func (n *BaseCreateStatementNode) SetNamePath(v []string) {
}

func (n *BaseCreateStatementNode) AddName(v string) {
}

func (n *BaseCreateStatementNode) CreateScope() CreateScope {
	return CreateScope(0)
}

func (n *BaseCreateStatementNode) SetCreateScope(v CreateScope) {
}

func (n *BaseCreateStatementNode) CreateMode() CreateMode {
	return CreateMode(0)
}

func (n *BaseCreateStatementNode) SetCreateMode(v CreateMode) {
}

// IndexItemNode represents one of indexed items in CREATE INDEX statement, with the
// ordering direction specified.
type IndexItemNode struct {
	*BaseArgumentNode
}

func (n *IndexItemNode) ColumnRef() *ColumnRefNode {
	return nil
}

func (n *IndexItemNode) SetColumnRef(v *ColumnRefNode) {
}

func (n *IndexItemNode) Descending() bool {
	return false
}

func (n *IndexItemNode) SetDescending(v bool) {
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
	return nil
}

func (n *UnnestItemNode) SetArrayExpr(v ExprNode) {
}

func (n *UnnestItemNode) ElementColumn() *Column {
	return nil
}

func (n *UnnestItemNode) SetElementColumn(v *Column) {
}

func (n *UnnestItemNode) ArrayOffsetColumn() *ColumnHolderNode {
	return nil
}

func (n *UnnestItemNode) SetArrayOffsetColumn(v *ColumnHolderNode) {
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
	return nil
}

func (n *CreateIndexStmtNode) SetTableNamePath(v []string) {
}

func (n *CreateIndexStmtNode) AddTableName(v string) {
}

func (n *CreateIndexStmtNode) TableScan() *TableScanNode {
	return nil
}

func (n *CreateIndexStmtNode) SetTableScan(v *TableScanNode) {
}

func (n *CreateIndexStmtNode) IsUnique() bool {
	return false
}

func (n *CreateIndexStmtNode) SetIsUnique(v bool) {
}

func (n *CreateIndexStmtNode) IsSearch() bool {
	return false
}

func (n *CreateIndexStmtNode) SetIsSearch(v bool) {
}

func (n *CreateIndexStmtNode) IndexAllColumns() bool {
	return false
}

func (n *CreateIndexStmtNode) SetIndexAllColumns(v bool) {
}

func (n *CreateIndexStmtNode) IndexItemList() []*IndexItemNode {
	return nil
}

func (n *CreateIndexStmtNode) SetIndexItemList(v []*IndexItemNode) {
}

func (n *CreateIndexStmtNode) AddIndexItem(v *IndexItemNode) {
}

func (n *CreateIndexStmtNode) StoringExpressionList() []ExprNode {
	return nil
}

func (n *CreateIndexStmtNode) SetStoringExpressionList(v []ExprNode) {
}

func (n *CreateIndexStmtNode) AddStoringExpression(v ExprNode) {
}

func (n *CreateIndexStmtNode) OptionList() []*OptionNode {
	return nil
}

func (n *CreateIndexStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *CreateIndexStmtNode) AddOption(v *OptionNode) {
}

func (n *CreateIndexStmtNode) ComputedColumnsList() []*ComputedColumnNode {
	return nil
}

func (n *CreateIndexStmtNode) SetComputedColumnList(v []*ComputedColumnNode) {
}

func (n *CreateIndexStmtNode) AddComputedColumn(v *ComputedColumnNode) {
}

func (n *CreateIndexStmtNode) UnnestExpressionList() []*UnnestItemNode {
	return nil
}

func (n *CreateIndexStmtNode) SetUnnestExpressionList(v []*UnnestItemNode) {
}

func (n *CreateIndexStmtNode) AddUnnestExpression(v *UnnestItemNode) {
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
	return nil
}

func (n *CreateSchemaStmtNode) SetCollationName(v ExprNode) {
}

func (n *CreateSchemaStmtNode) OptionList() []*OptionNode {
	return nil
}

func (n *CreateSchemaStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *CreateSchemaStmtNode) AddOption(v *OptionNode) {
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
	return nil
}

func (n *BaseCreateTableStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *BaseCreateTableStmtNode) AddOption(v *OptionNode) {
}

func (n *BaseCreateTableStmtNode) ColumnDefinitionList() []*ColumnDefinitionNode {
	return nil
}

func (n *BaseCreateTableStmtNode) SetColumnDefinitionList(v []*ColumnDefinitionNode) {
}

func (n *BaseCreateTableStmtNode) AddColumnDefinition(v *ColumnDefinitionNode) {
}

func (n *BaseCreateTableStmtNode) PseudoColumnList() []*Column {
	return nil
}

func (n *BaseCreateTableStmtNode) SetPseudoColumnList(v []*Column) {
}

func (n *BaseCreateTableStmtNode) AddPseudoColumn(v *Column) {
}

func (n *BaseCreateTableStmtNode) PrimaryKey() *PrimaryKeyNode {
	return nil
}

func (n *BaseCreateTableStmtNode) SetPrimaryKey(v *PrimaryKeyNode) {
}

func (n *BaseCreateTableStmtNode) ForeignKeyList() []*ForeignKeyNode {
	return nil
}

func (n *BaseCreateTableStmtNode) SetForeignKeyList(v []*ForeignKeyNode) {
}

func (n *BaseCreateTableStmtNode) AddForeignKey(v *ForeignKeyNode) {
}

func (n *BaseCreateTableStmtNode) CheckConstraintList() []*CheckConstraintNode {
	return nil
}

func (n *BaseCreateTableStmtNode) SetCheckConstraintList(v []*CheckConstraintNode) {
}

func (n *BaseCreateTableStmtNode) AddCheckConstraint(v *CheckConstraintNode) {
}

func (n *BaseCreateTableStmtNode) IsValueTable() bool {
	return false
}

func (n *BaseCreateTableStmtNode) SetIsValueTable(v bool) {
}

func (n *BaseCreateTableStmtNode) LikeTable() types.Table {
	return nil
}

func (n *BaseCreateTableStmtNode) SetLikeTable(v types.Table) {
}

func (n *BaseCreateTableStmtNode) CollationName() ExprNode {
	return nil
}

func (n *BaseCreateTableStmtNode) SetCollationName(v ExprNode) {
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
	return nil
}

func (n *CreateTableStmtNode) SetCloneFrom(v ScanNode) {
}

func (n *CreateTableStmtNode) CopyFrom() ScanNode {
	return nil
}

func (n *CreateTableStmtNode) SetCopyFrom(v ScanNode) {
}

func (n *CreateTableStmtNode) PartitionByList() []ExprNode {
	return nil
}

func (n *CreateTableStmtNode) SetPartitionByList(v []ExprNode) {
}

func (n *CreateTableStmtNode) AddPartitionBy(v ExprNode) {
}

func (n *CreateTableStmtNode) ClusterByList() []ExprNode {
	return nil
}

func (n *CreateTableStmtNode) SetClusterByList(v []ExprNode) {
}

func (n *CreateTableStmtNode) AddClusterBy(v ExprNode) {
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
	return nil
}

func (n *CreateTableAsSelectStmtNode) SetPartitionByList(v []ExprNode) {
}

func (n *CreateTableAsSelectStmtNode) AddPartitionBy(v ExprNode) {
}

func (n *CreateTableAsSelectStmtNode) ClusterByList() []ExprNode {
	return nil
}

func (n *CreateTableAsSelectStmtNode) SetClusterByList(v []ExprNode) {
}

func (n *CreateTableAsSelectStmtNode) AddClusterBy(v ExprNode) {
}

func (n *CreateTableAsSelectStmtNode) OutputColumnList() []*OutputColumnNode {
	return nil
}

func (n *CreateTableAsSelectStmtNode) SetOutputColumnList(v []*OutputColumnNode) {
}

func (n *CreateTableAsSelectStmtNode) AddOutputColumn(v *OutputColumnNode) {
}

func (n *CreateTableAsSelectStmtNode) Query() ScanNode {
	return nil
}

func (n *CreateTableAsSelectStmtNode) SetQuery(v ScanNode) {
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
	return nil
}

func (n *CreateModelStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *CreateModelStmtNode) AddOption(v *OptionNode) {
}

func (n *CreateModelStmtNode) OutputColumnList() []*OutputColumnNode {
	return nil
}

func (n *CreateModelStmtNode) SetOutputColumnList(v []*OutputColumnNode) {
}

func (n *CreateModelStmtNode) AddOutputColumn(v *OutputColumnNode) {
}

func (n *CreateModelStmtNode) Query() ScanNode {
	return nil
}

func (n *CreateModelStmtNode) SetQuery(v ScanNode) {
}

func (n *CreateModelStmtNode) TransformInputColumnList() []*ColumnDefinitionNode {
	return nil
}

func (n *CreateModelStmtNode) SetTransformInputColumnList(v []*ColumnDefinitionNode) {
}

func (n *CreateModelStmtNode) AddTransformInputColumn(v *ColumnDefinitionNode) {
}

func (n *CreateModelStmtNode) TransformList() []*ComputedColumnNode {
	return nil
}

func (n *CreateModelStmtNode) SetTransformList(v []*ComputedColumnNode) {
}

func (n *CreateModelStmtNode) AddTransform(v *ComputedColumnNode) {
}

func (n *CreateModelStmtNode) TransformOutputColumnList() []*OutputColumnNode {
	return nil
}

func (n *CreateModelStmtNode) SetTransformOutputColumnList(v []*OutputColumnNode) {
}

func (n *CreateModelStmtNode) AddTransformOutputColumn(v *OutputColumnNode) {
}

func (n *CreateModelStmtNode) TransformAnalyticFunctionGroupList() []*AnalyticFunctionGroupNode {
	return nil
}

func (n *CreateModelStmtNode) SetTransformAnalyticFunctionGroupList(v []*AnalyticFunctionGroupNode) {
}

func (n *CreateModelStmtNode) AddTransformAnalyticFunctionGroup(v *AnalyticFunctionGroupNode) {
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
	return nil
}

func (n *BaseCreateViewNode) SetOptionList(v []*OptionNode) {
}

func (n *BaseCreateViewNode) AddOption(v *OptionNode) {
}

func (n *BaseCreateViewNode) OutputColumnList() []*OutputColumnNode {
	return nil
}

func (n *BaseCreateViewNode) SetOutputColumnList(v []*OutputColumnNode) {
}

func (n *BaseCreateViewNode) AddOutputColumn(v *OutputColumnNode) {
}

func (n *BaseCreateViewNode) HasExplicitColumns() bool {
	return false
}

func (n *BaseCreateViewNode) SetHasExplicitColumns(v bool) {
}

func (n *BaseCreateViewNode) Query() ScanNode {
	return nil
}

func (n *BaseCreateViewNode) SetQuery(v ScanNode) {
}

func (n *BaseCreateViewNode) SQL() string {
	return ""
}

func (n *BaseCreateViewNode) SetSQL(v string) {
}

func (n *BaseCreateViewNode) SQLSecurity() SQLSecurity {
	return SQLSecurity(0)
}

func (n *BaseCreateViewNode) SetSQLSecurity(v SQLSecurity) {
}

func (n *BaseCreateViewNode) IsValueTable() bool {
	return false
}

func (n *BaseCreateViewNode) SetIsValueTable(v bool) {
}

func (n *BaseCreateViewNode) Recursive() bool {
	return false
}

func (n *BaseCreateViewNode) SetRecursive(v bool) {
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
	return nil
}

func (n *WithPartitionColumnsNode) SetColumnDefinitionList(v []*ColumnDefinitionNode) {
}

func (n *WithPartitionColumnsNode) AddColumnDefinition(v *ColumnDefinitionNode) {
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
	return nil
}

func (n *CreateSnapshotTableStmtNode) SetCloneFrom(v ScanNode) {
}

func (n *CreateSnapshotTableStmtNode) OptionList() []*OptionNode {
	return nil
}

func (n *CreateSnapshotTableStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *CreateSnapshotTableStmtNode) AddOption(v *OptionNode) {
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
	return nil
}

func (n *CreateExternalTableStmtNode) SetWithPartitionColumns(v *WithPartitionColumnsNode) {
}

func (n *CreateExternalTableStmtNode) Connection() *ConnectionNode {
	return nil
}

func (n *CreateExternalTableStmtNode) SetConnection(v *ConnectionNode) {
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
	return nil
}

func (n *ExportModelStmtNode) SetModelNamePath(v []string) {
}

func (n *ExportModelStmtNode) AddModelName(v string) {
}

func (n *ExportModelStmtNode) Connection() *ConnectionNode {
	return nil
}

func (n *ExportModelStmtNode) SetConnection(v *ConnectionNode) {
}

func (n *ExportModelStmtNode) OptionList() []*OptionNode {
	return nil
}

func (n *ExportModelStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *ExportModelStmtNode) AddOption(v *OptionNode) {
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
	return nil
}

func (n *ExportDataStmtNode) SetConnection(v *ConnectionNode) {
}

func (n *ExportDataStmtNode) OptionList() []*OptionNode {
	return nil
}

func (n *ExportDataStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *ExportDataStmtNode) AddOption(v *OptionNode) {
}

func (n *ExportDataStmtNode) OutputColumnList() []*OutputColumnNode {
	return nil
}

func (n *ExportDataStmtNode) SetOutputColumnList(v []*OutputColumnNode) {
}

func (n *ExportDataStmtNode) AddOutputColumn(v *OutputColumnNode) {
}

func (n *ExportDataStmtNode) IsValueTable() bool {
	return false
}

func (n *ExportDataStmtNode) SetIsValueTable(v bool) {
}

func (n *ExportDataStmtNode) Query() ScanNode {
	return nil
}

func (n *ExportDataStmtNode) SetQuery(v ScanNode) {
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
	return nil
}

func (n *DefineTableStmtNode) SetNamePath(v []string) {
}

func (n *DefineTableStmtNode) AddName(v string) {
}

func (n *DefineTableStmtNode) OptionList() []*OptionNode {
	return nil
}

func (n *DefineTableStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *DefineTableStmtNode) AddOption(v *OptionNode) {
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
	return ""
}

func (n *DescribeStmtNode) SetObjectType(v string) {
}

func (n *DescribeStmtNode) NamePath() []string {
	return nil
}

func (n *DescribeStmtNode) SetNamePath(v []string) {
}

func (n *DescribeStmtNode) AddName(v string) {
}

func (n *DescribeStmtNode) FromNamePath() []string {
	return nil
}

func (n *DescribeStmtNode) SetFromNamePath(v []string) {
}

func (n *DescribeStmtNode) AddFromName(v string) {
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
	return ""
}

func (n *ShowStmtNode) SetIdentifier(v string) {
}

func (n *ShowStmtNode) NamePath() []string {
	return nil
}

func (n *ShowStmtNode) SetNamePath(v []string) {
}

func (n *ShowStmtNode) AddName(v string) {
}

func (n *ShowStmtNode) LikeExpr() *LiteralNode {
	return nil
}

func (n *ShowStmtNode) SetLikeExpr(v *LiteralNode) {
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
	return ReadWriteMode(0)
}

func (n *BeginStmtNode) SetReadWriteMode(v ReadWriteMode) {
}

func (n *BeginStmtNode) IsolationLevelList() []string {
	return nil
}

func (n *BeginStmtNode) SetIsolationLevelList(v []string) {
}

func (n *BeginStmtNode) AddIsolationLevel(v string) {
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
	return ReadWriteMode(0)
}

func (n *SetTransactionStmtNode) SetReadWriteMode(v ReadWriteMode) {
}

func (n *SetTransactionStmtNode) IsolationLevelList() []string {
	return nil
}

func (n *SetTransactionStmtNode) SetIsolationLevelList(v []string) {
}

func (n *SetTransactionStmtNode) AddIsolationLevel(v string) {
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
	return ""
}

func (n *StartBatchStmtNode) SetBatchType(v string) {
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
	return ""
}

func (n *DropStmtNode) SetObjectType(v string) {
}

func (n *DropStmtNode) IsIfExists() bool {
	return false
}

func (n *DropStmtNode) SetIsIfExists(v bool) {
}

func (n *DropStmtNode) NamePath() []string {
	return nil
}

func (n *DropStmtNode) SetNamePath(v []string) {
}

func (n *DropStmtNode) AddName(v string) {
}

func (n *DropStmtNode) DropMode() DropMode {
	return DropMode(0)
}

func (n *DropStmtNode) SetDropMode(v DropMode) {
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
	return false
}

func (n *DropMaterializedViewStmtNode) SetIsIfExists(v bool) {
}

func (n *DropMaterializedViewStmtNode) NamePath() []string {
	return nil
}

func (n *DropMaterializedViewStmtNode) SetNamePath(v []string) {
}

func (n *DropMaterializedViewStmtNode) AddName(v string) {
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
	return false
}

func (n *DropSnapshotTableStmtNode) SetIsIfExists(v bool) {
}

func (n *DropSnapshotTableStmtNode) NamePath() []string {
	return nil
}

func (n *DropSnapshotTableStmtNode) SetNamePath(v []string) {
}

func (n *DropSnapshotTableStmtNode) AddName(v string) {
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
	return RecursiveSetOperationType(0)
}

func (n *RecursiveScanNode) SetOpType(v RecursiveSetOperationType) {
}

func (n *RecursiveScanNode) NonRecursiveTerm() *SetOperationItemNode {
	return nil
}

func (n *RecursiveScanNode) SetNonRecursiveTerm(v *SetOperationItemNode) {
}

func (n *RecursiveScanNode) RecursiveTerm() *SetOperationItemNode {
	return nil
}

func (n *RecursiveScanNode) SetRecursiveTerm(v *SetOperationItemNode) {
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
	return nil
}

func (n *WithScanNode) SetWithEntryList(v []*WithEntryNode) {
}

func (n *WithScanNode) AddWithEntry(v *WithEntryNode) {
}

func (n *WithScanNode) Query() ScanNode {
	return nil
}

func (n *WithScanNode) SetQuery(v ScanNode) {
}

// Recursive true if the WITH clause uses the recursive keyword.
func (n *WithScanNode) Recursive() bool {
	return false
}

func (n *WithScanNode) SetRecursive(v bool) {
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
	return ""
}

func (n *WithEntryNode) SetWithQueryName(v string) {
}

func (n *WithEntryNode) WithSubquery() ScanNode {
	return nil
}

func (n *WithEntryNode) SetWithSubquery(v ScanNode) {
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
	return ""
}

func (n *OptionNode) SetQualifier(v string) {
}

func (n *OptionNode) Name() string {
	return ""
}

func (n *OptionNode) SetName(v string) {
}

func (n *OptionNode) Value() ExprNode {
	return nil
}

func (n *OptionNode) SetValue(v ExprNode) {
}

// WindowPartitioningNode window partitioning specification for an analytic function call.
//
// PARTITION BY keys in <partition_by_list>.
type WindowPartitioningNode struct {
	*BaseArgumentNode
}

func (n *WindowPartitioningNode) PartitionByList() []*ColumnRefNode {
	return nil
}

func (n *WindowPartitioningNode) SetPartitionByList(v []*ColumnRefNode) {
}

func (n *WindowPartitioningNode) AddPartitionBy(v *ColumnRefNode) {
}

func (n *WindowPartitioningNode) HintList() []*OptionNode {
	return nil
}

func (n *WindowPartitioningNode) SetHintList(v []*OptionNode) {
}

func (n *WindowPartitioningNode) AddHint(v *OptionNode) {
}

// WindowOrderingNode window ordering specification for an analytic function call.
//
// ORDER BY items in <order_by_list>. There should be exactly one ORDER
// BY item if this is a window ORDER BY for a RANGE-based window.
type WindowOrderingNode struct {
	*BaseArgumentNode
}

func (n *WindowOrderingNode) OrderByItemList() []*OrderByItemNode {
	return nil
}

func (n *WindowOrderingNode) SetOrderByItemList(v []*OrderByItemNode) {
}

func (n *WindowOrderingNode) AddOrderByItem(v *OrderByItemNode) {
}

func (n *WindowOrderingNode) HintList() []*OptionNode {
	return nil
}

func (n *WindowOrderingNode) SetHintList(v []*OptionNode) {
}

func (n *WindowOrderingNode) AddHint(v *OptionNode) {
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
	return FrameUnit(0)
}

func (n *WindowFrameNode) SetFrameUnit(v FrameUnit) {
}

func (n *WindowFrameNode) StartExpr() *WindowFrameExprNode {
	return nil
}

func (n *WindowFrameNode) SetStartExpr(v *WindowFrameExprNode) {
}

func (n *WindowFrameNode) EndExpr() *WindowFrameExprNode {
	return nil
}

func (n *WindowFrameNode) SetEndExpr(v *WindowFrameExprNode) {
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
	return nil
}

func (n *AnalyticFunctionGroupNode) SetPartitionBy(v *WindowPartitioningNode) {
}

func (n *AnalyticFunctionGroupNode) OrderBy() *WindowOrderingNode {
	return nil
}

func (n *AnalyticFunctionGroupNode) SetOrderBy(v *WindowOrderingNode) {
}

func (n *AnalyticFunctionGroupNode) AnalyticFunctionList() []*ComputedColumnNode {
	return nil
}

func (n *AnalyticFunctionGroupNode) SetAnalyticFunctionList(v []*ComputedColumnNode) {
}

func (n *AnalyticFunctionGroupNode) AddAnalyticFunction(v *ComputedColumnNode) {
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
	return BoundaryType(0)
}

func (n *WindowFrameExprNode) SetBoundaryType(v BoundaryType) {
}

func (n *WindowFrameExprNode) Expression() ExprNode {
	return nil
}

func (n *WindowFrameExprNode) SetExpression(v ExprNode) {
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
	return nil
}

func (n *DMLValueNode) SetValue(v ExprNode) {
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
	return nil
}

func (n *AssertStmtNode) SetExpression(v ExprNode) {
}

func (n *AssertStmtNode) Description() string {
	return ""
}

func (n *AssertStmtNode) SetDescription(v string) {
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
	return nil
}

func (n *AssertRowsModifiedNode) SetRows(v ExprNode) {
}

// InsertRowNode represents one row in the VALUES clause of an INSERT.
type InsertRowNode struct {
	*BaseArgumentNode
}

func (n *InsertRowNode) ValueList() []*DMLValueNode {
	return nil
}

func (n *InsertRowNode) SetValueList(v []*DMLValueNode) {
}

func (n *InsertRowNode) AddValue(v *DMLValueNode) {
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
	return nil
}

func (n *InsertStmtNode) SetTableScan(v *TableScanNode) {
}

func (n *InsertStmtNode) InsertMode() InsertMode {
	return InsertMode(0)
}

func (n *InsertStmtNode) SetInsertMode(v InsertMode) {
}

func (n *InsertStmtNode) AssertRowsModified() *AssertRowsModifiedNode {
	return nil
}

func (n *InsertStmtNode) SetAssertRowsModified(v *AssertRowsModifiedNode) {
}

func (n *InsertStmtNode) Returning() *ReturningClauseNode {
	return nil
}

func (n *InsertStmtNode) SetReturning(v *ReturningClauseNode) {
}

func (n *InsertStmtNode) InsertColumnList() []*Column {
	return nil
}

func (n *InsertStmtNode) SetInsertColumnList(v []*Column) {
}

func (n *InsertStmtNode) AddInsertColumn(v *Column) {
}

func (n *InsertStmtNode) QueryParameterList() []*ColumnRefNode {
	return nil
}

func (n *InsertStmtNode) SetQueryParameterList(v []*ColumnRefNode) {
}

func (n *InsertStmtNode) AddQueryParameter(v *ColumnRefNode) {
}

func (n *InsertStmtNode) Query() ScanNode {
	return nil
}

func (n *InsertStmtNode) SetQuery(v ScanNode) {
}

func (n *InsertStmtNode) QueryOutputColumnList() []*Column {
	return nil
}

func (n *InsertStmtNode) SetQueryOutputColumnList(v []*Column) {
}

func (n *InsertStmtNode) AddQueryOutputColumn(v *Column) {
}

func (n *InsertStmtNode) RowList() []*InsertRowNode {
	return nil
}

func (n *InsertStmtNode) SetRowList(v []*InsertRowNode) {
}

func (n *InsertStmtNode) AddRow(v *InsertRowNode) {
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
	return nil
}

func (n *DeleteStmtNode) SetTableScan(v *TableScanNode) {
}

func (n *DeleteStmtNode) AssertRowsModified() *AssertRowsModifiedNode {
	return nil
}

func (n *DeleteStmtNode) SetAssertRowsModified(v *AssertRowsModifiedNode) {
}

func (n *DeleteStmtNode) Returning() *ReturningClauseNode {
	return nil
}

func (n *DeleteStmtNode) SetReturning(v *ReturningClauseNode) {
}

func (n *DeleteStmtNode) ArrayOffsetColumn() *ColumnHolderNode {
	return nil
}

func (n *DeleteStmtNode) SetArrayOffsetColumn(v *ColumnHolderNode) {
}

func (n *DeleteStmtNode) WhereExpr() ExprNode {
	return nil
}

func (n *DeleteStmtNode) SetWhereExpr(v ExprNode) {
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
	return nil
}

func (n *UpdateItemNode) SetTarget(v ExprNode) {
}

// SetValue set the target entity to this value.  The types must match.
// This can contain the same columns that can appear in the
// <where_expr> of the enclosing UpdateStmtNode.
//
// This is mutually exclusive with all fields below, which are used
// for nested updates only.
func (n *UpdateItemNode) SetValue() *DMLValueNode {
	return nil
}

func (n *UpdateItemNode) SetSetValue(v *DMLValueNode) {
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
	return nil
}

func (n *UpdateItemNode) SetElementColumn(v *ColumnHolderNode) {
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
	return nil
}

func (n *UpdateItemNode) SetArrayUpdateList(v []*UpdateArrayItemNode) {
}

func (n *UpdateItemNode) AddArrayUpdate(v *UpdateArrayItemNode) {
}

// DeleteList nested DELETE statements to apply.  Each delete runs on one value
// of <element_column> and may choose to delete that array element.
//
// DELETEs are applied before INSERTs or UPDATEs.
//
// It is legal for the same input element to match multiple DELETEs.
func (n *UpdateItemNode) DeleteList() []*DeleteStmtNode {
	return nil
}

func (n *UpdateItemNode) SetDeleteList(v []*DeleteStmtNode) {
}

func (n *UpdateItemNode) AddDelete(v *DeleteStmtNode) {
}

// UpdateList nested UPDATE statements to apply.  Each update runs on one value
// of <element_column> and may choose to update that array element.
//
// UPDATEs are applied after DELETEs and before INSERTs.
//
// It is an error if any element is matched by multiple UPDATEs.
func (n *UpdateItemNode) UpdateList() []*UpdateStmtNode {
	return nil
}

func (n *UpdateItemNode) SetUpdateList(v []*UpdateStmtNode) {
}

func (n *UpdateItemNode) AddUpdate(v *UpdateStmtNode) {
}

// InsertList nested INSERT statements to apply.  Each insert will produce zero
// or more values for <element_column>.
//
// INSERTs are applied after DELETEs and UPDATEs.
//
// For nested UPDATEs, insert_mode will always be the default, and has no effect.
func (n *UpdateItemNode) InsertList() []*InsertStmtNode {
	return nil
}

func (n *UpdateItemNode) SetInsertList(v []*InsertStmtNode) {
}

func (n *UpdateItemNode) AddInsert(v *InsertStmtNode) {
}

// UpdateArrayItemNode for an array element modification, this node represents the offset
// expression and the modification, but not the array. E.g., for
// SET a[<expr>] = 5, this node represents a modification of "= 5" to offset
// <expr> of the array defined by the parent node.
type UpdateArrayItemNode struct {
	*BaseArgumentNode
}

func (n *UpdateArrayItemNode) Offset() ExprNode {
	return nil
}

func (n *UpdateArrayItemNode) SetOffset(v ExprNode) {
}

func (n *UpdateArrayItemNode) UpdateItem() *UpdateItemNode {
	return nil
}

func (n *UpdateArrayItemNode) SetUpdateItem(v *UpdateItemNode) {
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
	return nil
}

func (n *UpdateStmtNode) SetTableScan(v *TableScanNode) {
}

func (n *UpdateStmtNode) ColumnAccessList() []ObjectAccess {
	return nil
}

func (n *UpdateStmtNode) SetColumnAccessList(v []ObjectAccess) {
}

func (n *UpdateStmtNode) AddColumnAccess(v ObjectAccess) {
}

func (n *UpdateStmtNode) AssertRowsModified() *AssertRowsModifiedNode {
	return nil
}

func (n *UpdateStmtNode) SetAssertRowsModified(v *AssertRowsModifiedNode) {
}

func (n *UpdateStmtNode) Returning() *ReturningClauseNode {
	return nil
}

func (n *UpdateStmtNode) SetReturning(v *ReturningClauseNode) {
}

func (n *UpdateStmtNode) ArrayOffsetColumn() *ColumnHolderNode {
	return nil
}

func (n *UpdateStmtNode) SetArrayOffsetColumn(v *ColumnHolderNode) {
}

func (n *UpdateStmtNode) WhereExpr() ExprNode {
	return nil
}

func (n *UpdateStmtNode) SetWhereExpr(v ExprNode) {
}

func (n *UpdateStmtNode) UpdateItemList() []*UpdateItemNode {
	return nil
}

func (n *UpdateStmtNode) SetUpdateItemList(v []*UpdateItemNode) {
}

func (n *UpdateStmtNode) AddUpdateItemList(v *UpdateItemNode) {
}

func (n *UpdateStmtNode) FromScan() ScanNode {
	return nil
}

func (n *UpdateStmtNode) SetFromScan(v ScanNode) {
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
	return MatchType(0)
}

func (n *MergeWhenNode) SetMatchType(v MatchType) {
}

func (n *MergeWhenNode) MatchExpr() ExprNode {
	return nil
}

func (n *MergeWhenNode) SetMatchExpr(v ExprNode) {
}

func (n *MergeWhenNode) ActionType() ActionType {
	return ActionType(0)
}

func (n *MergeWhenNode) SetActionType(v ActionType) {
}

func (n *MergeWhenNode) InsertColumnList() []*Column {
	return nil
}

func (n *MergeWhenNode) SetInsertColumnList(v []*Column) {
}

func (n *MergeWhenNode) AddInsertColumn(v *Column) {
}

func (n *MergeWhenNode) InsertRow() *InsertRowNode {
	return nil
}

func (n *MergeWhenNode) SetInsertRow(v *InsertRowNode) {
}

func (n *MergeWhenNode) UpdateItemList() []*UpdateItemNode {
	return nil
}

func (n *MergeWhenNode) SetUpdateItemList(v []*UpdateItemNode) {
}

func (n *MergeWhenNode) AddUpdateItem(v *UpdateItemNode) {

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

func (n *MergeStmtNode) FromScan() ScanNode {
	return nil
}

func (n *MergeStmtNode) SetFromScan(v ScanNode) {
}

func (n *MergeStmtNode) MergeExpr() ExprNode {
	return nil
}

func (n *MergeStmtNode) SetMergeExpr(v ExprNode) {
}

func (n *MergeStmtNode) WhenClauseList() []*MergeWhenNode {
	return nil
}

func (n *MergeStmtNode) SetWhenClauseList(v []*MergeWhenNode) {
}

func (n *MergeStmtNode) AddWhenClause(v *MergeWhenNode) {
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
	return nil
}

func (n *TruncateStmtNode) SetTableScan(v *TableScanNode) {
}

func (n *TruncateStmtNode) WhereExpr() ExprNode {
	return nil
}

func (n *TruncateStmtNode) SetWhereExpr(v ExprNode) {
}

// ObjectUnitNode a reference to a unit of an object (e.g. a column or field of a table).
//
// <name_path> is a vector giving the identifier path of the object unit.
type ObjectUnitNode struct {
	*BaseArgumentNode
}

func (n *ObjectUnitNode) NamePath() []string {
	return nil
}

func (n *ObjectUnitNode) SetNamePath(v []string) {
}

func (n *ObjectUnitNode) AddName(v string) {
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
	return ""
}

func (n *PrivilegeNode) SetActionType(v string) {
}

func (n *PrivilegeNode) UnitList() []*ObjectUnitNode {
	return nil
}

func (n *PrivilegeNode) SetUnitList(v []*ObjectUnitNode) {
}

func (n *PrivilegeNode) AddUnit(v *ObjectUnitNode) {
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
	return nil
}

func (n *GrantOrRevokeStmtNode) SetPrivilegeList(v []*PrivilegeNode) {
}

func (n *GrantOrRevokeStmtNode) AddPrivilege(v *PrivilegeNode) {
}

func (n *GrantOrRevokeStmtNode) ObjectType() string {
	return ""
}

func (n *GrantOrRevokeStmtNode) SetObjectType(v string) {
}

func (n *GrantOrRevokeStmtNode) NamePath() []string {
	return nil
}

func (n *GrantOrRevokeStmtNode) SetNamePath(v []string) {
}

func (n *GrantOrRevokeStmtNode) AddName(v string) {
}

func (n *GrantOrRevokeStmtNode) GranteeList() []string {
	return nil
}

func (n *GrantOrRevokeStmtNode) SetGranteeList(v []string) {
}

func (n *GrantOrRevokeStmtNode) AddGrantee(v string) {
}

func (n *GrantOrRevokeStmtNode) GranteeExprList() []ExprNode {
	return nil
}

func (n *GrantOrRevokeStmtNode) SetGranteeExprList(v []ExprNode) {
}

func (n *GrantOrRevokeStmtNode) AddGranteeExpr(v ExprNode) {
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
	return nil
}

func (n *AlterObjectStmtNode) SetNamePath(v []string) {
}

func (n *AlterObjectStmtNode) AddName(v string) {
}

func (n *AlterObjectStmtNode) AlterActionList() []*AlterActionNode {
	return nil
}

func (n *AlterObjectStmtNode) SetAlterActionList(v []*AlterActionNode) {
}

func (n *AlterObjectStmtNode) AddAlterAction(v *AlterActionNode) {
}

func (n *AlterObjectStmtNode) IsIfExists() bool {
	return false
}

func (n *AlterObjectStmtNode) SetIsIfExists(v bool) {
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
	return false
}

func (n *BaseAlterColumnActionNode) SetIsIfExists(v bool) {
}

func (n *BaseAlterColumnActionNode) Column() string {
	return ""
}

func (n *BaseAlterColumnActionNode) SetColumn(v string) {
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
	return nil
}

func (n *SetOptionsActionNode) SetOptionList(v []*OptionNode) {
}

func (n *SetOptionsActionNode) AddOption(v *OptionNode) {
}

// AddColumnActionNode
// ADD COLUMN action for ALTER TABLE statement.
type AddColumnActionNode struct {
	*BaseAlterActionNode
}

func (n *AddColumnActionNode) IsIfNotExists() bool {
	return false
}

func (n *AddColumnActionNode) SetIsIfNotExists(v bool) {
}

func (n *AddColumnActionNode) ColumnDefinition() *ColumnDefinitionNode {
	return nil
}

func (n *AddColumnActionNode) SetColumnDefinition(v *ColumnDefinitionNode) {
}

// AddConstraintActionNode
// ADD CONSTRAINT for ALTER TABLE statement.
type AddConstraintActionNode struct {
	*BaseAlterActionNode
}

func (n *AddConstraintActionNode) IsIfNotExists() bool {
	return false
}

func (n *AddConstraintActionNode) SetIsIfNotExists(v bool) {
}

func (n *AddConstraintActionNode) Constraint() *ConstraintNode {
	return nil
}

func (n *AddConstraintActionNode) SetConstraint(v *ConstraintNode) {
}

func (n *AddConstraintActionNode) Table() types.Table {
	return nil
}

func (n *AddConstraintActionNode) SetTable(v types.Table) {
}

// DropConstraintActionNode
// DROP CONSTRAINT for ALTER TABLE statement.
type DropConstraintActionNode struct {
	*BaseAlterActionNode
}

func (n *DropConstraintActionNode) IsIfExists() bool {
	return false
}

func (n *DropConstraintActionNode) SetIsIfExists(v bool) {
}

func (n *DropConstraintActionNode) Name() string {
	return ""
}

func (n *DropConstraintActionNode) SetName(v string) {
}

// DropPrimaryKeyActionNode
// DROP PRIMARY KEY [IF EXISTS] for ALTER TABLE statement.
type DropPrimaryKeyActionNode struct {
	*BaseAlterActionNode
}

func (n *DropPrimaryKeyActionNode) IsIfExists() bool {
	return false
}

func (n *DropPrimaryKeyActionNode) SetIsIfExists(v bool) {
}

// AlterColumnOptionsActionNode
type AlterColumnOptionsActionNode struct {
	*BaseAlterColumnActionNode
}

func (n *AlterColumnOptionsActionNode) OptionList() []*OptionNode {
	return nil
}

func (n *AlterColumnOptionsActionNode) SetOptionList(v []*OptionNode) {
}

func (n *AlterColumnOptionsActionNode) AddOption(v *OptionNode) {
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
	return nil
}

func (n *AlterColumnSetDataTypeActionNode) SetUpdatedType(v types.Type) {
}

// UpdatedTypeParameters the new type parameters for the column, if the new type has
// parameters. Note that unlike with CREATE TABLE, the child_list is
// populated for ARRAY and STRUCT types.
// TODO Use updated_annotations to pass type parameters.
func (n *AlterColumnSetDataTypeActionNode) UpdatedTypeParameters() *types.TypeParameters {
	return nil
}

func (n *AlterColumnSetDataTypeActionNode) SetUpdatedTypeParameters(v *types.TypeParameters) {
}

// UpdatedAnnotations the new annotations for the column including the new collation
// specifications. Changing options using SET DATA TYPE action is not allowed.
func (n *AlterColumnSetDataTypeActionNode) UpdatedAnnotations() *ColumnAnnotationsNode {
	return nil
}

func (n *AlterColumnSetDataTypeActionNode) SetUpdatedAnnotations(v *ColumnAnnotationsNode) {
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
	return nil
}

func (n *AlterColumnSetDefaultActionNode) SetDefaultValue(v *ColumnDefaultValueNode) {
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
	return false
}

func (n *DropColumnActionNode) SetIsIfExists(v bool) {
}

func (n *DropColumnActionNode) Name() string {
	return ""
}

func (n *DropColumnActionNode) SetName(v string) {
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
	return false
}

func (n *RenameColumnActionNode) SetIsIfExists(v bool) {
}

func (n *RenameColumnActionNode) Name() string {
	return ""
}

func (n *RenameColumnActionNode) SetName(v string) {
}

func (n *RenameColumnActionNode) NewName() string {
	return ""
}

func (n *RenameColumnActionNode) SetNewName(v string) {
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
	return ""
}

func (n *SetAsActionNode) SetEntityBodyJSON(v string) {
}

func (n *SetAsActionNode) EntityBodyText() string {
	return ""
}

func (n *SetAsActionNode) SetEntityBodyText(v string) {
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
	return nil
}

func (n *SetCollateClauseNode) SetCollationName(v ExprNode) {
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
	return nil
}

func (n *AlterTableSetOptionsStmtNode) SetNamePath(v []string) {
}

func (n *AlterTableSetOptionsStmtNode) AddName(v string) {
}

func (n *AlterTableSetOptionsStmtNode) OptionList() []*OptionNode {
	return nil
}

func (n *AlterTableSetOptionsStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *AlterTableSetOptionsStmtNode) AddOption(v *OptionNode) {
}

func (n *AlterTableSetOptionsStmtNode) IsIfExists() bool {
	return false
}

func (n *AlterTableSetOptionsStmtNode) SetIsIfExists(v bool) {
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
	return ""
}

func (n *RenameStmtNode) SetObjectType(v string) {
}

func (n *RenameStmtNode) OldNamePath() []string {
	return nil
}

func (n *RenameStmtNode) SetOldNamePath(v []string) {
}

func (n *RenameStmtNode) AddOldName(v string) {
}

func (n *RenameStmtNode) NewNamePath() []string {
	return nil
}

func (n *RenameStmtNode) SetNewNamePath(v []string) {
}

func (n *RenameStmtNode) AddNewName(v string) {
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
	return nil
}

func (n *CreatePrivilegeRestrictionStmtNode) SetColumnPrivilegeList(v []*PrivilegeNode) {
}

func (n *CreatePrivilegeRestrictionStmtNode) AddColumnPrivilege(v *PrivilegeNode) {
}

func (n *CreatePrivilegeRestrictionStmtNode) ObjectType() string {
	return ""
}

func (n *CreatePrivilegeRestrictionStmtNode) SetObjectType(v string) {
}

func (n *CreatePrivilegeRestrictionStmtNode) RestricteeList() []ExprNode {
	return nil
}

func (n *CreatePrivilegeRestrictionStmtNode) SetRestricteeList(v []ExprNode) {
}

func (n *CreatePrivilegeRestrictionStmtNode) AddRestrictee(v ExprNode) {
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
	return CreateMode(0)
}

func (n *CreateRowAccessPolicyStmtNode) SetCreateMode(v CreateMode) {
}

func (n *CreateRowAccessPolicyStmtNode) Name() string {
	return ""
}

func (n *CreateRowAccessPolicyStmtNode) SetName(v string) {
}

func (n *CreateRowAccessPolicyStmtNode) TargetNamePath() []string {
	return nil
}

func (n *CreateRowAccessPolicyStmtNode) SetTargetNamePath(v []string) {
}

func (n *CreateRowAccessPolicyStmtNode) AddTargetName(v string) {
}

func (n *CreateRowAccessPolicyStmtNode) GranteeList() []string {
	return nil
}

func (n *CreateRowAccessPolicyStmtNode) SetGranteeList(v []string) {
}

func (n *CreateRowAccessPolicyStmtNode) AddGrantee(v string) {
}

func (n *CreateRowAccessPolicyStmtNode) GranteeExprList() []ExprNode {
	return nil
}

func (n *CreateRowAccessPolicyStmtNode) SetGranteeExprList(v []ExprNode) {
}

func (n *CreateRowAccessPolicyStmtNode) AddGranteeExpr(v ExprNode) {
}

func (n *CreateRowAccessPolicyStmtNode) TableScan() *TableScanNode {
	return nil
}

func (n *CreateRowAccessPolicyStmtNode) SetTableScan(v *TableScanNode) {
}

func (n *CreateRowAccessPolicyStmtNode) Predicate() ExprNode {
	return nil
}

func (n *CreateRowAccessPolicyStmtNode) SetPredicate(v ExprNode) {
}

func (n *CreateRowAccessPolicyStmtNode) PredicateStr() string {
	return ""
}

func (n *CreateRowAccessPolicyStmtNode) SetPredicateStr(v string) {
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
	return ""
}

func (n *DropPrivilegeRestrictionStmtNode) SetObjectType(v string) {
}

func (n *DropPrivilegeRestrictionStmtNode) IsIfExists() bool {
	return false
}

func (n *DropPrivilegeRestrictionStmtNode) SetIsIfExists(v bool) {
}

func (n *DropPrivilegeRestrictionStmtNode) NamePath() []string {
	return nil
}

func (n *DropPrivilegeRestrictionStmtNode) SetNamePath(v []string) {
}

func (n *DropPrivilegeRestrictionStmtNode) AddName(v string) {
}

func (n *DropPrivilegeRestrictionStmtNode) ColumnPrivilegeList() []*PrivilegeNode {
	return nil
}

func (n *DropPrivilegeRestrictionStmtNode) SetColumnPrivilegeList(v []*PrivilegeNode) {
}

func (n *DropPrivilegeRestrictionStmtNode) AddColumnPrivilege(v *PrivilegeNode) {
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
	return false
}

func (n *DropRowAccessPolicyStmtNode) SetIsDropAll(v bool) {
}

func (n *DropRowAccessPolicyStmtNode) IsIfExists() bool {
	return false
}

func (n *DropRowAccessPolicyStmtNode) SetIsIfExists(v bool) {
}

func (n *DropRowAccessPolicyStmtNode) Name() string {
	return ""
}

func (n *DropRowAccessPolicyStmtNode) SetName(v string) {
}

func (n *DropRowAccessPolicyStmtNode) TargetNamePath() []string {
	return nil
}

func (n *DropRowAccessPolicyStmtNode) SetTargetNamePath(v []string) {
}

func (n *DropRowAccessPolicyStmtNode) AddTargetName(v string) {
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
	return false
}

func (n *DropSearchIndexStmtNode) SetIsIfExists(v bool) {
}

func (n *DropSearchIndexStmtNode) Name() string {
	return ""
}

func (n *DropSearchIndexStmtNode) SetName(v string) {
}

func (n *DropSearchIndexStmtNode) TableNamePath() []string {
	return nil
}

func (n *DropSearchIndexStmtNode) SetTableNamePath(v []string) {
}

func (n *DropSearchIndexStmtNode) AddTableName(v string) {
}

// GrantToActionNode
// GRANT TO action for ALTER ROW ACCESS POLICY statement
//
// <grantee_expr_list> is the list of grantees, and may include parameters.
type GrantToActionNode struct {
	*BaseAlterActionNode
}

func (n *GrantToActionNode) GranteeExprList() []ExprNode {
	return nil
}

func (n *GrantToActionNode) SetGranteeExprList(v []ExprNode) {
}

func (n *GrantToActionNode) AddGranteeExpr(v ExprNode) {
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
	return nil
}

func (n *RestrictToActionNode) SetRestricteeList(v []ExprNode) {
}

func (n *RestrictToActionNode) AddRestrictee(v ExprNode) {
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
	return false
}

func (n *AddToRestricteeListActionNode) SetIsIfNotExists(v bool) {
}

func (n *AddToRestricteeListActionNode) RestricteeList() []ExprNode {
	return nil
}

func (n *AddToRestricteeListActionNode) SetRestricteeList(v []ExprNode) {
}

func (n *AddToRestricteeListActionNode) AddRestrictee(v ExprNode) {
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
	return false
}

func (n *RemoveFromRestricteeListActionNode) SetIsIfExists(v bool) {
}

func (n *RemoveFromRestricteeListActionNode) RestricteeList() []ExprNode {
	return nil
}

func (n *RemoveFromRestricteeListActionNode) SetRestricteeList(v []ExprNode) {
}

func (n *RemoveFromRestricteeListActionNode) AddRestrictee(v ExprNode) {
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
	return nil
}

func (n *FilterUsingActionNode) SetPredicate(v ExprNode) {
}

func (n *FilterUsingActionNode) PredicateStr() string {
	return ""
}

func (n *FilterUsingActionNode) SetPredicateStr(v string) {
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
	return nil
}

func (n *RevokeFromActionNode) SetRevokeeExprList(v []ExprNode) {
}

func (n *RevokeFromActionNode) AddRevokeeExpr(v ExprNode) {
}

func (n *RevokeFromActionNode) IsRevokeFromAll() bool {
	return false
}

func (n *RevokeFromActionNode) SetIsRevokeFromAll(v bool) {
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
	return nil
}

func (n *RenameToActionNode) SetNewPath(v []string) {
}

func (n *RenameToActionNode) AddNewPath(v string) {
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
	return nil
}

func (n *AlterPrivilegeRestrictionStmtNode) SetColumnPrivilegeList(v []*PrivilegeNode) {
}

func (n *AlterPrivilegeRestrictionStmtNode) AddColumnPrivilege(v *PrivilegeNode) {
}

func (n *AlterPrivilegeRestrictionStmtNode) ObjectType() string {
	return ""
}

func (n *AlterPrivilegeRestrictionStmtNode) SetObjectType(v string) {
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
	return ""
}

func (n *AlterRowAccessPolicyStmtNode) SetName(v string) {
}

func (n *AlterRowAccessPolicyStmtNode) TableScan() *TableScanNode {
	return nil
}

func (n *AlterRowAccessPolicyStmtNode) SetTableScan(v *TableScanNode) {
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
	return nil
}

func (n *AlterAllRowAccessPoliciesStmtNode) SetTableScan(v *TableScanNode) {
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
	return nil
}

func (n *CreateConstantStmtNode) SetExpr(v ExprNode) {
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
	return false
}

func (n *CreateFunctionStmtNode) SetHasExplicitReturnType(v bool) {
}

func (n *CreateFunctionStmtNode) ReturnType() types.Type {
	return nil
}

func (n *CreateFunctionStmtNode) SetReturnType(v types.Type) {
}

func (n *CreateFunctionStmtNode) ArgumentNameList() []string {
	return nil
}

func (n *CreateFunctionStmtNode) SetArgumentNameList(v []string) {
}

func (n *CreateFunctionStmtNode) AddArgumentName(v string) {
}

func (n *CreateFunctionStmtNode) Signature() *types.FunctionSignature {
	return nil
}

func (n *CreateFunctionStmtNode) SetSignature(v *types.FunctionSignature) {
}

func (n *CreateFunctionStmtNode) IsAggregate() bool {
	return false
}

func (n *CreateFunctionStmtNode) SetIsAggregate(v bool) {
}

func (n *CreateFunctionStmtNode) Language() string {
	return ""
}

func (n *CreateFunctionStmtNode) SetLanguage(v string) {
}

func (n *CreateFunctionStmtNode) Code() string {
	return ""
}

func (n *CreateFunctionStmtNode) SetCode(v string) {
}

func (n *CreateFunctionStmtNode) AggregateExpressionList() []*ComputedColumnNode {
	return nil
}

func (n *CreateFunctionStmtNode) SetAggregateExpressionList(v []*ComputedColumnNode) {
}

func (n *CreateFunctionStmtNode) AddAggregateExpression(v *ComputedColumnNode) {
}

func (n *CreateFunctionStmtNode) FunctionExpression() ExprNode {
	return nil
}

func (n *CreateFunctionStmtNode) SetFunctionExpression(v ExprNode) {
}

func (n *CreateFunctionStmtNode) OptionList() []*OptionNode {
	return nil
}

func (n *CreateFunctionStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *CreateFunctionStmtNode) AddOption(v *OptionNode) {
}

func (n *CreateFunctionStmtNode) SQLSecurity() SQLSecurity {
	return SQLSecurity(0)
}

func (n *CreateFunctionStmtNode) SetSQLSecurity(v SQLSecurity) {
}

func (n *CreateFunctionStmtNode) DeterminismLevel() DeterminismLevel {
	return DeterminismLevel(0)
}

func (n *CreateFunctionStmtNode) SetDeterminismLevel(v DeterminismLevel) {
}

func (n *CreateFunctionStmtNode) IsRemote() bool {
	return false
}

func (n *CreateFunctionStmtNode) SetIsRemote(v bool) {
}

func (n *CreateFunctionStmtNode) Connection() *ConnectionNode {
	return nil
}

func (n *CreateFunctionStmtNode) SetConnection(v *ConnectionNode) {
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
	return ""
}

func (n *ArgumentDefNode) SetName(v string) {
}

func (n *ArgumentDefNode) Type() types.Type {
	return nil
}

func (n *ArgumentDefNode) SetType(v types.Type) {
}

func (n *ArgumentDefNode) ArgumentKind() ArgumentKind {
	return ArgumentKind(0)
}

func (n *ArgumentDefNode) SetArgumentKind(v ArgumentKind) {
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
	return ""
}

func (n *ArgumentRefNode) SetName(v string) {
}

func (n *ArgumentRefNode) ArgumentKind() ArgumentKind {
	return ArgumentKind(0)
}

func (n *ArgumentRefNode) SetArgumentKind(v ArgumentKind) {
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

func (n *CreateTableFunctionStmtNode) ArgumentNameList() []string {
	return nil
}

func (n *CreateTableFunctionStmtNode) SetArgumentNameList(v []string) {
}

func (n *CreateTableFunctionStmtNode) AddArgumentName(v string) {
}

func (n *CreateTableFunctionStmtNode) Signature() *types.FunctionSignature {
	return nil
}

func (n *CreateTableFunctionStmtNode) SetSignature(v *types.FunctionSignature) {
}

func (n *CreateTableFunctionStmtNode) HasExplicitReturnSchema() bool {
	return false
}

func (n *CreateTableFunctionStmtNode) SetHasExplicitReturnSchema(v bool) {
}

func (n *CreateTableFunctionStmtNode) OptionList() []*OptionNode {
	return nil
}

func (n *CreateTableFunctionStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *CreateTableFunctionStmtNode) AddOption(v *OptionNode) {
}

func (n *CreateTableFunctionStmtNode) Language() string {
	return ""
}

func (n *CreateTableFunctionStmtNode) SetLanguage(v string) {
}

func (n *CreateTableFunctionStmtNode) Code() string {
	return ""
}

func (n *CreateTableFunctionStmtNode) SetCode(v string) {
}

func (n *CreateTableFunctionStmtNode) Query() ScanNode {
	return nil
}

func (n *CreateTableFunctionStmtNode) SetQuery(v ScanNode) {
}

func (n *CreateTableFunctionStmtNode) OutputColumnList() []*OutputColumnNode {
	return nil
}

func (n *CreateTableFunctionStmtNode) SetOutputColumnList(v []*OutputColumnNode) {
}

func (n *CreateTableFunctionStmtNode) AddOutputColumn(v *OutputColumnNode) {
}

func (n *CreateTableFunctionStmtNode) IsValueTable() bool {
	return false
}

func (n *CreateTableFunctionStmtNode) SetIsValueTable(v bool) {
}

func (n *CreateTableFunctionStmtNode) SQLSecurity() SQLSecurity {
	return SQLSecurity(0)
}

func (n *CreateTableFunctionStmtNode) SetSQLSecurity(v SQLSecurity) {
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
	return ""
}

func (n *RelationArgumentScanNode) SetName(v string) {
}

// IsValueTable if true, the result of this query is a value table. Rather than
// producing rows with named columns, it produces rows with a single
// unnamed value type.
func (n *RelationArgumentScanNode) IsValueTable() bool {
	return false
}

func (n *RelationArgumentScanNode) SetIsValueTable(v bool) {
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
	return nil
}

func (n *ArgumentListNode) SetArgList(v []*ArgumentDefNode) {
}

func (n *ArgumentListNode) AddArg(v *ArgumentDefNode) {
}

// FunctionSignatureHolderNode this wrapper is used for an optional FunctionSignature.
type FunctionSignatureHolderNode struct {
	*BaseArgumentNode
}

func (n *FunctionSignatureHolderNode) Signature() *types.FunctionSignature {
	return nil
}

func (n *FunctionSignatureHolderNode) SetSignature(v *types.FunctionSignature) {
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
	return false
}

func (n *DropFunctionStmtNode) SetIsIfExists(v bool) {
}

func (n *DropFunctionStmtNode) NamePath() []string {
	return nil
}

func (n *DropFunctionStmtNode) SetNamePath(v []string) {
}

func (n *DropFunctionStmtNode) AddName(v string) {
}

// Arguments
// NOTE: arguments for DROP FUNCTION statements are matched only on
// type; names for any arguments in ResolvedArgumentList will be set
// to the empty string irrespective of whether or not argument names
// were given in the DROP FUNCTION statement.
func (n *DropFunctionStmtNode) Arguments() *ArgumentListNode {
	return nil
}

func (n *DropFunctionStmtNode) SetArguments(v *ArgumentListNode) {
}

// Signature
// NOTE: arguments for DROP FUNCTION statements are matched only on
// type; names are irrelevant, so no argument names are saved to use
// with this signature.  Additionally, the return type will always be
// <void>, since return types are ignored for DROP FUNCTION.
func (n *DropFunctionStmtNode) Signature() *FunctionSignatureHolderNode {
	return nil
}

func (n *DropFunctionStmtNode) SetSignature(v *FunctionSignatureHolderNode) {
}

// DropTableFunctionStmtNode this statement: DROP TABLE FUNCTION [IF EXISTS] <name_path>;
//
// <is_if_exists> silently ignore the "name_path does not exist" error.
// <name_path> is the identifier path of the function to be dropped.
type DropTableFunctionStmtNode struct {
	*BaseStatementNode
}

func (n *DropTableFunctionStmtNode) IsIfExists() bool {
	return false
}

func (n *DropTableFunctionStmtNode) SetIsIfExists(v bool) {
}

func (n *DropTableFunctionStmtNode) NamePath() []string {
	return nil
}

func (n *DropTableFunctionStmtNode) SetNamePath(v []string) {
}

func (n *DropTableFunctionStmtNode) AddName(v string) {
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
	return nil
}

func (n *CallStmtNode) SetProcedure(v types.Procedure) {
}

func (n *CallStmtNode) Signature() *types.FunctionSignature {
	return nil
}

func (n *CallStmtNode) SetSignature(v *types.FunctionSignature) {
}

func (n *CallStmtNode) ArgumentList() []ExprNode {
	return nil
}

func (n *CallStmtNode) SetArgumentList(v []ExprNode) {
}

func (n *CallStmtNode) AddArgument(v ExprNode) {
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
	return ImportKind(0)
}

func (n *ImportStmtNode) SetImportKind(v ImportKind) {
}

func (n *ImportStmtNode) NamePath() []string {
	return nil
}

func (n *ImportStmtNode) SetNamePath(v []string) {
}

func (n *ImportStmtNode) AddName(v string) {
}

func (n *ImportStmtNode) FilePath() string {
	return ""
}

func (n *ImportStmtNode) SetFilePath(v string) {
}

func (n *ImportStmtNode) AliasPath() []string {
	return nil
}

func (n *ImportStmtNode) SetAliasPath(v []string) {
}

func (n *ImportStmtNode) AddAlias(v string) {
}

func (n *ImportStmtNode) IntoAliasPath() []string {
	return nil
}

func (n *ImportStmtNode) SetIntoAliasPath(v []string) {
}

func (n *ImportStmtNode) AddIntoAlias(v string) {
}

func (n *ImportStmtNode) OptionList() []*OptionNode {
	return nil
}

func (n *ImportStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *ImportStmtNode) AddOption(v *OptionNode) {
}

// ModuleStmtNode this statement: MODULE <name_path> [<option_list>];
//
// <name_path> is the identifier path of the module.
// <option_list> Engine-specific directives for the module statement.
type ModuleStmtNode struct {
	*BaseStatementNode
}

func (n *ModuleStmtNode) NamePath() []string {
	return nil
}

func (n *ModuleStmtNode) SetNamePath(v []string) {
}

func (n *ModuleStmtNode) AddName(v string) {
}

func (n *ModuleStmtNode) OptionList() []*OptionNode {
	return nil
}

func (n *ModuleStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *ModuleStmtNode) AddOption(v *OptionNode) {
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
	return HavingModifierKind(0)
}

func (n *AggregateHavingModifierNode) SetModifierKind(v HavingModifierKind) {
}

func (n *AggregateHavingModifierNode) HavingExpr() ExprNode {
	return nil
}

func (n *AggregateHavingModifierNode) SetHavingExpr(v ExprNode) {
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
	return nil
}

func (n *CreateMaterializedViewStmtNode) SetColumnDefinitionList(v []*ColumnDefinitionNode) {
}

func (n *CreateMaterializedViewStmtNode) AddColumnDefinition(v *ColumnDefinitionNode) {
}

func (n *CreateMaterializedViewStmtNode) PartitionByList() []ExprNode {
	return nil
}

func (n *CreateMaterializedViewStmtNode) SetPartitionByList(v []ExprNode) {
}

func (n *CreateMaterializedViewStmtNode) AddPartitionBy(v ExprNode) {
}

func (n *CreateMaterializedViewStmtNode) ClusterByList() []ExprNode {
	return nil
}

func (n *CreateMaterializedViewStmtNode) SetClusterByList(v []ExprNode) {
}

func (n *CreateMaterializedViewStmtNode) AddClusterBy(v ExprNode) {
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
	return nil
}

func (n *CreateProcedureStmtNode) SetArgumentNameList(v []string) {
}

func (n *CreateProcedureStmtNode) AddArgumentName(v string) {
}

func (n *CreateProcedureStmtNode) Signature() *types.FunctionSignature {
	return nil
}

func (n *CreateProcedureStmtNode) SetSignature(v *types.FunctionSignature) {
}

func (n *CreateProcedureStmtNode) OptionList() []*OptionNode {
	return nil
}

func (n *CreateProcedureStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *CreateProcedureStmtNode) AddOption(v *OptionNode) {
}

func (n *CreateProcedureStmtNode) ProcedureBody() string {
	return ""
}

func (n *CreateProcedureStmtNode) SetProcedureBody(v string) {
}

// ExecuteImmediateArgumentNode an argument for an EXECUTE IMMEDIATE's USING clause.
//
// <name> an optional name for this expression
// <expression> the expression's value
type ExecuteImmediateArgumentNode struct {
	*BaseArgumentNode
}

func (n *ExecuteImmediateArgumentNode) Name() string {
	return ""
}

func (n *ExecuteImmediateArgumentNode) SetName(v string) {
}

func (n *ExecuteImmediateArgumentNode) Expression() ExprNode {
	return nil
}

func (n *ExecuteImmediateArgumentNode) SetExpression(v ExprNode) {
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
	return ""
}

func (n *ExecuteImmediateStmtNode) SetSQL(v string) {
}

func (n *ExecuteImmediateStmtNode) IntoIdentifierList() []string {
	return nil
}

func (n *ExecuteImmediateStmtNode) SetIntoIdentifierList(v []string) {
}

func (n *ExecuteImmediateStmtNode) AddIntoIdentifier(v string) {
}

func (n *ExecuteImmediateStmtNode) UsingArgumentList() []*ExecuteImmediateArgumentNode {
	return nil
}

func (n *ExecuteImmediateStmtNode) SetUsingArgumentList(v []*ExecuteImmediateArgumentNode) {
}

func (n *ExecuteImmediateStmtNode) AddUsingArgument(v *ExecuteImmediateArgumentNode) {
}

// AssignmentStmtNode an assignment of a value to another value.
type AssignmentStmtNode struct {
	*BaseStatementNode
}

func (n *AssignmentStmtNode) Target() ExprNode {
	return nil
}

func (n *AssignmentStmtNode) SetTarget(v ExprNode) {
}

func (n *AssignmentStmtNode) Expr() ExprNode {
	return nil
}

func (n *AssignmentStmtNode) SetExpr(v ExprNode) {
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
	return ""
}

func (n *CreateEntityStmtNode) SetEntityType(v string) {
}

func (n *CreateEntityStmtNode) EntityBodyJSON() string {
	return ""
}

func (n *CreateEntityStmtNode) SetEntityBodyJSON(v string) {
}

func (n *CreateEntityStmtNode) EntityBodyText() string {
	return ""
}

func (n *CreateEntityStmtNode) SetEntityBodyText(v string) {
}

func (n *CreateEntityStmtNode) OptionList() []*OptionNode {
	return nil
}

func (n *CreateEntityStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *CreateEntityStmtNode) AddOption(v *OptionNode) {
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
	return ""
}

func (n *AlterEntityStmtNode) SetEntityType(v string) {
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
	return nil
}

func (n *PivotColumnNode) SetColumn(v *Column) {
}

// PivotExprIndex specifies the index of the pivot expression
// within the enclosing PivotScanNode's <pivot_expr_list> used to
// determine the result of the column.
func (n *PivotColumnNode) PivotExprIndex() int {
	return 0
}

func (n *PivotColumnNode) SetPivotExprIndex(v int) {
}

// PivotValueIndex specifies the index of the pivot value within
// the enclosing PivotScanNode's <pivot_value_list> used to
// determine the subset of input rows the pivot expression should be
// evaluated over.
func (n *PivotColumnNode) PivotValueIndex() int {
	return 0
}

func (n *PivotColumnNode) SetPivotValueIndex(v int) {
}

// PivotScanNode a scan produced by the following SQL fragment:
//   <input_scan> PIVOT(... FOR ... IN (...))
//
// The column list of this scan consists of a subset of columns from
// <group_by_column_list> and <pivot_column_list>.
type PivotScanNode struct {
	*BaseScanNode
}

// InputScan input to the PIVOT clause
func (n *PivotScanNode) InputScan() ScanNode {
	return nil
}

func (n *PivotScanNode) SetInputScan(v ScanNode) {
}

// GroupByList the columns from <input_scan> to group by.
// The output will have one row for each distinct combination of
// values for all grouping columns. (There will be one output row if
// this list is empty.)
//
// Each element is a ComputedColumnNode. The expression is always
// a ColumnRefNode that references a column from <input_scan>.
func (n *PivotScanNode) GroupByList() []*ComputedColumnNode {
	return nil
}

func (n *PivotScanNode) SetGroupByList(v []*ComputedColumnNode) {
}

func (n *PivotScanNode) AddGroupBy(v *ComputedColumnNode) {
}

// PivotExprList pivot expressions which aggregate over the subset of <input_scan>
// where <for_expr> matches each value in <pivot_value_list>, plus
// all columns in <group_by_list>.
func (n *PivotScanNode) PivotExprList() []ExprNode {
	return nil
}

func (n *PivotScanNode) SetPivotExprList(v []ExprNode) {
}

func (n *PivotScanNode) AddPivotExpr(v ExprNode) {
}

// ForExpr expression following the FOR keyword, to be evaluated over each row
// in <input_scan>. This value is compared with each value in
// <pivot_value_list> to determine which columns the aggregation
// results of <pivot_expr_list> should go to.
func (n *PivotScanNode) ForExpr() ExprNode {
	return nil
}

func (n *PivotScanNode) SetForExpr(v ExprNode) {
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
	return nil
}

func (n *PivotScanNode) SetPivotValueList(v []ExprNode) {
}

func (n *PivotScanNode) AddPivotValue(v ExprNode) {
}

// PivotColumnList list of columns created to store the output pivot columns.
// Each is computed using one of pivot_expr_list and one of
// pivot_value_list.
func (n *PivotScanNode) PivotColumnList() []*PivotColumnNode {
	return nil
}

func (n *PivotScanNode) SetPivotColumnList(v []*PivotColumnNode) {
}

func (n *PivotScanNode) AddPivotColumn(v *PivotColumnNode) {
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
	return nil
}

func (n *ReturningClauseNode) SetOutputColumnList(v []*OutputColumnNode) {
}

func (n *ReturningClauseNode) AddOutputColumn(v *OutputColumnNode) {
}

// ActionColumn represents the WITH ACTION column in <output_column_list> as a
// string type column. There are four valid values for this action
// column: "INSERT", "REPLACE", "UPDATE", and "DELETE".
func (n *ReturningClauseNode) ActionColumn() *ColumnHolderNode {
	return nil
}

func (n *ReturningClauseNode) SetActionColumn(v *ColumnHolderNode) {
}

// ExprList represents the computed expressions so they can be referenced in
// <output_column_list>. Worth noting, it can't see <action_column>
// and can only access columns from the DML statement target table.
func (n *ReturningClauseNode) ExprList() []*ComputedColumnNode {
	return nil
}

func (n *ReturningClauseNode) SetExprList(v []*ComputedColumnNode) {
}

func (n *ReturningClauseNode) AddExpr(v *ComputedColumnNode) {
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
	return nil
}

func (n *UnpivotArgNode) SetColumnList(v []*ColumnRefNode) {
}

func (n *UnpivotArgNode) AddColumn(v *ColumnRefNode) {
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
	return nil
}

func (n *UnpivotScanNode) SetInputScan(v ScanNode) {
}

// ValueColumnList list of one or more new columns added by UNPIVOT.
// These new column(s) store the value of input columns that are in
// the UNPIVOT IN clause.
func (n *UnpivotScanNode) ValueColumnList() []*Column {
	return nil
}

func (n *UnpivotScanNode) SetValueColumnList(v []*Column) {
}

func (n *UnpivotScanNode) AddValueColumn(v *Column) {
}

// LabelColumn this is a new column added in the output for storing labels for
// input columns groups that are present in the IN clause. Its
// values are taken from <label_list>.
func (n *UnpivotScanNode) LabelColumn() *Column {
	return nil
}

func (n *UnpivotScanNode) SetLabelColumn(v *Column) {
}

// LabelList string or integer literal for each column group in
// <unpivot_arg_list>.
func (n *UnpivotScanNode) LabelList() []*LiteralNode {
	return nil
}

func (n *UnpivotScanNode) SetLabelList(v []*LiteralNode) {
}

func (n *UnpivotScanNode) AddLabel(v *LiteralNode) {
}

// UnpivotArgList the list of groups of columns in the UNPIVOT IN list. Each group
// contains references to the output columns of <input_scan> of the
// UnpivotScanNode. The values of these columns are stored in the
// new <value_column_list> and the column group labels/names
// in the <label_column>.
func (n *UnpivotScanNode) UnpivotArgList() []*UnpivotArgNode {
	return nil
}

func (n *UnpivotScanNode) SetUnpivotArgList(v []*UnpivotArgNode) {
}

func (n *UnpivotScanNode) AddUnpivotArg(v *UnpivotArgNode) {
}

// ProjectedInputColumnList the columns from <input_scan> that are not unpivoted in UNPIVOT
// IN clause. Columns in <projected_input_column_list> and
// <unpivot_arg_list> are mutually exclusive and their union is the
// complete set of columns in the unpivot input-source.
//
// The expression of each ComputedColumnNode is a
// ColumnRefNode that references a column from <input_scan>.
func (n *UnpivotScanNode) ProjectedInputColumnList() []*ComputedColumnNode {
	return nil
}

func (n *UnpivotScanNode) SetProjectedInputColumnList(v []*ComputedColumnNode) {
}

func (n *UnpivotScanNode) AddProjectedInputColumn(v *ComputedColumnNode) {
}

// IncludeNulls whether we need to include the rows from output where ALL columns
// from <value_column_list> are null.
func (n *UnpivotScanNode) IncludeNulls() bool {
	return false
}

func (n *UnpivotScanNode) SetIncludeNulls(v bool) {
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
	return nil
}

func (n *CloneDataStmtNode) SetTargetTable(v *TableScanNode) {
}

func (n *CloneDataStmtNode) CloneFrom() ScanNode {
	return nil
}

func (n *CloneDataStmtNode) SetCloneFrom(v ScanNode) {
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
	return nil
}

func (n *TableAndColumnInfoNode) SetTable(v types.Table) {
}

func (n *TableAndColumnInfoNode) ColumnIndexList() []int {
	return nil
}

func (n *TableAndColumnInfoNode) SetColumnIndexList(v []int) {
}

func (n *TableAndColumnInfoNode) AddColumnIndex(v int) {
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
	return nil
}

func (n *AnalyzeStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *AnalyzeStmtNode) AddOption(v *OptionNode) {
}

func (n *AnalyzeStmtNode) TableAndColumnIndexList() []*TableAndColumnInfoNode {
	return nil
}

func (n *AnalyzeStmtNode) SetTableAndColumnIndexList(v []*TableAndColumnInfoNode) {
}

func (n *AnalyzeStmtNode) AddTableAndColumnIndex(v *TableAndColumnInfoNode) {
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
	return InsertionMode(0)
}

func (n *AuxLoadDataStmtNode) SetInsertionMode(v InsertionMode) {
}

func (n *AuxLoadDataStmtNode) NamePath() []string {
	return nil
}

func (n *AuxLoadDataStmtNode) SetNamePath(v []string) {
}

func (n *AuxLoadDataStmtNode) AddName(v string) {
}

func (n *AuxLoadDataStmtNode) OutputColumnList() []*OutputColumnNode {
	return nil
}

func (n *AuxLoadDataStmtNode) SetOutputColumnList(v []*OutputColumnNode) {
}

func (n *AuxLoadDataStmtNode) AddOutputColumn(v *OutputColumnNode) {
}

func (n *AuxLoadDataStmtNode) ColumnDefinitionList() []*ColumnDefinitionNode {
	return nil
}

func (n *AuxLoadDataStmtNode) SetColumnDefinitionList(v []*ColumnDefinitionNode) {
}

func (n *AuxLoadDataStmtNode) AddColumnDefinition(v *ColumnDefinitionNode) {
}

func (n *AuxLoadDataStmtNode) PseudoColumnList() []*Column {
	return nil
}

func (n *AuxLoadDataStmtNode) SetPseudoColumnList(v []*Column) {
}

func (n *AuxLoadDataStmtNode) AddPseudoColumn(v *Column) {
}

func (n *AuxLoadDataStmtNode) PrimaryKey() *PrimaryKeyNode {
	return nil
}

func (n *AuxLoadDataStmtNode) SetPrimaryKey(v *PrimaryKeyNode) {
}

func (n *AuxLoadDataStmtNode) ForeignKeyList() []*ForeignKeyNode {
	return nil
}

func (n *AuxLoadDataStmtNode) SetForeignKeyList(v []*ForeignKeyNode) {
}

func (n *AuxLoadDataStmtNode) AddForeignKey(v *ForeignKeyNode) {
}

func (n *AuxLoadDataStmtNode) CheckConstraintList() []*CheckConstraintNode {
	return nil
}

func (n *AuxLoadDataStmtNode) SetCheckConstraintList(v []*CheckConstraintNode) {
}

func (n *AuxLoadDataStmtNode) AddCheckConstraint(v *CheckConstraintNode) {
}

func (n *AuxLoadDataStmtNode) PartitionByList() []ExprNode {
	return nil
}

func (n *AuxLoadDataStmtNode) SetPartitionByList(v []ExprNode) {
}

func (n *AuxLoadDataStmtNode) AddPartitionBy(v ExprNode) {
}

func (n *AuxLoadDataStmtNode) ClusterByList() []ExprNode {
	return nil
}

func (n *AuxLoadDataStmtNode) SetClusterByList(v []ExprNode) {
}

func (n *AuxLoadDataStmtNode) AddClusterBy(v ExprNode) {
}

func (n *AuxLoadDataStmtNode) OptionList() []*OptionNode {
	return nil
}

func (n *AuxLoadDataStmtNode) SetOptionList(v []*OptionNode) {
}

func (n *AuxLoadDataStmtNode) AddOption(v *OptionNode) {
}

func (n *AuxLoadDataStmtNode) WithPartitionColumns() *WithPartitionColumnsNode {
	return nil
}

func (n *AuxLoadDataStmtNode) SetWithPartitionColumns(v *WithPartitionColumnsNode) {
}

func (n *AuxLoadDataStmtNode) Connection() *ConnectionNode {
	return nil
}

func (n *AuxLoadDataStmtNode) SetConnection(v *ConnectionNode) {
}

func (n *AuxLoadDataStmtNode) FromFilesOptionList() []*OptionNode {
	return nil
}

func (n *AuxLoadDataStmtNode) SetFromFilesOptionList(v []*OptionNode) {
}

func (n *AuxLoadDataStmtNode) AddFromFilesOption(v *OptionNode) {
}

type TVFArgumentNode = FunctionArgumentNode

func newNode(v unsafe.Pointer) Node {
	if v == nil {
		return nil
	}
	var kind int
	internal.Node_node_kind(v, &kind)
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
