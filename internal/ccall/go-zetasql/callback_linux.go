package zetasql

/*
#cgo CXXFLAGS: -std=c++1z
#cgo CXXFLAGS: -I../
#cgo CXXFLAGS: -I../protobuf
#cgo CXXFLAGS: -I../gtest
#cgo CXXFLAGS: -I../icu
#cgo CXXFLAGS: -I../re2
#cgo CXXFLAGS: -I../json
#cgo CXXFLAGS: -I../googleapis
#cgo CXXFLAGS: -I../flex/src
#cgo CXXFLAGS: -Wno-char-subscripts
#cgo CXXFLAGS: -Wno-sign-compare
#cgo CXXFLAGS: -Wno-switch
#cgo CXXFLAGS: -Wno-unused-function
#cgo CXXFLAGS: -Wno-deprecated-declarations
#cgo CXXFLAGS: -Wno-inconsistent-missing-override
#cgo CXXFLAGS: -Wno-unknown-attributes
#cgo CXXFLAGS: -Wno-macro-redefined
#cgo CXXFLAGS: -Wno-shift-count-overflow
#cgo CXXFLAGS: -Wno-enum-compare-switch
#cgo CXXFLAGS: -Wno-return-type
#cgo CXXFLAGS: -Wno-subobject-linkage
#cgo CXXFLAGS: -Wno-unknown-warning-option
#cgo CXXFLAGS: -DHAVE_PTHREAD
#cgo CXXFLAGS: -DU_COMMON_IMPLEMENTATION
#cgo LDFLAGS: -ldl

#define GO_EXPORT(API) export_zetasql_ ## API
#include "bridge.h"
#include "../go-absl/time/go_internal/cctz/time_zone/bridge.h"
*/
import "C"
import (
	"reflect"
	"runtime/cgo"
	"unsafe"

	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone"
)

type GoCatalog struct {
	FullName                   func() string
	FindTable                  func([]string) (unsafe.Pointer, error)
	FindModel                  func([]string) (unsafe.Pointer, error)
	FindConnection             func([]string) (unsafe.Pointer, error)
	FindFunction               func([]string) (unsafe.Pointer, error)
	FindTableValuedFunction    func([]string) (unsafe.Pointer, error)
	FindProcedure              func([]string) (unsafe.Pointer, error)
	FindType                   func([]string) (unsafe.Pointer, error)
	FindConstant               func([]string) (unsafe.Pointer, int, error)
	FindConversion             func(unsafe.Pointer, unsafe.Pointer) (unsafe.Pointer, error)
	ExtendedTypeSuperTypes     func(unsafe.Pointer) (unsafe.Pointer, error)
	SuggestTable               func([]string) string
	SuggestModel               func([]string) string
	SuggestFunction            func([]string) string
	SuggestTableValuedFunction func([]string) string
	SuggestConstant            func([]string) string
}

type GoTable struct {
	Name                         func() string
	FullName                     func() string
	NumColumns                   func() int
	Column                       func(int) unsafe.Pointer
	PrimaryKey                   func() []int
	FindColumnByName             func(name string) unsafe.Pointer
	IsValueTable                 func() bool
	SerializationID              func() int64
	CreateEvaluatorTableIterator func(columnIdxs []int) (unsafe.Pointer, error)
	AnonymizationInfo            func() unsafe.Pointer
	SupportsAnonymization        func() bool
	TableTypeName                func(int) string
}

const uintptrSize = 4 << (^uintptr(0) >> 63)

func ptrToSlice(p unsafe.Pointer, cb func(unsafe.Pointer)) {
	slice := (*reflect.SliceHeader)(p)
	for i := 0; i < slice.Len; i++ {
		cb(*(*unsafe.Pointer)(unsafe.Pointer(slice.Data + uintptr(i)*uintptrSize)))
	}
}

//export GoCatalog_FullName
func GoCatalog_FullName(v unsafe.Pointer) *C.char {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	return C.CString(cat.FullName())
}

//export GoCatalog_FindTable
func GoCatalog_FindTable(v unsafe.Pointer, pathPtr unsafe.Pointer, table *unsafe.Pointer, ret **C.char) {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	var path []string
	ptrToSlice(pathPtr, func(p unsafe.Pointer) {
		path = append(path, C.GoString((*C.char)(p)))
	})
	tablePtr, err := cat.FindTable(path)
	if err != nil {
		*ret = C.CString(err.Error())
	} else {
		*table = tablePtr
	}
}

//export GoCatalog_FindModel
func GoCatalog_FindModel(v unsafe.Pointer, pathPtr unsafe.Pointer, model *unsafe.Pointer, ret **C.char) {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	var path []string
	ptrToSlice(pathPtr, func(p unsafe.Pointer) {
		path = append(path, C.GoString((*C.char)(p)))
	})
	modelPtr, err := cat.FindModel(path)
	if err != nil {
		*ret = C.CString(err.Error())
	} else {
		*model = modelPtr
	}
}

