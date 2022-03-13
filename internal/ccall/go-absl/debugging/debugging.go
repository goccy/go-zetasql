package debugging

import (
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/debugging/debugging_internal"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/debugging/demangle_internal"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/debugging/examine_stack"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/debugging/failure_signal_handler"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/debugging/leak_check"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/debugging/leak_check_disable"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/debugging/stack_consumption"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/debugging/stacktrace"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/debugging/symbolize"
)
