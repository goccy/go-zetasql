#ifndef ABSL_RANDOM_SEED_GEN_EXCEPTION_EXPORT_H
#define ABSL_RANDOM_SEED_GEN_EXCEPTION_EXPORT_H

#include "absl/random/seed_gen_exception.h"

namespace absl {
  SeedGenException::~SeedGenException() = default;
  const char* SeedGenException::what() const noexcept {
    return nullptr;
  }

  namespace random_internal {

    void ThrowSeedGenException() {
      throw std::runtime_error("error");
    }

  }
}

#include "go-absl/base/config/export.inc"

#endif
