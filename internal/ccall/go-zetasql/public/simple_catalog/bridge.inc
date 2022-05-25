#include "_cgo_export.h"

void GO_EXPORT(Type_Kind)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->kind();
}

void GO_EXPORT(Type_IsInt32)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsInt32();
}

void GO_EXPORT(Type_IsInt64)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsInt64();
}

void GO_EXPORT(Type_IsUint32)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsUint32();
}

void GO_EXPORT(Type_IsUint64)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsUint64();
}

void GO_EXPORT(Type_IsBool)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
}

void GO_EXPORT(Type_IsFloat)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsBool();
}

void GO_EXPORT(Type_IsDouble)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsDouble();
}

void GO_EXPORT(Type_IsString)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsString();
}

void GO_EXPORT(Type_IsBytes)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsBytes();
}

void GO_EXPORT(Type_IsDate)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsDate();
}

void GO_EXPORT(Type_IsTimestamp)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsTimestamp();
}

void GO_EXPORT(Type_IsTime)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsTime();
}

void GO_EXPORT(Type_IsDatetime)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsDatetime();
}

void GO_EXPORT(Type_IsInterval)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsInterval();
}

void GO_EXPORT(Type_IsNumericType)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsNumericType();
}

void GO_EXPORT(Type_IsBigNumericType)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsBigNumericType();
}

void GO_EXPORT(Type_IsJsonType)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsJsonType();
}

void GO_EXPORT(Type_IsFeatureV12CivilTimeType)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsFeatureV12CivilTimeType();
}

void GO_EXPORT(Type_UsingFeatureV12CivilTimeType)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->UsingFeatureV12CivilTimeType();
}

void GO_EXPORT(Type_IsCivilDateOrTimeType)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsCivilDateOrTimeType();
}

void GO_EXPORT(Type_IsGeography)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsGeography();
}

void GO_EXPORT(Type_IsJson)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsJson();
}

void GO_EXPORT(Type_IsEnum)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsEnum();
}

void GO_EXPORT(Type_IsArray)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsArray();
}

void GO_EXPORT(Type_IsStruct)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsStruct();
}

void GO_EXPORT(Type_IsProto)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsProto();
}

void GO_EXPORT(Type_IsStructOrProto)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsStructOrProto();
}

void GO_EXPORT(Type_IsFloatingPoint)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsFloatingPoint();
}

void GO_EXPORT(Type_IsNumerical)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsNumerical();
}

void GO_EXPORT(Type_IsInteger)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsInteger();
}

void GO_EXPORT(Type_IsInteger32)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsInteger32();
}

void GO_EXPORT(Type_IsInteger64)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsInteger64();
}

void GO_EXPORT(Type_IsSignedInteger)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsSignedInteger();
}

void GO_EXPORT(Type_IsUnsignedInteger)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsUnsignedInteger();
}

void GO_EXPORT(Type_IsSimpleType)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsSimpleType();
}

void GO_EXPORT(Type_IsExtendedType)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->IsExtendedType();
}

void GO_EXPORT(Type_SupportsGrouping)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  zetasql::LanguageOptions opt;
  *arg1 = type->SupportsGrouping(opt);
}

void GO_EXPORT(Type_SupportsPartitioning)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  zetasql::LanguageOptions opt;
  *arg1 = type->SupportsPartitioning(opt);
}

void GO_EXPORT(Type_SupportsOrdering)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  zetasql::LanguageOptions opt;
  *arg1 = type->SupportsOrdering(opt, nullptr); // TODO
}

void GO_EXPORT(Type_SupportsEquality)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  zetasql::LanguageOptions opt;
  *arg1 = type->SupportsEquality(opt);
}

void GO_EXPORT(Type_Equals)(void * arg0,void * arg1,int* arg2)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  zetasql::Type *target = (zetasql::Type *)arg1;
  *arg2 = type->Equals(target);
}

void GO_EXPORT(Type_Equivalent)(void * arg0,void * arg1,int* arg2)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  zetasql::Type *target = (zetasql::Type *)arg1;
  *arg2 = type->Equivalent(target);
}

void GO_EXPORT(Type_ShortTypeName)(void * arg0,int arg1,void ** arg2)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg2 = (void *)((new std::string(type->ShortTypeName((zetasql::ProductMode)arg1)))->c_str());
}

void GO_EXPORT(Type_TypeName)(void * arg0,int arg1,void ** arg2)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg2 = (void *)((new std::string(type->TypeName((zetasql::ProductMode)arg1)))->c_str());
}

void GO_EXPORT(Type_TypeNameWithParameters)(void * arg0,void * arg1,int arg2,void ** arg3,void ** arg4)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  zetasql::TypeParameters *params = (zetasql::TypeParameters *)arg1;
  absl::StatusOr<std::string> ret = type->TypeNameWithParameters(*params, (zetasql::ProductMode)arg2);
  if (ret.ok()) {
    *arg3 = (void *)((new std::string(ret.value()))->c_str());
    *arg4 = (void *)(new absl::Status(absl::OkStatus()));
  } else {
    *arg3 = nullptr;
    *arg4 = (void *)(new absl::Status(ret.status()));
  }
}

void GO_EXPORT(Type_DebugString)(void * arg0,int arg1,void ** arg2)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg2 = (void *)((new std::string(type->DebugString(arg1)))->c_str());
}

void GO_EXPORT(Type_HasAnyFields)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->HasAnyFields();
}

void GO_EXPORT(Type_NestingDepth)(void * arg0,int* arg1)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg1 = type->nesting_depth();
}

void GO_EXPORT(Type_ValidateAndResolveTypeParameters)(void * arg0,void * arg1,int arg2,int arg3,void ** arg4,void ** arg5)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  zetasql::TypeParameterValue **data = (zetasql::TypeParameterValue **)arg1;
  std::vector<zetasql::TypeParameterValue> params;
  for (int i = 0; i < arg2; i++) {
    params.push_back(*data[i]);
  }
  absl::StatusOr<zetasql::TypeParameters> ret = type->ValidateAndResolveTypeParameters(params, (zetasql::ProductMode)arg3);
  if (ret.ok()) {
    zetasql::TypeParameters v = ret.value();
    *arg4 = (void *)(new zetasql::TypeParameters(v));
    *arg5 = (void *)(new absl::Status(absl::OkStatus()));
  } else {
    *arg4 = nullptr;
    *arg5 = (void *)(new absl::Status(ret.status()));
  }
}

