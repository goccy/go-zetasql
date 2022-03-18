#ifndef ZETASQL_BASE_PATH_EXPORT_H
#define ZETASQL_BASE_PATH_EXPORT_H

#include "zetasql/base/path.h"
#include "zetasql/base/path.cc"

#if 0
namespace zetasql_base {

  std::string JoinPath(absl::string_view path1, absl::string_view path2) {
    return "";
  }

  namespace internal {

    std::string JoinPathImpl(bool honor_abs,
                             std::initializer_list<absl::string_view> paths) {
      return "";
    }

  }

  bool IsAbsolutePath(absl::string_view path) {
    return false;
  }

  std::string AddSlash(absl::string_view path) {
    return "";
  }

  absl::string_view Dirname(absl::string_view path) {
    absl::string_view v;
    return v;
  }

  absl::string_view Basename(absl::string_view path) {
    absl::string_view v;
    return v;
  }

  std::pair<absl::string_view, absl::string_view> SplitPath(absl::string_view path) {
    std::pair<absl::string_view, absl::string_view> v;
    return v;
  }

}
#endif

#include "go-absl/strings/strings/export.inc"

#endif