//export GoCatalog_FindConnection
func GoCatalog_FindConnection(v unsafe.Pointer, pathPtr unsafe.Pointer, conn *unsafe.Pointer, ret **C.char) {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	var path []string
	ptrToSlice(pathPtr, func(p unsafe.Pointer) {
		path = append(path, C.GoString((*C.char)(p)))
	})
	connPtr, err := cat.FindConnection(path)
	if err != nil {
		*ret = C.CString(err.Error())
	} else {
		*conn = connPtr
	}
}

//export GoCatalog_FindFunction
func GoCatalog_FindFunction(v unsafe.Pointer, pathPtr unsafe.Pointer, fn *unsafe.Pointer, ret **C.char) {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	var path []string
	ptrToSlice(pathPtr, func(p unsafe.Pointer) {
		path = append(path, C.GoString((*C.char)(p)))
	})
	fnPtr, err := cat.FindFunction(path)
	if err != nil {
		*ret = C.CString(err.Error())
	} else {
		*fn = fnPtr
	}
}

//export GoCatalog_FindTableValuedFunction
func GoCatalog_FindTableValuedFunction(v unsafe.Pointer, pathPtr unsafe.Pointer, fn *unsafe.Pointer, ret **C.char) {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	var path []string
	ptrToSlice(pathPtr, func(p unsafe.Pointer) {
		path = append(path, C.GoString((*C.char)(p)))
	})
	fnPtr, err := cat.FindTableValuedFunction(path)
	if err != nil {
		*ret = C.CString(err.Error())
	} else {
		*fn = fnPtr
	}
}

//export GoCatalog_FindProcedure
func GoCatalog_FindProcedure(v unsafe.Pointer, pathPtr unsafe.Pointer, proc *unsafe.Pointer, ret **C.char) {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	var path []string
	ptrToSlice(pathPtr, func(p unsafe.Pointer) {
		path = append(path, C.GoString((*C.char)(p)))
	})
	procPtr, err := cat.FindProcedure(path)
	if err != nil {
		*ret = C.CString(err.Error())
	} else {
		*proc = procPtr
	}
}

//export GoCatalog_FindType
func GoCatalog_FindType(v unsafe.Pointer, pathPtr unsafe.Pointer, typ *unsafe.Pointer, ret **C.char) {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	var path []string
	ptrToSlice(pathPtr, func(p unsafe.Pointer) {
		path = append(path, C.GoString((*C.char)(p)))
	})
	typPtr, err := cat.FindType(path)
	if err != nil {
		*ret = C.CString(err.Error())
	} else {
		*typ = typPtr
	}
}

//export GoCatalog_FindConstant
func GoCatalog_FindConstant(v unsafe.Pointer, pathPtr unsafe.Pointer, numNamesConsumed *C.int, constant *unsafe.Pointer, ret **C.char) {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	var path []string
	ptrToSlice(pathPtr, func(p unsafe.Pointer) {
		path = append(path, C.GoString((*C.char)(p)))
	})
	consPtr, num, err := cat.FindConstant(path)
	if err != nil {
		*ret = C.CString(err.Error())
	} else {
		*numNamesConsumed = C.int(num)
		*constant = consPtr
	}
}

//export GoCatalog_FindConversion
func GoCatalog_FindConversion(v unsafe.Pointer, from unsafe.Pointer, to unsafe.Pointer, conv *unsafe.Pointer, ret **C.char) {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	convPtr, err := cat.FindConversion(from, to)
	if err != nil {
		*ret = C.CString(err.Error())
	} else {
		*conv = convPtr
	}
}

//export GoCatalog_ExtendedTypeSuperTypes
func GoCatalog_ExtendedTypeSuperTypes(v unsafe.Pointer, typ unsafe.Pointer, list *unsafe.Pointer, ret **C.char) {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	listPtr, err := cat.ExtendedTypeSuperTypes(typ)
	if err != nil {
		*ret = C.CString(err.Error())
	} else {
		*list = listPtr
	}
}

//export GoCatalog_SuggestTable
func GoCatalog_SuggestTable(v unsafe.Pointer, pathPtr unsafe.Pointer) *C.char {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	var path []string
	ptrToSlice(pathPtr, func(p unsafe.Pointer) {
		path = append(path, C.GoString((*C.char)(p)))
	})
	return C.CString(cat.SuggestTable(path))
}

//export GoCatalog_SuggestModel
func GoCatalog_SuggestModel(v unsafe.Pointer, pathPtr unsafe.Pointer) *C.char {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	var path []string
	ptrToSlice(pathPtr, func(p unsafe.Pointer) {
		path = append(path, C.GoString((*C.char)(p)))
	})
	return C.CString(cat.SuggestModel(path))
}

