package parser

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

#define GO_EXPORT(API) export_zetasql_parser_parser_ ## API
#include "bridge.h"
#include "../../../go-absl/time/go_internal/cctz/time_zone/bridge.h"
*/
import "C"
import (
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone"
	"unsafe"
)

func ParseStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	parser_ParseStatement(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func parser_ParseStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParseStatement(arg0, arg1, arg2, arg3)
}

func ParseScript(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	parser_ParseScript(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
		arg4,
	)
}

func parser_ParseScript(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParseScript(arg0, arg1, arg2, arg3, arg4)
}

func ParseNextStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *bool, arg4 *unsafe.Pointer) {
	parser_ParseNextStatement(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
		arg4,
	)
}

func parser_ParseNextStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *C.char, arg4 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParseNextStatement(arg0, arg1, arg2, arg3, arg4)
}

func ParseNextScriptStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *bool, arg4 *unsafe.Pointer) {
	parser_ParseNextScriptStatement(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
		arg4,
	)
}

func parser_ParseNextScriptStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *C.char, arg4 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParseNextScriptStatement(arg0, arg1, arg2, arg3, arg4)
}

func ParseType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	parser_ParseType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func parser_ParseType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParseType(arg0, arg1, arg2, arg3)
}

func ParseExpression(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	parser_ParseExpression(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func parser_ParseExpression(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParseExpression(arg0, arg1, arg2, arg3)
}

func Unparse(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_Unparse(
		arg0,
		arg1,
	)
}

func parser_Unparse(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_Unparse(arg0, arg1)
}

func ParseResumeLocation_FromStringView(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ParseResumeLocation_FromStringView(
		arg0,
		arg1,
	)
}

func parser_ParseResumeLocation_FromStringView(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParseResumeLocation_FromStringView(arg0, arg1)
}

func Status_OK(arg0 unsafe.Pointer, arg1 *bool) {
	parser_Status_OK(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_Status_OK(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_Status_OK(arg0, arg1)
}

func Status_String(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_Status_String(
		arg0,
		arg1,
	)
}

func parser_Status_String(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_Status_String(arg0, arg1)
}

func ParserOptions_new(arg0 *unsafe.Pointer) {
	parser_ParserOptions_new(
		arg0,
	)
}

func parser_ParserOptions_new(arg0 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParserOptions_new(arg0)
}

func ParserOptions_set_language_options(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	parser_ParserOptions_set_language_options(
		arg0,
		arg1,
	)
}

func parser_ParserOptions_set_language_options(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParserOptions_set_language_options(arg0, arg1)
}

func ParserOptions_language_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ParserOptions_language_options(
		arg0,
		arg1,
	)
}

func parser_ParserOptions_language_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParserOptions_language_options(arg0, arg1)
}

func ParserOutput_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ParserOutput_statement(
		arg0,
		arg1,
	)
}

func parser_ParserOutput_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParserOutput_statement(arg0, arg1)
}

func ParserOutput_script(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ParserOutput_script(
		arg0,
		arg1,
	)
}

func parser_ParserOutput_script(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParserOutput_script(arg0, arg1)
}

func ParserOutput_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ParserOutput_type(
		arg0,
		arg1,
	)
}

func parser_ParserOutput_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParserOutput_type(arg0, arg1)
}

func ParserOutput_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ParserOutput_expression(
		arg0,
		arg1,
	)
}

func parser_ParserOutput_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParserOutput_expression(arg0, arg1)
}

func ASTNode_getId(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTNode_getId(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNode_getId(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTNode_getId(arg0, arg1)
}

func ASTNode_node_kind(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTNode_node_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNode_node_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTNode_node_kind(arg0, arg1)
}

func ASTNode_SingleNodeDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTNode_SingleNodeDebugString(
		arg0,
		arg1,
	)
}

func parser_ASTNode_SingleNodeDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_SingleNodeDebugString(arg0, arg1)
}

func ASTNode_set_parent(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	parser_ASTNode_set_parent(
		arg0,
		arg1,
	)
}

func parser_ASTNode_set_parent(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_set_parent(arg0, arg1)
}

func ASTNode_parent(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTNode_parent(
		arg0,
		arg1,
	)
}

func parser_ASTNode_parent(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_parent(arg0, arg1)
}

func ASTNode_AddChildren(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	parser_ASTNode_AddChildren(
		arg0,
		arg1,
	)
}

func parser_ASTNode_AddChildren(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_AddChildren(arg0, arg1)
}

func ASTNode_AddChild(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	parser_ASTNode_AddChild(
		arg0,
		arg1,
	)
}

func parser_ASTNode_AddChild(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_AddChild(arg0, arg1)
}

func ASTNode_AddChildFront(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	parser_ASTNode_AddChildFront(
		arg0,
		arg1,
	)
}

func parser_ASTNode_AddChildFront(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_AddChildFront(arg0, arg1)
}

func ASTNode_num_children(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTNode_num_children(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNode_num_children(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTNode_num_children(arg0, arg1)
}

func ASTNode_child(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTNode_child(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTNode_child(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_child(arg0, arg1, arg2)
}

func ASTNode_mutable_child(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTNode_mutable_child(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTNode_mutable_child(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_mutable_child(arg0, arg1, arg2)
}

func ASTNode_find_child_index(arg0 unsafe.Pointer, arg1 int, arg2 *int) {
	parser_ASTNode_find_child_index(
		arg0,
		C.int(arg1),
		(*C.int)(unsafe.Pointer(arg2)),
	)
}

func parser_ASTNode_find_child_index(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.int) {
	C.export_zetasql_parser_parser_ASTNode_find_child_index(arg0, arg1, arg2)
}

func ASTNode_DebugString(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTNode_DebugString(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTNode_DebugString(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_DebugString(arg0, arg1, arg2)
}

func ASTNode_MoveStartLocation(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTNode_MoveStartLocation(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTNode_MoveStartLocation(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTNode_MoveStartLocation(arg0, arg1)
}

func ASTNode_MoveStartLocationBack(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTNode_MoveStartLocationBack(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTNode_MoveStartLocationBack(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTNode_MoveStartLocationBack(arg0, arg1)
}

func ASTNode_SetStartLocationToEndLocation(arg0 unsafe.Pointer) {
	parser_ASTNode_SetStartLocationToEndLocation(
		arg0,
	)
}

func parser_ASTNode_SetStartLocationToEndLocation(arg0 unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_SetStartLocationToEndLocation(arg0)
}

func ASTNode_MoveEndLocationBack(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTNode_MoveEndLocationBack(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTNode_MoveEndLocationBack(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTNode_MoveEndLocationBack(arg0, arg1)
}

func ASTNode_set_start_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	parser_ASTNode_set_start_location(
		arg0,
		arg1,
	)
}

func parser_ASTNode_set_start_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_set_start_location(arg0, arg1)
}

func ASTNode_set_end_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	parser_ASTNode_set_end_location(
		arg0,
		arg1,
	)
}

func parser_ASTNode_set_end_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_set_end_location(arg0, arg1)
}

func ASTNode_IsTableExpression(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTNode_IsTableExpression(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNode_IsTableExpression(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTNode_IsTableExpression(arg0, arg1)
}

func ASTNode_IsQueryExpression(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTNode_IsQueryExpression(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNode_IsQueryExpression(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTNode_IsQueryExpression(arg0, arg1)
}

func ASTNode_IsExpression(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTNode_IsExpression(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNode_IsExpression(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTNode_IsExpression(arg0, arg1)
}

func ASTNode_IsType(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTNode_IsType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNode_IsType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTNode_IsType(arg0, arg1)
}

func ASTNode_IsLeaf(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTNode_IsLeaf(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNode_IsLeaf(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTNode_IsLeaf(arg0, arg1)
}

func ASTNode_IsStatement(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTNode_IsStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNode_IsStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTNode_IsStatement(arg0, arg1)
}

func ASTNode_IsScriptStatement(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTNode_IsScriptStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNode_IsScriptStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTNode_IsScriptStatement(arg0, arg1)
}

func ASTNode_IsLoopStatement(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTNode_IsLoopStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNode_IsLoopStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTNode_IsLoopStatement(arg0, arg1)
}

func ASTNode_IsSqlStatement(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTNode_IsSqlStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNode_IsSqlStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTNode_IsSqlStatement(arg0, arg1)
}

func ASTNode_IsDdlStatement(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTNode_IsDdlStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNode_IsDdlStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTNode_IsDdlStatement(arg0, arg1)
}

func ASTNode_IsCreateStatement(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTNode_IsCreateStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNode_IsCreateStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTNode_IsCreateStatement(arg0, arg1)
}

func ASTNode_IsAlterStatement(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTNode_IsAlterStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNode_IsAlterStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTNode_IsAlterStatement(arg0, arg1)
}

func ASTNode_GetNodeKindString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTNode_GetNodeKindString(
		arg0,
		arg1,
	)
}

func parser_ASTNode_GetNodeKindString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_GetNodeKindString(arg0, arg1)
}

func ASTNode_GetParseLocationRange(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTNode_GetParseLocationRange(
		arg0,
		arg1,
	)
}

func parser_ASTNode_GetParseLocationRange(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_GetParseLocationRange(arg0, arg1)
}

func ASTNode_GetLocationString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTNode_GetLocationString(
		arg0,
		arg1,
	)
}

func parser_ASTNode_GetLocationString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_GetLocationString(arg0, arg1)
}

func ASTNode_NodeKindToString(arg0 int, arg1 *unsafe.Pointer) {
	parser_ASTNode_NodeKindToString(
		C.int(arg0),
		arg1,
	)
}

func parser_ASTNode_NodeKindToString(arg0 C.int, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNode_NodeKindToString(arg0, arg1)
}

func ParseLocationPoint_filename(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ParseLocationPoint_filename(
		arg0,
		arg1,
	)
}

func parser_ParseLocationPoint_filename(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParseLocationPoint_filename(arg0, arg1)
}

func ParseLocationPoint_GetByteOffset(arg0 unsafe.Pointer, arg1 *int) {
	parser_ParseLocationPoint_GetByteOffset(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ParseLocationPoint_GetByteOffset(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ParseLocationPoint_GetByteOffset(arg0, arg1)
}

func ParseLocationPoint_GetString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ParseLocationPoint_GetString(
		arg0,
		arg1,
	)
}

func parser_ParseLocationPoint_GetString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParseLocationPoint_GetString(arg0, arg1)
}

func ParseLocationRange_start(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ParseLocationRange_start(
		arg0,
		arg1,
	)
}

func parser_ParseLocationRange_start(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParseLocationRange_start(arg0, arg1)
}

func ParseLocationRange_end(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ParseLocationRange_end(
		arg0,
		arg1,
	)
}

func parser_ParseLocationRange_end(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParseLocationRange_end(arg0, arg1)
}

func ParseLocationRange_GetString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ParseLocationRange_GetString(
		arg0,
		arg1,
	)
}

func parser_ParseLocationRange_GetString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ParseLocationRange_GetString(arg0, arg1)
}

func ASTQueryStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTQueryStatement_query(
		arg0,
		arg1,
	)
}

func parser_ASTQueryStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTQueryStatement_query(arg0, arg1)
}

func ASTQueryExpression_set_parenthesized(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTQueryExpression_set_parenthesized(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTQueryExpression_set_parenthesized(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTQueryExpression_set_parenthesized(arg0, arg1)
}

func ASTQueryExpression_parenthesized(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTQueryExpression_parenthesized(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTQueryExpression_parenthesized(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTQueryExpression_parenthesized(arg0, arg1)
}

func ASTQuery_set_is_nested(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTQuery_set_is_nested(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTQuery_set_is_nested(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTQuery_set_is_nested(arg0, arg1)
}

func ASTQuery_is_nested(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTQuery_is_nested(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTQuery_is_nested(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTQuery_is_nested(arg0, arg1)
}

func ASTQuery_set_is_pivot_input(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTQuery_set_is_pivot_input(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTQuery_set_is_pivot_input(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTQuery_set_is_pivot_input(arg0, arg1)
}

func ASTQuery_is_pivot_input(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTQuery_is_pivot_input(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTQuery_is_pivot_input(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTQuery_is_pivot_input(arg0, arg1)
}

func ASTQuery_with_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTQuery_with_clause(
		arg0,
		arg1,
	)
}

func parser_ASTQuery_with_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTQuery_with_clause(arg0, arg1)
}

func ASTQuery_query_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTQuery_query_expr(
		arg0,
		arg1,
	)
}

func parser_ASTQuery_query_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTQuery_query_expr(arg0, arg1)
}

func ASTQuery_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTQuery_order_by(
		arg0,
		arg1,
	)
}

func parser_ASTQuery_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTQuery_order_by(arg0, arg1)
}

func ASTQuery_limit_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTQuery_limit_offset(
		arg0,
		arg1,
	)
}

func parser_ASTQuery_limit_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTQuery_limit_offset(arg0, arg1)
}

func ASTSelect_set_distinct(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTSelect_set_distinct(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTSelect_set_distinct(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTSelect_set_distinct(arg0, arg1)
}

func ASTSelect_distinct(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTSelect_distinct(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTSelect_distinct(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTSelect_distinct(arg0, arg1)
}

func ASTSelect_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSelect_hint(
		arg0,
		arg1,
	)
}

func parser_ASTSelect_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSelect_hint(arg0, arg1)
}

func ASTSelect_anonymization_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSelect_anonymization_options(
		arg0,
		arg1,
	)
}

func parser_ASTSelect_anonymization_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSelect_anonymization_options(arg0, arg1)
}

func ASTSelect_select_as(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSelect_select_as(
		arg0,
		arg1,
	)
}

func parser_ASTSelect_select_as(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSelect_select_as(arg0, arg1)
}

func ASTSelect_select_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSelect_select_list(
		arg0,
		arg1,
	)
}

func parser_ASTSelect_select_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSelect_select_list(arg0, arg1)
}

func ASTSelect_from_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSelect_from_clause(
		arg0,
		arg1,
	)
}

func parser_ASTSelect_from_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSelect_from_clause(arg0, arg1)
}

func ASTSelect_where_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSelect_where_clause(
		arg0,
		arg1,
	)
}

func parser_ASTSelect_where_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSelect_where_clause(arg0, arg1)
}

func ASTSelect_group_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSelect_group_by(
		arg0,
		arg1,
	)
}

func parser_ASTSelect_group_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSelect_group_by(arg0, arg1)
}

func ASTSelect_having(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSelect_having(
		arg0,
		arg1,
	)
}

func parser_ASTSelect_having(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSelect_having(arg0, arg1)
}

func ASTSelect_qualify(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSelect_qualify(
		arg0,
		arg1,
	)
}

func parser_ASTSelect_qualify(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSelect_qualify(arg0, arg1)
}

func ASTSelect_window_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSelect_window_clause(
		arg0,
		arg1,
	)
}

func parser_ASTSelect_window_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSelect_window_clause(arg0, arg1)
}

func ASTSelectList_column_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTSelectList_column_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTSelectList_column_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTSelectList_column_num(arg0, arg1)
}

func ASTSelectList_column(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTSelectList_column(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTSelectList_column(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSelectList_column(arg0, arg1, arg2)
}

func ASTSelectColumn_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSelectColumn_expression(
		arg0,
		arg1,
	)
}

func parser_ASTSelectColumn_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSelectColumn_expression(arg0, arg1)
}

func ASTSelectColumn_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSelectColumn_alias(
		arg0,
		arg1,
	)
}

func parser_ASTSelectColumn_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSelectColumn_alias(arg0, arg1)
}

func ASTExpression_set_parenthesized(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTExpression_set_parenthesized(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTExpression_set_parenthesized(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTExpression_set_parenthesized(arg0, arg1)
}

func ASTExpression_parenthesized(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTExpression_parenthesized(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTExpression_parenthesized(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTExpression_parenthesized(arg0, arg1)
}

func ASTExpression_IsAllowedInComparison(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTExpression_IsAllowedInComparison(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTExpression_IsAllowedInComparison(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTExpression_IsAllowedInComparison(arg0, arg1)
}

func ASTLeaf_image(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTLeaf_image(
		arg0,
		arg1,
	)
}

func parser_ASTLeaf_image(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTLeaf_image(arg0, arg1)
}

func ASTLeaf_set_image(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	parser_ASTLeaf_set_image(
		arg0,
		arg1,
	)
}

func parser_ASTLeaf_set_image(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTLeaf_set_image(arg0, arg1)
}

func ASTIntLiteral_is_hex(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTIntLiteral_is_hex(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTIntLiteral_is_hex(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTIntLiteral_is_hex(arg0, arg1)
}

func ASTIdentifier_GetAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTIdentifier_GetAsString(
		arg0,
		arg1,
	)
}

func parser_ASTIdentifier_GetAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTIdentifier_GetAsString(arg0, arg1)
}

func ASTIdentifier_SetIdentifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	parser_ASTIdentifier_SetIdentifier(
		arg0,
		arg1,
	)
}

func parser_ASTIdentifier_SetIdentifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTIdentifier_SetIdentifier(arg0, arg1)
}

func ASTAlias_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlias_identifier(
		arg0,
		arg1,
	)
}

func parser_ASTAlias_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlias_identifier(arg0, arg1)
}

func ASTAlias_GetAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlias_GetAsString(
		arg0,
		arg1,
	)
}

func parser_ASTAlias_GetAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlias_GetAsString(arg0, arg1)
}

func ASTPathExpression_num_names(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTPathExpression_num_names(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTPathExpression_num_names(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTPathExpression_num_names(arg0, arg1)
}

func ASTPathExpression_name(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTPathExpression_name(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTPathExpression_name(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPathExpression_name(arg0, arg1, arg2)
}

func ASTPathExpression_ToIdentifierPathString(arg0 unsafe.Pointer, arg1 uint32, arg2 *unsafe.Pointer) {
	parser_ASTPathExpression_ToIdentifierPathString(
		arg0,
		C.uint32_t(arg1),
		arg2,
	)
}

func parser_ASTPathExpression_ToIdentifierPathString(arg0 unsafe.Pointer, arg1 C.uint32_t, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPathExpression_ToIdentifierPathString(arg0, arg1, arg2)
}

func ASTTablePathExpression_path_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTablePathExpression_path_expr(
		arg0,
		arg1,
	)
}

func parser_ASTTablePathExpression_path_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTablePathExpression_path_expr(arg0, arg1)
}

func ASTTablePathExpression_unnest_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTablePathExpression_unnest_expr(
		arg0,
		arg1,
	)
}

func parser_ASTTablePathExpression_unnest_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTablePathExpression_unnest_expr(arg0, arg1)
}

func ASTTablePathExpression_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTablePathExpression_hint(
		arg0,
		arg1,
	)
}

func parser_ASTTablePathExpression_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTablePathExpression_hint(arg0, arg1)
}

func ASTTablePathExpression_with_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTablePathExpression_with_offset(
		arg0,
		arg1,
	)
}

func parser_ASTTablePathExpression_with_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTablePathExpression_with_offset(arg0, arg1)
}

func ASTTablePathExpression_pivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTablePathExpression_pivot_clause(
		arg0,
		arg1,
	)
}

func parser_ASTTablePathExpression_pivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTablePathExpression_pivot_clause(arg0, arg1)
}

func ASTTablePathExpression_unpivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTablePathExpression_unpivot_clause(
		arg0,
		arg1,
	)
}

func parser_ASTTablePathExpression_unpivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTablePathExpression_unpivot_clause(arg0, arg1)
}

func ASTTablePathExpression_for_system_time(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTablePathExpression_for_system_time(
		arg0,
		arg1,
	)
}

func parser_ASTTablePathExpression_for_system_time(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTablePathExpression_for_system_time(arg0, arg1)
}

func ASTTablePathExpression_sample_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTablePathExpression_sample_clause(
		arg0,
		arg1,
	)
}

func parser_ASTTablePathExpression_sample_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTablePathExpression_sample_clause(arg0, arg1)
}

func ASTTablePathExpression_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTablePathExpression_alias(
		arg0,
		arg1,
	)
}

func parser_ASTTablePathExpression_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTablePathExpression_alias(arg0, arg1)
}

func ASTFromClause_table_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFromClause_table_expression(
		arg0,
		arg1,
	)
}

func parser_ASTFromClause_table_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFromClause_table_expression(arg0, arg1)
}

func ASTWhereClause_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWhereClause_expression(
		arg0,
		arg1,
	)
}

func parser_ASTWhereClause_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWhereClause_expression(arg0, arg1)
}

func ASTBooleanLiteral_set_value(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTBooleanLiteral_set_value(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTBooleanLiteral_set_value(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTBooleanLiteral_set_value(arg0, arg1)
}

func ASTBooleanLiteral_value(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTBooleanLiteral_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTBooleanLiteral_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTBooleanLiteral_value(arg0, arg1)
}

func ASTAndExpr_conjuncts_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTAndExpr_conjuncts_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAndExpr_conjuncts_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTAndExpr_conjuncts_num(arg0, arg1)
}

func ASTAndExpr_conjunct(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTAndExpr_conjunct(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTAndExpr_conjunct(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAndExpr_conjunct(arg0, arg1, arg2)
}

func ASTBinaryExpression_set_op(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTBinaryExpression_set_op(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTBinaryExpression_set_op(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTBinaryExpression_set_op(arg0, arg1)
}

func ASTBinaryExpression_op(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTBinaryExpression_op(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTBinaryExpression_op(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTBinaryExpression_op(arg0, arg1)
}

func ASTBinaryExpression_set_is_not(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTBinaryExpression_set_is_not(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTBinaryExpression_set_is_not(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTBinaryExpression_set_is_not(arg0, arg1)
}

func ASTBinaryExpression_is_not(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTBinaryExpression_is_not(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTBinaryExpression_is_not(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTBinaryExpression_is_not(arg0, arg1)
}

func ASTBinaryExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTBinaryExpression_lhs(
		arg0,
		arg1,
	)
}

func parser_ASTBinaryExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTBinaryExpression_lhs(arg0, arg1)
}

func ASTBinaryExpression_rhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTBinaryExpression_rhs(
		arg0,
		arg1,
	)
}

func parser_ASTBinaryExpression_rhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTBinaryExpression_rhs(arg0, arg1)
}

func ASTBinaryExpression_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTBinaryExpression_GetSQLForOperator(
		arg0,
		arg1,
	)
}

func parser_ASTBinaryExpression_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTBinaryExpression_GetSQLForOperator(arg0, arg1)
}

func ASTStringLiteral_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTStringLiteral_string_value(
		arg0,
		arg1,
	)
}

func parser_ASTStringLiteral_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStringLiteral_string_value(arg0, arg1)
}

func ASTStringLiteral_set_string_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	parser_ASTStringLiteral_set_string_value(
		arg0,
		arg1,
	)
}

func parser_ASTStringLiteral_set_string_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStringLiteral_set_string_value(arg0, arg1)
}

func ASTOrExpr_disjuncts_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTOrExpr_disjuncts_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTOrExpr_disjuncts_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTOrExpr_disjuncts_num(arg0, arg1)
}

func ASTOrExpr_disjunct(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTOrExpr_disjunct(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTOrExpr_disjunct(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTOrExpr_disjunct(arg0, arg1, arg2)
}

func ASTGroupingItem_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTGroupingItem_expression(
		arg0,
		arg1,
	)
}

func parser_ASTGroupingItem_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTGroupingItem_expression(arg0, arg1)
}

func ASTGroupingItem_rollup(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTGroupingItem_rollup(
		arg0,
		arg1,
	)
}

func parser_ASTGroupingItem_rollup(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTGroupingItem_rollup(arg0, arg1)
}

func ASTGroupBy_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTGroupBy_hint(
		arg0,
		arg1,
	)
}

func parser_ASTGroupBy_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTGroupBy_hint(arg0, arg1)
}

func ASTGroupBy_grouping_items_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTGroupBy_grouping_items_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTGroupBy_grouping_items_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTGroupBy_grouping_items_num(arg0, arg1)
}

