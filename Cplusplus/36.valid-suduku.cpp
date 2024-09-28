/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution
{
public:
    /**
    Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
    Note:
        A Sudoku board (partially filled) could be valid but is not necessarily solvable.
        Only the filled cells need to be validated according to the mentioned rules.
    */
    // 想复杂了，本题只是判断已有的结果是否满足数独的要求
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // init empty set
        vector<set<char>> rows, cols, subBoxes;
        for (int i = 0; i < 9; ++i)
        {
            rows.push_back({});
            cols.push_back({});
            subBoxes.push_back({});
        }
        // search
        int rowIdx = 0, colIdx = 0;
        while (rowIdx < 9 && colIdx < 9)
        {
            if (isdigit(board[rowIdx][colIdx]))
            {
                char val = board[rowIdx][colIdx];
                // rows
                if (rows[rowIdx].find(val) != rows[rowIdx].end())
                {
                    return false;
                }
                else
                {
                    rows[rowIdx].insert(val);
                }
                // cols
                if (cols[colIdx].find(val) != cols[colIdx].end())
                {
                    return false;
                }
                else
                {
                    cols[colIdx].insert(val);
                }
                // subBoxes
                if (subBoxes[(rowIdx / 3 * 3) + colIdx / 3].find(val) != subBoxes[(rowIdx / 3 * 3) + colIdx / 3].end())
                {
                    return false;
                }
                else
                {
                    subBoxes[(rowIdx / 3 * 3) + colIdx / 3].insert(val);
                }
            }
            // change the idx
            colIdx += 1;
            if (colIdx == 9)
            {
                colIdx = 0;
                rowIdx += 1;
            }
        }
        return true;
    }
};
// @lc code=end
