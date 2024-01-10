FROM golang:1.21-bookworm AS gotools

RUN go install github.com/goccy/go-wasmbind-tools/cmd/bazel2makefile@v0.1.2

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
COPY differential-privacy /differential-privacy

COPY --from=0 /go/bin/bazel2makefile /bin/bazel2makefile

WORKDIR /work

COPY config.yaml .

RUN bazel2makefile
