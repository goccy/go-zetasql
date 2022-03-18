#ifndef ZETASQL_REFERENCE_IMPL_COMMON_EXPORT_H
#define ZETASQL_REFERENCE_IMPL_COMMON_EXPORT_H

#include "zetasql/reference_impl/common.h"
#include "zetasql/reference_impl/variable_id.h"

#include "zetasql/reference_impl/common.cc"
#include "zetasql/reference_impl/variable_id.cc"

#if 0
namespace zetasql {

  absl::Status ValidateTypeSupportsEqualityComparison(const Type* type) {
    return absl::OkStatus();
  }

  absl::Status ValidateTypeSupportsOrderComparison(const Type* type) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::string>
  GetCollationNameFromResolvedCollation(const ResolvedCollation& resolved_collation) {
    return "";
  }

  absl::StatusOr<std::unique_ptr<const ZetaSqlCollator>>
  GetCollatorFromResolvedCollation(const ResolvedCollation& resolved_collation) {
    std::unique_ptr<const ZetaSqlCollator> v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<const ZetaSqlCollator>>
  GetCollatorFromResolvedCollationValue(const Value& collation_value) {
    std::unique_ptr<const ZetaSqlCollator> v;
    return v;
  }

}

namespace zetasql {

  VariableId::VariableId(const std::string& name) : name_(name) {
  }

  std::ostream& operator<<(std::ostream& out, const VariableId& id) {
    return out;
  }

}
#endif

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/collator_lite/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-absl/hash/hash/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
