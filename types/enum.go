package types

type ArgumentCardinality int

const (
	RequiredArgumentCardinality ArgumentCardinality = 0
	RepeatedArgumentCardinality ArgumentCardinality = 1
	OptionalArgumentCardinality ArgumentCardinality = 2
)

type ArgumentCollationMode int

const (
	AffectsNone                    ArgumentCollationMode = 0
	AffectsOperation               ArgumentCollationMode = 1
	AffectsPropagation             ArgumentCollationMode = 2
	AffectsOperationAndPropagation ArgumentCollationMode = 3
)

type SignatureArgumentKind int

const (
	// ArgTypeFixed a specific concrete Type.
	ArgTypeFixed SignatureArgumentKind = 0

	// ArgTypeAny1 templated type.  All arguments with this type must be the same type.
	// For example,
	//   IF <bool> THEN <T1> ELSE <T1> END -> <T1>
	ArgTypeAny1 SignatureArgumentKind = 1

	// ArgTypeAny2 templated type.  All arguments with this type must be the same type.
	// For example,
	//   CASE <T1> WHEN <T1> THEN <T2>
	//             WHEN <T1> THEN <T2> ELSE <T2> END -> <T2>
	ArgTypeAny2 SignatureArgumentKind = 2

	// ArgArrayTypeAny1 templated array type.  All arguments with this type must be the same
	// type.  Additionally, all arguments with this type must be an array
	// whose element type matches arguments with ARG_TYPE_ANY_1 type.
	// For example,
	//   FIRST(<array<T1>>) -> <T1>
	ArgArrayTypeAny1 SignatureArgumentKind = 3

	// ArgArrayTypeAny2 templated array type.  All arguments with this type must be the same
	// type.  Additionally, all arguments with this type must be an array
	// whose element type matches arguments with ARG_TYPE_ANY_2 type.
	// For example,
	//   LAST(<array<T2>>) -> <T2>
	ArgArrayTypeAny2 SignatureArgumentKind = 4

	// ArgProtoAny templated proto type. All arguments with this type must be the same type.
	// e.g.:
	//   DEBUGSTRING(<proto>) -> <string>
	ArgProtoAny SignatureArgumentKind = 5

	// ArgStructAny templated struct type. All arguments with this type must be the same type.
	// e.g.:
	//   DEBUGSTRING(<struct>) -> <string>
	ArgStructAny SignatureArgumentKind = 6

	// ArgEnumAny templated enum type. All arguments with this type must be the same type.
	// e.g.:
	//   ENUM_NAME(<enum>, 5) -> <string>
	ArgEnumAny SignatureArgumentKind = 7

	// ArgTypeArbitrary arbitrary Type. Multiple arguments with this type do not need to be the
	// same type. This does not include relation arguments.
	ArgTypeArbitrary SignatureArgumentKind = 8

	// ArgTypeRelation relation type. This is only valid for table-valued functions (TVFs). This
	// specifies a relation of any number and types of columns. Multiple arguments
	// with this type do not necessarily represent the same relation.
	//
	// Background: each TVF may accept value or relation arguments. The signature
	// specifies whether each argument should be a value or a relation. For a
	// value argument, the signature may use one of the other
	// SignatureArgumentKinds in this list.
	//
	// For more information, please see table_valued_function.h.
	ArgTypeRelation SignatureArgumentKind = 9

	// ArgTypeVoid this is used for a non-existent return type for signatures that do not
	// return a value.  This can only be used as a return type, and only in
	// contexts where there is no return (e.g. Procedures, or signatures in DropFunctionStmtNode).
	ArgTypeVoid SignatureArgumentKind = 10

	// ArgTypeModel model type. This is only valid for table-valued functions (TVFs). This
	// specifies a model for ML-related TVFs.
	ArgTypeModel SignatureArgumentKind = 11

	// ArgTypeConnection connection type. This is only valid for table-valued functions (TVFs). This
	// specifies a connection for EXTERNAL_QUERY TVF.
	ArgTypeConnection SignatureArgumentKind = 12

	// ArgTypeDescriptor descriptor type. This is only valid for table-valued functions (TVFs). This
	// specifies a descriptor with a list of column names.
	ArgTypeDescriptor SignatureArgumentKind = 13

	// ArgProtoMapAny templated proto map type. This is an array of protos where the proto
	// is a map entry. It has a key field and a value field. This kind allows
	// inference of the key and value field types from the map field type, as
	// in this expression:
	//
	// ARG_PROTO_MAP_ANY[KEY(ARG_PROTO_MAP_KEY_ANY)] ->
	// ARG_PROTO_MAP_VALUE_ANY
	ArgProtoMapAny SignatureArgumentKind = 14

	// ArgProtoMapKeyAny the key type of a proto map that matches ARG_PROTO_MAP_ANY.
	ArgProtoMapKeyAny SignatureArgumentKind = 15

	// ArgProtoMapValueAny the value type of a proto map that matches ARG_PROTO_MAP_ANY.
	ArgProtoMapValueAny SignatureArgumentKind = 16

	// ArgTypeLambda lambda type. This is only valid for lambda function arguments. This
	// specifies a lambda with a list of argument types and a body type.
	ArgTypeLambda SignatureArgumentKind = 17
)

type ProcedureArgumentMode int

const (
	NotSetProcedureArgumentMode ProcedureArgumentMode = 0
	InProcedureArgumentMode     ProcedureArgumentMode = 1
	OutProcedureArgumentMode    ProcedureArgumentMode = 2
	InOutProcedureArgumentMode  ProcedureArgumentMode = 3
)

type Mode int

const (
	ScalarMode    Mode = 1
	AggregateMode Mode = 2
	AnalyticMode  Mode = 3
)
