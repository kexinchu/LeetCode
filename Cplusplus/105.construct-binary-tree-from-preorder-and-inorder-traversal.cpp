#include<map>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    /**
    尝试递归去解决：前序遍历确定root，并通过root在中旭遍历中切分左子树和右子树；
    */
private:
    std::map<int, int> index;

    TreeNode* buildTreeCircle(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        // find the root index in inorder list
        int rootIdxIn = index[preorder[preStart]];
        // left sub tree size from inorder vector
        int leftSubTreeSize = rootIdxIn - inStart;
        
        // handle the left sub tree
        if (leftSubTreeSize > 0) root->left = buildTreeCircle(preorder, inorder, preStart+1, preStart + leftSubTreeSize, inStart, rootIdxIn-1);
        // handle the right sub tree
        if (preStart + leftSubTreeSize < preEnd) root->right = buildTreeCircle(preorder, inorder, preStart + leftSubTreeSize + 1, preEnd, rootIdxIn+1, inEnd);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preLen = preorder.size();
        int inLen = preorder.size();
        if (preLen == 0 || preLen != inLen) return nullptr;

        // 构建map, 快速查找根节点;
        for (int idx = 0; idx < inLen; idx++) {
            index[inorder[idx]] = idx;
        }

        // 递归处理
        return buildTreeCircle(preorder, inorder, 0, preLen-1, 0, inLen-1);
    }
};