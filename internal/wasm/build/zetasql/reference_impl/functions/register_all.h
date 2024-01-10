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

#ifndef ZETASQL_REFERENCE_IMPL_FUNCTIONS_REGISTER_ALL_H_
#define ZETASQL_REFERENCE_IMPL_FUNCTIONS_REGISTER_ALL_H_

// Please see ../public/evaluator_lite.h for usage instructions.

namespace zetasql {

// Registers builtin functions from all optional modules. Refer to each module's
// header file in this directory for the list of individual functions that it
// includes.
//
// Registration only needs to be done once, before any usage of
// PreparedExpressionLite/PreparedQueryLite. Thread safe.
void RegisterAllOptionalBuiltinFunctions();

}  // namespace zetasql

#endif  // ZETASQL_REFERENCE_IMPL_FUNCTIONS_REGISTER_ALL_H_
