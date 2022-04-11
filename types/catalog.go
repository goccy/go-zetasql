package types

import (
	"reflect"
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/public/simple_catalog"
	"github.com/goccy/go-zetasql/internal/helper"
)

import "C"

type Catalog interface {
	FullName() string
	FindTable(path []string) (Table, error)
	FindModel(path []string) (Model, error)
	FindConnection(path []string) (Connection, error)
	FindFunction(path []string) (*Function, error)
	FindTableValuedFunction(path []string) (TableValuedFunction, error)
	FindProcedure(path []string) (Procedure, error)
	FindType(path []string) (Type, error)
	FindConstant(path []string) (Constant, error)
	FindConversion(from, to Type) (Conversion, error)
	ExtendedTypeSuperTypes(typ Type) (*TypeListView, error)
	SuggestTable(mistypedPath []string) string
	SuggestModel(mistypedPath []string) string
	SuggestFunction(mistypedPath []string) string
	SuggestTableValuedFunction(mistypedPath []string) string
	SuggestConstant(mistypedPath []string) string
	getRaw() unsafe.Pointer
}

type EnumerableCatalog interface {
	Catalog
	Catalogs() ([]Catalog, error)
	Tables() ([]Table, error)
	Types() ([]Type, error)
	Functions() ([]Function, error)
	Conversions() ([]Conversion, error)
}

type BaseCatalog struct {
	raw unsafe.Pointer
}

func newBaseCatalog(v unsafe.Pointer) *BaseCatalog {
	if v == nil {
		return nil
	}
	return &BaseCatalog{raw: v}
}

func (c *BaseCatalog) getRaw() unsafe.Pointer {
	return c.raw
}

func (c *BaseCatalog) FullName() string {
	var v unsafe.Pointer
	internal.Catalog_FullName(c.raw, &v)
	return helper.PtrToString(v)
}

