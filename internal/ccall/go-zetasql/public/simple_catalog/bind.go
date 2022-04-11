package simple_catalog

/*
#cgo CXXFLAGS: -std=c++1z
#cgo CXXFLAGS: -I../../../
#cgo CXXFLAGS: -I../../../protobuf
#cgo CXXFLAGS: -I../../../gtest
#cgo CXXFLAGS: -I../../../icu
#cgo CXXFLAGS: -I../../../re2
#cgo CXXFLAGS: -I../../../json
#cgo CXXFLAGS: -I../../../googleapis
#cgo CXXFLAGS: -I../../../flex/src
#cgo CXXFLAGS: -Wno-char-subscripts
#cgo CXXFLAGS: -Wno-sign-compare
#cgo CXXFLAGS: -Wno-switch
#cgo CXXFLAGS: -Wno-unused-function
#cgo CXXFLAGS: -Wno-deprecated-declarations
#cgo CXXFLAGS: -Wno-inconsistent-missing-override
#cgo CXXFLAGS: -Wno-unknown-attributes
#cgo CXXFLAGS: -Wno-macro-redefined
#cgo CXXFLAGS: -Wno-shift-count-overflow
#cgo CXXFLAGS: -Wno-enum-compare-switch
#cgo CXXFLAGS: -Wno-return-type
#cgo CXXFLAGS: -Wno-subobject-linkage
#cgo CXXFLAGS: -Wno-unknown-warning-option
#cgo CXXFLAGS: -DHAVE_PTHREAD
#cgo CXXFLAGS: -DU_COMMON_IMPLEMENTATION

#define GO_EXPORT(API) export_zetasql_public_simple_catalog_ ## API
#include "bridge.h"
#include "../../../go-absl/time/go_internal/cctz/time_zone/bridge.h"
*/
import "C"
import (
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone"
	"unsafe"
)

func Type_Kind(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Type_Kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_Kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_Kind(arg0, arg1)
}

