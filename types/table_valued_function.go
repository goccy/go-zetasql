package types

import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
)

// TableValuedFunction this interface describes a table-valued function (TVF) available in a query
// engine.
//
// For reference, each call to the regular Function class:
//
// * accepts value (not relation) arguments only,
// * has a fixed list of (maybe templated) signatures and the function resolver
//   selects one concrete signature,
// * returns a single value.
//
// In contrast, each TVF call:
//
// * accepts scalar or relation arguments,
// * has a single signature specifying the types of input arguments,
// * returns a stream of rows,
// * has an output table schema (column names and types, or a value table)
//   computed by a method in this class, and not described in the signature.
//
// To resolve a TVF call, the resolver:
//
// (1) gets the signature (currently, only one signature is supported)
// (2) resolves all input arguments as values or as relations based on the
//     signature
// (3) prepares a TableValuedFunction.InputArgumentList from the resolved input
//     arguments
// (4) calls TableValuedFunction.Resolve, passing the input arguments, to get
//     a TableValuedFunctionCall object with the output schema for the TVF call
// (5) fills the output name list from the column names in the output schema
// (6) returns a TVFScanNode with the resolved arguments as children
type TableValuedFunction interface {
	Name() string
	FullName() string
	FunctionNamePath() []string
	NumSignatures() int64
	Signatures() []*FunctionSignature
	AddSignature(*FunctionSignature) error
	Signature(int64) *FunctionSignature
	SupportedSignaturesUserFacingText() string
	DebugString() string
	SetUserIdColumnNamePath(path []string) error
	AnonymizationInfo() *AnonymizationInfo
	getRaw() unsafe.Pointer
}

// TVFSignature contains information about a specific resolved TVF call. It
// includes the input arguments passed into the TVF call and also its output
// schema (including whether it is a value table). Engines may also subclass
// this to include more information if needed.
type TVFSignature struct {
	raw unsafe.Pointer
}

type BaseTableValuedFunction struct {
	raw unsafe.Pointer
}

func (f *BaseTableValuedFunction) Name() string {
	var v unsafe.Pointer
	internal.TableValuedFunction_Name(f.raw, &v)
	return helper.PtrToString(v)
}

func (f *BaseTableValuedFunction) FullName() string {
	var v unsafe.Pointer
	internal.TableValuedFunction_FullName(f.raw, &v)
	return helper.PtrToString(v)
}

func (f *BaseTableValuedFunction) FunctionNamePath() []string {
	var v unsafe.Pointer
	internal.TableValuedFunction_function_name_path(f.raw, &v)
	return helper.PtrToStrings(v)
}

func (f *BaseTableValuedFunction) NumSignatures() int64 {
	var v int
	internal.TableValuedFunction_NumSignatures(f.raw, &v)
	return int64(v)
}

func (f *BaseTableValuedFunction) Signatures() []*FunctionSignature {
	var v unsafe.Pointer
	internal.TableValuedFunction_signatures(f.raw, &v)
	ret := []*FunctionSignature{}
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, newFunctionSignature(p))
	})
	return ret
}

func (f *BaseTableValuedFunction) AddSignature(sig *FunctionSignature) error {
	var v unsafe.Pointer
	internal.TableValuedFunction_AddSignature(f.raw, sig.raw, &v)
	st := helper.NewStatus(v)
	if !st.OK() {
		return st.Error()
	}
	return nil
}

func (f *BaseTableValuedFunction) Signature(idx int64) *FunctionSignature {
	var v unsafe.Pointer
	internal.TableValuedFunction_GetSignature(f.raw, int(idx), &v)
	return newFunctionSignature(v)
}

func (f *BaseTableValuedFunction) SupportedSignaturesUserFacingText() string {
	var v unsafe.Pointer
	internal.TableValuedFunction_GetSupportedSignaturesUserFacingText(f.raw, &v)
	return helper.PtrToString(v)
}

func (f *BaseTableValuedFunction) DebugString() string {
	var v unsafe.Pointer
	internal.TableValuedFunction_DebugString(f.raw, &v)
	return helper.PtrToString(v)
}

func (f *BaseTableValuedFunction) SetUserIdColumnNamePath(path []string) error {
	var v unsafe.Pointer
	internal.TableValuedFunction_SetUserIdColumnNamePath(f.raw, helper.StringsToPtr(path), &v)
	st := helper.NewStatus(v)
	if !st.OK() {
		return st.Error()
	}
	return nil
}

func (f *BaseTableValuedFunction) AnonymizationInfo() *AnonymizationInfo {
	var v unsafe.Pointer
	internal.TableValuedFunction_anonymization_info(f.raw, &v)
	return newAnonymizationInfo(v)
}

func (f *BaseTableValuedFunction) getRaw() unsafe.Pointer {
	return f.raw
}

func NewSQLTableValuedFunction(createTableFunctionStmtPtr unsafe.Pointer) (*SQLTableValuedFunction, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.SQLTableValuedFunction_new(createTableFunctionStmtPtr, &v, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newSQLTableValuedFunction(v), nil
}

type SQLTableValuedFunction struct {
	*BaseTableValuedFunction
}

func newSQLTableValuedFunction(v unsafe.Pointer) *SQLTableValuedFunction {
	if v == nil {
		return nil
	}
	return &SQLTableValuedFunction{BaseTableValuedFunction: newBaseTableValuedFunction(v)}
}

func newBaseTableValuedFunction(v unsafe.Pointer) *BaseTableValuedFunction {
	if v == nil {
		return nil
	}
	return &BaseTableValuedFunction{raw: v}
}

func getRawTableValuedFunction(v TableValuedFunction) unsafe.Pointer {
	return v.getRaw()
}

func newTVFSignature(v unsafe.Pointer) *TVFSignature {
	return &TVFSignature{raw: v}
}

func getRawTVFSignature(v *TVFSignature) unsafe.Pointer {
	return v.raw
}
