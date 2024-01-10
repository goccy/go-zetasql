//
// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef ZETASQL_PUBLIC_TYPES_TYPE_DESERIALIZER_H_
#define ZETASQL_PUBLIC_TYPES_TYPE_DESERIALIZER_H_

#include "zetasql/base/logging.h"
#include "google/protobuf/descriptor.h"
#include "zetasql/public/type.pb.h"
#include "zetasql/public/types/extended_type.h"
#include "zetasql/public/types/type.h"
#include "zetasql/public/types/type_factory.h"
#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "absl/types/span.h"

namespace zetasql {

class TypeDeserializer;

// The interface for deserialization of ZetaSQL extended types. Is used by
// TypeDeserializer to deserialize an ExtendedType instance corresponding to
// a TypeProto obtained as a result of a call to this extended type's
// SerializeToProtoAndFileDescriptors.
//
// ExtendedTypeDeserializer must ensure that ExtendedType instances, pointers to
// which it returns must outlive all references to these instances that can be
// maintained by components (e.g. Catalog implementations) that use
// TypeDeserializer or ExtendedTypeDeserializer directly. The easiest way to
// achieve it is to internalize deserialized types in TypeFactory provided
// through TypeDeserializer.
//
// See ExtendedType for more detail on serialization of extended types.
class ExtendedTypeDeserializer {
 public:
#ifndef SWIG
  ExtendedTypeDeserializer(const ExtendedTypeDeserializer&) = delete;
  ExtendedTypeDeserializer& operator=(const ExtendedTypeDeserializer&) = delete;
#endif  // SWIG

  // Deserializes a TypeProto containing serialized representation of extended
  // type. Returned type instance should be either static or owned by
  // TypeFactory provided through TypeDeserializer.
  virtual absl::StatusOr<const ExtendedType*> Deserialize(
      const TypeProto& type_proto,
      const TypeDeserializer& type_deserializer) const = 0;

  virtual ~ExtendedTypeDeserializer() = default;

 protected:
  ExtendedTypeDeserializer() = default;
};

// TypeDeserializer is responsible for deserialization of ZetaSQL built-in
// and extended types. Types will be deserialized using the TypeFactory, list of
// DescriptorPools and optional ExtendedTypeDeserializer stored in an instance
// of this class. The DescriptorPools and TypeFactory must both outlive the
// references to deserialized types.
class TypeDeserializer {
 public:
  constexpr TypeDeserializer(
      TypeFactory* type_factory,
      absl::Span<const google::protobuf::DescriptorPool* const> descriptor_pools,
      const ExtendedTypeDeserializer* extended_type_deserializer = nullptr)
      : type_factory_(type_factory),
        descriptor_pools_(descriptor_pools),
        extended_type_deserializer_(extended_type_deserializer) {
    // In release code we still check type_factory using ZETASQL_RET_CHECK in
    // Deserialize.
    ZETASQL_DCHECK(type_factory);
  }
  constexpr explicit TypeDeserializer(
      TypeFactory* type_factory,
      const ExtendedTypeDeserializer* extended_type_deserializer = nullptr)
      : TypeDeserializer(type_factory, {}, extended_type_deserializer) {}

  // Explicitly copiable.
  TypeDeserializer(const TypeDeserializer&) = default;
  TypeDeserializer& operator=(const TypeDeserializer&) = default;

  // Deserializes the TypeProto produced by
  // Type::SerializeToProtoAndFileDescriptors. Types returned by this function
  // should be either static or owned by TypeFactory.
  absl::StatusOr<const Type*> Deserialize(const TypeProto& type_proto) const;

  // Deserializes FileDescriptorSets saved to TypeProto by
  // Type::SerializeToSelfContainedProto. This function must be called to
  // populate DescriptorPools provided to TypeDeserializer before a call to
  // TypeDeserializer::Deserialize for each TypeProto serialized using
  // Type::SerializeToSelfContainedProto.
  static absl::Status DeserializeDescriptorPoolsFromSelfContainedProto(
      const TypeProto& type_proto,
      absl::Span<google::protobuf::DescriptorPool* const> pools);

  // Returns type factory used by this deserialize to store deserialized types.
  TypeFactory* type_factory() const { return type_factory_; }

  // List of DescriptoPools used to serialize incoming types.
  absl::Span<const google::protobuf::DescriptorPool* const> descriptor_pools() const {
    return descriptor_pools_;
  }

  // Optional deserializer of extended types.
  const ExtendedTypeDeserializer* extended_type_deserializer() const {
    return extended_type_deserializer_;
  }

 private:
  TypeFactory* type_factory_;
  absl::Span<const google::protobuf::DescriptorPool* const> descriptor_pools_;
  const ExtendedTypeDeserializer* extended_type_deserializer_ = nullptr;
};

}  // namespace zetasql

#endif  // ZETASQL_PUBLIC_TYPES_TYPE_DESERIALIZER_H_
