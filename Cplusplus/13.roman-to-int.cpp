/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> Roman;
        Roman['I']=1;
        Roman['V']=5;
        Roman['X']=10;
        Roman['L']=50;
        Roman['C']=100;
        Roman['D']=500;
        Roman['M']=1000;

        int ans = 0;
        for (int idx=0; idx<s.length(); idx++) {
            if (Roman[s[idx]] < Roman[s[idx + 1]]) {
                ans -= Roman[s[idx]];
            } else {
                ans += Roman[s[idx]];
            }
        }

        return ans;
    }
};
// @lc code=end

