package types

type Procedure interface {
	Name() string
	FullName() string
	NamePath() []string
	Signature() FunctionSignature
	SupportedSignatureUserFacingText(ProductMode) string
}
