class Solution
{
public:
    string replaceSpace(string s)
    {
        int sLen = s.size(), spaceNum = 0;
        if (sLen == 0)
            return s;
        // count the space
        for (int idx = 0; idx < sLen; ++idx)
        {
            if (s[idx] == ' ')
                spaceNum += 3;
            else
                spaceNum += 1;
        }
        if (spaceNum == sLen)
            return s;
        // replace
        string res(spaceNum, ' ');
        int pos1 = sLen - 1, pos2 = spaceNum - 1;
        while (pos1 >= 0)
        {
            if (s[pos1] == ' ')
            {
                res[pos2] = '0';
                res[pos2 - 1] = '2';
                res[pos2 - 2] = '%';
                pos2 -= 2;
            }
            else
            {
                res[pos2] = s[pos1];
            }
            pos1 -= 1;
            pos2 -= 1;
        }
        return res;
    }
};