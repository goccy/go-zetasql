#ifndef ABSL_CONTAINER_RAW_HASH_SET_EXPORT_H
#define ABSL_CONTAINER_RAW_HASH_SET_EXPORT_H

#include "absl/container/internal/raw_hash_set.h"

#include "absl/container/internal/raw_hash_set.cc"

#if 0
#include "_cgo_export.h"
namespace absl {
  namespace container_internal {

    alignas(16) ABSL_CONST_INIT ABSL_DLL const ctrl_t kEmptyGroup[16] = {
                                                                         ctrl_t::kSentinel, ctrl_t::kEmpty, ctrl_t::kEmpty, ctrl_t::kEmpty,
                                                                         ctrl_t::kEmpty,    ctrl_t::kEmpty, ctrl_t::kEmpty, ctrl_t::kEmpty,
                                                                         ctrl_t::kEmpty,    ctrl_t::kEmpty, ctrl_t::kEmpty, ctrl_t::kEmpty,
                                                                         ctrl_t::kEmpty,    ctrl_t::kEmpty, ctrl_t::kEmpty, ctrl_t::kEmpty};
    bool ShouldInsertBackwards(size_t hash, const ctrl_t* ctrl) {
      GO_EXPORT(ctrl_t) arg1;
      arg1.ptr = (void *)ctrl;
      int ret;
      GO_EXPORT(ShouldInsertBackwards)(hash, arg1, &ret);
      return ret == 1;
    }

    void ConvertDeletedToEmptyAndFullToDeleted(ctrl_t* ctrl, size_t capacity) {
      GO_EXPORT(ctrl_t) arg0;
      arg0.ptr = (void *)ctrl;
      GO_EXPORT(ConvertDeletedToEmptyAndFullToDeleted)(arg0, capacity);
    }

    template FindInfo find_first_non_full(const ctrl_t*, size_t, size_t);
  }
}
#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/endian/export.inc"
#include "go-absl/container/common/export.inc"
#include "go-absl/container/compressed_tuple/export.inc"
#include "go-absl/container/container_memory/export.inc"
#include "go-absl/container/hash_policy_traits/export.inc"
#include "go-absl/container/hashtable_debug_hooks/export.inc"
#include "go-absl/container/hashtablez_sampler/export.inc"
#include "go-absl/container/have_sse/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/meta/type_traits/export.inc"
#include "go-absl/numeric/bits/export.inc"
#include "go-absl/utility/utility/export.inc"

#endif
