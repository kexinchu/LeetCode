/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
private:
    void exchange(vector<int>& nums, int left , int right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }
public:
    int removeElement(vector<int>& nums, int val) {
        int numSize = nums.size(), left = 0, right = numSize - 1;
        if (numSize == 0) return 0;
        // move all occurences of val to the right
        while(left <= right) {
            // left from 0 to right
            while(left < right && nums[left] != val) {
                left += 1;
            }
            // right from n-1 to left
            while(right >= left && nums[right] == val) {
                right -= 1;
            }
            if (left < right) {
                exchange(nums, left, right);
                left += 1;
                right -= 1;
            } else {
                // if left == right; => left += 1 to break the cycle
                left += 1;
            }
        }
        // left points to the first element which equal to val => return left + 1
        // if nums don't contain val; left will equal to numSize => return min(left + 1, numSize)
        return min(left + 1, right + 1);
    }
};
// @lc code=end

