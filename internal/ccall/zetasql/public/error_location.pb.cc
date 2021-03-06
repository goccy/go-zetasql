// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: zetasql/public/error_location.proto

#include "zetasql/public/error_location.pb.h"

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

namespace protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_ErrorLocation;
}  // namespace protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto
namespace zetasql {
class ErrorLocationDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ErrorLocation>
      _instance;
} _ErrorLocation_default_instance_;
class ErrorSourceDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ErrorSource>
      _instance;
} _ErrorSource_default_instance_;
}  // namespace zetasql
namespace protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto {
static void InitDefaultsErrorLocation() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::zetasql::_ErrorLocation_default_instance_;
    new (ptr) ::zetasql::ErrorLocation();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  {
    void* ptr = &::zetasql::_ErrorSource_default_instance_;
    new (ptr) ::zetasql::ErrorSource();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::zetasql::ErrorLocation::InitAsDefaultInstance();
  ::zetasql::ErrorSource::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_ErrorLocation =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsErrorLocation}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_ErrorLocation.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zetasql::ErrorLocation, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zetasql::ErrorLocation, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zetasql::ErrorLocation, line_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zetasql::ErrorLocation, column_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zetasql::ErrorLocation, filename_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zetasql::ErrorLocation, error_source_),
  1,
  2,
  0,
  ~0u,
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zetasql::ErrorSource, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zetasql::ErrorSource, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zetasql::ErrorSource, error_message_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zetasql::ErrorSource, error_message_caret_string_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::zetasql::ErrorSource, error_location_),
  0,
  1,
  2,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, sizeof(::zetasql::ErrorLocation)},
  { 13, 21, sizeof(::zetasql::ErrorSource)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::zetasql::_ErrorLocation_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::zetasql::_ErrorSource_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "zetasql/public/error_location.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n#zetasql/public/error_location.proto\022\007z"
      "etasql\"q\n\rErrorLocation\022\017\n\004line\030\001 \001(\005:\0011"
      "\022\021\n\006column\030\002 \001(\005:\0011\022\020\n\010filename\030\003 \001(\t\022*\n"
      "\014error_source\030\004 \003(\0132\024.zetasql.ErrorSourc"
      "e\"x\n\013ErrorSource\022\025\n\rerror_message\030\001 \001(\t\022"
      "\"\n\032error_message_caret_string\030\002 \001(\t\022.\n\016e"
      "rror_location\030\003 \001(\0132\026.zetasql.ErrorLocat"
      "ionB\024\n\022com.google.zetasql"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 305);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "zetasql/public/error_location.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto
namespace zetasql {

// ===================================================================

void ErrorLocation::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ErrorLocation::kLineFieldNumber;
const int ErrorLocation::kColumnFieldNumber;
const int ErrorLocation::kFilenameFieldNumber;
const int ErrorLocation::kErrorSourceFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ErrorLocation::ErrorLocation()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto::scc_info_ErrorLocation.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:zetasql.ErrorLocation)
}
ErrorLocation::ErrorLocation(const ErrorLocation& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      error_source_(from.error_source_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  filename_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_filename()) {
    filename_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.filename_);
  }
  ::memcpy(&line_, &from.line_,
    static_cast<size_t>(reinterpret_cast<char*>(&column_) -
    reinterpret_cast<char*>(&line_)) + sizeof(column_));
  // @@protoc_insertion_point(copy_constructor:zetasql.ErrorLocation)
}

void ErrorLocation::SharedCtor() {
  filename_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  line_ = 1;
  column_ = 1;
}

ErrorLocation::~ErrorLocation() {
  // @@protoc_insertion_point(destructor:zetasql.ErrorLocation)
  SharedDtor();
}

void ErrorLocation::SharedDtor() {
  filename_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void ErrorLocation::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* ErrorLocation::descriptor() {
  ::protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ErrorLocation& ErrorLocation::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto::scc_info_ErrorLocation.base);
  return *internal_default_instance();
}


void ErrorLocation::Clear() {
// @@protoc_insertion_point(message_clear_start:zetasql.ErrorLocation)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  error_source_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 7u) {
    if (cached_has_bits & 0x00000001u) {
      filename_.ClearNonDefaultToEmptyNoArena();
    }
    line_ = 1;
    column_ = 1;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool ErrorLocation::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:zetasql.ErrorLocation)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 line = 1 [default = 1];
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_line();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &line_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 column = 2 [default = 1];
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          set_has_column();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &column_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string filename = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_filename()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->filename().data(), static_cast<int>(this->filename().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "zetasql.ErrorLocation.filename");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .zetasql.ErrorSource error_source = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_error_source()));
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
  // @@protoc_insertion_point(parse_success:zetasql.ErrorLocation)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:zetasql.ErrorLocation)
  return false;
