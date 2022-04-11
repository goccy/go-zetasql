package zetasql

import (
	"reflect"
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/public/simple_catalog"
	"github.com/goccy/go-zetasql/internal/helper"
)

type TypeList []Type
type TypeListView = TypeList

type AnonymizationInfo struct {
	raw unsafe.Pointer
}

func newAnonymizationInfo(v unsafe.Pointer) *AnonymizationInfo {
	if v == nil {
		return nil
	}
	return &AnonymizationInfo{raw: v}
}

type TypeParameters struct {
	raw unsafe.Pointer
}

type TypeParameterValue struct {
	raw unsafe.Pointer
}

type AnnotatedType struct {
	raw unsafe.Pointer
}

func newAnnotatedType(raw unsafe.Pointer) *AnnotatedType {
	if raw == nil {
		return nil
	}
	return &AnnotatedType{raw: raw}
}

type TypeKind int

const (
	UnknownType TypeKind = 0
	Int32                = 1
	Int64                = 2
	Uint32               = 3
	Uint64               = 4
	Bool                 = 5
	Float                = 6
	Double               = 7
	String               = 8
	Bytes                = 9
	Date                 = 10
	Timestamp            = 19
	Enum                 = 15
	Array                = 16
	Struct               = 17
	Proto                = 18
	Time                 = 20
	Datetime             = 21
	Geography            = 22
	Numeric              = 23
	BigNumeric           = 24
	Extended             = 25
	Json                 = 26
	Internal             = 27
)

func (k TypeKind) String() string {
	switch k {
	case UnknownType:
		return "UNKNOWN"
	case Int32:
		return "INT32"
	case Int64:
		return "INT64"
	case Uint32:
		return "UINT32"
	case Uint64:
		return "UINT64"
	case Bool:
		return "BOOL"
	case Float:
		return "FLOAT"
	case Double:
		return "DOUBLE"
	case String:
		return "STRING"
	case Bytes:
		return "BYTES"
	case Date:
		return "DATE"
	case Timestamp:
		return "TIMESTAMP"
	case Enum:
		return "ENUM"
	case Array:
		return "ARRAY"
	case Struct:
		return "STRUCT"
	case Proto:
		return "PROTO"
	case Time:
		return "TIME"
	case Datetime:
		return "DATETIME"
	case Geography:
		return "GEOGRAPHY"
	case Numeric:
		return "NUMERIC"
	case BigNumeric:
		return "BIGNUMERIC"
	case Extended:
		return "EXTENDED"
	case Json:
		return "JSON"
	case Internal:
		return "INTERNAL"
	}
	return ""
}

type Type interface {
	Kind() TypeKind
	IsInt32() bool
	IsInt64() bool
	IsUint32() bool
	IsUint64() bool
	IsBool() bool
	IsFloat() bool
	IsDouble() bool
	IsString() bool
	IsBytes() bool
	IsDate() bool
	IsTimestamp() bool
	IsTime() bool
	IsDatetime() bool
	IsInterval() bool
	IsNumericType() bool
	IsBigNumericType() bool
	IsJsonType() bool
	IsFeatureV12CivilTimeType() bool
	UsingFeatureV12CivilTimeType() bool
	IsCivilDateOrTimeType() bool
	IsGeography() bool
	IsJson() bool
	IsEnum() bool
	IsArray() bool
	IsStruct() bool
	IsProto() bool
	IsStructOrProto() bool
	IsFloatingPoint() bool
	IsNumerical() bool
	IsInteger() bool
	IsInteger32() bool
	IsInteger64() bool
	IsSignedInteger() bool
	IsUnsignedInteger() bool
	IsSimpleType() bool
	IsExtendedType() bool
	SupportsGrouping() bool
	SupportsPartitioning() bool
	SupportsOrdering() bool
	SupportsEquality() bool
	Equals(Type) bool
	Equivalent(Type) bool
	ShortTypeName(ProductMode) string
	TypeName(ProductMode) string
	TypeNameWithParameters(*TypeParameters, ProductMode) (string, error)
	DebugString(details bool) string
	HasAnyFields() bool
	NestingDepth() int
	ValidateAndResolveTypeParameters(values []TypeParameterValue, mode ProductMode) (*TypeParameters, error)
	ValidateResolvedTypeParameters(params *TypeParameters, mode ProductMode) error
	getRaw() unsafe.Pointer
}

