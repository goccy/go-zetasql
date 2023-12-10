FROM golang:1.21-bookworm

ARG VERSION

RUN apt-get update && apt-get install -y --no-install-recommends clang

ENV CGO_ENABLED 1
ENV CXX clang++

WORKDIR /work

COPY ./go.* ./
RUN go mod download

COPY . ./

RUN go install .
