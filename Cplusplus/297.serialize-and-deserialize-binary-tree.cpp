/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// // Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Codec
{
private:
    // create a tree node
    TreeNode *CreateNode(string &data)
    {
        if (data == "null")
            return NULL;
        int value = stoi(data);
        TreeNode *node = new TreeNode(value);
        return node;
    }

    // BFS
    TreeNode *BFS(vector<string> &dataArr)
    {
        if (dataArr.size() == 0)
            return NULL;
        int pos = 1;
        TreeNode *root = CreateNode(dataArr[0]);
        queue<TreeNode *> QT;
        QT.push(root);
        while (pos < dataArr.size())
        {
            TreeNode *cur = QT.front();
            if (cur == NULL)
            {
                // empty node
                QT.pop();
                continue;
            }
            cur->left = CreateNode(dataArr[pos]);
            pos += 1;
            QT.push(cur->left);
            if (pos < dataArr.size())
            {
                cur->right = CreateNode(dataArr[pos]);
                pos += 1;
                QT.push(cur->right);
            }
            QT.pop();
        }
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        // if root is NULL, will run DataArr[endpos] == "null", and then will occur DataArr[-1], Error.
        if (root == NULL)
            return "[]";
        // sequence traversal
        queue<TreeNode *> QT;
        vector<string> DataArr;
        QT.push(root);
        while (!QT.empty())
        {
            TreeNode *n = QT.front();
            // Note: 叶子节点 同层的其他节点可能会有子节点
            // NULL 的下游不写了
            if (n == NULL)
            {
                DataArr.push_back("null");
            }
            else
            {
                DataArr.push_back(to_string(n->val));
                // left + right
                QT.push(n->left);
                QT.push(n->right);
            }
            QT.pop();
        }
        // delete the last null
        int endpos = DataArr.size() - 1;
        while (DataArr[endpos] == "null")
        {
            endpos--;
        }
        // create the res string
        string res = "[";
        for (int i = 0; i <= endpos; ++i)
        {
            res += DataArr[i];
            if (i < endpos)
                res += ",";
        }
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        // if '[' 和 ']' in string, delete them
        // the string literals "[" that have the type const char[2];
        // and data[0] is pointers to their first characters of the type const char *.
        // So you are trying to compare a character returned by the expression str[0] with a pointer.
        // Can use data[0] == *"[" or data[0] == "["[0].
        if (data[0] == "["[0])
        {
            string subStr = data.substr(1, data.size() - 2);
            data = subStr;
        }
        // string -> array
        vector<string> DataArr;
        int startPos = 0;
        for (int i = 0; i < data.size(); ++i)
        {
            if (data[i] == ',')
            {
                DataArr.push_back(data.substr(startPos, i - startPos));
                startPos = i + 1;
            }
            if (i == data.size() - 1)
            {
                DataArr.push_back(data.substr(startPos, i - startPos + 1));
            }
        }
        // BFS
        return BFS(DataArr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

// int main()
// {
//     Codec CD;
//     TreeNode *root = CD.deserialize("1,2,3,null,null,4,5");
//     cout << CD.serialize(root) << endl;
//     root = CD.deserialize("");
//     cout << CD.serialize(root) << endl;
//     root = CD.deserialize("[]");
//     cout << CD.serialize(root) << endl;
//     root = CD.deserialize("1");
//     cout << CD.serialize(root) << endl;
//     root = CD.deserialize("1,2");
//     cout << CD.serialize(root) << endl;
//     root = CD.deserialize("1,2,3,6,null,4,5,null,null,7");
//     cout << "is 7 ? : " << root->right->left->left->val << endl;
//     cout << CD.serialize(root) << endl;
// }