void GO_EXPORT(Type_ValidateResolvedTypeParameters)(void * arg0,void * arg1,int arg2,void ** arg3)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  zetasql::TypeParameters *params = (zetasql::TypeParameters *)arg1;
  absl::Status ret = type->ValidateResolvedTypeParameters(*params, (zetasql::ProductMode)arg2);
  *arg3 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(TypeFactory_MakeArrayType)(void * arg0,void * arg1,void ** arg2,void ** arg3)
{
  zetasql::TypeFactory *factory = (zetasql::TypeFactory *)arg0;
  const zetasql::ArrayType *out = nullptr;
  absl::Status ret = factory->MakeArrayType((const zetasql::Type *)arg1, &out);
  *arg2 = (void *)out;
  *arg3 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(TypeFactory_MakeStructType)(void * arg0,void * arg1,int arg2,void ** arg3,void ** arg4)
{
  zetasql::TypeFactory *factory = (zetasql::TypeFactory *)arg0;
  const zetasql::StructType::StructField **data = (const zetasql::StructType::StructField **)arg1;
  std::vector<zetasql::StructType::StructField> fields;
  for (int i = 0; i < arg2; i++) {
    fields.push_back(*data[i]);
  }
  const zetasql::StructType *out = nullptr;
  absl::Status ret = factory->MakeStructTypeFromVector(fields, &out);
  *arg3 = (void *)out;
  *arg4 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(Int32Type)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::Int32Type();
}

void GO_EXPORT(Int64Type)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::Int64Type();
}

void GO_EXPORT(Uint32Type)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::Uint32Type();
}

void GO_EXPORT(Uint64Type)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::Uint64Type();
}

void GO_EXPORT(BoolType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::BoolType();
}

void GO_EXPORT(FloatType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::FloatType();
}

void GO_EXPORT(DoubleType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::DoubleType();
}

void GO_EXPORT(StringType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::StringType();
}

void GO_EXPORT(BytesType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::BytesType();
}

void GO_EXPORT(DateType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::DateType();
}

void GO_EXPORT(TimestampType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::TimestampType();
}

void GO_EXPORT(TimeType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::TimeType();
}

void GO_EXPORT(DatetimeType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::DatetimeType();
}

void GO_EXPORT(IntervalType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::IntervalType();
}

void GO_EXPORT(GeographyType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::GeographyType();
}

void GO_EXPORT(NumericType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::NumericType();
}

void GO_EXPORT(BigNumericType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::BigNumericType();
}

void GO_EXPORT(JsonType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::JsonType();
}

void GO_EXPORT(EmptyStructType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::EmptyStructType();
}

void GO_EXPORT(Int32ArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::Int32ArrayType();
}

void GO_EXPORT(Int64ArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::Int64ArrayType();
}

void GO_EXPORT(Uint32ArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::Uint32ArrayType();
}

void GO_EXPORT(Uint64ArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::Uint64ArrayType();
}

void GO_EXPORT(BoolArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::BoolArrayType();
}

void GO_EXPORT(FloatArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::FloatArrayType();
}

void GO_EXPORT(DoubleArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::DoubleArrayType();
}

void GO_EXPORT(StringArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::StringArrayType();
}

void GO_EXPORT(BytesArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::BytesArrayType();
}

void GO_EXPORT(DateArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::DateArrayType();
}

void GO_EXPORT(TimestampArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::TimestampArrayType();
}

void GO_EXPORT(DatetimeArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::DatetimeArrayType();
}

void GO_EXPORT(TimeArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::TimeArrayType();
}

void GO_EXPORT(IntervalArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::IntervalArrayType();
}

void GO_EXPORT(GeographyArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::GeographyArrayType();
}

void GO_EXPORT(NumericArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::NumericArrayType();
}

void GO_EXPORT(BigNumericArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::BigNumericArrayType();
}

void GO_EXPORT(JsonArrayType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::JsonArrayType();
}

void GO_EXPORT(DatePartEnumType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::DatePartEnumType();
}

void GO_EXPORT(NormalizeModeEnumType)(void ** arg0)
{
  *arg0 = (void *)zetasql::types::NormalizeModeEnumType();
}

void GO_EXPORT(TypeFromSimpleTypeKind)(int arg0,void ** arg1)
{
  *arg1 = (void *)zetasql::types::TypeFromSimpleTypeKind((zetasql::TypeKind)arg0);
}

void GO_EXPORT(Value_type)(void * arg0,void ** arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = (void *)value->type();
}

void GO_EXPORT(Value_type_kind)(void * arg0,int* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->type_kind();
}

void GO_EXPORT(Value_physical_byte_size)(void * arg0,uint64_t* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->physical_byte_size();
}

void GO_EXPORT(Value_is_null)(void * arg0,int* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->is_null();
}

void GO_EXPORT(Value_is_empty_array)(void * arg0,int* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->is_empty_array();
}

void GO_EXPORT(Value_is_valid)(void * arg0,int* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->is_valid();
}

void GO_EXPORT(Value_has_content)(void * arg0,int* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->has_content();
}

void GO_EXPORT(Value_int32_value)(void * arg0,int* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->int32_value();
}

void GO_EXPORT(Value_int64_value)(void * arg0,int64_t* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->int64_value();
}

void GO_EXPORT(Value_uint32_value)(void * arg0,uint32_t* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->uint32_value();
}

void GO_EXPORT(Value_uint64_value)(void * arg0,uint64_t* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->uint64_value();
}

void GO_EXPORT(Value_bool_value)(void * arg0,int* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->bool_value();
}

void GO_EXPORT(Value_float_value)(void * arg0,float* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->float_value();
}

void GO_EXPORT(Value_double_value)(void * arg0,double* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->double_value();
}

void GO_EXPORT(Value_string_value)(void * arg0,void ** arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = (void *)((new std::string(value->string_value()))->c_str());
}

void GO_EXPORT(Value_bytes_value)(void * arg0,void ** arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = (void *)((new std::string(value->bytes_value()))->c_str());
}

void GO_EXPORT(Value_date_value)(void * arg0,int* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->date_value();
}

void GO_EXPORT(Value_enum_value)(void * arg0,int* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->enum_value();
}

void GO_EXPORT(Value_enum_name)(void * arg0,void ** arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = (void *)((new std::string(value->enum_name()))->c_str());
}

