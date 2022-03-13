package ast

type Kind int

const (
	Unknown Kind = -1 + iota
	Fake
	AbortBatchStatement
	AddColumnAction
	AddConstraintAction
	AddToRestricteeListClause
	FunctionCallWithGroupRows
	Alias
	AlterActionList
	AlterAllRowAccessPoliciesStatement
	AlterColumnOptionsAction
	AlterColumnDropNotNullAction
	AlterColumnTypeAction
	AlterColumnSetDefaultAction
	AlterColumnDropDefaultAction
	AlterConstraintEnforcementAction
	AlterConstraintSetOptionsAction
	AlterDatabaseStatement
	AlterEntityStatement
	AlterMaterializedViewStatement
	AlterPrivilegeRestrictionStatement
	AlterRowAccessPolicyStatement
	AlterSchemaStatement
	AlterTableStatement
	AlterViewStatement
	AnalyticFunctionCall
	AnalyzeStatement
	AndExpr
	AnySomeAllOp
	ArrayColumnSchema
	ArrayConstructor
	ArrayElement
	ArrayType
	AssertRowsModified
	AssertStatement
	AssignmentFromStruct
	BeginStatement
	BetweenExpression
	AuxLoadDataFromFilesOptionsList
	AuxLoadDataStatement
	BignumericLiteral
	BinaryExpression
	BitwiseShiftExpression
	BeginEndBlock
	BooleanLiteral
	BreakStatement
	BytesLiteral
	CallStatement
	CaseStatement
	CaseNoValueExpression
	CaseValueExpression
	CastExpression
	CheckConstraint
	ClampedBetweenModifier
	CloneDataSource
	CloneDataSourceList
	CloneDataStatement
	ClusterBy
	Collate
	ColumnAttributeList
	ColumnDefinition
	ColumnList
	ColumnPosition
	CommitStatement
	ConnectionClause
	ContinueStatement
	CopyDataSource
	CreateConstantStatement
	CreateDatabaseStatement
	CreateExternalTableStatement
	CreateFunctionStatement
	CreateIndexStatement
	CreateModelStatement
	CreateProcedureStatement
	CreatePrivilegeRestrictionStatement
	CreateRowAccessPolicyStatement
	CreateSchemaStatement
	CreateSnapshotTableStatement
	CreateTableFunctionStatement
	CreateTableStatement
	CreateEntityStatement
	CreateViewStatement
	CreateMaterializedViewStatement
	DateOrTimeLiteral
	DefaultLiteral
	DefineTableStatement
	DeleteStatement
	DescribeStatement
	DescriptorColumn
	DescriptorColumnList
	Descriptor
	DotGeneralizedField
	DotIdentifier
	DotStar
	DotStarWithModifiers
	DropAllRowAccessPoliciesStatement
	DropColumnAction
	DropConstraintAction
	DropEntityStatement
	DropFunctionStatement
	DropPrimaryKeyAction
	DropPrivilegeRestrictionStatement
	DropRowAccessPolicyStatement
	DropSearchIndexStatement
	DropStatement
	DropTableFunctionStatement
	DropMaterializedViewStatement
	DropSnapshotTableStatement
	ElseifClause
	ElseifClauseList
	ExceptionHandler
	ExceptionHandlerList
	ExecuteImmediateStatement
	ExecuteIntoClause
	ExecuteUsingArgument
	ExecuteUsingClause
	ExplainStatement
	ExportDataStatement
	ExportModelStatement
	ExpressionSubquery
	ExtractExpression
	FilterFieldsArg
	FilterFieldsExpression
	FilterUsingClause
	FloatLiteral
	ForInStatement
	ForeignKey
	ForeignKeyActions
	ForeignKeyColumnAttribute
	ForeignKeyReference
	FormatClause
	ForSystemTime
	FromClause
	FunctionCall
	FunctionDeclaration
	FunctionParameter
	FunctionParameters
	GeneratedColumnInfo
	GranteeList
	GrantStatement
	GrantToClause
	RestrictToClause
	GroupBy
	GroupingItem
	Having
	HavingModifier
	HiddenColumnAttribute
	Hint
	HintedStatement
	HintEntry
	Identifier
	IdentifierList
	IfStatement
	ImportStatement
	InExpression
	InList
	IndexAllColumns
	IndexItemList
	IndexStoringExpressionList
	IndexUnnestExpressionList
	InferredTypeColumnSchema
	InsertStatement
	InsertValuesRow
	InsertValuesRowList
	IntervalExpr
	IntoAlias
	IntLiteral
	Join
	JoinLiteral
	Label
	Lambda
	LikeExpression
	LimitOffset
	MaxLiteral
	MergeAction
	MergeStatement
	MergeWhenClause
	MergeWhenClauseList
	ModelClause
	ModuleStatement
	NamedArgument
	NewConstructor
	NewConstructorArg
	NotNullColumnAttribute
	NullLiteral
	NullOrder
	NumericLiteral
	OnClause
	OnOrUsingClauseList
	OptionsEntry
	OptionsList
	OrderBy
	OrderingExpression
	OrExpr
	ParameterAssignment
	ParameterExpr
	ParenthesizedJoin
	PartitionBy
	PathExpression
	PathExpressionList
	PivotClause
	UnpivotClause
	UnpivotInItemLabel
	UnpivotInItem
	UnpivotInItemList
	PivotExpression
	PivotExpressionList
	PivotValue
	PivotValueList
	PrimaryKey
	PrimaryKeyColumnAttribute
	Privilege
	Privileges
	Qualify
	Query
	QueryStatement
	RaiseStatement
	RemoveFromRestricteeListClause
	RenameColumnAction
	RenameToClause
	RenameStatement
	RepeatStatement
	RepeatableClause
	ReplaceFieldsArg
	ReplaceFieldsExpression
	ReturnStatement
	ReturningClause
	RevokeFromClause
	RevokeStatement
	RollbackStatement
	Rollup
	RunBatchStatement
	SampleClause
	SampleSize
	SampleSuffix
	Script
	Select
	SelectAs
	SelectColumn
	SelectList
	SetOperation
	SetOptionsAction
	SetAsAction
	SetCollateClause
	SetTransactionStatement
	SingleAssignment
	ShowStatement
	SimpleColumnSchema
	SimpleType
	SqlFunctionBody
	Star
	StarExceptList
	StarModifiers
	StarReplaceItem
	StarWithModifiers
	StarBatchStatement
	StatementList
	StringLiteral
	StructColumnField
	StructColumnSchema
	StructConstructorArg
	StructConstructorWithKeyword
	StructConstructorWithParens
	StructField
	StructType
	SystemVariableAssignment
	SystemVariableExpr
	TableAndColumnInfo
	TableAndColumnInfoList
	TableClause
	TableElementList
	TablePathExpression
	TableSubquery
	TemplatedParameterType
	TransactionIsolationLevel
	TransactionModeList
	TransactionReadWriteMode
	TransformClause
	TrucateStatement
	Tvf
	TvfArgument
	TvfSchema
	TvfSchemaColumn
	TypeParameterList
	UnaryExpression
	UnnestExpression
	UnnestExpressionWithOptAliasAndOffset
	UntilClause
	UpdateItem
	UpdateItemList
	UpdateSetValue
	UpdateStatement
	UsingClause
	VariableDeclaration
	WhenThenClause
	WhenThenClauseList
	WhereClause
	WhileStatement
	WindowClause
	WindowDefinition
	WindowFrame
	WindowFrameExpr
	WindowSpecification
	WithClause
	WithClauseEntry
	WithConnectionClause
	WithGroupRows
	WithOffset
	WithPartitionColumnsClause
	WithWeight
)

