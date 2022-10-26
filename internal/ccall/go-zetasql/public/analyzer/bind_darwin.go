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

func LanguageOptions_new(arg0 *unsafe.Pointer) {
	analyzer_LanguageOptions_new(
		arg0,
	)
}

func analyzer_LanguageOptions_new(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_LanguageOptions_new(arg0)
}

func LanguageOptions_SupportsStatementKind(arg0 unsafe.Pointer, arg1 int, arg2 *bool) {
	analyzer_LanguageOptions_SupportsStatementKind(
		arg0,
		C.int(arg1),
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func analyzer_LanguageOptions_SupportsStatementKind(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.char) {
	C.export_zetasql_public_analyzer_LanguageOptions_SupportsStatementKind(arg0, arg1, arg2)
}

func LanguageOptions_SetSupportedStatementKinds(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_LanguageOptions_SetSupportedStatementKinds(
		arg0,
		arg1,
	)
}

func analyzer_LanguageOptions_SetSupportedStatementKinds(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_LanguageOptions_SetSupportedStatementKinds(arg0, arg1)
}

func LanguageOptions_SetSupportsAllStatementKinds(arg0 unsafe.Pointer) {
	analyzer_LanguageOptions_SetSupportsAllStatementKinds(
		arg0,
	)
}

func analyzer_LanguageOptions_SetSupportsAllStatementKinds(arg0 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_LanguageOptions_SetSupportsAllStatementKinds(arg0)
}

func LanguageOptions_AddSupportedStatementKind(arg0 unsafe.Pointer, arg1 int) {
	analyzer_LanguageOptions_AddSupportedStatementKind(
		arg0,
		C.int(arg1),
	)
}

func analyzer_LanguageOptions_AddSupportedStatementKind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_LanguageOptions_AddSupportedStatementKind(arg0, arg1)
}

func LanguageOptions_LanguageFeatureEnabled(arg0 unsafe.Pointer, arg1 int, arg2 *bool) {
	analyzer_LanguageOptions_LanguageFeatureEnabled(
		arg0,
		C.int(arg1),
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func analyzer_LanguageOptions_LanguageFeatureEnabled(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.char) {
	C.export_zetasql_public_analyzer_LanguageOptions_LanguageFeatureEnabled(arg0, arg1, arg2)
}

func LanguageOptions_SetLanguageVersion(arg0 unsafe.Pointer, arg1 int) {
	analyzer_LanguageOptions_SetLanguageVersion(
		arg0,
		C.int(arg1),
	)
}

func analyzer_LanguageOptions_SetLanguageVersion(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_LanguageOptions_SetLanguageVersion(arg0, arg1)
}

func LanguageOptions_EnableLanguageFeature(arg0 unsafe.Pointer, arg1 int) {
	analyzer_LanguageOptions_EnableLanguageFeature(
		arg0,
		C.int(arg1),
	)
}

func analyzer_LanguageOptions_EnableLanguageFeature(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_LanguageOptions_EnableLanguageFeature(arg0, arg1)
}

func LanguageOptions_SetEnabledLanguageFeatures(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_LanguageOptions_SetEnabledLanguageFeatures(
		arg0,
		arg1,
	)
}

func analyzer_LanguageOptions_SetEnabledLanguageFeatures(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_LanguageOptions_SetEnabledLanguageFeatures(arg0, arg1)
}

func LanguageOptions_EnabledLanguageFeatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_LanguageOptions_EnabledLanguageFeatures(
		arg0,
		arg1,
	)
}

func analyzer_LanguageOptions_EnabledLanguageFeatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_LanguageOptions_EnabledLanguageFeatures(arg0, arg1)
}

func LanguageOptions_EnabledLanguageFeaturesAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_LanguageOptions_EnabledLanguageFeaturesAsString(
		arg0,
		arg1,
	)
}

func analyzer_LanguageOptions_EnabledLanguageFeaturesAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_LanguageOptions_EnabledLanguageFeaturesAsString(arg0, arg1)
}

func LanguageOptions_DisableAllLanguageFeatures(arg0 unsafe.Pointer) {
	analyzer_LanguageOptions_DisableAllLanguageFeatures(
		arg0,
	)
}

func analyzer_LanguageOptions_DisableAllLanguageFeatures(arg0 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_LanguageOptions_DisableAllLanguageFeatures(arg0)
}

func LanguageOptions_EnableMaximumLanguageFeatures(arg0 unsafe.Pointer) {
	analyzer_LanguageOptions_EnableMaximumLanguageFeatures(
		arg0,
	)
}

func analyzer_LanguageOptions_EnableMaximumLanguageFeatures(arg0 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_LanguageOptions_EnableMaximumLanguageFeatures(arg0)
}

func LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment(arg0 unsafe.Pointer) {
	analyzer_LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment(
		arg0,
	)
}

func analyzer_LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment(arg0 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment(arg0)
}

func LanguageOptions_set_name_resolution_mode(arg0 unsafe.Pointer, arg1 int) {
	analyzer_LanguageOptions_set_name_resolution_mode(
		arg0,
		C.int(arg1),
	)
}

func analyzer_LanguageOptions_set_name_resolution_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_LanguageOptions_set_name_resolution_mode(arg0, arg1)
}

func LanguageOptions_name_resolution_mode(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_LanguageOptions_name_resolution_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_LanguageOptions_name_resolution_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_LanguageOptions_name_resolution_mode(arg0, arg1)
}

func LanguageOptions_set_product_mode(arg0 unsafe.Pointer, arg1 int) {
	analyzer_LanguageOptions_set_product_mode(
		arg0,
		C.int(arg1),
	)
}

func analyzer_LanguageOptions_set_product_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_LanguageOptions_set_product_mode(arg0, arg1)
}

func LanguageOptions_product_mode(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_LanguageOptions_product_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_LanguageOptions_product_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_LanguageOptions_product_mode(arg0, arg1)
}

func LanguageOptions_SupportsProtoTypes(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_LanguageOptions_SupportsProtoTypes(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_LanguageOptions_SupportsProtoTypes(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_LanguageOptions_SupportsProtoTypes(arg0, arg1)
}

func LanguageOptions_set_error_on_deprecated_syntax(arg0 unsafe.Pointer, arg1 int) {
	analyzer_LanguageOptions_set_error_on_deprecated_syntax(
		arg0,
		C.int(arg1),
	)
}

func analyzer_LanguageOptions_set_error_on_deprecated_syntax(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_LanguageOptions_set_error_on_deprecated_syntax(arg0, arg1)
}

func LanguageOptions_error_on_deprecated_syntax(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_LanguageOptions_error_on_deprecated_syntax(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_LanguageOptions_error_on_deprecated_syntax(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_LanguageOptions_error_on_deprecated_syntax(arg0, arg1)
}

func LanguageOptions_SetSupportedGenericEntityTypes(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_LanguageOptions_SetSupportedGenericEntityTypes(
		arg0,
		arg1,
	)
}

func analyzer_LanguageOptions_SetSupportedGenericEntityTypes(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_LanguageOptions_SetSupportedGenericEntityTypes(arg0, arg1)
}

func LanguageOptions_GenericEntityTypeSupported(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	analyzer_LanguageOptions_GenericEntityTypeSupported(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func analyzer_LanguageOptions_GenericEntityTypeSupported(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_public_analyzer_LanguageOptions_GenericEntityTypeSupported(arg0, arg1, arg2)
}

func LanguageOptions_IsReservedKeyword(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	analyzer_LanguageOptions_IsReservedKeyword(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func analyzer_LanguageOptions_IsReservedKeyword(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_public_analyzer_LanguageOptions_IsReservedKeyword(arg0, arg1, arg2)
}

func LanguageOptions_EnableReservableKeyword(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	analyzer_LanguageOptions_EnableReservableKeyword(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func analyzer_LanguageOptions_EnableReservableKeyword(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_LanguageOptions_EnableReservableKeyword(arg0, arg1, arg2, arg3)
}

func LanguageOptions_EnableAllReservableKeywords(arg0 unsafe.Pointer, arg1 int) {
	analyzer_LanguageOptions_EnableAllReservableKeywords(
		arg0,
		C.int(arg1),
	)
}

func analyzer_LanguageOptions_EnableAllReservableKeywords(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_LanguageOptions_EnableAllReservableKeywords(arg0, arg1)
}

func AnalyzerOptions_new(arg0 *unsafe.Pointer) {
	analyzer_AnalyzerOptions_new(
		arg0,
	)
}

func analyzer_AnalyzerOptions_new(arg0 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_new(arg0)
}

func AnalyzerOptions_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_AnalyzerOptions_language(
		arg0,
		arg1,
	)
}

func analyzer_AnalyzerOptions_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_language(arg0, arg1)
}

func AnalyzerOptions_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_AnalyzerOptions_set_language(
		arg0,
		arg1,
	)
}

func analyzer_AnalyzerOptions_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_set_language(arg0, arg1)
}

func AnalyzerOptions_AddQueryParameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	analyzer_AnalyzerOptions_AddQueryParameter(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func analyzer_AnalyzerOptions_AddQueryParameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_AddQueryParameter(arg0, arg1, arg2, arg3)
}

func AnalyzerOptions_query_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_AnalyzerOptions_query_parameters(
		arg0,
		arg1,
	)
}

func analyzer_AnalyzerOptions_query_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_query_parameters(arg0, arg1)
}

func AnalyzerOptions_clear_query_parameters(arg0 unsafe.Pointer) {
	analyzer_AnalyzerOptions_clear_query_parameters(
		arg0,
	)
}

func analyzer_AnalyzerOptions_clear_query_parameters(arg0 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_clear_query_parameters(arg0)
}

func AnalyzerOptions_AddPositionalQueryParameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	analyzer_AnalyzerOptions_AddPositionalQueryParameter(
		arg0,
		arg1,
		arg2,
	)
}

func analyzer_AnalyzerOptions_AddPositionalQueryParameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_AddPositionalQueryParameter(arg0, arg1, arg2)
}

func AnalyzerOptions_positional_query_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_AnalyzerOptions_positional_query_parameters(
		arg0,
		arg1,
	)
}

func analyzer_AnalyzerOptions_positional_query_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_positional_query_parameters(arg0, arg1)
}

func AnalyzerOptions_clear_positional_query_parameters(arg0 unsafe.Pointer) {
	analyzer_AnalyzerOptions_clear_positional_query_parameters(
		arg0,
	)
}

func analyzer_AnalyzerOptions_clear_positional_query_parameters(arg0 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_clear_positional_query_parameters(arg0)
}

func AnalyzerOptions_AddExpressionColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	analyzer_AnalyzerOptions_AddExpressionColumn(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func analyzer_AnalyzerOptions_AddExpressionColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_AddExpressionColumn(arg0, arg1, arg2, arg3)
}

func AnalyzerOptions_SetInScopeExpressionColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	analyzer_AnalyzerOptions_SetInScopeExpressionColumn(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func analyzer_AnalyzerOptions_SetInScopeExpressionColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_SetInScopeExpressionColumn(arg0, arg1, arg2, arg3)
}

func AnalyzerOptions_expression_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_AnalyzerOptions_expression_columns(
		arg0,
		arg1,
	)
}

func analyzer_AnalyzerOptions_expression_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_expression_columns(arg0, arg1)
}

func AnalyzerOptions_has_in_scope_expression_column(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_AnalyzerOptions_has_in_scope_expression_column(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_AnalyzerOptions_has_in_scope_expression_column(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_has_in_scope_expression_column(arg0, arg1)
}

func AnalyzerOptions_in_scope_expression_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_AnalyzerOptions_in_scope_expression_column_name(
		arg0,
		arg1,
	)
}

func analyzer_AnalyzerOptions_in_scope_expression_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_in_scope_expression_column_name(arg0, arg1)
}

func AnalyzerOptions_in_scope_expression_column_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_AnalyzerOptions_in_scope_expression_column_type(
		arg0,
		arg1,
	)
}

func analyzer_AnalyzerOptions_in_scope_expression_column_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_in_scope_expression_column_type(arg0, arg1)
}

func AnalyzerOptions_set_error_message_mode(arg0 unsafe.Pointer, arg1 int) {
	analyzer_AnalyzerOptions_set_error_message_mode(
		arg0,
		C.int(arg1),
	)
}

func analyzer_AnalyzerOptions_set_error_message_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_set_error_message_mode(arg0, arg1)
}

func AnalyzerOptions_error_message_mode(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_AnalyzerOptions_error_message_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_AnalyzerOptions_error_message_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_error_message_mode(arg0, arg1)
}

func AnalyzerOptions_set_statement_context(arg0 unsafe.Pointer, arg1 int) {
	analyzer_AnalyzerOptions_set_statement_context(
		arg0,
		C.int(arg1),
	)
}

func analyzer_AnalyzerOptions_set_statement_context(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_set_statement_context(arg0, arg1)
}

func AnalyzerOptions_statement_context(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_AnalyzerOptions_statement_context(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_AnalyzerOptions_statement_context(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_statement_context(arg0, arg1)
}

func AnalyzerOptions_set_parse_location_record_type(arg0 unsafe.Pointer, arg1 int) {
	analyzer_AnalyzerOptions_set_parse_location_record_type(
		arg0,
		C.int(arg1),
	)
}

func analyzer_AnalyzerOptions_set_parse_location_record_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_set_parse_location_record_type(arg0, arg1)
}

func AnalyzerOptions_parse_location_record_type(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_AnalyzerOptions_parse_location_record_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_AnalyzerOptions_parse_location_record_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_parse_location_record_type(arg0, arg1)
}

func AnalyzerOptions_set_create_new_column_for_each_projected_output(arg0 unsafe.Pointer, arg1 int) {
	analyzer_AnalyzerOptions_set_create_new_column_for_each_projected_output(
		arg0,
		C.int(arg1),
	)
}

func analyzer_AnalyzerOptions_set_create_new_column_for_each_projected_output(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_set_create_new_column_for_each_projected_output(arg0, arg1)
}

func AnalyzerOptions_create_new_column_for_each_projected_output(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_AnalyzerOptions_create_new_column_for_each_projected_output(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_AnalyzerOptions_create_new_column_for_each_projected_output(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_create_new_column_for_each_projected_output(arg0, arg1)
}

func AnalyzerOptions_set_allow_undeclared_parameters(arg0 unsafe.Pointer, arg1 int) {
	analyzer_AnalyzerOptions_set_allow_undeclared_parameters(
		arg0,
		C.int(arg1),
	)
}

func analyzer_AnalyzerOptions_set_allow_undeclared_parameters(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_set_allow_undeclared_parameters(arg0, arg1)
}

func AnalyzerOptions_allow_undeclared_parameters(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_AnalyzerOptions_allow_undeclared_parameters(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_AnalyzerOptions_allow_undeclared_parameters(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_allow_undeclared_parameters(arg0, arg1)
}

func AnalyzerOptions_set_parameter_mode(arg0 unsafe.Pointer, arg1 int) {
	analyzer_AnalyzerOptions_set_parameter_mode(
		arg0,
		C.int(arg1),
	)
}

func analyzer_AnalyzerOptions_set_parameter_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_set_parameter_mode(arg0, arg1)
}

func AnalyzerOptions_parameter_mode(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_AnalyzerOptions_parameter_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_AnalyzerOptions_parameter_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_parameter_mode(arg0, arg1)
}

func AnalyzerOptions_set_prune_unused_columns(arg0 unsafe.Pointer, arg1 int) {
	analyzer_AnalyzerOptions_set_prune_unused_columns(
		arg0,
		C.int(arg1),
	)
}

func analyzer_AnalyzerOptions_set_prune_unused_columns(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_set_prune_unused_columns(arg0, arg1)
}

func AnalyzerOptions_prune_unused_columns(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_AnalyzerOptions_prune_unused_columns(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_AnalyzerOptions_prune_unused_columns(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_prune_unused_columns(arg0, arg1)
}

func AnalyzerOptions_set_preserve_column_aliases(arg0 unsafe.Pointer, arg1 int) {
	analyzer_AnalyzerOptions_set_preserve_column_aliases(
		arg0,
		C.int(arg1),
	)
}

func analyzer_AnalyzerOptions_set_preserve_column_aliases(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_set_preserve_column_aliases(arg0, arg1)
}

func AnalyzerOptions_preserve_column_aliases(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_AnalyzerOptions_preserve_column_aliases(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_AnalyzerOptions_preserve_column_aliases(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_preserve_column_aliases(arg0, arg1)
}

func AnalyzerOptions_GetParserOptions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_AnalyzerOptions_GetParserOptions(
		arg0,
		arg1,
	)
}

func analyzer_AnalyzerOptions_GetParserOptions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzerOptions_GetParserOptions(arg0, arg1)
}

func ValidateAnalyzerOptions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ValidateAnalyzerOptions(
		arg0,
		arg1,
	)
}

func analyzer_ValidateAnalyzerOptions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ValidateAnalyzerOptions(arg0, arg1)
}

func AnalyzeStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	analyzer_AnalyzeStatement(
		arg0,
		arg1,
		arg2,
		arg3,
		arg4,
	)
}

func analyzer_AnalyzeStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzeStatement(arg0, arg1, arg2, arg3, arg4)
}

func AnalyzeNextStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *bool, arg5 *unsafe.Pointer) {
	analyzer_AnalyzeNextStatement(
		arg0,
		arg1,
		arg2,
		arg3,
		(*C.char)(unsafe.Pointer(arg4)),
		arg5,
	)
}

func analyzer_AnalyzeNextStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *C.char, arg5 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzeNextStatement(arg0, arg1, arg2, arg3, arg4, arg5)
}

func AnalyzeExpression(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	analyzer_AnalyzeExpression(
		arg0,
		arg1,
		arg2,
		arg3,
		arg4,
	)
}

func analyzer_AnalyzeExpression(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzeExpression(arg0, arg1, arg2, arg3, arg4)
}

func AnalyzeStatementFromParserAST(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer, arg5 *unsafe.Pointer) {
	analyzer_AnalyzeStatementFromParserAST(
		arg0,
		arg1,
		arg2,
		arg3,
		arg4,
		arg5,
	)
}

