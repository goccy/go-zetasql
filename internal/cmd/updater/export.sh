#!/bin/bash

BAZEL_ZETASQL=$(readlink bazel-zetasql)
CACHE_ROOT=$BAZEL_ZETASQL/../../
cp -r $CACHE_ROOT/* /tmp/
