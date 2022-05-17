#ifndef ZETASQL_PUBLIC_ANNOTATION_COLLATION_EXPORT_H
#define ZETASQL_PUBLIC_ANNOTATION_COLLATION_EXPORT_H

#include "zetasql/public/annotation/collation.h"

#include "zetasql/public/annotation/collation.cc"

#if 0
namespace zetasql {

  absl::Status CollationAnnotation::CheckAndPropagateForColumnRef(const ResolvedColumnRef& column_ref,
                                                                  AnnotationMap* result_annotation_map) {
    return absl::OkStatus();
  }

  absl::Status CollationAnnotation::CheckAndPropagateForGetStructField(const ResolvedGetStructField& get_struct_field,
                                                                       AnnotationMap* result_annotation_map) {
    return absl::OkStatus();
  }

  absl::Status CollationAnnotation::CheckAndPropagateForMakeStruct(const ResolvedMakeStruct& make_struct,
                                                                   StructAnnotationMap* result_annotation_map) {
    return absl::OkStatus();
  }

  absl::Status CollationAnnotation::RejectsCollationOnFunctionArguments(const ResolvedFunctionCallBase& function_call) {
    return absl::OkStatus();
  }

  absl::Status CollationAnnotation::CheckAndPropagateForFunctionCallBase(const ResolvedFunctionCallBase& function_call,
                                                                         AnnotationMap* result_annotation_map) {
    return absl::OkStatus();
  }


  absl::Status CollationAnnotation::CheckAndPropagateForSubqueryExpr(const ResolvedSubqueryExpr& subquery_expr,
                                                                     AnnotationMap* result_annotation_map) {
    return absl::OkStatus();
  }

  absl::StatusOr<const AnnotationMap*> CollationAnnotation::GetCollationFromFunctionArguments(const ASTNode* error_location,
                                                                                              const ResolvedFunctionCallBase& function_call,
                                                                                              FunctionEnums::ArgumentCollationMode collation_mode_mask) {
    return absl::OkStatus();
  }

  absl::Status CollationAnnotation::ResolveCollationForResolvedOrderByItem(ResolvedOrderByItem* resolved_order_by_item) {
    return absl::OkStatus();
  }

}
#endif

#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/parser/parse_tree/export.inc"
#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/function_cc_proto/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
