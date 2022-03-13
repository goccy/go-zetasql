#ifndef ZETASQL_PUBLIC_FUNCTIONS_HASH_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_HASH_EXPORT_H

#include "zetasq/public/functions/hash.h"

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

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/endian/export.inc"
#include "go-absl/base/base/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-boringssl/export.inc"
#include "go-farmhash/export.inc"

#endif
