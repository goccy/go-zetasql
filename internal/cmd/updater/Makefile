CCALL_DIR := $(abspath $(CURDIR)/../../ccall)
EXTERNAL_DIR := $(abspath $(CURDIR)/cache/external)
OUT_DIR := $(abspath $(CURDIR)/cache/execroot/com_google_zetasql/bazel-out/k8-fastbuild/bin)
OUT_EXTERNAL_DIR := $(OUT_DIR)/external

build:
	docker build -t zetasql .

export: build
	docker run --rm -v "$(CURDIR)/cache:/tmp" zetasql sh -c "bash export.sh"

update:
	go run main.go
