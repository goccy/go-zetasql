package zetasql

import "C"
import (
	"fmt"
	"unsafe"

	"github.com/goccy/go-zetasql/ast"
	internalparser "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser"
)

var (
	ErrParseStatement  = fmt.Errorf("failed to get statement node")
	ErrParseScript     = fmt.Errorf("failed to get script node")
	ErrParseType       = fmt.Errorf("failed to get type node")
	ErrParseExpression = fmt.Errorf("failed to get expression node")
)

type parserOutput struct {
	raw unsafe.Pointer
}

func (o *parserOutput) Statement() (ast.StatementNode, error) {
	var stmt unsafe.Pointer
	internalparser.ParserOutput_statement(o.raw, &stmt)
	node, ok := newNode(stmt).(ast.StatementNode)
	if !ok {
		return nil, ErrParseStatement
	}
	return node, nil
}

func (o *parserOutput) Script() (ast.ScriptNode, error) {
	var script unsafe.Pointer
	internalparser.ParserOutput_script(o.raw, &script)
	node, ok := newNode(script).(ast.ScriptNode)
	if !ok {
		return nil, ErrParseScript
	}
	return node, nil
}

func (o *parserOutput) Type() (ast.TypeNode, error) {
	var typ unsafe.Pointer
	internalparser.ParserOutput_type(o.raw, &typ)
	node, ok := newNode(typ).(ast.TypeNode)
	if !ok {
		return nil, ErrParseType
	}
	return node, nil
}

func (o *parserOutput) Expression() (ast.ExpressionNode, error) {
	var expr unsafe.Pointer
	internalparser.ParserOutput_expression(o.raw, &expr)
	node, ok := newNode(expr).(ast.ExpressionNode)
	if !ok {
		return nil, ErrParseExpression
	}
	return node, nil
}

func ParseStatement(stmt string) (ast.StatementNode, error) {
	var (
		out    unsafe.Pointer
		status unsafe.Pointer
	)
	internalparser.ParseStatement(unsafe.Pointer(C.CString(stmt)), nil, &out, &status)
	parserStatus := newStatus(status)
	if !parserStatus.OK() {
		return nil, parserStatus.Error()
	}
	parserOut := &parserOutput{raw: out}
	return parserOut.Statement()
}

type ErrorMessageMode int

const (
	ErrorMessageWithPayload ErrorMessageMode = iota
	ErrorMessageOneLine
	ErrorMessageMultiLineWithCaret
)

func ParseScript(script string, mode ErrorMessageMode) (ast.ScriptNode, error) {
	var (
		out    unsafe.Pointer
		status unsafe.Pointer
	)
	internalparser.ParseScript(unsafe.Pointer(C.CString(script)), nil, int(mode), &out, &status)
	parserStatus := newStatus(status)
	if !parserStatus.OK() {
		return nil, parserStatus.Error()
	}
	parserOut := &parserOutput{raw: out}
	return parserOut.Script()
}

func ParseType(typ string) (ast.TypeNode, error) {
	var (
		out    unsafe.Pointer
		status unsafe.Pointer
	)
	internalparser.ParseType(unsafe.Pointer(C.CString(typ)), nil, &out, &status)
	parserStatus := newStatus(status)
	if !parserStatus.OK() {
		return nil, parserStatus.Error()
	}
	parserOut := &parserOutput{raw: out}
	return parserOut.Type()
}

func ParseExpression(expr string) (ast.ExpressionNode, error) {
	var (
		out    unsafe.Pointer
		status unsafe.Pointer
	)
	internalparser.ParseExpression(unsafe.Pointer(C.CString(expr)), nil, &out, &status)
	parserStatus := newStatus(status)
	if !parserStatus.OK() {
		return nil, parserStatus.Error()
	}
	parserOut := &parserOutput{raw: out}
	return parserOut.Expression()
}

type ParseResumeLocation struct {
	raw unsafe.Pointer
}

func NewParseResumeLocation(src string) *ParseResumeLocation {
	var v unsafe.Pointer
	internalparser.ParseResumeLocation_FromStringView(unsafe.Pointer(C.CString(src)), &v)
	return &ParseResumeLocation{raw: v}
}

func ParseNextStatement(loc *ParseResumeLocation) (ast.StatementNode, bool, error) {
	var (
		out    unsafe.Pointer
		isEnd  bool
		status unsafe.Pointer
	)
	internalparser.ParseNextStatement(loc.raw, nil, &out, &isEnd, &status)
	parserStatus := newStatus(status)
	if !parserStatus.OK() {
		return nil, isEnd, parserStatus.Error()
	}
	parserOut := &parserOutput{raw: out}
	stmt, err := parserOut.Statement()
	return stmt, isEnd, err
}

func ParseNextScriptStatement(loc *ParseResumeLocation) (ast.ScriptNode, bool, error) {
	var (
		out    unsafe.Pointer
		isEnd  bool
		status unsafe.Pointer
	)
	internalparser.ParseNextScriptStatement(loc.raw, nil, &out, &isEnd, &status)
	parserStatus := newStatus(status)
	if !parserStatus.OK() {
		return nil, isEnd, parserStatus.Error()
	}
	parserOut := &parserOutput{raw: out}
	script, err := parserOut.Script()
	return script, isEnd, err
}

func Unparse(node ast.Node) string {
	var v unsafe.Pointer
	internalparser.Unparse(getNodeRaw(node), &v)
	return C.GoString((*C.char)(v))
}

//go:linkname newNode github.com/goccy/go-zetasql/ast.newNode
func newNode(unsafe.Pointer) ast.Node

//go:linkname getNodeRaw github.com/goccy/go-zetasql/ast.getNodeRaw
func getNodeRaw(ast.Node) unsafe.Pointer