void GO_EXPORT(Value_ToUnixMicros)(void * arg0,int64_t* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->ToUnixMicros();
}

void GO_EXPORT(Value_ToUnixNanos)(void * arg0,int64_t* arg1,void ** arg2)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  absl::Status ret = value->ToUnixNanos(arg1);
  *arg2 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(Value_ToPacked64TimeMicros)(void * arg0,int64_t* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->ToPacked64TimeMicros();
}

void GO_EXPORT(Value_ToPacked64DatetimeMicros)(void * arg0,int64_t* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->ToPacked64DatetimeMicros();
}

void GO_EXPORT(Value_is_validated_json)(void * arg0,int* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->is_validated_json();
}

void GO_EXPORT(Value_is_unparsed_json)(void * arg0,int* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->is_unparsed_json();
}

void GO_EXPORT(Value_json_value_unparsed)(void * arg0,void ** arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = (void *)((new std::string(value->json_value_unparsed()))->c_str());
}

void GO_EXPORT(Value_json_string)(void * arg0,void ** arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = (void *)((new std::string(value->json_string()))->c_str());
}

void GO_EXPORT(Value_ToInt64)(void * arg0,int64_t* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->ToInt64();
}

void GO_EXPORT(Value_ToUint64)(void * arg0,uint64_t* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->ToUint64();
}

void GO_EXPORT(Value_ToDouble)(void * arg0,double* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->ToDouble();
}

void GO_EXPORT(Value_num_fields)(void * arg0,int* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->num_fields();
}

void GO_EXPORT(Value_field)(void * arg0,int arg1, void** arg2)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg2 = (void *)(new zetasql::Value(value->field(arg1)));
}

void GO_EXPORT(Value_FindFieldByName)(void * arg0,void * arg1,void ** arg2)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg2 = (void *)(new zetasql::Value(value->FindFieldByName((char *)arg1)));
}

void GO_EXPORT(Value_empty)(void * arg0,int* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->empty();
}

void GO_EXPORT(Value_num_elements)(void * arg0,int* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->num_elements();
}

void GO_EXPORT(Value_element)(void * arg0,int arg1,void ** arg2)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg2 = (void *)(new zetasql::Value(value->element(arg1)));
}

void GO_EXPORT(Value_Equals)(void * arg0,void * arg1,int* arg2)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg2 = value->Equals(*(zetasql::Value *)arg1);
}

void GO_EXPORT(Value_SqlEquals)(void * arg0,void * arg1,void ** arg2)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg2 = (void *)(new zetasql::Value(value->SqlEquals(*(zetasql::Value *)arg1)));
}

void GO_EXPORT(Value_LessThan)(void * arg0,void * arg1,int* arg2)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg2 = value->LessThan(*(zetasql::Value *)arg1);
}

void GO_EXPORT(Value_SqlLessThan)(void * arg0,void * arg1,void ** arg2)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg2 = (void *)(new zetasql::Value(value->SqlLessThan(*(zetasql::Value *)arg1)));
}

void GO_EXPORT(Value_HashCode)(void * arg0,uint64_t* arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = value->HashCode();
}

void GO_EXPORT(Value_ShortDebugString)(void * arg0,void ** arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = (void *)((new std::string(value->ShortDebugString()))->c_str());
}

void GO_EXPORT(Value_FullDebugString)(void * arg0,void ** arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = (void *)((new std::string(value->FullDebugString()))->c_str());
}

void GO_EXPORT(Value_DebugString)(void * arg0,void ** arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = (void *)((new std::string(value->DebugString()))->c_str());
}

void GO_EXPORT(Value_Format)(void * arg0,void ** arg1)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg1 = (void *)((new std::string(value->Format()))->c_str());
}

void GO_EXPORT(Value_GetSQL)(void * arg0,int arg1,void ** arg2)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg2 = (void *)((new std::string(value->GetSQL((zetasql::ProductMode)arg1)))->c_str());
}

void GO_EXPORT(Value_GetSQLLiteral)(void * arg0,int arg1,void ** arg2)
{
  zetasql::Value *value = (zetasql::Value *)arg0;
  *arg2 = (void *)((new std::string(value->GetSQLLiteral((zetasql::ProductMode)arg1)))->c_str());
}

void GO_EXPORT(Int64)(int64_t arg0,void ** arg1)
{
  *arg1 = (void *)(new zetasql::Value(zetasql::values::Int64(arg0)));
}

void GO_EXPORT(Column_Name)(void * arg0,void ** arg1)
{
  zetasql::Column *col = (zetasql::Column *)arg0;
  *arg1 = (void *)((new std::string(col->Name()))->c_str());
}

void GO_EXPORT(Column_FullName)(void * arg0,void ** arg1)
{
  zetasql::Column *col = (zetasql::Column *)arg0;
  *arg1 = (void *)((new std::string(col->FullName()))->c_str());
}

void GO_EXPORT(Column_Type)(void * arg0,void ** arg1)
{
  zetasql::Column *col = (zetasql::Column *)arg0;
  *arg1 = (void *)col->GetType();
}

void GO_EXPORT(Column_IsPseudoColumn)(void * arg0,int* arg1)
{
  zetasql::Column *col = (zetasql::Column *)arg0;
  *arg1 = col->IsPseudoColumn();
}

void GO_EXPORT(Column_IsWritableColumn)(void * arg0,int* arg1)
{
  zetasql::Column *col = (zetasql::Column *)arg0;
  *arg1 = col->IsWritableColumn();
}

void GO_EXPORT(SimpleColumn_new)(void * arg0,void * arg1,void * arg2,void ** arg3)
{
  zetasql::SimpleColumn *ret = new zetasql::SimpleColumn((char *)arg0, (char *)arg1, (const zetasql::Type *)arg2);
  *arg3 = (void *)(ret);
}

void GO_EXPORT(SimpleColumn_new_with_opt)(void * arg0,void * arg1,void * arg2,int arg3,int arg4,void ** arg5)
{
  zetasql::SimpleColumn *ret = new zetasql::SimpleColumn((char *)arg0, (char *)arg1, (const zetasql::Type *)arg2, (bool)arg3, (bool)arg4);
  *arg5 = (void *)ret;
}

