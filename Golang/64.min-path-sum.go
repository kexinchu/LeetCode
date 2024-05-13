/*
 * @lc app=leetcode.cn id=64 lang=go
 *
 * [64] 最小路径和
 */

package leetcode

// @lc code=start
func minPathSum(grid [][]int) int {
	var m int = len(grid)
	var n int = len(grid[0])
	// initiate
	stepMap := make([][]int, m)
	for raw := 0; raw < m; raw += 1 {
		stepMap[raw] = make([]int, n)
		// first line
		if raw == 0 {
			stepMap[0][0] = grid[0][0]
			for col := 1; col < n; col += 1 {
				stepMap[0][col] = stepMap[0][col-1] + grid[0][col]
			}
		} else {
			stepMap[raw][0] = stepMap[raw-1][0] + grid[raw][0]
		}
	}
	// regressive
	for raw := 1; raw < m; raw += 1 {
		for col := 1; col < n; col += 1 {
			stepMap[raw][col] = min(stepMap[raw-1][col], stepMap[raw][col-1]) + grid[raw][col]
		}
	}

	return stepMap[m-1][n-1]
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// @lc code=end
