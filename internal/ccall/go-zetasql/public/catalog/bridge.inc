#include "_cgo_export.h"

using namespace zetasql;

class GoCatalog : public Catalog {
public:
  GoCatalog(void *go_catalog_ptr) : go_catalog_ptr(go_catalog_ptr) {}
  ~GoCatalog() {}

  std::string FullName() const {
    return std::string(GoCatalog_FullName(this->go_catalog_ptr));
  }

  absl::Status FindTable(const absl::Span<const std::string>& path, const Table** table, const FindOptions& options = FindOptions()) {
    if (path.empty()) {
      return EmptyNamePathInternalError("Table");
    }
    GoSlice *path_slice = (GoSlice *)malloc(sizeof(GoSlice));
    const char **data = (const char **)malloc(sizeof(void *) * path.size());
    for (size_t i = 0; i < path.size(); i++) {
      data[i] = path[i].c_str();
    }
    path_slice->data = (void *)data;
    path_slice->len = path.size();
    path_slice->cap = path.size();

    void *tableV = nullptr;
    char *ret = nullptr;
    GoCatalog_FindTable(this->go_catalog_ptr, (void *)path_slice, &tableV, &ret);
    if (tableV == nullptr) {
      return TableNotFoundError(path);
    }
    if (ret != nullptr) {
      return absl::InvalidArgumentError(ret);
    }
    *table = (const Table *)tableV;
    return absl::OkStatus();
  }

  absl::Status FindModel(const absl::Span<const std::string>& path, const Model** model, const FindOptions& options = FindOptions()) {
    if (path.empty()) {
      return EmptyNamePathInternalError("Model");
    }
    GoSlice *path_slice = (GoSlice *)malloc(sizeof(GoSlice));
    const char **data = (const char **)malloc(sizeof(void *) * path.size());
    for (size_t i = 0; i < path.size(); i++) {
      data[i] = path[i].c_str();
    }
    path_slice->data = (void *)data;
    path_slice->len = path.size();
    path_slice->cap = path.size();

    void *modelV = nullptr;
    char *ret = nullptr;
    GoCatalog_FindModel(this->go_catalog_ptr, (void *)path_slice, &modelV, &ret);
    if (modelV == nullptr) {
      return ModelNotFoundError(path);
    }
    if (ret != nullptr) {
      return absl::InvalidArgumentError(ret);
    }
    *model = (const Model *)modelV;
    return absl::OkStatus();
  }
  
  absl::Status FindConnection(const absl::Span<const std::string>& path, const Connection** connection, const FindOptions& options) {
    if (path.empty()) {
      return EmptyNamePathInternalError("Connection");
    }
    GoSlice *path_slice = (GoSlice *)malloc(sizeof(GoSlice));
    const char **data = (const char **)malloc(sizeof(void *) * path.size());
    for (size_t i = 0; i < path.size(); i++) {
      data[i] = path[i].c_str();
    }
    path_slice->data = (void *)data;
    path_slice->len = path.size();
    path_slice->cap = path.size();

    void *connV = nullptr;
    char *ret = nullptr;
    GoCatalog_FindConnection(this->go_catalog_ptr, (void *)path_slice, &connV, &ret);
    if (connV == nullptr) {
      return ConnectionNotFoundError(path);
    }
    if (ret != nullptr) {
      return absl::InvalidArgumentError(ret);
    }
    *connection = (const Connection *)connV;
    return absl::OkStatus();
  }
  
  absl::Status FindFunction(const absl::Span<const std::string>& path, const Function** function, const FindOptions& options = FindOptions()) {
    if (path.empty()) {
      return EmptyNamePathInternalError("Function");
    }
    GoSlice *path_slice = (GoSlice *)malloc(sizeof(GoSlice));
    const char **data = (const char **)malloc(sizeof(void *) * path.size());
    for (size_t i = 0; i < path.size(); i++) {
      data[i] = path[i].c_str();
    }
    path_slice->data = (void *)data;
    path_slice->len = path.size();
    path_slice->cap = path.size();

    void *funcV = nullptr;
    char *ret = nullptr;
    GoCatalog_FindFunction(this->go_catalog_ptr, (void *)path_slice, &funcV, &ret);
    if (funcV == nullptr) {
      return FunctionNotFoundError(path);
    }
    if (ret != nullptr) {
      return absl::InvalidArgumentError(ret);
    }
    *function = (const Function *)funcV;
    return absl::OkStatus();
  }
  
