#ifndef ZETASQL_PUBLIC_FUNCTIONS_STRING_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_STRING_EXPORT_H

#include "zetasql/public/functions/string.h"
#include "zetasql/public/functions/string.cc"

#if 0
namespace zetasql {
  namespace functions {

    bool Utf8Trimmer::Initialize(absl::string_view to_trim, absl::Status* error) {
      return false;
    }

    bool Utf8Trimmer::TrimLeft(absl::string_view str, absl::string_view* out, absl::Status* error) const {
      return false;
    }

    bool Utf8Trimmer::TrimRight(absl::string_view str, absl::string_view* out, absl::Status* error) const {
      return false;
    }

    bool Utf8Trimmer::Trim(absl::string_view str, absl::string_view* out, absl::Status* error) const {
      return false;
    }

    void BytesTrimmer::Initialize(absl::string_view to_trim) {
    }

    absl::string_view BytesTrimmer::TrimLeft(absl::string_view str) {
      return "";
    }

    absl::string_view BytesTrimmer::TrimRight(absl::string_view str) {
      return "";
    }

    absl::string_view BytesTrimmer::Trim(absl::string_view str) {
      return "";
    }

    bool Utf8Capitalizer::Initialize(absl::string_view delimiters, absl::Status* error) {
      return false;
    }

    bool Utf8Capitalizer::InitializeDefault(absl::Status* error) {
      return false;
    }

