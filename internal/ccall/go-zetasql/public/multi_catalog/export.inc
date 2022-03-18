#ifndef ZETASQL_PUBLIC_MULTI_CATALOG_EXPORT_H
#define ZETASQL_PUBLIC_MULTI_CATALOG_EXPORT_H

#include "zetasql/public/multi_catalog.h"
#include "zetasql/public/multi_catalog.cc"

#if 0
namespace zetasql {

  class Procedure;
  class TableValuedFunction;

  absl::Status MultiCatalog::Create(absl::string_view name, const std::vector<Catalog*>& catalog_list,
                                    std::unique_ptr<MultiCatalog>* multi_catalog) {
    return absl::OkStatus();
  }

  void MultiCatalog::AppendCatalog(Catalog* catalog) {
  }

  absl::Status MultiCatalog::FindTable(const absl::Span<const std::string>& path,
                                       const Table** table,
                                       const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status MultiCatalog::FindModel(const absl::Span<const std::string>& path,
                                       const Model** model,
                                       const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status MultiCatalog::FindFunction(const absl::Span<const std::string>& path, const Function** function,
                                          const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status MultiCatalog::FindTableValuedFunction(const absl::Span<const std::string>& path,
                                                     const TableValuedFunction** function, const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status MultiCatalog::FindProcedure(const absl::Span<const std::string>& path, const Procedure** procedure,
                                           const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status MultiCatalog::FindType(const absl::Span<const std::string>& path,
                                      const Type** type,
                                      const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status MultiCatalog::FindConstantWithPathPrefix(const absl::Span<const std::string> path, int* num_names_consumed,
                                                        const Constant** constant, const FindOptions& options) {
    return absl::OkStatus();
  }

  std::string MultiCatalog::SuggestTable(const absl::Span<const std::string>& mistyped_path) {
    return "";
  }

  std::string MultiCatalog::SuggestFunction(const absl::Span<const std::string>& mistyped_path) {
    return "";
  }

  std::string MultiCatalog::SuggestTableValuedFunction(const absl::Span<const std::string>& mistyped_path) {
    return "";
  }

  std::string MultiCatalog::SuggestConstant(const absl::Span<const std::string>& mistyped_path) {
    return "";
  }

  std::vector<std::string> MultiCatalog::CatalogNames() const {
    std::vector<std::string> v;
    return v;
  }

}
#endif

#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/constant/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"

#endif
