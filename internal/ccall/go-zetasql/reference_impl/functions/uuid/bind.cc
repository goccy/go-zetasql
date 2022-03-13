
#ifndef zetasql_reference_impl_functions_uuid_bind_cc
#define zetasql_reference_impl_functions_uuid_bind_cc

// switch namespace
#define absl zetasql_reference_impl_functions_uuid_absl
#define google zetasql_reference_impl_functions_uuid_google
#define zetasql zetasql_reference_impl_functions_uuid_zetasql
#define zetasql_base zetasql_reference_impl_functions_uuid_zetasql_base
#define zetasql_bison_parser zetasql_reference_impl_functions_uuid_zetasql_bison_parser
#define re2 zetasql_reference_impl_functions_uuid_re2
#define AbslInternalSleepFor zetasql_reference_impl_functions_uuid_AbslInternalSleepFor
#define AbslInternalReportFatalUsageError zetasql_reference_impl_functions_uuid_AbslInternalReportFatalUsageError
#define AbslInternalMutexYield zetasql_reference_impl_functions_uuid_AbslInternalMutexYield
#define AbslInternalPerThreadSemPost zetasql_reference_impl_functions_uuid_AbslInternalPerThreadSemPost
#define AbslInternalPerThreadSemWait zetasql_reference_impl_functions_uuid_AbslInternalPerThreadSemWait
#define AbslContainerInternalSampleEverything zetasql_reference_impl_functions_uuid_AbslContainerInternalSampleEverything
#define AbslInternalSpinLockDelay zetasql_reference_impl_functions_uuid_AbslInternalSpinLockDelay
#define AbslInternalSpinLockWake zetasql_reference_impl_functions_uuid_AbslInternalSpinLockWake
#define AbslInternalAnnotateIgnoreReadsBegin zetasql_reference_impl_functions_uuid_AbslInternalAnnotateIgnoreReadsBegin
#define AbslInternalAnnotateIgnoreReadsEnd zetasql_reference_impl_functions_uuid_AbslInternalAnnotateIgnoreReadsEnd
#define ZetaSqlalloc zetasql_reference_impl_functions_uuid_ZetaSqlalloc
#define ZetaSqlfree zetasql_reference_impl_functions_uuid_ZetaSqlfree
#define ZetaSqlrealloc zetasql_reference_impl_functions_uuid_ZetaSqlrealloc
#define FLAGS_nooutput_asc_explicitly zetasql_reference_impl_functions_uuid_FLAGS_nooutput_asc_explicitly
#define FLAGS_nozetasql_use_customized_flex_istream zetasql_reference_impl_functions_uuid_FLAGS_nozetasql_use_customized_flex_istream
#define FLAGS_output_asc_explicitly zetasql_reference_impl_functions_uuid_FLAGS_output_asc_explicitly
#define FLAGS_zetasql_use_customized_flex_istream zetasql_reference_impl_functions_uuid_FLAGS_zetasql_use_customized_flex_istream
#define FLAGS_zetasql_type_factory_nesting_depth_limit zetasql_reference_impl_functions_uuid_FLAGS_zetasql_type_factory_nesting_depth_limit
#define FLAGS_nozetasql_type_factory_nesting_depth_limit zetasql_reference_impl_functions_uuid_FLAGS_nozetasql_type_factory_nesting_depth_limit
#define ZetaSqlFlexTokenizerBase zetasql_reference_impl_functions_uuid_ZetaSqlFlexTokenizerBase
#define ZetaSqlFlexLexer zetasql_reference_impl_functions_uuid_ZetaSqlFlexLexer
#define protobuf_google_2fprotobuf_2fdescriptor_2eproto zetasql_reference_impl_functions_uuid_protobuf_google_2fprotobuf_2fdescriptor_2eproto
#define protobuf_google_2fprotobuf_2ftimestamp_2eproto zetasql_reference_impl_functions_uuid_protobuf_google_2fprotobuf_2ftimestamp_2eproto
#define protobuf_google_2fprotobuf_2fany_2eproto zetasql_reference_impl_functions_uuid_protobuf_google_2fprotobuf_2fany_2eproto
#define protobuf_google_2fprotobuf_2fapi_2eproto zetasql_reference_impl_functions_uuid_protobuf_google_2fprotobuf_2fapi_2eproto
#define protobuf_google_2fprotobuf_2fduration_2eproto zetasql_reference_impl_functions_uuid_protobuf_google_2fprotobuf_2fduration_2eproto
#define protobuf_google_2fprotobuf_2fempty_2eproto zetasql_reference_impl_functions_uuid_protobuf_google_2fprotobuf_2fempty_2eproto
#define protobuf_google_2fprotobuf_2ffield_5fmask_2eproto zetasql_reference_impl_functions_uuid_protobuf_google_2fprotobuf_2ffield_5fmask_2eproto
#define protobuf_google_2fprotobuf_2fsource_5fcontext_2eproto zetasql_reference_impl_functions_uuid_protobuf_google_2fprotobuf_2fsource_5fcontext_2eproto
#define protobuf_google_2fprotobuf_2fstruct_2eproto zetasql_reference_impl_functions_uuid_protobuf_google_2fprotobuf_2fstruct_2eproto
#define protobuf_google_2fprotobuf_2ftype_2eproto zetasql_reference_impl_functions_uuid_protobuf_google_2fprotobuf_2ftype_2eproto
#define protobuf_google_2fprotobuf_2fwrappers_2eproto zetasql_reference_impl_functions_uuid_protobuf_google_2fprotobuf_2fwrappers_2eproto
#define protobuf_zetasql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto
#define protobuf_zetasql_2fparser_2fparse_5ftree_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fparser_2fparse_5ftree_2eproto
#define protobuf_zetasql_2fparser_2fast_5fenums_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fparser_2fast_5fenums_2eproto
#define protobuf_zetasql_2fproto_2foptions_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fproto_2foptions_2eproto
#define protobuf_zetasql_2fproto_2fsimple_5fcatalog_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fproto_2fsimple_5fcatalog_2eproto
#define protobuf_zetasql_2fproto_2ffunction_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fproto_2ffunction_2eproto
#define protobuf_zetasql_2fproto_2finternal_5ferror_5flocation_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fproto_2finternal_5ferror_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2fbuiltin_5ffunction_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2fbuiltin_5ffunction_2eproto
#define protobuf_zetasql_2fpublic_2fdeprecation_5fwarning_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2fdeprecation_5fwarning_2eproto
#define protobuf_zetasql_2fpublic_2ffunction_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2ffunction_2eproto
#define protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2foptions_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2foptions_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5ftable_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2fsimple_5ftable_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5fconstant_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2fsimple_5fconstant_2eproto
#define protobuf_zetasql_2fpublic_2fparse_5flocation_5frange_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2fparse_5flocation_5frange_2eproto
#define protobuf_zetasql_2fpublic_2ftype_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2ftype_2eproto
#define protobuf_zetasql_2fpublic_2ftype_5fannotation_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2ftype_5fannotation_2eproto
#define protobuf_zetasql_2fpublic_2fvalue_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2fvalue_2eproto
#define protobuf_zetasql_2fpublic_2ftype_5fparameters_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2ftype_5fparameters_2eproto
#define protobuf_zetasql_2fpublic_2fcollation_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2fcollation_2eproto
#define protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2fannotation_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2fannotation_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5fvalue_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2fsimple_5fvalue_2eproto
#define protobuf_zetasql_2fpublic_2ffunctions_2fdatetime_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2ffunctions_2fdatetime_2eproto
#define protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto
#define protobuf_zetasql_2fpublic_2fproto_2ftype_5fannotation_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fpublic_2fproto_2ftype_5fannotation_2eproto
#define protobuf_zetasql_2freference_5fimpl_2fevaluator_5ftable_5fiterator_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2freference_5fimpl_2fevaluator_5ftable_5fiterator_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fnode_5fkind_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fresolved_5fast_2fresolved_5fnode_5fkind_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_5fenums_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_5fenums_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fserialization_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fresolved_5fast_2fserialization_2eproto
#define protobuf_zetasql_2fscripting_2fscript_5fexception_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fscripting_2fscript_5fexception_2eproto
#define protobuf_zetasql_2fscripting_2fscript_5fexecutor_5fstate_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fscripting_2fscript_5fexecutor_5fstate_2eproto
#define protobuf_zetasql_2fscripting_2fvariable_2eproto zetasql_reference_impl_functions_uuid_protobuf_zetasql_2fscripting_2fvariable_2eproto

#define GO_EXPORT(def) export_zetasql_reference_impl_functions_uuid_ ## def
#define U_ICU_ENTRY_POINT_RENAME(x) GO_EXPORT(x)

// include headers
//#define private public
#include "zetasql/reference_impl/functions/uuid.h"
//#undef private

// include sources
#include "zetasql/reference_impl/functions/uuid.cc"

// include dependencies
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/public/functions/uuid/export.inc"
#include "go-zetasql/reference_impl/evaluation/export.inc"
#include "go-absl/status/statusor/export.inc"

#include "bridge.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "bridge.inc"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* zetasql_reference_impl_functions_uuid_bind_cc */