func ASTGroupBy_grouping_item(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTGroupBy_grouping_item(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTGroupBy_grouping_item(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTGroupBy_grouping_item(arg0, arg1, arg2)
}

func ASTOrderingExpression_set_ordering_spec(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTOrderingExpression_set_ordering_spec(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTOrderingExpression_set_ordering_spec(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTOrderingExpression_set_ordering_spec(arg0, arg1)
}

func ASTOrderingExpression_ordering_spec(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTOrderingExpression_ordering_spec(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTOrderingExpression_ordering_spec(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTOrderingExpression_ordering_spec(arg0, arg1)
}

func ASTOrderingExpression_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTOrderingExpression_expression(
		arg0,
		arg1,
	)
}

func parser_ASTOrderingExpression_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTOrderingExpression_expression(arg0, arg1)
}

func ASTOrderingExpression_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTOrderingExpression_collate(
		arg0,
		arg1,
	)
}

func parser_ASTOrderingExpression_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTOrderingExpression_collate(arg0, arg1)
}

func ASTOrderingExpression_null_order(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTOrderingExpression_null_order(
		arg0,
		arg1,
	)
}

func parser_ASTOrderingExpression_null_order(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTOrderingExpression_null_order(arg0, arg1)
}

func ASTOrderBy_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTOrderBy_hint(
		arg0,
		arg1,
	)
}

func parser_ASTOrderBy_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTOrderBy_hint(arg0, arg1)
}

func ASTOrderBy_ordering_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTOrderBy_ordering_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTOrderBy_ordering_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTOrderBy_ordering_expressions_num(arg0, arg1)
}

func ASTOrderBy_ordering_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTOrderBy_ordering_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTOrderBy_ordering_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTOrderBy_ordering_expression(arg0, arg1, arg2)
}

func ASTLimitOffset_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTLimitOffset_limit(
		arg0,
		arg1,
	)
}

func parser_ASTLimitOffset_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTLimitOffset_limit(arg0, arg1)
}

func ASTLimitOffset_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTLimitOffset_offset(
		arg0,
		arg1,
	)
}

func parser_ASTLimitOffset_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTLimitOffset_offset(arg0, arg1)
}

func ASTOnClause_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTOnClause_expression(
		arg0,
		arg1,
	)
}

func parser_ASTOnClause_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTOnClause_expression(arg0, arg1)
}

func ASTWithClauseEntry_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWithClauseEntry_alias(
		arg0,
		arg1,
	)
}

func parser_ASTWithClauseEntry_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWithClauseEntry_alias(arg0, arg1)
}

func ASTWithClauseEntry_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWithClauseEntry_query(
		arg0,
		arg1,
	)
}

func parser_ASTWithClauseEntry_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWithClauseEntry_query(arg0, arg1)
}

func ASTJoin_set_join_type(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTJoin_set_join_type(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTJoin_set_join_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTJoin_set_join_type(arg0, arg1)
}

func ASTJoin_join_type(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTJoin_join_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTJoin_join_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTJoin_join_type(arg0, arg1)
}

func ASTJoin_set_join_hint(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTJoin_set_join_hint(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTJoin_set_join_hint(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTJoin_set_join_hint(arg0, arg1)
}

func ASTJoin_join_hint(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTJoin_join_hint(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTJoin_join_hint(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTJoin_join_hint(arg0, arg1)
}

func ASTJoin_set_natural(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTJoin_set_natural(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTJoin_set_natural(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTJoin_set_natural(arg0, arg1)
}

func ASTJoin_natural(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTJoin_natural(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTJoin_natural(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTJoin_natural(arg0, arg1)
}

func ASTJoin_set_unmatched_join_count(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTJoin_set_unmatched_join_count(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTJoin_set_unmatched_join_count(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTJoin_set_unmatched_join_count(arg0, arg1)
}

func ASTJoin_unmatched_join_count(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTJoin_unmatched_join_count(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTJoin_unmatched_join_count(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTJoin_unmatched_join_count(arg0, arg1)
}

func ASTJoin_set_transformation_needed(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTJoin_set_transformation_needed(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTJoin_set_transformation_needed(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTJoin_set_transformation_needed(arg0, arg1)
}

func ASTJoin_transformation_needed(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTJoin_transformation_needed(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTJoin_transformation_needed(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTJoin_transformation_needed(arg0, arg1)
}

func ASTJoin_set_contains_comma_join(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTJoin_set_contains_comma_join(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTJoin_set_contains_comma_join(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTJoin_set_contains_comma_join(arg0, arg1)
}

func ASTJoin_contains_comma_join(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTJoin_contains_comma_join(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTJoin_contains_comma_join(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTJoin_contains_comma_join(arg0, arg1)
}

func ASTJoin_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTJoin_lhs(
		arg0,
		arg1,
	)
}

func parser_ASTJoin_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTJoin_lhs(arg0, arg1)
}

func ASTJoin_rhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTJoin_rhs(
		arg0,
		arg1,
	)
}

func parser_ASTJoin_rhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTJoin_rhs(arg0, arg1)
}

func ASTJoin_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTJoin_hint(
		arg0,
		arg1,
	)
}

func parser_ASTJoin_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTJoin_hint(arg0, arg1)
}

func ASTJoin_on_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTJoin_on_clause(
		arg0,
		arg1,
	)
}

func parser_ASTJoin_on_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTJoin_on_clause(arg0, arg1)
}

func ASTJoin_using_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTJoin_using_clause(
		arg0,
		arg1,
	)
}

func parser_ASTJoin_using_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTJoin_using_clause(arg0, arg1)
}

func JoinParseError_error_node(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_JoinParseError_error_node(
		arg0,
		arg1,
	)
}

func parser_JoinParseError_error_node(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_JoinParseError_error_node(arg0, arg1)
}

func JoinParseError_message(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_JoinParseError_message(
		arg0,
		arg1,
	)
}

func parser_JoinParseError_message(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_JoinParseError_message(arg0, arg1)
}

func ASTJoin_parse_error(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTJoin_parse_error(
		arg0,
		arg1,
	)
}

func parser_ASTJoin_parse_error(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTJoin_parse_error(arg0, arg1)
}

func ASTJoin_GetSQLForJoinType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTJoin_GetSQLForJoinType(
		arg0,
		arg1,
	)
}

func parser_ASTJoin_GetSQLForJoinType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTJoin_GetSQLForJoinType(arg0, arg1)
}

func ASTJoin_GetSQLForJoinHint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTJoin_GetSQLForJoinHint(
		arg0,
		arg1,
	)
}

func parser_ASTJoin_GetSQLForJoinHint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTJoin_GetSQLForJoinHint(arg0, arg1)
}

func ASTWithClause_set_recursive(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTWithClause_set_recursive(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTWithClause_set_recursive(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTWithClause_set_recursive(arg0, arg1)
}

func ASTWithClause_recursive(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTWithClause_recursive(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTWithClause_recursive(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTWithClause_recursive(arg0, arg1)
}

func ASTWithClause_with_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTWithClause_with_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTWithClause_with_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTWithClause_with_num(arg0, arg1)
}

func ASTWithClause_with(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTWithClause_with(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTWithClause_with(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWithClause_with(arg0, arg1, arg2)
}

func ASTHaving_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTHaving_expression(
		arg0,
		arg1,
	)
}

func parser_ASTHaving_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTHaving_expression(arg0, arg1)
}

func ASTType_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTType_type_parameters(
		arg0,
		arg1,
	)
}

func parser_ASTType_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTType_type_parameters(arg0, arg1)
}

func ASTType_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTType_collate(
		arg0,
		arg1,
	)
}

func parser_ASTType_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTType_collate(arg0, arg1)
}

func ASTSimpleType_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSimpleType_type_name(
		arg0,
		arg1,
	)
}

func parser_ASTSimpleType_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSimpleType_type_name(arg0, arg1)
}

func ASTArrayType_element_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTArrayType_element_type(
		arg0,
		arg1,
	)
}

func parser_ASTArrayType_element_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTArrayType_element_type(arg0, arg1)
}

func ASTStructField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTStructField_name(
		arg0,
		arg1,
	)
}

func parser_ASTStructField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStructField_name(arg0, arg1)
}

func ASTStructField_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTStructField_type(
		arg0,
		arg1,
	)
}

func parser_ASTStructField_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStructField_type(arg0, arg1)
}

func ASTStructType_struct_fields_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTStructType_struct_fields_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTStructType_struct_fields_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTStructType_struct_fields_num(arg0, arg1)
}

func ASTStructType_struct_field(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTStructType_struct_field(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTStructType_struct_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStructType_struct_field(arg0, arg1, arg2)
}

func ASTCastExpression_set_is_safe_cast(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTCastExpression_set_is_safe_cast(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTCastExpression_set_is_safe_cast(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTCastExpression_set_is_safe_cast(arg0, arg1)
}

func ASTCastExpression_is_safe_cast(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTCastExpression_is_safe_cast(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCastExpression_is_safe_cast(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTCastExpression_is_safe_cast(arg0, arg1)
}

func ASTCastExpression_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCastExpression_expr(
		arg0,
		arg1,
	)
}

func parser_ASTCastExpression_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCastExpression_expr(arg0, arg1)
}

func ASTCastExpression_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCastExpression_type(
		arg0,
		arg1,
	)
}

func parser_ASTCastExpression_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCastExpression_type(arg0, arg1)
}

func ASTCastExpression_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCastExpression_format(
		arg0,
		arg1,
	)
}

func parser_ASTCastExpression_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCastExpression_format(arg0, arg1)
}

func ASTSelectAs_set_as_mode(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTSelectAs_set_as_mode(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTSelectAs_set_as_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTSelectAs_set_as_mode(arg0, arg1)
}

func ASTSelectAs_as_mode(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTSelectAs_as_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTSelectAs_as_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTSelectAs_as_mode(arg0, arg1)
}

func ASTSelectAs_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSelectAs_type_name(
		arg0,
		arg1,
	)
}

func parser_ASTSelectAs_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSelectAs_type_name(arg0, arg1)
}

func ASTSelectAs_is_select_as_struct(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTSelectAs_is_select_as_struct(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTSelectAs_is_select_as_struct(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTSelectAs_is_select_as_struct(arg0, arg1)
}

func ASTSelectAs_is_select_as_value(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTSelectAs_is_select_as_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTSelectAs_is_select_as_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTSelectAs_is_select_as_value(arg0, arg1)
}

func ASTRollup_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTRollup_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTRollup_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTRollup_expressions_num(arg0, arg1)
}

func ASTRollup_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTRollup_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTRollup_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRollup_expression(arg0, arg1, arg2)
}

func ASTFunctionCall_set_null_handling_modifier(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTFunctionCall_set_null_handling_modifier(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTFunctionCall_set_null_handling_modifier(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTFunctionCall_set_null_handling_modifier(arg0, arg1)
}

func ASTFunctionCall_null_handling_modifier(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTFunctionCall_null_handling_modifier(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTFunctionCall_null_handling_modifier(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTFunctionCall_null_handling_modifier(arg0, arg1)
}

func ASTFunctionCall_set_distinct(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTFunctionCall_set_distinct(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTFunctionCall_set_distinct(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTFunctionCall_set_distinct(arg0, arg1)
}

func ASTFunctionCall_distinct(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTFunctionCall_distinct(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTFunctionCall_distinct(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTFunctionCall_distinct(arg0, arg1)
}

func ASTFunctionCall_set_is_current_date_time_without_parentheses(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTFunctionCall_set_is_current_date_time_without_parentheses(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTFunctionCall_set_is_current_date_time_without_parentheses(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTFunctionCall_set_is_current_date_time_without_parentheses(arg0, arg1)
}

func ASTFunctionCall_is_current_date_time_without_parentheses(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTFunctionCall_is_current_date_time_without_parentheses(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTFunctionCall_is_current_date_time_without_parentheses(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTFunctionCall_is_current_date_time_without_parentheses(arg0, arg1)
}

func ASTFunctionCall_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionCall_function(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionCall_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionCall_function(arg0, arg1)
}

func ASTFunctionCall_having_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionCall_having_modifier(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionCall_having_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionCall_having_modifier(arg0, arg1)
}

func ASTFunctionCall_clamped_between_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionCall_clamped_between_modifier(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionCall_clamped_between_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionCall_clamped_between_modifier(arg0, arg1)
}

func ASTFunctionCall_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionCall_order_by(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionCall_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionCall_order_by(arg0, arg1)
}

func ASTFunctionCall_limit_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionCall_limit_offset(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionCall_limit_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionCall_limit_offset(arg0, arg1)
}

func ASTFunctionCall_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionCall_hint(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionCall_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionCall_hint(arg0, arg1)
}

func ASTFunctionCall_with_group_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionCall_with_group_rows(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionCall_with_group_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionCall_with_group_rows(arg0, arg1)
}

func ASTFunctionCall_arguments_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTFunctionCall_arguments_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTFunctionCall_arguments_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTFunctionCall_arguments_num(arg0, arg1)
}

func ASTFunctionCall_argument(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTFunctionCall_argument(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTFunctionCall_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionCall_argument(arg0, arg1, arg2)
}

func ASTFunctionCall_HasModifiers(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTFunctionCall_HasModifiers(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTFunctionCall_HasModifiers(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTFunctionCall_HasModifiers(arg0, arg1)
}

func ASTArrayConstructor_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTArrayConstructor_type(
		arg0,
		arg1,
	)
}

func parser_ASTArrayConstructor_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTArrayConstructor_type(arg0, arg1)
}

func ASTArrayConstructor_elements_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTArrayConstructor_elements_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTArrayConstructor_elements_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTArrayConstructor_elements_num(arg0, arg1)
}

func ASTArrayConstructor_element(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTArrayConstructor_element(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTArrayConstructor_element(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTArrayConstructor_element(arg0, arg1, arg2)
}

func ASTStructConstructorArg_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTStructConstructorArg_expression(
		arg0,
		arg1,
	)
}

func parser_ASTStructConstructorArg_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStructConstructorArg_expression(arg0, arg1)
}

func ASTStructConstructorArg_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTStructConstructorArg_alias(
		arg0,
		arg1,
	)
}

func parser_ASTStructConstructorArg_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStructConstructorArg_alias(arg0, arg1)
}

func ASTStructConstructorWithParens_field_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTStructConstructorWithParens_field_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTStructConstructorWithParens_field_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTStructConstructorWithParens_field_expressions_num(arg0, arg1)
}

func ASTStructConstructorWithParens_field_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTStructConstructorWithParens_field_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTStructConstructorWithParens_field_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStructConstructorWithParens_field_expression(arg0, arg1, arg2)
}

func ASTStructConstructorWithKeyword_struct_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTStructConstructorWithKeyword_struct_type(
		arg0,
		arg1,
	)
}

func parser_ASTStructConstructorWithKeyword_struct_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStructConstructorWithKeyword_struct_type(arg0, arg1)
}

func ASTStructConstructorWithKeyword_fields_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTStructConstructorWithKeyword_fields_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTStructConstructorWithKeyword_fields_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTStructConstructorWithKeyword_fields_num(arg0, arg1)
}

func ASTStructConstructorWithKeyword_field(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTStructConstructorWithKeyword_field(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTStructConstructorWithKeyword_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStructConstructorWithKeyword_field(arg0, arg1, arg2)
}

func ASTInExpression_set_is_not(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTInExpression_set_is_not(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTInExpression_set_is_not(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTInExpression_set_is_not(arg0, arg1)
}

func ASTInExpression_is_not(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTInExpression_is_not(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTInExpression_is_not(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTInExpression_is_not(arg0, arg1)
}

func ASTInExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTInExpression_lhs(
		arg0,
		arg1,
	)
}

func parser_ASTInExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTInExpression_lhs(arg0, arg1)
}

func ASTInExpression_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTInExpression_hint(
		arg0,
		arg1,
	)
}

func parser_ASTInExpression_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTInExpression_hint(arg0, arg1)
}

func ASTInExpression_in_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTInExpression_in_list(
		arg0,
		arg1,
	)
}

func parser_ASTInExpression_in_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTInExpression_in_list(arg0, arg1)
}

func ASTInExpression_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTInExpression_query(
		arg0,
		arg1,
	)
}

func parser_ASTInExpression_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTInExpression_query(arg0, arg1)
}

func ASTInExpression_unnest_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTInExpression_unnest_expr(
		arg0,
		arg1,
	)
}

func parser_ASTInExpression_unnest_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTInExpression_unnest_expr(arg0, arg1)
}

func ASTInList_list_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTInList_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTInList_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTInList_list_num(arg0, arg1)
}

func ASTInList_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTInList_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTInList_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTInList_list(arg0, arg1, arg2)
}

func ASTBetweenExpression_set_is_not(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTBetweenExpression_set_is_not(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTBetweenExpression_set_is_not(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTBetweenExpression_set_is_not(arg0, arg1)
}

func ASTBetweenExpression_is_not(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTBetweenExpression_is_not(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTBetweenExpression_is_not(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTBetweenExpression_is_not(arg0, arg1)
}

func ASTBetweenExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTBetweenExpression_lhs(
		arg0,
		arg1,
	)
}

func parser_ASTBetweenExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTBetweenExpression_lhs(arg0, arg1)
}

func ASTBetweenExpression_low(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTBetweenExpression_low(
		arg0,
		arg1,
	)
}

func parser_ASTBetweenExpression_low(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTBetweenExpression_low(arg0, arg1)
}

func ASTBetweenExpression_high(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTBetweenExpression_high(
		arg0,
		arg1,
	)
}

func parser_ASTBetweenExpression_high(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTBetweenExpression_high(arg0, arg1)
}

func ASTDateOrTimeLiteral_set_type_kind(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDateOrTimeLiteral_set_type_kind(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDateOrTimeLiteral_set_type_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDateOrTimeLiteral_set_type_kind(arg0, arg1)
}

func ASTDateOrTimeLiteral_type_kind(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTDateOrTimeLiteral_type_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDateOrTimeLiteral_type_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTDateOrTimeLiteral_type_kind(arg0, arg1)
}

func ASTDateOrTimeLiteral_string_literal(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDateOrTimeLiteral_string_literal(
		arg0,
		arg1,
	)
}

func parser_ASTDateOrTimeLiteral_string_literal(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDateOrTimeLiteral_string_literal(arg0, arg1)
}

func ASTCaseValueExpression_arguments_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTCaseValueExpression_arguments_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCaseValueExpression_arguments_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTCaseValueExpression_arguments_num(arg0, arg1)
}

func ASTCaseValueExpression_argument(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTCaseValueExpression_argument(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTCaseValueExpression_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCaseValueExpression_argument(arg0, arg1, arg2)
}

func ASTCaseNoValueExpression_arguments_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTCaseNoValueExpression_arguments_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCaseNoValueExpression_arguments_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTCaseNoValueExpression_arguments_num(arg0, arg1)
}

func ASTCaseNoValueExpression_argument(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTCaseNoValueExpression_argument(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTCaseNoValueExpression_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCaseNoValueExpression_argument(arg0, arg1, arg2)
}

func ASTArrayElement_array(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTArrayElement_array(
		arg0,
		arg1,
	)
}

func parser_ASTArrayElement_array(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTArrayElement_array(arg0, arg1)
}

func ASTArrayElement_position(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTArrayElement_position(
		arg0,
		arg1,
	)
}

func parser_ASTArrayElement_position(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTArrayElement_position(arg0, arg1)
}

func ASTBitwiseShiftExpression_set_is_left_shift(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTBitwiseShiftExpression_set_is_left_shift(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTBitwiseShiftExpression_set_is_left_shift(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTBitwiseShiftExpression_set_is_left_shift(arg0, arg1)
}

func ASTBitwiseShiftExpression_is_left_shift(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTBitwiseShiftExpression_is_left_shift(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTBitwiseShiftExpression_is_left_shift(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTBitwiseShiftExpression_is_left_shift(arg0, arg1)
}

func ASTBitwiseShiftExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTBitwiseShiftExpression_lhs(
		arg0,
		arg1,
	)
}

func parser_ASTBitwiseShiftExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTBitwiseShiftExpression_lhs(arg0, arg1)
}

func ASTBitwiseShiftExpression_rhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTBitwiseShiftExpression_rhs(
		arg0,
		arg1,
	)
}

func parser_ASTBitwiseShiftExpression_rhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTBitwiseShiftExpression_rhs(arg0, arg1)
}

func ASTCollate_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCollate_collation_name(
		arg0,
		arg1,
	)
}

func parser_ASTCollate_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCollate_collation_name(arg0, arg1)
}

func ASTDotGeneralizedField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDotGeneralizedField_expr(
		arg0,
		arg1,
	)
}

func parser_ASTDotGeneralizedField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDotGeneralizedField_expr(arg0, arg1)
}

func ASTDotGeneralizedField_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDotGeneralizedField_path(
		arg0,
		arg1,
	)
}

func parser_ASTDotGeneralizedField_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDotGeneralizedField_path(arg0, arg1)
}

func ASTDotIdentifier_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDotIdentifier_expr(
		arg0,
		arg1,
	)
}

func parser_ASTDotIdentifier_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDotIdentifier_expr(arg0, arg1)
}

func ASTDotIdentifier_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDotIdentifier_name(
		arg0,
		arg1,
	)
}

func parser_ASTDotIdentifier_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDotIdentifier_name(arg0, arg1)
}

func ASTDotStar_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDotStar_expr(
		arg0,
		arg1,
	)
}

func parser_ASTDotStar_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDotStar_expr(arg0, arg1)
}

func ASTDotStarWithModifiers_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDotStarWithModifiers_expr(
		arg0,
		arg1,
	)
}

func parser_ASTDotStarWithModifiers_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDotStarWithModifiers_expr(arg0, arg1)
}

func ASTDotStarWithModifiers_modifiers(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDotStarWithModifiers_modifiers(
		arg0,
		arg1,
	)
}

func parser_ASTDotStarWithModifiers_modifiers(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDotStarWithModifiers_modifiers(arg0, arg1)
}

func ASTExpressionSubquery_set_modifier(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTExpressionSubquery_set_modifier(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTExpressionSubquery_set_modifier(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTExpressionSubquery_set_modifier(arg0, arg1)
}

func ASTExpressionSubquery_modifier(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTExpressionSubquery_modifier(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTExpressionSubquery_modifier(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTExpressionSubquery_modifier(arg0, arg1)
}

func ASTExpressionSubquery_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExpressionSubquery_hint(
		arg0,
		arg1,
	)
}

func parser_ASTExpressionSubquery_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExpressionSubquery_hint(arg0, arg1)
}

func ASTExpressionSubquery_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExpressionSubquery_query(
		arg0,
		arg1,
	)
}

func parser_ASTExpressionSubquery_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExpressionSubquery_query(arg0, arg1)
}

func ASTExtractExpression_lhs_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExtractExpression_lhs_expr(
		arg0,
		arg1,
	)
}

func parser_ASTExtractExpression_lhs_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExtractExpression_lhs_expr(arg0, arg1)
}

func ASTExtractExpression_rhs_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExtractExpression_rhs_expr(
		arg0,
		arg1,
	)
}

func parser_ASTExtractExpression_rhs_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExtractExpression_rhs_expr(arg0, arg1)
}

func ASTExtractExpression_time_zone_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExtractExpression_time_zone_expr(
		arg0,
		arg1,
	)
}

func parser_ASTExtractExpression_time_zone_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExtractExpression_time_zone_expr(arg0, arg1)
}

func ASTHavingModifier_set_modifier_kind(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTHavingModifier_set_modifier_kind(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTHavingModifier_set_modifier_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTHavingModifier_set_modifier_kind(arg0, arg1)
}

func ASTHavingModifier_modifier_kind(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTHavingModifier_modifier_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTHavingModifier_modifier_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTHavingModifier_modifier_kind(arg0, arg1)
}

func ASTHavingModifier_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTHavingModifier_expr(
		arg0,
		arg1,
	)
}

func parser_ASTHavingModifier_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTHavingModifier_expr(arg0, arg1)
}

func ASTIntervalExpr_interval_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTIntervalExpr_interval_value(
		arg0,
		arg1,
	)
}

func parser_ASTIntervalExpr_interval_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTIntervalExpr_interval_value(arg0, arg1)
}

func ASTIntervalExpr_date_part_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTIntervalExpr_date_part_name(
		arg0,
		arg1,
	)
}

func parser_ASTIntervalExpr_date_part_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTIntervalExpr_date_part_name(arg0, arg1)
}

func ASTIntervalExpr_date_part_name_to(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTIntervalExpr_date_part_name_to(
		arg0,
		arg1,
	)
}

