package helper

import (
	"reflect"
	"unsafe"
)
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

func PtrToStrings(p unsafe.Pointer) []string {
	slice := *(*[]*C.char)(p)
	ret := make([]string, 0, len(slice))
	for _, s := range slice {
		ret = append(ret, C.GoString(s))
	}
	return ret
}

const uintptrSize = 4 << (^uintptr(0) >> 63)

func PtrToSlice(p unsafe.Pointer, cb func(unsafe.Pointer)) {
	slice := (*reflect.SliceHeader)(p)
	for i := 0; i < slice.Len; i++ {
		cb(*(*unsafe.Pointer)(unsafe.Pointer(slice.Data + uintptr(i)*uintptrSize)))
	}
}

func SliceToPtr(v interface{}, cb func(int) unsafe.Pointer) unsafe.Pointer {
	rv := reflect.ValueOf(v)
	ret := make([]unsafe.Pointer, 0, rv.Len())
	for i := 0; i < rv.Len(); i++ {
		ret = append(ret, cb(i))
	}
	return *(*unsafe.Pointer)(unsafe.Pointer(&ret))
}
