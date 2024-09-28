// Ques: 14-II 剪绳子 <跟14-I逻辑类似>
// Author: chukexin - 2022-06-18

// 贪心算法:  ——>  逐步构造最优解
//    在每个阶段，都作出一个看上去最优的决策（在一定的标准下）。决策一旦作出，就不可更改。

// 最优 : 3
// 4 = 2*2;  5 < 2*3;

// 大数求余数 - 循环求余数  => (xy)⊙p=[(x⊙p)(y⊙p)]⊙p
// 且当 x < p时， x⊙p = x； 这里3 / 4 远小于 p = 1e9+7
// => (xy)⊙p=[(x⊙p)y)]⊙p

class Solution
{
public:
    long pow(long base, long power)
    {
        // 计算幂值
        long res = 1;
        while (power > 0)
        {
            res = res * base % 1000000007;
            power -= 1;
        }
        return res;
    }

    int cuttingRope(int n)
    {
        if (n < 4)
            return n - 1;
        int k = n % 3;
        n /= 3;
        if (k == 0)
            return pow(3, n);
        if (k == 1)
            return (pow(3, n - 1) * 4) % 1000000007;
        else
            return (pow(3, n) * 2) % 1000000007;
    }
};