func parser_ASTIntervalExpr_date_part_name_to(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTIntervalExpr_date_part_name_to(arg0, arg1)
}

func ASTNamedArgument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTNamedArgument_name(
		arg0,
		arg1,
	)
}

func parser_ASTNamedArgument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNamedArgument_name(arg0, arg1)
}

func ASTNamedArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTNamedArgument_expr(
		arg0,
		arg1,
	)
}

func parser_ASTNamedArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNamedArgument_expr(arg0, arg1)
}

func ASTNullOrder_set_nulls_first(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTNullOrder_set_nulls_first(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTNullOrder_set_nulls_first(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTNullOrder_set_nulls_first(arg0, arg1)
}

func ASTNullOrder_nulls_first(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTNullOrder_nulls_first(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNullOrder_nulls_first(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTNullOrder_nulls_first(arg0, arg1)
}

func ASTOnOrUsingClauseList_on_or_using_clause_list_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTOnOrUsingClauseList_on_or_using_clause_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTOnOrUsingClauseList_on_or_using_clause_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTOnOrUsingClauseList_on_or_using_clause_list_num(arg0, arg1)
}

func ASTOnUsingClauseList_on_or_using_clause_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTOnUsingClauseList_on_or_using_clause_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTOnUsingClauseList_on_or_using_clause_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTOnUsingClauseList_on_or_using_clause_list(arg0, arg1, arg2)
}

func ASTParenthesizedJoin_join(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTParenthesizedJoin_join(
		arg0,
		arg1,
	)
}

func parser_ASTParenthesizedJoin_join(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTParenthesizedJoin_join(arg0, arg1)
}

func ASTParenthesizedJoin_sample_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTParenthesizedJoin_sample_clause(
		arg0,
		arg1,
	)
}

func parser_ASTParenthesizedJoin_sample_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTParenthesizedJoin_sample_clause(arg0, arg1)
}

func ASTPartitionBy_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTPartitionBy_hint(
		arg0,
		arg1,
	)
}

func parser_ASTPartitionBy_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPartitionBy_hint(arg0, arg1)
}

func ASTPartitionBy_partitioning_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTPartitionBy_partitioning_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTPartitionBy_partitioning_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTPartitionBy_partitioning_expressions_num(arg0, arg1)
}

func ASTPartitionBy_partitioning_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTPartitionBy_partitioning_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTPartitionBy_partitioning_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPartitionBy_partitioning_expression(arg0, arg1, arg2)
}

func ASTSetOperation_set_op_type(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTSetOperation_set_op_type(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTSetOperation_set_op_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTSetOperation_set_op_type(arg0, arg1)
}

func ASTSetOperation_op_type(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTSetOperation_op_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTSetOperation_op_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTSetOperation_op_type(arg0, arg1)
}

func ASTSetOperation_set_distinct(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTSetOperation_set_distinct(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTSetOperation_set_distinct(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTSetOperation_set_distinct(arg0, arg1)
}

func ASTSetOperation_distinct(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTSetOperation_distinct(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTSetOperation_distinct(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTSetOperation_distinct(arg0, arg1)
}

func ASTSetOperation_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSetOperation_hint(
		arg0,
		arg1,
	)
}

func parser_ASTSetOperation_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSetOperation_hint(arg0, arg1)
}

func ASTSetOperation_inputs_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTSetOperation_inputs_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTSetOperation_inputs_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTSetOperation_inputs_num(arg0, arg1)
}

func ASTSetOperation_input(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTSetOperation_input(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTSetOperation_input(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSetOperation_input(arg0, arg1, arg2)
}

func ASTSetOperation_GetSQLForOperation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSetOperation_GetSQLForOperation(
		arg0,
		arg1,
	)
}

func parser_ASTSetOperation_GetSQLForOperation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSetOperation_GetSQLForOperation(arg0, arg1)
}

func ASTStarExceptList_identifiers_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTStarExceptList_identifiers_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTStarExceptList_identifiers_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTStarExceptList_identifiers_num(arg0, arg1)
}

func ASTStarExpcetList_identifier(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTStarExpcetList_identifier(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTStarExpcetList_identifier(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStarExpcetList_identifier(arg0, arg1, arg2)
}

func ASTStarModifiers_except_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTStarModifiers_except_list(
		arg0,
		arg1,
	)
}

func parser_ASTStarModifiers_except_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStarModifiers_except_list(arg0, arg1)
}

func ASTStarModifiers_replace_items_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTStarModifiers_replace_items_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTStarModifiers_replace_items_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTStarModifiers_replace_items_num(arg0, arg1)
}

func ASTStarModifiers_replace_item(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTStarModifiers_replace_item(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTStarModifiers_replace_item(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStarModifiers_replace_item(arg0, arg1, arg2)
}

func ASTStarReplaceItem_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTStarReplaceItem_expression(
		arg0,
		arg1,
	)
}

func parser_ASTStarReplaceItem_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStarReplaceItem_expression(arg0, arg1)
}

func ASTStarReplaceItem_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTStarReplaceItem_alias(
		arg0,
		arg1,
	)
}

func parser_ASTStarReplaceItem_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStarReplaceItem_alias(arg0, arg1)
}

func ASTStarWithModifiers_modifiers(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTStarWithModifiers_modifiers(
		arg0,
		arg1,
	)
}

func parser_ASTStarWithModifiers_modifiers(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStarWithModifiers_modifiers(arg0, arg1)
}

func ASTTableSubquery_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTableSubquery_subquery(
		arg0,
		arg1,
	)
}

func parser_ASTTableSubquery_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTableSubquery_subquery(arg0, arg1)
}

func ASTTableSubquery_pivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTableSubquery_pivot_clause(
		arg0,
		arg1,
	)
}

func parser_ASTTableSubquery_pivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTableSubquery_pivot_clause(arg0, arg1)
}

func ASTTableSubquery_unpivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTableSubquery_unpivot_clause(
		arg0,
		arg1,
	)
}

func parser_ASTTableSubquery_unpivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTableSubquery_unpivot_clause(arg0, arg1)
}

func ASTTableSubquery_sample_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTableSubquery_sample_clause(
		arg0,
		arg1,
	)
}

func parser_ASTTableSubquery_sample_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTableSubquery_sample_clause(arg0, arg1)
}

func ASTTableSubquery_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTableSubquery_alias(
		arg0,
		arg1,
	)
}

func parser_ASTTableSubquery_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTableSubquery_alias(arg0, arg1)
}

func ASTUnaryExpression_set_op(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTUnaryExpression_set_op(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTUnaryExpression_set_op(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTUnaryExpression_set_op(arg0, arg1)
}

func ASTUnaryExpression_op(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTUnaryExpression_op(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTUnaryExpression_op(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTUnaryExpression_op(arg0, arg1)
}

func ASTUnaryExpression_operand(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUnaryExpression_operand(
		arg0,
		arg1,
	)
}

func parser_ASTUnaryExpression_operand(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUnaryExpression_operand(arg0, arg1)
}

func ASTUnaryExpression_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUnaryExpression_GetSQLForOperator(
		arg0,
		arg1,
	)
}

func parser_ASTUnaryExpression_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUnaryExpression_GetSQLForOperator(arg0, arg1)
}

func ASTUnnestExpression_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUnnestExpression_expression(
		arg0,
		arg1,
	)
}

func parser_ASTUnnestExpression_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUnnestExpression_expression(arg0, arg1)
}

func ASTWindowClause_windows_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTWindowClause_windows_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTWindowClause_windows_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTWindowClause_windows_num(arg0, arg1)
}

func ASTWindowClause_window(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTWindowClause_window(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTWindowClause_window(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWindowClause_window(arg0, arg1, arg2)
}

func ASTWindowDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWindowDefinition_name(
		arg0,
		arg1,
	)
}

func parser_ASTWindowDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWindowDefinition_name(arg0, arg1)
}

func ASTWindowDefinition_window_spec(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWindowDefinition_window_spec(
		arg0,
		arg1,
	)
}

func parser_ASTWindowDefinition_window_spec(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWindowDefinition_window_spec(arg0, arg1)
}

func ASTWindowFrame_start_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWindowFrame_start_expr(
		arg0,
		arg1,
	)
}

func parser_ASTWindowFrame_start_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWindowFrame_start_expr(arg0, arg1)
}

func ASTWindowFrame_end_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWindowFrame_end_expr(
		arg0,
		arg1,
	)
}

func parser_ASTWindowFrame_end_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWindowFrame_end_expr(arg0, arg1)
}

func ASTWindowFrame_set_unit(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTWindowFrame_set_unit(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTWindowFrame_set_unit(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTWindowFrame_set_unit(arg0, arg1)
}

func ASTWindowFrame_frame_unit(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTWindowFrame_frame_unit(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTWindowFrame_frame_unit(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTWindowFrame_frame_unit(arg0, arg1)
}

func ASTWindowFrame_GetFrameUnitString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWindowFrame_GetFrameUnitString(
		arg0,
		arg1,
	)
}

func parser_ASTWindowFrame_GetFrameUnitString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWindowFrame_GetFrameUnitString(arg0, arg1)
}

func ASTWindowFrameExpr_set_boundary_type(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTWindowFrameExpr_set_boundary_type(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTWindowFrameExpr_set_boundary_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTWindowFrameExpr_set_boundary_type(arg0, arg1)
}

func ASTWindowFrameExpr_boundary_type(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTWindowFrameExpr_boundary_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTWindowFrameExpr_boundary_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTWindowFrameExpr_boundary_type(arg0, arg1)
}

func ASTWindowFrameExpr_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWindowFrameExpr_expression(
		arg0,
		arg1,
	)
}

func parser_ASTWindowFrameExpr_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWindowFrameExpr_expression(arg0, arg1)
}

func ASTLikeExpression_set_is_not(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTLikeExpression_set_is_not(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTLikeExpression_set_is_not(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTLikeExpression_set_is_not(arg0, arg1)
}

func ASTLikeExpression_is_not(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTLikeExpression_is_not(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTLikeExpression_is_not(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTLikeExpression_is_not(arg0, arg1)
}

func ASTLikeExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTLikeExpression_lhs(
		arg0,
		arg1,
	)
}

func parser_ASTLikeExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTLikeExpression_lhs(arg0, arg1)
}

func ASTLikeExpression_op(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTLikeExpression_op(
		arg0,
		arg1,
	)
}

func parser_ASTLikeExpression_op(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTLikeExpression_op(arg0, arg1)
}

func ASTLikeExpression_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTLikeExpression_hint(
		arg0,
		arg1,
	)
}

func parser_ASTLikeExpression_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTLikeExpression_hint(arg0, arg1)
}

func ASTLikeExpression_in_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTLikeExpression_in_list(
		arg0,
		arg1,
	)
}

func parser_ASTLikeExpression_in_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTLikeExpression_in_list(arg0, arg1)
}

func ASTLikeExpression_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTLikeExpression_query(
		arg0,
		arg1,
	)
}

func parser_ASTLikeExpression_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTLikeExpression_query(arg0, arg1)
}

func ASTLikeExpression_unnest_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTLikeExpression_unnest_expr(
		arg0,
		arg1,
	)
}

func parser_ASTLikeExpression_unnest_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTLikeExpression_unnest_expr(arg0, arg1)
}

func ASTWindowSpecification_base_window_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWindowSpecification_base_window_name(
		arg0,
		arg1,
	)
}

func parser_ASTWindowSpecification_base_window_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWindowSpecification_base_window_name(arg0, arg1)
}

func ASTWindowSpecification_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWindowSpecification_partition_by(
		arg0,
		arg1,
	)
}

func parser_ASTWindowSpecification_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWindowSpecification_partition_by(arg0, arg1)
}

func ASTWindowSpecification_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWindowSpecification_order_by(
		arg0,
		arg1,
	)
}

func parser_ASTWindowSpecification_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWindowSpecification_order_by(arg0, arg1)
}

func ASTWindowSpecification_window_frame(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWindowSpecification_window_frame(
		arg0,
		arg1,
	)
}

func parser_ASTWindowSpecification_window_frame(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWindowSpecification_window_frame(arg0, arg1)
}

func ASTWithOffset_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWithOffset_alias(
		arg0,
		arg1,
	)
}

func parser_ASTWithOffset_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWithOffset_alias(arg0, arg1)
}

func ASTAnySomeAllOp_set_op(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTAnySomeAllOp_set_op(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTAnySomeAllOp_set_op(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTAnySomeAllOp_set_op(arg0, arg1)
}

func ASTAnySomeAllOp_op(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTAnySomeAllOp_op(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAnySomeAllOp_op(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTAnySomeAllOp_op(arg0, arg1)
}

func ASTAnySomeAllOp_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAnySomeAllOp_GetSQLForOperator(
		arg0,
		arg1,
	)
}

func parser_ASTAnySomeAllOp_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAnySomeAllOp_GetSQLForOperator(arg0, arg1)
}

func ASTStatementList_set_variable_declarations_allowed(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTStatementList_set_variable_declarations_allowed(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTStatementList_set_variable_declarations_allowed(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTStatementList_set_variable_declarations_allowed(arg0, arg1)
}

func ASTStatementList_variable_declarations_allowed(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTStatementList_variable_declarations_allowed(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTStatementList_variable_declarations_allowed(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTStatementList_variable_declarations_allowed(arg0, arg1)
}

func ASTStatementList_statement_list_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTStatementList_statement_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTStatementList_statement_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTStatementList_statement_list_num(arg0, arg1)
}

func ASTStatementList_statement_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTStatementList_statement_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTStatementList_statement_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStatementList_statement_list(arg0, arg1, arg2)
}

func ASTHintedStatement_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTHintedStatement_hint(
		arg0,
		arg1,
	)
}

func parser_ASTHintedStatement_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTHintedStatement_hint(arg0, arg1)
}

func ASTHintedStatement_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTHintedStatement_statement(
		arg0,
		arg1,
	)
}

func parser_ASTHintedStatement_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTHintedStatement_statement(arg0, arg1)
}

func ASTExplainStatement_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExplainStatement_statement(
		arg0,
		arg1,
	)
}

func parser_ASTExplainStatement_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExplainStatement_statement(arg0, arg1)
}

func ASTDescribeStatement_optional_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDescribeStatement_optional_identifier(
		arg0,
		arg1,
	)
}

func parser_ASTDescribeStatement_optional_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDescribeStatement_optional_identifier(arg0, arg1)
}

func ASTDescribeStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDescribeStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTDescribeStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDescribeStatement_name(arg0, arg1)
}

func ASTDescribeStatement_optional_from_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDescribeStatement_optional_from_name(
		arg0,
		arg1,
	)
}

func parser_ASTDescribeStatement_optional_from_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDescribeStatement_optional_from_name(arg0, arg1)
}

func ASTShowStatement_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTShowStatement_identifier(
		arg0,
		arg1,
	)
}

func parser_ASTShowStatement_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTShowStatement_identifier(arg0, arg1)
}

func ASTShowStatement_optional_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTShowStatement_optional_name(
		arg0,
		arg1,
	)
}

func parser_ASTShowStatement_optional_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTShowStatement_optional_name(arg0, arg1)
}

func ASTShowStatement_optional_like_string(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTShowStatement_optional_like_string(
		arg0,
		arg1,
	)
}

func parser_ASTShowStatement_optional_like_string(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTShowStatement_optional_like_string(arg0, arg1)
}

func ASTTransactionIsolationLevel_identifier1(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTransactionIsolationLevel_identifier1(
		arg0,
		arg1,
	)
}

func parser_ASTTransactionIsolationLevel_identifier1(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTransactionIsolationLevel_identifier1(arg0, arg1)
}

func ASTTransactionIsolationLevel_identifier2(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTransactionIsolationLevel_identifier2(
		arg0,
		arg1,
	)
}

func parser_ASTTransactionIsolationLevel_identifier2(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTransactionIsolationLevel_identifier2(arg0, arg1)
}

func ASTTransactionReadWriteMode_set_mode(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTTransactionReadWriteMode_set_mode(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTTransactionReadWriteMode_set_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTTransactionReadWriteMode_set_mode(arg0, arg1)
}

func ASTTransactionReadWriteMode_mode(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTTransactionReadWriteMode_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTTransactionReadWriteMode_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTTransactionReadWriteMode_mode(arg0, arg1)
}

func ASTTransactionModeList_elements_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTTransactionModeList_elements_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTTransactionModeList_elements_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTTransactionModeList_elements_num(arg0, arg1)
}

func ASTTransactionModeList_element(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTTransactionModeList_element(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTTransactionModeList_element(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTransactionModeList_element(arg0, arg1, arg2)
}

func ASTBeginStatement_mode_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTBeginStatement_mode_list(
		arg0,
		arg1,
	)
}

func parser_ASTBeginStatement_mode_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTBeginStatement_mode_list(arg0, arg1)
}

func ASTSetTransactionStatement_mode_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSetTransactionStatement_mode_list(
		arg0,
		arg1,
	)
}

func parser_ASTSetTransactionStatement_mode_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSetTransactionStatement_mode_list(arg0, arg1)
}

func ASTStartBatchStatement_batch_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTStartBatchStatement_batch_type(
		arg0,
		arg1,
	)
}

func parser_ASTStartBatchStatement_batch_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStartBatchStatement_batch_type(arg0, arg1)
}

func ASTDdlStatement_GetDdlTarget(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDdlStatement_GetDdlTarget(
		arg0,
		arg1,
	)
}

func parser_ASTDdlStatement_GetDdlTarget(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDdlStatement_GetDdlTarget(arg0, arg1)
}

func ASTDropEntityStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDropEntityStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDropEntityStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDropEntityStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropEntityStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTDropEntityStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDropEntityStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTDropEntityStatement_is_if_exists(arg0, arg1)
}

func ASTDropEntityStatement_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropEntityStatement_entity_type(
		arg0,
		arg1,
	)
}

func parser_ASTDropEntityStatement_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropEntityStatement_entity_type(arg0, arg1)
}

func ASTDropEntityStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropEntityStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTDropEntityStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropEntityStatement_name(arg0, arg1)
}

func ASTDropFunctionStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDropFunctionStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDropFunctionStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDropFunctionStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropFunctionStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTDropFunctionStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDropFunctionStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTDropFunctionStatement_is_if_exists(arg0, arg1)
}

func ASTDropFunctionStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropFunctionStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTDropFunctionStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropFunctionStatement_name(arg0, arg1)
}

func ASTDropFunctionStatement_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropFunctionStatement_parameters(
		arg0,
		arg1,
	)
}

func parser_ASTDropFunctionStatement_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropFunctionStatement_parameters(arg0, arg1)
}

func ASTDropTableFunctionStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDropTableFunctionStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDropTableFunctionStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDropTableFunctionStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropTableFunctionStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTDropTableFunctionStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDropTableFunctionStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTDropTableFunctionStatement_is_if_exists(arg0, arg1)
}

func ASTDropTableFunctionStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropTableFunctionStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTDropTableFunctionStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropTableFunctionStatement_name(arg0, arg1)
}

func ASTDropAllRowAccessPoliciesStatement_set_has_access_keyword(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDropAllRowAccessPoliciesStatement_set_has_access_keyword(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDropAllRowAccessPoliciesStatement_set_has_access_keyword(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDropAllRowAccessPoliciesStatement_set_has_access_keyword(arg0, arg1)
}

func ASTDropAllRowAccessPoliciesStatement_has_access_keyword(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTDropAllRowAccessPoliciesStatement_has_access_keyword(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDropAllRowAccessPoliciesStatement_has_access_keyword(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTDropAllRowAccessPoliciesStatement_has_access_keyword(arg0, arg1)
}

func ASTDropAllRowAccessPoliciesStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropAllRowAccessPoliciesStatement_table_name(
		arg0,
		arg1,
	)
}

func parser_ASTDropAllRowAccessPoliciesStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropAllRowAccessPoliciesStatement_table_name(arg0, arg1)
}

func ASTDropMaterializedViewStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDropMaterializedViewStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDropMaterializedViewStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDropMaterializedViewStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropMaterializedViewStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTDropMaterializedViewStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDropMaterializedViewStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTDropMaterializedViewStatement_is_if_exists(arg0, arg1)
}

func ASTDropMaterializedViewStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropMaterializedViewStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTDropMaterializedViewStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropMaterializedViewStatement_name(arg0, arg1)
}

func ASTDropSnapshotTableStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDropSnapshotTableStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDropSnapshotTableStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDropSnapshotTableStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropSnapshotTableStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTDropSnapshotTableStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDropSnapshotTableStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTDropSnapshotTableStatement_is_if_exists(arg0, arg1)
}

func ASTDropSnapshotTableStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropSnapshotTableStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTDropSnapshotTableStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropSnapshotTableStatement_name(arg0, arg1)
}

func ASTDropSearchIndexStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDropSearchIndexStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDropSearchIndexStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDropSearchIndexStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropSearchIndexStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTDropSearchIndexStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDropSearchIndexStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTDropSearchIndexStatement_is_if_exists(arg0, arg1)
}

func ASTDropSearchIndexStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropSearchIndexStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTDropSearchIndexStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropSearchIndexStatement_name(arg0, arg1)
}

func ASTDropSearchIndexStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropSearchIndexStatement_table_name(
		arg0,
		arg1,
	)
}

func parser_ASTDropSearchIndexStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropSearchIndexStatement_table_name(arg0, arg1)
}

func ASTRenameStatement_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRenameStatement_identifier(
		arg0,
		arg1,
	)
}

func parser_ASTRenameStatement_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRenameStatement_identifier(arg0, arg1)
}

func ASTRenameStatement_old_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRenameStatement_old_name(
		arg0,
		arg1,
	)
}

func parser_ASTRenameStatement_old_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRenameStatement_old_name(arg0, arg1)
}

func ASTRenameStatement_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRenameStatement_new_name(
		arg0,
		arg1,
	)
}

func parser_ASTRenameStatement_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRenameStatement_new_name(arg0, arg1)
}

func ASTImportStatement_set_import_kind(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTImportStatement_set_import_kind(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTImportStatement_set_import_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTImportStatement_set_import_kind(arg0, arg1)
}

func ASTImportStatement_import_kind(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTImportStatement_import_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTImportStatement_import_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTImportStatement_import_kind(arg0, arg1)
}

func ASTImportStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTImportStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTImportStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTImportStatement_name(arg0, arg1)
}

func ASTImportStatement_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTImportStatement_string_value(
		arg0,
		arg1,
	)
}

func parser_ASTImportStatement_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTImportStatement_string_value(arg0, arg1)
}

func ASTImportStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTImportStatement_alias(
		arg0,
		arg1,
	)
}

func parser_ASTImportStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTImportStatement_alias(arg0, arg1)
}

func ASTImportStatement_into_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTImportStatement_into_alias(
		arg0,
		arg1,
	)
}

func parser_ASTImportStatement_into_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTImportStatement_into_alias(arg0, arg1)
}

func ASTImportStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTImportStatement_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTImportStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTImportStatement_options_list(arg0, arg1)
}

func ASTModuleStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTModuleStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTModuleStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTModuleStatement_name(arg0, arg1)
}

func ASTModuleStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTModuleStatement_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTModuleStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTModuleStatement_options_list(arg0, arg1)
}

func ASTWithConnectionClause_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWithConnectionClause_connection_clause(
		arg0,
		arg1,
	)
}

func parser_ASTWithConnectionClause_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWithConnectionClause_connection_clause(arg0, arg1)
}

func ASTIntoAlias_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTIntoAlias_identifier(
		arg0,
		arg1,
	)
}

func parser_ASTIntoAlias_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTIntoAlias_identifier(arg0, arg1)
}

func ASTIntoAlias_GetAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTIntoAlias_GetAsString(
		arg0,
		arg1,
	)
}

func parser_ASTIntoAlias_GetAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTIntoAlias_GetAsString(arg0, arg1)
}

func ASTUnnestExpressionWithOptAliasAndOffset_unnest_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUnnestExpressionWithOptAliasAndOffset_unnest_expression(
		arg0,
		arg1,
	)
}

