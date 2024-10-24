/*
 * @lc app=leetcode.cn id=62 lang=go
 *
 * [62] 不同路径
 */

package main

// @lc code=start
func uniquePaths(m int, n int) int {
	// 初始化二维数组
	stepMap := make([][]int, m)
	for idx := 0; idx < m; idx += 1 {
		stepMap[idx] = make([]int, n)
		stepMap[idx][0] = 1
		if idx == 0 {
			for col := 1; col < n; col += 1 {
				stepMap[idx][col] = 1
			}
		}
	}

	// regressive
	for raw := 1; raw < m; raw += 1 {
		for col := 1; col < n; col += 1 {
			stepMap[raw][col] = stepMap[raw-1][col] + stepMap[raw][col-1]
		}
	}

	return stepMap[m-1][n-1]
}

// @lc code=end
