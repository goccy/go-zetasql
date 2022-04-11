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

func PtrToString(p unsafe.Pointer) string {
	return C.GoString((*C.char)(p))
}

func StringsToPtr(s []string) unsafe.Pointer {
	data := make([]unsafe.Pointer, 0, len(s))
	for _, ss := range s {
		data = append(data, StringToPtr(ss))
	}
	return unsafe.Pointer(&data)
}
