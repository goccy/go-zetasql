package pkg

import (
	"os"
	"path/filepath"
	"runtime"
	"strings"
)

func pkgDir() string {
	_, file, _, _ := runtime.Caller(0)
	return filepath.Dir(file)
}

func repoRootDir() string {
	path, _ := filepath.Abs(filepath.Join(pkgDir(), "..", "..", "..", ".."))
	return path
}

func internalDir() string {
	return filepath.Join(repoRootDir(), "internal")
}

func ccallDir() string {
	return filepath.Join(internalDir(), "ccall")
}

func toSourceDirFromLibName(lib string) string {
	return filepath.Join(ccallDir(), lib)
}

func existsFile(path string) bool {
	_, err := os.Stat(path)
	return err == nil
}

func goPkgPath(base, pkg string) string {
	newPath := []string{}
	for _, path := range strings.Split(base, "/") {
		if path == "internal" {
			newPath = append(newPath, "go_internal")
		} else {
			newPath = append(newPath, path)
		}
	}
	return "go-" + filepath.Join(filepath.Join(newPath...), pkg)
}

func normalizeGoPkgPath(name string) string {
	splitted := strings.Split(name, "/")
	base := filepath.Join(splitted[:len(splitted)-1]...)
	pkg := splitted[len(splitted)-1]
	return goPkgPath(base, pkg)
}
