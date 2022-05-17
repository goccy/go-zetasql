package zetasql

import "C"
import (
	"errors"
	"unsafe"

	internalparser "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
)

type Status struct {
	raw unsafe.Pointer
}

func (s *Status) OK() bool {
	var v bool
	internalparser.Status_OK(s.raw, &v)
	return v
}

func (s *Status) String() string {
	var v unsafe.Pointer
	internalparser.Status_String(s.raw, &v)
	return C.GoString((*C.char)(v))
}

func (s *Status) Error() error {
	return errors.New(s.String())
}

func newStatus(raw unsafe.Pointer) *Status {
	return &Status{raw: raw}
}
