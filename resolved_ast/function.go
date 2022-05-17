package resolved_ast

import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
)

// FunctionCallInfo contains custom information about a particular function call.
// ZetaSQL passes it to the engine in the FunctionCallNode. Functions may
// introduce subclasses of this class to add custom information as needed on a
// per-function basis.
type FunctionCallInfo struct {
	raw unsafe.Pointer
}

func (f *FunctionCallInfo) DebugString() string {
	var v unsafe.Pointer
	internal.ResolvedFunctionCallInfo_DebugString(f.raw, &v)
	return helper.PtrToString(v)
}

func newFunctionCallInfo(v unsafe.Pointer) *FunctionCallInfo {
	if v == nil {
		return nil
	}
	return &FunctionCallInfo{raw: v}
}
