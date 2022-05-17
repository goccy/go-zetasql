#ifndef ZETASQL_PUBLIC_FUNCTIONS_STRING_FORMAT_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_STRING_FORMAT_EXPORT_H

#include "zetasql/public/functions/string_format.h"
#include "zetasql/public/functions/string_format.cc"

#if 0
namespace zetasql {
  namespace functions {
    namespace string_format_internal {

      bool StringFormatEvaluator::ValueAsString(const Value& value, int64_t var_index) {
        return false;
      }

      StringFormatEvaluator::StringFormatEvaluator(ProductMode product_mode)
        : product_mode_(product_mode), type_resolver_(nullptr), status_() {}

      absl::Status StringFormatEvaluator::SetPattern(absl::string_view pattern) {
        absl::Status v;
        return v;
      }

      absl::Status StringFormatEvaluator::SetTypes(std::vector<const Type*> arg_types,
                                                   google::protobuf::DynamicMessageFactory* factory) {
        absl::Status v;
        return v;
      }

      bool StringFormatEvaluator::ProcessType(const Type* arg_type) {
        return false;
      }

      void StringFormatEvaluator::ProcessTypes() {
      }

      absl::Status StringFormatEvaluator::Format(absl::Span<const Value> values,
                                                 std::string* output, bool* is_null) {
        absl::Status v;
        return v;
      }

      absl::Status StringFormatEvaluator::FormatString(const std::vector<absl::string_view>& raw_parts,
                                                       const std::vector<FormatPart>& format_parts, absl::Cord* out,
                                                       bool* set_null) {
        absl::Status v;
        return v;
      }

      FormatPart::SetterFn StringFormatEvaluator::MakeCopyValueSetter(int64_t index) {
        FormatPart::SetterFn v;
        return v;
      }

      bool StringFormatEvaluator::ValueAsStringSetter(const FormatPart& part,
                                                      absl::FormatArg* arg) {
        return false;
      }

      bool StringFormatEvaluator::ValueLiteralSetter(const FormatPart& part,
                                                     absl::FormatArg* arg) {
        return false;
      }

      template <typename T>
      bool StringFormatEvaluator::CopyValueSetter(const FormatPart& part,
                                                  absl::FormatArg* arg) {
        return false;
      }

      bool StringFormatEvaluator::CopyStringSetter(const FormatPart& part,
                                                   absl::FormatArg* arg) {
        return false;
      }

      FormatPart::SetterFn StringFormatEvaluator::MakeCopyWidthSetter(int64_t index) {
        FormatPart::SetterFn v;
        return v;
      }

      template <typename T>
      bool StringFormatEvaluator::CopyWidthSetter(const FormatPart& part,
                                                  absl::FormatArg* arg) {
        return false;
      }

      FormatPart::SetterFn StringFormatEvaluator::MakeCopyPrecisionSetter(int64_t index) {
        FormatPart::SetterFn v;
        return v;
      }

      template <typename T>
      bool StringFormatEvaluator::CopyPrecisionSetter(const FormatPart& part,
                                                      absl::FormatArg* arg) {
        return false;
      }

      template <bool GROUPING>
      FormatPart::SetterFn StringFormatEvaluator::MakeCopyIntCustom(int64_t index) {
        FormatPart::SetterFn v;
        return v;
      }

      template <typename T, bool GROUPING>
      bool StringFormatEvaluator::CopyIntCustom(const FormatPart& part,
                                                absl::FormatArg* arg) {
        return false;
      }

      template <typename T, bool GROUPING>
      bool StringFormatEvaluator::CopyDoubleCustom(const FormatPart& part,
                                                   absl::FormatArg* arg) {
        return false;
      }

      template <bool GROUPING>
      bool StringFormatEvaluator::CopyNumericCustom(const FormatPart& part,
                                                    absl::FormatArg* arg) {
        return false;
      }

      template <bool GROUPING>
      bool StringFormatEvaluator::CopyBigNumericCustom(const FormatPart& part,
                                                       absl::FormatArg* arg) {
        return false;
      }

      bool StringFormatEvaluator::PrintProto(const Value& value, bool single_line,
                                             bool print_null,  // if false and value.is_null(), this returns false.
                                             bool quote, int64_t var_index) {
        return false;
      }

      template <bool single_line, bool print_null, bool quote>
      bool StringFormatEvaluator::PrintProtoSetter(const FormatPart& part,
                                                   absl::FormatArg* arg) {
        return false;
      }

      bool StringFormatEvaluator::PrintJson(const Value& value, bool single_line,
                                            int64_t var_index) {
        return false;
      }

      template <bool single_line>
      bool StringFormatEvaluator::PrintJsonSetter(const FormatPart& part,
                                                  absl::FormatArg* arg) {
        return false;
      }