func parser_ASTUnnestExpressionWithOptAliasAndOffset_unnest_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUnnestExpressionWithOptAliasAndOffset_unnest_expression(arg0, arg1)
}

func ASTUnnestExpressionWithOptAliasAndOffset_optional_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUnnestExpressionWithOptAliasAndOffset_optional_alias(
		arg0,
		arg1,
	)
}

func parser_ASTUnnestExpressionWithOptAliasAndOffset_optional_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUnnestExpressionWithOptAliasAndOffset_optional_alias(arg0, arg1)
}

func ASTUnnestExpressionWithOptAliasAndOffset_optional_with_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUnnestExpressionWithOptAliasAndOffset_optional_with_offset(
		arg0,
		arg1,
	)
}

func parser_ASTUnnestExpressionWithOptAliasAndOffset_optional_with_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUnnestExpressionWithOptAliasAndOffset_optional_with_offset(arg0, arg1)
}

func ASTPivotExpression_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTPivotExpression_expression(
		arg0,
		arg1,
	)
}

func parser_ASTPivotExpression_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPivotExpression_expression(arg0, arg1)
}

func ASTPivotExpression_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTPivotExpression_alias(
		arg0,
		arg1,
	)
}

func parser_ASTPivotExpression_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPivotExpression_alias(arg0, arg1)
}

func ASTPivotValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTPivotValue_value(
		arg0,
		arg1,
	)
}

func parser_ASTPivotValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPivotValue_value(arg0, arg1)
}

func ASTPivotValue_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTPivotValue_alias(
		arg0,
		arg1,
	)
}

func parser_ASTPivotValue_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPivotValue_alias(arg0, arg1)
}

func ASTPivotExpressionList_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTPivotExpressionList_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTPivotExpressionList_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTPivotExpressionList_expressions_num(arg0, arg1)
}

func ASTPivotExpressionList_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTPivotExpressionList_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTPivotExpressionList_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPivotExpressionList_expression(arg0, arg1, arg2)
}

func ASTPivotValueList_values_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTPivotValueList_values_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTPivotValueList_values_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTPivotValueList_values_num(arg0, arg1)
}

func ASTPivotValueList_value(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTPivotValueList_value(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTPivotValueList_value(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPivotValueList_value(arg0, arg1, arg2)
}

func ASTPivotClause_pivot_expressions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTPivotClause_pivot_expressions(
		arg0,
		arg1,
	)
}

func parser_ASTPivotClause_pivot_expressions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPivotClause_pivot_expressions(arg0, arg1)
}

func ASTPivotClause_for_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTPivotClause_for_expression(
		arg0,
		arg1,
	)
}

func parser_ASTPivotClause_for_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPivotClause_for_expression(arg0, arg1)
}

func ASTPivotClause_pivot_values(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTPivotClause_pivot_values(
		arg0,
		arg1,
	)
}

func parser_ASTPivotClause_pivot_values(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPivotClause_pivot_values(arg0, arg1)
}

func ASTPivotClause_output_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTPivotClause_output_alias(
		arg0,
		arg1,
	)
}

func parser_ASTPivotClause_output_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPivotClause_output_alias(arg0, arg1)
}

func ASTUnpivotInItem_unpivot_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUnpivotInItem_unpivot_columns(
		arg0,
		arg1,
	)
}

func parser_ASTUnpivotInItem_unpivot_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUnpivotInItem_unpivot_columns(arg0, arg1)
}

func ASTUnpivotInItem_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUnpivotInItem_alias(
		arg0,
		arg1,
	)
}

func parser_ASTUnpivotInItem_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUnpivotInItem_alias(arg0, arg1)
}

func ASTUnpivotInItemList_in_items_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTUnpivotInItemList_in_items_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTUnpivotInItemList_in_items_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTUnpivotInItemList_in_items_num(arg0, arg1)
}

func ASTUnpivotInItemList_in_item(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTUnpivotInItemList_in_item(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTUnpivotInItemList_in_item(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUnpivotInItemList_in_item(arg0, arg1, arg2)
}

func ASTUnpivotClause_set_null_filter(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTUnpivotClause_set_null_filter(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTUnpivotClause_set_null_filter(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTUnpivotClause_set_null_filter(arg0, arg1)
}

func ASTUnpivotClause_null_filter(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTUnpivotClause_null_filter(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTUnpivotClause_null_filter(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTUnpivotClause_null_filter(arg0, arg1)
}

func ASTUnpivotClause_unpivot_output_value_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUnpivotClause_unpivot_output_value_columns(
		arg0,
		arg1,
	)
}

func parser_ASTUnpivotClause_unpivot_output_value_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUnpivotClause_unpivot_output_value_columns(arg0, arg1)
}

func ASTUnpivotClause_unpivot_output_name_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUnpivotClause_unpivot_output_name_column(
		arg0,
		arg1,
	)
}

func parser_ASTUnpivotClause_unpivot_output_name_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUnpivotClause_unpivot_output_name_column(arg0, arg1)
}

func ASTUnpivotClause_unpivot_in_items(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUnpivotClause_unpivot_in_items(
		arg0,
		arg1,
	)
}

func parser_ASTUnpivotClause_unpivot_in_items(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUnpivotClause_unpivot_in_items(arg0, arg1)
}

func ASTUnpivotClause_output_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUnpivotClause_output_alias(
		arg0,
		arg1,
	)
}

func parser_ASTUnpivotClause_output_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUnpivotClause_output_alias(arg0, arg1)
}

func ASTUsingClause_keys_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTUsingClause_keys_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTUsingClause_keys_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTUsingClause_keys_num(arg0, arg1)
}

func ASTUsingClause_key(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTUsingClause_key(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTUsingClause_key(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUsingClause_key(arg0, arg1, arg2)
}

func ASTForSystemTime_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTForSystemTime_expression(
		arg0,
		arg1,
	)
}

func parser_ASTForSystemTime_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTForSystemTime_expression(arg0, arg1)
}

func ASTQualify_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTQualify_expression(
		arg0,
		arg1,
	)
}

func parser_ASTQualify_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTQualify_expression(arg0, arg1)
}

func ASTClampedBetweenModifier_low(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTClampedBetweenModifier_low(
		arg0,
		arg1,
	)
}

func parser_ASTClampedBetweenModifier_low(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTClampedBetweenModifier_low(arg0, arg1)
}

func ASTClampedBetweenModifier_high(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTClampedBetweenModifier_high(
		arg0,
		arg1,
	)
}

func parser_ASTClampedBetweenModifier_high(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTClampedBetweenModifier_high(arg0, arg1)
}

func ASTFormatClause_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFormatClause_format(
		arg0,
		arg1,
	)
}

func parser_ASTFormatClause_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFormatClause_format(arg0, arg1)
}

func ASTFormatClause_time_zone_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFormatClause_time_zone_expr(
		arg0,
		arg1,
	)
}

func parser_ASTFormatClause_time_zone_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFormatClause_time_zone_expr(arg0, arg1)
}

func ASTPathExpressionList_path_expression_list_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTPathExpressionList_path_expression_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTPathExpressionList_path_expression_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTPathExpressionList_path_expression_list_num(arg0, arg1)
}

func ASTPathExpressionList_path_expression_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTPathExpressionList_path_expression_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTPathExpressionList_path_expression_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPathExpressionList_path_expression_list(arg0, arg1, arg2)
}

func ASTParameterExpr_set_position(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTParameterExpr_set_position(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTParameterExpr_set_position(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTParameterExpr_set_position(arg0, arg1)
}

func ASTParameterExpr_position(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTParameterExpr_position(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTParameterExpr_position(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTParameterExpr_position(arg0, arg1)
}

func ASTParameterExpr_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTParameterExpr_name(
		arg0,
		arg1,
	)
}

func parser_ASTParameterExpr_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTParameterExpr_name(arg0, arg1)
}

func ASTSystemVariableExpr_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSystemVariableExpr_path(
		arg0,
		arg1,
	)
}

func parser_ASTSystemVariableExpr_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSystemVariableExpr_path(arg0, arg1)
}

func ASTWithGroupRows_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWithGroupRows_subquery(
		arg0,
		arg1,
	)
}

func parser_ASTWithGroupRows_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWithGroupRows_subquery(arg0, arg1)
}

func ASTLambda_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTLambda_argument_list(
		arg0,
		arg1,
	)
}

func parser_ASTLambda_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTLambda_argument_list(arg0, arg1)
}

func ASTLambda_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTLambda_body(
		arg0,
		arg1,
	)
}

func parser_ASTLambda_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTLambda_body(arg0, arg1)
}

func ASTAnalyticFunctionCall_window_spec(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAnalyticFunctionCall_window_spec(
		arg0,
		arg1,
	)
}

func parser_ASTAnalyticFunctionCall_window_spec(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAnalyticFunctionCall_window_spec(arg0, arg1)
}

func ASTAnalyticFunctionCall_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAnalyticFunctionCall_function(
		arg0,
		arg1,
	)
}

func parser_ASTAnalyticFunctionCall_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAnalyticFunctionCall_function(arg0, arg1)
}

func ASTAnalyticFunctionCall_function_with_group_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAnalyticFunctionCall_function_with_group_rows(
		arg0,
		arg1,
	)
}

func parser_ASTAnalyticFunctionCall_function_with_group_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAnalyticFunctionCall_function_with_group_rows(arg0, arg1)
}

func ASTFunctionCallWithGroupRows_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionCallWithGroupRows_function(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionCallWithGroupRows_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionCallWithGroupRows_function(arg0, arg1)
}

func ASTFunctionCallWithGroupRows_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionCallWithGroupRows_subquery(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionCallWithGroupRows_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionCallWithGroupRows_subquery(arg0, arg1)
}

func ASTClusterBy_clustering_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTClusterBy_clustering_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTClusterBy_clustering_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTClusterBy_clustering_expressions_num(arg0, arg1)
}

func ASTClusterBy_clustering_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTClusterBy_clustering_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTClusterBy_clustering_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTClusterBy_clustering_expression(arg0, arg1, arg2)
}

func ASTNewConstructorArg_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTNewConstructorArg_expression(
		arg0,
		arg1,
	)
}

func parser_ASTNewConstructorArg_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNewConstructorArg_expression(arg0, arg1)
}

func ASTNewConstructorArg_optional_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTNewConstructorArg_optional_identifier(
		arg0,
		arg1,
	)
}

func parser_ASTNewConstructorArg_optional_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNewConstructorArg_optional_identifier(arg0, arg1)
}

func ASTNewConstructorArg_optional_path_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTNewConstructorArg_optional_path_expression(
		arg0,
		arg1,
	)
}

func parser_ASTNewConstructorArg_optional_path_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNewConstructorArg_optional_path_expression(arg0, arg1)
}

func ASTNewConstructor_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTNewConstructor_type_name(
		arg0,
		arg1,
	)
}

func parser_ASTNewConstructor_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNewConstructor_type_name(arg0, arg1)
}

func ASTNewConstructor_arguments_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTNewConstructor_arguments_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTNewConstructor_arguments_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTNewConstructor_arguments_num(arg0, arg1)
}

func ASTNewConstructor_argument(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTNewConstructor_argument(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTNewConstructor_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTNewConstructor_argument(arg0, arg1, arg2)
}

func ASTOptionsList_options_entries_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTOptionsList_options_entries_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTOptionsList_options_entries_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTOptionsList_options_entries_num(arg0, arg1)
}

func ASTOptionsList_options_entry(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTOptionsList_options_entry(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTOptionsList_options_entry(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTOptionsList_options_entry(arg0, arg1, arg2)
}

func ASTOptionsEntry_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTOptionsEntry_name(
		arg0,
		arg1,
	)
}

func parser_ASTOptionsEntry_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTOptionsEntry_name(arg0, arg1)
}

func ASTOptionsEntry_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTOptionsEntry_value(
		arg0,
		arg1,
	)
}

func parser_ASTOptionsEntry_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTOptionsEntry_value(arg0, arg1)
}

func ASTCreateStatement_set_scope(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTCreateStatement_set_scope(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTCreateStatement_set_scope(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTCreateStatement_set_scope(arg0, arg1)
}

func ASTCreateStatement_scope(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTCreateStatement_scope(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCreateStatement_scope(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTCreateStatement_scope(arg0, arg1)
}

func ASTCreateStatement_set_is_or_replace(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTCreateStatement_set_is_or_replace(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTCreateStatement_set_is_or_replace(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTCreateStatement_set_is_or_replace(arg0, arg1)
}

func ASTCreateStatement_is_or_replace(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTCreateStatement_is_or_replace(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCreateStatement_is_or_replace(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTCreateStatement_is_or_replace(arg0, arg1)
}

func ASTCreateStatement_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTCreateStatement_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTCreateStatement_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTCreateStatement_set_is_if_not_exists(arg0, arg1)
}

func ASTCreateStatement_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTCreateStatement_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCreateStatement_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTCreateStatement_is_if_not_exists(arg0, arg1)
}

func ASTCreateStatement_is_default_scope(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTCreateStatement_is_default_scope(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCreateStatement_is_default_scope(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTCreateStatement_is_default_scope(arg0, arg1)
}

func ASTCreateStatement_is_private(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTCreateStatement_is_private(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCreateStatement_is_private(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTCreateStatement_is_private(arg0, arg1)
}

func ASTCreateStatement_is_public(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTCreateStatement_is_public(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCreateStatement_is_public(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTCreateStatement_is_public(arg0, arg1)
}

func ASTCreateStatement_is_temp(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTCreateStatement_is_temp(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCreateStatement_is_temp(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTCreateStatement_is_temp(arg0, arg1)
}

func ASTFunctionParameter_set_procedure_parameter_mode(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTFunctionParameter_set_procedure_parameter_mode(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTFunctionParameter_set_procedure_parameter_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTFunctionParameter_set_procedure_parameter_mode(arg0, arg1)
}

func ASTFunctionParameter_procedure_parameter_mode(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTFunctionParameter_procedure_parameter_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTFunctionParameter_procedure_parameter_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTFunctionParameter_procedure_parameter_mode(arg0, arg1)
}

func ASTFunctionParameter_set_is_not_aggregate(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTFunctionParameter_set_is_not_aggregate(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTFunctionParameter_set_is_not_aggregate(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTFunctionParameter_set_is_not_aggregate(arg0, arg1)
}

func ASTFunctionParameter_is_not_aggregate(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTFunctionParameter_is_not_aggregate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTFunctionParameter_is_not_aggregate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTFunctionParameter_is_not_aggregate(arg0, arg1)
}

func ASTFunctionParameter_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionParameter_name(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionParameter_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionParameter_name(arg0, arg1)
}

func ASTFunctionParameter_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionParameter_type(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionParameter_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionParameter_type(arg0, arg1)
}

func ASTFunctionParameter_templated_parameter_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionParameter_templated_parameter_type(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionParameter_templated_parameter_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionParameter_templated_parameter_type(arg0, arg1)
}

func ASTFunctionParameter_tvf_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionParameter_tvf_schema(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionParameter_tvf_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionParameter_tvf_schema(arg0, arg1)
}

func ASTFunctionParameter_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionParameter_alias(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionParameter_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionParameter_alias(arg0, arg1)
}

func ASTFunctionParameter_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionParameter_default_value(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionParameter_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionParameter_default_value(arg0, arg1)
}

func ASTFunctionParameter_IsTableParameter(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTFunctionParameter_IsTableParameter(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTFunctionParameter_IsTableParameter(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTFunctionParameter_IsTableParameter(arg0, arg1)
}

func ASTFunctionParameter_IsTemplated(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTFunctionParameter_IsTemplated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTFunctionParameter_IsTemplated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTFunctionParameter_IsTemplated(arg0, arg1)
}

func ASTFunctionParameters_parameter_entries_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTFunctionParameters_parameter_entries_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTFunctionParameters_parameter_entries_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTFunctionParameters_parameter_entries_num(arg0, arg1)
}

func ASTFunctionParameters_parameter_entry(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTFunctionParameters_parameter_entry(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTFunctionParameters_parameter_entry(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionParameters_parameter_entry(arg0, arg1, arg2)
}

func ASTFunctionDeclaration_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionDeclaration_name(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionDeclaration_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionDeclaration_name(arg0, arg1)
}

func ASTFunctionDeclaration_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFunctionDeclaration_parameters(
		arg0,
		arg1,
	)
}

func parser_ASTFunctionDeclaration_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFunctionDeclaration_parameters(arg0, arg1)
}

func ASTFunctionDeclaration_IsTemplated(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTFunctionDeclaration_IsTemplated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTFunctionDeclaration_IsTemplated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTFunctionDeclaration_IsTemplated(arg0, arg1)
}

func ASTSqlFunctionBody_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSqlFunctionBody_expression(
		arg0,
		arg1,
	)
}

func parser_ASTSqlFunctionBody_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSqlFunctionBody_expression(arg0, arg1)
}

func ASTTVFArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTVFArgument_expr(
		arg0,
		arg1,
	)
}

func parser_ASTTVFArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTVFArgument_expr(arg0, arg1)
}

func ASTTVFArgument_table_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTVFArgument_table_clause(
		arg0,
		arg1,
	)
}

func parser_ASTTVFArgument_table_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTVFArgument_table_clause(arg0, arg1)
}

func ASTTVFArgument_model_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTVFArgument_model_clause(
		arg0,
		arg1,
	)
}

func parser_ASTTVFArgument_model_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTVFArgument_model_clause(arg0, arg1)
}

func ASTTVFArgument_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTVFArgument_connection_clause(
		arg0,
		arg1,
	)
}

func parser_ASTTVFArgument_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTVFArgument_connection_clause(arg0, arg1)
}

func ASTTVFArgument_descriptor(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTVFArgument_descriptor(
		arg0,
		arg1,
	)
}

func parser_ASTTVFArgument_descriptor(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTVFArgument_descriptor(arg0, arg1)
}

func ASTTVF_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTVF_name(
		arg0,
		arg1,
	)
}

func parser_ASTTVF_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTVF_name(arg0, arg1)
}

func ASTTVF_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTVF_hint(
		arg0,
		arg1,
	)
}

func parser_ASTTVF_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTVF_hint(arg0, arg1)
}

func ASTTVF_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTVF_alias(
		arg0,
		arg1,
	)
}

func parser_ASTTVF_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTVF_alias(arg0, arg1)
}

func ASTTVF_pivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTVF_pivot_clause(
		arg0,
		arg1,
	)
}

func parser_ASTTVF_pivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTVF_pivot_clause(arg0, arg1)
}

func ASTTVF_unpivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTVF_unpivot_clause(
		arg0,
		arg1,
	)
}

func parser_ASTTVF_unpivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTVF_unpivot_clause(arg0, arg1)
}

func ASTTVF_sample(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTVF_sample(
		arg0,
		arg1,
	)
}

func parser_ASTTVF_sample(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTVF_sample(arg0, arg1)
}

func ASTTVF_argument_entries_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTTVF_argument_entries_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTTVF_argument_entries_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTTVF_argument_entries_num(arg0, arg1)
}

func ASTTVF_argument_entry(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTTVF_argument_entry(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTTVF_argument_entry(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTVF_argument_entry(arg0, arg1, arg2)
}

func ASTTableClause_table_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTableClause_table_path(
		arg0,
		arg1,
	)
}

func parser_ASTTableClause_table_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTableClause_table_path(arg0, arg1)
}

func ASTTableClause_tvf(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTableClause_tvf(
		arg0,
		arg1,
	)
}

func parser_ASTTableClause_tvf(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTableClause_tvf(arg0, arg1)
}

func ASTModelClause_model_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTModelClause_model_path(
		arg0,
		arg1,
	)
}

func parser_ASTModelClause_model_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTModelClause_model_path(arg0, arg1)
}

func ASTConnectionClause_connection_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTConnectionClause_connection_path(
		arg0,
		arg1,
	)
}

func parser_ASTConnectionClause_connection_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTConnectionClause_connection_path(arg0, arg1)
}

func ASTTableDataSource_path_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTableDataSource_path_expr(
		arg0,
		arg1,
	)
}

func parser_ASTTableDataSource_path_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTableDataSource_path_expr(arg0, arg1)
}

func ASTTableDataSource_for_system_time(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTableDataSource_for_system_time(
		arg0,
		arg1,
	)
}

func parser_ASTTableDataSource_for_system_time(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTableDataSource_for_system_time(arg0, arg1)
}

func ASTTableDataSource_where_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTableDataSource_where_clause(
		arg0,
		arg1,
	)
}

func parser_ASTTableDataSource_where_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTableDataSource_where_clause(arg0, arg1)
}

func ASTCloneDataSourceList_data_sources_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTCloneDataSourceList_data_sources_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCloneDataSourceList_data_sources_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTCloneDataSourceList_data_sources_num(arg0, arg1)
}

func ASTCloneDataSourceList_data_source(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTCloneDataSourceList_data_source(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTCloneDataSourceList_data_source(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCloneDataSourceList_data_source(arg0, arg1, arg2)
}

func ASTCloneDataStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCloneDataStatement_target_path(
		arg0,
		arg1,
	)
}

func parser_ASTCloneDataStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCloneDataStatement_target_path(arg0, arg1)
}

func ASTCloneDataStatement_data_source_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCloneDataStatement_data_source_list(
		arg0,
		arg1,
	)
}

func parser_ASTCloneDataStatement_data_source_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCloneDataStatement_data_source_list(arg0, arg1)
}

func ASTCreateConstantStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateConstantStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTCreateConstantStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateConstantStatement_name(arg0, arg1)
}

func ASTCreateConstantStatement_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateConstantStatement_expr(
		arg0,
		arg1,
	)
}

func parser_ASTCreateConstantStatement_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateConstantStatement_expr(arg0, arg1)
}

func ASTCreateDatabaseStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateDatabaseStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTCreateDatabaseStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateDatabaseStatement_name(arg0, arg1)
}

func ASTCreateDatabaseStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateDatabaseStatement_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTCreateDatabaseStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateDatabaseStatement_options_list(arg0, arg1)
}

func ASTCreateProcedureStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateProcedureStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTCreateProcedureStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateProcedureStatement_name(arg0, arg1)
}

func ASTCreateProcedureStatement_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateProcedureStatement_parameters(
		arg0,
		arg1,
	)
}

func parser_ASTCreateProcedureStatement_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateProcedureStatement_parameters(arg0, arg1)
}

func ASTCreateProcedureStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateProcedureStatement_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTCreateProcedureStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateProcedureStatement_options_list(arg0, arg1)
}

func ASTCreateProcedureStatement_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateProcedureStatement_body(
		arg0,
		arg1,
	)
}

func parser_ASTCreateProcedureStatement_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateProcedureStatement_body(arg0, arg1)
}

func ASTCreateSchemaStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateSchemaStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTCreateSchemaStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateSchemaStatement_name(arg0, arg1)
}

func ASTCreateSchemaStatement_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateSchemaStatement_collate(
		arg0,
		arg1,
	)
}

func parser_ASTCreateSchemaStatement_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateSchemaStatement_collate(arg0, arg1)
}

func ASTCreateSchemaStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateSchemaStatement_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTCreateSchemaStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateSchemaStatement_options_list(arg0, arg1)
}

func ASTTransformClause_select_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTransformClause_select_list(
		arg0,
		arg1,
	)
}

func parser_ASTTransformClause_select_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTransformClause_select_list(arg0, arg1)
}

func ASTCreateModelStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateModelStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTCreateModelStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateModelStatement_name(arg0, arg1)
}

func ASTCreateModelStatement_transform_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateModelStatement_transform_clause(
		arg0,
		arg1,
	)
}

func parser_ASTCreateModelStatement_transform_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateModelStatement_transform_clause(arg0, arg1)
}

func ASTCreateModelStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateModelStatement_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTCreateModelStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateModelStatement_options_list(arg0, arg1)
}

func ASTCreateModelStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateModelStatement_query(
		arg0,
		arg1,
	)
}

func parser_ASTCreateModelStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateModelStatement_query(arg0, arg1)
}

func ASTIndexItemList_ordering_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTIndexItemList_ordering_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTIndexItemList_ordering_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTIndexItemList_ordering_expressions_num(arg0, arg1)
}

