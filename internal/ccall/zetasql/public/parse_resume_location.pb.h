// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: zetasql/public/parse_resume_location.proto

#ifndef PROTOBUF_INCLUDED_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto
#define PROTOBUF_INCLUDED_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto 

namespace protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto {
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
}  // namespace protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto
namespace zetasql {
class ParseResumeLocationProto;
class ParseResumeLocationProtoDefaultTypeInternal;
extern ParseResumeLocationProtoDefaultTypeInternal _ParseResumeLocationProto_default_instance_;
}  // namespace zetasql
namespace google {
namespace protobuf {
template<> ::zetasql::ParseResumeLocationProto* Arena::CreateMaybeMessage<::zetasql::ParseResumeLocationProto>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace zetasql {

// ===================================================================

class ParseResumeLocationProto : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:zetasql.ParseResumeLocationProto) */ {
 public:
  ParseResumeLocationProto();
  virtual ~ParseResumeLocationProto();

  ParseResumeLocationProto(const ParseResumeLocationProto& from);

  inline ParseResumeLocationProto& operator=(const ParseResumeLocationProto& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ParseResumeLocationProto(ParseResumeLocationProto&& from) noexcept
    : ParseResumeLocationProto() {
    *this = ::std::move(from);
  }

  inline ParseResumeLocationProto& operator=(ParseResumeLocationProto&& from) noexcept {
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
  static const ParseResumeLocationProto& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ParseResumeLocationProto* internal_default_instance() {
    return reinterpret_cast<const ParseResumeLocationProto*>(
               &_ParseResumeLocationProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(ParseResumeLocationProto* other);
  friend void swap(ParseResumeLocationProto& a, ParseResumeLocationProto& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ParseResumeLocationProto* New() const final {
    return CreateMaybeMessage<ParseResumeLocationProto>(NULL);
  }

  ParseResumeLocationProto* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ParseResumeLocationProto>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ParseResumeLocationProto& from);
  void MergeFrom(const ParseResumeLocationProto& from);
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
  void InternalSwap(ParseResumeLocationProto* other);
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

  // optional string input = 1;
  bool has_input() const;
  void clear_input();
  static const int kInputFieldNumber = 1;
  const ::std::string& input() const;
  void set_input(const ::std::string& value);
  #if LANG_CXX11
  void set_input(::std::string&& value);
  #endif
  void set_input(const char* value);
  void set_input(const char* value, size_t size);
  ::std::string* mutable_input();
  ::std::string* release_input();
  void set_allocated_input(::std::string* input);

  // optional string filename = 4;
  bool has_filename() const;
  void clear_filename();
  static const int kFilenameFieldNumber = 4;
  const ::std::string& filename() const;
  void set_filename(const ::std::string& value);
  #if LANG_CXX11
  void set_filename(::std::string&& value);
  #endif
  void set_filename(const char* value);
  void set_filename(const char* value, size_t size);
  ::std::string* mutable_filename();
  ::std::string* release_filename();
  void set_allocated_filename(::std::string* filename);

  // optional int32 byte_position = 2;
  bool has_byte_position() const;
  void clear_byte_position();
  static const int kBytePositionFieldNumber = 2;
  ::google::protobuf::int32 byte_position() const;
  void set_byte_position(::google::protobuf::int32 value);

  // optional bool allow_resume = 3;
  bool has_allow_resume() const;
  void clear_allow_resume();
  static const int kAllowResumeFieldNumber = 3;
  bool allow_resume() const;
  void set_allow_resume(bool value);

  // @@protoc_insertion_point(class_scope:zetasql.ParseResumeLocationProto)
 private:
  void set_has_filename();
  void clear_has_filename();
  void set_has_input();
  void clear_has_input();
  void set_has_byte_position();
  void clear_has_byte_position();
  void set_has_allow_resume();
  void clear_has_allow_resume();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr input_;
  ::google::protobuf::internal::ArenaStringPtr filename_;
  ::google::protobuf::int32 byte_position_;
  bool allow_resume_;
  friend struct ::protobuf_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ParseResumeLocationProto

// optional string filename = 4;
inline bool ParseResumeLocationProto::has_filename() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ParseResumeLocationProto::set_has_filename() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ParseResumeLocationProto::clear_has_filename() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ParseResumeLocationProto::clear_filename() {
  filename_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_filename();
}
inline const ::std::string& ParseResumeLocationProto::filename() const {
  // @@protoc_insertion_point(field_get:zetasql.ParseResumeLocationProto.filename)
  return filename_.GetNoArena();
}
inline void ParseResumeLocationProto::set_filename(const ::std::string& value) {
  set_has_filename();
  filename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zetasql.ParseResumeLocationProto.filename)
}
#if LANG_CXX11
inline void ParseResumeLocationProto::set_filename(::std::string&& value) {
  set_has_filename();
  filename_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:zetasql.ParseResumeLocationProto.filename)
}
#endif
inline void ParseResumeLocationProto::set_filename(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_filename();
  filename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zetasql.ParseResumeLocationProto.filename)
}
inline void ParseResumeLocationProto::set_filename(const char* value, size_t size) {
  set_has_filename();
  filename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zetasql.ParseResumeLocationProto.filename)
}
inline ::std::string* ParseResumeLocationProto::mutable_filename() {
  set_has_filename();
  // @@protoc_insertion_point(field_mutable:zetasql.ParseResumeLocationProto.filename)
  return filename_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ParseResumeLocationProto::release_filename() {
  // @@protoc_insertion_point(field_release:zetasql.ParseResumeLocationProto.filename)
  if (!has_filename()) {
    return NULL;
  }
  clear_has_filename();
  return filename_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ParseResumeLocationProto::set_allocated_filename(::std::string* filename) {
  if (filename != NULL) {
    set_has_filename();
  } else {
    clear_has_filename();
  }
  filename_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), filename);
  // @@protoc_insertion_point(field_set_allocated:zetasql.ParseResumeLocationProto.filename)
}

// optional string input = 1;
inline bool ParseResumeLocationProto::has_input() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ParseResumeLocationProto::set_has_input() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ParseResumeLocationProto::clear_has_input() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ParseResumeLocationProto::clear_input() {
  input_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_input();
}
inline const ::std::string& ParseResumeLocationProto::input() const {
  // @@protoc_insertion_point(field_get:zetasql.ParseResumeLocationProto.input)
  return input_.GetNoArena();
}
inline void ParseResumeLocationProto::set_input(const ::std::string& value) {
  set_has_input();
  input_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zetasql.ParseResumeLocationProto.input)
}
#if LANG_CXX11
inline void ParseResumeLocationProto::set_input(::std::string&& value) {
  set_has_input();
  input_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:zetasql.ParseResumeLocationProto.input)
}
#endif
inline void ParseResumeLocationProto::set_input(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_input();
  input_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zetasql.ParseResumeLocationProto.input)
}
inline void ParseResumeLocationProto::set_input(const char* value, size_t size) {
  set_has_input();
  input_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zetasql.ParseResumeLocationProto.input)
}
inline ::std::string* ParseResumeLocationProto::mutable_input() {
  set_has_input();
  // @@protoc_insertion_point(field_mutable:zetasql.ParseResumeLocationProto.input)
  return input_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ParseResumeLocationProto::release_input() {
  // @@protoc_insertion_point(field_release:zetasql.ParseResumeLocationProto.input)
  if (!has_input()) {
    return NULL;
  }
  clear_has_input();
  return input_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ParseResumeLocationProto::set_allocated_input(::std::string* input) {
  if (input != NULL) {
    set_has_input();
  } else {
    clear_has_input();
  }
  input_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), input);
  // @@protoc_insertion_point(field_set_allocated:zetasql.ParseResumeLocationProto.input)
}

