#ifndef ZETASQL_COMMON_JSON_UTIL_EXPORT_H
#define ZETASQL_COMMON_JSON_UTIL_EXPORT_H

#include "zetasql/common/json_util.h"
#include "zetasql/common/json_util.cc"

#if 0
namespace zetasql {

  void JsonEscapeString(absl::string_view raw, std::string* value_string) {
  }

  bool JsonStringNeedsEscaping(absl::string_view raw) {
    return false;
  }

}
#endif

#include "go-absl/strings/str_format/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