func ASTIndexItemList_ordering_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTIndexItemList_ordering_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTIndexItemList_ordering_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTIndexItemList_ordering_expression(arg0, arg1, arg2)
}

func ASTIndexStoringExpressionList_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTIndexStoringExpressionList_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTIndexStoringExpressionList_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTIndexStoringExpressionList_expressions_num(arg0, arg1)
}

func ASTIndexStoringExpressionList_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTIndexStoringExpressionList_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTIndexStoringExpressionList_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTIndexStoringExpressionList_expression(arg0, arg1, arg2)
}

func ASTIndexUnnestExpressionList_unnest_expressions_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTIndexUnnestExpressionList_unnest_expressions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTIndexUnnestExpressionList_unnest_expressions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTIndexUnnestExpressionList_unnest_expressions_num(arg0, arg1)
}

func ASTIndexUnnestExpressionList_unnest_expression(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTIndexUnnestExpressionList_unnest_expression(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTIndexUnnestExpressionList_unnest_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTIndexUnnestExpressionList_unnest_expression(arg0, arg1, arg2)
}

func ASTCreateIndexStatement_set_is_unique(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTCreateIndexStatement_set_is_unique(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTCreateIndexStatement_set_is_unique(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTCreateIndexStatement_set_is_unique(arg0, arg1)
}

func ASTCreateIndexStatement_is_unique(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTCreateIndexStatement_is_unique(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCreateIndexStatement_is_unique(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTCreateIndexStatement_is_unique(arg0, arg1)
}

func ASTCreateIndexStatement_set_is_search(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTCreateIndexStatement_set_is_search(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTCreateIndexStatement_set_is_search(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTCreateIndexStatement_set_is_search(arg0, arg1)
}

func ASTCreateIndexStatement_is_search(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTCreateIndexStatement_is_search(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCreateIndexStatement_is_search(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTCreateIndexStatement_is_search(arg0, arg1)
}

func ASTCreateIndexStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateIndexStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTCreateIndexStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateIndexStatement_name(arg0, arg1)
}

func ASTCreateIndexStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateIndexStatement_table_name(
		arg0,
		arg1,
	)
}

func parser_ASTCreateIndexStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateIndexStatement_table_name(arg0, arg1)
}

func ASTCreateIndexStatement_optional_table_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateIndexStatement_optional_table_alias(
		arg0,
		arg1,
	)
}

func parser_ASTCreateIndexStatement_optional_table_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateIndexStatement_optional_table_alias(arg0, arg1)
}

func ASTCreateIndexStatement_optional_index_unnest_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateIndexStatement_optional_index_unnest_expression_list(
		arg0,
		arg1,
	)
}

func parser_ASTCreateIndexStatement_optional_index_unnest_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateIndexStatement_optional_index_unnest_expression_list(arg0, arg1)
}

func ASTCreateIndexStatement_index_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateIndexStatement_index_item_list(
		arg0,
		arg1,
	)
}

func parser_ASTCreateIndexStatement_index_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateIndexStatement_index_item_list(arg0, arg1)
}

func ASTCreateIndexStatement_optional_index_storing_expressions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateIndexStatement_optional_index_storing_expressions(
		arg0,
		arg1,
	)
}

func parser_ASTCreateIndexStatement_optional_index_storing_expressions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateIndexStatement_optional_index_storing_expressions(arg0, arg1)
}

func ASTCreateIndexStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateIndexStatement_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTCreateIndexStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateIndexStatement_options_list(arg0, arg1)
}

func ASTExportDataStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExportDataStatement_with_connection_clause(
		arg0,
		arg1,
	)
}

func parser_ASTExportDataStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExportDataStatement_with_connection_clause(arg0, arg1)
}

func ASTExportDataStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExportDataStatement_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTExportDataStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExportDataStatement_options_list(arg0, arg1)
}

func ASTExportDataStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExportDataStatement_query(
		arg0,
		arg1,
	)
}

func parser_ASTExportDataStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExportDataStatement_query(arg0, arg1)
}

func ASTExportModelStatement_model_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExportModelStatement_model_name_path(
		arg0,
		arg1,
	)
}

func parser_ASTExportModelStatement_model_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExportModelStatement_model_name_path(arg0, arg1)
}

func ASTExportModelStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExportModelStatement_with_connection_clause(
		arg0,
		arg1,
	)
}

func parser_ASTExportModelStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExportModelStatement_with_connection_clause(arg0, arg1)
}

func ASTExportModelStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExportModelStatement_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTExportModelStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExportModelStatement_options_list(arg0, arg1)
}

func ASTCallStatement_procedure_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCallStatement_procedure_name(
		arg0,
		arg1,
	)
}

func parser_ASTCallStatement_procedure_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCallStatement_procedure_name(arg0, arg1)
}

func ASTCallStatement_arguments_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTCallStatement_arguments_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCallStatement_arguments_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTCallStatement_arguments_num(arg0, arg1)
}

func ASTCallStatement_argument(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTCallStatement_argument(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTCallStatement_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCallStatement_argument(arg0, arg1, arg2)
}

func ASTDefineTableStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDefineTableStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTDefineTableStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDefineTableStatement_name(arg0, arg1)
}

func ASTDefineTableStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDefineTableStatement_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTDefineTableStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDefineTableStatement_options_list(arg0, arg1)
}

func ASTWithPartitionColumnsClause_table_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWithPartitionColumnsClause_table_element_list(
		arg0,
		arg1,
	)
}

func parser_ASTWithPartitionColumnsClause_table_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWithPartitionColumnsClause_table_element_list(arg0, arg1)
}

func ASTCreateSnapshotTableStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateSnapshotTableStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTCreateSnapshotTableStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateSnapshotTableStatement_name(arg0, arg1)
}

func ASTCreateSnapshotTableStatement_clone_data_source(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateSnapshotTableStatement_clone_data_source(
		arg0,
		arg1,
	)
}

func parser_ASTCreateSnapshotTableStatement_clone_data_source(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateSnapshotTableStatement_clone_data_source(arg0, arg1)
}

func ASTCreateSnapshotTableStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateSnapshotTableStatement_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTCreateSnapshotTableStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateSnapshotTableStatement_options_list(arg0, arg1)
}

func ASTTypeParameterList_parameters_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTTypeParameterList_parameters_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTTypeParameterList_parameters_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTTypeParameterList_parameters_num(arg0, arg1)
}

func ASTTypeParameterList_parameter(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTTypeParameterList_parameter(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTTypeParameterList_parameter(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTypeParameterList_parameter(arg0, arg1, arg2)
}

func ASTTVFSchema_columns_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTTVFSchema_columns_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTTVFSchema_columns_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTTVFSchema_columns_num(arg0, arg1)
}

func ASTTVFSchema_column(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTTVFSchema_column(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTTVFSchema_column(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTVFSchema_column(arg0, arg1, arg2)
}

func ASTTVFSchemaColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTVFSchemaColumn_name(
		arg0,
		arg1,
	)
}

func parser_ASTTVFSchemaColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTVFSchemaColumn_name(arg0, arg1)
}

func ASTTVFSchemaColumn_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTVFSchemaColumn_type(
		arg0,
		arg1,
	)
}

func parser_ASTTVFSchemaColumn_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTVFSchemaColumn_type(arg0, arg1)
}

func ASTTableAndColumnInfo_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTableAndColumnInfo_table_name(
		arg0,
		arg1,
	)
}

func parser_ASTTableAndColumnInfo_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTableAndColumnInfo_table_name(arg0, arg1)
}

func ASTTableAndColumnInfo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTableAndColumnInfo_column_list(
		arg0,
		arg1,
	)
}

func parser_ASTTableAndColumnInfo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTableAndColumnInfo_column_list(arg0, arg1)
}

func ASTTableAndColumnInfoList_table_and_column_info_entries_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTTableAndColumnInfoList_table_and_column_info_entries_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTTableAndColumnInfoList_table_and_column_info_entries_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTTableAndColumnInfoList_table_and_column_info_entries_num(arg0, arg1)
}

func ASTTableAndColumnInfoList_table_and_column_info_entry(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTTableAndColumnInfoList_table_and_column_info_entry(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTTableAndColumnInfoList_table_and_column_info_entry(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTableAndColumnInfoList_table_and_column_info_entry(arg0, arg1, arg2)
}

func ASTTemplatedParameterType_set_kind(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTTemplatedParameterType_set_kind(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTTemplatedParameterType_set_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTTemplatedParameterType_set_kind(arg0, arg1)
}

func ASTTemplatedParameterType_kind(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTTemplatedParameterType_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTTemplatedParameterType_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTTemplatedParameterType_kind(arg0, arg1)
}

func ASTAnalyzeStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAnalyzeStatement_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTAnalyzeStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAnalyzeStatement_options_list(arg0, arg1)
}

func ASTAnalyzeStatement_table_and_column_info_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAnalyzeStatement_table_and_column_info_list(
		arg0,
		arg1,
	)
}

func parser_ASTAnalyzeStatement_table_and_column_info_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAnalyzeStatement_table_and_column_info_list(arg0, arg1)
}

func ASTAssertStatement_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAssertStatement_expr(
		arg0,
		arg1,
	)
}

func parser_ASTAssertStatement_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAssertStatement_expr(arg0, arg1)
}

func ASTAssertStatement_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAssertStatement_description(
		arg0,
		arg1,
	)
}

func parser_ASTAssertStatement_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAssertStatement_description(arg0, arg1)
}

func ASTAssertRowsModified_num_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAssertRowsModified_num_rows(
		arg0,
		arg1,
	)
}

func parser_ASTAssertRowsModified_num_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAssertRowsModified_num_rows(arg0, arg1)
}

func ASTReturningClause_select_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTReturningClause_select_list(
		arg0,
		arg1,
	)
}

func parser_ASTReturningClause_select_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTReturningClause_select_list(arg0, arg1)
}

func ASTReturningClause_action_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTReturningClause_action_alias(
		arg0,
		arg1,
	)
}

func parser_ASTReturningClause_action_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTReturningClause_action_alias(arg0, arg1)
}

func ASTDeleteStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDeleteStatement_target_path(
		arg0,
		arg1,
	)
}

func parser_ASTDeleteStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDeleteStatement_target_path(arg0, arg1)
}

func ASTDeleteStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDeleteStatement_alias(
		arg0,
		arg1,
	)
}

func parser_ASTDeleteStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDeleteStatement_alias(arg0, arg1)
}

func ASTDeleteStatement_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDeleteStatement_offset(
		arg0,
		arg1,
	)
}

func parser_ASTDeleteStatement_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDeleteStatement_offset(arg0, arg1)
}

func ASTDeleteStatement_where(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDeleteStatement_where(
		arg0,
		arg1,
	)
}

func parser_ASTDeleteStatement_where(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDeleteStatement_where(arg0, arg1)
}

func ASTDeleteStatement_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDeleteStatement_assert_rows_modified(
		arg0,
		arg1,
	)
}

func parser_ASTDeleteStatement_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDeleteStatement_assert_rows_modified(arg0, arg1)
}

func ASTDeleteStatement_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDeleteStatement_returning(
		arg0,
		arg1,
	)
}

func parser_ASTDeleteStatement_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDeleteStatement_returning(arg0, arg1)
}

func ASTPrimaryKeyColumnAttribute_set_enforced(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTPrimaryKeyColumnAttribute_set_enforced(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTPrimaryKeyColumnAttribute_set_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTPrimaryKeyColumnAttribute_set_enforced(arg0, arg1)
}

func ASTPrimaryKeyColumnAttribute_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTPrimaryKeyColumnAttribute_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTPrimaryKeyColumnAttribute_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTPrimaryKeyColumnAttribute_enforced(arg0, arg1)
}

func ASTForeignKeyColumnAttribute_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTForeignKeyColumnAttribute_constraint_name(
		arg0,
		arg1,
	)
}

func parser_ASTForeignKeyColumnAttribute_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTForeignKeyColumnAttribute_constraint_name(arg0, arg1)
}

func ASTForeignKeyColumnAttribute_reference(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTForeignKeyColumnAttribute_reference(
		arg0,
		arg1,
	)
}

func parser_ASTForeignKeyColumnAttribute_reference(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTForeignKeyColumnAttribute_reference(arg0, arg1)
}

func ASTColumnAttributeList_values_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTColumnAttributeList_values_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTColumnAttributeList_values_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTColumnAttributeList_values_num(arg0, arg1)
}

func ASTColumnAttributeList_value(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTColumnAttributeList_value(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTColumnAttributeList_value(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTColumnAttributeList_value(arg0, arg1, arg2)
}

func ASTStructColumnField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTStructColumnField_name(
		arg0,
		arg1,
	)
}

func parser_ASTStructColumnField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStructColumnField_name(arg0, arg1)
}

func ASTStructColumnField_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTStructColumnField_schema(
		arg0,
		arg1,
	)
}

func parser_ASTStructColumnField_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStructColumnField_schema(arg0, arg1)
}

func ASTGeneratedColumnInfo_set_stored_mode(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTGeneratedColumnInfo_set_stored_mode(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTGeneratedColumnInfo_set_stored_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTGeneratedColumnInfo_set_stored_mode(arg0, arg1)
}

func ASTGeneratedColumnInfo_stored_mode(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTGeneratedColumnInfo_stored_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTGeneratedColumnInfo_stored_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTGeneratedColumnInfo_stored_mode(arg0, arg1)
}

func ASTGeneratedColumnInfo_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTGeneratedColumnInfo_expression(
		arg0,
		arg1,
	)
}

func parser_ASTGeneratedColumnInfo_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTGeneratedColumnInfo_expression(arg0, arg1)
}

func ASTGeneratedColumnInfo_GetSqlForStoredMode(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTGeneratedColumnInfo_GetSqlForStoredMode(
		arg0,
		arg1,
	)
}

func parser_ASTGeneratedColumnInfo_GetSqlForStoredMode(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTGeneratedColumnInfo_GetSqlForStoredMode(arg0, arg1)
}

func ASTColumnDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTColumnDefinition_name(
		arg0,
		arg1,
	)
}

func parser_ASTColumnDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTColumnDefinition_name(arg0, arg1)
}

func ASTColumnDefinition_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTColumnDefinition_schema(
		arg0,
		arg1,
	)
}

func parser_ASTColumnDefinition_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTColumnDefinition_schema(arg0, arg1)
}

func ASTTableElementList_elements_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTTableElementList_elements_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTTableElementList_elements_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTTableElementList_elements_num(arg0, arg1)
}

func ASTTableElementList_element(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTTableElementList_element(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTTableElementList_element(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTableElementList_element(arg0, arg1, arg2)
}

func ASTColumnList_identifiers_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTColumnList_identifiers_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTColumnList_identifiers_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTColumnList_identifiers_num(arg0, arg1)
}

func ASTColumnList_identifier(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTColumnList_identifier(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTColumnList_identifier(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTColumnList_identifier(arg0, arg1, arg2)
}

func ASTColumnPosition_set_type(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTColumnPosition_set_type(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTColumnPosition_set_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTColumnPosition_set_type(arg0, arg1)
}

func ASTColumnPosition_type(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTColumnPosition_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTColumnPosition_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTColumnPosition_type(arg0, arg1)
}

func ASTColumnPosition_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTColumnPosition_identifier(
		arg0,
		arg1,
	)
}

func parser_ASTColumnPosition_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTColumnPosition_identifier(arg0, arg1)
}

func ASTInsertValuesRow_values_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTInsertValuesRow_values_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTInsertValuesRow_values_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTInsertValuesRow_values_num(arg0, arg1)
}

func ASTInsertValuesRow_value(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTInsertValuesRow_value(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTInsertValuesRow_value(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTInsertValuesRow_value(arg0, arg1, arg2)
}

func ASTInsertValuesRowList_rows_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTInsertValuesRowList_rows_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTInsertValuesRowList_rows_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTInsertValuesRowList_rows_num(arg0, arg1)
}

func ASTInsertValuesRowList_row(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTInsertValuesRowList_row(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTInsertValuesRowList_row(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTInsertValuesRowList_row(arg0, arg1, arg2)
}

func ASTInsertStatement_set_parse_progress(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTInsertStatement_set_parse_progress(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTInsertStatement_set_parse_progress(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTInsertStatement_set_parse_progress(arg0, arg1)
}

func ASTInsertStatement_parse_progress(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTInsertStatement_parse_progress(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTInsertStatement_parse_progress(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTInsertStatement_parse_progress(arg0, arg1)
}

func ASTInsertStatement_set_insert_mode(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTInsertStatement_set_insert_mode(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTInsertStatement_set_insert_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTInsertStatement_set_insert_mode(arg0, arg1)
}

func ASTInsertStatement_insert_mode(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTInsertStatement_insert_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTInsertStatement_insert_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTInsertStatement_insert_mode(arg0, arg1)
}

func ASTInsertStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTInsertStatement_target_path(
		arg0,
		arg1,
	)
}

func parser_ASTInsertStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTInsertStatement_target_path(arg0, arg1)
}

func ASTInsertStatement_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTInsertStatement_column_list(
		arg0,
		arg1,
	)
}

func parser_ASTInsertStatement_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTInsertStatement_column_list(arg0, arg1)
}

func ASTInsertStatement_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTInsertStatement_rows(
		arg0,
		arg1,
	)
}

func parser_ASTInsertStatement_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTInsertStatement_rows(arg0, arg1)
}

func ASTInsertStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTInsertStatement_query(
		arg0,
		arg1,
	)
}

func parser_ASTInsertStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTInsertStatement_query(arg0, arg1)
}

func ASTInsertStatement_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTInsertStatement_assert_rows_modified(
		arg0,
		arg1,
	)
}

func parser_ASTInsertStatement_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTInsertStatement_assert_rows_modified(arg0, arg1)
}

func ASTInsertStatement_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTInsertStatement_returning(
		arg0,
		arg1,
	)
}

func parser_ASTInsertStatement_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTInsertStatement_returning(arg0, arg1)
}

func ASTInsertStatement_GetSQLForInsertMode(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTInsertStatement_GetSQLForInsertMode(
		arg0,
		arg1,
	)
}

func parser_ASTInsertStatement_GetSQLForInsertMode(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTInsertStatement_GetSQLForInsertMode(arg0, arg1)
}

func ASTUpdateSetValue_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUpdateSetValue_path(
		arg0,
		arg1,
	)
}

func parser_ASTUpdateSetValue_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUpdateSetValue_path(arg0, arg1)
}

func ASTUpdateSetValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUpdateSetValue_value(
		arg0,
		arg1,
	)
}

func parser_ASTUpdateSetValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUpdateSetValue_value(arg0, arg1)
}

func ASTUpdateItem_set_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUpdateItem_set_value(
		arg0,
		arg1,
	)
}

func parser_ASTUpdateItem_set_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUpdateItem_set_value(arg0, arg1)
}

func ASTUpdateItem_insert_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUpdateItem_insert_statement(
		arg0,
		arg1,
	)
}

func parser_ASTUpdateItem_insert_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUpdateItem_insert_statement(arg0, arg1)
}

func ASTUpdateItem_delete_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUpdateItem_delete_statement(
		arg0,
		arg1,
	)
}

func parser_ASTUpdateItem_delete_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUpdateItem_delete_statement(arg0, arg1)
}

func ASTUpdateItem_update_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUpdateItem_update_statement(
		arg0,
		arg1,
	)
}

func parser_ASTUpdateItem_update_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUpdateItem_update_statement(arg0, arg1)
}

func ASTUpdateItemList_update_items_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTUpdateItemList_update_items_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTUpdateItemList_update_items_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTUpdateItemList_update_items_num(arg0, arg1)
}

func ASTUpdateItemList_update_item(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTUpdateItemList_update_item(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTUpdateItemList_update_item(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUpdateItemList_update_item(arg0, arg1, arg2)
}

func ASTUpdateStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUpdateStatement_target_path(
		arg0,
		arg1,
	)
}

func parser_ASTUpdateStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUpdateStatement_target_path(arg0, arg1)
}

func ASTUpdateStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUpdateStatement_alias(
		arg0,
		arg1,
	)
}

func parser_ASTUpdateStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUpdateStatement_alias(arg0, arg1)
}

func ASTUpdateStatement_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUpdateStatement_offset(
		arg0,
		arg1,
	)
}

func parser_ASTUpdateStatement_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUpdateStatement_offset(arg0, arg1)
}

func ASTUpdateStatement_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUpdateStatement_update_item_list(
		arg0,
		arg1,
	)
}

func parser_ASTUpdateStatement_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUpdateStatement_update_item_list(arg0, arg1)
}

func ASTUpdateStatement_from_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUpdateStatement_from_clause(
		arg0,
		arg1,
	)
}

func parser_ASTUpdateStatement_from_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUpdateStatement_from_clause(arg0, arg1)
}

func ASTUpdateStatement_where(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUpdateStatement_where(
		arg0,
		arg1,
	)
}

func parser_ASTUpdateStatement_where(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUpdateStatement_where(arg0, arg1)
}

func ASTUpdateStatement_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUpdateStatement_assert_rows_modified(
		arg0,
		arg1,
	)
}

func parser_ASTUpdateStatement_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUpdateStatement_assert_rows_modified(arg0, arg1)
}

func ASTUpdateStatement_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUpdateStatement_returning(
		arg0,
		arg1,
	)
}

func parser_ASTUpdateStatement_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUpdateStatement_returning(arg0, arg1)
}

func ASTTruncateStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTruncateStatement_target_path(
		arg0,
		arg1,
	)
}

func parser_ASTTruncateStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTruncateStatement_target_path(arg0, arg1)
}

func ASTTruncateStatement_where(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTruncateStatement_where(
		arg0,
		arg1,
	)
}

func parser_ASTTruncateStatement_where(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTruncateStatement_where(arg0, arg1)
}

func ASTMergeAction_set_action_type(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTMergeAction_set_action_type(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTMergeAction_set_action_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTMergeAction_set_action_type(arg0, arg1)
}

func ASTMergeAction_action_type(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTMergeAction_action_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTMergeAction_action_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTMergeAction_action_type(arg0, arg1)
}

func ASTMergeAction_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTMergeAction_insert_column_list(
		arg0,
		arg1,
	)
}

func parser_ASTMergeAction_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTMergeAction_insert_column_list(arg0, arg1)
}

func ASTMergeAction_insert_row(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTMergeAction_insert_row(
		arg0,
		arg1,
	)
}

func parser_ASTMergeAction_insert_row(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTMergeAction_insert_row(arg0, arg1)
}

func ASTMergeAction_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTMergeAction_update_item_list(
		arg0,
		arg1,
	)
}

func parser_ASTMergeAction_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTMergeAction_update_item_list(arg0, arg1)
}

func ASTMergeWhenClause_set_match_type(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTMergeWhenClause_set_match_type(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTMergeWhenClause_set_match_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTMergeWhenClause_set_match_type(arg0, arg1)
}

func ASTMergeWhenClause_match_type(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTMergeWhenClause_match_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTMergeWhenClause_match_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTMergeWhenClause_match_type(arg0, arg1)
}

func ASTMergeWhenClause_search_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTMergeWhenClause_search_condition(
		arg0,
		arg1,
	)
}

func parser_ASTMergeWhenClause_search_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTMergeWhenClause_search_condition(arg0, arg1)
}

func ASTMergeWhenClause_action(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTMergeWhenClause_action(
		arg0,
		arg1,
	)
}

func parser_ASTMergeWhenClause_action(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTMergeWhenClause_action(arg0, arg1)
}

func ASTMergeWhenClause_GetSQLForMatchType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTMergeWhenClause_GetSQLForMatchType(
		arg0,
		arg1,
	)
}

func parser_ASTMergeWhenClause_GetSQLForMatchType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTMergeWhenClause_GetSQLForMatchType(arg0, arg1)
}

func ASTMergeWhenClauseList_clause_list_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTMergeWhenClauseList_clause_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTMergeWhenClauseList_clause_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTMergeWhenClauseList_clause_list_num(arg0, arg1)
}

func ASTMergeWhenClauseList_clause_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTMergeWhenClauseList_clause_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTMergeWhenClauseList_clause_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTMergeWhenClauseList_clause_list(arg0, arg1, arg2)
}

func ASTMergeStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTMergeStatement_target_path(
		arg0,
		arg1,
	)
}

func parser_ASTMergeStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTMergeStatement_target_path(arg0, arg1)
}

func ASTMergeStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTMergeStatement_alias(
		arg0,
		arg1,
	)
}

func parser_ASTMergeStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTMergeStatement_alias(arg0, arg1)
}

func ASTMergeStatement_table_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTMergeStatement_table_expression(
		arg0,
		arg1,
	)
}

func parser_ASTMergeStatement_table_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTMergeStatement_table_expression(arg0, arg1)
}

func ASTMergeStatement_merge_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTMergeStatement_merge_condition(
		arg0,
		arg1,
	)
}

func parser_ASTMergeStatement_merge_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTMergeStatement_merge_condition(arg0, arg1)
}

func ASTMergeStatement_when_clauses(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTMergeStatement_when_clauses(
		arg0,
		arg1,
	)
}

func parser_ASTMergeStatement_when_clauses(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTMergeStatement_when_clauses(arg0, arg1)
}

func ASTPrivilege_privilege_action(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTPrivilege_privilege_action(
		arg0,
		arg1,
	)
}

func parser_ASTPrivilege_privilege_action(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPrivilege_privilege_action(arg0, arg1)
}

func ASTPrivilege_paths(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTPrivilege_paths(
		arg0,
		arg1,
	)
}

func parser_ASTPrivilege_paths(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPrivilege_paths(arg0, arg1)
}

func ASTPrivileges_privileges_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTPrivileges_privileges_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTPrivileges_privileges_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTPrivileges_privileges_num(arg0, arg1)
}

func ASTPrivileges_privilege(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTPrivileges_privilege(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTPrivileges_privilege(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPrivileges_privilege(arg0, arg1, arg2)
}

func ASTPrivileges_is_all_privileges(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTPrivileges_is_all_privileges(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTPrivileges_is_all_privileges(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTPrivileges_is_all_privileges(arg0, arg1)
}

func ASTGranteeList_grantee_list_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTGranteeList_grantee_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTGranteeList_grantee_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTGranteeList_grantee_list_num(arg0, arg1)
}

func ASTGranteeList_grantee_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTGranteeList_grantee_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTGranteeList_grantee_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTGranteeList_grantee_list(arg0, arg1, arg2)
}

func ASTGrantStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTGrantStatement_privileges(
		arg0,
		arg1,
	)
}

func parser_ASTGrantStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTGrantStatement_privileges(arg0, arg1)
}

func ASTGrantStatement_target_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTGrantStatement_target_type(
		arg0,
		arg1,
	)
}

func parser_ASTGrantStatement_target_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTGrantStatement_target_type(arg0, arg1)
}

func ASTGrantStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTGrantStatement_target_path(
		arg0,
		arg1,
	)
}

func parser_ASTGrantStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTGrantStatement_target_path(arg0, arg1)
}

func ASTGrantStatement_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTGrantStatement_grantee_list(
		arg0,
		arg1,
	)
}

func parser_ASTGrantStatement_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTGrantStatement_grantee_list(arg0, arg1)
}

func ASTRevokeStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRevokeStatement_privileges(
		arg0,
		arg1,
	)
}

func parser_ASTRevokeStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRevokeStatement_privileges(arg0, arg1)
}

func ASTRevokeStatement_target_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRevokeStatement_target_type(
		arg0,
		arg1,
	)
}

func parser_ASTRevokeStatement_target_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRevokeStatement_target_type(arg0, arg1)
}

func ASTRevokeStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRevokeStatement_target_path(
		arg0,
		arg1,
	)
}

func parser_ASTRevokeStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRevokeStatement_target_path(arg0, arg1)
}

func ASTRevokeStatement_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRevokeStatement_grantee_list(
		arg0,
		arg1,
	)
}

func parser_ASTRevokeStatement_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRevokeStatement_grantee_list(arg0, arg1)
}

func ASTRepeatableClause_argument(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRepeatableClause_argument(
		arg0,
		arg1,
	)
}

func parser_ASTRepeatableClause_argument(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRepeatableClause_argument(arg0, arg1)
}

func ASTFilterFieldsArg_set_filter_type(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTFilterFieldsArg_set_filter_type(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTFilterFieldsArg_set_filter_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTFilterFieldsArg_set_filter_type(arg0, arg1)
}

func ASTFilterFieldsArg_filter_type(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTFilterFieldsArg_filter_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTFilterFieldsArg_filter_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTFilterFieldsArg_filter_type(arg0, arg1)
}

func ASTFilterFieldsArg_path_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFilterFieldsArg_path_expression(
		arg0,
		arg1,
	)
}

func parser_ASTFilterFieldsArg_path_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFilterFieldsArg_path_expression(arg0, arg1)
}

func ASTFilterFieldsArg_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFilterFieldsArg_GetSQLForOperator(
		arg0,
		arg1,
	)
}

func parser_ASTFilterFieldsArg_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFilterFieldsArg_GetSQLForOperator(arg0, arg1)
}

func ASTReplaceFieldsArg_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTReplaceFieldsArg_expression(
		arg0,
		arg1,
	)
}

func parser_ASTReplaceFieldsArg_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTReplaceFieldsArg_expression(arg0, arg1)
}

func ASTReplaceFieldsArg_path_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTReplaceFieldsArg_path_expression(
		arg0,
		arg1,
	)
}

func parser_ASTReplaceFieldsArg_path_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTReplaceFieldsArg_path_expression(arg0, arg1)
}

func ASTReplaceFieldsExpression_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTReplaceFieldsExpression_expr(
		arg0,
		arg1,
	)
}

func parser_ASTReplaceFieldsExpression_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTReplaceFieldsExpression_expr(arg0, arg1)
}

func ASTReplaceFieldsExpression_arguments_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTReplaceFieldsExpression_arguments_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTReplaceFieldsExpression_arguments_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTReplaceFieldsExpression_arguments_num(arg0, arg1)
}

func ASTReplaceFieldsExpression_argument(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTReplaceFieldsExpression_argument(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTReplaceFieldsExpression_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTReplaceFieldsExpression_argument(arg0, arg1, arg2)
}

func ASTSampleSize_set_unit(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTSampleSize_set_unit(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTSampleSize_set_unit(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTSampleSize_set_unit(arg0, arg1)
}

func ASTSampleSize_unit(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTSampleSize_unit(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTSampleSize_unit(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTSampleSize_unit(arg0, arg1)
}

func ASTSampleSize_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSampleSize_size(
		arg0,
		arg1,
	)
}

func parser_ASTSampleSize_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSampleSize_size(arg0, arg1)
}

func ASTSampleSize_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSampleSize_partition_by(
		arg0,
		arg1,
	)
}

func parser_ASTSampleSize_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSampleSize_partition_by(arg0, arg1)
}

func ASTSampleSize_GetSQLForUnit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSampleSize_GetSQLForUnit(
		arg0,
		arg1,
	)
}

func parser_ASTSampleSize_GetSQLForUnit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSampleSize_GetSQLForUnit(arg0, arg1)
}

func ASTWithWeight_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWithWeight_alias(
		arg0,
		arg1,
	)
}

func parser_ASTWithWeight_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWithWeight_alias(arg0, arg1)
}

func ASTSampleSuffix_weight(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSampleSuffix_weight(
		arg0,
		arg1,
	)
}

func parser_ASTSampleSuffix_weight(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSampleSuffix_weight(arg0, arg1)
}

func ASTSampleSuffix_repeat(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSampleSuffix_repeat(
		arg0,
		arg1,
	)
}

func parser_ASTSampleSuffix_repeat(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSampleSuffix_repeat(arg0, arg1)
}

func ASTSampleClause_sample_method(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSampleClause_sample_method(
		arg0,
		arg1,
	)
}

func parser_ASTSampleClause_sample_method(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSampleClause_sample_method(arg0, arg1)
}

func ASTSampleClause_sample_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSampleClause_sample_size(
		arg0,
		arg1,
	)
}

func parser_ASTSampleClause_sample_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSampleClause_sample_size(arg0, arg1)
}

func ASTSampleClause_sample_suffix(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSampleClause_sample_suffix(
		arg0,
		arg1,
	)
}

func parser_ASTSampleClause_sample_suffix(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSampleClause_sample_suffix(arg0, arg1)
}

func ASTAlterAction_GetSQLForAlterAction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterAction_GetSQLForAlterAction(
		arg0,
		arg1,
	)
}

func parser_ASTAlterAction_GetSQLForAlterAction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterAction_GetSQLForAlterAction(arg0, arg1)
}

func ASTSetOptionsAction_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSetOptionsAction_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTSetOptionsAction_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSetOptionsAction_options_list(arg0, arg1)
}

func ASTSetAsAction_json_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSetAsAction_json_body(
		arg0,
		arg1,
	)
}

func parser_ASTSetAsAction_json_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSetAsAction_json_body(arg0, arg1)
}

func ASTSetAsAction_text_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSetAsAction_text_body(
		arg0,
		arg1,
	)
}

func parser_ASTSetAsAction_text_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSetAsAction_text_body(arg0, arg1)
}

func ASTAddConstraintAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTAddConstraintAction_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTAddConstraintAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTAddConstraintAction_set_is_if_not_exists(arg0, arg1)
}

func ASTAddConstraintAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTAddConstraintAction_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAddConstraintAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTAddConstraintAction_is_if_not_exists(arg0, arg1)
}

func ASTAddConstraintAction_constraint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAddConstraintAction_constraint(
		arg0,
		arg1,
	)
}

func parser_ASTAddConstraintAction_constraint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAddConstraintAction_constraint(arg0, arg1)
}

func ASTDropPrimaryKeyAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDropPrimaryKeyAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDropPrimaryKeyAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDropPrimaryKeyAction_set_is_if_exists(arg0, arg1)
}

func ASTDropPrimaryKeyAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTDropPrimaryKeyAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDropPrimaryKeyAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTDropPrimaryKeyAction_is_if_exists(arg0, arg1)
}

func ASTDropConstraintAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDropConstraintAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDropConstraintAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDropConstraintAction_set_is_if_exists(arg0, arg1)
}

func ASTDropConstraintAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTDropConstraintAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDropConstraintAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTDropConstraintAction_is_if_exists(arg0, arg1)
}

func ASTDropConstraintAction_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropConstraintAction_constraint_name(
		arg0,
		arg1,
	)
}

func parser_ASTDropConstraintAction_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropConstraintAction_constraint_name(arg0, arg1)
}

func ASTAlterConstraintEnforcementAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTAlterConstraintEnforcementAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTAlterConstraintEnforcementAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTAlterConstraintEnforcementAction_set_is_if_exists(arg0, arg1)
}

func ASTAlterConstraintEnforcementAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTAlterConstraintEnforcementAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAlterConstraintEnforcementAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTAlterConstraintEnforcementAction_is_if_exists(arg0, arg1)
}

func ASTAlterConstraintEnforcementAction_set_is_enforced(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTAlterConstraintEnforcementAction_set_is_enforced(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTAlterConstraintEnforcementAction_set_is_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTAlterConstraintEnforcementAction_set_is_enforced(arg0, arg1)
}

func ASTAlterConstraintEnforcementAction_is_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTAlterConstraintEnforcementAction_is_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAlterConstraintEnforcementAction_is_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTAlterConstraintEnforcementAction_is_enforced(arg0, arg1)
}

func ASTAlterConstraintEnforcementAction_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterConstraintEnforcementAction_constraint_name(
		arg0,
		arg1,
	)
}

func parser_ASTAlterConstraintEnforcementAction_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterConstraintEnforcementAction_constraint_name(arg0, arg1)
}

func ASTAlterConstraintSetOptionsAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTAlterConstraintSetOptionsAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTAlterConstraintSetOptionsAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTAlterConstraintSetOptionsAction_set_is_if_exists(arg0, arg1)
}

func ASTAlterConstraintSetOptionsAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTAlterConstraintSetOptionsAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAlterConstraintSetOptionsAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTAlterConstraintSetOptionsAction_is_if_exists(arg0, arg1)
}

func ASTAlterConstraintSetOptionsAction_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterConstraintSetOptionsAction_constraint_name(
		arg0,
		arg1,
	)
}

func parser_ASTAlterConstraintSetOptionsAction_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterConstraintSetOptionsAction_constraint_name(arg0, arg1)
}

func ASTAlterConstraintSetOptionsAction_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterConstraintSetOptionsAction_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTAlterConstraintSetOptionsAction_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterConstraintSetOptionsAction_options_list(arg0, arg1)
}

func ASTAddColumnAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTAddColumnAction_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTAddColumnAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTAddColumnAction_set_is_if_not_exists(arg0, arg1)
}

func ASTAddColumnAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTAddColumnAction_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAddColumnAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTAddColumnAction_is_if_not_exists(arg0, arg1)
}

func ASTAddColumnAction_column_definition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAddColumnAction_column_definition(
		arg0,
		arg1,
	)
}

func parser_ASTAddColumnAction_column_definition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAddColumnAction_column_definition(arg0, arg1)
}

func ASTAddColumnAction_column_position(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAddColumnAction_column_position(
		arg0,
		arg1,
	)
}

func parser_ASTAddColumnAction_column_position(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAddColumnAction_column_position(arg0, arg1)
}

func ASTAddColumnAction_fill_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAddColumnAction_fill_expression(
		arg0,
		arg1,
	)
}

func parser_ASTAddColumnAction_fill_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAddColumnAction_fill_expression(arg0, arg1)
}

func ASTDropColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDropColumnAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDropColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDropColumnAction_set_is_if_exists(arg0, arg1)
}

func ASTDropColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTDropColumnAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDropColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTDropColumnAction_is_if_exists(arg0, arg1)
}

func ASTDropColumnAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropColumnAction_column_name(
		arg0,
		arg1,
	)
}

func parser_ASTDropColumnAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropColumnAction_column_name(arg0, arg1)
}

func ASTRenameColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTRenameColumnAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTRenameColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTRenameColumnAction_set_is_if_exists(arg0, arg1)
}

func ASTRenameColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTRenameColumnAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTRenameColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTRenameColumnAction_is_if_exists(arg0, arg1)
}

func ASTRenameColumnAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRenameColumnAction_column_name(
		arg0,
		arg1,
	)
}

func parser_ASTRenameColumnAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRenameColumnAction_column_name(arg0, arg1)
}

func ASTRenameColumnAction_new_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRenameColumnAction_new_column_name(
		arg0,
		arg1,
	)
}

func parser_ASTRenameColumnAction_new_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRenameColumnAction_new_column_name(arg0, arg1)
}

func ASTAlterColumnTypeAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTAlterColumnTypeAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTAlterColumnTypeAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTAlterColumnTypeAction_set_is_if_exists(arg0, arg1)
}

func ASTAlterColumnTypeAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTAlterColumnTypeAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAlterColumnTypeAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTAlterColumnTypeAction_is_if_exists(arg0, arg1)
}

func ASTAlterColumnTypeAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterColumnTypeAction_column_name(
		arg0,
		arg1,
	)
}

func parser_ASTAlterColumnTypeAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterColumnTypeAction_column_name(arg0, arg1)
}

func ASTAlterColumnTypeAction_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterColumnTypeAction_schema(
		arg0,
		arg1,
	)
}

func parser_ASTAlterColumnTypeAction_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterColumnTypeAction_schema(arg0, arg1)
}

func ASTAlterColumnTypeAction_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterColumnTypeAction_collate(
		arg0,
		arg1,
	)
}

func parser_ASTAlterColumnTypeAction_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterColumnTypeAction_collate(arg0, arg1)
}

func ASTAlterColumnOptionsAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTAlterColumnOptionsAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTAlterColumnOptionsAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTAlterColumnOptionsAction_set_is_if_exists(arg0, arg1)
}

func ASTAlterColumnOptionsAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTAlterColumnOptionsAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAlterColumnOptionsAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTAlterColumnOptionsAction_is_if_exists(arg0, arg1)
}

func ASTAlterColumnOptionsAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterColumnOptionsAction_column_name(
		arg0,
		arg1,
	)
}

func parser_ASTAlterColumnOptionsAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterColumnOptionsAction_column_name(arg0, arg1)
}

func ASTAlterColumnOptionsAction_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterColumnOptionsAction_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTAlterColumnOptionsAction_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterColumnOptionsAction_options_list(arg0, arg1)
}

func ASTAlterColumnSetDefaultAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTAlterColumnSetDefaultAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTAlterColumnSetDefaultAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTAlterColumnSetDefaultAction_set_is_if_exists(arg0, arg1)
}

func ASTAlterColumnSetDefaultAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTAlterColumnSetDefaultAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAlterColumnSetDefaultAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTAlterColumnSetDefaultAction_is_if_exists(arg0, arg1)
}

func ASTAlterColumnSetDefaultAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterColumnSetDefaultAction_column_name(
		arg0,
		arg1,
	)
}

func parser_ASTAlterColumnSetDefaultAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterColumnSetDefaultAction_column_name(arg0, arg1)
}

func ASTAlterColumnSetDefaultAction_default_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterColumnSetDefaultAction_default_expression(
		arg0,
		arg1,
	)
}

func parser_ASTAlterColumnSetDefaultAction_default_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterColumnSetDefaultAction_default_expression(arg0, arg1)
}

func ASTAlterColumnDropDefaultAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTAlterColumnDropDefaultAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTAlterColumnDropDefaultAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTAlterColumnDropDefaultAction_set_is_if_exists(arg0, arg1)
}

func ASTAlterColumnDropDefaultAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTAlterColumnDropDefaultAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAlterColumnDropDefaultAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTAlterColumnDropDefaultAction_is_if_exists(arg0, arg1)
}

func ASTAlterColumnDropDefaultAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterColumnDropDefaultAction_column_name(
		arg0,
		arg1,
	)
}

func parser_ASTAlterColumnDropDefaultAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterColumnDropDefaultAction_column_name(arg0, arg1)
}

func ASTAlterColumnDropNotNullAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTAlterColumnDropNotNullAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTAlterColumnDropNotNullAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTAlterColumnDropNotNullAction_set_is_if_exists(arg0, arg1)
}

func ASTAlterColumnDropNotNullAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTAlterColumnDropNotNullAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAlterColumnDropNotNullAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTAlterColumnDropNotNullAction_is_if_exists(arg0, arg1)
}

func ASTAlterColumnDropNotNullAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterColumnDropNotNullAction_column_name(
		arg0,
		arg1,
	)
}

func parser_ASTAlterColumnDropNotNullAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterColumnDropNotNullAction_column_name(arg0, arg1)
}

func ASTGrantToClause_set_has_grant_keyword_and_parens(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTGrantToClause_set_has_grant_keyword_and_parens(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTGrantToClause_set_has_grant_keyword_and_parens(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTGrantToClause_set_has_grant_keyword_and_parens(arg0, arg1)
}

func ASTGrantToClause_has_grant_keyword_and_parens(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTGrantToClause_has_grant_keyword_and_parens(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTGrantToClause_has_grant_keyword_and_parens(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTGrantToClause_has_grant_keyword_and_parens(arg0, arg1)
}

func ASTGrantToClause_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTGrantToClause_grantee_list(
		arg0,
		arg1,
	)
}

func parser_ASTGrantToClause_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTGrantToClause_grantee_list(arg0, arg1)
}

func ASTRestrictToClause_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRestrictToClause_restrictee_list(
		arg0,
		arg1,
	)
}

func parser_ASTRestrictToClause_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRestrictToClause_restrictee_list(arg0, arg1)
}

func ASTAddToRestricteeListClause_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTAddToRestricteeListClause_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTAddToRestricteeListClause_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTAddToRestricteeListClause_set_is_if_not_exists(arg0, arg1)
}

func ASTAddToRestricteeListClause_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTAddToRestricteeListClause_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAddToRestricteeListClause_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTAddToRestricteeListClause_is_if_not_exists(arg0, arg1)
}

func ASTAddToRestricteeListClause_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAddToRestricteeListClause_restrictee_list(
		arg0,
		arg1,
	)
}

func parser_ASTAddToRestricteeListClause_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAddToRestricteeListClause_restrictee_list(arg0, arg1)
}

func ASTRemoveFromRestricteeListClause_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTRemoveFromRestricteeListClause_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTRemoveFromRestricteeListClause_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTRemoveFromRestricteeListClause_set_is_if_exists(arg0, arg1)
}

func ASTRemoveFromRestricteeListClause_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTRemoveFromRestricteeListClause_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTRemoveFromRestricteeListClause_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTRemoveFromRestricteeListClause_is_if_exists(arg0, arg1)
}

func ASTRemoveFromRestricteeListClause_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRemoveFromRestricteeListClause_restrictee_list(
		arg0,
		arg1,
	)
}

func parser_ASTRemoveFromRestricteeListClause_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRemoveFromRestricteeListClause_restrictee_list(arg0, arg1)
}

func ASTFilterUsingClause_set_has_filter_keyword(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTFilterUsingClause_set_has_filter_keyword(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTFilterUsingClause_set_has_filter_keyword(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTFilterUsingClause_set_has_filter_keyword(arg0, arg1)
}

func ASTFilterUsingClause_has_filter_keyword(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTFilterUsingClause_has_filter_keyword(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTFilterUsingClause_has_filter_keyword(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTFilterUsingClause_has_filter_keyword(arg0, arg1)
}

func ASTFilterUsingClause_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTFilterUsingClause_predicate(
		arg0,
		arg1,
	)
}

func parser_ASTFilterUsingClause_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTFilterUsingClause_predicate(arg0, arg1)
}

func ASTRevokeFromClause_set_is_revoke_from_all(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTRevokeFromClause_set_is_revoke_from_all(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTRevokeFromClause_set_is_revoke_from_all(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTRevokeFromClause_set_is_revoke_from_all(arg0, arg1)
}

func ASTRevokeFromClause_is_revoke_from_all(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTRevokeFromClause_is_revoke_from_all(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTRevokeFromClause_is_revoke_from_all(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTRevokeFromClause_is_revoke_from_all(arg0, arg1)
}

func ASTRevokeFromClause_revoke_from_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRevokeFromClause_revoke_from_list(
		arg0,
		arg1,
	)
}

func parser_ASTRevokeFromClause_revoke_from_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRevokeFromClause_revoke_from_list(arg0, arg1)
}

func ASTRenameToClause_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRenameToClause_new_name(
		arg0,
		arg1,
	)
}

func parser_ASTRenameToClause_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRenameToClause_new_name(arg0, arg1)
}

func ASTSetCollateClause_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSetCollateClause_collate(
		arg0,
		arg1,
	)
}

func parser_ASTSetCollateClause_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSetCollateClause_collate(arg0, arg1)
}

func ASTAlterActionList_actions_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTAlterActionList_actions_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAlterActionList_actions_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTAlterActionList_actions_num(arg0, arg1)
}

func ASTAlterActionList_action(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTAlterActionList_action(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTAlterActionList_action(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterActionList_action(arg0, arg1, arg2)
}

func ASTAlterAllRowAccessPoliciesStatement_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterAllRowAccessPoliciesStatement_table_name_path(
		arg0,
		arg1,
	)
}

func parser_ASTAlterAllRowAccessPoliciesStatement_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterAllRowAccessPoliciesStatement_table_name_path(arg0, arg1)
}

func ASTAlterAllRowAccessPoliciesStatement_alter_action(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterAllRowAccessPoliciesStatement_alter_action(
		arg0,
		arg1,
	)
}

func parser_ASTAlterAllRowAccessPoliciesStatement_alter_action(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterAllRowAccessPoliciesStatement_alter_action(arg0, arg1)
}

