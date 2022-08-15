#ifndef ABSL_TIME_INTERNAL_CCTZ_TIME_ZONE_EXPORT_H
#define ABSL_TIME_INTERNAL_CCTZ_TIME_ZONE_EXPORT_H

#include "absl/time/internal/cctz/include/cctz/time_zone.h"
#include "absl/time/internal/cctz/include/cctz/zone_info_source.h"

#include "absl/time/internal/cctz/src/time_zone_fixed.h"
#include "absl/time/internal/cctz/src/time_zone_if.h"
#include "absl/time/internal/cctz/src/time_zone_impl.h"
#include "absl/time/internal/cctz/src/time_zone_info.h"
#include "absl/time/internal/cctz/src/time_zone_libc.h"
#include "absl/time/internal/cctz/src/time_zone_posix.h"
#include "absl/time/internal/cctz/src/tzfile.h"
#include "_cgo_export.h"

namespace absl {
  namespace time_internal {
    namespace cctz {

      bool FixedOffsetFromName(const std::string& name, seconds* offset) {
        char v;
        GO_EXPORT(cctz_FixedOffsetFromName)((void *)name.c_str(), (void *)offset, &v);
        return (bool)v;
      }

      std::string FixedOffsetToName(const seconds& offset) {
        void *v = nullptr;
        GO_EXPORT(cctz_FixedOffsetToName)((void *)&offset, &v);
        return std::string((char *)v);
      }
      
      std::string FixedOffsetToAbbr(const seconds& offset) {
        void *v = nullptr;
        GO_EXPORT(cctz_FixedOffsetToAbbr)((void *)&offset, &v);
        return std::string((char *)v);
      }
    
    }
  }
}

namespace absl {
  namespace time_internal {
    namespace cctz {
      namespace detail {

        std::string format(const std::string& format, const time_point<seconds>& tp, const detail::femtoseconds& fs, const time_zone& tz) {
          void *v = nullptr;
          GO_EXPORT(cctz_detail_format)((void *)format.c_str(), (void *)&tp, (void *)&fs, (void *)&tz, &v);
          return std::string((char *)v);
        }

        bool parse(const std::string& format, const std::string& input, const time_zone& tz, time_point<seconds>* sec, detail::femtoseconds* fs, std::string* err) {
          char v;
          GO_EXPORT(cctz_detail_parse)((void *)format.c_str(), (void *)input.c_str(), (void *)&tz, (void *)sec, (void *)fs, (void *)err, &v);
          return (bool)v;
        }

      }
    }
  }
}

namespace absl {
  namespace time_internal {
    namespace cctz {

      std::unique_ptr<TimeZoneIf> TimeZoneIf::Load(const std::string& name) {
        void *v;
        GO_EXPORT(TimeZoneIf_Load)((void *)name.c_str(), &v);
        std::unique_ptr<TimeZoneIf> ret((TimeZoneIf *)v);
        return ret;
      }

      TimeZoneIf::~TimeZoneIf() {
      }

    }
  }
}

namespace absl {
  namespace time_internal {
    namespace cctz {

      time_zone time_zone::Impl::UTC() {
        void *v = nullptr;
        GO_EXPORT(time_zone_Impl_UTC)(&v);
        return *(time_zone *)v;
      }

      bool time_zone::Impl::LoadTimeZone(const std::string& name, time_zone* tz) {
        char v;
        GO_EXPORT(time_zone_Impl_LoadTimeZone)((void *)name.c_str(), (void *)tz, &v);
        return (bool)v;
      }

      void time_zone::Impl::ClearTimeZoneMapTestOnly() {
        GO_EXPORT(time_zone_Impl_ClearTimeZoneMapTestOnly)();
      }

      time_zone::Impl::Impl(const std::string& name)
        : name_(name), zone_(TimeZoneIf::Load(name_)) {}

      const time_zone::Impl* time_zone::Impl::UTCImpl() {
        void *v = nullptr;
        GO_EXPORT(time_zone_Impl_UTCImpl)(&v);
        return (time_zone::Impl *)v;
      }

    }
  }
}

namespace absl {
  namespace time_internal {
    namespace cctz {

      bool TimeZoneInfo::Load(const std::string& name) {
        char v;
        GO_EXPORT(TimeZoneInfo_Load)((void *)this, (void *)name.c_str(), &v);
        return (bool)v;
      }

      time_zone::absolute_lookup TimeZoneInfo::BreakTime(const time_point<seconds>& tp) const {
        void *v = nullptr;
        GO_EXPORT(TimeZoneInfo_BreakTime)((void *)this, (void *)&tp, &v);
        return *(time_zone::absolute_lookup *)v;
      }

      time_zone::civil_lookup TimeZoneInfo::MakeTime(const civil_second& cs) const {
        void *v = nullptr;
        GO_EXPORT(TimeZoneInfo_MakeTime)((void *)this, (void *)&cs, &v);
        return *(time_zone::civil_lookup *)v;
      }

      std::string TimeZoneInfo::Version() const {
        void *v = nullptr;
        GO_EXPORT(TimeZoneInfo_Version)((void *)this, &v);
        return std::string((char *)v);
      }

      std::string TimeZoneInfo::Description() const {
        void *v = nullptr;
        GO_EXPORT(TimeZoneInfo_Description)((void *)this, &v);
        return std::string((char *)v);
      }

