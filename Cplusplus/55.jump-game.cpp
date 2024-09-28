/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
private:
    bool canJump(vector<int>& nums, int start, int end) {
        if (start == end) return true;
        if (start > end || nums[start] <= 0) return false;
        int maxSteps = min(nums[start], end);
        for (int idx = 1; idx <= maxSteps; idx++) {
            if (canJump(nums, start + idx, end)) {
                return true;
            }
        }
        return false;
    }
public:
    /**
    You are given an integer array nums. You are initially positioned at the array's first index, 
    and each element in the array represents your maximum jump length at that position.

    Return true if you can reach the last index, or false otherwise.
    */
    bool canJump(vector<int>& nums) {
        int numsLen = nums.size();
        // solution 1: use back trace; two much calculate and beyond the time limits
        // return canJump(nums, 0, numsLen-1);
        vector<bool> validStart(numsLen, false);
        validStart[numsLen - 1] = true;
        for (int idx = numsLen - 2; idx >= 0; idx--) {
            int maxSteps = min(nums[idx], (numsLen - idx - 1));
            bool isValid = false;
            int bias = 1;
            while((bias <= maxSteps) && !isValid){
                isValid = isValid || validStart[idx + bias];
                bias += 1;
            }
            validStart[idx] = isValid;
        }
        return validStart[0];
    }
};
// @lc code=end

