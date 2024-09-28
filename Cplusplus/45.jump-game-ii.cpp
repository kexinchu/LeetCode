/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    /**
    You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

    Each element nums[i] represents the maximum length of a forward jump from index i. 
    In other words, if you are at nums[i], you can jump to any nums[i + j] where:
        0 <= j <= nums[i] and
        i + j < n
    Return the minimum number of jumps to reach nums[n - 1]. 
    The test cases are generated such that you can reach nums[n - 1].
    */
    // reference to the question 55.jump game
    int jump(vector<int>& nums) {
        int numsLen = nums.size();
        vector<int> numSteps(numsLen, 0);
        for (int idx = numsLen - 2; idx >= 0; idx--) {
            int maxSteps = min(nums[idx], (numsLen - idx - 1));
            int steps = numSteps[idx + 1] + 1;
            for(int bias = 2; bias <= maxSteps; bias++) {
                steps = min(steps, numSteps[idx + bias] + 1);
            }
            numSteps[idx] = steps;
        }
        return numSteps[0];
    }
};
// @lc code=end

