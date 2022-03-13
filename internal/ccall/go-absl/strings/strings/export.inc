#ifndef ABSL_STRINGS_STRINGS_EXPORT_H
#define ABSL_STRINGS_STRINGS_EXPORT_H

#include "absl/strings/string_view.h"
#include "absl/strings/ascii.h"
#include "absl/strings/charconv.h"
#include "absl/strings/escaping.h"
#include "absl/strings/internal/string_constant.h"
#include "absl/strings/match.h"
#include "absl/strings/numbers.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#include "absl/strings/str_replace.h"
#include "absl/strings/str_split.h"
#include "absl/strings/string_view.h"
#include "absl/strings/strip.h"
#include "absl/strings/substitute.h"

#include "absl/strings/internal/charconv_bigint.h"
#include "absl/strings/internal/charconv_parse.h"
#include "absl/strings/internal/stl_type_traits.h"
#include "absl/strings/internal/str_join_internal.h"
#include "absl/strings/internal/str_split_internal.h"

#include "absl/strings/ascii.cc"
#include "absl/strings/charconv.cc"
#include "absl/strings/escaping.cc"
#include "absl/strings/internal/charconv_bigint.cc"
#include "absl/strings/internal/charconv_bigint.h"
#include "absl/strings/internal/charconv_parse.cc"
#include "absl/strings/internal/charconv_parse.h"
#include "absl/strings/internal/memutil.cc"
#include "absl/strings/internal/memutil.h"
#include "absl/strings/internal/stl_type_traits.h"
#include "absl/strings/internal/str_join_internal.h"
#include "absl/strings/internal/str_split_internal.h"
#include "absl/strings/match.cc"

#define kAsciiToInt GO_EXPORT(stringskAsciiToInt)
#include "absl/strings/numbers.cc"
#undef kAsciiToInt

#include "absl/strings/str_cat.cc"
#include "absl/strings/str_replace.cc"
#include "absl/strings/str_split.cc"
#include "absl/strings/string_view.cc"
#include "absl/strings/substitute.cc"

#if 0

namespace absl {
  namespace ascii_internal {
    const unsigned char kPropertyBits[256] = {};
    const char kToLower[256] = {};
    const char kToUpper[256] = {};
  }

  void AsciiStrToLower(std::string* s) {
  }

  void AsciiStrToUpper(std::string* s) {
  }

  void RemoveExtraAsciiWhitespace(std::string* str) {
  }

}


namespace absl {

  from_chars_result from_chars(const char* first, const char* last, double& value,
                               chars_format fmt) {
    from_chars_result v;
    return v;
  }

  from_chars_result from_chars(const char* first, const char* last, float& value,
                               chars_format fmt) {
    from_chars_result v;
    return v;
  }

}

namespace absl {

  bool CUnescape(absl::string_view source, std::string* dest,
                 std::string* error) {
    return false;
  }

  std::string CEscape(absl::string_view src) {
    return "";
  }

  std::string CHexEscape(absl::string_view src) {
    return "";
  }

  std::string Utf8SafeCEscape(absl::string_view src) {
    return "";
  }

  std::string Utf8SafeCHexEscape(absl::string_view src) {
    return "";
  }

  bool Base64Unescape(absl::string_view src, std::string* dest) {
    return false;
  }

  bool WebSafeBase64Unescape(absl::string_view src, std::string* dest) {
    return false;
  }

  void Base64Escape(absl::string_view src, std::string* dest) {
  }

  void WebSafeBase64Escape(absl::string_view src, std::string* dest) {
  }

  std::string Base64Escape(absl::string_view src) {
    return "";
  }

  std::string WebSafeBase64Escape(absl::string_view src) {
    return "";
  }

  std::string HexStringToBytes(absl::string_view from) {
    return "";
  }

  std::string BytesToHexString(absl::string_view from) {
    return "";
  }

}

namespace absl {
  namespace strings_internal {

    const uint32_t kFiveToNth[14] = {};
    const uint32_t kTenToNth[10] = {};

    template <int max_words>
    int BigUnsigned<max_words>::ReadFloatMantissa(const ParsedFloat& fp,
                                                  int significant_digits) {
      return 0;
    }

    template <int max_words>
    int BigUnsigned<max_words>::ReadDigits(const char* begin, const char* end,
                                           int significant_digits) {
      return 0;
    }

    template <int max_words>
    BigUnsigned<max_words> BigUnsigned<max_words>::FiveToTheNth(int n) {
      BigUnsigned<max_words> v;
      return v;
    }

    template <int max_words>
    void BigUnsigned<max_words>::MultiplyStep(int original_size,
                                              const uint32_t* other_words,
                                              int other_size, int step) {
    }

