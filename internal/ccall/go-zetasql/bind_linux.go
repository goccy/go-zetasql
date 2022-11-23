package zetasql

/*
#cgo CXXFLAGS: -std=c++1z
#cgo CXXFLAGS: -I../
#cgo CXXFLAGS: -I../protobuf
#cgo CXXFLAGS: -I../gtest
#cgo CXXFLAGS: -I../icu
#cgo CXXFLAGS: -I../re2
#cgo CXXFLAGS: -I../json
#cgo CXXFLAGS: -I../googleapis
#cgo CXXFLAGS: -I../flex/src
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

#define GO_EXPORT(API) export_zetasql_ ## API
#include "bridge.h"
#include "../go-absl/time/go_internal/cctz/time_zone/bridge.h"
*/
import "C"
import (
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone"
	"unsafe"
)

func cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_cctz_FixedOffsetFromName(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_cctz_FixedOffsetFromName(arg0, arg1, arg2)
}

func cctz_FixedOffsetToName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_cctz_FixedOffsetToName(
		arg0,
		arg1,
	)
}

func zetasql_cctz_FixedOffsetToName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_cctz_FixedOffsetToName(arg0, arg1)
}

func cctz_FixedOffsetToAbbr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_cctz_FixedOffsetToAbbr(
		arg0,
		arg1,
	)
}

func zetasql_cctz_FixedOffsetToAbbr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_cctz_FixedOffsetToAbbr(arg0, arg1)
}

func cctz_detail_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer) {
	zetasql_cctz_detail_format(
		arg0,
		arg1,
		arg2,
		arg3,
		arg4,
	)
}

func zetasql_cctz_detail_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_zetasql_cctz_detail_format(arg0, arg1, arg2, arg3, arg4)
}

func cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *bool) {
	zetasql_cctz_detail_parse(
		arg0,
		arg1,
		arg2,
		arg3,
		arg4,
		arg5,
		(*C.char)(unsafe.Pointer(arg6)),
	)
}

func zetasql_cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *C.char) {
	C.export_zetasql_cctz_detail_parse(arg0, arg1, arg2, arg3, arg4, arg5, arg6)
}

func TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_TimeZoneIf_Load(
		arg0,
		arg1,
	)
}

func zetasql_TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_TimeZoneIf_Load(arg0, arg1)
}

func time_zone_Impl_UTC(arg0 *unsafe.Pointer) {
	zetasql_time_zone_Impl_UTC(
		arg0,
	)
}

func zetasql_time_zone_Impl_UTC(arg0 *unsafe.Pointer) {
	C.export_zetasql_time_zone_Impl_UTC(arg0)
}

func time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_time_zone_Impl_LoadTimeZone(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_time_zone_Impl_LoadTimeZone(arg0, arg1, arg2)
}

func time_zone_Impl_ClearTimeZoneMapTestOnly() {
	zetasql_time_zone_Impl_ClearTimeZoneMapTestOnly()
}

func zetasql_time_zone_Impl_ClearTimeZoneMapTestOnly() {
	C.export_zetasql_time_zone_Impl_ClearTimeZoneMapTestOnly()
}

func time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer) {
	zetasql_time_zone_Impl_UTCImpl(
		arg0,
	)
}

func zetasql_time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer) {
	C.export_zetasql_time_zone_Impl_UTCImpl(arg0)
}

func TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_TimeZoneInfo_Load(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_TimeZoneInfo_Load(arg0, arg1, arg2)
}

func TimeZoneInfo_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_TimeZoneInfo_BreakTime(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_TimeZoneInfo_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_TimeZoneInfo_BreakTime(arg0, arg1, arg2)
}

func TimeZoneInfo_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_TimeZoneInfo_MakeTime(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_TimeZoneInfo_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_TimeZoneInfo_MakeTime(arg0, arg1, arg2)
}

func TimeZoneInfo_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_TimeZoneInfo_Version(
		arg0,
		arg1,
	)
}

func zetasql_TimeZoneInfo_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_TimeZoneInfo_Version(arg0, arg1)
}

func TimeZoneInfo_Description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_TimeZoneInfo_Description(
		arg0,
		arg1,
	)
}

func zetasql_TimeZoneInfo_Description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_TimeZoneInfo_Description(arg0, arg1)
}

func TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	zetasql_TimeZoneInfo_NextTransition(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func zetasql_TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
	C.export_zetasql_TimeZoneInfo_NextTransition(arg0, arg1, arg2, arg3)
}

func TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	zetasql_TimeZoneInfo_PrevTransition(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func zetasql_TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
	C.export_zetasql_TimeZoneInfo_PrevTransition(arg0, arg1, arg2, arg3)
}

func TimeZoneLibC_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_TimeZoneLibC_BreakTime(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_TimeZoneLibC_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_TimeZoneLibC_BreakTime(arg0, arg1, arg2)
}

func TimeZoneLibC_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_TimeZoneLibC_MakeTime(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_TimeZoneLibC_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_TimeZoneLibC_MakeTime(arg0, arg1, arg2)
}

func TimeZoneLibC_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_TimeZoneLibC_Version(
		arg0,
		arg1,
	)
}

func zetasql_TimeZoneLibC_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_TimeZoneLibC_Version(arg0, arg1)
}

func TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	zetasql_TimeZoneLibC_NextTransition(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func zetasql_TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
	C.export_zetasql_TimeZoneLibC_NextTransition(arg0, arg1, arg2, arg3)
}

func TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	zetasql_TimeZoneLibC_PrevTransition(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func zetasql_TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
	C.export_zetasql_TimeZoneLibC_PrevTransition(arg0, arg1, arg2, arg3)
}

func time_zone_name(arg0 *unsafe.Pointer) {
	zetasql_time_zone_name(
		arg0,
	)
}

func zetasql_time_zone_name(arg0 *unsafe.Pointer) {
	C.export_zetasql_time_zone_name(arg0)
}

func time_zone_lookup(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_time_zone_lookup(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_time_zone_lookup(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_time_zone_lookup(arg0, arg1, arg2)
}

func time_zone_lookup2(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_time_zone_lookup2(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_time_zone_lookup2(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_time_zone_lookup2(arg0, arg1, arg2)
}

func time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_time_zone_next_transition(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_time_zone_next_transition(arg0, arg1, arg2)
}

func time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_time_zone_prev_transition(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_time_zone_prev_transition(arg0, arg1, arg2)
}

func time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_time_zone_version(
		arg0,
		arg1,
	)
}

func zetasql_time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_time_zone_version(arg0, arg1)
}

func time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_time_zone_description(
		arg0,
		arg1,
	)
}

func zetasql_time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_time_zone_description(arg0, arg1)
}

func cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_cctz_load_time_zone(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_cctz_load_time_zone(arg0, arg1, arg2)
}

func cctz_utc_time_zone(arg0 *unsafe.Pointer) {
	zetasql_cctz_utc_time_zone(
		arg0,
	)
}

func zetasql_cctz_utc_time_zone(arg0 *unsafe.Pointer) {
	C.export_zetasql_cctz_utc_time_zone(arg0)
}

func cctz_fixed_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_cctz_fixed_time_zone(
		arg0,
		arg1,
	)
}

func zetasql_cctz_fixed_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_cctz_fixed_time_zone(arg0, arg1)
}

func cctz_local_time_zone(arg0 *unsafe.Pointer) {
	zetasql_cctz_local_time_zone(
		arg0,
	)
}

func zetasql_cctz_local_time_zone(arg0 *unsafe.Pointer) {
	C.export_zetasql_cctz_local_time_zone(arg0)
}

func cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_cctz_ParsePosixSpec(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_cctz_ParsePosixSpec(arg0, arg1, arg2)
}

func ParseStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_ParseStatement(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_ParseStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_ParseStatement(arg0, arg1, arg2, arg3)
}

func ParseScript(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	zetasql_ParseScript(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
		arg4,
	)
}

func zetasql_ParseScript(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_zetasql_ParseScript(arg0, arg1, arg2, arg3, arg4)
}

func ParseNextStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *bool, arg4 *unsafe.Pointer) {
	zetasql_ParseNextStatement(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
		arg4,
	)
}

func zetasql_ParseNextStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *C.char, arg4 *unsafe.Pointer) {
	C.export_zetasql_ParseNextStatement(arg0, arg1, arg2, arg3, arg4)
}

func ParseNextScriptStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *bool, arg4 *unsafe.Pointer) {
	zetasql_ParseNextScriptStatement(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
		arg4,
	)
}

func zetasql_ParseNextScriptStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *C.char, arg4 *unsafe.Pointer) {
	C.export_zetasql_ParseNextScriptStatement(arg0, arg1, arg2, arg3, arg4)
}

func ParseType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_ParseType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_ParseType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_ParseType(arg0, arg1, arg2, arg3)
}

func ParseExpression(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_ParseExpression(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_ParseExpression(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_ParseExpression(arg0, arg1, arg2, arg3)
}

func Unparse(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Unparse(
		arg0,
		arg1,
	)
}

func zetasql_Unparse(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Unparse(arg0, arg1)
}

func ParseResumeLocation_FromStringView(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ParseResumeLocation_FromStringView(
		arg0,
		arg1,
	)
}

func zetasql_ParseResumeLocation_FromStringView(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ParseResumeLocation_FromStringView(arg0, arg1)
}

func Status_OK(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Status_OK(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Status_OK(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Status_OK(arg0, arg1)
}

func Status_String(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Status_String(
		arg0,
		arg1,
	)
}

func zetasql_Status_String(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Status_String(arg0, arg1)
}

func ParserOptions_new(arg0 *unsafe.Pointer) {
	zetasql_ParserOptions_new(
		arg0,
	)
}

func zetasql_ParserOptions_new(arg0 *unsafe.Pointer) {
	C.export_zetasql_ParserOptions_new(arg0)
}

func ParserOptions_set_language_options(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ParserOptions_set_language_options(
		arg0,
		arg1,
	)
}

func zetasql_ParserOptions_set_language_options(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ParserOptions_set_language_options(arg0, arg1)
}

func ParserOptions_language_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ParserOptions_language_options(
		arg0,
		arg1,
	)
}

func zetasql_ParserOptions_language_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ParserOptions_language_options(arg0, arg1)
}

func ParserOutput_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ParserOutput_statement(
		arg0,
		arg1,
	)
}

func zetasql_ParserOutput_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ParserOutput_statement(arg0, arg1)
}

func ParserOutput_script(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ParserOutput_script(
		arg0,
		arg1,
	)
}

func zetasql_ParserOutput_script(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ParserOutput_script(arg0, arg1)
}

func ParserOutput_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ParserOutput_type(
		arg0,
		arg1,
	)
}

func zetasql_ParserOutput_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ParserOutput_type(arg0, arg1)
}

func ParserOutput_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ParserOutput_expression(
		arg0,
		arg1,
	)
}

func zetasql_ParserOutput_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ParserOutput_expression(arg0, arg1)
}

func ASTNode_getId(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTNode_getId(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNode_getId(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTNode_getId(arg0, arg1)
}

func ASTNode_node_kind(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTNode_node_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNode_node_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTNode_node_kind(arg0, arg1)
}

func ASTNode_SingleNodeDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTNode_SingleNodeDebugString(
		arg0,
		arg1,
	)
}

func zetasql_ASTNode_SingleNodeDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTNode_SingleNodeDebugString(arg0, arg1)
}

func ASTNode_set_parent(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ASTNode_set_parent(
		arg0,
		arg1,
	)
}

func zetasql_ASTNode_set_parent(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ASTNode_set_parent(arg0, arg1)
}

func ASTNode_parent(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTNode_parent(
		arg0,
		arg1,
	)
}

func zetasql_ASTNode_parent(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTNode_parent(arg0, arg1)
}

func ASTNode_AddChildren(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ASTNode_AddChildren(
		arg0,
		arg1,
	)
}

func zetasql_ASTNode_AddChildren(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ASTNode_AddChildren(arg0, arg1)
}

func ASTNode_AddChild(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ASTNode_AddChild(
		arg0,
		arg1,
	)
}

func zetasql_ASTNode_AddChild(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ASTNode_AddChild(arg0, arg1)
}

func ASTNode_AddChildFront(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ASTNode_AddChildFront(
		arg0,
		arg1,
	)
}

func zetasql_ASTNode_AddChildFront(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ASTNode_AddChildFront(arg0, arg1)
}

func ASTNode_num_children(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTNode_num_children(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNode_num_children(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTNode_num_children(arg0, arg1)
}

func ASTNode_child(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTNode_child(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTNode_child(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTNode_child(arg0, arg1, arg2)
}

func ASTNode_mutable_child(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTNode_mutable_child(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTNode_mutable_child(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTNode_mutable_child(arg0, arg1, arg2)
}

func ASTNode_find_child_index(arg0 unsafe.Pointer, arg1 int, arg2 *int) {
	zetasql_ASTNode_find_child_index(
		arg0,
		C.int(arg1),
		(*C.int)(unsafe.Pointer(arg2)),
	)
}

func zetasql_ASTNode_find_child_index(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.int) {
	C.export_zetasql_ASTNode_find_child_index(arg0, arg1, arg2)
}

func ASTNode_DebugString(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTNode_DebugString(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTNode_DebugString(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTNode_DebugString(arg0, arg1, arg2)
}

func ASTNode_MoveStartLocation(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTNode_MoveStartLocation(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTNode_MoveStartLocation(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTNode_MoveStartLocation(arg0, arg1)
}

func ASTNode_MoveStartLocationBack(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTNode_MoveStartLocationBack(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTNode_MoveStartLocationBack(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTNode_MoveStartLocationBack(arg0, arg1)
}

func ASTNode_SetStartLocationToEndLocation(arg0 unsafe.Pointer) {
	zetasql_ASTNode_SetStartLocationToEndLocation(
		arg0,
	)
}

func zetasql_ASTNode_SetStartLocationToEndLocation(arg0 unsafe.Pointer) {
	C.export_zetasql_ASTNode_SetStartLocationToEndLocation(arg0)
}

func ASTNode_MoveEndLocationBack(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTNode_MoveEndLocationBack(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTNode_MoveEndLocationBack(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTNode_MoveEndLocationBack(arg0, arg1)
}

func ASTNode_set_start_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ASTNode_set_start_location(
		arg0,
		arg1,
	)
}

func zetasql_ASTNode_set_start_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ASTNode_set_start_location(arg0, arg1)
}

func ASTNode_set_end_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ASTNode_set_end_location(
		arg0,
		arg1,
	)
}

func zetasql_ASTNode_set_end_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ASTNode_set_end_location(arg0, arg1)
}

func ASTNode_IsTableExpression(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTNode_IsTableExpression(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNode_IsTableExpression(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTNode_IsTableExpression(arg0, arg1)
}

func ASTNode_IsQueryExpression(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTNode_IsQueryExpression(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNode_IsQueryExpression(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTNode_IsQueryExpression(arg0, arg1)
}

func ASTNode_IsExpression(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTNode_IsExpression(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNode_IsExpression(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTNode_IsExpression(arg0, arg1)
}

func ASTNode_IsType(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTNode_IsType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNode_IsType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTNode_IsType(arg0, arg1)
}

func ASTNode_IsLeaf(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTNode_IsLeaf(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNode_IsLeaf(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTNode_IsLeaf(arg0, arg1)
}

func ASTNode_IsStatement(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTNode_IsStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNode_IsStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTNode_IsStatement(arg0, arg1)
}

func ASTNode_IsScriptStatement(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTNode_IsScriptStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNode_IsScriptStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTNode_IsScriptStatement(arg0, arg1)
}

func ASTNode_IsLoopStatement(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTNode_IsLoopStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNode_IsLoopStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTNode_IsLoopStatement(arg0, arg1)
}

func ASTNode_IsSqlStatement(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTNode_IsSqlStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNode_IsSqlStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTNode_IsSqlStatement(arg0, arg1)
}

func ASTNode_IsDdlStatement(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTNode_IsDdlStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNode_IsDdlStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTNode_IsDdlStatement(arg0, arg1)
}

func ASTNode_IsCreateStatement(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTNode_IsCreateStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNode_IsCreateStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTNode_IsCreateStatement(arg0, arg1)
}

func ASTNode_IsAlterStatement(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTNode_IsAlterStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNode_IsAlterStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTNode_IsAlterStatement(arg0, arg1)
}

func ASTNode_GetNodeKindString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTNode_GetNodeKindString(
		arg0,
		arg1,
	)
}

func zetasql_ASTNode_GetNodeKindString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTNode_GetNodeKindString(arg0, arg1)
}

func ASTNode_GetParseLocationRange(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTNode_GetParseLocationRange(
		arg0,
		arg1,
	)
}

func zetasql_ASTNode_GetParseLocationRange(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTNode_GetParseLocationRange(arg0, arg1)
}

func ASTNode_GetLocationString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTNode_GetLocationString(
		arg0,
		arg1,
	)
}

func zetasql_ASTNode_GetLocationString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTNode_GetLocationString(arg0, arg1)
}

func ASTNode_NodeKindToString(arg0 int, arg1 *unsafe.Pointer) {
	zetasql_ASTNode_NodeKindToString(
		C.int(arg0),
		arg1,
	)
}

func zetasql_ASTNode_NodeKindToString(arg0 C.int, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTNode_NodeKindToString(arg0, arg1)
}

func ParseLocationPoint_filename(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ParseLocationPoint_filename(
		arg0,
		arg1,
	)
}

func zetasql_ParseLocationPoint_filename(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ParseLocationPoint_filename(arg0, arg1)
}

func ParseLocationPoint_GetByteOffset(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ParseLocationPoint_GetByteOffset(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ParseLocationPoint_GetByteOffset(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ParseLocationPoint_GetByteOffset(arg0, arg1)
}

func ParseLocationPoint_GetString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ParseLocationPoint_GetString(
		arg0,
		arg1,
	)
}

func zetasql_ParseLocationPoint_GetString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ParseLocationPoint_GetString(arg0, arg1)
}

func ParseLocationRange_start(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ParseLocationRange_start(
		arg0,
		arg1,
	)
}

func zetasql_ParseLocationRange_start(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ParseLocationRange_start(arg0, arg1)
}

func ParseLocationRange_end(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ParseLocationRange_end(
		arg0,
		arg1,
	)
}

func zetasql_ParseLocationRange_end(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ParseLocationRange_end(arg0, arg1)
}

func ParseLocationRange_GetString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ParseLocationRange_GetString(
		arg0,
		arg1,
	)
}

func zetasql_ParseLocationRange_GetString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ParseLocationRange_GetString(arg0, arg1)
}

func ASTQueryStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTQueryStatement_query(
		arg0,
		arg1,
	)
}

func zetasql_ASTQueryStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTQueryStatement_query(arg0, arg1)
}

func ASTQueryExpression_set_parenthesized(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTQueryExpression_set_parenthesized(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTQueryExpression_set_parenthesized(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTQueryExpression_set_parenthesized(arg0, arg1)
}

func ASTQueryExpression_parenthesized(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTQueryExpression_parenthesized(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTQueryExpression_parenthesized(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTQueryExpression_parenthesized(arg0, arg1)
}

func ASTQuery_set_is_nested(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTQuery_set_is_nested(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTQuery_set_is_nested(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTQuery_set_is_nested(arg0, arg1)
}

func ASTQuery_is_nested(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTQuery_is_nested(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTQuery_is_nested(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTQuery_is_nested(arg0, arg1)
}

func ASTQuery_set_is_pivot_input(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTQuery_set_is_pivot_input(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTQuery_set_is_pivot_input(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTQuery_set_is_pivot_input(arg0, arg1)
}

func ASTQuery_is_pivot_input(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTQuery_is_pivot_input(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTQuery_is_pivot_input(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTQuery_is_pivot_input(arg0, arg1)
}

func ASTQuery_with_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTQuery_with_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTQuery_with_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTQuery_with_clause(arg0, arg1)
}

func ASTQuery_query_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTQuery_query_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTQuery_query_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTQuery_query_expr(arg0, arg1)
}

func ASTQuery_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTQuery_order_by(
		arg0,
		arg1,
	)
}

func zetasql_ASTQuery_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTQuery_order_by(arg0, arg1)
}

func ASTQuery_limit_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTQuery_limit_offset(
		arg0,
		arg1,
	)
}

func zetasql_ASTQuery_limit_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTQuery_limit_offset(arg0, arg1)
}

func ASTSelect_set_distinct(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTSelect_set_distinct(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTSelect_set_distinct(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTSelect_set_distinct(arg0, arg1)
}

func ASTSelect_distinct(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTSelect_distinct(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTSelect_distinct(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTSelect_distinct(arg0, arg1)
}

func ASTSelect_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSelect_hint(
		arg0,
		arg1,
	)
}

func zetasql_ASTSelect_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSelect_hint(arg0, arg1)
}

func ASTSelect_anonymization_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSelect_anonymization_options(
		arg0,
		arg1,
	)
}

func zetasql_ASTSelect_anonymization_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSelect_anonymization_options(arg0, arg1)
}

func ASTSelect_select_as(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSelect_select_as(
		arg0,
		arg1,
	)
}

func zetasql_ASTSelect_select_as(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSelect_select_as(arg0, arg1)
}

func ASTSelect_select_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSelect_select_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTSelect_select_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSelect_select_list(arg0, arg1)
}

func ASTSelect_from_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSelect_from_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTSelect_from_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSelect_from_clause(arg0, arg1)
}

func ASTSelect_where_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSelect_where_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTSelect_where_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSelect_where_clause(arg0, arg1)
}

func ASTSelect_group_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSelect_group_by(
		arg0,
		arg1,
	)
}

func zetasql_ASTSelect_group_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSelect_group_by(arg0, arg1)
}

func ASTSelect_having(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSelect_having(
		arg0,
		arg1,
	)
}

func zetasql_ASTSelect_having(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSelect_having(arg0, arg1)
}

func ASTSelect_qualify(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSelect_qualify(
		arg0,
		arg1,
	)
}

func zetasql_ASTSelect_qualify(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSelect_qualify(arg0, arg1)
}

func ASTSelect_window_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSelect_window_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTSelect_window_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSelect_window_clause(arg0, arg1)
}

func ASTSelectList_column_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTSelectList_column_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTSelectList_column_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTSelectList_column_num(arg0, arg1)
}

func ASTSelectList_column(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTSelectList_column(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTSelectList_column(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTSelectList_column(arg0, arg1, arg2)
}

func ASTSelectColumn_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSelectColumn_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTSelectColumn_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSelectColumn_expression(arg0, arg1)
}

func ASTSelectColumn_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSelectColumn_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTSelectColumn_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSelectColumn_alias(arg0, arg1)
}

func ASTExpression_set_parenthesized(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTExpression_set_parenthesized(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTExpression_set_parenthesized(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTExpression_set_parenthesized(arg0, arg1)
}

func ASTExpression_parenthesized(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTExpression_parenthesized(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTExpression_parenthesized(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTExpression_parenthesized(arg0, arg1)
}

func ASTExpression_IsAllowedInComparison(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTExpression_IsAllowedInComparison(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTExpression_IsAllowedInComparison(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTExpression_IsAllowedInComparison(arg0, arg1)
}

func ASTLeaf_image(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTLeaf_image(
		arg0,
		arg1,
	)
}

func zetasql_ASTLeaf_image(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTLeaf_image(arg0, arg1)
}

func ASTLeaf_set_image(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ASTLeaf_set_image(
		arg0,
		arg1,
	)
}

func zetasql_ASTLeaf_set_image(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ASTLeaf_set_image(arg0, arg1)
}

func ASTIntLiteral_is_hex(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTIntLiteral_is_hex(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTIntLiteral_is_hex(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTIntLiteral_is_hex(arg0, arg1)
}

func ASTIdentifier_GetAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTIdentifier_GetAsString(
		arg0,
		arg1,
	)
}

func zetasql_ASTIdentifier_GetAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTIdentifier_GetAsString(arg0, arg1)
}

func ASTIdentifier_SetIdentifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ASTIdentifier_SetIdentifier(
		arg0,
		arg1,
	)
}

func zetasql_ASTIdentifier_SetIdentifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ASTIdentifier_SetIdentifier(arg0, arg1)
}

func ASTAlias_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlias_identifier(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlias_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlias_identifier(arg0, arg1)
}

func ASTAlias_GetAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlias_GetAsString(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlias_GetAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlias_GetAsString(arg0, arg1)
}

func ASTPathExpression_num_names(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTPathExpression_num_names(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTPathExpression_num_names(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTPathExpression_num_names(arg0, arg1)
}

func ASTPathExpression_name(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTPathExpression_name(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTPathExpression_name(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTPathExpression_name(arg0, arg1, arg2)
}

func ASTPathExpression_ToIdentifierPathString(arg0 unsafe.Pointer, arg1 uint32, arg2 *unsafe.Pointer) {
	zetasql_ASTPathExpression_ToIdentifierPathString(
		arg0,
		C.uint32_t(arg1),
		arg2,
	)
}

func zetasql_ASTPathExpression_ToIdentifierPathString(arg0 unsafe.Pointer, arg1 C.uint32_t, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTPathExpression_ToIdentifierPathString(arg0, arg1, arg2)
}

func ASTTablePathExpression_path_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTablePathExpression_path_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTTablePathExpression_path_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTablePathExpression_path_expr(arg0, arg1)
}

func ASTTablePathExpression_unnest_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTablePathExpression_unnest_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTTablePathExpression_unnest_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTablePathExpression_unnest_expr(arg0, arg1)
}

func ASTTablePathExpression_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTablePathExpression_hint(
		arg0,
		arg1,
	)
}

func zetasql_ASTTablePathExpression_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTablePathExpression_hint(arg0, arg1)
}

func ASTTablePathExpression_with_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTablePathExpression_with_offset(
		arg0,
		arg1,
	)
}

func zetasql_ASTTablePathExpression_with_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTablePathExpression_with_offset(arg0, arg1)
}

func ASTTablePathExpression_pivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTablePathExpression_pivot_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTTablePathExpression_pivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTablePathExpression_pivot_clause(arg0, arg1)
}

func ASTTablePathExpression_unpivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTablePathExpression_unpivot_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTTablePathExpression_unpivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTablePathExpression_unpivot_clause(arg0, arg1)
}

func ASTTablePathExpression_for_system_time(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTablePathExpression_for_system_time(
		arg0,
		arg1,
	)
}

func zetasql_ASTTablePathExpression_for_system_time(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTablePathExpression_for_system_time(arg0, arg1)
}

func ASTTablePathExpression_sample_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTablePathExpression_sample_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTTablePathExpression_sample_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTablePathExpression_sample_clause(arg0, arg1)
}

func ASTTablePathExpression_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTablePathExpression_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTTablePathExpression_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTablePathExpression_alias(arg0, arg1)
}

func ASTFromClause_table_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFromClause_table_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTFromClause_table_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFromClause_table_expression(arg0, arg1)
}

func ASTWhereClause_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWhereClause_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTWhereClause_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWhereClause_expression(arg0, arg1)
}

func ASTBooleanLiteral_set_value(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTBooleanLiteral_set_value(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTBooleanLiteral_set_value(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTBooleanLiteral_set_value(arg0, arg1)
}

func ASTBooleanLiteral_value(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTBooleanLiteral_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTBooleanLiteral_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTBooleanLiteral_value(arg0, arg1)
}

func ASTAndExpr_conjuncts_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTAndExpr_conjuncts_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAndExpr_conjuncts_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTAndExpr_conjuncts_num(arg0, arg1)
}

func ASTAndExpr_conjunct(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTAndExpr_conjunct(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTAndExpr_conjunct(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTAndExpr_conjunct(arg0, arg1, arg2)
}

func ASTBinaryExpression_set_op(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTBinaryExpression_set_op(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTBinaryExpression_set_op(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTBinaryExpression_set_op(arg0, arg1)
}

func ASTBinaryExpression_op(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTBinaryExpression_op(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTBinaryExpression_op(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTBinaryExpression_op(arg0, arg1)
}

func ASTBinaryExpression_set_is_not(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTBinaryExpression_set_is_not(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTBinaryExpression_set_is_not(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTBinaryExpression_set_is_not(arg0, arg1)
}

func ASTBinaryExpression_is_not(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTBinaryExpression_is_not(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTBinaryExpression_is_not(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTBinaryExpression_is_not(arg0, arg1)
}

func ASTBinaryExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTBinaryExpression_lhs(
		arg0,
		arg1,
	)
}

func zetasql_ASTBinaryExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTBinaryExpression_lhs(arg0, arg1)
}

func ASTBinaryExpression_rhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTBinaryExpression_rhs(
		arg0,
		arg1,
	)
}

func zetasql_ASTBinaryExpression_rhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTBinaryExpression_rhs(arg0, arg1)
}

func ASTBinaryExpression_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTBinaryExpression_GetSQLForOperator(
		arg0,
		arg1,
	)
}

func zetasql_ASTBinaryExpression_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTBinaryExpression_GetSQLForOperator(arg0, arg1)
}

func ASTStringLiteral_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTStringLiteral_string_value(
		arg0,
		arg1,
	)
}

func zetasql_ASTStringLiteral_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTStringLiteral_string_value(arg0, arg1)
}

func ASTStringLiteral_set_string_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ASTStringLiteral_set_string_value(
		arg0,
		arg1,
	)
}

func zetasql_ASTStringLiteral_set_string_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ASTStringLiteral_set_string_value(arg0, arg1)
}

func ASTOrExpr_disjuncts_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTOrExpr_disjuncts_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTOrExpr_disjuncts_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTOrExpr_disjuncts_num(arg0, arg1)
}

func ASTOrExpr_disjunct(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTOrExpr_disjunct(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTOrExpr_disjunct(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTOrExpr_disjunct(arg0, arg1, arg2)
}

func ASTGroupingItem_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTGroupingItem_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTGroupingItem_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTGroupingItem_expression(arg0, arg1)
}

func ASTGroupingItem_rollup(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTGroupingItem_rollup(
		arg0,
		arg1,
	)
}

func zetasql_ASTGroupingItem_rollup(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTGroupingItem_rollup(arg0, arg1)
}

func ASTGroupBy_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTGroupBy_hint(
		arg0,
		arg1,
	)
}

func zetasql_ASTGroupBy_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTGroupBy_hint(arg0, arg1)
}

func ASTGroupBy_grouping_items_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTGroupBy_grouping_items_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTGroupBy_grouping_items_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTGroupBy_grouping_items_num(arg0, arg1)
}

func ASTGroupBy_grouping_item(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTGroupBy_grouping_item(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTGroupBy_grouping_item(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTGroupBy_grouping_item(arg0, arg1, arg2)
}

func ASTOrderingExpression_set_ordering_spec(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTOrderingExpression_set_ordering_spec(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTOrderingExpression_set_ordering_spec(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTOrderingExpression_set_ordering_spec(arg0, arg1)
}

func ASTOrderingExpression_ordering_spec(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTOrderingExpression_ordering_spec(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTOrderingExpression_ordering_spec(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTOrderingExpression_ordering_spec(arg0, arg1)
}

func ASTOrderingExpression_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTOrderingExpression_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTOrderingExpression_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTOrderingExpression_expression(arg0, arg1)
}

func ASTOrderingExpression_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTOrderingExpression_collate(
		arg0,
		arg1,
	)
}

func zetasql_ASTOrderingExpression_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTOrderingExpression_collate(arg0, arg1)
}

func ASTOrderingExpression_null_order(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTOrderingExpression_null_order(
		arg0,
		arg1,
	)
}

func zetasql_ASTOrderingExpression_null_order(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTOrderingExpression_null_order(arg0, arg1)
}

func ASTOrderBy_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTOrderBy_hint(
		arg0,
		arg1,
	)
}

func zetasql_ASTOrderBy_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTOrderBy_hint(arg0, arg1)
}

func ASTOrderBy_ordering_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTOrderBy_ordering_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTOrderBy_ordering_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTOrderBy_ordering_expressions_num(arg0, arg1)
}

func ASTOrderBy_ordering_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTOrderBy_ordering_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTOrderBy_ordering_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTOrderBy_ordering_expression(arg0, arg1, arg2)
}

func ASTLimitOffset_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTLimitOffset_limit(
		arg0,
		arg1,
	)
}

func zetasql_ASTLimitOffset_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTLimitOffset_limit(arg0, arg1)
}

func ASTLimitOffset_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTLimitOffset_offset(
		arg0,
		arg1,
	)
}

func zetasql_ASTLimitOffset_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTLimitOffset_offset(arg0, arg1)
}

func ASTOnClause_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTOnClause_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTOnClause_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTOnClause_expression(arg0, arg1)
}

func ASTWithClauseEntry_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWithClauseEntry_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTWithClauseEntry_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWithClauseEntry_alias(arg0, arg1)
}

func ASTWithClauseEntry_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWithClauseEntry_query(
		arg0,
		arg1,
	)
}

func zetasql_ASTWithClauseEntry_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWithClauseEntry_query(arg0, arg1)
}

func ASTJoin_set_join_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTJoin_set_join_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTJoin_set_join_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTJoin_set_join_type(arg0, arg1)
}

func ASTJoin_join_type(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTJoin_join_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTJoin_join_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTJoin_join_type(arg0, arg1)
}

func ASTJoin_set_join_hint(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTJoin_set_join_hint(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTJoin_set_join_hint(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTJoin_set_join_hint(arg0, arg1)
}

func ASTJoin_join_hint(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTJoin_join_hint(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTJoin_join_hint(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTJoin_join_hint(arg0, arg1)
}

func ASTJoin_set_natural(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTJoin_set_natural(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTJoin_set_natural(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTJoin_set_natural(arg0, arg1)
}

func ASTJoin_natural(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTJoin_natural(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTJoin_natural(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTJoin_natural(arg0, arg1)
}

func ASTJoin_set_unmatched_join_count(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTJoin_set_unmatched_join_count(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTJoin_set_unmatched_join_count(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTJoin_set_unmatched_join_count(arg0, arg1)
}

func ASTJoin_unmatched_join_count(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTJoin_unmatched_join_count(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTJoin_unmatched_join_count(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTJoin_unmatched_join_count(arg0, arg1)
}

func ASTJoin_set_transformation_needed(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTJoin_set_transformation_needed(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTJoin_set_transformation_needed(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTJoin_set_transformation_needed(arg0, arg1)
}

func ASTJoin_transformation_needed(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTJoin_transformation_needed(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTJoin_transformation_needed(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTJoin_transformation_needed(arg0, arg1)
}

func ASTJoin_set_contains_comma_join(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTJoin_set_contains_comma_join(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTJoin_set_contains_comma_join(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTJoin_set_contains_comma_join(arg0, arg1)
}

func ASTJoin_contains_comma_join(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTJoin_contains_comma_join(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTJoin_contains_comma_join(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTJoin_contains_comma_join(arg0, arg1)
}

func ASTJoin_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTJoin_lhs(
		arg0,
		arg1,
	)
}

func zetasql_ASTJoin_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTJoin_lhs(arg0, arg1)
}

func ASTJoin_rhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTJoin_rhs(
		arg0,
		arg1,
	)
}

func zetasql_ASTJoin_rhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTJoin_rhs(arg0, arg1)
}

func ASTJoin_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTJoin_hint(
		arg0,
		arg1,
	)
}

func zetasql_ASTJoin_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTJoin_hint(arg0, arg1)
}

func ASTJoin_on_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTJoin_on_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTJoin_on_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTJoin_on_clause(arg0, arg1)
}

func ASTJoin_using_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTJoin_using_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTJoin_using_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTJoin_using_clause(arg0, arg1)
}

func JoinParseError_error_node(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_JoinParseError_error_node(
		arg0,
		arg1,
	)
}

func zetasql_JoinParseError_error_node(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_JoinParseError_error_node(arg0, arg1)
}

func JoinParseError_message(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_JoinParseError_message(
		arg0,
		arg1,
	)
}

func zetasql_JoinParseError_message(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_JoinParseError_message(arg0, arg1)
}

func ASTJoin_parse_error(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTJoin_parse_error(
		arg0,
		arg1,
	)
}

func zetasql_ASTJoin_parse_error(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTJoin_parse_error(arg0, arg1)
}

func ASTJoin_GetSQLForJoinType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTJoin_GetSQLForJoinType(
		arg0,
		arg1,
	)
}

func zetasql_ASTJoin_GetSQLForJoinType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTJoin_GetSQLForJoinType(arg0, arg1)
}

func ASTJoin_GetSQLForJoinHint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTJoin_GetSQLForJoinHint(
		arg0,
		arg1,
	)
}

func zetasql_ASTJoin_GetSQLForJoinHint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTJoin_GetSQLForJoinHint(arg0, arg1)
}

func ASTWithClause_set_recursive(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTWithClause_set_recursive(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTWithClause_set_recursive(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTWithClause_set_recursive(arg0, arg1)
}

func ASTWithClause_recursive(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTWithClause_recursive(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTWithClause_recursive(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTWithClause_recursive(arg0, arg1)
}

func ASTWithClause_with_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTWithClause_with_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTWithClause_with_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTWithClause_with_num(arg0, arg1)
}

func ASTWithClause_with(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTWithClause_with(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTWithClause_with(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTWithClause_with(arg0, arg1, arg2)
}

func ASTHaving_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTHaving_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTHaving_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTHaving_expression(arg0, arg1)
}

func ASTType_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTType_type_parameters(
		arg0,
		arg1,
	)
}

func zetasql_ASTType_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTType_type_parameters(arg0, arg1)
}

func ASTType_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTType_collate(
		arg0,
		arg1,
	)
}

func zetasql_ASTType_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTType_collate(arg0, arg1)
}

func ASTSimpleType_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSimpleType_type_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTSimpleType_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSimpleType_type_name(arg0, arg1)
}

func ASTArrayType_element_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTArrayType_element_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTArrayType_element_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTArrayType_element_type(arg0, arg1)
}

func ASTStructField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTStructField_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTStructField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTStructField_name(arg0, arg1)
}

func ASTStructField_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTStructField_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTStructField_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTStructField_type(arg0, arg1)
}

func ASTStructType_struct_fields_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTStructType_struct_fields_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTStructType_struct_fields_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTStructType_struct_fields_num(arg0, arg1)
}

func ASTStructType_struct_field(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTStructType_struct_field(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTStructType_struct_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTStructType_struct_field(arg0, arg1, arg2)
}

func ASTCastExpression_set_is_safe_cast(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTCastExpression_set_is_safe_cast(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTCastExpression_set_is_safe_cast(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTCastExpression_set_is_safe_cast(arg0, arg1)
}

func ASTCastExpression_is_safe_cast(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTCastExpression_is_safe_cast(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCastExpression_is_safe_cast(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTCastExpression_is_safe_cast(arg0, arg1)
}

func ASTCastExpression_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCastExpression_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTCastExpression_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCastExpression_expr(arg0, arg1)
}

func ASTCastExpression_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCastExpression_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTCastExpression_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCastExpression_type(arg0, arg1)
}

func ASTCastExpression_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCastExpression_format(
		arg0,
		arg1,
	)
}

func zetasql_ASTCastExpression_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCastExpression_format(arg0, arg1)
}

func ASTSelectAs_set_as_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTSelectAs_set_as_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTSelectAs_set_as_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTSelectAs_set_as_mode(arg0, arg1)
}

func ASTSelectAs_as_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTSelectAs_as_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTSelectAs_as_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTSelectAs_as_mode(arg0, arg1)
}

func ASTSelectAs_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSelectAs_type_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTSelectAs_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSelectAs_type_name(arg0, arg1)
}

func ASTSelectAs_is_select_as_struct(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTSelectAs_is_select_as_struct(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTSelectAs_is_select_as_struct(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTSelectAs_is_select_as_struct(arg0, arg1)
}

func ASTSelectAs_is_select_as_value(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTSelectAs_is_select_as_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTSelectAs_is_select_as_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTSelectAs_is_select_as_value(arg0, arg1)
}

func ASTRollup_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTRollup_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTRollup_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTRollup_expressions_num(arg0, arg1)
}

func ASTRollup_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTRollup_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTRollup_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTRollup_expression(arg0, arg1, arg2)
}

func ASTFunctionCall_set_null_handling_modifier(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTFunctionCall_set_null_handling_modifier(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTFunctionCall_set_null_handling_modifier(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTFunctionCall_set_null_handling_modifier(arg0, arg1)
}

func ASTFunctionCall_null_handling_modifier(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTFunctionCall_null_handling_modifier(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTFunctionCall_null_handling_modifier(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTFunctionCall_null_handling_modifier(arg0, arg1)
}

func ASTFunctionCall_set_distinct(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTFunctionCall_set_distinct(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTFunctionCall_set_distinct(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTFunctionCall_set_distinct(arg0, arg1)
}

func ASTFunctionCall_distinct(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTFunctionCall_distinct(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTFunctionCall_distinct(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTFunctionCall_distinct(arg0, arg1)
}

func ASTFunctionCall_set_is_current_date_time_without_parentheses(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTFunctionCall_set_is_current_date_time_without_parentheses(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTFunctionCall_set_is_current_date_time_without_parentheses(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTFunctionCall_set_is_current_date_time_without_parentheses(arg0, arg1)
}

func ASTFunctionCall_is_current_date_time_without_parentheses(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTFunctionCall_is_current_date_time_without_parentheses(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTFunctionCall_is_current_date_time_without_parentheses(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTFunctionCall_is_current_date_time_without_parentheses(arg0, arg1)
}

func ASTFunctionCall_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionCall_function(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionCall_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionCall_function(arg0, arg1)
}

func ASTFunctionCall_having_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionCall_having_modifier(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionCall_having_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionCall_having_modifier(arg0, arg1)
}

func ASTFunctionCall_clamped_between_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionCall_clamped_between_modifier(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionCall_clamped_between_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionCall_clamped_between_modifier(arg0, arg1)
}

func ASTFunctionCall_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionCall_order_by(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionCall_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionCall_order_by(arg0, arg1)
}

func ASTFunctionCall_limit_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionCall_limit_offset(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionCall_limit_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionCall_limit_offset(arg0, arg1)
}

func ASTFunctionCall_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionCall_hint(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionCall_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionCall_hint(arg0, arg1)
}

func ASTFunctionCall_with_group_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionCall_with_group_rows(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionCall_with_group_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionCall_with_group_rows(arg0, arg1)
}

func ASTFunctionCall_arguments_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTFunctionCall_arguments_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTFunctionCall_arguments_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTFunctionCall_arguments_num(arg0, arg1)
}

func ASTFunctionCall_argument(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTFunctionCall_argument(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTFunctionCall_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionCall_argument(arg0, arg1, arg2)
}

func ASTFunctionCall_HasModifiers(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTFunctionCall_HasModifiers(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTFunctionCall_HasModifiers(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTFunctionCall_HasModifiers(arg0, arg1)
}

func ASTArrayConstructor_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTArrayConstructor_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTArrayConstructor_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTArrayConstructor_type(arg0, arg1)
}

func ASTArrayConstructor_elements_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTArrayConstructor_elements_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTArrayConstructor_elements_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTArrayConstructor_elements_num(arg0, arg1)
}

func ASTArrayConstructor_element(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTArrayConstructor_element(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTArrayConstructor_element(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTArrayConstructor_element(arg0, arg1, arg2)
}

func ASTStructConstructorArg_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTStructConstructorArg_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTStructConstructorArg_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTStructConstructorArg_expression(arg0, arg1)
}

func ASTStructConstructorArg_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTStructConstructorArg_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTStructConstructorArg_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTStructConstructorArg_alias(arg0, arg1)
}

func ASTStructConstructorWithParens_field_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTStructConstructorWithParens_field_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTStructConstructorWithParens_field_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTStructConstructorWithParens_field_expressions_num(arg0, arg1)
}

func ASTStructConstructorWithParens_field_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTStructConstructorWithParens_field_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTStructConstructorWithParens_field_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTStructConstructorWithParens_field_expression(arg0, arg1, arg2)
}

func ASTStructConstructorWithKeyword_struct_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTStructConstructorWithKeyword_struct_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTStructConstructorWithKeyword_struct_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTStructConstructorWithKeyword_struct_type(arg0, arg1)
}

func ASTStructConstructorWithKeyword_fields_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTStructConstructorWithKeyword_fields_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTStructConstructorWithKeyword_fields_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTStructConstructorWithKeyword_fields_num(arg0, arg1)
}

func ASTStructConstructorWithKeyword_field(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTStructConstructorWithKeyword_field(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTStructConstructorWithKeyword_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTStructConstructorWithKeyword_field(arg0, arg1, arg2)
}

func ASTInExpression_set_is_not(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTInExpression_set_is_not(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTInExpression_set_is_not(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTInExpression_set_is_not(arg0, arg1)
}

func ASTInExpression_is_not(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTInExpression_is_not(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTInExpression_is_not(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTInExpression_is_not(arg0, arg1)
}

func ASTInExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTInExpression_lhs(
		arg0,
		arg1,
	)
}

func zetasql_ASTInExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTInExpression_lhs(arg0, arg1)
}

func ASTInExpression_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTInExpression_hint(
		arg0,
		arg1,
	)
}

func zetasql_ASTInExpression_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTInExpression_hint(arg0, arg1)
}

func ASTInExpression_in_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTInExpression_in_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTInExpression_in_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTInExpression_in_list(arg0, arg1)
}

func ASTInExpression_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTInExpression_query(
		arg0,
		arg1,
	)
}

func zetasql_ASTInExpression_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTInExpression_query(arg0, arg1)
}

func ASTInExpression_unnest_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTInExpression_unnest_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTInExpression_unnest_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTInExpression_unnest_expr(arg0, arg1)
}

func ASTInList_list_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTInList_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTInList_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTInList_list_num(arg0, arg1)
}

func ASTInList_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTInList_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTInList_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTInList_list(arg0, arg1, arg2)
}

func ASTBetweenExpression_set_is_not(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTBetweenExpression_set_is_not(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTBetweenExpression_set_is_not(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTBetweenExpression_set_is_not(arg0, arg1)
}

func ASTBetweenExpression_is_not(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTBetweenExpression_is_not(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTBetweenExpression_is_not(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTBetweenExpression_is_not(arg0, arg1)
}

func ASTBetweenExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTBetweenExpression_lhs(
		arg0,
		arg1,
	)
}

func zetasql_ASTBetweenExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTBetweenExpression_lhs(arg0, arg1)
}

func ASTBetweenExpression_low(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTBetweenExpression_low(
		arg0,
		arg1,
	)
}

func zetasql_ASTBetweenExpression_low(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTBetweenExpression_low(arg0, arg1)
}

func ASTBetweenExpression_high(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTBetweenExpression_high(
		arg0,
		arg1,
	)
}

func zetasql_ASTBetweenExpression_high(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTBetweenExpression_high(arg0, arg1)
}

func ASTDateOrTimeLiteral_set_type_kind(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDateOrTimeLiteral_set_type_kind(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDateOrTimeLiteral_set_type_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDateOrTimeLiteral_set_type_kind(arg0, arg1)
}

func ASTDateOrTimeLiteral_type_kind(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTDateOrTimeLiteral_type_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDateOrTimeLiteral_type_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTDateOrTimeLiteral_type_kind(arg0, arg1)
}

func ASTDateOrTimeLiteral_string_literal(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDateOrTimeLiteral_string_literal(
		arg0,
		arg1,
	)
}

func zetasql_ASTDateOrTimeLiteral_string_literal(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDateOrTimeLiteral_string_literal(arg0, arg1)
}

func ASTCaseValueExpression_arguments_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTCaseValueExpression_arguments_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCaseValueExpression_arguments_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTCaseValueExpression_arguments_num(arg0, arg1)
}

func ASTCaseValueExpression_argument(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTCaseValueExpression_argument(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTCaseValueExpression_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTCaseValueExpression_argument(arg0, arg1, arg2)
}

func ASTCaseNoValueExpression_arguments_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTCaseNoValueExpression_arguments_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCaseNoValueExpression_arguments_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTCaseNoValueExpression_arguments_num(arg0, arg1)
}

func ASTCaseNoValueExpression_argument(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTCaseNoValueExpression_argument(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTCaseNoValueExpression_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTCaseNoValueExpression_argument(arg0, arg1, arg2)
}

func ASTArrayElement_array(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTArrayElement_array(
		arg0,
		arg1,
	)
}

func zetasql_ASTArrayElement_array(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTArrayElement_array(arg0, arg1)
}

func ASTArrayElement_position(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTArrayElement_position(
		arg0,
		arg1,
	)
}

func zetasql_ASTArrayElement_position(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTArrayElement_position(arg0, arg1)
}

func ASTBitwiseShiftExpression_set_is_left_shift(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTBitwiseShiftExpression_set_is_left_shift(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTBitwiseShiftExpression_set_is_left_shift(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTBitwiseShiftExpression_set_is_left_shift(arg0, arg1)
}

func ASTBitwiseShiftExpression_is_left_shift(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTBitwiseShiftExpression_is_left_shift(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTBitwiseShiftExpression_is_left_shift(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTBitwiseShiftExpression_is_left_shift(arg0, arg1)
}

func ASTBitwiseShiftExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTBitwiseShiftExpression_lhs(
		arg0,
		arg1,
	)
}

func zetasql_ASTBitwiseShiftExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTBitwiseShiftExpression_lhs(arg0, arg1)
}

func ASTBitwiseShiftExpression_rhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTBitwiseShiftExpression_rhs(
		arg0,
		arg1,
	)
}

func zetasql_ASTBitwiseShiftExpression_rhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTBitwiseShiftExpression_rhs(arg0, arg1)
}

func ASTCollate_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCollate_collation_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTCollate_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCollate_collation_name(arg0, arg1)
}

func ASTDotGeneralizedField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDotGeneralizedField_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTDotGeneralizedField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDotGeneralizedField_expr(arg0, arg1)
}

func ASTDotGeneralizedField_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDotGeneralizedField_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTDotGeneralizedField_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDotGeneralizedField_path(arg0, arg1)
}

func ASTDotIdentifier_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDotIdentifier_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTDotIdentifier_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDotIdentifier_expr(arg0, arg1)
}

func ASTDotIdentifier_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDotIdentifier_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDotIdentifier_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDotIdentifier_name(arg0, arg1)
}

func ASTDotStar_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDotStar_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTDotStar_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDotStar_expr(arg0, arg1)
}

func ASTDotStarWithModifiers_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDotStarWithModifiers_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTDotStarWithModifiers_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDotStarWithModifiers_expr(arg0, arg1)
}

func ASTDotStarWithModifiers_modifiers(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDotStarWithModifiers_modifiers(
		arg0,
		arg1,
	)
}

func zetasql_ASTDotStarWithModifiers_modifiers(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDotStarWithModifiers_modifiers(arg0, arg1)
}

func ASTExpressionSubquery_set_modifier(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTExpressionSubquery_set_modifier(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTExpressionSubquery_set_modifier(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTExpressionSubquery_set_modifier(arg0, arg1)
}

func ASTExpressionSubquery_modifier(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTExpressionSubquery_modifier(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTExpressionSubquery_modifier(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTExpressionSubquery_modifier(arg0, arg1)
}

func ASTExpressionSubquery_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExpressionSubquery_hint(
		arg0,
		arg1,
	)
}

func zetasql_ASTExpressionSubquery_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExpressionSubquery_hint(arg0, arg1)
}

func ASTExpressionSubquery_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExpressionSubquery_query(
		arg0,
		arg1,
	)
}

func zetasql_ASTExpressionSubquery_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExpressionSubquery_query(arg0, arg1)
}

func ASTExtractExpression_lhs_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExtractExpression_lhs_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTExtractExpression_lhs_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExtractExpression_lhs_expr(arg0, arg1)
}

func ASTExtractExpression_rhs_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExtractExpression_rhs_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTExtractExpression_rhs_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExtractExpression_rhs_expr(arg0, arg1)
}

func ASTExtractExpression_time_zone_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExtractExpression_time_zone_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTExtractExpression_time_zone_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExtractExpression_time_zone_expr(arg0, arg1)
}

func ASTHavingModifier_set_modifier_kind(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTHavingModifier_set_modifier_kind(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTHavingModifier_set_modifier_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTHavingModifier_set_modifier_kind(arg0, arg1)
}

func ASTHavingModifier_modifier_kind(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTHavingModifier_modifier_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTHavingModifier_modifier_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTHavingModifier_modifier_kind(arg0, arg1)
}

func ASTHavingModifier_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTHavingModifier_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTHavingModifier_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTHavingModifier_expr(arg0, arg1)
}

func ASTIntervalExpr_interval_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTIntervalExpr_interval_value(
		arg0,
		arg1,
	)
}

func zetasql_ASTIntervalExpr_interval_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTIntervalExpr_interval_value(arg0, arg1)
}

func ASTIntervalExpr_date_part_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTIntervalExpr_date_part_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTIntervalExpr_date_part_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTIntervalExpr_date_part_name(arg0, arg1)
}

func ASTIntervalExpr_date_part_name_to(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTIntervalExpr_date_part_name_to(
		arg0,
		arg1,
	)
}

func zetasql_ASTIntervalExpr_date_part_name_to(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTIntervalExpr_date_part_name_to(arg0, arg1)
}

func ASTNamedArgument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTNamedArgument_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTNamedArgument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTNamedArgument_name(arg0, arg1)
}

func ASTNamedArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTNamedArgument_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTNamedArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTNamedArgument_expr(arg0, arg1)
}

func ASTNullOrder_set_nulls_first(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTNullOrder_set_nulls_first(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTNullOrder_set_nulls_first(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTNullOrder_set_nulls_first(arg0, arg1)
}

func ASTNullOrder_nulls_first(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTNullOrder_nulls_first(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNullOrder_nulls_first(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTNullOrder_nulls_first(arg0, arg1)
}

func ASTOnOrUsingClauseList_on_or_using_clause_list_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTOnOrUsingClauseList_on_or_using_clause_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTOnOrUsingClauseList_on_or_using_clause_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTOnOrUsingClauseList_on_or_using_clause_list_num(arg0, arg1)
}

func ASTOnUsingClauseList_on_or_using_clause_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTOnUsingClauseList_on_or_using_clause_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTOnUsingClauseList_on_or_using_clause_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTOnUsingClauseList_on_or_using_clause_list(arg0, arg1, arg2)
}

func ASTParenthesizedJoin_join(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTParenthesizedJoin_join(
		arg0,
		arg1,
	)
}

func zetasql_ASTParenthesizedJoin_join(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTParenthesizedJoin_join(arg0, arg1)
}

func ASTParenthesizedJoin_sample_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTParenthesizedJoin_sample_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTParenthesizedJoin_sample_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTParenthesizedJoin_sample_clause(arg0, arg1)
}

func ASTPartitionBy_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTPartitionBy_hint(
		arg0,
		arg1,
	)
}

func zetasql_ASTPartitionBy_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTPartitionBy_hint(arg0, arg1)
}

func ASTPartitionBy_partitioning_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTPartitionBy_partitioning_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTPartitionBy_partitioning_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTPartitionBy_partitioning_expressions_num(arg0, arg1)
}

func ASTPartitionBy_partitioning_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTPartitionBy_partitioning_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTPartitionBy_partitioning_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTPartitionBy_partitioning_expression(arg0, arg1, arg2)
}

func ASTSetOperation_set_op_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTSetOperation_set_op_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTSetOperation_set_op_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTSetOperation_set_op_type(arg0, arg1)
}

func ASTSetOperation_op_type(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTSetOperation_op_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTSetOperation_op_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTSetOperation_op_type(arg0, arg1)
}

func ASTSetOperation_set_distinct(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTSetOperation_set_distinct(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTSetOperation_set_distinct(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTSetOperation_set_distinct(arg0, arg1)
}

func ASTSetOperation_distinct(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTSetOperation_distinct(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTSetOperation_distinct(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTSetOperation_distinct(arg0, arg1)
}

func ASTSetOperation_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSetOperation_hint(
		arg0,
		arg1,
	)
}

func zetasql_ASTSetOperation_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSetOperation_hint(arg0, arg1)
}

func ASTSetOperation_inputs_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTSetOperation_inputs_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTSetOperation_inputs_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTSetOperation_inputs_num(arg0, arg1)
}

func ASTSetOperation_input(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTSetOperation_input(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTSetOperation_input(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTSetOperation_input(arg0, arg1, arg2)
}

func ASTSetOperation_GetSQLForOperation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSetOperation_GetSQLForOperation(
		arg0,
		arg1,
	)
}

func zetasql_ASTSetOperation_GetSQLForOperation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSetOperation_GetSQLForOperation(arg0, arg1)
}

func ASTStarExceptList_identifiers_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTStarExceptList_identifiers_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTStarExceptList_identifiers_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTStarExceptList_identifiers_num(arg0, arg1)
}

func ASTStarExpcetList_identifier(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTStarExpcetList_identifier(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTStarExpcetList_identifier(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTStarExpcetList_identifier(arg0, arg1, arg2)
}

func ASTStarModifiers_except_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTStarModifiers_except_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTStarModifiers_except_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTStarModifiers_except_list(arg0, arg1)
}

func ASTStarModifiers_replace_items_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTStarModifiers_replace_items_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTStarModifiers_replace_items_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTStarModifiers_replace_items_num(arg0, arg1)
}

func ASTStarModifiers_replace_item(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTStarModifiers_replace_item(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTStarModifiers_replace_item(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTStarModifiers_replace_item(arg0, arg1, arg2)
}

func ASTStarReplaceItem_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTStarReplaceItem_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTStarReplaceItem_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTStarReplaceItem_expression(arg0, arg1)
}

func ASTStarReplaceItem_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTStarReplaceItem_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTStarReplaceItem_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTStarReplaceItem_alias(arg0, arg1)
}

func ASTStarWithModifiers_modifiers(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTStarWithModifiers_modifiers(
		arg0,
		arg1,
	)
}

func zetasql_ASTStarWithModifiers_modifiers(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTStarWithModifiers_modifiers(arg0, arg1)
}

func ASTTableSubquery_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTableSubquery_subquery(
		arg0,
		arg1,
	)
}

func zetasql_ASTTableSubquery_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTableSubquery_subquery(arg0, arg1)
}

func ASTTableSubquery_pivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTableSubquery_pivot_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTTableSubquery_pivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTableSubquery_pivot_clause(arg0, arg1)
}

func ASTTableSubquery_unpivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTableSubquery_unpivot_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTTableSubquery_unpivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTableSubquery_unpivot_clause(arg0, arg1)
}

func ASTTableSubquery_sample_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTableSubquery_sample_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTTableSubquery_sample_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTableSubquery_sample_clause(arg0, arg1)
}

func ASTTableSubquery_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTableSubquery_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTTableSubquery_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTableSubquery_alias(arg0, arg1)
}

func ASTUnaryExpression_set_op(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTUnaryExpression_set_op(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTUnaryExpression_set_op(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTUnaryExpression_set_op(arg0, arg1)
}

func ASTUnaryExpression_op(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTUnaryExpression_op(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTUnaryExpression_op(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTUnaryExpression_op(arg0, arg1)
}

func ASTUnaryExpression_operand(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUnaryExpression_operand(
		arg0,
		arg1,
	)
}

func zetasql_ASTUnaryExpression_operand(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUnaryExpression_operand(arg0, arg1)
}

func ASTUnaryExpression_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUnaryExpression_GetSQLForOperator(
		arg0,
		arg1,
	)
}

func zetasql_ASTUnaryExpression_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUnaryExpression_GetSQLForOperator(arg0, arg1)
}

func ASTUnnestExpression_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUnnestExpression_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTUnnestExpression_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUnnestExpression_expression(arg0, arg1)
}

func ASTWindowClause_windows_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTWindowClause_windows_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTWindowClause_windows_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTWindowClause_windows_num(arg0, arg1)
}

func ASTWindowClause_window(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTWindowClause_window(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTWindowClause_window(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTWindowClause_window(arg0, arg1, arg2)
}

func ASTWindowDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWindowDefinition_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTWindowDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWindowDefinition_name(arg0, arg1)
}

func ASTWindowDefinition_window_spec(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWindowDefinition_window_spec(
		arg0,
		arg1,
	)
}

func zetasql_ASTWindowDefinition_window_spec(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWindowDefinition_window_spec(arg0, arg1)
}

func ASTWindowFrame_start_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWindowFrame_start_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTWindowFrame_start_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWindowFrame_start_expr(arg0, arg1)
}

func ASTWindowFrame_end_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWindowFrame_end_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTWindowFrame_end_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWindowFrame_end_expr(arg0, arg1)
}

func ASTWindowFrame_set_unit(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTWindowFrame_set_unit(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTWindowFrame_set_unit(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTWindowFrame_set_unit(arg0, arg1)
}

func ASTWindowFrame_frame_unit(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTWindowFrame_frame_unit(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTWindowFrame_frame_unit(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTWindowFrame_frame_unit(arg0, arg1)
}

func ASTWindowFrame_GetFrameUnitString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWindowFrame_GetFrameUnitString(
		arg0,
		arg1,
	)
}

func zetasql_ASTWindowFrame_GetFrameUnitString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWindowFrame_GetFrameUnitString(arg0, arg1)
}

func ASTWindowFrameExpr_set_boundary_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTWindowFrameExpr_set_boundary_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTWindowFrameExpr_set_boundary_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTWindowFrameExpr_set_boundary_type(arg0, arg1)
}

func ASTWindowFrameExpr_boundary_type(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTWindowFrameExpr_boundary_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTWindowFrameExpr_boundary_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTWindowFrameExpr_boundary_type(arg0, arg1)
}

func ASTWindowFrameExpr_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWindowFrameExpr_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTWindowFrameExpr_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWindowFrameExpr_expression(arg0, arg1)
}

func ASTLikeExpression_set_is_not(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTLikeExpression_set_is_not(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTLikeExpression_set_is_not(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTLikeExpression_set_is_not(arg0, arg1)
}

func ASTLikeExpression_is_not(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTLikeExpression_is_not(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTLikeExpression_is_not(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTLikeExpression_is_not(arg0, arg1)
}

func ASTLikeExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTLikeExpression_lhs(
		arg0,
		arg1,
	)
}

func zetasql_ASTLikeExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTLikeExpression_lhs(arg0, arg1)
}

func ASTLikeExpression_op(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTLikeExpression_op(
		arg0,
		arg1,
	)
}

func zetasql_ASTLikeExpression_op(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTLikeExpression_op(arg0, arg1)
}

func ASTLikeExpression_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTLikeExpression_hint(
		arg0,
		arg1,
	)
}

func zetasql_ASTLikeExpression_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTLikeExpression_hint(arg0, arg1)
}

func ASTLikeExpression_in_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTLikeExpression_in_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTLikeExpression_in_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTLikeExpression_in_list(arg0, arg1)
}

func ASTLikeExpression_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTLikeExpression_query(
		arg0,
		arg1,
	)
}

func zetasql_ASTLikeExpression_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTLikeExpression_query(arg0, arg1)
}

func ASTLikeExpression_unnest_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTLikeExpression_unnest_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTLikeExpression_unnest_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTLikeExpression_unnest_expr(arg0, arg1)
}

func ASTWindowSpecification_base_window_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWindowSpecification_base_window_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTWindowSpecification_base_window_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWindowSpecification_base_window_name(arg0, arg1)
}

func ASTWindowSpecification_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWindowSpecification_partition_by(
		arg0,
		arg1,
	)
}

func zetasql_ASTWindowSpecification_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWindowSpecification_partition_by(arg0, arg1)
}

func ASTWindowSpecification_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWindowSpecification_order_by(
		arg0,
		arg1,
	)
}

func zetasql_ASTWindowSpecification_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWindowSpecification_order_by(arg0, arg1)
}

func ASTWindowSpecification_window_frame(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWindowSpecification_window_frame(
		arg0,
		arg1,
	)
}

func zetasql_ASTWindowSpecification_window_frame(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWindowSpecification_window_frame(arg0, arg1)
}

func ASTWithOffset_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWithOffset_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTWithOffset_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWithOffset_alias(arg0, arg1)
}

func ASTAnySomeAllOp_set_op(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTAnySomeAllOp_set_op(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTAnySomeAllOp_set_op(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTAnySomeAllOp_set_op(arg0, arg1)
}

func ASTAnySomeAllOp_op(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTAnySomeAllOp_op(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAnySomeAllOp_op(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTAnySomeAllOp_op(arg0, arg1)
}

func ASTAnySomeAllOp_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAnySomeAllOp_GetSQLForOperator(
		arg0,
		arg1,
	)
}

func zetasql_ASTAnySomeAllOp_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAnySomeAllOp_GetSQLForOperator(arg0, arg1)
}

func ASTStatementList_set_variable_declarations_allowed(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTStatementList_set_variable_declarations_allowed(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTStatementList_set_variable_declarations_allowed(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTStatementList_set_variable_declarations_allowed(arg0, arg1)
}

func ASTStatementList_variable_declarations_allowed(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTStatementList_variable_declarations_allowed(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTStatementList_variable_declarations_allowed(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTStatementList_variable_declarations_allowed(arg0, arg1)
}

func ASTStatementList_statement_list_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTStatementList_statement_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTStatementList_statement_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTStatementList_statement_list_num(arg0, arg1)
}

func ASTStatementList_statement_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTStatementList_statement_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTStatementList_statement_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTStatementList_statement_list(arg0, arg1, arg2)
}

func ASTHintedStatement_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTHintedStatement_hint(
		arg0,
		arg1,
	)
}

func zetasql_ASTHintedStatement_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTHintedStatement_hint(arg0, arg1)
}

func ASTHintedStatement_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTHintedStatement_statement(
		arg0,
		arg1,
	)
}

func zetasql_ASTHintedStatement_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTHintedStatement_statement(arg0, arg1)
}

func ASTExplainStatement_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExplainStatement_statement(
		arg0,
		arg1,
	)
}

func zetasql_ASTExplainStatement_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExplainStatement_statement(arg0, arg1)
}

func ASTDescribeStatement_optional_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDescribeStatement_optional_identifier(
		arg0,
		arg1,
	)
}

func zetasql_ASTDescribeStatement_optional_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDescribeStatement_optional_identifier(arg0, arg1)
}

func ASTDescribeStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDescribeStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDescribeStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDescribeStatement_name(arg0, arg1)
}

func ASTDescribeStatement_optional_from_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDescribeStatement_optional_from_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDescribeStatement_optional_from_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDescribeStatement_optional_from_name(arg0, arg1)
}

func ASTShowStatement_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTShowStatement_identifier(
		arg0,
		arg1,
	)
}

func zetasql_ASTShowStatement_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTShowStatement_identifier(arg0, arg1)
}

func ASTShowStatement_optional_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTShowStatement_optional_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTShowStatement_optional_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTShowStatement_optional_name(arg0, arg1)
}

func ASTShowStatement_optional_like_string(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTShowStatement_optional_like_string(
		arg0,
		arg1,
	)
}

func zetasql_ASTShowStatement_optional_like_string(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTShowStatement_optional_like_string(arg0, arg1)
}

func ASTTransactionIsolationLevel_identifier1(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTransactionIsolationLevel_identifier1(
		arg0,
		arg1,
	)
}

func zetasql_ASTTransactionIsolationLevel_identifier1(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTransactionIsolationLevel_identifier1(arg0, arg1)
}

func ASTTransactionIsolationLevel_identifier2(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTransactionIsolationLevel_identifier2(
		arg0,
		arg1,
	)
}

func zetasql_ASTTransactionIsolationLevel_identifier2(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTransactionIsolationLevel_identifier2(arg0, arg1)
}

func ASTTransactionReadWriteMode_set_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTTransactionReadWriteMode_set_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTTransactionReadWriteMode_set_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTTransactionReadWriteMode_set_mode(arg0, arg1)
}

func ASTTransactionReadWriteMode_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTTransactionReadWriteMode_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTTransactionReadWriteMode_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTTransactionReadWriteMode_mode(arg0, arg1)
}

func ASTTransactionModeList_elements_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTTransactionModeList_elements_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTTransactionModeList_elements_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTTransactionModeList_elements_num(arg0, arg1)
}

func ASTTransactionModeList_element(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTTransactionModeList_element(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTTransactionModeList_element(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTTransactionModeList_element(arg0, arg1, arg2)
}

func ASTBeginStatement_mode_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTBeginStatement_mode_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTBeginStatement_mode_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTBeginStatement_mode_list(arg0, arg1)
}

func ASTSetTransactionStatement_mode_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSetTransactionStatement_mode_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTSetTransactionStatement_mode_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSetTransactionStatement_mode_list(arg0, arg1)
}

func ASTStartBatchStatement_batch_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTStartBatchStatement_batch_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTStartBatchStatement_batch_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTStartBatchStatement_batch_type(arg0, arg1)
}

func ASTDdlStatement_GetDdlTarget(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDdlStatement_GetDdlTarget(
		arg0,
		arg1,
	)
}

func zetasql_ASTDdlStatement_GetDdlTarget(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDdlStatement_GetDdlTarget(arg0, arg1)
}

func ASTDropEntityStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDropEntityStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDropEntityStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDropEntityStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropEntityStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTDropEntityStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDropEntityStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTDropEntityStatement_is_if_exists(arg0, arg1)
}

func ASTDropEntityStatement_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropEntityStatement_entity_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropEntityStatement_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropEntityStatement_entity_type(arg0, arg1)
}

func ASTDropEntityStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropEntityStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropEntityStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropEntityStatement_name(arg0, arg1)
}

func ASTDropFunctionStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDropFunctionStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDropFunctionStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDropFunctionStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropFunctionStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTDropFunctionStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDropFunctionStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTDropFunctionStatement_is_if_exists(arg0, arg1)
}

func ASTDropFunctionStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropFunctionStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropFunctionStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropFunctionStatement_name(arg0, arg1)
}

func ASTDropFunctionStatement_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropFunctionStatement_parameters(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropFunctionStatement_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropFunctionStatement_parameters(arg0, arg1)
}

func ASTDropTableFunctionStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDropTableFunctionStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDropTableFunctionStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDropTableFunctionStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropTableFunctionStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTDropTableFunctionStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDropTableFunctionStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTDropTableFunctionStatement_is_if_exists(arg0, arg1)
}

func ASTDropTableFunctionStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropTableFunctionStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropTableFunctionStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropTableFunctionStatement_name(arg0, arg1)
}

func ASTDropAllRowAccessPoliciesStatement_set_has_access_keyword(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDropAllRowAccessPoliciesStatement_set_has_access_keyword(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDropAllRowAccessPoliciesStatement_set_has_access_keyword(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDropAllRowAccessPoliciesStatement_set_has_access_keyword(arg0, arg1)
}

func ASTDropAllRowAccessPoliciesStatement_has_access_keyword(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTDropAllRowAccessPoliciesStatement_has_access_keyword(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDropAllRowAccessPoliciesStatement_has_access_keyword(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTDropAllRowAccessPoliciesStatement_has_access_keyword(arg0, arg1)
}

func ASTDropAllRowAccessPoliciesStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropAllRowAccessPoliciesStatement_table_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropAllRowAccessPoliciesStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropAllRowAccessPoliciesStatement_table_name(arg0, arg1)
}

func ASTDropMaterializedViewStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDropMaterializedViewStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDropMaterializedViewStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDropMaterializedViewStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropMaterializedViewStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTDropMaterializedViewStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDropMaterializedViewStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTDropMaterializedViewStatement_is_if_exists(arg0, arg1)
}

func ASTDropMaterializedViewStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropMaterializedViewStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropMaterializedViewStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropMaterializedViewStatement_name(arg0, arg1)
}

func ASTDropSnapshotTableStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDropSnapshotTableStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDropSnapshotTableStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDropSnapshotTableStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropSnapshotTableStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTDropSnapshotTableStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDropSnapshotTableStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTDropSnapshotTableStatement_is_if_exists(arg0, arg1)
}

func ASTDropSnapshotTableStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropSnapshotTableStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropSnapshotTableStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropSnapshotTableStatement_name(arg0, arg1)
}

func ASTDropSearchIndexStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDropSearchIndexStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDropSearchIndexStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDropSearchIndexStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropSearchIndexStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTDropSearchIndexStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDropSearchIndexStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTDropSearchIndexStatement_is_if_exists(arg0, arg1)
}

func ASTDropSearchIndexStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropSearchIndexStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropSearchIndexStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropSearchIndexStatement_name(arg0, arg1)
}

func ASTDropSearchIndexStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropSearchIndexStatement_table_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropSearchIndexStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropSearchIndexStatement_table_name(arg0, arg1)
}

func ASTRenameStatement_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRenameStatement_identifier(
		arg0,
		arg1,
	)
}

func zetasql_ASTRenameStatement_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRenameStatement_identifier(arg0, arg1)
}

func ASTRenameStatement_old_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRenameStatement_old_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTRenameStatement_old_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRenameStatement_old_name(arg0, arg1)
}

func ASTRenameStatement_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRenameStatement_new_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTRenameStatement_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRenameStatement_new_name(arg0, arg1)
}

func ASTImportStatement_set_import_kind(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTImportStatement_set_import_kind(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTImportStatement_set_import_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTImportStatement_set_import_kind(arg0, arg1)
}

func ASTImportStatement_import_kind(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTImportStatement_import_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTImportStatement_import_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTImportStatement_import_kind(arg0, arg1)
}

func ASTImportStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTImportStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTImportStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTImportStatement_name(arg0, arg1)
}

func ASTImportStatement_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTImportStatement_string_value(
		arg0,
		arg1,
	)
}

func zetasql_ASTImportStatement_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTImportStatement_string_value(arg0, arg1)
}

func ASTImportStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTImportStatement_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTImportStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTImportStatement_alias(arg0, arg1)
}

func ASTImportStatement_into_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTImportStatement_into_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTImportStatement_into_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTImportStatement_into_alias(arg0, arg1)
}

func ASTImportStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTImportStatement_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTImportStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTImportStatement_options_list(arg0, arg1)
}

func ASTModuleStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTModuleStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTModuleStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTModuleStatement_name(arg0, arg1)
}

func ASTModuleStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTModuleStatement_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTModuleStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTModuleStatement_options_list(arg0, arg1)
}

func ASTWithConnectionClause_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWithConnectionClause_connection_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTWithConnectionClause_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWithConnectionClause_connection_clause(arg0, arg1)
}

func ASTIntoAlias_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTIntoAlias_identifier(
		arg0,
		arg1,
	)
}

func zetasql_ASTIntoAlias_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTIntoAlias_identifier(arg0, arg1)
}

func ASTIntoAlias_GetAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTIntoAlias_GetAsString(
		arg0,
		arg1,
	)
}

func zetasql_ASTIntoAlias_GetAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTIntoAlias_GetAsString(arg0, arg1)
}

func ASTUnnestExpressionWithOptAliasAndOffset_unnest_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUnnestExpressionWithOptAliasAndOffset_unnest_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTUnnestExpressionWithOptAliasAndOffset_unnest_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUnnestExpressionWithOptAliasAndOffset_unnest_expression(arg0, arg1)
}

func ASTUnnestExpressionWithOptAliasAndOffset_optional_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUnnestExpressionWithOptAliasAndOffset_optional_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTUnnestExpressionWithOptAliasAndOffset_optional_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUnnestExpressionWithOptAliasAndOffset_optional_alias(arg0, arg1)
}

func ASTUnnestExpressionWithOptAliasAndOffset_optional_with_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUnnestExpressionWithOptAliasAndOffset_optional_with_offset(
		arg0,
		arg1,
	)
}

func zetasql_ASTUnnestExpressionWithOptAliasAndOffset_optional_with_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUnnestExpressionWithOptAliasAndOffset_optional_with_offset(arg0, arg1)
}

func ASTPivotExpression_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTPivotExpression_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTPivotExpression_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTPivotExpression_expression(arg0, arg1)
}

func ASTPivotExpression_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTPivotExpression_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTPivotExpression_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTPivotExpression_alias(arg0, arg1)
}

func ASTPivotValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTPivotValue_value(
		arg0,
		arg1,
	)
}

func zetasql_ASTPivotValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTPivotValue_value(arg0, arg1)
}

func ASTPivotValue_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTPivotValue_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTPivotValue_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTPivotValue_alias(arg0, arg1)
}

func ASTPivotExpressionList_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTPivotExpressionList_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTPivotExpressionList_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTPivotExpressionList_expressions_num(arg0, arg1)
}

func ASTPivotExpressionList_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTPivotExpressionList_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTPivotExpressionList_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTPivotExpressionList_expression(arg0, arg1, arg2)
}

func ASTPivotValueList_values_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTPivotValueList_values_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTPivotValueList_values_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTPivotValueList_values_num(arg0, arg1)
}

func ASTPivotValueList_value(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTPivotValueList_value(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTPivotValueList_value(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTPivotValueList_value(arg0, arg1, arg2)
}

func ASTPivotClause_pivot_expressions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTPivotClause_pivot_expressions(
		arg0,
		arg1,
	)
}

func zetasql_ASTPivotClause_pivot_expressions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTPivotClause_pivot_expressions(arg0, arg1)
}

func ASTPivotClause_for_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTPivotClause_for_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTPivotClause_for_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTPivotClause_for_expression(arg0, arg1)
}

func ASTPivotClause_pivot_values(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTPivotClause_pivot_values(
		arg0,
		arg1,
	)
}

func zetasql_ASTPivotClause_pivot_values(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTPivotClause_pivot_values(arg0, arg1)
}

func ASTPivotClause_output_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTPivotClause_output_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTPivotClause_output_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTPivotClause_output_alias(arg0, arg1)
}

func ASTUnpivotInItem_unpivot_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUnpivotInItem_unpivot_columns(
		arg0,
		arg1,
	)
}

func zetasql_ASTUnpivotInItem_unpivot_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUnpivotInItem_unpivot_columns(arg0, arg1)
}

func ASTUnpivotInItem_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUnpivotInItem_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTUnpivotInItem_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUnpivotInItem_alias(arg0, arg1)
}

func ASTUnpivotInItemList_in_items_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTUnpivotInItemList_in_items_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTUnpivotInItemList_in_items_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTUnpivotInItemList_in_items_num(arg0, arg1)
}

func ASTUnpivotInItemList_in_item(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTUnpivotInItemList_in_item(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTUnpivotInItemList_in_item(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTUnpivotInItemList_in_item(arg0, arg1, arg2)
}

func ASTUnpivotClause_set_null_filter(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTUnpivotClause_set_null_filter(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTUnpivotClause_set_null_filter(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTUnpivotClause_set_null_filter(arg0, arg1)
}

func ASTUnpivotClause_null_filter(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTUnpivotClause_null_filter(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTUnpivotClause_null_filter(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTUnpivotClause_null_filter(arg0, arg1)
}

func ASTUnpivotClause_unpivot_output_value_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUnpivotClause_unpivot_output_value_columns(
		arg0,
		arg1,
	)
}

func zetasql_ASTUnpivotClause_unpivot_output_value_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUnpivotClause_unpivot_output_value_columns(arg0, arg1)
}

func ASTUnpivotClause_unpivot_output_name_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUnpivotClause_unpivot_output_name_column(
		arg0,
		arg1,
	)
}

func zetasql_ASTUnpivotClause_unpivot_output_name_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUnpivotClause_unpivot_output_name_column(arg0, arg1)
}

func ASTUnpivotClause_unpivot_in_items(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUnpivotClause_unpivot_in_items(
		arg0,
		arg1,
	)
}

func zetasql_ASTUnpivotClause_unpivot_in_items(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUnpivotClause_unpivot_in_items(arg0, arg1)
}

func ASTUnpivotClause_output_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUnpivotClause_output_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTUnpivotClause_output_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUnpivotClause_output_alias(arg0, arg1)
}

func ASTUsingClause_keys_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTUsingClause_keys_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTUsingClause_keys_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTUsingClause_keys_num(arg0, arg1)
}

func ASTUsingClause_key(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTUsingClause_key(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTUsingClause_key(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTUsingClause_key(arg0, arg1, arg2)
}

func ASTForSystemTime_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTForSystemTime_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTForSystemTime_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTForSystemTime_expression(arg0, arg1)
}

func ASTQualify_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTQualify_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTQualify_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTQualify_expression(arg0, arg1)
}

func ASTClampedBetweenModifier_low(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTClampedBetweenModifier_low(
		arg0,
		arg1,
	)
}

func zetasql_ASTClampedBetweenModifier_low(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTClampedBetweenModifier_low(arg0, arg1)
}

func ASTClampedBetweenModifier_high(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTClampedBetweenModifier_high(
		arg0,
		arg1,
	)
}

func zetasql_ASTClampedBetweenModifier_high(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTClampedBetweenModifier_high(arg0, arg1)
}

func ASTFormatClause_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFormatClause_format(
		arg0,
		arg1,
	)
}

func zetasql_ASTFormatClause_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFormatClause_format(arg0, arg1)
}

func ASTFormatClause_time_zone_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFormatClause_time_zone_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTFormatClause_time_zone_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFormatClause_time_zone_expr(arg0, arg1)
}

func ASTPathExpressionList_path_expression_list_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTPathExpressionList_path_expression_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTPathExpressionList_path_expression_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTPathExpressionList_path_expression_list_num(arg0, arg1)
}

func ASTPathExpressionList_path_expression_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTPathExpressionList_path_expression_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTPathExpressionList_path_expression_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTPathExpressionList_path_expression_list(arg0, arg1, arg2)
}

func ASTParameterExpr_set_position(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTParameterExpr_set_position(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTParameterExpr_set_position(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTParameterExpr_set_position(arg0, arg1)
}

func ASTParameterExpr_position(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTParameterExpr_position(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTParameterExpr_position(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTParameterExpr_position(arg0, arg1)
}

func ASTParameterExpr_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTParameterExpr_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTParameterExpr_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTParameterExpr_name(arg0, arg1)
}

func ASTSystemVariableExpr_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSystemVariableExpr_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTSystemVariableExpr_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSystemVariableExpr_path(arg0, arg1)
}

func ASTWithGroupRows_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWithGroupRows_subquery(
		arg0,
		arg1,
	)
}

func zetasql_ASTWithGroupRows_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWithGroupRows_subquery(arg0, arg1)
}

func ASTLambda_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTLambda_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTLambda_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTLambda_argument_list(arg0, arg1)
}

func ASTLambda_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTLambda_body(
		arg0,
		arg1,
	)
}

func zetasql_ASTLambda_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTLambda_body(arg0, arg1)
}

func ASTAnalyticFunctionCall_window_spec(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAnalyticFunctionCall_window_spec(
		arg0,
		arg1,
	)
}

func zetasql_ASTAnalyticFunctionCall_window_spec(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAnalyticFunctionCall_window_spec(arg0, arg1)
}

func ASTAnalyticFunctionCall_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAnalyticFunctionCall_function(
		arg0,
		arg1,
	)
}

func zetasql_ASTAnalyticFunctionCall_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAnalyticFunctionCall_function(arg0, arg1)
}

func ASTAnalyticFunctionCall_function_with_group_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAnalyticFunctionCall_function_with_group_rows(
		arg0,
		arg1,
	)
}

func zetasql_ASTAnalyticFunctionCall_function_with_group_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAnalyticFunctionCall_function_with_group_rows(arg0, arg1)
}

func ASTFunctionCallWithGroupRows_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionCallWithGroupRows_function(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionCallWithGroupRows_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionCallWithGroupRows_function(arg0, arg1)
}

func ASTFunctionCallWithGroupRows_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionCallWithGroupRows_subquery(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionCallWithGroupRows_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionCallWithGroupRows_subquery(arg0, arg1)
}

func ASTClusterBy_clustering_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTClusterBy_clustering_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTClusterBy_clustering_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTClusterBy_clustering_expressions_num(arg0, arg1)
}

func ASTClusterBy_clustering_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTClusterBy_clustering_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTClusterBy_clustering_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTClusterBy_clustering_expression(arg0, arg1, arg2)
}

func ASTNewConstructorArg_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTNewConstructorArg_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTNewConstructorArg_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTNewConstructorArg_expression(arg0, arg1)
}

func ASTNewConstructorArg_optional_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTNewConstructorArg_optional_identifier(
		arg0,
		arg1,
	)
}

func zetasql_ASTNewConstructorArg_optional_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTNewConstructorArg_optional_identifier(arg0, arg1)
}

func ASTNewConstructorArg_optional_path_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTNewConstructorArg_optional_path_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTNewConstructorArg_optional_path_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTNewConstructorArg_optional_path_expression(arg0, arg1)
}

func ASTNewConstructor_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTNewConstructor_type_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTNewConstructor_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTNewConstructor_type_name(arg0, arg1)
}

func ASTNewConstructor_arguments_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTNewConstructor_arguments_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTNewConstructor_arguments_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTNewConstructor_arguments_num(arg0, arg1)
}

func ASTNewConstructor_argument(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTNewConstructor_argument(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTNewConstructor_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTNewConstructor_argument(arg0, arg1, arg2)
}

func ASTOptionsList_options_entries_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTOptionsList_options_entries_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTOptionsList_options_entries_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTOptionsList_options_entries_num(arg0, arg1)
}

func ASTOptionsList_options_entry(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTOptionsList_options_entry(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTOptionsList_options_entry(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTOptionsList_options_entry(arg0, arg1, arg2)
}

func ASTOptionsEntry_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTOptionsEntry_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTOptionsEntry_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTOptionsEntry_name(arg0, arg1)
}

func ASTOptionsEntry_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTOptionsEntry_value(
		arg0,
		arg1,
	)
}

func zetasql_ASTOptionsEntry_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTOptionsEntry_value(arg0, arg1)
}

func ASTCreateStatement_set_scope(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTCreateStatement_set_scope(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTCreateStatement_set_scope(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTCreateStatement_set_scope(arg0, arg1)
}

func ASTCreateStatement_scope(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTCreateStatement_scope(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCreateStatement_scope(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTCreateStatement_scope(arg0, arg1)
}

func ASTCreateStatement_set_is_or_replace(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTCreateStatement_set_is_or_replace(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTCreateStatement_set_is_or_replace(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTCreateStatement_set_is_or_replace(arg0, arg1)
}

func ASTCreateStatement_is_or_replace(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTCreateStatement_is_or_replace(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCreateStatement_is_or_replace(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTCreateStatement_is_or_replace(arg0, arg1)
}

func ASTCreateStatement_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTCreateStatement_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTCreateStatement_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTCreateStatement_set_is_if_not_exists(arg0, arg1)
}

func ASTCreateStatement_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTCreateStatement_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCreateStatement_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTCreateStatement_is_if_not_exists(arg0, arg1)
}

func ASTCreateStatement_is_default_scope(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTCreateStatement_is_default_scope(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCreateStatement_is_default_scope(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTCreateStatement_is_default_scope(arg0, arg1)
}

func ASTCreateStatement_is_private(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTCreateStatement_is_private(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCreateStatement_is_private(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTCreateStatement_is_private(arg0, arg1)
}

func ASTCreateStatement_is_public(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTCreateStatement_is_public(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCreateStatement_is_public(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTCreateStatement_is_public(arg0, arg1)
}

func ASTCreateStatement_is_temp(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTCreateStatement_is_temp(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCreateStatement_is_temp(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTCreateStatement_is_temp(arg0, arg1)
}

func ASTFunctionParameter_set_procedure_parameter_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTFunctionParameter_set_procedure_parameter_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTFunctionParameter_set_procedure_parameter_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTFunctionParameter_set_procedure_parameter_mode(arg0, arg1)
}

func ASTFunctionParameter_procedure_parameter_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTFunctionParameter_procedure_parameter_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTFunctionParameter_procedure_parameter_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTFunctionParameter_procedure_parameter_mode(arg0, arg1)
}

func ASTFunctionParameter_set_is_not_aggregate(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTFunctionParameter_set_is_not_aggregate(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTFunctionParameter_set_is_not_aggregate(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTFunctionParameter_set_is_not_aggregate(arg0, arg1)
}

func ASTFunctionParameter_is_not_aggregate(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTFunctionParameter_is_not_aggregate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTFunctionParameter_is_not_aggregate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTFunctionParameter_is_not_aggregate(arg0, arg1)
}

func ASTFunctionParameter_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionParameter_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionParameter_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionParameter_name(arg0, arg1)
}

func ASTFunctionParameter_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionParameter_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionParameter_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionParameter_type(arg0, arg1)
}

func ASTFunctionParameter_templated_parameter_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionParameter_templated_parameter_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionParameter_templated_parameter_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionParameter_templated_parameter_type(arg0, arg1)
}

func ASTFunctionParameter_tvf_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionParameter_tvf_schema(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionParameter_tvf_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionParameter_tvf_schema(arg0, arg1)
}

func ASTFunctionParameter_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionParameter_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionParameter_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionParameter_alias(arg0, arg1)
}

func ASTFunctionParameter_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionParameter_default_value(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionParameter_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionParameter_default_value(arg0, arg1)
}

func ASTFunctionParameter_IsTableParameter(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTFunctionParameter_IsTableParameter(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTFunctionParameter_IsTableParameter(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTFunctionParameter_IsTableParameter(arg0, arg1)
}

func ASTFunctionParameter_IsTemplated(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTFunctionParameter_IsTemplated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTFunctionParameter_IsTemplated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTFunctionParameter_IsTemplated(arg0, arg1)
}

func ASTFunctionParameters_parameter_entries_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTFunctionParameters_parameter_entries_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTFunctionParameters_parameter_entries_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTFunctionParameters_parameter_entries_num(arg0, arg1)
}

func ASTFunctionParameters_parameter_entry(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTFunctionParameters_parameter_entry(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTFunctionParameters_parameter_entry(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionParameters_parameter_entry(arg0, arg1, arg2)
}

func ASTFunctionDeclaration_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionDeclaration_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionDeclaration_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionDeclaration_name(arg0, arg1)
}

func ASTFunctionDeclaration_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFunctionDeclaration_parameters(
		arg0,
		arg1,
	)
}

func zetasql_ASTFunctionDeclaration_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFunctionDeclaration_parameters(arg0, arg1)
}

func ASTFunctionDeclaration_IsTemplated(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTFunctionDeclaration_IsTemplated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTFunctionDeclaration_IsTemplated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTFunctionDeclaration_IsTemplated(arg0, arg1)
}

func ASTSqlFunctionBody_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSqlFunctionBody_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTSqlFunctionBody_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSqlFunctionBody_expression(arg0, arg1)
}

func ASTTVFArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTVFArgument_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTTVFArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTVFArgument_expr(arg0, arg1)
}

func ASTTVFArgument_table_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTVFArgument_table_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTTVFArgument_table_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTVFArgument_table_clause(arg0, arg1)
}

func ASTTVFArgument_model_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTVFArgument_model_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTTVFArgument_model_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTVFArgument_model_clause(arg0, arg1)
}

func ASTTVFArgument_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTVFArgument_connection_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTTVFArgument_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTVFArgument_connection_clause(arg0, arg1)
}

func ASTTVFArgument_descriptor(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTVFArgument_descriptor(
		arg0,
		arg1,
	)
}

func zetasql_ASTTVFArgument_descriptor(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTVFArgument_descriptor(arg0, arg1)
}

func ASTTVF_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTVF_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTTVF_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTVF_name(arg0, arg1)
}

func ASTTVF_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTVF_hint(
		arg0,
		arg1,
	)
}

func zetasql_ASTTVF_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTVF_hint(arg0, arg1)
}

func ASTTVF_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTVF_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTTVF_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTVF_alias(arg0, arg1)
}

func ASTTVF_pivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTVF_pivot_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTTVF_pivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTVF_pivot_clause(arg0, arg1)
}

func ASTTVF_unpivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTVF_unpivot_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTTVF_unpivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTVF_unpivot_clause(arg0, arg1)
}

func ASTTVF_sample(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTVF_sample(
		arg0,
		arg1,
	)
}

func zetasql_ASTTVF_sample(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTVF_sample(arg0, arg1)
}

func ASTTVF_argument_entries_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTTVF_argument_entries_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTTVF_argument_entries_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTTVF_argument_entries_num(arg0, arg1)
}

func ASTTVF_argument_entry(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTTVF_argument_entry(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTTVF_argument_entry(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTTVF_argument_entry(arg0, arg1, arg2)
}

func ASTTableClause_table_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTableClause_table_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTTableClause_table_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTableClause_table_path(arg0, arg1)
}

func ASTTableClause_tvf(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTableClause_tvf(
		arg0,
		arg1,
	)
}

func zetasql_ASTTableClause_tvf(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTableClause_tvf(arg0, arg1)
}

func ASTModelClause_model_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTModelClause_model_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTModelClause_model_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTModelClause_model_path(arg0, arg1)
}

func ASTConnectionClause_connection_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTConnectionClause_connection_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTConnectionClause_connection_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTConnectionClause_connection_path(arg0, arg1)
}

func ASTTableDataSource_path_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTableDataSource_path_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTTableDataSource_path_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTableDataSource_path_expr(arg0, arg1)
}

func ASTTableDataSource_for_system_time(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTableDataSource_for_system_time(
		arg0,
		arg1,
	)
}

func zetasql_ASTTableDataSource_for_system_time(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTableDataSource_for_system_time(arg0, arg1)
}

func ASTTableDataSource_where_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTableDataSource_where_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTTableDataSource_where_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTableDataSource_where_clause(arg0, arg1)
}

func ASTCloneDataSourceList_data_sources_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTCloneDataSourceList_data_sources_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCloneDataSourceList_data_sources_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTCloneDataSourceList_data_sources_num(arg0, arg1)
}

func ASTCloneDataSourceList_data_source(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTCloneDataSourceList_data_source(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTCloneDataSourceList_data_source(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTCloneDataSourceList_data_source(arg0, arg1, arg2)
}

func ASTCloneDataStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCloneDataStatement_target_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTCloneDataStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCloneDataStatement_target_path(arg0, arg1)
}

func ASTCloneDataStatement_data_source_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCloneDataStatement_data_source_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCloneDataStatement_data_source_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCloneDataStatement_data_source_list(arg0, arg1)
}

func ASTCreateConstantStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateConstantStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateConstantStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateConstantStatement_name(arg0, arg1)
}

func ASTCreateConstantStatement_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateConstantStatement_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateConstantStatement_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateConstantStatement_expr(arg0, arg1)
}

func ASTCreateDatabaseStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateDatabaseStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateDatabaseStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateDatabaseStatement_name(arg0, arg1)
}

func ASTCreateDatabaseStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateDatabaseStatement_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateDatabaseStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateDatabaseStatement_options_list(arg0, arg1)
}

func ASTCreateProcedureStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateProcedureStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateProcedureStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateProcedureStatement_name(arg0, arg1)
}

func ASTCreateProcedureStatement_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateProcedureStatement_parameters(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateProcedureStatement_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateProcedureStatement_parameters(arg0, arg1)
}

func ASTCreateProcedureStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateProcedureStatement_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateProcedureStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateProcedureStatement_options_list(arg0, arg1)
}

func ASTCreateProcedureStatement_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateProcedureStatement_body(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateProcedureStatement_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateProcedureStatement_body(arg0, arg1)
}

func ASTCreateSchemaStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateSchemaStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateSchemaStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateSchemaStatement_name(arg0, arg1)
}

func ASTCreateSchemaStatement_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateSchemaStatement_collate(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateSchemaStatement_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateSchemaStatement_collate(arg0, arg1)
}

func ASTCreateSchemaStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateSchemaStatement_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateSchemaStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateSchemaStatement_options_list(arg0, arg1)
}

func ASTTransformClause_select_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTransformClause_select_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTTransformClause_select_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTransformClause_select_list(arg0, arg1)
}

func ASTCreateModelStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateModelStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateModelStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateModelStatement_name(arg0, arg1)
}

func ASTCreateModelStatement_transform_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateModelStatement_transform_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateModelStatement_transform_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateModelStatement_transform_clause(arg0, arg1)
}

func ASTCreateModelStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateModelStatement_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateModelStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateModelStatement_options_list(arg0, arg1)
}

func ASTCreateModelStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateModelStatement_query(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateModelStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateModelStatement_query(arg0, arg1)
}

func ASTIndexItemList_ordering_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTIndexItemList_ordering_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTIndexItemList_ordering_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTIndexItemList_ordering_expressions_num(arg0, arg1)
}

func ASTIndexItemList_ordering_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTIndexItemList_ordering_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTIndexItemList_ordering_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTIndexItemList_ordering_expression(arg0, arg1, arg2)
}

func ASTIndexStoringExpressionList_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTIndexStoringExpressionList_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTIndexStoringExpressionList_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTIndexStoringExpressionList_expressions_num(arg0, arg1)
}

func ASTIndexStoringExpressionList_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTIndexStoringExpressionList_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTIndexStoringExpressionList_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTIndexStoringExpressionList_expression(arg0, arg1, arg2)
}

func ASTIndexUnnestExpressionList_unnest_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTIndexUnnestExpressionList_unnest_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTIndexUnnestExpressionList_unnest_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTIndexUnnestExpressionList_unnest_expressions_num(arg0, arg1)
}

func ASTIndexUnnestExpressionList_unnest_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTIndexUnnestExpressionList_unnest_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTIndexUnnestExpressionList_unnest_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTIndexUnnestExpressionList_unnest_expression(arg0, arg1, arg2)
}

func ASTCreateIndexStatement_set_is_unique(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTCreateIndexStatement_set_is_unique(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTCreateIndexStatement_set_is_unique(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTCreateIndexStatement_set_is_unique(arg0, arg1)
}

func ASTCreateIndexStatement_is_unique(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTCreateIndexStatement_is_unique(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCreateIndexStatement_is_unique(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTCreateIndexStatement_is_unique(arg0, arg1)
}

func ASTCreateIndexStatement_set_is_search(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTCreateIndexStatement_set_is_search(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTCreateIndexStatement_set_is_search(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTCreateIndexStatement_set_is_search(arg0, arg1)
}

func ASTCreateIndexStatement_is_search(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTCreateIndexStatement_is_search(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCreateIndexStatement_is_search(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTCreateIndexStatement_is_search(arg0, arg1)
}

func ASTCreateIndexStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateIndexStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateIndexStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateIndexStatement_name(arg0, arg1)
}

func ASTCreateIndexStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateIndexStatement_table_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateIndexStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateIndexStatement_table_name(arg0, arg1)
}

func ASTCreateIndexStatement_optional_table_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateIndexStatement_optional_table_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateIndexStatement_optional_table_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateIndexStatement_optional_table_alias(arg0, arg1)
}

func ASTCreateIndexStatement_optional_index_unnest_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateIndexStatement_optional_index_unnest_expression_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateIndexStatement_optional_index_unnest_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateIndexStatement_optional_index_unnest_expression_list(arg0, arg1)
}

func ASTCreateIndexStatement_index_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateIndexStatement_index_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateIndexStatement_index_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateIndexStatement_index_item_list(arg0, arg1)
}

func ASTCreateIndexStatement_optional_index_storing_expressions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateIndexStatement_optional_index_storing_expressions(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateIndexStatement_optional_index_storing_expressions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateIndexStatement_optional_index_storing_expressions(arg0, arg1)
}

func ASTCreateIndexStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateIndexStatement_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateIndexStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateIndexStatement_options_list(arg0, arg1)
}

func ASTExportDataStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExportDataStatement_with_connection_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTExportDataStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExportDataStatement_with_connection_clause(arg0, arg1)
}

func ASTExportDataStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExportDataStatement_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTExportDataStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExportDataStatement_options_list(arg0, arg1)
}

func ASTExportDataStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExportDataStatement_query(
		arg0,
		arg1,
	)
}

func zetasql_ASTExportDataStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExportDataStatement_query(arg0, arg1)
}

func ASTExportModelStatement_model_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExportModelStatement_model_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTExportModelStatement_model_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExportModelStatement_model_name_path(arg0, arg1)
}

func ASTExportModelStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExportModelStatement_with_connection_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTExportModelStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExportModelStatement_with_connection_clause(arg0, arg1)
}

func ASTExportModelStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExportModelStatement_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTExportModelStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExportModelStatement_options_list(arg0, arg1)
}

func ASTCallStatement_procedure_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCallStatement_procedure_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTCallStatement_procedure_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCallStatement_procedure_name(arg0, arg1)
}

func ASTCallStatement_arguments_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTCallStatement_arguments_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCallStatement_arguments_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTCallStatement_arguments_num(arg0, arg1)
}

func ASTCallStatement_argument(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTCallStatement_argument(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTCallStatement_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTCallStatement_argument(arg0, arg1, arg2)
}

func ASTDefineTableStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDefineTableStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDefineTableStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDefineTableStatement_name(arg0, arg1)
}

func ASTDefineTableStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDefineTableStatement_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTDefineTableStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDefineTableStatement_options_list(arg0, arg1)
}

func ASTWithPartitionColumnsClause_table_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWithPartitionColumnsClause_table_element_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTWithPartitionColumnsClause_table_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWithPartitionColumnsClause_table_element_list(arg0, arg1)
}

func ASTCreateSnapshotTableStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateSnapshotTableStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateSnapshotTableStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateSnapshotTableStatement_name(arg0, arg1)
}

func ASTCreateSnapshotTableStatement_clone_data_source(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateSnapshotTableStatement_clone_data_source(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateSnapshotTableStatement_clone_data_source(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateSnapshotTableStatement_clone_data_source(arg0, arg1)
}

func ASTCreateSnapshotTableStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateSnapshotTableStatement_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateSnapshotTableStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateSnapshotTableStatement_options_list(arg0, arg1)
}

func ASTTypeParameterList_parameters_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTTypeParameterList_parameters_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTTypeParameterList_parameters_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTTypeParameterList_parameters_num(arg0, arg1)
}

func ASTTypeParameterList_parameter(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTTypeParameterList_parameter(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTTypeParameterList_parameter(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTTypeParameterList_parameter(arg0, arg1, arg2)
}

func ASTTVFSchema_columns_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTTVFSchema_columns_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTTVFSchema_columns_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTTVFSchema_columns_num(arg0, arg1)
}

func ASTTVFSchema_column(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTTVFSchema_column(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTTVFSchema_column(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTTVFSchema_column(arg0, arg1, arg2)
}

func ASTTVFSchemaColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTVFSchemaColumn_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTTVFSchemaColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTVFSchemaColumn_name(arg0, arg1)
}

func ASTTVFSchemaColumn_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTVFSchemaColumn_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTTVFSchemaColumn_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTVFSchemaColumn_type(arg0, arg1)
}

func ASTTableAndColumnInfo_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTableAndColumnInfo_table_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTTableAndColumnInfo_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTableAndColumnInfo_table_name(arg0, arg1)
}

func ASTTableAndColumnInfo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTableAndColumnInfo_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTTableAndColumnInfo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTableAndColumnInfo_column_list(arg0, arg1)
}

func ASTTableAndColumnInfoList_table_and_column_info_entries_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTTableAndColumnInfoList_table_and_column_info_entries_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTTableAndColumnInfoList_table_and_column_info_entries_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTTableAndColumnInfoList_table_and_column_info_entries_num(arg0, arg1)
}

func ASTTableAndColumnInfoList_table_and_column_info_entry(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTTableAndColumnInfoList_table_and_column_info_entry(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTTableAndColumnInfoList_table_and_column_info_entry(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTTableAndColumnInfoList_table_and_column_info_entry(arg0, arg1, arg2)
}

func ASTTemplatedParameterType_set_kind(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTTemplatedParameterType_set_kind(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTTemplatedParameterType_set_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTTemplatedParameterType_set_kind(arg0, arg1)
}

func ASTTemplatedParameterType_kind(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTTemplatedParameterType_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTTemplatedParameterType_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTTemplatedParameterType_kind(arg0, arg1)
}

func ASTAnalyzeStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAnalyzeStatement_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTAnalyzeStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAnalyzeStatement_options_list(arg0, arg1)
}

func ASTAnalyzeStatement_table_and_column_info_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAnalyzeStatement_table_and_column_info_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTAnalyzeStatement_table_and_column_info_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAnalyzeStatement_table_and_column_info_list(arg0, arg1)
}

func ASTAssertStatement_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAssertStatement_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTAssertStatement_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAssertStatement_expr(arg0, arg1)
}

func ASTAssertStatement_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAssertStatement_description(
		arg0,
		arg1,
	)
}

func zetasql_ASTAssertStatement_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAssertStatement_description(arg0, arg1)
}

func ASTAssertRowsModified_num_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAssertRowsModified_num_rows(
		arg0,
		arg1,
	)
}

func zetasql_ASTAssertRowsModified_num_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAssertRowsModified_num_rows(arg0, arg1)
}

func ASTReturningClause_select_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTReturningClause_select_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTReturningClause_select_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTReturningClause_select_list(arg0, arg1)
}

func ASTReturningClause_action_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTReturningClause_action_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTReturningClause_action_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTReturningClause_action_alias(arg0, arg1)
}

func ASTDeleteStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDeleteStatement_target_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTDeleteStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDeleteStatement_target_path(arg0, arg1)
}

func ASTDeleteStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDeleteStatement_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTDeleteStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDeleteStatement_alias(arg0, arg1)
}

func ASTDeleteStatement_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDeleteStatement_offset(
		arg0,
		arg1,
	)
}

func zetasql_ASTDeleteStatement_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDeleteStatement_offset(arg0, arg1)
}

func ASTDeleteStatement_where(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDeleteStatement_where(
		arg0,
		arg1,
	)
}

func zetasql_ASTDeleteStatement_where(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDeleteStatement_where(arg0, arg1)
}

func ASTDeleteStatement_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDeleteStatement_assert_rows_modified(
		arg0,
		arg1,
	)
}

func zetasql_ASTDeleteStatement_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDeleteStatement_assert_rows_modified(arg0, arg1)
}

func ASTDeleteStatement_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDeleteStatement_returning(
		arg0,
		arg1,
	)
}

func zetasql_ASTDeleteStatement_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDeleteStatement_returning(arg0, arg1)
}

func ASTPrimaryKeyColumnAttribute_set_enforced(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTPrimaryKeyColumnAttribute_set_enforced(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTPrimaryKeyColumnAttribute_set_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTPrimaryKeyColumnAttribute_set_enforced(arg0, arg1)
}

func ASTPrimaryKeyColumnAttribute_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTPrimaryKeyColumnAttribute_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTPrimaryKeyColumnAttribute_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTPrimaryKeyColumnAttribute_enforced(arg0, arg1)
}

func ASTForeignKeyColumnAttribute_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTForeignKeyColumnAttribute_constraint_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTForeignKeyColumnAttribute_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTForeignKeyColumnAttribute_constraint_name(arg0, arg1)
}

func ASTForeignKeyColumnAttribute_reference(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTForeignKeyColumnAttribute_reference(
		arg0,
		arg1,
	)
}

func zetasql_ASTForeignKeyColumnAttribute_reference(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTForeignKeyColumnAttribute_reference(arg0, arg1)
}

func ASTColumnAttributeList_values_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTColumnAttributeList_values_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTColumnAttributeList_values_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTColumnAttributeList_values_num(arg0, arg1)
}

func ASTColumnAttributeList_value(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTColumnAttributeList_value(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTColumnAttributeList_value(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTColumnAttributeList_value(arg0, arg1, arg2)
}

func ASTStructColumnField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTStructColumnField_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTStructColumnField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTStructColumnField_name(arg0, arg1)
}

func ASTStructColumnField_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTStructColumnField_schema(
		arg0,
		arg1,
	)
}

func zetasql_ASTStructColumnField_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTStructColumnField_schema(arg0, arg1)
}

func ASTGeneratedColumnInfo_set_stored_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTGeneratedColumnInfo_set_stored_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTGeneratedColumnInfo_set_stored_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTGeneratedColumnInfo_set_stored_mode(arg0, arg1)
}

func ASTGeneratedColumnInfo_stored_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTGeneratedColumnInfo_stored_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTGeneratedColumnInfo_stored_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTGeneratedColumnInfo_stored_mode(arg0, arg1)
}

func ASTGeneratedColumnInfo_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTGeneratedColumnInfo_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTGeneratedColumnInfo_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTGeneratedColumnInfo_expression(arg0, arg1)
}

func ASTGeneratedColumnInfo_GetSqlForStoredMode(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTGeneratedColumnInfo_GetSqlForStoredMode(
		arg0,
		arg1,
	)
}

func zetasql_ASTGeneratedColumnInfo_GetSqlForStoredMode(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTGeneratedColumnInfo_GetSqlForStoredMode(arg0, arg1)
}

func ASTColumnDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTColumnDefinition_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTColumnDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTColumnDefinition_name(arg0, arg1)
}

func ASTColumnDefinition_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTColumnDefinition_schema(
		arg0,
		arg1,
	)
}

func zetasql_ASTColumnDefinition_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTColumnDefinition_schema(arg0, arg1)
}

func ASTTableElementList_elements_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTTableElementList_elements_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTTableElementList_elements_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTTableElementList_elements_num(arg0, arg1)
}

func ASTTableElementList_element(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTTableElementList_element(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTTableElementList_element(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTTableElementList_element(arg0, arg1, arg2)
}

func ASTColumnList_identifiers_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTColumnList_identifiers_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTColumnList_identifiers_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTColumnList_identifiers_num(arg0, arg1)
}

func ASTColumnList_identifier(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTColumnList_identifier(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTColumnList_identifier(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTColumnList_identifier(arg0, arg1, arg2)
}

func ASTColumnPosition_set_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTColumnPosition_set_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTColumnPosition_set_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTColumnPosition_set_type(arg0, arg1)
}

func ASTColumnPosition_type(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTColumnPosition_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTColumnPosition_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTColumnPosition_type(arg0, arg1)
}

func ASTColumnPosition_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTColumnPosition_identifier(
		arg0,
		arg1,
	)
}

func zetasql_ASTColumnPosition_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTColumnPosition_identifier(arg0, arg1)
}

func ASTInsertValuesRow_values_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTInsertValuesRow_values_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTInsertValuesRow_values_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTInsertValuesRow_values_num(arg0, arg1)
}

func ASTInsertValuesRow_value(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTInsertValuesRow_value(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTInsertValuesRow_value(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTInsertValuesRow_value(arg0, arg1, arg2)
}

func ASTInsertValuesRowList_rows_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTInsertValuesRowList_rows_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTInsertValuesRowList_rows_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTInsertValuesRowList_rows_num(arg0, arg1)
}

func ASTInsertValuesRowList_row(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTInsertValuesRowList_row(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTInsertValuesRowList_row(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTInsertValuesRowList_row(arg0, arg1, arg2)
}

func ASTInsertStatement_set_parse_progress(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTInsertStatement_set_parse_progress(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTInsertStatement_set_parse_progress(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTInsertStatement_set_parse_progress(arg0, arg1)
}

func ASTInsertStatement_parse_progress(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTInsertStatement_parse_progress(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTInsertStatement_parse_progress(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTInsertStatement_parse_progress(arg0, arg1)
}

func ASTInsertStatement_set_insert_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTInsertStatement_set_insert_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTInsertStatement_set_insert_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTInsertStatement_set_insert_mode(arg0, arg1)
}

func ASTInsertStatement_insert_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTInsertStatement_insert_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTInsertStatement_insert_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTInsertStatement_insert_mode(arg0, arg1)
}

func ASTInsertStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTInsertStatement_target_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTInsertStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTInsertStatement_target_path(arg0, arg1)
}

func ASTInsertStatement_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTInsertStatement_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTInsertStatement_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTInsertStatement_column_list(arg0, arg1)
}

func ASTInsertStatement_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTInsertStatement_rows(
		arg0,
		arg1,
	)
}

func zetasql_ASTInsertStatement_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTInsertStatement_rows(arg0, arg1)
}

func ASTInsertStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTInsertStatement_query(
		arg0,
		arg1,
	)
}

func zetasql_ASTInsertStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTInsertStatement_query(arg0, arg1)
}

func ASTInsertStatement_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTInsertStatement_assert_rows_modified(
		arg0,
		arg1,
	)
}

func zetasql_ASTInsertStatement_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTInsertStatement_assert_rows_modified(arg0, arg1)
}

func ASTInsertStatement_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTInsertStatement_returning(
		arg0,
		arg1,
	)
}

func zetasql_ASTInsertStatement_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTInsertStatement_returning(arg0, arg1)
}

func ASTInsertStatement_GetSQLForInsertMode(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTInsertStatement_GetSQLForInsertMode(
		arg0,
		arg1,
	)
}

func zetasql_ASTInsertStatement_GetSQLForInsertMode(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTInsertStatement_GetSQLForInsertMode(arg0, arg1)
}

func ASTUpdateSetValue_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUpdateSetValue_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTUpdateSetValue_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUpdateSetValue_path(arg0, arg1)
}

func ASTUpdateSetValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUpdateSetValue_value(
		arg0,
		arg1,
	)
}

func zetasql_ASTUpdateSetValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUpdateSetValue_value(arg0, arg1)
}

func ASTUpdateItem_set_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUpdateItem_set_value(
		arg0,
		arg1,
	)
}

func zetasql_ASTUpdateItem_set_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUpdateItem_set_value(arg0, arg1)
}

func ASTUpdateItem_insert_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUpdateItem_insert_statement(
		arg0,
		arg1,
	)
}

func zetasql_ASTUpdateItem_insert_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUpdateItem_insert_statement(arg0, arg1)
}

func ASTUpdateItem_delete_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUpdateItem_delete_statement(
		arg0,
		arg1,
	)
}

func zetasql_ASTUpdateItem_delete_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUpdateItem_delete_statement(arg0, arg1)
}

func ASTUpdateItem_update_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUpdateItem_update_statement(
		arg0,
		arg1,
	)
}

func zetasql_ASTUpdateItem_update_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUpdateItem_update_statement(arg0, arg1)
}

func ASTUpdateItemList_update_items_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTUpdateItemList_update_items_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTUpdateItemList_update_items_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTUpdateItemList_update_items_num(arg0, arg1)
}

func ASTUpdateItemList_update_item(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTUpdateItemList_update_item(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTUpdateItemList_update_item(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTUpdateItemList_update_item(arg0, arg1, arg2)
}

func ASTUpdateStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUpdateStatement_target_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTUpdateStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUpdateStatement_target_path(arg0, arg1)
}

func ASTUpdateStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUpdateStatement_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTUpdateStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUpdateStatement_alias(arg0, arg1)
}

func ASTUpdateStatement_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUpdateStatement_offset(
		arg0,
		arg1,
	)
}

func zetasql_ASTUpdateStatement_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUpdateStatement_offset(arg0, arg1)
}

func ASTUpdateStatement_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUpdateStatement_update_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTUpdateStatement_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUpdateStatement_update_item_list(arg0, arg1)
}

func ASTUpdateStatement_from_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUpdateStatement_from_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTUpdateStatement_from_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUpdateStatement_from_clause(arg0, arg1)
}

func ASTUpdateStatement_where(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUpdateStatement_where(
		arg0,
		arg1,
	)
}

func zetasql_ASTUpdateStatement_where(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUpdateStatement_where(arg0, arg1)
}

func ASTUpdateStatement_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUpdateStatement_assert_rows_modified(
		arg0,
		arg1,
	)
}

func zetasql_ASTUpdateStatement_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUpdateStatement_assert_rows_modified(arg0, arg1)
}

func ASTUpdateStatement_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUpdateStatement_returning(
		arg0,
		arg1,
	)
}

func zetasql_ASTUpdateStatement_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUpdateStatement_returning(arg0, arg1)
}

func ASTTruncateStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTruncateStatement_target_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTTruncateStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTruncateStatement_target_path(arg0, arg1)
}

func ASTTruncateStatement_where(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTruncateStatement_where(
		arg0,
		arg1,
	)
}

func zetasql_ASTTruncateStatement_where(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTruncateStatement_where(arg0, arg1)
}

func ASTMergeAction_set_action_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTMergeAction_set_action_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTMergeAction_set_action_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTMergeAction_set_action_type(arg0, arg1)
}

func ASTMergeAction_action_type(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTMergeAction_action_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTMergeAction_action_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTMergeAction_action_type(arg0, arg1)
}

func ASTMergeAction_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTMergeAction_insert_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTMergeAction_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTMergeAction_insert_column_list(arg0, arg1)
}

func ASTMergeAction_insert_row(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTMergeAction_insert_row(
		arg0,
		arg1,
	)
}

func zetasql_ASTMergeAction_insert_row(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTMergeAction_insert_row(arg0, arg1)
}

func ASTMergeAction_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTMergeAction_update_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTMergeAction_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTMergeAction_update_item_list(arg0, arg1)
}

func ASTMergeWhenClause_set_match_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTMergeWhenClause_set_match_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTMergeWhenClause_set_match_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTMergeWhenClause_set_match_type(arg0, arg1)
}

func ASTMergeWhenClause_match_type(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTMergeWhenClause_match_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTMergeWhenClause_match_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTMergeWhenClause_match_type(arg0, arg1)
}

func ASTMergeWhenClause_search_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTMergeWhenClause_search_condition(
		arg0,
		arg1,
	)
}

func zetasql_ASTMergeWhenClause_search_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTMergeWhenClause_search_condition(arg0, arg1)
}

func ASTMergeWhenClause_action(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTMergeWhenClause_action(
		arg0,
		arg1,
	)
}

func zetasql_ASTMergeWhenClause_action(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTMergeWhenClause_action(arg0, arg1)
}

func ASTMergeWhenClause_GetSQLForMatchType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTMergeWhenClause_GetSQLForMatchType(
		arg0,
		arg1,
	)
}

func zetasql_ASTMergeWhenClause_GetSQLForMatchType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTMergeWhenClause_GetSQLForMatchType(arg0, arg1)
}

func ASTMergeWhenClauseList_clause_list_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTMergeWhenClauseList_clause_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTMergeWhenClauseList_clause_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTMergeWhenClauseList_clause_list_num(arg0, arg1)
}

func ASTMergeWhenClauseList_clause_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTMergeWhenClauseList_clause_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTMergeWhenClauseList_clause_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTMergeWhenClauseList_clause_list(arg0, arg1, arg2)
}

func ASTMergeStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTMergeStatement_target_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTMergeStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTMergeStatement_target_path(arg0, arg1)
}

func ASTMergeStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTMergeStatement_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTMergeStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTMergeStatement_alias(arg0, arg1)
}

func ASTMergeStatement_table_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTMergeStatement_table_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTMergeStatement_table_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTMergeStatement_table_expression(arg0, arg1)
}

func ASTMergeStatement_merge_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTMergeStatement_merge_condition(
		arg0,
		arg1,
	)
}

func zetasql_ASTMergeStatement_merge_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTMergeStatement_merge_condition(arg0, arg1)
}

func ASTMergeStatement_when_clauses(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTMergeStatement_when_clauses(
		arg0,
		arg1,
	)
}

func zetasql_ASTMergeStatement_when_clauses(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTMergeStatement_when_clauses(arg0, arg1)
}

func ASTPrivilege_privilege_action(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTPrivilege_privilege_action(
		arg0,
		arg1,
	)
}

func zetasql_ASTPrivilege_privilege_action(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTPrivilege_privilege_action(arg0, arg1)
}

func ASTPrivilege_paths(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTPrivilege_paths(
		arg0,
		arg1,
	)
}

func zetasql_ASTPrivilege_paths(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTPrivilege_paths(arg0, arg1)
}

func ASTPrivileges_privileges_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTPrivileges_privileges_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTPrivileges_privileges_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTPrivileges_privileges_num(arg0, arg1)
}

func ASTPrivileges_privilege(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTPrivileges_privilege(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTPrivileges_privilege(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTPrivileges_privilege(arg0, arg1, arg2)
}

func ASTPrivileges_is_all_privileges(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTPrivileges_is_all_privileges(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTPrivileges_is_all_privileges(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTPrivileges_is_all_privileges(arg0, arg1)
}

func ASTGranteeList_grantee_list_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTGranteeList_grantee_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTGranteeList_grantee_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTGranteeList_grantee_list_num(arg0, arg1)
}

func ASTGranteeList_grantee_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTGranteeList_grantee_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTGranteeList_grantee_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTGranteeList_grantee_list(arg0, arg1, arg2)
}

func ASTGrantStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTGrantStatement_privileges(
		arg0,
		arg1,
	)
}

func zetasql_ASTGrantStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTGrantStatement_privileges(arg0, arg1)
}

func ASTGrantStatement_target_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTGrantStatement_target_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTGrantStatement_target_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTGrantStatement_target_type(arg0, arg1)
}

func ASTGrantStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTGrantStatement_target_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTGrantStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTGrantStatement_target_path(arg0, arg1)
}

func ASTGrantStatement_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTGrantStatement_grantee_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTGrantStatement_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTGrantStatement_grantee_list(arg0, arg1)
}

func ASTRevokeStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRevokeStatement_privileges(
		arg0,
		arg1,
	)
}

func zetasql_ASTRevokeStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRevokeStatement_privileges(arg0, arg1)
}

func ASTRevokeStatement_target_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRevokeStatement_target_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTRevokeStatement_target_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRevokeStatement_target_type(arg0, arg1)
}

func ASTRevokeStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRevokeStatement_target_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTRevokeStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRevokeStatement_target_path(arg0, arg1)
}

func ASTRevokeStatement_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRevokeStatement_grantee_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTRevokeStatement_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRevokeStatement_grantee_list(arg0, arg1)
}

func ASTRepeatableClause_argument(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRepeatableClause_argument(
		arg0,
		arg1,
	)
}

func zetasql_ASTRepeatableClause_argument(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRepeatableClause_argument(arg0, arg1)
}

func ASTFilterFieldsArg_set_filter_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTFilterFieldsArg_set_filter_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTFilterFieldsArg_set_filter_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTFilterFieldsArg_set_filter_type(arg0, arg1)
}

func ASTFilterFieldsArg_filter_type(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTFilterFieldsArg_filter_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTFilterFieldsArg_filter_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTFilterFieldsArg_filter_type(arg0, arg1)
}

func ASTFilterFieldsArg_path_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFilterFieldsArg_path_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTFilterFieldsArg_path_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFilterFieldsArg_path_expression(arg0, arg1)
}

func ASTFilterFieldsArg_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFilterFieldsArg_GetSQLForOperator(
		arg0,
		arg1,
	)
}

func zetasql_ASTFilterFieldsArg_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFilterFieldsArg_GetSQLForOperator(arg0, arg1)
}

func ASTReplaceFieldsArg_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTReplaceFieldsArg_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTReplaceFieldsArg_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTReplaceFieldsArg_expression(arg0, arg1)
}

func ASTReplaceFieldsArg_path_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTReplaceFieldsArg_path_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTReplaceFieldsArg_path_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTReplaceFieldsArg_path_expression(arg0, arg1)
}

func ASTReplaceFieldsExpression_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTReplaceFieldsExpression_expr(
		arg0,
		arg1,
	)
}

func zetasql_ASTReplaceFieldsExpression_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTReplaceFieldsExpression_expr(arg0, arg1)
}

func ASTReplaceFieldsExpression_arguments_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTReplaceFieldsExpression_arguments_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTReplaceFieldsExpression_arguments_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTReplaceFieldsExpression_arguments_num(arg0, arg1)
}

func ASTReplaceFieldsExpression_argument(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTReplaceFieldsExpression_argument(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTReplaceFieldsExpression_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTReplaceFieldsExpression_argument(arg0, arg1, arg2)
}

func ASTSampleSize_set_unit(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTSampleSize_set_unit(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTSampleSize_set_unit(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTSampleSize_set_unit(arg0, arg1)
}

func ASTSampleSize_unit(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTSampleSize_unit(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTSampleSize_unit(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTSampleSize_unit(arg0, arg1)
}

func ASTSampleSize_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSampleSize_size(
		arg0,
		arg1,
	)
}

func zetasql_ASTSampleSize_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSampleSize_size(arg0, arg1)
}

func ASTSampleSize_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSampleSize_partition_by(
		arg0,
		arg1,
	)
}

func zetasql_ASTSampleSize_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSampleSize_partition_by(arg0, arg1)
}

func ASTSampleSize_GetSQLForUnit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSampleSize_GetSQLForUnit(
		arg0,
		arg1,
	)
}

func zetasql_ASTSampleSize_GetSQLForUnit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSampleSize_GetSQLForUnit(arg0, arg1)
}

func ASTWithWeight_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWithWeight_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTWithWeight_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWithWeight_alias(arg0, arg1)
}

func ASTSampleSuffix_weight(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSampleSuffix_weight(
		arg0,
		arg1,
	)
}

func zetasql_ASTSampleSuffix_weight(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSampleSuffix_weight(arg0, arg1)
}

func ASTSampleSuffix_repeat(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSampleSuffix_repeat(
		arg0,
		arg1,
	)
}

func zetasql_ASTSampleSuffix_repeat(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSampleSuffix_repeat(arg0, arg1)
}

func ASTSampleClause_sample_method(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSampleClause_sample_method(
		arg0,
		arg1,
	)
}

func zetasql_ASTSampleClause_sample_method(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSampleClause_sample_method(arg0, arg1)
}

func ASTSampleClause_sample_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSampleClause_sample_size(
		arg0,
		arg1,
	)
}

func zetasql_ASTSampleClause_sample_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSampleClause_sample_size(arg0, arg1)
}

func ASTSampleClause_sample_suffix(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSampleClause_sample_suffix(
		arg0,
		arg1,
	)
}

func zetasql_ASTSampleClause_sample_suffix(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSampleClause_sample_suffix(arg0, arg1)
}

func ASTAlterAction_GetSQLForAlterAction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterAction_GetSQLForAlterAction(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterAction_GetSQLForAlterAction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterAction_GetSQLForAlterAction(arg0, arg1)
}

func ASTSetOptionsAction_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSetOptionsAction_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTSetOptionsAction_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSetOptionsAction_options_list(arg0, arg1)
}

func ASTSetAsAction_json_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSetAsAction_json_body(
		arg0,
		arg1,
	)
}

func zetasql_ASTSetAsAction_json_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSetAsAction_json_body(arg0, arg1)
}

func ASTSetAsAction_text_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSetAsAction_text_body(
		arg0,
		arg1,
	)
}

func zetasql_ASTSetAsAction_text_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSetAsAction_text_body(arg0, arg1)
}

func ASTAddConstraintAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTAddConstraintAction_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTAddConstraintAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTAddConstraintAction_set_is_if_not_exists(arg0, arg1)
}

func ASTAddConstraintAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTAddConstraintAction_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAddConstraintAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTAddConstraintAction_is_if_not_exists(arg0, arg1)
}

func ASTAddConstraintAction_constraint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAddConstraintAction_constraint(
		arg0,
		arg1,
	)
}

func zetasql_ASTAddConstraintAction_constraint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAddConstraintAction_constraint(arg0, arg1)
}

func ASTDropPrimaryKeyAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDropPrimaryKeyAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDropPrimaryKeyAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDropPrimaryKeyAction_set_is_if_exists(arg0, arg1)
}

func ASTDropPrimaryKeyAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTDropPrimaryKeyAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDropPrimaryKeyAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTDropPrimaryKeyAction_is_if_exists(arg0, arg1)
}

func ASTDropConstraintAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDropConstraintAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDropConstraintAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDropConstraintAction_set_is_if_exists(arg0, arg1)
}

func ASTDropConstraintAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTDropConstraintAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDropConstraintAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTDropConstraintAction_is_if_exists(arg0, arg1)
}

func ASTDropConstraintAction_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropConstraintAction_constraint_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropConstraintAction_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropConstraintAction_constraint_name(arg0, arg1)
}

func ASTAlterConstraintEnforcementAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTAlterConstraintEnforcementAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTAlterConstraintEnforcementAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTAlterConstraintEnforcementAction_set_is_if_exists(arg0, arg1)
}

func ASTAlterConstraintEnforcementAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTAlterConstraintEnforcementAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAlterConstraintEnforcementAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTAlterConstraintEnforcementAction_is_if_exists(arg0, arg1)
}

func ASTAlterConstraintEnforcementAction_set_is_enforced(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTAlterConstraintEnforcementAction_set_is_enforced(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTAlterConstraintEnforcementAction_set_is_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTAlterConstraintEnforcementAction_set_is_enforced(arg0, arg1)
}

func ASTAlterConstraintEnforcementAction_is_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTAlterConstraintEnforcementAction_is_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAlterConstraintEnforcementAction_is_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTAlterConstraintEnforcementAction_is_enforced(arg0, arg1)
}

func ASTAlterConstraintEnforcementAction_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterConstraintEnforcementAction_constraint_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterConstraintEnforcementAction_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterConstraintEnforcementAction_constraint_name(arg0, arg1)
}

func ASTAlterConstraintSetOptionsAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTAlterConstraintSetOptionsAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTAlterConstraintSetOptionsAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTAlterConstraintSetOptionsAction_set_is_if_exists(arg0, arg1)
}

func ASTAlterConstraintSetOptionsAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTAlterConstraintSetOptionsAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAlterConstraintSetOptionsAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTAlterConstraintSetOptionsAction_is_if_exists(arg0, arg1)
}

func ASTAlterConstraintSetOptionsAction_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterConstraintSetOptionsAction_constraint_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterConstraintSetOptionsAction_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterConstraintSetOptionsAction_constraint_name(arg0, arg1)
}

func ASTAlterConstraintSetOptionsAction_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterConstraintSetOptionsAction_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterConstraintSetOptionsAction_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterConstraintSetOptionsAction_options_list(arg0, arg1)
}

func ASTAddColumnAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTAddColumnAction_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTAddColumnAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTAddColumnAction_set_is_if_not_exists(arg0, arg1)
}

func ASTAddColumnAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTAddColumnAction_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAddColumnAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTAddColumnAction_is_if_not_exists(arg0, arg1)
}

func ASTAddColumnAction_column_definition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAddColumnAction_column_definition(
		arg0,
		arg1,
	)
}

func zetasql_ASTAddColumnAction_column_definition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAddColumnAction_column_definition(arg0, arg1)
}

func ASTAddColumnAction_column_position(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAddColumnAction_column_position(
		arg0,
		arg1,
	)
}

func zetasql_ASTAddColumnAction_column_position(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAddColumnAction_column_position(arg0, arg1)
}

func ASTAddColumnAction_fill_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAddColumnAction_fill_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTAddColumnAction_fill_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAddColumnAction_fill_expression(arg0, arg1)
}

func ASTDropColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDropColumnAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDropColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDropColumnAction_set_is_if_exists(arg0, arg1)
}

func ASTDropColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTDropColumnAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDropColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTDropColumnAction_is_if_exists(arg0, arg1)
}

func ASTDropColumnAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropColumnAction_column_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropColumnAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropColumnAction_column_name(arg0, arg1)
}

func ASTRenameColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTRenameColumnAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTRenameColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTRenameColumnAction_set_is_if_exists(arg0, arg1)
}

func ASTRenameColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTRenameColumnAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTRenameColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTRenameColumnAction_is_if_exists(arg0, arg1)
}

func ASTRenameColumnAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRenameColumnAction_column_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTRenameColumnAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRenameColumnAction_column_name(arg0, arg1)
}

func ASTRenameColumnAction_new_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRenameColumnAction_new_column_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTRenameColumnAction_new_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRenameColumnAction_new_column_name(arg0, arg1)
}

func ASTAlterColumnTypeAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTAlterColumnTypeAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTAlterColumnTypeAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTAlterColumnTypeAction_set_is_if_exists(arg0, arg1)
}

func ASTAlterColumnTypeAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTAlterColumnTypeAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAlterColumnTypeAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTAlterColumnTypeAction_is_if_exists(arg0, arg1)
}

func ASTAlterColumnTypeAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterColumnTypeAction_column_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterColumnTypeAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterColumnTypeAction_column_name(arg0, arg1)
}

func ASTAlterColumnTypeAction_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterColumnTypeAction_schema(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterColumnTypeAction_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterColumnTypeAction_schema(arg0, arg1)
}

func ASTAlterColumnTypeAction_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterColumnTypeAction_collate(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterColumnTypeAction_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterColumnTypeAction_collate(arg0, arg1)
}

func ASTAlterColumnOptionsAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTAlterColumnOptionsAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTAlterColumnOptionsAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTAlterColumnOptionsAction_set_is_if_exists(arg0, arg1)
}

func ASTAlterColumnOptionsAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTAlterColumnOptionsAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAlterColumnOptionsAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTAlterColumnOptionsAction_is_if_exists(arg0, arg1)
}

func ASTAlterColumnOptionsAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterColumnOptionsAction_column_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterColumnOptionsAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterColumnOptionsAction_column_name(arg0, arg1)
}

func ASTAlterColumnOptionsAction_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterColumnOptionsAction_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterColumnOptionsAction_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterColumnOptionsAction_options_list(arg0, arg1)
}

func ASTAlterColumnSetDefaultAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTAlterColumnSetDefaultAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTAlterColumnSetDefaultAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTAlterColumnSetDefaultAction_set_is_if_exists(arg0, arg1)
}

func ASTAlterColumnSetDefaultAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTAlterColumnSetDefaultAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAlterColumnSetDefaultAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTAlterColumnSetDefaultAction_is_if_exists(arg0, arg1)
}

func ASTAlterColumnSetDefaultAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterColumnSetDefaultAction_column_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterColumnSetDefaultAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterColumnSetDefaultAction_column_name(arg0, arg1)
}

func ASTAlterColumnSetDefaultAction_default_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterColumnSetDefaultAction_default_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterColumnSetDefaultAction_default_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterColumnSetDefaultAction_default_expression(arg0, arg1)
}

func ASTAlterColumnDropDefaultAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTAlterColumnDropDefaultAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTAlterColumnDropDefaultAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTAlterColumnDropDefaultAction_set_is_if_exists(arg0, arg1)
}

func ASTAlterColumnDropDefaultAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTAlterColumnDropDefaultAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAlterColumnDropDefaultAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTAlterColumnDropDefaultAction_is_if_exists(arg0, arg1)
}

func ASTAlterColumnDropDefaultAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterColumnDropDefaultAction_column_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterColumnDropDefaultAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterColumnDropDefaultAction_column_name(arg0, arg1)
}

func ASTAlterColumnDropNotNullAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTAlterColumnDropNotNullAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTAlterColumnDropNotNullAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTAlterColumnDropNotNullAction_set_is_if_exists(arg0, arg1)
}

func ASTAlterColumnDropNotNullAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTAlterColumnDropNotNullAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAlterColumnDropNotNullAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTAlterColumnDropNotNullAction_is_if_exists(arg0, arg1)
}

func ASTAlterColumnDropNotNullAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterColumnDropNotNullAction_column_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterColumnDropNotNullAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterColumnDropNotNullAction_column_name(arg0, arg1)
}

func ASTGrantToClause_set_has_grant_keyword_and_parens(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTGrantToClause_set_has_grant_keyword_and_parens(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTGrantToClause_set_has_grant_keyword_and_parens(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTGrantToClause_set_has_grant_keyword_and_parens(arg0, arg1)
}

func ASTGrantToClause_has_grant_keyword_and_parens(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTGrantToClause_has_grant_keyword_and_parens(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTGrantToClause_has_grant_keyword_and_parens(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTGrantToClause_has_grant_keyword_and_parens(arg0, arg1)
}

func ASTGrantToClause_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTGrantToClause_grantee_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTGrantToClause_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTGrantToClause_grantee_list(arg0, arg1)
}

func ASTRestrictToClause_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRestrictToClause_restrictee_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTRestrictToClause_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRestrictToClause_restrictee_list(arg0, arg1)
}

func ASTAddToRestricteeListClause_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTAddToRestricteeListClause_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTAddToRestricteeListClause_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTAddToRestricteeListClause_set_is_if_not_exists(arg0, arg1)
}

func ASTAddToRestricteeListClause_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTAddToRestricteeListClause_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAddToRestricteeListClause_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTAddToRestricteeListClause_is_if_not_exists(arg0, arg1)
}

func ASTAddToRestricteeListClause_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAddToRestricteeListClause_restrictee_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTAddToRestricteeListClause_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAddToRestricteeListClause_restrictee_list(arg0, arg1)
}

func ASTRemoveFromRestricteeListClause_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTRemoveFromRestricteeListClause_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTRemoveFromRestricteeListClause_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTRemoveFromRestricteeListClause_set_is_if_exists(arg0, arg1)
}

func ASTRemoveFromRestricteeListClause_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTRemoveFromRestricteeListClause_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTRemoveFromRestricteeListClause_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTRemoveFromRestricteeListClause_is_if_exists(arg0, arg1)
}

func ASTRemoveFromRestricteeListClause_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRemoveFromRestricteeListClause_restrictee_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTRemoveFromRestricteeListClause_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRemoveFromRestricteeListClause_restrictee_list(arg0, arg1)
}

func ASTFilterUsingClause_set_has_filter_keyword(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTFilterUsingClause_set_has_filter_keyword(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTFilterUsingClause_set_has_filter_keyword(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTFilterUsingClause_set_has_filter_keyword(arg0, arg1)
}

func ASTFilterUsingClause_has_filter_keyword(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTFilterUsingClause_has_filter_keyword(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTFilterUsingClause_has_filter_keyword(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTFilterUsingClause_has_filter_keyword(arg0, arg1)
}

func ASTFilterUsingClause_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTFilterUsingClause_predicate(
		arg0,
		arg1,
	)
}

func zetasql_ASTFilterUsingClause_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTFilterUsingClause_predicate(arg0, arg1)
}

func ASTRevokeFromClause_set_is_revoke_from_all(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTRevokeFromClause_set_is_revoke_from_all(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTRevokeFromClause_set_is_revoke_from_all(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTRevokeFromClause_set_is_revoke_from_all(arg0, arg1)
}

func ASTRevokeFromClause_is_revoke_from_all(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTRevokeFromClause_is_revoke_from_all(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTRevokeFromClause_is_revoke_from_all(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTRevokeFromClause_is_revoke_from_all(arg0, arg1)
}

func ASTRevokeFromClause_revoke_from_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRevokeFromClause_revoke_from_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTRevokeFromClause_revoke_from_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRevokeFromClause_revoke_from_list(arg0, arg1)
}

func ASTRenameToClause_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRenameToClause_new_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTRenameToClause_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRenameToClause_new_name(arg0, arg1)
}

func ASTSetCollateClause_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSetCollateClause_collate(
		arg0,
		arg1,
	)
}

func zetasql_ASTSetCollateClause_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSetCollateClause_collate(arg0, arg1)
}

func ASTAlterActionList_actions_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTAlterActionList_actions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAlterActionList_actions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTAlterActionList_actions_num(arg0, arg1)
}

func ASTAlterActionList_action(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTAlterActionList_action(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTAlterActionList_action(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterActionList_action(arg0, arg1, arg2)
}

func ASTAlterAllRowAccessPoliciesStatement_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterAllRowAccessPoliciesStatement_table_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterAllRowAccessPoliciesStatement_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterAllRowAccessPoliciesStatement_table_name_path(arg0, arg1)
}

func ASTAlterAllRowAccessPoliciesStatement_alter_action(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterAllRowAccessPoliciesStatement_alter_action(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterAllRowAccessPoliciesStatement_alter_action(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterAllRowAccessPoliciesStatement_alter_action(arg0, arg1)
}

func ASTForeignKeyActions_set_udpate_action(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTForeignKeyActions_set_udpate_action(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTForeignKeyActions_set_udpate_action(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTForeignKeyActions_set_udpate_action(arg0, arg1)
}

func ASTForeignKeyActions_udpate_action(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTForeignKeyActions_udpate_action(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTForeignKeyActions_udpate_action(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTForeignKeyActions_udpate_action(arg0, arg1)
}

func ASTForeignKeyActions_set_delete_action(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTForeignKeyActions_set_delete_action(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTForeignKeyActions_set_delete_action(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTForeignKeyActions_set_delete_action(arg0, arg1)
}

func ASTForeignKeyActions_delete_action(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTForeignKeyActions_delete_action(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTForeignKeyActions_delete_action(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTForeignKeyActions_delete_action(arg0, arg1)
}

func ASTForeignKeyReference_set_match(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTForeignKeyReference_set_match(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTForeignKeyReference_set_match(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTForeignKeyReference_set_match(arg0, arg1)
}

func ASTForeignKeyReference_match(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTForeignKeyReference_match(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTForeignKeyReference_match(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTForeignKeyReference_match(arg0, arg1)
}

func ASTForeignKeyReference_set_enforced(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTForeignKeyReference_set_enforced(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTForeignKeyReference_set_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTForeignKeyReference_set_enforced(arg0, arg1)
}

func ASTForeignKeyReference_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTForeignKeyReference_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTForeignKeyReference_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTForeignKeyReference_enforced(arg0, arg1)
}

func ASTForeignKeyReference_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTForeignKeyReference_table_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTForeignKeyReference_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTForeignKeyReference_table_name(arg0, arg1)
}

func ASTForeignKeyReference_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTForeignKeyReference_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTForeignKeyReference_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTForeignKeyReference_column_list(arg0, arg1)
}

func ASTForeignKeyReference_actions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTForeignKeyReference_actions(
		arg0,
		arg1,
	)
}

func zetasql_ASTForeignKeyReference_actions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTForeignKeyReference_actions(arg0, arg1)
}

func ASTScript_statement_list_node(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTScript_statement_list_node(
		arg0,
		arg1,
	)
}

func zetasql_ASTScript_statement_list_node(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTScript_statement_list_node(arg0, arg1)
}

func ASTScript_statement_list_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTScript_statement_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTScript_statement_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTScript_statement_list_num(arg0, arg1)
}

func ASTScript_statement_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTScript_statement_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTScript_statement_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTScript_statement_list(arg0, arg1, arg2)
}

func ASTElseifClause_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTElseifClause_condition(
		arg0,
		arg1,
	)
}

func zetasql_ASTElseifClause_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTElseifClause_condition(arg0, arg1)
}

func ASTElseifClause_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTElseifClause_body(
		arg0,
		arg1,
	)
}

func zetasql_ASTElseifClause_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTElseifClause_body(arg0, arg1)
}

func ASTElseifClause_if_stmt(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTElseifClause_if_stmt(
		arg0,
		arg1,
	)
}

func zetasql_ASTElseifClause_if_stmt(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTElseifClause_if_stmt(arg0, arg1)
}

func ASTElseifClauseList_elseif_clauses_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTElseifClauseList_elseif_clauses_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTElseifClauseList_elseif_clauses_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTElseifClauseList_elseif_clauses_num(arg0, arg1)
}

func ASTElseifClauseList_elseif_clause(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTElseifClauseList_elseif_clause(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTElseifClauseList_elseif_clause(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTElseifClauseList_elseif_clause(arg0, arg1, arg2)
}

func ASTIfStatement_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTIfStatement_condition(
		arg0,
		arg1,
	)
}

func zetasql_ASTIfStatement_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTIfStatement_condition(arg0, arg1)
}

func ASTIfStatement_then_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTIfStatement_then_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTIfStatement_then_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTIfStatement_then_list(arg0, arg1)
}

func ASTIfStatement_elseif_clauses(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTIfStatement_elseif_clauses(
		arg0,
		arg1,
	)
}

func zetasql_ASTIfStatement_elseif_clauses(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTIfStatement_elseif_clauses(arg0, arg1)
}

func ASTIfStatement_else_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTIfStatement_else_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTIfStatement_else_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTIfStatement_else_list(arg0, arg1)
}

func ASTWhenThenClause_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWhenThenClause_condition(
		arg0,
		arg1,
	)
}

func zetasql_ASTWhenThenClause_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWhenThenClause_condition(arg0, arg1)
}

func ASTWhenThenClause_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWhenThenClause_body(
		arg0,
		arg1,
	)
}

func zetasql_ASTWhenThenClause_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWhenThenClause_body(arg0, arg1)
}

func ASTWhenThenClause_case_stmt(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWhenThenClause_case_stmt(
		arg0,
		arg1,
	)
}

func zetasql_ASTWhenThenClause_case_stmt(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWhenThenClause_case_stmt(arg0, arg1)
}

func ASTWhenThenClauseList_when_then_clauses_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTWhenThenClauseList_when_then_clauses_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTWhenThenClauseList_when_then_clauses_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTWhenThenClauseList_when_then_clauses_num(arg0, arg1)
}

func ASTWhenThenClauseList_when_then_clause(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTWhenThenClauseList_when_then_clause(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTWhenThenClauseList_when_then_clause(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTWhenThenClauseList_when_then_clause(arg0, arg1, arg2)
}

func ASTCaseStatement_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCaseStatement_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTCaseStatement_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCaseStatement_expression(arg0, arg1)
}

func ASTCaseStatement_when_then_clauses(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCaseStatement_when_then_clauses(
		arg0,
		arg1,
	)
}

func zetasql_ASTCaseStatement_when_then_clauses(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCaseStatement_when_then_clauses(arg0, arg1)
}

func ASTCaseStatement_else_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCaseStatement_else_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCaseStatement_else_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCaseStatement_else_list(arg0, arg1)
}

func ASTHint_num_shards_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTHint_num_shards_hint(
		arg0,
		arg1,
	)
}

func zetasql_ASTHint_num_shards_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTHint_num_shards_hint(arg0, arg1)
}

func ASTHint_hint_entries_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTHint_hint_entries_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTHint_hint_entries_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTHint_hint_entries_num(arg0, arg1)
}

func ASTHint_hint_entry(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTHint_hint_entry(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTHint_hint_entry(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTHint_hint_entry(arg0, arg1, arg2)
}

func ASTHintEntry_qualifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTHintEntry_qualifier(
		arg0,
		arg1,
	)
}

func zetasql_ASTHintEntry_qualifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTHintEntry_qualifier(arg0, arg1)
}

func ASTHintEntry_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTHintEntry_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTHintEntry_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTHintEntry_name(arg0, arg1)
}

func ASTHintEntry_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTHintEntry_value(
		arg0,
		arg1,
	)
}

func zetasql_ASTHintEntry_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTHintEntry_value(arg0, arg1)
}

func ASTUnpivotInItemLabel_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUnpivotInItemLabel_label(
		arg0,
		arg1,
	)
}

func zetasql_ASTUnpivotInItemLabel_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUnpivotInItemLabel_label(arg0, arg1)
}

func ASTDescriptor_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDescriptor_columns(
		arg0,
		arg1,
	)
}

func zetasql_ASTDescriptor_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDescriptor_columns(arg0, arg1)
}

func ASTColumnSchema_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTColumnSchema_type_parameters(
		arg0,
		arg1,
	)
}

func zetasql_ASTColumnSchema_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTColumnSchema_type_parameters(arg0, arg1)
}

func ASTColumnSchema_generated_column_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTColumnSchema_generated_column_info(
		arg0,
		arg1,
	)
}

func zetasql_ASTColumnSchema_generated_column_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTColumnSchema_generated_column_info(arg0, arg1)
}

func ASTColumnSchema_default_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTColumnSchema_default_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTColumnSchema_default_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTColumnSchema_default_expression(arg0, arg1)
}

func ASTColumnSchema_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTColumnSchema_collate(
		arg0,
		arg1,
	)
}

func zetasql_ASTColumnSchema_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTColumnSchema_collate(arg0, arg1)
}

func ASTColumnSchema_attributes(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTColumnSchema_attributes(
		arg0,
		arg1,
	)
}

func zetasql_ASTColumnSchema_attributes(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTColumnSchema_attributes(arg0, arg1)
}

func ASTColumnSchema_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTColumnSchema_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTColumnSchema_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTColumnSchema_options_list(arg0, arg1)
}

func ASTColumnSchema_ContainsAttribute(arg0 unsafe.Pointer, arg1 int, arg2 *bool) {
	zetasql_ASTColumnSchema_ContainsAttribute(
		arg0,
		C.int(arg1),
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_ASTColumnSchema_ContainsAttribute(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.char) {
	C.export_zetasql_ASTColumnSchema_ContainsAttribute(arg0, arg1, arg2)
}

func ASTSimpleColumnSchema_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSimpleColumnSchema_type_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTSimpleColumnSchema_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSimpleColumnSchema_type_name(arg0, arg1)
}

func ASTArrayColumnSchema_element_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTArrayColumnSchema_element_schema(
		arg0,
		arg1,
	)
}

func zetasql_ASTArrayColumnSchema_element_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTArrayColumnSchema_element_schema(arg0, arg1)
}

func ASTTableConstraint_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTTableConstraint_constraint_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTTableConstraint_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTTableConstraint_constraint_name(arg0, arg1)
}

func ASTPrimaryKey_set_enforced(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTPrimaryKey_set_enforced(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTPrimaryKey_set_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTPrimaryKey_set_enforced(arg0, arg1)
}

func ASTPrimaryKey_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTPrimaryKey_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTPrimaryKey_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTPrimaryKey_enforced(arg0, arg1)
}

func ASTPrimaryKey_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTPrimaryKey_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTPrimaryKey_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTPrimaryKey_column_list(arg0, arg1)
}

func ASTPrimaryKey_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTPrimaryKey_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTPrimaryKey_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTPrimaryKey_options_list(arg0, arg1)
}

func ASTForeignKey_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTForeignKey_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTForeignKey_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTForeignKey_column_list(arg0, arg1)
}

func ASTForeignKey_reference(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTForeignKey_reference(
		arg0,
		arg1,
	)
}

func zetasql_ASTForeignKey_reference(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTForeignKey_reference(arg0, arg1)
}

func ASTForeignKey_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTForeignKey_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTForeignKey_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTForeignKey_options_list(arg0, arg1)
}

func ASTCheckConstraint_set_is_enforced(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTCheckConstraint_set_is_enforced(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTCheckConstraint_set_is_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTCheckConstraint_set_is_enforced(arg0, arg1)
}

func ASTCheckConstraint_is_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTCheckConstraint_is_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCheckConstraint_is_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTCheckConstraint_is_enforced(arg0, arg1)
}

func ASTCheckConstraint_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCheckConstraint_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTCheckConstraint_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCheckConstraint_expression(arg0, arg1)
}

func ASTCheckConstraint_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCheckConstraint_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCheckConstraint_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCheckConstraint_options_list(arg0, arg1)
}

func ASTDescriptorColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDescriptorColumn_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDescriptorColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDescriptorColumn_name(arg0, arg1)
}

func ASTDescriptorColumnList_descriptor_column_list_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTDescriptorColumnList_descriptor_column_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDescriptorColumnList_descriptor_column_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTDescriptorColumnList_descriptor_column_list_num(arg0, arg1)
}

func ASTDescriptorColumnList_descriptor_column_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTDescriptorColumnList_descriptor_column_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTDescriptorColumnList_descriptor_column_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTDescriptorColumnList_descriptor_column_list(arg0, arg1, arg2)
}

func ASTCreateEntityStatement_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateEntityStatement_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateEntityStatement_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateEntityStatement_type(arg0, arg1)
}

func ASTCreateEntityStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateEntityStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateEntityStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateEntityStatement_name(arg0, arg1)
}

func ASTCreateEntityStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateEntityStatement_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateEntityStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateEntityStatement_options_list(arg0, arg1)
}

func ASTCreateEntityStatement_json_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateEntityStatement_json_body(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateEntityStatement_json_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateEntityStatement_json_body(arg0, arg1)
}

func ASTCreateEntityStatement_text_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateEntityStatement_text_body(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateEntityStatement_text_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateEntityStatement_text_body(arg0, arg1)
}

func ASTRaiseStatement_message(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRaiseStatement_message(
		arg0,
		arg1,
	)
}

func zetasql_ASTRaiseStatement_message(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRaiseStatement_message(arg0, arg1)
}

func ASTRaiseStatement_is_rethrow(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTRaiseStatement_is_rethrow(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTRaiseStatement_is_rethrow(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTRaiseStatement_is_rethrow(arg0, arg1)
}

func ASTExceptionHandler_statement_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExceptionHandler_statement_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTExceptionHandler_statement_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExceptionHandler_statement_list(arg0, arg1)
}

func ASTExceptionHandlerList_exception_handler_list_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTExceptionHandlerList_exception_handler_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTExceptionHandlerList_exception_handler_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTExceptionHandlerList_exception_handler_list_num(arg0, arg1)
}

func ASTExceptionHandlerList_exception_handler_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTExceptionHandlerList_exception_handler_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTExceptionHandlerList_exception_handler_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTExceptionHandlerList_exception_handler_list(arg0, arg1, arg2)
}

func ASTBeginEndBlock_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTBeginEndBlock_label(
		arg0,
		arg1,
	)
}

func zetasql_ASTBeginEndBlock_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTBeginEndBlock_label(arg0, arg1)
}

func ASTBeginEndBlock_statement_list_node(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTBeginEndBlock_statement_list_node(
		arg0,
		arg1,
	)
}

func zetasql_ASTBeginEndBlock_statement_list_node(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTBeginEndBlock_statement_list_node(arg0, arg1)
}

func ASTBeginEndBlock_handler_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTBeginEndBlock_handler_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTBeginEndBlock_handler_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTBeginEndBlock_handler_list(arg0, arg1)
}

func ASTBeginEndBlock_statement_list_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTBeginEndBlock_statement_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTBeginEndBlock_statement_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTBeginEndBlock_statement_list_num(arg0, arg1)
}

func ASTBeginEndBlock_statement_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTBeginEndBlock_statement_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTBeginEndBlock_statement_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTBeginEndBlock_statement_list(arg0, arg1, arg2)
}

func ASTBeginEndBlock_has_exception_handler(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTBeginEndBlock_has_exception_handler(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTBeginEndBlock_has_exception_handler(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTBeginEndBlock_has_exception_handler(arg0, arg1)
}

func ASTIdentifierList_identifier_list_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTIdentifierList_identifier_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTIdentifierList_identifier_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTIdentifierList_identifier_list_num(arg0, arg1)
}

func ASTIdentifierList_identifier_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTIdentifierList_identifier_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTIdentifierList_identifier_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTIdentifierList_identifier_list(arg0, arg1, arg2)
}

func ASTVariableDeclaration_variable_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTVariableDeclaration_variable_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTVariableDeclaration_variable_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTVariableDeclaration_variable_list(arg0, arg1)
}

func ASTVariableDeclaration_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTVariableDeclaration_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTVariableDeclaration_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTVariableDeclaration_type(arg0, arg1)
}

func ASTVariableDeclaration_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTVariableDeclaration_default_value(
		arg0,
		arg1,
	)
}

func zetasql_ASTVariableDeclaration_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTVariableDeclaration_default_value(arg0, arg1)
}

func ASTUntilClause_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUntilClause_condition(
		arg0,
		arg1,
	)
}

func zetasql_ASTUntilClause_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUntilClause_condition(arg0, arg1)
}

func ASTUntilClause_repeat_stmt(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTUntilClause_repeat_stmt(
		arg0,
		arg1,
	)
}

func zetasql_ASTUntilClause_repeat_stmt(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTUntilClause_repeat_stmt(arg0, arg1)
}

func ASTBreakContinueStatement_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTBreakContinueStatement_label(
		arg0,
		arg1,
	)
}

func zetasql_ASTBreakContinueStatement_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTBreakContinueStatement_label(arg0, arg1)
}

func ASTBreakContinueStatement_set_keyword(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTBreakContinueStatement_set_keyword(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTBreakContinueStatement_set_keyword(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTBreakContinueStatement_set_keyword(arg0, arg1)
}

func ASTBreakContinueStatement_keyword(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTBreakContinueStatement_keyword(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTBreakContinueStatement_keyword(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTBreakContinueStatement_keyword(arg0, arg1)
}

func ASTBreakStatement_set_keyword(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTBreakStatement_set_keyword(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTBreakStatement_set_keyword(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTBreakStatement_set_keyword(arg0, arg1)
}

func ASTBreakStatement_keyword(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTBreakStatement_keyword(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTBreakStatement_keyword(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTBreakStatement_keyword(arg0, arg1)
}

func ASTContinueStatement_set_keyword(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTContinueStatement_set_keyword(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTContinueStatement_set_keyword(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTContinueStatement_set_keyword(arg0, arg1)
}

func ASTContinueStatement_keyword(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTContinueStatement_keyword(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTContinueStatement_keyword(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTContinueStatement_keyword(arg0, arg1)
}

func ASTDropPrivilegeRestrictionStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDropPrivilegeRestrictionStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDropPrivilegeRestrictionStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDropPrivilegeRestrictionStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropPrivilegeRestrictionStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTDropPrivilegeRestrictionStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDropPrivilegeRestrictionStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTDropPrivilegeRestrictionStatement_is_if_exists(arg0, arg1)
}

func ASTDropPrivilegeRestrictionStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropPrivilegeRestrictionStatement_privileges(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropPrivilegeRestrictionStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropPrivilegeRestrictionStatement_privileges(arg0, arg1)
}

func ASTDropPrivilegeRestrictionStatement_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropPrivilegeRestrictionStatement_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropPrivilegeRestrictionStatement_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropPrivilegeRestrictionStatement_object_type(arg0, arg1)
}

func ASTDropPrivilegeRestrictionStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropPrivilegeRestrictionStatement_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropPrivilegeRestrictionStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropPrivilegeRestrictionStatement_name_path(arg0, arg1)
}

func ASTDropRowAccessPolicyStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDropRowAccessPolicyStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDropRowAccessPolicyStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDropRowAccessPolicyStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropRowAccessPolicyStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTDropRowAccessPolicyStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDropRowAccessPolicyStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTDropRowAccessPolicyStatement_is_if_exists(arg0, arg1)
}

func ASTDropRowAccessPolicyStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropRowAccessPolicyStatement_table_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropRowAccessPolicyStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropRowAccessPolicyStatement_table_name(arg0, arg1)
}

func ASTDropRowAccessPolicyStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropRowAccessPolicyStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropRowAccessPolicyStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropRowAccessPolicyStatement_name(arg0, arg1)
}

func ASTCreatePrivilegeRestrictionStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreatePrivilegeRestrictionStatement_privileges(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreatePrivilegeRestrictionStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreatePrivilegeRestrictionStatement_privileges(arg0, arg1)
}

func ASTCreatePrivilegeRestrictionStatement_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreatePrivilegeRestrictionStatement_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreatePrivilegeRestrictionStatement_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreatePrivilegeRestrictionStatement_object_type(arg0, arg1)
}

func ASTCreatePrivilegeRestrictionStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreatePrivilegeRestrictionStatement_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreatePrivilegeRestrictionStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreatePrivilegeRestrictionStatement_name_path(arg0, arg1)
}

func ASTCreatePrivilegeRestrictionStatement_restrict_to(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreatePrivilegeRestrictionStatement_restrict_to(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreatePrivilegeRestrictionStatement_restrict_to(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreatePrivilegeRestrictionStatement_restrict_to(arg0, arg1)
}

func ASTCreateRowAccessPolicyStatement_set_has_access_keyword(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTCreateRowAccessPolicyStatement_set_has_access_keyword(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTCreateRowAccessPolicyStatement_set_has_access_keyword(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTCreateRowAccessPolicyStatement_set_has_access_keyword(arg0, arg1)
}

func ASTCreateRowAccessPolicyStatement_has_access_keyword(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTCreateRowAccessPolicyStatement_has_access_keyword(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCreateRowAccessPolicyStatement_has_access_keyword(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTCreateRowAccessPolicyStatement_has_access_keyword(arg0, arg1)
}

func ASTCreateRowAccessPolicyStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateRowAccessPolicyStatement_target_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateRowAccessPolicyStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateRowAccessPolicyStatement_target_path(arg0, arg1)
}

func ASTCreateRowAccessPolicyStatement_grant_to(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateRowAccessPolicyStatement_grant_to(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateRowAccessPolicyStatement_grant_to(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateRowAccessPolicyStatement_grant_to(arg0, arg1)
}

func ASTCreateRowAccessPolicyStatement_filter_using(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateRowAccessPolicyStatement_filter_using(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateRowAccessPolicyStatement_filter_using(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateRowAccessPolicyStatement_filter_using(arg0, arg1)
}

func ASTCreateRowAccessPolicyStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateRowAccessPolicyStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateRowAccessPolicyStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateRowAccessPolicyStatement_name(arg0, arg1)
}

func ASTDropStatement_set_drop_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDropStatement_set_drop_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDropStatement_set_drop_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDropStatement_set_drop_mode(arg0, arg1)
}

func ASTDropStatement_drop_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTDropStatement_drop_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDropStatement_drop_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTDropStatement_drop_mode(arg0, arg1)
}

func ASTDropStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDropStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDropStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDropStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTDropStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDropStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTDropStatement_is_if_exists(arg0, arg1)
}

func ASTDropStatement_set_schema_object_kind(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTDropStatement_set_schema_object_kind(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTDropStatement_set_schema_object_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTDropStatement_set_schema_object_kind(arg0, arg1)
}

func ASTDropStatement_schema_object_kind(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTDropStatement_schema_object_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTDropStatement_schema_object_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTDropStatement_schema_object_kind(arg0, arg1)
}

func ASTDropStatemnt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTDropStatemnt_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTDropStatemnt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTDropStatemnt_name(arg0, arg1)
}

func ASTSingleAssignment_variable(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSingleAssignment_variable(
		arg0,
		arg1,
	)
}

func zetasql_ASTSingleAssignment_variable(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSingleAssignment_variable(arg0, arg1)
}

func ASTSingleAssignment_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSingleAssignment_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTSingleAssignment_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSingleAssignment_expression(arg0, arg1)
}

func ASTParameterAssignment_parameter(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTParameterAssignment_parameter(
		arg0,
		arg1,
	)
}

func zetasql_ASTParameterAssignment_parameter(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTParameterAssignment_parameter(arg0, arg1)
}

func ASTParameterAssignment_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTParameterAssignment_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTParameterAssignment_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTParameterAssignment_expression(arg0, arg1)
}

func ASTSystemVariableAssignment_system_variable(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSystemVariableAssignment_system_variable(
		arg0,
		arg1,
	)
}

func zetasql_ASTSystemVariableAssignment_system_variable(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSystemVariableAssignment_system_variable(arg0, arg1)
}

func ASTSystemVariableAssignment_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTSystemVariableAssignment_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTSystemVariableAssignment_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTSystemVariableAssignment_expression(arg0, arg1)
}

func ASTAssignmentFromStruct_variables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAssignmentFromStruct_variables(
		arg0,
		arg1,
	)
}

func zetasql_ASTAssignmentFromStruct_variables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAssignmentFromStruct_variables(arg0, arg1)
}

func ASTAssignmentFromStruct_struct_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAssignmentFromStruct_struct_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTAssignmentFromStruct_struct_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAssignmentFromStruct_struct_expression(arg0, arg1)
}

func ASTCreateTableStmtBase_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateTableStmtBase_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateTableStmtBase_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateTableStmtBase_name(arg0, arg1)
}

func ASTCreateTableStmtBase_table_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateTableStmtBase_table_element_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateTableStmtBase_table_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateTableStmtBase_table_element_list(arg0, arg1)
}

func ASTCreateTableStmtBase_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateTableStmtBase_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateTableStmtBase_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateTableStmtBase_options_list(arg0, arg1)
}

func ASTCreateTableStmtBase_like_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateTableStmtBase_like_table_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateTableStmtBase_like_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateTableStmtBase_like_table_name(arg0, arg1)
}

func ASTCreateTableStmtBase_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateTableStmtBase_collate(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateTableStmtBase_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateTableStmtBase_collate(arg0, arg1)
}

func ASTCreateTableStatement_clone_data_source(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateTableStatement_clone_data_source(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateTableStatement_clone_data_source(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateTableStatement_clone_data_source(arg0, arg1)
}

func ASTCreateTableStatement_copy_data_source(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateTableStatement_copy_data_source(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateTableStatement_copy_data_source(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateTableStatement_copy_data_source(arg0, arg1)
}

func ASTCreateTableStatement_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateTableStatement_partition_by(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateTableStatement_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateTableStatement_partition_by(arg0, arg1)
}

func ASTCreateTableStatement_cluster_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateTableStatement_cluster_by(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateTableStatement_cluster_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateTableStatement_cluster_by(arg0, arg1)
}

func ASTCreateTableStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateTableStatement_query(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateTableStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateTableStatement_query(arg0, arg1)
}

func ASTCreateExternalTableStatement_with_partition_columns_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateExternalTableStatement_with_partition_columns_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateExternalTableStatement_with_partition_columns_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateExternalTableStatement_with_partition_columns_clause(arg0, arg1)
}

func ASTCreateExternalTableStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateExternalTableStatement_with_connection_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateExternalTableStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateExternalTableStatement_with_connection_clause(arg0, arg1)
}

func ASTCreateViewStatementBase_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateViewStatementBase_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateViewStatementBase_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateViewStatementBase_name(arg0, arg1)
}

func ASTCreateViewStatementBase_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateViewStatementBase_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateViewStatementBase_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateViewStatementBase_column_list(arg0, arg1)
}

func ASTCreateViewStatementBase_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateViewStatementBase_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateViewStatementBase_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateViewStatementBase_options_list(arg0, arg1)
}

func ASTCreateViewStatementBase_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateViewStatementBase_query(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateViewStatementBase_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateViewStatementBase_query(arg0, arg1)
}

func ASTCreateMaterializedViewStatement_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateMaterializedViewStatement_partition_by(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateMaterializedViewStatement_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateMaterializedViewStatement_partition_by(arg0, arg1)
}

func ASTCreateMaterializedViewStatement_cluster_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateMaterializedViewStatement_cluster_by(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateMaterializedViewStatement_cluster_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateMaterializedViewStatement_cluster_by(arg0, arg1)
}

func ASTLoopStatement_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTLoopStatement_label(
		arg0,
		arg1,
	)
}

func zetasql_ASTLoopStatement_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTLoopStatement_label(arg0, arg1)
}

func ASTLoopStatement_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTLoopStatement_body(
		arg0,
		arg1,
	)
}

func zetasql_ASTLoopStatement_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTLoopStatement_body(arg0, arg1)
}

func ASTLoopStatement_IsLoopStatement(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTLoopStatement_IsLoopStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTLoopStatement_IsLoopStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTLoopStatement_IsLoopStatement(arg0, arg1)
}

func ASTWhileStatement_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTWhileStatement_condition(
		arg0,
		arg1,
	)
}

func zetasql_ASTWhileStatement_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTWhileStatement_condition(arg0, arg1)
}

func ASTRepeatStatement_until_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTRepeatStatement_until_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTRepeatStatement_until_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTRepeatStatement_until_clause(arg0, arg1)
}

func ASTForInStatement_variable(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTForInStatement_variable(
		arg0,
		arg1,
	)
}

func zetasql_ASTForInStatement_variable(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTForInStatement_variable(arg0, arg1)
}

func ASTForInStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTForInStatement_query(
		arg0,
		arg1,
	)
}

func zetasql_ASTForInStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTForInStatement_query(arg0, arg1)
}

func ASTAlterStatementBase_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTAlterStatementBase_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTAlterStatementBase_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTAlterStatementBase_set_is_if_exists(arg0, arg1)
}

func ASTAlterStatementBase_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTAlterStatementBase_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAlterStatementBase_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTAlterStatementBase_is_if_exists(arg0, arg1)
}

func ASTAlterStatementBase_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterStatementBase_path(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterStatementBase_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterStatementBase_path(arg0, arg1)
}

func ASTAlterStatementBase_action_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterStatementBase_action_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterStatementBase_action_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterStatementBase_action_list(arg0, arg1)
}

func ASTAlterPrivilegeRestrictionStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterPrivilegeRestrictionStatement_privileges(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterPrivilegeRestrictionStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterPrivilegeRestrictionStatement_privileges(arg0, arg1)
}

func ASTAlterPrivilegeRestrictionStatement_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterPrivilegeRestrictionStatement_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterPrivilegeRestrictionStatement_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterPrivilegeRestrictionStatement_object_type(arg0, arg1)
}

func ASTAlterRowAccessPolicyStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterRowAccessPolicyStatement_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterRowAccessPolicyStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterRowAccessPolicyStatement_name(arg0, arg1)
}

func ASTAlterEntityStatement_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAlterEntityStatement_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTAlterEntityStatement_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAlterEntityStatement_type(arg0, arg1)
}

func ASTCreateFunctionStmtBase_set_determinism_level(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTCreateFunctionStmtBase_set_determinism_level(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTCreateFunctionStmtBase_set_determinism_level(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTCreateFunctionStmtBase_set_determinism_level(arg0, arg1)
}

func ASTCreateFunctionStmtBase_determinism_level(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTCreateFunctionStmtBase_determinism_level(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCreateFunctionStmtBase_determinism_level(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTCreateFunctionStmtBase_determinism_level(arg0, arg1)
}

func ASTCreateFunctionStmtBase_set_sql_security(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTCreateFunctionStmtBase_set_sql_security(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTCreateFunctionStmtBase_set_sql_security(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTCreateFunctionStmtBase_set_sql_security(arg0, arg1)
}

func ASTCreateFunctionStmtBase_sql_security(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTCreateFunctionStmtBase_sql_security(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCreateFunctionStmtBase_sql_security(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTCreateFunctionStmtBase_sql_security(arg0, arg1)
}

func ASTCreateFunctionStmtBase_function_declaration(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateFunctionStmtBase_function_declaration(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateFunctionStmtBase_function_declaration(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateFunctionStmtBase_function_declaration(arg0, arg1)
}

func ASTCreateFunctionStmtBase_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateFunctionStmtBase_language(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateFunctionStmtBase_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateFunctionStmtBase_language(arg0, arg1)
}

func ASTCreateFunctionStmtBase_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateFunctionStmtBase_code(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateFunctionStmtBase_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateFunctionStmtBase_code(arg0, arg1)
}

func ASTCreateFunctionStmtBase_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateFunctionStmtBase_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateFunctionStmtBase_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateFunctionStmtBase_options_list(arg0, arg1)
}

func ASTCreateFunctionStatement_set_is_aggregate(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTCreateFunctionStatement_set_is_aggregate(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTCreateFunctionStatement_set_is_aggregate(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTCreateFunctionStatement_set_is_aggregate(arg0, arg1)
}

func ASTCreateFunctionStatement_is_aggregate(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTCreateFunctionStatement_is_aggregate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCreateFunctionStatement_is_aggregate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTCreateFunctionStatement_is_aggregate(arg0, arg1)
}

func ASTCreateFunctionStatement_set_is_remote(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTCreateFunctionStatement_set_is_remote(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTCreateFunctionStatement_set_is_remote(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTCreateFunctionStatement_set_is_remote(arg0, arg1)
}

func ASTCreateFunctionStatement_is_remote(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ASTCreateFunctionStatement_is_remote(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTCreateFunctionStatement_is_remote(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ASTCreateFunctionStatement_is_remote(arg0, arg1)
}

func ASTCreateFunctionStatement_return_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateFunctionStatement_return_type(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateFunctionStatement_return_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateFunctionStatement_return_type(arg0, arg1)
}

func ASTCreateFunctionStatement_sql_function_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateFunctionStatement_sql_function_body(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateFunctionStatement_sql_function_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateFunctionStatement_sql_function_body(arg0, arg1)
}

func ASTCreateFunctionStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateFunctionStatement_with_connection_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateFunctionStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateFunctionStatement_with_connection_clause(arg0, arg1)
}

func ASTCreateTableFunctionStatement_return_tvf_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateTableFunctionStatement_return_tvf_schema(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateTableFunctionStatement_return_tvf_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateTableFunctionStatement_return_tvf_schema(arg0, arg1)
}

func ASTCreateTableFunctionStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTCreateTableFunctionStatement_query(
		arg0,
		arg1,
	)
}

func zetasql_ASTCreateTableFunctionStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTCreateTableFunctionStatement_query(arg0, arg1)
}

func ASTStructColumnSchema_struct_fields_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTStructColumnSchema_struct_fields_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTStructColumnSchema_struct_fields_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTStructColumnSchema_struct_fields_num(arg0, arg1)
}

func ASTStructColumnSchema_struct_field(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTStructColumnSchema_struct_field(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTStructColumnSchema_struct_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTStructColumnSchema_struct_field(arg0, arg1, arg2)
}

func ASTExecuteIntoClause_identifiers(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExecuteIntoClause_identifiers(
		arg0,
		arg1,
	)
}

func zetasql_ASTExecuteIntoClause_identifiers(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExecuteIntoClause_identifiers(arg0, arg1)
}

func ASTExecuteUsingArgument_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExecuteUsingArgument_expression(
		arg0,
		arg1,
	)
}

func zetasql_ASTExecuteUsingArgument_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExecuteUsingArgument_expression(arg0, arg1)
}

func ASTExecuteUsingArgument_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExecuteUsingArgument_alias(
		arg0,
		arg1,
	)
}

func zetasql_ASTExecuteUsingArgument_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExecuteUsingArgument_alias(arg0, arg1)
}

func ASTExecuteUsingClause_arguments_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTExecuteUsingClause_arguments_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTExecuteUsingClause_arguments_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTExecuteUsingClause_arguments_num(arg0, arg1)
}

func ASTExecuteUsingClause_argument(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ASTExecuteUsingClause_argument(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ASTExecuteUsingClause_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ASTExecuteUsingClause_argument(arg0, arg1, arg2)
}

func ASTExecuteImmediateStatement_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExecuteImmediateStatement_sql(
		arg0,
		arg1,
	)
}

func zetasql_ASTExecuteImmediateStatement_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExecuteImmediateStatement_sql(arg0, arg1)
}

func ASTExecuteImmediateStatement_into_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExecuteImmediateStatement_into_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTExecuteImmediateStatement_into_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExecuteImmediateStatement_into_clause(arg0, arg1)
}

func ASTExecuteImmediateStatement_using_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTExecuteImmediateStatement_using_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTExecuteImmediateStatement_using_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTExecuteImmediateStatement_using_clause(arg0, arg1)
}

func ASTAuxLoadDataFromFilesOptionsList_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAuxLoadDataFromFilesOptionsList_options_list(
		arg0,
		arg1,
	)
}

func zetasql_ASTAuxLoadDataFromFilesOptionsList_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAuxLoadDataFromFilesOptionsList_options_list(arg0, arg1)
}

func ASTAuxLoadDataStatement_set_insertion_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ASTAuxLoadDataStatement_set_insertion_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ASTAuxLoadDataStatement_set_insertion_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ASTAuxLoadDataStatement_set_insertion_mode(arg0, arg1)
}

func ASTAuxLoadDataStatement_insertion_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ASTAuxLoadDataStatement_insertion_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ASTAuxLoadDataStatement_insertion_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ASTAuxLoadDataStatement_insertion_mode(arg0, arg1)
}

func ASTAuxLoadDataStatement_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAuxLoadDataStatement_partition_by(
		arg0,
		arg1,
	)
}

func zetasql_ASTAuxLoadDataStatement_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAuxLoadDataStatement_partition_by(arg0, arg1)
}

func ASTAuxLoadDataStatement_cluster_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAuxLoadDataStatement_cluster_by(
		arg0,
		arg1,
	)
}

func zetasql_ASTAuxLoadDataStatement_cluster_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAuxLoadDataStatement_cluster_by(arg0, arg1)
}

func ASTAuxLoadDataStatement_from_files(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAuxLoadDataStatement_from_files(
		arg0,
		arg1,
	)
}

func zetasql_ASTAuxLoadDataStatement_from_files(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAuxLoadDataStatement_from_files(arg0, arg1)
}

func ASTAuxLoadDataStatement_with_partition_columns_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAuxLoadDataStatement_with_partition_columns_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTAuxLoadDataStatement_with_partition_columns_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAuxLoadDataStatement_with_partition_columns_clause(arg0, arg1)
}

func ASTAuxLoadDataStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTAuxLoadDataStatement_with_connection_clause(
		arg0,
		arg1,
	)
}

func zetasql_ASTAuxLoadDataStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTAuxLoadDataStatement_with_connection_clause(arg0, arg1)
}

func ASTLabel_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ASTLabel_name(
		arg0,
		arg1,
	)
}

func zetasql_ASTLabel_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ASTLabel_name(arg0, arg1)
}

func LanguageOptions_new(arg0 *unsafe.Pointer) {
	zetasql_LanguageOptions_new(
		arg0,
	)
}

func zetasql_LanguageOptions_new(arg0 *unsafe.Pointer) {
	C.export_zetasql_LanguageOptions_new(arg0)
}

func LanguageOptions_SupportsStatementKind(arg0 unsafe.Pointer, arg1 int, arg2 *bool) {
	zetasql_LanguageOptions_SupportsStatementKind(
		arg0,
		C.int(arg1),
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_LanguageOptions_SupportsStatementKind(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.char) {
	C.export_zetasql_LanguageOptions_SupportsStatementKind(arg0, arg1, arg2)
}

func LanguageOptions_SetSupportedStatementKinds(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_LanguageOptions_SetSupportedStatementKinds(
		arg0,
		arg1,
	)
}

func zetasql_LanguageOptions_SetSupportedStatementKinds(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_LanguageOptions_SetSupportedStatementKinds(arg0, arg1)
}

func LanguageOptions_SetSupportsAllStatementKinds(arg0 unsafe.Pointer) {
	zetasql_LanguageOptions_SetSupportsAllStatementKinds(
		arg0,
	)
}

func zetasql_LanguageOptions_SetSupportsAllStatementKinds(arg0 unsafe.Pointer) {
	C.export_zetasql_LanguageOptions_SetSupportsAllStatementKinds(arg0)
}

func LanguageOptions_AddSupportedStatementKind(arg0 unsafe.Pointer, arg1 int) {
	zetasql_LanguageOptions_AddSupportedStatementKind(
		arg0,
		C.int(arg1),
	)
}

func zetasql_LanguageOptions_AddSupportedStatementKind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_LanguageOptions_AddSupportedStatementKind(arg0, arg1)
}

func LanguageOptions_LanguageFeatureEnabled(arg0 unsafe.Pointer, arg1 int, arg2 *bool) {
	zetasql_LanguageOptions_LanguageFeatureEnabled(
		arg0,
		C.int(arg1),
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_LanguageOptions_LanguageFeatureEnabled(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.char) {
	C.export_zetasql_LanguageOptions_LanguageFeatureEnabled(arg0, arg1, arg2)
}

func LanguageOptions_SetLanguageVersion(arg0 unsafe.Pointer, arg1 int) {
	zetasql_LanguageOptions_SetLanguageVersion(
		arg0,
		C.int(arg1),
	)
}

func zetasql_LanguageOptions_SetLanguageVersion(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_LanguageOptions_SetLanguageVersion(arg0, arg1)
}

func LanguageOptions_EnableLanguageFeature(arg0 unsafe.Pointer, arg1 int) {
	zetasql_LanguageOptions_EnableLanguageFeature(
		arg0,
		C.int(arg1),
	)
}

func zetasql_LanguageOptions_EnableLanguageFeature(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_LanguageOptions_EnableLanguageFeature(arg0, arg1)
}

func LanguageOptions_SetEnabledLanguageFeatures(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_LanguageOptions_SetEnabledLanguageFeatures(
		arg0,
		arg1,
	)
}

func zetasql_LanguageOptions_SetEnabledLanguageFeatures(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_LanguageOptions_SetEnabledLanguageFeatures(arg0, arg1)
}

func LanguageOptions_EnabledLanguageFeatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_LanguageOptions_EnabledLanguageFeatures(
		arg0,
		arg1,
	)
}

func zetasql_LanguageOptions_EnabledLanguageFeatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_LanguageOptions_EnabledLanguageFeatures(arg0, arg1)
}

func LanguageOptions_EnabledLanguageFeaturesAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_LanguageOptions_EnabledLanguageFeaturesAsString(
		arg0,
		arg1,
	)
}

func zetasql_LanguageOptions_EnabledLanguageFeaturesAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_LanguageOptions_EnabledLanguageFeaturesAsString(arg0, arg1)
}

func LanguageOptions_DisableAllLanguageFeatures(arg0 unsafe.Pointer) {
	zetasql_LanguageOptions_DisableAllLanguageFeatures(
		arg0,
	)
}

func zetasql_LanguageOptions_DisableAllLanguageFeatures(arg0 unsafe.Pointer) {
	C.export_zetasql_LanguageOptions_DisableAllLanguageFeatures(arg0)
}

func LanguageOptions_EnableMaximumLanguageFeatures(arg0 unsafe.Pointer) {
	zetasql_LanguageOptions_EnableMaximumLanguageFeatures(
		arg0,
	)
}

func zetasql_LanguageOptions_EnableMaximumLanguageFeatures(arg0 unsafe.Pointer) {
	C.export_zetasql_LanguageOptions_EnableMaximumLanguageFeatures(arg0)
}

func LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment(arg0 unsafe.Pointer) {
	zetasql_LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment(
		arg0,
	)
}

func zetasql_LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment(arg0 unsafe.Pointer) {
	C.export_zetasql_LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment(arg0)
}

func LanguageOptions_set_name_resolution_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_LanguageOptions_set_name_resolution_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_LanguageOptions_set_name_resolution_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_LanguageOptions_set_name_resolution_mode(arg0, arg1)
}

func LanguageOptions_name_resolution_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_LanguageOptions_name_resolution_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_LanguageOptions_name_resolution_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_LanguageOptions_name_resolution_mode(arg0, arg1)
}

func LanguageOptions_set_product_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_LanguageOptions_set_product_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_LanguageOptions_set_product_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_LanguageOptions_set_product_mode(arg0, arg1)
}

func LanguageOptions_product_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_LanguageOptions_product_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_LanguageOptions_product_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_LanguageOptions_product_mode(arg0, arg1)
}

func LanguageOptions_SupportsProtoTypes(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_LanguageOptions_SupportsProtoTypes(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_LanguageOptions_SupportsProtoTypes(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_LanguageOptions_SupportsProtoTypes(arg0, arg1)
}

func LanguageOptions_set_error_on_deprecated_syntax(arg0 unsafe.Pointer, arg1 int) {
	zetasql_LanguageOptions_set_error_on_deprecated_syntax(
		arg0,
		C.int(arg1),
	)
}

func zetasql_LanguageOptions_set_error_on_deprecated_syntax(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_LanguageOptions_set_error_on_deprecated_syntax(arg0, arg1)
}

func LanguageOptions_error_on_deprecated_syntax(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_LanguageOptions_error_on_deprecated_syntax(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_LanguageOptions_error_on_deprecated_syntax(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_LanguageOptions_error_on_deprecated_syntax(arg0, arg1)
}

func LanguageOptions_SetSupportedGenericEntityTypes(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_LanguageOptions_SetSupportedGenericEntityTypes(
		arg0,
		arg1,
	)
}

func zetasql_LanguageOptions_SetSupportedGenericEntityTypes(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_LanguageOptions_SetSupportedGenericEntityTypes(arg0, arg1)
}

func LanguageOptions_GenericEntityTypeSupported(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_LanguageOptions_GenericEntityTypeSupported(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_LanguageOptions_GenericEntityTypeSupported(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_LanguageOptions_GenericEntityTypeSupported(arg0, arg1, arg2)
}

func LanguageOptions_IsReservedKeyword(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_LanguageOptions_IsReservedKeyword(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_LanguageOptions_IsReservedKeyword(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_LanguageOptions_IsReservedKeyword(arg0, arg1, arg2)
}

func LanguageOptions_EnableReservableKeyword(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	zetasql_LanguageOptions_EnableReservableKeyword(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func zetasql_LanguageOptions_EnableReservableKeyword(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_zetasql_LanguageOptions_EnableReservableKeyword(arg0, arg1, arg2, arg3)
}

func LanguageOptions_EnableAllReservableKeywords(arg0 unsafe.Pointer, arg1 int) {
	zetasql_LanguageOptions_EnableAllReservableKeywords(
		arg0,
		C.int(arg1),
	)
}

func zetasql_LanguageOptions_EnableAllReservableKeywords(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_LanguageOptions_EnableAllReservableKeywords(arg0, arg1)
}

func AnalyzerOptions_new(arg0 *unsafe.Pointer) {
	zetasql_AnalyzerOptions_new(
		arg0,
	)
}

func zetasql_AnalyzerOptions_new(arg0 *unsafe.Pointer) {
	C.export_zetasql_AnalyzerOptions_new(arg0)
}

func AnalyzerOptions_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_AnalyzerOptions_language(
		arg0,
		arg1,
	)
}

func zetasql_AnalyzerOptions_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_AnalyzerOptions_language(arg0, arg1)
}

func AnalyzerOptions_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_AnalyzerOptions_set_language(
		arg0,
		arg1,
	)
}

func zetasql_AnalyzerOptions_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_AnalyzerOptions_set_language(arg0, arg1)
}

func AnalyzerOptions_AddQueryParameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_AnalyzerOptions_AddQueryParameter(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_AnalyzerOptions_AddQueryParameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_AnalyzerOptions_AddQueryParameter(arg0, arg1, arg2, arg3)
}

func AnalyzerOptions_query_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_AnalyzerOptions_query_parameters(
		arg0,
		arg1,
	)
}

func zetasql_AnalyzerOptions_query_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_AnalyzerOptions_query_parameters(arg0, arg1)
}

func AnalyzerOptions_clear_query_parameters(arg0 unsafe.Pointer) {
	zetasql_AnalyzerOptions_clear_query_parameters(
		arg0,
	)
}

func zetasql_AnalyzerOptions_clear_query_parameters(arg0 unsafe.Pointer) {
	C.export_zetasql_AnalyzerOptions_clear_query_parameters(arg0)
}

func AnalyzerOptions_AddPositionalQueryParameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_AnalyzerOptions_AddPositionalQueryParameter(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_AnalyzerOptions_AddPositionalQueryParameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_AnalyzerOptions_AddPositionalQueryParameter(arg0, arg1, arg2)
}

func AnalyzerOptions_positional_query_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_AnalyzerOptions_positional_query_parameters(
		arg0,
		arg1,
	)
}

func zetasql_AnalyzerOptions_positional_query_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_AnalyzerOptions_positional_query_parameters(arg0, arg1)
}

func AnalyzerOptions_clear_positional_query_parameters(arg0 unsafe.Pointer) {
	zetasql_AnalyzerOptions_clear_positional_query_parameters(
		arg0,
	)
}

func zetasql_AnalyzerOptions_clear_positional_query_parameters(arg0 unsafe.Pointer) {
	C.export_zetasql_AnalyzerOptions_clear_positional_query_parameters(arg0)
}

func AnalyzerOptions_AddExpressionColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_AnalyzerOptions_AddExpressionColumn(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_AnalyzerOptions_AddExpressionColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_AnalyzerOptions_AddExpressionColumn(arg0, arg1, arg2, arg3)
}

func AnalyzerOptions_SetInScopeExpressionColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_AnalyzerOptions_SetInScopeExpressionColumn(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_AnalyzerOptions_SetInScopeExpressionColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_AnalyzerOptions_SetInScopeExpressionColumn(arg0, arg1, arg2, arg3)
}

func AnalyzerOptions_expression_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_AnalyzerOptions_expression_columns(
		arg0,
		arg1,
	)
}

func zetasql_AnalyzerOptions_expression_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_AnalyzerOptions_expression_columns(arg0, arg1)
}

func AnalyzerOptions_has_in_scope_expression_column(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_AnalyzerOptions_has_in_scope_expression_column(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_AnalyzerOptions_has_in_scope_expression_column(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_AnalyzerOptions_has_in_scope_expression_column(arg0, arg1)
}

func AnalyzerOptions_in_scope_expression_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_AnalyzerOptions_in_scope_expression_column_name(
		arg0,
		arg1,
	)
}

func zetasql_AnalyzerOptions_in_scope_expression_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_AnalyzerOptions_in_scope_expression_column_name(arg0, arg1)
}

func AnalyzerOptions_in_scope_expression_column_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_AnalyzerOptions_in_scope_expression_column_type(
		arg0,
		arg1,
	)
}

func zetasql_AnalyzerOptions_in_scope_expression_column_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_AnalyzerOptions_in_scope_expression_column_type(arg0, arg1)
}

func AnalyzerOptions_set_error_message_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_AnalyzerOptions_set_error_message_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_AnalyzerOptions_set_error_message_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_AnalyzerOptions_set_error_message_mode(arg0, arg1)
}

func AnalyzerOptions_error_message_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_AnalyzerOptions_error_message_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_AnalyzerOptions_error_message_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_AnalyzerOptions_error_message_mode(arg0, arg1)
}

func AnalyzerOptions_set_statement_context(arg0 unsafe.Pointer, arg1 int) {
	zetasql_AnalyzerOptions_set_statement_context(
		arg0,
		C.int(arg1),
	)
}

func zetasql_AnalyzerOptions_set_statement_context(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_AnalyzerOptions_set_statement_context(arg0, arg1)
}

func AnalyzerOptions_statement_context(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_AnalyzerOptions_statement_context(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_AnalyzerOptions_statement_context(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_AnalyzerOptions_statement_context(arg0, arg1)
}

func AnalyzerOptions_set_parse_location_record_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_AnalyzerOptions_set_parse_location_record_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_AnalyzerOptions_set_parse_location_record_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_AnalyzerOptions_set_parse_location_record_type(arg0, arg1)
}

func AnalyzerOptions_parse_location_record_type(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_AnalyzerOptions_parse_location_record_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_AnalyzerOptions_parse_location_record_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_AnalyzerOptions_parse_location_record_type(arg0, arg1)
}

func AnalyzerOptions_set_create_new_column_for_each_projected_output(arg0 unsafe.Pointer, arg1 int) {
	zetasql_AnalyzerOptions_set_create_new_column_for_each_projected_output(
		arg0,
		C.int(arg1),
	)
}

func zetasql_AnalyzerOptions_set_create_new_column_for_each_projected_output(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_AnalyzerOptions_set_create_new_column_for_each_projected_output(arg0, arg1)
}

func AnalyzerOptions_create_new_column_for_each_projected_output(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_AnalyzerOptions_create_new_column_for_each_projected_output(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_AnalyzerOptions_create_new_column_for_each_projected_output(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_AnalyzerOptions_create_new_column_for_each_projected_output(arg0, arg1)
}

func AnalyzerOptions_set_allow_undeclared_parameters(arg0 unsafe.Pointer, arg1 int) {
	zetasql_AnalyzerOptions_set_allow_undeclared_parameters(
		arg0,
		C.int(arg1),
	)
}

func zetasql_AnalyzerOptions_set_allow_undeclared_parameters(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_AnalyzerOptions_set_allow_undeclared_parameters(arg0, arg1)
}

func AnalyzerOptions_allow_undeclared_parameters(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_AnalyzerOptions_allow_undeclared_parameters(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_AnalyzerOptions_allow_undeclared_parameters(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_AnalyzerOptions_allow_undeclared_parameters(arg0, arg1)
}

func AnalyzerOptions_set_parameter_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_AnalyzerOptions_set_parameter_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_AnalyzerOptions_set_parameter_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_AnalyzerOptions_set_parameter_mode(arg0, arg1)
}

func AnalyzerOptions_parameter_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_AnalyzerOptions_parameter_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_AnalyzerOptions_parameter_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_AnalyzerOptions_parameter_mode(arg0, arg1)
}

func AnalyzerOptions_set_prune_unused_columns(arg0 unsafe.Pointer, arg1 int) {
	zetasql_AnalyzerOptions_set_prune_unused_columns(
		arg0,
		C.int(arg1),
	)
}

func zetasql_AnalyzerOptions_set_prune_unused_columns(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_AnalyzerOptions_set_prune_unused_columns(arg0, arg1)
}

func AnalyzerOptions_prune_unused_columns(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_AnalyzerOptions_prune_unused_columns(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_AnalyzerOptions_prune_unused_columns(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_AnalyzerOptions_prune_unused_columns(arg0, arg1)
}

func AnalyzerOptions_set_preserve_column_aliases(arg0 unsafe.Pointer, arg1 int) {
	zetasql_AnalyzerOptions_set_preserve_column_aliases(
		arg0,
		C.int(arg1),
	)
}

func zetasql_AnalyzerOptions_set_preserve_column_aliases(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_AnalyzerOptions_set_preserve_column_aliases(arg0, arg1)
}

func AnalyzerOptions_preserve_column_aliases(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_AnalyzerOptions_preserve_column_aliases(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_AnalyzerOptions_preserve_column_aliases(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_AnalyzerOptions_preserve_column_aliases(arg0, arg1)
}

func AnalyzerOptions_GetParserOptions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_AnalyzerOptions_GetParserOptions(
		arg0,
		arg1,
	)
}

func zetasql_AnalyzerOptions_GetParserOptions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_AnalyzerOptions_GetParserOptions(arg0, arg1)
}

func ValidateAnalyzerOptions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ValidateAnalyzerOptions(
		arg0,
		arg1,
	)
}

func zetasql_ValidateAnalyzerOptions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ValidateAnalyzerOptions(arg0, arg1)
}

func AnalyzeStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	zetasql_AnalyzeStatement(
		arg0,
		arg1,
		arg2,
		arg3,
		arg4,
	)
}

func zetasql_AnalyzeStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_zetasql_AnalyzeStatement(arg0, arg1, arg2, arg3, arg4)
}

func AnalyzeNextStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *bool, arg5 *unsafe.Pointer) {
	zetasql_AnalyzeNextStatement(
		arg0,
		arg1,
		arg2,
		arg3,
		(*C.char)(unsafe.Pointer(arg4)),
		arg5,
	)
}

func zetasql_AnalyzeNextStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *C.char, arg5 *unsafe.Pointer) {
	C.export_zetasql_AnalyzeNextStatement(arg0, arg1, arg2, arg3, arg4, arg5)
}

func AnalyzeExpression(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	zetasql_AnalyzeExpression(
		arg0,
		arg1,
		arg2,
		arg3,
		arg4,
	)
}

func zetasql_AnalyzeExpression(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_zetasql_AnalyzeExpression(arg0, arg1, arg2, arg3, arg4)
}

func AnalyzeStatementFromParserAST(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer, arg5 *unsafe.Pointer) {
	zetasql_AnalyzeStatementFromParserAST(
		arg0,
		arg1,
		arg2,
		arg3,
		arg4,
		arg5,
	)
}

func zetasql_AnalyzeStatementFromParserAST(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer, arg5 *unsafe.Pointer) {
	C.export_zetasql_AnalyzeStatementFromParserAST(arg0, arg1, arg2, arg3, arg4, arg5)
}

func AnalyzerOutput_resolved_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_AnalyzerOutput_resolved_statement(
		arg0,
		arg1,
	)
}

func zetasql_AnalyzerOutput_resolved_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_AnalyzerOutput_resolved_statement(arg0, arg1)
}

func ResolvedNode_node_kind(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedNode_node_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedNode_node_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedNode_node_kind(arg0, arg1)
}

func ResolvedNode_IsScan(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedNode_IsScan(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedNode_IsScan(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedNode_IsScan(arg0, arg1)
}

func ResolvedNode_IsExpression(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedNode_IsExpression(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedNode_IsExpression(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedNode_IsExpression(arg0, arg1)
}

func ResolvedNode_IsStatement(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedNode_IsStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedNode_IsStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedNode_IsStatement(arg0, arg1)
}

func ResolvedNode_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedNode_DebugString(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedNode_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedNode_DebugString(arg0, arg1)
}

func ResolvedNode_GetChildNodes_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedNode_GetChildNodes_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedNode_GetChildNodes_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedNode_GetChildNodes_num(arg0, arg1)
}

func ResolvedNode_GetChildNode(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_ResolvedNode_GetChildNode(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_ResolvedNode_GetChildNode(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_ResolvedNode_GetChildNode(arg0, arg1, arg2)
}

func ResolvedNode_GetParseLocationRangeOrNULL(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedNode_GetParseLocationRangeOrNULL(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedNode_GetParseLocationRangeOrNULL(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedNode_GetParseLocationRangeOrNULL(arg0, arg1)
}

func ResolvedNode_GetTreeDepth(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedNode_GetTreeDepth(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedNode_GetTreeDepth(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedNode_GetTreeDepth(arg0, arg1)
}

func ResolvedExpr_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExpr_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExpr_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExpr_type(arg0, arg1)
}

func ResolvedExpr_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExpr_set_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExpr_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExpr_set_type(arg0, arg1)
}

func ResolvedExpr_type_annotation_map(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExpr_type_annotation_map(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExpr_type_annotation_map(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExpr_type_annotation_map(arg0, arg1)
}

func ResolvedExpr_set_type_annotation_map(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExpr_set_type_annotation_map(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExpr_set_type_annotation_map(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExpr_set_type_annotation_map(arg0, arg1)
}

func ResolvedLiteral_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedLiteral_value(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedLiteral_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedLiteral_value(arg0, arg1)
}

func ResolvedLiteral_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedLiteral_set_value(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedLiteral_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedLiteral_set_value(arg0, arg1)
}

func ResolvedLiteral_has_explicit_type(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedLiteral_has_explicit_type(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedLiteral_has_explicit_type(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedLiteral_has_explicit_type(arg0, arg1)
}

func ResolvedLiteral_set_has_explicit_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedLiteral_set_has_explicit_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedLiteral_set_has_explicit_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedLiteral_set_has_explicit_type(arg0, arg1)
}

func ResolvedLiteral_float_literal_id(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedLiteral_float_literal_id(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedLiteral_float_literal_id(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedLiteral_float_literal_id(arg0, arg1)
}

func ResolvedLiteral_set_float_literal_id(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedLiteral_set_float_literal_id(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedLiteral_set_float_literal_id(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedLiteral_set_float_literal_id(arg0, arg1)
}

func ResolvedLiteral_preserve_in_literal_remover(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedLiteral_preserve_in_literal_remover(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedLiteral_preserve_in_literal_remover(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedLiteral_preserve_in_literal_remover(arg0, arg1)
}

func ResolvedLiteral_set_preserve_in_literal_remover(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedLiteral_set_preserve_in_literal_remover(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedLiteral_set_preserve_in_literal_remover(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedLiteral_set_preserve_in_literal_remover(arg0, arg1)
}

func ResolvedParameter_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedParameter_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedParameter_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedParameter_name(arg0, arg1)
}

func ResolvedParameter_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedParameter_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedParameter_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedParameter_set_name(arg0, arg1)
}

func ResolvedParameter_position(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedParameter_position(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedParameter_position(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedParameter_position(arg0, arg1)
}

func ResolvedParameter_set_position(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedParameter_set_position(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedParameter_set_position(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedParameter_set_position(arg0, arg1)
}

func ResolvedParameter_is_untyped(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedParameter_is_untyped(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedParameter_is_untyped(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedParameter_is_untyped(arg0, arg1)
}

func ResolvedParameter_set_is_untyped(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedParameter_set_is_untyped(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedParameter_set_is_untyped(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedParameter_set_is_untyped(arg0, arg1)
}

func ResolvedExpressionColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExpressionColumn_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExpressionColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExpressionColumn_name(arg0, arg1)
}

func ResolvedExpressionColumn_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExpressionColumn_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExpressionColumn_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExpressionColumn_set_name(arg0, arg1)
}

func ResolvedColumnRef_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumnRef_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnRef_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnRef_column(arg0, arg1)
}

func ResolvedColumnRef_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnRef_set_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnRef_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnRef_set_column(arg0, arg1)
}

func ResolvedColumnRef_is_correlated(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedColumnRef_is_correlated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedColumnRef_is_correlated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedColumnRef_is_correlated(arg0, arg1)
}

func ResolvedColumnRef_set_is_correlated(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedColumnRef_set_is_correlated(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedColumnRef_set_is_correlated(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedColumnRef_set_is_correlated(arg0, arg1)
}

func ResolvedConstant_constant(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedConstant_constant(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedConstant_constant(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedConstant_constant(arg0, arg1)
}

func ResolvedConstant_set_constant(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedConstant_set_constant(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedConstant_set_constant(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedConstant_set_constant(arg0, arg1)
}

func ResolvedSystemVariable_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSystemVariable_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSystemVariable_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSystemVariable_name_path(arg0, arg1)
}

func ResolvedSystemVariable_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSystemVariable_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSystemVariable_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSystemVariable_set_name_path(arg0, arg1)
}

func ResolvedSystemVariable_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSystemVariable_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSystemVariable_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSystemVariable_add_name_path(arg0, arg1)
}

func ResolvedInlineLambda_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedInlineLambda_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInlineLambda_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedInlineLambda_argument_list(arg0, arg1)
}

func ResolvedInlineLambda_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInlineLambda_set_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInlineLambda_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInlineLambda_set_argument_list(arg0, arg1)
}

func ResolvedInlineLambda_add_argument(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInlineLambda_add_argument(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInlineLambda_add_argument(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInlineLambda_add_argument(arg0, arg1)
}

func ResolvedInlineLambda_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedInlineLambda_parameter_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInlineLambda_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedInlineLambda_parameter_list(arg0, arg1)
}

func ResolvedInlineLambda_set_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInlineLambda_set_parameter_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInlineLambda_set_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInlineLambda_set_parameter_list(arg0, arg1)
}

func ResolvedInlineLambda_add_parameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInlineLambda_add_parameter(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInlineLambda_add_parameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInlineLambda_add_parameter(arg0, arg1)
}

func ResolvedInlineLambda_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedInlineLambda_body(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInlineLambda_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedInlineLambda_body(arg0, arg1)
}

func ResolvedInlineLambda_set_body(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInlineLambda_set_body(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInlineLambda_set_body(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInlineLambda_set_body(arg0, arg1)
}

func ResolvedFilterFieldArg_include(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedFilterFieldArg_include(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedFilterFieldArg_include(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedFilterFieldArg_include(arg0, arg1)
}

func ResolvedFilterFieldArg_set_include(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedFilterFieldArg_set_include(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedFilterFieldArg_set_include(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedFilterFieldArg_set_include(arg0, arg1)
}

func ResolvedFilterField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFilterField_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFilterField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFilterField_expr(arg0, arg1)
}

func ResolvedFilterField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFilterField_set_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFilterField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFilterField_set_expr(arg0, arg1)
}

func ResolvedFilterField_filter_field_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFilterField_filter_field_arg_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFilterField_filter_field_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFilterField_filter_field_arg_list(arg0, arg1)
}

func ResolvedFilterField_set_filter_field_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFilterField_set_filter_field_arg_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFilterField_set_filter_field_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFilterField_set_filter_field_arg_list(arg0, arg1)
}

func ResolvedFilterField_add_filter_field_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFilterField_add_filter_field_arg_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFilterField_add_filter_field_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFilterField_add_filter_field_arg_list(arg0, arg1)
}

func ResolvedFilterField_reset_cleared_required_fields(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedFilterField_reset_cleared_required_fields(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedFilterField_reset_cleared_required_fields(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedFilterField_reset_cleared_required_fields(arg0, arg1)
}

func ResolvedFilterField_set_reset_cleared_required_fields(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedFilterField_set_reset_cleared_required_fields(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedFilterField_set_reset_cleared_required_fields(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedFilterField_set_reset_cleared_required_fields(arg0, arg1)
}

func ResolvedFunctionCallBase_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_function(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_function(arg0, arg1)
}

func ResolvedFunctionCallBase_set_function(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_set_function(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_set_function(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_set_function(arg0, arg1)
}

func ResolvedFunctionCallBase_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_signature(arg0, arg1)
}

func ResolvedFunctionCallBase_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_set_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_set_signature(arg0, arg1)
}

func ResolvedFunctionCallBase_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_set_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_set_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_add_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_add_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_generic_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_generic_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_generic_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_generic_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_set_generic_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_set_generic_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_set_generic_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_set_generic_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_add_generic_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_add_generic_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_add_generic_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_add_generic_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_error_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedFunctionCallBase_error_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedFunctionCallBase_error_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedFunctionCallBase_error_mode(arg0, arg1)
}

func ResolvedFunctionCallBase_set_error_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedFunctionCallBase_set_error_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedFunctionCallBase_set_error_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedFunctionCallBase_set_error_mode(arg0, arg1)
}

func ResolvedFunctionCallBase_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_hint_list(arg0, arg1)
}

func ResolvedFunctionCallBase_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_set_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_set_hint_list(arg0, arg1)
}

func ResolvedFunctionCallBase_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_add_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_add_hint_list(arg0, arg1)
}

func ResolvedFunctionCallBase_collation_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_collation_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_collation_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_collation_list(arg0, arg1)
}

func ResolvedFunctionCallBase_set_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_set_collation_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_set_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_set_collation_list(arg0, arg1)
}

func ResolvedFunctionCallBase_add_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionCallBase_add_collation_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallBase_add_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallBase_add_collation_list(arg0, arg1)
}

func ResolvedFunctionCall_function_call_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionCall_function_call_info(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCall_function_call_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCall_function_call_info(arg0, arg1)
}

func ResolvedFunctionCall_set_function_call_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionCall_set_function_call_info(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCall_set_function_call_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCall_set_function_call_info(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_distinct(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedNonScalarFunctionCallBase_distinct(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedNonScalarFunctionCallBase_distinct(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedNonScalarFunctionCallBase_distinct(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_set_distinct(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedNonScalarFunctionCallBase_set_distinct(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedNonScalarFunctionCallBase_set_distinct(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedNonScalarFunctionCallBase_set_distinct(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_null_handling_modifier(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedNonScalarFunctionCallBase_null_handling_modifier(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedNonScalarFunctionCallBase_null_handling_modifier(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedNonScalarFunctionCallBase_null_handling_modifier(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_set_null_handling_modifier(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedNonScalarFunctionCallBase_set_null_handling_modifier(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedNonScalarFunctionCallBase_set_null_handling_modifier(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedNonScalarFunctionCallBase_set_null_handling_modifier(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_with_group_rows_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedNonScalarFunctionCallBase_with_group_rows_subquery(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedNonScalarFunctionCallBase_with_group_rows_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedNonScalarFunctionCallBase_with_group_rows_subquery(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_set_with_group_rows_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedNonScalarFunctionCallBase_set_with_group_rows_subquery(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedNonScalarFunctionCallBase_set_with_group_rows_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedNonScalarFunctionCallBase_set_with_group_rows_subquery(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_with_group_rows_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedNonScalarFunctionCallBase_with_group_rows_parameter_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedNonScalarFunctionCallBase_with_group_rows_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedNonScalarFunctionCallBase_with_group_rows_parameter_list(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_set_with_group_rows_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedNonScalarFunctionCallBase_set_with_group_rows_parameter_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedNonScalarFunctionCallBase_set_with_group_rows_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedNonScalarFunctionCallBase_set_with_group_rows_parameter_list(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_add_with_group_rows_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedNonScalarFunctionCallBase_add_with_group_rows_parameter_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedNonScalarFunctionCallBase_add_with_group_rows_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedNonScalarFunctionCallBase_add_with_group_rows_parameter_list(arg0, arg1)
}

func ResolvedAggregateFunctionCall_having_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAggregateFunctionCall_having_modifier(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateFunctionCall_having_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateFunctionCall_having_modifier(arg0, arg1)
}

func ResolvedAggregateFunctionCall_set_having_modifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateFunctionCall_set_having_modifier(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateFunctionCall_set_having_modifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateFunctionCall_set_having_modifier(arg0, arg1)
}

func ResolvedAggregateFunctionCall_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAggregateFunctionCall_order_by_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateFunctionCall_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateFunctionCall_order_by_item_list(arg0, arg1)
}

func ResolvedAggregateFunctionCall_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateFunctionCall_set_order_by_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateFunctionCall_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateFunctionCall_set_order_by_item_list(arg0, arg1)
}

func ResolvedAggregateFunctionCall_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateFunctionCall_add_order_by_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateFunctionCall_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateFunctionCall_add_order_by_item_list(arg0, arg1)
}

func ResolvedAggregateFunctionCall_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAggregateFunctionCall_limit(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateFunctionCall_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateFunctionCall_limit(arg0, arg1)
}

func ResolvedAggregateFunctionCall_set_limit(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateFunctionCall_set_limit(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateFunctionCall_set_limit(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateFunctionCall_set_limit(arg0, arg1)
}

func ResolvedAggregateFunctionCall_function_call_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAggregateFunctionCall_function_call_info(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateFunctionCall_function_call_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateFunctionCall_function_call_info(arg0, arg1)
}

func ResolvedAggregateFunctionCall_set_function_call_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateFunctionCall_set_function_call_info(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateFunctionCall_set_function_call_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateFunctionCall_set_function_call_info(arg0, arg1)
}

func ResolvedAnalyticFunctionCall_window_frame(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAnalyticFunctionCall_window_frame(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyticFunctionCall_window_frame(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyticFunctionCall_window_frame(arg0, arg1)
}

func ResolvedAnalyticFunctionCall_set_window_frame(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAnalyticFunctionCall_set_window_frame(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyticFunctionCall_set_window_frame(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyticFunctionCall_set_window_frame(arg0, arg1)
}

func ResolvedExtendedCastElement_from_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExtendedCastElement_from_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExtendedCastElement_from_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExtendedCastElement_from_type(arg0, arg1)
}

func ResolvedExtendedCastElement_set_from_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExtendedCastElement_set_from_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExtendedCastElement_set_from_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExtendedCastElement_set_from_type(arg0, arg1)
}

func ResolvedExtendedCastElement_to_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExtendedCastElement_to_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExtendedCastElement_to_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExtendedCastElement_to_type(arg0, arg1)
}

func ResolvedExtendedCastElement_set_to_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExtendedCastElement_set_to_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExtendedCastElement_set_to_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExtendedCastElement_set_to_type(arg0, arg1)
}

func ResolvedExtendedCastElement_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExtendedCastElement_function(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExtendedCastElement_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExtendedCastElement_function(arg0, arg1)
}

func ResolvedExtendedCastElement_set_function(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExtendedCastElement_set_function(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExtendedCastElement_set_function(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExtendedCastElement_set_function(arg0, arg1)
}

func ResolvedExtendedCast_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExtendedCast_element_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExtendedCast_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExtendedCast_element_list(arg0, arg1)
}

func ResolvedExtendedCast_set_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExtendedCast_set_element_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExtendedCast_set_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExtendedCast_set_element_list(arg0, arg1)
}

func ResolvedExtendedCast_add_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExtendedCast_add_element_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExtendedCast_add_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExtendedCast_add_element_list(arg0, arg1)
}

func ResolvedCast_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCast_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCast_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCast_expr(arg0, arg1)
}

func ResolvedCast_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCast_set_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCast_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCast_set_expr(arg0, arg1)
}

func ResolvedCast_return_null_on_error(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCast_return_null_on_error(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCast_return_null_on_error(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCast_return_null_on_error(arg0, arg1)
}

func ResolvedCast_set_return_null_on_error(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCast_set_return_null_on_error(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCast_set_return_null_on_error(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCast_set_return_null_on_error(arg0, arg1)
}

func ResolvedCast_extended_cast(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCast_extended_cast(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCast_extended_cast(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCast_extended_cast(arg0, arg1)
}

func ResolvedCast_set_extended_cast(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCast_set_extended_cast(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCast_set_extended_cast(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCast_set_extended_cast(arg0, arg1)
}

func ResolvedCast_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCast_format(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCast_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCast_format(arg0, arg1)
}

func ResolvedCast_set_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCast_set_format(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCast_set_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCast_set_format(arg0, arg1)
}

func ResolvedCast_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCast_time_zone(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCast_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCast_time_zone(arg0, arg1)
}

func ResolvedCast_set_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCast_set_time_zone(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCast_set_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCast_set_time_zone(arg0, arg1)
}

func ResolvedCast_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCast_type_parameters(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCast_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCast_type_parameters(arg0, arg1)
}

func ResolvedCast_set_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCast_set_type_parameters(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCast_set_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCast_set_type_parameters(arg0, arg1)
}

func ResolvedMakeStruct_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedMakeStruct_field_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMakeStruct_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedMakeStruct_field_list(arg0, arg1)
}

func ResolvedMakeStruct_set_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMakeStruct_set_field_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMakeStruct_set_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMakeStruct_set_field_list(arg0, arg1)
}

func ResolvedMakeStruct_add_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMakeStruct_add_field_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMakeStruct_add_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMakeStruct_add_field_list(arg0, arg1)
}

func ResolvedMakeProto_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedMakeProto_field_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMakeProto_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedMakeProto_field_list(arg0, arg1)
}

func ResolvedMakeProto_set_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMakeProto_set_field_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMakeProto_set_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMakeProto_set_field_list(arg0, arg1)
}

func ResolvedMakeProto_add_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMakeProto_add_field_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMakeProto_add_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMakeProto_add_field_list(arg0, arg1)
}

func ResolvedMakeProtoField_format(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedMakeProtoField_format(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedMakeProtoField_format(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedMakeProtoField_format(arg0, arg1)
}

func ResolvedMakeProtoField_set_format(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedMakeProtoField_set_format(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedMakeProtoField_set_format(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedMakeProtoField_set_format(arg0, arg1)
}

func ResolvedMakeProtoField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedMakeProtoField_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMakeProtoField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedMakeProtoField_expr(arg0, arg1)
}

func ResolvedMakeProtoField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMakeProtoField_set_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMakeProtoField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMakeProtoField_set_expr(arg0, arg1)
}

func ResolvedGetStructField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedGetStructField_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGetStructField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedGetStructField_expr(arg0, arg1)
}

func ResolvedGetStructField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGetStructField_set_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGetStructField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGetStructField_set_expr(arg0, arg1)
}

func ResolvedGetStructField_field_idx(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedGetStructField_field_idx(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedGetStructField_field_idx(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedGetStructField_field_idx(arg0, arg1)
}

func ResolvedGetStructField_set_field_idx(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedGetStructField_set_field_idx(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedGetStructField_set_field_idx(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedGetStructField_set_field_idx(arg0, arg1)
}

func ResolvedGetProtoField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedGetProtoField_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGetProtoField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedGetProtoField_expr(arg0, arg1)
}

func ResolvedGetProtoField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGetProtoField_set_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGetProtoField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGetProtoField_set_expr(arg0, arg1)
}

func ResolvedGetProtoField_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedGetProtoField_default_value(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGetProtoField_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedGetProtoField_default_value(arg0, arg1)
}

func ResolvedGetProtoField_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGetProtoField_set_default_value(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGetProtoField_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGetProtoField_set_default_value(arg0, arg1)
}

func ResolvedGetProtoField_get_has_bit(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedGetProtoField_get_has_bit(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedGetProtoField_get_has_bit(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedGetProtoField_get_has_bit(arg0, arg1)
}

func ResolvedGetProtoField_set_get_has_bit(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedGetProtoField_set_get_has_bit(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedGetProtoField_set_get_has_bit(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedGetProtoField_set_get_has_bit(arg0, arg1)
}

func ResolvedGetProtoField_format(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedGetProtoField_format(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedGetProtoField_format(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedGetProtoField_format(arg0, arg1)
}

func ResolvedGetProtoField_set_format(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedGetProtoField_set_format(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedGetProtoField_set_format(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedGetProtoField_set_format(arg0, arg1)
}

func ResolvedGetProtoField_return_default_value_when_unset(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedGetProtoField_return_default_value_when_unset(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedGetProtoField_return_default_value_when_unset(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedGetProtoField_return_default_value_when_unset(arg0, arg1)
}

func ResolvedGetProtoField_set_return_default_value_when_unset(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedGetProtoField_set_return_default_value_when_unset(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedGetProtoField_set_return_default_value_when_unset(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedGetProtoField_set_return_default_value_when_unset(arg0, arg1)
}

func ResolvedGetJsonField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedGetJsonField_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGetJsonField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedGetJsonField_expr(arg0, arg1)
}

func ResolvedGetJsonField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGetJsonField_set_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGetJsonField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGetJsonField_set_expr(arg0, arg1)
}

func ResolvedGetJsonField_field_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedGetJsonField_field_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGetJsonField_field_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedGetJsonField_field_name(arg0, arg1)
}

func ResolvedGetJsonField_set_field_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGetJsonField_set_field_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGetJsonField_set_field_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGetJsonField_set_field_name(arg0, arg1)
}

func ResolvedFlatten_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFlatten_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFlatten_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFlatten_expr(arg0, arg1)
}

func ResolvedFlatten_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFlatten_set_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFlatten_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFlatten_set_expr(arg0, arg1)
}

func ResolvedFlatten_get_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFlatten_get_field_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFlatten_get_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFlatten_get_field_list(arg0, arg1)
}

func ResolvedFlatten_set_get_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFlatten_set_get_field_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFlatten_set_get_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFlatten_set_get_field_list(arg0, arg1)
}

func ResolvedFlatten_add_get_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFlatten_add_get_field_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFlatten_add_get_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFlatten_add_get_field_list(arg0, arg1)
}

func ResolvedReplaceFieldItem_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedReplaceFieldItem_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReplaceFieldItem_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedReplaceFieldItem_expr(arg0, arg1)
}

func ResolvedReplaceFieldItem_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedReplaceFieldItem_set_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReplaceFieldItem_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedReplaceFieldItem_set_expr(arg0, arg1)
}

func ResolvedReplaceFieldItem_struct_index_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedReplaceFieldItem_struct_index_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReplaceFieldItem_struct_index_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedReplaceFieldItem_struct_index_path(arg0, arg1)
}

func ResolvedReplaceFieldItem_set_struct_index_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedReplaceFieldItem_set_struct_index_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReplaceFieldItem_set_struct_index_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedReplaceFieldItem_set_struct_index_path(arg0, arg1)
}

func ResolvedReplaceFieldItem_add_struct_index_path(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedReplaceFieldItem_add_struct_index_path(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedReplaceFieldItem_add_struct_index_path(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedReplaceFieldItem_add_struct_index_path(arg0, arg1)
}

func ResolvedReplaceField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedReplaceField_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReplaceField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedReplaceField_expr(arg0, arg1)
}

func ResolvedReplaceField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedReplaceField_set_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReplaceField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedReplaceField_set_expr(arg0, arg1)
}

func ResolvedReplaceField_replace_field_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedReplaceField_replace_field_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReplaceField_replace_field_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedReplaceField_replace_field_item_list(arg0, arg1)
}

func ResolvedReplaceField_set_replace_field_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedReplaceField_set_replace_field_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReplaceField_set_replace_field_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedReplaceField_set_replace_field_item_list(arg0, arg1)
}

func ResolvedReplaceField_add_replace_field_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedReplaceField_add_replace_field_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReplaceField_add_replace_field_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedReplaceField_add_replace_field_item_list(arg0, arg1)
}

func ResolvedSubqueryExpr_subquery_type(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedSubqueryExpr_subquery_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedSubqueryExpr_subquery_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedSubqueryExpr_subquery_type(arg0, arg1)
}

func ResolvedSubqueryExpr_set_subquery_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedSubqueryExpr_set_subquery_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedSubqueryExpr_set_subquery_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedSubqueryExpr_set_subquery_type(arg0, arg1)
}

func ResolvedSubqueryExpr_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSubqueryExpr_parameter_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSubqueryExpr_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSubqueryExpr_parameter_list(arg0, arg1)
}

func ResolvedSubqueryExpr_set_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSubqueryExpr_set_parameter_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSubqueryExpr_set_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSubqueryExpr_set_parameter_list(arg0, arg1)
}

func ResolvedSubqueryExpr_add_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSubqueryExpr_add_parameter_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSubqueryExpr_add_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSubqueryExpr_add_parameter_list(arg0, arg1)
}

func ResolvedSubqueryExpr_in_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSubqueryExpr_in_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSubqueryExpr_in_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSubqueryExpr_in_expr(arg0, arg1)
}

func ResolvedSubqueryExpr_set_in_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSubqueryExpr_set_in_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSubqueryExpr_set_in_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSubqueryExpr_set_in_expr(arg0, arg1)
}

func ResolvedSubqueryExpr_in_collation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSubqueryExpr_in_collation(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSubqueryExpr_in_collation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSubqueryExpr_in_collation(arg0, arg1)
}

func ResolvedSubqueryExpr_set_in_collation(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSubqueryExpr_set_in_collation(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSubqueryExpr_set_in_collation(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSubqueryExpr_set_in_collation(arg0, arg1)
}

func ResolvedSubqueryExpr_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSubqueryExpr_subquery(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSubqueryExpr_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSubqueryExpr_subquery(arg0, arg1)
}

func ResolvedSubqueryExpr_set_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSubqueryExpr_set_subquery(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSubqueryExpr_set_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSubqueryExpr_set_subquery(arg0, arg1)
}

func ResolvedSubqueryExpr_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSubqueryExpr_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSubqueryExpr_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSubqueryExpr_hint_list(arg0, arg1)
}

func ResolvedSubqueryExpr_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSubqueryExpr_set_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSubqueryExpr_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSubqueryExpr_set_hint_list(arg0, arg1)
}

func ResolvedSubqueryExpr_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSubqueryExpr_add_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSubqueryExpr_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSubqueryExpr_add_hint_list(arg0, arg1)
}

func ResolvedLetExpr_assignment_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedLetExpr_assignment_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedLetExpr_assignment_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedLetExpr_assignment_list(arg0, arg1)
}

func ResolvedLetExpr_set_assignment_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedLetExpr_set_assignment_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedLetExpr_set_assignment_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedLetExpr_set_assignment_list(arg0, arg1)
}

func ResolvedLetExpr_add_assignment_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedLetExpr_add_assignment_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedLetExpr_add_assignment_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedLetExpr_add_assignment_list(arg0, arg1)
}

func ResolvedLetExpr_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedLetExpr_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedLetExpr_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedLetExpr_expr(arg0, arg1)
}

func ResolvedLetExpr_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedLetExpr_set_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedLetExpr_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedLetExpr_set_expr(arg0, arg1)
}

func ResolvedScan_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedScan_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedScan_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedScan_column_list(arg0, arg1)
}

func ResolvedScan_set_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedScan_set_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedScan_set_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedScan_set_column_list(arg0, arg1)
}

func ResolvedScan_add_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedScan_add_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedScan_add_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedScan_add_column_list(arg0, arg1)
}

func ResolvedScan_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedScan_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedScan_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedScan_hint_list(arg0, arg1)
}

func ResolvedScan_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedScan_set_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedScan_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedScan_set_hint_list(arg0, arg1)
}

func ResolvedScan_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedScan_add_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedScan_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedScan_add_hint_list(arg0, arg1)
}

func ResolvedScan_is_ordered(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedScan_is_ordered(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedScan_is_ordered(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedScan_is_ordered(arg0, arg1)
}

func ResolvedScan_set_is_ordered(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedScan_set_is_ordered(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedScan_set_is_ordered(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedScan_set_is_ordered(arg0, arg1)
}

func ResolvedModel_model(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedModel_model(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedModel_model(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedModel_model(arg0, arg1)
}

func ResolvedModel_set_model(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedModel_set_model(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedModel_set_model(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedModel_set_model(arg0, arg1)
}

func ResolvedConnection_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedConnection_connection(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedConnection_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedConnection_connection(arg0, arg1)
}

func ResolvedConnection_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedConnection_set_connection(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedConnection_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedConnection_set_connection(arg0, arg1)
}

func ResolvedDescriptor_descriptor_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDescriptor_descriptor_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDescriptor_descriptor_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDescriptor_descriptor_column_list(arg0, arg1)
}

func ResolvedDescriptor_set_descriptor_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDescriptor_set_descriptor_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDescriptor_set_descriptor_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDescriptor_set_descriptor_column_list(arg0, arg1)
}

func ResolvedDescriptor_add_descriptor_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDescriptor_add_descriptor_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDescriptor_add_descriptor_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDescriptor_add_descriptor_column_list(arg0, arg1)
}

func ResolvedDescriptor_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDescriptor_descriptor_column_name_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDescriptor_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDescriptor_descriptor_column_name_list(arg0, arg1)
}

func ResolvedDescriptor_set_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDescriptor_set_descriptor_column_name_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDescriptor_set_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDescriptor_set_descriptor_column_name_list(arg0, arg1)
}

func ResolvedDescriptor_add_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDescriptor_add_descriptor_column_name_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDescriptor_add_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDescriptor_add_descriptor_column_name_list(arg0, arg1)
}

func ResolvedTableScan_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedTableScan_table(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTableScan_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedTableScan_table(arg0, arg1)
}

func ResolvedTableScan_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedTableScan_set_table(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTableScan_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedTableScan_set_table(arg0, arg1)
}

func ResolvedTableScan_for_system_time_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedTableScan_for_system_time_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTableScan_for_system_time_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedTableScan_for_system_time_expr(arg0, arg1)
}

func ResolvedTableScan_set_for_system_time_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedTableScan_set_for_system_time_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTableScan_set_for_system_time_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedTableScan_set_for_system_time_expr(arg0, arg1)
}

func ResolvedTableScan_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedTableScan_column_index_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTableScan_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedTableScan_column_index_list(arg0, arg1)
}

func ResolvedTableScan_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedTableScan_set_column_index_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTableScan_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedTableScan_set_column_index_list(arg0, arg1)
}

func ResolvedTableScan_add_column_index_list(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedTableScan_add_column_index_list(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedTableScan_add_column_index_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedTableScan_add_column_index_list(arg0, arg1)
}

func ResolvedTableScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedTableScan_alias(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTableScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedTableScan_alias(arg0, arg1)
}

func ResolvedTableScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedTableScan_set_alias(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTableScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedTableScan_set_alias(arg0, arg1)
}

func ResolvedJoinScan_join_type(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedJoinScan_join_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedJoinScan_join_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedJoinScan_join_type(arg0, arg1)
}

func ResolvedJoinScan_set_join_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedJoinScan_set_join_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedJoinScan_set_join_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedJoinScan_set_join_type(arg0, arg1)
}

func ResolvedJoinScan_left_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedJoinScan_left_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedJoinScan_left_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedJoinScan_left_scan(arg0, arg1)
}

func ResolvedJoinScan_set_left_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedJoinScan_set_left_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedJoinScan_set_left_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedJoinScan_set_left_scan(arg0, arg1)
}

func ResolvedJoinScan_right_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedJoinScan_right_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedJoinScan_right_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedJoinScan_right_scan(arg0, arg1)
}

func ResolvedJoinScan_set_right_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedJoinScan_set_right_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedJoinScan_set_right_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedJoinScan_set_right_scan(arg0, arg1)
}

func ResolvedJoinScan_join_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedJoinScan_join_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedJoinScan_join_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedJoinScan_join_expr(arg0, arg1)
}

func ResolvedJoinScan_set_join_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedJoinScan_set_join_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedJoinScan_set_join_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedJoinScan_set_join_expr(arg0, arg1)
}

func ResolvedArrayScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedArrayScan_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArrayScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedArrayScan_input_scan(arg0, arg1)
}

func ResolvedArrayScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedArrayScan_set_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArrayScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedArrayScan_set_input_scan(arg0, arg1)
}

func ResolvedArrayScan_array_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedArrayScan_array_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArrayScan_array_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedArrayScan_array_expr(arg0, arg1)
}

func ResolvedArrayScan_set_array_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedArrayScan_set_array_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArrayScan_set_array_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedArrayScan_set_array_expr(arg0, arg1)
}

func ResolvedArrayScan_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedArrayScan_element_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArrayScan_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedArrayScan_element_column(arg0, arg1)
}

func ResolvedArrayScan_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedArrayScan_set_element_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArrayScan_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedArrayScan_set_element_column(arg0, arg1)
}

func ResolvedArrayScan_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedArrayScan_array_offset_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArrayScan_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedArrayScan_array_offset_column(arg0, arg1)
}

func ResolvedArrayScan_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedArrayScan_set_array_offset_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArrayScan_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedArrayScan_set_array_offset_column(arg0, arg1)
}

func ResolvedArrayScan_join_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedArrayScan_join_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArrayScan_join_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedArrayScan_join_expr(arg0, arg1)
}

func ResolvedArrayScan_set_join_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedArrayScan_set_join_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArrayScan_set_join_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedArrayScan_set_join_expr(arg0, arg1)
}

func ResolvedArrayScan_is_outer(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedArrayScan_is_outer(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedArrayScan_is_outer(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedArrayScan_is_outer(arg0, arg1)
}

func ResolvedArrayScan_set_is_outer(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedArrayScan_set_is_outer(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedArrayScan_set_is_outer(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedArrayScan_set_is_outer(arg0, arg1)
}

func ResolvedColumnHolder_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumnHolder_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnHolder_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnHolder_column(arg0, arg1)
}

func ResolvedColumnHolder_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnHolder_set_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnHolder_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnHolder_set_column(arg0, arg1)
}

func ResolvedFilterScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFilterScan_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFilterScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFilterScan_input_scan(arg0, arg1)
}

func ResolvedFilterScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFilterScan_set_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFilterScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFilterScan_set_input_scan(arg0, arg1)
}

func ResolvedFilterScan_filter_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFilterScan_filter_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFilterScan_filter_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFilterScan_filter_expr(arg0, arg1)
}

func ResolvedFilterScan_set_filter_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFilterScan_set_filter_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFilterScan_set_filter_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFilterScan_set_filter_expr(arg0, arg1)
}

func ResolvedGroupingSet_group_by_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedGroupingSet_group_by_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGroupingSet_group_by_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedGroupingSet_group_by_column_list(arg0, arg1)
}

func ResolvedGroupingSet_set_group_by_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGroupingSet_set_group_by_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGroupingSet_set_group_by_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGroupingSet_set_group_by_column_list(arg0, arg1)
}

func ResolvedGroupingSet_add_group_by_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGroupingSet_add_group_by_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGroupingSet_add_group_by_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGroupingSet_add_group_by_column_list(arg0, arg1)
}

func ResolvedAggregateScanBase_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAggregateScanBase_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScanBase_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScanBase_input_scan(arg0, arg1)
}

func ResolvedAggregateScanBase_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateScanBase_set_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScanBase_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScanBase_set_input_scan(arg0, arg1)
}

func ResolvedAggregateScanBase_group_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAggregateScanBase_group_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScanBase_group_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScanBase_group_by_list(arg0, arg1)
}

func ResolvedAggregateScanBase_set_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateScanBase_set_group_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScanBase_set_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScanBase_set_group_by_list(arg0, arg1)
}

func ResolvedAggregateScanBase_add_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateScanBase_add_group_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScanBase_add_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScanBase_add_group_by_list(arg0, arg1)
}

func ResolvedAggregateScanBase_collation_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAggregateScanBase_collation_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScanBase_collation_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScanBase_collation_list(arg0, arg1)
}

func ResolvedAggregateScanBase_set_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateScanBase_set_collation_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScanBase_set_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScanBase_set_collation_list(arg0, arg1)
}

func ResolvedAggregateScanBase_add_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateScanBase_add_collation_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScanBase_add_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScanBase_add_collation_list(arg0, arg1)
}

func ResolvedAggregateScanBase_aggregate_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAggregateScanBase_aggregate_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScanBase_aggregate_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScanBase_aggregate_list(arg0, arg1)
}

func ResolvedAggregateScanBase_set_aggregate_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateScanBase_set_aggregate_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScanBase_set_aggregate_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScanBase_set_aggregate_list(arg0, arg1)
}

func ResolvedAggregateScanBase_add_aggregate_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateScanBase_add_aggregate_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScanBase_add_aggregate_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScanBase_add_aggregate_list(arg0, arg1)
}

func ResolvedAggregateScan_grouping_set_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAggregateScan_grouping_set_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScan_grouping_set_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScan_grouping_set_list(arg0, arg1)
}

func ResolvedAggregateScan_set_grouping_set_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateScan_set_grouping_set_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScan_set_grouping_set_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScan_set_grouping_set_list(arg0, arg1)
}

func ResolvedAggregateScan_add_grouping_set_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateScan_add_grouping_set_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScan_add_grouping_set_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScan_add_grouping_set_list(arg0, arg1)
}

func ResolvedAggregateScan_rollup_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAggregateScan_rollup_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScan_rollup_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScan_rollup_column_list(arg0, arg1)
}

func ResolvedAggregateScan_set_rollup_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateScan_set_rollup_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScan_set_rollup_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScan_set_rollup_column_list(arg0, arg1)
}

func ResolvedAggregateScan_add_rollup_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateScan_add_rollup_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateScan_add_rollup_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateScan_add_rollup_column_list(arg0, arg1)
}

func ResolvedAnonymizedAggregateScan_k_threshold_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAnonymizedAggregateScan_k_threshold_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnonymizedAggregateScan_k_threshold_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAnonymizedAggregateScan_k_threshold_expr(arg0, arg1)
}

func ResolvedAnonymizedAggregateScan_set_k_threshold_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAnonymizedAggregateScan_set_k_threshold_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnonymizedAggregateScan_set_k_threshold_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAnonymizedAggregateScan_set_k_threshold_expr(arg0, arg1)
}

func ResolvedAnonymizedAggregateScan_anonymization_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAnonymizedAggregateScan_anonymization_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnonymizedAggregateScan_anonymization_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAnonymizedAggregateScan_anonymization_option_list(arg0, arg1)
}

func ResolvedAnonymizedAggregateScan_set_anonymization_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAnonymizedAggregateScan_set_anonymization_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnonymizedAggregateScan_set_anonymization_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAnonymizedAggregateScan_set_anonymization_option_list(arg0, arg1)
}

func ResolvedAnonymizedAggregateScan_add_anonymization_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAnonymizedAggregateScan_add_anonymization_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnonymizedAggregateScan_add_anonymization_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAnonymizedAggregateScan_add_anonymization_option_list(arg0, arg1)
}

func ResolvedSetOperationItem_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSetOperationItem_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetOperationItem_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSetOperationItem_scan(arg0, arg1)
}

func ResolvedSetOperationItem_set_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSetOperationItem_set_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetOperationItem_set_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSetOperationItem_set_scan(arg0, arg1)
}

func ResolvedSetOperationItem_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSetOperationItem_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetOperationItem_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSetOperationItem_output_column_list(arg0, arg1)
}

func ResolvedSetOperationItem_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSetOperationItem_set_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetOperationItem_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSetOperationItem_set_output_column_list(arg0, arg1)
}

func ResolvedSetOperationItem_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSetOperationItem_add_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetOperationItem_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSetOperationItem_add_output_column_list(arg0, arg1)
}

func ResolvedSetOperationScan_op_type(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedSetOperationScan_op_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedSetOperationScan_op_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedSetOperationScan_op_type(arg0, arg1)
}

func ResolvedSetOperationScan_set_op_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedSetOperationScan_set_op_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedSetOperationScan_set_op_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedSetOperationScan_set_op_type(arg0, arg1)
}

func ResolvedSetOperationScan_input_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSetOperationScan_input_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetOperationScan_input_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSetOperationScan_input_item_list(arg0, arg1)
}

func ResolvedSetOperationScan_set_input_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSetOperationScan_set_input_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetOperationScan_set_input_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSetOperationScan_set_input_item_list(arg0, arg1)
}

func ResolvedSetOperationScan_add_input_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSetOperationScan_add_input_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetOperationScan_add_input_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSetOperationScan_add_input_item_list(arg0, arg1)
}

func ResolvedOrderByScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedOrderByScan_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOrderByScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedOrderByScan_input_scan(arg0, arg1)
}

func ResolvedOrderByScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedOrderByScan_set_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOrderByScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedOrderByScan_set_input_scan(arg0, arg1)
}

func ResolvedOrderByScan_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedOrderByScan_order_by_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOrderByScan_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedOrderByScan_order_by_item_list(arg0, arg1)
}

func ResolvedOrderByScan_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedOrderByScan_set_order_by_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOrderByScan_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedOrderByScan_set_order_by_item_list(arg0, arg1)
}

func ResolvedOrderByScan_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedOrderByScan_add_order_by_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOrderByScan_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedOrderByScan_add_order_by_item_list(arg0, arg1)
}

func ResolvedLimitOffsetScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedLimitOffsetScan_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedLimitOffsetScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedLimitOffsetScan_input_scan(arg0, arg1)
}

func ResolvedLimitOffsetScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedLimitOffsetScan_set_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedLimitOffsetScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedLimitOffsetScan_set_input_scan(arg0, arg1)
}

func ResolvedLimitOffsetScan_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedLimitOffsetScan_limit(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedLimitOffsetScan_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedLimitOffsetScan_limit(arg0, arg1)
}

func ResolvedLimitOffsetScan_set_limit(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedLimitOffsetScan_set_limit(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedLimitOffsetScan_set_limit(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedLimitOffsetScan_set_limit(arg0, arg1)
}

func ResolvedLimitOffsetScan_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedLimitOffsetScan_offset(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedLimitOffsetScan_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedLimitOffsetScan_offset(arg0, arg1)
}

func ResolvedLimitOffsetScan_set_offset(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedLimitOffsetScan_set_offset(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedLimitOffsetScan_set_offset(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedLimitOffsetScan_set_offset(arg0, arg1)
}

func ResolvedWithRefScan_with_query_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedWithRefScan_with_query_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWithRefScan_with_query_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedWithRefScan_with_query_name(arg0, arg1)
}

func ResolvedWithRefScan_set_with_query_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWithRefScan_set_with_query_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWithRefScan_set_with_query_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWithRefScan_set_with_query_name(arg0, arg1)
}

func ResolvedAnalyticScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAnalyticScan_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyticScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyticScan_input_scan(arg0, arg1)
}

func ResolvedAnalyticScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAnalyticScan_set_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyticScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyticScan_set_input_scan(arg0, arg1)
}

func ResolvedAnalyticScan_function_group_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAnalyticScan_function_group_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyticScan_function_group_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyticScan_function_group_list(arg0, arg1)
}

func ResolvedAnalyticScan_set_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAnalyticScan_set_function_group_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyticScan_set_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyticScan_set_function_group_list(arg0, arg1)
}

func ResolvedAnalyticScan_add_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAnalyticScan_add_function_group_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyticScan_add_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyticScan_add_function_group_list(arg0, arg1)
}

func ResolvedSampleScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSampleScan_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSampleScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSampleScan_input_scan(arg0, arg1)
}

func ResolvedSampleScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSampleScan_set_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSampleScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSampleScan_set_input_scan(arg0, arg1)
}

func ResolvedSampleScan_method(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSampleScan_method(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSampleScan_method(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSampleScan_method(arg0, arg1)
}

func ResolvedSampleScan_set_method(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSampleScan_set_method(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSampleScan_set_method(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSampleScan_set_method(arg0, arg1)
}

func ResolvedSampleScan_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSampleScan_size(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSampleScan_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSampleScan_size(arg0, arg1)
}

func ResolvedSampleScan_set_size(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSampleScan_set_size(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSampleScan_set_size(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSampleScan_set_size(arg0, arg1)
}

func ResolvedSampleScan_unit(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedSampleScan_unit(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedSampleScan_unit(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedSampleScan_unit(arg0, arg1)
}

func ResolvedSampleScan_set_unit(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedSampleScan_set_unit(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedSampleScan_set_unit(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedSampleScan_set_unit(arg0, arg1)
}

func ResolvedSampleScan_repeatable_argument(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSampleScan_repeatable_argument(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSampleScan_repeatable_argument(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSampleScan_repeatable_argument(arg0, arg1)
}

func ResolvedSampleScan_set_repeatable_argument(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSampleScan_set_repeatable_argument(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSampleScan_set_repeatable_argument(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSampleScan_set_repeatable_argument(arg0, arg1)
}

func ResolvedSampleScan_weight_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSampleScan_weight_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSampleScan_weight_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSampleScan_weight_column(arg0, arg1)
}

func ResolvedSampleScan_set_weight_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSampleScan_set_weight_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSampleScan_set_weight_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSampleScan_set_weight_column(arg0, arg1)
}

func ResolvedSampleScan_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSampleScan_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSampleScan_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSampleScan_partition_by_list(arg0, arg1)
}

func ResolvedSampleScan_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSampleScan_set_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSampleScan_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSampleScan_set_partition_by_list(arg0, arg1)
}

func ResolvedSampleScan_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSampleScan_add_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSampleScan_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSampleScan_add_partition_by_list(arg0, arg1)
}

func ResolvedComputedColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedComputedColumn_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedComputedColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedComputedColumn_column(arg0, arg1)
}

func ResolvedComputedColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedComputedColumn_set_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedComputedColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedComputedColumn_set_column(arg0, arg1)
}

func ResolvedComputedColumn_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedComputedColumn_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedComputedColumn_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedComputedColumn_expr(arg0, arg1)
}

func ResolvedComputedColumn_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedComputedColumn_set_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedComputedColumn_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedComputedColumn_set_expr(arg0, arg1)
}

func ResolvedOrderByItem_column_ref(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedOrderByItem_column_ref(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOrderByItem_column_ref(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedOrderByItem_column_ref(arg0, arg1)
}

func ResolvedOrderByItem_set_column_ref(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedOrderByItem_set_column_ref(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOrderByItem_set_column_ref(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedOrderByItem_set_column_ref(arg0, arg1)
}

func ResolvedOrderByItem_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedOrderByItem_collation_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOrderByItem_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedOrderByItem_collation_name(arg0, arg1)
}

func ResolvedOrderByItem_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedOrderByItem_set_collation_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOrderByItem_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedOrderByItem_set_collation_name(arg0, arg1)
}

func ResolvedOrderByItem_is_descending(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedOrderByItem_is_descending(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedOrderByItem_is_descending(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedOrderByItem_is_descending(arg0, arg1)
}

func ResolvedOrderByItem_set_is_descending(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedOrderByItem_set_is_descending(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedOrderByItem_set_is_descending(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedOrderByItem_set_is_descending(arg0, arg1)
}

func ResolvedOrderByItem_null_order(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedOrderByItem_null_order(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedOrderByItem_null_order(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedOrderByItem_null_order(arg0, arg1)
}

func ResolvedOrderByItem_set_null_order(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedOrderByItem_set_null_order(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedOrderByItem_set_null_order(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedOrderByItem_set_null_order(arg0, arg1)
}

func ResolvedOrderByItem_collation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedOrderByItem_collation(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOrderByItem_collation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedOrderByItem_collation(arg0, arg1)
}

func ResolvedOrderByItem_set_collation(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedOrderByItem_set_collation(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOrderByItem_set_collation(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedOrderByItem_set_collation(arg0, arg1)
}

func ResolvedColumnAnnotations_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumnAnnotations_collation_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnAnnotations_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnAnnotations_collation_name(arg0, arg1)
}

func ResolvedColumnAnnotations_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnAnnotations_set_collation_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnAnnotations_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnAnnotations_set_collation_name(arg0, arg1)
}

func ResolvedColumnAnnotations_not_null(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedColumnAnnotations_not_null(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedColumnAnnotations_not_null(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedColumnAnnotations_not_null(arg0, arg1)
}

func ResolvedColumnAnnotations_set_not_null(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedColumnAnnotations_set_not_null(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedColumnAnnotations_set_not_null(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedColumnAnnotations_set_not_null(arg0, arg1)
}

func ResolvedColumnAnnotations_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumnAnnotations_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnAnnotations_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnAnnotations_option_list(arg0, arg1)
}

func ResolvedColumnAnnotations_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnAnnotations_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnAnnotations_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnAnnotations_set_option_list(arg0, arg1)
}

func ResolvedColumnAnnotations_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnAnnotations_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnAnnotations_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnAnnotations_add_option_list(arg0, arg1)
}

func ResolvedColumnAnnotations_child_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumnAnnotations_child_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnAnnotations_child_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnAnnotations_child_list(arg0, arg1)
}

func ResolvedColumnAnnotations_set_child_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnAnnotations_set_child_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnAnnotations_set_child_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnAnnotations_set_child_list(arg0, arg1)
}

func ResolvedColumnAnnotations_add_child_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnAnnotations_add_child_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnAnnotations_add_child_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnAnnotations_add_child_list(arg0, arg1)
}

func ResolvedColumnAnnotations_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumnAnnotations_type_parameters(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnAnnotations_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnAnnotations_type_parameters(arg0, arg1)
}

func ResolvedColumnAnnotations_set_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnAnnotations_set_type_parameters(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnAnnotations_set_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnAnnotations_set_type_parameters(arg0, arg1)
}

func ResolvedGeneratedColumnInfo_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedGeneratedColumnInfo_expression(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGeneratedColumnInfo_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedGeneratedColumnInfo_expression(arg0, arg1)
}

func ResolvedGeneratedColumnInfo_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGeneratedColumnInfo_set_expression(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGeneratedColumnInfo_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGeneratedColumnInfo_set_expression(arg0, arg1)
}

func ResolvedGeneratedColumnInfo_stored_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedGeneratedColumnInfo_stored_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedGeneratedColumnInfo_stored_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedGeneratedColumnInfo_stored_mode(arg0, arg1)
}

func ResolvedGeneratedColumnInfo_set_stored_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedGeneratedColumnInfo_set_stored_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedGeneratedColumnInfo_set_stored_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedGeneratedColumnInfo_set_stored_mode(arg0, arg1)
}

func ResolvedColumnDefaultValue_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumnDefaultValue_expression(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefaultValue_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefaultValue_expression(arg0, arg1)
}

func ResolvedColumnDefaultValue_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnDefaultValue_set_expression(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefaultValue_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefaultValue_set_expression(arg0, arg1)
}

func ResolvedColumnDefaultValue_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumnDefaultValue_sql(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefaultValue_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefaultValue_sql(arg0, arg1)
}

func ResolvedColumnDefaultValue_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnDefaultValue_set_sql(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefaultValue_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefaultValue_set_sql(arg0, arg1)
}

func ResolvedColumnDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumnDefinition_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefinition_name(arg0, arg1)
}

func ResolvedColumnDefinition_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnDefinition_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefinition_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefinition_set_name(arg0, arg1)
}

func ResolvedColumnDefinition_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumnDefinition_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefinition_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefinition_type(arg0, arg1)
}

func ResolvedColumnDefinition_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnDefinition_set_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefinition_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefinition_set_type(arg0, arg1)
}

func ResolvedColumnDefinition_annotations(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumnDefinition_annotations(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefinition_annotations(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefinition_annotations(arg0, arg1)
}

func ResolvedColumnDefinition_set_annotations(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnDefinition_set_annotations(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefinition_set_annotations(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefinition_set_annotations(arg0, arg1)
}

func ResolvedColumnDefinition_is_hidden(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedColumnDefinition_is_hidden(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedColumnDefinition_is_hidden(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedColumnDefinition_is_hidden(arg0, arg1)
}

func ResolvedColumnDefinition_set_is_hidden(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedColumnDefinition_set_is_hidden(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedColumnDefinition_set_is_hidden(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedColumnDefinition_set_is_hidden(arg0, arg1)
}

func ResolvedColumnDefinition_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumnDefinition_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefinition_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefinition_column(arg0, arg1)
}

func ResolvedColumnDefinition_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnDefinition_set_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefinition_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefinition_set_column(arg0, arg1)
}

func ResolvedColumnDefinition_generated_column_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumnDefinition_generated_column_info(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefinition_generated_column_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefinition_generated_column_info(arg0, arg1)
}

func ResolvedColumnDefinition_set_generated_column_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnDefinition_set_generated_column_info(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefinition_set_generated_column_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefinition_set_generated_column_info(arg0, arg1)
}

func ResolvedColumnDefinition_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumnDefinition_default_value(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefinition_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefinition_default_value(arg0, arg1)
}

func ResolvedColumnDefinition_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedColumnDefinition_set_default_value(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumnDefinition_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumnDefinition_set_default_value(arg0, arg1)
}

func ResolvedPrimaryKey_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedPrimaryKey_column_offset_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPrimaryKey_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedPrimaryKey_column_offset_list(arg0, arg1)
}

func ResolvedPrimaryKey_set_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPrimaryKey_set_column_offset_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPrimaryKey_set_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPrimaryKey_set_column_offset_list(arg0, arg1)
}

func ResolvedPrimaryKey_add_column_offset_list(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedPrimaryKey_add_column_offset_list(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedPrimaryKey_add_column_offset_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedPrimaryKey_add_column_offset_list(arg0, arg1)
}

func ResolvedPrimaryKey_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedPrimaryKey_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPrimaryKey_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedPrimaryKey_option_list(arg0, arg1)
}

func ResolvedPrimaryKey_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPrimaryKey_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPrimaryKey_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPrimaryKey_set_option_list(arg0, arg1)
}

func ResolvedPrimaryKey_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPrimaryKey_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPrimaryKey_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPrimaryKey_add_option_list(arg0, arg1)
}

func ResolvedPrimaryKey_unenforced(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedPrimaryKey_unenforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedPrimaryKey_unenforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedPrimaryKey_unenforced(arg0, arg1)
}

func ResolvedPrimaryKey_set_unenforced(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedPrimaryKey_set_unenforced(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedPrimaryKey_set_unenforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedPrimaryKey_set_unenforced(arg0, arg1)
}

func ResolvedPrimaryKey_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedPrimaryKey_constraint_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPrimaryKey_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedPrimaryKey_constraint_name(arg0, arg1)
}

func ResolvedPrimaryKey_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPrimaryKey_set_constraint_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPrimaryKey_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPrimaryKey_set_constraint_name(arg0, arg1)
}

func ResolvedPrimaryKey_column_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedPrimaryKey_column_name_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPrimaryKey_column_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedPrimaryKey_column_name_list(arg0, arg1)
}

func ResolvedPrimaryKey_set_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPrimaryKey_set_column_name_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPrimaryKey_set_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPrimaryKey_set_column_name_list(arg0, arg1)
}

func ResolvedPrimaryKey_add_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPrimaryKey_add_column_name_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPrimaryKey_add_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPrimaryKey_add_column_name_list(arg0, arg1)
}

func ResolvedForeignKey_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedForeignKey_constraint_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedForeignKey_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedForeignKey_constraint_name(arg0, arg1)
}

func ResolvedForeignKey_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedForeignKey_set_constraint_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedForeignKey_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedForeignKey_set_constraint_name(arg0, arg1)
}

func ResolvedForeignKey_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedForeignKey_referencing_column_offset_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedForeignKey_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedForeignKey_referencing_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_set_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedForeignKey_set_referencing_column_offset_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedForeignKey_set_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedForeignKey_set_referencing_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_add_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedForeignKey_add_referencing_column_offset_list(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedForeignKey_add_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedForeignKey_add_referencing_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_referenced_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedForeignKey_referenced_table(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedForeignKey_referenced_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedForeignKey_referenced_table(arg0, arg1)
}

func ResolvedForeignKey_set_referenced_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedForeignKey_set_referenced_table(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedForeignKey_set_referenced_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedForeignKey_set_referenced_table(arg0, arg1)
}

func ResolvedForeignKey_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedForeignKey_referenced_column_offset_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedForeignKey_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedForeignKey_referenced_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_set_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedForeignKey_set_referenced_column_offset_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedForeignKey_set_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedForeignKey_set_referenced_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_add_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedForeignKey_add_referenced_column_offset_list(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedForeignKey_add_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedForeignKey_add_referenced_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_match_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedForeignKey_match_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedForeignKey_match_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedForeignKey_match_mode(arg0, arg1)
}

func ResolvedForeignKey_set_match_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedForeignKey_set_match_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedForeignKey_set_match_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedForeignKey_set_match_mode(arg0, arg1)
}

func ResolvedForeignKey_update_action(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedForeignKey_update_action(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedForeignKey_update_action(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedForeignKey_update_action(arg0, arg1)
}

func ResolvedForeignKey_set_update_action(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedForeignKey_set_update_action(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedForeignKey_set_update_action(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedForeignKey_set_update_action(arg0, arg1)
}

func ResolvedForeignKey_delete_action(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedForeignKey_delete_action(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedForeignKey_delete_action(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedForeignKey_delete_action(arg0, arg1)
}

func ResolvedForeignKey_set_delete_action(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedForeignKey_set_delete_action(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedForeignKey_set_delete_action(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedForeignKey_set_delete_action(arg0, arg1)
}

func ResolvedForeignKey_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedForeignKey_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedForeignKey_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedForeignKey_enforced(arg0, arg1)
}

func ResolvedForeignKey_set_enforced(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedForeignKey_set_enforced(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedForeignKey_set_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedForeignKey_set_enforced(arg0, arg1)
}

func ResolvedForeignKey_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedForeignKey_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedForeignKey_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedForeignKey_option_list(arg0, arg1)
}

func ResolvedForeignKey_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedForeignKey_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedForeignKey_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedForeignKey_set_option_list(arg0, arg1)
}

func ResolvedForeignKey_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedForeignKey_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedForeignKey_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedForeignKey_add_option_list(arg0, arg1)
}

func ResolvedForeignKey_referencing_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedForeignKey_referencing_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedForeignKey_referencing_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedForeignKey_referencing_column_list(arg0, arg1)
}

func ResolvedForeignKey_set_referencing_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedForeignKey_set_referencing_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedForeignKey_set_referencing_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedForeignKey_set_referencing_column_list(arg0, arg1)
}

func ResolvedForeignKey_add_referencing_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedForeignKey_add_referencing_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedForeignKey_add_referencing_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedForeignKey_add_referencing_column_list(arg0, arg1)
}

func ResolvedCheckConstraint_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCheckConstraint_constraint_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCheckConstraint_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCheckConstraint_constraint_name(arg0, arg1)
}

func ResolvedCheckConstraint_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCheckConstraint_set_constraint_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCheckConstraint_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCheckConstraint_set_constraint_name(arg0, arg1)
}

func ResolvedCheckConstraint_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCheckConstraint_expression(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCheckConstraint_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCheckConstraint_expression(arg0, arg1)
}

func ResolvedCheckConstraint_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCheckConstraint_set_expression(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCheckConstraint_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCheckConstraint_set_expression(arg0, arg1)
}

func ResolvedCheckConstraint_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCheckConstraint_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCheckConstraint_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCheckConstraint_enforced(arg0, arg1)
}

func ResolvedCheckConstraint_set_enforced(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCheckConstraint_set_enforced(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCheckConstraint_set_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCheckConstraint_set_enforced(arg0, arg1)
}

func ResolvedCheckConstraint_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCheckConstraint_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCheckConstraint_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCheckConstraint_option_list(arg0, arg1)
}

func ResolvedCheckConstraint_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCheckConstraint_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCheckConstraint_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCheckConstraint_set_option_list(arg0, arg1)
}

func ResolvedCheckConstraint_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCheckConstraint_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCheckConstraint_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCheckConstraint_add_option_list(arg0, arg1)
}

func ResolvedOutputColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedOutputColumn_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOutputColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedOutputColumn_name(arg0, arg1)
}

func ResolvedOutputColumn_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedOutputColumn_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOutputColumn_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedOutputColumn_set_name(arg0, arg1)
}

func ResolvedOutputColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedOutputColumn_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOutputColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedOutputColumn_column(arg0, arg1)
}

func ResolvedOutputColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedOutputColumn_set_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOutputColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedOutputColumn_set_column(arg0, arg1)
}

func ResolvedProjectScan_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedProjectScan_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedProjectScan_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedProjectScan_expr_list(arg0, arg1)
}

func ResolvedProjectScan_set_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedProjectScan_set_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedProjectScan_set_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedProjectScan_set_expr_list(arg0, arg1)
}

func ResolvedProjectScan_add_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedProjectScan_add_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedProjectScan_add_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedProjectScan_add_expr_list(arg0, arg1)
}

func ResolvedProjectScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedProjectScan_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedProjectScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedProjectScan_input_scan(arg0, arg1)
}

func ResolvedProjectScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedProjectScan_set_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedProjectScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedProjectScan_set_input_scan(arg0, arg1)
}

func ResolvedTVFScan_tvf(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedTVFScan_tvf(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTVFScan_tvf(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedTVFScan_tvf(arg0, arg1)
}

func ResolvedTVFScan_set_tvf(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedTVFScan_set_tvf(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTVFScan_set_tvf(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedTVFScan_set_tvf(arg0, arg1)
}

func ResolvedTVFScan_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedTVFScan_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTVFScan_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedTVFScan_signature(arg0, arg1)
}

func ResolvedTVFScan_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedTVFScan_set_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTVFScan_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedTVFScan_set_signature(arg0, arg1)
}

func ResolvedTVFScan_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedTVFScan_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTVFScan_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedTVFScan_argument_list(arg0, arg1)
}

func ResolvedTVFScan_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedTVFScan_set_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTVFScan_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedTVFScan_set_argument_list(arg0, arg1)
}

func ResolvedTVFScan_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedTVFScan_add_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTVFScan_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedTVFScan_add_argument_list(arg0, arg1)
}

func ResolvedTVFScan_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedTVFScan_column_index_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTVFScan_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedTVFScan_column_index_list(arg0, arg1)
}

func ResolvedTVFScan_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedTVFScan_set_column_index_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTVFScan_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedTVFScan_set_column_index_list(arg0, arg1)
}

func ResolvedTVFScan_add_column_index_list(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedTVFScan_add_column_index_list(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedTVFScan_add_column_index_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedTVFScan_add_column_index_list(arg0, arg1)
}

func ResolvedTVFScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedTVFScan_alias(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTVFScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedTVFScan_alias(arg0, arg1)
}

func ResolvedTVFScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedTVFScan_set_alias(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTVFScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedTVFScan_set_alias(arg0, arg1)
}

func ResolvedTVFScan_function_call_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedTVFScan_function_call_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTVFScan_function_call_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedTVFScan_function_call_signature(arg0, arg1)
}

func ResolvedTVFScan_set_function_call_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedTVFScan_set_function_call_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTVFScan_set_function_call_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedTVFScan_set_function_call_signature(arg0, arg1)
}

func ResolvedGroupRowsScan_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedGroupRowsScan_input_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGroupRowsScan_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedGroupRowsScan_input_column_list(arg0, arg1)
}

func ResolvedGroupRowsScan_set_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGroupRowsScan_set_input_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGroupRowsScan_set_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGroupRowsScan_set_input_column_list(arg0, arg1)
}

func ResolvedGroupRowsScan_add_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGroupRowsScan_add_input_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGroupRowsScan_add_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGroupRowsScan_add_input_column_list(arg0, arg1)
}

func ResolvedGroupRowsScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedGroupRowsScan_alias(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGroupRowsScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedGroupRowsScan_alias(arg0, arg1)
}

func ResolvedGroupRowsScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGroupRowsScan_set_alias(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGroupRowsScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGroupRowsScan_set_alias(arg0, arg1)
}

func ResolvedFunctionArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionArgument_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionArgument_expr(arg0, arg1)
}

func ResolvedFunctionArgument_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionArgument_set_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionArgument_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionArgument_set_expr(arg0, arg1)
}

func ResolvedFunctionArgument_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionArgument_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionArgument_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionArgument_scan(arg0, arg1)
}

func ResolvedFunctionArgument_set_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionArgument_set_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionArgument_set_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionArgument_set_scan(arg0, arg1)
}

func ResolvedFunctionArgument_model(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionArgument_model(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionArgument_model(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionArgument_model(arg0, arg1)
}

func ResolvedFunctionArgument_set_model(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionArgument_set_model(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionArgument_set_model(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionArgument_set_model(arg0, arg1)
}

func ResolvedFunctionArgument_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionArgument_connection(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionArgument_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionArgument_connection(arg0, arg1)
}

func ResolvedFunctionArgument_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionArgument_set_connection(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionArgument_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionArgument_set_connection(arg0, arg1)
}

func ResolvedFunctionArgument_descriptor_arg(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionArgument_descriptor_arg(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionArgument_descriptor_arg(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionArgument_descriptor_arg(arg0, arg1)
}

func ResolvedFunctionArgument_set_descriptor_arg(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionArgument_set_descriptor_arg(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionArgument_set_descriptor_arg(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionArgument_set_descriptor_arg(arg0, arg1)
}

func ResolvedFunctionArgument_argument_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionArgument_argument_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionArgument_argument_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionArgument_argument_column_list(arg0, arg1)
}

func ResolvedFunctionArgument_set_argument_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionArgument_set_argument_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionArgument_set_argument_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionArgument_set_argument_column_list(arg0, arg1)
}

func ResolvedFunctionArgument_add_argument_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionArgument_add_argument_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionArgument_add_argument_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionArgument_add_argument_column_list(arg0, arg1)
}

func ResolvedFunctionArgument_inline_lambda(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionArgument_inline_lambda(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionArgument_inline_lambda(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionArgument_inline_lambda(arg0, arg1)
}

func ResolvedFunctionArgument_set_inline_lambda(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionArgument_set_inline_lambda(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionArgument_set_inline_lambda(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionArgument_set_inline_lambda(arg0, arg1)
}

func ResolvedStatement_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedStatement_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedStatement_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedStatement_hint_list(arg0, arg1)
}

func ResolvedStatement_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedStatement_set_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedStatement_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedStatement_set_hint_list(arg0, arg1)
}

func ResolvedStatement_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedStatement_add_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedStatement_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedStatement_add_hint_list(arg0, arg1)
}

func ResolvedExplainStmt_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExplainStmt_statement(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExplainStmt_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExplainStmt_statement(arg0, arg1)
}

func ResolvedExplainStmt_set_statement(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExplainStmt_set_statement(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExplainStmt_set_statement(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExplainStmt_set_statement(arg0, arg1)
}

func ResolvedQueryStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedQueryStmt_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedQueryStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedQueryStmt_output_column_list(arg0, arg1)
}

func ResolvedQueryStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedQueryStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedQueryStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedQueryStmt_set_output_column_list(arg0, arg1)
}

func ResolvedQueryStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedQueryStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedQueryStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedQueryStmt_add_output_column_list(arg0, arg1)
}

func ResolvedQueryStmt_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedQueryStmt_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedQueryStmt_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedQueryStmt_is_value_table(arg0, arg1)
}

func ResolvedQueryStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedQueryStmt_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedQueryStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedQueryStmt_set_is_value_table(arg0, arg1)
}

func ResolvedQueryStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedQueryStmt_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedQueryStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedQueryStmt_query(arg0, arg1)
}

func ResolvedQueryStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedQueryStmt_set_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedQueryStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedQueryStmt_set_query(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateDatabaseStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateDatabaseStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateDatabaseStmt_name_path(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateDatabaseStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateDatabaseStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateDatabaseStmt_set_name_path(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateDatabaseStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateDatabaseStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateDatabaseStmt_add_name_path(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateDatabaseStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateDatabaseStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateDatabaseStmt_option_list(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateDatabaseStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateDatabaseStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateDatabaseStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateDatabaseStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateDatabaseStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateDatabaseStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateStatement_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateStatement_name_path(arg0, arg1)
}

func ResolvedCreateStatement_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateStatement_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateStatement_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateStatement_set_name_path(arg0, arg1)
}

func ResolvedCreateStatement_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateStatement_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateStatement_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateStatement_add_name_path(arg0, arg1)
}

func ResolvedCreateStatement_create_scope(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedCreateStatement_create_scope(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateStatement_create_scope(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedCreateStatement_create_scope(arg0, arg1)
}

func ResolvedCreateStatement_set_create_scope(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateStatement_set_create_scope(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateStatement_set_create_scope(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateStatement_set_create_scope(arg0, arg1)
}

func ResolvedCreateStatement_create_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedCreateStatement_create_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateStatement_create_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedCreateStatement_create_mode(arg0, arg1)
}

func ResolvedCreateStatement_set_create_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateStatement_set_create_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateStatement_set_create_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateStatement_set_create_mode(arg0, arg1)
}

func ResolvedIndexItem_column_ref(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedIndexItem_column_ref(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedIndexItem_column_ref(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedIndexItem_column_ref(arg0, arg1)
}

func ResolvedIndexItem_set_column_ref(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedIndexItem_set_column_ref(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedIndexItem_set_column_ref(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedIndexItem_set_column_ref(arg0, arg1)
}

func ResolvedIndexItem_descending(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedIndexItem_descending(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedIndexItem_descending(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedIndexItem_descending(arg0, arg1)
}

func ResolvedIndexItem_set_descending(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedIndexItem_set_descending(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedIndexItem_set_descending(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedIndexItem_set_descending(arg0, arg1)
}

func ResolvedUnnestItem_array_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUnnestItem_array_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnnestItem_array_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUnnestItem_array_expr(arg0, arg1)
}

func ResolvedUnnestItem_set_array_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUnnestItem_set_array_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnnestItem_set_array_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUnnestItem_set_array_expr(arg0, arg1)
}

func ResolvedUnnestItem_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUnnestItem_element_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnnestItem_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUnnestItem_element_column(arg0, arg1)
}

func ResolvedUnnestItem_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUnnestItem_set_element_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnnestItem_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUnnestItem_set_element_column(arg0, arg1)
}

func ResolvedUnnestItem_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUnnestItem_array_offset_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnnestItem_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUnnestItem_array_offset_column(arg0, arg1)
}

func ResolvedUnnestItem_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUnnestItem_set_array_offset_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnnestItem_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUnnestItem_set_array_offset_column(arg0, arg1)
}

func ResolvedCreateIndexStmt_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_table_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_table_name_path(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_set_table_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_set_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_set_table_name_path(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_add_table_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_add_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_add_table_name_path(arg0, arg1)
}

func ResolvedCreateIndexStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_table_scan(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_set_table_scan(arg0, arg1)
}

func ResolvedCreateIndexStmt_is_unique(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCreateIndexStmt_is_unique(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateIndexStmt_is_unique(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCreateIndexStmt_is_unique(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_is_unique(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateIndexStmt_set_is_unique(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateIndexStmt_set_is_unique(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateIndexStmt_set_is_unique(arg0, arg1)
}

func ResolvedCreateIndexStmt_is_search(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCreateIndexStmt_is_search(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateIndexStmt_is_search(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCreateIndexStmt_is_search(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_is_search(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateIndexStmt_set_is_search(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateIndexStmt_set_is_search(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateIndexStmt_set_is_search(arg0, arg1)
}

func ResolvedCreateIndexStmt_index_all_columns(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCreateIndexStmt_index_all_columns(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateIndexStmt_index_all_columns(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCreateIndexStmt_index_all_columns(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_index_all_columns(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateIndexStmt_set_index_all_columns(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateIndexStmt_set_index_all_columns(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateIndexStmt_set_index_all_columns(arg0, arg1)
}

func ResolvedCreateIndexStmt_index_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_index_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_index_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_index_item_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_index_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_set_index_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_set_index_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_set_index_item_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_index_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_add_index_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_add_index_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_add_index_item_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_storing_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_storing_expression_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_storing_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_storing_expression_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_storing_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_set_storing_expression_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_set_storing_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_set_storing_expression_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_storing_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_add_storing_expression_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_add_storing_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_add_storing_expression_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_option_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_computed_columns_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_computed_columns_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_computed_columns_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_computed_columns_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_computed_columns_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_set_computed_columns_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_set_computed_columns_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_set_computed_columns_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_computed_columns_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_add_computed_columns_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_add_computed_columns_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_add_computed_columns_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_unnest_expressions_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_unnest_expressions_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_unnest_expressions_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_unnest_expressions_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_unnest_expressions_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_set_unnest_expressions_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_set_unnest_expressions_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_set_unnest_expressions_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_unnest_expressions_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateIndexStmt_add_unnest_expressions_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateIndexStmt_add_unnest_expressions_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateIndexStmt_add_unnest_expressions_list(arg0, arg1)
}

func ResolvedCreateSchemaStmt_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateSchemaStmt_collation_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateSchemaStmt_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateSchemaStmt_collation_name(arg0, arg1)
}

func ResolvedCreateSchemaStmt_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateSchemaStmt_set_collation_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateSchemaStmt_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateSchemaStmt_set_collation_name(arg0, arg1)
}

func ResolvedCreateSchemaStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateSchemaStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateSchemaStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateSchemaStmt_option_list(arg0, arg1)
}

func ResolvedCreateSchemaStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateSchemaStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateSchemaStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateSchemaStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateSchemaStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateSchemaStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateSchemaStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateSchemaStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_option_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_set_option_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_add_option_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_column_definition_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_column_definition_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_set_column_definition_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_set_column_definition_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_add_column_definition_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_add_column_definition_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_pseudo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_pseudo_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_pseudo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_pseudo_column_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_set_pseudo_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_set_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_set_pseudo_column_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_add_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_add_pseudo_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_add_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_add_pseudo_column_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_primary_key(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_primary_key(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_primary_key(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_primary_key(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_primary_key(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_set_primary_key(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_set_primary_key(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_set_primary_key(arg0, arg1)
}

func ResolvedCreateTableStmtBase_foreign_key_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_foreign_key_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_foreign_key_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_foreign_key_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_set_foreign_key_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_set_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_set_foreign_key_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_add_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_add_foreign_key_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_add_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_add_foreign_key_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_check_constraint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_check_constraint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_check_constraint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_check_constraint_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_set_check_constraint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_set_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_set_check_constraint_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_add_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_add_check_constraint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_add_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_add_check_constraint_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCreateTableStmtBase_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateTableStmtBase_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCreateTableStmtBase_is_value_table(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateTableStmtBase_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateTableStmtBase_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateTableStmtBase_set_is_value_table(arg0, arg1)
}

func ResolvedCreateTableStmtBase_like_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_like_table(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_like_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_like_table(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_like_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_set_like_table(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_set_like_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_set_like_table(arg0, arg1)
}

func ResolvedCreateTableStmtBase_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_collation_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_collation_name(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmtBase_set_collation_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmtBase_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmtBase_set_collation_name(arg0, arg1)
}

func ResolvedCreateTableStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmt_clone_from(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmt_clone_from(arg0, arg1)
}

func ResolvedCreateTableStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmt_set_clone_from(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmt_set_clone_from(arg0, arg1)
}

func ResolvedCreateTableStmt_copy_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmt_copy_from(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmt_copy_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmt_copy_from(arg0, arg1)
}

func ResolvedCreateTableStmt_set_copy_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmt_set_copy_from(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmt_set_copy_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmt_set_copy_from(arg0, arg1)
}

func ResolvedCreateTableStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmt_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmt_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmt_set_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmt_set_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmt_add_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmt_add_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmt_cluster_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmt_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmt_set_cluster_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmt_set_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableStmt_add_cluster_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableStmt_add_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableAsSelectStmt_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableAsSelectStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableAsSelectStmt_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableAsSelectStmt_set_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableAsSelectStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableAsSelectStmt_set_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableAsSelectStmt_add_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableAsSelectStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableAsSelectStmt_add_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableAsSelectStmt_cluster_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableAsSelectStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableAsSelectStmt_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableAsSelectStmt_set_cluster_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableAsSelectStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableAsSelectStmt_set_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableAsSelectStmt_add_cluster_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableAsSelectStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableAsSelectStmt_add_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableAsSelectStmt_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableAsSelectStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableAsSelectStmt_output_column_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableAsSelectStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableAsSelectStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableAsSelectStmt_set_output_column_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableAsSelectStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableAsSelectStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableAsSelectStmt_add_output_column_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableAsSelectStmt_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableAsSelectStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableAsSelectStmt_query(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableAsSelectStmt_set_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableAsSelectStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableAsSelectStmt_set_query(arg0, arg1)
}

func ResolvedCreateModelStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_option_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateModelStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_set_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_add_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_query(arg0, arg1)
}

func ResolvedCreateModelStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_set_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_set_query(arg0, arg1)
}

func ResolvedCreateModelStmt_transform_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_transform_input_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_transform_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_transform_input_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_transform_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_set_transform_input_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_set_transform_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_set_transform_input_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_transform_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_add_transform_input_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_add_transform_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_add_transform_input_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_transform_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_transform_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_transform_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_transform_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_transform_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_set_transform_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_set_transform_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_set_transform_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_transform_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_add_transform_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_add_transform_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_add_transform_list(arg0, arg1)
}

func ResolvedCreateModelStmt_transform_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_transform_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_transform_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_transform_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_transform_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_set_transform_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_set_transform_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_set_transform_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_transform_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_add_transform_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_add_transform_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_add_transform_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_transform_analytic_function_group_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_transform_analytic_function_group_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_set_transform_analytic_function_group_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_set_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_set_transform_analytic_function_group_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateModelStmt_add_transform_analytic_function_group_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateModelStmt_add_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateModelStmt_add_transform_analytic_function_group_list(arg0, arg1)
}

func ResolvedCreateViewBase_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateViewBase_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateViewBase_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateViewBase_option_list(arg0, arg1)
}

func ResolvedCreateViewBase_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateViewBase_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateViewBase_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateViewBase_set_option_list(arg0, arg1)
}

func ResolvedCreateViewBase_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateViewBase_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateViewBase_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateViewBase_add_option_list(arg0, arg1)
}

func ResolvedCreateViewBase_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateViewBase_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateViewBase_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateViewBase_output_column_list(arg0, arg1)
}

func ResolvedCreateViewBase_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateViewBase_set_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateViewBase_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateViewBase_set_output_column_list(arg0, arg1)
}

func ResolvedCreateViewBase_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateViewBase_add_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateViewBase_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateViewBase_add_output_column_list(arg0, arg1)
}

func ResolvedCreateViewBase_has_explicit_columns(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCreateViewBase_has_explicit_columns(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateViewBase_has_explicit_columns(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCreateViewBase_has_explicit_columns(arg0, arg1)
}

func ResolvedCreateViewBase_set_has_explicit_columns(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateViewBase_set_has_explicit_columns(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateViewBase_set_has_explicit_columns(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateViewBase_set_has_explicit_columns(arg0, arg1)
}

func ResolvedCreateViewBase_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateViewBase_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateViewBase_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateViewBase_query(arg0, arg1)
}

func ResolvedCreateViewBase_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateViewBase_set_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateViewBase_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateViewBase_set_query(arg0, arg1)
}

func ResolvedCreateViewBase_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateViewBase_sql(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateViewBase_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateViewBase_sql(arg0, arg1)
}

func ResolvedCreateViewBase_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateViewBase_set_sql(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateViewBase_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateViewBase_set_sql(arg0, arg1)
}

func ResolvedCreateViewBase_sql_security(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedCreateViewBase_sql_security(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateViewBase_sql_security(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedCreateViewBase_sql_security(arg0, arg1)
}

func ResolvedCreateViewBase_set_sql_security(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateViewBase_set_sql_security(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateViewBase_set_sql_security(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateViewBase_set_sql_security(arg0, arg1)
}

func ResolvedCreateViewBase_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCreateViewBase_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateViewBase_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCreateViewBase_is_value_table(arg0, arg1)
}

func ResolvedCreateViewBase_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateViewBase_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateViewBase_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateViewBase_set_is_value_table(arg0, arg1)
}

func ResolvedCreateViewBase_recursive(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCreateViewBase_recursive(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateViewBase_recursive(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCreateViewBase_recursive(arg0, arg1)
}

func ResolvedCreateViewBase_set_recursive(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateViewBase_set_recursive(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateViewBase_set_recursive(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateViewBase_set_recursive(arg0, arg1)
}

func ResolvedWithPartitionColumns_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedWithPartitionColumns_column_definition_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWithPartitionColumns_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedWithPartitionColumns_column_definition_list(arg0, arg1)
}

func ResolvedWithPartitionColumns_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWithPartitionColumns_set_column_definition_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWithPartitionColumns_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWithPartitionColumns_set_column_definition_list(arg0, arg1)
}

func ResolvedWithPartitionColumns_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWithPartitionColumns_add_column_definition_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWithPartitionColumns_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWithPartitionColumns_add_column_definition_list(arg0, arg1)
}

func ResolvedCreateSnapshotTableStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateSnapshotTableStmt_clone_from(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateSnapshotTableStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateSnapshotTableStmt_clone_from(arg0, arg1)
}

func ResolvedCreateSnapshotTableStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateSnapshotTableStmt_set_clone_from(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateSnapshotTableStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateSnapshotTableStmt_set_clone_from(arg0, arg1)
}

func ResolvedCreateSnapshotTableStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateSnapshotTableStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateSnapshotTableStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateSnapshotTableStmt_option_list(arg0, arg1)
}

func ResolvedCreateSnapshotTableStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateSnapshotTableStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateSnapshotTableStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateSnapshotTableStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateSnapshotTableStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateSnapshotTableStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateSnapshotTableStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateSnapshotTableStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateExternalTableStmt_with_partition_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateExternalTableStmt_with_partition_columns(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateExternalTableStmt_with_partition_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateExternalTableStmt_with_partition_columns(arg0, arg1)
}

func ResolvedCreateExternalTableStmt_set_with_partition_columns(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateExternalTableStmt_set_with_partition_columns(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateExternalTableStmt_set_with_partition_columns(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateExternalTableStmt_set_with_partition_columns(arg0, arg1)
}

func ResolvedCreateExternalTableStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateExternalTableStmt_connection(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateExternalTableStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateExternalTableStmt_connection(arg0, arg1)
}

func ResolvedCreateExternalTableStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateExternalTableStmt_set_connection(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateExternalTableStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateExternalTableStmt_set_connection(arg0, arg1)
}

func ResolvedExportModelStmt_model_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExportModelStmt_model_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportModelStmt_model_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExportModelStmt_model_name_path(arg0, arg1)
}

func ResolvedExportModelStmt_set_model_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExportModelStmt_set_model_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportModelStmt_set_model_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExportModelStmt_set_model_name_path(arg0, arg1)
}

func ResolvedExportModelStmt_add_model_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExportModelStmt_add_model_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportModelStmt_add_model_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExportModelStmt_add_model_name_path(arg0, arg1)
}

func ResolvedExportModelStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExportModelStmt_connection(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportModelStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExportModelStmt_connection(arg0, arg1)
}

func ResolvedExportModelStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExportModelStmt_set_connection(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportModelStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExportModelStmt_set_connection(arg0, arg1)
}

func ResolvedExportModelStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExportModelStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportModelStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExportModelStmt_option_list(arg0, arg1)
}

func ResolvedExportModelStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExportModelStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportModelStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExportModelStmt_set_option_list(arg0, arg1)
}

func ResolvedExportModelStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExportModelStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportModelStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExportModelStmt_add_option_list(arg0, arg1)
}

func ResolvedExportDataStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExportDataStmt_connection(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportDataStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExportDataStmt_connection(arg0, arg1)
}

func ResolvedExportDataStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExportDataStmt_set_connection(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportDataStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExportDataStmt_set_connection(arg0, arg1)
}

func ResolvedExportDataStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExportDataStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportDataStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExportDataStmt_option_list(arg0, arg1)
}

func ResolvedExportDataStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExportDataStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportDataStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExportDataStmt_set_option_list(arg0, arg1)
}

func ResolvedExportDataStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExportDataStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportDataStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExportDataStmt_add_option_list(arg0, arg1)
}

func ResolvedExportDataStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExportDataStmt_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportDataStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExportDataStmt_output_column_list(arg0, arg1)
}

func ResolvedExportDataStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExportDataStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportDataStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExportDataStmt_set_output_column_list(arg0, arg1)
}

func ResolvedExportDataStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExportDataStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportDataStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExportDataStmt_add_output_column_list(arg0, arg1)
}

func ResolvedExportDataStmt_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedExportDataStmt_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedExportDataStmt_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedExportDataStmt_is_value_table(arg0, arg1)
}

func ResolvedExportDataStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedExportDataStmt_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedExportDataStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedExportDataStmt_set_is_value_table(arg0, arg1)
}

func ResolvedExportDataStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExportDataStmt_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportDataStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExportDataStmt_query(arg0, arg1)
}

func ResolvedExportDataStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExportDataStmt_set_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExportDataStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExportDataStmt_set_query(arg0, arg1)
}

func ResolvedDefineTableStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDefineTableStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDefineTableStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDefineTableStmt_name_path(arg0, arg1)
}

func ResolvedDefineTableStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDefineTableStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDefineTableStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDefineTableStmt_set_name_path(arg0, arg1)
}

func ResolvedDefineTableStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDefineTableStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDefineTableStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDefineTableStmt_add_name_path(arg0, arg1)
}

func ResolvedDefineTableStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDefineTableStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDefineTableStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDefineTableStmt_option_list(arg0, arg1)
}

func ResolvedDefineTableStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDefineTableStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDefineTableStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDefineTableStmt_set_option_list(arg0, arg1)
}

func ResolvedDefineTableStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDefineTableStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDefineTableStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDefineTableStmt_add_option_list(arg0, arg1)
}

func ResolvedDescribeStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDescribeStmt_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDescribeStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDescribeStmt_object_type(arg0, arg1)
}

func ResolvedDescribeStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDescribeStmt_set_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDescribeStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDescribeStmt_set_object_type(arg0, arg1)
}

func ResolvedDescribeStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDescribeStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDescribeStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDescribeStmt_name_path(arg0, arg1)
}

func ResolvedDescribeStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDescribeStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDescribeStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDescribeStmt_set_name_path(arg0, arg1)
}

func ResolvedDescribeStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDescribeStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDescribeStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDescribeStmt_add_name_path(arg0, arg1)
}

func ResolvedDescribeStmt_from_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDescribeStmt_from_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDescribeStmt_from_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDescribeStmt_from_name_path(arg0, arg1)
}

func ResolvedDescribeStmt_set_from_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDescribeStmt_set_from_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDescribeStmt_set_from_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDescribeStmt_set_from_name_path(arg0, arg1)
}

func ResolvedDescribeStmt_add_from_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDescribeStmt_add_from_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDescribeStmt_add_from_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDescribeStmt_add_from_name_path(arg0, arg1)
}

func ResolvedShowStmt_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedShowStmt_identifier(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedShowStmt_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedShowStmt_identifier(arg0, arg1)
}

func ResolvedShowStmt_set_identifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedShowStmt_set_identifier(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedShowStmt_set_identifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedShowStmt_set_identifier(arg0, arg1)
}

func ResolvedShowStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedShowStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedShowStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedShowStmt_name_path(arg0, arg1)
}

func ResolvedShowStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedShowStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedShowStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedShowStmt_set_name_path(arg0, arg1)
}

func ResolvedShowStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedShowStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedShowStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedShowStmt_add_name_path(arg0, arg1)
}

func ResolvedShowStmt_like_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedShowStmt_like_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedShowStmt_like_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedShowStmt_like_expr(arg0, arg1)
}

func ResolvedShowStmt_set_like_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedShowStmt_set_like_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedShowStmt_set_like_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedShowStmt_set_like_expr(arg0, arg1)
}

func ResolvedBeginStmt_read_write_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedBeginStmt_read_write_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedBeginStmt_read_write_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedBeginStmt_read_write_mode(arg0, arg1)
}

func ResolvedBeginStmt_set_read_write_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedBeginStmt_set_read_write_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedBeginStmt_set_read_write_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedBeginStmt_set_read_write_mode(arg0, arg1)
}

func ResolvedBeginStmt_isolation_level_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedBeginStmt_isolation_level_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedBeginStmt_isolation_level_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedBeginStmt_isolation_level_list(arg0, arg1)
}

func ResolvedBeginStmt_set_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedBeginStmt_set_isolation_level_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedBeginStmt_set_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedBeginStmt_set_isolation_level_list(arg0, arg1)
}

func ResolvedBeginStmt_add_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedBeginStmt_add_isolation_level_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedBeginStmt_add_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedBeginStmt_add_isolation_level_list(arg0, arg1)
}

func ResolvedSetTransactionStmt_read_write_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedSetTransactionStmt_read_write_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedSetTransactionStmt_read_write_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedSetTransactionStmt_read_write_mode(arg0, arg1)
}

func ResolvedSetTransactionStmt_set_read_write_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedSetTransactionStmt_set_read_write_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedSetTransactionStmt_set_read_write_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedSetTransactionStmt_set_read_write_mode(arg0, arg1)
}

func ResolvedSetTransactionStmt_isolation_level_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSetTransactionStmt_isolation_level_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetTransactionStmt_isolation_level_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSetTransactionStmt_isolation_level_list(arg0, arg1)
}

func ResolvedSetTransactionStmt_set_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSetTransactionStmt_set_isolation_level_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetTransactionStmt_set_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSetTransactionStmt_set_isolation_level_list(arg0, arg1)
}

func ResolvedSetTransactionStmt_add_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSetTransactionStmt_add_isolation_level_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetTransactionStmt_add_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSetTransactionStmt_add_isolation_level_list(arg0, arg1)
}

func ResolvedStartBatchStmt_batch_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedStartBatchStmt_batch_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedStartBatchStmt_batch_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedStartBatchStmt_batch_type(arg0, arg1)
}

func ResolvedStartBatchStmt_set_batch_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedStartBatchStmt_set_batch_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedStartBatchStmt_set_batch_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedStartBatchStmt_set_batch_type(arg0, arg1)
}

func ResolvedDropStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropStmt_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropStmt_object_type(arg0, arg1)
}

func ResolvedDropStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropStmt_set_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropStmt_set_object_type(arg0, arg1)
}

func ResolvedDropStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedDropStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedDropStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedDropStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedDropStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedDropStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedDropStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropStmt_name_path(arg0, arg1)
}

func ResolvedDropStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropStmt_set_name_path(arg0, arg1)
}

func ResolvedDropStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropStmt_add_name_path(arg0, arg1)
}

func ResolvedDropStmt_drop_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedDropStmt_drop_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedDropStmt_drop_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedDropStmt_drop_mode(arg0, arg1)
}

func ResolvedDropStmt_set_drop_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedDropStmt_set_drop_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedDropStmt_set_drop_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedDropStmt_set_drop_mode(arg0, arg1)
}

func ResolvedDropMaterializedViewStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedDropMaterializedViewStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedDropMaterializedViewStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedDropMaterializedViewStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropMaterializedViewStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedDropMaterializedViewStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedDropMaterializedViewStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedDropMaterializedViewStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropMaterializedViewStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropMaterializedViewStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropMaterializedViewStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropMaterializedViewStmt_name_path(arg0, arg1)
}

func ResolvedDropMaterializedViewStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropMaterializedViewStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropMaterializedViewStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropMaterializedViewStmt_set_name_path(arg0, arg1)
}

func ResolvedDropMaterializedViewStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropMaterializedViewStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropMaterializedViewStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropMaterializedViewStmt_add_name_path(arg0, arg1)
}

func ResolvedDropSnapshotTableStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedDropSnapshotTableStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedDropSnapshotTableStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedDropSnapshotTableStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropSnapshotTableStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedDropSnapshotTableStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedDropSnapshotTableStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedDropSnapshotTableStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropSnapshotTableStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropSnapshotTableStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropSnapshotTableStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropSnapshotTableStmt_name_path(arg0, arg1)
}

func ResolvedDropSnapshotTableStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropSnapshotTableStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropSnapshotTableStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropSnapshotTableStmt_set_name_path(arg0, arg1)
}

func ResolvedDropSnapshotTableStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropSnapshotTableStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropSnapshotTableStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropSnapshotTableStmt_add_name_path(arg0, arg1)
}

func ResolvedRecursiveScan_op_type(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedRecursiveScan_op_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedRecursiveScan_op_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedRecursiveScan_op_type(arg0, arg1)
}

func ResolvedRecursiveScan_set_op_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedRecursiveScan_set_op_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedRecursiveScan_set_op_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedRecursiveScan_set_op_type(arg0, arg1)
}

func ResolvedRecursiveScan_non_recursive_term(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedRecursiveScan_non_recursive_term(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRecursiveScan_non_recursive_term(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedRecursiveScan_non_recursive_term(arg0, arg1)
}

func ResolvedRecursiveScan_set_non_recursive_term(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRecursiveScan_set_non_recursive_term(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRecursiveScan_set_non_recursive_term(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRecursiveScan_set_non_recursive_term(arg0, arg1)
}

func ResolvedRecursiveScan_recursive_term(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedRecursiveScan_recursive_term(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRecursiveScan_recursive_term(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedRecursiveScan_recursive_term(arg0, arg1)
}

func ResolvedRecursiveScan_set_recursive_term(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRecursiveScan_set_recursive_term(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRecursiveScan_set_recursive_term(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRecursiveScan_set_recursive_term(arg0, arg1)
}

func ResolvedWithScan_with_entry_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedWithScan_with_entry_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWithScan_with_entry_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedWithScan_with_entry_list(arg0, arg1)
}

func ResolvedWithScan_set_with_entry_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWithScan_set_with_entry_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWithScan_set_with_entry_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWithScan_set_with_entry_list(arg0, arg1)
}

func ResolvedWithScan_add_with_entry_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWithScan_add_with_entry_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWithScan_add_with_entry_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWithScan_add_with_entry_list(arg0, arg1)
}

func ResolvedWithScan_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedWithScan_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWithScan_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedWithScan_query(arg0, arg1)
}

func ResolvedWithScan_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWithScan_set_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWithScan_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWithScan_set_query(arg0, arg1)
}

func ResolvedWithScan_recursive(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedWithScan_recursive(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedWithScan_recursive(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedWithScan_recursive(arg0, arg1)
}

func ResolvedWithScan_set_recursive(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedWithScan_set_recursive(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedWithScan_set_recursive(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedWithScan_set_recursive(arg0, arg1)
}

func ResolvedWithEntry_with_query_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedWithEntry_with_query_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWithEntry_with_query_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedWithEntry_with_query_name(arg0, arg1)
}

func ResolvedWithEntry_set_with_query_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWithEntry_set_with_query_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWithEntry_set_with_query_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWithEntry_set_with_query_name(arg0, arg1)
}

func ResolvedWithEntry_with_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedWithEntry_with_subquery(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWithEntry_with_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedWithEntry_with_subquery(arg0, arg1)
}

func ResolvedWithEntry_set_with_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWithEntry_set_with_subquery(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWithEntry_set_with_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWithEntry_set_with_subquery(arg0, arg1)
}

func ResolvedOption_qualifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedOption_qualifier(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOption_qualifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedOption_qualifier(arg0, arg1)
}

func ResolvedOption_set_qualifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedOption_set_qualifier(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOption_set_qualifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedOption_set_qualifier(arg0, arg1)
}

func ResolvedOption_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedOption_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOption_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedOption_name(arg0, arg1)
}

func ResolvedOption_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedOption_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOption_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedOption_set_name(arg0, arg1)
}

func ResolvedOption_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedOption_value(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOption_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedOption_value(arg0, arg1)
}

func ResolvedOption_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedOption_set_value(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedOption_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedOption_set_value(arg0, arg1)
}

func ResolvedWindowPartitioning_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedWindowPartitioning_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowPartitioning_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowPartitioning_partition_by_list(arg0, arg1)
}

func ResolvedWindowPartitioning_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWindowPartitioning_set_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowPartitioning_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowPartitioning_set_partition_by_list(arg0, arg1)
}

func ResolvedWindowPartitioning_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWindowPartitioning_add_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowPartitioning_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowPartitioning_add_partition_by_list(arg0, arg1)
}

func ResolvedWindowPartitioning_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedWindowPartitioning_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowPartitioning_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowPartitioning_hint_list(arg0, arg1)
}

func ResolvedWindowPartitioning_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWindowPartitioning_set_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowPartitioning_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowPartitioning_set_hint_list(arg0, arg1)
}

func ResolvedWindowPartitioning_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWindowPartitioning_add_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowPartitioning_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowPartitioning_add_hint_list(arg0, arg1)
}

func ResolvedWindowOrdering_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedWindowOrdering_order_by_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowOrdering_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowOrdering_order_by_item_list(arg0, arg1)
}

func ResolvedWindowOrdering_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWindowOrdering_set_order_by_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowOrdering_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowOrdering_set_order_by_item_list(arg0, arg1)
}

func ResolvedWindowOrdering_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWindowOrdering_add_order_by_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowOrdering_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowOrdering_add_order_by_item_list(arg0, arg1)
}

func ResolvedWindowOrdering_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedWindowOrdering_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowOrdering_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowOrdering_hint_list(arg0, arg1)
}

func ResolvedWindowOrdering_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWindowOrdering_set_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowOrdering_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowOrdering_set_hint_list(arg0, arg1)
}

func ResolvedWindowOrdering_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWindowOrdering_add_hint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowOrdering_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowOrdering_add_hint_list(arg0, arg1)
}

func ResolvedWindowFrame_frame_unit(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedWindowFrame_frame_unit(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedWindowFrame_frame_unit(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedWindowFrame_frame_unit(arg0, arg1)
}

func ResolvedWindowFrame_set_frame_unit(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedWindowFrame_set_frame_unit(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedWindowFrame_set_frame_unit(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedWindowFrame_set_frame_unit(arg0, arg1)
}

func ResolvedWindowFrame_start_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedWindowFrame_start_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowFrame_start_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowFrame_start_expr(arg0, arg1)
}

func ResolvedWindowFrame_set_start_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWindowFrame_set_start_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowFrame_set_start_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowFrame_set_start_expr(arg0, arg1)
}

func ResolvedWindowFrame_end_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedWindowFrame_end_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowFrame_end_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowFrame_end_expr(arg0, arg1)
}

func ResolvedWindowFrame_set_end_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWindowFrame_set_end_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowFrame_set_end_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowFrame_set_end_expr(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAnalyticFunctionGroup_partition_by(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyticFunctionGroup_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyticFunctionGroup_partition_by(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_set_partition_by(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAnalyticFunctionGroup_set_partition_by(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyticFunctionGroup_set_partition_by(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyticFunctionGroup_set_partition_by(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAnalyticFunctionGroup_order_by(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyticFunctionGroup_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyticFunctionGroup_order_by(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_set_order_by(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAnalyticFunctionGroup_set_order_by(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyticFunctionGroup_set_order_by(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyticFunctionGroup_set_order_by(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_analytic_function_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAnalyticFunctionGroup_analytic_function_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyticFunctionGroup_analytic_function_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyticFunctionGroup_analytic_function_list(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_set_analytic_function_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAnalyticFunctionGroup_set_analytic_function_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyticFunctionGroup_set_analytic_function_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyticFunctionGroup_set_analytic_function_list(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_add_analytic_function_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAnalyticFunctionGroup_add_analytic_function_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyticFunctionGroup_add_analytic_function_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyticFunctionGroup_add_analytic_function_list(arg0, arg1)
}

func ResolvedWindowFrameExpr_boundary_type(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedWindowFrameExpr_boundary_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedWindowFrameExpr_boundary_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedWindowFrameExpr_boundary_type(arg0, arg1)
}

func ResolvedWindowFrameExpr_set_boundary_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedWindowFrameExpr_set_boundary_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedWindowFrameExpr_set_boundary_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedWindowFrameExpr_set_boundary_type(arg0, arg1)
}

func ResolvedWindowFrameExpr_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedWindowFrameExpr_expression(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowFrameExpr_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowFrameExpr_expression(arg0, arg1)
}

func ResolvedWindowFrameExpr_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedWindowFrameExpr_set_expression(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedWindowFrameExpr_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedWindowFrameExpr_set_expression(arg0, arg1)
}

func ResolvedDMLValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDMLValue_value(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDMLValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDMLValue_value(arg0, arg1)
}

func ResolvedDMLValue_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDMLValue_set_value(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDMLValue_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDMLValue_set_value(arg0, arg1)
}

func ResolvedAssertStmt_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAssertStmt_expression(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAssertStmt_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAssertStmt_expression(arg0, arg1)
}

func ResolvedAssertStmt_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAssertStmt_set_expression(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAssertStmt_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAssertStmt_set_expression(arg0, arg1)
}

func ResolvedAssertStmt_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAssertStmt_description(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAssertStmt_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAssertStmt_description(arg0, arg1)
}

func ResolvedAssertStmt_set_description(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAssertStmt_set_description(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAssertStmt_set_description(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAssertStmt_set_description(arg0, arg1)
}

func ResolvedAssertRowsModified_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAssertRowsModified_rows(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAssertRowsModified_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAssertRowsModified_rows(arg0, arg1)
}

func ResolvedAssertRowsModified_set_rows(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAssertRowsModified_set_rows(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAssertRowsModified_set_rows(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAssertRowsModified_set_rows(arg0, arg1)
}

func ResolvedInsertRow_value_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedInsertRow_value_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertRow_value_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertRow_value_list(arg0, arg1)
}

func ResolvedInsertRow_set_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInsertRow_set_value_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertRow_set_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertRow_set_value_list(arg0, arg1)
}

func ResolvedInsertRow_add_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInsertRow_add_value_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertRow_add_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertRow_add_value_list(arg0, arg1)
}

func ResolvedInsertStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_table_scan(arg0, arg1)
}

func ResolvedInsertStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_set_table_scan(arg0, arg1)
}

func ResolvedInsertStmt_insert_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedInsertStmt_insert_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedInsertStmt_insert_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedInsertStmt_insert_mode(arg0, arg1)
}

func ResolvedInsertStmt_set_insert_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedInsertStmt_set_insert_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedInsertStmt_set_insert_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedInsertStmt_set_insert_mode(arg0, arg1)
}

func ResolvedInsertStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_assert_rows_modified(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_assert_rows_modified(arg0, arg1)
}

func ResolvedInsertStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_set_assert_rows_modified(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_set_assert_rows_modified(arg0, arg1)
}

func ResolvedInsertStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_returning(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_returning(arg0, arg1)
}

func ResolvedInsertStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_set_returning(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_set_returning(arg0, arg1)
}

func ResolvedInsertStmt_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_insert_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_insert_column_list(arg0, arg1)
}

func ResolvedInsertStmt_set_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_set_insert_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_set_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_set_insert_column_list(arg0, arg1)
}

func ResolvedInsertStmt_add_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_add_insert_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_add_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_add_insert_column_list(arg0, arg1)
}

func ResolvedInsertStmt_query_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_query_parameter_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_query_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_query_parameter_list(arg0, arg1)
}

func ResolvedInsertStmt_set_query_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_set_query_parameter_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_set_query_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_set_query_parameter_list(arg0, arg1)
}

func ResolvedInsertStmt_add_query_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_add_query_parameter_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_add_query_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_add_query_parameter_list(arg0, arg1)
}

func ResolvedInsertStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_query(arg0, arg1)
}

func ResolvedInsertStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_set_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_set_query(arg0, arg1)
}

func ResolvedInsertStmt_query_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_query_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_query_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_query_output_column_list(arg0, arg1)
}

func ResolvedInsertStmt_set_query_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_set_query_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_set_query_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_set_query_output_column_list(arg0, arg1)
}

func ResolvedInsertStmt_add_query_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_add_query_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_add_query_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_add_query_output_column_list(arg0, arg1)
}

func ResolvedInsertStmt_row_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_row_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_row_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_row_list(arg0, arg1)
}

func ResolvedInsertStmt_set_row_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_set_row_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_set_row_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_set_row_list(arg0, arg1)
}

func ResolvedInsertStmt_add_row_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedInsertStmt_add_row_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedInsertStmt_add_row_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedInsertStmt_add_row_list(arg0, arg1)
}

func ResolvedDeleteStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDeleteStmt_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDeleteStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDeleteStmt_table_scan(arg0, arg1)
}

func ResolvedDeleteStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDeleteStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDeleteStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDeleteStmt_set_table_scan(arg0, arg1)
}

func ResolvedDeleteStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDeleteStmt_assert_rows_modified(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDeleteStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDeleteStmt_assert_rows_modified(arg0, arg1)
}

func ResolvedDeleteStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDeleteStmt_set_assert_rows_modified(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDeleteStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDeleteStmt_set_assert_rows_modified(arg0, arg1)
}

func ResolvedDeleteStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDeleteStmt_returning(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDeleteStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDeleteStmt_returning(arg0, arg1)
}

func ResolvedDeleteStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDeleteStmt_set_returning(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDeleteStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDeleteStmt_set_returning(arg0, arg1)
}

func ResolvedDeleteStmt_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDeleteStmt_array_offset_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDeleteStmt_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDeleteStmt_array_offset_column(arg0, arg1)
}

func ResolvedDeleteStmt_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDeleteStmt_set_array_offset_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDeleteStmt_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDeleteStmt_set_array_offset_column(arg0, arg1)
}

func ResolvedDeleteStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDeleteStmt_where_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDeleteStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDeleteStmt_where_expr(arg0, arg1)
}

func ResolvedDeleteStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDeleteStmt_set_where_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDeleteStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDeleteStmt_set_where_expr(arg0, arg1)
}

func ResolvedUpdateItem_target(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_target(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_target(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_target(arg0, arg1)
}

func ResolvedUpdateItem_set_target(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_set_target(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_set_target(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_set_target(arg0, arg1)
}

func ResolvedUpdateItem_set_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_set_value(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_set_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_set_value(arg0, arg1)
}

func ResolvedUpdateItem_set_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_set_set_value(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_set_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_set_set_value(arg0, arg1)
}

func ResolvedUpdateItem_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_element_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_element_column(arg0, arg1)
}

func ResolvedUpdateItem_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_set_element_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_set_element_column(arg0, arg1)
}

func ResolvedUpdateItem_array_update_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_array_update_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_array_update_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_array_update_list(arg0, arg1)
}

func ResolvedUpdateItem_set_array_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_set_array_update_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_set_array_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_set_array_update_list(arg0, arg1)
}

func ResolvedUpdateItem_add_array_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_add_array_update_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_add_array_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_add_array_update_list(arg0, arg1)
}

func ResolvedUpdateItem_delete_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_delete_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_delete_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_delete_list(arg0, arg1)
}

func ResolvedUpdateItem_set_delete_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_set_delete_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_set_delete_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_set_delete_list(arg0, arg1)
}

func ResolvedUpdateItem_add_delete_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_add_delete_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_add_delete_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_add_delete_list(arg0, arg1)
}

func ResolvedUpdateItem_update_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_update_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_update_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_update_list(arg0, arg1)
}

func ResolvedUpdateItem_set_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_set_update_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_set_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_set_update_list(arg0, arg1)
}

func ResolvedUpdateItem_add_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_add_update_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_add_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_add_update_list(arg0, arg1)
}

func ResolvedUpdateItem_insert_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_insert_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_insert_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_insert_list(arg0, arg1)
}

func ResolvedUpdateItem_set_insert_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_set_insert_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_set_insert_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_set_insert_list(arg0, arg1)
}

func ResolvedUpdateItem_add_insert_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateItem_add_insert_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateItem_add_insert_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateItem_add_insert_list(arg0, arg1)
}

func ResolvedUpdateArrayItem_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateArrayItem_offset(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateArrayItem_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateArrayItem_offset(arg0, arg1)
}

func ResolvedUpdateArrayItem_set_offset(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateArrayItem_set_offset(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateArrayItem_set_offset(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateArrayItem_set_offset(arg0, arg1)
}

func ResolvedUpdateArrayItem_update_item(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateArrayItem_update_item(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateArrayItem_update_item(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateArrayItem_update_item(arg0, arg1)
}

func ResolvedUpdateArrayItem_set_update_item(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateArrayItem_set_update_item(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateArrayItem_set_update_item(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateArrayItem_set_update_item(arg0, arg1)
}

func ResolvedUpdateStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_table_scan(arg0, arg1)
}

func ResolvedUpdateStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_set_table_scan(arg0, arg1)
}

func ResolvedUpdateStmt_column_access_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_column_access_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_column_access_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_column_access_list(arg0, arg1)
}

func ResolvedUpdateStmt_set_column_access_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_set_column_access_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_set_column_access_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_set_column_access_list(arg0, arg1)
}

func ResolvedUpdateStmt_add_column_access_list(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedUpdateStmt_add_column_access_list(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedUpdateStmt_add_column_access_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedUpdateStmt_add_column_access_list(arg0, arg1)
}

func ResolvedUpdateStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_assert_rows_modified(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_assert_rows_modified(arg0, arg1)
}

func ResolvedUpdateStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_set_assert_rows_modified(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_set_assert_rows_modified(arg0, arg1)
}

func ResolvedUpdateStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_returning(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_returning(arg0, arg1)
}

func ResolvedUpdateStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_set_returning(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_set_returning(arg0, arg1)
}

func ResolvedUpdateStmt_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_array_offset_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_array_offset_column(arg0, arg1)
}

func ResolvedUpdateStmt_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_set_array_offset_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_set_array_offset_column(arg0, arg1)
}

func ResolvedUpdateStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_where_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_where_expr(arg0, arg1)
}

func ResolvedUpdateStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_set_where_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_set_where_expr(arg0, arg1)
}

func ResolvedUpdateStmt_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_update_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_update_item_list(arg0, arg1)
}

func ResolvedUpdateStmt_set_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_set_update_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_set_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_set_update_item_list(arg0, arg1)
}

func ResolvedUpdateStmt_add_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_add_update_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_add_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_add_update_item_list(arg0, arg1)
}

func ResolvedUpdateStmt_from_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_from_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_from_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_from_scan(arg0, arg1)
}

func ResolvedUpdateStmt_set_from_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUpdateStmt_set_from_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUpdateStmt_set_from_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUpdateStmt_set_from_scan(arg0, arg1)
}

func ResolvedMergeWhen_match_type(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedMergeWhen_match_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedMergeWhen_match_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedMergeWhen_match_type(arg0, arg1)
}

func ResolvedMergeWhen_set_match_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedMergeWhen_set_match_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedMergeWhen_set_match_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedMergeWhen_set_match_type(arg0, arg1)
}

func ResolvedMergeWhen_match_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedMergeWhen_match_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeWhen_match_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeWhen_match_expr(arg0, arg1)
}

func ResolvedMergeWhen_set_match_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMergeWhen_set_match_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeWhen_set_match_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeWhen_set_match_expr(arg0, arg1)
}

func ResolvedMergeWhen_action_type(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedMergeWhen_action_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedMergeWhen_action_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedMergeWhen_action_type(arg0, arg1)
}

func ResolvedMergeWhen_set_action_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedMergeWhen_set_action_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedMergeWhen_set_action_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedMergeWhen_set_action_type(arg0, arg1)
}

func ResolvedMergeWhen_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedMergeWhen_insert_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeWhen_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeWhen_insert_column_list(arg0, arg1)
}

func ResolvedMergeWhen_set_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMergeWhen_set_insert_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeWhen_set_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeWhen_set_insert_column_list(arg0, arg1)
}

func ResolvedMergeWhen_add_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMergeWhen_add_insert_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeWhen_add_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeWhen_add_insert_column_list(arg0, arg1)
}

func ResolvedMergeWhen_insert_row(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedMergeWhen_insert_row(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeWhen_insert_row(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeWhen_insert_row(arg0, arg1)
}

func ResolvedMergeWhen_set_insert_row(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMergeWhen_set_insert_row(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeWhen_set_insert_row(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeWhen_set_insert_row(arg0, arg1)
}

func ResolvedMergeWhen_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedMergeWhen_update_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeWhen_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeWhen_update_item_list(arg0, arg1)
}

func ResolvedMergeWhen_set_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMergeWhen_set_update_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeWhen_set_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeWhen_set_update_item_list(arg0, arg1)
}

func ResolvedMergeWhen_add_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMergeWhen_add_update_item_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeWhen_add_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeWhen_add_update_item_list(arg0, arg1)
}

func ResolvedMergeStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedMergeStmt_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeStmt_table_scan(arg0, arg1)
}

func ResolvedMergeStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMergeStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeStmt_set_table_scan(arg0, arg1)
}

func ResolvedMergeStmt_column_access_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedMergeStmt_column_access_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeStmt_column_access_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeStmt_column_access_list(arg0, arg1)
}

func ResolvedMergeStmt_set_column_access_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMergeStmt_set_column_access_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeStmt_set_column_access_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeStmt_set_column_access_list(arg0, arg1)
}

func ResolvedMergeStmt_add_column_access_list(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedMergeStmt_add_column_access_list(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedMergeStmt_add_column_access_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedMergeStmt_add_column_access_list(arg0, arg1)
}

func ResolvedMergeStmt_from_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedMergeStmt_from_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeStmt_from_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeStmt_from_scan(arg0, arg1)
}

func ResolvedMergeStmt_set_from_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMergeStmt_set_from_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeStmt_set_from_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeStmt_set_from_scan(arg0, arg1)
}

func ResolvedMergeStmt_merge_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedMergeStmt_merge_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeStmt_merge_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeStmt_merge_expr(arg0, arg1)
}

func ResolvedMergeStmt_set_merge_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMergeStmt_set_merge_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeStmt_set_merge_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeStmt_set_merge_expr(arg0, arg1)
}

func ResolvedMergeStmt_when_clause_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedMergeStmt_when_clause_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeStmt_when_clause_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeStmt_when_clause_list(arg0, arg1)
}

func ResolvedMergeStmt_set_when_clause_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMergeStmt_set_when_clause_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeStmt_set_when_clause_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeStmt_set_when_clause_list(arg0, arg1)
}

func ResolvedMergeStmt_add_when_clause_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedMergeStmt_add_when_clause_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedMergeStmt_add_when_clause_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedMergeStmt_add_when_clause_list(arg0, arg1)
}

func ResolvedTruncateStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedTruncateStmt_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTruncateStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedTruncateStmt_table_scan(arg0, arg1)
}

func ResolvedTruncateStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedTruncateStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTruncateStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedTruncateStmt_set_table_scan(arg0, arg1)
}

func ResolvedTruncateStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedTruncateStmt_where_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTruncateStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedTruncateStmt_where_expr(arg0, arg1)
}

func ResolvedTruncateStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedTruncateStmt_set_where_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTruncateStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedTruncateStmt_set_where_expr(arg0, arg1)
}

func ResolvedObjectUnit_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedObjectUnit_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedObjectUnit_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedObjectUnit_name_path(arg0, arg1)
}

func ResolvedObjectUnit_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedObjectUnit_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedObjectUnit_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedObjectUnit_set_name_path(arg0, arg1)
}

func ResolvedObjectUnit_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedObjectUnit_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedObjectUnit_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedObjectUnit_add_name_path(arg0, arg1)
}

func ResolvedPrivilege_action_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedPrivilege_action_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPrivilege_action_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedPrivilege_action_type(arg0, arg1)
}

func ResolvedPrivilege_set_action_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPrivilege_set_action_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPrivilege_set_action_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPrivilege_set_action_type(arg0, arg1)
}

func ResolvedPrivilege_unit_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedPrivilege_unit_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPrivilege_unit_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedPrivilege_unit_list(arg0, arg1)
}

func ResolvedPrivilege_set_unit_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPrivilege_set_unit_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPrivilege_set_unit_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPrivilege_set_unit_list(arg0, arg1)
}

func ResolvedPrivilege_add_unit_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPrivilege_add_unit_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPrivilege_add_unit_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPrivilege_add_unit_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedGrantOrRevokeStmt_privilege_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantOrRevokeStmt_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantOrRevokeStmt_privilege_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_set_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGrantOrRevokeStmt_set_privilege_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantOrRevokeStmt_set_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantOrRevokeStmt_set_privilege_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_add_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGrantOrRevokeStmt_add_privilege_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantOrRevokeStmt_add_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantOrRevokeStmt_add_privilege_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedGrantOrRevokeStmt_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantOrRevokeStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantOrRevokeStmt_object_type(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGrantOrRevokeStmt_set_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantOrRevokeStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantOrRevokeStmt_set_object_type(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedGrantOrRevokeStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantOrRevokeStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantOrRevokeStmt_name_path(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGrantOrRevokeStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantOrRevokeStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantOrRevokeStmt_set_name_path(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGrantOrRevokeStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantOrRevokeStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantOrRevokeStmt_add_name_path(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedGrantOrRevokeStmt_grantee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantOrRevokeStmt_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantOrRevokeStmt_grantee_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_set_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGrantOrRevokeStmt_set_grantee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantOrRevokeStmt_set_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantOrRevokeStmt_set_grantee_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_add_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGrantOrRevokeStmt_add_grantee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantOrRevokeStmt_add_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantOrRevokeStmt_add_grantee_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedGrantOrRevokeStmt_grantee_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantOrRevokeStmt_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantOrRevokeStmt_grantee_expr_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGrantOrRevokeStmt_set_grantee_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantOrRevokeStmt_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantOrRevokeStmt_set_grantee_expr_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGrantOrRevokeStmt_add_grantee_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantOrRevokeStmt_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantOrRevokeStmt_add_grantee_expr_list(arg0, arg1)
}

func ResolvedAlterObjectStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterObjectStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterObjectStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterObjectStmt_name_path(arg0, arg1)
}

func ResolvedAlterObjectStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterObjectStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterObjectStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterObjectStmt_set_name_path(arg0, arg1)
}

func ResolvedAlterObjectStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterObjectStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterObjectStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterObjectStmt_add_name_path(arg0, arg1)
}

func ResolvedAlterObjectStmt_alter_action_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterObjectStmt_alter_action_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterObjectStmt_alter_action_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterObjectStmt_alter_action_list(arg0, arg1)
}

func ResolvedAlterObjectStmt_set_alter_action_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterObjectStmt_set_alter_action_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterObjectStmt_set_alter_action_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterObjectStmt_set_alter_action_list(arg0, arg1)
}

func ResolvedAlterObjectStmt_add_alter_action_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterObjectStmt_add_alter_action_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterObjectStmt_add_alter_action_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterObjectStmt_add_alter_action_list(arg0, arg1)
}

func ResolvedAlterObjectStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedAlterObjectStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedAlterObjectStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedAlterObjectStmt_is_if_exists(arg0, arg1)
}

func ResolvedAlterObjectStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedAlterObjectStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedAlterObjectStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedAlterObjectStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedAlterColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedAlterColumnAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedAlterColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedAlterColumnAction_is_if_exists(arg0, arg1)
}

func ResolvedAlterColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedAlterColumnAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedAlterColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedAlterColumnAction_set_is_if_exists(arg0, arg1)
}

func ResolvedAlterColumnAction_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterColumnAction_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterColumnAction_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterColumnAction_column(arg0, arg1)
}

func ResolvedAlterColumnAction_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterColumnAction_set_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterColumnAction_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterColumnAction_set_column(arg0, arg1)
}

func ResolvedSetOptionsAction_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSetOptionsAction_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetOptionsAction_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSetOptionsAction_option_list(arg0, arg1)
}

func ResolvedSetOptionsAction_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSetOptionsAction_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetOptionsAction_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSetOptionsAction_set_option_list(arg0, arg1)
}

func ResolvedSetOptionsAction_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSetOptionsAction_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetOptionsAction_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSetOptionsAction_add_option_list(arg0, arg1)
}

func ResolvedAddColumnAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedAddColumnAction_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedAddColumnAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedAddColumnAction_is_if_not_exists(arg0, arg1)
}

func ResolvedAddColumnAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedAddColumnAction_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedAddColumnAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedAddColumnAction_set_is_if_not_exists(arg0, arg1)
}

func ResolvedAddColumnAction_column_definition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAddColumnAction_column_definition(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAddColumnAction_column_definition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAddColumnAction_column_definition(arg0, arg1)
}

func ResolvedAddColumnAction_set_column_definition(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAddColumnAction_set_column_definition(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAddColumnAction_set_column_definition(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAddColumnAction_set_column_definition(arg0, arg1)
}

func ResolvedAddConstraintAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedAddConstraintAction_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedAddConstraintAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedAddConstraintAction_is_if_not_exists(arg0, arg1)
}

func ResolvedAddConstraintAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedAddConstraintAction_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedAddConstraintAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedAddConstraintAction_set_is_if_not_exists(arg0, arg1)
}

func ResolvedAddConstraintAction_constraint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAddConstraintAction_constraint(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAddConstraintAction_constraint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAddConstraintAction_constraint(arg0, arg1)
}

func ResolvedAddConstraintAction_set_constraint(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAddConstraintAction_set_constraint(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAddConstraintAction_set_constraint(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAddConstraintAction_set_constraint(arg0, arg1)
}

func ResolvedAddConstraintAction_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAddConstraintAction_table(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAddConstraintAction_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAddConstraintAction_table(arg0, arg1)
}

func ResolvedAddConstraintAction_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAddConstraintAction_set_table(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAddConstraintAction_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAddConstraintAction_set_table(arg0, arg1)
}

func ResolvedDropConstraintAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedDropConstraintAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedDropConstraintAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedDropConstraintAction_is_if_exists(arg0, arg1)
}

func ResolvedDropConstraintAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedDropConstraintAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedDropConstraintAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedDropConstraintAction_set_is_if_exists(arg0, arg1)
}

func ResolvedDropConstraintAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropConstraintAction_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropConstraintAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropConstraintAction_name(arg0, arg1)
}

func ResolvedDropConstraintAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropConstraintAction_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropConstraintAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropConstraintAction_set_name(arg0, arg1)
}

func ResolvedDropPrimaryKeyAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedDropPrimaryKeyAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedDropPrimaryKeyAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedDropPrimaryKeyAction_is_if_exists(arg0, arg1)
}

func ResolvedDropPrimaryKeyAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedDropPrimaryKeyAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedDropPrimaryKeyAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedDropPrimaryKeyAction_set_is_if_exists(arg0, arg1)
}

func ResolvedAlterColumnOptionsAction_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterColumnOptionsAction_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterColumnOptionsAction_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterColumnOptionsAction_option_list(arg0, arg1)
}

func ResolvedAlterColumnOptionsAction_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterColumnOptionsAction_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterColumnOptionsAction_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterColumnOptionsAction_set_option_list(arg0, arg1)
}

func ResolvedAlterColumnOptionsAction_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterColumnOptionsAction_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterColumnOptionsAction_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterColumnOptionsAction_add_option_list(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_updated_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterColumnSetDataTypeAction_updated_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterColumnSetDataTypeAction_updated_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterColumnSetDataTypeAction_updated_type(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_set_updated_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterColumnSetDataTypeAction_set_updated_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterColumnSetDataTypeAction_set_updated_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterColumnSetDataTypeAction_set_updated_type(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_updated_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterColumnSetDataTypeAction_updated_type_parameters(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterColumnSetDataTypeAction_updated_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterColumnSetDataTypeAction_updated_type_parameters(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_updated_annotations(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterColumnSetDataTypeAction_updated_annotations(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterColumnSetDataTypeAction_updated_annotations(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterColumnSetDataTypeAction_updated_annotations(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_set_updated_annotations(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterColumnSetDataTypeAction_set_updated_annotations(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterColumnSetDataTypeAction_set_updated_annotations(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterColumnSetDataTypeAction_set_updated_annotations(arg0, arg1)
}

func ResolvedAlterColumnSetDefaultAction_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterColumnSetDefaultAction_default_value(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterColumnSetDefaultAction_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterColumnSetDefaultAction_default_value(arg0, arg1)
}

func ResolvedAlterColumnSetDefaultAction_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterColumnSetDefaultAction_set_default_value(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterColumnSetDefaultAction_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterColumnSetDefaultAction_set_default_value(arg0, arg1)
}

func ResolvedDropColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedDropColumnAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedDropColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedDropColumnAction_is_if_exists(arg0, arg1)
}

func ResolvedDropColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedDropColumnAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedDropColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedDropColumnAction_set_is_if_exists(arg0, arg1)
}

func ResolvedDropColumnAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropColumnAction_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropColumnAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropColumnAction_name(arg0, arg1)
}

func ResolvedDropColumnAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropColumnAction_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropColumnAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropColumnAction_set_name(arg0, arg1)
}

func ResolvedRenameColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedRenameColumnAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedRenameColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedRenameColumnAction_is_if_exists(arg0, arg1)
}

func ResolvedRenameColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedRenameColumnAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedRenameColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedRenameColumnAction_set_is_if_exists(arg0, arg1)
}

func ResolvedRenameColumnAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedRenameColumnAction_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRenameColumnAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedRenameColumnAction_name(arg0, arg1)
}

func ResolvedRenameColumnAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRenameColumnAction_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRenameColumnAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRenameColumnAction_set_name(arg0, arg1)
}

func ResolvedRenameColumnAction_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedRenameColumnAction_new_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRenameColumnAction_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedRenameColumnAction_new_name(arg0, arg1)
}

func ResolvedRenameColumnAction_set_new_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRenameColumnAction_set_new_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRenameColumnAction_set_new_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRenameColumnAction_set_new_name(arg0, arg1)
}

func ResolvedSetAsAction_entity_body_json(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSetAsAction_entity_body_json(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetAsAction_entity_body_json(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSetAsAction_entity_body_json(arg0, arg1)
}

func ResolvedSetAsAction_set_entity_body_json(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSetAsAction_set_entity_body_json(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetAsAction_set_entity_body_json(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSetAsAction_set_entity_body_json(arg0, arg1)
}

func ResolvedSetAsAction_entity_body_text(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSetAsAction_entity_body_text(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetAsAction_entity_body_text(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSetAsAction_entity_body_text(arg0, arg1)
}

func ResolvedSetAsAction_set_entity_body_text(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSetAsAction_set_entity_body_text(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetAsAction_set_entity_body_text(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSetAsAction_set_entity_body_text(arg0, arg1)
}

func ResolvedSetCollateClause_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedSetCollateClause_collation_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetCollateClause_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedSetCollateClause_collation_name(arg0, arg1)
}

func ResolvedSetCollateClause_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedSetCollateClause_set_collation_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedSetCollateClause_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedSetCollateClause_set_collation_name(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterTableSetOptionsStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterTableSetOptionsStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterTableSetOptionsStmt_name_path(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterTableSetOptionsStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterTableSetOptionsStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterTableSetOptionsStmt_set_name_path(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterTableSetOptionsStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterTableSetOptionsStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterTableSetOptionsStmt_add_name_path(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterTableSetOptionsStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterTableSetOptionsStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterTableSetOptionsStmt_option_list(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterTableSetOptionsStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterTableSetOptionsStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterTableSetOptionsStmt_set_option_list(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterTableSetOptionsStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterTableSetOptionsStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterTableSetOptionsStmt_add_option_list(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedAlterTableSetOptionsStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedAlterTableSetOptionsStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedAlterTableSetOptionsStmt_is_if_exists(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedAlterTableSetOptionsStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedAlterTableSetOptionsStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedAlterTableSetOptionsStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedRenameStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedRenameStmt_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRenameStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedRenameStmt_object_type(arg0, arg1)
}

func ResolvedRenameStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRenameStmt_set_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRenameStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRenameStmt_set_object_type(arg0, arg1)
}

func ResolvedRenameStmt_old_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedRenameStmt_old_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRenameStmt_old_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedRenameStmt_old_name_path(arg0, arg1)
}

func ResolvedRenameStmt_set_old_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRenameStmt_set_old_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRenameStmt_set_old_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRenameStmt_set_old_name_path(arg0, arg1)
}

func ResolvedRenameStmt_add_old_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRenameStmt_add_old_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRenameStmt_add_old_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRenameStmt_add_old_name_path(arg0, arg1)
}

func ResolvedRenameStmt_new_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedRenameStmt_new_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRenameStmt_new_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedRenameStmt_new_name_path(arg0, arg1)
}

func ResolvedRenameStmt_set_new_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRenameStmt_set_new_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRenameStmt_set_new_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRenameStmt_set_new_name_path(arg0, arg1)
}

func ResolvedRenameStmt_add_new_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRenameStmt_add_new_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRenameStmt_add_new_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRenameStmt_add_new_name_path(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreatePrivilegeRestrictionStmt_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreatePrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreatePrivilegeRestrictionStmt_object_type(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreatePrivilegeRestrictionStmt_set_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreatePrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreatePrivilegeRestrictionStmt_set_object_type(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreatePrivilegeRestrictionStmt_restrictee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreatePrivilegeRestrictionStmt_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreatePrivilegeRestrictionStmt_restrictee_list(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_create_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_create_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_create_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_create_mode(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_create_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_set_create_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_set_create_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_set_create_mode(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_name(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_set_name(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_target_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_target_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_target_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_target_name_path(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_set_target_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_set_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_set_target_name_path(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_add_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_add_target_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_add_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_add_target_name_path(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_grantee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_grantee_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_set_grantee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_set_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_set_grantee_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_add_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_add_grantee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_add_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_add_grantee_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_grantee_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_grantee_expr_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_table_scan(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_set_table_scan(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_predicate(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_predicate(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_predicate(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_set_predicate(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_set_predicate(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_set_predicate(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_predicate_str(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_predicate_str(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_predicate_str(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_predicate_str(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_predicate_str(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateRowAccessPolicyStmt_set_predicate_str(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateRowAccessPolicyStmt_set_predicate_str(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateRowAccessPolicyStmt_set_predicate_str(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropPrivilegeRestrictionStmt_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropPrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropPrivilegeRestrictionStmt_object_type(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropPrivilegeRestrictionStmt_set_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropPrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropPrivilegeRestrictionStmt_set_object_type(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedDropPrivilegeRestrictionStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedDropPrivilegeRestrictionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedDropPrivilegeRestrictionStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropPrivilegeRestrictionStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropPrivilegeRestrictionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropPrivilegeRestrictionStmt_name_path(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropPrivilegeRestrictionStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropPrivilegeRestrictionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropPrivilegeRestrictionStmt_set_name_path(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropPrivilegeRestrictionStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropPrivilegeRestrictionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropPrivilegeRestrictionStmt_add_name_path(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropPrivilegeRestrictionStmt_column_privilege_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropPrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropPrivilegeRestrictionStmt_column_privilege_list(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_is_drop_all(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedDropRowAccessPolicyStmt_is_drop_all(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedDropRowAccessPolicyStmt_is_drop_all(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedDropRowAccessPolicyStmt_is_drop_all(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_set_is_drop_all(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedDropRowAccessPolicyStmt_set_is_drop_all(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedDropRowAccessPolicyStmt_set_is_drop_all(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedDropRowAccessPolicyStmt_set_is_drop_all(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedDropRowAccessPolicyStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedDropRowAccessPolicyStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedDropRowAccessPolicyStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedDropRowAccessPolicyStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedDropRowAccessPolicyStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedDropRowAccessPolicyStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropRowAccessPolicyStmt_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropRowAccessPolicyStmt_name(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropRowAccessPolicyStmt_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropRowAccessPolicyStmt_set_name(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_target_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropRowAccessPolicyStmt_target_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropRowAccessPolicyStmt_target_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropRowAccessPolicyStmt_target_name_path(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_set_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropRowAccessPolicyStmt_set_target_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropRowAccessPolicyStmt_set_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropRowAccessPolicyStmt_set_target_name_path(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_add_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropRowAccessPolicyStmt_add_target_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropRowAccessPolicyStmt_add_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropRowAccessPolicyStmt_add_target_name_path(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedDropSearchIndexStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedDropSearchIndexStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedDropSearchIndexStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedDropSearchIndexStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedDropSearchIndexStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedDropSearchIndexStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropSearchIndexStmt_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropSearchIndexStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropSearchIndexStmt_name(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropSearchIndexStmt_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropSearchIndexStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropSearchIndexStmt_set_name(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropSearchIndexStmt_table_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropSearchIndexStmt_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropSearchIndexStmt_table_name_path(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_set_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropSearchIndexStmt_set_table_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropSearchIndexStmt_set_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropSearchIndexStmt_set_table_name_path(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_add_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropSearchIndexStmt_add_table_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropSearchIndexStmt_add_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropSearchIndexStmt_add_table_name_path(arg0, arg1)
}

func ResolvedGrantToAction_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedGrantToAction_grantee_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantToAction_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantToAction_grantee_expr_list(arg0, arg1)
}

func ResolvedGrantToAction_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGrantToAction_set_grantee_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantToAction_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantToAction_set_grantee_expr_list(arg0, arg1)
}

func ResolvedGrantToAction_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedGrantToAction_add_grantee_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedGrantToAction_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedGrantToAction_add_grantee_expr_list(arg0, arg1)
}

func ResolvedRestrictToAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedRestrictToAction_restrictee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRestrictToAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedRestrictToAction_restrictee_list(arg0, arg1)
}

func ResolvedRestrictToAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRestrictToAction_set_restrictee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRestrictToAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRestrictToAction_set_restrictee_list(arg0, arg1)
}

func ResolvedRestrictToAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRestrictToAction_add_restrictee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRestrictToAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRestrictToAction_add_restrictee_list(arg0, arg1)
}

func ResolvedAddToRestricteeListAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedAddToRestricteeListAction_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedAddToRestricteeListAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedAddToRestricteeListAction_is_if_not_exists(arg0, arg1)
}

func ResolvedAddToRestricteeListAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedAddToRestricteeListAction_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedAddToRestricteeListAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedAddToRestricteeListAction_set_is_if_not_exists(arg0, arg1)
}

func ResolvedAddToRestricteeListAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAddToRestricteeListAction_restrictee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAddToRestricteeListAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAddToRestricteeListAction_restrictee_list(arg0, arg1)
}

func ResolvedAddToRestricteeListAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAddToRestricteeListAction_set_restrictee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAddToRestricteeListAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAddToRestricteeListAction_set_restrictee_list(arg0, arg1)
}

func ResolvedAddToRestricteeListAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAddToRestricteeListAction_add_restrictee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAddToRestricteeListAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAddToRestricteeListAction_add_restrictee_list(arg0, arg1)
}

func ResolvedRemoveFromRestricteeListAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedRemoveFromRestricteeListAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedRemoveFromRestricteeListAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedRemoveFromRestricteeListAction_is_if_exists(arg0, arg1)
}

func ResolvedRemoveFromRestricteeListAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedRemoveFromRestricteeListAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedRemoveFromRestricteeListAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedRemoveFromRestricteeListAction_set_is_if_exists(arg0, arg1)
}

func ResolvedRemoveFromRestricteeListAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedRemoveFromRestricteeListAction_restrictee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRemoveFromRestricteeListAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedRemoveFromRestricteeListAction_restrictee_list(arg0, arg1)
}

func ResolvedRemoveFromRestricteeListAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRemoveFromRestricteeListAction_set_restrictee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRemoveFromRestricteeListAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRemoveFromRestricteeListAction_set_restrictee_list(arg0, arg1)
}

func ResolvedRemoveFromRestricteeListAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRemoveFromRestricteeListAction_add_restrictee_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRemoveFromRestricteeListAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRemoveFromRestricteeListAction_add_restrictee_list(arg0, arg1)
}

func ResolvedFilterUsingAction_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFilterUsingAction_predicate(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFilterUsingAction_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFilterUsingAction_predicate(arg0, arg1)
}

func ResolvedFilterUsingAction_set_predicate(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFilterUsingAction_set_predicate(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFilterUsingAction_set_predicate(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFilterUsingAction_set_predicate(arg0, arg1)
}

func ResolvedFilterUsingAction_predicate_str(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFilterUsingAction_predicate_str(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFilterUsingAction_predicate_str(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFilterUsingAction_predicate_str(arg0, arg1)
}

func ResolvedFilterUsingAction_set_predicate_str(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFilterUsingAction_set_predicate_str(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFilterUsingAction_set_predicate_str(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFilterUsingAction_set_predicate_str(arg0, arg1)
}

func ResolvedRevokeFromAction_revokee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedRevokeFromAction_revokee_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRevokeFromAction_revokee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedRevokeFromAction_revokee_expr_list(arg0, arg1)
}

func ResolvedRevokeFromAction_set_revokee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRevokeFromAction_set_revokee_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRevokeFromAction_set_revokee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRevokeFromAction_set_revokee_expr_list(arg0, arg1)
}

func ResolvedRevokeFromAction_add_revokee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRevokeFromAction_add_revokee_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRevokeFromAction_add_revokee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRevokeFromAction_add_revokee_expr_list(arg0, arg1)
}

func ResolvedRevokeFromAction_is_revoke_from_all(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedRevokeFromAction_is_revoke_from_all(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedRevokeFromAction_is_revoke_from_all(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedRevokeFromAction_is_revoke_from_all(arg0, arg1)
}

func ResolvedRevokeFromAction_set_is_revoke_from_all(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedRevokeFromAction_set_is_revoke_from_all(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedRevokeFromAction_set_is_revoke_from_all(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedRevokeFromAction_set_is_revoke_from_all(arg0, arg1)
}

func ResolvedRenameToAction_new_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedRenameToAction_new_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRenameToAction_new_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedRenameToAction_new_path(arg0, arg1)
}

func ResolvedRenameToAction_set_new_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRenameToAction_set_new_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRenameToAction_set_new_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRenameToAction_set_new_path(arg0, arg1)
}

func ResolvedRenameToAction_add_new_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRenameToAction_add_new_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRenameToAction_add_new_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRenameToAction_add_new_path(arg0, arg1)
}

func ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list(arg0, arg1)
}

func ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list(arg0, arg1)
}

func ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list(arg0, arg1)
}

func ResolvedAlterPrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterPrivilegeRestrictionStmt_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterPrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterPrivilegeRestrictionStmt_object_type(arg0, arg1)
}

func ResolvedAlterPrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterPrivilegeRestrictionStmt_set_object_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterPrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterPrivilegeRestrictionStmt_set_object_type(arg0, arg1)
}

func ResolvedAlterRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterRowAccessPolicyStmt_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterRowAccessPolicyStmt_name(arg0, arg1)
}

func ResolvedAlterRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterRowAccessPolicyStmt_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterRowAccessPolicyStmt_set_name(arg0, arg1)
}

func ResolvedAlterRowAccessPolicyStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterRowAccessPolicyStmt_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterRowAccessPolicyStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterRowAccessPolicyStmt_table_scan(arg0, arg1)
}

func ResolvedAlterRowAccessPolicyStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterRowAccessPolicyStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterRowAccessPolicyStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterRowAccessPolicyStmt_set_table_scan(arg0, arg1)
}

func ResolvedAlterAllRowAccessPoliciesStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterAllRowAccessPoliciesStmt_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterAllRowAccessPoliciesStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterAllRowAccessPoliciesStmt_table_scan(arg0, arg1)
}

func ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan(arg0, arg1)
}

func ResolvedCreateConstantStmt_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateConstantStmt_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateConstantStmt_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateConstantStmt_expr(arg0, arg1)
}

func ResolvedCreateConstantStmt_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateConstantStmt_set_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateConstantStmt_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateConstantStmt_set_expr(arg0, arg1)
}

func ResolvedCreateFunctionStmt_has_explicit_return_type(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCreateFunctionStmt_has_explicit_return_type(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateFunctionStmt_has_explicit_return_type(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCreateFunctionStmt_has_explicit_return_type(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_has_explicit_return_type(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateFunctionStmt_set_has_explicit_return_type(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateFunctionStmt_set_has_explicit_return_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateFunctionStmt_set_has_explicit_return_type(arg0, arg1)
}

func ResolvedCreateFunctionStmt_return_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_return_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_return_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_return_type(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_return_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_set_return_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_set_return_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_set_return_type(arg0, arg1)
}

func ResolvedCreateFunctionStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_argument_name_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_argument_name_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_set_argument_name_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_set_argument_name_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_add_argument_name_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_add_argument_name_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_signature(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_set_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_set_signature(arg0, arg1)
}

func ResolvedCreateFunctionStmt_is_aggregate(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCreateFunctionStmt_is_aggregate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateFunctionStmt_is_aggregate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCreateFunctionStmt_is_aggregate(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_is_aggregate(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateFunctionStmt_set_is_aggregate(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateFunctionStmt_set_is_aggregate(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateFunctionStmt_set_is_aggregate(arg0, arg1)
}

func ResolvedCreateFunctionStmt_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_language(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_language(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_set_language(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_set_language(arg0, arg1)
}

func ResolvedCreateFunctionStmt_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_code(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_code(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_code(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_set_code(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_set_code(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_set_code(arg0, arg1)
}

func ResolvedCreateFunctionStmt_aggregate_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_aggregate_expression_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_aggregate_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_aggregate_expression_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_aggregate_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_set_aggregate_expression_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_set_aggregate_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_set_aggregate_expression_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_add_aggregate_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_add_aggregate_expression_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_add_aggregate_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_add_aggregate_expression_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_function_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_function_expression(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_function_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_function_expression(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_function_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_set_function_expression(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_set_function_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_set_function_expression(arg0, arg1)
}

func ResolvedCreateFunctionStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_option_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_sql_security(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedCreateFunctionStmt_sql_security(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateFunctionStmt_sql_security(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedCreateFunctionStmt_sql_security(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_sql_security(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateFunctionStmt_set_sql_security(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateFunctionStmt_set_sql_security(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateFunctionStmt_set_sql_security(arg0, arg1)
}

func ResolvedCreateFunctionStmt_determinism_level(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedCreateFunctionStmt_determinism_level(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateFunctionStmt_determinism_level(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedCreateFunctionStmt_determinism_level(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_determinism_level(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateFunctionStmt_set_determinism_level(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateFunctionStmt_set_determinism_level(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateFunctionStmt_set_determinism_level(arg0, arg1)
}

func ResolvedCreateFunctionStmt_is_remote(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCreateFunctionStmt_is_remote(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateFunctionStmt_is_remote(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCreateFunctionStmt_is_remote(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_is_remote(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateFunctionStmt_set_is_remote(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateFunctionStmt_set_is_remote(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateFunctionStmt_set_is_remote(arg0, arg1)
}

func ResolvedCreateFunctionStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_connection(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_connection(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateFunctionStmt_set_connection(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateFunctionStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateFunctionStmt_set_connection(arg0, arg1)
}

func ResolvedArgumentDef_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedArgumentDef_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArgumentDef_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedArgumentDef_name(arg0, arg1)
}

func ResolvedArgumentDef_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedArgumentDef_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArgumentDef_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedArgumentDef_set_name(arg0, arg1)
}

func ResolvedArgumentDef_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedArgumentDef_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArgumentDef_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedArgumentDef_type(arg0, arg1)
}

func ResolvedArgumentDef_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedArgumentDef_set_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArgumentDef_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedArgumentDef_set_type(arg0, arg1)
}

func ResolvedArgumentDef_argument_kind(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedArgumentDef_argument_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedArgumentDef_argument_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedArgumentDef_argument_kind(arg0, arg1)
}

func ResolvedArgumentDef_set_argument_kind(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedArgumentDef_set_argument_kind(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedArgumentDef_set_argument_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedArgumentDef_set_argument_kind(arg0, arg1)
}

func ResolvedArgumentRef_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedArgumentRef_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArgumentRef_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedArgumentRef_name(arg0, arg1)
}

func ResolvedArgumentRef_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedArgumentRef_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArgumentRef_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedArgumentRef_set_name(arg0, arg1)
}

func ResolvedArgumentRef_argument_kind(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedArgumentRef_argument_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedArgumentRef_argument_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedArgumentRef_argument_kind(arg0, arg1)
}

func ResolvedArgumentRef_set_argument_kind(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedArgumentRef_set_argument_kind(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedArgumentRef_set_argument_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedArgumentRef_set_argument_kind(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_new(arg0 unsafe.Pointer, arg1 int, arg2 int, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 int, arg6 unsafe.Pointer, arg7 unsafe.Pointer, arg8 unsafe.Pointer, arg9 unsafe.Pointer, arg10 unsafe.Pointer, arg11 int, arg12 int, arg13 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_new(
		arg0,
		C.int(arg1),
		C.int(arg2),
		arg3,
		arg4,
		C.int(arg5),
		arg6,
		arg7,
		arg8,
		arg9,
		arg10,
		C.int(arg11),
		C.int(arg12),
		arg13,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_new(arg0 unsafe.Pointer, arg1 C.int, arg2 C.int, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 C.int, arg6 unsafe.Pointer, arg7 unsafe.Pointer, arg8 unsafe.Pointer, arg9 unsafe.Pointer, arg10 unsafe.Pointer, arg11 C.int, arg12 C.int, arg13 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_new(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13)
}

func ResolvedCreateTableFunctionStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_argument_name_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_argument_name_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_set_argument_name_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_set_argument_name_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_add_argument_name_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_add_argument_name_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_signature(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_set_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_set_signature(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_has_explicit_return_schema(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCreateTableFunctionStmt_has_explicit_return_schema(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_has_explicit_return_schema(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_has_explicit_return_schema(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_option_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_language(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_language(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_set_language(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_set_language(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_code(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_code(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_code(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_set_code(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_set_code(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_set_code(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_query(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_set_query(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_set_query(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_output_column_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_set_output_column_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateTableFunctionStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_add_output_column_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCreateTableFunctionStmt_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_is_value_table(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateTableFunctionStmt_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_set_is_value_table(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_sql_security(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedCreateTableFunctionStmt_sql_security(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_sql_security(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_sql_security(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_sql_security(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedCreateTableFunctionStmt_set_sql_security(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedCreateTableFunctionStmt_set_sql_security(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedCreateTableFunctionStmt_set_sql_security(arg0, arg1)
}

func ResolvedRelationArgumentScan_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedRelationArgumentScan_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRelationArgumentScan_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedRelationArgumentScan_name(arg0, arg1)
}

func ResolvedRelationArgumentScan_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedRelationArgumentScan_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedRelationArgumentScan_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedRelationArgumentScan_set_name(arg0, arg1)
}

func ResolvedRelationArgumentScan_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedRelationArgumentScan_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedRelationArgumentScan_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedRelationArgumentScan_is_value_table(arg0, arg1)
}

func ResolvedRelationArgumentScan_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedRelationArgumentScan_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedRelationArgumentScan_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedRelationArgumentScan_set_is_value_table(arg0, arg1)
}

func ResolvedArgumentList_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedArgumentList_arg_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArgumentList_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedArgumentList_arg_list(arg0, arg1)
}

func ResolvedArgumentList_set_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedArgumentList_set_arg_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArgumentList_set_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedArgumentList_set_arg_list(arg0, arg1)
}

func ResolvedArgumentList_add_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedArgumentList_add_arg_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedArgumentList_add_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedArgumentList_add_arg_list(arg0, arg1)
}

func ResolvedFunctionSignatureHolder_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionSignatureHolder_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionSignatureHolder_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionSignatureHolder_signature(arg0, arg1)
}

func ResolvedFunctionSignatureHolder_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedFunctionSignatureHolder_set_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionSignatureHolder_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionSignatureHolder_set_signature(arg0, arg1)
}

func ResolvedDropFunctionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedDropFunctionStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedDropFunctionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedDropFunctionStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropFunctionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedDropFunctionStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedDropFunctionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedDropFunctionStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropFunctionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropFunctionStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropFunctionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropFunctionStmt_name_path(arg0, arg1)
}

func ResolvedDropFunctionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropFunctionStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropFunctionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropFunctionStmt_set_name_path(arg0, arg1)
}

func ResolvedDropFunctionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropFunctionStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropFunctionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropFunctionStmt_add_name_path(arg0, arg1)
}

func ResolvedDropFunctionStmt_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropFunctionStmt_arguments(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropFunctionStmt_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropFunctionStmt_arguments(arg0, arg1)
}

func ResolvedDropFunctionStmt_set_arguments(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropFunctionStmt_set_arguments(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropFunctionStmt_set_arguments(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropFunctionStmt_set_arguments(arg0, arg1)
}

func ResolvedDropFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropFunctionStmt_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropFunctionStmt_signature(arg0, arg1)
}

func ResolvedDropFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropFunctionStmt_set_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropFunctionStmt_set_signature(arg0, arg1)
}

func ResolvedDropTableFunctionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedDropTableFunctionStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedDropTableFunctionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedDropTableFunctionStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropTableFunctionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedDropTableFunctionStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedDropTableFunctionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedDropTableFunctionStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropTableFunctionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedDropTableFunctionStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropTableFunctionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedDropTableFunctionStmt_name_path(arg0, arg1)
}

func ResolvedDropTableFunctionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropTableFunctionStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropTableFunctionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropTableFunctionStmt_set_name_path(arg0, arg1)
}

func ResolvedDropTableFunctionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedDropTableFunctionStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedDropTableFunctionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedDropTableFunctionStmt_add_name_path(arg0, arg1)
}

func ResolvedCallStmt_procedure(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCallStmt_procedure(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCallStmt_procedure(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCallStmt_procedure(arg0, arg1)
}

func ResolvedCallStmt_set_procedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCallStmt_set_procedure(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCallStmt_set_procedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCallStmt_set_procedure(arg0, arg1)
}

func ResolvedCallStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCallStmt_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCallStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCallStmt_signature(arg0, arg1)
}

func ResolvedCallStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCallStmt_set_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCallStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCallStmt_set_signature(arg0, arg1)
}

func ResolvedCallStmt_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCallStmt_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCallStmt_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCallStmt_argument_list(arg0, arg1)
}

func ResolvedCallStmt_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCallStmt_set_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCallStmt_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCallStmt_set_argument_list(arg0, arg1)
}

func ResolvedCallStmt_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCallStmt_add_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCallStmt_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCallStmt_add_argument_list(arg0, arg1)
}

func ResolvedImportStmt_import_kind(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedImportStmt_import_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedImportStmt_import_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedImportStmt_import_kind(arg0, arg1)
}

func ResolvedImportStmt_set_import_kind(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedImportStmt_set_import_kind(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedImportStmt_set_import_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedImportStmt_set_import_kind(arg0, arg1)
}

func ResolvedImportStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedImportStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedImportStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedImportStmt_name_path(arg0, arg1)
}

func ResolvedImportStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedImportStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedImportStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedImportStmt_set_name_path(arg0, arg1)
}

func ResolvedImportStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedImportStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedImportStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedImportStmt_add_name_path(arg0, arg1)
}

func ResolvedImportStmt_file_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedImportStmt_file_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedImportStmt_file_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedImportStmt_file_path(arg0, arg1)
}

func ResolvedImportStmt_set_file_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedImportStmt_set_file_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedImportStmt_set_file_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedImportStmt_set_file_path(arg0, arg1)
}

func ResolvedImportStmt_alias_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedImportStmt_alias_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedImportStmt_alias_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedImportStmt_alias_path(arg0, arg1)
}

func ResolvedImportStmt_set_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedImportStmt_set_alias_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedImportStmt_set_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedImportStmt_set_alias_path(arg0, arg1)
}

func ResolvedImportStmt_add_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedImportStmt_add_alias_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedImportStmt_add_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedImportStmt_add_alias_path(arg0, arg1)
}

func ResolvedImportStmt_into_alias_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedImportStmt_into_alias_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedImportStmt_into_alias_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedImportStmt_into_alias_path(arg0, arg1)
}

func ResolvedImportStmt_set_into_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedImportStmt_set_into_alias_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedImportStmt_set_into_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedImportStmt_set_into_alias_path(arg0, arg1)
}

func ResolvedImportStmt_add_into_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedImportStmt_add_into_alias_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedImportStmt_add_into_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedImportStmt_add_into_alias_path(arg0, arg1)
}

func ResolvedImportStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedImportStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedImportStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedImportStmt_option_list(arg0, arg1)
}

func ResolvedImportStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedImportStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedImportStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedImportStmt_set_option_list(arg0, arg1)
}

func ResolvedImportStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedImportStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedImportStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedImportStmt_add_option_list(arg0, arg1)
}

func ResolvedModuleStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedModuleStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedModuleStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedModuleStmt_name_path(arg0, arg1)
}

func ResolvedModuleStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedModuleStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedModuleStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedModuleStmt_set_name_path(arg0, arg1)
}

func ResolvedModuleStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedModuleStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedModuleStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedModuleStmt_add_name_path(arg0, arg1)
}

func ResolvedModuleStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedModuleStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedModuleStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedModuleStmt_option_list(arg0, arg1)
}

func ResolvedModuleStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedModuleStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedModuleStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedModuleStmt_set_option_list(arg0, arg1)
}

func ResolvedModuleStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedModuleStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedModuleStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedModuleStmt_add_option_list(arg0, arg1)
}

func ResolvedAggregateHavingModifier_kind(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedAggregateHavingModifier_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedAggregateHavingModifier_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedAggregateHavingModifier_kind(arg0, arg1)
}

func ResolvedAggregateHavingModifier_set_kind(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedAggregateHavingModifier_set_kind(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedAggregateHavingModifier_set_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedAggregateHavingModifier_set_kind(arg0, arg1)
}

func ResolvedAggregateHavingModifier_having_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAggregateHavingModifier_having_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateHavingModifier_having_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateHavingModifier_having_expr(arg0, arg1)
}

func ResolvedAggregateHavingModifier_set_having_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAggregateHavingModifier_set_having_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAggregateHavingModifier_set_having_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAggregateHavingModifier_set_having_expr(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateMaterializedViewStmt_column_definition_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateMaterializedViewStmt_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateMaterializedViewStmt_column_definition_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateMaterializedViewStmt_set_column_definition_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateMaterializedViewStmt_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateMaterializedViewStmt_set_column_definition_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateMaterializedViewStmt_add_column_definition_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateMaterializedViewStmt_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateMaterializedViewStmt_add_column_definition_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateMaterializedViewStmt_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateMaterializedViewStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateMaterializedViewStmt_partition_by_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateMaterializedViewStmt_set_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateMaterializedViewStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateMaterializedViewStmt_set_partition_by_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateMaterializedViewStmt_add_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateMaterializedViewStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateMaterializedViewStmt_add_partition_by_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateMaterializedViewStmt_cluster_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateMaterializedViewStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateMaterializedViewStmt_cluster_by_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateMaterializedViewStmt_set_cluster_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateMaterializedViewStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateMaterializedViewStmt_set_cluster_by_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateMaterializedViewStmt_add_cluster_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateMaterializedViewStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateMaterializedViewStmt_add_cluster_by_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateProcedureStmt_argument_name_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateProcedureStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateProcedureStmt_argument_name_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateProcedureStmt_set_argument_name_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateProcedureStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateProcedureStmt_set_argument_name_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateProcedureStmt_add_argument_name_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateProcedureStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateProcedureStmt_add_argument_name_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateProcedureStmt_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateProcedureStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateProcedureStmt_signature(arg0, arg1)
}

func ResolvedCreateProcedureStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateProcedureStmt_set_signature(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateProcedureStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateProcedureStmt_set_signature(arg0, arg1)
}

func ResolvedCreateProcedureStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateProcedureStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateProcedureStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateProcedureStmt_option_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateProcedureStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateProcedureStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateProcedureStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateProcedureStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateProcedureStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateProcedureStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_procedure_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateProcedureStmt_procedure_body(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateProcedureStmt_procedure_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateProcedureStmt_procedure_body(arg0, arg1)
}

func ResolvedCreateProcedureStmt_set_procedure_body(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateProcedureStmt_set_procedure_body(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateProcedureStmt_set_procedure_body(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateProcedureStmt_set_procedure_body(arg0, arg1)
}

func ResolvedExecuteImmediateArgument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExecuteImmediateArgument_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExecuteImmediateArgument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExecuteImmediateArgument_name(arg0, arg1)
}

func ResolvedExecuteImmediateArgument_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExecuteImmediateArgument_set_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExecuteImmediateArgument_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExecuteImmediateArgument_set_name(arg0, arg1)
}

func ResolvedExecuteImmediateArgument_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExecuteImmediateArgument_expression(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExecuteImmediateArgument_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExecuteImmediateArgument_expression(arg0, arg1)
}

func ResolvedExecuteImmediateArgument_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExecuteImmediateArgument_set_expression(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExecuteImmediateArgument_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExecuteImmediateArgument_set_expression(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExecuteImmediateStmt_sql(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExecuteImmediateStmt_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExecuteImmediateStmt_sql(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExecuteImmediateStmt_set_sql(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExecuteImmediateStmt_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExecuteImmediateStmt_set_sql(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_into_identifier_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExecuteImmediateStmt_into_identifier_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExecuteImmediateStmt_into_identifier_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExecuteImmediateStmt_into_identifier_list(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_set_into_identifier_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExecuteImmediateStmt_set_into_identifier_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExecuteImmediateStmt_set_into_identifier_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExecuteImmediateStmt_set_into_identifier_list(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_add_into_identifier_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExecuteImmediateStmt_add_into_identifier_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExecuteImmediateStmt_add_into_identifier_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExecuteImmediateStmt_add_into_identifier_list(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_using_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedExecuteImmediateStmt_using_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExecuteImmediateStmt_using_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedExecuteImmediateStmt_using_argument_list(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_set_using_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExecuteImmediateStmt_set_using_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExecuteImmediateStmt_set_using_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExecuteImmediateStmt_set_using_argument_list(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_add_using_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedExecuteImmediateStmt_add_using_argument_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedExecuteImmediateStmt_add_using_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedExecuteImmediateStmt_add_using_argument_list(arg0, arg1)
}

func ResolvedAssignmentStmt_target(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAssignmentStmt_target(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAssignmentStmt_target(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAssignmentStmt_target(arg0, arg1)
}

func ResolvedAssignmentStmt_set_target(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAssignmentStmt_set_target(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAssignmentStmt_set_target(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAssignmentStmt_set_target(arg0, arg1)
}

func ResolvedAssignmentStmt_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAssignmentStmt_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAssignmentStmt_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAssignmentStmt_expr(arg0, arg1)
}

func ResolvedAssignmentStmt_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAssignmentStmt_set_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAssignmentStmt_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAssignmentStmt_set_expr(arg0, arg1)
}

func ResolvedCreateEntityStmt_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateEntityStmt_entity_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateEntityStmt_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateEntityStmt_entity_type(arg0, arg1)
}

func ResolvedCreateEntityStmt_set_entity_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateEntityStmt_set_entity_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateEntityStmt_set_entity_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateEntityStmt_set_entity_type(arg0, arg1)
}

func ResolvedCreateEntityStmt_entity_body_json(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateEntityStmt_entity_body_json(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateEntityStmt_entity_body_json(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateEntityStmt_entity_body_json(arg0, arg1)
}

func ResolvedCreateEntityStmt_set_entity_body_json(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateEntityStmt_set_entity_body_json(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateEntityStmt_set_entity_body_json(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateEntityStmt_set_entity_body_json(arg0, arg1)
}

func ResolvedCreateEntityStmt_entity_body_text(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateEntityStmt_entity_body_text(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateEntityStmt_entity_body_text(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateEntityStmt_entity_body_text(arg0, arg1)
}

func ResolvedCreateEntityStmt_set_entity_body_text(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateEntityStmt_set_entity_body_text(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateEntityStmt_set_entity_body_text(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateEntityStmt_set_entity_body_text(arg0, arg1)
}

func ResolvedCreateEntityStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCreateEntityStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateEntityStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateEntityStmt_option_list(arg0, arg1)
}

func ResolvedCreateEntityStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateEntityStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateEntityStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateEntityStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateEntityStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCreateEntityStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCreateEntityStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCreateEntityStmt_add_option_list(arg0, arg1)
}

func ResolvedAlterEntityStmt_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAlterEntityStmt_entity_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterEntityStmt_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterEntityStmt_entity_type(arg0, arg1)
}

func ResolvedAlterEntityStmt_set_entity_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAlterEntityStmt_set_entity_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAlterEntityStmt_set_entity_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAlterEntityStmt_set_entity_type(arg0, arg1)
}

func ResolvedPivotColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedPivotColumn_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotColumn_column(arg0, arg1)
}

func ResolvedPivotColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPivotColumn_set_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotColumn_set_column(arg0, arg1)
}

func ResolvedPivotColumn_pivot_expr_index(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedPivotColumn_pivot_expr_index(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedPivotColumn_pivot_expr_index(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedPivotColumn_pivot_expr_index(arg0, arg1)
}

func ResolvedPivotColumn_set_pivot_expr_index(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedPivotColumn_set_pivot_expr_index(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedPivotColumn_set_pivot_expr_index(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedPivotColumn_set_pivot_expr_index(arg0, arg1)
}

func ResolvedPivotColumn_pivot_value_index(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedPivotColumn_pivot_value_index(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedPivotColumn_pivot_value_index(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedPivotColumn_pivot_value_index(arg0, arg1)
}

func ResolvedPivotColumn_set_pivot_value_index(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedPivotColumn_set_pivot_value_index(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedPivotColumn_set_pivot_value_index(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedPivotColumn_set_pivot_value_index(arg0, arg1)
}

func ResolvedPivotScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedPivotScan_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_input_scan(arg0, arg1)
}

func ResolvedPivotScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPivotScan_set_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_set_input_scan(arg0, arg1)
}

func ResolvedPivotScan_group_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedPivotScan_group_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_group_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_group_by_list(arg0, arg1)
}

func ResolvedPivotScan_set_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPivotScan_set_group_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_set_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_set_group_by_list(arg0, arg1)
}

func ResolvedPivotScan_add_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPivotScan_add_group_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_add_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_add_group_by_list(arg0, arg1)
}

func ResolvedPivotScan_pivot_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedPivotScan_pivot_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_pivot_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_pivot_expr_list(arg0, arg1)
}

func ResolvedPivotScan_set_pivot_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPivotScan_set_pivot_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_set_pivot_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_set_pivot_expr_list(arg0, arg1)
}

func ResolvedPivotScan_add_pivot_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPivotScan_add_pivot_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_add_pivot_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_add_pivot_expr_list(arg0, arg1)
}

func ResolvedPivotScan_for_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedPivotScan_for_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_for_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_for_expr(arg0, arg1)
}

func ResolvedPivotScan_set_for_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPivotScan_set_for_expr(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_set_for_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_set_for_expr(arg0, arg1)
}

func ResolvedPivotScan_pivot_value_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedPivotScan_pivot_value_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_pivot_value_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_pivot_value_list(arg0, arg1)
}

func ResolvedPivotScan_set_pivot_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPivotScan_set_pivot_value_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_set_pivot_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_set_pivot_value_list(arg0, arg1)
}

func ResolvedPivotScan_add_pivot_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPivotScan_add_pivot_value_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_add_pivot_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_add_pivot_value_list(arg0, arg1)
}

func ResolvedPivotScan_pivot_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedPivotScan_pivot_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_pivot_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_pivot_column_list(arg0, arg1)
}

func ResolvedPivotScan_set_pivot_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPivotScan_set_pivot_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_set_pivot_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_set_pivot_column_list(arg0, arg1)
}

func ResolvedPivotScan_add_pivot_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedPivotScan_add_pivot_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedPivotScan_add_pivot_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedPivotScan_add_pivot_column_list(arg0, arg1)
}

func ResolvedReturningClause_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedReturningClause_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReturningClause_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedReturningClause_output_column_list(arg0, arg1)
}

func ResolvedReturningClause_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedReturningClause_set_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReturningClause_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedReturningClause_set_output_column_list(arg0, arg1)
}

func ResolvedReturningClause_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedReturningClause_add_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReturningClause_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedReturningClause_add_output_column_list(arg0, arg1)
}

func ResolvedReturningClause_action_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedReturningClause_action_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReturningClause_action_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedReturningClause_action_column(arg0, arg1)
}

func ResolvedReturningClause_set_action_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedReturningClause_set_action_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReturningClause_set_action_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedReturningClause_set_action_column(arg0, arg1)
}

func ResolvedReturningClause_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedReturningClause_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReturningClause_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedReturningClause_expr_list(arg0, arg1)
}

func ResolvedReturningClause_set_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedReturningClause_set_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReturningClause_set_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedReturningClause_set_expr_list(arg0, arg1)
}

func ResolvedReturningClause_add_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedReturningClause_add_expr_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedReturningClause_add_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedReturningClause_add_expr_list(arg0, arg1)
}

func ResolvedUnpivotArg_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUnpivotArg_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotArg_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotArg_column_list(arg0, arg1)
}

func ResolvedUnpivotArg_set_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUnpivotArg_set_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotArg_set_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotArg_set_column_list(arg0, arg1)
}

func ResolvedUnpivotArg_add_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUnpivotArg_add_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotArg_add_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotArg_add_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_input_scan(arg0, arg1)
}

func ResolvedUnpivotScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_set_input_scan(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_set_input_scan(arg0, arg1)
}

func ResolvedUnpivotScan_value_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_value_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_value_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_value_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_set_value_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_set_value_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_set_value_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_set_value_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_add_value_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_add_value_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_add_value_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_add_value_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_label_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_label_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_label_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_label_column(arg0, arg1)
}

func ResolvedUnpivotScan_set_label_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_set_label_column(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_set_label_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_set_label_column(arg0, arg1)
}

func ResolvedUnpivotScan_label_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_label_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_label_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_label_list(arg0, arg1)
}

func ResolvedUnpivotScan_set_label_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_set_label_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_set_label_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_set_label_list(arg0, arg1)
}

func ResolvedUnpivotScan_add_label_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_add_label_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_add_label_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_add_label_list(arg0, arg1)
}

func ResolvedUnpivotScan_unpivot_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_unpivot_arg_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_unpivot_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_unpivot_arg_list(arg0, arg1)
}

func ResolvedUnpivotScan_set_unpivot_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_set_unpivot_arg_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_set_unpivot_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_set_unpivot_arg_list(arg0, arg1)
}

func ResolvedUnpivotScan_add_unpivot_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_add_unpivot_arg_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_add_unpivot_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_add_unpivot_arg_list(arg0, arg1)
}

func ResolvedUnpivotScan_projected_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_projected_input_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_projected_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_projected_input_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_set_projected_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_set_projected_input_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_set_projected_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_set_projected_input_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_add_projected_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedUnpivotScan_add_projected_input_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedUnpivotScan_add_projected_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedUnpivotScan_add_projected_input_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_include_nulls(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedUnpivotScan_include_nulls(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedUnpivotScan_include_nulls(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedUnpivotScan_include_nulls(arg0, arg1)
}

func ResolvedUnpivotScan_set_include_nulls(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedUnpivotScan_set_include_nulls(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedUnpivotScan_set_include_nulls(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedUnpivotScan_set_include_nulls(arg0, arg1)
}

func ResolvedCloneDataStmt_target_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCloneDataStmt_target_table(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCloneDataStmt_target_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCloneDataStmt_target_table(arg0, arg1)
}

func ResolvedCloneDataStmt_set_target_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCloneDataStmt_set_target_table(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCloneDataStmt_set_target_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCloneDataStmt_set_target_table(arg0, arg1)
}

func ResolvedCloneDataStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCloneDataStmt_clone_from(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCloneDataStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCloneDataStmt_clone_from(arg0, arg1)
}

func ResolvedCloneDataStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedCloneDataStmt_set_clone_from(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCloneDataStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedCloneDataStmt_set_clone_from(arg0, arg1)
}

func ResolvedTableAndColumnInfo_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedTableAndColumnInfo_table(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTableAndColumnInfo_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedTableAndColumnInfo_table(arg0, arg1)
}

func ResolvedTableAndColumnInfo_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedTableAndColumnInfo_set_table(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTableAndColumnInfo_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedTableAndColumnInfo_set_table(arg0, arg1)
}

func ResolvedTableAndColumnInfo_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedTableAndColumnInfo_column_index_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTableAndColumnInfo_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedTableAndColumnInfo_column_index_list(arg0, arg1)
}

func ResolvedTableAndColumnInfo_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedTableAndColumnInfo_set_column_index_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedTableAndColumnInfo_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedTableAndColumnInfo_set_column_index_list(arg0, arg1)
}

func ResolvedTableAndColumnInfo_add_column_index_list(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedTableAndColumnInfo_add_column_index_list(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedTableAndColumnInfo_add_column_index_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedTableAndColumnInfo_add_column_index_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAnalyzeStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyzeStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyzeStmt_option_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAnalyzeStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyzeStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyzeStmt_set_option_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAnalyzeStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyzeStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyzeStmt_add_option_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_table_and_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAnalyzeStmt_table_and_column_index_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyzeStmt_table_and_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyzeStmt_table_and_column_index_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_set_table_and_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAnalyzeStmt_set_table_and_column_index_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyzeStmt_set_table_and_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyzeStmt_set_table_and_column_index_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_add_table_and_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAnalyzeStmt_add_table_and_column_index_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAnalyzeStmt_add_table_and_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAnalyzeStmt_add_table_and_column_index_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_insertion_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedAuxLoadDataStmt_insertion_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedAuxLoadDataStmt_insertion_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_insertion_mode(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_insertion_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_ResolvedAuxLoadDataStmt_set_insertion_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_ResolvedAuxLoadDataStmt_set_insertion_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_set_insertion_mode(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_name_path(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_set_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_set_name_path(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_add_name_path(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_add_name_path(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_output_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_set_output_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_add_output_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_column_definition_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_column_definition_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_set_column_definition_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_set_column_definition_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_add_column_definition_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_add_column_definition_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_pseudo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_pseudo_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_pseudo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_pseudo_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_set_pseudo_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_set_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_set_pseudo_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_add_pseudo_column_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_add_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_add_pseudo_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_primary_key(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_primary_key(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_primary_key(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_primary_key(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_primary_key(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_set_primary_key(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_set_primary_key(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_set_primary_key(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_foreign_key_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_foreign_key_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_foreign_key_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_foreign_key_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_set_foreign_key_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_set_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_set_foreign_key_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_add_foreign_key_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_add_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_add_foreign_key_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_check_constraint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_check_constraint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_check_constraint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_check_constraint_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_set_check_constraint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_set_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_set_check_constraint_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_add_check_constraint_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_add_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_add_check_constraint_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_partition_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_set_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_set_partition_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_add_partition_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_add_partition_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_cluster_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_cluster_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_set_cluster_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_set_cluster_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_add_cluster_by_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_add_cluster_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_option_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_set_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_set_option_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_add_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_add_option_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_with_partition_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_with_partition_columns(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_with_partition_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_with_partition_columns(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_with_partition_columns(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_set_with_partition_columns(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_set_with_partition_columns(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_set_with_partition_columns(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_connection(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_connection(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_set_connection(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_set_connection(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_from_files_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_from_files_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_from_files_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_from_files_option_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_from_files_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_set_from_files_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_set_from_files_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_set_from_files_option_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_from_files_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_ResolvedAuxLoadDataStmt_add_from_files_option_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedAuxLoadDataStmt_add_from_files_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_ResolvedAuxLoadDataStmt_add_from_files_option_list(arg0, arg1)
}

func ResolvedColumn_IsInitialized(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedColumn_IsInitialized(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedColumn_IsInitialized(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedColumn_IsInitialized(arg0, arg1)
}

func ResolvedColumn_Clear(arg0 unsafe.Pointer) {
	zetasql_ResolvedColumn_Clear(
		arg0,
	)
}

func zetasql_ResolvedColumn_Clear(arg0 unsafe.Pointer) {
	C.export_zetasql_ResolvedColumn_Clear(arg0)
}

func ResolvedColumn_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumn_DebugString(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumn_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumn_DebugString(arg0, arg1)
}

func ResolvedColumn_ShortDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumn_ShortDebugString(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumn_ShortDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumn_ShortDebugString(arg0, arg1)
}

func ResolvedColumn_column_id(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_ResolvedColumn_column_id(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedColumn_column_id(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_ResolvedColumn_column_id(arg0, arg1)
}

func ResolvedColumn_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumn_table_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumn_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumn_table_name(arg0, arg1)
}

func ResolvedColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumn_name(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumn_name(arg0, arg1)
}

func ResolvedColumn_table_name_id(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumn_table_name_id(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumn_table_name_id(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumn_table_name_id(arg0, arg1)
}

func ResolvedColumn_name_id(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumn_name_id(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumn_name_id(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumn_name_id(arg0, arg1)
}

func ResolvedColumn_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumn_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumn_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumn_type(arg0, arg1)
}

func ResolvedColumn_type_annotation_map(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumn_type_annotation_map(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumn_type_annotation_map(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumn_type_annotation_map(arg0, arg1)
}

func ResolvedColumn_annotated_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedColumn_annotated_type(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedColumn_annotated_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedColumn_annotated_type(arg0, arg1)
}

func ResolvedCollation_Empty(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCollation_Empty(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCollation_Empty(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCollation_Empty(arg0, arg1)
}

func ResolvedCollation_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_ResolvedCollation_Equals(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_ResolvedCollation_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_ResolvedCollation_Equals(arg0, arg1, arg2)
}

func ResolvedCollation_HasCompatibleStructure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_ResolvedCollation_HasCompatibleStructure(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_ResolvedCollation_HasCompatibleStructure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_ResolvedCollation_HasCompatibleStructure(arg0, arg1, arg2)
}

func ResolvedCollation_HasCollation(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_ResolvedCollation_HasCollation(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_ResolvedCollation_HasCollation(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_ResolvedCollation_HasCollation(arg0, arg1)
}

func ResolvedCollation_CollationName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCollation_CollationName(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCollation_CollationName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCollation_CollationName(arg0, arg1)
}

func ResolvedCollation_child_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCollation_child_list(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCollation_child_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCollation_child_list(arg0, arg1)
}

func ResolvedCollation_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedCollation_DebugString(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedCollation_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedCollation_DebugString(arg0, arg1)
}

func ResolvedFunctionCallInfo_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ResolvedFunctionCallInfo_DebugString(
		arg0,
		arg1,
	)
}

func zetasql_ResolvedFunctionCallInfo_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ResolvedFunctionCallInfo_DebugString(arg0, arg1)
}

func GoCatalog_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_GoCatalog_new(
		arg0,
		arg1,
	)
}

func zetasql_GoCatalog_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_GoCatalog_new(arg0, arg1)
}

func GoTable_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_GoTable_new(
		arg0,
		arg1,
	)
}

func zetasql_GoTable_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_GoTable_new(arg0, arg1)
}

func Type_Kind(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_Type_Kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_Kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_Type_Kind(arg0, arg1)
}

func Type_IsInt32(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsInt32(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsInt32(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsInt32(arg0, arg1)
}

func Type_IsInt64(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsInt64(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsInt64(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsInt64(arg0, arg1)
}

func Type_IsUint32(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsUint32(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsUint32(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsUint32(arg0, arg1)
}

func Type_IsUint64(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsUint64(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsUint64(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsUint64(arg0, arg1)
}

func Type_IsBool(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsBool(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsBool(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsBool(arg0, arg1)
}

func Type_IsFloat(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsFloat(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsFloat(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsFloat(arg0, arg1)
}

func Type_IsDouble(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsDouble(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsDouble(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsDouble(arg0, arg1)
}

func Type_IsString(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsString(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsString(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsString(arg0, arg1)
}

func Type_IsBytes(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsBytes(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsBytes(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsBytes(arg0, arg1)
}

func Type_IsDate(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsDate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsDate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsDate(arg0, arg1)
}

func Type_IsTimestamp(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsTimestamp(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsTimestamp(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsTimestamp(arg0, arg1)
}

func Type_IsTime(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsTime(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsTime(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsTime(arg0, arg1)
}

func Type_IsDatetime(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsDatetime(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsDatetime(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsDatetime(arg0, arg1)
}

func Type_IsInterval(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsInterval(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsInterval(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsInterval(arg0, arg1)
}

func Type_IsNumericType(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsNumericType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsNumericType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsNumericType(arg0, arg1)
}

func Type_IsBigNumericType(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsBigNumericType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsBigNumericType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsBigNumericType(arg0, arg1)
}

func Type_IsJsonType(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsJsonType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsJsonType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsJsonType(arg0, arg1)
}

func Type_IsFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsFeatureV12CivilTimeType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsFeatureV12CivilTimeType(arg0, arg1)
}

func Type_UsingFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_UsingFeatureV12CivilTimeType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_UsingFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_UsingFeatureV12CivilTimeType(arg0, arg1)
}

func Type_IsCivilDateOrTimeType(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsCivilDateOrTimeType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsCivilDateOrTimeType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsCivilDateOrTimeType(arg0, arg1)
}

func Type_IsGeography(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsGeography(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsGeography(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsGeography(arg0, arg1)
}

func Type_IsJson(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsJson(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsJson(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsJson(arg0, arg1)
}

func Type_IsEnum(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsEnum(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsEnum(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsEnum(arg0, arg1)
}

func Type_IsArray(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsArray(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsArray(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsArray(arg0, arg1)
}

func Type_IsStruct(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsStruct(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsStruct(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsStruct(arg0, arg1)
}

func Type_IsProto(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsProto(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsProto(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsProto(arg0, arg1)
}

func Type_IsStructOrProto(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsStructOrProto(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsStructOrProto(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsStructOrProto(arg0, arg1)
}

func Type_IsFloatingPoint(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsFloatingPoint(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsFloatingPoint(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsFloatingPoint(arg0, arg1)
}

func Type_IsNumerical(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsNumerical(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsNumerical(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsNumerical(arg0, arg1)
}

func Type_IsInteger(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsInteger(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsInteger(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsInteger(arg0, arg1)
}

func Type_IsInteger32(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsInteger32(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsInteger32(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsInteger32(arg0, arg1)
}

func Type_IsInteger64(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsInteger64(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsInteger64(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsInteger64(arg0, arg1)
}

func Type_IsSignedInteger(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsSignedInteger(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsSignedInteger(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsSignedInteger(arg0, arg1)
}

func Type_IsUnsignedInteger(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsUnsignedInteger(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsUnsignedInteger(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsUnsignedInteger(arg0, arg1)
}

func Type_IsSimpleType(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsSimpleType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsSimpleType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsSimpleType(arg0, arg1)
}

func Type_IsExtendedType(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_IsExtendedType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_IsExtendedType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_IsExtendedType(arg0, arg1)
}

func Type_AsArray(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Type_AsArray(
		arg0,
		arg1,
	)
}

func zetasql_Type_AsArray(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Type_AsArray(arg0, arg1)
}

func Type_AsStruct(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Type_AsStruct(
		arg0,
		arg1,
	)
}

func zetasql_Type_AsStruct(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Type_AsStruct(arg0, arg1)
}

func Type_AsProto(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Type_AsProto(
		arg0,
		arg1,
	)
}

func zetasql_Type_AsProto(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Type_AsProto(arg0, arg1)
}

func Type_AsEnum(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Type_AsEnum(
		arg0,
		arg1,
	)
}

func zetasql_Type_AsEnum(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Type_AsEnum(arg0, arg1)
}

func Type_AsExtendedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Type_AsExtendedType(
		arg0,
		arg1,
	)
}

func zetasql_Type_AsExtendedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Type_AsExtendedType(arg0, arg1)
}

func Type_SupportsGrouping(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_SupportsGrouping(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_SupportsGrouping(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_SupportsGrouping(arg0, arg1)
}

func Type_SupportsPartitioning(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_SupportsPartitioning(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_SupportsPartitioning(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_SupportsPartitioning(arg0, arg1)
}

func Type_SupportsOrdering(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_SupportsOrdering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_SupportsOrdering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_SupportsOrdering(arg0, arg1)
}

func Type_SupportsEquality(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_SupportsEquality(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_SupportsEquality(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_SupportsEquality(arg0, arg1)
}

func Type_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_Type_Equals(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_Type_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_Type_Equals(arg0, arg1, arg2)
}

func Type_Equivalent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_Type_Equivalent(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_Type_Equivalent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_Type_Equivalent(arg0, arg1, arg2)
}

func Type_ShortTypeName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_Type_ShortTypeName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_Type_ShortTypeName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_Type_ShortTypeName(arg0, arg1, arg2)
}

func Type_TypeName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_Type_TypeName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_Type_TypeName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_Type_TypeName(arg0, arg1, arg2)
}

func Type_TypeNameWithParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	zetasql_Type_TypeNameWithParameters(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
		arg4,
	)
}

func zetasql_Type_TypeNameWithParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_zetasql_Type_TypeNameWithParameters(arg0, arg1, arg2, arg3, arg4)
}

func Type_DebugString(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_Type_DebugString(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_Type_DebugString(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_Type_DebugString(arg0, arg1, arg2)
}

func Type_HasAnyFields(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Type_HasAnyFields(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_HasAnyFields(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Type_HasAnyFields(arg0, arg1)
}

func Type_NestingDepth(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_Type_NestingDepth(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Type_NestingDepth(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_Type_NestingDepth(arg0, arg1)
}

func Type_ValidateAndResolveTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 int, arg4 *unsafe.Pointer, arg5 *unsafe.Pointer) {
	zetasql_Type_ValidateAndResolveTypeParameters(
		arg0,
		arg1,
		C.int(arg2),
		C.int(arg3),
		arg4,
		arg5,
	)
}

func zetasql_Type_ValidateAndResolveTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 C.int, arg4 *unsafe.Pointer, arg5 *unsafe.Pointer) {
	C.export_zetasql_Type_ValidateAndResolveTypeParameters(arg0, arg1, arg2, arg3, arg4, arg5)
}

func Type_ValidateResolvedTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	zetasql_Type_ValidateResolvedTypeParameters(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func zetasql_Type_ValidateResolvedTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_zetasql_Type_ValidateResolvedTypeParameters(arg0, arg1, arg2, arg3)
}

func ArrayType_element_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ArrayType_element_type(
		arg0,
		arg1,
	)
}

func zetasql_ArrayType_element_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ArrayType_element_type(arg0, arg1)
}

func StructType_num_fields(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_StructType_num_fields(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_StructType_num_fields(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_StructType_num_fields(arg0, arg1)
}

func StructType_field(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_StructType_field(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_StructType_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_StructType_field(arg0, arg1, arg2)
}

func StructType_fields(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_StructType_fields(
		arg0,
		arg1,
	)
}

func zetasql_StructType_fields(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_StructType_fields(arg0, arg1)
}

func StructField_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_StructField_new(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_StructField_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_StructField_new(arg0, arg1, arg2)
}

func StructField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_StructField_name(
		arg0,
		arg1,
	)
}

func zetasql_StructField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_StructField_name(arg0, arg1)
}

func StructField_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_StructField_type(
		arg0,
		arg1,
	)
}

func zetasql_StructField_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_StructField_type(arg0, arg1)
}

func TypeFactory_new(arg0 *unsafe.Pointer) {
	zetasql_TypeFactory_new(
		arg0,
	)
}

func zetasql_TypeFactory_new(arg0 *unsafe.Pointer) {
	C.export_zetasql_TypeFactory_new(arg0)
}

func TypeFactory_MakeArrayType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_TypeFactory_MakeArrayType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_TypeFactory_MakeArrayType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_TypeFactory_MakeArrayType(arg0, arg1, arg2, arg3)
}

func TypeFactory_MakeStructType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_TypeFactory_MakeStructType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_TypeFactory_MakeStructType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_TypeFactory_MakeStructType(arg0, arg1, arg2, arg3)
}

func Int32Type(arg0 *unsafe.Pointer) {
	zetasql_Int32Type(
		arg0,
	)
}

func zetasql_Int32Type(arg0 *unsafe.Pointer) {
	C.export_zetasql_Int32Type(arg0)
}

func Int64Type(arg0 *unsafe.Pointer) {
	zetasql_Int64Type(
		arg0,
	)
}

func zetasql_Int64Type(arg0 *unsafe.Pointer) {
	C.export_zetasql_Int64Type(arg0)
}

func Uint32Type(arg0 *unsafe.Pointer) {
	zetasql_Uint32Type(
		arg0,
	)
}

func zetasql_Uint32Type(arg0 *unsafe.Pointer) {
	C.export_zetasql_Uint32Type(arg0)
}

func Uint64Type(arg0 *unsafe.Pointer) {
	zetasql_Uint64Type(
		arg0,
	)
}

func zetasql_Uint64Type(arg0 *unsafe.Pointer) {
	C.export_zetasql_Uint64Type(arg0)
}

func BoolType(arg0 *unsafe.Pointer) {
	zetasql_BoolType(
		arg0,
	)
}

func zetasql_BoolType(arg0 *unsafe.Pointer) {
	C.export_zetasql_BoolType(arg0)
}

func FloatType(arg0 *unsafe.Pointer) {
	zetasql_FloatType(
		arg0,
	)
}

func zetasql_FloatType(arg0 *unsafe.Pointer) {
	C.export_zetasql_FloatType(arg0)
}

func DoubleType(arg0 *unsafe.Pointer) {
	zetasql_DoubleType(
		arg0,
	)
}

func zetasql_DoubleType(arg0 *unsafe.Pointer) {
	C.export_zetasql_DoubleType(arg0)
}

func StringType(arg0 *unsafe.Pointer) {
	zetasql_StringType(
		arg0,
	)
}

func zetasql_StringType(arg0 *unsafe.Pointer) {
	C.export_zetasql_StringType(arg0)
}

func BytesType(arg0 *unsafe.Pointer) {
	zetasql_BytesType(
		arg0,
	)
}

func zetasql_BytesType(arg0 *unsafe.Pointer) {
	C.export_zetasql_BytesType(arg0)
}

func DateType(arg0 *unsafe.Pointer) {
	zetasql_DateType(
		arg0,
	)
}

func zetasql_DateType(arg0 *unsafe.Pointer) {
	C.export_zetasql_DateType(arg0)
}

func TimestampType(arg0 *unsafe.Pointer) {
	zetasql_TimestampType(
		arg0,
	)
}

func zetasql_TimestampType(arg0 *unsafe.Pointer) {
	C.export_zetasql_TimestampType(arg0)
}

func TimeType(arg0 *unsafe.Pointer) {
	zetasql_TimeType(
		arg0,
	)
}

func zetasql_TimeType(arg0 *unsafe.Pointer) {
	C.export_zetasql_TimeType(arg0)
}

func DatetimeType(arg0 *unsafe.Pointer) {
	zetasql_DatetimeType(
		arg0,
	)
}

func zetasql_DatetimeType(arg0 *unsafe.Pointer) {
	C.export_zetasql_DatetimeType(arg0)
}

func IntervalType(arg0 *unsafe.Pointer) {
	zetasql_IntervalType(
		arg0,
	)
}

func zetasql_IntervalType(arg0 *unsafe.Pointer) {
	C.export_zetasql_IntervalType(arg0)
}

func GeographyType(arg0 *unsafe.Pointer) {
	zetasql_GeographyType(
		arg0,
	)
}

func zetasql_GeographyType(arg0 *unsafe.Pointer) {
	C.export_zetasql_GeographyType(arg0)
}

func NumericType(arg0 *unsafe.Pointer) {
	zetasql_NumericType(
		arg0,
	)
}

func zetasql_NumericType(arg0 *unsafe.Pointer) {
	C.export_zetasql_NumericType(arg0)
}

func BigNumericType(arg0 *unsafe.Pointer) {
	zetasql_BigNumericType(
		arg0,
	)
}

func zetasql_BigNumericType(arg0 *unsafe.Pointer) {
	C.export_zetasql_BigNumericType(arg0)
}

func JsonType(arg0 *unsafe.Pointer) {
	zetasql_JsonType(
		arg0,
	)
}

func zetasql_JsonType(arg0 *unsafe.Pointer) {
	C.export_zetasql_JsonType(arg0)
}

func EmptyStructType(arg0 *unsafe.Pointer) {
	zetasql_EmptyStructType(
		arg0,
	)
}

func zetasql_EmptyStructType(arg0 *unsafe.Pointer) {
	C.export_zetasql_EmptyStructType(arg0)
}

func Int32ArrayType(arg0 *unsafe.Pointer) {
	zetasql_Int32ArrayType(
		arg0,
	)
}

func zetasql_Int32ArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_Int32ArrayType(arg0)
}

func Int64ArrayType(arg0 *unsafe.Pointer) {
	zetasql_Int64ArrayType(
		arg0,
	)
}

func zetasql_Int64ArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_Int64ArrayType(arg0)
}

func Uint32ArrayType(arg0 *unsafe.Pointer) {
	zetasql_Uint32ArrayType(
		arg0,
	)
}

func zetasql_Uint32ArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_Uint32ArrayType(arg0)
}

func Uint64ArrayType(arg0 *unsafe.Pointer) {
	zetasql_Uint64ArrayType(
		arg0,
	)
}

func zetasql_Uint64ArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_Uint64ArrayType(arg0)
}

func BoolArrayType(arg0 *unsafe.Pointer) {
	zetasql_BoolArrayType(
		arg0,
	)
}

func zetasql_BoolArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_BoolArrayType(arg0)
}

func FloatArrayType(arg0 *unsafe.Pointer) {
	zetasql_FloatArrayType(
		arg0,
	)
}

func zetasql_FloatArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_FloatArrayType(arg0)
}

func DoubleArrayType(arg0 *unsafe.Pointer) {
	zetasql_DoubleArrayType(
		arg0,
	)
}

func zetasql_DoubleArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_DoubleArrayType(arg0)
}

func StringArrayType(arg0 *unsafe.Pointer) {
	zetasql_StringArrayType(
		arg0,
	)
}

func zetasql_StringArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_StringArrayType(arg0)
}

func BytesArrayType(arg0 *unsafe.Pointer) {
	zetasql_BytesArrayType(
		arg0,
	)
}

func zetasql_BytesArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_BytesArrayType(arg0)
}

func TimestampArrayType(arg0 *unsafe.Pointer) {
	zetasql_TimestampArrayType(
		arg0,
	)
}

func zetasql_TimestampArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_TimestampArrayType(arg0)
}

func DateArrayType(arg0 *unsafe.Pointer) {
	zetasql_DateArrayType(
		arg0,
	)
}

func zetasql_DateArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_DateArrayType(arg0)
}

func DatetimeArrayType(arg0 *unsafe.Pointer) {
	zetasql_DatetimeArrayType(
		arg0,
	)
}

func zetasql_DatetimeArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_DatetimeArrayType(arg0)
}

func TimeArrayType(arg0 *unsafe.Pointer) {
	zetasql_TimeArrayType(
		arg0,
	)
}

func zetasql_TimeArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_TimeArrayType(arg0)
}

func IntervalArrayType(arg0 *unsafe.Pointer) {
	zetasql_IntervalArrayType(
		arg0,
	)
}

func zetasql_IntervalArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_IntervalArrayType(arg0)
}

func GeographyArrayType(arg0 *unsafe.Pointer) {
	zetasql_GeographyArrayType(
		arg0,
	)
}

func zetasql_GeographyArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_GeographyArrayType(arg0)
}

func NumericArrayType(arg0 *unsafe.Pointer) {
	zetasql_NumericArrayType(
		arg0,
	)
}

func zetasql_NumericArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_NumericArrayType(arg0)
}

func BigNumericArrayType(arg0 *unsafe.Pointer) {
	zetasql_BigNumericArrayType(
		arg0,
	)
}

func zetasql_BigNumericArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_BigNumericArrayType(arg0)
}

func JsonArrayType(arg0 *unsafe.Pointer) {
	zetasql_JsonArrayType(
		arg0,
	)
}

func zetasql_JsonArrayType(arg0 *unsafe.Pointer) {
	C.export_zetasql_JsonArrayType(arg0)
}

func DatePartEnumType(arg0 *unsafe.Pointer) {
	zetasql_DatePartEnumType(
		arg0,
	)
}

func zetasql_DatePartEnumType(arg0 *unsafe.Pointer) {
	C.export_zetasql_DatePartEnumType(arg0)
}

func NormalizeModeEnumType(arg0 *unsafe.Pointer) {
	zetasql_NormalizeModeEnumType(
		arg0,
	)
}

func zetasql_NormalizeModeEnumType(arg0 *unsafe.Pointer) {
	C.export_zetasql_NormalizeModeEnumType(arg0)
}

func TypeFromSimpleTypeKind(arg0 int, arg1 *unsafe.Pointer) {
	zetasql_TypeFromSimpleTypeKind(
		C.int(arg0),
		arg1,
	)
}

func zetasql_TypeFromSimpleTypeKind(arg0 C.int, arg1 *unsafe.Pointer) {
	C.export_zetasql_TypeFromSimpleTypeKind(arg0, arg1)
}

func Value_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Value_type(
		arg0,
		arg1,
	)
}

func zetasql_Value_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Value_type(arg0, arg1)
}

func Value_type_kind(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_Value_type_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_type_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_Value_type_kind(arg0, arg1)
}

func Value_physical_byte_size(arg0 unsafe.Pointer, arg1 *uint64) {
	zetasql_Value_physical_byte_size(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_physical_byte_size(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_zetasql_Value_physical_byte_size(arg0, arg1)
}

func Value_is_null(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Value_is_null(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_is_null(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Value_is_null(arg0, arg1)
}

func Value_is_empty_array(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Value_is_empty_array(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_is_empty_array(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Value_is_empty_array(arg0, arg1)
}

func Value_is_valid(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Value_is_valid(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_is_valid(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Value_is_valid(arg0, arg1)
}

func Value_has_content(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Value_has_content(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_has_content(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Value_has_content(arg0, arg1)
}

func Value_int32_value(arg0 unsafe.Pointer, arg1 *int32) {
	zetasql_Value_int32_value(
		arg0,
		(*C.int32_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_int32_value(arg0 unsafe.Pointer, arg1 *C.int32_t) {
	C.export_zetasql_Value_int32_value(arg0, arg1)
}

func Value_int64_value(arg0 unsafe.Pointer, arg1 *int64) {
	zetasql_Value_int64_value(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_int64_value(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_Value_int64_value(arg0, arg1)
}

func Value_uint32_value(arg0 unsafe.Pointer, arg1 *uint32) {
	zetasql_Value_uint32_value(
		arg0,
		(*C.uint32_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_uint32_value(arg0 unsafe.Pointer, arg1 *C.uint32_t) {
	C.export_zetasql_Value_uint32_value(arg0, arg1)
}

func Value_uint64_value(arg0 unsafe.Pointer, arg1 *uint64) {
	zetasql_Value_uint64_value(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_uint64_value(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_zetasql_Value_uint64_value(arg0, arg1)
}

func Value_bool_value(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Value_bool_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_bool_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Value_bool_value(arg0, arg1)
}

func Value_float_value(arg0 unsafe.Pointer, arg1 *float32) {
	zetasql_Value_float_value(
		arg0,
		(*C.float)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_float_value(arg0 unsafe.Pointer, arg1 *C.float) {
	C.export_zetasql_Value_float_value(arg0, arg1)
}

func Value_double_value(arg0 unsafe.Pointer, arg1 *float64) {
	zetasql_Value_double_value(
		arg0,
		(*C.double)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_double_value(arg0 unsafe.Pointer, arg1 *C.double) {
	C.export_zetasql_Value_double_value(arg0, arg1)
}

func Value_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Value_string_value(
		arg0,
		arg1,
	)
}

func zetasql_Value_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Value_string_value(arg0, arg1)
}

func Value_bytes_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Value_bytes_value(
		arg0,
		arg1,
	)
}

func zetasql_Value_bytes_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Value_bytes_value(arg0, arg1)
}

func Value_date_value(arg0 unsafe.Pointer, arg1 *int32) {
	zetasql_Value_date_value(
		arg0,
		(*C.int32_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_date_value(arg0 unsafe.Pointer, arg1 *C.int32_t) {
	C.export_zetasql_Value_date_value(arg0, arg1)
}

func Value_enum_value(arg0 unsafe.Pointer, arg1 *int32) {
	zetasql_Value_enum_value(
		arg0,
		(*C.int32_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_enum_value(arg0 unsafe.Pointer, arg1 *C.int32_t) {
	C.export_zetasql_Value_enum_value(arg0, arg1)
}

func Value_enum_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Value_enum_name(
		arg0,
		arg1,
	)
}

func zetasql_Value_enum_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Value_enum_name(arg0, arg1)
}

func Value_ToTime(arg0 unsafe.Pointer, arg1 *int64) {
	zetasql_Value_ToTime(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_ToTime(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_Value_ToTime(arg0, arg1)
}

func Value_ToUnixMicros(arg0 unsafe.Pointer, arg1 *int64) {
	zetasql_Value_ToUnixMicros(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_ToUnixMicros(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_Value_ToUnixMicros(arg0, arg1)
}

func Value_ToUnixNanos(arg0 unsafe.Pointer, arg1 *int64, arg2 *unsafe.Pointer) {
	zetasql_Value_ToUnixNanos(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
		arg2,
	)
}

func zetasql_Value_ToUnixNanos(arg0 unsafe.Pointer, arg1 *C.int64_t, arg2 *unsafe.Pointer) {
	C.export_zetasql_Value_ToUnixNanos(arg0, arg1, arg2)
}

func Value_ToPacked64TimeMicros(arg0 unsafe.Pointer, arg1 *int64) {
	zetasql_Value_ToPacked64TimeMicros(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_ToPacked64TimeMicros(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_Value_ToPacked64TimeMicros(arg0, arg1)
}

func Value_ToPacked64DatetimeMicros(arg0 unsafe.Pointer, arg1 *int64) {
	zetasql_Value_ToPacked64DatetimeMicros(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_ToPacked64DatetimeMicros(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_Value_ToPacked64DatetimeMicros(arg0, arg1)
}

func Value_is_validated_json(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Value_is_validated_json(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_is_validated_json(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Value_is_validated_json(arg0, arg1)
}

func Value_is_unparsed_json(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Value_is_unparsed_json(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_is_unparsed_json(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Value_is_unparsed_json(arg0, arg1)
}

func Value_json_value_unparsed(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Value_json_value_unparsed(
		arg0,
		arg1,
	)
}

func zetasql_Value_json_value_unparsed(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Value_json_value_unparsed(arg0, arg1)
}

func Value_json_string(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Value_json_string(
		arg0,
		arg1,
	)
}

func zetasql_Value_json_string(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Value_json_string(arg0, arg1)
}

func Value_ToInt64(arg0 unsafe.Pointer, arg1 *int64) {
	zetasql_Value_ToInt64(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_ToInt64(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_Value_ToInt64(arg0, arg1)
}

func Value_ToUint64(arg0 unsafe.Pointer, arg1 *uint64) {
	zetasql_Value_ToUint64(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_ToUint64(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_zetasql_Value_ToUint64(arg0, arg1)
}

func Value_ToDouble(arg0 unsafe.Pointer, arg1 *float64) {
	zetasql_Value_ToDouble(
		arg0,
		(*C.double)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_ToDouble(arg0 unsafe.Pointer, arg1 *C.double) {
	C.export_zetasql_Value_ToDouble(arg0, arg1)
}

func Value_num_fields(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_Value_num_fields(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_num_fields(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_Value_num_fields(arg0, arg1)
}

func Value_field(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_Value_field(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_Value_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_Value_field(arg0, arg1, arg2)
}

func Value_FindFieldByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_Value_FindFieldByName(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_Value_FindFieldByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_Value_FindFieldByName(arg0, arg1, arg2)
}

func Value_empty(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Value_empty(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_empty(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Value_empty(arg0, arg1)
}

func Value_num_elements(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_Value_num_elements(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_num_elements(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_Value_num_elements(arg0, arg1)
}

func Value_element(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_Value_element(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_Value_element(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_Value_element(arg0, arg1, arg2)
}

func Value_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_Value_Equals(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_Value_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_Value_Equals(arg0, arg1, arg2)
}

func Value_SqlEquals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_Value_SqlEquals(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_Value_SqlEquals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_Value_SqlEquals(arg0, arg1, arg2)
}

func Value_LessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_Value_LessThan(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_Value_LessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_Value_LessThan(arg0, arg1, arg2)
}

func Value_SqlLessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_Value_SqlLessThan(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_Value_SqlLessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_Value_SqlLessThan(arg0, arg1, arg2)
}

func Value_HashCode(arg0 unsafe.Pointer, arg1 *uint64) {
	zetasql_Value_HashCode(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Value_HashCode(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_zetasql_Value_HashCode(arg0, arg1)
}

func Value_ShortDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Value_ShortDebugString(
		arg0,
		arg1,
	)
}

func zetasql_Value_ShortDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Value_ShortDebugString(arg0, arg1)
}

func Value_FullDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Value_FullDebugString(
		arg0,
		arg1,
	)
}

func zetasql_Value_FullDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Value_FullDebugString(arg0, arg1)
}

func Value_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Value_DebugString(
		arg0,
		arg1,
	)
}

func zetasql_Value_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Value_DebugString(arg0, arg1)
}

func Value_Format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Value_Format(
		arg0,
		arg1,
	)
}

func zetasql_Value_Format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Value_Format(arg0, arg1)
}

func Value_GetSQL(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_Value_GetSQL(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_Value_GetSQL(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_Value_GetSQL(arg0, arg1, arg2)
}

func Value_GetSQLLiteral(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_Value_GetSQLLiteral(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_Value_GetSQLLiteral(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_Value_GetSQLLiteral(arg0, arg1, arg2)
}

func Int64(arg0 int64, arg1 *unsafe.Pointer) {
	zetasql_Int64(
		C.int64_t(arg0),
		arg1,
	)
}

func zetasql_Int64(arg0 C.int64_t, arg1 *unsafe.Pointer) {
	C.export_zetasql_Int64(arg0, arg1)
}

func Column_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Column_Name(
		arg0,
		arg1,
	)
}

func zetasql_Column_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Column_Name(arg0, arg1)
}

func Column_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Column_FullName(
		arg0,
		arg1,
	)
}

func zetasql_Column_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Column_FullName(arg0, arg1)
}

func Column_Type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Column_Type(
		arg0,
		arg1,
	)
}

func zetasql_Column_Type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Column_Type(arg0, arg1)
}

func Column_IsPseudoColumn(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Column_IsPseudoColumn(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Column_IsPseudoColumn(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Column_IsPseudoColumn(arg0, arg1)
}

func Column_IsWritableColumn(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Column_IsWritableColumn(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Column_IsWritableColumn(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Column_IsWritableColumn(arg0, arg1)
}

func SimpleColumn_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_SimpleColumn_new(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_SimpleColumn_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_SimpleColumn_new(arg0, arg1, arg2, arg3)
}

func SimpleColumn_new_with_opt(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 int, arg4 int, arg5 *unsafe.Pointer) {
	zetasql_SimpleColumn_new_with_opt(
		arg0,
		arg1,
		arg2,
		C.int(arg3),
		C.int(arg4),
		arg5,
	)
}

func zetasql_SimpleColumn_new_with_opt(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 C.int, arg4 C.int, arg5 *unsafe.Pointer) {
	C.export_zetasql_SimpleColumn_new_with_opt(arg0, arg1, arg2, arg3, arg4, arg5)
}

func SimpleColumn_AnnotatedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_SimpleColumn_AnnotatedType(
		arg0,
		arg1,
	)
}

func zetasql_SimpleColumn_AnnotatedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_SimpleColumn_AnnotatedType(arg0, arg1)
}

func SimpleColumn_SetIsPseudoColumn(arg0 unsafe.Pointer, arg1 int) {
	zetasql_SimpleColumn_SetIsPseudoColumn(
		arg0,
		C.int(arg1),
	)
}

func zetasql_SimpleColumn_SetIsPseudoColumn(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_SimpleColumn_SetIsPseudoColumn(arg0, arg1)
}

func Table_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Table_Name(
		arg0,
		arg1,
	)
}

func zetasql_Table_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Table_Name(arg0, arg1)
}

func Table_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Table_FullName(
		arg0,
		arg1,
	)
}

func zetasql_Table_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Table_FullName(arg0, arg1)
}

func Table_NumColumns(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_Table_NumColumns(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Table_NumColumns(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_Table_NumColumns(arg0, arg1)
}

func Table_Column(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_Table_Column(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_Table_Column(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_Table_Column(arg0, arg1, arg2)
}

func Table_PrimaryKey_num(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_Table_PrimaryKey_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Table_PrimaryKey_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_Table_PrimaryKey_num(arg0, arg1)
}

func Table_PrimaryKey(arg0 unsafe.Pointer, arg1 int, arg2 *int) {
	zetasql_Table_PrimaryKey(
		arg0,
		C.int(arg1),
		(*C.int)(unsafe.Pointer(arg2)),
	)
}

func zetasql_Table_PrimaryKey(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.int) {
	C.export_zetasql_Table_PrimaryKey(arg0, arg1, arg2)
}

func Table_FindColumnByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_Table_FindColumnByName(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_Table_FindColumnByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_Table_FindColumnByName(arg0, arg1, arg2)
}

func Table_IsValueTable(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Table_IsValueTable(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Table_IsValueTable(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Table_IsValueTable(arg0, arg1)
}

func Table_GetSerializationId(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_Table_GetSerializationId(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Table_GetSerializationId(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_Table_GetSerializationId(arg0, arg1)
}

func Table_CreateEvaluatorTableIterator(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	zetasql_Table_CreateEvaluatorTableIterator(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
		arg4,
	)
}

func zetasql_Table_CreateEvaluatorTableIterator(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_zetasql_Table_CreateEvaluatorTableIterator(arg0, arg1, arg2, arg3, arg4)
}

func Table_GetAnonymizationInfo(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Table_GetAnonymizationInfo(
		arg0,
		arg1,
	)
}

func zetasql_Table_GetAnonymizationInfo(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Table_GetAnonymizationInfo(arg0, arg1)
}

func Table_SupportsAnonymization(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Table_SupportsAnonymization(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Table_SupportsAnonymization(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Table_SupportsAnonymization(arg0, arg1)
}

func Table_GetTableTypeName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_Table_GetTableTypeName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_Table_GetTableTypeName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_Table_GetTableTypeName(arg0, arg1, arg2)
}

func SimpleTable_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	zetasql_SimpleTable_new(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func zetasql_SimpleTable_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_zetasql_SimpleTable_new(arg0, arg1, arg2, arg3)
}

func SimpleTable_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	zetasql_SimpleTable_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func zetasql_SimpleTable_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_SimpleTable_set_is_value_table(arg0, arg1)
}

func SimpleTable_AllowAnonymousColumnName(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_SimpleTable_AllowAnonymousColumnName(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_SimpleTable_AllowAnonymousColumnName(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_SimpleTable_AllowAnonymousColumnName(arg0, arg1)
}

func SimpleTable_set_allow_anonymous_column_name(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_SimpleTable_set_allow_anonymous_column_name(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_SimpleTable_set_allow_anonymous_column_name(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_SimpleTable_set_allow_anonymous_column_name(arg0, arg1, arg2)
}

func SimpleTable_AllowDuplicateColumnNames(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_SimpleTable_AllowDuplicateColumnNames(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_SimpleTable_AllowDuplicateColumnNames(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_SimpleTable_AllowDuplicateColumnNames(arg0, arg1)
}

func SimpleTable_set_allow_duplicate_column_names(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_SimpleTable_set_allow_duplicate_column_names(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_SimpleTable_set_allow_duplicate_column_names(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_SimpleTable_set_allow_duplicate_column_names(arg0, arg1, arg2)
}

func SimpleTable_AddColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_SimpleTable_AddColumn(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleTable_AddColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_SimpleTable_AddColumn(arg0, arg1, arg2)
}

func SimpleTable_SetPrimaryKey(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	zetasql_SimpleTable_SetPrimaryKey(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func zetasql_SimpleTable_SetPrimaryKey(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_zetasql_SimpleTable_SetPrimaryKey(arg0, arg1, arg2, arg3)
}

func SimpleTable_set_full_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_SimpleTable_set_full_name(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleTable_set_full_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_SimpleTable_set_full_name(arg0, arg1, arg2)
}

func SimpleTable_SetAnonymizationInfo(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_SimpleTable_SetAnonymizationInfo(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleTable_SetAnonymizationInfo(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_SimpleTable_SetAnonymizationInfo(arg0, arg1, arg2)
}

func SimpleTable_ResetAnonymizationInfo(arg0 unsafe.Pointer) {
	zetasql_SimpleTable_ResetAnonymizationInfo(
		arg0,
	)
}

func zetasql_SimpleTable_ResetAnonymizationInfo(arg0 unsafe.Pointer) {
	C.export_zetasql_SimpleTable_ResetAnonymizationInfo(arg0)
}

func Catalog_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Catalog_FullName(
		arg0,
		arg1,
	)
}

func zetasql_Catalog_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Catalog_FullName(arg0, arg1)
}

func Catalog_FindTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_Catalog_FindTable(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_Catalog_FindTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_Catalog_FindTable(arg0, arg1, arg2, arg3)
}

func Catalog_FindModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_Catalog_FindModel(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_Catalog_FindModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_Catalog_FindModel(arg0, arg1, arg2, arg3)
}

func Catalog_FindFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_Catalog_FindFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_Catalog_FindFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_Catalog_FindFunction(arg0, arg1, arg2, arg3)
}

func Catalog_FindTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_Catalog_FindTableValuedFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_Catalog_FindTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_Catalog_FindTableValuedFunction(arg0, arg1, arg2, arg3)
}

func Catalog_FindProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_Catalog_FindProcedure(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_Catalog_FindProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_Catalog_FindProcedure(arg0, arg1, arg2, arg3)
}

func Catalog_FindType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_Catalog_FindType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_Catalog_FindType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_Catalog_FindType(arg0, arg1, arg2, arg3)
}

func Catalog_FindConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *int, arg4 *unsafe.Pointer) {
	zetasql_Catalog_FindConstant(
		arg0,
		arg1,
		arg2,
		(*C.int)(unsafe.Pointer(arg3)),
		arg4,
	)
}

func zetasql_Catalog_FindConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *C.int, arg4 *unsafe.Pointer) {
	C.export_zetasql_Catalog_FindConstant(arg0, arg1, arg2, arg3, arg4)
}

func Catalog_SuggestTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_Catalog_SuggestTable(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_Catalog_SuggestTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_Catalog_SuggestTable(arg0, arg1, arg2)
}

func Catalog_SuggestModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_Catalog_SuggestModel(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_Catalog_SuggestModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_Catalog_SuggestModel(arg0, arg1, arg2)
}

func Catalog_SuggestFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_Catalog_SuggestFunction(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_Catalog_SuggestFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_Catalog_SuggestFunction(arg0, arg1, arg2)
}

func Catalog_SuggestTableValuedTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_Catalog_SuggestTableValuedTable(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_Catalog_SuggestTableValuedTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_Catalog_SuggestTableValuedTable(arg0, arg1, arg2)
}

func Catalog_SuggestConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_Catalog_SuggestConstant(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_Catalog_SuggestConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_Catalog_SuggestConstant(arg0, arg1, arg2)
}

func EnumerableCatalog_Catalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_EnumerableCatalog_Catalogs(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_EnumerableCatalog_Catalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_EnumerableCatalog_Catalogs(arg0, arg1, arg2)
}

func EnumerableCatalog_Tables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_EnumerableCatalog_Tables(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_EnumerableCatalog_Tables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_EnumerableCatalog_Tables(arg0, arg1, arg2)
}

func EnumerableCatalog_Types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_EnumerableCatalog_Types(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_EnumerableCatalog_Types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_EnumerableCatalog_Types(arg0, arg1, arg2)
}

func EnumerableCatalog_Functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_EnumerableCatalog_Functions(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_EnumerableCatalog_Functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_EnumerableCatalog_Functions(arg0, arg1, arg2)
}

func SimpleCatalog_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_SimpleCatalog_new(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_new(arg0, arg1)
}

func SimpleCatalog_GetTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_SimpleCatalog_GetTable(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_SimpleCatalog_GetTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_GetTable(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetTables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_SimpleCatalog_GetTables(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleCatalog_GetTables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_GetTables(arg0, arg1, arg2)
}

func SimpleCatalog_table_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_SimpleCatalog_table_names(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_table_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_table_names(arg0, arg1)
}

func SimpleCatalog_GetModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_SimpleCatalog_GetModel(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_SimpleCatalog_GetModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_GetModel(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_SimpleCatalog_GetFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_SimpleCatalog_GetFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_GetFunction(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetFunctions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_SimpleCatalog_GetFunctions(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleCatalog_GetFunctions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_GetFunctions(arg0, arg1, arg2)
}

func SimpleCatalog_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_SimpleCatalog_function_names(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_function_names(arg0, arg1)
}

func SimpleCatalog_GetTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_SimpleCatalog_GetTableValuedFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_SimpleCatalog_GetTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_GetTableValuedFunction(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_table_valued_functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_SimpleCatalog_table_valued_functions(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_table_valued_functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_table_valued_functions(arg0, arg1)
}

func SimpleCatalog_table_valued_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_SimpleCatalog_table_valued_function_names(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_table_valued_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_table_valued_function_names(arg0, arg1)
}

func SimpleCatalog_GetProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_SimpleCatalog_GetProcedure(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_SimpleCatalog_GetProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_GetProcedure(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_procedures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_SimpleCatalog_procedures(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_procedures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_procedures(arg0, arg1)
}

func SimpleCatalog_GetType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_SimpleCatalog_GetType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_SimpleCatalog_GetType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_GetType(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetTypes(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_SimpleCatalog_GetTypes(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleCatalog_GetTypes(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_GetTypes(arg0, arg1, arg2)
}

func SimpleCatalog_GetCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_SimpleCatalog_GetCatalog(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_SimpleCatalog_GetCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_GetCatalog(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetCatalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_SimpleCatalog_GetCatalogs(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleCatalog_GetCatalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_GetCatalogs(arg0, arg1, arg2)
}

func SimpleCatalog_catalog_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_SimpleCatalog_catalog_names(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_catalog_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_catalog_names(arg0, arg1)
}

func SimpleCatalog_AddTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddTable(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_AddTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddTable(arg0, arg1)
}

func SimpleCatalog_AddTableWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddTableWithName(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleCatalog_AddTableWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddTableWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddModel(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_AddModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddModel(arg0, arg1)
}

func SimpleCatalog_AddModelWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddModelWithName(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleCatalog_AddModelWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddModelWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddConnection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddConnection(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_AddConnection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddConnection(arg0, arg1)
}

func SimpleCatalog_AddConnectionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddConnectionWithName(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleCatalog_AddConnectionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddConnectionWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddType(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleCatalog_AddType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddType(arg0, arg1, arg2)
}

func SimpleCatalog_AddTypeIfNotPresent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	zetasql_SimpleCatalog_AddTypeIfNotPresent(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func zetasql_SimpleCatalog_AddTypeIfNotPresent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
	C.export_zetasql_SimpleCatalog_AddTypeIfNotPresent(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_AddCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddCatalog(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_AddCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddCatalog(arg0, arg1)
}

func SimpleCatalog_AddCatalogWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddCatalogWithName(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleCatalog_AddCatalogWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddCatalogWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddFunction(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_AddFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddFunction(arg0, arg1)
}

func SimpleCatalog_AddFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddFunctionWithName(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleCatalog_AddFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddFunctionWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddTableValuedFunction(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_AddTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddTableValuedFunction(arg0, arg1)
}

func SimpleCatalog_AddTableValuedFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddTableValuedFunctionWithName(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleCatalog_AddTableValuedFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddTableValuedFunctionWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddProcedure(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_AddProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddProcedure(arg0, arg1)
}

func SimpleCatalog_AddProcedureWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddProcedureWithName(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleCatalog_AddProcedureWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddProcedureWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddConstant(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_AddConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddConstant(arg0, arg1)
}

func SimpleCatalog_AddConstantWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddConstantWithName(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleCatalog_AddConstantWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddConstantWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddZetaSQLFunctions(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_SimpleCatalog_AddZetaSQLFunctions(
		arg0,
		arg1,
	)
}

func zetasql_SimpleCatalog_AddZetaSQLFunctions(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_SimpleCatalog_AddZetaSQLFunctions(arg0, arg1)
}

func Constant_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Constant_Name(
		arg0,
		arg1,
	)
}

func zetasql_Constant_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Constant_Name(arg0, arg1)
}

func Constant_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Constant_FullName(
		arg0,
		arg1,
	)
}

func zetasql_Constant_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Constant_FullName(arg0, arg1)
}

func Constant_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Constant_type(
		arg0,
		arg1,
	)
}

func zetasql_Constant_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Constant_type(arg0, arg1)
}

func Constant_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Constant_DebugString(
		arg0,
		arg1,
	)
}

func zetasql_Constant_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Constant_DebugString(arg0, arg1)
}

func Constant_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Constant_name_path(
		arg0,
		arg1,
	)
}

func zetasql_Constant_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Constant_name_path(arg0, arg1)
}

func Model_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Model_Name(
		arg0,
		arg1,
	)
}

func zetasql_Model_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Model_Name(arg0, arg1)
}

func Model_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Model_FullName(
		arg0,
		arg1,
	)
}

func zetasql_Model_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Model_FullName(arg0, arg1)
}

func Model_NumInputs(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_Model_NumInputs(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Model_NumInputs(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_Model_NumInputs(arg0, arg1)
}

func Model_Input(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_Model_Input(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_Model_Input(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_Model_Input(arg0, arg1, arg2)
}

func Model_NumOutputs(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_Model_NumOutputs(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Model_NumOutputs(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_Model_NumOutputs(arg0, arg1)
}

func Model_Output(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_Model_Output(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_Model_Output(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_Model_Output(arg0, arg1, arg2)
}

func Model_FindInputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_Model_FindInputByName(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_Model_FindInputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_Model_FindInputByName(arg0, arg1, arg2)
}

func Model_FindOutputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_Model_FindOutputByName(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_Model_FindOutputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_Model_FindOutputByName(arg0, arg1, arg2)
}

func Model_SerializationID(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_Model_SerializationID(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Model_SerializationID(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_Model_SerializationID(arg0, arg1)
}

func SimpleModel_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_SimpleModel_new(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_SimpleModel_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_SimpleModel_new(arg0, arg1, arg2, arg3)
}

func SimpleModel_AddInput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_SimpleModel_AddInput(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleModel_AddInput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_SimpleModel_AddInput(arg0, arg1, arg2)
}

func SimpleModel_AddOutput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_SimpleModel_AddOutput(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SimpleModel_AddOutput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_SimpleModel_AddOutput(arg0, arg1, arg2)
}

func BuiltinFunctionOptions_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_BuiltinFunctionOptions_new(
		arg0,
		arg1,
	)
}

func zetasql_BuiltinFunctionOptions_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_BuiltinFunctionOptions_new(arg0, arg1)
}

func Function_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 unsafe.Pointer, arg4 *unsafe.Pointer) {
	zetasql_Function_new(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
		arg4,
	)
}

func zetasql_Function_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_zetasql_Function_new(arg0, arg1, arg2, arg3, arg4)
}

func Function_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Function_Name(
		arg0,
		arg1,
	)
}

func zetasql_Function_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Function_Name(arg0, arg1)
}

func Function_FunctionNamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Function_FunctionNamePath(
		arg0,
		arg1,
	)
}

func zetasql_Function_FunctionNamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Function_FunctionNamePath(arg0, arg1)
}

func Function_FullName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_Function_FullName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_Function_FullName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_Function_FullName(arg0, arg1, arg2)
}

func Function_SQLName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Function_SQLName(
		arg0,
		arg1,
	)
}

func zetasql_Function_SQLName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Function_SQLName(arg0, arg1)
}

func Function_QualifiedSQLName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_Function_QualifiedSQLName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_Function_QualifiedSQLName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_Function_QualifiedSQLName(arg0, arg1, arg2)
}

func Function_Group(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Function_Group(
		arg0,
		arg1,
	)
}

func zetasql_Function_Group(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Function_Group(arg0, arg1)
}

func Function_IsZetaSQLBuiltin(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_IsZetaSQLBuiltin(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_IsZetaSQLBuiltin(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_IsZetaSQLBuiltin(arg0, arg1)
}

func Function_ArgumentsAreCoercible(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_ArgumentsAreCoercible(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_ArgumentsAreCoercible(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_ArgumentsAreCoercible(arg0, arg1)
}

func Function_NumSignatures(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_Function_NumSignatures(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_NumSignatures(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_Function_NumSignatures(arg0, arg1)
}

func Function_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Function_signatures(
		arg0,
		arg1,
	)
}

func zetasql_Function_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Function_signatures(arg0, arg1)
}

func Function_ResetSignatures(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_Function_ResetSignatures(
		arg0,
		arg1,
	)
}

func zetasql_Function_ResetSignatures(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_Function_ResetSignatures(arg0, arg1)
}

func Function_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_Function_AddSignature(
		arg0,
		arg1,
	)
}

func zetasql_Function_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_Function_AddSignature(arg0, arg1)
}

func Function_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_Function_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_Function_mode(arg0, arg1)
}

func Function_IsScalar(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_IsScalar(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_IsScalar(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_IsScalar(arg0, arg1)
}

func Function_IsAggregate(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_IsAggregate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_IsAggregate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_IsAggregate(arg0, arg1)
}

func Function_IsAnalytic(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_IsAnalytic(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_IsAnalytic(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_IsAnalytic(arg0, arg1)
}

func Function_DebugString(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_Function_DebugString(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_Function_DebugString(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_Function_DebugString(arg0, arg1, arg2)
}

func Function_GetSQL(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	zetasql_Function_GetSQL(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func zetasql_Function_GetSQL(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_Function_GetSQL(arg0, arg1, arg2, arg3)
}

func Function_SupportsOverClause(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_SupportsOverClause(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_SupportsOverClause(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_SupportsOverClause(arg0, arg1)
}

func Function_SupportsWindowOrdering(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_SupportsWindowOrdering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_SupportsWindowOrdering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_SupportsWindowOrdering(arg0, arg1)
}

func Function_RequiresWindowOrdering(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_RequiresWindowOrdering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_RequiresWindowOrdering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_RequiresWindowOrdering(arg0, arg1)
}

func Function_SupportsWindowFraming(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_SupportsWindowFraming(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_SupportsWindowFraming(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_SupportsWindowFraming(arg0, arg1)
}

func Function_SupportsOrderingArguments(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_SupportsOrderingArguments(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_SupportsOrderingArguments(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_SupportsOrderingArguments(arg0, arg1)
}

func Function_SupportsLimitArguments(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_SupportsLimitArguments(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_SupportsLimitArguments(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_SupportsLimitArguments(arg0, arg1)
}

func Function_SupportsNullHandlingModifier(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_SupportsNullHandlingModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_SupportsNullHandlingModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_SupportsNullHandlingModifier(arg0, arg1)
}

func Function_SupportsSafeErrorMode(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_SupportsSafeErrorMode(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_SupportsSafeErrorMode(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_SupportsSafeErrorMode(arg0, arg1)
}

func Function_SupportsHavingModifier(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_SupportsHavingModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_SupportsHavingModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_SupportsHavingModifier(arg0, arg1)
}

func Function_SupportsDistinctModifier(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_SupportsDistinctModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_SupportsDistinctModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_SupportsDistinctModifier(arg0, arg1)
}

func Function_SupportsClampedBetweenModifier(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_SupportsClampedBetweenModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_SupportsClampedBetweenModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_SupportsClampedBetweenModifier(arg0, arg1)
}

func Function_IsDeprecated(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_Function_IsDeprecated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_Function_IsDeprecated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_Function_IsDeprecated(arg0, arg1)
}

func Function_alias_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Function_alias_name(
		arg0,
		arg1,
	)
}

func zetasql_Function_alias_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Function_alias_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_new(arg0 int, arg1 *unsafe.Pointer) {
	zetasql_FunctionArgumentTypeOptions_new(
		C.int(arg0),
		arg1,
	)
}

func zetasql_FunctionArgumentTypeOptions_new(arg0 C.int, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentTypeOptions_new(arg0, arg1)
}

func FunctionArgumentTypeOptions_cardinality(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_FunctionArgumentTypeOptions_cardinality(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_cardinality(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_cardinality(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_be_constant(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentTypeOptions_must_be_constant(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_must_be_constant(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentTypeOptions_must_be_constant(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_be_non_null(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentTypeOptions_must_be_non_null(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_must_be_non_null(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentTypeOptions_must_be_non_null(arg0, arg1)
}

func FunctionArgumentTypeOptions_is_not_aggregate(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentTypeOptions_is_not_aggregate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_is_not_aggregate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentTypeOptions_is_not_aggregate(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_support_equality(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentTypeOptions_must_support_equality(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_must_support_equality(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentTypeOptions_must_support_equality(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_support_ordering(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentTypeOptions_must_support_ordering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_must_support_ordering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentTypeOptions_must_support_ordering(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_support_grouping(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentTypeOptions_must_support_grouping(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_must_support_grouping(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentTypeOptions_must_support_grouping(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_min_value(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentTypeOptions_has_min_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_has_min_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentTypeOptions_has_min_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_max_value(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentTypeOptions_has_max_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_has_max_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentTypeOptions_has_max_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_min_value(arg0 unsafe.Pointer, arg1 *int64) {
	zetasql_FunctionArgumentTypeOptions_min_value(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_min_value(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_FunctionArgumentTypeOptions_min_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_max_value(arg0 unsafe.Pointer, arg1 *int64) {
	zetasql_FunctionArgumentTypeOptions_max_value(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_max_value(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_zetasql_FunctionArgumentTypeOptions_max_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_relation_input_schema(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentTypeOptions_has_relation_input_schema(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_has_relation_input_schema(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentTypeOptions_has_relation_input_schema(arg0, arg1)
}

func FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(arg0, arg1)
}

func FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_argument_name(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentTypeOptions_has_argument_name(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_has_argument_name(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentTypeOptions_has_argument_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionArgumentTypeOptions_argument_name(
		arg0,
		arg1,
	)
}

func zetasql_FunctionArgumentTypeOptions_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentTypeOptions_argument_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentTypeOptions_argument_name_is_mandatory(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentTypeOptions_argument_name_is_mandatory(arg0, arg1)
}

func FunctionArgumentTypeOptions_procedure_argument_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_FunctionArgumentTypeOptions_procedure_argument_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_procedure_argument_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_procedure_argument_mode(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_cardinality(arg0 unsafe.Pointer, arg1 int) {
	zetasql_FunctionArgumentTypeOptions_set_cardinality(
		arg0,
		C.int(arg1),
	)
}

func zetasql_FunctionArgumentTypeOptions_set_cardinality(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_cardinality(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_be_constant(arg0 unsafe.Pointer, arg1 int) {
	zetasql_FunctionArgumentTypeOptions_set_must_be_constant(
		arg0,
		C.int(arg1),
	)
}

func zetasql_FunctionArgumentTypeOptions_set_must_be_constant(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_must_be_constant(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_be_non_null(arg0 unsafe.Pointer, arg1 int) {
	zetasql_FunctionArgumentTypeOptions_set_must_be_non_null(
		arg0,
		C.int(arg1),
	)
}

func zetasql_FunctionArgumentTypeOptions_set_must_be_non_null(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_must_be_non_null(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_is_not_aggregate(arg0 unsafe.Pointer, arg1 int) {
	zetasql_FunctionArgumentTypeOptions_set_is_not_aggregate(
		arg0,
		C.int(arg1),
	)
}

func zetasql_FunctionArgumentTypeOptions_set_is_not_aggregate(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_is_not_aggregate(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_support_equality(arg0 unsafe.Pointer, arg1 int) {
	zetasql_FunctionArgumentTypeOptions_set_must_support_equality(
		arg0,
		C.int(arg1),
	)
}

func zetasql_FunctionArgumentTypeOptions_set_must_support_equality(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_must_support_equality(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_support_ordering(arg0 unsafe.Pointer, arg1 int) {
	zetasql_FunctionArgumentTypeOptions_set_must_support_ordering(
		arg0,
		C.int(arg1),
	)
}

func zetasql_FunctionArgumentTypeOptions_set_must_support_ordering(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_must_support_ordering(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_support_grouping(arg0 unsafe.Pointer, arg1 int) {
	zetasql_FunctionArgumentTypeOptions_set_must_support_grouping(
		arg0,
		C.int(arg1),
	)
}

func zetasql_FunctionArgumentTypeOptions_set_must_support_grouping(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_must_support_grouping(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_min_value(arg0 unsafe.Pointer, arg1 int64) {
	zetasql_FunctionArgumentTypeOptions_set_min_value(
		arg0,
		C.int64_t(arg1),
	)
}

func zetasql_FunctionArgumentTypeOptions_set_min_value(arg0 unsafe.Pointer, arg1 C.int64_t) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_min_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_max_value(arg0 unsafe.Pointer, arg1 int64) {
	zetasql_FunctionArgumentTypeOptions_set_max_value(
		arg0,
		C.int64_t(arg1),
	)
}

func zetasql_FunctionArgumentTypeOptions_set_max_value(arg0 unsafe.Pointer, arg1 C.int64_t) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_max_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 int) {
	zetasql_FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(
		arg0,
		C.int(arg1),
	)
}

func zetasql_FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_FunctionArgumentTypeOptions_set_argument_name(
		arg0,
		arg1,
	)
}

func zetasql_FunctionArgumentTypeOptions_set_argument_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_argument_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 int) {
	zetasql_FunctionArgumentTypeOptions_set_argument_name_is_mandatory(
		arg0,
		C.int(arg1),
	)
}

func zetasql_FunctionArgumentTypeOptions_set_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_argument_name_is_mandatory(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_procedure_argument_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_FunctionArgumentTypeOptions_set_procedure_argument_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_FunctionArgumentTypeOptions_set_procedure_argument_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_procedure_argument_mode(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 int) {
	zetasql_FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(
		arg0,
		C.int(arg1),
	)
}

func zetasql_FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(arg0, arg1)
}

func FunctionArgumentTypeOptions_OptionsDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionArgumentTypeOptions_OptionsDebugString(
		arg0,
		arg1,
	)
}

func zetasql_FunctionArgumentTypeOptions_OptionsDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentTypeOptions_OptionsDebugString(arg0, arg1)
}

func FunctionArgumentTypeOptions_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_FunctionArgumentTypeOptions_GetSQLDeclaration(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_FunctionArgumentTypeOptions_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentTypeOptions_GetSQLDeclaration(arg0, arg1, arg2)
}

func FunctionArgumentTypeOptions_set_argument_name_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_FunctionArgumentTypeOptions_set_argument_name_parse_location(
		arg0,
		arg1,
	)
}

func zetasql_FunctionArgumentTypeOptions_set_argument_name_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_argument_name_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_name_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionArgumentTypeOptions_argument_name_parse_location(
		arg0,
		arg1,
	)
}

func zetasql_FunctionArgumentTypeOptions_argument_name_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentTypeOptions_argument_name_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_type_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_FunctionArgumentTypeOptions_set_argument_type_parse_location(
		arg0,
		arg1,
	)
}

func zetasql_FunctionArgumentTypeOptions_set_argument_type_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_argument_type_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_type_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionArgumentTypeOptions_argument_type_parse_location(
		arg0,
		arg1,
	)
}

func zetasql_FunctionArgumentTypeOptions_argument_type_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentTypeOptions_argument_type_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_default(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_FunctionArgumentTypeOptions_set_default(
		arg0,
		arg1,
	)
}

func zetasql_FunctionArgumentTypeOptions_set_default(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_default(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_default(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentTypeOptions_has_default(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_has_default(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentTypeOptions_has_default(arg0, arg1)
}

func FunctionArgumentTypeOptions_get_default(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionArgumentTypeOptions_get_default(
		arg0,
		arg1,
	)
}

func zetasql_FunctionArgumentTypeOptions_get_default(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentTypeOptions_get_default(arg0, arg1)
}

func FunctionArgumentTypeOptions_clear_default(arg0 unsafe.Pointer) {
	zetasql_FunctionArgumentTypeOptions_clear_default(
		arg0,
	)
}

func zetasql_FunctionArgumentTypeOptions_clear_default(arg0 unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentTypeOptions_clear_default(arg0)
}

func FunctionArgumentTypeOptions_argument_collation_mode(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_FunctionArgumentTypeOptions_argument_collation_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_argument_collation_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_argument_collation_mode(arg0, arg1)
}

func FunctionArgumentTypeOptions_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentTypeOptions_uses_array_element_for_collation(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentTypeOptions_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentTypeOptions_uses_array_element_for_collation(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 int) {
	zetasql_FunctionArgumentTypeOptions_set_uses_array_element_for_collation(
		arg0,
		C.int(arg1),
	)
}

func zetasql_FunctionArgumentTypeOptions_set_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_uses_array_element_for_collation(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_collation_mode(arg0 unsafe.Pointer, arg1 int) {
	zetasql_FunctionArgumentTypeOptions_set_argument_collation_mode(
		arg0,
		C.int(arg1),
	)
}

func zetasql_FunctionArgumentTypeOptions_set_argument_collation_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_FunctionArgumentTypeOptions_set_argument_collation_mode(arg0, arg1)
}

func FunctionArgumentType_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_FunctionArgumentType_new(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_FunctionArgumentType_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentType_new(arg0, arg1, arg2)
}

func FunctionArgumentType_new_templated_type(arg0 int, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_FunctionArgumentType_new_templated_type(
		C.int(arg0),
		arg1,
		arg2,
	)
}

func zetasql_FunctionArgumentType_new_templated_type(arg0 C.int, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentType_new_templated_type(arg0, arg1, arg2)
}

func FunctionArgumentType_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionArgumentType_options(
		arg0,
		arg1,
	)
}

func zetasql_FunctionArgumentType_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentType_options(arg0, arg1)
}

func FunctionArgumentType_required(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_required(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_required(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_required(arg0, arg1)
}

func FunctionArgumentType_repeated(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_repeated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_repeated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_repeated(arg0, arg1)
}

func FunctionArgumentType_optional(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_optional(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_optional(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_optional(arg0, arg1)
}

func FunctionArgumentType_cardinality(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_FunctionArgumentType_cardinality(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_cardinality(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_FunctionArgumentType_cardinality(arg0, arg1)
}

func FunctionArgumentType_must_be_constant(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_must_be_constant(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_must_be_constant(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_must_be_constant(arg0, arg1)
}

func FunctionArgumentType_has_argument_name(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_has_argument_name(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_has_argument_name(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_has_argument_name(arg0, arg1)
}

func FunctionArgumentType_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionArgumentType_argument_name(
		arg0,
		arg1,
	)
}

func zetasql_FunctionArgumentType_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentType_argument_name(arg0, arg1)
}

func FunctionArgumentType_num_occurrences(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_FunctionArgumentType_num_occurrences(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_num_occurrences(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_FunctionArgumentType_num_occurrences(arg0, arg1)
}

func FunctionArgumentType_set_num_occurrences(arg0 unsafe.Pointer, arg1 int) {
	zetasql_FunctionArgumentType_set_num_occurrences(
		arg0,
		C.int(arg1),
	)
}

func zetasql_FunctionArgumentType_set_num_occurrences(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_FunctionArgumentType_set_num_occurrences(arg0, arg1)
}

func FunctionArgumentType_IncrementNumOccurrences(arg0 unsafe.Pointer) {
	zetasql_FunctionArgumentType_IncrementNumOccurrences(
		arg0,
	)
}

func zetasql_FunctionArgumentType_IncrementNumOccurrences(arg0 unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentType_IncrementNumOccurrences(arg0)
}

func FunctionArgumentType_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionArgumentType_type(
		arg0,
		arg1,
	)
}

func zetasql_FunctionArgumentType_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentType_type(arg0, arg1)
}

func FunctionArgumentType_kind(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_FunctionArgumentType_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_FunctionArgumentType_kind(arg0, arg1)
}

func FunctionArgumentType_labmda(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionArgumentType_labmda(
		arg0,
		arg1,
	)
}

func zetasql_FunctionArgumentType_labmda(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentType_labmda(arg0, arg1)
}

func FunctionArgumentType_IsConcrete(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_IsConcrete(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_IsConcrete(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_IsConcrete(arg0, arg1)
}

func FunctionArgumentType_IsTemplated(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_IsTemplated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_IsTemplated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_IsTemplated(arg0, arg1)
}

func FunctionArgumentType_IsScalar(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_IsScalar(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_IsScalar(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_IsScalar(arg0, arg1)
}

func FunctionArgumentType_IsRelation(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_IsRelation(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_IsRelation(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_IsRelation(arg0, arg1)
}

func FunctionArgumentType_IsModel(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_IsModel(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_IsModel(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_IsModel(arg0, arg1)
}

func FunctionArgumentType_IsConnection(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_IsConnection(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_IsConnection(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_IsConnection(arg0, arg1)
}

func FunctionArgumentType_IsLambda(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_IsLambda(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_IsLambda(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_IsLambda(arg0, arg1)
}

func FunctionArgumentType_IsFixedRelation(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_IsFixedRelation(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_IsFixedRelation(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_IsFixedRelation(arg0, arg1)
}

func FunctionArgumentType_IsVoid(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_IsVoid(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_IsVoid(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_IsVoid(arg0, arg1)
}

func FunctionArgumentType_IsDescriptor(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_IsDescriptor(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_IsDescriptor(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_IsDescriptor(arg0, arg1)
}

func FunctionArgumentType_TemplatedKindIsRelated(arg0 unsafe.Pointer, arg1 int, arg2 *bool) {
	zetasql_FunctionArgumentType_TemplatedKindIsRelated(
		arg0,
		C.int(arg1),
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_FunctionArgumentType_TemplatedKindIsRelated(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.char) {
	C.export_zetasql_FunctionArgumentType_TemplatedKindIsRelated(arg0, arg1, arg2)
}

func FunctionArgumentType_AllowCoercionFrom(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	zetasql_FunctionArgumentType_AllowCoercionFrom(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func zetasql_FunctionArgumentType_AllowCoercionFrom(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_FunctionArgumentType_AllowCoercionFrom(arg0, arg1, arg2)
}

func FunctionArgumentType_HasDefault(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionArgumentType_HasDefault(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionArgumentType_HasDefault(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionArgumentType_HasDefault(arg0, arg1)
}

func FunctionArgumentType_GetDefault(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionArgumentType_GetDefault(
		arg0,
		arg1,
	)
}

func zetasql_FunctionArgumentType_GetDefault(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentType_GetDefault(arg0, arg1)
}

func FunctionArgumentType_UserFacingName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_FunctionArgumentType_UserFacingName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_FunctionArgumentType_UserFacingName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentType_UserFacingName(arg0, arg1, arg2)
}

func FunctionArgumentType_UserFacingNameWithCardinality(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_FunctionArgumentType_UserFacingNameWithCardinality(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_FunctionArgumentType_UserFacingNameWithCardinality(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentType_UserFacingNameWithCardinality(arg0, arg1, arg2)
}

func FunctionArgumentType_IsValid(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_FunctionArgumentType_IsValid(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_FunctionArgumentType_IsValid(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentType_IsValid(arg0, arg1, arg2)
}

func FunctionArgumentType_DebugString(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_FunctionArgumentType_DebugString(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_FunctionArgumentType_DebugString(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentType_DebugString(arg0, arg1, arg2)
}

func FunctionArgumentType_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_FunctionArgumentType_GetSQLDeclaration(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_FunctionArgumentType_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_FunctionArgumentType_GetSQLDeclaration(arg0, arg1, arg2)
}

func ArgumentTypeLambda_argument_types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ArgumentTypeLambda_argument_types(
		arg0,
		arg1,
	)
}

func zetasql_ArgumentTypeLambda_argument_types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ArgumentTypeLambda_argument_types(arg0, arg1)
}

func ArgumentTypeLambda_body_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_ArgumentTypeLambda_body_type(
		arg0,
		arg1,
	)
}

func zetasql_ArgumentTypeLambda_body_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_ArgumentTypeLambda_body_type(arg0, arg1)
}

func FunctionSignature_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_FunctionSignature_new(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_FunctionSignature_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_FunctionSignature_new(arg0, arg1, arg2)
}

func FunctionSignature_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionSignature_arguments(
		arg0,
		arg1,
	)
}

func zetasql_FunctionSignature_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionSignature_arguments(arg0, arg1)
}

func FunctionSignature_concret_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionSignature_concret_arguments(
		arg0,
		arg1,
	)
}

func zetasql_FunctionSignature_concret_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionSignature_concret_arguments(arg0, arg1)
}

func FunctionSignature_result_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionSignature_result_type(
		arg0,
		arg1,
	)
}

func zetasql_FunctionSignature_result_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionSignature_result_type(arg0, arg1)
}

func FunctionSignature_IsConcrete(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionSignature_IsConcrete(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionSignature_IsConcrete(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionSignature_IsConcrete(arg0, arg1)
}

func FunctionSignature_HasConcreteArguments(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionSignature_HasConcreteArguments(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionSignature_HasConcreteArguments(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionSignature_HasConcreteArguments(arg0, arg1)
}

func FunctionSignature_IsValid(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_FunctionSignature_IsValid(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_FunctionSignature_IsValid(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_FunctionSignature_IsValid(arg0, arg1, arg2)
}

func FunctionSignature_IsValidForFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionSignature_IsValidForFunction(
		arg0,
		arg1,
	)
}

func zetasql_FunctionSignature_IsValidForFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionSignature_IsValidForFunction(arg0, arg1)
}

func FunctionSignature_IsValidForTableValuedFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionSignature_IsValidForTableValuedFunction(
		arg0,
		arg1,
	)
}

func zetasql_FunctionSignature_IsValidForTableValuedFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionSignature_IsValidForTableValuedFunction(arg0, arg1)
}

func FunctionSignature_IsValidForProcedure(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionSignature_IsValidForProcedure(
		arg0,
		arg1,
	)
}

func zetasql_FunctionSignature_IsValidForProcedure(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionSignature_IsValidForProcedure(arg0, arg1)
}

func FunctionSignature_FirstRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_FunctionSignature_FirstRepeatedArgumentIndex(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionSignature_FirstRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_FunctionSignature_FirstRepeatedArgumentIndex(arg0, arg1)
}

func FunctionSignature_LastRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_FunctionSignature_LastRepeatedArgumentIndex(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionSignature_LastRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_FunctionSignature_LastRepeatedArgumentIndex(arg0, arg1)
}

func FunctionSignature_NumRequiredArguments(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_FunctionSignature_NumRequiredArguments(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionSignature_NumRequiredArguments(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_FunctionSignature_NumRequiredArguments(arg0, arg1)
}

func FunctionSignature_NumRepeatedArguments(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_FunctionSignature_NumRepeatedArguments(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionSignature_NumRepeatedArguments(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_FunctionSignature_NumRepeatedArguments(arg0, arg1)
}

func FunctionSignature_NumOptionalArguments(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_FunctionSignature_NumOptionalArguments(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionSignature_NumOptionalArguments(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_FunctionSignature_NumOptionalArguments(arg0, arg1)
}

func FunctionSignature_DebugString(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	zetasql_FunctionSignature_DebugString(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func zetasql_FunctionSignature_DebugString(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_zetasql_FunctionSignature_DebugString(arg0, arg1, arg2, arg3)
}

func FunctionSignature_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	zetasql_FunctionSignature_GetSQLDeclaration(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func zetasql_FunctionSignature_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_zetasql_FunctionSignature_GetSQLDeclaration(arg0, arg1, arg2, arg3)
}

func FunctionSignature_IsDeprecated(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionSignature_IsDeprecated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionSignature_IsDeprecated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionSignature_IsDeprecated(arg0, arg1)
}

func FunctionSignature_SetIsDeprecated(arg0 unsafe.Pointer, arg1 int) {
	zetasql_FunctionSignature_SetIsDeprecated(
		arg0,
		C.int(arg1),
	)
}

func zetasql_FunctionSignature_SetIsDeprecated(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_FunctionSignature_SetIsDeprecated(arg0, arg1)
}

func FunctionSignature_IsInternal(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionSignature_IsInternal(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionSignature_IsInternal(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionSignature_IsInternal(arg0, arg1)
}

func FunctionSignature_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_FunctionSignature_options(
		arg0,
		arg1,
	)
}

func zetasql_FunctionSignature_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_FunctionSignature_options(arg0, arg1)
}

func FunctionSignature_SetConcreteResultType(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	zetasql_FunctionSignature_SetConcreteResultType(
		arg0,
		arg1,
	)
}

func zetasql_FunctionSignature_SetConcreteResultType(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_FunctionSignature_SetConcreteResultType(arg0, arg1)
}

func FunctionSignature_IsTemplated(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionSignature_IsTemplated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionSignature_IsTemplated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionSignature_IsTemplated(arg0, arg1)
}

func FunctionSignature_AllArgumentsHaveDefaults(arg0 unsafe.Pointer, arg1 *bool) {
	zetasql_FunctionSignature_AllArgumentsHaveDefaults(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func zetasql_FunctionSignature_AllArgumentsHaveDefaults(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_FunctionSignature_AllArgumentsHaveDefaults(arg0, arg1)
}

func Procedure_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_Procedure_new(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_Procedure_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_Procedure_new(arg0, arg1, arg2)
}

func Procedure_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Procedure_Name(
		arg0,
		arg1,
	)
}

func zetasql_Procedure_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Procedure_Name(arg0, arg1)
}

func Procedure_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Procedure_FullName(
		arg0,
		arg1,
	)
}

func zetasql_Procedure_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Procedure_FullName(arg0, arg1)
}

func Procedure_NamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Procedure_NamePath(
		arg0,
		arg1,
	)
}

func zetasql_Procedure_NamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Procedure_NamePath(arg0, arg1)
}

func Procedure_Signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_Procedure_Signature(
		arg0,
		arg1,
	)
}

func zetasql_Procedure_Signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_Procedure_Signature(arg0, arg1)
}

func Procedure_SupportedSignatureUserFacingText(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_Procedure_SupportedSignatureUserFacingText(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_Procedure_SupportedSignatureUserFacingText(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_Procedure_SupportedSignatureUserFacingText(arg0, arg1, arg2)
}

func SQLTableValuedFunction_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_SQLTableValuedFunction_new(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_SQLTableValuedFunction_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_SQLTableValuedFunction_new(arg0, arg1, arg2)
}

func TableValuedFunction_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_TableValuedFunction_Name(
		arg0,
		arg1,
	)
}

func zetasql_TableValuedFunction_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_TableValuedFunction_Name(arg0, arg1)
}

func TableValuedFunction_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_TableValuedFunction_FullName(
		arg0,
		arg1,
	)
}

func zetasql_TableValuedFunction_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_TableValuedFunction_FullName(arg0, arg1)
}

func TableValuedFunction_function_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_TableValuedFunction_function_name_path(
		arg0,
		arg1,
	)
}

func zetasql_TableValuedFunction_function_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_TableValuedFunction_function_name_path(arg0, arg1)
}

func TableValuedFunction_NumSignatures(arg0 unsafe.Pointer, arg1 *int) {
	zetasql_TableValuedFunction_NumSignatures(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func zetasql_TableValuedFunction_NumSignatures(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_TableValuedFunction_NumSignatures(arg0, arg1)
}

func TableValuedFunction_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_TableValuedFunction_signatures(
		arg0,
		arg1,
	)
}

func zetasql_TableValuedFunction_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_TableValuedFunction_signatures(arg0, arg1)
}

func TableValuedFunction_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_TableValuedFunction_AddSignature(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_TableValuedFunction_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_TableValuedFunction_AddSignature(arg0, arg1, arg2)
}

func TableValuedFunction_GetSignature(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	zetasql_TableValuedFunction_GetSignature(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func zetasql_TableValuedFunction_GetSignature(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_TableValuedFunction_GetSignature(arg0, arg1, arg2)
}

func TableValuedFunction_GetSupportedSignaturesUserFacingText(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_TableValuedFunction_GetSupportedSignaturesUserFacingText(
		arg0,
		arg1,
	)
}

func zetasql_TableValuedFunction_GetSupportedSignaturesUserFacingText(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_TableValuedFunction_GetSupportedSignaturesUserFacingText(arg0, arg1)
}

func TableValuedFunction_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_TableValuedFunction_DebugString(
		arg0,
		arg1,
	)
}

func zetasql_TableValuedFunction_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_TableValuedFunction_DebugString(arg0, arg1)
}

func TableValuedFunction_SetUserIdColumnNamePath(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_TableValuedFunction_SetUserIdColumnNamePath(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_TableValuedFunction_SetUserIdColumnNamePath(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_TableValuedFunction_SetUserIdColumnNamePath(arg0, arg1, arg2)
}

func TableValuedFunction_anonymization_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	zetasql_TableValuedFunction_anonymization_info(
		arg0,
		arg1,
	)
}

func zetasql_TableValuedFunction_anonymization_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_TableValuedFunction_anonymization_info(arg0, arg1)
}

func FormatSql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	zetasql_FormatSql(
		arg0,
		arg1,
		arg2,
	)
}

func zetasql_FormatSql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_FormatSql(arg0, arg1, arg2)
}

//export export_zetasql_cctz_FixedOffsetFromName
//go:linkname export_zetasql_cctz_FixedOffsetFromName github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetFromName
func export_zetasql_cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_cctz_FixedOffsetToName
//go:linkname export_zetasql_cctz_FixedOffsetToName github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToName
func export_zetasql_cctz_FixedOffsetToName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_cctz_FixedOffsetToAbbr
//go:linkname export_zetasql_cctz_FixedOffsetToAbbr github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToAbbr
func export_zetasql_cctz_FixedOffsetToAbbr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_cctz_detail_format
//go:linkname export_zetasql_cctz_detail_format github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_format
func export_zetasql_cctz_detail_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer)

//export export_zetasql_cctz_detail_parse
//go:linkname export_zetasql_cctz_detail_parse github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_parse
func export_zetasql_cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *C.char)

//export export_zetasql_TimeZoneIf_Load
//go:linkname export_zetasql_TimeZoneIf_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneIf_Load
func export_zetasql_TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_time_zone_Impl_UTC
//go:linkname export_zetasql_time_zone_Impl_UTC github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTC
func export_zetasql_time_zone_Impl_UTC(arg0 *unsafe.Pointer)

//export export_zetasql_time_zone_Impl_LoadTimeZone
//go:linkname export_zetasql_time_zone_Impl_LoadTimeZone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_LoadTimeZone
func export_zetasql_time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_time_zone_Impl_ClearTimeZoneMapTestOnly
//go:linkname export_zetasql_time_zone_Impl_ClearTimeZoneMapTestOnly github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_ClearTimeZoneMapTestOnly
func export_zetasql_time_zone_Impl_ClearTimeZoneMapTestOnly()

//export export_zetasql_time_zone_Impl_UTCImpl
//go:linkname export_zetasql_time_zone_Impl_UTCImpl github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTCImpl
func export_zetasql_time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer)

//export export_zetasql_TimeZoneInfo_Load
//go:linkname export_zetasql_TimeZoneInfo_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Load
func export_zetasql_TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_TimeZoneInfo_BreakTime
//go:linkname export_zetasql_TimeZoneInfo_BreakTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_BreakTime
func export_zetasql_TimeZoneInfo_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_TimeZoneInfo_MakeTime
//go:linkname export_zetasql_TimeZoneInfo_MakeTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_MakeTime
func export_zetasql_TimeZoneInfo_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_TimeZoneInfo_Version
//go:linkname export_zetasql_TimeZoneInfo_Version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Version
func export_zetasql_TimeZoneInfo_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_TimeZoneInfo_Description
//go:linkname export_zetasql_TimeZoneInfo_Description github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Description
func export_zetasql_TimeZoneInfo_Description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_TimeZoneInfo_NextTransition
//go:linkname export_zetasql_TimeZoneInfo_NextTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_NextTransition
func export_zetasql_TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_TimeZoneInfo_PrevTransition
//go:linkname export_zetasql_TimeZoneInfo_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_PrevTransition
func export_zetasql_TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_TimeZoneLibC_BreakTime
//go:linkname export_zetasql_TimeZoneLibC_BreakTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_BreakTime
func export_zetasql_TimeZoneLibC_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_TimeZoneLibC_MakeTime
//go:linkname export_zetasql_TimeZoneLibC_MakeTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_MakeTime
func export_zetasql_TimeZoneLibC_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_TimeZoneLibC_Version
//go:linkname export_zetasql_TimeZoneLibC_Version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_Version
func export_zetasql_TimeZoneLibC_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_TimeZoneLibC_NextTransition
//go:linkname export_zetasql_TimeZoneLibC_NextTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_NextTransition
func export_zetasql_TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_TimeZoneLibC_PrevTransition
//go:linkname export_zetasql_TimeZoneLibC_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_PrevTransition
func export_zetasql_TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_time_zone_name
//go:linkname export_zetasql_time_zone_name github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_name
func export_zetasql_time_zone_name(arg0 *unsafe.Pointer)

//export export_zetasql_time_zone_lookup
//go:linkname export_zetasql_time_zone_lookup github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup
func export_zetasql_time_zone_lookup(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_time_zone_lookup2
//go:linkname export_zetasql_time_zone_lookup2 github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup2
func export_zetasql_time_zone_lookup2(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_time_zone_next_transition
//go:linkname export_zetasql_time_zone_next_transition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_next_transition
func export_zetasql_time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_time_zone_prev_transition
//go:linkname export_zetasql_time_zone_prev_transition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_prev_transition
func export_zetasql_time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_time_zone_version
//go:linkname export_zetasql_time_zone_version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_version
func export_zetasql_time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_time_zone_description
//go:linkname export_zetasql_time_zone_description github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_description
func export_zetasql_time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_cctz_load_time_zone
//go:linkname export_zetasql_cctz_load_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_load_time_zone
func export_zetasql_cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_cctz_utc_time_zone
//go:linkname export_zetasql_cctz_utc_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_utc_time_zone
func export_zetasql_cctz_utc_time_zone(arg0 *unsafe.Pointer)

//export export_zetasql_cctz_fixed_time_zone
//go:linkname export_zetasql_cctz_fixed_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_fixed_time_zone
func export_zetasql_cctz_fixed_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_cctz_local_time_zone
//go:linkname export_zetasql_cctz_local_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_local_time_zone
func export_zetasql_cctz_local_time_zone(arg0 *unsafe.Pointer)

//export export_zetasql_cctz_ParsePosixSpec
//go:linkname export_zetasql_cctz_ParsePosixSpec github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_ParsePosixSpec
func export_zetasql_cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)
