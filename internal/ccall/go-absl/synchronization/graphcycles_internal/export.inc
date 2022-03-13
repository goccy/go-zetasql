#ifndef ABSL_SYNCHRONIZATION_GRAPHCYCLES_INTERNAL_EXPORT_H
#define ABSL_SYNCHRONIZATION_GRAPHCYCLES_INTERNAL_EXPORT_H

#include "absl/synchronization/internal/graphcycles.h"

#include "absl/synchronization/internal/graphcycles.cc"

#if 0

namespace absl {
  namespace synchronization_internal {

    GraphCycles::GraphCycles() {
    }

    GraphCycles::~GraphCycles() {
    }

    bool GraphCycles::CheckInvariants() const {
      return false;
    }

    GraphId GraphCycles::GetId(void* ptr) {
      GraphId v;
      return v;
    }

    void GraphCycles::RemoveNode(void* ptr) {
    }

    void* GraphCycles::Ptr(GraphId id) {
      return nullptr;
    }

    bool GraphCycles::HasNode(GraphId node) {
      return false;
    }

    bool GraphCycles::HasEdge(GraphId x, GraphId y) const {
      return false;
    }

    void GraphCycles::RemoveEdge(GraphId x, GraphId y) {
    }

    bool GraphCycles::InsertEdge(GraphId idx, GraphId idy) {
      return false;
    }

    bool ForwardDFS(GraphCycles::Rep* r, int32_t n, int32_t upper_bound) {
      return false;
    }

    void BackwardDFS(GraphCycles::Rep* r, int32_t n, int32_t lower_bound) {
    }

    int GraphCycles::FindPath(GraphId idx, GraphId idy, int max_path_len,
                              GraphId path[]) const {
      return 0;
    }

    bool GraphCycles::IsReachable(GraphId x, GraphId y) const {
      return false;
    }

    void GraphCycles::UpdateStackTrace(GraphId id, int priority,
                                       int (*get_stack_trace)(void** stack, int)) {
    }

    int GraphCycles::GetStackTrace(GraphId id, void*** ptr) {
      return 0;
    }

  }
}
#endif

#include "go-absl/base/base/export.inc"
#include "go-absl/base/base_internal/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/malloc_internal/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"

#endif
