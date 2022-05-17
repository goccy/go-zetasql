package types

import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
)

import "C"

type Column interface {
	Name() string
	FullName() string
	Type() Type
	TypeAnnotationMap() AnnotationMap
	IsPseudoColumn() bool
	IsWritableColumn() bool
	getRaw() unsafe.Pointer
}

type BaseColumn struct {
	raw unsafe.Pointer
}

func (c *BaseColumn) getRaw() unsafe.Pointer {
	return c.raw
}

func (c *BaseColumn) Name() string {
	var v unsafe.Pointer
	internal.Column_Name(c.raw, &v)
	return helper.PtrToString(v)
}

func (c *BaseColumn) FullName() string {
	var v unsafe.Pointer
	internal.Column_FullName(c.raw, &v)
	return helper.PtrToString(v)
}

func (c *BaseColumn) Type() Type {
	var v unsafe.Pointer
	internal.Column_Type(c.raw, &v)
	return newType(v)
}

func (c *BaseColumn) TypeAnnotationMap() AnnotationMap {
	return nil
}

func (c *BaseColumn) IsPseudoColumn() bool {
	var v bool
	internal.Column_IsPseudoColumn(c.raw, &v)
	return v
}

func (c *BaseColumn) IsWritableColumn() bool {
	var v bool
	internal.Column_IsWritableColumn(c.raw, &v)
	return v
}

func newBaseColumn(raw unsafe.Pointer) *BaseColumn {
	if raw == nil {
		return nil
	}
	return &BaseColumn{raw: raw}
}

type SimpleColumn struct {
	*BaseColumn
}

func (c *SimpleColumn) AnnotatedType() *AnnotatedType {
	var v unsafe.Pointer
	internal.SimpleColumn_AnnotatedType(c.raw, &v)
	return newAnnotatedType(v)
}

func (c *SimpleColumn) SetIsPseudoColumn(v bool) {
	internal.SimpleColumn_SetIsPseudoColumn(c.raw, helper.BoolToInt(v))
}

func NewSimpleColumn(tableName, name string, typ Type) *SimpleColumn {
	var v unsafe.Pointer
	internal.SimpleColumn_new(helper.StringToPtr(tableName), helper.StringToPtr(name), typ.getRaw(), &v)
	if v == nil {
		return nil
	}
	return &SimpleColumn{BaseColumn: newBaseColumn(v)}
}

func NewSimpleColumnWithOpt(tableName, name string, typ Type, isPseudoColumn, isWritableColumn bool) *SimpleColumn {
	var v unsafe.Pointer
	internal.SimpleColumn_new_with_opt(
		helper.StringToPtr(tableName),
		helper.StringToPtr(name),
		typ.getRaw(),
		helper.BoolToInt(isPseudoColumn),
		helper.BoolToInt(isWritableColumn),
		&v,
	)
	if v == nil {
		return nil
	}
	return &SimpleColumn{BaseColumn: newBaseColumn(v)}
}
