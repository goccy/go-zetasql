#ifndef ZETASQL_COMMON_PROTO_FROM_ITERATOR_EXPORT_H
#define ZETASQL_COMMON_PROTO_FROM_ITERATOR_EXPORT_H

#include "zetasql/common/proto_from_iterator.h"
#include "zetasql/common/proto_from_iterator.cc"

#if 0
namespace zetasql {

  IteratorProtoDescriptorOptions::IteratorProtoDescriptorOptions() {
  }

  absl::StatusOr<IteratorProtoDescriptors> ConvertIteratorToProto(const EvaluatorTableIterator& iter,
                                                                  const IteratorProtoDescriptorOptions& options,
                                                                  google::protobuf::DescriptorPool& pool) {
    absl::StatusOr<IteratorProtoDescriptors> v;
    return v;
  }

  absl::Status MergeRowToProto(const EvaluatorTableIterator& iter,
                               google::protobuf::MessageFactory& message_factory,
                               google::protobuf::Message& proto_out) {
    return absl::OkStatus();
  }

  absl::StatusOr<std::unique_ptr<google::protobuf::Message>> ProtoFromIterator(EvaluatorTableIterator& iter, const google::protobuf::Descriptor& table,
                                                                               google::protobuf::MessageFactory& message_factory) {
    absl::StatusOr<std::unique_ptr<google::protobuf::Message>> v;
    return v;
  }

}
#endif

#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/evaluator_table_iterator/export.inc"
#include "go-zetasql/public/proto_value_conversion/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
