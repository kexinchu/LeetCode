/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
// #include <iostream>
// #include <string>
// #include <map> // dict in python
// #include <queue>
// using namespace std;

// dynamic programming
class Solution
{
private:
    // 中心裂变法
    bool checkPalindrome(string val)
    {
        int val_len = val.size();
        // single element
        if (val_len == 1)
            return true;
        // val[1:n-1] 已经确定是回文，才会执行此函数
        if (val[0] == val[val_len - 1])
            return true;
        return false;
    }

public:
    string longestPalindrome(string s)
    {
        int str_len = s.size();
        if (str_len <= 1)
            return s;
        // core : 连续的element
        int core_left = 0, core_right = 1;
        string res = "";
        while (core_left < str_len)
        {
            // find a core
            while ((s[core_left] == s[core_right]) && (core_right < str_len))
            {
                core_right += 1;
            }
            // string sub_str = s.substr(core_left, core_right - core_left); // one core (由连续的相同字符组成)
            // 中心裂变
            int pd_left = core_left, pd_right = core_right;
            while (pd_left >= 0 && pd_right <= str_len && checkPalindrome(s.substr(pd_left, pd_right - pd_left)))
            {
                if (res.size() < (pd_right - pd_left))
                    res = s.substr(pd_left, pd_right - pd_left);
                pd_left -= 1;
                pd_right += 1;
            }

            // find next core;
            core_left = core_right;
            core_right += 1;
        }
        return res;
    }
};
// @lc code=end

// int main()
// {
//     Solution sl;
//     string s = "babad";
//     cout << sl.longestPalindrome(s) << endl;
//     s = "abbcccbbbcaaccbababcbcabca";
//     cout << sl.longestPalindrome(s) << endl;
//     s = "";
//     cout << sl.longestPalindrome(s) << endl;
//     s = "a";
//     cout << sl.longestPalindrome(s) << endl;
//     s = "cbbd";
//     cout << sl.longestPalindrome(s) << endl;
//     s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
//     cout << sl.longestPalindrome(s) << endl;
//     s = "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc";
//     cout << sl.longestPalindrome(s) << endl;
//     return 0;
// }
