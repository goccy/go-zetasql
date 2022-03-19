#include "_cgo_export.h"

void GO_EXPORT(TypeFactory_MakeArrayType)(void * arg0,void * arg1,void ** arg2,void ** arg3)
{
  zetasql::TypeFactory *factory = (zetasql::TypeFactory *)arg0;
  const zetasql::ArrayType *out = nullptr;
  absl::Status ret = factory->MakeArrayType((const zetasql::Type *)arg1, &out);
  *arg2 = (void *)out;
  *arg3 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(TypeFactory_MakeStructType)(void * arg0,void * arg1,void ** arg2,void ** arg3)
{
  zetasql::TypeFactory *factory = (zetasql::TypeFactory *)arg0;
  GoSlice *slice = (GoSlice *)arg1;
  absl::Span<const zetasql::StructType::StructField> fields((const zetasql::StructType::StructField *)slice->data, slice->len);
  const zetasql::StructType *out = nullptr;
  absl::Status ret = factory->MakeStructType(fields, &out);
  *arg2 = (void *)out;
  *arg3 = (void *)(new absl::Status(ret));
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

void GO_EXPORT(SimpleTable_new)(void * arg0,void * arg1,void ** arg2)
{
  GoSlice *slice = (GoSlice *)arg1;
  zetasql::Column **data = (zetasql::Column **)slice->data;
  std::vector<const zetasql::Column *> columns;
  for (int i = 0; i < slice->len; i++) {
    columns.push_back(data[i]);
  }
  zetasql::SimpleTable *ret = new zetasql::SimpleTable((char *)arg0, columns);
  *arg2 = (void *)ret;
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
