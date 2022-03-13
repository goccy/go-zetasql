#ifndef ZETASQL_PUBLIC_LANGUAGE_OPTIONS_EXPORT_H
#define ZETASQL_PUBLIC_LANGUAGE_OPTIONS_EXPORT_H

#include "zetasql/public/language_options.h"
#include "zetasql/public/language_options.cc"

#if 0
namespace zetasql {

  LanguageOptions::LanguageFeatureSet
  LanguageOptions::GetLanguageFeaturesForVersion(LanguageVersion version) {
    LanguageOptions::LanguageFeatureSet v;
    return v;
  }

  void LanguageOptions::SetLanguageVersion(LanguageVersion version) {
  }

  LanguageOptions LanguageOptions::MaximumFeatures() {
    LanguageOptions v;
    return v;
  }

  std::string LanguageOptions::GetEnabledLanguageFeaturesAsString() const {
    return "";
  }

  std::string LanguageOptions::ToString(const LanguageFeatureSet& features) {
    return "";
  }

  LanguageOptions::LanguageOptions(const LanguageOptionsProto& proto)
    : name_resolution_mode_(proto.name_resolution_mode()),
      product_mode_(proto.product_mode()),
      error_on_deprecated_syntax_(proto.error_on_deprecated_syntax()) {
  }

  void LanguageOptions::Serialize(LanguageOptionsProto* proto) const {
  }

  void LanguageOptions::EnableMaximumLanguageFeatures(bool for_development) {
  }

  const LanguageOptions::KeywordSet& LanguageOptions::GetReservableKeywords() {
    LanguageOptions::KeywordSet *v;
    return *v;
  }

  bool LanguageOptions::IsReservedKeyword(absl::string_view keyword) const {
    return false;
  }

  absl::Status LanguageOptions::EnableReservableKeyword(absl::string_view keyword,
                                                        bool reserved) {
    return absl::OkStatus();
  }

  void LanguageOptions::EnableAllReservableKeywords(bool reserved) {
  }
}
#endif

#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/case/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/parser/keywords/export.inc"
#include "go-zetasql/proto/options_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/hash/hash/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
