/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    void backTrace(vector<string>& combinations, 
                   unordered_map<char, string>& phoneMap, 
                   string combination, 
                   string& digits, 
                   int pos) {
        // search one value
        if (pos == digits.size()) {
            combinations.push_back(combination);
        } else {
            // keep searching -> only contains 2-9; so don't need to judge case "1"
            // if (phoneMap.find(digits[pos]) == phoneMap.end()) {
            //     backTrace(combinations, phoneMap, combination, digits, pos+1);
            // } 
            string letters = phoneMap.at(digits[pos]);
            for (int i = 0; i < letters.size(); i++) {
                combination.push_back(letters[i]);
                backTrace(combinations, phoneMap, combination, digits, pos+1);
                combination.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.empty()) return combinations;

        unordered_map<char, string> phoneMap = {
            { '2', "abc" },
            { '3', "edf" },
            { '4', "ghi" },
            { '5', "jkl" },
            { '6', "mno" },
            { '7', "pqrs" },
            { '8', "tuv" },
            { '9', "wxyz" },
        };
        string combination = "";
        backTrace(combinations, phoneMap, combination, digits, 0);
        return combinations;
    }
};
// @lc code=end

