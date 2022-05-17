#ifndef ICU_EXPORT_H
#define ICU_EXPORT_H

#include "common/unicode/utypes.h"
#include "common/unicode/utf.h"
#include "common/unicode/utf8.h"
#include "common/uassert.h"
#include "common/unisetspan.h"
#include "common/bmpset.h"
#include "common/unicode/uobject.h"
#include "common/unicode/ures.h"

#include "common/utf_impl.cpp"

#define BACKSLASH GO_EXPORT(uniset_BACKSLASH)
#define UPPER_U GO_EXPORT(uniset_UPPER_U)
#define LOWER_U GO_EXPORT(uniset_LOWER_U)
#include "common/uniset.cpp"
#undef BACKSLASH
#undef UPPER_U
#undef LOWER_U

#include "common/util.cpp"
#include "common/loadednormalizer2impl.cpp"

#include "common/normalizer2.cpp"

#include "common/patternprops.cpp"
#include "common/unifilt.cpp"
#include "common/unistr.cpp"
#include "common/unisetspan.cpp"
#include "common/bmpset.cpp"
#include "common/uobject.cpp"
#include "common/uvector.cpp"
#include "common/bytestream.cpp"

#include "common/bytesinkutil.cpp"

#include "common/errorcode.cpp"
#include "common/unifunct.cpp"

#define swap GO_EXPORT(cswap)
#include "common/characterproperties.cpp"
#undef swap

#define _enumPropertyStartsRange GO_EXPORT(uchar_enumPropertyStartsRange)
#include "common/uchar.cpp"
#undef _enumPropertyStartsRange

#include "common/ustring.cpp"
#include "common/cmemory.cpp"
#include "common/appendable.cpp"
#include "common/ustrcase.cpp"
#include "common/stringpiece.cpp"
#include "common/unistr_case.cpp"

#include "common/normalizer2impl.cpp"

#include "common/umutex.cpp"
#include "common/edits.cpp"

#define _enumPropertyStartsRange GO_EXPORT(ucase_enumPropertyStartsRange)
#include "common/ucase.cpp"
#undef _enumPropertyStartsRange

#include "common/uinvchar.cpp"
#include "common/ucptrie.cpp"
#include "common/udataswp.cpp"
#include "common/udatamem.cpp"
#include "common/uhash.cpp"
#include "common/uloc.cpp"

#define appendResult GO_EXPORT(ucasemap_appendResult)
#include "common/ucasemap.cpp"
#undef appendResult

#include "common/locid.cpp"

#include "common/utypes.cpp"
#include "common/ustrtrns.cpp"
#include "common/ucln_cmn.cpp"
#include "common/ucmndata.cpp"

#include "common/unicode/udata.h"
#include "common/udata.cpp"

#include "common/uenum.cpp"
#include "common/uloc_keytype.cpp"
#include "common/uloc_tag.cpp"
#include "common/cstring.cpp"
#include "common/locmap.cpp"
#include "common/umath.cpp"
#include "common/uarrsort.cpp"
#include "common/ustrcase_locale.cpp"
#include "common/utrie2.cpp"
#include "common/charstr.cpp"

#define cache GO_EXPORT(uresbund_cache)
#include "common/uresbund.cpp"
#undef cache

#include "common/uresdata.cpp"

#include "common/utrace.cpp"
#include "common/putil.cpp"
#include "common/umapfile.cpp"

#define getRange GO_EXPORT(umutablecptrie_getRange)
#include "common/umutablecptrie.cpp"
#undef getRange

#include "common/uprops.cpp"
#include "common/resource.cpp"
#include "common/ustrenum.cpp"
#include "common/ubidi_props.cpp"
#include "common/ucol_swp.cpp"
#include "common/loclikely.cpp"

#define ASCII_LIMIT GO_EXPORT(utrie_swap_ASCII_LIMIT)
#include "common/utrie_swap.cpp"
#undef ASCII_LIMIT

#include "common/propname.cpp"
#include "common/uscript_props.cpp"
#include "common/bytestrie.cpp"

#endif
