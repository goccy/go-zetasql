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

func StructType(arg0 *unsafe.Pointer) {
	simple_catalog_StructType(
		arg0,
	)
}

func simple_catalog_StructType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_StructType(arg0)
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

func DepartEnumType(arg0 *unsafe.Pointer) {
	simple_catalog_DepartEnumType(
		arg0,
	)
}

func simple_catalog_DepartEnumType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_DepartEnumType(arg0)
}

func NormalizeModeEnumType(arg0 *unsafe.Pointer) {
	simple_catalog_NormalizeModeEnumType(
		arg0,
	)
}

func simple_catalog_NormalizeModeEnumType(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_NormalizeModeEnumType(arg0)
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

func Table_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Table_new(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Table_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Table_new(arg0, arg1, arg2)
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

func Table_PrimaryKey(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Table_PrimaryKey(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Table_PrimaryKey(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_simple_catalog_Table_PrimaryKey(arg0, arg1, arg2)
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
