FROM emscripten/emsdk:latest

COPY zetasql /zetasql
COPY protobuf /protobuf
COPY gtest /gtest
COPY icu /icu
COPY re2 /re2
COPY json /json
COPY googleapis /googleapis
COPY flex /flex
COPY absl /absl
COPY boringssl /boringssl
COPY farmhash /farmhash
COPY com_google_googletest /com_google_googletest

WORKDIR /work

COPY Makefile .
