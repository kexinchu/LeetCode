/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

#include <vector>
#include <queue>
using namespace std;

// @lc code=start
class Solution
{
    // 这里可以借助有向无环图来解决
    // 拓扑排序法： https://zhuanlan.zhihu.com/p/135094687
    // 判断是否是一张有向无环图
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // create a graph
        vector<vector<int>> graph(numCourses, vector<int>());
        // step1 获取图中节点的入度
        vector<int> indegree = vector<int>(numCourses);
        for (auto &&prerequisite : prerequisites)
        {
            indegree[prerequisite[0]] += 1;
            graph[prerequisite[1]].emplace_back(prerequisite[0]);
        }
        // 通过queue来处理入度为0的结果
        queue<int> ops_que;
        for (int idx = 0; idx < numCourses; idx += 1)
        {
            if (indegree[idx] == 0)
            {
                ops_que.push(idx);
            }
        }
        int count = 0;
        while (!ops_que.empty())
        {
            int point = ops_que.front();
            vector<int> follows = graph[point];
            for (auto &&idx : follows)
            {
                indegree[idx] -= 1;
                if (indegree[idx] <= 0)
                {
                    ops_que.push(idx);
                }
            }
            ops_que.pop();
            count += 1;
        }
        if (count == numCourses)
            return true;
        else
            return false;
    }
};
// @lc code=end
