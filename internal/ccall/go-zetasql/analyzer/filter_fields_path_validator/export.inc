#ifndef ZETASQL_ANALYZER_FILTER_FIELDS_PATH_VALIDATOR_EXPORT_H
#define ZETASQL_ANALYZER_FILTER_FIELDS_PATH_VALIDATOR_EXPORT_H

#include "zetasql/analyzer/filter_fields_path_validator.h"
#include "zetasql/analyzer/filter_fields_path_validator.cc"

#if 0
namespace zetasql {

  absl::Status FilterFieldsPathValidator::ValidateFieldPath(bool include,
                                                            const std::vector<const google::protobuf::FieldDescriptor*>& field_path) {
    return absl::OkStatus();
  }

  absl::Status FilterFieldsPathValidator::FinalValidation(bool reset_cleared_required_fields) const {
    return absl::OkStatus();
  }

  absl::Status FilterFieldsPathValidator::RecursivelyValidateNode(const FieldPathTrieNode* node) const {
    return absl::OkStatus();
  }

}
#endif

#include "go-zetasql/base/logging/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
