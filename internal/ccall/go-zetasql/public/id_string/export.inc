#ifndef ZETASQL_PUBLIC_ID_STRING_EXPORT_H
#define ZETASQL_PUBLIC_ID_STRING_EXPORT_H

#include "zetasql/public/id_string.h"
#include "zetasql/public/id_string.cc"

#if 0
namespace zetasql {

#ifndef NDEBUG

  absl::Mutex IdStringPool::global_mutex_;

  std::unordered_set<int64_t>* IdStringPool::live_pool_ids_ = nullptr;

  int64_t IdStringPool::max_pool_id_ = 0;

  void IdStringPool::CheckPoolIdAlive(int64_t pool_id) {
  }
#endif

  IdStringPool::IdStringPool()
#ifndef NDEBUG
    : arena_(std::make_shared<zetasql_base::UnsafeArena>(/*block_size=*/1024)),
      pool_id_(AllocatePoolId()) {
#else
    : arena_(std::make_shared<zetasql_base::UnsafeArena>(/*block_size=*/1024)) {
#endif
    }

    IdStringPool::IdStringPool(const std::shared_ptr<zetasql_base::UnsafeArena>& arena)
#ifndef NDEBUG
      : arena_(arena), pool_id_(AllocatePoolId()) {
#else
      : arena_(arena) {
#endif
    }

    IdStringPool::~IdStringPool() {
    }

#ifndef NDEBUG
    int64_t IdStringPool::AllocatePoolId() {
      return 0;
    }
#endif

    const IdString* const IdString::kEmptyString = new IdString(IdString::MakeGlobal(""));

    IdString IdString::ToLower(IdStringPool* pool) const {
      IdString v;
      return v;
    }

 }

#endif

#include "go-zetasql/base/arena/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/case/export.inc"
#include "go-zetasql/base/endian/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/hash/hash/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"

#endif
