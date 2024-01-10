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

#ifndef ZETASQL_PARSER_FLEX_TOKENIZER_H_
#define ZETASQL_PARSER_FLEX_TOKENIZER_H_

#include <cstdint>
#include <istream>
#include <memory>
#include <sstream>
#include <string>

#include "zetasql/parser/position.hh"
#include "zetasql/public/language_options.h"
#include <cstdint>
#include "absl/flags/flag.h"
#include "absl/memory/memory.h"
#include "absl/strings/match.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/string_view.h"

// Some contortions to avoid duplicate inclusion of FlexLexer.h in the
// generated flex_tokenizer.flex.cc.
#undef yyFlexLexer
#define yyFlexLexer  ZetaSqlFlexTokenizerBase
#include <FlexLexer.h>

#include "zetasql/common/errors.h"
#include "zetasql/parser/bison_parser_mode.h"
#include "zetasql/parser/location.hh"
#include "zetasql/public/parse_location.h"

#include "zetasql/parser/flex_istream.h"
#include "absl/flags/declare.h"
#include "zetasql/base/status.h"
#include "zetasql/base/status_builder.h"

ABSL_DECLARE_FLAG(bool, zetasql_use_customized_flex_istream);

namespace zetasql {
namespace parser {

// Flex-based tokenizer for the ZetaSQL Bison parser.
class ZetaSqlFlexTokenizer final : public ZetaSqlFlexTokenizerBase {
 public:
  // Constructs a simple wrapper around a flex generated tokenizer. 'mode'
  // controls the first token that is returned to the bison parser, which
  // determines the starting production used by the parser.
  // 'filename', 'input', and 'language_options' must outlive this object.
  ZetaSqlFlexTokenizer(BisonParserMode mode, absl::string_view filename,
                         absl::string_view input, int start_offset,
                         const LanguageOptions& language_options)
      : filename_(filename),
        start_offset_(start_offset),
        input_size_(static_cast<int64_t>(input.size())),
        mode_(mode),
        language_options_(language_options) {
    if (absl::GetFlag(FLAGS_zetasql_use_customized_flex_istream)) {
      input_stream_ = absl::make_unique<StringStreamWithSentinel>(input);
    } else {
      input_stream_ = absl::make_unique<std::istringstream>(
          absl::StrCat(input, kEofSentinelInput));
    }
    // Seek the stringstream to the start_offset, and then instruct flex to read
    // from the stream. (Flex has the ability to read multiple consecutive
    // streams, but we only ever feed it one.)
    input_stream_->seekg(start_offset, std::ios_base::beg);
    switch_streams(input_stream_.get() /* new_in */, nullptr /* new_out */);
  }

  ZetaSqlFlexTokenizer(const ZetaSqlFlexTokenizer&) = delete;
  ZetaSqlFlexTokenizer& operator=(const ZetaSqlFlexTokenizer&) = delete;

  // Returns the next token id, returning its location in 'yylloc'. On input,
  // 'yylloc' must be the location of the previous token that was returned.
  int GetNextTokenFlex(zetasql_bison_parser::location* yylloc) {
    prev_token_ = GetNextTokenFlexImpl(yylloc);
    return prev_token_;
  }

  // This is the "nice" API for the tokenizer, to be used by GetParseTokens().
  // On input, 'location' must be the location of the previous token that was
  // generated. Returns the Bison token id in 'token' and the ZetaSQL location
  // in 'location'. Returns an error if the tokenizer sets override_error.
  absl::Status GetNextToken(ParseLocationRange* location, int* token);

  // Returns a non-OK error status if the tokenizer encountered an error. This
  // error takes priority over a parser error, because the parser error is
  // always a consequence of the tokenizer error.
  absl::Status GetOverrideError() const {
    return override_error_;
  }

  // Ensures that the next token returned will be EOF, even if we're not at the
  // end of the input.
  void SetForceTerminate() { force_terminate_ = true; }

