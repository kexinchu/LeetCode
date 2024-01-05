/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [2870] 使数组为空的最少操作次数
 */

// @lc code=start
class Solution
{
    /**
     * 优先删除 3 个元素, 剩下1个, 改最后两步为2，2； 剩下2个，直接删尽
     */
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int numSteps = 0, numLen = nums.size();
        // get the num of elements
        for (int id = 0; id < numLen; id++)
        {
            if (mp.find(nums[id]) == mp.end())
                mp.insert(make_pair(nums[id], 1));
            else
                mp[nums[id]] += 1;
        }
        // count times
        unordered_map<int, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            // single element, can not be deleted
            if (it->second == 1)
            {
                numSteps = -1;
                break;
            }
            numSteps += (it->second / 3);
            if ((it->second % 3) > 0)
                numSteps += 1;
        }
        return numSteps;
    }
};
// @lc code=end