func analyzer_AnalyzeStatementFromParserAST(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer, arg5 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_AnalyzeStatementFromParserAST(arg0, arg1, arg2, arg3, arg4, arg5)
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
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedNode_IsScan(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedNode_IsScan(arg0, arg1)
}

func ResolvedNode_IsExpression(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedNode_IsExpression(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedNode_IsExpression(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedNode_IsExpression(arg0, arg1)
}

func ResolvedNode_IsStatement(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedNode_IsStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedNode_IsStatement(arg0 unsafe.Pointer, arg1 *C.char) {
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

func ResolvedNode_GetParseLocationRangeOrNULL(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedNode_GetParseLocationRangeOrNULL(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedNode_GetParseLocationRangeOrNULL(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedNode_GetParseLocationRangeOrNULL(arg0, arg1)
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
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedLiteral_has_explicit_type(arg0 unsafe.Pointer, arg1 *C.char) {
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
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedLiteral_preserve_in_literal_remover(arg0 unsafe.Pointer, arg1 *C.char) {
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
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedParameter_is_untyped(arg0 unsafe.Pointer, arg1 *C.char) {
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
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedColumnRef_is_correlated(arg0 unsafe.Pointer, arg1 *C.char) {
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

func ResolvedFilterFieldArg_include(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedFilterFieldArg_include(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedFilterFieldArg_include(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedFilterFieldArg_include(arg0, arg1)
}

func ResolvedFilterFieldArg_set_include(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedFilterFieldArg_set_include(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedFilterFieldArg_set_include(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedFilterFieldArg_set_include(arg0, arg1)
}

func ResolvedFilterField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFilterField_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFilterField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFilterField_expr(arg0, arg1)
}

func ResolvedFilterField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFilterField_set_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFilterField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFilterField_set_expr(arg0, arg1)
}

func ResolvedFilterField_filter_field_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFilterField_filter_field_arg_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFilterField_filter_field_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFilterField_filter_field_arg_list(arg0, arg1)
}

func ResolvedFilterField_set_filter_field_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFilterField_set_filter_field_arg_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFilterField_set_filter_field_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFilterField_set_filter_field_arg_list(arg0, arg1)
}

func ResolvedFilterField_add_filter_field_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFilterField_add_filter_field_arg_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFilterField_add_filter_field_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFilterField_add_filter_field_arg_list(arg0, arg1)
}

func ResolvedFilterField_reset_cleared_required_fields(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedFilterField_reset_cleared_required_fields(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedFilterField_reset_cleared_required_fields(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedFilterField_reset_cleared_required_fields(arg0, arg1)
}

func ResolvedFilterField_set_reset_cleared_required_fields(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedFilterField_set_reset_cleared_required_fields(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedFilterField_set_reset_cleared_required_fields(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedFilterField_set_reset_cleared_required_fields(arg0, arg1)
}

func ResolvedFunctionCallBase_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_function(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_function(arg0, arg1)
}

func ResolvedFunctionCallBase_set_function(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_set_function(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_set_function(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_set_function(arg0, arg1)
}

func ResolvedFunctionCallBase_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_signature(arg0, arg1)
}

func ResolvedFunctionCallBase_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_set_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_set_signature(arg0, arg1)
}

func ResolvedFunctionCallBase_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_set_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_set_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_add_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_add_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_generic_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_generic_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_generic_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_generic_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_set_generic_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_set_generic_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_set_generic_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_set_generic_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_add_generic_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_add_generic_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_add_generic_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_add_generic_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_error_mode(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedFunctionCallBase_error_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedFunctionCallBase_error_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_error_mode(arg0, arg1)
}

func ResolvedFunctionCallBase_set_error_mode(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedFunctionCallBase_set_error_mode(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedFunctionCallBase_set_error_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_set_error_mode(arg0, arg1)
}

func ResolvedFunctionCallBase_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_hint_list(arg0, arg1)
}

func ResolvedFunctionCallBase_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_set_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_set_hint_list(arg0, arg1)
}

func ResolvedFunctionCallBase_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_add_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_add_hint_list(arg0, arg1)
}

func ResolvedFunctionCallBase_collation_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_collation_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_collation_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_collation_list(arg0, arg1)
}

func ResolvedFunctionCallBase_set_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_set_collation_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_set_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_set_collation_list(arg0, arg1)
}

func ResolvedFunctionCallBase_add_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionCallBase_add_collation_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallBase_add_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallBase_add_collation_list(arg0, arg1)
}

func ResolvedFunctionCall_function_call_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionCall_function_call_info(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCall_function_call_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCall_function_call_info(arg0, arg1)
}

func ResolvedFunctionCall_set_function_call_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionCall_set_function_call_info(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCall_set_function_call_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCall_set_function_call_info(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_distinct(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedNonScalarFunctionCallBase_distinct(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedNonScalarFunctionCallBase_distinct(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedNonScalarFunctionCallBase_distinct(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_set_distinct(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedNonScalarFunctionCallBase_set_distinct(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedNonScalarFunctionCallBase_set_distinct(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedNonScalarFunctionCallBase_set_distinct(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_null_handling_modifier(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedNonScalarFunctionCallBase_null_handling_modifier(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedNonScalarFunctionCallBase_null_handling_modifier(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedNonScalarFunctionCallBase_null_handling_modifier(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_set_null_handling_modifier(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedNonScalarFunctionCallBase_set_null_handling_modifier(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedNonScalarFunctionCallBase_set_null_handling_modifier(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedNonScalarFunctionCallBase_set_null_handling_modifier(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_with_group_rows_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedNonScalarFunctionCallBase_with_group_rows_subquery(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedNonScalarFunctionCallBase_with_group_rows_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedNonScalarFunctionCallBase_with_group_rows_subquery(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_set_with_group_rows_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedNonScalarFunctionCallBase_set_with_group_rows_subquery(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedNonScalarFunctionCallBase_set_with_group_rows_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedNonScalarFunctionCallBase_set_with_group_rows_subquery(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_with_group_rows_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedNonScalarFunctionCallBase_with_group_rows_parameter_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedNonScalarFunctionCallBase_with_group_rows_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedNonScalarFunctionCallBase_with_group_rows_parameter_list(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_set_with_group_rows_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedNonScalarFunctionCallBase_set_with_group_rows_parameter_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedNonScalarFunctionCallBase_set_with_group_rows_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedNonScalarFunctionCallBase_set_with_group_rows_parameter_list(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_add_with_group_rows_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedNonScalarFunctionCallBase_add_with_group_rows_parameter_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedNonScalarFunctionCallBase_add_with_group_rows_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedNonScalarFunctionCallBase_add_with_group_rows_parameter_list(arg0, arg1)
}

func ResolvedAggregateFunctionCall_having_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAggregateFunctionCall_having_modifier(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateFunctionCall_having_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateFunctionCall_having_modifier(arg0, arg1)
}

func ResolvedAggregateFunctionCall_set_having_modifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateFunctionCall_set_having_modifier(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateFunctionCall_set_having_modifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateFunctionCall_set_having_modifier(arg0, arg1)
}

func ResolvedAggregateFunctionCall_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAggregateFunctionCall_order_by_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateFunctionCall_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateFunctionCall_order_by_item_list(arg0, arg1)
}

func ResolvedAggregateFunctionCall_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateFunctionCall_set_order_by_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateFunctionCall_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateFunctionCall_set_order_by_item_list(arg0, arg1)
}

func ResolvedAggregateFunctionCall_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateFunctionCall_add_order_by_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateFunctionCall_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateFunctionCall_add_order_by_item_list(arg0, arg1)
}

func ResolvedAggregateFunctionCall_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAggregateFunctionCall_limit(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateFunctionCall_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateFunctionCall_limit(arg0, arg1)
}

func ResolvedAggregateFunctionCall_set_limit(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateFunctionCall_set_limit(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateFunctionCall_set_limit(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateFunctionCall_set_limit(arg0, arg1)
}

func ResolvedAggregateFunctionCall_function_call_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAggregateFunctionCall_function_call_info(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateFunctionCall_function_call_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateFunctionCall_function_call_info(arg0, arg1)
}

func ResolvedAggregateFunctionCall_set_function_call_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateFunctionCall_set_function_call_info(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateFunctionCall_set_function_call_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateFunctionCall_set_function_call_info(arg0, arg1)
}

func ResolvedAnalyticFunctionCall_window_frame(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAnalyticFunctionCall_window_frame(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyticFunctionCall_window_frame(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyticFunctionCall_window_frame(arg0, arg1)
}

func ResolvedAnalyticFunctionCall_set_window_frame(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAnalyticFunctionCall_set_window_frame(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyticFunctionCall_set_window_frame(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyticFunctionCall_set_window_frame(arg0, arg1)
}

func ResolvedExtendedCastElement_from_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExtendedCastElement_from_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExtendedCastElement_from_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExtendedCastElement_from_type(arg0, arg1)
}

func ResolvedExtendedCastElement_set_from_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExtendedCastElement_set_from_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExtendedCastElement_set_from_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExtendedCastElement_set_from_type(arg0, arg1)
}

func ResolvedExtendedCastElement_to_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExtendedCastElement_to_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExtendedCastElement_to_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExtendedCastElement_to_type(arg0, arg1)
}

func ResolvedExtendedCastElement_set_to_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExtendedCastElement_set_to_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExtendedCastElement_set_to_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExtendedCastElement_set_to_type(arg0, arg1)
}

func ResolvedExtendedCastElement_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExtendedCastElement_function(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExtendedCastElement_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExtendedCastElement_function(arg0, arg1)
}

func ResolvedExtendedCastElement_set_function(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExtendedCastElement_set_function(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExtendedCastElement_set_function(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExtendedCastElement_set_function(arg0, arg1)
}

func ResolvedExtendedCast_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExtendedCast_element_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExtendedCast_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExtendedCast_element_list(arg0, arg1)
}

func ResolvedExtendedCast_set_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExtendedCast_set_element_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExtendedCast_set_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExtendedCast_set_element_list(arg0, arg1)
}

func ResolvedExtendedCast_add_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExtendedCast_add_element_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExtendedCast_add_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExtendedCast_add_element_list(arg0, arg1)
}

func ResolvedCast_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCast_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCast_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCast_expr(arg0, arg1)
}

func ResolvedCast_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCast_set_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCast_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCast_set_expr(arg0, arg1)
}

func ResolvedCast_return_null_on_error(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCast_return_null_on_error(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCast_return_null_on_error(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCast_return_null_on_error(arg0, arg1)
}

func ResolvedCast_set_return_null_on_error(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCast_set_return_null_on_error(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCast_set_return_null_on_error(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCast_set_return_null_on_error(arg0, arg1)
}

func ResolvedCast_extended_cast(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCast_extended_cast(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCast_extended_cast(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCast_extended_cast(arg0, arg1)
}

func ResolvedCast_set_extended_cast(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCast_set_extended_cast(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCast_set_extended_cast(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCast_set_extended_cast(arg0, arg1)
}

func ResolvedCast_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCast_format(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCast_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCast_format(arg0, arg1)
}

func ResolvedCast_set_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCast_set_format(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCast_set_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCast_set_format(arg0, arg1)
}

func ResolvedCast_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCast_time_zone(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCast_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCast_time_zone(arg0, arg1)
}

func ResolvedCast_set_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCast_set_time_zone(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCast_set_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCast_set_time_zone(arg0, arg1)
}

func ResolvedCast_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCast_type_parameters(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCast_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCast_type_parameters(arg0, arg1)
}

func ResolvedCast_set_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCast_set_type_parameters(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCast_set_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCast_set_type_parameters(arg0, arg1)
}

func ResolvedMakeStruct_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedMakeStruct_field_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMakeStruct_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMakeStruct_field_list(arg0, arg1)
}

func ResolvedMakeStruct_set_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMakeStruct_set_field_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMakeStruct_set_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMakeStruct_set_field_list(arg0, arg1)
}

func ResolvedMakeStruct_add_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMakeStruct_add_field_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMakeStruct_add_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMakeStruct_add_field_list(arg0, arg1)
}

func ResolvedMakeProto_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedMakeProto_field_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMakeProto_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMakeProto_field_list(arg0, arg1)
}

func ResolvedMakeProto_set_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMakeProto_set_field_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMakeProto_set_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMakeProto_set_field_list(arg0, arg1)
}

func ResolvedMakeProto_add_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMakeProto_add_field_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMakeProto_add_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMakeProto_add_field_list(arg0, arg1)
}

func ResolvedMakeProtoField_format(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedMakeProtoField_format(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedMakeProtoField_format(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedMakeProtoField_format(arg0, arg1)
}

func ResolvedMakeProtoField_set_format(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedMakeProtoField_set_format(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedMakeProtoField_set_format(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedMakeProtoField_set_format(arg0, arg1)
}

func ResolvedMakeProtoField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedMakeProtoField_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMakeProtoField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMakeProtoField_expr(arg0, arg1)
}

func ResolvedMakeProtoField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMakeProtoField_set_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMakeProtoField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMakeProtoField_set_expr(arg0, arg1)
}

func ResolvedGetStructField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedGetStructField_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGetStructField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGetStructField_expr(arg0, arg1)
}

func ResolvedGetStructField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGetStructField_set_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGetStructField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGetStructField_set_expr(arg0, arg1)
}

func ResolvedGetStructField_field_idx(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedGetStructField_field_idx(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedGetStructField_field_idx(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedGetStructField_field_idx(arg0, arg1)
}

func ResolvedGetStructField_set_field_idx(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedGetStructField_set_field_idx(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedGetStructField_set_field_idx(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedGetStructField_set_field_idx(arg0, arg1)
}

func ResolvedGetProtoField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedGetProtoField_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGetProtoField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGetProtoField_expr(arg0, arg1)
}

func ResolvedGetProtoField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGetProtoField_set_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGetProtoField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGetProtoField_set_expr(arg0, arg1)
}

func ResolvedGetProtoField_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedGetProtoField_default_value(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGetProtoField_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGetProtoField_default_value(arg0, arg1)
}

func ResolvedGetProtoField_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGetProtoField_set_default_value(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGetProtoField_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGetProtoField_set_default_value(arg0, arg1)
}

func ResolvedGetProtoField_get_has_bit(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedGetProtoField_get_has_bit(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedGetProtoField_get_has_bit(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedGetProtoField_get_has_bit(arg0, arg1)
}

func ResolvedGetProtoField_set_get_has_bit(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedGetProtoField_set_get_has_bit(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedGetProtoField_set_get_has_bit(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedGetProtoField_set_get_has_bit(arg0, arg1)
}

func ResolvedGetProtoField_format(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedGetProtoField_format(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedGetProtoField_format(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedGetProtoField_format(arg0, arg1)
}

func ResolvedGetProtoField_set_format(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedGetProtoField_set_format(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedGetProtoField_set_format(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedGetProtoField_set_format(arg0, arg1)
}

func ResolvedGetProtoField_return_default_value_when_unset(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedGetProtoField_return_default_value_when_unset(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedGetProtoField_return_default_value_when_unset(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedGetProtoField_return_default_value_when_unset(arg0, arg1)
}

func ResolvedGetProtoField_set_return_default_value_when_unset(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedGetProtoField_set_return_default_value_when_unset(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedGetProtoField_set_return_default_value_when_unset(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedGetProtoField_set_return_default_value_when_unset(arg0, arg1)
}

func ResolvedGetJsonField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedGetJsonField_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGetJsonField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGetJsonField_expr(arg0, arg1)
}

func ResolvedGetJsonField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGetJsonField_set_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGetJsonField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGetJsonField_set_expr(arg0, arg1)
}

func ResolvedGetJsonField_field_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedGetJsonField_field_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGetJsonField_field_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGetJsonField_field_name(arg0, arg1)
}

func ResolvedGetJsonField_set_field_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGetJsonField_set_field_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGetJsonField_set_field_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGetJsonField_set_field_name(arg0, arg1)
}

func ResolvedFlatten_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFlatten_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFlatten_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFlatten_expr(arg0, arg1)
}

func ResolvedFlatten_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFlatten_set_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFlatten_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFlatten_set_expr(arg0, arg1)
}

func ResolvedFlatten_get_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFlatten_get_field_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFlatten_get_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFlatten_get_field_list(arg0, arg1)
}

func ResolvedFlatten_set_get_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFlatten_set_get_field_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFlatten_set_get_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFlatten_set_get_field_list(arg0, arg1)
}

func ResolvedFlatten_add_get_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFlatten_add_get_field_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFlatten_add_get_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFlatten_add_get_field_list(arg0, arg1)
}

func ResolvedReplaceFieldItem_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedReplaceFieldItem_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReplaceFieldItem_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReplaceFieldItem_expr(arg0, arg1)
}

func ResolvedReplaceFieldItem_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedReplaceFieldItem_set_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReplaceFieldItem_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReplaceFieldItem_set_expr(arg0, arg1)
}

func ResolvedReplaceFieldItem_struct_index_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedReplaceFieldItem_struct_index_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReplaceFieldItem_struct_index_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReplaceFieldItem_struct_index_path(arg0, arg1)
}

func ResolvedReplaceFieldItem_set_struct_index_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedReplaceFieldItem_set_struct_index_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReplaceFieldItem_set_struct_index_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReplaceFieldItem_set_struct_index_path(arg0, arg1)
}

func ResolvedReplaceFieldItem_add_struct_index_path(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedReplaceFieldItem_add_struct_index_path(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedReplaceFieldItem_add_struct_index_path(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedReplaceFieldItem_add_struct_index_path(arg0, arg1)
}

func ResolvedReplaceField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedReplaceField_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReplaceField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReplaceField_expr(arg0, arg1)
}

func ResolvedReplaceField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedReplaceField_set_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReplaceField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReplaceField_set_expr(arg0, arg1)
}

func ResolvedReplaceField_replace_field_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedReplaceField_replace_field_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReplaceField_replace_field_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReplaceField_replace_field_item_list(arg0, arg1)
}

func ResolvedReplaceField_set_replace_field_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedReplaceField_set_replace_field_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReplaceField_set_replace_field_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReplaceField_set_replace_field_item_list(arg0, arg1)
}

func ResolvedReplaceField_add_replace_field_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedReplaceField_add_replace_field_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReplaceField_add_replace_field_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReplaceField_add_replace_field_item_list(arg0, arg1)
}

func ResolvedSubqueryExpr_subquery_type(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedSubqueryExpr_subquery_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedSubqueryExpr_subquery_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedSubqueryExpr_subquery_type(arg0, arg1)
}

func ResolvedSubqueryExpr_set_subquery_type(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedSubqueryExpr_set_subquery_type(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedSubqueryExpr_set_subquery_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedSubqueryExpr_set_subquery_type(arg0, arg1)
}

func ResolvedSubqueryExpr_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSubqueryExpr_parameter_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSubqueryExpr_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSubqueryExpr_parameter_list(arg0, arg1)
}

func ResolvedSubqueryExpr_set_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSubqueryExpr_set_parameter_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSubqueryExpr_set_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSubqueryExpr_set_parameter_list(arg0, arg1)
}

func ResolvedSubqueryExpr_add_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSubqueryExpr_add_parameter_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSubqueryExpr_add_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSubqueryExpr_add_parameter_list(arg0, arg1)
}

func ResolvedSubqueryExpr_in_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSubqueryExpr_in_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSubqueryExpr_in_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSubqueryExpr_in_expr(arg0, arg1)
}

func ResolvedSubqueryExpr_set_in_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSubqueryExpr_set_in_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSubqueryExpr_set_in_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSubqueryExpr_set_in_expr(arg0, arg1)
}

func ResolvedSubqueryExpr_in_collation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSubqueryExpr_in_collation(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSubqueryExpr_in_collation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSubqueryExpr_in_collation(arg0, arg1)
}

func ResolvedSubqueryExpr_set_in_collation(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSubqueryExpr_set_in_collation(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSubqueryExpr_set_in_collation(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSubqueryExpr_set_in_collation(arg0, arg1)
}

func ResolvedSubqueryExpr_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSubqueryExpr_subquery(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSubqueryExpr_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSubqueryExpr_subquery(arg0, arg1)
}

func ResolvedSubqueryExpr_set_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSubqueryExpr_set_subquery(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSubqueryExpr_set_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSubqueryExpr_set_subquery(arg0, arg1)
}

func ResolvedSubqueryExpr_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSubqueryExpr_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSubqueryExpr_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSubqueryExpr_hint_list(arg0, arg1)
}

func ResolvedSubqueryExpr_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSubqueryExpr_set_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSubqueryExpr_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSubqueryExpr_set_hint_list(arg0, arg1)
}

func ResolvedSubqueryExpr_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSubqueryExpr_add_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSubqueryExpr_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSubqueryExpr_add_hint_list(arg0, arg1)
}

func ResolvedLetExpr_assignment_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedLetExpr_assignment_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedLetExpr_assignment_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedLetExpr_assignment_list(arg0, arg1)
}

func ResolvedLetExpr_set_assignment_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedLetExpr_set_assignment_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedLetExpr_set_assignment_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedLetExpr_set_assignment_list(arg0, arg1)
}

func ResolvedLetExpr_add_assignment_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedLetExpr_add_assignment_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedLetExpr_add_assignment_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedLetExpr_add_assignment_list(arg0, arg1)
}

func ResolvedLetExpr_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedLetExpr_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedLetExpr_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedLetExpr_expr(arg0, arg1)
}

func ResolvedLetExpr_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedLetExpr_set_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedLetExpr_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedLetExpr_set_expr(arg0, arg1)
}

func ResolvedScan_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedScan_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedScan_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedScan_column_list(arg0, arg1)
}

func ResolvedScan_set_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedScan_set_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedScan_set_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedScan_set_column_list(arg0, arg1)
}

func ResolvedScan_add_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedScan_add_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedScan_add_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedScan_add_column_list(arg0, arg1)
}

func ResolvedScan_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedScan_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedScan_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedScan_hint_list(arg0, arg1)
}

func ResolvedScan_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedScan_set_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedScan_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedScan_set_hint_list(arg0, arg1)
}

func ResolvedScan_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedScan_add_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedScan_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedScan_add_hint_list(arg0, arg1)
}

func ResolvedScan_is_ordered(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedScan_is_ordered(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedScan_is_ordered(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedScan_is_ordered(arg0, arg1)
}

func ResolvedScan_set_is_ordered(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedScan_set_is_ordered(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedScan_set_is_ordered(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedScan_set_is_ordered(arg0, arg1)
}

func ResolvedModel_model(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedModel_model(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedModel_model(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedModel_model(arg0, arg1)
}

func ResolvedModel_set_model(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedModel_set_model(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedModel_set_model(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedModel_set_model(arg0, arg1)
}

func ResolvedConnection_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedConnection_connection(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedConnection_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedConnection_connection(arg0, arg1)
}

func ResolvedConnection_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedConnection_set_connection(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedConnection_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedConnection_set_connection(arg0, arg1)
}

func ResolvedDescriptor_descriptor_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDescriptor_descriptor_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDescriptor_descriptor_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDescriptor_descriptor_column_list(arg0, arg1)
}

func ResolvedDescriptor_set_descriptor_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDescriptor_set_descriptor_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDescriptor_set_descriptor_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDescriptor_set_descriptor_column_list(arg0, arg1)
}

func ResolvedDescriptor_add_descriptor_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDescriptor_add_descriptor_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDescriptor_add_descriptor_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDescriptor_add_descriptor_column_list(arg0, arg1)
}

func ResolvedDescriptor_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDescriptor_descriptor_column_name_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDescriptor_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDescriptor_descriptor_column_name_list(arg0, arg1)
}

func ResolvedDescriptor_set_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDescriptor_set_descriptor_column_name_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDescriptor_set_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDescriptor_set_descriptor_column_name_list(arg0, arg1)
}

func ResolvedDescriptor_add_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDescriptor_add_descriptor_column_name_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDescriptor_add_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDescriptor_add_descriptor_column_name_list(arg0, arg1)
}

func ResolvedTableScan_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedTableScan_table(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTableScan_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTableScan_table(arg0, arg1)
}

func ResolvedTableScan_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedTableScan_set_table(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTableScan_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTableScan_set_table(arg0, arg1)
}

func ResolvedTableScan_for_system_time_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedTableScan_for_system_time_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTableScan_for_system_time_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTableScan_for_system_time_expr(arg0, arg1)
}

func ResolvedTableScan_set_for_system_time_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedTableScan_set_for_system_time_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTableScan_set_for_system_time_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTableScan_set_for_system_time_expr(arg0, arg1)
}

func ResolvedTableScan_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedTableScan_column_index_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTableScan_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTableScan_column_index_list(arg0, arg1)
}

func ResolvedTableScan_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedTableScan_set_column_index_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTableScan_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTableScan_set_column_index_list(arg0, arg1)
}

func ResolvedTableScan_add_column_index_list(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedTableScan_add_column_index_list(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedTableScan_add_column_index_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedTableScan_add_column_index_list(arg0, arg1)
}

func ResolvedTableScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedTableScan_alias(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTableScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTableScan_alias(arg0, arg1)
}

func ResolvedTableScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedTableScan_set_alias(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTableScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTableScan_set_alias(arg0, arg1)
}

func ResolvedJoinScan_join_type(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedJoinScan_join_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedJoinScan_join_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedJoinScan_join_type(arg0, arg1)
}

func ResolvedJoinScan_set_join_type(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedJoinScan_set_join_type(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedJoinScan_set_join_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedJoinScan_set_join_type(arg0, arg1)
}

func ResolvedJoinScan_left_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedJoinScan_left_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedJoinScan_left_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedJoinScan_left_scan(arg0, arg1)
}

func ResolvedJoinScan_set_left_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedJoinScan_set_left_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedJoinScan_set_left_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedJoinScan_set_left_scan(arg0, arg1)
}

func ResolvedJoinScan_right_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedJoinScan_right_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedJoinScan_right_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedJoinScan_right_scan(arg0, arg1)
}

func ResolvedJoinScan_set_right_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedJoinScan_set_right_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedJoinScan_set_right_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedJoinScan_set_right_scan(arg0, arg1)
}

func ResolvedJoinScan_join_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedJoinScan_join_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedJoinScan_join_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedJoinScan_join_expr(arg0, arg1)
}

func ResolvedJoinScan_set_join_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedJoinScan_set_join_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedJoinScan_set_join_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedJoinScan_set_join_expr(arg0, arg1)
}

func ResolvedArrayScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedArrayScan_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArrayScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArrayScan_input_scan(arg0, arg1)
}

func ResolvedArrayScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedArrayScan_set_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArrayScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArrayScan_set_input_scan(arg0, arg1)
}

func ResolvedArrayScan_array_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedArrayScan_array_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArrayScan_array_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArrayScan_array_expr(arg0, arg1)
}

func ResolvedArrayScan_set_array_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedArrayScan_set_array_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArrayScan_set_array_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArrayScan_set_array_expr(arg0, arg1)
}

func ResolvedArrayScan_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedArrayScan_element_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArrayScan_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArrayScan_element_column(arg0, arg1)
}

func ResolvedArrayScan_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedArrayScan_set_element_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArrayScan_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArrayScan_set_element_column(arg0, arg1)
}

func ResolvedArrayScan_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedArrayScan_array_offset_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArrayScan_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArrayScan_array_offset_column(arg0, arg1)
}

func ResolvedArrayScan_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedArrayScan_set_array_offset_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArrayScan_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArrayScan_set_array_offset_column(arg0, arg1)
}

func ResolvedArrayScan_join_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedArrayScan_join_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArrayScan_join_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArrayScan_join_expr(arg0, arg1)
}

func ResolvedArrayScan_set_join_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedArrayScan_set_join_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArrayScan_set_join_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArrayScan_set_join_expr(arg0, arg1)
}

func ResolvedArrayScan_is_outer(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedArrayScan_is_outer(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedArrayScan_is_outer(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedArrayScan_is_outer(arg0, arg1)
}

func ResolvedArrayScan_set_is_outer(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedArrayScan_set_is_outer(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedArrayScan_set_is_outer(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedArrayScan_set_is_outer(arg0, arg1)
}

func ResolvedColumnHolder_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumnHolder_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnHolder_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnHolder_column(arg0, arg1)
}

func ResolvedColumnHolder_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnHolder_set_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnHolder_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnHolder_set_column(arg0, arg1)
}

func ResolvedFilterScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFilterScan_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFilterScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFilterScan_input_scan(arg0, arg1)
}

func ResolvedFilterScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFilterScan_set_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFilterScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFilterScan_set_input_scan(arg0, arg1)
}

func ResolvedFilterScan_filter_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFilterScan_filter_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFilterScan_filter_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFilterScan_filter_expr(arg0, arg1)
}

func ResolvedFilterScan_set_filter_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFilterScan_set_filter_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFilterScan_set_filter_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFilterScan_set_filter_expr(arg0, arg1)
}

func ResolvedGroupingSet_group_by_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedGroupingSet_group_by_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGroupingSet_group_by_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGroupingSet_group_by_column_list(arg0, arg1)
}

func ResolvedGroupingSet_set_group_by_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGroupingSet_set_group_by_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGroupingSet_set_group_by_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGroupingSet_set_group_by_column_list(arg0, arg1)
}

func ResolvedGroupingSet_add_group_by_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGroupingSet_add_group_by_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGroupingSet_add_group_by_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGroupingSet_add_group_by_column_list(arg0, arg1)
}

func ResolvedAggregateScanBase_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAggregateScanBase_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScanBase_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScanBase_input_scan(arg0, arg1)
}

