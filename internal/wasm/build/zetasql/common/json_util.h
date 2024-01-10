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

#ifndef ZETASQL_COMMON_JSON_UTIL_H__
#define ZETASQL_COMMON_JSON_UTIL_H__

#include <string>

#include "absl/strings/string_view.h"

namespace zetasql {

// Escape the contents of `raw` in JSON style, and return the result in
// `value_string`.  This also adds double quotes to the beginning and end of
// the string. We can't use CEscape because it isn't entirely JSON compatible.
void JsonEscapeString(absl::string_view raw, std::string* value_string);

// Returns true iff JsonEscapeString(...) would have found any characters that
// need escaping in the given raw input string.
bool JsonStringNeedsEscaping(absl::string_view raw);

}  // namespace zetasql

#endif  // ZETASQL_COMMON_JSON_UTIL_H__