      FormatPart::SetterFn StringFormatEvaluator::MakeValueAsStringSetter(int64_t index) {
        FormatPart::SetterFn v;
        return v;
      }

      FormatPart::SetterFn StringFormatEvaluator::MakeValueLiteralSetter(int64_t index) {
        FormatPart::SetterFn v;
        return v;
      }

      bool StringFormatEvaluator::ProcessPattern() {
        return false;
      }

      absl::Status StringFormatEvaluator::TypeError(int64_t arg_index,
                                                    absl::string_view expected,
                                                    const Type* actual) const {
        absl::Status v;
        return v;
      }

      absl::Status StringFormatEvaluator::ValueError(int64_t arg_index,
                                                     absl::string_view error) const {
        absl::Status v;
        return v;
      }

      bool StringFormatEvaluator::TypeCheckSIntArg(int64_t arg_index) {
        return false;
      }

      bool StringFormatEvaluator::TypeCheckUintArg(int64_t arg_index) {
        return false;
      }

      bool StringFormatEvaluator::TypeCheckIntOrUintArg(int64_t arg_index) {
        return false;
      }

      bool StringFormatEvaluator::TypeCheckDoubleArg(int64_t arg_index) {
        return false;
      }

      bool StringFormatEvaluator::TypeCheckDoubleOrNumericArg(int64_t arg_index) {
        return false;
      }

      bool StringFormatEvaluator::TypeCheckStringArg(int64_t arg_index) {
        return false;
      }

      bool StringFormatEvaluator::TypeCheckProtoOrJsonArg(int64_t arg_index) {
        return false;
      }

      absl::FormatConvertResult<absl::FormatConversionCharSet::s> AbslFormatConvert(const FormatGsqlString& value, const absl::FormatConversionSpec& conv, absl::FormatSink* sink) {
        return {false};
      }

      template <bool GROUPING>
      absl::FormatConvertResult<absl::FormatConversionCharSet::kIntegral> ConvertInt(uint64_t magnitude, bool negative, const absl::FormatConversionSpec& conv, absl::FormatSink* sink) {
        return {false};
      }

      template <bool GROUPING>
      bool FormatConvert(const FormatGsqlInt64<GROUPING>& value,
                         const absl::FormatConversionSpec& conv, absl::Cord* sink) {
        return false;
      }

      template <bool GROUPING>
      absl::FormatConvertResult<absl::FormatConversionCharSet::kIntegral>
      AbslFormatConvert(const FormatGsqlInt64<GROUPING>& value,
                        const absl::FormatConversionSpec& conv,
                        absl::FormatSink* sink) {
        absl::FormatConvertResult<absl::FormatConversionCharSet::kIntegral> v;
        return v;
      }

      template <bool GROUPING>
      absl::FormatConvertResult<absl::FormatConversionCharSet::kIntegral>
      AbslFormatConvert(const FormatGsqlUint64<GROUPING>& value,
                        const absl::FormatConversionSpec& conv,
                        absl::FormatSink* sink) {
        absl::FormatConvertResult<absl::FormatConversionCharSet::kIntegral> v;
        return v;
      }

      template <bool GROUPING>
      absl::FormatConvertResult<absl::FormatConversionCharSet::kFloating>
      AbslFormatConvert(const FormatGsqlDouble<GROUPING>& value,
                        const absl::FormatConversionSpec& conv,
                        absl::FormatSink* sink) {
        return {false};
      }

      template <typename NumericType, bool GROUPING>
      absl::FormatConvertResult<absl::FormatConversionCharSet::kFloating>
      AbslFormatConvert(const FormatGsqlNumeric<NumericType, GROUPING>& value,
                        const absl::FormatConversionSpec& conv,
                        absl::FormatSink* sink) {
        return {false};
      }

    }

    absl::Status StringFormatUtf8(absl::string_view format_string,
                                  absl::Span<const Value> values,
                                  ProductMode product_mode, std::string* output,
                                  bool* is_null) {
      absl::Status v;
      return v;
    }

    absl::Status CheckStringFormatUtf8ArgumentTypes(absl::string_view format_string,
                                                    std::vector<const Type*> types,
                                                    ProductMode product_mode) {
      absl::Status v;
      return v;
    }

  }
}
#endif

#include "go-zetasql/public/functions/convert_proto/export.inc"
#include "go-zetasql/public/functions/format_max_output_width/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/utf_util/export.inc"
#include "go-zetasql/public/numeric_value/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/cord/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-absl/types/span/export.inc"
#include "go-protobuf/protobuf/export.inc"
#include "go-re2/re2/export.inc"
#include "go-icu/icu/export.inc"

#endif
