CC := emcc

ZETASQL_ROOT := /zetasql
PROTOBUF_ROOT := /protobuf
GTEST_ROOT := /gtest
ICU_ROOT := /icu
RE2_ROOT := /re2
JSON_ROOT := /json
GOOGLEAPIS_ROOT := /googleapis
FLEX_ROOT := /flex
ABSL := /absl
GOOGLETEST := /com_google_googletest

TARGET := zetasql.wasm

build:
	$(CC) \
		--no-entry \
		-Wall \
		-Wextra \
		-Wno-ignored-qualifiers \
		-Wno-array-parameter \
		-Wno-bitwise-instead-of-logical \
		-Wno-implicit-function-declaration \
		-Wno-incompatible-pointer-types-discards-qualifiers \
		-Wno-missing-field-initializers \
		-Wno-undef \
		-Wno-unused-parameter \
		-Wno-final-dtor-non-final-class \
		-Wno-implicit-const-int-float-conversion \
		-Wno-char-subscripts \
		-Wno-sign-compare \
		-Wno-switch \
		-Wno-unused-function \
		-Wno-deprecated-declarations \
		-Wno-inconsistent-missing-override \
		-Wno-unknown-attributes \
		-Wno-macro-redefined \
		-Wno-shift-count-overflow \
		-Wno-enum-compare-switch \
		-Wno-return-type \
		-Wno-subobject-linkage \
		-Wno-unknown-warning-option \
		-Wno-deprecated \
		-fno-exceptions \
		-funsigned-char \
		-DU_COMMON_IMPLEMENTATION \
		-sWASM=1 \
		-sSTANDALONE_WASM \
		-sEXPORT_ALL \
		-sSTACK_SIZE=1MB \
		--emit-symbol-map \
		-std=c++1z \
		-I/ \
		-I$(ZETASQL_ROOT) \
		-I$(PROTOBUF_ROOT) \
		-I$(GTEST_ROOT) \
		-I$(ICU_ROOT) \
		-I$(RE2_ROOT) \
		-I$(JSON_ROOT) \
		-I$(GOOGLEAPIS_ROOT) \
		-I$(FLEX_ROOT)/src \
		-I$(GOOGLETEST)/googlemock/include \
		$(ZETASQL_ROOT)/parser/bison_parser.cc \
		$(ZETASQL_ROOT)/parser/flex_tokenizer.cc \
		$(ZETASQL_ROOT)/parser/parser.cc \
		$(ZETASQL_ROOT)/parser/unparser.cc \
		$(ABSL)/base/*.cc \
		$(ABSL)/base/internal/*.cc \
		$(ABSL)/container/internal/*.cc \
		$(ABSL)/flags/*.cc \
		$(ABSL)/flags/internal/*.cc \
		$(ABSL)/hash/internal/*.cc \
		$(ABSL)/strings/*.cc \
		$(ABSL)/strings/internal/*.cc \
		$(ABSL)/strings/internal/str_format/*.cc \
		$(ABSL)/synchronization/*.cc \
		$(ABSL)/synchronization/internal/*.cc \
		$(ABSL)/debugging/*.cc \
		$(ABSL)/debugging/internal/*.cc \
		$(ABSL)/profiling/internal/*.cc \
		$(ABSL)/random/*.cc \
		$(ABSL)/random/internal/*.cc \
		$(ABSL)/status/*.cc \
		$(ABSL)/time/*.cc \
		$(ABSL)/time/internal/*.cc \
		$(ABSL)/time/internal/cctz/src/*.cc \
		$(ABSL)/types/*.cc \
		$(ABSL)/numeric/*.cc \
		-o $(TARGET)

