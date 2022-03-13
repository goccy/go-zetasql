#ifndef ZETASQL_PARSER_PARSE_TREE_SERIALIZER_EXPORT_H
#define ZETASQL_PARSER_PARSE_TREE_SERIALIZER_EXPORT_H

#include "zetasql/parser/parse_tree_serializer.h"
#include "zetasql/parser/parser.h"
#include "zetasql/parser/statement_properties.h"

namespace zetasql {
  absl::Status ParseTreeSerializer::Serialize(const ASTStatement* node, AnyASTStatementProto* proto) {
    absl::Status v;
    return v;
  }

  absl::Status ParseTreeSerializer::Serialize(const ASTExpression* node, AnyASTExpressionProto* proto) {
    absl::Status v;
    return v;
  }

  absl::Status ParseTreeSerializer::Serialize(const ASTType* node, AnyASTTypeProto* proto) {
    absl::Status v;
    return v;
  }

  absl::StatusOr<std::unique_ptr<ParserOutput>> ParseTreeSerializer::Deserialize(const AnyASTStatementProto& proto, const ParserOptions& parser_options_in) {
    std::unique_ptr<ParserOutput> v;
    return v;
  }
}

#include "go-zetasql/parser/parse_tree/export.inc"
#include "go-zetasql/parser/parse_tree_cc_proto/export.inc"
#include "go-zetasql/base/arena/export.inc"
#include "go-zetasql/base/arena_allocator/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/variant/export.inc"

#endif
