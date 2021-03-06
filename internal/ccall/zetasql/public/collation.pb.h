// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: zetasql/public/collation.proto

#ifndef PROTOBUF_INCLUDED_zetasql_2fpublic_2fcollation_2eproto
#define PROTOBUF_INCLUDED_zetasql_2fpublic_2fcollation_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_zetasql_2fpublic_2fcollation_2eproto 

namespace protobuf_zetasql_2fpublic_2fcollation_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_zetasql_2fpublic_2fcollation_2eproto
namespace zetasql {
class CollationProto;
class CollationProtoDefaultTypeInternal;
extern CollationProtoDefaultTypeInternal _CollationProto_default_instance_;
}  // namespace zetasql
namespace google {
namespace protobuf {
template<> ::zetasql::CollationProto* Arena::CreateMaybeMessage<::zetasql::CollationProto>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace zetasql {

// ===================================================================

class CollationProto : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:zetasql.CollationProto) */ {
 public:
  CollationProto();
  virtual ~CollationProto();

  CollationProto(const CollationProto& from);

  inline CollationProto& operator=(const CollationProto& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  CollationProto(CollationProto&& from) noexcept
    : CollationProto() {
    *this = ::std::move(from);
  }

  inline CollationProto& operator=(CollationProto&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CollationProto& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const CollationProto* internal_default_instance() {
    return reinterpret_cast<const CollationProto*>(
               &_CollationProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(CollationProto* other);
  friend void swap(CollationProto& a, CollationProto& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline CollationProto* New() const final {
    return CreateMaybeMessage<CollationProto>(NULL);
  }

  CollationProto* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<CollationProto>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const CollationProto& from);
  void MergeFrom(const CollationProto& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(CollationProto* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .zetasql.CollationProto child_list = 2;
  int child_list_size() const;
  void clear_child_list();
  static const int kChildListFieldNumber = 2;
  ::zetasql::CollationProto* mutable_child_list(int index);
  ::google::protobuf::RepeatedPtrField< ::zetasql::CollationProto >*
      mutable_child_list();
  const ::zetasql::CollationProto& child_list(int index) const;
  ::zetasql::CollationProto* add_child_list();
  const ::google::protobuf::RepeatedPtrField< ::zetasql::CollationProto >&
      child_list() const;

  // optional string collation_name = 1;
  bool has_collation_name() const;
  void clear_collation_name();
  static const int kCollationNameFieldNumber = 1;
  const ::std::string& collation_name() const;
  void set_collation_name(const ::std::string& value);
  #if LANG_CXX11
  void set_collation_name(::std::string&& value);
  #endif
  void set_collation_name(const char* value);
  void set_collation_name(const char* value, size_t size);
  ::std::string* mutable_collation_name();
  ::std::string* release_collation_name();
  void set_allocated_collation_name(::std::string* collation_name);

  // @@protoc_insertion_point(class_scope:zetasql.CollationProto)
 private:
  void set_has_collation_name();
  void clear_has_collation_name();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::zetasql::CollationProto > child_list_;
  ::google::protobuf::internal::ArenaStringPtr collation_name_;
  friend struct ::protobuf_zetasql_2fpublic_2fcollation_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CollationProto

// optional string collation_name = 1;
inline bool CollationProto::has_collation_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CollationProto::set_has_collation_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CollationProto::clear_has_collation_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CollationProto::clear_collation_name() {
  collation_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_collation_name();
}
inline const ::std::string& CollationProto::collation_name() const {
  // @@protoc_insertion_point(field_get:zetasql.CollationProto.collation_name)
  return collation_name_.GetNoArena();
}
inline void CollationProto::set_collation_name(const ::std::string& value) {
  set_has_collation_name();
  collation_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zetasql.CollationProto.collation_name)
}
#if LANG_CXX11
inline void CollationProto::set_collation_name(::std::string&& value) {
  set_has_collation_name();
  collation_name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:zetasql.CollationProto.collation_name)
}
#endif
inline void CollationProto::set_collation_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_collation_name();
  collation_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zetasql.CollationProto.collation_name)
}
inline void CollationProto::set_collation_name(const char* value, size_t size) {
  set_has_collation_name();
  collation_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zetasql.CollationProto.collation_name)
}
inline ::std::string* CollationProto::mutable_collation_name() {
  set_has_collation_name();
  // @@protoc_insertion_point(field_mutable:zetasql.CollationProto.collation_name)
  return collation_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CollationProto::release_collation_name() {
  // @@protoc_insertion_point(field_release:zetasql.CollationProto.collation_name)
  if (!has_collation_name()) {
    return NULL;
  }
  clear_has_collation_name();
  return collation_name_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CollationProto::set_allocated_collation_name(::std::string* collation_name) {
  if (collation_name != NULL) {
    set_has_collation_name();
  } else {
    clear_has_collation_name();
  }
  collation_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), collation_name);
  // @@protoc_insertion_point(field_set_allocated:zetasql.CollationProto.collation_name)
}

// repeated .zetasql.CollationProto child_list = 2;
inline int CollationProto::child_list_size() const {
  return child_list_.size();
}
inline void CollationProto::clear_child_list() {
  child_list_.Clear();
}
inline ::zetasql::CollationProto* CollationProto::mutable_child_list(int index) {
  // @@protoc_insertion_point(field_mutable:zetasql.CollationProto.child_list)
  return child_list_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::zetasql::CollationProto >*
CollationProto::mutable_child_list() {
  // @@protoc_insertion_point(field_mutable_list:zetasql.CollationProto.child_list)
  return &child_list_;
}
inline const ::zetasql::CollationProto& CollationProto::child_list(int index) const {
  // @@protoc_insertion_point(field_get:zetasql.CollationProto.child_list)
  return child_list_.Get(index);
}
inline ::zetasql::CollationProto* CollationProto::add_child_list() {
  // @@protoc_insertion_point(field_add:zetasql.CollationProto.child_list)
  return child_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::zetasql::CollationProto >&
CollationProto::child_list() const {
  // @@protoc_insertion_point(field_list:zetasql.CollationProto.child_list)
  return child_list_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace zetasql

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_zetasql_2fpublic_2fcollation_2eproto