func ResolvedAggregateScanBase_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateScanBase_set_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScanBase_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScanBase_set_input_scan(arg0, arg1)
}

func ResolvedAggregateScanBase_group_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAggregateScanBase_group_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScanBase_group_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScanBase_group_by_list(arg0, arg1)
}

func ResolvedAggregateScanBase_set_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateScanBase_set_group_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScanBase_set_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScanBase_set_group_by_list(arg0, arg1)
}

func ResolvedAggregateScanBase_add_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateScanBase_add_group_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScanBase_add_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScanBase_add_group_by_list(arg0, arg1)
}

func ResolvedAggregateScanBase_collation_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAggregateScanBase_collation_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScanBase_collation_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScanBase_collation_list(arg0, arg1)
}

func ResolvedAggregateScanBase_set_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateScanBase_set_collation_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScanBase_set_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScanBase_set_collation_list(arg0, arg1)
}

func ResolvedAggregateScanBase_add_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateScanBase_add_collation_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScanBase_add_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScanBase_add_collation_list(arg0, arg1)
}

func ResolvedAggregateScanBase_aggregate_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAggregateScanBase_aggregate_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScanBase_aggregate_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScanBase_aggregate_list(arg0, arg1)
}

func ResolvedAggregateScanBase_set_aggregate_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateScanBase_set_aggregate_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScanBase_set_aggregate_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScanBase_set_aggregate_list(arg0, arg1)
}

func ResolvedAggregateScanBase_add_aggregate_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateScanBase_add_aggregate_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScanBase_add_aggregate_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScanBase_add_aggregate_list(arg0, arg1)
}

func ResolvedAggregateScan_grouping_set_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAggregateScan_grouping_set_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScan_grouping_set_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScan_grouping_set_list(arg0, arg1)
}

func ResolvedAggregateScan_set_grouping_set_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateScan_set_grouping_set_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScan_set_grouping_set_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScan_set_grouping_set_list(arg0, arg1)
}

func ResolvedAggregateScan_add_grouping_set_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateScan_add_grouping_set_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScan_add_grouping_set_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScan_add_grouping_set_list(arg0, arg1)
}

func ResolvedAggregateScan_rollup_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAggregateScan_rollup_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScan_rollup_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScan_rollup_column_list(arg0, arg1)
}

func ResolvedAggregateScan_set_rollup_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateScan_set_rollup_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScan_set_rollup_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScan_set_rollup_column_list(arg0, arg1)
}

func ResolvedAggregateScan_add_rollup_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateScan_add_rollup_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateScan_add_rollup_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateScan_add_rollup_column_list(arg0, arg1)
}

func ResolvedAnonymizedAggregateScan_k_threshold_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAnonymizedAggregateScan_k_threshold_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnonymizedAggregateScan_k_threshold_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnonymizedAggregateScan_k_threshold_expr(arg0, arg1)
}

func ResolvedAnonymizedAggregateScan_set_k_threshold_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAnonymizedAggregateScan_set_k_threshold_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnonymizedAggregateScan_set_k_threshold_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnonymizedAggregateScan_set_k_threshold_expr(arg0, arg1)
}

func ResolvedAnonymizedAggregateScan_anonymization_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAnonymizedAggregateScan_anonymization_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnonymizedAggregateScan_anonymization_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnonymizedAggregateScan_anonymization_option_list(arg0, arg1)
}

func ResolvedAnonymizedAggregateScan_set_anonymization_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAnonymizedAggregateScan_set_anonymization_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnonymizedAggregateScan_set_anonymization_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnonymizedAggregateScan_set_anonymization_option_list(arg0, arg1)
}

func ResolvedAnonymizedAggregateScan_add_anonymization_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAnonymizedAggregateScan_add_anonymization_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnonymizedAggregateScan_add_anonymization_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnonymizedAggregateScan_add_anonymization_option_list(arg0, arg1)
}

func ResolvedSetOperationItem_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSetOperationItem_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetOperationItem_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetOperationItem_scan(arg0, arg1)
}

func ResolvedSetOperationItem_set_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSetOperationItem_set_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetOperationItem_set_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetOperationItem_set_scan(arg0, arg1)
}

func ResolvedSetOperationItem_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSetOperationItem_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetOperationItem_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetOperationItem_output_column_list(arg0, arg1)
}

func ResolvedSetOperationItem_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSetOperationItem_set_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetOperationItem_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetOperationItem_set_output_column_list(arg0, arg1)
}

func ResolvedSetOperationItem_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSetOperationItem_add_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetOperationItem_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetOperationItem_add_output_column_list(arg0, arg1)
}

func ResolvedSetOperationScan_op_type(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedSetOperationScan_op_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedSetOperationScan_op_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedSetOperationScan_op_type(arg0, arg1)
}

func ResolvedSetOperationScan_set_op_type(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedSetOperationScan_set_op_type(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedSetOperationScan_set_op_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedSetOperationScan_set_op_type(arg0, arg1)
}

func ResolvedSetOperationScan_input_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSetOperationScan_input_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetOperationScan_input_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetOperationScan_input_item_list(arg0, arg1)
}

func ResolvedSetOperationScan_set_input_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSetOperationScan_set_input_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetOperationScan_set_input_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetOperationScan_set_input_item_list(arg0, arg1)
}

func ResolvedSetOperationScan_add_input_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSetOperationScan_add_input_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetOperationScan_add_input_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetOperationScan_add_input_item_list(arg0, arg1)
}

func ResolvedOrderByScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedOrderByScan_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOrderByScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOrderByScan_input_scan(arg0, arg1)
}

func ResolvedOrderByScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedOrderByScan_set_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOrderByScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOrderByScan_set_input_scan(arg0, arg1)
}

func ResolvedOrderByScan_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedOrderByScan_order_by_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOrderByScan_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOrderByScan_order_by_item_list(arg0, arg1)
}

func ResolvedOrderByScan_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedOrderByScan_set_order_by_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOrderByScan_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOrderByScan_set_order_by_item_list(arg0, arg1)
}

func ResolvedOrderByScan_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedOrderByScan_add_order_by_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOrderByScan_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOrderByScan_add_order_by_item_list(arg0, arg1)
}

func ResolvedLimitOffsetScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedLimitOffsetScan_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedLimitOffsetScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedLimitOffsetScan_input_scan(arg0, arg1)
}

func ResolvedLimitOffsetScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedLimitOffsetScan_set_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedLimitOffsetScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedLimitOffsetScan_set_input_scan(arg0, arg1)
}

func ResolvedLimitOffsetScan_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedLimitOffsetScan_limit(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedLimitOffsetScan_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedLimitOffsetScan_limit(arg0, arg1)
}

func ResolvedLimitOffsetScan_set_limit(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedLimitOffsetScan_set_limit(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedLimitOffsetScan_set_limit(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedLimitOffsetScan_set_limit(arg0, arg1)
}

func ResolvedLimitOffsetScan_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedLimitOffsetScan_offset(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedLimitOffsetScan_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedLimitOffsetScan_offset(arg0, arg1)
}

func ResolvedLimitOffsetScan_set_offset(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedLimitOffsetScan_set_offset(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedLimitOffsetScan_set_offset(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedLimitOffsetScan_set_offset(arg0, arg1)
}

func ResolvedWithRefScan_with_query_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedWithRefScan_with_query_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWithRefScan_with_query_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWithRefScan_with_query_name(arg0, arg1)
}

func ResolvedWithRefScan_set_with_query_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWithRefScan_set_with_query_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWithRefScan_set_with_query_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWithRefScan_set_with_query_name(arg0, arg1)
}

func ResolvedAnalyticScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAnalyticScan_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyticScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyticScan_input_scan(arg0, arg1)
}

func ResolvedAnalyticScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAnalyticScan_set_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyticScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyticScan_set_input_scan(arg0, arg1)
}

func ResolvedAnalyticScan_function_group_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAnalyticScan_function_group_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyticScan_function_group_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyticScan_function_group_list(arg0, arg1)
}

func ResolvedAnalyticScan_set_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAnalyticScan_set_function_group_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyticScan_set_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyticScan_set_function_group_list(arg0, arg1)
}

func ResolvedAnalyticScan_add_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAnalyticScan_add_function_group_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyticScan_add_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyticScan_add_function_group_list(arg0, arg1)
}

func ResolvedSampleScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSampleScan_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSampleScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSampleScan_input_scan(arg0, arg1)
}

func ResolvedSampleScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSampleScan_set_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSampleScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSampleScan_set_input_scan(arg0, arg1)
}

func ResolvedSampleScan_method(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSampleScan_method(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSampleScan_method(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSampleScan_method(arg0, arg1)
}

func ResolvedSampleScan_set_method(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSampleScan_set_method(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSampleScan_set_method(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSampleScan_set_method(arg0, arg1)
}

func ResolvedSampleScan_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSampleScan_size(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSampleScan_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSampleScan_size(arg0, arg1)
}

func ResolvedSampleScan_set_size(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSampleScan_set_size(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSampleScan_set_size(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSampleScan_set_size(arg0, arg1)
}

func ResolvedSampleScan_unit(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedSampleScan_unit(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedSampleScan_unit(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedSampleScan_unit(arg0, arg1)
}

func ResolvedSampleScan_set_unit(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedSampleScan_set_unit(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedSampleScan_set_unit(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedSampleScan_set_unit(arg0, arg1)
}

func ResolvedSampleScan_repeatable_argument(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSampleScan_repeatable_argument(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSampleScan_repeatable_argument(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSampleScan_repeatable_argument(arg0, arg1)
}

func ResolvedSampleScan_set_repeatable_argument(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSampleScan_set_repeatable_argument(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSampleScan_set_repeatable_argument(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSampleScan_set_repeatable_argument(arg0, arg1)
}

func ResolvedSampleScan_weight_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSampleScan_weight_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSampleScan_weight_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSampleScan_weight_column(arg0, arg1)
}

func ResolvedSampleScan_set_weight_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSampleScan_set_weight_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSampleScan_set_weight_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSampleScan_set_weight_column(arg0, arg1)
}

func ResolvedSampleScan_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSampleScan_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSampleScan_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSampleScan_partition_by_list(arg0, arg1)
}

func ResolvedSampleScan_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSampleScan_set_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSampleScan_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSampleScan_set_partition_by_list(arg0, arg1)
}

func ResolvedSampleScan_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSampleScan_add_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSampleScan_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSampleScan_add_partition_by_list(arg0, arg1)
}

func ResolvedComputedColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedComputedColumn_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedComputedColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedComputedColumn_column(arg0, arg1)
}

func ResolvedComputedColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedComputedColumn_set_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedComputedColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedComputedColumn_set_column(arg0, arg1)
}

func ResolvedComputedColumn_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedComputedColumn_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedComputedColumn_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedComputedColumn_expr(arg0, arg1)
}

func ResolvedComputedColumn_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedComputedColumn_set_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedComputedColumn_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedComputedColumn_set_expr(arg0, arg1)
}

func ResolvedOrderByItem_column_ref(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedOrderByItem_column_ref(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOrderByItem_column_ref(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOrderByItem_column_ref(arg0, arg1)
}

func ResolvedOrderByItem_set_column_ref(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedOrderByItem_set_column_ref(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOrderByItem_set_column_ref(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOrderByItem_set_column_ref(arg0, arg1)
}

func ResolvedOrderByItem_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedOrderByItem_collation_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOrderByItem_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOrderByItem_collation_name(arg0, arg1)
}

func ResolvedOrderByItem_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedOrderByItem_set_collation_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOrderByItem_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOrderByItem_set_collation_name(arg0, arg1)
}

func ResolvedOrderByItem_is_descending(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedOrderByItem_is_descending(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedOrderByItem_is_descending(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedOrderByItem_is_descending(arg0, arg1)
}

func ResolvedOrderByItem_set_is_descending(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedOrderByItem_set_is_descending(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedOrderByItem_set_is_descending(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedOrderByItem_set_is_descending(arg0, arg1)
}

func ResolvedOrderByItem_null_order(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedOrderByItem_null_order(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedOrderByItem_null_order(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedOrderByItem_null_order(arg0, arg1)
}

func ResolvedOrderByItem_set_null_order(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedOrderByItem_set_null_order(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedOrderByItem_set_null_order(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedOrderByItem_set_null_order(arg0, arg1)
}

func ResolvedOrderByItem_collation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedOrderByItem_collation(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOrderByItem_collation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOrderByItem_collation(arg0, arg1)
}

func ResolvedOrderByItem_set_collation(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedOrderByItem_set_collation(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOrderByItem_set_collation(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOrderByItem_set_collation(arg0, arg1)
}

func ResolvedColumnAnnotations_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumnAnnotations_collation_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnAnnotations_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnAnnotations_collation_name(arg0, arg1)
}

func ResolvedColumnAnnotations_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnAnnotations_set_collation_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnAnnotations_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnAnnotations_set_collation_name(arg0, arg1)
}

func ResolvedColumnAnnotations_not_null(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedColumnAnnotations_not_null(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedColumnAnnotations_not_null(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedColumnAnnotations_not_null(arg0, arg1)
}

func ResolvedColumnAnnotations_set_not_null(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedColumnAnnotations_set_not_null(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedColumnAnnotations_set_not_null(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedColumnAnnotations_set_not_null(arg0, arg1)
}

func ResolvedColumnAnnotations_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumnAnnotations_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnAnnotations_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnAnnotations_option_list(arg0, arg1)
}

func ResolvedColumnAnnotations_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnAnnotations_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnAnnotations_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnAnnotations_set_option_list(arg0, arg1)
}

func ResolvedColumnAnnotations_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnAnnotations_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnAnnotations_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnAnnotations_add_option_list(arg0, arg1)
}

func ResolvedColumnAnnotations_child_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumnAnnotations_child_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnAnnotations_child_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnAnnotations_child_list(arg0, arg1)
}

func ResolvedColumnAnnotations_set_child_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnAnnotations_set_child_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnAnnotations_set_child_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnAnnotations_set_child_list(arg0, arg1)
}

func ResolvedColumnAnnotations_add_child_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnAnnotations_add_child_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnAnnotations_add_child_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnAnnotations_add_child_list(arg0, arg1)
}

func ResolvedColumnAnnotations_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumnAnnotations_type_parameters(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnAnnotations_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnAnnotations_type_parameters(arg0, arg1)
}

func ResolvedColumnAnnotations_set_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnAnnotations_set_type_parameters(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnAnnotations_set_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnAnnotations_set_type_parameters(arg0, arg1)
}

func ResolvedGeneratedColumnInfo_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedGeneratedColumnInfo_expression(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGeneratedColumnInfo_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGeneratedColumnInfo_expression(arg0, arg1)
}

func ResolvedGeneratedColumnInfo_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGeneratedColumnInfo_set_expression(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGeneratedColumnInfo_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGeneratedColumnInfo_set_expression(arg0, arg1)
}

func ResolvedGeneratedColumnInfo_stored_mode(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedGeneratedColumnInfo_stored_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedGeneratedColumnInfo_stored_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedGeneratedColumnInfo_stored_mode(arg0, arg1)
}

func ResolvedGeneratedColumnInfo_set_stored_mode(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedGeneratedColumnInfo_set_stored_mode(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedGeneratedColumnInfo_set_stored_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedGeneratedColumnInfo_set_stored_mode(arg0, arg1)
}

func ResolvedColumnDefaultValue_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumnDefaultValue_expression(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefaultValue_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefaultValue_expression(arg0, arg1)
}

func ResolvedColumnDefaultValue_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnDefaultValue_set_expression(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefaultValue_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefaultValue_set_expression(arg0, arg1)
}

func ResolvedColumnDefaultValue_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumnDefaultValue_sql(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefaultValue_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefaultValue_sql(arg0, arg1)
}

func ResolvedColumnDefaultValue_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnDefaultValue_set_sql(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefaultValue_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefaultValue_set_sql(arg0, arg1)
}

func ResolvedColumnDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumnDefinition_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefinition_name(arg0, arg1)
}

func ResolvedColumnDefinition_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnDefinition_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefinition_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefinition_set_name(arg0, arg1)
}

func ResolvedColumnDefinition_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumnDefinition_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefinition_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefinition_type(arg0, arg1)
}

func ResolvedColumnDefinition_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnDefinition_set_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefinition_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefinition_set_type(arg0, arg1)
}

func ResolvedColumnDefinition_annotations(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumnDefinition_annotations(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefinition_annotations(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefinition_annotations(arg0, arg1)
}

func ResolvedColumnDefinition_set_annotations(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnDefinition_set_annotations(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefinition_set_annotations(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefinition_set_annotations(arg0, arg1)
}

func ResolvedColumnDefinition_is_hidden(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedColumnDefinition_is_hidden(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedColumnDefinition_is_hidden(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefinition_is_hidden(arg0, arg1)
}

func ResolvedColumnDefinition_set_is_hidden(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedColumnDefinition_set_is_hidden(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedColumnDefinition_set_is_hidden(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefinition_set_is_hidden(arg0, arg1)
}

func ResolvedColumnDefinition_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumnDefinition_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefinition_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefinition_column(arg0, arg1)
}

func ResolvedColumnDefinition_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnDefinition_set_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefinition_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefinition_set_column(arg0, arg1)
}

func ResolvedColumnDefinition_generated_column_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumnDefinition_generated_column_info(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefinition_generated_column_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefinition_generated_column_info(arg0, arg1)
}

func ResolvedColumnDefinition_set_generated_column_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnDefinition_set_generated_column_info(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefinition_set_generated_column_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefinition_set_generated_column_info(arg0, arg1)
}

func ResolvedColumnDefinition_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumnDefinition_default_value(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefinition_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefinition_default_value(arg0, arg1)
}

func ResolvedColumnDefinition_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedColumnDefinition_set_default_value(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumnDefinition_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumnDefinition_set_default_value(arg0, arg1)
}

func ResolvedPrimaryKey_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedPrimaryKey_column_offset_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPrimaryKey_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPrimaryKey_column_offset_list(arg0, arg1)
}

func ResolvedPrimaryKey_set_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPrimaryKey_set_column_offset_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPrimaryKey_set_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPrimaryKey_set_column_offset_list(arg0, arg1)
}

func ResolvedPrimaryKey_add_column_offset_list(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedPrimaryKey_add_column_offset_list(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedPrimaryKey_add_column_offset_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedPrimaryKey_add_column_offset_list(arg0, arg1)
}

func ResolvedPrimaryKey_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedPrimaryKey_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPrimaryKey_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPrimaryKey_option_list(arg0, arg1)
}

func ResolvedPrimaryKey_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPrimaryKey_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPrimaryKey_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPrimaryKey_set_option_list(arg0, arg1)
}

func ResolvedPrimaryKey_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPrimaryKey_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPrimaryKey_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPrimaryKey_add_option_list(arg0, arg1)
}

func ResolvedPrimaryKey_unenforced(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedPrimaryKey_unenforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedPrimaryKey_unenforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedPrimaryKey_unenforced(arg0, arg1)
}

func ResolvedPrimaryKey_set_unenforced(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedPrimaryKey_set_unenforced(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedPrimaryKey_set_unenforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedPrimaryKey_set_unenforced(arg0, arg1)
}

func ResolvedPrimaryKey_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedPrimaryKey_constraint_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPrimaryKey_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPrimaryKey_constraint_name(arg0, arg1)
}

func ResolvedPrimaryKey_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPrimaryKey_set_constraint_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPrimaryKey_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPrimaryKey_set_constraint_name(arg0, arg1)
}

func ResolvedPrimaryKey_column_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedPrimaryKey_column_name_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPrimaryKey_column_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPrimaryKey_column_name_list(arg0, arg1)
}

func ResolvedPrimaryKey_set_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPrimaryKey_set_column_name_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPrimaryKey_set_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPrimaryKey_set_column_name_list(arg0, arg1)
}

func ResolvedPrimaryKey_add_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPrimaryKey_add_column_name_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPrimaryKey_add_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPrimaryKey_add_column_name_list(arg0, arg1)
}

func ResolvedForeignKey_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedForeignKey_constraint_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedForeignKey_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_constraint_name(arg0, arg1)
}

func ResolvedForeignKey_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedForeignKey_set_constraint_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedForeignKey_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_set_constraint_name(arg0, arg1)
}

func ResolvedForeignKey_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedForeignKey_referencing_column_offset_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedForeignKey_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_referencing_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_set_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedForeignKey_set_referencing_column_offset_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedForeignKey_set_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_set_referencing_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_add_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedForeignKey_add_referencing_column_offset_list(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedForeignKey_add_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_add_referencing_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_referenced_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedForeignKey_referenced_table(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedForeignKey_referenced_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_referenced_table(arg0, arg1)
}

func ResolvedForeignKey_set_referenced_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedForeignKey_set_referenced_table(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedForeignKey_set_referenced_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_set_referenced_table(arg0, arg1)
}

func ResolvedForeignKey_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedForeignKey_referenced_column_offset_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedForeignKey_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_referenced_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_set_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedForeignKey_set_referenced_column_offset_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedForeignKey_set_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_set_referenced_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_add_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedForeignKey_add_referenced_column_offset_list(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedForeignKey_add_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_add_referenced_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_match_mode(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedForeignKey_match_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedForeignKey_match_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_match_mode(arg0, arg1)
}

func ResolvedForeignKey_set_match_mode(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedForeignKey_set_match_mode(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedForeignKey_set_match_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_set_match_mode(arg0, arg1)
}

func ResolvedForeignKey_update_action(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedForeignKey_update_action(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedForeignKey_update_action(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_update_action(arg0, arg1)
}

func ResolvedForeignKey_set_update_action(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedForeignKey_set_update_action(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedForeignKey_set_update_action(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_set_update_action(arg0, arg1)
}

func ResolvedForeignKey_delete_action(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedForeignKey_delete_action(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedForeignKey_delete_action(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_delete_action(arg0, arg1)
}

func ResolvedForeignKey_set_delete_action(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedForeignKey_set_delete_action(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedForeignKey_set_delete_action(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_set_delete_action(arg0, arg1)
}

func ResolvedForeignKey_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedForeignKey_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedForeignKey_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_enforced(arg0, arg1)
}

func ResolvedForeignKey_set_enforced(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedForeignKey_set_enforced(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedForeignKey_set_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_set_enforced(arg0, arg1)
}

func ResolvedForeignKey_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedForeignKey_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedForeignKey_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_option_list(arg0, arg1)
}

func ResolvedForeignKey_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedForeignKey_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedForeignKey_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_set_option_list(arg0, arg1)
}

func ResolvedForeignKey_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedForeignKey_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedForeignKey_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_add_option_list(arg0, arg1)
}

func ResolvedForeignKey_referencing_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedForeignKey_referencing_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedForeignKey_referencing_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_referencing_column_list(arg0, arg1)
}

func ResolvedForeignKey_set_referencing_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedForeignKey_set_referencing_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedForeignKey_set_referencing_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_set_referencing_column_list(arg0, arg1)
}

func ResolvedForeignKey_add_referencing_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedForeignKey_add_referencing_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedForeignKey_add_referencing_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedForeignKey_add_referencing_column_list(arg0, arg1)
}

func ResolvedCheckConstraint_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCheckConstraint_constraint_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCheckConstraint_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCheckConstraint_constraint_name(arg0, arg1)
}

func ResolvedCheckConstraint_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCheckConstraint_set_constraint_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCheckConstraint_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCheckConstraint_set_constraint_name(arg0, arg1)
}

func ResolvedCheckConstraint_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCheckConstraint_expression(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCheckConstraint_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCheckConstraint_expression(arg0, arg1)
}

func ResolvedCheckConstraint_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCheckConstraint_set_expression(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCheckConstraint_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCheckConstraint_set_expression(arg0, arg1)
}

func ResolvedCheckConstraint_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCheckConstraint_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCheckConstraint_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCheckConstraint_enforced(arg0, arg1)
}

func ResolvedCheckConstraint_set_enforced(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCheckConstraint_set_enforced(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCheckConstraint_set_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCheckConstraint_set_enforced(arg0, arg1)
}

func ResolvedCheckConstraint_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCheckConstraint_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCheckConstraint_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCheckConstraint_option_list(arg0, arg1)
}

func ResolvedCheckConstraint_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCheckConstraint_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCheckConstraint_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCheckConstraint_set_option_list(arg0, arg1)
}

func ResolvedCheckConstraint_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCheckConstraint_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCheckConstraint_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCheckConstraint_add_option_list(arg0, arg1)
}

func ResolvedOutputColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedOutputColumn_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOutputColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOutputColumn_name(arg0, arg1)
}

func ResolvedOutputColumn_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedOutputColumn_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOutputColumn_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOutputColumn_set_name(arg0, arg1)
}

func ResolvedOutputColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedOutputColumn_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOutputColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOutputColumn_column(arg0, arg1)
}

func ResolvedOutputColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedOutputColumn_set_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOutputColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOutputColumn_set_column(arg0, arg1)
}

func ResolvedProjectScan_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedProjectScan_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedProjectScan_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedProjectScan_expr_list(arg0, arg1)
}

func ResolvedProjectScan_set_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedProjectScan_set_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedProjectScan_set_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedProjectScan_set_expr_list(arg0, arg1)
}

