FROM golang:1.21-bookworm

RUN apt-get update && apt-get install -y --no-install-recommends clang

ENV CGO_ENABLED 1
ENV CXX clang++

COPY . /go-zetasql

WORKDIR /go-zetasql
