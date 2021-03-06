// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: zetasql/public/functions/normalize_mode.proto

#include "zetasql/public/functions/normalize_mode.pb.h"

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

namespace zetasql {
namespace functions {
}  // namespace functions
}  // namespace zetasql
namespace protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto {
void InitDefaults() {
}

const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];
const ::google::protobuf::uint32 TableStruct::offsets[1] = {};
static const ::google::protobuf::internal::MigrationSchema* schemas = NULL;
static const ::google::protobuf::Message* const* file_default_instances = NULL;

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "zetasql/public/functions/normalize_mode.proto", schemas, file_default_instances, TableStruct::offsets,
      NULL, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n-zetasql/public/functions/normalize_mod"
      "e.proto\022\021zetasql.functions*5\n\rNormalizeM"
      "ode\022\007\n\003NFC\020\000\022\010\n\004NFKC\020\001\022\007\n\003NFD\020\002\022\010\n\004NFKD\020"
      "\003B4\n\034com.google.zetasql.functionsB\024ZetaS"
      "QLNormalizeMode"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 175);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "zetasql/public/functions/normalize_mode.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto
namespace zetasql {
namespace functions {
const ::google::protobuf::EnumDescriptor* NormalizeMode_descriptor() {
  protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_zetasql_2fpublic_2ffunctions_2fnormalize_5fmode_2eproto::file_level_enum_descriptors[0];
}
bool NormalizeMode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace functions
}  // namespace zetasql
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
