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

// Library for multi-precision integer arithmetics.
// The following classes are defined:
// FixedUint: unsigned integer with fixed length.
// FixedInt: signed integer with fixed length.
// VarUintRef, ConstVarUintRef: unsigned integer reference with variable length
// VarIntRef, ConstVarIntRef: signed integer reference with variable length
//
// VarUintRef, ConstVarUintRef, VarIntRef, ConstVarIntRef have very limited
// support. Their performance is not optimized. FixedUint and FixedInt should
// be used instead whenever possible.
//
// All classes defined in this library represent an integer by an array of
// 32 or 64 bit words, in little endian order. For example, FixedInt<64, 4>
// represents a 256-bit signed integer with 4 uint64_t words (with alias
// Word=int64_t and UnsignedWord=uint64_t), and interprets the array
// {0x1, 0x2, 0x3, 0x4} as 0x4000000000000000300000000000000020000000000000001.
// Negative values are represented with 2's complement.
// In general, 64-bit words perform better, except for some corner cases (see
// performance hints below).
//
// Supported operators and functions of FixedUint and FixedInt
//     Operator/function      Argument type           Notes
//
//         >>=, <<=           uint
//   ==, !=, <, >, <=, >=     FixedUint/FixedInt
//
//      +=, AddOverflow       Word
//      +=, AddOverflow       UnsignedWord            Same as Word for FixedUint
//      +=, AddOverflow       FixedUint/FixedInt
//
//   -=, SubtractOverflow     Word
//   -=, SubtractOverflow     UnsignedWord            Same as Word for FixedUint
//   -=, SubtractOverflow     FixedUint/FixedInt
//
//   *=, MultiplyOverflow     Word
//   *=, MultiplyOverflow     UnsignedWord            Same as Word for FixedUint
//   *=, MultiplyOverflow     FixedUint/FixedInt
//     ExtendAndMultiply      FixedUint/FixedInt
//
//            /=              integral_constant<uint32_t>
//            /=              integral_constant<int32_t>    (FixedInt only)
//            /=              Word
//            /=              UnsignedWord            Same as Word for FixedUint
//            /=              FixedUint/FixedInt
//
//            %=              integral_constant<uint32_t>
//            %=              integral_constant<int32_t>    (FixedInt only)
//            %=              Word
//            %=              UnsignedWord            Same as Word for FixedUint
//            %=              FixedUint/FixedInt
//
//  DivAndRoundAwayFromZero   integral_constant<uint32_t>
//  DivAndRoundAwayFromZero   integral_constant<int32_t>    (FixedInt only)
//  DivAndRoundAwayFromZero   Word
//  DivAndRoundAwayFromZero   UnsignedWord            Same as Word for FixedUint
//  DivAndRoundAwayFromZero   FixedUint/FixedInt
//
//          DivMod            integral_constant<uint32_t>   (FixedUint only)
//          DivMod            integral_constant<int32_t>    (FixedInt only)
//          DivMod            Word
//          DivMod            UnsignedWord                (FixedUint only)
//          DivMod            FixedUint/FixedInt
//
//          is_zero           None
//        is_negative         None                        (FixedInt only)
//    -, NegateOverflow       None                        (FixedInt only)
//           abs              None                        (FixedInt only)
//       SetSignAndAbs        bool, FixedUint             (FixedInt only)
//
//      cast to double        None
//  cast to int128/uint128    None
//
//        absl::Hash          None                        (FixedInt only)
//
//        PowerOf10           uint
//    CountDecimalDigits      None
//
//      AppendToString        std::string*
//   ParseFromStringStrict    absl::string_view
//  ParseFromStringSegments   absl::string_view
//
//     SerializeToBytes       std::string*
//   DeserializeFromBytes     absl::string_view
//
//
// Arithmetic operator/function performance hints
// * Left hand side:
//   - FixedUint is generally no slower than FixedInt.
//   - FixedUint<64, n> is generally faster than FixedUint<32, 2 * n>, and
//     FixedInt<64, n> is generally faster than FixedInt<32, 2 * n>.
//     <32, m> is recommended only when m is an odd number *and* the bottleneck
//     is a division by integral_constant<uint32_t> or integral_constant<int32_t>.
//
// * Right hand side (from fastest to slowest):
//     integral_constant<uint32_t> > integral_constant<int32_t> > UnsignedWord
//       >= Word >= FixedUint/FixedInt
//   For FixedUint on the left hand side, UnsignedWord = Word;
//   for FixedInt on the left hand side, UnsignedWord is faster than Word.
//   Note, constexpr int32_t/uint32 will not be converted to integral_constant.
//   In C++, currently there is no reliable way to identify constexpr arguments.
//
// * Comparison among operators and functions:
//   - is_zero and is_negative are faster than comparison to zero.
//   - MultiplyOverflow(FixedUint/FixedInt) is usually much slower than
//     operator*= with the same argument type. Other *Overflow methods are
//     slightly slower than the corresponding operator.
//   - ExtendAndMultiply is faster than operator*= given the same output type.
//   - DivMod is faster than calling operator/= and operator%= separately.
//   - For a FixedInt, if multiple multiplications and/or divisions are
//     performed, it is generally much faster if the FixedInt is converted to
//     FixedUint first, because each multiplication or division with FixedInt
//     involves up to 2 negations in the implementation, except for
//     operator*=(UnsignedWord).
//
// Unless otherwise documented, the operators of this class do not check
// overflows. If a result overflows, the result bits higher than the kNumBits
// are silently dropped. This is consistent with the primitive integer types,
// except that FixedInt overflow behavior is defined while int overflow behavior
// is undefined in C/C++.
#ifndef ZETASQL_COMMON_MULTIPRECISION_INT_H_
#define ZETASQL_COMMON_MULTIPRECISION_INT_H_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>

#include <algorithm>
#include <array>
#include <cstdint>
#include <iterator>
#include <limits>
#include <string>
#include <type_traits>

#include "zetasql/base/logging.h"
#include "zetasql/common/multiprecision_int_impl.h"
#include "absl/base/attributes.h"
#include <cstdint>
#include "absl/base/optimization.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/string_view.h"
#include "absl/types/span.h"

namespace zetasql {

// Don't use this class directly. Use VarUintRef, ConstVarUintRef, VarIntRef,
// or ConstVarIntRef instead. Note that the methods of theses classes are not
// optimized for performance. Prefer FixedInt or FixedUint.
template <bool is_signed, typename UnsignedWord>
class VarIntBase {
 public:
  template <typename Containder>
  explicit VarIntBase(Containder& src) : number_(src.data(), src.size()) {}

  absl::Span<UnsignedWord> number() const { return number_; }
  UnsignedWord* data() const { return number_.data(); }
  size_t size() const { return number_.size(); }

  void SerializeToBytes(std::string* bytes) const;
  bool DeserializeFromBytes(absl::string_view bytes);

  // Defined only for UnsignedWord = uint32_t.
  void AppendToString(std::string* result) const;
  std::string ToString() const {
    std::string result;
    AppendToString(&result);
    return result;
  }

 protected:
  absl::Span<UnsignedWord> number_;
};

template <int kNumBitsPerWord>
using ConstVarUintRef =
    VarIntBase<false, const multiprecision_int_impl::Uint<kNumBitsPerWord>>;

template <int kNumBitsPerWord>
using ConstVarIntRef =
    VarIntBase<true, const multiprecision_int_impl::Uint<kNumBitsPerWord>>;

template <int kNumBitsPerWord>
class VarUintRef
    : public VarIntBase<false, multiprecision_int_impl::Uint<kNumBitsPerWord>> {
 public:
  using VarIntBase<false,
                   multiprecision_int_impl::Uint<kNumBitsPerWord>>::VarIntBase;

  // Defined only for kNumBitsPerWord == 32.
  // Computes *this /= divisor and returns the remainder.
  template <uint32_t divisor>
  uint32_t DivMod(std::integral_constant<uint32_t, divisor> x);
  uint32_t DivMod(uint32_t divisor);
};

template <int kNumBitsPerWord>
class VarIntRef
    : public VarIntBase<true, multiprecision_int_impl::Uint<kNumBitsPerWord>> {
 public:
  using VarIntBase<true,
                   multiprecision_int_impl::Uint<kNumBitsPerWord>>::VarIntBase;
  void Negate();
};

template <int kNumBitsPerWord, int kNumWords>
class FixedInt;

template <int kNumBitsPerWord, int kNumWords>
class FixedUint final {
 public:
  using Word = multiprecision_int_impl::Uint<kNumBitsPerWord>;
  using UnsignedWord = Word;
  static constexpr int kNumBits = kNumBitsPerWord * kNumWords;
  // The max bits an integer can have to be casted to double when all the bits
  // in the integer are set. Also limited by the kNumBitsPerWord.
  static constexpr int kMaxBitsToDouble = 992;

