package resolved_ast

import (
	"unsafe"

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
	return false
}

func (c *Column) Clear() {
}

func (c *Column) DebugString() string {
	return ""
}

func (c *Column) ShortDebugString() string {
	return ""
}

func (c *Column) ColumnID() int {
	return 0
}

func (c *Column) TableName() string {
	return ""
}

func (c *Column) Name() string {
	return ""
}

func (c *Column) TableNameID() string {
	return ""
}

func (c *Column) NameID() string {
	return ""
}

func (c *Column) Type() types.Type {
	return nil
}

func (c *Column) TypeAnnotationMap() types.AnnotationMap {
	return nil
}

func (c *Column) AnnotatedType() *types.AnnotatedType {
	return nil
}

func newColumn(v unsafe.Pointer) *Column {
	if v == nil {
		return nil
	}
	return &Column{raw: v}
}
