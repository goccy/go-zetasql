void GO_EXPORT(AnalyzeStatement)(void * arg0,void * arg1,void ** arg2,void ** arg3)
{
  zetasql::AnalyzerOptions opt;
  std::unique_ptr<const zetasql::AnalyzerOutput> out;
  absl::Status ret = zetasql::AnalyzeStatement((char *)arg0, opt, (zetasql::Catalog *)arg1, nullptr, &out);
  *(std::unique_ptr<const zetasql::AnalyzerOutput> *)arg2 = std::move(out);
  *arg3 = (void *)(new absl::Status(ret));
}
