/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
#include "limits.h"
using namespace std;

class Solution
{
    /**
     * 1, 忽略前导空格 和 后置字符串
     * 2, 检查符号"+"/"-"
     * 3, 判断数字范围: [-2^31, 2^31 - 1]; 并进行截断
     */

public:
    int myAtoi(string str)
    {
        int boundary = INT_MAX / 10;
        int sLen = str.length(), strIdx = 0;
        int sign = 1;
        long value = 0; // 这里可能会超过int的范围，所以这里用long
        // 忽略前置空格
        while (strIdx < sLen && str[strIdx] == ' ')
        {
            strIdx += 1;
        }
        // "+"/"-"
        if (str[strIdx] == '+' || str[strIdx] == '-')
        {
            if (str[strIdx] == '-')
                sign = -1;
            strIdx += 1;
        }
        // 忽略后置字符串 + 计算数据 + 截断
        while (strIdx < sLen && str[strIdx] >= '0' && str[strIdx] <= '9')
        {
            // 截断 (-2^31, 2^31 - 1); 而且 2^31 = 2147483648
            if (value > boundary || (value == boundary && str[strIdx] > '7'))
            {
                if (sign == -1)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
            // 累积数字
            value = value * 10 + (str[strIdx] - '0');
            strIdx += 1;
        }
        return sign * int(value);
    }
};
// @lc code=end
