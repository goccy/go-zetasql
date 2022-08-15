package time_zone

/*
#cgo CXXFLAGS: -std=c++11
#cgo CXXFLAGS: -I../../../../../
#cgo CXXFLAGS: -I../../../../../protobuf
#cgo CXXFLAGS: -I../../../../../gtest
#cgo CXXFLAGS: -I../../../../../icu
#cgo CXXFLAGS: -I../../../../../re2
#cgo CXXFLAGS: -I../../../../../json
#cgo CXXFLAGS: -I../../../../../googleapis
#cgo CXXFLAGS: -I../../../../../flex/src
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

#define GO_EXPORT(API) export_absl_time_internal_cctz_time_zone_ ## API
#include "bridge.h"
*/
import "C"
import (
	"unsafe"
)

func cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	time_zone_cctz_FixedOffsetFromName(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func time_zone_cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_absl_time_internal_cctz_time_zone_cctz_FixedOffsetFromName(arg0, arg1, arg2)
}

func cctz_FixedOffsetToName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	time_zone_cctz_FixedOffsetToName(
		arg0,
		arg1,
	)
}

func time_zone_cctz_FixedOffsetToName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_cctz_FixedOffsetToName(arg0, arg1)
}

func cctz_FixedOffsetToAbbr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	time_zone_cctz_FixedOffsetToAbbr(
		arg0,
		arg1,
	)
}

func time_zone_cctz_FixedOffsetToAbbr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_cctz_FixedOffsetToAbbr(arg0, arg1)
}

func cctz_detail_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer) {
	time_zone_cctz_detail_format(
		arg0,
		arg1,
		arg2,
		arg3,
		arg4,
	)
}

func time_zone_cctz_detail_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_cctz_detail_format(arg0, arg1, arg2, arg3, arg4)
}

func cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *bool) {
	time_zone_cctz_detail_parse(
		arg0,
		arg1,
		arg2,
		arg3,
		arg4,
		arg5,
		(*C.char)(unsafe.Pointer(arg6)),
	)
}

func time_zone_cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *C.char) {
	C.export_absl_time_internal_cctz_time_zone_cctz_detail_parse(arg0, arg1, arg2, arg3, arg4, arg5, arg6)
}

func TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	time_zone_TimeZoneIf_Load(
		arg0,
		arg1,
	)
}

func time_zone_TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_TimeZoneIf_Load(arg0, arg1)
}

func time_zone_Impl_UTC(arg0 *unsafe.Pointer) {
	time_zone_time_zone_Impl_UTC(
		arg0,
	)
}

func time_zone_time_zone_Impl_UTC(arg0 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_time_zone_Impl_UTC(arg0)
}

func time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	time_zone_time_zone_Impl_LoadTimeZone(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func time_zone_time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_absl_time_internal_cctz_time_zone_time_zone_Impl_LoadTimeZone(arg0, arg1, arg2)
}

func time_zone_Impl_ClearTimeZoneMapTestOnly() {
	time_zone_time_zone_Impl_ClearTimeZoneMapTestOnly()
}

func time_zone_time_zone_Impl_ClearTimeZoneMapTestOnly() {
	C.export_absl_time_internal_cctz_time_zone_time_zone_Impl_ClearTimeZoneMapTestOnly()
}

func time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer) {
	time_zone_time_zone_Impl_UTCImpl(
		arg0,
	)
}

func time_zone_time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_time_zone_Impl_UTCImpl(arg0)
}

func TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	time_zone_TimeZoneInfo_Load(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func time_zone_TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_absl_time_internal_cctz_time_zone_TimeZoneInfo_Load(arg0, arg1, arg2)
}

func TimeZoneInfo_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	time_zone_TimeZoneInfo_BreakTime(
		arg0,
		arg1,
		arg2,
	)
}

func time_zone_TimeZoneInfo_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_TimeZoneInfo_BreakTime(arg0, arg1, arg2)
}

func TimeZoneInfo_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	time_zone_TimeZoneInfo_MakeTime(
		arg0,
		arg1,
		arg2,
	)
}

func time_zone_TimeZoneInfo_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_TimeZoneInfo_MakeTime(arg0, arg1, arg2)
}

func TimeZoneInfo_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	time_zone_TimeZoneInfo_Version(
		arg0,
		arg1,
	)
}

func time_zone_TimeZoneInfo_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_TimeZoneInfo_Version(arg0, arg1)
}

