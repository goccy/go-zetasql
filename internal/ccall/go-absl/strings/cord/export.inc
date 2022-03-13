#ifndef ABSL_STRINGS_CORD_EXPORT_H
#define ABSL_STRINGS_CORD_EXPORT_H

#include "absl/strings/cord.h"
#include "absl/strings/cord_analysis.h"

#include "absl/strings/cord.cc"
#include "absl/strings/cord_analysis.cc"

#if 0

namespace absl {

  using ::absl::cord_internal::CordRep;
  using ::absl::cord_internal::CordRepBtree;
  using ::absl::cord_internal::CordRepConcat;
  using ::absl::cord_internal::CordRepCrc;
  using ::absl::cord_internal::CordRepExternal;
  using ::absl::cord_internal::CordRepFlat;
  using ::absl::cord_internal::CordRepSubstring;
  using ::absl::cord_internal::CordzUpdateTracker;
  using ::absl::cord_internal::InlineData;
  using ::absl::cord_internal::kMaxFlatLength;
  using ::absl::cord_internal::kMinFlatLength;

  using ::absl::cord_internal::kInlinedVectorSize;
  using ::absl::cord_internal::kMaxBytesToCopy;

  void SetConcatChildren(CordRepConcat* concat, CordRep* left,
                                CordRep* right) {
  }

  CordRep* RawConcat(CordRep* left, CordRep* right) {
    return nullptr;
  }

  CordRep* Concat(CordRep* left, CordRep* right) {
    return nullptr;
  }

  CordRep* MakeBalancedTree(CordRep** reps, size_t n) {
    return nullptr;
  }

  CordRepFlat* CreateFlat(const char* data, size_t length,
                                 size_t alloc_hint) {
    return nullptr;
  }

  CordRep* NewBtree(const char* data, size_t length, size_t alloc_hint) {
    return nullptr;
  }

  CordRep* NewTree(const char* data, size_t length, size_t alloc_hint) {
    return nullptr;
  }

  namespace cord_internal {

    void InitializeCordRepExternal(absl::string_view data, CordRepExternal* rep) {
    }

  }

  CordRep* NewSubstring(CordRep* child, size_t offset, size_t length) {
    return nullptr;
  }

  CordRep* CordRepFromString(std::string&& src) {
    return nullptr;
  }

  CordRepBtree* ForceBtree(CordRep* rep) {
    return nullptr;
  }

  void Cord::InlineRep::AppendTreeToInlined(CordRep* tree,
                                            MethodIdentifier method) {
  }

  void Cord::InlineRep::AppendTreeToTree(CordRep* tree, MethodIdentifier method) {
  }

  void Cord::InlineRep::AppendTree(CordRep* tree, MethodIdentifier method) {
  }

  void Cord::InlineRep::PrependTreeToInlined(CordRep* tree,
                                             MethodIdentifier method) {
  }

  void Cord::InlineRep::PrependTreeToTree(CordRep* tree,
                                          MethodIdentifier method) {
  }

  void Cord::InlineRep::PrependTree(CordRep* tree, MethodIdentifier method) {
  }

  void Cord::InlineRep::AssignSlow(const Cord::InlineRep& src) {
  }

  void Cord::InlineRep::UnrefTree() {
  }

  Cord::Cord(absl::string_view src, MethodIdentifier method)
    : contents_(InlineData::kDefaultInit) {
  }

  template <typename T, Cord::EnableIfString<T>>
  Cord::Cord(T&& src) : contents_(InlineData::kDefaultInit) {
  }

  template Cord::Cord(std::string&& src);

  void Cord::DestroyCordSlow() {
  }

  void Cord::Clear() {
  }

  Cord& Cord::AssignLargeString(std::string&& src) {
    return *this;
  }

  Cord& Cord::operator=(absl::string_view src) {
    return *this;
  }

  void Cord::InlineRep::AppendArray(absl::string_view src,
                                    MethodIdentifier method) {
  }

  void Cord::Append(const Cord& src) {
  }

  void Cord::Append(Cord&& src) {
  }

  template <typename T, Cord::EnableIfString<T>>
  void Cord::Append(T&& src) {
  }

  template void Cord::Append(std::string&& src);

  void Cord::Prepend(const Cord& src) {
  }

  void Cord::PrependArray(absl::string_view src, MethodIdentifier method) {
  }

  template <typename T, Cord::EnableIfString<T>>
  inline void Cord::Prepend(T&& src) {
  }

  template void Cord::Prepend(std::string&& src);

  CordRep* RemovePrefixFrom(CordRep* node, size_t n) {
    return nullptr;
  }

