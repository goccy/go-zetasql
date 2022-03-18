#ifndef ABSL_RANDOM_DISTRIBUTIONS_EXPORT_H
#define ABSL_RANDOM_DISTRIBUTIONS_EXPORT_H

#include "absl/random/bernoulli_distribution.h"
#include "absl/random/beta_distribution.h"
#include "absl/random/discrete_distribution.h"
#include "absl/random/distributions.h"
#include "absl/random/exponential_distribution.h"
#include "absl/random/gaussian_distribution.h"
#include "absl/random/log_uniform_int_distribution.h"
#include "absl/random/poisson_distribution.h"
#include "absl/random/uniform_int_distribution.h"
#include "absl/random/uniform_real_distribution.h"
#include "absl/random/zipf_distribution.h"

#include "absl/random/discrete_distribution.cc"
#include "absl/random/gaussian_distribution.cc"

#if 0

namespace absl {
  namespace random_internal {

    std::vector<std::pair<double, size_t>> InitDiscreteDistribution(std::vector<double>* probabilities) {
      std::vector<std::pair<double, size_t>> v;
      return v;
    }

  }
}

namespace absl {
  namespace random_internal {
    const gaussian_distribution_base::Tables gaussian_distribution_base::zg_;
  }
}
#endif

#include "go-absl/base/base_internal/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/meta/type_traits/export.inc"
#include "go-absl/numeric/bits/export.inc"
#include "go-absl/random/go_internal/distribution_caller/export.inc"
#include "go-absl/random/go_internal/fast_uniform_bits/export.inc"
#include "go-absl/random/go_internal/fastmath/export.inc"
#include "go-absl/random/go_internal/generate_real/export.inc"
#include "go-absl/random/go_internal/iostream_state_saver/export.inc"
#include "go-absl/random/go_internal/traits/export.inc"
#include "go-absl/random/go_internal/uniform_helper/export.inc"
#include "go-absl/random/go_internal/wide_multiply/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
