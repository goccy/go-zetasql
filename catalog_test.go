package zetasql_test

import (
	"testing"

	"github.com/goccy/go-zetasql"
)

func TestCatalog(t *testing.T) {
	const tableName = "z_table"

	catalog := zetasql.NewSimpleCatalog("z_catalog")
	catalog.AddTable(
		zetasql.NewSimpleTable(tableName, []zetasql.Column{
			zetasql.NewSimpleColumn(tableName, "col1", zetasql.Int64Type()),
			zetasql.NewSimpleColumn(tableName, "col2", zetasql.StringType()),
		}),
	)
	catalog.AddZetaSQLBuiltinFunctions()
	tables, err := catalog.Tables()
	if err != nil {
		t.Fatal(err)
	}
	if len(tables) != 1 {
		t.Fatalf("failed to get tables: %d", len(tables))
	}
	if tables[0].Name() != tableName {
		t.Fatalf("failed to get table name exp:%s got:%s", tableName, tables[0].Name())
	}
}
