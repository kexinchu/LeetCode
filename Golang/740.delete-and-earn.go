/*
 * @lc app=leetcode.cn id=740 lang=go
 *
 * [740] 删除并获得点数
 *
 * 借助一个 sum(x) 数组来辅助处理 - 类似与198.house-robber
 */

package leetcode

// @lc code=start
func deleteAndEarn(nums []int) int {
    maxVal := 0
    for _, val := range nums {
        maxVal = max(maxVal, val)
    }

    sum_nums := make([]int, maxVal+1)
    for _, val := range nums {
        sum_nums[val] += val
    }

    return rob(sum_nums)
}

func rob(nums []int) int {
    first, second := nums[0], max(nums[0], nums[1])
    for idx := 2; idx < len(nums); idx += 1 {
        first, second = second, max(first + nums[idx], second)
    }
    return second
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
// @lc code=end
