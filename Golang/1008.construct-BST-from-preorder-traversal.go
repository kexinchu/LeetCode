package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// first Solution: Recurse
func bstFromPreorder(preorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}

	// root
	root := &TreeNode{Val: preorder[0]}

	// split left-/right- sub tree
	// first value which is bigger than preorder[0]
	i := 1
	for i < len(preorder) && preorder[i] < preorder[0] {
		i += 1
	}

	root.Left = bstFromPreorder(preorder[1:i])
	root.Right = bstFromPreorder(preorder[i:])

	return root
}

// second Solution: Iteration
// iteration
// with help of stack
func bstFromPreorder_iter(preorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}
	root := &TreeNode{Val: preorder[0]}
	var stack = []*TreeNode{root}

	// iteration
	for i := 1; i < len(preorder); i++ {
		node := &TreeNode{Val: preorder[i]}

		// left- sub node
		if preorder[i] < stack[len(stack)-1].Val {
			stack[len(stack)-1].Left = node
		} else {
			var parent *TreeNode
			// parent is the last one which is smaller than preorder[i]
			for len(stack) > 0 && preorder[i] > stack[len(stack)-1].Val {
				parent = stack[len(stack)-1]
				stack = stack[:len(stack)-1]
			}
			parent.Right = node
		}

		stack = append(stack, node)
	}

	return root
}
