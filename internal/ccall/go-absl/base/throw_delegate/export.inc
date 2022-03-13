#ifndef ABSL_BASE_THROW_DELEGATE_EXPORT_H
#define ABSL_BASE_THROW_DELEGATE_EXPORT_H

#include "absl/base/internal/throw_delegate.h"

#include "absl/base/internal/throw_delegate.cc"

#if 0
namespace absl {
  namespace base_internal {

    void ThrowStdLogicError(const std::string& what_arg) {
      throw std::runtime_error("error");
    }
    void ThrowStdLogicError(const char* what_arg) {
      throw std::runtime_error("error");
    }
    void ThrowStdInvalidArgument(const std::string& what_arg) {
      throw std::runtime_error("error");
    }
    void ThrowStdInvalidArgument(const char* what_arg) {
      throw std::runtime_error("error");
    }

    void ThrowStdDomainError(const std::string& what_arg) {
      throw std::runtime_error("error");
    }
    void ThrowStdDomainError(const char* what_arg) {
      throw std::runtime_error("error");
    }

    void ThrowStdLengthError(const std::string& what_arg) {
      throw std::runtime_error("error");
    }
    void ThrowStdLengthError(const char* what_arg) {
      throw std::runtime_error("error");
    }

    void ThrowStdOutOfRange(const std::string& what_arg) {
      throw std::runtime_error("error");
    }
    void ThrowStdOutOfRange(const char* what_arg) {
      throw std::runtime_error("error");
    }

    void ThrowStdRuntimeError(const std::string& what_arg) {
      throw std::runtime_error("error");
    }
    void ThrowStdRuntimeError(const char* what_arg) {
      throw std::runtime_error("error");
    }

    void ThrowStdRangeError(const std::string& what_arg) {
      throw std::runtime_error("error");
    }
    void ThrowStdRangeError(const char* what_arg) {
      throw std::runtime_error("error");
    }

    void ThrowStdOverflowError(const std::string& what_arg) {
      throw std::runtime_error("error");
    }
    void ThrowStdOverflowError(const char* what_arg) {
      throw std::runtime_error("error");
    }

    void ThrowStdUnderflowError(const std::string& what_arg) {
      throw std::runtime_error("error");
    }
    void ThrowStdUnderflowError(const char* what_arg) {
      throw std::runtime_error("error");
    }

    void ThrowStdBadFunctionCall() {
      throw std::runtime_error("error");
    }

    void ThrowStdBadAlloc() {
      throw std::runtime_error("error");
    }
  }
}

#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"

#endif
