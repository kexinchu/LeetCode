package main

/**
Preorder: 144
Inorder: 94
Postorder: 145
is quite similar
*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
// 递归
func preorderTraversal_recurse(root *TreeNode) []int {
	var result = []int{}

	// 注意定义方法
	// func recurse(node *TreeNode) {  // error
	// correct way:
	var recurse func(node *TreeNode)
	recurse = func(node *TreeNode) {
		if node == nil {
			return
		}

		result = append(result, node.Val)
		recurse(node.Left)
		recurse(node.Right)
	}

	recurse(root)
	return result
}

// 迭代 - 栈 通过数组/切片实现
func preorderTraversal_iteration(root *TreeNode) []int {
	var result = []int{}

	// 栈
	var stack = []*TreeNode{root}
	var node *TreeNode

	for len(stack) > 0 {
		node = stack[len(stack)-1]
		stack = stack[:len(stack)-1]

		if node == nil {
			continue
		}
		result = append(result, node.Val)
		// 后进先出 - 先右子节点
		stack = append(stack, node.Right)
		stack = append(stack, node.Left)
	}

	return result
}

// 迭代实现 left -> root -> right; based on stack
func inorderTraversal(root *TreeNode) []int {
	var result = []int{}
	var stack = []*TreeNode{}
	var current = root

	for current != nil || len(stack) > 0 {
		// 压左子树入栈直到叶子节点
		for current != nil {
			stack = append(stack, current)
			current = current.Left
		}

		// meet 左叶子节点
		current = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		result = append(result, current.Val)
		// 处理右子节点
		current = current.Right
	}

	return result
}

// iteration: left -> right -> root
// with the help of stack and lastVisited ptr
func postorderTraversal(root *TreeNode) []int {
	var result = []int{}
	var current = root
	var lastVisited *TreeNode = nil
	var stack = []*TreeNode{}

	for current != nil || len(stack) > 0 {
		// put left node to stack
		for current != nil {
			stack = append(stack, current)
			current = current.Left
		}

		// meet left leaf node
		current = stack[len(stack)-1]

		// if right node was handled, print current.Val
		if current.Right == nil || current.Right == lastVisited {
			result = append(result, current.Val)
			lastVisited = current
			stack = stack[:len(stack)-1]
			current = nil
		} else {
			current = current.Right
		}
	}

	return result
}
