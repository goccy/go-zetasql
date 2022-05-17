#ifndef ZETASQL_PUBLIC_PROTO_VALUE_CONVERSION_EXPORT_H
#define ZETASQL_PUBLIC_PROTO_VALUE_CONVERSION_EXPORT_H

#include "zetasql/public/proto_value_conversion.h"
#include "zetasql/public/proto_value_conversion.cc"

#if 0
namespace zetasql {

  absl::Status MergeValueToProtoField(const Value& value,
                                      const google::protobuf::FieldDescriptor* field,
                                      bool use_wire_format_annotations,
                                      google::protobuf::MessageFactory* message_factory,
                                      google::protobuf::Message* proto_out) {
    return absl::OkStatus();
  }

  absl::Status ConvertStructOrArrayValueToProtoMessage(const Value& value, google::protobuf::MessageFactory* message_factory,
                                                       google::protobuf::Message* proto_out) {
    return absl::OkStatus();
  }

  absl::Status ProtoFieldToValue(const google::protobuf::Message& proto,
                                 const google::protobuf::FieldDescriptor* field, int index,
                                 const Type* type,
                                 bool use_wire_format_annotations,
                                 Value* value_out) {
    return absl::OkStatus();
  }

  absl::Status ConvertProtoMessageToStructOrArrayValue(const google::protobuf::Message& proto, const Type* type, Value* value_out) {
    return absl::OkStatus();
  }

}
#endif

#include "go-zetasql/public/json_value/export.inc"
#include "go-zetasql/public/numeric_value/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/public/value_cc_proto/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/proto/type_annotation_cc_proto/export.inc"
#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/cord/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
