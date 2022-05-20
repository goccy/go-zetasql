package types

// ProductMode this identifies whether ZetaSQL works in INTERNAL (inside Google) mode,
// or in EXTERNAL (exposed to non-Googlers in the products such as Cloud).
type ProductMode int

const (
	ProductInternal ProductMode = 0
	ProductExternal ProductMode = 1
)
