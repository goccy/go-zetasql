package types

type FunctionSignature struct{}

type Function struct {
}

func (f *Function) Name() string {
	return ""
}

func (f *Function) FunctionNamePath() []string {
	return nil
}

func (f *Function) FullName(includeGroup bool) string {
	return ""
}

func (f *Function) SQLName() string {
	return ""
}

func (f *Function) QualifiedSQLName(capitalizeQualifier bool) string {
	return ""
}

func (f *Function) Group() string {
	return ""
}

func (f *Function) IsZetaSQLBuiltin() bool {
	return false
}

func (f *Function) ArgumentsAreCoercible() bool {
	return false
}

func (f *Function) NumSignatures() int {
	return 0
}

func (f *Function) Signatures() []FunctionSignature {
	return nil
}

func (f *Function) ResetSignatures(sigs []FunctionSignature) {

}

func (f *Function) AddSignature(sig FunctionSignature) {}

type Mode int

func (f *Function) Mode() Mode {
	return 0
}

func (f *Function) IsScalar() bool      { return false }
func (f *Function) IsAggregate() bool   { return false }
func (f *Function) IsAnalytic() bool    { return false }
func (f *Function) DebugString() string { return "" }