      bool TimeZoneInfo::NextTransition(const time_point<seconds>& tp, time_zone::civil_transition* trans) const {
        char v;
        GO_EXPORT(TimeZoneInfo_NextTransition)((void *)this, (void *)&tp, (void *)trans, &v);
        return (bool)v;
      }

      bool TimeZoneInfo::PrevTransition(const time_point<seconds>& tp, time_zone::civil_transition* trans) const {
        char v;
        GO_EXPORT(TimeZoneInfo_PrevTransition)((void *)this, (void *)&tp, (void *)trans, &v);
        return (bool)v;
      }

    }
  }
}

namespace absl {
  namespace time_internal {
    namespace cctz {

      TimeZoneLibC::TimeZoneLibC(const std::string& name)
        : local_(name == "localtime") {}

      time_zone::absolute_lookup TimeZoneLibC::BreakTime(const time_point<seconds>& tp) const {
        void *v = nullptr;
        GO_EXPORT(TimeZoneLibC_BreakTime)((void *)this, (void *)&tp, &v);
        return *(time_zone::absolute_lookup *)v;
      }

      time_zone::civil_lookup TimeZoneLibC::MakeTime(const civil_second& cs) const {
        void *v = nullptr;
        GO_EXPORT(TimeZoneLibC_MakeTime)((void *)this, (void *)&cs, &v);
        return *(time_zone::civil_lookup *)v;
      }

      bool TimeZoneLibC::NextTransition(const time_point<seconds>& a0, time_zone::civil_transition* a1) const {
        char v;
        GO_EXPORT(TimeZoneLibC_NextTransition)((void *)this, (void *)&a0, (void *)a1, &v);
        return (bool)v;
      }

      bool TimeZoneLibC::PrevTransition(const time_point<seconds>& a0, time_zone::civil_transition* a1) const {
        char v;
        GO_EXPORT(TimeZoneLibC_PrevTransition)((void *)this, (void *)&a0, (void *)a1, &v);
        return (bool)v;
      }

      std::string TimeZoneLibC::Version() const {
        void *v = nullptr;
        GO_EXPORT(TimeZoneLibC_Version)((void *)this, &v);
        return std::string((char *)v);
      }

      std::string TimeZoneLibC::Description() const {
        return local_ ? "localtime" : "UTC";
      }
    }
  }
}

namespace absl {
  namespace time_internal {
    namespace cctz {

      std::string time_zone::name() const {
        void *v = nullptr;
        GO_EXPORT(time_zone_name)(&v);
        return std::string((char *)v);
      }

      time_zone::absolute_lookup time_zone::lookup(const time_point<seconds>& tp) const {
        void *v = nullptr;
        GO_EXPORT(time_zone_lookup)((void *)this, (void *)&tp, &v);
        return *(time_zone::absolute_lookup *)v;
      }

      time_zone::civil_lookup time_zone::lookup(const civil_second& cs) const {
        void *v = nullptr;
        GO_EXPORT(time_zone_lookup2)((void *)this, (void *)&cs, &v);
        return *(time_zone::civil_lookup *)v;
      }

      bool time_zone::next_transition(const time_point<seconds>& tp, civil_transition* trans) const {
        char v;
        GO_EXPORT(time_zone_next_transition)((void *)&tp, (void *)trans, &v);
        return (bool)v;
      }

      bool time_zone::prev_transition(const time_point<seconds>& tp, civil_transition* trans) const {
        char v;
        GO_EXPORT(time_zone_prev_transition)((void *)&tp, (void *)trans, &v);
        return (bool)v;
      }

      std::string time_zone::version() const {
        void *v = nullptr;
        GO_EXPORT(time_zone_version)((void *)this, &v);
        return std::string((char *)v);
      }

      std::string time_zone::description() const {
        void *v = nullptr;
        GO_EXPORT(time_zone_description)((void *)this, &v);
        return std::string((char *)v);
      }

      const time_zone::Impl& time_zone::effective_impl() const {
        return *impl_;
      }

      bool load_time_zone(const std::string& name, time_zone* tz) {
        char v;
        GO_EXPORT(cctz_load_time_zone)((void *)name.c_str(), (void *)tz, &v);
        return (bool)v;
      }

      time_zone utc_time_zone() {
        void *v = nullptr;
        GO_EXPORT(cctz_utc_time_zone)(&v);
        return *(time_zone *)v;
      }

      time_zone fixed_time_zone(const seconds& offset) {
        void *v = nullptr;
        GO_EXPORT(cctz_fixed_time_zone)((void *)&offset, &v);
        return *(time_zone *)v;
      }

      time_zone local_time_zone() {
        void *v = nullptr;
        GO_EXPORT(cctz_local_time_zone)(&v);
        return *(time_zone *)v;
      }

    }
  }
}

namespace absl {
  namespace time_internal {
    namespace cctz {

      bool ParsePosixSpec(const std::string& spec, PosixTimeZone* res) {
        char v;
        GO_EXPORT(cctz_ParsePosixSpec)((void *)spec.c_str(), (void *)res, &v);
        return (bool)v;
      }

    }
  }
}

namespace absl {
  namespace time_internal {
    namespace cctz_extension {
      ZoneInfoSourceFactory zone_info_source_factory;
    }
  }
}

#include "go-absl/base/config/export.inc"
#include "go-absl/time/go_internal/cctz/civil_time/export.inc"

#endif
