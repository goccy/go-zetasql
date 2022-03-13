package cord_rep_test_util

/*
#cgo CXXFLAGS: -std=c++11
#cgo CXXFLAGS: -I../../../
*/
import "C"

import (
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/base/config"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/base/raw_logging_internal"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/strings/cord_internal"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/strings/strings"
)
