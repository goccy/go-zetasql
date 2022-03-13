#ifndef ABSL_STRINGS_INTERNAL_EXPORT_H
#define ABSL_STRINGS_INTERNAL_EXPORT_H

#include "absl/strings/internal/char_map.h"
#include "absl/strings/internal/escaping.h"
#include "absl/strings/internal/ostringstream.h"
#include "absl/strings/internal/resize_uninitialized.h"
#include "absl/strings/internal/utf8.h"

#include "absl/strings/internal/escaping.cc"
#include "absl/strings/internal/ostringstream.cc"
#include "absl/strings/internal/utf8.cc"

#if 0
namespace absl {
  namespace strings_internal {

    const char kBase64Chars[] = {};

    size_t CalculateBase64EscapedLenInternal(size_t input_len, bool do_padding) {
      return 0;
    }

    size_t Base64EscapeInternal(const unsigned char* src, size_t szsrc, char* dest,
                                size_t szdest, const char* base64,
                                bool do_padding) {
      return 0;
    }

  }
}

namespace absl {
  namespace strings_internal {

    OStringStream::Buf::int_type OStringStream::overflow(int c) {
      return 0;
    }

    std::streamsize OStringStream::xsputn(const char* s, std::streamsize n) {
      std::streamsize v;
      return v;
    }

  }
}

namespace absl {
  namespace strings_internal {

    size_t EncodeUTF8Char(char *buffer, char32_t utf8_char) {
      return 0;
    }

  }
}

#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/endian/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/meta/type_traits/export.inc"

#endif
