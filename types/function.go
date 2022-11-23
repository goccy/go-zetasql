package types

import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
)

// FunctionArgumentTypeOptions specifies options on a function argument, including
// argument cardinality.  This includes some options that are used to specify
// argument values that are illegal and should cause an analysis error.
type FunctionArgumentTypeOptions struct {
	raw unsafe.Pointer
}

func (o *FunctionArgumentTypeOptions) getRaw() unsafe.Pointer {
	if o == nil {
		return nil
	}
	return o.raw
}

func (o *FunctionArgumentTypeOptions) Cardinality() ArgumentCardinality {
	var v int
	internal.FunctionArgumentTypeOptions_cardinality(o.raw, &v)
	return ArgumentCardinality(v)
}

func (o *FunctionArgumentTypeOptions) MustBeConstant() bool {
	var v bool
	internal.FunctionArgumentTypeOptions_must_be_constant(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) MustBeNonNull() bool {
	var v bool
	internal.FunctionArgumentTypeOptions_must_be_non_null(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) IsNotAggregate() bool {
	var v bool
	internal.FunctionArgumentTypeOptions_is_not_aggregate(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) MustSupportEquality() bool {
	var v bool
	internal.FunctionArgumentTypeOptions_must_support_equality(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) MustSupportOrdering() bool {
	var v bool
	internal.FunctionArgumentTypeOptions_must_support_ordering(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) MustSupportGrouping() bool {
	var v bool
	internal.FunctionArgumentTypeOptions_must_support_grouping(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) HasMinValue() bool {
	var v bool
	internal.FunctionArgumentTypeOptions_has_min_value(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) HasMaxValue() bool {
	var v bool
	internal.FunctionArgumentTypeOptions_has_max_value(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) MinValue() int64 {
	var v int64
	internal.FunctionArgumentTypeOptions_min_value(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) MaxValue() int64 {
	var v int64
	internal.FunctionArgumentTypeOptions_max_value(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) HasRelationInputSchema() bool {
	var v bool
	internal.FunctionArgumentTypeOptions_has_relation_input_schema(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) ResolveDescriptorNamesTableOffset() int {
	var v int
	internal.FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) ExtraRelationInputColumnsAllowed() bool {
	var v bool
	internal.FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) HasArgumentName() bool {
	var v bool
	internal.FunctionArgumentTypeOptions_has_argument_name(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) ArgumentName() string {
	var v unsafe.Pointer
	internal.FunctionArgumentTypeOptions_argument_name(o.raw, &v)
	return helper.PtrToString(v)
}

func (o *FunctionArgumentTypeOptions) ArgumentNameIsMandatory() bool {
	var v bool
	internal.FunctionArgumentTypeOptions_argument_name_is_mandatory(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) ProcedureArgumentMode() ProcedureArgumentMode {
	var v int
	internal.FunctionArgumentTypeOptions_procedure_argument_mode(o.raw, &v)
	return ProcedureArgumentMode(v)
}

func (o *FunctionArgumentTypeOptions) SetCardinality(c ArgumentCardinality) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_cardinality(o.raw, int(c))
	return o
}

func (o *FunctionArgumentTypeOptions) SetMustBeConstant(v bool) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_must_be_constant(o.raw, helper.BoolToInt(v))
	return o
}

func (o *FunctionArgumentTypeOptions) SetMustBeNonNull(v bool) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_must_be_non_null(o.raw, helper.BoolToInt(v))
	return o
}

func (o *FunctionArgumentTypeOptions) SetIsNotAggregate(v bool) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_is_not_aggregate(o.raw, helper.BoolToInt(v))
	return o
}

func (o *FunctionArgumentTypeOptions) SetMustSupportEquality(v bool) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_must_support_equality(o.raw, helper.BoolToInt(v))
	return o
}

func (o *FunctionArgumentTypeOptions) SetMustSupportOrdering(v bool) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_must_support_ordering(o.raw, helper.BoolToInt(v))
	return o
}

func (o *FunctionArgumentTypeOptions) SetMustSupportGrouping(v bool) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_must_support_grouping(o.raw, helper.BoolToInt(v))
	return o
}

func (o *FunctionArgumentTypeOptions) SetMinValue(v int64) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_min_value(o.raw, v)
	return o
}

func (o *FunctionArgumentTypeOptions) SetMaxValue(v int64) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_max_value(o.raw, v)
	return o
}

func (o *FunctionArgumentTypeOptions) SetExtraRelationInputColumnsAllowed(v bool) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(o.raw, helper.BoolToInt(v))
	return o
}

func (o *FunctionArgumentTypeOptions) SetArgumentName(name string) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_argument_name(o.raw, helper.StringToPtr(name))
	return o
}

func (o *FunctionArgumentTypeOptions) SetArgumentNameIsMandatory(value bool) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_argument_name_is_mandatory(o.raw, helper.BoolToInt(value))
	return o
}

func (o *FunctionArgumentTypeOptions) SetProcedureArgumentMode(mode ProcedureArgumentMode) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_procedure_argument_mode(o.raw, int(mode))
	return o
}

