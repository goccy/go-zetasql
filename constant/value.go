package constant

import (
	"time"
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/public/simple_catalog"
	"github.com/goccy/go-zetasql/internal/helper"
	"github.com/goccy/go-zetasql/types"
)

type Value interface {
	// Type returns the type of the value.
	Type() types.Type

	// TypeKind returns the type kind of the value.
	TypeKind() types.TypeKind

	// PhysicalByteSize returns the estimated size of the in-memory C++ representation of this value.
	PhysicalByteSize() uint64

	// IsNull returns true if the value is null.
	IsNull() bool

	// IsEmptyArray returns true if the value is an empty array.
	IsEmptyArray() bool

	// IsValid returns true if the value is valid (invalid values are created by the default constructor).
	IsValid() bool

	// HasContent returns true if the Value is valid and non-null.
	HasContent() bool

	// Int32Value REQUIRES: int32 type
	Int32Value() int32

	// Int64Value REQUIRES: int64 type
	Int64Value() int64

	// Uint32Value REQUIRES: uint32 type
	Uint32Value() uint32

	// Uint64Value REQUIRES: uint64 type
	Uint64Value() uint64

	// BoolValue REQUIRES: bool type
	BoolValue() bool

	// FloatValue REQUIRES: float type
	FloatValue() float32

	// DoubleValue REQUIRES: double type
	DoubleValue() float64

	// StringValue REQUIRES: string type
	StringValue() string

	// BytesValue REQUIRES: bytes type
	BytesValue() []byte

	// DateValue REQUIRES: date type
	DateValue() int32

	// EnumValue REQUIRES: enum type
	EnumValue() int32

	// EnumName REQUIRES: enum type
	EnumName() string

	// ToTime REQUIRES: timestamp type
	ToTime() time.Time

	// ToUnixMicros returns timestamp value as Unix epoch microseconds. REQUIRES: timestamp type
	ToUnixMicros() int64

	// ToUnixNanos returns timestamp value as Unix epoch nanoseconds or an error if the value
	// does not fit into an int64. REQUIRES: timestamp type
	ToUnixNanos() (int64, error)

	// ToPacked64TimeMicros REQUIRES: time type.
	ToPacked64TimeMicros() int64

	// ToPacked64DatetimeMicros REQUIRES: datetime type.
	ToPacked64DatetimeMicros() int64

	//TimeValue() TimeValue
	//DatetimeValue() DatetimeValue
	//NumericValue() NumericValue
	//BignumericValue() BigNumericValue

	// IsValidatedJSON checks whether the value belongs to the JSON type, non-NULL and is in
	// validated representation. JSON values can be in one of the two
	// representations:
	//  1) Validated: JSON is parsed, validated and transformed into an efficient
	//    (for field read/updates) in-memory representation (field tree) that can
	//    be accessed through json_value() method. ZetaSQL Analyzer uses this
	//    representation by default to represent JSON values (e.g. literals).
	//  2) Unparsed: string that was not validated and thus potentially can be
	//    an invalid JSON. ZetaSQL Analyzer uses this representation when
	//    LanguageFeature FEATURE_JSON_NO_VALIDATION is enabled.
	IsValidatedJSON() bool

	// IsUnparsedJSON returns true if the value belongs to the JSON type, non-null and is in
	// unparsed representation. See comments to IsValidatedJSON() for more details.
	IsUnparsedJSON() bool

	JSONValueUnparsed() string
	JSONString() string

	// ToInt64 for bool, int32, int64, date, enum types.
	ToInt64() int64

	// ToUint64 for bool, uint32, uint64 types.
	ToUint64() uint64
	ToDouble() float64

	// NumFields struct-specific methods. REQUIRES: !IsNull().
	NumFields() int

	Field(int) Value
	Fields() []Value

	// FindFieldByName returns the value of the first field with the given 'name'.
	// If one doesn't exist, returns an invalid value.
	// Does not find anonymous fields (those with empty names).
	FindFieldByName(name string) Value

	// Empty array-specific methods. REQUIRES: !IsNull().
	Empty() bool
	NumElements() int
	Element(int) Value
	Elements() []Value

	// Equals returns true if 'this' equals 'that' or both are null. This is *not* SQL
	// equality which returns null when either value is null. Returns false if
	// 'this' and 'that' have different types. For floating point values, returns
	// 'true' if both values are NaN of the same type.
	// For protos, returns true if the protos have the equivalent descriptors
	// (using Type::Equivalent) and the values are equivalent according to
	// MessageDifferencer::Equals, using the descriptor from 'this'.
	Equals(Value) bool

	// SQLEquals returns the BOOL (possibly NULL) Value of the SQL expression (*this =
	// that). Handles corner cases involving NULLs and NaNs. Returns an invalid
	// Value if the value types are not directly comparable (without an implicit
	// or explicit cast). (For example, INT64 and UINT64 are directly comparable,
	// but INT64 and INT32 are not comparable without a widening cast.) To be
	// safe, it is best to only use this method with Types that appear as
	// arguments to a call to the $equals function in a resolved AST generated by
	// the resolver.
	SQLEquals(Value) Value

	// LessThan when the types of 'this' and 'that' are compatible, this function returns
	// true when 'this' is smaller than 'that'. When the types of 'this' and
	// 'that' are not compatible, the behavior is undefined.
	//
	// For simple types, this uses '<' operator on native c++ types to compare the
	// values. A null value is less than any non-null value. This is
	// *not* SQL inequality. For floating point values, NaN sorts smaller than
	// any other value including negative infinity.
	// For struct types, this compares the fields of the STRUCT pairwise in
	// ordinal order, returns true as soon as LessThan returns true for a field.
	// For array types, this compares the arrays in lexicographical order.
	LessThan(Value) bool

	// SQLLessThan returns the BOOL (possibly NULL) Value of the SQL expression (*this <
	// that). Handles corner cases involving NULLs, NaNs. Returns an invalid Value
	// if the value types are not directly comparable (without an implicit or
	// explicit cast). (For example, INT64 and UINT64 are directly comparable, but
	// INT64 and INT32 are not comparable without a widening cast.) To be safe, it
	// is best to only use this method with Types that appear as arguments to a
	// call to a comparison function ($equals, $less, $less_or_equals, $greater,
	// or $greater_or_equals) in a resolved AST generated by the resolver.
	SQLLessThan(Value) Value

	// HashCode returns the hash code of a value.
	//
	// Result is not guaranteed stable across different runs of a program. It is
	// not cryptographically secure. It should not be used for distributed
	// coordination, security or storage which requires a stable computation.
	//
	// For more background see https://abseil.io/docs/cpp/guides/hash.
	HashCode() uint64

	// ShortDebugString returns printable string for this Value.
	// Verbose DebugStrings include the type name.
	ShortDebugString() string
	FullDebugString() string
	DebugString() string

	// Format returns a pretty-printed (e.g. wrapped) string for the value.
	// Suitable for printing in golden-tests and documentation.
	Format() string

	// SQL returns a SQL expression that produces this value.
	// This is not necessarily a literal since we don't have literal syntax
	// for all values.
	// This assumes that any types used in Value can be resolved using the name
	// returned from type->TypeName().  Returned type names are sensitive to
	// the SQL ProductMode (INTERNAL or EXTERNAL).
	//
	// Note: Arguably, GetSQL() and GetSQLLiteral() don't work quite right for
	// STRUCTs.  In particular, they do not preserve field names in the result
	// string.  For example, if you have a STRUCT value like
	// STRUCT<a INT64, b STRING>(1, 'a'), and call GetSQL(), the result will
	// be "(1, 'a')".  If we're only interested in the value itself and not the
	// original type (with named fields) then maybe that's ok.  Note that
	// GetSQLLiteral() is used in ZetaSQL's FORMAT() function implementation
	// (Format() in zetasql/public_functions/format.cc) so we cannot change
	// the output without breaking existing ZetaSQL function semantics.
	SQL(mode types.ProductMode) string

	// SQLLiteral returns a SQL expression that is compatible as a literal for this value.
	// This won't include CASTs except for non-finite floating point values, and
	// won't necessarily produce the exact same type when parsed on its own, but
	// it should be the closest SQL literal form for this value.  Returned type
	// names are sensitive to the SQL ProductMode (INTERNAL or EXTERNAL).
	SQLLiteral(mode types.ProductMode) string
	getRaw() unsafe.Pointer
}

