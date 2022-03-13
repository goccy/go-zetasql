package name_scope

/*
#cgo CXXFLAGS: -std=c++17
#cgo CXXFLAGS: -I../../../
#cgo CXXFLAGS: -I../../../protobuf
#cgo CXXFLAGS: -I../../../gtest
#cgo CXXFLAGS: -I../../../icu
#cgo CXXFLAGS: -Wno-char-subscripts
#cgo CXXFLAGS: -Wno-sign-compare
#cgo CXXFLAGS: -Wno-switch
#cgo CXXFLAGS: -Wno-unused-function
#cgo CXXFLAGS: -Wno-deprecated-declarations
#cgo CXXFLAGS: -Wno-inconsistent-missing-override
#cgo CXXFLAGS: -Wno-unknown-attributes
*/
import "C"

import (
	_ "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/base/base"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/base/map_util"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/base/ret_check"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/base/status"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/public/catalog"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/public/id_string"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/public/strings"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/public/type"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/resolved_ast/resolved_ast"

	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/container/flat_hash_map"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/memory/memory"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/status/status"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/status/statusor"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/strings/strings"
)
