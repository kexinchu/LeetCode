package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func levelOrder(root *TreeNode) [][]int {
	var result = [][]int{}
	if root == nil {
		return result
	}

	// init two queue
	var left_queue = []*TreeNode{root}
	var right_queue = []*TreeNode{}

	for len(left_queue) > 0 || len(right_queue) > 0 {
		var tmp_res = []int{}
		var node *TreeNode
		// print value from left to right
		if len(left_queue) > 0 {
			for len(left_queue) > 0 {
				node = left_queue[0]
				left_queue = left_queue[1:] // slice

				tmp_res = append(tmp_res, node.Val)
				if node.Left != nil {
					right_queue = append(right_queue, node.Left)
				}
				if node.Right != nil {
					right_queue = append(right_queue, node.Right)
				}
			}
		} else {
			for len(right_queue) > 0 {
				node = right_queue[0]
				right_queue = right_queue[1:] // slice

				tmp_res = append(tmp_res, node.Val)
				if node.Left != nil {
					left_queue = append(left_queue, node.Left)
				}
				if node.Right != nil {
					left_queue = append(left_queue, node.Right)
				}
			}
		}
		result = append(result, tmp_res)
	}

	// for 107.binary-tree-level-order-traversal-ii; need return result from leaf to root
	// second step: reverse the order
	// res_len := len(result)
	// for i := 0; i < res_len/2; i++ {
	//	  result[i], result[res_len-1-i] = result[res_len-1-i], result[i]
	// }

	return result
}
