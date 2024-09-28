/*
 * @lc app=leetcode.cn id=198 lang=go
 *
 * [198] 打家劫舍
 */
package leetcode

// @lc code=start
func rob(nums []int) int {
	n := len(nums)
	values := map[int]int{
		0: 0,
		1: nums[0],
	}

	for idx := 2; idx <= n; idx += 1 {
		values[idx] = max(values[idx-1], values[idx-2]+nums[idx-1])
	}

	return values[n]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end