func newType(v unsafe.Pointer) Type {
	if v == nil {
		return nil
	}
	return &ztype{raw: v}
}

type ztype struct {
	raw unsafe.Pointer
}

func (t *ztype) getRaw() unsafe.Pointer {
	return t.raw
}

func (t *ztype) Kind() TypeKind {
	var v int
	internal.Type_Kind(t.raw, &v)
	return TypeKind(v)
}

func (t *ztype) IsInt32() bool {
	var v bool
	internal.Type_IsInt32(t.raw, &v)
	return v
}

func (t *ztype) IsInt64() bool {
	var v bool
	internal.Type_IsInt64(t.raw, &v)
	return v
}

func (t *ztype) IsUint32() bool {
	var v bool
	internal.Type_IsUint32(t.raw, &v)
	return v
}

func (t *ztype) IsUint64() bool {
	var v bool
	internal.Type_IsUint64(t.raw, &v)
	return v
}

func (t *ztype) IsBool() bool {
	var v bool
	internal.Type_IsBool(t.raw, &v)
	return v
}

func (t *ztype) IsFloat() bool {
	var v bool
	internal.Type_IsFloat(t.raw, &v)
	return v
}

func (t *ztype) IsDouble() bool {
	var v bool
	internal.Type_IsDouble(t.raw, &v)
	return v
}

func (t *ztype) IsString() bool {
	var v bool
	internal.Type_IsString(t.raw, &v)
	return v
}

func (t *ztype) IsBytes() bool {
	var v bool
	internal.Type_IsBytes(t.raw, &v)
	return v
}

func (t *ztype) IsDate() bool {
	var v bool
	internal.Type_IsDate(t.raw, &v)
	return v
}

func (t *ztype) IsTimestamp() bool {
	var v bool
	internal.Type_IsTimestamp(t.raw, &v)
	return v
}

func (t *ztype) IsTime() bool {
	var v bool
	internal.Type_IsTime(t.raw, &v)
	return v
}

func (t *ztype) IsDatetime() bool {
	var v bool
	internal.Type_IsDatetime(t.raw, &v)
	return v
}

func (t *ztype) IsInterval() bool {
	var v bool
	internal.Type_IsInterval(t.raw, &v)
	return v
}

func (t *ztype) IsNumericType() bool {
	var v bool
	internal.Type_IsNumericType(t.raw, &v)
	return v
}

func (t *ztype) IsBigNumericType() bool {
	var v bool
	internal.Type_IsBigNumericType(t.raw, &v)
	return v
}

func (t *ztype) IsJsonType() bool {
	var v bool
	internal.Type_IsJsonType(t.raw, &v)
	return v
}

func (t *ztype) IsFeatureV12CivilTimeType() bool {
	var v bool
	internal.Type_IsFeatureV12CivilTimeType(t.raw, &v)
	return v
}

func (t *ztype) UsingFeatureV12CivilTimeType() bool {
	var v bool
	internal.Type_UsingFeatureV12CivilTimeType(t.raw, &v)
	return v
}

func (t *ztype) IsCivilDateOrTimeType() bool {
	var v bool
	internal.Type_IsCivilDateOrTimeType(t.raw, &v)
	return v
}

func (t *ztype) IsGeography() bool {
	var v bool
	internal.Type_IsGeography(t.raw, &v)
	return v
}

func (t *ztype) IsJson() bool {
	var v bool
	internal.Type_IsJson(t.raw, &v)
	return v
}

