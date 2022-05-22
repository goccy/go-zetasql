package zetasql

// ParameterMode mode describing how parameters are defined and referenced.
type ParameterMode int

const (
	// Parameters are defined by name (the default) and referenced using the
	// syntax @param_name.
	ParameterNamed ParameterMode = 0

	// Parameters are defined positionally and referenced with ?. For example, if
	// two parameters are bound, the first occurrence of ? in the query string
	// refers to the first parameter and the second occurrence to the second
	// parameter.
	ParameterPositional ParameterMode = 1

	// No parameters are allowed in the query.
	ParameterNone ParameterMode = 2
)

// ErrorMessageMode mode describing how errors should be constructed in the returned error.
type ErrorMessageMode int

const (
	// The error string does not contain a location.
	// An ErrorLocation proto will be attached to the error with
	// a location, when applicable.
	ErrorMessageWithPayload ErrorMessageMode = 0

	// The error string contains a suffix " [at <line>:<column>]" when an
	// error location is available.
	ErrorMessageOneLine ErrorMessageMode = 1

	// The error string matches ErrorMessageOneLine, and also contains
	// a second line with a substring of the input query, and a third line
	// with a caret ("^") pointing at the error location above.
	ErrorMessageMultiLineWithCaret ErrorMessageMode = 2
)

// StatementContext identifies whether statements are resolved in module context (i.e.,
// as a statement contained in a module), or in normal/default context
// (outside of a module).
type StatementContext int

const (
	StatementContextDefault StatementContext = 0
	StatementContextModule  StatementContext = 1
)

// ParseLocationRecordType the option controlling what kind of parse location is recorded in a resolved AST node.
type ParseLocationRecordType int

const (
	// Parse locations are not recorded.
	ParseLocationRecordNone ParseLocationRecordType = 0

	// Parse locations cover the entire range of the related node, e.g., the full
	// function call text associated with a FunctionCallNode, or the full
	// expression text associated with a CastNode.
	ParseLocationRecordFullNodeScope ParseLocationRecordType = 1

	// Parse locations of nodes cover a related object name in the text, as
	// convenient for code search, e.g., just the function name associated with a
	// FunctionCallNode, or the target Type text associated with a CastNode.
	ParseLocationRecordCodeSearch ParseLocationRecordType = 2
)

// LanguageFeature the list of optional features that engines may or may not support.
// Features can be opted into in AnalyzerOptions.
//
// There are three types of LanguageFeatures.
// * Cross-version - Optional features that can be enabled orthogonally to
//                   versioning.  Some engines will never implement these
//                   features, and zetasql code will always support this
//                   switch.
// * Versioned - Features that describe behavior changes adopted as of some
//               language version.  Eventually, all engines should support these
//               features, and switches in the zetasql code (and tests)
//               should eventually be removed.
//               All of these, and only these, show up in VERSION_CURRENT.
// * Experimental - Features not currently part of any language version.
//
// All optional features are off by default.  Some features have a negative
// meaning, so turning them on will remove a feature or enable an error.
type LanguageFeature int

