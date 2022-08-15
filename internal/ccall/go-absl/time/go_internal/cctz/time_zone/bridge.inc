void GO_EXPORT(cctz_FixedOffsetFromName)(void * arg0,void * arg1,char* arg2)
{
  *arg2 = absl::time_internal::cctz::FixedOffsetFromName((char *)arg0, (std::chrono::seconds *)arg1);
}

void GO_EXPORT(cctz_FixedOffsetToName)(void * arg0,void ** arg1)
{
  *arg1 = (void *)absl::time_internal::cctz::FixedOffsetToName(*(std::chrono::seconds *)arg0).c_str();
}

void GO_EXPORT(cctz_FixedOffsetToAbbr)(void * arg0,void ** arg1)
{
  *arg1 = (void *)absl::time_internal::cctz::FixedOffsetToAbbr(*(std::chrono::seconds *)arg0).c_str();
}

void GO_EXPORT(cctz_detail_format)(void * arg0,void * arg1,void * arg2,void * arg3,void ** arg4)
{
  *arg4 = (void *)((new std::string(absl::time_internal::cctz::detail::format(
    (char *)arg0,
    *(absl::time_internal::cctz::time_point<absl::time_internal::cctz::seconds> *)arg1,
    *(absl::time_internal::cctz::detail::femtoseconds *)arg2,
    *(absl::time_internal::cctz::time_zone *)arg3
  )))->c_str());
}

void GO_EXPORT(cctz_detail_parse)(void * arg0,void * arg1,void * arg2,void * arg3,void * arg4,void * arg5,char* arg6)
{
  fprintf(stderr, "[WARN] unimplemented cctz_detail_parse\n");
}

void GO_EXPORT(TimeZoneIf_Load)(void * arg0,void ** arg1)
{
  std::unique_ptr<absl::time_internal::cctz::TimeZoneIf> ret = absl::time_internal::cctz::TimeZoneIf::Load((char *)arg0);
  *(std::unique_ptr<absl::time_internal::cctz::TimeZoneIf> *)arg1 = std::move(ret);
}

void GO_EXPORT(time_zone_Impl_UTC)(void ** arg0)
{
  absl::time_internal::cctz::time_zone ret = absl::time_internal::cctz::time_zone::Impl::UTC();
  *arg0 = malloc(sizeof(absl::time_internal::cctz::time_zone));
  memcpy(*arg0, &ret, sizeof(absl::time_internal::cctz::time_zone));
}

void GO_EXPORT(time_zone_Impl_LoadTimeZone)(void * arg0,void * arg1,char* arg2)
{
  *arg2 = absl::time_internal::cctz::time_zone::Impl::LoadTimeZone((char *)arg0, (absl::time_internal::cctz::time_zone *)arg1);
}

void GO_EXPORT(time_zone_Impl_ClearTimeZoneMapTestOnly)()
{
  absl::time_internal::cctz::time_zone::Impl::ClearTimeZoneMapTestOnly();
}

void GO_EXPORT(time_zone_Impl_UTCImpl)(void ** arg0)
{
  fprintf(stderr, "[WARN] unimplemented time_zone::Impl::UTCImpl\n");
}

void GO_EXPORT(TimeZoneInfo_Load)(void * arg0,void * arg1,char* arg2)
{
  absl::time_internal::cctz::TimeZoneInfo *info = (absl::time_internal::cctz::TimeZoneInfo *)arg0;
  *arg2 = info->Load((char *)arg1);
}

void GO_EXPORT(TimeZoneInfo_BreakTime)(void * arg0,void * arg1,void ** arg2)
{
  absl::time_internal::cctz::TimeZoneInfo *info = (absl::time_internal::cctz::TimeZoneInfo *)arg0;
  std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> *tp = (std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> *)arg1;
  absl::time_internal::cctz::time_zone::absolute_lookup ret = info->BreakTime(*tp);
  *arg2 = malloc(sizeof(absl::time_internal::cctz::time_zone::absolute_lookup));
  memcpy(*arg2, &ret, sizeof(absl::time_internal::cctz::time_zone::absolute_lookup));
}

void GO_EXPORT(TimeZoneInfo_MakeTime)(void * arg0,void * arg1,void ** arg2)
{
  absl::time_internal::cctz::TimeZoneInfo *info = (absl::time_internal::cctz::TimeZoneInfo *)arg0;
  absl::time_internal::cctz::time_zone::civil_lookup ret = info->MakeTime(*(absl::time_internal::cctz::civil_second *)arg1);
  *arg2 = malloc(sizeof(absl::time_internal::cctz::time_zone::civil_lookup));
  memcpy(*arg2, &ret, sizeof(absl::time_internal::cctz::time_zone::civil_lookup));
}

void GO_EXPORT(TimeZoneInfo_Version)(void * arg0,void ** arg1)
{
  absl::time_internal::cctz::TimeZoneInfo *info = (absl::time_internal::cctz::TimeZoneInfo *)arg0;
  *arg1 = (void *)info->Version().c_str();
}

void GO_EXPORT(TimeZoneInfo_Description)(void * arg0,void ** arg1)
{
  absl::time_internal::cctz::TimeZoneInfo *info = (absl::time_internal::cctz::TimeZoneInfo *)arg0;
  *arg1 = (void *)info->Description().c_str();
}

