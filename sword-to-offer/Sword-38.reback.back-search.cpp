#include <vector>
#include <string>
using namespace std;

class Solution
{
    // 回溯算法
    //   - 剪枝，标记到当前一步已经使用过的节点
    //      - 借助一个数组
    //   - 单次结束条件，所有节点均已搜索过
    //   - 全部结束条件: 没有新的元素能充当首位
public:
    vector<string> resVec;
    vector<int> flagVec, firstFlagVec;

    void backSearch(string s, int i, int len, string perm)
    {
        if (i == len)
        { // 检索到一组答案
            resVec.push_back(perm);
        }
        for (int j = 0; j < len; ++j)
        {
            // 判断当前节点是否已经使用过
            // || 重复元素 (s[j-1] == s[j]; 此时需要看重复元素的另一个值是否已使用，若已经使用，则此处放s[j]不影响;
            //             否则可能导致s[j]和s[j-1]互换位置的情况)
            if (1 == flagVec[j] || (j > 0 && flagVec[j - 1] == 0 && s[j] == s[j - 1]))
            {
                continue;
            }

            flagVec[j] = 1;
            perm.push_back(s[j]);
            backSearch(s, i + 1, len, perm);
            perm.pop_back();
            flagVec[j] = 0;
        }
    }

    vector<string> permutation(string s)
    {
        int len = s.size();
        flagVec.resize(len);
        firstFlagVec.resize(len);
        sort(s.begin(), s.end()); // 将s排序
        string perm = "";
        backSearch(s, 0, len, perm);

        return resVec;
    }
};