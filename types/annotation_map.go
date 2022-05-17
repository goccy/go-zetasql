package types

import "unsafe"

// AnnotationMap maps from AnnotationSpec ID to SimpleValue.
type AnnotationMap interface {
	IsStructMap() bool
	IsArrayMap() bool
	getRaw() unsafe.Pointer
}

type BaseAnnotationMap struct {
	raw unsafe.Pointer
}

func (m *BaseAnnotationMap) getRaw() unsafe.Pointer {
	return m.raw
}

func (m *BaseAnnotationMap) IsStructMap() bool {
	return false
}

func (m *BaseAnnotationMap) IsArrayMap() bool {
	return false
}

type StructAnnotationMap struct {
	*BaseAnnotationMap
}

type ArrayAnnotationMap struct {
	*BaseAnnotationMap
}

func newAnnotationMap(v unsafe.Pointer) AnnotationMap {
	return &BaseAnnotationMap{raw: v}
}

func getRawAnnotationMap(v AnnotationMap) unsafe.Pointer {
	return v.getRaw()
}
