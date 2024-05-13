/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // dynamic programming
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> stepMap = vector<vector<int>>(m, vector<int>(n, 0));

        // regressive
        // record the number of path from (0,0) to (raw, col)
        for (int raw = 0; raw < m; ++raw) {
            for (int col = 0; col < n; ++col) {
                if (obstacleGrid[raw][col] == 1) {
                    // meet a obsticle, fail
                    stepMap[raw][col] = 0;
                } else {
                    if (raw == 0 && col == 0) {
                        stepMap[0][0] = 1;
                    } else if (raw == 0) {
                        // first raw
                        stepMap[0][col] = stepMap[0][col - 1];
                    } else if (col == 0) {
                        // first col
                        stepMap[raw][0] = stepMap[raw - 1][0]; 
                    } else {
                        // sum(left->right, up->down)
                        stepMap[raw][col] = stepMap[raw - 1][col] + stepMap[raw][col - 1];
                    }
                }
            }
        }
        
        return stepMap[m - 1][n - 1];
    }
};
// @lc code=end

