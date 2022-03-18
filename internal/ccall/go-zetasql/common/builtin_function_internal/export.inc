#ifndef ZETASQL_COMMON_BUILTIN_FUNCTION_INTERNAL_EXPORT_H
#define ZETASQL_COMMON_BUILTIN_FUNCTION_INTERNAL_EXPORT_H

#include "zetasql/common/builtin_function_internal.h"

#include "zetasql/common/builtin_function_internal_1.cc"
#include "zetasql/common/builtin_function_internal_2.cc"
#include "zetasql/common/builtin_function_internal_3.cc"

#if 0
namespace zetasql {

  using ::zetasql::functions::DateTimestampPartToSQL;

  using FunctionIdToNameMap =
    absl::flat_hash_map<FunctionSignatureId, std::string>;
  using NameToFunctionMap = std::map<std::string, std::unique_ptr<Function>>;

  bool ArgumentsAreComparable(const std::vector<InputArgumentType>& arguments,
                              const LanguageOptions& language_options,
                              int* bad_argument_idx) {
    return false;
  }

  bool ArgumentsArrayType(const std::vector<InputArgumentType>& arguments,
                          bool is_array, int* bad_argument_idx) {
    return false;
  }

  std::string InfixFunctionSQL(const std::string& display_name,
                               const std::vector<std::string>& inputs) {
    return "";
  }
  std::string PreUnaryFunctionSQL(const std::string& display_name,
                                  const std::vector<std::string>& inputs) {
    return "";
  }
  std::string PostUnaryFunctionSQL(const std::string& display_name,
                                   const std::vector<std::string>& inputs) {
    return "";
  }
  std::string DateAddOrSubFunctionSQL(const std::string& display_name,
                                      const std::vector<std::string>& inputs) {
    return "";
  }

  std::string CountStarFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string AnonCountStarFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string SupportedSignaturesForAnonCountStarFunction(const std::string& unused_function_name,
                                                          const LanguageOptions& language_options, const Function& function) {
    return "";
  }

  std::string BetweenFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string InListFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string LikeAnyFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string LikeAllFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string CaseWithValueFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string CaseNoValueFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string InArrayFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string LikeAnyArrayFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string LikeAllArrayFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string ParenthesizedArrayFunctionSQL(const std::string& input) {
    return "";
  }

  std::string ArrayAtFunctionSQL(absl::string_view inner_function_name,
                                 const std::vector<std::string>& inputs) {
    return "";
  }

  std::string ArrayAtOffsetFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string ArrayAtOrdinalFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string SafeArrayAtOffsetFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string SubscriptFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string SubscriptWithKeyFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string SubscriptWithOffsetFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string SubscriptWithOrdinalFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string SafeArrayAtOrdinalFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string ProtoMapAtKeySQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string SafeProtoMapAtKeySQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string GenerateDateTimestampArrayFunctionSQL(const std::string& function_name, const std::vector<std::string>& inputs) {
    return "";
  }

  std::string MakeArrayFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string ExtractFunctionSQL(const std::vector<std::string>& inputs) {
    return "";
  }

  std::string ExtractDateOrTimeFunctionSQL(const std::string& date_part, const std::vector<std::string>& inputs) {
    return "";
  }

  bool ArgumentIsStringLiteral(const InputArgumentType& argument) {
    return false;
  }

  template <typename ArgumentType>
  bool AllArgumentsHaveType(const std::vector<ArgumentType>& arguments) {
    return false;
  }

  absl::Status EnsureArgumentsHaveType(absl::string_view function_name,
                                       const std::vector<InputArgumentType>& arguments, ProductMode product_mode) {
    return absl::OkStatus();
  }

