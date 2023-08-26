/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    /**
    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    You want to maximize your profit by choosing a single day to buy one stock 
    and choosing a different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. 
    If you cannot achieve any profit, return 0.
    */
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        // if the price is cheaper, buy it
        int maxProfit = 0, buyPos = 0;
        for (int dayIdx = 1; dayIdx < len; dayIdx++) {
            if (prices[dayIdx] < prices[buyPos]) {
                buyPos = dayIdx;
            } else {
                maxProfit = max(maxProfit, prices[dayIdx] - prices[buyPos]);
            }
        }
        return maxProfit;
    }
};
// @lc code=end