type value struct {
	raw unsafe.Pointer
}

func (v *value) Type() types.Type {
	var ret unsafe.Pointer
	internal.Value_type(v.raw, &ret)
	return newType(ret)
}

func (v *value) TypeKind() types.TypeKind {
	var ret int
	internal.Value_type_kind(v.raw, &ret)
	return types.TypeKind(ret)
}

func (v *value) PhysicalByteSize() uint64 {
	var ret uint64
	internal.Value_physical_byte_size(v.raw, &ret)
	return ret
}

func (v *value) IsNull() bool {
	var ret bool
	internal.Value_is_null(v.raw, &ret)
	return ret
}

func (v *value) IsEmptyArray() bool {
	var ret bool
	internal.Value_is_empty_array(v.raw, &ret)
	return ret
}

func (v *value) IsValid() bool {
	var ret bool
	internal.Value_is_valid(v.raw, &ret)
	return ret
}

func (v *value) HasContent() bool {
	var ret bool
	internal.Value_has_content(v.raw, &ret)
	return ret
}

func (v *value) Int32Value() int32 {
	var ret int32
	internal.Value_int32_value(v.raw, &ret)
	return ret
}

func (v *value) Int64Value() int64 {
	var ret int64
	internal.Value_int64_value(v.raw, &ret)
	return ret
}

