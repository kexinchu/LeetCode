/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
#include<vector>
#include<stack>
using namespace std;

class Solution {
    /**
     方法1： 内存占用高，时间复杂度O(3*n)
        单调栈: 用来寻找左侧/右侧第一个比当前值大或比当前值小的元素
            单调递增栈：仅当元素比栈顶元素小的元素能入栈 (从栈顶到栈底单调递增)
            单调递减栈：仅当元素比栈顶元素大的元素能入栈
        主要用来解决：
            1，寻找左侧第一个比当前元素大的元素。
                构造 单调递增栈
            2，寻找左侧第一个比当前元素小的元素。
                构造 单调递减栈
            3，寻找右侧第一个比当前元素大的元素。
                构造 单调递增栈
            4，寻找右侧第一个比当前元素小的元素。
                构造 单调递减栈
     方法2：优化 - 在数据入栈的时候标记左边界，在出栈的时候标记右边界
     */
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> left_mono_stack, right_moni_stack;
        // 通过单调递增栈寻找 向左第一个小于它的 列
        for (int idx = 0; idx < n; idx++) {
            // 确定当前栈中元素都比 heights[idx] 小
            while (!left_mono_stack.empty() && heights[left_mono_stack.top()] >= heights[idx]) {
                left_mono_stack.pop();
            }
            // 将第一个小于heights[idx]的结果存到left中
            left[idx] = (left_mono_stack.empty()) ? -1 : left_mono_stack.top();
            left_mono_stack.push(idx);
        }
        // 通过单调递增栈寻找 向右第一个小于它的 列
        for (int idx = n - 1; idx >= 0; idx--) {
            while(!right_moni_stack.empty() && heights[right_moni_stack.top()] >= heights[idx]) {
                right_moni_stack.pop();
            }
            right[idx] = (right_moni_stack.empty()) ? n : right_moni_stack.top();
            right_moni_stack.push(idx);
        }

        // 计算矩阵面积
        int max_area = 0;
        for (int idx = 0; idx < n; idx++) {
            int area = heights[idx] * (right[idx] - left[idx] - 1);
            if (area > max_area) max_area = area;
        }

        // 返回
        return max_area;
    }
};
// @lc code=end

