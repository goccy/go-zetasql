package zetasql_test

import (
	"fmt"
	"testing"

	"github.com/goccy/go-zetasql"
	"github.com/goccy/go-zetasql/ast"
)

func TestParser(t *testing.T) {
	stmt, err := zetasql.ParseStatement("SELECT * FROM Samples WHERE id = 1", nil)
	if err != nil {
		t.Fatal(err)
	}
	queryStmt := stmt.(*ast.QueryStatementNode)
	queryExpr := queryStmt.Query().QueryExpr()
	switch expr := queryExpr.(type) {
	case *ast.SelectNode:
		for _, col := range expr.SelectList().Columns() {
			colExpr := col.Expression()
			switch colExpr.(type) {
			case *ast.StarNode:
			default:
				fmt.Printf("col is %T\n", colExpr)
			}
		}
		fromClause := expr.FromClause()
		if fromClause != nil {
			tableExpr := fromClause.TableExpression()
			switch expr := tableExpr.(type) {
			case *ast.TablePathExpressionNode:
				for _, ident := range expr.PathExpr().Names() {
					fmt.Println("table name = ", ident.Name())
				}
			}
		}
		whereClause := expr.WhereClause()
		if whereClause != nil {
			whereExpr := whereClause.Expression()
			switch expr := whereExpr.(type) {
			case *ast.BinaryExpressionNode:
				fmt.Println("op = ", expr.Op())
				for _, ident := range expr.Lhs().(*ast.PathExpressionNode).Names() {
					fmt.Println("op name = ", ident.Name())
				}
				val, err := expr.Rhs().(*ast.IntLiteralNode).Value()
				if err != nil {
					t.Fatal(err)
				}
				fmt.Println("value = ", val)
			}
		}
	}
}

func TestWalk(t *testing.T) {
	for _, test := range []struct {
		name  string
		query string
	}{
		// from https://cloud.google.com/spanner/docs/structs
		{"struct", "SELECT SingerId FROM SINGERS WHERE (FirstName, LastName) = @singerinfo"},
		{"struct array", "SELECT SingerId FROM SINGERS WHERE STRUCT<FirstName STRING, LastName STRING>(FirstName, LastName) IN UNNEST(@names)"},
		{"struct update", "Update Singers Set LastName = 'Grant' WHERE STRUCT<FirstName String, LastName String>(Firstname, LastName) = @name"},
		{"struct field", "SELECT SingerId FROM SINGERS WHERE FirstName = @name.FirstName"},
		{"struct with array field", "SELECT SingerId, @songinfo.SongName FROM Singers WHERE STRUCT<FirstName STRING, LastName STRING>(FirstName, LastName) IN UNNEST(@songinfo.ArtistNames)"},
	} {
		t.Run(test.name, func(t *testing.T) {
			stmt, err := zetasql.ParseStatement(test.query, zetasql.NewParserOptions())
			if err != nil {
				t.Fatal(err)
			}
			ast.Walk(stmt, func(n ast.Node) error {
				fmt.Printf("node = %T loc:%s\n", n, n.ParseLocationRange())
				return nil
			})
		})
	}
}