func (c *BaseCatalog) FindTable(path []string) (Table, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.Catalog_FindTable(c.raw, helper.StringsToPtr(path), &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newBaseTable(v), nil
}

func (c *BaseCatalog) FindModel(path []string) (Model, error) {
	return nil, nil
}

func (c *BaseCatalog) FindConnection(path []string) (Connection, error) {
	return nil, nil
}

func (c *BaseCatalog) FindFunction(path []string) (*Function, error) {
	return nil, nil
}

func (c *BaseCatalog) FindTableValuedFunction(path []string) (TableValuedFunction, error) {
	return nil, nil
}

func (c *BaseCatalog) FindProcedure(path []string) (Procedure, error) {
	return nil, nil
}

func (c *BaseCatalog) FindType(path []string) (Type, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.Catalog_FindType(c.raw, unsafe.Pointer(&path), &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newType(v), nil
}

func (c *BaseCatalog) FindConstant(path []string) (Constant, error) {
	return nil, nil
}

func (c *BaseCatalog) FindConversion(from, to Type) (Conversion, error) {
	return nil, nil
}

func (c *BaseCatalog) ExtendedTypeSuperTypes(typ Type) (*TypeListView, error) {
	return nil, nil
}

func (c *BaseCatalog) SuggestTable(mistypedPath []string) string {
	var v unsafe.Pointer
	internal.Catalog_SuggestTable(c.raw, helper.StringsToPtr(mistypedPath), &v)
	return helper.PtrToString(v)
}

func (c *BaseCatalog) SuggestModel(mistypedPath []string) string {
	return ""
}

func (c *BaseCatalog) SuggestFunction(mistypedPath []string) string {
	return ""
}

func (c *BaseCatalog) SuggestTableValuedFunction(mistypedPath []string) string {
	return ""
}

func (c *BaseCatalog) SuggestConstant(mistypedPath []string) string {
	return ""
}

type BaseEnumerableCatalog struct {
	*BaseCatalog
}

func newBaseEnumerableCatalog(v unsafe.Pointer) *BaseEnumerableCatalog {
	if v == nil {
		return nil
	}
	return &BaseEnumerableCatalog{BaseCatalog: newBaseCatalog(v)}
}

func (c *BaseEnumerableCatalog) Catalogs() ([]Catalog, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.EnumerableCatalog_Catalogs(c.raw, &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	catalogs := *(*[]unsafe.Pointer)(unsafe.Pointer(&v))
	ret := make([]Catalog, 0, len(catalogs))
	for _, cat := range catalogs {
		ret = append(ret, newBaseCatalog(cat))
	}
	return ret, nil
}

func (c *BaseEnumerableCatalog) Tables() ([]Table, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.EnumerableCatalog_Tables(c.raw, &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	tables := *(*[]unsafe.Pointer)(unsafe.Pointer(&v))
	ret := make([]Table, 0, len(tables))
	for _, table := range tables {
		ret = append(ret, newBaseTable(table))
	}
	return ret, nil
}

func (c *BaseEnumerableCatalog) Types() ([]Type, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.EnumerableCatalog_Types(c.raw, &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	types := *(*[]unsafe.Pointer)(unsafe.Pointer(&v))
	ret := make([]Type, 0, len(types))
	for _, typ := range types {
		ret = append(ret, newType(typ))
	}
	return ret, nil
}

func (c *BaseEnumerableCatalog) Functions() ([]Function, error) {
	return nil, nil
}

func (c *BaseEnumerableCatalog) Conversions() ([]Conversion, error) {
	return nil, nil
}

type SimpleCatalog struct {
	*BaseEnumerableCatalog
}

func NewSimpleCatalog(name string) *SimpleCatalog {
	var v unsafe.Pointer
	internal.SimpleCatalog_new(helper.StringToPtr(name), &v)
	if v == nil {
		return nil
	}
	return &SimpleCatalog{
		BaseEnumerableCatalog: newBaseEnumerableCatalog(v),
	}
}

func (c *SimpleCatalog) Table(name string) (Table, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.SimpleCatalog_GetTable(c.raw, helper.StringToPtr(name), &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newBaseTable(v), nil
}

const uintptrSize = 4 << (^uintptr(0) >> 63)

func (c *SimpleCatalog) Tables() ([]Table, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.SimpleCatalog_GetTables(c.raw, &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	slice := (*reflect.SliceHeader)(v)
	ret := make([]Table, 0, slice.Len)
	for i := 0; i < slice.Len; i++ {
		p := *(*unsafe.Pointer)(unsafe.Pointer(slice.Data + uintptrSize*uintptr(i)))
		ret = append(ret, newBaseTable(p))
	}
	return ret, nil
}

func (c *SimpleCatalog) TableNames() []string {
	var num int
	internal.SimpleCatalog_table_names_num(c.raw, &num)
	ret := make([]string, 0, num)
	for i := 0; i < num; i++ {
		var v unsafe.Pointer
		internal.SimpleCatalog_table_name(c.raw, i, &v)
		ret = append(ret, helper.PtrToString(v))
	}
	return ret
}

func (c *SimpleCatalog) Model(name string) (Model, error) {
	return nil, nil
}

func (c *SimpleCatalog) Models() ([]Model, error) {
	return nil, nil
}

func (c *SimpleCatalog) ModelNames() []string {
	return nil
}

func (c *SimpleCatalog) Connection(name string) (Connection, error) {
	return nil, nil
}

func (c *SimpleCatalog) Function(name string) (*Function, error) {
	return nil, nil
}

func (c *SimpleCatalog) Functions() ([]Function, error) {
	return nil, nil
}

func (c *SimpleCatalog) FunctionNames() []string {
	return nil
}

func (c *SimpleCatalog) TableValuedFunction(name string) (TableValuedFunction, error) {
	return nil, nil
}

func (c *SimpleCatalog) TableValuedFunctions() ([]TableValuedFunction, error) {
	return nil, nil
}

func (c *SimpleCatalog) TableValuedFunctionNames() []string {
	return nil
}

func (c *SimpleCatalog) Procedure(name string) (Procedure, error) {
	return nil, nil
}

func (c *SimpleCatalog) Procedures() ([]Procedure, error) {
	return nil, nil
}

func (c *SimpleCatalog) Type(name string) (Type, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.SimpleCatalog_GetType(c.raw, helper.StringToPtr(name), &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newType(v), nil
}

func (c *SimpleCatalog) Types() ([]Type, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.SimpleCatalog_GetTypes(c.raw, &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	slice := (*reflect.SliceHeader)(v)
	ret := make([]Type, 0, slice.Len)
	for i := 0; i < slice.Len; i++ {
		p := *(*unsafe.Pointer)(unsafe.Pointer(slice.Data + uintptrSize*uintptr(i)))
		ret = append(ret, newType(p))
	}
	return ret, nil
}

func (c *SimpleCatalog) Catalog(name string) (Catalog, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.SimpleCatalog_GetCatalog(c.raw, helper.StringToPtr(name), &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newBaseCatalog(v), nil
}

func (c *SimpleCatalog) Catalogs() ([]Catalog, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.SimpleCatalog_GetCatalogs(c.raw, &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	slice := (*reflect.SliceHeader)(v)
	ret := make([]Catalog, 0, slice.Len)
	for i := 0; i < slice.Len; i++ {
		p := *(*unsafe.Pointer)(unsafe.Pointer(slice.Data + uintptrSize*uintptr(i)))
		ret = append(ret, newBaseCatalog(p))
	}
	return ret, nil
}

func (c *SimpleCatalog) CatalogNames() []string {
	var num int
	internal.SimpleCatalog_catalog_names_num(c.raw, &num)
	ret := make([]string, 0, num)
	for i := 0; i < num; i++ {
		var v unsafe.Pointer
		internal.SimpleCatalog_catalog_name(c.raw, i, &v)
		ret = append(ret, helper.PtrToString(v))
	}
	return ret
}

func (c *SimpleCatalog) Constant(name string) (Constant, error) {
	return nil, nil
}

func (c *SimpleCatalog) Constants() ([]Constant, error) {
	return nil, nil
}

func (c *SimpleCatalog) ConstantNames() []string {
	return nil
}

func (c *SimpleCatalog) AddTable(table Table) {
	internal.SimpleCatalog_AddTable(c.raw, table.getRaw())
}

func (c *SimpleCatalog) AddTableWithName(name string, table Table) {
	internal.SimpleCatalog_AddTableWithName(c.raw, helper.StringToPtr(name), table.getRaw())
}

func (c *SimpleCatalog) AddModel(model Model) {

}

func (c *SimpleCatalog) AddModelWithName(name string, model Model) {

}

func (c *SimpleCatalog) AddConnection(conn Connection) {

}

func (c *SimpleCatalog) AddConnectionWithName(name string, conn Connection) {

}

func (c *SimpleCatalog) AddType(name string, typ Type) {
	internal.SimpleCatalog_AddType(c.raw, helper.StringToPtr(name), typ.getRaw())
}

func (c *SimpleCatalog) AddTypeIfNotPresent(name string, typ Type) bool {
	var v bool
	internal.SimpleCatalog_AddTypeIfNotPresent(c.raw, helper.StringToPtr(name), typ.getRaw(), &v)
	return v
}

func (c *SimpleCatalog) AddCatalog(catalog Catalog) {
	internal.SimpleCatalog_AddCatalog(c.raw, catalog.getRaw())
}

func (c *SimpleCatalog) AddCatalogWithName(name string, catalog Catalog) {
	internal.SimpleCatalog_AddCatalogWithName(c.raw, helper.StringToPtr(name), catalog.getRaw())
}

func (c *SimpleCatalog) AddFunction(fn Function) {

}

func (c *SimpleCatalog) AddFunctionWithName(name string, fn Function) {

}

func (c *SimpleCatalog) AddTableValuedFunction(fn TableValuedFunction) {

}

func (c *SimpleCatalog) AddTableValuedFunctionWithName(name string, fn TableValuedFunction) {

}

func (c *SimpleCatalog) AddProcedure(proc Procedure) {

}

func (c *SimpleCatalog) AddProcedureWithName(name string, proc Procedure) {

}

func (c *SimpleCatalog) AddConstant(cons Constant) {

}

func (c *SimpleCatalog) AddConstantWithName(name string, cons Constant) {

}

func (c *SimpleCatalog) AddZetaSQLBuiltinFunctions() {
	internal.SimpleCatalog_AddZetaSQLFunctions(c.raw)
}

func getRawCatalog(c Catalog) unsafe.Pointer {
	return c.getRaw()
}
