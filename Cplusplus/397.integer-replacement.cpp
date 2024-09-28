/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

// #include <iostream>
// using namespace std;

// @lc code=start
class Solution
{
private:
    enum
    {
        MAXINT = numeric_limits<int>::max(),
        HALFMAXINT = 1 << 30,
    };

    int
    dfs(int cur)
    {
        if (cur == 1)
            return 0;
        else if (cur % 2 == 0)
            return dfs(cur / 2) + 1;
        else if (cur == MAXINT)
            return dfs(HALFMAXINT) + 2;
        else
            return min(dfs(cur - 1), dfs(cur + 1)) + 1;
    }

public:
    int integerReplacement(int n)
    {
        return dfs(n);
    }
};
// @lc code=end

// int main()
// {
//     Solution sl;
//     cout << "int: \t 所占字节数: " << sizeof(int) << "\t最大值：" << (numeric_limits<int>::max)() << "\t最小值：" << (numeric_limits<int>::min)() << endl;
//     // cout << "n = 8; steps = " << sl.integerReplacement(8) << endl;           // 3
//     // cout << "n = 7; steps = " << sl.integerReplacement(7) << endl;           // 4
//     // cout << "n = 4; steps = " << sl.integerReplacement(4) << endl;           // 2
//     cout << "n = 2147483647; steps = " << sl.integerReplacement(2147483647) << endl; // 32
// }