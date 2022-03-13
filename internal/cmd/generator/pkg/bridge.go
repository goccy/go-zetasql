package pkg

import (
	"github.com/goccy/go-yaml"
)

type Bridge struct {
	Packages []Package
}

type ImportSymbol = Bridge

type Package struct {
	Name    string   `yaml:"package"`
	Methods []Method `yaml:"methods"`
}

type Method struct {
	Name string   `yaml:"name"`
	Args []string `yaml:"args,omitempty"`
	Ret  []string `yaml:"ret,omitempty"`
}

func LoadBridge(bridgeYAML []byte) (*Bridge, error) {
	var pkgs []Package
	if err := yaml.Unmarshal(bridgeYAML, &pkgs); err != nil {
		return nil, err
	}
	return &Bridge{Packages: pkgs}, nil
}

func LoadImport(importYAML []byte) (*ImportSymbol, error) {
	var pkgs []Package
	if err := yaml.Unmarshal(importYAML, &pkgs); err != nil {
		return nil, err
	}
	return &ImportSymbol{Packages: pkgs}, nil
}
