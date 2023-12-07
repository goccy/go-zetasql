FROM golang:1.21-bookworm

RUN apt-get update && apt-get install -y --no-install-recommends curl ca-certificates gnupg
RUN curl https://bazel.build/bazel-release.pub.gpg | apt-key add -
RUN echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list
RUN apt-get update && apt-get install --no-install-recommends -y make g++ git python3 openjdk-11-jdk unzip
RUN update-alternatives --install /usr/bin/python python /usr/bin/python3 100
RUN go get github.com/bazelbuild/bazelisk

COPY zetasql /zetasql

WORKDIR /zetasql

RUN bazelisk build '//zetasql/public:sql_formatter'

COPY export.sh export.sh
