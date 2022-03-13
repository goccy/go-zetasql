#ifndef ZETASQL_PARSER_KEYWORDS_EXPORT_H
#define ZETASQL_PARSER_KEYWORDS_EXPORT_H

#include "zetasql/parser/keywords.h"
#include "zetasql/parser/keywords.cc"

#if 0
namespace zetasql {
  namespace parser {

    const KeywordInfo* GetKeywordInfo(absl::string_view keyword) {
      return nullptr;
    }

    const KeywordInfo* GetKeywordInfoForBisonToken(int bison_token) {
      return nullptr;
    }

    const std::vector<KeywordInfo>& GetAllKeywords() {
      std::vector<KeywordInfo> *v;
      return *v;
    }

    bool IsKeywordInTokenizer(absl::string_view identifier) {
      return false;
    }

    bool NonReservedIdentifierMustBeBackquoted(absl::string_view identifier) {
      return false;
    }

  }
}
#endif

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/case/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/optional/export.inc"
#include "go-absl/types/variant/export.inc"

#endif
