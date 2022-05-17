package resolved_ast

import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
	"github.com/goccy/go-zetasql/types"
)

// Column a column produced by part of a query (e.g. a scan or subquery).
//
// This is used in the column_list of a resolved AST node to represent a
// "slot" in the "tuple" produced by that logical operator.
// This is also used in expressions in ColumnRefNode to point at the
// column selected during name resolution.
//
// The column_id is the definitive identifier for a Column, and
// the column_id should be used to match a ColumnRefNode in an expression
// to the scan that produces that column.  column_ids are unique within
// a query.  If the same table is scanned multiple times, distinct column_ids
// will be chosen for each scan.
//
// Joins and other combining nodes may propagate Columns from their
// inputs, with the same column_ids.
type Column struct {
	raw unsafe.Pointer
}

func (c *Column) IsInitialized() bool {
	var v bool
	internal.ResolvedColumn_IsInitialized(c.raw, &v)
	return v
}

func (c *Column) Clear() {
	internal.ResolvedColumn_Clear(c.raw)
}

func (c *Column) DebugString() string {
	var v unsafe.Pointer
	internal.ResolvedColumn_DebugString(c.raw, &v)
	return helper.PtrToString(v)
}

func (c *Column) ShortDebugString() string {
	var v unsafe.Pointer
	internal.ResolvedColumn_ShortDebugString(c.raw, &v)
	return helper.PtrToString(v)
}

func (c *Column) ColumnID() int {
	var v int
	internal.ResolvedColumn_column_id(c.raw, &v)
	return v
}

func (c *Column) TableName() string {
	var v unsafe.Pointer
	internal.ResolvedColumn_table_name(c.raw, &v)
	return helper.PtrToString(v)
}

func (c *Column) Name() string {
	var v unsafe.Pointer
	internal.ResolvedColumn_name(c.raw, &v)
	return helper.PtrToString(v)
}

func (c *Column) TableNameID() string {
	var v unsafe.Pointer
	internal.ResolvedColumn_table_name_id(c.raw, &v)
	return helper.PtrToString(v)
}

func (c *Column) NameID() string {
	var v unsafe.Pointer
	internal.ResolvedColumn_name_id(c.raw, &v)
	return helper.PtrToString(v)
}

func (c *Column) Type() types.Type {
	var v unsafe.Pointer
	internal.ResolvedColumn_type(c.raw, &v)
	return newType(v)
}

func (c *Column) TypeAnnotationMap() types.AnnotationMap {
	var v unsafe.Pointer
	internal.ResolvedColumn_type_annotation_map(c.raw, &v)
	return newAnnotationMap(v)
}

func (c *Column) AnnotatedType() *types.AnnotatedType {
	var v unsafe.Pointer
	internal.ResolvedColumn_annotated_type(c.raw, &v)
	return newAnnotatedType(v)
}

func newColumn(v unsafe.Pointer) *Column {
	if v == nil {
		return nil
	}
	return &Column{raw: v}
}
