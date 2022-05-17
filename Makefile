docker/build:
	docker build -t go-zetasql .

test/linux: docker/build
	docker run --rm go-zetasql bash -c "go test -v ./..."
