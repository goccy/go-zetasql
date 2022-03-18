#ifndef ABSL_RANDOM_SEED_GEN_EXCEPTION_EXPORT_H
#define ABSL_RANDOM_SEED_GEN_EXCEPTION_EXPORT_H

#include "absl/random/seed_gen_exception.h"
#include "absl/random/seed_gen_exception.cc"

#if 0
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
#endif

#include "go-absl/base/config/export.inc"

#endif