func ResolvedProjectScan_add_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedProjectScan_add_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedProjectScan_add_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedProjectScan_add_expr_list(arg0, arg1)
}

func ResolvedProjectScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedProjectScan_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedProjectScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedProjectScan_input_scan(arg0, arg1)
}

func ResolvedProjectScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedProjectScan_set_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedProjectScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedProjectScan_set_input_scan(arg0, arg1)
}

func ResolvedTVFScan_tvf(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedTVFScan_tvf(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTVFScan_tvf(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTVFScan_tvf(arg0, arg1)
}

func ResolvedTVFScan_set_tvf(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedTVFScan_set_tvf(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTVFScan_set_tvf(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTVFScan_set_tvf(arg0, arg1)
}

func ResolvedTVFScan_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedTVFScan_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTVFScan_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTVFScan_signature(arg0, arg1)
}

func ResolvedTVFScan_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedTVFScan_set_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTVFScan_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTVFScan_set_signature(arg0, arg1)
}

func ResolvedTVFScan_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedTVFScan_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTVFScan_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTVFScan_argument_list(arg0, arg1)
}

func ResolvedTVFScan_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedTVFScan_set_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTVFScan_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTVFScan_set_argument_list(arg0, arg1)
}

func ResolvedTVFScan_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedTVFScan_add_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTVFScan_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTVFScan_add_argument_list(arg0, arg1)
}

func ResolvedTVFScan_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedTVFScan_column_index_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTVFScan_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTVFScan_column_index_list(arg0, arg1)
}

func ResolvedTVFScan_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedTVFScan_set_column_index_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTVFScan_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTVFScan_set_column_index_list(arg0, arg1)
}

func ResolvedTVFScan_add_column_index_list(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedTVFScan_add_column_index_list(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedTVFScan_add_column_index_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedTVFScan_add_column_index_list(arg0, arg1)
}

func ResolvedTVFScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedTVFScan_alias(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTVFScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTVFScan_alias(arg0, arg1)
}

func ResolvedTVFScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedTVFScan_set_alias(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTVFScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTVFScan_set_alias(arg0, arg1)
}

func ResolvedTVFScan_function_call_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedTVFScan_function_call_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTVFScan_function_call_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTVFScan_function_call_signature(arg0, arg1)
}

func ResolvedTVFScan_set_function_call_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedTVFScan_set_function_call_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTVFScan_set_function_call_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTVFScan_set_function_call_signature(arg0, arg1)
}

func ResolvedGroupRowsScan_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedGroupRowsScan_input_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGroupRowsScan_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGroupRowsScan_input_column_list(arg0, arg1)
}

func ResolvedGroupRowsScan_set_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGroupRowsScan_set_input_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGroupRowsScan_set_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGroupRowsScan_set_input_column_list(arg0, arg1)
}

func ResolvedGroupRowsScan_add_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGroupRowsScan_add_input_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGroupRowsScan_add_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGroupRowsScan_add_input_column_list(arg0, arg1)
}

func ResolvedGroupRowsScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedGroupRowsScan_alias(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGroupRowsScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGroupRowsScan_alias(arg0, arg1)
}

func ResolvedGroupRowsScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGroupRowsScan_set_alias(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGroupRowsScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGroupRowsScan_set_alias(arg0, arg1)
}

func ResolvedFunctionArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionArgument_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionArgument_expr(arg0, arg1)
}

func ResolvedFunctionArgument_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionArgument_set_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionArgument_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionArgument_set_expr(arg0, arg1)
}

func ResolvedFunctionArgument_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionArgument_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionArgument_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionArgument_scan(arg0, arg1)
}

func ResolvedFunctionArgument_set_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionArgument_set_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionArgument_set_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionArgument_set_scan(arg0, arg1)
}

func ResolvedFunctionArgument_model(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionArgument_model(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionArgument_model(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionArgument_model(arg0, arg1)
}

func ResolvedFunctionArgument_set_model(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionArgument_set_model(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionArgument_set_model(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionArgument_set_model(arg0, arg1)
}

func ResolvedFunctionArgument_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionArgument_connection(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionArgument_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionArgument_connection(arg0, arg1)
}

func ResolvedFunctionArgument_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionArgument_set_connection(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionArgument_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionArgument_set_connection(arg0, arg1)
}

func ResolvedFunctionArgument_descriptor_arg(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionArgument_descriptor_arg(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionArgument_descriptor_arg(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionArgument_descriptor_arg(arg0, arg1)
}

func ResolvedFunctionArgument_set_descriptor_arg(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionArgument_set_descriptor_arg(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionArgument_set_descriptor_arg(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionArgument_set_descriptor_arg(arg0, arg1)
}

func ResolvedFunctionArgument_argument_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionArgument_argument_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionArgument_argument_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionArgument_argument_column_list(arg0, arg1)
}

func ResolvedFunctionArgument_set_argument_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionArgument_set_argument_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionArgument_set_argument_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionArgument_set_argument_column_list(arg0, arg1)
}

func ResolvedFunctionArgument_add_argument_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionArgument_add_argument_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionArgument_add_argument_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionArgument_add_argument_column_list(arg0, arg1)
}

func ResolvedFunctionArgument_inline_lambda(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionArgument_inline_lambda(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionArgument_inline_lambda(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionArgument_inline_lambda(arg0, arg1)
}

func ResolvedFunctionArgument_set_inline_lambda(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionArgument_set_inline_lambda(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionArgument_set_inline_lambda(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionArgument_set_inline_lambda(arg0, arg1)
}

func ResolvedStatement_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedStatement_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedStatement_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedStatement_hint_list(arg0, arg1)
}

func ResolvedStatement_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedStatement_set_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedStatement_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedStatement_set_hint_list(arg0, arg1)
}

func ResolvedStatement_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedStatement_add_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedStatement_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedStatement_add_hint_list(arg0, arg1)
}

func ResolvedExplainStmt_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExplainStmt_statement(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExplainStmt_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExplainStmt_statement(arg0, arg1)
}

func ResolvedExplainStmt_set_statement(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExplainStmt_set_statement(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExplainStmt_set_statement(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExplainStmt_set_statement(arg0, arg1)
}

func ResolvedQueryStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedQueryStmt_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedQueryStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedQueryStmt_output_column_list(arg0, arg1)
}

func ResolvedQueryStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedQueryStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedQueryStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedQueryStmt_set_output_column_list(arg0, arg1)
}

func ResolvedQueryStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedQueryStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedQueryStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedQueryStmt_add_output_column_list(arg0, arg1)
}

func ResolvedQueryStmt_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedQueryStmt_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedQueryStmt_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedQueryStmt_is_value_table(arg0, arg1)
}

func ResolvedQueryStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedQueryStmt_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedQueryStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedQueryStmt_set_is_value_table(arg0, arg1)
}

func ResolvedQueryStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedQueryStmt_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedQueryStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedQueryStmt_query(arg0, arg1)
}

func ResolvedQueryStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedQueryStmt_set_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedQueryStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedQueryStmt_set_query(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateDatabaseStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateDatabaseStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateDatabaseStmt_name_path(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateDatabaseStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateDatabaseStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateDatabaseStmt_set_name_path(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateDatabaseStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateDatabaseStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateDatabaseStmt_add_name_path(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateDatabaseStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateDatabaseStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateDatabaseStmt_option_list(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateDatabaseStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateDatabaseStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateDatabaseStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateDatabaseStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateDatabaseStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateDatabaseStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateStatement_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateStatement_name_path(arg0, arg1)
}

func ResolvedCreateStatement_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateStatement_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateStatement_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateStatement_set_name_path(arg0, arg1)
}

func ResolvedCreateStatement_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateStatement_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateStatement_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateStatement_add_name_path(arg0, arg1)
}

func ResolvedCreateStatement_create_scope(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedCreateStatement_create_scope(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateStatement_create_scope(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateStatement_create_scope(arg0, arg1)
}

func ResolvedCreateStatement_set_create_scope(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateStatement_set_create_scope(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateStatement_set_create_scope(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateStatement_set_create_scope(arg0, arg1)
}

func ResolvedCreateStatement_create_mode(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedCreateStatement_create_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateStatement_create_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateStatement_create_mode(arg0, arg1)
}

func ResolvedCreateStatement_set_create_mode(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateStatement_set_create_mode(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateStatement_set_create_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateStatement_set_create_mode(arg0, arg1)
}

func ResolvedIndexItem_column_ref(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedIndexItem_column_ref(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedIndexItem_column_ref(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedIndexItem_column_ref(arg0, arg1)
}

func ResolvedIndexItem_set_column_ref(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedIndexItem_set_column_ref(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedIndexItem_set_column_ref(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedIndexItem_set_column_ref(arg0, arg1)
}

func ResolvedIndexItem_descending(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedIndexItem_descending(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedIndexItem_descending(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedIndexItem_descending(arg0, arg1)
}

func ResolvedIndexItem_set_descending(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedIndexItem_set_descending(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedIndexItem_set_descending(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedIndexItem_set_descending(arg0, arg1)
}

func ResolvedUnnestItem_array_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUnnestItem_array_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnnestItem_array_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnnestItem_array_expr(arg0, arg1)
}

func ResolvedUnnestItem_set_array_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUnnestItem_set_array_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnnestItem_set_array_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnnestItem_set_array_expr(arg0, arg1)
}

func ResolvedUnnestItem_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUnnestItem_element_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnnestItem_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnnestItem_element_column(arg0, arg1)
}

func ResolvedUnnestItem_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUnnestItem_set_element_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnnestItem_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnnestItem_set_element_column(arg0, arg1)
}

func ResolvedUnnestItem_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUnnestItem_array_offset_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnnestItem_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnnestItem_array_offset_column(arg0, arg1)
}

func ResolvedUnnestItem_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUnnestItem_set_array_offset_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnnestItem_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnnestItem_set_array_offset_column(arg0, arg1)
}

func ResolvedCreateIndexStmt_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_table_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_table_name_path(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_set_table_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_set_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_set_table_name_path(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_add_table_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_add_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_add_table_name_path(arg0, arg1)
}

func ResolvedCreateIndexStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_table_scan(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_set_table_scan(arg0, arg1)
}

func ResolvedCreateIndexStmt_is_unique(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCreateIndexStmt_is_unique(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateIndexStmt_is_unique(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_is_unique(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_is_unique(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateIndexStmt_set_is_unique(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateIndexStmt_set_is_unique(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_set_is_unique(arg0, arg1)
}

func ResolvedCreateIndexStmt_is_search(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCreateIndexStmt_is_search(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateIndexStmt_is_search(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_is_search(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_is_search(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateIndexStmt_set_is_search(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateIndexStmt_set_is_search(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_set_is_search(arg0, arg1)
}

func ResolvedCreateIndexStmt_index_all_columns(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCreateIndexStmt_index_all_columns(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateIndexStmt_index_all_columns(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_index_all_columns(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_index_all_columns(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateIndexStmt_set_index_all_columns(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateIndexStmt_set_index_all_columns(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_set_index_all_columns(arg0, arg1)
}

func ResolvedCreateIndexStmt_index_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_index_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_index_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_index_item_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_index_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_set_index_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_set_index_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_set_index_item_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_index_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_add_index_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_add_index_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_add_index_item_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_storing_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_storing_expression_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_storing_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_storing_expression_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_storing_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_set_storing_expression_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_set_storing_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_set_storing_expression_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_storing_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_add_storing_expression_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_add_storing_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_add_storing_expression_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_option_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_computed_columns_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_computed_columns_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_computed_columns_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_computed_columns_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_computed_columns_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_set_computed_columns_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_set_computed_columns_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_set_computed_columns_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_computed_columns_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_add_computed_columns_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_add_computed_columns_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_add_computed_columns_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_unnest_expressions_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_unnest_expressions_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_unnest_expressions_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_unnest_expressions_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_unnest_expressions_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_set_unnest_expressions_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_set_unnest_expressions_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_set_unnest_expressions_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_unnest_expressions_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateIndexStmt_add_unnest_expressions_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateIndexStmt_add_unnest_expressions_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateIndexStmt_add_unnest_expressions_list(arg0, arg1)
}

func ResolvedCreateSchemaStmt_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateSchemaStmt_collation_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateSchemaStmt_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateSchemaStmt_collation_name(arg0, arg1)
}

func ResolvedCreateSchemaStmt_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateSchemaStmt_set_collation_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateSchemaStmt_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateSchemaStmt_set_collation_name(arg0, arg1)
}

func ResolvedCreateSchemaStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateSchemaStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateSchemaStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateSchemaStmt_option_list(arg0, arg1)
}

func ResolvedCreateSchemaStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateSchemaStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateSchemaStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateSchemaStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateSchemaStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateSchemaStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateSchemaStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateSchemaStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_option_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_set_option_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_add_option_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_column_definition_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_column_definition_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_set_column_definition_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_set_column_definition_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_add_column_definition_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_add_column_definition_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_pseudo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_pseudo_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_pseudo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_pseudo_column_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_set_pseudo_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_set_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_set_pseudo_column_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_add_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_add_pseudo_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_add_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_add_pseudo_column_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_primary_key(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_primary_key(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_primary_key(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_primary_key(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_primary_key(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_set_primary_key(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_set_primary_key(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_set_primary_key(arg0, arg1)
}

func ResolvedCreateTableStmtBase_foreign_key_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_foreign_key_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_foreign_key_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_foreign_key_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_set_foreign_key_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_set_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_set_foreign_key_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_add_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_add_foreign_key_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_add_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_add_foreign_key_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_check_constraint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_check_constraint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_check_constraint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_check_constraint_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_set_check_constraint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_set_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_set_check_constraint_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_add_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_add_check_constraint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_add_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_add_check_constraint_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCreateTableStmtBase_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateTableStmtBase_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_is_value_table(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateTableStmtBase_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateTableStmtBase_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_set_is_value_table(arg0, arg1)
}

func ResolvedCreateTableStmtBase_like_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_like_table(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_like_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_like_table(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_like_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_set_like_table(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_set_like_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_set_like_table(arg0, arg1)
}

func ResolvedCreateTableStmtBase_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_collation_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_collation_name(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmtBase_set_collation_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmtBase_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmtBase_set_collation_name(arg0, arg1)
}

func ResolvedCreateTableStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmt_clone_from(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmt_clone_from(arg0, arg1)
}

func ResolvedCreateTableStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmt_set_clone_from(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmt_set_clone_from(arg0, arg1)
}

func ResolvedCreateTableStmt_copy_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmt_copy_from(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmt_copy_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmt_copy_from(arg0, arg1)
}

func ResolvedCreateTableStmt_set_copy_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmt_set_copy_from(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmt_set_copy_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmt_set_copy_from(arg0, arg1)
}

func ResolvedCreateTableStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmt_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmt_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmt_set_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmt_set_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmt_add_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmt_add_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmt_cluster_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmt_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmt_set_cluster_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmt_set_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableStmt_add_cluster_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableStmt_add_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableAsSelectStmt_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableAsSelectStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableAsSelectStmt_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableAsSelectStmt_set_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableAsSelectStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableAsSelectStmt_set_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableAsSelectStmt_add_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableAsSelectStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableAsSelectStmt_add_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableAsSelectStmt_cluster_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableAsSelectStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableAsSelectStmt_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableAsSelectStmt_set_cluster_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableAsSelectStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableAsSelectStmt_set_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableAsSelectStmt_add_cluster_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableAsSelectStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableAsSelectStmt_add_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableAsSelectStmt_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableAsSelectStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableAsSelectStmt_output_column_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableAsSelectStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableAsSelectStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableAsSelectStmt_set_output_column_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableAsSelectStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableAsSelectStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableAsSelectStmt_add_output_column_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableAsSelectStmt_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableAsSelectStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableAsSelectStmt_query(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableAsSelectStmt_set_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableAsSelectStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableAsSelectStmt_set_query(arg0, arg1)
}

func ResolvedCreateModelStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_option_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateModelStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_set_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_add_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_query(arg0, arg1)
}

func ResolvedCreateModelStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_set_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_set_query(arg0, arg1)
}

func ResolvedCreateModelStmt_transform_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_transform_input_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_transform_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_transform_input_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_transform_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_set_transform_input_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_set_transform_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_set_transform_input_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_transform_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_add_transform_input_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_add_transform_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_add_transform_input_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_transform_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_transform_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_transform_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_transform_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_transform_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_set_transform_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_set_transform_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_set_transform_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_transform_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_add_transform_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_add_transform_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_add_transform_list(arg0, arg1)
}

func ResolvedCreateModelStmt_transform_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_transform_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_transform_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_transform_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_transform_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_set_transform_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_set_transform_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_set_transform_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_transform_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_add_transform_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_add_transform_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_add_transform_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_transform_analytic_function_group_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_transform_analytic_function_group_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_set_transform_analytic_function_group_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_set_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_set_transform_analytic_function_group_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateModelStmt_add_transform_analytic_function_group_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateModelStmt_add_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateModelStmt_add_transform_analytic_function_group_list(arg0, arg1)
}

func ResolvedCreateViewBase_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateViewBase_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateViewBase_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_option_list(arg0, arg1)
}

func ResolvedCreateViewBase_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateViewBase_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateViewBase_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_set_option_list(arg0, arg1)
}

func ResolvedCreateViewBase_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateViewBase_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateViewBase_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_add_option_list(arg0, arg1)
}

func ResolvedCreateViewBase_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateViewBase_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateViewBase_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_output_column_list(arg0, arg1)
}

func ResolvedCreateViewBase_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateViewBase_set_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateViewBase_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_set_output_column_list(arg0, arg1)
}

func ResolvedCreateViewBase_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateViewBase_add_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateViewBase_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_add_output_column_list(arg0, arg1)
}

func ResolvedCreateViewBase_has_explicit_columns(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCreateViewBase_has_explicit_columns(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateViewBase_has_explicit_columns(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_has_explicit_columns(arg0, arg1)
}

func ResolvedCreateViewBase_set_has_explicit_columns(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateViewBase_set_has_explicit_columns(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateViewBase_set_has_explicit_columns(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_set_has_explicit_columns(arg0, arg1)
}

func ResolvedCreateViewBase_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateViewBase_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateViewBase_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_query(arg0, arg1)
}

func ResolvedCreateViewBase_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateViewBase_set_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateViewBase_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_set_query(arg0, arg1)
}

func ResolvedCreateViewBase_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateViewBase_sql(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateViewBase_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_sql(arg0, arg1)
}

func ResolvedCreateViewBase_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateViewBase_set_sql(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateViewBase_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_set_sql(arg0, arg1)
}

func ResolvedCreateViewBase_sql_security(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedCreateViewBase_sql_security(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateViewBase_sql_security(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_sql_security(arg0, arg1)
}

func ResolvedCreateViewBase_set_sql_security(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateViewBase_set_sql_security(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateViewBase_set_sql_security(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_set_sql_security(arg0, arg1)
}

func ResolvedCreateViewBase_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCreateViewBase_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateViewBase_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_is_value_table(arg0, arg1)
}

func ResolvedCreateViewBase_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateViewBase_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateViewBase_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_set_is_value_table(arg0, arg1)
}

func ResolvedCreateViewBase_recursive(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCreateViewBase_recursive(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateViewBase_recursive(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_recursive(arg0, arg1)
}

func ResolvedCreateViewBase_set_recursive(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateViewBase_set_recursive(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateViewBase_set_recursive(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateViewBase_set_recursive(arg0, arg1)
}

func ResolvedWithPartitionColumns_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedWithPartitionColumns_column_definition_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWithPartitionColumns_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWithPartitionColumns_column_definition_list(arg0, arg1)
}

func ResolvedWithPartitionColumns_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWithPartitionColumns_set_column_definition_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWithPartitionColumns_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWithPartitionColumns_set_column_definition_list(arg0, arg1)
}

func ResolvedWithPartitionColumns_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWithPartitionColumns_add_column_definition_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWithPartitionColumns_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWithPartitionColumns_add_column_definition_list(arg0, arg1)
}

func ResolvedCreateSnapshotTableStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateSnapshotTableStmt_clone_from(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateSnapshotTableStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateSnapshotTableStmt_clone_from(arg0, arg1)
}

func ResolvedCreateSnapshotTableStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateSnapshotTableStmt_set_clone_from(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateSnapshotTableStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateSnapshotTableStmt_set_clone_from(arg0, arg1)
}

func ResolvedCreateSnapshotTableStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateSnapshotTableStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateSnapshotTableStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateSnapshotTableStmt_option_list(arg0, arg1)
}

func ResolvedCreateSnapshotTableStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateSnapshotTableStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateSnapshotTableStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateSnapshotTableStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateSnapshotTableStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateSnapshotTableStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateSnapshotTableStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateSnapshotTableStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateExternalTableStmt_with_partition_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateExternalTableStmt_with_partition_columns(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateExternalTableStmt_with_partition_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateExternalTableStmt_with_partition_columns(arg0, arg1)
}

func ResolvedCreateExternalTableStmt_set_with_partition_columns(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateExternalTableStmt_set_with_partition_columns(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateExternalTableStmt_set_with_partition_columns(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateExternalTableStmt_set_with_partition_columns(arg0, arg1)
}

func ResolvedCreateExternalTableStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateExternalTableStmt_connection(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateExternalTableStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateExternalTableStmt_connection(arg0, arg1)
}

func ResolvedCreateExternalTableStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateExternalTableStmt_set_connection(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateExternalTableStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateExternalTableStmt_set_connection(arg0, arg1)
}

func ResolvedExportModelStmt_model_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExportModelStmt_model_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportModelStmt_model_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportModelStmt_model_name_path(arg0, arg1)
}

func ResolvedExportModelStmt_set_model_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExportModelStmt_set_model_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportModelStmt_set_model_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportModelStmt_set_model_name_path(arg0, arg1)
}

func ResolvedExportModelStmt_add_model_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExportModelStmt_add_model_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportModelStmt_add_model_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportModelStmt_add_model_name_path(arg0, arg1)
}

func ResolvedExportModelStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExportModelStmt_connection(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportModelStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportModelStmt_connection(arg0, arg1)
}

func ResolvedExportModelStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExportModelStmt_set_connection(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportModelStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportModelStmt_set_connection(arg0, arg1)
}

func ResolvedExportModelStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExportModelStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportModelStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportModelStmt_option_list(arg0, arg1)
}

func ResolvedExportModelStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExportModelStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportModelStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportModelStmt_set_option_list(arg0, arg1)
}

func ResolvedExportModelStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExportModelStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportModelStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportModelStmt_add_option_list(arg0, arg1)
}

func ResolvedExportDataStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExportDataStmt_connection(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportDataStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportDataStmt_connection(arg0, arg1)
}

func ResolvedExportDataStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExportDataStmt_set_connection(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportDataStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportDataStmt_set_connection(arg0, arg1)
}

func ResolvedExportDataStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExportDataStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportDataStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportDataStmt_option_list(arg0, arg1)
}

func ResolvedExportDataStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExportDataStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportDataStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportDataStmt_set_option_list(arg0, arg1)
}

func ResolvedExportDataStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExportDataStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportDataStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportDataStmt_add_option_list(arg0, arg1)
}

func ResolvedExportDataStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExportDataStmt_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportDataStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportDataStmt_output_column_list(arg0, arg1)
}

func ResolvedExportDataStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExportDataStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportDataStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportDataStmt_set_output_column_list(arg0, arg1)
}

func ResolvedExportDataStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExportDataStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportDataStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportDataStmt_add_output_column_list(arg0, arg1)
}

func ResolvedExportDataStmt_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedExportDataStmt_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedExportDataStmt_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedExportDataStmt_is_value_table(arg0, arg1)
}

func ResolvedExportDataStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedExportDataStmt_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedExportDataStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedExportDataStmt_set_is_value_table(arg0, arg1)
}

func ResolvedExportDataStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExportDataStmt_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportDataStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportDataStmt_query(arg0, arg1)
}

func ResolvedExportDataStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExportDataStmt_set_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExportDataStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExportDataStmt_set_query(arg0, arg1)
}

func ResolvedDefineTableStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDefineTableStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDefineTableStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDefineTableStmt_name_path(arg0, arg1)
}

func ResolvedDefineTableStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDefineTableStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDefineTableStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDefineTableStmt_set_name_path(arg0, arg1)
}

func ResolvedDefineTableStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDefineTableStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDefineTableStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDefineTableStmt_add_name_path(arg0, arg1)
}

func ResolvedDefineTableStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDefineTableStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDefineTableStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDefineTableStmt_option_list(arg0, arg1)
}

func ResolvedDefineTableStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDefineTableStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDefineTableStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDefineTableStmt_set_option_list(arg0, arg1)
}

func ResolvedDefineTableStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDefineTableStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDefineTableStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDefineTableStmt_add_option_list(arg0, arg1)
}

func ResolvedDescribeStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDescribeStmt_object_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDescribeStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDescribeStmt_object_type(arg0, arg1)
}

func ResolvedDescribeStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDescribeStmt_set_object_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDescribeStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDescribeStmt_set_object_type(arg0, arg1)
}

func ResolvedDescribeStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDescribeStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDescribeStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDescribeStmt_name_path(arg0, arg1)
}

func ResolvedDescribeStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDescribeStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDescribeStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDescribeStmt_set_name_path(arg0, arg1)
}

func ResolvedDescribeStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDescribeStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDescribeStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDescribeStmt_add_name_path(arg0, arg1)
}

func ResolvedDescribeStmt_from_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDescribeStmt_from_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDescribeStmt_from_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDescribeStmt_from_name_path(arg0, arg1)
}

func ResolvedDescribeStmt_set_from_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDescribeStmt_set_from_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDescribeStmt_set_from_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDescribeStmt_set_from_name_path(arg0, arg1)
}

func ResolvedDescribeStmt_add_from_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDescribeStmt_add_from_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDescribeStmt_add_from_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDescribeStmt_add_from_name_path(arg0, arg1)
}

