/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // depth
    int min_depth = INT_MAX;

    void dfs(TreeNode* root, int depth) {
        if (root->left == NULL && root->right == NULL && min_depth > depth) {
            min_depth = depth;
        }
        if (root->left != NULL && depth < min_depth) dfs(root->left, depth + 1);
        if (root->right != NULL && depth < min_depth) dfs(root->right, depth + 1);
    }
public:
    int minDepth(TreeNode* root) {
        // meet the first leaf node => return
        if (root == NULL) return 0;
        dfs(root, 1);
        return min_depth;
    }
};
// @lc code=end

