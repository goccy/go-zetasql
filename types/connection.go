package types

import "unsafe"

type Connection interface {
	Name() string
	FullName() string
	getRaw() unsafe.Pointer
}

type connection struct {
	raw unsafe.Pointer
}

func (c *connection) Name() string {
	return ""
}

func (c *connection) FullName() string {
	return ""
}

func (c *connection) getRaw() unsafe.Pointer {
	return c.raw
}

func newConnection(v unsafe.Pointer) Connection {
	return &connection{raw: v}
}

func getRawConnection(v Connection) unsafe.Pointer {
	return v.getRaw()
}
