#ifndef ZETASQL_BASE_BITS_EXPORT_H
#define ZETASQL_BASE_BITS_EXPORT_H

#include "zetasql/base/bits.h"

#include "zetasql/base/bits.cc"

#if 0
namespace zetasql_base {

  const char Bits::num_bits[] = {};
  int Bits::Count(const void *m, int num_bytes) {
    return 0;
  }

  int Bits::Difference(const void *m1, const void *m2, int num_bytes) {
    return 0;
  }

  int Bits::CappedDifference(const void *m1, const void *m2,
                             int num_bytes, int cap) {
    return 0;
  }

  int Bits::Log2Floor_Portable(uint32_t n) {
    return 0;
  }

  int Bits::Log2Ceiling(uint32_t n) {
    return 0;
  }

  int Bits::Log2Ceiling64(uint64_t n) {
    return 0;
  }

  int Bits::Log2Ceiling128(absl::uint128 n) {
    return 0;
  }

  int Bits::FindLSBSetNonZero_Portable(uint32_t n) {
    return 0;
  }

  int Bits::CountLeadingZeros32_Portable(uint32_t n) {
    return 0;
  }

  int Bits::CountLeadingZeros64_Portable(uint64_t n) {
    return 0;
  }

}
#endif

#include "go-zetasql/base/endian/export.inc"
#include "go-zetasql/base/logging/export.inc"
#include "go-absl/base/base/export.inc"
#include "go-absl/numeric/int128/export.inc"

#endif
