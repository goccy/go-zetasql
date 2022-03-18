#ifndef ZETASQL_PUBLIC_FUNCTIONS_HASH_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_HASH_EXPORT_H

#include "zetasql/public/functions/hash.h"
#include "zetasql/public/functions/hash.cc"

#if 0
namespace zetasql {
  namespace functions {

    std::unique_ptr<Hasher> Hasher::Create(Algorithm algorithm) {
      std::unique_ptr<Hasher> v;
      return v;
    }

    int64_t FarmFingerprint(absl::string_view input) {
      return 0;
    }

  }
}
#endif

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/endian/export.inc"
#include "go-boringssl/boringssl/export.inc"
#include "go-absl/base/base/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-farmhash/farmhash/export.inc"

#endif
