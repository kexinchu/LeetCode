#include "reverse_kgroup_list.h"

#include <tuple>

namespace goodcoder
{
    // 根据数据构造链表
    Node ReverseKGroupList::createByArray(std::vector<int> valArr)
    {
        if (valArr.size() == 0)
        {
            return NULL;
        }
        Node head = new ListNode(valArr[0]);
        Node tail = head;
        for (int i = 1; i < valArr.size(); i++)
        {
            Node tmp = new ListNode(valArr[i]);
            tail->next = tmp;
            tail = tail->next;
        }
        return head;
    }

    // 链表打印
    std::string ReverseKGroupList::listToStr(Node head)
    {
        if (head == NULL)
        {
            return "";
        }
        std::string strList = std::to_string(head->data);
        Node tmp = head->next;
        while (tmp != NULL)
        {
            strList = strList + "->" + std::to_string(tmp->data);
            tmp = tmp->next;
        }
        return strList;
    }

    // 翻转一个子链表，并且返回新的头与尾
    std::pair<Node, Node> ReverseKGroupList::reverse(Node head, Node tail)
    {
        Node prev = head;
        Node tmp = head->next;
        head->next = NULL; // 避免reverse之后造成：head->next -> head -> head->next  这样的闭环
        while (prev != tail)
        {
            Node rev = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = rev;
        }
        return std::make_pair(tail, head);
    }

    // 按 K 分组反转
    Node ReverseKGroupList::reverseKGroup(Node head, int K)
    {
        Node hair = new ListNode(0, head);
        Node pre = hair;

        while (head)
        {
            Node tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < K; ++i)
            {
                tail = tail->next;
                if (!tail)
                {
                    return hair->next;
                }
            }
            Node nex = tail->next;
            std::tie(head, tail) = reverse(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
} // namespace goodcoder
