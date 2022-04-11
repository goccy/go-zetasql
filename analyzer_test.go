package zetasql_test

import (
	"fmt"
	"testing"

	"github.com/goccy/go-zetasql"
)

func TestAnalyzer(t *testing.T) {
	const tableName = "z_table"
	catalog := zetasql.NewSimpleCatalog("z_catalog")
	catalog.AddTable(
		zetasql.NewSimpleTable(tableName, []zetasql.Column{
			zetasql.NewSimpleColumn(tableName, "col1", zetasql.Int64Type()),
			zetasql.NewSimpleColumn(tableName, "col2", zetasql.StringType()),
		}),
	)
	catalog.AddZetaSQLBuiltinFunctions()
	out, err := zetasql.AnalyzeStatement("SELECT * FROM z_table WHERE col1 = 1000", catalog)
	if err != nil {
		t.Fatal(err)
	}
	fmt.Println("out = ", out)
}
