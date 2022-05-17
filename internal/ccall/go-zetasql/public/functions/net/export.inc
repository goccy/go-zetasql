#ifndef ZETASQL_PUBLIC_FUNCTIONS_NET_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_NET_EXPORT_H

#include "zetasql/public/functions/net.h"
#include "zetasql/public/functions/net.cc"

#if 0
namespace zetasql {
  namespace functions {
    namespace net {

      bool FormatIP(int64_t in, std::string* out, absl::Status* error) {
        return false;
      }

      bool IPv4FromInt64(int64_t in, std::string* out, absl::Status* error) {
        return false;
      }

      bool ParseIP(absl::string_view in, int64_t* out, absl::Status* error) {
        return false;
      }

      bool IPv4ToInt64(absl::string_view in, int64_t* out, absl::Status* error) {
        return false;
      }

      bool FormatPackedIP(absl::string_view in, std::string* out, absl::Status* error) {
        return false;
      }

      bool IPToString(absl::string_view in, std::string* out, absl::Status* error) {
        return false;
      }

      bool ParsePackedIP(absl::string_view in, std::string* out, absl::Status* error) {
        return false;
      }

      bool IPFromString(absl::string_view in, std::string* out, absl::Status* error) {
        return false;
      }

      absl::Status SafeIPFromString(absl::string_view in, std::string* out, bool* is_null) {
        return absl::OkStatus();
      }

      bool IPNetMask(int64_t output_length_bytes, int64_t prefix_length_bits, std::string* out, absl::Status* error) {
        return false;
      }

      bool IPTrunc(absl::string_view in, int64_t prefix_length_bits, std::string* out, absl::Status* error) {
        return false;
      }

      bool IPInNet(absl::string_view ip, absl::string_view net, bool* out, absl::Status* error) {
        return false;
      }

      bool MakeNet(absl::string_view ip_string, int32_t subnet_size, std::string* out, absl::Status* error) {
        return false;
      }

      absl::Status Host(absl::string_view url, absl::string_view* out, bool* is_null) {
        return absl::OkStatus();
      }

      absl::Status RegDomain(absl::string_view url, absl::string_view* out, bool* is_null) {
        return absl::OkStatus();
      }

      absl::Status PublicSuffix(absl::string_view url, absl::string_view* out, bool* is_null) {
        return absl::OkStatus();
      }

    }
  }
}
#endif

#include "go-zetasql/public/functions/util/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/net/idn/export.inc"
#include "go-zetasql/base/net/ipaddress/export.inc"
#include "go-zetasql/base/net/public_suffix/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
