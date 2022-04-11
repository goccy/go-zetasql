package types

import "unsafe"

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

// TVFSignature contains information about a specific resolved TVF call. It
// includes the input arguments passed into the TVF call and also its output
// schema (including whether it is a value table). Engines may also subclass
// this to include more information if needed.
type TVFSignature struct {
	raw unsafe.Pointer
}
