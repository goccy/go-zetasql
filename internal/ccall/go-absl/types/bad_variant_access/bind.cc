
#ifndef absl_types_bad_variant_access_bind_cc
#define absl_types_bad_variant_access_bind_cc

// switch namespace
#define absl absl_types_bad_variant_access_absl
#define google absl_types_bad_variant_access_google
#define zetasql absl_types_bad_variant_access_zetasql
#define zetasql_base absl_types_bad_variant_access_zetasql_base
#define zetasql_bison_parser absl_types_bad_variant_access_zetasql_bison_parser
#define re2 absl_types_bad_variant_access_re2
#define AbslInternalSleepFor absl_types_bad_variant_access_AbslInternalSleepFor
#define AbslInternalReportFatalUsageError absl_types_bad_variant_access_AbslInternalReportFatalUsageError
#define AbslInternalMutexYield absl_types_bad_variant_access_AbslInternalMutexYield
#define AbslInternalPerThreadSemPost absl_types_bad_variant_access_AbslInternalPerThreadSemPost
#define AbslInternalPerThreadSemWait absl_types_bad_variant_access_AbslInternalPerThreadSemWait
#define AbslContainerInternalSampleEverything absl_types_bad_variant_access_AbslContainerInternalSampleEverything
#define AbslInternalSpinLockDelay absl_types_bad_variant_access_AbslInternalSpinLockDelay
#define AbslInternalSpinLockWake absl_types_bad_variant_access_AbslInternalSpinLockWake
#define AbslInternalAnnotateIgnoreReadsBegin absl_types_bad_variant_access_AbslInternalAnnotateIgnoreReadsBegin
#define AbslInternalAnnotateIgnoreReadsEnd absl_types_bad_variant_access_AbslInternalAnnotateIgnoreReadsEnd
#define AbslInternalGetFileMappingHint absl_types_bad_variant_access_AbslInternalGetFileMappingHint
#define ZetaSqlalloc absl_types_bad_variant_access_ZetaSqlalloc
#define ZetaSqlfree absl_types_bad_variant_access_ZetaSqlfree
#define ZetaSqlrealloc absl_types_bad_variant_access_ZetaSqlrealloc
#define FLAGS_nooutput_asc_explicitly absl_types_bad_variant_access_FLAGS_nooutput_asc_explicitly
#define FLAGS_nozetasql_use_customized_flex_istream absl_types_bad_variant_access_FLAGS_nozetasql_use_customized_flex_istream
#define FLAGS_output_asc_explicitly absl_types_bad_variant_access_FLAGS_output_asc_explicitly
#define FLAGS_zetasql_use_customized_flex_istream absl_types_bad_variant_access_FLAGS_zetasql_use_customized_flex_istream
#define FLAGS_zetasql_type_factory_nesting_depth_limit absl_types_bad_variant_access_FLAGS_zetasql_type_factory_nesting_depth_limit
#define FLAGS_zetasql_read_proto_field_optimized_path absl_types_bad_variant_access_FLAGS_zetasql_read_proto_field_optimized_path
#define FLAGS_zetasql_format_max_output_width absl_types_bad_variant_access_FLAGS_zetasql_format_max_output_width
#define FLAGS_zetasql_min_length_required_for_edit_distance absl_types_bad_variant_access_FLAGS_zetasql_min_length_required_for_edit_distance
#define FLAGS_zetasql_simple_iterator_call_time_now_rows_period absl_types_bad_variant_access_FLAGS_zetasql_simple_iterator_call_time_now_rows_period
#define FLAGS_nozetasql_type_factory_nesting_depth_limit absl_types_bad_variant_access_FLAGS_nozetasql_type_factory_nesting_depth_limit
#define FLAGS_nozetasql_read_proto_field_optimized_path absl_types_bad_variant_access_FLAGS_nozetasql_read_proto_field_optimized_path
#define FLAGS_nozetasql_format_max_output_width absl_types_bad_variant_access_FLAGS_nozetasql_format_max_output_width
#define FLAGS_nozetasql_min_length_required_for_edit_distance absl_types_bad_variant_access_FLAGS_nozetasql_min_length_required_for_edit_distance
#define FLAGS_nozetasql_simple_iterator_call_time_now_rows_period absl_types_bad_variant_access_FLAGS_nozetasql_simple_iterator_call_time_now_rows_period
#define ZetaSqlFlexTokenizerBase absl_types_bad_variant_access_ZetaSqlFlexTokenizerBase
#define ZetaSqlFlexLexer absl_types_bad_variant_access_ZetaSqlFlexLexer
#define UCaseMap absl_types_bad_variant_access_UCaseMap
#define protobuf_google_2fprotobuf_2fdescriptor_2eproto absl_types_bad_variant_access_protobuf_google_2fprotobuf_2fdescriptor_2eproto
#define protobuf_google_2fprotobuf_2ftimestamp_2eproto absl_types_bad_variant_access_protobuf_google_2fprotobuf_2ftimestamp_2eproto
#define protobuf_google_2fprotobuf_2fany_2eproto absl_types_bad_variant_access_protobuf_google_2fprotobuf_2fany_2eproto
#define protobuf_google_2fprotobuf_2fapi_2eproto absl_types_bad_variant_access_protobuf_google_2fprotobuf_2fapi_2eproto
#define protobuf_google_2fprotobuf_2fduration_2eproto absl_types_bad_variant_access_protobuf_google_2fprotobuf_2fduration_2eproto
#define protobuf_google_2fprotobuf_2fempty_2eproto absl_types_bad_variant_access_protobuf_google_2fprotobuf_2fempty_2eproto
#define protobuf_google_2fprotobuf_2ffield_5fmask_2eproto absl_types_bad_variant_access_protobuf_google_2fprotobuf_2ffield_5fmask_2eproto
#define protobuf_google_2fprotobuf_2fsource_5fcontext_2eproto absl_types_bad_variant_access_protobuf_google_2fprotobuf_2fsource_5fcontext_2eproto
#define protobuf_google_2fprotobuf_2fstruct_2eproto absl_types_bad_variant_access_protobuf_google_2fprotobuf_2fstruct_2eproto
#define protobuf_google_2fprotobuf_2ftype_2eproto absl_types_bad_variant_access_protobuf_google_2fprotobuf_2ftype_2eproto
#define protobuf_google_2fprotobuf_2fwrappers_2eproto absl_types_bad_variant_access_protobuf_google_2fprotobuf_2fwrappers_2eproto
#define protobuf_google_2ftype_2fdate_2eproto absl_types_bad_variant_access_protobuf_google_2ftype_2fdate_2eproto
#define protobuf_google_2ftype_2flatlng_2eproto absl_types_bad_variant_access_protobuf_google_2ftype_2flatlng_2eproto
#define protobuf_google_2ftype_2ftimeofday_2eproto absl_types_bad_variant_access_protobuf_google_2ftype_2ftimeofday_2eproto
#define protobuf_zetasql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto
#define protobuf_zetasql_2fparser_2fparse_5ftree_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fparser_2fparse_5ftree_2eproto
#define protobuf_zetasql_2fparser_2fast_5fenums_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fparser_2fast_5fenums_2eproto
#define protobuf_zetasql_2fproto_2foptions_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fproto_2foptions_2eproto
#define protobuf_zetasql_2fproto_2fsimple_5fcatalog_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fproto_2fsimple_5fcatalog_2eproto
#define protobuf_zetasql_2fproto_2ffunction_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fproto_2ffunction_2eproto
#define protobuf_zetasql_2fproto_2finternal_5ferror_5flocation_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fproto_2finternal_5ferror_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2fbuiltin_5ffunction_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2fbuiltin_5ffunction_2eproto
#define protobuf_zetasql_2fpublic_2fdeprecation_5fwarning_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2fdeprecation_5fwarning_2eproto
#define protobuf_zetasql_2fpublic_2ffunction_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2ffunction_2eproto
#define protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2foptions_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2foptions_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5ftable_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2fsimple_5ftable_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5fconstant_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2fsimple_5fconstant_2eproto
#define protobuf_zetasql_2fpublic_2fparse_5flocation_5frange_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2fparse_5flocation_5frange_2eproto
#define protobuf_zetasql_2fpublic_2ftype_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2ftype_2eproto
#define protobuf_zetasql_2fpublic_2ftype_5fannotation_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2ftype_5fannotation_2eproto
#define protobuf_zetasql_2fpublic_2fvalue_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2fvalue_2eproto
#define protobuf_zetasql_2fpublic_2ftype_5fparameters_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2ftype_5fparameters_2eproto
#define protobuf_zetasql_2fpublic_2fcollation_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2fcollation_2eproto
#define protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2fannotation_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2fannotation_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5fvalue_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2fsimple_5fvalue_2eproto
#define protobuf_zetasql_2fpublic_2ffunctions_2fdatetime_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2ffunctions_2fdatetime_2eproto
#define protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto
#define protobuf_zetasql_2fpublic_2fproto_2ftype_5fannotation_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fpublic_2fproto_2ftype_5fannotation_2eproto
#define protobuf_zetasql_2freference_5fimpl_2fevaluator_5ftable_5fiterator_2eproto absl_types_bad_variant_access_protobuf_zetasql_2freference_5fimpl_2fevaluator_5ftable_5fiterator_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fnode_5fkind_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fresolved_5fast_2fresolved_5fnode_5fkind_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_5fenums_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_5fenums_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fserialization_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fresolved_5fast_2fserialization_2eproto
#define protobuf_zetasql_2fscripting_2fscript_5fexception_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fscripting_2fscript_5fexception_2eproto
#define protobuf_zetasql_2fscripting_2fscript_5fexecutor_5fstate_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fscripting_2fscript_5fexecutor_5fstate_2eproto
#define protobuf_zetasql_2fscripting_2fvariable_2eproto absl_types_bad_variant_access_protobuf_zetasql_2fscripting_2fvariable_2eproto

#define GO_EXPORT(def) export_absl_types_bad_variant_access_ ## def
#define U_ICU_ENTRY_POINT_RENAME(x) GO_EXPORT(x)

// include headers
//#define private public
#include "absl/types/bad_variant_access.h"
//#undef private

// include sources
#include "absl/types/bad_variant_access.cc"

// include dependencies
#include "go-absl/base/config/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"

#include "bridge.h"

#include "bridge_cc.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "bridge.inc"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* absl_types_bad_variant_access_bind_cc */