  static constexpr FixedUint min() {
    return FixedUint(multiprecision_int_impl::LeftPad<Word, kNumWords>(0));
  }
  static constexpr FixedUint max() {
    return FixedUint(
        multiprecision_int_impl::LeftPad<Word, kNumWords>(~Word{0}));
  }

  constexpr FixedUint()
      : number_(multiprecision_int_impl::RightPad<Word, kNumWords>(0)) {}
  constexpr explicit FixedUint(uint32_t x)
      : number_(multiprecision_int_impl::RightPad<Word, kNumWords>(0, x)) {}
  constexpr explicit FixedUint(uint64_t x)
      : number_(multiprecision_int_impl::UintToArray<64, kNumBitsPerWord,
                                                     kNumWords>(x, 0)) {
    static_assert(kNumBits >= 64, "Size too small");
  }
  constexpr explicit FixedUint(unsigned __int128 x)
      : number_(multiprecision_int_impl::UintToArray<128, kNumBitsPerWord,
                                                     kNumWords>(x, Word{0})) {
    static_assert(kNumBits >= 128, "Size too small");
  }
  FixedUint(uint64_t hi, unsigned __int128 low) {
    static_assert(kNumBits >= 192, "Size too small");
    number_.fill(0);
    multiprecision_int_impl::UintToArray<128, kNumBitsPerWord>(low,
                                                               number_.data());
    multiprecision_int_impl::UintToArray<64, kNumBitsPerWord>(
        hi, &number_[128 / kNumBitsPerWord]);
  }
  FixedUint(unsigned __int128 hi, unsigned __int128 low) {
    static_assert(kNumBits >= 256, "Size too small");
    number_.fill(0);
    multiprecision_int_impl::UintToArray<128, kNumBitsPerWord>(low,
                                                               number_.data());
    multiprecision_int_impl::UintToArray<128, kNumBitsPerWord>(
        hi, &number_[128 / kNumBitsPerWord]);
  }

  // If k * n > kNumBits, then the k * n - kNumBits most significant bits are
  // dropped.
  template <int k, int n>
  explicit FixedUint(const FixedUint<k, n>& src)
      : number_(
            multiprecision_int_impl::Convert<kNumBitsPerWord, kNumWords, k, n>(
                src.number(), false)) {}
  explicit constexpr FixedUint(
      const std::array<Word, kNumWords>& little_endian_number)
      : number_(little_endian_number) {}

  explicit operator unsigned __int128() const {
    return multiprecision_int_impl::ArrayToUint<128, kNumBitsPerWord>(
        number_.data());
  }

  // Cast FixedUint<kNumBitsPerWord, kNumWords> into double. When there is a
  // loss of significance during conversion, we will use the rounding rule that
  // rounds half to even. It is the same rule being used in the built-in cast
  // functions for integer to double numbers. For example, 0xfffffffffffff400
  // (2^64 - 3 * 2^10) should be rounded down to 0xfffffffffffff000 (2^64 - 4 *
  // 2^10) while 0xfffffffffffffc00 (2^64 - 2^10) should be rounded up to
  // 0x10000000000000000 (2^64) since the values rounded to have even mantissas
  // in double form while 0xfffffffffffff800 (2^64 - 2 * 2^10) has an odd
  // mantissa.
  explicit operator double() const;

  // Shifts the number left by the given number of bits.
  FixedUint& operator<<=(uint bits) {
    if (ABSL_PREDICT_TRUE(bits != 0)) {
      if (ABSL_PREDICT_TRUE(bits < kNumBitsPerWord)) {
        multiprecision_int_impl::ShiftLeftFast(number_.data(), kNumWords, bits);
        return *this;
      }
      multiprecision_int_impl::ShiftLeft(number_.data(), kNumWords, bits);
    }
    return *this;
  }

  // Shifts the number right by the given number of bits.
  FixedUint& operator>>=(uint bits) {
    if (ABSL_PREDICT_TRUE(bits != 0)) {
      if (ABSL_PREDICT_TRUE(bits < kNumBitsPerWord)) {
        multiprecision_int_impl::ShiftRightFast<Word>(number_.data(), kNumWords,
                                                      bits);
        return *this;
      }
      multiprecision_int_impl::ShiftRight(Word{0}, number_.data(), kNumWords,
                                          bits);
    }
    return *this;
  }

  // Returns true iff the result overflows.
  bool AddOverflow(Word x) { return AddOverflow(FixedUint(x)); }
  bool AddOverflow(const FixedUint& rh) {
    return multiprecision_int_impl::Add<kNumWords>(number_, rh.number_) != 0;
  }

  FixedUint& operator+=(Word x) {
    AddOverflow(x);
    return *this;
  }
  FixedUint& operator+=(const FixedUint& rh) {
    multiprecision_int_impl::Add<kNumWords>(number_, rh.number_);
    return *this;
  }

  bool SubtractOverflow(Word x) {
    uint8_t carry =
        multiprecision_int_impl::SubtractWithBorrow(&number_[0], x, 0);
    for (int i = 1; i < kNumWords; ++i) {
      carry = multiprecision_int_impl::SubtractWithBorrow(&number_[i], Word{0},
                                                          carry);
    }
    return carry != 0;
  }
  bool SubtractOverflow(const FixedUint& rh) {
    return multiprecision_int_impl::Subtract<kNumWords>(number_, rh.number_) !=
           0;
  }

  FixedUint& operator-=(Word x) {
    SubtractOverflow(x);
    return *this;
  }
  FixedUint& operator-=(const FixedUint& rh) {
    multiprecision_int_impl::Subtract<kNumWords>(number_, rh.number_);
    return *this;
  }

  FixedUint& operator*=(Word x) {
    multiprecision_int_impl::MulWord(number_.data(), kNumWords, x);
    return *this;
  }
  FixedUint& operator*=(const FixedUint& rh) {
    FixedUint res;
    PartialMultiplyOverflow(rh, &res);
    return *this = res;
  }

  bool MultiplyOverflow(Word x) {
    return multiprecision_int_impl::MulWord(number_.data(), kNumWords, x) != 0;
  }
  bool MultiplyOverflow(const FixedUint& rh) {
    FixedUint res;
    bool overflow = PartialMultiplyOverflow(rh, &res) ||
                    NonZeroLength() + rh.NonZeroLength() > kNumWords + 1;
    *this = res;
    return overflow;
  }

  template <uint32_t divisor>
  void DivMod(std::integral_constant<uint32_t, divisor> x, FixedUint* quotient,
              uint32_t* remainder) const {
    uint32_t r = multiprecision_int_impl::ShortDivModConstant<kNumWords>(
        number_, x, quotient != nullptr ? &quotient->number_ : nullptr);
    if (remainder != nullptr) {
      *remainder = r;
    }
  }
  void DivMod(Word x, FixedUint* quotient, Word* remainder) const {
    Word r = multiprecision_int_impl::ShortDivMod<Word, kNumWords>(
        number_, x, quotient != nullptr ? &quotient->number_ : nullptr);
    if (remainder != nullptr) {
      *remainder = r;
    }
  }
  // Computes *quotient = *this / divisor, and *remainder = *this % divisor.
  // quotient and remainder can be null, this, or point to other instances.
  // If quotient and remainder are the same and are not null, the instance will
  // receive the remainder value.
  void DivMod(const FixedUint& divisor, FixedUint* quotient,
              FixedUint* remainder) const {
    multiprecision_int_impl::DivMod<kNumWords>(
        number_, divisor.number_,
        quotient != nullptr ? &quotient->number_ : nullptr,
        remainder != nullptr ? &remainder->number_ : nullptr);
  }

