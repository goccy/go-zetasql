package types_test

import (
	"testing"

	"github.com/goccy/go-zetasql/types"
)

func TestCatalog(t *testing.T) {
	const tableName = "z_table"

	catalog := types.NewSimpleCatalog("z_catalog")
	catalog.AddTable(
		types.NewSimpleTable(tableName, []types.Column{
			types.NewSimpleColumn(tableName, "col1", types.Int64Type()),
			types.NewSimpleColumn(tableName, "col2", types.StringType()),
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
