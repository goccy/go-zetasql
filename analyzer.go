package zetasql

import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/public/analyzer"
	"github.com/goccy/go-zetasql/internal/helper"
	"github.com/goccy/go-zetasql/resolved_ast"
)

import "C"

type AnalyzerOutput struct {
	raw unsafe.Pointer
}

type AnalyzerOptions struct{}

func (o *AnalyzerOptions) AddQueryParameter(name string, typ Type) {
}

func (o *AnalyzerOptions) ClearQueryParameters() {}

func (o *AnalyzerOptions) AddPositionalQueryParameter(typ Type) error {
	return nil
}

func (o *AnalyzerOptions) ClearPositionalQueyParameters() {}

func (o *AnalyzerOptions) AddExpressionColumn(name string, typ Type) error {
	return nil
}

func (o *AnalyzerOptions) SetInScopeExpressionColumn(name string, typ Type) error {
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

func (o *AnalyzerOptions) InScopeExpressionColumnType() Type {
	return nil
}

type ResolvedASTRewrite struct{}
type ResolvedExpr struct{}

func newAnalyzerOutput(raw unsafe.Pointer) *AnalyzerOutput {
	if raw == nil {
		return nil
	}
	return &AnalyzerOutput{raw: raw}
}

func (o *AnalyzerOutput) ResolvedStatement() *ResolvedStatement {
	var v unsafe.Pointer
	internal.AnalyzerOutput_resolved_statement(o.raw, &v)
	return newResolvedNode(v).(resolved_ast.Statement)
}

func (o *AnalyzerOutput) ResolvedExpr() *ResolvedExpr {
	return nil
}

type DeprecationWarnings struct {
}

func (o *AnalyzerOutput) DeprecationWarnings() *DeprecationWarnings {
	return nil
}

type QueryParametersMap map[string]Type

func (o *AnalyzerOutput) UndeclaredParameters() QueryParametersMap {
	return nil
}

func (o *AnalyzerOutput) UndeclaredPositionalParameters() []Type {
	return nil
}

func (o *AnalyzerOutput) MaxColumnID() int {
	return 0
}

type AnalyzerOutputProperties struct {
	HasFlatten       bool
	HasAnonymization bool
}

func (p *AnalyzerOutputProperties) IsRelevant(rewrite ResolvedASTRewrite) bool {
	return false
}

func (p *AnalyzerOutputProperties) MarkRelevant(rewrite ResolvedASTRewrite) {}

func (p *AnalyzerOutputProperties) RelevantRewrites() []ResolvedASTRewrite {
	return nil
}

func (o *AnalyzerOutput) AnalyzerOutputProperties() *AnalyzerOutputProperties {
	return nil
}

func AnalyzeStatement(sql string, catalog Catalog) (*AnalyzerOutput, error) {
	var (
		v      unsafe.Pointer
		status unsafe.Pointer
	)
	internal.AnalyzeStatement(helper.StringToPtr(sql), catalog.getRaw(), &v, &status)
	st := newStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	return newAnalyzerOutput(raw), nil
}

func AnalyzeNextStatement(loc *ParseResumeLocation, catalog Catalog) (*AnalyzerOutput, bool, error) {
	return nil, false, nil
}

func AnalyzeExpression(sql string, catalog Catalog, targetType Type) (*AnalyzerOutput, error) {
	return nil, nil
}

func AnalyzeType(typeName string, catalog Catalog, targetType Type) ([]Type, error) {
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
