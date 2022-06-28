// Ques: 09 用两个栈实现队列
// Author: chukexin - 2022-06-18

#include <stack>
using namespace std;

class CQueue
{
    // 一个栈负责压入新元素
    // 一个栈负责弹出尾巴元素
private:
    stack<int> leftStk, rightStk;

public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        leftStk.push(value);
    }

    int deleteHead()
    {
        if (rightStk.empty() && !leftStk.empty())
        {
            while (!leftStk.empty())
            {
                int top = leftStk.top();
                rightStk.push(top);
                leftStk.pop();
            }
        }
        if (rightStk.empty())
        {
            return -1;
        }
        int top = rightStk.top();
        rightStk.pop();
        return top;
    }
};