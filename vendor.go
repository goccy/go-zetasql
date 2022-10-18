// This file is intended to fix a bug that occurs with Go's go mod vendor and cgo combination.
// Normally, directories containing only C/C++ language files are ignored by go mod vendor, but go:embed forces them to be copied.
// If we do not use embed.FS to perform the operation, the generated binaries will not reflect the embedded files.
// See detail issue: https://github.com/golang/go/issues/26366
package zetasql

import (
	"embed"
)

//go:embed internal/ccall/*
var _ embed.FS
