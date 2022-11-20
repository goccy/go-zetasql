#define GO_EXPORT(def) export_zetasql_ ## def
#define U_ICU_ENTRY_POINT_RENAME(x) GO_EXPORT(x)
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/public/analyzer/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/simple_catalog/export.inc"
#include "go-zetasql/public/sql_formatter/export.inc"
#include "go-zetasql/parser/parser/bridge.h"
#include "go-zetasql/public/analyzer/bridge.h"
#include "go-zetasql/public/catalog/bridge.h"
#include "go-zetasql/public/simple_catalog/bridge.h"
#include "go-zetasql/public/sql_formatter/bridge.h"
#include "go-zetasql/parser/parser/bridge_cc.inc"
#include "go-zetasql/public/analyzer/bridge_cc.inc"
#include "go-zetasql/public/catalog/bridge_cc.inc"
#include "go-zetasql/public/simple_catalog/bridge_cc.inc"
#include "go-zetasql/public/sql_formatter/bridge_cc.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#include "go-zetasql/parser/parser/bridge.inc"
#include "go-zetasql/public/analyzer/bridge.inc"
#include "go-zetasql/public/catalog/bridge.inc"
#include "go-zetasql/public/simple_catalog/bridge.inc"
#include "go-zetasql/public/sql_formatter/bridge.inc"

#ifdef __cplusplus
}
#endif /* __cplusplus */
