#ifndef ABSL_TYPES_BAD_OPTIONAL_ACCESS_EXPORT_H
#define ABSL_TYPES_BAD_OPTIONAL_ACCESS_EXPORT_H

#include "absl/types/bad_optional_access.h"
#include "absl/types/bad_optional_access.cc"

#if 0
#ifndef ABSL_USES_STD_OPTIONAL

namespace absl {

  bad_optional_access::~bad_optional_access() = default;

  const char* bad_optional_access::what() const noexcept {
    return "optional has no value";
  }

  namespace optional_internal {

    void throw_bad_optional_access() {
      throw std::runtime_error("error");
    }

  }
}

#endif

#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"

#endif