//export GoCatalog_SuggestFunction
func GoCatalog_SuggestFunction(v unsafe.Pointer, pathPtr unsafe.Pointer) *C.char {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	var path []string
	ptrToSlice(pathPtr, func(p unsafe.Pointer) {
		path = append(path, C.GoString((*C.char)(p)))
	})
	return C.CString(cat.SuggestFunction(path))
}

//export GoCatalog_SuggestTableValuedFunction
func GoCatalog_SuggestTableValuedFunction(v unsafe.Pointer, pathPtr unsafe.Pointer) *C.char {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	var path []string
	ptrToSlice(pathPtr, func(p unsafe.Pointer) {
		path = append(path, C.GoString((*C.char)(p)))
	})
	return C.CString(cat.SuggestTableValuedFunction(path))
}

//export GoCatalog_SuggestConstant
func GoCatalog_SuggestConstant(v unsafe.Pointer, pathPtr unsafe.Pointer) *C.char {
	h := *(*cgo.Handle)(v)
	cat := h.Value().(*GoCatalog)
	var path []string
	ptrToSlice(pathPtr, func(p unsafe.Pointer) {
		path = append(path, C.GoString((*C.char)(p)))
	})
	return C.CString(cat.SuggestConstant(path))
}

//export GoTable_Name
func GoTable_Name(v unsafe.Pointer) *C.char {
	h := *(*cgo.Handle)(v)
	table := h.Value().(*GoTable)
	return C.CString(table.Name())
}

//export GoTable_FullName
func GoTable_FullName(v unsafe.Pointer) *C.char {
	h := *(*cgo.Handle)(v)
	table := h.Value().(*GoTable)
	return C.CString(table.FullName())
}

//export GoTable_NumColumns
func GoTable_NumColumns(v unsafe.Pointer) C.int {
	h := *(*cgo.Handle)(v)
	table := h.Value().(*GoTable)
	return C.int(table.NumColumns())
}

//export GoTable_Column
func GoTable_Column(v unsafe.Pointer, idx C.int) unsafe.Pointer {
	h := *(*cgo.Handle)(v)
	table := h.Value().(*GoTable)
	return table.Column(int(idx))
}

//export GoTable_PrimaryKey
func GoTable_PrimaryKey(v unsafe.Pointer) unsafe.Pointer {
	h := *(*cgo.Handle)(v)
	table := h.Value().(*GoTable)
	keys := table.PrimaryKey()
	return unsafe.Pointer(&keys)
}

//export GoTable_FindColumnByName
func GoTable_FindColumnByName(v unsafe.Pointer, name *C.char) unsafe.Pointer {
	h := *(*cgo.Handle)(v)
	table := h.Value().(*GoTable)
	return table.FindColumnByName(C.GoString(name))
}

//export GoTable_IsValueTable
func GoTable_IsValueTable(v unsafe.Pointer) C.int {
	h := *(*cgo.Handle)(v)
	table := h.Value().(*GoTable)
	if table.IsValueTable() {
		return 1
	}
	return 0
}

//export GoTable_SerializationID
func GoTable_SerializationID(v unsafe.Pointer) C.int64_t {
	h := *(*cgo.Handle)(v)
	table := h.Value().(*GoTable)
	return C.int64_t(table.SerializationID())
}

//export GoTable_CreateEvaluatorTableIterator
func GoTable_CreateEvaluatorTableIterator(v unsafe.Pointer, columnIdxsPtr unsafe.Pointer, iter *unsafe.Pointer, ret **C.char) {
	h := *(*cgo.Handle)(v)
	table := h.Value().(*GoTable)
	var idxs []int
	ptrToSlice(columnIdxsPtr, func(p unsafe.Pointer) {
		idxs = append(idxs, int(uintptr(p)))
	})
	iterPtr, err := table.CreateEvaluatorTableIterator(idxs)
	if err != nil {
		*ret = C.CString(err.Error())
	} else {
		*iter = iterPtr
	}
}

//export GoTable_AnonymizationInfo
func GoTable_AnonymizationInfo(v unsafe.Pointer) unsafe.Pointer {
	h := *(*cgo.Handle)(v)
	table := h.Value().(*GoTable)
	return table.AnonymizationInfo()
}

//export GoTable_SupportsAnonymization
func GoTable_SupportsAnonymization(v unsafe.Pointer) C.int {
	h := *(*cgo.Handle)(v)
	table := h.Value().(*GoTable)
	if table.SupportsAnonymization() {
		return 1
	}
	return 0
}

//export GoTable_TableTypeName
func GoTable_TableTypeName(v unsafe.Pointer, mode C.int) *C.char {
	h := *(*cgo.Handle)(v)
	table := h.Value().(*GoTable)
	return C.CString(table.TableTypeName(int(mode)))
}
