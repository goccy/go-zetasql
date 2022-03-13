package main

import (
	"io"
	"io/fs"
	"os"
	"path/filepath"
	"runtime"
	"strings"

	cp "github.com/otiai10/copy"
)

func pkgDir() string {
	_, file, _, _ := runtime.Caller(0)
	return filepath.Dir(file)
}

func repoRootDir() string {
	path, _ := filepath.Abs(filepath.Join(pkgDir(), "..", "..", ".."))
	return path
}

func internalDir() string {
	return filepath.Join(repoRootDir(), "internal")
}

func ccallDir() string {
	return filepath.Join(internalDir(), "ccall")
}

func cacheDir() string {
	return filepath.Join(pkgDir(), "cache")
}

func externalDir() string {
	return filepath.Join(cacheDir(), "external")
}

func outDir() string {
	return filepath.Join(
		cacheDir(),
		"execroot",
		"com_google_zetasql",
		"bazel-out",
		"k8-fastbuild",
		"bin",
	)
}

func outExternalDir() string {
	return filepath.Join(outDir(), "external")
}

var copyExternalLibMap = map[string]string{
	"icu/source":                "icu",
	"json":                      "json",
	"flex":                      "flex",
	"com_google_absl/absl":      "absl",
	"com_google_protobuf/src":   "protobuf",
	"com_googlesource_code_re2": "re2",
}

var copyOutExternalLibMap = map[string]string{
	"com_google_googleapis": "googleapis",
}

func main() {
	opt := cp.Options{
		AddPermission: 0o755,
		Skip: func(src string) (bool, error) {
			info, err := os.Stat(src)
			if err != nil {
				return false, err
			}
			if info.IsDir() {
				return false, nil
			}
			switch filepath.Base(src) {
			case "BUILD", "BUILD.bazel":
				return false, nil
			}
			switch filepath.Ext(src) {
			case ".h", ".hh", ".cc", ".c", ".inc":
				return false, nil
			}
			return true, nil
		},
	}
	for src, dst := range copyExternalLibMap {
		cp.Copy(
			filepath.Join(externalDir(), src),
			filepath.Join(ccallDir(), dst),
			opt,
		)
	}
	for src, dst := range copyOutExternalLibMap {
		cp.Copy(
			filepath.Join(outExternalDir(), src),
			filepath.Join(ccallDir(), dst),
			opt,
		)
	}
	cp.Copy(
		filepath.Join(pkgDir(), "zetasql", "zetasql"),
		filepath.Join(ccallDir(), "zetasql"),
		opt,
	)
	if err := filepath.Walk(
		filepath.Join(outDir(), "zetasql"),
		func(path string, info fs.FileInfo, err error) error {
			if info.IsDir() {
				return nil
			}
			if (info.Mode() & fs.ModeSymlink) != 0 {
				return nil
			}
			fileName := filepath.Base(path)
			lastChar := fileName[len(fileName)-1]
			if lastChar == 'h' || lastChar == 'c' {
				idx := strings.LastIndex(path, "zetasql")
				trimmedPath := path[idx:]
				dstFile := filepath.Join(ccallDir(), trimmedPath)
				src, err := os.Open(path)
				if err != nil {
					return err
				}
				defer src.Close()
				dst, err := os.Create(dstFile)
				if err != nil {
					return err
				}
				defer dst.Close()
				if _, err := io.Copy(dst, src); err != nil {
					return err
				}
			}
			return nil
		},
	); err != nil {
		panic(err)
	}
}