    bool Utf8Capitalizer::Capitalize(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool LengthUtf8(absl::string_view str, int64_t* out, absl::Status* error) {
      return false;
    }

    bool LengthBytes(absl::string_view str, int64_t* out, absl::Status* error) {
      return false;
    }

    bool StartsWithUtf8(absl::string_view str, absl::string_view substr, bool* out, absl::Status* error) {
      return false;
    }

    bool StartsWithBytes(absl::string_view str, absl::string_view substr, bool* out, absl::Status* error) {
      return false;
    }

    bool EndsWithUtf8(absl::string_view str, absl::string_view substr, bool* out, absl::Status* error) {
      return false;
    }

    bool EndsWithBytes(absl::string_view str, absl::string_view substr, bool* out, absl::Status* error) {
      return false;
    }

    bool TrimSpacesUtf8(absl::string_view str, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool LeftTrimSpacesUtf8(absl::string_view str, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool RightTrimSpacesUtf8(absl::string_view str, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool TrimUtf8(absl::string_view str, absl::string_view chars, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool LeftTrimUtf8(absl::string_view str, absl::string_view chars, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool RightTrimUtf8(absl::string_view str, absl::string_view chars, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool TrimBytes(absl::string_view str, absl::string_view chars, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool LeftTrimBytes(absl::string_view str, absl::string_view chars, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool RightTrimBytes(absl::string_view str, absl::string_view chars, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool LeftUtf8(absl::string_view str, int64_t length, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool LeftBytes(absl::string_view str, int64_t length, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool RightUtf8(absl::string_view str, int64_t length, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool RightBytes(absl::string_view str, int64_t length, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool SubstrUtf8(absl::string_view str, int64_t pos, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool StrPosOccurrenceUtf8(absl::string_view str, absl::string_view substr, int64_t pos, int64_t occurrence, int64_t* out, absl::Status* error) {
      return false;
    }

    bool StrPosOccurrenceBytes(absl::string_view str, absl::string_view substr, int64_t pos, int64_t occurrence, int64_t* out, absl::Status* error) {
      return false;
    }

    bool SubstrWithLengthUtf8(absl::string_view str, int64_t pos, int64_t length, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool SubstrBytes(absl::string_view str, int64_t pos, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool SubstrWithLengthBytes(absl::string_view str, int64_t pos, int64_t length, absl::string_view* out, absl::Status* error) {
      return false;
    }

    bool UpperUtf8(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool LowerUtf8(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool UpperBytes(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool LowerBytes(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool InitialCapitalize(absl::string_view str, absl::string_view delimiters, std::string* out, absl::Status* error) {
      return false;
    }

    bool InitialCapitalizeDefault(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool ReplaceUtf8(absl::string_view str, absl::string_view oldsub, absl::string_view newsub, std::string* out, absl::Status* error) {
      return false;
    }

    bool ReplaceBytes(absl::string_view str, absl::string_view oldsub, absl::string_view newsub, std::string* out, absl::Status* error) {
      return false;
    }

    template <class Container>
    bool SplitUtf8Impl(absl::string_view str, absl::string_view delimiter, Container* out, absl::Status* error) {
      return false;
    }

    bool SplitUtf8(absl::string_view str, absl::string_view delimiter, std::vector<std::string>* out, absl::Status* error) {
      return false;
    }

    bool SplitUtf8(absl::string_view str, absl::string_view delimiter, std::vector<absl::string_view>* out, absl::Status* error) {
      return false;
    }

    bool SplitBytes(absl::string_view str, absl::string_view delimiter, std::vector<std::string>* out, absl::Status* error) {
      return false;
    }

    bool SplitBytes(absl::string_view str, absl::string_view delimiter, std::vector<absl::string_view>* out, absl::Status* error) {
      return false;
    }

    bool SafeConvertBytes(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool Normalize(absl::string_view str, NormalizeMode mode, bool is_casefold, std::string* out, absl::Status* error) {
      return false;
    }

    bool ToBase64(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool FromBase64(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool ToHex(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool FromHex(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool FirstCharOfStringToASCII(absl::string_view str, int64_t* out, absl::Status* error) {
      return false;
    }

    bool FirstByteOfBytesToASCII(absl::string_view str, int64_t* out, absl::Status* error) {
      return false;
    }

    bool FirstCharToCodePoint(absl::string_view str, int64_t* out, absl::Status* error) {
      return false;
    }

    bool CodePointToString(int64_t codepoint, std::string* out, absl::Status* error) {
      return false;
    }

    bool StringToCodePoints(absl::string_view str, std::vector<int64_t>* out, absl::Status* error) {
      return false;
    }

    bool BytesToCodePoints(absl::string_view str, std::vector<int64_t>* out, absl::Status* error) {
      return false;
    }

    bool CodePointsToString(absl::Span<const int64_t> codepoints, std::string* out, absl::Status* error) {
      return false;
    }

    bool CodePointsToBytes(absl::Span<const int64_t> codepoints, std::string* out, absl::Status* error) {
      return false;
    }

    bool LeftPadBytes(absl::string_view input_str, int64_t output_size_bytes, absl::string_view pattern, std::string* out, absl::Status* error) {
      return false;
    }

    bool LeftPadBytesDefault(absl::string_view input_str, int64_t output_size_bytes, std::string* out, absl::Status* error) {
      return false;
    }

    bool LeftPadUtf8(absl::string_view input_str, int64_t output_size_chars, absl::string_view pattern, std::string* out, absl::Status* error) {
      return false;
    }

    bool LeftPadUtf8Default(absl::string_view input_str, int64_t output_size_chars, std::string* out, absl::Status* error) {
      return false;
    }

    bool RightPadBytes(absl::string_view input_str, int64_t output_size_bytes, absl::string_view pattern, std::string* out, absl::Status* error) {
      return false;
    }

    bool RightPadBytesDefault(absl::string_view input_str, int64_t output_size_bytes, std::string* out, absl::Status* error) {
      return false;
    }

    bool RightPadUtf8(absl::string_view input_str, int64_t output_size_chars, absl::string_view pattern, std::string* out, absl::Status* error) {
      return false;
    }

    bool RightPadUtf8Default(absl::string_view input_str, int64_t output_size_chars, std::string* out, absl::Status* error) {
      return false;
    }

    bool Repeat(absl::string_view input_str, int64_t repeat_count, std::string* out, absl::Status* error) {
      return false;
    }

    bool ReverseBytes(absl::string_view input, std::string* out, absl::Status* error) {
      return false;
    }

    bool ReverseUtf8(absl::string_view input, std::string* out, absl::Status* error) {
      return false;
    }

    LikeRewriteType GetRewriteForLikePattern(bool is_string, absl::string_view pattern, absl::string_view* substring) {
      LikeRewriteType v;
      return v;
    }

    bool Soundex(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool Utf8Translator::Initialize(absl::string_view source_characters, absl::string_view target_characters, absl::Status* error) {
      return false;
    }

    bool Utf8Translator::Translate(absl::string_view str, std::string* out, absl::Status* error) const {
      return false;
    }

    bool BytesTranslator::Initialize(absl::string_view source_bytes, absl::string_view target_bytes, absl::Status* error) {
      return false;
    }

    bool BytesTranslator::Translate(absl::string_view str, std::string* out, absl::Status* error) const {
      return false;
    }

    bool TranslateUtf8(absl::string_view str, absl::string_view source_characters, absl::string_view target_characters, std::string* out, absl::Status* error) {
      return false;
    }

    bool TranslateBytes(absl::string_view str, absl::string_view source_bytes, absl::string_view target_bytes, std::string* out, absl::Status* error) {
      return false;
    }

    bool ToBase8(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool FromBase8(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool ToBase2(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool FromBase2(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool ASCIICheckAndCopy(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool UTF8CheckAndCopy(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    bool ToBase64m(absl::string_view str, std::string* out, absl::Status* error) {
      return false;
    }

    const ConversionFuncMap& GetConversionFuncMap() {
      ConversionFuncMap *v;
      return *v;
    }

    absl::Status BytesToString(absl::string_view str, absl::string_view format, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status StringToBytes(absl::string_view str, absl::string_view format, std::string* out) {
      return absl::OkStatus();
    }

    absl::Status ValidateFormat(absl::string_view format) {
      return absl::OkStatus();
    }

  }
}
#endif

#include "go-zetasql/public/functions/normalize_mode_cc_proto/export.inc"
#include "go-zetasql/public/functions/util/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/stl_util/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/common/utf_util/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-absl/base/base/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/span/export.inc"

#endif
