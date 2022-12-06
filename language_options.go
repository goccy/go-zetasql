package zetasql

import (
	"unsafe"

	internal "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"github.com/goccy/go-zetasql/internal/helper"
	"github.com/goccy/go-zetasql/resolved_ast"
	"github.com/goccy/go-zetasql/types"
)

// LanguageOptions contains options controlling the language that should be
// accepted, and the desired semantics.  This is used for libraries where
// behavior differs by language version, flags, or other options.
type LanguageOptions struct {
	raw unsafe.Pointer
}

// NewLanguageOptions creates a new LanguageOptions instance.
func NewLanguageOptions() *LanguageOptions {
	var v unsafe.Pointer
	internal.LanguageOptions_new(&v)
	return newLanguageOptions(v)
}

func newLanguageOptions(v unsafe.Pointer) *LanguageOptions {
	if v == nil {
		return nil
	}
	return &LanguageOptions{raw: v}
}

// SupportsStatementKind returns true if 'kind' is supported.
//
// Note: The "supported statement kind" mechanism does not support script
// statements, as script statements do not exist in the resolved tree, so no
// resolved_ast.Kind enumeration for them exists. Script statements are gated
// through language features (see LanguageFeatureEnabled()).
func (o *LanguageOptions) SupportsStatementKind(kind resolved_ast.Kind) bool {
	var v bool
	internal.LanguageOptions_SupportsStatementKind(o.raw, int(kind), &v)
	return v
}

// SetSupportedStatementKinds the provided set of resolved_ast.Kind indicates the statements
// supported by the caller. The potentially supported statements are the
// subclasses of StatementNode. An empty set indicates no restrictions. If
// ZetaSQL encounters a statement kind that is not supported during
// analysis, it immediately returns an error.
//
// By default, the set includes only resolved_ast.QueryStmt, so callers must
// explicitly opt in to support other statements.
func (o *LanguageOptions) SetSupportedStatementKinds(kinds []resolved_ast.Kind) {
	internal.LanguageOptions_SetSupportedStatementKinds(o.raw, helper.SliceToPtr(kinds, func(i int) unsafe.Pointer {
		return helper.IntPtr(int(kinds[i]))
	}))
}

// SetSupportsAllStatementKinds equivalent to SetSupportedStatementKinds({}).
func (o *LanguageOptions) SetSupportsAllStatementKinds() {
	internal.LanguageOptions_SetSupportsAllStatementKinds(o.raw)
}

// AddSupportedStatementKind adds <kind> to the set of supported statement kinds.
func (o *LanguageOptions) AddSupportedStatementKind(kind resolved_ast.Kind) {
	internal.LanguageOptions_AddSupportedStatementKind(o.raw, int(kind))
}

// LanguageFeatureEnabled teturns whether or not <feature> is enabled.
func (o *LanguageOptions) LanguageFeatureEnabled(feature LanguageFeature) bool {
	var v bool
	internal.LanguageOptions_LanguageFeatureEnabled(o.raw, int(feature), &v)
	return v
}

// SetLanguageVersion set the ZetaSQL LanguageVersion.
// This is equivalent to enabling the set of LanguageFeatures defined as part of that version,
// and disabling all other LanguageFeatures.
// The LanguageVersion itself is not stored.
//
// Calling this cancels out any previous calls to EnableLanguageFeature, so
// EnableLanguageFeature would normally be called after SetLanguageVersion.
func (o *LanguageOptions) SetLanguageVersion(version LanguageVersion) {
	internal.LanguageOptions_SetLanguageVersion(o.raw, int(version))
}

// EnableLanguageFeature enables support for the specified <feature>.
func (o *LanguageOptions) EnableLanguageFeature(feature LanguageFeature) {
	internal.LanguageOptions_EnableLanguageFeature(o.raw, int(feature))
}

func (o *LanguageOptions) SetEnabledLanguageFeatures(features []LanguageFeature) {
	internal.LanguageOptions_SetEnabledLanguageFeatures(o.raw, helper.SliceToPtr(features, func(i int) unsafe.Pointer {
		return helper.IntPtr(int(features[i]))
	}))
}

// EnabledLanguageFeatures.
func (o *LanguageOptions) EnabledLanguageFeatures() []LanguageFeature {
	var v unsafe.Pointer
	internal.LanguageOptions_EnabledLanguageFeatures(o.raw, &v)
	var ret []LanguageFeature
	helper.PtrToSlice(v, func(p unsafe.Pointer) {
		ret = append(ret, LanguageFeature(uintptr(p)))
	})
	return ret
}

// EnabledLanguageFeaturesAsString returns a comma-separated string listing enabled LanguageFeatures.
func (o *LanguageOptions) EnabledLanguageFeaturesAsString() string {
	var v unsafe.Pointer
	internal.LanguageOptions_EnabledLanguageFeaturesAsString(o.raw, &v)
	return helper.PtrToString(v)
}

