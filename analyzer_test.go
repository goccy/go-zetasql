package zetasql_test

import (
	"testing"

	"github.com/goccy/go-zetasql"
	ast "github.com/goccy/go-zetasql/resolved_ast"
	"github.com/goccy/go-zetasql/types"
)

func TestAnalyzer(t *testing.T) {
	const tableName = "z_table"
	catalog := types.NewSimpleCatalog("z_catalog")
	catalog.AddTable(
		types.NewSimpleTable(tableName, []types.Column{
			types.NewSimpleColumn(tableName, "col1", types.Int64Type()),
			types.NewSimpleColumn(tableName, "col2", types.StringType()),
		}),
	)
	catalog.AddZetaSQLBuiltinFunctions()
	out, err := zetasql.AnalyzeStatement("SELECT * FROM z_table WHERE col1 = 1000", catalog)
	if err != nil {
		t.Fatal(err)
	}
	stmt := out.Statement()
	if err := ast.Walk(stmt, func(n ast.Node) error {
		t.Logf("%T %s", n, n.DebugString())
		return nil
	}); err != nil {
		t.Fatal(err)
	}
}
