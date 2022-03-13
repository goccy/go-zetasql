void GO_EXPORT(FormatSql)(void * arg0,void ** arg1,void ** arg2)
{
  std::string out;
  absl::Status ret = zetasql::FormatSql((char *)arg0, &out);
  *arg1 = (void *)((new std::string(out))->c_str());
  *arg2 = (void *)(new absl::Status(ret));
}
