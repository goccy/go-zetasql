#ifndef ZETASQL_COMMON_SIMPLE_EVALUATOR_TABLE_ITERATOR_EXPORT_H
#define ZETASQL_COMMON_SIMPLE_EVALUATOR_TABLE_ITERATOR_EXPORT_H

#include "zetasql/common/simple_evaluator_table_iterator.h"
#include "zetasql/common/simple_evaluator_table_iterator.cc"

#if 0
namespace zetasql {

  absl::Status SimpleEvaluatorTableIterator::SetColumnFilterMap(absl::flat_hash_map<int, std::unique_ptr<ColumnFilter>> filter_map) {
    return absl::OkStatus();
  }

  bool SimpleEvaluatorTableIterator::NextRow() {
    return false;
  }

}
#endif

#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/clock/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/evaluator_table_iterator/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/synchronization/synchronization/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-absl/types/span/export.inc"

#endif
