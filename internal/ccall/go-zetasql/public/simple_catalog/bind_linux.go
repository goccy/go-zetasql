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
#cgo CXXFLAGS: -Wno-final-dtor-non-final-class
#cgo CXXFLAGS: -Wno-implicit-const-int-float-conversion
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
#cgo LDFLAGS: -ldl

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
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInt32(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsInt32(arg0, arg1)
}

func Type_IsInt64(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInt64(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInt64(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsInt64(arg0, arg1)
}

func Type_IsUint32(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsUint32(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsUint32(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsUint32(arg0, arg1)
}

func Type_IsUint64(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsUint64(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsUint64(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsUint64(arg0, arg1)
}

func Type_IsBool(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsBool(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsBool(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsBool(arg0, arg1)
}

func Type_IsFloat(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsFloat(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsFloat(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsFloat(arg0, arg1)
}

func Type_IsDouble(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsDouble(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsDouble(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsDouble(arg0, arg1)
}

func Type_IsString(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsString(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsString(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsString(arg0, arg1)
}

func Type_IsBytes(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsBytes(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsBytes(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsBytes(arg0, arg1)
}

func Type_IsDate(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsDate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsDate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsDate(arg0, arg1)
}

func Type_IsTimestamp(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsTimestamp(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsTimestamp(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsTimestamp(arg0, arg1)
}

func Type_IsTime(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsTime(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsTime(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsTime(arg0, arg1)
}

func Type_IsDatetime(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsDatetime(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsDatetime(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsDatetime(arg0, arg1)
}

func Type_IsInterval(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInterval(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInterval(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsInterval(arg0, arg1)
}

func Type_IsNumericType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsNumericType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsNumericType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsNumericType(arg0, arg1)
}

func Type_IsBigNumericType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsBigNumericType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsBigNumericType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsBigNumericType(arg0, arg1)
}

func Type_IsJsonType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsJsonType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsJsonType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsJsonType(arg0, arg1)
}

func Type_IsFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsFeatureV12CivilTimeType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsFeatureV12CivilTimeType(arg0, arg1)
}

func Type_UsingFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_UsingFeatureV12CivilTimeType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_UsingFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_UsingFeatureV12CivilTimeType(arg0, arg1)
}

func Type_IsCivilDateOrTimeType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsCivilDateOrTimeType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsCivilDateOrTimeType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsCivilDateOrTimeType(arg0, arg1)
}

func Type_IsGeography(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsGeography(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsGeography(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsGeography(arg0, arg1)
}

func Type_IsJson(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsJson(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsJson(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsJson(arg0, arg1)
}

func Type_IsEnum(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsEnum(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsEnum(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsEnum(arg0, arg1)
}

func Type_IsArray(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsArray(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsArray(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsArray(arg0, arg1)
}

func Type_IsStruct(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsStruct(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsStruct(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsStruct(arg0, arg1)
}

func Type_IsProto(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsProto(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsProto(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsProto(arg0, arg1)
}

func Type_IsStructOrProto(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsStructOrProto(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsStructOrProto(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsStructOrProto(arg0, arg1)
}

func Type_IsFloatingPoint(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsFloatingPoint(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsFloatingPoint(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsFloatingPoint(arg0, arg1)
}

func Type_IsNumerical(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsNumerical(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsNumerical(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsNumerical(arg0, arg1)
}

func Type_IsInteger(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInteger(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInteger(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsInteger(arg0, arg1)
}

func Type_IsInteger32(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInteger32(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInteger32(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsInteger32(arg0, arg1)
}

func Type_IsInteger64(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInteger64(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInteger64(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsInteger64(arg0, arg1)
}

func Type_IsSignedInteger(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsSignedInteger(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsSignedInteger(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsSignedInteger(arg0, arg1)
}

func Type_IsUnsignedInteger(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsUnsignedInteger(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsUnsignedInteger(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsUnsignedInteger(arg0, arg1)
}

func Type_IsSimpleType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsSimpleType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsSimpleType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsSimpleType(arg0, arg1)
}

func Type_IsExtendedType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsExtendedType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsExtendedType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_IsExtendedType(arg0, arg1)
}

func Type_AsArray(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Type_AsArray(
		arg0,
		arg1,
	)
}

func simple_catalog_Type_AsArray(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Type_AsArray(arg0, arg1)
}

func Type_AsStruct(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Type_AsStruct(
		arg0,
		arg1,
	)
}

func simple_catalog_Type_AsStruct(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Type_AsStruct(arg0, arg1)
}

func Type_AsProto(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Type_AsProto(
		arg0,
		arg1,
	)
}

func simple_catalog_Type_AsProto(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Type_AsProto(arg0, arg1)
}

func Type_AsEnum(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Type_AsEnum(
		arg0,
		arg1,
	)
}

func simple_catalog_Type_AsEnum(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Type_AsEnum(arg0, arg1)
}

func Type_AsExtendedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Type_AsExtendedType(
		arg0,
		arg1,
	)
}

func simple_catalog_Type_AsExtendedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Type_AsExtendedType(arg0, arg1)
}

func Type_SupportsGrouping(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_SupportsGrouping(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_SupportsGrouping(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_SupportsGrouping(arg0, arg1)
}

func Type_SupportsPartitioning(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_SupportsPartitioning(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_SupportsPartitioning(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_SupportsPartitioning(arg0, arg1)
}

func Type_SupportsOrdering(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_SupportsOrdering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_SupportsOrdering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_SupportsOrdering(arg0, arg1)
}

func Type_SupportsEquality(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_SupportsEquality(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_SupportsEquality(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_SupportsEquality(arg0, arg1)
}

func Type_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	simple_catalog_Type_Equals(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_Type_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_public_simple_catalog_Type_Equals(arg0, arg1, arg2)
}

func Type_Equivalent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	simple_catalog_Type_Equivalent(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_Type_Equivalent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
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
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_HasAnyFields(arg0 unsafe.Pointer, arg1 *C.char) {
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

func ArrayType_element_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_ArrayType_element_type(
		arg0,
		arg1,
	)
}

func simple_catalog_ArrayType_element_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_ArrayType_element_type(arg0, arg1)
}

func StructType_num_fields(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_StructType_num_fields(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_StructType_num_fields(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_StructType_num_fields(arg0, arg1)
}

func StructType_field(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_StructType_field(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_StructType_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_StructType_field(arg0, arg1, arg2)
}

func StructType_fields(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_StructType_fields(
		arg0,
		arg1,
	)
}

func simple_catalog_StructType_fields(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_StructType_fields(arg0, arg1)
}

func StructField_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_StructField_new(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_StructField_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_StructField_new(arg0, arg1, arg2)
}

func StructField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_StructField_name(
		arg0,
		arg1,
	)
}

func simple_catalog_StructField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_StructField_name(arg0, arg1)
}

func StructField_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_StructField_type(
		arg0,
		arg1,
	)
}

func simple_catalog_StructField_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_StructField_type(arg0, arg1)
}

func TypeFactory_new(arg0 *unsafe.Pointer) {
	simple_catalog_TypeFactory_new(
		arg0,
	)
}

func simple_catalog_TypeFactory_new(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TypeFactory_new(arg0)
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

func TypeFactory_MakeStructType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_TypeFactory_MakeStructType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_TypeFactory_MakeStructType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TypeFactory_MakeStructType(arg0, arg1, arg2, arg3)
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

func TypeFromSimpleTypeKind(arg0 int, arg1 *unsafe.Pointer) {
	simple_catalog_TypeFromSimpleTypeKind(
		C.int(arg0),
		arg1,
	)
}

func simple_catalog_TypeFromSimpleTypeKind(arg0 C.int, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TypeFromSimpleTypeKind(arg0, arg1)
}

func Value_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_type(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_type(arg0, arg1)
}

func Value_type_kind(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Value_type_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_type_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Value_type_kind(arg0, arg1)
}

func Value_physical_byte_size(arg0 unsafe.Pointer, arg1 *uint64) {
	simple_catalog_Value_physical_byte_size(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_physical_byte_size(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_zetasql_public_simple_catalog_Value_physical_byte_size(arg0, arg1)
}

func Value_is_null(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_is_null(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_is_null(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Value_is_null(arg0, arg1)
}

func Value_is_empty_array(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_is_empty_array(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_is_empty_array(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Value_is_empty_array(arg0, arg1)
}

func Value_is_valid(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_is_valid(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_is_valid(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Value_is_valid(arg0, arg1)
}

func Value_has_content(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_has_content(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_has_content(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Value_has_content(arg0, arg1)
}

func Value_int32_value(arg0 unsafe.Pointer, arg1 *int32) {
	simple_catalog_Value_int32_value(
		arg0,
		(*C.int32_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_int32_value(arg0 unsafe.Pointer, arg1 *C.int32_t) {
	C.export_zetasql_public_simple_catalog_Value_int32_value(arg0, arg1)
}

func Value_int64_value(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_Value_int64_value(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_int64_value(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_public_simple_catalog_Value_int64_value(arg0, arg1)
}

func Value_uint32_value(arg0 unsafe.Pointer, arg1 *uint32) {
	simple_catalog_Value_uint32_value(
		arg0,
		(*C.uint32_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_uint32_value(arg0 unsafe.Pointer, arg1 *C.uint32_t) {
	C.export_zetasql_public_simple_catalog_Value_uint32_value(arg0, arg1)
}

func Value_uint64_value(arg0 unsafe.Pointer, arg1 *uint64) {
	simple_catalog_Value_uint64_value(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_uint64_value(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_zetasql_public_simple_catalog_Value_uint64_value(arg0, arg1)
}

func Value_bool_value(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_bool_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_bool_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Value_bool_value(arg0, arg1)
}

func Value_float_value(arg0 unsafe.Pointer, arg1 *float32) {
	simple_catalog_Value_float_value(
		arg0,
		(*C.float)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_float_value(arg0 unsafe.Pointer, arg1 *C.float) {
	C.export_zetasql_public_simple_catalog_Value_float_value(arg0, arg1)
}

func Value_double_value(arg0 unsafe.Pointer, arg1 *float64) {
	simple_catalog_Value_double_value(
		arg0,
		(*C.double)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_double_value(arg0 unsafe.Pointer, arg1 *C.double) {
	C.export_zetasql_public_simple_catalog_Value_double_value(arg0, arg1)
}

func Value_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_string_value(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_string_value(arg0, arg1)
}

func Value_bytes_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_bytes_value(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_bytes_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_bytes_value(arg0, arg1)
}

func Value_date_value(arg0 unsafe.Pointer, arg1 *int32) {
	simple_catalog_Value_date_value(
		arg0,
		(*C.int32_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_date_value(arg0 unsafe.Pointer, arg1 *C.int32_t) {
	C.export_zetasql_public_simple_catalog_Value_date_value(arg0, arg1)
}

func Value_enum_value(arg0 unsafe.Pointer, arg1 *int32) {
	simple_catalog_Value_enum_value(
		arg0,
		(*C.int32_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_enum_value(arg0 unsafe.Pointer, arg1 *C.int32_t) {
	C.export_zetasql_public_simple_catalog_Value_enum_value(arg0, arg1)
}

func Value_enum_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_enum_name(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_enum_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_enum_name(arg0, arg1)
}

func Value_ToTime(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_Value_ToTime(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_ToTime(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_public_simple_catalog_Value_ToTime(arg0, arg1)
}

func Value_ToUnixMicros(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_Value_ToUnixMicros(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_ToUnixMicros(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_public_simple_catalog_Value_ToUnixMicros(arg0, arg1)
}

func Value_ToUnixNanos(arg0 unsafe.Pointer, arg1 *int64, arg2 *unsafe.Pointer) {
	simple_catalog_Value_ToUnixNanos(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
		arg2,
	)
}

func simple_catalog_Value_ToUnixNanos(arg0 unsafe.Pointer, arg1 *C.int64_t, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_ToUnixNanos(arg0, arg1, arg2)
}

func Value_ToPacked64TimeMicros(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_Value_ToPacked64TimeMicros(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_ToPacked64TimeMicros(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_public_simple_catalog_Value_ToPacked64TimeMicros(arg0, arg1)
}

func Value_ToPacked64DatetimeMicros(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_Value_ToPacked64DatetimeMicros(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_ToPacked64DatetimeMicros(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_public_simple_catalog_Value_ToPacked64DatetimeMicros(arg0, arg1)
}

func Value_is_validated_json(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_is_validated_json(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_is_validated_json(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Value_is_validated_json(arg0, arg1)
}

func Value_is_unparsed_json(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_is_unparsed_json(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_is_unparsed_json(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Value_is_unparsed_json(arg0, arg1)
}

func Value_json_value_unparsed(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_json_value_unparsed(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_json_value_unparsed(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_json_value_unparsed(arg0, arg1)
}

func Value_json_string(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_json_string(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_json_string(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_json_string(arg0, arg1)
}

func Value_ToInt64(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_Value_ToInt64(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_ToInt64(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_public_simple_catalog_Value_ToInt64(arg0, arg1)
}

func Value_ToUint64(arg0 unsafe.Pointer, arg1 *uint64) {
	simple_catalog_Value_ToUint64(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_ToUint64(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_zetasql_public_simple_catalog_Value_ToUint64(arg0, arg1)
}

func Value_ToDouble(arg0 unsafe.Pointer, arg1 *float64) {
	simple_catalog_Value_ToDouble(
		arg0,
		(*C.double)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_ToDouble(arg0 unsafe.Pointer, arg1 *C.double) {
	C.export_zetasql_public_simple_catalog_Value_ToDouble(arg0, arg1)
}

func Value_num_fields(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Value_num_fields(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_num_fields(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Value_num_fields(arg0, arg1)
}

func Value_field(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Value_field(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Value_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_field(arg0, arg1, arg2)
}

func Value_FindFieldByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Value_FindFieldByName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Value_FindFieldByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_FindFieldByName(arg0, arg1, arg2)
}

func Value_empty(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_empty(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_empty(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Value_empty(arg0, arg1)
}

func Value_num_elements(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Value_num_elements(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_num_elements(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Value_num_elements(arg0, arg1)
}

func Value_element(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Value_element(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Value_element(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_element(arg0, arg1, arg2)
}

func Value_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	simple_catalog_Value_Equals(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_Value_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_public_simple_catalog_Value_Equals(arg0, arg1, arg2)
}

func Value_SqlEquals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Value_SqlEquals(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Value_SqlEquals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_SqlEquals(arg0, arg1, arg2)
}

func Value_LessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	simple_catalog_Value_LessThan(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_Value_LessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_public_simple_catalog_Value_LessThan(arg0, arg1, arg2)
}

func Value_SqlLessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Value_SqlLessThan(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Value_SqlLessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_SqlLessThan(arg0, arg1, arg2)
}

func Value_HashCode(arg0 unsafe.Pointer, arg1 *uint64) {
	simple_catalog_Value_HashCode(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_HashCode(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_zetasql_public_simple_catalog_Value_HashCode(arg0, arg1)
}

func Value_ShortDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_ShortDebugString(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_ShortDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_ShortDebugString(arg0, arg1)
}

func Value_FullDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_FullDebugString(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_FullDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_FullDebugString(arg0, arg1)
}

func Value_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_DebugString(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_DebugString(arg0, arg1)
}

func Value_Format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_Format(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_Format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_Format(arg0, arg1)
}

func Value_GetSQL(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Value_GetSQL(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Value_GetSQL(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_GetSQL(arg0, arg1, arg2)
}

func Value_GetSQLLiteral(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Value_GetSQLLiteral(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Value_GetSQLLiteral(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Value_GetSQLLiteral(arg0, arg1, arg2)
}

func Int64(arg0 int64, arg1 *unsafe.Pointer) {
	simple_catalog_Int64(
		C.int64_t(arg0),
		arg1,
	)
}

func simple_catalog_Int64(arg0 C.int64_t, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Int64(arg0, arg1)
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
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Column_IsPseudoColumn(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Column_IsPseudoColumn(arg0, arg1)
}

func Column_IsWritableColumn(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Column_IsWritableColumn(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Column_IsWritableColumn(arg0 unsafe.Pointer, arg1 *C.char) {
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
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Table_IsValueTable(arg0 unsafe.Pointer, arg1 *C.char) {
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
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Table_SupportsAnonymization(arg0 unsafe.Pointer, arg1 *C.char) {
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
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_SimpleTable_AllowAnonymousColumnName(arg0 unsafe.Pointer, arg1 *C.char) {
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
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_SimpleTable_AllowDuplicateColumnNames(arg0 unsafe.Pointer, arg1 *C.char) {
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

func Catalog_FindModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_Catalog_FindModel(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_Catalog_FindModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Catalog_FindModel(arg0, arg1, arg2, arg3)
}

func Catalog_FindFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_Catalog_FindFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_Catalog_FindFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Catalog_FindFunction(arg0, arg1, arg2, arg3)
}

func Catalog_FindTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_Catalog_FindTableValuedFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_Catalog_FindTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Catalog_FindTableValuedFunction(arg0, arg1, arg2, arg3)
}

func Catalog_FindProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_Catalog_FindProcedure(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_Catalog_FindProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Catalog_FindProcedure(arg0, arg1, arg2, arg3)
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

func Catalog_FindConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *int, arg4 *unsafe.Pointer) {
	simple_catalog_Catalog_FindConstant(
		arg0,
		arg1,
		arg2,
		(*C.int)(unsafe.Pointer(arg3)),
		arg4,
	)
}

func simple_catalog_Catalog_FindConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *C.int, arg4 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Catalog_FindConstant(arg0, arg1, arg2, arg3, arg4)
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

func Catalog_SuggestModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Catalog_SuggestModel(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Catalog_SuggestModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Catalog_SuggestModel(arg0, arg1, arg2)
}

func Catalog_SuggestFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Catalog_SuggestFunction(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Catalog_SuggestFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Catalog_SuggestFunction(arg0, arg1, arg2)
}

func Catalog_SuggestTableValuedTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Catalog_SuggestTableValuedTable(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Catalog_SuggestTableValuedTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Catalog_SuggestTableValuedTable(arg0, arg1, arg2)
}

func Catalog_SuggestConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Catalog_SuggestConstant(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Catalog_SuggestConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Catalog_SuggestConstant(arg0, arg1, arg2)
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

func EnumerableCatalog_Functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_EnumerableCatalog_Functions(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_EnumerableCatalog_Functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_EnumerableCatalog_Functions(arg0, arg1, arg2)
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

func SimpleCatalog_table_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_table_names(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_table_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_table_names(arg0, arg1)
}

func SimpleCatalog_GetModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetModel(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleCatalog_GetModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_GetModel(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleCatalog_GetFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_GetFunction(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetFunctions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetFunctions(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_GetFunctions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_GetFunctions(arg0, arg1, arg2)
}

func SimpleCatalog_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_function_names(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_function_names(arg0, arg1)
}

func SimpleCatalog_GetTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetTableValuedFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleCatalog_GetTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_GetTableValuedFunction(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_table_valued_functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_table_valued_functions(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_table_valued_functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_table_valued_functions(arg0, arg1)
}

func SimpleCatalog_table_valued_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_table_valued_function_names(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_table_valued_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_table_valued_function_names(arg0, arg1)
}

func SimpleCatalog_GetProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetProcedure(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleCatalog_GetProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_GetProcedure(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_procedures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_procedures(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_procedures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_procedures(arg0, arg1)
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

func SimpleCatalog_catalog_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_catalog_names(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_catalog_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_catalog_names(arg0, arg1)
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

func SimpleCatalog_AddModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddModel(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddModel(arg0, arg1)
}

func SimpleCatalog_AddModelWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddModelWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddModelWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddModelWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddConnection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddConnection(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddConnection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddConnection(arg0, arg1)
}

func SimpleCatalog_AddConnectionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddConnectionWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddConnectionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddConnectionWithName(arg0, arg1, arg2)
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
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func simple_catalog_SimpleCatalog_AddTypeIfNotPresent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
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

func SimpleCatalog_AddFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddFunction(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddFunction(arg0, arg1)
}

func SimpleCatalog_AddFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddFunctionWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddFunctionWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddTableValuedFunction(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddTableValuedFunction(arg0, arg1)
}

func SimpleCatalog_AddTableValuedFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddTableValuedFunctionWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddTableValuedFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddTableValuedFunctionWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddProcedure(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddProcedure(arg0, arg1)
}

func SimpleCatalog_AddProcedureWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddProcedureWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddProcedureWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddProcedureWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddConstant(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddConstant(arg0, arg1)
}

func SimpleCatalog_AddConstantWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddConstantWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddConstantWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddConstantWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddZetaSQLFunctions(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddZetaSQLFunctions(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddZetaSQLFunctions(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleCatalog_AddZetaSQLFunctions(arg0, arg1)
}

func Constant_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Constant_Name(
		arg0,
		arg1,
	)
}

func simple_catalog_Constant_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Constant_Name(arg0, arg1)
}

func Constant_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Constant_FullName(
		arg0,
		arg1,
	)
}

func simple_catalog_Constant_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Constant_FullName(arg0, arg1)
}

func Constant_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Constant_type(
		arg0,
		arg1,
	)
}

func simple_catalog_Constant_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Constant_type(arg0, arg1)
}

func Constant_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Constant_DebugString(
		arg0,
		arg1,
	)
}

func simple_catalog_Constant_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Constant_DebugString(arg0, arg1)
}

func Constant_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Constant_name_path(
		arg0,
		arg1,
	)
}

func simple_catalog_Constant_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Constant_name_path(arg0, arg1)
}

func Model_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Model_Name(
		arg0,
		arg1,
	)
}

func simple_catalog_Model_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Model_Name(arg0, arg1)
}

func Model_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Model_FullName(
		arg0,
		arg1,
	)
}

func simple_catalog_Model_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Model_FullName(arg0, arg1)
}

func Model_NumInputs(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Model_NumInputs(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Model_NumInputs(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Model_NumInputs(arg0, arg1)
}

func Model_Input(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Model_Input(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Model_Input(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Model_Input(arg0, arg1, arg2)
}

func Model_NumOutputs(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Model_NumOutputs(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Model_NumOutputs(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Model_NumOutputs(arg0, arg1)
}

func Model_Output(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Model_Output(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Model_Output(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Model_Output(arg0, arg1, arg2)
}

func Model_FindInputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Model_FindInputByName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Model_FindInputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Model_FindInputByName(arg0, arg1, arg2)
}

func Model_FindOutputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Model_FindOutputByName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Model_FindOutputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Model_FindOutputByName(arg0, arg1, arg2)
}

func Model_SerializationID(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Model_SerializationID(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Model_SerializationID(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Model_SerializationID(arg0, arg1)
}

func SimpleModel_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleModel_new(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleModel_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleModel_new(arg0, arg1, arg2, arg3)
}

func SimpleModel_AddInput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleModel_AddInput(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleModel_AddInput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleModel_AddInput(arg0, arg1, arg2)
}

func SimpleModel_AddOutput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleModel_AddOutput(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleModel_AddOutput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SimpleModel_AddOutput(arg0, arg1, arg2)
}

func BuiltinFunctionOptions_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_BuiltinFunctionOptions_new(
		arg0,
		arg1,
	)
}

func simple_catalog_BuiltinFunctionOptions_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_BuiltinFunctionOptions_new(arg0, arg1)
}

func Function_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 unsafe.Pointer, arg4 *unsafe.Pointer) {
	simple_catalog_Function_new(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
		arg4,
	)
}

func simple_catalog_Function_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Function_new(arg0, arg1, arg2, arg3, arg4)
}

func Function_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Function_Name(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Function_Name(arg0, arg1)
}

func Function_FunctionNamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Function_FunctionNamePath(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_FunctionNamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Function_FunctionNamePath(arg0, arg1)
}

func Function_FullName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Function_FullName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Function_FullName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Function_FullName(arg0, arg1, arg2)
}

func Function_SQLName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Function_SQLName(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_SQLName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Function_SQLName(arg0, arg1)
}

func Function_QualifiedSQLName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Function_QualifiedSQLName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Function_QualifiedSQLName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Function_QualifiedSQLName(arg0, arg1, arg2)
}

func Function_Group(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Function_Group(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_Group(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Function_Group(arg0, arg1)
}

func Function_IsZetaSQLBuiltin(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_IsZetaSQLBuiltin(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_IsZetaSQLBuiltin(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_IsZetaSQLBuiltin(arg0, arg1)
}

func Function_ArgumentsAreCoercible(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_ArgumentsAreCoercible(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_ArgumentsAreCoercible(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_ArgumentsAreCoercible(arg0, arg1)
}

func Function_NumSignatures(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Function_NumSignatures(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_NumSignatures(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Function_NumSignatures(arg0, arg1)
}

func Function_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Function_signatures(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Function_signatures(arg0, arg1)
}

func Function_ResetSignatures(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_Function_ResetSignatures(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_ResetSignatures(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Function_ResetSignatures(arg0, arg1)
}

func Function_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_Function_AddSignature(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Function_AddSignature(arg0, arg1)
}

func Function_mode(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Function_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_Function_mode(arg0, arg1)
}

func Function_IsScalar(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_IsScalar(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_IsScalar(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_IsScalar(arg0, arg1)
}

func Function_IsAggregate(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_IsAggregate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_IsAggregate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_IsAggregate(arg0, arg1)
}

func Function_IsAnalytic(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_IsAnalytic(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_IsAnalytic(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_IsAnalytic(arg0, arg1)
}

func Function_DebugString(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Function_DebugString(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Function_DebugString(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Function_DebugString(arg0, arg1, arg2)
}

func Function_GetSQL(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_Function_GetSQL(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_Function_GetSQL(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Function_GetSQL(arg0, arg1, arg2, arg3)
}

func Function_SupportsOverClause(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsOverClause(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsOverClause(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_SupportsOverClause(arg0, arg1)
}

func Function_SupportsWindowOrdering(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsWindowOrdering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsWindowOrdering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_SupportsWindowOrdering(arg0, arg1)
}

func Function_RequiresWindowOrdering(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_RequiresWindowOrdering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_RequiresWindowOrdering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_RequiresWindowOrdering(arg0, arg1)
}

func Function_SupportsWindowFraming(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsWindowFraming(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsWindowFraming(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_SupportsWindowFraming(arg0, arg1)
}

func Function_SupportsOrderingArguments(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsOrderingArguments(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsOrderingArguments(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_SupportsOrderingArguments(arg0, arg1)
}

func Function_SupportsLimitArguments(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsLimitArguments(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsLimitArguments(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_SupportsLimitArguments(arg0, arg1)
}

func Function_SupportsNullHandlingModifier(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsNullHandlingModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsNullHandlingModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_SupportsNullHandlingModifier(arg0, arg1)
}

func Function_SupportsSafeErrorMode(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsSafeErrorMode(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsSafeErrorMode(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_SupportsSafeErrorMode(arg0, arg1)
}

func Function_SupportsHavingModifier(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsHavingModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsHavingModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_SupportsHavingModifier(arg0, arg1)
}

func Function_SupportsDistinctModifier(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsDistinctModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsDistinctModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_SupportsDistinctModifier(arg0, arg1)
}

func Function_SupportsClampedBetweenModifier(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsClampedBetweenModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsClampedBetweenModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_SupportsClampedBetweenModifier(arg0, arg1)
}

func Function_IsDeprecated(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_IsDeprecated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_IsDeprecated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_Function_IsDeprecated(arg0, arg1)
}

func Function_alias_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Function_alias_name(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_alias_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Function_alias_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_new(arg0 int, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_new(
		C.int(arg0),
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_new(arg0 C.int, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_new(arg0, arg1)
}

func FunctionArgumentTypeOptions_cardinality(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionArgumentTypeOptions_cardinality(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_cardinality(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_cardinality(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_be_constant(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_must_be_constant(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_must_be_constant(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_must_be_constant(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_be_non_null(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_must_be_non_null(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_must_be_non_null(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_must_be_non_null(arg0, arg1)
}

func FunctionArgumentTypeOptions_is_not_aggregate(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_is_not_aggregate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_is_not_aggregate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_is_not_aggregate(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_support_equality(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_must_support_equality(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_must_support_equality(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_must_support_equality(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_support_ordering(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_must_support_ordering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_must_support_ordering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_must_support_ordering(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_support_grouping(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_must_support_grouping(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_must_support_grouping(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_must_support_grouping(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_min_value(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_has_min_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_has_min_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_has_min_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_max_value(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_has_max_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_has_max_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_has_max_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_min_value(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_FunctionArgumentTypeOptions_min_value(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_min_value(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_min_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_max_value(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_FunctionArgumentTypeOptions_max_value(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_max_value(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_max_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_relation_input_schema(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_has_relation_input_schema(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_has_relation_input_schema(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_has_relation_input_schema(arg0, arg1)
}

func FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(arg0, arg1)
}

func FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_argument_name(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_has_argument_name(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_has_argument_name(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_has_argument_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_argument_name(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_argument_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_argument_name_is_mandatory(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_argument_name_is_mandatory(arg0, arg1)
}

func FunctionArgumentTypeOptions_procedure_argument_mode(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionArgumentTypeOptions_procedure_argument_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_procedure_argument_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_procedure_argument_mode(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_cardinality(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_cardinality(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_cardinality(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_cardinality(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_be_constant(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_must_be_constant(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_must_be_constant(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_must_be_constant(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_be_non_null(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_must_be_non_null(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_must_be_non_null(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_must_be_non_null(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_is_not_aggregate(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_is_not_aggregate(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_is_not_aggregate(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_is_not_aggregate(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_support_equality(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_must_support_equality(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_must_support_equality(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_must_support_equality(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_support_ordering(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_must_support_ordering(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_must_support_ordering(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_must_support_ordering(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_support_grouping(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_must_support_grouping(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_must_support_grouping(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_must_support_grouping(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_min_value(arg0 unsafe.Pointer, arg1 int64) {
	simple_catalog_FunctionArgumentTypeOptions_set_min_value(
		arg0,
		C.int64_t(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_min_value(arg0 unsafe.Pointer, arg1 C.int64_t) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_min_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_max_value(arg0 unsafe.Pointer, arg1 int64) {
	simple_catalog_FunctionArgumentTypeOptions_set_max_value(
		arg0,
		C.int64_t(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_max_value(arg0 unsafe.Pointer, arg1 C.int64_t) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_max_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_set_argument_name(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_argument_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_argument_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_argument_name_is_mandatory(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_argument_name_is_mandatory(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_procedure_argument_mode(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_procedure_argument_mode(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_procedure_argument_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_procedure_argument_mode(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(arg0, arg1)
}

func FunctionArgumentTypeOptions_OptionsDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_OptionsDebugString(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_OptionsDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_OptionsDebugString(arg0, arg1)
}

func FunctionArgumentTypeOptions_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_GetSQLDeclaration(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_GetSQLDeclaration(arg0, arg1, arg2)
}

func FunctionArgumentTypeOptions_set_argument_name_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_set_argument_name_parse_location(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_argument_name_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_argument_name_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_name_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_argument_name_parse_location(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_argument_name_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_argument_name_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_type_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_set_argument_type_parse_location(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_argument_type_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_argument_type_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_type_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_argument_type_parse_location(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_argument_type_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_argument_type_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_default(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_set_default(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_default(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_default(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_default(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_has_default(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_has_default(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_has_default(arg0, arg1)
}

func FunctionArgumentTypeOptions_get_default(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_get_default(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_get_default(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_get_default(arg0, arg1)
}

func FunctionArgumentTypeOptions_clear_default(arg0 unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_clear_default(
		arg0,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_clear_default(arg0 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_clear_default(arg0)
}

func FunctionArgumentTypeOptions_argument_collation_mode(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionArgumentTypeOptions_argument_collation_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_argument_collation_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_argument_collation_mode(arg0, arg1)
}

func FunctionArgumentTypeOptions_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_uses_array_element_for_collation(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_uses_array_element_for_collation(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_uses_array_element_for_collation(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_uses_array_element_for_collation(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_collation_mode(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_argument_collation_mode(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_argument_collation_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentTypeOptions_set_argument_collation_mode(arg0, arg1)
}

func FunctionArgumentType_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_new(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_FunctionArgumentType_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_new(arg0, arg1, arg2)
}

func FunctionArgumentType_new_templated_type(arg0 int, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_new_templated_type(
		C.int(arg0),
		arg1,
		arg2,
	)
}

func simple_catalog_FunctionArgumentType_new_templated_type(arg0 C.int, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_new_templated_type(arg0, arg1, arg2)
}

func FunctionArgumentType_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_options(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentType_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_options(arg0, arg1)
}

func FunctionArgumentType_required(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_required(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_required(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_required(arg0, arg1)
}

func FunctionArgumentType_repeated(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_repeated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_repeated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_repeated(arg0, arg1)
}

func FunctionArgumentType_optional(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_optional(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_optional(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_optional(arg0, arg1)
}

func FunctionArgumentType_cardinality(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionArgumentType_cardinality(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_cardinality(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_cardinality(arg0, arg1)
}

func FunctionArgumentType_must_be_constant(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_must_be_constant(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_must_be_constant(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_must_be_constant(arg0, arg1)
}

func FunctionArgumentType_has_argument_name(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_has_argument_name(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_has_argument_name(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_has_argument_name(arg0, arg1)
}

func FunctionArgumentType_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_argument_name(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentType_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_argument_name(arg0, arg1)
}

func FunctionArgumentType_num_occurrences(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionArgumentType_num_occurrences(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_num_occurrences(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_num_occurrences(arg0, arg1)
}

func FunctionArgumentType_set_num_occurrences(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentType_set_num_occurrences(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentType_set_num_occurrences(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_set_num_occurrences(arg0, arg1)
}

func FunctionArgumentType_IncrementNumOccurrences(arg0 unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_IncrementNumOccurrences(
		arg0,
	)
}

func simple_catalog_FunctionArgumentType_IncrementNumOccurrences(arg0 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_IncrementNumOccurrences(arg0)
}

func FunctionArgumentType_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_type(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentType_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_type(arg0, arg1)
}

func FunctionArgumentType_kind(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionArgumentType_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_kind(arg0, arg1)
}

func FunctionArgumentType_labmda(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_labmda(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentType_labmda(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_labmda(arg0, arg1)
}

func FunctionArgumentType_IsConcrete(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsConcrete(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsConcrete(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_IsConcrete(arg0, arg1)
}

func FunctionArgumentType_IsTemplated(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsTemplated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsTemplated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_IsTemplated(arg0, arg1)
}

func FunctionArgumentType_IsScalar(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsScalar(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsScalar(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_IsScalar(arg0, arg1)
}

func FunctionArgumentType_IsRelation(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsRelation(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsRelation(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_IsRelation(arg0, arg1)
}

func FunctionArgumentType_IsModel(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsModel(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsModel(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_IsModel(arg0, arg1)
}

func FunctionArgumentType_IsConnection(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsConnection(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsConnection(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_IsConnection(arg0, arg1)
}

func FunctionArgumentType_IsLambda(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsLambda(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsLambda(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_IsLambda(arg0, arg1)
}

func FunctionArgumentType_IsFixedRelation(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsFixedRelation(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsFixedRelation(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_IsFixedRelation(arg0, arg1)
}

func FunctionArgumentType_IsVoid(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsVoid(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsVoid(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_IsVoid(arg0, arg1)
}

func FunctionArgumentType_IsDescriptor(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsDescriptor(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsDescriptor(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_IsDescriptor(arg0, arg1)
}

func FunctionArgumentType_TemplatedKindIsRelated(arg0 unsafe.Pointer, arg1 int, arg2 *bool) {
	simple_catalog_FunctionArgumentType_TemplatedKindIsRelated(
		arg0,
		C.int(arg1),
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_FunctionArgumentType_TemplatedKindIsRelated(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_TemplatedKindIsRelated(arg0, arg1, arg2)
}

func FunctionArgumentType_AllowCoercionFrom(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	simple_catalog_FunctionArgumentType_AllowCoercionFrom(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_FunctionArgumentType_AllowCoercionFrom(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_AllowCoercionFrom(arg0, arg1, arg2)
}

func FunctionArgumentType_HasDefault(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_HasDefault(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_HasDefault(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_HasDefault(arg0, arg1)
}

func FunctionArgumentType_GetDefault(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_GetDefault(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentType_GetDefault(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_GetDefault(arg0, arg1)
}

func FunctionArgumentType_UserFacingName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_UserFacingName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_FunctionArgumentType_UserFacingName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_UserFacingName(arg0, arg1, arg2)
}

func FunctionArgumentType_UserFacingNameWithCardinality(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_UserFacingNameWithCardinality(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_FunctionArgumentType_UserFacingNameWithCardinality(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_UserFacingNameWithCardinality(arg0, arg1, arg2)
}

func FunctionArgumentType_IsValid(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_IsValid(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_FunctionArgumentType_IsValid(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_IsValid(arg0, arg1, arg2)
}

func FunctionArgumentType_DebugString(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_DebugString(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_FunctionArgumentType_DebugString(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_DebugString(arg0, arg1, arg2)
}

func FunctionArgumentType_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_GetSQLDeclaration(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_FunctionArgumentType_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionArgumentType_GetSQLDeclaration(arg0, arg1, arg2)
}

func ArgumentTypeLambda_argument_types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_ArgumentTypeLambda_argument_types(
		arg0,
		arg1,
	)
}

func simple_catalog_ArgumentTypeLambda_argument_types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_ArgumentTypeLambda_argument_types(arg0, arg1)
}

func ArgumentTypeLambda_body_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_ArgumentTypeLambda_body_type(
		arg0,
		arg1,
	)
}

func simple_catalog_ArgumentTypeLambda_body_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_ArgumentTypeLambda_body_type(arg0, arg1)
}

func FunctionSignature_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_new(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_FunctionSignature_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_new(arg0, arg1, arg2)
}

func FunctionSignature_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_arguments(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_arguments(arg0, arg1)
}

func FunctionSignature_concret_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_concret_arguments(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_concret_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_concret_arguments(arg0, arg1)
}

func FunctionSignature_result_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_result_type(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_result_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_result_type(arg0, arg1)
}

func FunctionSignature_IsConcrete(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionSignature_IsConcrete(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_IsConcrete(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_IsConcrete(arg0, arg1)
}

func FunctionSignature_HasConcreteArguments(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionSignature_HasConcreteArguments(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_HasConcreteArguments(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_HasConcreteArguments(arg0, arg1)
}

func FunctionSignature_IsValid(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_IsValid(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_FunctionSignature_IsValid(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_IsValid(arg0, arg1, arg2)
}

func FunctionSignature_IsValidForFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_IsValidForFunction(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_IsValidForFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_IsValidForFunction(arg0, arg1)
}

func FunctionSignature_IsValidForTableValuedFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_IsValidForTableValuedFunction(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_IsValidForTableValuedFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_IsValidForTableValuedFunction(arg0, arg1)
}

func FunctionSignature_IsValidForProcedure(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_IsValidForProcedure(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_IsValidForProcedure(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_IsValidForProcedure(arg0, arg1)
}

func FunctionSignature_FirstRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionSignature_FirstRepeatedArgumentIndex(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_FirstRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_FirstRepeatedArgumentIndex(arg0, arg1)
}

func FunctionSignature_LastRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionSignature_LastRepeatedArgumentIndex(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_LastRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_LastRepeatedArgumentIndex(arg0, arg1)
}

func FunctionSignature_NumRequiredArguments(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionSignature_NumRequiredArguments(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_NumRequiredArguments(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_NumRequiredArguments(arg0, arg1)
}

func FunctionSignature_NumRepeatedArguments(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionSignature_NumRepeatedArguments(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_NumRepeatedArguments(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_NumRepeatedArguments(arg0, arg1)
}

func FunctionSignature_NumOptionalArguments(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionSignature_NumOptionalArguments(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_NumOptionalArguments(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_NumOptionalArguments(arg0, arg1)
}

func FunctionSignature_DebugString(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_DebugString(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func simple_catalog_FunctionSignature_DebugString(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_DebugString(arg0, arg1, arg2, arg3)
}

func FunctionSignature_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_GetSQLDeclaration(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func simple_catalog_FunctionSignature_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_GetSQLDeclaration(arg0, arg1, arg2, arg3)
}

func FunctionSignature_IsDeprecated(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionSignature_IsDeprecated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_IsDeprecated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_IsDeprecated(arg0, arg1)
}

func FunctionSignature_SetIsDeprecated(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionSignature_SetIsDeprecated(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionSignature_SetIsDeprecated(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_SetIsDeprecated(arg0, arg1)
}

func FunctionSignature_IsInternal(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionSignature_IsInternal(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_IsInternal(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_IsInternal(arg0, arg1)
}

func FunctionSignature_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_options(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_options(arg0, arg1)
}

func FunctionSignature_SetConcreteResultType(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_FunctionSignature_SetConcreteResultType(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_SetConcreteResultType(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_SetConcreteResultType(arg0, arg1)
}

func FunctionSignature_IsTemplated(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionSignature_IsTemplated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_IsTemplated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_IsTemplated(arg0, arg1)
}

func FunctionSignature_AllArgumentsHaveDefaults(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionSignature_AllArgumentsHaveDefaults(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_AllArgumentsHaveDefaults(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_simple_catalog_FunctionSignature_AllArgumentsHaveDefaults(arg0, arg1)
}

func Procedure_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Procedure_new(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Procedure_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Procedure_new(arg0, arg1, arg2)
}

func Procedure_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Procedure_Name(
		arg0,
		arg1,
	)
}

func simple_catalog_Procedure_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Procedure_Name(arg0, arg1)
}

func Procedure_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Procedure_FullName(
		arg0,
		arg1,
	)
}

func simple_catalog_Procedure_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Procedure_FullName(arg0, arg1)
}

func Procedure_NamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Procedure_NamePath(
		arg0,
		arg1,
	)
}

func simple_catalog_Procedure_NamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Procedure_NamePath(arg0, arg1)
}

func Procedure_Signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Procedure_Signature(
		arg0,
		arg1,
	)
}

func simple_catalog_Procedure_Signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Procedure_Signature(arg0, arg1)
}

func Procedure_SupportedSignatureUserFacingText(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Procedure_SupportedSignatureUserFacingText(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Procedure_SupportedSignatureUserFacingText(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Procedure_SupportedSignatureUserFacingText(arg0, arg1, arg2)
}

func SQLTableValuedFunction_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SQLTableValuedFunction_new(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SQLTableValuedFunction_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_SQLTableValuedFunction_new(arg0, arg1, arg2)
}

func TableValuedFunction_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_Name(
		arg0,
		arg1,
	)
}

func simple_catalog_TableValuedFunction_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TableValuedFunction_Name(arg0, arg1)
}

func TableValuedFunction_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_FullName(
		arg0,
		arg1,
	)
}

func simple_catalog_TableValuedFunction_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TableValuedFunction_FullName(arg0, arg1)
}

func TableValuedFunction_function_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_function_name_path(
		arg0,
		arg1,
	)
}

func simple_catalog_TableValuedFunction_function_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TableValuedFunction_function_name_path(arg0, arg1)
}

func TableValuedFunction_NumSignatures(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_TableValuedFunction_NumSignatures(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_TableValuedFunction_NumSignatures(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_simple_catalog_TableValuedFunction_NumSignatures(arg0, arg1)
}

func TableValuedFunction_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_signatures(
		arg0,
		arg1,
	)
}

func simple_catalog_TableValuedFunction_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TableValuedFunction_signatures(arg0, arg1)
}

func TableValuedFunction_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_AddSignature(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_TableValuedFunction_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TableValuedFunction_AddSignature(arg0, arg1, arg2)
}

func TableValuedFunction_GetSignature(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_GetSignature(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_TableValuedFunction_GetSignature(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TableValuedFunction_GetSignature(arg0, arg1, arg2)
}

func TableValuedFunction_GetSupportedSignaturesUserFacingText(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_GetSupportedSignaturesUserFacingText(
		arg0,
		arg1,
	)
}

func simple_catalog_TableValuedFunction_GetSupportedSignaturesUserFacingText(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TableValuedFunction_GetSupportedSignaturesUserFacingText(arg0, arg1)
}

func TableValuedFunction_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_DebugString(
		arg0,
		arg1,
	)
}

func simple_catalog_TableValuedFunction_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TableValuedFunction_DebugString(arg0, arg1)
}

func TableValuedFunction_SetUserIdColumnNamePath(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_SetUserIdColumnNamePath(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_TableValuedFunction_SetUserIdColumnNamePath(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TableValuedFunction_SetUserIdColumnNamePath(arg0, arg1, arg2)
}

func TableValuedFunction_anonymization_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_anonymization_info(
		arg0,
		arg1,
	)
}

func simple_catalog_TableValuedFunction_anonymization_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_TableValuedFunction_anonymization_info(arg0, arg1)
}

//export export_zetasql_public_simple_catalog_cctz_FixedOffsetFromName
//go:linkname export_zetasql_public_simple_catalog_cctz_FixedOffsetFromName github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetFromName
func export_zetasql_public_simple_catalog_cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

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
func export_zetasql_public_simple_catalog_cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *C.char)

//export export_zetasql_public_simple_catalog_TimeZoneIf_Load
//go:linkname export_zetasql_public_simple_catalog_TimeZoneIf_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneIf_Load
func export_zetasql_public_simple_catalog_TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_time_zone_Impl_UTC
//go:linkname export_zetasql_public_simple_catalog_time_zone_Impl_UTC github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTC
func export_zetasql_public_simple_catalog_time_zone_Impl_UTC(arg0 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_time_zone_Impl_LoadTimeZone
//go:linkname export_zetasql_public_simple_catalog_time_zone_Impl_LoadTimeZone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_LoadTimeZone
func export_zetasql_public_simple_catalog_time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_public_simple_catalog_time_zone_Impl_ClearTimeZoneMapTestOnly
//go:linkname export_zetasql_public_simple_catalog_time_zone_Impl_ClearTimeZoneMapTestOnly github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_ClearTimeZoneMapTestOnly
func export_zetasql_public_simple_catalog_time_zone_Impl_ClearTimeZoneMapTestOnly()

//export export_zetasql_public_simple_catalog_time_zone_Impl_UTCImpl
//go:linkname export_zetasql_public_simple_catalog_time_zone_Impl_UTCImpl github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTCImpl
func export_zetasql_public_simple_catalog_time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_TimeZoneInfo_Load
//go:linkname export_zetasql_public_simple_catalog_TimeZoneInfo_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Load
func export_zetasql_public_simple_catalog_TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

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
func export_zetasql_public_simple_catalog_TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_public_simple_catalog_TimeZoneInfo_PrevTransition
//go:linkname export_zetasql_public_simple_catalog_TimeZoneInfo_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_PrevTransition
func export_zetasql_public_simple_catalog_TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

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
func export_zetasql_public_simple_catalog_TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_public_simple_catalog_TimeZoneLibC_PrevTransition
//go:linkname export_zetasql_public_simple_catalog_TimeZoneLibC_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_PrevTransition
func export_zetasql_public_simple_catalog_TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

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
func export_zetasql_public_simple_catalog_time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_public_simple_catalog_time_zone_prev_transition
//go:linkname export_zetasql_public_simple_catalog_time_zone_prev_transition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_prev_transition
func export_zetasql_public_simple_catalog_time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_public_simple_catalog_time_zone_version
//go:linkname export_zetasql_public_simple_catalog_time_zone_version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_version
func export_zetasql_public_simple_catalog_time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_time_zone_description
//go:linkname export_zetasql_public_simple_catalog_time_zone_description github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_description
func export_zetasql_public_simple_catalog_time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_simple_catalog_cctz_load_time_zone
//go:linkname export_zetasql_public_simple_catalog_cctz_load_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_load_time_zone
func export_zetasql_public_simple_catalog_cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

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
func export_zetasql_public_simple_catalog_cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)
