#include <string>
#include <queue>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
    // 序列化二叉树的格式可以参考：https://support.leetcode-cn.com/hc/kb/article/1567641/
    //     按层序遍历二叉树
    // 反序列化:
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        // BFS 层序遍历
        //     1, 保留节点的空子节点
        //     2, 删除string末尾的null
        if (NULL == root)
        {
            return "[]";
        }
        vector<TreeNode *> nodeVec; // 存储BFS的节点
        queue<TreeNode *> nodeQue;
        nodeQue.push(root);
        TreeNode *tmp;
        // BFS
        while (!nodeQue.empty())
        {
            tmp = nodeQue.front();
            nodeVec.push_back(tmp);
            if (tmp != NULL)
            {
                nodeQue.push(tmp->left);
                nodeQue.push(tmp->right);
            }
            nodeQue.pop();
        }
        // 删除结尾的NULL节点，保证string最后一个元素不为null
        while (NULL == nodeVec.back())
        {
            nodeVec.pop_back();
        }
        // string 序列化结果 + 迭代器(it是指针)
        // 注意 int 4个字节，char 1个字节，所以要用string
        string strRes = "[";
        for (vector<TreeNode *>::iterator it = nodeVec.begin(); it != nodeVec.end(); ++it)
        {
            if (nodeVec.begin() != it)
            {
                strRes += ",";
            }
            if (NULL != *it)
            {
                strRes += to_string((*it)->val);
            }
            else
            {
                strRes += '#';
            }
        }
        strRes.push_back(']');
        return strRes;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        // 将data分割成节点值; 并令root为第一个值对应的节点。
        // 将root加入队列; 每当队列非空：
        //      令level_size等于当前队列节点个数。
        //      执行level_size次，从队列中取出节点，并将接下来两个节点值连接到节点上。
        // 返回root
        if ("[]" == data)
            return NULL;
        // 分割节点值
        vector<string> strVec = split(data.substr(1, data.size() - 2)); // 子串 + split
        int len = strVec.size(), idx = 1;
        TreeNode *root = new TreeNode(stoi(strVec[0])), *tmp; // char to int
        queue<TreeNode *> nodeQue;
        nodeQue.push(root);
        while (!nodeQue.empty())
        {
            tmp = nodeQue.front();
            if (idx < len)
            {
                if ("#" != strVec[idx])
                {
                    tmp->left = new TreeNode(stoi(strVec[idx]));
                    nodeQue.push(tmp->left);
                }
                idx += 1;
            }
            if (idx < len)
            {
                if ("#" != strVec[idx])
                {
                    tmp->right = new TreeNode(stoi(strVec[idx]));
                    nodeQue.push(tmp->right);
                }
                idx += 1;
            }
            nodeQue.pop();
        }
        return root;
    }

    vector<string> split(const string &s)
    {
        string temp = "";
        vector<string> result;
        for (char c : s) // C++ 11 支持
        {
            if (c == ',')
            {
                result.push_back(temp);
                temp = "";
            }
            else
            {
                temp += c;
            }
        }
        result.push_back(temp);
        return result;
    }
};
