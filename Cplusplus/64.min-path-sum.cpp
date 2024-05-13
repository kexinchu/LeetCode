/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > stepMap = vector<vector<int> >(m, vector<int>(n, grid[0][0]));
        // set first raw and col
        for (int col = 1; col < n; ++col) {
            stepMap[0][col] = stepMap[0][col - 1] + grid[0][col];
        }
        for (int raw = 1; raw < m; ++raw) {
            stepMap[raw][0] = stepMap[raw - 1][0] + grid[raw][0];
        }

        // regressive
        for (int raw = 1; raw < m; ++raw) {
            for (int col = 1; col < n; ++col) {
                stepMap[raw][col] = min(stepMap[raw - 1][col], stepMap[raw][col - 1]) + grid[raw][col];
            }
        }

        return stepMap[m - 1][n - 1];
    }
};
// @lc code=end

