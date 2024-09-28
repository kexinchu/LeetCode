/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start

// Definition for a Node.
// ListNode with random link
// class Node
// {
// public:
//     int val;
//     Node *next;
//     Node *random;

//     Node(int _val)
//     {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

// 带随机指针链表的复制
class Solution
{
    /**
     * 方法1: 借助hash表存储 旧Node -> 新Node 的映射关系；来完成random指针的copy
     * 方法2: 原地: 拼接 -> 拆分
     * 这里采用第二种方法
     */
public:
    Node *copyRandomList(Node *head)
    {
        Node *newHead = nullptr, *prior = nullptr, *cur = head, *next = nullptr;
        // 按 next 遍历链表, 并将每一个新节点放在旧节点后面
        while (cur != nullptr)
        {
            int val = cur->val;
            next = new Node(val);
            next->next = cur->next;
            cur->next = next;
            cur = next->next;
        }
        // 处理random节点
        cur = head;
        while (cur != nullptr)
        {
            next = cur->next;
            if (cur->random != nullptr)
            {
                next->random = cur->random->next;
            }
            cur = next->next;
        }
        // 分开新链表 和 旧链表
        cur = head;
        while (cur != nullptr)
        {
            next = cur->next;
            if (newHead == nullptr)
            {
                newHead = next;
                prior = next;
            }
            else
            {
                prior->next = next;
                prior = prior->next;
            }
            cur->next = next->next;
            cur = cur->next;
        }
        return newHead;
    }
};
// @lc code=end