func (o *FunctionArgumentTypeOptions) SetResolveDescriptorNamesTableOffset(tableOffset int) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(o.raw, tableOffset)
	return o
}

// OptionsDebugString return a string describing the options (not including cardinality).
// If no options are set, this returns an empty string.
// Otherwise, includes a leading space.
func (o *FunctionArgumentTypeOptions) OptionsDebugString() string {
	var v unsafe.Pointer
	internal.FunctionArgumentTypeOptions_OptionsDebugString(o.raw, &v)
	return helper.PtrToString(v)
}

// SQLDeclaration get the SQL declaration for these options.
// The result is formatted as SQL that can be included inside a function
// signature in CREATE FUNCTION, DROP FUNCTION, etc, if possible.
func (o *FunctionArgumentTypeOptions) SQLDeclaration(mode ProductMode) string {
	var v unsafe.Pointer
	internal.FunctionArgumentTypeOptions_GetSQLDeclaration(o.raw, int(mode), &v)
	return helper.PtrToString(v)
}

// SetArgumentNameParseLocation sets the ParseLocationRange of the argument name.
func (o *FunctionArgumentTypeOptions) SetArgumentNameParseLocation(locRange *ParseLocationRange) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_argument_name_parse_location(o.raw, locRange.raw)
	return o
}

// ArgumentNameParseLocation gets the ParseLocationRange of the argument name.
func (o *FunctionArgumentTypeOptions) ArgumentNameParseLocation() *ParseLocationRange {
	var v unsafe.Pointer
	internal.FunctionArgumentTypeOptions_argument_name_parse_location(o.raw, &v)
	return newParseLocationRange(v)
}

// SetArgumentTypeParseLocation sets the ParseLocationRange of the argument type.
func (o *FunctionArgumentTypeOptions) SetArgumentTypeParseLocation(locRange *ParseLocationRange) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_argument_type_parse_location(o.raw, locRange.raw)
	return o
}

// ArgumentTypeParseLocation gets the ParseLocationRange of the argument type.
func (o *FunctionArgumentTypeOptions) ArgumentTypeParseLocation() *ParseLocationRange {
	var v unsafe.Pointer
	internal.FunctionArgumentTypeOptions_argument_type_parse_location(o.raw, &v)
	return newParseLocationRange(v)
}

// SetDefault sets the default value of this argument. Only optional arguments can
// (optionally) have default values.
// Restrictions on the default values:
// - For fixed-typed arguments, the type of <default_value> must be Equals to
//   the type of the argument.
// - Non-expression-typed templated arguments (e.g., tables, connections,
//   models, etc.) cannot have default values.
//
// Note that (in the near future), an optional argument that has a default
// value and is omitted in a function call will be resolved as if the default
// value is specified.
//
// Also note that the type of <default_value> must outlive this object as well
// as all the FunctionSignature instances created using this object.
func (o *FunctionArgumentTypeOptions) SetDefault(value Value) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_default(o.raw, value.getRaw())
	return o
}

// HasDefault returns true if a default value has been defined for this argument.
func (o *FunctionArgumentTypeOptions) HasDefault() bool {
	var v bool
	internal.FunctionArgumentTypeOptions_has_default(o.raw, &v)
	return v
}

// Default gets the default value of this argument.
func (o *FunctionArgumentTypeOptions) Default() Value {
	var v unsafe.Pointer
	internal.FunctionArgumentTypeOptions_get_default(o.raw, &v)
	return newValue(v)
}

// ClearDefault clears the default argument value set to this object.
func (o *FunctionArgumentTypeOptions) ClearDefault() *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_clear_default(o.raw)
	return o
}

func (o *FunctionArgumentTypeOptions) ArgumentCollationMode() ArgumentCollationMode {
	var v int
	internal.FunctionArgumentTypeOptions_argument_collation_mode(o.raw, &v)
	return ArgumentCollationMode(v)
}

func (o *FunctionArgumentTypeOptions) UsesArrayElementForCollation() bool {
	var v bool
	internal.FunctionArgumentTypeOptions_uses_array_element_for_collation(o.raw, &v)
	return v
}

func (o *FunctionArgumentTypeOptions) SetUsesArrayElementForCollation(v bool) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_uses_array_element_for_collation(o.raw, helper.BoolToInt(v))
	return o
}

func (o *FunctionArgumentTypeOptions) SetArgumentCollationMode(mode ArgumentCollationMode) *FunctionArgumentTypeOptions {
	internal.FunctionArgumentTypeOptions_set_argument_collation_mode(o.raw, int(mode))
	return o
}

// FunctionArgumentType a type for an argument or result value in a function signature.
// Types can be fixed or templated.  Arguments can be marked as repeated (denoting
// it can occur zero or more times in a function invocation) or optional.
// Result types cannot be marked as repeated or optional.
// Type VOID is valid for the return type in Procedures and in
// DropFunctionStmtNode only; VOID is not allowed as the return type for
// Functions, and is never allowed as a argument type.
// A FunctionArgumentType is concrete if it is not templated and
// num_occurrences_ indicates how many times the argument appears in a
// concrete FunctionSignature.  FunctionArgumentTypeOptions can be used to
// apply additional constraints on legal values for the argument.
type FunctionArgumentType struct {
	raw unsafe.Pointer
}

