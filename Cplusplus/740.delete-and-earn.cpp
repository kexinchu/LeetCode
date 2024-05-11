/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 *
 * 借助一个 sum(x) 数组来辅助处理 - 类似与198.house-robber
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int n = nums.size();
        int max_value = *max_element(nums.begin(), nums.end());
        vector<int> sum_nums = vector<int>(max_value + 1, 0);
        vector<int> tempVec = vector<int>(max_value + 2, 0);

        // calc the sum(x)
        for (int idx = 0; idx < n; ++idx){
            sum_nums[nums[idx]] += nums[idx];
        }

        // regressive
        tempVec[1] = sum_nums[0];
        for (int idx = 2; idx <= max_value + 1; ++idx) {
            tempVec[idx] = max(tempVec[idx - 2] + sum_nums[idx - 1], tempVec[idx - 1]);
        }

        return tempVec[max_value + 1];
    }
};
// @lc code=end
