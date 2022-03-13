#ifndef ZETASQL_REFERENCE_IMPL_REWRITE_FLAGS_EXPORT_H
#define ZETASQL_REFERENCE_IMPL_REWRITE_FLAGS_EXPORT_H

#include "zetasql/reference_impl/rewrite_flags.h"

namespace zetasql {

  std::string AbslUnparseFlag(RewriteSet set) {
    return "";
  }

  bool AbslParseFlag(absl::string_view text, RewriteSet* set,
                     std::string* error) {
    return false;
  }

}

#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-absl/container/btree/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
