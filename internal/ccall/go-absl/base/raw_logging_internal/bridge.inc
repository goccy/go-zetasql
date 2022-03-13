#if 0
void GO_EXPORT(SafeWriteToStderr)(char * arg0,size_t arg1)
{
  absl::raw_logging_internal::SafeWriteToStderr(arg0, arg1);
}

void GO_EXPORT(RawLog)(GO_EXPORT(LogSeverity) arg0, char * arg1,int arg2, char * arg3)
{

}

void GO_EXPORT(RawLoggingFullySupported)(int* arg0)
{
  bool ret = absl::raw_logging_internal::RawLoggingFullySupported();
  if (ret) {
    *arg0 = 1;
  } else {
    *arg0 = 0;
  }
}

void GO_EXPORT(RegisterLogPrefixHook)(GO_EXPORT(LogPrefixHook) arg0)
{
  absl::raw_logging_internal::LogPrefixHook *a0 = (absl::raw_logging_internal::LogPrefixHook *)arg0.ptr;
  if (a0 != nullptr) {
    absl::raw_logging_internal::RegisterLogPrefixHook(*a0);
  } else {
    absl::raw_logging_internal::LogPrefixHook v;
    absl::raw_logging_internal::RegisterLogPrefixHook(v);
  }
}

void GO_EXPORT(RegisterAbortHook)(GO_EXPORT(AbortHook) arg0)
{
  absl::raw_logging_internal::AbortHook *a0 = (absl::raw_logging_internal::AbortHook *)arg0.ptr;
  if (a0 != nullptr) {
    absl::raw_logging_internal::RegisterAbortHook(*a0);
  } else {
    absl::raw_logging_internal::AbortHook v;
    absl::raw_logging_internal::RegisterAbortHook(v);
  }
}

void GO_EXPORT(RegisterInternalLogFunction)(GO_EXPORT(InternalLogFunction) arg0)
{
  absl::raw_logging_internal::InternalLogFunction *a0 = (absl::raw_logging_internal::InternalLogFunction *)arg0.ptr;
  if (a0 != nullptr) {
    absl::raw_logging_internal::RegisterInternalLogFunction(*a0);
  } else {
    absl::raw_logging_internal::InternalLogFunction v;
    absl::raw_logging_internal::RegisterInternalLogFunction(v);
  }
}
#endif
