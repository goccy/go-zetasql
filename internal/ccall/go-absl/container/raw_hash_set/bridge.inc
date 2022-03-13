#if 0
void GO_EXPORT(ShouldInsertBackwards)(size_t arg0,GO_EXPORT(ctrl_t) arg1,int* arg2)
{
  absl::container_internal::ctrl_t *a1 = (absl::container_internal::ctrl_t *)arg1.ptr;
  bool ret = absl::container_internal::ShouldInsertBackwards(arg0, a1);
  if (ret) {
    *arg2 = 1;
  } else {
    *arg2 = 0;
  }
}

void GO_EXPORT(ConvertDeletedToEmptyAndFullToDeleted)(GO_EXPORT(ctrl_t) arg0,size_t arg1)
{
  absl::container_internal::ctrl_t *a0 = (absl::container_internal::ctrl_t *)arg0.ptr;
  absl::container_internal::ConvertDeletedToEmptyAndFullToDeleted(a0, arg1);
}
#endif
