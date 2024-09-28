/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.size() < needle.size())
            return -1;
        int start = 0, needPos = 0;
        while (start <= haystack.size() - needle.size())
        {
            if (haystack[start] == needle[needPos])
            {
                int i = 0;
                while (i < needle.size() && haystack[start + i] == needle[needPos + i])
                {
                    i += 1;
                }
                if (i == needle.size())
                    return start;
            }
            start += 1;
        }
        return -1;
    }
};
// @lc code=end
