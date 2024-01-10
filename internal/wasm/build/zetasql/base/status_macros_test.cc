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

#include "zetasql/base/status_macros.h"

#include <memory>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "absl/memory/memory.h"
#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "absl/strings/string_view.h"
#include "zetasql/base/source_location.h"
#include "zetasql/base/status_builder.h"

namespace {

using ::testing::AllOf;
using ::testing::HasSubstr;
using ::testing::Eq;

absl::Status ReturnOk() { return absl::OkStatus(); }

zetasql_base::StatusBuilder ReturnOkBuilder() {
  return zetasql_base::StatusBuilder(absl::OkStatus(), ZETASQL_LOC);
}

absl::Status ReturnError(absl::string_view msg) {
  return absl::Status(absl::StatusCode::kUnknown, msg);
}

zetasql_base::StatusBuilder ReturnErrorBuilder(absl::string_view msg) {
  return zetasql_base::StatusBuilder(
      absl::Status(absl::StatusCode::kUnknown, msg), ZETASQL_LOC);
}

absl::StatusOr<int> ReturnStatusOrValue(int v) { return v; }

absl::StatusOr<int> ReturnStatusOrError(absl::string_view msg) {
  return absl::Status(absl::StatusCode::kUnknown, msg);
}

absl::StatusOr<std::unique_ptr<int>> ReturnStatusOrPtrValue(int v) {
  return absl::make_unique<int>(v);
}

TEST(AssignOrReturn, Works) {
  auto func = []() -> absl::Status {
    ZETASQL_ASSIGN_OR_RETURN(int value1, ReturnStatusOrValue(1));
    EXPECT_EQ(1, value1);
    ZETASQL_ASSIGN_OR_RETURN(const int value2, ReturnStatusOrValue(2));
    EXPECT_EQ(2, value2);
    ZETASQL_ASSIGN_OR_RETURN(const int& value3, ReturnStatusOrValue(3));
    EXPECT_EQ(3, value3);
    ZETASQL_ASSIGN_OR_RETURN(ABSL_ATTRIBUTE_UNUSED int value4,
                             ReturnStatusOrError("EXPECTED"));
    return ReturnError("ERROR");
  };

  EXPECT_THAT(func().message(), Eq("EXPECTED"));
}

TEST(AssignOrReturn, WorksWithAppend) {
  auto fail_test_if_called = []() -> std::string {
    ADD_FAILURE();
    return "FAILURE";
  };
  auto func = [&]() -> absl::Status {
    ABSL_ATTRIBUTE_UNUSED int value;
    ZETASQL_ASSIGN_OR_RETURN(value, ReturnStatusOrValue(1),
                             _ << fail_test_if_called());
    ZETASQL_ASSIGN_OR_RETURN(value, ReturnStatusOrError("EXPECTED A"),
                             _ << "EXPECTED B");
    return ReturnOk();
  };

  EXPECT_THAT(func().message(),
              AllOf(HasSubstr("EXPECTED A"), HasSubstr("EXPECTED B")));
}

TEST(AssignOrReturn, WorksWithAdaptorFunc) {
  auto fail_test_if_called = [](zetasql_base::StatusBuilder builder) {
    ADD_FAILURE();
    return builder;
  };
  auto adaptor = [](zetasql_base::StatusBuilder builder) {
    return builder << "EXPECTED B";
  };
  auto func = [&]() -> absl::Status {
    ABSL_ATTRIBUTE_UNUSED int value;
    ZETASQL_ASSIGN_OR_RETURN(value, ReturnStatusOrValue(1),
                             fail_test_if_called(_));
    ZETASQL_ASSIGN_OR_RETURN(value, ReturnStatusOrError("EXPECTED A"),
                             adaptor(_));
    return ReturnOk();
  };

  EXPECT_THAT(func().message(),
              AllOf(HasSubstr("EXPECTED A"), HasSubstr("EXPECTED B")));
}

TEST(AssignOrReturn, WorksWithAppendIncludingLocals) {
  auto func = [&](const std::string& str) -> absl::Status {
    ABSL_ATTRIBUTE_UNUSED int value;
    ZETASQL_ASSIGN_OR_RETURN(value, ReturnStatusOrError("EXPECTED A"),
                             _ << str);
    return ReturnOk();
  };

  EXPECT_THAT(func("EXPECTED B").message(),
              AllOf(HasSubstr("EXPECTED A"), HasSubstr("EXPECTED B")));
}

TEST(AssignOrReturn, WorksForExistingVariable) {
  auto func = []() -> absl::Status {
    int value = 1;
    ZETASQL_ASSIGN_OR_RETURN(value, ReturnStatusOrValue(2));
    EXPECT_EQ(2, value);
    ZETASQL_ASSIGN_OR_RETURN(value, ReturnStatusOrValue(3));
    EXPECT_EQ(3, value);
    ZETASQL_ASSIGN_OR_RETURN(value, ReturnStatusOrError("EXPECTED"));
    return ReturnError("ERROR");
  };

  EXPECT_THAT(func().message(), Eq("EXPECTED"));
}

TEST(AssignOrReturn, UniquePtrWorks) {
  auto func = []() -> absl::Status {
    ZETASQL_ASSIGN_OR_RETURN(std::unique_ptr<int> ptr,
                             ReturnStatusOrPtrValue(1));
    EXPECT_EQ(*ptr, 1);
    return ReturnError("EXPECTED");
  };

  EXPECT_THAT(func().message(), Eq("EXPECTED"));
}

TEST(AssignOrReturn, UniquePtrWorksForExistingVariable) {
  auto func = []() -> absl::Status {
    std::unique_ptr<int> ptr;
    ZETASQL_ASSIGN_OR_RETURN(ptr, ReturnStatusOrPtrValue(1));
    EXPECT_EQ(*ptr, 1);

    ZETASQL_ASSIGN_OR_RETURN(ptr, ReturnStatusOrPtrValue(2));
    EXPECT_EQ(*ptr, 2);
    return ReturnError("EXPECTED");
  };

  EXPECT_THAT(func().message(), Eq("EXPECTED"));
}

TEST(ReturnIfError, Works) {
  auto func = []() -> absl::Status {
    ZETASQL_RETURN_IF_ERROR(ReturnOk());
    ZETASQL_RETURN_IF_ERROR(ReturnOk());
    ZETASQL_RETURN_IF_ERROR(ReturnError("EXPECTED"));
    return ReturnError("ERROR");
  };

  EXPECT_THAT(func().message(), Eq("EXPECTED"));
}

TEST(ReturnIfError, WorksWithBuilder) {
  auto func = []() -> absl::Status {
    ZETASQL_RETURN_IF_ERROR(ReturnOkBuilder());
    ZETASQL_RETURN_IF_ERROR(ReturnOkBuilder());
    ZETASQL_RETURN_IF_ERROR(ReturnErrorBuilder("EXPECTED"));
    return ReturnErrorBuilder("ERROR");
  };

  EXPECT_THAT(func().message(), Eq("EXPECTED"));
}

TEST(ReturnIfError, WorksWithLambda) {
  auto func = []() -> absl::Status {
    ZETASQL_RETURN_IF_ERROR([] { return ReturnOk(); }());
    ZETASQL_RETURN_IF_ERROR([] { return ReturnError("EXPECTED"); }());
    return ReturnError("ERROR");
  };

  EXPECT_THAT(func().message(), Eq("EXPECTED"));
}

TEST(ReturnIfError, WorksWithAppend) {
  auto fail_test_if_called = []() -> std::string {
    ADD_FAILURE();
    return "FAILURE";
  };
  auto func = [&]() -> absl::Status {
    ZETASQL_RETURN_IF_ERROR(ReturnOk()) << fail_test_if_called();
    ZETASQL_RETURN_IF_ERROR(ReturnError("EXPECTED A")) << "EXPECTED B";
    return absl::OkStatus();
  };

  EXPECT_THAT(func().message(),
              AllOf(HasSubstr("EXPECTED A"), HasSubstr("EXPECTED B")));
}

}  // namespace