  absl::Status FindTableValuedFunction(const absl::Span<const std::string>& path, const TableValuedFunction** function, const FindOptions& options = FindOptions()) {
    if (path.empty()) {
      return EmptyNamePathInternalError("TableValuedFunction");
    }
    GoSlice *path_slice = (GoSlice *)malloc(sizeof(GoSlice));
    const char **data = (const char **)malloc(sizeof(void *) * path.size());
    for (size_t i = 0; i < path.size(); i++) {
      data[i] = path[i].c_str();
    }
    path_slice->data = (void *)data;
    path_slice->len = path.size();
    path_slice->cap = path.size();

    void *funcV = nullptr;
    char *ret = nullptr;
    GoCatalog_FindTableValuedFunction(this->go_catalog_ptr, (void *)path_slice, &funcV, &ret);
    if (funcV == nullptr) {
      return TableValuedFunctionNotFoundError(path);
    }
    if (ret != nullptr) {
      return absl::InvalidArgumentError(ret);
    }
    *function = (const TableValuedFunction *)funcV;
    return absl::OkStatus();
  }
  
  absl::Status FindProcedure(const absl::Span<const std::string>& path, const Procedure** procedure, const FindOptions& options = FindOptions()) {
    if (path.empty()) {
      return EmptyNamePathInternalError("Procedure");
    }
    GoSlice *path_slice = (GoSlice *)malloc(sizeof(GoSlice));
    const char **data = (const char **)malloc(sizeof(void *) * path.size());
    for (size_t i = 0; i < path.size(); i++) {
      data[i] = path[i].c_str();
    }
    path_slice->data = (void *)data;
    path_slice->len = path.size();
    path_slice->cap = path.size();

    void *procV = nullptr;
    char *ret = nullptr;
    GoCatalog_FindProcedure(this->go_catalog_ptr, (void *)path_slice, &procV, &ret);
    if (procV == nullptr) {
      return ProcedureNotFoundError(path);
    }
    if (ret != nullptr) {
      return absl::InvalidArgumentError(ret);
    }
    *procedure = (const Procedure *)procV;
    return absl::OkStatus();
  }
  
  absl::Status FindType(const absl::Span<const std::string>& path, const Type** type, const FindOptions& options = FindOptions()) {
    if (path.empty()) {
      return EmptyNamePathInternalError("Type");
    }
    GoSlice *path_slice = (GoSlice *)malloc(sizeof(GoSlice));
    const char **data = (const char **)malloc(sizeof(void *) * path.size());
    for (size_t i = 0; i < path.size(); i++) {
      data[i] = path[i].c_str();
    }
    path_slice->data = (void *)data;
    path_slice->len = path.size();
    path_slice->cap = path.size();

    void *typeV = nullptr;
    char *ret = nullptr;
    GoCatalog_FindType(this->go_catalog_ptr, (void *)path_slice, &typeV, &ret);
    if (typeV == nullptr) {
      return TypeNotFoundError(path);
    }
    if (ret != nullptr) {
      return absl::InvalidArgumentError(ret);
    }
    *type = (const Type *)typeV;
    return absl::OkStatus();
  }

  absl::Status FindConstantWithPathPrefix(const absl::Span<const std::string> path, int* num_names_consumed, const Constant** constant, const FindOptions& options = FindOptions()) {
    if (path.empty()) {
      return EmptyNamePathInternalError("Constant");
    }
    GoSlice *path_slice = (GoSlice *)malloc(sizeof(GoSlice));
    const char **data = (const char **)malloc(sizeof(void *) * path.size());
    for (size_t i = 0; i < path.size(); i++) {
      data[i] = path[i].c_str();
    }
    path_slice->data = (void *)data;
    path_slice->len = path.size();
    path_slice->cap = path.size();

    void *constV = nullptr;
    char *ret = nullptr;
    GoCatalog_FindConstant(this->go_catalog_ptr, (void *)path_slice, num_names_consumed, &constV, &ret);
    if (constV == nullptr) {
      return ConstantNotFoundError(path);
    }
    if (ret != nullptr) {
      return absl::InvalidArgumentError(ret);
    }
    *constant = (const Constant *)constV;
    return absl::OkStatus();
  }
    
