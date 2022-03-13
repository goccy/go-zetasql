
#ifndef zetasql_resolved_ast_validator_bind_cc
#define zetasql_resolved_ast_validator_bind_cc

// switch namespace
#define absl zetasql_resolved_ast_validator_absl
#define google zetasql_resolved_ast_validator_google
#define zetasql zetasql_resolved_ast_validator_zetasql
#define zetasql_base zetasql_resolved_ast_validator_zetasql_base
#define zetasql_bison_parser zetasql_resolved_ast_validator_zetasql_bison_parser
#define re2 zetasql_resolved_ast_validator_re2
#define AbslInternalSleepFor zetasql_resolved_ast_validator_AbslInternalSleepFor
#define AbslInternalReportFatalUsageError zetasql_resolved_ast_validator_AbslInternalReportFatalUsageError
#define AbslInternalMutexYield zetasql_resolved_ast_validator_AbslInternalMutexYield
#define AbslInternalPerThreadSemPost zetasql_resolved_ast_validator_AbslInternalPerThreadSemPost
#define AbslInternalPerThreadSemWait zetasql_resolved_ast_validator_AbslInternalPerThreadSemWait
#define AbslContainerInternalSampleEverything zetasql_resolved_ast_validator_AbslContainerInternalSampleEverything
#define AbslInternalSpinLockDelay zetasql_resolved_ast_validator_AbslInternalSpinLockDelay
#define AbslInternalSpinLockWake zetasql_resolved_ast_validator_AbslInternalSpinLockWake
#define AbslInternalAnnotateIgnoreReadsBegin zetasql_resolved_ast_validator_AbslInternalAnnotateIgnoreReadsBegin
#define AbslInternalAnnotateIgnoreReadsEnd zetasql_resolved_ast_validator_AbslInternalAnnotateIgnoreReadsEnd
#define AbslInternalGetFileMappingHint zetasql_resolved_ast_validator_AbslInternalGetFileMappingHint
#define ZetaSqlalloc zetasql_resolved_ast_validator_ZetaSqlalloc
#define ZetaSqlfree zetasql_resolved_ast_validator_ZetaSqlfree
#define ZetaSqlrealloc zetasql_resolved_ast_validator_ZetaSqlrealloc
#define FLAGS_nooutput_asc_explicitly zetasql_resolved_ast_validator_FLAGS_nooutput_asc_explicitly
#define FLAGS_nozetasql_use_customized_flex_istream zetasql_resolved_ast_validator_FLAGS_nozetasql_use_customized_flex_istream
#define FLAGS_output_asc_explicitly zetasql_resolved_ast_validator_FLAGS_output_asc_explicitly
#define FLAGS_zetasql_use_customized_flex_istream zetasql_resolved_ast_validator_FLAGS_zetasql_use_customized_flex_istream
#define FLAGS_zetasql_type_factory_nesting_depth_limit zetasql_resolved_ast_validator_FLAGS_zetasql_type_factory_nesting_depth_limit
#define FLAGS_nozetasql_type_factory_nesting_depth_limit zetasql_resolved_ast_validator_FLAGS_nozetasql_type_factory_nesting_depth_limit
#define ZetaSqlFlexTokenizerBase zetasql_resolved_ast_validator_ZetaSqlFlexTokenizerBase
#define ZetaSqlFlexLexer zetasql_resolved_ast_validator_ZetaSqlFlexLexer
#define protobuf_google_2fprotobuf_2fdescriptor_2eproto zetasql_resolved_ast_validator_protobuf_google_2fprotobuf_2fdescriptor_2eproto
#define protobuf_google_2fprotobuf_2ftimestamp_2eproto zetasql_resolved_ast_validator_protobuf_google_2fprotobuf_2ftimestamp_2eproto
#define protobuf_google_2fprotobuf_2fany_2eproto zetasql_resolved_ast_validator_protobuf_google_2fprotobuf_2fany_2eproto
#define protobuf_google_2fprotobuf_2fapi_2eproto zetasql_resolved_ast_validator_protobuf_google_2fprotobuf_2fapi_2eproto
#define protobuf_google_2fprotobuf_2fduration_2eproto zetasql_resolved_ast_validator_protobuf_google_2fprotobuf_2fduration_2eproto
#define protobuf_google_2fprotobuf_2fempty_2eproto zetasql_resolved_ast_validator_protobuf_google_2fprotobuf_2fempty_2eproto
#define protobuf_google_2fprotobuf_2ffield_5fmask_2eproto zetasql_resolved_ast_validator_protobuf_google_2fprotobuf_2ffield_5fmask_2eproto
#define protobuf_google_2fprotobuf_2fsource_5fcontext_2eproto zetasql_resolved_ast_validator_protobuf_google_2fprotobuf_2fsource_5fcontext_2eproto
#define protobuf_google_2fprotobuf_2fstruct_2eproto zetasql_resolved_ast_validator_protobuf_google_2fprotobuf_2fstruct_2eproto
#define protobuf_google_2fprotobuf_2ftype_2eproto zetasql_resolved_ast_validator_protobuf_google_2fprotobuf_2ftype_2eproto
#define protobuf_google_2fprotobuf_2fwrappers_2eproto zetasql_resolved_ast_validator_protobuf_google_2fprotobuf_2fwrappers_2eproto
#define protobuf_zetasql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto
#define protobuf_zetasql_2fparser_2fparse_5ftree_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fparser_2fparse_5ftree_2eproto
#define protobuf_zetasql_2fparser_2fast_5fenums_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fparser_2fast_5fenums_2eproto
#define protobuf_zetasql_2fproto_2foptions_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fproto_2foptions_2eproto
#define protobuf_zetasql_2fproto_2fsimple_5fcatalog_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fproto_2fsimple_5fcatalog_2eproto
#define protobuf_zetasql_2fproto_2ffunction_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fproto_2ffunction_2eproto
#define protobuf_zetasql_2fproto_2finternal_5ferror_5flocation_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fproto_2finternal_5ferror_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2fbuiltin_5ffunction_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2fbuiltin_5ffunction_2eproto
#define protobuf_zetasql_2fpublic_2fdeprecation_5fwarning_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2fdeprecation_5fwarning_2eproto
#define protobuf_zetasql_2fpublic_2ffunction_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2ffunction_2eproto
#define protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2foptions_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2foptions_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5ftable_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2fsimple_5ftable_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5fconstant_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2fsimple_5fconstant_2eproto
#define protobuf_zetasql_2fpublic_2fparse_5flocation_5frange_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2fparse_5flocation_5frange_2eproto
#define protobuf_zetasql_2fpublic_2ftype_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2ftype_2eproto
#define protobuf_zetasql_2fpublic_2ftype_5fannotation_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2ftype_5fannotation_2eproto
#define protobuf_zetasql_2fpublic_2fvalue_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2fvalue_2eproto
#define protobuf_zetasql_2fpublic_2ftype_5fparameters_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2ftype_5fparameters_2eproto
#define protobuf_zetasql_2fpublic_2fcollation_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2fcollation_2eproto
#define protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto
#define protobuf_zetasql_2fpublic_2fannotation_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2fannotation_2eproto
#define protobuf_zetasql_2fpublic_2fsimple_5fvalue_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2fsimple_5fvalue_2eproto
#define protobuf_zetasql_2fpublic_2ffunctions_2fdatetime_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2ffunctions_2fdatetime_2eproto
#define protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto
#define protobuf_zetasql_2fpublic_2fproto_2ftype_5fannotation_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fpublic_2fproto_2ftype_5fannotation_2eproto
#define protobuf_zetasql_2freference_5fimpl_2fevaluator_5ftable_5fiterator_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2freference_5fimpl_2fevaluator_5ftable_5fiterator_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fnode_5fkind_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fresolved_5fast_2fresolved_5fnode_5fkind_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_5fenums_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_5fenums_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fresolved_5fast_2fresolved_5fast_2eproto
#define protobuf_zetasql_2fresolved_5fast_2fserialization_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fresolved_5fast_2fserialization_2eproto
#define protobuf_zetasql_2fscripting_2fscript_5fexception_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fscripting_2fscript_5fexception_2eproto
#define protobuf_zetasql_2fscripting_2fscript_5fexecutor_5fstate_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fscripting_2fscript_5fexecutor_5fstate_2eproto
#define protobuf_zetasql_2fscripting_2fvariable_2eproto zetasql_resolved_ast_validator_protobuf_zetasql_2fscripting_2fvariable_2eproto

#define GO_EXPORT(def) export_zetasql_resolved_ast_validator_ ## def
#define U_ICU_ENTRY_POINT_RENAME(x) GO_EXPORT(x)

// include headers
//#define private public
#include "zetasql/resolved_ast/validator.h"
//#undef private

// include sources
#include "zetasql/resolved_ast/validator.cc"

// include dependencies
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast_enums_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/rewrite_utils/export.inc"
#include "go-zetasql/analyzer/filter_fields_path_validator/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/stl_util/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/base/varsetter/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/constant/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/function_cc_proto/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/templated_sql_function/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-absl/cleanup/cleanup/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-protobuf/protobuf/export.inc"

#include "bridge.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "bridge.inc"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* zetasql_resolved_ast_validator_bind_cc */
