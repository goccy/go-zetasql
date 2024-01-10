#if 0 // wasi-sdk
#include "absl/synchronization/mutex.h"
#include "icu/common/putilimp.h"
#include "icu/common/unicode/putil.h"
#include "icu/common/unicode/urename.h"
#include "icu/common/unicode/uversion.h"

void absl::Mutex::Lock() {}
void absl::Mutex::Unlock() {}
void absl::Mutex::Dtor(){}
void absl::Mutex::ReaderLock() {}
void absl::Mutex::ReaderUnlock() {}
void absl::Mutex::AssertHeld() const {}
bool absl::Mutex::AwaitCommon(absl::Condition const&, absl::synchronization_internal::KernelTimeout) { return false; }
bool absl::Mutex::LockWhenCommon(absl::Condition const&, absl::synchronization_internal::KernelTimeout, bool) { return false; }
void absl::Mutex::ForgetDeadlockInfo() {}

absl::Condition::Condition(bool (*)(void*), void*) {}
const char *uprv_getDefaultLocaleID_65() {}
const char *u_getDataDirectory_65() {}
UBool uprv_pathIsAbsolute_65(const char *path) { return false; }
const char *u_getTimeZoneFilesDirectory_65() {}
void u_versionFromString_65(UVersionInfo versionArray, const char *versionString) {}
void u_versionFromUString_65(UVersionInfo versionArray, const UChar *versionString) {}
const char *u_getTimeZoneFilesDirectory_65(UErrorCode *status) {}

#endif

#if 1 //emscripten
#include "zetasql/parser/ast_node.h"
#include "zetasql/parser/ast_node_kind.h"
#include "zetasql/parser/parse_tree.h"
#include "zetasql/parser/parse_tree_decls.h"
#include "zetasql/parser/parse_tree_errors.h"
#include "zetasql/parser/parse_tree_visitor.h"
#include "zetasql/parser/parser.h"
#include "zetasql/parser/statement_properties.h"
#include "zetasql/parser/unparser.h"
#include "zetasql/parser/visit_result.h"

#include "zetasql/public/analyzer.h"

#include <emscripten.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

EMSCRIPTEN_KEEPALIVE void ParseStatement(void * arg0,void * arg1,void ** arg2,void ** arg3) {
  absl::string_view s = absl::string_view((char *)arg0);
  zetasql::ParserOptions opt;
  if (arg1 != nullptr) {
    opt = *(zetasql::ParserOptions *)arg1;
  }
  std::unique_ptr<zetasql::ParserOutput> out;
  absl::Status ret = zetasql::ParseStatement(s, opt, &out);
  *(std::unique_ptr<zetasql::ParserOutput> *)arg2 = std::move(out);
  *arg3 = (void *)(new absl::Status(ret));
}

EMSCRIPTEN_KEEPALIVE void AnalyzeStatement(void * arg0,void * arg1,void * arg2,void ** arg3,void ** arg4){
  std::unique_ptr<const zetasql::AnalyzerOutput> out;
  auto typeFactory = new zetasql::TypeFactory(); // FIXME: typeFactory will be leaked.
  absl::Status ret = zetasql::AnalyzeStatement(
    (char *)arg0,
    *(zetasql::AnalyzerOptions *)arg1,
    (zetasql::Catalog *)arg2,
    typeFactory,
    &out
  );
  *(std::unique_ptr<const zetasql::AnalyzerOutput> *)arg3 = std::move(out);
  *arg4 = (void *)(new absl::Status(ret));
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
