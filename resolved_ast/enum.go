package resolved_ast

type ErrorMode int

const (
	DefaultErrorMode ErrorMode = 0
	SafeErrorMode    ErrorMode = 1
)

type NullHandlingModifier int

const (
	DefaultNullHandling NullHandlingModifier = 0
	IgnoreNulls         NullHandlingModifier = 1
	RespectNulls        NullHandlingModifier = 2
)

type FieldFormat int

const (
	DefaultFormat            FieldFormat = 0
	DateFormat               FieldFormat = 1
	TimestampSecondsFormat   FieldFormat = 2
	TimestampMillisFormat    FieldFormat = 3
	TimestampMicrosFormat    FieldFormat = 4
	TimestampNanosFormat     FieldFormat = 5
	DateDecimalFormat        FieldFormat = 6
	TimeMicros               FieldFormat = 7
	DatetimeMicrosFormat     FieldFormat = 8
	StGeographyEncodedFormat FieldFormat = 9
	NumericFormat            FieldFormat = 10
	BigNumericFormat         FieldFormat = 11
	JsonFormat               FieldFormat = 12
	IntervalFormat           FieldFormat = 14
)

type SubqueryType int

const (
	SubqueryTypeScalar  SubqueryType = 0
	SubqueryTypeArray   SubqueryType = 1
	SubqueryTypeExists  SubqueryType = 2
	SubqueryTypeIn      SubqueryType = 3
	SubqueryTypeLikeAny SubqueryType = 4
	SubqueryTypeLikeAll SubqueryType = 5
)

type JoinType int

const (
	JoinTypeInner JoinType = 0
	JoinTypeLeft  JoinType = 1
	JoinTypeRight JoinType = 2
	JoinTypeFull  JoinType = 3
)

type SetOperationType int

const (
	SetOperationTypeUnionAll          SetOperationType = 0
	SetOperationTypeUnionDistinct     SetOperationType = 1
	SetOperationTypeIntersectAll      SetOperationType = 2
	SetOperationTypeIntersectDistinct SetOperationType = 3
	SetOperationTypeExceptAll         SetOperationType = 4
	SetOperationTypeExceptDistinct    SetOperationType = 5
)

type SampleUnit int

const (
	SampleUnitRows    SampleUnit = 0
	SampleUnitPercent SampleUnit = 1
)

type FrameUnit int

const (
	FrameUnitRows  FrameUnit = 0
	FrameUnitRange FrameUnit = 1
)

type NullOrderMode int

const (
	NullOrderModeOrderUnspecified NullOrderMode = 0
	NullOrderModeNullsFirst       NullOrderMode = 1
	NullOrderModeNullsLast        NullOrderMode = 2
)

type StoredMode int

const (
	StoredModeNonStored      StoredMode = 0
	StoredModeStored         StoredMode = 1
	StoredModeStoredVolatile StoredMode = 2
)

type MatchMode int

const (
	MatchModeSimple      MatchMode = 0
	MatchModeFull        MatchMode = 1
	MatchModeNotDistinct MatchMode = 2
)

type ActionOperation int

const (
	ActionOperationNoAction ActionOperation = 0
	ActionOperationRestrict ActionOperation = 1
	ActionOperationCascade  ActionOperation = 2
	ActionOperationSetNull  ActionOperation = 3
)

type CreateScope int

const (
	CreateScopeDefault CreateScope = 0
	CreateScopePrivate CreateScope = 1
	CreateScopePublic  CreateScope = 2
	CreateScopeTemp    CreateScope = 3
)

type CreateMode int

const (
	CreateDefaultMode     CreateMode = 0
	CreateOrReplaceMode   CreateMode = 1
	CreateIfNotExistsMode CreateMode = 2
)

type SQLSecurity int

const (
	SQLSecurityUnspecified SQLSecurity = 0
	SQLSecurityDefiner     SQLSecurity = 1
	SQLSecurityInvoker     SQLSecurity = 2
)

type ReadWriteMode int

const (
	ReadWriteModeUnspecified ReadWriteMode = 0
	ReadWriteModeReadOnly    ReadWriteMode = 1
	ReadWriteModeReadWrite   ReadWriteMode = 2
)

type DropMode int

const (
	DropModeUnspecified DropMode = 0
	DropModeRestrict    DropMode = 1
	DropModeCascade     DropMode = 2
)

type RecursiveSetOperationType int

const (
	RecursiveSetOperationTypeUnionAll      RecursiveSetOperationType = 0
	RecursiveSetOperationTypeUnionDistinct RecursiveSetOperationType = 1
)

type BoundaryType int

const (
	UnboundedPrecedingType BoundaryType = 0
	OffsetPrecedingType    BoundaryType = 1
	CurrentRowType         BoundaryType = 2
	OffsetFollowingType    BoundaryType = 3
	UnboundedFollowingType BoundaryType = 4
)

type ObjectAccess int

const (
	ObjectAccessNone      ObjectAccess = 0
	ObjectAccessRead      ObjectAccess = 1
	ObjectAccessWrite     ObjectAccess = 2
	ObjectAccessReadWrite ObjectAccess = 3
)

type MatchType int

const (
	MatchTypeMatched            MatchType = 0
	MatchTypeNotMatchedBySource MatchType = 1
	MatchTypeNotMatchedByTarget MatchType = 2
)

type ActionType int

const (
	ActionTypeInsert ActionType = 0
	ActionTypeUpdate ActionType = 1
	ActionTypeDelete ActionType = 2
)

type ArgumentKind int

const (
	ArgumentKindScalar       ArgumentKind = 0
	ArgumentKindAggregate    ArgumentKind = 1
	ArgumentKindNotAggregate ArgumentKind = 2
)

type ImportKind int

const (
	ImportKindModule ImportKind = 0
	ImportKindProto  ImportKind = 1
)

type HavingModifierKind int

const (
	HavingModifierKindInvalid HavingModifierKind = 0
	HavingModifierKindMax     HavingModifierKind = 1
	HavingModifierKindMin     HavingModifierKind = 2
)

type InsertionMode int

const (
	InsertionModeNone      InsertionMode = 0
	InsertionModeAppend    InsertionMode = 1
	InsertionModeOverwrite InsertionMode = 2
)

type InsertMode int

const (
	InsertModeOrError   InsertMode = 0
	InsertModeOrIgnore  InsertMode = 1
	InsertModeOrReplace InsertMode = 2
	InsertModeOrUpdate  InsertMode = 3
)

type DeterminismLevel int

const (
	DeterminismUnspecified      DeterminismLevel = 0
	DeterminismDeterministic    DeterminismLevel = 1
	DeterminismNotDeterministic DeterminismLevel = 2
	DeterminismImmutable        DeterminismLevel = 3
	DeterminismStable           DeterminismLevel = 4
	DeterminismVolatile         DeterminismLevel = 5
)
