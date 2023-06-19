/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// #include <iostream>
// #include <string>
// using namespace std;

// @lc code=start
class Solution
{
private:
    bool isEqual(string &s, string &p, int strPos, int pPos)
    {
        if (p[pPos] == "."[0])
            return true;
        if (p[pPos] == s[strPos])
            return true;
        return false;
    }

    bool isMatchPa(string &s, string &p, int strPos, int pPos, int &strLen, int &pLen)
    {
        // reach the end of s
        // Note1: may strPos == strLen; while p[pPos:] = ".*.*", this case need be judged as true;
        // Used be:
        // if (strPos == strLen && pPos == pLen)
        //     return true;
        if (strPos == strLen)
        {
            if (pPos == pLen)
                return true;
            else if (pPos < pLen - 1 && p[pPos + 1] == "*"[0])
                return isMatchPa(s, p, strPos, pPos + 2, strLen, pLen);
            else
                return false;
        }
        // check *
        if (pPos < pLen - 1 && p[pPos + 1] == "*"[0])
        {
            // p[Pos] can exist anytimes，even Zero
            if (isEqual(s, p, strPos, pPos))
                // Note2: if s = "aaa", p = "a*a"; the old solution can not satisfy this condition
                // used be:
                // return isMatchPa(s, p, strPos + 1, pPos, strLen, pLen)
                return isMatchPa(s, p, strPos + 1, pPos, strLen, pLen) || isMatchPa(s, p, strPos, pPos + 2, strLen, pLen);
            else
                // Zero
                return isMatchPa(s, p, strPos, pPos + 2, strLen, pLen);
        }
        else if (isEqual(s, p, strPos, pPos))
        {
            return isMatchPa(s, p, strPos + 1, pPos + 1, strLen, pLen);
        }
        return false;
    }

public:
    bool isMatch(string s, string p)
    {
        int strLen = s.size(), pLen = p.size();
        return isMatchPa(s, p, 0, 0, strLen, pLen);
    }
};
// @lc code=end

// int main() {
//     string s = "aa", p = "a";
//     cout << Solution().isMatch(s,p) << endl;
//     s = "aa";
//     p = "a*";
//     cout << Solution().isMatch(s,p) << endl;
//     s = "abc";
//     p = ".*";
//     cout <<Solution().isMatch(s,p) << endl;
//     s = "";
//     cout <<Solution().isMatch(s,p) << endl;
//     s = "abc";
//     p = ".*.*.*";
//     cout << Solution().isMatch(s,p) << endl;
//     s = "abc";
//     p = ".*.*.*.";
//     cout << Solution().isMatch(s,p) << endl;
// }