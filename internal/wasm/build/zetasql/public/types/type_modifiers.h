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

#ifndef ZETASQL_PUBLIC_TYPES_TYPE_MODIFIERS_H_
#define ZETASQL_PUBLIC_TYPES_TYPE_MODIFIERS_H_

#include <string>
#include <utility>

#include "zetasql/public/type_modifiers.pb.h"
#include "zetasql/public/types/collation.h"
#include "zetasql/public/types/type_parameters.h"
namespace zetasql {

// This class wraps all modifiers following the type name in a type string, e.g.
// type parameters, collation.
class TypeModifiers {
 public:
  // Constructs TypeModifiers with input type modifier objects.
  static TypeModifiers MakeTypeModifiers(TypeParameters type_parameters,
                                         Collation collation);

  // Constructs empty TypeModifiers where each modifier class is empty. Default
  // constructor must be public to be used in the ResolvedAST.
  TypeModifiers() = default;

  const TypeParameters& type_parameters() const { return type_parameters_; }

  const Collation& collation() const { return collation_; }

  bool Equals(const TypeModifiers& that) const;

  absl::Status Serialize(TypeModifiersProto* proto) const;
  static absl::StatusOr<TypeModifiers> Deserialize(
      const TypeModifiersProto& proto);

  std::string DebugString(absl::string_view indent = "") const;

 private:
  TypeModifiers(TypeParameters type_parameters, Collation collation)
      : type_parameters_(std::move(type_parameters)),
        collation_(std::move(collation)) {}

  TypeParameters type_parameters_;
  Collation collation_;
};

}  // namespace zetasql

#endif  // ZETASQL_PUBLIC_TYPES_TYPE_MODIFIERS_H_
