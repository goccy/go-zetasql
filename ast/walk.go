package ast

func Walk(n Node, cb func(Node) error) error {
	if err := cb(n); err != nil {
		return err
	}
	if n == nil {
		return nil
	}
	for i := 0; i < n.NumChildren(); i++ {
		nn := n.Child(i)
		if err := Walk(nn, cb); err != nil {
			return err
		}
	}
	return nil
}
