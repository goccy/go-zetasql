#ifndef ZETASQL_BASE_LOGGING_EXPORT_H
#define ZETASQL_BASE_LOGGING_EXPORT_H

#include "zetasql/base/logging.h"

#include "zetasql/base/logging.cc"

#if 0
namespace zetasql_base {

  std::string get_log_directory() {
    return "";
  }

  int get_vlog_level() { return 0; }

  bool InitLogging(const char *directory, const char *file_name, int level) {
    return false;
  }


  CheckOpMessageBuilder::CheckOpMessageBuilder(const char *exprtext)
    : stream_(new std::ostringstream) {
  }

  CheckOpMessageBuilder::~CheckOpMessageBuilder() { }

  std::ostream *CheckOpMessageBuilder::ForVar2() {
    return stream_;
  }

  std::string *CheckOpMessageBuilder::NewString() {  // NOLINT
    return nullptr;
  }

  template <>
  void MakeCheckOpValueString(std::ostream *os, const char &v) {
  }

  template <>
  void MakeCheckOpValueString(std::ostream *os, const signed char &v) {
  }

  template <>
  void MakeCheckOpValueString(std::ostream *os, const unsigned char &v) {
  }

  template <>
  void MakeCheckOpValueString(std::ostream *os, const std::nullptr_t &v) {
  }

  namespace logging_internal {

    LogMessage::LogMessage(const char *file, int line)
      : LogMessage(file, line, absl::LogSeverity::kInfo) {}

    LogMessage::LogMessage(const char *file, int line, const std::string &result)
      : LogMessage(file, line, absl::LogSeverity::kFatal) {
    }

    LogMessage::LogMessage(const char *file, int line, absl::LogSeverity severity)
      : severity_(severity) {
    }

    LogMessage::~LogMessage() {
    }

    void LogMessage::SendToLog(const std::string &message_text) {
    }

    void LogMessage::Flush() {
    }

    LogMessageFatal::~LogMessageFatal() {
      abort();
    }

  }

}
#endif

#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/log_severity/export.inc"


#endif
