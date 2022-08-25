package types

import (
	"fmt"
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
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
	FindProcedure(path []string) (*Procedure, error)
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
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.Catalog_FindModel(c.raw, helper.StringsToPtr(path), &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newModel(v), nil
}

func (c *BaseCatalog) FindConnection(path []string) (Connection, error) {
	return nil, fmt.Errorf("unimplemented Catalog.FindConnection")
}

func (c *BaseCatalog) FindFunction(path []string) (*Function, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.Catalog_FindFunction(c.raw, helper.StringsToPtr(path), &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newFunction(v), nil
}

func (c *BaseCatalog) FindTableValuedFunction(path []string) (TableValuedFunction, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.Catalog_FindTableValuedFunction(c.raw, helper.StringsToPtr(path), &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newBaseTableValuedFunction(v), nil
}

func (c *BaseCatalog) FindProcedure(path []string) (*Procedure, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.Catalog_FindProcedure(c.raw, helper.StringsToPtr(path), &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newProcedure(v), nil
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
	return nil, fmt.Errorf("unimplemented Catalog.FindConstant")
}

func (c *BaseCatalog) FindConversion(from, to Type) (Conversion, error) {
	return nil, fmt.Errorf("unimplemented Catalog.FindConversion")
}

func (c *BaseCatalog) ExtendedTypeSuperTypes(typ Type) (*TypeListView, error) {
	return nil, fmt.Errorf("unimplemented Catalog.ExtendedTypeSuperTypes")
}

func (c *BaseCatalog) SuggestTable(mistypedPath []string) string {
	var v unsafe.Pointer
	internal.Catalog_SuggestTable(c.raw, helper.StringsToPtr(mistypedPath), &v)
	return helper.PtrToString(v)
}

func (c *BaseCatalog) SuggestModel(mistypedPath []string) string {
	var v unsafe.Pointer
	internal.Catalog_SuggestModel(c.raw, helper.StringsToPtr(mistypedPath), &v)
	return helper.PtrToString(v)
}

func (c *BaseCatalog) SuggestFunction(mistypedPath []string) string {
	var v unsafe.Pointer
	internal.Catalog_SuggestFunction(c.raw, helper.StringsToPtr(mistypedPath), &v)
	return helper.PtrToString(v)
}

func (c *BaseCatalog) SuggestTableValuedFunction(mistypedPath []string) string {
	var v unsafe.Pointer
	internal.Catalog_SuggestTableValuedTable(c.raw, helper.StringsToPtr(mistypedPath), &v)
	return helper.PtrToString(v)
}

func (c *BaseCatalog) SuggestConstant(mistypedPath []string) string {
	var v unsafe.Pointer
	internal.Catalog_SuggestConstant(c.raw, helper.StringsToPtr(mistypedPath), &v)
	return helper.PtrToString(v)
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
	ret := []Catalog{}
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newBaseCatalog(p))
	})
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
	ret := []Table{}
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newBaseTable(p))
	})
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
	var types []Type
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		types = append(types, newType(p))
	})
	return types, nil
}

func (c *BaseEnumerableCatalog) Functions() ([]*Function, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.EnumerableCatalog_Functions(c.raw, &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	var funcs []*Function
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		funcs = append(funcs, newFunction(p))
	})
	return funcs, nil
}

func (c *BaseEnumerableCatalog) Conversions() ([]Conversion, error) {
	return nil, fmt.Errorf("unimplemented EnumerableCatalog.Conversion")
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
	ret := []Table{}
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newBaseTable(p))
	})
	return ret, nil
}

func (c *SimpleCatalog) TableNames() []string {
	var v unsafe.Pointer
	internal.SimpleCatalog_table_names(c.raw, &v)
	return helper.PtrToStrings(v)
}

func (c *SimpleCatalog) Model(name string) (Model, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.SimpleCatalog_GetModel(c.raw, helper.StringToPtr(name), &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newModel(v), nil
}

func (c *SimpleCatalog) Connection(name string) (Connection, error) {
	return nil, fmt.Errorf("unimplemented SimpleCatalog.Connection")
}

func (c *SimpleCatalog) Function(name string) (*Function, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.SimpleCatalog_GetFunction(c.raw, helper.StringToPtr(name), &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newFunction(v), nil
}

func (c *SimpleCatalog) Functions() ([]*Function, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.SimpleCatalog_GetFunctions(c.raw, &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	ret := []*Function{}
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newFunction(p))
	})
	return ret, nil
}

func (c *SimpleCatalog) FunctionNames() []string {
	var v unsafe.Pointer
	internal.SimpleCatalog_function_names(c.raw, &v)
	return helper.PtrToStrings(v)
}

