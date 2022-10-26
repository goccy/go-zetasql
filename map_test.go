package zetasql_test

import (
	"testing"

	"github.com/goccy/go-zetasql"
	"github.com/goccy/go-zetasql/resolved_ast"
	"github.com/goccy/go-zetasql/types"
)

func TestNodeMap(t *testing.T) {
	const tableName = "z_table"
	catalog := types.NewSimpleCatalog("z_catalog")
	catalog.AddTable(
		types.NewSimpleTable(tableName, []types.Column{
			types.NewSimpleColumn(tableName, "col1", types.Int64Type()),
			types.NewSimpleColumn(tableName, "col2", types.StringType()),
		}),
	)
	catalog.AddZetaSQLBuiltinFunctions(nil)
	langOpt := zetasql.NewLanguageOptions()
	langOpt.SetNameResolutionMode(zetasql.NameResolutionDefault)
	langOpt.SetProductMode(types.ProductExternal)
	langOpt.SetSupportedStatementKinds([]resolved_ast.Kind{resolved_ast.QueryStmt})
	opt := zetasql.NewAnalyzerOptions()
	opt.SetAllowUndeclaredParameters(true)
	opt.SetLanguage(langOpt)
	opt.SetParseLocationRecordType(zetasql.ParseLocationRecordFullNodeScope)

	query := `SELECT SUM(col1), col2 FROM z_table GROUP BY col2 HAVING SUM(col1) > 100`

	analyzerOut, err := zetasql.AnalyzeStatement(query, catalog, opt)
	if err != nil {
		t.Fatal(err)
	}
	node, err := zetasql.ParseStatement(query, nil)
	if err != nil {
		t.Fatal(err)
	}

	resolvedNode := analyzerOut.Statement()
	nodeMap := zetasql.NewNodeMap(resolvedNode, node)

	_ = resolved_ast.Walk(resolvedNode, func(n resolved_ast.Node) error {
		found := nodeMap.FindNodeFromResolvedNode(n)
		if len(found) == 0 {
			t.Fatal("failed to find node")
		}
		return nil
	})
}
