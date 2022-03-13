#ifndef ZETASQL_PUBLIC_FUNCTIONS_UTIL_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_UTIL_EXPORT_H

#include "zetasql/public/functions/util.h"

//#include "zetasql/public/functions/util.cc"

namespace zetasql {
  namespace functions {
    namespace internal {

      absl::Status CreateFunctionError(absl::string_view msg) {
        return absl::OkStatus();
      }

      bool UpdateError(absl::Status* status, absl::string_view msg) {
        return false;
      }

      absl::Status ValidatePositionAndOccurrence(int64_t position,
                                                 int64_t occurrence) {
        return absl::OkStatus();
      }

      template <typename T>
      std::string UnaryOverflowMessage(T in, absl::string_view operator_symbol) {
        return "";
      }

      template std::string UnaryOverflowMessage<int32_t>(int32_t in, absl::string_view operator_symbol);
      template std::string UnaryOverflowMessage<int64_t>(int64_t in, absl::string_view operator_symbol);

      template <typename T>
      std::string BinaryOverflowMessage(T in1, T in2, absl::string_view operator_symbol) {
        return "";
      }

      template std::string BinaryOverflowMessage<int32_t>(int32_t in1, int32_t in2, absl::string_view operator_symbol);
      template std::string BinaryOverflowMessage<int64_t>(int64_t in1, int64_t in2, absl::string_view operator_symbol);
      template std::string BinaryOverflowMessage<uint64_t>(uint64_t in1, uint64_t in2, absl::string_view operator_symbol);
      template std::string BinaryOverflowMessage<float>(float in1, float in2, absl::string_view operator_symbol);
      template std::string BinaryOverflowMessage<double>(double in1, double in2, absl::string_view operator_symbol);
      template std::string BinaryOverflowMessage<long double>(long double in1, long double in2, absl::string_view operator_symbol);

      template <typename T>
      std::string DivisionByZeroMessage(T in1, T in2) {
        return "";
      }

      template std::string DivisionByZeroMessage<int64_t>(int64_t in1, int64_t in2);
      template std::string DivisionByZeroMessage<uint64_t>(uint64_t in1, uint64_t in2);
      template std::string DivisionByZeroMessage<double>(double in1, double in2);
      template std::string DivisionByZeroMessage<long double>(long double in1, long double in2);
    }
  }
}

#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/utf_util/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
