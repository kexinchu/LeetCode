/*
 * @lc app=leetcode id=1739 lang=cpp
 *
 * [1739] Building Boxes
 */

// @lc code=start
#include<iostream>
using namespace std;

class Solution {
    /**
     因为要求 盒子X放在盒子Y的顶部的基础是： 盒子X的四个竖直侧面都必须跟其他盒子或墙相邻
     => 从角落开始(盒子的两个侧面与墙接触)；更快满足堆第二层的目标
     => 因为 房间长宽高都是n，所以不存在触及最大的可能性

     => 画图分析可知：对于从角落向外的每一次，带来的接触地面的盒子数 和 最多能容纳的盒子数目 分别是：
        |层数        | 1 | 2 | 3 |  4 | ... |
        |接触地面盒子数| 1 | 2 | 3 |  4 | ... |
        |最多可容纳盒子| 1 | 3 | 6 | 10 | ... |
        => 每一层新增 i 个 接触地面盒子，同时带来 i! = (i * (i + 1)) / 2 的收益
        => 可以先判断需要多少层？ 得到层数 x => 完整层(x-1)! = ((x - 1) * x) / 2个贴地盒子
     => 计算第x层中，没新增一个元素, 带来的收益:
        |增加第i个贴地盒子 | 1 | 2 | 3 |  4 | ... |
        |最多可容纳盒子    | 1 | 3 | 6 | 10 | ... |
        => 同样满足 i! 规则
     */
public:
    int minimumBoxes(int n) {
        if (n == 0) return 0;
        // step 1, 寻找需要多少层来存放n个盒子
        int maxBox = 1, levels = 1, nearGround = 1, remains = n - 1;
        while (remains > 0) {
            levels += 1;
            nearGround += levels;
            maxBox = maxBox + levels;
            remains = remains - maxBox;
        }
        // cout << remains << "\t" << levels << "\t" << nearGround << endl;

        // step 2, 寻找剩下的盒子需要几个贴地
        if (remains == 0) return nearGround;
        // 不是刚和够第i层，退回i-1层，并在第i层计算需要多少个贴地盒子
        int addBox = 1, addNearGBox = 1; 
        remains+=maxBox;
        while (remains - addBox > 0) {
            addNearGBox += 1;
            addBox += addNearGBox;
        }

        return nearGround - levels + addNearGBox;
    }
};
// @lc code=end

