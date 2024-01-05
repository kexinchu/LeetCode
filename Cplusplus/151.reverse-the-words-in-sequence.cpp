/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string message) {
        // reverse the total string message
        reverse(message.begin(), message.end());

        // reverse every words
        int start = 0, end = 0, meLen = message.length();
        int idx = 0;
        for (; start < meLen; start++) {
            // find head
            if (message[start] != ' ') {
                if (idx != 0) message[idx++] = ' ';
                
                // search for end index
                end = start;
                while(end < meLen && message[end] != ' ') message[idx++] = message[end++];

                // reverse the single word
                reverse(message.begin() + (idx - (end - start)), message.begin() + idx);

                start = end;
            }
        }
        // delete the following ' '
        message.erase(message.begin() + idx, message.end());
        return message;
    }
};
// @lc code=end

