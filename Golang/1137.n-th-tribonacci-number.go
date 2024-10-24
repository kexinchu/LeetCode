/*
 * @lc app=leetcode.cn id=1137 lang=gp
 *
 * [1137] 第 N 个泰波那契数
 *
 * 泰波那契序列 Tn 定义如下：
 *     T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2
 */
package main

func tribonacci(n int) int {
	var tempVec = map[int]int{
		0: 0,
		1: 1,
		2: 1,
	}
	// regressive_tribonacci
	for idx := 3; idx <= n; idx += 1 {
		tempVec[idx%3] = tempVec[0] + tempVec[1] + tempVec[2]
	}
	return tempVec[n%3]
}

// @lc code=end
