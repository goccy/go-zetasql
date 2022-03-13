#ifndef ABSL_STRINGS_CORD_INTERNAL_EXPORT_H
#define ABSL_STRINGS_CORD_INTERNAL_EXPORT_H

#include "absl/strings/internal/cord_internal.h"
#include "absl/strings/internal/cord_rep_btree.h"
#include "absl/strings/internal/cord_rep_btree_navigator.h"
#include "absl/strings/internal/cord_rep_btree_reader.h"
#include "absl/strings/internal/cord_rep_consume.h"
#include "absl/strings/internal/cord_rep_crc.h"
#include "absl/strings/internal/cord_rep_flat.h"
#include "absl/strings/internal/cord_rep_ring.h"
#include "absl/strings/internal/cord_rep_ring_reader.h"

#include "absl/strings/internal/cord_internal.cc"
#include "absl/strings/internal/cord_rep_btree.cc"
#include "absl/strings/internal/cord_rep_btree_navigator.cc"
#include "absl/strings/internal/cord_rep_btree_reader.cc"
#include "absl/strings/internal/cord_rep_concat.cc"
#include "absl/strings/internal/cord_rep_consume.cc"
#include "absl/strings/internal/cord_rep_crc.cc"
#include "absl/strings/internal/cord_rep_ring.cc"

#if 0
namespace absl {
  namespace cord_internal {

    std::atomic<bool> cord_btree_enabled;
    std::atomic<bool> cord_ring_buffer_enabled;
    std::atomic<bool> shallow_subcords_enabled;
    std::atomic<bool> cord_btree_exhaustive_validation(false);

    void CordRep::Destroy(CordRep* rep) {
    }
  }
}

namespace absl {
  namespace cord_internal {

    namespace {
      using EdgeType = CordRepBtree::EdgeType;
      using OpResult = CordRepBtree::OpResult;
      using CopyResult = CordRepBtree::CopyResult;
      constexpr auto kFront = CordRepBtree::kFront;
      constexpr auto kBack = CordRepBtree::kBack;
    }

    void CordRepBtree::Dump(const CordRep* rep, absl::string_view label,
                            bool include_contents, std::ostream& stream) {
    }

    void CordRepBtree::Dump(const CordRep* rep, absl::string_view label,
                            std::ostream& stream) {
    }

    void CordRepBtree::Dump(const CordRep* rep, std::ostream& stream) {
    }

    template <size_t size>
    void DestroyTree(CordRepBtree* tree) {
    }

    void CordRepBtree::Destroy(CordRepBtree* tree) {
    }

    bool CordRepBtree::IsValid(const CordRepBtree* tree, bool shallow) {
      return false;
    }

    CordRepBtree* CordRepBtree::AssertValid(CordRepBtree* tree, bool shallow) {
      return nullptr;
    }

    const CordRepBtree* CordRepBtree::AssertValid(const CordRepBtree* tree,
                                                  bool shallow) {
      return nullptr;
    }

    template <EdgeType edge_type>
    OpResult CordRepBtree::SetEdge(bool owned, CordRep* edge, size_t delta) {
      OpResult v;
      return v;
    }

    template <EdgeType edge_type>
    CordRepBtree* CordRepBtree::AddCordRep(CordRepBtree* tree, CordRep* rep) {
      return nullptr;
    }

    template <>
    CordRepBtree* CordRepBtree::NewLeaf<kBack>(absl::string_view data,
                                               size_t extra) {
      return nullptr;
    }

    template <>
    CordRepBtree* CordRepBtree::NewLeaf<kFront>(absl::string_view data,
                                                size_t extra) {
      return nullptr;
    }

    template <>
    absl::string_view CordRepBtree::AddData<kBack>(absl::string_view data,
                                                   size_t extra) {
      return nullptr;
    }

    template <>
    absl::string_view CordRepBtree::AddData<kFront>(absl::string_view data,
                                                    size_t extra) {
      absl::string_view v;
      return v;
    }

    template <EdgeType edge_type>
    CordRepBtree* CordRepBtree::AddData(CordRepBtree* tree, absl::string_view data,
                                        size_t extra) {
      return nullptr;
    }

    template <EdgeType edge_type>
    CordRepBtree* CordRepBtree::Merge(CordRepBtree* dst, CordRepBtree* src) {
      return nullptr;
    }

    CopyResult CordRepBtree::CopySuffix(size_t offset) {
      CopyResult v;
      return v;
    }

    CopyResult CordRepBtree::CopyPrefix(size_t n, bool allow_folding) {
      CopyResult v;
      return v;
    }

