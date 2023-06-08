#ifndef BAIDU_GOODCODER_CHUKEXIN_INCLUDE_REVERSEKGROUPLIST_H
#define BAIDU_GOODCODER_CHUKEXIN_INCLUDE_REVERSEKGROUPLIST_H

#include <iostream>
#include <utility>
#include <vector>

namespace goodcoder
{
    struct ListNode
    {
        int data;
        struct ListNode *next;
        // 初始化方法
        ListNode() : data(0), next(NULL){};
        ListNode(int val) : data(val), next(NULL){};
        ListNode(int val, ListNode *nextptr) : data(val), next(nextptr){};
    };
    typedef struct ListNode *Node;

    class ReverseKGroupList
    {
    public:
        // 根据数组构造链表
        Node createByArray(std::vector<int> valArr);

        // 链表->string
        std::string listToStr(Node head);

        // 按 K 分组反转
        Node reverseKGroup(Node head, int k);

        // 翻转一个子链表，并且返回新的头与尾
        std::pair<Node, Node> reverse(Node head, Node tail);
    };
} // namespace goodcoder

#endif // BAIDU_GOODCODER_CHUKEXIN_INCLUDE_REVERSEKGROUPLIST_H