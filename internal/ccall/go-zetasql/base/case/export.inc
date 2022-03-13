#ifndef ZETASQL_BASE_CASE_EXPORT_H
#define ZETASQL_BASE_CASE_EXPORT_H

#include "zetasql/base/case.h"

#include "zetasql/base/case.cc"

#if 0
namespace zetasql_base {

  static int memcasecmp(const char* s1, const char* s2, size_t len) {
    return 0;
  }

  bool CaseEqual(absl::string_view s1, absl::string_view s2) {
    return false;
  }

  int CaseCompare(absl::string_view s1, absl::string_view s2) {
    return 0;
  }

}
#endif

#include "go-absl/base/core_headers/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
