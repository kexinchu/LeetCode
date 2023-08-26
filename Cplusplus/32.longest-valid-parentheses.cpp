/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution
{
public:
    // old ans: Can not handle s = "(())("; my ans = 0, while correct ans = 4;
    // previous ans:
    // int longestValidParentheses(string s) {
    //     // 栈方法
    //     //    指针 left 指向连续有效的左边界(-1); right向右探索直到结束
    //     int length = s.size();
    //     int left = -1, right = 0, maxLen = 0;
    //     stack<int> sStk;
    //     while (right < length) {
    //         // 找到一段有效的结果(探索到右边界)
    //         if (sStk.empty() && s[right] == ")"[0] && right > left){
    //             maxLen = max(maxLen, right - left - 1);
    //             left = right;
    //         } else {
    //             // right 不断向右探索
    //             if (s[right] == "("[0]) sStk.push(right);
    //             else sStk.pop();
    //         }
    //         right += 1;
    //     }
    //     // 结束
    //     if (right > left){
    //         // Note1: parameter mismatch: size_t and int;
    //         // Used Error:
    //         // maxLen = max(maxLen, right - left - sStk.size() - 1);
    //         // Note2: this case will lead to error when s = "()(()"; (My ans = 4 while correct = 2)
    //         // Used Error:
    //         // maxLen = max(maxLen, right - left - static_cast<int>(sStk.size()) - 1);
    //         if (sStk.empty()) maxLen = max(maxLen, right - left - 1);
    //         else maxLen = max(maxLen, right - sStk.top() - 1);
    //     }
    //     return maxLen;
    // }

    int longestValidParentheses(string s)
    {
        // Note: https://biaodigit.github.io/LeetCode/0032/#%E8%A7%A3%E9%A2%98%E6%80%9D%E8%B7%AF
        int length = s.size(), maxLen = 0;
        stack<int> sStk;
        sStk.push(-1);
        for (int idx = 0; idx < length; ++idx)
        {
            if (s[idx] == "("[0])
                sStk.push(idx);
            else
            {
                sStk.pop();
                // if s = ")", sStk.empty() will be true;
                if (sStk.empty())
                    sStk.push(idx);
                // 尝试更新maxLen
                maxLen = max(maxLen, idx - sStk.top());
            }
        }
        return maxLen;
    }
};
// @lc code=end
