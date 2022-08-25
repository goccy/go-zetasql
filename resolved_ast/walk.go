package resolved_ast

// Walk traverse all nodes by depth-first search.
func Walk(n Node, cb func(Node) error) error {
	if err := cb(n); err != nil {
		return err
	}
	if n == nil {
		return nil
	}
	for _, nn := range n.ChildNodes() {
		if err := Walk(nn, cb); err != nil {
			return err
		}
	}
	return nil
}
