#ifndef ZETASQL_COMMON_STATUS_PAYLOAD_UTILS_EXPORT_H
#define ZETASQL_COMMON_STATUS_PAYLOAD_UTILS_EXPORT_H

#include "zetasql/common/status_payload_utils.h"
#include "zetasql/common/status_payload_utils.cc"

#if 0
namespace zetasql {
  namespace internal {

    bool HasPayload(const absl::Status& status) {
      return false;
    }

    int GetPayloadCount(const absl::Status& status) {
      return 0;
    }

    std::string PayloadToString(absl::string_view type_url,
                                const absl::Cord& payload) {
      return "";
    }

    std::string LegacyStatusCodeToString(absl::StatusCode code) {
      return "";
    }

    std::string PayloadToString(const absl::Status& status) {
      return "";
    }

    std::string StatusToString(const absl::Status& status) {
      return "";
    }

  }
}
#endif

#include "go-zetasql/base/status/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/strings/cord/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
