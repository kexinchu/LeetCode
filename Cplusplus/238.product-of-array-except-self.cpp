/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    // solution1 :
    //      use arry suffix product and prefix product
    //      O(3*n) , but need 2*n additional space
    // solution2 :
    //      only use prefix product
    vector<int> productExceptSelf(vector<int>& nums) {
        int Len = nums.size();
        vector<int> prefixProduct(Len, 1);
        if (Len == 0) return prefixProduct;

        // calculate prefix
        for(int idx=1; idx < Len; idx++) {
            prefixProduct[idx] = prefixProduct[idx-1] * nums[idx-1];
        }
        // calculate nums
        int suffix = 1;
        for (int idx = Len-2; idx >= 0; idx--) {
            suffix = suffix * nums[idx + 1];
            prefixProduct[idx] = prefixProduct[idx] * suffix;
        }
        return prefixProduct;
    }
};
// @lc code=end

