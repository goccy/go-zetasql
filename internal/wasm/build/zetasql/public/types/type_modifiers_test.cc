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

#include "zetasql/public/types/type_modifiers.h"

#include "zetasql/public/types/type_factory.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace zetasql {

TEST(TypeModifiersTest, Creation) {
  {
    // Test creating empty TypeModifiers.
    TypeModifiers type_modifiers;
    EXPECT_TRUE(type_modifiers.type_parameters().IsEmpty());
    EXPECT_TRUE(type_modifiers.collation().Empty());

    // Test serialization / deserialization.
    TypeModifiersProto proto;
    ZETASQL_ASSERT_OK(type_modifiers.Serialize(&proto));
    ZETASQL_ASSERT_OK_AND_ASSIGN(TypeModifiers deserialized_type_modifiers,
                         TypeModifiers::Deserialize(proto));
    ASSERT_TRUE(type_modifiers.Equals(deserialized_type_modifiers));

    EXPECT_EQ(type_modifiers.DebugString(),
              "type_parameters: null\ncollation: _");
  }
  {
    StringTypeParametersProto string_type_param_proto;
    string_type_param_proto.set_max_length(1000);
    ZETASQL_ASSERT_OK_AND_ASSIGN(
        TypeParameters type_param,
        TypeParameters::MakeStringTypeParameters(string_type_param_proto));
    Collation collation = Collation::MakeScalar("und:ci");

    TypeModifiers type_modifiers =
        TypeModifiers::MakeTypeModifiers(type_param, collation);
    EXPECT_TRUE(type_modifiers.type_parameters().Equals(type_param));
    EXPECT_TRUE(type_modifiers.collation().Equals(collation));

    // Test serialization / deserialization.
    TypeModifiersProto proto;
    ZETASQL_ASSERT_OK(type_modifiers.Serialize(&proto));
    ZETASQL_ASSERT_OK_AND_ASSIGN(TypeModifiers deserialized_type_modifiers,
                         TypeModifiers::Deserialize(proto));
    ASSERT_TRUE(type_modifiers.Equals(deserialized_type_modifiers));

    EXPECT_EQ(type_modifiers.DebugString(),
              "type_parameters: (max_length=1000)\ncollation: und:ci");
  }
  {
    // TypeModifiers does not require that underlying modifiers must have the
    // same nested structure.
    StringTypeParametersProto string_type_param_proto;
    string_type_param_proto.set_max_length(1000);
    ZETASQL_ASSERT_OK_AND_ASSIGN(
        TypeParameters type_param,
        TypeParameters::MakeStringTypeParameters(string_type_param_proto));

    TypeFactory type_factory;
    const ArrayType* array_of_string_type;
    ZETASQL_CHECK_OK(
        type_factory.MakeArrayType(types::StringType(), &array_of_string_type));
    std::unique_ptr<AnnotationMap> annotation_map =
        AnnotationMap::Create(array_of_string_type);
    annotation_map->AsArrayMap()->mutable_element()->SetAnnotation(
        static_cast<int>(AnnotationKind::kCollation),
        SimpleValue::String("und:ci"));
    annotation_map->Normalize();

    ZETASQL_ASSERT_OK_AND_ASSIGN(Collation collation,
                         Collation::MakeCollation(*annotation_map));

    TypeModifiers type_modifiers =
        TypeModifiers::MakeTypeModifiers(type_param, collation);
    EXPECT_TRUE(type_modifiers.type_parameters().Equals(type_param));
    EXPECT_TRUE(type_modifiers.collation().Equals(collation));

    // Test serialization / deserialization.
    TypeModifiersProto proto;
    ZETASQL_ASSERT_OK(type_modifiers.Serialize(&proto));
    ZETASQL_ASSERT_OK_AND_ASSIGN(TypeModifiers deserialized_type_modifiers,
                         TypeModifiers::Deserialize(proto));
    ASSERT_TRUE(type_modifiers.Equals(deserialized_type_modifiers));

    EXPECT_EQ(type_modifiers.DebugString(),
              "type_parameters: (max_length=1000)\ncollation: [und:ci]");
  }
}

}  // namespace zetasql
