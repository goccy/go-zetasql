package pkg

import (
	"bufio"
	"bytes"
	"embed"
	"fmt"
	"go/format"
	"io/fs"
	"log"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"text/template"
)

var (
	bazelSupportedLibs = []string{"zetasql", "absl"}
	includeDirs        = []string{"protobuf", "gtest", "icu", "re2", "json", "googleapis", "flex/src"}
)

type Generator struct {
	buildFileParser               *BuildFileParser
	cfg                           *Config
	bridge                        *Bridge
	importSymbol                  *ImportSymbol
	libMap                        map[string]*Lib
	pkgMap                        map[string]Package
	importSymbolPackageMap        map[string]Package
	containsConflictSymbolFileMap map[string]ConflictSymbol
	containsAddSourceFileMap      map[string]SourceConfig
	pkgToAllDeps                  map[string][]string
	internalExportNames           []string
	templates                     embed.FS
}

func NewGenerator(cfg *Config, bridge *Bridge, importSymbol *ImportSymbol, templates embed.FS) *Generator {
	containsConflictSymbolFileMap := map[string]ConflictSymbol{}
	for _, sym := range cfg.ConflictSymbols {
		sym := sym
		containsConflictSymbolFileMap[sym.File] = sym
	}
	containsAddSourceFileMap := map[string]SourceConfig{}
	for _, src := range cfg.AddSources {
		src := src
		containsAddSourceFileMap[src.File] = src
	}
	pkgMap := map[string]Package{}
	for _, pkg := range bridge.Packages {
		pkg := pkg
		pkgMap[pkg.Name] = pkg
	}
	importSymbolPackageMap := map[string]Package{}
	for _, pkg := range importSymbol.Packages {
		pkg := pkg
		importSymbolPackageMap[pkg.Name] = pkg
		pkgMap[pkg.Name] = pkg // merge import symbols to package map
	}
	return &Generator{
		buildFileParser:               NewBuildFileParser(cfg),
		cfg:                           cfg,
		bridge:                        bridge,
		importSymbol:                  importSymbol,
		templates:                     templates,
		containsConflictSymbolFileMap: containsConflictSymbolFileMap,
		containsAddSourceFileMap:      containsAddSourceFileMap,
		importSymbolPackageMap:        importSymbolPackageMap,
		pkgMap:                        pkgMap,
	}
}

func (g *Generator) Generate() error {
	parsedFiles, err := g.createParsedFiles()
	if err != nil {
		return err
	}
	g.libMap = g.createLibMap(parsedFiles)
	pkgToAllDeps, err := g.createAllDependencyMap(parsedFiles)
	if err != nil {
		return err
	}
	g.pkgToAllDeps = pkgToAllDeps
	internalExportNames, err := g.protobufInternalExportNames(parsedFiles)
	if err != nil {
		return err
	}
	g.internalExportNames = internalExportNames
	for _, parsedFile := range parsedFiles {
		if err := g.generate(parsedFile); err != nil {
			return err
		}
	}
	dummyGo, err := g.templates.ReadFile("templates/dummy.go.tmpl")
	if err != nil {
		return err
	}
	for _, dir := range append(includeDirs, "zetasql", "absl") {
		if err := filepath.Walk(filepath.Join(ccallDir(), dir), func(path string, info fs.FileInfo, err error) error {
			if err != nil {
				return err
			}
			if info.IsDir() {
				if err := os.WriteFile(filepath.Join(path, "dummy.go"), dummyGo, 0o600); err != nil {
					return err
				}
			}
			return nil
		}); err != nil {
			return err
		}
	}
	return nil
}

