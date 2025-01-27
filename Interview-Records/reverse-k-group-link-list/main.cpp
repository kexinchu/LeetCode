#include "reverse_kgroup_list.h"

using goodcoder::Node;
using goodcoder::ReverseKGroupList;

int main()
{
    // 初始化
    ReverseKGroupList *RKGL = new ReverseKGroupList();

    // 反转K链表
    // head = 1 -> 2 -> 3 -> 4 -> 5; K=3
    // out = 3 -> 2 -> 1 -> 4 -> 5
    // head = 1 -> 2 -> 3 -> 4 -> 5; K=2
    // out = 2 -> 1 -> 4 -> 3 -> 5
    std::vector<int> testVec{1, 2, 3, 4, 5};
    Node head = RKGL->createByArray(testVec);
    std::string a = RKGL->listToStr(head);
    std::cout << a << std::endl;
    Node headNew = RKGL->reverseKGroup(head, 3);
    a = RKGL->listToStr(headNew);
    std::cout << a << std::endl;
    head = RKGL->createByArray(testVec);
    headNew = RKGL->reverseKGroup(head, 2);
    a = RKGL->listToStr(headNew);
    std::cout << a << std::endl;
}