func ASTForeignKeyActions_set_udpate_action(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTForeignKeyActions_set_udpate_action(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTForeignKeyActions_set_udpate_action(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTForeignKeyActions_set_udpate_action(arg0, arg1)
}

func ASTForeignKeyActions_udpate_action(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTForeignKeyActions_udpate_action(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTForeignKeyActions_udpate_action(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTForeignKeyActions_udpate_action(arg0, arg1)
}

func ASTForeignKeyActions_set_delete_action(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTForeignKeyActions_set_delete_action(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTForeignKeyActions_set_delete_action(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTForeignKeyActions_set_delete_action(arg0, arg1)
}

func ASTForeignKeyActions_delete_action(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTForeignKeyActions_delete_action(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTForeignKeyActions_delete_action(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTForeignKeyActions_delete_action(arg0, arg1)
}

func ASTForeignKeyReference_set_match(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTForeignKeyReference_set_match(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTForeignKeyReference_set_match(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTForeignKeyReference_set_match(arg0, arg1)
}

func ASTForeignKeyReference_match(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTForeignKeyReference_match(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTForeignKeyReference_match(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTForeignKeyReference_match(arg0, arg1)
}

func ASTForeignKeyReference_set_enforced(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTForeignKeyReference_set_enforced(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTForeignKeyReference_set_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTForeignKeyReference_set_enforced(arg0, arg1)
}

func ASTForeignKeyReference_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTForeignKeyReference_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTForeignKeyReference_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTForeignKeyReference_enforced(arg0, arg1)
}

func ASTForeignKeyReference_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTForeignKeyReference_table_name(
		arg0,
		arg1,
	)
}

func parser_ASTForeignKeyReference_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTForeignKeyReference_table_name(arg0, arg1)
}

func ASTForeignKeyReference_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTForeignKeyReference_column_list(
		arg0,
		arg1,
	)
}

func parser_ASTForeignKeyReference_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTForeignKeyReference_column_list(arg0, arg1)
}

func ASTForeignKeyReference_actions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTForeignKeyReference_actions(
		arg0,
		arg1,
	)
}

func parser_ASTForeignKeyReference_actions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTForeignKeyReference_actions(arg0, arg1)
}

func ASTScript_statement_list_node(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTScript_statement_list_node(
		arg0,
		arg1,
	)
}

func parser_ASTScript_statement_list_node(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTScript_statement_list_node(arg0, arg1)
}

func ASTScript_statement_list_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTScript_statement_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTScript_statement_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTScript_statement_list_num(arg0, arg1)
}

func ASTScript_statement_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTScript_statement_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTScript_statement_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTScript_statement_list(arg0, arg1, arg2)
}

func ASTElseifClause_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTElseifClause_condition(
		arg0,
		arg1,
	)
}

func parser_ASTElseifClause_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTElseifClause_condition(arg0, arg1)
}

func ASTElseifClause_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTElseifClause_body(
		arg0,
		arg1,
	)
}

func parser_ASTElseifClause_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTElseifClause_body(arg0, arg1)
}

func ASTElseifClause_if_stmt(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTElseifClause_if_stmt(
		arg0,
		arg1,
	)
}

func parser_ASTElseifClause_if_stmt(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTElseifClause_if_stmt(arg0, arg1)
}

func ASTElseifClauseList_elseif_clauses_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTElseifClauseList_elseif_clauses_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTElseifClauseList_elseif_clauses_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTElseifClauseList_elseif_clauses_num(arg0, arg1)
}

func ASTElseifClauseList_elseif_clause(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTElseifClauseList_elseif_clause(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTElseifClauseList_elseif_clause(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTElseifClauseList_elseif_clause(arg0, arg1, arg2)
}

func ASTIfStatement_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTIfStatement_condition(
		arg0,
		arg1,
	)
}

func parser_ASTIfStatement_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTIfStatement_condition(arg0, arg1)
}

func ASTIfStatement_then_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTIfStatement_then_list(
		arg0,
		arg1,
	)
}

func parser_ASTIfStatement_then_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTIfStatement_then_list(arg0, arg1)
}

func ASTIfStatement_elseif_clauses(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTIfStatement_elseif_clauses(
		arg0,
		arg1,
	)
}

func parser_ASTIfStatement_elseif_clauses(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTIfStatement_elseif_clauses(arg0, arg1)
}

func ASTIfStatement_else_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTIfStatement_else_list(
		arg0,
		arg1,
	)
}

func parser_ASTIfStatement_else_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTIfStatement_else_list(arg0, arg1)
}

func ASTWhenThenClause_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWhenThenClause_condition(
		arg0,
		arg1,
	)
}

func parser_ASTWhenThenClause_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWhenThenClause_condition(arg0, arg1)
}

func ASTWhenThenClause_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWhenThenClause_body(
		arg0,
		arg1,
	)
}

func parser_ASTWhenThenClause_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWhenThenClause_body(arg0, arg1)
}

func ASTWhenThenClause_case_stmt(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWhenThenClause_case_stmt(
		arg0,
		arg1,
	)
}

func parser_ASTWhenThenClause_case_stmt(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWhenThenClause_case_stmt(arg0, arg1)
}

func ASTWhenThenClauseList_when_then_clauses_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTWhenThenClauseList_when_then_clauses_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTWhenThenClauseList_when_then_clauses_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTWhenThenClauseList_when_then_clauses_num(arg0, arg1)
}

func ASTWhenThenClauseList_when_then_clause(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTWhenThenClauseList_when_then_clause(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTWhenThenClauseList_when_then_clause(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWhenThenClauseList_when_then_clause(arg0, arg1, arg2)
}

func ASTCaseStatement_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCaseStatement_expression(
		arg0,
		arg1,
	)
}

func parser_ASTCaseStatement_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCaseStatement_expression(arg0, arg1)
}

func ASTCaseStatement_when_then_clauses(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCaseStatement_when_then_clauses(
		arg0,
		arg1,
	)
}

func parser_ASTCaseStatement_when_then_clauses(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCaseStatement_when_then_clauses(arg0, arg1)
}

func ASTCaseStatement_else_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCaseStatement_else_list(
		arg0,
		arg1,
	)
}

func parser_ASTCaseStatement_else_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCaseStatement_else_list(arg0, arg1)
}

func ASTHint_num_shards_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTHint_num_shards_hint(
		arg0,
		arg1,
	)
}

func parser_ASTHint_num_shards_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTHint_num_shards_hint(arg0, arg1)
}

func ASTHint_hint_entries_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTHint_hint_entries_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTHint_hint_entries_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTHint_hint_entries_num(arg0, arg1)
}

func ASTHint_hint_entry(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTHint_hint_entry(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTHint_hint_entry(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTHint_hint_entry(arg0, arg1, arg2)
}

func ASTHintEntry_qualifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTHintEntry_qualifier(
		arg0,
		arg1,
	)
}

func parser_ASTHintEntry_qualifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTHintEntry_qualifier(arg0, arg1)
}

func ASTHintEntry_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTHintEntry_name(
		arg0,
		arg1,
	)
}

func parser_ASTHintEntry_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTHintEntry_name(arg0, arg1)
}

func ASTHintEntry_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTHintEntry_value(
		arg0,
		arg1,
	)
}

func parser_ASTHintEntry_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTHintEntry_value(arg0, arg1)
}

func ASTUnpivotInItemLabel_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUnpivotInItemLabel_label(
		arg0,
		arg1,
	)
}

func parser_ASTUnpivotInItemLabel_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUnpivotInItemLabel_label(arg0, arg1)
}

func ASTDescriptor_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDescriptor_columns(
		arg0,
		arg1,
	)
}

func parser_ASTDescriptor_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDescriptor_columns(arg0, arg1)
}

func ASTColumnSchema_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTColumnSchema_type_parameters(
		arg0,
		arg1,
	)
}

func parser_ASTColumnSchema_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTColumnSchema_type_parameters(arg0, arg1)
}

func ASTColumnSchema_generated_column_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTColumnSchema_generated_column_info(
		arg0,
		arg1,
	)
}

func parser_ASTColumnSchema_generated_column_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTColumnSchema_generated_column_info(arg0, arg1)
}

func ASTColumnSchema_default_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTColumnSchema_default_expression(
		arg0,
		arg1,
	)
}

func parser_ASTColumnSchema_default_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTColumnSchema_default_expression(arg0, arg1)
}

func ASTColumnSchema_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTColumnSchema_collate(
		arg0,
		arg1,
	)
}

func parser_ASTColumnSchema_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTColumnSchema_collate(arg0, arg1)
}

func ASTColumnSchema_attributes(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTColumnSchema_attributes(
		arg0,
		arg1,
	)
}

func parser_ASTColumnSchema_attributes(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTColumnSchema_attributes(arg0, arg1)
}

func ASTColumnSchema_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTColumnSchema_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTColumnSchema_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTColumnSchema_options_list(arg0, arg1)
}

func ASTColumnSchema_ContainsAttribute(arg0 unsafe.Pointer, arg1 int, arg2 *bool) {
	parser_ASTColumnSchema_ContainsAttribute(
		arg0,
		C.int(arg1),
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func parser_ASTColumnSchema_ContainsAttribute(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.char) {
	C.export_zetasql_parser_parser_ASTColumnSchema_ContainsAttribute(arg0, arg1, arg2)
}

func ASTSimpleColumnSchema_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSimpleColumnSchema_type_name(
		arg0,
		arg1,
	)
}

func parser_ASTSimpleColumnSchema_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSimpleColumnSchema_type_name(arg0, arg1)
}

func ASTArrayColumnSchema_element_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTArrayColumnSchema_element_schema(
		arg0,
		arg1,
	)
}

func parser_ASTArrayColumnSchema_element_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTArrayColumnSchema_element_schema(arg0, arg1)
}

func ASTTableConstraint_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTTableConstraint_constraint_name(
		arg0,
		arg1,
	)
}

func parser_ASTTableConstraint_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTTableConstraint_constraint_name(arg0, arg1)
}

func ASTPrimaryKey_set_enforced(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTPrimaryKey_set_enforced(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTPrimaryKey_set_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTPrimaryKey_set_enforced(arg0, arg1)
}

func ASTPrimaryKey_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTPrimaryKey_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTPrimaryKey_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTPrimaryKey_enforced(arg0, arg1)
}

func ASTPrimaryKey_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTPrimaryKey_column_list(
		arg0,
		arg1,
	)
}

func parser_ASTPrimaryKey_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPrimaryKey_column_list(arg0, arg1)
}

func ASTPrimaryKey_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTPrimaryKey_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTPrimaryKey_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTPrimaryKey_options_list(arg0, arg1)
}

func ASTForeignKey_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTForeignKey_column_list(
		arg0,
		arg1,
	)
}

func parser_ASTForeignKey_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTForeignKey_column_list(arg0, arg1)
}

func ASTForeignKey_reference(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTForeignKey_reference(
		arg0,
		arg1,
	)
}

func parser_ASTForeignKey_reference(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTForeignKey_reference(arg0, arg1)
}

func ASTForeignKey_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTForeignKey_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTForeignKey_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTForeignKey_options_list(arg0, arg1)
}

func ASTCheckConstraint_set_is_enforced(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTCheckConstraint_set_is_enforced(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTCheckConstraint_set_is_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTCheckConstraint_set_is_enforced(arg0, arg1)
}

func ASTCheckConstraint_is_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTCheckConstraint_is_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCheckConstraint_is_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTCheckConstraint_is_enforced(arg0, arg1)
}

func ASTCheckConstraint_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCheckConstraint_expression(
		arg0,
		arg1,
	)
}

func parser_ASTCheckConstraint_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCheckConstraint_expression(arg0, arg1)
}

func ASTCheckConstraint_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCheckConstraint_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTCheckConstraint_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCheckConstraint_options_list(arg0, arg1)
}

func ASTDescriptorColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDescriptorColumn_name(
		arg0,
		arg1,
	)
}

func parser_ASTDescriptorColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDescriptorColumn_name(arg0, arg1)
}

func ASTDescriptorColumnList_descriptor_column_list_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTDescriptorColumnList_descriptor_column_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDescriptorColumnList_descriptor_column_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTDescriptorColumnList_descriptor_column_list_num(arg0, arg1)
}

func ASTDescriptorColumnList_descriptor_column_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTDescriptorColumnList_descriptor_column_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTDescriptorColumnList_descriptor_column_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDescriptorColumnList_descriptor_column_list(arg0, arg1, arg2)
}

func ASTCreateEntityStatement_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateEntityStatement_type(
		arg0,
		arg1,
	)
}

func parser_ASTCreateEntityStatement_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateEntityStatement_type(arg0, arg1)
}

func ASTCreateEntityStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateEntityStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTCreateEntityStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateEntityStatement_name(arg0, arg1)
}

func ASTCreateEntityStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateEntityStatement_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTCreateEntityStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateEntityStatement_options_list(arg0, arg1)
}

func ASTCreateEntityStatement_json_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateEntityStatement_json_body(
		arg0,
		arg1,
	)
}

func parser_ASTCreateEntityStatement_json_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateEntityStatement_json_body(arg0, arg1)
}

func ASTCreateEntityStatement_text_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateEntityStatement_text_body(
		arg0,
		arg1,
	)
}

func parser_ASTCreateEntityStatement_text_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateEntityStatement_text_body(arg0, arg1)
}

func ASTRaiseStatement_message(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRaiseStatement_message(
		arg0,
		arg1,
	)
}

func parser_ASTRaiseStatement_message(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRaiseStatement_message(arg0, arg1)
}

func ASTRaiseStatement_is_rethrow(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTRaiseStatement_is_rethrow(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTRaiseStatement_is_rethrow(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTRaiseStatement_is_rethrow(arg0, arg1)
}

func ASTExceptionHandler_statement_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExceptionHandler_statement_list(
		arg0,
		arg1,
	)
}

func parser_ASTExceptionHandler_statement_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExceptionHandler_statement_list(arg0, arg1)
}

func ASTExceptionHandlerList_exception_handler_list_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTExceptionHandlerList_exception_handler_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTExceptionHandlerList_exception_handler_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTExceptionHandlerList_exception_handler_list_num(arg0, arg1)
}

func ASTExceptionHandlerList_exception_handler_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTExceptionHandlerList_exception_handler_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTExceptionHandlerList_exception_handler_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExceptionHandlerList_exception_handler_list(arg0, arg1, arg2)
}

func ASTBeginEndBlock_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTBeginEndBlock_label(
		arg0,
		arg1,
	)
}

func parser_ASTBeginEndBlock_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTBeginEndBlock_label(arg0, arg1)
}

func ASTBeginEndBlock_statement_list_node(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTBeginEndBlock_statement_list_node(
		arg0,
		arg1,
	)
}

func parser_ASTBeginEndBlock_statement_list_node(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTBeginEndBlock_statement_list_node(arg0, arg1)
}

func ASTBeginEndBlock_handler_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTBeginEndBlock_handler_list(
		arg0,
		arg1,
	)
}

func parser_ASTBeginEndBlock_handler_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTBeginEndBlock_handler_list(arg0, arg1)
}

func ASTBeginEndBlock_statement_list_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTBeginEndBlock_statement_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTBeginEndBlock_statement_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTBeginEndBlock_statement_list_num(arg0, arg1)
}

func ASTBeginEndBlock_statement_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTBeginEndBlock_statement_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTBeginEndBlock_statement_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTBeginEndBlock_statement_list(arg0, arg1, arg2)
}

func ASTBeginEndBlock_has_exception_handler(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTBeginEndBlock_has_exception_handler(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTBeginEndBlock_has_exception_handler(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTBeginEndBlock_has_exception_handler(arg0, arg1)
}

func ASTIdentifierList_identifier_list_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTIdentifierList_identifier_list_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTIdentifierList_identifier_list_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTIdentifierList_identifier_list_num(arg0, arg1)
}

func ASTIdentifierList_identifier_list(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTIdentifierList_identifier_list(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTIdentifierList_identifier_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTIdentifierList_identifier_list(arg0, arg1, arg2)
}

func ASTVariableDeclaration_variable_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTVariableDeclaration_variable_list(
		arg0,
		arg1,
	)
}

func parser_ASTVariableDeclaration_variable_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTVariableDeclaration_variable_list(arg0, arg1)
}

func ASTVariableDeclaration_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTVariableDeclaration_type(
		arg0,
		arg1,
	)
}

func parser_ASTVariableDeclaration_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTVariableDeclaration_type(arg0, arg1)
}

func ASTVariableDeclaration_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTVariableDeclaration_default_value(
		arg0,
		arg1,
	)
}

func parser_ASTVariableDeclaration_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTVariableDeclaration_default_value(arg0, arg1)
}

func ASTUntilClause_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUntilClause_condition(
		arg0,
		arg1,
	)
}

func parser_ASTUntilClause_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUntilClause_condition(arg0, arg1)
}

func ASTUntilClause_repeat_stmt(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTUntilClause_repeat_stmt(
		arg0,
		arg1,
	)
}

func parser_ASTUntilClause_repeat_stmt(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTUntilClause_repeat_stmt(arg0, arg1)
}

func ASTBreakContinueStatement_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTBreakContinueStatement_label(
		arg0,
		arg1,
	)
}

func parser_ASTBreakContinueStatement_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTBreakContinueStatement_label(arg0, arg1)
}

func ASTBreakContinueStatement_set_keyword(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTBreakContinueStatement_set_keyword(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTBreakContinueStatement_set_keyword(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTBreakContinueStatement_set_keyword(arg0, arg1)
}

func ASTBreakContinueStatement_keyword(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTBreakContinueStatement_keyword(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTBreakContinueStatement_keyword(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTBreakContinueStatement_keyword(arg0, arg1)
}

func ASTBreakStatement_set_keyword(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTBreakStatement_set_keyword(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTBreakStatement_set_keyword(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTBreakStatement_set_keyword(arg0, arg1)
}

func ASTBreakStatement_keyword(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTBreakStatement_keyword(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTBreakStatement_keyword(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTBreakStatement_keyword(arg0, arg1)
}

func ASTContinueStatement_set_keyword(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTContinueStatement_set_keyword(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTContinueStatement_set_keyword(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTContinueStatement_set_keyword(arg0, arg1)
}

func ASTContinueStatement_keyword(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTContinueStatement_keyword(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTContinueStatement_keyword(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTContinueStatement_keyword(arg0, arg1)
}

func ASTDropPrivilegeRestrictionStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDropPrivilegeRestrictionStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDropPrivilegeRestrictionStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDropPrivilegeRestrictionStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropPrivilegeRestrictionStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTDropPrivilegeRestrictionStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDropPrivilegeRestrictionStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTDropPrivilegeRestrictionStatement_is_if_exists(arg0, arg1)
}

func ASTDropPrivilegeRestrictionStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropPrivilegeRestrictionStatement_privileges(
		arg0,
		arg1,
	)
}

func parser_ASTDropPrivilegeRestrictionStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropPrivilegeRestrictionStatement_privileges(arg0, arg1)
}

func ASTDropPrivilegeRestrictionStatement_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropPrivilegeRestrictionStatement_object_type(
		arg0,
		arg1,
	)
}

func parser_ASTDropPrivilegeRestrictionStatement_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropPrivilegeRestrictionStatement_object_type(arg0, arg1)
}

func ASTDropPrivilegeRestrictionStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropPrivilegeRestrictionStatement_name_path(
		arg0,
		arg1,
	)
}

func parser_ASTDropPrivilegeRestrictionStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropPrivilegeRestrictionStatement_name_path(arg0, arg1)
}

func ASTDropRowAccessPolicyStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDropRowAccessPolicyStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDropRowAccessPolicyStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDropRowAccessPolicyStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropRowAccessPolicyStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTDropRowAccessPolicyStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDropRowAccessPolicyStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTDropRowAccessPolicyStatement_is_if_exists(arg0, arg1)
}

func ASTDropRowAccessPolicyStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropRowAccessPolicyStatement_table_name(
		arg0,
		arg1,
	)
}

func parser_ASTDropRowAccessPolicyStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropRowAccessPolicyStatement_table_name(arg0, arg1)
}

func ASTDropRowAccessPolicyStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropRowAccessPolicyStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTDropRowAccessPolicyStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropRowAccessPolicyStatement_name(arg0, arg1)
}

func ASTCreatePrivilegeRestrictionStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreatePrivilegeRestrictionStatement_privileges(
		arg0,
		arg1,
	)
}

func parser_ASTCreatePrivilegeRestrictionStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreatePrivilegeRestrictionStatement_privileges(arg0, arg1)
}

func ASTCreatePrivilegeRestrictionStatement_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreatePrivilegeRestrictionStatement_object_type(
		arg0,
		arg1,
	)
}

func parser_ASTCreatePrivilegeRestrictionStatement_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreatePrivilegeRestrictionStatement_object_type(arg0, arg1)
}

func ASTCreatePrivilegeRestrictionStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreatePrivilegeRestrictionStatement_name_path(
		arg0,
		arg1,
	)
}

func parser_ASTCreatePrivilegeRestrictionStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreatePrivilegeRestrictionStatement_name_path(arg0, arg1)
}

func ASTCreatePrivilegeRestrictionStatement_restrict_to(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreatePrivilegeRestrictionStatement_restrict_to(
		arg0,
		arg1,
	)
}

func parser_ASTCreatePrivilegeRestrictionStatement_restrict_to(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreatePrivilegeRestrictionStatement_restrict_to(arg0, arg1)
}

func ASTCreateRowAccessPolicyStatement_set_has_access_keyword(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTCreateRowAccessPolicyStatement_set_has_access_keyword(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTCreateRowAccessPolicyStatement_set_has_access_keyword(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTCreateRowAccessPolicyStatement_set_has_access_keyword(arg0, arg1)
}

func ASTCreateRowAccessPolicyStatement_has_access_keyword(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTCreateRowAccessPolicyStatement_has_access_keyword(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCreateRowAccessPolicyStatement_has_access_keyword(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTCreateRowAccessPolicyStatement_has_access_keyword(arg0, arg1)
}

func ASTCreateRowAccessPolicyStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateRowAccessPolicyStatement_target_path(
		arg0,
		arg1,
	)
}

func parser_ASTCreateRowAccessPolicyStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateRowAccessPolicyStatement_target_path(arg0, arg1)
}

func ASTCreateRowAccessPolicyStatement_grant_to(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateRowAccessPolicyStatement_grant_to(
		arg0,
		arg1,
	)
}

func parser_ASTCreateRowAccessPolicyStatement_grant_to(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateRowAccessPolicyStatement_grant_to(arg0, arg1)
}

func ASTCreateRowAccessPolicyStatement_filter_using(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateRowAccessPolicyStatement_filter_using(
		arg0,
		arg1,
	)
}

func parser_ASTCreateRowAccessPolicyStatement_filter_using(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateRowAccessPolicyStatement_filter_using(arg0, arg1)
}

func ASTCreateRowAccessPolicyStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateRowAccessPolicyStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTCreateRowAccessPolicyStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateRowAccessPolicyStatement_name(arg0, arg1)
}

func ASTDropStatement_set_drop_mode(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDropStatement_set_drop_mode(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDropStatement_set_drop_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDropStatement_set_drop_mode(arg0, arg1)
}

func ASTDropStatement_drop_mode(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTDropStatement_drop_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDropStatement_drop_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTDropStatement_drop_mode(arg0, arg1)
}

func ASTDropStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDropStatement_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDropStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDropStatement_set_is_if_exists(arg0, arg1)
}

func ASTDropStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTDropStatement_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDropStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTDropStatement_is_if_exists(arg0, arg1)
}

func ASTDropStatement_set_schema_object_kind(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTDropStatement_set_schema_object_kind(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTDropStatement_set_schema_object_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTDropStatement_set_schema_object_kind(arg0, arg1)
}

func ASTDropStatement_schema_object_kind(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTDropStatement_schema_object_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTDropStatement_schema_object_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTDropStatement_schema_object_kind(arg0, arg1)
}

func ASTDropStatemnt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTDropStatemnt_name(
		arg0,
		arg1,
	)
}

func parser_ASTDropStatemnt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTDropStatemnt_name(arg0, arg1)
}

func ASTSingleAssignment_variable(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSingleAssignment_variable(
		arg0,
		arg1,
	)
}

func parser_ASTSingleAssignment_variable(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSingleAssignment_variable(arg0, arg1)
}

func ASTSingleAssignment_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSingleAssignment_expression(
		arg0,
		arg1,
	)
}

func parser_ASTSingleAssignment_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSingleAssignment_expression(arg0, arg1)
}

func ASTParameterAssignment_parameter(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTParameterAssignment_parameter(
		arg0,
		arg1,
	)
}

func parser_ASTParameterAssignment_parameter(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTParameterAssignment_parameter(arg0, arg1)
}

