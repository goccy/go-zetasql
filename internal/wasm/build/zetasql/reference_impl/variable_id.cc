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

#include "zetasql/reference_impl/variable_id.h"

#include <string>

#include "zetasql/base/logging.h"
#include "absl/strings/match.h"

namespace zetasql {

VariableId::VariableId(const std::string& name) : name_(name) {
  // Make sure we don't use certain special characters for ease of debugging.
  ZETASQL_DCHECK(!absl::StrContains(name, '$'));  // used in the resolved AST
  ZETASQL_DCHECK(!absl::StrContains(name, '@'));  // used for query parameters
}

std::ostream& operator<<(std::ostream& out, const VariableId& id) {
  return out << id.ToString();
}

}  // namespace zetasql
