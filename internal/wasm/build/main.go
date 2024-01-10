package main

import (
	"context"
	_ "embed"
	"fmt"
	"runtime"

	"github.com/tetratelabs/wazero"
	"github.com/tetratelabs/wazero/api"
	"github.com/tetratelabs/wazero/imports/emscripten"
	"github.com/tetratelabs/wazero/imports/wasi_snapshot_preview1"
)

//go:embed zetasql.wasm
var wasm []byte

type Bridge struct {
	mod    api.Module
	malloc api.Function
	free   api.Function
}

func NewBridge(mod api.Module) *Bridge {
	return &Bridge{
		mod:    mod,
		malloc: mod.ExportedFunction("malloc"),
		free:   mod.ExportedFunction("free"),
	}
}

type String struct {
	v   *string
	ptr uint64
	mod api.Module
}

func (s *String) Param() uint64 {
	return s.ptr
}

func (s *String) String() string {
	if s.v != nil {
		return *s.v
	}
	var (
		offset = uint32(s.ptr)
		bytes  []byte
	)
	for {
		b, ok := s.mod.Memory().Read(offset, 1)
		if !ok || b[0] == 0 {
			break
		}
		bytes = append(bytes, b...)
		offset++
	}
	v := string(bytes)
	s.v = &v
	return v
}

type Float32 float32

func (f Float32) Param() uint64 {
	return api.EncodeF32(float32(f))
}

type Float64 float64

func (f Float64) Param() uint64 {
	return api.EncodeF64(float64(f))
}

type Int32 int32

func (i Int32) Param() uint64 {
	return api.EncodeI32(int32(i))
}

type Int64 int64

func (i Int64) Param() uint64 {
	return api.EncodeI64(int64(i))
}

type Uint32 uint32

func (u Uint32) Param() uint64 {
	return api.EncodeU32(uint32(u))
}

type Uint64 uint64

func (u Uint64) Param() uint64 {
	return uint64(u)
}

func (b *Bridge) ToString(ctx context.Context, v string) (*String, error) {
	results, err := b.malloc.Call(ctx, uint64(len(v)))
	if err != nil {
		return nil, err
	}
	ptr := results[0]
	ret := &String{
		v:   &v,
		ptr: ptr,
		mod: b.mod,
	}
	if !b.mod.Memory().Write(uint32(ptr), []byte(v)) {
		return nil, fmt.Errorf("Memory.Write(%d, %d) out of range of memory size %d",
			ptr, len(v), b.mod.Memory().Size(),
		)
	}

	runtime.SetFinalizer(ret, func(v *String) {
		b.free.Call(ctx, v.ptr)
	})
	return ret, nil
}

func (b *Bridge) ToRawString(ptr uint64) *String {
	return &String{
		ptr: ptr,
		mod: b.mod,
	}
}

type Function struct {
	fn api.Function
}

type FunctionParam interface {
	Param() uint64
}

func (f *Function) Call(ctx context.Context, params ...FunctionParam) (uint64, error) {
	args := make([]uint64, 0, len(params))
	for _, param := range params {
		args = append(args, param.Param())
	}
	res, err := f.fn.Call(ctx, args...)
	if err != nil {
		return 0, err
	}
	if len(res) == 0 {
		return 0, err
	}
	return res[0], nil
}

func (b *Bridge) NewFunction(name string) *Function {
	fn := b.mod.ExportedFunction(name)
	return &Function{fn: fn}
}

func main() {
	ctx := context.Background()

	// Create a new WebAssembly Runtime.
	r := wazero.NewRuntime(ctx)
	defer r.Close(ctx) // This closes everything this Runtime created.

	wasi_snapshot_preview1.MustInstantiate(ctx, r)

	compiled, err := r.CompileModule(ctx, wasm)
	if err != nil {
		panic(err)
	}
	for k := range compiled.ExportedFunctions() {
		fmt.Println(k)
	}
	exporter, err := emscripten.NewFunctionExporterForModule(compiled)
	if err != nil {
		panic(err)
	}
	_ = exporter
}
