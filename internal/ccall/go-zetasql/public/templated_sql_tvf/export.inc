#ifndef ZETASQL_PUBLIC_TEMPLATED_SQL_TVF_EXPORT_H
#define ZETASQL_PUBLIC_TEMPLATED_SQL_TVF_EXPORT_H

#include "zetasql/public/templated_sql_tvf.h"
#include "zetasql/public/templated_sql_tvf.cc"

#if 0
namespace zetasql {

  absl::Status TemplatedSQLTVF::Serialize(FileDescriptorSetMap* file_descriptor_set_map,
                                          TableValuedFunctionProto* proto) const {
    return absl::OkStatus();
  }

  absl::Status TemplatedSQLTVF::Deserialize(const TableValuedFunctionProto& proto,
                                            const std::vector<const google::protobuf::DescriptorPool*>& pools,
                                            TypeFactory* factory, std::unique_ptr<TableValuedFunction>* result) {
    return absl::OkStatus();
  }

  absl::Status TemplatedSQLTVF::Resolve(const AnalyzerOptions* analyzer_options,
                                        const std::vector<TVFInputArgumentType>& input_arguments,
                                        const FunctionSignature& concrete_signature, Catalog* catalog,
                                        TypeFactory* type_factory,
                                        std::shared_ptr<TVFSignature>* tvf_signature) const {
    return absl::OkStatus();
  }

  absl::Status TemplatedSQLTVF::CheckIsValid() const {
    return absl::OkStatus();
  }

  absl::Status TemplatedSQLTVF::ForwardNestedResolutionAnalysisError(const absl::Status& status, ErrorMessageMode mode) const {
    return absl::OkStatus();
  }

  absl::Status TemplatedSQLTVF::MakeTVFQueryAnalysisError(const std::string& message) const {
    return absl::OkStatus();
  }

  TemplatedSQLTVFSignature::~TemplatedSQLTVFSignature() {
  }

}
#endif

#include "go-zetasql/public/analyzer/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/cycle_detector/export.inc"
#include "go-zetasql/public/deprecation_warning_cc_proto/export.inc"
#include "go-zetasql/public/error_helpers/export.inc"
#include "go-zetasql/public/error_location_cc_proto/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/function_cc_proto/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/parse_resume_location/export.inc"
#include "go-zetasql/public/simple_table_cc_proto/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/analyzer/name_scope/export.inc"
#include "go-zetasql/analyzer/resolver/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/status_payload_utils/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/proto/function_cc_proto/export.inc"
#include "go-zetasql/proto/internal_error_location_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast_enums_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
