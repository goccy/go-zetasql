package zetasql

import (
	"unsafe"

	"github.com/goccy/go-zetasql/resolved_ast"
	"github.com/goccy/go-zetasql/types"
)

//go:linkname getRawCatalog github.com/goccy/go-zetasql/types.getRawCatalog
func getRawCatalog(types.Catalog) unsafe.Pointer

//go:linkname newResolvedNode github.com/goccy/go-zetasql/resolved_ast.newNode
func newResolvedNode(unsafe.Pointer) resolved_ast.Node

//go:linkname newType github.com/goccy/go-zetasql/types.newType
func newType(unsafe.Pointer) types.Type

//go:linkname getRawType github.com/goccy/go-zetasql/types.getRawType
func getRawType(types.Type) unsafe.Pointer
