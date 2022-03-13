#ifndef ZETASQL_PUBLIC_COLLATOR_LITE_EXPORT_H
#define ZETASQL_PUBLIC_COLLATOR_LITE_EXPORT_H

#include "zetasql/public/collator.h"

namespace zetasql {

  ZetaSqlCollator::~ZetaSqlCollator() {}

  absl::StatusOr<std::unique_ptr<const ZetaSqlCollator>> MakeSqlCollatorLite(absl::string_view collation_name, CollatorLegacyUnicodeMode mode) {
    absl::StatusOr<std::unique_ptr<const ZetaSqlCollator>> v;
    return v;
  }

  namespace internal {
    void RegisterDefaultCollatorImpl() {
    }

    void RegisterIcuCollatorImpl(std::function<absl::StatusOr<std::unique_ptr<const ZetaSqlCollator>>(absl::string_view, CollatorLegacyUnicodeMode)> create_fn) {
    }
  }

}

#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"

#endif
