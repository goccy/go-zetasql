package zetasql

type TableValuedFunction interface {
	Name() string
	FullName() string
	FunctionNamePath() []string
	NumSignatures() int64
	Signatures() []FunctionSignature
	AddSignature(FunctionSignature) error
	Signature(int64) FunctionSignature
	SupportedSignaturesUserFacingText() string
	DebugString() string
	SetUserIdColumnNamePath(path []string) error
	AnonymizationInfo() AnonymizationInfo
}