func (t *FunctionArgumentType) Options() *FunctionArgumentTypeOptions {
	var v unsafe.Pointer
	internal.FunctionArgumentType_options(t.raw, &v)
	return newFunctionArgumentTypeOptions(v)
}

func (t *FunctionArgumentType) Required() bool {
	var v bool
	internal.FunctionArgumentType_required(t.raw, &v)
	return v
}

func (t *FunctionArgumentType) Repeated() bool {
	var v bool
	internal.FunctionArgumentType_repeated(t.raw, &v)
	return v
}

func (t *FunctionArgumentType) Optional() bool {
	var v bool
	internal.FunctionArgumentType_optional(t.raw, &v)
	return v
}

func (t *FunctionArgumentType) Cardinality() ArgumentCardinality {
	var v int
	internal.FunctionArgumentType_cardinality(t.raw, &v)
	return ArgumentCardinality(v)
}

func (t *FunctionArgumentType) MustBeConstant() bool {
	var v bool
	internal.FunctionArgumentType_must_be_constant(t.raw, &v)
	return v
}

func (t *FunctionArgumentType) HasArgumentName() bool {
	var v bool
	internal.FunctionArgumentType_has_argument_name(t.raw, &v)
	return v
}

func (t *FunctionArgumentType) ArgumentName() string {
	var v unsafe.Pointer
	internal.FunctionArgumentType_argument_name(t.raw, &v)
	return helper.PtrToString(v)
}

func (t *FunctionArgumentType) NumOccurrences() int {
	var v int
	internal.FunctionArgumentType_num_occurrences(t.raw, &v)
	return v
}

func (t *FunctionArgumentType) SetNumOccurrences(num int) {
	internal.FunctionArgumentType_set_num_occurrences(t.raw, num)
}

func (t *FunctionArgumentType) IncrementNumOccurrences() {
	internal.FunctionArgumentType_IncrementNumOccurrences(t.raw)
}

// Type returns nil if kind is not ARG_TYPE_FIXED or ARG_TYPE_LAMBDA.
// If kind is ARG_TYPE_LAMBDA, returns the type of lambda body type, which could be nil
// if the body type is templated.
func (t *FunctionArgumentType) Type() Type {
	var v unsafe.Pointer
	internal.FunctionArgumentType_type(t.raw, &v)
	return newType(v)
}

func (t *FunctionArgumentType) Kind() SignatureArgumentKind {
	var v int
	internal.FunctionArgumentType_kind(t.raw, &v)
	return SignatureArgumentKind(v)
}

// Lambda returns information about a lambda typed function argument.
func (t *FunctionArgumentType) Lambda() *ArgumentTypeLambda {
	var v unsafe.Pointer
	internal.FunctionArgumentType_labmda(t.raw, &v)
	return newArgumentTypeLambda(v)
}

// IsConcrete returns true if kind is ARG_TYPE_FIXED or ARG_TYPE_RELATION and the number
// of occurrences is greater than -1.
func (t *FunctionArgumentType) IsConcrete() bool {
	var v bool
	internal.FunctionArgumentType_IsConcrete(t.raw, &v)
	return v
}

func (t *FunctionArgumentType) IsTemplated() bool {
	var v bool
	internal.FunctionArgumentType_IsTemplated(t.raw, &v)
	return v
}

func (t *FunctionArgumentType) IsScalar() bool {
	var v bool
	internal.FunctionArgumentType_IsScalar(t.raw, &v)
	return v
}

func (t *FunctionArgumentType) IsRelation() bool {
	var v bool
	internal.FunctionArgumentType_IsRelation(t.raw, &v)
	return v
}

func (t *FunctionArgumentType) IsModel() bool {
	var v bool
	internal.FunctionArgumentType_IsModel(t.raw, &v)
	return v
}

func (t *FunctionArgumentType) IsConnection() bool {
	var v bool
	internal.FunctionArgumentType_IsConnection(t.raw, &v)
	return v
}

func (t *FunctionArgumentType) IsLambda() bool {
	var v bool
	internal.FunctionArgumentType_IsLambda(t.raw, &v)
	return v
}

func (t *FunctionArgumentType) IsFixedRelation() bool {
	var v bool
	internal.FunctionArgumentType_IsFixedRelation(t.raw, &v)
	return v
}

func (t *FunctionArgumentType) IsVoid() bool {
	var v bool
	internal.FunctionArgumentType_IsVoid(t.raw, &v)
	return v
}

func (t *FunctionArgumentType) IsDescriptor() bool {
	var v bool
	internal.FunctionArgumentType_IsDescriptor(t.raw, &v)
	return v
}

