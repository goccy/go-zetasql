package resolved_ast

import "unsafe"

// FunctionCallInfo contains custom information about a particular function call.
// ZetaSQL passes it to the engine in the FunctionCallNode. Functions may
// introduce subclasses of this class to add custom information as needed on a
// per-function basis.
type FunctionCallInfo struct {
	raw unsafe.Pointer
}

func (f *FunctionCallInfo) DebugString() string {
	return ""
}

func newFunctionCallInfo(v unsafe.Pointer) *FunctionCallInfo {
	if v == nil {
		return nil
	}
	return &FunctionCallInfo{raw: v}
}
