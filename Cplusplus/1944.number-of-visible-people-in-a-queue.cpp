/*
 * @lc app=leetcode.cn id=1944 lang=cpp
 *
 * [1944] 队列中可以看到的人数
 */

// @lc code=start
#include <stack>
#include <vector>
using namespace std;

class Solution
{
    /**
     * 借助单调栈实现
     *
     * 方法1，类似于柱状图面积, 对每一类 向左 + 向右 寻找第一个比自身更高的列
     *      Note: 1, Here only consider 向右,
     *            2, 中间的也有可能被挡住：eg [10,6,8,5,11,6]; 从0号位置向右，5会被8和6挡住；
     *               可以通过中间元素 x 的左边界是否在 id -> 有边界之间来判断该结果是否会被看到。实际跑的时候会超时
     * 方法2，通过画图可知，每一个列 m 被 列x 看到的条件是：
     *      max(h[x+1, h[x+2], ..., h[m-1]) < min(h[x], h[m])
     *      即：1，仅当处理列m时, 列x依旧在单调栈内(否则说明中间有一个元素会不满足上式，被挡住),
     *          2，if h[m] < 栈顶, m直接入栈，此时栈内元素仅栈顶能看到h；(因为栈顶元素最小)
     *          2，如果h[m] > 栈顶，栈顶元素退栈，此时说明不光栈顶元素能看到，栈中新的栈顶也能看到；
     *      eg:                               [10, 6, 8, 5, 11, 9]
     *      处理过程:                           [0 |0 |0 |0 |0 |0 ]
     *      step1, 处理10, 入栈10
     *      step2, 处理6, 入栈6                  +1|
     *      step3, 处理8, 出栈6，入栈8            +1|+1
     *      step4, 处理5, 入栈5                        +1
     *      step5, 处理11, 出栈5，8，10，入栈11    +1|  |+1|+1
     *      step6, 处理9, 入栈9                              |+1|
     *      汇总结果                            [3,1,2,1,1,0]  与答案匹配
     */
public:
    // 方法1, 遍历多次，会导致超时
    vector<int> canSeePersonsCount_method1(vector<int> &heights)
    {
        int heiLen = heights.size();
        // 记录 i 能看到的右边最高的下标 left right
        vector<int> leftVec(heiLen, -1), rightVec(heiLen, heiLen - 1), resVec(heiLen, 0);
        stack<int> tmpStk;
        for (int id = 0; id < heiLen; id++)
        {
            // keep the tmpStk element > heights[id]
            while (!tmpStk.empty() && heights[id] > heights[tmpStk.top()])
            {
                // right boundary
                rightVec[tmpStk.top()] = id;
                tmpStk.pop();
            }

            // left boundary
            if (!tmpStk.empty())
                leftVec[id] = tmpStk.top();

            tmpStk.push(id);
        }
        // calc max width
        for (int id = 0; id < (heiLen - 1); id++)
        {
            resVec[id] = rightVec[id] - id;
            for (int j = id + 1; j <= rightVec[id]; j++)
            {
                if (leftVec[j] > id)
                    resVec[id] -= 1;
            }
        }
        return resVec;
    }

    // 方法2，仅遍历一次
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        int heiLen = heights.size();
        stack<int> tmpStk;
        vector<int> resVec(heiLen, 0);

        for (int id = 0; id < heiLen; id++)
        {
            // out stack
            while (!tmpStk.empty() && heights[id] > heights[tmpStk.top()])
            {
                resVec[tmpStk.top()] += 1;
                tmpStk.pop();
            }

            // insert stack
            if (!tmpStk.empty())
                resVec[tmpStk.top()] += 1;
            tmpStk.push(id);
        }
        return resVec;
    }
};
// @lc code=end
