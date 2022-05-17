#ifndef ZETASQL_PUBLIC_FUNCTIONS_JSON_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_JSON_EXPORT_H

#include "zetasql/public/functions/json.h"
#include "zetasql/public/functions/json.cc"

#if 0
namespace zetasql {
  namespace functions {

    JsonPathEvaluator::~JsonPathEvaluator() {}

    JsonPathEvaluator::JsonPathEvaluator(std::unique_ptr<ValidJSONPathIterator> itr)
      : path_iterator_(std::move(itr)) {}

    absl::StatusOr<std::unique_ptr<JsonPathEvaluator>> JsonPathEvaluator::Create(absl::string_view json_path, bool sql_standard_mode) {
      std::unique_ptr<JsonPathEvaluator> v;
      return v;
    }

    absl::Status JsonPathEvaluator::Extract(absl::string_view json, std::string* value, bool* is_null) const {
      return absl::OkStatus();
    }

    absl::optional<JSONValueConstRef> JsonPathEvaluator::Extract(JSONValueConstRef input) const {
      return absl::nullopt;
    }

    absl::Status JsonPathEvaluator::ExtractScalar(absl::string_view json, std::string* value, bool* is_null) const {
      return absl::OkStatus();
    }

    absl::optional<std::string> JsonPathEvaluator::ExtractScalar(JSONValueConstRef input) const {
      return absl::nullopt;
    }

    absl::Status JsonPathEvaluator::ExtractArray(absl::string_view json, std::vector<std::string>* value, bool* is_null) const {
      return absl::OkStatus();
    }

    absl::optional<std::vector<JSONValueConstRef>> JsonPathEvaluator::ExtractArray(JSONValueConstRef input) const {
      return absl::nullopt;
    }

    absl::Status JsonPathEvaluator::ExtractStringArray(absl::string_view json, std::vector<absl::optional<std::string>>* value, bool* is_null) const {
      return absl::OkStatus();
    }

    absl::optional<std::vector<absl::optional<std::string>>> JsonPathEvaluator::ExtractStringArray(JSONValueConstRef input) const {
      return absl::nullopt;
    }

    std::string ConvertJSONPathTokenToSqlStandardMode(absl::string_view json_path_token) {
      return "";
    }

    absl::StatusOr<std::string> ConvertJSONPathToSqlStandardMode(absl::string_view json_path) {
      return "";
    }

    absl::StatusOr<std::string> MergeJSONPathsIntoSqlStandardMode(absl::Span<const std::string> json_paths) {
      return "";
    }

    absl::StatusOr<int64_t> ConvertJsonToInt64(JSONValueConstRef input) {
      return 0;
    }

    absl::StatusOr<bool> ConvertJsonToBool(JSONValueConstRef input) {
      return false;
    }

    absl::StatusOr<std::string> ConvertJsonToString(JSONValueConstRef input) {
      return "";
    }

    absl::StatusOr<double> ConvertJsonToDouble(JSONValueConstRef input, WideNumberMode wide_number_mode, ProductMode product_mode) {
      return 0;
    }

    absl::StatusOr<std::string> GetJsonType(JSONValueConstRef input) {
      return "";
    }

  }
}
#endif

#include "go-zetasql/public/functions/json_format/export.inc"
#include "go-zetasql/public/functions/json_internal/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/int_ops_util/export.inc"
#include "go-zetasql/public/json_value/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-re2/re2/export.inc"

#endif
