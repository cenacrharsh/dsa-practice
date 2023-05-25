#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Without Extra Space

//* compare the largest element in nums1 and smallest element in nums2, if largest element of nums1 is > smallest element of nums2 then we swap and move forward, once we find an element in nums1 and nums2 such that nums1 < nums2 we don't have to check any further since arr is sorted



//! With Extra Space
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> merged(n + m);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                merged[k++] = nums1[i++];
            }
            else
            {
                merged[k++] = nums2[j++];
            }
        }
        while (i < m)
        {
            merged[k++] = nums1[i++];
        }
        while (j < n)
        {
            merged[k++] = nums2[j++];
        }
        for (i = 0; i < (m + n); i++)
        {
            nums1[i] = merged[i];
        }
    }
};