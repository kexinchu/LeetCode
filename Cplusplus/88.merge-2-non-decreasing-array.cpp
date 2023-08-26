/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // nums1 is empty
        if (m == 0) nums1 = nums2;
        else if (m != 0 && n != 0) {
            // both not empty
            int pos1 = m-1, pos2 = n-1;
            while(pos1 >= 0 && pos2 >= 0) {
                if (nums1[pos1] <= nums2[pos2]) {
                    nums1[pos1 + pos2 + 1] = nums2[pos2];
                    pos2 -= 1;
                } else {
                    nums1[pos1 + pos2 + 1] = nums1[pos1];
                    pos1 -= 1;
                }
            }
            // nums2 is not finished
            while(pos2 >= 0) {
                nums1[pos2] = nums2[pos2];
                pos2 -= 1;
            }
        }
    }
};
// @lc code=end