func Type_IsInt32(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInt32(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInt32(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsInt32(arg0, arg1)
}

func Type_IsInt64(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInt64(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInt64(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsInt64(arg0, arg1)
}

func Type_IsUint32(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsUint32(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsUint32(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsUint32(arg0, arg1)
}

func Type_IsUint64(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsUint64(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsUint64(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsUint64(arg0, arg1)
}

func Type_IsBool(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsBool(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsBool(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsBool(arg0, arg1)
}

func Type_IsFloat(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsFloat(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsFloat(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsFloat(arg0, arg1)
}

func Type_IsDouble(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsDouble(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsDouble(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsDouble(arg0, arg1)
}

func Type_IsString(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsString(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsString(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsString(arg0, arg1)
}

func Type_IsBytes(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsBytes(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsBytes(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsBytes(arg0, arg1)
}

func Type_IsDate(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsDate(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsDate(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsDate(arg0, arg1)
}

func Type_IsTimestamp(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsTimestamp(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsTimestamp(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsTimestamp(arg0, arg1)
}

func Type_IsTime(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsTime(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsTime(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsTime(arg0, arg1)
}

func Type_IsDatetime(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsDatetime(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsDatetime(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsDatetime(arg0, arg1)
}

func Type_IsInterval(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInterval(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInterval(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsInterval(arg0, arg1)
}

func Type_IsNumericType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsNumericType(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsNumericType(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsNumericType(arg0, arg1)
}

func Type_IsBigNumericType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsBigNumericType(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsBigNumericType(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsBigNumericType(arg0, arg1)
}

func Type_IsJsonType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsJsonType(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsJsonType(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsJsonType(arg0, arg1)
}

func Type_IsFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsFeatureV12CivilTimeType(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsFeatureV12CivilTimeType(arg0, arg1)
}

func Type_UsingFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_UsingFeatureV12CivilTimeType(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_UsingFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_UsingFeatureV12CivilTimeType(arg0, arg1)
}

func Type_IsCivilDateOrTimeType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsCivilDateOrTimeType(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsCivilDateOrTimeType(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsCivilDateOrTimeType(arg0, arg1)
}

func Type_IsGeography(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsGeography(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsGeography(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsGeography(arg0, arg1)
}

func Type_IsJson(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsJson(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsJson(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsJson(arg0, arg1)
}

func Type_IsEnum(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsEnum(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsEnum(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsEnum(arg0, arg1)
}

func Type_IsArray(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsArray(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsArray(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsArray(arg0, arg1)
}

func Type_IsStruct(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsStruct(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsStruct(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsStruct(arg0, arg1)
}

func Type_IsProto(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsProto(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsProto(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsProto(arg0, arg1)
}

func Type_IsStructOrProto(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsStructOrProto(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsStructOrProto(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsStructOrProto(arg0, arg1)
}

func Type_IsFloatingPoint(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsFloatingPoint(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsFloatingPoint(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsFloatingPoint(arg0, arg1)
}

func Type_IsNumerical(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsNumerical(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsNumerical(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsNumerical(arg0, arg1)
}

func Type_IsInteger(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInteger(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInteger(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsInteger(arg0, arg1)
}

func Type_IsInteger32(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInteger32(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInteger32(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsInteger32(arg0, arg1)
}

func Type_IsInteger64(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInteger64(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInteger64(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsInteger64(arg0, arg1)
}

func Type_IsSignedInteger(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsSignedInteger(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsSignedInteger(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsSignedInteger(arg0, arg1)
}

func Type_IsUnsignedInteger(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsUnsignedInteger(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsUnsignedInteger(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsUnsignedInteger(arg0, arg1)
}

func Type_IsSimpleType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsSimpleType(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsSimpleType(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsSimpleType(arg0, arg1)
}

func Type_IsExtendedType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsExtendedType(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsExtendedType(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_IsExtendedType(arg0, arg1)
}

func Type_SupportsGrouping(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_SupportsGrouping(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_SupportsGrouping(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_SupportsGrouping(arg0, arg1)
}

func Type_SupportsPartitioning(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_SupportsPartitioning(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_SupportsPartitioning(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_SupportsPartitioning(arg0, arg1)
}

func Type_SupportsOrdering(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_SupportsOrdering(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_SupportsOrdering(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_SupportsOrdering(arg0, arg1)
}

func Type_SupportsEquality(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_SupportsEquality(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_SupportsEquality(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_SupportsEquality(arg0, arg1)
}

func Type_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	simple_catalog_Type_Equals(
		arg0,
		arg1,
		(*C.int)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_Type_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_Equals(arg0, arg1, arg2)
}

func Type_Equivalent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	simple_catalog_Type_Equivalent(
		arg0,
		arg1,
		(*C.int)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_Type_Equivalent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_Equivalent(arg0, arg1, arg2)
}

func Type_ShortTypeName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Type_ShortTypeName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Type_ShortTypeName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Type_ShortTypeName(arg0, arg1, arg2)
}

func Type_TypeName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Type_TypeName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Type_TypeName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Type_TypeName(arg0, arg1, arg2)
}

func Type_TypeNameWithParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	simple_catalog_Type_TypeNameWithParameters(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
		arg4,
	)
}

func simple_catalog_Type_TypeNameWithParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Type_TypeNameWithParameters(arg0, arg1, arg2, arg3, arg4)
}

func Type_DebugString(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Type_DebugString(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Type_DebugString(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Type_DebugString(arg0, arg1, arg2)
}

func Type_HasAnyFields(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_HasAnyFields(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_HasAnyFields(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_HasAnyFields(arg0, arg1)
}

func Type_NestingDepth(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Type_NestingDepth(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_NestingDepth(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Type_NestingDepth(arg0, arg1)
}

func Type_ValidateAndResolveTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 int, arg4 *unsafe.Pointer, arg5 *unsafe.Pointer) {
	simple_catalog_Type_ValidateAndResolveTypeParameters(
		arg0,
		arg1,
		C.int(arg2),
		C.int(arg3),
		arg4,
		arg5,
	)
}

func simple_catalog_Type_ValidateAndResolveTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 C.int, arg4 *unsafe.Pointer, arg5 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Type_ValidateAndResolveTypeParameters(arg0, arg1, arg2, arg3, arg4, arg5)
}

func Type_ValidateResolvedTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	simple_catalog_Type_ValidateResolvedTypeParameters(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func simple_catalog_Type_ValidateResolvedTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Type_ValidateResolvedTypeParameters(arg0, arg1, arg2, arg3)
}

func TypeFactory_MakeArrayType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_TypeFactory_MakeArrayType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_TypeFactory_MakeArrayType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TypeFactory_MakeArrayType(arg0, arg1, arg2, arg3)
}

func TypeFactory_MakeStructType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	simple_catalog_TypeFactory_MakeStructType(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
		arg4,
	)
}

func simple_catalog_TypeFactory_MakeStructType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TypeFactory_MakeStructType(arg0, arg1, arg2, arg3, arg4)
}

func Int32Type(arg0 *unsafe.Pointer) {
	simple_catalog_Int32Type(
		arg0,
	)
}

func simple_catalog_Int32Type(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Int32Type(arg0)
}

func Int64Type(arg0 *unsafe.Pointer) {
	simple_catalog_Int64Type(
		arg0,
	)
}

func simple_catalog_Int64Type(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Int64Type(arg0)
}

func Uint32Type(arg0 *unsafe.Pointer) {
	simple_catalog_Uint32Type(
		arg0,
	)
}

func simple_catalog_Uint32Type(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Uint32Type(arg0)
}

func Uint64Type(arg0 *unsafe.Pointer) {
	simple_catalog_Uint64Type(
		arg0,
	)
}

func simple_catalog_Uint64Type(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Uint64Type(arg0)
}

func BoolType(arg0 *unsafe.Pointer) {
	simple_catalog_BoolType(
		arg0,
	)
}

func simple_catalog_BoolType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_BoolType(arg0)
}

func FloatType(arg0 *unsafe.Pointer) {
	simple_catalog_FloatType(
		arg0,
	)
}

func simple_catalog_FloatType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FloatType(arg0)
}

func DoubleType(arg0 *unsafe.Pointer) {
	simple_catalog_DoubleType(
		arg0,
	)
}

func simple_catalog_DoubleType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_DoubleType(arg0)
}

func StringType(arg0 *unsafe.Pointer) {
	simple_catalog_StringType(
		arg0,
	)
}

func simple_catalog_StringType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_StringType(arg0)
}

func BytesType(arg0 *unsafe.Pointer) {
	simple_catalog_BytesType(
		arg0,
	)
}

func simple_catalog_BytesType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_BytesType(arg0)
}

func DateType(arg0 *unsafe.Pointer) {
	simple_catalog_DateType(
		arg0,
	)
}

func simple_catalog_DateType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_DateType(arg0)
}

func TimestampType(arg0 *unsafe.Pointer) {
	simple_catalog_TimestampType(
		arg0,
	)
}

func simple_catalog_TimestampType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TimestampType(arg0)
}

func TimeType(arg0 *unsafe.Pointer) {
	simple_catalog_TimeType(
		arg0,
	)
}

func simple_catalog_TimeType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TimeType(arg0)
}

func DatetimeType(arg0 *unsafe.Pointer) {
	simple_catalog_DatetimeType(
		arg0,
	)
}

func simple_catalog_DatetimeType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_DatetimeType(arg0)
}

func IntervalType(arg0 *unsafe.Pointer) {
	simple_catalog_IntervalType(
		arg0,
	)
}

func simple_catalog_IntervalType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_IntervalType(arg0)
}

func GeographyType(arg0 *unsafe.Pointer) {
	simple_catalog_GeographyType(
		arg0,
	)
}

func simple_catalog_GeographyType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_GeographyType(arg0)
}

func NumericType(arg0 *unsafe.Pointer) {
	simple_catalog_NumericType(
		arg0,
	)
}

func simple_catalog_NumericType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_NumericType(arg0)
}

func BigNumericType(arg0 *unsafe.Pointer) {
	simple_catalog_BigNumericType(
		arg0,
	)
}

func simple_catalog_BigNumericType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_BigNumericType(arg0)
}

func JsonType(arg0 *unsafe.Pointer) {
	simple_catalog_JsonType(
		arg0,
	)
}

func simple_catalog_JsonType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_JsonType(arg0)
}

func EmptyStructType(arg0 *unsafe.Pointer) {
	simple_catalog_EmptyStructType(
		arg0,
	)
}

func simple_catalog_EmptyStructType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_EmptyStructType(arg0)
}

func Int32ArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_Int32ArrayType(
		arg0,
	)
}

func simple_catalog_Int32ArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Int32ArrayType(arg0)
}

func Int64ArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_Int64ArrayType(
		arg0,
	)
}

func simple_catalog_Int64ArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Int64ArrayType(arg0)
}

func Uint32ArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_Uint32ArrayType(
		arg0,
	)
}

func simple_catalog_Uint32ArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Uint32ArrayType(arg0)
}

func Uint64ArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_Uint64ArrayType(
		arg0,
	)
}

func simple_catalog_Uint64ArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Uint64ArrayType(arg0)
}

func BoolArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_BoolArrayType(
		arg0,
	)
}

func simple_catalog_BoolArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_BoolArrayType(arg0)
}

func FloatArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_FloatArrayType(
		arg0,
	)
}

func simple_catalog_FloatArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FloatArrayType(arg0)
}

func DoubleArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_DoubleArrayType(
		arg0,
	)
}

func simple_catalog_DoubleArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_DoubleArrayType(arg0)
}

func StringArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_StringArrayType(
		arg0,
	)
}

func simple_catalog_StringArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_StringArrayType(arg0)
}

func BytesArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_BytesArrayType(
		arg0,
	)
}

func simple_catalog_BytesArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_BytesArrayType(arg0)
}

func TimestampArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_TimestampArrayType(
		arg0,
	)
}

func simple_catalog_TimestampArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TimestampArrayType(arg0)
}

func DateArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_DateArrayType(
		arg0,
	)
}

func simple_catalog_DateArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_DateArrayType(arg0)
}

func DatetimeArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_DatetimeArrayType(
		arg0,
	)
}

func simple_catalog_DatetimeArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_DatetimeArrayType(arg0)
}

func TimeArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_TimeArrayType(
		arg0,
	)
}

func simple_catalog_TimeArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TimeArrayType(arg0)
}

func IntervalArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_IntervalArrayType(
		arg0,
	)
}

func simple_catalog_IntervalArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_IntervalArrayType(arg0)
}

func GeographyArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_GeographyArrayType(
		arg0,
	)
}

func simple_catalog_GeographyArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_GeographyArrayType(arg0)
}

func NumericArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_NumericArrayType(
		arg0,
	)
}

func simple_catalog_NumericArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_NumericArrayType(arg0)
}

func BigNumericArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_BigNumericArrayType(
		arg0,
	)
}

func simple_catalog_BigNumericArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_BigNumericArrayType(arg0)
}

func JsonArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_JsonArrayType(
		arg0,
	)
}

func simple_catalog_JsonArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_JsonArrayType(arg0)
}

func DatePartEnumType(arg0 *unsafe.Pointer) {
	simple_catalog_DatePartEnumType(
		arg0,
	)
}

func simple_catalog_DatePartEnumType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_DatePartEnumType(arg0)
}

func NormalizeModeEnumType(arg0 *unsafe.Pointer) {
	simple_catalog_NormalizeModeEnumType(
		arg0,
	)
}

func simple_catalog_NormalizeModeEnumType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_NormalizeModeEnumType(arg0)
}

func Column_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Column_Name(
		arg0,
		arg1,
	)
}

func simple_catalog_Column_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Column_Name(arg0, arg1)
}

func Column_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Column_FullName(
		arg0,
		arg1,
	)
}

func simple_catalog_Column_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Column_FullName(arg0, arg1)
}

func Column_Type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Column_Type(
		arg0,
		arg1,
	)
}

func simple_catalog_Column_Type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Column_Type(arg0, arg1)
}

func Column_IsPseudoColumn(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Column_IsPseudoColumn(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Column_IsPseudoColumn(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Column_IsPseudoColumn(arg0, arg1)
}

func Column_IsWritableColumn(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Column_IsWritableColumn(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Column_IsWritableColumn(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Column_IsWritableColumn(arg0, arg1)
}

func SimpleColumn_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleColumn_new(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleColumn_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleColumn_new(arg0, arg1, arg2, arg3)
}

func SimpleColumn_new_with_opt(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 int, arg4 int, arg5 *unsafe.Pointer) {
	simple_catalog_SimpleColumn_new_with_opt(
		arg0,
		arg1,
		arg2,
		C.int(arg3),
		C.int(arg4),
		arg5,
	)
}

func simple_catalog_SimpleColumn_new_with_opt(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 C.int, arg4 C.int, arg5 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleColumn_new_with_opt(arg0, arg1, arg2, arg3, arg4, arg5)
}

func SimpleColumn_AnnotatedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleColumn_AnnotatedType(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleColumn_AnnotatedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleColumn_AnnotatedType(arg0, arg1)
}

func SimpleColumn_SetIsPseudoColumn(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_SimpleColumn_SetIsPseudoColumn(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_SimpleColumn_SetIsPseudoColumn(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_SimpleColumn_SetIsPseudoColumn(arg0, arg1)
}

func Table_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Table_Name(
		arg0,
		arg1,
	)
}

func simple_catalog_Table_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Table_Name(arg0, arg1)
}

func Table_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Table_FullName(
		arg0,
		arg1,
	)
}

func simple_catalog_Table_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Table_FullName(arg0, arg1)
}

func Table_NumColumns(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Table_NumColumns(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Table_NumColumns(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Table_NumColumns(arg0, arg1)
}

func Table_Column(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Table_Column(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Table_Column(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Table_Column(arg0, arg1, arg2)
}

func Table_PrimaryKey_num(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Table_PrimaryKey_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Table_PrimaryKey_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Table_PrimaryKey_num(arg0, arg1)
}

func Table_PrimaryKey(arg0 unsafe.Pointer, arg1 int, arg2 *int) {
	simple_catalog_Table_PrimaryKey(
		arg0,
		C.int(arg1),
		(*C.int)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_Table_PrimaryKey(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.int) {
	C.export_zetasql_public_simple_catalog_Table_PrimaryKey(arg0, arg1, arg2)
}

func Table_FindColumnByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Table_FindColumnByName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Table_FindColumnByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Table_FindColumnByName(arg0, arg1, arg2)
}

func Table_IsValueTable(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Table_IsValueTable(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Table_IsValueTable(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Table_IsValueTable(arg0, arg1)
}

func Table_GetSerializationId(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Table_GetSerializationId(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Table_GetSerializationId(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Table_GetSerializationId(arg0, arg1)
}

func Table_CreateEvaluatorTableIterator(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	simple_catalog_Table_CreateEvaluatorTableIterator(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
		arg4,
	)
}

func simple_catalog_Table_CreateEvaluatorTableIterator(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Table_CreateEvaluatorTableIterator(arg0, arg1, arg2, arg3, arg4)
}

func Table_GetAnonymizationInfo(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Table_GetAnonymizationInfo(
		arg0,
		arg1,
	)
}

func simple_catalog_Table_GetAnonymizationInfo(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Table_GetAnonymizationInfo(arg0, arg1)
}

func Table_SupportsAnonymization(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Table_SupportsAnonymization(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Table_SupportsAnonymization(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Table_SupportsAnonymization(arg0, arg1)
}

func Table_GetTableTypeName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Table_GetTableTypeName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Table_GetTableTypeName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Table_GetTableTypeName(arg0, arg1, arg2)
}

func SimpleTable_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleTable_new(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func simple_catalog_SimpleTable_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleTable_new(arg0, arg1, arg2, arg3)
}

func SimpleTable_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_SimpleTable_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_SimpleTable_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_SimpleTable_set_is_value_table(arg0, arg1)
}

func SimpleTable_AllowAnonymousColumnName(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_SimpleTable_AllowAnonymousColumnName(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_SimpleTable_AllowAnonymousColumnName(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_SimpleTable_AllowAnonymousColumnName(arg0, arg1)
}

func SimpleTable_set_allow_anonymous_column_name(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleTable_set_allow_anonymous_column_name(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_SimpleTable_set_allow_anonymous_column_name(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleTable_set_allow_anonymous_column_name(arg0, arg1, arg2)
}

func SimpleTable_AllowDuplicateColumnNames(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_SimpleTable_AllowDuplicateColumnNames(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_SimpleTable_AllowDuplicateColumnNames(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_SimpleTable_AllowDuplicateColumnNames(arg0, arg1)
}

func SimpleTable_set_allow_duplicate_column_names(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleTable_set_allow_duplicate_column_names(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_SimpleTable_set_allow_duplicate_column_names(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleTable_set_allow_duplicate_column_names(arg0, arg1, arg2)
}

func SimpleTable_AddColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleTable_AddColumn(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleTable_AddColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleTable_AddColumn(arg0, arg1, arg2)
}

func SimpleTable_SetPrimaryKey(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleTable_SetPrimaryKey(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func simple_catalog_SimpleTable_SetPrimaryKey(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleTable_SetPrimaryKey(arg0, arg1, arg2, arg3)
}

func SimpleTable_set_full_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleTable_set_full_name(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleTable_set_full_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleTable_set_full_name(arg0, arg1, arg2)
}

func SimpleTable_SetAnonymizationInfo(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleTable_SetAnonymizationInfo(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleTable_SetAnonymizationInfo(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleTable_SetAnonymizationInfo(arg0, arg1, arg2)
}

func SimpleTable_ResetAnonymizationInfo(arg0 unsafe.Pointer) {
	simple_catalog_SimpleTable_ResetAnonymizationInfo(
		arg0,
	)
}

func simple_catalog_SimpleTable_ResetAnonymizationInfo(arg0 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleTable_ResetAnonymizationInfo(arg0)
}

func Catalog_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Catalog_FullName(
		arg0,
		arg1,
	)
}

func simple_catalog_Catalog_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Catalog_FullName(arg0, arg1)
}

func Catalog_FindTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_Catalog_FindTable(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_Catalog_FindTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Catalog_FindTable(arg0, arg1, arg2, arg3)
}

func Catalog_FindType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_Catalog_FindType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_Catalog_FindType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Catalog_FindType(arg0, arg1, arg2, arg3)
}

func Catalog_SuggestTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Catalog_SuggestTable(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Catalog_SuggestTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Catalog_SuggestTable(arg0, arg1, arg2)
}

func EnumerableCatalog_Catalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_EnumerableCatalog_Catalogs(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_EnumerableCatalog_Catalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_EnumerableCatalog_Catalogs(arg0, arg1, arg2)
}

func EnumerableCatalog_Tables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_EnumerableCatalog_Tables(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_EnumerableCatalog_Tables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_EnumerableCatalog_Tables(arg0, arg1, arg2)
}

func EnumerableCatalog_Types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_EnumerableCatalog_Types(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_EnumerableCatalog_Types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_EnumerableCatalog_Types(arg0, arg1, arg2)
}

func SimpleCatalog_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_new(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_new(arg0, arg1)
}

func SimpleCatalog_GetTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetTable(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleCatalog_GetTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_GetTable(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetTables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetTables(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_GetTables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_GetTables(arg0, arg1, arg2)
}

func SimpleCatalog_table_names_num(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_SimpleCatalog_table_names_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_SimpleCatalog_table_names_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_table_names_num(arg0, arg1)
}

func SimpleCatalog_table_name(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_table_name(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_SimpleCatalog_table_name(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_table_name(arg0, arg1, arg2)
}

func SimpleCatalog_GetType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleCatalog_GetType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_GetType(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetTypes(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetTypes(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_GetTypes(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_GetTypes(arg0, arg1, arg2)
}

func SimpleCatalog_GetCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetCatalog(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleCatalog_GetCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_GetCatalog(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetCatalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetCatalogs(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_GetCatalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_GetCatalogs(arg0, arg1, arg2)
}

func SimpleCatalog_catalog_names_num(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_SimpleCatalog_catalog_names_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_SimpleCatalog_catalog_names_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_catalog_names_num(arg0, arg1)
}

func SimpleCatalog_catalog_name(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_catalog_name(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_SimpleCatalog_catalog_name(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_catalog_name(arg0, arg1, arg2)
}

func SimpleCatalog_AddTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddTable(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddTable(arg0, arg1)
}

func SimpleCatalog_AddTableWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddTableWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddTableWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddTableWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddType(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddType(arg0, arg1, arg2)
}

func SimpleCatalog_AddTypeIfNotPresent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	simple_catalog_SimpleCatalog_AddTypeIfNotPresent(
		arg0,
		arg1,
		arg2,
		(*C.int)(unsafe.Pointer(arg3)),
	)
}

func simple_catalog_SimpleCatalog_AddTypeIfNotPresent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.int) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddTypeIfNotPresent(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_AddCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddCatalog(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddCatalog(arg0, arg1)
}

func SimpleCatalog_AddCatalogWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddCatalogWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddCatalogWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddCatalogWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddZetaSQLFunctions(arg0 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddZetaSQLFunctions(
		arg0,
	)
}

func simple_catalog_SimpleCatalog_AddZetaSQLFunctions(arg0 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddZetaSQLFunctions(arg0)
}

//export export_zetasql_public_simple_catalog_cctz_FixedOffsetFromName
//go:linkname export_zetasql_public_simple_catalog_cctz_FixedOffsetFromName github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetFromName
func export_zetasql_public_simple_catalog_cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int)

//export export_zetasql_public_simple_catalog_cctz_FixedOffsetToName
//go:linkname export_zetasql_public_simple_catalog_cctz_FixedOffsetToName github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToName
func export_zetasql_public_simple_catalog_cctz_FixedOffsetToName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_cctz_FixedOffsetToAbbr
//go:linkname export_zetasql_public_simple_catalog_cctz_FixedOffsetToAbbr github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToAbbr
func export_zetasql_public_simple_catalog_cctz_FixedOffsetToAbbr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_cctz_detail_format
//go:linkname export_zetasql_public_simple_catalog_cctz_detail_format github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_format
func export_zetasql_public_simple_catalog_cctz_detail_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_cctz_detail_parse
//go:linkname export_zetasql_public_simple_catalog_cctz_detail_parse github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_parse
func export_zetasql_public_simple_catalog_cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *C.int)

//export export_zetasql_public_simple_catalog_TimeZoneIf_Load
//go:linkname export_zetasql_public_simple_catalog_TimeZoneIf_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneIf_Load
func export_zetasql_public_simple_catalog_TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_time_zone_Impl_UTC
//go:linkname export_zetasql_public_simple_catalog_time_zone_Impl_UTC github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTC
func export_zetasql_public_simple_catalog_time_zone_Impl_UTC(arg0 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_time_zone_Impl_LoadTimeZone
//go:linkname export_zetasql_public_simple_catalog_time_zone_Impl_LoadTimeZone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_LoadTimeZone
func export_zetasql_public_simple_catalog_time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int)

//export export_zetasql_public_simple_catalog_time_zone_Impl_ClearTimeZoneMapTestOnly
//go:linkname export_zetasql_public_simple_catalog_time_zone_Impl_ClearTimeZoneMapTestOnly github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_ClearTimeZoneMapTestOnly
func export_zetasql_public_simple_catalog_time_zone_Impl_ClearTimeZoneMapTestOnly()

//export export_zetasql_public_simple_catalog_time_zone_Impl_UTCImpl
//go:linkname export_zetasql_public_simple_catalog_time_zone_Impl_UTCImpl github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTCImpl
func export_zetasql_public_simple_catalog_time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_TimeZoneInfo_Load
//go:linkname export_zetasql_public_simple_catalog_TimeZoneInfo_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Load
func export_zetasql_public_simple_catalog_TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int)

//export export_zetasql_public_simple_catalog_TimeZoneInfo_BreakTime
//go:linkname export_zetasql_public_simple_catalog_TimeZoneInfo_BreakTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_BreakTime
func export_zetasql_public_simple_catalog_TimeZoneInfo_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_TimeZoneInfo_MakeTime
//go:linkname export_zetasql_public_simple_catalog_TimeZoneInfo_MakeTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_MakeTime
func export_zetasql_public_simple_catalog_TimeZoneInfo_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_TimeZoneInfo_Version
//go:linkname export_zetasql_public_simple_catalog_TimeZoneInfo_Version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Version
func export_zetasql_public_simple_catalog_TimeZoneInfo_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_TimeZoneInfo_Description
//go:linkname export_zetasql_public_simple_catalog_TimeZoneInfo_Description github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Description
func export_zetasql_public_simple_catalog_TimeZoneInfo_Description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_TimeZoneInfo_NextTransition
//go:linkname export_zetasql_public_simple_catalog_TimeZoneInfo_NextTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_NextTransition
func export_zetasql_public_simple_catalog_TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.int)

//export export_zetasql_public_simple_catalog_TimeZoneInfo_PrevTransition
//go:linkname export_zetasql_public_simple_catalog_TimeZoneInfo_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_PrevTransition
func export_zetasql_public_simple_catalog_TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.int)

//export export_zetasql_public_simple_catalog_TimeZoneLibC_BreakTime
//go:linkname export_zetasql_public_simple_catalog_TimeZoneLibC_BreakTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_BreakTime
func export_zetasql_public_simple_catalog_TimeZoneLibC_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_TimeZoneLibC_MakeTime
//go:linkname export_zetasql_public_simple_catalog_TimeZoneLibC_MakeTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_MakeTime
func export_zetasql_public_simple_catalog_TimeZoneLibC_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_TimeZoneLibC_Version
//go:linkname export_zetasql_public_simple_catalog_TimeZoneLibC_Version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_Version
func export_zetasql_public_simple_catalog_TimeZoneLibC_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_TimeZoneLibC_NextTransition
//go:linkname export_zetasql_public_simple_catalog_TimeZoneLibC_NextTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_NextTransition
func export_zetasql_public_simple_catalog_TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.int)

//export export_zetasql_public_simple_catalog_TimeZoneLibC_PrevTransition
//go:linkname export_zetasql_public_simple_catalog_TimeZoneLibC_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_PrevTransition
func export_zetasql_public_simple_catalog_TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.int)

//export export_zetasql_public_simple_catalog_time_zone_name
//go:linkname export_zetasql_public_simple_catalog_time_zone_name github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_name
func export_zetasql_public_simple_catalog_time_zone_name(arg0 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_time_zone_lookup
//go:linkname export_zetasql_public_simple_catalog_time_zone_lookup github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup
func export_zetasql_public_simple_catalog_time_zone_lookup(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_time_zone_lookup2
//go:linkname export_zetasql_public_simple_catalog_time_zone_lookup2 github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup2
func export_zetasql_public_simple_catalog_time_zone_lookup2(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_time_zone_next_transition
//go:linkname export_zetasql_public_simple_catalog_time_zone_next_transition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_next_transition
func export_zetasql_public_simple_catalog_time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int)

//export export_zetasql_public_simple_catalog_time_zone_prev_transition
//go:linkname export_zetasql_public_simple_catalog_time_zone_prev_transition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_prev_transition
func export_zetasql_public_simple_catalog_time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int)

//export export_zetasql_public_simple_catalog_time_zone_version
//go:linkname export_zetasql_public_simple_catalog_time_zone_version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_version
func export_zetasql_public_simple_catalog_time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_time_zone_description
//go:linkname export_zetasql_public_simple_catalog_time_zone_description github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_description
func export_zetasql_public_simple_catalog_time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_cctz_load_time_zone
//go:linkname export_zetasql_public_simple_catalog_cctz_load_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_load_time_zone
func export_zetasql_public_simple_catalog_cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int)

//export export_zetasql_public_simple_catalog_cctz_utc_time_zone
//go:linkname export_zetasql_public_simple_catalog_cctz_utc_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_utc_time_zone
func export_zetasql_public_simple_catalog_cctz_utc_time_zone(arg0 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_cctz_fixed_time_zone
//go:linkname export_zetasql_public_simple_catalog_cctz_fixed_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_fixed_time_zone
func export_zetasql_public_simple_catalog_cctz_fixed_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_cctz_local_time_zone
//go:linkname export_zetasql_public_simple_catalog_cctz_local_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_local_time_zone
func export_zetasql_public_simple_catalog_cctz_local_time_zone(arg0 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_cctz_ParsePosixSpec
//go:linkname export_zetasql_public_simple_catalog_cctz_ParsePosixSpec github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_ParsePosixSpec
func export_zetasql_public_simple_catalog_cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int)
