package resolved_ast

import (
	"unsafe"

	"github.com/goccy/go-zetasql/constant"
	"github.com/goccy/go-zetasql/types"
)

//go:linkname newValue github.com/goccy/go-zetasql/constant.newValue
func newValue(unsafe.Pointer) constant.Value

//go:linkname getRawValue github.com/goccy/go-zetasql/constant.getRawValue
func getRawValue(constant.Value) unsafe.Pointer

//go:linkname newType github.com/goccy/go-zetasql/types.newType
func newType(unsafe.Pointer) types.Type

//go:linkname getRawType github.com/goccy/go-zetasql/types.getRawType
func getRawType(types.Type) unsafe.Pointer

//go:linkname newAnnotationMap github.com/goccy/go-zetasql/types.newAnnotationMap
func newAnnotationMap(unsafe.Pointer) *types.AnnotationMap

//go:linkname getRawAnnotationMap github.com/goccy/go-zetasql/types.getRawAnnotationMap
func getRawAnnotationMap(*types.AnnotationMap) unsafe.Pointer

//go:linkname newConstant github.com/goccy/go-zetasql/types.newConstant
func newConstant(unsafe.Pointer) types.Constant

//go:linkname getRawConstant github.com/goccy/go-zetasql/types.getRawConstant
func getRawConstant(types.Constant) unsafe.Pointer

//go:linkname newFunction github.com/goccy/go-zetasql/types.newFunction
func newFunction(unsafe.Pointer) *types.Function

//go:linkname getRawFunction github.com/goccy/go-zetasql/types.getRawFunction
func getRawFunction(*types.Function) unsafe.Pointer
