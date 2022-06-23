package types

import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
)

type Model interface {
	Name() string
	FullName() string
	NumInputs() uint64
	Input(int) Column
	NumOutputs() uint64
	Output(int) Column
	FindInputByName(name string) Column
	FindOutputByName(name string) Column
	SerializationID() int64
	getRaw() unsafe.Pointer
}

type BaseModel struct {
	raw unsafe.Pointer
}

func (m *BaseModel) Name() string {
	var v unsafe.Pointer
	internal.Model_Name(m.raw, &v)
	return helper.PtrToString(v)
}

func (m *BaseModel) FullName() string {
	var v unsafe.Pointer
	internal.Model_FullName(m.raw, &v)
	return helper.PtrToString(v)
}

func (m *BaseModel) NumInputs() uint64 {
	var v int
	internal.Model_NumInputs(m.raw, &v)
	return uint64(v)
}

func (m *BaseModel) Input(i int) Column {
	var v unsafe.Pointer
	internal.Model_Input(m.raw, i, &v)
	return newBaseColumn(v)
}

func (m *BaseModel) NumOutputs() uint64 {
	var v int
	internal.Model_NumOutputs(m.raw, &v)
	return uint64(v)
}

func (m *BaseModel) Output(i int) Column {
	var v unsafe.Pointer
	internal.Model_Output(m.raw, i, &v)
	return newBaseColumn(v)
}

func (m *BaseModel) FindInputByName(name string) Column {
	var v unsafe.Pointer
	internal.Model_FindInputByName(m.raw, helper.StringToPtr(name), &v)
	return newBaseColumn(v)
}

func (m *BaseModel) FindOutputByName(name string) Column {
	var v unsafe.Pointer
	internal.Model_FindOutputByName(m.raw, helper.StringToPtr(name), &v)
	return newBaseColumn(v)
}

func (m *BaseModel) SerializationID() int64 {
	var v int
	internal.Model_SerializationID(m.raw, &v)
	return int64(v)
}

func (m *BaseModel) getRaw() unsafe.Pointer {
	return m.raw
}

func newBaseModel(v unsafe.Pointer) *BaseModel {
	if v == nil {
		return nil
	}
	return &BaseModel{raw: v}
}

func newModel(v unsafe.Pointer) *SimpleModel {
	if v == nil {
		return nil
	}
	return &SimpleModel{BaseModel: newBaseModel(v)}
}

func getRawModel(v Model) unsafe.Pointer {
	return v.getRaw()
}

type SimpleModel struct {
	*BaseModel
}

func (m *SimpleModel) AddInput(column Column) error {
	var v unsafe.Pointer
	internal.SimpleModel_AddInput(m.raw, column.getRaw(), &v)
	st := helper.NewStatus(v)
	if !st.OK() {
		return st.Error()
	}
	return nil
}

func (m *SimpleModel) AddOutput(column Column) error {
	var v unsafe.Pointer
	internal.SimpleModel_AddOutput(m.raw, column.getRaw(), &v)
	st := helper.NewStatus(v)
	if !st.OK() {
		return st.Error()
	}
	return nil
}

func NewSimpleModel(name string, inputs []Column, outputs []Column) *SimpleModel {
	var v unsafe.Pointer
	internal.SimpleModel_new(
		helper.StringToPtr(name),
		helper.SliceToPtr(inputs, func(idx int) unsafe.Pointer {
			return inputs[idx].getRaw()
		}),
		helper.SliceToPtr(outputs, func(idx int) unsafe.Pointer {
			return outputs[idx].getRaw()
		}),
		&v,
	)
	return &SimpleModel{BaseModel: newBaseModel(v)}
}