func (v *value) Uint32Value() uint32 {
	var ret uint32
	internal.Value_uint32_value(v.raw, &ret)
	return ret
}

func (v *value) Uint64Value() uint64 {
	var ret uint64
	internal.Value_uint64_value(v.raw, &ret)
	return ret
}

func (v *value) BoolValue() bool {
	var ret bool
	internal.Value_bool_value(v.raw, &ret)
	return ret
}

func (v *value) FloatValue() float32 {
	var ret float32
	internal.Value_float_value(v.raw, &ret)
	return ret
}

func (v *value) DoubleValue() float64 {
	var ret float64
	internal.Value_double_value(v.raw, &ret)
	return ret
}

func (v *value) StringValue() string {
	var ret unsafe.Pointer
	internal.Value_string_value(v.raw, &ret)
	return helper.PtrToString(ret)
}

func (v *value) BytesValue() []byte {
	var ret unsafe.Pointer
	internal.Value_bytes_value(v.raw, &ret)
	return []byte(helper.PtrToString(ret))
}

func (v *value) DateValue() int32 {
	var ret int32
	internal.Value_date_value(v.raw, &ret)
	return ret
}

func (v *value) EnumValue() int32 {
	var ret int32
	internal.Value_enum_value(v.raw, &ret)
	return ret
}

func (v *value) EnumName() string {
	var ret unsafe.Pointer
	internal.Value_enum_name(v.raw, &ret)
	return helper.PtrToString(ret)
}

func (v *value) ToTime() time.Time {
	return time.Time{}
}

func (v *value) ToUnixMicros() int64 {
	var ret int64
	internal.Value_ToUnixMicros(v.raw, &ret)
	return ret
}

func (v *value) ToUnixNanos() (int64, error) {
	var (
		ret    int64
		status unsafe.Pointer
	)
	internal.Value_ToUnixNanos(v.raw, &ret, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return 0, st.Error()
	}
	return ret, nil
}

func (v *value) ToPacked64TimeMicros() int64 {
	var ret int64
	internal.Value_ToPacked64TimeMicros(v.raw, &ret)
	return ret
}

func (v *value) ToPacked64DatetimeMicros() int64 {
	var ret int64
	internal.Value_ToPacked64DatetimeMicros(v.raw, &ret)
	return ret
}

//func (v *value)TimeValue() TimeValue
//func (v *value)DatetimeValue() DatetimeValue
//func (v *value)NumericValue() NumericValue
//func (v *value)BignumericValue() BigNumericValue

func (v *value) IsValidatedJSON() bool {
	var ret bool
	internal.Value_is_validated_json(v.raw, &ret)
	return ret
}

func (v *value) IsUnparsedJSON() bool {
	var ret bool
	internal.Value_is_unparsed_json(v.raw, &ret)
	return ret
}