    CordRep* CordRepBtree::ExtractFront(CordRepBtree* tree) {
      return nullptr;
    }

    CordRepBtree* CordRepBtree::ConsumeBeginTo(CordRepBtree* tree, size_t end,
                                               size_t new_length) {
      return nullptr;
    }

    CordRep* CordRepBtree::RemoveSuffix(CordRepBtree* tree, size_t n) {
      return nullptr;
    }

    CordRep* CordRepBtree::SubTree(size_t offset, size_t n) {
      return nullptr;
    }

    CordRepBtree* CordRepBtree::MergeTrees(CordRepBtree* left,
                                           CordRepBtree* right) {
      return nullptr;
    }

    bool CordRepBtree::IsFlat(absl::string_view* fragment) const {
      return false;
    }

    bool CordRepBtree::IsFlat(size_t offset, const size_t n,
                              absl::string_view* fragment) const {
      return false;
    }

    char CordRepBtree::GetCharacter(size_t offset) const {
      return 0;
    }

    Span<char> CordRepBtree::GetAppendBufferSlow(size_t size) {
      Span<char> v;
      return v;
    }

    CordRepBtree* CordRepBtree::CreateSlow(CordRep* rep) {
      return nullptr;
    }

    CordRepBtree* CordRepBtree::AppendSlow(CordRepBtree* tree, CordRep* rep) {
      return nullptr;
    }

    CordRepBtree* CordRepBtree::PrependSlow(CordRepBtree* tree, CordRep* rep) {
      return nullptr;
    }

    CordRepBtree* CordRepBtree::Append(CordRepBtree* tree, absl::string_view data,
                                       size_t extra) {
      return nullptr;
    }

    CordRepBtree* CordRepBtree::Prepend(CordRepBtree* tree, absl::string_view data,
                                        size_t extra) {
      return nullptr;
    }

    template CordRepBtree* CordRepBtree::AddCordRep<kFront>(CordRepBtree* tree,
                                                            CordRep* rep);
    template CordRepBtree* CordRepBtree::AddCordRep<kBack>(CordRepBtree* tree,
                                                           CordRep* rep);
    template CordRepBtree* CordRepBtree::AddData<kFront>(CordRepBtree* tree,
                                                         absl::string_view data,
                                                         size_t extra);
    template CordRepBtree* CordRepBtree::AddData<kBack>(CordRepBtree* tree,
                                                        absl::string_view data,
                                                        size_t extra);

    void CordRepBtree::Rebuild(CordRepBtree** stack, CordRepBtree* tree,
                               bool consume) {
    }

    CordRepBtree* CordRepBtree::Rebuild(CordRepBtree* tree) {
      return nullptr;
    }

    CordRepBtree::ExtractResult CordRepBtree::ExtractAppendBuffer(
                                                                  CordRepBtree* tree, size_t extra_capacity) {
      CordRepBtree::ExtractResult v;
      return v;
    }
  }
}

namespace absl {
  namespace cord_internal {

    using ReadResult = CordRepBtreeNavigator::ReadResult;

    CordRepBtreeNavigator::Position CordRepBtreeNavigator::Skip(size_t n) {
      CordRepBtreeNavigator::Position v;
      return v;
    }

    ReadResult CordRepBtreeNavigator::Read(size_t edge_offset, size_t n) {
      ReadResult v;
      return v;
    }
  }
}

namespace absl {

  namespace cord_internal {

    absl::string_view CordRepBtreeReader::Read(size_t n, size_t chunk_size,
                                               CordRep*& tree) {
      absl::string_view v;
      return v;
    }

  }
}

namespace absl {
  namespace cord_internal {

    CordRepConcat::ExtractResult CordRepConcat::ExtractAppendBuffer(
                                                                    CordRepConcat* tree, size_t extra_capacity) {
      CordRepConcat::ExtractResult v;
      return v;
    }

  }
}

namespace absl {

  namespace cord_internal {

    void Consume(CordRep* rep, ConsumeFn consume_fn) {
    }

    void ReverseConsume(CordRep* rep, ConsumeFn consume_fn) {
    }

  }
}

namespace absl {

  namespace cord_internal {

    CordRepCrc* CordRepCrc::New(CordRep* child, uint32_t crc) {
      return nullptr;
    }

    void CordRepCrc::Destroy(CordRepCrc* node) {
    }

  }
}


namespace absl {
  ABSL_NAMESPACE_BEGIN
  namespace cord_internal {

    std::ostream& operator<<(std::ostream& s, const CordRepRing& rep) {
      return s;
    }

    void CordRepRing::AddDataOffset(index_type index, size_t n) {
    }

