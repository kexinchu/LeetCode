#include "include/reverse_kgroup_list.h"

#include <tuple>
using namespace std;

// 构造函数
Node ReverseKGroupList::createNode(int val, Node nextptr = NULL)
{
    ListNode headNode = {data : val, next : nextptr};
    return &headNode;
}

// 根据数据构造链表
Node ReverseKGroupList::createByArray(vector<int> valArr)
{
    if (valArr.size() == 0)
    {
        return NULL;
    }
    Node head = createNode(valArr[0]);
    Node tail = head;
    for (int i = 1; i < valArr.size(); i++)
    {
        Node tmp = createNode(valArr[i]);
        tail->next = tmp;
        tail = tail->next;
    }
    return head;
}

// 链表打印
void ReverseKGroupList::print(Node head)
{
    if (head == NULL)
    {
        cout << "单链表为空" << endl;
        return;
    }
    Node tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << "\t";
        tmp = tmp->next;
    }
    cout << endl;
}

// 翻转一个子链表，并且返回新的头与尾
pair<Node, Node> ReverseKGroupList::reverse(Node head, Node tail)
{
    Node prev = head;
    Node tmp = head->next;
    while (tmp != tail->next)
    {
        Node rev = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = rev;
    }
    return make_pair(tail, head);
}

Node ReverseKGroupList::reverseKGroup(Node head, int K)
{
    Node hair = createNode(0);
    hair->next = head;
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
        tie(head, tail) = reverse(head, tail);
        // 把子链表重新接回原链表
        pre->next = head;
        tail->next = nex;
        pre = tail;
        head = tail->next;
    }

    return hair->next;
}

int main()
{
    // 初始化
    ReverseKGroupList RKGL = ReverseKGroupList();

    // 单一节点
    Node testInit = RKGL.createNode(0);
    cout << testInit->data << endl;

    // 通过vector生成链表
    vector<int> testVec(3, 5);
    Node head = RKGL.createByArray(testVec);
    cout << head->data << "\t" << head->next->data << endl;

    // 打印链表
    RKGL.print(head);

    // 反转K链表
    // head = 1 -> 2 -> 3 -> 4 -> 5; K=3
    // out = 3 -> 2 -> 1 -> 4 -> 5
}