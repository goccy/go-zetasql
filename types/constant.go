package types

import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
)

type Constant interface {
	Name() string
	FullName() string
	Type() Type
	DebugString() string
	NamePath() []string
	getRaw() unsafe.Pointer
}

type constant struct {
	raw unsafe.Pointer
}

func (c *constant) Name() string {
	var v unsafe.Pointer
	internal.Constant_Name(c.raw, &v)
	return helper.PtrToString(v)
}

func (c *constant) FullName() string {
	var v unsafe.Pointer
	internal.Constant_FullName(c.raw, &v)
	return helper.PtrToString(v)
}

func (c *constant) Type() Type {
	var v unsafe.Pointer
	internal.Constant_type(c.raw, &v)
	return newType(v)
}

func (c *constant) DebugString() string {
	var v unsafe.Pointer
	internal.Constant_DebugString(c.raw, &v)
	return helper.PtrToString(v)
}

func (c *constant) NamePath() []string {
	var v unsafe.Pointer
	internal.Constant_name_path(c.raw, &v)
	var ret []string
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, helper.PtrToString(p))
	})
	return ret
}

func (c *constant) getRaw() unsafe.Pointer {
	return c.raw
}

func newConstant(v unsafe.Pointer) Constant {
	return &constant{raw: v}
}

func getRawConstant(v Constant) unsafe.Pointer {
	return v.getRaw()
}