func (t *ztype) IsEnum() bool {
	var v bool
	internal.Type_IsEnum(t.raw, &v)
	return v
}

func (t *ztype) IsArray() bool {
	var v bool
	internal.Type_IsArray(t.raw, &v)
	return v
}

func (t *ztype) IsStruct() bool {
	var v bool
	internal.Type_IsStruct(t.raw, &v)
	return v
}

func (t *ztype) IsProto() bool {
	var v bool
	internal.Type_IsProto(t.raw, &v)
	return v
}

func (t *ztype) IsStructOrProto() bool {
	var v bool
	internal.Type_IsStructOrProto(t.raw, &v)
	return v
}

func (t *ztype) IsFloatingPoint() bool {
	var v bool
	internal.Type_IsFloatingPoint(t.raw, &v)
	return v
}

func (t *ztype) IsNumerical() bool {
	var v bool
	internal.Type_IsNumerical(t.raw, &v)
	return v
}

func (t *ztype) IsInteger() bool {
	var v bool
	internal.Type_IsInteger(t.raw, &v)
	return v
}

func (t *ztype) IsInteger32() bool {
	var v bool
	internal.Type_IsInteger32(t.raw, &v)
	return v
}

func (t *ztype) IsInteger64() bool {
	var v bool
	internal.Type_IsInteger64(t.raw, &v)
	return v
}

func (t *ztype) IsSignedInteger() bool {
	var v bool
	internal.Type_IsSignedInteger(t.raw, &v)
	return v
}

func (t *ztype) IsUnsignedInteger() bool {
	var v bool
	internal.Type_IsUnsignedInteger(t.raw, &v)
	return v
}

func (t *ztype) IsSimpleType() bool {
	var v bool
	internal.Type_IsSimpleType(t.raw, &v)
	return v
}

func (t *ztype) IsExtendedType() bool {
	var v bool
	internal.Type_IsExtendedType(t.raw, &v)
	return v
}

func (t *ztype) SupportsGrouping() bool {
	var v bool
	internal.Type_SupportsGrouping(t.raw, &v)
	return v
}

func (t *ztype) SupportsPartitioning() bool {
	var v bool
	internal.Type_SupportsPartitioning(t.raw, &v)
	return v
}

func (t *ztype) SupportsOrdering() bool {
	var v bool
	internal.Type_SupportsOrdering(t.raw, &v)
	return v
}

func (t *ztype) SupportsEquality() bool {
	var v bool
	internal.Type_SupportsEquality(t.raw, &v)
	return v
}

func (t *ztype) Equals(typ Type) bool {
	var v bool
	internal.Type_Equals(t.raw, typ.getRaw(), &v)
	return v
}

func (t *ztype) Equivalent(typ Type) bool {
	var v bool
	internal.Type_Equivalent(t.raw, typ.getRaw(), &v)
	return v
}

func (t *ztype) ShortTypeName(mode ProductMode) string {
	var v unsafe.Pointer
	internal.Type_ShortTypeName(t.raw, int(mode), &v)
	return helper.PtrToString(v)
}

func (t *ztype) TypeName(mode ProductMode) string {
	var v unsafe.Pointer
	internal.Type_TypeName(t.raw, int(mode), &v)
	return helper.PtrToString(v)
}

func (t *ztype) TypeNameWithParameters(param *TypeParameters, mode ProductMode) (string, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.Type_TypeNameWithParameters(t.raw, param.raw, int(mode), &v, &status)
	st := newStatus(status)
	if !st.OK() {
		return "", st.Error()
	}
	return helper.PtrToString(v), nil
}

func (t *ztype) DebugString(details bool) string {
	var v unsafe.Pointer
	internal.Type_DebugString(t.raw, helper.BoolToInt(details), &v)
	return helper.PtrToString(v)
}

func (t *ztype) HasAnyFields() bool {
	var v bool
	internal.Type_HasAnyFields(t.raw, &v)
	return v
}

