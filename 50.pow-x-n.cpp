/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
private:
    double absPow(double x, unsigned int n)
    {
        if (n == 0)
            return 1;
        double powRes = absPow(x, n >> 1);
        double res = powRes * powRes;
        if (n & 0x1 == 1)
            res *= x;
        return res;
    }

    bool isEqual(double x, double y)
    {
        if (fabs(x - y) < 1e-5)
            return true;
        else
            return false;
    }

public:
    double myPow(double x, int n)
    {
        // check n == 0?
        if (n == 0)
            return 1;
        // check n < 0?
        unsigned int pow = static_cast<unsigned>(abs(n));
        // calc x^n
        double res = absPow(x, pow);

        // 1/x^pow
        if (n < 0)
        {
            if (isEqual(x, 0.0))
            {
                return 0;
            }
            else
            {
                res = 1 / res;
            }
        }
        return res;
    }
};
// @lc code=end
