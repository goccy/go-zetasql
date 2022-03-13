#ifndef ZETASQL_BASE_ARENA_EXPORT_H
#define ZETASQL_BASE_ARENA_EXPORT_H

#include "zetasql/base/arena.h"
#include "zetasql/base/arena.cc" // because occur 'Illegal Instruction'
#if 0
namespace zetasql_base {

  const int BaseArena::kDefaultAlignment;
  BaseArena::BaseArena(char* first, const size_t orig_block_size,
                       bool align_to_page)
    : remaining_(0),
      block_size_(orig_block_size),
      freestart_(nullptr),  // set for real in Reset()
      last_alloc_(nullptr),
      overflow_blocks_(nullptr),
      first_block_externally_owned_(first != nullptr),
      page_aligned_(align_to_page),
      blocks_alloced_(1) {
  }

  BaseArena::~BaseArena() {
  }

  int BaseArena::block_count() const {
    return 0;
  }

  bool BaseArena::SatisfyAlignment(size_t alignment) {
    return false;
  }

  void BaseArena::Reset() {
  }

  void BaseArena::MakeNewBlock(const uint32_t alignment) {
  }

  static uint32_t GCD(uint32_t x, uint32_t y) {
    return 0;
  }

  static uint32_t LeastCommonMultiple(uint32_t a, uint32_t b) {
    return 0;
  }

  BaseArena::AllocatedBlock* BaseArena::AllocNewBlock(const size_t block_size,
                                                      const uint32_t alignment) {
    return nullptr;
  }

  const BaseArena::AllocatedBlock *BaseArena::IndexToBlock(int index) const {
    return nullptr;
  }

  void* BaseArena::GetMemoryFallback(const size_t size, const int alignment) {
    return nullptr;
  }

  void BaseArena::FreeBlocks() {
  }

  bool BaseArena::AdjustLastAlloc(void *last_alloc, const size_t newsize) {
    return false;
  }

  char* UnsafeArena::Realloc(char* original, size_t oldsize, size_t newsize) {
    return nullptr;
  }

  char* SafeArena::Realloc(char* original, size_t oldsize, size_t newsize) {
    return nullptr;
  }

  void UnsafeArena::UnusedKeyMethod() {}
  void SafeArena::UnusedKeyMethod() {}

}
#endif
#include "go-zetasql/base/logging/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"

#endif