// optional int32 byte_position = 2;
inline bool ParseResumeLocationProto::has_byte_position() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ParseResumeLocationProto::set_has_byte_position() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ParseResumeLocationProto::clear_has_byte_position() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ParseResumeLocationProto::clear_byte_position() {
  byte_position_ = 0;
  clear_has_byte_position();
}
inline ::google::protobuf::int32 ParseResumeLocationProto::byte_position() const {
  // @@protoc_insertion_point(field_get:zetasql.ParseResumeLocationProto.byte_position)
  return byte_position_;
}
inline void ParseResumeLocationProto::set_byte_position(::google::protobuf::int32 value) {
  set_has_byte_position();
  byte_position_ = value;
  // @@protoc_insertion_point(field_set:zetasql.ParseResumeLocationProto.byte_position)
}

// optional bool allow_resume = 3;
inline bool ParseResumeLocationProto::has_allow_resume() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ParseResumeLocationProto::set_has_allow_resume() {
  _has_bits_[0] |= 0x00000008u;
}
inline void ParseResumeLocationProto::clear_has_allow_resume() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void ParseResumeLocationProto::clear_allow_resume() {
  allow_resume_ = false;
  clear_has_allow_resume();
}
inline bool ParseResumeLocationProto::allow_resume() const {
  // @@protoc_insertion_point(field_get:zetasql.ParseResumeLocationProto.allow_resume)
  return allow_resume_;
}
inline void ParseResumeLocationProto::set_allow_resume(bool value) {
  set_has_allow_resume();
  allow_resume_ = value;
  // @@protoc_insertion_point(field_set:zetasql.ParseResumeLocationProto.allow_resume)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace zetasql

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_zetasql_2fpublic_2fparse_5fresume_5flocation_2eproto
