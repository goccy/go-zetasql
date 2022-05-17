package types

import "unsafe"

type Procedure interface {
	Name() string
	FullName() string
	NamePath() []string
	Signature() *FunctionSignature
	SupportedSignatureUserFacingText(ProductMode) string
	getRaw() unsafe.Pointer
}

type procedure struct {
	raw unsafe.Pointer
}

func (p *procedure) Name() string {
	return ""
}

func (p *procedure) FullName() string {
	return ""
}

func (p *procedure) NamePath() []string {
	return nil
}

func (p *procedure) Signature() *FunctionSignature {
	return nil
}

func (p *procedure) SupportedSignatureUserFacingText(ProductMode) string {
	return ""
}

func (p *procedure) getRaw() unsafe.Pointer {
	return p.raw
}

func newProcedure(v unsafe.Pointer) Procedure {
	return &procedure{raw: v}
}

func getRawProcedure(v Procedure) unsafe.Pointer {
	return v.getRaw()
}
