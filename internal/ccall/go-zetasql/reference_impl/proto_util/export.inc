#ifndef ZETASQL_REFERENCE_IMPL_PROTO_UTIL_EXPORT_H
#define ZETASQL_REFERENCE_IMPL_PROTO_UTIL_EXPORT_H

#include "zetasql/reference_impl/proto_util.h"

namespace zetasql {

  absl::Status ProtoUtil::CheckIsSupportedFieldFormat(FieldFormat::Format format,
                                                      const google::protobuf::FieldDescriptor* field) {
    return absl::OkStatus();
  }

  absl::Status ProtoUtil::WriteField(const WriteFieldOptions& options,
                                     const FieldDescriptor* field_descr,
                                     const FieldFormat::Format format,
                                     const Value& value, bool* nondeterministic,
                                     CodedOutputStream* dst) {
    return absl::OkStatus();
  }

}

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/internal_value/export.inc"
#include "go-zetasql/public/functions/arithmetics/export.inc"
#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-zetasql/public/proto/type_annotation_cc_proto/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-absl/base/base/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/strings/cord/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
