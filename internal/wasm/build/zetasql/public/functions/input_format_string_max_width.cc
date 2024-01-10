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

#include "zetasql/public/functions/input_format_string_max_width.h"

#include "absl/flags/flag.h"

// TODO: Change references of zetasql_format_max_output_width to
// this new flag for ZetaSQL Cast functions with input format string.
ABSL_FLAG(int32_t, zetasql_cast_format_string_max_width, 1024 * 1024,
          "Maximum width of input format string for Cast functions. If a input"
          "format string has a wider value, it will fail at runtime.");
