/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        // regressive
        vector<int> values = vector<int>(n + 1, 0);
        values[1] = nums[0];
        for (int idx = 2; idx <= n; ++idx)
        {
            values[idx] = max(values[idx - 2] + nums[idx - 1], values[idx - 1]);
        }
        return values[n];
    }
};
// @lc code=end
