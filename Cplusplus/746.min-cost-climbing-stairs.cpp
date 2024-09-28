/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // 可以从0 或者 1号台阶开始
        // 每一次支付完成之后，可以选择爬 1 或 2个台阶
        int stepStamp = cost.size();
        // set
        vector<int> tempVec = vector<int>(2, 0);
        tempVec[0] = cost[0];
        tempVec[1] = cost[1];
        // regressive
        cost.push_back(0); // 最后楼顶台阶，费用为0
        for (int idx = 2; idx <= stepStamp; ++idx)
        {
            tempVec[idx % 2] = min(tempVec[0], tempVec[1]) + cost[idx];
        }

        return tempVec[(stepStamp) % 2];
    }
};
// @lc code=end
