/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
 *
 * 思路：统计<k的字符，然后按照这些字符split字符串，统计最长子串的长度
 */

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// @lc code=start
class Solution
{
private:
    // split the string into k substring and count the length of each substring
    int dfs(const string &s, int k, int left, int right)
    {
        // count all elements
        int cnt[26] = {0};
        for (int i = left; i < right; i++)
        {
            cnt[s[i] - 'a'] += 1;
        }
        // select the split element
        char split = 0;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] > 0 && cnt[i] < k)
            {
                split = i + 'a';
                break;
            }
        }
        // if no element < k
        if (split == 0)
        {
            return right - left;
        }
        // split the string s
        int idx_left = left, idx_right = left;
        int max_ = 0;
        while (idx_right < right)
        {
            if (s[idx_right] == split)
            {
                max_ = max(max_, dfs(s, k, idx_left, idx_right));
                idx_left = idx_right + 1;
            }
            idx_right += 1;
        }
        if (idx_left < idx_right)
        {
            max_ = max(max_, dfs(s, k, idx_left, right));
        }
        return max_;
    }

public:
    int longestSubstring(string s, int k)
    {
        return dfs(s, k, 0, s.length());
    }
};
// @lc code=end

// int main()
// {
//     Solution sl;
//     string s = "aaabb";
//     int k = 3;
//     cout << sl.longestSubstring(s, k) << endl;
//     s = "ababbc";
//     k = 2;
//     cout << sl.longestSubstring(s, k) << endl;
//     s = "aaaabcccdeeeee";
//     k = 3;
//     cout << sl.longestSubstring(s, k) << endl;
//     return 0;
// }
