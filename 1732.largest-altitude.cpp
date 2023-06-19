/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */

// @lc code=start
class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int gainLen = gain.size();
        int highest = 0, high = 0;
        for (int idx = 0; idx < gainLen; ++idx)
        {
            high += gain[idx];
            if (highest < high)
                highest = high;
        }
        return highest;
    }
};
// @lc code=end
