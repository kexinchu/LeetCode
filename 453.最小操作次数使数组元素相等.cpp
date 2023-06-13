/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        // add 1 for n-1 elements means one element sub 1;
        // so this question equals to all element = min(nums)
        // --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
        // find the min element
        if (nums.size() == 0)
            return 0;
        int minElement = nums[0], numMoves = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < minElement)
            {
                minElement = nums[i];
            }
        }
        // calc number of subs
        for (int i = 0; i < nums.size(); ++i)
        {
            numMoves += (nums[i] - minElement);
        }
        return numMoves;
    }
};
// @lc code=end