void GO_EXPORT(SimpleColumn_AnnotatedType)(void * arg0,void ** arg1)
{
  zetasql::SimpleColumn *col = (zetasql::SimpleColumn *)arg0;
  zetasql::AnnotatedType *ret = (zetasql::AnnotatedType *)malloc(sizeof(zetasql::AnnotatedType));
  zetasql::AnnotatedType t = col->annotated_type();
  ret->type = t.type;
  ret->annotation_map = t.annotation_map;
  *arg1 = (void *)ret;
}

void GO_EXPORT(SimpleColumn_SetIsPseudoColumn)(void * arg0,int arg1)
{
  zetasql::SimpleColumn *col = (zetasql::SimpleColumn *)arg0;
  col->set_is_pseudo_column(arg1);
}

void GO_EXPORT(Table_Name)(void * arg0,void ** arg1)
{
  zetasql::Table *table = (zetasql::Table *)arg0;
  *arg1 = (void *)((new std::string(table->Name()))->c_str());
}

void GO_EXPORT(Table_FullName)(void * arg0,void ** arg1)
{
  zetasql::Table *table = (zetasql::Table *)arg0;
  *arg1 = (void *)((new std::string(table->FullName()))->c_str());
}

void GO_EXPORT(Table_NumColumns)(void * arg0,int* arg1)
{
  zetasql::Table *table = (zetasql::Table *)arg0;
  *arg1 = table->NumColumns();
}

void GO_EXPORT(Table_Column)(void * arg0,int arg1,void ** arg2)
{
  zetasql::Table *table = (zetasql::Table *)arg0;
  *arg2 = (void *)table->GetColumn(arg1);
}

void GO_EXPORT(Table_PrimaryKey_num)(void * arg0,int* arg1)
{
  zetasql::Table *table = (zetasql::Table *)arg0;
  std::optional<std::vector<int>> ret = table->PrimaryKey();
  if (ret) {
    *arg1 = ret.value().size();
  }
}

void GO_EXPORT(Table_PrimaryKey)(void * arg0,int arg1,int * arg2)
{
  zetasql::Table *table = (zetasql::Table *)arg0;
  std::optional<std::vector<int>> ret = table->PrimaryKey();
  if (ret) {
    *arg2 = ret.value()[arg1];
  }
}

void GO_EXPORT(Table_FindColumnByName)(void * arg0,void * arg1,void ** arg2)
{
  zetasql::Table *table = (zetasql::Table *)arg0;
  *arg2 = (void *)table->FindColumnByName((char *)arg1);
}

void GO_EXPORT(Table_IsValueTable)(void * arg0,int* arg1)
{
  zetasql::Table *table = (zetasql::Table *)arg0;
  *arg1 = table->IsValueTable();
}

void GO_EXPORT(Table_GetSerializationId)(void * arg0,int* arg1)
{
  zetasql::Table *table = (zetasql::Table *)arg0;
  *arg1 = table->GetSerializationId();
}

void GO_EXPORT(Table_CreateEvaluatorTableIterator)(void * arg0,void * arg1,int arg2,void ** arg3,void ** arg4)
{
  zetasql::Table *table = (zetasql::Table *)arg0;
  absl::Span<const int> column_idxs((int *)arg1, arg2);
  absl::StatusOr<std::unique_ptr<zetasql::EvaluatorTableIterator>> ret = table->CreateEvaluatorTableIterator(column_idxs);
  if (ret.ok()) {
    *(std::unique_ptr<zetasql::EvaluatorTableIterator> *)arg3 = std::move(ret.value());
    *arg4 = (void *)(new absl::Status(absl::OkStatus()));
  } else {
    *arg3 = nullptr;
    *arg4 = (void *)(new absl::Status(ret.status()));
  }
}

void GO_EXPORT(Table_GetAnonymizationInfo)(void * arg0,void ** arg1)
{
  zetasql::Table *table = (zetasql::Table *)arg0;
  std::optional<const zetasql::AnonymizationInfo> ret = table->GetAnonymizationInfo();
  if (ret) {
    *arg1 = (void *)(new zetasql::AnonymizationInfo(ret.value()));
  } else {
    *arg1 = nullptr;
  }
}

void GO_EXPORT(Table_SupportsAnonymization)(void * arg0,int* arg1)
{
  zetasql::Table *table = (zetasql::Table *)arg0;
  *arg1 = table->SupportsAnonymization();
}

void GO_EXPORT(Table_GetTableTypeName)(void * arg0,int arg1,void ** arg2)
{
  zetasql::Table *table = (zetasql::Table *)arg0;
  *arg2 = (void *)((new std::string(table->GetTableTypeName((zetasql::ProductMode)arg1)))->c_str());
}

void GO_EXPORT(SimpleTable_new)(void * arg0,void * arg1,int arg2,void ** arg3)
{
  std::vector<const zetasql::Column *> columns;
  zetasql::Column **data = (zetasql::Column **)arg1;
  for (int i = 0; i < arg2; i++) {
    columns.push_back(data[i]);
  }
  zetasql::SimpleTable *ret = new zetasql::SimpleTable((char *)arg0, columns);
  *arg3 = (void *)ret;
}

void GO_EXPORT(SimpleTable_set_is_value_table)(void * arg0,int arg1)
{
  zetasql::SimpleTable *table = (zetasql::SimpleTable *)arg0;
  table->set_is_value_table(arg1);
}

void GO_EXPORT(SimpleTable_AllowAnonymousColumnName)(void * arg0,int* arg1)
{
  zetasql::SimpleTable *table = (zetasql::SimpleTable *)arg0;
  *arg1 = table->AllowAnonymousColumnName();
}

void GO_EXPORT(SimpleTable_set_allow_anonymous_column_name)(void * arg0,int arg1,void ** arg2)
{
  zetasql::SimpleTable *table = (zetasql::SimpleTable *)arg0;
  *arg2 = (void *)(new absl::Status(table->set_allow_anonymous_column_name(arg1)));
}

void GO_EXPORT(SimpleTable_AllowDuplicateColumnNames)(void * arg0,int* arg1)
{
  zetasql::SimpleTable *table = (zetasql::SimpleTable *)arg0;
  *arg1 = table->AllowDuplicateColumnNames();
}

void GO_EXPORT(SimpleTable_set_allow_duplicate_column_names)(void * arg0,int arg1,void ** arg2)
{
  zetasql::SimpleTable *table = (zetasql::SimpleTable *)arg0;
  *arg2 = (void *)(new absl::Status(table->set_allow_duplicate_column_names(arg1)));
}

