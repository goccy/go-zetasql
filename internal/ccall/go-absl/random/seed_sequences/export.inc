#ifndef ABSL_RANDOM_SEED_SEQUENCES_EXPORT_H
#define ABSL_RANDOM_SEED_SEQUENCES_EXPORT_H

#include "absl/random/seed_sequences.h"
#include "absl/random/seed_sequences.cc"

#if 0
namespace absl {

  SeedSeq MakeSeedSeq() {
    SeedSeq v;
    return v;
  }

}
#endif

#include "go-absl/random/seed_gen_exception/export.inc"
#include "go-absl/container/inlined_vector/export.inc"
#include "go-absl/random/go_internal/nonsecure_base/export.inc"
#include "go-absl/random/go_internal/pool_urbg/export.inc"
#include "go-absl/random/go_internal/salted_seed_seq/export.inc"
#include "go-absl/random/go_internal/seed_material/export.inc"
#include "go-absl/types/span/export.inc"

#endif
