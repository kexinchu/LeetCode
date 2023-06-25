class Solution
{
private:
    string useAdditionalSpace(string &s, int n)
    {
        int sLen = s.size();
        if (n == sLen)
            return s;
        // use additional space
        string res(sLen, ' ');
        for (int idx = n; idx < sLen; idx++)
        {
            res[idx - n] = s[idx];
        }
        for (int idx = 0; idx < n; idx++)
        {
            res[idx + (sLen - n)] = s[idx];
        }
        return res;
    }

    void exchange(string &s, int left, int right)
    {
        int leftPos = left, rightPos = right;
        char tmp = ' ';
        while (leftPos < rightPos)
        {
            tmp = s[leftPos];
            s[leftPos] = s[rightPos];
            s[rightPos] = tmp;
            leftPos += 1;
            rightPos -= 1;
        }
    }

    string notUseAdditonalSpace(string &s, int n)
    {
        int sLen = s.size();
        if (n == sLen)
            return s;
        // exchange whole + exchange subString
        exchange(s, 0, sLen - 1);
        // exchange sub string
        exchange(s, sLen - n, sLen - 1);
        exchange(s, 0, sLen - n - 1);
        return s;
    }

public:
    string reverseLeftWords(string s, int n)
    {
        // use additional space
        // return useAdditionalSpace(s, n);
        // not use additional space
        return notUseAdditonalSpace(s, n);
    }
};