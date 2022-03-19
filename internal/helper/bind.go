package helper

import "unsafe"
import "C"

func BoolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func StringToPtr(s string) unsafe.Pointer {
	return unsafe.Pointer(C.CString(s))
}
