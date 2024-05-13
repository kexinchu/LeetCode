/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // dynamic programming
        vector<vector<int>> stepMap = vector<vector<int>>(m, vector<int>(n, 1));

        // regressive
        // record the number of path from (0,0) to (raw, col)
        for (int raw = 1; raw < m; ++raw)
        {
            for (int col = 1; col < n; ++col)
            {
                stepMap[raw][col] = stepMap[raw - 1][col] + stepMap[raw][col - 1];
            }
        }
        return stepMap[m - 1][n - 1];
    }
};
// @lc code=end
