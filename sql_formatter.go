package zetasql

import "C"
import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
)

// FormatSQL formats ZetaSQL statements.
// Multiple statements separated by semi-colons are supported.
//
// On return, the first return value is always populated with equivalent SQL.
// The returned error contains the concatenation of any errors that
// occurred while parsing the statements.
//
// Any statements that fail to parse as valid ZetaSQL are returned unchanged.
// All valid statements will be reformatted.
//
// CAVEATS:
// 1. This can only reformat SQL statements that can be parsed successfully.
// Statements that cannot be parsed are returned unchanged.
// 2. Comments are stripped in the formatted output.
func FormatSQL(sql string) (string, error) {
	var (
		out    unsafe.Pointer
		status unsafe.Pointer
	)
	internal.FormatSql(unsafe.Pointer(C.CString(sql)), &out, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return "", st.Error()
	}
	return C.GoString((*C.char)(out)), nil
}
