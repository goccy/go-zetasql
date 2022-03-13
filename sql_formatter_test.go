package zetasql_test

import (
	"fmt"
	"testing"

	"github.com/goccy/go-zetasql"
)

func TestSQLFormatter(t *testing.T) {
	formatted, err := zetasql.FormatSQL("SELECT * FROM Tables WHERE id = 1")
	if err != nil {
		t.Fatal(err)
	}
	fmt.Println("formatted = ", formatted)
}
