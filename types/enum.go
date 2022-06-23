package types

type ArgumentCardinality int

type SignatureArgumentKind int

type Mode int

const (
	ScalarMode    Mode = 1
	AggregateMode Mode = 2
	AnalyticMode  Mode = 3
)
