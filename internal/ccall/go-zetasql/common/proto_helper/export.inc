#ifndef ZETASQL_COMMON_PROTO_HELPER_EXPORT_H
#define ZETASQL_COMMON_PROTO_HELPER_EXPORT_H

#include "zetasql/common/proto_helper.h"
#include "zetasql/common/proto_helper.cc"

#if 0
namespace zetasql {

  absl::Status PopulateFileDescriptorSet(const google::protobuf::FileDescriptor* file_descr,
                                         absl::optional<int64_t> file_descriptor_set_max_size_bytes,
                                         google::protobuf::FileDescriptorSet* file_descriptor_set,
                                         std::set<const google::protobuf::FileDescriptor*>* file_descriptors) {
    return absl::OkStatus();
  }

  absl::Status AddFileDescriptorSetToPool(const google::protobuf::FileDescriptorSet* file_descriptor_set,
                                          google::protobuf::DescriptorPool* pool) {
    return absl::OkStatus();
  }

}
#endif

#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/optional/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