void GO_EXPORT(SimpleTable_AddColumn)(void * arg0,void * arg1,void ** arg2)
{
  zetasql::SimpleTable *table = (zetasql::SimpleTable *)arg0;
  *arg2 = (void *)(new absl::Status(table->AddColumn((zetasql::Column *)arg1, false)));
}

void GO_EXPORT(SimpleTable_SetPrimaryKey)(void * arg0,void * arg1,int arg2,void ** arg3)
{
  zetasql::SimpleTable *table = (zetasql::SimpleTable *)arg0;
  int *data = (int *)arg1;
  std::vector<int> primary_key;
  for (int i = 0; i < arg2; i++) {
    primary_key.push_back(data[i]);
  }
  *arg3 = (void *)(new absl::Status(table->SetPrimaryKey(primary_key)));
}

void GO_EXPORT(SimpleTable_set_full_name)(void * arg0,void * arg1,void ** arg2)
{
  zetasql::SimpleTable *table = (zetasql::SimpleTable *)arg0;
  *arg2 = (void *)(new absl::Status(table->set_full_name((char *)arg1)));
}

void GO_EXPORT(SimpleTable_SetAnonymizationInfo)(void * arg0,void * arg1,void ** arg2)
{
  zetasql::SimpleTable *table = (zetasql::SimpleTable *)arg0;
  *arg2 = (void *)(new absl::Status(table->SetAnonymizationInfo((char *)arg1)));
}

void GO_EXPORT(SimpleTable_ResetAnonymizationInfo)(void *arg0)
{
  zetasql::SimpleTable *table = (zetasql::SimpleTable *)arg0;
  table->ResetAnonymizationInfo();
}

void GO_EXPORT(Catalog_FullName)(void * arg0,void ** arg1)
{
  zetasql::Catalog *catalog = (zetasql::Catalog *)arg0;
  *arg1 = (void *)((new std::string(catalog->FullName()))->c_str());
}

void GO_EXPORT(Catalog_FindTable)(void * arg0,void * arg1,void **arg2,void ** arg3)
{
  zetasql::Catalog *catalog = (zetasql::Catalog *)arg0;
  GoSlice *slice = (GoSlice *)arg1;
  char **data = (char **)slice->data;
  std::vector<std::string> pathvec; 
  for (int i = 0; i < slice->len; i++) {
    pathvec.push_back(std::string(data[i]));
  }
  const absl::Span<const std::string> path(pathvec);
  const zetasql::Table *table = nullptr;
  absl::Status ret = catalog->FindTable(path, &table);
  *arg2 = (void *)table;
  *arg3 = new absl::Status(ret);
}

void GO_EXPORT(Catalog_FindType)(void * arg0,void * arg1,void **arg2,void ** arg3)
{
  zetasql::Catalog *catalog = (zetasql::Catalog *)arg0;
  GoSlice *slice = (GoSlice *)arg1;
  char **data = (char **)slice->data;
  std::vector<std::string> pathvec; 
  for (int i = 0; i < slice->len; i++) {
    pathvec.push_back(std::string(data[i]));
  }
  const absl::Span<const std::string> path(pathvec);
  const zetasql::Type *type = nullptr;
  absl::Status ret = catalog->FindType(path, &type);
  *arg2 = (void *)type;
  *arg3 = new absl::Status(ret);
}

void GO_EXPORT(Catalog_SuggestTable)(void * arg0,void * arg1,void ** arg2)
{
  zetasql::Catalog *catalog = (zetasql::Catalog *)arg0;
  GoSlice *slice = (GoSlice *)arg1;
  char **data = (char **)slice->data;
  std::vector<std::string> pathvec; 
  for (int i = 0; i < slice->len; i++) {
    pathvec.push_back(std::string(data[i]));
  }
  const absl::Span<const std::string> path(pathvec);
  *arg2 = (void *)((new std::string(catalog->SuggestTable(path)))->c_str());
}

void GO_EXPORT(EnumerableCatalog_Catalogs)(void * arg0,void **arg1,void ** arg2)
{
  zetasql::EnumerableCatalog *catalog = (zetasql::EnumerableCatalog *)arg0;
  absl::flat_hash_set<const zetasql::Catalog *> out;
  absl::Status ret = catalog->GetCatalogs(&out);
  absl::flat_hash_set<const zetasql::Catalog *>::iterator it;
  GoSlice *catalogs = (GoSlice *)malloc(sizeof(GoSlice));
  void **data = (void **)malloc(sizeof(void *) * out.size());
  catalogs->data = (void *)data;
  catalogs->len = out.size();
  catalogs->cap = out.size();
  int i = 0;
  for (it = out.begin(); it != out.end(); it++) {
    data[i] = (void *)(*it);
    i++;
  }
  *arg1 = catalogs;
  *arg2 = new absl::Status(ret);
}

void GO_EXPORT(EnumerableCatalog_Tables)(void * arg0,void ** arg1,void ** arg2)
{
  zetasql::EnumerableCatalog *catalog = (zetasql::EnumerableCatalog *)arg0;
  absl::flat_hash_set<const zetasql::Table *> out;
  absl::Status ret = catalog->GetTables(&out);
  absl::flat_hash_set<const zetasql::Table *>::iterator it;
  GoSlice *tables = (GoSlice *)malloc(sizeof(GoSlice));
  void **data = (void **)malloc(sizeof(void *) * out.size());
  tables->data = (void *)data;
  tables->len = out.size();
  tables->cap = out.size();
  int i = 0;
  for (it = out.begin(); it != out.end(); it++) {
    data[i] = (void *)(*it);
    i++;
  }
  *arg1 = tables;
  *arg2 = new absl::Status(ret);
}

void GO_EXPORT(EnumerableCatalog_Types)(void * arg0,void ** arg1,void ** arg2)
{
  zetasql::EnumerableCatalog *catalog = (zetasql::EnumerableCatalog *)arg0;
  absl::flat_hash_set<const zetasql::Type *> out;
  absl::Status ret = catalog->GetTypes(&out);
  GoSlice *types = (GoSlice *)malloc(sizeof(GoSlice));
  void **data = (void **)malloc(sizeof(void *) * out.size());
  types->data = (void *)data;
  types->len = out.size();
  types->cap = out.size();
  absl::flat_hash_set<const zetasql::Type *>::iterator it;
  int i = 0;
  for (it = out.begin(); it != out.end(); it++) {
    data[i] = (void *)(*it);
    i++;
  }
  *arg1 = types;
  *arg2 = new absl::Status(ret);
}

