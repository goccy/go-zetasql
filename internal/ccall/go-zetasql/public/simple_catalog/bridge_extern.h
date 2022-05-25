
extern void GO_EXPORT(Type_Kind)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsInt32)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsInt64)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsUint32)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsUint64)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsBool)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsFloat)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsDouble)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsString)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsBytes)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsDate)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsTimestamp)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsTime)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsDatetime)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsInterval)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsNumericType)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsBigNumericType)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsJsonType)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsFeatureV12CivilTimeType)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_UsingFeatureV12CivilTimeType)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsCivilDateOrTimeType)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsGeography)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsJson)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsEnum)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsArray)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsStruct)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsProto)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsStructOrProto)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsFloatingPoint)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsNumerical)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsInteger)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsInteger32)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsInteger64)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsSignedInteger)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsUnsignedInteger)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsSimpleType)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_IsExtendedType)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_SupportsGrouping)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_SupportsPartitioning)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_SupportsOrdering)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_SupportsEquality)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_Equals)(void * arg0,void * arg1,int* arg2);
extern void GO_EXPORT(Type_Equivalent)(void * arg0,void * arg1,int* arg2);
extern void GO_EXPORT(Type_ShortTypeName)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(Type_TypeName)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(Type_TypeNameWithParameters)(void * arg0,void * arg1,int arg2,void ** arg3,void ** arg4);
extern void GO_EXPORT(Type_DebugString)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(Type_HasAnyFields)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_NestingDepth)(void * arg0,int* arg1);
extern void GO_EXPORT(Type_ValidateAndResolveTypeParameters)(void * arg0,void * arg1,int arg2,int arg3,void ** arg4,void ** arg5);
extern void GO_EXPORT(Type_ValidateResolvedTypeParameters)(void * arg0,void * arg1,int arg2,void ** arg3);
extern void GO_EXPORT(TypeFactory_MakeArrayType)(void * arg0,void * arg1,void ** arg2,void ** arg3);
extern void GO_EXPORT(TypeFactory_MakeStructType)(void * arg0,void * arg1,int arg2,void ** arg3,void ** arg4);
extern void GO_EXPORT(Int32Type)(void ** arg0);
extern void GO_EXPORT(Int64Type)(void ** arg0);
extern void GO_EXPORT(Uint32Type)(void ** arg0);
extern void GO_EXPORT(Uint64Type)(void ** arg0);
extern void GO_EXPORT(BoolType)(void ** arg0);
extern void GO_EXPORT(FloatType)(void ** arg0);
extern void GO_EXPORT(DoubleType)(void ** arg0);
extern void GO_EXPORT(StringType)(void ** arg0);
extern void GO_EXPORT(BytesType)(void ** arg0);
extern void GO_EXPORT(DateType)(void ** arg0);
extern void GO_EXPORT(TimestampType)(void ** arg0);
extern void GO_EXPORT(TimeType)(void ** arg0);
extern void GO_EXPORT(DatetimeType)(void ** arg0);
extern void GO_EXPORT(IntervalType)(void ** arg0);
extern void GO_EXPORT(GeographyType)(void ** arg0);
extern void GO_EXPORT(NumericType)(void ** arg0);
extern void GO_EXPORT(BigNumericType)(void ** arg0);
extern void GO_EXPORT(JsonType)(void ** arg0);
extern void GO_EXPORT(EmptyStructType)(void ** arg0);
extern void GO_EXPORT(Int32ArrayType)(void ** arg0);
extern void GO_EXPORT(Int64ArrayType)(void ** arg0);
extern void GO_EXPORT(Uint32ArrayType)(void ** arg0);
extern void GO_EXPORT(Uint64ArrayType)(void ** arg0);
extern void GO_EXPORT(BoolArrayType)(void ** arg0);
extern void GO_EXPORT(FloatArrayType)(void ** arg0);
extern void GO_EXPORT(DoubleArrayType)(void ** arg0);
extern void GO_EXPORT(StringArrayType)(void ** arg0);
extern void GO_EXPORT(BytesArrayType)(void ** arg0);
extern void GO_EXPORT(TimestampArrayType)(void ** arg0);
extern void GO_EXPORT(DateArrayType)(void ** arg0);
extern void GO_EXPORT(DatetimeArrayType)(void ** arg0);
extern void GO_EXPORT(TimeArrayType)(void ** arg0);
extern void GO_EXPORT(IntervalArrayType)(void ** arg0);
extern void GO_EXPORT(GeographyArrayType)(void ** arg0);
extern void GO_EXPORT(NumericArrayType)(void ** arg0);
extern void GO_EXPORT(BigNumericArrayType)(void ** arg0);
extern void GO_EXPORT(JsonArrayType)(void ** arg0);
extern void GO_EXPORT(DatePartEnumType)(void ** arg0);
extern void GO_EXPORT(NormalizeModeEnumType)(void ** arg0);
extern void GO_EXPORT(TypeFromSimpleTypeKind)(int arg0,void ** arg1);
extern void GO_EXPORT(Value_type)(void * arg0,void ** arg1);
extern void GO_EXPORT(Value_type_kind)(void * arg0,int* arg1);
extern void GO_EXPORT(Value_physical_byte_size)(void * arg0,uint64_t* arg1);
extern void GO_EXPORT(Value_is_null)(void * arg0,int* arg1);
extern void GO_EXPORT(Value_is_empty_array)(void * arg0,int* arg1);
extern void GO_EXPORT(Value_is_valid)(void * arg0,int* arg1);
extern void GO_EXPORT(Value_has_content)(void * arg0,int* arg1);
extern void GO_EXPORT(Value_int32_value)(void * arg0,int* arg1);
extern void GO_EXPORT(Value_int64_value)(void * arg0,int64_t* arg1);
extern void GO_EXPORT(Value_uint32_value)(void * arg0,uint32_t* arg1);
extern void GO_EXPORT(Value_uint64_value)(void * arg0,uint64_t* arg1);
extern void GO_EXPORT(Value_bool_value)(void * arg0,int* arg1);
extern void GO_EXPORT(Value_float_value)(void * arg0,float* arg1);
extern void GO_EXPORT(Value_double_value)(void * arg0,double* arg1);
extern void GO_EXPORT(Value_string_value)(void * arg0,void ** arg1);
extern void GO_EXPORT(Value_bytes_value)(void * arg0,void ** arg1);
extern void GO_EXPORT(Value_date_value)(void * arg0,int* arg1);
extern void GO_EXPORT(Value_enum_value)(void * arg0,int* arg1);
extern void GO_EXPORT(Value_enum_name)(void * arg0,void ** arg1);
extern void GO_EXPORT(Value_ToUnixMicros)(void * arg0,int64_t* arg1);
extern void GO_EXPORT(Value_ToUnixNanos)(void * arg0,int64_t* arg1,void ** arg2);
extern void GO_EXPORT(Value_ToPacked64TimeMicros)(void * arg0,int64_t* arg1);
extern void GO_EXPORT(Value_ToPacked64DatetimeMicros)(void * arg0,int64_t* arg1);
extern void GO_EXPORT(Value_is_validated_json)(void * arg0,int* arg1);
extern void GO_EXPORT(Value_is_unparsed_json)(void * arg0,int* arg1);
extern void GO_EXPORT(Value_json_value_unparsed)(void * arg0,void ** arg1);
extern void GO_EXPORT(Value_json_string)(void * arg0,void ** arg1);
extern void GO_EXPORT(Value_ToInt64)(void * arg0,int64_t* arg1);
extern void GO_EXPORT(Value_ToUint64)(void * arg0,uint64_t* arg1);
extern void GO_EXPORT(Value_ToDouble)(void * arg0,double* arg1);
extern void GO_EXPORT(Value_num_fields)(void * arg0,int* arg1);
extern void GO_EXPORT(Value_field)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(Value_FindFieldByName)(void * arg0,void * arg1,void ** arg2);
extern void GO_EXPORT(Value_empty)(void * arg0,int* arg1);
extern void GO_EXPORT(Value_num_elements)(void * arg0,int* arg1);
extern void GO_EXPORT(Value_element)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(Value_Equals)(void * arg0,void * arg1,int* arg2);
extern void GO_EXPORT(Value_SqlEquals)(void * arg0,void * arg1,void ** arg2);
extern void GO_EXPORT(Value_LessThan)(void * arg0,void * arg1,int* arg2);
extern void GO_EXPORT(Value_SqlLessThan)(void * arg0,void * arg1,void ** arg2);
extern void GO_EXPORT(Value_HashCode)(void * arg0,uint64_t* arg1);
extern void GO_EXPORT(Value_ShortDebugString)(void * arg0,void ** arg1);
extern void GO_EXPORT(Value_FullDebugString)(void * arg0,void ** arg1);
extern void GO_EXPORT(Value_DebugString)(void * arg0,void ** arg1);
extern void GO_EXPORT(Value_Format)(void * arg0,void ** arg1);
extern void GO_EXPORT(Value_GetSQL)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(Value_GetSQLLiteral)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(Int64)(int64_t arg0,void ** arg1);
extern void GO_EXPORT(Column_Name)(void * arg0,void ** arg1);
extern void GO_EXPORT(Column_FullName)(void * arg0,void ** arg1);
extern void GO_EXPORT(Column_Type)(void * arg0,void ** arg1);
extern void GO_EXPORT(Column_IsPseudoColumn)(void * arg0,int* arg1);
extern void GO_EXPORT(Column_IsWritableColumn)(void * arg0,int* arg1);
extern void GO_EXPORT(SimpleColumn_new)(void * arg0,void * arg1,void * arg2,void ** arg3);
extern void GO_EXPORT(SimpleColumn_new_with_opt)(void * arg0,void * arg1,void * arg2,int arg3,int arg4,void ** arg5);
extern void GO_EXPORT(SimpleColumn_AnnotatedType)(void * arg0,void ** arg1);
extern void GO_EXPORT(SimpleColumn_SetIsPseudoColumn)(void * arg0,int arg1);
extern void GO_EXPORT(Table_Name)(void * arg0,void ** arg1);
extern void GO_EXPORT(Table_FullName)(void * arg0,void ** arg1);
extern void GO_EXPORT(Table_NumColumns)(void * arg0,int* arg1);
extern void GO_EXPORT(Table_Column)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(Table_PrimaryKey_num)(void * arg0,int* arg1);
extern void GO_EXPORT(Table_PrimaryKey)(void * arg0,int arg1,int* arg2);
extern void GO_EXPORT(Table_FindColumnByName)(void * arg0,void * arg1,void ** arg2);
extern void GO_EXPORT(Table_IsValueTable)(void * arg0,int* arg1);
extern void GO_EXPORT(Table_GetSerializationId)(void * arg0,int* arg1);
extern void GO_EXPORT(Table_CreateEvaluatorTableIterator)(void * arg0,void * arg1,int arg2,void ** arg3,void ** arg4);
extern void GO_EXPORT(Table_GetAnonymizationInfo)(void * arg0,void ** arg1);
extern void GO_EXPORT(Table_SupportsAnonymization)(void * arg0,int* arg1);
extern void GO_EXPORT(Table_GetTableTypeName)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(SimpleTable_new)(void * arg0,void * arg1,int arg2,void ** arg3);
extern void GO_EXPORT(SimpleTable_set_is_value_table)(void * arg0,int arg1);
extern void GO_EXPORT(SimpleTable_AllowAnonymousColumnName)(void * arg0,int* arg1);
extern void GO_EXPORT(SimpleTable_set_allow_anonymous_column_name)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(SimpleTable_AllowDuplicateColumnNames)(void * arg0,int* arg1);
extern void GO_EXPORT(SimpleTable_set_allow_duplicate_column_names)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(SimpleTable_AddColumn)(void * arg0,void * arg1,void ** arg2);
extern void GO_EXPORT(SimpleTable_SetPrimaryKey)(void * arg0,void * arg1,int arg2,void ** arg3);
extern void GO_EXPORT(SimpleTable_set_full_name)(void * arg0,void * arg1,void ** arg2);
extern void GO_EXPORT(SimpleTable_SetAnonymizationInfo)(void * arg0,void * arg1,void ** arg2);
extern void GO_EXPORT(SimpleTable_ResetAnonymizationInfo)(void * arg0);
extern void GO_EXPORT(Catalog_FullName)(void * arg0,void ** arg1);
extern void GO_EXPORT(Catalog_FindTable)(void * arg0,void * arg1,void ** arg2,void ** arg3);
extern void GO_EXPORT(Catalog_FindType)(void * arg0,void * arg1,void ** arg2,void ** arg3);
extern void GO_EXPORT(Catalog_SuggestTable)(void * arg0,void * arg1,void ** arg2);
extern void GO_EXPORT(EnumerableCatalog_Catalogs)(void * arg0,void ** arg1,void ** arg2);
extern void GO_EXPORT(EnumerableCatalog_Tables)(void * arg0,void ** arg1,void ** arg2);
extern void GO_EXPORT(EnumerableCatalog_Types)(void * arg0,void ** arg1,void ** arg2);
extern void GO_EXPORT(SimpleCatalog_new)(void * arg0,void ** arg1);
extern void GO_EXPORT(SimpleCatalog_GetTable)(void * arg0,void * arg1,void ** arg2,void ** arg3);
extern void GO_EXPORT(SimpleCatalog_GetTables)(void * arg0,void ** arg1,void ** arg2);
extern void GO_EXPORT(SimpleCatalog_table_names_num)(void * arg0,int* arg1);
extern void GO_EXPORT(SimpleCatalog_table_name)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(SimpleCatalog_GetType)(void * arg0,void * arg1,void ** arg2,void ** arg3);
extern void GO_EXPORT(SimpleCatalog_GetTypes)(void * arg0,void ** arg1,void ** arg2);
extern void GO_EXPORT(SimpleCatalog_GetCatalog)(void * arg0,void * arg1,void ** arg2,void ** arg3);
extern void GO_EXPORT(SimpleCatalog_GetCatalogs)(void * arg0,void ** arg1,void ** arg2);
extern void GO_EXPORT(SimpleCatalog_catalog_names_num)(void * arg0,int* arg1);
extern void GO_EXPORT(SimpleCatalog_catalog_name)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(SimpleCatalog_AddTable)(void * arg0,void * arg1);
extern void GO_EXPORT(SimpleCatalog_AddTableWithName)(void * arg0,void * arg1,void * arg2);
extern void GO_EXPORT(SimpleCatalog_AddType)(void * arg0,void * arg1,void * arg2);
extern void GO_EXPORT(SimpleCatalog_AddTypeIfNotPresent)(void * arg0,void * arg1,void * arg2,int* arg3);
extern void GO_EXPORT(SimpleCatalog_AddCatalog)(void * arg0,void * arg1);
extern void GO_EXPORT(SimpleCatalog_AddCatalogWithName)(void * arg0,void * arg1,void * arg2);
extern void GO_EXPORT(SimpleCatalog_AddZetaSQLFunctions)(void * arg0);
extern void GO_EXPORT(Function_Name)(void * arg0,void ** arg1);
extern void GO_EXPORT(Function_FunctionNamePath)(void * arg0,void ** arg1);
extern void GO_EXPORT(Function_FullName)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(Function_SQLName)(void * arg0,void ** arg1);
extern void GO_EXPORT(Function_QualifiedSQLName)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(Function_Group)(void * arg0,void ** arg1);
extern void GO_EXPORT(Function_IsZetaSQLBuiltin)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_ArgumentsAreCoercible)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_NumSignatures)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_signatures)(void * arg0,void ** arg1);
extern void GO_EXPORT(Function_ResetSignatures)(void * arg0,void * arg1);
extern void GO_EXPORT(Function_AddSignature)(void * arg0,void * arg1);
extern void GO_EXPORT(Function_mode)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_IsScalar)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_IsAggregate)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_IsAnalytic)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_DebugString)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(Function_GetSQL)(void * arg0,void * arg1,void * arg2,void ** arg3);
extern void GO_EXPORT(Function_SupportsOverClause)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_SupportsWindowOrdering)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_RequiresWindowOrdering)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_SupportsWindowFraming)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_SupportsOrderingArguments)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_SupportsLimitArguments)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_SupportsNullHandlingModifier)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_SupportsSafeErrorMode)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_SupportsHavingModifier)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_SupportsDistinctModifier)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_SupportsClampedBetweenModifier)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_IsDeprecated)(void * arg0,int* arg1);
extern void GO_EXPORT(Function_alias_name)(void * arg0,void ** arg1);
extern void GO_EXPORT(FunctionArgumentType_required)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_repeated)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_optional)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_cardinality)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_must_be_constant)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_has_argument_name)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_argument_name)(void * arg0,void ** arg1);
extern void GO_EXPORT(FunctionArgumentType_num_occurrences)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_set_num_occurrences)(void * arg0,int arg1);
extern void GO_EXPORT(FunctionArgumentType_IncrementNumOccurrences)(void * arg0);
extern void GO_EXPORT(FunctionArgumentType_type)(void * arg0,void ** arg1);
extern void GO_EXPORT(FunctionArgumentType_kind)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_labmda)(void * arg0,void ** arg1);
extern void GO_EXPORT(FunctionArgumentType_IsConcrete)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_IsTemplated)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_IsScalar)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_IsRelation)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_IsModel)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_IsConnection)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_IsLambda)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_IsFixedRelation)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_IsVoid)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_IsDescriptor)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_TemplatedKindIsRelated)(void * arg0,int arg1,int* arg2);
extern void GO_EXPORT(FunctionArgumentType_AllowCoercionFrom)(void * arg0,void * arg1,int* arg2);
extern void GO_EXPORT(FunctionArgumentType_HasDefault)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionArgumentType_GetDefault)(void * arg0,void ** arg1);
extern void GO_EXPORT(FunctionArgumentType_UserFacingName)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(FunctionArgumentType_UserFacingNameWithCardinality)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(FunctionArgumentType_IsValid)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(FunctionArgumentType_DebugString)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(FunctionArgumentType_GetSQLDeclaration)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(ArgumentTypeLambda_argument_types)(void * arg0,void ** arg1);
extern void GO_EXPORT(ArgumentTypeLambda_body_type)(void * arg0,void ** arg1);
extern void GO_EXPORT(FunctionSignature_arguments)(void * arg0,void ** arg1);
extern void GO_EXPORT(FunctionSignature_concret_arguments)(void * arg0,void ** arg1);
extern void GO_EXPORT(FunctionSignature_result_type)(void * arg0,void ** arg1);
extern void GO_EXPORT(FunctionSignature_IsConcrete)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionSignature_HasConcreteArguments)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionSignature_IsValid)(void * arg0,int arg1,void ** arg2);
extern void GO_EXPORT(FunctionSignature_IsValidForFunction)(void * arg0,void ** arg1);
extern void GO_EXPORT(FunctionSignature_IsValidForTableValuedFunction)(void * arg0,void ** arg1);
extern void GO_EXPORT(FunctionSignature_IsValidForProcedure)(void * arg0,void ** arg1);
extern void GO_EXPORT(FunctionSignature_FirstRepeatedArgumentIndex)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionSignature_LastRepeatedArgumentIndex)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionSignature_NumRequiredArguments)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionSignature_NumRepeatedArguments)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionSignature_NumOptionalArguments)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionSignature_DebugString)(void * arg0,void * arg1,int arg2,void ** arg3);
extern void GO_EXPORT(FunctionSignature_GetSQLDeclaration)(void * arg0,void * arg1,int arg2,void ** arg3);
extern void GO_EXPORT(FunctionSignature_IsDeprecated)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionSignature_SetIsDeprecated)(void * arg0,int arg1);
extern void GO_EXPORT(FunctionSignature_IsInternal)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionSignature_options)(void * arg0,void ** arg1);
extern void GO_EXPORT(FunctionSignature_SetConcreteResultType)(void * arg0,void * arg1);
extern void GO_EXPORT(FunctionSignature_IsTemplated)(void * arg0,int* arg1);
extern void GO_EXPORT(FunctionSignature_AllArgumentsHaveDefaults)(void * arg0,int* arg1);
