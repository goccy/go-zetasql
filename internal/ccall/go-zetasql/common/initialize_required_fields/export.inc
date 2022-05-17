#ifndef ZETASQL_COMMON_INITIALIZE_REQUIRED_FIELDS_EXPORT_H
#define ZETASQL_COMMON_INITIALIZE_REQUIRED_FIELDS_EXPORT_H

#include "zetasql/common/initialize_required_fields.h"
#include "zetasql/common/initialize_required_fields.cc"

#if 0
namespace zetasql {

  bool InitializeRequiredField(const google::protobuf::Reflection* reflection,
                               const google::protobuf::FieldDescriptor* field,
                               google::protobuf::Message* message,
                               std::set<std::string>* visited) {
    return false;
  }

  bool InitializeMissingRequiredFields(google::protobuf::Message* message,
                                       std::set<std::string>* visited) {
    return false;
  }

  void InitializeRequiredFields(google::protobuf::Message* message) {
  }

}
#endif

#include "go-protobuf/protobuf/export.inc"

#endif
