/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    /**
     * 完全背包问题
     * dp[x] = min(dp[x], dp[x - coins[i]] + 1)
     * 可以从 x=0 向上检索： x -> x + coins[cpos]
     * */
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int num_coins = coins.size();
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int pos = 0; pos <= amount; pos += 1)
        {
            if (dp[pos] == -1)
            {
                continue;
            }
            // iteration for coins
            for (int cpos = 0; cpos < num_coins; cpos += 1)
            {
                if (coins[cpos] > amount || pos + coins[cpos] > amount)
                {
                    continue;
                }
                // pos -> pos + coins[cpos]
                if (dp[pos + coins[cpos]] == -1)
                {
                    dp[pos + coins[cpos]] = dp[pos] + 1;
                }
                else
                {
                    dp[pos + coins[cpos]] = min(dp[pos + coins[cpos]], dp[pos] + 1);
                }
            }
        }
        return dp[amount];
    }
};
// @lc code=end
