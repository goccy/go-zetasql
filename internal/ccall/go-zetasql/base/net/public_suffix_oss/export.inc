#ifndef ZETASQL_BASE_NET_PUBLIC_SUFFIX_OSS_EXPORT_H
#define ZETASQL_BASE_NET_PUBLIC_SUFFIX_OSS_EXPORT_H

#include "zetasql/base/net/public_suffix_oss.h"
#include "zetasql/base/net/public_suffix_list_data.h"
#include "zetasql/base/net/public_suffix_oss.cc"

#if 0
namespace zetasql::internal {

  PublicSuffixRulesBuilder& PublicSuffixRulesBuilder::AddRule(absl::string_view rule, PublicSuffixRules::DomainType domain_type) {
    return *this;
  }

  void PublicSuffixRulesBuilder::ProcessRulesOrChanges(absl::string_view rules) {
  }

  PublicSuffixRulesBuilder& PublicSuffixRulesBuilder::AddRules(absl::string_view rules) {
    return *this;
  }

  const PublicSuffixRules& PublicSuffixRules::GetLatest() {
    return *this;
  }

  void PublicSuffixRulesBuilder::ProcessRules(const absl::flat_hash_set<std::string>& rules, PublicSuffixRules::DomainType domain_type) {
  }

  PublicSuffixRules* PublicSuffixRulesBuilder::Build() {
    return nullptr;
  }

  void PublicSuffixRules::GetMatchingRules(absl::string_view name, MatchVector* matches) const {
  }

  absl::string_view PublicSuffixRules::GetPublicSuffixOrTopPrivateDomain(absl::string_view name, absl::FunctionRef<void(const MatchVector&, const char**)> find_match) const {
    return "";
  }

  void PublicSuffixRules::DoPublicSuffix(const MatchVector& matches, const char** label) {
  }

  void PublicSuffixRules::DoTopPrivate(const MatchVector& matches, const char** label) {
  }

  absl::string_view PublicSuffixRules::GetPublicSuffix(absl::string_view name) const {
    return "";
  }

  absl::string_view PublicSuffixRules::GetTopPrivateDomain(absl::string_view name) const {
    return "";
  }

  absl::string_view GetPublicSuffix(absl::string_view name) {
    return "";
  }

  absl::string_view GetTopPrivateDomain(absl::string_view name) {
    return "";
  }

}
#endif

#include "go-zetasql/base/logging/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/container/inlined_vector/export.inc"
#include "go-absl/functional/function_ref/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-icu/icu/export.inc"

#endif