func (t *ztype) NestingDepth() int {
	var v int
	internal.Type_NestingDepth(t.raw, &v)
	return v
}

func typeParamValueToPtr(v []TypeParameterValue) (unsafe.Pointer, int) {
	ptrs := make([]unsafe.Pointer, 0, len(v))
	for _, vv := range v {
		ptrs = append(ptrs, vv.raw)
	}
	slice := (*reflect.SliceHeader)(unsafe.Pointer(&ptrs))
	return unsafe.Pointer(slice.Data), slice.Len
}

func (t *ztype) ValidateAndResolveTypeParameters(values []TypeParameterValue, mode ProductMode) (*TypeParameters, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	data, len := typeParamValueToPtr(values)
	internal.Type_ValidateAndResolveTypeParameters(t.raw, data, len, int(mode), &v, &status)
	st := newStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newTypeParameters(v), nil
}

func (t *ztype) ValidateResolvedTypeParameters(params *TypeParameters, mode ProductMode) error {
	var (
		status unsafe.Pointer
	)
	internal.Type_ValidateResolvedTypeParameters(t.raw, params.raw, int(mode), &status)
	st := newStatus(status)
	if !st.OK() {
		return st.Error()
	}
	return nil
}

func newTypeParameters(raw unsafe.Pointer) *TypeParameters {
	return &TypeParameters{raw: raw}
}

type StructType struct {
	*ztype
	fields []*StructField
}

type StructField struct {
	Name string
	Type Type
}

func (t *StructType) NumFields() int {
	return len(t.fields)
}

func (t *StructType) Field(i int) *StructField {
	return t.fields[i]
}

func (t *StructType) Fields() []*StructField {
	return t.fields
}

type ArrayType struct {
	*ztype
	elem Type
}

func (t *ArrayType) ElementType() Type {
	return t.elem
}

type EnumType struct {
	*ztype
}

func (t *EnumType) FindName(number int) (string, bool) {
	return "", false
}

func (t *EnumType) FindNumber(name string) (int, bool) {
	return 0, false
}

var (
	int32Type             *ztype
	int64Type             *ztype
	uint32Type            *ztype
	uint64Type            *ztype
	boolType              *ztype
	floatType             *ztype
	doubleType            *ztype
	stringType            *ztype
	bytesType             *ztype
	dateType              *ztype
	timestampType         *ztype
	timeType              *ztype
	datetimeType          *ztype
	intervalType          *ztype
	geographyType         *ztype
	numericType           *ztype
	bigNumericType        *ztype
	jsonType              *ztype
	structType            *ztype
	int32ArrayType        *ArrayType
	int64ArrayType        *ArrayType
	uint32ArrayType       *ArrayType
	uint64ArrayType       *ArrayType
	boolArrayType         *ArrayType
	floatArrayType        *ArrayType
	doubleArrayType       *ArrayType
	stringArrayType       *ArrayType
	bytesArrayType        *ArrayType
	timestampArrayType    *ArrayType
	dateArrayType         *ArrayType
	datetimeArrayType     *ArrayType
	timeArrayType         *ArrayType
	intervalArrayType     *ArrayType
	geographyArrayType    *ArrayType
	numericArrayType      *ArrayType
	bigNumericArrayType   *ArrayType
	jsonArrayType         *ArrayType
	datePartEnumType      *EnumType
	normalizeModeEnumType *EnumType
	factory               *typeFactory
)

type typeFactory struct {
	raw unsafe.Pointer
}

func (f *typeFactory) createArrayType(elem Type) (*ArrayType, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.TypeFactory_MakeArrayType(f.raw, elem.getRaw(), &v, &status)
	st := newStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newArrayType(v, elem), nil
}

