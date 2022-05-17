#ifndef ZETASQL_PUBLIC_FUNCTIONS_STRING_WITH_COLLATION_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_STRING_WITH_COLLATION_EXPORT_H

#include "zetasql/public/functions/string_with_collation.h"
#include "zetasql/public/functions/string_with_collation.cc"

#if 0
namespace zetasql {
  namespace functions {

    bool ReplaceUtf8WithCollation(const ZetaSqlCollator& collator,
                                  absl::string_view str, absl::string_view oldsub,
                                  absl::string_view newsub, std::string* out,
                                  absl::Status* error) {
      return false;
    }

    bool SplitUtf8WithCollationImpl(const ZetaSqlCollator& collator,
                                    absl::string_view str,
                                    absl::string_view delimiter,
                                    std::vector<absl::string_view>* out,
                                    absl::Status* error) {
      return false;
    }

    bool SplitUtf8WithCollation(const ZetaSqlCollator& collator,
                                absl::string_view str, absl::string_view delimiter,
                                std::vector<absl::string_view>* out,
                                absl::Status* error) {
      return false;
    }

    absl::StatusOr<std::unique_ptr<icu::StringSearch>> InitOverlappingStringSearchAtOffset(const ZetaSqlCollator& collator,
                                                                                           icu::UnicodeString& unicode_str,
                                                                                           icu::UnicodeString& unicode_substr,
                                                                                           int32_t offset, bool* is_out_of_bounds) {
      std::unique_ptr<icu::StringSearch> v;
      return v;
    }

    bool GetNthPosMatchIndex(const ZetaSqlCollator& collator,
                             absl::string_view str, absl::string_view substr,
                             int32_t code_point_pos, int32_t occurrence,
                             int64_t* out, absl::Status* error) {
      return false;
    }

    bool GetNthNegMatchIndex(const ZetaSqlCollator& collator,
                             absl::string_view str, absl::string_view substr,
                             int32_t code_point_pos, int32_t occurrence,
                             int64_t* out, bool* is_ends_with,
                             absl::Status* error) {
      return false;
    }

    bool StrPosOccurrenceUtf8WithCollation(const ZetaSqlCollator& collator,
                                           absl::string_view str,
                                           absl::string_view substr, int64_t pos,
                                           int64_t occurrence, int64_t* out,
                                           absl::Status* error) {
      return false;
    }

    bool StartsWithUtf8WithCollation(const ZetaSqlCollator& collator,
                                     absl::string_view str,
                                     absl::string_view substr, bool* out,
                                     absl::Status* error) {
      return false;
    }

    bool EndsWithUtf8WithCollation(const ZetaSqlCollator& collator,
                                   absl::string_view str, absl::string_view substr,
                                   bool* out, absl::Status* error) {
      return false;
    }

  }
}
#endif

#include "go-zetasql/public/functions/string/export.inc"
#include "go-zetasql/public/functions/util/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/utf_util/export.inc"
#include "go-zetasql/public/collator_lite/export.inc"
#include "go-zetasql/public/functions/arithmetics/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
