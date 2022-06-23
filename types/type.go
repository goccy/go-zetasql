package types

import (
	"reflect"
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
)

type TypeList []Type
type TypeListView = TypeList

type AnonymizationInfo struct {
	raw unsafe.Pointer
}

//go:noinline
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

// AnnotatedType holds unowned pointers to Type and AnnoationMap.
// <annotation_map> could be nil to indicate that the <type> doesn't have annotation.
type AnnotatedType struct {
	raw unsafe.Pointer
}

func (t *AnnotatedType) Type() Type {
	return nil
}

func (t *AnnotatedType) AnnotationMap() AnnotationMap {
	return nil
}

//go:noinline
func newAnnotatedType(raw unsafe.Pointer) *AnnotatedType {
	if raw == nil {
		return nil
	}
	return &AnnotatedType{raw: raw}
}

func getRawAnnotatedType(v *AnnotatedType) unsafe.Pointer {
	return v.raw
}

type TypeKind int

const (
	UNKNOWN     TypeKind = 0
	INT32                = 1
	INT64                = 2
	UINT32               = 3
	UINT64               = 4
	BOOL                 = 5
	FLOAT                = 6
	DOUBLE               = 7
	STRING               = 8
	BYTES                = 9
	DATE                 = 10
	TIMESTAMP            = 19
	ENUM                 = 15
	ARRAY                = 16
	STRUCT               = 17
	PROTO                = 18
	TIME                 = 20
	DATETIME             = 21
	GEOGRAPHY            = 22
	NUMERIC              = 23
	BIG_NUMERIC          = 24
	EXTENDED             = 25
	JSON                 = 26
	INTERVAL             = 27
)

func (k TypeKind) String() string {
	switch k {
	case UNKNOWN:
		return "UNKNOWN"
	case INT32:
		return "INT32"
	case INT64:
		return "INT64"
	case UINT32:
		return "UINT32"
	case UINT64:
		return "UINT64"
	case BOOL:
		return "BOOL"
	case FLOAT:
		return "FLOAT"
	case DOUBLE:
		return "DOUBLE"
	case STRING:
		return "STRING"
	case BYTES:
		return "BYTES"
	case DATE:
		return "DATE"
	case TIMESTAMP:
		return "TIMESTAMP"
	case ENUM:
		return "ENUM"
	case ARRAY:
		return "ARRAY"
	case STRUCT:
		return "STRUCT"
	case PROTO:
		return "PROTO"
	case TIME:
		return "TIME"
	case DATETIME:
		return "DATETIME"
	case GEOGRAPHY:
		return "GEOGRAPHY"
	case NUMERIC:
		return "NUMERIC"
	case BIG_NUMERIC:
		return "BIGNUMERIC"
	case EXTENDED:
		return "EXTENDED"
	case JSON:
		return "JSON"
	case INTERVAL:
		return "INTERVAL"
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
	AsArray() *ArrayType
	AsStruct() *StructType
	AsEnum() *EnumType
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

var _ Type = &ztype{}

//go:noinline
func newType(v unsafe.Pointer) Type {
	if v == nil {
		return nil
	}
	return &ztype{raw: v}
}

func getRawType(v Type) unsafe.Pointer {
	return v.getRaw()
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

func (t *ztype) AsArray() *ArrayType {
	var v unsafe.Pointer
	internal.Type_AsArray(t.raw, &v)
	if v == nil {
		return nil
	}
	return newArrayType(v)
}

func (t *ztype) AsStruct() *StructType {
	var v unsafe.Pointer
	internal.Type_AsStruct(t.raw, &v)
	if v == nil {
		return nil
	}
	return newStructType(v)
}

func (t *ztype) AsEnum() *EnumType {
	var v unsafe.Pointer
	internal.Type_AsEnum(t.raw, &v)
	return &EnumType{
		ztype: &ztype{raw: v},
	}
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
	st := helper.NewStatus(status)
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
	st := helper.NewStatus(status)
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
	st := helper.NewStatus(status)
	if !st.OK() {
		return st.Error()
	}
	return nil
}

//go:noinline
func newTypeParameters(raw unsafe.Pointer) *TypeParameters {
	return &TypeParameters{raw: raw}
}

func getRawTypeParameters(v *TypeParameters) unsafe.Pointer {
	return v.raw
}

type StructType struct {
	*ztype
}

type StructField struct {
	raw unsafe.Pointer
}

func NewStructField(name string, typ Type) *StructField {
	var v unsafe.Pointer
	internal.StructField_new(helper.StringToPtr(name), typ.getRaw(), &v)
	return newStructField(v)
}

func (f *StructField) Name() string {
	var v unsafe.Pointer
	internal.StructField_name(f.raw, &v)
	return helper.PtrToString(v)
}

func (f *StructField) Type() Type {
	var v unsafe.Pointer
	internal.StructField_type(f.raw, &v)
	return newType(v)
}

//go:noinline
func newStructField(p unsafe.Pointer) *StructField {
	if p == nil {
		return nil
	}
	return &StructField{raw: p}
}

func (t *StructType) NumFields() int {
	var v int
	internal.StructType_num_fields(t.raw, &v)
	return v
}

func (t *StructType) Field(i int) *StructField {
	var v unsafe.Pointer
	internal.StructType_field(t.raw, i, &v)
	return newStructField(v)
}

func (t *StructType) Fields() []*StructField {
	var v unsafe.Pointer
	internal.StructType_fields(t.raw, &v)
	ret := []*StructField{}
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newStructField(p))
	})
	return ret
}

