package types

import "unsafe"

type Constant interface {
	getRaw() unsafe.Pointer
}

type constant struct {
	raw unsafe.Pointer
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
