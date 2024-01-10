//
// Copyright 2018 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef THIRD_PARTY_ZETASQL_ZETASQL_BASE_STATUS_H_
#define THIRD_PARTY_ZETASQL_ZETASQL_BASE_STATUS_H_

#include "absl/status/status.h"  
#include "absl/status/statusor.h"  

// This is better than ZETASQL_CHECK((val).ok()) because the embedded
// error string gets printed by the ZETASQL_CHECK_EQ.
#define ZETASQL_CHECK_OK(val) \
  ZETASQL_CHECK_EQ(::absl::OkStatus(), ::zetasql::status_internal::AsStatus((val)))
#define ZETASQL_DCHECK_OK(val) \
  ZETASQL_DCHECK_EQ(::absl::OkStatus(), ::zetasql::status_internal::AsStatus((val)))
#define ZETASQL_ZETASQL_CHECK_OK(val) \
  ZETASQL_DCHECK_EQ(::absl::OkStatus(), ::zetasql::status_internal::AsStatus((val)))

namespace zetasql::status_internal {

// Returns a Status or StatusOr as a Status.
// Only for use in template or macro code that must work with both Status and
// StatusOr.
template <typename T>
inline const absl::Status& AsStatus(const absl::StatusOr<T>& status_or) {
  return status_or.status();
}
inline const absl::Status& AsStatus(const absl::Status& status) {
  return status;
}

}  // namespace zetasql::status_internal

#endif  // THIRD_PARTY_ZETASQL_ZETASQL_BASE_STATUS_H_
