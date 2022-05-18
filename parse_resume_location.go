package zetasql

import "C"
import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
)

// ParseResumeLocation stores the parser input and a location, and is used as a restart token
// in repeated calls to operations that parse multiple items from one input string.
// Each successive call updates this location object so the next call knows where to start.
type ParseResumeLocation struct {
	raw unsafe.Pointer
}

// NewParseResumeLocation creates ParseResumeLocation instance.
func NewParseResumeLocation(src string) *ParseResumeLocation {
	var v unsafe.Pointer
	internal.ParseResumeLocation_FromStringView(unsafe.Pointer(C.CString(src)), &v)
	return &ParseResumeLocation{raw: v}
}