  // The caller is responsible for ensuring that the value is not zero.
  template <uint32_t divisor>
  FixedUint& operator/=(std::integral_constant<uint32_t, divisor> x) {
    multiprecision_int_impl::ShortDivModConstant<kNumWords>(number_, x,
                                                            &number_);
    return *this;
  }

  FixedUint& operator/=(const FixedUint& x) {
    multiprecision_int_impl::DivMod<kNumWords>(number_, x.number_, &number_,
                                               nullptr);
    return *this;
  }

  FixedUint& operator/=(Word divisor) {
    if (kNumBitsPerWord == 32) {
      multiprecision_int_impl::ShortDivMod<Word, kNumWords>(number_, divisor,
                                                            &number_);
      return *this;
    }
    FixedUint tmp;
    tmp.number_[0] = divisor;
    return *this /= tmp;
  }

  template <uint32_t divisor>
  FixedUint& DivAndRoundAwayFromZero(
      std::integral_constant<uint32_t, divisor> x) {
    if (ABSL_PREDICT_TRUE(!AddOverflow(divisor >> 1))) {
      return *this /= x;
    }
    *this -= x;
    *this /= x;
    return *this += Word{1};
  }

  FixedUint& DivAndRoundAwayFromZero(Word x) {
    if (ABSL_PREDICT_TRUE(!AddOverflow(x >> 1))) {
      return *this /= x;
    }
    *this -= x;
    *this /= x;
    return *this += Word{1};
  }

  FixedUint& DivAndRoundAwayFromZero(const FixedUint& x) {
    FixedUint half_x = x;
    half_x >>= 1;
    uint8_t carry =
        multiprecision_int_impl::Add<kNumWords>(number_, half_x.number_);
    if (ABSL_PREDICT_TRUE(carry == 0)) {
      return *this /= x;
    }
    *this -= x;
    *this /= x;
    return *this += Word{1};
  }

  template <uint32_t divisor>
  FixedUint& operator%=(std::integral_constant<uint32_t, divisor> x) {
    number_[0] = multiprecision_int_impl::ShortDivModConstant<kNumWords>(
        number_, x, nullptr);
    std::fill(number_.begin() + 1, number_.end(), 0);
    return *this;
  }

  FixedUint& operator%=(const FixedUint& x) {
    DivMod(x, nullptr, this);
    return *this;
  }

  FixedUint& operator%=(Word x) {
    if (kNumBitsPerWord == 32) {
      number_[0] = multiprecision_int_impl::ShortDivMod<Word, kNumWords>(
          number_, x, nullptr);
      std::fill(number_.begin() + 1, number_.end(), 0);
      return *this;
    }
    FixedUint tmp;
    tmp.number_[0] = x;
    return *this %= tmp;
  }

  bool is_zero() const { return NonZeroLength() == 0; }
  // Returns the number of words excluding leading zero words.
  int NonZeroLength() const {
    return multiprecision_int_impl::NonZeroLength<Word, kNumWords>(
        number_.data());
  }

  // Returns the first set most significant bit index, 0 based. If this number
  // is 0 then this function will return 0;
  int FindMSBSetNonZero() const;

  constexpr const std::array<Word, kNumWords>& number() const {
    return number_;
  }

  // Serializes to minimum number of bytes needed to represent the number.
  // The result is appended to *out.
  void SerializeToBytes(std::string* out) const {
    ConstVarUintRef<kNumBitsPerWord>(number_).SerializeToBytes(out);
  }

  // Deserializes the output of Serialize() from a FixedUint (not FixedInt) with
  // the same template arguments. If the input is valid, false is returned and
  // this instance is unchanged.
  ABSL_MUST_USE_RESULT bool DeserializeFromBytes(absl::string_view bytes) {
    return VarUintRef<kNumBitsPerWord>(number_).DeserializeFromBytes(bytes);
  }

  // Convert the FixedUint to a readable string form.
  std::string ToString() const {
    std::string result;
    AppendToString(&result);
    return result;
  }

  void AppendToString(std::string* result) const;

  // Parse digit-only string representation of an unsigned decimal integer and
  // write the number into the FixedUint. Returns true iff str is valid.
  // If false is returned, the state of *this is undefined.
  bool ParseFromStringStrict(absl::string_view str) {
    return !str.empty() && ParseOrAppendDigits(str, false);
  }
  // Equivalent to ParseFromStringStrict(absl::StrCat(<all segments>)),
  // except that no temporary string is created, and first_segment cannot be
  // empty (extra_segments and its elements can be empty).
  bool ParseFromStringSegments(
      absl::string_view first_segment,
      absl::Span<const absl::string_view> extra_segments) {
    if (ABSL_PREDICT_FALSE(!ParseFromStringStrict(first_segment))) {
      return false;
    }
    for (absl::string_view segment : extra_segments) {
      if (ABSL_PREDICT_FALSE(!segment.empty() &&
                             !ParseOrAppendDigits(segment, true))) {
        return false;
      }
    }
    return true;
  }

  // Returns pow(10, exponent).
  static const FixedUint& PowerOf10(uint exponent) {
    static constexpr auto kPowersOf10 = GetPowersOf10();
    ZETASQL_DCHECK_LT(exponent, kPowersOf10.size());
    return kPowersOf10[exponent];
  }
  // Equivalent to ToString().size(), but is much faster.
  // Note, this method returns 1 when *this = 0.
  uint CountDecimalDigits() const {
    static constexpr auto kPowersOf10 = GetPowersOf10();
    constexpr uint kStartingValue = 1;  // returns 1 even when *this = 0
    static constexpr auto kMSBInfos =
        GetMSBInfoArray(kPowersOf10, FixedUint(Word{1}), kStartingValue);
    int msb_set = FindMSBSetNonZero();
    const MSBInfo& t = kMSBInfos[msb_set];
    uint num_digits = t.min_num_digits;
    if (t.power_of_10_in_bucket != nullptr &&
        *this >= *t.power_of_10_in_bucket) {
      ++num_digits;
    }
    return num_digits;
  }

  template <typename H>
  friend H AbslHashValue(H h,
                         const FixedUint<kNumBitsPerWord, kNumWords>& value) {
    return H::combine(std::move(h), value.number_);
  }

 private:
  friend class FixedInt<kNumBitsPerWord, kNumWords>;

  // Computes *this * rh using only the products of the input words that fit
  // into <result>, and returns whether these products result in an overflow.
  // For example, in the case kNumWords = 2, then only
  // number_[0] * rh.number_[0], number_[0] * rh.number_[1] and
  // number_[1] * rh.number_[0] are considered.
  bool PartialMultiplyOverflow(const FixedUint& rh, FixedUint* result) const;
  // Either parse or append decimal digits. In append mode, for example,
  // if *this = 123 and str = "456", then *this will become 123456.
  // The caller must ensure str is not empty.
  bool ParseOrAppendDigits(absl::string_view str, bool append);

  static constexpr auto GetPowersOf10() {
    // Convert number of bits to max number of decimal digits.
    constexpr double kLog10_2 = 0.3010299956639812;
    constexpr size_t kMaxDigits = static_cast<size_t>(kNumBits * kLog10_2) + 1;
    return PowersAsc<kMaxDigits>(FixedUint(Word{1}), 10);
  }

  // PowersAsc<size>(v, multipler) returns an array of arrays
  // representing {v, v * multiplier, ..., v * pow(multiplier, size - 1)}.
  template <size_t size, typename... T>
  static constexpr std::array<FixedUint, size> PowersAsc(
      const FixedUint& last_value, Word multiplier, const T&... v) {
    if constexpr (sizeof...(T) < size) {
      const FixedUint new_value(multiprecision_int_impl::MulWord(
          last_value.number(), multiplier, Word{0}));
      return PowersAsc<size>(new_value, multiplier, v..., last_value);
    } else {
      return std::array<FixedUint, size>{v...};
    }
  }