func fieldsToPtr(v []*StructField) (unsafe.Pointer, int) {
	ptrs := make([]unsafe.Pointer, 0, len(v))
	for _, vv := range v {
		ptrs = append(ptrs, unsafe.Pointer(vv))
	}
	slice := (*reflect.SliceHeader)(unsafe.Pointer(&ptrs))
	return unsafe.Pointer(slice.Data), slice.Len
}

func (f *typeFactory) createStructType(fields []*StructField) (*StructType, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	data, len := fieldsToPtr(fields)
	internal.TypeFactory_MakeStructType(f.raw, data, len, &v, &status)
	st := newStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newStructType(v, fields), nil
}

func newStructType(raw unsafe.Pointer, fields []*StructField) *StructType {
	return &StructType{ztype: &ztype{raw: raw}, fields: fields}
}

func newArrayType(raw unsafe.Pointer, elem Type) *ArrayType {
	return &ArrayType{ztype: &ztype{raw: raw}, elem: elem}
}

func newEnumType(raw unsafe.Pointer) *EnumType {
	return &EnumType{ztype: &ztype{raw: raw}}
}

func init() {
	{
		var v unsafe.Pointer
		internal.Int32Type(&v)
		int32Type = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.Int64Type(&v)
		int64Type = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.Uint32Type(&v)
		uint32Type = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.Uint64Type(&v)
		uint64Type = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.BoolType(&v)
		boolType = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.FloatType(&v)
		floatType = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.DoubleType(&v)
		doubleType = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.StringType(&v)
		stringType = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.BytesType(&v)
		bytesType = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.DateType(&v)
		dateType = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.TimestampType(&v)
		timestampType = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.TimeType(&v)
		timeType = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.DatetimeType(&v)
		datetimeType = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.IntervalType(&v)
		intervalType = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.GeographyType(&v)
		geographyType = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.NumericType(&v)
		numericType = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.BigNumericType(&v)
		bigNumericType = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.JsonType(&v)
		jsonType = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.EmptyStructType(&v)
		structType = &ztype{raw: v}
	}
	{
		var v unsafe.Pointer
		internal.Int32ArrayType(&v)
		int32ArrayType = newArrayType(v, int32Type)
	}
	{
		var v unsafe.Pointer
		internal.Int64ArrayType(&v)
		int64ArrayType = newArrayType(v, int64Type)
	}
	{
		var v unsafe.Pointer
		internal.Uint32ArrayType(&v)
		uint32ArrayType = newArrayType(v, uint32Type)
	}
	{
		var v unsafe.Pointer
		internal.Uint64ArrayType(&v)
		uint64ArrayType = newArrayType(v, uint64Type)
	}
	{
		var v unsafe.Pointer
		internal.BoolArrayType(&v)
		boolArrayType = newArrayType(v, boolType)
	}
	{
		var v unsafe.Pointer
		internal.FloatArrayType(&v)
		floatArrayType = newArrayType(v, floatType)
	}
	{
		var v unsafe.Pointer
		internal.DoubleArrayType(&v)
		doubleArrayType = newArrayType(v, doubleType)
	}
	{
		var v unsafe.Pointer
		internal.StringArrayType(&v)
		stringArrayType = newArrayType(v, stringType)
	}
	{
		var v unsafe.Pointer
		internal.BytesArrayType(&v)
		bytesArrayType = newArrayType(v, bytesType)
	}
	{
		var v unsafe.Pointer
		internal.TimestampArrayType(&v)
		timestampArrayType = newArrayType(v, timestampType)
	}
	{
		var v unsafe.Pointer
		internal.DateArrayType(&v)
		dateArrayType = newArrayType(v, dateType)
	}
	{
		var v unsafe.Pointer
		internal.DatetimeArrayType(&v)
		datetimeArrayType = newArrayType(v, datetimeType)
	}
	{
		var v unsafe.Pointer
		internal.TimeArrayType(&v)
		timeArrayType = newArrayType(v, timeType)
	}
	{
		var v unsafe.Pointer
		internal.IntervalArrayType(&v)
		intervalArrayType = newArrayType(v, intervalType)
	}
	{
		var v unsafe.Pointer
		internal.GeographyArrayType(&v)
		geographyArrayType = newArrayType(v, geographyType)
	}
	{
		var v unsafe.Pointer
		internal.NumericArrayType(&v)
		numericArrayType = newArrayType(v, numericType)
	}
	{
		var v unsafe.Pointer
		internal.BigNumericArrayType(&v)
		bigNumericArrayType = newArrayType(v, bigNumericType)
	}
	{
		var v unsafe.Pointer
		internal.JsonArrayType(&v)
		jsonArrayType = newArrayType(v, jsonType)
	}
	{
		var v unsafe.Pointer
		internal.DatePartEnumType(&v)
		datePartEnumType = newEnumType(v)
	}
	{
		var v unsafe.Pointer
		internal.NormalizeModeEnumType(&v)
		normalizeModeEnumType = newEnumType(v)
	}
}

