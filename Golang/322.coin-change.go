/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

package leetcode

func coinChange(coins []int, amount int) int {
	var num_coins int = len(coins)
	dp := make([]int, amount+1)
	// 初始化dp
	for pos := 1; pos <= amount; pos += 1 {
		dp[pos] = -1
	}
	for pos := 0; pos <= amount; pos += 1 {
		if dp[pos] == -1 {
			continue
		}
		// 向后search
		for j := 0; j < num_coins; j += 1 {
			if pos+coins[j] > amount {
				continue
			}
			if dp[pos+coins[j]] == -1 {
				dp[pos+coins[j]] = dp[pos] + 1
			} else {
				dp[pos+coins[j]] = min(dp[pos+coins[j]], dp[pos]+1)
			}
		}
	}

	return dp[amount]
}

// @lc code=end
