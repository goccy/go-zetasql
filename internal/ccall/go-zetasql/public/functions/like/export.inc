#ifndef ZETASQL_PUBLIC_FUNCTIONS_LIKE_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_LIKE_EXPORT_H

#include "zetasql/public/functions/like.h"
#include "zetasql/public/functions/like.cc"

#if 0
namespace zetasql {
  namespace functions {

    bool IsRegexSpecialChar(char c) {
      return false;
    }

    absl::StatusOr<std::string> GetRePatternFromLikePattern(absl::string_view pattern) {
      return "";
    }

    absl::Status CreateLikeRegexpWithOptions(absl::string_view pattern,
                                             const RE2::Options& options,
                                             std::unique_ptr<RE2>* regexp) {
      return absl::OkStatus();
    }

    absl::Status CreateLikeRegexp(absl::string_view pattern, TypeKind type,
                                  std::unique_ptr<RE2>* regexp) {
      return absl::OkStatus();
    }

  }
}
#endif

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-re2/re2/export.inc"

#endif