type ArrayType struct {
	*ztype
}

func (t *ArrayType) ElementType() Type {
	var v unsafe.Pointer
	internal.ArrayType_element_type(t.raw, &v)
	return newType(v)
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
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newArrayType(v), nil
}

func (f *typeFactory) createStructType(fields []*StructField) (*StructType, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.TypeFactory_MakeStructType(f.raw, helper.SliceToPtr(fields, func(idx int) unsafe.Pointer {
		return fields[idx].raw
	}), &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newStructType(v), nil
}

//go:noinline
func newStructType(raw unsafe.Pointer) *StructType {
	if raw == nil {
		return nil
	}
	return &StructType{ztype: &ztype{raw: raw}}
}

//go:noinline
func newArrayType(raw unsafe.Pointer) *ArrayType {
	if raw == nil {
		return nil
	}
	return &ArrayType{ztype: &ztype{raw: raw}}
}

//go:noinline
func newEnumType(raw unsafe.Pointer) *EnumType {
	if raw == nil {
		return nil
	}
	return &EnumType{ztype: &ztype{raw: raw}}
}

//go:noinline
func newFactory() *typeFactory {
	var v unsafe.Pointer
	internal.TypeFactory_new(&v)
	return &typeFactory{raw: v}
}

func init() {
	factory = newFactory()
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
		int32ArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.Int64ArrayType(&v)
		int64ArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.Uint32ArrayType(&v)
		uint32ArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.Uint64ArrayType(&v)
		uint64ArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.BoolArrayType(&v)
		boolArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.FloatArrayType(&v)
		floatArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.DoubleArrayType(&v)
		doubleArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.StringArrayType(&v)
		stringArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.BytesArrayType(&v)
		bytesArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.TimestampArrayType(&v)
		timestampArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.DateArrayType(&v)
		dateArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.DatetimeArrayType(&v)
		datetimeArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.TimeArrayType(&v)
		timeArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.IntervalArrayType(&v)
		intervalArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.GeographyArrayType(&v)
		geographyArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.NumericArrayType(&v)
		numericArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.BigNumericArrayType(&v)
		bigNumericArrayType = newArrayType(v)
	}
	{
		var v unsafe.Pointer
		internal.JsonArrayType(&v)
		jsonArrayType = newArrayType(v)
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
	var v unsafe.Pointer
	internal.TypeFromSimpleTypeKind(int(kind), &v)
	return newType(v)
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

func TypeOf(v interface{}) Type {
	return nil
}
