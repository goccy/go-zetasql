#ifndef ZETASQL_PUBLIC_CATALOG_EXPORT_H
#define ZETASQL_PUBLIC_CATALOG_EXPORT_H

#include "zetasql/public/catalog.h"
#include "zetasql/public/catalog_helper.h"

#include "zetasql/public/catalog.cc"
#include "zetasql/public/catalog_helper.cc"

#if 0
namespace zetasql {

  absl::Status Catalog::FindTable(const absl::Span<const std::string>& path,
                                  const Table** table,
                                  const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::FindModel(const absl::Span<const std::string>& path,
                                  const Model** model,
                                  const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::FindConnection(const absl::Span<const std::string>& path,
                                       const Connection** connection,
                                       const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::FindFunction(const absl::Span<const std::string>& path,
                                     const Function** function,
                                     const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::FindTableValuedFunction(
                                                const absl::Span<const std::string>& path,
                                                const TableValuedFunction** function, const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::FindProcedure(const absl::Span<const std::string>& path,
                                      const Procedure** procedure,
                                      const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::FindType(const absl::Span<const std::string>& path,
                                 const Type** type, const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::FindConstant(const absl::Span<const std::string> path,
                                     const Constant** constant,
                                     const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::FindConversion(const Type* from_type, const Type* to_type,
                                       const FindConversionOptions& options,
                                       Conversion* conversion) {
    return absl::OkStatus();
  }

  absl::Status Catalog::FindConstantWithPathPrefix(
                                                   const absl::Span<const std::string> path, int* num_names_consumed,
                                                   const Constant** constant, const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::FindConstantWithPathPrefixImpl(
                                                       const absl::Span<const std::string> path, int* num_names_consumed,
                                                       const Constant** constant, const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::FindObject(absl::Span<const std::string> path,
                                   const Function** object,
                                   const FindOptions& options) {
  }
  absl::Status Catalog::FindObject(absl::Span<const std::string> path,
                                   const TableValuedFunction** object,
                                   const FindOptions& options) {
  }
  absl::Status Catalog::FindObject(absl::Span<const std::string> path,
                                   const Table** object,
                                   const FindOptions& options) {
  }
  absl::Status Catalog::FindObject(const absl::Span<const std::string> path,
                                   const Model** object,
                                   const FindOptions& options) {
  }
  absl::Status Catalog::FindObject(absl::Span<const std::string> path,
                                   const Connection** object,
                                   const FindOptions& options) {
  }
  absl::Status Catalog::FindObject(absl::Span<const std::string> path,
                                   const Procedure** object,
                                   const FindOptions& options) {
  }
  absl::Status Catalog::FindObject(absl::Span<const std::string> path,
                                   const Type** object,
                                   const FindOptions& options) {
  }
  absl::Status Catalog::FindObject(absl::Span<const std::string> path,
                                   const Constant** object,
                                   const FindOptions& options) {
  }

  absl::StatusOr<TypeListView> Catalog::GetExtendedTypeSuperTypes(const Type* type) {
  }

  std::string Catalog::ConvertPathToProtoName( absl::Span<const std::string> path) {
    return "";
  }

  std::string Catalog::SuggestTable(const absl::Span<const std::string>& mistyped_path) {
    return "";
  }

  std::string Catalog::SuggestModel(const absl::Span<const std::string>& mistyped_path) {
    return "";
  }

  std::string Catalog::SuggestFunction(const absl::Span<const std::string>& mistyped_path) {
    return "";
  }

  std::string Catalog::SuggestTableValuedFunction(const absl::Span<const std::string>& mistyped_path) {
    return "";
  }

  std::string Catalog::SuggestConstant(const absl::Span<const std::string>& mistyped_path) {
    return "";
  }

  absl::Status Catalog::GetTable(const std::string& name, const Table** table,
                                 const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::GetModel(const std::string& name, const Model** model,
                                 const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::GetConnection(const std::string& name,
                                      const Connection** connection,
                                      const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::GetFunction(const std::string& name,
                                    const Function** function,
                                    const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::GetTableValuedFunction(
                                               const std::string& name, const TableValuedFunction** function,
                                               const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::GetProcedure(const std::string& name,
                                     const Procedure** procedure,
                                     const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::GetType(const std::string& name, const Type** type,
                                const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::GetCatalog(const std::string& name, Catalog** catalog,
                                   const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::GetConstant(const std::string& name,
                                    const Constant** constant,
                                    const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status Catalog::GenericNotFoundError(const std::string& object_type, absl::Span<const std::string> path) const {
    return absl::OkStatus();
  }

  absl::Status Catalog::TableNotFoundError(absl::Span<const std::string> path) const {
    return absl::OkStatus();
  }

  absl::Status Catalog::ModelNotFoundError(absl::Span<const std::string> path) const {
    return absl::OkStatus();
  }

  absl::Status Catalog::ConnectionNotFoundError(absl::Span<const std::string> path) const {
    return absl::OkStatus();
  }

  absl::Status Catalog::FunctionNotFoundError(absl::Span<const std::string> path) const {
    return absl::OkStatus();
  }

  absl::Status Catalog::TableValuedFunctionNotFoundError(const absl::Span<const std::string> path) const {
    return absl::OkStatus();
  }

  absl::Status Catalog::ProcedureNotFoundError(absl::Span<const std::string> path) const {
    return absl::OkStatus();
  }

  absl::Status Catalog::TypeNotFoundError(absl::Span<const std::string> path) const {
    return absl::OkStatus();
  }

  absl::Status Catalog::ConstantNotFoundError(const absl::Span<const std::string> path) const {
    return absl::OkStatus();
  }

  absl::Status Catalog::ConversionNotFoundError(const Type* from, const Type* to,
                                                const FindConversionOptions& options) const {
    return absl::OkStatus();
  }

  absl::Status Catalog::EmptyNamePathInternalError(const std::string& object_type) const {
    return absl::OkStatus();
  }

  absl::StatusOr<AnonymizationUserIdInfo> AnonymizationUserIdInfo::Create(const Column* column) {
    absl::StatusOr<AnonymizationUserIdInfo> v;
    return v;
  }

  absl::StatusOr<AnonymizationUserIdInfo> AnonymizationUserIdInfo::Create(absl::Span<const std::string> column_name_path) {
    absl::StatusOr<AnonymizationUserIdInfo> v;
    return v;
  }

  AnonymizationUserIdInfo::AnonymizationUserIdInfo(const Column* column)
    : column_(column), column_name_path_(1, column->Name()) {
  }

  AnonymizationUserIdInfo::AnonymizationUserIdInfo(absl::Span<const std::string> column_name_path)
    : column_name_path_(column_name_path.begin(), column_name_path.end()) {}

  absl::StatusOr<std::unique_ptr<AnonymizationInfo>> AnonymizationInfo::Create(const Table* table, absl::Span<const std::string> userid_column_name_path) {
    absl::StatusOr<std::unique_ptr<AnonymizationInfo>> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<AnonymizationInfo>> AnonymizationInfo::Create(absl::Span<const std::string> userid_column_name_path) {
    absl::StatusOr<std::unique_ptr<AnonymizationInfo>> v;
    return v;
  }

  absl::Span<const std::string> AnonymizationInfo::UserIdColumnNamePath() const {
    absl::Span<const std::string> v;
    return v;
  }

  std::string Table::GetTableTypeName(ProductMode mode) const {
    return "";
  }

}

namespace zetasql {

  std::string ClosestName(const std::string& mistyped_name,
                          const std::vector<std::string>& possible_names) {
    return "";
  }
}
#endif

#include "go-zetasql/public/evaluator_table_iterator/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/edit_distance/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"
#include "go-absl/types/variant/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