  // Decimal info of an MSB (most-significant-bit) index.
  // For example, in an array of MSBInfo, the first element means
  // the decimal info for the values whose MSB index is 0 (i.e., 0 and 1),
  // the second element means the decimal info for the values whose MSB index is
  // 1 (i.e., values 2 and 3), the third element is for the values whose MSB
  // index is 2 (i.e., values 4, 5, 6, 7), and so on. This array is designed for
  // efficient lookup of number of decimal digits by value. The number of
  // decimal digits of the value is either t.min_num_digits or t.min_num_digits
  // + 1 where t is the corresponding MSBInfo.
  struct MSBInfo {
    uint min_num_digits;
    // If not null, it means the value range covers a power of 10. If a value in
    // the range is greater than or equal to this power of 10, then it has
    // min_num_digits + 1 decimal digits; otherwise it has min_num_digits
    // decimal digits.
    const FixedUint* power_of_10_in_bucket;
  };

  template <size_t max_num_digits, typename... T>
  static constexpr std::array<MSBInfo, kNumBits> GetMSBInfoArray(
      const std::array<FixedUint, max_num_digits>& powers_of_10,
      const FixedUint& power_of_2, uint current_num_digits, T... v) {
    if constexpr (sizeof...(T) < kNumBits) {
      const FixedUint next_power_of_2(
          multiprecision_int_impl::MulWord<Word>(power_of_2.number(), 2, 0));
      const bool threshold_in_current_range =
          current_num_digits < max_num_digits &&
          multiprecision_int_impl::Less(
              powers_of_10[current_num_digits].number(),
              next_power_of_2.number());
      const uint next_num_digits =
          current_num_digits + threshold_in_current_range;
      const MSBInfo current_elem = {current_num_digits,
                                    threshold_in_current_range
                                        ? &powers_of_10[current_num_digits]
                                        : nullptr};
      return GetMSBInfoArray(powers_of_10, next_power_of_2, next_num_digits,
                             v..., current_elem);
    } else {
      return std::array<MSBInfo, kNumBits>{v...};
    }
  }

  // The number is stored in the little-endian order with the least significant
  // word being at the index 0.
  std::array<Word, kNumWords> number_;
};

template <int kNumBitsPerWord, int kNumWords>
FixedUint<kNumBitsPerWord, kNumWords>::operator double() const {
  static_assert(kNumBits <= kMaxBitsToDouble,
                "Size too big to convert to double.");
  static_assert(kNumBits > 0, "The number has less than one bit.");
  // DOUBLE can have 53 bits in the significand, which is less than 64. We will
  // keep 55 bits at most for rounding. We take at most 54 bits from the
  // FixedUint, and decide the 55th by the trailing bits if needed. Keeping
  // two more bits for rounding halves ties to the nearest even number.
  uint64_t significand = 0;
  int word_idx = NonZeroLength() - 1;
  if (word_idx == -1) {
    return 0.0;
  }
  int bit_idx = multiprecision_int_impl::FindMSBSetNonZero(number_[word_idx]);
  int significant_bits = 0;
  while (true) {
    if (significant_bits + bit_idx >= 54) {
      significand <<= (54 - significant_bits);
      bit_idx += (significant_bits - 54);
      significand |= (number_[word_idx] >> bit_idx);
      // Set the 55th bit for rounding. Set it to 1 if any non-zero in trailing
      // digits.
      significand <<= 1;
      int exp = word_idx * kNumBitsPerWord + bit_idx - 1;
      Word remainder = number_[word_idx] & ~(~Word{0} << bit_idx);
      while (remainder == 0) {
        if (--word_idx < 0) {
          return std::ldexp(significand, exp);
        }
        remainder = number_[word_idx];
      }
      return std::ldexp(significand | 1, exp);
    }
    significand = (significand << bit_idx) | number_[word_idx];
    significant_bits += bit_idx;
    bit_idx = kNumBitsPerWord;
    if (--word_idx < 0) {
      ZETASQL_DCHECK_LT(significant_bits, 54);
      return static_cast<double>(significand);
    }
  }
}

template <int kNumBitsPerWord, int kNumWords>
inline int FixedUint<kNumBitsPerWord, kNumWords>::FindMSBSetNonZero() const {
  const int nzlen = NonZeroLength();
  if (nzlen == 0) {
    return 0;
  }
  return multiprecision_int_impl::FindMSBSetNonZero(number_[nzlen - 1]) +
         (nzlen - 1) * kNumBitsPerWord;
}

template <int kNumBitsPerWord, int kNumWords>
inline bool FixedUint<kNumBitsPerWord, kNumWords>::PartialMultiplyOverflow(
    const FixedUint& rh, FixedUint* result) const {
  using DWord = multiprecision_int_impl::Uint<kNumBitsPerWord * 2>;
  Word overflow_carry = 0;
  for (int j = 0; j < kNumWords; ++j) {
    Word carry = 0;
    for (int i = 0; i < kNumWords - j; ++i) {
      DWord tmp = static_cast<DWord>(number_[i]) * rh.number_[j] +
                  result->number_[i + j] + carry;
      result->number_[i + j] = static_cast<Word>(tmp);
      carry = static_cast<Word>(tmp >> kNumBitsPerWord);
    }
    overflow_carry |= carry;
  }
  return overflow_carry != 0;
}

template <int kNumBitsPerWord, int kNumWords>
inline bool operator==(const FixedUint<kNumBitsPerWord, kNumWords>& lh,
                       const FixedUint<kNumBitsPerWord, kNumWords>& rh) {
  return lh.number() == rh.number();
}

template <int kNumBitsPerWord, int kNumWords>
inline bool operator!=(const FixedUint<kNumBitsPerWord, kNumWords>& lh,
                       const FixedUint<kNumBitsPerWord, kNumWords>& rh) {
  return lh.number() != rh.number();
}

template <int kNumBitsPerWord, int kNumWords>
inline bool operator<(const FixedUint<kNumBitsPerWord, kNumWords>& lh,
                      const FixedUint<kNumBitsPerWord, kNumWords>& rh) {
  return multiprecision_int_impl::Less<kNumBitsPerWord, kNumWords>(
      lh.number().data(), rh.number().data());
}

template <int kNumBitsPerWord, int kNumWords>
inline bool operator>(const FixedUint<kNumBitsPerWord, kNumWords>& lh,
                      const FixedUint<kNumBitsPerWord, kNumWords>& rh) {
  return rh < lh;
}

template <int kNumBitsPerWord, int kNumWords>
inline bool operator<=(const FixedUint<kNumBitsPerWord, kNumWords>& lh,
                       const FixedUint<kNumBitsPerWord, kNumWords>& rh) {
  return !(rh < lh);
}

template <int kNumBitsPerWord, int kNumWords>
inline bool operator>=(const FixedUint<kNumBitsPerWord, kNumWords>& lh,
                       const FixedUint<kNumBitsPerWord, kNumWords>& rh) {
  return !(lh < rh);
}

template <int kNumBitsPerWord, int kNumWords>
void FixedUint<kNumBitsPerWord, kNumWords>::AppendToString(
    std::string* result) const {
  // 32-bit quotient is faster than 64-bit.
  static_assert(kNumBits % 32 == 0);
  FixedUint<32, kNumBits / 32> quotient(*this);
  std::integral_constant<uint32_t, 1000000000> divisor;
  // The number of segments needed = ceil(kNumBits * log(2) / log(1000000000))
  // = ceil(kNumBits / 29.897352854) <= ceil(kNumBits / 29).
  std::array<uint32_t, (kNumBits + 28) / 29> segments;
  int num_segments = 0;
  while (!quotient.is_zero()) {
    quotient.DivMod(divisor, &quotient, &segments[num_segments]);
    ++num_segments;
  }
  multiprecision_int_impl::AppendSegmentsToString(segments.data(), num_segments,
                                                  result);
}

template <int kNumBitsPerWord, int kNumWords>
bool FixedUint<kNumBitsPerWord, kNumWords>::ParseOrAppendDigits(
    absl::string_view str, bool append) {
  ZETASQL_DCHECK(!str.empty());
  Word radix =
      multiprecision_int_impl::IntTraits<kNumBitsPerWord>::kMaxPowerOf10;
  constexpr size_t kMaxDigitsPerSegment = multiprecision_int_impl::IntTraits<
      kNumBitsPerWord>::kMaxWholeDecimalDigits;
  size_t first_segment_length = (str.size() - 1) % kMaxDigitsPerSegment + 1;
  const char* ptr = str.data();
  const char* end = ptr + str.size();
  Word segment_val;
  // Handle the first segment of string
  if (ABSL_PREDICT_FALSE(
          !multiprecision_int_impl::ParseFromBase10UnsignedString(
              str.substr(0, first_segment_length), &segment_val))) {
    return false;
  }
  if (append) {
    static constexpr std::array<Word, kMaxDigitsPerSegment> kPowersOf10 =
        multiprecision_int_impl::PowersAsc<Word, 10, 10,
                                           kMaxDigitsPerSegment>();
    if (ABSL_PREDICT_FALSE(
            MultiplyOverflow(kPowersOf10[first_segment_length - 1]) ||
            AddOverflow(segment_val))) {
      return false;
    }
  } else {
    *this = FixedUint(segment_val);
  }
  for (ptr += first_segment_length; ptr < end; ptr += kMaxDigitsPerSegment) {
    if (ABSL_PREDICT_FALSE(MultiplyOverflow(radix)) ||
        ABSL_PREDICT_FALSE(
            !multiprecision_int_impl::ParseFromBase10UnsignedString(
                absl::string_view(ptr, kMaxDigitsPerSegment), &segment_val)) ||
        ABSL_PREDICT_FALSE(AddOverflow(segment_val))) {
      return false;
    }
  }
  return true;
}

template <int kNumBitsPerWord, int kNumWords>
class FixedInt final {
 public:
  using Word = multiprecision_int_impl::Int<kNumBitsPerWord>;
  using UnsignedWord = multiprecision_int_impl::Uint<kNumBitsPerWord>;
  static constexpr int kNumBits = kNumBitsPerWord * kNumWords;
  static constexpr int kMaxBitsToDouble = 992;

