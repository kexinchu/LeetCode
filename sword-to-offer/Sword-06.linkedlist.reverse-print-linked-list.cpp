/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        stack<int> nodeStk;
        ListNode *tmp = head;
        while (tmp != NULL) {
            nodeStk.push(tmp->val);
            tmp = tmp->next;
        }
        while (!nodeStk.empty()) {
            res.push_back(nodeStk.top());
            nodeStk.pop();
        }
        return res;
    }
};