#undef DO_
}

void ErrorLocation::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:zetasql.ErrorLocation)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 line = 1 [default = 1];
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->line(), output);
  }

  // optional int32 column = 2 [default = 1];
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->column(), output);
  }

  // optional string filename = 3;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->filename().data(), static_cast<int>(this->filename().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "zetasql.ErrorLocation.filename");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->filename(), output);
  }

  // repeated .zetasql.ErrorSource error_source = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->error_source_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4,
      this->error_source(static_cast<int>(i)),
      output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:zetasql.ErrorLocation)
}

::google::protobuf::uint8* ErrorLocation::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:zetasql.ErrorLocation)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 line = 1 [default = 1];
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->line(), target);
  }

  // optional int32 column = 2 [default = 1];
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->column(), target);
  }

  // optional string filename = 3;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->filename().data(), static_cast<int>(this->filename().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "zetasql.ErrorLocation.filename");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->filename(), target);
  }

  // repeated .zetasql.ErrorSource error_source = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->error_source_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        4, this->error_source(static_cast<int>(i)), deterministic, target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:zetasql.ErrorLocation)
  return target;
}

size_t ErrorLocation::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:zetasql.ErrorLocation)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // repeated .zetasql.ErrorSource error_source = 4;
  {
    unsigned int count = static_cast<unsigned int>(this->error_source_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->error_source(static_cast<int>(i)));
    }
  }

  if (_has_bits_[0 / 32] & 7u) {
    // optional string filename = 3;
    if (has_filename()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->filename());
    }

    // optional int32 line = 1 [default = 1];
    if (has_line()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->line());
    }

    // optional int32 column = 2 [default = 1];
    if (has_column()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->column());
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ErrorLocation::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:zetasql.ErrorLocation)
  GOOGLE_DCHECK_NE(&from, this);
  const ErrorLocation* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ErrorLocation>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:zetasql.ErrorLocation)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:zetasql.ErrorLocation)
    MergeFrom(*source);
  }
}

void ErrorLocation::MergeFrom(const ErrorLocation& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:zetasql.ErrorLocation)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  error_source_.MergeFrom(from.error_source_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 7u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_filename();
      filename_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.filename_);
    }
    if (cached_has_bits & 0x00000002u) {
      line_ = from.line_;
    }
    if (cached_has_bits & 0x00000004u) {
      column_ = from.column_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void ErrorLocation::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:zetasql.ErrorLocation)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ErrorLocation::CopyFrom(const ErrorLocation& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:zetasql.ErrorLocation)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ErrorLocation::IsInitialized() const {
  return true;
}

void ErrorLocation::Swap(ErrorLocation* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ErrorLocation::InternalSwap(ErrorLocation* other) {
  using std::swap;
  CastToBase(&error_source_)->InternalSwap(CastToBase(&other->error_source_));
  filename_.Swap(&other->filename_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(line_, other->line_);
  swap(column_, other->column_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata ErrorLocation::GetMetadata() const {
  protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void ErrorSource::InitAsDefaultInstance() {
  ::zetasql::_ErrorSource_default_instance_._instance.get_mutable()->error_location_ = const_cast< ::zetasql::ErrorLocation*>(
      ::zetasql::ErrorLocation::internal_default_instance());
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ErrorSource::kErrorMessageFieldNumber;
const int ErrorSource::kErrorMessageCaretStringFieldNumber;
const int ErrorSource::kErrorLocationFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ErrorSource::ErrorSource()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto::scc_info_ErrorLocation.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:zetasql.ErrorSource)
}
ErrorSource::ErrorSource(const ErrorSource& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  error_message_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_error_message()) {
    error_message_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.error_message_);
  }
  error_message_caret_string_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_error_message_caret_string()) {
    error_message_caret_string_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.error_message_caret_string_);
  }
  if (from.has_error_location()) {
    error_location_ = new ::zetasql::ErrorLocation(*from.error_location_);
  } else {
    error_location_ = NULL;
  }
  // @@protoc_insertion_point(copy_constructor:zetasql.ErrorSource)
}

void ErrorSource::SharedCtor() {
  error_message_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  error_message_caret_string_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  error_location_ = NULL;
}

ErrorSource::~ErrorSource() {
  // @@protoc_insertion_point(destructor:zetasql.ErrorSource)
  SharedDtor();
}

void ErrorSource::SharedDtor() {
  error_message_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  error_message_caret_string_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete error_location_;
}

