package types

import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
)

type Procedure struct {
	raw unsafe.Pointer
}

func (p *Procedure) Name() string {
	var v unsafe.Pointer
	internal.Procedure_Name(p.raw, &v)
	return helper.PtrToString(v)
}

func (p *Procedure) FullName() string {
	var v unsafe.Pointer
	internal.Procedure_FullName(p.raw, &v)
	return helper.PtrToString(v)
}

func (p *Procedure) NamePath() []string {
	var v unsafe.Pointer
	internal.Procedure_NamePath(p.raw, &v)
	return helper.PtrToStrings(v)
}

func (p *Procedure) Signature() *FunctionSignature {
	var v unsafe.Pointer
	internal.Procedure_Signature(p.raw, &v)
	return newFunctionSignature(v)
}

func (p *Procedure) SupportedSignatureUserFacingText(mode ProductMode) string {
	var v unsafe.Pointer
	internal.Procedure_SupportedSignatureUserFacingText(p.raw, int(mode), &v)
	return helper.PtrToString(v)
}

func NewProcedure(namePath []string, signature *FunctionSignature) *Procedure {
	var v unsafe.Pointer
	internal.Procedure_new(helper.StringsToPtr(namePath), signature.raw, &v)
	return newProcedure(v)
}

func newProcedure(v unsafe.Pointer) *Procedure {
	return &Procedure{raw: v}
}

func getRawProcedure(v *Procedure) unsafe.Pointer {
	return v.raw
}
