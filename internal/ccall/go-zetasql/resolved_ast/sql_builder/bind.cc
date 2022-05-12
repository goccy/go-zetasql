
#ifndef zetasql_resolved_ast_sql_builder_bind_cc
#define zetasql_resolved_ast_sql_builder_bind_cc

// switch namespace
#define absl zetasql_resolved_ast_sql_builder_absl
#define google zetasql_resolved_ast_sql_builder_google
#define zetasql zetasql_resolved_ast_sql_builder_zetasql
#define zetasql_base zetasql_resolved_ast_sql_builder_zetasql_base
#define zetasql_bison_parser zetasql_resolved_ast_sql_builder_zetasql_bison_parser
#define re2 zetasql_resolved_ast_sql_builder_re2
#define AbslInternalSleepFor zetasql_resolved_ast_sql_builder_AbslInternalSleepFor
#define AbslInternalReportFatalUsageError zetasql_resolved_ast_sql_builder_AbslInternalReportFatalUsageError
#define AbslInternalMutexYield zetasql_resolved_ast_sql_builder_AbslInternalMutexYield
#define AbslInternalPerThreadSemPost zetasql_resolved_ast_sql_builder_AbslInternalPerThreadSemPost
#define AbslInternalPerThreadSemWait zetasql_resolved_ast_sql_builder_AbslInternalPerThreadSemWait
#define AbslContainerInternalSampleEverything zetasql_resolved_ast_sql_builder_AbslContainerInternalSampleEverything
#define AbslInternalSpinLockDelay zetasql_resolved_ast_sql_builder_AbslInternalSpinLockDelay
#define AbslInternalSpinLockWake zetasql_resolved_ast_sql_builder_AbslInternalSpinLockWake
#define AbslInternalAnnotateIgnoreReadsBegin zetasql_resolved_ast_sql_builder_AbslInternalAnnotateIgnoreReadsBegin
#define AbslInternalAnnotateIgnoreReadsEnd zetasql_resolved_ast_sql_builder_AbslInternalAnnotateIgnoreReadsEnd
#define AbslInternalGetFileMappingHint zetasql_resolved_ast_sql_builder_AbslInternalGetFileMappingHint
#define ZetaSqlalloc zetasql_resolved_ast_sql_builder_ZetaSqlalloc
#define ZetaSqlfree zetasql_resolved_ast_sql_builder_ZetaSqlfree
#define ZetaSqlrealloc zetasql_resolved_ast_sql_builder_ZetaSqlrealloc
#define FLAGS_nooutput_asc_explicitly zetasql_resolved_ast_sql_builder_FLAGS_nooutput_asc_explicitly
#define FLAGS_nozetasql_use_customized_flex_istream zetasql_resolved_ast_sql_builder_FLAGS_nozetasql_use_customized_flex_istream
#define FLAGS_output_asc_explicitly zetasql_resolved_ast_sql_builder_FLAGS_output_asc_explicitly
#define FLAGS_zetasql_use_customized_flex_istream zetasql_resolved_ast_sql_builder_FLAGS_zetasql_use_customized_flex_istream
#define FLAGS_zetasql_type_factory_nesting_depth_limit zetasql_resolved_ast_sql_builder_FLAGS_zetasql_type_factory_nesting_depth_limit
#define FLAGS_zetasql_read_proto_field_optimized_path zetasql_resolved_ast_sql_builder_FLAGS_zetasql_read_proto_field_optimized_path
#define FLAGS_zetasql_format_max_output_width zetasql_resolved_ast_sql_builder_FLAGS_zetasql_format_max_output_width
#define FLAGS_zetasql_min_length_required_for_edit_distance zetasql_resolved_ast_sql_builder_FLAGS_zetasql_min_length_required_for_edit_distance
#define FLAGS_zetasql_simple_iterator_call_time_now_rows_period zetasql_resolved_ast_sql_builder_FLAGS_zetasql_simple_iterator_call_time_now_rows_period
#define FLAGS_nozetasql_type_factory_nesting_depth_limit zetasql_resolved_ast_sql_builder_FLAGS_nozetasql_type_factory_nesting_depth_limit
#define FLAGS_nozetasql_read_proto_field_optimized_path zetasql_resolved_ast_sql_builder_FLAGS_nozetasql_read_proto_field_optimized_path
#define FLAGS_nozetasql_format_max_output_width zetasql_resolved_ast_sql_builder_FLAGS_nozetasql_format_max_output_width
#define FLAGS_nozetasql_min_length_required_for_edit_distance zetasql_resolved_ast_sql_builder_FLAGS_nozetasql_min_length_required_for_edit_distance
#define FLAGS_nozetasql_simple_iterator_call_time_now_rows_period zetasql_resolved_ast_sql_builder_FLAGS_nozetasql_simple_iterator_call_time_now_rows_period
#define ZetaSqlFlexTokenizerBase zetasql_resolved_ast_sql_builder_ZetaSqlFlexTokenizerBase
#define ZetaSqlFlexLexer zetasql_resolved_ast_sql_builder_ZetaSqlFlexLexer
#define UCaseMap zetasql_resolved_ast_sql_builder_UCaseMap
#define protobuf_google_2fprotobuf_2fdescriptor_2eproto zetasql_resolved_ast_sql_builder_protobuf_google_2fprotobuf_2fdescriptor_2eproto
#define protobuf_google_2fprotobuf_2ftimestamp_2eproto zetasql_resolved_ast_sql_builder_protobuf_google_2fprotobuf_2ftimestamp_2eproto
#define protobuf_google_2fprotobuf_2fany_2eproto zetasql_resolved_ast_sql_builder_protobuf_google_2fprotobuf_2fany_2eproto
#define protobuf_google_2fprotobuf_2fapi_2eproto zetasql_resolved_ast_sql_builder_protobuf_google_2fprotobuf_2fapi_2eproto
#define protobuf_google_2fprotobuf_2fduration_2eproto zetasql_resolved_ast_sql_builder_protobuf_google_2fprotobuf_2fduration_2eproto
#define protobuf_google_2fprotobuf_2fempty_2eproto zetasql_resolved_ast_sql_builder_protobuf_google_2fprotobuf_2fempty_2eproto
#define protobuf_google_2fprotobuf_2ffield_5fmask_2eproto zetasql_resolved_ast_sql_builder_protobuf_google_2fprotobuf_2ffield_5fmask_2eproto
#define protobuf_google_2fprotobuf_2fsource_5fcontext_2eproto zetasql_resolved_ast_sql_builder_protobuf_google_2fprotobuf_2fsource_5fcontext_2eproto
#define protobuf_google_2fprotobuf_2fstruct_2eproto zetasql_resolved_ast_sql_builder_protobuf_google_2fprotobuf_2fstruct_2eproto
#define protobuf_google_2fprotobuf_2ftype_2eproto zetasql_resolved_ast_sql_builder_protobuf_google_2fprotobuf_2ftype_2eproto
#define protobuf_google_2fprotobuf_2fwrappers_2eproto zetasql_resolved_ast_sql_builder_protobuf_google_2fprotobuf_2fwrappers_2eproto
#define protobuf_google_2ftype_2fdate_2eproto zetasql_resolved_ast_sql_builder_protobuf_google_2ftype_2fdate_2eproto
#define protobuf_google_2ftype_2flatlng_2eproto zetasql_resolved_ast_sql_builder_protobuf_google_2ftype_2flatlng_2eproto
#define protobuf_google_2ftype_2ftimeofday_2eproto zetasql_resolved_ast_sql_builder_protobuf_google_2ftype_2ftimeofday_2eproto
#define protobuf_zetasql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto
#define protobuf_zetasql_2fparser_2fparse_5ftree_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fparser_2fparse_5ftree_2eproto
#define protobuf_zetasql_2fparser_2fast_5fenums_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fparser_2fast_5fenums_2eproto
#define protobuf_zetasql_2fproto_2foptions_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fproto_2foptions_2eproto
#define protobuf_zetasql_2fproto_2fsimple_5fcatalog_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fproto_2fsimple_5fcatalog_2eproto
#define protobuf_zetasql_2fproto_2ffunction_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fproto_2ffunction_2eproto
#define protobuf_zetasql_2fproto_2finternal_5ferror_5flocation_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fproto_2finternal_5ferror_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2fbuiltin_5ffunction_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2fbuiltin_5ffunction_2eproto
#define protobuf_zetasql_2fpublic_2fdeprecation_5fwarning_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2fdeprecation_5fwarning_2eproto
#define protobuf_zetasql_2fpublic_2ffunction_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2ffunction_2eproto
#define protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2foptions_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2foptions_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5ftable_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2fsimple_5ftable_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5fconstant_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2fsimple_5fconstant_2eproto
#define protobuf_zetasql_2fpublic_2fparse_5flocation_5frange_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2fparse_5flocation_5frange_2eproto
#define protobuf_zetasql_2fpublic_2ftype_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2ftype_2eproto
#define protobuf_zetasql_2fpublic_2ftype_5fannotation_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2ftype_5fannotation_2eproto
#define protobuf_zetasql_2fpublic_2fvalue_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2fvalue_2eproto
#define protobuf_zetasql_2fpublic_2ftype_5fparameters_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2ftype_5fparameters_2eproto
#define protobuf_zetasql_2fpublic_2fcollation_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2fcollation_2eproto
#define protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2fannotation_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2fannotation_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5fvalue_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2fsimple_5fvalue_2eproto
#define protobuf_zetasql_2fpublic_2ffunctions_2fdatetime_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2ffunctions_2fdatetime_2eproto
#define protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto
#define protobuf_zetasql_2fpublic_2fproto_2ftype_5fannotation_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fpublic_2fproto_2ftype_5fannotation_2eproto
#define protobuf_zetasql_2freference_5fimpl_2fevaluator_5ftable_5fiterator_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2freference_5fimpl_2fevaluator_5ftable_5fiterator_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fnode_5fkind_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fresolved_5fast_2fresolved_5fnode_5fkind_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_5fenums_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_5fenums_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fserialization_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fresolved_5fast_2fserialization_2eproto
#define protobuf_zetasql_2fscripting_2fscript_5fexception_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fscripting_2fscript_5fexception_2eproto
#define protobuf_zetasql_2fscripting_2fscript_5fexecutor_5fstate_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fscripting_2fscript_5fexecutor_5fstate_2eproto
#define protobuf_zetasql_2fscripting_2fvariable_2eproto zetasql_resolved_ast_sql_builder_protobuf_zetasql_2fscripting_2fvariable_2eproto

#define GO_EXPORT(def) export_zetasql_resolved_ast_sql_builder_ ## def
#define U_ICU_ENTRY_POINT_RENAME(x) GO_EXPORT(x)

// include headers
//#define private public
#include "zetasql/resolved_ast/query_expression.h"
#include "zetasql/resolved_ast/sql_builder.h"
//#undef private

// include sources
#include "zetasql/resolved_ast/query_expression.cc"
#include "zetasql/resolved_ast/sql_builder.cc"

// include dependencies
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast_enums_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/rewrite_utils/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/public/analyzer/export.inc"
#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/constant/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-zetasql/public/functions/datetime_cc_proto/export.inc"
#include "go-zetasql/public/functions/normalize_mode_cc_proto/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/cleanup/cleanup/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-protobuf/protobuf/export.inc"

#include "bridge.h"

#include "bridge_cc.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "bridge.inc"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#undef GET_LIST
#undef GET_UNIQUE_PTR_LIST
#undef GET_STRS
#undef SET_LIST
#undef SET_UNIQUE_PTR_LIST
#undef ADD_UNIQUE_PTR_LIST

#endif /* zetasql_resolved_ast_sql_builder_bind_cc */