  absl::Status FindConversion(const Type* from_type, const Type* to_type, const FindConversionOptions& options, Conversion* conversion) {
    void *convV = nullptr;
    char *ret = nullptr;
    GoCatalog_FindConversion(this->go_catalog_ptr, (void *)from_type, (void *)to_type, &convV, &ret);
    if (convV == nullptr) {
      return ConversionNotFoundError(from_type, to_type, options);
    }
    if (ret != nullptr) {
      return absl::InvalidArgumentError(ret);
    }
    *conversion = *(Conversion *)convV;
    return absl::OkStatus();
  }
  
  absl::StatusOr<TypeListView> GetExtendedTypeSuperTypes(const Type* type) {
    void *listV = nullptr;
    char *ret = nullptr;
    GoCatalog_ExtendedTypeSuperTypes(this->go_catalog_ptr, (void *)type, &listV, &ret);
    if (ret != nullptr) {
      return absl::InvalidArgumentError(ret);
    }
    return *(TypeListView *)listV;
  }
  
  std::string SuggestTable(const absl::Span<const std::string>& mistyped_path) {
    if (mistyped_path.empty()) {
      return "";
    }
    GoSlice *path_slice = (GoSlice *)malloc(sizeof(GoSlice));
    const char **data = (const char **)malloc(sizeof(void *) * mistyped_path.size());
    for (size_t i = 0; i < mistyped_path.size(); i++) {
      data[i] = mistyped_path[i].c_str();
    }
    path_slice->data = (void *)data;
    path_slice->len = mistyped_path.size();
    path_slice->cap = mistyped_path.size();

    return std::string(GoCatalog_SuggestTable(this->go_catalog_ptr, (void *)path_slice));
  }
  
  std::string SuggestModel(const absl::Span<const std::string>& mistyped_path) {
    if (mistyped_path.empty()) {
      return "";
    }
    GoSlice *path_slice = (GoSlice *)malloc(sizeof(GoSlice));
    const char **data = (const char **)malloc(sizeof(void *) * mistyped_path.size());
    for (size_t i = 0; i < mistyped_path.size(); i++) {
      data[i] = mistyped_path[i].c_str();
    }
    path_slice->data = (void *)data;
    path_slice->len = mistyped_path.size();
    path_slice->cap = mistyped_path.size();

    return std::string(GoCatalog_SuggestModel(this->go_catalog_ptr, (void *)path_slice));
  }

  std::string SuggestFunction(const absl::Span<const std::string>& mistyped_path) {
    if (mistyped_path.empty()) {
      return "";
    }
    GoSlice *path_slice = (GoSlice *)malloc(sizeof(GoSlice));
    const char **data = (const char **)malloc(sizeof(void *) * mistyped_path.size());
    for (size_t i = 0; i < mistyped_path.size(); i++) {
      data[i] = mistyped_path[i].c_str();
    }
    path_slice->data = (void *)data;
    path_slice->len = mistyped_path.size();
    path_slice->cap = mistyped_path.size();

    return std::string(GoCatalog_SuggestFunction(this->go_catalog_ptr, (void *)path_slice));
  }
  
  std::string SuggestTableValuedFunction(const absl::Span<const std::string>& mistyped_path) {
    if (mistyped_path.empty()) {
      return "";
    }
    GoSlice *path_slice = (GoSlice *)malloc(sizeof(GoSlice));
    const char **data = (const char **)malloc(sizeof(void *) * mistyped_path.size());
    for (size_t i = 0; i < mistyped_path.size(); i++) {
      data[i] = mistyped_path[i].c_str();
    }
    path_slice->data = (void *)data;
    path_slice->len = mistyped_path.size();
    path_slice->cap = mistyped_path.size();

    return std::string(GoCatalog_SuggestTableValuedFunction(this->go_catalog_ptr, (void *)path_slice));
  }
  
