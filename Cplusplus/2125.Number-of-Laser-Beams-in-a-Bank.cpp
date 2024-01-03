/*
 * @lc app=leetcode.cn id=2125 lang=cpp
 *
 * [2125] 银行中的激光束数量
 */
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int numBeams = 0, priorDetect = 0, newDetect = 0, bankLen = bank.size();
        for (int i = 0; i < bankLen; ++i) {
            int strLen = bank[i].length();
            for (int j = 0; j < strLen; ++j) {
                if (bank[i][j] == '1') {
                    newDetect += 1;
                }
            }
            if (newDetect != 0) {
                numBeams += (priorDetect * newDetect);
                priorDetect = newDetect;
                newDetect = 0;
            }
        }
        return numBeams;
    }
};
// @lc code=end