func (k Kind) String() string {
	switch k {
	case Unknown:
		return "Unknown"
	case Fake:
		return "Fake"
	case AbortBatchStatement:
		return "AbortBatchStatement"
	case AddColumnAction:
		return "AddColumnAction"
	case AddConstraintAction:
		return "AddConstraintAction"
	case AddToRestricteeListClause:
		return "AddToRestricteeListClause"
	case FunctionCallWithGroupRows:
		return "FunctionCallWithGroupRows"
	case Alias:
		return "Alias"
	case AlterActionList:
		return "AlterActionList"
	case AlterAllRowAccessPoliciesStatement:
		return "AlterAllRowAccessPoliciesStatement"
	case AlterColumnOptionsAction:
		return "AlterColumnOptionsAction"
	case AlterColumnDropNotNullAction:
		return "AlterColumnDropNotNullAction"
	case AlterColumnTypeAction:
		return "AlterColumnTypeAction"
	case AlterColumnSetDefaultAction:
		return "AlterColumnSetDefaultAction"
	case AlterColumnDropDefaultAction:
		return "AlterColumnDropDefaultAction"
	case AlterConstraintEnforcementAction:
		return "AlterConstraintEnforcementAction"
	case AlterConstraintSetOptionsAction:
		return "AlterConstraintSetOptionsAction"
	case AlterDatabaseStatement:
		return "AlterDatabaseStatement"
	case AlterEntityStatement:
		return "AlterEntityStatement"
	case AlterMaterializedViewStatement:
		return "AlterMaterializedViewStatement"
	case AlterPrivilegeRestrictionStatement:
		return "AlterPrivilegeRestrictionStatement"
	case AlterRowAccessPolicyStatement:
		return "AlterRowAccessPolicyStatement"
	case AlterSchemaStatement:
		return "AlterSchemaStatement"
	case AlterTableStatement:
		return "AlterTableStatement"
	case AlterViewStatement:
		return "AlterViewStatement"
	case AnalyticFunctionCall:
		return "AnalyticFunctionCall"
	case AnalyzeStatement:
		return "AnalyzeStatement"
	case AndExpr:
		return "AndExpr"
	case AnySomeAllOp:
		return "AnySomeAllOp"
	case ArrayColumnSchema:
		return "ArrayColumnSchema"
	case ArrayConstructor:
		return "ArrayConstructor"
	case ArrayElement:
		return "ArrayElement"
	case ArrayType:
		return "ArrayType"
	case AssertRowsModified:
		return "AssertRowsModified"
	case AssertStatement:
		return "AssertStatement"
	case AssignmentFromStruct:
		return "AssignmentFromStruct"
	case BeginStatement:
		return "BeginStatement"
	case BetweenExpression:
		return "BetweenExpression"
	case AuxLoadDataFromFilesOptionsList:
		return "AuxLoadDataFromFilesOptionsList"
	case AuxLoadDataStatement:
		return "AuxLoadDataStatement"
	case BignumericLiteral:
		return "BignumericLiteral"
	case BinaryExpression:
		return "BinaryExpression"
	case BitwiseShiftExpression:
		return "BitwiseShiftExpression"
	case BeginEndBlock:
		return "BeginEndBlock"
	case BooleanLiteral:
		return "BooleanLiteral"
	case BreakStatement:
		return "BreakStatement"
	case BytesLiteral:
		return "BytesLiteral"
	case CallStatement:
		return "CallStatement"
	case CaseStatement:
		return "CaseStatement"
	case CaseNoValueExpression:
		return "CaseNoValueExpression"
	case CaseValueExpression:
		return "CaseValueExpression"
	case CastExpression:
		return "CastExpression"
	case CheckConstraint:
		return "CheckConstraint"
	case ClampedBetweenModifier:
		return "ClampedBetweenModifier"
	case CloneDataSource:
		return "CloneDataSource"
	case CloneDataSourceList:
		return "CloneDataSourceList"
	case CloneDataStatement:
		return "CloneDataStatement"
	case ClusterBy:
		return "ClusterBy"
	case Collate:
		return "Collate"
	case ColumnAttributeList:
		return "ColumnAttributeList"
	case ColumnDefinition:
		return "ColumnDefinition"
	case ColumnList:
		return "ColumnList"
	case ColumnPosition:
		return "ColumnPosition"
	case CommitStatement:
		return "CommitStatement"
	case ConnectionClause:
		return "ConnectionClause"
	case ContinueStatement:
		return "ContinueStatement"
	case CopyDataSource:
		return "CopyDataSource"
	case CreateConstantStatement:
		return "CreateConstantStatement"
	case CreateDatabaseStatement:
		return "CreateDatabaseStatement"
	case CreateExternalTableStatement:
		return "CreateExternalTableStatement"
	case CreateFunctionStatement:
		return "CreateFunctionStatement"
	case CreateIndexStatement:
		return "CreateIndexStatement"
	case CreateModelStatement:
		return "CreateModelStatement"
	case CreateProcedureStatement:
		return "CreateProcedureStatement"
	case CreatePrivilegeRestrictionStatement:
		return "CreatePrivilegeRestrictionStatement"
	case CreateRowAccessPolicyStatement:
		return "CreateRowAccessPolicyStatement"
	case CreateSchemaStatement:
		return "CreateSchemaStatement"
	case CreateSnapshotTableStatement:
		return "CreateSnapshotTableStatement"
	case CreateTableFunctionStatement:
		return "CreateTableFunctionStatement"
	case CreateTableStatement:
		return "CreateTableStatement"
	case CreateEntityStatement:
		return "CreateEntityStatement"
	case CreateViewStatement:
		return "CreateViewStatement"
	case CreateMaterializedViewStatement:
		return "CreateMaterializedViewStatement"
	case DateOrTimeLiteral:
		return "DateOrTimeLiteral"
	case DefaultLiteral:
		return "DefaultLiteral"
	case DefineTableStatement:
		return "DefineTableStatement"
	case DeleteStatement:
		return "DeleteStatement"
	case DescribeStatement:
		return "DescribeStatement"
	case DescriptorColumn:
		return "DescriptorColumn"
	case DescriptorColumnList:
		return "DescriptorColumnList"
	case Descriptor:
		return "Descriptor"
	case DotGeneralizedField:
		return "DotGeneralizedField"
	case DotIdentifier:
		return "DotIdentifier"
	case DotStar:
		return "DotStar"
	case DotStarWithModifiers:
		return "DotStarWithModifiers"
	case DropAllRowAccessPoliciesStatement:
		return "DropAllRowAccessPoliciesStatement"
	case DropColumnAction:
		return "DropColumnAction"
	case DropConstraintAction:
		return "DropConstraintAction"
	case DropEntityStatement:
		return "DropEntityStatement"
	case DropFunctionStatement:
		return "DropFunctionStatement"
	case DropPrimaryKeyAction:
		return "DropPrimaryKeyAction"
	case DropPrivilegeRestrictionStatement:
		return "DropPrivilegeRestrictionStatement"
	case DropRowAccessPolicyStatement:
		return "DropRowAccessPolicyStatement"
	case DropSearchIndexStatement:
		return "DropSearchIndexStatement"
	case DropStatement:
		return "DropStatement"
	case DropTableFunctionStatement:
		return "DropTableFunctionStatement"
	case DropMaterializedViewStatement:
		return "DropMaterializedViewStatement"
	case DropSnapshotTableStatement:
		return "DropSnapshotTableStatement"
	case ElseifClause:
		return "ElseifClause"
	case ElseifClauseList:
		return "ElseifClauseList"
	case ExceptionHandler:
		return "ExceptionHandler"
	case ExceptionHandlerList:
		return "ExceptionHandlerList"
	case ExecuteImmediateStatement:
		return "ExecuteImmediateStatement"
	case ExecuteIntoClause:
		return "ExecuteIntoClause"
	case ExecuteUsingArgument:
		return "ExecuteUsingArgument"
	case ExecuteUsingClause:
		return "ExecuteUsingClause"
	case ExplainStatement:
		return "ExplainStatement"
	case ExportDataStatement:
		return "ExportDataStatement"
	case ExportModelStatement:
		return "ExportModelStatement"
	case ExpressionSubquery:
		return "ExpressionSubquery"
	case ExtractExpression:
		return "ExtractExpression"
	case FilterFieldsArg:
		return "FilterFieldsArg"
	case FilterFieldsExpression:
		return "FilterFieldsExpression"
	case FilterUsingClause:
		return "FilterUsingClause"
	case FloatLiteral:
		return "FloatLiteral"
	case ForInStatement:
		return "ForInStatement"
	case ForeignKey:
		return "ForeignKey"
	case ForeignKeyActions:
		return "ForeignKeyActions"
	case ForeignKeyColumnAttribute:
		return "ForeignKeyColumnAttribute"
	case ForeignKeyReference:
		return "ForeignKeyReference"
	case FormatClause:
		return "FormatClause"
	case ForSystemTime:
		return "ForSystemTime"
	case FromClause:
		return "FromClause"
	case FunctionCall:
		return "FunctionCall"
	case FunctionDeclaration:
		return "FunctionDeclaration"
	case FunctionParameter:
		return "FunctionParameter"
	case FunctionParameters:
		return "FunctionParameters"
	case GeneratedColumnInfo:
		return "GeneratedColumnInfo"
	case GranteeList:
		return "GranteeList"
	case GrantStatement:
		return "GrantStatement"
	case GrantToClause:
		return "GrantToClause"
	case RestrictToClause:
		return "RestrictToClause"
	case GroupBy:
		return "GroupBy"
	case GroupingItem:
		return "GroupingItem"
	case Having:
		return "Having"
	case HavingModifier:
		return "HavingModifier"
	case HiddenColumnAttribute:
		return "HiddenColumnAttribute"
	case Hint:
		return "Hint"
	case HintedStatement:
		return "HintedStatement"
	case HintEntry:
		return "HintEntry"
	case Identifier:
		return "Identifier"
	case IdentifierList:
		return "IdentifierList"
	case IfStatement:
		return "IfStatement"
	case ImportStatement:
		return "ImportStatement"
	case InExpression:
		return "InExpression"
	case InList:
		return "InList"
	case IndexAllColumns:
		return "IndexAllColumns"
	case IndexItemList:
		return "IndexItemList"
	case IndexStoringExpressionList:
		return "IndexStoringExpressionList"
	case IndexUnnestExpressionList:
		return "IndexUnnestExpressionList"
	case InferredTypeColumnSchema:
		return "InferredTypeColumnSchema"
	case InsertStatement:
		return "InsertStatement"
	case InsertValuesRow:
		return "InsertValuesRow"
	case InsertValuesRowList:
		return "InsertValuesRowList"
	case IntervalExpr:
		return "IntervalExpr"
	case IntoAlias:
		return "IntoAlias"
	case IntLiteral:
		return "IntLiteral"
	case Join:
		return "Join"
	case JoinLiteral:
		return "JoinLiteral"
	case Label:
		return "Label"
	case Lambda:
		return "Lambda"
	case LikeExpression:
		return "LikeExpression"
	case LimitOffset:
		return "LimitOffset"
	case MaxLiteral:
		return "MaxLiteral"
	case MergeAction:
		return "MergeAction"
	case MergeStatement:
		return "MergeStatement"
	case MergeWhenClause:
		return "MergeWhenClause"
	case MergeWhenClauseList:
		return "MergeWhenClauseList"
	case ModelClause:
		return "ModelClause"
	case ModuleStatement:
		return "ModuleStatement"
	case NamedArgument:
		return "NamedArgument"
	case NewConstructor:
		return "NewConstructor"
	case NewConstructorArg:
		return "NewConstructorArg"
	case NotNullColumnAttribute:
		return "NotNullColumnAttribute"
	case NullLiteral:
		return "NullLiteral"
	case NullOrder:
		return "NullOrder"
	case NumericLiteral:
		return "NumericLiteral"
	case OnClause:
		return "OnClause"
	case OnOrUsingClauseList:
		return "OnOrUsingClauseList"
	case OptionsEntry:
		return "OptionsEntry"
	case OptionsList:
		return "OptionsList"
	case OrderBy:
		return "OrderBy"
	case OrderingExpression:
		return "OrderingExpression"
	case OrExpr:
		return "OrExpr"
	case ParameterAssignment:
		return "ParameterAssignment"
	case ParameterExpr:
		return "ParameterExpr"
	case ParenthesizedJoin:
		return "ParenthesizedJoin"
	case PartitionBy:
		return "PartitionBy"
	case PathExpression:
		return "PathExpression"
	case PathExpressionList:
		return "PathExpressionList"
	case PivotClause:
		return "PivotClause"
	case UnpivotClause:
		return "UnpivotClause"
	case UnpivotInItemLabel:
		return "UnpivotInItemLabel"
	case UnpivotInItem:
		return "UnpivotInItem"
	case UnpivotInItemList:
		return "UnpivotInItemList"
	case PivotExpression:
		return "PivotExpression"
	case PivotExpressionList:
		return "PivotExpressionList"
	case PivotValue:
		return "PivotValue"
	case PivotValueList:
		return "PivotValueList"
	case PrimaryKey:
		return "PrimaryKey"
	case PrimaryKeyColumnAttribute:
		return "PrimaryKeyColumnAttribute"
	case Privilege:
		return "Privilege"
	case Privileges:
		return "Privileges"
	case Qualify:
		return "Qualify"
	case Query:
		return "Query"
	case QueryStatement:
		return "QueryStatement"
	case RaiseStatement:
		return "RaiseStatement"
	case RemoveFromRestricteeListClause:
		return "RemoveFromRestricteeListClause"
	case RenameColumnAction:
		return "RenameColumnAction"
	case RenameToClause:
		return "RenameToClause"
	case RenameStatement:
		return "RenameStatement"
	case RepeatStatement:
		return "RepeatStatement"
	case RepeatableClause:
		return "RepeatableClause"
	case ReplaceFieldsArg:
		return "ReplaceFieldsArg"
	case ReplaceFieldsExpression:
		return "ReplaceFieldsExpression"
	case ReturnStatement:
		return "ReturnStatement"
	case ReturningClause:
		return "ReturningClause"
	case RevokeFromClause:
		return "RevokeFromClause"
	case RevokeStatement:
		return "RevokeStatement"
	case RollbackStatement:
		return "RollbackStatement"
	case Rollup:
		return "Rollup"
	case RunBatchStatement:
		return "RunBatchStatement"
	case SampleClause:
		return "SampleClause"
	case SampleSize:
		return "SampleSize"
	case SampleSuffix:
		return "SampleSuffix"
	case Script:
		return "Script"
	case Select:
		return "Select"
	case SelectAs:
		return "SelectAs"
	case SelectColumn:
		return "SelectColumn"
	case SelectList:
		return "SelectList"
	case SetOperation:
		return "SetOperation"
	case SetOptionsAction:
		return "SetOptionsAction"
	case SetAsAction:
		return "SetAsAction"
	case SetCollateClause:
		return "SetCollateClause"
	case SetTransactionStatement:
		return "SetTransactionStatement"
	case SingleAssignment:
		return "SingleAssignment"
	case ShowStatement:
		return "ShowStatement"
	case SimpleColumnSchema:
		return "SimpleColumnSchema"
	case SimpleType:
		return "SimpleType"
	case SqlFunctionBody:
		return "SqlFunctionBody"
	case Star:
		return "Star"
	case StarExceptList:
		return "StarExceptList"
	case StarModifiers:
		return "StarModifiers"
	case StarReplaceItem:
		return "StarReplaceItem"
	case StarWithModifiers:
		return "StarWithModifiers"
	case StarBatchStatement:
		return "StarBatchStatement"
	case StatementList:
		return "StatementList"
	case StringLiteral:
		return "StringLiteral"
	case StructColumnField:
		return "StructColumnField"
	case StructColumnSchema:
		return "StructColumnSchema"
	case StructConstructorArg:
		return "StructConstructorArg"
	case StructConstructorWithKeyword:
		return "StructConstructorWithKeyword"
	case StructConstructorWithParens:
		return "StructConstructorWithParens"
	case StructField:
		return "StructField"
	case StructType:
		return "StructType"
	case SystemVariableAssignment:
		return "SystemVariableAssignment"
	case SystemVariableExpr:
		return "SystemVariableExpr"
	case TableAndColumnInfo:
		return "TableAndColumnInfo"
	case TableAndColumnInfoList:
		return "TableAndColumnInfoList"
	case TableClause:
		return "TableClause"
	case TableElementList:
		return "TableElementList"
	case TablePathExpression:
		return "TablePathExpression"
	case TableSubquery:
		return "TableSubquery"
	case TemplatedParameterType:
		return "TemplatedParameterType"
	case TransactionIsolationLevel:
		return "TransactionIsolationLevel"
	case TransactionModeList:
		return "TransactionModeList"
	case TransactionReadWriteMode:
		return "TransactionReadWriteMode"
	case TransformClause:
		return "TransformClause"
	case TrucateStatement:
		return "TrucateStatement"
	case Tvf:
		return "Tvf"
	case TvfArgument:
		return "TvfArgument"
	case TvfSchema:
		return "TvfSchema"
	case TvfSchemaColumn:
		return "TvfSchemaColumn"
	case TypeParameterList:
		return "TypeParameterList"
	case UnaryExpression:
		return "UnaryExpression"
	case UnnestExpression:
		return "UnnestExpression"
	case UnnestExpressionWithOptAliasAndOffset:
		return "UnnestExpressionWithOptAliasAndOffset"
	case UntilClause:
		return "UntilClause"
	case UpdateItem:
		return "UpdateItem"
	case UpdateItemList:
		return "UpdateItemList"
	case UpdateSetValue:
		return "UpdateSetValue"
	case UpdateStatement:
		return "UpdateStatement"
	case UsingClause:
		return "UsingClause"
	case VariableDeclaration:
		return "VariableDeclaration"
	case WhenThenClause:
		return "WhenThenClause"
	case WhenThenClauseList:
		return "WhenThenClauseList"
	case WhereClause:
		return "WhereClause"
	case WhileStatement:
		return "WhileStatement"
	case WindowClause:
		return "WindowClause"
	case WindowDefinition:
		return "WindowDefinition"
	case WindowFrame:
		return "WindowFrame"
	case WindowFrameExpr:
		return "WindowFrameExpr"
	case WindowSpecification:
		return "WindowSpecification"
	case WithClause:
		return "WithClause"
	case WithClauseEntry:
		return "WithClauseEntry"
	case WithConnectionClause:
		return "WithConnectionClause"
	case WithGroupRows:
		return "WithGroupRows"
	case WithOffset:
		return "WithOffset"
	case WithPartitionColumnsClause:
		return "WithPartitionColumnsClause"
	case WithWeight:
		return "WithWeight"
	}
	return ""
}

