#ifndef ZETASQL_PUBLIC_FUNCTIONS_CONVERT_PROTO_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_CONVERT_PROTO_EXPORT_H

#include "zetasql/public/functions/convert_proto.h"
#include "zetasql/public/functions/convert_proto.cc"

#if 0
namespace zetasql {
  namespace functions {

    bool ProtoToString(const google::protobuf::Message* value, absl::Cord* out, absl::Status* error) {
      return false;
    }

    bool ProtoToMultilineString(const google::protobuf::Message* value, absl::Cord* out, absl::Status* error) {
      return false;
    }

    bool StringToProto(const absl::string_view value, google::protobuf::Message* out, absl::Status* error) {
      return false;
    }

  }
}
#endif

#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-absl/strings/cord/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