    template <int max_words>
    std::string BigUnsigned<max_words>::ToString() const {
      return "";
    }

    template class BigUnsigned<4>;
    template class BigUnsigned<84>;

  }
}

namespace absl {

  namespace strings_internal {

    template <int base>
    strings_internal::ParsedFloat ParseFloat(const char* begin, const char* end,
                                             chars_format format_flags) {
      strings_internal::ParsedFloat v;
      return v;
    }

    template ParsedFloat ParseFloat<10>(const char* begin, const char* end,
                                        chars_format format_flags);
    template ParsedFloat ParseFloat<16>(const char* begin, const char* end,
                                        chars_format format_flags);

  }
}

namespace absl {
  namespace strings_internal {

    int memcasecmp(const char* s1, const char* s2, size_t len) {
      return 0;
    }

    char* memdup(const char* s, size_t slen) {
      return nullptr;
    }

    char* memrchr(const char* s, int c, size_t slen) {
      return nullptr;
    }

    size_t memspn(const char* s, size_t slen, const char* accept) {
      return 0;
    }

    size_t memcspn(const char* s, size_t slen, const char* reject) {
      return 0;
    }

    char* mempbrk(const char* s, size_t slen, const char* accept) {
      return nullptr;
    }

    const char* memmatch(const char* phaystack, size_t haylen, const char* pneedle,
                         size_t neelen) {
      return nullptr;
    }

  }
}

namespace absl {

  bool EqualsIgnoreCase(absl::string_view piece1,
                        absl::string_view piece2) noexcept {
    return false;
  }

  bool StartsWithIgnoreCase(absl::string_view text,
                            absl::string_view prefix) noexcept {
    return false;
  }

  bool EndsWithIgnoreCase(absl::string_view text,
                          absl::string_view suffix) noexcept {
    return false;
  }

}

namespace absl {

  bool SimpleAtof(absl::string_view str, float* out) {
    return false;
  }

  bool SimpleAtod(absl::string_view str, double* out) {
    return false;
  }

  bool SimpleAtob(absl::string_view str, bool* out) {
    return false;
  }

  char* numbers_internal::FastIntToBuffer(uint32_t i, char* buffer) {
    return nullptr;
  }

  char* numbers_internal::FastIntToBuffer(int32_t i, char* buffer) {
    return nullptr;
  }

  char* numbers_internal::FastIntToBuffer(uint64_t i, char* buffer) {
    return nullptr;
  }

  char* numbers_internal::FastIntToBuffer(int64_t i, char* buffer) {
    return nullptr;
  }

  std::pair<uint64_t, uint64_t> Mul32(std::pair<uint64_t, uint64_t> num,
                                             uint32_t mul) {
    std::pair<uint64_t, uint64_t> v;
    return v;
  }

  std::pair<uint64_t, uint64_t> PowFive(uint64_t num, int expfive) {
    std::pair<uint64_t, uint64_t> v;
    return v;
  }


  size_t numbers_internal::SixDigitsToBuffer(double d, char* const buffer) {
    return 0;
  }

  namespace numbers_internal {

    const char kHexChar[] = {};
    const char kHexTable[513] = {};
    const char two_ASCII_digits[100][2] = {};

    bool safe_strto32_base(absl::string_view text, int32_t* value, int base) {
      return false;
    }

    bool safe_strto64_base(absl::string_view text, int64_t* value, int base) {
      return false;
    }

    bool safe_strto128_base(absl::string_view text, int128* value, int base) {
      return false;
    }

    bool safe_strtou32_base(absl::string_view text, uint32_t* value, int base) {
      return false;
    }

    bool safe_strtou64_base(absl::string_view text, uint64_t* value, int base) {
      return false;
    }

    bool safe_strtou128_base(absl::string_view text, uint128* value, int base) {
      return false;
    }

  }
}

namespace absl {

  AlphaNum::AlphaNum(Hex hex) {
  }

  AlphaNum::AlphaNum(Dec dec) {
  }

  char* Append(char* out, const AlphaNum& x) {
    return nullptr;
  }

  std::string StrCat(const AlphaNum& a, const AlphaNum& b) {
    return "";
  }

  std::string StrCat(const AlphaNum& a, const AlphaNum& b, const AlphaNum& c) {
    return "";
  }

  std::string StrCat(const AlphaNum& a, const AlphaNum& b, const AlphaNum& c,
                     const AlphaNum& d) {
    return "";
  }

  namespace strings_internal {

    std::string CatPieces(std::initializer_list<absl::string_view> pieces) {
      return "";
    }