func TimeZoneInfo_Description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	time_zone_TimeZoneInfo_Description(
		arg0,
		arg1,
	)
}

func time_zone_TimeZoneInfo_Description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_TimeZoneInfo_Description(arg0, arg1)
}

func TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	time_zone_TimeZoneInfo_NextTransition(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func time_zone_TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
	C.export_absl_time_internal_cctz_time_zone_TimeZoneInfo_NextTransition(arg0, arg1, arg2, arg3)
}

func TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	time_zone_TimeZoneInfo_PrevTransition(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func time_zone_TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
	C.export_absl_time_internal_cctz_time_zone_TimeZoneInfo_PrevTransition(arg0, arg1, arg2, arg3)
}

func TimeZoneLibC_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	time_zone_TimeZoneLibC_BreakTime(
		arg0,
		arg1,
		arg2,
	)
}

func time_zone_TimeZoneLibC_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_TimeZoneLibC_BreakTime(arg0, arg1, arg2)
}

func TimeZoneLibC_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	time_zone_TimeZoneLibC_MakeTime(
		arg0,
		arg1,
		arg2,
	)
}

func time_zone_TimeZoneLibC_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_TimeZoneLibC_MakeTime(arg0, arg1, arg2)
}

func TimeZoneLibC_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	time_zone_TimeZoneLibC_Version(
		arg0,
		arg1,
	)
}

func time_zone_TimeZoneLibC_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_TimeZoneLibC_Version(arg0, arg1)
}

func TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	time_zone_TimeZoneLibC_NextTransition(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func time_zone_TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
	C.export_absl_time_internal_cctz_time_zone_TimeZoneLibC_NextTransition(arg0, arg1, arg2, arg3)
}

func TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	time_zone_TimeZoneLibC_PrevTransition(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func time_zone_TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
	C.export_absl_time_internal_cctz_time_zone_TimeZoneLibC_PrevTransition(arg0, arg1, arg2, arg3)
}

func time_zone_name(arg0 *unsafe.Pointer) {
	time_zone_time_zone_name(
		arg0,
	)
}

func time_zone_time_zone_name(arg0 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_time_zone_name(arg0)
}

func time_zone_lookup(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	time_zone_time_zone_lookup(
		arg0,
		arg1,
		arg2,
	)
}

func time_zone_time_zone_lookup(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_time_zone_lookup(arg0, arg1, arg2)
}

func time_zone_lookup2(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	time_zone_time_zone_lookup2(
		arg0,
		arg1,
		arg2,
	)
}

func time_zone_time_zone_lookup2(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_time_zone_lookup2(arg0, arg1, arg2)
}

func time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	time_zone_time_zone_next_transition(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func time_zone_time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_absl_time_internal_cctz_time_zone_time_zone_next_transition(arg0, arg1, arg2)
}

func time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	time_zone_time_zone_prev_transition(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func time_zone_time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_absl_time_internal_cctz_time_zone_time_zone_prev_transition(arg0, arg1, arg2)
}

func time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	time_zone_time_zone_version(
		arg0,
		arg1,
	)
}

func time_zone_time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_time_zone_version(arg0, arg1)
}

func time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	time_zone_time_zone_description(
		arg0,
		arg1,
	)
}

func time_zone_time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_time_zone_description(arg0, arg1)
}

func cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	time_zone_cctz_load_time_zone(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func time_zone_cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_absl_time_internal_cctz_time_zone_cctz_load_time_zone(arg0, arg1, arg2)
}

func cctz_utc_time_zone(arg0 *unsafe.Pointer) {
	time_zone_cctz_utc_time_zone(
		arg0,
	)
}

func time_zone_cctz_utc_time_zone(arg0 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_cctz_utc_time_zone(arg0)
}

func cctz_fixed_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	time_zone_cctz_fixed_time_zone(
		arg0,
		arg1,
	)
}

func time_zone_cctz_fixed_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_cctz_fixed_time_zone(arg0, arg1)
}

func cctz_local_time_zone(arg0 *unsafe.Pointer) {
	time_zone_cctz_local_time_zone(
		arg0,
	)
}

func time_zone_cctz_local_time_zone(arg0 *unsafe.Pointer) {
	C.export_absl_time_internal_cctz_time_zone_cctz_local_time_zone(arg0)
}

func cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	time_zone_cctz_ParsePosixSpec(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func time_zone_cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_absl_time_internal_cctz_time_zone_cctz_ParsePosixSpec(arg0, arg1, arg2)
}
