/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
 */

// @lc code=start
#include <stack>
using namespace std;

Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//
class Solution
{
    /**
     * Use Stack
     *
     */
public:
    ListNode *removeNodes(ListNode *head)
    {
        stack<ListNode *> tmpStk;
        ListNode *curP = head, *newHead = nullptr, *tmpNode = nullptr;
        // 遍历
        while (curP != nullptr)
        {
            while (!tmpStk.empty() && tmpStk.top()->val < curP->val)
            {
                tmpStk.pop();
            }
            tmpStk.push(curP);
            curP = curP->next;
        }
        // 生成新的list
        while (!tmpStk.empty())
        {
            tmpNode = tmpStk.top();
            if (tmpNode != nullptr)
            {
                tmpNode->next = newHead;
                newHead = tmpNode;
            }
            tmpStk.pop();
        }
        return newHead;
    }
};
// @lc code=end
