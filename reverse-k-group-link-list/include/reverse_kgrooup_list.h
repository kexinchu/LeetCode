#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct ListNode
{
    int data;
    struct ListNode *next;
};
typedef struct ListNode *Node;

class ReverseKGroupList
{
public:
    // 构造函数
    Node createNode(int val, Node nextptr = NULL);

    // 根据数组构造链表
    Node createByArray(vector<int> valArr);

    // 链表打印
    void print(Node head);

    Node reverseKGroup(Node head, int k);

    pair<Node, Node> reverse(Node head, Node tail);
};