package pkg

import (
	"github.com/goccy/go-yaml"
)

type Config struct {
	Dependencies                    []ThirdPartyDependency `yaml:"dependencies"`
	GlobalSymbols                   []string               `yaml:"global_symbols"`
	TopLevelNamespaces              []string               `yaml:"top_level_namespaces"`
	ConflictSymbols                 []ConflictSymbol       `yaml:"conflict_symbols"`
	AddSources                      []SourceConfig         `yaml:"add_sources"`
	ExcludeZetaSQLDirs              []string               `yaml:"exclude_zetasql_dirs"`
	ProtobufInternalExportNameFiles []string               `yaml:"protobuf_internal_export_name_files"`
	CCLib                           CCLibConfig            `yaml:"cclib"`
	Protoc                          []ProtocConfig         `yaml:"protoc"`
}

type ThirdPartyDependency struct {
	Name string             `yaml:"name"`
	FQDN string             `yaml:"fqdn"`
	Deps []DependencyConfig `yaml:"deps"`
}

type DependencyConfig struct {
	Base string `yaml:"base"`
	Pkg  string `yaml:"pkg"`
}

type ConflictSymbol struct {
	File   string `yaml:"file"`
	Symbol string `yaml:"symbol"`
}

type SourceConfig struct {
	File   string `yaml:"file"`
	Source string `yaml:"source"`
}

type CCLibConfig struct {
	Excludes []string `yaml:"excludes"`
}

type ProtocConfig struct {
	Name string   `yaml:"name"`
	Deps []string `yaml:"deps"`
}

func LoadConfig(configYAML []byte) (*Config, error) {
	var cfg Config
	if err := yaml.Unmarshal(configYAML, &cfg); err != nil {
		return nil, err
	}
	return &cfg, nil
}
