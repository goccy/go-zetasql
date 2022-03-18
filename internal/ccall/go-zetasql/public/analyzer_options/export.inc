#ifndef ZETASQL_PUBLIC_ANALYZER_OPTIONS_EXPORT_H
#define ZETASQL_PUBLIC_ANALYZER_OPTIONS_EXPORT_H

#include "zetasql/public/analyzer_options.h"

#include "zetasql/public/analyzer_options.cc"

#if 0
namespace zetasql {

  bool StringVectorCaseLess::operator()(const std::vector<std::string>& v1,
                                        const std::vector<std::string>& v2) const {
    return false;
  }

  void AllowedHintsAndOptions::AddOption(const std::string& name,
                                         const Type* type) {
  }

  absl::Status AllowedHintsAndOptions::AddOptionImpl(const std::string& name,
                                                     const Type* type) {
    return absl::OkStatus();
  }

  void AllowedHintsAndOptions::AddHint(const std::string& qualifier,
                                       const std::string& name, const Type* type,
                                       bool allow_unqualified) {
  }

  absl::Status AllowedHintsAndOptions::AddHintImpl(const std::string& qualifier,
                                                   const std::string& name,
                                                   const Type* type,
                                                   bool allow_unqualified) {
    return absl::OkStatus();
  }

  absl::Status AllowedHintsAndOptions::Deserialize(const AllowedHintsAndOptionsProto& proto,
                                                   const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                                   TypeFactory* factory, AllowedHintsAndOptions* result) {
    return absl::OkStatus();
  }

  absl::Status AllowedHintsAndOptions::Serialize(FileDescriptorSetMap* file_descriptor_set_map,
                                                 AllowedHintsAndOptionsProto* proto) const {
    return absl::OkStatus();
  }

  AnalyzerOptions::AnalyzerOptions() : AnalyzerOptions(LanguageOptions()) {}

  AnalyzerOptions::AnalyzerOptions(const LanguageOptions& language_options)
    : language_options_(language_options) {
  }

  AnalyzerOptions::~AnalyzerOptions() {}

  void AnalyzerOptions::CreateDefaultArenasIfNotSet() {
  }

  absl::Status AnalyzerOptions::Deserialize(const AnalyzerOptionsProto& proto,
                                            const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                            TypeFactory* factory, AnalyzerOptions* result) {
    return absl::OkStatus();
  }

  absl::Status AnalyzerOptions::Serialize(FileDescriptorSetMap* map,
                                          AnalyzerOptionsProto* proto) const {
    return absl::OkStatus();
  }

  absl::Status AnalyzerOptions::AddSystemVariable(const std::vector<std::string>& name_path, const Type* type) {
    return absl::OkStatus();
  }

  absl::Status AnalyzerOptions::AddQueryParameter(const std::string& name,
                                                  const Type* type) {
    return absl::OkStatus();
  }

  absl::Status AnalyzerOptions::AddPositionalQueryParameter(const Type* type) {
    return absl::OkStatus();
  }

  absl::Status AnalyzerOptions::AddExpressionColumn(const std::string& name,
                                                    const Type* type) {
    return absl::OkStatus();
  }

  absl::Status AnalyzerOptions::SetInScopeExpressionColumn(const std::string& name, const Type* type) {
    return absl::OkStatus();
  }

  void AnalyzerOptions::SetDdlPseudoColumnsCallback(DdlPseudoColumnsCallback ddl_pseudo_columns_callback) {
  }

  void AnalyzerOptions::SetDdlPseudoColumns(const std::vector<std::pair<std::string, const Type*>>& ddl_pseudo_columns) {
  }

  ParserOptions AnalyzerOptions::GetParserOptions() const {
    ParserOptions v;
    return v;
  }

  void AnalyzerOptions::enable_rewrite(ResolvedASTRewrite rewrite, bool enable) {
  }

  absl::btree_set<ResolvedASTRewrite> AnalyzerOptions::DefaultRewrites() {
    absl::btree_set<ResolvedASTRewrite> v;
    return v;
  }

  const AnalyzerOptions& GetOptionsWithArenas(const AnalyzerOptions* options, std::unique_ptr<AnalyzerOptions>* copy) {
    AnalyzerOptions *v;
    return *v;
  }

  absl::Status ValidateAnalyzerOptions(const AnalyzerOptions& options) {
    return absl::OkStatus();
  }

}
#endif

#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/btree/export.inc"

#endif