    void CordRepRing::SubLength(index_type index, size_t n) {
    }

    bool CordRepRing::IsValid(std::ostream& output) const {
      return false;
    }

#ifdef EXTRA_CORD_RING_VALIDATION
    CordRepRing* CordRepRing::Validate(CordRepRing* rep, const char* file,
                                       int line) {
      return nullptr;
    }
#endif  // EXTRA_CORD_RING_VALIDATION

    CordRepRing* CordRepRing::New(size_t capacity, size_t extra) {
      return nullptr;
    }

    void CordRepRing::SetCapacityForTesting(size_t capacity) {
    }

    void CordRepRing::Delete(CordRepRing* rep) {
    }

    void CordRepRing::Destroy(CordRepRing* rep) {
    }

    template <bool ref>
    void CordRepRing::Fill(const CordRepRing* src, index_type head,
                           index_type tail) {
    }

    CordRepRing* CordRepRing::Copy(CordRepRing* rep, index_type head,
                                   index_type tail, size_t extra) {
      return nullptr;
    }

    CordRepRing* CordRepRing::Mutable(CordRepRing* rep, size_t extra) {
      return nullptr;
    }

    Span<char> CordRepRing::GetAppendBuffer(size_t size) {
      return {nullptr, 0};
    }

    Span<char> CordRepRing::GetPrependBuffer(size_t size) {
      return {nullptr, 0};
    }

    CordRepRing* CordRepRing::CreateFromLeaf(CordRep* child, size_t offset,
                                             size_t len, size_t extra) {
      return nullptr;
    }

    CordRepRing* CordRepRing::CreateSlow(CordRep* child, size_t extra) {
      return nullptr;
    }

    CordRepRing* CordRepRing::Create(CordRep* child, size_t extra) {
      return nullptr;
    }

    template <CordRepRing::AddMode mode>
    CordRepRing* CordRepRing::AddRing(CordRepRing* rep, CordRepRing* ring,
                                      size_t offset, size_t len) {
      return nullptr;
    }

    CordRepRing* CordRepRing::AppendSlow(CordRepRing* rep, CordRep* child) {
      return nullptr;
    }

    CordRepRing* CordRepRing::AppendLeaf(CordRepRing* rep, CordRep* child,
                                         size_t offset, size_t len) {
      return nullptr;
    }

    CordRepRing* CordRepRing::Append(CordRepRing* rep, CordRep* child) {
      return nullptr;
    }

    CordRepRing* CordRepRing::PrependSlow(CordRepRing* rep, CordRep* child) {
      return nullptr;
    }

    CordRepRing* CordRepRing::PrependLeaf(CordRepRing* rep, CordRep* child,
                                          size_t offset, size_t len) {
      return nullptr;
    }

    CordRepRing* CordRepRing::Prepend(CordRepRing* rep, CordRep* child) {
      return nullptr;
    }

    CordRepRing* CordRepRing::Append(CordRepRing* rep, absl::string_view data,
                                     size_t extra) {
      return nullptr;
    }

    CordRepRing* CordRepRing::Prepend(CordRepRing* rep, absl::string_view data,
                                      size_t extra) {
      return nullptr;
    }

    template <bool wrap>
    CordRepRing::index_type CordRepRing::FindBinary(index_type head,
                                                    index_type tail,
                                                    size_t offset) const {
      CordRepRing::index_type v;
      return v;
    }

    CordRepRing::Position CordRepRing::FindSlow(index_type head,
                                                size_t offset) const {
      CordRepRing::Position v;
      return v;
    }

    CordRepRing::Position CordRepRing::FindTailSlow(index_type head,
                                                    size_t offset) const {
      CordRepRing::Position v;
      return v;
    }

    char CordRepRing::GetCharacter(size_t offset) const {
      return 0;
    }

    CordRepRing* CordRepRing::SubRing(CordRepRing* rep, size_t offset,
                                      size_t len, size_t extra) {
      return nullptr;
    }

    CordRepRing* CordRepRing::RemovePrefix(CordRepRing* rep, size_t len,
                                           size_t extra) {
      return nullptr;
    }

    CordRepRing* CordRepRing::RemoveSuffix(CordRepRing* rep, size_t len,
                                           size_t extra) {
      return nullptr;
    }

  }
}

#endif

#include "go-absl/base/base_internal/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/endian/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/base/throw_delegate/export.inc"
#include "go-absl/container/compressed_tuple/export.inc"
#include "go-absl/container/inlined_vector/export.inc"
#include "go-absl/container/layout/export.inc"
#include "go-absl/functional/function_ref/export.inc"
#include "go-absl/meta/type_traits/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"

#endif
