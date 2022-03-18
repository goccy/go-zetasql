#ifndef ZETASQL_PUBLIC_SIGNATURE_MATCH_RESULT_EXPORT_H
#define ZETASQL_PUBLIC_SIGNATURE_MATCH_RESULT_EXPORT_H

#include "zetasql/public/signature_match_result.h"
#include "zetasql/public/signature_match_result.cc"

#if 0
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
#endif

#include "go-zetasql/public/type/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
