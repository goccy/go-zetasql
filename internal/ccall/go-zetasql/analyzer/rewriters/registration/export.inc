#ifndef ZETASQL_ANALYZER_REWRITERS_REGISTRATION_EXPORT_H
#define ZETASQL_ANALYZER_REWRITERS_REGISTRATION_EXPORT_H

#include "zetasql/analyzer/rewriters/registration.h"
#include "zetasql/analyzer/rewriters/registration.cc"

#if 0
namespace zetasql {

  RewriteRegistry& RewriteRegistry::global_instance() {
    RewriteRegistry *v;
    return *v;
  }

  const Rewriter* RewriteRegistry::Get(ResolvedASTRewrite key) const {
    return nullptr;
  }

  absl::Span<const ResolvedASTRewrite> RewriteRegistry::registration_order() const {
    absl::Span<const ResolvedASTRewrite> v;
    return v;
  }

  void RewriteRegistry::Register(ResolvedASTRewrite key,
                                 const Rewriter* rewriter) {
  }

}
#endif

#include "go-zetasql/base/logging/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"
#include "go-absl/types/optional/export.inc"

#endif
