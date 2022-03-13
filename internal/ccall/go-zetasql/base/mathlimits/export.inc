#ifndef ZETASQL_BASE_MATHLIMITS_EXPORT_H
#define ZETASQL_BASE_MATHLIMITS_EXPORT_H

#include "zetasql/base/mathlimits.h"

#include "zetasql/base/mathlimits.cc"

#if 0

namespace zetasql_base {

#ifdef COMPILER_MSVC

#define DEF_COMMON_LIMITS(Type)
#define DEF_UNSIGNED_INT_LIMITS(Type)
#define DEF_SIGNED_INT_LIMITS(Type)
#define DEF_PRECISION_LIMITS(Type)

#else

#define DEF_COMMON_LIMITS(Type)                 \
  const bool MathLimits<Type>::kIsSigned;       \
  const bool MathLimits<Type>::kIsInteger;      \
  const int MathLimits<Type>::kMin10Exp;        \
  const int MathLimits<Type>::kMax10Exp;

#define DEF_UNSIGNED_INT_LIMITS(Type)           \
  DEF_COMMON_LIMITS(Type)                       \
  const Type MathLimits<Type>::kPosMin;         \
  const Type MathLimits<Type>::kPosMax;         \
  const Type MathLimits<Type>::kMin;            \
  const Type MathLimits<Type>::kMax;            \
  const Type MathLimits<Type>::kEpsilon;        \
  const Type MathLimits<Type>::kStdError;

#define DEF_SIGNED_INT_LIMITS(Type)             \
  DEF_UNSIGNED_INT_LIMITS(Type)                 \
  const Type MathLimits<Type>::kNegMin;         \
  const Type MathLimits<Type>::kNegMax;

#define DEF_PRECISION_LIMITS(Type)              \
  const int MathLimits<Type>::kPrecisionDigits;

#endif  // not COMPILER_MSVC

#define DEF_FP_LIMITS(Type, min_val, max_val, eps_val, inf_val)         \
  DEF_COMMON_LIMITS(Type)                                               \
  const Type MathLimits<Type>::kPosMin = min_val;                       \
  const Type MathLimits<Type>::kPosMax = max_val;                       \
  const Type MathLimits<Type>::kMin = -max_val;                         \
  const Type MathLimits<Type>::kMax = max_val;                          \
  const Type MathLimits<Type>::kNegMin = -min_val;                      \
  const Type MathLimits<Type>::kNegMax = -max_val;                      \
  const Type MathLimits<Type>::kEpsilon = eps_val;                      \
  /* 32 is 5 bits of mantissa error; should be adequate for common errors */ \
  const Type MathLimits<Type>::kStdError =                              \
    32 * (static_cast<Type>(DBL_EPSILON * DBL_EPSILON) >                \
          MathLimits<Type>::kEpsilon                                    \
          ? static_cast<Type>(DBL_EPSILON * DBL_EPSILON)                \
          : MathLimits<Type>::kEpsilon);                                \
  DEF_PRECISION_LIMITS(Type)                                            \
  const Type MathLimits<Type>::kNaN = inf_val - inf_val;                \
  const Type MathLimits<Type>::kPosInf = inf_val;                       \
  const Type MathLimits<Type>::kNegInf = -inf_val;

  // The following are *not* casts!
  DEF_SIGNED_INT_LIMITS(signed char)
  DEF_SIGNED_INT_LIMITS(short)      // NOLINT(runtime/int)
  DEF_SIGNED_INT_LIMITS(int)        // NOLINT(runtime/int)
  DEF_SIGNED_INT_LIMITS(long)       // NOLINT(runtime/int)
  DEF_SIGNED_INT_LIMITS(long long)  // NOLINT(runtime/int)

  DEF_UNSIGNED_INT_LIMITS(unsigned char)
  DEF_UNSIGNED_INT_LIMITS(unsigned short)      // NOLINT(runtime/int)
  DEF_UNSIGNED_INT_LIMITS(unsigned)            // NOLINT(runtime/int)
  DEF_UNSIGNED_INT_LIMITS(unsigned long)       // NOLINT(runtime/int)
  DEF_UNSIGNED_INT_LIMITS(unsigned long long)  // NOLINT(runtime/int)

  DEF_FP_LIMITS(float, FLT_MIN, FLT_MAX, FLT_EPSILON, HUGE_VALF)
  DEF_FP_LIMITS(double, DBL_MIN, DBL_MAX, DBL_EPSILON, HUGE_VAL)
  DEF_FP_LIMITS(long double, LDBL_MIN, LDBL_MAX, LDBL_EPSILON, HUGE_VALL)

#undef DEF_COMMON_LIMITS
#undef DEF_SIGNED_INT_LIMITS
#undef DEF_UNSIGNED_INT_LIMITS
#undef DEF_FP_LIMITS
#undef DEF_PRECISION_LIMITS

}  // namespace zetasql_base

#endif

#endif
