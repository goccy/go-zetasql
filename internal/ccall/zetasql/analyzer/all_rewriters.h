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

#ifndef ZETASQL_ANALYZER_ALL_REWRITERS_H_
#define ZETASQL_ANALYZER_ALL_REWRITERS_H_

#include <vector>

#include "zetasql/analyzer/rewriters/rewriter_interface.h"

namespace zetasql {

// Returns a vector of the built-in Rewriter objects to be used for rewrites
// in ZetaSQL. Does not pass ownership of the returned pointers.
const std::vector<const Rewriter*>& AllRewriters();

// Registers the built-in rewriters with the global RewriteRegistry.
// After the first call, takes no action.
void RegisterBuiltinRewriters();

}  // namespace zetasql

#endif  // ZETASQL_ANALYZER_ALL_REWRITERS_H_