const (
	// CROSS-VERSION FEATURES
	//
	// These are features that can be opted into independently from versioning.
	// Some features may disable operations that are normally allowed by default.
	//
	// These features should not change semantics, other than whether a feature
	// is allowed or not.  Versioned options may further the behavior of these
	// features, if they are enabled.  For example, an engine may choose to
	// support DML, orthogonally to versioning.  If it supports DML, and
	// specified semantics for DML may change over time, and the engine may use
	// versioned options to choose DML behavior as of v1.0 or v1.1.

	// Enable analytic functions.
	FeatureAnalyticFunctions LanguageFeature = 1

	// Enable the TABLESAMPLE clause on scans.
	FeatureTablesample LanguageFeature = 2

	// If enabled, give an error on GROUP BY, DISTINCT or set operations (other
	// than UNION ALL) on floating point types. This feature is disabled in the
	// idealized ZetaSQL (i.e. LanguageOptions::EnableMaximumLanguageFeatures)
	// because enabling it turns off support for a feature that is normally on by default.
	FeatureDisallowGroupByFloat LanguageFeature = 3

	// If enabled, treats TIMESTAMP literal as 9 digits (nanos) precision.
	// Otherwise TIMESTAMP has 6 digits (micros) precision.
	// In general, a TIMESTAMP value has only 6 digits precision. This feature
	// will only affect how a timestamp literal string is interpreted into a
	// TIMESTAMP value. If enabled, a timestamp literal string can have up to 9
	// digits of subseconds(nanos). Otherwise, it can only have up to 6 digits of
	// subseconds (micros). 9 digits subsecond literal is not a valid timestamp
	// string in the later case.
	FeatureTimestampNanos LanguageFeature = 5

	// Enable support for JOINs in UPDATE statements.
	FeatureDMLUpdateWithJoin LanguageFeature = 6

	// Enable table-valued functions.
	FeatureTableValuedFunctions LanguageFeature = 8

	// This enables support for CREATE AGGREGATE FUNCTION.
	FeatureCreateAggregateFunction LanguageFeature = 9

	// This enables support for CREATE TABLE FUNCTION.
	FeatureCreateTableFunction LanguageFeature = 10

	// This enables support for GROUP BY ROLLUP.
	FeatureGroupByRollup LanguageFeature = 12

	// This enables support for creating and calling functions with templated
	// argument types, using CREATE FUNCTION, CREATE AGGREGATE FUNCTION, or CREATE
	// TABLE FUNCTION statements. For example, a function argument may be written
	// as "argument ANY TYPE" to match against any scalar value.
	FeatureTemplateFunctions LanguageFeature = 13

	// Enables support for PARTITION BY with CREATE TABLE and CREATE TABLE AS.
	FeatureCreateTablePartitionBy LanguageFeature = 14

	// Enables support for CLUSTER BY with CREATE TABLE and CREATE TABLE AS.
	FeatureCreateTableClusterBy LanguageFeature = 15

	// NUMERIC type support.
	FeatureNumericType LanguageFeature = 16

	// Enables support for NOT NULL annotation in CREATE TABLE.
	// See comment on FEATURE_CREATE_TABLE_FIELD_ANNOTATIONS
	FeatureCreateTableNotNull LanguageFeature = 17

	// Enables support for annotations (e.g., NOT NULL and OPTIONS()) for struct
	// fields and array elements in CREATE TABLE.
	// Does not affect table options or table column annotations.
	//
	// Example: Among the following queries
	// Q1: CREATE TABLE t (c STRUCT<a INT64> NOT NULL)
	// Q2: CREATE TABLE t (c STRUCT<a INT64 NOT NULL>)
	// Q3: CREATE TABLE t (c STRUCT<a INT64> OPTIONS(foo=1))
	// Q4: CREATE TABLE t (c STRUCT<a INT64 OPTIONS(foo=1)>)
	// Q5: CREATE TABLE t (c STRUCT<a INT64 NOT NULL OPTIONS(foo=1)>)
	//
	// Allowed queries                  FEATURE_CREATE_TABLE_FIELD_ANNOTATIONS
	//                                         =0               =1
	// FEATURE_CREATE_TABLE_NOT_NULL=0        {Q3}           {Q3, Q4}
	// FEATURE_CREATE_TABLE_NOT_NULL=1      {Q1, Q3}    {Q1, Q2, Q3, Q4, Q5}
	FeatureCreateTableFieldAnnotations LanguageFeature = 18

	// Enables support for column definition list in CREATE TABLE AS SELECT.
	// Example: CREATE TABLE t (x FLOAT64) AS SELECT 1 x
	// The features in the column definition list are controlled by
	// FEATURE_CREATE_TABLE_NOT_NULL and FEATURE_CREATE_TABLE_FIELD_ANNOTATIONS.
	FeatureCreateTableAsSelectColumnList LanguageFeature = 19

	// Indicates that an engine that supports primary keys does not allow any
	// primary key column to be NULL. Similarly, non-NULL primary key columns
	// cannot have any NULL array elements or struct/proto fields anywhere inside
	// them.
	//
	// Only interpreted by the compliance tests and the reference implementation
	// (not the analyzer). It exists so that engines can disable tests for this
	// atypical behavior without impacting their compliance ratios. It can never
	// be totally enforced in the analyzer because the analyzer cannot evaluate
	// expressions.
	//
	// TODO: When this feature is enabled, the reference implementation
	// forbids NULL primary key columns, but it allows NULL array elements and
	// NULL struct/proto fields. Change this behavior if we ever want to write
	// compliance tests for these cases.
	FeatureDisallowNullPrimaryKeys LanguageFeature = 20

	// Indicates that an engine that supports primary keys does not allow any
	// primary key column to be modified with UPDATE.
	//
	// Only interpreted by the compliance tests and the reference implementation
	// (not the analyzer) for now. It exists so that engines can disable tests for
	// this atypical behavior without impacting their compliance ratios.
	//
	// TODO: Consider exposing information about primary keys to the
	// analyzer and enforcing this feature there.
	FeatureDisallowPrimaryKeyUpdates LanguageFeature = 21

	// Enables support for the TABLESAMPLE clause applied to table-valued function
	// calls. For more information about table-valued functions.
	FeatureTablesampleFromTableValuedFunctions LanguageFeature = 22

	// Enable encryption- and decryption-related functions.
	FeatureEncryption LanguageFeature = 23

	// Differentially private anonymization functions, syntax, and semantics.
	FeatureAnonymization LanguageFeature = 24

	// Geography type support.
	FeatureGeography LanguageFeature = 25

	// Enables support for stratified TABLESAMPLE.
	// For more information about stratified sampling.
	FeatureStratifiedReservoirTablesample LanguageFeature = 26

	// Enables foreign keys.
	FeatureForeignKeys LanguageFeature = 27

	// Enables BETWEEN function signatures for UINT64/INT64 comparisons.
	FeatureBetweenUint64Int64 LanguageFeature = 28

	// Enables check constraint.
	FeatureCheckConstraint LanguageFeature = 29

	// Enables statement parameters and system variables in the GRANTEE list of
	// GRANT, REVOKE, CREATE ROW POLICY, and ALTER ROW POLICY statements.
	// TODO: The behavior of this feature is intended to become
	// mandatory.  This is a temporary feature, that preserves existing
	// behavior prior to engine migrations.  Once all engines have migrated,
	// this feature will be deprecated/removed and the new behavior will be mandatory.
	FeatureParametersInGranteeList LanguageFeature = 30

	// Enables support for named arguments in function calls using a syntax like
	// this: 'SELECT function(argname => 'value', otherarg => 42)'. Function
	// arguments with associated names in the signature options may specify values
	// by providing the argument name followed by an equals sign and greater than
	// sign (=>) followed by a value for the argument. Function calls may include
	// a mix of positional arguments and named arguments. The resolver will
	// compare provided arguments against function signatures and handle signature
	// matching appropriately.
	FeatureNamedArguments LanguageFeature = 31

	// Enables support for the old syntax for the DDL for ROW ACCESS POLICY,
	// previously called ROW POLICY.
	//
	// When this feature is enabled, either the legacy or new syntax can be used
	// for CREATE/DROP ROW [ACCESS] POLICY.  Note, however, that when using the
	// new syntax the GRANT TO clause is required (the GRANT TO clause is optional
	// when the feature is off).
	//
	// When it is not enabled, the new syntax must be used for CREATE ROW ACCESS
	// POLICY and DROP ALL ROW ACCESS POLICIES. The new syntax is always required
	// for ALTER ROW ACCESS POLICY and DROP ROW ACCESS POLICY: at the time of this
	// writing, these statements are new/not in use.
	//
	// This is a temporary feature that preserves legacy engine behavior that will
	// be deprecated, and the new syntax will become mandatory (b/135116351). For
	// more details on syntax changes.
	FeatureAllowLegacyRowAccessPolicySyntax LanguageFeature = 32

	// Enables support for PARTITION BY with CREATE MATERIALIZED VIEW.
	FeatureCreateMaterializedViewPartitionBy LanguageFeature = 33

	// Enables support for CLUSTER BY with CREATE MATERIALIZED VIEW.
	FeatureCreateMaterializedViewClusterBy LanguageFeature = 34

	// Enables support for column definition list in CREATE EXTERNAL TABLE.
	// Example: CREATE EXTERNAL TABLE t (x FLOAT64)
	FeatureCreateExternalTableWithTableElementList LanguageFeature = 35

	// Enables using NOT ENFORCED in primary keys.
	FeatureUnenforcedPrimaryKeys LanguageFeature = 40

	// BIGNUMERIC data type.
	FeatureBignumericType LanguageFeature = 41

	// Extended types (TYPE_EXTENDED).
	FeatureExtendedTypes LanguageFeature = 42

	// JSON data type.
	FeatureJsonType LanguageFeature = 43

	// If true, JSON values are not parsed and validated.
	FeatureJsonNoValidation LanguageFeature = 44

	// If true, JSON string documents will be parsed using the proto JSON parse
	// rules that are more relaxed than the JSON RFC (for example allowing single
	// quotes in the documents).
	FeatureJsonLegacyParse LanguageFeature = 46

	// Enables support for WITH PARTITION COLUMNS in CREATE EXTERNAL TABLE.
	// Example:
	// CREATE EXTERNAL TABLE t WITH PARTITION COLUMNS (x int64)
	FeatureCreateExternalTableWithPartitionColumns LanguageFeature = 47

	// INTERVAL data type.
	FeatureIntervalType LanguageFeature = 49

	// If enabled, JSON parsing fails for JSON documents containing number values
	// that cannot fit into the range of numbers supported by uint64, int64 or
	// double.
	// For unsigned integers, the valid range is [0, 2^64-1]
	// For signed integers, the valid range is [-2^63, 2^63-1].
	// For floating point values, the valid range contains all numbers that can
	// round-trip from string -> double -> string. The round-tripped string
	// doesn't need to match the input string exactly, but must hold the same
	// number value (i.e. "1e+3" -> double -> "1000" is a valid round-trip).
	// If precision loss occurs as a result of the round-trip, the number is not
	// considered valid (i.e. 0.142857142857142857142857142857142857 -> double ->
	// 14285714285714285 is not valid).
	// NOTE: FEATURE_JSON_LEGACY_PARSE does not work with
	// FEATURE_JSON_STRICT_NUMBER_PARSING
	FeatureJsonStrictNumberParsing LanguageFeature = 52

	// When enabled, (table) function argument names will hide column names in
	// expression resolution and relational table function argument names will
	// hide table names from the catalog. This changes name resolution and is
	// a backward compatibility breaking change.
	//
	// Related bugs: b/118904900 (scalar arguments) b/165763119 (table arguments)
	FeatureFunctionArgumentNamesHideLocalNames LanguageFeature = 55

	// Enables support for the following parameterized types.
	// - STRING(L) / BYTES(L)
	// - NUMERIC(P) / NUMERIC(P, S)
	// - BIGNUMERIC(P) / BIGNUMERIC(P, S)
	FeatureParameterizedTypes LanguageFeature = 56

	// Enables support for CREATE TABLE LIKE
	// Example:
	// CREATE TABLE t1 LIKE t2
	FeatureCreateTableLike LanguageFeature = 57

	// Enable support for JSON_EXTRACT_STRING_ARRAY, JSON_VALUE_ARRAY and
	// JSON_QUERY_ARRAY.
	FeatureJsonArrayFunctions LanguageFeature = 58

	// Enables explicit column list for CREATE VIEW.
	// Example:
	// CREATE VIEW v(a, b) AS SELECT ...
	FeatureCreateViewWithColumnList LanguageFeature = 59

	// Enables support for CREATE TABLE CLONE
	// Example:
	// CREATE TABLE t1 CLONE t2
	FeatureCreateTableClone LanguageFeature = 60

	// Enables support for CLONE DATA INTO
	// Example: CLONE DATA INTO ds.tbl;
	FeatureCloneData LanguageFeature = 61

	// Enables support for ALTER COLUMN SET DATA TYPE.
	FeatureAlterColumnSetDataType LanguageFeature = 62

	// Enables support for CREATE SNAPSHOT TABLE.
	FeatureCreateSnapshotTable LanguageFeature = 63

	// Enables support for defining argument defaults in function calls using
	// syntax like:
	//   CREATE FUNCTION foo (a INT64 DEFAULT 5) AS (a);
	// In effect, the argument with a default becomes optional when the function
	// is called, like:
	//   SELECT foo();
	FeatureFunctionArgumentsWithDefaults LanguageFeature = 64

	// Enables support for WITH CONNECTION in CREATE EXTERNAL TABLE.
	// Example:
	// CREATE EXTERNAL TABLE t WITH CONNECTION `project.region.connection_1`
	FeatureCreateExternalTableWithConnection LanguageFeature = 65

	// Enables support for CREATE TABLE COPY
	// Example:
	// CREATE TABLE t1 COPY t2
	FeatureCreateTableCopy LanguageFeature = 66

	// Enables support for ALTER TABLE RENAME COLUMN.
	FeatureAlterTableRenameColumn LanguageFeature = 67

	// Enables STRING(JSON), INT64(JSON), BOOL(JSON), DOUBLE(JSON),
	// JSON_TYPE(JSON) functions.
	FeatureJsonValueExtractionFunctions LanguageFeature = 68

	// Disallows "unicode", "unicode:ci", "unicode:cs" in ORDER BY ... COLLATE and
	// other collation features. "unicode" is a legacy feature, and the desired
	// behavior is to allow only "binary" and valid icu language tags.
	// Enabling this feature must produce an error if 'unicode' is specified as
	// a collation name.
	FeatureDisallowLegacyUnicodeCollation LanguageFeature = 69

	FeatureAllowMissingPathExpressionInAlterDDL LanguageFeature = 70

	// VERSIONED FEATURES
	// These are features or changes as of some version.
	// Each should start with a prefix FEATURE_V_x_y_.  The feature will be
	// included in the default set enabled for LanguageVersion VERSION_x_y.
	//
	// Features that will remain optional for compliance, and are not expected to
	// be implemented in all engines, should be added as cross-version features
	// (above) instead.
	//
	// Some versioned features may have dependencies and only make sense if
	// other features are also enabled.  Dependencies should be commented here.

	// Enable ORDER BY COLLATE.
	FeatureV11OrderByCollate LanguageFeature = 11001

	// Enable WITH clause on subqueries.  Without this, WITH is allowed
	// only at the top level.  The WITH subqueries still cannot be
	// correlated subqueries.
	FeatureV11WithOnSubquery LanguageFeature = 11002

	// Enable the SELECT * EXCEPT and SELECT * REPLACE features.
	FeatureV11SelectStarExceptReplace LanguageFeature = 11003

	// Enable the ORDER BY in aggregate functions.
	FeatureV11OrderByInAggregate LanguageFeature = 11004

	// Enable casting between different array types.
	FeatureV11CastDifferentArrayTypes LanguageFeature = 11005

	// Enable comparing array equality.
	FeatureV11ArrayEquality LanguageFeature = 11006

	// Enable LIMIT in aggregate functions.
	FeatureV11LimitInAggregate LanguageFeature = 11007

	// Enable HAVING modifier in aggregate functions.
	FeatureV11HavingInAggregate LanguageFeature = 11008

	// Enable IGNORE/RESPECT NULLS modifier in analytic functions.
	FeatureV11NullHandlingModifierInAnalytic LanguageFeature = 11009

	// Enable IGNORE/RESPECT NULLS modifier in aggregate functions.
	FeatureV11NullHandlingModifierInAggregate LanguageFeature = 11010

	// Enable FOR SYSTEM_TIME AS OF (time travel).
	FeatureV11ForSystemTimeAsOf LanguageFeature = 11011

	// Enable TIME and DATETIME types and related functions.
	FeatureV12CivilTime LanguageFeature = 12001

	// Enable SAFE mode function calls.  e.g. SAFE.FUNC(...) for FUNC(...).
	FeatureV12SafeFunctionCall LanguageFeature = 12002

	// Enable support for GROUP BY STRUCT.
	FeatureV12GroupByStruct LanguageFeature = 12003

	// Enable use of proto extensions with NEW.
	FeatureV12ProtoExtensionsWithNew LanguageFeature = 12004

	// Enable support for GROUP BY ARRAY.
	FeatureV12GroupByArray LanguageFeature = 12005

	// Enable use of proto extensions with UPDATE ... SET.
	FeatureV12ProtoExtensionsWithSet LanguageFeature = 12006

	// Allows nested DML statements to refer to names defined in the parent
	// scopes. Without this, a nested DML statement can only refer to names
	// created in the local statement - i.e. the array element.
	// Examples that are allowed only with this option:
	//   UPDATE Table t SET (UPDATE t.ArrayColumn elem SET elem = t.OtherColumn)
	//   UPDATE Table t SET (DELETE t.ArrayColumn elem WHERE elem = t.OtherColumn)
	//   UPDATE Table t SET (INSERT t.ArrayColumn VALUES (t.OtherColumn))
	//   UPDATE Table t SET (INSERT t.ArrayColumn SELECT t.OtherColumn)
	FeatureV12CorrelatedRefsInNestedDML LanguageFeature = 12007

	// Enable use of WEEK(<Weekday>) with the functions that support it.
	FeatureV12WeekWithWeekday LanguageFeature = 12008

	// Enable use of array element [] syntax in targets with UPDATE ... SET.
	// For example, allow UPDATE T SET a.b[OFFSET(0)].c = 5.
	FeatureV12ArrayElementsWithSet LanguageFeature = 12009

	// Enable nested updates/deletes of the form
	// UPDATE/DELETE ... WITH OFFSET AS ... .
	FeatureV12NestedUpdateDeleteWithOffset LanguageFeature = 12010

	// Enable Generated Columns on CREATE and ALTER TABLE statements.
	FeatureV12GeneratedColumns LanguageFeature = 12011

	// Enables support for the PROTO_DEFAULT_IF_NULL() function.
	FeatureV13ProtoDefaultIfNull LanguageFeature = 13001

	// Enables support for proto field pseudo-accessors in the EXTRACT function.
	// For example, EXTRACT(FIELD(x) from foo) will extract the value of the field
	// x defined in message foo. EXTRACT(HAS(x) from foo) will return a boolean
	// denoting if x is set in foo or NULL if foo is NULL. EXTRACT(RAW(x) from
	// foo) will get the value of x on the wire (i.e., without applying any
	// FieldFormat.Format annotations or automatic conversions). If the field is
	// missing, the default is always returned, which is NULL for message fields
	// and the field default (either the explicit default or the default default)
	// for primitive fields. If the containing message is NULL, NULL is returned.
	FeatureV13ExtractFromProto LanguageFeature = 13002

	// If enabled, the analyzer will return an error when attempting to check
	// if a proto3 scalar field has been explicitly set (e.g.,
	// proto3.has_scalar_field and EXTRACT(HAS(scalar_field) from proto3)).
	// This feature is deprecated and should not be used, since proto3 now
	// supports scalar field presence testing. Eventually we will remove this
	// feature and the underlying code.
	FeatureDeprecatedDisallowProto3HasScalarField LanguageFeature = 13003

	// Enable array ordering (and non-equality comparisons).  This enables
	// arrays in the ORDER BY of a query, as well as in aggregate and analytic
	// function arguments.  Also enables inequality comparisons between arrays
	// (<, <=, >, >=).  This flag enables arrays for MIN/MAX,
	// although semantics over array inputs are surprising sometimes.
	//
	// Note: there is a separate flag for GREATEST/LEAST, as not all engines are
	//       ready to implement them for arrays.
	FeatureV13ArrayOrdering LanguageFeature = 13004

	// Allow omitting column and value lists in INSERT statement and INSERT clause
	// of MERGE statement.
	FeatureV13OmitInsertColumnList LanguageFeature = 13005

	// If enabled, the 'use_defaults' and 'use_field_defaults' annotations are
	// ignored for proto3 scalar fields. This results in the default value always
	// being returned for proto3 scalar fields that are not explicitly set,
	// including when they are annotated with 'use_defaults=false' or their parent
	// message is annotated with 'use_field_defaults=false'. This aligns with
	// proto3 semantics as proto3 does not expose whether scalar fields are set or
	// not.
	FeatureV13IgnoreProto3UseDefaults LanguageFeature = 13006

	// Enables support for the REPLACE_FIELDS() function. REPLACE_FIELDS(p,
	// <value> AS <field_path>) returns the proto obtained by setting p.field_path
	// = value. If value is NULL, this unsets field_path or returns an error if
	// the last component of field_path is a required field. Multiple fields can
	// be modified: REPLACE_FIELDS(p, <value_1> AS <field_path_1>, ..., <value_n>
	// AS <field_path_n>). REPLACE_FIELDS() can also be used to modify structs
	// using the similar syntax: REPLACE_FIELDS(s, <value> AS
	// <struct_field_path>).
	FeatureV13ReplaceFields LanguageFeature = 13007

	// Enable NULLS FIRST/NULLS LAST in ORDER BY expressions.
	FeatureV13NullsFirstLastInOrderBy LanguageFeature = 13008

	// Allows dashes in the first part of multi-part table name. This is to
	// accommodate GCP project names which use dashes instead of underscores, e.g.
	// crafty-tractor-287. So fully qualified table name which includes project
	// name normally has to be quoted in the query, i.e. SELECT * FROM
	// `crafty-tractor-287`.dataset.table This feature allows it to be used
	// unquoted, i.e. SELECT * FROM crafty-tractor-287.dataset.table
	FeatureV13AllowDashesInTableName LanguageFeature = 13009

	// CONCAT allows arguments of different types, automatically coerced to
	// STRING for FN_CONCAT_STRING signature. Only types which have CAST to
	// STRING defined are allowed, and BYTES is explicitly excluded (since BYTES
	// should match FN_CONCAT_BYTES signature).
	FeatureV13ConcatMixedTypes LanguageFeature = 13010

	// Enable WITH RECURSIVE
	FeatureV13WithRecursive LanguageFeature = 13011

	// Support maps in protocol buffers.
	FeatureV13ProtoMaps LanguageFeature = 13012

	// Enables support for the ENUM_VALUE_DESCRIPTOR_PROTO() function.
	FeatureV13EnumValueDescriptorProto LanguageFeature = 13013

	// Allows DECIMAL as an alias of NUMERIC type, and BIGDECIMAL as an alias
	// of BIGNUMERIC type. By itself, this feature does not enable NUMERIC type
	// or BIGNUMERIC, which are controlled by FEATURE_NUMERIC_TYPE and
	// FEATURE_BIGNUMERIC_TYPE.
	FeatureV13DecimalAlias LanguageFeature = 13014

	// Support UNNEST and FLATTEN on paths through arrays.
	FeatureV13UnnestAndFlattenArrays LanguageFeature = 13015

	// Allows consecutive ON/USING clauses for JOINs, such as
	//    t1 JOIN t2 JOIN t3 ON cond1 USING (col2)
	FeatureV13AllowConsecutiveOn LanguageFeature = 13016

	// Enables support for optional parameters position and occurrence in
	// REGEXP_EXTRACT. In addition, allows alias REGEXP_SUBSTR.
	FeatureV13AllowRegexpExtractOptionals LanguageFeature = 13017

	// Additional signatures for DATE, TIMESTAMP, TIME, DATETIME and STRING
	// constructor functions.
	FeatureV13DateTimeConstructors LanguageFeature = 13018

	// Enables DATE +/- INT64 arithmetics.
	FeatureV13DateArithmetics LanguageFeature = 13019

	// Enable support for additional string functions.
	FeatureV13AdditionalStringFunctions LanguageFeature = 13020

	// Enable support for aggregate functions with WITH GROUP_ROWS syntax.
	FeatureV13WithGroupRows LanguageFeature = 13021

	// Additional signatures for [DATE|DATETIME|TIMESTAMP]_[ADD|SUB|DIFF|TRUNC]
	// functions.
	FeatureV13ExtendedDateTimeSignatures LanguageFeature = 13022

	// Additional signatures for ST_GeogFromText/FromGeoJson/From* functions.
	FeatureV13ExtendedGeographyParsers LanguageFeature = 13023

	// Inline lambda function argument.
	FeatureV13InlineLambdaArgument LanguageFeature = 13024

	// PIVOT clause.
	FeatureV13Pivot LanguageFeature = 13025

	// This flag enables propagation of annotation during query analysis. See
	// public/types/annotation.h for the introduction of annotation framework.
	// Engines must turn on this flag before turning on any built-in annotation
	// feature or passing in engine defined AnnotationSpec.
	FeatureV13AnnotationFramework LanguageFeature = 13026

	// Enables collation annotation support.
	FeatureV13CollationSupport LanguageFeature = 13027

	// IS [NOT] DISTINCT FROM.
	FeatureV13IsDistinct LanguageFeature = 13028

	// If true, FORMAT clause is supported in CAST().
	// Fully implemented:
	//   BYTES <=> STRING
	//   DATE/DATETIME/TIME/TIMESTAMP => STRING
	//
	// Under development:
	//   STRING => DATE/DATETIME/TIME/TIMESTAMP
	//   NUMBER => STRING
	FeatureV13FormatInCast LanguageFeature = 13029

	// UNPIVOT clause.
	FeatureV13Unpivot LanguageFeature = 13030

	// If true, dml returning is supported.
	FeatureV13DMLReturning LanguageFeature = 13031

	// Enables support for the FILTER_FIELDS() function.
	//    FILTER_FIELDS(p, <-|+><field_path>, ...)
	// returns the proto obtained by keeping p.field_path whose
	// sign is '+' and remove p.field_path whose sign is '-'.
	FeatureV13FilterFields LanguageFeature = 13032

	// QUALIFY clause.
	FeatureV13Qualify LanguageFeature = 13033

	// Enable support for REPEAT...UNTIL...END REPEAT statement.
	FeatureV13Repeat LanguageFeature = 13034

	// Enables column DEFAULT clause in CREATE and ALTER TABLE statements.
	FeatureV13ColumnDefaultValue LanguageFeature = 13035

	// Enable support for FOR...IN...DO...END FOR statement.
	FeatureV13ForIn LanguageFeature = 13036

	// Enables support for initializing KLLs with weights as an additional
	// parameter. Support for this feature in addition to the weighting
	// functionality also requires support for named arguments as the weight
	// argument must be named.
	FeatureKllWights LanguageFeature = 13037

	// LIKE ANY/SOME/ALL support.
	FeatureV13LikeAnySomeAll LanguageFeature = 13038

	// Enable support for CASE...WHEN...THEN...END CASE statement.
	FeatureV13CaseStmt LanguageFeature = 13039

	// Support for table names that start with slash and contain slashes, dashes,
	// and colons before the first dot: /span/test/my-grp:db.Table.
	FeatureV13AllowSlashPaths LanguageFeature = 13040

	// Enable the TYPEOF(expr) debugging and exploration function.
	FeatureV13TypeofFunction LanguageFeature = 13041

	// Enable support for SCRIPT LABELS (e.g. L1: BEGIN...END).
	FeatureV13ScriptLabel LanguageFeature = 13042

	// Enable support for remote function (e.g. CREATE FUNCTION ... REMOTE ...).
	FeatureV13RemoteFunction LanguageFeature = 13043

	// If Array ordering is enabled, this flag enables arrays for GREATEST/LEAST.
	FeatureV13ArrayGreatestLeast LanguageFeature = 13044

	// EXPERIMENTAL FEATURES
	// These are features supported in the code that are not currently part of
	// officially supported ZetaSQL as of any version.

	// Enable ZetaSQL MODULES.  For an engine to fully opt into this feature,
	// they must enable this feature flag and add support for the related
	// StatementKinds: ImportStmtNode and ModuleStmtNode.
	FeatureExperimentalModules LanguageFeature = 999002

	// These are not real features. They are just for unit testing the handling of
	// various LanguageFeatureOptions.
	FeatureTestIdeallyEnabledButInDevelopment LanguageFeature = 999991

	FeatureTestIdeallyDisabled LanguageFeature = 999992

	FeatureTestIdeallyDisabledAndInDevelopment LanguageFeature = 999993
)