type TypeKind int

const (
	TypeUnknown TypeKind = iota
	TypeInt32
	TypeInt64
	TypeUint32
	TypeUint64
	TypeBool
	TypeFloat
	TypeDouble
	TypeString
	TypeBytes
	TypeDate
	TypeTimestamp
	TypeEnum
	TypeArray
	TypeStruct
	TypeProto
	TypeTime
	TypeDatetime
	TypeGeography
	TypeNumeric
	TypBignumeric
	TypeExtended
	TypeJson
	TypeInternal
)

func (t TypeKind) String() string {
	switch t {
	case TypeUnknown:
		return "UNKNOWN"
	case TypeInt32:
		return "INT32"
	case TypeInt64:
		return "INT64"
	case TypeUint32:
		return "UINT32"
	case TypeUint64:
		return "UINT64"
	case TypeBool:
		return "BOOL"
	case TypeFloat:
		return "FLOAT"
	case TypeDouble:
		return "DOUBLE"
	case TypeString:
		return "STRING"
	case TypeBytes:
		return "BYTES"
	case TypeDate:
		return "DATE"
	case TypeTimestamp:
		return "TIMESTAMP"
	case TypeEnum:
		return "ENUM"
	case TypeArray:
		return "ARRAY"
	case TypeStruct:
		return "STRUCT"
	case TypeProto:
		return "PROTO"
	case TypeTime:
		return "TIME"
	case TypeDatetime:
		return "DATETIME"
	case TypeGeography:
		return "GEOGRAPHY"
	case TypeNumeric:
		return "NUMERIC"
	case TypBignumeric:
		return "BIGNUMERIC"
	case TypeExtended:
		return "EXTENDED"
	case TypeJson:
		return "JSON"
	case TypeInternal:
		return "INTERNAL"
	}
	return ""
}

type SchemaObjectKind int

const (
	UnknownSchemaObject SchemaObjectKind = iota
	InvalidSchemaObjectKind
	AggregateFunctionKind
	ConstantKind
	DatabaseKind
	ExternalTableKind
	FunctionKind
	IndexKind
	MaterializedViewKind
	ModelKind
	ProcedureKind
	SchemaKind
	TableKind
	TableFunctionKind
	ViewKind
	SnapshotTableKind
)
