/*
 * @lc app=leetcode.cn id=741 lang=cpp
 *
 * [741] 摘樱桃
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    /*
    1, 经典DP问题
    2, 从位置 (0, 0) 出发, 到达 (n - 1, n - 1), 并最后返回 (0, 0)  =>  等效于两个人同时从(0,0)出发, 且每个格子的樱桃只能获取1次，到达(n-1, n-1) 所能获得樱桃最大值
    3, 考虑到A,B同时从(0,0)出发，A，B 只会同时踩到同一个格子
    */
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<vector<int>>> f(2 * n - 1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        f[0][0][0] = grid[0][0];
        for (int k = 1; k < 2 * n - 1; k++)
        {
            for (int x1 = max(k - n + 1, 0); x1 <= min(k, n - 1); ++x1)
            {
                // 判断是否是"荆棘" => 如果是，直接置为 INT_MIN
                int y1 = k - x1;
                if (grid[x1][y1] == -1)
                {
                    continue;
                }
                for (int x2 = x1; x2 <= min(k, n - 1); ++x2)
                {
                    // 判断荆棘
                    int y2 = k - x2;
                    if (grid[x2][y2] == -1)
                    {
                        continue;
                    }
                    // 计算得到f[k][x1][x2]
                    int res = f[k - 1][x1][x2]; // 都往右
                    if (x1)
                    {
                        res = max(res, f[k - 1][x1 - 1][x2]); // 往下，往右
                    }
                    if (x2)
                    {
                        res = max(res, f[k - 1][x1][x2 - 1]); // 往右，往下
                    }
                    if (x1 && x2)
                    {
                        res = max(res, f[k - 1][x1 - 1][x2 - 1]); // 都往下
                    }
                    // add grid[x1][y1] 和 grid[x2][y2]
                    res += grid[x1][y1];
                    if (x1 != x2)
                    { // 避免重复摘同一个
                        res += grid[x2][y2];
                    }
                    f[k][x1][x2] = res;
                }
            }
        }
        return max(f[2 * n - 2][n - 1][n - 1], 0);
    }
};
// @lc code=end