  CordRep* RemoveSuffixFrom(CordRep* node, size_t n) {
    return nullptr;
  }

  void Cord::RemovePrefix(size_t n) {
  }

  void Cord::RemoveSuffix(size_t n) {
  }

  CordRep* NewSubRange(CordRep* node, size_t pos, size_t n) {
    return nullptr;
  }

  Cord Cord::Subcord(size_t pos, size_t new_size) const {
    Cord v;
    return v;
  }

  CordRep* Rebalance(CordRep* node) {
    return nullptr;
  }

  void Cord::SetExpectedChecksum(uint32_t crc) {
  }

  absl::optional<uint32_t> Cord::ExpectedChecksum() const {
    absl::optional<uint32_t> v;
    return v;
  }

  template <typename ResultType, typename RHS>
  ResultType GenericCompare(const Cord& lhs, const RHS& rhs,
                            size_t size_to_compare) {
    ResultType v;
    return v;
  }

  bool Cord::EqualsImpl(absl::string_view rhs, size_t size_to_compare) const {
    return false;
  }

  bool Cord::EqualsImpl(const Cord& rhs, size_t size_to_compare) const {
    return false;
  }

  int Cord::Compare(absl::string_view rhs) const {
    return 0;
  }

  int Cord::CompareImpl(const Cord& rhs) const {
    return 0;
  }

  bool Cord::EndsWith(absl::string_view rhs) const {
    return false;
  }

  bool Cord::EndsWith(const Cord& rhs) const {
    return false;
  }

  Cord::operator std::string() const {
    std::string s;
    return s;
  }

  void CopyCordToString(const Cord& src, std::string* dst) {
  }

  void Cord::CopyToArraySlowPath(char* dst) const {
  }

  Cord::ChunkIterator& Cord::ChunkIterator::AdvanceStack() {
    return *this;
  }

  Cord Cord::ChunkIterator::AdvanceAndReadBytes(size_t n) {
    Cord v;
    return v;
  }

  void Cord::ChunkIterator::AdvanceBytesSlowPath(size_t n) {
  }

  char Cord::operator[](size_t i) const {
    return 0;
  }

  absl::string_view Cord::FlattenSlowPath() {
    string_view v;
    return v;
  }

  bool Cord::GetFlatAux(CordRep* rep, absl::string_view* fragment) {
    return false;
  }

  void Cord::ForEachChunkAux(
                             absl::cord_internal::CordRep* rep,
                             absl::FunctionRef<void(absl::string_view)> callback) {
  }

  void DumpNode(CordRep* rep, bool include_data, std::ostream* os,
                int indent) {
  }

  std::string ReportError(CordRep* root, CordRep* node) {
    return "";
  }

  bool VerifyNode(CordRep* root, CordRep* start_node,
                  bool full_validation) {
    return false;
  }

  std::ostream& operator<<(std::ostream& out, const Cord& cord) {
    return out;
  }

  namespace strings_internal {
    size_t CordTestAccess::FlatOverhead() { return 0; }
    size_t CordTestAccess::MaxFlatLength() { return 0; }
    size_t CordTestAccess::FlatTagToLength(uint8_t tag) {
      return 0;
    }
    uint8_t CordTestAccess::LengthToTag(size_t s) {
      return 0;
    }
    size_t CordTestAccess::SizeofCordRepConcat() { return 0; }
    size_t CordTestAccess::SizeofCordRepExternal() {
      return 0;
    }
    size_t CordTestAccess::SizeofCordRepSubstring() {
      return 0;
    }
  }
}

namespace absl {
  namespace cord_internal {
    size_t GetEstimatedMemoryUsage(const CordRep* rep) {
      return 0;
    }

    size_t GetEstimatedFairShareMemoryUsage(const CordRep* rep) {
      return 0;
    }
  }
}

#endif

#include "go-absl/base/base/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/endian/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/container/fixed_array/export.inc"
#include "go-absl/container/inlined_vector/export.inc"
#include "go-absl/functional/function_ref/export.inc"
#include "go-absl/meta/type_traits/export.inc"
#include "go-absl/numeric/bits/export.inc"
#include "go-absl/strings/cord_internal/export.inc"
#include "go-absl/strings/cordz_functions/export.inc"
#include "go-absl/strings/cordz_info/export.inc"
#include "go-absl/strings/cordz_statistics/export.inc"
#include "go-absl/strings/cordz_update_scope/export.inc"
#include "go-absl/strings/cordz_update_tracker/export.inc"
#include "go-absl/strings/internal/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/optional/export.inc"
#include "go-absl/types/span/export.inc"

#endif