// TemplatedKindIsRelated returns TRUE if kind() can be used to derive something about kind.
// For example, if kind() is ARG_ARRAY_TYPE_ANY_1, it can be used to derive
// information about ARG_TYPE_ANY_1, but not ARG_TYPE_ANY_2. Likewise, a
// proto map key can be used to derive information about the map itself, but
// not about the map value.
func (t *FunctionArgumentType) TemplatedKindIsRelated(kind SignatureArgumentKind) bool {
	var v bool
	internal.FunctionArgumentType_TemplatedKindIsRelated(t.raw, int(kind), &v)
	return v
}

func (t *FunctionArgumentType) AllowCoercionFrom(actualArgType Type) bool {
	var v bool
	internal.FunctionArgumentType_AllowCoercionFrom(t.raw, actualArgType.getRaw(), &v)
	return v
}

// HasDefault returns TRUE if the argument has a default value provided in the argument option.
func (t *FunctionArgumentType) HasDefault() bool {
	var v bool
	internal.FunctionArgumentType_HasDefault(t.raw, &v)
	return v
}

// Default returns default value provided in the argument option, or nil if
// the argument does not have a default value.
func (t *FunctionArgumentType) Default() Value {
	var v unsafe.Pointer
	internal.FunctionArgumentType_GetDefault(t.raw, &v)
	return newValue(v)
}

// UserFacingName returns argument type name to be used in error messages.
// This either would be a scalar short type name - DATE, INT64, BYTES etc. or
// STRUCT, PROTO, ENUM for complex type names, or ANY when any data type is allowed.
func (t *FunctionArgumentType) UserFacingName(mode ProductMode) string {
	var v unsafe.Pointer
	internal.FunctionArgumentType_UserFacingName(t.raw, int(mode), &v)
	return helper.PtrToString(v)
}

// UserFacingNameWithCardinality returns user facing text for the argument including argument cardinality
// (to be used in error message):
//   - required, just argument type, e.g. INT64
//   - optional, argument type enclosed in [], e.g. [INT64]
//   - repeated, argument type enclosed in [] with ..., e.g. [INT64, ...]
func (t *FunctionArgumentType) UserFacingNameWithCardinality(mode ProductMode) string {
	var v unsafe.Pointer
	internal.FunctionArgumentType_UserFacingNameWithCardinality(t.raw, int(mode), &v)
	return helper.PtrToString(v)
}

// IsValid checks concrete arguments to validate the number of occurrences.
func (t *FunctionArgumentType) IsValid(mode ProductMode) error {
	var v unsafe.Pointer
	internal.FunctionArgumentType_IsValid(t.raw, int(mode), &v)
	status := helper.NewStatus(v)
	if !status.OK() {
		return status.Error()
	}
	return nil
}

// DebugString if verbose is true, include FunctionOptions modifiers.
func (t *FunctionArgumentType) DebugString(verbose bool) string {
	var v unsafe.Pointer
	internal.FunctionArgumentType_DebugString(t.raw, helper.BoolToInt(verbose), &v)
	return helper.PtrToString(v)
}

// SQLDeclaration get the SQL declaration for this argument, including all options.
// The result is formatted as SQL that can be included inside a function
// signature in CREATE FUNCTION, DROP FUNCTION, etc, if possible.
func (t *FunctionArgumentType) SQLDeclaration(mode ProductMode) string {
	var v unsafe.Pointer
	internal.FunctionArgumentType_GetSQLDeclaration(t.raw, int(mode), &v)
	return helper.PtrToString(v)
}

// ArgumentTypeLambda contains type information for ARG_TYPE_LAMBDA, which represents the lambda
// type of a function argument. A lambda has a list of arguments and a body.
// Both the lambda arguments and body could be templated or nontemplated.
// Putting them together to minimize stack usage of FunctionArgumentType.
type ArgumentTypeLambda struct {
	raw unsafe.Pointer
}

func (t *ArgumentTypeLambda) ArgumentTypes() []*FunctionArgumentType {
	var v unsafe.Pointer
	internal.ArgumentTypeLambda_argument_types(t.raw, &v)
	var ret []*FunctionArgumentType
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newFunctionArgumentType(p))
	})
	return ret
}

func (t *ArgumentTypeLambda) BodyType() *FunctionArgumentType {
	var v unsafe.Pointer
	internal.ArgumentTypeLambda_body_type(t.raw, &v)
	return newFunctionArgumentType(v)
}

// FunctionSignature identifies the argument Types and other properties
// per overload of a Function (or a similar object, like a Procedure or
// TableValuedFunction).  A FunctionSignature is concrete if it
// identifies the exact number and fixed Types of its arguments and results.
// A FunctionSignature can be non-concrete, but have concrete arguments.
// A FunctionSignature can be abstract, specifying templated types and
// identifying arguments as repeated or optional.  Optional arguments must
// appear at the end of the argument list.
//
// If multiple arguments are repeated, they must be consecutive and are
// treated as if they repeat together.  To illustrate, consider the expression:
// 'CASE WHEN <bool_expr_1> THEN <expr_1>
//       WHEN <bool_expr_2> THEN <expr_2>
//       ...
//       ELSE <expr_n> END'.
//
// This expression has the following signature <arguments>:
//   arg1: <bool> repeated - WHEN
//   arg2: <any_type_1> repeated - THEN
//   arg3: <any_type_1> optional - ELSE
//   result: <any_type_1>
//
// The WHEN and THEN arguments (arg1 and arg2) repeat together and must
// occur at least once, and the ELSE is optional.  The THEN, ELSE, and
// RESULT types can be any type, but must be the same type.
//
// In order to avoid potential ambiguity, the number of optional arguments
// must be less than the number of repeated arguments.
//
// The FunctionSignature also includes <options> for specifying
// additional signature matching requirements, if any.
type FunctionSignature struct {
	raw unsafe.Pointer
}

