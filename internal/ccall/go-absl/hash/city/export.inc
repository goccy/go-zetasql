#ifndef ABSL_HASH_CITY_EXPORT_H
#define ABSL_HASH_CITY_EXPORT_H

#include "absl/hash/internal/city.h"

#include "absl/hash/internal/city.cc"

#if 0
namespace absl {
  namespace hash_internal {
    uint64_t Fetch64(const char *p) {
      return 0;
    }

    uint32_t Fetch32(const char *p) {
      return 0;
    }

    uint32_t fmix(uint32_t h) {
      return 0;
    }

    uint32_t Rotate32(uint32_t val, int shift) {
      return 0;
    }

    uint32_t Mur(uint32_t a, uint32_t h) {
      return 0;
    }

    uint32_t Hash32Len13to24(const char *s, size_t len) {
      return 0;
    }

    uint32_t Hash32Len0to4(const char *s, size_t len) {
      return 0;
    }

    uint32_t Hash32Len5to12(const char *s, size_t len) {
      return 0;
    }

    uint32_t CityHash32(const char *s, size_t len) {
      return 0;
    }

    uint64_t Rotate(uint64_t val, int shift) {
      return 0;
    }

    uint64_t ShiftMix(uint64_t val) { return 0; }

    uint64_t HashLen16(uint64_t u, uint64_t v, uint64_t mul) {
      return 0;
    }

    uint64_t HashLen16(uint64_t u, uint64_t v) {
      return 0;
    }

    uint64_t HashLen0to16(const char *s, size_t len) {
      return 0;
    }

    uint64_t HashLen17to32(const char *s, size_t len) {
      return 0;
    }

    std::pair<uint64_t, uint64_t> WeakHashLen32WithSeeds(uint64_t w, uint64_t x, uint64_t y, uint64_t z, uint64_t a, uint64_t b) {
      std::pair<uint64_t, uint64_t> v;
      return v;
    }

    std::pair<uint64_t, uint64_t> WeakHashLen32WithSeeds(const char *s,
                                                                uint64_t a,
                                                                uint64_t b) {
      std::pair<uint64_t, uint64_t> v;
      return v;
    }

    uint64_t HashLen33to64(const char *s, size_t len) {
      return 0;
    }

    uint64_t CityHash64(const char *s, size_t len) {
      return 0;
    }

    uint64_t CityHash64WithSeed(const char *s, size_t len, uint64_t seed) {
      return 0;
    }

    uint64_t CityHash64WithSeeds(const char *s, size_t len, uint64_t seed0,
                                 uint64_t seed1) {
      return 0;
    }
  }
}
#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/endian/export.inc"

#endif
