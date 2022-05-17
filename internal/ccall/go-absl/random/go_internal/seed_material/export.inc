#ifndef ABSL_RANDOM_INTERNAL_SEED_MATERIAL_EXPORT_H
#define ABSL_RANDOM_INTERNAL_SEED_MATERIAL_EXPORT_H

#include "absl/random/internal/seed_material.h"
#include "absl/random/internal/seed_material.cc"

#if 0
namespace absl {
  namespace random_internal {

    bool ReadSeedMaterialFromOSEntropy(absl::Span<uint32_t> values) {
      return false;
    }

    void MixIntoSeedMaterial(absl::Span<const uint32_t> sequence,
                             absl::Span<uint32_t> seed_material) {
    }

    absl::optional<uint32_t> GetSaltMaterial() {
      absl::optional<uint32_t> v;
      return v;
    }
  }
}
#endif

#include "go-absl/random/go_internal/fast_uniform_bits/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/dynamic_annotations/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/optional/export.inc"
#include "go-absl/types/span/export.inc"

#endif
