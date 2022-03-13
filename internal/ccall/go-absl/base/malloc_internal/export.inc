#ifndef ABSL_BASE_MALLOC_INTERNAL_EXPORT_H
#define ABSL_BASE_MALLOC_INTERNAL_EXPORT_H

#include "absl/base/internal/low_level_alloc.h"
#include "absl/base/internal/low_level_alloc.cc"

#if 0
#include "_cgo_export.h"

namespace absl {
  namespace base_internal {

    struct LowLevelAlloc::Arena {
      explicit Arena(uint32_t flags_value);

      base_internal::SpinLock mu;
      int32_t allocation_count ABSL_GUARDED_BY(mu);
      const uint32_t flags;
      const size_t pagesize;
      const size_t round_up;
      const size_t min_size;
      uint32_t random ABSL_GUARDED_BY(mu);
    };

    LowLevelAlloc::Arena *LowLevelAlloc::DefaultArena() {
      GO_EXPORT(Arena) arena;
      GO_EXPORT(LowLevelAlloc_DefaultArena)(&arena);
      return (LowLevelAlloc::Arena *)arena.ptr;
    }

    LowLevelAlloc::Arena::Arena(uint32_t flags_value)
      : mu(base_internal::SCHEDULE_KERNEL_ONLY),
        allocation_count(0),
        flags(flags_value),
        pagesize(0),
        round_up(0),
        min_size(2 * round_up),
        random(0) {
      GO_EXPORT(Arena) ret;
      GO_EXPORT(LowLevelAlloc_Arena_Arena)(flags_value, &ret);
      memcpy(this, ret.ptr, sizeof(LowLevelAlloc::Arena));
      free(ret.ptr);
    }

    LowLevelAlloc::Arena *LowLevelAlloc::NewArena(int32_t flags) {
      GO_EXPORT(Arena) arena;
      GO_EXPORT(LowLevelAlloc_NewArena)(flags, &arena);
      return (LowLevelAlloc::Arena *)arena.ptr;
    }

    bool LowLevelAlloc::DeleteArena(Arena *arena) {
      GO_EXPORT(Arena) arg0;
      arg0.ptr = arena;
      int ret;
      GO_EXPORT(LowLevelAlloc_DeleteArena)(arg0, &ret);
      return ret == 1;
    }

    void LowLevelAlloc::Free(void *v) {
      GO_EXPORT(LowLevelAlloc_Free)(v);
    }

    void *LowLevelAlloc::Alloc(size_t request) {
      void *ret;
      GO_EXPORT(LowLevelAlloc_Alloc)(request, &ret);
      return ret;
    }

    void *LowLevelAlloc::AllocWithArena(size_t request, Arena *arena) {
      GO_EXPORT(Arena) arenaV;
      arenaV.ptr = (void *)arena;
      void *ret;
      GO_EXPORT(LowLevelAlloc_AllocWithArena)(request, arenaV, &ret);
      return ret;
    }
  }
}

#endif

#include "go-absl/base/base/export.inc"
#include "go-absl/base/base_internal/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/dynamic_annotations/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"

#endif