func (c *SimpleCatalog) TableValuedFunction(name string) (TableValuedFunction, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.SimpleCatalog_GetTableValuedFunction(c.raw, helper.StringToPtr(name), &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newBaseTableValuedFunction(v), nil
}

func (c *SimpleCatalog) TableValuedFunctions() []TableValuedFunction {
	var v unsafe.Pointer
	internal.SimpleCatalog_table_valued_functions(c.raw, &v)
	ret := []TableValuedFunction{}
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newBaseTableValuedFunction(p))
	})
	return ret
}

func (c *SimpleCatalog) TableValuedFunctionNames() []string {
	var v unsafe.Pointer
	internal.SimpleCatalog_table_valued_function_names(c.raw, &v)
	return helper.PtrToStrings(v)
}

func (c *SimpleCatalog) Procedure(name string) (*Procedure, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.SimpleCatalog_GetProcedure(c.raw, helper.StringToPtr(name), &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newProcedure(v), nil
}

func (c *SimpleCatalog) Procedures() []*Procedure {
	var v unsafe.Pointer
	internal.SimpleCatalog_procedures(c.raw, &v)
	ret := []*Procedure{}
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newProcedure(p))
	})
	return ret
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
	ret := []Type{}
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newType(p))
	})
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
	ret := []Catalog{}
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newBaseCatalog(p))
	})
	return ret, nil
}

func (c *SimpleCatalog) CatalogNames() []string {
	var v unsafe.Pointer
	internal.SimpleCatalog_catalog_names(c.raw, &v)
	return helper.PtrToStrings(v)
}

func (c *SimpleCatalog) Constant(name string) (Constant, error) {
	return nil, fmt.Errorf("unimplemented SimpleCatalog.Constant")
}

func (c *SimpleCatalog) Constants() ([]Constant, error) {
	return nil, fmt.Errorf("unimplemented SimpleCatalog.Constants")
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
	internal.SimpleCatalog_AddModel(c.raw, model.getRaw())
}

func (c *SimpleCatalog) AddModelWithName(name string, model Model) {
	internal.SimpleCatalog_AddModelWithName(c.raw, helper.StringToPtr(name), model.getRaw())
}

func (c *SimpleCatalog) AddConnection(conn Connection) {
	internal.SimpleCatalog_AddConnection(c.raw, conn.getRaw())
}

func (c *SimpleCatalog) AddConnectionWithName(name string, conn Connection) {
	internal.SimpleCatalog_AddConnectionWithName(c.raw, helper.StringToPtr(name), conn.getRaw())
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

func (c *SimpleCatalog) AddFunction(fn *Function) {
	internal.SimpleCatalog_AddFunction(c.raw, fn.raw)
}

func (c *SimpleCatalog) AddFunctionWithName(name string, fn *Function) {
	internal.SimpleCatalog_AddFunctionWithName(c.raw, helper.StringToPtr(name), fn.raw)
}

func (c *SimpleCatalog) AddTableValuedFunction(fn TableValuedFunction) {
	internal.SimpleCatalog_AddTableValuedFunction(c.raw, fn.getRaw())
}

func (c *SimpleCatalog) AddTableValuedFunctionWithName(name string, fn TableValuedFunction) {
	internal.SimpleCatalog_AddTableValuedFunctionWithName(c.raw, helper.StringToPtr(name), fn.getRaw())
}

func (c *SimpleCatalog) AddProcedure(proc *Procedure) {
	internal.SimpleCatalog_AddProcedure(c.raw, proc.raw)
}

func (c *SimpleCatalog) AddProcedureWithName(name string, proc *Procedure) {
	internal.SimpleCatalog_AddProcedureWithName(c.raw, helper.StringToPtr(name), proc.raw)
}

func (c *SimpleCatalog) AddConstant(cons Constant) {
	internal.SimpleCatalog_AddConstant(c.raw, cons.getRaw())
}

func (c *SimpleCatalog) AddConstantWithName(name string, cons Constant) {
	internal.SimpleCatalog_AddConstantWithName(c.raw, helper.StringToPtr(name), cons.getRaw())
}

func (c *SimpleCatalog) AddZetaSQLBuiltinFunctions(opt *BuiltinFunctionOptions) {
	if opt == nil {
		var langOpt unsafe.Pointer
		internal.LanguageOptions_new(&langOpt)
		internal.LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment(langOpt)
		var out unsafe.Pointer
		internal.BuiltinFunctionOptions_new(langOpt, &out)
		opt = &BuiltinFunctionOptions{raw: out}
	}
	internal.SimpleCatalog_AddZetaSQLFunctions(c.raw, opt.raw)
}

func getRawCatalog(c Catalog) unsafe.Pointer {
	return c.getRaw()
}
