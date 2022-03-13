#if 0
void GO_EXPORT(LowLevelAlloc_Arena_Arena)(uint32_t arg0, GO_EXPORT(Arena)* arg1) {
  arg1->ptr = (void *)(new absl::base_internal::LowLevelAlloc::Arena(arg0));
}

void GO_EXPORT(LowLevelAlloc_Alloc)(size_t arg0,void** arg1) {
  *arg1 = absl::base_internal::LowLevelAlloc::Alloc(arg0);
}

void GO_EXPORT(LowLevelAlloc_AllocWithArena)(size_t arg0,GO_EXPORT(Arena) arg1,void** arg2) {
  absl::base_internal::LowLevelAlloc::Arena *arena = (absl::base_internal::LowLevelAlloc::Arena *)arg1.ptr;
  *arg2 = absl::base_internal::LowLevelAlloc::AllocWithArena(arg0, arena);
}

void GO_EXPORT(LowLevelAlloc_Free)(void* arg0) {
  absl::base_internal::LowLevelAlloc::Free(arg0);
}

void GO_EXPORT(LowLevelAlloc_NewArena)(int32_t arg0,GO_EXPORT(Arena)* arg1) {
  absl::base_internal::LowLevelAlloc::Arena *arena = absl::base_internal::LowLevelAlloc::NewArena(arg0);
  arg1->ptr = (void *)arena;
}

void GO_EXPORT(LowLevelAlloc_DeleteArena)(GO_EXPORT(Arena) arg0,int* arg1) {
  absl::base_internal::LowLevelAlloc::Arena *arena = (absl::base_internal::LowLevelAlloc::Arena *)arg0.ptr;
  if (absl::base_internal::LowLevelAlloc::DeleteArena(arena)) {
    *arg1 = 1;
  } else {
    *arg1 = 0;
  }
}

void GO_EXPORT(LowLevelAlloc_DefaultArena)(GO_EXPORT(Arena)* arg0) {
  absl::base_internal::LowLevelAlloc::Arena *arena = absl::base_internal::LowLevelAlloc::DefaultArena();
  arg0->ptr = (void *)arena;
}
#endif
