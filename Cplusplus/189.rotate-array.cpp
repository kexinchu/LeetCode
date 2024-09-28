/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
private:
    void reverse(vector<int>& nums, int leftPos, int rightPos) {
        int lPos = leftPos, rPos = rightPos;
        while (lPos < rPos)  {
            int tmp = nums[lPos];
            nums[lPos] = nums[rPos];
            nums[rPos] = tmp;
            lPos += 1;
            rPos -= 1;
        }
    }
public:
    // every step move the last element to the beginning
    // move k steps
    void rotate(vector<int>& nums, int k) {
        int numsLen = nums.size();
        int validK = k % numsLen;
        if (validK == 0) return;
        // reverse first time
        reverse(nums, 0, numsLen-1);
        // reverse twise
        reverse(nums, 0, validK - 1);
        reverse(nums, validK, numsLen - 1);
    }
};
// @lc code=end

