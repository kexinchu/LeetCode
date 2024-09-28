/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// #include<iostream>
// #include<vector>
// #include<stack>
// using namespace std;

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double res = 0.0;
        int Len1 = nums1.size(), Len2 = nums2.size(), mid = (Len1 + Len2) >> 1;
        // 边界判断
        if (Len1 == 0 && Len2 == 0)
            return res;
        int pos1 = 0, pos2 = 0, left = 0, right = 0;
        while (pos1 <= Len1 || pos2 <= Len2)
        {
            if ((pos1 + pos2) == mid + 1)
            {
                if (((Len1 + Len2) & 0x1) == 1)
                    return right / 1.0;
                else
                    return (left + right) / 2.0;
            }
            left = right;
            if (pos1 == Len1)
            {
                pos2 = mid - pos1;
                if (pos2 > 0 && nums2[pos2 - 1] > left)
                    left = nums2[pos2 - 1];
                right = nums2[pos2];
                pos2 += 1;
            }
            else if (pos2 == Len2)
            {
                pos1 = mid - pos2;
                if (pos1 > 0 && nums1[pos1 - 1] > left)
                    left = nums1[pos1 - 1];
                right = nums1[pos1];
                pos1 += 1;
            }
            else
            {
                if (nums1[pos1] <= nums2[pos2])
                {
                    right = nums1[pos1];
                    pos1 += 1;
                }
                else
                {
                    right = nums2[pos2];
                    pos2 += 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end

// int main() {
//     vector<int> nums1 = {1, 3};
//     vector<int> nums2 = {2};
//     cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

//     nums1 = {1, 2};
//     nums2 = {3, 4};
//     cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

//     nums1 = {};
//     nums2 = {};
//     cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

//     nums1 = {0, 0};
//     nums2 = {0, 0};
//     cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

//     nums1 = {2, 4, 5, 6, 7, 8};
//     nums2 = {};
//     cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

//     nums1 = {};
//     nums2 = {2, 4, 6, 7, 8, 9};
//     cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

//     nums1 = {2};
//     nums2 = {2, 4, 6, 7, 8, 9, 10};
//     cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

//     nums1 = {2, 5, 6, 7, 8, 9};
//     nums2 = {2, 4, 5, 6, 7, 8};
//     cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

//     nums1 = {};
//     nums2 = {2};
//     cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
// }