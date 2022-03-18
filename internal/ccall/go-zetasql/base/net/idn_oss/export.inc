#ifndef ZETASQL_BASE_NET_IDN_OSS_EXPORT_H
#define ZETASQL_BASE_NET_IDN_OSS_EXPORT_H

#include "zetasql/base/net/idn_oss.h"
#include "zetasql/base/net/idn_oss.cc"

#if 0
namespace zetasql::internal {

  bool ToASCII(absl::string_view utf8_host, std::string* ascii_host) {
    return false;
  }

}
#endif

#include "go-zetasql/base/logging/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-icu/icu/export.inc"

#endif
