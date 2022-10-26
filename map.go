package zetasql

import (
	"unsafe"

	"github.com/goccy/go-zetasql/ast"
	"github.com/goccy/go-zetasql/resolved_ast"
	"github.com/goccy/go-zetasql/types"
)

type NodeMap struct {
	resolvedNode              resolved_ast.Node
	node                      ast.Node
	locationToNodeMap         map[string][]ast.Node
	locationToResolvedNodeMap map[string][]resolved_ast.Node
	resolvedNodeToParentMap   map[unsafe.Pointer][]resolved_ast.Node
}

func NewNodeMap(resolvedNode resolved_ast.Node, node ast.Node) *NodeMap {
	m := &NodeMap{
		resolvedNode:              resolvedNode,
		node:                      node,
		locationToNodeMap:         map[string][]ast.Node{},
		locationToResolvedNodeMap: map[string][]resolved_ast.Node{},
		resolvedNodeToParentMap:   map[unsafe.Pointer][]resolved_ast.Node{},
	}
	m.init()
	return m
}

func (m *NodeMap) init() {
	_ = ast.Walk(m.node, func(n ast.Node) error {
		if n == nil {
			return nil
		}
		locRange := n.ParseLocationRange().String()
		m.locationToNodeMap[locRange] = append(m.locationToNodeMap[locRange], n)
		return nil
	})
	_ = resolved_ast.Walk(m.resolvedNode, func(n resolved_ast.Node) error {
		if n == nil {
			return nil
		}
		for _, child := range n.ChildNodes() {
			p := getRawResolvedNode(child)
			m.resolvedNodeToParentMap[p] = append(m.resolvedNodeToParentMap[p], n)
		}
		locRange := n.ParseLocationRange()
		if locRange == nil {
			return nil
		}
		key := locRange.String()
		m.locationToResolvedNodeMap[key] = append(m.locationToResolvedNodeMap[key], n)
		return nil
	})
}

func (m *NodeMap) FindNodeFromResolvedNode(n resolved_ast.Node) []ast.Node {
	return m.findNodeFromResolvedNode(n)
}

func (m *NodeMap) FindResolvedNodeFromNode(n ast.Node) []resolved_ast.Node {
	return m.findResolvedNodeFromNode(n)
}

func (m *NodeMap) findNodeFromResolvedNode(n resolved_ast.Node) []ast.Node {
	found := m.findNodeFromLocationRange(n.ParseLocationRange())
	if len(found) != 0 {
		return found
	}
	for _, child := range n.ChildNodes() {
		found := m.findNodeFromLocationRange(child.ParseLocationRange())
		if len(found) == 0 {
			continue
		}
		parents := make([]ast.Node, 0, len(found))
		for _, node := range found {
			p := node.Parent()
			if p == nil {
				parents = append(parents, node)
			} else {
				parents = append(parents, p)
			}
		}
		return parents
	}
	p := getRawResolvedNode(n)
	for _, parent := range m.resolvedNodeToParentMap[p] {
		found := m.findNodeFromResolvedNode(parent)
		if len(found) != 0 {
			return found
		}
	}
	return nil
}

func (m *NodeMap) findResolvedNodeFromNode(n ast.Node) []resolved_ast.Node {
	found := m.findResolvedNodeFromLocationRange(n.ParseLocationRange())
	if len(found) != 0 {
		return found
	}
	for i := 0; i < n.NumChildren(); i++ {
		child := n.Child(i)
		found := m.findResolvedNodeFromLocationRange(child.ParseLocationRange())
		if len(found) == 0 {
			continue
		}
		parents := make([]resolved_ast.Node, 0, len(found))
		for _, node := range found {
			p := getRawResolvedNode(node)
			parent := m.resolvedNodeToParentMap[p]
			if len(parent) == 0 {
				parents = append(parents, node)
			} else {
				parents = append(parents, parent...)
			}
		}
		return parents
	}
	return m.findResolvedNodeFromNode(n.Parent())
}

func (m *NodeMap) findNodeFromLocationRange(locRange *types.ParseLocationRange) []ast.Node {
	if locRange == nil {
		return nil
	}
	found, exists := m.locationToNodeMap[locRange.String()]
	if exists {
		return found
	}
	return nil
}

func (m *NodeMap) findResolvedNodeFromLocationRange(locRange *types.ParseLocationRange) []resolved_ast.Node {
	if locRange == nil {
		return nil
	}
	found, exists := m.locationToResolvedNodeMap[locRange.String()]
	if exists {
		return found
	}
	return nil
}
