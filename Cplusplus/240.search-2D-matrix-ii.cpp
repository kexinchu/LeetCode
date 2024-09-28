/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int rowSize =  matrix.size(), colSize = matrix[0].size();
        if (rowSize == 0 || colSize == 0) return false;
        // search from matrix[0][colSize-1]
        int row = 0, col = colSize - 1;
        while(row < rowSize && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }
            if (matrix[row][col] < target) {
                row+=1;
            } else {
                col-=1;
            }
        }
        return false; 
    }
};
// @lc code=end