void GO_EXPORT(TimeZoneInfo_NextTransition)(void * arg0,void * arg1,void * arg2,char* arg3)
{
  absl::time_internal::cctz::TimeZoneInfo *info = (absl::time_internal::cctz::TimeZoneInfo *)arg0;
  *arg3 = info->NextTransition(*(std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> *)arg1, (absl::time_internal::cctz::time_zone::civil_transition *)arg2);
}

void GO_EXPORT(TimeZoneInfo_PrevTransition)(void * arg0,void * arg1,void * arg2,char* arg3)
{
  absl::time_internal::cctz::TimeZoneInfo *info = (absl::time_internal::cctz::TimeZoneInfo *)arg0;
  *arg3 = info->PrevTransition(*(std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> *)arg1, (absl::time_internal::cctz::time_zone::civil_transition *)arg2);
}

void GO_EXPORT(TimeZoneLibC_BreakTime)(void * arg0,void * arg1,void ** arg2)
{
  fprintf(stderr, "[WARN] unimplemented TimeZoneLibC_BreakTime\n");
}

void GO_EXPORT(TimeZoneLibC_MakeTime)(void * arg0,void * arg1,void ** arg2)
{
  fprintf(stderr, "[WARN] unimplemented TimeZoneLibC_MakeTime\n");
}

void GO_EXPORT(TimeZoneLibC_Version)(void * arg0,void ** arg1)
{
  fprintf(stderr, "[WARN] unimplemented TimeZoneLibC_Version\n");
}

void GO_EXPORT(TimeZoneLibC_NextTransition)(void * arg0,void * arg1,void * arg2,char* arg3)
{
  fprintf(stderr, "[WARN] unimplemented TimeZoneLibC_NextTransition\n");
}

void GO_EXPORT(TimeZoneLibC_PrevTransition)(void * arg0,void * arg1,void * arg2,char* arg3)
{
  fprintf(stderr, "[WARN] unimplemented TimeZoneLibC_PrevTransition\n");
}

void GO_EXPORT(time_zone_name)(void ** arg0)
{
  fprintf(stderr, "[WARN] unimplemented time_zone_name\n");
}

void GO_EXPORT(time_zone_lookup)(void * arg0,void * arg1,void ** arg2)
{
  absl::time_internal::cctz::time_zone *zone = (absl::time_internal::cctz::time_zone *)arg0;
  *arg2 = (void *)(new absl::time_internal::cctz::time_zone::absolute_lookup(zone->lookup(*(absl::time_internal::cctz::time_point<absl::time_internal::cctz::seconds> *)arg1)));
}

void GO_EXPORT(time_zone_lookup2)(void * arg0,void * arg1,void ** arg2)
{
  absl::time_internal::cctz::time_zone *zone = (absl::time_internal::cctz::time_zone *)arg0;
  *arg2 = (void *)(new absl::time_internal::cctz::time_zone::civil_lookup(zone->lookup(*(absl::time_internal::cctz::civil_second *)arg1)));
}

void GO_EXPORT(time_zone_next_transition)(void * arg0,void * arg1,char* arg2)
{
  fprintf(stderr, "[WARN] unimplemented time_zone_next_transition\n");
}

void GO_EXPORT(time_zone_prev_transition)(void * arg0,void * arg1,char* arg2)
{
  fprintf(stderr, "[WARN] unimplemented time_zone_prev_transition\n");
}

void GO_EXPORT(time_zone_version)(void * arg0,void ** arg1)
{
  fprintf(stderr, "[WARN] unimplemented time_zone_version\n");
}

void GO_EXPORT(time_zone_description)(void * arg0,void ** arg1)
{
  fprintf(stderr, "[WARN] unimplemented time_zone_description\n");
}

void GO_EXPORT(cctz_load_time_zone)(void * arg0,void * arg1,char* arg2)
{
  *arg2 = absl::time_internal::cctz::load_time_zone((char *)arg0, (absl::time_internal::cctz::time_zone *)arg1);
}

void GO_EXPORT(cctz_utc_time_zone)(void ** arg0)
{
  *arg0 = malloc(sizeof(absl::time_internal::cctz::time_zone));
  absl::time_internal::cctz::time_zone ret = absl::time_internal::cctz::utc_time_zone();
  memcpy(*arg0, &ret, sizeof(absl::time_internal::cctz::time_zone));
}

void GO_EXPORT(cctz_fixed_time_zone)(void * arg0,void ** arg1)
{
  *arg1 = malloc(sizeof(absl::time_internal::cctz::time_zone));
  absl::time_internal::cctz::time_zone ret = absl::time_internal::cctz::fixed_time_zone(*(std::chrono::seconds *)arg0);
  memcpy(*arg1, &ret, sizeof(absl::time_internal::cctz::time_zone));
}

void GO_EXPORT(cctz_local_time_zone)(void ** arg0)
{
  *arg0 = malloc(sizeof(absl::time_internal::cctz::time_zone));
  absl::time_internal::cctz::time_zone ret = absl::time_internal::cctz::local_time_zone();
  memcpy(*arg0, &ret, sizeof(absl::time_internal::cctz::time_zone));
}

void GO_EXPORT(cctz_ParsePosixSpec)(void * arg0,void * arg1,char* arg2)
{
  fprintf(stderr, "[WARN] unimplemented cctz_ParsePosixSpec\n");
}
