/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution
{
    /**
    Solution 1: sorting + return the middle value
    Solution 2: hash map count the occurrences, return the biggest
    Solution 3: Moore Voting Algorithm (if same element, count +=1, else count -=1, return the final candidate)
    */
public:
    int majorityElement(vector<int> &nums)
    {
        // Moore Voting algorithm
        if (nums.empty())
            return 0;
        int candidate, count = 0;
        for (int pos = 0; pos < nums.size(); pos++)
        {
            if (count == 0)
            {
                candidate = nums[pos];
                count += 1;
            }
            else
            {
                if (candidate == nums[pos])
                    count += 1;
                else
                    count -= 1;
            }
        }
        return candidate;
    }
};
// @lc code=end

