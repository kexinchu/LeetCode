/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// #include<iostream>
// #include<vector>
// using namespace std;

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rowSize = matrix.size(), colSize = matrix[0].size();
        if (rowSize == 0 || colSize == 0)
            return false;
        // search from matrix[0][colSize-1]
        int row = 0, col = colSize - 1;
        while (row < rowSize && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            if (matrix[row][col] < target)
            {
                row += 1;
            }
            else
            {
                col -= 1;
            }
        }
        return false;
    }
};
// @lc code=end

// int main() {
//     vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
//     int target = 3;
//     cout << Solution().searchMatrix(matrix, target) << endl;

//     matrix = {{}};
//     target = 10;
//     cout <<Solution().searchMatrix(matrix, target) << endl;

//     matrix = {{}, {}};
//     target = 10;
//     cout <<Solution().searchMatrix(matrix, target) << endl;

//     matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
//     target = 13;
//     cout <<Solution().searchMatrix(matrix, target) << endl;
//     return 0;
// }