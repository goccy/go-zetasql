#ifndef ABSL_STRINGS_STR_FORMAT_INTERNAL_EXPORT_H
#define ABSL_STRINGS_STR_FORMAT_INTERNAL_EXPORT_H

#include "absl/strings/internal/str_format/arg.h"
#include "absl/strings/internal/str_format/bind.h"
#include "absl/strings/internal/str_format/checker.h"
#include "absl/strings/internal/str_format/extension.h"
#include "absl/strings/internal/str_format/float_conversion.h"
#include "absl/strings/internal/str_format/output.h"
#include "absl/strings/internal/str_format/parser.h"

#include "absl/strings/internal/str_format/arg.cc"
#include "absl/strings/internal/str_format/bind.cc"
#include "absl/strings/internal/str_format/extension.cc"
#include "absl/strings/internal/str_format/float_conversion.cc"
#include "absl/strings/internal/str_format/output.cc"
#include "absl/strings/internal/str_format/parser.cc"

#if 0
namespace absl {
  namespace str_format_internal {

    StringConvertResult FormatConvertImpl(const std::string &v,
                                          const FormatConversionSpecImpl conv,
                                          FormatSinkImpl *sink) {
      StringConvertResult rv;
      return rv;
    }

    StringConvertResult FormatConvertImpl(string_view v,
                                          const FormatConversionSpecImpl conv,
                                          FormatSinkImpl *sink) {
      StringConvertResult rv;
      return rv;
    }

    ArgConvertResult<FormatConversionCharSetUnion(FormatConversionCharSetInternal::s, FormatConversionCharSetInternal::p)>
    FormatConvertImpl(const char *v, const FormatConversionSpecImpl conv,
                      FormatSinkImpl *sink) {
      ArgConvertResult<FormatConversionCharSetUnion(FormatConversionCharSetInternal::s, FormatConversionCharSetInternal::p)> rv;
      return rv;
    }

    ArgConvertResult<FormatConversionCharSetInternal::p> FormatConvertImpl(VoidPtr v, const FormatConversionSpecImpl conv, FormatSinkImpl *sink) {
      ArgConvertResult<FormatConversionCharSetInternal::p> rv;
      return rv;
    }

    FloatingConvertResult FormatConvertImpl(float v,
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      FloatingConvertResult rv;
      return rv;
    }
    FloatingConvertResult FormatConvertImpl(double v,
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      FloatingConvertResult rv;
      return rv;
    }
    FloatingConvertResult FormatConvertImpl(long double v,
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      FloatingConvertResult rv;
      return rv;
    }

    IntegralConvertResult FormatConvertImpl(char v,
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      IntegralConvertResult rv;
      return rv;
    }
    IntegralConvertResult FormatConvertImpl(signed char v,
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      IntegralConvertResult rv;
      return rv;
    }
    IntegralConvertResult FormatConvertImpl(unsigned char v,
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      IntegralConvertResult rv;
      return rv;
    }

    IntegralConvertResult FormatConvertImpl(short v,  // NOLINT
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      IntegralConvertResult rv;
      return rv;
    }
    IntegralConvertResult FormatConvertImpl(unsigned short v,  // NOLINT
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      IntegralConvertResult rv;
      return rv;
    }
    IntegralConvertResult FormatConvertImpl(int v,
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      IntegralConvertResult rv;
      return rv;
    }
    IntegralConvertResult FormatConvertImpl(unsigned v,
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      IntegralConvertResult rv;
      return rv;
    }
    IntegralConvertResult FormatConvertImpl(long v,  // NOLINT
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      IntegralConvertResult rv;
      return rv;
    }
    IntegralConvertResult FormatConvertImpl(unsigned long v,  // NOLINT
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      IntegralConvertResult rv;
      return rv;
    }
    IntegralConvertResult FormatConvertImpl(long long v,  // NOLINT
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      IntegralConvertResult rv;
      return rv;
    }
    IntegralConvertResult FormatConvertImpl(unsigned long long v,  // NOLINT
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      IntegralConvertResult rv;
      return rv;
    }
    IntegralConvertResult FormatConvertImpl(absl::int128 v,
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      IntegralConvertResult rv;
      return rv;
    }
    IntegralConvertResult FormatConvertImpl(absl::uint128 v,
                                            const FormatConversionSpecImpl conv,
                                            FormatSinkImpl *sink) {
      IntegralConvertResult rv;
      return rv;
    }

