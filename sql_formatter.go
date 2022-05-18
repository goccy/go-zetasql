package zetasql

import "C"
import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
)

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
