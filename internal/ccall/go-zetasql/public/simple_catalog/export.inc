#ifndef ZETASQL_PUBLIC_SIMPLE_CATALOG_EXPORT_H
#define ZETASQL_PUBLIC_SIMPLE_CATALOG_EXPORT_H

#include "zetasql/public/simple_catalog.h"
#include "zetasql/public/table_from_proto.h"

#include "zetasql/public/simple_catalog.cc"
#include "zetasql/public/table_from_proto.cc"

#if 0
namespace zetasql {

  SimpleCatalog::SimpleCatalog(const std::string& name, TypeFactory* type_factory)
    : name_(name), type_factory_(type_factory) {}

  absl::Status SimpleCatalog::GetTable(const std::string& name,
                                       const Table** table,
                                       const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status SimpleCatalog::GetModel(const std::string& name,
                                       const Model** model,
                                       const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status SimpleCatalog::GetConnection(const std::string& name,
                                            const Connection** connection,
                                            const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status SimpleCatalog::GetFunction(const std::string& name,
                                          const Function** function,
                                          const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status SimpleCatalog::GetTableValuedFunction(
                                                     const std::string& name, const TableValuedFunction** function,
                                                     const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status SimpleCatalog::GetProcedure(const std::string& name,
                                           const Procedure** procedure,
                                           const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status SimpleCatalog::GetType(const std::string& name, const Type** type,
                                      const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status SimpleCatalog::GetCatalog(const std::string& name,
                                         Catalog** catalog,
                                         const FindOptions& options) {
    return absl::OkStatus();
  }

  absl::Status SimpleCatalog::GetConstant(const std::string& name,
                                          const Constant** constant,
                                          const FindOptions& options) {
    return absl::OkStatus();
  }

  std::string SimpleCatalog::SuggestTable(const absl::Span<const std::string>& mistyped_path) {
    return "";
  }

  std::string SimpleCatalog::SuggestFunctionOrTableValuedFunction(bool is_table_valued_function,
                                                                  absl::Span<const std::string> mistyped_path) {
    return "";
  }

  std::string SimpleCatalog::SuggestFunction(const absl::Span<const std::string>& mistyped_path) {
    return "";
  }

  std::string SimpleCatalog::SuggestTableValuedFunction(const absl::Span<const std::string>& mistyped_path) {
    return "";
  }

  std::string SimpleCatalog::SuggestConstant(const absl::Span<const std::string>& mistyped_path) {
    return "";
  }

  void SimpleCatalog::AddTable(absl::string_view name, const Table* table) {
  }

  void SimpleCatalog::AddModel(const std::string& name, const Model* model) {
  }

  void SimpleCatalog::AddConnection(const std::string& name,
                                    const Connection* connection) {
  }

  void SimpleCatalog::AddType(const std::string& name, const Type* type) {
  }

  void SimpleCatalog::AddCatalog(const std::string& name, Catalog* catalog) {
  }

  void SimpleCatalog::AddCatalogLocked(const std::string& name,
                                       Catalog* catalog) {
  }

  void SimpleCatalog::AddFunctionLocked(const std::string& name,
                                        const Function* function) {
  }

  void SimpleCatalog::AddFunction(const std::string& name,
                                  const Function* function) {
  }

  void SimpleCatalog::AddTableValuedFunctionLocked(const std::string& name, const TableValuedFunction* table_function) {
  }

  void SimpleCatalog::AddTableValuedFunction(const std::string& name, const TableValuedFunction* function) {
  }

  void SimpleCatalog::AddProcedure(const std::string& name,
                                   const Procedure* procedure) {
  }

  void SimpleCatalog::AddConstant(const std::string& name,
                                  const Constant* constant) {
  }

  void SimpleCatalog::AddConstantLocked(const std::string& name,
                                        const Constant* constant) {
  }

  void SimpleCatalog::AddOwnedTable(absl::string_view name,
                                    std::unique_ptr<const Table> table) {
  }

  bool SimpleCatalog::AddOwnedTableIfNotPresent(absl::string_view name, std::unique_ptr<const Table> table) {
    return false;
  }

  void SimpleCatalog::AddOwnedTable(absl::string_view name, const Table* table) {
  }

  void SimpleCatalog::AddOwnedModel(const std::string& name,
                                    std::unique_ptr<const Model> model) {
  }

  void SimpleCatalog::AddOwnedModel(const std::string& name, const Model* model) {
  }

  void SimpleCatalog::AddOwnedCatalog(const std::string& name,
                                      std::unique_ptr<Catalog> catalog) {
  }

  void SimpleCatalog::AddOwnedCatalog(const std::string& name, Catalog* catalog) {
  }

  void SimpleCatalog::AddOwnedFunction(const std::string& name,
                                       std::unique_ptr<const Function> function) {
  }

  void SimpleCatalog::AddOwnedFunction(const std::string& name,
                                       const Function* function) {
  }

  void SimpleCatalog::AddOwnedFunctionLocked(const std::string& name, std::unique_ptr<const Function> function) {
  }

  void SimpleCatalog::AddOwnedTableValuedFunction(const std::string& name,
                                                  std::unique_ptr<const TableValuedFunction> function) {
  }

  void SimpleCatalog::AddOwnedTableValuedFunction(const std::string& name, const TableValuedFunction* function) {
  }

  void SimpleCatalog::AddOwnedTableValuedFunctionLocked(const std::string& name,
                                                        std::unique_ptr<const TableValuedFunction> table_function) {
  }

  void SimpleCatalog::AddOwnedProcedure(const std::string& name, std::unique_ptr<const Procedure> procedure) {
  }

  bool SimpleCatalog::AddOwnedProcedureIfNotPresent(std::unique_ptr<Procedure> procedure) {
    return false;
  }

  void SimpleCatalog::AddOwnedProcedure(const std::string& name,
                                        const Procedure* procedure) {
  }

  void SimpleCatalog::AddOwnedConstant(const std::string& name,
                                       std::unique_ptr<const Constant> constant) {
  }

  void SimpleCatalog::AddOwnedConstant(const std::string& name,
                                       const Constant* constant) {
  }

  void SimpleCatalog::AddTable(const Table* table) {
  }

  void SimpleCatalog::AddModel(const Model* model) {
  }

  void SimpleCatalog::AddConnection(const Connection* connection) {
  }

  void SimpleCatalog::AddCatalog(Catalog* catalog) {
  }

  void SimpleCatalog::AddFunction(const Function* function) {
  }

  void SimpleCatalog::AddTableValuedFunction(const TableValuedFunction* function) {
  }

  void SimpleCatalog::AddProcedure(const Procedure* procedure) {
  }

  void SimpleCatalog::AddConstant(const Constant* constant) {
  }

  void SimpleCatalog::AddOwnedTable(std::unique_ptr<const Table> table) {
  }

  void SimpleCatalog::AddOwnedTable(const Table* table) {
  }

  void SimpleCatalog::AddOwnedModel(std::unique_ptr<const Model> model) {
  }

  void SimpleCatalog::AddOwnedModel(const Model* model) {
  }

  void SimpleCatalog::AddOwnedCatalog(std::unique_ptr<Catalog> catalog) {
  }

  void SimpleCatalog::AddOwnedCatalog(Catalog* catalog) {
  }

  void SimpleCatalog::AddOwnedCatalogLocked(const std::string& name,
                                            std::unique_ptr<Catalog> catalog) {
  }

  bool SimpleCatalog::AddOwnedCatalogIfNotPresent(const std::string& name, std::unique_ptr<Catalog> catalog) {
    return false;
  }

  void SimpleCatalog::AddOwnedFunction(std::unique_ptr<const Function> function) {
  }

  void SimpleCatalog::AddOwnedFunction(const Function* function) {
  }

  bool SimpleCatalog::AddOwnedFunctionIfNotPresent(const std::string& name, std::unique_ptr<Function>* function) {
    return false;
  }

  bool SimpleCatalog::AddOwnedFunctionIfNotPresent(std::unique_ptr<Function>* function) {
    return false;
  }

  void SimpleCatalog::AddOwnedTableValuedFunction(std::unique_ptr<const TableValuedFunction> function) {
  }

  void SimpleCatalog::AddOwnedTableValuedFunction(const TableValuedFunction* function) {
  }

  bool SimpleCatalog::AddOwnedTableValuedFunctionIfNotPresent(const std::string& name,
                                                              std::unique_ptr<TableValuedFunction>* table_function) {
    return false;
  }

  bool SimpleCatalog::AddOwnedTableValuedFunctionIfNotPresent(std::unique_ptr<TableValuedFunction>* table_function) {
    return false;
  }

  bool SimpleCatalog::AddTypeIfNotPresent(const std::string& name,
                                          const Type* type) {
    return false;
  }

  void SimpleCatalog::AddOwnedProcedure(std::unique_ptr<const Procedure> procedure) {
  }

  void SimpleCatalog::AddOwnedProcedure(const Procedure* procedure) {
  }

  void SimpleCatalog::AddOwnedConstant(std::unique_ptr<const Constant> constant) {
  }

  bool SimpleCatalog::AddOwnedConstantIfNotPresent(std::unique_ptr<const Constant> constant) {
    return false;
  }

  void SimpleCatalog::AddOwnedConstant(const Constant* constant) {
  }

  SimpleCatalog* SimpleCatalog::MakeOwnedSimpleCatalog(const std::string& name) {
    return nullptr;
  }

  void SimpleCatalog::SetDescriptorPool(const google::protobuf::DescriptorPool* pool) {
  }

  void SimpleCatalog::SetOwnedDescriptorPool(const google::protobuf::DescriptorPool* pool) {
  }

  void SimpleCatalog::SetOwnedDescriptorPool(std::unique_ptr<const google::protobuf::DescriptorPool> pool) {
  }

  void SimpleCatalog::AddZetaSQLFunctions(const std::vector<const Function*>& functions) {
  }

  void SimpleCatalog::AddZetaSQLFunctions(const ZetaSQLBuiltinFunctionOptions& options) {
  }

  void SimpleCatalog::ClearFunctions() {
  }

  void SimpleCatalog::ClearTableValuedFunctions() {
  }

  TypeFactory* SimpleCatalog::type_factory() {
    return nullptr;
  }

  absl::Status SimpleCatalog::DeserializeImpl(const SimpleCatalogProto& proto,
                                              const TypeDeserializer& type_deserializer) {
    return absl::OkStatus();
  }

  absl::Status SimpleCatalog::Deserialize(const SimpleCatalogProto& proto,
                                          const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                          std::unique_ptr<SimpleCatalog>* result) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<SimpleCatalog>> SimpleCatalog::Deserialize(
                                                                            const SimpleCatalogProto& proto,
                                                                            const absl::Span<const google::protobuf::DescriptorPool* const> pools,
                                                                            const ExtendedTypeDeserializer* extended_type_deserializer) {
    absl::StatusOr<std::unique_ptr<SimpleCatalog>> v;
    return v;
  }

  absl::Status SimpleCatalog::Serialize(FileDescriptorSetMap* file_descriptor_set_map,
                                        SimpleCatalogProto* proto,
                                        bool ignore_builtin,
                                        bool ignore_recursive) const {
    return absl::OkStatus();
  }

  absl::Status SimpleCatalog::SerializeImpl(absl::flat_hash_set<const Catalog*>* seen_catalogs,
                                            FileDescriptorSetMap* file_descriptor_set_map, SimpleCatalogProto* proto,
                                            bool ignore_builtin, bool ignore_recursive) const {
    return absl::OkStatus();
  }

  absl::Status SimpleCatalog::GetCatalogs(absl::flat_hash_set<const Catalog*>* output) const {
    return absl::OkStatus();
  }

  absl::Status SimpleCatalog::GetTables(absl::flat_hash_set<const Table*>* output) const {
    return absl::OkStatus();
  }

  absl::Status SimpleCatalog::GetTypes(absl::flat_hash_set<const Type*>* output) const {
    return absl::OkStatus();
  }

  absl::Status SimpleCatalog::GetFunctions(absl::flat_hash_set<const Function*>* output) const {
    return absl::OkStatus();
  }

  std::vector<std::string> SimpleCatalog::table_names() const {
    std::vector<std::string> v;
    return v;
  }

  std::vector<const Table*> SimpleCatalog::tables() const {
    std::vector<const Table*> v;
    return v;
  }

  std::vector<const Type*> SimpleCatalog::types() const {
    std::vector<const Type*> v;
    return v;
  }

  std::vector<std::string> SimpleCatalog::function_names() const {
    std::vector<std::string> v;
    return v;
  }

  std::vector<const Function*> SimpleCatalog::functions() const {
    std::vector<const Function*> v;
    return v;
  }

  std::vector<std::string> SimpleCatalog::table_valued_function_names() const {
    std::vector<std::string> v;
    return v;
  }

  std::vector<const TableValuedFunction*> SimpleCatalog::table_valued_functions() {
    std::vector<const TableValuedFunction*> v;
    return v;
  }

  std::vector<const Procedure*> SimpleCatalog::procedures() const {
    std::vector<const Procedure*> v;
    return v;
  }

  std::vector<std::string> SimpleCatalog::catalog_names() const {
    std::vector<std::string> v;
    return v;
  }

  std::vector<Catalog*> SimpleCatalog::catalogs() const {
    std::vector<Catalog*> v;
    return v;
  }

  std::vector<std::string> SimpleCatalog::constant_names() const {
    std::vector<std::string> v;
    return v;
  }

  std::vector<const Constant*> SimpleCatalog::constants() const {
    std::vector<const Constant*> v;
    return v;
  }

  SimpleTable::SimpleTable(absl::string_view name,
                           const std::vector<NameAndType>& columns,
                           const int64_t serialization_id)
    : name_(name), id_(serialization_id) {
  }

  SimpleTable::SimpleTable(absl::string_view name,
                           const std::vector<NameAndAnnotatedType>& columns,
                           const int64_t serialization_id)
    : name_(name), id_(serialization_id) {
  }

  SimpleTable::SimpleTable(absl::string_view name,
                           const std::vector<const Column*>& columns,
                           bool take_ownership, const int64_t serialization_id)
    : name_(name), id_(serialization_id) {
  }

  SimpleTable::SimpleTable(absl::string_view name, const Type* row_type,
                           const int64_t id)
    : SimpleTable(name, {{"value", row_type}}, id) {
  }

  SimpleTable::SimpleTable(absl::string_view name, const int64_t id)
    : name_(name), id_(id) {}

  absl::Status SimpleTable::SetAnonymizationInfo(const std::string& userid_column_name) {
    return absl::OkStatus();
  }

  absl::Status SimpleTable::SetAnonymizationInfo(absl::Span<const std::string> userid_column_name_path) {
    return absl::OkStatus();
  }

  const Column* SimpleTable::FindColumnByName(const std::string& name) const {
    return nullptr;
  }

  absl::Status SimpleTable::AddColumn(const Column* column, bool is_owned) {
    return absl::OkStatus();
  }

  absl::Status SimpleTable::SetPrimaryKey(std::vector<int> primary_key) {
    return absl::OkStatus();
  }

  absl::Status SimpleTable::InsertColumnToColumnMap(const Column* column) {
    return absl::OkStatus();
  }

  void SimpleTable::SetContents(const std::vector<std::vector<Value>>& rows) {
  }

  absl::StatusOr<std::unique_ptr<EvaluatorTableIterator>>
  SimpleTable::CreateEvaluatorTableIterator(absl::Span<const int> column_idxs) const {
    absl::StatusOr<std::unique_ptr<EvaluatorTableIterator>> v;
    return v;
  }

  absl::Status SimpleTable::Serialize(FileDescriptorSetMap* file_descriptor_set_map,
                                      SimpleTableProto* proto) const {
    return absl::OkStatus();
  }

  absl::Status SimpleTable::Deserialize(const SimpleTableProto& proto,
                                        const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                        TypeFactory* factory,
                                        std::unique_ptr<SimpleTable>* result) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<SimpleTable>> SimpleTable::Deserialize(const SimpleTableProto& proto, const TypeDeserializer& type_deserializer) {
    absl::StatusOr<std::unique_ptr<SimpleTable>> v;
    return v;
  }

  SimpleColumn::SimpleColumn(const std::string& table_name,
                             const std::string& name, const Type* type,
                             bool is_pseudo_column, bool is_writable_column)
    : SimpleColumn(table_name, name,
                   AnnotatedType(type, /*annotation_map=*/nullptr),
                   is_pseudo_column, is_writable_column) {}

  SimpleColumn::SimpleColumn(const std::string& table_name,
                             const std::string& name,
                             AnnotatedType annotated_type, bool is_pseudo_column,
                             bool is_writable_column)
    : name_(name),
      full_name_(absl::StrCat(table_name, ".", name)),
      is_pseudo_column_(is_pseudo_column),
      is_writable_column_(is_writable_column),
      annotated_type_(annotated_type) {}

  SimpleColumn::~SimpleColumn() {
  }

  absl::Status SimpleColumn::Serialize(FileDescriptorSetMap* file_descriptor_set_map,
                                       SimpleColumnProto* proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<SimpleColumn>> SimpleColumn::Deserialize(const SimpleColumnProto& proto, const std::string& table_name,
                                                                          const TypeDeserializer& type_deserializer) {
    absl::StatusOr<std::unique_ptr<SimpleColumn>> v;
    return v;
  }

  absl::Status SimpleConstant::Create(const std::vector<std::string>& name_path, const Value& value,
                                      std::unique_ptr<SimpleConstant>* simple_constant) {
    return absl::OkStatus();
  }

  std::string SimpleConstant::DebugString() const {
    return "";
  }

  std::string SimpleConstant::VerboseDebugString() const {
    return "";
  }

  absl::Status SimpleConstant::Serialize(FileDescriptorSetMap* file_descriptor_set_map,
                                         SimpleConstantProto* simple_constant_proto) const {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<SimpleConstant>> SimpleConstant::Deserialize(const SimpleConstantProto& simple_constant_proto,
                                                                              const TypeDeserializer& type_deserializer) {
    absl::StatusOr<std::unique_ptr<SimpleConstant>> v;
    return v;
  }

  SimpleModel::SimpleModel(const std::string& name,
                           const std::vector<NameAndType>& inputs,
                           const std::vector<NameAndType>& outputs,
                           const int64_t id) {
  }

  SimpleModel::SimpleModel(const std::string& name,
                           const std::vector<const Column*>& inputs,
                           const std::vector<const Column*>& outputs,
                           bool take_ownership, const int64_t id)
    : name_(name), id_(id) {
  }

  const Column* SimpleModel::FindInputByName(const std::string& name) const {
    return nullptr;
  }

  const Column* SimpleModel::FindOutputByName(const std::string& name) const {
    return nullptr;
  }

  absl::Status SimpleModel::AddInput(const Column* column, bool is_owned) {
    return absl::OkStatus();
  }

  absl::Status SimpleModel::AddOutput(const Column* column, bool is_owned) {
    return absl::OkStatus();
  }

}

namespace zetasql {

  TableFromProto::TableFromProto(const std::string& name) : SimpleTable(name) {}

  TableFromProto::~TableFromProto() {}

  absl::Status TableFromProto::Init(const google::protobuf::Descriptor* descriptor,
                                    TypeFactory* type_factory,
                                    const TableFromProtoOptions& options) {
    return absl::OkStatus();
  }

}
#endif

#include "go-zetasql/public/builtin_function/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/constant/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/simple_constant_cc_proto/export.inc"
#include "go-zetasql/public/simple_table_cc_proto/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/case/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/common/simple_evaluator_table_iterator/export.inc"
#include "go-zetasql/proto/simple_catalog_cc_proto/export.inc"
#include "go-zetasql/public/proto/type_annotation_cc_proto/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"
#include "go-absl/types/span/export.inc"
#include "go-protobuf/protobuf/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
