#define GET_LIST(list, v) assign_list(list(), v)

template<typename T> void assign_list(const std::vector<T> &val, void **target)
{
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  T **data = (T **)malloc(sizeof(void *) * val.size());
  for (size_t i = 0; i < val.size(); i++) {
    data[i] = new T(val[i]);
  }
  slice->data = (void *)data;
  slice->len = val.size();
  slice->cap = val.size();
  *target = (void *)data;
}

#define GET_STRS(list, v) assign_strs(list(), v)

static void assign_strs(const std::vector<std::string> &val, void **target)
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


#define SET_LIST(list, T, v) list(slice_to_vec<T>(v));

template<typename T> std::vector<T> slice_to_vec(void *slice)
{
  GoSlice *goslice = (GoSlice *)slice;
  T **data = (T **)goslice->data;
  std::vector<T> vec;
  for (int i = 0; i < goslice->len; i++) {
    vec.push_back(*data[i]);
  }
  return vec;
}
