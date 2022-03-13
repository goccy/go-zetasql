#ifndef ZETASQL_BASE_TIME_PROTO_UTIL_EXPORT_H
#define ZETASQL_BASE_TIME_PROTO_UTIL_EXPORT_H

#include "zetasql/base/time_proto_util.h"

#include "zetasql/base/time_proto_util.cc"

#if 0
namespace zetasql_base {

  absl::Status EncodeGoogleApiProto(absl::Time t,
                                    google::protobuf::Timestamp* proto) {
    absl::Status v;
    return v;
  }

  absl::StatusOr<absl::Time> DecodeGoogleApiProto(const google::protobuf::Timestamp& proto) {
    absl::StatusOr<absl::Time> v;
    return v;
  }

}
#endif

#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/time/time/export.inc"

#endif
