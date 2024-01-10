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

#ifndef ZETASQL_PUBLIC_TYPES_ENUM_TYPE_H_
#define ZETASQL_PUBLIC_TYPES_ENUM_TYPE_H_

#include <cstdint>
#include <string>

#include "zetasql/base/logging.h"
#include "google/protobuf/descriptor.h"
#include "zetasql/public/options.pb.h"
#include "zetasql/public/type.pb.h"
#include "zetasql/public/types/type.h"
#include "zetasql/public/types/type_parameters.h"
#include "absl/base/attributes.h"
#include "absl/hash/hash.h"
#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "absl/types/span.h"

namespace zetasql {
class LanguageOptions;
class TypeFactory;
class ValueContent;
class ValueProto;
}  // namespace zetasql

namespace zetasql {

namespace internal {
struct CatalogName;
}

// An enum type.
// Each EnumType object defines a set of legal numeric (int32_t) values.  Each
// value has one (or more) string names.  The first name is treated as the
// canonical name for that numeric value, and additional names are treated
// as aliases.
//
// The type may contain a catalog path if it was explicitly provided during
// construction, so it can be reproduced by SQLBuilder while rebuilding SQL and
// error messages and SQLBuilder. Two types with the same descriptors but
// different catalog names are not equal, but equivalent.
//
// We currently support creating a ZetaSQL EnumType from a protocol
// buffer EnumDescriptor.  This is likely to be extended to support EnumTypes
// without an EnumDescriptor by explicitly providing a list of enum values
// instead.
class EnumType : public Type {
 public:
#ifndef SWIG
  EnumType(const EnumType&) = delete;
  EnumType& operator=(const EnumType&) = delete;
#endif  // SWIG

  const EnumType* AsEnum() const override { return this; }

  const google::protobuf::EnumDescriptor* enum_descriptor() const;

  // Helper function to determine equality or equivalence for enum types.
  static bool EqualsImpl(const EnumType* type1, const EnumType* type2,
                         bool equivalent);

  // TODO: The current implementation of TypeName/ShortTypeName
  // should be re-examined for Proto and Enum Types.  Currently, the
  // TypeName is the back-ticked descriptor full_name, while the ShortTypeName
  // is just the descriptor full_name (without back-ticks).  The back-ticks
  // are not necessary for TypeName() to be reparseable, so should be removed.
  std::string TypeName(ProductMode mode_unused) const override;
  // EnumType does not support type parameters, which is why TypeName(mode) is
  // used.
  absl::StatusOr<std::string> TypeNameWithParameters(
      const TypeParameters& type_params, ProductMode mode) const override {
    ZETASQL_DCHECK(type_params.IsEmpty());
    return TypeName(mode);
  }
  std::string ShortTypeName(
      ProductMode mode_unused = ProductMode::PRODUCT_INTERNAL) const override;
  std::string TypeName() const;  // Enum-specific version does not need mode.

  // Nested catalog names, that were passed to the constructor.
  absl::Span<const std::string> CatalogNamePath() const;

  bool UsingFeatureV12CivilTimeType() const override { return false; }

  // Finds the enum name given a corresponding enum number.  Returns true
  // upon success, and false if the number is not found.  For enum numbers
  // that are not unique, this function will return the canonical name
  // for that number.
  ABSL_MUST_USE_RESULT bool FindName(int number,
                                     const std::string** name) const;

  // Find the enum number given a corresponding name.  Returns true
  // upon success, and false if the name is not found.
  ABSL_MUST_USE_RESULT bool FindNumber(const std::string& name,
                                       int* number) const;

  bool IsSupportedType(const LanguageOptions& language_options) const override;

 protected:
  int64_t GetEstimatedOwnedMemoryBytesSize() const override {
    return sizeof(*this);
  }

 private:
  // Does not take ownership of <factory> or <enum_descr>.  The
  // <enum_descriptor> must outlive the type.  The <enum_descr> must not be
  // NULL.
  EnumType(const TypeFactory* factory, const google::protobuf::EnumDescriptor* enum_descr,
           const internal::CatalogName* catalog_name);
  ~EnumType() override;

  bool SupportsGroupingImpl(const LanguageOptions& language_options,
                            const Type** no_grouping_type) const override {
    if (no_grouping_type != nullptr) {
      *no_grouping_type = nullptr;
    }
    return true;
  }

  bool SupportsPartitioningImpl(
      const LanguageOptions& language_options,
      const Type** no_partitioning_type) const override {
    if (no_partitioning_type != nullptr) {
      *no_partitioning_type = nullptr;
    }
    return true;
  }

  absl::Status SerializeToProtoAndDistinctFileDescriptorsImpl(
      const BuildFileDescriptorSetMapOptions& options, TypeProto* type_proto,
      FileDescriptorSetMap* file_descriptor_set_map) const override;

  bool EqualsForSameKind(const Type* that, bool equivalent) const override;

  void DebugStringImpl(bool details, TypeOrStringVector* stack,
                       std::string* debug_string) const override;

  absl::HashState HashTypeParameter(absl::HashState state) const override;
  absl::HashState HashValueContent(const ValueContent& value,
                                   absl::HashState state) const override;
  bool ValueContentEquals(
      const ValueContent& x, const ValueContent& y,
      const ValueEqualityCheckOptions& options) const override;
  bool ValueContentLess(const ValueContent& x, const ValueContent& y,
                        const Type* other_type) const override;
  std::string FormatValueContent(
      const ValueContent& value,
      const FormatValueContentOptions& options) const override;
  absl::Status SerializeValueContent(const ValueContent& value,
                                     ValueProto* value_proto) const override;
  absl::Status DeserializeValueContent(const ValueProto& value_proto,
                                       ValueContent* value) const override;

  const google::protobuf::EnumDescriptor* enum_descriptor_;  // Not owned.
  const internal::CatalogName* catalog_name_;      // Optional.

  friend class TypeFactory;
};

}  // namespace zetasql

#endif  // ZETASQL_PUBLIC_TYPES_ENUM_TYPE_H_