  // Helper function for determining if the given 'bison_token' followed by "."
  // should trigger the generalized identifier tokenizer mode.
  bool IsDotGeneralizedIdentifierPrefixToken(int bison_token) const;

 private:
  void SetOverrideError(const zetasql_bison_parser::location& yylloc,
                        const std::string& error_message) {
    override_error_ = MakeSqlErrorAtPoint(ParseLocationPoint::FromByteOffset(
        filename_, yylloc.begin.column)) << error_message;
  }

  // This method is implemented by the flex generated tokenizer. On input,
  // 'yylloc' must be the location of the previous token that was returned.
  // Returns the next token id, returning its location in 'yylloc'.
  int GetNextTokenFlexImpl(zetasql_bison_parser::location* yylloc);

  // This is called by flex when it is wedged.
  void LexerError(const char* msg) override {
    override_error_ = MakeSqlError() << msg;
  }

  // Given a fragment of text that starts with an identifier, returns the length
  // of just the identifier portion of the text. Backquotes are included in the
  // returned length if the identifier is correctly backquoted.
  int GetIdentifierLength(absl::string_view text);

  bool IsReservedKeyword(absl::string_view text) const;

  // EOF sentinel input. This is appended to the input and used as a sentinel in
  // the tokenizer. The reason for doing this is that some tokenizer rules
  // try to match trailing context of the form [^...] where "..." is a set of
  // characters that should *not* be present after the token. Unfortunately
  // these rules actually also need to be triggered if, instead of "any
  // character that is not in [...]", there is EOF. For instance, the
  // unterminated comment rule cannot include the last star in "/* abcdef *"
  // because it looks for a * followed by "something that is not a star". To
  // solve this, we add some useless input characters at the end of the stream
  // that are not in any [...] used by affected rules. The useless input
  // characters are never returned as a token; when it is found, we return EOF
  // instead. All "open ended tokens" (unclosed string literal / comment)
  // that would include this bogus character in their location range are not
  // affected because they are all error tokens, and they immediately produce
  // errors that mention only their start location.
  static constexpr char kEofSentinelInput[] = "\n";

  // True only before the first call to lex(). We use an artificial first token
  // to determine which mode the bison parser should run in.
  bool is_first_token_ = true;

  // The code for the previous token that was returned. This is used to take
  // action in tokenizer rules based on context.
  int prev_token_ = 0;

  // The (optional) filename from which the statement is being parsed.
  absl::string_view filename_;

  // The offset in the input of the first byte that is tokenized. This is used
  // to determine the returned location for the first token.
  const int start_offset_ = 0;

  // The length of the input string without the sentinel.
  const int input_size_;
  // An input stream over the input string (of size input_size_) plus the
  // sentinel.
  std::unique_ptr<std::istream> input_stream_;

  // This determines the first token returned to the bison parser, which
  // determines the mode that we'll run in.
  const BisonParserMode mode_;

  // The tokenizer may want to return an error directly. It does this by
  // returning EOF to the bison parser, which then may or may not spew out its
  // own error message. The BisonParser wrapper then grabs the error from the
  // tokenizer instead.
  absl::Status override_error_;

  // If this is set to true, the next token returned will be EOF, even if we're
  // not at the end of the input.
  bool force_terminate_ = false;

  // LanguageOptions passed in from parser, used to decide if reservable
  // keywords are reserved or not.
  const LanguageOptions& language_options_;
};

}  // namespace parser
}  // namespace zetasql

// This incantation is necessary because for some reason these functions are not
// generated for ZetaSqlFlexTokenizerBase, but the class does reference them.
inline int ZetaSqlFlexTokenizerBase::yylex() { return 0; }
inline int ZetaSqlFlexTokenizerBase::yywrap() { return 1; }

#endif  // ZETASQL_PARSER_FLEX_TOKENIZER_H_