func ResolvedShowStmt_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedShowStmt_identifier(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedShowStmt_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedShowStmt_identifier(arg0, arg1)
}

func ResolvedShowStmt_set_identifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedShowStmt_set_identifier(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedShowStmt_set_identifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedShowStmt_set_identifier(arg0, arg1)
}

func ResolvedShowStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedShowStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedShowStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedShowStmt_name_path(arg0, arg1)
}

func ResolvedShowStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedShowStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedShowStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedShowStmt_set_name_path(arg0, arg1)
}

func ResolvedShowStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedShowStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedShowStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedShowStmt_add_name_path(arg0, arg1)
}

func ResolvedShowStmt_like_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedShowStmt_like_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedShowStmt_like_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedShowStmt_like_expr(arg0, arg1)
}

func ResolvedShowStmt_set_like_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedShowStmt_set_like_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedShowStmt_set_like_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedShowStmt_set_like_expr(arg0, arg1)
}

func ResolvedBeginStmt_read_write_mode(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedBeginStmt_read_write_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedBeginStmt_read_write_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedBeginStmt_read_write_mode(arg0, arg1)
}

func ResolvedBeginStmt_set_read_write_mode(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedBeginStmt_set_read_write_mode(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedBeginStmt_set_read_write_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedBeginStmt_set_read_write_mode(arg0, arg1)
}

func ResolvedBeginStmt_isolation_level_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedBeginStmt_isolation_level_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedBeginStmt_isolation_level_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedBeginStmt_isolation_level_list(arg0, arg1)
}

func ResolvedBeginStmt_set_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedBeginStmt_set_isolation_level_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedBeginStmt_set_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedBeginStmt_set_isolation_level_list(arg0, arg1)
}

func ResolvedBeginStmt_add_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedBeginStmt_add_isolation_level_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedBeginStmt_add_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedBeginStmt_add_isolation_level_list(arg0, arg1)
}

func ResolvedSetTransactionStmt_read_write_mode(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedSetTransactionStmt_read_write_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedSetTransactionStmt_read_write_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedSetTransactionStmt_read_write_mode(arg0, arg1)
}

func ResolvedSetTransactionStmt_set_read_write_mode(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedSetTransactionStmt_set_read_write_mode(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedSetTransactionStmt_set_read_write_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedSetTransactionStmt_set_read_write_mode(arg0, arg1)
}

func ResolvedSetTransactionStmt_isolation_level_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSetTransactionStmt_isolation_level_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetTransactionStmt_isolation_level_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetTransactionStmt_isolation_level_list(arg0, arg1)
}

func ResolvedSetTransactionStmt_set_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSetTransactionStmt_set_isolation_level_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetTransactionStmt_set_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetTransactionStmt_set_isolation_level_list(arg0, arg1)
}

func ResolvedSetTransactionStmt_add_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSetTransactionStmt_add_isolation_level_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetTransactionStmt_add_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetTransactionStmt_add_isolation_level_list(arg0, arg1)
}

func ResolvedStartBatchStmt_batch_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedStartBatchStmt_batch_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedStartBatchStmt_batch_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedStartBatchStmt_batch_type(arg0, arg1)
}

func ResolvedStartBatchStmt_set_batch_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedStartBatchStmt_set_batch_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedStartBatchStmt_set_batch_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedStartBatchStmt_set_batch_type(arg0, arg1)
}

func ResolvedDropStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropStmt_object_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropStmt_object_type(arg0, arg1)
}

func ResolvedDropStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropStmt_set_object_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropStmt_set_object_type(arg0, arg1)
}

func ResolvedDropStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedDropStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedDropStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedDropStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedDropStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedDropStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedDropStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropStmt_name_path(arg0, arg1)
}

func ResolvedDropStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropStmt_set_name_path(arg0, arg1)
}

func ResolvedDropStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropStmt_add_name_path(arg0, arg1)
}

func ResolvedDropStmt_drop_mode(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedDropStmt_drop_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedDropStmt_drop_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedDropStmt_drop_mode(arg0, arg1)
}

func ResolvedDropStmt_set_drop_mode(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedDropStmt_set_drop_mode(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedDropStmt_set_drop_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedDropStmt_set_drop_mode(arg0, arg1)
}

func ResolvedDropMaterializedViewStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedDropMaterializedViewStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedDropMaterializedViewStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedDropMaterializedViewStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropMaterializedViewStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedDropMaterializedViewStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedDropMaterializedViewStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedDropMaterializedViewStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropMaterializedViewStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropMaterializedViewStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropMaterializedViewStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropMaterializedViewStmt_name_path(arg0, arg1)
}

func ResolvedDropMaterializedViewStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropMaterializedViewStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropMaterializedViewStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropMaterializedViewStmt_set_name_path(arg0, arg1)
}

func ResolvedDropMaterializedViewStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropMaterializedViewStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropMaterializedViewStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropMaterializedViewStmt_add_name_path(arg0, arg1)
}

func ResolvedDropSnapshotTableStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedDropSnapshotTableStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedDropSnapshotTableStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedDropSnapshotTableStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropSnapshotTableStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedDropSnapshotTableStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedDropSnapshotTableStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedDropSnapshotTableStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropSnapshotTableStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropSnapshotTableStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropSnapshotTableStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropSnapshotTableStmt_name_path(arg0, arg1)
}

func ResolvedDropSnapshotTableStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropSnapshotTableStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropSnapshotTableStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropSnapshotTableStmt_set_name_path(arg0, arg1)
}

func ResolvedDropSnapshotTableStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropSnapshotTableStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropSnapshotTableStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropSnapshotTableStmt_add_name_path(arg0, arg1)
}

func ResolvedRecursiveScan_op_type(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedRecursiveScan_op_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedRecursiveScan_op_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedRecursiveScan_op_type(arg0, arg1)
}

func ResolvedRecursiveScan_set_op_type(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedRecursiveScan_set_op_type(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedRecursiveScan_set_op_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedRecursiveScan_set_op_type(arg0, arg1)
}

func ResolvedRecursiveScan_non_recursive_term(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedRecursiveScan_non_recursive_term(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRecursiveScan_non_recursive_term(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRecursiveScan_non_recursive_term(arg0, arg1)
}

func ResolvedRecursiveScan_set_non_recursive_term(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRecursiveScan_set_non_recursive_term(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRecursiveScan_set_non_recursive_term(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRecursiveScan_set_non_recursive_term(arg0, arg1)
}

func ResolvedRecursiveScan_recursive_term(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedRecursiveScan_recursive_term(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRecursiveScan_recursive_term(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRecursiveScan_recursive_term(arg0, arg1)
}

func ResolvedRecursiveScan_set_recursive_term(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRecursiveScan_set_recursive_term(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRecursiveScan_set_recursive_term(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRecursiveScan_set_recursive_term(arg0, arg1)
}

func ResolvedWithScan_with_entry_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedWithScan_with_entry_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWithScan_with_entry_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWithScan_with_entry_list(arg0, arg1)
}

func ResolvedWithScan_set_with_entry_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWithScan_set_with_entry_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWithScan_set_with_entry_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWithScan_set_with_entry_list(arg0, arg1)
}

func ResolvedWithScan_add_with_entry_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWithScan_add_with_entry_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWithScan_add_with_entry_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWithScan_add_with_entry_list(arg0, arg1)
}

func ResolvedWithScan_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedWithScan_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWithScan_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWithScan_query(arg0, arg1)
}

func ResolvedWithScan_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWithScan_set_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWithScan_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWithScan_set_query(arg0, arg1)
}

func ResolvedWithScan_recursive(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedWithScan_recursive(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedWithScan_recursive(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedWithScan_recursive(arg0, arg1)
}

func ResolvedWithScan_set_recursive(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedWithScan_set_recursive(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedWithScan_set_recursive(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedWithScan_set_recursive(arg0, arg1)
}

func ResolvedWithEntry_with_query_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedWithEntry_with_query_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWithEntry_with_query_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWithEntry_with_query_name(arg0, arg1)
}

func ResolvedWithEntry_set_with_query_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWithEntry_set_with_query_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWithEntry_set_with_query_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWithEntry_set_with_query_name(arg0, arg1)
}

func ResolvedWithEntry_with_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedWithEntry_with_subquery(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWithEntry_with_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWithEntry_with_subquery(arg0, arg1)
}

func ResolvedWithEntry_set_with_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWithEntry_set_with_subquery(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWithEntry_set_with_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWithEntry_set_with_subquery(arg0, arg1)
}

func ResolvedOption_qualifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedOption_qualifier(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOption_qualifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOption_qualifier(arg0, arg1)
}

func ResolvedOption_set_qualifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedOption_set_qualifier(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOption_set_qualifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOption_set_qualifier(arg0, arg1)
}

func ResolvedOption_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedOption_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOption_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOption_name(arg0, arg1)
}

func ResolvedOption_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedOption_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOption_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOption_set_name(arg0, arg1)
}

func ResolvedOption_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedOption_value(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOption_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOption_value(arg0, arg1)
}

func ResolvedOption_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedOption_set_value(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedOption_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedOption_set_value(arg0, arg1)
}

func ResolvedWindowPartitioning_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedWindowPartitioning_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowPartitioning_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowPartitioning_partition_by_list(arg0, arg1)
}

func ResolvedWindowPartitioning_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWindowPartitioning_set_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowPartitioning_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowPartitioning_set_partition_by_list(arg0, arg1)
}

func ResolvedWindowPartitioning_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWindowPartitioning_add_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowPartitioning_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowPartitioning_add_partition_by_list(arg0, arg1)
}

func ResolvedWindowPartitioning_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedWindowPartitioning_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowPartitioning_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowPartitioning_hint_list(arg0, arg1)
}

func ResolvedWindowPartitioning_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWindowPartitioning_set_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowPartitioning_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowPartitioning_set_hint_list(arg0, arg1)
}

func ResolvedWindowPartitioning_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWindowPartitioning_add_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowPartitioning_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowPartitioning_add_hint_list(arg0, arg1)
}

func ResolvedWindowOrdering_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedWindowOrdering_order_by_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowOrdering_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowOrdering_order_by_item_list(arg0, arg1)
}

func ResolvedWindowOrdering_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWindowOrdering_set_order_by_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowOrdering_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowOrdering_set_order_by_item_list(arg0, arg1)
}

func ResolvedWindowOrdering_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWindowOrdering_add_order_by_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowOrdering_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowOrdering_add_order_by_item_list(arg0, arg1)
}

func ResolvedWindowOrdering_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedWindowOrdering_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowOrdering_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowOrdering_hint_list(arg0, arg1)
}

func ResolvedWindowOrdering_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWindowOrdering_set_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowOrdering_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowOrdering_set_hint_list(arg0, arg1)
}

func ResolvedWindowOrdering_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWindowOrdering_add_hint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowOrdering_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowOrdering_add_hint_list(arg0, arg1)
}

func ResolvedWindowFrame_frame_unit(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedWindowFrame_frame_unit(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedWindowFrame_frame_unit(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedWindowFrame_frame_unit(arg0, arg1)
}

func ResolvedWindowFrame_set_frame_unit(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedWindowFrame_set_frame_unit(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedWindowFrame_set_frame_unit(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedWindowFrame_set_frame_unit(arg0, arg1)
}

func ResolvedWindowFrame_start_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedWindowFrame_start_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowFrame_start_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowFrame_start_expr(arg0, arg1)
}

func ResolvedWindowFrame_set_start_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWindowFrame_set_start_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowFrame_set_start_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowFrame_set_start_expr(arg0, arg1)
}

func ResolvedWindowFrame_end_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedWindowFrame_end_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowFrame_end_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowFrame_end_expr(arg0, arg1)
}

func ResolvedWindowFrame_set_end_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWindowFrame_set_end_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowFrame_set_end_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowFrame_set_end_expr(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAnalyticFunctionGroup_partition_by(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyticFunctionGroup_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyticFunctionGroup_partition_by(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_set_partition_by(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAnalyticFunctionGroup_set_partition_by(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyticFunctionGroup_set_partition_by(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyticFunctionGroup_set_partition_by(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAnalyticFunctionGroup_order_by(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyticFunctionGroup_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyticFunctionGroup_order_by(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_set_order_by(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAnalyticFunctionGroup_set_order_by(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyticFunctionGroup_set_order_by(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyticFunctionGroup_set_order_by(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_analytic_function_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAnalyticFunctionGroup_analytic_function_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyticFunctionGroup_analytic_function_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyticFunctionGroup_analytic_function_list(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_set_analytic_function_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAnalyticFunctionGroup_set_analytic_function_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyticFunctionGroup_set_analytic_function_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyticFunctionGroup_set_analytic_function_list(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_add_analytic_function_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAnalyticFunctionGroup_add_analytic_function_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyticFunctionGroup_add_analytic_function_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyticFunctionGroup_add_analytic_function_list(arg0, arg1)
}

func ResolvedWindowFrameExpr_boundary_type(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedWindowFrameExpr_boundary_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedWindowFrameExpr_boundary_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedWindowFrameExpr_boundary_type(arg0, arg1)
}

func ResolvedWindowFrameExpr_set_boundary_type(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedWindowFrameExpr_set_boundary_type(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedWindowFrameExpr_set_boundary_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedWindowFrameExpr_set_boundary_type(arg0, arg1)
}

func ResolvedWindowFrameExpr_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedWindowFrameExpr_expression(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowFrameExpr_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowFrameExpr_expression(arg0, arg1)
}

func ResolvedWindowFrameExpr_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedWindowFrameExpr_set_expression(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedWindowFrameExpr_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedWindowFrameExpr_set_expression(arg0, arg1)
}

func ResolvedDMLValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDMLValue_value(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDMLValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDMLValue_value(arg0, arg1)
}

func ResolvedDMLValue_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDMLValue_set_value(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDMLValue_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDMLValue_set_value(arg0, arg1)
}

func ResolvedAssertStmt_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAssertStmt_expression(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAssertStmt_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAssertStmt_expression(arg0, arg1)
}

func ResolvedAssertStmt_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAssertStmt_set_expression(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAssertStmt_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAssertStmt_set_expression(arg0, arg1)
}

func ResolvedAssertStmt_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAssertStmt_description(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAssertStmt_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAssertStmt_description(arg0, arg1)
}

func ResolvedAssertStmt_set_description(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAssertStmt_set_description(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAssertStmt_set_description(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAssertStmt_set_description(arg0, arg1)
}

func ResolvedAssertRowsModified_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAssertRowsModified_rows(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAssertRowsModified_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAssertRowsModified_rows(arg0, arg1)
}

func ResolvedAssertRowsModified_set_rows(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAssertRowsModified_set_rows(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAssertRowsModified_set_rows(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAssertRowsModified_set_rows(arg0, arg1)
}

func ResolvedInsertRow_value_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedInsertRow_value_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertRow_value_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertRow_value_list(arg0, arg1)
}

func ResolvedInsertRow_set_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInsertRow_set_value_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertRow_set_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertRow_set_value_list(arg0, arg1)
}

func ResolvedInsertRow_add_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInsertRow_add_value_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertRow_add_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertRow_add_value_list(arg0, arg1)
}

func ResolvedInsertStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_table_scan(arg0, arg1)
}

func ResolvedInsertStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_set_table_scan(arg0, arg1)
}

func ResolvedInsertStmt_insert_mode(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedInsertStmt_insert_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedInsertStmt_insert_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_insert_mode(arg0, arg1)
}

func ResolvedInsertStmt_set_insert_mode(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedInsertStmt_set_insert_mode(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedInsertStmt_set_insert_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_set_insert_mode(arg0, arg1)
}

func ResolvedInsertStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_assert_rows_modified(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_assert_rows_modified(arg0, arg1)
}

func ResolvedInsertStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_set_assert_rows_modified(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_set_assert_rows_modified(arg0, arg1)
}

func ResolvedInsertStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_returning(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_returning(arg0, arg1)
}

func ResolvedInsertStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_set_returning(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_set_returning(arg0, arg1)
}

func ResolvedInsertStmt_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_insert_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_insert_column_list(arg0, arg1)
}

func ResolvedInsertStmt_set_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_set_insert_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_set_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_set_insert_column_list(arg0, arg1)
}

func ResolvedInsertStmt_add_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_add_insert_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_add_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_add_insert_column_list(arg0, arg1)
}

func ResolvedInsertStmt_query_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_query_parameter_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_query_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_query_parameter_list(arg0, arg1)
}

func ResolvedInsertStmt_set_query_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_set_query_parameter_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_set_query_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_set_query_parameter_list(arg0, arg1)
}

func ResolvedInsertStmt_add_query_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_add_query_parameter_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_add_query_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_add_query_parameter_list(arg0, arg1)
}

func ResolvedInsertStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_query(arg0, arg1)
}

func ResolvedInsertStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_set_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_set_query(arg0, arg1)
}

func ResolvedInsertStmt_query_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_query_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_query_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_query_output_column_list(arg0, arg1)
}

func ResolvedInsertStmt_set_query_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_set_query_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_set_query_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_set_query_output_column_list(arg0, arg1)
}

func ResolvedInsertStmt_add_query_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_add_query_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_add_query_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_add_query_output_column_list(arg0, arg1)
}

func ResolvedInsertStmt_row_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_row_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_row_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_row_list(arg0, arg1)
}

func ResolvedInsertStmt_set_row_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_set_row_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_set_row_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_set_row_list(arg0, arg1)
}

func ResolvedInsertStmt_add_row_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedInsertStmt_add_row_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedInsertStmt_add_row_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedInsertStmt_add_row_list(arg0, arg1)
}

func ResolvedDeleteStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDeleteStmt_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDeleteStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDeleteStmt_table_scan(arg0, arg1)
}

func ResolvedDeleteStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDeleteStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDeleteStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDeleteStmt_set_table_scan(arg0, arg1)
}

func ResolvedDeleteStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDeleteStmt_assert_rows_modified(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDeleteStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDeleteStmt_assert_rows_modified(arg0, arg1)
}

func ResolvedDeleteStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDeleteStmt_set_assert_rows_modified(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDeleteStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDeleteStmt_set_assert_rows_modified(arg0, arg1)
}

func ResolvedDeleteStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDeleteStmt_returning(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDeleteStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDeleteStmt_returning(arg0, arg1)
}

func ResolvedDeleteStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDeleteStmt_set_returning(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDeleteStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDeleteStmt_set_returning(arg0, arg1)
}

func ResolvedDeleteStmt_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDeleteStmt_array_offset_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDeleteStmt_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDeleteStmt_array_offset_column(arg0, arg1)
}

func ResolvedDeleteStmt_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDeleteStmt_set_array_offset_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDeleteStmt_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDeleteStmt_set_array_offset_column(arg0, arg1)
}

func ResolvedDeleteStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDeleteStmt_where_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDeleteStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDeleteStmt_where_expr(arg0, arg1)
}

func ResolvedDeleteStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDeleteStmt_set_where_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDeleteStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDeleteStmt_set_where_expr(arg0, arg1)
}

func ResolvedUpdateItem_target(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_target(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_target(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_target(arg0, arg1)
}

func ResolvedUpdateItem_set_target(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_set_target(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_set_target(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_set_target(arg0, arg1)
}

func ResolvedUpdateItem_set_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_set_value(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_set_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_set_value(arg0, arg1)
}

func ResolvedUpdateItem_set_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_set_set_value(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_set_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_set_set_value(arg0, arg1)
}

func ResolvedUpdateItem_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_element_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_element_column(arg0, arg1)
}

func ResolvedUpdateItem_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_set_element_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_set_element_column(arg0, arg1)
}

func ResolvedUpdateItem_array_update_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_array_update_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_array_update_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_array_update_list(arg0, arg1)
}

func ResolvedUpdateItem_set_array_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_set_array_update_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_set_array_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_set_array_update_list(arg0, arg1)
}

