//
// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "zetasql/resolved_ast/resolved_node.h"

#include <queue>

#include "zetasql/base/logging.h"
#include "google/protobuf/descriptor.h"
#include "zetasql/public/constant.h"
#include "zetasql/public/function.h"
#include "zetasql/public/parse_location.h"
#include "zetasql/public/parse_location_range.pb.h"
#include "zetasql/public/proto/type_annotation.pb.h"
#include "zetasql/public/simple_catalog.h"
#include "zetasql/public/strings.h"
#include "zetasql/public/type.h"
#include "zetasql/public/types/type_parameters.h"
#include "zetasql/public/value.h"
#include "zetasql/resolved_ast/resolved_ast.h"
#include "zetasql/resolved_ast/resolved_collation.h"
#include "zetasql/resolved_ast/resolved_column.h"
#include "absl/memory/memory.h"
#include "absl/status/statusor.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#include "zetasql/base/map_util.h"

namespace zetasql {

// ResolvedNode::RestoreFrom is generated in resolved_node.cc.template.

absl::Status ResolvedNode::Accept(ResolvedASTVisitor* visitor) const {
  return absl::OkStatus();
}

absl::Status ResolvedNode::ChildrenAccept(ResolvedASTVisitor* visitor) const {
  return absl::OkStatus();
}

void ResolvedNode::SetParseLocationRange(
    const ParseLocationRange& parse_location_range) {
  parse_location_range_ =
      absl::make_unique<ParseLocationRange>(parse_location_range);
}

void ResolvedNode::ClearParseLocationRange() { parse_location_range_.reset(); }

std::string ResolvedNode::DebugString(
    absl::Span<const NodeAnnotation> annotations) const {
  std::string output;
  DebugStringImpl(this, annotations, /*prefix=1*/ "", /*prefix2=*/"", &output);
  return output;
}

void ResolvedNode::AppendAnnotations(
    const ResolvedNode* node, absl::Span<const NodeAnnotation> annotations,
    std::string* output) {
  if (node == nullptr) {
    return;
  }
  for (const NodeAnnotation& annotation : annotations) {
    if (annotation.node == node) {
      absl::StrAppend(output, " ", annotation.annotation);
      return;
    }
  }
}

void ResolvedNode::DebugStringImpl(const ResolvedNode* node,
                                   absl::Span<const NodeAnnotation> annotations,
                                   const std::string& prefix1,
                                   const std::string& prefix2,
                                   std::string* output) {
  std::vector<DebugStringField> fields;

  // Trees containing nullptr AST nodes are not valid; however we still want
  // them to display a debug string indicating where the null node is in the
  // tree, as this makes debugging easier.
  if (node != nullptr) {
    node->CollectDebugStringFields(&fields);
  }

  // Use multiline DebugString format if any of the fields are ResolvedNodes.
  bool multiline = false;
  for (const DebugStringField& field : fields) {
    if (!field.nodes.empty()) {
      multiline = true;
      break;
    }
  }

  if (node != nullptr) {
    absl::StrAppend(output, prefix2, node->GetNameForDebugString());
  } else {
    absl::StrAppend(output, prefix2, "<nullptr AST node>");
  }

  if (fields.empty()) {
    AppendAnnotations(node, annotations, output);
    *output += "\n";
  } else if (multiline) {
    AppendAnnotations(node, annotations, output);
    *output += "\n";
    for (const DebugStringField& field : fields) {
      const bool print_field_name = !field.name.empty();
      const bool print_one_line = field.nodes.empty();

      if (print_field_name) {
        absl::StrAppend(output, prefix1, "+-", field.name, "=");
        if (print_one_line) {
          absl::StrAppend(output, field.value);
        }
        absl::StrAppend(output, "\n");
      } else if (print_one_line) {
        absl::StrAppend(output, prefix1, "+-", field.value, "\n");
      }

      if (!print_one_line) {
        for (const ResolvedNode* node : field.nodes) {
          const std::string field_name_indent =
              print_field_name ? (&field != &fields.back() ? "| " : "  ") : "";
          const std::string field_value_indent =
              (node != field.nodes.back() ? "| " : "  ");

          DebugStringImpl(
              node, annotations,
              absl::StrCat(prefix1, field_name_indent, field_value_indent),
              absl::StrCat(prefix1, field_name_indent, "+-"), output);
        }
      }
    }
  } else {
    *output += "(";
    for (const DebugStringField& field : fields) {
      if (&field != &fields[0]) *output += ", ";
      if (field.name.empty()) {
        absl::StrAppend(output, field.value);
      } else {
        absl::StrAppend(output, field.name, "=", field.value);
      }
    }
    *output += ")";
    AppendAnnotations(node, annotations, output);
    *output += "\n";
  }
}

void ResolvedNode::CollectDebugStringFields(
    std::vector<DebugStringField>* fields) const {
  // Print parse_location if available.
  const auto location = GetParseLocationRangeOrNULL();
  if (location != nullptr) {
    fields->push_back(
        DebugStringField("parse_location", location->GetString()));
  }
}

bool ResolvedNode::HasDebugStringFieldsWithNodes() const {
  std::vector<DebugStringField> fields;
  CollectDebugStringFields(&fields);
  for (const DebugStringField& field : fields) {
    if (!field.nodes.empty()) {
      return true;
    }
  }
  return false;
}

std::string ResolvedNode::GetNameForDebugString() const {
  return node_kind_string();
}

absl::Status ResolvedNode::CheckNoFieldsAccessed() const {
  return absl::OkStatus();
}

void ResolvedNode::ClearFieldsAccessed() const {}

void ResolvedNode::MarkFieldsAccessed() const {}

// NOTE: An equivalent method on ASTNodes exists in ../parser/parse_tree.cc.
void ResolvedNode::GetDescendantsWithKinds(
    const std::set<ResolvedNodeKind>& node_kinds,
    std::vector<const ResolvedNode*>* found_nodes) const {
  found_nodes->clear();

  // Use non-recursive traversal to avoid stack issues.
  std::queue<const ResolvedNode*> node_queue;
  node_queue.push(this);

  std::vector<const ResolvedNode*> tmp_vector;

  while (!node_queue.empty()) {
    const ResolvedNode* node = node_queue.front();
    node_queue.pop();

    if (zetasql_base::ContainsKey(node_kinds, node->node_kind())) {
      // Emit this node and don't scan its children.
      found_nodes->push_back(node);
    } else {
      // Else queue its children for traversal.
      tmp_vector.clear();
      node->GetChildNodes(&tmp_vector);
      for (const ResolvedNode* tmp_node : tmp_vector) {
        node_queue.push(tmp_node);
      }
    }
  }
}

void ResolvedNode::GetDescendantsSatisfying(
    bool (ResolvedNode::*filter_method)() const,
    std::vector<const ResolvedNode*>* found_nodes) const {
  found_nodes->clear();

  // Use non-recursive traversal to avoid stack issues.
  std::queue<const ResolvedNode*> node_queue;
  node_queue.push(this);

  std::vector<const ResolvedNode*> tmp_vector;

  while (!node_queue.empty()) {
    const ResolvedNode* node = node_queue.front();
    node_queue.pop();

    if ((node->*filter_method)()) {
      found_nodes->push_back(node);
    }

    // Queue node's children for traversal.
    tmp_vector.clear();
    node->GetChildNodes(&tmp_vector);
    for (const ResolvedNode* tmp_node : tmp_vector) {
      node_queue.push(tmp_node);
    }
  }
}

// NameFormat nodes format as
//   <name> := <node>
// if <node> fits on one line (because it has no child fields to print).
//
// Otherwise, they format as
//   <name> :=
//     <node>
//       <children of node>
//       ...
void ResolvedNode::CollectDebugStringFieldsWithNameFormat(
    const ResolvedNode* node, std::vector<DebugStringField>* fields) const {
  ZETASQL_DCHECK(fields->empty());
  if (node == nullptr) {
    return;
  }
  if (node->HasDebugStringFieldsWithNodes()) {
    fields->emplace_back(DebugStringField("" /* name */, node));
  } else {
    node->CollectDebugStringFields(fields);
  }
}

std::string ResolvedNode::GetNameForDebugStringWithNameFormat(
    const std::string& name, const ResolvedNode* node) const {
  if (node == nullptr) {
    return absl::StrCat(name, " := <nullptr AST node>");
  } else if (node->HasDebugStringFieldsWithNodes()) {
    return absl::StrCat(name, " :=");
  } else {
    return absl::StrCat(name, " := ", node->GetNameForDebugString());
  }
}

const int ResolvedNode::GetTreeDepth() const {
  int max_depth = 0;
  std::vector<const ResolvedNode*> children;
  GetChildNodes(&children);
  for (const ResolvedNode* child : children) {
    const int child_depth = child->GetTreeDepth();
    if (child_depth > max_depth) {
      max_depth = child_depth;
    }
  }
  return max_depth + 1;
}

absl::Status ResolvedNode::SaveTo(FileDescriptorSetMap* file_descriptor_set_map,
                                  ResolvedNodeProto* proto) const {
  const ParseLocationRange* parse_location_range =
      GetParseLocationRangeOrNULL();
  if (parse_location_range == nullptr) {
    return absl::OkStatus();
  }
  // Serialize parse location range.
  ZETASQL_ASSIGN_OR_RETURN(*proto->mutable_parse_location_range(),
                   parse_location_range->ToProto());
  return absl::OkStatus();
}

// Methods for classes in the generated code with customized DebugStrings.

// ResolvedComputedColumn gets formatted as
//   <name> := <expr>
// with <expr>'s children printed as its own children.
void ResolvedComputedColumn::CollectDebugStringFields(
    std::vector<DebugStringField>* fields) const {
  SUPER::CollectDebugStringFields(fields);
  CollectDebugStringFieldsWithNameFormat(expr_.get(), fields);
}

std::string ResolvedComputedColumn::GetNameForDebugString() const {
  return GetNameForDebugStringWithNameFormat(column_.ShortDebugString(),
                                             expr_.get());
}

// ResolvedOutputColumn gets formatted as
//   <column> AS <name> [<column->type>]
void ResolvedOutputColumn::CollectDebugStringFields(
    std::vector<DebugStringField>* fields) const {
  SUPER::CollectDebugStringFields(fields);
  ZETASQL_DCHECK(fields->empty());
}

std::string ResolvedOutputColumn::GetNameForDebugString() const {
  return absl::StrCat(column_.DebugString(), " AS ", ToIdentifierLiteral(name_),
                      " [", column_.type()->DebugString(), "]");
}

// ResolvedConstant gets formatted as
//   Constant(name(constant), type[, value]).
void ResolvedConstant::CollectDebugStringFields(
    std::vector<DebugStringField>* fields) const {
  SUPER::CollectDebugStringFields(fields);
  ZETASQL_DCHECK_LE(fields->size(), 2);  // type and parse location

  fields->emplace(fields->begin(), "", constant_->FullName());
  if (constant_->Is<SimpleConstant>()) {
    fields->emplace_back(
        "value", constant_->GetAs<SimpleConstant>()->value().DebugString());
  }
  // TODO: It would be nice if we could also produce the Value
  // associated with a SQLConstant, but we can't have a dependency from
  // here to SQLConstant.
}

std::string ResolvedConstant::GetNameForDebugString() const {
  return absl::StrCat("Constant");
}

void ResolvedSystemVariable::CollectDebugStringFields(
    std::vector<DebugStringField>* fields) const {
  SUPER::CollectDebugStringFields(fields);
  fields->emplace(fields->begin(), "",
                  absl::StrJoin(name_path(), ".",
                                [](std::string* out, const std::string& in) {
                                  absl::StrAppend(out, ToIdentifierLiteral(in));
                                }));
}

std::string ResolvedSystemVariable::GetNameForDebugString() const {
  return absl::StrCat("SystemVariable");
}

// ResolvedFunctionCall gets formatted as
//   FunctionCall(name(arg_types) -> type)
// with only <arguments> printed as children.
void ResolvedFunctionCallBase::CollectDebugStringFields(
    std::vector<DebugStringField>* fields) const {
  SUPER::CollectDebugStringFields(fields);

  ZETASQL_DCHECK_LE(fields->size(), 3);  // type, parse_location and type_annotation_map

  // Clear the "type" field if present.
  fields->erase(std::remove_if(
                    fields->begin(), fields->end(),
                    [](const DebugStringField& x) { return x.name == "type"; }),
                fields->end());

  if (!argument_list_.empty()) {
    // Use empty name to avoid printing "arguments=" with extra indentation.
    fields->emplace_back("", argument_list_);
  } else if (!generic_argument_list_.empty()) {
    fields->emplace_back("", generic_argument_list_);
  }
  if (!hint_list_.empty()) {
    fields->emplace_back("hint_list", hint_list_);
  }
  if (!collation_list_.empty()) {
    fields->emplace_back("collation_list",
                         ResolvedCollation::ToString(collation_list_));
  }
}

std::string ResolvedFunctionCallBase::GetNameForDebugString() const {
  return absl::StrCat(
      node_kind_string(), "(",
      error_mode_ == SAFE_ERROR_MODE ? "{SAFE_ERROR_MODE} " : "",
      function_ != nullptr ? function_->DebugString() : "<unknown>",
      signature_.DebugString(), ")");
}

// ResolvedCast gets formatted as
//   Cast(<from_type> -> <to_type>)
// with only <from_expr> and <return_null_on_error> (if set to true) printed
// as children.
void ResolvedCast::CollectDebugStringFields(
    std::vector<DebugStringField>* fields) const {
  SUPER::CollectDebugStringFields(fields);
  ZETASQL_DCHECK_LE(fields->size(), 2);  // type and parse location

  // Clear the "type" field if present.
  fields->erase(std::remove_if(
                    fields->begin(), fields->end(),
                    [](const DebugStringField& x) { return x.name == "type"; }),
                fields->end());

  if (expr_ != nullptr) {
    // Use empty name to avoid printing "arguments=" with extra indentation.
    fields->emplace_back("", expr_.get());
  }
  if (return_null_on_error_) {
    fields->emplace_back("return_null_on_error", "TRUE");
  }
  if (extended_cast_ != nullptr) {
    fields->emplace_back("extended_cast", extended_cast_.get());
  }
  if (format_ != nullptr) {
    fields->emplace_back("format", format_.get());
  }
  if (time_zone_ != nullptr) {
    fields->emplace_back("time_zone", time_zone_.get());
  }
  if (!type_parameters_.IsEmpty()) {
    fields->emplace_back("type_parameters", type_parameters_.DebugString());
  }
}

std::string ResolvedCast::GetNameForDebugString() const {
  return absl::StrCat("Cast(", expr_->type()->DebugString(), " -> ",
                      type()->DebugString(), ")");
}

// ResolvedExtendedCastElement gets formatted as
//   ResolvedExtendedCastElement(function=name).
void ResolvedExtendedCastElement::CollectDebugStringFields(
    std::vector<DebugStringField>* fields) const {
  SUPER::CollectDebugStringFields(fields);
  ZETASQL_DCHECK_LE(fields->size(), 1);  // function
}

std::string ResolvedExtendedCastElement::GetNameForDebugString() const {
  return absl::StrCat(
      "ResolvedExtendedCastElement(", from_type_->DebugString(), " -> ",
      to_type_->DebugString(), ", function",
      function_ != nullptr ? function_->DebugString() : "<unknown>", ")");
}

// ResolvedMakeProtoField gets formatted as
//   <field>[(format=TIMESTAMP_MILLIS)] := <expr>
// with <expr>'s children printed as its own children.  The required proto
// format is shown in parentheses when present.
// <expr> is normally just a ResolvedColumnRef, but could be a cast expr.
void ResolvedMakeProtoField::CollectDebugStringFields(
    std::vector<DebugStringField>* fields) const {
  SUPER::CollectDebugStringFields(fields);
  CollectDebugStringFieldsWithNameFormat(expr_.get(), fields);
}

std::string ResolvedMakeProtoField::GetNameForDebugString() const {
  // If the MakeProtoFieldNode has any modifiers present, add them
  // in parentheses on the field name.
  std::string name;
  if (field_descriptor_->is_extension()) {
    absl::StrAppend(&name, "[", field_descriptor_->full_name(), "]");
  } else {
    absl::StrAppend(&name, field_descriptor_->name());
  }

  std::vector<std::string> modifiers;
  if (format() != FieldFormat::DEFAULT_FORMAT) {
    modifiers.push_back(
        absl::StrCat("format=", FieldFormat_Format_Name(format_)));
  }

  if (!modifiers.empty()) {
    absl::StrAppend(&name, "(", absl::StrJoin(modifiers, ","), ")");
  }
  return GetNameForDebugStringWithNameFormat(name, expr_.get());
}

// ResolvedOption gets formatted as
//   [<qualifier>.]<name> := <value>
// if no parse location is available. Otherwise, it is formatted as
//   [<qualifier>.]<name>=
//   +-parse_location=<location>
//   +-<value>
void ResolvedOption::CollectDebugStringFields(
    std::vector<DebugStringField>* fields) const {
  SUPER::CollectDebugStringFields(fields);
  if (fields->empty()) {
    CollectDebugStringFieldsWithNameFormat(value_.get(), fields);
  } else {
    fields->emplace_back("", value_.get());
  }
}

std::string ResolvedOption::GetNameForDebugString() const {
  const std::string prefix = absl::StrCat(
      qualifier_.empty() ? ""
                          : absl::StrCat(ToIdentifierLiteral(qualifier_), "."),
      ToIdentifierLiteral(name_));
  if (GetParseLocationRangeOrNULL() == nullptr) {
    return GetNameForDebugStringWithNameFormat(prefix, value_.get());
  }
  return absl::StrCat(prefix, "=");
}

std::string ResolvedWindowFrame::FrameUnitToString(FrameUnit frame_unit) {
  switch (frame_unit) {
    case ResolvedWindowFrame::ROWS:
      return "ROWS";
    case ResolvedWindowFrame::RANGE:
      return "RANGE";
    default:
      ZETASQL_LOG(DFATAL) << "Invalid frame unit: " << frame_unit;
      return absl::StrCat("INVALID_FRAME_UNIT(", frame_unit, ")");
  }
}

std::string ResolvedWindowFrameExpr::BoundaryTypeToString(
    BoundaryType boundary_type) {
  switch (boundary_type) {
    case ResolvedWindowFrameExpr::UNBOUNDED_PRECEDING:
      return "UNBOUNDED PRECEDING";
    case ResolvedWindowFrameExpr::OFFSET_PRECEDING:
      return "OFFSET PRECEDING";
    case ResolvedWindowFrameExpr::CURRENT_ROW:
      return "CURRENT ROW";
    case ResolvedWindowFrameExpr::OFFSET_FOLLOWING:
      return "OFFSET FOLLOWING";
    case ResolvedWindowFrameExpr::UNBOUNDED_FOLLOWING:
      return "UNBOUNDED FOLLOWING";
    default:
      ZETASQL_LOG(DFATAL) << "Invalid boundary Type: " << boundary_type;
      return absl::StrCat("INVALID_BOUNDARY_TYPE(", boundary_type, ")");
  }
}

void ResolvedWindowFrame::CollectDebugStringFields(
    std::vector<DebugStringField>* fields) const {
  SUPER::CollectDebugStringFields(fields);
  fields->emplace_back("start_expr", start_expr_.get());
  fields->emplace_back("end_expr", end_expr_.get());
}

std::string ResolvedWindowFrame::GetFrameUnitString() const {
  return FrameUnitToString(frame_unit_);
}

std::string ResolvedWindowFrame::GetNameForDebugString() const {
  return absl::StrCat(node_kind_string(), "(frame_unit=", GetFrameUnitString(),
                      ")");
}

void ResolvedWindowFrameExpr::CollectDebugStringFields(
    std::vector<DebugStringField>* fields) const {
  SUPER::CollectDebugStringFields(fields);
  if (expression_ != nullptr) {
    // Use empty name to avoid printing "expression=" with extra indentation.
    fields->emplace_back("", expression_.get());
  }
}

std::string ResolvedWindowFrameExpr::GetNameForDebugString() const {
  return absl::StrCat(node_kind_string(),
                      "(boundary_type=", GetBoundaryTypeString(), ")");
}

std::string ResolvedWindowFrameExpr::GetBoundaryTypeString() const {
  return BoundaryTypeToString(boundary_type_);
}

std::string ResolvedInsertStmt::InsertModeToString(InsertMode insert_mode) {
  switch (insert_mode) {
    case ResolvedInsertStmt::OR_ERROR:
      return "OR ERROR";
    case ResolvedInsertStmt::OR_IGNORE:
      return "OR IGNORE";
    case ResolvedInsertStmt::OR_REPLACE:
      return "OR REPLACE";
    case ResolvedInsertStmt::OR_UPDATE:
      return "OR UPDATE";
    default:
      ZETASQL_LOG(DFATAL) << "Invalid insert mode: " << insert_mode;
      return absl::StrCat("INVALID_INSERT_MODE(", insert_mode, ")");
  }
}

std::string ResolvedInsertStmt::GetInsertModeString() const {
  return InsertModeToString(insert_mode_);
}

std::string ResolvedAggregateHavingModifier::HavingModifierKindToString(
    HavingModifierKind kind) {
  switch (kind) {
    case ResolvedAggregateHavingModifier::MAX:
      return "MAX";
    case ResolvedAggregateHavingModifier::MIN:
      return "MIN";
    default:
      ZETASQL_LOG(DFATAL) << "Invalid having modifier kind: " << kind;
      return absl::StrCat("INVALID_HAVING_MODIFIER_KIND(", kind, ")");
  }
}

std::string ResolvedAggregateHavingModifier::GetHavingModifierKindString()
    const {
  return HavingModifierKindToString(kind_);
}

std::string ResolvedImportStmt::ImportKindToString(ImportKind kind) {
  switch (kind) {
    case MODULE:
      return "MODULE";
    case PROTO:
      return "PROTO";
    default:
      ZETASQL_LOG(DFATAL) << "Invalid import kind: " << kind;
      return absl::StrCat("INVALID_IMPORT_KIND(", kind, ")");
  }
}

std::string ResolvedImportStmt::GetImportKindString() const {
  return ImportKindToString(import_kind_);
}

absl::StatusOr<TypeParameters> ResolvedColumnAnnotations::GetFullTypeParameters(
    const Type* type) const {
  // We need Type* to figure out the size of TypeParameters.child_list since
  // TypeParameters.child_list.size() is not equals to
  // ResolvedColumnAnnotations.child_list.size().
  // ResolvedColumnAnnotations.child_list will shrink the list size while
  // TypeParameters.child_list won't, see their contracts for details.

  // Annotations with child_list describes complex type parameters, (e.g.
  // STRUCT<STRING(10)>). We reconstruct full type parameters recursively.
  if (child_list_size() > 0) {
    std::vector<TypeParameters> child_parameters;
    if (type->IsArray()) {
      ZETASQL_RET_CHECK_EQ(child_list_size(), 1);
      ZETASQL_ASSIGN_OR_RETURN(TypeParameters child_parameter,
                       child_list(0)->GetFullTypeParameters(
                           type->AsArray()->element_type()));
      child_parameters.push_back(child_parameter);
    } else if (type->IsStruct()) {
      const StructType* struct_type = type->AsStruct();
      ZETASQL_RET_CHECK_LE(child_list_size(), struct_type->num_fields());
      // TypeParameters.child_list.size() is the same as number of subfields
      // in the STRUCT, which may be longer than child_list.size().
      child_parameters.resize(struct_type->num_fields());
      for (int field_index = 0; field_index < child_list_size();
           ++field_index) {
        ZETASQL_ASSIGN_OR_RETURN(
            child_parameters[field_index],
            child_list(field_index)
                ->GetFullTypeParameters(struct_type->field(field_index).type));
      }
    } else {
      ZETASQL_RET_CHECK_FAIL() << "ResolvedColumnAnnotations has children, but type is "
                          "not STRUCT or ARRAY";
    }

    // If no children has type parameters, return empty type parameters.
    bool has_no_children =
        std::all_of(child_parameters.begin(), child_parameters.end(),
                    std::mem_fn(&TypeParameters::IsEmpty));
    if (has_no_children) {
      return TypeParameters();
    }

    // If children has type parameters, make sure type parameters in root
    // annotation is empty.
    ZETASQL_RET_CHECK(type_parameters().IsEmpty())
        << "ResolvedColumnAnnotations can't have both child type parameters "
           "and root type parameters";
    return TypeParameters::MakeTypeParametersWithChildList(child_parameters);
  }

  // Non-empty type_parameters means annotations with simple type
  // parameters. We directly return type_parameters here.
  if (!type_parameters().IsEmpty()) {
    return type_parameters();
  }

  return TypeParameters();
}

// Gets the type parameters for a complex type (STRUCT or ARRAY etc..) as one
// object, by storing type parameters for subfields in
// TypeParameters.child_list instead of ResolvedColumnAnnotations.child_list.
absl::StatusOr<TypeParameters> ResolvedColumnDefinition::GetFullTypeParameters()
    const {
  if (annotations() == nullptr) {
    return TypeParameters();
  }
  return annotations()->GetFullTypeParameters(type());
}

FunctionEnums::Volatility ResolvedCreateFunctionStmt::volatility() const {
  switch (determinism_level()) {
    case ResolvedCreateStatementEnums::DETERMINISM_VOLATILE:
    case ResolvedCreateStatementEnums::DETERMINISM_NOT_DETERMINISTIC:
    case ResolvedCreateStatementEnums::DETERMINISM_UNSPECIFIED:
      return FunctionEnums::VOLATILE;
    case ResolvedCreateStatementEnums::DETERMINISM_DETERMINISTIC:
    case ResolvedCreateStatementEnums::DETERMINISM_IMMUTABLE:
      return FunctionEnums::IMMUTABLE;
    case ResolvedCreateStatementEnums::DETERMINISM_STABLE:
      return FunctionEnums::STABLE;
  }
}

}  // namespace zetasql
