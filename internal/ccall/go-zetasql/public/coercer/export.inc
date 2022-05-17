#ifndef ZETASQL_PUBLIC_COERCER_EXPORT_H
#define ZETASQL_PUBLIC_COERCER_EXPORT_H

#include "zetasql/public/cast.h"
#include "zetasql/public/coercer.h"

#define FCT GO_EXPORT(cast_FCT)
#include "zetasql/public/cast.cc"
#undef FCT

#include "zetasql/public/coercer.cc"

#if 0
namespace zetasql {

  bool SupportsImplicitCoercion(CastFunctionType type) {
    return false;
  }

  bool SupportsLiteralCoercion(CastFunctionType type) {
    return false;
  }

  bool SupportsParameterCoercion(CastFunctionType type) {
    return false;
  }

  bool SupportsExplicitCast(CastFunctionType type) {
    return false;
  }

  absl::StatusOr<Value> CastValue(const Value& from_value,
                                  absl::TimeZone default_timezone,
                                  const LanguageOptions& language_options,
                                  const Type* to_type, Catalog* catalog) {
    absl::StatusOr<Value> v;
    return v;
  }

  absl::StatusOr<Value> CastValue(const Value& from_value,
                                  absl::TimeZone default_timezone,
                                  const LanguageOptions& language_options,
                                  const Type* to_type,
                                  const absl::optional<std::string>& format,
                                  Catalog* catalog) {
    absl::StatusOr<Value> v;
    return v;
  }

  namespace internal {

    absl::StatusOr<Value> CastValueWithoutTypeValidation(
                                                         const Value& from_value, absl::TimeZone default_timezone,
                                                         absl::optional<absl::Time> current_timestamp,
                                                         const LanguageOptions& language_options, const Type* to_type,
                                                         const absl::optional<std::string>& format,
                                                         const absl::optional<std::string>& explicit_time_zone,
                                                         const ExtendedCompositeCastEvaluator* extended_cast_evaluator) {
      absl::StatusOr<Value> v;
      return v;
    }

    const CastHashMap& GetZetaSQLCasts() {
      return nullptr;
    }

    const CastFormatMap& GetCastFormatMap() {
      return nullptr;
    }

  }

  absl::StatusOr<ConversionEvaluator> ConversionEvaluator::Create(const Type* from_type, const Type* to_type, const Function* function) {
    absl::StatusOr<ConversionEvaluator> v;
    return v;
  }

  FunctionSignature ConversionEvaluator::GetFunctionSignature(const Type* from_type, const Type* to_type) {
    FunctionSignature v;
    return v;
  }

  absl::StatusOr<Value> ConversionEvaluator::Eval(const Value& from_value) const {
    absl::StatusOr<Value> v;
    return v;
  }

  absl::StatusOr<Conversion> Conversion::Create(const Type* from_type, const Type* to_type, const Function* function,
                                                const CastFunctionProperty& property) {
    absl::StatusOr<Conversion> v;
    return v;
  }

  absl::StatusOr<Conversion> Conversion::Create(const ConversionEvaluator& evaluator,
                                                const CastFunctionProperty& property) {
    absl::StatusOr<Conversion> v;
    return v;
  }

  bool Conversion::IsMatch(const Catalog::FindConversionOptions& options) const {
    return false;
  }

  absl::StatusOr<Value> ExtendedCompositeCastEvaluator::Eval(const Value& from_value, const Type* to_type) const {
    absl::StatusOr<Value> v;
    return v;
  }

}
#endif

#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/civil_time/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/numeric_value/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/proto_value_conversion/export.inc"
#include "go-zetasql/public/signature_match_result/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/internal_value/export.inc"
#include "go-zetasql/common/utf_util/export.inc"
#include "go-zetasql/public/functions/cast_date_time/export.inc"
#include "go-zetasql/public/functions/convert/export.inc"
#include "go-zetasql/public/functions/convert_proto/export.inc"
#include "go-zetasql/public/functions/convert_string/export.inc"
#include "go-zetasql/public/functions/convert_string_with_format/export.inc"
#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-zetasql/public/functions/datetime_cc_proto/export.inc"
#include "go-zetasql/public/functions/string/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-absl/algorithm/container/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/cord/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-absl/types/optional/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
