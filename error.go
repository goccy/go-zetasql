package zetasql

import "fmt"

var (
	ErrParseStatement  = fmt.Errorf("failed to get statement node")
	ErrParseScript     = fmt.Errorf("failed to get script node")
	ErrParseType       = fmt.Errorf("failed to get type node")
	ErrParseExpression = fmt.Errorf("failed to get expression node")
	ErrRequiredCatalog = fmt.Errorf("catalog is required parameter to analyze sql")
)