  static constexpr FixedInt min() {
    return FixedInt(multiprecision_int_impl::LeftPad<UnsignedWord, kNumWords>(
        0, static_cast<UnsignedWord>(std::numeric_limits<Word>::min())));
  }
  static constexpr FixedInt max() {
    constexpr UnsignedWord kMaxUnsigned =
        std::numeric_limits<UnsignedWord>::max();
    constexpr Word kMaxSigned = std::numeric_limits<Word>::max();
    return FixedInt(multiprecision_int_impl::LeftPad<UnsignedWord, kNumWords>(
        kMaxUnsigned, static_cast<UnsignedWord>(kMaxSigned)));
  }

  constexpr FixedInt() {}

  constexpr explicit FixedInt(int32_t x)
      : rep_(multiprecision_int_impl::RightPad<UnsignedWord, kNumWords>(
            x >= 0 ? 0 : ~UnsignedWord{0},
            static_cast<UnsignedWord>(static_cast<Word>(x)))) {}
  constexpr explicit FixedInt(int64_t x)
      : rep_(multiprecision_int_impl::UintToArray<64, kNumBitsPerWord,
                                                  kNumWords>(
            x, x >= 0 ? 0 : ~UnsignedWord{0})) {
    static_assert(kNumBits >= 64, "Size too small");
  }
  constexpr explicit FixedInt(__int128 x)
      : rep_(multiprecision_int_impl::UintToArray<128, kNumBitsPerWord,
                                                  kNumWords>(
            x, x >= 0 ? 0 : ~UnsignedWord{0})) {
    static_assert(kNumBits >= 128, "Size too small");
  }
  FixedInt(int64_t hi, unsigned __int128 low) {
    static_assert(kNumBits >= 192, "Size too small");
    rep_.number_.fill(hi >= 0 ? 0 : ~UnsignedWord{0});
    multiprecision_int_impl::UintToArray<128, kNumBitsPerWord>(
        low, rep_.number_.data());
    multiprecision_int_impl::UintToArray<64, kNumBitsPerWord>(
        static_cast<uint64_t>(hi), &rep_.number_[128 / kNumBitsPerWord]);
  }
  FixedInt(__int128 hi, unsigned __int128 low) {
    static_assert(kNumBits >= 256, "Size too small");
    rep_.number_.fill(hi >= 0 ? 0 : ~UnsignedWord{0});
    multiprecision_int_impl::UintToArray<128, kNumBitsPerWord>(
        low, rep_.number_.data());
    multiprecision_int_impl::UintToArray<128, kNumBitsPerWord>(
        static_cast<unsigned __int128>(hi),
        &rep_.number_[128 / kNumBitsPerWord]);
  }

  template <int k, int n>
  explicit FixedInt(const FixedInt<k, n>& src)
      : rep_(multiprecision_int_impl::Convert<kNumBitsPerWord, kNumWords, k, n>(
            src.number(), src.is_negative())) {}

  template <int k, int n>
  explicit FixedInt(const FixedUint<k, n>& src) : rep_(src) {}

  explicit constexpr FixedInt(
      const std::array<UnsignedWord, kNumWords>& little_endian_number)
      : rep_(little_endian_number) {}

  explicit operator __int128() const {
    return static_cast<unsigned __int128>(rep_);
  }

  explicit operator double() const {
    static_assert(kNumBits <= kMaxBitsToDouble,
                  "Size too big to convert to double.");
    static_assert(kNumBits > 0, "The number has less than one bit.");
    double abs_result = static_cast<double>(abs());
    return ABSL_PREDICT_FALSE(is_negative()) ? -abs_result : abs_result;
  }

  FixedInt& operator<<=(uint bits) {
    rep_ <<= bits;
    return *this;
  }

  FixedInt& operator>>=(uint bits) {
    if (ABSL_PREDICT_TRUE(bits != 0)) {
      if (ABSL_PREDICT_TRUE(bits < kNumBitsPerWord)) {
        multiprecision_int_impl::ShiftRightFast<Word>(rep_.number_.data(),
                                                      kNumWords, bits);
        return *this;
      }
      Word filler = -Word{is_negative()};
      multiprecision_int_impl::ShiftRight(filler, rep_.number_.data(),
                                          kNumWords, bits);
    }
    return *this;
  }

  bool AddOverflow(UnsignedWord x) {
    UnsignedWord old_val = rep_.number_[kNumWords - 1];
    rep_ += x;
    UnsignedWord new_val = rep_.number_[kNumWords - 1];
    return static_cast<Word>(~old_val & new_val) < 0;
  }
  bool AddOverflow(Word x) { return AddOverflow(FixedInt(x)); }
  bool AddOverflow(const FixedInt& rh) {
    UnsignedWord old_val = rep_.number_[kNumWords - 1];
    UnsignedWord y = rh.rep_.number_[kNumWords - 1];
    rep_ += rh.rep_;
    UnsignedWord new_val = rep_.number_[kNumWords - 1];
    return static_cast<Word>((old_val ^ new_val) & (new_val ^ y)) < 0;
  }

  FixedInt& operator+=(UnsignedWord x) {
    rep_ += x;
    return *this;
  }
  FixedInt& operator+=(Word x) { return *this += FixedInt(x); }
  FixedInt& operator+=(const FixedInt& rh) {
    rep_ += rh.rep_;
    return *this;
  }

  bool SubtractOverflow(UnsignedWord x) {
    UnsignedWord old_val = rep_.number_[kNumWords - 1];
    rep_ -= x;
    UnsignedWord new_val = rep_.number_[kNumWords - 1];
    return static_cast<Word>(~new_val & old_val) < 0;
  }
  bool SubtractOverflow(Word x) { return SubtractOverflow(FixedInt(x)); }
  bool SubtractOverflow(const FixedInt& rh) {
    UnsignedWord old_val = rep_.number_[kNumWords - 1];
    UnsignedWord y = rh.rep_.number_[kNumWords - 1];
    rep_ -= rh.rep_;
    UnsignedWord new_val = rep_.number_[kNumWords - 1];
    return static_cast<Word>((new_val ^ old_val) & (old_val ^ y)) < 0;
  }

