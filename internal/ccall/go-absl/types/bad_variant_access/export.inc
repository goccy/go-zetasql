#ifndef ABSL_TYPES_BAD_VARIANT_ACCESS_EXPORT_H
#define ABSL_TYPES_BAD_VARIANT_ACCESS_EXPORT_H

#include "absl/types/bad_variant_access.h"

#include "absl/types/bad_variant_access.cc"

#if 0

#ifndef ABSL_USES_STD_VARIANT

namespace absl {
  bad_variant_access::~bad_variant_access() = default;

  const char* bad_variant_access::what() const noexcept {
    return "Bad variant access";
  }

  namespace variant_internal {

    void ThrowBadVariantAccess() {
      throw std::runtime_error("error");
    }

    void Rethrow() {
      throw std::runtime_error("error");
    }

  }
}

#endif

#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"

#endif
