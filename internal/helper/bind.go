package helper

import (
	"reflect"
	"unsafe"
)

/*
#include <stdlib.h>
#include <memory.h>

void assignptr(void *data, int i, void *p) {
  void **d = (void **)data;
  *(d + i) = p;
}
*/
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
	return SliceToPtr(s, func(idx int) unsafe.Pointer {
		return StringToPtr(s[idx])
	})
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

func IntPtr(v int) unsafe.Pointer {
	return *(*unsafe.Pointer)(unsafe.Pointer(&v))
}

func SliceToPtr(v interface{}, cb func(int) unsafe.Pointer) unsafe.Pointer {
	rv := reflect.ValueOf(v)
	slice := (*reflect.SliceHeader)(C.malloc(C.ulong(unsafe.Sizeof(reflect.SliceHeader{}))))
	ptrSize := C.ulong(unsafe.Sizeof(uintptr(1)))
	data := C.malloc(C.ulong(rv.Len()) * ptrSize)
	slice.Data = uintptr(data)
	slice.Len = rv.Len()
	slice.Cap = rv.Len()
	for i := 0; i < rv.Len(); i++ {
		C.assignptr(data, C.int(i), cb(i))
	}
	return unsafe.Pointer(slice)
}

type CPtrHolder struct {
	Ptr     unsafe.Pointer
	Handler unsafe.Pointer
}
