/*
 * @lc app=leetcode.cn id=63 lang=go
 *
 * [63] 不同路径 II
 */

package leetcode

// @lc code=start
func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	var m int = len(obstacleGrid)
	var n int = len(obstacleGrid[0])
	// initiate
	stepMap := make([][]int, m)
	for raw := 0; raw < m; raw += 1 {
		stepMap[raw] = make([]int, n)
	}

	// regressive
	for raw := 0; raw < m; raw += 1 {
		for col := 0; col < n; col += 1 {
			// met obstacle
			if obstacleGrid[raw][col] == 1 {
				stepMap[raw][col] = 0
			} else {
				// (0,0)
				if raw == 0 && col == 0 {
					stepMap[0][0] = 1
				} else if raw == 0 {
					stepMap[0][col] = stepMap[0][col-1]
				} else if col == 0 {
					stepMap[raw][0] = stepMap[raw-1][0]
				} else {
					// sum(left -> right, up -> down)
					stepMap[raw][col] = stepMap[raw-1][col] + stepMap[raw][col-1]
				}
			}
		}
	}

	return stepMap[m-1][n-1]
}

// @lc code=end
