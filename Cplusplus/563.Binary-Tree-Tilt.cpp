/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
 */

// @lc code=start
// #include <iostream>
// using namespace std;

// Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
private:
    // return the sum
    int dfs(TreeNode *root, int &gradient)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            int left_res = dfs(root->left, gradient);
            int right_res = dfs(root->right, gradient);
            int sum = left_res + right_res + root->val;
            int grd = abs(left_res - right_res);
            gradient += grd;
            return sum;
        }
    }

public:
    int findTilt(TreeNode *root)
    {
        int gradient = 0;
        dfs(root, gradient);
        return gradient;
    }
};
// @lc code=end

// int mian()
// {
//     Solution sl;

//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     cout << sl.findTilt(root) << endl;

//     root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(9);
//     root->left->left = new TreeNode(3);
//     root->left->right = new TreeNode(5);
//     root->right->right = new TreeNode(7);
//     cout << sl.findTilt(root) << endl;

//     root = new TreeNode(21);
//     root->left = new TreeNode(7);
//     root->right = new TreeNode(14);
//     root->left->left = new TreeNode(1);
//     root->left->right = new TreeNode(1);
//     root->left->left->left = new TreeNode(3);
//     root->left->left->right = new TreeNode(3);
//     root->right->left = new TreeNode(2);
//     root->right->right = new TreeNode(2);
//     cout << sl.findTilt(root) << endl;
//     return 1;
// }