func ResolvedUpdateItem_add_array_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_add_array_update_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_add_array_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_add_array_update_list(arg0, arg1)
}

func ResolvedUpdateItem_delete_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_delete_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_delete_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_delete_list(arg0, arg1)
}

func ResolvedUpdateItem_set_delete_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_set_delete_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_set_delete_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_set_delete_list(arg0, arg1)
}

func ResolvedUpdateItem_add_delete_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_add_delete_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_add_delete_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_add_delete_list(arg0, arg1)
}

func ResolvedUpdateItem_update_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_update_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_update_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_update_list(arg0, arg1)
}

func ResolvedUpdateItem_set_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_set_update_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_set_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_set_update_list(arg0, arg1)
}

func ResolvedUpdateItem_add_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_add_update_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_add_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_add_update_list(arg0, arg1)
}

func ResolvedUpdateItem_insert_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_insert_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_insert_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_insert_list(arg0, arg1)
}

func ResolvedUpdateItem_set_insert_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_set_insert_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_set_insert_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_set_insert_list(arg0, arg1)
}

func ResolvedUpdateItem_add_insert_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateItem_add_insert_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateItem_add_insert_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateItem_add_insert_list(arg0, arg1)
}

func ResolvedUpdateArrayItem_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateArrayItem_offset(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateArrayItem_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateArrayItem_offset(arg0, arg1)
}

func ResolvedUpdateArrayItem_set_offset(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateArrayItem_set_offset(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateArrayItem_set_offset(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateArrayItem_set_offset(arg0, arg1)
}

func ResolvedUpdateArrayItem_update_item(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateArrayItem_update_item(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateArrayItem_update_item(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateArrayItem_update_item(arg0, arg1)
}

func ResolvedUpdateArrayItem_set_update_item(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateArrayItem_set_update_item(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateArrayItem_set_update_item(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateArrayItem_set_update_item(arg0, arg1)
}

func ResolvedUpdateStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_table_scan(arg0, arg1)
}

func ResolvedUpdateStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_set_table_scan(arg0, arg1)
}

func ResolvedUpdateStmt_column_access_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_column_access_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_column_access_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_column_access_list(arg0, arg1)
}

func ResolvedUpdateStmt_set_column_access_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_set_column_access_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_set_column_access_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_set_column_access_list(arg0, arg1)
}

func ResolvedUpdateStmt_add_column_access_list(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedUpdateStmt_add_column_access_list(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedUpdateStmt_add_column_access_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_add_column_access_list(arg0, arg1)
}

func ResolvedUpdateStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_assert_rows_modified(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_assert_rows_modified(arg0, arg1)
}

func ResolvedUpdateStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_set_assert_rows_modified(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_set_assert_rows_modified(arg0, arg1)
}

func ResolvedUpdateStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_returning(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_returning(arg0, arg1)
}

func ResolvedUpdateStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_set_returning(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_set_returning(arg0, arg1)
}

func ResolvedUpdateStmt_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_array_offset_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_array_offset_column(arg0, arg1)
}

func ResolvedUpdateStmt_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_set_array_offset_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_set_array_offset_column(arg0, arg1)
}

func ResolvedUpdateStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_where_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_where_expr(arg0, arg1)
}

func ResolvedUpdateStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_set_where_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_set_where_expr(arg0, arg1)
}

func ResolvedUpdateStmt_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_update_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_update_item_list(arg0, arg1)
}

func ResolvedUpdateStmt_set_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_set_update_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_set_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_set_update_item_list(arg0, arg1)
}

func ResolvedUpdateStmt_add_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_add_update_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_add_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_add_update_item_list(arg0, arg1)
}

func ResolvedUpdateStmt_from_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_from_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_from_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_from_scan(arg0, arg1)
}

func ResolvedUpdateStmt_set_from_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUpdateStmt_set_from_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUpdateStmt_set_from_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUpdateStmt_set_from_scan(arg0, arg1)
}

func ResolvedMergeWhen_match_type(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedMergeWhen_match_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedMergeWhen_match_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedMergeWhen_match_type(arg0, arg1)
}

func ResolvedMergeWhen_set_match_type(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedMergeWhen_set_match_type(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedMergeWhen_set_match_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedMergeWhen_set_match_type(arg0, arg1)
}

func ResolvedMergeWhen_match_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedMergeWhen_match_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeWhen_match_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeWhen_match_expr(arg0, arg1)
}

func ResolvedMergeWhen_set_match_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMergeWhen_set_match_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeWhen_set_match_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeWhen_set_match_expr(arg0, arg1)
}

func ResolvedMergeWhen_action_type(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedMergeWhen_action_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedMergeWhen_action_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedMergeWhen_action_type(arg0, arg1)
}

func ResolvedMergeWhen_set_action_type(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedMergeWhen_set_action_type(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedMergeWhen_set_action_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedMergeWhen_set_action_type(arg0, arg1)
}

func ResolvedMergeWhen_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedMergeWhen_insert_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeWhen_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeWhen_insert_column_list(arg0, arg1)
}

func ResolvedMergeWhen_set_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMergeWhen_set_insert_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeWhen_set_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeWhen_set_insert_column_list(arg0, arg1)
}

func ResolvedMergeWhen_add_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMergeWhen_add_insert_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeWhen_add_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeWhen_add_insert_column_list(arg0, arg1)
}

func ResolvedMergeWhen_insert_row(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedMergeWhen_insert_row(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeWhen_insert_row(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeWhen_insert_row(arg0, arg1)
}

func ResolvedMergeWhen_set_insert_row(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMergeWhen_set_insert_row(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeWhen_set_insert_row(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeWhen_set_insert_row(arg0, arg1)
}

func ResolvedMergeWhen_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedMergeWhen_update_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeWhen_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeWhen_update_item_list(arg0, arg1)
}

func ResolvedMergeWhen_set_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMergeWhen_set_update_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeWhen_set_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeWhen_set_update_item_list(arg0, arg1)
}

func ResolvedMergeWhen_add_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMergeWhen_add_update_item_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeWhen_add_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeWhen_add_update_item_list(arg0, arg1)
}

func ResolvedMergeStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedMergeStmt_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeStmt_table_scan(arg0, arg1)
}

func ResolvedMergeStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMergeStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeStmt_set_table_scan(arg0, arg1)
}

func ResolvedMergeStmt_column_access_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedMergeStmt_column_access_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeStmt_column_access_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeStmt_column_access_list(arg0, arg1)
}

func ResolvedMergeStmt_set_column_access_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMergeStmt_set_column_access_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeStmt_set_column_access_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeStmt_set_column_access_list(arg0, arg1)
}

func ResolvedMergeStmt_add_column_access_list(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedMergeStmt_add_column_access_list(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedMergeStmt_add_column_access_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedMergeStmt_add_column_access_list(arg0, arg1)
}

func ResolvedMergeStmt_from_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedMergeStmt_from_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeStmt_from_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeStmt_from_scan(arg0, arg1)
}

func ResolvedMergeStmt_set_from_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMergeStmt_set_from_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeStmt_set_from_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeStmt_set_from_scan(arg0, arg1)
}

func ResolvedMergeStmt_merge_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedMergeStmt_merge_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeStmt_merge_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeStmt_merge_expr(arg0, arg1)
}

func ResolvedMergeStmt_set_merge_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMergeStmt_set_merge_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeStmt_set_merge_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeStmt_set_merge_expr(arg0, arg1)
}

func ResolvedMergeStmt_when_clause_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedMergeStmt_when_clause_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeStmt_when_clause_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeStmt_when_clause_list(arg0, arg1)
}

func ResolvedMergeStmt_set_when_clause_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMergeStmt_set_when_clause_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeStmt_set_when_clause_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeStmt_set_when_clause_list(arg0, arg1)
}

func ResolvedMergeStmt_add_when_clause_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedMergeStmt_add_when_clause_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedMergeStmt_add_when_clause_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedMergeStmt_add_when_clause_list(arg0, arg1)
}

func ResolvedTruncateStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedTruncateStmt_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTruncateStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTruncateStmt_table_scan(arg0, arg1)
}

func ResolvedTruncateStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedTruncateStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTruncateStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTruncateStmt_set_table_scan(arg0, arg1)
}

func ResolvedTruncateStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedTruncateStmt_where_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTruncateStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTruncateStmt_where_expr(arg0, arg1)
}

func ResolvedTruncateStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedTruncateStmt_set_where_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTruncateStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTruncateStmt_set_where_expr(arg0, arg1)
}

func ResolvedObjectUnit_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedObjectUnit_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedObjectUnit_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedObjectUnit_name_path(arg0, arg1)
}

func ResolvedObjectUnit_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedObjectUnit_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedObjectUnit_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedObjectUnit_set_name_path(arg0, arg1)
}

func ResolvedObjectUnit_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedObjectUnit_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedObjectUnit_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedObjectUnit_add_name_path(arg0, arg1)
}

func ResolvedPrivilege_action_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedPrivilege_action_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPrivilege_action_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPrivilege_action_type(arg0, arg1)
}

func ResolvedPrivilege_set_action_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPrivilege_set_action_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPrivilege_set_action_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPrivilege_set_action_type(arg0, arg1)
}

func ResolvedPrivilege_unit_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedPrivilege_unit_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPrivilege_unit_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPrivilege_unit_list(arg0, arg1)
}

func ResolvedPrivilege_set_unit_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPrivilege_set_unit_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPrivilege_set_unit_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPrivilege_set_unit_list(arg0, arg1)
}

func ResolvedPrivilege_add_unit_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPrivilege_add_unit_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPrivilege_add_unit_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPrivilege_add_unit_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedGrantOrRevokeStmt_privilege_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantOrRevokeStmt_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantOrRevokeStmt_privilege_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_set_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGrantOrRevokeStmt_set_privilege_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantOrRevokeStmt_set_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantOrRevokeStmt_set_privilege_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_add_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGrantOrRevokeStmt_add_privilege_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantOrRevokeStmt_add_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantOrRevokeStmt_add_privilege_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedGrantOrRevokeStmt_object_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantOrRevokeStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantOrRevokeStmt_object_type(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGrantOrRevokeStmt_set_object_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantOrRevokeStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantOrRevokeStmt_set_object_type(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedGrantOrRevokeStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantOrRevokeStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantOrRevokeStmt_name_path(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGrantOrRevokeStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantOrRevokeStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantOrRevokeStmt_set_name_path(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGrantOrRevokeStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantOrRevokeStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantOrRevokeStmt_add_name_path(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedGrantOrRevokeStmt_grantee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantOrRevokeStmt_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantOrRevokeStmt_grantee_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_set_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGrantOrRevokeStmt_set_grantee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantOrRevokeStmt_set_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantOrRevokeStmt_set_grantee_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_add_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGrantOrRevokeStmt_add_grantee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantOrRevokeStmt_add_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantOrRevokeStmt_add_grantee_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedGrantOrRevokeStmt_grantee_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantOrRevokeStmt_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantOrRevokeStmt_grantee_expr_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGrantOrRevokeStmt_set_grantee_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantOrRevokeStmt_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantOrRevokeStmt_set_grantee_expr_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGrantOrRevokeStmt_add_grantee_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantOrRevokeStmt_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantOrRevokeStmt_add_grantee_expr_list(arg0, arg1)
}

func ResolvedAlterObjectStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterObjectStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterObjectStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterObjectStmt_name_path(arg0, arg1)
}

func ResolvedAlterObjectStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterObjectStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterObjectStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterObjectStmt_set_name_path(arg0, arg1)
}

func ResolvedAlterObjectStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterObjectStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterObjectStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterObjectStmt_add_name_path(arg0, arg1)
}

func ResolvedAlterObjectStmt_alter_action_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterObjectStmt_alter_action_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterObjectStmt_alter_action_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterObjectStmt_alter_action_list(arg0, arg1)
}

func ResolvedAlterObjectStmt_set_alter_action_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterObjectStmt_set_alter_action_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterObjectStmt_set_alter_action_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterObjectStmt_set_alter_action_list(arg0, arg1)
}

func ResolvedAlterObjectStmt_add_alter_action_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterObjectStmt_add_alter_action_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterObjectStmt_add_alter_action_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterObjectStmt_add_alter_action_list(arg0, arg1)
}

func ResolvedAlterObjectStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedAlterObjectStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedAlterObjectStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedAlterObjectStmt_is_if_exists(arg0, arg1)
}

func ResolvedAlterObjectStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedAlterObjectStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedAlterObjectStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedAlterObjectStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedAlterColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedAlterColumnAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedAlterColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedAlterColumnAction_is_if_exists(arg0, arg1)
}

func ResolvedAlterColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedAlterColumnAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedAlterColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedAlterColumnAction_set_is_if_exists(arg0, arg1)
}

func ResolvedAlterColumnAction_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterColumnAction_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterColumnAction_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterColumnAction_column(arg0, arg1)
}

func ResolvedAlterColumnAction_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterColumnAction_set_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterColumnAction_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterColumnAction_set_column(arg0, arg1)
}

func ResolvedSetOptionsAction_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSetOptionsAction_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetOptionsAction_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetOptionsAction_option_list(arg0, arg1)
}

func ResolvedSetOptionsAction_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSetOptionsAction_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetOptionsAction_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetOptionsAction_set_option_list(arg0, arg1)
}

func ResolvedSetOptionsAction_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSetOptionsAction_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetOptionsAction_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetOptionsAction_add_option_list(arg0, arg1)
}

func ResolvedAddColumnAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedAddColumnAction_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedAddColumnAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedAddColumnAction_is_if_not_exists(arg0, arg1)
}

func ResolvedAddColumnAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedAddColumnAction_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedAddColumnAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedAddColumnAction_set_is_if_not_exists(arg0, arg1)
}

func ResolvedAddColumnAction_column_definition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAddColumnAction_column_definition(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAddColumnAction_column_definition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAddColumnAction_column_definition(arg0, arg1)
}

func ResolvedAddColumnAction_set_column_definition(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAddColumnAction_set_column_definition(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAddColumnAction_set_column_definition(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAddColumnAction_set_column_definition(arg0, arg1)
}

func ResolvedAddConstraintAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedAddConstraintAction_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedAddConstraintAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedAddConstraintAction_is_if_not_exists(arg0, arg1)
}

func ResolvedAddConstraintAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedAddConstraintAction_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedAddConstraintAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedAddConstraintAction_set_is_if_not_exists(arg0, arg1)
}

func ResolvedAddConstraintAction_constraint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAddConstraintAction_constraint(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAddConstraintAction_constraint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAddConstraintAction_constraint(arg0, arg1)
}

func ResolvedAddConstraintAction_set_constraint(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAddConstraintAction_set_constraint(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAddConstraintAction_set_constraint(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAddConstraintAction_set_constraint(arg0, arg1)
}

func ResolvedAddConstraintAction_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAddConstraintAction_table(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAddConstraintAction_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAddConstraintAction_table(arg0, arg1)
}

func ResolvedAddConstraintAction_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAddConstraintAction_set_table(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAddConstraintAction_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAddConstraintAction_set_table(arg0, arg1)
}

func ResolvedDropConstraintAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedDropConstraintAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedDropConstraintAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedDropConstraintAction_is_if_exists(arg0, arg1)
}

func ResolvedDropConstraintAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedDropConstraintAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedDropConstraintAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedDropConstraintAction_set_is_if_exists(arg0, arg1)
}

func ResolvedDropConstraintAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropConstraintAction_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropConstraintAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropConstraintAction_name(arg0, arg1)
}

func ResolvedDropConstraintAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropConstraintAction_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropConstraintAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropConstraintAction_set_name(arg0, arg1)
}

func ResolvedDropPrimaryKeyAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedDropPrimaryKeyAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedDropPrimaryKeyAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedDropPrimaryKeyAction_is_if_exists(arg0, arg1)
}

func ResolvedDropPrimaryKeyAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedDropPrimaryKeyAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedDropPrimaryKeyAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedDropPrimaryKeyAction_set_is_if_exists(arg0, arg1)
}

func ResolvedAlterColumnOptionsAction_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterColumnOptionsAction_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterColumnOptionsAction_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterColumnOptionsAction_option_list(arg0, arg1)
}

func ResolvedAlterColumnOptionsAction_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterColumnOptionsAction_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterColumnOptionsAction_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterColumnOptionsAction_set_option_list(arg0, arg1)
}