func (v *value) JSONValueUnparsed() string {
	var ret unsafe.Pointer
	internal.Value_json_value_unparsed(v.raw, &ret)
	return helper.PtrToString(ret)
}

func (v *value) JSONString() string {
	var ret unsafe.Pointer
	internal.Value_json_string(v.raw, &ret)
	return helper.PtrToString(ret)
}

func (v *value) ToInt64() int64 {
	var ret int64
	internal.Value_ToInt64(v.raw, &ret)
	return ret
}

func (v *value) ToUint64() uint64 {
	var ret uint64
	internal.Value_ToUint64(v.raw, &ret)
	return ret
}

func (v *value) ToDouble() float64 {
	var ret float64
	internal.Value_ToDouble(v.raw, &ret)
	return ret
}

func (v *value) NumFields() int {
	var ret int
	internal.Value_num_fields(v.raw, &ret)
	return ret
}

func (v *value) Field(i int) Value {
	var ret unsafe.Pointer
	internal.Value_field(v.raw, i, &ret)
	return newValue(ret)
}

func (v *value) Fields() []Value {
	return nil
}

func (v *value) FindFieldByName(name string) Value {
	var ret unsafe.Pointer
	internal.Value_FindFieldByName(v.raw, helper.StringToPtr(name), &ret)
	return newValue(ret)
}

func (v *value) Empty() bool {
	var ret bool
	internal.Value_empty(v.raw, &ret)
	return ret
}

func (v *value) NumElements() int {
	var ret int
	internal.Value_num_elements(v.raw, &ret)
	return ret
}

func (v *value) Element(i int) Value {
	var ret unsafe.Pointer
	internal.Value_element(v.raw, i, &ret)
	return newValue(ret)
}

func (v *value) Elements() []Value {
	return nil
}

func (v *value) Equals(that Value) bool {
	var ret bool
	internal.Value_Equals(v.raw, that.getRaw(), &ret)
	return ret
}

func (v *value) SQLEquals(that Value) Value {
	var ret unsafe.Pointer
	internal.Value_SqlEquals(v.raw, that.getRaw(), &ret)
	return newValue(ret)
}

func (v *value) LessThan(that Value) bool {
	var ret bool
	internal.Value_LessThan(v.raw, that.getRaw(), &ret)
	return ret
}

func (v *value) SQLLessThan(that Value) Value {
	var ret unsafe.Pointer
	internal.Value_SqlLessThan(v.raw, that.getRaw(), &ret)
	return newValue(ret)
}

func (v *value) HashCode() uint64 {
	var ret uint64
	internal.Value_HashCode(v.raw, &ret)
	return ret
}

func (v *value) ShortDebugString() string {
	var ret unsafe.Pointer
	internal.Value_ShortDebugString(v.raw, &ret)
	return helper.PtrToString(ret)
}

func (v *value) FullDebugString() string {
	var ret unsafe.Pointer
	internal.Value_FullDebugString(v.raw, &ret)
	return helper.PtrToString(ret)
}

func (v *value) DebugString() string {
	var ret unsafe.Pointer
	internal.Value_DebugString(v.raw, &ret)
	return helper.PtrToString(ret)
}

func (v *value) Format() string {
	var ret unsafe.Pointer
	internal.Value_Format(v.raw, &ret)
	return helper.PtrToString(ret)
}

func (v *value) SQL(mode types.ProductMode) string {
	var ret unsafe.Pointer
	internal.Value_GetSQL(v.raw, int(mode), &ret)
	return helper.PtrToString(ret)
}

func (v *value) SQLLiteral(mode types.ProductMode) string {
	var ret unsafe.Pointer
	internal.Value_GetSQLLiteral(v.raw, int(mode), &ret)
	return helper.PtrToString(ret)
}

func (v *value) getRaw() unsafe.Pointer {
	return v.raw
}

func newValue(v unsafe.Pointer) Value {
	if v == nil {
		return nil
	}
	return &value{raw: v}
}

func getRawValue(v Value) unsafe.Pointer {
	return v.getRaw()
}

func Int64(v int64) Value {
	var ret unsafe.Pointer
	internal.Int64(v, &ret)
	return newValue(ret)
}

//go:linkname newType github.com/goccy/go-zetasql/types.newType
func newType(unsafe.Pointer) types.Type