func (s *FunctionSignature) Arguments() []*FunctionArgumentType {
	var v unsafe.Pointer
	internal.FunctionSignature_arguments(s.raw, &v)
	var ret []*FunctionArgumentType
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newFunctionArgumentType(p))
	})
	return ret
}

// ConcreteArguments returns concrete argument.
// Differs from argments above in that repeated and optional arguments
// are fully expanded in a concrete signature.
// Requires that the signature has concrete arguments.
func (s *FunctionSignature) ConcreteArguments() []*FunctionArgumentType {
	var v unsafe.Pointer
	internal.FunctionSignature_concret_arguments(s.raw, &v)
	var ret []*FunctionArgumentType
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newFunctionArgumentType(p))
	})
	return ret
}

func (s *FunctionSignature) ResultType() *FunctionArgumentType {
	var v unsafe.Pointer
	internal.FunctionSignature_result_type(s.raw, &v)
	return newFunctionArgumentType(v)
}

func (s *FunctionSignature) IsConcrete() bool {
	var v bool
	internal.FunctionSignature_IsConcrete(s.raw, &v)
	return v
}

// HasConcreteArguments returns TRUE if all arguments are concrete.
func (s *FunctionSignature) HasConcreteArguments() bool {
	var v bool
	internal.FunctionSignature_HasConcreteArguments(s.raw, &v)
	return v
}

// IsValid determines whether the argument and result types are valid.
// Additionally, it requires that all repeated arguments are consecutive, and all optional
// arguments appear at the end.  There may be required arguments before
// the repeated arguments, and there may be required arguments between the
// repeated and optional arguments.
func (s *FunctionSignature) IsValid(mode ProductMode) error {
	var v unsafe.Pointer
	internal.FunctionSignature_IsValid(s.raw, int(mode), &v)
	status := helper.NewStatus(v)
	if !status.OK() {
		return status.Error()
	}
	return nil
}

// IsValidForFunction checks specific invariants for the argument and return types for regular function calls.
// The latter may use relation types (returning true for (*FunctionArgumentType).IsRelation()) but the former may not.
func (s *FunctionSignature) IsValidForFunction() error {
	var v unsafe.Pointer
	internal.FunctionSignature_IsValidForFunction(s.raw, &v)
	status := helper.NewStatus(v)
	if !status.OK() {
		return status.Error()
	}
	return nil
}

// IsValidForTableValuedFunction checks specific invariants for the argument and return types for table-valued function calls.
// The latter may use relation types (returning true for (*FunctionArgumentType).IsRelation()) but the former may not.
func (s *FunctionSignature) IsValidForTableValuedFunction() error {
	var v unsafe.Pointer
	internal.FunctionSignature_IsValidForTableValuedFunction(s.raw, &v)
	status := helper.NewStatus(v)
	if !status.OK() {
		return status.Error()
	}
	return nil
}

// IsValidForProcedure checks if this signature is valid for Procedure.
// Procedure may only have fixed required arguments.
func (s *FunctionSignature) IsValidForProcedure() error {
	var v unsafe.Pointer
	internal.FunctionSignature_IsValidForProcedure(s.raw, &v)
	status := helper.NewStatus(v)
	if !status.OK() {
		return status.Error()
	}
	return nil
}

// FirstRepeatedArgumentIndex gets the first repeated argument index.
// If there are no repeated arguments then returns -1.
func (s *FunctionSignature) FirstRepeatedArgumentIndex() int {
	var v int
	internal.FunctionSignature_FirstRepeatedArgumentIndex(s.raw, &v)
	return v
}

// LastRepeatedArgumentIndex gets the first repeated argument index.
// If there are no repeated arguments then returns -1.
func (s *FunctionSignature) LastRepeatedArgumentIndex() int {
	var v int
	internal.FunctionSignature_LastRepeatedArgumentIndex(s.raw, &v)
	return v
}

// NumRequiredArguments gets the number of required arguments.
func (s *FunctionSignature) NumRequiredArguments() int {
	var v int
	internal.FunctionSignature_NumRequiredArguments(s.raw, &v)
	return v
}

// NumRepeatedArguments gets the number of repeated arguments.
func (s *FunctionSignature) NumRepeatedArguments() int {
	var v int
	internal.FunctionSignature_NumRepeatedArguments(s.raw, &v)
	return v
}

// NumOptionalArguments gets the number of optional arguments.
func (s *FunctionSignature) NumOptionalArguments() int {
	var v int
	internal.FunctionSignature_NumOptionalArguments(s.raw, &v)
	return v
}

