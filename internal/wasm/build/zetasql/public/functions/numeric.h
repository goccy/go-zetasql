//
// Copyright 2019 Google LLC
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

#ifndef ZETASQL_PUBLIC_FUNCTIONS_NUMERIC_H_
#define ZETASQL_PUBLIC_FUNCTIONS_NUMERIC_H_

#include "zetasql/public/numeric_value.h"
#include "absl/status/status.h"
#include "absl/strings/string_view.h"

namespace zetasql {
namespace functions {

// PARSE_NUMERIC(STRING) -> NUMERIC
bool ParseNumeric(absl::string_view str, NumericValue* out,
                  absl::Status* error);

// PARSE_BIGNUMERIC(STRING) -> BIGNUMERIC
bool ParseBigNumeric(absl::string_view str, BigNumericValue* out,
                     absl::Status* error);

}  // namespace functions
}  // namespace zetasql

#endif  // ZETASQL_PUBLIC_FUNCTIONS_NUMERIC_H_
