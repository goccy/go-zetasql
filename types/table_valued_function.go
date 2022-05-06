package types

import "unsafe"

type TableValuedFunction interface {
	Name() string
	FullName() string
	FunctionNamePath() []string
	NumSignatures() int64
	Signatures() []*FunctionSignature
	AddSignature(*FunctionSignature) error
	Signature(int64) *FunctionSignature
	SupportedSignaturesUserFacingText() string
	DebugString() string
	SetUserIdColumnNamePath(path []string) error
	AnonymizationInfo() *AnonymizationInfo
	getRaw() unsafe.Pointer
}

// TVFSignature contains information about a specific resolved TVF call. It
// includes the input arguments passed into the TVF call and also its output
// schema (including whether it is a value table). Engines may also subclass
// this to include more information if needed.
type TVFSignature struct {
	raw unsafe.Pointer
}

type tableValuedFunction struct {
	raw unsafe.Pointer
}

func (*tableValuedFunction) Name() string {
	return ""
}

func (*tableValuedFunction) FullName() string {
	return ""
}

func (*tableValuedFunction) FunctionNamePath() []string {
	return nil
}

func (*tableValuedFunction) NumSignatures() int64 {
	return 0
}

func (*tableValuedFunction) Signatures() []*FunctionSignature {
	return nil
}

func (*tableValuedFunction) AddSignature(*FunctionSignature) error {
	return nil
}

func (*tableValuedFunction) Signature(int64) *FunctionSignature {
	return nil
}

func (*tableValuedFunction) SupportedSignaturesUserFacingText() string {
	return ""
}

func (*tableValuedFunction) DebugString() string {
	return ""
}

func (*tableValuedFunction) SetUserIdColumnNamePath(path []string) error {
	return nil
}

func (*tableValuedFunction) AnonymizationInfo() *AnonymizationInfo {
	return nil
}

func (*tableValuedFunction) getRaw() unsafe.Pointer {
	return nil
}

func newTableValuedFunction(v unsafe.Pointer) TableValuedFunction {
	return &tableValuedFunction{raw: v}
}

func getRawTableValuedFunction(v TableValuedFunction) unsafe.Pointer {
	return v.getRaw()
}

func newTVFSignature(v unsafe.Pointer) *TVFSignature {
	return &TVFSignature{raw: v}
}

func getRawTVFSignature(v *TVFSignature) unsafe.Pointer {
	return v.raw
}
