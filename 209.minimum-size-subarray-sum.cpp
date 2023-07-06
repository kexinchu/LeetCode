/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution
{
public:
    // Given an array of positive integers nums and a positive integer target,
    // return the minimal length of a subarray whose sum is greater than or equal to target.
    // If there is no such subarray, return 0 instead.
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int minLen = 0;
        if (nums.size() == 0)
            return minLen;
        int leftPos = 0, rightPos = 0, sum = 0;
        while (rightPos < nums.size())
        {
            // already meet the target
            sum += nums[rightPos];
            if (sum >= target)
            {
                // try abandon left elements
                while (sum >= target)
                {
                    sum -= nums[leftPos];
                    leftPos++;
                }
                leftPos--;
                sum += nums[leftPos];
                if (minLen == 0 || minLen > (rightPos - leftPos + 1))
                    minLen = rightPos - leftPos + 1;
            }
            rightPos++;
        }
        return minLen;
    }
};
// @lc code=end
