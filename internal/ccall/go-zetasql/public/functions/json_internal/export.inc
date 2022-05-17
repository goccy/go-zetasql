#ifndef ZETASQL_PUBLIC_FUNCTIONS_JSON_INTERNAL_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_JSON_INTERNAL_EXPORT_H

#include "zetasql/public/functions/json_internal.h"
#include "zetasql/public/functions/json_internal.cc"

#if 0
namespace zetasql {
  namespace functions {
    namespace json_internal {

      absl::Status IsValidJSONPath(absl::string_view text, bool sql_standard_mode) {
        return absl::OkStatus();
      }

      void RemoveBackSlashFollowedByChar(std::string* token, char esc_chr) {
      }

      absl::StatusOr<std::unique_ptr<ValidJSONPathIterator>> ValidJSONPathIterator::Create(absl::string_view js_path, bool sql_standard_mode) {
        std::unique_ptr<ValidJSONPathIterator> v;
        return v;
      }

      bool ValidJSONPathIterator::operator++() {
        return false;
      }

      ValidJSONPathIterator::ValidJSONPathIterator(absl::string_view input, bool sql_standard_mode)
        : sql_standard_mode_(sql_standard_mode), text_(input) {
      }

      void ValidJSONPathIterator::Init() {
      }

    }
  }
}
#endif

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/common/json_parser/export.inc"
#include "go-zetasql/common/json_util/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-re2/re2/export.inc"

#endif
