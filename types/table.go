package types

import (
	"reflect"
	"runtime/cgo"
	"sync"
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
)

import "C"

type EvaluatorTableIterator struct {
	raw unsafe.Pointer
}

func newEvaluatorTableIterator(v unsafe.Pointer) *EvaluatorTableIterator {
	if v == nil {
		return nil
	}
	return &EvaluatorTableIterator{raw: v}
}

type Table interface {
	Name() string
	FullName() string
	NumColumns() int
	Column(int) Column
	PrimaryKey() []int
	FindColumnByName(name string) Column
	IsValueTable() bool
	SerializationID() int64
	CreateEvaluatorTableIterator(columnIdxs []int) (*EvaluatorTableIterator, error)
	AnonymizationInfo() *AnonymizationInfo
	SupportsAnonymization() bool
	TableTypeName(mode ProductMode) string
}

type BaseTable struct {
	raw unsafe.Pointer
}

func (t *BaseTable) getRaw() unsafe.Pointer {
	return t.raw
}

func (t *BaseTable) Name() string {
	var v unsafe.Pointer
	internal.Table_Name(t.raw, &v)
	return C.GoString((*C.char)(v))
}

func (t *BaseTable) FullName() string {
	var v unsafe.Pointer
	internal.Table_FullName(t.raw, &v)
	return C.GoString((*C.char)(v))
}

func (t *BaseTable) NumColumns() int {
	var v int
	internal.Table_NumColumns(t.raw, &v)
	return v
}

func (t *BaseTable) Column(idx int) Column {
	var v unsafe.Pointer
	internal.Table_Column(t.raw, idx, &v)
	return newBaseColumn(v)
}

func (t *BaseTable) PrimaryKey() []int {
	var num int
	internal.Table_PrimaryKey_num(t.raw, &num)
	ret := make([]int, 0, num)
	for i := 0; i < num; i++ {
		var v int
		internal.Table_PrimaryKey(t.raw, i, &v)
		ret = append(ret, v)
	}
	return ret
}

func (t *BaseTable) FindColumnByName(name string) Column {
	var v unsafe.Pointer
	internal.Table_FindColumnByName(t.raw, helper.StringToPtr(name), &v)
	return newBaseColumn(v)
}

func (t *BaseTable) IsValueTable() bool {
	var v bool
	internal.Table_IsValueTable(t.raw, &v)
	return v
}

func (t *BaseTable) SerializationID() int64 {
	var v int
	internal.Table_GetSerializationId(t.raw, &v)
	return int64(v)
}