  absl::Status EnsureArgumentsHaveType(absl::string_view function_name,
                                       const std::vector<InputArgumentType>& arguments,
                                       const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckDateDatetimeTimeTimestampDiffArguments(const std::string& function_name,
                                                           const std::vector<InputArgumentType>& arguments,
                                                           const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckBitwiseOperatorArgumentsHaveSameType(const std::string& operator_string,
                                                         const std::vector<InputArgumentType>& arguments,
                                                         const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckBitwiseOperatorFirstArgumentIsIntegerOrBytes(const std::string& operator_string,
                                                                 const std::vector<InputArgumentType>& arguments,
                                                                 const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckDateDatetimeTimeTimestampTruncArguments(const std::string& function_name,
                                                            const std::vector<InputArgumentType>& arguments,
                                                            const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckLastDayArguments(const std::string& function_name,
                                     const std::vector<InputArgumentType>& arguments,
                                     const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckExtractPreResolutionArguments(const std::vector<InputArgumentType>& arguments,
                                                  const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckExtractPostResolutionArguments(const FunctionSignature& /*signature*/,
                                                   const std::vector<InputArgumentType>& arguments,
                                                   const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckDateDatetimeTimestampAddSubArguments(const std::string& function_name,
                                                         const std::vector<InputArgumentType>& arguments,
                                                         const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckTimeAddSubArguments(const std::string& function_name,
                                        const std::vector<InputArgumentType>& arguments,
                                        const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckGenerateDateArrayArguments(const std::vector<InputArgumentType>& arguments,
                                               const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckGenerateTimestampArrayArguments(const std::vector<InputArgumentType>& arguments,
                                                    const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckJsonArguments(const std::vector<InputArgumentType>& arguments,
                                  const LanguageOptions& options) {
    return absl::OkStatus();
  }

  absl::Status CheckFormatPostResolutionArguments(const FunctionSignature& /*signature*/,
                                                  const std::vector<InputArgumentType>& arguments,
                                                  const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckIsSupportedKeyType(absl::string_view function_name,
                                       const std::set<std::string>& supported_key_types,
                                       int key_type_argument_index,
                                       const std::vector<InputArgumentType>& arguments,
                                       const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  const std::set<std::string>& GetSupportedKeyTypes() {
    std::set<std::string> *v;
    return *v;
  }

  const std::set<std::string>& GetSupportedRawKeyTypes() {
    std::set<std::string> *v;
    return *v;
  }

  bool IsStringLiteralComparedToBytes(const InputArgumentType& lhs_arg,
                                      const InputArgumentType& rhs_arg) {
    return false;
  }

  std::string NoMatchingSignatureForCaseNoValueFunction(const std::string& qualified_function_name,
                                                        const std::vector<InputArgumentType>& arguments, ProductMode product_mode) {
    return "";
  }

  std::string NoMatchingSignatureForInFunction(const std::string& qualified_function_name,
                                               const std::vector<InputArgumentType>& arguments, ProductMode product_mode) {
    return "";
  }

  std::string NoMatchingSignatureForInArrayFunction(const std::string& qualified_function_name,
                                                    const std::vector<InputArgumentType>& arguments, ProductMode product_mode) {
    return "";
  }

  std::string NoMatchingSignatureForLikeExprFunction(const std::string& qualified_function_name,
                                                     const std::vector<InputArgumentType>& arguments, ProductMode product_mode) {
    return "";
  }
  std::string NoMatchingSignatureForLikeExprArrayFunction(const std::string& qualified_function_name,
                                                          const std::vector<InputArgumentType>& arguments, ProductMode product_mode) {
    return "";
  }

  std::string NoMatchingSignatureForComparisonOperator(const std::string& operator_name,
                                                       const std::vector<InputArgumentType>& arguments, ProductMode product_mode) {
    return "";
  }

  std::string NoMatchingSignatureForFunctionUsingInterval(const std::string& qualified_function_name,
                                                          const std::vector<InputArgumentType>& arguments, ProductMode product_mode,
                                                          int index_of_interval_argument) {
    return "";
  }

  std::string NoMatchingSignatureForDateOrTimeAddOrSubFunction(const std::string& qualified_function_name,
                                                               const std::vector<InputArgumentType>& arguments, ProductMode product_mode) {
    return "";
  }

  std::string NoMatchingSignatureForGenerateDateOrTimestampArrayFunction(const std::string& qualified_function_name,
                                                                         const std::vector<InputArgumentType>& arguments, ProductMode product_mode) {
    return "";
  }

  template <class ArgumentType>
  std::string GetExtractFunctionSignatureString(const std::string& explicit_datepart_name,
                                                const std::vector<ArgumentType>& arguments, ProductMode product_mode,
                                                bool include_bracket) {
    return "";
  }

  std::string NoMatchingSignatureForExtractFunction(const std::string& explicit_datepart_name,
                                                    const std::string& qualified_function_name,
                                                    const std::vector<InputArgumentType>& arguments, ProductMode product_mode) {
    return "";
  }

  std::string ExtractSupportedSignatures(const std::string& explicit_datepart_name,
                                         const LanguageOptions& language_options, const Function& function) {
    return "";
  }

  std::string NoMatchingSignatureForSubscript(absl::string_view offset_or_ordinal, absl::string_view operator_name,
                                              const std::vector<InputArgumentType>& arguments, ProductMode product_mode) {
    return "";
  }

  std::string EmptySupportedSignatures(const LanguageOptions& language_options,
                                       const Function& function) {
    return "";
  }

  absl::Status CheckArgumentsSupportEquality(const std::string& comparison_name,
                                             const FunctionSignature& signature,
                                             const std::vector<InputArgumentType>& arguments,
                                             const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckArgumentsSupportGrouping(const std::string& comparison_name, const FunctionSignature& signature,
                                             const std::vector<InputArgumentType>& arguments,
                                             const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::StatusOr<const Type*> GetOrMakeEnumValueDescriptorType(Catalog* catalog, TypeFactory* type_factory, CycleDetector* cycle,
                                                               const FunctionSignature& /*signature*/,
                                                               const std::vector<InputArgumentType>& arguments,
                                                               const AnalyzerOptions& analyzer_options) {
    absl::StatusOr<const Type*> v;
    return v;
  }

  absl::Status PreResolutionCheckArgumentsSupportComparison(const std::string& comparison_name,
                                                            const std::vector<InputArgumentType>& arguments,
                                                            const LanguageOptions& language_options) {
     return absl::OkStatus();
  }

  absl::Status CheckArgumentsSupportComparison(const std::string& comparison_name,
                                               const FunctionSignature& /*signature*/,
                                               const std::vector<InputArgumentType>& arguments,
                                               const LanguageOptions& language_options) {
     return absl::OkStatus();
  }

  absl::Status CheckMinMaxArguments(const std::string& function_name,
                                    const std::vector<InputArgumentType>& arguments,
                                    const LanguageOptions& language_options) {
     return absl::OkStatus();
  }

  absl::Status CheckGreatestLeastArguments(const std::string& function_name,
                                           const std::vector<InputArgumentType>& arguments,
                                           const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckFirstArgumentSupportsEquality(const std::string& comparison_name,
                                                  const std::vector<InputArgumentType>& arguments,
                                                  const LanguageOptions& language_options) {
     return absl::OkStatus();
  }

  absl::Status CheckArrayAggArguments(const std::vector<InputArgumentType>& arguments,
                                      const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckArrayConcatArguments(const std::vector<InputArgumentType>& arguments,
                                         const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckArrayIsDistinctArguments(const std::vector<InputArgumentType>& arguments,
                                             const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckInArrayArguments(const std::vector<InputArgumentType>& arguments,
                                     const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckLikeExprArrayArguments(const std::vector<InputArgumentType>& arguments,
                                           const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  absl::Status CheckRangeBucketArguments(const std::vector<InputArgumentType>& arguments,
                                         const LanguageOptions& language_options) {
    return absl::OkStatus();
  }

  std::string AnonCountStarBadArgumentErrorPrefix(const FunctionSignature&,
                                                  int idx) {
    return "";
  }

  FunctionOptions DefaultAggregateFunctionOptions() {
    FunctionOptions v;
    return v;
  }

  bool CanStringConcatCoerceFrom(const zetasql::Type* arg_type) {
    return false;
  }

  bool HasFloatingPointArgument(const FunctionSignature& matched_signature,
                                const std::vector<InputArgumentType>& arguments) {
    return false;
  }

  bool HasNumericTypeArgument(const FunctionSignature& matched_signature,
                              const std::vector<InputArgumentType>& arguments) {
    return false;
  }

  bool AllArgumentsHaveNumericOrBigNumericType(const FunctionSignature& matched_signature,
                                               const std::vector<InputArgumentType>& arguments) {
    return false;
  }

  bool LastArgumentHasNumericOrBigNumericType(const FunctionSignature& matched_signature,
                                              const std::vector<InputArgumentType>& arguments) {
    return false;
  }

  bool HasBigNumericTypeArgument(const FunctionSignature& matched_signature,
                                 const std::vector<InputArgumentType>& arguments) {
    return false;
  }

  bool HasIntervalTypeArgument(const FunctionSignature& matched_signature,
                               const std::vector<InputArgumentType>& arguments) {
    return false;
  }

  absl::StatusOr<const Type*> ComputeResultTypeForTopStruct(const std::string& field2_name, Catalog* catalog, TypeFactory* type_factory,
                                                            CycleDetector* cycle_detector,
                                                            const FunctionSignature& /*signature*/,
                                                            const std::vector<InputArgumentType>& arguments,
                                                            const AnalyzerOptions& analyzer_options) {
    absl::StatusOr<const Type*> v;
    return v;
  }

  absl::StatusOr<const Type*> ComputeResultTypeForNearestNeighborsStruct(Catalog* catalog, TypeFactory* type_factory, CycleDetector* cycle_detector,
                                                                         const FunctionSignature& /*signature*/,
                                                                         const std::vector<InputArgumentType>& arguments,
                                                                         const AnalyzerOptions& analyzer_options) {
    absl::StatusOr<const Type*> v;
    return v;
  }

  void InsertCreatedFunction(NameToFunctionMap* functions,
                             const ZetaSQLBuiltinFunctionOptions& options,
                             Function* function_in) {
  }

  void InsertFunction(NameToFunctionMap* functions,
                      const ZetaSQLBuiltinFunctionOptions& options,
                      absl::string_view name, Function::Mode mode,
                      const std::vector<FunctionSignatureOnHeap>& signatures,
                      FunctionOptions function_options) {
  }

  void InsertFunction(NameToFunctionMap* functions,
                      const ZetaSQLBuiltinFunctionOptions& options,
                      absl::string_view name, Function::Mode mode,
                      const std::vector<FunctionSignatureOnHeap>& signatures) {
  }

  void InsertSimpleFunction(NameToFunctionMap* functions,
                            const ZetaSQLBuiltinFunctionOptions& options, absl::string_view name,
                            Function::Mode mode,
                            std::initializer_list<FunctionSignatureProxy> signatures) {
  }

  void InsertSimpleFunction(NameToFunctionMap* functions,
                            const ZetaSQLBuiltinFunctionOptions& options, absl::string_view name,
                            Function::Mode mode,
                            std::initializer_list<FunctionSignatureProxy> signatures,
                            const FunctionOptions& function_options) {
  }

  void InsertNamespaceFunction(NameToFunctionMap* functions,
                               const ZetaSQLBuiltinFunctionOptions& options, absl::string_view space,
                               absl::string_view name, Function::Mode mode,
                               const std::vector<FunctionSignatureOnHeap>& signatures) {
  }

  void InsertNamespaceFunction(NameToFunctionMap* functions,
                               const ZetaSQLBuiltinFunctionOptions& options, absl::string_view space,
                               absl::string_view name, Function::Mode mode,
                               const std::vector<FunctionSignatureOnHeap>& signatures,
                               FunctionOptions function_options) {
  }

  void InsertSimpleNamespaceFunction(NameToFunctionMap* functions,
                                     const ZetaSQLBuiltinFunctionOptions& options, absl::string_view space,
                                     absl::string_view name, Function::Mode mode,
                                     std::initializer_list<FunctionSignatureProxy> signatures) {
  }

  void InsertSimpleNamespaceFunction(NameToFunctionMap* functions,
                                     const ZetaSQLBuiltinFunctionOptions& options, absl::string_view space,
                                     absl::string_view name, Function::Mode mode,
                                     std::initializer_list<FunctionSignatureProxy> signatures,
                                     FunctionOptions function_options) {
  }

}
#endif

#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/proto/options_cc_proto/export.inc"
#include "go-zetasql/public/anon_function/export.inc"
#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-zetasql/public/builtin_function_options/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/cycle_detector/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/function_cc_proto/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-zetasql/public/functions/datetime_cc_proto/export.inc"
#include "go-zetasql/public/functions/string_format/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
