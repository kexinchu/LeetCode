/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
    /**
     * Given a string s consisting of words and spaces, return the length of the last word in the string.

        A word is a maximal 
        substring
        consisting of non-space characters only.
    */
public:
    int lengthOfLastWord(string s) {
        int sLen = s.length();
        int pos = sLen - 1;
        // skip the spaces 
        while (pos >= 0 && s[pos] == ' ') {
            pos -= 1;
        }
        int length = 0;
        while (pos >= 0 && s[pos] != ' ') {
            pos -= 1;
            length += 1;
        }
        return length;
    }
};
// @lc code=end

