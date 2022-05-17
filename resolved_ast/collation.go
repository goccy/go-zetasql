package resolved_ast

import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
	"github.com/goccy/go-zetasql/types"
)

// Collation is used with types.Type to indicate the resolved collation
// for the type. For nested types, see comments on <child_list_> for how
// collation on subfield(s) are stored.
// This is always stored in a normalized form, meaning on all the nested levels,
// it has either an empty <child_list_> to indicate that it has no collation in
// any child, or it has at least one non-empty child.
type Collation struct {
	raw unsafe.Pointer
}

// Empty returns true if current type has no collation and has no children with collation.
func (c *Collation) Empty() bool {
	var v bool
	internal.ResolvedCollation_Empty(c.raw, &v)
	return v
}

func (c *Collation) Equals(that *Collation) bool {
	var v bool
	internal.ResolvedCollation_Equals(c.raw, that.raw, &v)
	return v
}

// HasCompatibleStructure returns true if this Collation has compatible nested structure with
// <type>. The structures are compatible when they meet the conditions below:
// * The Collation instance is either empty or is compatible by
//   recursively following these rules. When it is empty, it indicates that
//   the collation is empty on all the nested levels, and therefore such
//   instance is compatible with any Type (including structs and arrays).
// * This instance has collation and the <type> is a STRING type.
// * This instance has non-empty child_list and the <type> is a STRUCT,
//   the number of children matches the number of struct fields, and the
//   children have a compatible structure with the corresponding struct field
//   types.
// * This instance has exactly one child and <type> is an ARRAY, and the child
//   has a compatible structure with the array's element type.
func (c *Collation) HasCompatibleStructure(typ types.Type) bool {
	var v bool
	internal.ResolvedCollation_HasCompatibleStructure(c.raw, getRawType(typ), &v)
	return v
}

// HasCollation collation on current type (STRING), not on subfields.
func (c *Collation) HasCollation() bool {
	var v bool
	internal.ResolvedCollation_HasCollation(c.raw, &v)
	return v
}

func (c *Collation) CollationName() string {
	var v unsafe.Pointer
	internal.ResolvedCollation_CollationName(c.raw, &v)
	return helper.PtrToString(v)
}

// ChildList children only exist if any of the children have a collation.
func (c *Collation) ChildList() []*Collation {
	var v unsafe.Pointer
	internal.ResolvedCollation_child_list(c.raw, &v)
	var ret []*Collation
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newCollation(p))
	})
	return ret
}

func (c *Collation) DebugString() string {
	var v unsafe.Pointer
	internal.ResolvedCollation_DebugString(c.raw, &v)
	return helper.PtrToString(v)
}

func newCollation(v unsafe.Pointer) *Collation {
	if v == nil {
		return nil
	}
	return &Collation{raw: v}
}
