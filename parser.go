package zetasql

import "C"
import (
	"unsafe"

	"github.com/goccy/go-zetasql/ast"
	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
)

type ParserOptions struct {
	raw unsafe.Pointer
}

func NewParserOptions() *ParserOptions {
	var v unsafe.Pointer
	internal.ParserOptions_new(&v)
	return newParserOptions(v)
}

func newParserOptions(v unsafe.Pointer) *ParserOptions {
	if v == nil {
		return nil
	}
	return &ParserOptions{raw: v}
}

func (o *ParserOptions) getRaw() unsafe.Pointer {
	if o == nil {
		return nil
	}
	return o.raw
}

func (o *ParserOptions) SetLanguageOptions(opt *LanguageOptions) {
	internal.ParserOptions_set_language_options(o.raw, opt.raw)
}

func (o *ParserOptions) LanguageOptions() *LanguageOptions {
	var v unsafe.Pointer
	internal.ParserOptions_language_options(o.raw, &v)
	return newLanguageOptions(v)
}

type parserOutput struct {
	raw unsafe.Pointer
}

func (o *parserOutput) stmt() (ast.StatementNode, error) {
	var stmt unsafe.Pointer
	internal.ParserOutput_statement(o.raw, &stmt)
	node, ok := newNode(stmt).(ast.StatementNode)
	if !ok {
		return nil, ErrParseStatement
	}
	return node, nil
}

func (o *parserOutput) script() (ast.ScriptNode, error) {
	var script unsafe.Pointer
	internal.ParserOutput_script(o.raw, &script)
	node, ok := newNode(script).(ast.ScriptNode)
	if !ok {
		return nil, ErrParseScript
	}
	return node, nil
}

func (o *parserOutput) typ() (ast.TypeNode, error) {
	var typ unsafe.Pointer
	internal.ParserOutput_type(o.raw, &typ)
	node, ok := newNode(typ).(ast.TypeNode)
	if !ok {
		return nil, ErrParseType
	}
	return node, nil
}

func (o *parserOutput) expr() (ast.ExpressionNode, error) {
	var expr unsafe.Pointer
	internal.ParserOutput_expression(o.raw, &expr)
	node, ok := newNode(expr).(ast.ExpressionNode)
	if !ok {
		return nil, ErrParseExpression
	}
	return node, nil
}

// ParseStatement parses <statement_string> and returns the statement node upon success.
//
// A semi-colon following the statement is optional.
//
// Script statements are not supported.
//
// This can return errors annotated with an ErrorLocation payload that indicates
// the input location of an error.
func ParseStatement(stmt string, opt *ParserOptions) (ast.StatementNode, error) {
	var (
		out    unsafe.Pointer
		status unsafe.Pointer
	)
	internal.ParseStatement(unsafe.Pointer(C.CString(stmt)), opt.getRaw(), &out, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	parserOut := &parserOutput{raw: out}
	return parserOut.stmt()
}

// ParseScript parses <script_string> and returns the script node upon success.
//
// A terminating semi-colon is optional for the last statement in the script,
// and mandatory for all other statements.
//
// <error_message_mode> describes how errors should be represented.
func ParseScript(script string, opt *ParserOptions, mode ErrorMessageMode) (ast.ScriptNode, error) {
	var (
		out    unsafe.Pointer
		status unsafe.Pointer
	)
	internal.ParseScript(unsafe.Pointer(C.CString(script)), opt.getRaw(), int(mode), &out, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	parserOut := &parserOutput{raw: out}
	return parserOut.script()
}

// ParseType parses <type_string> as a type name and returns the type node upon success.
//
// This can return errors annotated with an ErrorLocation payload that indicates
// the input location of an error.
func ParseType(typ string, opt *ParserOptions) (ast.TypeNode, error) {
	var (
		out    unsafe.Pointer
		status unsafe.Pointer
	)
	internal.ParseType(unsafe.Pointer(C.CString(typ)), opt.getRaw(), &out, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	parserOut := &parserOutput{raw: out}
	return parserOut.typ()
}

// ParseExpression parses <expression_string> as an expression and returns the expression node upon success.
//
// This can return errors annotated with an ErrorLocation payload that indicates
// the input location of an error.
func ParseExpression(expr string, opt *ParserOptions) (ast.ExpressionNode, error) {
	var (
		out    unsafe.Pointer
		status unsafe.Pointer
	)
	internal.ParseExpression(unsafe.Pointer(C.CString(expr)), opt.getRaw(), &out, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, st.Error()
	}
	parserOut := &parserOutput{raw: out}
	return parserOut.expr()
}

// ParseNextStatement parses one statement from a string that may contain multiple statements.
// This can be called in a loop with the same <resume_location> to parse all statements from a string.
//
// Returns the statement node upon success. The second return value will be true if parsing reached
// the end of the string.
//
// Statements are separated by semicolons.  A final semicolon is not required
// on the last statement.  If only whitespace and comments follow the
// semicolon, The second return value will be set to true.  Otherwise, it will be set
// to false.  Script statements are not supported.
//
// After a parse error, <resume_location> is not updated and parsing further
// statements is not supported.
//
// This can return errors annotated with an ErrorLocation payload that indicates
// the input location of an error.
func ParseNextStatement(loc *ParseResumeLocation, opt *ParserOptions) (ast.StatementNode, bool, error) {
	var (
		out    unsafe.Pointer
		isEnd  bool
		status unsafe.Pointer
	)
	internal.ParseNextStatement(loc.raw, opt.getRaw(), &out, &isEnd, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, isEnd, st.Error()
	}
	parserOut := &parserOutput{raw: out}
	stmt, err := parserOut.stmt()
	return stmt, isEnd, err
}

// ParseNextScriptStatement similar to the ParseNextStatement function,
// but allows statements specific to scripting, in addition to SQL statements.
// Entire constructs such as IF...END IF,
// WHILE...END WHILE, and BEGIN...END are returned as a single statement, and
// may contain inner statements, which can be examined through the returned parse tree.
func ParseNextScriptStatement(loc *ParseResumeLocation, opt *ParserOptions) (ast.StatementNode, bool, error) {
	var (
		out    unsafe.Pointer
		isEnd  bool
		status unsafe.Pointer
	)
	internal.ParseNextScriptStatement(loc.raw, opt.getRaw(), &out, &isEnd, &status)
	st := helper.NewStatus(status)
	if !st.OK() {
		return nil, isEnd, st.Error()
	}
	parserOut := &parserOutput{raw: out}
	stmt, err := parserOut.stmt()
	return stmt, isEnd, err
}

// Unparse a given AST back to a canonical SQL string and return it.
// Works for any AST node.
func Unparse(node ast.Node) string {
	var v unsafe.Pointer
	internal.Unparse(getNodeRaw(node), &v)
	return C.GoString((*C.char)(v))
}
