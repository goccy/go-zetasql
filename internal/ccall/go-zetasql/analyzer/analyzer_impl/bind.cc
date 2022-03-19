
#ifndef zetasql_analyzer_analyzer_impl_bind_cc
#define zetasql_analyzer_analyzer_impl_bind_cc

// switch namespace
#define absl zetasql_analyzer_analyzer_impl_absl
#define google zetasql_analyzer_analyzer_impl_google
#define zetasql zetasql_analyzer_analyzer_impl_zetasql
#define zetasql_base zetasql_analyzer_analyzer_impl_zetasql_base
#define zetasql_bison_parser zetasql_analyzer_analyzer_impl_zetasql_bison_parser
#define re2 zetasql_analyzer_analyzer_impl_re2
#define AbslInternalSleepFor zetasql_analyzer_analyzer_impl_AbslInternalSleepFor
#define AbslInternalReportFatalUsageError zetasql_analyzer_analyzer_impl_AbslInternalReportFatalUsageError
#define AbslInternalMutexYield zetasql_analyzer_analyzer_impl_AbslInternalMutexYield
#define AbslInternalPerThreadSemPost zetasql_analyzer_analyzer_impl_AbslInternalPerThreadSemPost
#define AbslInternalPerThreadSemWait zetasql_analyzer_analyzer_impl_AbslInternalPerThreadSemWait
#define AbslContainerInternalSampleEverything zetasql_analyzer_analyzer_impl_AbslContainerInternalSampleEverything
#define AbslInternalSpinLockDelay zetasql_analyzer_analyzer_impl_AbslInternalSpinLockDelay
#define AbslInternalSpinLockWake zetasql_analyzer_analyzer_impl_AbslInternalSpinLockWake
#define AbslInternalAnnotateIgnoreReadsBegin zetasql_analyzer_analyzer_impl_AbslInternalAnnotateIgnoreReadsBegin
#define AbslInternalAnnotateIgnoreReadsEnd zetasql_analyzer_analyzer_impl_AbslInternalAnnotateIgnoreReadsEnd
#define AbslInternalGetFileMappingHint zetasql_analyzer_analyzer_impl_AbslInternalGetFileMappingHint
#define ZetaSqlalloc zetasql_analyzer_analyzer_impl_ZetaSqlalloc
#define ZetaSqlfree zetasql_analyzer_analyzer_impl_ZetaSqlfree
#define ZetaSqlrealloc zetasql_analyzer_analyzer_impl_ZetaSqlrealloc
#define FLAGS_nooutput_asc_explicitly zetasql_analyzer_analyzer_impl_FLAGS_nooutput_asc_explicitly
#define FLAGS_nozetasql_use_customized_flex_istream zetasql_analyzer_analyzer_impl_FLAGS_nozetasql_use_customized_flex_istream
#define FLAGS_output_asc_explicitly zetasql_analyzer_analyzer_impl_FLAGS_output_asc_explicitly
#define FLAGS_zetasql_use_customized_flex_istream zetasql_analyzer_analyzer_impl_FLAGS_zetasql_use_customized_flex_istream
#define FLAGS_zetasql_type_factory_nesting_depth_limit zetasql_analyzer_analyzer_impl_FLAGS_zetasql_type_factory_nesting_depth_limit
#define FLAGS_zetasql_read_proto_field_optimized_path zetasql_analyzer_analyzer_impl_FLAGS_zetasql_read_proto_field_optimized_path
#define FLAGS_nozetasql_type_factory_nesting_depth_limit zetasql_analyzer_analyzer_impl_FLAGS_nozetasql_type_factory_nesting_depth_limit
#define FLAGS_nozetasql_read_proto_field_optimized_path zetasql_analyzer_analyzer_impl_FLAGS_nozetasql_read_proto_field_optimized_path
#define ZetaSqlFlexTokenizerBase zetasql_analyzer_analyzer_impl_ZetaSqlFlexTokenizerBase
#define ZetaSqlFlexLexer zetasql_analyzer_analyzer_impl_ZetaSqlFlexLexer
#define UCaseMap zetasql_analyzer_analyzer_impl_UCaseMap
#define protobuf_google_2fprotobuf_2fdescriptor_2eproto zetasql_analyzer_analyzer_impl_protobuf_google_2fprotobuf_2fdescriptor_2eproto
#define protobuf_google_2fprotobuf_2ftimestamp_2eproto zetasql_analyzer_analyzer_impl_protobuf_google_2fprotobuf_2ftimestamp_2eproto
#define protobuf_google_2fprotobuf_2fany_2eproto zetasql_analyzer_analyzer_impl_protobuf_google_2fprotobuf_2fany_2eproto
#define protobuf_google_2fprotobuf_2fapi_2eproto zetasql_analyzer_analyzer_impl_protobuf_google_2fprotobuf_2fapi_2eproto
#define protobuf_google_2fprotobuf_2fduration_2eproto zetasql_analyzer_analyzer_impl_protobuf_google_2fprotobuf_2fduration_2eproto
#define protobuf_google_2fprotobuf_2fempty_2eproto zetasql_analyzer_analyzer_impl_protobuf_google_2fprotobuf_2fempty_2eproto
#define protobuf_google_2fprotobuf_2ffield_5fmask_2eproto zetasql_analyzer_analyzer_impl_protobuf_google_2fprotobuf_2ffield_5fmask_2eproto
#define protobuf_google_2fprotobuf_2fsource_5fcontext_2eproto zetasql_analyzer_analyzer_impl_protobuf_google_2fprotobuf_2fsource_5fcontext_2eproto
#define protobuf_google_2fprotobuf_2fstruct_2eproto zetasql_analyzer_analyzer_impl_protobuf_google_2fprotobuf_2fstruct_2eproto
#define protobuf_google_2fprotobuf_2ftype_2eproto zetasql_analyzer_analyzer_impl_protobuf_google_2fprotobuf_2ftype_2eproto
#define protobuf_google_2fprotobuf_2fwrappers_2eproto zetasql_analyzer_analyzer_impl_protobuf_google_2fprotobuf_2fwrappers_2eproto
#define protobuf_google_2ftype_2fdate_2eproto zetasql_analyzer_analyzer_impl_protobuf_google_2ftype_2fdate_2eproto
#define protobuf_google_2ftype_2flatlng_2eproto zetasql_analyzer_analyzer_impl_protobuf_google_2ftype_2flatlng_2eproto
#define protobuf_google_2ftype_2ftimeofday_2eproto zetasql_analyzer_analyzer_impl_protobuf_google_2ftype_2ftimeofday_2eproto
#define protobuf_zetasql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto
#define protobuf_zetasql_2fparser_2fparse_5ftree_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fparser_2fparse_5ftree_2eproto
#define protobuf_zetasql_2fparser_2fast_5fenums_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fparser_2fast_5fenums_2eproto
#define protobuf_zetasql_2fproto_2foptions_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fproto_2foptions_2eproto
#define protobuf_zetasql_2fproto_2fsimple_5fcatalog_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fproto_2fsimple_5fcatalog_2eproto
#define protobuf_zetasql_2fproto_2ffunction_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fproto_2ffunction_2eproto
#define protobuf_zetasql_2fproto_2finternal_5ferror_5flocation_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fproto_2finternal_5ferror_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2fbuiltin_5ffunction_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2fbuiltin_5ffunction_2eproto
#define protobuf_zetasql_2fpublic_2fdeprecation_5fwarning_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2fdeprecation_5fwarning_2eproto
#define protobuf_zetasql_2fpublic_2ffunction_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2ffunction_2eproto
#define protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2foptions_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2foptions_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5ftable_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2fsimple_5ftable_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5fconstant_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2fsimple_5fconstant_2eproto
#define protobuf_zetasql_2fpublic_2fparse_5flocation_5frange_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2fparse_5flocation_5frange_2eproto
#define protobuf_zetasql_2fpublic_2ftype_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2ftype_2eproto
#define protobuf_zetasql_2fpublic_2ftype_5fannotation_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2ftype_5fannotation_2eproto
#define protobuf_zetasql_2fpublic_2fvalue_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2fvalue_2eproto
#define protobuf_zetasql_2fpublic_2ftype_5fparameters_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2ftype_5fparameters_2eproto
#define protobuf_zetasql_2fpublic_2fcollation_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2fcollation_2eproto
#define protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2fannotation_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2fannotation_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5fvalue_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2fsimple_5fvalue_2eproto
#define protobuf_zetasql_2fpublic_2ffunctions_2fdatetime_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2ffunctions_2fdatetime_2eproto
#define protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto
#define protobuf_zetasql_2fpublic_2fproto_2ftype_5fannotation_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fpublic_2fproto_2ftype_5fannotation_2eproto
#define protobuf_zetasql_2freference_5fimpl_2fevaluator_5ftable_5fiterator_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2freference_5fimpl_2fevaluator_5ftable_5fiterator_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fnode_5fkind_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fresolved_5fast_2fresolved_5fnode_5fkind_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_5fenums_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_5fenums_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fserialization_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fresolved_5fast_2fserialization_2eproto
#define protobuf_zetasql_2fscripting_2fscript_5fexception_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fscripting_2fscript_5fexception_2eproto
#define protobuf_zetasql_2fscripting_2fscript_5fexecutor_5fstate_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fscripting_2fscript_5fexecutor_5fstate_2eproto
#define protobuf_zetasql_2fscripting_2fvariable_2eproto zetasql_analyzer_analyzer_impl_protobuf_zetasql_2fscripting_2fvariable_2eproto

#define GO_EXPORT(def) export_zetasql_analyzer_analyzer_impl_ ## def
#define U_ICU_ENTRY_POINT_RENAME(x) GO_EXPORT(x)

// include headers
//#define private public
#include "zetasql/analyzer/analyzer_impl.h"
//#undef private

// include sources
#include "zetasql/analyzer/analyzer_impl.cc"

// include dependencies
#include "go-zetasql/analyzer/resolver/export.inc"
#include "go-zetasql/analyzer/rewrite_resolved_ast/export.inc"
#include "go-zetasql/analyzer/rewriters/rewriter_interface/export.inc"
#include "go-zetasql/base/logging/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/analyzer_output/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/validator/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"

#include "bridge.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "bridge.inc"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* zetasql_analyzer_analyzer_impl_bind_cc */
