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
  *arg2 = (void *)type->ShortTypeName((zetasql::ProductMode)arg1).c_str();
}

void GO_EXPORT(Type_TypeName)(void * arg0,int arg1,void ** arg2)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg2 = (void *)type->TypeName((zetasql::ProductMode)arg1).c_str();
}

void GO_EXPORT(Type_TypeNameWithParameters)(void * arg0,void * arg1,int arg2,void ** arg3,void ** arg4)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  zetasql::TypeParameters *params = (zetasql::TypeParameters *)arg1;
  absl::StatusOr<std::string> ret = type->TypeNameWithParameters(*params, (zetasql::ProductMode)arg2);
  if (ret.ok()) {
    *arg3 = (void *)ret.value().c_str();
    *arg4 = (void *)(new absl::Status(absl::OkStatus()));
  } else {
    *arg3 = nullptr;
    *arg4 = (void *)(new absl::Status(ret.status()));
  }
}

void GO_EXPORT(Type_DebugString)(void * arg0,int arg1,void ** arg2)
{
  zetasql::Type *type = (zetasql::Type *)arg0;
  *arg2 = (void *)type->DebugString(arg1).c_str();
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
  std::vector<const zetasql::StructType::StructField> fields;
  for (int i = 0; i < arg2; i++) {
    fields.push_back(*data[i]);
  }
  const zetasql::StructType *out = nullptr;
  absl::Status ret = factory->MakeStructType(fields, &out);
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

void GO_EXPORT(Column_Name)(void * arg0,void ** arg1)
{
  zetasql::Column *col = (zetasql::Column *)arg0;
  *arg1 = (void *)col->Name().c_str();
}

void GO_EXPORT(Column_FullName)(void * arg0,void ** arg1)
{
  zetasql::Column *col = (zetasql::Column *)arg0;
  *arg1 = (void *)col->FullName().c_str();
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
  *arg1 = (void *)table->Name().c_str();
}

void GO_EXPORT(Table_FullName)(void * arg0,void ** arg1)
{
  zetasql::Table *table = (zetasql::Table *)arg0;
  *arg1 = (void *)table->FullName().c_str();
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
  *arg2 = (void *)table->GetTableTypeName((zetasql::ProductMode)arg1).c_str();
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
  *arg1 = (void *)catalog->FullName().c_str();
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
  *arg2 = (void *)catalog->SuggestTable(path).c_str();
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
  *arg2 = (void *)catalog->table_names()[arg1].c_str();
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
  *arg2 = (void *)catalog->catalog_names()[arg1].c_str();
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
