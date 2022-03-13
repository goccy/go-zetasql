#ifndef ABSL_BASE_SCOPED_SET_ENV_EXPORT_H
#define ABSL_BASE_SCOPED_SET_ENV_EXPORT_H

#include "absl/base/internal/scoped_set_env.h"

namespace absl {
  namespace base_internal {

    ScopedSetEnv::ScopedSetEnv(const char* var_name, const char* new_value)
      : var_name_(var_name), was_unset_(false) {
    }

    ScopedSetEnv::~ScopedSetEnv() {
    }

  }
}

#include "go-absl/base/config/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"

#endif