// DisableAllLanguageFeatures.
func (o *LanguageOptions) DisableAllLanguageFeatures() {
	internal.LanguageOptions_DisableAllLanguageFeatures(o.raw)
}

// EnableMaximumLanguageFeatures enable all optional features and reservable keywords that are enabled in
// the idealized ZetaSQL and are released to users.
func (o *LanguageOptions) EnableMaximumLanguageFeatures() {
	internal.LanguageOptions_EnableMaximumLanguageFeatures(o.raw)
}

// Enable all optional features and reservable keywords that are enabled in
// the idealized ZetaSQL, including features that are still under
// development. For internal ZetaSQL use only.
func (o *LanguageOptions) EnableMaximumLanguageFeaturesForDevelopment() {
	internal.LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment(o.raw)
}

// SetNameReolutionMode.
func (o *LanguageOptions) SetNameResolutionMode(mode NameResolutionMode) {
	internal.LanguageOptions_set_name_resolution_mode(o.raw, int(mode))
}

// NameReolutionMode.
func (o *LanguageOptions) NameReolutionMode() NameResolutionMode {
	var v int
	internal.LanguageOptions_name_resolution_mode(o.raw, &v)
	return NameResolutionMode(v)
}

// SetProductMode set ProductMode.
func (o *LanguageOptions) SetProductMode(mode types.ProductMode) {
	internal.LanguageOptions_set_product_mode(o.raw, int(mode))
}

// ProductMode returns current ProductMode.
func (o *LanguageOptions) ProductMode() types.ProductMode {
	var v int
	internal.LanguageOptions_product_mode(o.raw, &v)
	return types.ProductMode(v)
}

// SupportsProtoTypes.
func (o *LanguageOptions) SupportsProtoTypes() bool {
	var v bool
	internal.LanguageOptions_SupportsProtoTypes(o.raw, &v)
	return v
}

// SetErrorOnDeprecatedSyntax.
func (o *LanguageOptions) SetErrorOnDeprecatedSyntax(value bool) {
	internal.LanguageOptions_set_error_on_deprecated_syntax(o.raw, helper.BoolToInt(value))
}

// ErrorOnDeprecatedSyntax.
func (o *LanguageOptions) ErrorOnDeprecatedSyntax() bool {
	var v bool
	internal.LanguageOptions_error_on_deprecated_syntax(o.raw, &v)
	return v
}

// SetSupportedGenericEntityTypes.
func (o *LanguageOptions) SetSupportedGenericEntityTypes(entityTypes []string) {
	internal.LanguageOptions_SetSupportedGenericEntityTypes(o.raw, helper.SliceToPtr(entityTypes, func(i int) unsafe.Pointer {
		return helper.StringToPtr(entityTypes[i])
	}))
}

// GenericEntityTypeSupported.
func (o *LanguageOptions) GenericEntityTypeSupported(typ string) bool {
	var v bool
	internal.LanguageOptions_GenericEntityTypeSupported(o.raw, helper.StringToPtr(typ), &v)
	return v
}

// IsReservedKeyword returns true if <keyword> is reserved.
//
// reservable keywords are non-reserved by default, but can be made reserved
// by calling EnableReservableKeyword().
//
// For non-reservable keywords, the return value simply indicates the fixed
// behavior as to whether the keyword is reserved or not (e.g. true for
// SELECT, false for DECIMAL).
//
// For non-keywords, the return value is false.
//
// <keyword> is case-insensitive.
func (o *LanguageOptions) IsReservedKeyword(keyword string) bool {
	var v bool
	internal.LanguageOptions_IsReservedKeyword(o.raw, helper.StringToPtr(keyword), &v)
	return v
}

// EnableReservableKeyword indicates whether or not <keyword> should be considered "reserved".
// reservable keywords are nonreserved by default. When nonreserved, they
// still exist as keywords, but may also be used in queries as identifiers,
// without backticks.
//
// Returns an error if <keyword> is not reservable.
//
// <keyword> is case-insensitive.
func (o *LanguageOptions) EnableReservableKeyword(keyword string, reserved bool) error {
	var v unsafe.Pointer
	internal.LanguageOptions_EnableReservableKeyword(o.raw, helper.StringToPtr(keyword), helper.BoolToInt(reserved), &v)
	st := helper.NewStatus(v)
	if !st.OK() {
		return st.Error()
	}
	return nil
}

// EnableAllReservableKeywords similar to EnableReservableKeyword(), but applies to all reservable keywords.
func (o *LanguageOptions) EnableAllReservableKeywords(reserved bool) {
	internal.LanguageOptions_EnableAllReservableKeywords(o.raw, helper.BoolToInt(reserved))
}

func (o *LanguageOptions) BuiltinFunctionOptions() *types.BuiltinFunctionOptions {
	var v unsafe.Pointer
	internal.BuiltinFunctionOptions_new(o.raw, &v)
	return newBuiltinFunctionOptions(v)
}