// LanguageVersion ZetaSQL language versions.
//
// A language version defines a stable set of features and required semantics.
// LanguageVersion VersionXY implicitly includes the LanguageFeatures below
// named FeatureVXY*.
//
// The features and behavior supported by an engine can be expressed as a
// LanguageVersion plus a set of LanguageFeatures added on top of that version.
//
// New version numbers will be introduced periodically, and will normally
// include the new features that have been specified up to that point.
// Engines should move their version number forwards over time rather than
// accumulating large sets of LanguageFeatures.
type LanguageVersion int

const (
	VersionCurrent LanguageVersion = 1

	// Version 1.0, frozen January 2015.
	Version10 LanguageVersion = 10000

	// Version 1.1, frozen February 2017.
	Version11 LanguageVersion = 11000

	// Version 1.2, frozen January 2018.
	Version12 LanguageVersion = 12000

	// Version 1.3.  New features are being added here.
	Version13 LanguageVersion = 13000
)

// This can be used to select strict name resolution mode.
//
// In strict mode, implicit column names cannot be used unqualified.
// This ensures that existing queries will not be broken if additional
// elements are added to the schema in the future.
//
// For example,
//   SELECT c1, c2 FROM table1, table2;
// is not legal in strict mode because another column could be added to one of
// these tables, making the query ambiguous.  The query must be written
// with aliases in strict mode:
//   SELECT t1.c1, t2.c2 FROM table1 t1, table t2;
//
// SELECT * is also not allowed in strict mode because the number of output
// columns may change.
type NameResolutionMode int

const (
	NameResolutionDefault NameResolutionMode = 0
	NameResolutionStrict  NameResolutionMode = 1
)
