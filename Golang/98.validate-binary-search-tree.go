package main

// Definition for a binary tree node.
//type TreeNode struct {
//	Val   int
//	Left  *TreeNode
//	Right *TreeNode
//}

// isValidBST checks if a binary tree is a valid binary search tree.
func isValidBST(root *TreeNode) bool {
	return validate(root, nil, nil)
}

// validate recursively checks the validity of the BST by ensuring that all left nodes are less than the current node
// and all right nodes are greater than the current node.
func validate(node *TreeNode, min, max *int) bool {
	if node == nil {
		return true
	}
	if min != nil && node.Val <= *min {
		return false
	}
	if max != nil && node.Val >= *max {
		return false
	}
	return validate(node.Left, min, &node.Val) && validate(node.Right, &node.Val, max)
}
