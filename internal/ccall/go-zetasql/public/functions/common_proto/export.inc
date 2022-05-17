#ifndef ZETASQL_PUBLIC_FUNCTIONS_COMMON_PROTO_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_COMMON_PROTO_EXPORT_H

#include "zetasql/public/functions/common_proto.h"
#include "zetasql/public/functions/common_proto.cc"

#if 0
namespace zetasql {
  namespace functions {

    absl::Status ConvertTimeToProto3TimeOfDay(TimeValue input, google::type::TimeOfDay* output) {
      return absl::OkStatus();
    }

    absl::Status ConvertProto3TimeOfDayToTime(const google::type::TimeOfDay& input, TimestampScale scale, TimeValue* output) {
      return absl::OkStatus();
    }

  }
}
#endif

#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/utf_util/export.inc"
#include "go-zetasql/public/civil_time/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/cord/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
