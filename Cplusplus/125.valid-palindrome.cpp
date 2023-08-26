/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
private:
    /**
    isalnum()：判断字符是否是字母或数字
    isalpha()：判断字符是否是字母
    isdigit()：判断字符是否是数字
    ispunct()：判断字符是否是标点符号
    isupper()：判断字符是否是大写字母
    islower()：判断字符是否是小写字母
    toupper()：转换为大写字母
    tolower()：转换为小写字母
    isxdigit()：判断字符是否是十六进制数
    */
    bool isEqual(char leftVal, char rightVal) {
        if (isupper(leftVal)) leftVal = tolower(leftVal);
        if (isupper(rightVal)) rightVal = tolower(rightVal);
        if (leftVal == rightVal) return true;
        else return false;
    }
public:
    // palindrome 回文
    bool isPalindrome(string s) {
        // after converting all uppercase letters into lowercase letters 
        // and removing all non-alphanumeric characters
        if (s.size() <= 1) return true;
        int posLeft = 0, posRight = s.size() - 1;
        while(posLeft < posRight) {
            if (!isalnum(s[posLeft])) {
                posLeft++;
                continue;
            }
            if (!isalnum(s[posRight])) {
                posRight--;
                continue;
            }
            if (isEqual(s[posLeft], s[posRight])) {
                posLeft++;
                posRight--;
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

