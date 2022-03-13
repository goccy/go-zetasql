#ifndef ABSL_BASE_LOG_SEVERITY_EXPORT_H
#define ABSL_BASE_LOG_SEVERITY_EXPORT_H

#include "absl/base/log_severity.h"
#include "absl/base/log_severity.cc"

#if 0
namespace absl {
  std::ostream& operator<<(std::ostream& os, absl::LogSeverity s) {
    if (s == absl::NormalizeLogSeverity(s)) return os << absl::LogSeverityName(s);
    return os << "absl::LogSeverity(" << static_cast<int>(s) << ")";
  }
  
  std::ostream& operator<<(std::ostream& os, absl::LogSeverityAtLeast s) {
    switch (s) {
    case absl::LogSeverityAtLeast::kInfo:
    case absl::LogSeverityAtLeast::kWarning:
    case absl::LogSeverityAtLeast::kError:
    case absl::LogSeverityAtLeast::kFatal:
      return os << ">=" << static_cast<absl::LogSeverity>(s);
    case absl::LogSeverityAtLeast::kInfinity:
      return os << "INFINITY";
    }
    return os;
  }

  std::ostream& operator<<(std::ostream& os, absl::LogSeverityAtMost s) {
    switch (s) {
    case absl::LogSeverityAtMost::kInfo:
    case absl::LogSeverityAtMost::kWarning:
    case absl::LogSeverityAtMost::kError:
    case absl::LogSeverityAtMost::kFatal:
      return os << "<=" << static_cast<absl::LogSeverity>(s);
    case absl::LogSeverityAtMost::kNegativeInfinity:
      return os << "NEGATIVE_INFINITY";
    }
    return os;
  }
}
#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"

#endif
