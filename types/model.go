package types

import "unsafe"

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

type model struct {
	raw unsafe.Pointer
}

func (m *model) Name() string {
	return ""
}

func (m *model) FullName() string {
	return ""
}

func (m *model) NumInputs() uint64 {
	return 0
}

func (m *model) Input(int) Column {
	return nil
}

func (m *model) NumOutputs() uint64 {
	return 0
}

func (m *model) Output(int) Column {
	return nil
}

func (m *model) FindInputByName(name string) Column {
	return nil
}

func (m *model) FindOutputByName(name string) Column {
	return nil
}

func (m *model) SerializationID() int64 {
	return 0
}

func (m *model) getRaw() unsafe.Pointer {
	return nil
}

func newModel(v unsafe.Pointer) Model {
	return &model{raw: v}
}

func getRawModel(v Model) unsafe.Pointer {
	return v.getRaw()
}
