#ifndef ABSL_CONTAINER_HASHTABLEZ_SAMPLER_EXPORT_H
#define ABSL_CONTAINER_HASHTABLEZ_SAMPLER_EXPORT_H

#include "absl/container/internal/hashtablez_sampler.h"

#include "absl/container/internal/hashtablez_sampler.cc"
#include "absl/container/internal/hashtablez_sampler_force_weak_definition.cc"

#if 0
namespace absl {
  namespace container_internal {

    SamplingState global_next_sample = {0, 0};
    HashtablezSampler& GlobalHashtablezSampler() {
      HashtablezSampler *v;
      return *v;
    }

    HashtablezInfo::HashtablezInfo() = default;
    HashtablezInfo::~HashtablezInfo() = default;

    void HashtablezInfo::PrepareForSampling(int64_t stride,
                                            size_t inline_element_size_value) {
    }

    bool ShouldForceSampling() {
      return false;
    }

    HashtablezInfo* SampleSlow(SamplingState& next_sample,
                               size_t inline_element_size) {
      return nullptr;
    }

    void UnsampleSlow(HashtablezInfo* info) {
    }

    void RecordInsertSlow(HashtablezInfo* info, size_t hash,
                          size_t distance_from_desired) {
    }

    void SetHashtablezConfigListener(HashtablezConfigListener l) {
    }

    bool IsHashtablezEnabled() {
      return false;
    }

    void SetHashtablezEnabled(bool enabled) {
    }

    void SetHashtablezEnabledInternal(bool enabled) {
    }

    int32_t GetHashtablezSampleParameter() {
      return 0;
    }

    void SetHashtablezSampleParameter(int32_t rate) {
    }

    void SetHashtablezSampleParameterInternal(int32_t rate) {
    }

    int32_t GetHashtablezMaxSamples() {
      return 0;
    }

    void SetHashtablezMaxSamples(int32_t max) {
    }

    void SetHashtablezMaxSamplesInternal(int32_t max) {
    }
  }
}

namespace absl {
  namespace container_internal {
    extern "C" {
      bool AbslContainerInternalSampleEverything() {
        return false;
      }
    }
  }
}

#endif

#include "go-absl/base/base/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/have_sse/export.inc"
#include "go-absl/debugging/stacktrace/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/profiling/exponential_biased/export.inc"
#include "go-absl/profiling/sample_recorder/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"
#include "go-absl/utility/utility/export.inc"

#endif
