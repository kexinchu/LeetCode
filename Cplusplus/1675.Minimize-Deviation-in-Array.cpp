/*
 * @lc app=leetcode.cn id=1675 lang=cpp
 *
 * [1675] 数组的最小偏移量
 */

// @lc code=start
#include <set>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
    /**
    Idea:
        Pre-doubling all of the odd numbers, and then only do division to make numbers smaller.
        When to stop: when the largest number becomes odd
    Implecation:
        1, PriorityQueue,（Max Heap） - 集合在动态变化
            缺点：1，need to manually track the mini number in the set
                 2, Can have duplication in the queue
        2, TreeSet
            O(1) to get the max/min in the set
            Automatically remove duplicates
        Time complexity: O(n * logm * logn)
        Space complexity: O(n)
    */
public:
    int minimumDeviation(vector<int> &nums)
    {
        set<int> tmpSet;
        // send to set with pre-doubling all of the odd number
        for (int x : nums)
            tmpSet.insert(x & 1 ? x * 2 : x);

        // 处理
        int ans = *rbegin(tmpSet) - *begin(tmpSet);
        while (*rbegin(tmpSet) % 2 == 0)
        {
            tmpSet.insert(*rbegin(tmpSet) / 2);
            tmpSet.erase(*rbegin(tmpSet));
            ans = min(ans, *rbegin(tmpSet) - *begin(tmpSet));
        }
        // 返回最大值
        return ans;
    }
};
// @lc code=end
