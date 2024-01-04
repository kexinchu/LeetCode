/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
 */

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

// @lc code=start
class Solution
{
    /**
     * 位运算 + 遍历查找
     */
public:
    int maximumRows(vector<vector<int>> &matrix, int numSelect)
    {
        int rowNum = matrix.size(), colNum = matrix[0].size(), tmpVal = 0, maxRows = 0;
        // vector -> binary num
        vector<int> rows;
        for (int i = 0; i < rowNum; ++i)
        {
            tmpVal = 0;
            for (int j = 0; j < colNum; ++j)
            {
                tmpVal = (tmpVal << 1) + matrix[i][j];
            }
            rows.push_back(tmpVal);
        }
        // 遍历查询
        for (uint mask = 1; mask < (1 << colNum); ++mask)
        {
            if (__builtin_popcount(mask) != numSelect)
                continue;
            // 行数比较
            tmpVal = 0;
            for (int i = 0; i < rowNum; ++i)
            {
                if ((rows[i] & (~mask)) == 0)
                {
                    tmpVal += 1;
                }
            }
            if (maxRows < tmpVal)
                maxRows = tmpVal;
        }
        return maxRows;
    }
};
// @lc code=end
