/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int ratLen = ratings.size();
        if (ratLen == 0) return 0;
        // 初始化为全为1的数组
        vector<int> candies(ratLen, 1);
        // from left to right
        int numCandies = ratLen;
        for (int i=1; i<ratLen; i++) {
            if (ratings[i] > ratings[i-1]) {
                numCandies += (candies[i-1] + 1 - candies[i]);
                candies[i] = candies[i-1] + 1;
            }
        }
        // from right to left
        for (int i=ratLen-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) {
                numCandies += (candies[i+1] + 1 - candies[i]);
                candies[i] = candies[i+1] + 1;
            }
        }
        return numCandies;
    }
};
// @lc code=end

