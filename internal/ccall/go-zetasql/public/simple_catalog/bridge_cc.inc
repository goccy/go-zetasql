#define SIMPLE_CATALOG_GET_LIST(list, v) simple_catalog_assign_list(list(), v)

template<typename T> void simple_catalog_assign_list(const std::vector<T> &val, void **target)
{
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  T **data = (T **)malloc(sizeof(void *) * val.size());
  for (size_t i = 0; i < val.size(); i++) {
    data[i] = new T(val[i]);
  }
  slice->data = (void *)data;
  slice->len = val.size();
  slice->cap = val.size();
  *target = (void *)slice;
}

#define SIMPLE_CATALOG_GET_STRS(list, v) simple_catalog_assign_strs(list(), v)

static void simple_catalog_assign_strs(const std::vector<std::string> &val, void **target)
{
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  const char **data = (const char **)malloc(sizeof(void *) * val.size());
  for (size_t i = 0; i < val.size(); i++) {
    data[i] = (new std::string(val[i]))->c_str();
  }
  slice->data = (void *)data;
  slice->len = val.size();
  slice->cap = val.size();
  *target = (void *)slice;
}


#define SIMPLE_CATALOG_SET_LIST(list, T, v) list(simple_catalog_slice_to_vec<T>(v));

template<typename T> std::vector<T> simple_catalog_slice_to_vec(void *slice)
{
  GoSlice *goslice = (GoSlice *)slice;
  T **data = (T **)goslice->data;
  std::vector<T> vec;
  for (int i = 0; i < goslice->len; i++) {
    vec.push_back(*data[i]);
  }
  return vec;
}

std::vector<std::string> simple_catalog_slice_to_strs(void *slice)
{
  GoSlice *goslice = (GoSlice *)slice;
  char **data = (char **)goslice->data;
  std::vector<std::string> vec; 
  for (int i = 0; i < goslice->len; i++) {
    vec.push_back(std::string(data[i]));
  }
  return vec;
}

std::vector<const zetasql::Column *> simple_catalog_columns_to_vec(void *slice)
{
  GoSlice *goslice = (GoSlice *)slice;
  zetasql::Column **data = (zetasql::Column **)goslice->data;
  std::vector<const zetasql::Column *> vec;
  for (int i = 0; i < goslice->len; i++) {
    vec.push_back(data[i]);
  }
  return vec;
}
