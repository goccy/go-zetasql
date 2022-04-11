package zetasql

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
}
