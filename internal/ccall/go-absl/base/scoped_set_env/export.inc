#ifndef ABSL_BASE_SCOPED_SET_ENV_EXPORT_H
#define ABSL_BASE_SCOPED_SET_ENV_EXPORT_H

#include "absl/base/internal/scoped_set_env.h"
#include "absl/base/internal/scoped_set_env.cc"

#if 0
namespace absl {
  namespace base_internal {

    ScopedSetEnv::ScopedSetEnv(const char* var_name, const char* new_value)
      : var_name_(var_name), was_unset_(false) {
    }

    ScopedSetEnv::~ScopedSetEnv() {
    }

  }
}
#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"

#endif
