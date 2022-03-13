package main

import (
	"embed"
	"log"

	"github.com/goccy/go-zetasql/internal/cmd/generator/pkg"
)

//go:embed templates/*.tmpl
var templates embed.FS

//go:embed config.yaml
var configYAML []byte

//go:embed bridge.yaml
var bridgeYAML []byte

//go:embed import.yaml
var importYAML []byte

func main() {
	if err := run(); err != nil {
		log.Fatalf("%+v\n", err)
	}
}

func run() error {
	cfg, err := pkg.LoadConfig(configYAML)
	if err != nil {
		return err
	}
	bridge, err := pkg.LoadBridge(bridgeYAML)
	if err != nil {
		return err
	}
	importSymbols, err := pkg.LoadImport(importYAML)
	if err != nil {
		return err
	}
	generator := pkg.NewGenerator(cfg, bridge, importSymbols, templates)
	return generator.Generate()
}
