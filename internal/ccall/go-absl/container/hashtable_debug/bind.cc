
#ifndef absl_container_hashtable_debug_bind_cc
#define absl_container_hashtable_debug_bind_cc

// switch namespace
#define absl absl_container_hashtable_debug_absl
#define google absl_container_hashtable_debug_google
#define zetasql absl_container_hashtable_debug_zetasql
#define zetasql_base absl_container_hashtable_debug_zetasql_base
#define zetasql_bison_parser absl_container_hashtable_debug_zetasql_bison_parser
#define re2 absl_container_hashtable_debug_re2
#define AbslInternalSleepFor absl_container_hashtable_debug_AbslInternalSleepFor
#define AbslInternalReportFatalUsageError absl_container_hashtable_debug_AbslInternalReportFatalUsageError
#define AbslInternalMutexYield absl_container_hashtable_debug_AbslInternalMutexYield
#define AbslInternalPerThreadSemPost absl_container_hashtable_debug_AbslInternalPerThreadSemPost
#define AbslInternalPerThreadSemWait absl_container_hashtable_debug_AbslInternalPerThreadSemWait
#define AbslContainerInternalSampleEverything absl_container_hashtable_debug_AbslContainerInternalSampleEverything
#define AbslInternalSpinLockDelay absl_container_hashtable_debug_AbslInternalSpinLockDelay
#define AbslInternalSpinLockWake absl_container_hashtable_debug_AbslInternalSpinLockWake
#define AbslInternalAnnotateIgnoreReadsBegin absl_container_hashtable_debug_AbslInternalAnnotateIgnoreReadsBegin
#define AbslInternalAnnotateIgnoreReadsEnd absl_container_hashtable_debug_AbslInternalAnnotateIgnoreReadsEnd
#define AbslInternalGetFileMappingHint absl_container_hashtable_debug_AbslInternalGetFileMappingHint
#define ZetaSqlalloc absl_container_hashtable_debug_ZetaSqlalloc
#define ZetaSqlfree absl_container_hashtable_debug_ZetaSqlfree
#define ZetaSqlrealloc absl_container_hashtable_debug_ZetaSqlrealloc
#define FLAGS_nooutput_asc_explicitly absl_container_hashtable_debug_FLAGS_nooutput_asc_explicitly
#define FLAGS_nozetasql_use_customized_flex_istream absl_container_hashtable_debug_FLAGS_nozetasql_use_customized_flex_istream
#define FLAGS_output_asc_explicitly absl_container_hashtable_debug_FLAGS_output_asc_explicitly
#define FLAGS_zetasql_use_customized_flex_istream absl_container_hashtable_debug_FLAGS_zetasql_use_customized_flex_istream
#define FLAGS_zetasql_type_factory_nesting_depth_limit absl_container_hashtable_debug_FLAGS_zetasql_type_factory_nesting_depth_limit
#define FLAGS_zetasql_read_proto_field_optimized_path absl_container_hashtable_debug_FLAGS_zetasql_read_proto_field_optimized_path
#define FLAGS_nozetasql_type_factory_nesting_depth_limit absl_container_hashtable_debug_FLAGS_nozetasql_type_factory_nesting_depth_limit
#define FLAGS_nozetasql_read_proto_field_optimized_path absl_container_hashtable_debug_FLAGS_nozetasql_read_proto_field_optimized_path
#define ZetaSqlFlexTokenizerBase absl_container_hashtable_debug_ZetaSqlFlexTokenizerBase
#define ZetaSqlFlexLexer absl_container_hashtable_debug_ZetaSqlFlexLexer
#define UCaseMap absl_container_hashtable_debug_UCaseMap
#define protobuf_google_2fprotobuf_2fdescriptor_2eproto absl_container_hashtable_debug_protobuf_google_2fprotobuf_2fdescriptor_2eproto
#define protobuf_google_2fprotobuf_2ftimestamp_2eproto absl_container_hashtable_debug_protobuf_google_2fprotobuf_2ftimestamp_2eproto
#define protobuf_google_2fprotobuf_2fany_2eproto absl_container_hashtable_debug_protobuf_google_2fprotobuf_2fany_2eproto
#define protobuf_google_2fprotobuf_2fapi_2eproto absl_container_hashtable_debug_protobuf_google_2fprotobuf_2fapi_2eproto
#define protobuf_google_2fprotobuf_2fduration_2eproto absl_container_hashtable_debug_protobuf_google_2fprotobuf_2fduration_2eproto
#define protobuf_google_2fprotobuf_2fempty_2eproto absl_container_hashtable_debug_protobuf_google_2fprotobuf_2fempty_2eproto
#define protobuf_google_2fprotobuf_2ffield_5fmask_2eproto absl_container_hashtable_debug_protobuf_google_2fprotobuf_2ffield_5fmask_2eproto
#define protobuf_google_2fprotobuf_2fsource_5fcontext_2eproto absl_container_hashtable_debug_protobuf_google_2fprotobuf_2fsource_5fcontext_2eproto
#define protobuf_google_2fprotobuf_2fstruct_2eproto absl_container_hashtable_debug_protobuf_google_2fprotobuf_2fstruct_2eproto
#define protobuf_google_2fprotobuf_2ftype_2eproto absl_container_hashtable_debug_protobuf_google_2fprotobuf_2ftype_2eproto
#define protobuf_google_2fprotobuf_2fwrappers_2eproto absl_container_hashtable_debug_protobuf_google_2fprotobuf_2fwrappers_2eproto
#define protobuf_google_2ftype_2fdate_2eproto absl_container_hashtable_debug_protobuf_google_2ftype_2fdate_2eproto
#define protobuf_google_2ftype_2flatlng_2eproto absl_container_hashtable_debug_protobuf_google_2ftype_2flatlng_2eproto
#define protobuf_google_2ftype_2ftimeofday_2eproto absl_container_hashtable_debug_protobuf_google_2ftype_2ftimeofday_2eproto
#define protobuf_zetasql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto
#define protobuf_zetasql_2fparser_2fparse_5ftree_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fparser_2fparse_5ftree_2eproto
#define protobuf_zetasql_2fparser_2fast_5fenums_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fparser_2fast_5fenums_2eproto
#define protobuf_zetasql_2fproto_2foptions_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fproto_2foptions_2eproto
#define protobuf_zetasql_2fproto_2fsimple_5fcatalog_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fproto_2fsimple_5fcatalog_2eproto
#define protobuf_zetasql_2fproto_2ffunction_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fproto_2ffunction_2eproto
#define protobuf_zetasql_2fproto_2finternal_5ferror_5flocation_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fproto_2finternal_5ferror_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2fbuiltin_5ffunction_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2fbuiltin_5ffunction_2eproto
#define protobuf_zetasql_2fpublic_2fdeprecation_5fwarning_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2fdeprecation_5fwarning_2eproto
#define protobuf_zetasql_2fpublic_2ffunction_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2ffunction_2eproto
#define protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2foptions_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2foptions_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5ftable_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2fsimple_5ftable_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5fconstant_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2fsimple_5fconstant_2eproto
#define protobuf_zetasql_2fpublic_2fparse_5flocation_5frange_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2fparse_5flocation_5frange_2eproto
#define protobuf_zetasql_2fpublic_2ftype_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2ftype_2eproto
#define protobuf_zetasql_2fpublic_2ftype_5fannotation_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2ftype_5fannotation_2eproto
#define protobuf_zetasql_2fpublic_2fvalue_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2fvalue_2eproto
#define protobuf_zetasql_2fpublic_2ftype_5fparameters_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2ftype_5fparameters_2eproto
#define protobuf_zetasql_2fpublic_2fcollation_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2fcollation_2eproto
#define protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2fannotation_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2fannotation_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5fvalue_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2fsimple_5fvalue_2eproto
#define protobuf_zetasql_2fpublic_2ffunctions_2fdatetime_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2ffunctions_2fdatetime_2eproto
#define protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto
#define protobuf_zetasql_2fpublic_2fproto_2ftype_5fannotation_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fpublic_2fproto_2ftype_5fannotation_2eproto
#define protobuf_zetasql_2freference_5fimpl_2fevaluator_5ftable_5fiterator_2eproto absl_container_hashtable_debug_protobuf_zetasql_2freference_5fimpl_2fevaluator_5ftable_5fiterator_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fnode_5fkind_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fresolved_5fast_2fresolved_5fnode_5fkind_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_5fenums_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_5fenums_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fserialization_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fresolved_5fast_2fserialization_2eproto
#define protobuf_zetasql_2fscripting_2fscript_5fexception_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fscripting_2fscript_5fexception_2eproto
#define protobuf_zetasql_2fscripting_2fscript_5fexecutor_5fstate_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fscripting_2fscript_5fexecutor_5fstate_2eproto
#define protobuf_zetasql_2fscripting_2fvariable_2eproto absl_container_hashtable_debug_protobuf_zetasql_2fscripting_2fvariable_2eproto

#define GO_EXPORT(def) export_absl_container_hashtable_debug_ ## def
#define U_ICU_ENTRY_POINT_RENAME(x) GO_EXPORT(x)

// include headers
//#define private public
#include "absl/container/internal/hashtable_debug.h"
//#undef private

// include sources

// include dependencies
#include "go-absl/container/hashtable_debug_hooks/export.inc"

#include "bridge.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "bridge.inc"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* absl_container_hashtable_debug_bind_cc */
