/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
private:
    // each unique element appears at most K times (K >= 1)
    int removeDuplicates(vector<int>& nums, int K) {
        int numLen = nums.size();
        if (numLen <= K) return numLen;
        // use two points
        int slow = 0, fast = K;
        while (fast < numLen) {
            if (nums[fast] != nums[slow]) {
                nums[slow + K] = nums[fast];
                slow += 1;
            }
            fast += 1;
        }
        return slow + K;
    }
public:
    // each unique element appears at most twice
    int removeDuplicates(vector<int>& nums) {
        return removeDuplicates(nums, 2);
    }
};
// @lc code=end