  std::string SuggestConstant(const absl::Span<const std::string>& mistyped_path) {
    if (mistyped_path.empty()) {
      return "";
    }
    GoSlice *path_slice = (GoSlice *)malloc(sizeof(GoSlice));
    const char **data = (const char **)malloc(sizeof(void *) * mistyped_path.size());
    for (size_t i = 0; i < mistyped_path.size(); i++) {
      data[i] = mistyped_path[i].c_str();
    }
    path_slice->data = (void *)data;
    path_slice->len = mistyped_path.size();
    path_slice->cap = mistyped_path.size();

    return std::string(GoCatalog_SuggestConstant(this->go_catalog_ptr, (void *)path_slice));
  }

private:
  void *go_catalog_ptr;
};

class GoTable : public Table {
public:
  GoTable(void *go_table_ptr) : go_table_ptr(go_table_ptr) {}
  ~GoTable() {}

  std::string Name() const {
    return std::string(GoTable_Name(this->go_table_ptr));
  }

  std::string FullName() const {
    return std::string(GoTable_FullName(this->go_table_ptr));
  }

  int NumColumns() const {
    return GoTable_NumColumns(this->go_table_ptr);
  }

  const Column* GetColumn(int i) const {
    return (Column *)GoTable_Column(this->go_table_ptr, i);
  }

  std::optional<std::vector<int>> PrimaryKey() const {
    GoSlice *ret = (GoSlice *)GoTable_PrimaryKey(this->go_table_ptr);
    std::vector<int> keys;
    int **data = (int **)ret->data;
    for (int i = 0; i < ret->len; i++) {
      keys.push_back(*data[i]);
    }
    return keys;
  }

  const Column* FindColumnByName(const std::string& name) const {
    return (Column *)GoTable_FindColumnByName(this->go_table_ptr, (char *)name.c_str());
  }

  bool IsValueTable() const {
    if (GoTable_IsValueTable(this->go_table_ptr) == 1) {
      return true;
    }
    return false;
  }

  int64_t GetSerializationId() const {
    return GoTable_SerializationID(this->go_table_ptr);
  }

  absl::StatusOr<std::unique_ptr<EvaluatorTableIterator>> CreateEvaluatorTableIterator(absl::Span<const int> column_idxs) const {
    GoSlice *idxs_slice = (GoSlice *)malloc(sizeof(GoSlice));
    int64_t *data = (int64_t *)malloc(sizeof(int64_t) * column_idxs.size());
    for (size_t i = 0; i < column_idxs.size(); i++) {
      data[i] = column_idxs[i]; 
    }
    idxs_slice->data = (void *)data;
    idxs_slice->len = column_idxs.size();
    idxs_slice->cap = column_idxs.size();

    void *iter = nullptr;
    char *ret  = nullptr;
    GoTable_CreateEvaluatorTableIterator(this->go_table_ptr, (void *)idxs_slice, &iter, &ret);

    if (ret != nullptr) {
      return absl::InvalidArgumentError(ret);
    }
    std::unique_ptr<EvaluatorTableIterator> v((EvaluatorTableIterator *)iter);
    return v;
  }

  std::optional<const AnonymizationInfo> GetAnonymizationInfo() const {
    AnonymizationInfo *ret = (AnonymizationInfo *)GoTable_AnonymizationInfo(this->go_table_ptr);
    if (ret == nullptr) {
      return std::nullopt;
    }
    return *ret;
  }

  bool SupportsAnonymization() const {
    if (GoTable_SupportsAnonymization(this->go_table_ptr) == 1) {
      return true;
    }
    return false;
  }

  std::string GetTableTypeName(ProductMode mode) const {
    return std::string(GoTable_TableTypeName(this->go_table_ptr, int(mode)));
  }

private:
  void *go_table_ptr;
};


void GO_EXPORT(GoCatalog_new)(void * arg0,void ** arg1)
{
  *arg1 = (void *)(new GoCatalog(arg0));
}

void GO_EXPORT(GoTable_new)(void * arg0,void ** arg1)
{
  *arg1 = (void *)(new GoTable(arg0));
}
