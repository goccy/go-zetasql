#ifndef ZETASQL_PUBLIC_COLLATOR_EXPORT_H
#define ZETASQL_PUBLIC_COLLATOR_EXPORT_H

#include "zetasql/public/collator.h"
#include "zetasql/public/collator.cc"

#if 0
namespace zetasql {

  absl::StatusOr<std::unique_ptr<const ZetaSqlCollator>> MakeSqlCollator(absl::string_view collation_name,
                                                                         CollatorLegacyUnicodeMode legacy_unicode_mode) {
    absl::StatusOr<std::unique_ptr<const ZetaSqlCollator>> v;
    return v;
  }

}
#endif

#include "go-zetasql/public/collator_lite/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/cord/export.inc"
#include "go-icu/icu/export.inc"

#endif
