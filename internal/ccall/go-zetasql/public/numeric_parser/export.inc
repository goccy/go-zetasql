#ifndef ZETASQL_PUBLIC_NUMERIC_PARSER_EXPORT_H
#define ZETASQL_PUBLIC_NUMERIC_PARSER_EXPORT_H

#include "zetasql/public/numeric_parser.h"

#define PowersAsc GO_EXPORT(PowersAscParser)
#include "zetasql/public/numeric_parser.cc"
#undef PowersAsc

#if 0
namespace zetasql {

  bool ParseExponent(absl::string_view exp_part, uint extra_scale, int64_t* exp) {
    return false;
  }

  template <typename Word, Word first_value, Word base, int size, typename... T>
  constexpr std::array<Word, size> PowersAsc(T... v) {
    if constexpr (sizeof...(T) < size) {
        return PowersAsc<Word, first_value, base, size>(first_value, v * base...);
      } else {
      return std::array<Word, size>{v...};
    }
  }

  template <int n>
  bool ParseNumber(absl::string_view int_part, absl::string_view fract_part,
                   int64_t exp, bool strict, FixedUint<64, n>* output) {
    return false;
  }

  template <uint32_t word_count, uint32_t scale, bool strict_parsing>
  absl::Status ParseNumber(absl::string_view str,
                           FixedPointRepresentation<word_count>& parsed) {
    absl::Status v;
    return v;
  }

  template <bool strict_parsing>
  absl::Status ParseNumeric(absl::string_view str,
                            FixedPointRepresentation<2>& parsed) {
    absl::Status v;
    return v;
  }

  template <bool strict_parsing>
  absl::Status ParseBigNumeric(absl::string_view str,
                               FixedPointRepresentation<4>& parsed) {
    absl::Status v;
    return v;
  }

  absl::Status ParseJSONNumber(absl::string_view str,
                               FixedPointRepresentation<79>& parsed) {
    absl::Status v;
    return v;
  }

  template absl::Status ParseNumeric</*strict_parsing=*/true>(absl::string_view str, FixedPointRepresentation<2>& parsed);
  template absl::Status ParseNumeric</*strict_parsing=*/false>(absl::string_view str, FixedPointRepresentation<2>& parsed);
  template absl::Status ParseBigNumeric</*strict_parsing=*/true>(absl::string_view str, FixedPointRepresentation<4>& parsed);
  template absl::Status ParseBigNumeric</*strict_parsing=*/false>(absl::string_view str, FixedPointRepresentation<4>& parsed);

}
#endif

#include "go-zetasql/public/numeric_constants/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/multiprecision_int/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
