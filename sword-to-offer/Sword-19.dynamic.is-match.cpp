// Ques: 19 正则表达式匹配
// Author: chukexin - 2022-08-07

// 动态规划
//    借助 二维数组 来存储状态

// 状态定义: 设动态规划矩阵 dp, dp[i][j] 代表字符串 s 的前 i 个字符和 p 的前 j 个字符能否匹配

// 转移方程:  需要注意, 由于 dp[0][0] 代表的是空字符的状态,  因此 dp[i][j] 对应的添加字符是 s[i-1] 和 p[j-1]
//   当 p[j - 1] = '*' 时:
//      注意: 所以 s[i-1] == p[j-2] || '.' == p[j-2] 时不一定至少出现1次, 也可能不出现; eg: "a" 和 "ab*a*"
//      if s[i - 1] == p[j - 2] || '.' == p[j-2] 时, '_*'有可能出现1次或更多次
//          dp[i][j] = dp[i-1][j] || dp[i][j-2]
//      if s[i - 1] != p[j - 2] && '.' != p[j-2] 时, '_*'必然只出现0次
//          dp[i][j] = dp[i][j-2]
//   当 p[j - 1] != '*' 时:
//      if s[i - 1] == p[j - 2] || '.' == p[j-2]
//          dp[i][j] = dp[i-1][j-1]

// 初始化:  需要先初始化 dp 矩阵首行, 以避免状态转移时索引越界
//      dp[0][0] = true:        代表两个空字符串能够匹配
//      dp[0][j] = dp[0][j - 2] 且 p[j - 1] = '*':  首行 s 为空字符串, 因此当 p 的偶数位为时才能够匹配
//                                                  (即让 p 的奇数位出现 0 次, 保持 p 是空字符串);
//                                                  因此, 循环遍历字符串 p , 步长为 2（即只看偶数位）

// 返回值:  dp 矩阵右下角字符, 代表字符串 s 和 p 能否匹配

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int slen = s.length() + 1, plen = p.length() + 1;
        vector<vector<bool> > dp(slen, vector<bool>(plen, false));
        dp[0][0] = true; // 初始化首行；表示s和p均为空的情况
        for (int j = 2; j < plen; j += 2)
        {                                               // 二维数组首行处理
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*'; // 状态转移
        }
        for (int i = 1; i < slen; i++)
        {
            for (int j = 1; j < plen; j++)
            {
                // 判断 p[j-1] 和 s[i-1]
                if (p[j - 1] == '*')
                {
                    // 注意"a" 和 "ab*a*" 是适配的；
                    // 所以 s[i-1] == p[j-2] || '.' == p[j-2] 时不一定至少出现1次，也可能不出现
                    if ('.' != p[j - 2] && s[i - 1] != p[j - 2])
                    {
                        // case 1, s[i-1] != p[j-2] && p[j-2] != '.' => '_*'出现0次
                        dp[i][j] = dp[i][j - 2];
                    }
                    else if (s[i - 1] == p[j - 2] || '.' == p[j - 2])
                    {
                        // case 2, '_*' 可能出现至少1次，也可能不出现
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                    }
                }
                else
                {
                    if (s[i - 1] == p[j - 1] || '.' == p[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[slen - 1][plen - 1];
    }
};
