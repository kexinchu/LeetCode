/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 *
 * 泰波那契序列 Tn 定义如下：
 *     T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int tribonacci(int n)
    {
        // Tn = T_{n-3} + T_{n-2} + T_{n-1}
        vector<int> tempVec = vector<int>(3, 0);
        tempVec[0] = 0;
        tempVec[1] = 1;
        tempVec[2] = 1;
        // regression
        for (int idx = 3; idx <= n; ++idx)
        {
            tempVec[idx % 3] = tempVec[0] + tempVec[1] + tempVec[2];
        }
        return tempVec[n % 3];
    }
};
// @lc code=end
