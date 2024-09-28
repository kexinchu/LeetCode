/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
private:
    // quick search
    void quick_sort_recursive(vector<int>& arr, int start, int end) {
        if (start >= end)
            return;
        int mid = arr[end];  // select lastone as split point
        int left = start, right = end - 1;
        // search from arr[left] to arr[right]; 
        // ensure the left value is smaller than mid, while the right value is larger than mid
        while (left < right) { 
            // search the first val which is bigger / equal than mid
            while (arr[left] < mid && left < right) 
                left++;
            // search the last val which is smaller than mid
            while (arr[right] >= mid && left < right) 
                right--;
            std::swap(arr[left], arr[right]); //change the value
        }
        // after resorted, relocated the middle value arr[end];
        if (arr[left] >= arr[end])
            std::swap(arr[left], arr[end]);
        else
            // arr[left] to arr[right] is all smaller than mid, change left = end
            left++;
        quick_sort_recursive(arr, start, left - 1);
        quick_sort_recursive(arr, left + 1, end);
    }
public:
    /**
    Given an array of integers citations where citations[i] is the number of citations \
    a researcher received for their ith paper, return the researcher's h-index.

    According to the definition of h-index on Wikipedia: 
    The h-index is defined as the maximum value of h such that the given researcher has published \
    at least h papers that have each been cited at least h times.
    */
    int hIndex(vector<int>& citations) {
        int citeLen = citations.size();
        // sort the citations
        quick_sort_recursive(citations, 0, citeLen - 1);
        int pos = citeLen - 1;
        while(pos >= 0 && citations[pos] >= (citeLen - pos)) {
            pos--;
        }
        return citeLen - pos - 1;
    }
};
// @lc code=end