func (g *Generator) createParsedFiles() ([]*ParsedFile, error) {
	var parsedFiles []*ParsedFile
	for _, lib := range bazelSupportedLibs {
		srcPath := toSourceDirFromLibName(lib)
		if err := filepath.Walk(srcPath, func(path string, info fs.FileInfo, err error) error {
			if err != nil {
				return fmt.Errorf("unexpected error in walk: %w", err)
			}
			switch filepath.Base(path) {
			case "BUILD", "BUILD.bazel":
				f, err := g.buildFileParser.Parse(path)
				if err != nil {
					return err
				}
				parsedFiles = append(parsedFiles, f)
			}
			return nil
		}); err != nil {
			return nil, err
		}
	}
	return parsedFiles, nil
}

func (g *Generator) createLibMap(parsedFiles []*ParsedFile) map[string]*Lib {
	cclibMap := map[string]*Lib{}
	for _, parsedFile := range parsedFiles {
		for _, cclib := range parsedFile.cclibs {
			srcPkgName := fmt.Sprintf("%s/%s", cclib.BasePkg, cclib.Name)
			cclibMap[srcPkgName] = cclib
		}
	}
	for _, dep := range g.cfg.Dependencies {
		cclibdeps := make([]Dependency, 0, len(dep.Deps))
		for _, d := range dep.Deps {
			cclibdeps = append(cclibdeps, Dependency{
				BasePkg: d.Base,
				Pkg:     d.Pkg,
			})
		}
		cclibMap[fmt.Sprintf("%s/%s", dep.Name, dep.Name)] = &Lib{
			BasePkg: dep.Name,
			Name:    dep.Name,
			Deps:    cclibdeps,
		}
	}
	return cclibMap
}

func (g *Generator) createAllDependencyMap(parsedFiles []*ParsedFile) (map[string][]string, error) {
	pkgToAllDeps := map[string][]string{}
	for pkgName, lib := range g.libMap {
		pkgMap := map[string]struct{}{}
		if err := g.resolveDeps(pkgMap, lib); err != nil {
			return nil, err
		}
		sorted := []string{}
		for k := range pkgMap {
			lib, exists := g.libMap[k]
			if exists {
				if len(lib.Sources) == 0 || lib.headerOnly() {
					continue
				}
			}
			sorted = append(sorted, k)
		}
		sort.Strings(sorted)
		pkgToAllDeps[pkgName] = sorted
	}
	return pkgToAllDeps, nil
}

func (g *Generator) resolveDeps(pkgMap map[string]struct{}, lib *Lib) error {
	pkgName := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	for _, dep := range lib.Deps {
		dep := dep
		depPkgName := fmt.Sprintf("%s/%s", dep.BasePkg, dep.Pkg)
		if _, exists := pkgMap[depPkgName]; exists {
			continue
		}
		lib, exists := g.libMap[depPkgName]
		if exists {
			if err := g.resolveDeps(pkgMap, lib); err != nil {
				return err
			}
		}
	}
	pkgMap[pkgName] = struct{}{}
	return nil
}

func (g *Generator) protobufInternalExportNames(parsedFiles []*ParsedFile) ([]string, error) {
	internalExportNames := []string{}
	for _, path := range g.cfg.ProtobufInternalExportNameFiles {
		internalExportName, err := g.headerPathToInternalExportName(filepath.Join(ccallDir(), path))
		if err != nil {
			return nil, err
		}
		internalExportNames = append(internalExportNames, internalExportName)
	}
	for _, parsedFile := range parsedFiles {
		for _, ccproto := range parsedFile.ccprotos {
			for _, header := range ccproto.Headers {
				headerPath := filepath.Join(ccallDir(), ccproto.BasePkg, header)
				internalExportName, err := g.headerPathToInternalExportName(headerPath)
				if err != nil {
					return nil, err
				}
				internalExportNames = append(internalExportNames, internalExportName)
			}
		}
	}
	return internalExportNames, nil
}