void GO_EXPORT(SimpleCatalog_new)(void * arg0,void ** arg1)
{
  *arg1 = (void *)(new zetasql::SimpleCatalog((char *)arg0));
}
  
void GO_EXPORT(SimpleCatalog_GetTable)(void * arg0,void * arg1,void ** arg2,void ** arg3)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  const zetasql::Table *table;
  absl::Status ret = catalog->GetTable((char *)arg1, &table);
  *arg2 = (void *)table;
  *arg3 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(SimpleCatalog_GetTables)(void * arg0,void ** arg1,void ** arg2)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  absl::flat_hash_set<const zetasql::Table*> out;
  absl::Status ret = catalog->GetTables(&out);

  absl::flat_hash_set<const zetasql::Table *>::iterator it;
  GoSlice *tables = (GoSlice *)malloc(sizeof(GoSlice));
  void **data = (void **)malloc(sizeof(void *) * out.size());
  tables->data = (void *)data;
  tables->len = out.size();
  tables->cap = out.size();
  int i = 0;
  for (it = out.begin(); it != out.end(); it++) {
    data[i] = (void *)(*it);
    i++;
  }
  *arg1 = tables;
  *arg2 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(SimpleCatalog_table_names_num)(void * arg0,int* arg1)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  *arg1 = catalog->table_names().size();
}

void GO_EXPORT(SimpleCatalog_table_name)(void * arg0,int arg1,void ** arg2)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  *arg2 = (void *)((new std::string(catalog->table_names()[arg1]))->c_str());
}

void GO_EXPORT(SimpleCatalog_GetType)(void * arg0,void * arg1,void ** arg2,void ** arg3)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  const zetasql::Type *type;
  absl::Status ret = catalog->GetType((char *)arg1, &type);
  *arg2 = (void *)type;
  *arg3 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(SimpleCatalog_GetTypes)(void * arg0,void ** arg1,void ** arg2)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  absl::flat_hash_set<const zetasql::Type*> out;
  absl::Status ret = catalog->GetTypes(&out);

  GoSlice *types = (GoSlice *)malloc(sizeof(GoSlice));
  void **data = (void **)malloc(sizeof(void *) * out.size());
  types->data = (void *)data;
  types->len = out.size();
  types->cap = out.size();
  absl::flat_hash_set<const zetasql::Type *>::iterator it;
  int i = 0;
  for (it = out.begin(); it != out.end(); it++) {
    data[i] = (void *)(*it);
    i++;
  }
  *arg1 = types;
  *arg2 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(SimpleCatalog_GetCatalog)(void * arg0,void * arg1,void ** arg2,void ** arg3)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  zetasql::Catalog *cat;
  absl::Status ret = catalog->GetCatalog((char *)arg1, &cat);
  *arg2 = (void *)cat;
  *arg3 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(SimpleCatalog_GetCatalogs)(void * arg0,void ** arg1,void ** arg2)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  absl::flat_hash_set<const zetasql::Catalog *> out;
  absl::Status ret = catalog->GetCatalogs(&out);

  absl::flat_hash_set<const zetasql::Catalog *>::iterator it;
  GoSlice *catalogs = (GoSlice *)malloc(sizeof(GoSlice));
  void **data = (void **)malloc(sizeof(void *) * out.size());
  catalogs->data = (void *)data;
  catalogs->len = out.size();
  catalogs->cap = out.size();
  int i = 0;
  for (it = out.begin(); it != out.end(); it++) {
    data[i] = (void *)(*it);
    i++;
  }
  *arg1 = catalogs;
  *arg2 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(SimpleCatalog_catalog_names_num)(void * arg0,int* arg1)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  *arg1 = catalog->catalog_names().size();
}

void GO_EXPORT(SimpleCatalog_catalog_name)(void * arg0,int arg1,void ** arg2)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  *arg2 = (void *)((new std::string(catalog->catalog_names()[arg1]))->c_str());
}

void GO_EXPORT(SimpleCatalog_AddTable)(void * arg0,void * arg1)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  catalog->AddTable((const zetasql::Table *)arg1);
}

void GO_EXPORT(SimpleCatalog_AddTableWithName)(void * arg0,void * arg1,void * arg2)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  catalog->AddTable((char *)arg1, (const zetasql::Table *)arg2);
}

void GO_EXPORT(SimpleCatalog_AddType)(void * arg0,void * arg1,void * arg2)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  catalog->AddType((char *)arg1, (const zetasql::Type *)arg2);
}

void GO_EXPORT(SimpleCatalog_AddTypeIfNotPresent)(void * arg0,void * arg1,void * arg2,int* arg3)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  catalog->AddTypeIfNotPresent((char *)arg1, (const zetasql::Type *)arg2);
}

void GO_EXPORT(SimpleCatalog_AddCatalog)(void * arg0,void * arg1)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  catalog->AddCatalog((zetasql::Catalog *)arg1);
}

void GO_EXPORT(SimpleCatalog_AddCatalogWithName)(void * arg0,void * arg1,void * arg2)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  catalog->AddCatalog((char *)arg1, (zetasql::Catalog *)arg2);
}
  
void GO_EXPORT(SimpleCatalog_AddZetaSQLFunctions)(void * arg0)
{
  zetasql::SimpleCatalog *catalog = (zetasql::SimpleCatalog *)arg0;
  catalog->AddZetaSQLFunctions();
}

void GO_EXPORT(Function_Name)(void * arg0,void ** arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = (void *)((new std::string(f->Name()))->c_str());
}

void GO_EXPORT(Function_FunctionNamePath)(void * arg0,void ** arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  SIMPLE_CATALOG_GET_STRS(f->FunctionNamePath, arg1);
}

void GO_EXPORT(Function_FullName)(void * arg0,int arg1,void ** arg2)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg2 = (void *)((new std::string(f->FullName(arg1)))->c_str());
}

void GO_EXPORT(Function_SQLName)(void * arg0,void ** arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = (void *)((new std::string(f->SQLName()))->c_str());
}

void GO_EXPORT(Function_QualifiedSQLName)(void * arg0,int arg1,void ** arg2)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg2 = (void *)((new std::string(f->QualifiedSQLName(arg1)))->c_str());
}

void GO_EXPORT(Function_Group)(void * arg0,void ** arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = (void *)((new std::string(f->GetGroup()))->c_str());
}