// DebugString if verbose is true, include FunctionOptions modifiers.
func (s *FunctionSignature) DebugString(functionName string, verbose bool) string {
	var v unsafe.Pointer
	internal.FunctionSignature_DebugString(s.raw, helper.StringToPtr(functionName), helper.BoolToInt(verbose), &v)
	return helper.PtrToString(v)
}

// SQLDeclaration get the SQL declaration for this signature, including all options.
// For each argument in the signature, the name will be taken from the
// corresponding entry of <argument_names> if present.  An empty
// <argument_names> will result in a signature with just type names.
// The result is formatted as "(arg_name type, ...) RETURNS type", which
// is valid to use in CREATE FUNCTION, DROP FUNCTION, etc, if possible.
func (s *FunctionSignature) SQLDeclaration(argumentNames []string, mode ProductMode) string {
	names := helper.SliceToPtr(argumentNames, func(i int) unsafe.Pointer {
		return helper.StringToPtr(argumentNames[i])
	})
	var v unsafe.Pointer
	internal.FunctionSignature_GetSQLDeclaration(s.raw, names, int(mode), &v)
	return helper.PtrToString(v)
}

func (s *FunctionSignature) IsDeprecated() bool {
	var v bool
	internal.FunctionSignature_IsDeprecated(s.raw, &v)
	return v
}

func (s *FunctionSignature) SetIsDeprecated(v bool) {
	internal.FunctionSignature_SetIsDeprecated(s.raw, helper.BoolToInt(v))
}

func (s *FunctionSignature) IsInternal() bool {
	var v bool
	internal.FunctionSignature_IsInternal(s.raw, &v)
	return v
}

func (s *FunctionSignature) Options() *FunctionSignatureOptions {
	var v unsafe.Pointer
	internal.FunctionSignature_options(s.raw, &v)
	return newFunctionSignatureOptions(v)
}

func (s *FunctionSignature) SetConcreteResultType(typ Type) {
	internal.FunctionSignature_SetConcreteResultType(s.raw, typ.getRaw())
}

// IsTemplated returns true if this function signature contains any templated arguments.
func (s *FunctionSignature) IsTemplated() bool {
	var v bool
	internal.FunctionSignature_IsTemplated(s.raw, &v)
	return v
}

// Returns true if all the arguments in the signature have default values.
// Note this function returns true when the signature has no arguments.
func (s *FunctionSignature) AllArgumentsHaveDefaults() bool {
	var v bool
	internal.FunctionSignature_AllArgumentsHaveDefaults(s.raw, &v)
	return v
}

type FunctionSignatureOptions struct {
	raw unsafe.Pointer
}

// Function interface identifies the functions available in a query engine.
// Each Function includes a set of FunctionSignatures, where
// a signature indicates:
//
//  1) Argument and result types.
//  2) A 'context' for the signature.
//
// A Function also indicates the 'group' it belongs to.
//
// The Function also includes <function_options_> for specifying additional
// resolution requirements, if any.  Additionally, <function_options_> can
// identify a function alias/synonym that Catalogs must expose for function
// lookups by name.
type Function struct {
	raw unsafe.Pointer
}

func (f *Function) Name() string {
	var v unsafe.Pointer
	internal.Function_Name(f.raw, &v)
	return helper.PtrToString(v)
}

func (f *Function) FunctionNamePath() []string {
	var v unsafe.Pointer
	internal.Function_FunctionNamePath(f.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

// FullName returns <function_name_path_> strings joined with '.', and if
// <include_group> is true then it is prefixed with the group name.
func (f *Function) FullName(includeGroup bool) string {
	var v unsafe.Pointer
	internal.Function_FullName(f.raw, helper.BoolToInt(includeGroup), &v)
	return helper.PtrToString(v)
}

// SQLName returns an external 'SQL' name for the function, for use in error messages
// and anywhere else appropriate.  If <function_options_> has its <sql_name>
// set then it returns <sql_name>.  If <sql_name> is not set and Name() is
// an internal function name (starting with '$'), then it strips off the '$'
// and converts any '_' to ' '.  Otherwise it simply returns Name() for
// ZetaSQL builtin functions and FullName() for non-builtin functions.
func (f *Function) SQLName() string {
	var v unsafe.Pointer
	internal.Function_SQLName(f.raw, &v)
	return helper.PtrToString(v)
}

// QualifiedSQLName returns SQLName() prefixed with either 'operator ' or 'function ',
// and 'aggregate ' or 'analytic ' if appropriate.  If <capitalize_qualifier>
// is true, then the first letter of the (first) qualifier is capitalized
// (i.e., 'Operator' vs. 'operator' and 'Analytic function' vs.
// 'analytic function').  A function uses the 'operator ' prefix if its name starts with '$'.
func (f *Function) QualifiedSQLName(capitalizeQualifier bool) string {
	var v unsafe.Pointer
	internal.Function_QualifiedSQLName(f.raw, helper.BoolToInt(capitalizeQualifier), &v)
	return helper.PtrToString(v)
}

// Group returns the 'group' the function belongs to.
func (f *Function) Group() string {
	var v unsafe.Pointer
	internal.Function_Group(f.raw, &v)
	return helper.PtrToString(v)
}

func (f *Function) IsZetaSQLBuiltin() bool {
	var v bool
	internal.Function_IsZetaSQLBuiltin(f.raw, &v)
	return v
}

func (f *Function) ArgumentsAreCoercible() bool {
	var v bool
	internal.Function_ArgumentsAreCoercible(f.raw, &v)
	return v
}

// NumSignatures returns the number of function signatures.
func (f *Function) NumSignatures() int {
	var v int
	internal.Function_NumSignatures(f.raw, &v)
	return v
}

// Signatures returns all of the function signatures.
func (f *Function) Signatures() []*FunctionSignature {
	var v unsafe.Pointer
	internal.Function_signatures(f.raw, &v)
	var ret []*FunctionSignature
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newFunctionSignature(p))
	})
	return ret
}

