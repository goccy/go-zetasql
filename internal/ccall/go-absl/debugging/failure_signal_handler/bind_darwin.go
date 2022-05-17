package failure_signal_handler

/*
#cgo CXXFLAGS: -std=c++11
#cgo CXXFLAGS: -I../../../
#cgo CXXFLAGS: -I../../../protobuf
#cgo CXXFLAGS: -I../../../gtest
#cgo CXXFLAGS: -I../../../icu
#cgo CXXFLAGS: -I../../../re2
#cgo CXXFLAGS: -I../../../json
#cgo CXXFLAGS: -I../../../googleapis
#cgo CXXFLAGS: -I../../../flex/src
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

#define GO_EXPORT(API) export_absl_debugging_failure_signal_handler_ ## API
#include "bridge.h"
*/
import "C"
import ()
