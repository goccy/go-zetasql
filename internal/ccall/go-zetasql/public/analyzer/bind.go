package analyzer

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

#define GO_EXPORT(API) export_zetasql_public_analyzer_ ## API
#include "bridge.h"
#include "../../../go-absl/time/go_internal/cctz/time_zone/bridge.h"
*/
import "C"
import (
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone"
	"unsafe"
)

func AnalyzeStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	analyzer_AnalyzeStatement(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func analyzer_AnalyzeStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzeStatement(arg0, arg1, arg2, arg3)
}

func AnalyzerOutput_resolved_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_AnalyzerOutput_resolved_statement(
		arg0,
		arg1,
	)
}

func analyzer_AnalyzerOutput_resolved_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOutput_resolved_statement(arg0, arg1)
}

func ResolvedNode_node_kind(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedNode_node_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedNode_node_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedNode_node_kind(arg0, arg1)
}

func ResolvedNode_IsScan(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedNode_IsScan(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedNode_IsScan(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedNode_IsScan(arg0, arg1)
}

func ResolvedNode_IsExpression(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedNode_IsExpression(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedNode_IsExpression(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedNode_IsExpression(arg0, arg1)
}

func ResolvedNode_IsStatement(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedNode_IsStatement(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedNode_IsStatement(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedNode_IsStatement(arg0, arg1)
}

func ResolvedNode_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedNode_DebugString(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedNode_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedNode_DebugString(arg0, arg1)
}

func ResolvedNode_GetChildNodes_num(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedNode_GetChildNodes_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedNode_GetChildNodes_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedNode_GetChildNodes_num(arg0, arg1)
}

func ResolvedNode_GetChildNode(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	analyzer_ResolvedNode_GetChildNode(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func analyzer_ResolvedNode_GetChildNode(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedNode_GetChildNode(arg0, arg1, arg2)
}

func ResolvedNode_GetTreeDepth(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedNode_GetTreeDepth(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedNode_GetTreeDepth(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedNode_GetTreeDepth(arg0, arg1)
}

func ResolvedExpr_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExpr_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExpr_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExpr_type(arg0, arg1)
}

func ResolvedExpr_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExpr_set_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExpr_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExpr_set_type(arg0, arg1)
}

func ResolvedExpr_type_annotation_map(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExpr_type_annotation_map(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExpr_type_annotation_map(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExpr_type_annotation_map(arg0, arg1)
}

func ResolvedExpr_set_type_annotation_map(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExpr_set_type_annotation_map(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExpr_set_type_annotation_map(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExpr_set_type_annotation_map(arg0, arg1)
}

func ResolvedLiteral_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedLiteral_value(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedLiteral_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedLiteral_value(arg0, arg1)
}

func ResolvedLiteral_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedLiteral_set_value(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedLiteral_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedLiteral_set_value(arg0, arg1)
}

func ResolvedLiteral_has_explicit_type(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedLiteral_has_explicit_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedLiteral_has_explicit_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedLiteral_has_explicit_type(arg0, arg1)
}

func ResolvedLiteral_set_has_explicit_type(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedLiteral_set_has_explicit_type(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedLiteral_set_has_explicit_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedLiteral_set_has_explicit_type(arg0, arg1)
}

func ResolvedLiteral_float_literal_id(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedLiteral_float_literal_id(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedLiteral_float_literal_id(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedLiteral_float_literal_id(arg0, arg1)
}

func ResolvedLiteral_set_float_literal_id(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedLiteral_set_float_literal_id(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedLiteral_set_float_literal_id(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedLiteral_set_float_literal_id(arg0, arg1)
}

func ResolvedLiteral_preserve_in_literal_remover(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedLiteral_preserve_in_literal_remover(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedLiteral_preserve_in_literal_remover(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedLiteral_preserve_in_literal_remover(arg0, arg1)
}

func ResolvedLiteral_set_preserve_in_literal_remover(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedLiteral_set_preserve_in_literal_remover(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedLiteral_set_preserve_in_literal_remover(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedLiteral_set_preserve_in_literal_remover(arg0, arg1)
}

func ResolvedParameter_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedParameter_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedParameter_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedParameter_name(arg0, arg1)
}

func ResolvedParameter_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedParameter_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedParameter_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedParameter_set_name(arg0, arg1)
}

func ResolvedParameter_position(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedParameter_position(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedParameter_position(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedParameter_position(arg0, arg1)
}

func ResolvedParameter_set_position(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedParameter_set_position(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedParameter_set_position(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedParameter_set_position(arg0, arg1)
}

func ResolvedParameter_is_untyped(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedParameter_is_untyped(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedParameter_is_untyped(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedParameter_is_untyped(arg0, arg1)
}

func ResolvedParameter_set_is_untyped(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedParameter_set_is_untyped(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedParameter_set_is_untyped(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedParameter_set_is_untyped(arg0, arg1)
}

func ResolvedExpressionColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExpressionColumn_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExpressionColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExpressionColumn_name(arg0, arg1)
}

func ResolvedExpressionColumn_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExpressionColumn_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExpressionColumn_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExpressionColumn_set_name(arg0, arg1)
}

func ResolvedColumnRef_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumnRef_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnRef_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnRef_column(arg0, arg1)
}

func ResolvedColumnRef_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnRef_set_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnRef_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnRef_set_column(arg0, arg1)
}

func ResolvedColumnRef_is_correlated(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedColumnRef_is_correlated(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedColumnRef_is_correlated(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedColumnRef_is_correlated(arg0, arg1)
}

func ResolvedColumnRef_set_is_correlated(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedColumnRef_set_is_correlated(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedColumnRef_set_is_correlated(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedColumnRef_set_is_correlated(arg0, arg1)
}

func ResolvedConstant_constant(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedConstant_constant(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedConstant_constant(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedConstant_constant(arg0, arg1)
}

func ResolvedConstant_set_constant(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedConstant_set_constant(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedConstant_set_constant(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedConstant_set_constant(arg0, arg1)
}

func ResolvedSystemVariable_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSystemVariable_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSystemVariable_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSystemVariable_name_path(arg0, arg1)
}

func ResolvedSystemVariable_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSystemVariable_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSystemVariable_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSystemVariable_set_name_path(arg0, arg1)
}

func ResolvedSystemVariable_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSystemVariable_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSystemVariable_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSystemVariable_add_name_path(arg0, arg1)
}

func ResolvedInlineLambda_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedInlineLambda_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInlineLambda_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInlineLambda_argument_list(arg0, arg1)
}

func ResolvedInlineLambda_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInlineLambda_set_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInlineLambda_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInlineLambda_set_argument_list(arg0, arg1)
}

func ResolvedInlineLambda_add_argument(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInlineLambda_add_argument(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInlineLambda_add_argument(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInlineLambda_add_argument(arg0, arg1)
}

func ResolvedInlineLambda_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedInlineLambda_parameter_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInlineLambda_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInlineLambda_parameter_list(arg0, arg1)
}

func ResolvedInlineLambda_set_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInlineLambda_set_parameter_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInlineLambda_set_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInlineLambda_set_parameter_list(arg0, arg1)
}

func ResolvedInlineLambda_add_parameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInlineLambda_add_parameter(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInlineLambda_add_parameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInlineLambda_add_parameter(arg0, arg1)
}

func ResolvedInlineLambda_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedInlineLambda_body(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInlineLambda_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInlineLambda_body(arg0, arg1)
}

func ResolvedInlineLambda_set_body(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInlineLambda_set_body(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInlineLambda_set_body(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInlineLambda_set_body(arg0, arg1)
}

//export export_zetasql_public_analyzer_cctz_FixedOffsetFromName
//go:linkname export_zetasql_public_analyzer_cctz_FixedOffsetFromName github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetFromName
func export_zetasql_public_analyzer_cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int)

//export export_zetasql_public_analyzer_cctz_FixedOffsetToName
//go:linkname export_zetasql_public_analyzer_cctz_FixedOffsetToName github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToName
func export_zetasql_public_analyzer_cctz_FixedOffsetToName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_analyzer_cctz_FixedOffsetToAbbr
//go:linkname export_zetasql_public_analyzer_cctz_FixedOffsetToAbbr github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToAbbr
func export_zetasql_public_analyzer_cctz_FixedOffsetToAbbr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_analyzer_cctz_detail_format
//go:linkname export_zetasql_public_analyzer_cctz_detail_format github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_format
func export_zetasql_public_analyzer_cctz_detail_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer)

//export export_zetasql_public_analyzer_cctz_detail_parse
//go:linkname export_zetasql_public_analyzer_cctz_detail_parse github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_parse
func export_zetasql_public_analyzer_cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *C.int)

//export export_zetasql_public_analyzer_TimeZoneIf_Load
//go:linkname export_zetasql_public_analyzer_TimeZoneIf_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneIf_Load
func export_zetasql_public_analyzer_TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_analyzer_time_zone_Impl_UTC
//go:linkname export_zetasql_public_analyzer_time_zone_Impl_UTC github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTC
func export_zetasql_public_analyzer_time_zone_Impl_UTC(arg0 *unsafe.Pointer)

//export export_zetasql_public_analyzer_time_zone_Impl_LoadTimeZone
//go:linkname export_zetasql_public_analyzer_time_zone_Impl_LoadTimeZone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_LoadTimeZone
func export_zetasql_public_analyzer_time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int)

//export export_zetasql_public_analyzer_time_zone_Impl_ClearTimeZoneMapTestOnly
//go:linkname export_zetasql_public_analyzer_time_zone_Impl_ClearTimeZoneMapTestOnly github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_ClearTimeZoneMapTestOnly
func export_zetasql_public_analyzer_time_zone_Impl_ClearTimeZoneMapTestOnly()

//export export_zetasql_public_analyzer_time_zone_Impl_UTCImpl
//go:linkname export_zetasql_public_analyzer_time_zone_Impl_UTCImpl github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTCImpl
func export_zetasql_public_analyzer_time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer)

//export export_zetasql_public_analyzer_TimeZoneInfo_Load
//go:linkname export_zetasql_public_analyzer_TimeZoneInfo_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Load
func export_zetasql_public_analyzer_TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int)

//export export_zetasql_public_analyzer_TimeZoneInfo_BreakTime
//go:linkname export_zetasql_public_analyzer_TimeZoneInfo_BreakTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_BreakTime
func export_zetasql_public_analyzer_TimeZoneInfo_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_analyzer_TimeZoneInfo_MakeTime
//go:linkname export_zetasql_public_analyzer_TimeZoneInfo_MakeTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_MakeTime
func export_zetasql_public_analyzer_TimeZoneInfo_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_analyzer_TimeZoneInfo_Version
//go:linkname export_zetasql_public_analyzer_TimeZoneInfo_Version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Version
func export_zetasql_public_analyzer_TimeZoneInfo_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_analyzer_TimeZoneInfo_Description
//go:linkname export_zetasql_public_analyzer_TimeZoneInfo_Description github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Description
func export_zetasql_public_analyzer_TimeZoneInfo_Description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_analyzer_TimeZoneInfo_NextTransition
//go:linkname export_zetasql_public_analyzer_TimeZoneInfo_NextTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_NextTransition
func export_zetasql_public_analyzer_TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.int)

//export export_zetasql_public_analyzer_TimeZoneInfo_PrevTransition
//go:linkname export_zetasql_public_analyzer_TimeZoneInfo_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_PrevTransition
func export_zetasql_public_analyzer_TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.int)

//export export_zetasql_public_analyzer_TimeZoneLibC_BreakTime
//go:linkname export_zetasql_public_analyzer_TimeZoneLibC_BreakTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_BreakTime
func export_zetasql_public_analyzer_TimeZoneLibC_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_analyzer_TimeZoneLibC_MakeTime
//go:linkname export_zetasql_public_analyzer_TimeZoneLibC_MakeTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_MakeTime
func export_zetasql_public_analyzer_TimeZoneLibC_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_analyzer_TimeZoneLibC_Version
//go:linkname export_zetasql_public_analyzer_TimeZoneLibC_Version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_Version
func export_zetasql_public_analyzer_TimeZoneLibC_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_analyzer_TimeZoneLibC_NextTransition
//go:linkname export_zetasql_public_analyzer_TimeZoneLibC_NextTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_NextTransition
func export_zetasql_public_analyzer_TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.int)

//export export_zetasql_public_analyzer_TimeZoneLibC_PrevTransition
//go:linkname export_zetasql_public_analyzer_TimeZoneLibC_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_PrevTransition
func export_zetasql_public_analyzer_TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.int)

//export export_zetasql_public_analyzer_time_zone_name
//go:linkname export_zetasql_public_analyzer_time_zone_name github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_name
func export_zetasql_public_analyzer_time_zone_name(arg0 *unsafe.Pointer)

//export export_zetasql_public_analyzer_time_zone_lookup
//go:linkname export_zetasql_public_analyzer_time_zone_lookup github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup
func export_zetasql_public_analyzer_time_zone_lookup(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_analyzer_time_zone_lookup2
//go:linkname export_zetasql_public_analyzer_time_zone_lookup2 github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup2
func export_zetasql_public_analyzer_time_zone_lookup2(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_analyzer_time_zone_next_transition
//go:linkname export_zetasql_public_analyzer_time_zone_next_transition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_next_transition
func export_zetasql_public_analyzer_time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int)

//export export_zetasql_public_analyzer_time_zone_prev_transition
//go:linkname export_zetasql_public_analyzer_time_zone_prev_transition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_prev_transition
func export_zetasql_public_analyzer_time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int)

//export export_zetasql_public_analyzer_time_zone_version
//go:linkname export_zetasql_public_analyzer_time_zone_version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_version
func export_zetasql_public_analyzer_time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_analyzer_time_zone_description
//go:linkname export_zetasql_public_analyzer_time_zone_description github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_description
func export_zetasql_public_analyzer_time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_analyzer_cctz_load_time_zone
//go:linkname export_zetasql_public_analyzer_cctz_load_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_load_time_zone
func export_zetasql_public_analyzer_cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int)

//export export_zetasql_public_analyzer_cctz_utc_time_zone
//go:linkname export_zetasql_public_analyzer_cctz_utc_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_utc_time_zone
func export_zetasql_public_analyzer_cctz_utc_time_zone(arg0 *unsafe.Pointer)

//export export_zetasql_public_analyzer_cctz_fixed_time_zone
//go:linkname export_zetasql_public_analyzer_cctz_fixed_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_fixed_time_zone
func export_zetasql_public_analyzer_cctz_fixed_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_analyzer_cctz_local_time_zone
//go:linkname export_zetasql_public_analyzer_cctz_local_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_local_time_zone
func export_zetasql_public_analyzer_cctz_local_time_zone(arg0 *unsafe.Pointer)

//export export_zetasql_public_analyzer_cctz_ParsePosixSpec
//go:linkname export_zetasql_public_analyzer_cctz_ParsePosixSpec github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_ParsePosixSpec
func export_zetasql_public_analyzer_cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.int)
