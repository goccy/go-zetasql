#ifndef ZETASQL_PUBLIC_INTERVAL_VALUE_EXPORT_H
#define ZETASQL_PUBLIC_INTERVAL_VALUE_EXPORT_H

#include "zetasql/public/interval_value.h"
#include "re2/re2.h"

#include "zetasql/public/interval_value.cc"

#if 0
namespace zetasql {

  absl::StatusOr<IntervalValue> IntervalValue::FromYMDHMS(int64_t years, int64_t months, int64_t days, int64_t hours, int64_t minutes, int64_t seconds) {
    IntervalValue v;
    return v;
  }

  size_t IntervalValue::HashCode() const {
    return 0;
  }

  absl::StatusOr<IntervalValue> IntervalValue::operator*(int64_t value) const {
    IntervalValue v;
    return v;
  }

  absl::StatusOr<IntervalValue> IntervalValue::operator/(int64_t value) const {
    IntervalValue v;
    return v;
  }

  void IntervalValue::SumAggregator::Add(IntervalValue value) {
  }

  absl::StatusOr<IntervalValue> IntervalValue::SumAggregator::GetSum() const {
    IntervalValue v;
    return v;
  }

  absl::StatusOr<IntervalValue> IntervalValue::SumAggregator::GetAverage(int64_t count) const {
    IntervalValue v;
    return v;
  }

  std::string IntervalValue::SumAggregator::SerializeAsProtoBytes() const {
    return "";
  }

  void IntervalValue::SumAggregator::SerializeAndAppendToProtoBytes(std::string* bytes) const {
  }

  absl::StatusOr<IntervalValue::SumAggregator> IntervalValue::SumAggregator::DeserializeFromProtoBytes(absl::string_view bytes) {
    IntervalValue::SumAggregator v;
    return v;
  }

  std::string IntervalValue::SumAggregator::DebugString() const {
    return "";
  }

  void IntervalValue::SumAggregator::MergeWith(const SumAggregator& other) {
  }

  void IntervalValue::SerializeAndAppendToBytes(std::string* bytes) const {
  }

  absl::StatusOr<IntervalValue> IntervalValue::DeserializeFromBytes(absl::string_view bytes) {
    IntervalValue v;
    return v;
  }

  std::string IntervalValue::ToString() const {
    return "";
  }

  std::string IntervalValue::ToISO8601() const {
    return "";
  }

  absl::StatusOr<int64_t> NanosFromFractionDigits(absl::string_view input,
                                                  absl::string_view digits) {
    return 0;
  }

  const LazyRE2 kRESecond = {R"(([-+])?(\d*)\.(\d+))"};

  absl::StatusOr<IntervalValue> IntervalValue::ParseFromString(absl::string_view input, functions::DateTimestampPart part) {
    IntervalValue v;
    return v;
  }

  const LazyRE2 kREYearToMonth = {R"(([-+])?(\d+)-(\d+))"};
  const LazyRE2 kREYearToDay = {R"(([-+])?(\d+)-(\d+) ([-+]?\d+))"};
  const LazyRE2 kREYearToHour = {R"(([-+])?(\d+)-(\d+) ([-+]?\d+) ([-+])?(\d+))"};
  const LazyRE2 kREYearToMinute = {
                                   R"(([-+])?(\d+)-(\d+) ([-+]?\d+) ([-+])?(\d+):(\d+))"};
  const LazyRE2 kREYearToSecond = {
                                   R"(([-+])?(\d+)-(\d+) ([-+]?\d+) ([-+])?(\d+):(\d+):(\d+))"};
  const LazyRE2 kREYearToSecondFractions = {
                                            R"(([-+])?(\d+)-(\d+) ([-+]?\d+) ([-+])?(\d+):(\d+):(\d+)\.(\d+))"};

  const LazyRE2 kREMonthToDay = {R"(([-+])?(\d+) ([-+]?\d+))"};
  const LazyRE2 kREMonthToHour = {R"(([-+])?(\d+) ([-+]?\d+) ([-+])?(\d+))"};
  const LazyRE2 kREMonthToMinute = {
                                    R"(([-+])?(\d+) ([-+]?\d+) ([-+])?(\d+):(\d+))"};
  const LazyRE2 kREMonthToSecond = {
                                    R"(([-+])?(\d+) ([-+]?\d+) ([-+])?(\d+):(\d+):(\d+))"};
  const LazyRE2 kREMonthToSecondFractions = {
                                             R"(([-+])?(\d+) ([-+]?\d+) ([-+])?(\d+):(\d+):(\d+)\.(\d+))"};

  const LazyRE2 kREDayToHour = {R"(([-+]?\d+) ([-+])?(\d+))"};
  const LazyRE2 kREDayToMinute = {R"(([-+]?\d+) ([-+])?(\d+):(\d+))"};
  const LazyRE2 kREDayToSecond = {R"(([-+]?\d+) ([-+])?(\d+):(\d+):(\d+))"};
  const LazyRE2 kREDayToSecondFractions = {
                                           R"(([-+]?\d+) ([-+])?(\d+):(\d+):(\d+)\.(\d+))"};

  const LazyRE2 kREHourToMinute = {R"(([-+])?(\d+):(\d+))"};
  const LazyRE2 kREHourToSecond = {R"(([-+])?(\d+):(\d+):(\d+))"};
  const LazyRE2 kREHourToSecondFractions = {R"(([-+])?(\d+):(\d+):(\d+)\.(\d+))"};

  const LazyRE2 kREMinuteToSecond = {R"(([-+])?(\d+):(\d+))"};
  const LazyRE2 kREMinuteToSecondFractions = {R"(([-+])?(\d+):(\d+)\.(\d+))"};

  absl::StatusOr<IntervalValue> IntervalValue::ParseFromString(absl::string_view input, functions::DateTimestampPart from,
                                                               functions::DateTimestampPart to) {
    IntervalValue v;
    return v;
  }

  absl::StatusOr<IntervalValue> IntervalValue::ParseFromString(absl::string_view input) {
    IntervalValue v;
    return v;
  }

  absl::StatusOr<IntervalValue> IntervalValue::ParseFromISO8601(absl::string_view input) {
    IntervalValue v;
    return v;
  }

  absl::StatusOr<IntervalValue> IntervalValue::Parse(absl::string_view input) {
    IntervalValue v;
    return v;
  }

  absl::StatusOr<IntervalValue> IntervalValue::FromInteger(int64_t value, functions::DateTimestampPart part) {
    IntervalValue v;
    return v;
  }

  absl::StatusOr<int64_t> IntervalValue::Extract(functions::DateTimestampPart part) const {
    return 0;
  }

  std::ostream& operator<<(std::ostream& out, IntervalValue value) {
    return out;
  }

  absl::StatusOr<IntervalValue> JustifyHours(const IntervalValue& v) {
    IntervalValue r;
    return r;
  }

  absl::StatusOr<IntervalValue> JustifyDays(const IntervalValue& v) {
    IntervalValue r;
    return r;
  }

  absl::StatusOr<IntervalValue> JustifyInterval(const IntervalValue& v) {
    IntervalValue r;
    return r;
  }

}
#endif

#include "go-zetasql/base/endian/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/multiprecision_int/export.inc"
#include "go-zetasql/public/functions/arithmetics/export.inc"
#include "go-zetasql/public/functions/datetime_cc_proto/export.inc"

#include "go-absl/base/base/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/hash/hash/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-re2/re2/export.inc"

#endif
