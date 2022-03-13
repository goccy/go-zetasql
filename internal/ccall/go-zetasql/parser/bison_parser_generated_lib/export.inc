#ifndef ZETASQL_PARSER_BISON_GENERATED_LIB_EXPORT_H
#define ZETASQL_PARSER_BISON_GENERATED_LIB_EXPORT_H

#include "zetasql/parser/bison_parser.bison.h"
#include "zetasql/parser/bison_parser.h"
#include "zetasql/parser/bison_parser_mode.h"
#include "zetasql/parser/flex_tokenizer.h"
#include "zetasql/parser/join_processor.h"
#include "zetasql/parser/location.hh"
#include "zetasql/parser/position.hh"
#include "zetasql/parser/stack.hh"
#include "zetasql/parser/statement_properties.h"

#include "zetasql/parser/bison_parser.bison.cc"
#include "zetasql/parser/flex_tokenizer.flex.cc"
#include "zetasql/parser/join_processor.cc"
#include "flex_tokenizer_base.inc"

/*
template <typename ASTNodeType>
ASTNodeType* WithExtraChildren(
    ASTNodeType* node,
    absl::Span<zetasql::ASTNode* const> children) {
}

using zetasql::ASTInsertStatement;
using zetasql::ASTCreateFunctionStmtBase;
using zetasql::ASTDropStatement;


namespace zetasql_bison_parser {

  BisonParserImpl::BisonParserImpl(zetasql::parser::ZetaSqlFlexTokenizer* tokenizer_yyarg, zetasql::parser::BisonParser* parser_yyarg, zetasql::ASTNode** ast_node_result_yyarg, zetasql::parser::ASTStatementProperties*
                                   ast_statement_properties_yyarg, std::string* error_message_yyarg, zetasql::ParseLocationPoint* error_location_yyarg, bool* move_error_location_past_whitespace_yyarg, int* statement_end_byte_offset_yyarg)
    :
      tokenizer (tokenizer_yyarg),
      parser (parser_yyarg),
      ast_node_result (ast_node_result_yyarg),
      ast_statement_properties (ast_statement_properties_yyarg),
      error_message (error_message_yyarg),
      error_location (error_location_yyarg),
      move_error_location_past_whitespace (move_error_location_past_whitespace_yyarg),
      statement_end_byte_offset (statement_end_byte_offset_yyarg)
  {}

  BisonParserImpl::~BisonParserImpl ()
  {}

  BisonParserImpl::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  template <typename Base>
  BisonParserImpl::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  template <typename Base>
  BisonParserImpl::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  BisonParserImpl::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  BisonParserImpl::symbol_kind_type
  BisonParserImpl::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
  }

  template <typename Base>
  bool
  BisonParserImpl::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return false;
  }

  template <typename Base>
  void
  BisonParserImpl::basic_symbol<Base>::move (basic_symbol& s)
  {
  }

  int BisonParserImpl::operator() () {
    return parse ();
  }

  int BisonParserImpl::parse () {
    return 0;
  }

  void BisonParserImpl::error (const syntax_error& yyexc) {
  }

  std::string BisonParserImpl::symbol_name (symbol_kind_type yysymbol) {
    return "";
  }


  BisonParserImpl::context::context (const BisonParserImpl& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  BisonParserImpl::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    return 0;
  }
}

void zetasql_bison_parser::BisonParserImpl::error(
    const zetasql_bison_parser::location& loc,
    const std::string& msg) {
}

namespace zetasql {
  namespace parser {

    ZetaSqlFlexTokenizer::ZetaSqlFlexTokenizer(BisonParserMode mode, absl::string_view filename,
                                               absl::string_view input, int start_offset,
                                               const LanguageOptions& language_options)
      : filename_(filename),
        start_offset_(start_offset),
        input_size_(static_cast<int64_t>(input.size())),
        mode_(mode),
        language_options_(language_options) {
    }

    ZetaSqlFlexTokenizer::ZetaSqlFlexTokenizer(const ZetaSqlFlexTokenizer&){
    }

    ZetaSqlFlexTokenizer& ZetaSqlFlexTokenizer::operator=(const ZetaSqlFlexTokenizer&){
      return *this;
    }

    int ZetaSqlFlexTokenizer::GetNextTokenFlex(zetasql_bison_parser::location* yylloc) {
      return 0;
    }

    absl::Status ZetaSqlFlexTokenizer::GetNextToken(ParseLocationRange* location, int* token) {
      absl::Status v;
      return v;
    }

    absl::Status ZetaSqlFlexTokenizer::GetOverrideError() const {
      absl::Status v;
      return v;
    }

    void ZetaSqlFlexTokenizer::SetForceTerminate() {
    }

    bool ZetaSqlFlexTokenizer::IsDotGeneralizedIdentifierPrefixToken(int bison_token) const {
      return false;
    }

  }

}

namespace zetasql {
  namespace parser {

    ASTNode* MakeInternalError(ErrorInfo* error_info,
                               const zetasql_bison_parser::location& error_location,
                               const std::string& error_message) {
      return nullptr;
    }

    ASTNode* MakeSyntaxError(ErrorInfo* error_info,
                             const zetasql_bison_parser::location& error_location,
                             const std::string& error_message) {
      return nullptr;
    }

    ASTNode* ProcessFlattenedJoinExpression(BisonParser* parser, std::stack<ASTNode*>* flattened_join_expression,
                                            ErrorInfo* error_info) {
      return nullptr;
    }

    ASTNode* JoinRuleAction(const zetasql_bison_parser::location& start_location,
                            const zetasql_bison_parser::location& end_location, ASTNode* lhs,
                            bool natural, ASTJoin::JoinType join_type, ASTJoin::JoinHint join_hint,
                            ASTNode* hint, ASTNode* table_primary, ASTNode* on_or_using_clause_list,
                            BisonParser* parser,
                            ErrorInfo* error_info) {
      return nullptr;
    }

    ASTNode* CommaJoinRuleAction(const zetasql_bison_parser::location& start_location,
                                 const zetasql_bison_parser::location& end_location, ASTNode* lhs,
                                 ASTNode* table_primary,
                                 BisonParser* parser,
                                 ErrorInfo* error_info) {
      return nullptr;
    }

    ASTNode* TransformJoinExpression(ASTNode* node, BisonParser* parser,
                                     ErrorInfo* error_info) {
      return nullptr;
    }

  }

}
*/
#include "go-zetasql/parser/flex_istream/export.inc"
#include "go-zetasql/parser/keywords/export.inc"
#include "go-zetasql/parser/parse_tree/export.inc"
#include "go-zetasql/base/arena/export.inc"
#include "go-zetasql/base/arena_allocator/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/inlined_vector/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"

#endif