void GO_EXPORT(Function_IsZetaSQLBuiltin)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->IsZetaSQLBuiltin();
}

void GO_EXPORT(Function_ArgumentsAreCoercible)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->ArgumentsAreCoercible();
}

void GO_EXPORT(Function_NumSignatures)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->NumSignatures();
}

void GO_EXPORT(Function_signatures)(void * arg0,void ** arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  SIMPLE_CATALOG_GET_LIST(f->signatures, arg1);
}

void GO_EXPORT(Function_ResetSignatures)(void * arg0,void * arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  SIMPLE_CATALOG_SET_LIST(f->ResetSignatures, zetasql::FunctionSignature, arg1);
}

void GO_EXPORT(Function_AddSignature)(void * arg0,void * arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  f->AddSignature(*(zetasql::FunctionSignature *)arg1);
}

void GO_EXPORT(Function_mode)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->mode();
}

void GO_EXPORT(Function_IsScalar)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->IsScalar();
}

void GO_EXPORT(Function_IsAggregate)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->IsAggregate();
}

void GO_EXPORT(Function_IsAnalytic)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->IsAnalytic();
}

void GO_EXPORT(Function_DebugString)(void * arg0,int arg1,void ** arg2)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg2 = (void *)((new std::string(f->DebugString(arg1)))->c_str());
}

void GO_EXPORT(Function_GetSQL)(void * arg0,void * arg1,void * arg2,void ** arg3)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  const std::vector<std::string> &inputs = slice_to_vec<std::string>(arg1);
  *arg3 = (void *)((new std::string(f->GetSQL(inputs, (const zetasql::FunctionSignature *)arg2)))->c_str());
}

void GO_EXPORT(Function_SupportsOverClause)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->SupportsOverClause();
}

void GO_EXPORT(Function_SupportsWindowOrdering)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->SupportsWindowOrdering();
}

void GO_EXPORT(Function_RequiresWindowOrdering)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->RequiresWindowOrdering();
}

void GO_EXPORT(Function_SupportsWindowFraming)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->SupportsWindowFraming();
}

void GO_EXPORT(Function_SupportsOrderingArguments)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->SupportsOrderingArguments();
}

void GO_EXPORT(Function_SupportsLimitArguments)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->SupportsLimitArguments();
}

void GO_EXPORT(Function_SupportsNullHandlingModifier)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->SupportsNullHandlingModifier();
}

void GO_EXPORT(Function_SupportsSafeErrorMode)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->SupportsSafeErrorMode();
}

void GO_EXPORT(Function_SupportsHavingModifier)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->SupportsHavingModifier();
}

void GO_EXPORT(Function_SupportsDistinctModifier)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->SupportsDistinctModifier();
}

void GO_EXPORT(Function_SupportsClampedBetweenModifier)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->SupportsClampedBetweenModifier();
}

void GO_EXPORT(Function_IsDeprecated)(void * arg0,int* arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = f->IsDeprecated();
}

void GO_EXPORT(Function_alias_name)(void * arg0,void ** arg1)
{
  zetasql::Function *f = (zetasql::Function *)arg0;
  *arg1 = (void *)((new std::string(f->alias_name()))->c_str());
}

void GO_EXPORT(FunctionArgumentType_required)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->required();
}

void GO_EXPORT(FunctionArgumentType_repeated)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->repeated();
}

void GO_EXPORT(FunctionArgumentType_optional)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->optional();
}

void GO_EXPORT(FunctionArgumentType_cardinality)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->cardinality();
}

void GO_EXPORT(FunctionArgumentType_must_be_constant)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->must_be_constant();
}

void GO_EXPORT(FunctionArgumentType_has_argument_name)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->has_argument_name();
}

void GO_EXPORT(FunctionArgumentType_argument_name)(void * arg0,void ** arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = (void *)((new std::string(type->argument_name()))->c_str());
}

void GO_EXPORT(FunctionArgumentType_num_occurrences)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->num_occurrences();
}

void GO_EXPORT(FunctionArgumentType_set_num_occurrences)(void * arg0,int arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  type->set_num_occurrences(arg1);
}

void GO_EXPORT(FunctionArgumentType_IncrementNumOccurrences)(void * arg0)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  type->IncrementNumOccurrences();
}

void GO_EXPORT(FunctionArgumentType_type)(void * arg0,void ** arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = (void *)type->type();
}

void GO_EXPORT(FunctionArgumentType_kind)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->kind();
}

void GO_EXPORT(FunctionArgumentType_labmda)(void * arg0,void ** arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = (void *)(new zetasql::FunctionArgumentType::ArgumentTypeLambda(type->lambda()));
}

void GO_EXPORT(FunctionArgumentType_IsConcrete)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->IsConcrete();
}

void GO_EXPORT(FunctionArgumentType_IsTemplated)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->IsTemplated();
}

void GO_EXPORT(FunctionArgumentType_IsScalar)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->IsScalar();
}

void GO_EXPORT(FunctionArgumentType_IsRelation)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->IsRelation();
}

void GO_EXPORT(FunctionArgumentType_IsModel)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->IsModel();
}

void GO_EXPORT(FunctionArgumentType_IsConnection)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->IsConnection();
}

void GO_EXPORT(FunctionArgumentType_IsLambda)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->IsLambda();
}

void GO_EXPORT(FunctionArgumentType_IsFixedRelation)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->IsFixedRelation();
}

void GO_EXPORT(FunctionArgumentType_IsVoid)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->IsVoid();
}

void GO_EXPORT(FunctionArgumentType_IsDescriptor)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->IsDescriptor();
}

void GO_EXPORT(FunctionArgumentType_TemplatedKindIsRelated)(void * arg0,int arg1,int* arg2)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg2 = type->TemplatedKindIsRelated((zetasql::SignatureArgumentKind)arg1);
}

void GO_EXPORT(FunctionArgumentType_AllowCoercionFrom)(void * arg0,void * arg1,int* arg2)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg2 = type->AllowCoercionFrom((const zetasql::Type *)arg1);
}

void GO_EXPORT(FunctionArgumentType_HasDefault)(void * arg0,int* arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg1 = type->HasDefault();
}

void GO_EXPORT(FunctionArgumentType_GetDefault)(void * arg0,void ** arg1)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  std::optional<zetasql::Value> ret = type->GetDefault();
  if (ret) {
    *arg1 = (void *)(new zetasql::Value(ret.value()));
  }
}