  FixedInt& operator-=(UnsignedWord x) {
    rep_ -= x;
    return *this;
  }
  FixedInt& operator-=(Word x) { return *this -= FixedInt(x); }
  FixedInt& operator-=(const FixedInt& rh) {
    rep_ -= rh.rep_;
    return *this;
  }

  FixedInt& operator*=(UnsignedWord x) {
    rep_ *= x;
    return *this;
  }
  FixedInt& operator*=(Word x) {
    if (x >= 0) {
      rep_ *= x;
      return *this;
    }
    rep_ *= -static_cast<UnsignedWord>(x);
    *this = -(*this);
    return *this;
  }
  FixedInt& operator*=(const FixedInt& x) {
    rep_ *= x.rep_;
    return *this;
  }

  bool MultiplyOverflow(UnsignedWord x) {
    bool was_negative = is_negative();
    UnsignedWord carry =
        multiprecision_int_impl::MulWord(rep_.number_.data(), kNumWords, x);
    // See comment at ExtendAndMultiply(FixedInt) for why we subtract x from
    // carry.
    carry -= was_negative ? x : 0;
    return carry != (is_negative() ? ~UnsignedWord{0} : 0);
  }
  bool MultiplyOverflow(Word x) {
    FixedInt<kNumBitsPerWord, kNumWords + 1> result =
        ExtendAndMultiply(*this, FixedInt<kNumBitsPerWord, 1>(x));
    *this = FixedInt(result);
    return result.number()[kNumWords] != (is_negative() ? ~UnsignedWord{0} : 0);
  }
  // MultiplyOverflow(const FixedInt&) is much less efficient than
  // operator*=(const FixedInt&) and MultiplyOverflow(Word).
  bool MultiplyOverflow(const FixedInt& rh) {
    bool result_non_positive = is_negative() != rh.is_negative();
    if (ABSL_PREDICT_FALSE(is_negative())) {
      *this = -(*this);
    }
    // use | instead of ||, to call SetSignAndAbs even when MultiplyOverflow
    // returns true.
    return rep_.MultiplyOverflow(SafeAbs(rh)) |
           !SetSignAndAbs(result_non_positive, rep_);
  }

  template <int32_t divisor>
  void DivMod(std::integral_constant<int32_t, divisor> x, FixedInt* quotient,
              int32_t* remainder) const {
    bool neg = is_negative();
    bool divisor_negative = divisor < 0;
    const FixedInt& dividend_abs = ABSL_PREDICT_TRUE(!neg) ? *this : -(*this);
    uint32_t r = multiprecision_int_impl::ShortDivModConstant<kNumWords>(
        dividend_abs.rep_.number_, SafeAbs(x),
        quotient != nullptr ? &quotient->rep_.number_ : nullptr);
    if (ABSL_PREDICT_FALSE(neg != divisor_negative) && quotient != nullptr) {
      *quotient = -(*quotient);
    }
    if (remainder != nullptr) {
      *remainder = ABSL_PREDICT_FALSE(neg) ? -r : r;
    }
  }
  void DivMod(Word x, FixedInt* quotient, Word* remainder) const {
    bool neg = is_negative();
    bool divisor_negative = x < 0;
    const FixedInt& dividend_abs = ABSL_PREDICT_TRUE(!neg) ? *this : -(*this);
    UnsignedWord r =
        multiprecision_int_impl::ShortDivMod<UnsignedWord, kNumWords>(
            dividend_abs.rep_.number_, SafeAbs(x),
            quotient != nullptr ? &quotient->rep_.number_ : nullptr);
    if (ABSL_PREDICT_FALSE(neg != divisor_negative) && quotient != nullptr) {
      *quotient = -(*quotient);
    }
    if (remainder != nullptr) {
      *remainder = ABSL_PREDICT_FALSE(neg) ? -r : r;
    }
  }
  void DivMod(const FixedInt& divisor, FixedInt* quotient,
              FixedInt* remainder) const {
    bool neg = is_negative();
    bool divisor_negative = divisor.is_negative();
    const FixedInt& dividend_abs = ABSL_PREDICT_TRUE(!neg) ? *this : -(*this);
    const FixedInt& divisor_abs =
        ABSL_PREDICT_TRUE(!divisor_negative) ? divisor : -divisor;
    multiprecision_int_impl::DivMod<kNumWords>(
        dividend_abs.rep_.number_, divisor_abs.rep_.number_,
        quotient != nullptr ? &quotient->rep_.number_ : nullptr,
        remainder != nullptr ? &remainder->rep_.number_ : nullptr);
    if (ABSL_PREDICT_FALSE(neg != divisor_negative) && quotient != nullptr &&
        quotient != remainder) {
      *quotient = -(*quotient);
    }
    if (ABSL_PREDICT_FALSE(neg) && remainder != nullptr) {
      *remainder = -(*remainder);
    }
  }

  template <uint32_t divisor>
  FixedInt& operator/=(std::integral_constant<uint32_t, divisor> x) {
    return InternalDivMod<DivOp, true>(x);
  }
  template <int32_t divisor>
  FixedInt& operator/=(std::integral_constant<int32_t, divisor> x) {
    return InternalDivMod<DivOp, true>(x);
  }
  FixedInt& operator/=(UnsignedWord x) {
    return InternalDivMod<DivOp, true>(x);
  }
  FixedInt& operator/=(Word x) { return InternalDivMod<DivOp, true>(x); }
  FixedInt& operator/=(const FixedInt& x) {
    return InternalDivMod<DivOp, true>(x);
  }

  template <uint32_t divisor>
  FixedInt& DivAndRoundAwayFromZero(
      std::integral_constant<uint32_t, divisor> x) {
    return InternalDivMod<DivRoundOp, true>(x);
  }
  template <int32_t divisor>
  FixedInt& DivAndRoundAwayFromZero(
      std::integral_constant<int32_t, divisor> x) {
    return InternalDivMod<DivRoundOp, true>(x);
  }
  FixedInt& DivAndRoundAwayFromZero(UnsignedWord x) {
    return InternalDivMod<DivRoundOp, true>(x);
  }
  FixedInt& DivAndRoundAwayFromZero(Word x) {
    return InternalDivMod<DivRoundOp, true>(x);
  }
  FixedInt& DivAndRoundAwayFromZero(const FixedInt& x) {
    return InternalDivMod<DivRoundOp, true>(x);
  }

  template <int32_t divisor>
  FixedInt& operator%=(std::integral_constant<int32_t, divisor> x) {
    return InternalDivMod<ModOp, false>(x);
  }
  template <uint32_t divisor>
  FixedInt& operator%=(std::integral_constant<uint32_t, divisor> x) {
    return InternalDivMod<ModOp, false>(x);
  }
  FixedInt& operator%=(UnsignedWord x) {
    return InternalDivMod<ModOp, false>(x);
  }
  FixedInt& operator%=(Word x) { return InternalDivMod<ModOp, false>(x); }
  FixedInt& operator%=(const FixedInt& x) {
    return InternalDivMod<ModOp, false>(x);
  }

  bool is_zero() const { return rep_.is_zero(); }
  bool is_negative() const {
    return static_cast<Word>(rep_.number().back()) < 0;
  }
  FixedInt operator-() const { return FixedInt() -= *this; }
  bool NegateOverflow() {
    bool was_negative = is_negative();
    FixedUint<kNumBitsPerWord, kNumWords> result;
    bool is_nonzero = result.SubtractOverflow(rep_);
    rep_ = result;
    return is_nonzero && was_negative == is_negative();
  }

  constexpr const std::array<UnsignedWord, kNumWords>& number() const {
    return rep_.number_;
  }
  FixedUint<kNumBitsPerWord, kNumWords> abs() const {
    return ABSL_PREDICT_FALSE(is_negative()) ? (-(*this)).rep_ : rep_;
  }

  // Serializes to minimum number of bytes needed to represent the number,
  // using two's complement. The result is appended to *out.
  void SerializeToBytes(std::string* out) const {
    ConstVarIntRef<kNumBitsPerWord>(rep_.number_).SerializeToBytes(out);
  }

