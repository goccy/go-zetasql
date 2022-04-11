package zetasql

type Connection interface {
	Name() string
	FullName() string
}
