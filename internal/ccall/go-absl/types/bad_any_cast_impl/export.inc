#ifndef ABSL_TYPES_BAD_ANY_CAST_IMPL_EXPORT_H
#define ABSL_TYPES_BAD_ANY_CAST_IMPL_EXPORT_H

#include "absl/types/bad_any_cast.h"
#include "absl/types/bad_any_cast.cc"


#if 0
namespace absl {

  bad_any_cast::~bad_any_cast() = default;

  const char* bad_any_cast::what() const noexcept { return "Bad any cast"; }

  namespace any_internal {

    void ThrowBadAnyCast() {
    }

  }
}
#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"

#endif
