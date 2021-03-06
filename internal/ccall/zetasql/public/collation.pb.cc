// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: zetasql/public/collation.proto

#include "zetasql/public/collation.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace protobuf_zetasql_2fpublic_2fcollation_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_zetasql_2fpublic_2fcollation_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_CollationProto;
}  // namespace protobuf_zetasql_2fpublic_2fcollation_2eproto
namespace zetasql {
class CollationProtoDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<CollationProto>
      _instance;
} _CollationProto_default_instance_;
}  // namespace zetasql
namespace protobuf_zetasql_2fpublic_2fcollation_2eproto {
static void InitDefaultsCollationProto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::zetasql::_CollationProto_default_instance_;
    new (ptr) ::zetasql::CollationProto();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::zetasql::CollationProto::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_CollationProto =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsCollationProto}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_CollationProto.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zetasql::CollationProto, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zetasql::CollationProto, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zetasql::CollationProto, collation_name_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zetasql::CollationProto, child_list_),
  0,
  ~0u,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 7, sizeof(::zetasql::CollationProto)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::zetasql::_CollationProto_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "zetasql/public/collation.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\036zetasql/public/collation.proto\022\007zetasq"
      "l\"U\n\016CollationProto\022\026\n\016collation_name\030\001 "
      "\001(\t\022+\n\nchild_list\030\002 \003(\0132\027.zetasql.Collat"
      "ionProtoB\037\n\022com.google.zetasqlB\tCollatio"
      "n"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 161);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "zetasql/public/collation.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_zetasql_2fpublic_2fcollation_2eproto
namespace zetasql {

// ===================================================================

void CollationProto::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int CollationProto::kCollationNameFieldNumber;
const int CollationProto::kChildListFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

CollationProto::CollationProto()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_zetasql_2fpublic_2fcollation_2eproto::scc_info_CollationProto.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:zetasql.CollationProto)
}
CollationProto::CollationProto(const CollationProto& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      child_list_(from.child_list_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  collation_name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_collation_name()) {
    collation_name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.collation_name_);
  }
  // @@protoc_insertion_point(copy_constructor:zetasql.CollationProto)
}

void CollationProto::SharedCtor() {
  collation_name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

CollationProto::~CollationProto() {
  // @@protoc_insertion_point(destructor:zetasql.CollationProto)
  SharedDtor();
}

void CollationProto::SharedDtor() {
  collation_name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void CollationProto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* CollationProto::descriptor() {
  ::protobuf_zetasql_2fpublic_2fcollation_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_zetasql_2fpublic_2fcollation_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const CollationProto& CollationProto::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_zetasql_2fpublic_2fcollation_2eproto::scc_info_CollationProto.base);
  return *internal_default_instance();
}


void CollationProto::Clear() {
// @@protoc_insertion_point(message_clear_start:zetasql.CollationProto)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  child_list_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    collation_name_.ClearNonDefaultToEmptyNoArena();
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool CollationProto::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:zetasql.CollationProto)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string collation_name = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_collation_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->collation_name().data(), static_cast<int>(this->collation_name().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "zetasql.CollationProto.collation_name");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .zetasql.CollationProto child_list = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_child_list()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:zetasql.CollationProto)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:zetasql.CollationProto)
  return false;
#undef DO_
}

void CollationProto::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:zetasql.CollationProto)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string collation_name = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->collation_name().data(), static_cast<int>(this->collation_name().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "zetasql.CollationProto.collation_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->collation_name(), output);
  }

  // repeated .zetasql.CollationProto child_list = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->child_list_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2,
      this->child_list(static_cast<int>(i)),
      output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:zetasql.CollationProto)
}

::google::protobuf::uint8* CollationProto::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:zetasql.CollationProto)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string collation_name = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->collation_name().data(), static_cast<int>(this->collation_name().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "zetasql.CollationProto.collation_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->collation_name(), target);
  }

  // repeated .zetasql.CollationProto child_list = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->child_list_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        2, this->child_list(static_cast<int>(i)), deterministic, target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:zetasql.CollationProto)
  return target;
}

size_t CollationProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:zetasql.CollationProto)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // repeated .zetasql.CollationProto child_list = 2;
  {
    unsigned int count = static_cast<unsigned int>(this->child_list_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->child_list(static_cast<int>(i)));
    }
  }

  // optional string collation_name = 1;
  if (has_collation_name()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->collation_name());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CollationProto::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:zetasql.CollationProto)
  GOOGLE_DCHECK_NE(&from, this);
  const CollationProto* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const CollationProto>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:zetasql.CollationProto)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:zetasql.CollationProto)
    MergeFrom(*source);
  }
}

void CollationProto::MergeFrom(const CollationProto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:zetasql.CollationProto)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  child_list_.MergeFrom(from.child_list_);
  if (from.has_collation_name()) {
    set_has_collation_name();
    collation_name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.collation_name_);
  }
}

void CollationProto::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:zetasql.CollationProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CollationProto::CopyFrom(const CollationProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:zetasql.CollationProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CollationProto::IsInitialized() const {
  return true;
}

void CollationProto::Swap(CollationProto* other) {
  if (other == this) return;
  InternalSwap(other);
}
void CollationProto::InternalSwap(CollationProto* other) {
  using std::swap;
  CastToBase(&child_list_)->InternalSwap(CastToBase(&other->child_list_));
  collation_name_.Swap(&other->collation_name_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata CollationProto::GetMetadata() const {
  protobuf_zetasql_2fpublic_2fcollation_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_zetasql_2fpublic_2fcollation_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace zetasql
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::zetasql::CollationProto* Arena::CreateMaybeMessage< ::zetasql::CollationProto >(Arena* arena) {
  return Arena::CreateInternal< ::zetasql::CollationProto >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
