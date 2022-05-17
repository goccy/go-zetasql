
#ifndef zetasql_analyzer_lambda_util_bind_cc
#define zetasql_analyzer_lambda_util_bind_cc

// switch namespace
#define absl zetasql_analyzer_lambda_util_absl
#define google zetasql_analyzer_lambda_util_google
#define zetasql zetasql_analyzer_lambda_util_zetasql
#define zetasql_base zetasql_analyzer_lambda_util_zetasql_base
#define zetasql_bison_parser zetasql_analyzer_lambda_util_zetasql_bison_parser
#define re2 zetasql_analyzer_lambda_util_re2
#define AbslInternalSleepFor zetasql_analyzer_lambda_util_AbslInternalSleepFor
#define AbslInternalReportFatalUsageError zetasql_analyzer_lambda_util_AbslInternalReportFatalUsageError
#define AbslInternalMutexYield zetasql_analyzer_lambda_util_AbslInternalMutexYield
#define AbslInternalPerThreadSemPost zetasql_analyzer_lambda_util_AbslInternalPerThreadSemPost
#define AbslInternalPerThreadSemWait zetasql_analyzer_lambda_util_AbslInternalPerThreadSemWait
#define AbslContainerInternalSampleEverything zetasql_analyzer_lambda_util_AbslContainerInternalSampleEverything
#define AbslInternalSpinLockDelay zetasql_analyzer_lambda_util_AbslInternalSpinLockDelay
#define AbslInternalSpinLockWake zetasql_analyzer_lambda_util_AbslInternalSpinLockWake
#define AbslInternalAnnotateIgnoreReadsBegin zetasql_analyzer_lambda_util_AbslInternalAnnotateIgnoreReadsBegin
#define AbslInternalAnnotateIgnoreReadsEnd zetasql_analyzer_lambda_util_AbslInternalAnnotateIgnoreReadsEnd
#define AbslInternalGetFileMappingHint zetasql_analyzer_lambda_util_AbslInternalGetFileMappingHint
#define ZetaSqlalloc zetasql_analyzer_lambda_util_ZetaSqlalloc
#define ZetaSqlfree zetasql_analyzer_lambda_util_ZetaSqlfree
#define ZetaSqlrealloc zetasql_analyzer_lambda_util_ZetaSqlrealloc
#define FLAGS_nooutput_asc_explicitly zetasql_analyzer_lambda_util_FLAGS_nooutput_asc_explicitly
#define FLAGS_nozetasql_use_customized_flex_istream zetasql_analyzer_lambda_util_FLAGS_nozetasql_use_customized_flex_istream
#define FLAGS_output_asc_explicitly zetasql_analyzer_lambda_util_FLAGS_output_asc_explicitly
#define FLAGS_zetasql_use_customized_flex_istream zetasql_analyzer_lambda_util_FLAGS_zetasql_use_customized_flex_istream
#define FLAGS_zetasql_type_factory_nesting_depth_limit zetasql_analyzer_lambda_util_FLAGS_zetasql_type_factory_nesting_depth_limit
#define FLAGS_zetasql_read_proto_field_optimized_path zetasql_analyzer_lambda_util_FLAGS_zetasql_read_proto_field_optimized_path
#define FLAGS_zetasql_format_max_output_width zetasql_analyzer_lambda_util_FLAGS_zetasql_format_max_output_width
#define FLAGS_zetasql_min_length_required_for_edit_distance zetasql_analyzer_lambda_util_FLAGS_zetasql_min_length_required_for_edit_distance
#define FLAGS_zetasql_simple_iterator_call_time_now_rows_period zetasql_analyzer_lambda_util_FLAGS_zetasql_simple_iterator_call_time_now_rows_period
#define FLAGS_nozetasql_type_factory_nesting_depth_limit zetasql_analyzer_lambda_util_FLAGS_nozetasql_type_factory_nesting_depth_limit
#define FLAGS_nozetasql_read_proto_field_optimized_path zetasql_analyzer_lambda_util_FLAGS_nozetasql_read_proto_field_optimized_path
#define FLAGS_nozetasql_format_max_output_width zetasql_analyzer_lambda_util_FLAGS_nozetasql_format_max_output_width
#define FLAGS_nozetasql_min_length_required_for_edit_distance zetasql_analyzer_lambda_util_FLAGS_nozetasql_min_length_required_for_edit_distance
#define FLAGS_nozetasql_simple_iterator_call_time_now_rows_period zetasql_analyzer_lambda_util_FLAGS_nozetasql_simple_iterator_call_time_now_rows_period
#define ZetaSqlFlexTokenizerBase zetasql_analyzer_lambda_util_ZetaSqlFlexTokenizerBase
#define ZetaSqlFlexLexer zetasql_analyzer_lambda_util_ZetaSqlFlexLexer
#define UCaseMap zetasql_analyzer_lambda_util_UCaseMap
#define protobuf_google_2fprotobuf_2fdescriptor_2eproto zetasql_analyzer_lambda_util_protobuf_google_2fprotobuf_2fdescriptor_2eproto
#define protobuf_google_2fprotobuf_2ftimestamp_2eproto zetasql_analyzer_lambda_util_protobuf_google_2fprotobuf_2ftimestamp_2eproto
#define protobuf_google_2fprotobuf_2fany_2eproto zetasql_analyzer_lambda_util_protobuf_google_2fprotobuf_2fany_2eproto
#define protobuf_google_2fprotobuf_2fapi_2eproto zetasql_analyzer_lambda_util_protobuf_google_2fprotobuf_2fapi_2eproto
#define protobuf_google_2fprotobuf_2fduration_2eproto zetasql_analyzer_lambda_util_protobuf_google_2fprotobuf_2fduration_2eproto
#define protobuf_google_2fprotobuf_2fempty_2eproto zetasql_analyzer_lambda_util_protobuf_google_2fprotobuf_2fempty_2eproto
#define protobuf_google_2fprotobuf_2ffield_5fmask_2eproto zetasql_analyzer_lambda_util_protobuf_google_2fprotobuf_2ffield_5fmask_2eproto
#define protobuf_google_2fprotobuf_2fsource_5fcontext_2eproto zetasql_analyzer_lambda_util_protobuf_google_2fprotobuf_2fsource_5fcontext_2eproto
#define protobuf_google_2fprotobuf_2fstruct_2eproto zetasql_analyzer_lambda_util_protobuf_google_2fprotobuf_2fstruct_2eproto
#define protobuf_google_2fprotobuf_2ftype_2eproto zetasql_analyzer_lambda_util_protobuf_google_2fprotobuf_2ftype_2eproto
#define protobuf_google_2fprotobuf_2fwrappers_2eproto zetasql_analyzer_lambda_util_protobuf_google_2fprotobuf_2fwrappers_2eproto
#define protobuf_google_2ftype_2fdate_2eproto zetasql_analyzer_lambda_util_protobuf_google_2ftype_2fdate_2eproto
#define protobuf_google_2ftype_2flatlng_2eproto zetasql_analyzer_lambda_util_protobuf_google_2ftype_2flatlng_2eproto
#define protobuf_google_2ftype_2ftimeofday_2eproto zetasql_analyzer_lambda_util_protobuf_google_2ftype_2ftimeofday_2eproto
#define protobuf_zetasql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto
#define protobuf_zetasql_2fparser_2fparse_5ftree_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fparser_2fparse_5ftree_2eproto
#define protobuf_zetasql_2fparser_2fast_5fenums_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fparser_2fast_5fenums_2eproto
#define protobuf_zetasql_2fproto_2foptions_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fproto_2foptions_2eproto
#define protobuf_zetasql_2fproto_2fsimple_5fcatalog_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fproto_2fsimple_5fcatalog_2eproto
#define protobuf_zetasql_2fproto_2ffunction_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fproto_2ffunction_2eproto
#define protobuf_zetasql_2fproto_2finternal_5ferror_5flocation_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fproto_2finternal_5ferror_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2fbuiltin_5ffunction_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2fbuiltin_5ffunction_2eproto
#define protobuf_zetasql_2fpublic_2fdeprecation_5fwarning_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2fdeprecation_5fwarning_2eproto
#define protobuf_zetasql_2fpublic_2ffunction_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2ffunction_2eproto
#define protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2foptions_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2foptions_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5ftable_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2fsimple_5ftable_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5fconstant_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2fsimple_5fconstant_2eproto
#define protobuf_zetasql_2fpublic_2fparse_5flocation_5frange_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2fparse_5flocation_5frange_2eproto
#define protobuf_zetasql_2fpublic_2ftype_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2ftype_2eproto
#define protobuf_zetasql_2fpublic_2ftype_5fannotation_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2ftype_5fannotation_2eproto
#define protobuf_zetasql_2fpublic_2fvalue_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2fvalue_2eproto
#define protobuf_zetasql_2fpublic_2ftype_5fparameters_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2ftype_5fparameters_2eproto
#define protobuf_zetasql_2fpublic_2fcollation_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2fcollation_2eproto
#define protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2fannotation_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2fannotation_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5fvalue_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2fsimple_5fvalue_2eproto
#define protobuf_zetasql_2fpublic_2ffunctions_2fdatetime_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2ffunctions_2fdatetime_2eproto
#define protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto
#define protobuf_zetasql_2fpublic_2fproto_2ftype_5fannotation_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fpublic_2fproto_2ftype_5fannotation_2eproto
#define protobuf_zetasql_2freference_5fimpl_2fevaluator_5ftable_5fiterator_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2freference_5fimpl_2fevaluator_5ftable_5fiterator_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fnode_5fkind_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fresolved_5fast_2fresolved_5fnode_5fkind_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_5fenums_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_5fenums_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fserialization_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fresolved_5fast_2fserialization_2eproto
#define protobuf_zetasql_2fscripting_2fscript_5fexception_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fscripting_2fscript_5fexception_2eproto
#define protobuf_zetasql_2fscripting_2fscript_5fexecutor_5fstate_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fscripting_2fscript_5fexecutor_5fstate_2eproto
#define protobuf_zetasql_2fscripting_2fvariable_2eproto zetasql_analyzer_lambda_util_protobuf_zetasql_2fscripting_2fvariable_2eproto

#define GO_EXPORT(def) export_zetasql_analyzer_lambda_util_ ## def
#define U_ICU_ENTRY_POINT_RENAME(x) GO_EXPORT(x)

// include headers
//#define private public
#include "zetasql/analyzer/lambda_util.h"
//#undef private

// include sources
#include "zetasql/analyzer/lambda_util.cc"

// include dependencies
#include "go-zetasql/base/logging/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"

#include "bridge.h"

#include "bridge_cc.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "bridge.inc"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* zetasql_analyzer_lambda_util_bind_cc */
