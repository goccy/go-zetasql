#ifndef ABSL_STRINGS_CORDZ_SAMPLE_TOKEN_EXPORT_H
#define ABSL_STRINGS_CORDZ_SAMPLE_TOKEN_EXPORT_H

#include "absl/strings/internal/cordz_sample_token.h"
#include "absl/strings/internal/cordz_sample_token.cc"

#if 0
namespace absl {
  namespace cord_internal {

    CordzSampleToken::Iterator& CordzSampleToken::Iterator::operator++() {
      return *this;
    }

    CordzSampleToken::Iterator CordzSampleToken::Iterator::operator++(int) {
      Iterator it(*this);
      operator++();
      return it;
    }

    bool operator==(const CordzSampleToken::Iterator& lhs,
                    const CordzSampleToken::Iterator& rhs) {
      return false;
    }

    bool operator!=(const CordzSampleToken::Iterator& lhs,
                    const CordzSampleToken::Iterator& rhs) {
      return false;
    }

    CordzSampleToken::Iterator::reference CordzSampleToken::Iterator::operator*()
      const {
      return *current_;
    }

    CordzSampleToken::Iterator::pointer CordzSampleToken::Iterator::operator->()
      const {
      return current_;
    }

    CordzSampleToken::Iterator::Iterator(const CordzSampleToken* token)
      : token_(token), current_(CordzInfo::Head(*token)) {}

  }
}
#endif

#include "go-absl/strings/cordz_handle/export.inc"
#include "go-absl/strings/cordz_info/export.inc"
#include "go-absl/base/config/export.inc"

#endif
