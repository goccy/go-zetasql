FROM ubuntu:18.04 as zetasql

RUN apt-get update && apt-get -qq install -y default-jre default-jdk curl tar build-essential wget python python3 zip unzip

ENV BAZEL_VERSION=6.2.0

RUN mkdir -p bazel && cd bazel && wget https://github.com/bazelbuild/bazel/releases/download/${BAZEL_VERSION}/bazel-${BAZEL_VERSION}-dist.zip && \
    unzip bazel-${BAZEL_VERSION}-dist.zip && rm -rf bazel-${BAZEL_VERSION}-dist.zip

ENV PATH=$PATH:/usr/bin:/usr/local/bin
ENV EXTRA_BAZEL_ARGS="--tool_java_runtime_version=local_jdk"
RUN cd bazel && bash ./compile.sh
RUN cp /bazel/output/bazel  /usr/local/bin

RUN apt-get update && DEBIAN_FRONTEND="noninteractive" TZ="America/Los_Angeles" apt-get install -y tzdata

RUN apt-get -qq install -y software-properties-common
RUN add-apt-repository ppa:ubuntu-toolchain-r/test                          && \
    apt-get -qq update                                                      && \
    apt-get -qq install -y gcc-11 g++-11 make rename  git                   && \
    apt-get -qq install -y ca-certificates libgnutls30                      && \
    update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 90          \
                        --slave   /usr/bin/g++ g++ /usr/bin/g++-11          && \
    update-alternatives --set gcc /usr/bin/gcc-11

WORKDIR /work

RUN git clone --depth=1 https://github.com/google/zetasql zetasql

ENV BAZEL_ARGS="--config=g++"
ENV CC=/usr/bin/gcc
ENV CXX=/usr/bin/g++

WORKDIR /work/zetasql

RUN bazel build ${BAZEL_ARGS} '//zetasql/parser:parser'
RUN bazel build ${BAZEL_ARGS} '//zetasql/public:catalog'
RUN bazel build ${BAZEL_ARGS} '//zetasql/public:simple_catalog'
RUN bazel build ${BAZEL_ARGS} '//zetasql/public:sql_formatter'
RUN bazel build ${BAZEL_ARGS} '//zetasql/public:analyzer'

FROM golang:1.21-bookworm AS gotools

RUN go install github.com/goccy/go-wasmbind-tools/cmd/bazel2makefile@c37dd6c1174e0716e44486444d7193fd385ad523

FROM emscripten/emsdk:latest

WORKDIR /work

RUN apt-get update && apt-get install -y less tree emacs

COPY --from=zetasql /root/.cache/bazel /root/.cache/bazel
COPY --from=zetasql /work/zetasql .
COPY --from=gotools /go/bin/bazel2makefile /bin/bazel2makefile

RUN cp -r $(find /root/.cache/bazel -name 'external' -type d | awk '{print length() ,$0}' | sort -r | awk '{print  $2}'| head -n1) /external
RUN cp -r . /zetasql
RUN cp -r bazel-bin/zetasql/* /zetasql/zetasql/
RUN cp -r bazel-bin/zetasql/resolved_ast/_virtual_imports/resolved_ast_proto/* /zetasql/
RUN cp -r bazel-bin/zetasql/resolved_ast/_virtual_imports/resolved_node_kind_proto/* /zetasql/
RUN cp -r bazel-bin/external/com_google_googleapis/* /external/com_google_googleapis/
RUN cp -r bazel-bin/external/com_google_differential_privacy/* /external/com_google_differential_privacy/

COPY config.yaml .
COPY bind.cc .
COPY value_inl.h /zetasql/zetasql/public/
COPY value.cc /zetasql/zetasql/public/
COPY synchronization_build.bazel /external/com_google_absl/absl/synchronization/BUILD.bazel
COPY icu_build.bazel /external/icu/BUILD.bazel
COPY protobuf_build.bazel /external/com_google_protobuf/BUILD.bazel

RUN bazel2makefile
RUN mkdir out


