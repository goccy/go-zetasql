# go-zetasql

![Go](https://github.com/goccy/go-zetasql/workflows/Go/badge.svg)
[![GoDoc](https://godoc.org/github.com/goccy/go-zetasql?status.svg)](https://pkg.go.dev/github.com/goccy/go-zetasql?tab=doc)

Go bindings for [ZetaSQL](https://github.com/google/zetasql)

ZetaSQL can parse all queries related to Cloud Spanner and BigQuery. This functionality is provided from the Go language using cgo. 

# Features

- No need to install ZetaSQL library
  - go-zetasql contains all the source code needed to build ZetaSQL and builds at `go get github.com/goccy/go-zetasql` timing. Therefore, there is no need to install dependent libraries separately.

- Can create a portable single binary even though it using cgo
  - You can create a static binary even with `CGO_ENABLED=1` by specifying the following options at build time: `--ldflags '-extldflags "-static"'`

- Can access all the APIs of the ZetaSQL parser
  - The ZetaSQL parser is not publicly available, but it is available in go-zetasql

# Status

In the feaatures of ZetaSQL, you can use the functions of the following packages. Will be added sequentially.

| Package        | Supported  |
| ----           | ----       |
| parser         | yes        |
| public         | partial    |
| analyzer       | no         |
| scripting      | no         |
| reference_impl | no         |

# Prerequisites

go-zetasql uses cgo. Therefore, `CGO_ENABLED=1` is required to build.  
Also, the compiler recommends `clang++`. Please set `CXX=clang++` to install.

|  Environment Name |  Value                   |
| ----              | ----                     |
|  CGO_ENABLED      |  1  ( required )         |
|  CXX              |  clang++ ( recommended ) |

# Installation

```
go get github.com/goccy/go-zetasql
```

The first time you run it, it takes time to build all the ZetaSQL code used by go-zetasql.

# License

Apache-2.0 License

Since go-zetasql builds all source code including dependencies at install time, it directly contains the source code of the following libraries. Therefore, the license is set according to the license of the dependent library.

- [zetasql](https://github.com/google/zetasql): [Apache License 2.0](https://github.com/google/zetasql/blob/master/LICENSE)
- [abseil](https://github.com/abseil/abseil-cpp): [Apache License 2.0](https://github.com/abseil/abseil-cpp/blob/master/LICENSE)
- [json](https://github.com/nlohmann/json): [MIT License](https://github.com/nlohmann/json/blob/develop/LICENSE.MIT)
- [re2](https://github.com/google/re2): [BSD 3-Clause](https://github.com/google/re2/blob/main/LICENSE)
- [boringssl](https://github.com/google/boringssl): [ISC License](https://github.com/google/boringssl/blob/master/LICENSE)
- [protobuf](https://github.com/protocolbuffers/protobuf): [License](https://github.com/protocolbuffers/protobuf/blob/master/LICENSE)
- [icu](https://github.com/unicode-org/icu): [ICU License](https://github.com/unicode-org/icu/blob/main/icu4c/LICENSE)
- [farmhash](https://github.com/google/farmhash): [MIT License](https://github.com/google/farmhash/blob/master/COPYING)
- [googletest](https://github.com/google/googletest): [BSD 3-Clause](https://github.com/google/googletest/blob/main/LICENSE)
