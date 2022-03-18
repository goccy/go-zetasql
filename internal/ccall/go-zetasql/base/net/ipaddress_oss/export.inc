#ifndef ZETASQL_BASE_NET_IPADDRESS_OSS_EXPORT_H
#define ZETASQL_BASE_NET_IPADDRESS_OSS_EXPORT_H

#include "zetasql/base/net/ipaddress_oss.h"
#include "zetasql/base/net/ipaddress_oss.cc"

#if 0
namespace zetasql::internal {

  IPAddress IPAddress::Any4() {
    IPAddress v;
    return v;
  }

  IPAddress IPAddress::Any6() {
    IPAddress v;
    return v;
  }

  in6_addr IPAddress::ipv6_address_slowpath() const {
    in6_addr v;
    return v;
  }

  IPAddress HostUInt32ToIPAddress(uint32_t address) {
    IPAddress v;
    return v;
  }

  IPAddress UInt128ToIPAddress(const absl::uint128 bigint) {
    IPAddress v;
    return v;
  }

  std::string IPAddress::ToString() const {
    return "";
  }

  std::string IPAddress::ToPackedString() const {
    return "";
  }

  absl::StatusOr<IPAddress> MakeIPAddressWithScopeId(const in6_addr& addr, uint32_t scope_id) {
    IPAddress v;
    return v;
  }

  bool StringToIPAddress(const char* str, IPAddress* out) {
    return false;
  }

  bool StringToIPAddress(const absl::string_view str, IPAddress* out) {
    return false;
  }

  absl::StatusOr<IPAddress> StringToIPAddressWithOptionalScope(const absl::string_view str) {
    IPAddress v;
    return v;
  }

  bool PackedStringToIPAddress(absl::string_view str, IPAddress* out) {
    return false;
  }

  bool StringToIPRange(absl::string_view str, IPRange* out) {
    return false;
  }

  bool StringToIPRangeAndTruncate(absl::string_view str, IPRange* out) {
    return false;
  }

  namespace ipaddress_internal {
    IPAddress TruncateIPAndLength(const IPAddress& addr, int* length_io) {
      IPAddress v;
      return v;
    }

  }

}
#endif

#include "go-zetasql/base/endian/export.inc"
#include "go-zetasql/base/logging/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/numeric/int128/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/str_format/export.inc"

#endif