func (t *BaseTable) CreateEvaluatorTableIterator(columnIdxs []int) (*EvaluatorTableIterator, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	data, len := intSlice(columnIdxs)
	internal.Table_CreateEvaluatorTableIterator(t.raw, data, len, &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newEvaluatorTableIterator(v), nil
}

func (t *BaseTable) AnonymizationInfo() *AnonymizationInfo {
	var v unsafe.Pointer
	internal.Table_GetAnonymizationInfo(t.raw, &v)
	return newAnonymizationInfo(v)
}

func (t *BaseTable) SupportsAnonymization() bool {
	var v bool
	internal.Table_SupportsAnonymization(t.raw, &v)
	return v
}

func (t *BaseTable) TableTypeName(mode ProductMode) string {
	var v unsafe.Pointer
	internal.Table_GetTableTypeName(t.raw, int(mode), &v)
	return helper.PtrToString(v)
}

func newBaseTable(v unsafe.Pointer) *BaseTable {
	if v == nil {
		return nil
	}
	return &BaseTable{raw: v}
}

type SimpleTable struct {
	*BaseTable
}

func columnsToPtr(columns []Column) (unsafe.Pointer, int) {
	rawSlice := make([]unsafe.Pointer, 0, len(columns))
	for _, col := range columns {
		rawSlice = append(rawSlice, col.getRaw())
	}
	slice := (*reflect.SliceHeader)(unsafe.Pointer(&rawSlice))
	return unsafe.Pointer(slice.Data), slice.Len
}

func NewSimpleTable(name string, columns []Column) *SimpleTable {
	var v unsafe.Pointer
	columnsData, columnsLen := columnsToPtr(columns)
	internal.SimpleTable_new(helper.StringToPtr(name), columnsData, columnsLen, &v)
	if v == nil {
		return nil
	}
	return &SimpleTable{BaseTable: newBaseTable(v)}
}

func (t *SimpleTable) AddColumn(col Column) error {
	var status unsafe.Pointer
	internal.SimpleTable_AddColumn(t.raw, col.getRaw(), &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return st.Error()
	}
	return nil
}

func intSlice(v []int) (unsafe.Pointer, int) {
	slice := (*reflect.SliceHeader)(unsafe.Pointer(&v))
	return unsafe.Pointer(slice.Data), slice.Len
}

func (t *SimpleTable) SetPrimaryKey(primaryKey []int) error {
	var status unsafe.Pointer
	data, len := intSlice(primaryKey)
	internal.SimpleTable_SetPrimaryKey(t.raw, data, len, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return st.Error()
	}
	return nil
}

func (t *SimpleTable) SetFullName(fullName string) error {
	var status unsafe.Pointer
	internal.SimpleTable_set_full_name(t.raw, helper.StringToPtr(fullName), &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return st.Error()
	}
	return nil
}

func (t *SimpleTable) SetIsValueTable(value bool) {
	internal.SimpleTable_set_is_value_table(t.raw, helper.BoolToInt(value))
}

func (t *SimpleTable) AllowAnonymousColumnName() bool {
	var v bool
	internal.SimpleTable_AllowAnonymousColumnName(t.raw, &v)
	return v
}

func (t *SimpleTable) AllowDuplicateColumnNames() bool {
	var v bool
	internal.SimpleTable_AllowDuplicateColumnNames(t.raw, &v)
	return v
}

func (t *SimpleTable) SetAllowAnonymousColumnName(value bool) error {
	var status unsafe.Pointer
	internal.SimpleTable_set_allow_anonymous_column_name(t.raw, helper.BoolToInt(value), &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return st.Error()
	}
	return nil
}

func (t *SimpleTable) SetAllowDuplicateColumnNames(value bool) error {
	var status unsafe.Pointer
	internal.SimpleTable_set_allow_duplicate_column_names(t.raw, helper.BoolToInt(value), &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return st.Error()
	}
	return nil
}

var (
	tableMap   = map[Table]*helper.CPtrHolder{}
	tableMapMu sync.Mutex
)

func newTable(v unsafe.Pointer) Table {
	tableMapMu.Lock()
	defer tableMapMu.Unlock()

	for t, holder := range tableMap {
		if holder.Ptr == v {
			return t
		}
	}
	return &SimpleTable{BaseTable: &BaseTable{raw: v}}
}

func getRawTable(v Table) unsafe.Pointer {
	if v == nil {
		return nil
	}
	switch t := v.(type) {
	case *BaseTable:
		return t.raw
	case *SimpleTable:
		return t.getRaw()
	}
	tableMapMu.Lock()
	defer tableMapMu.Unlock()

	holder, exists := tableMap[v]
	if exists {
		return holder.Ptr
	}

	goTable := &internal.GoTable{
		Name: func() string {
			return v.Name()
		},
		FullName: func() string {
			return v.FullName()
		},
		NumColumns: func() int {
			return v.NumColumns()
		},
		Column: func(idx int) unsafe.Pointer {
			c := v.Column(idx)
			return c.getRaw()
		},
		PrimaryKey: func() []int {
			return v.PrimaryKey()
		},
		FindColumnByName: func(name string) unsafe.Pointer {
			c := v.FindColumnByName(name)
			return c.getRaw()
		},
		IsValueTable: func() bool {
			return v.IsValueTable()
		},
		SerializationID: func() int64 {
			return v.SerializationID()
		},
		CreateEvaluatorTableIterator: func(columnIdxs []int) (unsafe.Pointer, error) {
			iter, err := v.CreateEvaluatorTableIterator(columnIdxs)
			if err != nil {
				return nil, err
			}
			return iter.raw, nil
		},
		AnonymizationInfo: func() unsafe.Pointer {
			ret := v.AnonymizationInfo()
			if ret == nil {
				return nil
			}
			return ret.raw
		},
		SupportsAnonymization: func() bool {
			return v.SupportsAnonymization()
		},
		TableTypeName: func(mode int) string {
			return v.TableTypeName(ProductMode(mode))
		},
	}

	h := cgo.NewHandle(goTable)
	var ret unsafe.Pointer
	handlerPtr := unsafe.Pointer(&h)
	internal.GoTable_new(handlerPtr, &ret)
	tableMap[v] = &helper.CPtrHolder{
		Ptr:     ret,
		Handler: handlerPtr,
	}
	return ret
}