    ABSL_INTERNAL_FORMAT_DISPATCH_OVERLOADS_EXPAND_();
  }
}

namespace absl {
  namespace str_format_internal {

    bool BindWithPack(const UnboundConversion* props,
                      absl::Span<const FormatArgImpl> pack,
                      BoundConversion* bound) {
      return false;
    }

    std::string Summarize(const UntypedFormatSpecImpl format,
                          absl::Span<const FormatArgImpl> args) {
      return "";
    }

    bool FormatUntyped(FormatRawSinkImpl raw_sink,
                       const UntypedFormatSpecImpl format,
                       absl::Span<const FormatArgImpl> args) {
      return false;
    }

    std::ostream& Streamable::Print(std::ostream& os) const {
      return os;
    }

    std::string& AppendPack(std::string* out, const UntypedFormatSpecImpl format,
                            absl::Span<const FormatArgImpl> args) {
      return *out;
    }

    std::string FormatPack(const UntypedFormatSpecImpl format,
                           absl::Span<const FormatArgImpl> args) {
      return "";
    }

    int FprintF(std::FILE* output, const UntypedFormatSpecImpl format,
                absl::Span<const FormatArgImpl> args) {
      return 0;
    }

    int SnprintF(char* output, size_t size, const UntypedFormatSpecImpl format,
                 absl::Span<const FormatArgImpl> args) {
      return 0;
    }

  }
}

namespace absl {
  namespace str_format_internal {

    std::string FlagsToString(Flags v) {
      return "";
    }

    bool FormatSinkImpl::PutPaddedString(string_view value, int width,
                                         int precision, bool left) {
      return false;
    }

  }
}

namespace absl {
  namespace str_format_internal {

    bool ConvertFloatImpl(long double v, const FormatConversionSpecImpl &conv,
                          FormatSinkImpl *sink) {
      return false;
    }

    bool ConvertFloatImpl(float v, const FormatConversionSpecImpl &conv,
                          FormatSinkImpl *sink) {
      return false;
    }

    bool ConvertFloatImpl(double v, const FormatConversionSpecImpl &conv,
                          FormatSinkImpl *sink) {
      return false;
    }

  }
}

namespace absl {
  namespace str_format_internal {

    void BufferRawSink::Write(string_view v) {
    }

    void FILERawSink::Write(string_view v) {
    }

  }
}

namespace absl {
  namespace str_format_internal {

    using CC = FormatConversionCharInternal;
    using LM = LengthMod;
    const ConvTag kTags[256] = {};

    std::string LengthModToString(LengthMod v) {
      return "";
    }

    const char *ConsumeUnboundConversion(const char *p, const char *end,
                                         UnboundConversion *conv, int *next_arg) {
      return nullptr;
    }

    ParsedFormatBase::ParsedFormatBase(
                                       string_view format, bool allow_ignored,
                                       std::initializer_list<FormatConversionCharSet> convs)
      : data_(format.empty() ? nullptr : new char[format.size()]) {
    }

    bool ParsedFormatBase::MatchesConversions(
                                              bool allow_ignored,
                                              std::initializer_list<FormatConversionCharSet> convs) const {
      return false;
    }

  }
}

#endif

#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/functional/function_ref/export.inc"
#include "go-absl/meta/type_traits/export.inc"
#include "go-absl/numeric/bits/export.inc"
#include "go-absl/numeric/int128/export.inc"
#include "go-absl/numeric/representation/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/types/optional/export.inc"
#include "go-absl/types/span/export.inc"

#endif
