package zetasql_test

import (
	"testing"

	"github.com/goccy/go-zetasql"
	"github.com/goccy/go-zetasql/resolved_ast"
	"github.com/goccy/go-zetasql/types"
)

type myCatalog struct {
	simpleCatalog *types.SimpleCatalog
	tables        []types.Table
	functions     []*types.Function
}

func (c *myCatalog) FullName() string {
	return "catalog"
}

func (c *myCatalog) FindTable(path []string) (types.Table, error) {
	tableName := path[len(path)-1]
	for _, table := range c.tables {
		if table.Name() == tableName {
			return table, nil
		}
	}
	return nil, nil
}

func (c *myCatalog) FindModel(path []string) (types.Model, error) {
	return nil, nil
}

func (c *myCatalog) FindConnection(path []string) (types.Connection, error) {
	return nil, nil
}

func (c *myCatalog) FindFunction(path []string) (*types.Function, error) {
	funcName := path[len(path)-1]
	for _, fn := range c.functions {
		if fn.Name() == funcName {
			return fn, nil
		}
	}
	return c.simpleCatalog.FindFunction(path)
}

func (c *myCatalog) FindTableValuedFunction(path []string) (types.TableValuedFunction, error) {
	return nil, nil
}

func (c *myCatalog) FindProcedure(path []string) (*types.Procedure, error) {
	return nil, nil
}

func (c *myCatalog) FindType(path []string) (types.Type, error) {
	return nil, nil
}

func (c *myCatalog) FindConstant(path []string) (types.Constant, int, error) {
	return nil, 0, nil
}

func (c *myCatalog) FindConversion(from, to types.Type) (types.Conversion, error) {
	return nil, nil
}

func (c *myCatalog) ExtendedTypeSuperTypes(typ types.Type) (*types.TypeListView, error) {
	return nil, nil
}

func (c *myCatalog) SuggestTable(mistypedPath []string) string {
	return ""
}

func (c *myCatalog) SuggestModel(mistypedPath []string) string {
	return ""
}

func (c *myCatalog) SuggestFunction(mistypedPath []string) string {
	return ""
}

func (c *myCatalog) SuggestTableValuedFunction(mistypedPath []string) string {
	return ""
}

func (c *myCatalog) SuggestConstant(mistypedPath []string) string {
	return ""
}

type myTable struct {
	name    string
	columns []types.Column
}

func (t *myTable) Name() string {
	return t.name
}

func (t *myTable) FullName() string {
	return t.name
}

func (t *myTable) NumColumns() int {
	return len(t.columns)
}

func (t *myTable) Column(idx int) types.Column {
	return t.columns[idx]
}

func (t *myTable) PrimaryKey() []int {
	return nil
}

func (t *myTable) FindColumnByName(name string) types.Column {
	return nil
}

func (t *myTable) IsValueTable() bool {
	return false
}

func (t *myTable) SerializationID() int64 {
	return 0
}

func (t *myTable) CreateEvaluatorTableIterator(columnIdxs []int) (*types.EvaluatorTableIterator, error) {
	return nil, nil
}

func (t *myTable) AnonymizationInfo() *types.AnonymizationInfo {
	return nil
}

func (t *myTable) SupportsAnonymization() bool {
	return false
}

func (t *myTable) TableTypeName(mode types.ProductMode) string {
	return ""
}

var (
	_ types.Catalog = &myCatalog{}
	_ types.Table   = &myTable{}
)

func TestCatalog(t *testing.T) {
	langOpt := zetasql.NewLanguageOptions()
	langOpt.SetNameResolutionMode(zetasql.NameResolutionDefault)
	langOpt.SetProductMode(types.ProductExternal)
	langOpt.SetEnabledLanguageFeatures([]zetasql.LanguageFeature{
		zetasql.FeatureTemplateFunctions,
	})
	langOpt.SetSupportedStatementKinds([]resolved_ast.Kind{resolved_ast.QueryStmt})
	opt := zetasql.NewAnalyzerOptions()
	opt.SetAllowUndeclaredParameters(true)
	opt.SetLanguage(langOpt)

	simpleCatalog := types.NewSimpleCatalog("simple")
	simpleCatalog.AddZetaSQLBuiltinFunctions(langOpt.BuiltinFunctionOptions())
	catalog := &myCatalog{
		simpleCatalog: simpleCatalog,
		tables: []types.Table{
			&myTable{
				name: "sample_table",
				columns: []types.Column{
					types.NewSimpleColumn("sample_table", "col1", types.Int64Type()),
				},
			},
		},
		functions: []*types.Function{
			types.NewFunction(
				[]string{"MY_FUNC"},
				"",
				types.ScalarMode,
				[]*types.FunctionSignature{
					types.NewFunctionSignature(
						types.NewFunctionArgumentType(
							types.StringType(),
							types.NewFunctionArgumentTypeOptions(types.RequiredArgumentCardinality),
						),
						[]*types.FunctionArgumentType{
							types.NewTemplatedFunctionArgumentType(
								types.ArgTypeAny1,
								types.NewFunctionArgumentTypeOptions(types.RequiredArgumentCardinality),
							),
						},
					),
				},
			),
		},
	}
	query := `SELECT * FROM sample_table WHERE MY_FUNC(1.0) = 'foo'`
	if _, err := zetasql.AnalyzeStatement(query, catalog, opt); err != nil {
		t.Fatal(err)
	}
}
