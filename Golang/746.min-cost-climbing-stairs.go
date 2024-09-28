/*
 * @lc app=leetcode.cn id=746 lang=go
 *
 * [746] 使用最小花费爬楼梯
 */
package leetcode

// @lc code=start
func minCostClimbingStairs(cost []int) int {
	var stepStamp int = len(cost)
	var tempVec = map[int]int{
		0: cost[0],
		1: cost[1],
	}
	var stepCost int = 0
	for idx := 2; idx <= stepStamp; idx += 1 {
		if idx == stepStamp {
			stepCost = 0
		} else {
			stepCost = cost[idx]
		}
		// golang 1.21 已经支持max, min函数
		tempVec[idx%2] = min(tempVec[0], tempVec[1]) + stepCost
	}

	return tempVec[stepStamp%2]
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// @lc code=end
