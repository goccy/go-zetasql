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

#include "zetasql/base/simple_reference_counted.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::Eq;

namespace zetasql_base {

// Test class that counts dtor and OnRefCountIsZero() invocations and exposes
// ref_count().
class TestRefCounted : public SimpleReferenceCounted {
 public:
  TestRefCounted(int* destructor_counter, int* final_unref_count)
      : destruct_count_(destructor_counter),
        final_unref_count_(final_unref_count) {}

  ~TestRefCounted() override {
    if (destruct_count_) ++*destruct_count_;
  }

  void OnRefCountIsZero() const override {
    if (final_unref_count_) ++*final_unref_count_;
    SimpleReferenceCounted::OnRefCountIsZero();
  }

  size_t ref_count() const { return SimpleReferenceCounted::ref_count(); }

 private:
  int* const destruct_count_;
  int* const final_unref_count_;
};

// Tests simple creation, Unref() and public observable state.
TEST(SimpleReferenceCounted, Create) {
  SimpleReferenceCounted* rc = new SimpleReferenceCounted();
  EXPECT_TRUE(rc->RefCountIsOne());
  rc->Unref();
}

// Tests Ref(), Unref(), reference counts and OnRefCountIsZero / Dtor
// invocations.
TEST(SimpleReferenceCounted, RefUnrefAndRefCount) {
  int destruct_count = 0;
  int finalize_count = 0;
  TestRefCounted* rc = new TestRefCounted(&destruct_count, &finalize_count);
  EXPECT_TRUE(rc->RefCountIsOne());
  EXPECT_THAT(rc->ref_count(), Eq(1));

  rc->Ref();
  EXPECT_FALSE(rc->RefCountIsOne());
  EXPECT_THAT(rc->ref_count(), Eq(2));

  rc->Unref();
  EXPECT_TRUE(rc->RefCountIsOne());
  EXPECT_THAT(rc->ref_count(), Eq(1));

  EXPECT_THAT(destruct_count, Eq(0));
  EXPECT_THAT(finalize_count, Eq(0));

  rc->Unref();
  EXPECT_THAT(destruct_count, Eq(1));
  EXPECT_THAT(finalize_count, Eq(1));
}

// Test class that counts dtor and OnRefCountIsZero invocations, exposes
// ref_count(), and consumes the first 8 OnRefCountIsZero() calls before calling
// the default OnRefCountIsZero() on the 9th call.
class NineLives : public SimpleReferenceCounted {
 public:
  NineLives(int* destructor_counter, int* final_unref_count)
      : destruct_count_(destructor_counter),
        final_unref_count_(final_unref_count) {}

  ~NineLives() override {
    if (destruct_count_) ++*destruct_count_;
  }

  void OnRefCountIsZero() const override {
    if (final_unref_count_) ++*final_unref_count_;
    if (--const_cast<NineLives*>(this)->lives_ == 0) {
      SimpleReferenceCounted::OnRefCountIsZero();
    }
  }

  size_t ref_count() const { return SimpleReferenceCounted::ref_count(); }

 private:
  int* const destruct_count_;
  int* const final_unref_count_;
  int lives_{9};
};

// Tests OnRefCountIsZero() overrides and overrules finalization behavior.
TEST(SimpleReferenceCounted, NineLives) {
  int destruct_count = 0;
  int finalize_count = 0;
  NineLives* rc = new NineLives(&destruct_count, &finalize_count);
  for (int i = 1; i <= 8; ++i) {
    EXPECT_TRUE(rc->RefCountIsOne());
    EXPECT_THAT(rc->ref_count(), Eq(1));
    rc->Unref();
    EXPECT_THAT(rc->ref_count(), Eq(0));
    EXPECT_THAT(destruct_count, Eq(0));
    EXPECT_THAT(finalize_count, Eq(i));
    rc->Ref();  // Raise from the death.
  }
  rc->Unref();
  EXPECT_THAT(destruct_count, Eq(1));
  EXPECT_THAT(finalize_count, Eq(9));
}

}  // namespace zetasql_base