  // Deserializes the output of Serialize() from a FixedInt (not FixedUint) with
  // the same template arguments. If the input is valid, false is returned and
  // this instance is unchanged.
  ABSL_MUST_USE_RESULT bool DeserializeFromBytes(absl::string_view bytes) {
    return VarIntRef<kNumBitsPerWord>(rep_.number_).DeserializeFromBytes(bytes);
  }

  // Convert the FixedInt to a readable string form.
  std::string ToString() const {
    std::string result;
    AppendToString(&result);
    return result;
  }

  void AppendToString(std::string* result) const {
    if (ABSL_PREDICT_TRUE(!is_negative())) {
      rep_.AppendToString(result);
      return;
    }
    result->push_back('-');
    (-(*this)).rep_.AppendToString(result);
  }

  // Parse string representation of a signed decimal integer with digits only
  // except the plus/minus sign at the front, and write the number into the
  // FixedInt.
  bool ParseFromStringStrict(absl::string_view str) {
    if (ABSL_PREDICT_FALSE(str.empty())) {
      return false;
    }
    bool negate = str.at(0) == '-';
    str.remove_prefix(str.at(0) == '-' || str.at(0) == '+');
    return rep_.ParseFromStringStrict(str) && SetSignAndAbs(negate, rep_);
  }

  bool ParseFromStringSegments(
      absl::string_view first_segment,
      absl::Span<const absl::string_view> extra_segments) {
    if (ABSL_PREDICT_FALSE(first_segment.empty())) {
      return false;
    }
    bool negate = first_segment.at(0) == '-';
    first_segment.remove_prefix(first_segment.at(0) == '-' ||
                                first_segment.at(0) == '+');
    return rep_.ParseFromStringSegments(first_segment, extra_segments) &&
           SetSignAndAbs(negate, rep_);
  }

  static FixedInt PowerOf10(uint exponent) {
    FixedInt result(FixedUint<kNumBitsPerWord, kNumWords>::PowerOf10(exponent));
    ZETASQL_DCHECK(!result.is_negative());
    return result;
  }
  uint CountDecimalDigits() const { return abs().CountDecimalDigits(); }

  // Sets sign and absolute value. Returns false in case of overflow.
  bool SetSignAndAbs(bool negative,
                     const FixedUint<kNumBitsPerWord, kNumWords>& abs) {
    if (!negative) {
      rep_ = abs;
      return !is_negative();
    }
    FixedUint<kNumBitsPerWord, kNumWords> abs_copy = abs;
    rep_ = FixedUint<kNumBitsPerWord, kNumWords>();
    // SubtractOverflow returns false iff abs == 0.
    return !rep_.SubtractOverflow(abs_copy) || is_negative();
  }

  template <typename H>
  friend H AbslHashValue(H h,
                         const FixedInt<kNumBitsPerWord, kNumWords>& value) {
    return H::combine(std::move(h), value.rep_);
  }

 private:
  struct DivOp {
    template <typename T>
    void operator()(FixedInt& dividend, const T& divisor) const {
      dividend.rep_ /= divisor;
    }
  };
  struct DivRoundOp {
    template <typename T>
    void operator()(FixedInt& dividend, const T& divisor) const {
      // Highest value of rep_ is 0x8000...; the addition never overflows.
      dividend.rep_ += (divisor >> 1);
      dividend.rep_ /= divisor;
    }
    void operator()(
        FixedInt& dividend,
        const FixedUint<kNumBitsPerWord, kNumWords>& divisor) const {
      FixedUint<kNumBitsPerWord, kNumWords> tmp = divisor;
      tmp >>= 1;
      // Highest value of rep_ is 0x8000...; the addition never overflows.
      dividend.rep_ += tmp;
      dividend.rep_ /= divisor;
    }
  };
  struct ModOp {
    template <typename T>
    void operator()(FixedInt& dividend, const T& divisor) const {
      dividend.rep_ %= divisor;
    }
  };

  template <typename Op, bool use_divisor_sign, typename T>
  // GCC seems to produce bad code here on -02
  __attribute__((optimize("O0")))
  inline FixedInt& InternalDivMod(const T& divisor) {
    bool neg = is_negative();
    bool should_negate_again =
        neg != (use_divisor_sign && internal_is_negative(divisor));
    auto abs_divisor = SafeAbs(divisor);
    if (ABSL_PREDICT_FALSE(neg)) {
      *this = -(*this);
    }
    Op()(*this, abs_divisor);
    if (ABSL_PREDICT_FALSE(should_negate_again)) {
      *this = -(*this);
    }
    return *this;
  }

  template <typename V>
  static bool internal_is_negative(V x) {
    return x < 0;
  }
  static bool internal_is_negative(const FixedInt& x) {
    return x.is_negative();
  }
  static FixedUint<kNumBitsPerWord, kNumWords> SafeAbs(const FixedInt& x) {
    return x.abs();
  }
  static UnsignedWord SafeAbs(Word x) {
    return multiprecision_int_impl::SafeAbs<Word>(x);
  }
  static UnsignedWord SafeAbs(UnsignedWord x) { return x; }
  template <int32_t v>
  static std::integral_constant<uint32_t, multiprecision_int_impl::SafeAbs(v)>
  SafeAbs(std::integral_constant<int32_t, v> x) {
    return std::integral_constant<uint32_t,
                                  multiprecision_int_impl::SafeAbs(v)>();
  }
  template <uint32_t v>
  static std::integral_constant<uint32_t, v> SafeAbs(
      std::integral_constant<uint32_t, v> x) {
    return x;
  }

