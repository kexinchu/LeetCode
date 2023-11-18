/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    /**
     参考84题，这里可以先按行累计连续1的个数，得到n列 => 近似于柱状图
     再使用 单调栈 的方式对每一列处理，得到每一列中最大的面积
     然后取最大面积即可
     */
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rowNum = matrix.size();  // 行数
        int colNum = matrix[0].size(); // 列数
        if (rowNum == 0 || colNum == 0) return 0;

        // 辅助数组
        vector<vector<int> > tmpMatrix = vector<vector<int> >(rowNum, vector<int>(colNum, 0));
        // 按行 从左到右处理 累计 a[i][0] 到 a[i][j] 中与 a[i][j]连续的1个数
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < colNum; j++) {
                if (matrix[i][j] == '1') {
                    tmpMatrix[i][j] = ((j == 0)? 0 : tmpMatrix[i][j-1]) + 1;
                }
            }
        }


        // 按列处理，每一列当做一个柱状图计算
        // 注意：入栈能发现最左侧的边界，出栈则能表示最右侧的边界；可以结合使用，减少一次遍历
        int ret = 0;
        stack<int> left_mono_stack;
        vector<int> up, down;
        for (int j = 0; j < colNum; j++) {
            // 查找最up边界
            up = vector<int>(rowNum, 0);
            down = vector<int>(rowNum, 0);
            left_mono_stack = stack<int>();
            for (int i = 0; i < rowNum; i++) {
                while (!left_mono_stack.empty() && tmpMatrix[left_mono_stack.top()][j] >= tmpMatrix[i][j]) {
                    down[left_mono_stack.top()] = i;
                    left_mono_stack.pop();
                }
                up[i] = left_mono_stack.empty() ? -1 : left_mono_stack.top();
                left_mono_stack.push(i);
            }
            // 部分还在栈内的结果，需要统计到down数组中
            while (!left_mono_stack.empty()) {
                down[left_mono_stack.top()] = rowNum;
                left_mono_stack.pop();
            }

            // 计算最大 "面积"
            for (int idx = 0; idx < rowNum; idx++) {
                // cout << tmpMatrix[idx][j] << "\t" << down[idx] << "\t" << up[idx] << endl;
                int area = tmpMatrix[idx][j] * (down[idx] - up[idx] - 1);
                if (area > ret) ret = area;
            }
        }

        // 返回结果
        return ret;
    }
};
// @lc code=end

