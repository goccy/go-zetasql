package zetasql

import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/public/analyzer"
	"github.com/goccy/go-zetasql/internal/helper"
	"github.com/goccy/go-zetasql/resolved_ast"
	"github.com/goccy/go-zetasql/types"
)

import "C"

type AnalyzerOutput struct {
	raw unsafe.Pointer
}

type AnalyzerOptions struct{}

func (o *AnalyzerOptions) AddQueryParameter(name string, typ types.Type) {
}

func (o *AnalyzerOptions) ClearQueryParameters() {}

func (o *AnalyzerOptions) AddPositionalQueryParameter(typ types.Type) error {
	return nil
}

func (o *AnalyzerOptions) ClearPositionalQueyParameters() {}

func (o *AnalyzerOptions) AddExpressionColumn(name string, typ types.Type) error {
	return nil
}

func (o *AnalyzerOptions) SetInScopeExpressionColumn(name string, typ types.Type) error {
	return nil
}

func (o *AnalyzerOptions) ExpressionColumns() QueryParametersMap {
	return nil
}

func (o *AnalyzerOptions) HasInScopeExpressionColumn() bool {
	return false
}

func (o *AnalyzerOptions) InScopeExpressionColumnName() string {
	return ""
}

func (o *AnalyzerOptions) InScopeExpressionColumnType() types.Type {
	return nil
}

func newAnalyzerOutput(raw unsafe.Pointer) *AnalyzerOutput {
	if raw == nil {
		return nil
	}
	return &AnalyzerOutput{raw: raw}
}

func (o *AnalyzerOutput) Statement() resolved_ast.StatementNode {
	var v unsafe.Pointer
	internal.AnalyzerOutput_resolved_statement(o.raw, &v)
	return newResolvedNode(v).(resolved_ast.StatementNode)
}

func (o *AnalyzerOutput) Expr() resolved_ast.ExprNode {
	return nil
}

type DeprecationWarnings struct {
}

func (o *AnalyzerOutput) DeprecationWarnings() *DeprecationWarnings {
	return nil
}

type QueryParametersMap map[string]types.Type

func (o *AnalyzerOutput) UndeclaredParameters() QueryParametersMap {
	return nil
}

func (o *AnalyzerOutput) UndeclaredPositionalParameters() []types.Type {
	return nil
}

func (o *AnalyzerOutput) MaxColumnID() int {
	return 0
}

type AnalyzerOutputProperties struct {
	HasFlatten       bool
	HasAnonymization bool
}

func (o *AnalyzerOutput) AnalyzerOutputProperties() *AnalyzerOutputProperties {
	return nil
}

func AnalyzeStatement(sql string, catalog types.Catalog) (*AnalyzerOutput, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.AnalyzeStatement(helper.StringToPtr(sql), getRawCatalog(catalog), &v, &status)
	st := newStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newAnalyzerOutput(v), nil
}

func AnalyzeNextStatement(loc *ParseResumeLocation, catalog types.Catalog) (*AnalyzerOutput, bool, error) {
	return nil, false, nil
}

func AnalyzeExpression(sql string, catalog types.Catalog, targetType types.Type) (*AnalyzerOutput, error) {
	return nil, nil
}

func AnalyzeType(typeName string, catalog types.Catalog, targetType types.Type) ([]types.Type, error) {
	return nil, nil
}

type TableNameSet struct{}

func ExtractTableNamesFromStatement(sql string) (*TableNameSet, error) {
	return nil, nil
}

func ExtractTableNamesFromNextStatement(loc *ParseResumeLocation) (*TableNameSet, bool, error) {
	return nil, false, nil
}

func ExtractTableNamesFromScript(sql string) (*TableNameSet, error) {
	return nil, nil
}

//go:linkname getRawCatalog github.com/goccy/go-zetasql/types.getRawCatalog
func getRawCatalog(types.Catalog) unsafe.Pointer

//go:linkname newResolvedNode github.com/goccy/go-zetasql/resolved_ast.newNode
func newResolvedNode(unsafe.Pointer) resolved_ast.Node
