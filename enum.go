package zetasql

type ParameterMode int

const (
	ParameterNamed      ParameterMode = 0
	ParameterPositional ParameterMode = 1
	ParameterNone       ParameterMode = 2
)

type ErrorMessageMode int

const (
	ErrorMessageWithPayload        ErrorMessageMode = 0
	ErrorMessageOneLine            ErrorMessageMode = 1
	ErrorMessageMultiLineWithCaret ErrorMessageMode = 2
)

type StatementContext int

const (
	StatementContextDefault StatementContext = 0
	StatementContextModule  StatementContext = 1
)

type ParseLocationRecordType int

const (
	ParseLocationRecordNone          ParseLocationRecordType = 0
	ParseLocationRecordFullNodeScope ParseLocationRecordType = 1
	ParseLocationRecordCodeSearch    ParseLocationRecordType = 2
)
