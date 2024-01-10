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

// This file declares cast functions between strings and numeric types.
// The following two functions are defined.
//
//   template <typename T>
//   bool NumericToString(T value, string* out, absl::Status* error);
//   template <typename T>
//   bool StringToNumeric(absl::string_view value, T* out, absl::Status* error);
//
// Here T must be one of the following seven types: bool, int32_t, int64_t, uint32_t,
// uint64_t, float, double.
// On error both functions return false and update *error.

#ifndef ZETASQL_PUBLIC_FUNCTIONS_CONVERT_STRING_H_
#define ZETASQL_PUBLIC_FUNCTIONS_CONVERT_STRING_H_

#include <cstdint>
#include <string>

#include "zetasql/public/numeric_value.h"
#include <cstdint>
#include "absl/strings/string_view.h"
#include "zetasql/base/status.h"

namespace zetasql {
namespace functions {

// Ensure a compile-time error (rather than link-time) for unsupported types.
template <typename T>
bool NumericToString(T value, std::string* out, absl::Status* error) = delete;

template <typename T>
bool NumericToString(T value, std::string* out, absl::Status* error);

// Ensure a compile-time error (rather than link-time) for unsupported types.
template <typename T>
bool StringToNumeric(absl::string_view value, T* out,
                     absl::Status* error) = delete;

template <typename T>
bool StringToNumeric(absl::string_view value, T* out, absl::Status* error);

template <>
bool NumericToString(bool value, std::string* out, absl::Status* error);
template <>
bool NumericToString(int32_t value, std::string* out, absl::Status* error);
template <>
bool NumericToString(int64_t value, std::string* out, absl::Status* error);
template <>
bool NumericToString(uint32_t value, std::string* out, absl::Status* error);
template <>
bool NumericToString(uint64_t value, std::string* out, absl::Status* error);
template <>
bool NumericToString(float value, std::string* out, absl::Status* error);
template <>
bool NumericToString(double value, std::string* out, absl::Status* error);
template <>
bool NumericToString(NumericValue value, std::string* out, absl::Status* error);
template <>
bool NumericToString(BigNumericValue value, std::string* out,
                     absl::Status* error);

template <>
bool StringToNumeric(absl::string_view value, bool* out, absl::Status* error);
template <>
bool StringToNumeric(absl::string_view value, int32_t* out,
                     absl::Status* error);
template <>
bool StringToNumeric(absl::string_view value, int64_t* out,
                     absl::Status* error);
template <>
bool StringToNumeric(absl::string_view value, uint32_t* out,
                     absl::Status* error);
template <>
bool StringToNumeric(absl::string_view value, uint64_t* out,
                     absl::Status* error);
template <>
bool StringToNumeric(absl::string_view value, float* out, absl::Status* error);
template <>
bool StringToNumeric(absl::string_view value, double* out, absl::Status* error);
template <>
bool StringToNumeric(absl::string_view value, NumericValue* out,
                     absl::Status* error);
template <>
bool StringToNumeric(absl::string_view value, BigNumericValue* out,
                     absl::Status* error);

}  // namespace functions
}  // namespace zetasql

#endif  // ZETASQL_PUBLIC_FUNCTIONS_CONVERT_STRING_H_