func (f *Function) ResetSignatures(sigs []*FunctionSignature) {
	internal.Function_ResetSignatures(f.raw, helper.SliceToPtr(sigs, func(i int) unsafe.Pointer {
		return sigs[i].raw
	}))
}

// AddSignature adds a function signature to an existing function.
func (f *Function) AddSignature(sig *FunctionSignature) {
	internal.Function_AddSignature(f.raw, sig.raw)
}

func (f *Function) Mode() Mode {
	var v int
	internal.Function_mode(f.raw, &v)
	return Mode(v)
}

func (f *Function) IsScalar() bool {
	var v bool
	internal.Function_IsScalar(f.raw, &v)
	return v
}

func (f *Function) IsAggregate() bool {
	var v bool
	internal.Function_IsAggregate(f.raw, &v)
	return v
}

func (f *Function) IsAnalytic() bool {
	var v bool
	internal.Function_IsAnalytic(f.raw, &v)
	return v
}

// DebugString returns the function name.
// If <verbose> then also returns DebugString() of all its function signatures.
func (f *Function) DebugString(verbose bool) string {
	var v unsafe.Pointer
	internal.Function_DebugString(f.raw, helper.BoolToInt(verbose), &v)
	return helper.PtrToString(v)
}

func (f *Function) SQL(inputs []string, sig *FunctionSignature) string {
	var sigRaw unsafe.Pointer
	if sig.raw != nil {
		sigRaw = sig.raw
	}
	p := helper.SliceToPtr(inputs, func(i int) unsafe.Pointer {
		return helper.StringToPtr(inputs[i])
	})
	var v unsafe.Pointer
	internal.Function_GetSQL(f.raw, p, sigRaw, &v)
	return helper.PtrToString(v)
}

// SupportsOverClause returns true if it supports the OVER clause (i.e. this function can act as
// an analytic function). If true, the mode cannot be SCALAR.
func (f *Function) SupportsOverClause() bool {
	var v bool
	internal.Function_SupportsOverClause(f.raw, &v)
	return v
}

// SupportsWindowOrdering returns true if ORDER BY is allowed in a window definition for this function.
func (f *Function) SupportsWindowOrdering() bool {
	var v bool
	internal.Function_SupportsWindowOrdering(f.raw, &v)
	return v
}

// RequiresWindowOrdering returns true if ORDER BY must be specified in a window definition for this function.
func (f *Function) RequiresWindowOrdering() bool {
	var v bool
	internal.Function_RequiresWindowOrdering(f.raw, &v)
	return v
}

// SupportsWindowFraming returns true if window framing clause is allowed in a window definition for this function.
func (f *Function) SupportsWindowFraming() bool {
	var v bool
	internal.Function_SupportsWindowFraming(f.raw, &v)
	return v
}

// SupportsOrderingArguments returns true if order by is allowed in the function arguments.
func (f *Function) SupportsOrderingArguments() bool {
	var v bool
	internal.Function_SupportsOrderingArguments(f.raw, &v)
	return v
}

// SupportsLimitArguments returns true if LIMIT is allowed in the function arguments.
func (f *Function) SupportsLimitArguments() bool {
	var v bool
	internal.Function_SupportsLimitArguments(f.raw, &v)
	return v
}

// SupportsNullHandlingModifier returns true if IGNORE NULLS and RESPECT NULLS are allowed in the function arguments.
func (f *Function) SupportsNullHandlingModifier() bool {
	var v bool
	internal.Function_SupportsNullHandlingModifier(f.raw, &v)
	return v
}

// SupportsSafeErrorMode returns true if this function supports SAFE_ERROR_MODE.  See full comment on field definition.
func (f *Function) SupportsSafeErrorMode() bool {
	var v bool
	internal.Function_SupportsSafeErrorMode(f.raw, &v)
	return v
}

// SupportsHavingModifier returns true if HAVING is allowed in the function arguments.
func (f *Function) SupportsHavingModifier() bool {
	var v bool
	internal.Function_SupportsHavingModifier(f.raw, &v)
	return v
}

