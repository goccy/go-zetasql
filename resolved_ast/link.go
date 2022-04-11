package resolved_ast

import (
	"unsafe"

	"github.com/goccy/go-zetasql/constant"
)

//go:linkname newValue github.com/goccy/go-zetasql/constant.newValue
func newValue(unsafe.Pointer) constant.Value

//go:linkname getRawValue github.com/goccy/go-zetasql/constant.getRawValue
func getRawValue(constant.Value) unsafe.Pointer