func (g *Generator) headerPathToInternalExportName(path string) (string, error) {
	f, err := os.Open(path)
	if err != nil {
		return "", err
	}
	defer f.Close()
	scanner := bufio.NewScanner(f)
	for scanner.Scan() {
		text := scanner.Text()
		if strings.HasPrefix(text, "#define PROTOBUF_INTERNAL_EXPORT") {
			splitted := strings.Split(text, " ")
			return splitted[1][len("PROTOBUF_INTERNAL_EXPORT_"):], nil
		}
	}
	if err := scanner.Err(); err != nil {
		return "", err
	}
	return "", fmt.Errorf("failed to find PROTOBUF_INTERNAL_EXPORT in %s", path)
}

func (g *Generator) generate(f *ParsedFile) error {
	for _, lib := range f.cclibs {
		outputDir := filepath.Join(ccallDir(), goPkgPath(lib.BasePkg, lib.Name))
		if err := g.generateBindCC(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeH(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeExternH(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeCCInc(outputDir); err != nil {
			return err
		}
		if err := g.generateBridgeInc(outputDir); err != nil {
			return err
		}
		if err := g.generateBindGO(outputDir, lib); err != nil {
			return err
		}
	}
	for _, lib := range f.ccprotos {
		outputDir := filepath.Join(ccallDir(), goPkgPath(lib.BasePkg, lib.Name))
		if err := g.generateBindCC(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeH(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeExternH(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeCCInc(outputDir); err != nil {
			return err
		}
		if err := g.generateBridgeInc(outputDir); err != nil {
			return err
		}
	}
	return nil
}

func (g *Generator) generateBindCC(outputDir string, lib *Lib) error {
	output, err := g.generateCCSourceByTemplate(
		"templates/bind.cc.tmpl",
		g.createBindCCParam(lib),
	)
	if err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bind.cc"), output, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateBridgeH(outputDir string, lib *Lib) error {
	output, err := g.generateCCSourceByTemplate(
		"templates/bridge.h.tmpl",
		g.createBindCCParam(lib),
	)
	if err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bridge.h"), output, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateBridgeExternH(outputDir string, lib *Lib) error {
	output, err := g.generateCCSourceByTemplate(
		"templates/bridge_extern.h.tmpl",
		g.createBridgeExternParam(lib),
	)
	if err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bridge_extern.h"), output, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateBindGO(outputDir string, lib *Lib) error {
	{
		// for darwin ( currently windows not supported )
		output, err := g.generateGoSourceByTemplate(
			"templates/bind.go.tmpl",
			g.createBindGoParamDarwin(lib),
		)
		if err != nil {
			return err
		}
		if err := os.WriteFile(filepath.Join(outputDir, "bind_darwin.go"), output, 0o600); err != nil {
			return err
		}
	}
	{
		output, err := g.generateGoSourceByTemplate(
			"templates/bind.go.tmpl",
			g.createBindGoParamLinux(lib),
		)
		if err != nil {
			return err
		}
		if err := os.WriteFile(filepath.Join(outputDir, "bind_linux.go"), output, 0o600); err != nil {
			return err
		}
	}
	if existsFile(filepath.Join(outputDir, "bind.go")) {
		if err := os.Remove(filepath.Join(outputDir, "bind.go")); err != nil {
			return err
		}
	}
	return nil
}

func (g *Generator) generateBridgeCCInc(outputDir string) error {
	if existsFile(filepath.Join(outputDir, "bridge_cc.inc")) {
		return nil
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bridge_cc.inc"), nil, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateBridgeInc(outputDir string) error {
	if existsFile(filepath.Join(outputDir, "bridge.inc")) {
		return nil
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bridge.inc"), nil, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateCCSourceByTemplate(tmplPath string, param interface{}) ([]byte, error) {
	tmplText, err := g.templates.ReadFile(tmplPath)
	if err != nil {
		return nil, fmt.Errorf("failed to read template: %w", err)
	}
	tmpl, err := template.New("").Parse(string(tmplText))
	if err != nil {
		return nil, fmt.Errorf("failed to parse template: %w", err)
	}
	var b bytes.Buffer
	if err := tmpl.Execute(&b, param); err != nil {
		return nil, fmt.Errorf("failed to execute template: %w", err)
	}
	return b.Bytes(), nil
}

func (g *Generator) generateGoSourceByTemplate(tmplPath string, param interface{}) ([]byte, error) {
	tmplText, err := g.templates.ReadFile(tmplPath)
	if err != nil {
		return nil, fmt.Errorf("failed to read template: %w", err)
	}
	tmpl, err := template.New("").Parse(string(tmplText))
	if err != nil {
		return nil, fmt.Errorf("failed to parse template: %w", err)
	}
	var b bytes.Buffer
	if err := tmpl.Execute(&b, param); err != nil {
		return nil, fmt.Errorf("failed to execute template: %w", err)
	}
	buf, err := format.Source(b.Bytes())
	if err != nil {
		return nil, fmt.Errorf("failed to format %s: %w", b.String(), err)
	}
	return buf, nil
}

type BindCCParam struct {
	FQDN         string
	PkgPath      string
	ReplaceNames []string
	Headers      []string
	Sources      []SourceParam
	Deps         []string
}

type SourceParam struct {
	Value             string
	BeforeIncludeHook string
	AfterIncludeHook  string
}

func (g *Generator) createBindCCParam(lib *Lib) *BindCCParam {
	param := &BindCCParam{}

	prefix := strings.ReplaceAll(lib.BasePkg, "/", "_")
	param.FQDN = fmt.Sprintf("%s_%s", prefix, lib.Name)
	param.PkgPath = lib.BasePkg
	param.ReplaceNames = append(
		append(
			append([]string{}, g.cfg.TopLevelNamespaces...),
			g.cfg.GlobalSymbols...,
		),
		g.internalExportNames...,
	)
	param.Headers = lib.HeaderPaths()
	sources := make([]SourceParam, 0, len(lib.Sources))
	for _, src := range lib.SourcePaths() {
		sourceParam := SourceParam{Value: src}
		if sym, exists := g.containsConflictSymbolFileMap[src]; exists {
			sourceParam.BeforeIncludeHook = fmt.Sprintf("\n\n#define %s %s%s", sym.Symbol, prefix, sym.Symbol)
			sourceParam.AfterIncludeHook = fmt.Sprintf("\n#undef %s\n", sym.Symbol)
		}
		if addSource, exists := g.containsAddSourceFileMap[src]; exists {
			sourceParam.AfterIncludeHook += fmt.Sprintf("\n#include \"%s\"\n", addSource.Source)
		}
		sources = append(sources, sourceParam)
	}
	param.Sources = sources
	deps := make([]string, 0, len(lib.Deps))
	for _, dep := range lib.Deps {
		deps = append(deps, goPkgPath(dep.BasePkg, dep.Pkg))
	}
	param.Deps = deps
	return param
}

type BindGoParam struct {
	Compiler        string
	DebugMode       bool
	Pkg             string
	FQDN            string
	ImportUnsafePkg bool
	IncludePaths    []string
	CXXFlags        []string
	LDFlags         []string
	BridgeHeaders   []string
	ImportGoLibs    []string
	Funcs           []Func
	ExportFuncs     []ExportFunc
}

type BridgeExternParam struct {
	Funcs []Func
}

type Func struct {
	BasePkg string
	Name    string
	Args    []Type
}

type ExportFunc struct {
	Func
	LibName string
}

type Type struct {
	IsCustomType bool
	IsRetType    bool
	NeedsCast    bool
	GO           string
	CGO          string
	C            string
}

func (t *Type) GoToC(index int) string {
	argName := fmt.Sprintf("arg%d", index)
	if t.IsRetType {
		return fmt.Sprintf("(%s)(unsafe.Pointer(%s))", t.CGO, argName)
	}
	return fmt.Sprintf("%s(%s)", t.CGO, argName)
}

var reservedKeywords = []string{
	"case", "type",
}

func (g *Generator) goReservedKeyword(keyword string) bool {
	for _, k := range reservedKeywords {
		if keyword == k {
			return true
		}
	}
	return false
}

func (g *Generator) cgoCompiler(lib *Lib) string {
	if strings.Contains(lib.BasePkg, "absl") {
		return "c++11"
	}
	return "c++1z"
}

func (g *Generator) goPkgName(lib *Lib) string {
	if g.goReservedKeyword(lib.Name) {
		return "go_" + lib.Name
	}
	return lib.Name
}

func (g *Generator) extendLibs(lib *Lib) []string {
	if lib.BasePkg == "absl/time/internal/cctz" && lib.Name == "time_zone" {
		// TODO: switch by platform
		return []string{"-framework Foundation"}
	}
	return nil
}

func (g *Generator) createBindGoParamLinux(lib *Lib) *BindGoParam {
	ldflags := []string{"-ldl"}
	for _, flag := range lib.LinkerFlags {
		if flag.OSType == Darwin || flag.OSType == Windows {
			continue
		}
		ldflags = append(ldflags, flag.Flag)
	}
	cxxflags := []string{
		"-Wno-final-dtor-non-final-class",
		"-Wno-implicit-const-int-float-conversion",
	}
	return g.createBindGoParam(lib, cxxflags, ldflags)
}

func (g *Generator) createBindGoParamDarwin(lib *Lib) *BindGoParam {
	ldflags := []string{}
	for _, flag := range lib.LinkerFlags {
		if flag.OSType != Darwin {
			continue
		}
		ldflags = append(ldflags, flag.Flag)
	}
	return g.createBindGoParam(lib, nil, ldflags)
}

func (g *Generator) createBindGoParam(lib *Lib, cxxflags, ldflags []string) *BindGoParam {
	param := &BindGoParam{DebugMode: false}
	param.Pkg = g.goPkgName(lib)
	param.Compiler = g.cgoCompiler(lib)
	param.CXXFlags = cxxflags
	param.LDFlags = ldflags
	prefix := strings.ReplaceAll(lib.BasePkg, "/", "_")
	param.FQDN = fmt.Sprintf("%s_%s", prefix, lib.Name)
	ccallDir := strings.Repeat("../", len(strings.Split(lib.BasePkg, "/"))+1)
	includePaths := []string{ccallDir}
	for _, includeDir := range includeDirs {
		includePaths = append(includePaths, filepath.Join(ccallDir, includeDir))
	}
	param.IncludePaths = includePaths
	pkgName := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	exportFuncs := []ExportFunc{}
	bridgeHeaders := []string{}
	importGoLibs := []string{}
	exportFQDN := fmt.Sprintf("export_%s", param.FQDN)
	for _, dep := range g.pkgToAllDeps[pkgName] {
		if dep == pkgName {
			continue
		}
		pkg, exists := g.importSymbolPackageMap[dep]
		if !exists {
			continue
		}
		goPkgPath := normalizeGoPkgPath(dep)
		libName := fmt.Sprintf("github.com/goccy/go-zetasql/internal/ccall/%s", goPkgPath)
		importGoLibs = append(importGoLibs, libName)
		basePkg := filepath.Base(goPkgPath)
		bridgeHeaders = append(bridgeHeaders, filepath.Join(ccallDir, goPkgPath, "bridge.h"))
		for _, method := range pkg.Methods {
			fn := ExportFunc{
				Func: Func{
					BasePkg: basePkg,
					Name:    method.Name,
				},
				LibName: libName,
			}
			args := []Type{}
			for _, arg := range method.Args {
				cgoType := g.toCGOType(arg)
				if cgoType == "" {
					log.Fatalf("unexpected type: %s.%s", exportFQDN, arg)
				}
				if cgoType == "unsafe.Pointer" {
					param.ImportUnsafePkg = true
				}
				args = append(args, Type{CGO: cgoType})
			}
			for _, ret := range method.Ret {
				cgoType := g.toCGOType(ret)
				if cgoType == "" {
					log.Fatalf("unexpected type: %s.%s", exportFQDN, ret)
				}
				if cgoType == "unsafe.Pointer" {
					param.ImportUnsafePkg = true
				}
				args = append(args, Type{CGO: "*" + cgoType})
			}
			fn.Args = args
			exportFuncs = append(exportFuncs, fn)
		}
	}
	param.ImportGoLibs = importGoLibs
	param.BridgeHeaders = bridgeHeaders
	param.ExportFuncs = exportFuncs
	if pkg, exists := g.pkgMap[pkgName]; exists {
		funcs := make([]Func, 0, len(pkg.Methods))
		for _, method := range pkg.Methods {
			fn := Func{
				BasePkg: lib.Name,
				Name:    method.Name,
			}
			args := []Type{}
			for _, arg := range method.Args {
				cgoType := g.toCGOType(arg)
				if cgoType == "" {
					log.Fatalf("unexpected type: %s.%s", exportFQDN, arg)
				}
				if cgoType == "unsafe.Pointer" {
					param.ImportUnsafePkg = true
				}
				goType := g.toGoType(arg)
				needsCast := goType != cgoType
				args = append(args, Type{
					NeedsCast: needsCast,
					GO:        goType,
					CGO:       cgoType,
				})
			}
			for _, ret := range method.Ret {
				cgoType := g.toCGOType(ret)
				if cgoType == "" {
					log.Fatalf("unexpected type: %s.%s", exportFQDN, ret)
				}
				if cgoType == "unsafe.Pointer" {
					param.ImportUnsafePkg = true
				}
				goType := g.toGoType(ret)
				needsCast := goType != cgoType
				if needsCast {
					param.ImportUnsafePkg = true
				}
				args = append(args, Type{
					IsRetType: true,
					NeedsCast: needsCast,
					GO:        "*" + goType,
					CGO:       "*" + cgoType,
				})
			}
			fn.Args = args
			funcs = append(funcs, fn)
		}
		param.Funcs = funcs
	}
	return param
}

func (g *Generator) createBridgeExternParam(lib *Lib) *BridgeExternParam {
	param := &BridgeExternParam{}
	pkgName := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	if pkg, exists := g.pkgMap[pkgName]; exists {
		funcs := make([]Func, 0, len(pkg.Methods))
		for _, method := range pkg.Methods {
			fn := Func{
				BasePkg: lib.Name,
				Name:    method.Name,
			}
			args := []Type{}
			for _, arg := range method.Args {
				args = append(args, Type{C: g.toCType(arg)})
			}
			for _, ret := range method.Ret {
				args = append(args, Type{C: fmt.Sprintf("%s*", g.toCType(ret))})
			}
			fn.Args = args
			funcs = append(funcs, fn)
		}
		param.Funcs = funcs
	}
	return param
}

func (g *Generator) toGoType(typ string) string {
	if typ == "string" || typ == "struct" {
		return "unsafe.Pointer"
	}
	return typ
}

func (g *Generator) toCGOType(typ string) string {
	switch typ {
	case "int", "int8", "int16", "int32", "bool":
		return "C.int"
	case "uint", "uint8", "uint16", "uint32":
		return "C.uint"
	case "int64":
		return "C.longlong"
	case "uint64":
		return "C.uint64_t"
	case "float32":
		return "C.float"
	case "float64":
		return "C.double"
	case "string", "struct":
		return "unsafe.Pointer"
	}
	return ""
}

func (g *Generator) toCType(typ string) string {
	switch typ {
	case "int", "int8", "int16", "int32", "bool":
		return "int"
	case "uint", "uint8", "uint16", "uint32":
		return "uint32_t"
	case "int64":
		return "int64_t"
	case "uint64":
		return "uint64_t"
	case "float32":
		return "float"
	case "float64":
		return "double"
	case "string", "struct":
		return "void *"
	}
	return ""
}