func ASTParameterAssignment_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTParameterAssignment_expression(
		arg0,
		arg1,
	)
}

func parser_ASTParameterAssignment_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTParameterAssignment_expression(arg0, arg1)
}

func ASTSystemVariableAssignment_system_variable(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSystemVariableAssignment_system_variable(
		arg0,
		arg1,
	)
}

func parser_ASTSystemVariableAssignment_system_variable(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSystemVariableAssignment_system_variable(arg0, arg1)
}

func ASTSystemVariableAssignment_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTSystemVariableAssignment_expression(
		arg0,
		arg1,
	)
}

func parser_ASTSystemVariableAssignment_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTSystemVariableAssignment_expression(arg0, arg1)
}

func ASTAssignmentFromStruct_variables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAssignmentFromStruct_variables(
		arg0,
		arg1,
	)
}

func parser_ASTAssignmentFromStruct_variables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAssignmentFromStruct_variables(arg0, arg1)
}

func ASTAssignmentFromStruct_struct_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAssignmentFromStruct_struct_expression(
		arg0,
		arg1,
	)
}

func parser_ASTAssignmentFromStruct_struct_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAssignmentFromStruct_struct_expression(arg0, arg1)
}

func ASTCreateTableStmtBase_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateTableStmtBase_name(
		arg0,
		arg1,
	)
}

func parser_ASTCreateTableStmtBase_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateTableStmtBase_name(arg0, arg1)
}

func ASTCreateTableStmtBase_table_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateTableStmtBase_table_element_list(
		arg0,
		arg1,
	)
}

func parser_ASTCreateTableStmtBase_table_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateTableStmtBase_table_element_list(arg0, arg1)
}

func ASTCreateTableStmtBase_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateTableStmtBase_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTCreateTableStmtBase_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateTableStmtBase_options_list(arg0, arg1)
}

func ASTCreateTableStmtBase_like_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateTableStmtBase_like_table_name(
		arg0,
		arg1,
	)
}

func parser_ASTCreateTableStmtBase_like_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateTableStmtBase_like_table_name(arg0, arg1)
}

func ASTCreateTableStmtBase_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateTableStmtBase_collate(
		arg0,
		arg1,
	)
}

func parser_ASTCreateTableStmtBase_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateTableStmtBase_collate(arg0, arg1)
}

func ASTCreateTableStatement_clone_data_source(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateTableStatement_clone_data_source(
		arg0,
		arg1,
	)
}

func parser_ASTCreateTableStatement_clone_data_source(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateTableStatement_clone_data_source(arg0, arg1)
}

func ASTCreateTableStatement_copy_data_source(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateTableStatement_copy_data_source(
		arg0,
		arg1,
	)
}

func parser_ASTCreateTableStatement_copy_data_source(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateTableStatement_copy_data_source(arg0, arg1)
}

func ASTCreateTableStatement_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateTableStatement_partition_by(
		arg0,
		arg1,
	)
}

func parser_ASTCreateTableStatement_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateTableStatement_partition_by(arg0, arg1)
}

func ASTCreateTableStatement_cluster_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateTableStatement_cluster_by(
		arg0,
		arg1,
	)
}

func parser_ASTCreateTableStatement_cluster_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateTableStatement_cluster_by(arg0, arg1)
}

func ASTCreateTableStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateTableStatement_query(
		arg0,
		arg1,
	)
}

func parser_ASTCreateTableStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateTableStatement_query(arg0, arg1)
}

func ASTCreateExternalTableStatement_with_partition_columns_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateExternalTableStatement_with_partition_columns_clause(
		arg0,
		arg1,
	)
}

func parser_ASTCreateExternalTableStatement_with_partition_columns_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateExternalTableStatement_with_partition_columns_clause(arg0, arg1)
}

func ASTCreateExternalTableStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateExternalTableStatement_with_connection_clause(
		arg0,
		arg1,
	)
}

func parser_ASTCreateExternalTableStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateExternalTableStatement_with_connection_clause(arg0, arg1)
}

func ASTCreateViewStatementBase_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateViewStatementBase_name(
		arg0,
		arg1,
	)
}

func parser_ASTCreateViewStatementBase_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateViewStatementBase_name(arg0, arg1)
}

func ASTCreateViewStatementBase_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateViewStatementBase_column_list(
		arg0,
		arg1,
	)
}

func parser_ASTCreateViewStatementBase_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateViewStatementBase_column_list(arg0, arg1)
}

func ASTCreateViewStatementBase_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateViewStatementBase_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTCreateViewStatementBase_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateViewStatementBase_options_list(arg0, arg1)
}

func ASTCreateViewStatementBase_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateViewStatementBase_query(
		arg0,
		arg1,
	)
}

func parser_ASTCreateViewStatementBase_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateViewStatementBase_query(arg0, arg1)
}

func ASTCreateMaterializedViewStatement_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateMaterializedViewStatement_partition_by(
		arg0,
		arg1,
	)
}

func parser_ASTCreateMaterializedViewStatement_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateMaterializedViewStatement_partition_by(arg0, arg1)
}

func ASTCreateMaterializedViewStatement_cluster_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateMaterializedViewStatement_cluster_by(
		arg0,
		arg1,
	)
}

func parser_ASTCreateMaterializedViewStatement_cluster_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateMaterializedViewStatement_cluster_by(arg0, arg1)
}

func ASTLoopStatement_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTLoopStatement_label(
		arg0,
		arg1,
	)
}

func parser_ASTLoopStatement_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTLoopStatement_label(arg0, arg1)
}

func ASTLoopStatement_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTLoopStatement_body(
		arg0,
		arg1,
	)
}

func parser_ASTLoopStatement_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTLoopStatement_body(arg0, arg1)
}

func ASTLoopStatement_IsLoopStatement(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTLoopStatement_IsLoopStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTLoopStatement_IsLoopStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTLoopStatement_IsLoopStatement(arg0, arg1)
}

func ASTWhileStatement_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTWhileStatement_condition(
		arg0,
		arg1,
	)
}

func parser_ASTWhileStatement_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTWhileStatement_condition(arg0, arg1)
}

func ASTRepeatStatement_until_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTRepeatStatement_until_clause(
		arg0,
		arg1,
	)
}

func parser_ASTRepeatStatement_until_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTRepeatStatement_until_clause(arg0, arg1)
}

func ASTForInStatement_variable(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTForInStatement_variable(
		arg0,
		arg1,
	)
}

func parser_ASTForInStatement_variable(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTForInStatement_variable(arg0, arg1)
}

func ASTForInStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTForInStatement_query(
		arg0,
		arg1,
	)
}

func parser_ASTForInStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTForInStatement_query(arg0, arg1)
}

func ASTAlterStatementBase_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTAlterStatementBase_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTAlterStatementBase_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTAlterStatementBase_set_is_if_exists(arg0, arg1)
}

func ASTAlterStatementBase_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTAlterStatementBase_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAlterStatementBase_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTAlterStatementBase_is_if_exists(arg0, arg1)
}

func ASTAlterStatementBase_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterStatementBase_path(
		arg0,
		arg1,
	)
}

func parser_ASTAlterStatementBase_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterStatementBase_path(arg0, arg1)
}

func ASTAlterStatementBase_action_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterStatementBase_action_list(
		arg0,
		arg1,
	)
}

func parser_ASTAlterStatementBase_action_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterStatementBase_action_list(arg0, arg1)
}

func ASTAlterPrivilegeRestrictionStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterPrivilegeRestrictionStatement_privileges(
		arg0,
		arg1,
	)
}

func parser_ASTAlterPrivilegeRestrictionStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterPrivilegeRestrictionStatement_privileges(arg0, arg1)
}

func ASTAlterPrivilegeRestrictionStatement_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterPrivilegeRestrictionStatement_object_type(
		arg0,
		arg1,
	)
}

func parser_ASTAlterPrivilegeRestrictionStatement_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterPrivilegeRestrictionStatement_object_type(arg0, arg1)
}

func ASTAlterRowAccessPolicyStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterRowAccessPolicyStatement_name(
		arg0,
		arg1,
	)
}

func parser_ASTAlterRowAccessPolicyStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterRowAccessPolicyStatement_name(arg0, arg1)
}

func ASTAlterEntityStatement_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAlterEntityStatement_type(
		arg0,
		arg1,
	)
}

func parser_ASTAlterEntityStatement_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAlterEntityStatement_type(arg0, arg1)
}

func ASTCreateFunctionStmtBase_set_determinism_level(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTCreateFunctionStmtBase_set_determinism_level(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTCreateFunctionStmtBase_set_determinism_level(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTCreateFunctionStmtBase_set_determinism_level(arg0, arg1)
}

func ASTCreateFunctionStmtBase_determinism_level(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTCreateFunctionStmtBase_determinism_level(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCreateFunctionStmtBase_determinism_level(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTCreateFunctionStmtBase_determinism_level(arg0, arg1)
}

func ASTCreateFunctionStmtBase_set_sql_security(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTCreateFunctionStmtBase_set_sql_security(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTCreateFunctionStmtBase_set_sql_security(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTCreateFunctionStmtBase_set_sql_security(arg0, arg1)
}

func ASTCreateFunctionStmtBase_sql_security(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTCreateFunctionStmtBase_sql_security(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCreateFunctionStmtBase_sql_security(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTCreateFunctionStmtBase_sql_security(arg0, arg1)
}

func ASTCreateFunctionStmtBase_function_declaration(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateFunctionStmtBase_function_declaration(
		arg0,
		arg1,
	)
}

func parser_ASTCreateFunctionStmtBase_function_declaration(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateFunctionStmtBase_function_declaration(arg0, arg1)
}

func ASTCreateFunctionStmtBase_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateFunctionStmtBase_language(
		arg0,
		arg1,
	)
}

func parser_ASTCreateFunctionStmtBase_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateFunctionStmtBase_language(arg0, arg1)
}

func ASTCreateFunctionStmtBase_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateFunctionStmtBase_code(
		arg0,
		arg1,
	)
}

func parser_ASTCreateFunctionStmtBase_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateFunctionStmtBase_code(arg0, arg1)
}

func ASTCreateFunctionStmtBase_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateFunctionStmtBase_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTCreateFunctionStmtBase_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateFunctionStmtBase_options_list(arg0, arg1)
}

func ASTCreateFunctionStatement_set_is_aggregate(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTCreateFunctionStatement_set_is_aggregate(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTCreateFunctionStatement_set_is_aggregate(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTCreateFunctionStatement_set_is_aggregate(arg0, arg1)
}

func ASTCreateFunctionStatement_is_aggregate(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTCreateFunctionStatement_is_aggregate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCreateFunctionStatement_is_aggregate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTCreateFunctionStatement_is_aggregate(arg0, arg1)
}

func ASTCreateFunctionStatement_set_is_remote(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTCreateFunctionStatement_set_is_remote(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTCreateFunctionStatement_set_is_remote(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTCreateFunctionStatement_set_is_remote(arg0, arg1)
}

func ASTCreateFunctionStatement_is_remote(arg0 unsafe.Pointer, arg1 *bool) {
	parser_ASTCreateFunctionStatement_is_remote(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTCreateFunctionStatement_is_remote(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_parser_parser_ASTCreateFunctionStatement_is_remote(arg0, arg1)
}

func ASTCreateFunctionStatement_return_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateFunctionStatement_return_type(
		arg0,
		arg1,
	)
}

func parser_ASTCreateFunctionStatement_return_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateFunctionStatement_return_type(arg0, arg1)
}

func ASTCreateFunctionStatement_sql_function_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateFunctionStatement_sql_function_body(
		arg0,
		arg1,
	)
}

func parser_ASTCreateFunctionStatement_sql_function_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateFunctionStatement_sql_function_body(arg0, arg1)
}

func ASTCreateFunctionStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateFunctionStatement_with_connection_clause(
		arg0,
		arg1,
	)
}

func parser_ASTCreateFunctionStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateFunctionStatement_with_connection_clause(arg0, arg1)
}

func ASTCreateTableFunctionStatement_return_tvf_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateTableFunctionStatement_return_tvf_schema(
		arg0,
		arg1,
	)
}

func parser_ASTCreateTableFunctionStatement_return_tvf_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateTableFunctionStatement_return_tvf_schema(arg0, arg1)
}

func ASTCreateTableFunctionStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTCreateTableFunctionStatement_query(
		arg0,
		arg1,
	)
}

func parser_ASTCreateTableFunctionStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTCreateTableFunctionStatement_query(arg0, arg1)
}

func ASTStructColumnSchema_struct_fields_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTStructColumnSchema_struct_fields_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTStructColumnSchema_struct_fields_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTStructColumnSchema_struct_fields_num(arg0, arg1)
}

func ASTStructColumnSchema_struct_field(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTStructColumnSchema_struct_field(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTStructColumnSchema_struct_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTStructColumnSchema_struct_field(arg0, arg1, arg2)
}

func ASTExecuteIntoClause_identifiers(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExecuteIntoClause_identifiers(
		arg0,
		arg1,
	)
}

func parser_ASTExecuteIntoClause_identifiers(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExecuteIntoClause_identifiers(arg0, arg1)
}

func ASTExecuteUsingArgument_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExecuteUsingArgument_expression(
		arg0,
		arg1,
	)
}

func parser_ASTExecuteUsingArgument_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExecuteUsingArgument_expression(arg0, arg1)
}

func ASTExecuteUsingArgument_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExecuteUsingArgument_alias(
		arg0,
		arg1,
	)
}

func parser_ASTExecuteUsingArgument_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExecuteUsingArgument_alias(arg0, arg1)
}

func ASTExecuteUsingClause_arguments_num(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTExecuteUsingClause_arguments_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTExecuteUsingClause_arguments_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTExecuteUsingClause_arguments_num(arg0, arg1)
}

func ASTExecuteUsingClause_argument(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	parser_ASTExecuteUsingClause_argument(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func parser_ASTExecuteUsingClause_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExecuteUsingClause_argument(arg0, arg1, arg2)
}

func ASTExecuteImmediateStatement_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExecuteImmediateStatement_sql(
		arg0,
		arg1,
	)
}

func parser_ASTExecuteImmediateStatement_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExecuteImmediateStatement_sql(arg0, arg1)
}

func ASTExecuteImmediateStatement_into_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExecuteImmediateStatement_into_clause(
		arg0,
		arg1,
	)
}

func parser_ASTExecuteImmediateStatement_into_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExecuteImmediateStatement_into_clause(arg0, arg1)
}

func ASTExecuteImmediateStatement_using_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTExecuteImmediateStatement_using_clause(
		arg0,
		arg1,
	)
}

func parser_ASTExecuteImmediateStatement_using_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTExecuteImmediateStatement_using_clause(arg0, arg1)
}

func ASTAuxLoadDataFromFilesOptionsList_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAuxLoadDataFromFilesOptionsList_options_list(
		arg0,
		arg1,
	)
}

func parser_ASTAuxLoadDataFromFilesOptionsList_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAuxLoadDataFromFilesOptionsList_options_list(arg0, arg1)
}

func ASTAuxLoadDataStatement_set_insertion_mode(arg0 unsafe.Pointer, arg1 int) {
	parser_ASTAuxLoadDataStatement_set_insertion_mode(
		arg0,
		C.int(arg1),
	)
}

func parser_ASTAuxLoadDataStatement_set_insertion_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_parser_parser_ASTAuxLoadDataStatement_set_insertion_mode(arg0, arg1)
}

func ASTAuxLoadDataStatement_insertion_mode(arg0 unsafe.Pointer, arg1 *int) {
	parser_ASTAuxLoadDataStatement_insertion_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func parser_ASTAuxLoadDataStatement_insertion_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_parser_parser_ASTAuxLoadDataStatement_insertion_mode(arg0, arg1)
}

func ASTAuxLoadDataStatement_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAuxLoadDataStatement_partition_by(
		arg0,
		arg1,
	)
}

func parser_ASTAuxLoadDataStatement_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAuxLoadDataStatement_partition_by(arg0, arg1)
}

func ASTAuxLoadDataStatement_cluster_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAuxLoadDataStatement_cluster_by(
		arg0,
		arg1,
	)
}

func parser_ASTAuxLoadDataStatement_cluster_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAuxLoadDataStatement_cluster_by(arg0, arg1)
}

func ASTAuxLoadDataStatement_from_files(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAuxLoadDataStatement_from_files(
		arg0,
		arg1,
	)
}

func parser_ASTAuxLoadDataStatement_from_files(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAuxLoadDataStatement_from_files(arg0, arg1)
}

func ASTAuxLoadDataStatement_with_partition_columns_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAuxLoadDataStatement_with_partition_columns_clause(
		arg0,
		arg1,
	)
}

func parser_ASTAuxLoadDataStatement_with_partition_columns_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAuxLoadDataStatement_with_partition_columns_clause(arg0, arg1)
}

func ASTAuxLoadDataStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTAuxLoadDataStatement_with_connection_clause(
		arg0,
		arg1,
	)
}

func parser_ASTAuxLoadDataStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTAuxLoadDataStatement_with_connection_clause(arg0, arg1)
}

func ASTLabel_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	parser_ASTLabel_name(
		arg0,
		arg1,
	)
}

func parser_ASTLabel_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_parser_parser_ASTLabel_name(arg0, arg1)
}

//export export_zetasql_parser_parser_cctz_FixedOffsetFromName
//go:linkname export_zetasql_parser_parser_cctz_FixedOffsetFromName github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetFromName
func export_zetasql_parser_parser_cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_parser_parser_cctz_FixedOffsetToName
//go:linkname export_zetasql_parser_parser_cctz_FixedOffsetToName github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToName
func export_zetasql_parser_parser_cctz_FixedOffsetToName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_parser_parser_cctz_FixedOffsetToAbbr
//go:linkname export_zetasql_parser_parser_cctz_FixedOffsetToAbbr github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToAbbr
func export_zetasql_parser_parser_cctz_FixedOffsetToAbbr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_parser_parser_cctz_detail_format
//go:linkname export_zetasql_parser_parser_cctz_detail_format github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_format
func export_zetasql_parser_parser_cctz_detail_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer)

//export export_zetasql_parser_parser_cctz_detail_parse
//go:linkname export_zetasql_parser_parser_cctz_detail_parse github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_parse
func export_zetasql_parser_parser_cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *C.char)

//export export_zetasql_parser_parser_TimeZoneIf_Load
//go:linkname export_zetasql_parser_parser_TimeZoneIf_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneIf_Load
func export_zetasql_parser_parser_TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_parser_parser_time_zone_Impl_UTC
//go:linkname export_zetasql_parser_parser_time_zone_Impl_UTC github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTC
func export_zetasql_parser_parser_time_zone_Impl_UTC(arg0 *unsafe.Pointer)

//export export_zetasql_parser_parser_time_zone_Impl_LoadTimeZone
//go:linkname export_zetasql_parser_parser_time_zone_Impl_LoadTimeZone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_LoadTimeZone
func export_zetasql_parser_parser_time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_parser_parser_time_zone_Impl_ClearTimeZoneMapTestOnly
//go:linkname export_zetasql_parser_parser_time_zone_Impl_ClearTimeZoneMapTestOnly github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_ClearTimeZoneMapTestOnly
func export_zetasql_parser_parser_time_zone_Impl_ClearTimeZoneMapTestOnly()

//export export_zetasql_parser_parser_time_zone_Impl_UTCImpl
//go:linkname export_zetasql_parser_parser_time_zone_Impl_UTCImpl github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTCImpl
func export_zetasql_parser_parser_time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer)

//export export_zetasql_parser_parser_TimeZoneInfo_Load
//go:linkname export_zetasql_parser_parser_TimeZoneInfo_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Load
func export_zetasql_parser_parser_TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_parser_parser_TimeZoneInfo_BreakTime
//go:linkname export_zetasql_parser_parser_TimeZoneInfo_BreakTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_BreakTime
func export_zetasql_parser_parser_TimeZoneInfo_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_parser_parser_TimeZoneInfo_MakeTime
//go:linkname export_zetasql_parser_parser_TimeZoneInfo_MakeTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_MakeTime
func export_zetasql_parser_parser_TimeZoneInfo_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_parser_parser_TimeZoneInfo_Version
//go:linkname export_zetasql_parser_parser_TimeZoneInfo_Version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Version
func export_zetasql_parser_parser_TimeZoneInfo_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_parser_parser_TimeZoneInfo_Description
//go:linkname export_zetasql_parser_parser_TimeZoneInfo_Description github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Description
func export_zetasql_parser_parser_TimeZoneInfo_Description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_parser_parser_TimeZoneInfo_NextTransition
//go:linkname export_zetasql_parser_parser_TimeZoneInfo_NextTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_NextTransition
func export_zetasql_parser_parser_TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_parser_parser_TimeZoneInfo_PrevTransition
//go:linkname export_zetasql_parser_parser_TimeZoneInfo_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_PrevTransition
func export_zetasql_parser_parser_TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_parser_parser_TimeZoneLibC_BreakTime
//go:linkname export_zetasql_parser_parser_TimeZoneLibC_BreakTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_BreakTime
func export_zetasql_parser_parser_TimeZoneLibC_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_parser_parser_TimeZoneLibC_MakeTime
//go:linkname export_zetasql_parser_parser_TimeZoneLibC_MakeTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_MakeTime
func export_zetasql_parser_parser_TimeZoneLibC_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_parser_parser_TimeZoneLibC_Version
//go:linkname export_zetasql_parser_parser_TimeZoneLibC_Version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_Version
func export_zetasql_parser_parser_TimeZoneLibC_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_parser_parser_TimeZoneLibC_NextTransition
//go:linkname export_zetasql_parser_parser_TimeZoneLibC_NextTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_NextTransition
func export_zetasql_parser_parser_TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_parser_parser_TimeZoneLibC_PrevTransition
//go:linkname export_zetasql_parser_parser_TimeZoneLibC_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_PrevTransition
func export_zetasql_parser_parser_TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_parser_parser_time_zone_name
//go:linkname export_zetasql_parser_parser_time_zone_name github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_name
func export_zetasql_parser_parser_time_zone_name(arg0 *unsafe.Pointer)

//export export_zetasql_parser_parser_time_zone_lookup
//go:linkname export_zetasql_parser_parser_time_zone_lookup github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup
func export_zetasql_parser_parser_time_zone_lookup(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_parser_parser_time_zone_lookup2
//go:linkname export_zetasql_parser_parser_time_zone_lookup2 github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup2
func export_zetasql_parser_parser_time_zone_lookup2(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_parser_parser_time_zone_next_transition
//go:linkname export_zetasql_parser_parser_time_zone_next_transition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_next_transition
func export_zetasql_parser_parser_time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_parser_parser_time_zone_prev_transition
//go:linkname export_zetasql_parser_parser_time_zone_prev_transition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_prev_transition
func export_zetasql_parser_parser_time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_parser_parser_time_zone_version
//go:linkname export_zetasql_parser_parser_time_zone_version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_version
func export_zetasql_parser_parser_time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_parser_parser_time_zone_description
//go:linkname export_zetasql_parser_parser_time_zone_description github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_description
func export_zetasql_parser_parser_time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_parser_parser_cctz_load_time_zone
//go:linkname export_zetasql_parser_parser_cctz_load_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_load_time_zone
func export_zetasql_parser_parser_cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_parser_parser_cctz_utc_time_zone
//go:linkname export_zetasql_parser_parser_cctz_utc_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_utc_time_zone
func export_zetasql_parser_parser_cctz_utc_time_zone(arg0 *unsafe.Pointer)

//export export_zetasql_parser_parser_cctz_fixed_time_zone
//go:linkname export_zetasql_parser_parser_cctz_fixed_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_fixed_time_zone
func export_zetasql_parser_parser_cctz_fixed_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_parser_parser_cctz_local_time_zone
//go:linkname export_zetasql_parser_parser_cctz_local_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_local_time_zone
func export_zetasql_parser_parser_cctz_local_time_zone(arg0 *unsafe.Pointer)

//export export_zetasql_parser_parser_cctz_ParsePosixSpec
//go:linkname export_zetasql_parser_parser_cctz_ParsePosixSpec github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_ParsePosixSpec
func export_zetasql_parser_parser_cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)