  FixedUint<kNumBitsPerWord, kNumWords> rep_;
};

template <int kNumBitsPerWord, int kNumWords>
inline bool operator==(const FixedInt<kNumBitsPerWord, kNumWords>& lh,
                       const FixedInt<kNumBitsPerWord, kNumWords>& rh) {
  return lh.number() == rh.number();
}

template <int kNumBitsPerWord, int kNumWords>
inline bool operator!=(const FixedInt<kNumBitsPerWord, kNumWords>& lh,
                       const FixedInt<kNumBitsPerWord, kNumWords>& rh) {
  return lh.number() != rh.number();
}

template <int kNumBitsPerWord, int kNumWords>
inline bool operator<(const FixedInt<kNumBitsPerWord, kNumWords>& lh,
                      const FixedInt<kNumBitsPerWord, kNumWords>& rh) {
  if (kNumWords == 1) {
    using SignedWord = multiprecision_int_impl::Int<kNumBitsPerWord>;
    return static_cast<SignedWord>(lh.number()[0]) <
           static_cast<SignedWord>(rh.number()[0]);
  }
  using SignedDword = multiprecision_int_impl::Int<kNumBitsPerWord * 2>;
  auto lh_hi = static_cast<SignedDword>(
      multiprecision_int_impl::MakeDword<kNumBitsPerWord>(lh.number().data() +
                                                          kNumWords - 2));
  auto rh_hi = static_cast<SignedDword>(
      multiprecision_int_impl::MakeDword<kNumBitsPerWord>(rh.number().data() +
                                                          kNumWords - 2));
  if (lh_hi != rh_hi) {
    return lh_hi < rh_hi;
  }
  return multiprecision_int_impl::Less<kNumBitsPerWord, kNumWords - 2>(
      lh.number().data(), rh.number().data());
}

template <int kNumBitsPerWord, int kNumWords>
inline bool operator>(const FixedInt<kNumBitsPerWord, kNumWords>& lh,
                      const FixedInt<kNumBitsPerWord, kNumWords>& rh) {
  return rh < lh;
}

template <int kNumBitsPerWord, int kNumWords>
inline bool operator<=(const FixedInt<kNumBitsPerWord, kNumWords>& lh,
                       const FixedInt<kNumBitsPerWord, kNumWords>& rh) {
  return !(rh < lh);
}

template <int kNumBitsPerWord, int kNumWords>
inline bool operator>=(const FixedInt<kNumBitsPerWord, kNumWords>& lh,
                       const FixedInt<kNumBitsPerWord, kNumWords>& rh) {
  return !(lh < rh);
}

// Equivalent to FixedUint<k, n1 + n2>(x) *= FixedUint<k, n1 + n2>(y)
// except that this method is typically 50-60% faster than the above code.
// This method never overflows.
template <int k, int n1, int n2>
inline FixedUint<k, n1 + n2> ExtendAndMultiply(const FixedUint<k, n1>& lh,
                                               const FixedUint<k, n2>& rh) {
  return FixedUint<k, n1 + n2>(
      multiprecision_int_impl::ExtendAndMultiply<k, n1, n2>(lh.number(),
                                                            rh.number()));
}

// Equivalent to FixedInt<k, n1 + n2>(x) *= FixedInt<k, n1 + n2>(y)
// except that this method is typically 50-60% faster than the above code.
// This method never overflows.
template <int k, int n1, int n2>
inline FixedInt<k, n1 + n2> ExtendAndMultiply(const FixedInt<k, n1>& lh,
                                              const FixedInt<k, n2>& rh) {
  auto result = multiprecision_int_impl::ExtendAndMultiply<k, n1, n2>(
      lh.number(), rh.number());
  // Let b = 2 ^ k, L = lh.number() (treated as an unsigned integer) and
  // R = rh.number() (treated as an unsigned integer).
  // 1) If lh < 0 and rh > 0, then lh = L - b ^ n1 and rh = R;
  //    lh * rh = L * R - R * b ^ n1 = result - R * b ^ n1;
  //    we should subtract R * b ^ n1 from <result>.
  // 2) Similarly, if lh > 0 and rh < 0, then we should subtract L * b ^ n2 from
  //    <result>.
  // 3) If lh < 0 and rh < 0, then
  //    lh * rh = (L - b ^ n1) * (R - b ^ n2)
  //            = L * R - R * b ^ n1 - L * b ^ n2 + b ^ (n1 + n2);
  //    b ^ (n1 + n2) can be ignored because result has only n1 + n2 words.
  //    We should subtract both R * b ^ n1 and L * b ^ n2.
  if (ABSL_PREDICT_FALSE(lh.is_negative())) {
    multiprecision_int_impl::SubtractWithVariableSize(result.data() + n1,
                                                      rh.number().data(), n2);
  }
  if (ABSL_PREDICT_FALSE(rh.is_negative())) {
    multiprecision_int_impl::SubtractWithVariableSize(result.data() + n2,
                                                      lh.number().data(), n1);
  }
  return FixedInt<k, n1 + n2>(result);
}

template <bool is_signed, typename UnsignedWord>
void VarIntBase<is_signed, UnsignedWord>::SerializeToBytes(
    std::string* bytes) const {
#ifdef ABSL_IS_LITTLE_ENDIAN
  ZETASQL_DCHECK(!number_.empty());
  const char extension =
      is_signed &&
              static_cast<std::make_signed_t<UnsignedWord>>(number_.back()) < 0
          ? '\xff'
          : '\x0';
  const char* src_begin = reinterpret_cast<const char*>(number_.data());
  const char* src_end = src_begin + sizeof(UnsignedWord) * number_.size();
  const char* last_byte = src_end - 1;
  // Skip last extension characters if they are redundant.
  while (last_byte > src_begin && *last_byte == extension) {
    --last_byte;
  }
  // If signed and the last byte has a different sign bit than the extension,
  // add one extension byte to preserve the sign bit.
  // "last_byte < src_end" is not necessary but makes the compiler generate
  // more efficient code, for unknown reasons.
  if (is_signed && last_byte < src_end &&
      ((*last_byte ^ extension) & '\x80') != 0) {
    ++last_byte;
  }
  bytes->append(src_begin, last_byte - src_begin + 1);
#else
  multiprecision_int_impl::SerializeNoOptimization<is_signed>(number_, bytes);
#endif
}

// Deserialize from minimum number of bytes needed to represent the number.
// Similarly to Serialize, if is_signed is true then a high 0x80 bit
// will result in padding with 0xff rather than 0x00
template <bool is_signed, typename UnsignedWord>
bool VarIntBase<is_signed, UnsignedWord>::DeserializeFromBytes(
    absl::string_view bytes) {
  // We allow one extra byte in case of the 0x80 high byte case, see
  // comments on Serialize for details
  if (ABSL_PREDICT_FALSE(bytes.empty() || bytes.size() > sizeof(UnsignedWord) *
                                                             number_.size())) {
    return false;
  }
  // Most callers already initialize *out to zero and the compiler is likely
  // to optimize fill(0) away.
  UnsignedWord* output_begin = number_.data();
  UnsignedWord* output_end = output_begin + number_.size();
  std::fill(output_begin, output_end, UnsignedWord{0});
  if (is_signed && (bytes.back() & '\x80')) {
    std::fill(output_begin, output_end, ~UnsignedWord{0});
  }
  memcpy(output_begin, bytes.data(), bytes.size());
  // The compiler is expected to remove this loop if the host is little endian.
  for (UnsignedWord* word = output_begin; word != output_end; ++word) {
    static_assert(sizeof(UnsignedWord) == sizeof(uint32_t) ||
                  sizeof(UnsignedWord) == sizeof(uint64_t));
    if (sizeof(UnsignedWord) == sizeof(uint32_t)) {
      *word = zetasql_base::LittleEndian::ToHost32(*word);
    } else {
      *word = zetasql_base::LittleEndian::ToHost64(*word);
    }
  }
  return true;
}

template <int kNumBitsPerWord>
void VarIntRef<kNumBitsPerWord>::Negate() {
  uint8_t carry = 1;
  using UnsignedWord = multiprecision_int_impl::Uint<kNumBitsPerWord>;
  for (UnsignedWord& word : this->number_) {
    word = ~word;
    carry =
        multiprecision_int_impl::AddWithCarry(&word, UnsignedWord{0}, carry);
  }
}

template <int kNumBitsPerWord>
template <uint32_t divisor>
uint32_t VarUintRef<kNumBitsPerWord>::DivMod(
    std::integral_constant<uint32_t, divisor> x) {
  static_assert(kNumBitsPerWord == 32);
  uint32_t remainder = 0;
  for (auto itr = this->number_.rbegin(); itr != this->number_.rend(); ++itr) {
    // DivModWord is more efficient than RawDivModWord if and only if
    // the divisor is a compile-time constant.
    multiprecision_int_impl::DivModWord(remainder, *itr, divisor, &*itr,
                                        &remainder);
  }
  return remainder;
}

template <int kNumBitsPerWord>
uint32_t VarUintRef<kNumBitsPerWord>::DivMod(uint32_t divisor) {
  static_assert(kNumBitsPerWord == 32);
  uint32_t remainder = 0;
  for (auto itr = this->number_.rbegin(); itr != this->number_.rend(); ++itr) {
    multiprecision_int_impl::RawDivModWord(remainder, *itr, divisor, &*itr,
                                           &remainder);
  }
  return remainder;
}

template <bool is_signed, typename UnsignedWord>
void VarIntBase<is_signed, UnsignedWord>::AppendToString(
    std::string* result) const {
  ZETASQL_DCHECK(result != nullptr);
  if (number_.empty()) {
    result->push_back('0');
    return;
  }
  static_assert(sizeof(UnsignedWord) == sizeof(uint32_t));
  std::vector<uint32_t> dividend(data(), data() + size());
  if (is_signed && (dividend.back() & (1U << 31)) != 0) {
    VarIntRef<32>(dividend).Negate();
    result->push_back('-');
  }

  while (dividend.back() == 0) {
    dividend.pop_back();
    if (dividend.empty()) {
      result->push_back('0');
      return;
    }
  }

  size_t num_bits = 32 * dividend.size();
  // The number of segments needed = ceil(num_bits * log(2) / log(1000000000))
  // = ceil(num_bits / 29.897352854) <= ceil(num_bits / 29).
  std::vector<uint32_t> segments((num_bits + 28) / 29);
  size_t num_segments = 0;
  do {
    VarUintRef<32> ref(dividend);
    segments[num_segments] =
        ref.DivMod(std::integral_constant<uint32_t, 1000000000>());
    ++num_segments;
    if (dividend.back() == 0) {
      dividend.pop_back();
    }
  } while (!dividend.empty());
  multiprecision_int_impl::AppendSegmentsToString(segments.data(), num_segments,
                                                  result);
}

}  // namespace zetasql

#endif  // ZETASQL_COMMON_MULTIPRECISION_INT_H_