// SupportsDistinctModifier returns true if DISTINCT is allowed in the function arguments.
func (f *Function) SupportsDistinctModifier() bool {
	var v bool
	internal.Function_SupportsDistinctModifier(f.raw, &v)
	return v
}

// SupportsClampedBetweenModifier returns true if CLAMPED BETWEEN is allowed in the function arguments.
// Must only be true for differential privacy functions.
func (f *Function) SupportsClampedBetweenModifier() bool {
	var v bool
	internal.Function_SupportsClampedBetweenModifier(f.raw, &v)
	return v
}

// IsDeprecated
func (f *Function) IsDeprecated() bool {
	var v bool
	internal.Function_IsDeprecated(f.raw, &v)
	return v
}

// AliasName
func (f *Function) AliasName() string {
	var v unsafe.Pointer
	internal.Function_alias_name(f.raw, &v)
	return helper.PtrToString(v)
}

type BuiltinFunctionOptions struct {
	raw unsafe.Pointer
}

// Functions in a nested catalog should use the constructor with the
// <namePath>, identifying the full path name of the function
// including its containing catalog names.
//
// These constructors perform ZETASQL_CHECK validations of basic invariants:
// * Scalar functions cannot support the OVER clause.
// * Analytic functions must support OVER clause.
// * Signatures must satisfy FunctionSignature.IsValidForFunction().
func NewFunction(namePath []string, group string, mode Mode, sigs []*FunctionSignature) *Function {
	var v unsafe.Pointer
	internal.Function_new(
		helper.StringsToPtr(namePath),
		helper.StringToPtr(group),
		int(mode),
		helper.SliceToPtr(sigs, func(idx int) unsafe.Pointer {
			return sigs[idx].raw
		}),
		&v,
	)
	return newFunction(v)
}

func NewFunctionSignature(resultType *FunctionArgumentType, args []*FunctionArgumentType) *FunctionSignature {
	var v unsafe.Pointer
	internal.FunctionSignature_new(resultType.raw, helper.SliceToPtr(args, func(idx int) unsafe.Pointer {
		return args[idx].raw
	}), &v)
	return newFunctionSignature(v)
}

func NewFunctionArgumentType(typ Type, opt *FunctionArgumentTypeOptions) *FunctionArgumentType {
	if opt == nil {
		opt = NewFunctionArgumentTypeOptions(RequiredArgumentCardinality)
	}
	var v unsafe.Pointer
	internal.FunctionArgumentType_new(typ.getRaw(), opt.getRaw(), &v)
	return newFunctionArgumentType(v)
}

func NewTemplatedFunctionArgumentType(kind SignatureArgumentKind, opt *FunctionArgumentTypeOptions) *FunctionArgumentType {
	if opt == nil {
		opt = NewFunctionArgumentTypeOptions(RequiredArgumentCardinality)
	}
	var v unsafe.Pointer
	internal.FunctionArgumentType_new_templated_type(int(kind), opt.getRaw(), &v)
	return newFunctionArgumentType(v)
}

func NewFunctionArgumentTypeOptions(cardinality ArgumentCardinality) *FunctionArgumentTypeOptions {
	var v unsafe.Pointer
	internal.FunctionArgumentTypeOptions_new(int(cardinality), &v)
	return newFunctionArgumentTypeOptions(v)
}

//go:noinline
func newFunction(v unsafe.Pointer) *Function {
	return &Function{raw: v}
}

func getRawFunction(v *Function) unsafe.Pointer {
	return v.raw
}

//go:noinline
func newFunctionSignature(v unsafe.Pointer) *FunctionSignature {
	return &FunctionSignature{raw: v}
}

func getRawFunctionSignature(v *FunctionSignature) unsafe.Pointer {
	return v.raw
}

//go:noinline
func newFunctionArgumentType(v unsafe.Pointer) *FunctionArgumentType {
	return &FunctionArgumentType{raw: v}
}

func getRawFunctionArgumentType(v *FunctionArgumentType) unsafe.Pointer {
	return v.raw
}

//go:noinline
func newFunctionArgumentTypeOptions(v unsafe.Pointer) *FunctionArgumentTypeOptions {
	if v == nil {
		return nil
	}
	return &FunctionArgumentTypeOptions{raw: v}
}

func getRawFunctionArgumentTypeOptions(v *FunctionArgumentTypeOptions) unsafe.Pointer {
	if v == nil {
		return nil
	}
	return v.raw
}

func newArgumentTypeLambda(v unsafe.Pointer) *ArgumentTypeLambda {
	return &ArgumentTypeLambda{raw: v}
}

func getRawArgumentTypeLambda(v *ArgumentTypeLambda) unsafe.Pointer {
	return v.raw
}

func newFunctionSignatureOptions(v unsafe.Pointer) *FunctionSignatureOptions {
	return &FunctionSignatureOptions{raw: v}
}

func getRawFunctionSignatureOptions(v *FunctionSignatureOptions) unsafe.Pointer {
	return v.raw
}

func newBuiltinFunctionOptions(v unsafe.Pointer) *BuiltinFunctionOptions {
	return &BuiltinFunctionOptions{raw: v}
}
