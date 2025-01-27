/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *tmp = head;
        ListNode *revHead = NULL;
        stack<ListNode *> nodeStk;
        nodeStk.push(NULL);
        while (tmp != NULL)
        {
            nodeStk.push(tmp);
            tmp = tmp->next;
        }
        while (!nodeStk.empty())
        {
            if (revHead == NULL)
            {
                tmp = nodeStk.top();
                revHead = tmp;
            }
            else
            {
                tmp->next = nodeStk.top();
                tmp = tmp->next;
            }
            nodeStk.pop();
        }
        return revHead;
    }
};