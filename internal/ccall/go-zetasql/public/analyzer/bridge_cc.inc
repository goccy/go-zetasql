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
  *target = (void *)slice;
}

#define GET_UNIQUE_PTR_LIST(list, v) get_unique_ptr_list(list(), v)

template<typename T> void get_unique_ptr_list(const std::vector<std::unique_ptr<T>> &val, void **target)
{
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  T **data = (T **)malloc(sizeof(void *) * val.size());
  for (size_t i = 0; i < val.size(); i++) {
    data[i] = val[i].get();
  }
  slice->data = (void *)data;
  slice->len = val.size();
  slice->cap = val.size();
  *target = (void *)slice;
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

#define GET_INTS(list, v) assign_ints(list(), v)

static void assign_ints(const std::vector<int> &val, void **target)
{
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  int *data = (int *)malloc(sizeof(int) * val.size());
  for (size_t i = 0; i < val.size(); i++) {
    data[i] = val[i];
  }
  slice->data = (void *)data;
  slice->len = val.size();
  slice->cap = val.size();
  *target = (void *)slice;
}

#define GET_ENUMS(list, v) assign_enums(list(), v)

template<typename T> void assign_enums(const std::vector<T> &val, void **target)
{
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  int *data = (int *)malloc(sizeof(int) * val.size());
  for (size_t i = 0; i < val.size(); i++) {
    data[i] = (int)val[i];
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

std::vector<std::string> slice_to_strs(void *slice)
{
  GoSlice *goslice = (GoSlice *)slice;
  char **data = (char **)goslice->data;
  std::vector<std::string> vec;
  for (int i = 0; i < goslice->len; i++) {
    vec.push_back(data[i]);
  }
  return vec;
}

#define UNIQUE_PTR_LIST_TO_VEC(vecptr, T, v) do {                   \
    std::vector<std::unique_ptr<const zetasql::T>> vec;             \
    GoSlice *goslice = (GoSlice *)v;                                \
    zetasql::T **data = (zetasql::T **)goslice->data;               \
    for (int i = 0; i < goslice->len; i++) {                        \
      auto p = zetasql::Make ## T();                                \
      memcpy((void *)p.get(), (void *)data[i], sizeof(zetasql::T)); \
      vec.push_back(std::move(p));                                  \
    }                                                               \
    *vecptr = std::move(vec);                                       \
  } while (0)

#define SET_UNIQUE_PTR(setter, T, v) do {                   \
    auto p = zetasql::Make ## T();                          \
    memcpy((void *)p.get(), (void *)v, sizeof(zetasql::T)); \
    setter(std::move(p));                                   \
  } while (0)

#define SET_INTS(list, v) do {                  \
    std::vector<int> vec;                       \
    GoSlice *goslice = (GoSlice *)v;            \
    int *data = (int *)goslice->data;           \
    for (int i = 0; i < goslice->len; i++) {    \
      vec.push_back(data[i]);                   \
    }                                           \
    list(vec);                                  \
  } while (0)

#define SET_ENUMS(list, T, v) do {              \
    std::vector<T> vec;                         \
    GoSlice *goslice = (GoSlice *)v;            \
    int *data = (int *)goslice->data;           \
    for (int i = 0; i < goslice->len; i++) {    \
      vec.push_back((T)data[i]);                \
    }                                           \
    list(vec);                                  \
  } while (0)

#define SET_UNIQUE_PTR_LIST(list, T, v) do {                        \
    std::vector<std::unique_ptr<const zetasql::T>> vec;             \
    GoSlice *goslice = (GoSlice *)v;                                \
    zetasql::T **data = (zetasql::T **)goslice->data;               \
    for (int i = 0; i < goslice->len; i++) {                        \
      auto p = zetasql::Make ## T();                                \
      memcpy((void *)p.get(), (void *)data[i], sizeof(zetasql::T)); \
      vec.push_back(std::move(p));                                  \
    }                                                               \
    list(std::move(vec));                                           \
  } while (0)

#define SET_UNIQUE_PTR_EXPR_LIST(list, v) do {                      \
    std::vector<std::unique_ptr<const zetasql::ResolvedExpr>> vec;  \
    GoSlice *goslice = (GoSlice *)v;                                \
    void **data = (void **)goslice->data;                           \
    for (int i = 0; i < goslice->len; i++) {                        \
      vec.push_back(make_unique_expr(data[i]));                     \
    }                                                               \
    list(std::move(vec));                                           \
  } while (0)

#define SET_UNIQUE_PTR_ACTION_LIST(list, v) do {                    \
    std::vector<std::unique_ptr<const zetasql::ResolvedAlterAction>> vec; \
    GoSlice *goslice = (GoSlice *)v;                                \
    void **data = (void **)goslice->data;                           \
    for (int i = 0; i < goslice->len; i++) {                        \
      vec.push_back(make_unique_action(data[i]));                   \
    }                                                               \
    list(std::move(vec));                                           \
  } while (0)

#define SET_UNIQUE_PTR_CONSTRAINT_LIST(list, v) do {                    \
    std::vector<std::unique_ptr<const zetasql::ResolvedConstraint>> vec; \
    GoSlice *goslice = (GoSlice *)v;                                    \
    void **data = (void **)goslice->data;                               \
    for (int i = 0; i < goslice->len; i++) {                            \
      vec.push_back(make_unique_constraint(data[i]));                   \
    }                                                                   \
    list(std::move(vec));                                               \
  } while (0)

#define SET_UNIQUE_PTR_SCAN_LIST(list, v) do {                      \
    std::vector<std::unique_ptr<const zetasql::ResolvedExpr>> vec;  \
    GoSlice *goslice = (GoSlice *)v;                                \
    void **data = (void **)goslice->data;                           \
    for (int i = 0; i < goslice->len; i++) {                        \
      vec.push_back(make_unique_scan(data[i]));                     \
    }                                                               \
    list(std::move(vec));                                           \
  } while (0)

#define ADD_UNIQUE_PTR_LIST(list, T, v) do {                \
    auto p = zetasql::Make ## T();                          \
    memcpy((void *)p.get(), (void *)v, sizeof(zetasql::T)); \
    list(std::move(p));                                     \
  } while (0)

#define ADD_UNIQUE_PTR_EXPR_LIST(list, v) do {  \
    list(make_unique_expr(v));                  \
  } while (0)

#define ADD_UNIQUE_PTR_ACTION_LIST(list, v) do {    \
    list(make_unique_action(v));                    \
  } while (0)

#define ADD_UNIQUE_PTR_CONSTRAINT_LIST(list, v) do {    \
    list(make_unique_constraint(v));                    \
  } while (0)

#define ADD_UNIQUE_PTR_SCAN_LIST(list, v) do {  \
    list(make_unique_scan(v));                  \
  } while (0)

#define ADD_LIST(list, T, v) list(*(T *)v)
