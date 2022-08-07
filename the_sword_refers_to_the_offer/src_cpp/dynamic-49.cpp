// Ques: 49 丑数
// Author: chukexin - 2022-08-07

// 动态规划： 由过去的丑数来计算新的丑数: x2 x3 x5
// 借助最大堆来存储
// 优先队列不支持去重, 需要单独处理

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> factors = {2, 3, 5};                        // 质因子
        priority_queue<long, vector<long>, greater<long> > Que; // 存储+排序
        Que.push(1L);
        vector<long> resVec(n); // 存放丑数结果

        // 遍历获取新的丑数
        for (int i = 0; i < n; ++i)
        {
            long tmp = Que.top();
            for (int j = 0; j < 3; ++j)
            {
                Que.push(factors[j] * tmp);
            }
            resVec[i] = tmp;
            // 去顶 + 去重
            while (tmp == Que.top())
            {
                Que.pop();
            }
        }

        return (int)resVec[n - 1];
    }
};