void ErrorSource::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* ErrorSource::descriptor() {
  ::protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ErrorSource& ErrorSource::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto::scc_info_ErrorLocation.base);
  return *internal_default_instance();
}


void ErrorSource::Clear() {
// @@protoc_insertion_point(message_clear_start:zetasql.ErrorSource)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 7u) {
    if (cached_has_bits & 0x00000001u) {
      error_message_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      error_message_caret_string_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000004u) {
      GOOGLE_DCHECK(error_location_ != NULL);
      error_location_->Clear();
    }
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool ErrorSource::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:zetasql.ErrorSource)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string error_message = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_error_message()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->error_message().data(), static_cast<int>(this->error_message().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "zetasql.ErrorSource.error_message");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string error_message_caret_string = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_error_message_caret_string()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->error_message_caret_string().data(), static_cast<int>(this->error_message_caret_string().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "zetasql.ErrorSource.error_message_caret_string");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .zetasql.ErrorLocation error_location = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_error_location()));
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
  // @@protoc_insertion_point(parse_success:zetasql.ErrorSource)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:zetasql.ErrorSource)
  return false;
#undef DO_
}

void ErrorSource::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:zetasql.ErrorSource)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string error_message = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->error_message().data(), static_cast<int>(this->error_message().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "zetasql.ErrorSource.error_message");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->error_message(), output);
  }

  // optional string error_message_caret_string = 2;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->error_message_caret_string().data(), static_cast<int>(this->error_message_caret_string().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "zetasql.ErrorSource.error_message_caret_string");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->error_message_caret_string(), output);
  }

  // optional .zetasql.ErrorLocation error_location = 3;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->_internal_error_location(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:zetasql.ErrorSource)
}

::google::protobuf::uint8* ErrorSource::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:zetasql.ErrorSource)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string error_message = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->error_message().data(), static_cast<int>(this->error_message().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "zetasql.ErrorSource.error_message");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->error_message(), target);
  }

  // optional string error_message_caret_string = 2;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->error_message_caret_string().data(), static_cast<int>(this->error_message_caret_string().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "zetasql.ErrorSource.error_message_caret_string");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->error_message_caret_string(), target);
  }

  // optional .zetasql.ErrorLocation error_location = 3;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        3, this->_internal_error_location(), deterministic, target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:zetasql.ErrorSource)
  return target;
}

size_t ErrorSource::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:zetasql.ErrorSource)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (_has_bits_[0 / 32] & 7u) {
    // optional string error_message = 1;
    if (has_error_message()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->error_message());
    }

    // optional string error_message_caret_string = 2;
    if (has_error_message_caret_string()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->error_message_caret_string());
    }

    // optional .zetasql.ErrorLocation error_location = 3;
    if (has_error_location()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          *error_location_);
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ErrorSource::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:zetasql.ErrorSource)
  GOOGLE_DCHECK_NE(&from, this);
  const ErrorSource* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ErrorSource>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:zetasql.ErrorSource)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:zetasql.ErrorSource)
    MergeFrom(*source);
  }
}

void ErrorSource::MergeFrom(const ErrorSource& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:zetasql.ErrorSource)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 7u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_error_message();
      error_message_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.error_message_);
    }
    if (cached_has_bits & 0x00000002u) {
      set_has_error_message_caret_string();
      error_message_caret_string_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.error_message_caret_string_);
    }
    if (cached_has_bits & 0x00000004u) {
      mutable_error_location()->::zetasql::ErrorLocation::MergeFrom(from.error_location());
    }
  }
}

void ErrorSource::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:zetasql.ErrorSource)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ErrorSource::CopyFrom(const ErrorSource& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:zetasql.ErrorSource)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ErrorSource::IsInitialized() const {
  return true;
}

void ErrorSource::Swap(ErrorSource* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ErrorSource::InternalSwap(ErrorSource* other) {
  using std::swap;
  error_message_.Swap(&other->error_message_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  error_message_caret_string_.Swap(&other->error_message_caret_string_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(error_location_, other->error_location_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata ErrorSource::GetMetadata() const {
  protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_zetasql_2fpublic_2ferror_5flocation_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace zetasql
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::zetasql::ErrorLocation* Arena::CreateMaybeMessage< ::zetasql::ErrorLocation >(Arena* arena) {
  return Arena::CreateInternal< ::zetasql::ErrorLocation >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::zetasql::ErrorSource* Arena::CreateMaybeMessage< ::zetasql::ErrorSource >(Arena* arena) {
  return Arena::CreateInternal< ::zetasql::ErrorSource >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