func Int32Type() Type {
	return int32Type
}

func Int64Type() Type {
	return int64Type
}

func Uint32Type() Type {
	return uint32Type
}

func Uint64Type() Type {
	return uint64Type
}

func BoolType() Type {
	return boolType
}

func FloatType() Type {
	return floatType
}

func DoubleType() Type {
	return doubleType
}

func StringType() Type {
	return stringType
}

func BytesType() Type {
	return bytesType
}

func DateType() Type {
	return dateType
}

func TimestampType() Type {
	return timestampType
}

func TimeType() Type {
	return timeType
}

func DatetimeType() Type {
	return datetimeType
}

func IntervalType() Type {
	return intervalType
}

func GeographyType() Type {
	return geographyType
}

func NumericType() Type {
	return numericType
}

func BigNumericType() Type {
	return bigNumericType
}

func JsonType() Type {
	return jsonType
}

func EmptyStructType() Type {
	return structType
}

func Int32ArrayType() *ArrayType {
	return int32ArrayType
}

func Int64ArrayType() *ArrayType {
	return int64ArrayType
}

func Uint32ArrayType() *ArrayType {
	return uint32ArrayType
}

func Uint64ArrayType() *ArrayType {
	return uint64ArrayType
}

func BoolArrayType() *ArrayType {
	return boolArrayType
}

func FloatArrayType() *ArrayType {
	return floatArrayType
}

func DoubleArrayType() *ArrayType {
	return doubleArrayType
}

func StringArrayType() *ArrayType {
	return stringArrayType
}

func BytesArrayType() *ArrayType {
	return bytesArrayType
}

func TimestampArrayType() *ArrayType {
	return timestampArrayType
}

func DateArrayType() *ArrayType {
	return dateArrayType
}

func DatetimeArrayType() *ArrayType {
	return datetimeArrayType
}

func TimeArrayType() *ArrayType {
	return timeArrayType
}

func IntervalArrayType() *ArrayType {
	return intervalArrayType
}

func GeographyArrayType() *ArrayType {
	return geographyArrayType
}

func NumericArrayType() *ArrayType {
	return numericArrayType
}

func BigNumericArrayType() *ArrayType {
	return bigNumericArrayType
}

func JsonArrayType() *ArrayType {
	return jsonArrayType
}

func DatePartEnumType() *EnumType {
	return datePartEnumType
}

func NormalizeModeEnumType() *EnumType {
	return normalizeModeEnumType
}

func TypeFromKind(kind TypeKind) Type {
	return nil
}

func ArrayTypeFromKind(kind TypeKind) *ArrayType {
	return nil
}

func NewArrayType(elem Type) (*ArrayType, error) {
	return factory.createArrayType(elem)
}

func NewStructType(fields []*StructField) (*StructType, error) {
	return factory.createStructType(fields)
}

func NewStructField(name string, typ Type) *StructField {
	return &StructField{Name: name, Type: typ}
}

func TypeOf(v interface{}) Type {
	return nil
}
