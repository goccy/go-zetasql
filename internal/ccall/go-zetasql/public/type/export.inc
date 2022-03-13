#ifndef ZETASQL_PUBLIC_TYPE_EXPORT_H
#define ZETASQL_PUBLIC_TYPE_EXPORT_H

#include "zetasql/public/type.h"
#include "zetasql/public/convert_type_to_proto.h"

#include "zetasql/public/convert_type_to_proto.cc"

#if 0

namespace zetasql {

  typedef ConvertTypeToProtoOptions::MessageOrEnumDescriptor
  MessageOrEnumDescriptor;

  absl::Status ConvertStructToProto(const StructType* struct_type,
                                    google::protobuf::FileDescriptorProto* file,
                                    const ConvertTypeToProtoOptions& options) {
    return absl::OkStatus();
  }

  absl::Status ConvertArrayToProto(const ArrayType* array_type,
                                   google::protobuf::FileDescriptorProto* file,
                                   const ConvertTypeToProtoOptions& options) {
    return absl::OkStatus();
  }

  absl::Status ConvertTableToProto(const std::vector<std::pair<std::string, const Type*>>& columns,
                                   bool is_value_table, google::protobuf::FileDescriptorProto* file,
                                   const ConvertTypeToProtoOptions& options) {
    return absl::OkStatus();
  }

  absl::Status ConvertTableToProto(const Type* row_type,
                                   bool is_value_table,
                                   google::protobuf::FileDescriptorProto* file,
                                   const ConvertTypeToProtoOptions& options) {
    return absl::OkStatus();
  }

  static google::protobuf::DescriptorProto* FindDescriptorProtoImpl(const std::vector<std::string>& message_names, int message_names_at,
                                                                    google::protobuf::DescriptorProto* current_message) {
    return nullptr;
  }

  static google::protobuf::DescriptorProto* FindDescriptorProto(google::protobuf::FileDescriptorProto* file, const std::string& full_name) {
    return nullptr;
  }

  absl::Status AddValueTableAnnotationForProto(const std::string& message_full_name, google::protobuf::FileDescriptorProto* file) {
    return absl::OkStatus();
  }

}

#endif

#include "go-zetasql/public/proto/type_annotation_cc_proto/export.inc"
#include "go-zetasql/public/type_annotation_cc_proto/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/case/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
