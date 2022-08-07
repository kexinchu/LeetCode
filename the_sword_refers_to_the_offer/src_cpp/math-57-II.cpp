// Ques: 和为s的连续正数序列
// Author: chukexin - 2022-06-18

// 连续正整数 <至少含有2个数字>
// 采用双指针的方法
// 当res < target; 右指针向右移动，res += right
// 当res > target; 左指针向右移动，res -= left
// 当res == target; 得到一组结果
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > findContinuousSequence(int target)
    {
        if (target < 3)
            return {};
        int array[target / 2 + 2]; // 定义变量长度的数组，不能同时初始化
        // left = 1, 如果等于0，会导致当target=15时，计算到1+2+3+4+5 = 15时，left仍=1，导致 "array + left - 1" overflow
        int left = 1, right = 0, tmp = 0;
        vector<vector<int> > resArr;
        // 偶数: 到target/2，后面的值均大于target
        // 奇数: target/2 + (target/2 + 1) == target
        while (right <= (target / 2 + 1))
        {
            if (tmp == target)
            {
                // 使用 left -> right 之间的值构造vector
                vector<int> tmpArr(array + left - 1, array + right);
                resArr.push_back(tmpArr);
                // right+= 1; 避免死循环
                right += 1;
                tmp += right;
                array[right - 1] = right;
            }
            else if (tmp < target)
            {
                right += 1;
                tmp += right;
                array[right - 1] = right;
            }
            else
            {
                // tmp > target
                tmp -= left;
                left += 1;
            }
        }
        return resArr;
    }
};