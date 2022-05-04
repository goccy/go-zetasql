package types

import "unsafe"

type AnnotationMap struct {
	raw unsafe.Pointer
}

func newAnnotationMap(v unsafe.Pointer) *AnnotationMap {
	return &AnnotationMap{raw: v}
}

func getRawAnnotationMap(v *AnnotationMap) unsafe.Pointer {
	return v.raw
}
