#ifndef ABSL_FLAGS_MARSHALLING_EXPORT_H
#define ABSL_FLAGS_MARSHALLING_EXPORT_H

#include "absl/flags/marshalling.h"

#include "absl/flags/marshalling.cc"

#if 0

namespace absl {
  namespace flags_internal {

    bool AbslParseFlag(absl::string_view text, bool* dst, std::string*) {
      return false;
    }

    int NumericBase(absl::string_view text) {
      return 0;
    }

    template <typename IntType>
    bool ParseFlagImpl(absl::string_view text, IntType& dst) {
      return false;
    }

    bool AbslParseFlag(absl::string_view text, short* dst, std::string*) {
      return false;
    }

    bool AbslParseFlag(absl::string_view text, unsigned short* dst, std::string*) {
      return false;
    }

    bool AbslParseFlag(absl::string_view text, int* dst, std::string*) {
      return false;
    }

    bool AbslParseFlag(absl::string_view text, unsigned int* dst, std::string*) {
      return false;
    }

    bool AbslParseFlag(absl::string_view text, long* dst, std::string*) {
      return false;
    }

    bool AbslParseFlag(absl::string_view text, unsigned long* dst, std::string*) {
      return false;
    }

    bool AbslParseFlag(absl::string_view text, long long* dst, std::string*) {
      return false;
    }

    bool AbslParseFlag(absl::string_view text, unsigned long long* dst,
                       std::string*) {
      return false;
    }

    bool AbslParseFlag(absl::string_view text, float* dst, std::string*) {
      return false;
    }

    bool AbslParseFlag(absl::string_view text, double* dst, std::string*) {
      return false;
    }

    bool AbslParseFlag(absl::string_view text, std::string* dst, std::string*) {
      return false;
    }

    bool AbslParseFlag(absl::string_view text, std::vector<std::string>* dst,
                       std::string*) {
      return false;
    }

    std::string Unparse(bool v) { return ""; }
    std::string Unparse(short v) { return ""; }
    std::string Unparse(unsigned short v) { return ""; }
    std::string Unparse(int v) { return ""; }
    std::string Unparse(unsigned int v) { return ""; }
    std::string Unparse(long v) { return ""; }
    std::string Unparse(unsigned long v) { return ""; }
    std::string Unparse(long long v) { return ""; }
    std::string Unparse(unsigned long long v) { return ""; }
    template <typename T>
    std::string UnparseFloatingPointVal(T v) {
      return "";
    }
    std::string Unparse(float v) { return ""; }
    std::string Unparse(double v) { return ""; }
    std::string AbslUnparseFlag(absl::string_view v) { return ""; }
    std::string AbslUnparseFlag(const std::vector<std::string>& v) {
      return "";
    }
  }
  bool AbslParseFlag(absl::string_view text, absl::LogSeverity* dst,
                     std::string* err) {
    return false;
  }

  std::string AbslUnparseFlag(absl::LogSeverity v) {
    return "";
  }
}

#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/log_severity/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