func ResolvedAlterColumnOptionsAction_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterColumnOptionsAction_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterColumnOptionsAction_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterColumnOptionsAction_add_option_list(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_updated_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterColumnSetDataTypeAction_updated_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterColumnSetDataTypeAction_updated_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterColumnSetDataTypeAction_updated_type(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_set_updated_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterColumnSetDataTypeAction_set_updated_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterColumnSetDataTypeAction_set_updated_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterColumnSetDataTypeAction_set_updated_type(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_updated_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterColumnSetDataTypeAction_updated_type_parameters(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterColumnSetDataTypeAction_updated_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterColumnSetDataTypeAction_updated_type_parameters(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_updated_annotations(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterColumnSetDataTypeAction_updated_annotations(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterColumnSetDataTypeAction_updated_annotations(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterColumnSetDataTypeAction_updated_annotations(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_set_updated_annotations(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterColumnSetDataTypeAction_set_updated_annotations(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterColumnSetDataTypeAction_set_updated_annotations(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterColumnSetDataTypeAction_set_updated_annotations(arg0, arg1)
}

func ResolvedAlterColumnSetDefaultAction_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterColumnSetDefaultAction_default_value(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterColumnSetDefaultAction_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterColumnSetDefaultAction_default_value(arg0, arg1)
}

func ResolvedAlterColumnSetDefaultAction_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterColumnSetDefaultAction_set_default_value(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterColumnSetDefaultAction_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterColumnSetDefaultAction_set_default_value(arg0, arg1)
}

func ResolvedDropColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedDropColumnAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedDropColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedDropColumnAction_is_if_exists(arg0, arg1)
}

func ResolvedDropColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedDropColumnAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedDropColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedDropColumnAction_set_is_if_exists(arg0, arg1)
}

func ResolvedDropColumnAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropColumnAction_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropColumnAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropColumnAction_name(arg0, arg1)
}

func ResolvedDropColumnAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropColumnAction_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropColumnAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropColumnAction_set_name(arg0, arg1)
}

func ResolvedRenameColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedRenameColumnAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedRenameColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedRenameColumnAction_is_if_exists(arg0, arg1)
}

func ResolvedRenameColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedRenameColumnAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedRenameColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedRenameColumnAction_set_is_if_exists(arg0, arg1)
}

func ResolvedRenameColumnAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedRenameColumnAction_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRenameColumnAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRenameColumnAction_name(arg0, arg1)
}

func ResolvedRenameColumnAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRenameColumnAction_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRenameColumnAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRenameColumnAction_set_name(arg0, arg1)
}

func ResolvedRenameColumnAction_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedRenameColumnAction_new_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRenameColumnAction_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRenameColumnAction_new_name(arg0, arg1)
}

func ResolvedRenameColumnAction_set_new_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRenameColumnAction_set_new_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRenameColumnAction_set_new_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRenameColumnAction_set_new_name(arg0, arg1)
}

func ResolvedSetAsAction_entity_body_json(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSetAsAction_entity_body_json(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetAsAction_entity_body_json(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetAsAction_entity_body_json(arg0, arg1)
}

func ResolvedSetAsAction_set_entity_body_json(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSetAsAction_set_entity_body_json(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetAsAction_set_entity_body_json(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetAsAction_set_entity_body_json(arg0, arg1)
}

func ResolvedSetAsAction_entity_body_text(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSetAsAction_entity_body_text(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetAsAction_entity_body_text(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetAsAction_entity_body_text(arg0, arg1)
}

func ResolvedSetAsAction_set_entity_body_text(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSetAsAction_set_entity_body_text(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetAsAction_set_entity_body_text(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetAsAction_set_entity_body_text(arg0, arg1)
}

func ResolvedSetCollateClause_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedSetCollateClause_collation_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetCollateClause_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetCollateClause_collation_name(arg0, arg1)
}

func ResolvedSetCollateClause_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedSetCollateClause_set_collation_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedSetCollateClause_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedSetCollateClause_set_collation_name(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterTableSetOptionsStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterTableSetOptionsStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterTableSetOptionsStmt_name_path(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterTableSetOptionsStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterTableSetOptionsStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterTableSetOptionsStmt_set_name_path(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterTableSetOptionsStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterTableSetOptionsStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterTableSetOptionsStmt_add_name_path(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterTableSetOptionsStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterTableSetOptionsStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterTableSetOptionsStmt_option_list(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterTableSetOptionsStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterTableSetOptionsStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterTableSetOptionsStmt_set_option_list(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterTableSetOptionsStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterTableSetOptionsStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterTableSetOptionsStmt_add_option_list(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedAlterTableSetOptionsStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedAlterTableSetOptionsStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedAlterTableSetOptionsStmt_is_if_exists(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedAlterTableSetOptionsStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedAlterTableSetOptionsStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedAlterTableSetOptionsStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedRenameStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedRenameStmt_object_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRenameStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRenameStmt_object_type(arg0, arg1)
}

func ResolvedRenameStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRenameStmt_set_object_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRenameStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRenameStmt_set_object_type(arg0, arg1)
}

func ResolvedRenameStmt_old_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedRenameStmt_old_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRenameStmt_old_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRenameStmt_old_name_path(arg0, arg1)
}

func ResolvedRenameStmt_set_old_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRenameStmt_set_old_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRenameStmt_set_old_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRenameStmt_set_old_name_path(arg0, arg1)
}

func ResolvedRenameStmt_add_old_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRenameStmt_add_old_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRenameStmt_add_old_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRenameStmt_add_old_name_path(arg0, arg1)
}

func ResolvedRenameStmt_new_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedRenameStmt_new_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRenameStmt_new_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRenameStmt_new_name_path(arg0, arg1)
}

func ResolvedRenameStmt_set_new_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRenameStmt_set_new_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRenameStmt_set_new_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRenameStmt_set_new_name_path(arg0, arg1)
}

func ResolvedRenameStmt_add_new_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRenameStmt_add_new_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRenameStmt_add_new_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRenameStmt_add_new_name_path(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreatePrivilegeRestrictionStmt_object_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreatePrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreatePrivilegeRestrictionStmt_object_type(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreatePrivilegeRestrictionStmt_set_object_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreatePrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreatePrivilegeRestrictionStmt_set_object_type(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreatePrivilegeRestrictionStmt_restrictee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreatePrivilegeRestrictionStmt_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreatePrivilegeRestrictionStmt_restrictee_list(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_create_mode(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_create_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_create_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_create_mode(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_create_mode(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_set_create_mode(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_set_create_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_set_create_mode(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_name(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_set_name(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_target_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_target_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_target_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_target_name_path(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_set_target_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_set_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_set_target_name_path(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_add_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_add_target_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_add_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_add_target_name_path(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_grantee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_grantee_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_set_grantee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_set_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_set_grantee_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_add_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_add_grantee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_add_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_add_grantee_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_grantee_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_grantee_expr_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_table_scan(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_set_table_scan(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_predicate(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_predicate(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_predicate(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_set_predicate(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_set_predicate(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_set_predicate(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_predicate_str(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_predicate_str(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_predicate_str(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_predicate_str(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_predicate_str(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateRowAccessPolicyStmt_set_predicate_str(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateRowAccessPolicyStmt_set_predicate_str(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateRowAccessPolicyStmt_set_predicate_str(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropPrivilegeRestrictionStmt_object_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropPrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropPrivilegeRestrictionStmt_object_type(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropPrivilegeRestrictionStmt_set_object_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropPrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropPrivilegeRestrictionStmt_set_object_type(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedDropPrivilegeRestrictionStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedDropPrivilegeRestrictionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedDropPrivilegeRestrictionStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropPrivilegeRestrictionStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropPrivilegeRestrictionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropPrivilegeRestrictionStmt_name_path(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropPrivilegeRestrictionStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropPrivilegeRestrictionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropPrivilegeRestrictionStmt_set_name_path(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropPrivilegeRestrictionStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropPrivilegeRestrictionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropPrivilegeRestrictionStmt_add_name_path(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropPrivilegeRestrictionStmt_column_privilege_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropPrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropPrivilegeRestrictionStmt_column_privilege_list(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_is_drop_all(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedDropRowAccessPolicyStmt_is_drop_all(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedDropRowAccessPolicyStmt_is_drop_all(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedDropRowAccessPolicyStmt_is_drop_all(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_set_is_drop_all(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedDropRowAccessPolicyStmt_set_is_drop_all(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedDropRowAccessPolicyStmt_set_is_drop_all(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedDropRowAccessPolicyStmt_set_is_drop_all(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedDropRowAccessPolicyStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedDropRowAccessPolicyStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedDropRowAccessPolicyStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedDropRowAccessPolicyStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedDropRowAccessPolicyStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedDropRowAccessPolicyStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropRowAccessPolicyStmt_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropRowAccessPolicyStmt_name(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropRowAccessPolicyStmt_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropRowAccessPolicyStmt_set_name(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_target_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropRowAccessPolicyStmt_target_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropRowAccessPolicyStmt_target_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropRowAccessPolicyStmt_target_name_path(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_set_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropRowAccessPolicyStmt_set_target_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropRowAccessPolicyStmt_set_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropRowAccessPolicyStmt_set_target_name_path(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_add_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropRowAccessPolicyStmt_add_target_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropRowAccessPolicyStmt_add_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropRowAccessPolicyStmt_add_target_name_path(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedDropSearchIndexStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedDropSearchIndexStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedDropSearchIndexStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedDropSearchIndexStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedDropSearchIndexStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedDropSearchIndexStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropSearchIndexStmt_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropSearchIndexStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropSearchIndexStmt_name(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropSearchIndexStmt_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropSearchIndexStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropSearchIndexStmt_set_name(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropSearchIndexStmt_table_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropSearchIndexStmt_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropSearchIndexStmt_table_name_path(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_set_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropSearchIndexStmt_set_table_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropSearchIndexStmt_set_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropSearchIndexStmt_set_table_name_path(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_add_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropSearchIndexStmt_add_table_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropSearchIndexStmt_add_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropSearchIndexStmt_add_table_name_path(arg0, arg1)
}

func ResolvedGrantToAction_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedGrantToAction_grantee_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantToAction_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantToAction_grantee_expr_list(arg0, arg1)
}

func ResolvedGrantToAction_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGrantToAction_set_grantee_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantToAction_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantToAction_set_grantee_expr_list(arg0, arg1)
}

func ResolvedGrantToAction_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedGrantToAction_add_grantee_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedGrantToAction_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedGrantToAction_add_grantee_expr_list(arg0, arg1)
}

func ResolvedRestrictToAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedRestrictToAction_restrictee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRestrictToAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRestrictToAction_restrictee_list(arg0, arg1)
}

func ResolvedRestrictToAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRestrictToAction_set_restrictee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRestrictToAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRestrictToAction_set_restrictee_list(arg0, arg1)
}

func ResolvedRestrictToAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRestrictToAction_add_restrictee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRestrictToAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRestrictToAction_add_restrictee_list(arg0, arg1)
}

func ResolvedAddToRestricteeListAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedAddToRestricteeListAction_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedAddToRestricteeListAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedAddToRestricteeListAction_is_if_not_exists(arg0, arg1)
}

func ResolvedAddToRestricteeListAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedAddToRestricteeListAction_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedAddToRestricteeListAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedAddToRestricteeListAction_set_is_if_not_exists(arg0, arg1)
}

func ResolvedAddToRestricteeListAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAddToRestricteeListAction_restrictee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAddToRestricteeListAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAddToRestricteeListAction_restrictee_list(arg0, arg1)
}

func ResolvedAddToRestricteeListAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAddToRestricteeListAction_set_restrictee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAddToRestricteeListAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAddToRestricteeListAction_set_restrictee_list(arg0, arg1)
}

func ResolvedAddToRestricteeListAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAddToRestricteeListAction_add_restrictee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAddToRestricteeListAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAddToRestricteeListAction_add_restrictee_list(arg0, arg1)
}

func ResolvedRemoveFromRestricteeListAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedRemoveFromRestricteeListAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedRemoveFromRestricteeListAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedRemoveFromRestricteeListAction_is_if_exists(arg0, arg1)
}

func ResolvedRemoveFromRestricteeListAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedRemoveFromRestricteeListAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedRemoveFromRestricteeListAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedRemoveFromRestricteeListAction_set_is_if_exists(arg0, arg1)
}

func ResolvedRemoveFromRestricteeListAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedRemoveFromRestricteeListAction_restrictee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRemoveFromRestricteeListAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRemoveFromRestricteeListAction_restrictee_list(arg0, arg1)
}

func ResolvedRemoveFromRestricteeListAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRemoveFromRestricteeListAction_set_restrictee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRemoveFromRestricteeListAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRemoveFromRestricteeListAction_set_restrictee_list(arg0, arg1)
}

func ResolvedRemoveFromRestricteeListAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRemoveFromRestricteeListAction_add_restrictee_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRemoveFromRestricteeListAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRemoveFromRestricteeListAction_add_restrictee_list(arg0, arg1)
}

func ResolvedFilterUsingAction_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFilterUsingAction_predicate(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFilterUsingAction_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFilterUsingAction_predicate(arg0, arg1)
}

func ResolvedFilterUsingAction_set_predicate(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFilterUsingAction_set_predicate(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFilterUsingAction_set_predicate(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFilterUsingAction_set_predicate(arg0, arg1)
}

func ResolvedFilterUsingAction_predicate_str(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFilterUsingAction_predicate_str(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFilterUsingAction_predicate_str(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFilterUsingAction_predicate_str(arg0, arg1)
}

func ResolvedFilterUsingAction_set_predicate_str(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFilterUsingAction_set_predicate_str(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFilterUsingAction_set_predicate_str(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFilterUsingAction_set_predicate_str(arg0, arg1)
}

func ResolvedRevokeFromAction_revokee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedRevokeFromAction_revokee_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRevokeFromAction_revokee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRevokeFromAction_revokee_expr_list(arg0, arg1)
}

func ResolvedRevokeFromAction_set_revokee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRevokeFromAction_set_revokee_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRevokeFromAction_set_revokee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRevokeFromAction_set_revokee_expr_list(arg0, arg1)
}

func ResolvedRevokeFromAction_add_revokee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRevokeFromAction_add_revokee_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRevokeFromAction_add_revokee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRevokeFromAction_add_revokee_expr_list(arg0, arg1)
}

func ResolvedRevokeFromAction_is_revoke_from_all(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedRevokeFromAction_is_revoke_from_all(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedRevokeFromAction_is_revoke_from_all(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedRevokeFromAction_is_revoke_from_all(arg0, arg1)
}

func ResolvedRevokeFromAction_set_is_revoke_from_all(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedRevokeFromAction_set_is_revoke_from_all(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedRevokeFromAction_set_is_revoke_from_all(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedRevokeFromAction_set_is_revoke_from_all(arg0, arg1)
}

func ResolvedRenameToAction_new_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedRenameToAction_new_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRenameToAction_new_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRenameToAction_new_path(arg0, arg1)
}

func ResolvedRenameToAction_set_new_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRenameToAction_set_new_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRenameToAction_set_new_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRenameToAction_set_new_path(arg0, arg1)
}

func ResolvedRenameToAction_add_new_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRenameToAction_add_new_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRenameToAction_add_new_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRenameToAction_add_new_path(arg0, arg1)
}

func ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list(arg0, arg1)
}

func ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list(arg0, arg1)
}

func ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list(arg0, arg1)
}

func ResolvedAlterPrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterPrivilegeRestrictionStmt_object_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterPrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterPrivilegeRestrictionStmt_object_type(arg0, arg1)
}

func ResolvedAlterPrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterPrivilegeRestrictionStmt_set_object_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterPrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterPrivilegeRestrictionStmt_set_object_type(arg0, arg1)
}

func ResolvedAlterRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterRowAccessPolicyStmt_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterRowAccessPolicyStmt_name(arg0, arg1)
}

func ResolvedAlterRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterRowAccessPolicyStmt_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterRowAccessPolicyStmt_set_name(arg0, arg1)
}

func ResolvedAlterRowAccessPolicyStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterRowAccessPolicyStmt_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterRowAccessPolicyStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterRowAccessPolicyStmt_table_scan(arg0, arg1)
}

func ResolvedAlterRowAccessPolicyStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterRowAccessPolicyStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterRowAccessPolicyStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterRowAccessPolicyStmt_set_table_scan(arg0, arg1)
}

func ResolvedAlterAllRowAccessPoliciesStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterAllRowAccessPoliciesStmt_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterAllRowAccessPoliciesStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterAllRowAccessPoliciesStmt_table_scan(arg0, arg1)
}

func ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan(arg0, arg1)
}

func ResolvedCreateConstantStmt_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateConstantStmt_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateConstantStmt_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateConstantStmt_expr(arg0, arg1)
}

func ResolvedCreateConstantStmt_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateConstantStmt_set_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateConstantStmt_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateConstantStmt_set_expr(arg0, arg1)
}

func ResolvedCreateFunctionStmt_has_explicit_return_type(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCreateFunctionStmt_has_explicit_return_type(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateFunctionStmt_has_explicit_return_type(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_has_explicit_return_type(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_has_explicit_return_type(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateFunctionStmt_set_has_explicit_return_type(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateFunctionStmt_set_has_explicit_return_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_set_has_explicit_return_type(arg0, arg1)
}

func ResolvedCreateFunctionStmt_return_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_return_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_return_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_return_type(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_return_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_set_return_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_set_return_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_set_return_type(arg0, arg1)
}

func ResolvedCreateFunctionStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_argument_name_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_argument_name_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_set_argument_name_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_set_argument_name_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_add_argument_name_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_add_argument_name_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_signature(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_set_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_set_signature(arg0, arg1)
}

func ResolvedCreateFunctionStmt_is_aggregate(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCreateFunctionStmt_is_aggregate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateFunctionStmt_is_aggregate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_is_aggregate(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_is_aggregate(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateFunctionStmt_set_is_aggregate(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateFunctionStmt_set_is_aggregate(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_set_is_aggregate(arg0, arg1)
}

func ResolvedCreateFunctionStmt_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_language(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_language(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_set_language(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_set_language(arg0, arg1)
}

func ResolvedCreateFunctionStmt_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_code(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_code(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_code(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_set_code(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_set_code(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_set_code(arg0, arg1)
}

func ResolvedCreateFunctionStmt_aggregate_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_aggregate_expression_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_aggregate_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_aggregate_expression_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_aggregate_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_set_aggregate_expression_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_set_aggregate_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_set_aggregate_expression_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_add_aggregate_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_add_aggregate_expression_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_add_aggregate_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_add_aggregate_expression_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_function_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_function_expression(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_function_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_function_expression(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_function_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_set_function_expression(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_set_function_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_set_function_expression(arg0, arg1)
}

func ResolvedCreateFunctionStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_option_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_sql_security(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedCreateFunctionStmt_sql_security(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateFunctionStmt_sql_security(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_sql_security(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_sql_security(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateFunctionStmt_set_sql_security(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateFunctionStmt_set_sql_security(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_set_sql_security(arg0, arg1)
}

func ResolvedCreateFunctionStmt_determinism_level(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedCreateFunctionStmt_determinism_level(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateFunctionStmt_determinism_level(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_determinism_level(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_determinism_level(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateFunctionStmt_set_determinism_level(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateFunctionStmt_set_determinism_level(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_set_determinism_level(arg0, arg1)
}

func ResolvedCreateFunctionStmt_is_remote(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCreateFunctionStmt_is_remote(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateFunctionStmt_is_remote(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_is_remote(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_is_remote(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateFunctionStmt_set_is_remote(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateFunctionStmt_set_is_remote(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_set_is_remote(arg0, arg1)
}

func ResolvedCreateFunctionStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_connection(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_connection(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateFunctionStmt_set_connection(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateFunctionStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateFunctionStmt_set_connection(arg0, arg1)
}

func ResolvedArgumentDef_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedArgumentDef_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArgumentDef_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArgumentDef_name(arg0, arg1)
}

func ResolvedArgumentDef_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedArgumentDef_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArgumentDef_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArgumentDef_set_name(arg0, arg1)
}

func ResolvedArgumentDef_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedArgumentDef_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArgumentDef_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArgumentDef_type(arg0, arg1)
}

func ResolvedArgumentDef_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedArgumentDef_set_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArgumentDef_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArgumentDef_set_type(arg0, arg1)
}

func ResolvedArgumentDef_argument_kind(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedArgumentDef_argument_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedArgumentDef_argument_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedArgumentDef_argument_kind(arg0, arg1)
}

func ResolvedArgumentDef_set_argument_kind(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedArgumentDef_set_argument_kind(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedArgumentDef_set_argument_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedArgumentDef_set_argument_kind(arg0, arg1)
}

func ResolvedArgumentRef_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedArgumentRef_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArgumentRef_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArgumentRef_name(arg0, arg1)
}

func ResolvedArgumentRef_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedArgumentRef_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArgumentRef_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArgumentRef_set_name(arg0, arg1)
}

func ResolvedArgumentRef_argument_kind(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedArgumentRef_argument_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedArgumentRef_argument_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedArgumentRef_argument_kind(arg0, arg1)
}

func ResolvedArgumentRef_set_argument_kind(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedArgumentRef_set_argument_kind(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedArgumentRef_set_argument_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedArgumentRef_set_argument_kind(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_new(arg0 unsafe.Pointer, arg1 int, arg2 int, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 int, arg6 unsafe.Pointer, arg7 unsafe.Pointer, arg8 unsafe.Pointer, arg9 unsafe.Pointer, arg10 unsafe.Pointer, arg11 int, arg12 int, arg13 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_new(
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

func analyzer_ResolvedCreateTableFunctionStmt_new(arg0 unsafe.Pointer, arg1 C.int, arg2 C.int, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 C.int, arg6 unsafe.Pointer, arg7 unsafe.Pointer, arg8 unsafe.Pointer, arg9 unsafe.Pointer, arg10 unsafe.Pointer, arg11 C.int, arg12 C.int, arg13 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_new(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13)
}

func ResolvedCreateTableFunctionStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_argument_name_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_argument_name_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_set_argument_name_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_set_argument_name_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_add_argument_name_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_add_argument_name_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_signature(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_set_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_set_signature(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_has_explicit_return_schema(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCreateTableFunctionStmt_has_explicit_return_schema(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_has_explicit_return_schema(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_has_explicit_return_schema(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_option_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_language(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_language(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_set_language(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_set_language(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_code(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_code(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_code(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_set_code(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_set_code(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_set_code(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_query(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_set_query(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_set_query(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_output_column_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_set_output_column_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateTableFunctionStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_add_output_column_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCreateTableFunctionStmt_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_is_value_table(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateTableFunctionStmt_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_set_is_value_table(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_sql_security(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedCreateTableFunctionStmt_sql_security(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_sql_security(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_sql_security(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_sql_security(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedCreateTableFunctionStmt_set_sql_security(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedCreateTableFunctionStmt_set_sql_security(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedCreateTableFunctionStmt_set_sql_security(arg0, arg1)
}

func ResolvedRelationArgumentScan_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedRelationArgumentScan_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRelationArgumentScan_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRelationArgumentScan_name(arg0, arg1)
}

func ResolvedRelationArgumentScan_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedRelationArgumentScan_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedRelationArgumentScan_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedRelationArgumentScan_set_name(arg0, arg1)
}

func ResolvedRelationArgumentScan_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedRelationArgumentScan_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedRelationArgumentScan_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedRelationArgumentScan_is_value_table(arg0, arg1)
}

func ResolvedRelationArgumentScan_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedRelationArgumentScan_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedRelationArgumentScan_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedRelationArgumentScan_set_is_value_table(arg0, arg1)
}

func ResolvedArgumentList_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedArgumentList_arg_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArgumentList_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArgumentList_arg_list(arg0, arg1)
}

func ResolvedArgumentList_set_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedArgumentList_set_arg_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArgumentList_set_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArgumentList_set_arg_list(arg0, arg1)
}

func ResolvedArgumentList_add_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedArgumentList_add_arg_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedArgumentList_add_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedArgumentList_add_arg_list(arg0, arg1)
}

func ResolvedFunctionSignatureHolder_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionSignatureHolder_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionSignatureHolder_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionSignatureHolder_signature(arg0, arg1)
}

func ResolvedFunctionSignatureHolder_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedFunctionSignatureHolder_set_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionSignatureHolder_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionSignatureHolder_set_signature(arg0, arg1)
}

func ResolvedDropFunctionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedDropFunctionStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedDropFunctionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedDropFunctionStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropFunctionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedDropFunctionStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedDropFunctionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedDropFunctionStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropFunctionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropFunctionStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropFunctionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropFunctionStmt_name_path(arg0, arg1)
}

func ResolvedDropFunctionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropFunctionStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropFunctionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropFunctionStmt_set_name_path(arg0, arg1)
}

func ResolvedDropFunctionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropFunctionStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropFunctionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropFunctionStmt_add_name_path(arg0, arg1)
}

func ResolvedDropFunctionStmt_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropFunctionStmt_arguments(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropFunctionStmt_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropFunctionStmt_arguments(arg0, arg1)
}

func ResolvedDropFunctionStmt_set_arguments(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropFunctionStmt_set_arguments(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropFunctionStmt_set_arguments(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropFunctionStmt_set_arguments(arg0, arg1)
}

func ResolvedDropFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropFunctionStmt_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropFunctionStmt_signature(arg0, arg1)
}

func ResolvedDropFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropFunctionStmt_set_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropFunctionStmt_set_signature(arg0, arg1)
}

func ResolvedDropTableFunctionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedDropTableFunctionStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedDropTableFunctionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedDropTableFunctionStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropTableFunctionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedDropTableFunctionStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedDropTableFunctionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedDropTableFunctionStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropTableFunctionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedDropTableFunctionStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropTableFunctionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropTableFunctionStmt_name_path(arg0, arg1)
}

func ResolvedDropTableFunctionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropTableFunctionStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropTableFunctionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropTableFunctionStmt_set_name_path(arg0, arg1)
}

func ResolvedDropTableFunctionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedDropTableFunctionStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedDropTableFunctionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedDropTableFunctionStmt_add_name_path(arg0, arg1)
}

func ResolvedCallStmt_procedure(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCallStmt_procedure(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCallStmt_procedure(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCallStmt_procedure(arg0, arg1)
}

func ResolvedCallStmt_set_procedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCallStmt_set_procedure(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCallStmt_set_procedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCallStmt_set_procedure(arg0, arg1)
}

func ResolvedCallStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCallStmt_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCallStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCallStmt_signature(arg0, arg1)
}

func ResolvedCallStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCallStmt_set_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCallStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCallStmt_set_signature(arg0, arg1)
}

func ResolvedCallStmt_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCallStmt_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCallStmt_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCallStmt_argument_list(arg0, arg1)
}

func ResolvedCallStmt_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCallStmt_set_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCallStmt_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCallStmt_set_argument_list(arg0, arg1)
}

func ResolvedCallStmt_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCallStmt_add_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCallStmt_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCallStmt_add_argument_list(arg0, arg1)
}

func ResolvedImportStmt_import_kind(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedImportStmt_import_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedImportStmt_import_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_import_kind(arg0, arg1)
}

func ResolvedImportStmt_set_import_kind(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedImportStmt_set_import_kind(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedImportStmt_set_import_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_set_import_kind(arg0, arg1)
}

func ResolvedImportStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedImportStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedImportStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_name_path(arg0, arg1)
}

func ResolvedImportStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedImportStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedImportStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_set_name_path(arg0, arg1)
}

func ResolvedImportStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedImportStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedImportStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_add_name_path(arg0, arg1)
}

func ResolvedImportStmt_file_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedImportStmt_file_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedImportStmt_file_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_file_path(arg0, arg1)
}

func ResolvedImportStmt_set_file_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedImportStmt_set_file_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedImportStmt_set_file_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_set_file_path(arg0, arg1)
}

func ResolvedImportStmt_alias_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedImportStmt_alias_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedImportStmt_alias_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_alias_path(arg0, arg1)
}

func ResolvedImportStmt_set_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedImportStmt_set_alias_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedImportStmt_set_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_set_alias_path(arg0, arg1)
}

func ResolvedImportStmt_add_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedImportStmt_add_alias_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedImportStmt_add_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_add_alias_path(arg0, arg1)
}

func ResolvedImportStmt_into_alias_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedImportStmt_into_alias_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedImportStmt_into_alias_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_into_alias_path(arg0, arg1)
}

func ResolvedImportStmt_set_into_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedImportStmt_set_into_alias_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedImportStmt_set_into_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_set_into_alias_path(arg0, arg1)
}

func ResolvedImportStmt_add_into_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedImportStmt_add_into_alias_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedImportStmt_add_into_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_add_into_alias_path(arg0, arg1)
}

func ResolvedImportStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedImportStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedImportStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_option_list(arg0, arg1)
}

func ResolvedImportStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedImportStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedImportStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_set_option_list(arg0, arg1)
}

func ResolvedImportStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedImportStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedImportStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedImportStmt_add_option_list(arg0, arg1)
}

func ResolvedModuleStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedModuleStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedModuleStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedModuleStmt_name_path(arg0, arg1)
}

func ResolvedModuleStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedModuleStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedModuleStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedModuleStmt_set_name_path(arg0, arg1)
}

func ResolvedModuleStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedModuleStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedModuleStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedModuleStmt_add_name_path(arg0, arg1)
}

func ResolvedModuleStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedModuleStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedModuleStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedModuleStmt_option_list(arg0, arg1)
}

func ResolvedModuleStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedModuleStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedModuleStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedModuleStmt_set_option_list(arg0, arg1)
}

func ResolvedModuleStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedModuleStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedModuleStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedModuleStmt_add_option_list(arg0, arg1)
}

func ResolvedAggregateHavingModifier_kind(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedAggregateHavingModifier_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedAggregateHavingModifier_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedAggregateHavingModifier_kind(arg0, arg1)
}

func ResolvedAggregateHavingModifier_set_kind(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedAggregateHavingModifier_set_kind(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedAggregateHavingModifier_set_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedAggregateHavingModifier_set_kind(arg0, arg1)
}

func ResolvedAggregateHavingModifier_having_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAggregateHavingModifier_having_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateHavingModifier_having_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateHavingModifier_having_expr(arg0, arg1)
}

func ResolvedAggregateHavingModifier_set_having_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAggregateHavingModifier_set_having_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAggregateHavingModifier_set_having_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAggregateHavingModifier_set_having_expr(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateMaterializedViewStmt_column_definition_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateMaterializedViewStmt_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateMaterializedViewStmt_column_definition_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateMaterializedViewStmt_set_column_definition_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateMaterializedViewStmt_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateMaterializedViewStmt_set_column_definition_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateMaterializedViewStmt_add_column_definition_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateMaterializedViewStmt_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateMaterializedViewStmt_add_column_definition_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateMaterializedViewStmt_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateMaterializedViewStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateMaterializedViewStmt_partition_by_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateMaterializedViewStmt_set_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateMaterializedViewStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateMaterializedViewStmt_set_partition_by_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateMaterializedViewStmt_add_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateMaterializedViewStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateMaterializedViewStmt_add_partition_by_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateMaterializedViewStmt_cluster_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateMaterializedViewStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateMaterializedViewStmt_cluster_by_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateMaterializedViewStmt_set_cluster_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateMaterializedViewStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateMaterializedViewStmt_set_cluster_by_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateMaterializedViewStmt_add_cluster_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateMaterializedViewStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateMaterializedViewStmt_add_cluster_by_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateProcedureStmt_argument_name_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateProcedureStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateProcedureStmt_argument_name_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateProcedureStmt_set_argument_name_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateProcedureStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateProcedureStmt_set_argument_name_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateProcedureStmt_add_argument_name_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateProcedureStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateProcedureStmt_add_argument_name_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateProcedureStmt_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateProcedureStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateProcedureStmt_signature(arg0, arg1)
}

func ResolvedCreateProcedureStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateProcedureStmt_set_signature(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateProcedureStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateProcedureStmt_set_signature(arg0, arg1)
}

func ResolvedCreateProcedureStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateProcedureStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateProcedureStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateProcedureStmt_option_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateProcedureStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateProcedureStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateProcedureStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateProcedureStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateProcedureStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateProcedureStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_procedure_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateProcedureStmt_procedure_body(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateProcedureStmt_procedure_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateProcedureStmt_procedure_body(arg0, arg1)
}

func ResolvedCreateProcedureStmt_set_procedure_body(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateProcedureStmt_set_procedure_body(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateProcedureStmt_set_procedure_body(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateProcedureStmt_set_procedure_body(arg0, arg1)
}

func ResolvedExecuteImmediateArgument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExecuteImmediateArgument_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExecuteImmediateArgument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExecuteImmediateArgument_name(arg0, arg1)
}

func ResolvedExecuteImmediateArgument_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExecuteImmediateArgument_set_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExecuteImmediateArgument_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExecuteImmediateArgument_set_name(arg0, arg1)
}

func ResolvedExecuteImmediateArgument_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExecuteImmediateArgument_expression(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExecuteImmediateArgument_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExecuteImmediateArgument_expression(arg0, arg1)
}

func ResolvedExecuteImmediateArgument_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExecuteImmediateArgument_set_expression(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExecuteImmediateArgument_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExecuteImmediateArgument_set_expression(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExecuteImmediateStmt_sql(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExecuteImmediateStmt_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExecuteImmediateStmt_sql(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExecuteImmediateStmt_set_sql(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExecuteImmediateStmt_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExecuteImmediateStmt_set_sql(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_into_identifier_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExecuteImmediateStmt_into_identifier_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExecuteImmediateStmt_into_identifier_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExecuteImmediateStmt_into_identifier_list(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_set_into_identifier_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExecuteImmediateStmt_set_into_identifier_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExecuteImmediateStmt_set_into_identifier_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExecuteImmediateStmt_set_into_identifier_list(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_add_into_identifier_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExecuteImmediateStmt_add_into_identifier_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExecuteImmediateStmt_add_into_identifier_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExecuteImmediateStmt_add_into_identifier_list(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_using_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedExecuteImmediateStmt_using_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExecuteImmediateStmt_using_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExecuteImmediateStmt_using_argument_list(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_set_using_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExecuteImmediateStmt_set_using_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExecuteImmediateStmt_set_using_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExecuteImmediateStmt_set_using_argument_list(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_add_using_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedExecuteImmediateStmt_add_using_argument_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedExecuteImmediateStmt_add_using_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedExecuteImmediateStmt_add_using_argument_list(arg0, arg1)
}

func ResolvedAssignmentStmt_target(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAssignmentStmt_target(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAssignmentStmt_target(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAssignmentStmt_target(arg0, arg1)
}

func ResolvedAssignmentStmt_set_target(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAssignmentStmt_set_target(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAssignmentStmt_set_target(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAssignmentStmt_set_target(arg0, arg1)
}

func ResolvedAssignmentStmt_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAssignmentStmt_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAssignmentStmt_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAssignmentStmt_expr(arg0, arg1)
}

func ResolvedAssignmentStmt_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAssignmentStmt_set_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAssignmentStmt_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAssignmentStmt_set_expr(arg0, arg1)
}

func ResolvedCreateEntityStmt_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateEntityStmt_entity_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateEntityStmt_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateEntityStmt_entity_type(arg0, arg1)
}

func ResolvedCreateEntityStmt_set_entity_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateEntityStmt_set_entity_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateEntityStmt_set_entity_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateEntityStmt_set_entity_type(arg0, arg1)
}

func ResolvedCreateEntityStmt_entity_body_json(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateEntityStmt_entity_body_json(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateEntityStmt_entity_body_json(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateEntityStmt_entity_body_json(arg0, arg1)
}

func ResolvedCreateEntityStmt_set_entity_body_json(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateEntityStmt_set_entity_body_json(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateEntityStmt_set_entity_body_json(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateEntityStmt_set_entity_body_json(arg0, arg1)
}

func ResolvedCreateEntityStmt_entity_body_text(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateEntityStmt_entity_body_text(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateEntityStmt_entity_body_text(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateEntityStmt_entity_body_text(arg0, arg1)
}

func ResolvedCreateEntityStmt_set_entity_body_text(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateEntityStmt_set_entity_body_text(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateEntityStmt_set_entity_body_text(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateEntityStmt_set_entity_body_text(arg0, arg1)
}

func ResolvedCreateEntityStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCreateEntityStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateEntityStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateEntityStmt_option_list(arg0, arg1)
}

func ResolvedCreateEntityStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateEntityStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateEntityStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateEntityStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateEntityStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCreateEntityStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCreateEntityStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCreateEntityStmt_add_option_list(arg0, arg1)
}

func ResolvedAlterEntityStmt_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAlterEntityStmt_entity_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterEntityStmt_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterEntityStmt_entity_type(arg0, arg1)
}

func ResolvedAlterEntityStmt_set_entity_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAlterEntityStmt_set_entity_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAlterEntityStmt_set_entity_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAlterEntityStmt_set_entity_type(arg0, arg1)
}

func ResolvedPivotColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedPivotColumn_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotColumn_column(arg0, arg1)
}

func ResolvedPivotColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPivotColumn_set_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotColumn_set_column(arg0, arg1)
}

func ResolvedPivotColumn_pivot_expr_index(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedPivotColumn_pivot_expr_index(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedPivotColumn_pivot_expr_index(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedPivotColumn_pivot_expr_index(arg0, arg1)
}

func ResolvedPivotColumn_set_pivot_expr_index(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedPivotColumn_set_pivot_expr_index(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedPivotColumn_set_pivot_expr_index(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedPivotColumn_set_pivot_expr_index(arg0, arg1)
}

func ResolvedPivotColumn_pivot_value_index(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedPivotColumn_pivot_value_index(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedPivotColumn_pivot_value_index(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedPivotColumn_pivot_value_index(arg0, arg1)
}

func ResolvedPivotColumn_set_pivot_value_index(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedPivotColumn_set_pivot_value_index(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedPivotColumn_set_pivot_value_index(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedPivotColumn_set_pivot_value_index(arg0, arg1)
}

func ResolvedPivotScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedPivotScan_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_input_scan(arg0, arg1)
}

func ResolvedPivotScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPivotScan_set_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_set_input_scan(arg0, arg1)
}

func ResolvedPivotScan_group_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedPivotScan_group_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_group_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_group_by_list(arg0, arg1)
}

func ResolvedPivotScan_set_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPivotScan_set_group_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_set_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_set_group_by_list(arg0, arg1)
}

func ResolvedPivotScan_add_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPivotScan_add_group_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_add_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_add_group_by_list(arg0, arg1)
}

func ResolvedPivotScan_pivot_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedPivotScan_pivot_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_pivot_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_pivot_expr_list(arg0, arg1)
}

func ResolvedPivotScan_set_pivot_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPivotScan_set_pivot_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_set_pivot_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_set_pivot_expr_list(arg0, arg1)
}

func ResolvedPivotScan_add_pivot_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPivotScan_add_pivot_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_add_pivot_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_add_pivot_expr_list(arg0, arg1)
}

func ResolvedPivotScan_for_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedPivotScan_for_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_for_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_for_expr(arg0, arg1)
}

func ResolvedPivotScan_set_for_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPivotScan_set_for_expr(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_set_for_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_set_for_expr(arg0, arg1)
}

func ResolvedPivotScan_pivot_value_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedPivotScan_pivot_value_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_pivot_value_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_pivot_value_list(arg0, arg1)
}

func ResolvedPivotScan_set_pivot_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPivotScan_set_pivot_value_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_set_pivot_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_set_pivot_value_list(arg0, arg1)
}

func ResolvedPivotScan_add_pivot_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPivotScan_add_pivot_value_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_add_pivot_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_add_pivot_value_list(arg0, arg1)
}

func ResolvedPivotScan_pivot_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedPivotScan_pivot_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_pivot_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_pivot_column_list(arg0, arg1)
}

func ResolvedPivotScan_set_pivot_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPivotScan_set_pivot_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_set_pivot_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_set_pivot_column_list(arg0, arg1)
}

func ResolvedPivotScan_add_pivot_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedPivotScan_add_pivot_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedPivotScan_add_pivot_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedPivotScan_add_pivot_column_list(arg0, arg1)
}

func ResolvedReturningClause_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedReturningClause_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReturningClause_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReturningClause_output_column_list(arg0, arg1)
}

func ResolvedReturningClause_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedReturningClause_set_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReturningClause_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReturningClause_set_output_column_list(arg0, arg1)
}

func ResolvedReturningClause_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedReturningClause_add_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReturningClause_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReturningClause_add_output_column_list(arg0, arg1)
}

func ResolvedReturningClause_action_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedReturningClause_action_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReturningClause_action_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReturningClause_action_column(arg0, arg1)
}

func ResolvedReturningClause_set_action_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedReturningClause_set_action_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReturningClause_set_action_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReturningClause_set_action_column(arg0, arg1)
}

func ResolvedReturningClause_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedReturningClause_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReturningClause_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReturningClause_expr_list(arg0, arg1)
}

func ResolvedReturningClause_set_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedReturningClause_set_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReturningClause_set_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReturningClause_set_expr_list(arg0, arg1)
}

func ResolvedReturningClause_add_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedReturningClause_add_expr_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedReturningClause_add_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedReturningClause_add_expr_list(arg0, arg1)
}

func ResolvedUnpivotArg_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUnpivotArg_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotArg_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotArg_column_list(arg0, arg1)
}

func ResolvedUnpivotArg_set_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUnpivotArg_set_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotArg_set_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotArg_set_column_list(arg0, arg1)
}

func ResolvedUnpivotArg_add_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUnpivotArg_add_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotArg_add_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotArg_add_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_input_scan(arg0, arg1)
}

func ResolvedUnpivotScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_set_input_scan(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_set_input_scan(arg0, arg1)
}

func ResolvedUnpivotScan_value_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_value_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_value_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_value_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_set_value_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_set_value_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_set_value_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_set_value_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_add_value_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_add_value_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_add_value_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_add_value_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_label_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_label_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_label_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_label_column(arg0, arg1)
}

func ResolvedUnpivotScan_set_label_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_set_label_column(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_set_label_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_set_label_column(arg0, arg1)
}

func ResolvedUnpivotScan_label_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_label_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_label_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_label_list(arg0, arg1)
}

func ResolvedUnpivotScan_set_label_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_set_label_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_set_label_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_set_label_list(arg0, arg1)
}

func ResolvedUnpivotScan_add_label_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_add_label_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_add_label_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_add_label_list(arg0, arg1)
}

func ResolvedUnpivotScan_unpivot_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_unpivot_arg_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_unpivot_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_unpivot_arg_list(arg0, arg1)
}

func ResolvedUnpivotScan_set_unpivot_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_set_unpivot_arg_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_set_unpivot_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_set_unpivot_arg_list(arg0, arg1)
}

func ResolvedUnpivotScan_add_unpivot_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_add_unpivot_arg_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_add_unpivot_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_add_unpivot_arg_list(arg0, arg1)
}

func ResolvedUnpivotScan_projected_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_projected_input_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_projected_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_projected_input_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_set_projected_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_set_projected_input_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_set_projected_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_set_projected_input_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_add_projected_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedUnpivotScan_add_projected_input_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedUnpivotScan_add_projected_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_add_projected_input_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_include_nulls(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedUnpivotScan_include_nulls(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedUnpivotScan_include_nulls(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_include_nulls(arg0, arg1)
}

func ResolvedUnpivotScan_set_include_nulls(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedUnpivotScan_set_include_nulls(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedUnpivotScan_set_include_nulls(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedUnpivotScan_set_include_nulls(arg0, arg1)
}

func ResolvedCloneDataStmt_target_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCloneDataStmt_target_table(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCloneDataStmt_target_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCloneDataStmt_target_table(arg0, arg1)
}

func ResolvedCloneDataStmt_set_target_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCloneDataStmt_set_target_table(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCloneDataStmt_set_target_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCloneDataStmt_set_target_table(arg0, arg1)
}

func ResolvedCloneDataStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCloneDataStmt_clone_from(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCloneDataStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCloneDataStmt_clone_from(arg0, arg1)
}

func ResolvedCloneDataStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedCloneDataStmt_set_clone_from(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCloneDataStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCloneDataStmt_set_clone_from(arg0, arg1)
}

func ResolvedTableAndColumnInfo_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedTableAndColumnInfo_table(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTableAndColumnInfo_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTableAndColumnInfo_table(arg0, arg1)
}

func ResolvedTableAndColumnInfo_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedTableAndColumnInfo_set_table(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTableAndColumnInfo_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTableAndColumnInfo_set_table(arg0, arg1)
}

func ResolvedTableAndColumnInfo_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedTableAndColumnInfo_column_index_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTableAndColumnInfo_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTableAndColumnInfo_column_index_list(arg0, arg1)
}

func ResolvedTableAndColumnInfo_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedTableAndColumnInfo_set_column_index_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedTableAndColumnInfo_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedTableAndColumnInfo_set_column_index_list(arg0, arg1)
}

func ResolvedTableAndColumnInfo_add_column_index_list(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedTableAndColumnInfo_add_column_index_list(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedTableAndColumnInfo_add_column_index_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedTableAndColumnInfo_add_column_index_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAnalyzeStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyzeStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyzeStmt_option_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAnalyzeStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyzeStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyzeStmt_set_option_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAnalyzeStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyzeStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyzeStmt_add_option_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_table_and_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAnalyzeStmt_table_and_column_index_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyzeStmt_table_and_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyzeStmt_table_and_column_index_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_set_table_and_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAnalyzeStmt_set_table_and_column_index_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyzeStmt_set_table_and_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyzeStmt_set_table_and_column_index_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_add_table_and_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAnalyzeStmt_add_table_and_column_index_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAnalyzeStmt_add_table_and_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAnalyzeStmt_add_table_and_column_index_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_insertion_mode(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedAuxLoadDataStmt_insertion_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedAuxLoadDataStmt_insertion_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_insertion_mode(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_insertion_mode(arg0 unsafe.Pointer, arg1 int) {
	analyzer_ResolvedAuxLoadDataStmt_set_insertion_mode(
		arg0,
		C.int(arg1),
	)
}

func analyzer_ResolvedAuxLoadDataStmt_set_insertion_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_set_insertion_mode(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_name_path(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_set_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_set_name_path(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_add_name_path(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_add_name_path(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_output_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_set_output_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_add_output_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_column_definition_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_column_definition_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_set_column_definition_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_set_column_definition_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_add_column_definition_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_add_column_definition_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_pseudo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_pseudo_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_pseudo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_pseudo_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_set_pseudo_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_set_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_set_pseudo_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_add_pseudo_column_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_add_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_add_pseudo_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_primary_key(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_primary_key(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_primary_key(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_primary_key(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_primary_key(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_set_primary_key(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_set_primary_key(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_set_primary_key(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_foreign_key_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_foreign_key_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_foreign_key_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_foreign_key_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_set_foreign_key_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_set_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_set_foreign_key_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_add_foreign_key_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_add_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_add_foreign_key_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_check_constraint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_check_constraint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_check_constraint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_check_constraint_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_set_check_constraint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_set_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_set_check_constraint_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_add_check_constraint_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_add_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_add_check_constraint_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_partition_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_set_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_set_partition_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_add_partition_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_add_partition_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_cluster_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_cluster_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_set_cluster_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_set_cluster_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_add_cluster_by_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_add_cluster_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_option_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_set_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_set_option_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_add_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_add_option_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_with_partition_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_with_partition_columns(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_with_partition_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_with_partition_columns(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_with_partition_columns(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_set_with_partition_columns(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_set_with_partition_columns(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_set_with_partition_columns(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_connection(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_connection(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_set_connection(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_set_connection(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_from_files_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_from_files_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_from_files_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_from_files_option_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_from_files_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_set_from_files_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_set_from_files_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_set_from_files_option_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_from_files_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	analyzer_ResolvedAuxLoadDataStmt_add_from_files_option_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedAuxLoadDataStmt_add_from_files_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedAuxLoadDataStmt_add_from_files_option_list(arg0, arg1)
}

func ResolvedColumn_IsInitialized(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedColumn_IsInitialized(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedColumn_IsInitialized(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedColumn_IsInitialized(arg0, arg1)
}

func ResolvedColumn_Clear(arg0 unsafe.Pointer) {
	analyzer_ResolvedColumn_Clear(
		arg0,
	)
}

func analyzer_ResolvedColumn_Clear(arg0 unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumn_Clear(arg0)
}

func ResolvedColumn_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumn_DebugString(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumn_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumn_DebugString(arg0, arg1)
}

func ResolvedColumn_ShortDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumn_ShortDebugString(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumn_ShortDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumn_ShortDebugString(arg0, arg1)
}

func ResolvedColumn_column_id(arg0 unsafe.Pointer, arg1 *int) {
	analyzer_ResolvedColumn_column_id(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedColumn_column_id(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_zetasql_public_analyzer_ResolvedColumn_column_id(arg0, arg1)
}

func ResolvedColumn_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumn_table_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumn_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumn_table_name(arg0, arg1)
}

func ResolvedColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumn_name(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumn_name(arg0, arg1)
}

func ResolvedColumn_table_name_id(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumn_table_name_id(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumn_table_name_id(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumn_table_name_id(arg0, arg1)
}

func ResolvedColumn_name_id(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumn_name_id(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumn_name_id(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumn_name_id(arg0, arg1)
}

func ResolvedColumn_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumn_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumn_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumn_type(arg0, arg1)
}

func ResolvedColumn_type_annotation_map(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumn_type_annotation_map(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumn_type_annotation_map(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumn_type_annotation_map(arg0, arg1)
}

func ResolvedColumn_annotated_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedColumn_annotated_type(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedColumn_annotated_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedColumn_annotated_type(arg0, arg1)
}

func ResolvedCollation_Empty(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCollation_Empty(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCollation_Empty(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCollation_Empty(arg0, arg1)
}

func ResolvedCollation_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	analyzer_ResolvedCollation_Equals(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func analyzer_ResolvedCollation_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCollation_Equals(arg0, arg1, arg2)
}

func ResolvedCollation_HasCompatibleStructure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	analyzer_ResolvedCollation_HasCompatibleStructure(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func analyzer_ResolvedCollation_HasCompatibleStructure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCollation_HasCompatibleStructure(arg0, arg1, arg2)
}

func ResolvedCollation_HasCollation(arg0 unsafe.Pointer, arg1 *bool) {
	analyzer_ResolvedCollation_HasCollation(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func analyzer_ResolvedCollation_HasCollation(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_zetasql_public_analyzer_ResolvedCollation_HasCollation(arg0, arg1)
}

func ResolvedCollation_CollationName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCollation_CollationName(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCollation_CollationName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCollation_CollationName(arg0, arg1)
}

func ResolvedCollation_child_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCollation_child_list(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCollation_child_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCollation_child_list(arg0, arg1)
}

func ResolvedCollation_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedCollation_DebugString(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedCollation_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedCollation_DebugString(arg0, arg1)
}

func ResolvedFunctionCallInfo_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	analyzer_ResolvedFunctionCallInfo_DebugString(
		arg0,
		arg1,
	)
}

func analyzer_ResolvedFunctionCallInfo_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_analyzer_ResolvedFunctionCallInfo_DebugString(arg0, arg1)
}

//export export_zetasql_public_analyzer_cctz_FixedOffsetFromName
//go:linkname export_zetasql_public_analyzer_cctz_FixedOffsetFromName github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetFromName
func export_zetasql_public_analyzer_cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

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
func export_zetasql_public_analyzer_cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *C.char)

//export export_zetasql_public_analyzer_TimeZoneIf_Load
//go:linkname export_zetasql_public_analyzer_TimeZoneIf_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneIf_Load
func export_zetasql_public_analyzer_TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_analyzer_time_zone_Impl_UTC
//go:linkname export_zetasql_public_analyzer_time_zone_Impl_UTC github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTC
func export_zetasql_public_analyzer_time_zone_Impl_UTC(arg0 *unsafe.Pointer)

//export export_zetasql_public_analyzer_time_zone_Impl_LoadTimeZone
//go:linkname export_zetasql_public_analyzer_time_zone_Impl_LoadTimeZone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_LoadTimeZone
func export_zetasql_public_analyzer_time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_public_analyzer_time_zone_Impl_ClearTimeZoneMapTestOnly
//go:linkname export_zetasql_public_analyzer_time_zone_Impl_ClearTimeZoneMapTestOnly github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_ClearTimeZoneMapTestOnly
func export_zetasql_public_analyzer_time_zone_Impl_ClearTimeZoneMapTestOnly()

//export export_zetasql_public_analyzer_time_zone_Impl_UTCImpl
//go:linkname export_zetasql_public_analyzer_time_zone_Impl_UTCImpl github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTCImpl
func export_zetasql_public_analyzer_time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer)

//export export_zetasql_public_analyzer_TimeZoneInfo_Load
//go:linkname export_zetasql_public_analyzer_TimeZoneInfo_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Load
func export_zetasql_public_analyzer_TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

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
func export_zetasql_public_analyzer_TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_public_analyzer_TimeZoneInfo_PrevTransition
//go:linkname export_zetasql_public_analyzer_TimeZoneInfo_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_PrevTransition
func export_zetasql_public_analyzer_TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

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
func export_zetasql_public_analyzer_TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_public_analyzer_TimeZoneLibC_PrevTransition
//go:linkname export_zetasql_public_analyzer_TimeZoneLibC_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_PrevTransition
func export_zetasql_public_analyzer_TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

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
func export_zetasql_public_analyzer_time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_public_analyzer_time_zone_prev_transition
//go:linkname export_zetasql_public_analyzer_time_zone_prev_transition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_prev_transition
func export_zetasql_public_analyzer_time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_public_analyzer_time_zone_version
//go:linkname export_zetasql_public_analyzer_time_zone_version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_version
func export_zetasql_public_analyzer_time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_analyzer_time_zone_description
//go:linkname export_zetasql_public_analyzer_time_zone_description github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_description
func export_zetasql_public_analyzer_time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_analyzer_cctz_load_time_zone
//go:linkname export_zetasql_public_analyzer_cctz_load_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_load_time_zone
func export_zetasql_public_analyzer_cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

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
func export_zetasql_public_analyzer_cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)