void GO_EXPORT(FunctionArgumentType_UserFacingName)(void * arg0,int arg1,void ** arg2)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg2 = (void *)((new std::string(type->UserFacingName((zetasql::ProductMode)arg1)))->c_str());
}

void GO_EXPORT(FunctionArgumentType_UserFacingNameWithCardinality)(void * arg0,int arg1,void ** arg2)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg2 = (void *)((new std::string(type->UserFacingNameWithCardinality((zetasql::ProductMode)arg1)))->c_str());
}

void GO_EXPORT(FunctionArgumentType_IsValid)(void * arg0,int arg1,void ** arg2)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg2 = (void *)(new absl::Status(type->IsValid((zetasql::ProductMode)arg1)));
}

void GO_EXPORT(FunctionArgumentType_DebugString)(void * arg0,int arg1,void ** arg2)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg2 = (void *)((new std::string(type->DebugString(arg1)))->c_str());
}

void GO_EXPORT(FunctionArgumentType_GetSQLDeclaration)(void * arg0,int arg1,void ** arg2)
{
  zetasql::FunctionArgumentType *type = (zetasql::FunctionArgumentType *)arg0;
  *arg2 = (void *)((new std::string(type->GetSQLDeclaration((zetasql::ProductMode)arg1)))->c_str());
}

void GO_EXPORT(ArgumentTypeLambda_argument_types)(void * arg0,void ** arg1)
{
  zetasql::FunctionArgumentType::ArgumentTypeLambda *lambda = (zetasql::FunctionArgumentType::ArgumentTypeLambda *)arg0;
  SIMPLE_CATALOG_GET_LIST(lambda->argument_types, arg1);
}

void GO_EXPORT(ArgumentTypeLambda_body_type)(void * arg0,void ** arg1)
{
  zetasql::FunctionArgumentType::ArgumentTypeLambda *lambda = (zetasql::FunctionArgumentType::ArgumentTypeLambda *)arg0;
  *arg1 = (void *)(new zetasql::FunctionArgumentType(lambda->body_type()));
}

void GO_EXPORT(FunctionSignature_arguments)(void * arg0,void ** arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  SIMPLE_CATALOG_GET_LIST(sig->arguments, arg1);
}

void GO_EXPORT(FunctionSignature_concret_arguments)(void * arg0,void ** arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  int num = sig->NumConcreteArguments();
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  void **data = (void **)malloc(sizeof(void *) * num);
  for (int i = 0; i < sig->NumConcreteArguments(); i++) {
    data[i] =(void *)(new zetasql::FunctionArgumentType(sig->ConcreteArgument(i)));
  }
  slice->data = (void *)data;
  slice->len = num;
  slice->cap = num;
  *arg1 = (void *)data;
}

void GO_EXPORT(FunctionSignature_result_type)(void * arg0,void ** arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = (void *)(new zetasql::FunctionArgumentType(sig->result_type()));
}

void GO_EXPORT(FunctionSignature_IsConcrete)(void * arg0,int* arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = sig->IsConcrete();
}

void GO_EXPORT(FunctionSignature_HasConcreteArguments)(void * arg0,int* arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = sig->HasConcreteArguments();
}

void GO_EXPORT(FunctionSignature_IsValid)(void * arg0,int arg1,void ** arg2)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg2 = (void *)(new absl::Status(sig->IsValid((zetasql::ProductMode)arg1)));
}

void GO_EXPORT(FunctionSignature_IsValidForFunction)(void * arg0,void ** arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = (void *)(new absl::Status(sig->IsValidForFunction()));
}

void GO_EXPORT(FunctionSignature_IsValidForTableValuedFunction)(void * arg0,void ** arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = (void *)(new absl::Status(sig->IsValidForTableValuedFunction()));
}

void GO_EXPORT(FunctionSignature_IsValidForProcedure)(void * arg0,void ** arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = (void *)(new absl::Status(sig->IsValidForProcedure()));
}

void GO_EXPORT(FunctionSignature_FirstRepeatedArgumentIndex)(void * arg0,int* arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = sig->FirstRepeatedArgumentIndex();
}

void GO_EXPORT(FunctionSignature_LastRepeatedArgumentIndex)(void * arg0,int* arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = sig->LastRepeatedArgumentIndex();
}

void GO_EXPORT(FunctionSignature_NumRequiredArguments)(void * arg0,int* arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = sig->NumRequiredArguments();
}

void GO_EXPORT(FunctionSignature_NumRepeatedArguments)(void * arg0,int* arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = sig->NumRepeatedArguments();
}

void GO_EXPORT(FunctionSignature_NumOptionalArguments)(void * arg0,int* arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = sig->NumOptionalArguments();
}

void GO_EXPORT(FunctionSignature_DebugString)(void * arg0,void * arg1,int arg2,void ** arg3)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg3 = (void *)((new std::string(sig->DebugString((char *)arg1, arg2)))->c_str());
}

void GO_EXPORT(FunctionSignature_GetSQLDeclaration)(void * arg0,void * arg1,int arg2,void ** arg3)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  const std::vector<std::string> &names = slice_to_vec<std::string>(arg1);
  *arg3 = (void *)((new std::string(sig->GetSQLDeclaration(names, (zetasql::ProductMode)arg2)))->c_str());
}

void GO_EXPORT(FunctionSignature_IsDeprecated)(void * arg0,int* arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = sig->IsDeprecated();
}

void GO_EXPORT(FunctionSignature_SetIsDeprecated)(void * arg0,int arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  sig->SetIsDeprecated(arg1);
}

void GO_EXPORT(FunctionSignature_IsInternal)(void * arg0,int* arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = sig->IsInternal();
}

void GO_EXPORT(FunctionSignature_options)(void * arg0,void ** arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = (void *)(new zetasql::FunctionSignatureOptions(sig->options()));
}

void GO_EXPORT(FunctionSignature_SetConcreteResultType)(void * arg0,void * arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  sig->SetConcreteResultType((const zetasql::Type *)arg1);
}

void GO_EXPORT(FunctionSignature_IsTemplated)(void * arg0,int* arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = sig->IsTemplated();
}

void GO_EXPORT(FunctionSignature_AllArgumentsHaveDefaults)(void * arg0,int* arg1)
{
  zetasql::FunctionSignature *sig = (zetasql::FunctionSignature *)arg0;
  *arg1 = sig->AllArgumentsHaveDefaults();
}

