#ifndef ZETASQL_PUBLIC_CYCLE_DETECTOR_EXPORT_H
#define ZETASQL_PUBLIC_CYCLE_DETECTOR_EXPORT_H

#include "zetasql/public/cycle_detector.h"
#include "zetasql/public/cycle_detector.cc"

#if 0
namespace zetasql {

  absl::Status CycleDetector::ObjectInfo::DetectCycle(const std::string& object_type) const {
    absl::Status v;
    return v;
  }

  bool CycleDetector::DetectCycleOrPushObject(const ObjectInfo* object_info) {
    return false;
  }

  void CycleDetector::PopObject(const ObjectInfo* expected_object_info) {
  }

  CycleDetector::ObjectInfo::ObjectInfo(const std::string& name,
                                        const void* object,
                                        CycleDetector* cycle_detector)
    : name_(name), object_(object) {
  }

  CycleDetector::ObjectInfo::~ObjectInfo() {
  }

  bool CycleDetector::ObjectInfo::DetectCycleOrAddToCycleDetector(CycleDetector* cycle_detector) {
    return false;
  }

  std::string CycleDetector::DebugString() const {
    return "";
  }

  std::vector<std::string> CycleDetector::ObjectNames() const {
    std::vector<std::string> v;
    return v;
  }

}
#endif

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
