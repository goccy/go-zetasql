#ifndef ZETASQL_PUBLIC_SIGNATURE_MATCH_RESULT_EXPORT_H
#define ZETASQL_PUBLIC_SIGNATURE_MATCH_RESULT_EXPORT_H

#include "zetasql/public/signature_match_result.h"

namespace zetasql {

  bool SignatureMatchResult::IsCloserMatchThan(const SignatureMatchResult& other_result) const {
    return false;
  }

  void SignatureMatchResult::UpdateFromResult(const SignatureMatchResult& other_result) {
  }

  std::string SignatureMatchResult::DebugString() const {
    return "";
  }

}

#include "go-zetasql/public/type/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