    void AppendPieces(std::string* dest,
                      std::initializer_list<absl::string_view> pieces) {
    }

  }

  void StrAppend(std::string* dest, const AlphaNum& a) {
  }

  void StrAppend(std::string* dest, const AlphaNum& a, const AlphaNum& b) {
  }

  void StrAppend(std::string* dest, const AlphaNum& a, const AlphaNum& b,
                 const AlphaNum& c) {
  }

  void StrAppend(std::string* dest, const AlphaNum& a, const AlphaNum& b,
                 const AlphaNum& c, const AlphaNum& d) {
  }

}

namespace absl {

  namespace strings_internal {

    using FixedMapping =
      std::initializer_list<std::pair<absl::string_view, absl::string_view>>;

    int ApplySubstitutions(
                           absl::string_view s,
                           std::vector<strings_internal::ViableSubstitution>* subs_ptr,
                           std::string* result_ptr) {
      return 0;
    }

  }

  std::string StrReplaceAll(absl::string_view s,
                            strings_internal::FixedMapping replacements) {
    return "";
  }

  int StrReplaceAll(strings_internal::FixedMapping replacements,
                    std::string* target) {
    return 0;
  }

}

namespace absl {

  ByString::ByString(absl::string_view sp) : delimiter_(sp) {}

  absl::string_view ByString::Find(absl::string_view text, size_t pos) const {
    absl::string_view v;
    return v;
  }

  absl::string_view ByChar::Find(absl::string_view text, size_t pos) const {
    absl::string_view v;
    return v;
  }

  ByAnyChar::ByAnyChar(absl::string_view sp) : delimiters_(sp) {}

  absl::string_view ByAnyChar::Find(absl::string_view text, size_t pos) const {
    absl::string_view v;
    return v;
  }

  ByLength::ByLength(ptrdiff_t length) : length_(length) {
  }

  absl::string_view ByLength::Find(absl::string_view text,
                                   size_t pos) const {
    absl::string_view v;
    return v;
  }

}

#ifdef ABSL_USES_STD_STRING_VIEW

#include <string_view>  // IWYU pragma: export

namespace absl {
  using string_view = std::string_view;
}  // namespace absl

#else  // ABSL_USES_STD_STRING_VIEW

#include <algorithm>
#include <climits>
#include <cstring>
#include <ostream>

#include "absl/strings/internal/memutil.h"

namespace absl {

  std::ostream& operator<<(std::ostream& o, string_view piece) {
    return o;
  }

  string_view::size_type string_view::find(string_view s,
                                           size_type pos) const noexcept {
    string_view::size_type v;
    return v;
  }

  string_view::size_type string_view::find(char c, size_type pos) const noexcept {
    string_view::size_type v;
    return v;
  }

  string_view::size_type string_view::rfind(string_view s,
                                            size_type pos) const noexcept {
    string_view::size_type v;
    return v;
  }

  string_view::size_type string_view::rfind(char c,
                                            size_type pos) const noexcept {
    string_view::size_type v;
    return v;
  }

  string_view::size_type string_view::find_first_of(
                                                    string_view s, size_type pos) const noexcept {
    string_view::size_type v;
    return v;
   
  }

  string_view::size_type string_view::find_first_not_of(
                                                        string_view s, size_type pos) const noexcept {
    string_view::size_type v;
    return v;
  }

  string_view::size_type string_view::find_first_not_of(
                                                        char c, size_type pos) const noexcept {
    string_view::size_type v;
    return v;
  }

  string_view::size_type string_view::find_last_of(string_view s,
                                                   size_type pos) const noexcept {
    string_view::size_type v;
    return v;
  }

  string_view::size_type string_view::find_last_not_of(
                                                       string_view s, size_type pos) const noexcept {
    string_view::size_type v;
    return v;
  }

  string_view::size_type string_view::find_last_not_of(
                                                       char c, size_type pos) const noexcept {
    string_view::size_type v;
    return v;
  }

}
#endif  // ABSL_USES_STD_STRING_VIEW

namespace absl {

  namespace substitute_internal {

    void SubstituteAndAppendArray(std::string* output, absl::string_view format,
                                  const absl::string_view* args_array,
                                  size_t num_args) {
    }

    Arg::Arg(const void* value) {
    }

    Arg::Arg(Hex hex) {
    }

    Arg::Arg(Dec dec) {
    }

  }
}

#endif

#include "go-absl/base/base/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/endian/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/base/throw_delegate/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/meta/type_traits/export.inc"
#include "go-absl/numeric/bits/export.inc"
#include "go-absl/numeric/int128/export.inc"
#include "go-absl/strings/internal/export.inc"

#endif
