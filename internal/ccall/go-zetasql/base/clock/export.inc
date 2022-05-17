#ifndef ZETASQL_BASE_CLOCK_EXPORT_H
#define ZETASQL_BASE_CLOCK_EXPORT_H

#include "zetasql/base/clock.h"
#include "zetasql/base/clock.cc"

#if 0
namespace zetasql_base {

  Clock* Clock::RealClock() {
    return nullptr;
  }

  SimulatedClock::SimulatedClock(absl::Time t) : now_(t) {}

  absl::Time SimulatedClock::TimeNow() {
    absl::Time v;
    return v;
  }

  void SimulatedClock::SetTime(absl::Time t) ABSL_NO_THREAD_SAFETY_ANALYSIS {
  }

  void SimulatedClock::AdvanceTime(absl::Duration d) ABSL_NO_THREAD_SAFETY_ANALYSIS {
  }

  template <class T>
  void SimulatedClock::UpdateTime(const T& now_updater) {
  }

}
#endif

#include "go-zetasql/base/base/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"
#include "go-absl/time/time/export.inc"

#endif
